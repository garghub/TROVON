void F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
T_3 * V_6 ;
if( ! V_2 ) return;
if( ! V_4 || ! F_2 ( V_2 ) ) {
F_3 ( V_1 , L_1 , V_3 , L_2 ) ;
if( ! F_2 ( V_2 ) ) F_4 ( V_1 , L_3 ) ;
}
for( V_5 = 0 ; V_5 < F_2 ( V_2 ) ; V_5 ++ ) {
if( V_4 ) F_3 ( V_1 , L_1 , V_3 , L_2 ) ;
else if( V_5 > 0 ) F_3 ( V_1 , L_4 ) ;
V_6 = ( T_3 * ) F_5 ( V_2 , V_5 ) ;
if( ! V_6 -> V_7 ) F_4 ( V_1 , V_6 -> V_8 ) ;
else if( ! V_6 -> V_8 ) F_4 ( V_1 , V_6 -> V_7 ) ;
else F_3 ( V_1 , L_5 , V_6 -> V_7 , V_6 -> V_8 ) ;
if( V_4 ) F_4 ( V_1 , L_6 ) ;
}
}
int F_6 ( T_1 * V_1 , T_4 * V_9 , int V_10 , int V_3 )
{
char * V_11 = NULL , * V_8 = NULL ;
unsigned char * V_12 ;
T_5 * V_13 ;
T_2 * V_6 = NULL ;
int V_14 = 1 ;
if( ! ( V_13 = F_7 ( V_9 ) ) ) return 0 ;
V_12 = V_9 -> V_8 -> V_15 ;
if( ! ( V_11 = V_13 -> V_16 ( NULL , & V_12 , V_9 -> V_8 -> V_17 ) ) ) return 0 ;
if( V_13 -> V_18 ) {
if( ! ( V_8 = V_13 -> V_18 ( V_13 , V_11 ) ) ) {
V_14 = 0 ;
goto V_19;
}
F_3 ( V_1 , L_7 , V_3 , L_2 , V_8 ) ;
} else if( V_13 -> V_20 ) {
if( ! ( V_6 = V_13 -> V_20 ( V_13 , V_11 , NULL ) ) ) {
V_14 = 0 ;
goto V_19;
}
F_1 ( V_1 , V_6 , V_3 ,
V_13 -> V_21 & V_22 ) ;
} else if( V_13 -> V_23 ) {
if( ! V_13 -> V_23 ( V_13 , V_11 , V_1 , V_3 ) ) V_14 = 0 ;
} else V_14 = 0 ;
V_19:
F_8 ( V_6 , V_24 ) ;
if( V_8 ) Free ( V_8 ) ;
V_13 -> V_25 ( V_11 ) ;
return V_14 ;
}
int F_9 ( T_6 * V_26 , T_4 * V_9 , int V_10 , int V_3 )
{
T_1 * V_27 ;
int V_28 ;
if( ! ( V_27 = F_10 ( V_26 , V_29 ) ) ) return 0 ;
V_28 = F_6 ( V_27 , V_9 , V_10 , V_3 ) ;
F_11 ( V_27 ) ;
return V_28 ;
}
