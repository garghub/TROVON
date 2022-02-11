static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_5 )
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_6 * V_7 , int V_8 )
{
if ( V_8 ) {
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_5 = V_4 -> V_5 ;
if ( V_5 && V_5 -> V_7 == V_7 ) {
V_5 -> V_7 = F_5 ( V_7 ) -> V_10 ;
F_6 ( V_5 -> V_7 ) ;
F_7 ( V_7 ) ;
}
}
}
static T_1 unsigned int F_8 ( T_2 V_11 , T_2 V_2 )
{
T_3 V_12 = ( T_3 V_13 ) ( V_11 ^ V_2 ) ;
V_12 ^= ( V_12 >> 3 ) ;
V_12 ^= ( V_12 >> 5 ) ;
V_12 ^= ( V_12 >> 10 ) ;
return V_14 & ( unsigned int ) V_12 ;
}
static inline void F_9 ( struct V_3 * V_4 )
{
F_10 ( & V_4 -> V_2 . V_15 , V_16 ) ;
}
static inline void F_11 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_2 ) ;
F_10 ( & V_4 -> V_2 . V_15 , V_16 ) ;
}
static void F_13 ( unsigned long V_17 )
{
int V_18 ;
struct V_3 * V_4 ;
struct V_3 T_4 * * V_19 ;
unsigned long V_20 = V_21 ;
unsigned long V_22 = 120 * V_23 ;
for ( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
V_19 = & V_24 [ V_18 ] . V_25 ;
F_14 ( & V_24 [ V_18 ] . V_26 ) ;
while ( ( V_4 = F_15 ( * V_19 ,
F_16 ( & V_24 [ V_18 ] . V_26 ) ) ) != NULL ) {
if ( F_17 ( & V_4 -> V_2 . V_27 ) ||
( V_20 - V_4 -> V_2 . V_28 ) < V_22 ) {
V_19 = & V_4 -> V_2 . V_29 ;
continue;
}
* V_19 = V_4 -> V_2 . V_29 ;
V_4 -> V_2 . V_29 = NULL ;
F_9 ( V_4 ) ;
}
F_18 ( & V_24 [ V_18 ] . V_26 ) ;
if ( ( V_21 - V_20 ) > 0 )
break;
}
F_19 ( & V_30 , V_20 + V_31 * V_23 ) ;
}
static int F_20 ( struct V_32 * V_33 )
{
struct V_3 * V_4 ;
struct V_3 T_4 * * V_19 ;
int V_18 ;
unsigned long V_20 = V_21 ;
unsigned long V_22 = 10 * V_23 ;
for ( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
F_21 ( & V_24 [ V_18 ] . V_26 ) ;
V_19 = & V_24 [ V_18 ] . V_25 ;
while ( ( V_4 = F_15 ( * V_19 ,
F_16 ( & V_24 [ V_18 ] . V_26 ) ) ) != NULL ) {
if ( F_17 ( & V_4 -> V_2 . V_27 ) ||
( V_20 - V_4 -> V_2 . V_28 ) < V_22 ) {
V_19 = & V_4 -> V_2 . V_29 ;
continue;
}
* V_19 = V_4 -> V_2 . V_29 ;
V_4 -> V_2 . V_29 = NULL ;
F_11 ( V_4 ) ;
break;
}
F_22 ( & V_24 [ V_18 ] . V_26 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 , T_5 V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_5 = V_4 -> V_5 ;
T_5 V_39 = 230 ;
struct V_40 * V_41 ;
V_41 = V_5 ? F_24 ( V_5 -> V_7 -> V_42 ) : NULL ;
if ( V_41 && V_41 -> V_43 == 0 )
V_39 -= 6 ;
else
V_39 -= 21 ;
if ( F_25 ( V_2 , V_44 ) > V_38 && V_38 >= V_39 ) {
if ( ! ( F_26 ( V_2 , V_44 ) ) ) {
F_27 ( V_2 , V_44 , V_38 ) ;
F_28 ( V_2 , V_45 ) ;
}
if ( ! ( F_26 ( V_2 , V_46 ) ) ) {
T_5 V_47 = V_38 - V_48 ;
T_5 V_49 = F_29 ( V_2 , V_46 ) ;
if ( ! V_49 || V_49 > V_47 )
F_27 ( V_2 , V_46 , V_47 ) ;
}
}
}
static void F_30 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 )
{
}
static struct V_1 * F_31 ( struct V_1 * V_2 , T_6 V_50 )
{
return NULL ;
}
static struct V_1 * F_32 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
return NULL ;
}
static void F_33 ( struct V_36 * V_37 )
{
}
static inline int F_34 ( struct V_51 * V_52 , struct V_51 * V_53 )
{
return ( ( V_52 -> V_54 ^ V_53 -> V_54 ) |
( V_52 -> V_55 ^ V_53 -> V_55 ) |
( V_52 -> V_56 ^ V_53 -> V_56 ) |
( V_52 -> V_57 ^ V_53 -> V_57 ) |
( V_52 -> V_58 ^ V_53 -> V_58 ) |
( V_52 -> V_59 ^ V_53 -> V_59 ) ) == 0 ;
}
static int F_35 ( struct V_3 * V_4 , unsigned int V_60 , struct V_3 * * V_61 )
{
struct V_3 * V_62 ;
struct V_3 T_4 * * V_63 ;
unsigned long V_20 = V_21 ;
V_63 = & V_24 [ V_60 ] . V_25 ;
F_21 ( & V_24 [ V_60 ] . V_26 ) ;
while ( ( V_62 = F_15 ( * V_63 ,
F_16 ( & V_24 [ V_60 ] . V_26 ) ) ) != NULL ) {
if ( F_34 ( & V_62 -> V_64 , & V_4 -> V_64 ) ) {
* V_63 = V_62 -> V_2 . V_29 ;
F_36 ( V_62 -> V_2 . V_29 ,
V_24 [ V_60 ] . V_25 ) ;
F_36 ( V_24 [ V_60 ] . V_25 , V_62 ) ;
F_37 ( & V_62 -> V_2 , V_20 ) ;
F_22 ( & V_24 [ V_60 ] . V_26 ) ;
F_11 ( V_4 ) ;
* V_61 = V_62 ;
return 0 ;
}
V_63 = & V_62 -> V_2 . V_29 ;
}
F_36 ( V_4 -> V_2 . V_29 , V_24 [ V_60 ] . V_25 ) ;
F_36 ( V_24 [ V_60 ] . V_25 , V_4 ) ;
F_37 ( & V_4 -> V_2 , V_20 ) ;
F_22 ( & V_24 [ V_60 ] . V_26 ) ;
* V_61 = V_4 ;
return 0 ;
}
static void F_38 ( unsigned long V_17 )
{
int V_18 ;
struct V_3 * V_4 , * V_65 ;
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
F_21 ( & V_24 [ V_18 ] . V_26 ) ;
if ( ( V_4 = F_39 ( (struct V_3 * * ) & V_24 [ V_18 ] . V_25 , NULL ) ) == NULL )
goto V_66;
for(; V_4 ; V_4 = V_65 ) {
V_65 = F_24 ( V_4 -> V_2 . V_29 ) ;
F_40 ( V_4 -> V_2 . V_29 , NULL ) ;
F_41 ( (struct V_1 * ) V_4 ) ;
}
V_66:
F_22 ( & V_24 [ V_18 ] . V_26 ) ;
}
}
void F_42 ( int V_67 )
{
unsigned long V_20 = V_21 ;
int V_68 = ! F_43 () ;
if ( V_67 < 0 )
V_67 = V_69 ;
F_21 ( & V_70 ) ;
if ( F_44 ( & V_71 ) && V_67 > 0 && V_72 ) {
long V_73 = ( long ) ( V_72 - V_20 ) ;
if ( V_68 && V_73 < V_74 - V_69 )
V_73 = 0 ;
if ( V_67 > V_73 )
V_67 = V_73 ;
}
if ( V_67 <= 0 ) {
F_22 ( & V_70 ) ;
F_38 ( 0 ) ;
return;
}
if ( V_72 == 0 )
V_72 = V_20 + V_74 ;
V_71 . V_75 = V_20 + V_67 ;
F_45 ( & V_71 ) ;
F_22 ( & V_70 ) ;
}
static int F_46 ( struct V_36 * V_37 )
{
struct V_76 * V_77 ;
unsigned char * V_78 ;
T_2 * V_11 ;
T_2 * V_2 ;
F_47 ( V_37 , V_37 -> V_79 - F_48 ( V_37 ) ) ;
if ( ( V_37 = F_49 ( V_37 , V_80 ) ) == NULL )
return V_81 ;
V_77 = F_50 ( V_37 ) ;
V_78 = V_37 -> V_79 + 2 ;
* V_78 ++ = ( V_77 -> V_82 & ~ V_83 ) | V_84 ;
V_2 = ( T_2 * ) V_78 ;
V_78 += 2 ;
V_11 = ( T_2 * ) V_78 ;
V_78 += 2 ;
* V_78 = 0 ;
F_51 ( * V_11 , * V_2 ) ;
V_37 -> V_85 = V_86 ;
F_52 ( V_37 , NULL , NULL ) ;
return V_87 ;
}
static int F_53 ( struct V_36 * V_37 )
{
struct V_76 * V_77 ;
unsigned char * V_78 ;
unsigned char * V_88 , * V_89 ;
unsigned char V_12 [ V_90 ] ;
F_47 ( V_37 , V_37 -> V_79 - F_48 ( V_37 ) ) ;
if ( ( V_37 = F_49 ( V_37 , V_80 ) ) == NULL )
return V_81 ;
V_77 = F_50 ( V_37 ) ;
V_78 = V_37 -> V_79 + 2 ;
if ( * V_78 & V_91 ) {
char V_92 = ( * V_78 & ~ V_91 ) ;
V_78 += V_92 ;
}
* V_78 ++ = ( V_77 -> V_82 & ~ V_83 ) | V_84 ;
V_78 += 2 ;
V_89 = V_78 ;
V_78 += 8 ;
V_88 = V_78 ;
V_78 += 6 ;
* V_78 = 0 ;
memcpy ( V_12 , V_88 , V_90 ) ;
memcpy ( V_88 , V_89 , V_90 ) ;
memcpy ( V_89 , V_12 , V_90 ) ;
V_37 -> V_85 = V_86 ;
F_52 ( V_37 , V_89 , V_88 ) ;
return V_87 ;
}
static int F_54 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_76 * V_77 ;
int V_93 ;
if ( ( V_93 = F_55 ( V_37 ) ) == 0 )
return F_56 ( V_37 ) ;
V_77 = F_50 ( V_37 ) ;
if ( V_94 & 4 ) {
char * V_95 = V_37 -> V_7 ? V_37 -> V_7 -> V_96 : L_1 ;
F_57 ( V_97
L_2 ,
( int ) V_77 -> V_82 , V_95 , V_37 -> V_98 ,
F_58 ( V_77 -> V_11 ) , F_58 ( V_77 -> V_2 ) ,
V_93 , V_37 -> V_85 ) ;
}
if ( ( V_37 -> V_85 == V_99 ) && ( V_77 -> V_82 & V_83 ) ) {
switch ( V_77 -> V_82 & V_100 ) {
case V_101 :
return F_46 ( V_37 ) ;
case V_102 :
return F_53 ( V_37 ) ;
}
}
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_60 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
unsigned char * V_78 = V_37 -> V_79 ;
if ( ! F_61 ( V_37 , 21 ) )
goto V_103;
F_62 ( V_37 , 20 ) ;
F_63 ( V_37 ) ;
V_78 += 2 ;
V_77 -> V_2 = F_64 ( V_78 ) ;
if ( memcmp ( V_78 , V_104 , 4 ) != 0 )
goto V_103;
V_78 += 6 ;
V_78 += 2 ;
V_77 -> V_11 = F_64 ( V_78 ) ;
if ( memcmp ( V_78 , V_104 , 4 ) != 0 )
goto V_103;
V_78 += 6 ;
V_78 ++ ;
V_77 -> V_105 = * V_78 ++ ;
return F_65 ( V_106 , V_107 , NULL , V_37 ,
V_37 -> V_7 , NULL ,
F_54 ) ;
V_103:
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_66 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
unsigned char * V_78 = V_37 -> V_79 ;
if ( ! F_61 ( V_37 , 6 ) )
goto V_103;
F_62 ( V_37 , 5 ) ;
F_63 ( V_37 ) ;
V_77 -> V_2 = * ( T_2 * ) V_78 ;
V_78 += 2 ;
V_77 -> V_11 = * ( T_2 * ) V_78 ;
V_78 += 2 ;
V_77 -> V_105 = * V_78 & 0x3f ;
return F_65 ( V_106 , V_107 , NULL , V_37 ,
V_37 -> V_7 , NULL ,
F_54 ) ;
V_103:
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_67 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
F_59 ( V_37 ) ;
return V_87 ;
}
static int F_68 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
F_69 ( V_37 ) ;
F_70 ( V_37 ) ;
return V_87 ;
}
int F_71 ( struct V_36 * V_37 , struct V_6 * V_7 , struct V_108 * V_109 , struct V_6 * V_110 )
{
struct V_76 * V_77 ;
unsigned char V_111 = 0 ;
T_3 V_98 = F_58 ( * ( T_2 * ) V_37 -> V_79 ) ;
struct V_40 * V_41 = F_72 ( V_7 -> V_42 ) ;
unsigned char V_92 = 0 ;
if ( ! F_73 ( F_5 ( V_7 ) , & V_112 ) )
goto V_113;
if ( V_41 == NULL )
goto V_113;
if ( ( V_37 = F_74 ( V_37 , V_80 ) ) == NULL )
goto V_114;
if ( ! F_61 ( V_37 , 3 ) )
goto V_113;
F_62 ( V_37 , 2 ) ;
if ( V_98 > V_37 -> V_98 )
goto V_113;
F_75 ( V_37 , V_98 ) ;
V_111 = * V_37 -> V_79 ;
V_77 = F_50 ( V_37 ) ;
V_77 -> V_115 = V_21 ;
V_77 -> V_116 = V_7 -> V_117 ;
if ( V_111 & V_91 ) {
V_92 = V_111 & ~ V_91 ;
if ( ! F_61 ( V_37 , V_92 + 1 ) )
goto V_113;
F_62 ( V_37 , V_92 ) ;
V_111 = * V_37 -> V_79 ;
}
F_76 ( V_37 ) ;
if ( V_111 & V_118 )
goto V_113;
V_77 -> V_82 = V_111 ;
if ( V_94 & 1 )
F_57 ( V_97
L_3 ,
( int ) V_111 , ( V_7 ) ? V_7 -> V_96 : L_1 , V_98 , V_37 -> V_98 ,
V_92 ) ;
if ( V_111 & V_119 ) {
if ( F_77 ( F_78 ( V_37 ) ) )
goto V_113;
switch ( V_111 & V_120 ) {
case V_121 :
F_79 ( V_37 ) ;
break;
case V_122 :
F_80 ( V_37 ) ;
break;
}
if ( V_41 -> V_123 . V_124 != V_125 )
goto V_113;
switch ( V_111 & V_120 ) {
case V_126 :
return F_65 ( V_106 , V_127 ,
NULL , V_37 , V_37 -> V_7 , NULL ,
F_68 ) ;
case V_128 :
case V_129 :
return F_65 ( V_106 , V_130 ,
NULL , V_37 , V_37 -> V_7 , NULL ,
F_67 ) ;
case V_131 :
return F_65 ( V_106 , V_127 ,
NULL , V_37 , V_37 -> V_7 , NULL ,
V_132 ) ;
case V_133 :
return F_65 ( V_106 , V_127 ,
NULL , V_37 , V_37 -> V_7 , NULL ,
V_134 ) ;
}
} else {
if ( V_41 -> V_123 . V_124 != V_125 )
goto V_113;
F_62 ( V_37 , 1 ) ;
switch ( V_111 & V_100 ) {
case V_102 :
return F_60 ( V_37 ) ;
case V_101 :
return F_66 ( V_37 ) ;
}
}
V_113:
F_59 ( V_37 ) ;
V_114:
return V_81 ;
}
static int F_81 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_82 ( V_37 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_76 * V_77 = F_50 ( V_37 ) ;
int V_93 = - V_135 ;
if ( V_4 -> V_5 == NULL )
goto error;
V_37 -> V_7 = V_7 ;
V_77 -> V_11 = V_4 -> V_136 ;
V_77 -> V_2 = V_4 -> V_137 ;
V_77 -> V_82 &= ~ V_83 ;
V_77 -> V_82 |= V_138 ;
V_77 -> V_105 = 0 ;
return F_65 ( V_106 , V_139 , V_35 , V_37 ,
NULL , V_7 ,
V_140 ) ;
error:
F_83 ( L_4 ) ;
F_59 ( V_37 ) ;
return V_93 ;
}
static int F_84 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
struct V_1 * V_2 = F_82 ( V_37 ) ;
struct V_40 * V_141 = F_72 ( V_2 -> V_7 -> V_42 ) ;
struct V_3 * V_4 ;
int V_142 ;
#ifdef F_85
struct V_6 * V_7 = V_37 -> V_7 ;
#endif
if ( V_37 -> V_85 != V_99 )
goto V_143;
V_4 = (struct V_3 * ) F_82 ( V_37 ) ;
V_142 = V_141 -> V_43 ? 21 : 6 ;
if ( F_86 ( V_37 , F_87 ( V_4 -> V_2 . V_7 ) + V_142 ) )
goto V_143;
if ( ++ V_77 -> V_105 > 30 )
goto V_143;
V_37 -> V_7 = V_4 -> V_2 . V_7 ;
V_77 -> V_82 &= ~ V_138 ;
if ( V_4 -> V_82 & V_144 )
V_77 -> V_82 |= V_138 ;
return F_65 ( V_106 , V_145 , NULL , V_37 ,
V_7 , V_37 -> V_7 ,
V_140 ) ;
V_143:
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_88 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
F_83 ( L_5 ,
F_58 ( V_77 -> V_11 ) , F_58 ( V_77 -> V_2 ) ) ;
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_89 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
F_83 ( L_5 ,
F_58 ( V_77 -> V_11 ) , F_58 ( V_77 -> V_2 ) ) ;
F_59 ( V_37 ) ;
return V_81 ;
}
static unsigned int F_90 ( const struct V_1 * V_2 )
{
return F_91 ( V_2 -> V_7 , F_92 ( V_2 ) ) ;
}
static unsigned int F_93 ( const struct V_1 * V_2 )
{
unsigned int V_38 = F_29 ( V_2 , V_44 ) ;
return V_38 ? : V_2 -> V_7 -> V_38 ;
}
static struct V_9 * F_94 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const void * V_54 )
{
return F_95 ( & V_146 , V_54 , V_2 -> V_7 ) ;
}
static int F_96 ( struct V_3 * V_4 , struct V_147 * V_148 )
{
struct V_149 * V_150 = V_148 -> V_150 ;
struct V_6 * V_7 = V_4 -> V_2 . V_7 ;
unsigned int V_151 ;
struct V_9 * V_5 ;
if ( V_150 ) {
if ( F_97 ( * V_148 ) &&
F_98 ( * V_148 ) . V_152 == V_153 )
V_4 -> V_154 = F_97 ( * V_148 ) ;
F_99 ( & V_4 -> V_2 , V_150 -> V_155 , true ) ;
}
V_4 -> V_156 = V_148 -> type ;
if ( V_7 != NULL && V_4 -> V_5 == NULL ) {
V_5 = F_95 ( & V_146 , & V_4 -> V_154 , V_7 ) ;
if ( F_100 ( V_5 ) )
return F_101 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
}
if ( F_25 ( & V_4 -> V_2 , V_44 ) > V_4 -> V_2 . V_7 -> V_38 )
F_27 ( & V_4 -> V_2 , V_44 , V_4 -> V_2 . V_7 -> V_38 ) ;
V_151 = F_29 ( & V_4 -> V_2 , V_46 ) ;
if ( V_151 ) {
unsigned int V_47 = F_91 ( V_7 , F_92 ( & V_4 -> V_2 ) ) ;
if ( V_151 > V_47 )
F_27 ( & V_4 -> V_2 , V_46 , V_47 ) ;
}
return 0 ;
}
static inline int F_102 ( T_2 V_157 , T_2 V_158 )
{
T_3 V_12 = F_58 ( V_157 ) ^ F_58 ( V_158 ) ;
int V_159 = 16 ;
while( V_12 ) {
V_12 >>= 1 ;
V_159 -- ;
}
return V_159 ;
}
static T_2 F_103 ( const struct V_6 * V_7 , T_2 V_54 , int V_160 )
{
T_2 V_55 = 0 ;
struct V_40 * V_141 ;
struct V_161 * V_162 ;
int V_163 = 0 ;
int V_164 ;
F_104 () ;
V_141 = F_72 ( V_7 -> V_42 ) ;
for ( V_162 = F_72 ( V_141 -> V_165 ) ;
V_162 != NULL ;
V_162 = F_72 ( V_162 -> V_166 ) ) {
if ( V_162 -> V_167 > V_160 )
continue;
if ( ! V_54 ) {
V_55 = V_162 -> V_168 ;
break;
}
V_164 = F_102 ( V_54 , V_162 -> V_168 ) ;
if ( V_164 > V_163 )
V_55 = V_162 -> V_168 ;
if ( V_163 == 0 )
V_55 = V_162 -> V_168 ;
}
F_105 () ;
return V_55 ;
}
static inline T_2 F_106 ( struct V_147 * V_148 )
{
return F_103 ( F_107 ( * V_148 ) , F_97 ( * V_148 ) , V_148 -> V_160 ) ;
}
static inline T_2 F_108 ( T_2 V_54 , struct V_147 * V_148 )
{
T_2 V_169 = F_109 ( V_148 -> V_170 ) ;
return ( V_54 & ~ V_169 ) | V_148 -> V_150 -> V_171 -> V_172 ;
}
static int F_110 ( struct V_1 * * V_173 , const struct V_51 * V_174 , int V_175 )
{
struct V_51 V_64 = {
. V_54 = V_174 -> V_54 ,
. V_55 = V_174 -> V_55 ,
. V_57 = V_176 ,
. V_56 = V_174 -> V_56 ,
. V_59 = V_177 ,
. V_58 = V_174 -> V_58 ,
} ;
struct V_3 * V_4 = NULL ;
struct V_6 * V_178 = NULL , * V_7 ;
struct V_9 * V_179 = NULL ;
unsigned int V_60 ;
unsigned int V_111 = 0 ;
struct V_147 V_148 = { . V_150 = NULL , . type = V_180 } ;
int V_93 ;
int V_181 = 0 ;
T_2 V_182 = 0 ;
if ( V_94 & 16 )
F_57 ( V_97
L_6
L_7 , F_58 ( V_174 -> V_54 ) ,
F_58 ( V_174 -> V_55 ) ,
V_174 -> V_56 , V_177 ,
V_174 -> V_58 ) ;
if ( V_174 -> V_58 ) {
V_178 = F_111 ( & V_112 , V_174 -> V_58 ) ;
V_93 = - V_183 ;
if ( V_178 && V_178 -> V_42 == NULL ) {
F_7 ( V_178 ) ;
V_178 = NULL ;
}
if ( V_178 == NULL )
goto V_114;
}
if ( V_174 -> V_55 ) {
V_93 = - V_184 ;
if ( V_178 ) {
if ( F_112 ( V_178 , V_174 -> V_55 ) )
goto V_185;
F_7 ( V_178 ) ;
goto V_114;
}
F_104 () ;
F_113 (&init_net, dev) {
if ( ! V_7 -> V_42 )
continue;
if ( ! F_112 ( V_7 , V_174 -> V_55 ) )
continue;
if ( ( V_7 -> V_111 & V_186 ) &&
V_174 -> V_54 &&
! F_112 ( V_7 , V_174 -> V_54 ) )
continue;
V_178 = V_7 ;
break;
}
F_105 () ;
if ( V_178 == NULL )
goto V_114;
F_6 ( V_178 ) ;
V_185:
;
}
if ( ! V_64 . V_54 ) {
V_64 . V_54 = V_64 . V_55 ;
V_93 = - V_184 ;
if ( V_178 )
F_7 ( V_178 ) ;
V_178 = V_112 . V_10 ;
F_6 ( V_178 ) ;
if ( ! V_64 . V_54 ) {
V_64 . V_54 =
V_64 . V_55 = F_103 ( V_178 , 0 ,
V_187 ) ;
if ( ! V_64 . V_54 )
goto V_114;
}
V_64 . V_58 = V_177 ;
V_148 . type = V_188 ;
goto V_189;
}
if ( V_94 & 16 )
F_57 ( V_97
L_8
L_9 ,
F_58 ( V_64 . V_54 ) , F_58 ( V_64 . V_55 ) ,
V_64 . V_58 , V_175 ) ;
V_93 = - V_190 ;
if ( V_175 || ( V_93 = F_114 ( & V_64 , & V_148 ) ) != 0 ) {
struct V_40 * V_141 ;
if ( V_93 != - V_190 )
goto V_114;
if ( ! V_175 ) {
V_179 = F_115 ( & V_146 , & V_112 , & V_64 . V_54 ) ;
if ( V_179 ) {
if ( ( V_174 -> V_58 &&
( V_179 -> V_7 -> V_117 != V_174 -> V_58 ) ) ||
( V_174 -> V_55 &&
( ! F_112 ( V_179 -> V_7 ,
V_174 -> V_55 ) ) ) ) {
F_2 ( V_179 ) ;
V_179 = NULL ;
} else {
if ( V_178 )
F_7 ( V_178 ) ;
if ( F_112 ( V_179 -> V_7 , V_64 . V_54 ) ) {
V_178 = V_112 . V_10 ;
V_148 . type = V_188 ;
} else {
V_178 = V_179 -> V_7 ;
}
F_6 ( V_178 ) ;
goto V_191;
}
}
}
if ( V_178 == NULL )
V_178 = F_116 () ;
V_93 = - V_183 ;
if ( V_178 == NULL )
goto V_114;
V_141 = F_24 ( V_178 -> V_42 ) ;
if ( F_112 ( V_178 , V_64 . V_54 ) ) {
F_7 ( V_178 ) ;
V_178 = V_112 . V_10 ;
F_6 ( V_178 ) ;
V_148 . type = V_188 ;
goto V_191;
}
V_179 = F_117 ( V_141 -> V_192 ) ;
F_118 ( V_179 && V_179 -> V_7 != V_178 ) ;
V_191:
if ( V_179 )
V_182 = ( (struct V_193 * ) V_179 ) -> V_194 ;
if ( V_182 == 0 )
V_182 = V_64 . V_54 ;
if ( V_64 . V_55 == 0 ) {
V_64 . V_55 = F_103 ( V_178 , V_182 ,
V_148 . type == V_188 ?
V_187 :
V_153 ) ;
if ( V_64 . V_55 == 0 && V_148 . type != V_188 )
goto V_195;
}
V_64 . V_58 = V_178 -> V_117 ;
goto V_189;
}
V_181 = 1 ;
if ( V_148 . type == V_196 )
goto V_197;
if ( V_148 . type == V_188 ) {
if ( ! V_64 . V_55 )
V_64 . V_55 = V_64 . V_54 ;
if ( V_178 )
F_7 ( V_178 ) ;
V_178 = V_112 . V_10 ;
F_6 ( V_178 ) ;
V_64 . V_58 = V_178 -> V_117 ;
if ( V_148 . V_150 )
F_119 ( V_148 . V_150 ) ;
V_148 . V_150 = NULL ;
goto V_189;
}
if ( V_148 . V_150 -> V_198 > 1 && V_64 . V_58 == 0 )
F_120 ( & V_64 , & V_148 ) ;
if ( ! V_64 . V_55 )
V_64 . V_55 = F_121 ( V_148 ) ;
if ( V_178 )
F_7 ( V_178 ) ;
V_178 = F_107 ( V_148 ) ;
F_6 ( V_178 ) ;
V_64 . V_58 = V_178 -> V_117 ;
V_182 = F_97 ( V_148 ) ;
V_189:
if ( V_178 -> V_111 & V_186 )
V_111 |= V_199 ;
V_4 = F_122 ( & V_200 , V_178 , 1 , V_201 , V_202 ) ;
if ( V_4 == NULL )
goto V_203;
memset ( & V_4 -> V_64 , 0 , sizeof( V_4 -> V_64 ) ) ;
V_4 -> V_64 . V_55 = V_174 -> V_55 ;
V_4 -> V_64 . V_54 = V_174 -> V_54 ;
V_4 -> V_64 . V_58 = V_174 -> V_58 ;
V_4 -> V_64 . V_59 = 0 ;
V_4 -> V_64 . V_56 = V_174 -> V_56 ;
V_4 -> V_136 = V_64 . V_55 ;
V_4 -> V_137 = V_64 . V_54 ;
V_4 -> V_154 = V_182 ? V_182 : V_64 . V_54 ;
V_4 -> V_204 = V_64 . V_55 ;
V_4 -> V_205 = V_64 . V_54 ;
V_4 -> V_206 = V_64 . V_55 ;
V_4 -> V_5 = V_179 ;
V_179 = NULL ;
V_4 -> V_2 . V_28 = V_21 ;
V_4 -> V_2 . V_207 = F_81 ;
V_4 -> V_2 . V_208 = F_89 ;
V_4 -> V_82 = V_111 ;
if ( V_111 & V_199 )
V_4 -> V_2 . V_208 = V_209 ;
V_93 = F_96 ( V_4 , & V_148 ) ;
if ( V_93 )
goto V_210;
V_60 = F_8 ( V_4 -> V_64 . V_55 , V_4 -> V_64 . V_54 ) ;
F_35 ( V_4 , V_60 , (struct V_3 * * ) V_173 ) ;
V_211:
if ( V_179 )
F_2 ( V_179 ) ;
if ( V_181 )
F_123 ( & V_148 ) ;
if ( V_178 )
F_7 ( V_178 ) ;
V_114:
return V_93 ;
V_195:
V_93 = - V_184 ;
goto V_211;
V_197:
V_93 = - V_135 ;
goto V_211;
V_203:
V_93 = - V_212 ;
goto V_211;
V_210:
F_41 ( & V_4 -> V_2 ) ;
goto V_203;
}
static int F_124 ( struct V_1 * * V_173 , const struct V_51 * V_213 , int V_111 )
{
unsigned int V_60 = F_8 ( V_213 -> V_55 , V_213 -> V_54 ) ;
struct V_3 * V_4 = NULL ;
if ( ! ( V_111 & V_214 ) ) {
F_125 () ;
for ( V_4 = F_126 ( V_24 [ V_60 ] . V_25 ) ; V_4 ;
V_4 = F_126 ( V_4 -> V_2 . V_29 ) ) {
if ( ( V_213 -> V_54 == V_4 -> V_64 . V_54 ) &&
( V_213 -> V_55 == V_4 -> V_64 . V_55 ) &&
( V_213 -> V_56 == V_4 -> V_64 . V_56 ) &&
F_127 ( V_4 ) &&
( V_4 -> V_64 . V_58 == V_213 -> V_58 ) ) {
F_37 ( & V_4 -> V_2 , V_21 ) ;
F_128 () ;
* V_173 = & V_4 -> V_2 ;
return 0 ;
}
}
F_128 () ;
}
return F_110 ( V_173 , V_213 , V_111 ) ;
}
static int F_129 ( struct V_1 * * V_173 , struct V_51 * V_213 , int V_111 )
{
int V_93 ;
V_93 = F_124 ( V_173 , V_213 , V_111 ) ;
if ( V_93 == 0 && V_213 -> V_215 ) {
* V_173 = F_130 ( & V_112 , * V_173 ,
F_131 ( V_213 ) , NULL , 0 ) ;
if ( F_100 ( * V_173 ) ) {
V_93 = F_101 ( * V_173 ) ;
* V_173 = NULL ;
}
}
return V_93 ;
}
int F_132 ( struct V_1 T_4 * * V_173 , struct V_51 * V_216 , struct V_34 * V_35 , int V_111 )
{
int V_93 ;
V_93 = F_124 ( V_173 , V_216 , V_111 & V_214 ) ;
if ( V_93 == 0 && V_216 -> V_215 ) {
* V_173 = F_130 ( & V_112 , * V_173 ,
F_131 ( V_216 ) , V_35 , 0 ) ;
if ( F_100 ( * V_173 ) ) {
V_93 = F_101 ( * V_173 ) ;
* V_173 = NULL ;
}
}
return V_93 ;
}
static int F_133 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = NULL ;
struct V_76 * V_77 = F_50 ( V_37 ) ;
struct V_6 * V_217 = V_37 -> V_7 ;
struct V_6 * V_218 = NULL ;
struct V_40 * V_141 ;
struct V_9 * V_179 = NULL ;
unsigned int V_60 ;
int V_111 = 0 ;
T_2 V_182 = 0 ;
T_2 V_219 = 0 ;
struct V_51 V_64 = {
. V_54 = V_77 -> V_2 ,
. V_55 = V_77 -> V_11 ,
. V_57 = V_176 ,
. V_56 = V_37 -> V_220 ,
. V_59 = V_37 -> V_7 -> V_117 ,
} ;
struct V_147 V_148 = { . V_150 = NULL , . type = V_221 } ;
int V_93 = - V_135 ;
int V_181 = 0 ;
F_6 ( V_217 ) ;
if ( ( V_141 = F_72 ( V_217 -> V_42 ) ) == NULL )
goto V_114;
if ( V_64 . V_55 == 0 )
goto V_114;
V_93 = - V_222 ;
if ( F_112 ( V_217 , V_77 -> V_11 ) )
goto V_114;
V_93 = F_114 ( & V_64 , & V_148 ) ;
if ( V_93 ) {
if ( V_93 != - V_190 )
goto V_114;
if ( ! F_112 ( V_217 , V_77 -> V_2 ) )
goto V_197;
V_148 . type = V_188 ;
} else {
T_2 V_223 = V_64 . V_55 ;
V_181 = 1 ;
V_218 = F_107 ( V_148 ) ;
if ( V_218 == NULL ) {
F_134 ( L_10 ) ;
goto V_197;
}
F_6 ( V_218 ) ;
if ( V_148 . V_224 )
V_223 = V_64 . V_55 ;
V_182 = F_97 ( V_148 ) ;
if ( V_148 . type == V_196 ) {
V_64 . V_54 = F_108 ( V_64 . V_54 , & V_148 ) ;
F_123 ( & V_148 ) ;
V_181 = 0 ;
if ( F_114 ( & V_64 , & V_148 ) )
goto V_197;
V_181 = 1 ;
if ( V_148 . type != V_180 )
goto V_197;
V_111 |= V_225 ;
V_182 = V_64 . V_54 ;
}
V_64 . V_55 = V_223 ;
}
switch( V_148 . type ) {
case V_180 :
if ( V_141 -> V_123 . V_226 == 0 )
goto V_197;
if ( V_148 . V_150 -> V_198 > 1 && V_64 . V_58 == 0 )
F_120 ( & V_64 , & V_148 ) ;
if ( V_218 == V_217 && ! ( V_111 & V_227 ) )
V_111 |= V_144 ;
V_219 = F_121 ( V_148 ) ;
case V_228 :
case V_221 :
break;
case V_188 :
V_111 |= V_199 ;
V_64 . V_55 = V_77 -> V_2 ;
V_64 . V_54 = V_77 -> V_11 ;
if ( V_182 )
goto V_189;
if ( V_77 -> V_82 & V_138 ) {
V_182 = V_77 -> V_11 ;
goto V_189;
}
V_179 = F_117 ( V_141 -> V_192 ) ;
if ( V_179 ) {
V_182 = ( (struct V_193 * ) V_179 ) -> V_194 ;
goto V_189;
}
V_182 = V_77 -> V_11 ;
goto V_189;
default:
goto V_197;
}
V_189:
V_4 = F_122 ( & V_200 , V_218 , 0 , V_201 , V_202 ) ;
if ( V_4 == NULL )
goto V_203;
memset ( & V_4 -> V_64 , 0 , sizeof( V_4 -> V_64 ) ) ;
V_4 -> V_136 = V_64 . V_55 ;
V_4 -> V_137 = V_64 . V_54 ;
V_4 -> V_154 = V_64 . V_54 ;
if ( V_182 )
V_4 -> V_154 = V_182 ;
V_4 -> V_204 = V_219 ? V_219 : V_4 -> V_136 ;
V_4 -> V_205 = V_64 . V_54 ;
V_4 -> V_206 = V_64 . V_55 ;
V_4 -> V_64 . V_55 = V_77 -> V_11 ;
V_4 -> V_64 . V_54 = V_77 -> V_2 ;
V_4 -> V_64 . V_58 = 0 ;
V_4 -> V_64 . V_59 = V_217 -> V_117 ;
V_4 -> V_64 . V_56 = V_64 . V_56 ;
V_4 -> V_5 = V_179 ;
V_4 -> V_2 . V_28 = V_21 ;
V_4 -> V_2 . V_207 = F_88 ;
switch ( V_148 . type ) {
case V_180 :
V_4 -> V_2 . V_208 = F_84 ;
break;
case V_188 :
V_4 -> V_2 . V_207 = F_81 ;
V_4 -> V_2 . V_208 = V_209 ;
V_4 -> V_2 . V_7 = V_217 ;
V_111 |= V_199 ;
break;
default:
case V_221 :
case V_228 :
V_4 -> V_2 . V_208 = V_229 ;
}
V_4 -> V_82 = V_111 ;
V_93 = F_96 ( V_4 , & V_148 ) ;
if ( V_93 )
goto V_210;
V_60 = F_8 ( V_4 -> V_64 . V_55 , V_4 -> V_64 . V_54 ) ;
F_35 ( V_4 , V_60 , & V_4 ) ;
F_135 ( V_37 , & V_4 -> V_2 ) ;
V_211:
if ( V_179 )
F_2 ( V_179 ) ;
if ( V_181 )
F_123 ( & V_148 ) ;
F_7 ( V_217 ) ;
if ( V_218 )
F_7 ( V_218 ) ;
V_114:
return V_93 ;
V_197:
V_93 = - V_135 ;
goto V_211;
V_203:
V_93 = - V_212 ;
goto V_211;
V_210:
F_41 ( & V_4 -> V_2 ) ;
goto V_211;
}
static int F_55 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_76 * V_77 = F_50 ( V_37 ) ;
unsigned int V_60 = F_8 ( V_77 -> V_11 , V_77 -> V_2 ) ;
if ( F_82 ( V_37 ) )
return 0 ;
F_104 () ;
for( V_4 = F_72 ( V_24 [ V_60 ] . V_25 ) ; V_4 != NULL ;
V_4 = F_72 ( V_4 -> V_2 . V_29 ) ) {
if ( ( V_4 -> V_64 . V_55 == V_77 -> V_11 ) &&
( V_4 -> V_64 . V_54 == V_77 -> V_2 ) &&
( V_4 -> V_64 . V_58 == 0 ) &&
( V_4 -> V_64 . V_56 == V_37 -> V_220 ) &&
( V_4 -> V_64 . V_59 == V_77 -> V_116 ) ) {
F_37 ( & V_4 -> V_2 , V_21 ) ;
F_105 () ;
F_135 ( V_37 , (struct V_1 * ) V_4 ) ;
return 0 ;
}
}
F_105 () ;
return F_133 ( V_37 ) ;
}
static int F_136 ( struct V_36 * V_37 , T_5 V_230 , T_5 V_231 ,
int V_232 , int V_233 , unsigned int V_111 )
{
struct V_3 * V_4 = (struct V_3 * ) F_82 ( V_37 ) ;
struct V_234 * V_224 ;
struct V_235 * V_236 ;
long V_75 ;
V_236 = F_137 ( V_37 , V_230 , V_231 , V_232 , sizeof( * V_224 ) , V_111 ) ;
if ( ! V_236 )
return - V_237 ;
V_224 = F_138 ( V_236 ) ;
V_224 -> V_238 = V_239 ;
V_224 -> V_240 = 16 ;
V_224 -> V_241 = 0 ;
V_224 -> V_242 = 0 ;
V_224 -> V_243 = V_244 ;
V_224 -> V_245 = V_4 -> V_156 ;
V_224 -> V_246 = ( V_4 -> V_82 & ~ 0xFFFF ) | V_247 ;
V_224 -> V_248 = V_176 ;
V_224 -> V_249 = V_250 ;
if ( V_4 -> V_82 & V_251 )
V_224 -> V_246 |= V_252 ;
if ( F_139 ( V_37 , V_253 , V_244 ) < 0 ||
F_140 ( V_37 , V_254 , V_4 -> V_137 ) < 0 )
goto V_255;
if ( V_4 -> V_64 . V_55 ) {
V_224 -> V_241 = 16 ;
if ( F_140 ( V_37 , V_256 , V_4 -> V_64 . V_55 ) < 0 )
goto V_255;
}
if ( V_4 -> V_2 . V_7 &&
F_139 ( V_37 , V_257 , V_4 -> V_2 . V_7 -> V_117 ) < 0 )
goto V_255;
if ( F_140 ( V_37 , V_258 , V_4 -> V_204 ) < 0 )
goto V_255;
if ( V_4 -> V_137 != V_4 -> V_154 &&
F_140 ( V_37 , V_259 , V_4 -> V_154 ) < 0 )
goto V_255;
if ( F_141 ( V_37 , F_142 ( & V_4 -> V_2 ) ) < 0 )
goto V_255;
V_75 = V_4 -> V_2 . V_75 ? V_4 -> V_2 . V_75 - V_21 : 0 ;
if ( F_143 ( V_37 , & V_4 -> V_2 , 0 , V_75 ,
V_4 -> V_2 . error ) < 0 )
goto V_255;
if ( F_144 ( V_4 ) &&
F_139 ( V_37 , V_260 , V_4 -> V_64 . V_59 ) < 0 )
goto V_255;
F_145 ( V_37 , V_236 ) ;
return 0 ;
V_255:
F_146 ( V_37 , V_236 ) ;
return - V_237 ;
}
static int F_147 ( struct V_36 * V_261 , struct V_235 * V_236 )
{
struct V_262 * V_262 = F_148 ( V_261 -> V_35 ) ;
struct V_234 * V_263 = F_138 ( V_236 ) ;
struct V_3 * V_4 = NULL ;
struct V_76 * V_77 ;
int V_93 ;
struct V_36 * V_37 ;
struct V_51 V_64 ;
struct V_264 * V_265 [ V_266 + 1 ] ;
if ( ! F_73 ( V_262 , & V_112 ) )
return - V_135 ;
V_93 = F_149 ( V_236 , sizeof( * V_263 ) , V_265 , V_266 , V_267 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_215 = V_268 ;
V_37 = F_150 ( V_269 , V_270 ) ;
if ( V_37 == NULL )
return - V_212 ;
F_151 ( V_37 ) ;
V_77 = F_50 ( V_37 ) ;
if ( V_265 [ V_256 ] )
V_64 . V_55 = F_152 ( V_265 [ V_256 ] ) ;
if ( V_265 [ V_254 ] )
V_64 . V_54 = F_152 ( V_265 [ V_254 ] ) ;
if ( V_265 [ V_260 ] )
V_64 . V_59 = F_153 ( V_265 [ V_260 ] ) ;
if ( V_64 . V_59 ) {
struct V_6 * V_7 ;
V_7 = F_154 ( & V_112 , V_64 . V_59 ) ;
if ( ! V_7 || ! V_7 -> V_42 ) {
F_59 ( V_37 ) ;
return - V_183 ;
}
V_37 -> V_271 = F_155 ( V_272 ) ;
V_37 -> V_7 = V_7 ;
V_77 -> V_11 = V_64 . V_55 ;
V_77 -> V_2 = V_64 . V_54 ;
F_156 () ;
V_93 = F_55 ( V_37 ) ;
F_157 () ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_4 = (struct V_3 * ) F_82 ( V_37 ) ;
if ( ! V_93 && - V_4 -> V_2 . error )
V_93 = V_4 -> V_2 . error ;
} else {
if ( V_265 [ V_257 ] )
V_64 . V_58 = F_153 ( V_265 [ V_257 ] ) ;
V_93 = F_129 ( (struct V_1 * * ) & V_4 , & V_64 , 0 ) ;
}
V_37 -> V_7 = NULL ;
if ( V_93 )
goto V_273;
F_135 ( V_37 , & V_4 -> V_2 ) ;
if ( V_263 -> V_246 & V_252 )
V_4 -> V_82 |= V_251 ;
V_93 = F_136 ( V_37 , F_158 ( V_261 ) . V_230 , V_236 -> V_274 , V_275 , 0 , 0 ) ;
if ( V_93 < 0 ) {
V_93 = - V_237 ;
goto V_273;
}
return F_159 ( V_37 , & V_112 , F_158 ( V_261 ) . V_230 ) ;
V_273:
F_59 ( V_37 ) ;
return V_93 ;
}
int F_160 ( struct V_36 * V_37 , struct V_276 * V_77 )
{
struct V_262 * V_262 = F_148 ( V_37 -> V_35 ) ;
struct V_3 * V_4 ;
int V_277 , V_278 ;
int V_279 , V_280 ;
struct V_234 * V_263 ;
if ( ! F_73 ( V_262 , & V_112 ) )
return 0 ;
if ( F_161 ( V_77 -> V_236 ) < sizeof( struct V_234 ) )
return - V_135 ;
V_263 = F_138 ( V_77 -> V_236 ) ;
if ( ! ( V_263 -> V_246 & V_247 ) )
return 0 ;
V_278 = V_77 -> args [ 0 ] ;
V_280 = V_279 = V_77 -> args [ 1 ] ;
for( V_277 = 0 ; V_277 <= V_14 ; V_277 ++ ) {
if ( V_277 < V_278 )
continue;
if ( V_277 > V_278 )
V_280 = 0 ;
F_125 () ;
for( V_4 = F_126 ( V_24 [ V_277 ] . V_25 ) , V_279 = 0 ;
V_4 ;
V_4 = F_126 ( V_4 -> V_2 . V_29 ) , V_279 ++ ) {
if ( V_279 < V_280 )
continue;
F_135 ( V_37 , F_162 ( & V_4 -> V_2 ) ) ;
if ( F_136 ( V_37 , F_158 ( V_77 -> V_37 ) . V_230 ,
V_77 -> V_236 -> V_274 , V_275 ,
1 , V_281 ) < 0 ) {
F_163 ( V_37 ) ;
F_128 () ;
goto V_211;
}
F_163 ( V_37 ) ;
}
F_128 () ;
}
V_211:
V_77 -> args [ 0 ] = V_277 ;
V_77 -> args [ 1 ] = V_279 ;
return V_37 -> V_98 ;
}
static struct V_3 * F_164 ( struct V_282 * V_231 )
{
struct V_3 * V_4 = NULL ;
struct V_283 * V_284 = V_231 -> V_285 ;
for( V_284 -> V_286 = V_14 ; V_284 -> V_286 >= 0 ; -- V_284 -> V_286 ) {
F_125 () ;
V_4 = F_126 ( V_24 [ V_284 -> V_286 ] . V_25 ) ;
if ( V_4 )
break;
F_128 () ;
}
return V_4 ;
}
static struct V_3 * F_165 ( struct V_282 * V_231 , struct V_3 * V_4 )
{
struct V_283 * V_284 = V_231 -> V_285 ;
V_4 = F_126 ( V_4 -> V_2 . V_29 ) ;
while ( ! V_4 ) {
F_128 () ;
if ( -- V_284 -> V_286 < 0 )
break;
F_125 () ;
V_4 = F_126 ( V_24 [ V_284 -> V_286 ] . V_25 ) ;
}
return V_4 ;
}
static void * F_166 ( struct V_282 * V_231 , T_7 * V_287 )
{
struct V_3 * V_4 = F_164 ( V_231 ) ;
if ( V_4 ) {
while( * V_287 && ( V_4 = F_165 ( V_231 , V_4 ) ) )
-- * V_287 ;
}
return * V_287 ? NULL : V_4 ;
}
static void * F_167 ( struct V_282 * V_231 , void * V_288 , T_7 * V_287 )
{
struct V_3 * V_4 = F_165 ( V_231 , V_288 ) ;
++ * V_287 ;
return V_4 ;
}
static void F_168 ( struct V_282 * V_231 , void * V_288 )
{
if ( V_288 )
F_128 () ;
}
static int F_169 ( struct V_282 * V_231 , void * V_288 )
{
struct V_3 * V_4 = V_288 ;
char V_289 [ V_290 ] , V_291 [ V_290 ] ;
F_170 ( V_231 , L_11 ,
V_4 -> V_2 . V_7 ? V_4 -> V_2 . V_7 -> V_96 : L_12 ,
F_171 ( F_58 ( V_4 -> V_137 ) , V_289 ) ,
F_171 ( F_58 ( V_4 -> V_136 ) , V_291 ) ,
F_17 ( & V_4 -> V_2 . V_27 ) ,
V_4 -> V_2 . V_292 , 0 ) ;
return 0 ;
}
static int F_172 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_173 ( V_294 , & V_295 ,
sizeof( struct V_283 ) ) ;
}
void T_8 F_174 ( void )
{
int V_18 , V_296 , V_297 ;
V_200 . V_298 =
F_175 ( L_13 , sizeof( struct V_3 ) , 0 ,
V_299 | V_300 , NULL ) ;
F_176 ( & V_200 ) ;
F_177 ( & V_30 , F_13 , 0 ) ;
V_30 . V_75 = V_21 + V_31 * V_23 ;
F_45 ( & V_30 ) ;
V_296 = V_301 >> ( 26 - V_302 ) ;
for( V_297 = 0 ; ( 1UL << V_297 ) < V_296 ; V_297 ++ )
;
while( V_297 && ( ( ( ( 1UL << V_297 ) * V_303 ) /
sizeof( struct V_304 ) ) >= 2048 ) )
V_297 -- ;
do {
V_14 = ( 1UL << V_297 ) * V_303 /
sizeof( struct V_304 ) ;
while( V_14 & ( V_14 - 1 ) )
V_14 -- ;
V_24 = (struct V_304 * )
F_178 ( V_80 , V_297 ) ;
} while ( V_24 == NULL && -- V_297 > 0 );
if ( ! V_24 )
F_179 ( L_14 ) ;
F_57 ( V_305
L_15 ,
V_14 ,
( long ) ( V_14 * sizeof( struct V_304 ) ) / 1024 ) ;
V_14 -- ;
for( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
F_180 ( & V_24 [ V_18 ] . V_26 ) ;
V_24 [ V_18 ] . V_25 = NULL ;
}
V_200 . V_306 = ( V_14 + 1 ) ;
F_181 ( L_16 , V_307 , V_112 . V_308 ,
& V_309 ) ;
#ifdef F_182
F_183 ( V_310 , V_311 , F_147 ,
V_312 , NULL ) ;
#else
F_183 ( V_310 , V_311 , F_147 ,
F_160 , NULL ) ;
#endif
}
void T_9 F_184 ( void )
{
F_44 ( & V_30 ) ;
F_38 ( 0 ) ;
F_185 ( L_16 , V_112 . V_308 ) ;
F_186 ( & V_200 ) ;
}
