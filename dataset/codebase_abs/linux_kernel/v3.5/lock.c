int F_1 ( int V_1 , int V_2 )
{
return V_3 [ V_1 + 1 ] [ V_2 + 1 ] ;
}
void F_2 ( struct V_4 * V_5 )
{
F_3 ( V_6 L_1
L_2 ,
V_5 -> V_7 , V_5 -> V_8 , V_5 -> V_9 , V_5 -> V_10 ,
V_5 -> V_11 , V_5 -> V_12 , V_5 -> V_13 ,
V_5 -> V_14 , V_5 -> V_15 , V_5 -> V_16 ,
( unsigned long long ) V_5 -> V_17 ) ;
}
static void F_4 ( struct V_18 * V_19 )
{
F_3 ( V_6 L_3 ,
V_19 -> V_20 , V_19 -> V_21 , V_19 -> V_22 ,
V_19 -> V_23 , V_19 -> V_24 ) ;
}
void F_5 ( struct V_18 * V_19 )
{
struct V_4 * V_5 ;
F_4 ( V_19 ) ;
F_3 ( V_6 L_4 ,
F_6 ( & V_19 -> V_25 ) , F_6 ( & V_19 -> V_26 ) ) ;
F_3 ( V_6 L_5 ) ;
F_7 (lkb, &r->res_lookup, lkb_rsb_lookup)
F_2 ( V_5 ) ;
F_3 ( V_6 L_6 ) ;
F_7 (lkb, &r->res_grantqueue, lkb_statequeue)
F_2 ( V_5 ) ;
F_3 ( V_6 L_7 ) ;
F_7 (lkb, &r->res_convertqueue, lkb_statequeue)
F_2 ( V_5 ) ;
F_3 ( V_6 L_8 ) ;
F_7 (lkb, &r->res_waitqueue, lkb_statequeue)
F_2 ( V_5 ) ;
}
static inline void F_8 ( struct V_27 * V_28 )
{
F_9 ( & V_28 -> V_29 ) ;
}
void F_10 ( struct V_27 * V_28 )
{
F_11 ( & V_28 -> V_29 ) ;
}
int F_12 ( struct V_27 * V_28 )
{
return F_13 ( & V_28 -> V_29 ) ;
}
static inline int F_14 ( struct V_4 * V_5 )
{
return ! ( V_5 -> V_10 & V_30 ) ;
}
static inline int F_15 ( struct V_4 * V_5 )
{
return ( V_5 -> V_10 & V_31 ) ;
}
static inline int F_16 ( struct V_4 * V_5 )
{
return ( V_5 -> V_32 & V_33 ) ;
}
static inline int F_17 ( struct V_4 * V_5 )
{
return ( V_5 -> V_32 & V_34 ) ;
}
static inline int F_18 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 == V_35 ) ;
}
static inline int F_19 ( struct V_18 * V_19 )
{
F_20 (r->res_nodeid >= 0 , dlm_print_rsb(r);) ;
return ! ! V_19 -> V_20 ;
}
static inline int F_21 ( struct V_4 * V_5 )
{
return ( V_5 -> V_7 && ! ( V_5 -> V_11 & V_36 ) ) ;
}
static inline int F_22 ( struct V_4 * V_5 )
{
return ( V_5 -> V_11 & V_36 ) ? 1 : 0 ;
}
static inline int F_23 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_14 == V_37 && V_5 -> V_13 == V_38 ) ||
( V_5 -> V_13 == V_37 && V_5 -> V_14 == V_38 ) )
return 1 ;
return 0 ;
}
static inline int F_24 ( struct V_4 * V_5 )
{
return ( ! F_23 ( V_5 ) && V_5 -> V_13 < V_5 -> V_14 ) ;
}
static inline int F_25 ( struct V_4 * V_5 )
{
return V_5 -> V_11 & V_39 ;
}
static inline int F_26 ( struct V_4 * V_5 )
{
return V_5 -> V_11 & V_40 ;
}
static inline int F_27 ( struct V_4 * V_5 )
{
return ( V_5 -> V_11 & ( V_39 |
V_40 ) ) ;
}
static void F_28 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_41 )
{
if ( F_22 ( V_5 ) )
return;
F_29 ( V_5 ) ;
F_20 (lkb->lkb_lksb, dlm_print_lkb(lkb);) ;
if ( V_41 == - V_42 && ( V_5 -> V_11 & V_43 ) ) {
V_5 -> V_11 &= ~ V_43 ;
V_41 = - V_44 ;
}
if ( V_41 == - V_42 && ( V_5 -> V_11 & V_45 ) ) {
V_5 -> V_11 &= ~ V_45 ;
V_41 = - V_46 ;
}
F_30 ( V_5 , V_47 , V_5 -> V_14 , V_41 , V_5 -> V_32 ) ;
}
static inline void F_31 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_28 ( V_19 , V_5 ,
F_25 ( V_5 ) ? - V_48 : - V_42 ) ;
}
static void F_32 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_49 )
{
if ( F_22 ( V_5 ) ) {
F_33 ( V_19 , V_5 , V_49 ) ;
} else {
F_30 ( V_5 , V_50 , V_49 , 0 , 0 ) ;
}
}
static int F_34 ( struct V_27 * V_28 )
{
struct V_18 * V_51 , * V_52 ;
int V_53 = 0 ;
F_35 ( & V_28 -> V_54 ) ;
if ( V_28 -> V_55 > V_56 . V_57 / 2 ) {
F_36 ( & V_28 -> V_54 ) ;
return 0 ;
}
F_36 ( & V_28 -> V_54 ) ;
V_51 = F_37 ( V_28 ) ;
V_52 = F_37 ( V_28 ) ;
F_35 ( & V_28 -> V_54 ) ;
if ( V_51 ) {
F_38 ( & V_51 -> V_58 , & V_28 -> V_59 ) ;
V_28 -> V_55 ++ ;
}
if ( V_52 ) {
F_38 ( & V_52 -> V_58 , & V_28 -> V_59 ) ;
V_28 -> V_55 ++ ;
}
V_53 = V_28 -> V_55 ;
F_36 ( & V_28 -> V_54 ) ;
if ( ! V_53 )
return - V_60 ;
return 0 ;
}
static int F_39 ( struct V_27 * V_28 , char * V_61 , int V_62 ,
struct V_18 * * V_63 )
{
struct V_18 * V_19 ;
int V_53 ;
F_35 ( & V_28 -> V_54 ) ;
if ( F_6 ( & V_28 -> V_59 ) ) {
V_53 = V_28 -> V_55 ;
F_36 ( & V_28 -> V_54 ) ;
F_40 ( V_28 , L_9 ,
V_53 , V_56 . V_57 , V_61 ) ;
return - V_64 ;
}
V_19 = F_41 ( & V_28 -> V_59 , struct V_18 , V_58 ) ;
F_42 ( & V_19 -> V_58 ) ;
memset ( & V_19 -> V_65 , 0 , sizeof( struct V_66 ) ) ;
V_28 -> V_55 -- ;
F_36 ( & V_28 -> V_54 ) ;
V_19 -> V_67 = V_28 ;
V_19 -> V_68 = V_62 ;
memcpy ( V_19 -> V_24 , V_61 , V_62 ) ;
F_43 ( & V_19 -> V_69 ) ;
F_44 ( & V_19 -> V_70 ) ;
F_44 ( & V_19 -> V_71 ) ;
F_44 ( & V_19 -> V_72 ) ;
F_44 ( & V_19 -> V_73 ) ;
F_44 ( & V_19 -> V_25 ) ;
F_44 ( & V_19 -> V_26 ) ;
* V_63 = V_19 ;
return 0 ;
}
static int F_45 ( struct V_18 * V_19 , const char * V_61 , int V_74 )
{
char V_75 [ V_76 ] ;
memset ( V_75 , 0 , V_76 ) ;
memcpy ( V_75 , V_61 , V_74 ) ;
return memcmp ( V_19 -> V_24 , V_75 , V_76 ) ;
}
int F_46 ( struct V_77 * V_78 , char * V_61 , int V_62 ,
unsigned int V_79 , struct V_18 * * V_63 )
{
struct V_66 * V_80 = V_78 -> V_66 ;
struct V_18 * V_19 ;
int error = 0 ;
int V_81 ;
while ( V_80 ) {
V_19 = F_47 ( V_80 , struct V_18 , V_65 ) ;
V_81 = F_45 ( V_19 , V_61 , V_62 ) ;
if ( V_81 < 0 )
V_80 = V_80 -> V_82 ;
else if ( V_81 > 0 )
V_80 = V_80 -> V_83 ;
else
goto V_84;
}
* V_63 = NULL ;
return - V_85 ;
V_84:
if ( V_19 -> V_20 && ( V_79 & V_86 ) )
error = - V_87 ;
* V_63 = V_19 ;
return error ;
}
static int F_48 ( struct V_18 * V_88 , struct V_77 * V_78 )
{
struct V_66 * * V_89 = & V_78 -> V_66 ;
struct V_66 * V_90 = NULL ;
int V_81 ;
while ( * V_89 ) {
struct V_18 * V_91 = F_47 ( * V_89 , struct V_18 ,
V_65 ) ;
V_90 = * V_89 ;
V_81 = F_45 ( V_91 , V_88 -> V_24 , V_88 -> V_68 ) ;
if ( V_81 < 0 )
V_89 = & V_90 -> V_82 ;
else if ( V_81 > 0 )
V_89 = & V_90 -> V_83 ;
else {
F_49 ( L_10 ) ;
F_5 ( V_88 ) ;
F_5 ( V_91 ) ;
return - V_92 ;
}
}
F_50 ( & V_88 -> V_65 , V_90 , V_89 ) ;
F_51 ( & V_88 -> V_65 , V_78 ) ;
return 0 ;
}
static int F_52 ( struct V_27 * V_28 , char * V_61 , int V_62 , int V_93 ,
unsigned int V_79 , struct V_18 * * V_63 )
{
struct V_18 * V_19 ;
int error ;
error = F_46 ( & V_28 -> V_94 [ V_93 ] . V_95 , V_61 , V_62 , V_79 , & V_19 ) ;
if ( ! error ) {
F_53 ( & V_19 -> V_96 ) ;
goto V_97;
}
if ( error == - V_87 )
goto V_97;
error = F_46 ( & V_28 -> V_94 [ V_93 ] . V_98 , V_61 , V_62 , V_79 , & V_19 ) ;
if ( error )
goto V_97;
F_54 ( & V_19 -> V_65 , & V_28 -> V_94 [ V_93 ] . V_98 ) ;
error = F_48 ( V_19 , & V_28 -> V_94 [ V_93 ] . V_95 ) ;
if ( error )
return error ;
if ( F_55 ( V_28 ) )
goto V_97;
if ( V_19 -> V_20 == - 1 ) {
F_56 ( V_19 , V_99 ) ;
V_19 -> V_22 = 0 ;
} else if ( V_19 -> V_20 > 0 ) {
F_57 ( V_19 , V_99 ) ;
V_19 -> V_22 = 0 ;
} else {
F_20 (r->res_nodeid == 0 , dlm_print_rsb(r);) ;
F_20 ( ! F_58 ( V_19 , V_99 ) ,) ;
}
V_97:
* V_63 = V_19 ;
return error ;
}
static int F_59 ( struct V_27 * V_28 , char * V_61 , int V_100 ,
unsigned int V_79 , struct V_18 * * V_63 )
{
struct V_18 * V_19 = NULL ;
T_1 V_101 , V_102 ;
int error ;
if ( V_100 > V_76 ) {
error = - V_103 ;
goto V_97;
}
if ( F_55 ( V_28 ) )
V_79 |= V_104 ;
V_101 = F_60 ( V_61 , V_100 , 0 ) ;
V_102 = V_101 & ( V_28 -> V_105 - 1 ) ;
V_106:
if ( V_79 & V_104 ) {
error = F_34 ( V_28 ) ;
if ( error < 0 )
goto V_97;
}
F_35 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
error = F_52 ( V_28 , V_61 , V_100 , V_102 , V_79 , & V_19 ) ;
if ( ! error )
goto V_108;
if ( error == - V_85 && ! ( V_79 & V_104 ) )
goto V_108;
if ( error == - V_87 )
goto V_108;
error = F_39 ( V_28 , V_61 , V_100 , & V_19 ) ;
if ( error == - V_64 ) {
F_36 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
goto V_106;
}
if ( error )
goto V_108;
V_19 -> V_109 = V_101 ;
V_19 -> V_110 = V_102 ;
V_19 -> V_20 = - 1 ;
F_61 ( & V_19 -> V_96 ) ;
if ( F_55 ( V_28 ) ) {
int V_111 = F_62 ( V_19 ) ;
if ( V_111 == F_63 () )
V_111 = 0 ;
V_19 -> V_20 = V_111 ;
}
error = F_48 ( V_19 , & V_28 -> V_94 [ V_102 ] . V_95 ) ;
V_108:
F_36 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
V_97:
* V_63 = V_19 ;
return error ;
}
static void F_64 ( struct V_27 * V_28 , T_1 V_101 )
{
struct V_66 * V_112 ;
struct V_18 * V_19 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_28 -> V_105 ; V_113 ++ ) {
F_35 ( & V_28 -> V_94 [ V_113 ] . V_107 ) ;
for ( V_112 = F_65 ( & V_28 -> V_94 [ V_113 ] . V_95 ) ; V_112 ; V_112 = F_66 ( V_112 ) ) {
V_19 = F_47 ( V_112 , struct V_18 , V_65 ) ;
if ( V_19 -> V_109 == V_101 )
F_5 ( V_19 ) ;
}
F_36 ( & V_28 -> V_94 [ V_113 ] . V_107 ) ;
}
}
static inline void F_67 ( struct V_18 * V_19 )
{
F_53 ( & V_19 -> V_96 ) ;
}
void F_68 ( struct V_18 * V_19 )
{
F_67 ( V_19 ) ;
}
static void F_69 ( struct V_114 * V_114 )
{
struct V_18 * V_19 = F_70 ( V_114 , struct V_18 , V_96 ) ;
struct V_27 * V_28 = V_19 -> V_67 ;
F_20 (list_empty(&r->res_root_list), dlm_print_rsb(r);) ;
F_61 ( & V_19 -> V_96 ) ;
F_54 ( & V_19 -> V_65 , & V_28 -> V_94 [ V_19 -> V_110 ] . V_95 ) ;
F_48 ( V_19 , & V_28 -> V_94 [ V_19 -> V_110 ] . V_98 ) ;
V_19 -> V_115 = V_116 ;
if ( V_19 -> V_117 ) {
F_71 ( V_19 -> V_117 ) ;
V_19 -> V_117 = NULL ;
}
}
static void F_72 ( struct V_18 * V_19 )
{
struct V_27 * V_28 = V_19 -> V_67 ;
T_1 V_102 = V_19 -> V_110 ;
F_35 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
F_73 ( & V_19 -> V_96 , F_69 ) ;
F_36 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
}
void F_74 ( struct V_18 * V_19 )
{
F_72 ( V_19 ) ;
}
static void F_75 ( struct V_18 * V_19 )
{
int V_41 ;
V_41 = F_73 ( & V_19 -> V_96 , F_69 ) ;
F_20 (!rv, dlm_dump_rsb(r);) ;
}
static void F_76 ( struct V_114 * V_114 )
{
struct V_18 * V_19 = F_70 ( V_114 , struct V_18 , V_96 ) ;
F_20 (list_empty(&r->res_lookup), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_grantqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_convertqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_waitqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_root_list), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_recover_list), dlm_dump_rsb(r);) ;
}
static void F_77 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_67 ( V_19 ) ;
V_5 -> V_118 = V_19 ;
}
static void F_78 ( struct V_4 * V_5 )
{
if ( V_5 -> V_118 ) {
F_72 ( V_5 -> V_118 ) ;
V_5 -> V_118 = NULL ;
}
}
static int F_79 ( struct V_27 * V_28 , struct V_4 * * V_119 )
{
struct V_4 * V_5 ;
int V_41 , V_120 ;
V_5 = F_80 ( V_28 ) ;
if ( ! V_5 )
return - V_60 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_14 = V_121 ;
F_61 ( & V_5 -> V_122 ) ;
F_44 ( & V_5 -> V_123 ) ;
F_44 ( & V_5 -> V_124 ) ;
F_44 ( & V_5 -> V_125 ) ;
F_44 ( & V_5 -> V_126 ) ;
F_43 ( & V_5 -> V_127 ) ;
F_81 ( & V_5 -> V_128 , V_129 ) ;
V_106:
V_41 = F_82 ( & V_28 -> V_130 , V_131 ) ;
if ( ! V_41 )
return - V_60 ;
F_35 ( & V_28 -> V_132 ) ;
V_41 = F_83 ( & V_28 -> V_130 , V_5 , 1 , & V_120 ) ;
if ( ! V_41 )
V_5 -> V_8 = V_120 ;
F_36 ( & V_28 -> V_132 ) ;
if ( V_41 == - V_64 )
goto V_106;
if ( V_41 < 0 ) {
F_84 ( V_28 , L_11 , V_41 ) ;
return V_41 ;
}
* V_119 = V_5 ;
return 0 ;
}
static int F_85 ( struct V_27 * V_28 , T_1 V_133 , struct V_4 * * V_119 )
{
struct V_4 * V_5 ;
F_35 ( & V_28 -> V_132 ) ;
V_5 = F_86 ( & V_28 -> V_130 , V_133 ) ;
if ( V_5 )
F_53 ( & V_5 -> V_122 ) ;
F_36 ( & V_28 -> V_132 ) ;
* V_119 = V_5 ;
return V_5 ? 0 : - V_134 ;
}
static void F_87 ( struct V_114 * V_114 )
{
struct V_4 * V_5 = F_70 ( V_114 , struct V_4 , V_122 ) ;
F_20 (!lkb->lkb_status, dlm_print_lkb(lkb);) ;
}
static int F_88 ( struct V_27 * V_28 , struct V_4 * V_5 )
{
T_1 V_133 = V_5 -> V_8 ;
F_35 ( & V_28 -> V_132 ) ;
if ( F_73 ( & V_5 -> V_122 , F_87 ) ) {
F_89 ( & V_28 -> V_130 , V_133 ) ;
F_36 ( & V_28 -> V_132 ) ;
F_78 ( V_5 ) ;
if ( V_5 -> V_135 && F_22 ( V_5 ) )
F_71 ( V_5 -> V_135 ) ;
F_90 ( V_5 ) ;
return 1 ;
} else {
F_36 ( & V_28 -> V_132 ) ;
return 0 ;
}
}
int F_91 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
F_20 (lkb->lkb_resource, dlm_print_lkb(lkb);) ;
F_20 (lkb->lkb_resource->res_ls, dlm_print_lkb(lkb);) ;
V_28 = V_5 -> V_118 -> V_67 ;
return F_88 ( V_28 , V_5 ) ;
}
static inline void F_92 ( struct V_4 * V_5 )
{
F_53 ( & V_5 -> V_122 ) ;
}
static inline void F_93 ( struct V_4 * V_5 )
{
int V_41 ;
V_41 = F_73 ( & V_5 -> V_122 , F_87 ) ;
F_20 (!rv, dlm_print_lkb(lkb);) ;
}
static void F_94 ( struct V_136 * V_137 , struct V_136 * V_138 ,
int V_139 )
{
struct V_4 * V_5 = NULL ;
F_7 (lkb, head, lkb_statequeue)
if ( V_5 -> V_13 < V_139 )
break;
F_95 ( V_137 , V_5 -> V_140 . V_141 , & V_5 -> V_140 ) ;
}
static void F_96 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_142 )
{
F_53 ( & V_5 -> V_122 ) ;
F_20 (!lkb->lkb_status, dlm_print_lkb(lkb);) ;
V_5 -> V_143 = F_97 () ;
V_5 -> V_12 = V_142 ;
switch ( V_142 ) {
case V_144 :
if ( V_5 -> V_10 & V_145 )
F_38 ( & V_5 -> V_140 , & V_19 -> V_73 ) ;
else
F_98 ( & V_5 -> V_140 , & V_19 -> V_73 ) ;
break;
case V_35 :
F_94 ( & V_5 -> V_140 , & V_19 -> V_71 ,
V_5 -> V_14 ) ;
break;
case V_146 :
if ( V_5 -> V_10 & V_145 )
F_38 ( & V_5 -> V_140 , & V_19 -> V_72 ) ;
else
F_98 ( & V_5 -> V_140 ,
& V_19 -> V_72 ) ;
break;
default:
F_20 ( 0 , dlm_print_lkb(lkb); printk(L_12, status);) ;
}
}
static void F_99 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_12 = 0 ;
F_42 ( & V_5 -> V_140 ) ;
F_93 ( V_5 ) ;
}
static void F_100 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_147 )
{
F_92 ( V_5 ) ;
F_99 ( V_19 , V_5 ) ;
F_96 ( V_19 , V_5 , V_147 ) ;
F_93 ( V_5 ) ;
}
static int F_101 ( int V_148 )
{
switch ( V_148 ) {
case V_149 :
return V_150 ;
case V_151 :
return V_152 ;
case V_153 :
return V_154 ;
case V_155 :
return V_156 ;
case V_157 :
return V_158 ;
}
return - 1 ;
}
static int F_102 ( int V_111 , int V_159 , int * V_160 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_159 ; V_113 ++ ) {
if ( ! V_160 [ V_113 ] ) {
V_160 [ V_113 ] = V_111 ;
return 0 ;
}
if ( V_160 [ V_113 ] == V_111 )
return 1 ;
}
return 0 ;
}
void F_103 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
T_2 V_161 = F_104 ( 0 , 0 ) ;
T_3 V_162 ;
T_3 V_163 = 0 ;
T_4 V_164 = 0 ;
T_4 V_165 = 0 ;
int V_159 = 0 ;
int * V_160 = NULL ;
if ( ! V_56 . V_166 )
return;
F_105 ( & V_28 -> V_167 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_106 ( V_5 -> V_168 , V_161 ) )
continue;
V_164 ++ ;
V_162 = F_107 ( F_108 ( F_97 () , V_5 -> V_168 ) ) ;
if ( V_162 < V_56 . V_166 )
continue;
V_5 -> V_168 = V_161 ;
V_165 ++ ;
if ( V_162 > V_163 )
V_163 = V_162 ;
if ( ! V_159 ) {
V_159 = V_28 -> V_169 ;
V_160 = F_109 ( V_159 * sizeof( int ) , V_170 ) ;
}
if ( ! V_160 )
continue;
if ( F_102 ( V_5 -> V_16 , V_159 , V_160 ) )
continue;
F_84 ( V_28 , L_13
L_14 , V_5 -> V_8 , ( long long ) V_162 ,
V_56 . V_166 , V_5 -> V_16 ) ;
}
F_110 ( & V_28 -> V_167 ) ;
F_111 ( V_160 ) ;
if ( V_165 )
F_40 ( V_28 , L_15 ,
V_164 , V_165 ,
V_56 . V_166 , ( long long ) V_163 ) ;
}
static int F_112 ( struct V_4 * V_5 , int V_148 , int V_171 )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
int error = 0 ;
F_105 ( & V_28 -> V_167 ) ;
if ( F_25 ( V_5 ) ||
( F_26 ( V_5 ) && ( V_148 == V_155 ) ) ) {
error = - V_103 ;
goto V_97;
}
if ( V_5 -> V_15 || F_26 ( V_5 ) ) {
switch ( V_148 ) {
case V_153 :
V_5 -> V_11 |= V_39 ;
break;
case V_155 :
V_5 -> V_11 |= V_40 ;
break;
default:
error = - V_172 ;
goto V_97;
}
V_5 -> V_173 ++ ;
F_92 ( V_5 ) ;
F_40 ( V_28 , L_16 ,
V_5 -> V_8 , V_5 -> V_15 , V_148 ,
V_5 -> V_173 , V_5 -> V_11 ) ;
goto V_97;
}
F_20 (!lkb->lkb_wait_count,
dlm_print_lkb(lkb);
printk(L_17, lkb->lkb_wait_count);) ;
V_5 -> V_173 ++ ;
V_5 -> V_15 = V_148 ;
V_5 -> V_168 = F_97 () ;
V_5 -> V_16 = V_171 ;
F_92 ( V_5 ) ;
F_38 ( & V_5 -> V_174 , & V_28 -> V_175 ) ;
V_97:
if ( error )
F_84 ( V_28 , L_18 ,
V_5 -> V_8 , error , V_5 -> V_11 , V_148 ,
V_5 -> V_15 , V_5 -> V_118 -> V_24 ) ;
F_110 ( & V_28 -> V_167 ) ;
return error ;
}
static int F_113 ( struct V_4 * V_5 , int V_148 ,
struct V_176 * V_177 )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
int V_178 = 0 ;
if ( F_25 ( V_5 ) && ( V_148 == V_154 ) ) {
F_40 ( V_28 , L_19 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_39 ;
V_178 = 1 ;
goto V_179;
}
if ( F_26 ( V_5 ) && ( V_148 == V_156 ) ) {
F_40 ( V_28 , L_20 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_40 ;
V_178 = 1 ;
goto V_179;
}
if ( ( V_148 == V_156 ) &&
( V_5 -> V_15 != V_155 ) ) {
F_40 ( V_28 , L_21 ,
V_5 -> V_8 , V_5 -> V_15 ) ;
return - 1 ;
}
if ( ( V_148 == V_152 ) &&
( V_5 -> V_15 == V_151 ) &&
F_26 ( V_5 ) && V_177 && ! V_177 -> V_180 ) {
F_40 ( V_28 , L_22 ,
V_5 -> V_8 ) ;
V_5 -> V_15 = 0 ;
V_5 -> V_11 &= ~ V_40 ;
V_5 -> V_173 -- ;
goto V_179;
}
if ( V_5 -> V_15 ) {
V_5 -> V_15 = 0 ;
goto V_179;
}
F_84 ( V_28 , L_23 ,
V_5 -> V_8 , V_177 ? V_177 -> V_181 . V_182 : 0 , V_5 -> V_9 ,
V_148 , V_5 -> V_11 ) ;
return - 1 ;
V_179:
if ( V_178 && V_5 -> V_15 ) {
F_84 ( V_28 , L_24 ,
V_5 -> V_8 , V_148 , V_5 -> V_15 ) ;
V_5 -> V_173 -- ;
V_5 -> V_15 = 0 ;
}
F_20 (lkb->lkb_wait_count, dlm_print_lkb(lkb);) ;
V_5 -> V_11 &= ~ V_183 ;
V_5 -> V_173 -- ;
if ( ! V_5 -> V_173 )
F_114 ( & V_5 -> V_174 ) ;
F_93 ( V_5 ) ;
return 0 ;
}
static int F_115 ( struct V_4 * V_5 , int V_148 )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
int error ;
F_105 ( & V_28 -> V_167 ) ;
error = F_113 ( V_5 , V_148 , NULL ) ;
F_110 ( & V_28 -> V_167 ) ;
return error ;
}
static int F_116 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
int error ;
if ( V_177 -> V_184 != V_185 )
F_105 ( & V_28 -> V_167 ) ;
error = F_113 ( V_5 , V_177 -> V_186 , V_177 ) ;
if ( V_177 -> V_184 != V_185 )
F_110 ( & V_28 -> V_167 ) ;
return error ;
}
static void F_117 ( struct V_18 * V_19 )
{
int V_171 ;
if ( F_55 ( V_19 -> V_67 ) )
return;
V_171 = F_62 ( V_19 ) ;
if ( V_171 != F_63 () )
F_118 ( V_19 ) ;
else
F_119 ( V_19 -> V_67 , V_171 ,
V_19 -> V_24 , V_19 -> V_68 ) ;
}
static int F_120 ( struct V_27 * V_28 , int V_93 )
{
struct V_66 * V_112 ;
struct V_18 * V_19 ;
int V_53 = 0 , V_84 ;
for (; ; ) {
V_84 = 0 ;
F_35 ( & V_28 -> V_94 [ V_93 ] . V_107 ) ;
for ( V_112 = F_65 ( & V_28 -> V_94 [ V_93 ] . V_98 ) ; V_112 ; V_112 = F_66 ( V_112 ) ) {
V_19 = F_47 ( V_112 , struct V_18 , V_65 ) ;
if ( ! F_121 ( V_116 , V_19 -> V_115 +
V_56 . V_187 * V_188 ) )
continue;
V_84 = 1 ;
break;
}
if ( ! V_84 ) {
F_36 ( & V_28 -> V_94 [ V_93 ] . V_107 ) ;
break;
}
if ( F_73 ( & V_19 -> V_96 , F_76 ) ) {
F_54 ( & V_19 -> V_65 , & V_28 -> V_94 [ V_93 ] . V_98 ) ;
F_36 ( & V_28 -> V_94 [ V_93 ] . V_107 ) ;
if ( F_122 ( V_19 ) )
F_117 ( V_19 ) ;
F_123 ( V_19 ) ;
V_53 ++ ;
} else {
F_36 ( & V_28 -> V_94 [ V_93 ] . V_107 ) ;
F_84 ( V_28 , L_25 , V_19 -> V_24 ) ;
}
}
return V_53 ;
}
void F_124 ( struct V_27 * V_28 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_28 -> V_105 ; V_113 ++ ) {
F_120 ( V_28 , V_113 ) ;
if ( F_125 ( V_28 ) )
break;
F_126 () ;
}
}
static void F_127 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
if ( F_22 ( V_5 ) )
return;
if ( F_128 ( V_189 , & V_28 -> V_190 ) &&
! ( V_5 -> V_10 & V_191 ) ) {
V_5 -> V_11 |= V_192 ;
goto V_193;
}
if ( V_5 -> V_10 & V_194 )
goto V_193;
return;
V_193:
F_20 (list_empty(&lkb->lkb_time_list), dlm_print_lkb(lkb);) ;
F_105 ( & V_28 -> V_195 ) ;
F_92 ( V_5 ) ;
F_98 ( & V_5 -> V_125 , & V_28 -> V_196 ) ;
F_110 ( & V_28 -> V_195 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
F_105 ( & V_28 -> V_195 ) ;
if ( ! F_6 ( & V_5 -> V_125 ) ) {
F_114 ( & V_5 -> V_125 ) ;
F_93 ( V_5 ) ;
}
F_110 ( & V_28 -> V_195 ) ;
}
void F_129 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
struct V_4 * V_5 ;
int V_197 , V_198 ;
T_3 V_199 ;
for (; ; ) {
if ( F_125 ( V_28 ) )
break;
V_197 = 0 ;
V_198 = 0 ;
F_105 ( & V_28 -> V_195 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list) {
V_199 = F_107 ( F_108 ( F_97 () ,
V_5 -> V_143 ) ) ;
if ( ( V_5 -> V_10 & V_194 ) &&
V_199 >= ( V_5 -> V_200 * 10000 ) )
V_197 = 1 ;
if ( ( V_5 -> V_11 & V_192 ) &&
V_199 >= V_56 . V_201 * 10000 )
V_198 = 1 ;
if ( ! V_197 && ! V_198 )
continue;
F_92 ( V_5 ) ;
break;
}
F_110 ( & V_28 -> V_195 ) ;
if ( ! V_197 && ! V_198 )
break;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
if ( V_198 ) {
V_5 -> V_11 &= ~ V_192 ;
if ( ! ( V_5 -> V_10 & V_194 ) )
F_29 ( V_5 ) ;
F_131 ( V_5 ) ;
}
if ( V_197 ) {
F_40 ( V_28 , L_26 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_24 ) ;
V_5 -> V_11 &= ~ V_192 ;
V_5 -> V_11 |= V_43 ;
F_29 ( V_5 ) ;
F_132 ( V_19 , V_5 ) ;
}
F_133 ( V_19 ) ;
F_75 ( V_19 ) ;
F_91 ( V_5 ) ;
}
}
void F_134 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
T_5 V_202 = F_135 ( V_116 - V_28 -> V_203 ) ;
V_28 -> V_203 = 0 ;
F_105 ( & V_28 -> V_195 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list)
V_5 -> V_143 = F_136 ( V_5 -> V_143 , V_202 ) ;
F_110 ( & V_28 -> V_195 ) ;
if ( ! V_56 . V_166 )
return;
F_105 ( & V_28 -> V_167 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_107 ( V_5 -> V_168 ) )
V_5 -> V_168 = F_97 () ;
}
F_110 ( & V_28 -> V_167 ) ;
}
static void F_137 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_93 , V_62 = V_19 -> V_67 -> V_204 ;
V_93 = V_205 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_93 == 1 ) {
if ( ! V_5 -> V_135 )
return;
if ( ! ( V_5 -> V_10 & V_206 ) )
return;
if ( ! V_19 -> V_117 )
return;
memcpy ( V_5 -> V_135 , V_19 -> V_117 , V_62 ) ;
V_5 -> V_207 = V_19 -> V_208 ;
} else if ( V_93 == 0 ) {
if ( V_5 -> V_10 & V_209 ) {
F_57 ( V_19 , V_210 ) ;
return;
}
if ( ! V_5 -> V_135 )
return;
if ( ! ( V_5 -> V_10 & V_206 ) )
return;
if ( ! V_19 -> V_117 )
V_19 -> V_117 = F_138 ( V_19 -> V_67 ) ;
if ( ! V_19 -> V_117 )
return;
memcpy ( V_19 -> V_117 , V_5 -> V_135 , V_62 ) ;
V_19 -> V_208 ++ ;
V_5 -> V_207 = V_19 -> V_208 ;
F_56 ( V_19 , V_210 ) ;
}
if ( F_58 ( V_19 , V_210 ) )
V_5 -> V_32 |= V_211 ;
}
static void F_139 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 < V_212 )
return;
if ( V_5 -> V_10 & V_209 ) {
F_57 ( V_19 , V_210 ) ;
return;
}
if ( ! V_5 -> V_135 )
return;
if ( ! ( V_5 -> V_10 & V_206 ) )
return;
if ( ! V_19 -> V_117 )
V_19 -> V_117 = F_138 ( V_19 -> V_67 ) ;
if ( ! V_19 -> V_117 )
return;
memcpy ( V_19 -> V_117 , V_5 -> V_135 , V_19 -> V_67 -> V_204 ) ;
V_19 -> V_208 ++ ;
F_56 ( V_19 , V_210 ) ;
}
static void F_140 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
int V_93 ;
if ( ! V_5 -> V_135 )
return;
if ( ! ( V_5 -> V_10 & V_206 ) )
return;
V_93 = V_205 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_93 == 1 ) {
int V_62 = F_141 ( V_177 ) ;
if ( V_62 > V_76 )
V_62 = V_76 ;
memcpy ( V_5 -> V_135 , V_177 -> V_213 , V_62 ) ;
V_5 -> V_207 = V_177 -> V_214 ;
}
}
static void F_142 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_99 ( V_19 , V_5 ) ;
V_5 -> V_14 = V_121 ;
F_93 ( V_5 ) ;
}
static void F_143 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_139 ( V_19 , V_5 ) ;
F_142 ( V_19 , V_5 ) ;
}
static void F_144 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_142 ( V_19 , V_5 ) ;
}
static int F_145 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_41 = 0 ;
V_5 -> V_13 = V_121 ;
switch ( V_5 -> V_12 ) {
case V_35 :
break;
case V_146 :
F_100 ( V_19 , V_5 , V_35 ) ;
V_41 = 1 ;
break;
case V_144 :
F_99 ( V_19 , V_5 ) ;
V_5 -> V_14 = V_121 ;
F_93 ( V_5 ) ;
V_41 = - 1 ;
break;
default:
F_49 ( L_27 , V_5 -> V_12 ) ;
}
return V_41 ;
}
static int F_146 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_145 ( V_19 , V_5 ) ;
}
static void F_147 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 != V_5 -> V_13 ) {
V_5 -> V_14 = V_5 -> V_13 ;
if ( V_5 -> V_12 )
F_100 ( V_19 , V_5 , V_35 ) ;
else
F_96 ( V_19 , V_5 , V_35 ) ;
}
V_5 -> V_13 = V_121 ;
V_5 -> V_215 = 0 ;
}
static void F_148 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_137 ( V_19 , V_5 ) ;
F_147 ( V_19 , V_5 ) ;
}
static void F_149 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
F_140 ( V_19 , V_5 , V_177 ) ;
F_147 ( V_19 , V_5 ) ;
}
static void F_150 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_148 ( V_19 , V_5 ) ;
if ( F_22 ( V_5 ) )
F_151 ( V_19 , V_5 ) ;
else
F_28 ( V_19 , V_5 , 0 ) ;
}
static void F_152 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 == V_121 || V_5 -> V_14 == V_121 ) {
F_49 ( L_28 ,
V_5 -> V_8 , V_5 -> V_14 , V_5 -> V_13 ) ;
return;
}
V_5 -> V_14 = V_216 ;
}
static void F_153 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
if ( V_177 -> V_186 != V_150 &&
V_177 -> V_186 != V_217 ) {
F_49 ( L_29 ,
V_5 -> V_8 , V_177 -> V_186 ) ;
return;
}
if ( V_5 -> V_10 & V_218 )
V_5 -> V_13 = V_37 ;
else if ( V_5 -> V_10 & V_219 )
V_5 -> V_13 = V_38 ;
else {
F_49 ( L_30 , V_5 -> V_10 ) ;
F_2 ( V_5 ) ;
}
}
static inline int F_154 ( struct V_4 * V_5 , struct V_136 * V_138 )
{
struct V_4 * V_220 = F_155 ( V_138 -> V_221 , struct V_4 ,
V_140 ) ;
if ( V_5 -> V_8 == V_220 -> V_8 )
return 1 ;
return 0 ;
}
static int F_156 ( struct V_136 * V_138 , struct V_4 * V_5 )
{
struct V_4 * V_222 ;
F_7 (this, head, lkb_statequeue) {
if ( V_222 == V_5 )
continue;
if ( ! F_157 ( V_222 , V_5 ) )
return 1 ;
}
return 0 ;
}
static int F_158 ( struct V_18 * V_19 , struct V_4 * V_223 )
{
struct V_4 * V_224 ;
int V_225 = 0 ;
F_7 (lkb1, &r->res_convertqueue, lkb_statequeue) {
if ( V_224 == V_223 ) {
V_225 = 1 ;
continue;
}
if ( ! V_225 ) {
if ( ! F_157 ( V_223 , V_224 ) )
return 1 ;
} else {
if ( ! F_157 ( V_223 , V_224 ) &&
! F_157 ( V_224 , V_223 ) )
return 1 ;
}
}
return 0 ;
}
static int F_159 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_226 )
{
T_6 V_227 = ( V_5 -> V_14 != V_121 ) ;
if ( V_5 -> V_10 & V_228 )
return 1 ;
if ( F_156 ( & V_19 -> V_71 , V_5 ) )
goto V_97;
if ( F_156 ( & V_19 -> V_72 , V_5 ) )
goto V_97;
if ( V_226 && V_227 && ! ( V_5 -> V_10 & V_229 ) )
return 1 ;
if ( V_226 && V_227 && ( V_5 -> V_10 & V_229 ) ) {
if ( F_6 ( & V_19 -> V_72 ) )
return 1 ;
else
goto V_97;
}
if ( V_5 -> V_10 & V_230 )
return 1 ;
if ( ! V_226 && V_227 && F_154 ( V_5 , & V_19 -> V_72 ) )
return 1 ;
if ( V_226 && ! V_227 && F_6 ( & V_19 -> V_72 ) &&
F_6 ( & V_19 -> V_73 ) )
return 1 ;
if ( ! V_226 && ! V_227 && F_6 ( & V_19 -> V_72 ) &&
F_154 ( V_5 , & V_19 -> V_73 ) )
return 1 ;
V_97:
return 0 ;
}
static int F_160 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_226 ,
int * V_231 )
{
int V_41 ;
T_6 V_232 = 0 , V_49 = V_5 -> V_13 ;
T_6 V_233 = ( V_5 -> V_14 != V_121 ) ;
if ( V_231 )
* V_231 = 0 ;
V_41 = F_159 ( V_19 , V_5 , V_226 ) ;
if ( V_41 )
goto V_97;
if ( V_233 && F_14 ( V_5 ) &&
F_158 ( V_19 , V_5 ) ) {
if ( V_5 -> V_10 & V_234 ) {
V_5 -> V_14 = V_216 ;
V_5 -> V_32 |= V_33 ;
} else if ( ! ( V_5 -> V_10 & V_191 ) ) {
if ( V_231 )
* V_231 = - V_46 ;
else {
F_49 ( L_31 ,
V_5 -> V_8 , V_226 ) ;
F_5 ( V_19 ) ;
}
}
goto V_97;
}
if ( V_49 != V_37 && ( V_5 -> V_10 & V_218 ) )
V_232 = V_37 ;
else if ( V_49 != V_38 && ( V_5 -> V_10 & V_219 ) )
V_232 = V_38 ;
if ( V_232 ) {
V_5 -> V_13 = V_232 ;
V_41 = F_159 ( V_19 , V_5 , V_226 ) ;
if ( V_41 )
V_5 -> V_32 |= V_34 ;
else
V_5 -> V_13 = V_49 ;
}
V_97:
return V_41 ;
}
static int F_161 ( struct V_18 * V_19 , int V_235 , int * V_236 ,
unsigned int * V_53 )
{
struct V_4 * V_5 , * V_237 ;
int V_238 , V_239 , V_240 , V_241 , V_242 ;
int V_243 ;
V_240 = 0 ;
V_244:
V_241 = 0 ;
V_242 = 0 ;
V_238 = V_121 ;
F_162 (lkb, s, &r->res_convertqueue, lkb_statequeue) {
V_239 = F_16 ( V_5 ) ;
V_243 = 0 ;
if ( F_160 ( V_19 , V_5 , 0 , & V_243 ) ) {
F_150 ( V_19 , V_5 ) ;
V_241 = 1 ;
if ( V_53 )
( * V_53 ) ++ ;
continue;
}
if ( ! V_239 && F_16 ( V_5 ) ) {
F_49 ( L_32 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_24 ) ;
V_242 = 1 ;
continue;
}
if ( V_243 ) {
F_49 ( L_33 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_24 ) ;
F_5 ( V_19 ) ;
continue;
}
V_238 = F_163 ( int , V_5 -> V_13 , V_238 ) ;
if ( V_236 && V_5 -> V_13 == V_38 )
* V_236 = 1 ;
}
if ( V_241 )
goto V_244;
if ( V_242 && ! V_240 ) {
V_240 = 1 ;
goto V_244;
}
return F_163 ( int , V_235 , V_238 ) ;
}
static int F_164 ( struct V_18 * V_19 , int V_235 , int * V_236 ,
unsigned int * V_53 )
{
struct V_4 * V_5 , * V_237 ;
F_162 (lkb, s, &r->res_waitqueue, lkb_statequeue) {
if ( F_160 ( V_19 , V_5 , 0 , NULL ) ) {
F_150 ( V_19 , V_5 ) ;
if ( V_53 )
( * V_53 ) ++ ;
} else {
V_235 = F_163 ( int , V_5 -> V_13 , V_235 ) ;
if ( V_5 -> V_13 == V_38 )
* V_236 = 1 ;
}
}
return V_235 ;
}
static int F_165 ( struct V_4 * V_245 , int V_235 , int V_236 )
{
if ( V_245 -> V_14 == V_37 && V_236 ) {
if ( V_245 -> V_215 < V_246 )
return 1 ;
return 0 ;
}
if ( V_245 -> V_215 < V_235 &&
! V_3 [ V_245 -> V_14 + 1 ] [ V_235 + 1 ] )
return 1 ;
return 0 ;
}
static void F_166 ( struct V_18 * V_19 , unsigned int * V_53 )
{
struct V_4 * V_5 , * V_237 ;
int V_235 = V_121 ;
int V_236 = 0 ;
if ( ! F_122 ( V_19 ) ) {
F_49 ( L_34 , V_19 -> V_20 ) ;
F_5 ( V_19 ) ;
return;
}
V_235 = F_161 ( V_19 , V_235 , & V_236 , V_53 ) ;
V_235 = F_164 ( V_19 , V_235 , & V_236 , V_53 ) ;
if ( V_235 == V_121 )
return;
F_162 (lkb, s, &r->res_grantqueue, lkb_statequeue) {
if ( V_5 -> V_247 && F_165 ( V_5 , V_235 , V_236 ) ) {
if ( V_236 && V_235 == V_37 &&
V_5 -> V_14 == V_37 )
F_32 ( V_19 , V_5 , V_38 ) ;
else
F_32 ( V_19 , V_5 , V_235 ) ;
V_5 -> V_215 = V_235 ;
}
}
}
static int F_167 ( struct V_4 * V_245 , struct V_4 * V_248 )
{
if ( ( V_245 -> V_14 == V_37 && V_248 -> V_13 == V_38 ) ||
( V_245 -> V_14 == V_38 && V_248 -> V_13 == V_37 ) ) {
if ( V_245 -> V_215 < V_246 )
return 1 ;
return 0 ;
}
if ( V_245 -> V_215 < V_248 -> V_13 && ! F_157 ( V_245 , V_248 ) )
return 1 ;
return 0 ;
}
static void F_168 ( struct V_18 * V_19 , struct V_136 * V_138 ,
struct V_4 * V_5 )
{
struct V_4 * V_245 ;
F_7 (gr, head, lkb_statequeue) {
if ( V_245 == V_5 )
continue;
if ( V_245 -> V_247 && F_167 ( V_245 , V_5 ) ) {
F_32 ( V_19 , V_245 , V_5 -> V_13 ) ;
V_245 -> V_215 = V_5 -> V_13 ;
}
}
}
static void F_169 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_168 ( V_19 , & V_19 -> V_71 , V_5 ) ;
}
static void F_170 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_168 ( V_19 , & V_19 -> V_71 , V_5 ) ;
F_168 ( V_19 , & V_19 -> V_72 , V_5 ) ;
}
static int F_171 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_27 * V_28 = V_19 -> V_67 ;
int V_113 , error , V_249 , V_250 , V_251 = F_63 () ;
if ( F_58 ( V_19 , V_99 ) ) {
F_56 ( V_19 , V_99 ) ;
V_19 -> V_22 = V_5 -> V_8 ;
V_5 -> V_7 = V_19 -> V_20 ;
return 0 ;
}
if ( V_19 -> V_22 && V_19 -> V_22 != V_5 -> V_8 ) {
F_98 ( & V_5 -> V_124 , & V_19 -> V_70 ) ;
return 1 ;
}
if ( V_19 -> V_20 == 0 ) {
V_5 -> V_7 = 0 ;
return 0 ;
}
if ( V_19 -> V_20 > 0 ) {
V_5 -> V_7 = V_19 -> V_20 ;
return 0 ;
}
F_20 (r->res_nodeid == -1 , dlm_dump_rsb(r);) ;
V_249 = F_62 ( V_19 ) ;
if ( V_249 != V_251 ) {
V_19 -> V_22 = V_5 -> V_8 ;
F_172 ( V_19 , V_5 ) ;
return 1 ;
}
for ( V_113 = 0 ; V_113 < 2 ; V_113 ++ ) {
error = F_173 ( V_28 , V_251 , V_19 -> V_24 ,
V_19 -> V_68 , & V_250 ) ;
if ( ! error )
break;
F_40 ( V_28 , L_35 , error , V_19 -> V_24 ) ;
F_174 () ;
}
if ( error && error != - V_92 )
return error ;
if ( V_250 == V_251 ) {
V_19 -> V_22 = 0 ;
V_19 -> V_20 = 0 ;
V_5 -> V_7 = 0 ;
} else {
V_19 -> V_22 = V_5 -> V_8 ;
V_19 -> V_20 = V_250 ;
V_5 -> V_7 = V_250 ;
}
return 0 ;
}
static void F_175 ( struct V_18 * V_19 )
{
struct V_4 * V_5 , * V_252 ;
F_162 (lkb, safe, &r->res_lookup, lkb_rsb_lookup) {
F_114 ( & V_5 -> V_124 ) ;
F_176 ( V_19 , V_5 ) ;
F_174 () ;
}
}
static void F_177 ( struct V_18 * V_19 , int error )
{
struct V_4 * V_5 ;
if ( ! V_19 -> V_22 )
return;
switch ( error ) {
case 0 :
case - V_253 :
V_19 -> V_22 = 0 ;
F_175 ( V_19 ) ;
break;
case - V_64 :
case - V_85 :
case - V_87 :
V_19 -> V_22 = 0 ;
if ( ! F_6 ( & V_19 -> V_70 ) ) {
V_5 = F_155 ( V_19 -> V_70 . V_221 , struct V_4 ,
V_124 ) ;
F_114 ( & V_5 -> V_124 ) ;
V_19 -> V_22 = V_5 -> V_8 ;
F_176 ( V_19 , V_5 ) ;
}
break;
default:
F_84 ( V_19 -> V_67 , L_36 , error ) ;
}
}
static int F_178 ( int V_139 , struct V_254 * V_255 , T_1 V_79 ,
int V_100 , unsigned long V_256 ,
void (* F_179) ( void * V_257 ) ,
void * V_257 ,
void (* F_180) ( void * V_257 , int V_139 ) ,
struct V_258 * args )
{
int V_41 = - V_103 ;
if ( V_139 < 0 || V_139 > V_246 )
goto V_97;
if ( ! ( V_79 & V_259 ) && ( V_100 > V_76 ) )
goto V_97;
if ( V_79 & V_260 )
goto V_97;
if ( V_79 & V_229 && ! ( V_79 & V_259 ) )
goto V_97;
if ( V_79 & V_234 && ! ( V_79 & V_259 ) )
goto V_97;
if ( V_79 & V_234 && V_79 & V_30 )
goto V_97;
if ( V_79 & V_228 && V_79 & V_259 )
goto V_97;
if ( V_79 & V_228 && V_79 & V_229 )
goto V_97;
if ( V_79 & V_228 && V_79 & V_30 )
goto V_97;
if ( V_79 & V_228 && V_139 != V_216 )
goto V_97;
if ( ! F_179 || ! V_255 )
goto V_97;
if ( V_79 & V_206 && ! V_255 -> V_261 )
goto V_97;
if ( V_79 & V_259 && ! V_255 -> V_262 )
goto V_97;
args -> V_79 = V_79 ;
args -> V_263 = F_179 ;
args -> V_257 = V_257 ;
args -> V_264 = F_180 ;
args -> V_265 = V_256 ;
args -> V_139 = V_139 ;
args -> V_255 = V_255 ;
V_41 = 0 ;
V_97:
return V_41 ;
}
static int F_181 ( T_1 V_79 , void * V_266 , struct V_258 * args )
{
if ( V_79 & ~ ( V_260 | V_206 | V_209 |
V_267 ) )
return - V_103 ;
if ( V_79 & V_260 && V_79 & V_267 )
return - V_103 ;
args -> V_79 = V_79 ;
args -> V_257 = V_266 ;
return 0 ;
}
static int F_182 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_258 * args )
{
int V_41 = - V_103 ;
if ( args -> V_79 & V_259 ) {
if ( V_5 -> V_11 & V_36 )
goto V_97;
if ( args -> V_79 & V_229 &&
! V_268 [ V_5 -> V_14 + 1 ] [ args -> V_139 + 1 ] )
goto V_97;
V_41 = - V_172 ;
if ( V_5 -> V_12 != V_35 )
goto V_97;
if ( V_5 -> V_15 )
goto V_97;
if ( F_27 ( V_5 ) )
goto V_97;
}
V_5 -> V_10 = args -> V_79 ;
V_5 -> V_32 = 0 ;
V_5 -> V_269 = args -> V_263 ;
V_5 -> V_270 = args -> V_257 ;
V_5 -> V_247 = args -> V_264 ;
V_5 -> V_13 = args -> V_139 ;
V_5 -> V_271 = args -> V_255 ;
V_5 -> V_135 = args -> V_255 -> V_261 ;
V_5 -> V_272 = ( int ) V_273 -> V_274 ;
V_5 -> V_200 = args -> V_265 ;
V_41 = 0 ;
V_97:
if ( V_41 )
F_40 ( V_28 , L_37 ,
V_41 , V_5 -> V_8 , V_5 -> V_11 , args -> V_79 ,
V_5 -> V_12 , V_5 -> V_15 ,
V_5 -> V_118 -> V_24 ) ;
return V_41 ;
}
static int F_183 ( struct V_4 * V_5 , struct V_258 * args )
{
struct V_27 * V_28 = V_5 -> V_118 -> V_67 ;
int V_41 = - V_103 ;
if ( V_5 -> V_11 & V_36 ) {
F_84 ( V_28 , L_38 , V_5 -> V_8 ) ;
F_2 ( V_5 ) ;
goto V_97;
}
if ( V_5 -> V_11 & V_275 ) {
F_40 ( V_28 , L_39 , V_5 -> V_8 ) ;
V_41 = - V_134 ;
goto V_97;
}
if ( ! F_6 ( & V_5 -> V_124 ) ) {
if ( args -> V_79 & ( V_260 | V_267 ) ) {
F_40 ( V_28 , L_40 , V_5 -> V_8 ) ;
F_114 ( & V_5 -> V_124 ) ;
F_28 ( V_5 -> V_118 , V_5 ,
args -> V_79 & V_260 ?
- V_42 : - V_48 ) ;
F_93 ( V_5 ) ;
}
V_41 = - V_172 ;
goto V_97;
}
if ( args -> V_79 & V_260 ) {
if ( V_5 -> V_10 & V_260 )
goto V_97;
if ( F_27 ( V_5 ) )
goto V_97;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_183 ) {
V_5 -> V_11 |= V_40 ;
V_41 = - V_172 ;
goto V_97;
}
if ( V_5 -> V_12 == V_35 &&
! V_5 -> V_15 ) {
V_41 = - V_172 ;
goto V_97;
}
switch ( V_5 -> V_15 ) {
case V_157 :
case V_149 :
V_5 -> V_11 |= V_40 ;
V_41 = - V_172 ;
goto V_97;
case V_153 :
case V_155 :
goto V_97;
}
goto V_276;
}
if ( args -> V_79 & V_267 ) {
if ( V_5 -> V_10 & V_267 )
goto V_97;
if ( F_25 ( V_5 ) )
goto V_97;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_183 ) {
V_5 -> V_11 |= V_39 ;
V_41 = - V_172 ;
goto V_97;
}
switch ( V_5 -> V_15 ) {
case V_157 :
case V_149 :
V_5 -> V_11 |= V_39 ;
V_41 = - V_172 ;
goto V_97;
case V_153 :
goto V_97;
}
goto V_276;
}
V_41 = - V_172 ;
if ( V_5 -> V_15 || V_5 -> V_173 )
goto V_97;
V_276:
V_5 -> V_10 |= args -> V_79 ;
V_5 -> V_32 = 0 ;
V_5 -> V_270 = args -> V_257 ;
V_41 = 0 ;
V_97:
if ( V_41 )
F_40 ( V_28 , L_41 , V_41 ,
V_5 -> V_8 , V_5 -> V_11 , V_5 -> V_10 ,
args -> V_79 , V_5 -> V_15 ,
V_5 -> V_118 -> V_24 ) ;
return V_41 ;
}
static int F_184 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error = 0 ;
if ( F_160 ( V_19 , V_5 , 1 , NULL ) ) {
F_148 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_97;
}
if ( F_14 ( V_5 ) ) {
error = - V_253 ;
F_96 ( V_19 , V_5 , V_144 ) ;
F_127 ( V_5 ) ;
goto V_97;
}
error = - V_64 ;
F_28 ( V_19 , V_5 , - V_64 ) ;
V_97:
return error ;
}
static void F_185 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case - V_64 :
if ( F_15 ( V_5 ) )
F_170 ( V_19 , V_5 ) ;
break;
case - V_253 :
F_169 ( V_19 , V_5 ) ;
break;
}
}
static int F_186 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error = 0 ;
int V_243 = 0 ;
if ( F_160 ( V_19 , V_5 , 1 , & V_243 ) ) {
F_148 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_97;
}
if ( V_243 ) {
F_145 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_46 ) ;
error = - V_46 ;
goto V_97;
}
if ( F_16 ( V_5 ) ) {
F_161 ( V_19 , V_121 , NULL , NULL ) ;
if ( F_159 ( V_19 , V_5 , 1 ) ) {
F_148 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_97;
}
}
if ( F_14 ( V_5 ) ) {
error = - V_253 ;
F_99 ( V_19 , V_5 ) ;
F_96 ( V_19 , V_5 , V_146 ) ;
F_127 ( V_5 ) ;
goto V_97;
}
error = - V_64 ;
F_28 ( V_19 , V_5 , - V_64 ) ;
V_97:
return error ;
}
static void F_187 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case 0 :
F_166 ( V_19 , NULL ) ;
break;
case - V_64 :
if ( F_15 ( V_5 ) )
F_170 ( V_19 , V_5 ) ;
break;
case - V_253 :
F_169 ( V_19 , V_5 ) ;
break;
}
}
static int F_188 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_143 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_48 ) ;
return - V_48 ;
}
static void F_189 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
F_166 ( V_19 , NULL ) ;
}
static int V_197 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_145 ( V_19 , V_5 ) ;
if ( error ) {
F_28 ( V_19 , V_5 , - V_42 ) ;
return - V_42 ;
}
return 0 ;
}
static void F_190 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
if ( error )
F_166 ( V_19 , NULL ) ;
}
static int F_176 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_171 ( V_19 , V_5 ) ;
if ( error < 0 )
goto V_97;
if ( error ) {
error = 0 ;
goto V_97;
}
if ( F_19 ( V_19 ) ) {
error = F_191 ( V_19 , V_5 ) ;
} else {
error = F_184 ( V_19 , V_5 ) ;
F_185 ( V_19 , V_5 , error ) ;
}
V_97:
return error ;
}
static int F_192 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_193 ( V_19 , V_5 ) ;
} else {
error = F_186 ( V_19 , V_5 ) ;
F_187 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_194 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_195 ( V_19 , V_5 ) ;
} else {
error = F_188 ( V_19 , V_5 ) ;
F_189 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_132 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_196 ( V_19 , V_5 ) ;
} else {
error = V_197 ( V_19 , V_5 ) ;
F_190 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_197 ( struct V_27 * V_28 , struct V_4 * V_5 , char * V_61 ,
int V_62 , struct V_258 * args )
{
struct V_18 * V_19 ;
int error ;
error = F_182 ( V_28 , V_5 , args ) ;
if ( error )
goto V_97;
error = F_59 ( V_28 , V_61 , V_62 , V_104 , & V_19 ) ;
if ( error )
goto V_97;
F_130 ( V_19 ) ;
F_77 ( V_19 , V_5 ) ;
V_5 -> V_271 -> V_262 = V_5 -> V_8 ;
error = F_176 ( V_19 , V_5 ) ;
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
V_97:
return error ;
}
static int F_198 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_258 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_182 ( V_28 , V_5 , args ) ;
if ( error )
goto V_97;
error = F_192 ( V_19 , V_5 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
return error ;
}
static int F_199 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_258 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_183 ( V_5 , args ) ;
if ( error )
goto V_97;
error = F_194 ( V_19 , V_5 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
return error ;
}
static int F_200 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_258 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_183 ( V_5 , args ) ;
if ( error )
goto V_97;
error = F_132 ( V_19 , V_5 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
return error ;
}
int F_201 ( T_7 * V_277 ,
int V_139 ,
struct V_254 * V_255 ,
T_1 V_79 ,
void * V_61 ,
unsigned int V_100 ,
T_1 V_278 ,
void (* F_179) ( void * V_266 ) ,
void * V_266 ,
void (* F_180) ( void * V_266 , int V_139 ) )
{
struct V_27 * V_28 ;
struct V_4 * V_5 ;
struct V_258 args ;
int error , V_279 = V_79 & V_259 ;
V_28 = F_202 ( V_277 ) ;
if ( ! V_28 )
return - V_103 ;
F_8 ( V_28 ) ;
if ( V_279 )
error = F_85 ( V_28 , V_255 -> V_262 , & V_5 ) ;
else
error = F_79 ( V_28 , & V_5 ) ;
if ( error )
goto V_97;
error = F_178 ( V_139 , V_255 , V_79 , V_100 , 0 , F_179 ,
V_266 , F_180 , & args ) ;
if ( error )
goto V_280;
if ( V_279 )
error = F_198 ( V_28 , V_5 , & args ) ;
else
error = F_197 ( V_28 , V_5 , V_61 , V_100 , & args ) ;
if ( error == - V_253 )
error = 0 ;
V_280:
if ( V_279 || error )
F_88 ( V_28 , V_5 ) ;
if ( error == - V_64 || error == - V_46 )
error = 0 ;
V_97:
F_10 ( V_28 ) ;
F_203 ( V_28 ) ;
return error ;
}
int F_204 ( T_7 * V_277 ,
T_1 V_133 ,
T_1 V_79 ,
struct V_254 * V_255 ,
void * V_266 )
{
struct V_27 * V_28 ;
struct V_4 * V_5 ;
struct V_258 args ;
int error ;
V_28 = F_202 ( V_277 ) ;
if ( ! V_28 )
return - V_103 ;
F_8 ( V_28 ) ;
error = F_85 ( V_28 , V_133 , & V_5 ) ;
if ( error )
goto V_97;
error = F_181 ( V_79 , V_266 , & args ) ;
if ( error )
goto V_280;
if ( V_79 & V_260 )
error = F_200 ( V_28 , V_5 , & args ) ;
else
error = F_199 ( V_28 , V_5 , & args ) ;
if ( error == - V_48 || error == - V_42 )
error = 0 ;
if ( error == - V_172 && ( V_79 & ( V_260 | V_267 ) ) )
error = 0 ;
V_280:
F_91 ( V_5 ) ;
V_97:
F_10 ( V_28 ) ;
F_203 ( V_28 ) ;
return error ;
}
static int F_205 ( struct V_27 * V_28 , int V_281 ,
int V_171 , int V_148 ,
struct V_176 * * V_282 ,
struct V_283 * * V_284 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
char * V_286 ;
V_285 = F_206 ( V_171 , V_281 , V_131 , & V_286 ) ;
if ( ! V_285 )
return - V_287 ;
memset ( V_286 , 0 , V_281 ) ;
V_177 = (struct V_176 * ) V_286 ;
V_177 -> V_181 . V_288 = ( V_289 | V_290 ) ;
V_177 -> V_181 . V_291 = V_28 -> V_292 ;
V_177 -> V_181 . V_182 = F_63 () ;
V_177 -> V_181 . V_293 = V_281 ;
V_177 -> V_181 . V_294 = V_295 ;
V_177 -> V_186 = V_148 ;
* V_284 = V_285 ;
* V_282 = V_177 ;
return 0 ;
}
static int F_207 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_171 , int V_148 ,
struct V_176 * * V_282 ,
struct V_283 * * V_284 )
{
int V_281 = sizeof( struct V_176 ) ;
switch ( V_148 ) {
case V_149 :
case V_157 :
case V_296 :
V_281 += V_19 -> V_68 ;
break;
case V_151 :
case V_153 :
case V_150 :
case V_152 :
case V_217 :
if ( V_5 && V_5 -> V_135 )
V_281 += V_19 -> V_67 -> V_204 ;
break;
}
return F_205 ( V_19 -> V_67 , V_281 , V_171 , V_148 ,
V_282 , V_284 ) ;
}
static int F_208 ( struct V_283 * V_285 , struct V_176 * V_177 )
{
F_209 ( V_177 ) ;
F_210 ( V_285 ) ;
return 0 ;
}
static void F_211 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
V_177 -> V_297 = V_5 -> V_7 ;
V_177 -> V_298 = V_5 -> V_272 ;
V_177 -> V_299 = V_5 -> V_8 ;
V_177 -> V_300 = V_5 -> V_9 ;
V_177 -> V_301 = V_5 -> V_10 ;
V_177 -> V_302 = V_5 -> V_32 ;
V_177 -> V_184 = V_5 -> V_11 ;
V_177 -> V_214 = V_5 -> V_207 ;
V_177 -> V_303 = V_5 -> V_12 ;
V_177 -> V_304 = V_5 -> V_14 ;
V_177 -> V_305 = V_5 -> V_13 ;
V_177 -> V_306 = V_19 -> V_109 ;
if ( V_5 -> V_247 )
V_177 -> V_307 |= V_50 ;
if ( V_5 -> V_269 )
V_177 -> V_307 |= V_47 ;
switch ( V_177 -> V_186 ) {
case V_149 :
case V_157 :
memcpy ( V_177 -> V_213 , V_19 -> V_24 , V_19 -> V_68 ) ;
break;
case V_151 :
case V_153 :
case V_150 :
case V_152 :
case V_217 :
if ( ! V_5 -> V_135 )
break;
memcpy ( V_177 -> V_213 , V_5 -> V_135 , V_19 -> V_67 -> V_204 ) ;
break;
}
}
static int F_212 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_148 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int V_171 , error ;
V_171 = V_19 -> V_20 ;
error = F_112 ( V_5 , V_148 , V_171 ) ;
if ( error )
return error ;
error = F_207 ( V_19 , V_5 , V_171 , V_148 , & V_177 , & V_285 ) ;
if ( error )
goto V_308;
F_211 ( V_19 , V_5 , V_177 ) ;
error = F_208 ( V_285 , V_177 ) ;
if ( error )
goto V_308;
return 0 ;
V_308:
F_115 ( V_5 , F_101 ( V_148 ) ) ;
return error ;
}
static int F_191 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_212 ( V_19 , V_5 , V_149 ) ;
}
static int F_193 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_212 ( V_19 , V_5 , V_151 ) ;
if ( ! error && F_24 ( V_5 ) ) {
F_115 ( V_5 , V_152 ) ;
V_19 -> V_67 -> V_309 . V_184 = V_185 ;
V_19 -> V_67 -> V_309 . V_186 = V_152 ;
V_19 -> V_67 -> V_309 . V_180 = 0 ;
F_213 ( V_19 , V_5 , & V_19 -> V_67 -> V_309 ) ;
}
return error ;
}
static int F_195 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_212 ( V_19 , V_5 , V_153 ) ;
}
static int F_196 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_212 ( V_19 , V_5 , V_155 ) ;
}
static int F_151 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int V_171 , error ;
V_171 = V_5 -> V_7 ;
error = F_207 ( V_19 , V_5 , V_171 , V_217 , & V_177 , & V_285 ) ;
if ( error )
goto V_97;
F_211 ( V_19 , V_5 , V_177 ) ;
V_177 -> V_180 = 0 ;
error = F_208 ( V_285 , V_177 ) ;
V_97:
return error ;
}
static int F_33 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_139 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int V_171 , error ;
V_171 = V_5 -> V_7 ;
error = F_207 ( V_19 , NULL , V_171 , V_310 , & V_177 , & V_285 ) ;
if ( error )
goto V_97;
F_211 ( V_19 , V_5 , V_177 ) ;
V_177 -> V_311 = V_139 ;
error = F_208 ( V_285 , V_177 ) ;
V_97:
return error ;
}
static int F_172 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int V_171 , error ;
V_171 = F_62 ( V_19 ) ;
error = F_112 ( V_5 , V_157 , V_171 ) ;
if ( error )
return error ;
error = F_207 ( V_19 , NULL , V_171 , V_157 , & V_177 , & V_285 ) ;
if ( error )
goto V_308;
F_211 ( V_19 , V_5 , V_177 ) ;
error = F_208 ( V_285 , V_177 ) ;
if ( error )
goto V_308;
return 0 ;
V_308:
F_115 ( V_5 , V_158 ) ;
return error ;
}
static int F_118 ( struct V_18 * V_19 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int V_171 , error ;
V_171 = F_62 ( V_19 ) ;
error = F_207 ( V_19 , NULL , V_171 , V_296 , & V_177 , & V_285 ) ;
if ( error )
goto V_97;
memcpy ( V_177 -> V_213 , V_19 -> V_24 , V_19 -> V_68 ) ;
V_177 -> V_306 = V_19 -> V_109 ;
error = F_208 ( V_285 , V_177 ) ;
V_97:
return error ;
}
static int F_214 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_148 , int V_41 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int V_171 , error ;
V_171 = V_5 -> V_7 ;
error = F_207 ( V_19 , V_5 , V_171 , V_148 , & V_177 , & V_285 ) ;
if ( error )
goto V_97;
F_211 ( V_19 , V_5 , V_177 ) ;
V_177 -> V_180 = V_41 ;
error = F_208 ( V_285 , V_177 ) ;
V_97:
return error ;
}
static int F_215 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_41 )
{
return F_214 ( V_19 , V_5 , V_150 , V_41 ) ;
}
static int F_216 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_41 )
{
return F_214 ( V_19 , V_5 , V_152 , V_41 ) ;
}
static int F_217 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_41 )
{
return F_214 ( V_19 , V_5 , V_154 , V_41 ) ;
}
static int F_218 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_41 )
{
return F_214 ( V_19 , V_5 , V_156 , V_41 ) ;
}
static int F_219 ( struct V_27 * V_28 , struct V_176 * V_312 ,
int V_250 , int V_41 )
{
struct V_18 * V_19 = & V_28 -> V_313 ;
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int error , V_111 = V_312 -> V_181 . V_182 ;
error = F_207 ( V_19 , NULL , V_111 , V_158 , & V_177 , & V_285 ) ;
if ( error )
goto V_97;
V_177 -> V_299 = V_312 -> V_299 ;
V_177 -> V_180 = V_41 ;
V_177 -> V_297 = V_250 ;
error = F_208 ( V_285 , V_177 ) ;
V_97:
return error ;
}
static void F_220 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
V_5 -> V_10 = V_177 -> V_301 ;
V_5 -> V_32 = V_177 -> V_302 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_177 -> V_184 & 0x0000FFFF ) ;
}
static void F_221 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
if ( V_177 -> V_184 == V_185 )
return;
V_5 -> V_32 = V_177 -> V_302 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_177 -> V_184 & 0x0000FFFF ) ;
}
static int F_141 ( struct V_176 * V_177 )
{
return ( V_177 -> V_181 . V_293 - sizeof( struct V_176 ) ) ;
}
static int F_222 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
int V_62 ;
if ( V_5 -> V_10 & V_206 ) {
if ( ! V_5 -> V_135 )
V_5 -> V_135 = F_138 ( V_28 ) ;
if ( ! V_5 -> V_135 )
return - V_60 ;
V_62 = F_141 ( V_177 ) ;
if ( V_62 > V_76 )
V_62 = V_76 ;
memcpy ( V_5 -> V_135 , V_177 -> V_213 , V_62 ) ;
}
return 0 ;
}
static void F_223 ( void * V_257 , int V_139 )
{
F_49 ( L_42 ) ;
}
static void F_224 ( void * V_257 )
{
F_49 ( L_43 ) ;
}
static int F_225 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
V_5 -> V_7 = V_177 -> V_181 . V_182 ;
V_5 -> V_272 = V_177 -> V_298 ;
V_5 -> V_9 = V_177 -> V_299 ;
V_5 -> V_14 = V_121 ;
V_5 -> V_13 = V_177 -> V_305 ;
V_5 -> V_247 = ( V_177 -> V_307 & V_50 ) ? & F_223 : NULL ;
V_5 -> V_269 = ( V_177 -> V_307 & V_47 ) ? & F_224 : NULL ;
if ( V_5 -> V_10 & V_206 ) {
V_5 -> V_135 = F_138 ( V_28 ) ;
if ( ! V_5 -> V_135 )
return - V_60 ;
}
return 0 ;
}
static int F_226 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
if ( V_5 -> V_12 != V_35 )
return - V_172 ;
if ( F_222 ( V_28 , V_5 , V_177 ) )
return - V_60 ;
V_5 -> V_13 = V_177 -> V_305 ;
V_5 -> V_207 = V_177 -> V_214 ;
return 0 ;
}
static int F_227 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
if ( F_222 ( V_28 , V_5 , V_177 ) )
return - V_60 ;
return 0 ;
}
static void F_228 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 = & V_28 -> V_314 ;
V_5 -> V_7 = V_177 -> V_181 . V_182 ;
V_5 -> V_9 = V_177 -> V_299 ;
}
static int F_229 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
int V_315 = V_177 -> V_181 . V_182 ;
int error = 0 ;
switch ( V_177 -> V_186 ) {
case V_151 :
case V_153 :
case V_155 :
if ( ! F_22 ( V_5 ) || V_5 -> V_7 != V_315 )
error = - V_103 ;
break;
case V_152 :
case V_154 :
case V_156 :
case V_217 :
case V_310 :
if ( ! F_21 ( V_5 ) || V_5 -> V_7 != V_315 )
error = - V_103 ;
break;
case V_150 :
if ( ! F_21 ( V_5 ) )
error = - V_103 ;
else if ( V_5 -> V_7 != - 1 && V_5 -> V_7 != V_315 )
error = - V_103 ;
break;
default:
error = - V_103 ;
}
if ( error )
F_84 ( V_5 -> V_118 -> V_67 ,
L_44 ,
V_177 -> V_186 , V_315 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_11 , V_5 -> V_7 ) ;
return error ;
}
static int F_230 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_100 ;
error = F_79 ( V_28 , & V_5 ) ;
if ( error )
goto V_308;
F_220 ( V_5 , V_177 ) ;
V_5 -> V_11 |= V_36 ;
error = F_225 ( V_28 , V_5 , V_177 ) ;
if ( error ) {
F_88 ( V_28 , V_5 ) ;
goto V_308;
}
V_100 = F_141 ( V_177 ) ;
error = F_59 ( V_28 , V_177 -> V_213 , V_100 , V_86 , & V_19 ) ;
if ( error ) {
F_88 ( V_28 , V_5 ) ;
goto V_308;
}
F_130 ( V_19 ) ;
F_77 ( V_19 , V_5 ) ;
error = F_184 ( V_19 , V_5 ) ;
F_215 ( V_19 , V_5 , error ) ;
F_185 ( V_19 , V_5 , error ) ;
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
if ( error == - V_253 )
error = 0 ;
if ( error )
F_91 ( V_5 ) ;
return 0 ;
V_308:
F_228 ( V_28 , V_177 ) ;
F_215 ( & V_28 -> V_313 , & V_28 -> V_314 , error ) ;
return error ;
}
static int F_231 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_316 = 1 ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
goto V_308;
if ( V_5 -> V_9 != V_177 -> V_299 ) {
F_84 ( V_28 , L_45
L_46 , V_5 -> V_8 , V_5 -> V_9 ,
( unsigned long long ) V_5 -> V_17 ,
V_177 -> V_181 . V_182 , V_177 -> V_299 ) ;
error = - V_134 ;
goto V_308;
}
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
F_220 ( V_5 , V_177 ) ;
error = F_226 ( V_28 , V_5 , V_177 ) ;
if ( error ) {
F_216 ( V_19 , V_5 , error ) ;
goto V_97;
}
V_316 = ! F_24 ( V_5 ) ;
error = F_186 ( V_19 , V_5 ) ;
if ( V_316 )
F_216 ( V_19 , V_5 , error ) ;
F_187 ( V_19 , V_5 , error ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
V_308:
F_228 ( V_28 , V_177 ) ;
F_216 ( & V_28 -> V_313 , & V_28 -> V_314 , error ) ;
return error ;
}
static int F_232 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
goto V_308;
if ( V_5 -> V_9 != V_177 -> V_299 ) {
F_84 ( V_28 , L_47 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_177 -> V_181 . V_182 , V_177 -> V_299 ) ;
error = - V_134 ;
goto V_308;
}
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
F_220 ( V_5 , V_177 ) ;
error = F_227 ( V_28 , V_5 , V_177 ) ;
if ( error ) {
F_217 ( V_19 , V_5 , error ) ;
goto V_97;
}
error = F_188 ( V_19 , V_5 ) ;
F_217 ( V_19 , V_5 , error ) ;
F_189 ( V_19 , V_5 , error ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
V_308:
F_228 ( V_28 , V_177 ) ;
F_217 ( & V_28 -> V_313 , & V_28 -> V_314 , error ) ;
return error ;
}
static int F_233 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
goto V_308;
F_220 ( V_5 , V_177 ) ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
error = V_197 ( V_19 , V_5 ) ;
F_218 ( V_19 , V_5 , error ) ;
F_190 ( V_19 , V_5 , error ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
V_308:
F_228 ( V_28 , V_177 ) ;
F_218 ( & V_28 -> V_313 , & V_28 -> V_314 , error ) ;
return error ;
}
static int F_234 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
F_221 ( V_5 , V_177 ) ;
if ( F_17 ( V_5 ) )
F_153 ( V_5 , V_177 ) ;
F_149 ( V_19 , V_5 , V_177 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
static int F_235 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
F_32 ( V_19 , V_5 , V_177 -> V_311 ) ;
V_5 -> V_215 = V_177 -> V_311 ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
static void F_236 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
int V_62 , error , V_250 , V_249 , V_317 , V_251 ;
V_317 = V_177 -> V_181 . V_182 ;
V_251 = F_63 () ;
V_62 = F_141 ( V_177 ) ;
V_249 = F_237 ( V_28 , V_177 -> V_306 ) ;
if ( V_249 != V_251 ) {
F_84 ( V_28 , L_48 ,
V_249 , V_317 ) ;
error = - V_103 ;
V_250 = - 1 ;
goto V_97;
}
error = F_173 ( V_28 , V_317 , V_177 -> V_213 , V_62 , & V_250 ) ;
if ( ! error && V_250 == V_251 ) {
F_230 ( V_28 , V_177 ) ;
return;
}
V_97:
F_219 ( V_28 , V_177 , V_250 , error ) ;
}
static void F_238 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
int V_62 , V_249 , V_317 ;
V_317 = V_177 -> V_181 . V_182 ;
V_62 = F_141 ( V_177 ) ;
V_249 = F_237 ( V_28 , V_177 -> V_306 ) ;
if ( V_249 != F_63 () ) {
F_84 ( V_28 , L_49 ,
V_249 , V_317 ) ;
return;
}
F_119 ( V_28 , V_317 , V_177 -> V_213 , V_62 ) ;
}
static void F_239 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
F_240 ( V_28 , V_177 -> V_297 , V_177 -> V_298 ) ;
}
static int F_241 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_148 , V_318 ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
V_148 = V_5 -> V_15 ;
error = F_115 ( V_5 , V_150 ) ;
if ( error ) {
F_84 ( V_28 , L_50 ,
V_5 -> V_8 , V_177 -> V_181 . V_182 , V_177 -> V_299 ,
V_177 -> V_180 ) ;
F_5 ( V_19 ) ;
goto V_97;
}
if ( V_148 == V_157 ) {
V_19 -> V_20 = V_177 -> V_181 . V_182 ;
V_5 -> V_7 = V_19 -> V_20 ;
}
V_318 = V_177 -> V_180 ;
switch ( V_318 ) {
case - V_64 :
F_28 ( V_19 , V_5 , - V_64 ) ;
F_177 ( V_19 , - V_64 ) ;
F_93 ( V_5 ) ;
break;
case - V_253 :
case 0 :
F_221 ( V_5 , V_177 ) ;
V_5 -> V_9 = V_177 -> V_299 ;
if ( F_17 ( V_5 ) )
F_153 ( V_5 , V_177 ) ;
if ( V_318 ) {
F_96 ( V_19 , V_5 , V_144 ) ;
F_127 ( V_5 ) ;
} else {
F_149 ( V_19 , V_5 , V_177 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
}
F_177 ( V_19 , V_318 ) ;
break;
case - V_85 :
case - V_87 :
F_40 ( V_28 , L_51 ,
V_5 -> V_8 , V_5 -> V_11 , V_19 -> V_20 , V_318 ) ;
V_19 -> V_20 = - 1 ;
V_5 -> V_7 = - 1 ;
if ( F_27 ( V_5 ) ) {
F_31 ( V_19 , V_5 ) ;
F_177 ( V_19 , V_318 ) ;
F_93 ( V_5 ) ;
} else
F_176 ( V_19 , V_5 ) ;
break;
default:
F_84 ( V_28 , L_52 ,
V_5 -> V_8 , V_318 ) ;
}
if ( F_25 ( V_5 ) && ( V_318 == 0 || V_318 == - V_253 ) ) {
F_40 ( V_28 , L_53 ,
V_5 -> V_8 , V_318 ) ;
V_5 -> V_11 &= ~ V_39 ;
V_5 -> V_11 &= ~ V_40 ;
F_195 ( V_19 , V_5 ) ;
} else if ( F_26 ( V_5 ) && ( V_318 == - V_253 ) ) {
F_40 ( V_28 , L_54 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_39 ;
V_5 -> V_11 &= ~ V_40 ;
F_196 ( V_19 , V_5 ) ;
} else {
V_5 -> V_11 &= ~ V_40 ;
V_5 -> V_11 &= ~ V_39 ;
}
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
static void F_213 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_176 * V_177 )
{
switch ( V_177 -> V_180 ) {
case - V_64 :
F_28 ( V_19 , V_5 , - V_64 ) ;
break;
case - V_46 :
F_221 ( V_5 , V_177 ) ;
F_146 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_46 ) ;
break;
case - V_253 :
F_221 ( V_5 , V_177 ) ;
if ( F_16 ( V_5 ) )
F_152 ( V_5 ) ;
F_99 ( V_19 , V_5 ) ;
F_96 ( V_19 , V_5 , V_146 ) ;
F_127 ( V_5 ) ;
break;
case 0 :
F_221 ( V_5 , V_177 ) ;
if ( F_16 ( V_5 ) )
F_152 ( V_5 ) ;
F_149 ( V_19 , V_5 , V_177 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
break;
default:
F_84 ( V_19 -> V_67 , L_55 ,
V_5 -> V_8 , V_177 -> V_181 . V_182 , V_177 -> V_299 ,
V_177 -> V_180 ) ;
F_4 ( V_19 ) ;
F_2 ( V_5 ) ;
}
}
static void F_242 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
struct V_18 * V_19 = V_5 -> V_118 ;
int error ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
error = F_116 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
F_213 ( V_19 , V_5 , V_177 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
}
static int F_243 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
return error ;
F_242 ( V_5 , V_177 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
static void F_244 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
struct V_18 * V_19 = V_5 -> V_118 ;
int error ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
error = F_116 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
switch ( V_177 -> V_180 ) {
case - V_48 :
F_221 ( V_5 , V_177 ) ;
F_144 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_48 ) ;
break;
case - V_134 :
break;
default:
F_84 ( V_19 -> V_67 , L_56 ,
V_5 -> V_8 , V_177 -> V_180 ) ;
}
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
}
static int F_245 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
return error ;
F_244 ( V_5 , V_177 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
static void F_246 ( struct V_4 * V_5 , struct V_176 * V_177 )
{
struct V_18 * V_19 = V_5 -> V_118 ;
int error ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_229 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
error = F_116 ( V_5 , V_177 ) ;
if ( error )
goto V_97;
switch ( V_177 -> V_180 ) {
case - V_42 :
F_221 ( V_5 , V_177 ) ;
F_146 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_42 ) ;
break;
case 0 :
break;
default:
F_84 ( V_19 -> V_67 , L_57 ,
V_5 -> V_8 , V_177 -> V_180 ) ;
}
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
}
static int F_247 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
int error ;
error = F_85 ( V_28 , V_177 -> V_300 , & V_5 ) ;
if ( error )
return error ;
F_246 ( V_5 , V_177 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
static void F_248 ( struct V_27 * V_28 , struct V_176 * V_177 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_250 ;
error = F_85 ( V_28 , V_177 -> V_299 , & V_5 ) ;
if ( error ) {
F_84 ( V_28 , L_58 , V_177 -> V_299 ) ;
return;
}
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_115 ( V_5 , V_158 ) ;
if ( error )
goto V_97;
V_250 = V_177 -> V_297 ;
if ( V_250 == F_63 () ) {
V_19 -> V_20 = 0 ;
V_250 = 0 ;
V_19 -> V_22 = 0 ;
} else {
V_19 -> V_20 = V_250 ;
}
if ( F_27 ( V_5 ) ) {
F_40 ( V_28 , L_59 ,
V_5 -> V_8 , V_5 -> V_11 ) ;
F_31 ( V_19 , V_5 ) ;
F_93 ( V_5 ) ;
goto V_319;
}
F_176 ( V_19 , V_5 ) ;
V_319:
if ( ! V_250 )
F_175 ( V_19 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
}
static void F_249 ( struct V_27 * V_28 , struct V_176 * V_177 ,
T_1 V_320 )
{
int error = 0 , V_321 = 0 ;
if ( ! F_250 ( V_28 , V_177 -> V_181 . V_182 ) ) {
F_40 ( V_28 , L_60 ,
V_177 -> V_186 , V_177 -> V_181 . V_182 , V_177 -> V_299 ,
V_177 -> V_300 , V_177 -> V_180 ) ;
return;
}
switch ( V_177 -> V_186 ) {
case V_149 :
error = F_230 ( V_28 , V_177 ) ;
break;
case V_151 :
error = F_231 ( V_28 , V_177 ) ;
break;
case V_153 :
error = F_232 ( V_28 , V_177 ) ;
break;
case V_155 :
V_321 = 1 ;
error = F_233 ( V_28 , V_177 ) ;
break;
case V_150 :
error = F_241 ( V_28 , V_177 ) ;
break;
case V_152 :
error = F_243 ( V_28 , V_177 ) ;
break;
case V_154 :
error = F_245 ( V_28 , V_177 ) ;
break;
case V_156 :
error = F_247 ( V_28 , V_177 ) ;
break;
case V_217 :
V_321 = 1 ;
error = F_234 ( V_28 , V_177 ) ;
break;
case V_310 :
V_321 = 1 ;
error = F_235 ( V_28 , V_177 ) ;
break;
case V_157 :
F_236 ( V_28 , V_177 ) ;
break;
case V_296 :
F_238 ( V_28 , V_177 ) ;
break;
case V_158 :
F_248 ( V_28 , V_177 ) ;
break;
case V_322 :
F_239 ( V_28 , V_177 ) ;
break;
default:
F_84 ( V_28 , L_61 , V_177 -> V_186 ) ;
}
if ( error == - V_134 && V_321 ) {
F_40 ( V_28 , L_62 ,
V_177 -> V_186 , V_177 -> V_300 , V_177 -> V_181 . V_182 ,
V_177 -> V_299 , V_320 ) ;
} else if ( error == - V_134 ) {
F_84 ( V_28 , L_62 ,
V_177 -> V_186 , V_177 -> V_300 , V_177 -> V_181 . V_182 ,
V_177 -> V_299 , V_320 ) ;
if ( V_177 -> V_186 == V_151 )
F_64 ( V_28 , V_177 -> V_306 ) ;
}
if ( error == - V_103 ) {
F_84 ( V_28 , L_63
L_64 ,
V_177 -> V_186 , V_177 -> V_181 . V_182 ,
V_177 -> V_299 , V_177 -> V_300 , V_320 ) ;
}
}
static void F_251 ( struct V_27 * V_28 , struct V_176 * V_177 ,
int V_111 )
{
if ( F_125 ( V_28 ) ) {
F_252 ( V_28 , V_111 , V_177 ) ;
} else {
F_253 ( V_28 ) ;
F_249 ( V_28 , V_177 , 0 ) ;
}
}
void F_254 ( struct V_27 * V_28 , struct V_176 * V_177 ,
T_1 V_320 )
{
F_249 ( V_28 , V_177 , V_320 ) ;
}
void F_255 ( union V_323 * V_324 , int V_111 )
{
struct V_325 * V_326 = & V_324 -> V_327 ;
struct V_27 * V_28 ;
int type = 0 ;
switch ( V_326 -> V_294 ) {
case V_295 :
F_256 ( & V_324 -> V_328 ) ;
type = V_324 -> V_328 . V_186 ;
break;
case V_329 :
F_257 ( & V_324 -> V_330 ) ;
type = V_324 -> V_330 . V_331 ;
break;
default:
F_49 ( L_65 , V_326 -> V_294 , V_111 ) ;
return;
}
if ( V_326 -> V_182 != V_111 ) {
F_49 ( L_66 ,
V_326 -> V_182 , V_111 , V_326 -> V_291 ) ;
return;
}
V_28 = F_258 ( V_326 -> V_291 ) ;
if ( ! V_28 ) {
if ( V_56 . V_332 ) {
F_259 ( V_333 L_67
L_68 ,
V_326 -> V_291 , V_111 , V_326 -> V_294 , type ) ;
}
if ( V_326 -> V_294 == V_329 && type == V_334 )
F_260 ( V_111 , & V_324 -> V_330 ) ;
return;
}
F_9 ( & V_28 -> V_335 ) ;
if ( V_326 -> V_294 == V_295 )
F_251 ( V_28 , & V_324 -> V_328 , V_111 ) ;
else
F_261 ( V_28 , & V_324 -> V_330 , V_111 ) ;
F_11 ( & V_28 -> V_335 ) ;
F_203 ( V_28 ) ;
}
static void F_262 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_176 * V_336 )
{
if ( F_23 ( V_5 ) ) {
F_92 ( V_5 ) ;
memset ( V_336 , 0 , sizeof( struct V_176 ) ) ;
V_336 -> V_184 = V_185 ;
V_336 -> V_186 = V_152 ;
V_336 -> V_180 = - V_253 ;
V_336 -> V_181 . V_182 = V_5 -> V_7 ;
F_242 ( V_5 , V_336 ) ;
V_5 -> V_14 = V_121 ;
F_57 ( V_5 -> V_118 , V_337 ) ;
F_93 ( V_5 ) ;
} else if ( V_5 -> V_13 >= V_5 -> V_14 ) {
V_5 -> V_11 |= V_183 ;
}
}
static int F_263 ( struct V_27 * V_28 , struct V_4 * V_5 ,
int V_249 )
{
if ( F_55 ( V_28 ) )
return 1 ;
if ( F_264 ( V_28 , V_5 -> V_16 ) )
return 1 ;
return 0 ;
}
void F_265 ( struct V_27 * V_28 )
{
struct V_4 * V_5 , * V_252 ;
struct V_176 * V_336 ;
int V_338 , V_339 , V_340 ;
int V_249 ;
V_336 = F_266 ( sizeof( struct V_176 ) , V_170 ) ;
if ( ! V_336 ) {
F_84 ( V_28 , L_69 ) ;
return;
}
F_105 ( & V_28 -> V_167 ) ;
F_162 (lkb, safe, &ls->ls_waiters, lkb_wait_reply) {
V_249 = F_62 ( V_5 -> V_118 ) ;
if ( V_5 -> V_15 != V_153 ) {
F_40 ( V_28 , L_70
L_71 ,
V_5 -> V_8 ,
V_5 -> V_9 ,
V_5 -> V_15 ,
V_5 -> V_118 -> V_20 ,
V_5 -> V_7 ,
V_5 -> V_16 ,
V_249 ) ;
}
if ( V_5 -> V_15 == V_157 ) {
V_5 -> V_11 |= V_183 ;
continue;
}
if ( ! F_263 ( V_28 , V_5 , V_249 ) )
continue;
V_338 = V_5 -> V_15 ;
V_339 = - V_48 ;
V_340 = - V_42 ;
if ( ! V_338 ) {
if ( F_26 ( V_5 ) ) {
V_338 = V_155 ;
if ( V_5 -> V_14 == V_121 )
V_340 = 0 ;
}
if ( F_25 ( V_5 ) ) {
V_338 = V_153 ;
if ( V_5 -> V_14 == V_121 )
V_339 = - V_134 ;
}
F_40 ( V_28 , L_72 ,
V_5 -> V_8 , V_5 -> V_11 , V_338 ,
V_340 , V_339 ) ;
}
switch ( V_338 ) {
case V_149 :
V_5 -> V_11 |= V_183 ;
break;
case V_151 :
F_262 ( V_28 , V_5 , V_336 ) ;
break;
case V_153 :
F_92 ( V_5 ) ;
memset ( V_336 , 0 , sizeof( struct V_176 ) ) ;
V_336 -> V_184 = V_185 ;
V_336 -> V_186 = V_154 ;
V_336 -> V_180 = V_339 ;
V_336 -> V_181 . V_182 = V_5 -> V_7 ;
F_244 ( V_5 , V_336 ) ;
F_91 ( V_5 ) ;
break;
case V_155 :
F_92 ( V_5 ) ;
memset ( V_336 , 0 , sizeof( struct V_176 ) ) ;
V_336 -> V_184 = V_185 ;
V_336 -> V_186 = V_156 ;
V_336 -> V_180 = V_340 ;
V_336 -> V_181 . V_182 = V_5 -> V_7 ;
F_246 ( V_5 , V_336 ) ;
F_91 ( V_5 ) ;
break;
default:
F_84 ( V_28 , L_73 ,
V_5 -> V_15 , V_338 ) ;
}
F_174 () ;
}
F_110 ( & V_28 -> V_167 ) ;
F_111 ( V_336 ) ;
}
static struct V_4 * F_267 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
int V_84 = 0 ;
F_105 ( & V_28 -> V_167 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( V_5 -> V_11 & V_183 ) {
F_92 ( V_5 ) ;
V_84 = 1 ;
break;
}
}
F_110 ( & V_28 -> V_167 ) ;
if ( ! V_84 )
V_5 = NULL ;
return V_5 ;
}
int F_268 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error = 0 , V_148 , V_231 , V_341 , V_342 ;
while ( 1 ) {
if ( F_125 ( V_28 ) ) {
F_40 ( V_28 , L_74 ) ;
error = - V_343 ;
break;
}
V_5 = F_267 ( V_28 ) ;
if ( ! V_5 )
break;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
V_148 = V_5 -> V_15 ;
V_341 = F_26 ( V_5 ) ;
V_342 = F_25 ( V_5 ) ;
V_231 = 0 ;
F_40 ( V_28 , L_70
L_75
L_76 , V_5 -> V_8 , V_5 -> V_9 , V_148 ,
V_19 -> V_20 , V_5 -> V_7 , V_5 -> V_16 ,
F_62 ( V_19 ) , V_341 , V_342 ) ;
V_5 -> V_11 &= ~ V_183 ;
V_5 -> V_11 &= ~ V_39 ;
V_5 -> V_11 &= ~ V_40 ;
V_5 -> V_15 = 0 ;
V_5 -> V_173 = 0 ;
F_105 ( & V_28 -> V_167 ) ;
F_114 ( & V_5 -> V_174 ) ;
F_110 ( & V_28 -> V_167 ) ;
F_93 ( V_5 ) ;
if ( V_341 || V_342 ) {
switch ( V_148 ) {
case V_157 :
case V_149 :
F_28 ( V_19 , V_5 , V_342 ? - V_48 :
- V_42 ) ;
F_93 ( V_5 ) ;
break;
case V_151 :
if ( V_341 ) {
F_28 ( V_19 , V_5 , - V_42 ) ;
} else {
V_5 -> V_10 |= V_267 ;
F_194 ( V_19 , V_5 ) ;
}
break;
default:
V_231 = 1 ;
}
} else {
switch ( V_148 ) {
case V_157 :
case V_149 :
F_176 ( V_19 , V_5 ) ;
if ( F_122 ( V_19 ) )
F_177 ( V_19 , 0 ) ;
break;
case V_151 :
F_192 ( V_19 , V_5 ) ;
break;
default:
V_231 = 1 ;
}
}
if ( V_231 ) {
F_84 ( V_28 , L_77
L_78 ,
V_5 -> V_8 , V_148 , V_19 -> V_20 ,
F_62 ( V_19 ) , V_341 , V_342 ) ;
}
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
}
return error ;
}
static void F_269 ( struct V_27 * V_28 , struct V_18 * V_19 ,
struct V_136 * V_344 )
{
struct V_4 * V_5 , * V_252 ;
F_162 (lkb, safe, list, lkb_statequeue) {
if ( ! F_22 ( V_5 ) )
continue;
if ( V_5 -> V_17 == V_28 -> V_345 )
continue;
F_99 ( V_19 , V_5 ) ;
if ( ! F_91 ( V_5 ) )
F_84 ( V_28 , L_79 ) ;
}
}
void F_270 ( struct V_18 * V_19 )
{
struct V_27 * V_28 = V_19 -> V_67 ;
F_269 ( V_28 , V_19 , & V_19 -> V_71 ) ;
F_269 ( V_28 , V_19 , & V_19 -> V_72 ) ;
F_269 ( V_28 , V_19 , & V_19 -> V_73 ) ;
}
static void F_271 ( struct V_27 * V_28 , struct V_18 * V_19 ,
struct V_136 * V_344 ,
int V_346 , unsigned int * V_53 )
{
struct V_4 * V_5 , * V_252 ;
F_162 (lkb, safe, list, lkb_statequeue) {
if ( ! F_22 ( V_5 ) )
continue;
if ( ( V_5 -> V_7 == V_346 ) ||
F_264 ( V_28 , V_5 -> V_7 ) ) {
F_99 ( V_19 , V_5 ) ;
if ( ! F_91 ( V_5 ) )
F_84 ( V_28 , L_80 ) ;
F_57 ( V_19 , V_347 ) ;
( * V_53 ) ++ ;
}
}
}
void F_272 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
struct V_348 * V_349 ;
int V_350 = 0 ;
int V_346 = 0 ;
unsigned int V_351 = 0 ;
F_7 (memb, &ls->ls_nodes_gone, list) {
V_350 ++ ;
V_346 = V_349 -> V_111 ;
}
if ( ! V_350 )
return;
F_273 ( & V_28 -> V_352 ) ;
F_7 (r, &ls->ls_root_list, res_root_list) {
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
if ( F_122 ( V_19 ) ) {
F_271 ( V_28 , V_19 , & V_19 -> V_71 ,
V_346 , & V_351 ) ;
F_271 ( V_28 , V_19 , & V_19 -> V_72 ,
V_346 , & V_351 ) ;
F_271 ( V_28 , V_19 , & V_19 -> V_73 ,
V_346 , & V_351 ) ;
}
F_133 ( V_19 ) ;
F_75 ( V_19 ) ;
F_126 () ;
}
F_274 ( & V_28 -> V_352 ) ;
if ( V_351 )
F_40 ( V_28 , L_81 ,
V_351 , V_350 ) ;
}
static struct V_18 * F_275 ( struct V_27 * V_28 , int V_102 )
{
struct V_66 * V_112 ;
struct V_18 * V_19 ;
F_35 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
for ( V_112 = F_65 ( & V_28 -> V_94 [ V_102 ] . V_95 ) ; V_112 ; V_112 = F_66 ( V_112 ) ) {
V_19 = F_47 ( V_112 , struct V_18 , V_65 ) ;
if ( ! F_58 ( V_19 , V_347 ) )
continue;
F_56 ( V_19 , V_347 ) ;
if ( ! F_122 ( V_19 ) )
continue;
F_67 ( V_19 ) ;
F_36 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
return V_19 ;
}
F_36 ( & V_28 -> V_94 [ V_102 ] . V_107 ) ;
return NULL ;
}
void F_276 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
int V_102 = 0 ;
unsigned int V_53 = 0 ;
unsigned int V_353 = 0 ;
unsigned int V_351 = 0 ;
while ( 1 ) {
V_19 = F_275 ( V_28 , V_102 ) ;
if ( ! V_19 ) {
if ( V_102 == V_28 -> V_105 - 1 )
break;
V_102 ++ ;
continue;
}
V_353 ++ ;
V_53 = 0 ;
F_130 ( V_19 ) ;
F_166 ( V_19 , & V_53 ) ;
V_351 += V_53 ;
F_177 ( V_19 , 0 ) ;
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_126 () ;
}
if ( V_351 )
F_40 ( V_28 , L_82 ,
V_351 , V_353 ) ;
}
static struct V_4 * F_277 ( struct V_136 * V_138 , int V_111 ,
T_1 V_354 )
{
struct V_4 * V_5 ;
F_7 (lkb, head, lkb_statequeue) {
if ( V_5 -> V_7 == V_111 && V_5 -> V_9 == V_354 )
return V_5 ;
}
return NULL ;
}
static struct V_4 * F_278 ( struct V_18 * V_19 , int V_111 ,
T_1 V_354 )
{
struct V_4 * V_5 ;
V_5 = F_277 ( & V_19 -> V_71 , V_111 , V_354 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_277 ( & V_19 -> V_72 , V_111 , V_354 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_277 ( & V_19 -> V_73 , V_111 , V_354 ) ;
if ( V_5 )
return V_5 ;
return NULL ;
}
static int F_279 ( struct V_27 * V_28 , struct V_4 * V_5 ,
struct V_18 * V_19 , struct V_355 * V_81 )
{
struct V_356 * V_357 = (struct V_356 * ) V_81 -> V_358 ;
V_5 -> V_7 = V_81 -> V_359 . V_182 ;
V_5 -> V_272 = F_280 ( V_357 -> V_360 ) ;
V_5 -> V_9 = F_280 ( V_357 -> V_361 ) ;
V_5 -> V_10 = F_280 ( V_357 -> V_362 ) ;
V_5 -> V_11 = F_280 ( V_357 -> V_363 ) & 0x0000FFFF ;
V_5 -> V_11 |= V_36 ;
V_5 -> V_207 = F_280 ( V_357 -> V_364 ) ;
V_5 -> V_13 = V_357 -> V_365 ;
V_5 -> V_14 = V_357 -> V_366 ;
V_5 -> V_247 = ( V_357 -> V_367 & V_50 ) ? & F_223 : NULL ;
V_5 -> V_269 = ( V_357 -> V_367 & V_47 ) ? & F_224 : NULL ;
if ( V_5 -> V_10 & V_206 ) {
int V_368 = V_81 -> V_359 . V_293 - sizeof( struct V_355 ) -
sizeof( struct V_356 ) ;
if ( V_368 > V_28 -> V_204 )
return - V_103 ;
V_5 -> V_135 = F_138 ( V_28 ) ;
if ( ! V_5 -> V_135 )
return - V_60 ;
memcpy ( V_5 -> V_135 , V_357 -> V_369 , V_368 ) ;
}
if ( V_357 -> V_370 == F_281 ( V_151 ) &&
F_23 ( V_5 ) ) {
V_357 -> V_371 = V_146 ;
V_5 -> V_14 = V_121 ;
F_57 ( V_19 , V_337 ) ;
}
return 0 ;
}
int F_282 ( struct V_27 * V_28 , struct V_355 * V_81 )
{
struct V_356 * V_357 = (struct V_356 * ) V_81 -> V_358 ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
T_1 V_354 = 0 ;
int error ;
if ( V_357 -> V_372 ) {
error = - V_373 ;
goto V_97;
}
V_354 = F_280 ( V_357 -> V_361 ) ;
error = F_59 ( V_28 , V_357 -> V_374 , F_283 ( V_357 -> V_375 ) , 0 , & V_19 ) ;
if ( error )
goto V_97;
if ( F_55 ( V_28 ) && ( F_62 ( V_19 ) != F_63 () ) ) {
F_84 ( V_28 , L_83 ,
V_81 -> V_359 . V_182 , V_354 ) ;
error = - V_85 ;
F_72 ( V_19 ) ;
goto V_97;
}
F_130 ( V_19 ) ;
V_5 = F_278 ( V_19 , V_81 -> V_359 . V_182 , V_354 ) ;
if ( V_5 ) {
error = - V_92 ;
goto V_376;
}
error = F_79 ( V_28 , & V_5 ) ;
if ( error )
goto V_108;
error = F_279 ( V_28 , V_5 , V_19 , V_81 ) ;
if ( error ) {
F_88 ( V_28 , V_5 ) ;
goto V_108;
}
F_77 ( V_19 , V_5 ) ;
F_96 ( V_19 , V_5 , V_357 -> V_371 ) ;
error = 0 ;
V_28 -> V_377 ++ ;
if ( ! F_6 ( & V_19 -> V_73 ) || ! F_6 ( & V_19 -> V_72 ) )
F_57 ( V_19 , V_347 ) ;
V_376:
V_357 -> V_378 = F_284 ( V_5 -> V_8 ) ;
V_5 -> V_17 = V_28 -> V_345 ;
V_108:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
V_97:
if ( error && error != - V_92 )
F_40 ( V_28 , L_84 ,
V_81 -> V_359 . V_182 , V_354 , error ) ;
V_357 -> V_379 = F_284 ( error ) ;
return error ;
}
int F_285 ( struct V_27 * V_28 , struct V_355 * V_81 )
{
struct V_356 * V_357 = (struct V_356 * ) V_81 -> V_358 ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
T_1 V_133 , V_354 ;
int error , V_318 ;
V_133 = F_280 ( V_357 -> V_361 ) ;
V_354 = F_280 ( V_357 -> V_378 ) ;
V_318 = F_280 ( V_357 -> V_379 ) ;
error = F_85 ( V_28 , V_133 , & V_5 ) ;
if ( error ) {
F_84 ( V_28 , L_85 ,
V_133 , V_81 -> V_359 . V_182 , V_354 , V_318 ) ;
return error ;
}
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
if ( ! F_21 ( V_5 ) ) {
F_84 ( V_28 , L_86 ,
V_133 , V_81 -> V_359 . V_182 , V_354 , V_318 ) ;
F_5 ( V_19 ) ;
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return - V_103 ;
}
switch ( V_318 ) {
case - V_85 :
F_40 ( V_28 , L_87 ,
V_133 , V_81 -> V_359 . V_182 , V_354 , V_318 ) ;
F_286 ( V_19 , V_5 ) ;
goto V_97;
case - V_92 :
case 0 :
V_5 -> V_9 = V_354 ;
break;
default:
F_84 ( V_28 , L_88 ,
V_133 , V_81 -> V_359 . V_182 , V_354 , V_318 ) ;
}
F_287 ( V_19 ) ;
V_97:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
F_91 ( V_5 ) ;
return 0 ;
}
int F_288 ( struct V_27 * V_28 , struct V_380 * V_381 ,
int V_139 , T_1 V_79 , void * V_61 , unsigned int V_100 ,
unsigned long V_256 )
{
struct V_4 * V_5 ;
struct V_258 args ;
int error ;
F_8 ( V_28 ) ;
error = F_79 ( V_28 , & V_5 ) ;
if ( error ) {
F_111 ( V_381 ) ;
goto V_97;
}
if ( V_79 & V_206 ) {
V_381 -> V_255 . V_261 = F_109 ( V_382 , V_131 ) ;
if ( ! V_381 -> V_255 . V_261 ) {
F_111 ( V_381 ) ;
F_88 ( V_28 , V_5 ) ;
error = - V_60 ;
goto V_97;
}
}
error = F_178 ( V_139 , & V_381 -> V_255 , V_79 , V_100 , V_256 ,
F_224 , V_381 , F_223 , & args ) ;
V_5 -> V_11 |= V_383 ;
if ( error ) {
F_88 ( V_28 , V_5 ) ;
goto V_97;
}
error = F_197 ( V_28 , V_5 , V_61 , V_100 , & args ) ;
switch ( error ) {
case 0 :
break;
case - V_253 :
error = 0 ;
break;
case - V_64 :
error = 0 ;
default:
F_88 ( V_28 , V_5 ) ;
goto V_97;
}
F_35 ( & V_381 -> V_384 -> V_385 ) ;
F_92 ( V_5 ) ;
F_98 ( & V_5 -> V_123 , & V_381 -> V_384 -> V_386 ) ;
F_36 ( & V_381 -> V_384 -> V_385 ) ;
V_97:
F_10 ( V_28 ) ;
return error ;
}
int F_289 ( struct V_27 * V_28 , struct V_380 * V_387 ,
int V_139 , T_1 V_79 , T_1 V_133 , char * V_388 ,
unsigned long V_256 )
{
struct V_4 * V_5 ;
struct V_258 args ;
struct V_380 * V_381 ;
int error ;
F_8 ( V_28 ) ;
error = F_85 ( V_28 , V_133 , & V_5 ) ;
if ( error )
goto V_97;
V_381 = V_5 -> V_389 ;
if ( V_79 & V_206 && ! V_381 -> V_255 . V_261 ) {
V_381 -> V_255 . V_261 = F_109 ( V_382 , V_131 ) ;
if ( ! V_381 -> V_255 . V_261 ) {
error = - V_60 ;
goto V_280;
}
}
if ( V_388 && V_381 -> V_255 . V_261 )
memcpy ( V_381 -> V_255 . V_261 , V_388 , V_382 ) ;
V_381 -> V_390 = V_387 -> V_390 ;
V_381 -> V_391 = V_387 -> V_391 ;
V_381 -> V_392 = V_387 -> V_392 ;
V_381 -> V_393 = V_387 -> V_393 ;
V_381 -> V_394 = V_387 -> V_394 ;
V_381 -> V_395 = V_387 -> V_395 ;
error = F_178 ( V_139 , & V_381 -> V_255 , V_79 , 0 , V_256 ,
F_224 , V_381 , F_223 , & args ) ;
if ( error )
goto V_280;
error = F_198 ( V_28 , V_5 , & args ) ;
if ( error == - V_253 || error == - V_64 || error == - V_46 )
error = 0 ;
V_280:
F_91 ( V_5 ) ;
V_97:
F_10 ( V_28 ) ;
F_111 ( V_387 ) ;
return error ;
}
int F_290 ( struct V_27 * V_28 , struct V_380 * V_387 ,
T_1 V_79 , T_1 V_133 , char * V_388 )
{
struct V_4 * V_5 ;
struct V_258 args ;
struct V_380 * V_381 ;
int error ;
F_8 ( V_28 ) ;
error = F_85 ( V_28 , V_133 , & V_5 ) ;
if ( error )
goto V_97;
V_381 = V_5 -> V_389 ;
if ( V_388 && V_381 -> V_255 . V_261 )
memcpy ( V_381 -> V_255 . V_261 , V_388 , V_382 ) ;
if ( V_387 -> V_391 )
V_381 -> V_391 = V_387 -> V_391 ;
V_381 -> V_395 = V_387 -> V_395 ;
error = F_181 ( V_79 , V_381 , & args ) ;
if ( error )
goto V_280;
error = F_199 ( V_28 , V_5 , & args ) ;
if ( error == - V_48 )
error = 0 ;
if ( error == - V_172 && ( V_79 & V_267 ) )
error = 0 ;
if ( error )
goto V_280;
F_35 ( & V_381 -> V_384 -> V_385 ) ;
if ( ! F_6 ( & V_5 -> V_123 ) )
F_291 ( & V_5 -> V_123 , & V_381 -> V_384 -> V_396 ) ;
F_36 ( & V_381 -> V_384 -> V_385 ) ;
V_280:
F_91 ( V_5 ) ;
V_97:
F_10 ( V_28 ) ;
F_111 ( V_387 ) ;
return error ;
}
int F_292 ( struct V_27 * V_28 , struct V_380 * V_387 ,
T_1 V_79 , T_1 V_133 )
{
struct V_4 * V_5 ;
struct V_258 args ;
struct V_380 * V_381 ;
int error ;
F_8 ( V_28 ) ;
error = F_85 ( V_28 , V_133 , & V_5 ) ;
if ( error )
goto V_97;
V_381 = V_5 -> V_389 ;
if ( V_387 -> V_391 )
V_381 -> V_391 = V_387 -> V_391 ;
V_381 -> V_395 = V_387 -> V_395 ;
error = F_181 ( V_79 , V_381 , & args ) ;
if ( error )
goto V_280;
error = F_200 ( V_28 , V_5 , & args ) ;
if ( error == - V_42 )
error = 0 ;
if ( error == - V_172 )
error = 0 ;
V_280:
F_91 ( V_5 ) ;
V_97:
F_10 ( V_28 ) ;
F_111 ( V_387 ) ;
return error ;
}
int F_293 ( struct V_27 * V_28 , T_1 V_79 , T_1 V_133 )
{
struct V_4 * V_5 ;
struct V_258 args ;
struct V_380 * V_381 ;
struct V_18 * V_19 ;
int error ;
F_8 ( V_28 ) ;
error = F_85 ( V_28 , V_133 , & V_5 ) ;
if ( error )
goto V_97;
V_381 = V_5 -> V_389 ;
error = F_181 ( V_79 , V_381 , & args ) ;
if ( error )
goto V_280;
V_19 = V_5 -> V_118 ;
F_67 ( V_19 ) ;
F_130 ( V_19 ) ;
error = F_183 ( V_5 , & args ) ;
if ( error )
goto V_397;
V_5 -> V_11 |= V_45 ;
error = F_132 ( V_19 , V_5 ) ;
V_397:
F_133 ( V_19 ) ;
F_72 ( V_19 ) ;
if ( error == - V_42 )
error = 0 ;
if ( error == - V_172 )
error = 0 ;
V_280:
F_91 ( V_5 ) ;
V_97:
F_10 ( V_28 ) ;
return error ;
}
static int F_294 ( struct V_27 * V_28 , struct V_4 * V_5 )
{
struct V_258 args ;
int error ;
F_92 ( V_5 ) ;
F_105 ( & V_28 -> V_398 ) ;
F_98 ( & V_5 -> V_123 , & V_28 -> V_399 ) ;
F_110 ( & V_28 -> V_398 ) ;
F_181 ( 0 , V_5 -> V_389 , & args ) ;
error = F_200 ( V_28 , V_5 , & args ) ;
if ( error == - V_42 )
error = 0 ;
return error ;
}
static int F_295 ( struct V_27 * V_28 , struct V_4 * V_5 )
{
struct V_258 args ;
int error ;
F_181 ( V_267 , V_5 -> V_389 , & args ) ;
error = F_199 ( V_28 , V_5 , & args ) ;
if ( error == - V_48 )
error = 0 ;
return error ;
}
static struct V_4 * F_296 ( struct V_27 * V_28 ,
struct V_400 * V_384 )
{
struct V_4 * V_5 = NULL ;
F_105 ( & V_28 -> V_401 ) ;
if ( F_6 ( & V_384 -> V_386 ) )
goto V_97;
V_5 = F_155 ( V_384 -> V_386 . V_221 , struct V_4 , V_123 ) ;
F_114 ( & V_5 -> V_123 ) ;
if ( V_5 -> V_10 & V_402 )
V_5 -> V_11 |= V_403 ;
else
V_5 -> V_11 |= V_404 ;
V_97:
F_110 ( & V_28 -> V_401 ) ;
return V_5 ;
}
void F_297 ( struct V_27 * V_28 , struct V_400 * V_384 )
{
struct V_4 * V_5 , * V_252 ;
F_8 ( V_28 ) ;
while ( 1 ) {
V_5 = F_296 ( V_28 , V_384 ) ;
if ( ! V_5 )
break;
F_29 ( V_5 ) ;
if ( V_5 -> V_10 & V_402 )
F_294 ( V_28 , V_5 ) ;
else
F_295 ( V_28 , V_5 ) ;
F_91 ( V_5 ) ;
}
F_105 ( & V_28 -> V_401 ) ;
F_162 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_114 ( & V_5 -> V_123 ) ;
V_5 -> V_11 |= V_404 ;
F_91 ( V_5 ) ;
}
F_162 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_405 , 0 ,
sizeof( struct V_406 ) * V_407 ) ;
F_114 ( & V_5 -> V_126 ) ;
F_91 ( V_5 ) ;
}
F_110 ( & V_28 -> V_401 ) ;
F_10 ( V_28 ) ;
}
static void F_298 ( struct V_27 * V_28 , struct V_400 * V_384 )
{
struct V_4 * V_5 , * V_252 ;
while ( 1 ) {
V_5 = NULL ;
F_35 ( & V_384 -> V_385 ) ;
if ( ! F_6 ( & V_384 -> V_386 ) ) {
V_5 = F_155 ( V_384 -> V_386 . V_221 , struct V_4 ,
V_123 ) ;
F_114 ( & V_5 -> V_123 ) ;
}
F_36 ( & V_384 -> V_385 ) ;
if ( ! V_5 )
break;
V_5 -> V_11 |= V_404 ;
F_295 ( V_28 , V_5 ) ;
F_91 ( V_5 ) ;
}
F_35 ( & V_384 -> V_385 ) ;
F_162 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_114 ( & V_5 -> V_123 ) ;
V_5 -> V_11 |= V_404 ;
F_91 ( V_5 ) ;
}
F_36 ( & V_384 -> V_385 ) ;
F_35 ( & V_384 -> V_408 ) ;
F_162 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_405 , 0 ,
sizeof( struct V_406 ) * V_407 ) ;
F_114 ( & V_5 -> V_126 ) ;
F_91 ( V_5 ) ;
}
F_36 ( & V_384 -> V_408 ) ;
}
static void F_240 ( struct V_27 * V_28 , int V_111 , int V_274 )
{
struct V_4 * V_5 , * V_252 ;
F_105 ( & V_28 -> V_398 ) ;
F_162 (lkb, safe, &ls->ls_orphans, lkb_ownqueue) {
if ( V_274 && V_5 -> V_272 != V_274 )
continue;
F_295 ( V_28 , V_5 ) ;
F_114 ( & V_5 -> V_123 ) ;
F_91 ( V_5 ) ;
}
F_110 ( & V_28 -> V_398 ) ;
}
static int F_299 ( struct V_27 * V_28 , int V_111 , int V_274 )
{
struct V_176 * V_177 ;
struct V_283 * V_285 ;
int error ;
error = F_205 ( V_28 , sizeof( struct V_176 ) , V_111 ,
V_322 , & V_177 , & V_285 ) ;
if ( error )
return error ;
V_177 -> V_297 = V_111 ;
V_177 -> V_298 = V_274 ;
return F_208 ( V_285 , V_177 ) ;
}
int F_300 ( struct V_27 * V_28 , struct V_400 * V_384 ,
int V_111 , int V_274 )
{
int error = 0 ;
if ( V_111 != F_63 () ) {
error = F_299 ( V_28 , V_111 , V_274 ) ;
} else {
F_8 ( V_28 ) ;
if ( V_274 == V_273 -> V_274 )
F_298 ( V_28 , V_384 ) ;
else
F_240 ( V_28 , V_111 , V_274 ) ;
F_10 ( V_28 ) ;
}
return error ;
}
