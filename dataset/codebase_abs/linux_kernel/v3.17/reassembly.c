static inline T_1 F_1 ( const struct V_1 * V_2 )
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
F_10 ( & V_15 -> V_7 , V_18 -> V_21 ) ;
}
void F_11 ( struct V_12 * V_13 , const void * V_16 )
{
struct V_14 * V_15 = F_8 ( V_13 , struct V_14 , V_13 ) ;
const struct V_17 * V_18 = V_16 ;
V_15 -> V_4 = V_18 -> V_4 ;
V_15 -> V_19 = V_18 -> V_19 ;
V_15 -> V_6 = * V_18 -> V_20 ;
V_15 -> V_7 = * V_18 -> V_21 ;
V_15 -> V_22 = V_18 -> V_22 ;
}
void F_12 ( struct V_23 * V_23 , struct V_14 * V_15 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = NULL ;
F_13 ( & V_15 -> V_13 . V_28 ) ;
if ( V_15 -> V_13 . V_29 & V_30 )
goto V_31;
F_14 ( & V_15 -> V_13 , V_25 ) ;
F_15 () ;
V_27 = F_16 ( V_23 , V_15 -> V_32 ) ;
if ( ! V_27 )
goto V_33;
F_17 ( V_23 , F_18 ( V_27 ) , V_34 ) ;
if ( V_15 -> V_13 . V_29 & V_35 )
goto V_33;
F_17 ( V_23 , F_18 ( V_27 ) , V_36 ) ;
if ( ! ( V_15 -> V_13 . V_29 & V_37 ) || ! V_15 -> V_13 . V_38 )
goto V_33;
V_15 -> V_13 . V_38 -> V_27 = V_27 ;
F_19 ( V_15 -> V_13 . V_38 , V_39 , V_40 , 0 ) ;
V_33:
F_20 () ;
V_31:
F_21 ( & V_15 -> V_13 . V_28 ) ;
F_22 ( & V_15 -> V_13 , V_25 ) ;
}
static void F_23 ( unsigned long V_41 )
{
struct V_14 * V_15 ;
struct V_23 * V_23 ;
V_15 = F_8 ( (struct V_12 * ) V_41 , struct V_14 , V_13 ) ;
V_23 = F_8 ( V_15 -> V_13 . V_23 , struct V_23 , V_42 . V_25 ) ;
F_12 ( V_23 , V_15 , & V_8 ) ;
}
int F_24 ( struct V_14 * V_15 , struct V_43 * V_44 ,
struct V_45 * V_46 , int V_47 )
{
struct V_43 * V_48 , * V_49 ;
struct V_26 * V_27 ;
int V_50 , V_51 ;
struct V_23 * V_23 = F_25 ( F_26 ( V_44 ) -> V_27 ) ;
T_1 V_22 ;
if ( V_15 -> V_13 . V_29 & V_30 )
goto V_52;
V_50 = F_27 ( V_46 -> V_53 ) & ~ 0x7 ;
V_51 = V_50 + ( F_27 ( F_28 ( V_44 ) -> V_54 ) -
( ( T_1 * ) ( V_46 + 1 ) - ( T_1 * ) ( F_28 ( V_44 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_51 > V_55 ) {
F_17 ( V_23 , F_29 ( F_26 ( V_44 ) ) ,
V_56 ) ;
F_30 ( V_44 , V_57 ,
( ( T_1 * ) & V_46 -> V_53 -
F_31 ( V_44 ) ) ) ;
return - 1 ;
}
V_22 = F_1 ( F_28 ( V_44 ) ) ;
if ( V_44 -> V_58 == V_59 ) {
const unsigned char * V_60 = F_31 ( V_44 ) ;
V_44 -> V_61 = F_32 ( V_44 -> V_61 ,
F_33 ( V_60 , ( T_1 * ) ( V_46 + 1 ) - V_60 ,
0 ) ) ;
}
if ( ! ( V_46 -> V_53 & F_34 ( V_62 ) ) ) {
if ( V_51 < V_15 -> V_13 . V_63 ||
( ( V_15 -> V_13 . V_29 & V_64 ) && V_51 != V_15 -> V_13 . V_63 ) )
goto V_52;
V_15 -> V_13 . V_29 |= V_64 ;
V_15 -> V_13 . V_63 = V_51 ;
} else {
if ( V_51 & 0x7 ) {
F_17 ( V_23 , F_29 ( F_26 ( V_44 ) ) ,
V_56 ) ;
F_30 ( V_44 , V_57 ,
F_35 ( struct V_1 , V_54 ) ) ;
return - 1 ;
}
if ( V_51 > V_15 -> V_13 . V_63 ) {
if ( V_15 -> V_13 . V_29 & V_64 )
goto V_52;
V_15 -> V_13 . V_63 = V_51 ;
}
}
if ( V_51 == V_50 )
goto V_52;
if ( ! F_36 ( V_44 , ( T_1 * ) ( V_46 + 1 ) - V_44 -> V_41 ) )
goto V_52;
if ( F_37 ( V_44 , V_51 - V_50 ) )
goto V_52;
V_48 = V_15 -> V_13 . V_65 ;
if ( ! V_48 || F_38 ( V_48 ) -> V_50 < V_50 ) {
V_49 = NULL ;
goto V_66;
}
V_48 = NULL ;
for( V_49 = V_15 -> V_13 . V_38 ; V_49 != NULL ; V_49 = V_49 -> V_49 ) {
if ( F_38 ( V_49 ) -> V_50 >= V_50 )
break;
V_48 = V_49 ;
}
V_66:
if ( V_48 &&
( F_38 ( V_48 ) -> V_50 + V_48 -> V_63 ) > V_50 )
goto V_67;
if ( V_49 && F_38 ( V_49 ) -> V_50 < V_51 )
goto V_67;
F_38 ( V_44 ) -> V_50 = V_50 ;
V_44 -> V_49 = V_49 ;
if ( ! V_49 )
V_15 -> V_13 . V_65 = V_44 ;
if ( V_48 )
V_48 -> V_49 = V_44 ;
else
V_15 -> V_13 . V_38 = V_44 ;
V_27 = V_44 -> V_27 ;
if ( V_27 ) {
V_15 -> V_32 = V_27 -> V_68 ;
V_44 -> V_27 = NULL ;
}
V_15 -> V_13 . V_69 = V_44 -> V_70 ;
V_15 -> V_13 . V_71 += V_44 -> V_63 ;
V_15 -> V_22 |= V_22 ;
F_39 ( & V_15 -> V_13 , V_44 -> V_72 ) ;
if ( V_50 == 0 ) {
V_15 -> V_73 = V_47 ;
V_15 -> V_13 . V_29 |= V_37 ;
}
if ( V_15 -> V_13 . V_29 == ( V_37 | V_64 ) &&
V_15 -> V_13 . V_71 == V_15 -> V_13 . V_63 ) {
int V_74 ;
unsigned long V_75 = V_44 -> V_76 ;
V_44 -> V_76 = 0UL ;
V_74 = F_40 ( V_15 , V_48 , V_27 ) ;
V_44 -> V_76 = V_75 ;
return V_74 ;
}
F_41 ( V_44 ) ;
return - 1 ;
V_67:
F_14 ( & V_15 -> V_13 , & V_8 ) ;
V_52:
F_17 ( V_23 , F_29 ( F_26 ( V_44 ) ) ,
V_34 ) ;
F_42 ( V_44 ) ;
return - 1 ;
}
static int F_40 ( struct V_14 * V_15 , struct V_43 * V_48 ,
struct V_26 * V_27 )
{
struct V_23 * V_23 = F_8 ( V_15 -> V_13 . V_23 , struct V_23 , V_42 . V_25 ) ;
struct V_43 * V_77 , * V_78 = V_15 -> V_13 . V_38 ;
int V_54 ;
unsigned int V_47 ;
int V_79 ;
T_1 V_22 ;
F_14 ( & V_15 -> V_13 , & V_8 ) ;
V_22 = V_80 [ V_15 -> V_22 ] ;
if ( F_43 ( V_22 == 0xff ) )
goto V_81;
if ( V_48 ) {
V_78 = V_48 -> V_49 ;
V_77 = F_44 ( V_78 , V_82 ) ;
if ( ! V_77 )
goto V_83;
V_77 -> V_49 = V_78 -> V_49 ;
if ( ! V_77 -> V_49 )
V_15 -> V_13 . V_65 = V_77 ;
V_48 -> V_49 = V_77 ;
F_45 ( V_78 , V_15 -> V_13 . V_38 ) ;
V_78 -> V_49 = V_15 -> V_13 . V_38 -> V_49 ;
F_46 ( V_15 -> V_13 . V_38 ) ;
V_15 -> V_13 . V_38 = V_78 ;
}
F_47 ( V_78 == NULL ) ;
F_47 ( F_38 ( V_78 ) -> V_50 != 0 ) ;
V_54 = ( ( V_78 -> V_41 - F_31 ( V_78 ) ) -
sizeof( struct V_1 ) + V_15 -> V_13 . V_63 -
sizeof( struct V_45 ) ) ;
if ( V_54 > V_55 )
goto V_84;
if ( F_48 ( V_78 , V_82 ) )
goto V_83;
if ( F_49 ( V_78 ) ) {
struct V_43 * V_85 ;
int V_86 , V_87 = 0 ;
if ( ( V_85 = F_50 ( 0 , V_82 ) ) == NULL )
goto V_83;
V_85 -> V_49 = V_78 -> V_49 ;
V_78 -> V_49 = V_85 ;
F_51 ( V_85 ) -> V_88 = F_51 ( V_78 ) -> V_88 ;
F_52 ( V_78 ) ;
for ( V_86 = 0 ; V_86 < F_51 ( V_78 ) -> V_89 ; V_86 ++ )
V_87 += F_53 ( & F_51 ( V_78 ) -> V_25 [ V_86 ] ) ;
V_85 -> V_63 = V_85 -> V_90 = V_78 -> V_90 - V_87 ;
V_78 -> V_90 -= V_85 -> V_63 ;
V_78 -> V_63 -= V_85 -> V_63 ;
V_85 -> V_61 = 0 ;
V_85 -> V_58 = V_78 -> V_58 ;
F_39 ( & V_15 -> V_13 , V_85 -> V_72 ) ;
}
V_47 = V_15 -> V_73 ;
F_31 ( V_78 ) [ V_47 ] = F_54 ( V_78 ) [ 0 ] ;
memmove ( V_78 -> V_78 + sizeof( struct V_45 ) , V_78 -> V_78 ,
( V_78 -> V_41 - V_78 -> V_78 ) - sizeof( struct V_45 ) ) ;
V_78 -> V_91 += sizeof( struct V_45 ) ;
V_78 -> V_92 += sizeof( struct V_45 ) ;
F_55 ( V_78 ) ;
F_56 ( V_78 , V_78 -> V_41 - F_31 ( V_78 ) ) ;
V_79 = V_78 -> V_72 ;
for ( V_77 = V_78 -> V_49 ; V_77 ; ) {
bool V_93 ;
int V_94 ;
struct V_43 * V_49 = V_77 -> V_49 ;
V_79 += V_77 -> V_72 ;
if ( V_78 -> V_58 != V_77 -> V_58 )
V_78 -> V_58 = V_95 ;
else if ( V_78 -> V_58 == V_59 )
V_78 -> V_61 = F_57 ( V_78 -> V_61 , V_77 -> V_61 ) ;
if ( F_58 ( V_78 , V_77 , & V_93 , & V_94 ) ) {
F_59 ( V_77 , V_93 ) ;
} else {
if ( ! F_51 ( V_78 ) -> V_88 )
F_51 ( V_78 ) -> V_88 = V_77 ;
V_78 -> V_90 += V_77 -> V_63 ;
V_78 -> V_63 += V_77 -> V_63 ;
V_78 -> V_72 += V_77 -> V_72 ;
}
V_77 = V_49 ;
}
F_60 ( & V_15 -> V_13 , V_79 ) ;
V_78 -> V_49 = NULL ;
V_78 -> V_27 = V_27 ;
V_78 -> V_70 = V_15 -> V_13 . V_69 ;
F_28 ( V_78 ) -> V_54 = F_34 ( V_54 ) ;
F_61 ( F_28 ( V_78 ) , 0xff , V_22 ) ;
F_62 ( V_78 ) -> V_47 = V_47 ;
F_62 ( V_78 ) -> V_29 |= V_96 ;
if ( V_78 -> V_58 == V_59 )
V_78 -> V_61 = F_33 ( F_31 ( V_78 ) ,
F_63 ( V_78 ) ,
V_78 -> V_61 ) ;
F_15 () ;
F_17 ( V_23 , F_18 ( V_27 ) , V_97 ) ;
F_20 () ;
V_15 -> V_13 . V_38 = NULL ;
V_15 -> V_13 . V_65 = NULL ;
return 1 ;
V_84:
F_64 ( L_1 , V_54 ) ;
goto V_81;
V_83:
F_64 ( L_2 ) ;
V_81:
F_15 () ;
F_17 ( V_23 , F_18 ( V_27 ) , V_34 ) ;
F_20 () ;
return - 1 ;
}
static int F_65 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_14 * V_15 ;
const struct V_1 * V_98 = F_28 ( V_44 ) ;
struct V_23 * V_23 = F_25 ( F_26 ( V_44 ) -> V_27 ) ;
if ( F_62 ( V_44 ) -> V_29 & V_96 )
goto V_99;
F_17 ( V_23 , F_29 ( F_26 ( V_44 ) ) , V_100 ) ;
if ( V_98 -> V_54 == 0 )
goto V_99;
if ( ! F_66 ( V_44 , ( F_67 ( V_44 ) +
sizeof( struct V_45 ) ) ) )
goto V_99;
V_98 = F_28 ( V_44 ) ;
V_46 = (struct V_45 * ) F_54 ( V_44 ) ;
if ( ! ( V_46 -> V_53 & F_34 ( 0xFFF9 ) ) ) {
V_44 -> V_101 += sizeof( struct V_45 ) ;
F_17 ( V_23 ,
F_29 ( F_26 ( V_44 ) ) , V_97 ) ;
F_62 ( V_44 ) -> V_47 = ( T_1 * ) V_46 - F_31 ( V_44 ) ;
F_62 ( V_44 ) -> V_29 |= V_96 ;
return 1 ;
}
V_15 = F_68 ( V_23 , V_46 -> V_102 , & V_98 -> V_6 , & V_98 -> V_7 ,
F_1 ( V_98 ) ) ;
if ( V_15 != NULL ) {
int V_103 ;
F_13 ( & V_15 -> V_13 . V_28 ) ;
V_103 = F_24 ( V_15 , V_44 , V_46 , F_62 ( V_44 ) -> V_47 ) ;
F_21 ( & V_15 -> V_13 . V_28 ) ;
F_22 ( & V_15 -> V_13 , & V_8 ) ;
return V_103 ;
}
F_17 ( V_23 , F_29 ( F_26 ( V_44 ) ) , V_34 ) ;
F_42 ( V_44 ) ;
return - 1 ;
V_99:
F_17 ( V_23 , F_29 ( F_26 ( V_44 ) ) ,
V_56 ) ;
F_30 ( V_44 , V_57 , F_63 ( V_44 ) ) ;
return - 1 ;
}
static int T_3 F_69 ( struct V_23 * V_23 )
{
struct V_104 * V_105 ;
struct V_106 * V_98 ;
V_105 = V_107 ;
if ( ! F_70 ( V_23 , & V_108 ) ) {
V_105 = F_71 ( V_105 , sizeof( V_107 ) , V_109 ) ;
if ( V_105 == NULL )
goto V_110;
V_105 [ 0 ] . V_41 = & V_23 -> V_42 . V_25 . V_111 ;
V_105 [ 0 ] . V_112 = & V_23 -> V_42 . V_25 . V_113 ;
V_105 [ 0 ] . V_114 = & V_108 . V_42 . V_25 . V_111 ;
V_105 [ 1 ] . V_41 = & V_23 -> V_42 . V_25 . V_113 ;
V_105 [ 1 ] . V_114 = & V_23 -> V_42 . V_25 . V_111 ;
V_105 [ 2 ] . V_41 = & V_23 -> V_42 . V_25 . V_115 ;
if ( V_23 -> V_116 != & V_117 )
V_105 [ 0 ] . V_118 = NULL ;
}
V_98 = F_72 ( V_23 , L_3 , V_105 ) ;
if ( V_98 == NULL )
goto V_119;
V_23 -> V_42 . V_120 . V_121 = V_98 ;
return 0 ;
V_119:
if ( ! F_70 ( V_23 , & V_108 ) )
F_73 ( V_105 ) ;
V_110:
return - V_122 ;
}
static void T_4 F_74 ( struct V_23 * V_23 )
{
struct V_104 * V_105 ;
V_105 = V_23 -> V_42 . V_120 . V_121 -> V_123 ;
F_75 ( V_23 -> V_42 . V_120 . V_121 ) ;
if ( ! F_70 ( V_23 , & V_108 ) )
F_73 ( V_105 ) ;
}
static int F_76 ( void )
{
V_124 = F_72 ( & V_108 , L_3 ,
V_125 ) ;
return V_124 == NULL ? - V_122 : 0 ;
}
static void F_77 ( void )
{
F_75 ( V_124 ) ;
}
static inline int F_69 ( struct V_23 * V_23 )
{
return 0 ;
}
static inline void F_74 ( struct V_23 * V_23 )
{
}
static inline int F_76 ( void )
{
return 0 ;
}
static inline void F_77 ( void )
{
}
static int T_3 F_78 ( struct V_23 * V_23 )
{
V_23 -> V_42 . V_25 . V_111 = V_126 ;
V_23 -> V_42 . V_25 . V_113 = V_127 ;
V_23 -> V_42 . V_25 . V_115 = V_128 ;
F_79 ( & V_23 -> V_42 . V_25 ) ;
return F_69 ( V_23 ) ;
}
static void T_4 F_80 ( struct V_23 * V_23 )
{
F_74 ( V_23 ) ;
F_81 ( & V_23 -> V_42 . V_25 , & V_8 ) ;
}
int T_5 F_82 ( void )
{
int V_103 ;
V_103 = F_83 ( & V_129 , V_130 ) ;
if ( V_103 )
goto V_31;
V_103 = F_76 () ;
if ( V_103 )
goto V_131;
V_103 = F_84 ( & V_132 ) ;
if ( V_103 )
goto V_133;
V_8 . V_134 = F_7 ;
V_8 . V_135 = F_11 ;
V_8 . V_136 = NULL ;
V_8 . V_137 = NULL ;
V_8 . V_138 = sizeof( struct V_14 ) ;
V_8 . V_139 = F_9 ;
V_8 . V_140 = F_23 ;
V_8 . V_141 = V_142 ;
V_103 = F_85 ( & V_8 ) ;
if ( V_103 )
goto V_133;
V_31:
return V_103 ;
V_133:
F_77 () ;
V_131:
F_86 ( & V_129 , V_130 ) ;
goto V_31;
}
void F_87 ( void )
{
F_88 ( & V_8 ) ;
F_77 () ;
F_89 ( & V_132 ) ;
F_86 ( & V_129 , V_130 ) ;
}
