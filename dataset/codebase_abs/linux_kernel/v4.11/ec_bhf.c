static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_3 + V_4 ) ;
F_2 ( 0 , V_2 -> V_3 + V_5 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0 , V_2 -> V_3 + V_7 ) ;
F_3 ( 0 , V_2 -> V_3 + V_8 ) ;
F_3 ( 0 , V_2 -> V_3 + V_9 ) ;
F_2 ( 0 , V_2 -> V_3 + V_10 ) ;
F_2 ( 0 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0 , V_2 -> V_11 + V_13 ) ;
F_2 ( 0 , V_2 -> V_3 + V_14 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_17 = F_5 ( V_16 -> V_18 . V_17 ) + sizeof( V_16 -> V_18 ) ;
T_1 V_19 = ( V_20 * ) V_16 - V_2 -> V_21 . V_22 ;
F_3 ( ( F_6 ( V_17 , 8 ) << 24 ) | V_19 , V_2 -> V_11 + V_23 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
return F_8 ( V_16 -> V_18 . V_24 ) & V_25 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( F_11 ( V_2 -> V_26 ) ) ) {
F_12 () ;
if ( F_7 ( & V_2 -> V_27 [ V_2 -> V_28 ] ) )
F_13 ( V_2 -> V_26 ) ;
}
}
static int F_14 ( struct V_29 * V_16 )
{
return F_8 ( V_16 -> V_18 . V_30 ) & V_31 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_29 * V_16 )
{
F_3 ( V_32 | ( ( V_20 * ) ( V_16 ) - V_2 -> V_33 . V_22 ) ,
V_2 -> V_11 + V_34 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_16 = & V_2 -> V_35 [ V_2 -> V_36 ] ;
while ( F_14 ( V_16 ) ) {
int V_37 = ( F_5 ( V_16 -> V_18 . V_17 ) &
V_38 ) - sizeof( struct V_39 ) - 4 ;
V_20 * V_40 = V_16 -> V_40 ;
struct V_41 * V_42 ;
V_42 = F_17 ( V_2 -> V_26 , V_37 ) ;
if ( V_42 ) {
memcpy ( F_18 ( V_42 , V_37 ) , V_40 , V_37 ) ;
V_42 -> V_43 = F_19 ( V_42 , V_2 -> V_26 ) ;
V_2 -> V_44 += V_37 ;
F_20 ( V_42 ) ;
} else {
F_21 ( F_22 ( V_2 ) ,
L_1 ,
V_37 ) ;
}
V_16 -> V_18 . V_30 = 0 ;
F_15 ( V_2 , V_16 ) ;
V_2 -> V_36 = ( V_2 -> V_36 + 1 ) % V_2 -> V_45 ;
V_16 = & V_2 -> V_35 [ V_2 -> V_36 ] ;
}
}
static enum V_46 F_23 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_24 ( V_48 , struct V_1 ,
V_47 ) ;
F_16 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( ! F_25 ( V_2 -> V_26 ) )
return V_49 ;
F_26 ( V_48 , V_50 ) ;
return V_51 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_22 ( V_2 ) ;
unsigned V_54 , V_55 ;
void T_2 * V_56 ;
V_54 = F_28 ( V_2 -> V_57 + V_58 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
T_3 type = F_29 ( V_2 -> V_57 + V_55 * V_59 +
V_60 ) ;
if ( type == V_61 )
break;
}
if ( V_55 == V_54 ) {
F_30 ( V_53 , L_2 ) ;
return - V_62 ;
}
V_56 = V_2 -> V_57 + V_55 * V_59 ;
V_2 -> V_63 = F_28 ( V_56 + V_64 ) ;
V_2 -> V_65 = F_28 ( V_56 + V_66 ) ;
V_2 -> V_67 = V_2 -> V_57 + F_31 ( V_56 + V_68 ) ;
V_2 -> V_69 = V_2 -> V_67 + F_31 ( V_2 -> V_67 + V_70 ) ;
V_2 -> V_11 = V_2 -> V_67 + F_31 ( V_2 -> V_67 + V_71 ) ;
V_2 -> V_3 = V_2 -> V_67 + F_31 ( V_2 -> V_67 + V_72 ) ;
return 0 ;
}
static T_4 F_32 ( struct V_41 * V_42 ,
struct V_73 * V_26 )
{
struct V_1 * V_2 = F_33 ( V_26 ) ;
struct V_15 * V_16 ;
unsigned V_17 ;
V_16 = & V_2 -> V_27 [ V_2 -> V_28 ] ;
F_34 ( V_42 , V_16 -> V_40 ) ;
V_17 = V_42 -> V_17 ;
memset ( & V_16 -> V_18 , 0 , sizeof( V_16 -> V_18 ) ) ;
V_16 -> V_18 . V_17 = F_35 ( V_17 ) ;
V_16 -> V_18 . V_74 = V_75 ;
F_4 ( V_2 , V_16 ) ;
V_2 -> V_28 = ( V_2 -> V_28 + 1 ) % V_2 -> V_76 ;
if ( ! F_7 ( & V_2 -> V_27 [ V_2 -> V_28 ] ) ) {
F_36 () ;
F_37 ( V_26 ) ;
}
V_2 -> V_77 += V_17 ;
F_38 ( V_42 ) ;
return V_78 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_79 * V_22 ,
int V_80 ,
int V_81 )
{
int V_82 = V_80 * V_83 + V_84 ;
struct V_52 * V_53 = F_22 ( V_2 ) ;
T_1 V_85 ;
F_3 ( 0xffffffff , V_2 -> V_86 + V_82 ) ;
V_85 = F_31 ( V_2 -> V_86 + V_82 ) ;
V_85 &= V_87 ;
V_22 -> V_17 = F_40 ( int , ~ V_85 + 1 , V_81 ) ;
V_22 -> V_88 = 2 * V_22 -> V_17 ;
V_22 -> V_89 = F_41 ( V_53 , V_22 -> V_88 , & V_22 -> V_90 ,
V_91 ) ;
if ( V_22 -> V_89 == NULL ) {
F_30 ( V_53 , L_3 ) ;
return - V_92 ;
}
V_22 -> V_93 = ( V_22 -> V_90 + V_22 -> V_17 ) & V_85 ;
V_22 -> V_22 = V_22 -> V_89 + ( V_22 -> V_93 - V_22 -> V_90 ) ;
F_3 ( 0 , V_2 -> V_86 + V_82 + 4 ) ;
F_3 ( V_22 -> V_93 , V_2 -> V_86 + V_82 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_55 = 0 ;
V_2 -> V_76 = V_2 -> V_21 . V_17 / sizeof( struct V_15 ) ;
V_2 -> V_27 = (struct V_15 * ) V_2 -> V_21 . V_22 ;
V_2 -> V_28 = 0 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_76 ; V_55 ++ )
V_2 -> V_27 [ V_55 ] . V_18 . V_24 = F_43 ( V_25 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
int V_55 ;
V_2 -> V_45 = V_2 -> V_33 . V_17 / sizeof( struct V_29 ) ;
V_2 -> V_35 = (struct V_29 * ) V_2 -> V_33 . V_22 ;
V_2 -> V_36 = 0 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_45 ; V_55 ++ ) {
struct V_29 * V_16 = & V_2 -> V_35 [ V_55 ] ;
T_1 V_94 ;
if ( V_55 != V_2 -> V_45 - 1 )
V_94 = ( V_20 * ) ( V_16 + 1 ) - V_2 -> V_33 . V_22 ;
else
V_94 = 0 ;
V_94 |= V_95 ;
V_16 -> V_18 . V_94 = F_43 ( V_94 ) ;
V_16 -> V_18 . V_30 = 0 ;
F_15 ( V_2 , V_16 ) ;
}
}
static int F_45 ( struct V_73 * V_26 )
{
struct V_1 * V_2 = F_33 ( V_26 ) ;
struct V_52 * V_53 = F_22 ( V_2 ) ;
int V_96 = 0 ;
F_1 ( V_2 ) ;
V_96 = F_39 ( V_2 , & V_2 -> V_33 , V_2 -> V_65 ,
V_97 * sizeof( struct V_29 ) ) ;
if ( V_96 ) {
F_30 ( V_53 , L_4 ) ;
goto V_98;
}
F_44 ( V_2 ) ;
V_96 = F_39 ( V_2 , & V_2 -> V_21 , V_2 -> V_63 ,
V_97 * sizeof( struct V_15 ) ) ;
if ( V_96 ) {
F_30 ( V_53 , L_5 ) ;
goto V_99;
}
F_2 ( 0 , V_2 -> V_69 + V_100 ) ;
F_42 ( V_2 ) ;
F_46 ( V_26 ) ;
F_47 ( & V_2 -> V_47 , V_101 , V_102 ) ;
V_2 -> V_47 . V_103 = F_23 ;
F_48 ( & V_2 -> V_47 , V_50 , V_102 ) ;
return 0 ;
V_99:
F_49 ( V_53 , V_2 -> V_33 . V_88 , V_2 -> V_33 . V_89 ,
V_2 -> V_33 . V_88 ) ;
V_98:
return V_96 ;
}
static int F_50 ( struct V_73 * V_26 )
{
struct V_1 * V_2 = F_33 ( V_26 ) ;
struct V_52 * V_53 = F_22 ( V_2 ) ;
F_51 ( & V_2 -> V_47 ) ;
F_1 ( V_2 ) ;
F_52 ( V_26 ) ;
F_49 ( V_53 , V_2 -> V_21 . V_88 ,
V_2 -> V_21 . V_89 , V_2 -> V_21 . V_90 ) ;
F_49 ( V_53 , V_2 -> V_33 . V_88 ,
V_2 -> V_33 . V_89 , V_2 -> V_33 . V_90 ) ;
return 0 ;
}
static void
F_53 ( struct V_73 * V_26 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_33 ( V_26 ) ;
V_105 -> V_106 = F_28 ( V_2 -> V_3 + V_5 ) +
F_28 ( V_2 -> V_3 + V_6 ) +
F_28 ( V_2 -> V_3 + V_4 ) ;
V_105 -> V_107 = F_31 ( V_2 -> V_3 + V_9 ) ;
V_105 -> V_108 = F_31 ( V_2 -> V_3 + V_8 ) ;
V_105 -> V_109 = F_28 ( V_2 -> V_3 + V_10 ) ;
V_105 -> V_110 = V_2 -> V_77 ;
V_105 -> V_111 = V_2 -> V_44 ;
}
static int F_54 ( struct V_112 * V_53 , const struct V_113 * V_114 )
{
struct V_73 * V_26 ;
struct V_1 * V_2 ;
void T_2 * V_86 ;
void T_2 * V_57 ;
int V_96 = 0 ;
V_96 = F_55 ( V_53 ) ;
if ( V_96 )
return V_96 ;
F_56 ( V_53 ) ;
V_96 = F_57 ( V_53 , F_58 ( 32 ) ) ;
if ( V_96 ) {
F_30 ( & V_53 -> V_53 ,
L_6 ) ;
V_96 = - V_115 ;
goto V_116;
}
V_96 = F_59 ( V_53 , F_58 ( 32 ) ) ;
if ( V_96 ) {
F_30 ( & V_53 -> V_53 ,
L_6 ) ;
goto V_116;
}
V_96 = F_60 ( V_53 , L_7 ) ;
if ( V_96 ) {
F_30 ( & V_53 -> V_53 , L_8 ) ;
goto V_116;
}
V_57 = F_61 ( V_53 , 0 , 0 ) ;
if ( ! V_57 ) {
F_30 ( & V_53 -> V_53 , L_9 ) ;
V_96 = - V_115 ;
goto V_117;
}
V_86 = F_61 ( V_53 , 2 , 0 ) ;
if ( ! V_86 ) {
F_30 ( & V_53 -> V_53 , L_10 ) ;
V_96 = - V_115 ;
goto V_118;
}
V_26 = F_62 ( sizeof( struct V_1 ) ) ;
if ( V_26 == NULL ) {
V_96 = - V_92 ;
goto V_119;
}
F_63 ( V_53 , V_26 ) ;
F_64 ( V_26 , & V_53 -> V_53 ) ;
V_26 -> V_120 = 0 ;
V_26 -> V_121 |= V_122 ;
V_26 -> V_123 = & V_124 ;
V_2 = F_33 ( V_26 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_86 = V_86 ;
V_2 -> V_53 = V_53 ;
V_96 = F_27 ( V_2 ) ;
if ( V_96 < 0 )
goto V_125;
F_65 ( V_26 -> V_126 , V_2 -> V_69 + V_127 , 6 ) ;
V_96 = F_66 ( V_26 ) ;
if ( V_96 < 0 )
goto V_125;
return 0 ;
V_125:
F_67 ( V_26 ) ;
V_119:
F_68 ( V_53 , V_86 ) ;
V_118:
F_68 ( V_53 , V_57 ) ;
V_117:
F_69 ( V_53 ) ;
V_116:
F_70 ( V_53 ) ;
F_71 ( V_53 ) ;
return V_96 ;
}
static void F_72 ( struct V_112 * V_53 )
{
struct V_73 * V_26 = F_73 ( V_53 ) ;
struct V_1 * V_2 = F_33 ( V_26 ) ;
F_74 ( V_26 ) ;
F_67 ( V_26 ) ;
F_68 ( V_53 , V_2 -> V_86 ) ;
F_68 ( V_53 , V_2 -> V_57 ) ;
F_69 ( V_53 ) ;
F_70 ( V_53 ) ;
F_71 ( V_53 ) ;
}
