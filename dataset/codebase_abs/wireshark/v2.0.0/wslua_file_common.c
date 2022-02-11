void F_1 ( T_1 * V_1 , T_2 * V_2 ) {
T_3 * V_3 = ( T_3 * ) F_2 ( sizeof( T_3 ) ) ;
if ( V_2 -> V_3 != NULL ) {
F_3 ( V_1 , L_1 ) ;
return;
}
V_3 -> V_4 = V_5 ;
V_2 -> V_3 = ( void * ) V_3 ;
}
int F_4 ( T_1 * V_1 , T_2 * V_2 ) {
T_3 * V_3 = ( T_3 * ) V_2 -> V_3 ;
if ( ! V_3 ) {
F_3 ( V_1 , L_2 ) ;
return V_5 ;
}
F_5 ( V_1 , V_6 , V_3 -> V_4 ) ;
return 1 ;
}
int F_6 ( T_1 * V_1 , T_2 * V_2 ) {
T_3 * V_3 = ( T_3 * ) V_2 -> V_3 ;
if ( ! V_3 ) {
F_3 ( V_1 , L_2 ) ;
return 0 ;
}
if ( F_7 ( V_1 , - 1 ) ) {
F_8 ( V_1 , V_6 , V_3 -> V_4 ) ;
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( ! F_9 ( V_1 , - 1 ) ) {
F_3 ( V_1 , L_3 ) ;
return 0 ;
}
if ( V_3 -> V_4 != V_5 ) {
F_8 ( V_1 , V_6 , V_3 -> V_4 ) ;
}
V_3 -> V_4 = F_10 ( V_1 , V_6 ) ;
return 0 ;
}
void F_11 ( T_1 * V_1 , T_2 * V_2 ) {
T_3 * V_3 = ( T_3 * ) V_2 -> V_3 ;
if ( ! V_3 ) {
F_3 ( V_1 , L_4 ) ;
return;
}
F_8 ( V_1 , V_6 , V_3 -> V_4 ) ;
F_12 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
void F_13 ( T_1 * V_1 , T_4 * V_7 ) {
T_3 * V_3 = ( T_3 * ) F_2 ( sizeof( T_3 ) ) ;
if ( V_7 -> V_3 != NULL ) {
F_3 ( V_1 , L_5 ) ;
return;
}
V_3 -> V_4 = V_5 ;
V_7 -> V_3 = ( void * ) V_3 ;
}
int F_14 ( T_1 * V_1 , T_4 * V_7 ) {
T_3 * V_3 = ( T_3 * ) V_7 -> V_3 ;
if ( ! V_3 ) {
F_3 ( V_1 , L_6 ) ;
return V_5 ;
}
F_5 ( V_1 , V_6 , V_3 -> V_4 ) ;
return 1 ;
}
int F_15 ( T_1 * V_1 , T_4 * V_7 ) {
T_3 * V_3 = ( T_3 * ) V_7 -> V_3 ;
if ( ! V_3 ) {
F_3 ( V_1 , L_2 ) ;
return 0 ;
}
if ( F_7 ( V_1 , - 1 ) ) {
F_8 ( V_1 , V_6 , V_3 -> V_4 ) ;
V_3 -> V_4 = V_5 ;
return 0 ;
}
if ( ! F_9 ( V_1 , - 1 ) ) {
F_3 ( V_1 , L_3 ) ;
return 0 ;
}
if ( V_3 -> V_4 != V_5 ) {
F_8 ( V_1 , V_6 , V_3 -> V_4 ) ;
}
V_3 -> V_4 = F_10 ( V_1 , V_6 ) ;
return 0 ;
}
void F_16 ( T_1 * V_1 , T_4 * V_7 ) {
T_3 * V_3 = ( T_3 * ) V_7 -> V_3 ;
if ( ! V_3 ) {
F_3 ( V_1 , L_7 ) ;
return;
}
F_8 ( V_1 , V_6 , V_3 -> V_4 ) ;
}
