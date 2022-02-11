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
static int T_3 F_8 ( void )
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
int F_22 ( const unsigned char * V_42 ,
const struct V_26 * V_27 )
{
int V_43 = - V_44 ;
T_1 V_28 ;
struct V_11 * V_12 = NULL ;
struct V_11 * V_45 = NULL ;
T_1 V_46 ;
if ( ! V_31 || V_47 <= 0 )
return 0 ;
V_46 = V_42 [ 1 ] ;
V_12 = F_23 ( sizeof( * V_12 ) , V_48 ) ;
if ( V_12 == NULL )
return - V_21 ;
V_12 -> V_14 = F_24 ( V_42 , V_46 , V_48 ) ;
if ( V_12 -> V_14 == NULL ) {
V_43 = - V_21 ;
goto V_49;
}
V_12 -> V_15 = V_46 ;
V_12 -> V_30 = F_6 ( V_42 , V_46 ) ;
F_19 ( & V_27 -> V_35 -> V_34 ) ;
V_12 -> V_13 = V_27 -> V_35 ;
V_28 = V_12 -> V_30 & ( V_18 - 1 ) ;
F_13 ( & V_17 [ V_28 ] . V_22 ) ;
if ( V_17 [ V_28 ] . V_23 < V_47 ) {
F_25 ( & V_12 -> V_24 , & V_17 [ V_28 ] . V_24 ) ;
V_17 [ V_28 ] . V_23 += 1 ;
} else {
V_45 = F_26 ( V_17 [ V_28 ] . V_24 . V_40 ,
struct V_11 , V_24 ) ;
F_15 ( & V_45 -> V_24 ) ;
F_25 ( & V_12 -> V_24 , & V_17 [ V_28 ] . V_24 ) ;
F_3 ( V_45 ) ;
}
F_16 ( & V_17 [ V_28 ] . V_22 ) ;
return 0 ;
V_49:
if ( V_12 )
F_3 ( V_12 ) ;
return V_43 ;
}
static struct V_50 * F_27 ( T_1 V_51 )
{
struct V_50 * V_16 ;
F_28 (iter, &cipso_v4_doi_list, list)
if ( V_16 -> V_51 == V_51 && F_29 ( & V_16 -> V_34 ) )
return V_16 ;
return NULL ;
}
int F_30 ( struct V_50 * V_52 ,
struct V_53 * V_54 )
{
int V_43 = - V_55 ;
T_1 V_16 ;
T_1 V_51 ;
T_1 V_56 ;
struct V_57 * V_58 ;
V_51 = V_52 -> V_51 ;
V_56 = V_52 -> type ;
if ( V_52 -> V_51 == V_59 )
goto V_60;
for ( V_16 = 0 ; V_16 < V_61 ; V_16 ++ ) {
switch ( V_52 -> V_62 [ V_16 ] ) {
case V_63 :
break;
case V_64 :
case V_65 :
if ( V_52 -> type != V_66 )
goto V_60;
break;
case V_67 :
if ( V_52 -> type != V_68 )
goto V_60;
break;
case V_69 :
if ( V_16 == 0 )
goto V_60;
break;
default:
goto V_60;
}
}
F_31 ( & V_52 -> V_34 , 1 ) ;
F_32 ( & V_70 ) ;
if ( F_27 ( V_52 -> V_51 ) != NULL ) {
F_33 ( & V_70 ) ;
V_43 = - V_71 ;
goto V_60;
}
F_34 ( & V_52 -> V_24 , & V_72 ) ;
F_33 ( & V_70 ) ;
V_43 = 0 ;
V_60:
V_58 = F_35 ( V_73 , V_54 ) ;
if ( V_58 != NULL ) {
const char * V_74 ;
switch ( V_56 ) {
case V_75 :
V_74 = L_1 ;
break;
case V_66 :
V_74 = L_2 ;
break;
case V_68 :
V_74 = L_3 ;
break;
default:
V_74 = L_4 ;
}
F_36 ( V_58 ,
L_5 ,
V_51 , V_74 , V_43 == 0 ? 1 : 0 ) ;
F_37 ( V_58 ) ;
}
return V_43 ;
}
void F_38 ( struct V_50 * V_52 )
{
if ( V_52 == NULL )
return;
switch ( V_52 -> type ) {
case V_75 :
F_5 ( V_52 -> V_76 . V_77 -> V_78 . V_79 ) ;
F_5 ( V_52 -> V_76 . V_77 -> V_78 . V_80 ) ;
F_5 ( V_52 -> V_76 . V_77 -> V_81 . V_79 ) ;
F_5 ( V_52 -> V_76 . V_77 -> V_81 . V_80 ) ;
break;
}
F_5 ( V_52 ) ;
}
static void F_39 ( struct V_82 * V_12 )
{
struct V_50 * V_52 ;
V_52 = F_40 ( V_12 , struct V_50 , V_83 ) ;
F_38 ( V_52 ) ;
}
int F_41 ( T_1 V_51 , struct V_53 * V_54 )
{
int V_43 ;
struct V_50 * V_52 ;
struct V_57 * V_58 ;
F_32 ( & V_70 ) ;
V_52 = F_27 ( V_51 ) ;
if ( V_52 == NULL ) {
F_33 ( & V_70 ) ;
V_43 = - V_32 ;
goto V_84;
}
if ( ! F_42 ( & V_52 -> V_34 ) ) {
F_33 ( & V_70 ) ;
V_43 = - V_85 ;
goto V_84;
}
F_43 ( & V_52 -> V_24 ) ;
F_33 ( & V_70 ) ;
F_12 () ;
F_44 ( & V_52 -> V_83 , F_39 ) ;
V_43 = 0 ;
V_84:
V_58 = F_35 ( V_86 , V_54 ) ;
if ( V_58 != NULL ) {
F_36 ( V_58 ,
L_6 ,
V_51 , V_43 == 0 ? 1 : 0 ) ;
F_37 ( V_58 ) ;
}
return V_43 ;
}
struct V_50 * F_45 ( T_1 V_51 )
{
struct V_50 * V_52 ;
F_46 () ;
V_52 = F_27 ( V_51 ) ;
if ( V_52 == NULL )
goto V_87;
if ( ! F_47 ( & V_52 -> V_34 ) )
V_52 = NULL ;
V_87:
F_48 () ;
return V_52 ;
}
void F_49 ( struct V_50 * V_52 )
{
if ( V_52 == NULL )
return;
if ( ! F_42 ( & V_52 -> V_34 ) )
return;
F_32 ( & V_70 ) ;
F_43 ( & V_52 -> V_24 ) ;
F_33 ( & V_70 ) ;
F_12 () ;
F_44 ( & V_52 -> V_83 , F_39 ) ;
}
int F_50 ( T_1 * V_88 ,
int (* F_51) ( struct V_50 * V_52 , void * V_89 ) ,
void * V_90 )
{
int V_43 = - V_32 ;
T_1 V_91 = 0 ;
struct V_50 * V_92 ;
F_46 () ;
F_28 (iter_doi, &cipso_v4_doi_list, list)
if ( F_29 ( & V_92 -> V_34 ) > 0 ) {
if ( V_91 ++ < * V_88 )
continue;
V_43 = F_51 ( V_92 , V_90 ) ;
if ( V_43 < 0 ) {
V_91 -- ;
goto V_93;
}
}
V_93:
F_48 () ;
* V_88 = V_91 ;
return V_43 ;
}
static int F_52 ( const struct V_50 * V_52 , T_2 V_94 )
{
switch ( V_52 -> type ) {
case V_66 :
return 0 ;
case V_75 :
if ( V_52 -> V_76 . V_77 -> V_78 . V_79 [ V_94 ] < V_95 )
return 0 ;
break;
}
return - V_96 ;
}
static int F_53 ( const struct V_50 * V_52 ,
T_1 V_97 ,
T_1 * V_98 )
{
switch ( V_52 -> type ) {
case V_66 :
* V_98 = V_97 ;
return 0 ;
case V_75 :
if ( V_97 < V_52 -> V_76 . V_77 -> V_78 . V_99 &&
V_52 -> V_76 . V_77 -> V_78 . V_80 [ V_97 ] < V_95 ) {
* V_98 = V_52 -> V_76 . V_77 -> V_78 . V_80 [ V_97 ] ;
return 0 ;
}
return - V_44 ;
}
return - V_55 ;
}
static int F_54 ( const struct V_50 * V_52 ,
T_1 V_98 ,
T_1 * V_97 )
{
struct V_100 * V_101 ;
switch ( V_52 -> type ) {
case V_66 :
* V_97 = V_98 ;
return 0 ;
case V_75 :
V_101 = V_52 -> V_76 . V_77 ;
if ( V_98 < V_101 -> V_78 . V_102 &&
V_101 -> V_78 . V_79 [ V_98 ] < V_95 ) {
* V_97 = V_52 -> V_76 . V_77 -> V_78 . V_79 [ V_98 ] ;
return 0 ;
}
return - V_44 ;
}
return - V_55 ;
}
static int F_55 ( const struct V_50 * V_52 ,
const unsigned char * V_1 ,
T_1 V_2 )
{
int V_81 = - 1 ;
T_1 V_103 = V_2 * 8 ;
T_1 V_104 ;
T_1 * V_105 ;
switch ( V_52 -> type ) {
case V_66 :
return 0 ;
case V_75 :
V_104 = V_52 -> V_76 . V_77 -> V_81 . V_102 ;
V_105 = V_52 -> V_76 . V_77 -> V_81 . V_79 ;
for (; ; ) {
V_81 = F_1 ( V_1 ,
V_103 ,
V_81 + 1 ,
1 ) ;
if ( V_81 < 0 )
break;
if ( V_81 >= V_104 ||
V_105 [ V_81 ] >= V_106 )
return - V_96 ;
}
if ( V_81 == - 1 )
return 0 ;
break;
}
return - V_96 ;
}
static int F_56 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_107 ,
T_1 V_108 )
{
int V_109 = - 1 ;
T_1 V_110 = V_106 ;
T_1 V_111 = 0 ;
T_1 V_112 = V_108 * 8 ;
T_1 V_113 = 0 ;
T_1 * V_114 = NULL ;
if ( V_52 -> type == V_75 ) {
V_113 = V_52 -> V_76 . V_77 -> V_81 . V_99 ;
V_114 = V_52 -> V_76 . V_77 -> V_81 . V_80 ;
}
for (; ; ) {
V_109 = F_57 ( V_27 -> V_115 . V_116 . V_81 ,
V_109 + 1 ) ;
if ( V_109 < 0 )
break;
switch ( V_52 -> type ) {
case V_66 :
V_110 = V_109 ;
break;
case V_75 :
if ( V_109 >= V_113 )
return - V_44 ;
V_110 = V_114 [ V_109 ] ;
if ( V_110 >= V_106 )
return - V_44 ;
break;
}
if ( V_110 >= V_112 )
return - V_117 ;
F_2 ( V_107 , V_110 , 1 ) ;
if ( V_110 > V_111 )
V_111 = V_110 ;
}
if ( ++ V_111 % 8 )
return V_111 / 8 + 1 ;
return V_111 / 8 ;
}
static int F_58 ( const struct V_50 * V_52 ,
const unsigned char * V_107 ,
T_1 V_108 ,
struct V_26 * V_27 )
{
int V_43 ;
int V_110 = - 1 ;
T_1 V_109 = V_106 ;
T_1 V_112 = V_108 * 8 ;
T_1 V_118 = 0 ;
T_1 * V_119 = NULL ;
if ( V_52 -> type == V_75 ) {
V_118 = V_52 -> V_76 . V_77 -> V_81 . V_102 ;
V_119 = V_52 -> V_76 . V_77 -> V_81 . V_79 ;
}
for (; ; ) {
V_110 = F_1 ( V_107 ,
V_112 ,
V_110 + 1 ,
1 ) ;
if ( V_110 < 0 ) {
if ( V_110 == - 2 )
return - V_96 ;
return 0 ;
}
switch ( V_52 -> type ) {
case V_66 :
V_109 = V_110 ;
break;
case V_75 :
if ( V_110 >= V_118 )
return - V_44 ;
V_109 = V_119 [ V_110 ] ;
if ( V_109 >= V_106 )
return - V_44 ;
break;
}
V_43 = F_59 ( & V_27 -> V_115 . V_116 . V_81 ,
V_109 ,
V_48 ) ;
if ( V_43 != 0 )
return V_43 ;
}
return - V_55 ;
}
static int F_60 ( const struct V_50 * V_52 ,
const unsigned char * V_120 ,
T_1 V_121 )
{
T_4 V_81 ;
int V_122 = - 1 ;
T_1 V_16 ;
if ( V_52 -> type != V_66 || V_121 & 0x01 )
return - V_96 ;
for ( V_16 = 0 ; V_16 < V_121 ; V_16 += 2 ) {
V_81 = F_61 ( & V_120 [ V_16 ] ) ;
if ( V_81 <= V_122 )
return - V_96 ;
V_122 = V_81 ;
}
return 0 ;
}
static int F_62 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_107 ,
T_1 V_108 )
{
int V_81 = - 1 ;
T_1 V_123 = 0 ;
for (; ; ) {
V_81 = F_57 ( V_27 -> V_115 . V_116 . V_81 , V_81 + 1 ) ;
if ( V_81 < 0 )
break;
if ( ( V_123 + 2 ) > V_108 )
return - V_117 ;
* ( ( V_124 * ) & V_107 [ V_123 ] ) = F_63 ( V_81 ) ;
V_123 += 2 ;
}
return V_123 ;
}
static int F_64 ( const struct V_50 * V_52 ,
const unsigned char * V_107 ,
T_1 V_108 ,
struct V_26 * V_27 )
{
int V_43 ;
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_108 ; V_16 += 2 ) {
V_43 = F_59 ( & V_27 -> V_115 . V_116 . V_81 ,
F_61 ( & V_107 [ V_16 ] ) ,
V_48 ) ;
if ( V_43 != 0 )
return V_43 ;
}
return 0 ;
}
static int F_65 ( const struct V_50 * V_52 ,
const unsigned char * V_125 ,
T_1 V_126 )
{
T_4 V_127 ;
T_4 V_128 ;
T_1 V_122 = V_129 + 1 ;
T_1 V_16 ;
if ( V_52 -> type != V_66 || V_126 & 0x01 )
return - V_96 ;
for ( V_16 = 0 ; V_16 < V_126 ; V_16 += 4 ) {
V_127 = F_61 ( & V_125 [ V_16 ] ) ;
if ( ( V_16 + 4 ) <= V_126 )
V_128 = F_61 ( & V_125 [ V_16 + 2 ] ) ;
else
V_128 = 0 ;
if ( V_127 > V_122 )
return - V_96 ;
V_122 = V_128 ;
}
return 0 ;
}
static int F_66 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_107 ,
T_1 V_108 )
{
int V_16 = - 1 ;
T_4 V_130 [ V_131 * 2 ] ;
T_1 V_132 = 0 ;
T_1 V_133 = 0 ;
if ( V_108 >
( V_134 - V_135 - V_136 ) )
return - V_117 ;
for (; ; ) {
V_16 = F_57 ( V_27 -> V_115 . V_116 . V_81 , V_16 + 1 ) ;
if ( V_16 < 0 )
break;
V_133 += ( V_16 == 0 ? 0 : sizeof( T_4 ) ) ;
if ( V_133 > V_108 )
return - V_117 ;
V_130 [ V_132 ++ ] = V_16 ;
V_16 = F_67 ( V_27 -> V_115 . V_116 . V_81 , V_16 ) ;
if ( V_16 < 0 )
return - V_96 ;
V_133 += sizeof( T_4 ) ;
if ( V_133 > V_108 )
return - V_117 ;
V_130 [ V_132 ++ ] = V_16 ;
}
for ( V_16 = 0 ; V_132 > 0 ; ) {
* ( ( V_124 * ) & V_107 [ V_16 ] ) = F_63 ( V_130 [ -- V_132 ] ) ;
V_16 += 2 ;
V_132 -- ;
if ( V_130 [ V_132 ] != 0 ) {
* ( ( V_124 * ) & V_107 [ V_16 ] ) = F_63 ( V_130 [ V_132 ] ) ;
V_16 += 2 ;
}
}
return V_133 ;
}
static int F_68 ( const struct V_50 * V_52 ,
const unsigned char * V_107 ,
T_1 V_108 ,
struct V_26 * V_27 )
{
int V_43 ;
T_1 V_137 ;
T_4 V_128 ;
T_4 V_127 ;
for ( V_137 = 0 ; V_137 < V_108 ; V_137 += 4 ) {
V_127 = F_61 ( & V_107 [ V_137 ] ) ;
if ( ( V_137 + 4 ) <= V_108 )
V_128 = F_61 ( & V_107 [ V_137 + 2 ] ) ;
else
V_128 = 0 ;
V_43 = F_69 ( & V_27 -> V_115 . V_116 . V_81 ,
V_128 ,
V_127 ,
V_48 ) ;
if ( V_43 != 0 )
return V_43 ;
}
return 0 ;
}
static void F_70 ( const struct V_50 * V_52 ,
unsigned char * V_138 ,
T_1 V_139 )
{
V_138 [ 0 ] = V_140 ;
V_138 [ 1 ] = V_135 + V_139 ;
* ( V_141 * ) & V_138 [ 2 ] = F_71 ( V_52 -> V_51 ) ;
}
static int F_72 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_142 ,
T_1 V_143 )
{
int V_43 ;
T_1 V_144 ;
T_1 V_94 ;
if ( ( V_27 -> V_36 & V_145 ) == 0 )
return - V_44 ;
V_43 = F_53 ( V_52 ,
V_27 -> V_115 . V_116 . V_78 ,
& V_94 ) ;
if ( V_43 != 0 )
return V_43 ;
if ( V_27 -> V_36 & V_146 ) {
V_43 = F_56 ( V_52 ,
V_27 ,
& V_142 [ 4 ] ,
V_143 - 4 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_147 && V_43 > 0 && V_43 <= 10 )
V_144 = 14 ;
else
V_144 = 4 + V_43 ;
} else
V_144 = 4 ;
V_142 [ 0 ] = V_63 ;
V_142 [ 1 ] = V_144 ;
V_142 [ 3 ] = V_94 ;
return V_144 ;
}
static int F_73 ( const struct V_50 * V_52 ,
const unsigned char * V_148 ,
struct V_26 * V_27 )
{
int V_43 ;
T_2 V_144 = V_148 [ 1 ] ;
T_1 V_94 ;
V_43 = F_54 ( V_52 , V_148 [ 3 ] , & V_94 ) ;
if ( V_43 != 0 )
return V_43 ;
V_27 -> V_115 . V_116 . V_78 = V_94 ;
V_27 -> V_36 |= V_145 ;
if ( V_144 > 4 ) {
V_43 = F_58 ( V_52 ,
& V_148 [ 4 ] ,
V_144 - 4 ,
V_27 ) ;
if ( V_43 != 0 ) {
F_74 ( V_27 -> V_115 . V_116 . V_81 ) ;
return V_43 ;
}
V_27 -> V_36 |= V_146 ;
}
return 0 ;
}
static int F_75 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_142 ,
T_1 V_143 )
{
int V_43 ;
T_1 V_144 ;
T_1 V_94 ;
if ( ! ( V_27 -> V_36 & V_145 ) )
return - V_44 ;
V_43 = F_53 ( V_52 ,
V_27 -> V_115 . V_116 . V_78 ,
& V_94 ) ;
if ( V_43 != 0 )
return V_43 ;
if ( V_27 -> V_36 & V_146 ) {
V_43 = F_62 ( V_52 ,
V_27 ,
& V_142 [ 4 ] ,
V_143 - 4 ) ;
if ( V_43 < 0 )
return V_43 ;
V_144 = 4 + V_43 ;
} else
V_144 = 4 ;
V_142 [ 0 ] = V_65 ;
V_142 [ 1 ] = V_144 ;
V_142 [ 3 ] = V_94 ;
return V_144 ;
}
static int F_76 ( const struct V_50 * V_52 ,
const unsigned char * V_148 ,
struct V_26 * V_27 )
{
int V_43 ;
T_2 V_144 = V_148 [ 1 ] ;
T_1 V_94 ;
V_43 = F_54 ( V_52 , V_148 [ 3 ] , & V_94 ) ;
if ( V_43 != 0 )
return V_43 ;
V_27 -> V_115 . V_116 . V_78 = V_94 ;
V_27 -> V_36 |= V_145 ;
if ( V_144 > 4 ) {
V_43 = F_64 ( V_52 ,
& V_148 [ 4 ] ,
V_144 - 4 ,
V_27 ) ;
if ( V_43 != 0 ) {
F_74 ( V_27 -> V_115 . V_116 . V_81 ) ;
return V_43 ;
}
V_27 -> V_36 |= V_146 ;
}
return 0 ;
}
static int F_77 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_142 ,
T_1 V_143 )
{
int V_43 ;
T_1 V_144 ;
T_1 V_94 ;
if ( ! ( V_27 -> V_36 & V_145 ) )
return - V_44 ;
V_43 = F_53 ( V_52 ,
V_27 -> V_115 . V_116 . V_78 ,
& V_94 ) ;
if ( V_43 != 0 )
return V_43 ;
if ( V_27 -> V_36 & V_146 ) {
V_43 = F_66 ( V_52 ,
V_27 ,
& V_142 [ 4 ] ,
V_143 - 4 ) ;
if ( V_43 < 0 )
return V_43 ;
V_144 = 4 + V_43 ;
} else
V_144 = 4 ;
V_142 [ 0 ] = V_64 ;
V_142 [ 1 ] = V_144 ;
V_142 [ 3 ] = V_94 ;
return V_144 ;
}
static int F_78 ( const struct V_50 * V_52 ,
const unsigned char * V_148 ,
struct V_26 * V_27 )
{
int V_43 ;
T_2 V_144 = V_148 [ 1 ] ;
T_1 V_94 ;
V_43 = F_54 ( V_52 , V_148 [ 3 ] , & V_94 ) ;
if ( V_43 != 0 )
return V_43 ;
V_27 -> V_115 . V_116 . V_78 = V_94 ;
V_27 -> V_36 |= V_145 ;
if ( V_144 > 4 ) {
V_43 = F_68 ( V_52 ,
& V_148 [ 4 ] ,
V_144 - 4 ,
V_27 ) ;
if ( V_43 != 0 ) {
F_74 ( V_27 -> V_115 . V_116 . V_81 ) ;
return V_43 ;
}
V_27 -> V_36 |= V_146 ;
}
return 0 ;
}
static int F_79 ( const struct V_50 * V_52 ,
const struct V_26 * V_27 ,
unsigned char * V_142 ,
T_1 V_143 )
{
if ( ! ( V_27 -> V_36 & V_149 ) )
return - V_44 ;
V_142 [ 0 ] = V_67 ;
V_142 [ 1 ] = V_150 ;
* ( T_1 * ) & V_142 [ 2 ] = V_27 -> V_115 . V_151 ;
return V_150 ;
}
static int F_80 ( const struct V_50 * V_52 ,
const unsigned char * V_148 ,
struct V_26 * V_27 )
{
V_27 -> V_115 . V_151 = * ( T_1 * ) & V_148 [ 2 ] ;
V_27 -> V_36 |= V_149 ;
return 0 ;
}
unsigned char * F_81 ( const struct V_152 * V_153 )
{
const struct V_154 * V_155 = F_82 ( V_153 ) ;
unsigned char * V_156 = ( unsigned char * ) & ( F_82 ( V_153 ) [ 1 ] ) ;
int V_157 ;
int V_158 ;
for ( V_157 = V_155 -> V_159 * 4 - sizeof( struct V_154 ) ; V_157 > 0 ; ) {
if ( V_156 [ 0 ] == V_140 )
return V_156 ;
V_158 = V_156 [ 1 ] ;
V_157 -= V_158 ;
V_156 += V_158 ;
}
return NULL ;
}
int F_83 ( const struct V_152 * V_153 , unsigned char * * V_160 )
{
unsigned char * V_161 = * V_160 ;
unsigned char * V_148 ;
unsigned char V_162 ;
unsigned char V_163 = 0 ;
T_2 V_164 ;
T_2 V_144 ;
struct V_50 * V_52 = NULL ;
T_1 V_165 ;
V_164 = V_161 [ 1 ] ;
if ( V_164 < 8 ) {
V_163 = 1 ;
goto V_166;
}
F_46 () ;
V_52 = F_27 ( F_84 ( & V_161 [ 2 ] ) ) ;
if ( V_52 == NULL ) {
V_163 = 2 ;
goto V_167;
}
V_162 = V_135 ;
V_148 = V_161 + V_162 ;
while ( V_162 < V_164 ) {
for ( V_165 = 0 ; V_52 -> V_62 [ V_165 ] != V_148 [ 0 ] ; )
if ( V_52 -> V_62 [ V_165 ] == V_69 ||
++ V_165 == V_61 ) {
V_163 = V_162 ;
goto V_167;
}
V_144 = V_148 [ 1 ] ;
if ( V_144 > ( V_164 - V_162 ) ) {
V_163 = V_162 + 1 ;
goto V_167;
}
switch ( V_148 [ 0 ] ) {
case V_63 :
if ( V_144 < V_168 ) {
V_163 = V_162 + 1 ;
goto V_167;
}
if ( V_169 ) {
if ( F_52 ( V_52 ,
V_148 [ 3 ] ) < 0 ) {
V_163 = V_162 + 3 ;
goto V_167;
}
if ( V_144 > V_168 &&
F_55 ( V_52 ,
& V_148 [ 4 ] ,
V_144 - 4 ) < 0 ) {
V_163 = V_162 + 4 ;
goto V_167;
}
}
break;
case V_65 :
if ( V_144 < V_170 ) {
V_163 = V_162 + 1 ;
goto V_167;
}
if ( F_52 ( V_52 ,
V_148 [ 3 ] ) < 0 ) {
V_163 = V_162 + 3 ;
goto V_167;
}
if ( V_144 > V_170 &&
F_60 ( V_52 ,
& V_148 [ 4 ] ,
V_144 - 4 ) < 0 ) {
V_163 = V_162 + 4 ;
goto V_167;
}
break;
case V_64 :
if ( V_144 < V_136 ) {
V_163 = V_162 + 1 ;
goto V_167;
}
if ( F_52 ( V_52 ,
V_148 [ 3 ] ) < 0 ) {
V_163 = V_162 + 3 ;
goto V_167;
}
if ( V_144 > V_136 &&
F_65 ( V_52 ,
& V_148 [ 4 ] ,
V_144 - 4 ) < 0 ) {
V_163 = V_162 + 4 ;
goto V_167;
}
break;
case V_67 :
if ( V_153 == NULL || ! ( V_153 -> V_171 -> V_36 & V_172 ) ) {
V_163 = V_162 ;
goto V_167;
}
if ( V_144 != V_150 ) {
V_163 = V_162 + 1 ;
goto V_167;
}
break;
default:
V_163 = V_162 ;
goto V_167;
}
V_148 += V_144 ;
V_162 += V_144 ;
}
V_167:
F_48 () ;
V_166:
* V_160 = V_161 + V_163 ;
return V_163 ;
}
void F_85 ( struct V_152 * V_153 , int error , T_1 V_173 )
{
if ( F_82 ( V_153 ) -> V_174 == V_175 || error != - V_176 )
return;
if ( V_173 )
F_86 ( V_153 , V_177 , V_178 , 0 ) ;
else
F_86 ( V_153 , V_177 , V_179 , 0 ) ;
}
static int F_87 ( unsigned char * V_138 , T_1 V_180 ,
const struct V_50 * V_52 ,
const struct V_26 * V_27 )
{
int V_43 ;
T_1 V_16 ;
if ( V_180 <= V_135 )
return - V_117 ;
V_16 = 0 ;
do {
memset ( V_138 , 0 , V_180 ) ;
switch ( V_52 -> V_62 [ V_16 ] ) {
case V_63 :
V_43 = F_72 ( V_52 ,
V_27 ,
& V_138 [ V_135 ] ,
V_180 - V_135 ) ;
break;
case V_65 :
V_43 = F_75 ( V_52 ,
V_27 ,
& V_138 [ V_135 ] ,
V_180 - V_135 ) ;
break;
case V_64 :
V_43 = F_77 ( V_52 ,
V_27 ,
& V_138 [ V_135 ] ,
V_180 - V_135 ) ;
break;
case V_67 :
V_43 = F_79 ( V_52 ,
V_27 ,
& V_138 [ V_135 ] ,
V_180 - V_135 ) ;
break;
default:
return - V_44 ;
}
V_16 ++ ;
} while ( V_43 < 0 &&
V_16 < V_61 &&
V_52 -> V_62 [ V_16 ] != V_69 );
if ( V_43 < 0 )
return V_43 ;
F_70 ( V_52 , V_138 , V_43 ) ;
return V_135 + V_43 ;
}
int F_88 ( struct V_181 * V_182 ,
const struct V_50 * V_52 ,
const struct V_26 * V_27 )
{
int V_43 = - V_44 ;
unsigned char * V_138 = NULL ;
T_1 V_180 ;
T_1 V_164 ;
struct V_183 * V_184 , * V_161 = NULL ;
struct V_185 * V_186 ;
struct V_187 * V_188 ;
if ( V_182 == NULL )
return 0 ;
V_180 = V_134 ;
V_138 = F_89 ( V_180 , V_48 ) ;
if ( V_138 == NULL ) {
V_43 = - V_21 ;
goto V_189;
}
V_43 = F_87 ( V_138 , V_180 , V_52 , V_27 ) ;
if ( V_43 < 0 )
goto V_189;
V_180 = V_43 ;
V_164 = ( V_180 + 3 ) & ~ 3 ;
V_161 = F_23 ( sizeof( * V_161 ) + V_164 , V_48 ) ;
if ( V_161 == NULL ) {
V_43 = - V_21 ;
goto V_189;
}
memcpy ( V_161 -> V_161 . V_190 , V_138 , V_180 ) ;
V_161 -> V_161 . V_157 = V_164 ;
V_161 -> V_161 . V_79 = sizeof( struct V_154 ) ;
F_5 ( V_138 ) ;
V_138 = NULL ;
V_186 = F_90 ( V_182 ) ;
V_184 = F_91 ( V_186 -> V_191 , F_92 ( V_182 ) ) ;
if ( V_186 -> V_192 ) {
V_188 = F_93 ( V_182 ) ;
if ( V_184 )
V_188 -> V_193 -= V_184 -> V_161 . V_157 ;
V_188 -> V_193 += V_161 -> V_161 . V_157 ;
V_188 -> V_194 ( V_182 , V_188 -> V_195 ) ;
}
F_94 ( V_186 -> V_191 , V_161 ) ;
if ( V_184 )
F_95 ( V_184 , V_83 ) ;
return 0 ;
V_189:
F_5 ( V_138 ) ;
F_5 ( V_161 ) ;
return V_43 ;
}
int F_96 ( struct V_196 * V_197 ,
const struct V_50 * V_52 ,
const struct V_26 * V_27 )
{
int V_43 = - V_44 ;
unsigned char * V_138 = NULL ;
T_1 V_180 ;
T_1 V_164 ;
struct V_183 * V_161 = NULL ;
struct V_198 * V_199 ;
V_180 = V_134 ;
V_138 = F_89 ( V_180 , V_48 ) ;
if ( V_138 == NULL ) {
V_43 = - V_21 ;
goto V_200;
}
V_43 = F_87 ( V_138 , V_180 , V_52 , V_27 ) ;
if ( V_43 < 0 )
goto V_200;
V_180 = V_43 ;
V_164 = ( V_180 + 3 ) & ~ 3 ;
V_161 = F_23 ( sizeof( * V_161 ) + V_164 , V_48 ) ;
if ( V_161 == NULL ) {
V_43 = - V_21 ;
goto V_200;
}
memcpy ( V_161 -> V_161 . V_190 , V_138 , V_180 ) ;
V_161 -> V_161 . V_157 = V_164 ;
V_161 -> V_161 . V_79 = sizeof( struct V_154 ) ;
F_5 ( V_138 ) ;
V_138 = NULL ;
V_199 = F_97 ( V_197 ) ;
V_161 = F_98 ( & V_199 -> V_161 , V_161 ) ;
if ( V_161 )
F_95 ( V_161 , V_83 ) ;
return 0 ;
V_200:
F_5 ( V_138 ) ;
F_5 ( V_161 ) ;
return V_43 ;
}
static int F_99 ( struct V_183 * * V_201 )
{
int V_202 = 0 ;
struct V_183 * V_161 = * V_201 ;
if ( V_161 -> V_161 . V_203 || V_161 -> V_161 . V_204 || V_161 -> V_161 . V_205 || V_161 -> V_161 . V_206 ) {
T_2 V_207 ;
T_2 V_208 ;
unsigned char * V_42 ;
int V_16 ;
int V_209 ;
V_208 = V_161 -> V_161 . V_79 - sizeof( struct V_154 ) ;
V_42 = & V_161 -> V_161 . V_190 [ V_208 ] ;
V_207 = V_42 [ 1 ] ;
if ( V_161 -> V_161 . V_203 > V_161 -> V_161 . V_79 )
V_161 -> V_161 . V_203 -= V_207 ;
if ( V_161 -> V_161 . V_204 > V_161 -> V_161 . V_79 )
V_161 -> V_161 . V_204 -= V_207 ;
if ( V_161 -> V_161 . V_205 > V_161 -> V_161 . V_79 )
V_161 -> V_161 . V_205 -= V_207 ;
if ( V_161 -> V_161 . V_206 > V_161 -> V_161 . V_79 )
V_161 -> V_161 . V_206 -= V_207 ;
V_161 -> V_161 . V_79 = 0 ;
memmove ( V_42 , V_42 + V_207 ,
V_161 -> V_161 . V_157 - V_208 - V_207 ) ;
V_16 = 0 ;
V_209 = 0 ;
while ( V_16 < V_161 -> V_161 . V_157 )
if ( V_161 -> V_161 . V_190 [ V_16 ] != V_210 ) {
V_16 += V_161 -> V_161 . V_190 [ V_16 + 1 ] ;
V_209 = V_16 ;
} else
V_16 ++ ;
V_202 = V_161 -> V_161 . V_157 ;
V_161 -> V_161 . V_157 = ( V_209 + 3 ) & ~ 3 ;
V_202 -= V_161 -> V_161 . V_157 ;
} else {
* V_201 = NULL ;
V_202 = V_161 -> V_161 . V_157 ;
F_95 ( V_161 , V_83 ) ;
}
return V_202 ;
}
void F_100 ( struct V_181 * V_182 )
{
int V_202 ;
struct V_183 * V_161 ;
struct V_185 * V_186 ;
V_186 = F_90 ( V_182 ) ;
V_161 = F_91 ( V_186 -> V_191 , 1 ) ;
if ( V_161 == NULL || V_161 -> V_161 . V_79 == 0 )
return;
V_202 = F_99 ( & V_186 -> V_191 ) ;
if ( V_186 -> V_192 && V_202 > 0 ) {
struct V_187 * V_188 = F_93 ( V_182 ) ;
V_188 -> V_193 -= V_202 ;
V_188 -> V_194 ( V_182 , V_188 -> V_195 ) ;
}
}
void F_101 ( struct V_196 * V_197 )
{
struct V_183 * V_161 ;
struct V_198 * V_199 ;
V_199 = F_97 ( V_197 ) ;
V_161 = V_199 -> V_161 ;
if ( V_161 == NULL || V_161 -> V_161 . V_79 == 0 )
return;
F_99 ( & V_199 -> V_161 ) ;
}
int F_102 ( const unsigned char * V_79 ,
struct V_26 * V_27 )
{
int V_43 = - V_211 ;
T_1 V_51 ;
struct V_50 * V_52 ;
if ( F_17 ( V_79 , V_79 [ 1 ] , V_27 ) == 0 )
return 0 ;
V_51 = F_84 ( & V_79 [ 2 ] ) ;
F_46 () ;
V_52 = F_27 ( V_51 ) ;
if ( V_52 == NULL )
goto V_212;
switch ( V_79 [ 6 ] ) {
case V_63 :
V_43 = F_73 ( V_52 , & V_79 [ 6 ] , V_27 ) ;
break;
case V_65 :
V_43 = F_76 ( V_52 , & V_79 [ 6 ] , V_27 ) ;
break;
case V_64 :
V_43 = F_78 ( V_52 , & V_79 [ 6 ] , V_27 ) ;
break;
case V_67 :
V_43 = F_80 ( V_52 , & V_79 [ 6 ] , V_27 ) ;
break;
}
if ( V_43 == 0 )
V_27 -> type = V_38 ;
V_212:
F_48 () ;
return V_43 ;
}
int F_103 ( struct V_181 * V_182 , struct V_26 * V_27 )
{
struct V_183 * V_161 ;
int V_213 = - V_211 ;
F_46 () ;
V_161 = F_104 ( F_90 ( V_182 ) -> V_191 ) ;
if ( V_161 && V_161 -> V_161 . V_79 )
V_213 = F_102 ( V_161 -> V_161 . V_190 +
V_161 -> V_161 . V_79 -
sizeof( struct V_154 ) ,
V_27 ) ;
F_48 () ;
return V_213 ;
}
int F_105 ( struct V_152 * V_153 ,
const struct V_50 * V_52 ,
const struct V_26 * V_27 )
{
int V_43 ;
struct V_154 * V_155 ;
struct V_214 * V_161 = & F_106 ( V_153 ) -> V_161 ;
unsigned char V_138 [ V_134 ] ;
T_1 V_180 = V_134 ;
T_1 V_164 ;
int V_215 ;
V_43 = F_87 ( V_138 , V_180 , V_52 , V_27 ) ;
if ( V_43 < 0 )
return V_43 ;
V_180 = V_43 ;
V_164 = ( V_180 + 3 ) & ~ 3 ;
V_215 = V_164 - V_161 -> V_157 ;
V_43 = F_107 ( V_153 , F_108 ( V_153 ) + V_215 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_215 > 0 ) {
V_155 = F_82 ( V_153 ) ;
F_109 ( V_153 , V_215 ) ;
memmove ( ( char * ) V_155 - V_215 , V_155 , V_155 -> V_159 << 2 ) ;
F_110 ( V_153 ) ;
V_155 = F_82 ( V_153 ) ;
} else if ( V_215 < 0 ) {
V_155 = F_82 ( V_153 ) ;
memset ( V_155 + 1 , V_210 , V_161 -> V_157 ) ;
} else
V_155 = F_82 ( V_153 ) ;
if ( V_161 -> V_157 > 0 )
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> V_157 = V_164 ;
V_161 -> V_79 = sizeof( struct V_154 ) ;
V_161 -> V_216 = 1 ;
memcpy ( V_155 + 1 , V_138 , V_180 ) ;
if ( V_164 > V_180 )
memset ( ( char * ) ( V_155 + 1 ) + V_180 , 0 , V_164 - V_180 ) ;
if ( V_215 != 0 ) {
V_155 -> V_159 = 5 + ( V_164 >> 2 ) ;
V_155 -> V_217 = F_63 ( V_153 -> V_139 ) ;
}
F_111 ( V_155 ) ;
return 0 ;
}
int F_112 ( struct V_152 * V_153 )
{
int V_43 ;
struct V_154 * V_155 ;
struct V_214 * V_161 = & F_106 ( V_153 ) -> V_161 ;
unsigned char * V_42 ;
if ( V_161 -> V_79 == 0 )
return 0 ;
V_43 = F_107 ( V_153 , F_108 ( V_153 ) ) ;
if ( V_43 < 0 )
return V_43 ;
V_155 = F_82 ( V_153 ) ;
V_42 = ( unsigned char * ) V_155 + V_161 -> V_79 ;
memset ( V_42 , V_218 , V_42 [ 1 ] ) ;
V_161 -> V_79 = 0 ;
V_161 -> V_216 = 1 ;
F_111 ( V_155 ) ;
return 0 ;
}
static int T_3 F_113 ( void )
{
int V_43 ;
V_43 = F_8 () ;
if ( V_43 != 0 )
F_114 ( L_7 ,
V_43 ) ;
return 0 ;
}
