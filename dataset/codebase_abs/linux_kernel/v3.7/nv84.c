static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 -> V_2 ;
struct V_8 * V_9 = ( void * ) V_3 ;
T_1 V_10 = V_9 -> V_11 + V_9 -> V_12 - 1 ;
T_1 V_13 = V_9 -> V_11 ;
T_2 V_11 ;
switch ( F_2 ( V_3 -> V_14 ) ) {
case V_15 : return 0 ;
case V_16 : V_11 = 0x0020 ; break;
case V_17 : V_11 = 0x0060 ; break;
case V_18 : V_11 = 0x00a0 ; break;
case V_19 : V_11 = 0x00c0 ; break;
default:
return - V_20 ;
}
F_3 ( V_9 ) -> V_11 = F_4 ( V_7 ) -> V_11 >> 12 ;
F_5 ( V_7 -> V_21 , V_11 + 0x00 , 0x00190000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x04 , F_6 ( V_10 ) ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x08 , F_6 ( V_13 ) ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x0c , F_7 ( V_10 ) << 24 |
F_7 ( V_13 ) ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x10 , 0x00000000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x14 , 0x00000000 ) ;
V_5 -> V_22 ( V_5 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , bool V_23 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_24 * V_25 = ( void * ) V_2 -> V_14 ;
struct V_6 * V_7 = ( void * ) V_2 -> V_2 ;
struct V_26 * V_27 = ( void * ) V_2 ;
T_2 V_11 , V_28 , V_29 ;
bool V_30 ;
switch ( F_2 ( V_3 -> V_14 ) ) {
case V_15 : return 0 ;
case V_16 : V_29 = 0 ; V_11 = 0x0020 ; break;
case V_17 : V_29 = 1 ; V_11 = 0x0060 ; break;
case V_18 : V_29 = 4 ; V_11 = 0x00a0 ; break;
case V_19 : V_29 = 2 ; V_11 = 0x00c0 ; break;
default:
return - V_20 ;
}
F_5 ( V_7 -> V_21 , V_11 + 0x00 , 0x00000000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x04 , 0x00000000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x08 , 0x00000000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x0c , 0x00000000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x10 , 0x00000000 ) ;
F_5 ( V_7 -> V_21 , V_11 + 0x14 , 0x00000000 ) ;
V_5 -> V_22 ( V_5 ) ;
V_28 = F_9 ( V_25 , 0x002520 , 0x0000003f , 1 << V_29 ) ;
F_10 ( V_25 , 0x0032fc , F_4 ( V_7 ) -> V_11 >> 12 ) ;
V_30 = F_11 ( V_25 , 0x0032fc , 0xffffffff , 0xffffffff ) ;
F_10 ( V_25 , 0x002520 , V_28 ) ;
if ( ! V_30 ) {
F_12 ( V_25 , L_1 , V_27 -> V_7 . V_31 ) ;
if ( V_23 )
return - V_32 ;
}
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
struct V_1 * V_3 , T_2 V_33 )
{
struct V_26 * V_27 = ( void * ) V_2 ;
T_2 V_34 ;
if ( F_14 ( V_3 , V_35 ) )
V_34 = F_4 ( V_3 ) -> V_36 -> V_37 >> 4 ;
else
V_34 = 0x00000004 ;
switch ( F_2 ( V_3 -> V_14 ) ) {
case V_38 :
case V_15 : V_34 |= 0x00000000 ; break;
case V_16 : V_34 |= 0x00100000 ; break;
case V_17 :
case V_39 : V_34 |= 0x00200000 ; break;
case V_40 :
case V_19 : V_34 |= 0x00300000 ; break;
case V_41 : V_34 |= 0x00400000 ; break;
case V_18 :
case V_42 : V_34 |= 0x00500000 ; break;
case V_43 : V_34 |= 0x00600000 ; break;
default:
return - V_20 ;
}
return F_15 ( V_27 -> V_44 , 0 , V_33 , V_34 ) ;
}
static int
F_16 ( struct V_1 * V_2 ,
struct V_1 * V_14 ,
struct V_45 * V_46 , void * V_47 , T_2 V_12 ,
struct V_1 * * V_48 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_26 * V_27 ;
struct V_49 * args = V_47 ;
int V_50 ;
if ( V_12 < sizeof( * args ) )
return - V_20 ;
V_50 = F_17 ( V_2 , V_14 , V_46 , 0 , 0xc00000 ,
0x2000 , args -> V_51 ,
( 1 << V_38 ) |
( 1 << V_15 ) |
( 1 << V_16 ) |
( 1 << V_17 ) |
( 1 << V_40 ) |
( 1 << V_41 ) |
( 1 << V_18 ) |
( 1 << V_43 ) |
( 1 << V_39 ) |
( 1 << V_19 ) |
( 1 << V_42 ) , & V_27 ) ;
* V_48 = F_18 ( V_27 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_19 ( V_2 , V_2 , 0x8000 , 16 , & V_27 -> V_44 ) ;
if ( V_50 )
return V_50 ;
F_20 ( V_27 ) -> V_52 = F_1 ;
F_20 ( V_27 ) -> V_53 = F_8 ;
F_20 ( V_27 ) -> V_54 = F_13 ;
F_20 ( V_27 ) -> V_55 = V_56 ;
F_5 ( V_7 -> V_57 , 0x08 , F_6 ( args -> V_37 ) ) ;
F_5 ( V_7 -> V_57 , 0x0c , F_7 ( args -> V_37 ) ) ;
F_5 ( V_7 -> V_57 , 0x10 , F_6 ( args -> V_37 ) ) ;
F_5 ( V_7 -> V_57 , 0x14 , F_7 ( args -> V_37 ) ) ;
F_5 ( V_7 -> V_57 , 0x3c , 0x003f6078 ) ;
F_5 ( V_7 -> V_57 , 0x44 , 0x01003fff ) ;
F_5 ( V_7 -> V_57 , 0x48 , V_27 -> V_7 . V_58 -> V_36 -> V_37 >> 4 ) ;
F_5 ( V_7 -> V_57 , 0x4c , 0xffffffff ) ;
F_5 ( V_7 -> V_57 , 0x60 , 0x7fffffff ) ;
F_5 ( V_7 -> V_57 , 0x78 , 0x00000000 ) ;
F_5 ( V_7 -> V_57 , 0x7c , 0x30000001 ) ;
F_5 ( V_7 -> V_57 , 0x80 , ( ( V_27 -> V_44 -> V_59 - 9 ) << 27 ) |
( 4 << 24 ) |
( V_27 -> V_44 -> V_7 . V_36 -> V_37 >> 4 ) ) ;
F_5 ( V_7 -> V_57 , 0x88 , V_7 -> V_60 -> V_11 >> 10 ) ;
F_5 ( V_7 -> V_57 , 0x98 , F_4 ( V_7 ) -> V_11 >> 12 ) ;
V_5 -> V_22 ( V_5 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 ,
struct V_1 * V_14 ,
struct V_45 * V_46 , void * V_47 , T_2 V_12 ,
struct V_1 * * V_48 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_26 * V_27 ;
struct V_61 * args = V_47 ;
T_1 V_62 , V_63 ;
int V_50 ;
if ( V_12 < sizeof( * args ) )
return - V_20 ;
V_50 = F_17 ( V_2 , V_14 , V_46 , 0 , 0xc00000 ,
0x2000 , args -> V_51 ,
( 1 << V_38 ) |
( 1 << V_15 ) |
( 1 << V_16 ) |
( 1 << V_17 ) |
( 1 << V_40 ) |
( 1 << V_41 ) |
( 1 << V_18 ) |
( 1 << V_43 ) |
( 1 << V_39 ) |
( 1 << V_19 ) |
( 1 << V_42 ) , & V_27 ) ;
* V_48 = F_18 ( V_27 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_19 ( V_2 , V_2 , 0x8000 , 16 , & V_27 -> V_44 ) ;
if ( V_50 )
return V_50 ;
F_20 ( V_27 ) -> V_52 = F_1 ;
F_20 ( V_27 ) -> V_53 = F_8 ;
F_20 ( V_27 ) -> V_54 = F_13 ;
F_20 ( V_27 ) -> V_55 = V_56 ;
V_62 = args -> V_62 ;
V_63 = F_22 ( args -> V_63 / 8 ) ;
F_5 ( V_7 -> V_57 , 0x3c , 0x403f6078 ) ;
F_5 ( V_7 -> V_57 , 0x44 , 0x01003fff ) ;
F_5 ( V_7 -> V_57 , 0x48 , V_27 -> V_7 . V_58 -> V_36 -> V_37 >> 4 ) ;
F_5 ( V_7 -> V_57 , 0x50 , F_6 ( V_62 ) ) ;
F_5 ( V_7 -> V_57 , 0x54 , F_7 ( V_62 ) | ( V_63 << 16 ) ) ;
F_5 ( V_7 -> V_57 , 0x60 , 0x7fffffff ) ;
F_5 ( V_7 -> V_57 , 0x78 , 0x00000000 ) ;
F_5 ( V_7 -> V_57 , 0x7c , 0x30000001 ) ;
F_5 ( V_7 -> V_57 , 0x80 , ( ( V_27 -> V_44 -> V_59 - 9 ) << 27 ) |
( 4 << 24 ) |
( V_27 -> V_44 -> V_7 . V_36 -> V_37 >> 4 ) ) ;
F_5 ( V_7 -> V_57 , 0x88 , V_7 -> V_60 -> V_11 >> 10 ) ;
F_5 ( V_7 -> V_57 , 0x98 , F_4 ( V_7 ) -> V_11 >> 12 ) ;
V_5 -> V_22 ( V_5 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_3 )
{
struct V_24 * V_25 = ( void * ) V_3 -> V_14 ;
struct V_6 * V_7 = ( void * ) V_3 -> V_2 ;
struct V_26 * V_27 = ( void * ) V_3 ;
struct V_8 * V_57 = V_7 -> V_57 ;
T_2 V_31 = V_27 -> V_7 . V_31 ;
int V_50 ;
V_50 = F_24 ( & V_27 -> V_7 ) ;
if ( V_50 )
return V_50 ;
F_10 ( V_25 , 0x002600 + ( V_31 * 4 ) , 0x80000000 | V_57 -> V_11 >> 8 ) ;
F_25 ( V_25 ) ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_1 * V_14 ,
struct V_45 * V_46 , void * V_47 , T_2 V_12 ,
struct V_1 * * V_48 )
{
struct V_6 * V_7 ;
int V_50 ;
V_50 = F_27 ( V_2 , V_14 , V_46 , NULL , 0x10000 ,
0x1000 , V_64 , & V_7 ) ;
* V_48 = F_18 ( V_7 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_28 ( V_2 , F_18 ( V_7 ) , 0x0200 , 0 ,
V_65 , & V_7 -> V_21 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_28 ( V_2 , F_18 ( V_7 ) , 0x4000 , 0 ,
0 , & V_7 -> V_66 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_29 ( F_30 ( V_2 ) -> V_67 , & V_7 -> V_67 , V_7 -> V_66 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_28 ( V_2 , F_18 ( V_7 ) , 0x1000 , 0x400 ,
V_65 , & V_7 -> V_60 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_28 ( V_2 , F_18 ( V_7 ) , 0x0100 , 0x100 ,
V_65 , & V_7 -> V_57 ) ;
if ( V_50 )
return V_50 ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 , struct V_1 * V_14 ,
struct V_45 * V_46 , void * V_47 , T_2 V_12 ,
struct V_1 * * V_48 )
{
struct V_24 * V_25 ;
int V_50 ;
V_50 = F_32 ( V_2 , V_14 , V_46 , 1 , 127 , & V_25 ) ;
* V_48 = F_18 ( V_25 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_28 ( V_2 , NULL , 128 * 4 , 0x1000 , 0 ,
& V_25 -> V_68 [ 0 ] ) ;
if ( V_50 )
return V_50 ;
V_50 = F_28 ( V_2 , NULL , 128 * 4 , 0x1000 , 0 ,
& V_25 -> V_68 [ 1 ] ) ;
if ( V_50 )
return V_50 ;
F_33 ( V_25 ) -> V_69 = 0x00000100 ;
F_33 ( V_25 ) -> V_70 = V_71 ;
F_34 ( V_25 ) -> V_72 = & V_73 ;
F_34 ( V_25 ) -> V_74 = V_75 ;
return 0 ;
}
