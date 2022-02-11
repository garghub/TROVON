static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
static T_1 F_4 ( const unsigned char * V_4 , T_1 V_5 )
{
return F_5 ( V_4 , V_5 , 0 ) ;
}
static int T_2 F_6 ( void )
{
T_1 V_6 ;
V_7 = F_7 ( V_8 ,
sizeof( struct V_9 ) ,
V_10 ) ;
if ( ! V_7 )
return - V_11 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
F_8 ( & V_7 [ V_6 ] . V_12 ) ;
V_7 [ V_6 ] . V_13 = 0 ;
F_9 ( & V_7 [ V_6 ] . V_14 ) ;
}
return 0 ;
}
void F_10 ( void )
{
struct V_1 * V_2 , * V_15 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
F_11 ( & V_7 [ V_6 ] . V_12 ) ;
F_12 (entry,
tmp_entry,
&cipso_v4_cache[iter].list, list) {
F_13 ( & V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
}
V_7 [ V_6 ] . V_13 = 0 ;
F_14 ( & V_7 [ V_6 ] . V_12 ) ;
}
}
static int F_15 ( const unsigned char * V_4 ,
T_1 V_5 ,
struct V_16 * V_17 )
{
T_1 V_18 ;
struct V_1 * V_2 ;
struct V_1 * V_19 = NULL ;
T_1 V_20 ;
if ( ! V_21 )
return - V_22 ;
V_20 = F_4 ( V_4 , V_5 ) ;
V_18 = V_20 & ( V_8 - 1 ) ;
F_11 ( & V_7 [ V_18 ] . V_12 ) ;
F_16 (entry, &cipso_v4_cache[bkt].list, list) {
if ( V_2 -> V_20 == V_20 &&
V_2 -> V_5 == V_5 &&
memcmp ( V_2 -> V_4 , V_4 , V_5 ) == 0 ) {
V_2 -> V_23 += 1 ;
F_17 ( & V_2 -> V_3 -> V_24 ) ;
V_17 -> V_25 = V_2 -> V_3 ;
V_17 -> V_26 |= V_27 ;
V_17 -> type = V_28 ;
if ( ! V_19 ) {
F_14 ( & V_7 [ V_18 ] . V_12 ) ;
return 0 ;
}
if ( V_19 -> V_23 > 0 )
V_19 -> V_23 -= 1 ;
if ( V_2 -> V_23 > V_19 -> V_23 &&
V_2 -> V_23 - V_19 -> V_23 >
V_29 ) {
F_18 ( V_2 -> V_14 . V_30 , V_2 -> V_14 . V_31 ) ;
F_19 ( & V_2 -> V_14 ,
V_19 -> V_14 . V_30 ,
& V_19 -> V_14 ) ;
}
F_14 ( & V_7 [ V_18 ] . V_12 ) ;
return 0 ;
}
V_19 = V_2 ;
}
F_14 ( & V_7 [ V_18 ] . V_12 ) ;
return - V_22 ;
}
int F_20 ( const unsigned char * V_32 ,
const struct V_16 * V_17 )
{
int V_33 = - V_34 ;
T_1 V_18 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_35 = NULL ;
T_1 V_36 ;
if ( ! V_21 || V_37 <= 0 )
return 0 ;
V_36 = V_32 [ 1 ] ;
V_2 = F_21 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_11 ;
V_2 -> V_4 = F_22 ( V_32 , V_36 , V_38 ) ;
if ( ! V_2 -> V_4 ) {
V_33 = - V_11 ;
goto V_39;
}
V_2 -> V_5 = V_36 ;
V_2 -> V_20 = F_4 ( V_32 , V_36 ) ;
F_17 ( & V_17 -> V_25 -> V_24 ) ;
V_2 -> V_3 = V_17 -> V_25 ;
V_18 = V_2 -> V_20 & ( V_8 - 1 ) ;
F_11 ( & V_7 [ V_18 ] . V_12 ) ;
if ( V_7 [ V_18 ] . V_13 < V_37 ) {
F_23 ( & V_2 -> V_14 , & V_7 [ V_18 ] . V_14 ) ;
V_7 [ V_18 ] . V_13 += 1 ;
} else {
V_35 = F_24 ( V_7 [ V_18 ] . V_14 . V_30 ,
struct V_1 , V_14 ) ;
F_13 ( & V_35 -> V_14 ) ;
F_23 ( & V_2 -> V_14 , & V_7 [ V_18 ] . V_14 ) ;
F_1 ( V_35 ) ;
}
F_14 ( & V_7 [ V_18 ] . V_12 ) ;
return 0 ;
V_39:
if ( V_2 )
F_1 ( V_2 ) ;
return V_33 ;
}
static struct V_40 * F_25 ( T_1 V_41 )
{
struct V_40 * V_6 ;
F_26 (iter, &cipso_v4_doi_list, list)
if ( V_6 -> V_41 == V_41 && F_27 ( & V_6 -> V_24 ) )
return V_6 ;
return NULL ;
}
int F_28 ( struct V_40 * V_42 ,
struct V_43 * V_44 )
{
int V_33 = - V_45 ;
T_1 V_6 ;
T_1 V_41 ;
T_1 V_46 ;
struct V_47 * V_48 ;
V_41 = V_42 -> V_41 ;
V_46 = V_42 -> type ;
if ( V_42 -> V_41 == V_49 )
goto V_50;
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ ) {
switch ( V_42 -> V_52 [ V_6 ] ) {
case V_53 :
break;
case V_54 :
case V_55 :
if ( V_42 -> type != V_56 )
goto V_50;
break;
case V_57 :
if ( V_42 -> type != V_58 )
goto V_50;
break;
case V_59 :
if ( V_6 == 0 )
goto V_50;
break;
default:
goto V_50;
}
}
F_29 ( & V_42 -> V_24 , 1 ) ;
F_30 ( & V_60 ) ;
if ( F_25 ( V_42 -> V_41 ) ) {
F_31 ( & V_60 ) ;
V_33 = - V_61 ;
goto V_50;
}
F_32 ( & V_42 -> V_14 , & V_62 ) ;
F_31 ( & V_60 ) ;
V_33 = 0 ;
V_50:
V_48 = F_33 ( V_63 , V_44 ) ;
if ( V_48 ) {
const char * V_64 ;
switch ( V_46 ) {
case V_65 :
V_64 = L_1 ;
break;
case V_56 :
V_64 = L_2 ;
break;
case V_58 :
V_64 = L_3 ;
break;
default:
V_64 = L_4 ;
}
F_34 ( V_48 ,
L_5 ,
V_41 , V_64 , V_33 == 0 ? 1 : 0 ) ;
F_35 ( V_48 ) ;
}
return V_33 ;
}
void F_36 ( struct V_40 * V_42 )
{
if ( ! V_42 )
return;
switch ( V_42 -> type ) {
case V_65 :
F_3 ( V_42 -> V_66 . V_67 -> V_68 . V_69 ) ;
F_3 ( V_42 -> V_66 . V_67 -> V_68 . V_70 ) ;
F_3 ( V_42 -> V_66 . V_67 -> V_71 . V_69 ) ;
F_3 ( V_42 -> V_66 . V_67 -> V_71 . V_70 ) ;
break;
}
F_3 ( V_42 ) ;
}
static void F_37 ( struct V_72 * V_2 )
{
struct V_40 * V_42 ;
V_42 = F_38 ( V_2 , struct V_40 , V_73 ) ;
F_36 ( V_42 ) ;
}
int F_39 ( T_1 V_41 , struct V_43 * V_44 )
{
int V_33 ;
struct V_40 * V_42 ;
struct V_47 * V_48 ;
F_30 ( & V_60 ) ;
V_42 = F_25 ( V_41 ) ;
if ( ! V_42 ) {
F_31 ( & V_60 ) ;
V_33 = - V_22 ;
goto V_74;
}
if ( ! F_40 ( & V_42 -> V_24 ) ) {
F_31 ( & V_60 ) ;
V_33 = - V_75 ;
goto V_74;
}
F_41 ( & V_42 -> V_14 ) ;
F_31 ( & V_60 ) ;
F_10 () ;
F_42 ( & V_42 -> V_73 , F_37 ) ;
V_33 = 0 ;
V_74:
V_48 = F_33 ( V_76 , V_44 ) ;
if ( V_48 ) {
F_34 ( V_48 ,
L_6 ,
V_41 , V_33 == 0 ? 1 : 0 ) ;
F_35 ( V_48 ) ;
}
return V_33 ;
}
struct V_40 * F_43 ( T_1 V_41 )
{
struct V_40 * V_42 ;
F_44 () ;
V_42 = F_25 ( V_41 ) ;
if ( ! V_42 )
goto V_77;
if ( ! F_45 ( & V_42 -> V_24 ) )
V_42 = NULL ;
V_77:
F_46 () ;
return V_42 ;
}
void F_47 ( struct V_40 * V_42 )
{
if ( ! V_42 )
return;
if ( ! F_40 ( & V_42 -> V_24 ) )
return;
F_30 ( & V_60 ) ;
F_41 ( & V_42 -> V_14 ) ;
F_31 ( & V_60 ) ;
F_10 () ;
F_42 ( & V_42 -> V_73 , F_37 ) ;
}
int F_48 ( T_1 * V_78 ,
int (* F_49) ( struct V_40 * V_42 , void * V_79 ) ,
void * V_80 )
{
int V_33 = - V_22 ;
T_1 V_81 = 0 ;
struct V_40 * V_82 ;
F_44 () ;
F_26 (iter_doi, &cipso_v4_doi_list, list)
if ( F_27 ( & V_82 -> V_24 ) > 0 ) {
if ( V_81 ++ < * V_78 )
continue;
V_33 = F_49 ( V_82 , V_80 ) ;
if ( V_33 < 0 ) {
V_81 -- ;
goto V_83;
}
}
V_83:
F_46 () ;
* V_78 = V_81 ;
return V_33 ;
}
static int F_50 ( const struct V_40 * V_42 , T_3 V_84 )
{
switch ( V_42 -> type ) {
case V_56 :
return 0 ;
case V_65 :
if ( V_42 -> V_66 . V_67 -> V_68 . V_69 [ V_84 ] < V_85 )
return 0 ;
break;
}
return - V_86 ;
}
static int F_51 ( const struct V_40 * V_42 ,
T_1 V_87 ,
T_1 * V_88 )
{
switch ( V_42 -> type ) {
case V_56 :
* V_88 = V_87 ;
return 0 ;
case V_65 :
if ( V_87 < V_42 -> V_66 . V_67 -> V_68 . V_89 &&
V_42 -> V_66 . V_67 -> V_68 . V_70 [ V_87 ] < V_85 ) {
* V_88 = V_42 -> V_66 . V_67 -> V_68 . V_70 [ V_87 ] ;
return 0 ;
}
return - V_34 ;
}
return - V_45 ;
}
static int F_52 ( const struct V_40 * V_42 ,
T_1 V_88 ,
T_1 * V_87 )
{
struct V_90 * V_91 ;
switch ( V_42 -> type ) {
case V_56 :
* V_87 = V_88 ;
return 0 ;
case V_65 :
V_91 = V_42 -> V_66 . V_67 ;
if ( V_88 < V_91 -> V_68 . V_92 &&
V_91 -> V_68 . V_69 [ V_88 ] < V_85 ) {
* V_87 = V_42 -> V_66 . V_67 -> V_68 . V_69 [ V_88 ] ;
return 0 ;
}
return - V_34 ;
}
return - V_45 ;
}
static int F_53 ( const struct V_40 * V_42 ,
const unsigned char * V_93 ,
T_1 V_94 )
{
int V_71 = - 1 ;
T_1 V_95 = V_94 * 8 ;
T_1 V_96 ;
T_1 * V_97 ;
switch ( V_42 -> type ) {
case V_56 :
return 0 ;
case V_65 :
V_96 = V_42 -> V_66 . V_67 -> V_71 . V_92 ;
V_97 = V_42 -> V_66 . V_67 -> V_71 . V_69 ;
for (; ; ) {
V_71 = F_54 ( V_93 ,
V_95 ,
V_71 + 1 ,
1 ) ;
if ( V_71 < 0 )
break;
if ( V_71 >= V_96 ||
V_97 [ V_71 ] >= V_98 )
return - V_86 ;
}
if ( V_71 == - 1 )
return 0 ;
break;
}
return - V_86 ;
}
static int F_55 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_99 ,
T_1 V_100 )
{
int V_101 = - 1 ;
T_1 V_102 = V_98 ;
T_1 V_103 = 0 ;
T_1 V_104 = V_100 * 8 ;
T_1 V_105 = 0 ;
T_1 * V_106 = NULL ;
if ( V_42 -> type == V_65 ) {
V_105 = V_42 -> V_66 . V_67 -> V_71 . V_89 ;
V_106 = V_42 -> V_66 . V_67 -> V_71 . V_70 ;
}
for (; ; ) {
V_101 = F_56 ( V_17 -> V_107 . V_108 . V_71 ,
V_101 + 1 ) ;
if ( V_101 < 0 )
break;
switch ( V_42 -> type ) {
case V_56 :
V_102 = V_101 ;
break;
case V_65 :
if ( V_101 >= V_105 )
return - V_34 ;
V_102 = V_106 [ V_101 ] ;
if ( V_102 >= V_98 )
return - V_34 ;
break;
}
if ( V_102 >= V_104 )
return - V_109 ;
F_57 ( V_99 , V_102 , 1 ) ;
if ( V_102 > V_103 )
V_103 = V_102 ;
}
if ( ++ V_103 % 8 )
return V_103 / 8 + 1 ;
return V_103 / 8 ;
}
static int F_58 ( const struct V_40 * V_42 ,
const unsigned char * V_99 ,
T_1 V_100 ,
struct V_16 * V_17 )
{
int V_33 ;
int V_102 = - 1 ;
T_1 V_101 = V_98 ;
T_1 V_104 = V_100 * 8 ;
T_1 V_110 = 0 ;
T_1 * V_111 = NULL ;
if ( V_42 -> type == V_65 ) {
V_110 = V_42 -> V_66 . V_67 -> V_71 . V_92 ;
V_111 = V_42 -> V_66 . V_67 -> V_71 . V_69 ;
}
for (; ; ) {
V_102 = F_54 ( V_99 ,
V_104 ,
V_102 + 1 ,
1 ) ;
if ( V_102 < 0 ) {
if ( V_102 == - 2 )
return - V_86 ;
return 0 ;
}
switch ( V_42 -> type ) {
case V_56 :
V_101 = V_102 ;
break;
case V_65 :
if ( V_102 >= V_110 )
return - V_34 ;
V_101 = V_111 [ V_102 ] ;
if ( V_101 >= V_98 )
return - V_34 ;
break;
}
V_33 = F_59 ( & V_17 -> V_107 . V_108 . V_71 ,
V_101 ,
V_38 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return - V_45 ;
}
static int F_60 ( const struct V_40 * V_42 ,
const unsigned char * V_112 ,
T_1 V_113 )
{
T_4 V_71 ;
int V_114 = - 1 ;
T_1 V_6 ;
if ( V_42 -> type != V_56 || V_113 & 0x01 )
return - V_86 ;
for ( V_6 = 0 ; V_6 < V_113 ; V_6 += 2 ) {
V_71 = F_61 ( & V_112 [ V_6 ] ) ;
if ( V_71 <= V_114 )
return - V_86 ;
V_114 = V_71 ;
}
return 0 ;
}
static int F_62 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_99 ,
T_1 V_100 )
{
int V_71 = - 1 ;
T_1 V_115 = 0 ;
for (; ; ) {
V_71 = F_56 ( V_17 -> V_107 . V_108 . V_71 , V_71 + 1 ) ;
if ( V_71 < 0 )
break;
if ( ( V_115 + 2 ) > V_100 )
return - V_109 ;
* ( ( V_116 * ) & V_99 [ V_115 ] ) = F_63 ( V_71 ) ;
V_115 += 2 ;
}
return V_115 ;
}
static int F_64 ( const struct V_40 * V_42 ,
const unsigned char * V_99 ,
T_1 V_100 ,
struct V_16 * V_17 )
{
int V_33 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 += 2 ) {
V_33 = F_59 ( & V_17 -> V_107 . V_108 . V_71 ,
F_61 ( & V_99 [ V_6 ] ) ,
V_38 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return 0 ;
}
static int F_65 ( const struct V_40 * V_42 ,
const unsigned char * V_117 ,
T_1 V_118 )
{
T_4 V_119 ;
T_4 V_120 ;
T_1 V_114 = V_121 + 1 ;
T_1 V_6 ;
if ( V_42 -> type != V_56 || V_118 & 0x01 )
return - V_86 ;
for ( V_6 = 0 ; V_6 < V_118 ; V_6 += 4 ) {
V_119 = F_61 ( & V_117 [ V_6 ] ) ;
if ( ( V_6 + 4 ) <= V_118 )
V_120 = F_61 ( & V_117 [ V_6 + 2 ] ) ;
else
V_120 = 0 ;
if ( V_119 > V_114 )
return - V_86 ;
V_114 = V_120 ;
}
return 0 ;
}
static int F_66 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_99 ,
T_1 V_100 )
{
int V_6 = - 1 ;
T_4 V_122 [ V_123 * 2 ] ;
T_1 V_124 = 0 ;
T_1 V_125 = 0 ;
if ( V_100 >
( V_126 - V_127 - V_128 ) )
return - V_109 ;
for (; ; ) {
V_6 = F_56 ( V_17 -> V_107 . V_108 . V_71 , V_6 + 1 ) ;
if ( V_6 < 0 )
break;
V_125 += ( V_6 == 0 ? 0 : sizeof( T_4 ) ) ;
if ( V_125 > V_100 )
return - V_109 ;
V_122 [ V_124 ++ ] = V_6 ;
V_6 = F_67 ( V_17 -> V_107 . V_108 . V_71 , V_6 ) ;
if ( V_6 < 0 )
return - V_86 ;
V_125 += sizeof( T_4 ) ;
if ( V_125 > V_100 )
return - V_109 ;
V_122 [ V_124 ++ ] = V_6 ;
}
for ( V_6 = 0 ; V_124 > 0 ; ) {
* ( ( V_116 * ) & V_99 [ V_6 ] ) = F_63 ( V_122 [ -- V_124 ] ) ;
V_6 += 2 ;
V_124 -- ;
if ( V_122 [ V_124 ] != 0 ) {
* ( ( V_116 * ) & V_99 [ V_6 ] ) = F_63 ( V_122 [ V_124 ] ) ;
V_6 += 2 ;
}
}
return V_125 ;
}
static int F_68 ( const struct V_40 * V_42 ,
const unsigned char * V_99 ,
T_1 V_100 ,
struct V_16 * V_17 )
{
int V_33 ;
T_1 V_129 ;
T_4 V_120 ;
T_4 V_119 ;
for ( V_129 = 0 ; V_129 < V_100 ; V_129 += 4 ) {
V_119 = F_61 ( & V_99 [ V_129 ] ) ;
if ( ( V_129 + 4 ) <= V_100 )
V_120 = F_61 ( & V_99 [ V_129 + 2 ] ) ;
else
V_120 = 0 ;
V_33 = F_69 ( & V_17 -> V_107 . V_108 . V_71 ,
V_120 ,
V_119 ,
V_38 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return 0 ;
}
static void F_70 ( const struct V_40 * V_42 ,
unsigned char * V_130 ,
T_1 V_131 )
{
V_130 [ 0 ] = V_132 ;
V_130 [ 1 ] = V_127 + V_131 ;
* ( V_133 * ) & V_130 [ 2 ] = F_71 ( V_42 -> V_41 ) ;
}
static int F_72 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_134 ,
T_1 V_135 )
{
int V_33 ;
T_1 V_136 ;
T_1 V_84 ;
if ( ( V_17 -> V_26 & V_137 ) == 0 )
return - V_34 ;
V_33 = F_51 ( V_42 ,
V_17 -> V_107 . V_108 . V_68 ,
& V_84 ) ;
if ( V_33 != 0 )
return V_33 ;
if ( V_17 -> V_26 & V_138 ) {
V_33 = F_55 ( V_42 ,
V_17 ,
& V_134 [ 4 ] ,
V_135 - 4 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_139 && V_33 > 0 && V_33 <= 10 )
V_136 = 14 ;
else
V_136 = 4 + V_33 ;
} else
V_136 = 4 ;
V_134 [ 0 ] = V_53 ;
V_134 [ 1 ] = V_136 ;
V_134 [ 3 ] = V_84 ;
return V_136 ;
}
static int F_73 ( const struct V_40 * V_42 ,
const unsigned char * V_140 ,
struct V_16 * V_17 )
{
int V_33 ;
T_3 V_136 = V_140 [ 1 ] ;
T_1 V_84 ;
V_33 = F_52 ( V_42 , V_140 [ 3 ] , & V_84 ) ;
if ( V_33 != 0 )
return V_33 ;
V_17 -> V_107 . V_108 . V_68 = V_84 ;
V_17 -> V_26 |= V_137 ;
if ( V_136 > 4 ) {
V_33 = F_58 ( V_42 ,
& V_140 [ 4 ] ,
V_136 - 4 ,
V_17 ) ;
if ( V_33 != 0 ) {
F_74 ( V_17 -> V_107 . V_108 . V_71 ) ;
return V_33 ;
}
V_17 -> V_26 |= V_138 ;
}
return 0 ;
}
static int F_75 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_134 ,
T_1 V_135 )
{
int V_33 ;
T_1 V_136 ;
T_1 V_84 ;
if ( ! ( V_17 -> V_26 & V_137 ) )
return - V_34 ;
V_33 = F_51 ( V_42 ,
V_17 -> V_107 . V_108 . V_68 ,
& V_84 ) ;
if ( V_33 != 0 )
return V_33 ;
if ( V_17 -> V_26 & V_138 ) {
V_33 = F_62 ( V_42 ,
V_17 ,
& V_134 [ 4 ] ,
V_135 - 4 ) ;
if ( V_33 < 0 )
return V_33 ;
V_136 = 4 + V_33 ;
} else
V_136 = 4 ;
V_134 [ 0 ] = V_55 ;
V_134 [ 1 ] = V_136 ;
V_134 [ 3 ] = V_84 ;
return V_136 ;
}
static int F_76 ( const struct V_40 * V_42 ,
const unsigned char * V_140 ,
struct V_16 * V_17 )
{
int V_33 ;
T_3 V_136 = V_140 [ 1 ] ;
T_1 V_84 ;
V_33 = F_52 ( V_42 , V_140 [ 3 ] , & V_84 ) ;
if ( V_33 != 0 )
return V_33 ;
V_17 -> V_107 . V_108 . V_68 = V_84 ;
V_17 -> V_26 |= V_137 ;
if ( V_136 > 4 ) {
V_33 = F_64 ( V_42 ,
& V_140 [ 4 ] ,
V_136 - 4 ,
V_17 ) ;
if ( V_33 != 0 ) {
F_74 ( V_17 -> V_107 . V_108 . V_71 ) ;
return V_33 ;
}
V_17 -> V_26 |= V_138 ;
}
return 0 ;
}
static int F_77 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_134 ,
T_1 V_135 )
{
int V_33 ;
T_1 V_136 ;
T_1 V_84 ;
if ( ! ( V_17 -> V_26 & V_137 ) )
return - V_34 ;
V_33 = F_51 ( V_42 ,
V_17 -> V_107 . V_108 . V_68 ,
& V_84 ) ;
if ( V_33 != 0 )
return V_33 ;
if ( V_17 -> V_26 & V_138 ) {
V_33 = F_66 ( V_42 ,
V_17 ,
& V_134 [ 4 ] ,
V_135 - 4 ) ;
if ( V_33 < 0 )
return V_33 ;
V_136 = 4 + V_33 ;
} else
V_136 = 4 ;
V_134 [ 0 ] = V_54 ;
V_134 [ 1 ] = V_136 ;
V_134 [ 3 ] = V_84 ;
return V_136 ;
}
static int F_78 ( const struct V_40 * V_42 ,
const unsigned char * V_140 ,
struct V_16 * V_17 )
{
int V_33 ;
T_3 V_136 = V_140 [ 1 ] ;
T_1 V_84 ;
V_33 = F_52 ( V_42 , V_140 [ 3 ] , & V_84 ) ;
if ( V_33 != 0 )
return V_33 ;
V_17 -> V_107 . V_108 . V_68 = V_84 ;
V_17 -> V_26 |= V_137 ;
if ( V_136 > 4 ) {
V_33 = F_68 ( V_42 ,
& V_140 [ 4 ] ,
V_136 - 4 ,
V_17 ) ;
if ( V_33 != 0 ) {
F_74 ( V_17 -> V_107 . V_108 . V_71 ) ;
return V_33 ;
}
V_17 -> V_26 |= V_138 ;
}
return 0 ;
}
static int F_79 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_134 ,
T_1 V_135 )
{
if ( ! ( V_17 -> V_26 & V_141 ) )
return - V_34 ;
V_134 [ 0 ] = V_57 ;
V_134 [ 1 ] = V_142 ;
* ( T_1 * ) & V_134 [ 2 ] = V_17 -> V_107 . V_143 ;
return V_142 ;
}
static int F_80 ( const struct V_40 * V_42 ,
const unsigned char * V_140 ,
struct V_16 * V_17 )
{
V_17 -> V_107 . V_143 = * ( T_1 * ) & V_140 [ 2 ] ;
V_17 -> V_26 |= V_141 ;
return 0 ;
}
unsigned char * F_81 ( const struct V_144 * V_145 )
{
const struct V_146 * V_147 = F_82 ( V_145 ) ;
unsigned char * V_148 = ( unsigned char * ) & ( F_82 ( V_145 ) [ 1 ] ) ;
int V_149 ;
int V_150 ;
for ( V_149 = V_147 -> V_151 * 4 - sizeof( struct V_146 ) ; V_149 > 0 ; ) {
switch ( V_148 [ 0 ] ) {
case V_132 :
return V_148 ;
case V_152 :
return NULL ;
case V_153 :
V_150 = 1 ;
break;
default:
V_150 = V_148 [ 1 ] ;
}
V_149 -= V_150 ;
V_148 += V_150 ;
}
return NULL ;
}
int F_83 ( const struct V_144 * V_145 , unsigned char * * V_154 )
{
unsigned char * V_155 = * V_154 ;
unsigned char * V_140 ;
unsigned char V_156 ;
unsigned char V_157 = 0 ;
T_3 V_158 ;
T_3 V_136 ;
struct V_40 * V_42 = NULL ;
T_1 V_159 ;
V_158 = V_155 [ 1 ] ;
if ( V_158 < 8 ) {
V_157 = 1 ;
goto V_160;
}
F_44 () ;
V_42 = F_25 ( F_84 ( & V_155 [ 2 ] ) ) ;
if ( ! V_42 ) {
V_157 = 2 ;
goto V_161;
}
V_156 = V_127 ;
V_140 = V_155 + V_156 ;
while ( V_156 < V_158 ) {
for ( V_159 = 0 ; V_42 -> V_52 [ V_159 ] != V_140 [ 0 ] ; )
if ( V_42 -> V_52 [ V_159 ] == V_59 ||
++ V_159 == V_51 ) {
V_157 = V_156 ;
goto V_161;
}
if ( V_156 + 1 == V_158 ) {
V_157 = V_156 ;
goto V_161;
}
V_136 = V_140 [ 1 ] ;
if ( V_136 > ( V_158 - V_156 ) ) {
V_157 = V_156 + 1 ;
goto V_161;
}
switch ( V_140 [ 0 ] ) {
case V_53 :
if ( V_136 < V_162 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
if ( V_163 ) {
if ( F_50 ( V_42 ,
V_140 [ 3 ] ) < 0 ) {
V_157 = V_156 + 3 ;
goto V_161;
}
if ( V_136 > V_162 &&
F_53 ( V_42 ,
& V_140 [ 4 ] ,
V_136 - 4 ) < 0 ) {
V_157 = V_156 + 4 ;
goto V_161;
}
}
break;
case V_55 :
if ( V_136 < V_164 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
if ( F_50 ( V_42 ,
V_140 [ 3 ] ) < 0 ) {
V_157 = V_156 + 3 ;
goto V_161;
}
if ( V_136 > V_164 &&
F_60 ( V_42 ,
& V_140 [ 4 ] ,
V_136 - 4 ) < 0 ) {
V_157 = V_156 + 4 ;
goto V_161;
}
break;
case V_54 :
if ( V_136 < V_128 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
if ( F_50 ( V_42 ,
V_140 [ 3 ] ) < 0 ) {
V_157 = V_156 + 3 ;
goto V_161;
}
if ( V_136 > V_128 &&
F_65 ( V_42 ,
& V_140 [ 4 ] ,
V_136 - 4 ) < 0 ) {
V_157 = V_156 + 4 ;
goto V_161;
}
break;
case V_57 :
if ( ! V_145 || ! ( V_145 -> V_165 -> V_26 & V_166 ) ) {
V_157 = V_156 ;
goto V_161;
}
if ( V_136 != V_142 ) {
V_157 = V_156 + 1 ;
goto V_161;
}
break;
default:
V_157 = V_156 ;
goto V_161;
}
V_140 += V_136 ;
V_156 += V_136 ;
}
V_161:
F_46 () ;
V_160:
* V_154 = V_155 + V_157 ;
return V_157 ;
}
void F_85 ( struct V_144 * V_145 , int error , T_1 V_167 )
{
if ( F_82 ( V_145 ) -> V_168 == V_169 || error != - V_170 )
return;
if ( V_167 )
F_86 ( V_145 , V_171 , V_172 , 0 ) ;
else
F_86 ( V_145 , V_171 , V_173 , 0 ) ;
}
static int F_87 ( unsigned char * V_130 , T_1 V_174 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 ;
T_1 V_6 ;
if ( V_174 <= V_127 )
return - V_109 ;
V_6 = 0 ;
do {
memset ( V_130 , 0 , V_174 ) ;
switch ( V_42 -> V_52 [ V_6 ] ) {
case V_53 :
V_33 = F_72 ( V_42 ,
V_17 ,
& V_130 [ V_127 ] ,
V_174 - V_127 ) ;
break;
case V_55 :
V_33 = F_75 ( V_42 ,
V_17 ,
& V_130 [ V_127 ] ,
V_174 - V_127 ) ;
break;
case V_54 :
V_33 = F_77 ( V_42 ,
V_17 ,
& V_130 [ V_127 ] ,
V_174 - V_127 ) ;
break;
case V_57 :
V_33 = F_79 ( V_42 ,
V_17 ,
& V_130 [ V_127 ] ,
V_174 - V_127 ) ;
break;
default:
return - V_34 ;
}
V_6 ++ ;
} while ( V_33 < 0 &&
V_6 < V_51 &&
V_42 -> V_52 [ V_6 ] != V_59 );
if ( V_33 < 0 )
return V_33 ;
F_70 ( V_42 , V_130 , V_33 ) ;
return V_127 + V_33 ;
}
int F_88 ( struct V_175 * V_176 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 = - V_34 ;
unsigned char * V_130 = NULL ;
T_1 V_174 ;
T_1 V_158 ;
struct V_177 * V_178 , * V_155 = NULL ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
if ( ! V_176 )
return 0 ;
V_174 = V_126 ;
V_130 = F_89 ( V_174 , V_38 ) ;
if ( ! V_130 ) {
V_33 = - V_11 ;
goto V_183;
}
V_33 = F_87 ( V_130 , V_174 , V_42 , V_17 ) ;
if ( V_33 < 0 )
goto V_183;
V_174 = V_33 ;
V_158 = ( V_174 + 3 ) & ~ 3 ;
V_155 = F_21 ( sizeof( * V_155 ) + V_158 , V_38 ) ;
if ( ! V_155 ) {
V_33 = - V_11 ;
goto V_183;
}
memcpy ( V_155 -> V_155 . V_184 , V_130 , V_174 ) ;
V_155 -> V_155 . V_149 = V_158 ;
V_155 -> V_155 . V_69 = sizeof( struct V_146 ) ;
F_3 ( V_130 ) ;
V_130 = NULL ;
V_180 = F_90 ( V_176 ) ;
V_178 = F_91 ( V_180 -> V_185 ,
F_92 ( V_176 ) ) ;
if ( V_180 -> V_186 ) {
V_182 = F_93 ( V_176 ) ;
if ( V_178 )
V_182 -> V_187 -= V_178 -> V_155 . V_149 ;
V_182 -> V_187 += V_155 -> V_155 . V_149 ;
V_182 -> V_188 ( V_176 , V_182 -> V_189 ) ;
}
F_94 ( V_180 -> V_185 , V_155 ) ;
if ( V_178 )
F_95 ( V_178 , V_73 ) ;
return 0 ;
V_183:
F_3 ( V_130 ) ;
F_3 ( V_155 ) ;
return V_33 ;
}
int F_96 ( struct V_190 * V_191 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 = - V_34 ;
unsigned char * V_130 = NULL ;
T_1 V_174 ;
T_1 V_158 ;
struct V_177 * V_155 = NULL ;
struct V_192 * V_193 ;
V_174 = V_126 ;
V_130 = F_89 ( V_174 , V_38 ) ;
if ( ! V_130 ) {
V_33 = - V_11 ;
goto V_194;
}
V_33 = F_87 ( V_130 , V_174 , V_42 , V_17 ) ;
if ( V_33 < 0 )
goto V_194;
V_174 = V_33 ;
V_158 = ( V_174 + 3 ) & ~ 3 ;
V_155 = F_21 ( sizeof( * V_155 ) + V_158 , V_38 ) ;
if ( ! V_155 ) {
V_33 = - V_11 ;
goto V_194;
}
memcpy ( V_155 -> V_155 . V_184 , V_130 , V_174 ) ;
V_155 -> V_155 . V_149 = V_158 ;
V_155 -> V_155 . V_69 = sizeof( struct V_146 ) ;
F_3 ( V_130 ) ;
V_130 = NULL ;
V_193 = F_97 ( V_191 ) ;
V_155 = F_98 ( ( V_195 struct V_177 * * ) & V_193 -> V_196 , V_155 ) ;
if ( V_155 )
F_95 ( V_155 , V_73 ) ;
return 0 ;
V_194:
F_3 ( V_130 ) ;
F_3 ( V_155 ) ;
return V_33 ;
}
static int F_99 ( struct V_177 T_5 * * V_197 )
{
struct V_177 * V_155 = F_91 ( * V_197 , 1 ) ;
int V_198 = 0 ;
if ( ! V_155 || V_155 -> V_155 . V_69 == 0 )
return 0 ;
if ( V_155 -> V_155 . V_199 || V_155 -> V_155 . V_200 || V_155 -> V_155 . V_201 || V_155 -> V_155 . V_202 ) {
T_3 V_203 ;
T_3 V_204 ;
unsigned char * V_32 ;
int V_6 ;
int V_205 ;
V_204 = V_155 -> V_155 . V_69 - sizeof( struct V_146 ) ;
V_32 = & V_155 -> V_155 . V_184 [ V_204 ] ;
V_203 = V_32 [ 1 ] ;
if ( V_155 -> V_155 . V_199 > V_155 -> V_155 . V_69 )
V_155 -> V_155 . V_199 -= V_203 ;
if ( V_155 -> V_155 . V_200 > V_155 -> V_155 . V_69 )
V_155 -> V_155 . V_200 -= V_203 ;
if ( V_155 -> V_155 . V_201 > V_155 -> V_155 . V_69 )
V_155 -> V_155 . V_201 -= V_203 ;
if ( V_155 -> V_155 . V_202 > V_155 -> V_155 . V_69 )
V_155 -> V_155 . V_202 -= V_203 ;
V_155 -> V_155 . V_69 = 0 ;
memmove ( V_32 , V_32 + V_203 ,
V_155 -> V_155 . V_149 - V_204 - V_203 ) ;
V_6 = 0 ;
V_205 = 0 ;
while ( V_6 < V_155 -> V_155 . V_149 )
if ( V_155 -> V_155 . V_184 [ V_6 ] != V_206 ) {
V_6 += V_155 -> V_155 . V_184 [ V_6 + 1 ] ;
V_205 = V_6 ;
} else
V_6 ++ ;
V_198 = V_155 -> V_155 . V_149 ;
V_155 -> V_155 . V_149 = ( V_205 + 3 ) & ~ 3 ;
V_198 -= V_155 -> V_155 . V_149 ;
} else {
* V_197 = NULL ;
V_198 = V_155 -> V_155 . V_149 ;
F_95 ( V_155 , V_73 ) ;
}
return V_198 ;
}
void F_100 ( struct V_175 * V_176 )
{
struct V_179 * V_180 ;
int V_198 ;
V_180 = F_90 ( V_176 ) ;
V_198 = F_99 ( & V_180 -> V_185 ) ;
if ( V_180 -> V_186 && V_198 > 0 ) {
struct V_181 * V_182 = F_93 ( V_176 ) ;
V_182 -> V_187 -= V_198 ;
V_182 -> V_188 ( V_176 , V_182 -> V_189 ) ;
}
}
void F_101 ( struct V_190 * V_191 )
{
F_99 ( & F_97 ( V_191 ) -> V_196 ) ;
}
int F_102 ( const unsigned char * V_69 ,
struct V_16 * V_17 )
{
int V_33 = - V_207 ;
T_1 V_41 ;
struct V_40 * V_42 ;
if ( F_15 ( V_69 , V_69 [ 1 ] , V_17 ) == 0 )
return 0 ;
V_41 = F_84 ( & V_69 [ 2 ] ) ;
F_44 () ;
V_42 = F_25 ( V_41 ) ;
if ( ! V_42 )
goto V_208;
switch ( V_69 [ 6 ] ) {
case V_53 :
V_33 = F_73 ( V_42 , & V_69 [ 6 ] , V_17 ) ;
break;
case V_55 :
V_33 = F_76 ( V_42 , & V_69 [ 6 ] , V_17 ) ;
break;
case V_54 :
V_33 = F_78 ( V_42 , & V_69 [ 6 ] , V_17 ) ;
break;
case V_57 :
V_33 = F_80 ( V_42 , & V_69 [ 6 ] , V_17 ) ;
break;
}
if ( V_33 == 0 )
V_17 -> type = V_28 ;
V_208:
F_46 () ;
return V_33 ;
}
int F_103 ( struct V_175 * V_176 , struct V_16 * V_17 )
{
struct V_177 * V_155 ;
int V_209 = - V_207 ;
F_44 () ;
V_155 = F_104 ( F_90 ( V_176 ) -> V_185 ) ;
if ( V_155 && V_155 -> V_155 . V_69 )
V_209 = F_102 ( V_155 -> V_155 . V_184 +
V_155 -> V_155 . V_69 -
sizeof( struct V_146 ) ,
V_17 ) ;
F_46 () ;
return V_209 ;
}
int F_105 ( struct V_144 * V_145 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 ;
struct V_146 * V_147 ;
struct V_210 * V_155 = & F_106 ( V_145 ) -> V_155 ;
unsigned char V_130 [ V_126 ] ;
T_1 V_174 = V_126 ;
T_1 V_158 ;
int V_211 ;
V_33 = F_87 ( V_130 , V_174 , V_42 , V_17 ) ;
if ( V_33 < 0 )
return V_33 ;
V_174 = V_33 ;
V_158 = ( V_174 + 3 ) & ~ 3 ;
V_211 = V_158 - V_155 -> V_149 ;
V_33 = F_107 ( V_145 , F_108 ( V_145 ) + V_211 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_211 > 0 ) {
V_147 = F_82 ( V_145 ) ;
F_109 ( V_145 , V_211 ) ;
memmove ( ( char * ) V_147 - V_211 , V_147 , V_147 -> V_151 << 2 ) ;
F_110 ( V_145 ) ;
V_147 = F_82 ( V_145 ) ;
} else if ( V_211 < 0 ) {
V_147 = F_82 ( V_145 ) ;
memset ( V_147 + 1 , V_206 , V_155 -> V_149 ) ;
} else
V_147 = F_82 ( V_145 ) ;
if ( V_155 -> V_149 > 0 )
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_149 = V_158 ;
V_155 -> V_69 = sizeof( struct V_146 ) ;
V_155 -> V_212 = 1 ;
memcpy ( V_147 + 1 , V_130 , V_174 ) ;
if ( V_158 > V_174 )
memset ( ( char * ) ( V_147 + 1 ) + V_174 , 0 , V_158 - V_174 ) ;
if ( V_211 != 0 ) {
V_147 -> V_151 = 5 + ( V_158 >> 2 ) ;
V_147 -> V_213 = F_63 ( V_145 -> V_131 ) ;
}
F_111 ( V_147 ) ;
return 0 ;
}
int F_112 ( struct V_144 * V_145 )
{
int V_33 ;
struct V_146 * V_147 ;
struct V_210 * V_155 = & F_106 ( V_145 ) -> V_155 ;
unsigned char * V_32 ;
if ( V_155 -> V_69 == 0 )
return 0 ;
V_33 = F_107 ( V_145 , F_108 ( V_145 ) ) ;
if ( V_33 < 0 )
return V_33 ;
V_147 = F_82 ( V_145 ) ;
V_32 = ( unsigned char * ) V_147 + V_155 -> V_69 ;
memset ( V_32 , V_153 , V_32 [ 1 ] ) ;
V_155 -> V_69 = 0 ;
V_155 -> V_212 = 1 ;
F_111 ( V_147 ) ;
return 0 ;
}
static int T_2 F_113 ( void )
{
int V_33 ;
V_33 = F_6 () ;
if ( V_33 != 0 )
F_114 ( L_7 ,
V_33 ) ;
return 0 ;
}
