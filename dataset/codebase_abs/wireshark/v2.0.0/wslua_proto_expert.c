T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
#define F_3 2
#define F_4 3
#define F_5 4
T_3 V_2 = NULL ;
const T_4 * V_3 = F_6 ( V_1 , F_2 ) ;
const T_4 * V_4 = F_6 ( V_1 , F_3 ) ;
int V_5 = ( int ) F_7 ( V_1 , F_4 ) ;
int V_6 = ( int ) F_7 ( V_1 , F_5 ) ;
V_2 = F_8 ( V_7 , 1 ) ;
V_2 -> V_8 . V_9 = V_10 ;
V_2 -> V_8 . V_11 = V_12 ;
V_2 -> V_13 = F_9 ( V_3 ) ;
V_2 -> V_4 = F_9 ( V_4 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
F_10 ( V_1 , V_2 ) ;
F_11 ( 1 ) ;
}
T_5 F_12 ( T_2 * V_1 ) {
T_3 V_2 = F_13 ( V_1 , 1 ) ;
if ( ! V_2 ) {
F_14 ( V_1 , L_1 ) ;
} else {
F_15 ( V_1 , L_2 ,
V_2 -> V_8 . V_9 , V_2 -> V_8 . V_11 , V_2 -> V_13 , V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 ) ;
}
return 1 ;
}
static int F_16 ( T_2 * V_1 ) {
T_3 V_2 = F_13 ( V_1 , 1 ) ;
if ( V_2 -> V_8 . V_11 == - 2 ) {
F_17 ( ( T_4 * ) V_2 -> V_13 ) ;
F_17 ( ( T_4 * ) V_2 -> V_4 ) ;
F_17 ( V_2 ) ;
}
return 0 ;
}
int F_18 ( T_2 * V_1 ) {
F_19 ( T_3 ) ;
return 0 ;
}
