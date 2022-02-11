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
static void F_11 ( unsigned long V_17 )
{
int V_18 ;
struct V_3 * V_4 ;
struct V_3 T_4 * * V_19 ;
unsigned long V_20 = V_21 ;
unsigned long V_22 = 120 * V_23 ;
for ( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
V_19 = & V_24 [ V_18 ] . V_25 ;
F_12 ( & V_24 [ V_18 ] . V_26 ) ;
while ( ( V_4 = F_13 ( * V_19 ,
F_14 ( & V_24 [ V_18 ] . V_26 ) ) ) != NULL ) {
if ( F_15 ( & V_4 -> V_2 . V_27 ) ||
( V_20 - V_4 -> V_2 . V_28 ) < V_22 ) {
V_19 = & V_4 -> V_2 . V_29 ;
continue;
}
* V_19 = V_4 -> V_2 . V_29 ;
V_4 -> V_2 . V_29 = NULL ;
F_9 ( V_4 ) ;
}
F_16 ( & V_24 [ V_18 ] . V_26 ) ;
if ( ( V_21 - V_20 ) > 0 )
break;
}
F_17 ( & V_30 , V_20 + V_31 * V_23 ) ;
}
static int F_18 ( struct V_32 * V_33 )
{
struct V_3 * V_4 ;
struct V_3 T_4 * * V_19 ;
int V_18 ;
unsigned long V_20 = V_21 ;
unsigned long V_22 = 10 * V_23 ;
for ( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
F_19 ( & V_24 [ V_18 ] . V_26 ) ;
V_19 = & V_24 [ V_18 ] . V_25 ;
while ( ( V_4 = F_13 ( * V_19 ,
F_14 ( & V_24 [ V_18 ] . V_26 ) ) ) != NULL ) {
if ( F_15 ( & V_4 -> V_2 . V_27 ) ||
( V_20 - V_4 -> V_2 . V_28 ) < V_22 ) {
V_19 = & V_4 -> V_2 . V_29 ;
continue;
}
* V_19 = V_4 -> V_2 . V_29 ;
V_4 -> V_2 . V_29 = NULL ;
F_9 ( V_4 ) ;
break;
}
F_20 ( & V_24 [ V_18 ] . V_26 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 , T_5 V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_9 * V_5 = V_4 -> V_5 ;
T_5 V_39 = 230 ;
struct V_40 * V_41 ;
V_41 = V_5 ? F_22 ( V_5 -> V_7 -> V_42 ) : NULL ;
if ( V_41 && V_41 -> V_43 == 0 )
V_39 -= 6 ;
else
V_39 -= 21 ;
if ( F_23 ( V_2 , V_44 ) > V_38 && V_38 >= V_39 ) {
if ( ! ( F_24 ( V_2 , V_44 ) ) ) {
F_25 ( V_2 , V_44 , V_38 ) ;
F_26 ( V_2 , V_45 ) ;
}
if ( ! ( F_24 ( V_2 , V_46 ) ) ) {
T_5 V_47 = V_38 - V_48 ;
T_5 V_49 = F_27 ( V_2 , V_46 ) ;
if ( ! V_49 || V_49 > V_47 )
F_25 ( V_2 , V_46 , V_47 ) ;
}
}
}
static void F_28 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_36 * V_37 )
{
}
static struct V_1 * F_29 ( struct V_1 * V_2 , T_6 V_50 )
{
return NULL ;
}
static struct V_1 * F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
return NULL ;
}
static void F_32 ( struct V_36 * V_37 )
{
}
static inline int F_33 ( struct V_51 * V_52 , struct V_51 * V_53 )
{
return ( ( V_52 -> V_54 ^ V_53 -> V_54 ) |
( V_52 -> V_55 ^ V_53 -> V_55 ) |
( V_52 -> V_56 ^ V_53 -> V_56 ) |
( V_52 -> V_57 ^ V_53 -> V_57 ) |
( V_52 -> V_58 ^ V_53 -> V_58 ) |
( V_52 -> V_59 ^ V_53 -> V_59 ) ) == 0 ;
}
static int F_34 ( struct V_3 * V_4 , unsigned int V_60 , struct V_3 * * V_61 )
{
struct V_3 * V_62 ;
struct V_3 T_4 * * V_63 ;
unsigned long V_20 = V_21 ;
V_63 = & V_24 [ V_60 ] . V_25 ;
F_19 ( & V_24 [ V_60 ] . V_26 ) ;
while ( ( V_62 = F_13 ( * V_63 ,
F_14 ( & V_24 [ V_60 ] . V_26 ) ) ) != NULL ) {
if ( F_33 ( & V_62 -> V_64 , & V_4 -> V_64 ) ) {
* V_63 = V_62 -> V_2 . V_29 ;
F_35 ( V_62 -> V_2 . V_29 ,
V_24 [ V_60 ] . V_25 ) ;
F_35 ( V_24 [ V_60 ] . V_25 , V_62 ) ;
F_36 ( & V_62 -> V_2 , V_20 ) ;
F_20 ( & V_24 [ V_60 ] . V_26 ) ;
F_37 ( & V_4 -> V_2 ) ;
* V_61 = V_62 ;
return 0 ;
}
V_63 = & V_62 -> V_2 . V_29 ;
}
F_35 ( V_4 -> V_2 . V_29 , V_24 [ V_60 ] . V_25 ) ;
F_35 ( V_24 [ V_60 ] . V_25 , V_4 ) ;
F_36 ( & V_4 -> V_2 , V_20 ) ;
F_20 ( & V_24 [ V_60 ] . V_26 ) ;
* V_61 = V_4 ;
return 0 ;
}
static void F_38 ( unsigned long V_17 )
{
int V_18 ;
struct V_3 * V_4 , * V_65 ;
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
F_19 ( & V_24 [ V_18 ] . V_26 ) ;
if ( ( V_4 = F_39 ( (struct V_3 * * ) & V_24 [ V_18 ] . V_25 , NULL ) ) == NULL )
goto V_66;
for(; V_4 ; V_4 = V_65 ) {
V_65 = F_22 ( V_4 -> V_2 . V_29 ) ;
F_40 ( V_4 -> V_2 . V_29 , NULL ) ;
F_9 ( V_4 ) ;
}
V_66:
F_20 ( & V_24 [ V_18 ] . V_26 ) ;
}
}
void F_41 ( int V_67 )
{
unsigned long V_20 = V_21 ;
int V_68 = ! F_42 () ;
if ( V_67 < 0 )
V_67 = V_69 ;
F_19 ( & V_70 ) ;
if ( F_43 ( & V_71 ) && V_67 > 0 && V_72 ) {
long V_73 = ( long ) ( V_72 - V_20 ) ;
if ( V_68 && V_73 < V_74 - V_69 )
V_73 = 0 ;
if ( V_67 > V_73 )
V_67 = V_73 ;
}
if ( V_67 <= 0 ) {
F_20 ( & V_70 ) ;
F_38 ( 0 ) ;
return;
}
if ( V_72 == 0 )
V_72 = V_20 + V_74 ;
V_71 . V_75 = V_20 + V_67 ;
F_44 ( & V_71 ) ;
F_20 ( & V_70 ) ;
}
static int F_45 ( struct V_36 * V_37 )
{
struct V_76 * V_77 ;
unsigned char * V_78 ;
T_2 * V_11 ;
T_2 * V_2 ;
F_46 ( V_37 , V_37 -> V_79 - F_47 ( V_37 ) ) ;
if ( ( V_37 = F_48 ( V_37 , V_80 ) ) == NULL )
return V_81 ;
V_77 = F_49 ( V_37 ) ;
V_78 = V_37 -> V_79 + 2 ;
* V_78 ++ = ( V_77 -> V_82 & ~ V_83 ) | V_84 ;
V_2 = ( T_2 * ) V_78 ;
V_78 += 2 ;
V_11 = ( T_2 * ) V_78 ;
V_78 += 2 ;
* V_78 = 0 ;
F_50 ( * V_11 , * V_2 ) ;
V_37 -> V_85 = V_86 ;
F_51 ( V_37 , NULL , NULL ) ;
return V_87 ;
}
static int F_52 ( struct V_36 * V_37 )
{
struct V_76 * V_77 ;
unsigned char * V_78 ;
unsigned char * V_88 , * V_89 ;
unsigned char V_12 [ V_90 ] ;
F_46 ( V_37 , V_37 -> V_79 - F_47 ( V_37 ) ) ;
if ( ( V_37 = F_48 ( V_37 , V_80 ) ) == NULL )
return V_81 ;
V_77 = F_49 ( V_37 ) ;
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
F_51 ( V_37 , V_89 , V_88 ) ;
return V_87 ;
}
static int F_53 ( struct V_93 * V_93 , struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_76 * V_77 ;
int V_94 ;
if ( ( V_94 = F_54 ( V_37 ) ) == 0 )
return F_55 ( V_37 ) ;
V_77 = F_49 ( V_37 ) ;
if ( V_95 & 4 ) {
char * V_96 = V_37 -> V_7 ? V_37 -> V_7 -> V_97 : L_1 ;
F_56 ( V_98
L_2 ,
( int ) V_77 -> V_82 , V_96 , V_37 -> V_99 ,
F_57 ( V_77 -> V_11 ) , F_57 ( V_77 -> V_2 ) ,
V_94 , V_37 -> V_85 ) ;
}
if ( ( V_37 -> V_85 == V_100 ) && ( V_77 -> V_82 & V_83 ) ) {
switch ( V_77 -> V_82 & V_101 ) {
case V_102 :
return F_45 ( V_37 ) ;
case V_103 :
return F_52 ( V_37 ) ;
}
}
F_58 ( V_37 ) ;
return V_81 ;
}
static int F_59 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_49 ( V_37 ) ;
unsigned char * V_78 = V_37 -> V_79 ;
if ( ! F_60 ( V_37 , 21 ) )
goto V_104;
F_61 ( V_37 , 20 ) ;
F_62 ( V_37 ) ;
V_78 += 2 ;
V_77 -> V_2 = F_63 ( V_78 ) ;
if ( memcmp ( V_78 , V_105 , 4 ) != 0 )
goto V_104;
V_78 += 6 ;
V_78 += 2 ;
V_77 -> V_11 = F_63 ( V_78 ) ;
if ( memcmp ( V_78 , V_105 , 4 ) != 0 )
goto V_104;
V_78 += 6 ;
V_78 ++ ;
V_77 -> V_106 = * V_78 ++ ;
return F_64 ( V_107 , V_108 ,
& V_109 , NULL , V_37 , V_37 -> V_7 , NULL ,
F_53 ) ;
V_104:
F_58 ( V_37 ) ;
return V_81 ;
}
static int F_65 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_49 ( V_37 ) ;
unsigned char * V_78 = V_37 -> V_79 ;
if ( ! F_60 ( V_37 , 6 ) )
goto V_104;
F_61 ( V_37 , 5 ) ;
F_62 ( V_37 ) ;
V_77 -> V_2 = * ( T_2 * ) V_78 ;
V_78 += 2 ;
V_77 -> V_11 = * ( T_2 * ) V_78 ;
V_78 += 2 ;
V_77 -> V_106 = * V_78 & 0x3f ;
return F_64 ( V_107 , V_108 ,
& V_109 , NULL , V_37 , V_37 -> V_7 , NULL ,
F_53 ) ;
V_104:
F_58 ( V_37 ) ;
return V_81 ;
}
static int F_66 ( struct V_93 * V_93 , struct V_34 * V_35 , struct V_36 * V_37 )
{
F_58 ( V_37 ) ;
return V_87 ;
}
static int F_67 ( struct V_93 * V_93 , struct V_34 * V_35 , struct V_36 * V_37 )
{
F_68 ( V_37 ) ;
F_69 ( V_37 ) ;
return V_87 ;
}
int F_70 ( struct V_36 * V_37 , struct V_6 * V_7 , struct V_110 * V_111 , struct V_6 * V_112 )
{
struct V_76 * V_77 ;
unsigned char V_113 = 0 ;
T_3 V_99 = F_57 ( * ( T_2 * ) V_37 -> V_79 ) ;
struct V_40 * V_41 = F_71 ( V_7 -> V_42 ) ;
unsigned char V_92 = 0 ;
if ( ! F_72 ( F_5 ( V_7 ) , & V_109 ) )
goto V_114;
if ( V_41 == NULL )
goto V_114;
if ( ( V_37 = F_73 ( V_37 , V_80 ) ) == NULL )
goto V_115;
if ( ! F_60 ( V_37 , 3 ) )
goto V_114;
F_61 ( V_37 , 2 ) ;
if ( V_99 > V_37 -> V_99 )
goto V_114;
F_74 ( V_37 , V_99 ) ;
V_113 = * V_37 -> V_79 ;
V_77 = F_49 ( V_37 ) ;
V_77 -> V_116 = V_21 ;
V_77 -> V_117 = V_7 -> V_118 ;
if ( V_113 & V_91 ) {
V_92 = V_113 & ~ V_91 ;
if ( ! F_60 ( V_37 , V_92 + 1 ) )
goto V_114;
F_61 ( V_37 , V_92 ) ;
V_113 = * V_37 -> V_79 ;
}
F_75 ( V_37 ) ;
if ( V_113 & V_119 )
goto V_114;
V_77 -> V_82 = V_113 ;
if ( V_95 & 1 )
F_56 ( V_98
L_3 ,
( int ) V_113 , ( V_7 ) ? V_7 -> V_97 : L_1 , V_99 , V_37 -> V_99 ,
V_92 ) ;
if ( V_113 & V_120 ) {
if ( F_76 ( F_77 ( V_37 ) ) )
goto V_114;
switch ( V_113 & V_121 ) {
case V_122 :
F_78 ( V_37 ) ;
break;
case V_123 :
F_79 ( V_37 ) ;
break;
}
if ( V_41 -> V_124 . V_125 != V_126 )
goto V_114;
switch ( V_113 & V_121 ) {
case V_127 :
return F_64 ( V_107 , V_128 ,
& V_109 , NULL , V_37 , V_37 -> V_7 , NULL ,
F_67 ) ;
case V_129 :
case V_130 :
return F_64 ( V_107 , V_131 ,
& V_109 , NULL , V_37 , V_37 -> V_7 , NULL ,
F_66 ) ;
case V_132 :
return F_64 ( V_107 , V_128 ,
& V_109 , NULL , V_37 , V_37 -> V_7 , NULL ,
V_133 ) ;
case V_134 :
return F_64 ( V_107 , V_128 ,
& V_109 , NULL , V_37 , V_37 -> V_7 , NULL ,
V_135 ) ;
}
} else {
if ( V_41 -> V_124 . V_125 != V_126 )
goto V_114;
F_61 ( V_37 , 1 ) ;
switch ( V_113 & V_101 ) {
case V_103 :
return F_59 ( V_37 ) ;
case V_102 :
return F_65 ( V_37 ) ;
}
}
V_114:
F_58 ( V_37 ) ;
V_115:
return V_81 ;
}
static int F_80 ( struct V_93 * V_93 , struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_81 ( V_37 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_76 * V_77 = F_49 ( V_37 ) ;
int V_94 = - V_136 ;
if ( V_4 -> V_5 == NULL )
goto error;
V_37 -> V_7 = V_7 ;
V_77 -> V_11 = V_4 -> V_137 ;
V_77 -> V_2 = V_4 -> V_138 ;
V_77 -> V_82 &= ~ V_83 ;
V_77 -> V_82 |= V_139 ;
V_77 -> V_106 = 0 ;
return F_64 ( V_107 , V_140 ,
& V_109 , V_35 , V_37 , NULL , V_7 ,
V_141 ) ;
error:
F_82 ( L_4 ) ;
F_58 ( V_37 ) ;
return V_94 ;
}
static int F_83 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_49 ( V_37 ) ;
struct V_1 * V_2 = F_81 ( V_37 ) ;
struct V_40 * V_142 = F_71 ( V_2 -> V_7 -> V_42 ) ;
struct V_3 * V_4 ;
int V_143 ;
struct V_6 * V_7 = V_37 -> V_7 ;
if ( V_37 -> V_85 != V_100 )
goto V_144;
V_4 = (struct V_3 * ) F_81 ( V_37 ) ;
V_143 = V_142 -> V_43 ? 21 : 6 ;
if ( F_84 ( V_37 , F_85 ( V_4 -> V_2 . V_7 ) + V_143 ) )
goto V_144;
if ( ++ V_77 -> V_106 > 30 )
goto V_144;
V_37 -> V_7 = V_4 -> V_2 . V_7 ;
V_77 -> V_82 &= ~ V_139 ;
if ( V_4 -> V_82 & V_145 )
V_77 -> V_82 |= V_139 ;
return F_64 ( V_107 , V_146 ,
& V_109 , NULL , V_37 , V_7 , V_37 -> V_7 ,
V_141 ) ;
V_144:
F_58 ( V_37 ) ;
return V_81 ;
}
static int F_86 ( struct V_93 * V_93 , struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_76 * V_77 = F_49 ( V_37 ) ;
F_82 ( L_5 ,
F_57 ( V_77 -> V_11 ) , F_57 ( V_77 -> V_2 ) ) ;
F_58 ( V_37 ) ;
return V_81 ;
}
static int F_87 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_49 ( V_37 ) ;
F_82 ( L_5 ,
F_57 ( V_77 -> V_11 ) , F_57 ( V_77 -> V_2 ) ) ;
F_58 ( V_37 ) ;
return V_81 ;
}
static unsigned int F_88 ( const struct V_1 * V_2 )
{
return F_89 ( V_2 -> V_7 , F_90 ( V_2 ) ) ;
}
static unsigned int F_91 ( const struct V_1 * V_2 )
{
unsigned int V_38 = F_27 ( V_2 , V_44 ) ;
return V_38 ? : V_2 -> V_7 -> V_38 ;
}
static struct V_9 * F_92 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const void * V_54 )
{
return F_93 ( & V_147 , V_54 , V_2 -> V_7 ) ;
}
static int F_94 ( struct V_3 * V_4 , struct V_148 * V_149 )
{
struct V_150 * V_151 = V_149 -> V_151 ;
struct V_6 * V_7 = V_4 -> V_2 . V_7 ;
unsigned int V_152 ;
struct V_9 * V_5 ;
if ( V_151 ) {
if ( F_95 ( * V_149 ) &&
F_96 ( * V_149 ) . V_153 == V_154 )
V_4 -> V_155 = F_95 ( * V_149 ) ;
F_97 ( & V_4 -> V_2 , V_151 -> V_156 , true ) ;
}
V_4 -> V_157 = V_149 -> type ;
if ( V_7 != NULL && V_4 -> V_5 == NULL ) {
V_5 = F_93 ( & V_147 , & V_4 -> V_155 , V_7 ) ;
if ( F_98 ( V_5 ) )
return F_99 ( V_5 ) ;
V_4 -> V_5 = V_5 ;
}
if ( F_23 ( & V_4 -> V_2 , V_44 ) > V_4 -> V_2 . V_7 -> V_38 )
F_25 ( & V_4 -> V_2 , V_44 , V_4 -> V_2 . V_7 -> V_38 ) ;
V_152 = F_27 ( & V_4 -> V_2 , V_46 ) ;
if ( V_152 ) {
unsigned int V_47 = F_89 ( V_7 , F_90 ( & V_4 -> V_2 ) ) ;
if ( V_152 > V_47 )
F_25 ( & V_4 -> V_2 , V_46 , V_47 ) ;
}
return 0 ;
}
static inline int F_100 ( T_2 V_158 , T_2 V_159 )
{
T_3 V_12 = F_57 ( V_158 ) ^ F_57 ( V_159 ) ;
int V_160 = 16 ;
while( V_12 ) {
V_12 >>= 1 ;
V_160 -- ;
}
return V_160 ;
}
static T_2 F_101 ( const struct V_6 * V_7 , T_2 V_54 , int V_161 )
{
T_2 V_55 = 0 ;
struct V_40 * V_142 ;
struct V_162 * V_163 ;
int V_164 = 0 ;
int V_165 ;
F_102 () ;
V_142 = F_71 ( V_7 -> V_42 ) ;
for ( V_163 = F_71 ( V_142 -> V_166 ) ;
V_163 != NULL ;
V_163 = F_71 ( V_163 -> V_167 ) ) {
if ( V_163 -> V_168 > V_161 )
continue;
if ( ! V_54 ) {
V_55 = V_163 -> V_169 ;
break;
}
V_165 = F_100 ( V_54 , V_163 -> V_169 ) ;
if ( V_165 > V_164 )
V_55 = V_163 -> V_169 ;
if ( V_164 == 0 )
V_55 = V_163 -> V_169 ;
}
F_103 () ;
return V_55 ;
}
static inline T_2 F_104 ( struct V_148 * V_149 )
{
return F_101 ( F_105 ( * V_149 ) , F_95 ( * V_149 ) , V_149 -> V_161 ) ;
}
static inline T_2 F_106 ( T_2 V_54 , struct V_148 * V_149 )
{
T_2 V_170 = F_107 ( V_149 -> V_171 ) ;
return ( V_54 & ~ V_170 ) | V_149 -> V_151 -> V_172 -> V_173 ;
}
static int F_108 ( struct V_1 * * V_174 , const struct V_51 * V_175 , int V_176 )
{
struct V_51 V_64 = {
. V_54 = V_175 -> V_54 ,
. V_55 = V_175 -> V_55 ,
. V_57 = V_177 ,
. V_56 = V_175 -> V_56 ,
. V_59 = V_178 ,
. V_58 = V_175 -> V_58 ,
} ;
struct V_3 * V_4 = NULL ;
struct V_6 * V_179 = NULL , * V_7 ;
struct V_9 * V_180 = NULL ;
unsigned int V_60 ;
unsigned int V_113 = 0 ;
struct V_148 V_149 = { . V_151 = NULL , . type = V_181 } ;
int V_94 ;
int V_182 = 0 ;
T_2 V_183 = 0 ;
if ( V_95 & 16 )
F_56 ( V_98
L_6
L_7 , F_57 ( V_175 -> V_54 ) ,
F_57 ( V_175 -> V_55 ) ,
V_175 -> V_56 , V_178 ,
V_175 -> V_58 ) ;
if ( V_175 -> V_58 ) {
V_179 = F_109 ( & V_109 , V_175 -> V_58 ) ;
V_94 = - V_184 ;
if ( V_179 && V_179 -> V_42 == NULL ) {
F_7 ( V_179 ) ;
V_179 = NULL ;
}
if ( V_179 == NULL )
goto V_115;
}
if ( V_175 -> V_55 ) {
V_94 = - V_185 ;
if ( V_179 ) {
if ( F_110 ( V_179 , V_175 -> V_55 ) )
goto V_186;
F_7 ( V_179 ) ;
goto V_115;
}
F_102 () ;
F_111 (&init_net, dev) {
if ( ! V_7 -> V_42 )
continue;
if ( ! F_110 ( V_7 , V_175 -> V_55 ) )
continue;
if ( ( V_7 -> V_113 & V_187 ) &&
V_175 -> V_54 &&
! F_110 ( V_7 , V_175 -> V_54 ) )
continue;
V_179 = V_7 ;
break;
}
F_103 () ;
if ( V_179 == NULL )
goto V_115;
F_6 ( V_179 ) ;
V_186:
;
}
if ( ! V_64 . V_54 ) {
V_64 . V_54 = V_64 . V_55 ;
if ( V_179 )
F_7 ( V_179 ) ;
V_94 = - V_136 ;
V_179 = V_109 . V_10 ;
if ( ! V_179 -> V_42 )
goto V_115;
V_94 = - V_185 ;
F_6 ( V_179 ) ;
if ( ! V_64 . V_54 ) {
V_64 . V_54 =
V_64 . V_55 = F_101 ( V_179 , 0 ,
V_188 ) ;
if ( ! V_64 . V_54 )
goto V_115;
}
V_64 . V_58 = V_178 ;
V_149 . type = V_189 ;
goto V_190;
}
if ( V_95 & 16 )
F_56 ( V_98
L_8
L_9 ,
F_57 ( V_64 . V_54 ) , F_57 ( V_64 . V_55 ) ,
V_64 . V_58 , V_176 ) ;
V_94 = - V_191 ;
if ( V_176 || ( V_94 = F_112 ( & V_64 , & V_149 ) ) != 0 ) {
struct V_40 * V_142 ;
if ( V_94 != - V_191 )
goto V_115;
if ( ! V_176 ) {
V_180 = F_113 ( & V_147 , & V_109 , & V_64 . V_54 ) ;
if ( V_180 ) {
if ( ( V_175 -> V_58 &&
( V_180 -> V_7 -> V_118 != V_175 -> V_58 ) ) ||
( V_175 -> V_55 &&
( ! F_110 ( V_180 -> V_7 ,
V_175 -> V_55 ) ) ) ) {
F_2 ( V_180 ) ;
V_180 = NULL ;
} else {
if ( V_179 )
F_7 ( V_179 ) ;
if ( F_110 ( V_180 -> V_7 , V_64 . V_54 ) ) {
V_179 = V_109 . V_10 ;
V_149 . type = V_189 ;
} else {
V_179 = V_180 -> V_7 ;
}
F_6 ( V_179 ) ;
goto V_192;
}
}
}
if ( V_179 == NULL )
V_179 = F_114 () ;
V_94 = - V_184 ;
if ( V_179 == NULL )
goto V_115;
V_142 = F_22 ( V_179 -> V_42 ) ;
if ( ! V_142 )
goto V_193;
if ( F_110 ( V_179 , V_64 . V_54 ) ) {
F_7 ( V_179 ) ;
V_179 = V_109 . V_10 ;
F_6 ( V_179 ) ;
V_149 . type = V_189 ;
goto V_192;
}
V_180 = F_115 ( V_142 -> V_194 ) ;
F_116 ( V_180 && V_180 -> V_7 != V_179 ) ;
V_192:
if ( V_180 )
V_183 = ( (struct V_195 * ) V_180 ) -> V_196 ;
if ( V_183 == 0 )
V_183 = V_64 . V_54 ;
if ( V_64 . V_55 == 0 ) {
V_64 . V_55 = F_101 ( V_179 , V_183 ,
V_149 . type == V_189 ?
V_188 :
V_154 ) ;
if ( V_64 . V_55 == 0 && V_149 . type != V_189 )
goto V_197;
}
V_64 . V_58 = V_179 -> V_118 ;
goto V_190;
}
V_182 = 1 ;
if ( V_149 . type == V_198 )
goto V_193;
if ( V_149 . type == V_189 ) {
if ( ! V_64 . V_55 )
V_64 . V_55 = V_64 . V_54 ;
if ( V_179 )
F_7 ( V_179 ) ;
V_179 = V_109 . V_10 ;
F_6 ( V_179 ) ;
if ( ! V_179 -> V_42 )
goto V_193;
V_64 . V_58 = V_179 -> V_118 ;
if ( V_149 . V_151 )
F_117 ( V_149 . V_151 ) ;
V_149 . V_151 = NULL ;
goto V_190;
}
if ( V_149 . V_151 -> V_199 > 1 && V_64 . V_58 == 0 )
F_118 ( & V_64 , & V_149 ) ;
if ( ! V_64 . V_55 )
V_64 . V_55 = F_119 ( V_149 ) ;
if ( V_179 )
F_7 ( V_179 ) ;
V_179 = F_105 ( V_149 ) ;
F_6 ( V_179 ) ;
V_64 . V_58 = V_179 -> V_118 ;
V_183 = F_95 ( V_149 ) ;
V_190:
if ( V_179 -> V_113 & V_187 )
V_113 |= V_200 ;
V_4 = F_120 ( & V_201 , V_179 , 0 , V_202 , V_203 ) ;
if ( V_4 == NULL )
goto V_204;
memset ( & V_4 -> V_64 , 0 , sizeof( V_4 -> V_64 ) ) ;
V_4 -> V_64 . V_55 = V_175 -> V_55 ;
V_4 -> V_64 . V_54 = V_175 -> V_54 ;
V_4 -> V_64 . V_58 = V_175 -> V_58 ;
V_4 -> V_64 . V_59 = 0 ;
V_4 -> V_64 . V_56 = V_175 -> V_56 ;
V_4 -> V_137 = V_64 . V_55 ;
V_4 -> V_138 = V_64 . V_54 ;
V_4 -> V_155 = V_183 ? V_183 : V_64 . V_54 ;
V_4 -> V_205 = V_64 . V_55 ;
V_4 -> V_206 = V_64 . V_54 ;
V_4 -> V_207 = V_64 . V_55 ;
V_4 -> V_5 = V_180 ;
V_180 = NULL ;
V_4 -> V_2 . V_28 = V_21 ;
V_4 -> V_2 . V_208 = F_80 ;
V_4 -> V_2 . V_209 = F_87 ;
V_4 -> V_82 = V_113 ;
if ( V_113 & V_200 )
V_4 -> V_2 . V_209 = V_210 ;
V_94 = F_94 ( V_4 , & V_149 ) ;
if ( V_94 )
goto V_211;
V_60 = F_8 ( V_4 -> V_64 . V_55 , V_4 -> V_64 . V_54 ) ;
F_34 ( V_4 , V_60 , (struct V_3 * * ) V_174 ) ;
V_212:
if ( V_180 )
F_2 ( V_180 ) ;
if ( V_182 )
F_121 ( & V_149 ) ;
if ( V_179 )
F_7 ( V_179 ) ;
V_115:
return V_94 ;
V_197:
V_94 = - V_185 ;
goto V_212;
V_193:
V_94 = - V_136 ;
goto V_212;
V_204:
V_94 = - V_213 ;
goto V_212;
V_211:
F_37 ( & V_4 -> V_2 ) ;
goto V_204;
}
static int F_122 ( struct V_1 * * V_174 , const struct V_51 * V_214 , int V_113 )
{
unsigned int V_60 = F_8 ( V_214 -> V_55 , V_214 -> V_54 ) ;
struct V_3 * V_4 = NULL ;
if ( ! ( V_113 & V_215 ) ) {
F_123 () ;
for ( V_4 = F_124 ( V_24 [ V_60 ] . V_25 ) ; V_4 ;
V_4 = F_124 ( V_4 -> V_2 . V_29 ) ) {
if ( ( V_214 -> V_54 == V_4 -> V_64 . V_54 ) &&
( V_214 -> V_55 == V_4 -> V_64 . V_55 ) &&
( V_214 -> V_56 == V_4 -> V_64 . V_56 ) &&
F_125 ( V_4 ) &&
( V_4 -> V_64 . V_58 == V_214 -> V_58 ) ) {
F_36 ( & V_4 -> V_2 , V_21 ) ;
F_126 () ;
* V_174 = & V_4 -> V_2 ;
return 0 ;
}
}
F_126 () ;
}
return F_108 ( V_174 , V_214 , V_113 ) ;
}
static int F_127 ( struct V_1 * * V_174 , struct V_51 * V_214 , int V_113 )
{
int V_94 ;
V_94 = F_122 ( V_174 , V_214 , V_113 ) ;
if ( V_94 == 0 && V_214 -> V_216 ) {
* V_174 = F_128 ( & V_109 , * V_174 ,
F_129 ( V_214 ) , NULL , 0 ) ;
if ( F_98 ( * V_174 ) ) {
V_94 = F_99 ( * V_174 ) ;
* V_174 = NULL ;
}
}
return V_94 ;
}
int F_130 ( struct V_1 T_4 * * V_174 , struct V_51 * V_217 , struct V_34 * V_35 , int V_113 )
{
int V_94 ;
V_94 = F_122 ( V_174 , V_217 , V_113 & V_215 ) ;
if ( V_94 == 0 && V_217 -> V_216 ) {
* V_174 = F_128 ( & V_109 , * V_174 ,
F_129 ( V_217 ) , V_35 , 0 ) ;
if ( F_98 ( * V_174 ) ) {
V_94 = F_99 ( * V_174 ) ;
* V_174 = NULL ;
}
}
return V_94 ;
}
static int F_131 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = NULL ;
struct V_76 * V_77 = F_49 ( V_37 ) ;
struct V_6 * V_218 = V_37 -> V_7 ;
struct V_6 * V_219 = NULL ;
struct V_40 * V_142 ;
struct V_9 * V_180 = NULL ;
unsigned int V_60 ;
int V_113 = 0 ;
T_2 V_183 = 0 ;
T_2 V_220 = 0 ;
struct V_51 V_64 = {
. V_54 = V_77 -> V_2 ,
. V_55 = V_77 -> V_11 ,
. V_57 = V_177 ,
. V_56 = V_37 -> V_221 ,
. V_59 = V_37 -> V_7 -> V_118 ,
} ;
struct V_148 V_149 = { . V_151 = NULL , . type = V_222 } ;
int V_94 = - V_136 ;
int V_182 = 0 ;
F_6 ( V_218 ) ;
if ( ( V_142 = F_71 ( V_218 -> V_42 ) ) == NULL )
goto V_115;
if ( V_64 . V_55 == 0 )
goto V_115;
V_94 = - V_223 ;
if ( F_110 ( V_218 , V_77 -> V_11 ) )
goto V_115;
V_94 = F_112 ( & V_64 , & V_149 ) ;
if ( V_94 ) {
if ( V_94 != - V_191 )
goto V_115;
if ( ! F_110 ( V_218 , V_77 -> V_2 ) )
goto V_193;
V_149 . type = V_189 ;
} else {
T_2 V_224 = V_64 . V_55 ;
V_182 = 1 ;
V_219 = F_105 ( V_149 ) ;
if ( V_219 == NULL ) {
F_132 ( L_10 ) ;
goto V_193;
}
F_6 ( V_219 ) ;
if ( V_149 . V_225 )
V_224 = V_64 . V_55 ;
V_183 = F_95 ( V_149 ) ;
if ( V_149 . type == V_198 ) {
V_64 . V_54 = F_106 ( V_64 . V_54 , & V_149 ) ;
F_121 ( & V_149 ) ;
V_182 = 0 ;
if ( F_112 ( & V_64 , & V_149 ) )
goto V_193;
V_182 = 1 ;
if ( V_149 . type != V_181 )
goto V_193;
V_113 |= V_226 ;
V_183 = V_64 . V_54 ;
}
V_64 . V_55 = V_224 ;
}
switch( V_149 . type ) {
case V_181 :
if ( V_142 -> V_124 . V_227 == 0 )
goto V_193;
if ( V_149 . V_151 -> V_199 > 1 && V_64 . V_58 == 0 )
F_118 ( & V_64 , & V_149 ) ;
if ( V_219 == V_218 && ! ( V_113 & V_228 ) )
V_113 |= V_145 ;
V_220 = F_119 ( V_149 ) ;
case V_229 :
case V_222 :
break;
case V_189 :
V_113 |= V_200 ;
V_64 . V_55 = V_77 -> V_2 ;
V_64 . V_54 = V_77 -> V_11 ;
if ( V_183 )
goto V_190;
if ( V_77 -> V_82 & V_139 ) {
V_183 = V_77 -> V_11 ;
goto V_190;
}
V_180 = F_115 ( V_142 -> V_194 ) ;
if ( V_180 ) {
V_183 = ( (struct V_195 * ) V_180 ) -> V_196 ;
goto V_190;
}
V_183 = V_77 -> V_11 ;
goto V_190;
default:
goto V_193;
}
V_190:
V_4 = F_120 ( & V_201 , V_219 , 0 , V_202 , V_203 ) ;
if ( V_4 == NULL )
goto V_204;
memset ( & V_4 -> V_64 , 0 , sizeof( V_4 -> V_64 ) ) ;
V_4 -> V_137 = V_64 . V_55 ;
V_4 -> V_138 = V_64 . V_54 ;
V_4 -> V_155 = V_64 . V_54 ;
if ( V_183 )
V_4 -> V_155 = V_183 ;
V_4 -> V_205 = V_220 ? V_220 : V_4 -> V_137 ;
V_4 -> V_206 = V_64 . V_54 ;
V_4 -> V_207 = V_64 . V_55 ;
V_4 -> V_64 . V_55 = V_77 -> V_11 ;
V_4 -> V_64 . V_54 = V_77 -> V_2 ;
V_4 -> V_64 . V_58 = 0 ;
V_4 -> V_64 . V_59 = V_218 -> V_118 ;
V_4 -> V_64 . V_56 = V_64 . V_56 ;
V_4 -> V_5 = V_180 ;
V_4 -> V_2 . V_28 = V_21 ;
V_4 -> V_2 . V_208 = F_86 ;
switch ( V_149 . type ) {
case V_181 :
V_4 -> V_2 . V_209 = F_83 ;
break;
case V_189 :
V_4 -> V_2 . V_208 = F_80 ;
V_4 -> V_2 . V_209 = V_210 ;
V_4 -> V_2 . V_7 = V_218 ;
V_113 |= V_200 ;
break;
default:
case V_222 :
case V_229 :
V_4 -> V_2 . V_209 = V_230 ;
}
V_4 -> V_82 = V_113 ;
V_94 = F_94 ( V_4 , & V_149 ) ;
if ( V_94 )
goto V_211;
V_60 = F_8 ( V_4 -> V_64 . V_55 , V_4 -> V_64 . V_54 ) ;
F_34 ( V_4 , V_60 , & V_4 ) ;
F_133 ( V_37 , & V_4 -> V_2 ) ;
V_212:
if ( V_180 )
F_2 ( V_180 ) ;
if ( V_182 )
F_121 ( & V_149 ) ;
F_7 ( V_218 ) ;
if ( V_219 )
F_7 ( V_219 ) ;
V_115:
return V_94 ;
V_193:
V_94 = - V_136 ;
goto V_212;
V_204:
V_94 = - V_213 ;
goto V_212;
V_211:
F_37 ( & V_4 -> V_2 ) ;
goto V_212;
}
static int F_54 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_76 * V_77 = F_49 ( V_37 ) ;
unsigned int V_60 = F_8 ( V_77 -> V_11 , V_77 -> V_2 ) ;
if ( F_81 ( V_37 ) )
return 0 ;
F_102 () ;
for( V_4 = F_71 ( V_24 [ V_60 ] . V_25 ) ; V_4 != NULL ;
V_4 = F_71 ( V_4 -> V_2 . V_29 ) ) {
if ( ( V_4 -> V_64 . V_55 == V_77 -> V_11 ) &&
( V_4 -> V_64 . V_54 == V_77 -> V_2 ) &&
( V_4 -> V_64 . V_58 == 0 ) &&
( V_4 -> V_64 . V_56 == V_37 -> V_221 ) &&
( V_4 -> V_64 . V_59 == V_77 -> V_117 ) ) {
F_36 ( & V_4 -> V_2 , V_21 ) ;
F_103 () ;
F_133 ( V_37 , (struct V_1 * ) V_4 ) ;
return 0 ;
}
}
F_103 () ;
return F_131 ( V_37 ) ;
}
static int F_134 ( struct V_36 * V_37 , T_5 V_231 , T_5 V_232 ,
int V_233 , int V_234 , unsigned int V_113 )
{
struct V_3 * V_4 = (struct V_3 * ) F_81 ( V_37 ) ;
struct V_235 * V_225 ;
struct V_236 * V_237 ;
long V_75 ;
V_237 = F_135 ( V_37 , V_231 , V_232 , V_233 , sizeof( * V_225 ) , V_113 ) ;
if ( ! V_237 )
return - V_238 ;
V_225 = F_136 ( V_237 ) ;
V_225 -> V_239 = V_240 ;
V_225 -> V_241 = 16 ;
V_225 -> V_242 = 0 ;
V_225 -> V_243 = 0 ;
V_225 -> V_244 = V_245 ;
V_225 -> V_246 = V_4 -> V_157 ;
V_225 -> V_247 = ( V_4 -> V_82 & ~ 0xFFFF ) | V_248 ;
V_225 -> V_249 = V_177 ;
V_225 -> V_250 = V_251 ;
if ( V_4 -> V_82 & V_252 )
V_225 -> V_247 |= V_253 ;
if ( F_137 ( V_37 , V_254 , V_245 ) < 0 ||
F_138 ( V_37 , V_255 , V_4 -> V_138 ) < 0 )
goto V_256;
if ( V_4 -> V_64 . V_55 ) {
V_225 -> V_242 = 16 ;
if ( F_138 ( V_37 , V_257 , V_4 -> V_64 . V_55 ) < 0 )
goto V_256;
}
if ( V_4 -> V_2 . V_7 &&
F_137 ( V_37 , V_258 , V_4 -> V_2 . V_7 -> V_118 ) < 0 )
goto V_256;
if ( F_138 ( V_37 , V_259 , V_4 -> V_205 ) < 0 )
goto V_256;
if ( V_4 -> V_138 != V_4 -> V_155 &&
F_138 ( V_37 , V_260 , V_4 -> V_155 ) < 0 )
goto V_256;
if ( F_139 ( V_37 , F_140 ( & V_4 -> V_2 ) ) < 0 )
goto V_256;
V_75 = V_4 -> V_2 . V_75 ? V_4 -> V_2 . V_75 - V_21 : 0 ;
if ( F_141 ( V_37 , & V_4 -> V_2 , 0 , V_75 ,
V_4 -> V_2 . error ) < 0 )
goto V_256;
if ( F_142 ( V_4 ) &&
F_137 ( V_37 , V_261 , V_4 -> V_64 . V_59 ) < 0 )
goto V_256;
F_143 ( V_37 , V_237 ) ;
return 0 ;
V_256:
F_144 ( V_37 , V_237 ) ;
return - V_238 ;
}
static int F_145 ( struct V_36 * V_262 , struct V_236 * V_237 ,
struct V_263 * V_264 )
{
struct V_93 * V_93 = F_146 ( V_262 -> V_35 ) ;
struct V_235 * V_265 = F_136 ( V_237 ) ;
struct V_3 * V_4 = NULL ;
struct V_76 * V_77 ;
int V_94 ;
struct V_36 * V_37 ;
struct V_51 V_64 ;
struct V_266 * V_267 [ V_268 + 1 ] ;
if ( ! F_72 ( V_93 , & V_109 ) )
return - V_136 ;
V_94 = F_147 ( V_237 , sizeof( * V_265 ) , V_267 , V_268 , V_269 ,
V_264 ) ;
if ( V_94 < 0 )
return V_94 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_216 = V_270 ;
V_37 = F_148 ( V_271 , V_272 ) ;
if ( V_37 == NULL )
return - V_213 ;
F_149 ( V_37 ) ;
V_77 = F_49 ( V_37 ) ;
if ( V_267 [ V_257 ] )
V_64 . V_55 = F_150 ( V_267 [ V_257 ] ) ;
if ( V_267 [ V_255 ] )
V_64 . V_54 = F_150 ( V_267 [ V_255 ] ) ;
if ( V_267 [ V_261 ] )
V_64 . V_59 = F_151 ( V_267 [ V_261 ] ) ;
if ( V_64 . V_59 ) {
struct V_6 * V_7 ;
V_7 = F_152 ( & V_109 , V_64 . V_59 ) ;
if ( ! V_7 || ! V_7 -> V_42 ) {
F_58 ( V_37 ) ;
return - V_184 ;
}
V_37 -> V_273 = F_153 ( V_274 ) ;
V_37 -> V_7 = V_7 ;
V_77 -> V_11 = V_64 . V_55 ;
V_77 -> V_2 = V_64 . V_54 ;
F_154 () ;
V_94 = F_54 ( V_37 ) ;
F_155 () ;
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_4 = (struct V_3 * ) F_81 ( V_37 ) ;
if ( ! V_94 && - V_4 -> V_2 . error )
V_94 = V_4 -> V_2 . error ;
} else {
if ( V_267 [ V_258 ] )
V_64 . V_58 = F_151 ( V_267 [ V_258 ] ) ;
V_94 = F_127 ( (struct V_1 * * ) & V_4 , & V_64 , 0 ) ;
}
V_37 -> V_7 = NULL ;
if ( V_94 )
goto V_275;
F_133 ( V_37 , & V_4 -> V_2 ) ;
if ( V_265 -> V_247 & V_253 )
V_4 -> V_82 |= V_252 ;
V_94 = F_134 ( V_37 , F_156 ( V_262 ) . V_231 , V_237 -> V_276 , V_277 , 0 , 0 ) ;
if ( V_94 < 0 ) {
V_94 = - V_238 ;
goto V_275;
}
return F_157 ( V_37 , & V_109 , F_156 ( V_262 ) . V_231 ) ;
V_275:
F_58 ( V_37 ) ;
return V_94 ;
}
int F_158 ( struct V_36 * V_37 , struct V_278 * V_77 )
{
struct V_93 * V_93 = F_146 ( V_37 -> V_35 ) ;
struct V_3 * V_4 ;
int V_279 , V_280 ;
int V_281 , V_282 ;
struct V_235 * V_265 ;
if ( ! F_72 ( V_93 , & V_109 ) )
return 0 ;
if ( F_159 ( V_77 -> V_237 ) < sizeof( struct V_235 ) )
return - V_136 ;
V_265 = F_136 ( V_77 -> V_237 ) ;
if ( ! ( V_265 -> V_247 & V_248 ) )
return 0 ;
V_280 = V_77 -> args [ 0 ] ;
V_282 = V_281 = V_77 -> args [ 1 ] ;
for( V_279 = 0 ; V_279 <= V_14 ; V_279 ++ ) {
if ( V_279 < V_280 )
continue;
if ( V_279 > V_280 )
V_282 = 0 ;
F_123 () ;
for( V_4 = F_124 ( V_24 [ V_279 ] . V_25 ) , V_281 = 0 ;
V_4 ;
V_4 = F_124 ( V_4 -> V_2 . V_29 ) , V_281 ++ ) {
if ( V_281 < V_282 )
continue;
F_133 ( V_37 , F_160 ( & V_4 -> V_2 ) ) ;
if ( F_134 ( V_37 , F_156 ( V_77 -> V_37 ) . V_231 ,
V_77 -> V_237 -> V_276 , V_277 ,
1 , V_283 ) < 0 ) {
F_161 ( V_37 ) ;
F_126 () ;
goto V_212;
}
F_161 ( V_37 ) ;
}
F_126 () ;
}
V_212:
V_77 -> args [ 0 ] = V_279 ;
V_77 -> args [ 1 ] = V_281 ;
return V_37 -> V_99 ;
}
static struct V_3 * F_162 ( struct V_284 * V_232 )
{
struct V_3 * V_4 = NULL ;
struct V_285 * V_286 = V_232 -> V_287 ;
for( V_286 -> V_288 = V_14 ; V_286 -> V_288 >= 0 ; -- V_286 -> V_288 ) {
F_123 () ;
V_4 = F_124 ( V_24 [ V_286 -> V_288 ] . V_25 ) ;
if ( V_4 )
break;
F_126 () ;
}
return V_4 ;
}
static struct V_3 * F_163 ( struct V_284 * V_232 , struct V_3 * V_4 )
{
struct V_285 * V_286 = V_232 -> V_287 ;
V_4 = F_124 ( V_4 -> V_2 . V_29 ) ;
while ( ! V_4 ) {
F_126 () ;
if ( -- V_286 -> V_288 < 0 )
break;
F_123 () ;
V_4 = F_124 ( V_24 [ V_286 -> V_288 ] . V_25 ) ;
}
return V_4 ;
}
static void * F_164 ( struct V_284 * V_232 , T_7 * V_289 )
{
struct V_3 * V_4 = F_162 ( V_232 ) ;
if ( V_4 ) {
while( * V_289 && ( V_4 = F_163 ( V_232 , V_4 ) ) )
-- * V_289 ;
}
return * V_289 ? NULL : V_4 ;
}
static void * F_165 ( struct V_284 * V_232 , void * V_290 , T_7 * V_289 )
{
struct V_3 * V_4 = F_163 ( V_232 , V_290 ) ;
++ * V_289 ;
return V_4 ;
}
static void F_166 ( struct V_284 * V_232 , void * V_290 )
{
if ( V_290 )
F_126 () ;
}
static int F_167 ( struct V_284 * V_232 , void * V_290 )
{
struct V_3 * V_4 = V_290 ;
char V_291 [ V_292 ] , V_293 [ V_292 ] ;
F_168 ( V_232 , L_11 ,
V_4 -> V_2 . V_7 ? V_4 -> V_2 . V_7 -> V_97 : L_12 ,
F_169 ( F_57 ( V_4 -> V_138 ) , V_291 ) ,
F_169 ( F_57 ( V_4 -> V_137 ) , V_293 ) ,
F_15 ( & V_4 -> V_2 . V_27 ) ,
V_4 -> V_2 . V_294 , 0 ) ;
return 0 ;
}
static int F_170 ( struct V_295 * V_295 , struct V_296 * V_296 )
{
return F_171 ( V_296 , & V_297 ,
sizeof( struct V_285 ) ) ;
}
void T_8 F_172 ( void )
{
int V_18 , V_298 , V_299 ;
V_201 . V_300 =
F_173 ( L_13 , sizeof( struct V_3 ) , 0 ,
V_301 | V_302 , NULL ) ;
F_174 ( & V_201 ) ;
F_175 ( & V_30 , F_11 , 0 ) ;
V_30 . V_75 = V_21 + V_31 * V_23 ;
F_44 ( & V_30 ) ;
V_298 = V_303 >> ( 26 - V_304 ) ;
for( V_299 = 0 ; ( 1UL << V_299 ) < V_298 ; V_299 ++ )
;
while( V_299 && ( ( ( ( 1UL << V_299 ) * V_305 ) /
sizeof( struct V_306 ) ) >= 2048 ) )
V_299 -- ;
do {
V_14 = ( 1UL << V_299 ) * V_305 /
sizeof( struct V_306 ) ;
while( V_14 & ( V_14 - 1 ) )
V_14 -- ;
V_24 = (struct V_306 * )
F_176 ( V_80 , V_299 ) ;
} while ( V_24 == NULL && -- V_299 > 0 );
if ( ! V_24 )
F_177 ( L_14 ) ;
F_56 ( V_307
L_15 ,
V_14 ,
( long ) ( V_14 * sizeof( struct V_306 ) ) / 1024 ) ;
V_14 -- ;
for( V_18 = 0 ; V_18 <= V_14 ; V_18 ++ ) {
F_178 ( & V_24 [ V_18 ] . V_26 ) ;
V_24 [ V_18 ] . V_25 = NULL ;
}
V_201 . V_308 = ( V_14 + 1 ) ;
F_179 ( L_16 , V_309 , V_109 . V_310 ,
& V_311 ) ;
#ifdef F_180
F_181 ( V_312 , V_313 , F_145 ,
V_314 , NULL ) ;
#else
F_181 ( V_312 , V_313 , F_145 ,
F_158 , NULL ) ;
#endif
}
void T_9 F_182 ( void )
{
F_43 ( & V_30 ) ;
F_38 ( 0 ) ;
F_183 ( L_16 , V_109 . V_310 ) ;
F_184 ( & V_201 ) ;
}
