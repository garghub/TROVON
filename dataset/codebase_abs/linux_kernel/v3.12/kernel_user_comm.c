int F_1 ( T_1 * V_1 , int V_2 )
{
int V_3 [ 2 ] ;
if ( F_2 ( V_3 ) < 0 )
return - V_4 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_5 = V_3 [ 0 ] ;
V_1 -> V_6 = V_3 [ 1 ] ;
V_1 -> V_7 = V_2 ;
V_1 -> V_8 = F_3 () ;
return 0 ;
}
int F_4 ( T_1 * V_1 )
{
if ( V_1 -> V_6 > 0 )
F_5 ( V_1 -> V_6 ) ;
return F_5 ( V_1 -> V_5 ) ;
}
int F_6 ( T_1 * V_1 , char * V_9 , int V_10 ,
int V_11 )
{
struct V_12 * V_13 ;
int V_14 = 0 ;
memset ( V_9 , 0 , V_10 ) ;
F_7 ( V_15 , L_1 ,
V_1 -> V_5 ) ;
while ( 1 ) {
V_14 = F_8 ( V_1 -> V_5 , V_9 , V_16 ) ;
if ( V_14 <= 0 ) {
V_14 = - V_4 ;
break;
}
V_13 = (struct V_12 * ) V_9 ;
F_7 ( V_15 , L_2 ,
V_13 -> V_17 , V_13 -> V_18 , V_13 -> V_19 ,
V_13 -> V_20 ) ;
if ( V_13 -> V_17 != V_21 ) {
F_9 ( L_3 ,
V_13 -> V_17 , V_21 ) ;
V_14 = - V_22 ;
break;
}
if ( V_13 -> V_20 > V_10 ) {
V_14 = - V_23 ;
break;
}
V_14 = F_8 ( V_1 -> V_5 , V_9 + V_16 , V_13 -> V_20 - V_16 ) ;
if ( V_14 < 0 ) {
V_14 = - V_4 ;
break;
}
if ( V_14 < ( V_13 -> V_20 - V_16 ) ) {
F_9 ( L_4 ,
V_14 , V_13 -> V_20 ) ;
V_14 = - V_22 ;
break;
}
if ( V_13 -> V_18 == V_11 ||
V_13 -> V_18 == V_24 ) {
return 0 ;
}
}
return V_14 ;
}
int F_10 ( struct V_25 * V_26 , void * V_27 )
{
struct V_12 * V_13 = (struct V_12 * ) V_27 ;
T_2 V_28 = V_13 -> V_20 ;
T_3 V_29 = 0 ;
T_4 V_30 ;
int V_14 = - V_31 ;
if ( V_26 == NULL || F_11 ( V_26 ) )
return - V_32 ;
if ( V_13 -> V_17 != V_21 ) {
F_9 ( L_5 , V_13 -> V_17 ) ;
return - V_31 ;
}
V_30 = F_12 () ;
F_13 ( V_33 ) ;
while ( V_28 > 0 ) {
V_14 = F_14 ( V_26 , ( void V_34 V_35 * ) V_27 ,
V_28 , & V_29 ) ;
if ( V_14 < 0 )
break;
V_28 -= V_14 ;
V_27 += V_14 ;
V_14 = 0 ;
}
F_13 ( V_30 ) ;
if ( V_14 < 0 )
F_15 ( L_6 , V_14 ) ;
else
F_7 ( V_15 , L_7 , V_14 , V_26 ) ;
return V_14 ;
}
int F_16 ( struct V_25 * V_26 , int V_36 , int V_2 , T_5 V_37 )
{
struct V_38 * V_39 ;
if ( V_2 > V_40 ) {
F_7 ( V_41 , L_8 , V_2 ) ;
return - V_42 ;
}
if ( V_26 == NULL )
return - V_32 ;
V_39 = F_17 ( sizeof( * V_39 ) , 0 ) ;
if ( V_39 == NULL )
return - V_43 ;
V_39 -> V_44 = V_26 ;
V_39 -> V_45 = V_36 ;
V_39 -> V_46 = V_37 ;
F_18 ( & V_47 ) ;
if ( V_48 [ V_2 ] . V_49 == NULL )
F_19 ( & V_48 [ V_2 ] ) ;
F_20 ( & V_39 -> V_50 , & V_48 [ V_2 ] ) ;
F_21 ( & V_47 ) ;
F_7 ( V_15 , L_9 , V_36 , V_26 , V_2 ) ;
return 0 ;
}
int F_22 ( int V_36 , int V_2 )
{
struct V_38 * V_39 , * V_49 ;
if ( V_48 [ V_2 ] . V_49 == NULL )
return 0 ;
if ( V_36 == 0 ) {
struct V_12 V_51 ;
V_51 . V_17 = V_21 ;
V_51 . V_18 = V_24 ;
V_51 . V_19 = V_52 ;
V_51 . V_20 = sizeof( V_51 ) ;
F_23 ( V_2 , & V_51 ) ;
}
F_18 ( & V_47 ) ;
F_24 (reg, next, &kkuc_groups[group], kr_chain) {
if ( ( V_36 == 0 ) || ( V_36 == V_39 -> V_45 ) ) {
F_25 ( & V_39 -> V_50 ) ;
F_7 ( V_15 , L_10 ,
V_39 -> V_45 , V_39 -> V_44 , V_2 ) ;
if ( V_39 -> V_44 != NULL )
F_26 ( V_39 -> V_44 ) ;
F_27 ( V_39 ) ;
}
}
F_21 ( & V_47 ) ;
return 0 ;
}
int F_23 ( int V_2 , void * V_27 )
{
struct V_38 * V_39 ;
int V_14 = 0 ;
int V_53 = 0 ;
F_28 ( & V_47 ) ;
F_29 (reg, &kkuc_groups[group], kr_chain) {
if ( V_39 -> V_44 != NULL ) {
V_14 = F_10 ( V_39 -> V_44 , V_27 ) ;
if ( V_14 == 0 )
V_53 = 1 ;
else if ( V_14 == - V_54 ) {
F_26 ( V_39 -> V_44 ) ;
V_39 -> V_44 = NULL ;
}
}
}
F_30 ( & V_47 ) ;
if ( V_53 )
V_14 = 0 ;
return V_14 ;
}
int F_31 ( int V_2 , T_6 V_55 ,
void * V_56 )
{
struct V_38 * V_39 ;
int V_14 = 0 ;
if ( V_2 > V_40 ) {
F_7 ( V_41 , L_8 , V_2 ) ;
return - V_42 ;
}
if ( V_48 [ V_2 ] . V_49 == NULL )
return 0 ;
F_28 ( & V_47 ) ;
F_29 (reg, &kkuc_groups[group], kr_chain) {
if ( V_39 -> V_44 != NULL ) {
V_14 = V_55 ( V_39 -> V_46 , V_56 ) ;
}
}
F_30 ( & V_47 ) ;
return V_14 ;
}
