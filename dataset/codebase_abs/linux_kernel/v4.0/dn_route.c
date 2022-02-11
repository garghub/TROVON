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
static int F_54 ( struct V_36 * V_37 )
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
return F_65 ( V_106 , V_107 , V_37 , V_37 -> V_7 , NULL ,
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
return F_65 ( V_106 , V_107 , V_37 , V_37 -> V_7 , NULL ,
F_54 ) ;
V_103:
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_67 ( struct V_36 * V_37 )
{
F_59 ( V_37 ) ;
return V_87 ;
}
static int F_68 ( struct V_36 * V_37 )
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
V_37 , V_37 -> V_7 , NULL ,
F_68 ) ;
case V_128 :
case V_129 :
return F_65 ( V_106 , V_130 ,
V_37 , V_37 -> V_7 , NULL ,
F_67 ) ;
case V_131 :
return F_65 ( V_106 , V_127 ,
V_37 , V_37 -> V_7 , NULL ,
V_132 ) ;
case V_133 :
return F_65 ( V_106 , V_127 ,
V_37 , V_37 -> V_7 , NULL ,
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
static int F_81 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_82 ( V_37 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_5 = V_4 -> V_5 ;
return V_5 -> V_135 ( V_5 , V_37 ) ;
}
static int F_83 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_82 ( V_37 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_76 * V_77 = F_50 ( V_37 ) ;
int V_93 = - V_136 ;
if ( V_4 -> V_5 == NULL )
goto error;
V_37 -> V_7 = V_7 ;
V_77 -> V_11 = V_4 -> V_137 ;
V_77 -> V_2 = V_4 -> V_138 ;
V_77 -> V_82 &= ~ V_83 ;
V_77 -> V_82 |= V_139 ;
V_77 -> V_105 = 0 ;
return F_65 ( V_106 , V_140 , V_37 , NULL , V_7 ,
F_81 ) ;
error:
F_84 ( L_4 ) ;
F_59 ( V_37 ) ;
return V_93 ;
}
static int F_85 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
struct V_1 * V_2 = F_82 ( V_37 ) ;
struct V_40 * V_141 = F_72 ( V_2 -> V_7 -> V_42 ) ;
struct V_3 * V_4 ;
int V_142 ;
#ifdef F_86
struct V_6 * V_7 = V_37 -> V_7 ;
#endif
if ( V_37 -> V_85 != V_99 )
goto V_143;
V_4 = (struct V_3 * ) F_82 ( V_37 ) ;
V_142 = V_141 -> V_43 ? 21 : 6 ;
if ( F_87 ( V_37 , F_88 ( V_4 -> V_2 . V_7 ) + V_142 ) )
goto V_143;
if ( ++ V_77 -> V_105 > 30 )
goto V_143;
V_37 -> V_7 = V_4 -> V_2 . V_7 ;
V_77 -> V_82 &= ~ V_139 ;
if ( V_4 -> V_82 & V_144 )
V_77 -> V_82 |= V_139 ;
return F_65 ( V_106 , V_145 , V_37 , V_7 , V_37 -> V_7 ,
F_81 ) ;
V_143:
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_89 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
F_84 ( L_5 ,
F_58 ( V_77 -> V_11 ) , F_58 ( V_77 -> V_2 ) ) ;
F_59 ( V_37 ) ;
return V_81 ;
}
static int F_90 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_50 ( V_37 ) ;
F_84 ( L_5 ,
F_58 ( V_77 -> V_11 ) , F_58 ( V_77 -> V_2 ) ) ;
F_59 ( V_37 ) ;
return V_81 ;
}
static unsigned int F_91 ( const struct V_1 * V_2 )
{
return F_92 ( V_2 -> V_7 , F_93 ( V_2 ) ) ;
}
static unsigned int F_94 ( const struct V_1 * V_2 )
{
unsigned int V_38 = F_29 ( V_2 , V_44 ) ;
return V_38 ? : V_2 -> V_7 -> V_38 ;
}
static struct V_9 * F_95 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const void * V_54 )
{
return F_96 ( & V_146 , V_54 , V_2 -> V_7 ) ;
}
static int F_97 ( struct V_3 * V_4 , struct V_147 * V_148 )
{
struct V_149 * V_150 = V_148 -> V_150 ;
struct V_6 * V_7 = V_4 -> V_2 . V_7 ;
unsigned int V_151 ;
struct V_9 * V_5 ;
if ( V_150 ) {
if ( F_98 ( * V_148 ) &&
F_99 ( * V_148 ) . V_152 == V_153 )
V_4 -> V_154 = F_98 ( * V_148 ) ;
F_100 ( & V_4 -> V_2 , V_150 -> V_155 , true ) ;
}
V_4 -> V_156 = V_148 -> type ;
if ( V_7 != NULL && V_4 -> V_5 == NULL ) {
V_5 = F_96 ( & V_146 , & V_4 -> V_154 , V_7 ) ;
if ( F_101 ( V_5 ) )
return F_102 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
}
if ( F_25 ( & V_4 -> V_2 , V_44 ) > V_4 -> V_2 . V_7 -> V_38 )
F_27 ( & V_4 -> V_2 , V_44 , V_4 -> V_2 . V_7 -> V_38 ) ;
V_151 = F_29 ( & V_4 -> V_2 , V_46 ) ;
if ( V_151 ) {
unsigned int V_47 = F_92 ( V_7 , F_93 ( & V_4 -> V_2 ) ) ;
if ( V_151 > V_47 )
F_27 ( & V_4 -> V_2 , V_46 , V_47 ) ;
}
return 0 ;
}
static inline int F_103 ( T_2 V_157 , T_2 V_158 )
{
T_3 V_12 = F_58 ( V_157 ) ^ F_58 ( V_158 ) ;
int V_159 = 16 ;
while( V_12 ) {
V_12 >>= 1 ;
V_159 -- ;
}
return V_159 ;
}
static T_2 F_104 ( const struct V_6 * V_7 , T_2 V_54 , int V_160 )
{
T_2 V_55 = 0 ;
struct V_40 * V_141 ;
struct V_161 * V_162 ;
int V_163 = 0 ;
int V_164 ;
F_105 () ;
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
V_164 = F_103 ( V_54 , V_162 -> V_168 ) ;
if ( V_164 > V_163 )
V_55 = V_162 -> V_168 ;
if ( V_163 == 0 )
V_55 = V_162 -> V_168 ;
}
F_106 () ;
return V_55 ;
}
static inline T_2 F_107 ( struct V_147 * V_148 )
{
return F_104 ( F_108 ( * V_148 ) , F_98 ( * V_148 ) , V_148 -> V_160 ) ;
}
static inline T_2 F_109 ( T_2 V_54 , struct V_147 * V_148 )
{
T_2 V_169 = F_110 ( V_148 -> V_170 ) ;
return ( V_54 & ~ V_169 ) | V_148 -> V_150 -> V_171 -> V_172 ;
}
static int F_111 ( struct V_1 * * V_173 , const struct V_51 * V_174 , int V_175 )
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
V_178 = F_112 ( & V_112 , V_174 -> V_58 ) ;
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
if ( F_113 ( V_178 , V_174 -> V_55 ) )
goto V_185;
F_7 ( V_178 ) ;
goto V_114;
}
F_105 () ;
F_114 (&init_net, dev) {
if ( ! V_7 -> V_42 )
continue;
if ( ! F_113 ( V_7 , V_174 -> V_55 ) )
continue;
if ( ( V_7 -> V_111 & V_186 ) &&
V_174 -> V_54 &&
! F_113 ( V_7 , V_174 -> V_54 ) )
continue;
V_178 = V_7 ;
break;
}
F_106 () ;
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
V_64 . V_55 = F_104 ( V_178 , 0 ,
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
if ( V_175 || ( V_93 = F_115 ( & V_64 , & V_148 ) ) != 0 ) {
struct V_40 * V_141 ;
if ( V_93 != - V_190 )
goto V_114;
if ( ! V_175 ) {
V_179 = F_116 ( & V_146 , & V_112 , & V_64 . V_54 ) ;
if ( V_179 ) {
if ( ( V_174 -> V_58 &&
( V_179 -> V_7 -> V_117 != V_174 -> V_58 ) ) ||
( V_174 -> V_55 &&
( ! F_113 ( V_179 -> V_7 ,
V_174 -> V_55 ) ) ) ) {
F_2 ( V_179 ) ;
V_179 = NULL ;
} else {
if ( V_178 )
F_7 ( V_178 ) ;
if ( F_113 ( V_179 -> V_7 , V_64 . V_54 ) ) {
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
V_178 = F_117 () ;
V_93 = - V_183 ;
if ( V_178 == NULL )
goto V_114;
V_141 = F_24 ( V_178 -> V_42 ) ;
if ( F_113 ( V_178 , V_64 . V_54 ) ) {
F_7 ( V_178 ) ;
V_178 = V_112 . V_10 ;
F_6 ( V_178 ) ;
V_148 . type = V_188 ;
goto V_191;
}
V_179 = F_118 ( V_141 -> V_192 ) ;
F_119 ( V_179 && V_179 -> V_7 != V_178 ) ;
V_191:
if ( V_179 )
V_182 = ( (struct V_193 * ) V_179 ) -> V_194 ;
if ( V_182 == 0 )
V_182 = V_64 . V_54 ;
if ( V_64 . V_55 == 0 ) {
V_64 . V_55 = F_104 ( V_178 , V_182 ,
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
F_120 ( V_148 . V_150 ) ;
V_148 . V_150 = NULL ;
goto V_189;
}
if ( V_148 . V_150 -> V_198 > 1 && V_64 . V_58 == 0 )
F_121 ( & V_64 , & V_148 ) ;
if ( ! V_64 . V_55 )
V_64 . V_55 = F_122 ( V_148 ) ;
if ( V_178 )
F_7 ( V_178 ) ;
V_178 = F_108 ( V_148 ) ;
F_6 ( V_178 ) ;
V_64 . V_58 = V_178 -> V_117 ;
V_182 = F_98 ( V_148 ) ;
V_189:
if ( V_178 -> V_111 & V_186 )
V_111 |= V_199 ;
V_4 = F_123 ( & V_200 , V_178 , 1 , V_201 , V_202 ) ;
if ( V_4 == NULL )
goto V_203;
memset ( & V_4 -> V_64 , 0 , sizeof( V_4 -> V_64 ) ) ;
V_4 -> V_64 . V_55 = V_174 -> V_55 ;
V_4 -> V_64 . V_54 = V_174 -> V_54 ;
V_4 -> V_64 . V_58 = V_174 -> V_58 ;
V_4 -> V_64 . V_59 = 0 ;
V_4 -> V_64 . V_56 = V_174 -> V_56 ;
V_4 -> V_137 = V_64 . V_55 ;
V_4 -> V_138 = V_64 . V_54 ;
V_4 -> V_154 = V_182 ? V_182 : V_64 . V_54 ;
V_4 -> V_204 = V_64 . V_55 ;
V_4 -> V_205 = V_64 . V_54 ;
V_4 -> V_206 = V_64 . V_55 ;
V_4 -> V_5 = V_179 ;
V_179 = NULL ;
V_4 -> V_2 . V_28 = V_21 ;
V_4 -> V_2 . V_135 = F_83 ;
V_4 -> V_2 . V_207 = F_90 ;
V_4 -> V_82 = V_111 ;
if ( V_111 & V_199 )
V_4 -> V_2 . V_207 = V_208 ;
V_93 = F_97 ( V_4 , & V_148 ) ;
if ( V_93 )
goto V_209;
V_60 = F_8 ( V_4 -> V_64 . V_55 , V_4 -> V_64 . V_54 ) ;
F_35 ( V_4 , V_60 , (struct V_3 * * ) V_173 ) ;
V_210:
if ( V_179 )
F_2 ( V_179 ) ;
if ( V_181 )
F_124 ( & V_148 ) ;
if ( V_178 )
F_7 ( V_178 ) ;
V_114:
return V_93 ;
V_195:
V_93 = - V_184 ;
goto V_210;
V_197:
V_93 = - V_136 ;
goto V_210;
V_203:
V_93 = - V_211 ;
goto V_210;
V_209:
F_41 ( & V_4 -> V_2 ) ;
goto V_203;
}
static int F_125 ( struct V_1 * * V_173 , const struct V_51 * V_212 , int V_111 )
{
unsigned int V_60 = F_8 ( V_212 -> V_55 , V_212 -> V_54 ) ;
struct V_3 * V_4 = NULL ;
if ( ! ( V_111 & V_213 ) ) {
F_126 () ;
for ( V_4 = F_127 ( V_24 [ V_60 ] . V_25 ) ; V_4 ;
V_4 = F_127 ( V_4 -> V_2 . V_29 ) ) {
if ( ( V_212 -> V_54 == V_4 -> V_64 . V_54 ) &&
( V_212 -> V_55 == V_4 -> V_64 . V_55 ) &&
( V_212 -> V_56 == V_4 -> V_64 . V_56 ) &&
F_128 ( V_4 ) &&
( V_4 -> V_64 . V_58 == V_212 -> V_58 ) ) {
F_37 ( & V_4 -> V_2 , V_21 ) ;
F_129 () ;
* V_173 = & V_4 -> V_2 ;
return 0 ;
}
}
F_129 () ;
}
return F_111 ( V_173 , V_212 , V_111 ) ;
}
static int F_130 ( struct V_1 * * V_173 , struct V_51 * V_212 , int V_111 )
{
int V_93 ;
V_93 = F_125 ( V_173 , V_212 , V_111 ) ;
if ( V_93 == 0 && V_212 -> V_214 ) {
* V_173 = F_131 ( & V_112 , * V_173 ,
F_132 ( V_212 ) , NULL , 0 ) ;
if ( F_101 ( * V_173 ) ) {
V_93 = F_102 ( * V_173 ) ;
* V_173 = NULL ;
}
}
return V_93 ;
}
int F_133 ( struct V_1 T_4 * * V_173 , struct V_51 * V_215 , struct V_34 * V_35 , int V_111 )
{
int V_93 ;
V_93 = F_125 ( V_173 , V_215 , V_111 & V_213 ) ;
if ( V_93 == 0 && V_215 -> V_214 ) {
* V_173 = F_131 ( & V_112 , * V_173 ,
F_132 ( V_215 ) , V_35 , 0 ) ;
if ( F_101 ( * V_173 ) ) {
V_93 = F_102 ( * V_173 ) ;
* V_173 = NULL ;
}
}
return V_93 ;
}
static int F_134 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = NULL ;
struct V_76 * V_77 = F_50 ( V_37 ) ;
struct V_6 * V_216 = V_37 -> V_7 ;
struct V_6 * V_217 = NULL ;
struct V_40 * V_141 ;
struct V_9 * V_179 = NULL ;
unsigned int V_60 ;
int V_111 = 0 ;
T_2 V_182 = 0 ;
T_2 V_218 = 0 ;
struct V_51 V_64 = {
. V_54 = V_77 -> V_2 ,
. V_55 = V_77 -> V_11 ,
. V_57 = V_176 ,
. V_56 = V_37 -> V_219 ,
. V_59 = V_37 -> V_7 -> V_117 ,
} ;
struct V_147 V_148 = { . V_150 = NULL , . type = V_220 } ;
int V_93 = - V_136 ;
int V_181 = 0 ;
F_6 ( V_216 ) ;
if ( ( V_141 = F_72 ( V_216 -> V_42 ) ) == NULL )
goto V_114;
if ( V_64 . V_55 == 0 )
goto V_114;
V_93 = - V_221 ;
if ( F_113 ( V_216 , V_77 -> V_11 ) )
goto V_114;
V_93 = F_115 ( & V_64 , & V_148 ) ;
if ( V_93 ) {
if ( V_93 != - V_190 )
goto V_114;
if ( ! F_113 ( V_216 , V_77 -> V_2 ) )
goto V_197;
V_148 . type = V_188 ;
} else {
T_2 V_222 = V_64 . V_55 ;
V_181 = 1 ;
V_217 = F_108 ( V_148 ) ;
if ( V_217 == NULL ) {
F_135 ( L_10 ) ;
goto V_197;
}
F_6 ( V_217 ) ;
if ( V_148 . V_223 )
V_222 = V_64 . V_55 ;
V_182 = F_98 ( V_148 ) ;
if ( V_148 . type == V_196 ) {
V_64 . V_54 = F_109 ( V_64 . V_54 , & V_148 ) ;
F_124 ( & V_148 ) ;
V_181 = 0 ;
if ( F_115 ( & V_64 , & V_148 ) )
goto V_197;
V_181 = 1 ;
if ( V_148 . type != V_180 )
goto V_197;
V_111 |= V_224 ;
V_182 = V_64 . V_54 ;
}
V_64 . V_55 = V_222 ;
}
switch( V_148 . type ) {
case V_180 :
if ( V_141 -> V_123 . V_225 == 0 )
goto V_197;
if ( V_148 . V_150 -> V_198 > 1 && V_64 . V_58 == 0 )
F_121 ( & V_64 , & V_148 ) ;
if ( V_217 == V_216 && ! ( V_111 & V_226 ) )
V_111 |= V_144 ;
V_218 = F_122 ( V_148 ) ;
case V_227 :
case V_220 :
break;
case V_188 :
V_111 |= V_199 ;
V_64 . V_55 = V_77 -> V_2 ;
V_64 . V_54 = V_77 -> V_11 ;
if ( V_182 )
goto V_189;
if ( V_77 -> V_82 & V_139 ) {
V_182 = V_77 -> V_11 ;
goto V_189;
}
V_179 = F_118 ( V_141 -> V_192 ) ;
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
V_4 = F_123 ( & V_200 , V_217 , 0 , V_201 , V_202 ) ;
if ( V_4 == NULL )
goto V_203;
memset ( & V_4 -> V_64 , 0 , sizeof( V_4 -> V_64 ) ) ;
V_4 -> V_137 = V_64 . V_55 ;
V_4 -> V_138 = V_64 . V_54 ;
V_4 -> V_154 = V_64 . V_54 ;
if ( V_182 )
V_4 -> V_154 = V_182 ;
V_4 -> V_204 = V_218 ? V_218 : V_4 -> V_137 ;
V_4 -> V_205 = V_64 . V_54 ;
V_4 -> V_206 = V_64 . V_55 ;
V_4 -> V_64 . V_55 = V_77 -> V_11 ;
V_4 -> V_64 . V_54 = V_77 -> V_2 ;
V_4 -> V_64 . V_58 = 0 ;
V_4 -> V_64 . V_59 = V_216 -> V_117 ;
V_4 -> V_64 . V_56 = V_64 . V_56 ;
V_4 -> V_5 = V_179 ;
V_4 -> V_2 . V_28 = V_21 ;
V_4 -> V_2 . V_135 = F_89 ;
switch ( V_148 . type ) {
case V_180 :
V_4 -> V_2 . V_207 = F_85 ;
break;
case V_188 :
V_4 -> V_2 . V_135 = F_83 ;
V_4 -> V_2 . V_207 = V_208 ;
V_4 -> V_2 . V_7 = V_216 ;
V_111 |= V_199 ;
break;
default:
case V_220 :
case V_227 :
V_4 -> V_2 . V_207 = V_228 ;
}
V_4 -> V_82 = V_111 ;
V_93 = F_97 ( V_4 , & V_148 ) ;
if ( V_93 )
goto V_209;
V_60 = F_8 ( V_4 -> V_64 . V_55 , V_4 -> V_64 . V_54 ) ;
F_35 ( V_4 , V_60 , & V_4 ) ;
F_136 ( V_37 , & V_4 -> V_2 ) ;
V_210:
if ( V_179 )
F_2 ( V_179 ) ;
if ( V_181 )
F_124 ( & V_148 ) ;
F_7 ( V_216 ) ;
if ( V_217 )
F_7 ( V_217 ) ;
V_114:
return V_93 ;
V_197:
V_93 = - V_136 ;
goto V_210;
V_203:
V_93 = - V_211 ;
goto V_210;
V_209:
F_41 ( & V_4 -> V_2 ) ;
goto V_210;
}
static int F_55 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_76 * V_77 = F_50 ( V_37 ) ;
unsigned int V_60 = F_8 ( V_77 -> V_11 , V_77 -> V_2 ) ;
if ( F_82 ( V_37 ) )
return 0 ;
F_105 () ;
for( V_4 = F_72 ( V_24 [ V_60 ] . V_25 ) ; V_4 != NULL ;
V_4 = F_72 ( V_4 -> V_2 . V_29 ) ) {
if ( ( V_4 -> V_64 . V_55 == V_77 -> V_11 ) &&
( V_4 -> V_64 . V_54 == V_77 -> V_2 ) &&
( V_4 -> V_64 . V_58 == 0 ) &&
( V_4 -> V_64 . V_56 == V_37 -> V_219 ) &&
( V_4 -> V_64 . V_59 == V_77 -> V_116 ) ) {
F_37 ( & V_4 -> V_2 , V_21 ) ;
F_106 () ;
F_136 ( V_37 , (struct V_1 * ) V_4 ) ;
return 0 ;
}
}
F_106 () ;
return F_134 ( V_37 ) ;
}
static int F_137 ( struct V_36 * V_37 , T_5 V_229 , T_5 V_230 ,
int V_231 , int V_232 , unsigned int V_111 )
{
struct V_3 * V_4 = (struct V_3 * ) F_82 ( V_37 ) ;
struct V_233 * V_223 ;
struct V_234 * V_235 ;
long V_75 ;
V_235 = F_138 ( V_37 , V_229 , V_230 , V_231 , sizeof( * V_223 ) , V_111 ) ;
if ( ! V_235 )
return - V_236 ;
V_223 = F_139 ( V_235 ) ;
V_223 -> V_237 = V_238 ;
V_223 -> V_239 = 16 ;
V_223 -> V_240 = 0 ;
V_223 -> V_241 = 0 ;
V_223 -> V_242 = V_243 ;
V_223 -> V_244 = V_4 -> V_156 ;
V_223 -> V_245 = ( V_4 -> V_82 & ~ 0xFFFF ) | V_246 ;
V_223 -> V_247 = V_176 ;
V_223 -> V_248 = V_249 ;
if ( V_4 -> V_82 & V_250 )
V_223 -> V_245 |= V_251 ;
if ( F_140 ( V_37 , V_252 , V_243 ) < 0 ||
F_141 ( V_37 , V_253 , V_4 -> V_138 ) < 0 )
goto V_254;
if ( V_4 -> V_64 . V_55 ) {
V_223 -> V_240 = 16 ;
if ( F_141 ( V_37 , V_255 , V_4 -> V_64 . V_55 ) < 0 )
goto V_254;
}
if ( V_4 -> V_2 . V_7 &&
F_140 ( V_37 , V_256 , V_4 -> V_2 . V_7 -> V_117 ) < 0 )
goto V_254;
if ( F_141 ( V_37 , V_257 , V_4 -> V_204 ) < 0 )
goto V_254;
if ( V_4 -> V_138 != V_4 -> V_154 &&
F_141 ( V_37 , V_258 , V_4 -> V_154 ) < 0 )
goto V_254;
if ( F_142 ( V_37 , F_143 ( & V_4 -> V_2 ) ) < 0 )
goto V_254;
V_75 = V_4 -> V_2 . V_75 ? V_4 -> V_2 . V_75 - V_21 : 0 ;
if ( F_144 ( V_37 , & V_4 -> V_2 , 0 , V_75 ,
V_4 -> V_2 . error ) < 0 )
goto V_254;
if ( F_145 ( V_4 ) &&
F_140 ( V_37 , V_259 , V_4 -> V_64 . V_59 ) < 0 )
goto V_254;
F_146 ( V_37 , V_235 ) ;
return 0 ;
V_254:
F_147 ( V_37 , V_235 ) ;
return - V_236 ;
}
static int F_148 ( struct V_36 * V_260 , struct V_234 * V_235 )
{
struct V_261 * V_261 = F_149 ( V_260 -> V_35 ) ;
struct V_233 * V_262 = F_139 ( V_235 ) ;
struct V_3 * V_4 = NULL ;
struct V_76 * V_77 ;
int V_93 ;
struct V_36 * V_37 ;
struct V_51 V_64 ;
struct V_263 * V_264 [ V_265 + 1 ] ;
if ( ! F_73 ( V_261 , & V_112 ) )
return - V_136 ;
V_93 = F_150 ( V_235 , sizeof( * V_262 ) , V_264 , V_265 , V_266 ) ;
if ( V_93 < 0 )
return V_93 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_214 = V_267 ;
V_37 = F_151 ( V_268 , V_269 ) ;
if ( V_37 == NULL )
return - V_211 ;
F_152 ( V_37 ) ;
V_77 = F_50 ( V_37 ) ;
if ( V_264 [ V_255 ] )
V_64 . V_55 = F_153 ( V_264 [ V_255 ] ) ;
if ( V_264 [ V_253 ] )
V_64 . V_54 = F_153 ( V_264 [ V_253 ] ) ;
if ( V_264 [ V_259 ] )
V_64 . V_59 = F_154 ( V_264 [ V_259 ] ) ;
if ( V_64 . V_59 ) {
struct V_6 * V_7 ;
V_7 = F_155 ( & V_112 , V_64 . V_59 ) ;
if ( ! V_7 || ! V_7 -> V_42 ) {
F_59 ( V_37 ) ;
return - V_183 ;
}
V_37 -> V_270 = F_156 ( V_271 ) ;
V_37 -> V_7 = V_7 ;
V_77 -> V_11 = V_64 . V_55 ;
V_77 -> V_2 = V_64 . V_54 ;
F_157 () ;
V_93 = F_55 ( V_37 ) ;
F_158 () ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_4 = (struct V_3 * ) F_82 ( V_37 ) ;
if ( ! V_93 && - V_4 -> V_2 . error )
V_93 = V_4 -> V_2 . error ;
} else {
if ( V_264 [ V_256 ] )
V_64 . V_58 = F_154 ( V_264 [ V_256 ] ) ;
V_93 = F_130 ( (struct V_1 * * ) & V_4 , & V_64 , 0 ) ;
}
V_37 -> V_7 = NULL ;
if ( V_93 )
goto V_272;
F_136 ( V_37 , & V_4 -> V_2 ) ;
if ( V_262 -> V_245 & V_251 )
V_4 -> V_82 |= V_250 ;
V_93 = F_137 ( V_37 , F_159 ( V_260 ) . V_229 , V_235 -> V_273 , V_274 , 0 , 0 ) ;
if ( V_93 < 0 ) {
V_93 = - V_236 ;
goto V_272;
}
return F_160 ( V_37 , & V_112 , F_159 ( V_260 ) . V_229 ) ;
V_272:
F_59 ( V_37 ) ;
return V_93 ;
}
int F_161 ( struct V_36 * V_37 , struct V_275 * V_77 )
{
struct V_261 * V_261 = F_149 ( V_37 -> V_35 ) ;
struct V_3 * V_4 ;
int V_276 , V_277 ;
int V_278 , V_279 ;
struct V_233 * V_262 ;
if ( ! F_73 ( V_261 , & V_112 ) )
return 0 ;
if ( F_162 ( V_77 -> V_235 ) < sizeof( struct V_233 ) )
return - V_136 ;
V_262 = F_139 ( V_77 -> V_235 ) ;
if ( ! ( V_262 -> V_245 & V_246 ) )
return 0 ;
V_277 = V_77 -> args [ 0 ] ;
V_279 = V_278 = V_77 -> args [ 1 ] ;
for( V_276 = 0 ; V_276 <= V_14 ; V_276 ++ ) {
if ( V_276 < V_277 )
continue;
if ( V_276 > V_277 )
V_279 = 0 ;
F_126 () ;
for( V_4 = F_127 ( V_24 [ V_276 ] . V_25 ) , V_278 = 0 ;
V_4 ;
V_4 = F_127 ( V_4 -> V_2 . V_29 ) , V_278 ++ ) {
if ( V_278 < V_279 )
continue;
F_136 ( V_37 , F_163 ( & V_4 -> V_2 ) ) ;
if ( F_137 ( V_37 , F_159 ( V_77 -> V_37 ) . V_229 ,
V_77 -> V_235 -> V_273 , V_274 ,
1 , V_280 ) < 0 ) {
F_164 ( V_37 ) ;
F_129 () ;
goto V_210;
}
F_164 ( V_37 ) ;
}
F_129 () ;
}
V_210:
V_77 -> args [ 0 ] = V_276 ;
V_77 -> args [ 1 ] = V_278 ;
return V_37 -> V_98 ;
}
static struct V_3 * F_165 ( struct V_281 * V_230 )
{
struct V_3 * V_4 = NULL ;
struct V_282 * V_283 = V_230 -> V_284 ;
for( V_283 -> V_285 = V_14 ; V_283 -> V_285 >= 0 ; -- V_283 -> V_285 ) {
F_126 () ;
V_4 = F_127 ( V_24 [ V_283 -> V_285 ] . V_25 ) ;
if ( V_4 )
break;
F_129 () ;
}
return V_4 ;
}
static struct V_3 * F_166 ( struct V_281 * V_230 , struct V_3 * V_4 )
{
struct V_282 * V_283 = V_230 -> V_284 ;
V_4 = F_127 ( V_4 -> V_2 . V_29 ) ;
while ( ! V_4 ) {
F_129 () ;
if ( -- V_283 -> V_285 < 0 )
break;
F_126 () ;
V_4 = F_127 ( V_24 [ V_283 -> V_285 ] . V_25 ) ;
}
return V_4 ;
}
static void * F_167 ( struct V_281 * V_230 , T_7 * V_286 )
{
struct V_3 * V_4 = F_165 ( V_230 ) ;
if ( V_4 ) {
while( * V_286 && ( V_4 = F_166 ( V_230 , V_4 ) ) )
-- * V_286 ;
}
return * V_286 ? NULL : V_4 ;
}
static void * F_168 ( struct V_281 * V_230 , void * V_287 , T_7 * V_286 )
{
struct V_3 * V_4 = F_166 ( V_230 , V_287 ) ;
++ * V_286 ;
return V_4 ;
}
static void F_169 ( struct V_281 * V_230 , void * V_287 )
{
if ( V_287 )
F_129 () ;
}
static int F_170 ( struct V_281 * V_230 , void * V_287 )
{
struct V_3 * V_4 = V_287 ;
char V_288 [ V_289 ] , V_290 [ V_289 ] ;
F_171 ( V_230 , L_11 ,
V_4 -> V_2 . V_7 ? V_4 -> V_2 . V_7 -> V_96 : L_12 ,
F_172 ( F_58 ( V_4 -> V_138 ) , V_288 ) ,
F_172 ( F_58 ( V_4 -> V_137 ) , V_290 ) ,
F_17 ( & V_4 -> V_2 . V_27 ) ,
V_4 -> V_2 . V_291 , 0 ) ;
return 0 ;
}
static int F_173 ( struct V_292 * V_292 , struct V_293 * V_293 )
{
return F_174 ( V_293 , & V_294 ,
sizeof( struct V_282 ) ) ;
}
void T_8 F_175 ( void )
{
int V_18 , V_295 , V_296 ;
V_200 . V_297 =
F_176 ( L_13 , sizeof( struct V_3 ) , 0 ,
V_298 | V_299 , NULL ) ;
F_177 ( & V_200 ) ;
F_178 ( & V_30 , F_13 , 0 ) ;
V_30 . V_75 = V_21 + V_31 * V_23 ;
F_45 ( & V_30 ) ;
V_295 = V_300 >> ( 26 - V_301 ) ;
for( V_296 = 0 ; ( 1UL << V_296 ) < V_295 ; V_296 ++ )
;
while( V_296 && ( ( ( ( 1UL << V_296 ) * V_302 ) /
sizeof( struct V_303 ) ) >= 2048 ) )
V_296 -- ;
do {
V_14 = ( 1UL << V_296 ) * V_302 /
sizeof( struct V_303 ) ;
while( V_14 & ( V_14 - 1 ) )
V_14 -- ;
V_24 = (struct V_303 * )
F_179 ( V_80 , V_296 ) ;
} while ( V_24 == NULL && -- V_296 > 0 );
if ( ! V_24 )
F_180 ( L_14 ) ;
F_57 ( V_304
L_15 ,
V_14 ,
( long ) ( V_14 * sizeof( struct V_303 ) ) / 1024 ) ;
V_14 -- ;
for( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
F_181 ( & V_24 [ V_18 ] . V_26 ) ;
V_24 [ V_18 ] . V_25 = NULL ;
}
V_200 . V_305 = ( V_14 + 1 ) ;
F_182 ( L_16 , V_306 , V_112 . V_307 ,
& V_308 ) ;
#ifdef F_183
F_184 ( V_309 , V_310 , F_148 ,
V_311 , NULL ) ;
#else
F_184 ( V_309 , V_310 , F_148 ,
F_161 , NULL ) ;
#endif
}
void T_9 F_185 ( void )
{
F_44 ( & V_30 ) ;
F_38 ( 0 ) ;
F_186 ( L_16 , V_112 . V_307 ) ;
F_187 ( & V_200 ) ;
}
