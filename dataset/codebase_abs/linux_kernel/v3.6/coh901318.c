static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 = V_4 ;
int V_6 = 0 ;
while ( V_5 ) {
F_2 ( F_3 ( V_2 ) , L_1
L_2 ,
V_6 , V_5 , V_5 -> V_7 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
V_6 ++ ;
V_5 = V_5 -> V_11 ;
}
}
static int F_4 ( struct V_12 * V_12 , char T_1 * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
T_4 V_16 = V_17 -> V_18 . V_16 ;
int V_19 = V_17 -> V_20 . V_21 ;
int V_6 ;
int V_22 = 0 ;
char * V_23 ;
char * V_24 ;
int V_25 ;
V_23 = F_5 ( 4 * 1024 , V_26 ) ;
if ( V_23 == NULL )
goto V_27;
V_24 = V_23 ;
V_24 += sprintf ( V_24 , L_3 ) ;
for ( V_6 = 0 ; V_6 < V_17 -> V_28 -> V_29 ; V_6 ++ )
if ( V_16 & ( 1 << V_6 ) )
V_24 += sprintf ( V_24 , L_4 , V_6 ) ;
V_24 += sprintf ( V_24 , L_5 , V_19 ) ;
V_25 = V_24 - V_23 ;
if ( * V_15 > V_25 )
goto V_30;
if ( V_14 > V_25 - * V_15 )
V_14 = V_25 - * V_15 ;
if ( F_6 ( V_13 , V_23 + * V_15 , V_14 ) )
V_22 = - V_31 ;
V_22 = V_14 ;
* V_15 += V_14 ;
V_30:
F_7 ( V_23 ) ;
return V_22 ;
V_27:
return 0 ;
}
static int T_5 F_8 ( void )
{
V_32 = F_9 ( L_6 , NULL ) ;
( void ) F_10 ( L_7 ,
V_33 | V_34 ,
V_32 , NULL ,
& V_35 ) ;
return 0 ;
}
static void T_6 F_11 ( void )
{
F_12 ( V_32 ) ;
}
static inline struct V_1 * F_13 ( struct V_36 * V_37 )
{
return F_14 ( V_37 , struct V_1 , V_37 ) ;
}
static inline T_7
F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 )
return V_2 -> V_38 ;
return V_2 -> V_39 -> V_28 -> V_40 [ V_2 -> V_41 ] . V_42 ;
}
static inline const struct V_43 *
F_16 ( struct V_1 * V_2 )
{
return & V_2 -> V_39 -> V_28 -> V_40 [ V_2 -> V_41 ] . V_44 ;
}
static inline const struct V_45 *
F_17 ( struct V_1 * V_2 )
{
return & V_2 -> V_39 -> V_28 -> V_40 [ V_2 -> V_41 ] ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
struct V_47 * V_18 = & V_2 -> V_39 -> V_18 ;
F_19 ( & V_18 -> V_48 , V_46 ) ;
V_18 -> V_16 &= ~ ( 1ULL << V_2 -> V_41 ) ;
if ( ! V_18 -> V_16 ) {
V_2 -> V_39 -> V_28 -> V_49 ( V_2 -> V_39 -> V_50 ,
false ) ;
}
F_20 ( & V_18 -> V_48 , V_46 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
struct V_47 * V_18 = & V_2 -> V_39 -> V_18 ;
F_19 ( & V_18 -> V_48 , V_46 ) ;
if ( ! V_18 -> V_16 ) {
V_2 -> V_39 -> V_28 -> V_49 ( V_2 -> V_39 -> V_50 ,
true ) ;
}
V_18 -> V_16 |= ( 1ULL << V_2 -> V_41 ) ;
F_20 ( & V_18 -> V_48 , V_46 ) ;
}
static inline int F_22 ( struct V_1 * V_2 , T_8 V_7 )
{
int V_51 = V_2 -> V_41 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
F_23 ( V_7 ,
V_52 + V_53 +
V_54 * V_51 ) ;
return 0 ;
}
static inline int F_24 ( struct V_1 * V_2 , T_8 V_55 )
{
int V_51 = V_2 -> V_41 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
F_23 ( V_55 ,
V_52 + V_56 +
V_57 * V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_8 V_58 ;
int V_51 = V_2 -> V_41 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
F_21 ( V_2 ) ;
V_58 = F_26 ( V_52 + V_56 +
V_57 * V_51 ) ;
V_58 |= V_59 ;
F_23 ( V_58 , V_52 + V_56 +
V_57 * V_51 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_51 = V_2 -> V_41 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
F_28 ( F_26 ( V_52 + V_60 +
V_61 * V_51 ) &
V_62 ) ;
F_23 ( V_4 -> V_8 ,
V_52 + V_63 +
V_64 * V_51 ) ;
F_23 ( V_4 -> V_9 , V_52 +
V_65 +
V_66 * V_51 ) ;
F_23 ( V_4 -> V_10 , V_52 + V_67 +
V_68 * V_51 ) ;
F_23 ( V_4 -> V_7 , V_52 + V_53 +
V_54 * V_51 ) ;
return 0 ;
}
static struct V_69 *
F_29 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
if ( F_30 ( & V_2 -> free ) ) {
V_70 = F_31 ( sizeof( struct V_69 ) , V_71 ) ;
if ( V_70 == NULL )
goto V_30;
F_32 ( & V_70 -> V_72 ) ;
F_33 ( & V_70 -> V_70 , & V_2 -> V_37 ) ;
} else {
V_70 = F_34 ( & V_2 -> free ,
struct V_69 ,
V_72 ) ;
F_35 ( & V_70 -> V_72 ) ;
V_70 -> V_73 = NULL ;
V_70 -> V_74 = 0 ;
V_70 -> V_70 . V_75 = NULL ;
V_70 -> V_70 . V_76 = NULL ;
}
V_30:
return V_70 ;
}
static void
F_36 ( struct V_1 * V_2 , struct V_69 * V_77 )
{
F_37 ( & V_77 -> V_72 , & V_2 -> free ) ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
F_37 ( & V_70 -> V_72 , & V_2 -> V_78 ) ;
}
static struct V_69 *
F_39 ( struct V_1 * V_2 )
{
struct V_69 * V_79 ;
if ( F_30 ( & V_2 -> V_78 ) )
return NULL ;
V_79 = F_34 ( & V_2 -> V_78 ,
struct V_69 ,
V_72 ) ;
return V_79 ;
}
static void
F_40 ( struct V_69 * V_77 )
{
F_35 ( & V_77 -> V_72 ) ;
}
static void
F_41 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
F_37 ( & V_70 -> V_72 , & V_2 -> V_80 ) ;
}
static struct V_69 *
F_42 ( struct V_1 * V_2 )
{
struct V_69 * V_79 ;
if ( F_30 ( & V_2 -> V_80 ) )
return NULL ;
V_79 = F_34 ( & V_2 -> V_80 ,
struct V_69 ,
V_72 ) ;
return V_79 ;
}
static inline T_8 F_43 ( struct V_3 * V_81 )
{
struct V_3 * V_4 = V_81 ;
T_8 V_82 = 0 ;
while ( V_4 ) {
V_82 += V_4 -> V_7 & V_83 ;
V_4 = V_4 -> V_11 ;
}
return V_82 ;
}
static T_8 F_44 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
struct V_69 * V_77 ;
struct V_84 * V_85 ;
unsigned long V_46 ;
T_8 V_86 = 0 ;
int V_6 = 0 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
F_45 (pos, &cohc->active) {
V_77 = F_46 ( V_85 , struct V_69 , V_72 ) ;
if ( V_6 == 0 ) {
struct V_3 * V_4 ;
T_7 V_87 ;
V_86 = F_26 ( V_2 -> V_39 -> V_52 +
V_53 +
V_54 * V_2 -> V_41 ) &
V_83 ;
V_87 = F_26 ( V_2 -> V_39 -> V_52 +
V_67 +
V_68 *
V_2 -> V_41 ) &
~ V_88 ;
if ( ! V_87 )
continue;
V_4 = V_77 -> V_4 ;
while ( V_4 && V_4 -> V_10 != V_87 )
V_4 = V_4 -> V_11 ;
if ( V_4 )
V_4 = V_4 -> V_11 ;
V_86 += F_43 ( V_4 ) ;
} else {
V_86 += F_43 ( V_77 -> V_4 ) ;
}
V_6 ++ ;
}
F_45 (pos, &cohc->queue) {
V_77 = F_46 ( V_85 , struct V_69 , V_72 ) ;
V_86 += F_43 ( V_77 -> V_4 ) ;
}
F_20 ( & V_2 -> V_48 , V_46 ) ;
return V_86 ;
}
static void F_47 ( struct V_36 * V_37 )
{
T_8 V_58 ;
unsigned long V_46 ;
struct V_1 * V_2 = F_13 ( V_37 ) ;
int V_51 = V_2 -> V_41 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
V_58 = F_26 ( V_52 + V_56 +
V_57 * V_51 ) ;
if ( ( V_58 & V_89 ) == 0 &&
( V_58 & V_59 ) )
V_2 -> V_90 = 1 ;
V_58 &= ~ V_59 ;
F_23 ( V_58 , V_52 + V_56 +
V_57 * V_51 ) ;
F_23 ( V_58 , V_52 + V_56 +
V_57 * V_51 ) ;
while ( F_26 ( V_52 + V_60 + V_61 *
V_51 ) & V_62 )
F_48 () ;
if ( ( F_26 ( V_52 + V_53 + V_54 *
V_51 ) & V_83 ) > 0 )
V_2 -> V_90 = 1 ;
F_18 ( V_2 ) ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
}
static void F_49 ( struct V_36 * V_37 )
{
T_8 V_58 ;
unsigned long V_46 ;
struct V_1 * V_2 = F_13 ( V_37 ) ;
int V_51 = V_2 -> V_41 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
F_21 ( V_2 ) ;
if ( V_2 -> V_90 ) {
V_58 = F_26 ( V_2 -> V_39 -> V_52 + V_56 +
V_57 * V_51 ) ;
V_58 |= V_59 ;
F_23 ( V_58 , V_2 -> V_39 -> V_52 + V_56 +
V_57 * V_51 ) ;
V_2 -> V_90 = 0 ;
}
F_20 ( & V_2 -> V_48 , V_46 ) ;
}
bool F_50 ( struct V_36 * V_37 , void * V_91 )
{
unsigned int V_92 = ( unsigned int ) V_91 ;
if ( V_92 == F_13 ( V_37 ) -> V_41 )
return true ;
return false ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned long V_46 ;
const struct V_43 * V_93 ;
int V_51 = V_2 -> V_41 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
if ( V_44 )
V_93 = V_44 ;
else
V_93 = & V_2 -> V_39 -> V_28 -> V_40 [ V_51 ] . V_44 ;
if ( V_51 < 32 ) {
F_23 ( 1 << V_51 , V_52 + V_94 ) ;
F_23 ( 1 << V_51 , V_52 + V_95 ) ;
} else {
F_23 ( 1 << ( V_51 - 32 ) , V_52 +
V_96 ) ;
F_23 ( 1 << ( V_51 - 32 ) , V_52 +
V_97 ) ;
}
F_24 ( V_2 , V_93 -> V_98 ) ;
F_22 ( V_2 , V_93 -> V_99 ) ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
return 0 ;
}
static struct V_69 * F_52 ( struct V_1 * V_2 )
{
struct V_69 * V_77 ;
V_77 = F_42 ( V_2 ) ;
if ( V_77 != NULL ) {
F_40 ( V_77 ) ;
V_2 -> V_100 = 1 ;
F_38 ( V_2 , V_77 ) ;
F_24 ( V_2 , V_77 -> V_101 ) ;
F_22 ( V_2 , V_77 -> V_102 ) ;
F_27 ( V_2 , V_77 -> V_4 ) ;
F_25 ( V_2 ) ;
}
return V_77 ;
}
static void F_53 ( unsigned long V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_103 ;
struct V_69 * V_104 ;
unsigned long V_46 ;
T_10 V_75 ;
void * V_76 ;
F_2 ( F_3 ( V_2 ) , L_8
L_9 , V_105 ,
V_2 -> V_41 , V_2 -> V_106 ) ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
V_104 = F_39 ( V_2 ) ;
if ( V_104 == NULL )
goto V_107;
V_75 = V_104 -> V_70 . V_75 ;
V_76 = V_104 -> V_70 . V_76 ;
F_54 ( & V_104 -> V_70 ) ;
F_55 ( & V_2 -> V_39 -> V_20 , & V_104 -> V_4 ) ;
F_40 ( V_104 ) ;
F_36 ( V_2 , V_104 ) ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
if ( V_75 )
V_75 ( V_76 ) ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
V_2 -> V_106 -- ;
if ( V_2 -> V_106 ) {
F_56 ( F_3 ( V_2 ) , L_10
L_11 ) ;
if ( F_17 ( V_2 ) -> V_108 )
F_57 ( & V_2 -> V_109 ) ;
else
F_58 ( & V_2 -> V_109 ) ;
}
F_20 ( & V_2 -> V_48 , V_46 ) ;
return;
V_107:
F_20 ( & V_2 -> V_48 , V_46 ) ;
F_59 ( F_3 ( V_2 ) , L_12 , V_105 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_110 ) {
F_59 ( F_3 ( V_2 ) , L_13
L_14 ) ;
return;
}
F_61 ( & V_2 -> V_48 ) ;
F_28 ( F_30 ( & V_2 -> V_78 ) ) ;
V_2 -> V_106 ++ ;
if ( F_52 ( V_2 ) == NULL )
V_2 -> V_100 = 0 ;
F_62 ( & V_2 -> V_48 ) ;
if ( F_17 ( V_2 ) -> V_108 )
F_57 ( & V_2 -> V_109 ) ;
else
F_58 ( & V_2 -> V_109 ) ;
}
static T_11 F_63 ( int V_111 , void * V_112 )
{
T_8 V_113 ;
T_8 V_114 ;
int V_6 ;
int V_115 ;
struct V_116 * V_39 = V_112 ;
struct V_1 * V_2 ;
void T_9 * V_52 = V_39 -> V_52 ;
V_113 = F_26 ( V_52 + V_117 ) ;
V_114 = F_26 ( V_52 + V_118 ) ;
if ( F_64 ( V_113 == 0 && V_114 == 0 ) ) {
F_65 ( V_39 -> V_50 , L_15 ) ;
return V_119 ;
}
while ( V_113 ) {
V_6 = F_66 ( V_113 ) - 1 ;
V_115 = V_6 ;
V_2 = & V_39 -> V_120 [ V_115 ] ;
F_61 ( & V_2 -> V_48 ) ;
V_113 &= ~ ( 1 << V_6 ) ;
if ( F_67 ( V_6 , V_52 + V_121 ) ) {
F_68 ( F_3 ( V_2 ) ,
L_16 , V_115 ) ;
F_28 ( 1 ) ;
F_69 ( V_6 , V_52 + V_94 ) ;
} else {
if ( F_64 ( ! F_67 ( V_6 , V_52 +
V_122 ) ) ) {
F_65 ( F_3 ( V_2 ) ,
L_17 , V_115 ) ;
F_28 ( 1 ) ;
F_69 ( V_6 , V_52 + V_95 ) ;
} else {
if ( ! ( F_26 ( V_52 + V_60 +
V_61 * V_115 ) &
V_123 ) ) {
F_18 ( V_2 ) ;
}
F_69 ( V_6 , V_52 + V_95 ) ;
F_60 ( V_2 ) ;
}
}
F_62 ( & V_2 -> V_48 ) ;
}
while ( V_114 ) {
V_6 = F_66 ( V_114 ) - 1 ;
V_115 = V_6 + 32 ;
V_2 = & V_39 -> V_120 [ V_115 ] ;
F_61 ( & V_2 -> V_48 ) ;
V_114 &= ~ ( 1 << V_6 ) ;
if ( F_67 ( V_6 , V_52 + V_124 ) ) {
F_68 ( F_3 ( V_2 ) ,
L_16 , V_115 ) ;
F_28 ( 1 ) ;
F_69 ( V_6 , V_52 + V_96 ) ;
} else {
if ( F_64 ( ! F_67 ( V_6 , V_52 +
V_125 ) ) ) {
F_65 ( F_3 ( V_2 ) ,
L_17 , V_115 ) ;
F_69 ( V_6 , V_52 + V_97 ) ;
F_28 ( 1 ) ;
} else {
if ( ! ( F_26 ( V_52 + V_60 +
V_61 * V_115 ) &
V_123 ) ) {
F_18 ( V_2 ) ;
}
F_69 ( V_6 , V_52 + V_97 ) ;
F_60 ( V_2 ) ;
}
}
F_62 ( & V_2 -> V_48 ) ;
}
return V_119 ;
}
static int F_70 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
unsigned long V_46 ;
F_2 ( F_3 ( V_2 ) , L_18 ,
V_105 , V_2 -> V_41 ) ;
if ( V_37 -> V_126 > 1 )
return - V_127 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
F_51 ( V_2 , NULL ) ;
V_2 -> V_110 = 1 ;
F_71 ( V_37 ) ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
return 1 ;
}
static void
F_72 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
int V_51 = V_2 -> V_41 ;
unsigned long V_46 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
F_23 ( 0x00000000U , V_2 -> V_39 -> V_52 + V_56 +
V_57 * V_51 ) ;
F_23 ( 0x00000000U , V_2 -> V_39 -> V_52 + V_53 +
V_54 * V_51 ) ;
V_2 -> V_110 = 0 ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
V_37 -> V_128 -> V_129 ( V_37 , V_130 , 0 ) ;
}
static T_12
F_73 ( struct V_131 * V_132 )
{
struct V_69 * V_77 = F_14 ( V_132 , struct V_69 ,
V_70 ) ;
struct V_1 * V_2 = F_13 ( V_132 -> V_37 ) ;
unsigned long V_46 ;
T_12 V_133 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
V_133 = F_74 ( V_132 ) ;
F_41 ( V_2 , V_77 ) ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
return V_133 ;
}
static struct V_131 *
F_75 ( struct V_36 * V_37 , T_7 V_134 , T_7 V_135 ,
T_2 V_136 , unsigned long V_46 )
{
struct V_3 * V_4 ;
struct V_69 * V_77 ;
unsigned long V_137 ;
struct V_1 * V_2 = F_13 ( V_37 ) ;
int V_138 ;
T_8 V_139 = F_16 ( V_2 ) -> V_99 ;
int V_22 ;
F_19 ( & V_2 -> V_48 , V_137 ) ;
F_2 ( F_3 ( V_2 ) ,
L_19 ,
V_105 , V_2 -> V_41 , V_135 , V_134 , V_136 ) ;
if ( V_46 & V_140 )
V_139 |= V_141 ;
V_138 = V_136 >> V_142 ;
if ( ( V_138 << V_142 ) < V_136 )
V_138 ++ ;
V_4 = F_76 ( & V_2 -> V_39 -> V_20 , V_138 ) ;
if ( V_4 == NULL )
goto V_107;
V_22 = F_77 (
& V_2 -> V_39 -> V_20 , V_4 , V_135 , V_136 , V_134 ,
F_16 ( V_2 ) -> V_143 ,
V_139 ) ;
if ( V_22 )
goto V_107;
F_78 ( F_1 ( V_2 , V_4 ) ) ;
V_77 = F_29 ( V_2 ) ;
V_77 -> V_4 = V_4 ;
V_77 -> V_46 = V_46 ;
V_77 -> V_70 . V_144 = F_73 ;
F_20 ( & V_2 -> V_48 , V_137 ) ;
return & V_77 -> V_70 ;
V_107:
F_20 ( & V_2 -> V_48 , V_137 ) ;
return NULL ;
}
static struct V_131 *
F_79 ( struct V_36 * V_37 , struct V_145 * V_146 ,
unsigned int V_74 , enum V_147 V_148 ,
unsigned long V_46 , void * V_149 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
struct V_3 * V_4 ;
struct V_69 * V_77 ;
const struct V_43 * V_150 ;
struct V_145 * V_73 ;
int V_151 = 0 ;
int V_136 ;
int V_6 ;
T_8 V_152 = F_16 ( V_2 ) -> V_143 ;
T_8 V_153 = F_16 ( V_2 ) -> V_154 ;
T_8 V_139 = F_16 ( V_2 ) -> V_99 ;
T_8 V_98 ;
unsigned long V_137 ;
int V_22 ;
if ( ! V_146 )
goto V_30;
if ( F_80 ( V_146 ) == 0 )
goto V_30;
F_19 ( & V_2 -> V_48 , V_137 ) ;
F_2 ( F_3 ( V_2 ) , L_20 ,
V_105 , V_74 , V_148 ) ;
if ( V_46 & V_140 )
V_139 |= V_141 ;
V_150 = F_16 ( V_2 ) ;
V_98 = V_150 -> V_98 ;
V_152 |= V_2 -> V_155 ;
V_139 |= V_2 -> V_155 ;
V_153 |= V_2 -> V_155 ;
if ( V_148 == V_156 ) {
T_8 V_157 = V_158 |
V_159 ;
V_98 |= V_160 ;
V_152 |= V_157 ;
V_139 |= V_157 ;
V_153 |= V_157 ;
} else if ( V_148 == V_161 ) {
T_8 V_162 = V_163 |
V_164 ;
V_98 |= V_165 ;
V_152 |= V_162 ;
V_139 |= V_162 ;
V_153 |= V_162 ;
} else
goto V_166;
F_81 (sgl, sg, sg_len, i) {
unsigned int V_167 ;
V_136 = F_80 ( V_73 ) ;
if ( V_136 <= V_168 ) {
V_151 ++ ;
continue;
}
V_167 = V_136 >> V_142 ;
if ( ( V_167 << V_142 ) < V_136 )
V_167 ++ ;
V_151 += V_167 ;
}
F_82 ( L_21 , V_151 ) ;
V_4 = F_76 ( & V_2 -> V_39 -> V_20 , V_151 ) ;
if ( V_4 == NULL )
goto V_169;
V_22 = F_83 ( & V_2 -> V_39 -> V_20 , V_4 , V_146 , V_74 ,
F_15 ( V_2 ) ,
V_152 ,
V_153 ,
V_139 ,
V_148 , V_141 ) ;
if ( V_22 )
goto V_170;
F_78 ( F_1 ( V_2 , V_4 ) ) ;
V_77 = F_29 ( V_2 ) ;
V_77 -> V_101 = V_98 ;
V_77 -> V_102 = V_4 -> V_7 ;
V_77 -> V_171 = V_148 ;
V_77 -> V_46 = V_46 ;
V_77 -> V_70 . V_144 = F_73 ;
V_77 -> V_4 = V_4 ;
F_20 ( & V_2 -> V_48 , V_137 ) ;
return & V_77 -> V_70 ;
V_170:
V_169:
V_166:
F_20 ( & V_2 -> V_48 , V_137 ) ;
V_30:
return NULL ;
}
static enum V_172
F_84 ( struct V_36 * V_37 , T_12 V_133 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
enum V_172 V_22 ;
V_22 = F_85 ( V_37 , V_133 , V_174 ) ;
F_86 ( V_174 , F_44 ( V_37 ) ) ;
if ( V_22 == V_175 && V_2 -> V_90 )
V_22 = V_176 ;
return V_22 ;
}
static void
F_87 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
unsigned long V_46 ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
if ( ! V_2 -> V_100 )
F_52 ( V_2 ) ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
}
static void F_88 ( struct V_36 * V_37 ,
struct V_177 * V_98 )
{
struct V_1 * V_2 = F_13 ( V_37 ) ;
T_7 V_178 ;
enum V_179 V_180 ;
T_8 V_181 ;
T_8 V_155 = 0 ;
int V_6 = 0 ;
if ( V_98 -> V_148 == V_161 ) {
V_178 = V_98 -> V_8 ;
V_180 = V_98 -> V_182 ;
V_181 = V_98 -> V_183 ;
} else if ( V_98 -> V_148 == V_156 ) {
V_178 = V_98 -> V_9 ;
V_180 = V_98 -> V_184 ;
V_181 = V_98 -> V_185 ;
} else {
F_59 ( F_3 ( V_2 ) , L_22 ) ;
return;
}
F_56 ( F_3 ( V_2 ) , L_23 ,
V_180 ) ;
switch ( V_180 ) {
case V_186 :
V_155 |=
V_187 |
V_188 ;
while ( V_6 < F_89 ( V_189 ) ) {
if ( V_189 [ V_6 ] . V_190 <= V_181 )
break;
V_6 ++ ;
}
break;
case V_191 :
V_155 |=
V_192 |
V_193 ;
while ( V_6 < F_89 ( V_189 ) ) {
if ( V_189 [ V_6 ] . V_194 <= V_181 )
break;
V_6 ++ ;
}
break;
case V_195 :
V_155 |=
V_196 |
V_197 ;
while ( V_6 < F_89 ( V_189 ) ) {
if ( V_189 [ V_6 ] . V_198 <= V_181 )
break;
V_6 ++ ;
}
break;
default:
F_59 ( F_3 ( V_2 ) ,
L_24 ) ;
return;
}
V_155 |= V_189 [ V_6 ] . V_199 ;
F_56 ( F_3 ( V_2 ) ,
L_25 ,
V_189 [ V_6 ] . V_190 , V_180 , V_181 ) ;
V_2 -> V_38 = V_178 ;
V_2 -> V_155 = V_155 ;
}
static int
F_90 ( struct V_36 * V_37 , enum V_200 V_201 ,
unsigned long V_202 )
{
unsigned long V_46 ;
struct V_1 * V_2 = F_13 ( V_37 ) ;
struct V_69 * V_77 ;
void T_9 * V_52 = V_2 -> V_39 -> V_52 ;
if ( V_201 == V_203 ) {
struct V_177 * V_98 =
(struct V_177 * ) V_202 ;
F_88 ( V_37 , V_98 ) ;
return 0 ;
}
if ( V_201 == V_204 ) {
F_47 ( V_37 ) ;
return 0 ;
}
if ( V_201 == V_205 ) {
F_49 ( V_37 ) ;
return 0 ;
}
if ( V_201 != V_130 )
return - V_206 ;
F_47 ( V_37 ) ;
F_19 ( & V_2 -> V_48 , V_46 ) ;
if ( V_2 -> V_41 < 32 ) {
F_23 ( 1 << V_2 -> V_41 , V_52 + V_94 ) ;
F_23 ( 1 << V_2 -> V_41 , V_52 + V_95 ) ;
} else {
F_23 ( 1 << ( V_2 -> V_41 - 32 ) , V_52 +
V_96 ) ;
F_23 ( 1 << ( V_2 -> V_41 - 32 ) , V_52 +
V_97 ) ;
}
F_18 ( V_2 ) ;
while ( ( V_77 = F_39 ( V_2 ) ) ) {
F_55 ( & V_2 -> V_39 -> V_20 , & V_77 -> V_4 ) ;
F_40 ( V_77 ) ;
F_36 ( V_2 , V_77 ) ;
}
while ( ( V_77 = F_42 ( V_2 ) ) ) {
F_55 ( & V_2 -> V_39 -> V_20 , & V_77 -> V_4 ) ;
F_40 ( V_77 ) ;
F_36 ( V_2 , V_77 ) ;
}
V_2 -> V_106 = 0 ;
V_2 -> V_100 = 0 ;
F_20 ( & V_2 -> V_48 , V_46 ) ;
return 0 ;
}
void F_91 ( struct V_207 * V_208 , const int * V_209 ,
struct V_116 * V_39 )
{
int V_210 ;
int V_6 = 0 ;
struct V_1 * V_2 ;
F_32 ( & V_208 -> V_211 ) ;
for ( V_210 = 0 ; V_209 [ V_210 ] != - 1 ; V_210 += 2 ) {
for ( V_6 = V_209 [ V_210 ] ; V_6 <= V_209 [ V_210 + 1 ] ; V_6 ++ ) {
V_2 = & V_39 -> V_120 [ V_6 ] ;
V_2 -> V_39 = V_39 ;
V_2 -> V_37 . V_128 = V_208 ;
V_2 -> V_41 = V_6 ;
F_92 ( & V_2 -> V_48 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_100 = 0 ;
F_32 ( & V_2 -> free ) ;
F_32 ( & V_2 -> V_78 ) ;
F_32 ( & V_2 -> V_80 ) ;
F_93 ( & V_2 -> V_109 , F_53 ,
( unsigned long ) V_2 ) ;
F_37 ( & V_2 -> V_37 . V_212 ,
& V_208 -> V_211 ) ;
}
}
}
static int T_5 F_94 ( struct V_213 * V_214 )
{
int V_107 = 0 ;
struct V_215 * V_216 ;
struct V_116 * V_39 ;
int V_111 ;
struct V_217 * V_218 ;
V_218 = F_95 ( V_214 , V_219 , 0 ) ;
if ( ! V_218 )
return - V_220 ;
if ( F_96 ( & V_214 -> V_50 ,
V_218 -> V_221 ,
F_97 ( V_218 ) ,
V_214 -> V_50 . V_222 -> V_223 ) == NULL )
return - V_224 ;
V_216 = V_214 -> V_50 . V_225 ;
if ( ! V_216 )
return - V_220 ;
V_39 = F_98 ( & V_214 -> V_50 ,
F_99 ( sizeof( struct V_116 ) , 4 ) +
V_216 -> V_29 *
sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_39 )
return - V_224 ;
V_39 -> V_120 = ( ( void * ) V_39 ) + F_99 ( sizeof( struct V_116 ) , 4 ) ;
V_39 -> V_52 = F_100 ( & V_214 -> V_50 , V_218 -> V_221 , F_97 ( V_218 ) ) ;
if ( ! V_39 -> V_52 )
return - V_224 ;
V_39 -> V_50 = & V_214 -> V_50 ;
V_39 -> V_28 = V_216 ;
F_92 ( & V_39 -> V_18 . V_48 ) ;
V_39 -> V_18 . V_16 = 0 ;
F_101 ( V_17 , V_39 ) ;
V_111 = F_102 ( V_214 , 0 ) ;
if ( V_111 < 0 )
return V_111 ;
V_107 = F_103 ( & V_214 -> V_50 , V_111 , F_63 , V_226 ,
L_26 , V_39 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_104 ( & V_39 -> V_20 , & V_214 -> V_50 ,
sizeof( struct V_3 ) ,
32 ) ;
if ( V_107 )
return V_107 ;
F_91 ( & V_39 -> V_227 , V_39 -> V_28 -> V_228 ,
V_39 ) ;
F_105 ( V_39 -> V_227 . V_229 ) ;
F_106 ( V_230 , V_39 -> V_227 . V_229 ) ;
V_39 -> V_227 . V_231 = F_70 ;
V_39 -> V_227 . V_232 = F_72 ;
V_39 -> V_227 . V_233 = F_79 ;
V_39 -> V_227 . V_234 = F_84 ;
V_39 -> V_227 . V_235 = F_87 ;
V_39 -> V_227 . V_129 = F_90 ;
V_39 -> V_227 . V_50 = & V_214 -> V_50 ;
V_107 = F_107 ( & V_39 -> V_227 ) ;
if ( V_107 )
goto V_236;
F_91 ( & V_39 -> V_237 , V_39 -> V_28 -> V_238 ,
V_39 ) ;
F_105 ( V_39 -> V_237 . V_229 ) ;
F_106 ( V_239 , V_39 -> V_237 . V_229 ) ;
V_39 -> V_237 . V_231 = F_70 ;
V_39 -> V_237 . V_232 = F_72 ;
V_39 -> V_237 . V_240 = F_75 ;
V_39 -> V_237 . V_234 = F_84 ;
V_39 -> V_237 . V_235 = F_87 ;
V_39 -> V_237 . V_129 = F_90 ;
V_39 -> V_237 . V_50 = & V_214 -> V_50 ;
V_39 -> V_237 . V_241 = 2 ;
V_107 = F_107 ( & V_39 -> V_237 ) ;
if ( V_107 )
goto V_242;
F_108 ( V_214 , V_39 ) ;
F_109 ( & V_214 -> V_50 , L_27 ,
( T_8 ) V_39 -> V_52 ) ;
return V_107 ;
V_242:
F_110 ( & V_39 -> V_227 ) ;
V_236:
F_111 ( & V_39 -> V_20 ) ;
return V_107 ;
}
static int T_6 F_112 ( struct V_213 * V_214 )
{
struct V_116 * V_39 = F_113 ( V_214 ) ;
F_110 ( & V_39 -> V_237 ) ;
F_110 ( & V_39 -> V_227 ) ;
F_111 ( & V_39 -> V_20 ) ;
return 0 ;
}
int T_5 F_114 ( void )
{
return F_115 ( & V_243 , F_94 ) ;
}
void T_6 F_116 ( void )
{
F_117 ( & V_243 ) ;
}
