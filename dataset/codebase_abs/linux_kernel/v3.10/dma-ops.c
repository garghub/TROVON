static unsigned F_1 ( enum V_1 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 , char * V_6 )
{
T_1 V_7 ;
F_2 ( V_7 ) ;
F_3 ( V_3 -> V_8 , V_7 ) ;
if ( V_5 -> V_9 )
return ( unsigned ) F_4 ( V_5 , V_6 ) ;
else
return ( unsigned ) F_5 ( V_7 , V_10 ,
( void * ) V_1 ) ;
}
static int F_6 ( unsigned V_11 , void * V_3 )
{
F_7 ( (struct V_12 * ) V_11 ) ;
return 0 ;
}
static int F_8 ( unsigned V_11 ,
struct V_13 * V_3 )
{
struct V_12 * V_14 = (struct V_12 * ) V_11 ;
struct V_15 V_16 ;
if ( V_3 -> V_17 == V_18 ) {
memset ( & V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 . V_17 = V_3 -> V_17 ;
V_16 . V_19 = V_3 -> V_20 ;
V_16 . V_21 = V_3 -> V_22 ;
V_16 . V_23 = 1 ;
F_9 ( V_14 , & V_16 ) ;
} else if ( V_3 -> V_17 == V_24 ) {
memset ( & V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 . V_17 = V_3 -> V_17 ;
V_16 . V_25 = V_3 -> V_20 ;
V_16 . V_26 = V_3 -> V_22 ;
V_16 . V_27 = 1 ;
F_9 ( V_14 , & V_16 ) ;
} else {
F_10 ( L_1 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_11 ( unsigned V_11 ,
struct V_29 * V_3 )
{
struct V_30 V_31 ;
struct V_12 * V_14 = (struct V_12 * ) V_11 ;
struct V_32 * V_33 ;
switch ( V_3 -> V_8 ) {
case V_34 :
F_12 ( & V_31 , 1 ) ;
F_13 ( & V_31 ) = V_3 -> V_35 ;
F_14 ( & V_31 , F_15 ( F_16 ( V_3 -> V_36 ) ) ,
V_3 -> V_35 , F_17 ( V_3 -> V_36 ) ) ;
F_18 ( & V_31 ) = V_3 -> V_36 ;
V_33 = F_19 ( V_14 ,
& V_31 , 1 , V_3 -> V_17 , V_37 ) ;
break;
case V_38 :
V_33 = F_20 ( V_14 , V_3 -> V_36 ,
V_3 -> V_35 , V_3 -> V_39 , V_3 -> V_17 ,
V_37 | V_40 ) ;
break;
default:
F_21 ( & V_14 -> V_5 -> V_4 , L_2 ) ;
return - V_41 ;
}
if ( ! V_33 ) {
F_21 ( & V_14 -> V_5 -> V_4 , L_3 ) ;
return - V_41 ;
}
V_33 -> V_42 = V_3 -> V_43 ;
V_33 -> V_44 = V_3 -> V_45 ;
F_22 ( (struct V_32 * ) V_33 ) ;
return 0 ;
}
static inline int F_23 ( unsigned V_11 )
{
F_24 ( (struct V_12 * ) V_11 ) ;
return 0 ;
}
static inline int F_25 ( unsigned V_11 )
{
return F_26 ( (struct V_12 * ) V_11 ) ;
}
void * F_27 ( void )
{
return & V_46 ;
}
