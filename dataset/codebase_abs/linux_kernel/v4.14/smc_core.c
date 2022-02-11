static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * * V_4 , * V_5 = NULL ;
T_1 V_6 = V_2 -> V_7 ;
V_4 = & V_2 -> V_8 -> V_9 . V_3 ;
while ( * V_4 ) {
struct V_1 * V_10 = F_2 ( * V_4 ,
struct V_1 , V_11 ) ;
V_5 = * V_4 ;
if ( V_10 -> V_7 > V_6 )
V_4 = & V_5 -> V_12 ;
else
V_4 = & V_5 -> V_13 ;
}
F_3 ( & V_2 -> V_11 , V_5 , V_4 ) ;
F_4 ( & V_2 -> V_11 , & V_2 -> V_8 -> V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 , struct V_14 , V_2 ) ;
static T_2 V_16 = F_7 ( 0 ) ;
F_8 ( & V_15 -> V_17 ) ;
while ( ! V_2 -> V_7 ) {
V_2 -> V_7 = F_9 ( & V_16 ) ;
if ( F_10 ( V_2 -> V_7 , V_2 -> V_8 ) )
V_2 -> V_7 = 0 ;
}
F_1 ( V_2 ) ;
V_2 -> V_8 -> V_18 ++ ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 , struct V_14 , V_2 ) ;
struct V_19 * V_8 = V_2 -> V_8 ;
F_12 ( & V_2 -> V_11 , & V_8 -> V_9 ) ;
V_8 -> V_18 -- ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = NULL ;
F_13 ( & V_15 -> V_17 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
int V_20 = 0 ;
F_15 ( & V_8 -> V_21 ) ;
if ( V_2 -> V_7 ) {
V_20 = 1 ;
F_11 ( V_2 ) ;
}
F_16 ( & V_8 -> V_21 ) ;
if ( ! V_20 || V_8 -> V_18 )
return;
F_17 ( V_22 , & V_8 -> V_23 ,
V_8 -> V_24 == V_25 ? V_26 :
V_27 ) ;
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_19 * V_8 = F_6 ( F_19 ( V_29 ) ,
struct V_19 ,
V_23 ) ;
bool V_30 ;
F_20 ( & V_31 . V_32 ) ;
F_21 ( & V_8 -> V_21 ) ;
V_30 = F_22 ( & V_8 -> V_9 ) ;
F_23 ( & V_8 -> V_21 ) ;
if ( ! V_30 ) {
F_24 ( & V_31 . V_32 ) ;
return;
}
F_25 ( & V_8 -> V_33 ) ;
F_24 ( & V_31 . V_32 ) ;
F_26 ( V_8 ) ;
}
static int F_27 ( struct V_14 * V_15 , T_3 V_34 ,
struct V_35 * V_36 , T_4 V_37 ,
char * V_38 , unsigned short V_39 )
{
struct V_19 * V_8 ;
struct V_40 * V_41 ;
T_4 V_42 [ 3 ] ;
int V_43 = 0 ;
int V_44 ;
V_8 = F_28 ( sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 ) {
V_43 = - V_46 ;
goto V_47;
}
V_8 -> V_24 = V_15 -> V_48 ? V_49 : V_25 ;
V_8 -> V_50 = false ;
V_8 -> V_51 = V_34 ;
memcpy ( V_8 -> V_38 , V_38 , V_52 ) ;
V_8 -> V_39 = V_39 ;
F_29 ( & V_8 -> V_53 ) ;
F_29 ( & V_8 -> V_54 ) ;
for ( V_44 = 0 ; V_44 < V_55 ; V_44 ++ ) {
F_30 ( & V_8 -> V_56 [ V_44 ] ) ;
F_30 ( & V_8 -> V_57 [ V_44 ] ) ;
}
V_58 += V_59 ;
memcpy ( & V_8 -> V_60 , ( T_4 * ) & V_58 , V_61 ) ;
F_31 ( & V_8 -> V_23 , F_18 ) ;
V_8 -> V_9 = V_62 ;
V_41 = & V_8 -> V_41 [ V_63 ] ;
V_41 -> V_36 = V_36 ;
V_41 -> V_37 = V_37 ;
V_41 -> V_64 = V_36 -> V_65 [ V_37 - 1 ] . V_66 ;
if ( ! V_36 -> V_67 )
F_32 ( V_36 ) ;
F_33 ( V_42 , sizeof( V_42 ) ) ;
V_41 -> V_68 = V_42 [ 0 ] + ( V_42 [ 1 ] << 8 ) + ( V_42 [ 2 ] << 16 ) ;
V_43 = F_34 ( V_41 ) ;
if ( V_43 )
goto V_69;
V_43 = F_35 ( V_41 ) ;
if ( V_43 )
goto V_70;
V_43 = F_36 ( V_41 ) ;
if ( V_43 )
goto V_71;
V_43 = F_37 ( V_41 ) ;
if ( V_43 )
goto V_72;
F_38 ( & V_41 -> V_73 ) ;
F_38 ( & V_41 -> V_74 ) ;
V_15 -> V_2 . V_8 = V_8 ;
F_29 ( & V_8 -> V_21 ) ;
F_20 ( & V_31 . V_32 ) ;
F_39 ( & V_8 -> V_33 , & V_31 . V_33 ) ;
F_24 ( & V_31 . V_32 ) ;
return 0 ;
V_72:
F_40 ( V_41 ) ;
V_71:
F_41 ( V_41 ) ;
V_70:
F_42 ( V_41 ) ;
V_69:
F_43 ( V_8 ) ;
V_47:
return V_43 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 ) {
V_2 -> V_75 -> V_76 = 0 ;
V_2 -> V_77 = 0 ;
}
if ( V_2 -> V_78 ) {
V_2 -> V_78 -> V_79 = true ;
V_2 -> V_78 -> V_76 = 0 ;
V_2 -> V_80 = 0 ;
}
}
void F_45 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return;
F_46 ( V_2 ) ;
F_14 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_47 ( struct V_40 * V_41 )
{
V_41 -> V_81 = 0 ;
F_48 ( V_41 ) ;
F_49 ( V_41 ) ;
F_40 ( V_41 ) ;
F_41 ( V_41 ) ;
F_42 ( V_41 ) ;
}
static void F_50 ( struct V_82 * V_83 , struct V_40 * V_41 ,
bool V_84 )
{
if ( V_84 ) {
if ( V_83 -> V_85 [ V_63 ] )
F_51 (
V_83 -> V_85 [ V_63 ] ) ;
F_52 ( V_41 -> V_36 , V_83 ,
V_86 ) ;
} else {
F_52 ( V_41 -> V_36 , V_83 ,
V_87 ) ;
}
F_53 ( & V_83 -> V_88 [ V_63 ] ) ;
if ( V_83 -> V_89 )
F_54 ( ( unsigned long ) V_83 -> V_89 , V_83 -> V_90 ) ;
F_43 ( V_83 ) ;
}
static void F_55 ( struct V_19 * V_8 , bool V_84 )
{
struct V_40 * V_41 = & V_8 -> V_41 [ V_63 ] ;
struct V_82 * V_83 , * V_91 ;
struct V_92 * V_93 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_55 ; V_44 ++ ) {
if ( V_84 )
V_93 = & V_8 -> V_57 [ V_44 ] ;
else
V_93 = & V_8 -> V_56 [ V_44 ] ;
F_56 (buf_desc, bf_desc, buf_list,
list) {
F_57 ( & V_83 -> V_33 ) ;
F_50 ( V_83 , V_41 , V_84 ) ;
}
}
}
static void F_58 ( struct V_19 * V_8 )
{
F_55 ( V_8 , false ) ;
F_55 ( V_8 , true ) ;
}
void F_26 ( struct V_19 * V_8 )
{
F_58 ( V_8 ) ;
F_47 ( & V_8 -> V_41 [ V_63 ] ) ;
F_43 ( V_8 ) ;
}
void F_59 ( struct V_19 * V_8 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
struct V_3 * V_94 ;
F_20 ( & V_31 . V_32 ) ;
if ( F_60 ( & V_8 -> V_33 ) ) {
F_24 ( & V_31 . V_32 ) ;
return;
}
F_25 ( & V_8 -> V_33 ) ;
F_24 ( & V_31 . V_32 ) ;
F_15 ( & V_8 -> V_21 ) ;
V_94 = F_61 ( & V_8 -> V_9 ) ;
while ( V_94 ) {
V_2 = F_2 ( V_94 , struct V_1 , V_11 ) ;
V_15 = F_6 ( V_2 , struct V_14 , V_2 ) ;
F_8 ( & V_15 -> V_17 ) ;
F_11 ( V_2 ) ;
F_62 ( & V_2 -> V_95 ) ;
F_13 ( & V_15 -> V_17 ) ;
V_94 = F_61 ( & V_8 -> V_9 ) ;
}
F_16 ( & V_8 -> V_21 ) ;
}
static int F_63 ( struct V_96 * V_97 , unsigned short * V_39 )
{
struct V_98 * V_99 = F_64 ( V_97 -> V_17 ) ;
int V_43 = 0 ;
* V_39 = 0 ;
if ( ! V_99 ) {
V_43 = - V_100 ;
goto V_47;
}
if ( ! V_99 -> V_101 ) {
V_43 = - V_102 ;
goto V_103;
}
if ( F_65 ( V_99 -> V_101 ) )
* V_39 = F_66 ( V_99 -> V_101 ) ;
V_103:
F_67 ( V_99 ) ;
V_47:
return V_43 ;
}
static int F_68 ( struct V_19 * V_8 )
{
struct V_40 * V_41 = & V_8 -> V_41 [ V_63 ] ;
struct V_104 V_105 ;
union V_106 V_107 ;
int V_44 ;
if ( ! V_8 -> V_39 ) {
V_41 -> V_107 = V_41 -> V_36 -> V_107 [ V_41 -> V_37 - 1 ] ;
return 0 ;
}
for ( V_44 = 0 ; V_44 < V_41 -> V_36 -> V_65 [ V_41 -> V_37 - 1 ] . V_108 ;
V_44 ++ ) {
if ( F_69 ( V_41 -> V_36 -> V_109 , V_41 -> V_37 , V_44 , & V_107 ,
& V_105 ) )
continue;
if ( V_105 . V_110 &&
( F_66 ( V_105 . V_110 ) == V_8 -> V_39 ) ) {
V_41 -> V_107 = V_107 ;
return 0 ;
}
}
return - V_102 ;
}
int F_70 ( struct V_14 * V_15 , T_3 V_34 ,
struct V_35 * V_36 , T_4 V_37 ,
struct V_111 * V_112 , int V_113 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_19 * V_8 ;
unsigned short V_39 ;
enum V_114 V_24 ;
int V_115 = V_116 ;
int V_43 = 0 ;
V_24 = V_15 -> V_48 ? V_49 : V_25 ;
V_43 = F_63 ( V_15 -> V_97 , & V_39 ) ;
if ( V_43 )
return V_43 ;
if ( ( V_24 == V_25 ) && V_113 )
goto V_117;
F_20 ( & V_31 . V_32 ) ;
F_71 (lgr, &smc_lgr_list.list, list) {
F_15 ( & V_8 -> V_21 ) ;
if ( ! memcmp ( V_8 -> V_38 , V_112 -> V_118 ,
V_52 ) &&
! memcmp ( V_8 -> V_41 [ V_63 ] . V_119 , & V_112 -> V_107 ,
V_120 ) &&
! memcmp ( V_8 -> V_41 [ V_63 ] . V_121 , V_112 -> V_122 ,
sizeof( V_112 -> V_122 ) ) &&
! V_8 -> V_50 &&
( V_8 -> V_24 == V_24 ) &&
( V_8 -> V_39 == V_39 ) &&
( ( V_24 == V_25 ) ||
( V_8 -> V_18 < V_123 ) ) ) {
V_115 = V_124 ;
V_2 -> V_8 = V_8 ;
F_5 ( V_2 ) ;
F_16 ( & V_8 -> V_21 ) ;
break;
}
F_16 ( & V_8 -> V_21 ) ;
}
F_24 ( & V_31 . V_32 ) ;
if ( V_24 == V_25 && ! V_113 &&
( V_115 == V_116 ) ) {
return - V_125 ;
}
V_117:
if ( V_115 == V_116 ) {
V_43 = F_27 ( V_15 , V_34 , V_36 , V_37 ,
V_112 -> V_118 , V_39 ) ;
if ( V_43 )
goto V_47;
F_5 ( V_2 ) ;
V_43 = F_68 ( V_2 -> V_8 ) ;
}
V_2 -> V_126 . V_127 . type = V_128 ;
V_2 -> V_126 . V_129 = sizeof( struct V_130 ) ;
#ifndef F_72
F_73 ( & V_2 -> V_131 ) ;
#endif
V_47:
return V_43 ? V_43 : V_115 ;
}
static inline
struct V_82 * F_74 ( struct V_19 * V_8 ,
int V_132 ,
T_5 * V_32 ,
struct V_92 * V_93 )
{
struct V_82 * V_133 ;
F_21 ( V_32 ) ;
F_71 (buf_slot, buf_list, list) {
if ( F_75 ( & V_133 -> V_76 , 0 , 1 ) == 0 ) {
F_23 ( V_32 ) ;
return V_133 ;
}
}
F_23 ( V_32 ) ;
return NULL ;
}
static inline int F_76 ( int V_80 )
{
return F_77 ( int , V_80 / 10 , V_134 / 2 ) ;
}
static struct V_82 * F_78 ( struct V_19 * V_8 ,
bool V_84 , int V_135 )
{
struct V_82 * V_83 ;
struct V_40 * V_41 ;
int V_43 ;
V_83 = F_28 ( sizeof( * V_83 ) , V_45 ) ;
if ( ! V_83 )
return F_79 ( - V_46 ) ;
V_83 -> V_89 =
( void * ) F_80 ( V_45 | V_136 |
V_137 |
V_138 | V_139 ,
F_81 ( V_135 ) ) ;
if ( ! V_83 -> V_89 ) {
F_43 ( V_83 ) ;
return F_79 ( - V_140 ) ;
}
V_83 -> V_90 = F_81 ( V_135 ) ;
V_41 = & V_8 -> V_41 [ V_63 ] ;
V_43 = F_82 ( & V_83 -> V_88 [ V_63 ] , 1 ,
V_45 ) ;
if ( V_43 ) {
F_50 ( V_83 , V_41 , V_84 ) ;
return F_79 ( V_43 ) ;
}
F_83 ( V_83 -> V_88 [ V_63 ] . V_141 ,
V_83 -> V_89 , V_135 ) ;
V_43 = F_84 ( V_41 -> V_36 , V_83 ,
V_84 ? V_86 : V_87 ) ;
if ( V_43 != 1 ) {
F_50 ( V_83 , V_41 , V_84 ) ;
return F_79 ( - V_140 ) ;
}
if ( V_84 ) {
V_43 = F_85 ( V_41 -> V_142 ,
V_143 |
V_144 ,
V_83 ) ;
if ( V_43 ) {
F_50 ( V_83 , V_41 , V_84 ) ;
return F_79 ( V_43 ) ;
}
}
return V_83 ;
}
static int F_86 ( struct V_14 * V_15 , bool V_84 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_19 * V_8 = V_2 -> V_8 ;
struct V_82 * V_83 = NULL ;
struct V_92 * V_93 ;
int V_135 , V_145 ;
int V_146 ;
T_5 * V_32 ;
if ( V_84 )
V_146 = V_15 -> V_17 . V_147 / 2 ;
else
V_146 = V_15 -> V_17 . V_148 / 2 ;
for ( V_145 = F_87 ( V_15 -> V_17 . V_148 / 2 ) ;
V_145 >= 0 ; V_145 -- ) {
if ( V_84 ) {
V_32 = & V_8 -> V_54 ;
V_93 = & V_8 -> V_57 [ V_145 ] ;
} else {
V_32 = & V_8 -> V_53 ;
V_93 = & V_8 -> V_56 [ V_145 ] ;
}
V_135 = F_88 ( V_145 ) ;
if ( ( 1 << F_81 ( V_135 ) ) > V_149 )
continue;
V_83 = F_74 ( V_8 , V_145 , V_32 , V_93 ) ;
if ( V_83 ) {
memset ( V_83 -> V_89 , 0 , V_135 ) ;
break;
}
V_83 = F_78 ( V_8 , V_84 , V_135 ) ;
if ( F_89 ( V_83 ) == - V_46 )
break;
if ( F_90 ( V_83 ) )
continue;
V_83 -> V_76 = 1 ;
F_15 ( V_32 ) ;
F_39 ( & V_83 -> V_33 , V_93 ) ;
F_16 ( V_32 ) ;
break;
}
if ( F_90 ( V_83 ) )
return - V_46 ;
if ( V_84 ) {
V_2 -> V_78 = V_83 ;
V_2 -> V_80 = V_135 ;
V_2 -> V_150 = V_145 ;
V_15 -> V_17 . V_147 = V_135 * 2 ;
F_91 ( & V_2 -> V_151 , 0 ) ;
V_2 -> V_152 = F_76 ( V_135 ) ;
} else {
V_2 -> V_75 = V_83 ;
V_2 -> V_77 = V_135 ;
V_15 -> V_17 . V_148 = V_135 * 2 ;
F_91 ( & V_2 -> V_153 , V_135 ) ;
}
return 0 ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
F_93 ( V_8 -> V_41 [ V_63 ] . V_36 ,
V_2 -> V_75 , V_87 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
F_95 ( V_8 -> V_41 [ V_63 ] . V_36 ,
V_2 -> V_75 , V_87 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
F_93 ( V_8 -> V_41 [ V_63 ] . V_36 ,
V_2 -> V_78 , V_86 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_19 * V_8 = V_2 -> V_8 ;
F_95 ( V_8 -> V_41 [ V_63 ] . V_36 ,
V_2 -> V_78 , V_86 ) ;
}
int F_98 ( struct V_14 * V_15 )
{
int V_43 ;
V_43 = F_86 ( V_15 , false ) ;
if ( V_43 )
return V_43 ;
V_43 = F_86 ( V_15 , true ) ;
if ( V_43 )
F_50 ( V_15 -> V_2 . V_75 ,
& V_15 -> V_2 . V_8 -> V_41 [ V_63 ] , false ) ;
return V_43 ;
}
static inline int F_99 ( struct V_19 * V_8 )
{
int V_44 ;
F_100 (i, lgr->rtokens_used_mask, SMC_RMBS_PER_LGR_MAX) {
if ( ! F_101 ( V_44 , V_8 -> V_154 ) )
return V_44 ;
}
return - V_155 ;
}
int F_102 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
T_6 V_158 = F_103 ( V_157 -> V_159 ) ;
struct V_19 * V_8 = V_2 -> V_8 ;
T_1 V_160 = F_104 ( V_157 -> V_161 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_123 ; V_44 ++ ) {
if ( ( V_8 -> V_162 [ V_44 ] [ V_63 ] . V_160 == V_160 ) &&
( V_8 -> V_162 [ V_44 ] [ V_63 ] . V_158 == V_158 ) &&
F_105 ( V_44 , V_8 -> V_154 ) ) {
V_2 -> V_163 = V_44 ;
return 0 ;
}
}
V_2 -> V_163 = F_99 ( V_8 ) ;
if ( V_2 -> V_163 < 0 )
return V_2 -> V_163 ;
V_8 -> V_162 [ V_2 -> V_163 ] [ V_63 ] . V_160 = V_160 ;
V_8 -> V_162 [ V_2 -> V_163 ] [ V_63 ] . V_158 = V_158 ;
return 0 ;
}
