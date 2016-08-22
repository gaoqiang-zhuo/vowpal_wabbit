#include "../../../../vowpalwabbit/vw.h"
#include "jni_base_learner.h"
#include "vowpalWabbit_learner_VWProbLearner.h"

jfloat prob_predictor(example* vec, JNIEnv *env) { return vec->pred.prob; }

JNIEXPORT jfloat JNICALL Java_vowpalWabbit_learner_ProbLearner_predict(JNIEnv *env, jobject obj, jstring example_string, jboolean learn, jlong vwPtr)
{ return base_predict<jfloat>(env, example_string, learn, vwPtr, prob_predictor);
}

JNIEXPORT jfloat JNICALL Java_vowpalWabbit_learner_ProbLearner_predictMultiline(JNIEnv *env, jobject obj, jobjectArray example_strings, jboolean learn, jlong vwPtr)
{ return base_predict<jfloat>(env, example_strings, learn, vwPtr, prob_predictor);
}
