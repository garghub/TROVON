int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 ==
V_5 )
return 1 << V_6 ;
else
return F_2 ( ( 1 << V_7 ) ,
V_8 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return 4 * ( F_1 ( V_2 ) / 16 - 2 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
T_1 V_11 ,
T_2 * V_12 )
{
T_2 V_13 ;
int V_14 = 0 ;
V_14 = F_5 ( V_2 , V_10 -> V_15 , & V_13 , V_11 , 0 ,
V_16 , V_17 ,
V_18 ) ;
if ( V_14 )
return V_14 ;
* V_12 = V_13 ;
return V_14 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_14 = 0 ;
V_14 = F_7 ( V_2 , V_19 , 0 , 0 ,
V_20 , V_17 ,
V_18 ) ;
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 , int V_21 ,
struct V_9 * V_10 )
{
return F_9 ( V_2 , 0 , V_10 -> V_15 , V_21 , 0 , V_22 ,
V_17 , V_18 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_21 ,
struct V_9 * V_10 )
{
return F_7 ( V_2 , V_10 -> V_15 , V_21 , 0 , V_23 ,
V_17 , V_18 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_3 V_24 , T_3 V_25 ,
struct V_9 * V_10 )
{
T_1 V_26 ;
V_26 = ( T_1 ) V_24 << 16 | V_25 << 1 ;
return F_7 ( V_2 , V_10 -> V_15 , V_26 , 0x1 ,
V_23 , V_17 ,
V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_4 * V_27 , T_3 V_28 )
{
T_2 V_13 ;
int V_14 ;
V_14 = F_5 ( V_2 , V_10 -> V_15 , & V_13 , 0 , V_28 ,
V_29 , V_17 ,
V_18 ) ;
if ( ! V_14 )
* V_27 = V_13 ;
return V_14 ;
}
static struct V_30 * F_13 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 ,
T_1 V_32 )
{
struct V_33 * V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
struct V_30 * V_35 ;
F_15 (pqp, &s_steer->promisc_qps[steer], list) {
if ( V_35 -> V_32 == V_32 )
return V_35 ;
}
return NULL ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 ,
unsigned int V_21 , T_1 V_32 )
{
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_36 * V_37 ;
T_1 V_38 ;
struct V_39 * V_40 ;
struct V_30 * V_35 ;
struct V_30 * V_41 = NULL ;
T_1 V_42 ;
int V_14 ;
V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
V_40 = F_17 ( sizeof *V_40 , V_43 ) ;
if ( ! V_40 )
return - V_44 ;
F_18 ( & V_40 -> V_45 ) ;
V_40 -> V_21 = V_21 ;
F_19 ( & V_40 -> V_46 , & V_34 -> V_47 [ V_25 ] ) ;
V_35 = F_13 ( V_2 , V_24 , V_25 , V_32 ) ;
if ( V_35 ) {
V_41 = F_20 ( sizeof *V_41 , V_43 ) ;
if ( ! V_41 ) {
V_14 = - V_44 ;
goto V_48;
}
V_41 -> V_32 = V_32 ;
F_19 ( & V_41 -> V_46 , & V_40 -> V_45 ) ;
}
if ( F_21 ( & V_34 -> V_49 [ V_25 ] ) )
return 0 ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) ) {
V_14 = - V_44 ;
goto V_48;
}
V_37 = V_10 -> V_50 ;
V_14 = F_8 ( V_2 , V_21 , V_10 ) ;
if ( V_14 )
goto V_51;
V_38 = F_24 ( V_37 -> V_38 ) & 0xffffff ;
V_42 = F_24 ( V_37 -> V_38 ) >> 30 ;
F_15 (pqp, &s_steer->promisc_qps[steer], list) {
if ( V_35 -> V_32 == V_32 )
continue;
if ( V_38 == V_2 -> V_3 . V_52 ) {
V_14 = - V_44 ;
goto V_51;
}
V_37 -> V_53 [ V_38 ++ ] = F_25 ( V_35 -> V_32 & V_54 ) ;
}
V_37 -> V_38 = F_25 ( V_38 | ( V_42 << 30 ) ) ;
V_14 = F_10 ( V_2 , V_21 , V_10 ) ;
V_51:
F_26 ( V_2 , V_10 ) ;
if ( ! V_14 )
return 0 ;
V_48:
if ( V_41 ) {
F_27 ( & V_41 -> V_46 ) ;
F_28 ( V_41 ) ;
}
F_27 ( & V_40 -> V_46 ) ;
F_28 ( V_40 ) ;
return V_14 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 ,
unsigned int V_21 , T_1 V_32 )
{
struct V_33 * V_34 ;
struct V_39 * V_55 , * V_56 = NULL ;
struct V_30 * V_35 ;
struct V_30 * V_41 ;
V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
V_35 = F_13 ( V_2 , V_24 , V_25 , V_32 ) ;
if ( ! V_35 )
return 0 ;
F_15 (tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_55 -> V_21 == V_21 ) {
V_56 = V_55 ;
break;
}
}
if ( F_30 ( ! V_56 ) ) {
F_31 ( V_2 , L_1 , V_21 ) ;
return - V_57 ;
}
F_15 (dqp, &entry->duplicates, list) {
if ( V_32 == V_35 -> V_32 )
return 0 ;
}
V_41 = F_20 ( sizeof *V_41 , V_43 ) ;
if ( ! V_41 )
return - V_44 ;
V_41 -> V_32 = V_32 ;
F_19 ( & V_41 -> V_46 , & V_56 -> V_45 ) ;
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 ,
unsigned int V_21 , T_1 V_32 )
{
struct V_33 * V_34 ;
struct V_39 * V_55 , * V_56 = NULL ;
struct V_30 * V_41 , * V_58 ;
V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
if ( ! F_13 ( V_2 , V_24 , V_25 , V_32 ) )
return false ;
F_15 (tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_55 -> V_21 == V_21 ) {
V_56 = V_55 ;
break;
}
}
if ( F_30 ( ! V_56 ) ) {
F_31 ( V_2 , L_2 , V_21 ) ;
return false ;
}
F_33 (dqp, tmp_dqp, &entry->duplicates, list) {
if ( V_41 -> V_32 == V_32 ) {
F_27 ( & V_41 -> V_46 ) ;
F_28 ( V_41 ) ;
}
}
return true ;
}
static bool F_34 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 ,
unsigned int V_21 , T_1 V_59 )
{
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_36 * V_37 ;
struct V_39 * V_56 = NULL , * V_55 ;
T_1 V_32 ;
T_1 V_38 ;
bool V_60 = false ;
int V_61 ;
V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) )
return false ;
V_37 = V_10 -> V_50 ;
if ( F_8 ( V_2 , V_21 , V_10 ) )
goto V_62;
V_38 = F_24 ( V_37 -> V_38 ) & 0xffffff ;
for ( V_61 = 0 ; V_61 < V_38 ; V_61 ++ ) {
V_32 = F_24 ( V_37 -> V_53 [ V_61 ] ) & V_54 ;
if ( ! F_13 ( V_2 , V_24 , V_25 , V_32 ) && V_32 != V_59 ) {
goto V_62;
}
}
V_60 = true ;
F_33 (entry, tmp_entry, &s_steer->steer_entries[steer], list) {
if ( V_56 -> V_21 == V_21 ) {
if ( F_21 ( & V_56 -> V_45 ) ) {
F_27 ( & V_56 -> V_46 ) ;
F_28 ( V_56 ) ;
} else {
V_60 = false ;
goto V_62;
}
}
}
V_62:
F_26 ( V_2 , V_10 ) ;
return V_60 ;
}
static int F_35 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 , T_1 V_32 )
{
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_36 * V_37 ;
struct V_39 * V_56 ;
struct V_30 * V_35 ;
struct V_30 * V_41 ;
T_1 V_38 ;
T_1 V_42 ;
int V_61 ;
bool V_63 ;
int V_14 ;
struct F_14 * V_64 = F_14 ( V_2 ) ;
V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
F_36 ( & V_64 -> V_65 . V_66 ) ;
if ( F_13 ( V_2 , V_24 , V_25 , V_32 ) ) {
V_14 = 0 ;
goto V_67;
}
V_35 = F_20 ( sizeof *V_35 , V_43 ) ;
if ( ! V_35 ) {
V_14 = - V_44 ;
goto V_67;
}
V_35 -> V_32 = V_32 ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) ) {
V_14 = - V_44 ;
goto V_48;
}
V_37 = V_10 -> V_50 ;
F_15 (entry, &s_steer->steer_entries[steer], list) {
V_14 = F_8 ( V_2 , V_56 -> V_21 , V_10 ) ;
if ( V_14 )
goto V_51;
V_38 = F_24 ( V_37 -> V_38 ) & 0xffffff ;
V_42 = F_24 ( V_37 -> V_38 ) >> 30 ;
V_63 = false ;
for ( V_61 = 0 ; V_61 < V_38 ; V_61 ++ ) {
if ( ( F_24 ( V_37 -> V_53 [ V_61 ] ) & V_54 ) == V_32 ) {
V_41 = F_20 ( sizeof *V_41 , V_43 ) ;
if ( ! V_41 ) {
V_14 = - V_44 ;
goto V_51;
}
V_41 -> V_32 = V_32 ;
F_19 ( & V_41 -> V_46 , & V_56 -> V_45 ) ;
V_63 = true ;
}
}
if ( ! V_63 ) {
if ( V_38 == V_2 -> V_3 . V_52 ) {
V_14 = - V_44 ;
goto V_51;
}
V_37 -> V_53 [ V_38 ++ ] = F_25 ( V_32 & V_54 ) ;
V_37 -> V_38 = F_25 ( V_38 | ( V_42 << 30 ) ) ;
V_14 = F_10 ( V_2 , V_56 -> V_21 , V_10 ) ;
if ( V_14 )
goto V_51;
}
}
F_19 ( & V_35 -> V_46 , & V_34 -> V_49 [ V_25 ] ) ;
memset ( V_37 , 0 , sizeof *V_37 ) ;
V_38 = 0 ;
F_15 (dqp, &s_steer->promisc_qps[steer], list)
V_37 -> V_53 [ V_38 ++ ] = F_25 ( V_41 -> V_32 & V_54 ) ;
V_37 -> V_38 = F_25 ( V_38 | V_68 << 30 ) ;
V_14 = F_11 ( V_2 , V_24 , V_25 , V_10 ) ;
if ( V_14 )
goto V_69;
F_26 ( V_2 , V_10 ) ;
F_37 ( & V_64 -> V_65 . V_66 ) ;
return 0 ;
V_69:
F_27 ( & V_35 -> V_46 ) ;
V_51:
F_26 ( V_2 , V_10 ) ;
V_48:
F_28 ( V_35 ) ;
V_67:
F_37 ( & V_64 -> V_65 . V_66 ) ;
return V_14 ;
}
static int F_38 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_31 V_25 , T_1 V_32 )
{
struct F_14 * V_64 = F_14 ( V_2 ) ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
struct V_36 * V_37 ;
struct V_39 * V_56 ;
struct V_30 * V_35 ;
struct V_30 * V_41 ;
T_1 V_38 ;
bool V_63 ;
bool V_70 = false ;
int V_71 , V_61 ;
int V_14 ;
V_34 = & F_14 ( V_2 ) -> V_25 [ V_24 - 1 ] ;
F_36 ( & V_64 -> V_65 . V_66 ) ;
V_35 = F_13 ( V_2 , V_24 , V_25 , V_32 ) ;
if ( F_30 ( ! V_35 ) ) {
F_31 ( V_2 , L_3 , V_32 ) ;
V_14 = 0 ;
goto V_67;
}
F_27 ( & V_35 -> V_46 ) ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) ) {
V_14 = - V_44 ;
V_70 = true ;
goto V_69;
}
V_37 = V_10 -> V_50 ;
memset ( V_37 , 0 , sizeof *V_37 ) ;
V_38 = 0 ;
F_15 (dqp, &s_steer->promisc_qps[steer], list)
V_37 -> V_53 [ V_38 ++ ] = F_25 ( V_41 -> V_32 & V_54 ) ;
V_37 -> V_38 = F_25 ( V_38 | V_68 << 30 ) ;
V_14 = F_11 ( V_2 , V_24 , V_25 , V_10 ) ;
if ( V_14 )
goto V_51;
F_15 (entry, &s_steer->steer_entries[steer], list) {
V_63 = false ;
F_15 (dqp, &entry->duplicates, list) {
if ( V_41 -> V_32 == V_32 ) {
V_63 = true ;
break;
}
}
if ( V_63 ) {
F_27 ( & V_41 -> V_46 ) ;
F_28 ( V_41 ) ;
} else {
V_14 = F_8 ( V_2 , V_56 -> V_21 , V_10 ) ;
if ( V_14 )
goto V_51;
V_38 = F_24 ( V_37 -> V_38 ) & 0xffffff ;
for ( V_71 = - 1 , V_61 = 0 ; V_61 < V_38 ; ++ V_61 )
if ( ( F_24 ( V_37 -> V_53 [ V_61 ] ) & V_54 ) == V_32 )
V_71 = V_61 ;
V_37 -> V_38 = F_25 ( -- V_38 |
( V_68 << 30 ) ) ;
V_37 -> V_53 [ V_71 ] = V_37 -> V_53 [ V_61 - 1 ] ;
V_37 -> V_53 [ V_61 - 1 ] = 0 ;
V_14 = F_10 ( V_2 , V_56 -> V_21 , V_10 ) ;
if ( V_14 )
goto V_51;
}
}
V_51:
F_26 ( V_2 , V_10 ) ;
V_69:
if ( V_70 )
F_19 ( & V_35 -> V_46 , & V_34 -> V_49 [ V_25 ] ) ;
else
F_28 ( V_35 ) ;
V_67:
F_37 ( & V_64 -> V_65 . V_66 ) ;
return V_14 ;
}
static int F_39 ( struct V_1 * V_2 , T_3 V_24 ,
T_3 * V_72 , enum V_73 V_42 ,
struct V_9 * V_74 ,
int * V_75 , int * V_21 )
{
struct V_9 * V_10 ;
struct V_36 * V_37 = V_74 -> V_50 ;
T_3 * V_76 ;
int V_14 ;
T_4 V_27 ;
T_3 V_28 = ( V_42 == V_68 ) ?
! ! ( V_2 -> V_3 . V_77 & V_78 ) : 0 ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) )
return - V_44 ;
V_76 = V_10 -> V_50 ;
memcpy ( V_76 , V_72 , 16 ) ;
V_14 = F_12 ( V_2 , V_10 , & V_27 , V_28 ) ;
F_26 ( V_2 , V_10 ) ;
if ( V_14 )
return V_14 ;
if ( 0 )
F_40 ( V_2 , L_4 , V_72 , V_27 ) ;
* V_21 = V_27 ;
* V_75 = - 1 ;
do {
V_14 = F_8 ( V_2 , * V_21 , V_74 ) ;
if ( V_14 )
return V_14 ;
if ( ! ( F_24 ( V_37 -> V_38 ) & 0xffffff ) ) {
if ( * V_21 != V_27 ) {
F_41 ( V_2 , L_5 ) ;
V_14 = - V_57 ;
}
return V_14 ;
}
if ( ! memcmp ( V_37 -> V_72 , V_72 , 16 ) &&
F_24 ( V_37 -> V_38 ) >> 30 == V_42 )
return V_14 ;
* V_75 = * V_21 ;
* V_21 = F_24 ( V_37 -> V_79 ) >> 6 ;
} while ( * V_21 );
* V_21 = - 1 ;
return V_14 ;
}
static void F_42 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
static const T_3 V_84 [] = {
[ V_85 ] = 0x0 ,
[ V_86 ] = 0x1 ,
[ V_87 ] = 0x2 ,
[ V_88 ] = 0x3 ,
} ;
T_1 V_89 = 0 ;
V_89 = V_81 -> V_90 == V_91 ? 1 : 0 ;
V_89 |= V_81 -> V_92 ? ( 1 << 2 ) : 0 ;
V_89 |= V_81 -> V_93 ? ( 1 << 3 ) : 0 ;
V_89 |= V_84 [ V_81 -> V_94 ] << 8 ;
V_89 |= V_81 -> V_95 << 16 ;
V_83 -> V_81 = F_25 ( V_89 ) ;
V_83 -> V_96 = F_25 ( V_81 -> V_24 ) ;
V_83 -> V_32 = F_25 ( V_81 -> V_32 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_97 * V_98 ,
struct V_99 * V_100 )
{
static const T_5 V_101 [] = {
[ V_102 ] =
sizeof( struct V_103 ) ,
[ V_104 ] =
sizeof( struct V_105 ) ,
[ V_106 ] = 0 ,
[ V_107 ] =
sizeof( struct V_108 ) ,
[ V_109 ] =
sizeof( struct V_110 ) ,
[ V_111 ] =
sizeof(struct V_110 )
} ;
if ( V_98 -> V_112 >= V_113 ) {
F_41 ( V_2 , L_6 , V_98 -> V_112 ) ;
return - V_57 ;
}
memset ( V_100 , 0 , V_101 [ V_98 -> V_112 ] ) ;
V_100 -> V_112 = F_44 ( V_114 [ V_98 -> V_112 ] ) ;
V_100 -> V_11 = V_101 [ V_98 -> V_112 ] >> 2 ;
switch ( V_98 -> V_112 ) {
case V_102 :
memcpy ( V_100 -> V_115 . V_116 , V_98 -> V_115 . V_116 , V_117 ) ;
memcpy ( V_100 -> V_115 . V_118 , V_98 -> V_115 . V_118 ,
V_117 ) ;
memcpy ( V_100 -> V_115 . V_119 , V_98 -> V_115 . V_119 , V_117 ) ;
memcpy ( V_100 -> V_115 . V_120 , V_98 -> V_115 . V_120 ,
V_117 ) ;
if ( V_98 -> V_115 . V_121 ) {
V_100 -> V_115 . V_121 = 1 ;
V_100 -> V_115 . V_122 = V_98 -> V_115 . V_122 ;
}
V_100 -> V_115 . V_123 = V_98 -> V_115 . V_123 ;
V_100 -> V_115 . V_124 = V_98 -> V_115 . V_124 ;
break;
case V_104 :
V_100 -> V_125 . V_32 = V_98 -> V_125 . V_126 ;
V_100 -> V_125 . V_127 = V_98 -> V_125 . V_128 ;
memcpy ( & V_100 -> V_125 . V_129 , & V_98 -> V_125 . V_129 , 16 ) ;
memcpy ( & V_100 -> V_125 . V_130 , & V_98 -> V_125 . V_130 , 16 ) ;
break;
case V_106 :
return - V_131 ;
case V_107 :
V_100 -> V_132 . V_133 = V_98 -> V_132 . V_133 ;
V_100 -> V_132 . V_134 = V_98 -> V_132 . V_134 ;
V_100 -> V_132 . V_135 = V_98 -> V_132 . V_135 ;
V_100 -> V_132 . V_136 = V_98 -> V_132 . V_136 ;
break;
case V_109 :
case V_111 :
V_100 -> V_137 . V_138 = V_98 -> V_137 . V_138 ;
V_100 -> V_137 . V_139 = V_98 -> V_137 . V_139 ;
V_100 -> V_137 . V_140 = V_98 -> V_137 . V_140 ;
V_100 -> V_137 . V_141 = V_98 -> V_137 . V_141 ;
break;
default:
return - V_57 ;
}
return V_101 [ V_98 -> V_112 ] ;
}
static void F_45 ( struct V_1 * V_2 , char * V_142 ,
struct V_80 * V_143 )
{
#define F_46 256
struct V_97 * V_144 ;
char V_50 [ F_46 ] ;
int V_145 = 0 ;
F_41 ( V_2 , L_7 , V_142 ) ;
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_8 ,
V_143 -> V_24 , V_143 -> V_95 , V_143 -> V_32 ) ;
F_15 (cur, &rule->list, list) {
switch ( V_144 -> V_112 ) {
case V_102 :
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_9 , & V_144 -> V_115 . V_116 ) ;
if ( V_144 -> V_115 . V_122 )
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_10 ,
F_47 ( V_144 -> V_115 . V_122 ) ) ;
if ( V_144 -> V_115 . V_123 )
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_11 ,
F_47 ( V_144 -> V_115 . V_123 ) ) ;
break;
case V_107 :
if ( V_144 -> V_132 . V_133 )
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_12 ,
& V_144 -> V_132 . V_133 ) ;
if ( V_144 -> V_132 . V_135 )
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_13 ,
& V_144 -> V_132 . V_135 ) ;
break;
case V_109 :
case V_111 :
if ( V_144 -> V_137 . V_140 )
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_14 ,
F_47 ( V_144 -> V_137 . V_140 ) ) ;
if ( V_144 -> V_137 . V_138 )
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_15 ,
F_47 ( V_144 -> V_137 . V_138 ) ) ;
break;
case V_104 :
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_16 , V_144 -> V_125 . V_129 ) ;
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 ,
L_17 ,
V_144 -> V_125 . V_130 ) ;
break;
case V_106 :
break;
default:
break;
}
}
V_145 += snprintf ( V_50 + V_145 , F_46 - V_145 , L_18 ) ;
F_41 ( V_2 , L_7 , V_50 ) ;
if ( V_145 >= F_46 )
F_41 ( V_2 , L_19 ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_80 * V_143 , T_2 * V_12 )
{
struct V_9 * V_10 ;
struct V_97 * V_144 ;
T_1 V_11 = 0 ;
int V_60 ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) )
return F_49 ( V_10 ) ;
memset ( V_10 -> V_50 , 0 , sizeof( struct V_82 ) ) ;
F_42 ( V_143 , V_10 -> V_50 ) ;
V_11 += sizeof( struct V_82 ) ;
F_15 (cur, &rule->list, list) {
V_60 = F_43 ( V_2 , V_144 , V_10 -> V_50 + V_11 ) ;
if ( V_60 < 0 ) {
F_26 ( V_2 , V_10 ) ;
return - V_57 ;
}
V_11 += V_60 ;
}
V_60 = F_4 ( V_2 , V_10 , V_11 >> 2 , V_12 ) ;
if ( V_60 == - V_44 )
F_45 ( V_2 ,
L_20 ,
V_143 ) ;
else if ( V_60 )
F_45 ( V_2 , L_21 , V_143 ) ;
F_26 ( V_2 , V_10 ) ;
return V_60 ;
}
int F_50 ( struct V_1 * V_2 , T_2 V_12 )
{
int V_14 ;
V_14 = F_6 ( V_2 , V_12 ) ;
if ( V_14 )
F_41 ( V_2 , L_22 ,
V_12 ) ;
return V_14 ;
}
int F_51 ( struct V_1 * V_2 , struct V_146 * V_53 , T_3 V_72 [ 16 ] ,
int V_147 , enum V_73 V_42 ,
enum V_31 V_25 )
{
struct F_14 * V_64 = F_14 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_36 * V_37 ;
T_1 V_38 ;
int V_21 , V_75 ;
int V_148 = 0 ;
int V_61 ;
int V_14 ;
T_3 V_24 = V_72 [ 5 ] ;
T_3 V_40 = 0 ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) )
return F_49 ( V_10 ) ;
V_37 = V_10 -> V_50 ;
F_36 ( & V_64 -> V_65 . V_66 ) ;
V_14 = F_39 ( V_2 , V_24 , V_72 , V_42 ,
V_10 , & V_75 , & V_21 ) ;
if ( V_14 )
goto V_62;
if ( V_21 != - 1 ) {
if ( ! ( F_24 ( V_37 -> V_38 ) & 0xffffff ) ) {
V_40 = 1 ;
memcpy ( V_37 -> V_72 , V_72 , 16 ) ;
}
} else {
V_148 = 1 ;
V_21 = F_52 ( & V_64 -> V_65 . V_149 ) ;
if ( V_21 == - 1 ) {
F_41 ( V_2 , L_23 ) ;
V_14 = - V_44 ;
goto V_62;
}
V_21 += V_2 -> V_3 . V_150 ;
V_40 = 1 ;
memset ( V_37 , 0 , sizeof *V_37 ) ;
memcpy ( V_37 -> V_72 , V_72 , 16 ) ;
}
V_38 = F_24 ( V_37 -> V_38 ) & 0xffffff ;
if ( V_38 == V_2 -> V_3 . V_52 ) {
F_41 ( V_2 , L_24 , V_21 ) ;
V_14 = - V_44 ;
goto V_62;
}
for ( V_61 = 0 ; V_61 < V_38 ; ++ V_61 )
if ( ( F_24 ( V_37 -> V_53 [ V_61 ] ) & V_54 ) == V_53 -> V_32 ) {
F_40 ( V_2 , L_25 , V_53 -> V_32 ) ;
V_14 = 0 ;
goto V_62;
}
if ( V_147 )
V_37 -> V_53 [ V_38 ++ ] = F_25 ( ( V_53 -> V_32 & V_54 ) |
( 1U << V_151 ) ) ;
else
V_37 -> V_53 [ V_38 ++ ] = F_25 ( V_53 -> V_32 & V_54 ) ;
V_37 -> V_38 = F_25 ( V_38 | ( T_1 ) V_42 << 30 ) ;
V_14 = F_10 ( V_2 , V_21 , V_10 ) ;
if ( V_14 )
goto V_62;
if ( ! V_148 )
goto V_62;
V_14 = F_8 ( V_2 , V_75 , V_10 ) ;
if ( V_14 )
goto V_62;
V_37 -> V_79 = F_25 ( V_21 << 6 ) ;
V_14 = F_10 ( V_2 , V_75 , V_10 ) ;
if ( V_14 )
goto V_62;
V_62:
if ( V_42 == V_68 ) {
if ( V_40 )
F_16 ( V_2 , V_24 , V_25 , V_21 , V_53 -> V_32 ) ;
else
F_29 ( V_2 , V_24 , V_25 ,
V_21 , V_53 -> V_32 ) ;
}
if ( V_14 && V_148 && V_21 != - 1 ) {
if ( V_21 < V_2 -> V_3 . V_150 )
F_31 ( V_2 , L_26 ,
V_21 , V_2 -> V_3 . V_150 ) ;
else
F_53 ( & V_64 -> V_65 . V_149 ,
V_21 - V_2 -> V_3 . V_150 ) ;
}
F_37 ( & V_64 -> V_65 . V_66 ) ;
F_26 ( V_2 , V_10 ) ;
return V_14 ;
}
int F_54 ( struct V_1 * V_2 , struct V_146 * V_53 , T_3 V_72 [ 16 ] ,
enum V_73 V_42 , enum V_31 V_25 )
{
struct F_14 * V_64 = F_14 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_36 * V_37 ;
T_1 V_38 ;
int V_75 , V_21 ;
int V_61 , V_71 ;
int V_14 ;
T_3 V_24 = V_72 [ 5 ] ;
bool V_152 = false ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) )
return F_49 ( V_10 ) ;
V_37 = V_10 -> V_50 ;
F_36 ( & V_64 -> V_65 . V_66 ) ;
V_14 = F_39 ( V_2 , V_24 , V_72 , V_42 ,
V_10 , & V_75 , & V_21 ) ;
if ( V_14 )
goto V_62;
if ( V_21 == - 1 ) {
F_41 ( V_2 , L_27 , V_72 ) ;
V_14 = - V_57 ;
goto V_62;
}
if ( V_42 == V_68 &&
F_32 ( V_2 , V_24 , V_25 , V_21 , V_53 -> V_32 ) )
goto V_62;
V_38 = F_24 ( V_37 -> V_38 ) & 0xffffff ;
for ( V_71 = - 1 , V_61 = 0 ; V_61 < V_38 ; ++ V_61 )
if ( ( F_24 ( V_37 -> V_53 [ V_61 ] ) & V_54 ) == V_53 -> V_32 )
V_71 = V_61 ;
if ( V_71 == - 1 ) {
F_41 ( V_2 , L_28 , V_53 -> V_32 ) ;
V_14 = - V_57 ;
goto V_62;
}
V_37 -> V_38 = F_25 ( -- V_38 | ( T_1 ) V_42 << 30 ) ;
V_37 -> V_53 [ V_71 ] = V_37 -> V_53 [ V_61 - 1 ] ;
V_37 -> V_53 [ V_61 - 1 ] = 0 ;
if ( V_42 == V_68 )
V_152 = F_34 ( V_2 , V_24 , V_25 ,
V_21 , V_53 -> V_32 ) ;
if ( V_61 != 1 && ( V_42 != V_68 || ! V_152 ) ) {
V_14 = F_10 ( V_2 , V_21 , V_10 ) ;
goto V_62;
}
V_37 -> V_38 = F_25 ( ( T_1 ) V_42 << 30 ) ;
if ( V_75 == - 1 ) {
int V_153 = F_24 ( V_37 -> V_79 ) >> 6 ;
if ( V_153 ) {
V_14 = F_8 ( V_2 , V_153 , V_10 ) ;
if ( V_14 )
goto V_62;
} else
memset ( V_37 -> V_72 , 0 , 16 ) ;
V_14 = F_10 ( V_2 , V_21 , V_10 ) ;
if ( V_14 )
goto V_62;
if ( V_153 ) {
if ( V_153 < V_2 -> V_3 . V_150 )
F_31 ( V_2 , L_29 ,
V_21 , V_153 , V_2 -> V_3 . V_150 ) ;
else
F_53 ( & V_64 -> V_65 . V_149 ,
V_153 - V_2 -> V_3 . V_150 ) ;
}
} else {
int V_154 = F_24 ( V_37 -> V_79 ) >> 6 ;
V_14 = F_8 ( V_2 , V_75 , V_10 ) ;
if ( V_14 )
goto V_62;
V_37 -> V_79 = F_25 ( V_154 << 6 ) ;
V_14 = F_10 ( V_2 , V_75 , V_10 ) ;
if ( V_14 )
goto V_62;
if ( V_21 < V_2 -> V_3 . V_150 )
F_31 ( V_2 , L_30 ,
V_75 , V_21 , V_2 -> V_3 . V_150 ) ;
else
F_53 ( & V_64 -> V_65 . V_149 ,
V_21 - V_2 -> V_3 . V_150 ) ;
}
V_62:
F_37 ( & V_64 -> V_65 . V_66 ) ;
F_26 ( V_2 , V_10 ) ;
return V_14 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_146 * V_53 ,
T_3 V_72 [ 16 ] , T_3 V_155 , T_3 V_156 ,
enum V_73 V_42 )
{
struct V_9 * V_10 ;
int V_14 = 0 ;
int V_32 ;
if ( ! F_56 ( V_2 ) )
return - V_157 ;
V_10 = F_22 ( V_2 ) ;
if ( F_23 ( V_10 ) )
return F_49 ( V_10 ) ;
memcpy ( V_10 -> V_50 , V_72 , 16 ) ;
V_32 = V_53 -> V_32 ;
V_32 |= ( V_42 << 28 ) ;
if ( V_155 && V_156 )
V_32 |= ( 1 << 31 ) ;
V_14 = F_7 ( V_2 , V_10 -> V_15 , V_32 , V_155 ,
V_158 , V_17 ,
V_159 ) ;
F_26 ( V_2 , V_10 ) ;
return V_14 ;
}
int F_57 ( struct V_1 * V_2 , struct V_146 * V_53 , T_3 V_72 [ 16 ] ,
T_3 V_24 , int V_147 ,
enum V_73 V_42 , T_2 * V_12 )
{
switch ( V_2 -> V_3 . V_4 ) {
case V_160 :
if ( V_42 == V_68 )
return 0 ;
case V_161 :
if ( V_42 == V_68 )
V_72 [ 7 ] |= ( V_162 << 1 ) ;
if ( F_56 ( V_2 ) )
return F_55 ( V_2 , V_53 , V_72 , 1 ,
V_147 , V_42 ) ;
return F_51 ( V_2 , V_53 , V_72 ,
V_147 , V_42 ,
V_162 ) ;
case V_5 : {
struct V_97 V_98 = { { NULL } } ;
T_6 V_163 = F_58 ( V_164 << 16 ) ;
struct V_80 V_143 = {
. V_90 = V_165 ,
. V_92 = 0 ,
. V_94 = V_85 ,
. V_95 = V_166 ,
} ;
V_143 . V_93 = ~ V_147 ;
V_143 . V_24 = V_24 ;
V_143 . V_32 = V_53 -> V_32 ;
F_18 ( & V_143 . V_46 ) ;
switch ( V_42 ) {
case V_68 :
V_98 . V_112 = V_102 ;
memcpy ( V_98 . V_115 . V_116 , & V_72 [ 10 ] , V_117 ) ;
memcpy ( V_98 . V_115 . V_118 , & V_163 , V_117 ) ;
break;
case V_167 :
V_98 . V_112 = V_104 ;
memcpy ( V_98 . V_125 . V_129 , V_72 , 16 ) ;
memset ( & V_98 . V_125 . V_130 , 0xff , 16 ) ;
break;
default:
return - V_57 ;
}
F_19 ( & V_98 . V_46 , & V_143 . V_46 ) ;
return F_48 ( V_2 , & V_143 , V_12 ) ;
}
default:
return - V_57 ;
}
}
int F_59 ( struct V_1 * V_2 , struct V_146 * V_53 , T_3 V_72 [ 16 ] ,
enum V_73 V_42 , T_2 V_12 )
{
switch ( V_2 -> V_3 . V_4 ) {
case V_160 :
if ( V_42 == V_68 )
return 0 ;
case V_161 :
if ( V_42 == V_68 )
V_72 [ 7 ] |= ( V_162 << 1 ) ;
if ( F_56 ( V_2 ) )
return F_55 ( V_2 , V_53 , V_72 , 0 , 0 , V_42 ) ;
return F_54 ( V_2 , V_53 , V_72 , V_42 ,
V_162 ) ;
case V_5 :
return F_50 ( V_2 , V_12 ) ;
default:
return - V_57 ;
}
}
int F_60 ( struct V_1 * V_2 , T_3 V_24 ,
T_1 V_32 , enum V_168 V_169 )
{
struct V_80 V_143 ;
T_2 * V_170 ;
switch ( V_169 ) {
case V_86 :
case V_87 :
V_170 = & V_2 -> V_171 [ V_24 ] ;
break;
case V_88 :
V_170 = & V_2 -> V_172 [ V_24 ] ;
break;
default:
return - 1 ;
}
if ( * V_170 != 0 )
return - 1 ;
V_143 . V_94 = V_169 ;
V_143 . V_24 = V_24 ;
V_143 . V_32 = V_32 ;
F_18 ( & V_143 . V_46 ) ;
F_41 ( V_2 , L_31 , V_24 ) ;
return F_48 ( V_2 , & V_143 , V_170 ) ;
}
int F_61 ( struct V_1 * V_2 , T_3 V_24 ,
enum V_168 V_169 )
{
int V_60 ;
T_2 * V_170 ;
switch ( V_169 ) {
case V_86 :
case V_87 :
V_170 = & V_2 -> V_171 [ V_24 ] ;
break;
case V_88 :
V_170 = & V_2 -> V_172 [ V_24 ] ;
break;
default:
return - 1 ;
}
if ( * V_170 == 0 )
return - 1 ;
V_60 = F_50 ( V_2 , * V_170 ) ;
if ( V_60 == 0 )
* V_170 = 0 ;
return V_60 ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_146 * V_53 , T_3 V_72 [ 16 ] ,
int V_147 , enum V_73 V_42 )
{
if ( V_42 == V_68 )
V_72 [ 7 ] |= ( V_173 << 1 ) ;
if ( F_56 ( V_2 ) )
return F_55 ( V_2 , V_53 , V_72 , 1 ,
V_147 , V_42 ) ;
return F_51 ( V_2 , V_53 , V_72 , V_147 ,
V_42 , V_173 ) ;
}
int F_63 ( struct V_1 * V_2 , struct V_146 * V_53 ,
T_3 V_72 [ 16 ] , enum V_73 V_42 )
{
if ( V_42 == V_68 )
V_72 [ 7 ] |= ( V_173 << 1 ) ;
if ( F_56 ( V_2 ) )
return F_55 ( V_2 , V_53 , V_72 , 0 , 0 , V_42 ) ;
return F_54 ( V_2 , V_53 , V_72 , V_42 , V_173 ) ;
}
int F_64 ( struct V_1 * V_2 , int V_174 ,
struct V_175 * V_176 ,
struct V_9 * V_177 ,
struct V_9 * V_178 ,
struct V_179 * V_180 )
{
T_1 V_32 = ( T_1 ) V_176 -> V_181 & 0xffffffff ;
T_3 V_24 = V_176 -> V_181 >> 62 ;
enum V_31 V_25 = V_176 -> V_182 ;
if ( F_56 ( V_2 ) && V_25 == V_173 )
return 0 ;
if ( V_176 -> V_183 )
return F_35 ( V_2 , V_24 , V_25 , V_32 ) ;
else
return F_38 ( V_2 , V_24 , V_25 , V_32 ) ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_32 ,
enum V_31 V_25 , T_3 V_184 , T_3 V_24 )
{
return F_7 ( V_2 , ( T_2 ) V_32 | ( T_2 ) V_24 << 62 , ( T_1 ) V_25 , V_184 ,
V_185 , V_17 ,
V_159 ) ;
}
int F_66 ( struct V_1 * V_2 , T_1 V_32 , T_3 V_24 )
{
if ( F_56 ( V_2 ) )
return F_65 ( V_2 , V_32 , V_162 , 1 , V_24 ) ;
return F_35 ( V_2 , V_24 , V_162 , V_32 ) ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_32 , T_3 V_24 )
{
if ( F_56 ( V_2 ) )
return F_65 ( V_2 , V_32 , V_162 , 0 , V_24 ) ;
return F_38 ( V_2 , V_24 , V_162 , V_32 ) ;
}
int F_68 ( struct V_1 * V_2 , T_1 V_32 , T_3 V_24 )
{
if ( F_56 ( V_2 ) )
return F_65 ( V_2 , V_32 , V_173 , 1 , V_24 ) ;
return F_35 ( V_2 , V_24 , V_173 , V_32 ) ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_32 , T_3 V_24 )
{
if ( F_56 ( V_2 ) )
return F_65 ( V_2 , V_32 , V_173 , 0 , V_24 ) ;
return F_38 ( V_2 , V_24 , V_173 , V_32 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
struct F_14 * V_64 = F_14 ( V_2 ) ;
int V_14 ;
if ( V_2 -> V_3 . V_4 ==
V_5 )
return 0 ;
V_14 = F_71 ( & V_64 -> V_65 . V_149 , V_2 -> V_3 . V_186 ,
V_2 -> V_3 . V_186 - 1 , 0 , 0 ) ;
if ( V_14 )
return V_14 ;
F_72 ( & V_64 -> V_65 . V_66 ) ;
return 0 ;
}
void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 !=
V_5 )
F_74 ( & F_14 ( V_2 ) -> V_65 . V_149 ) ;
}
