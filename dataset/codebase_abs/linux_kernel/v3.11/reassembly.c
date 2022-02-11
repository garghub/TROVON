static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return 1 << ( F_2 ( V_2 ) & V_3 ) ;
}
unsigned int F_3 ( T_2 V_4 , const struct V_5 * V_6 ,
const struct V_5 * V_7 , T_3 V_8 )
{
T_3 V_9 ;
V_9 = F_4 ( F_5 ( V_6 ) , F_5 ( V_7 ) ,
( V_10 T_3 ) V_4 , V_8 ) ;
return V_9 & ( V_11 - 1 ) ;
}
static unsigned int F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
V_15 = F_7 ( V_13 , struct V_14 , V_13 ) ;
return F_3 ( V_15 -> V_4 , & V_15 -> V_6 , & V_15 -> V_7 , V_16 . V_8 ) ;
}
bool F_8 ( struct V_12 * V_13 , void * V_17 )
{
struct V_14 * V_15 ;
struct V_18 * V_19 = V_17 ;
V_15 = F_7 ( V_13 , struct V_14 , V_13 ) ;
return V_15 -> V_4 == V_19 -> V_4 &&
V_15 -> V_20 == V_19 -> V_20 &&
F_9 ( & V_15 -> V_6 , V_19 -> V_21 ) &&
F_9 ( & V_15 -> V_7 , V_19 -> V_22 ) ;
}
void F_10 ( struct V_12 * V_13 , void * V_17 )
{
struct V_14 * V_15 = F_7 ( V_13 , struct V_14 , V_13 ) ;
struct V_18 * V_19 = V_17 ;
V_15 -> V_4 = V_19 -> V_4 ;
V_15 -> V_20 = V_19 -> V_20 ;
V_15 -> V_6 = * V_19 -> V_21 ;
V_15 -> V_7 = * V_19 -> V_22 ;
V_15 -> V_23 = V_19 -> V_23 ;
}
void F_11 ( struct V_24 * V_24 , struct V_14 * V_15 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = NULL ;
F_12 ( & V_15 -> V_13 . V_29 ) ;
if ( V_15 -> V_13 . V_30 & V_31 )
goto V_32;
F_13 ( & V_15 -> V_13 , V_26 ) ;
F_14 () ;
V_28 = F_15 ( V_24 , V_15 -> V_33 ) ;
if ( ! V_28 )
goto V_34;
F_16 ( V_24 , F_17 ( V_28 ) , V_35 ) ;
F_16 ( V_24 , F_17 ( V_28 ) , V_36 ) ;
if ( ! ( V_15 -> V_13 . V_30 & V_37 ) || ! V_15 -> V_13 . V_38 )
goto V_34;
V_15 -> V_13 . V_38 -> V_28 = V_28 ;
F_18 ( V_15 -> V_13 . V_38 , V_39 , V_40 , 0 ) ;
V_34:
F_19 () ;
V_32:
F_20 ( & V_15 -> V_13 . V_29 ) ;
F_21 ( & V_15 -> V_13 , V_26 ) ;
}
static void F_22 ( unsigned long V_41 )
{
struct V_14 * V_15 ;
struct V_24 * V_24 ;
V_15 = F_7 ( (struct V_12 * ) V_41 , struct V_14 , V_13 ) ;
V_24 = F_7 ( V_15 -> V_13 . V_24 , struct V_24 , V_42 . V_26 ) ;
F_11 ( V_24 , V_15 , & V_16 ) ;
}
int F_23 ( struct V_14 * V_15 , struct V_43 * V_44 ,
struct V_45 * V_46 , int V_47 )
{
struct V_43 * V_48 , * V_49 ;
struct V_27 * V_28 ;
int V_50 , V_51 ;
struct V_24 * V_24 = F_24 ( F_25 ( V_44 ) -> V_28 ) ;
T_1 V_23 ;
if ( V_15 -> V_13 . V_30 & V_31 )
goto V_52;
V_50 = F_26 ( V_46 -> V_53 ) & ~ 0x7 ;
V_51 = V_50 + ( F_26 ( F_27 ( V_44 ) -> V_54 ) -
( ( T_1 * ) ( V_46 + 1 ) - ( T_1 * ) ( F_27 ( V_44 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_51 > V_55 ) {
F_16 ( V_24 , F_28 ( F_25 ( V_44 ) ) ,
V_56 ) ;
F_29 ( V_44 , V_57 ,
( ( T_1 * ) & V_46 -> V_53 -
F_30 ( V_44 ) ) ) ;
return - 1 ;
}
V_23 = F_1 ( F_27 ( V_44 ) ) ;
if ( V_44 -> V_58 == V_59 ) {
const unsigned char * V_60 = F_30 ( V_44 ) ;
V_44 -> V_61 = F_31 ( V_44 -> V_61 ,
F_32 ( V_60 , ( T_1 * ) ( V_46 + 1 ) - V_60 ,
0 ) ) ;
}
if ( ! ( V_46 -> V_53 & F_33 ( V_62 ) ) ) {
if ( V_51 < V_15 -> V_13 . V_63 ||
( ( V_15 -> V_13 . V_30 & V_64 ) && V_51 != V_15 -> V_13 . V_63 ) )
goto V_52;
V_15 -> V_13 . V_30 |= V_64 ;
V_15 -> V_13 . V_63 = V_51 ;
} else {
if ( V_51 & 0x7 ) {
F_16 ( V_24 , F_28 ( F_25 ( V_44 ) ) ,
V_56 ) ;
F_29 ( V_44 , V_57 ,
F_34 ( struct V_1 , V_54 ) ) ;
return - 1 ;
}
if ( V_51 > V_15 -> V_13 . V_63 ) {
if ( V_15 -> V_13 . V_30 & V_64 )
goto V_52;
V_15 -> V_13 . V_63 = V_51 ;
}
}
if ( V_51 == V_50 )
goto V_52;
if ( ! F_35 ( V_44 , ( T_1 * ) ( V_46 + 1 ) - V_44 -> V_41 ) )
goto V_52;
if ( F_36 ( V_44 , V_51 - V_50 ) )
goto V_52;
V_48 = V_15 -> V_13 . V_65 ;
if ( ! V_48 || F_37 ( V_48 ) -> V_50 < V_50 ) {
V_49 = NULL ;
goto V_66;
}
V_48 = NULL ;
for( V_49 = V_15 -> V_13 . V_38 ; V_49 != NULL ; V_49 = V_49 -> V_49 ) {
if ( F_37 ( V_49 ) -> V_50 >= V_50 )
break;
V_48 = V_49 ;
}
V_66:
if ( V_48 &&
( F_37 ( V_48 ) -> V_50 + V_48 -> V_63 ) > V_50 )
goto V_67;
if ( V_49 && F_37 ( V_49 ) -> V_50 < V_51 )
goto V_67;
F_37 ( V_44 ) -> V_50 = V_50 ;
V_44 -> V_49 = V_49 ;
if ( ! V_49 )
V_15 -> V_13 . V_65 = V_44 ;
if ( V_48 )
V_48 -> V_49 = V_44 ;
else
V_15 -> V_13 . V_38 = V_44 ;
V_28 = V_44 -> V_28 ;
if ( V_28 ) {
V_15 -> V_33 = V_28 -> V_68 ;
V_44 -> V_28 = NULL ;
}
V_15 -> V_13 . V_69 = V_44 -> V_70 ;
V_15 -> V_13 . V_71 += V_44 -> V_63 ;
V_15 -> V_23 |= V_23 ;
F_38 ( & V_15 -> V_13 , V_44 -> V_72 ) ;
if ( V_50 == 0 ) {
V_15 -> V_73 = V_47 ;
V_15 -> V_13 . V_30 |= V_37 ;
}
if ( V_15 -> V_13 . V_30 == ( V_37 | V_64 ) &&
V_15 -> V_13 . V_71 == V_15 -> V_13 . V_63 ) {
int V_74 ;
unsigned long V_75 = V_44 -> V_76 ;
V_44 -> V_76 = 0UL ;
V_74 = F_39 ( V_15 , V_48 , V_28 ) ;
V_44 -> V_76 = V_75 ;
return V_74 ;
}
F_40 ( V_44 ) ;
F_41 ( & V_15 -> V_13 ) ;
return - 1 ;
V_67:
F_13 ( & V_15 -> V_13 , & V_16 ) ;
V_52:
F_42 ( V_24 , F_28 ( F_25 ( V_44 ) ) ,
V_36 ) ;
F_43 ( V_44 ) ;
return - 1 ;
}
static int F_39 ( struct V_14 * V_15 , struct V_43 * V_48 ,
struct V_27 * V_28 )
{
struct V_24 * V_24 = F_7 ( V_15 -> V_13 . V_24 , struct V_24 , V_42 . V_26 ) ;
struct V_43 * V_77 , * V_78 = V_15 -> V_13 . V_38 ;
int V_54 ;
unsigned int V_47 ;
int V_79 ;
T_1 V_23 ;
F_13 ( & V_15 -> V_13 , & V_16 ) ;
V_23 = V_80 [ V_15 -> V_23 ] ;
if ( F_44 ( V_23 == 0xff ) )
goto V_81;
if ( V_48 ) {
V_78 = V_48 -> V_49 ;
V_77 = F_45 ( V_78 , V_82 ) ;
if ( ! V_77 )
goto V_83;
V_77 -> V_49 = V_78 -> V_49 ;
if ( ! V_77 -> V_49 )
V_15 -> V_13 . V_65 = V_77 ;
V_48 -> V_49 = V_77 ;
F_46 ( V_78 , V_15 -> V_13 . V_38 ) ;
V_78 -> V_49 = V_15 -> V_13 . V_38 -> V_49 ;
F_47 ( V_15 -> V_13 . V_38 ) ;
V_15 -> V_13 . V_38 = V_78 ;
}
F_48 ( V_78 == NULL ) ;
F_48 ( F_37 ( V_78 ) -> V_50 != 0 ) ;
V_54 = ( ( V_78 -> V_41 - F_30 ( V_78 ) ) -
sizeof( struct V_1 ) + V_15 -> V_13 . V_63 -
sizeof( struct V_45 ) ) ;
if ( V_54 > V_55 )
goto V_84;
if ( F_49 ( V_78 , V_82 ) )
goto V_83;
if ( F_50 ( V_78 ) ) {
struct V_43 * V_85 ;
int V_86 , V_87 = 0 ;
if ( ( V_85 = F_51 ( 0 , V_82 ) ) == NULL )
goto V_83;
V_85 -> V_49 = V_78 -> V_49 ;
V_78 -> V_49 = V_85 ;
F_52 ( V_85 ) -> V_88 = F_52 ( V_78 ) -> V_88 ;
F_53 ( V_78 ) ;
for ( V_86 = 0 ; V_86 < F_52 ( V_78 ) -> V_89 ; V_86 ++ )
V_87 += F_54 ( & F_52 ( V_78 ) -> V_26 [ V_86 ] ) ;
V_85 -> V_63 = V_85 -> V_90 = V_78 -> V_90 - V_87 ;
V_78 -> V_90 -= V_85 -> V_63 ;
V_78 -> V_63 -= V_85 -> V_63 ;
V_85 -> V_61 = 0 ;
V_85 -> V_58 = V_78 -> V_58 ;
F_38 ( & V_15 -> V_13 , V_85 -> V_72 ) ;
}
V_47 = V_15 -> V_73 ;
F_30 ( V_78 ) [ V_47 ] = F_55 ( V_78 ) [ 0 ] ;
memmove ( V_78 -> V_78 + sizeof( struct V_45 ) , V_78 -> V_78 ,
( V_78 -> V_41 - V_78 -> V_78 ) - sizeof( struct V_45 ) ) ;
V_78 -> V_91 += sizeof( struct V_45 ) ;
V_78 -> V_92 += sizeof( struct V_45 ) ;
F_56 ( V_78 ) ;
F_57 ( V_78 , V_78 -> V_41 - F_30 ( V_78 ) ) ;
V_79 = V_78 -> V_72 ;
for ( V_77 = V_78 -> V_49 ; V_77 ; ) {
bool V_93 ;
int V_94 ;
struct V_43 * V_49 = V_77 -> V_49 ;
V_79 += V_77 -> V_72 ;
if ( V_78 -> V_58 != V_77 -> V_58 )
V_78 -> V_58 = V_95 ;
else if ( V_78 -> V_58 == V_59 )
V_78 -> V_61 = F_58 ( V_78 -> V_61 , V_77 -> V_61 ) ;
if ( F_59 ( V_78 , V_77 , & V_93 , & V_94 ) ) {
F_60 ( V_77 , V_93 ) ;
} else {
if ( ! F_52 ( V_78 ) -> V_88 )
F_52 ( V_78 ) -> V_88 = V_77 ;
V_78 -> V_90 += V_77 -> V_63 ;
V_78 -> V_63 += V_77 -> V_63 ;
V_78 -> V_72 += V_77 -> V_72 ;
}
V_77 = V_49 ;
}
F_61 ( & V_15 -> V_13 , V_79 ) ;
V_78 -> V_49 = NULL ;
V_78 -> V_28 = V_28 ;
V_78 -> V_70 = V_15 -> V_13 . V_69 ;
F_27 ( V_78 ) -> V_54 = F_33 ( V_54 ) ;
F_62 ( F_27 ( V_78 ) , 0xff , V_23 ) ;
F_63 ( V_78 ) -> V_47 = V_47 ;
F_63 ( V_78 ) -> V_96 |= V_97 ;
if ( V_78 -> V_58 == V_59 )
V_78 -> V_61 = F_32 ( F_30 ( V_78 ) ,
F_64 ( V_78 ) ,
V_78 -> V_61 ) ;
F_14 () ;
F_16 ( V_24 , F_17 ( V_28 ) , V_98 ) ;
F_19 () ;
V_15 -> V_13 . V_38 = NULL ;
V_15 -> V_13 . V_65 = NULL ;
return 1 ;
V_84:
F_65 ( L_1 , V_54 ) ;
goto V_81;
V_83:
F_65 ( L_2 ) ;
V_81:
F_14 () ;
F_16 ( V_24 , F_17 ( V_28 ) , V_36 ) ;
F_19 () ;
return - 1 ;
}
static int F_66 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_14 * V_15 ;
const struct V_1 * V_99 = F_27 ( V_44 ) ;
struct V_24 * V_24 = F_24 ( F_25 ( V_44 ) -> V_28 ) ;
int V_100 ;
if ( F_63 ( V_44 ) -> V_96 & V_97 )
goto V_101;
F_16 ( V_24 , F_28 ( F_25 ( V_44 ) ) , V_102 ) ;
if ( V_99 -> V_54 == 0 )
goto V_101;
if ( ! F_67 ( V_44 , ( F_68 ( V_44 ) +
sizeof( struct V_45 ) ) ) )
goto V_101;
V_99 = F_27 ( V_44 ) ;
V_46 = (struct V_45 * ) F_55 ( V_44 ) ;
if ( ! ( V_46 -> V_53 & F_33 ( 0xFFF9 ) ) ) {
V_44 -> V_103 += sizeof( struct V_45 ) ;
F_16 ( V_24 ,
F_28 ( F_25 ( V_44 ) ) , V_98 ) ;
F_63 ( V_44 ) -> V_47 = ( T_1 * ) V_46 - F_30 ( V_44 ) ;
F_63 ( V_44 ) -> V_96 |= V_97 ;
return 1 ;
}
V_100 = F_69 ( & V_24 -> V_42 . V_26 , & V_16 , false ) ;
if ( V_100 )
F_70 ( V_24 , F_28 ( F_25 ( V_44 ) ) ,
V_36 , V_100 ) ;
V_15 = F_71 ( V_24 , V_46 -> V_104 , & V_99 -> V_6 , & V_99 -> V_7 ,
F_1 ( V_99 ) ) ;
if ( V_15 != NULL ) {
int V_105 ;
F_12 ( & V_15 -> V_13 . V_29 ) ;
V_105 = F_23 ( V_15 , V_44 , V_46 , F_63 ( V_44 ) -> V_47 ) ;
F_20 ( & V_15 -> V_13 . V_29 ) ;
F_21 ( & V_15 -> V_13 , & V_16 ) ;
return V_105 ;
}
F_16 ( V_24 , F_28 ( F_25 ( V_44 ) ) , V_36 ) ;
F_43 ( V_44 ) ;
return - 1 ;
V_101:
F_42 ( V_24 , F_28 ( F_25 ( V_44 ) ) , V_56 ) ;
F_29 ( V_44 , V_57 , F_64 ( V_44 ) ) ;
return - 1 ;
}
static int T_4 F_72 ( struct V_24 * V_24 )
{
struct V_106 * V_107 ;
struct V_108 * V_99 ;
V_107 = V_109 ;
if ( ! F_73 ( V_24 , & V_110 ) ) {
V_107 = F_74 ( V_107 , sizeof( V_109 ) , V_111 ) ;
if ( V_107 == NULL )
goto V_112;
V_107 [ 0 ] . V_41 = & V_24 -> V_42 . V_26 . V_113 ;
V_107 [ 1 ] . V_41 = & V_24 -> V_42 . V_26 . V_114 ;
V_107 [ 2 ] . V_41 = & V_24 -> V_42 . V_26 . V_115 ;
if ( V_24 -> V_116 != & V_117 )
V_107 [ 0 ] . V_118 = NULL ;
}
V_99 = F_75 ( V_24 , L_3 , V_107 ) ;
if ( V_99 == NULL )
goto V_119;
V_24 -> V_42 . V_120 . V_121 = V_99 ;
return 0 ;
V_119:
if ( ! F_73 ( V_24 , & V_110 ) )
F_76 ( V_107 ) ;
V_112:
return - V_122 ;
}
static void T_5 F_77 ( struct V_24 * V_24 )
{
struct V_106 * V_107 ;
V_107 = V_24 -> V_42 . V_120 . V_121 -> V_123 ;
F_78 ( V_24 -> V_42 . V_120 . V_121 ) ;
if ( ! F_73 ( V_24 , & V_110 ) )
F_76 ( V_107 ) ;
}
static int F_79 ( void )
{
V_124 = F_75 ( & V_110 , L_3 ,
V_125 ) ;
return V_124 == NULL ? - V_122 : 0 ;
}
static void F_80 ( void )
{
F_78 ( V_124 ) ;
}
static inline int F_72 ( struct V_24 * V_24 )
{
return 0 ;
}
static inline void F_77 ( struct V_24 * V_24 )
{
}
static inline int F_79 ( void )
{
return 0 ;
}
static inline void F_80 ( void )
{
}
static int T_4 F_81 ( struct V_24 * V_24 )
{
V_24 -> V_42 . V_26 . V_113 = V_126 ;
V_24 -> V_42 . V_26 . V_114 = V_127 ;
V_24 -> V_42 . V_26 . V_115 = V_128 ;
F_82 ( & V_24 -> V_42 . V_26 ) ;
return F_72 ( V_24 ) ;
}
static void T_5 F_83 ( struct V_24 * V_24 )
{
F_77 ( V_24 ) ;
F_84 ( & V_24 -> V_42 . V_26 , & V_16 ) ;
}
int T_6 F_85 ( void )
{
int V_105 ;
V_105 = F_86 ( & V_129 , V_130 ) ;
if ( V_105 )
goto V_32;
V_105 = F_79 () ;
if ( V_105 )
goto V_131;
V_105 = F_87 ( & V_132 ) ;
if ( V_105 )
goto V_133;
V_16 . V_134 = F_6 ;
V_16 . V_135 = F_10 ;
V_16 . V_136 = NULL ;
V_16 . V_137 = NULL ;
V_16 . V_138 = sizeof( struct V_14 ) ;
V_16 . V_139 = F_8 ;
V_16 . V_140 = F_22 ;
V_16 . V_141 = 10 * 60 * V_142 ;
F_88 ( & V_16 ) ;
V_32:
return V_105 ;
V_133:
F_80 () ;
V_131:
F_89 ( & V_129 , V_130 ) ;
goto V_32;
}
void F_90 ( void )
{
F_91 ( & V_16 ) ;
F_80 () ;
F_92 ( & V_132 ) ;
F_89 ( & V_129 , V_130 ) ;
}
