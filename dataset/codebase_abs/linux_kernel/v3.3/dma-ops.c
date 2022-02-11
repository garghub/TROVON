static unsigned F_1 ( enum V_1 V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
struct V_7 V_8 ;
void * V_9 ;
F_2 ( V_6 ) ;
F_3 ( V_3 -> V_10 , V_6 ) ;
V_9 = ( V_1 == V_11 ) ? ( void * ) V_3 -> V_12 :
( void * ) V_1 ;
V_5 = F_4 ( V_6 , V_13 , V_9 ) ;
if ( V_3 -> V_14 == V_15 ) {
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_14 = V_3 -> V_14 ;
V_8 . V_16 = V_3 -> V_17 ;
V_8 . V_18 = V_3 -> V_19 ;
V_8 . V_20 = 1 ;
F_5 ( V_5 , & V_8 ) ;
} else if ( V_3 -> V_14 == V_21 ) {
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_14 = V_3 -> V_14 ;
V_8 . V_22 = V_3 -> V_17 ;
V_8 . V_23 = V_3 -> V_19 ;
V_8 . V_24 = 1 ;
F_5 ( V_5 , & V_8 ) ;
}
return ( unsigned ) V_5 ;
}
static int F_6 ( unsigned V_25 ,
struct V_26 * V_27 )
{
F_7 ( (struct V_4 * ) V_25 ) ;
return 0 ;
}
static int F_8 ( unsigned V_25 ,
struct V_28 * V_3 )
{
struct V_29 V_30 ;
struct V_4 * V_5 = (struct V_4 * ) V_25 ;
struct V_31 * V_32 ;
switch ( V_3 -> V_10 ) {
case V_33 :
F_9 ( & V_30 , 1 ) ;
F_10 ( & V_30 ) = V_3 -> V_34 ;
F_11 ( & V_30 , F_12 ( F_13 ( V_3 -> V_35 ) ) ,
V_3 -> V_34 , F_14 ( V_3 -> V_35 ) ) ;
F_15 ( & V_30 ) = V_3 -> V_35 ;
V_32 = V_5 -> V_36 -> V_37 ( V_5 ,
& V_30 , 1 , V_3 -> V_14 , V_38 ) ;
break;
case V_39 :
V_32 = V_5 -> V_36 -> V_40 ( V_5 ,
V_3 -> V_35 , V_3 -> V_34 , V_3 -> V_41 , V_3 -> V_14 ) ;
break;
default:
F_16 ( & V_5 -> V_42 -> V_36 , L_1 ) ;
return - V_43 ;
}
if ( ! V_32 ) {
F_16 ( & V_5 -> V_42 -> V_36 , L_2 ) ;
return - V_43 ;
}
V_32 -> V_44 = V_3 -> V_45 ;
V_32 -> V_46 = V_3 -> V_47 ;
F_17 ( (struct V_31 * ) V_32 ) ;
return 0 ;
}
static inline int F_18 ( unsigned V_25 )
{
F_19 ( (struct V_4 * ) V_25 ) ;
return 0 ;
}
static inline int F_20 ( unsigned V_25 )
{
return F_21 ( (struct V_4 * ) V_25 ) ;
}
void * F_22 ( void )
{
return & V_48 ;
}
