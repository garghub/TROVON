void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
memset ( & V_2 -> V_3 . V_4 , 0xFF , V_5 ) ;
F_2 ( & V_2 -> V_6 . V_7 ) ;
F_2 ( & V_2 -> V_6 . V_8 ) ;
F_2 ( & V_2 -> V_6 . V_9 ) ;
F_3 ( V_2 -> V_10 ) ;
F_3 ( V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_12 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 , * V_15 ;
struct V_16 * V_17 , * V_18 ;
struct V_19 * V_20 , * V_21 ;
F_6 (sl, sn, &sec->table.security_levels, list) {
struct V_22 * V_23 ;
V_23 = F_7 ( V_14 , struct V_22 , V_24 ) ;
F_8 ( & V_14 -> V_25 ) ;
F_9 ( V_23 ) ;
}
F_6 (dev, dn, &sec->table.devices, list) {
struct V_26 * V_27 ;
V_27 = F_7 ( V_17 , struct V_26 , V_17 ) ;
F_8 ( & V_17 -> V_25 ) ;
F_10 ( V_27 ) ;
}
F_6 (key, kn, &sec->table.keys, list) {
struct V_28 * V_29 ;
V_29 = F_7 ( V_20 -> V_20 , struct V_28 , V_20 ) ;
F_8 ( & V_20 -> V_25 ) ;
F_11 ( V_29 ) ;
F_9 ( V_20 ) ;
}
}
int F_12 ( struct V_1 * V_2 ,
struct V_30 * V_3 )
{
F_13 ( & V_2 -> V_12 ) ;
* V_3 = V_2 -> V_3 ;
F_14 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
const struct V_30 * V_3 ,
int V_31 )
{
F_16 ( & V_2 -> V_12 ) ;
if ( V_31 & V_32 )
V_2 -> V_3 . V_33 = V_3 -> V_33 ;
if ( V_31 & V_34 )
V_2 -> V_3 . V_35 = V_3 -> V_35 ;
if ( V_31 & V_36 )
V_2 -> V_3 . V_37 = V_3 -> V_37 ;
if ( V_31 & V_38 )
V_2 -> V_3 . V_39 = V_3 -> V_39 ;
if ( V_31 & V_40 )
V_2 -> V_3 . V_4 = V_3 -> V_4 ;
if ( V_31 & V_41 )
V_2 -> V_3 . V_42 = V_3 -> V_42 ;
if ( V_31 & V_43 )
V_2 -> V_3 . V_44 = V_3 -> V_44 ;
if ( V_31 & V_45 )
V_2 -> V_3 . V_46 = V_3 -> V_46 ;
if ( V_31 & V_47 )
V_2 -> V_3 . V_48 = V_3 -> V_48 ;
F_17 ( & V_2 -> V_12 ) ;
return 0 ;
}
static struct V_28 *
F_18 ( const struct V_49 * V_50 )
{
const int V_51 [ 3 ] = { 4 , 8 , 16 } ;
struct V_28 * V_20 ;
int V_52 ;
V_20 = F_19 ( sizeof( * V_20 ) , V_53 ) ;
if ( ! V_20 )
return NULL ;
F_20 ( & V_20 -> V_54 ) ;
V_20 -> V_20 = * V_50 ;
F_21 ( F_22 ( V_51 ) != F_22 ( V_20 -> V_55 ) ) ;
for ( V_52 = 0 ; V_52 < F_22 ( V_20 -> V_55 ) ; V_52 ++ ) {
V_20 -> V_55 [ V_52 ] = F_23 ( L_1 , 0 ,
V_56 ) ;
if ( F_24 ( V_20 -> V_55 [ V_52 ] ) )
goto V_57;
if ( F_25 ( V_20 -> V_55 [ V_52 ] , V_50 -> V_20 ,
V_58 ) )
goto V_57;
if ( F_26 ( V_20 -> V_55 [ V_52 ] , V_51 [ V_52 ] ) )
goto V_57;
}
V_20 -> V_59 = F_27 ( L_2 , 0 , V_56 ) ;
if ( F_24 ( V_20 -> V_59 ) )
goto V_57;
if ( F_28 ( V_20 -> V_59 , V_50 -> V_20 ,
V_58 ) )
goto V_60;
return V_20 ;
V_60:
F_29 ( V_20 -> V_59 ) ;
V_57:
for ( V_52 = 0 ; V_52 < F_22 ( V_20 -> V_55 ) ; V_52 ++ )
if ( V_20 -> V_55 [ V_52 ] )
F_30 ( V_20 -> V_55 [ V_52 ] ) ;
F_9 ( V_20 ) ;
return NULL ;
}
static void F_31 ( struct V_61 * V_54 )
{
struct V_28 * V_20 ;
int V_52 ;
V_20 = F_7 ( V_54 , struct V_28 , V_54 ) ;
for ( V_52 = 0 ; V_52 < F_22 ( V_20 -> V_55 ) ; V_52 ++ )
F_30 ( V_20 -> V_55 [ V_52 ] ) ;
F_29 ( V_20 -> V_59 ) ;
F_9 ( V_20 ) ;
}
static struct V_28 *
F_32 ( struct V_28 * V_20 )
{
F_33 ( & V_20 -> V_54 ) ;
return V_20 ;
}
static void F_11 ( struct V_28 * V_20 )
{
F_34 ( & V_20 -> V_54 , F_31 ) ;
}
static bool F_35 ( const struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
if ( V_63 -> V_65 != V_64 -> V_65 )
return false ;
if ( V_63 -> V_65 == V_66 )
return F_36 ( & V_63 -> V_67 , & V_64 -> V_67 ) ;
if ( V_63 -> V_68 != V_64 -> V_68 )
return false ;
switch ( V_63 -> V_65 ) {
case V_69 :
return true ;
case V_70 :
return V_63 -> V_71 == V_64 -> V_71 ;
case V_72 :
return V_63 -> V_73 == V_64 -> V_73 ;
}
return false ;
}
int F_37 ( struct V_1 * V_2 ,
const struct V_62 * V_68 ,
const struct V_49 * V_20 )
{
struct V_28 * V_29 = NULL ;
struct V_19 * V_74 , * V_75 ;
if ( ! ( V_20 -> V_76 & ( 1 << V_77 ) ) &&
V_20 -> V_78 )
return - V_79 ;
F_38 (pos, &sec->table.keys, list) {
if ( F_35 ( & V_74 -> V_68 , V_68 ) )
return - V_80 ;
if ( memcmp ( V_74 -> V_20 -> V_20 , V_20 -> V_20 ,
V_58 ) )
continue;
V_29 = F_7 ( V_74 -> V_20 , struct V_28 , V_20 ) ;
if ( V_74 -> V_20 -> V_76 != V_20 -> V_76 ||
V_74 -> V_20 -> V_78 != V_20 -> V_78 )
return - V_80 ;
break;
}
V_75 = F_19 ( sizeof( * V_75 ) , V_53 ) ;
if ( ! V_75 )
return - V_81 ;
if ( ! V_29 )
V_29 = F_18 ( V_20 ) ;
else
V_29 = F_32 ( V_29 ) ;
if ( ! V_29 )
goto V_82;
V_75 -> V_68 = * V_68 ;
V_75 -> V_20 = & V_29 -> V_20 ;
F_39 ( & V_75 -> V_25 , & V_2 -> V_6 . V_9 ) ;
return 0 ;
V_82:
F_9 ( V_75 ) ;
return - V_81 ;
}
int F_40 ( struct V_1 * V_2 ,
const struct V_62 * V_20 )
{
struct V_19 * V_74 ;
F_38 (pos, &sec->table.keys, list) {
struct V_28 * V_29 ;
V_29 = F_7 ( V_74 -> V_20 , struct V_28 , V_20 ) ;
if ( F_35 ( & V_74 -> V_68 , V_20 ) ) {
F_41 ( & V_74 -> V_25 ) ;
F_11 ( V_29 ) ;
return 0 ;
}
}
return - V_83 ;
}
static bool F_42 ( T_1 V_84 )
{
return V_84 != F_43 ( V_85 ) &&
V_84 != F_43 ( 0xffff ) ;
}
static T_2 F_44 ( T_1 V_84 , T_1 V_42 )
{
return ( ( V_86 V_87 ) V_84 ) << 16 | ( V_86 V_87 ) V_42 ;
}
static T_3 F_45 ( T_4 V_44 )
{
return ( V_86 T_3 ) V_44 ;
}
static struct V_26 *
F_46 ( struct V_1 * V_2 , T_1 V_84 ,
T_1 V_42 )
{
struct V_26 * V_17 ;
T_2 V_20 = F_44 ( V_84 , V_42 ) ;
F_47 (sec->devices_short, dev, bucket_s, key) {
if ( V_17 -> V_17 . V_84 == V_84 &&
V_17 -> V_17 . V_42 == V_42 )
return V_17 ;
}
return NULL ;
}
static struct V_26 *
F_48 ( struct V_1 * V_2 , T_4 V_44 )
{
struct V_26 * V_17 ;
T_3 V_20 = F_45 ( V_44 ) ;
F_47 (sec->devices_hw, dev, bucket_hw, key) {
if ( V_17 -> V_17 . V_44 == V_44 )
return V_17 ;
}
return NULL ;
}
static void F_10 ( struct V_26 * V_17 )
{
struct V_88 * V_74 , * V_89 ;
struct V_90 * V_91 ;
F_6 (pos, pn, &dev->dev.keys, list) {
V_91 = F_7 ( V_74 , struct V_90 ,
V_91 ) ;
F_8 ( & V_74 -> V_25 ) ;
F_9 ( V_91 ) ;
}
F_9 ( V_17 ) ;
}
int F_49 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_26 * V_92 ;
T_2 V_93 = F_44 ( V_17 -> V_84 , V_17 -> V_42 ) ;
T_3 V_94 = F_45 ( V_17 -> V_44 ) ;
F_21 ( sizeof( V_94 ) != V_5 ) ;
if ( ( F_42 ( V_17 -> V_84 ) &&
F_46 ( V_2 , V_17 -> V_84 , V_17 -> V_42 ) ) ||
F_48 ( V_2 , V_17 -> V_44 ) )
return - V_80 ;
V_92 = F_50 ( sizeof( * V_92 ) , V_53 ) ;
if ( ! V_92 )
return - V_81 ;
V_92 -> V_17 = * V_17 ;
F_51 ( & V_92 -> V_12 ) ;
F_2 ( & V_92 -> V_17 . V_9 ) ;
if ( F_42 ( V_17 -> V_84 ) )
F_52 ( V_2 -> V_10 , & V_92 -> V_95 , V_93 ) ;
else
F_53 ( & V_92 -> V_95 ) ;
F_52 ( V_2 -> V_11 , & V_92 -> V_96 , V_94 ) ;
F_54 ( & V_92 -> V_17 . V_25 , & V_2 -> V_6 . V_8 ) ;
return 0 ;
}
static void F_55 ( struct V_97 * V_98 )
{
F_10 ( F_7 ( V_98 , struct V_26 , V_98 ) ) ;
}
int F_56 ( struct V_1 * V_2 , T_4 V_67 )
{
struct V_26 * V_74 ;
V_74 = F_48 ( V_2 , V_67 ) ;
if ( ! V_74 )
return - V_83 ;
F_57 ( & V_74 -> V_95 ) ;
F_57 ( & V_74 -> V_96 ) ;
F_41 ( & V_74 -> V_17 . V_25 ) ;
F_58 ( & V_74 -> V_98 , F_55 ) ;
return 0 ;
}
static struct V_90 *
F_59 ( struct V_26 * V_17 ,
const struct V_62 * V_20 )
{
struct V_88 * V_91 ;
F_60 (devkey, &dev->dev.keys, list) {
if ( ! F_35 ( V_20 , & V_91 -> V_99 ) )
continue;
return F_7 ( V_91 , struct V_90 ,
V_91 ) ;
}
return NULL ;
}
int F_61 ( struct V_1 * V_2 ,
T_4 V_100 ,
const struct V_88 * V_20 )
{
struct V_26 * V_17 ;
struct V_90 * V_91 ;
V_17 = F_48 ( V_2 , V_100 ) ;
if ( ! V_17 )
return - V_83 ;
if ( F_59 ( V_17 , & V_20 -> V_99 ) )
return - V_80 ;
V_91 = F_50 ( sizeof( * V_91 ) , V_53 ) ;
if ( ! V_91 )
return - V_81 ;
V_91 -> V_91 = * V_20 ;
F_54 ( & V_91 -> V_91 . V_25 , & V_17 -> V_17 . V_9 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
T_4 V_100 ,
const struct V_88 * V_20 )
{
struct V_26 * V_17 ;
struct V_90 * V_91 ;
V_17 = F_48 ( V_2 , V_100 ) ;
if ( ! V_17 )
return - V_83 ;
V_91 = F_59 ( V_17 , & V_20 -> V_99 ) ;
if ( ! V_91 )
return - V_83 ;
F_41 ( & V_91 -> V_91 . V_25 ) ;
F_63 ( V_91 , V_98 ) ;
return 0 ;
}
static struct V_22 *
F_64 ( const struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_13 * V_74 ;
F_38 (pos, &sec->table.security_levels, list) {
if ( V_74 -> V_101 != V_14 -> V_101 ||
( V_74 -> V_101 == V_77 &&
V_74 -> V_102 != V_14 -> V_102 ) ||
V_74 -> V_103 != V_14 -> V_103 ||
V_74 -> V_104 != V_14 -> V_104 )
continue;
return F_7 ( V_74 , struct V_22 ,
V_24 ) ;
}
return NULL ;
}
int F_65 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_22 * V_92 ;
if ( F_64 ( V_2 , V_14 ) )
return - V_80 ;
V_92 = F_50 ( sizeof( * V_92 ) , V_53 ) ;
if ( ! V_92 )
return - V_81 ;
V_92 -> V_24 = * V_14 ;
F_54 ( & V_92 -> V_24 . V_25 , & V_2 -> V_6 . V_7 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_22 * V_74 ;
V_74 = F_64 ( V_2 , V_14 ) ;
if ( ! V_74 )
return - V_83 ;
F_41 ( & V_74 -> V_24 . V_25 ) ;
F_63 ( V_74 , V_98 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
T_1 V_107 = V_2 -> V_3 . V_48 ;
V_106 -> V_42 = V_2 -> V_3 . V_42 ;
if ( V_107 == F_43 ( V_108 ) ) {
return - V_79 ;
} else if ( V_107 == F_43 ( V_85 ) ) {
V_106 -> V_109 = V_2 -> V_3 . V_46 ;
V_106 -> V_65 = V_110 ;
} else {
V_106 -> V_84 = V_2 -> V_3 . V_48 ;
V_106 -> V_65 = V_111 ;
}
return 0 ;
}
static struct V_28 *
F_68 ( struct V_1 * V_2 ,
const struct V_112 * V_113 ,
const struct V_105 * V_106 ,
struct V_62 * V_99 )
{
struct V_105 V_114 = * V_106 ;
T_5 V_115 = V_113 -> V_2 . V_115 ;
struct V_19 * V_116 ;
struct V_28 * V_20 ;
if ( V_115 == V_66 &&
V_114 . V_65 == V_117 ) {
if ( V_113 -> V_118 . type == V_119 ) {
V_114 . V_109 = V_2 -> V_3 . V_46 ;
V_114 . V_65 = V_110 ;
} else if ( F_67 ( V_2 , & V_114 ) < 0 ) {
return NULL ;
}
}
F_60 (key_entry, &sec->table.keys, list) {
const struct V_62 * V_68 = & V_116 -> V_68 ;
if ( ! ( V_116 -> V_20 -> V_76 & F_69 ( V_113 -> V_118 . type ) ) )
continue;
if ( V_68 -> V_65 != V_115 )
continue;
if ( V_115 == V_66 ) {
if ( F_36 ( & V_114 , & V_68 -> V_67 ) )
goto V_120;
} else {
if ( V_68 -> V_68 != V_113 -> V_2 . V_99 )
continue;
if ( ( V_115 == V_69 ) ||
( V_115 == V_70 &&
V_68 -> V_71 == V_113 -> V_2 . V_121 ) ||
( V_115 == V_72 &&
V_68 -> V_73 == V_113 -> V_2 . V_122 ) )
goto V_120;
}
}
return NULL ;
V_120:
V_20 = F_7 ( V_116 -> V_20 , struct V_28 , V_20 ) ;
if ( V_99 )
* V_99 = V_116 -> V_68 ;
return F_32 ( V_20 ) ;
}
static void F_70 ( T_5 V_123 [ 16 ] , T_4 V_106 ,
const struct V_124 * V_2 )
{
T_6 V_125 = ( V_86 T_6 ) F_71 ( ( V_86 T_3 ) V_106 ) ;
T_7 V_35 = ( V_86 T_7 ) F_72 ( ( V_86 T_2 ) V_2 -> V_35 ) ;
V_123 [ 0 ] = 1 ;
memcpy ( V_123 + 1 , & V_125 , sizeof( V_125 ) ) ;
memcpy ( V_123 + 9 , & V_35 , sizeof( V_35 ) ) ;
V_123 [ 13 ] = V_2 -> V_24 ;
V_123 [ 14 ] = 0 ;
V_123 [ 15 ] = 1 ;
}
static int
F_73 ( struct V_126 * V_127 , const struct V_1 * V_2 ,
const struct V_112 * V_113 ,
struct V_28 * V_20 )
{
T_5 V_123 [ 16 ] ;
struct V_128 V_129 ;
struct V_130 V_131 = {
. V_55 = V_20 -> V_59 ,
. V_132 = V_123 ,
. V_133 = 0 ,
} ;
F_70 ( V_123 , V_2 -> V_3 . V_44 , & V_113 -> V_2 ) ;
F_74 ( & V_129 , V_127 -> V_134 , V_127 -> V_135 ) ;
return F_75 ( & V_131 , & V_129 , & V_129 , V_127 -> V_135 ) ;
}
static struct V_136 *
F_76 ( struct V_28 * V_20 , int V_137 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < F_22 ( V_20 -> V_55 ) ; V_52 ++ )
if ( F_77 ( V_20 -> V_55 [ V_52 ] ) == V_137 )
return V_20 -> V_55 [ V_52 ] ;
F_78 () ;
}
static int
F_79 ( struct V_126 * V_127 , const struct V_1 * V_2 ,
const struct V_112 * V_113 ,
struct V_28 * V_20 )
{
T_5 V_123 [ 16 ] ;
unsigned char * V_134 ;
int V_137 , V_138 , V_139 , V_140 ;
struct V_128 V_141 ;
struct V_142 * V_131 ;
V_137 = F_80 ( & V_113 -> V_2 ) ;
F_70 ( V_123 , V_2 -> V_3 . V_44 , & V_113 -> V_2 ) ;
V_131 = F_81 ( F_76 ( V_20 , V_137 ) , V_143 ) ;
if ( ! V_131 )
return - V_81 ;
V_138 = V_127 -> V_144 ;
V_134 = F_82 ( V_127 ) + V_127 -> V_144 ;
V_139 = F_83 ( V_127 ) - V_134 ;
F_84 ( V_127 , V_137 ) ;
F_74 ( & V_141 , F_82 ( V_127 ) , V_138 + V_139 + V_137 ) ;
if ( ! ( V_113 -> V_2 . V_24 & V_145 ) ) {
V_138 += V_139 ;
V_139 = 0 ;
}
F_85 ( V_131 , 0 , NULL , NULL ) ;
F_86 ( V_131 , & V_141 , & V_141 , V_139 , V_123 ) ;
F_87 ( V_131 , V_138 ) ;
V_140 = F_88 ( V_131 ) ;
F_9 ( V_131 ) ;
return V_140 ;
}
static int F_89 ( struct V_126 * V_127 ,
const struct V_1 * V_2 ,
const struct V_112 * V_113 ,
struct V_28 * V_20 )
{
if ( V_113 -> V_2 . V_24 == V_145 )
return F_73 ( V_127 , V_2 , V_113 , V_20 ) ;
else
return F_79 ( V_127 , V_2 , V_113 , V_20 ) ;
}
int F_90 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_112 V_113 ;
int V_140 , V_137 , V_146 ;
struct V_28 * V_20 ;
T_2 V_147 ;
V_146 = F_91 ( V_127 , & V_113 ) ;
if ( V_146 < 0 || V_113 . V_118 . type != V_148 )
return - V_79 ;
if ( ! V_113 . V_118 . V_149 || V_113 . V_2 . V_24 == 0 ) {
F_92 ( V_127 , V_146 ) ;
return 0 ;
}
V_137 = F_80 ( & V_113 . V_2 ) ;
if ( V_127 -> V_135 + V_146 + V_137 + V_150 > V_151 )
return - V_152 ;
F_93 () ;
F_13 ( & V_2 -> V_12 ) ;
if ( ! V_2 -> V_3 . V_33 ) {
V_140 = - V_79 ;
goto V_153;
}
V_20 = F_68 ( V_2 , & V_113 , & V_113 . V_154 , NULL ) ;
if ( ! V_20 ) {
V_140 = - V_155 ;
goto V_153;
}
F_14 ( & V_2 -> V_12 ) ;
F_16 ( & V_2 -> V_12 ) ;
V_147 = F_94 ( V_2 -> V_3 . V_35 ) ;
V_113 . V_2 . V_35 = F_95 ( V_147 ) ;
if ( V_147 == 0xFFFFFFFF ) {
F_17 ( & V_2 -> V_12 ) ;
F_11 ( V_20 ) ;
V_140 = - V_156 ;
goto V_82;
}
V_2 -> V_3 . V_35 = F_96 ( V_147 + 1 ) ;
F_17 ( & V_2 -> V_12 ) ;
F_97 () ;
V_127 -> V_144 = F_98 ( V_127 , & V_113 ) ;
F_99 ( V_127 ) ;
V_140 = F_89 ( V_127 , V_2 , & V_113 , V_20 ) ;
F_11 ( V_20 ) ;
return V_140 ;
V_153:
F_14 ( & V_2 -> V_12 ) ;
V_82:
F_97 () ;
return V_140 ;
}
static struct V_26 *
F_100 ( struct V_1 * V_2 ,
const struct V_105 * V_106 )
{
struct V_105 V_114 = * V_106 ;
struct V_26 * V_17 = NULL ;
if ( V_114 . V_65 == V_117 &&
F_67 ( V_2 , & V_114 ) < 0 )
return NULL ;
if ( V_114 . V_65 == V_111 ) {
T_2 V_20 = F_44 ( V_114 . V_84 ,
V_114 . V_42 ) ;
F_47 (sec->devices_short, dev,
bucket_s, key) {
if ( V_17 -> V_17 . V_42 == V_114 . V_42 &&
V_17 -> V_17 . V_84 == V_114 . V_84 )
return V_17 ;
}
} else {
T_3 V_20 = F_45 ( V_114 . V_109 ) ;
F_47 (sec->devices_hw, dev,
bucket_hw, key) {
if ( V_17 -> V_17 . V_44 == V_114 . V_109 )
return V_17 ;
}
}
return NULL ;
}
static int
F_101 ( const struct V_1 * V_2 ,
T_5 V_101 , T_5 V_102 ,
struct V_13 * V_157 )
{
struct V_13 * V_24 ;
F_60 (level, &sec->table.security_levels, list) {
if ( V_24 -> V_101 == V_101 &&
( V_101 != V_77 ||
V_24 -> V_102 == V_102 ) ) {
* V_157 = * V_24 ;
return 0 ;
}
}
return - V_79 ;
}
static int
F_102 ( struct V_126 * V_127 , const struct V_1 * V_2 ,
const struct V_112 * V_113 ,
struct V_28 * V_20 , T_4 V_100 )
{
T_5 V_123 [ 16 ] ;
unsigned char * V_134 ;
int V_139 ;
struct V_128 V_129 ;
struct V_130 V_131 = {
. V_55 = V_20 -> V_59 ,
. V_132 = V_123 ,
. V_133 = 0 ,
} ;
F_70 ( V_123 , V_100 , & V_113 -> V_2 ) ;
V_134 = F_82 ( V_127 ) + V_127 -> V_144 ;
V_139 = F_83 ( V_127 ) - V_134 ;
F_74 ( & V_129 , V_134 , V_139 ) ;
return F_103 ( & V_131 , & V_129 , & V_129 , V_139 ) ;
}
static int
F_104 ( struct V_126 * V_127 , const struct V_1 * V_2 ,
const struct V_112 * V_113 ,
struct V_28 * V_20 , T_4 V_100 )
{
T_5 V_123 [ 16 ] ;
unsigned char * V_134 ;
int V_137 , V_139 , V_138 , V_140 ;
struct V_128 V_141 ;
struct V_142 * V_131 ;
V_137 = F_80 ( & V_113 -> V_2 ) ;
F_70 ( V_123 , V_100 , & V_113 -> V_2 ) ;
V_131 = F_81 ( F_76 ( V_20 , V_137 ) , V_143 ) ;
if ( ! V_131 )
return - V_81 ;
V_138 = V_127 -> V_144 ;
V_134 = F_82 ( V_127 ) + V_127 -> V_144 ;
V_139 = F_83 ( V_127 ) - V_134 ;
F_74 ( & V_141 , F_82 ( V_127 ) , V_138 + V_139 ) ;
if ( ! ( V_113 -> V_2 . V_24 & V_145 ) ) {
V_138 += V_139 - V_137 ;
V_139 = V_137 ;
}
F_85 ( V_131 , 0 , NULL , NULL ) ;
F_86 ( V_131 , & V_141 , & V_141 , V_139 , V_123 ) ;
F_87 ( V_131 , V_138 ) ;
V_140 = F_105 ( V_131 ) ;
F_9 ( V_131 ) ;
F_106 ( V_127 , V_127 -> V_135 - V_137 ) ;
return V_140 ;
}
static int
F_107 ( struct V_126 * V_127 , const struct V_1 * V_2 ,
const struct V_112 * V_113 ,
struct V_28 * V_20 , T_4 V_100 )
{
if ( V_113 -> V_2 . V_24 == V_145 )
return F_102 ( V_127 , V_2 , V_113 , V_20 , V_100 ) ;
else
return F_104 ( V_127 , V_2 , V_113 , V_20 , V_100 ) ;
}
static int
F_108 ( struct V_26 * V_17 ,
const struct V_62 * V_158 )
{
struct V_90 * V_91 ;
V_91 = F_59 ( V_17 , V_158 ) ;
if ( ! V_91 ) {
struct V_90 * V_159 ;
V_159 = F_19 ( sizeof( * V_91 ) , V_143 ) ;
if ( ! V_159 )
return - V_81 ;
V_159 -> V_91 . V_99 = * V_158 ;
F_109 ( & V_17 -> V_12 ) ;
V_91 = F_59 ( V_17 , V_158 ) ;
if ( ! V_91 )
F_39 ( & V_159 -> V_91 . V_25 , & V_17 -> V_17 . V_9 ) ;
else
F_9 ( V_159 ) ;
F_110 ( & V_17 -> V_12 ) ;
}
return 0 ;
}
static int
F_111 ( struct V_26 * V_17 ,
const struct V_62 * V_158 ,
T_2 V_35 )
{
struct V_90 * V_91 = NULL ;
if ( V_17 -> V_17 . V_160 == V_161 ) {
V_91 = F_59 ( V_17 , V_158 ) ;
if ( ! V_91 )
return - V_83 ;
}
if ( V_17 -> V_17 . V_160 == V_162 ) {
int V_140 = F_108 ( V_17 , V_158 ) ;
if ( V_140 < 0 )
return V_140 ;
}
F_109 ( & V_17 -> V_12 ) ;
if ( ( ! V_91 && V_35 < V_17 -> V_17 . V_35 ) ||
( V_91 && V_35 < V_91 -> V_91 . V_35 ) ) {
F_110 ( & V_17 -> V_12 ) ;
return - V_79 ;
}
if ( V_91 )
V_91 -> V_91 . V_35 = V_35 + 1 ;
else
V_17 -> V_17 . V_35 = V_35 + 1 ;
F_110 ( & V_17 -> V_12 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_112 V_113 ;
struct V_28 * V_20 ;
struct V_62 V_99 ;
struct V_26 * V_17 ;
struct V_13 V_163 ;
int V_164 ;
T_4 V_100 ;
T_2 V_147 ;
if ( F_113 ( V_127 , & V_113 ) < 0 )
return - V_79 ;
if ( ! V_113 . V_118 . V_149 )
return 0 ;
if ( V_113 . V_118 . V_165 == 0 )
return - V_79 ;
F_13 ( & V_2 -> V_12 ) ;
if ( ! V_2 -> V_3 . V_33 ) {
F_14 ( & V_2 -> V_12 ) ;
return - V_79 ;
}
F_14 ( & V_2 -> V_12 ) ;
F_93 () ;
V_20 = F_68 ( V_2 , & V_113 , & V_113 . V_166 , & V_99 ) ;
if ( ! V_20 ) {
V_164 = - V_155 ;
goto V_82;
}
V_17 = F_100 ( V_2 , & V_113 . V_166 ) ;
if ( ! V_17 ) {
V_164 = - V_79 ;
goto V_167;
}
if ( F_101 ( V_2 , V_113 . V_118 . type , 0 , & V_163 ) < 0 ) {
V_164 = - V_79 ;
goto V_167;
}
if ( ! ( V_163 . V_104 & F_69 ( V_113 . V_2 . V_24 ) ) &&
( V_113 . V_2 . V_24 == 0 && V_163 . V_103 &&
! V_17 -> V_17 . V_168 ) ) {
V_164 = - V_79 ;
goto V_167;
}
V_147 = F_114 ( V_113 . V_2 . V_35 ) ;
if ( V_147 == 0xffffffff ) {
V_164 = - V_156 ;
goto V_167;
}
V_164 = F_111 ( V_17 , & V_99 , V_147 ) ;
if ( V_164 )
goto V_167;
V_100 = V_17 -> V_17 . V_44 ;
F_97 () ;
V_164 = F_107 ( V_127 , V_2 , & V_113 , V_20 , V_100 ) ;
F_11 ( V_20 ) ;
return V_164 ;
V_167:
F_11 ( V_20 ) ;
V_82:
F_97 () ;
return V_164 ;
}
