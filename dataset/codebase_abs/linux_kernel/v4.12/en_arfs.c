static enum V_1 F_1 ( enum V_2 type )
{
switch ( type ) {
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
default:
return - V_11 ;
}
}
static int F_2 ( struct V_12 * V_13 )
{
struct V_14 V_15 ;
struct V_16 * V_17 = V_13 -> V_18 ;
int V_19 = 0 ;
int V_20 ;
int V_21 ;
V_15 . type = V_22 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_15 . V_24 = V_17 [ V_21 ] . V_25 ;
V_20 = F_1 ( V_21 ) ;
V_19 = F_3 ( V_13 -> V_26 . V_27 . V_28 [ V_20 ] ,
& V_15 , NULL ) ;
if ( V_19 ) {
F_4 ( V_13 -> V_29 ,
L_1 ,
V_30 ) ;
return V_19 ;
}
}
return 0 ;
}
int F_5 ( struct V_12 * V_13 )
{
F_6 ( V_13 ) ;
return F_2 ( V_13 ) ;
}
int F_7 ( struct V_12 * V_13 )
{
struct V_14 V_15 ;
int V_19 = 0 ;
int V_20 ;
int V_21 ;
V_15 . type = V_31 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_15 . V_32 = V_13 -> V_26 . V_33 . V_34 [ V_21 ] . V_32 . V_35 ;
V_20 = F_1 ( V_21 ) ;
V_19 = F_3 ( V_13 -> V_26 . V_27 . V_28 [ V_20 ] ,
& V_15 , NULL ) ;
if ( V_19 ) {
F_4 ( V_13 -> V_29 ,
L_2 ,
V_30 , V_19 ) ;
F_2 ( V_13 ) ;
return V_19 ;
}
}
return 0 ;
}
static void F_8 ( struct V_36 * V_37 )
{
F_9 ( V_37 -> V_38 ) ;
F_10 ( & V_37 -> V_32 ) ;
}
void F_11 ( struct V_12 * V_13 )
{
int V_21 ;
if ( ! ( V_13 -> V_29 -> V_39 & V_40 ) )
return;
F_6 ( V_13 ) ;
F_12 ( V_13 -> V_26 . V_33 . V_41 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
if ( ! F_13 ( V_13 -> V_26 . V_33 . V_34 [ V_21 ] . V_32 . V_35 ) )
F_8 ( & V_13 -> V_26 . V_33 . V_34 [ V_21 ] ) ;
}
}
static int F_14 ( struct V_12 * V_13 ,
enum V_2 type )
{
struct V_36 * V_37 = & V_13 -> V_26 . V_33 . V_34 [ type ] ;
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_14 V_15 ;
F_15 ( V_42 ) ;
struct V_43 * V_44 ;
int V_19 = 0 ;
V_44 = F_16 ( sizeof( * V_44 ) ) ;
if ( ! V_44 ) {
F_4 ( V_13 -> V_29 , L_3 , V_30 ) ;
V_19 = - V_45 ;
goto V_46;
}
V_15 . type = V_22 ;
switch ( type ) {
case V_3 :
V_15 . V_24 = V_17 [ V_4 ] . V_25 ;
break;
case V_5 :
V_15 . V_24 = V_17 [ V_6 ] . V_25 ;
break;
case V_7 :
V_15 . V_24 = V_17 [ V_8 ] . V_25 ;
break;
case V_9 :
V_15 . V_24 = V_17 [ V_10 ] . V_25 ;
break;
default:
V_19 = - V_11 ;
goto V_46;
}
V_37 -> V_38 = F_17 ( V_37 -> V_32 . V_35 , V_44 ,
& V_42 ,
& V_15 , 1 ) ;
if ( F_18 ( V_37 -> V_38 ) ) {
V_19 = F_19 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
F_4 ( V_13 -> V_29 , L_4 ,
V_30 , type ) ;
}
V_46:
F_20 ( V_44 ) ;
return V_19 ;
}
static int F_21 ( struct V_47 * V_32 ,
enum V_2 type )
{
int V_48 = F_22 ( V_49 ) ;
void * V_50 ;
int V_51 = 0 ;
T_1 * V_52 ;
int V_19 ;
T_2 * V_53 ;
V_32 -> V_54 = F_23 ( V_55 ,
sizeof( * V_32 -> V_54 ) , V_56 ) ;
V_52 = F_16 ( V_48 ) ;
if ( ! V_52 || ! V_32 -> V_54 ) {
F_20 ( V_32 -> V_54 ) ;
F_20 ( V_52 ) ;
return - V_45 ;
}
V_53 = F_24 ( V_49 , V_52 , V_57 ) ;
V_50 = F_24 ( V_58 , V_53 ,
V_59 ) ;
F_25 ( V_60 , V_50 , V_61 ) ;
switch ( type ) {
case V_3 :
case V_7 :
F_25 ( V_60 , V_50 , V_62 ) ;
F_25 ( V_60 , V_50 , V_63 ) ;
break;
case V_5 :
case V_9 :
F_25 ( V_60 , V_50 , V_64 ) ;
F_25 ( V_60 , V_50 , V_65 ) ;
break;
default:
V_19 = - V_11 ;
goto V_46;
}
switch ( type ) {
case V_3 :
case V_5 :
F_25 ( V_60 , V_50 ,
V_66 . V_67 . V_68 ) ;
F_25 ( V_60 , V_50 ,
V_69 . V_67 . V_68 ) ;
break;
case V_7 :
case V_9 :
memset ( F_24 ( V_60 , V_50 ,
V_66 . V_70 . V_71 ) ,
0xff , 16 ) ;
memset ( F_24 ( V_60 , V_50 ,
V_69 . V_70 . V_71 ) ,
0xff , 16 ) ;
break;
default:
V_19 = - V_11 ;
goto V_46;
}
F_26 ( V_52 , V_72 , V_73 ) ;
F_26 ( V_52 , V_74 , V_51 ) ;
V_51 += V_75 ;
F_26 ( V_52 , V_76 , V_51 - 1 ) ;
V_32 -> V_54 [ V_32 -> V_77 ] = F_27 ( V_32 -> V_35 , V_52 ) ;
if ( F_18 ( V_32 -> V_54 [ V_32 -> V_77 ] ) )
goto V_19;
V_32 -> V_77 ++ ;
memset ( V_52 , 0 , V_48 ) ;
F_26 ( V_52 , V_74 , V_51 ) ;
V_51 += V_78 ;
F_26 ( V_52 , V_76 , V_51 - 1 ) ;
V_32 -> V_54 [ V_32 -> V_77 ] = F_27 ( V_32 -> V_35 , V_52 ) ;
if ( F_18 ( V_32 -> V_54 [ V_32 -> V_77 ] ) )
goto V_19;
V_32 -> V_77 ++ ;
F_20 ( V_52 ) ;
return 0 ;
V_19:
V_19 = F_19 ( V_32 -> V_54 [ V_32 -> V_77 ] ) ;
V_32 -> V_54 [ V_32 -> V_77 ] = NULL ;
V_46:
F_20 ( V_52 ) ;
return V_19 ;
}
static int F_28 ( struct V_12 * V_13 ,
enum V_2 type )
{
struct V_79 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_47 * V_32 = & V_33 -> V_34 [ type ] . V_32 ;
struct V_80 V_81 = {} ;
int V_19 ;
V_32 -> V_77 = 0 ;
V_81 . V_82 = V_83 ;
V_81 . V_84 = V_85 ;
V_81 . V_86 = V_87 ;
V_32 -> V_35 = F_29 ( V_13 -> V_26 . V_88 , & V_81 ) ;
if ( F_18 ( V_32 -> V_35 ) ) {
V_19 = F_19 ( V_32 -> V_35 ) ;
V_32 -> V_35 = NULL ;
return V_19 ;
}
V_19 = F_21 ( V_32 , type ) ;
if ( V_19 )
goto V_19;
V_19 = F_14 ( V_13 , type ) ;
if ( V_19 )
goto V_19;
return 0 ;
V_19:
F_10 ( V_32 ) ;
return V_19 ;
}
int F_30 ( struct V_12 * V_13 )
{
int V_19 = 0 ;
int V_21 ;
if ( ! ( V_13 -> V_29 -> V_39 & V_40 ) )
return 0 ;
F_31 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_32 ( & V_13 -> V_26 . V_33 . V_28 ) ;
V_13 -> V_26 . V_33 . V_41 = F_33 ( L_5 ) ;
if ( ! V_13 -> V_26 . V_33 . V_41 )
return - V_45 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_19 = F_28 ( V_13 , V_21 ) ;
if ( V_19 )
goto V_19;
}
return 0 ;
V_19:
F_11 ( V_13 ) ;
return V_19 ;
}
static void F_34 ( struct V_12 * V_13 )
{
struct V_90 * V_90 ;
struct V_91 * V_92 ;
int V_93 = 0 ;
int V_21 ;
int V_94 ;
F_35 ( V_95 ) ;
F_36 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_37 (arfs_rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
if ( V_93 ++ > V_96 )
break;
if ( ! F_38 ( & V_90 -> V_97 ) &&
F_39 ( V_13 -> V_29 ,
V_90 -> V_98 , V_90 -> V_99 ,
V_90 -> V_100 ) ) {
F_40 ( & V_90 -> V_101 ) ;
F_41 ( & V_90 -> V_101 , & V_95 ) ;
}
}
F_42 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_43 (arfs_rule, htmp, &del_list, hlist) {
if ( V_90 -> V_102 )
F_9 ( V_90 -> V_102 ) ;
F_44 ( & V_90 -> V_101 ) ;
F_45 ( V_90 ) ;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_91 * V_92 ;
struct V_90 * V_102 ;
int V_21 ;
int V_94 ;
F_35 ( V_95 ) ;
F_36 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_37 (rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
F_40 ( & V_102 -> V_101 ) ;
F_41 ( & V_102 -> V_101 , & V_95 ) ;
}
F_42 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_43 (rule, htmp, &del_list, hlist) {
F_46 ( & V_102 -> V_97 ) ;
if ( V_102 -> V_102 )
F_9 ( V_102 -> V_102 ) ;
F_44 ( & V_102 -> V_101 ) ;
F_45 ( V_102 ) ;
}
}
static struct V_103 *
F_47 ( struct V_36 * V_37 , T_3 V_104 ,
T_3 V_105 )
{
unsigned long V_106 ;
int V_107 ;
V_106 = ( V_108 unsigned long ) V_104 |
( ( V_108 unsigned long ) V_105 << 2 ) ;
V_107 = F_48 ( V_106 , V_109 ) ;
return & V_37 -> V_110 [ V_107 ] ;
}
static T_2 F_49 ( const struct V_111 * V_112 )
{
return ( V_112 -> V_113 == F_50 ( V_114 ) ) ?
F_51 ( V_112 ) -> V_113 : F_52 ( V_112 ) -> V_115 ;
}
static struct V_36 * F_53 ( struct V_79 * V_33 ,
T_2 V_116 , T_3 V_117 )
{
if ( V_117 == F_50 ( V_114 ) && V_116 == V_118 )
return & V_33 -> V_34 [ V_3 ] ;
if ( V_117 == F_50 ( V_114 ) && V_116 == V_119 )
return & V_33 -> V_34 [ V_5 ] ;
if ( V_117 == F_50 ( V_120 ) && V_116 == V_118 )
return & V_33 -> V_34 [ V_7 ] ;
if ( V_117 == F_50 ( V_120 ) && V_116 == V_119 )
return & V_33 -> V_34 [ V_9 ] ;
return NULL ;
}
static struct V_121 * F_54 ( struct V_12 * V_13 ,
struct V_90 * V_90 )
{
struct V_79 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_122 * V_123 = & V_90 -> V_123 ;
struct V_121 * V_102 = NULL ;
struct V_14 V_15 ;
F_15 ( V_42 ) ;
struct V_36 * V_36 ;
struct V_43 * V_44 ;
struct V_124 * V_32 ;
int V_19 = 0 ;
V_44 = F_16 ( sizeof( * V_44 ) ) ;
if ( ! V_44 ) {
F_4 ( V_13 -> V_29 , L_3 , V_30 ) ;
V_19 = - V_45 ;
goto V_46;
}
V_44 -> V_72 = V_73 ;
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_61 ) ;
F_55 ( V_58 , V_44 -> V_125 , V_59 . V_61 ,
F_56 ( V_123 -> V_117 ) ) ;
V_36 = F_53 ( V_33 , V_123 -> V_116 , V_123 -> V_117 ) ;
if ( ! V_36 ) {
V_19 = - V_11 ;
goto V_46;
}
V_32 = V_36 -> V_32 . V_35 ;
if ( V_123 -> V_116 == V_118 ) {
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_62 ) ;
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_63 ) ;
F_55 ( V_58 , V_44 -> V_125 , V_59 . V_62 ,
F_56 ( V_123 -> V_105 ) ) ;
F_55 ( V_58 , V_44 -> V_125 , V_59 . V_63 ,
F_56 ( V_123 -> V_104 ) ) ;
} else {
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_64 ) ;
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_65 ) ;
F_55 ( V_58 , V_44 -> V_125 , V_59 . V_64 ,
F_56 ( V_123 -> V_105 ) ) ;
F_55 ( V_58 , V_44 -> V_125 , V_59 . V_65 ,
F_56 ( V_123 -> V_104 ) ) ;
}
if ( V_123 -> V_117 == F_50 ( V_114 ) ) {
memcpy ( F_24 ( V_58 , V_44 -> V_125 ,
V_59 . V_66 . V_67 . V_68 ) ,
& V_123 -> V_126 ,
4 ) ;
memcpy ( F_24 ( V_58 , V_44 -> V_125 ,
V_59 . V_69 . V_67 . V_68 ) ,
& V_123 -> V_127 ,
4 ) ;
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_66 . V_67 . V_68 ) ;
F_25 ( V_58 , V_44 -> V_57 ,
V_59 . V_69 . V_67 . V_68 ) ;
} else {
memcpy ( F_24 ( V_58 , V_44 -> V_125 ,
V_59 . V_66 . V_70 . V_71 ) ,
& V_123 -> V_128 ,
16 ) ;
memcpy ( F_24 ( V_58 , V_44 -> V_125 ,
V_59 . V_69 . V_70 . V_71 ) ,
& V_123 -> V_129 ,
16 ) ;
memset ( F_24 ( V_58 , V_44 -> V_57 ,
V_59 . V_66 . V_70 . V_71 ) ,
0xff ,
16 ) ;
memset ( F_24 ( V_58 , V_44 -> V_57 ,
V_59 . V_69 . V_70 . V_71 ) ,
0xff ,
16 ) ;
}
V_15 . type = V_22 ;
V_15 . V_24 = V_13 -> V_130 [ V_90 -> V_98 ] . V_25 ;
V_102 = F_17 ( V_32 , V_44 , & V_42 , & V_15 , 1 ) ;
if ( F_18 ( V_102 ) ) {
V_19 = F_19 ( V_102 ) ;
F_4 ( V_13 -> V_29 , L_6 ,
V_30 , V_90 -> V_100 , V_90 -> V_98 , V_19 ) ;
}
V_46:
F_20 ( V_44 ) ;
return V_19 ? F_57 ( V_19 ) : V_102 ;
}
static void F_58 ( struct V_12 * V_13 ,
struct V_121 * V_102 , T_4 V_98 )
{
struct V_14 V_131 ;
int V_19 = 0 ;
V_131 . type = V_22 ;
V_131 . V_24 = V_13 -> V_130 [ V_98 ] . V_25 ;
V_19 = F_3 ( V_102 , & V_131 , NULL ) ;
if ( V_19 )
F_59 ( V_13 -> V_29 ,
L_7 , V_98 ) ;
}
static void F_60 ( struct V_132 * V_133 )
{
struct V_90 * V_90 = F_61 ( V_133 ,
struct V_90 ,
V_97 ) ;
struct V_12 * V_13 = V_90 -> V_13 ;
struct V_121 * V_102 ;
F_62 ( & V_13 -> V_134 ) ;
if ( ! F_63 ( V_135 , & V_13 -> V_136 ) ) {
F_36 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_44 ( & V_90 -> V_101 ) ;
F_42 ( & V_13 -> V_26 . V_33 . V_89 ) ;
F_64 ( & V_13 -> V_134 ) ;
F_45 ( V_90 ) ;
goto V_46;
}
F_64 ( & V_13 -> V_134 ) ;
if ( ! V_90 -> V_102 ) {
V_102 = F_54 ( V_13 , V_90 ) ;
if ( F_18 ( V_102 ) )
goto V_46;
V_90 -> V_102 = V_102 ;
} else {
F_58 ( V_13 , V_90 -> V_102 ,
V_90 -> V_98 ) ;
}
V_46:
F_34 ( V_13 ) ;
}
static T_3 F_65 ( const struct V_111 * V_112 )
{
char * V_137 ;
V_137 = F_66 ( V_112 ) ;
if ( F_49 ( V_112 ) == V_118 )
return ( (struct V_138 * ) V_137 ) -> V_15 ;
return ( (struct V_139 * ) V_137 ) -> V_15 ;
}
static T_3 F_67 ( const struct V_111 * V_112 )
{
char * V_137 ;
V_137 = F_66 ( V_112 ) ;
if ( F_49 ( V_112 ) == V_118 )
return ( (struct V_138 * ) V_137 ) -> V_140 ;
return ( (struct V_139 * ) V_137 ) -> V_140 ;
}
static struct V_90 * F_68 ( struct V_12 * V_13 ,
struct V_36 * V_37 ,
const struct V_111 * V_112 ,
T_4 V_98 , T_1 V_99 )
{
struct V_90 * V_102 ;
struct V_122 * V_123 ;
V_102 = F_69 ( sizeof( * V_102 ) , V_141 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_13 = V_13 ;
V_102 -> V_98 = V_98 ;
F_70 ( & V_102 -> V_97 , F_60 ) ;
V_123 = & V_102 -> V_123 ;
V_123 -> V_117 = V_112 -> V_113 ;
if ( V_123 -> V_117 == F_50 ( V_114 ) ) {
V_123 -> V_126 = F_51 ( V_112 ) -> V_142 ;
V_123 -> V_127 = F_51 ( V_112 ) -> V_143 ;
} else {
memcpy ( & V_123 -> V_128 , & F_52 ( V_112 ) -> V_142 ,
sizeof( struct V_144 ) ) ;
memcpy ( & V_123 -> V_129 , & F_52 ( V_112 ) -> V_143 ,
sizeof( struct V_144 ) ) ;
}
V_123 -> V_116 = F_49 ( V_112 ) ;
V_123 -> V_104 = F_67 ( V_112 ) ;
V_123 -> V_105 = F_65 ( V_112 ) ;
V_102 -> V_99 = V_99 ;
V_102 -> V_100 = V_13 -> V_26 . V_33 . V_145 ++ % V_146 ;
F_41 ( & V_102 -> V_101 ,
F_47 ( V_37 , V_123 -> V_104 ,
V_123 -> V_105 ) ) ;
return V_102 ;
}
static bool F_71 ( struct V_122 * V_123 ,
const struct V_111 * V_112 )
{
if ( V_123 -> V_117 == F_50 ( V_114 ) &&
V_123 -> V_126 == F_51 ( V_112 ) -> V_142 &&
V_123 -> V_127 == F_51 ( V_112 ) -> V_143 )
return true ;
if ( V_123 -> V_117 == F_50 ( V_120 ) &&
( ! memcmp ( & V_123 -> V_128 , & F_52 ( V_112 ) -> V_142 ,
sizeof( struct V_144 ) ) ) &&
( ! memcmp ( & V_123 -> V_129 , & F_52 ( V_112 ) -> V_143 ,
sizeof( struct V_144 ) ) ) )
return true ;
return false ;
}
static struct V_90 * F_72 ( struct V_36 * V_37 ,
const struct V_111 * V_112 )
{
struct V_90 * V_90 ;
struct V_103 * V_147 ;
T_3 V_104 = F_67 ( V_112 ) ;
T_3 V_105 = F_65 ( V_112 ) ;
V_147 = F_47 ( V_37 , V_104 , V_105 ) ;
F_73 (arfs_rule, head, hlist) {
if ( V_90 -> V_123 . V_104 == V_104 &&
V_90 -> V_123 . V_105 == V_105 &&
F_71 ( & V_90 -> V_123 , V_112 ) ) {
return V_90 ;
}
}
return NULL ;
}
int F_74 ( struct V_148 * V_149 , const struct V_111 * V_112 ,
T_4 V_150 , T_1 V_99 )
{
struct V_12 * V_13 = F_75 ( V_149 ) ;
struct V_79 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_36 * V_37 ;
struct V_90 * V_90 ;
if ( V_112 -> V_113 != F_50 ( V_114 ) &&
V_112 -> V_113 != F_50 ( V_120 ) )
return - V_151 ;
V_37 = F_53 ( V_33 , F_49 ( V_112 ) , V_112 -> V_113 ) ;
if ( ! V_37 )
return - V_151 ;
F_36 ( & V_33 -> V_89 ) ;
V_90 = F_72 ( V_37 , V_112 ) ;
if ( V_90 ) {
if ( V_90 -> V_98 == V_150 ) {
F_42 ( & V_33 -> V_89 ) ;
return V_90 -> V_100 ;
}
V_90 -> V_98 = V_150 ;
} else {
V_90 = F_68 ( V_13 , V_37 , V_112 ,
V_150 , V_99 ) ;
if ( ! V_90 ) {
F_42 ( & V_33 -> V_89 ) ;
return - V_45 ;
}
}
F_76 ( V_13 -> V_26 . V_33 . V_41 , & V_90 -> V_97 ) ;
F_42 ( & V_33 -> V_89 ) ;
return V_90 -> V_100 ;
}
