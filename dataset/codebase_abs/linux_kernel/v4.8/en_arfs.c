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
& V_15 ) ;
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
& V_15 ) ;
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
struct V_14 V_15 ;
struct V_16 * V_17 = V_13 -> V_18 ;
struct V_42 * V_43 ;
int V_19 = 0 ;
V_43 = F_15 ( sizeof( * V_43 ) ) ;
if ( ! V_43 ) {
F_4 ( V_13 -> V_29 , L_3 , V_30 ) ;
V_19 = - V_44 ;
goto V_45;
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
goto V_45;
}
V_37 -> V_38 = F_16 ( V_37 -> V_32 . V_35 , V_43 ,
V_46 ,
V_47 ,
& V_15 ) ;
if ( F_17 ( V_37 -> V_38 ) ) {
V_19 = F_18 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
F_4 ( V_13 -> V_29 , L_4 ,
V_30 , type ) ;
}
V_45:
F_19 ( V_43 ) ;
return V_19 ;
}
static int F_20 ( struct V_48 * V_32 ,
enum V_2 type )
{
int V_49 = F_21 ( V_50 ) ;
void * V_51 ;
int V_52 = 0 ;
T_1 * V_53 ;
int V_19 ;
T_2 * V_54 ;
V_32 -> V_55 = F_22 ( V_56 ,
sizeof( * V_32 -> V_55 ) , V_57 ) ;
V_53 = F_15 ( V_49 ) ;
if ( ! V_53 || ! V_32 -> V_55 ) {
F_19 ( V_32 -> V_55 ) ;
F_19 ( V_53 ) ;
return - V_44 ;
}
V_54 = F_23 ( V_50 , V_53 , V_58 ) ;
V_51 = F_23 ( V_59 , V_54 ,
V_60 ) ;
F_24 ( V_61 , V_51 , V_62 ) ;
switch ( type ) {
case V_3 :
case V_7 :
F_24 ( V_61 , V_51 , V_63 ) ;
F_24 ( V_61 , V_51 , V_64 ) ;
break;
case V_5 :
case V_9 :
F_24 ( V_61 , V_51 , V_65 ) ;
F_24 ( V_61 , V_51 , V_66 ) ;
break;
default:
V_19 = - V_11 ;
goto V_45;
}
switch ( type ) {
case V_3 :
case V_5 :
F_24 ( V_61 , V_51 ,
V_67 . V_68 . V_69 ) ;
F_24 ( V_61 , V_51 ,
V_70 . V_68 . V_69 ) ;
break;
case V_7 :
case V_9 :
memset ( F_23 ( V_61 , V_51 ,
V_67 . V_71 . V_72 ) ,
0xff , 16 ) ;
memset ( F_23 ( V_61 , V_51 ,
V_70 . V_71 . V_72 ) ,
0xff , 16 ) ;
break;
default:
V_19 = - V_11 ;
goto V_45;
}
F_25 ( V_53 , V_73 , V_74 ) ;
F_25 ( V_53 , V_75 , V_52 ) ;
V_52 += V_76 ;
F_25 ( V_53 , V_77 , V_52 - 1 ) ;
V_32 -> V_55 [ V_32 -> V_78 ] = F_26 ( V_32 -> V_35 , V_53 ) ;
if ( F_17 ( V_32 -> V_55 [ V_32 -> V_78 ] ) )
goto V_19;
V_32 -> V_78 ++ ;
memset ( V_53 , 0 , V_49 ) ;
F_25 ( V_53 , V_75 , V_52 ) ;
V_52 += V_79 ;
F_25 ( V_53 , V_77 , V_52 - 1 ) ;
V_32 -> V_55 [ V_32 -> V_78 ] = F_26 ( V_32 -> V_35 , V_53 ) ;
if ( F_17 ( V_32 -> V_55 [ V_32 -> V_78 ] ) )
goto V_19;
V_32 -> V_78 ++ ;
F_19 ( V_53 ) ;
return 0 ;
V_19:
V_19 = F_18 ( V_32 -> V_55 [ V_32 -> V_78 ] ) ;
V_32 -> V_55 [ V_32 -> V_78 ] = NULL ;
V_45:
F_19 ( V_53 ) ;
return V_19 ;
}
static int F_27 ( struct V_12 * V_13 ,
enum V_2 type )
{
struct V_80 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_48 * V_32 = & V_33 -> V_34 [ type ] . V_32 ;
int V_19 ;
V_32 -> V_35 = F_28 ( V_13 -> V_26 . V_81 , V_82 ,
V_83 , V_84 ) ;
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
F_30 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_31 ( & V_13 -> V_26 . V_33 . V_28 ) ;
V_13 -> V_26 . V_33 . V_41 = F_32 ( L_5 ) ;
if ( ! V_13 -> V_26 . V_33 . V_41 )
return - V_44 ;
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
struct V_86 * V_86 ;
struct V_87 * V_88 ;
int V_89 = 0 ;
int V_21 ;
int V_90 ;
F_34 ( V_91 ) ;
F_35 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_36 (arfs_rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
if ( V_89 ++ > V_92 )
break;
if ( ! F_37 ( & V_86 -> V_93 ) &&
F_38 ( V_13 -> V_29 ,
V_86 -> V_94 , V_86 -> V_95 ,
V_86 -> V_96 ) ) {
F_39 ( & V_86 -> V_97 ) ;
F_40 ( & V_86 -> V_97 , & V_91 ) ;
}
}
F_41 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_42 (arfs_rule, htmp, &del_list, hlist) {
if ( V_86 -> V_98 )
F_9 ( V_86 -> V_98 ) ;
F_43 ( & V_86 -> V_97 ) ;
F_44 ( V_86 ) ;
}
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_87 * V_88 ;
struct V_86 * V_98 ;
int V_21 ;
int V_90 ;
F_34 ( V_91 ) ;
F_35 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_36 (rule, htmp, priv->fs.arfs.arfs_tables, i, j) {
F_39 ( & V_98 -> V_97 ) ;
F_40 ( & V_98 -> V_97 , & V_91 ) ;
}
F_41 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_42 (rule, htmp, &del_list, hlist) {
F_45 ( & V_98 -> V_93 ) ;
if ( V_98 -> V_98 )
F_9 ( V_98 -> V_98 ) ;
F_43 ( & V_98 -> V_97 ) ;
F_44 ( V_98 ) ;
}
}
static struct V_99 *
F_46 ( struct V_36 * V_37 , T_3 V_100 ,
T_3 V_101 )
{
unsigned long V_102 ;
int V_103 ;
V_102 = ( V_104 unsigned long ) V_100 |
( ( V_104 unsigned long ) V_101 << 2 ) ;
V_103 = F_47 ( V_102 , V_105 ) ;
return & V_37 -> V_106 [ V_103 ] ;
}
static T_2 F_48 ( const struct V_107 * V_108 )
{
return ( V_108 -> V_109 == F_49 ( V_110 ) ) ?
F_50 ( V_108 ) -> V_109 : F_51 ( V_108 ) -> V_111 ;
}
static struct V_36 * F_52 ( struct V_80 * V_33 ,
T_2 V_112 , T_3 V_113 )
{
if ( V_113 == F_49 ( V_110 ) && V_112 == V_114 )
return & V_33 -> V_34 [ V_3 ] ;
if ( V_113 == F_49 ( V_110 ) && V_112 == V_115 )
return & V_33 -> V_34 [ V_5 ] ;
if ( V_113 == F_49 ( V_116 ) && V_112 == V_114 )
return & V_33 -> V_34 [ V_7 ] ;
if ( V_113 == F_49 ( V_116 ) && V_112 == V_115 )
return & V_33 -> V_34 [ V_9 ] ;
return NULL ;
}
static struct V_117 * F_53 ( struct V_12 * V_13 ,
struct V_86 * V_86 )
{
struct V_80 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_118 * V_119 = & V_86 -> V_119 ;
struct V_117 * V_98 = NULL ;
struct V_14 V_15 ;
struct V_36 * V_36 ;
struct V_42 * V_43 ;
struct V_120 * V_32 ;
int V_19 = 0 ;
V_43 = F_15 ( sizeof( * V_43 ) ) ;
if ( ! V_43 ) {
F_4 ( V_13 -> V_29 , L_3 , V_30 ) ;
V_19 = - V_44 ;
goto V_45;
}
V_43 -> V_73 = V_74 ;
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_62 ) ;
F_54 ( V_59 , V_43 -> V_121 , V_60 . V_62 ,
F_55 ( V_119 -> V_113 ) ) ;
V_36 = F_52 ( V_33 , V_119 -> V_112 , V_119 -> V_113 ) ;
if ( ! V_36 ) {
V_19 = - V_11 ;
goto V_45;
}
V_32 = V_36 -> V_32 . V_35 ;
if ( V_119 -> V_112 == V_114 ) {
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_63 ) ;
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_64 ) ;
F_54 ( V_59 , V_43 -> V_121 , V_60 . V_63 ,
F_55 ( V_119 -> V_101 ) ) ;
F_54 ( V_59 , V_43 -> V_121 , V_60 . V_64 ,
F_55 ( V_119 -> V_100 ) ) ;
} else {
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_65 ) ;
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_66 ) ;
F_54 ( V_59 , V_43 -> V_121 , V_60 . V_65 ,
F_55 ( V_119 -> V_101 ) ) ;
F_54 ( V_59 , V_43 -> V_121 , V_60 . V_66 ,
F_55 ( V_119 -> V_100 ) ) ;
}
if ( V_119 -> V_113 == F_49 ( V_110 ) ) {
memcpy ( F_23 ( V_59 , V_43 -> V_121 ,
V_60 . V_67 . V_68 . V_69 ) ,
& V_119 -> V_122 ,
4 ) ;
memcpy ( F_23 ( V_59 , V_43 -> V_121 ,
V_60 . V_70 . V_68 . V_69 ) ,
& V_119 -> V_123 ,
4 ) ;
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_67 . V_68 . V_69 ) ;
F_24 ( V_59 , V_43 -> V_58 ,
V_60 . V_70 . V_68 . V_69 ) ;
} else {
memcpy ( F_23 ( V_59 , V_43 -> V_121 ,
V_60 . V_67 . V_71 . V_72 ) ,
& V_119 -> V_124 ,
16 ) ;
memcpy ( F_23 ( V_59 , V_43 -> V_121 ,
V_60 . V_70 . V_71 . V_72 ) ,
& V_119 -> V_125 ,
16 ) ;
memset ( F_23 ( V_59 , V_43 -> V_58 ,
V_60 . V_67 . V_71 . V_72 ) ,
0xff ,
16 ) ;
memset ( F_23 ( V_59 , V_43 -> V_58 ,
V_60 . V_70 . V_71 . V_72 ) ,
0xff ,
16 ) ;
}
V_15 . type = V_22 ;
V_15 . V_24 = V_13 -> V_126 [ V_86 -> V_94 ] . V_25 ;
V_98 = F_16 ( V_32 , V_43 , V_46 ,
V_47 ,
& V_15 ) ;
if ( F_17 ( V_98 ) ) {
V_19 = F_18 ( V_98 ) ;
F_4 ( V_13 -> V_29 , L_6 ,
V_30 , V_86 -> V_96 , V_86 -> V_94 , V_19 ) ;
}
V_45:
F_19 ( V_43 ) ;
return V_19 ? F_56 ( V_19 ) : V_98 ;
}
static void F_57 ( struct V_12 * V_13 ,
struct V_117 * V_98 , T_4 V_94 )
{
struct V_14 V_127 ;
int V_19 = 0 ;
V_127 . type = V_22 ;
V_127 . V_24 = V_13 -> V_126 [ V_94 ] . V_25 ;
V_19 = F_3 ( V_98 , & V_127 ) ;
if ( V_19 )
F_58 ( V_13 -> V_29 ,
L_7 , V_94 ) ;
}
static void F_59 ( struct V_128 * V_129 )
{
struct V_86 * V_86 = F_60 ( V_129 ,
struct V_86 ,
V_93 ) ;
struct V_12 * V_13 = V_86 -> V_13 ;
struct V_117 * V_98 ;
F_61 ( & V_13 -> V_130 ) ;
if ( ! F_62 ( V_131 , & V_13 -> V_132 ) ) {
F_35 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_43 ( & V_86 -> V_97 ) ;
F_41 ( & V_13 -> V_26 . V_33 . V_85 ) ;
F_63 ( & V_13 -> V_130 ) ;
F_44 ( V_86 ) ;
goto V_45;
}
F_63 ( & V_13 -> V_130 ) ;
if ( ! V_86 -> V_98 ) {
V_98 = F_53 ( V_13 , V_86 ) ;
if ( F_17 ( V_98 ) )
goto V_45;
V_86 -> V_98 = V_98 ;
} else {
F_57 ( V_13 , V_86 -> V_98 ,
V_86 -> V_94 ) ;
}
V_45:
F_33 ( V_13 ) ;
}
static T_3 F_64 ( const struct V_107 * V_108 )
{
char * V_133 ;
V_133 = F_65 ( V_108 ) ;
if ( F_48 ( V_108 ) == V_114 )
return ( (struct V_134 * ) V_133 ) -> V_15 ;
return ( (struct V_135 * ) V_133 ) -> V_15 ;
}
static T_3 F_66 ( const struct V_107 * V_108 )
{
char * V_133 ;
V_133 = F_65 ( V_108 ) ;
if ( F_48 ( V_108 ) == V_114 )
return ( (struct V_134 * ) V_133 ) -> V_136 ;
return ( (struct V_135 * ) V_133 ) -> V_136 ;
}
static struct V_86 * F_67 ( struct V_12 * V_13 ,
struct V_36 * V_37 ,
const struct V_107 * V_108 ,
T_4 V_94 , T_1 V_95 )
{
struct V_86 * V_98 ;
struct V_118 * V_119 ;
V_98 = F_68 ( sizeof( * V_98 ) , V_137 ) ;
if ( ! V_98 )
return NULL ;
V_98 -> V_13 = V_13 ;
V_98 -> V_94 = V_94 ;
F_69 ( & V_98 -> V_93 , F_59 ) ;
V_119 = & V_98 -> V_119 ;
V_119 -> V_113 = V_108 -> V_109 ;
if ( V_119 -> V_113 == F_49 ( V_110 ) ) {
V_119 -> V_122 = F_50 ( V_108 ) -> V_138 ;
V_119 -> V_123 = F_50 ( V_108 ) -> V_139 ;
} else {
memcpy ( & V_119 -> V_124 , & F_51 ( V_108 ) -> V_138 ,
sizeof( struct V_140 ) ) ;
memcpy ( & V_119 -> V_125 , & F_51 ( V_108 ) -> V_139 ,
sizeof( struct V_140 ) ) ;
}
V_119 -> V_112 = F_48 ( V_108 ) ;
V_119 -> V_100 = F_66 ( V_108 ) ;
V_119 -> V_101 = F_64 ( V_108 ) ;
V_98 -> V_95 = V_95 ;
V_98 -> V_96 = V_13 -> V_26 . V_33 . V_141 ++ % V_142 ;
F_40 ( & V_98 -> V_97 ,
F_46 ( V_37 , V_119 -> V_100 ,
V_119 -> V_101 ) ) ;
return V_98 ;
}
static bool F_70 ( struct V_118 * V_119 ,
const struct V_107 * V_108 )
{
if ( V_119 -> V_113 == F_49 ( V_110 ) &&
V_119 -> V_122 == F_50 ( V_108 ) -> V_138 &&
V_119 -> V_123 == F_50 ( V_108 ) -> V_139 )
return true ;
if ( V_119 -> V_113 == F_49 ( V_116 ) &&
( ! memcmp ( & V_119 -> V_124 , & F_51 ( V_108 ) -> V_138 ,
sizeof( struct V_140 ) ) ) &&
( ! memcmp ( & V_119 -> V_125 , & F_51 ( V_108 ) -> V_139 ,
sizeof( struct V_140 ) ) ) )
return true ;
return false ;
}
static struct V_86 * F_71 ( struct V_36 * V_37 ,
const struct V_107 * V_108 )
{
struct V_86 * V_86 ;
struct V_99 * V_143 ;
T_3 V_100 = F_66 ( V_108 ) ;
T_3 V_101 = F_64 ( V_108 ) ;
V_143 = F_46 ( V_37 , V_100 , V_101 ) ;
F_72 (arfs_rule, head, hlist) {
if ( V_86 -> V_119 . V_100 == V_100 &&
V_86 -> V_119 . V_101 == V_101 &&
F_70 ( & V_86 -> V_119 , V_108 ) ) {
return V_86 ;
}
}
return NULL ;
}
int F_73 ( struct V_144 * V_145 , const struct V_107 * V_108 ,
T_4 V_146 , T_1 V_95 )
{
struct V_12 * V_13 = F_74 ( V_145 ) ;
struct V_80 * V_33 = & V_13 -> V_26 . V_33 ;
struct V_36 * V_37 ;
struct V_86 * V_86 ;
if ( V_108 -> V_109 != F_49 ( V_110 ) &&
V_108 -> V_109 != F_49 ( V_116 ) )
return - V_147 ;
V_37 = F_52 ( V_33 , F_48 ( V_108 ) , V_108 -> V_109 ) ;
if ( ! V_37 )
return - V_147 ;
F_35 ( & V_33 -> V_85 ) ;
V_86 = F_71 ( V_37 , V_108 ) ;
if ( V_86 ) {
if ( V_86 -> V_94 == V_146 ) {
F_41 ( & V_33 -> V_85 ) ;
return V_86 -> V_96 ;
}
V_86 -> V_94 = V_146 ;
} else {
V_86 = F_67 ( V_13 , V_37 , V_108 ,
V_146 , V_95 ) ;
if ( ! V_86 ) {
F_41 ( & V_33 -> V_85 ) ;
return - V_44 ;
}
}
F_75 ( V_13 -> V_26 . V_33 . V_41 , & V_86 -> V_93 ) ;
F_41 ( & V_33 -> V_85 ) ;
return V_86 -> V_96 ;
}
