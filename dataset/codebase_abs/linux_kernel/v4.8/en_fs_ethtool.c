static void F_1 ( struct V_1 * V_2 )
{
if ( ! -- V_2 -> V_3 ) {
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
}
static struct V_1 * F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
int V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_12 * V_4 ;
int V_13 ;
int V_14 ;
int V_15 ;
switch ( V_8 -> V_16 & ~ ( V_17 | V_18 ) ) {
case V_19 :
case V_20 :
V_13 = V_21 ;
V_15 = V_22 + ( V_13 - V_9 ) ;
V_2 = & V_6 -> V_8 . V_23 . V_24 [ V_15 ] ;
break;
case V_25 :
V_13 = V_21 ;
V_15 = V_22 + ( V_13 - V_9 ) ;
V_2 = & V_6 -> V_8 . V_23 . V_24 [ V_15 ] ;
break;
case V_26 :
V_13 = V_27 ;
V_15 = V_13 - V_9 ;
V_2 = & V_6 -> V_8 . V_23 . V_28 [ V_15 ] ;
V_15 += V_29 ;
break;
default:
return F_4 ( - V_30 ) ;
}
V_2 -> V_3 ++ ;
if ( V_2 -> V_4 )
return V_2 ;
V_11 = F_5 ( V_6 -> V_31 ,
V_32 ) ;
if ( ! V_11 )
return F_4 ( - V_33 ) ;
V_14 = F_6 ( V_34 , F_7 ( F_8 ( V_6 -> V_31 ,
V_35 . V_36 ) ) ,
V_37 ) ;
V_4 = F_9 ( V_11 , V_15 ,
V_14 ,
V_38 , 0 ) ;
if ( F_10 ( V_4 ) )
return ( void * ) V_4 ;
V_2 -> V_4 = V_4 ;
return V_2 ;
}
static void F_11 ( T_1 * V_39 , T_1 * V_40 , T_2 V_41 )
{
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ , V_39 ++ , V_40 ++ )
* ( ( T_1 * ) V_40 ) = * ( ( T_1 * ) V_39 ) & * ( ( T_1 * ) V_40 ) ;
}
static void F_12 ( void * V_43 , void * V_44 , T_3 V_45 ,
T_3 V_46 , T_3 V_47 , T_3 V_48 )
{
if ( V_45 ) {
memcpy ( F_13 ( V_49 , V_43 ,
V_50 . V_51 . V_52 ) ,
& V_46 , sizeof( V_46 ) ) ;
memset ( F_13 ( V_49 , V_44 ,
V_50 . V_51 . V_52 ) ,
0xff , sizeof( V_45 ) ) ;
}
if ( V_47 ) {
memcpy ( F_13 ( V_49 , V_43 ,
V_53 . V_51 . V_52 ) ,
& V_48 , sizeof( V_48 ) ) ;
memset ( F_13 ( V_49 , V_44 ,
V_53 . V_51 . V_52 ) ,
0xff , sizeof( V_47 ) ) ;
}
F_14 ( V_49 , V_43 ,
V_54 , V_55 ) ;
F_14 ( V_49 , V_44 ,
V_54 , 0xffff ) ;
}
static int F_15 ( V_34 * V_56 , V_34 * V_57 ,
struct V_7 * V_8 )
{
void * V_44 = F_13 ( V_58 , V_56 ,
V_59 ) ;
void * V_43 = F_13 ( V_58 , V_57 ,
V_59 ) ;
V_34 V_16 = V_8 -> V_16 & ~ ( V_17 | V_18 ) ;
struct V_60 * V_61 ;
struct V_60 * V_62 ;
struct V_63 * V_64 ;
struct V_63 * V_65 ;
struct V_66 * V_67 ;
struct V_66 * V_68 ;
switch ( V_16 ) {
case V_19 :
V_61 = & V_8 -> V_69 . V_70 ;
V_62 = & V_8 -> V_71 . V_70 ;
F_12 ( V_43 , V_44 , V_61 -> V_72 ,
V_62 -> V_72 , V_61 -> V_73 , V_62 -> V_73 ) ;
if ( V_61 -> V_74 ) {
F_14 ( V_49 , V_44 , V_75 ,
0xffff ) ;
F_14 ( V_49 , V_43 , V_75 ,
F_16 ( V_62 -> V_74 ) ) ;
}
if ( V_61 -> V_76 ) {
F_14 ( V_49 , V_44 , V_77 ,
0xffff ) ;
F_14 ( V_49 , V_43 , V_77 ,
F_16 ( V_62 -> V_76 ) ) ;
}
F_14 ( V_49 , V_44 , V_78 ,
0xffff ) ;
F_14 ( V_49 , V_43 , V_78 ,
V_79 ) ;
break;
case V_20 :
V_61 = & V_8 -> V_69 . V_70 ;
V_62 = & V_8 -> V_71 . V_70 ;
F_12 ( V_43 , V_44 , V_61 -> V_72 ,
V_62 -> V_72 , V_61 -> V_73 , V_62 -> V_73 ) ;
if ( V_61 -> V_74 ) {
F_14 ( V_49 , V_44 , V_80 ,
0xffff ) ;
F_14 ( V_49 , V_43 , V_80 ,
F_16 ( V_62 -> V_74 ) ) ;
}
if ( V_61 -> V_76 ) {
F_14 ( V_49 , V_44 , V_81 ,
0xffff ) ;
F_14 ( V_49 , V_43 , V_81 ,
F_16 ( V_62 -> V_76 ) ) ;
}
F_14 ( V_49 , V_44 , V_78 ,
0xffff ) ;
F_14 ( V_49 , V_43 , V_78 ,
V_82 ) ;
break;
case V_25 :
V_64 = & V_8 -> V_69 . V_83 ;
V_65 = & V_8 -> V_71 . V_83 ;
F_12 ( V_43 , V_44 , V_64 -> V_72 ,
V_65 -> V_72 , V_64 -> V_73 , V_65 -> V_73 ) ;
break;
case V_26 :
V_68 = & V_8 -> V_69 . V_84 ;
V_67 = & V_8 -> V_71 . V_84 ;
F_11 ( ( T_1 * ) V_68 , ( T_1 * ) V_67 , sizeof( * V_68 ) ) ;
F_17 ( F_13 ( V_49 ,
V_44 , V_85 ) ,
V_68 -> V_86 ) ;
F_17 ( F_13 ( V_49 ,
V_43 , V_85 ) ,
V_67 -> V_86 ) ;
F_17 ( F_13 ( V_49 ,
V_44 , V_87 ) ,
V_68 -> V_88 ) ;
F_17 ( F_13 ( V_49 ,
V_43 , V_87 ) ,
V_67 -> V_88 ) ;
F_14 ( V_49 , V_44 , V_54 ,
F_16 ( V_68 -> V_89 ) ) ;
F_14 ( V_49 , V_43 , V_54 ,
F_16 ( V_67 -> V_89 ) ) ;
break;
default:
return - V_30 ;
}
if ( ( V_8 -> V_16 & V_17 ) &&
( V_8 -> V_90 . V_91 & F_18 ( V_92 ) ) ) {
F_14 ( V_49 , V_44 ,
V_93 , 1 ) ;
F_14 ( V_49 , V_43 ,
V_93 , 1 ) ;
F_14 ( V_49 , V_44 ,
V_94 , 0xfff ) ;
F_14 ( V_49 , V_43 ,
V_94 , F_16 ( V_8 -> V_95 . V_91 ) ) ;
}
if ( V_8 -> V_16 & V_18 &&
! F_19 ( V_8 -> V_90 . V_88 ) ) {
F_17 ( F_13 ( V_49 ,
V_44 , V_87 ) ,
V_8 -> V_90 . V_88 ) ;
F_17 ( F_13 ( V_49 ,
V_43 , V_87 ) ,
V_8 -> V_95 . V_88 ) ;
}
return 0 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_96 * V_97 )
{
struct V_96 * V_98 ;
struct V_99 * V_100 = & V_6 -> V_8 . V_23 . V_101 ;
F_21 (iter, &priv->fs.ethtool.rules, list) {
if ( V_98 -> V_102 . V_103 > V_97 -> V_102 . V_103 )
break;
V_100 = & V_98 -> V_104 ;
}
V_6 -> V_8 . V_23 . V_105 ++ ;
F_22 ( & V_97 -> V_104 , V_100 ) ;
}
static bool F_23 ( V_34 * V_106 )
{
int V_41 = F_24 ( V_58 ) ;
char * V_44 = F_13 ( V_58 , V_106 ,
V_59 ) ;
return V_44 [ 0 ] == 0 && ! memcmp ( V_44 ,
V_44 + 1 ,
V_41 - 1 ) ;
}
static struct V_107 * F_25 ( struct V_5 * V_6 ,
struct V_12 * V_4 ,
struct V_7 * V_8 )
{
struct V_108 * V_109 = NULL ;
struct V_110 * V_111 ;
struct V_107 * V_97 ;
int V_112 = 0 ;
V_34 V_113 ;
V_111 = F_26 ( sizeof( * V_111 ) ) ;
if ( ! V_111 )
return F_4 ( - V_114 ) ;
V_112 = F_15 ( V_111 -> V_106 , V_111 -> V_115 ,
V_8 ) ;
if ( V_112 )
goto free;
if ( V_8 -> V_116 == V_117 ) {
V_113 = V_118 ;
} else {
V_109 = F_27 ( sizeof( * V_109 ) , V_119 ) ;
if ( ! V_109 ) {
V_112 = - V_114 ;
goto free;
}
V_109 -> type = V_120 ;
V_109 -> V_121 = V_6 -> V_122 [ V_8 -> V_116 ] . V_123 ;
V_113 = V_124 ;
}
V_111 -> V_125 = ( ! F_23 ( V_111 -> V_106 ) ) ;
V_97 = F_28 ( V_4 , V_111 , V_113 ,
V_126 , V_109 ) ;
if ( F_10 ( V_97 ) ) {
V_112 = F_29 ( V_97 ) ;
F_30 ( V_6 -> V_127 , L_1 ,
V_128 , V_112 ) ;
goto free;
}
free:
F_31 ( V_111 ) ;
F_32 ( V_109 ) ;
return V_112 ? F_4 ( V_112 ) : V_97 ;
}
static void F_33 ( struct V_5 * V_6 ,
struct V_96 * V_129 )
{
if ( V_129 -> V_97 )
F_34 ( V_129 -> V_97 ) ;
F_35 ( & V_129 -> V_104 ) ;
V_6 -> V_8 . V_23 . V_105 -- ;
F_1 ( V_129 -> V_2 ) ;
F_32 ( V_129 ) ;
}
static struct V_96 * F_36 ( struct V_5 * V_6 ,
int V_103 )
{
struct V_96 * V_98 ;
F_21 (iter, &priv->fs.ethtool.rules, list) {
if ( V_98 -> V_102 . V_103 == V_103 )
return V_98 ;
}
return NULL ;
}
static struct V_96 * F_37 ( struct V_5 * V_6 ,
int V_103 )
{
struct V_96 * V_129 ;
V_129 = F_36 ( V_6 , V_103 ) ;
if ( V_129 )
F_33 ( V_6 , V_129 ) ;
V_129 = F_27 ( sizeof( * V_129 ) , V_119 ) ;
if ( ! V_129 )
return F_4 ( - V_114 ) ;
F_20 ( V_6 , V_129 ) ;
return V_129 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_60 * V_61 ;
struct V_63 * V_64 ;
struct V_66 * V_68 ;
int V_9 = 0 ;
if ( V_8 -> V_103 >= V_130 )
return - V_30 ;
if ( V_8 -> V_116 >= V_6 -> V_131 . V_132 &&
V_8 -> V_116 != V_117 )
return - V_30 ;
switch ( V_8 -> V_16 & ~ ( V_17 | V_18 ) ) {
case V_26 :
V_68 = & V_8 -> V_69 . V_84 ;
if ( ! F_19 ( V_68 -> V_88 ) )
V_9 ++ ;
if ( ! F_19 ( V_68 -> V_86 ) )
V_9 ++ ;
if ( V_68 -> V_89 )
V_9 ++ ;
break;
case V_19 :
case V_20 :
if ( V_8 -> V_69 . V_70 . V_133 )
return - V_30 ;
V_61 = & V_8 -> V_69 . V_70 ;
if ( V_61 -> V_72 ) {
if ( ! F_39 ( V_61 -> V_72 ) )
return - V_30 ;
V_9 ++ ;
}
if ( V_61 -> V_73 ) {
if ( ! F_39 ( V_61 -> V_73 ) )
return - V_30 ;
V_9 ++ ;
}
if ( V_61 -> V_74 ) {
if ( ! F_39 ( V_61 -> V_74 ) )
return - V_30 ;
V_9 ++ ;
}
if ( V_61 -> V_76 ) {
if ( ! F_39 ( V_61 -> V_76 ) )
return - V_30 ;
V_9 ++ ;
}
V_9 ++ ;
break;
case V_25 :
V_64 = & V_8 -> V_69 . V_83 ;
if ( V_64 -> V_134 || V_64 -> V_133 || V_64 -> V_135 ||
V_8 -> V_71 . V_83 . V_136 != V_137 )
return - V_30 ;
if ( V_64 -> V_72 ) {
if ( ! F_39 ( V_64 -> V_72 ) )
return - V_30 ;
V_9 ++ ;
}
if ( V_64 -> V_73 ) {
if ( ! F_39 ( V_64 -> V_73 ) )
return - V_30 ;
V_9 ++ ;
}
V_9 ++ ;
break;
default:
return - V_30 ;
}
if ( ( V_8 -> V_16 & V_17 ) ) {
if ( V_8 -> V_90 . V_138 ||
( V_8 -> V_90 . V_91 != F_18 ( V_92 ) ) )
return - V_30 ;
if ( V_8 -> V_90 . V_91 ) {
if ( F_40 ( V_8 -> V_95 . V_91 ) >= V_139 )
return - V_30 ;
}
V_9 ++ ;
}
if ( V_8 -> V_16 & V_18 &&
! F_19 ( V_8 -> V_90 . V_88 ) )
V_9 ++ ;
return V_9 ;
}
int F_41 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_96 * V_129 ;
struct V_107 * V_97 ;
int V_9 ;
int V_112 ;
V_9 = F_38 ( V_6 , V_8 ) ;
if ( V_9 <= 0 ) {
F_42 ( V_6 -> V_127 , L_2 , V_128 ) ;
return - V_30 ;
}
V_2 = F_3 ( V_6 , V_8 , V_9 ) ;
if ( F_10 ( V_2 ) )
return F_29 ( V_2 ) ;
V_129 = F_37 ( V_6 , V_8 -> V_103 ) ;
if ( F_10 ( V_129 ) ) {
F_1 ( V_2 ) ;
return F_29 ( V_129 ) ;
}
V_129 -> V_102 = * V_8 ;
V_129 -> V_2 = V_2 ;
if ( ! V_2 -> V_4 ) {
V_112 = - V_30 ;
goto F_33;
}
V_97 = F_25 ( V_6 , V_2 -> V_4 , V_8 ) ;
if ( F_10 ( V_97 ) ) {
V_112 = F_29 ( V_97 ) ;
goto F_33;
}
V_129 -> V_97 = V_97 ;
return 0 ;
F_33:
F_33 ( V_6 , V_129 ) ;
return V_112 ;
}
int F_43 ( struct V_5 * V_6 ,
int V_103 )
{
struct V_96 * V_129 ;
int V_112 = 0 ;
if ( V_103 >= V_130 )
return - V_140 ;
V_129 = F_36 ( V_6 , V_103 ) ;
if ( ! V_129 ) {
V_112 = - V_141 ;
goto V_142;
}
F_33 ( V_6 , V_129 ) ;
V_142:
return V_112 ;
}
int F_44 ( struct V_5 * V_6 , struct V_143 * V_144 ,
int V_103 )
{
struct V_96 * V_129 ;
if ( V_103 < 0 || V_103 >= V_130 )
return - V_30 ;
F_21 (eth_rule, &priv->fs.ethtool.rules, list) {
if ( V_129 -> V_102 . V_103 == V_103 ) {
V_144 -> V_8 = V_129 -> V_102 ;
return 0 ;
}
}
return - V_141 ;
}
int F_45 ( struct V_5 * V_6 , struct V_143 * V_144 ,
V_34 * V_145 )
{
int V_103 = 0 ;
int V_146 = 0 ;
int V_112 = 0 ;
while ( ( ! V_112 || V_112 == - V_141 ) && V_146 < V_144 -> V_147 ) {
V_112 = F_44 ( V_6 , V_144 , V_103 ) ;
if ( ! V_112 )
V_145 [ V_146 ++ ] = V_103 ;
V_103 ++ ;
}
return V_112 ;
}
void F_46 ( struct V_5 * V_6 )
{
struct V_96 * V_98 ;
struct V_96 * V_148 ;
F_47 (iter, temp, &priv->fs.ethtool.rules, list)
F_33 ( V_6 , V_98 ) ;
}
void F_48 ( struct V_5 * V_6 )
{
F_49 ( & V_6 -> V_8 . V_23 . V_101 ) ;
}
