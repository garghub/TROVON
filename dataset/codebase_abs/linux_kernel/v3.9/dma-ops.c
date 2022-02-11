static unsigned F_1 ( enum V_1 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 , char * V_6 )
{
T_1 V_7 ;
void * V_8 ;
F_2 ( V_7 ) ;
F_3 ( V_3 -> V_9 , V_7 ) ;
V_8 = ( V_1 == V_10 ) ?
( void * ) V_3 -> V_11 : ( void * ) V_1 ;
if ( V_5 -> V_12 )
return ( unsigned ) F_4 ( V_5 , V_6 ) ;
else
return ( unsigned ) F_5 ( V_7 , V_13 ,
V_8 ) ;
}
static int F_6 ( unsigned V_14 , void * V_3 )
{
F_7 ( (struct V_15 * ) V_14 ) ;
return 0 ;
}
static int F_8 ( unsigned V_14 ,
struct V_16 * V_3 )
{
struct V_15 * V_17 = (struct V_15 * ) V_14 ;
struct V_18 V_19 ;
if ( V_3 -> V_20 == V_21 ) {
memset ( & V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 . V_20 = V_3 -> V_20 ;
V_19 . V_22 = V_3 -> V_23 ;
V_19 . V_24 = V_3 -> V_25 ;
V_19 . V_26 = 1 ;
F_9 ( V_17 , & V_19 ) ;
} else if ( V_3 -> V_20 == V_27 ) {
memset ( & V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 . V_20 = V_3 -> V_20 ;
V_19 . V_28 = V_3 -> V_23 ;
V_19 . V_29 = V_3 -> V_25 ;
V_19 . V_30 = 1 ;
F_9 ( V_17 , & V_19 ) ;
} else {
F_10 ( L_1 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_11 ( unsigned V_14 ,
struct V_32 * V_3 )
{
struct V_33 V_34 ;
struct V_15 * V_17 = (struct V_15 * ) V_14 ;
struct V_35 * V_36 ;
switch ( V_3 -> V_9 ) {
case V_37 :
F_12 ( & V_34 , 1 ) ;
F_13 ( & V_34 ) = V_3 -> V_38 ;
F_14 ( & V_34 , F_15 ( F_16 ( V_3 -> V_39 ) ) ,
V_3 -> V_38 , F_17 ( V_3 -> V_39 ) ) ;
F_18 ( & V_34 ) = V_3 -> V_39 ;
V_36 = F_19 ( V_17 ,
& V_34 , 1 , V_3 -> V_20 , V_40 ) ;
break;
case V_41 :
V_36 = F_20 ( V_17 , V_3 -> V_39 ,
V_3 -> V_38 , V_3 -> V_42 , V_3 -> V_20 ,
V_40 | V_43 ) ;
break;
default:
F_21 ( & V_17 -> V_5 -> V_4 , L_2 ) ;
return - V_44 ;
}
if ( ! V_36 ) {
F_21 ( & V_17 -> V_5 -> V_4 , L_3 ) ;
return - V_44 ;
}
V_36 -> V_45 = V_3 -> V_46 ;
V_36 -> V_47 = V_3 -> V_48 ;
F_22 ( (struct V_35 * ) V_36 ) ;
return 0 ;
}
static inline int F_23 ( unsigned V_14 )
{
F_24 ( (struct V_15 * ) V_14 ) ;
return 0 ;
}
static inline int F_25 ( unsigned V_14 )
{
return F_26 ( (struct V_15 * ) V_14 ) ;
}
void * F_27 ( void )
{
return & V_49 ;
}
