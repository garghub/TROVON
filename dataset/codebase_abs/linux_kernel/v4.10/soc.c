static int T_1 F_1 ( T_2 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 ;
void T_3 * V_5 ;
V_4 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_4 )
V_4 = F_2 ( NULL , NULL ,
L_2 ) ;
if ( ! V_4 )
return - V_6 ;
V_5 = F_3 ( V_4 , 0 ) ;
F_4 ( V_4 ) ;
if ( ! V_5 ) {
F_5 ( L_3 ) ;
return - V_7 ;
}
* V_1 = F_6 ( V_5 + V_8 ) ;
* V_2 = F_6 ( V_5 + V_9 ) ;
F_7 ( V_5 ) ;
return 0 ;
}
static int T_1 F_8 ( T_2 * V_1 , T_2 * V_2 )
{
struct V_3 * V_4 ;
void T_3 * V_5 ;
V_4 = F_2 ( NULL , NULL , L_4 ) ;
if ( ! V_4 )
return - V_6 ;
V_5 = F_3 ( V_4 , 0 ) ;
F_4 ( V_4 ) ;
if ( ! V_5 ) {
F_5 ( L_3 ) ;
return - V_7 ;
}
* V_1 = F_6 ( V_5 + V_10 ) ;
* V_2 = F_6 ( V_5 + V_11 ) ;
F_7 ( V_5 ) ;
return 0 ;
}
struct V_12 * T_1 F_9 ( const struct V_13 * V_14 )
{
struct V_15 * V_16 ;
const struct V_13 * V_17 ;
struct V_12 * V_18 ;
T_2 V_1 , V_2 ;
int V_19 ;
V_19 = F_1 ( & V_1 , & V_2 ) ;
if ( V_19 )
V_19 = F_8 ( & V_1 , & V_2 ) ;
if ( V_19 ) {
if ( V_19 == - V_6 )
F_5 ( L_5 ) ;
return NULL ;
}
for ( V_17 = V_14 ; V_17 -> V_20 ; V_17 ++ ) {
if ( V_17 -> V_21 != ( V_1 & V_22 ) )
continue;
if ( ! ( V_1 & V_23 ) || V_17 -> V_24 == V_2 )
break;
}
if ( ! V_17 -> V_20 ) {
F_5 ( L_6 ) ;
return NULL ;
}
V_16 = F_10 ( sizeof( * V_16 ) , V_25 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_26 = V_17 -> V_26 ;
V_16 -> V_27 = V_17 -> V_20 ;
V_16 -> V_28 = F_11 ( V_25 , L_7 ,
F_12 ( V_1 ) ) ;
V_18 = F_13 ( V_16 ) ;
if ( F_14 ( V_18 ) ) {
F_15 ( V_16 -> V_28 ) ;
F_15 ( V_16 ) ;
F_5 ( L_8 ) ;
return NULL ;
}
if ( V_17 -> V_26 )
F_16 ( L_9 , V_17 -> V_26 ) ;
F_16 ( L_10 , V_17 -> V_20 ,
F_12 ( V_1 ) ) ;
return V_18 ;
}
