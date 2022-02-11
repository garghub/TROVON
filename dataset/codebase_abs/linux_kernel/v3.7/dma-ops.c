static unsigned F_1 ( enum V_1 V_1 ,
struct V_2 * V_3 )
{
T_1 V_4 ;
void * V_5 ;
F_2 ( V_4 ) ;
F_3 ( V_3 -> V_6 , V_4 ) ;
V_5 = ( V_1 == V_7 ) ?
( void * ) V_3 -> V_8 : ( void * ) V_1 ;
return ( unsigned ) F_4 ( V_4 , V_9 , V_5 ) ;
}
static int F_5 ( unsigned V_10 , void * V_3 )
{
F_6 ( (struct V_11 * ) V_10 ) ;
return 0 ;
}
static int F_7 ( unsigned V_10 ,
struct V_12 * V_3 )
{
struct V_11 * V_13 = (struct V_11 * ) V_10 ;
struct V_14 V_15 ;
if ( V_3 -> V_16 == V_17 ) {
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_16 = V_3 -> V_16 ;
V_15 . V_18 = V_3 -> V_19 ;
V_15 . V_20 = V_3 -> V_21 ;
V_15 . V_22 = 1 ;
F_8 ( V_13 , & V_15 ) ;
} else if ( V_3 -> V_16 == V_23 ) {
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_16 = V_3 -> V_16 ;
V_15 . V_24 = V_3 -> V_19 ;
V_15 . V_25 = V_3 -> V_21 ;
V_15 . V_26 = 1 ;
F_8 ( V_13 , & V_15 ) ;
} else {
F_9 ( L_1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_10 ( unsigned V_10 ,
struct V_28 * V_3 )
{
struct V_29 V_30 ;
struct V_11 * V_13 = (struct V_11 * ) V_10 ;
struct V_31 * V_32 ;
switch ( V_3 -> V_6 ) {
case V_33 :
F_11 ( & V_30 , 1 ) ;
F_12 ( & V_30 ) = V_3 -> V_34 ;
F_13 ( & V_30 , F_14 ( F_15 ( V_3 -> V_35 ) ) ,
V_3 -> V_34 , F_16 ( V_3 -> V_35 ) ) ;
F_17 ( & V_30 ) = V_3 -> V_35 ;
V_32 = F_18 ( V_13 ,
& V_30 , 1 , V_3 -> V_16 , V_36 ) ;
break;
case V_37 :
V_32 = F_19 ( V_13 , V_3 -> V_35 ,
V_3 -> V_34 , V_3 -> V_38 , V_3 -> V_16 ,
V_36 | V_39 ) ;
break;
default:
F_20 ( & V_13 -> V_40 -> V_41 , L_2 ) ;
return - V_42 ;
}
if ( ! V_32 ) {
F_20 ( & V_13 -> V_40 -> V_41 , L_3 ) ;
return - V_42 ;
}
V_32 -> V_43 = V_3 -> V_44 ;
V_32 -> V_45 = V_3 -> V_46 ;
F_21 ( (struct V_31 * ) V_32 ) ;
return 0 ;
}
static inline int F_22 ( unsigned V_10 )
{
F_23 ( (struct V_11 * ) V_10 ) ;
return 0 ;
}
static inline int F_24 ( unsigned V_10 )
{
return F_25 ( (struct V_11 * ) V_10 ) ;
}
void * F_26 ( void )
{
return & V_47 ;
}
