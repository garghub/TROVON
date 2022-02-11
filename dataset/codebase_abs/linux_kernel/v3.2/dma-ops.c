static inline bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return V_5 -> V_7 == ( unsigned ) V_3 ;
}
static unsigned F_2 ( enum V_8 V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 ;
struct V_12 V_13 ;
F_3 ( V_11 ) ;
F_4 ( V_10 -> V_14 , V_11 ) ;
V_2 = F_5 ( V_11 , F_1 , ( void * ) V_8 ) ;
if ( V_10 -> V_15 == V_16 ) {
memset ( & V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 . V_15 = V_10 -> V_15 ;
V_13 . V_17 = V_10 -> V_18 ;
V_13 . V_19 = V_10 -> V_20 ;
V_13 . V_21 = 1 ;
F_6 ( V_2 , & V_13 ) ;
} else if ( V_10 -> V_15 == V_22 ) {
memset ( & V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 . V_15 = V_10 -> V_15 ;
V_13 . V_23 = V_10 -> V_18 ;
V_13 . V_24 = V_10 -> V_20 ;
V_13 . V_25 = 1 ;
F_6 ( V_2 , & V_13 ) ;
}
return ( unsigned ) V_2 ;
}
static int F_7 ( unsigned V_26 ,
struct V_27 * V_28 )
{
F_8 ( (struct V_1 * ) V_26 ) ;
return 0 ;
}
static int F_9 ( unsigned V_26 ,
struct V_29 * V_10 )
{
struct V_30 V_31 ;
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
struct V_32 * V_33 ;
switch ( V_10 -> V_14 ) {
case V_34 :
F_10 ( & V_31 , 1 ) ;
F_11 ( & V_31 ) = V_10 -> V_35 ;
F_12 ( & V_31 , F_13 ( F_14 ( V_10 -> V_36 ) ) ,
V_10 -> V_35 , F_15 ( V_10 -> V_36 ) ) ;
F_16 ( & V_31 ) = V_10 -> V_36 ;
V_33 = V_2 -> V_37 -> V_38 ( V_2 ,
& V_31 , 1 , V_10 -> V_15 , V_39 ) ;
break;
case V_40 :
V_33 = V_2 -> V_37 -> V_41 ( V_2 ,
V_10 -> V_36 , V_10 -> V_35 , V_10 -> V_42 , V_10 -> V_15 ) ;
break;
default:
F_17 ( & V_2 -> V_43 -> V_37 , L_1 ) ;
return - V_44 ;
}
if ( ! V_33 ) {
F_17 ( & V_2 -> V_43 -> V_37 , L_2 ) ;
return - V_44 ;
}
V_33 -> V_45 = V_10 -> V_46 ;
V_33 -> V_47 = V_10 -> V_48 ;
F_18 ( (struct V_32 * ) V_33 ) ;
return 0 ;
}
static inline int F_19 ( unsigned V_26 )
{
F_20 ( (struct V_1 * ) V_26 ) ;
return 0 ;
}
static inline int F_21 ( unsigned V_26 )
{
return F_22 ( (struct V_1 * ) V_26 ) ;
}
void * F_23 ( void )
{
return & V_49 ;
}
