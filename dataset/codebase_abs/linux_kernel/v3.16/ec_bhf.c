static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ,
F_4 ( V_2 -> V_5 + V_6 ) ) ;
F_3 ( V_4 , L_2 ,
F_4 ( V_2 -> V_5 + V_7 ) ) ;
F_3 ( V_4 , L_3 ,
F_4 ( V_2 -> V_5 + V_8 ) ) ;
F_3 ( V_4 , L_4 ,
F_5 ( V_2 -> V_5 + V_9 ) ) ;
F_3 ( V_4 , L_5 ,
F_5 ( V_2 -> V_5 + V_10 ) ) ;
F_3 ( V_4 , L_6 ,
F_4 ( V_2 -> V_5 + V_11 ) ) ;
F_3 ( V_4 , L_7 ,
F_4 ( V_2 -> V_5 + V_12 ) ) ;
F_3 ( V_4 , L_8 ,
F_4 ( V_2 -> V_5 + V_13 ) ) ;
F_3 ( V_4 , L_9 ,
F_4 ( V_2 -> V_14 + V_15 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( 0 , V_2 -> V_5 + V_6 ) ;
F_7 ( 0 , V_2 -> V_5 + V_7 ) ;
F_7 ( 0 , V_2 -> V_5 + V_8 ) ;
F_7 ( 0 , V_2 -> V_5 + V_16 ) ;
F_8 ( 0 , V_2 -> V_5 + V_9 ) ;
F_8 ( 0 , V_2 -> V_5 + V_10 ) ;
F_7 ( 0 , V_2 -> V_5 + V_12 ) ;
F_7 ( 0 , V_2 -> V_17 + V_18 ) ;
F_7 ( 0 , V_2 -> V_17 + V_19 ) ;
F_7 ( 0 , V_2 -> V_5 + V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_22 = F_10 ( V_21 -> V_23 . V_22 ) + sizeof( V_21 -> V_23 ) ;
T_1 V_24 = ( V_25 * ) V_21 - V_2 -> V_26 . V_27 ;
F_8 ( ( F_11 ( V_22 , 8 ) << 24 ) | V_24 , V_2 -> V_17 + V_28 ) ;
F_3 ( F_2 ( V_2 ) , L_10 ) ;
}
static int F_12 ( struct V_20 * V_21 )
{
return F_13 ( V_21 -> V_23 . V_29 ) & V_30 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( F_16 ( V_2 -> V_31 ) ) ) {
F_17 () ;
if ( F_12 ( & V_2 -> V_32 [ V_2 -> V_33 ] ) )
F_18 ( V_2 -> V_31 ) ;
}
}
static int F_19 ( struct V_34 * V_21 )
{
return F_13 ( V_21 -> V_23 . V_35 ) & V_36 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_34 * V_21 )
{
F_8 ( V_37 | ( ( V_25 * ) ( V_21 ) - V_2 -> V_38 . V_27 ) ,
V_2 -> V_17 + V_39 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_34 * V_21 = & V_2 -> V_40 [ V_2 -> V_41 ] ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
while ( F_19 ( V_21 ) ) {
int V_42 = ( F_10 ( V_21 -> V_23 . V_22 ) &
V_43 ) - sizeof( struct V_44 ) - 4 ;
V_25 * V_45 = V_21 -> V_45 ;
struct V_46 * V_47 ;
V_47 = F_22 ( V_2 -> V_31 , V_42 ) ;
F_3 ( V_4 , L_11 , V_42 ) ;
if ( V_47 ) {
memcpy ( F_23 ( V_47 , V_42 ) , V_45 , V_42 ) ;
V_47 -> V_48 = F_24 ( V_47 , V_2 -> V_31 ) ;
F_3 ( V_4 , L_12 , V_47 -> V_48 ) ;
V_2 -> V_49 += V_42 ;
F_25 ( V_47 ) ;
} else {
F_26 ( V_4 ,
L_13 ,
V_42 ) ;
}
V_21 -> V_23 . V_35 = 0 ;
F_20 ( V_2 , V_21 ) ;
V_2 -> V_41 = ( V_2 -> V_41 + 1 ) % V_2 -> V_50 ;
V_21 = & V_2 -> V_40 [ V_2 -> V_41 ] ;
}
}
static enum V_51 F_27 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_28 ( V_53 , struct V_1 ,
V_52 ) ;
F_21 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( ! F_29 ( V_2 -> V_31 ) )
return V_54 ;
F_30 ( V_53 , F_31 ( 0 , V_55 ) ) ;
return V_56 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned V_57 , V_58 ;
void T_2 * V_59 ;
F_3 ( V_4 , L_14 ) ;
F_3 ( V_4 , L_15 , ( unsigned ) F_33 ( V_2 -> V_60 ) ) ;
F_3 ( V_4 , L_16 ,
( unsigned ) F_33 ( V_2 -> V_60 + V_61 ) ) ;
V_57 = F_4 ( V_2 -> V_60 + V_62 ) ;
F_3 ( V_4 , L_17 , V_57 ) ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
T_3 type = F_33 ( V_2 -> V_60 + V_58 * V_63 +
V_64 ) ;
if ( type == V_65 )
break;
}
if ( V_58 == V_57 ) {
F_34 ( V_4 , L_18 ) ;
return - V_66 ;
}
F_3 ( V_4 , L_19 , V_58 ) ;
V_59 = V_2 -> V_60 + V_58 * V_63 ;
F_3 ( V_4 , L_20 ,
F_33 ( V_59 + V_61 ) ) ;
V_2 -> V_67 = F_4 ( V_59 + V_68 ) ;
F_3 ( V_4 , L_21 ,
V_2 -> V_67 ) ;
V_2 -> V_69 = F_4 ( V_59 + V_70 ) ;
F_3 ( V_4 , L_22 ,
V_2 -> V_69 ) ;
V_2 -> V_71 = V_2 -> V_60 + F_5 ( V_59 + V_72 ) ;
V_2 -> V_14 = V_2 -> V_71 + F_5 ( V_2 -> V_71 + V_73 ) ;
V_2 -> V_17 = V_2 -> V_71 + F_5 ( V_2 -> V_71 + V_74 ) ;
V_2 -> V_5 = V_2 -> V_71 + F_5 ( V_2 -> V_71 + V_75 ) ;
F_3 ( V_4 ,
L_23 ,
V_2 -> V_71 , V_2 -> V_17 , V_2 -> V_14 , V_2 -> V_5 ) ;
return 0 ;
}
static T_4 F_35 ( struct V_46 * V_47 ,
struct V_76 * V_31 )
{
struct V_1 * V_2 = F_36 ( V_31 ) ;
struct V_20 * V_21 ;
unsigned V_22 ;
F_3 ( F_2 ( V_2 ) , L_24 ) ;
V_21 = & V_2 -> V_32 [ V_2 -> V_33 ] ;
F_37 ( V_47 , V_21 -> V_45 ) ;
V_22 = V_47 -> V_22 ;
memset ( & V_21 -> V_23 , 0 , sizeof( V_21 -> V_23 ) ) ;
V_21 -> V_23 . V_22 = F_38 ( V_22 ) ;
V_21 -> V_23 . V_77 = V_78 ;
F_9 ( V_2 , V_21 ) ;
V_2 -> V_33 = ( V_2 -> V_33 + 1 ) % V_2 -> V_79 ;
if ( ! F_12 ( & V_2 -> V_32 [ V_2 -> V_33 ] ) ) {
F_39 () ;
F_40 ( V_31 ) ;
F_3 ( F_2 ( V_2 ) , L_25 ) ;
F_1 ( V_2 ) ;
}
V_2 -> V_80 += V_22 ;
F_41 ( V_47 ) ;
return V_81 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_82 * V_27 ,
int V_83 ,
int V_84 )
{
int V_85 = V_83 * V_86 + V_87 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_88 ;
F_8 ( 0xffffffff , V_2 -> V_89 + V_85 ) ;
V_88 = F_5 ( V_2 -> V_89 + V_85 ) ;
V_88 &= V_90 ;
F_3 ( V_4 , L_26 , V_88 , V_83 ) ;
V_27 -> V_22 = F_43 ( int , ~ V_88 + 1 , V_84 ) ;
V_27 -> V_91 = 2 * V_27 -> V_22 ;
F_3 ( V_4 , L_27 ,
( int ) V_27 -> V_91 , V_83 ) ;
V_27 -> V_92 = F_44 ( V_4 , V_27 -> V_91 , & V_27 -> V_93 ,
V_94 ) ;
if ( V_27 -> V_92 == NULL ) {
F_45 ( V_4 , L_28 ) ;
return - V_95 ;
}
V_27 -> V_96 = ( V_27 -> V_93 + V_27 -> V_22 ) & V_88 ;
V_27 -> V_27 = V_27 -> V_92 + ( V_27 -> V_96 - V_27 -> V_93 ) ;
F_8 ( 0 , V_2 -> V_89 + V_85 + 4 ) ;
F_8 ( V_27 -> V_96 , V_2 -> V_89 + V_85 ) ;
F_3 ( V_4 , L_29 ,
( unsigned ) V_27 -> V_96 , F_5 ( V_2 -> V_89 + V_85 ) ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_58 = 0 ;
V_2 -> V_79 = V_2 -> V_26 . V_22 / sizeof( struct V_20 ) ;
V_2 -> V_32 = (struct V_20 * ) V_2 -> V_26 . V_27 ;
V_2 -> V_33 = 0 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_79 ; V_58 ++ )
V_2 -> V_32 [ V_58 ] . V_23 . V_29 = F_47 ( V_30 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_58 ;
V_2 -> V_50 = V_2 -> V_38 . V_22 / sizeof( struct V_34 ) ;
V_2 -> V_40 = (struct V_34 * ) V_2 -> V_38 . V_27 ;
V_2 -> V_41 = 0 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_50 ; V_58 ++ ) {
struct V_34 * V_21 = & V_2 -> V_40 [ V_58 ] ;
T_1 V_97 ;
if ( V_58 != V_2 -> V_50 - 1 )
V_97 = ( V_25 * ) ( V_21 + 1 ) - V_2 -> V_38 . V_27 ;
else
V_97 = 0 ;
V_97 |= V_98 ;
V_21 -> V_23 . V_97 = F_47 ( V_97 ) ;
V_21 -> V_23 . V_35 = 0 ;
F_20 ( V_2 , V_21 ) ;
}
}
static int F_49 ( struct V_76 * V_31 )
{
struct V_1 * V_2 = F_36 ( V_31 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_99 = 0 ;
F_45 ( V_4 , L_30 ) ;
F_6 ( V_2 ) ;
V_99 = F_42 ( V_2 , & V_2 -> V_38 , V_2 -> V_69 ,
V_100 * sizeof( struct V_34 ) ) ;
if ( V_99 ) {
F_34 ( V_4 , L_31 ) ;
goto V_101;
}
F_48 ( V_2 ) ;
F_45 ( V_4 , L_32 ,
( unsigned ) V_2 -> V_38 . V_96 ) ;
V_99 = F_42 ( V_2 , & V_2 -> V_26 , V_2 -> V_67 ,
V_100 * sizeof( struct V_20 ) ) ;
if ( V_99 ) {
F_34 ( V_4 , L_33 ) ;
goto V_102;
}
F_3 ( V_4 , L_34 ,
( unsigned ) V_2 -> V_26 . V_96 ) ;
F_7 ( 0 , V_2 -> V_14 + V_103 ) ;
F_46 ( V_2 ) ;
F_50 ( V_31 ) ;
F_51 ( & V_2 -> V_52 , V_104 , V_105 ) ;
V_2 -> V_52 . V_106 = F_27 ;
F_52 ( & V_2 -> V_52 , F_31 ( 0 , V_55 ) ,
V_105 ) ;
F_45 ( F_2 ( V_2 ) , L_35 ) ;
F_1 ( V_2 ) ;
return 0 ;
V_102:
F_53 ( V_4 , V_2 -> V_38 . V_91 , V_2 -> V_38 . V_92 ,
V_2 -> V_38 . V_91 ) ;
V_101:
return V_99 ;
}
static int F_54 ( struct V_76 * V_31 )
{
struct V_1 * V_2 = F_36 ( V_31 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_55 ( & V_2 -> V_52 ) ;
F_6 ( V_2 ) ;
F_56 ( V_31 ) ;
F_53 ( V_4 , V_2 -> V_26 . V_91 ,
V_2 -> V_26 . V_92 , V_2 -> V_26 . V_93 ) ;
F_53 ( V_4 , V_2 -> V_38 . V_91 ,
V_2 -> V_38 . V_92 , V_2 -> V_38 . V_93 ) ;
return 0 ;
}
static struct V_107 *
F_57 ( struct V_76 * V_31 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_36 ( V_31 ) ;
V_108 -> V_109 = F_4 ( V_2 -> V_5 + V_7 ) +
F_4 ( V_2 -> V_5 + V_8 ) +
F_4 ( V_2 -> V_5 + V_6 ) ;
V_108 -> V_110 = F_5 ( V_2 -> V_5 + V_10 ) ;
V_108 -> V_111 = F_5 ( V_2 -> V_5 + V_9 ) ;
V_108 -> V_112 = F_4 ( V_2 -> V_5 + V_12 ) ;
V_108 -> V_113 = V_2 -> V_80 ;
V_108 -> V_114 = V_2 -> V_49 ;
return V_108 ;
}
static int F_58 ( struct V_115 * V_4 , const struct V_116 * V_117 )
{
struct V_76 * V_31 ;
struct V_1 * V_2 ;
void T_2 * V_89 ;
void T_2 * V_60 ;
int V_99 = 0 ;
V_99 = F_59 ( V_4 ) ;
if ( V_99 )
return V_99 ;
F_60 ( V_4 ) ;
V_99 = F_61 ( V_4 , F_62 ( 32 ) ) ;
if ( V_99 ) {
F_34 ( & V_4 -> V_4 ,
L_36 ) ;
V_99 = - V_118 ;
goto V_119;
}
V_99 = F_63 ( V_4 , F_62 ( 32 ) ) ;
if ( V_99 ) {
F_34 ( & V_4 -> V_4 ,
L_36 ) ;
goto V_119;
}
V_99 = F_64 ( V_4 , L_37 ) ;
if ( V_99 ) {
F_34 ( & V_4 -> V_4 , L_38 ) ;
goto V_119;
}
V_60 = F_65 ( V_4 , 0 , 0 ) ;
if ( ! V_60 ) {
F_34 ( & V_4 -> V_4 , L_39 ) ;
V_99 = - V_118 ;
goto V_120;
}
V_89 = F_65 ( V_4 , 2 , 0 ) ;
if ( ! V_89 ) {
F_34 ( & V_4 -> V_4 , L_40 ) ;
V_99 = - V_118 ;
goto V_121;
}
V_31 = F_66 ( sizeof( struct V_1 ) ) ;
if ( V_31 == NULL ) {
V_99 = - V_95 ;
goto V_122;
}
F_67 ( V_4 , V_31 ) ;
F_68 ( V_31 , & V_4 -> V_4 ) ;
V_31 -> V_123 = 0 ;
V_31 -> V_124 |= V_125 ;
V_31 -> V_126 = & V_127 ;
V_2 = F_36 ( V_31 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_60 = V_60 ;
V_2 -> V_89 = V_89 ;
V_2 -> V_4 = V_4 ;
V_99 = F_32 ( V_2 ) ;
if ( V_99 < 0 )
goto V_128;
F_69 ( V_31 -> V_129 , V_2 -> V_14 + V_130 , 6 ) ;
F_3 ( & V_4 -> V_4 , L_41 ,
V_31 -> V_129 ) ;
V_99 = F_70 ( V_31 ) ;
if ( V_99 < 0 )
goto V_128;
return 0 ;
V_128:
F_71 ( V_31 ) ;
V_122:
F_72 ( V_4 , V_89 ) ;
V_121:
F_72 ( V_4 , V_60 ) ;
V_120:
F_73 ( V_4 ) ;
V_119:
F_74 ( V_4 ) ;
F_75 ( V_4 ) ;
return V_99 ;
}
static void F_76 ( struct V_115 * V_4 )
{
struct V_76 * V_31 = F_77 ( V_4 ) ;
struct V_1 * V_2 = F_36 ( V_31 ) ;
F_78 ( V_31 ) ;
F_71 ( V_31 ) ;
F_72 ( V_4 , V_2 -> V_89 ) ;
F_72 ( V_4 , V_2 -> V_60 ) ;
F_73 ( V_4 ) ;
F_74 ( V_4 ) ;
F_75 ( V_4 ) ;
}
static int T_5 F_79 ( void )
{
return F_80 ( & V_131 ) ;
}
static void T_6 F_81 ( void )
{
F_82 ( & V_131 ) ;
}
