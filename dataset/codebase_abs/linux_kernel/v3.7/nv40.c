static inline int
F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 & 0xf0 ) == 0x60 )
return 1 ;
return ! ( 0x0baf & ( 1 << ( V_2 -> V_3 & 0x0f ) ) ) ;
}
static void
F_2 ( struct V_4 * V_5 , int V_6 , struct V_7 * V_8 )
{
F_3 ( V_5 , 0x100604 + ( V_6 * 0x10 ) , V_8 -> V_9 ) ;
F_3 ( V_5 , 0x100608 + ( V_6 * 0x10 ) , V_8 -> V_10 ) ;
F_3 ( V_5 , 0x100600 + ( V_6 * 0x10 ) , V_8 -> V_11 ) ;
}
static void
F_4 ( struct V_12 * V_13 )
{
F_3 ( V_13 , 0x100800 , 0x00000001 ) ;
}
static void
F_5 ( struct V_12 * V_13 )
{
F_3 ( V_13 , 0x100850 , 0x80000000 ) ;
F_3 ( V_13 , 0x100800 , 0x00000001 ) ;
}
static int
F_6 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = ( void * ) V_15 ;
int V_16 ;
V_16 = F_7 ( & V_13 -> V_17 ) ;
if ( V_16 )
return V_16 ;
switch ( F_8 ( V_13 ) -> V_3 ) {
case 0x40 :
case 0x45 :
F_9 ( V_13 , 0x10033c , 0x00008000 , 0x00000000 ) ;
break;
default:
if ( F_1 ( F_8 ( V_13 ) ) )
F_5 ( V_13 ) ;
else
F_4 ( V_13 ) ;
break;
}
return 0 ;
}
static int
F_10 ( struct V_14 * V_18 , struct V_14 * V_19 ,
struct V_20 * V_21 , void * V_22 , T_1 V_23 ,
struct V_14 * * V_24 )
{
struct V_1 * V_2 = F_8 ( V_18 ) ;
struct V_12 * V_13 ;
int V_16 ;
V_16 = F_11 ( V_18 , V_19 , V_21 , & V_13 ) ;
* V_24 = F_12 ( V_13 ) ;
if ( V_16 )
return V_16 ;
if ( V_2 -> V_3 == 0x40 ) {
T_1 V_25 = F_13 ( V_13 , 0x001218 ) ;
switch ( V_25 & 0x00000300 ) {
case 0x00000000 : V_13 -> V_17 . V_26 . type = V_27 ; break;
case 0x00000100 : V_13 -> V_17 . V_26 . type = V_28 ; break;
case 0x00000200 : V_13 -> V_17 . V_26 . type = V_29 ; break;
case 0x00000300 : V_13 -> V_17 . V_26 . type = V_30 ; break;
}
} else
if ( V_2 -> V_3 == 0x49 || V_2 -> V_3 == 0x4b ) {
T_1 V_31 = F_13 ( V_13 , 0x100914 ) ;
switch ( V_31 & 0x00000003 ) {
case 0x00000000 : V_13 -> V_17 . V_26 . type = V_28 ; break;
case 0x00000001 : V_13 -> V_17 . V_26 . type = V_30 ; break;
case 0x00000002 : V_13 -> V_17 . V_26 . type = V_29 ; break;
case 0x00000003 : break;
}
} else
if ( V_2 -> V_3 != 0x4e ) {
T_1 V_32 = F_13 ( V_13 , 0x100474 ) ;
if ( V_32 & 0x00000004 )
V_13 -> V_17 . V_26 . type = V_29 ;
if ( V_32 & 0x00000002 )
V_13 -> V_17 . V_26 . type = V_30 ;
if ( V_32 & 0x00000001 )
V_13 -> V_17 . V_26 . type = V_28 ;
} else {
V_13 -> V_17 . V_26 . type = V_33 ;
}
V_13 -> V_17 . V_26 . V_23 = F_13 ( V_13 , 0x10020c ) & 0xff000000 ;
V_13 -> V_17 . V_34 = V_35 ;
switch ( V_2 -> V_3 ) {
case 0x40 :
case 0x45 :
V_13 -> V_17 . V_8 . V_36 = 8 ;
break;
case 0x46 :
case 0x47 :
case 0x49 :
case 0x4b :
case 0x4c :
V_13 -> V_17 . V_8 . V_36 = 15 ;
break;
default:
V_13 -> V_17 . V_8 . V_36 = 12 ;
break;
}
V_13 -> V_17 . V_8 . V_37 = V_38 ;
V_13 -> V_17 . V_8 . V_39 = V_40 ;
if ( V_2 -> V_3 == 0x40 )
V_13 -> V_17 . V_8 . V_41 = V_42 ;
else
V_13 -> V_17 . V_8 . V_41 = F_2 ;
return F_14 ( & V_13 -> V_17 ) ;
}
