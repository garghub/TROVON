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
static void F_10 ( void )
{
struct V_1 * V_2 , * V_15 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
F_11 ( & V_7 [ V_6 ] . V_12 ) ;
F_12 (entry,
tmp_entry,
&calipso_cache[iter].list, list) {
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
F_16 (entry, &calipso_cache[bkt].list, list) {
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
static int F_20 ( const unsigned char * V_32 ,
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
V_2 -> V_4 = F_22 ( V_32 + 2 , V_36 , V_38 ) ;
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
F_26 (iter, &calipso_doi_list, list)
if ( V_6 -> V_41 == V_41 && F_27 ( & V_6 -> V_24 ) )
return V_6 ;
return NULL ;
}
static int F_28 ( struct V_40 * V_42 ,
struct V_43 * V_44 )
{
int V_33 = - V_45 ;
T_1 V_41 ;
T_1 V_46 ;
struct V_47 * V_48 ;
V_41 = V_42 -> V_41 ;
V_46 = V_42 -> type ;
if ( V_42 -> V_41 == V_49 )
goto V_50;
F_29 ( & V_42 -> V_24 , 1 ) ;
F_30 ( & V_51 ) ;
if ( F_25 ( V_42 -> V_41 ) ) {
F_31 ( & V_51 ) ;
V_33 = - V_52 ;
goto V_50;
}
F_32 ( & V_42 -> V_14 , & V_53 ) ;
F_31 ( & V_51 ) ;
V_33 = 0 ;
V_50:
V_48 = F_33 ( V_54 , V_44 ) ;
if ( V_48 ) {
const char * V_55 ;
switch ( V_46 ) {
case V_56 :
V_55 = L_1 ;
break;
default:
V_55 = L_2 ;
}
F_34 ( V_48 ,
L_3 ,
V_41 , V_55 , V_33 == 0 ? 1 : 0 ) ;
F_35 ( V_48 ) ;
}
return V_33 ;
}
static void F_36 ( struct V_40 * V_42 )
{
F_3 ( V_42 ) ;
}
static void F_37 ( struct V_57 * V_2 )
{
struct V_40 * V_42 ;
V_42 = F_38 ( V_2 , struct V_40 , V_58 ) ;
F_36 ( V_42 ) ;
}
static int F_39 ( T_1 V_41 , struct V_43 * V_44 )
{
int V_33 ;
struct V_40 * V_42 ;
struct V_47 * V_48 ;
F_30 ( & V_51 ) ;
V_42 = F_25 ( V_41 ) ;
if ( ! V_42 ) {
F_31 ( & V_51 ) ;
V_33 = - V_22 ;
goto V_59;
}
if ( ! F_40 ( & V_42 -> V_24 ) ) {
F_31 ( & V_51 ) ;
V_33 = - V_60 ;
goto V_59;
}
F_41 ( & V_42 -> V_14 ) ;
F_31 ( & V_51 ) ;
F_42 ( & V_42 -> V_58 , F_37 ) ;
V_33 = 0 ;
V_59:
V_48 = F_33 ( V_61 , V_44 ) ;
if ( V_48 ) {
F_34 ( V_48 ,
L_4 ,
V_41 , V_33 == 0 ? 1 : 0 ) ;
F_35 ( V_48 ) ;
}
return V_33 ;
}
static struct V_40 * F_43 ( T_1 V_41 )
{
struct V_40 * V_42 ;
F_44 () ;
V_42 = F_25 ( V_41 ) ;
if ( ! V_42 )
goto V_62;
if ( ! F_45 ( & V_42 -> V_24 ) )
V_42 = NULL ;
V_62:
F_46 () ;
return V_42 ;
}
static void F_47 ( struct V_40 * V_42 )
{
if ( ! V_42 )
return;
if ( ! F_40 ( & V_42 -> V_24 ) )
return;
F_30 ( & V_51 ) ;
F_41 ( & V_42 -> V_14 ) ;
F_31 ( & V_51 ) ;
F_42 ( & V_42 -> V_58 , F_37 ) ;
}
static int F_48 ( T_1 * V_63 ,
int (* F_49)( struct V_40 * V_42 ,
void * V_64 ) ,
void * V_65 )
{
int V_33 = - V_22 ;
T_1 V_66 = 0 ;
struct V_40 * V_67 ;
F_44 () ;
F_26 (iter_doi, &calipso_doi_list, list)
if ( F_27 ( & V_67 -> V_24 ) > 0 ) {
if ( V_66 ++ < * V_63 )
continue;
V_33 = F_49 ( V_67 , V_65 ) ;
if ( V_33 < 0 ) {
V_66 -- ;
goto V_68;
}
}
V_68:
F_46 () ;
* V_63 = V_66 ;
return V_33 ;
}
bool F_50 ( const struct V_69 * V_70 , const unsigned char * V_71 )
{
struct V_40 * V_42 ;
bool V_33 ;
T_3 V_72 , V_73 = V_71 [ 1 ] + 2 ;
static const T_4 V_74 [ 2 ] ;
V_72 = F_51 ( 0xffff , V_71 , 8 ) ;
V_72 = F_51 ( V_72 , V_74 , sizeof( V_74 ) ) ;
if ( V_73 > 10 )
V_72 = F_51 ( V_72 , V_71 + 10 , V_73 - 10 ) ;
V_72 = ~ V_72 ;
if ( V_71 [ 8 ] != ( V_72 & 0xff ) || V_71 [ 9 ] != ( ( V_72 >> 8 ) & 0xff ) )
return false ;
F_44 () ;
V_42 = F_25 ( F_52 ( V_71 + 2 ) ) ;
V_33 = ! ! V_42 ;
F_46 () ;
return V_33 ;
}
static int F_53 ( const struct V_40 * V_42 ,
const struct V_16 * V_17 ,
unsigned char * V_75 ,
T_1 V_76 )
{
int V_77 = - 1 ;
T_1 V_78 = 0 ;
T_1 V_79 = V_76 * 8 ;
for (; ; ) {
V_77 = F_54 ( V_17 -> V_80 . V_81 . V_82 ,
V_77 + 1 ) ;
if ( V_77 < 0 )
break;
if ( V_77 >= V_79 )
return - V_83 ;
F_55 ( V_75 , V_77 , 1 ) ;
if ( V_77 > V_78 )
V_78 = V_77 ;
}
return ( V_78 / 32 + 1 ) * 4 ;
}
static int F_56 ( const struct V_40 * V_42 ,
const unsigned char * V_75 ,
T_1 V_76 ,
struct V_16 * V_17 )
{
int V_33 ;
int V_77 = - 1 ;
T_1 V_79 = V_76 * 8 ;
for (; ; ) {
V_77 = F_57 ( V_75 ,
V_79 ,
V_77 + 1 ,
1 ) ;
if ( V_77 < 0 ) {
if ( V_77 == - 2 )
return - V_84 ;
return 0 ;
}
V_33 = F_58 ( & V_17 -> V_80 . V_81 . V_82 ,
V_77 ,
V_38 ) ;
if ( V_33 != 0 )
return V_33 ;
}
return - V_45 ;
}
static int F_59 ( unsigned char * V_85 , unsigned int V_86 ,
unsigned int V_87 )
{
if ( F_60 ( V_87 >= 8 ) )
return - V_45 ;
switch ( V_87 ) {
case 0 :
break;
case 1 :
V_85 [ V_86 ] = V_88 ;
break;
default:
V_85 [ V_86 ] = V_89 ;
V_85 [ V_86 + 1 ] = V_87 - 2 ;
if ( V_87 > 2 )
memset ( V_85 + V_86 + 2 , 0 , V_87 - 2 ) ;
break;
}
return 0 ;
}
static int F_61 ( unsigned char * V_85 , T_1 V_90 , T_1 V_91 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 ;
T_1 V_73 , V_92 ;
T_3 V_72 ;
static const unsigned char V_93 [ 4 ] = { 2 , 1 , 0 , 3 } ;
unsigned char * V_94 ;
V_92 = V_93 [ V_90 & 3 ] ;
if ( V_91 <= V_90 + V_92 + V_95 )
return - V_83 ;
if ( ( V_17 -> V_26 & V_96 ) == 0 )
return - V_34 ;
V_73 = V_95 ;
if ( V_17 -> V_26 & V_97 ) {
V_33 = F_53 ( V_42 ,
V_17 ,
V_85 + V_90 + V_92 + V_73 ,
V_91 - V_90 - V_92 - V_73 ) ;
if ( V_33 < 0 )
return V_33 ;
V_73 += V_33 ;
}
F_59 ( V_85 , V_90 , V_92 ) ;
V_94 = V_85 + V_90 + V_92 ;
V_94 [ 0 ] = V_98 ;
V_94 [ 1 ] = V_73 - 2 ;
* ( V_99 * ) ( V_94 + 2 ) = F_62 ( V_42 -> V_41 ) ;
V_94 [ 6 ] = ( V_73 - V_95 ) / 4 ;
V_94 [ 7 ] = V_17 -> V_80 . V_81 . V_100 ,
V_72 = ~ F_51 ( 0xffff , V_94 , V_73 ) ;
V_94 [ 8 ] = V_72 & 0xff ;
V_94 [ 9 ] = ( V_72 >> 8 ) & 0xff ;
return V_92 + V_73 ;
}
static int F_63 ( struct V_101 * V_102 , struct V_103 * V_104 )
{
struct V_105 * V_106 = F_64 ( F_65 ( V_102 ) ) , * V_107 ;
V_107 = F_66 ( V_102 , V_106 , V_108 ,
V_104 , V_104 ? F_67 ( V_104 ) : 0 ) ;
F_68 ( V_106 ) ;
if ( F_69 ( V_107 ) )
return F_70 ( V_107 ) ;
V_107 = F_71 ( V_102 , V_107 ) ;
if ( V_107 ) {
F_72 ( V_107 -> V_109 , & V_102 -> V_110 ) ;
F_68 ( V_107 ) ;
}
return 0 ;
}
static int F_73 ( struct V_103 * V_111 , unsigned int V_86 )
{
unsigned char * V_112 = ( unsigned char * ) V_111 ;
unsigned int V_113 = F_67 ( V_111 ) , V_114 ;
if ( V_86 < sizeof( * V_111 ) || V_86 >= V_113 )
return - V_45 ;
if ( V_112 [ V_86 ] == V_88 )
return 1 ;
if ( V_86 + 1 >= V_113 )
return - V_45 ;
V_114 = V_112 [ V_86 + 1 ] + 2 ;
if ( V_86 + V_114 > V_113 )
return - V_45 ;
return V_114 ;
}
static int F_74 ( struct V_103 * V_104 , unsigned int * V_90 ,
unsigned int * V_115 )
{
int V_33 = - V_22 , V_114 ;
unsigned int V_113 , V_86 , V_116 = 0 , V_117 = 0 ;
unsigned char * V_111 = ( unsigned char * ) V_104 ;
V_113 = F_67 ( V_104 ) ;
V_86 = sizeof( * V_104 ) ;
while ( V_86 < V_113 ) {
V_114 = F_73 ( V_104 , V_86 ) ;
if ( V_114 < 0 )
return V_114 ;
switch ( V_111 [ V_86 ] ) {
case V_88 :
case V_89 :
if ( V_117 )
V_117 = V_86 ;
break;
case V_98 :
V_33 = 0 ;
V_117 = V_86 ;
break;
default:
if ( V_117 == 0 )
V_116 = V_86 ;
else
goto V_118;
}
V_86 += V_114 ;
}
V_118:
if ( V_116 )
* V_90 = V_116 + F_73 ( V_104 , V_116 ) ;
else
* V_90 = sizeof( * V_104 ) ;
if ( V_117 )
* V_115 = V_117 + F_73 ( V_104 , V_117 ) ;
else
* V_115 = V_113 ;
return V_33 ;
}
static struct V_103 *
F_75 ( struct V_103 * V_104 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
unsigned int V_90 , V_115 , V_91 , V_92 , V_119 ;
struct V_103 * V_120 ;
int V_33 ;
if ( V_104 ) {
V_119 = F_67 ( V_104 ) ;
V_33 = F_74 ( V_104 , & V_90 , & V_115 ) ;
if ( V_33 && V_33 != - V_22 )
return F_76 ( V_33 ) ;
} else {
V_119 = 0 ;
V_90 = sizeof( * V_104 ) ;
V_115 = 0 ;
}
V_91 = V_119 + V_90 - V_115 + V_121 ;
V_120 = F_21 ( V_91 , V_38 ) ;
if ( ! V_120 )
return F_76 ( - V_11 ) ;
if ( V_90 > sizeof( * V_104 ) )
memcpy ( V_120 , V_104 , V_90 ) ;
V_33 = F_61 ( ( unsigned char * ) V_120 , V_90 , V_91 , V_42 ,
V_17 ) ;
if ( V_33 < 0 ) {
F_3 ( V_120 ) ;
return F_76 ( V_33 ) ;
}
V_91 = V_90 + V_33 ;
V_92 = ( ( V_91 & 4 ) + ( V_115 & 7 ) ) & 7 ;
F_59 ( ( unsigned char * ) V_120 , V_91 , V_92 ) ;
V_91 += V_92 ;
if ( V_115 != V_119 ) {
memcpy ( ( char * ) V_120 + V_91 , ( char * ) V_104 + V_115 , V_119 - V_115 ) ;
V_91 += V_119 - V_115 ;
}
V_120 -> V_122 = 0 ;
V_120 -> V_123 = V_91 / 8 - 1 ;
return V_120 ;
}
static int F_77 ( struct V_103 * V_104 ,
struct V_103 * * V_120 )
{
int V_33 ;
unsigned int V_90 , V_115 , V_124 , V_92 , V_119 ;
V_33 = F_74 ( V_104 , & V_90 , & V_115 ) ;
if ( V_33 )
return V_33 ;
V_119 = F_67 ( V_104 ) ;
if ( V_90 == sizeof( * V_104 ) && V_115 == V_119 ) {
* V_120 = NULL ;
return 0 ;
}
V_124 = ( V_115 - V_90 ) & ~ 7 ;
* V_120 = F_21 ( V_119 - V_124 , V_38 ) ;
if ( ! * V_120 )
return - V_11 ;
memcpy ( * V_120 , V_104 , V_90 ) ;
( * V_120 ) -> V_123 -= V_124 / 8 ;
V_92 = ( V_115 - V_90 ) & 7 ;
F_59 ( ( unsigned char * ) * V_120 , V_90 , V_92 ) ;
if ( V_115 != V_119 )
memcpy ( ( char * ) * V_120 + V_90 + V_92 , ( char * ) V_104 + V_115 ,
V_119 - V_115 ) ;
return 0 ;
}
static int F_78 ( const unsigned char * V_94 ,
struct V_16 * V_17 )
{
int V_33 = - V_125 ;
T_1 V_41 , V_73 = V_94 [ 1 ] , V_126 = V_94 [ 6 ] * 4 ;
struct V_40 * V_42 ;
if ( V_126 + 8 > V_73 )
return - V_45 ;
if ( F_15 ( V_94 + 2 , V_94 [ 1 ] , V_17 ) == 0 )
return 0 ;
V_41 = F_52 ( V_94 + 2 ) ;
F_44 () ;
V_42 = F_25 ( V_41 ) ;
if ( ! V_42 )
goto V_127;
V_17 -> V_80 . V_81 . V_100 = V_94 [ 7 ] ;
V_17 -> V_26 |= V_96 ;
if ( V_126 ) {
V_33 = F_56 ( V_42 ,
V_94 + 10 ,
V_126 ,
V_17 ) ;
if ( V_33 != 0 ) {
F_79 ( V_17 -> V_80 . V_81 . V_82 ) ;
goto V_127;
}
V_17 -> V_26 |= V_97 ;
}
V_17 -> type = V_28 ;
V_127:
F_46 () ;
return V_33 ;
}
static int F_80 ( struct V_101 * V_102 ,
struct V_16 * V_17 )
{
struct V_103 * V_104 ;
int V_113 , V_73 , V_33 = - V_125 , V_86 ;
unsigned char * V_111 ;
struct V_105 * V_107 = F_64 ( F_65 ( V_102 ) ) ;
if ( ! V_107 || ! V_107 -> V_128 )
goto V_129;
V_104 = V_107 -> V_128 ;
V_111 = ( unsigned char * ) V_104 ;
V_113 = F_67 ( V_104 ) ;
V_86 = sizeof( * V_104 ) ;
while ( V_86 < V_113 ) {
V_73 = F_73 ( V_104 , V_86 ) ;
if ( V_73 < 0 ) {
V_33 = V_73 ;
goto V_129;
}
switch ( V_111 [ V_86 ] ) {
case V_98 :
if ( V_73 < V_95 )
V_33 = - V_45 ;
else
V_33 = F_78 ( & V_111 [ V_86 ] ,
V_17 ) ;
goto V_129;
default:
V_86 += V_73 ;
break;
}
}
V_129:
F_68 ( V_107 ) ;
return V_33 ;
}
static int F_81 ( struct V_101 * V_102 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 ;
struct V_103 * V_106 , * V_120 ;
struct V_105 * V_107 = F_64 ( F_65 ( V_102 ) ) ;
V_106 = NULL ;
if ( V_107 )
V_106 = V_107 -> V_128 ;
V_120 = F_75 ( V_106 , V_42 , V_17 ) ;
F_68 ( V_107 ) ;
if ( F_69 ( V_120 ) )
return F_70 ( V_120 ) ;
V_33 = F_63 ( V_102 , V_120 ) ;
F_3 ( V_120 ) ;
return V_33 ;
}
static void F_82 ( struct V_101 * V_102 )
{
struct V_103 * V_130 ;
struct V_105 * V_107 = F_64 ( F_65 ( V_102 ) ) ;
if ( ! V_107 || ! V_107 -> V_128 )
goto V_129;
if ( F_77 ( V_107 -> V_128 , & V_130 ) )
goto V_129;
F_63 ( V_102 , V_130 ) ;
F_3 ( V_130 ) ;
V_129:
F_68 ( V_107 ) ;
}
static int F_83 ( struct V_131 * V_132 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
struct V_105 * V_107 ;
struct V_133 * V_134 = F_84 ( V_132 ) ;
struct V_103 * V_106 , * V_120 ;
struct V_101 * V_102 = F_85 ( F_86 ( V_132 ) ) ;
if ( V_134 -> V_135 && V_134 -> V_135 -> V_128 )
V_106 = V_134 -> V_135 -> V_128 ;
else
V_106 = NULL ;
V_120 = F_75 ( V_106 , V_42 , V_17 ) ;
if ( F_69 ( V_120 ) )
return F_70 ( V_120 ) ;
V_107 = F_66 ( V_102 , V_134 -> V_135 , V_108 ,
V_120 , V_120 ? F_67 ( V_120 ) : 0 ) ;
F_3 ( V_120 ) ;
if ( F_69 ( V_107 ) )
return F_70 ( V_107 ) ;
V_107 = F_87 ( & V_134 -> V_135 , V_107 ) ;
if ( V_107 ) {
F_72 ( V_107 -> V_109 , & V_102 -> V_110 ) ;
F_68 ( V_107 ) ;
}
return 0 ;
}
static void F_88 ( struct V_131 * V_132 )
{
struct V_133 * V_134 = F_84 ( V_132 ) ;
struct V_103 * V_120 ;
struct V_105 * V_107 ;
struct V_101 * V_102 = F_85 ( F_86 ( V_132 ) ) ;
if ( ! V_134 -> V_135 || ! V_134 -> V_135 -> V_128 )
return;
if ( F_77 ( V_134 -> V_135 -> V_128 , & V_120 ) )
return;
V_107 = F_66 ( V_102 , V_134 -> V_135 , V_108 ,
V_120 , V_120 ? F_67 ( V_120 ) : 0 ) ;
if ( ! F_69 ( V_107 ) ) {
V_107 = F_87 ( & V_134 -> V_135 , V_107 ) ;
if ( V_107 ) {
F_72 ( V_107 -> V_109 , & V_102 -> V_110 ) ;
F_68 ( V_107 ) ;
}
}
F_3 ( V_120 ) ;
}
static unsigned char * F_89 ( const struct V_69 * V_70 )
{
const struct V_136 * V_137 = F_90 ( V_70 ) ;
int V_86 ;
if ( V_137 -> V_122 != V_138 )
return NULL ;
V_86 = F_91 ( V_70 , sizeof( * V_137 ) , V_98 ) ;
if ( V_86 >= 0 )
return ( unsigned char * ) V_137 + V_86 ;
return NULL ;
}
static int F_92 ( struct V_69 * V_70 ,
const struct V_40 * V_42 ,
const struct V_16 * V_17 )
{
int V_33 ;
struct V_136 * V_137 ;
struct V_103 * V_104 ;
unsigned char V_85 [ V_139 ] ;
int V_140 , V_141 , V_92 , V_142 ;
unsigned int V_90 , V_115 ;
V_137 = F_90 ( V_70 ) ;
if ( V_137 -> V_122 == V_138 ) {
V_104 = (struct V_103 * ) ( V_137 + 1 ) ;
V_33 = F_74 ( V_104 , & V_90 , & V_115 ) ;
if ( V_33 && V_33 != - V_22 )
return V_33 ;
} else {
V_90 = 0 ;
V_115 = 0 ;
}
memset ( V_85 , 0 , sizeof( V_85 ) ) ;
V_33 = F_61 ( V_85 , V_90 & 3 , sizeof( V_85 ) , V_42 , V_17 ) ;
if ( V_33 < 0 )
return V_33 ;
V_141 = V_90 + V_33 ;
V_92 = ( ( V_141 & 4 ) + ( V_115 & 7 ) ) & 7 ;
V_140 = V_141 - ( int ) V_115 + V_92 ;
V_33 = F_93 ( V_70 , F_94 ( V_70 ) + V_140 ) ;
if ( V_33 < 0 )
return V_33 ;
V_137 = F_90 ( V_70 ) ;
if ( V_140 ) {
if ( V_140 > 0 )
F_95 ( V_70 , V_140 ) ;
else
F_96 ( V_70 , - V_140 ) ;
memmove ( ( char * ) V_137 - V_140 , V_137 ,
sizeof( * V_137 ) + V_90 ) ;
F_97 ( V_70 ) ;
V_137 = F_90 ( V_70 ) ;
V_142 = F_98 ( V_137 -> V_143 ) ;
V_137 -> V_143 = F_99 ( V_142 + V_140 ) ;
}
V_104 = (struct V_103 * ) ( V_137 + 1 ) ;
if ( V_90 == 0 ) {
struct V_103 * V_130 = (struct V_103 * ) V_85 ;
V_130 -> V_122 = V_137 -> V_122 ;
V_130 -> V_123 = V_140 / 8 - 1 ;
V_137 -> V_122 = V_138 ;
} else {
V_104 -> V_123 += V_140 / 8 ;
}
memcpy ( ( char * ) V_104 + V_90 , V_85 + ( V_90 & 3 ) , V_141 - V_90 ) ;
F_59 ( ( unsigned char * ) V_104 , V_141 , V_92 ) ;
return 0 ;
}
static int F_100 ( struct V_69 * V_70 )
{
int V_33 ;
struct V_136 * V_137 ;
struct V_103 * V_144 ;
T_1 V_145 , V_90 = 0 , V_115 = 0 , V_124 , V_13 , V_92 ;
if ( ! F_89 ( V_70 ) )
return 0 ;
V_33 = F_93 ( V_70 , F_94 ( V_70 ) ) ;
if ( V_33 < 0 )
return V_33 ;
V_137 = F_90 ( V_70 ) ;
V_144 = (struct V_103 * ) ( V_137 + 1 ) ;
V_145 = F_67 ( V_144 ) ;
V_33 = F_74 ( V_144 , & V_90 , & V_115 ) ;
if ( V_33 )
return V_33 ;
if ( V_90 == sizeof( * V_144 ) && V_115 == V_145 ) {
V_124 = V_145 ;
V_13 = sizeof( * V_137 ) ;
V_137 -> V_122 = V_144 -> V_122 ;
} else {
V_124 = ( V_115 - V_90 ) & ~ 7 ;
if ( V_124 )
V_144 -> V_123 -= V_124 / 8 ;
V_92 = ( V_115 - V_90 ) & 7 ;
V_13 = sizeof( * V_137 ) + V_90 + V_92 ;
F_59 ( ( unsigned char * ) V_144 , V_90 , V_92 ) ;
}
if ( V_124 ) {
F_96 ( V_70 , V_124 ) ;
memmove ( ( char * ) V_137 + V_124 , V_137 , V_13 ) ;
F_97 ( V_70 ) ;
}
return 0 ;
}
int T_2 F_101 ( void )
{
int V_33 ;
V_33 = F_6 () ;
if ( ! V_33 )
F_102 ( & V_146 ) ;
return V_33 ;
}
void F_103 ( void )
{
F_102 ( NULL ) ;
F_10 () ;
F_3 ( V_7 ) ;
}
