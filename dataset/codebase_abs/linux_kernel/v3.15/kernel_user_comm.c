int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
T_1 V_6 = V_5 -> V_7 ;
T_2 V_8 = 0 ;
T_3 V_9 ;
int V_10 = - V_11 ;
if ( V_2 == NULL || F_2 ( V_2 ) )
return - V_12 ;
if ( V_5 -> V_13 != V_14 ) {
F_3 ( L_1 , V_5 -> V_13 ) ;
return - V_11 ;
}
V_9 = F_4 () ;
F_5 ( V_15 ) ;
while ( V_6 > 0 ) {
V_10 = F_6 ( V_2 , ( void V_16 V_17 * ) V_3 ,
V_6 , & V_8 ) ;
if ( V_10 < 0 )
break;
V_6 -= V_10 ;
V_3 += V_10 ;
V_10 = 0 ;
}
F_5 ( V_9 ) ;
if ( V_10 < 0 )
F_7 ( L_2 , V_10 ) ;
else
F_8 ( V_18 , L_3 , V_10 , V_2 ) ;
return V_10 ;
}
int F_9 ( struct V_1 * V_2 , int V_19 , int V_20 , T_4 V_21 )
{
struct V_22 * V_23 ;
if ( V_20 > V_24 ) {
F_8 ( V_25 , L_4 , V_20 ) ;
return - V_26 ;
}
if ( V_2 == NULL )
return - V_12 ;
V_23 = F_10 ( sizeof( * V_23 ) , 0 ) ;
if ( V_23 == NULL )
return - V_27 ;
V_23 -> V_28 = V_2 ;
V_23 -> V_29 = V_19 ;
V_23 -> V_30 = V_21 ;
F_11 ( & V_31 ) ;
if ( V_32 [ V_20 ] . V_33 == NULL )
F_12 ( & V_32 [ V_20 ] ) ;
F_13 ( & V_23 -> V_34 , & V_32 [ V_20 ] ) ;
F_14 ( & V_31 ) ;
F_8 ( V_18 , L_5 , V_19 , V_2 , V_20 ) ;
return 0 ;
}
int F_15 ( int V_19 , int V_20 )
{
struct V_22 * V_23 , * V_33 ;
if ( V_32 [ V_20 ] . V_33 == NULL )
return 0 ;
if ( V_19 == 0 ) {
struct V_4 V_35 ;
V_35 . V_13 = V_14 ;
V_35 . V_36 = V_37 ;
V_35 . V_38 = V_39 ;
V_35 . V_7 = sizeof( V_35 ) ;
F_16 ( V_20 , & V_35 ) ;
}
F_11 ( & V_31 ) ;
F_17 (reg, next, &kkuc_groups[group], kr_chain) {
if ( ( V_19 == 0 ) || ( V_19 == V_23 -> V_29 ) ) {
F_18 ( & V_23 -> V_34 ) ;
F_8 ( V_18 , L_6 ,
V_23 -> V_29 , V_23 -> V_28 , V_20 ) ;
if ( V_23 -> V_28 != NULL )
F_19 ( V_23 -> V_28 ) ;
F_20 ( V_23 ) ;
}
}
F_14 ( & V_31 ) ;
return 0 ;
}
int F_16 ( int V_20 , void * V_3 )
{
struct V_22 * V_23 ;
int V_10 = 0 ;
int V_40 = 0 ;
F_21 ( & V_31 ) ;
F_22 (reg, &kkuc_groups[group], kr_chain) {
if ( V_23 -> V_28 != NULL ) {
V_10 = F_1 ( V_23 -> V_28 , V_3 ) ;
if ( V_10 == 0 )
V_40 = 1 ;
else if ( V_10 == - V_41 ) {
F_19 ( V_23 -> V_28 ) ;
V_23 -> V_28 = NULL ;
}
}
}
F_23 ( & V_31 ) ;
if ( V_40 )
V_10 = 0 ;
return V_10 ;
}
int F_24 ( int V_20 , T_5 V_42 ,
void * V_43 )
{
struct V_22 * V_23 ;
int V_10 = 0 ;
if ( V_20 > V_24 ) {
F_8 ( V_25 , L_4 , V_20 ) ;
return - V_26 ;
}
if ( V_32 [ V_20 ] . V_33 == NULL )
return 0 ;
F_21 ( & V_31 ) ;
F_22 (reg, &kkuc_groups[group], kr_chain) {
if ( V_23 -> V_28 != NULL )
V_10 = V_42 ( V_23 -> V_30 , V_43 ) ;
}
F_23 ( & V_31 ) ;
return V_10 ;
}
