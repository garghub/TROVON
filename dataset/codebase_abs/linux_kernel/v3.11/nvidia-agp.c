static int F_1 ( void )
{
int V_1 ;
T_1 V_2 ;
struct V_3 * V_4 ;
F_2 ( V_5 -> V_6 , V_7 , & V_2 ) ;
V_2 &= 0x0f ;
V_4 = F_3 ( V_5 -> V_8 -> V_9 ) ;
for ( V_1 = 0 ; V_1 < V_5 -> V_8 -> V_10 ; V_1 ++ ) {
if ( V_2 == V_4 [ V_1 ] . V_2 ) {
V_5 -> V_11 =
V_5 -> V_12 = ( void * ) ( V_4 + V_1 ) ;
V_5 -> V_13 = V_1 ;
return V_4 [ V_1 ] . V_14 ;
}
}
return 0 ;
}
static int F_4 ( T_2 V_15 , T_2 V_14 )
{
T_2 V_16 , V_17 ;
T_2 V_18 , V_19 ;
T_2 V_20 , V_21 ;
T_2 V_22 , V_23 ;
V_23 = V_24 ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
F_5 ( V_25 + 2 * V_22 , V_17 , V_16 ) ;
F_5 ( V_26 + 2 * V_22 , V_19 , V_18 ) ;
if ( ( V_17 & 0xfffff000 ) == ( V_15 & 0xfffff000 ) )
break;
if ( ( V_19 & 0x00000800 ) == 0 )
V_23 = V_22 ;
}
if ( V_22 >= V_24 ) {
V_22 = V_23 ;
if ( V_22 >= V_24 )
return - V_27 ;
}
V_16 = 0x0 ;
V_17 = ( V_15 & ~ 0xfff ) | 0x18 ;
V_18 = 0xf ;
V_19 = ( ( ~ ( V_14 - 1 ) ) & 0xfffff000 ) | 0x800 ;
F_6 ( V_25 + 2 * V_22 , V_17 , V_16 ) ;
F_6 ( V_26 + 2 * V_22 , V_19 , V_18 ) ;
F_5 ( V_28 , V_21 , V_20 ) ;
V_21 |= 0x00100000 ;
F_6 ( V_28 , V_21 , V_20 ) ;
return 0 ;
}
static int F_7 ( void )
{
int V_1 , V_29 , V_30 ;
T_2 V_31 , V_32 ;
struct V_3 * V_12 ;
T_2 V_33 ;
V_12 = F_3 ( V_5 -> V_12 ) ;
F_8 ( V_5 -> V_6 , V_7 ,
V_12 -> V_2 ) ;
F_9 ( V_5 -> V_6 , V_34 , & V_31 ) ;
V_31 &= V_35 ;
V_5 -> V_36 = V_31 ;
V_32 = V_31 + ( V_12 -> V_14 * 1024 * 1024 ) - 1 ;
F_10 ( V_37 . V_38 , V_39 , V_31 ) ;
F_10 ( V_37 . V_38 , V_40 , V_32 ) ;
F_10 ( V_37 . V_41 , V_42 , V_31 ) ;
F_10 ( V_37 . V_41 , V_43 , V_32 ) ;
if ( 0 != ( V_29 = F_4 ( V_31 , V_12 -> V_14 * 1024 * 1024 ) ) )
return V_29 ;
V_30 = V_12 -> V_14 / 64 ;
V_37 . V_44 = V_12 -> V_45 ;
V_37 . V_46 = 0 ;
if ( V_30 == 0 ) {
V_30 = 1 ;
V_37 . V_44 /= ( 64 / V_12 -> V_14 ) ;
V_37 . V_46 = ( V_31 & ( 64 * 1024 * 1024 - 1 ) &
~ ( V_12 -> V_14 * 1024 * 1024 - 1 ) ) / V_47 ;
}
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
F_10 ( V_37 . V_38 , F_11 ( V_1 ) ,
( V_5 -> V_48 + ( V_1 % V_30 ) * 64 * 1024 ) | 1 ) ;
}
F_9 ( V_37 . V_38 , V_49 , & V_33 ) ;
F_10 ( V_37 . V_38 , V_49 , V_33 | 0x11 ) ;
F_9 ( V_5 -> V_6 , V_7 , & V_33 ) ;
F_10 ( V_5 -> V_6 , V_7 , V_33 | 0x100 ) ;
V_37 . V_50 =
( volatile T_2 V_51 * ) F_12 ( V_31 , 33 * V_47 ) ;
if ( ! V_37 . V_50 )
return - V_52 ;
return 0 ;
}
static void F_13 ( void )
{
struct V_3 * V_11 ;
T_2 V_33 ;
F_9 ( V_5 -> V_6 , V_7 , & V_33 ) ;
F_10 ( V_5 -> V_6 , V_7 , V_33 & ~ ( 0x100 ) ) ;
F_9 ( V_37 . V_38 , V_49 , & V_33 ) ;
F_10 ( V_37 . V_38 , V_49 , V_33 & ~ ( 0x11 ) ) ;
F_14 ( ( void V_51 * ) V_37 . V_50 ) ;
V_11 = F_3 ( V_5 -> V_11 ) ;
F_8 ( V_5 -> V_6 , V_7 ,
V_11 -> V_2 ) ;
F_4 ( V_5 -> V_36 ,
V_11 -> V_14 * 1024 * 1024 ) ;
}
static int F_15 ( struct V_53 * V_54 , T_3 V_55 , int type )
{
int V_1 , V_56 ;
int V_57 ;
V_57 = F_16 ( V_54 -> V_58 , type ) ;
if ( V_57 != 0 || type != V_54 -> type )
return - V_27 ;
if ( V_54 -> V_59 == 0 )
return 0 ;
if ( ( V_55 + V_54 -> V_59 ) >
( V_37 . V_44 - V_60 / V_47 ) )
return - V_27 ;
for ( V_56 = V_55 ; V_56 < ( V_55 + V_54 -> V_59 ) ; V_56 ++ ) {
if ( ! F_17 ( V_5 , F_18 ( V_5 -> V_61 + V_37 . V_46 + V_56 ) ) )
return - V_62 ;
}
if ( ! V_54 -> V_63 ) {
F_19 () ;
V_54 -> V_63 = true ;
}
for ( V_1 = 0 , V_56 = V_55 ; V_1 < V_54 -> V_59 ; V_1 ++ , V_56 ++ ) {
F_20 ( V_5 -> V_8 -> V_64 ( V_5 ,
F_21 ( V_54 -> V_65 [ V_1 ] ) , V_57 ) ,
V_5 -> V_61 + V_37 . V_46 + V_56 ) ;
}
F_18 ( V_5 -> V_61 + V_37 . V_46 + V_56 - 1 ) ;
V_5 -> V_8 -> V_66 ( V_54 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_54 , T_3 V_55 , int type )
{
int V_1 ;
int V_57 ;
V_57 = F_16 ( V_54 -> V_58 , type ) ;
if ( V_57 != 0 || type != V_54 -> type )
return - V_27 ;
if ( V_54 -> V_59 == 0 )
return 0 ;
for ( V_1 = V_55 ; V_1 < ( V_54 -> V_59 + V_55 ) ; V_1 ++ )
F_20 ( V_5 -> V_67 , V_5 -> V_61 + V_37 . V_46 + V_1 ) ;
V_5 -> V_8 -> V_66 ( V_54 ) ;
return 0 ;
}
static void F_23 ( struct V_53 * V_54 )
{
unsigned long V_68 ;
T_2 V_69 , V_33 ;
int V_1 ;
if ( V_37 . V_70 ) {
F_9 ( V_37 . V_71 , V_72 , & V_69 ) ;
V_69 |= V_37 . V_70 ;
F_10 ( V_37 . V_71 , V_72 , V_69 ) ;
V_68 = V_73 + 3 * V_74 ;
do {
F_9 ( V_37 . V_71 ,
V_72 , & V_69 ) ;
if ( F_24 ( V_68 , V_73 ) ) {
F_25 (KERN_ERR PFX
L_1 ) ;
}
} while ( V_69 & V_37 . V_70 );
}
for ( V_1 = 0 ; V_1 < 32 + 1 ; V_1 ++ )
V_33 = F_18 ( V_37 . V_50 + ( V_1 * V_47 / sizeof( T_2 ) ) ) ;
for ( V_1 = 0 ; V_1 < 32 + 1 ; V_1 ++ )
V_33 = F_18 ( V_37 . V_50 + ( V_1 * V_47 / sizeof( T_2 ) ) ) ;
}
static int F_26 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_79 * V_58 ;
T_1 V_80 ;
V_37 . V_71 =
F_27 ( ( unsigned int ) V_76 -> V_81 -> V_82 , F_28 ( 0 , 1 ) ) ;
V_37 . V_38 =
F_27 ( ( unsigned int ) V_76 -> V_81 -> V_82 , F_28 ( 0 , 2 ) ) ;
V_37 . V_41 =
F_27 ( ( unsigned int ) V_76 -> V_81 -> V_82 , F_28 ( 30 , 0 ) ) ;
if ( ! V_37 . V_71 || ! V_37 . V_38 || ! V_37 . V_41 ) {
F_25 (KERN_INFO PFX L_2
L_3 ) ;
return - V_83 ;
}
V_80 = F_29 ( V_76 , V_84 ) ;
if ( ! V_80 )
return - V_83 ;
switch ( V_76 -> V_85 ) {
case V_86 :
F_25 (KERN_INFO PFX L_4 ) ;
V_37 . V_70 = 0x00010000 ;
break;
case V_87 :
F_25 (KERN_INFO PFX L_5 ) ;
V_37 . V_70 = 0x80000000 ;
break;
default:
F_25 (KERN_ERR PFX L_6 ,
pdev->device) ;
return - V_83 ;
}
V_58 = F_30 () ;
if ( ! V_58 )
return - V_52 ;
V_58 -> V_8 = & V_88 ;
V_58 -> V_89 = & V_37 ,
V_58 -> V_6 = V_76 ;
V_58 -> V_90 = V_80 ;
F_9 ( V_76 ,
V_58 -> V_90 + V_91 ,
& V_58 -> V_92 ) ;
F_31 ( V_76 , V_58 ) ;
return F_32 ( V_58 ) ;
}
static void F_33 ( struct V_75 * V_76 )
{
struct V_79 * V_58 = F_34 ( V_76 ) ;
F_35 ( V_58 ) ;
F_36 ( V_58 ) ;
}
static int F_37 ( struct V_75 * V_76 , T_4 V_93 )
{
F_38 ( V_76 ) ;
F_39 ( V_76 , V_94 ) ;
return 0 ;
}
static int F_40 ( struct V_75 * V_76 )
{
F_39 ( V_76 , V_95 ) ;
F_41 ( V_76 ) ;
F_7 () ;
return 0 ;
}
static int T_5 F_42 ( void )
{
if ( V_96 )
return - V_27 ;
return F_43 ( & V_97 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_97 ) ;
F_46 ( V_37 . V_71 ) ;
F_46 ( V_37 . V_38 ) ;
F_46 ( V_37 . V_41 ) ;
}
