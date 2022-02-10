: ${3?"usage: ${0} <TESTSEQ_DIR> <MODEL_DIR> <GENFILE_NAME>"}

#Inputs
TESTSEQ_DIR="${1}";
MODEL_DIR="${2}";
GENSEQ_DIR="${1}";
GENFILE_NAME="${3}";

#Setting environment variables
export TESTLHSSEQ=${TESTSEQ_DIR}/lhs.txt
export MODEL_DIR=${MODEL_DIR}
export GENSEQ_DIR_SAME=${GENSEQ_DIR}
export GENFILE_NAME_SAME=${GENFILE_NAME}
mkdir -p $GENSEQ_DIR

echo "--------------- Generate seqs ${TESTSEQ_DIR} : START ---------------------"
python -m bin.infer \
  --tasks "
    - class: DecodeText" \
  --model_dir $MODEL_DIR \
  --input_pipeline "
    class: ParallelTextInputPipeline
    params:
      source_files:
        - $TESTLHSSEQ" \
  >  ${GENSEQ_DIR_SAME}/${GENFILE_NAME_SAME}
echo "--------------- Generate seqs ${TESTSEQ_DIR} : FINISH ---------------------"