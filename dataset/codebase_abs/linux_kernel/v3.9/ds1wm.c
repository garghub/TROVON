static inline void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_2 V_3 )
{
F_2 ( V_3 , V_1 -> V_4 + ( V_2 << V_1 -> V_5 ) ) ;
}
static inline T_2 F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
return F_4 ( V_1 -> V_4 + ( V_2 << V_1 -> V_5 ) ) ;
}
static T_3 F_5 ( int V_6 , void * V_7 )
{
struct V_1 * V_1 = V_7 ;
T_2 V_8 ;
T_2 V_9 = F_3 ( V_1 , V_10 ) ;
if ( ! ( V_9 & V_11 ) )
return V_12 ;
F_1 ( V_1 ,
V_10 , V_1 -> V_13 ) ;
V_8 = F_3 ( V_1 , V_14 ) ;
V_1 -> V_15 = ( V_8 & V_16 ) ? 0 : 1 ;
if ( ( V_8 & V_17 ) && V_1 -> V_18 ) {
V_9 &= ~ V_19 ;
F_6 ( V_1 -> V_18 ) ;
}
if ( V_8 & V_20 ) {
V_1 -> V_21 = F_3 ( V_1 ,
V_22 ) ;
V_9 &= ~ V_23 ;
if ( V_1 -> V_24 )
F_6 ( V_1 -> V_24 ) ;
}
if ( ( V_8 & V_25 ) && V_1 -> V_26 ) {
V_9 &= ~ V_27 ;
F_6 ( V_1 -> V_26 ) ;
}
F_1 ( V_1 , V_10 , V_9 ) ;
return V_28 ;
}
static int F_7 ( struct V_1 * V_1 )
{
unsigned long V_29 ;
F_8 ( V_30 ) ;
V_1 -> V_26 = & V_30 ;
F_1 ( V_1 , V_10 , V_27 |
V_1 -> V_13 ) ;
F_1 ( V_1 , V_31 , V_32 ) ;
V_29 = F_9 ( & V_30 , V_33 ) ;
V_1 -> V_26 = NULL ;
if ( ! V_29 ) {
F_10 ( & V_1 -> V_34 -> V_35 , L_1 ) ;
return 1 ;
}
if ( ! V_1 -> V_15 ) {
F_11 ( & V_1 -> V_34 -> V_35 , L_2 ) ;
return 1 ;
}
if ( V_1 -> V_36 )
F_12 ( V_1 -> V_36 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , T_2 V_7 )
{
unsigned long V_29 ;
F_8 ( V_37 ) ;
V_1 -> V_18 = & V_37 ;
F_1 ( V_1 , V_10 ,
V_1 -> V_13 | V_19 ) ;
F_1 ( V_1 , V_22 , V_7 ) ;
V_29 = F_9 ( & V_37 , V_33 ) ;
V_1 -> V_18 = NULL ;
if ( ! V_29 ) {
F_10 ( & V_1 -> V_34 -> V_35 , L_3 ) ;
return - V_38 ;
}
return 0 ;
}
static T_2 F_14 ( struct V_1 * V_1 , unsigned char V_39 )
{
unsigned long V_29 ;
T_2 V_40 = V_23 | V_1 -> V_13 ;
F_8 ( V_41 ) ;
F_3 ( V_1 , V_22 ) ;
V_1 -> V_24 = & V_41 ;
F_1 ( V_1 , V_10 , V_40 ) ;
F_1 ( V_1 , V_22 , V_39 ) ;
V_29 = F_9 ( & V_41 , V_33 ) ;
V_1 -> V_24 = NULL ;
if ( ! V_29 ) {
F_10 ( & V_1 -> V_34 -> V_35 , L_4 ) ;
V_1 -> V_42 = - V_38 ;
return 0xFF ;
}
V_1 -> V_42 = 0 ;
return V_1 -> V_21 ;
}
static int F_15 ( int V_43 )
{
int V_44 ;
for ( V_44 = F_16 ( V_45 ) - 1 ; V_44 >= 0 ; -- V_44 )
if ( V_43 >= V_45 [ V_44 ] . V_45 )
return V_45 [ V_44 ] . V_46 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_1 )
{
int V_46 ;
struct V_47 * V_48 = V_1 -> V_34 -> V_35 . V_49 ;
if ( V_1 -> V_50 -> V_51 )
V_1 -> V_50 -> V_51 ( V_1 -> V_34 ) ;
V_46 = F_15 ( V_48 -> V_52 ) ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_5 , V_46 , V_48 -> V_52 ) ;
if ( V_46 == 0 ) {
F_10 ( & V_1 -> V_34 -> V_35 ,
L_6 ,
V_48 -> V_52 ) ;
return;
}
F_1 ( V_1 , V_53 , V_46 ) ;
F_12 ( 1 ) ;
F_7 ( V_1 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
F_7 ( V_1 ) ;
F_1 ( V_1 , V_10 ,
V_1 -> V_13 ) ;
if ( V_1 -> V_50 -> V_54 )
V_1 -> V_50 -> V_54 ( V_1 -> V_34 ) ;
}
static T_2 F_19 ( void * V_7 )
{
struct V_1 * V_1 = V_7 ;
return F_14 ( V_1 , 0xff ) ;
}
static void F_20 ( void * V_7 , T_2 V_55 )
{
struct V_1 * V_1 = V_7 ;
F_13 ( V_1 , V_55 ) ;
}
static T_2 F_21 ( void * V_7 )
{
struct V_1 * V_1 = V_7 ;
F_7 ( V_1 ) ;
return 0 ;
}
static void F_22 ( void * V_7 , struct V_56 * V_57 ,
T_2 V_58 , T_4 V_59 )
{
struct V_1 * V_1 = V_7 ;
int V_44 ;
int V_60 = - 1 ;
T_5 V_61 = 0 ;
T_5 V_62 , V_63 ;
unsigned V_64 = 0 ;
unsigned int V_65 = 0 ;
F_11 ( & V_1 -> V_34 -> V_35 , L_7 ) ;
while ( true ) {
++ V_65 ;
if ( V_65 > 100 ) {
F_11 ( & V_1 -> V_34 -> V_35 ,
L_8 ) ;
return;
}
F_23 ( & V_57 -> V_66 ) ;
if ( F_7 ( V_1 ) ) {
F_24 ( & V_57 -> V_66 ) ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_9 , V_65 ) ;
break;
}
F_11 ( & V_1 -> V_34 -> V_35 ,
L_10 , V_65 , V_61 ) ;
F_13 ( V_1 , V_58 ) ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_11 , V_65 ) ;
F_1 ( V_1 , V_31 , V_67 ) ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_12 , V_65 ) ;
V_62 = 0 ;
V_63 = 0 ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ ) {
unsigned char V_68 , V_69 , V_70 , V_71 ;
V_69 = ( V_61 >> ( 4 * V_44 ) ) & 0xf ;
V_69 = ( ( V_69 & 0x1 ) << 1 ) |
( ( V_69 & 0x2 ) << 2 ) |
( ( V_69 & 0x4 ) << 3 ) |
( ( V_69 & 0x8 ) << 4 ) ;
V_68 = F_14 ( V_1 , V_69 ) ;
if ( V_1 -> V_42 ) {
F_10 ( & V_1 -> V_34 -> V_35 ,
L_13 , V_65 , V_44 ) ;
break;
}
V_70 = ( ( V_68 & 0x02 ) >> 1 ) |
( ( V_68 & 0x08 ) >> 2 ) |
( ( V_68 & 0x20 ) >> 3 ) |
( ( V_68 & 0x80 ) >> 4 ) ;
V_71 = ( ( V_68 & 0x01 ) >> 0 ) |
( ( V_68 & 0x04 ) >> 1 ) |
( ( V_68 & 0x10 ) >> 2 ) |
( ( V_68 & 0x40 ) >> 3 ) ;
V_62 |= ( unsigned long long ) V_70 << ( V_44 * 4 ) ;
V_63 |= ( unsigned long long ) V_71 << ( V_44 * 4 ) ;
}
if ( V_1 -> V_42 ) {
F_24 ( & V_57 -> V_66 ) ;
F_10 ( & V_1 -> V_34 -> V_35 ,
L_14 , V_65 ) ;
break;
}
F_11 ( & V_1 -> V_34 -> V_35 ,
L_15 ,
V_65 , V_62 , V_63 ) ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_16 , V_65 ) ;
F_1 ( V_1 , V_31 , ~ V_67 ) ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_17 , V_65 ) ;
F_7 ( V_1 ) ;
F_24 ( & V_57 -> V_66 ) ;
if ( ( V_62 & ( ( T_5 ) 1 << 63 ) ) && ( V_63 & ( ( T_5 ) 1 << 63 ) ) ) {
F_10 ( & V_1 -> V_34 -> V_35 ,
L_18 , V_65 ) ;
continue;
}
F_11 ( & V_1 -> V_34 -> V_35 ,
L_19 , V_65 , V_62 ) ;
V_59 ( V_57 , V_62 ) ;
++ V_64 ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_20 , V_65 ) ;
V_63 &= ~ V_61 ;
V_60 = F_25 ( V_63 ) - 1 ;
F_11 ( & V_1 -> V_34 -> V_35 ,
L_21 ,
V_65 , V_63 , V_60 ) ;
if ( V_60 == - 1 )
break;
V_61 = ( V_61 & ~ ( ~ 0ull << ( V_60 ) ) ) | 1 << V_60 ;
}
F_11 ( & V_1 -> V_34 -> V_35 ,
L_22 , V_65 ,
V_64 , V_60 ) ;
}
static int F_26 ( struct V_72 * V_34 )
{
struct V_1 * V_1 ;
struct V_47 * V_48 ;
struct V_73 * V_74 ;
int V_75 ;
if ( ! V_34 )
return - V_76 ;
V_1 = F_27 ( & V_34 -> V_35 , sizeof( * V_1 ) , V_77 ) ;
if ( ! V_1 )
return - V_78 ;
F_28 ( V_34 , V_1 ) ;
V_74 = F_29 ( V_34 , V_79 , 0 ) ;
if ( ! V_74 )
return - V_80 ;
V_1 -> V_4 = F_30 ( & V_34 -> V_35 , V_74 -> V_81 ,
F_31 ( V_74 ) ) ;
if ( ! V_1 -> V_4 )
return - V_78 ;
V_1 -> V_5 = F_31 ( V_74 ) >> 3 ;
V_1 -> V_34 = V_34 ;
V_1 -> V_50 = F_32 ( V_34 ) ;
if ( ! V_1 -> V_50 )
return - V_76 ;
V_48 = V_34 -> V_35 . V_49 ;
if ( ! V_48 )
return - V_76 ;
V_74 = F_29 ( V_34 , V_82 , 0 ) ;
if ( ! V_74 )
return - V_80 ;
V_1 -> V_83 = V_74 -> V_81 ;
V_1 -> V_13 = ( V_48 -> V_84 ? V_85 : 0 ) ;
V_1 -> V_36 = V_48 -> V_36 ;
if ( V_74 -> V_86 & V_87 )
F_33 ( V_1 -> V_83 , V_88 ) ;
if ( V_74 -> V_86 & V_89 )
F_33 ( V_1 -> V_83 , V_90 ) ;
V_75 = F_34 ( & V_34 -> V_35 , V_1 -> V_83 , F_5 ,
V_91 | V_92 , L_23 , V_1 ) ;
if ( V_75 )
return V_75 ;
F_17 ( V_1 ) ;
V_93 . V_7 = ( void * ) V_1 ;
V_75 = F_35 ( & V_93 ) ;
if ( V_75 )
goto V_94;
return 0 ;
V_94:
F_18 ( V_1 ) ;
return V_75 ;
}
static int F_36 ( struct V_72 * V_34 , T_6 V_95 )
{
struct V_1 * V_1 = F_37 ( V_34 ) ;
F_18 ( V_1 ) ;
return 0 ;
}
static int F_38 ( struct V_72 * V_34 )
{
struct V_1 * V_1 = F_37 ( V_34 ) ;
F_17 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_72 * V_34 )
{
struct V_1 * V_1 = F_37 ( V_34 ) ;
F_40 ( & V_93 ) ;
F_18 ( V_1 ) ;
return 0 ;
}
static int T_7 F_41 ( void )
{
F_42 ( L_24 ) ;
return F_43 ( & V_96 ) ;
}
static void T_8 F_44 ( void )
{
F_45 ( & V_96 ) ;
}
