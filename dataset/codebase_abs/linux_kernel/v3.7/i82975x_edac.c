static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_8 ) ;
F_4 ( V_6 , V_9 , & V_4 -> V_10 ) ;
F_5 ( V_6 , V_11 , & V_4 -> V_12 ) ;
F_5 ( V_6 , V_13 , & V_4 -> V_14 ) ;
F_5 ( V_6 , V_15 , & V_4 -> V_16 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_17 ) ;
F_6 ( V_6 , V_7 , 0x0003 , 0x0003 ) ;
if ( ! ( V_4 -> V_17 & 0x0003 ) )
return;
if ( ( V_4 -> V_8 ^ V_4 -> V_17 ) & 0x0003 ) {
F_4 ( V_6 , V_9 , & V_4 -> V_10 ) ;
F_5 ( V_6 , V_11 , & V_4 -> V_12 ) ;
F_5 ( V_6 , V_13 , & V_4 -> V_14 ) ;
F_5 ( V_6 , V_15 ,
& V_4 -> V_16 ) ;
}
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_18 )
{
int V_19 , V_20 ;
unsigned long V_21 , V_22 ;
if ( ! ( V_4 -> V_17 & 0x0003 ) )
return 0 ;
if ( ! V_18 )
return 1 ;
if ( ( V_4 -> V_8 ^ V_4 -> V_17 ) & 0x0003 ) {
F_8 ( V_23 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_1 , L_2 ) ;
V_4 -> V_8 = V_4 -> V_17 ;
}
V_22 = ( unsigned long ) V_4 -> V_10 ;
V_22 >>= 1 ;
if ( V_4 -> V_12 & 1 )
V_22 |= 0x80000000 ;
V_22 >>= ( V_24 - 1 ) ;
V_19 = F_9 ( V_2 , V_22 ) ;
if ( V_19 == - 1 ) {
F_10 ( V_2 , V_25 , L_3
L_4
L_5
L_6 ,
( V_4 -> V_12 & 1 ) ? 1 : 0 , V_4 -> V_10 , ( unsigned int ) V_22 ) ;
return 0 ;
}
V_20 = ( V_2 -> V_26 [ V_19 ] -> V_27 == 1 ) ? 0 : V_4 -> V_10 & 1 ;
V_21 = V_4 -> V_10
& ( ( 1 << V_24 ) -
( 1 << V_2 -> V_26 [ V_19 ] -> V_28 [ V_20 ] -> V_29 -> V_30 ) ) ;
if ( V_4 -> V_8 & 0x0002 )
F_8 ( V_23 , V_2 , 1 ,
V_22 , V_21 , 0 ,
V_19 , - 1 , - 1 ,
L_7 , L_2 ) ;
else
F_8 ( V_31 , V_2 , 1 ,
V_22 , V_21 , V_4 -> V_16 ,
V_19 , V_20 ? V_20 : 0 , - 1 ,
L_8 , L_2 ) ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_12 ( 1 , L_9 , V_2 -> V_32 ) ;
F_1 ( V_2 , & V_4 ) ;
F_7 ( V_2 , & V_4 , 1 ) ;
}
static int F_13 ( void T_1 * V_33 )
{
T_2 V_34 [ 4 ] [ 2 ] ;
int V_19 ;
int V_35 ;
for ( V_35 = 1 , V_19 = 0 ; V_35 && ( V_19 < 4 ) ; V_19 ++ ) {
V_34 [ V_19 ] [ 0 ] = F_14 ( V_33 + V_36 + V_19 ) ;
V_34 [ V_19 ] [ 1 ] = F_14 ( V_33 + V_36 + V_19 + 0x80 ) ;
V_35 = V_35 && ( V_34 [ V_19 ] [ 0 ] == V_34 [ V_19 ] [ 1 ] ) ;
}
return V_35 ;
}
static enum V_37 F_15 ( void T_1 * V_33 , int V_38 )
{
return V_39 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 , void T_1 * V_33 )
{
struct V_40 * V_41 ;
unsigned long V_42 ;
T_2 V_43 ;
T_3 V_44 , V_45 ;
int V_46 , V_20 ;
struct V_47 * V_29 ;
enum V_37 V_48 ;
V_42 = 0 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_49 ; V_46 ++ ) {
V_41 = V_2 -> V_26 [ V_46 ] ;
V_43 = F_14 ( V_33 + V_36 + V_46 +
( ( V_46 >= 4 ) ? 0x80 : 0 ) ) ;
V_44 = V_43 ;
V_44 <<= ( V_50 - V_24 ) ;
if ( V_41 -> V_27 > 1 )
V_44 <<= 1 ;
F_12 ( 3 , L_10 , V_46 , V_44 ) ;
V_45 = V_44 - V_42 ;
if ( ! V_45 )
continue;
V_48 = F_15 ( V_33 , V_46 ) ;
for ( V_20 = 0 ; V_20 < V_41 -> V_27 ; V_20 ++ ) {
V_29 = V_2 -> V_26 [ V_46 ] -> V_28 [ V_20 ] -> V_29 ;
V_29 -> V_45 = V_45 / V_41 -> V_27 ;
snprintf ( V_41 -> V_28 [ V_20 ] -> V_29 -> V_51 , V_52 , L_11 ,
( V_20 == 0 ) ? 'A' : 'B' ,
V_46 ) ;
V_29 -> V_30 = 1 << 7 ;
V_29 -> V_48 = F_15 ( V_33 , V_46 ) ;
V_29 -> V_53 = V_54 ;
V_29 -> V_55 = V_56 ;
}
V_41 -> V_57 = V_42 ;
V_41 -> V_58 = V_44 - 1 ;
V_42 = V_44 ;
}
}
static void F_17 ( void T_1 * V_33 )
{
static const int V_59 [ 4 ] = { 5 , 4 , 3 , 6 } ;
T_3 V_60 [ 2 ] ;
V_60 [ 0 ] = F_18 ( V_33 + 0x114 ) ;
V_60 [ 1 ] = F_18 ( V_33 + 0x194 ) ;
F_19 ( V_61 , L_12
L_13
L_14
L_15
L_16 ,
( V_60 [ 0 ] >> 19 ) & 0x0f ,
( V_60 [ 1 ] >> 19 ) & 0x0f ,
V_59 [ ( V_60 [ 0 ] >> 8 ) & 0x03 ] ,
V_59 [ ( V_60 [ 1 ] >> 8 ) & 0x03 ] ,
( ( V_60 [ 0 ] >> 4 ) & 0x07 ) + 2 ,
( ( V_60 [ 1 ] >> 4 ) & 0x07 ) + 2 ,
( V_60 [ 0 ] & 0x07 ) + 2 ,
( V_60 [ 1 ] & 0x07 ) + 2
) ;
}
static int F_20 ( struct V_5 * V_6 , int V_62 )
{
int V_63 = - V_64 ;
struct V_1 * V_2 ;
struct V_65 V_66 [ 2 ] ;
struct V_67 * V_68 ;
void T_1 * V_33 ;
T_3 V_69 ;
T_3 V_70 [ 2 ] ;
struct V_3 V_71 ;
int V_72 ;
#ifdef F_21
T_2 V_73 [ 4 ] ;
T_2 V_74 [ 4 ] ;
#endif
F_12 ( 0 , L_17 ) ;
F_4 ( V_6 , V_75 , & V_69 ) ;
if ( ! ( V_69 & 1 ) ) {
F_12 ( 3 , L_18 ) ;
goto V_76;
}
V_69 &= 0xffffc000 ;
V_33 = F_22 ( V_69 , 0x1000 ) ;
#ifdef F_21
F_19 ( V_61 , L_19 ,
V_69 , V_33 ) ;
V_73 [ 0 ] = F_14 ( V_33 + V_77 ) ;
V_73 [ 1 ] = F_14 ( V_33 + V_78 ) ;
V_73 [ 2 ] = F_14 ( V_33 + V_79 ) ;
V_73 [ 3 ] = F_14 ( V_33 + V_80 ) ;
V_74 [ 0 ] = F_14 ( V_33 + V_81 ) ;
V_74 [ 1 ] = F_14 ( V_33 + V_82 ) ;
V_74 [ 2 ] = F_14 ( V_33 + V_83 ) ;
V_74 [ 3 ] = F_14 ( V_33 + V_84 ) ;
F_19 ( V_61 , L_20 , V_73 [ 0 ] ) ;
F_19 ( V_61 , L_21 , V_73 [ 1 ] ) ;
F_19 ( V_61 , L_22 , V_73 [ 2 ] ) ;
F_19 ( V_61 , L_23 , V_73 [ 3 ] ) ;
F_19 ( V_61 , L_24 , V_74 [ 0 ] ) ;
F_19 ( V_61 , L_25 , V_74 [ 1 ] ) ;
F_19 ( V_61 , L_26 , V_74 [ 2 ] ) ;
F_19 ( V_61 , L_27 , V_74 [ 3 ] ) ;
#endif
V_70 [ 0 ] = F_18 ( V_33 + V_85 ) ;
V_70 [ 1 ] = F_18 ( V_33 + V_86 ) ;
#ifdef F_21
F_19 ( V_61 , L_28 , V_70 [ 0 ] ,
( ( V_70 [ 0 ] >> 21 ) & 3 ) == 1 ?
L_29 : L_30 ) ;
F_19 ( V_61 , L_31 , V_70 [ 1 ] ,
( ( V_70 [ 1 ] >> 21 ) & 3 ) == 1 ?
L_29 : L_30 ) ;
F_19 ( V_61 , L_32 ,
F_23 ( V_33 + V_87 ) ) ;
F_19 ( V_61 , L_33 ,
F_23 ( V_33 + V_88 ) ) ;
F_17 ( V_33 ) ;
goto V_89;
#endif
if ( ! ( ( ( V_70 [ 0 ] >> 21 ) & 3 ) == 1 || ( ( V_70 [ 1 ] >> 21 ) & 3 ) == 1 ) ) {
F_19 ( V_61 , L_34 ) ;
goto V_89;
}
V_72 = F_13 ( V_33 ) + 1 ;
V_66 [ 0 ] . type = V_90 ;
V_66 [ 0 ] . V_91 = V_92 ;
V_66 [ 0 ] . V_93 = true ;
V_66 [ 1 ] . type = V_94 ;
V_66 [ 1 ] . V_91 = F_24 ( V_72 ) ;
V_66 [ 1 ] . V_93 = false ;
V_2 = F_25 ( 0 , F_26 ( V_66 ) , V_66 , sizeof( * V_68 ) ) ;
if ( ! V_2 ) {
V_63 = - V_95 ;
goto V_89;
}
F_12 ( 3 , L_35 ) ;
V_2 -> V_6 = & V_6 -> V_96 ;
V_2 -> V_97 = V_98 ;
V_2 -> V_99 = V_100 | V_101 ;
V_2 -> V_102 = V_100 | V_101 ;
V_2 -> V_103 = V_104 ;
V_2 -> V_105 = V_106 ;
V_2 -> V_107 = V_108 [ V_62 ] . V_107 ;
V_2 -> V_109 = F_27 ( V_6 ) ;
V_2 -> V_110 = F_11 ;
V_2 -> V_111 = NULL ;
F_12 ( 3 , L_36 ) ;
V_68 = (struct V_67 * ) V_2 -> V_112 ;
V_68 -> V_33 = V_33 ;
F_16 ( V_2 , V_6 , V_33 ) ;
V_2 -> V_113 = V_114 ;
F_1 ( V_2 , & V_71 ) ;
if ( F_28 ( V_2 ) ) {
F_12 ( 3 , L_37 ) ;
goto V_115;
}
F_12 ( 3 , L_38 ) ;
return 0 ;
V_115:
F_29 ( V_2 ) ;
V_89:
F_30 ( V_33 ) ;
V_76:
return V_63 ;
}
static int T_4 F_31 ( struct V_5 * V_6 ,
const struct V_116 * V_117 )
{
int V_63 ;
F_12 ( 0 , L_17 ) ;
if ( F_32 ( V_6 ) < 0 )
return - V_118 ;
V_63 = F_20 ( V_6 , V_117 -> V_119 ) ;
if ( V_120 == NULL )
V_120 = F_33 ( V_6 ) ;
return V_63 ;
}
static void T_5 F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_67 * V_68 ;
F_12 ( 0 , L_17 ) ;
V_2 = F_35 ( & V_6 -> V_96 ) ;
if ( V_2 == NULL )
return;
V_68 = V_2 -> V_112 ;
if ( V_68 -> V_33 )
F_30 ( V_68 -> V_33 ) ;
F_29 ( V_2 ) ;
}
static int T_6 F_36 ( void )
{
int V_121 ;
F_12 ( 3 , L_17 ) ;
F_37 () ;
V_121 = F_38 ( & V_122 ) ;
if ( V_121 < 0 )
goto V_76;
if ( V_120 == NULL ) {
V_120 = F_39 ( V_123 ,
V_124 , NULL ) ;
if ( ! V_120 ) {
F_12 ( 0 , L_39 ) ;
V_121 = - V_64 ;
goto V_89;
}
V_121 = F_31 ( V_120 , V_125 ) ;
if ( V_121 < 0 ) {
F_12 ( 0 , L_40 ) ;
V_121 = - V_64 ;
goto V_89;
}
}
return 0 ;
V_89:
F_40 ( & V_122 ) ;
V_76:
if ( V_120 != NULL )
F_41 ( V_120 ) ;
return V_121 ;
}
static void T_7 F_42 ( void )
{
F_12 ( 3 , L_17 ) ;
F_40 ( & V_122 ) ;
if ( ! V_126 ) {
F_34 ( V_120 ) ;
F_41 ( V_120 ) ;
}
}
