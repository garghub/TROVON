static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) && V_2 -> V_4 == 0 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_2 -> V_7 [ V_5 ] . V_8 = 0 ;
V_2 -> V_7 [ V_5 ] . V_9 = 0 ;
V_2 -> V_7 [ V_5 ] . V_10 = 0 ;
}
}
}
static int T_1 F_3 ( struct V_11 * V_12 )
{
unsigned int V_13 = 100 ;
while ( V_13 -- ) {
if ( F_4 ( V_12 , V_14 ) & ( 1 << V_15 ) )
return 0 ;
F_5 ( 100 ) ;
}
return - V_16 ;
}
static int T_1 F_6 ( struct V_11 * V_12 , unsigned int V_17 )
{
unsigned int V_13 = 100 ;
while ( V_13 -- ) {
if ( ( F_4 ( V_12 , V_18 ) & V_17 ) == V_17 )
return 0 ;
F_5 ( 100 ) ;
}
return - V_16 ;
}
static void T_1 F_7 ( struct V_11 * V_12 , unsigned int V_19 ,
unsigned int V_20 , unsigned int V_21 )
{
unsigned long V_22 ;
V_22 = ( 1 << V_23 ) + ( ( V_20 & 0xf ) << V_24 ) +
( ( V_19 & 0xff ) << V_25 ) ;
F_8 ( V_12 , V_21 , V_26 ) ;
F_8 ( V_12 , V_22 , V_14 ) ;
F_3 ( V_12 ) ;
F_8 ( V_12 , 0 , V_26 ) ;
F_8 ( V_12 , 0 , V_14 ) ;
F_3 ( V_12 ) ;
}
static int T_1 F_9 ( struct V_27 * V_28 )
{
struct V_11 * V_12 = V_28 -> V_29 ;
struct V_30 * V_30 ;
char V_31 [ 16 ] ;
int V_32 ;
V_32 = F_10 ( & V_33 ) ;
if ( F_11 ( V_32 != 0 ) )
return V_32 ;
snprintf ( V_31 , sizeof( V_31 ) , L_1 , V_28 -> V_34 ) ;
V_28 -> V_35 = F_12 ( NULL , V_31 ) ;
if ( F_13 ( V_28 -> V_35 ) ) {
V_32 = F_14 ( V_28 -> V_35 ) ;
goto V_36;
}
F_15 ( V_28 -> V_35 ) ;
V_30 = & V_28 -> V_37 ;
memset ( V_30 , 0 , sizeof( struct V_30 ) ) ;
V_30 -> V_38 = & V_33 ;
V_30 -> V_39 = ( void V_40 * ) ( V_12 -> V_41 + V_42 ) ;
V_30 -> V_43 = V_44 ;
V_32 = F_16 ( V_30 , 1 ) ;
if ( F_11 ( V_32 < 0 ) )
goto V_45;
return 0 ;
V_45:
F_17 ( V_28 -> V_35 ) ;
F_18 ( V_28 -> V_35 ) ;
V_36:
F_19 ( & V_33 ) ;
return V_32 ;
}
static int T_1 F_20 ( struct V_27 * V_28 )
{
struct V_11 * V_12 = V_28 -> V_29 ;
unsigned int V_13 = 100 ;
F_15 ( & V_28 -> V_37 ) ;
F_7 ( V_12 , 0x60 , 0xf , 0x004b008b ) ;
F_7 ( V_12 , 0x61 , 0xf , 0x00007b41 ) ;
F_7 ( V_12 , 0x64 , 0xf , 0x00ff4f00 ) ;
F_7 ( V_12 , 0x65 , 0xf , 0x09070907 ) ;
F_7 ( V_12 , 0x66 , 0xf , 0x00000010 ) ;
F_7 ( V_12 , 0x74 , 0xf , 0x0007001c ) ;
F_7 ( V_12 , 0x79 , 0xf , 0x01fc000d ) ;
F_7 ( V_12 , 0xb0 , 0xf , 0x00000610 ) ;
F_7 ( V_12 , 0x67 , 0x1 , 0x00000400 ) ;
F_17 ( & V_28 -> V_37 ) ;
while ( V_13 -- ) {
if ( F_4 ( V_12 , V_46 ) )
return 0 ;
F_5 ( 100 ) ;
}
return - V_16 ;
}
static void T_1 F_21 ( struct V_27 * V_28 )
{
struct V_11 * V_12 = V_28 -> V_29 ;
F_8 ( V_12 , 1 , V_47 ) ;
F_8 ( V_12 , 0 , V_48 ) ;
F_8 ( V_12 , 0 , V_47 ) ;
F_8 ( V_12 , 0 , V_49 ) ;
}
static int T_1 F_22 ( struct V_27 * V_28 )
{
struct V_11 * V_12 = V_28 -> V_29 ;
unsigned int V_21 ;
T_2 V_50 ;
T_3 V_51 ;
int V_32 , V_5 , V_52 ;
F_21 ( V_28 ) ;
F_8 ( V_12 , V_53 << 16 , V_54 ) ;
V_21 = F_4 ( V_12 , V_55 ) ;
V_21 &= ~ ( V_56 << 16 ) ;
if ( V_28 -> V_57 )
V_21 |= V_58 << 20 ;
else
V_21 |= V_59 << 20 ;
V_21 |= V_60 ;
F_8 ( V_12 , V_21 , V_55 ) ;
F_8 ( V_12 , V_61 , V_62 ) ;
V_21 = F_4 ( V_12 , V_63 ) ;
V_21 &= ~ V_64 ;
V_21 |= V_65 | 1 ;
F_8 ( V_12 , V_21 , V_63 ) ;
V_21 = F_4 ( V_12 , V_66 ) ;
V_21 &= ~ V_67 ;
V_21 |= ( V_28 -> V_34 + 1 ) << 19 ;
F_8 ( V_12 , V_21 , V_66 ) ;
V_21 = F_4 ( V_12 , V_68 ) ;
V_21 &= ~ 0x3f00 ;
V_21 |= 0x32 << 8 ;
F_8 ( V_12 , V_21 , V_68 ) ;
V_21 = F_4 ( V_12 , V_69 ) ;
V_21 &= ~ V_70 ;
V_21 |= ( 0xff << 16 ) ;
F_8 ( V_12 , V_21 , V_69 ) ;
V_50 = F_23 ( V_71 ) ;
V_51 = F_24 ( V_72 - V_71 ) ;
if ( V_51 > V_73 ) {
F_8 ( V_12 , V_50 + V_73 , V_74 ) ;
F_8 ( V_12 , ( ( V_51 - V_73 ) - V_75 ) | 1 ,
V_76 ) ;
V_51 = V_73 ;
} else {
F_8 ( V_12 , 0 , V_74 ) ;
F_8 ( V_12 , 0 , V_76 ) ;
}
F_8 ( V_12 , V_50 , V_77 ) ;
F_8 ( V_12 , ( V_51 - V_75 ) | 1 , V_78 ) ;
V_21 = F_4 ( V_12 , V_48 ) ;
V_21 |= 0x1 ;
F_8 ( V_12 , V_21 , V_48 ) ;
F_25 ( 100 ) ;
V_21 = F_4 ( V_12 , V_79 ) ;
V_21 |= V_80 ;
F_8 ( V_12 , V_21 , V_79 ) ;
V_21 = F_4 ( V_12 , V_69 ) ;
V_21 |= V_70 | ( 0xff << 16 ) ;
F_8 ( V_12 , V_21 , V_69 ) ;
V_32 = F_6 ( V_12 , V_81 ) ;
V_21 = F_4 ( V_12 , V_82 ) ;
V_21 &= ~ ( V_83 << 16 ) ;
V_21 |= V_84 | V_85 | V_86 |
( V_87 | V_88 ) << 16 ;
F_8 ( V_12 , V_21 , V_82 ) ;
F_8 ( V_12 , 0x80888000 , V_89 ) ;
F_8 ( V_12 , 0x00222000 , V_90 ) ;
F_26 () ;
if ( V_32 == 0 ) {
V_21 = F_4 ( V_12 , V_91 ) ;
F_27 ( V_92 L_2 ,
V_28 -> V_34 , ( V_21 >> 20 ) & 0x3f ) ;
} else
F_27 ( V_92 L_3 ,
V_28 -> V_34 ) ;
for ( V_5 = V_52 = 0 ; V_5 < V_12 -> V_93 ; V_5 ++ ) {
struct V_7 * V_94 = V_12 -> V_95 + V_5 ;
T_4 V_96 ;
T_5 V_17 ;
if ( ( V_94 -> V_10 & V_97 ) && F_28 () )
continue;
F_8 ( V_12 , 0x00000000 , F_29 ( V_52 ) ) ;
V_96 = F_30 ( V_94 ) ;
V_17 = ( F_24 ( V_96 ) / V_98 ) - 1 ;
F_8 ( V_12 , V_17 << 18 , F_31 ( V_52 ) ) ;
F_8 ( V_12 , F_32 ( V_94 -> V_8 ) ,
F_33 ( V_52 ) ) ;
F_8 ( V_12 , F_34 ( V_94 -> V_8 ) ,
F_35 ( V_52 ) ) ;
V_17 = V_99 ;
if ( V_94 -> V_10 & V_100 )
V_17 |= V_101 ;
F_8 ( V_12 , V_17 , F_29 ( V_52 ) ) ;
V_52 ++ ;
}
return 0 ;
}
int F_36 ( const struct V_1 * V_102 , T_6 V_103 , T_6 V_104 )
{
return F_37 ( 0xae0 ) ;
}
static int T_1 F_38 ( void )
{
return F_39 ( V_105 ) ? 3 : 2 ;
}
static void T_1 F_40 ( void * V_21 , T_7 V_106 )
{
struct V_27 * V_28 = V_21 ;
int V_32 ;
V_28 -> V_57 = F_39 ( V_107 ) ;
V_32 = F_9 ( V_28 ) ;
if ( F_11 ( V_32 < 0 ) ) {
F_41 ( L_4 ,
V_28 -> V_34 ) ;
return;
}
V_32 = F_20 ( V_28 ) ;
if ( F_11 ( V_32 < 0 ) ) {
F_41 ( L_5 ,
V_28 -> V_34 ) ;
return;
}
V_32 = F_22 ( V_28 ) ;
if ( F_11 ( V_32 < 0 ) ) {
F_41 ( L_6 ,
V_28 -> V_34 ) ;
return;
}
F_42 ( V_106 ) ;
F_43 ( V_28 -> V_29 ) ;
}
static int T_1 F_44 ( void )
{
struct V_30 * V_108 ;
int V_5 ;
F_27 ( V_92 L_7 ) ;
V_109 = & V_110 ;
V_111 = V_109 -> V_112 () ;
F_45 ( V_111 > F_46 ( V_113 ) ) ;
if ( F_11 ( V_111 == 0 ) )
return - V_114 ;
V_115 = F_47 ( V_111 * sizeof( struct V_27 ) ,
V_116 ) ;
if ( F_11 ( ! V_115 ) )
return - V_117 ;
V_108 = F_12 ( NULL , L_8 ) ;
if ( F_13 ( V_108 ) ) {
V_108 = NULL ;
}
F_15 ( V_108 ) ;
F_27 ( V_92 L_9 , V_111 ) ;
for ( V_5 = 0 ; V_5 < V_111 ; V_5 ++ ) {
struct V_27 * V_28 = V_115 + V_5 ;
V_28 -> V_34 = V_5 ;
V_28 -> V_29 = V_113 + V_5 ;
V_28 -> V_29 -> V_118 = V_28 -> V_29 -> V_95 [ 0 ] . V_8 ;
F_48 ( V_109 -> V_119 , V_28 ) ;
}
F_49 () ;
return 0 ;
}
