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
T_1 * V_16 = V_13 -> V_17 ;
int V_18 = 0 ;
int V_19 ;
int V_20 ;
V_15 . type = V_21 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_15 . V_23 = V_16 [ V_20 ] ;
V_19 = F_1 ( V_20 ) ;
V_18 = F_3 ( V_13 -> V_24 . V_25 . V_26 [ V_19 ] ,
& V_15 ) ;
if ( V_18 ) {
F_4 ( V_13 -> V_27 ,
L_1 ,
V_28 ) ;
return V_18 ;
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
int V_18 = 0 ;
int V_19 ;
int V_20 ;
V_15 . type = V_29 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_15 . V_30 = V_13 -> V_24 . V_31 . V_32 [ V_20 ] . V_30 . V_33 ;
V_19 = F_1 ( V_20 ) ;
V_18 = F_3 ( V_13 -> V_24 . V_25 . V_26 [ V_19 ] ,
& V_15 ) ;
if ( V_18 ) {
F_4 ( V_13 -> V_27 ,
L_2 ,
V_28 , V_18 ) ;
F_2 ( V_13 ) ;
return V_18 ;
}
}
return 0 ;
}
static void F_8 ( struct V_34 * V_35 )
{
F_9 ( V_35 -> V_36 ) ;
F_10 ( & V_35 -> V_30 ) ;
}
void F_11 ( struct V_12 * V_13 )
{
int V_20 ;
if ( ! ( V_13 -> V_27 -> V_37 & V_38 ) )
return;
F_6 ( V_13 ) ;
F_12 ( V_13 -> V_24 . V_31 . V_39 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( ! F_13 ( V_13 -> V_24 . V_31 . V_32 [ V_20 ] . V_30 . V_33 ) )
F_8 ( & V_13 -> V_24 . V_31 . V_32 [ V_20 ] ) ;
}
}
static int F_14 ( struct V_12 * V_13 ,
enum V_2 type )
{
struct V_34 * V_35 = & V_13 -> V_24 . V_31 . V_32 [ type ] ;
struct V_14 V_15 ;
T_2 V_40 = 0 ;
T_1 * V_16 = V_13 -> V_17 ;
T_1 * V_41 ;
T_1 * V_42 ;
int V_18 = 0 ;
V_42 = F_15 ( F_16 ( V_43 ) ) ;
V_41 = F_15 ( F_16 ( V_43 ) ) ;
if ( ! V_42 || ! V_41 ) {
F_4 ( V_13 -> V_27 , L_3 , V_28 ) ;
V_18 = - V_44 ;
goto V_45;
}
V_15 . type = V_21 ;
switch ( type ) {
case V_3 :
V_15 . V_23 = V_16 [ V_4 ] ;
break;
case V_5 :
V_15 . V_23 = V_16 [ V_6 ] ;
break;
case V_7 :
V_15 . V_23 = V_16 [ V_8 ] ;
break;
case V_9 :
V_15 . V_23 = V_16 [ V_10 ] ;
break;
default:
V_18 = - V_11 ;
goto V_45;
}
V_35 -> V_36 = F_17 ( V_35 -> V_30 . V_33 , V_40 ,
V_41 , V_42 ,
V_46 ,
V_47 ,
& V_15 ) ;
if ( F_18 ( V_35 -> V_36 ) ) {
V_18 = F_19 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
F_4 ( V_13 -> V_27 , L_4 ,
V_28 , type ) ;
}
V_45:
F_20 ( V_41 ) ;
F_20 ( V_42 ) ;
return V_18 ;
}
static int F_21 ( struct V_48 * V_30 ,
enum V_2 type )
{
int V_49 = F_16 ( V_50 ) ;
void * V_51 ;
int V_52 = 0 ;
T_1 * V_53 ;
int V_18 ;
T_2 * V_54 ;
V_30 -> V_55 = F_22 ( V_56 ,
sizeof( * V_30 -> V_55 ) , V_57 ) ;
V_53 = F_15 ( V_49 ) ;
if ( ! V_53 || ! V_30 -> V_55 ) {
F_20 ( V_30 -> V_55 ) ;
F_20 ( V_53 ) ;
return - V_44 ;
}
V_54 = F_23 ( V_50 , V_53 , V_41 ) ;
V_51 = F_23 ( V_43 , V_54 ,
V_58 ) ;
F_24 ( V_59 , V_51 , V_60 ) ;
switch ( type ) {
case V_3 :
case V_7 :
F_24 ( V_59 , V_51 , V_61 ) ;
F_24 ( V_59 , V_51 , V_62 ) ;
break;
case V_5 :
case V_9 :
F_24 ( V_59 , V_51 , V_63 ) ;
F_24 ( V_59 , V_51 , V_64 ) ;
break;
default:
V_18 = - V_11 ;
goto V_45;
}
switch ( type ) {
case V_3 :
case V_5 :
F_24 ( V_59 , V_51 ,
V_65 . V_66 . V_67 ) ;
F_24 ( V_59 , V_51 ,
V_68 . V_66 . V_67 ) ;
break;
case V_7 :
case V_9 :
memset ( F_23 ( V_59 , V_51 ,
V_65 . V_69 . V_70 ) ,
0xff , 16 ) ;
memset ( F_23 ( V_59 , V_51 ,
V_68 . V_69 . V_70 ) ,
0xff , 16 ) ;
break;
default:
V_18 = - V_11 ;
goto V_45;
}
F_25 ( V_53 , V_40 , V_71 ) ;
F_25 ( V_53 , V_72 , V_52 ) ;
V_52 += V_73 ;
F_25 ( V_53 , V_74 , V_52 - 1 ) ;
V_30 -> V_55 [ V_30 -> V_75 ] = F_26 ( V_30 -> V_33 , V_53 ) ;
if ( F_18 ( V_30 -> V_55 [ V_30 -> V_75 ] ) )
goto V_18;
V_30 -> V_75 ++ ;
memset ( V_53 , 0 , V_49 ) ;
F_25 ( V_53 , V_72 , V_52 ) ;
V_52 += V_76 ;
F_25 ( V_53 , V_74 , V_52 - 1 ) ;
V_30 -> V_55 [ V_30 -> V_75 ] = F_26 ( V_30 -> V_33 , V_53 ) ;
if ( F_18 ( V_30 -> V_55 [ V_30 -> V_75 ] ) )
goto V_18;
V_30 -> V_75 ++ ;
F_20 ( V_53 ) ;
return 0 ;
V_18:
V_18 = F_19 ( V_30 -> V_55 [ V_30 -> V_75 ] ) ;
V_30 -> V_55 [ V_30 -> V_75 ] = NULL ;
V_45:
F_20 ( V_53 ) ;
return V_18 ;
}
static int F_27 ( struct V_12 * V_13 ,
enum V_2 type )
{
struct V_77 * V_31 = & V_13 -> V_24 . V_31 ;
struct V_48 * V_30 = & V_31 -> V_32 [ type ] . V_30 ;
int V_18 ;
V_30 -> V_33 = F_28 ( V_13 -> V_24 . V_78 , V_79 ,
V_80 , V_81 ) ;
if ( F_18 ( V_30 -> V_33 ) ) {
V_18 = F_19 ( V_30 -> V_33 ) ;
V_30 -> V_33 = NULL ;
return V_18 ;
}
V_18 = F_21 ( V_30 , type ) ;
if ( V_18 )
goto V_18;
V_18 = F_14 ( V_13 , type ) ;
if ( V_18 )
goto V_18;
return 0 ;
V_18:
F_10 ( V_30 ) ;
return V_18 ;
}
int F_29 ( struct V_12 * V_13 )
{
int V_18 = 0 ;
int V_20 ;
if ( ! ( V_13 -> V_27 -> V_37 & V_38 ) )
return 0 ;
F_30 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_31 ( & V_13 -> V_24 . V_31 . V_26 ) ;
V_13 -> V_24 . V_31 . V_39 = F_32 ( L_5 ) ;
if ( ! V_13 -> V_24 . V_31 . V_39 )
return - V_44 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_18 = F_27 ( V_13 , V_20 ) ;
if ( V_18 )
goto V_18;
}
return 0 ;
V_18:
F_11 ( V_13 ) ;
return V_18 ;
}
static void F_33 ( struct V_12 * V_13 )
{
struct V_83 * V_83 ;
struct V_84 * V_85 ;
int V_86 = 0 ;
int V_20 ;
int V_87 ;
F_34 ( V_88 ) ;
F_35 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_36 (arfs_rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
if ( V_86 ++ > V_89 )
break;
if ( ! F_37 ( & V_83 -> V_90 ) &&
F_38 ( V_13 -> V_27 ,
V_83 -> V_91 , V_83 -> V_92 ,
V_83 -> V_93 ) ) {
F_39 ( & V_83 -> V_94 ) ;
F_40 ( & V_83 -> V_94 , & V_88 ) ;
}
}
F_41 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_42 (arfs_rule, htmp, &del_list, hlist) {
if ( V_83 -> V_95 )
F_9 ( V_83 -> V_95 ) ;
F_43 ( & V_83 -> V_94 ) ;
F_44 ( V_83 ) ;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_84 * V_85 ;
struct V_83 * V_95 ;
int V_20 ;
int V_87 ;
F_34 ( V_88 ) ;
F_35 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_36 (rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
F_39 ( & V_95 -> V_94 ) ;
F_40 ( & V_95 -> V_94 , & V_88 ) ;
}
F_41 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_42 (rule, htmp, &del_list, hlist) {
F_45 ( & V_95 -> V_90 ) ;
if ( V_95 -> V_95 )
F_9 ( V_95 -> V_95 ) ;
F_43 ( & V_95 -> V_94 ) ;
F_44 ( V_95 ) ;
}
}
static struct V_96 *
F_46 ( struct V_34 * V_35 , T_3 V_97 ,
T_3 V_98 )
{
unsigned long V_99 ;
int V_100 ;
V_99 = ( V_101 unsigned long ) V_97 |
( ( V_101 unsigned long ) V_98 << 2 ) ;
V_100 = F_47 ( V_99 , V_102 ) ;
return & V_35 -> V_103 [ V_100 ] ;
}
static T_2 F_48 ( const struct V_104 * V_105 )
{
return ( V_105 -> V_106 == F_49 ( V_107 ) ) ?
F_50 ( V_105 ) -> V_106 : F_51 ( V_105 ) -> V_108 ;
}
static struct V_34 * F_52 ( struct V_77 * V_31 ,
T_2 V_109 , T_3 V_110 )
{
if ( V_110 == F_49 ( V_107 ) && V_109 == V_111 )
return & V_31 -> V_32 [ V_3 ] ;
if ( V_110 == F_49 ( V_107 ) && V_109 == V_112 )
return & V_31 -> V_32 [ V_5 ] ;
if ( V_110 == F_49 ( V_113 ) && V_109 == V_111 )
return & V_31 -> V_32 [ V_7 ] ;
if ( V_110 == F_49 ( V_113 ) && V_109 == V_112 )
return & V_31 -> V_32 [ V_9 ] ;
return NULL ;
}
static struct V_114 * F_53 ( struct V_12 * V_13 ,
struct V_83 * V_83 )
{
struct V_77 * V_31 = & V_13 -> V_24 . V_31 ;
struct V_115 * V_116 = & V_83 -> V_116 ;
struct V_114 * V_95 = NULL ;
struct V_14 V_15 ;
struct V_34 * V_34 ;
T_2 V_40 = 0 ;
struct V_117 * V_30 ;
T_1 * V_41 ;
T_1 * V_42 ;
int V_18 = 0 ;
V_42 = F_15 ( F_16 ( V_43 ) ) ;
V_41 = F_15 ( F_16 ( V_43 ) ) ;
if ( ! V_42 || ! V_41 ) {
F_4 ( V_13 -> V_27 , L_3 , V_28 ) ;
V_18 = - V_44 ;
goto V_45;
}
V_40 = V_71 ;
F_24 ( V_43 , V_41 ,
V_58 . V_60 ) ;
F_54 ( V_43 , V_42 , V_58 . V_60 ,
F_55 ( V_116 -> V_110 ) ) ;
V_34 = F_52 ( V_31 , V_116 -> V_109 , V_116 -> V_110 ) ;
if ( ! V_34 ) {
V_18 = - V_11 ;
goto V_45;
}
V_30 = V_34 -> V_30 . V_33 ;
if ( V_116 -> V_109 == V_111 ) {
F_24 ( V_43 , V_41 ,
V_58 . V_61 ) ;
F_24 ( V_43 , V_41 ,
V_58 . V_62 ) ;
F_54 ( V_43 , V_42 , V_58 . V_61 ,
F_55 ( V_116 -> V_98 ) ) ;
F_54 ( V_43 , V_42 , V_58 . V_62 ,
F_55 ( V_116 -> V_97 ) ) ;
} else {
F_24 ( V_43 , V_41 ,
V_58 . V_63 ) ;
F_24 ( V_43 , V_41 ,
V_58 . V_64 ) ;
F_54 ( V_43 , V_42 , V_58 . V_63 ,
F_55 ( V_116 -> V_98 ) ) ;
F_54 ( V_43 , V_42 , V_58 . V_64 ,
F_55 ( V_116 -> V_97 ) ) ;
}
if ( V_116 -> V_110 == F_49 ( V_107 ) ) {
memcpy ( F_23 ( V_43 , V_42 ,
V_58 . V_65 . V_66 . V_67 ) ,
& V_116 -> V_118 ,
4 ) ;
memcpy ( F_23 ( V_43 , V_42 ,
V_58 . V_68 . V_66 . V_67 ) ,
& V_116 -> V_119 ,
4 ) ;
F_24 ( V_43 , V_41 ,
V_58 . V_65 . V_66 . V_67 ) ;
F_24 ( V_43 , V_41 ,
V_58 . V_68 . V_66 . V_67 ) ;
} else {
memcpy ( F_23 ( V_43 , V_42 ,
V_58 . V_65 . V_69 . V_70 ) ,
& V_116 -> V_120 ,
16 ) ;
memcpy ( F_23 ( V_43 , V_42 ,
V_58 . V_68 . V_69 . V_70 ) ,
& V_116 -> V_121 ,
16 ) ;
memset ( F_23 ( V_43 , V_41 ,
V_58 . V_65 . V_69 . V_70 ) ,
0xff ,
16 ) ;
memset ( F_23 ( V_43 , V_41 ,
V_58 . V_68 . V_69 . V_70 ) ,
0xff ,
16 ) ;
}
V_15 . type = V_21 ;
V_15 . V_23 = V_13 -> V_122 [ V_83 -> V_91 ] . V_16 ;
V_95 = F_17 ( V_30 , V_40 , V_41 ,
V_42 , V_46 ,
V_47 ,
& V_15 ) ;
if ( F_18 ( V_95 ) ) {
V_18 = F_19 ( V_95 ) ;
F_4 ( V_13 -> V_27 , L_6 ,
V_28 , V_83 -> V_93 , V_83 -> V_91 , V_18 ) ;
}
V_45:
F_20 ( V_41 ) ;
F_20 ( V_42 ) ;
return V_18 ? F_56 ( V_18 ) : V_95 ;
}
static void F_57 ( struct V_12 * V_13 ,
struct V_114 * V_95 , T_4 V_91 )
{
struct V_14 V_123 ;
int V_18 = 0 ;
V_123 . type = V_21 ;
V_123 . V_23 = V_13 -> V_122 [ V_91 ] . V_16 ;
V_18 = F_3 ( V_95 , & V_123 ) ;
if ( V_18 )
F_58 ( V_13 -> V_27 ,
L_7 , V_91 ) ;
}
static void F_59 ( struct V_124 * V_125 )
{
struct V_83 * V_83 = F_60 ( V_125 ,
struct V_83 ,
V_90 ) ;
struct V_12 * V_13 = V_83 -> V_13 ;
struct V_114 * V_95 ;
F_61 ( & V_13 -> V_126 ) ;
if ( ! F_62 ( V_127 , & V_13 -> V_128 ) ) {
F_35 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_43 ( & V_83 -> V_94 ) ;
F_41 ( & V_13 -> V_24 . V_31 . V_82 ) ;
F_63 ( & V_13 -> V_126 ) ;
F_44 ( V_83 ) ;
goto V_45;
}
F_63 ( & V_13 -> V_126 ) ;
if ( ! V_83 -> V_95 ) {
V_95 = F_53 ( V_13 , V_83 ) ;
if ( F_18 ( V_95 ) )
goto V_45;
V_83 -> V_95 = V_95 ;
} else {
F_57 ( V_13 , V_83 -> V_95 ,
V_83 -> V_91 ) ;
}
V_45:
F_33 ( V_13 ) ;
}
static T_3 F_64 ( const struct V_104 * V_105 )
{
char * V_129 ;
V_129 = F_65 ( V_105 ) ;
if ( F_48 ( V_105 ) == V_111 )
return ( (struct V_130 * ) V_129 ) -> V_15 ;
return ( (struct V_131 * ) V_129 ) -> V_15 ;
}
static T_3 F_66 ( const struct V_104 * V_105 )
{
char * V_129 ;
V_129 = F_65 ( V_105 ) ;
if ( F_48 ( V_105 ) == V_111 )
return ( (struct V_130 * ) V_129 ) -> V_132 ;
return ( (struct V_131 * ) V_129 ) -> V_132 ;
}
static struct V_83 * F_67 ( struct V_12 * V_13 ,
struct V_34 * V_35 ,
const struct V_104 * V_105 ,
T_4 V_91 , T_1 V_92 )
{
struct V_83 * V_95 ;
struct V_115 * V_116 ;
V_95 = F_68 ( sizeof( * V_95 ) , V_133 ) ;
if ( ! V_95 )
return NULL ;
V_95 -> V_13 = V_13 ;
V_95 -> V_91 = V_91 ;
F_69 ( & V_95 -> V_90 , F_59 ) ;
V_116 = & V_95 -> V_116 ;
V_116 -> V_110 = V_105 -> V_106 ;
if ( V_116 -> V_110 == F_49 ( V_107 ) ) {
V_116 -> V_118 = F_50 ( V_105 ) -> V_134 ;
V_116 -> V_119 = F_50 ( V_105 ) -> V_135 ;
} else {
memcpy ( & V_116 -> V_120 , & F_51 ( V_105 ) -> V_134 ,
sizeof( struct V_136 ) ) ;
memcpy ( & V_116 -> V_121 , & F_51 ( V_105 ) -> V_135 ,
sizeof( struct V_136 ) ) ;
}
V_116 -> V_109 = F_48 ( V_105 ) ;
V_116 -> V_97 = F_66 ( V_105 ) ;
V_116 -> V_98 = F_64 ( V_105 ) ;
V_95 -> V_92 = V_92 ;
V_95 -> V_93 = V_13 -> V_24 . V_31 . V_137 ++ % V_138 ;
F_40 ( & V_95 -> V_94 ,
F_46 ( V_35 , V_116 -> V_97 ,
V_116 -> V_98 ) ) ;
return V_95 ;
}
static bool F_70 ( struct V_115 * V_116 ,
const struct V_104 * V_105 )
{
if ( V_116 -> V_110 == F_49 ( V_107 ) &&
V_116 -> V_118 == F_50 ( V_105 ) -> V_134 &&
V_116 -> V_119 == F_50 ( V_105 ) -> V_135 )
return true ;
if ( V_116 -> V_110 == F_49 ( V_113 ) &&
( ! memcmp ( & V_116 -> V_120 , & F_51 ( V_105 ) -> V_134 ,
sizeof( struct V_136 ) ) ) &&
( ! memcmp ( & V_116 -> V_121 , & F_51 ( V_105 ) -> V_135 ,
sizeof( struct V_136 ) ) ) )
return true ;
return false ;
}
static struct V_83 * F_71 ( struct V_34 * V_35 ,
const struct V_104 * V_105 )
{
struct V_83 * V_83 ;
struct V_96 * V_139 ;
T_3 V_97 = F_66 ( V_105 ) ;
T_3 V_98 = F_64 ( V_105 ) ;
V_139 = F_46 ( V_35 , V_97 , V_98 ) ;
F_72 (arfs_rule, head, hlist) {
if ( V_83 -> V_116 . V_97 == V_97 &&
V_83 -> V_116 . V_98 == V_98 &&
F_70 ( & V_83 -> V_116 , V_105 ) ) {
return V_83 ;
}
}
return NULL ;
}
int F_73 ( struct V_140 * V_141 , const struct V_104 * V_105 ,
T_4 V_142 , T_1 V_92 )
{
struct V_12 * V_13 = F_74 ( V_141 ) ;
struct V_77 * V_31 = & V_13 -> V_24 . V_31 ;
struct V_34 * V_35 ;
struct V_83 * V_83 ;
if ( V_105 -> V_106 != F_49 ( V_107 ) &&
V_105 -> V_106 != F_49 ( V_113 ) )
return - V_143 ;
V_35 = F_52 ( V_31 , F_48 ( V_105 ) , V_105 -> V_106 ) ;
if ( ! V_35 )
return - V_143 ;
F_35 ( & V_31 -> V_82 ) ;
V_83 = F_71 ( V_35 , V_105 ) ;
if ( V_83 ) {
if ( V_83 -> V_91 == V_142 ) {
F_41 ( & V_31 -> V_82 ) ;
return V_83 -> V_93 ;
}
V_83 -> V_91 = V_142 ;
} else {
V_83 = F_67 ( V_13 , V_35 , V_105 ,
V_142 , V_92 ) ;
if ( ! V_83 ) {
F_41 ( & V_31 -> V_82 ) ;
return - V_44 ;
}
}
F_75 ( V_13 -> V_24 . V_31 . V_39 , & V_83 -> V_90 ) ;
F_41 ( & V_31 -> V_82 ) ;
return V_83 -> V_93 ;
}
