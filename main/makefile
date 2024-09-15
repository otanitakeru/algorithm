# フォルダ構成
PROJECT_ROOT := ..
UTILS_DIR := $(PROJECT_ROOT)/utils
MAIN_DIR := .

# モジュール名
MODULES := $(filter-out utils main,$(notdir $(wildcard $(PROJECT_ROOT)/*)))

# 実行可能なターゲットを検出（モジュール名/ターゲット名の形式）
EXECUTABLES := $(foreach module,$(MODULES),$(patsubst $(PROJECT_ROOT)/$(module)/%.c,$(module)/%,$(wildcard $(PROJECT_ROOT)/$(module)/*.c)))

# 実行可能なターゲットを持つモジュールのリスト
EXECUTABLE_MODULES := $(sort $(foreach exec,$(EXECUTABLES),$(firstword $(subst /, ,$(exec)))))

# コンパイラ設定
CC := gcc
CFLAGS := -Wall -Wextra -I$(UTILS_DIR)

# utils ディレクトリの .c ファイルを取得
UTILS_SRCS := $(wildcard $(UTILS_DIR)/*.c)
UTILS_OBJS := $(UTILS_SRCS:.c=.o)

.PHONY: all clean $(MODULES) list modules

all: modules list

# utils ディレクトリの .c ファイルをコンパイル
$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ターゲットをコンパイルして実行
define MODULE_template
$(1)/%: $(PROJECT_ROOT)/$(1)/%.c $(UTILS_OBJS)
	$(CC) $(CFLAGS) $$^ -o $(MAIN_DIR)/$$*.o
	@echo "\n--- 実行開始 ---\n"
	@$(MAIN_DIR)/$$*.o
	@echo "\n--- 実行終了 ---\n"
endef

$(foreach module,$(MODULES),$(eval $(call MODULE_template,$(module))))

clean:
	rm -f $(MAIN_DIR)/*.o

$(MODULES):
	@echo "$@ のターゲット一覧:"
	@for target in $(filter $@/%,$(EXECUTABLES)); do \
		echo "  make $$target"; \
	done

modules:
	@echo "実行可能なターゲットを持つモジュール:"
	@for module in $(EXECUTABLE_MODULES); do \
		echo "  $$module"; \
	done
	@echo ""

list:
	@echo "実行可能なターゲット一覧:"
	@for target in $(EXECUTABLES); do \
		echo "  make $$target"; \
	done

help:
	@echo "利用可能なコマンド:"
	@echo "  make modules           - 実行可能なターゲットを持つモジュールを表示"
	@echo "  make list              - 全ての実行可能なターゲットを表示"
	@echo "  make <モジュール>        - 特定のモジュールの実行可能なターゲットを表示"
	@echo "  make <モジュール>/<ターゲット名> - 特定のターゲットをビルドして実行"
	@echo "  make clean             - コンパイルされた .o ファイルを削除"
	@echo ""
	@echo "例: make sort/insertion_sort"
	@echo ""
	@echo "全てのモジュール: $(MODULES)"
	@echo "実行可能なターゲットを持つモジュール: $(EXECUTABLE_MODULES)"
	@echo ""
	@echo "コンパイルされた実行ファイルは一時的に '<ターゲット名>.o' という名前で作成され、"
	@echo "実行後に自動的に削除されます。"