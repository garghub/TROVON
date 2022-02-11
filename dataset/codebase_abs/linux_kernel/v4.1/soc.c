struct V_1 * T_1 F_1 ( const struct V_2 * V_3 )
{
struct V_4 * V_5 ;
const struct V_2 * V_6 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
void T_2 * V_10 ;
T_3 V_11 , V_12 ;
V_9 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_9 )
V_9 = F_2 ( NULL , NULL ,
L_2 ) ;
if ( ! V_9 ) {
F_3 ( L_3 ) ;
return NULL ;
}
V_10 = F_4 ( V_9 , 0 ) ;
F_5 ( V_9 ) ;
if ( ! V_10 ) {
F_3 ( L_4 ) ;
return NULL ;
}
V_11 = F_6 ( V_10 + V_13 ) ;
V_12 = F_6 ( V_10 + V_14 ) ;
F_7 ( V_10 ) ;
for ( V_6 = V_3 ; V_6 -> V_15 ; V_6 ++ ) {
if ( V_6 -> V_16 != ( V_11 & V_17 ) )
continue;
if ( ! ( V_11 & V_18 ) || V_6 -> V_19 == V_12 )
break;
}
if ( ! V_6 -> V_15 ) {
F_3 ( L_5 ) ;
return NULL ;
}
V_5 = F_8 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_21 = V_6 -> V_21 ;
V_5 -> V_22 = V_6 -> V_15 ;
V_5 -> V_23 = F_9 ( V_20 , L_6 ,
F_10 ( V_11 ) ) ;
V_7 = F_11 ( V_5 ) ;
if ( F_12 ( V_7 ) ) {
F_13 ( V_5 -> V_23 ) ;
F_13 ( V_5 ) ;
F_3 ( L_7 ) ;
return NULL ;
}
if ( V_6 -> V_21 )
F_14 ( L_8 , V_6 -> V_21 ) ;
F_14 ( L_9 , V_6 -> V_15 ,
F_10 ( V_11 ) ) ;
return V_7 ;
}
