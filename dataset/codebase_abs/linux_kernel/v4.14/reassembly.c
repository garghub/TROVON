static T_1 F_1 ( const struct V_1 * V_2 )
{
return 1 << ( F_2 ( V_2 ) & V_3 ) ;
}
static unsigned int F_3 ( T_2 V_4 , const struct V_5 * V_6 ,
const struct V_5 * V_7 )
{
F_4 ( & V_8 . V_9 , sizeof( V_8 . V_9 ) ) ;
return F_5 ( F_6 ( V_6 ) , F_6 ( V_7 ) ,
( V_10 V_11 ) V_4 , V_8 . V_9 ) ;
}
static unsigned int F_7 ( const struct V_12 * V_13 )
{
const struct V_14 * V_15 ;
V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
return F_3 ( V_15 -> V_4 , & V_15 -> V_6 , & V_15 -> V_7 ) ;
}
bool F_9 ( const struct V_12 * V_13 , const void * V_16 )
{
const struct V_14 * V_15 ;
const struct V_17 * V_18 = V_16 ;
V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
return V_15 -> V_4 == V_18 -> V_4 &&
V_15 -> V_19 == V_18 -> V_19 &&
F_10 ( & V_15 -> V_6 , V_18 -> V_20 ) &&
F_10 ( & V_15 -> V_7 , V_18 -> V_21 ) &&
( V_18 -> V_22 == V_15 -> V_22 ||
! ( F_11 ( V_18 -> V_21 ) & ( V_23 |
V_24 ) ) ) ;
}
void F_12 ( struct V_12 * V_13 , const void * V_16 )
{
struct V_14 * V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
const struct V_17 * V_18 = V_16 ;
V_15 -> V_4 = V_18 -> V_4 ;
V_15 -> V_19 = V_18 -> V_19 ;
V_15 -> V_6 = * V_18 -> V_20 ;
V_15 -> V_7 = * V_18 -> V_21 ;
V_15 -> V_25 = V_18 -> V_25 ;
}
void F_13 ( struct V_26 * V_26 , struct V_14 * V_15 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = NULL ;
F_14 ( & V_15 -> V_13 . V_31 ) ;
if ( V_15 -> V_13 . V_32 & V_33 )
goto V_34;
F_15 ( & V_15 -> V_13 , V_28 ) ;
F_16 () ;
V_30 = F_17 ( V_26 , V_15 -> V_22 ) ;
if ( ! V_30 )
goto V_35;
F_18 ( V_26 , F_19 ( V_30 ) , V_36 ) ;
if ( F_20 ( & V_15 -> V_13 ) )
goto V_35;
F_18 ( V_26 , F_19 ( V_30 ) , V_37 ) ;
if ( ! ( V_15 -> V_13 . V_32 & V_38 ) || ! V_15 -> V_13 . V_39 )
goto V_35;
V_15 -> V_13 . V_39 -> V_30 = V_30 ;
F_21 ( V_15 -> V_13 . V_39 , V_40 , V_41 , 0 ) ;
V_35:
F_22 () ;
V_34:
F_23 ( & V_15 -> V_13 . V_31 ) ;
F_24 ( & V_15 -> V_13 , V_28 ) ;
}
static void F_25 ( unsigned long V_42 )
{
struct V_14 * V_15 ;
struct V_26 * V_26 ;
V_15 = F_8 ( (struct V_12 * ) V_42 , struct V_14 , V_13 ) ;
V_26 = F_8 ( V_15 -> V_13 . V_26 , struct V_26 , V_43 . V_28 ) ;
F_13 ( V_26 , V_15 , & V_8 ) ;
}
static struct V_14 *
F_26 ( struct V_26 * V_26 , T_2 V_4 , const struct V_5 * V_20 ,
const struct V_5 * V_21 , int V_22 , T_1 V_25 )
{
struct V_12 * V_13 ;
struct V_17 V_18 ;
unsigned int V_44 ;
V_18 . V_4 = V_4 ;
V_18 . V_19 = V_45 ;
V_18 . V_20 = V_20 ;
V_18 . V_21 = V_21 ;
V_18 . V_22 = V_22 ;
V_18 . V_25 = V_25 ;
V_44 = F_3 ( V_4 , V_20 , V_21 ) ;
V_13 = F_27 ( & V_26 -> V_43 . V_28 , & V_8 , & V_18 , V_44 ) ;
if ( F_28 ( V_13 ) ) {
F_29 ( V_13 , F_30 () ) ;
return NULL ;
}
return F_8 ( V_13 , struct V_14 , V_13 ) ;
}
static int F_31 ( struct V_14 * V_15 , struct V_46 * V_47 ,
struct V_48 * V_49 , int V_50 )
{
struct V_46 * V_51 , * V_52 ;
struct V_29 * V_30 ;
int V_53 , V_54 , V_55 ;
struct V_26 * V_26 = F_32 ( F_33 ( V_47 ) -> V_30 ) ;
T_1 V_25 ;
if ( V_15 -> V_13 . V_32 & V_33 )
goto V_56;
V_53 = F_34 ( V_49 -> V_57 ) & ~ 0x7 ;
V_54 = V_53 + ( F_34 ( F_35 ( V_47 ) -> V_58 ) -
( ( T_1 * ) ( V_49 + 1 ) - ( T_1 * ) ( F_35 ( V_47 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_54 > V_59 ) {
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_60 ) ;
F_37 ( V_47 , V_61 ,
( ( T_1 * ) & V_49 -> V_57 -
F_38 ( V_47 ) ) ) ;
return - 1 ;
}
V_25 = F_1 ( F_35 ( V_47 ) ) ;
if ( V_47 -> V_62 == V_63 ) {
const unsigned char * V_64 = F_38 ( V_47 ) ;
V_47 -> V_65 = F_39 ( V_47 -> V_65 ,
F_40 ( V_64 , ( T_1 * ) ( V_49 + 1 ) - V_64 ,
0 ) ) ;
}
if ( ! ( V_49 -> V_57 & F_41 ( V_66 ) ) ) {
if ( V_54 < V_15 -> V_13 . V_67 ||
( ( V_15 -> V_13 . V_32 & V_68 ) && V_54 != V_15 -> V_13 . V_67 ) )
goto V_56;
V_15 -> V_13 . V_32 |= V_68 ;
V_15 -> V_13 . V_67 = V_54 ;
} else {
if ( V_54 & 0x7 ) {
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_60 ) ;
F_37 ( V_47 , V_61 ,
F_42 ( struct V_1 , V_58 ) ) ;
return - 1 ;
}
if ( V_54 > V_15 -> V_13 . V_67 ) {
if ( V_15 -> V_13 . V_32 & V_68 )
goto V_56;
V_15 -> V_13 . V_67 = V_54 ;
}
}
if ( V_54 == V_53 )
goto V_56;
if ( ! F_43 ( V_47 , ( T_1 * ) ( V_49 + 1 ) - V_47 -> V_42 ) )
goto V_56;
if ( F_44 ( V_47 , V_54 - V_53 ) )
goto V_56;
V_51 = V_15 -> V_13 . V_69 ;
if ( ! V_51 || F_45 ( V_51 ) -> V_53 < V_53 ) {
V_52 = NULL ;
goto V_70;
}
V_51 = NULL ;
for ( V_52 = V_15 -> V_13 . V_39 ; V_52 != NULL ; V_52 = V_52 -> V_52 ) {
if ( F_45 ( V_52 ) -> V_53 >= V_53 )
break;
V_51 = V_52 ;
}
V_70:
if ( V_51 &&
( F_45 ( V_51 ) -> V_53 + V_51 -> V_67 ) > V_53 )
goto V_71;
if ( V_52 && F_45 ( V_52 ) -> V_53 < V_54 )
goto V_71;
F_45 ( V_47 ) -> V_53 = V_53 ;
V_47 -> V_52 = V_52 ;
if ( ! V_52 )
V_15 -> V_13 . V_69 = V_47 ;
if ( V_51 )
V_51 -> V_52 = V_47 ;
else
V_15 -> V_13 . V_39 = V_47 ;
V_30 = V_47 -> V_30 ;
if ( V_30 ) {
V_15 -> V_22 = V_30 -> V_72 ;
V_47 -> V_30 = NULL ;
}
V_15 -> V_13 . V_73 = V_47 -> V_74 ;
V_15 -> V_13 . V_75 += V_47 -> V_67 ;
V_15 -> V_25 |= V_25 ;
F_46 ( V_15 -> V_13 . V_26 , V_47 -> V_76 ) ;
V_55 = - F_47 ( V_47 ) + V_47 -> V_67 ;
if ( V_55 > V_15 -> V_13 . V_77 )
V_15 -> V_13 . V_77 = V_55 ;
if ( V_53 == 0 ) {
V_15 -> V_78 = V_50 ;
V_15 -> V_13 . V_32 |= V_38 ;
}
if ( V_15 -> V_13 . V_32 == ( V_38 | V_68 ) &&
V_15 -> V_13 . V_75 == V_15 -> V_13 . V_67 ) {
int V_79 ;
unsigned long V_80 = V_47 -> V_81 ;
V_47 -> V_81 = 0UL ;
V_79 = F_48 ( V_15 , V_51 , V_30 ) ;
V_47 -> V_81 = V_80 ;
return V_79 ;
}
F_49 ( V_47 ) ;
return - 1 ;
V_71:
F_15 ( & V_15 -> V_13 , & V_8 ) ;
V_56:
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_36 ) ;
F_50 ( V_47 ) ;
return - 1 ;
}
static int F_48 ( struct V_14 * V_15 , struct V_46 * V_51 ,
struct V_29 * V_30 )
{
struct V_26 * V_26 = F_8 ( V_15 -> V_13 . V_26 , struct V_26 , V_43 . V_28 ) ;
struct V_46 * V_82 , * V_83 = V_15 -> V_13 . V_39 ;
int V_58 ;
unsigned int V_50 ;
int V_84 ;
T_1 V_25 ;
F_15 ( & V_15 -> V_13 , & V_8 ) ;
V_25 = V_85 [ V_15 -> V_25 ] ;
if ( F_51 ( V_25 == 0xff ) )
goto V_86;
if ( V_51 ) {
V_83 = V_51 -> V_52 ;
V_82 = F_52 ( V_83 , V_87 ) ;
if ( ! V_82 )
goto V_88;
V_82 -> V_52 = V_83 -> V_52 ;
if ( ! V_82 -> V_52 )
V_15 -> V_13 . V_69 = V_82 ;
V_51 -> V_52 = V_82 ;
F_53 ( V_83 , V_15 -> V_13 . V_39 ) ;
V_83 -> V_52 = V_15 -> V_13 . V_39 -> V_52 ;
F_54 ( V_15 -> V_13 . V_39 ) ;
V_15 -> V_13 . V_39 = V_83 ;
}
F_55 ( V_83 == NULL ) ;
F_55 ( F_45 ( V_83 ) -> V_53 != 0 ) ;
V_58 = ( ( V_83 -> V_42 - F_38 ( V_83 ) ) -
sizeof( struct V_1 ) + V_15 -> V_13 . V_67 -
sizeof( struct V_48 ) ) ;
if ( V_58 > V_59 )
goto V_89;
if ( F_56 ( V_83 , V_87 ) )
goto V_88;
if ( F_57 ( V_83 ) ) {
struct V_46 * V_90 ;
int V_91 , V_92 = 0 ;
V_90 = F_58 ( 0 , V_87 ) ;
if ( ! V_90 )
goto V_88;
V_90 -> V_52 = V_83 -> V_52 ;
V_83 -> V_52 = V_90 ;
F_59 ( V_90 ) -> V_93 = F_59 ( V_83 ) -> V_93 ;
F_60 ( V_83 ) ;
for ( V_91 = 0 ; V_91 < F_59 ( V_83 ) -> V_94 ; V_91 ++ )
V_92 += F_61 ( & F_59 ( V_83 ) -> V_28 [ V_91 ] ) ;
V_90 -> V_67 = V_90 -> V_95 = V_83 -> V_95 - V_92 ;
V_83 -> V_95 -= V_90 -> V_67 ;
V_83 -> V_67 -= V_90 -> V_67 ;
V_90 -> V_65 = 0 ;
V_90 -> V_62 = V_83 -> V_62 ;
F_46 ( V_15 -> V_13 . V_26 , V_90 -> V_76 ) ;
}
V_50 = V_15 -> V_78 ;
F_38 ( V_83 ) [ V_50 ] = F_62 ( V_83 ) [ 0 ] ;
memmove ( V_83 -> V_83 + sizeof( struct V_48 ) , V_83 -> V_83 ,
( V_83 -> V_42 - V_83 -> V_83 ) - sizeof( struct V_48 ) ) ;
if ( F_63 ( V_83 ) )
V_83 -> V_96 += sizeof( struct V_48 ) ;
V_83 -> V_97 += sizeof( struct V_48 ) ;
F_64 ( V_83 ) ;
F_65 ( V_83 , V_83 -> V_42 - F_38 ( V_83 ) ) ;
V_84 = V_83 -> V_76 ;
for ( V_82 = V_83 -> V_52 ; V_82 ; ) {
bool V_98 ;
int V_99 ;
struct V_46 * V_52 = V_82 -> V_52 ;
V_84 += V_82 -> V_76 ;
if ( V_83 -> V_62 != V_82 -> V_62 )
V_83 -> V_62 = V_100 ;
else if ( V_83 -> V_62 == V_63 )
V_83 -> V_65 = F_66 ( V_83 -> V_65 , V_82 -> V_65 ) ;
if ( F_67 ( V_83 , V_82 , & V_98 , & V_99 ) ) {
F_68 ( V_82 , V_98 ) ;
} else {
if ( ! F_59 ( V_83 ) -> V_93 )
F_59 ( V_83 ) -> V_93 = V_82 ;
V_83 -> V_95 += V_82 -> V_67 ;
V_83 -> V_67 += V_82 -> V_67 ;
V_83 -> V_76 += V_82 -> V_76 ;
}
V_82 = V_52 ;
}
F_69 ( V_15 -> V_13 . V_26 , V_84 ) ;
V_83 -> V_52 = NULL ;
V_83 -> V_30 = V_30 ;
V_83 -> V_74 = V_15 -> V_13 . V_73 ;
F_35 ( V_83 ) -> V_58 = F_41 ( V_58 ) ;
F_70 ( F_35 ( V_83 ) , 0xff , V_25 ) ;
F_71 ( V_83 ) -> V_50 = V_50 ;
F_71 ( V_83 ) -> V_32 |= V_101 ;
F_71 ( V_83 ) -> V_102 = V_15 -> V_13 . V_77 ;
F_72 ( V_83 , F_38 ( V_83 ) ,
F_73 ( V_83 ) ) ;
F_16 () ;
F_18 ( V_26 , F_19 ( V_30 ) , V_103 ) ;
F_22 () ;
V_15 -> V_13 . V_39 = NULL ;
V_15 -> V_13 . V_69 = NULL ;
return 1 ;
V_89:
F_74 ( L_1 , V_58 ) ;
goto V_86;
V_88:
F_74 ( L_2 ) ;
V_86:
F_16 () ;
F_18 ( V_26 , F_19 ( V_30 ) , V_36 ) ;
F_22 () ;
return - 1 ;
}
static int F_75 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_14 * V_15 ;
const struct V_1 * V_104 = F_35 ( V_47 ) ;
struct V_26 * V_26 = F_32 ( F_33 ( V_47 ) -> V_30 ) ;
if ( F_71 ( V_47 ) -> V_32 & V_101 )
goto V_105;
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) , V_106 ) ;
if ( V_104 -> V_58 == 0 )
goto V_105;
if ( ! F_76 ( V_47 , ( F_77 ( V_47 ) +
sizeof( struct V_48 ) ) ) )
goto V_105;
V_104 = F_35 ( V_47 ) ;
V_49 = (struct V_48 * ) F_62 ( V_47 ) ;
if ( ! ( V_49 -> V_57 & F_41 ( 0xFFF9 ) ) ) {
V_47 -> V_107 += sizeof( struct V_48 ) ;
F_18 ( V_26 ,
F_36 ( F_33 ( V_47 ) ) , V_103 ) ;
F_71 ( V_47 ) -> V_50 = ( T_1 * ) V_49 - F_38 ( V_47 ) ;
F_71 ( V_47 ) -> V_32 |= V_101 ;
return 1 ;
}
V_15 = F_26 ( V_26 , V_49 -> V_108 , & V_104 -> V_6 , & V_104 -> V_7 ,
V_47 -> V_30 ? V_47 -> V_30 -> V_72 : 0 , F_1 ( V_104 ) ) ;
if ( V_15 ) {
int V_109 ;
F_14 ( & V_15 -> V_13 . V_31 ) ;
V_109 = F_31 ( V_15 , V_47 , V_49 , F_71 ( V_47 ) -> V_50 ) ;
F_23 ( & V_15 -> V_13 . V_31 ) ;
F_24 ( & V_15 -> V_13 , & V_8 ) ;
return V_109 ;
}
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) , V_36 ) ;
F_50 ( V_47 ) ;
return - 1 ;
V_105:
F_18 ( V_26 , F_36 ( F_33 ( V_47 ) ) ,
V_60 ) ;
F_37 ( V_47 , V_61 , F_73 ( V_47 ) ) ;
return - 1 ;
}
static int T_3 F_78 ( struct V_26 * V_26 )
{
struct V_110 * V_111 ;
struct V_112 * V_104 ;
V_111 = V_113 ;
if ( ! F_79 ( V_26 , & V_114 ) ) {
V_111 = F_80 ( V_111 , sizeof( V_113 ) , V_115 ) ;
if ( ! V_111 )
goto V_116;
V_111 [ 0 ] . V_42 = & V_26 -> V_43 . V_28 . V_117 ;
V_111 [ 0 ] . V_118 = & V_26 -> V_43 . V_28 . V_119 ;
V_111 [ 0 ] . V_120 = & V_114 . V_43 . V_28 . V_117 ;
V_111 [ 1 ] . V_42 = & V_26 -> V_43 . V_28 . V_119 ;
V_111 [ 1 ] . V_120 = & V_26 -> V_43 . V_28 . V_117 ;
V_111 [ 2 ] . V_42 = & V_26 -> V_43 . V_28 . V_121 ;
if ( V_26 -> V_122 != & V_123 )
V_111 [ 0 ] . V_124 = NULL ;
}
V_104 = F_81 ( V_26 , L_3 , V_111 ) ;
if ( ! V_104 )
goto V_125;
V_26 -> V_43 . V_126 . V_127 = V_104 ;
return 0 ;
V_125:
if ( ! F_79 ( V_26 , & V_114 ) )
F_82 ( V_111 ) ;
V_116:
return - V_128 ;
}
static void T_4 F_83 ( struct V_26 * V_26 )
{
struct V_110 * V_111 ;
V_111 = V_26 -> V_43 . V_126 . V_127 -> V_129 ;
F_84 ( V_26 -> V_43 . V_126 . V_127 ) ;
if ( ! F_79 ( V_26 , & V_114 ) )
F_82 ( V_111 ) ;
}
static int F_85 ( void )
{
V_130 = F_81 ( & V_114 , L_3 ,
V_131 ) ;
return V_130 == NULL ? - V_128 : 0 ;
}
static void F_86 ( void )
{
F_84 ( V_130 ) ;
}
static int F_78 ( struct V_26 * V_26 )
{
return 0 ;
}
static void F_83 ( struct V_26 * V_26 )
{
}
static int F_85 ( void )
{
return 0 ;
}
static void F_86 ( void )
{
}
static int T_3 F_87 ( struct V_26 * V_26 )
{
V_26 -> V_43 . V_28 . V_117 = V_132 ;
V_26 -> V_43 . V_28 . V_119 = V_133 ;
V_26 -> V_43 . V_28 . V_121 = V_134 ;
F_88 ( & V_26 -> V_43 . V_28 ) ;
return F_78 ( V_26 ) ;
}
static void T_4 F_89 ( struct V_26 * V_26 )
{
F_83 ( V_26 ) ;
F_90 ( & V_26 -> V_43 . V_28 , & V_8 ) ;
}
int T_5 F_91 ( void )
{
int V_109 ;
V_109 = F_92 ( & V_135 , V_136 ) ;
if ( V_109 )
goto V_34;
V_109 = F_85 () ;
if ( V_109 )
goto V_137;
V_109 = F_93 ( & V_138 ) ;
if ( V_109 )
goto V_139;
V_8 . V_140 = F_7 ;
V_8 . V_141 = F_12 ;
V_8 . V_142 = NULL ;
V_8 . V_143 = sizeof( struct V_14 ) ;
V_8 . V_144 = F_9 ;
V_8 . V_145 = F_25 ;
V_8 . V_146 = V_147 ;
V_109 = F_94 ( & V_8 ) ;
if ( V_109 )
goto V_139;
V_34:
return V_109 ;
V_139:
F_86 () ;
V_137:
F_95 ( & V_135 , V_136 ) ;
goto V_34;
}
void F_96 ( void )
{
F_97 ( & V_8 ) ;
F_86 () ;
F_98 ( & V_138 ) ;
F_95 ( & V_135 , V_136 ) ;
}
