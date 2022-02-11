void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = V_6 + V_3 ;
F_2 ( V_2 , V_7 , V_5 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_8 )
{
unsigned long V_9 = V_10 + V_11 ;
int V_12 , V_13 = 0 ;
for (; ; ) {
int V_14 ;
V_12 = F_4 ( V_8 , V_15 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_14 = ( ( V_12 >> V_17 ) &
( ( 1 << V_18 ) - 1 ) ) ;
if ( V_13 == 0 )
V_13 = V_14 ;
else if ( V_14 != V_13 )
break;
if ( F_5 ( V_10 , V_9 ) ) {
F_6 ( V_8 , V_19 , V_8 -> V_20 ,
L_1
L_2
L_3 ) ;
return - V_21 ;
}
F_7 ( V_22 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_8 )
{
unsigned long V_9 = V_10 + V_23 ;
int V_12 ;
for (; ; ) {
V_12 = F_4 ( V_8 , V_15 , V_24 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( V_12 &
( ( 1 << V_25 ) - 1 ) << V_26 ) >=
V_27 )
break;
if ( F_5 ( V_10 , V_9 ) )
return - V_21 ;
F_7 ( V_28 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_8 )
{
F_2 ( V_8 , 3 , 0xe854 , 0x00c0 ) ;
F_2 ( V_8 , 3 , 0xe854 , 0x0040 ) ;
F_7 ( 50 ) ;
}
static int F_10 ( struct V_1 * V_8 )
{
int V_29 ;
V_29 = F_3 ( V_8 ) ;
if ( V_29 != 0 )
return V_29 ;
V_29 = F_8 ( V_8 ) ;
if ( V_29 == - V_21 ) {
F_11 ( V_8 , V_19 , V_8 -> V_20 ,
L_4 ) ;
F_9 ( V_8 ) ;
V_29 = F_3 ( V_8 ) ;
if ( V_29 != 0 )
return V_29 ;
V_29 = F_8 ( V_8 ) ;
}
return V_29 ;
}
static void F_12 ( struct V_1 * V_8 )
{
struct V_30 * V_31 = V_8 -> V_31 ;
T_1 V_32 [ 9 ] ;
T_2 V_33 ;
for ( V_33 = 0 ; V_33 < sizeof( V_32 ) ; V_33 ++ )
V_32 [ V_33 ] = F_4 ( V_8 , V_15 ,
V_34 + V_33 ) ;
F_13 ( V_8 , V_35 , V_8 -> V_20 ,
L_5 ,
( V_32 [ 0 ] << 8 ) | V_32 [ 1 ] , V_32 [ 2 ] ,
V_32 [ 3 ] >> 4 , V_32 [ 3 ] & 0xf ,
V_32 [ 4 ] , V_32 [ 5 ] ,
V_32 [ 6 ] , V_32 [ 7 ] , V_32 [ 8 ] ) ;
V_31 -> V_36 = ( ( V_32 [ 3 ] & 0xf0 ) << 20 ) |
( ( V_32 [ 3 ] & 0x0f ) << 16 ) |
( V_32 [ 4 ] << 8 ) | V_32 [ 5 ] ;
}
static void F_14 ( struct V_1 * V_8 )
{
struct V_30 * V_31 = V_8 -> V_31 ;
if ( V_8 -> V_37 . V_38 ||
! F_15 ( V_8 , V_39 | V_40 ) ) {
V_31 -> V_41 = false ;
return;
}
if ( ! V_31 -> V_41 ) {
V_31 -> V_41 = true ;
V_31 -> V_42 = V_10 + V_43 ;
return;
}
if ( F_16 ( V_10 , V_31 -> V_42 ) ) {
F_11 ( V_8 , V_19 , V_8 -> V_20 , L_6 ) ;
F_17 ( V_8 , V_7 , V_44 ,
V_45 , true ) ;
F_7 ( 100 ) ;
F_17 ( V_8 , V_7 , V_44 ,
V_45 , false ) ;
V_31 -> V_42 = V_10 + V_43 ;
}
}
static int F_18 ( struct V_1 * V_8 )
{
struct V_30 * V_31 = V_8 -> V_31 ;
struct V_46 * V_47 = V_46 ( V_8 ) ;
int V_12 , V_29 , V_33 ;
T_3 V_48 ;
if ( V_31 -> V_36 < 0x02000100 )
return 0 ;
V_48 = ( V_8 -> V_49 == V_50 ) ? 0x0038 : 0x0020 ;
V_12 = F_4 ( V_8 , 1 , 0xc319 ) ;
if ( ( V_12 & 0x0038 ) == V_48 )
return 0 ;
F_11 ( V_8 , V_19 , V_8 -> V_20 , L_7 ,
V_48 ) ;
F_2 ( V_8 , 1 , 0xc300 , 0x0000 ) ;
if ( V_47 -> V_51 == 0 && V_47 -> V_52 < 2 ) {
F_2 ( V_8 , 1 , 0xc303 , 0x4498 ) ;
for ( V_33 = 0 ; V_33 < 9 ; V_33 ++ ) {
F_2 ( V_8 , 1 , 0xc303 , 0x4488 ) ;
F_2 ( V_8 , 1 , 0xc303 , 0x4480 ) ;
F_2 ( V_8 , 1 , 0xc303 , 0x4490 ) ;
F_2 ( V_8 , 1 , 0xc303 , 0x4498 ) ;
}
} else {
F_2 ( V_8 , 1 , 0xc303 , 0x0920 ) ;
F_2 ( V_8 , 1 , 0xd008 , 0x0004 ) ;
for ( V_33 = 0 ; V_33 < 9 ; V_33 ++ ) {
F_2 ( V_8 , 1 , 0xc303 , 0x0900 ) ;
F_2 ( V_8 , 1 , 0xd008 , 0x0005 ) ;
F_2 ( V_8 , 1 , 0xc303 , 0x0920 ) ;
F_2 ( V_8 , 1 , 0xd008 , 0x0004 ) ;
}
F_2 ( V_8 , 1 , 0xc303 , 0x4900 ) ;
}
F_2 ( V_8 , 1 , 0xc303 , 0x4900 ) ;
F_2 ( V_8 , 1 , 0xc302 , 0x0004 ) ;
F_2 ( V_8 , 1 , 0xc316 , 0x0013 ) ;
F_2 ( V_8 , 1 , 0xc318 , 0x0054 ) ;
F_2 ( V_8 , 1 , 0xc319 , V_48 ) ;
F_2 ( V_8 , 1 , 0xc31a , 0x0098 ) ;
F_2 ( V_8 , 3 , 0x0026 , 0x0e00 ) ;
F_2 ( V_8 , 3 , 0x0027 , 0x0013 ) ;
F_2 ( V_8 , 3 , 0x0028 , 0xa528 ) ;
F_2 ( V_8 , 1 , 0xd006 , 0x000a ) ;
F_2 ( V_8 , 1 , 0xd007 , 0x0009 ) ;
F_2 ( V_8 , 1 , 0xd008 , 0x0004 ) ;
F_2 ( V_8 , 1 , 0xc317 , 0x00ff ) ;
F_17 ( V_8 , 1 , V_53 ,
1 << V_54 , false ) ;
F_2 ( V_8 , 1 , 0xc300 , 0x0002 ) ;
F_7 ( 20 ) ;
F_9 ( V_8 ) ;
V_29 = F_10 ( V_8 ) ;
if ( V_29 < 0 ) {
F_6 ( V_8 , V_19 , V_8 -> V_20 ,
L_8
L_9 ) ;
return V_29 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_8 )
{
int V_29 ;
if ( V_8 -> V_55 == V_56 ) {
V_29 = F_10 ( V_8 ) ;
if ( V_29 < 0 )
goto V_57;
} else {
V_29 = F_20 ( V_8 , V_58 ,
V_59 /
V_60 ,
V_60 ) ;
if ( V_29 < 0 )
goto V_57;
}
F_7 ( 250 ) ;
V_46 ( V_8 ) -> type -> V_61 ( V_8 ) ;
return 0 ;
V_57:
F_6 ( V_8 , V_19 , V_8 -> V_20 , L_10 ) ;
return V_29 ;
}
static int F_21 ( struct V_1 * V_8 )
{
struct V_30 * V_31 ;
V_31 = F_22 ( sizeof( struct V_30 ) , V_62 ) ;
if ( ! V_31 )
return - V_63 ;
V_8 -> V_31 = V_31 ;
V_31 -> V_64 = V_8 -> V_64 ;
V_31 -> V_41 = false ;
V_31 -> V_42 = 0 ;
V_8 -> V_65 . V_66 = V_67 ;
V_8 -> V_65 . V_68 = V_69 | V_70 ;
V_8 -> V_71 = V_72 | V_73 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_8 )
{
T_4 V_74 ;
int V_29 ;
V_29 = F_19 ( V_8 ) ;
if ( V_29 ) {
F_6 ( V_8 , V_35 , V_8 -> V_20 , L_11 ) ;
return V_29 ;
}
V_74 = F_24 ( V_8 , V_58 ) ;
F_13 ( V_8 , V_35 , V_8 -> V_20 ,
L_12 ,
V_74 , F_25 ( V_74 ) , F_26 ( V_74 ) ,
F_27 ( V_74 ) ) ;
if ( V_8 -> V_55 == V_56 )
F_12 ( V_8 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_8 )
{
return F_15 ( V_8 , V_67 ) ;
}
static bool F_29 ( struct V_1 * V_8 )
{
bool V_75 = V_8 -> V_37 . V_38 ;
V_8 -> V_37 . V_38 = F_28 ( V_8 ) ;
V_8 -> V_37 . V_76 = 10000 ;
V_8 -> V_37 . V_77 = true ;
V_8 -> V_37 . V_78 = V_8 -> V_79 ;
if ( V_8 -> V_55 == V_56 )
F_14 ( V_8 ) ;
return V_8 -> V_37 . V_38 != V_75 ;
}
static int F_30 ( struct V_1 * V_8 )
{
struct V_30 * V_31 = V_8 -> V_31 ;
if ( V_8 -> V_55 == V_56 ) {
int V_29 = F_18 ( V_8 ) ;
if ( V_29 )
return V_29 ;
F_31 (
& V_8 -> V_65 , V_8 -> V_65 . V_80 , V_7 ,
V_81 , 1 << V_82 ,
V_8 -> V_64 & V_83 ||
V_8 -> V_64 & V_84 ||
V_8 -> V_49 == V_85 ||
V_8 -> V_49 == V_86 ) ;
} else {
if ( ! ( V_8 -> V_64 & V_83 ) &&
( V_31 -> V_64 & V_83 ) )
F_19 ( V_8 ) ;
F_32 ( V_8 ) ;
}
F_33 ( V_8 ) ;
V_31 -> V_64 = V_8 -> V_64 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_8 , struct V_87 * V_88 )
{
F_35 ( & V_8 -> V_65 , V_88 ) ;
}
static void F_36 ( struct V_1 * V_8 )
{
F_37 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
}
