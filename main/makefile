# フォルダ構成
PROJECT_ROOT := ..
UTILS_DIR := $(PROJECT_ROOT)/utils
MAIN_DIR := .

# モジュール名
MODULES := $(filter-out utils main,$(notdir $(wildcard $(PROJECT_ROOT)/*)))

# コンパイラ設定
CC := gcc
CFLAGS := -Wall -Wextra -I$(UTILS_DIR)

# utils/*.c
UTILS_SRCS := $(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJS := $(UTILS_SRCS:.c=.o)


.PHONY: all clean $(MODULES)

all: $(MODULES)

# utils/*.cをコンパイル
$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ターゲットをコンパイルして実行
define MODULE_template
$(1)/%: $(PROJECT_ROOT)/$(1)/%.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) $$^ -o $(MAIN_DIR)/main
	@echo "\n--- 実行開始 $@ ---\n"
	@$(MAIN_DIR)/main
	@echo "\n--- 実行終了 ---\n"
endef

$(foreach module,$(MODULES),$(eval $(call MODULE_template,$(module))))


clean:
	rm -f $(MAIN_DIR)/main

$(MODULES):
	@echo "$@ のターゲット一覧"
	@echo "  make $@/<target_name>"
	@echo "例: make sort/insertion_sort"

help:
	@echo "利用可能なモジュール: $(MODULES)"
	@echo "特定のターゲットをビルドして実行するには: make <モジュール>/<ターゲット名>"
	@echo "例: make sort/insertion_sort"
	@echo "コンパイルされた実行ファイルは現在のディレクトリに 'main' という名前で作成され、自動的に実行されます"
	@echo "モジュールで利用可能なターゲットを確認するには: make <モジュール>"
	@echo "クリーンアップ（'main'ファイルを削除）するには: make clean"