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
struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = 0 ,
} ;
struct V_14 V_15 ;
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_49 * V_50 ;
int V_19 = 0 ;
V_50 = F_15 ( sizeof( * V_50 ) ) ;
if ( ! V_50 ) {
F_4 ( V_13 -> V_29 , L_3 , V_30 ) ;
V_19 = - V_51 ;
goto V_52;
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
goto V_52;
}
V_37 -> V_38 = F_16 ( V_37 -> V_32 . V_35 , V_50 ,
& V_43 ,
& V_15 , 1 ) ;
if ( F_17 ( V_37 -> V_38 ) ) {
V_19 = F_18 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
F_4 ( V_13 -> V_29 , L_4 ,
V_30 , type ) ;
}
V_52:
F_19 ( V_50 ) ;
return V_19 ;
}
static int F_20 ( struct V_53 * V_32 ,
enum V_2 type )
{
int V_54 = F_21 ( V_55 ) ;
void * V_56 ;
int V_57 = 0 ;
T_1 * V_58 ;
int V_19 ;
T_2 * V_59 ;
V_32 -> V_60 = F_22 ( V_61 ,
sizeof( * V_32 -> V_60 ) , V_62 ) ;
V_58 = F_15 ( V_54 ) ;
if ( ! V_58 || ! V_32 -> V_60 ) {
F_19 ( V_32 -> V_60 ) ;
F_19 ( V_58 ) ;
return - V_51 ;
}
V_59 = F_23 ( V_55 , V_58 , V_63 ) ;
V_56 = F_23 ( V_64 , V_59 ,
V_65 ) ;
F_24 ( V_66 , V_56 , V_67 ) ;
switch ( type ) {
case V_3 :
case V_7 :
F_24 ( V_66 , V_56 , V_68 ) ;
F_24 ( V_66 , V_56 , V_69 ) ;
break;
case V_5 :
case V_9 :
F_24 ( V_66 , V_56 , V_70 ) ;
F_24 ( V_66 , V_56 , V_71 ) ;
break;
default:
V_19 = - V_11 ;
goto V_52;
}
switch ( type ) {
case V_3 :
case V_5 :
F_24 ( V_66 , V_56 ,
V_72 . V_73 . V_74 ) ;
F_24 ( V_66 , V_56 ,
V_75 . V_73 . V_74 ) ;
break;
case V_7 :
case V_9 :
memset ( F_23 ( V_66 , V_56 ,
V_72 . V_76 . V_77 ) ,
0xff , 16 ) ;
memset ( F_23 ( V_66 , V_56 ,
V_75 . V_76 . V_77 ) ,
0xff , 16 ) ;
break;
default:
V_19 = - V_11 ;
goto V_52;
}
F_25 ( V_58 , V_78 , V_79 ) ;
F_25 ( V_58 , V_80 , V_57 ) ;
V_57 += V_81 ;
F_25 ( V_58 , V_82 , V_57 - 1 ) ;
V_32 -> V_60 [ V_32 -> V_83 ] = F_26 ( V_32 -> V_35 , V_58 ) ;
if ( F_17 ( V_32 -> V_60 [ V_32 -> V_83 ] ) )
goto V_19;
V_32 -> V_83 ++ ;
memset ( V_58 , 0 , V_54 ) ;
F_25 ( V_58 , V_80 , V_57 ) ;
V_57 += V_84 ;
F_25 ( V_58 , V_82 , V_57 - 1 ) ;
V_32 -> V_60 [ V_32 -> V_83 ] = F_26 ( V_32 -> V_35 , V_58 ) ;
if ( F_17 ( V_32 -> V_60 [ V_32 -> V_83 ] ) )
goto V_19;
V_32 -> V_83 ++ ;
F_19 ( V_58 ) ;
return 0 ;
V_19:
V_19 = F_18 ( V_32 -> V_60 [ V_32 -> V_83 ] ) ;
V_32 -> V_60 [ V_32 -> V_83 ] = NULL ;
V_52:
F_19 ( V_58 ) ;
return V_19 ;
}
static int F_27 ( struct V_12 * V_13 ,
enum V_2 type )
{
struct V_85 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_53 * V_32 = & V_33 -> V_34 [ type ] . V_32 ;
int V_19 ;
V_32 -> V_35 = F_28 ( V_13 -> V_26 . V_86 , V_87 ,
V_88 , V_89 , 0 ) ;
if ( F_17 ( V_32 -> V_35 ) ) {
V_19 = F_18 ( V_32 -> V_35 ) ;
V_32 -> V_35 = NULL ;
return V_19 ;
}
V_19 = F_20 ( V_32 , type ) ;
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
int F_29 ( struct V_12 * V_13 )
{
int V_19 = 0 ;
int V_21 ;
if ( ! ( V_13 -> V_29 -> V_39 & V_40 ) )
return 0 ;
F_30 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_31 ( & V_13 -> V_26 . V_33 . V_28 ) ;
V_13 -> V_26 . V_33 . V_41 = F_32 ( L_5 ) ;
if ( ! V_13 -> V_26 . V_33 . V_41 )
return - V_51 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_19 = F_27 ( V_13 , V_21 ) ;
if ( V_19 )
goto V_19;
}
return 0 ;
V_19:
F_11 ( V_13 ) ;
return V_19 ;
}
static void F_33 ( struct V_12 * V_13 )
{
struct V_91 * V_91 ;
struct V_92 * V_93 ;
int V_94 = 0 ;
int V_21 ;
int V_95 ;
F_34 ( V_96 ) ;
F_35 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_36 (arfs_rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
if ( V_94 ++ > V_97 )
break;
if ( ! F_37 ( & V_91 -> V_98 ) &&
F_38 ( V_13 -> V_29 ,
V_91 -> V_99 , V_91 -> V_100 ,
V_91 -> V_101 ) ) {
F_39 ( & V_91 -> V_102 ) ;
F_40 ( & V_91 -> V_102 , & V_96 ) ;
}
}
F_41 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_42 (arfs_rule, htmp, &del_list, hlist) {
if ( V_91 -> V_103 )
F_9 ( V_91 -> V_103 ) ;
F_43 ( & V_91 -> V_102 ) ;
F_44 ( V_91 ) ;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_92 * V_93 ;
struct V_91 * V_103 ;
int V_21 ;
int V_95 ;
F_34 ( V_96 ) ;
F_35 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_36 (rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
F_39 ( & V_103 -> V_102 ) ;
F_40 ( & V_103 -> V_102 , & V_96 ) ;
}
F_41 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_42 (rule, htmp, &del_list, hlist) {
F_45 ( & V_103 -> V_98 ) ;
if ( V_103 -> V_103 )
F_9 ( V_103 -> V_103 ) ;
F_43 ( & V_103 -> V_102 ) ;
F_44 ( V_103 ) ;
}
}
static struct V_104 *
F_46 ( struct V_36 * V_37 , T_3 V_105 ,
T_3 V_106 )
{
unsigned long V_107 ;
int V_108 ;
V_107 = ( V_109 unsigned long ) V_105 |
( ( V_109 unsigned long ) V_106 << 2 ) ;
V_108 = F_47 ( V_107 , V_110 ) ;
return & V_37 -> V_111 [ V_108 ] ;
}
static T_2 F_48 ( const struct V_112 * V_113 )
{
return ( V_113 -> V_114 == F_49 ( V_115 ) ) ?
F_50 ( V_113 ) -> V_114 : F_51 ( V_113 ) -> V_116 ;
}
static struct V_36 * F_52 ( struct V_85 * V_33 ,
T_2 V_117 , T_3 V_118 )
{
if ( V_118 == F_49 ( V_115 ) && V_117 == V_119 )
return & V_33 -> V_34 [ V_3 ] ;
if ( V_118 == F_49 ( V_115 ) && V_117 == V_120 )
return & V_33 -> V_34 [ V_5 ] ;
if ( V_118 == F_49 ( V_121 ) && V_117 == V_119 )
return & V_33 -> V_34 [ V_7 ] ;
if ( V_118 == F_49 ( V_121 ) && V_117 == V_120 )
return & V_33 -> V_34 [ V_9 ] ;
return NULL ;
}
static struct V_122 * F_53 ( struct V_12 * V_13 ,
struct V_91 * V_91 )
{
struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = 0 ,
} ;
struct V_85 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_123 * V_124 = & V_91 -> V_124 ;
struct V_122 * V_103 = NULL ;
struct V_14 V_15 ;
struct V_36 * V_36 ;
struct V_49 * V_50 ;
struct V_125 * V_32 ;
int V_19 = 0 ;
V_50 = F_15 ( sizeof( * V_50 ) ) ;
if ( ! V_50 ) {
F_4 ( V_13 -> V_29 , L_3 , V_30 ) ;
V_19 = - V_51 ;
goto V_52;
}
V_50 -> V_78 = V_79 ;
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_67 ) ;
F_54 ( V_64 , V_50 -> V_126 , V_65 . V_67 ,
F_55 ( V_124 -> V_118 ) ) ;
V_36 = F_52 ( V_33 , V_124 -> V_117 , V_124 -> V_118 ) ;
if ( ! V_36 ) {
V_19 = - V_11 ;
goto V_52;
}
V_32 = V_36 -> V_32 . V_35 ;
if ( V_124 -> V_117 == V_119 ) {
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_68 ) ;
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_69 ) ;
F_54 ( V_64 , V_50 -> V_126 , V_65 . V_68 ,
F_55 ( V_124 -> V_106 ) ) ;
F_54 ( V_64 , V_50 -> V_126 , V_65 . V_69 ,
F_55 ( V_124 -> V_105 ) ) ;
} else {
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_70 ) ;
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_71 ) ;
F_54 ( V_64 , V_50 -> V_126 , V_65 . V_70 ,
F_55 ( V_124 -> V_106 ) ) ;
F_54 ( V_64 , V_50 -> V_126 , V_65 . V_71 ,
F_55 ( V_124 -> V_105 ) ) ;
}
if ( V_124 -> V_118 == F_49 ( V_115 ) ) {
memcpy ( F_23 ( V_64 , V_50 -> V_126 ,
V_65 . V_72 . V_73 . V_74 ) ,
& V_124 -> V_127 ,
4 ) ;
memcpy ( F_23 ( V_64 , V_50 -> V_126 ,
V_65 . V_75 . V_73 . V_74 ) ,
& V_124 -> V_128 ,
4 ) ;
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_72 . V_73 . V_74 ) ;
F_24 ( V_64 , V_50 -> V_63 ,
V_65 . V_75 . V_73 . V_74 ) ;
} else {
memcpy ( F_23 ( V_64 , V_50 -> V_126 ,
V_65 . V_72 . V_76 . V_77 ) ,
& V_124 -> V_129 ,
16 ) ;
memcpy ( F_23 ( V_64 , V_50 -> V_126 ,
V_65 . V_75 . V_76 . V_77 ) ,
& V_124 -> V_130 ,
16 ) ;
memset ( F_23 ( V_64 , V_50 -> V_63 ,
V_65 . V_72 . V_76 . V_77 ) ,
0xff ,
16 ) ;
memset ( F_23 ( V_64 , V_50 -> V_63 ,
V_65 . V_75 . V_76 . V_77 ) ,
0xff ,
16 ) ;
}
V_15 . type = V_22 ;
V_15 . V_24 = V_13 -> V_131 [ V_91 -> V_99 ] . V_25 ;
V_103 = F_16 ( V_32 , V_50 , & V_43 , & V_15 , 1 ) ;
if ( F_17 ( V_103 ) ) {
V_19 = F_18 ( V_103 ) ;
F_4 ( V_13 -> V_29 , L_6 ,
V_30 , V_91 -> V_101 , V_91 -> V_99 , V_19 ) ;
}
V_52:
F_19 ( V_50 ) ;
return V_19 ? F_56 ( V_19 ) : V_103 ;
}
static void F_57 ( struct V_12 * V_13 ,
struct V_122 * V_103 , T_4 V_99 )
{
struct V_14 V_132 ;
int V_19 = 0 ;
V_132 . type = V_22 ;
V_132 . V_24 = V_13 -> V_131 [ V_99 ] . V_25 ;
V_19 = F_3 ( V_103 , & V_132 , NULL ) ;
if ( V_19 )
F_58 ( V_13 -> V_29 ,
L_7 , V_99 ) ;
}
static void F_59 ( struct V_133 * V_134 )
{
struct V_91 * V_91 = F_60 ( V_134 ,
struct V_91 ,
V_98 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
struct V_122 * V_103 ;
F_61 ( & V_13 -> V_135 ) ;
if ( ! F_62 ( V_136 , & V_13 -> V_137 ) ) {
F_35 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_43 ( & V_91 -> V_102 ) ;
F_41 ( & V_13 -> V_26 . V_33 . V_90 ) ;
F_63 ( & V_13 -> V_135 ) ;
F_44 ( V_91 ) ;
goto V_52;
}
F_63 ( & V_13 -> V_135 ) ;
if ( ! V_91 -> V_103 ) {
V_103 = F_53 ( V_13 , V_91 ) ;
if ( F_17 ( V_103 ) )
goto V_52;
V_91 -> V_103 = V_103 ;
} else {
F_57 ( V_13 , V_91 -> V_103 ,
V_91 -> V_99 ) ;
}
V_52:
F_33 ( V_13 ) ;
}
static T_3 F_64 ( const struct V_112 * V_113 )
{
char * V_138 ;
V_138 = F_65 ( V_113 ) ;
if ( F_48 ( V_113 ) == V_119 )
return ( (struct V_139 * ) V_138 ) -> V_15 ;
return ( (struct V_140 * ) V_138 ) -> V_15 ;
}
static T_3 F_66 ( const struct V_112 * V_113 )
{
char * V_138 ;
V_138 = F_65 ( V_113 ) ;
if ( F_48 ( V_113 ) == V_119 )
return ( (struct V_139 * ) V_138 ) -> V_141 ;
return ( (struct V_140 * ) V_138 ) -> V_141 ;
}
static struct V_91 * F_67 ( struct V_12 * V_13 ,
struct V_36 * V_37 ,
const struct V_112 * V_113 ,
T_4 V_99 , T_1 V_100 )
{
struct V_91 * V_103 ;
struct V_123 * V_124 ;
V_103 = F_68 ( sizeof( * V_103 ) , V_142 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_13 = V_13 ;
V_103 -> V_99 = V_99 ;
F_69 ( & V_103 -> V_98 , F_59 ) ;
V_124 = & V_103 -> V_124 ;
V_124 -> V_118 = V_113 -> V_114 ;
if ( V_124 -> V_118 == F_49 ( V_115 ) ) {
V_124 -> V_127 = F_50 ( V_113 ) -> V_143 ;
V_124 -> V_128 = F_50 ( V_113 ) -> V_144 ;
} else {
memcpy ( & V_124 -> V_129 , & F_51 ( V_113 ) -> V_143 ,
sizeof( struct V_145 ) ) ;
memcpy ( & V_124 -> V_130 , & F_51 ( V_113 ) -> V_144 ,
sizeof( struct V_145 ) ) ;
}
V_124 -> V_117 = F_48 ( V_113 ) ;
V_124 -> V_105 = F_66 ( V_113 ) ;
V_124 -> V_106 = F_64 ( V_113 ) ;
V_103 -> V_100 = V_100 ;
V_103 -> V_101 = V_13 -> V_26 . V_33 . V_146 ++ % V_147 ;
F_40 ( & V_103 -> V_102 ,
F_46 ( V_37 , V_124 -> V_105 ,
V_124 -> V_106 ) ) ;
return V_103 ;
}
static bool F_70 ( struct V_123 * V_124 ,
const struct V_112 * V_113 )
{
if ( V_124 -> V_118 == F_49 ( V_115 ) &&
V_124 -> V_127 == F_50 ( V_113 ) -> V_143 &&
V_124 -> V_128 == F_50 ( V_113 ) -> V_144 )
return true ;
if ( V_124 -> V_118 == F_49 ( V_121 ) &&
( ! memcmp ( & V_124 -> V_129 , & F_51 ( V_113 ) -> V_143 ,
sizeof( struct V_145 ) ) ) &&
( ! memcmp ( & V_124 -> V_130 , & F_51 ( V_113 ) -> V_144 ,
sizeof( struct V_145 ) ) ) )
return true ;
return false ;
}
static struct V_91 * F_71 ( struct V_36 * V_37 ,
const struct V_112 * V_113 )
{
struct V_91 * V_91 ;
struct V_104 * V_148 ;
T_3 V_105 = F_66 ( V_113 ) ;
T_3 V_106 = F_64 ( V_113 ) ;
V_148 = F_46 ( V_37 , V_105 , V_106 ) ;
F_72 (arfs_rule, head, hlist) {
if ( V_91 -> V_124 . V_105 == V_105 &&
V_91 -> V_124 . V_106 == V_106 &&
F_70 ( & V_91 -> V_124 , V_113 ) ) {
return V_91 ;
}
}
return NULL ;
}
int F_73 ( struct V_149 * V_150 , const struct V_112 * V_113 ,
T_4 V_151 , T_1 V_100 )
{
struct V_12 * V_13 = F_74 ( V_150 ) ;
struct V_85 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_36 * V_37 ;
struct V_91 * V_91 ;
if ( V_113 -> V_114 != F_49 ( V_115 ) &&
V_113 -> V_114 != F_49 ( V_121 ) )
return - V_152 ;
V_37 = F_52 ( V_33 , F_48 ( V_113 ) , V_113 -> V_114 ) ;
if ( ! V_37 )
return - V_152 ;
F_35 ( & V_33 -> V_90 ) ;
V_91 = F_71 ( V_37 , V_113 ) ;
if ( V_91 ) {
if ( V_91 -> V_99 == V_151 ) {
F_41 ( & V_33 -> V_90 ) ;
return V_91 -> V_101 ;
}
V_91 -> V_99 = V_151 ;
} else {
V_91 = F_67 ( V_13 , V_37 , V_113 ,
V_151 , V_100 ) ;
if ( ! V_91 ) {
F_41 ( & V_33 -> V_90 ) ;
return - V_51 ;
}
}
F_75 ( V_13 -> V_26 . V_33 . V_41 , & V_91 -> V_98 ) ;
F_41 ( & V_33 -> V_90 ) ;
return V_91 -> V_101 ;
}
