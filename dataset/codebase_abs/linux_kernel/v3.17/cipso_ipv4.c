static int F_1 ( const unsigned char * V_1 ,
T_1 V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
unsigned char V_7 ;
unsigned char V_8 ;
V_6 = V_3 / 8 ;
V_8 = V_1 [ V_6 ] ;
V_5 = V_3 ;
V_7 = 0x80 >> ( V_3 % 8 ) ;
while ( V_5 < V_2 ) {
if ( ( V_4 && ( V_8 & V_7 ) == V_7 ) ||
( V_4 == 0 && ( V_8 & V_7 ) == 0 ) )
return V_5 ;
V_5 ++ ;
V_7 >>= 1 ;
if ( V_7 == 0 ) {
V_8 = V_1 [ ++ V_6 ] ;
V_7 = 0x80 ;
}
}
return - 1 ;
}
static void F_2 ( unsigned char * V_1 ,
T_1 V_9 ,
T_2 V_4 )
{
T_1 V_10 ;
T_2 V_7 ;
V_10 = V_9 / 8 ;
V_7 = 0x80 >> ( V_9 % 8 ) ;
if ( V_4 )
V_1 [ V_10 ] |= V_7 ;
else
V_1 [ V_10 ] &= ~ V_7 ;
}
static void F_3 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 )
F_4 ( V_12 -> V_13 ) ;
F_5 ( V_12 -> V_14 ) ;
F_5 ( V_12 ) ;
}
static T_1 F_6 ( const unsigned char * V_14 , T_1 V_15 )
{
return F_7 ( V_14 , V_15 , 0 ) ;
}
static int F_8 ( void )
{
T_1 V_16 ;
V_17 = F_9 ( V_18 ,
sizeof( struct V_19 ) ,
V_20 ) ;
if ( V_17 == NULL )
return - V_21 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
F_10 ( & V_17 [ V_16 ] . V_22 ) ;
V_17 [ V_16 ] . V_23 = 0 ;
F_11 ( & V_17 [ V_16 ] . V_24 ) ;
}
return 0 ;
}
void F_12 ( void )
{
struct V_11 * V_12 , * V_25 ;
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
F_13 ( & V_17 [ V_16 ] . V_22 ) ;
F_14 (entry,
tmp_entry,
&cipso_v4_cache[iter].list, list) {
F_15 ( & V_12 -> V_24 ) ;
F_3 ( V_12 ) ;
}
V_17 [ V_16 ] . V_23 = 0 ;
F_16 ( & V_17 [ V_16 ] . V_22 ) ;
}
}
static int F_17 ( const unsigned char * V_14 ,
T_1 V_15 ,
struct V_26 * V_27 )
{
T_1 V_28 ;
struct V_11 * V_12 ;
struct V_11 * V_29 = NULL ;
T_1 V_30 ;
if ( ! V_31 )
return - V_32 ;
V_30 = F_6 ( V_14 , V_15 ) ;
V_28 = V_30 & ( V_18 - 1 ) ;
F_13 ( & V_17 [ V_28 ] . V_22 ) ;
F_18 (entry, &cipso_v4_cache[bkt].list, list) {
if ( V_12 -> V_30 == V_30 &&
V_12 -> V_15 == V_15 &&
memcmp ( V_12 -> V_14 , V_14 , V_15 ) == 0 ) {
V_12 -> V_33 += 1 ;
F_19 ( & V_12 -> V_13 -> V_34 ) ;
V_27 -> V_35 = V_12 -> V_13 ;
V_27 -> V_36 |= V_37 ;
V_27 -> type = V_38 ;
if ( V_29 == NULL ) {
F_16 ( & V_17 [ V_28 ] . V_22 ) ;
return 0 ;
}
if ( V_29 -> V_33 > 0 )
V_29 -> V_33 -= 1 ;
if ( V_12 -> V_33 > V_29 -> V_33 &&
V_12 -> V_33 - V_29 -> V_33 >
V_39 ) {
F_20 ( V_12 -> V_24 . V_40 , V_12 -> V_24 . V_41 ) ;
F_21 ( & V_12 -> V_24 ,
V_29 -> V_24 . V_40 ,
& V_29 -> V_24 ) ;
}
F_16 ( & V_17 [ V_28 ] . V_22 ) ;
return 0 ;
}
V_29 = V_12 ;
}
F_16 ( & V_17 [ V_28 ] . V_22 ) ;
return - V_32 ;
}
int F_22 ( const struct V_42 * V_43 ,
const struct V_26 * V_27 )
{
int V_44 = - V_45 ;
T_1 V_28 ;
struct V_11 * V_12 = NULL ;
struct V_11 * V_46 = NULL ;
unsigned char * V_47 ;
T_1 V_48 ;
if ( ! V_31 || V_49 <= 0 )
return 0 ;
V_47 = F_23 ( V_43 ) ;
V_48 = V_47 [ 1 ] ;
V_12 = F_24 ( sizeof( * V_12 ) , V_50 ) ;
if ( V_12 == NULL )
return - V_21 ;
V_12 -> V_14 = F_25 ( V_47 , V_48 , V_50 ) ;
if ( V_12 -> V_14 == NULL ) {
V_44 = - V_21 ;
goto V_51;
}
V_12 -> V_15 = V_48 ;
V_12 -> V_30 = F_6 ( V_47 , V_48 ) ;
F_19 ( & V_27 -> V_35 -> V_34 ) ;
V_12 -> V_13 = V_27 -> V_35 ;
V_28 = V_12 -> V_30 & ( V_18 - 1 ) ;
F_13 ( & V_17 [ V_28 ] . V_22 ) ;
if ( V_17 [ V_28 ] . V_23 < V_49 ) {
F_26 ( & V_12 -> V_24 , & V_17 [ V_28 ] . V_24 ) ;
V_17 [ V_28 ] . V_23 += 1 ;
} else {
V_46 = F_27 ( V_17 [ V_28 ] . V_24 . V_40 ,
struct V_11 , V_24 ) ;
F_15 ( & V_46 -> V_24 ) ;
F_26 ( & V_12 -> V_24 , & V_17 [ V_28 ] . V_24 ) ;
F_3 ( V_46 ) ;
}
F_16 ( & V_17 [ V_28 ] . V_22 ) ;
return 0 ;
V_51:
if ( V_12 )
F_3 ( V_12 ) ;
return V_44 ;
}
static struct V_52 * F_28 ( T_1 V_53 )
{
struct V_52 * V_16 ;
F_29 (iter, &cipso_v4_doi_list, list)
if ( V_16 -> V_53 == V_53 && F_30 ( & V_16 -> V_34 ) )
return V_16 ;
return NULL ;
}
int F_31 ( struct V_52 * V_54 ,
struct V_55 * V_56 )
{
int V_44 = - V_57 ;
T_1 V_16 ;
T_1 V_53 ;
T_1 V_58 ;
struct V_59 * V_60 ;
V_53 = V_54 -> V_53 ;
V_58 = V_54 -> type ;
if ( V_54 -> V_53 == V_61 )
goto V_62;
for ( V_16 = 0 ; V_16 < V_63 ; V_16 ++ ) {
switch ( V_54 -> V_64 [ V_16 ] ) {
case V_65 :
break;
case V_66 :
case V_67 :
if ( V_54 -> type != V_68 )
goto V_62;
break;
case V_69 :
if ( V_54 -> type != V_70 )
goto V_62;
break;
case V_71 :
if ( V_16 == 0 )
goto V_62;
break;
default:
goto V_62;
}
}
F_32 ( & V_54 -> V_34 , 1 ) ;
F_33 ( & V_72 ) ;
if ( F_28 ( V_54 -> V_53 ) != NULL ) {
F_34 ( & V_72 ) ;
V_44 = - V_73 ;
goto V_62;
}
F_35 ( & V_54 -> V_24 , & V_74 ) ;
F_34 ( & V_72 ) ;
V_44 = 0 ;
V_62:
V_60 = F_36 ( V_75 , V_56 ) ;
if ( V_60 != NULL ) {
const char * V_76 ;
switch ( V_58 ) {
case V_77 :
V_76 = L_1 ;
break;
case V_68 :
V_76 = L_2 ;
break;
case V_70 :
V_76 = L_3 ;
break;
default:
V_76 = L_4 ;
}
F_37 ( V_60 ,
L_5 ,
V_53 , V_76 , V_44 == 0 ? 1 : 0 ) ;
F_38 ( V_60 ) ;
}
return V_44 ;
}
void F_39 ( struct V_52 * V_54 )
{
if ( V_54 == NULL )
return;
switch ( V_54 -> type ) {
case V_77 :
F_5 ( V_54 -> V_78 . V_79 -> V_80 . V_81 ) ;
F_5 ( V_54 -> V_78 . V_79 -> V_80 . V_82 ) ;
F_5 ( V_54 -> V_78 . V_79 -> V_83 . V_81 ) ;
F_5 ( V_54 -> V_78 . V_79 -> V_83 . V_82 ) ;
break;
}
F_5 ( V_54 ) ;
}
static void F_40 ( struct V_84 * V_12 )
{
struct V_52 * V_54 ;
V_54 = F_41 ( V_12 , struct V_52 , V_85 ) ;
F_39 ( V_54 ) ;
}
int F_42 ( T_1 V_53 , struct V_55 * V_56 )
{
int V_44 ;
struct V_52 * V_54 ;
struct V_59 * V_60 ;
F_33 ( & V_72 ) ;
V_54 = F_28 ( V_53 ) ;
if ( V_54 == NULL ) {
F_34 ( & V_72 ) ;
V_44 = - V_32 ;
goto V_86;
}
if ( ! F_43 ( & V_54 -> V_34 ) ) {
F_34 ( & V_72 ) ;
V_44 = - V_87 ;
goto V_86;
}
F_44 ( & V_54 -> V_24 ) ;
F_34 ( & V_72 ) ;
F_12 () ;
F_45 ( & V_54 -> V_85 , F_40 ) ;
V_44 = 0 ;
V_86:
V_60 = F_36 ( V_88 , V_56 ) ;
if ( V_60 != NULL ) {
F_37 ( V_60 ,
L_6 ,
V_53 , V_44 == 0 ? 1 : 0 ) ;
F_38 ( V_60 ) ;
}
return V_44 ;
}
struct V_52 * F_46 ( T_1 V_53 )
{
struct V_52 * V_54 ;
F_47 () ;
V_54 = F_28 ( V_53 ) ;
if ( V_54 == NULL )
goto V_89;
if ( ! F_48 ( & V_54 -> V_34 ) )
V_54 = NULL ;
V_89:
F_49 () ;
return V_54 ;
}
void F_50 ( struct V_52 * V_54 )
{
if ( V_54 == NULL )
return;
if ( ! F_43 ( & V_54 -> V_34 ) )
return;
F_33 ( & V_72 ) ;
F_44 ( & V_54 -> V_24 ) ;
F_34 ( & V_72 ) ;
F_12 () ;
F_45 ( & V_54 -> V_85 , F_40 ) ;
}
int F_51 ( T_1 * V_90 ,
int (* F_52) ( struct V_52 * V_54 , void * V_91 ) ,
void * V_92 )
{
int V_44 = - V_32 ;
T_1 V_93 = 0 ;
struct V_52 * V_94 ;
F_47 () ;
F_29 (iter_doi, &cipso_v4_doi_list, list)
if ( F_30 ( & V_94 -> V_34 ) > 0 ) {
if ( V_93 ++ < * V_90 )
continue;
V_44 = F_52 ( V_94 , V_92 ) ;
if ( V_44 < 0 ) {
V_93 -- ;
goto V_95;
}
}
V_95:
F_49 () ;
* V_90 = V_93 ;
return V_44 ;
}
static int F_53 ( const struct V_52 * V_54 , T_2 V_96 )
{
switch ( V_54 -> type ) {
case V_68 :
return 0 ;
case V_77 :
if ( V_54 -> V_78 . V_79 -> V_80 . V_81 [ V_96 ] < V_97 )
return 0 ;
break;
}
return - V_98 ;
}
static int F_54 ( const struct V_52 * V_54 ,
T_1 V_99 ,
T_1 * V_100 )
{
switch ( V_54 -> type ) {
case V_68 :
* V_100 = V_99 ;
return 0 ;
case V_77 :
if ( V_99 < V_54 -> V_78 . V_79 -> V_80 . V_101 &&
V_54 -> V_78 . V_79 -> V_80 . V_82 [ V_99 ] < V_97 ) {
* V_100 = V_54 -> V_78 . V_79 -> V_80 . V_82 [ V_99 ] ;
return 0 ;
}
return - V_45 ;
}
return - V_57 ;
}
static int F_55 ( const struct V_52 * V_54 ,
T_1 V_100 ,
T_1 * V_99 )
{
struct V_102 * V_103 ;
switch ( V_54 -> type ) {
case V_68 :
* V_99 = V_100 ;
return 0 ;
case V_77 :
V_103 = V_54 -> V_78 . V_79 ;
if ( V_100 < V_103 -> V_80 . V_104 &&
V_103 -> V_80 . V_81 [ V_100 ] < V_97 ) {
* V_99 = V_54 -> V_78 . V_79 -> V_80 . V_81 [ V_100 ] ;
return 0 ;
}
return - V_45 ;
}
return - V_57 ;
}
static int F_56 ( const struct V_52 * V_54 ,
const unsigned char * V_1 ,
T_1 V_2 )
{
int V_83 = - 1 ;
T_1 V_105 = V_2 * 8 ;
T_1 V_106 ;
T_1 * V_107 ;
switch ( V_54 -> type ) {
case V_68 :
return 0 ;
case V_77 :
V_106 = V_54 -> V_78 . V_79 -> V_83 . V_104 ;
V_107 = V_54 -> V_78 . V_79 -> V_83 . V_81 ;
for (; ; ) {
V_83 = F_1 ( V_1 ,
V_105 ,
V_83 + 1 ,
1 ) ;
if ( V_83 < 0 )
break;
if ( V_83 >= V_106 ||
V_107 [ V_83 ] >= V_108 )
return - V_98 ;
}
if ( V_83 == - 1 )
return 0 ;
break;
}
return - V_98 ;
}
static int F_57 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_109 ,
T_1 V_110 )
{
int V_111 = - 1 ;
T_1 V_112 = V_108 ;
T_1 V_113 = 0 ;
T_1 V_114 = V_110 * 8 ;
T_1 V_115 = 0 ;
T_1 * V_116 = NULL ;
if ( V_54 -> type == V_77 ) {
V_115 = V_54 -> V_78 . V_79 -> V_83 . V_101 ;
V_116 = V_54 -> V_78 . V_79 -> V_83 . V_82 ;
}
for (; ; ) {
V_111 = F_58 ( V_27 -> V_117 . V_118 . V_83 ,
V_111 + 1 ) ;
if ( V_111 < 0 )
break;
switch ( V_54 -> type ) {
case V_68 :
V_112 = V_111 ;
break;
case V_77 :
if ( V_111 >= V_115 )
return - V_45 ;
V_112 = V_116 [ V_111 ] ;
if ( V_112 >= V_108 )
return - V_45 ;
break;
}
if ( V_112 >= V_114 )
return - V_119 ;
F_2 ( V_109 , V_112 , 1 ) ;
if ( V_112 > V_113 )
V_113 = V_112 ;
}
if ( ++ V_113 % 8 )
return V_113 / 8 + 1 ;
return V_113 / 8 ;
}
static int F_59 ( const struct V_52 * V_54 ,
const unsigned char * V_109 ,
T_1 V_110 ,
struct V_26 * V_27 )
{
int V_44 ;
int V_112 = - 1 ;
T_1 V_111 = V_108 ;
T_1 V_114 = V_110 * 8 ;
T_1 V_120 = 0 ;
T_1 * V_121 = NULL ;
if ( V_54 -> type == V_77 ) {
V_120 = V_54 -> V_78 . V_79 -> V_83 . V_104 ;
V_121 = V_54 -> V_78 . V_79 -> V_83 . V_81 ;
}
for (; ; ) {
V_112 = F_1 ( V_109 ,
V_114 ,
V_112 + 1 ,
1 ) ;
if ( V_112 < 0 ) {
if ( V_112 == - 2 )
return - V_98 ;
return 0 ;
}
switch ( V_54 -> type ) {
case V_68 :
V_111 = V_112 ;
break;
case V_77 :
if ( V_112 >= V_120 )
return - V_45 ;
V_111 = V_121 [ V_112 ] ;
if ( V_111 >= V_108 )
return - V_45 ;
break;
}
V_44 = F_60 ( & V_27 -> V_117 . V_118 . V_83 ,
V_111 ,
V_50 ) ;
if ( V_44 != 0 )
return V_44 ;
}
return - V_57 ;
}
static int F_61 ( const struct V_52 * V_54 ,
const unsigned char * V_122 ,
T_1 V_123 )
{
T_3 V_83 ;
int V_124 = - 1 ;
T_1 V_16 ;
if ( V_54 -> type != V_68 || V_123 & 0x01 )
return - V_98 ;
for ( V_16 = 0 ; V_16 < V_123 ; V_16 += 2 ) {
V_83 = F_62 ( & V_122 [ V_16 ] ) ;
if ( V_83 <= V_124 )
return - V_98 ;
V_124 = V_83 ;
}
return 0 ;
}
static int F_63 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_109 ,
T_1 V_110 )
{
int V_83 = - 1 ;
T_1 V_125 = 0 ;
for (; ; ) {
V_83 = F_58 ( V_27 -> V_117 . V_118 . V_83 , V_83 + 1 ) ;
if ( V_83 < 0 )
break;
if ( ( V_125 + 2 ) > V_110 )
return - V_119 ;
* ( ( V_126 * ) & V_109 [ V_125 ] ) = F_64 ( V_83 ) ;
V_125 += 2 ;
}
return V_125 ;
}
static int F_65 ( const struct V_52 * V_54 ,
const unsigned char * V_109 ,
T_1 V_110 ,
struct V_26 * V_27 )
{
int V_44 ;
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_110 ; V_16 += 2 ) {
V_44 = F_60 ( & V_27 -> V_117 . V_118 . V_83 ,
F_62 ( & V_109 [ V_16 ] ) ,
V_50 ) ;
if ( V_44 != 0 )
return V_44 ;
}
return 0 ;
}
static int F_66 ( const struct V_52 * V_54 ,
const unsigned char * V_127 ,
T_1 V_128 )
{
T_3 V_129 ;
T_3 V_130 ;
T_1 V_124 = V_131 + 1 ;
T_1 V_16 ;
if ( V_54 -> type != V_68 || V_128 & 0x01 )
return - V_98 ;
for ( V_16 = 0 ; V_16 < V_128 ; V_16 += 4 ) {
V_129 = F_62 ( & V_127 [ V_16 ] ) ;
if ( ( V_16 + 4 ) <= V_128 )
V_130 = F_62 ( & V_127 [ V_16 + 2 ] ) ;
else
V_130 = 0 ;
if ( V_129 > V_124 )
return - V_98 ;
V_124 = V_130 ;
}
return 0 ;
}
static int F_67 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_109 ,
T_1 V_110 )
{
int V_16 = - 1 ;
T_3 V_132 [ V_133 * 2 ] ;
T_1 V_134 = 0 ;
T_1 V_135 = 0 ;
if ( V_110 >
( V_136 - V_137 - V_138 ) )
return - V_119 ;
for (; ; ) {
V_16 = F_58 ( V_27 -> V_117 . V_118 . V_83 , V_16 + 1 ) ;
if ( V_16 < 0 )
break;
V_135 += ( V_16 == 0 ? 0 : sizeof( T_3 ) ) ;
if ( V_135 > V_110 )
return - V_119 ;
V_132 [ V_134 ++ ] = V_16 ;
V_16 = F_68 ( V_27 -> V_117 . V_118 . V_83 , V_16 ) ;
if ( V_16 < 0 )
return - V_98 ;
V_135 += sizeof( T_3 ) ;
if ( V_135 > V_110 )
return - V_119 ;
V_132 [ V_134 ++ ] = V_16 ;
}
for ( V_16 = 0 ; V_134 > 0 ; ) {
* ( ( V_126 * ) & V_109 [ V_16 ] ) = F_64 ( V_132 [ -- V_134 ] ) ;
V_16 += 2 ;
V_134 -- ;
if ( V_132 [ V_134 ] != 0 ) {
* ( ( V_126 * ) & V_109 [ V_16 ] ) = F_64 ( V_132 [ V_134 ] ) ;
V_16 += 2 ;
}
}
return V_135 ;
}
static int F_69 ( const struct V_52 * V_54 ,
const unsigned char * V_109 ,
T_1 V_110 ,
struct V_26 * V_27 )
{
int V_44 ;
T_1 V_139 ;
T_3 V_130 ;
T_3 V_129 ;
for ( V_139 = 0 ; V_139 < V_110 ; V_139 += 4 ) {
V_129 = F_62 ( & V_109 [ V_139 ] ) ;
if ( ( V_139 + 4 ) <= V_110 )
V_130 = F_62 ( & V_109 [ V_139 + 2 ] ) ;
else
V_130 = 0 ;
V_44 = F_70 ( & V_27 -> V_117 . V_118 . V_83 ,
V_130 ,
V_129 ,
V_50 ) ;
if ( V_44 != 0 )
return V_44 ;
}
return 0 ;
}
static void F_71 ( const struct V_52 * V_54 ,
unsigned char * V_140 ,
T_1 V_141 )
{
V_140 [ 0 ] = V_142 ;
V_140 [ 1 ] = V_137 + V_141 ;
* ( V_143 * ) & V_140 [ 2 ] = F_72 ( V_54 -> V_53 ) ;
}
static int F_73 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_144 ,
T_1 V_145 )
{
int V_44 ;
T_1 V_146 ;
T_1 V_96 ;
if ( ( V_27 -> V_36 & V_147 ) == 0 )
return - V_45 ;
V_44 = F_54 ( V_54 ,
V_27 -> V_117 . V_118 . V_80 ,
& V_96 ) ;
if ( V_44 != 0 )
return V_44 ;
if ( V_27 -> V_36 & V_148 ) {
V_44 = F_57 ( V_54 ,
V_27 ,
& V_144 [ 4 ] ,
V_145 - 4 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_149 && V_44 > 0 && V_44 <= 10 )
V_146 = 14 ;
else
V_146 = 4 + V_44 ;
} else
V_146 = 4 ;
V_144 [ 0 ] = V_65 ;
V_144 [ 1 ] = V_146 ;
V_144 [ 3 ] = V_96 ;
return V_146 ;
}
static int F_74 ( const struct V_52 * V_54 ,
const unsigned char * V_150 ,
struct V_26 * V_27 )
{
int V_44 ;
T_2 V_146 = V_150 [ 1 ] ;
T_1 V_96 ;
V_44 = F_55 ( V_54 , V_150 [ 3 ] , & V_96 ) ;
if ( V_44 != 0 )
return V_44 ;
V_27 -> V_117 . V_118 . V_80 = V_96 ;
V_27 -> V_36 |= V_147 ;
if ( V_146 > 4 ) {
V_44 = F_59 ( V_54 ,
& V_150 [ 4 ] ,
V_146 - 4 ,
V_27 ) ;
if ( V_44 != 0 ) {
F_75 ( V_27 -> V_117 . V_118 . V_83 ) ;
return V_44 ;
}
V_27 -> V_36 |= V_148 ;
}
return 0 ;
}
static int F_76 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_144 ,
T_1 V_145 )
{
int V_44 ;
T_1 V_146 ;
T_1 V_96 ;
if ( ! ( V_27 -> V_36 & V_147 ) )
return - V_45 ;
V_44 = F_54 ( V_54 ,
V_27 -> V_117 . V_118 . V_80 ,
& V_96 ) ;
if ( V_44 != 0 )
return V_44 ;
if ( V_27 -> V_36 & V_148 ) {
V_44 = F_63 ( V_54 ,
V_27 ,
& V_144 [ 4 ] ,
V_145 - 4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_146 = 4 + V_44 ;
} else
V_146 = 4 ;
V_144 [ 0 ] = V_67 ;
V_144 [ 1 ] = V_146 ;
V_144 [ 3 ] = V_96 ;
return V_146 ;
}
static int F_77 ( const struct V_52 * V_54 ,
const unsigned char * V_150 ,
struct V_26 * V_27 )
{
int V_44 ;
T_2 V_146 = V_150 [ 1 ] ;
T_1 V_96 ;
V_44 = F_55 ( V_54 , V_150 [ 3 ] , & V_96 ) ;
if ( V_44 != 0 )
return V_44 ;
V_27 -> V_117 . V_118 . V_80 = V_96 ;
V_27 -> V_36 |= V_147 ;
if ( V_146 > 4 ) {
V_44 = F_65 ( V_54 ,
& V_150 [ 4 ] ,
V_146 - 4 ,
V_27 ) ;
if ( V_44 != 0 ) {
F_75 ( V_27 -> V_117 . V_118 . V_83 ) ;
return V_44 ;
}
V_27 -> V_36 |= V_148 ;
}
return 0 ;
}
static int F_78 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_144 ,
T_1 V_145 )
{
int V_44 ;
T_1 V_146 ;
T_1 V_96 ;
if ( ! ( V_27 -> V_36 & V_147 ) )
return - V_45 ;
V_44 = F_54 ( V_54 ,
V_27 -> V_117 . V_118 . V_80 ,
& V_96 ) ;
if ( V_44 != 0 )
return V_44 ;
if ( V_27 -> V_36 & V_148 ) {
V_44 = F_67 ( V_54 ,
V_27 ,
& V_144 [ 4 ] ,
V_145 - 4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_146 = 4 + V_44 ;
} else
V_146 = 4 ;
V_144 [ 0 ] = V_66 ;
V_144 [ 1 ] = V_146 ;
V_144 [ 3 ] = V_96 ;
return V_146 ;
}
static int F_79 ( const struct V_52 * V_54 ,
const unsigned char * V_150 ,
struct V_26 * V_27 )
{
int V_44 ;
T_2 V_146 = V_150 [ 1 ] ;
T_1 V_96 ;
V_44 = F_55 ( V_54 , V_150 [ 3 ] , & V_96 ) ;
if ( V_44 != 0 )
return V_44 ;
V_27 -> V_117 . V_118 . V_80 = V_96 ;
V_27 -> V_36 |= V_147 ;
if ( V_146 > 4 ) {
V_44 = F_69 ( V_54 ,
& V_150 [ 4 ] ,
V_146 - 4 ,
V_27 ) ;
if ( V_44 != 0 ) {
F_75 ( V_27 -> V_117 . V_118 . V_83 ) ;
return V_44 ;
}
V_27 -> V_36 |= V_148 ;
}
return 0 ;
}
static int F_80 ( const struct V_52 * V_54 ,
const struct V_26 * V_27 ,
unsigned char * V_144 ,
T_1 V_145 )
{
if ( ! ( V_27 -> V_36 & V_151 ) )
return - V_45 ;
V_144 [ 0 ] = V_69 ;
V_144 [ 1 ] = V_152 ;
* ( T_1 * ) & V_144 [ 2 ] = V_27 -> V_117 . V_153 ;
return V_152 ;
}
static int F_81 ( const struct V_52 * V_54 ,
const unsigned char * V_150 ,
struct V_26 * V_27 )
{
V_27 -> V_117 . V_153 = * ( T_1 * ) & V_150 [ 2 ] ;
V_27 -> V_36 |= V_151 ;
return 0 ;
}
int F_82 ( const struct V_42 * V_43 , unsigned char * * V_154 )
{
unsigned char * V_155 = * V_154 ;
unsigned char * V_150 ;
unsigned char V_156 ;
unsigned char V_157 = 0 ;
T_2 V_158 ;
T_2 V_146 ;
struct V_52 * V_54 = NULL ;
T_1 V_159 ;
V_158 = V_155 [ 1 ] ;
if ( V_158 < 8 ) {
V_157 = 1 ;
goto V_160;
}
F_47 () ;
V_54 = F_28 ( F_83 ( & V_155 [ 2 ] ) ) ;
if ( V_54 == NULL ) {
V_157 = 2 ;
goto V_161;
}
V_156 = V_137 ;
V_150 = V_155 + V_156 ;
while ( V_156 < V_158 ) {
for ( V_159 = 0 ; V_54 -> V_64 [ V_159 ] != V_150 [ 0 ] ; )
if ( V_54 -> V_64 [ V_159 ] == V_71 ||
++ V_159 == V_63 ) {
V_157 = V_156 ;
goto V_161;
}
V_146 = V_150 [ 1 ] ;
if ( V_146 > ( V_158 - V_156 ) ) {
V_157 = V_156 + 1 ;
goto V_161;
}
switch ( V_150 [ 0 ] ) {
case V_65 :
if ( V_146 < V_162 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
if ( V_163 ) {
if ( F_53 ( V_54 ,
V_150 [ 3 ] ) < 0 ) {
V_157 = V_156 + 3 ;
goto V_161;
}
if ( V_146 > V_162 &&
F_56 ( V_54 ,
& V_150 [ 4 ] ,
V_146 - 4 ) < 0 ) {
V_157 = V_156 + 4 ;
goto V_161;
}
}
break;
case V_67 :
if ( V_146 < V_164 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
if ( F_53 ( V_54 ,
V_150 [ 3 ] ) < 0 ) {
V_157 = V_156 + 3 ;
goto V_161;
}
if ( V_146 > V_164 &&
F_61 ( V_54 ,
& V_150 [ 4 ] ,
V_146 - 4 ) < 0 ) {
V_157 = V_156 + 4 ;
goto V_161;
}
break;
case V_66 :
if ( V_146 < V_138 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
if ( F_53 ( V_54 ,
V_150 [ 3 ] ) < 0 ) {
V_157 = V_156 + 3 ;
goto V_161;
}
if ( V_146 > V_138 &&
F_66 ( V_54 ,
& V_150 [ 4 ] ,
V_146 - 4 ) < 0 ) {
V_157 = V_156 + 4 ;
goto V_161;
}
break;
case V_69 :
if ( V_43 == NULL || ! ( V_43 -> V_165 -> V_36 & V_166 ) ) {
V_157 = V_156 ;
goto V_161;
}
if ( V_146 != V_152 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
break;
default:
V_157 = V_156 ;
goto V_161;
}
V_150 += V_146 ;
V_156 += V_146 ;
}
V_161:
F_49 () ;
V_160:
* V_154 = V_155 + V_157 ;
return V_157 ;
}
void F_84 ( struct V_42 * V_43 , int error , T_1 V_167 )
{
if ( F_85 ( V_43 ) -> V_168 == V_169 || error != - V_170 )
return;
if ( V_167 )
F_86 ( V_43 , V_171 , V_172 , 0 ) ;
else
F_86 ( V_43 , V_171 , V_173 , 0 ) ;
}
static int F_87 ( unsigned char * V_140 , T_1 V_174 ,
const struct V_52 * V_54 ,
const struct V_26 * V_27 )
{
int V_44 ;
T_1 V_16 ;
if ( V_174 <= V_137 )
return - V_119 ;
V_16 = 0 ;
do {
memset ( V_140 , 0 , V_174 ) ;
switch ( V_54 -> V_64 [ V_16 ] ) {
case V_65 :
V_44 = F_73 ( V_54 ,
V_27 ,
& V_140 [ V_137 ] ,
V_174 - V_137 ) ;
break;
case V_67 :
V_44 = F_76 ( V_54 ,
V_27 ,
& V_140 [ V_137 ] ,
V_174 - V_137 ) ;
break;
case V_66 :
V_44 = F_78 ( V_54 ,
V_27 ,
& V_140 [ V_137 ] ,
V_174 - V_137 ) ;
break;
case V_69 :
V_44 = F_80 ( V_54 ,
V_27 ,
& V_140 [ V_137 ] ,
V_174 - V_137 ) ;
break;
default:
return - V_45 ;
}
V_16 ++ ;
} while ( V_44 < 0 &&
V_16 < V_63 &&
V_54 -> V_64 [ V_16 ] != V_71 );
if ( V_44 < 0 )
return V_44 ;
F_71 ( V_54 , V_140 , V_44 ) ;
return V_137 + V_44 ;
}
int F_88 ( struct V_175 * V_176 ,
const struct V_52 * V_54 ,
const struct V_26 * V_27 )
{
int V_44 = - V_45 ;
unsigned char * V_140 = NULL ;
T_1 V_174 ;
T_1 V_158 ;
struct V_177 * V_178 , * V_155 = NULL ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
if ( V_176 == NULL )
return 0 ;
V_174 = V_136 ;
V_140 = F_89 ( V_174 , V_50 ) ;
if ( V_140 == NULL ) {
V_44 = - V_21 ;
goto V_183;
}
V_44 = F_87 ( V_140 , V_174 , V_54 , V_27 ) ;
if ( V_44 < 0 )
goto V_183;
V_174 = V_44 ;
V_158 = ( V_174 + 3 ) & ~ 3 ;
V_155 = F_24 ( sizeof( * V_155 ) + V_158 , V_50 ) ;
if ( V_155 == NULL ) {
V_44 = - V_21 ;
goto V_183;
}
memcpy ( V_155 -> V_155 . V_184 , V_140 , V_174 ) ;
V_155 -> V_155 . V_185 = V_158 ;
V_155 -> V_155 . V_81 = sizeof( struct V_186 ) ;
F_5 ( V_140 ) ;
V_140 = NULL ;
V_180 = F_90 ( V_176 ) ;
V_178 = F_91 ( V_180 -> V_187 , F_92 ( V_176 ) ) ;
if ( V_180 -> V_188 ) {
V_182 = F_93 ( V_176 ) ;
if ( V_178 )
V_182 -> V_189 -= V_178 -> V_155 . V_185 ;
V_182 -> V_189 += V_155 -> V_155 . V_185 ;
V_182 -> V_190 ( V_176 , V_182 -> V_191 ) ;
}
F_94 ( V_180 -> V_187 , V_155 ) ;
if ( V_178 )
F_95 ( V_178 , V_85 ) ;
return 0 ;
V_183:
F_5 ( V_140 ) ;
F_5 ( V_155 ) ;
return V_44 ;
}
int F_96 ( struct V_192 * V_193 ,
const struct V_52 * V_54 ,
const struct V_26 * V_27 )
{
int V_44 = - V_45 ;
unsigned char * V_140 = NULL ;
T_1 V_174 ;
T_1 V_158 ;
struct V_177 * V_155 = NULL ;
struct V_194 * V_195 ;
V_174 = V_136 ;
V_140 = F_89 ( V_174 , V_50 ) ;
if ( V_140 == NULL ) {
V_44 = - V_21 ;
goto V_196;
}
V_44 = F_87 ( V_140 , V_174 , V_54 , V_27 ) ;
if ( V_44 < 0 )
goto V_196;
V_174 = V_44 ;
V_158 = ( V_174 + 3 ) & ~ 3 ;
V_155 = F_24 ( sizeof( * V_155 ) + V_158 , V_50 ) ;
if ( V_155 == NULL ) {
V_44 = - V_21 ;
goto V_196;
}
memcpy ( V_155 -> V_155 . V_184 , V_140 , V_174 ) ;
V_155 -> V_155 . V_185 = V_158 ;
V_155 -> V_155 . V_81 = sizeof( struct V_186 ) ;
F_5 ( V_140 ) ;
V_140 = NULL ;
V_195 = F_97 ( V_193 ) ;
V_155 = F_98 ( & V_195 -> V_155 , V_155 ) ;
if ( V_155 )
F_95 ( V_155 , V_85 ) ;
return 0 ;
V_196:
F_5 ( V_140 ) ;
F_5 ( V_155 ) ;
return V_44 ;
}
static int F_99 ( struct V_177 * * V_197 )
{
int V_198 = 0 ;
struct V_177 * V_155 = * V_197 ;
if ( V_155 -> V_155 . V_199 || V_155 -> V_155 . V_200 || V_155 -> V_155 . V_201 || V_155 -> V_155 . V_202 ) {
T_2 V_203 ;
T_2 V_204 ;
unsigned char * V_47 ;
int V_16 ;
int V_205 ;
V_204 = V_155 -> V_155 . V_81 - sizeof( struct V_186 ) ;
V_47 = & V_155 -> V_155 . V_184 [ V_204 ] ;
V_203 = V_47 [ 1 ] ;
if ( V_155 -> V_155 . V_199 > V_155 -> V_155 . V_81 )
V_155 -> V_155 . V_199 -= V_203 ;
if ( V_155 -> V_155 . V_200 > V_155 -> V_155 . V_81 )
V_155 -> V_155 . V_200 -= V_203 ;
if ( V_155 -> V_155 . V_201 > V_155 -> V_155 . V_81 )
V_155 -> V_155 . V_201 -= V_203 ;
if ( V_155 -> V_155 . V_202 > V_155 -> V_155 . V_81 )
V_155 -> V_155 . V_202 -= V_203 ;
V_155 -> V_155 . V_81 = 0 ;
memmove ( V_47 , V_47 + V_203 ,
V_155 -> V_155 . V_185 - V_204 - V_203 ) ;
V_16 = 0 ;
V_205 = 0 ;
while ( V_16 < V_155 -> V_155 . V_185 )
if ( V_155 -> V_155 . V_184 [ V_16 ] != V_206 ) {
V_16 += V_155 -> V_155 . V_184 [ V_16 + 1 ] ;
V_205 = V_16 ;
} else
V_16 ++ ;
V_198 = V_155 -> V_155 . V_185 ;
V_155 -> V_155 . V_185 = ( V_205 + 3 ) & ~ 3 ;
V_198 -= V_155 -> V_155 . V_185 ;
} else {
* V_197 = NULL ;
V_198 = V_155 -> V_155 . V_185 ;
F_95 ( V_155 , V_85 ) ;
}
return V_198 ;
}
void F_100 ( struct V_175 * V_176 )
{
int V_198 ;
struct V_177 * V_155 ;
struct V_179 * V_180 ;
V_180 = F_90 ( V_176 ) ;
V_155 = F_91 ( V_180 -> V_187 , 1 ) ;
if ( V_155 == NULL || V_155 -> V_155 . V_81 == 0 )
return;
V_198 = F_99 ( & V_180 -> V_187 ) ;
if ( V_180 -> V_188 && V_198 > 0 ) {
struct V_181 * V_182 = F_93 ( V_176 ) ;
V_182 -> V_189 -= V_198 ;
V_182 -> V_190 ( V_176 , V_182 -> V_191 ) ;
}
}
void F_101 ( struct V_192 * V_193 )
{
struct V_177 * V_155 ;
struct V_194 * V_195 ;
V_195 = F_97 ( V_193 ) ;
V_155 = V_195 -> V_155 ;
if ( V_155 == NULL || V_155 -> V_155 . V_81 == 0 )
return;
F_99 ( & V_195 -> V_155 ) ;
}
static int F_102 ( const unsigned char * V_81 ,
struct V_26 * V_27 )
{
int V_44 = - V_207 ;
T_1 V_53 ;
struct V_52 * V_54 ;
if ( F_17 ( V_81 , V_81 [ 1 ] , V_27 ) == 0 )
return 0 ;
V_53 = F_83 ( & V_81 [ 2 ] ) ;
F_47 () ;
V_54 = F_28 ( V_53 ) ;
if ( V_54 == NULL )
goto V_208;
switch ( V_81 [ 6 ] ) {
case V_65 :
V_44 = F_74 ( V_54 , & V_81 [ 6 ] , V_27 ) ;
break;
case V_67 :
V_44 = F_77 ( V_54 , & V_81 [ 6 ] , V_27 ) ;
break;
case V_66 :
V_44 = F_79 ( V_54 , & V_81 [ 6 ] , V_27 ) ;
break;
case V_69 :
V_44 = F_81 ( V_54 , & V_81 [ 6 ] , V_27 ) ;
break;
}
if ( V_44 == 0 )
V_27 -> type = V_38 ;
V_208:
F_49 () ;
return V_44 ;
}
int F_103 ( struct V_175 * V_176 , struct V_26 * V_27 )
{
struct V_177 * V_155 ;
int V_209 = - V_207 ;
F_47 () ;
V_155 = F_104 ( F_90 ( V_176 ) -> V_187 ) ;
if ( V_155 && V_155 -> V_155 . V_81 )
V_209 = F_102 ( V_155 -> V_155 . V_184 +
V_155 -> V_155 . V_81 -
sizeof( struct V_186 ) ,
V_27 ) ;
F_49 () ;
return V_209 ;
}
int F_105 ( struct V_42 * V_43 ,
const struct V_52 * V_54 ,
const struct V_26 * V_27 )
{
int V_44 ;
struct V_186 * V_210 ;
struct V_211 * V_155 = & F_106 ( V_43 ) -> V_155 ;
unsigned char V_140 [ V_136 ] ;
T_1 V_174 = V_136 ;
T_1 V_158 ;
int V_212 ;
V_44 = F_87 ( V_140 , V_174 , V_54 , V_27 ) ;
if ( V_44 < 0 )
return V_44 ;
V_174 = V_44 ;
V_158 = ( V_174 + 3 ) & ~ 3 ;
V_212 = V_158 - V_155 -> V_185 ;
V_44 = F_107 ( V_43 , F_108 ( V_43 ) + V_212 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_212 > 0 ) {
V_210 = F_85 ( V_43 ) ;
F_109 ( V_43 , V_212 ) ;
memmove ( ( char * ) V_210 - V_212 , V_210 , V_210 -> V_213 << 2 ) ;
F_110 ( V_43 ) ;
V_210 = F_85 ( V_43 ) ;
} else if ( V_212 < 0 ) {
V_210 = F_85 ( V_43 ) ;
memset ( V_210 + 1 , V_206 , V_155 -> V_185 ) ;
} else
V_210 = F_85 ( V_43 ) ;
if ( V_155 -> V_185 > 0 )
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_185 = V_158 ;
V_155 -> V_81 = sizeof( struct V_186 ) ;
V_155 -> V_214 = 1 ;
memcpy ( V_210 + 1 , V_140 , V_174 ) ;
if ( V_158 > V_174 )
memset ( ( char * ) ( V_210 + 1 ) + V_174 , 0 , V_158 - V_174 ) ;
if ( V_212 != 0 ) {
V_210 -> V_213 = 5 + ( V_158 >> 2 ) ;
V_210 -> V_215 = F_64 ( V_43 -> V_141 ) ;
}
F_111 ( V_210 ) ;
return 0 ;
}
int F_112 ( struct V_42 * V_43 )
{
int V_44 ;
struct V_186 * V_210 ;
struct V_211 * V_155 = & F_106 ( V_43 ) -> V_155 ;
unsigned char * V_47 ;
if ( V_155 -> V_81 == 0 )
return 0 ;
V_44 = F_107 ( V_43 , F_108 ( V_43 ) ) ;
if ( V_44 < 0 )
return V_44 ;
V_210 = F_85 ( V_43 ) ;
V_47 = ( unsigned char * ) V_210 + V_155 -> V_81 ;
memset ( V_47 , V_216 , V_47 [ 1 ] ) ;
V_155 -> V_81 = 0 ;
V_155 -> V_214 = 1 ;
F_111 ( V_210 ) ;
return 0 ;
}
int F_113 ( const struct V_42 * V_43 ,
struct V_26 * V_27 )
{
return F_102 ( F_23 ( V_43 ) , V_27 ) ;
}
static int T_4 F_114 ( void )
{
int V_44 ;
V_44 = F_8 () ;
if ( V_44 != 0 )
F_115 ( L_7 ,
V_44 ) ;
return 0 ;
}
