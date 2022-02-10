: ${8?"usage: ${0} <DATA_DIR> <TRAIN_STEPS> <MODEL_DIR> <CONFIG> <BATCH_SIZE> <CHECKPOINT_STEPS> <EVAL_STEPS> <MAX_CHECKPOINT>"}

#Inputs
DATA_DIR="${1}";
TRAIN_STEPS="${2}";
MODEL_DIR="${3}";
CONFIG="${4}";
BATCH_SIZE="${5}";
CHECKPOINT_STEPS="${6}";
EVAL_STEPS="${7}";
MAX_CHECKPOINT="${8}";

#Setting environment variables
export DATA_DIR=${DATA_DIR}
export VOCAB_SOURCE=${DATA_DIR}/train/lhsvocab.txt
export VOCAB_TARGET=${DATA_DIR}/train/rhsvocab.txt
export TRAIN_SOURCES=${DATA_DIR}/train/lhs.txt
export TRAIN_TARGETS=${DATA_DIR}/train/rhs.txt
export DEV_SOURCES=${DATA_DIR}/eval/lhs.txt
export DEV_TARGETS=${DATA_DIR}/eval/rhs.txt

PRED_SCRIPTS="predictions/"

CHECKPOINT_STEPS=${CHECKPOINT_STEPS}
EVAL_STEPS=${EVAL_STEPS}
MAX_CHECKPOINT=${MAX_CHECKPOINT}

export TRAIN_STEPS=${TRAIN_STEPS}
export CHECKPOINT_STEPS=${CHECKPOINT_STEPS}
export EVAL_STEPS=${EVAL_STEPS}
export MAX_CHECKPOINT=${MAX_CHECKPOINT}
export BATCH_SIZE=${BATCH_SIZE}


#Generate vocabulary
python bin/tools/generate_vocab.py < ${TRAIN_SOURCES} > ${VOCAB_SOURCE}
python bin/tools/generate_vocab.py < ${TRAIN_TARGETS} > ${VOCAB_TARGET}

#Create output model dir
export MODEL_DIR=${MODEL_DIR}
mkdir -p $MODEL_DIR

python -m bin.train \
  --config_paths="
      ./configs/$CONFIG.yml,
      ./example_configs/train_seq2seq_optimized.yml,
      ./example_configs/text_metrics.yml" \
  --model_params "
      vocab_source: $VOCAB_SOURCE
      vocab_target: $VOCAB_TARGET" \
  --input_pipeline_train "
    class: ParallelTextInputPipeline
    params:
      source_files:
        - $TRAIN_SOURCES
      target_files:
        - $TRAIN_TARGETS" \
  --input_pipeline_dev "
    class: ParallelTextInputPipeline
    params:
       source_files:
        - $DEV_SOURCES
       target_files:
        - $DEV_TARGETS" \
  --batch_size $BATCH_SIZE \
  --train_steps $TRAIN_STEPS \
  --output_dir $MODEL_DIR \
  --save_checkpoints_steps $CHECKPOINT_STEPS \
  --eval_every_n_steps $EVAL_STEPS \
  --keep_checkpoint_max $MAX_CHECKPOINT 

echo "--------------- TRAINING COMPLETE ---------------------" 