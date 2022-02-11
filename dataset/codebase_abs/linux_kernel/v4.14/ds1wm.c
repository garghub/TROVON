static inline void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_2 V_3 )
{
if ( V_1 -> V_4 ) {
switch ( V_1 -> V_5 ) {
case 0 :
F_2 ( V_3 , V_1 -> V_6 + ( V_2 << 0 ) ) ;
break;
case 1 :
F_3 ( ( V_7 ) V_3 , V_1 -> V_6 + ( V_2 << 1 ) ) ;
break;
case 2 :
F_4 ( ( T_1 ) V_3 , V_1 -> V_6 + ( V_2 << 2 ) ) ;
break;
}
} else {
switch ( V_1 -> V_5 ) {
case 0 :
F_2 ( V_3 , V_1 -> V_6 + ( V_2 << 0 ) ) ;
break;
case 1 :
F_5 ( ( V_7 ) V_3 , V_1 -> V_6 + ( V_2 << 1 ) ) ;
break;
case 2 :
F_6 ( ( T_1 ) V_3 , V_1 -> V_6 + ( V_2 << 2 ) ) ;
break;
}
}
}
static inline T_2 F_7 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_3 = 0 ;
if ( V_1 -> V_4 ) {
switch ( V_1 -> V_5 ) {
case 0 :
V_3 = F_8 ( V_1 -> V_6 + ( V_2 << 0 ) ) ;
break;
case 1 :
V_3 = F_9 ( V_1 -> V_6 + ( V_2 << 1 ) ) ;
break;
case 2 :
V_3 = F_10 ( V_1 -> V_6 + ( V_2 << 2 ) ) ;
break;
}
} else {
switch ( V_1 -> V_5 ) {
case 0 :
V_3 = F_8 ( V_1 -> V_6 + ( V_2 << 0 ) ) ;
break;
case 1 :
V_3 = F_11 ( V_1 -> V_6 + ( V_2 << 1 ) ) ;
break;
case 2 :
V_3 = F_12 ( V_1 -> V_6 + ( V_2 << 2 ) ) ;
break;
}
}
F_13 ( & V_1 -> V_8 -> V_9 ,
L_1 , V_2 , V_3 ) ;
return ( T_2 ) V_3 ;
}
static T_3 F_14 ( int V_10 , void * V_11 )
{
struct V_1 * V_1 = V_11 ;
T_2 V_12 ;
T_2 V_13 = F_7 ( V_1 , V_14 ) ;
if ( ! ( V_13 & V_15 ) )
return V_16 ;
F_1 ( V_1 ,
V_14 , V_1 -> V_17 ) ;
V_12 = F_7 ( V_1 , V_18 ) ;
V_1 -> V_19 = ( V_12 & V_20 ) ? 0 : 1 ;
if ( ( V_12 & V_21 ) && V_1 -> V_22 ) {
V_13 &= ~ V_23 ;
F_15 ( V_1 -> V_22 ) ;
}
if ( V_12 & V_24 ) {
V_1 -> V_25 = F_7 ( V_1 ,
V_26 ) ;
V_13 &= ~ V_27 ;
if ( V_1 -> V_28 )
F_15 ( V_1 -> V_28 ) ;
}
if ( ( V_12 & V_29 ) && V_1 -> V_30 ) {
V_13 &= ~ V_31 ;
F_15 ( V_1 -> V_30 ) ;
}
F_1 ( V_1 , V_14 , V_13 ) ;
return V_32 ;
}
static int F_16 ( struct V_1 * V_1 )
{
unsigned long V_33 ;
F_17 ( V_34 ) ;
V_1 -> V_30 = & V_34 ;
F_1 ( V_1 , V_14 , V_31 |
V_1 -> V_17 ) ;
F_1 ( V_1 , V_35 , V_36 ) ;
V_33 = F_18 ( & V_34 , V_37 ) ;
V_1 -> V_30 = NULL ;
if ( ! V_33 ) {
F_19 ( & V_1 -> V_8 -> V_9 , L_2 ) ;
return 1 ;
}
if ( ! V_1 -> V_19 ) {
F_13 ( & V_1 -> V_8 -> V_9 , L_3 ) ;
return 1 ;
}
if ( V_1 -> V_38 )
F_20 ( V_1 -> V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , T_2 V_11 )
{
unsigned long V_33 ;
F_17 ( V_39 ) ;
V_1 -> V_22 = & V_39 ;
F_1 ( V_1 , V_14 ,
V_1 -> V_17 | V_23 ) ;
F_1 ( V_1 , V_26 , V_11 ) ;
V_33 = F_18 ( & V_39 , V_37 ) ;
V_1 -> V_22 = NULL ;
if ( ! V_33 ) {
F_19 ( & V_1 -> V_8 -> V_9 , L_4 ) ;
return - V_40 ;
}
return 0 ;
}
static T_2 F_22 ( struct V_1 * V_1 , unsigned char V_41 )
{
unsigned long V_33 ;
T_2 V_42 = V_27 | V_1 -> V_17 ;
F_17 ( V_43 ) ;
F_7 ( V_1 , V_26 ) ;
V_1 -> V_28 = & V_43 ;
F_1 ( V_1 , V_14 , V_42 ) ;
F_1 ( V_1 , V_26 , V_41 ) ;
V_33 = F_18 ( & V_43 , V_37 ) ;
V_1 -> V_28 = NULL ;
if ( ! V_33 ) {
F_19 ( & V_1 -> V_8 -> V_9 , L_5 ) ;
V_1 -> V_44 = - V_40 ;
return 0xFF ;
}
V_1 -> V_44 = 0 ;
return V_1 -> V_25 ;
}
static int F_23 ( int V_45 )
{
int V_46 ;
for ( V_46 = F_24 ( V_47 ) - 1 ; V_46 >= 0 ; -- V_46 )
if ( V_45 >= V_47 [ V_46 ] . V_47 )
return V_47 [ V_46 ] . V_48 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_1 )
{
int V_48 ;
struct V_49 * V_9 = & V_1 -> V_8 -> V_9 ;
struct V_50 * V_51 = F_26 ( V_9 ) ;
if ( V_1 -> V_52 -> V_53 )
V_1 -> V_52 -> V_53 ( V_1 -> V_8 ) ;
V_48 = F_23 ( V_51 -> V_54 ) ;
F_13 ( V_9 , L_6 ,
V_48 , V_51 -> V_54 ) ;
if ( V_48 == 0 ) {
F_19 ( V_9 , L_7 ,
V_51 -> V_54 ) ;
return;
}
F_1 ( V_1 , V_55 , V_48 ) ;
F_20 ( 1 ) ;
F_16 ( V_1 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_16 ( V_1 ) ;
F_1 ( V_1 , V_14 ,
V_1 -> V_17 ) ;
if ( V_1 -> V_52 -> V_56 )
V_1 -> V_52 -> V_56 ( V_1 -> V_8 ) ;
}
static T_2 F_28 ( void * V_11 )
{
struct V_1 * V_1 = V_11 ;
return F_22 ( V_1 , 0xff ) ;
}
static void F_29 ( void * V_11 , T_2 V_57 )
{
struct V_1 * V_1 = V_11 ;
F_21 ( V_1 , V_57 ) ;
}
static T_2 F_30 ( void * V_11 )
{
struct V_1 * V_1 = V_11 ;
F_16 ( V_1 ) ;
return 0 ;
}
static void F_31 ( void * V_11 , struct V_58 * V_59 ,
T_2 V_60 , T_4 V_61 )
{
struct V_1 * V_1 = V_11 ;
int V_46 ;
int V_62 = - 1 ;
T_5 V_63 = 0 ;
T_5 V_64 , V_65 ;
unsigned V_66 = 0 ;
unsigned int V_67 = 0 ;
F_13 ( & V_1 -> V_8 -> V_9 , L_8 ) ;
while ( true ) {
++ V_67 ;
if ( V_67 > 100 ) {
F_13 ( & V_1 -> V_8 -> V_9 ,
L_9 ) ;
return;
}
F_32 ( & V_59 -> V_68 ) ;
if ( F_16 ( V_1 ) ) {
F_33 ( & V_59 -> V_68 ) ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_10 , V_67 ) ;
break;
}
F_13 ( & V_1 -> V_8 -> V_9 ,
L_11 , V_67 , V_63 ) ;
F_21 ( V_1 , V_60 ) ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_12 , V_67 ) ;
F_1 ( V_1 , V_35 , V_69 ) ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_13 , V_67 ) ;
V_64 = 0 ;
V_65 = 0 ;
for ( V_46 = 0 ; V_46 < 16 ; V_46 ++ ) {
unsigned char V_70 , V_71 , V_72 , V_73 ;
V_71 = ( V_63 >> ( 4 * V_46 ) ) & 0xf ;
V_71 = ( ( V_71 & 0x1 ) << 1 ) |
( ( V_71 & 0x2 ) << 2 ) |
( ( V_71 & 0x4 ) << 3 ) |
( ( V_71 & 0x8 ) << 4 ) ;
V_70 = F_22 ( V_1 , V_71 ) ;
if ( V_1 -> V_44 ) {
F_19 ( & V_1 -> V_8 -> V_9 ,
L_14 , V_67 , V_46 ) ;
break;
}
V_72 = ( ( V_70 & 0x02 ) >> 1 ) |
( ( V_70 & 0x08 ) >> 2 ) |
( ( V_70 & 0x20 ) >> 3 ) |
( ( V_70 & 0x80 ) >> 4 ) ;
V_73 = ( ( V_70 & 0x01 ) >> 0 ) |
( ( V_70 & 0x04 ) >> 1 ) |
( ( V_70 & 0x10 ) >> 2 ) |
( ( V_70 & 0x40 ) >> 3 ) ;
V_64 |= ( unsigned long long ) V_72 << ( V_46 * 4 ) ;
V_65 |= ( unsigned long long ) V_73 << ( V_46 * 4 ) ;
}
if ( V_1 -> V_44 ) {
F_33 ( & V_59 -> V_68 ) ;
F_19 ( & V_1 -> V_8 -> V_9 ,
L_15 , V_67 ) ;
break;
}
F_13 ( & V_1 -> V_8 -> V_9 ,
L_16 ,
V_67 , V_64 , V_65 ) ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_17 , V_67 ) ;
F_1 ( V_1 , V_35 , ~ V_69 ) ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_18 , V_67 ) ;
F_16 ( V_1 ) ;
F_33 ( & V_59 -> V_68 ) ;
if ( ( V_64 & ( ( T_5 ) 1 << 63 ) ) && ( V_65 & ( ( T_5 ) 1 << 63 ) ) ) {
F_19 ( & V_1 -> V_8 -> V_9 ,
L_19 , V_67 ) ;
continue;
}
F_13 ( & V_1 -> V_8 -> V_9 ,
L_20 , V_67 , V_64 ) ;
V_61 ( V_59 , V_64 ) ;
++ V_66 ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_21 , V_67 ) ;
V_65 &= ~ V_63 ;
V_62 = F_34 ( V_65 ) - 1 ;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_22 ,
V_67 , V_65 , V_62 ) ;
if ( V_62 == - 1 )
break;
V_63 = ( V_63 & ~ ( ~ 0ull << ( V_62 ) ) ) | 1 << V_62 ;
}
F_13 ( & V_1 -> V_8 -> V_9 ,
L_23 , V_67 ,
V_66 , V_62 ) ;
}
static int F_35 ( struct V_74 * V_8 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
struct V_75 * V_76 ;
int V_77 ;
T_2 V_13 ;
if ( ! V_8 )
return - V_78 ;
V_1 = F_36 ( & V_8 -> V_9 , sizeof( * V_1 ) , V_79 ) ;
if ( ! V_1 )
return - V_80 ;
F_37 ( V_8 , V_1 ) ;
V_76 = F_38 ( V_8 , V_81 , 0 ) ;
if ( ! V_76 )
return - V_82 ;
V_1 -> V_6 = F_39 ( & V_8 -> V_9 , V_76 -> V_83 ,
F_40 ( V_76 ) ) ;
if ( ! V_1 -> V_6 )
return - V_80 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_52 = F_41 ( V_8 ) ;
if ( ! V_1 -> V_52 )
return - V_78 ;
V_51 = F_26 ( & V_8 -> V_9 ) ;
if ( ! V_51 )
return - V_78 ;
if ( V_51 -> V_5 > 2 ) {
F_19 ( & V_1 -> V_8 -> V_9 ,
L_24 ,
V_1 -> V_5 ) ;
return - V_84 ;
}
V_1 -> V_5 = V_51 -> V_5 ;
if ( ( 8 << V_1 -> V_5 ) > F_40 ( V_76 ) ) {
F_19 ( & V_1 -> V_8 -> V_9 ,
L_25 ,
( int ) F_40 ( V_76 ) ,
8 << V_1 -> V_5 ) ;
return - V_84 ;
}
V_1 -> V_4 = V_51 -> V_4 ;
V_76 = F_38 ( V_8 , V_85 , 0 ) ;
if ( ! V_76 )
return - V_82 ;
V_1 -> V_86 = V_76 -> V_83 ;
V_1 -> V_17 = ( V_51 -> V_87 ? V_88 : 0 ) ;
V_1 -> V_38 = V_51 -> V_38 ;
V_13 = F_7 ( V_1 , V_14 ) ;
F_1 ( V_1 ,
V_14 , V_1 -> V_17 ) ;
if ( V_76 -> V_89 & V_90 )
F_42 ( V_1 -> V_86 , V_91 ) ;
if ( V_76 -> V_89 & V_92 )
F_42 ( V_1 -> V_86 , V_93 ) ;
if ( V_76 -> V_89 & V_94 )
F_42 ( V_1 -> V_86 , V_95 ) ;
if ( V_76 -> V_89 & V_96 )
F_42 ( V_1 -> V_86 , V_97 ) ;
V_77 = F_43 ( & V_8 -> V_9 , V_1 -> V_86 , F_14 ,
V_98 , L_26 , V_1 ) ;
if ( V_77 ) {
F_19 ( & V_1 -> V_8 -> V_9 ,
L_27 ,
V_1 -> V_86 ,
V_77 ) ;
return V_77 ;
}
F_25 ( V_1 ) ;
V_99 . V_11 = ( void * ) V_1 ;
V_77 = F_44 ( & V_99 ) ;
if ( V_77 )
goto V_100;
F_13 ( & V_1 -> V_8 -> V_9 ,
L_28 ,
V_51 -> V_87 ,
V_51 -> V_38 ,
V_51 -> V_54 ,
V_1 -> V_5 ,
V_1 -> V_4 ) ;
return 0 ;
V_100:
F_27 ( V_1 ) ;
return V_77 ;
}
static int F_45 ( struct V_74 * V_8 , T_6 V_101 )
{
struct V_1 * V_1 = F_46 ( V_8 ) ;
F_27 ( V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_74 * V_8 )
{
struct V_1 * V_1 = F_46 ( V_8 ) ;
F_25 ( V_1 ) ;
return 0 ;
}
static int F_48 ( struct V_74 * V_8 )
{
struct V_1 * V_1 = F_46 ( V_8 ) ;
F_49 ( & V_99 ) ;
F_27 ( V_1 ) ;
return 0 ;
}
static int T_7 F_50 ( void )
{
F_51 ( L_29 ) ;
return F_52 ( & V_102 ) ;
}
static void T_8 F_53 ( void )
{
F_54 ( & V_102 ) ;
}
