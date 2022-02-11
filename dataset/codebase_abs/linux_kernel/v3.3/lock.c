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
V_5 -> V_14 , V_5 -> V_15 ) ;
}
static void F_4 ( struct V_16 * V_17 )
{
F_3 ( V_6 L_3 ,
V_17 -> V_18 , V_17 -> V_19 , V_17 -> V_20 ,
V_17 -> V_21 , V_17 -> V_22 ) ;
}
void F_5 ( struct V_16 * V_17 )
{
struct V_4 * V_5 ;
F_4 ( V_17 ) ;
F_3 ( V_6 L_4 ,
F_6 ( & V_17 -> V_23 ) , F_6 ( & V_17 -> V_24 ) ) ;
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
static inline void F_8 ( struct V_25 * V_26 )
{
F_9 ( & V_26 -> V_27 ) ;
}
void F_10 ( struct V_25 * V_26 )
{
F_11 ( & V_26 -> V_27 ) ;
}
int F_12 ( struct V_25 * V_26 )
{
return F_13 ( & V_26 -> V_27 ) ;
}
static inline int F_14 ( struct V_4 * V_5 )
{
return ! ( V_5 -> V_10 & V_28 ) ;
}
static inline int F_15 ( struct V_4 * V_5 )
{
return ( V_5 -> V_10 & V_29 ) ;
}
static inline int F_16 ( struct V_4 * V_5 )
{
return ( V_5 -> V_30 & V_31 ) ;
}
static inline int F_17 ( struct V_4 * V_5 )
{
return ( V_5 -> V_30 & V_32 ) ;
}
static inline int F_18 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 == V_33 ) ;
}
static inline int F_19 ( struct V_16 * V_17 )
{
F_20 (r->res_nodeid >= 0 , dlm_print_rsb(r);) ;
return ! ! V_17 -> V_18 ;
}
static inline int F_21 ( struct V_4 * V_5 )
{
return ( V_5 -> V_7 && ! ( V_5 -> V_11 & V_34 ) ) ;
}
static inline int F_22 ( struct V_4 * V_5 )
{
if ( V_5 -> V_11 & V_34 )
F_20 (lkb->lkb_nodeid, dlm_print_lkb(lkb);) ;
return ( V_5 -> V_11 & V_34 ) ? 1 : 0 ;
}
static inline int F_23 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_14 == V_35 && V_5 -> V_13 == V_36 ) ||
( V_5 -> V_13 == V_35 && V_5 -> V_14 == V_36 ) )
return 1 ;
return 0 ;
}
static inline int F_24 ( struct V_4 * V_5 )
{
return ( ! F_23 ( V_5 ) && V_5 -> V_13 < V_5 -> V_14 ) ;
}
static inline int F_25 ( struct V_4 * V_5 )
{
return V_5 -> V_11 & V_37 ;
}
static inline int F_26 ( struct V_4 * V_5 )
{
return V_5 -> V_11 & V_38 ;
}
static inline int F_27 ( struct V_4 * V_5 )
{
return ( V_5 -> V_11 & ( V_37 |
V_38 ) ) ;
}
static void F_28 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_39 )
{
if ( F_22 ( V_5 ) )
return;
F_29 ( V_5 ) ;
F_20 (lkb->lkb_lksb, dlm_print_lkb(lkb);) ;
if ( V_39 == - V_40 && ( V_5 -> V_11 & V_41 ) ) {
V_5 -> V_11 &= ~ V_41 ;
V_39 = - V_42 ;
}
if ( V_39 == - V_40 && ( V_5 -> V_11 & V_43 ) ) {
V_5 -> V_11 &= ~ V_43 ;
V_39 = - V_44 ;
}
F_30 ( V_5 , V_45 , V_5 -> V_14 , V_39 , V_5 -> V_30 ) ;
}
static inline void F_31 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_28 ( V_17 , V_5 ,
F_25 ( V_5 ) ? - V_46 : - V_40 ) ;
}
static void F_32 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_47 )
{
if ( F_22 ( V_5 ) ) {
F_33 ( V_17 , V_5 , V_47 ) ;
} else {
F_30 ( V_5 , V_48 , V_47 , 0 , 0 ) ;
}
}
static int F_34 ( struct V_25 * V_26 )
{
struct V_16 * V_49 , * V_50 ;
int V_51 = 0 ;
F_35 ( & V_26 -> V_52 ) ;
if ( V_26 -> V_53 > V_54 . V_55 / 2 ) {
F_36 ( & V_26 -> V_52 ) ;
return 0 ;
}
F_36 ( & V_26 -> V_52 ) ;
V_49 = F_37 ( V_26 ) ;
V_50 = F_37 ( V_26 ) ;
F_35 ( & V_26 -> V_52 ) ;
if ( V_49 ) {
F_38 ( & V_49 -> V_56 , & V_26 -> V_57 ) ;
V_26 -> V_53 ++ ;
}
if ( V_50 ) {
F_38 ( & V_50 -> V_56 , & V_26 -> V_57 ) ;
V_26 -> V_53 ++ ;
}
V_51 = V_26 -> V_53 ;
F_36 ( & V_26 -> V_52 ) ;
if ( ! V_51 )
return - V_58 ;
return 0 ;
}
static int F_39 ( struct V_25 * V_26 , char * V_59 , int V_60 ,
struct V_16 * * V_61 )
{
struct V_16 * V_17 ;
int V_51 ;
F_35 ( & V_26 -> V_52 ) ;
if ( F_6 ( & V_26 -> V_57 ) ) {
V_51 = V_26 -> V_53 ;
F_36 ( & V_26 -> V_52 ) ;
F_40 ( V_26 , L_9 ,
V_51 , V_54 . V_55 , V_59 ) ;
return - V_62 ;
}
V_17 = F_41 ( & V_26 -> V_57 , struct V_16 , V_56 ) ;
F_42 ( & V_17 -> V_56 ) ;
memset ( & V_17 -> V_63 , 0 , sizeof( struct V_64 ) ) ;
V_26 -> V_53 -- ;
F_36 ( & V_26 -> V_52 ) ;
V_17 -> V_65 = V_26 ;
V_17 -> V_66 = V_60 ;
memcpy ( V_17 -> V_22 , V_59 , V_60 ) ;
F_43 ( & V_17 -> V_67 ) ;
F_44 ( & V_17 -> V_68 ) ;
F_44 ( & V_17 -> V_69 ) ;
F_44 ( & V_17 -> V_70 ) ;
F_44 ( & V_17 -> V_71 ) ;
F_44 ( & V_17 -> V_23 ) ;
F_44 ( & V_17 -> V_24 ) ;
* V_61 = V_17 ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 , const char * V_59 , int V_72 )
{
char V_73 [ V_74 ] ;
memset ( V_73 , 0 , V_74 ) ;
memcpy ( V_73 , V_59 , V_72 ) ;
return memcmp ( V_17 -> V_22 , V_73 , V_74 ) ;
}
static int F_46 ( struct V_75 * V_76 , char * V_59 , int V_60 ,
unsigned int V_77 , struct V_16 * * V_61 )
{
struct V_64 * V_78 = V_76 -> V_64 ;
struct V_16 * V_17 ;
int error = 0 ;
int V_79 ;
while ( V_78 ) {
V_17 = F_47 ( V_78 , struct V_16 , V_63 ) ;
V_79 = F_45 ( V_17 , V_59 , V_60 ) ;
if ( V_79 < 0 )
V_78 = V_78 -> V_80 ;
else if ( V_79 > 0 )
V_78 = V_78 -> V_81 ;
else
goto V_82;
}
* V_61 = NULL ;
return - V_83 ;
V_82:
if ( V_17 -> V_18 && ( V_77 & V_84 ) )
error = - V_85 ;
* V_61 = V_17 ;
return error ;
}
static int F_48 ( struct V_16 * V_86 , struct V_75 * V_76 )
{
struct V_64 * * V_87 = & V_76 -> V_64 ;
struct V_64 * V_88 = NULL ;
int V_79 ;
while ( * V_87 ) {
struct V_16 * V_89 = F_47 ( * V_87 , struct V_16 ,
V_63 ) ;
V_88 = * V_87 ;
V_79 = F_45 ( V_89 , V_86 -> V_22 , V_86 -> V_66 ) ;
if ( V_79 < 0 )
V_87 = & V_88 -> V_80 ;
else if ( V_79 > 0 )
V_87 = & V_88 -> V_81 ;
else {
F_49 ( L_10 ) ;
F_5 ( V_86 ) ;
F_5 ( V_89 ) ;
return - V_90 ;
}
}
F_50 ( & V_86 -> V_63 , V_88 , V_87 ) ;
F_51 ( & V_86 -> V_63 , V_76 ) ;
return 0 ;
}
static int F_52 ( struct V_25 * V_26 , char * V_59 , int V_60 , int V_91 ,
unsigned int V_77 , struct V_16 * * V_61 )
{
struct V_16 * V_17 ;
int error ;
error = F_46 ( & V_26 -> V_92 [ V_91 ] . V_93 , V_59 , V_60 , V_77 , & V_17 ) ;
if ( ! error ) {
F_53 ( & V_17 -> V_94 ) ;
goto V_95;
}
error = F_46 ( & V_26 -> V_92 [ V_91 ] . V_96 , V_59 , V_60 , V_77 , & V_17 ) ;
if ( error )
goto V_95;
F_54 ( & V_17 -> V_63 , & V_26 -> V_92 [ V_91 ] . V_96 ) ;
error = F_48 ( V_17 , & V_26 -> V_92 [ V_91 ] . V_93 ) ;
if ( error )
return error ;
if ( F_55 ( V_26 ) )
goto V_95;
if ( V_17 -> V_18 == - 1 ) {
F_56 ( V_17 , V_97 ) ;
V_17 -> V_20 = 0 ;
} else if ( V_17 -> V_18 > 0 ) {
F_57 ( V_17 , V_97 ) ;
V_17 -> V_20 = 0 ;
} else {
F_20 (r->res_nodeid == 0 , dlm_print_rsb(r);) ;
F_20 ( ! F_58 ( V_17 , V_97 ) ,) ;
}
V_95:
* V_61 = V_17 ;
return error ;
}
static int F_59 ( struct V_25 * V_26 , char * V_59 , int V_98 ,
unsigned int V_77 , struct V_16 * * V_61 )
{
struct V_16 * V_17 = NULL ;
T_1 V_99 , V_100 ;
int error ;
if ( V_98 > V_74 ) {
error = - V_101 ;
goto V_95;
}
if ( F_55 ( V_26 ) )
V_77 |= V_102 ;
V_99 = F_60 ( V_59 , V_98 , 0 ) ;
V_100 = V_99 & ( V_26 -> V_103 - 1 ) ;
V_104:
if ( V_77 & V_102 ) {
error = F_34 ( V_26 ) ;
if ( error < 0 )
goto V_95;
}
F_35 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
error = F_52 ( V_26 , V_59 , V_98 , V_100 , V_77 , & V_17 ) ;
if ( ! error )
goto V_106;
if ( error == - V_83 && ! ( V_77 & V_102 ) )
goto V_106;
if ( error == - V_85 )
goto V_106;
error = F_39 ( V_26 , V_59 , V_98 , & V_17 ) ;
if ( error == - V_62 ) {
F_36 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
goto V_104;
}
if ( error )
goto V_106;
V_17 -> V_107 = V_99 ;
V_17 -> V_108 = V_100 ;
V_17 -> V_18 = - 1 ;
F_61 ( & V_17 -> V_94 ) ;
if ( F_55 ( V_26 ) ) {
int V_109 = F_62 ( V_17 ) ;
if ( V_109 == F_63 () )
V_109 = 0 ;
V_17 -> V_18 = V_109 ;
}
error = F_48 ( V_17 , & V_26 -> V_92 [ V_100 ] . V_93 ) ;
V_106:
F_36 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
V_95:
* V_61 = V_17 ;
return error ;
}
static inline void F_64 ( struct V_16 * V_17 )
{
F_53 ( & V_17 -> V_94 ) ;
}
void F_65 ( struct V_16 * V_17 )
{
F_64 ( V_17 ) ;
}
static void F_66 ( struct V_110 * V_110 )
{
struct V_16 * V_17 = F_67 ( V_110 , struct V_16 , V_94 ) ;
struct V_25 * V_26 = V_17 -> V_65 ;
F_20 (list_empty(&r->res_root_list), dlm_print_rsb(r);) ;
F_61 ( & V_17 -> V_94 ) ;
F_54 ( & V_17 -> V_63 , & V_26 -> V_92 [ V_17 -> V_108 ] . V_93 ) ;
F_48 ( V_17 , & V_26 -> V_92 [ V_17 -> V_108 ] . V_96 ) ;
V_17 -> V_111 = V_112 ;
if ( V_17 -> V_113 ) {
F_68 ( V_17 -> V_113 ) ;
V_17 -> V_113 = NULL ;
}
}
static void F_69 ( struct V_16 * V_17 )
{
struct V_25 * V_26 = V_17 -> V_65 ;
T_1 V_100 = V_17 -> V_108 ;
F_35 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
F_70 ( & V_17 -> V_94 , F_66 ) ;
F_36 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
}
void F_71 ( struct V_16 * V_17 )
{
F_69 ( V_17 ) ;
}
static void F_72 ( struct V_16 * V_17 )
{
int V_39 ;
V_39 = F_70 ( & V_17 -> V_94 , F_66 ) ;
F_20 (!rv, dlm_dump_rsb(r);) ;
}
static void F_73 ( struct V_110 * V_110 )
{
struct V_16 * V_17 = F_67 ( V_110 , struct V_16 , V_94 ) ;
F_20 (list_empty(&r->res_lookup), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_grantqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_convertqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_waitqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_root_list), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_recover_list), dlm_dump_rsb(r);) ;
}
static void F_74 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_64 ( V_17 ) ;
V_5 -> V_114 = V_17 ;
}
static void F_75 ( struct V_4 * V_5 )
{
if ( V_5 -> V_114 ) {
F_69 ( V_5 -> V_114 ) ;
V_5 -> V_114 = NULL ;
}
}
static int F_76 ( struct V_25 * V_26 , struct V_4 * * V_115 )
{
struct V_4 * V_5 ;
int V_39 , V_116 ;
V_5 = F_77 ( V_26 ) ;
if ( ! V_5 )
return - V_58 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_14 = V_117 ;
F_61 ( & V_5 -> V_118 ) ;
F_44 ( & V_5 -> V_119 ) ;
F_44 ( & V_5 -> V_120 ) ;
F_44 ( & V_5 -> V_121 ) ;
F_44 ( & V_5 -> V_122 ) ;
F_43 ( & V_5 -> V_123 ) ;
F_78 ( & V_5 -> V_124 , V_125 ) ;
V_104:
V_39 = F_79 ( & V_26 -> V_126 , V_127 ) ;
if ( ! V_39 )
return - V_58 ;
F_35 ( & V_26 -> V_128 ) ;
V_39 = F_80 ( & V_26 -> V_126 , V_5 , 1 , & V_116 ) ;
if ( ! V_39 )
V_5 -> V_8 = V_116 ;
F_36 ( & V_26 -> V_128 ) ;
if ( V_39 == - V_62 )
goto V_104;
if ( V_39 < 0 ) {
F_81 ( V_26 , L_11 , V_39 ) ;
return V_39 ;
}
* V_115 = V_5 ;
return 0 ;
}
static int F_82 ( struct V_25 * V_26 , T_1 V_129 , struct V_4 * * V_115 )
{
struct V_4 * V_5 ;
F_35 ( & V_26 -> V_128 ) ;
V_5 = F_83 ( & V_26 -> V_126 , V_129 ) ;
if ( V_5 )
F_53 ( & V_5 -> V_118 ) ;
F_36 ( & V_26 -> V_128 ) ;
* V_115 = V_5 ;
return V_5 ? 0 : - V_130 ;
}
static void F_84 ( struct V_110 * V_110 )
{
struct V_4 * V_5 = F_67 ( V_110 , struct V_4 , V_118 ) ;
F_20 (!lkb->lkb_status, dlm_print_lkb(lkb);) ;
}
static int F_85 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
T_1 V_129 = V_5 -> V_8 ;
F_35 ( & V_26 -> V_128 ) ;
if ( F_70 ( & V_5 -> V_118 , F_84 ) ) {
F_86 ( & V_26 -> V_126 , V_129 ) ;
F_36 ( & V_26 -> V_128 ) ;
F_75 ( V_5 ) ;
if ( V_5 -> V_131 && F_22 ( V_5 ) )
F_68 ( V_5 -> V_131 ) ;
F_87 ( V_5 ) ;
return 1 ;
} else {
F_36 ( & V_26 -> V_128 ) ;
return 0 ;
}
}
int F_88 ( struct V_4 * V_5 )
{
struct V_25 * V_26 ;
F_20 (lkb->lkb_resource, dlm_print_lkb(lkb);) ;
F_20 (lkb->lkb_resource->res_ls, dlm_print_lkb(lkb);) ;
V_26 = V_5 -> V_114 -> V_65 ;
return F_85 ( V_26 , V_5 ) ;
}
static inline void F_89 ( struct V_4 * V_5 )
{
F_53 ( & V_5 -> V_118 ) ;
}
static inline void F_90 ( struct V_4 * V_5 )
{
int V_39 ;
V_39 = F_70 ( & V_5 -> V_118 , F_84 ) ;
F_20 (!rv, dlm_print_lkb(lkb);) ;
}
static void F_91 ( struct V_132 * V_133 , struct V_132 * V_134 ,
int V_135 )
{
struct V_4 * V_5 = NULL ;
F_7 (lkb, head, lkb_statequeue)
if ( V_5 -> V_13 < V_135 )
break;
F_92 ( V_133 , V_5 -> V_136 . V_137 , & V_5 -> V_136 ) ;
}
static void F_93 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_138 )
{
F_53 ( & V_5 -> V_118 ) ;
F_20 (!lkb->lkb_status, dlm_print_lkb(lkb);) ;
V_5 -> V_139 = F_94 () ;
V_5 -> V_12 = V_138 ;
switch ( V_138 ) {
case V_140 :
if ( V_5 -> V_10 & V_141 )
F_38 ( & V_5 -> V_136 , & V_17 -> V_71 ) ;
else
F_95 ( & V_5 -> V_136 , & V_17 -> V_71 ) ;
break;
case V_33 :
F_91 ( & V_5 -> V_136 , & V_17 -> V_69 ,
V_5 -> V_14 ) ;
break;
case V_142 :
if ( V_5 -> V_10 & V_141 )
F_38 ( & V_5 -> V_136 , & V_17 -> V_70 ) ;
else
F_95 ( & V_5 -> V_136 ,
& V_17 -> V_70 ) ;
break;
default:
F_20 ( 0 , dlm_print_lkb(lkb); printk(L_12, status);) ;
}
}
static void F_96 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
V_5 -> V_12 = 0 ;
F_42 ( & V_5 -> V_136 ) ;
F_90 ( V_5 ) ;
}
static void F_97 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_143 )
{
F_89 ( V_5 ) ;
F_96 ( V_17 , V_5 ) ;
F_93 ( V_17 , V_5 , V_143 ) ;
F_90 ( V_5 ) ;
}
static int F_98 ( int V_144 )
{
switch ( V_144 ) {
case V_145 :
return V_146 ;
case V_147 :
return V_148 ;
case V_149 :
return V_150 ;
case V_151 :
return V_152 ;
case V_153 :
return V_154 ;
}
return - 1 ;
}
static int F_99 ( int V_109 , int V_155 , int * V_156 )
{
int V_157 ;
for ( V_157 = 0 ; V_157 < V_155 ; V_157 ++ ) {
if ( ! V_156 [ V_157 ] ) {
V_156 [ V_157 ] = V_109 ;
return 0 ;
}
if ( V_156 [ V_157 ] == V_109 )
return 1 ;
}
return 0 ;
}
void F_100 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
T_2 V_158 = F_101 ( 0 , 0 ) ;
T_3 V_159 ;
T_3 V_160 = 0 ;
T_4 V_161 = 0 ;
T_4 V_162 = 0 ;
int V_155 = 0 ;
int * V_156 = NULL ;
if ( ! V_54 . V_163 )
return;
F_102 ( & V_26 -> V_164 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_103 ( V_5 -> V_165 , V_158 ) )
continue;
V_161 ++ ;
V_159 = F_104 ( F_105 ( F_94 () , V_5 -> V_165 ) ) ;
if ( V_159 < V_54 . V_163 )
continue;
V_5 -> V_165 = V_158 ;
V_162 ++ ;
if ( V_159 > V_160 )
V_160 = V_159 ;
if ( ! V_155 ) {
V_155 = V_26 -> V_166 ;
V_156 = F_106 ( V_155 * sizeof( int ) , V_167 ) ;
}
if ( ! V_156 )
continue;
if ( F_99 ( V_5 -> V_168 , V_155 , V_156 ) )
continue;
F_81 ( V_26 , L_13
L_14 , V_5 -> V_8 , ( long long ) V_159 ,
V_54 . V_163 , V_5 -> V_168 ) ;
}
F_107 ( & V_26 -> V_164 ) ;
F_108 ( V_156 ) ;
if ( V_162 )
F_40 ( V_26 , L_15 ,
V_161 , V_162 ,
V_54 . V_163 , ( long long ) V_160 ) ;
}
static int F_109 ( struct V_4 * V_5 , int V_144 , int V_169 )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
int error = 0 ;
F_102 ( & V_26 -> V_164 ) ;
if ( F_25 ( V_5 ) ||
( F_26 ( V_5 ) && ( V_144 == V_151 ) ) ) {
error = - V_101 ;
goto V_95;
}
if ( V_5 -> V_15 || F_26 ( V_5 ) ) {
switch ( V_144 ) {
case V_149 :
V_5 -> V_11 |= V_37 ;
break;
case V_151 :
V_5 -> V_11 |= V_38 ;
break;
default:
error = - V_170 ;
goto V_95;
}
V_5 -> V_171 ++ ;
F_89 ( V_5 ) ;
F_40 ( V_26 , L_16 ,
V_5 -> V_8 , V_5 -> V_15 , V_144 ,
V_5 -> V_171 , V_5 -> V_11 ) ;
goto V_95;
}
F_20 (!lkb->lkb_wait_count,
dlm_print_lkb(lkb);
printk(L_17, lkb->lkb_wait_count);) ;
V_5 -> V_171 ++ ;
V_5 -> V_15 = V_144 ;
V_5 -> V_165 = F_94 () ;
V_5 -> V_168 = V_169 ;
F_89 ( V_5 ) ;
F_38 ( & V_5 -> V_172 , & V_26 -> V_173 ) ;
V_95:
if ( error )
F_81 ( V_26 , L_18 ,
V_5 -> V_8 , error , V_5 -> V_11 , V_144 ,
V_5 -> V_15 , V_5 -> V_114 -> V_22 ) ;
F_107 ( & V_26 -> V_164 ) ;
return error ;
}
static int F_110 ( struct V_4 * V_5 , int V_144 ,
struct V_174 * V_175 )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
int V_176 = 0 ;
if ( F_25 ( V_5 ) && ( V_144 == V_150 ) ) {
F_40 ( V_26 , L_19 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_37 ;
V_176 = 1 ;
goto V_177;
}
if ( F_26 ( V_5 ) && ( V_144 == V_152 ) ) {
F_40 ( V_26 , L_20 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_38 ;
V_176 = 1 ;
goto V_177;
}
if ( ( V_144 == V_152 ) &&
( V_5 -> V_15 != V_151 ) ) {
F_40 ( V_26 , L_21 ,
V_5 -> V_8 , V_5 -> V_15 ) ;
return - 1 ;
}
if ( ( V_144 == V_148 ) &&
( V_5 -> V_15 == V_147 ) &&
F_26 ( V_5 ) && V_175 && ! V_175 -> V_178 ) {
F_40 ( V_26 , L_22 ,
V_5 -> V_8 ) ;
V_5 -> V_15 = 0 ;
V_5 -> V_11 &= ~ V_38 ;
V_5 -> V_171 -- ;
goto V_177;
}
if ( V_5 -> V_15 ) {
V_5 -> V_15 = 0 ;
goto V_177;
}
F_81 ( V_26 , L_23 ,
V_5 -> V_8 , V_144 , V_5 -> V_11 ) ;
return - 1 ;
V_177:
if ( V_176 && V_5 -> V_15 ) {
F_81 ( V_26 , L_24 ,
V_5 -> V_8 , V_144 , V_5 -> V_15 ) ;
V_5 -> V_171 -- ;
V_5 -> V_15 = 0 ;
}
F_20 (lkb->lkb_wait_count, dlm_print_lkb(lkb);) ;
V_5 -> V_11 &= ~ V_179 ;
V_5 -> V_171 -- ;
if ( ! V_5 -> V_171 )
F_111 ( & V_5 -> V_172 ) ;
F_90 ( V_5 ) ;
return 0 ;
}
static int F_112 ( struct V_4 * V_5 , int V_144 )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
int error ;
F_102 ( & V_26 -> V_164 ) ;
error = F_110 ( V_5 , V_144 , NULL ) ;
F_107 ( & V_26 -> V_164 ) ;
return error ;
}
static int F_113 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
int error ;
if ( V_175 -> V_180 != V_181 )
F_102 ( & V_26 -> V_164 ) ;
error = F_110 ( V_5 , V_175 -> V_182 , V_175 ) ;
if ( V_175 -> V_180 != V_181 )
F_107 ( & V_26 -> V_164 ) ;
return error ;
}
static void F_114 ( struct V_16 * V_17 )
{
int V_169 ;
if ( F_55 ( V_17 -> V_65 ) )
return;
V_169 = F_62 ( V_17 ) ;
if ( V_169 != F_63 () )
F_115 ( V_17 ) ;
else
F_116 ( V_17 -> V_65 , V_169 ,
V_17 -> V_22 , V_17 -> V_66 ) ;
}
static int F_117 ( struct V_25 * V_26 , int V_91 )
{
struct V_64 * V_183 ;
struct V_16 * V_17 ;
int V_51 = 0 , V_82 ;
for (; ; ) {
V_82 = 0 ;
F_35 ( & V_26 -> V_92 [ V_91 ] . V_105 ) ;
for ( V_183 = F_118 ( & V_26 -> V_92 [ V_91 ] . V_96 ) ; V_183 ; V_183 = F_119 ( V_183 ) ) {
V_17 = F_47 ( V_183 , struct V_16 , V_63 ) ;
if ( ! F_120 ( V_112 , V_17 -> V_111 +
V_54 . V_184 * V_185 ) )
continue;
V_82 = 1 ;
break;
}
if ( ! V_82 ) {
F_36 ( & V_26 -> V_92 [ V_91 ] . V_105 ) ;
break;
}
if ( F_70 ( & V_17 -> V_94 , F_73 ) ) {
F_54 ( & V_17 -> V_63 , & V_26 -> V_92 [ V_91 ] . V_96 ) ;
F_36 ( & V_26 -> V_92 [ V_91 ] . V_105 ) ;
if ( F_121 ( V_17 ) )
F_114 ( V_17 ) ;
F_122 ( V_17 ) ;
V_51 ++ ;
} else {
F_36 ( & V_26 -> V_92 [ V_91 ] . V_105 ) ;
F_81 ( V_26 , L_25 , V_17 -> V_22 ) ;
}
}
return V_51 ;
}
void F_123 ( struct V_25 * V_26 )
{
int V_157 ;
for ( V_157 = 0 ; V_157 < V_26 -> V_103 ; V_157 ++ ) {
F_117 ( V_26 , V_157 ) ;
if ( F_124 ( V_26 ) )
break;
F_125 () ;
}
}
static void F_126 ( struct V_4 * V_5 )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
if ( F_22 ( V_5 ) )
return;
if ( F_127 ( V_186 , & V_26 -> V_187 ) &&
! ( V_5 -> V_10 & V_188 ) ) {
V_5 -> V_11 |= V_189 ;
goto V_190;
}
if ( V_5 -> V_10 & V_191 )
goto V_190;
return;
V_190:
F_20 (list_empty(&lkb->lkb_time_list), dlm_print_lkb(lkb);) ;
F_102 ( & V_26 -> V_192 ) ;
F_89 ( V_5 ) ;
F_95 ( & V_5 -> V_121 , & V_26 -> V_193 ) ;
F_107 ( & V_26 -> V_192 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
F_102 ( & V_26 -> V_192 ) ;
if ( ! F_6 ( & V_5 -> V_121 ) ) {
F_111 ( & V_5 -> V_121 ) ;
F_90 ( V_5 ) ;
}
F_107 ( & V_26 -> V_192 ) ;
}
void F_128 ( struct V_25 * V_26 )
{
struct V_16 * V_17 ;
struct V_4 * V_5 ;
int V_194 , V_195 ;
T_3 V_196 ;
for (; ; ) {
if ( F_124 ( V_26 ) )
break;
V_194 = 0 ;
V_195 = 0 ;
F_102 ( & V_26 -> V_192 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list) {
V_196 = F_104 ( F_105 ( F_94 () ,
V_5 -> V_139 ) ) ;
if ( ( V_5 -> V_10 & V_191 ) &&
V_196 >= ( V_5 -> V_197 * 10000 ) )
V_194 = 1 ;
if ( ( V_5 -> V_11 & V_189 ) &&
V_196 >= V_54 . V_198 * 10000 )
V_195 = 1 ;
if ( ! V_194 && ! V_195 )
continue;
F_89 ( V_5 ) ;
break;
}
F_107 ( & V_26 -> V_192 ) ;
if ( ! V_194 && ! V_195 )
break;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
if ( V_195 ) {
V_5 -> V_11 &= ~ V_189 ;
if ( ! ( V_5 -> V_10 & V_191 ) )
F_29 ( V_5 ) ;
F_130 ( V_5 ) ;
}
if ( V_194 ) {
F_40 ( V_26 , L_26 ,
V_5 -> V_8 , V_5 -> V_7 , V_17 -> V_22 ) ;
V_5 -> V_11 &= ~ V_189 ;
V_5 -> V_11 |= V_41 ;
F_29 ( V_5 ) ;
F_131 ( V_17 , V_5 ) ;
}
F_132 ( V_17 ) ;
F_72 ( V_17 ) ;
F_88 ( V_5 ) ;
}
}
void F_133 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
T_5 V_199 = F_134 ( V_112 - V_26 -> V_200 ) ;
V_26 -> V_200 = 0 ;
F_102 ( & V_26 -> V_192 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list)
V_5 -> V_139 = F_135 ( V_5 -> V_139 , V_199 ) ;
F_107 ( & V_26 -> V_192 ) ;
if ( ! V_54 . V_163 )
return;
F_102 ( & V_26 -> V_164 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_104 ( V_5 -> V_165 ) )
V_5 -> V_165 = F_94 () ;
}
F_107 ( & V_26 -> V_164 ) ;
}
static void F_136 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int V_91 , V_60 = V_17 -> V_65 -> V_201 ;
V_91 = V_202 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_91 == 1 ) {
if ( ! V_5 -> V_131 )
return;
if ( ! ( V_5 -> V_10 & V_203 ) )
return;
if ( ! V_17 -> V_113 )
return;
memcpy ( V_5 -> V_131 , V_17 -> V_113 , V_60 ) ;
V_5 -> V_204 = V_17 -> V_205 ;
} else if ( V_91 == 0 ) {
if ( V_5 -> V_10 & V_206 ) {
F_57 ( V_17 , V_207 ) ;
return;
}
if ( ! V_5 -> V_131 )
return;
if ( ! ( V_5 -> V_10 & V_203 ) )
return;
if ( ! V_17 -> V_113 )
V_17 -> V_113 = F_137 ( V_17 -> V_65 ) ;
if ( ! V_17 -> V_113 )
return;
memcpy ( V_17 -> V_113 , V_5 -> V_131 , V_60 ) ;
V_17 -> V_205 ++ ;
V_5 -> V_204 = V_17 -> V_205 ;
F_56 ( V_17 , V_207 ) ;
}
if ( F_58 ( V_17 , V_207 ) )
V_5 -> V_30 |= V_208 ;
}
static void F_138 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 < V_209 )
return;
if ( V_5 -> V_10 & V_206 ) {
F_57 ( V_17 , V_207 ) ;
return;
}
if ( ! V_5 -> V_131 )
return;
if ( ! ( V_5 -> V_10 & V_203 ) )
return;
if ( ! V_17 -> V_113 )
V_17 -> V_113 = F_137 ( V_17 -> V_65 ) ;
if ( ! V_17 -> V_113 )
return;
memcpy ( V_17 -> V_113 , V_5 -> V_131 , V_17 -> V_65 -> V_201 ) ;
V_17 -> V_205 ++ ;
F_56 ( V_17 , V_207 ) ;
}
static void F_139 ( struct V_16 * V_17 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
int V_91 ;
if ( ! V_5 -> V_131 )
return;
if ( ! ( V_5 -> V_10 & V_203 ) )
return;
V_91 = V_202 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_91 == 1 ) {
int V_60 = F_140 ( V_175 ) ;
if ( V_60 > V_74 )
V_60 = V_74 ;
memcpy ( V_5 -> V_131 , V_175 -> V_210 , V_60 ) ;
V_5 -> V_204 = V_175 -> V_211 ;
}
}
static void F_141 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_96 ( V_17 , V_5 ) ;
V_5 -> V_14 = V_117 ;
F_90 ( V_5 ) ;
}
static void F_142 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_138 ( V_17 , V_5 ) ;
F_141 ( V_17 , V_5 ) ;
}
static void F_143 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_141 ( V_17 , V_5 ) ;
}
static int F_144 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int V_39 = 0 ;
V_5 -> V_13 = V_117 ;
switch ( V_5 -> V_12 ) {
case V_33 :
break;
case V_142 :
F_97 ( V_17 , V_5 , V_33 ) ;
V_39 = 1 ;
break;
case V_140 :
F_96 ( V_17 , V_5 ) ;
V_5 -> V_14 = V_117 ;
F_90 ( V_5 ) ;
V_39 = - 1 ;
break;
default:
F_49 ( L_27 , V_5 -> V_12 ) ;
}
return V_39 ;
}
static int F_145 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
return F_144 ( V_17 , V_5 ) ;
}
static void F_146 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 != V_5 -> V_13 ) {
V_5 -> V_14 = V_5 -> V_13 ;
if ( V_5 -> V_12 )
F_97 ( V_17 , V_5 , V_33 ) ;
else
F_93 ( V_17 , V_5 , V_33 ) ;
}
V_5 -> V_13 = V_117 ;
}
static void F_147 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_136 ( V_17 , V_5 ) ;
F_146 ( V_17 , V_5 ) ;
V_5 -> V_212 = 0 ;
}
static void F_148 ( struct V_16 * V_17 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
F_139 ( V_17 , V_5 , V_175 ) ;
F_146 ( V_17 , V_5 ) ;
}
static void F_149 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_147 ( V_17 , V_5 ) ;
if ( F_22 ( V_5 ) )
F_150 ( V_17 , V_5 ) ;
else
F_28 ( V_17 , V_5 , 0 ) ;
}
static void F_151 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 == V_117 || V_5 -> V_14 == V_117 ) {
F_49 ( L_28 ,
V_5 -> V_8 , V_5 -> V_14 , V_5 -> V_13 ) ;
return;
}
V_5 -> V_14 = V_213 ;
}
static void F_152 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
if ( V_175 -> V_182 != V_146 &&
V_175 -> V_182 != V_214 ) {
F_49 ( L_29 ,
V_5 -> V_8 , V_175 -> V_182 ) ;
return;
}
if ( V_5 -> V_10 & V_215 )
V_5 -> V_13 = V_35 ;
else if ( V_5 -> V_10 & V_216 )
V_5 -> V_13 = V_36 ;
else {
F_49 ( L_30 , V_5 -> V_10 ) ;
F_2 ( V_5 ) ;
}
}
static inline int F_153 ( struct V_4 * V_5 , struct V_132 * V_134 )
{
struct V_4 * V_217 = F_154 ( V_134 -> V_218 , struct V_4 ,
V_136 ) ;
if ( V_5 -> V_8 == V_217 -> V_8 )
return 1 ;
return 0 ;
}
static int F_155 ( struct V_132 * V_134 , struct V_4 * V_5 )
{
struct V_4 * V_219 ;
F_7 (this, head, lkb_statequeue) {
if ( V_219 == V_5 )
continue;
if ( ! F_156 ( V_219 , V_5 ) )
return 1 ;
}
return 0 ;
}
static int F_157 ( struct V_16 * V_17 , struct V_4 * V_220 )
{
struct V_4 * V_221 ;
int V_222 = 0 ;
F_7 (lkb1, &r->res_convertqueue, lkb_statequeue) {
if ( V_221 == V_220 ) {
V_222 = 1 ;
continue;
}
if ( ! V_222 ) {
if ( ! F_156 ( V_220 , V_221 ) )
return 1 ;
} else {
if ( ! F_156 ( V_220 , V_221 ) &&
! F_156 ( V_221 , V_220 ) )
return 1 ;
}
}
return 0 ;
}
static int F_158 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_223 )
{
T_6 V_224 = ( V_5 -> V_14 != V_117 ) ;
if ( V_5 -> V_10 & V_225 )
return 1 ;
if ( F_155 ( & V_17 -> V_69 , V_5 ) )
goto V_95;
if ( F_155 ( & V_17 -> V_70 , V_5 ) )
goto V_95;
if ( V_223 && V_224 && ! ( V_5 -> V_10 & V_226 ) )
return 1 ;
if ( V_5 -> V_10 & V_227 )
return 1 ;
if ( ! V_223 && V_224 && F_153 ( V_5 , & V_17 -> V_70 ) )
return 1 ;
if ( V_223 && ! V_224 && F_6 ( & V_17 -> V_70 ) &&
F_6 ( & V_17 -> V_71 ) )
return 1 ;
if ( ! V_223 && ! V_224 && F_6 ( & V_17 -> V_70 ) &&
F_153 ( V_5 , & V_17 -> V_71 ) )
return 1 ;
V_95:
return 0 ;
}
static int F_159 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_223 ,
int * V_228 )
{
int V_39 ;
T_6 V_229 = 0 , V_47 = V_5 -> V_13 ;
T_6 V_230 = ( V_5 -> V_14 != V_117 ) ;
if ( V_228 )
* V_228 = 0 ;
V_39 = F_158 ( V_17 , V_5 , V_223 ) ;
if ( V_39 )
goto V_95;
if ( V_230 && F_14 ( V_5 ) &&
F_157 ( V_17 , V_5 ) ) {
if ( V_5 -> V_10 & V_231 ) {
V_5 -> V_14 = V_213 ;
V_5 -> V_30 |= V_31 ;
} else if ( ! ( V_5 -> V_10 & V_188 ) ) {
if ( V_228 )
* V_228 = - V_44 ;
else {
F_49 ( L_31 ,
V_5 -> V_8 , V_223 ) ;
F_5 ( V_17 ) ;
}
}
goto V_95;
}
if ( V_47 != V_35 && ( V_5 -> V_10 & V_215 ) )
V_229 = V_35 ;
else if ( V_47 != V_36 && ( V_5 -> V_10 & V_216 ) )
V_229 = V_36 ;
if ( V_229 ) {
V_5 -> V_13 = V_229 ;
V_39 = F_158 ( V_17 , V_5 , V_223 ) ;
if ( V_39 )
V_5 -> V_30 |= V_32 ;
else
V_5 -> V_13 = V_47 ;
}
V_95:
return V_39 ;
}
static int F_160 ( struct V_16 * V_17 , int V_232 , int * V_233 )
{
struct V_4 * V_5 , * V_234 ;
int V_235 , V_236 , V_237 , V_238 , V_239 ;
int V_240 ;
V_237 = 0 ;
V_241:
V_238 = 0 ;
V_239 = 0 ;
V_235 = V_117 ;
F_161 (lkb, s, &r->res_convertqueue, lkb_statequeue) {
V_236 = F_16 ( V_5 ) ;
V_240 = 0 ;
if ( F_159 ( V_17 , V_5 , 0 , & V_240 ) ) {
F_149 ( V_17 , V_5 ) ;
V_238 = 1 ;
continue;
}
if ( ! V_236 && F_16 ( V_5 ) ) {
F_49 ( L_32 ,
V_5 -> V_8 , V_5 -> V_7 , V_17 -> V_22 ) ;
V_239 = 1 ;
continue;
}
if ( V_240 ) {
F_49 ( L_33 ,
V_5 -> V_8 , V_5 -> V_7 , V_17 -> V_22 ) ;
F_5 ( V_17 ) ;
continue;
}
V_235 = F_162 ( int , V_5 -> V_13 , V_235 ) ;
if ( V_233 && V_5 -> V_13 == V_36 )
* V_233 = 1 ;
}
if ( V_238 )
goto V_241;
if ( V_239 && ! V_237 ) {
V_237 = 1 ;
goto V_241;
}
return F_162 ( int , V_232 , V_235 ) ;
}
static int F_163 ( struct V_16 * V_17 , int V_232 , int * V_233 )
{
struct V_4 * V_5 , * V_234 ;
F_161 (lkb, s, &r->res_waitqueue, lkb_statequeue) {
if ( F_159 ( V_17 , V_5 , 0 , NULL ) )
F_149 ( V_17 , V_5 ) ;
else {
V_232 = F_162 ( int , V_5 -> V_13 , V_232 ) ;
if ( V_5 -> V_13 == V_36 )
* V_233 = 1 ;
}
}
return V_232 ;
}
static int F_164 ( struct V_4 * V_242 , int V_232 , int V_233 )
{
if ( V_242 -> V_14 == V_35 && V_233 ) {
if ( V_242 -> V_212 < V_243 )
return 1 ;
return 0 ;
}
if ( V_242 -> V_212 < V_232 &&
! V_3 [ V_242 -> V_14 + 1 ] [ V_232 + 1 ] )
return 1 ;
return 0 ;
}
static void F_165 ( struct V_16 * V_17 )
{
struct V_4 * V_5 , * V_234 ;
int V_232 = V_117 ;
int V_233 = 0 ;
F_20 (is_master(r), dlm_dump_rsb(r);) ;
V_232 = F_160 ( V_17 , V_232 , & V_233 ) ;
V_232 = F_163 ( V_17 , V_232 , & V_233 ) ;
if ( V_232 == V_117 )
return;
F_161 (lkb, s, &r->res_grantqueue, lkb_statequeue) {
if ( V_5 -> V_244 && F_164 ( V_5 , V_232 , V_233 ) ) {
if ( V_233 && V_232 == V_35 &&
V_5 -> V_14 == V_35 )
F_32 ( V_17 , V_5 , V_36 ) ;
else
F_32 ( V_17 , V_5 , V_232 ) ;
V_5 -> V_212 = V_232 ;
}
}
}
static int F_166 ( struct V_4 * V_242 , struct V_4 * V_245 )
{
if ( ( V_242 -> V_14 == V_35 && V_245 -> V_13 == V_36 ) ||
( V_242 -> V_14 == V_36 && V_245 -> V_13 == V_35 ) ) {
if ( V_242 -> V_212 < V_243 )
return 1 ;
return 0 ;
}
if ( V_242 -> V_212 < V_245 -> V_13 && ! F_156 ( V_242 , V_245 ) )
return 1 ;
return 0 ;
}
static void F_167 ( struct V_16 * V_17 , struct V_132 * V_134 ,
struct V_4 * V_5 )
{
struct V_4 * V_242 ;
F_7 (gr, head, lkb_statequeue) {
if ( V_242 == V_5 )
continue;
if ( V_242 -> V_244 && F_166 ( V_242 , V_5 ) ) {
F_32 ( V_17 , V_242 , V_5 -> V_13 ) ;
V_242 -> V_212 = V_5 -> V_13 ;
}
}
}
static void F_168 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_167 ( V_17 , & V_17 -> V_69 , V_5 ) ;
}
static void F_169 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_167 ( V_17 , & V_17 -> V_69 , V_5 ) ;
F_167 ( V_17 , & V_17 -> V_70 , V_5 ) ;
}
static int F_170 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
struct V_25 * V_26 = V_17 -> V_65 ;
int V_157 , error , V_246 , V_247 , V_248 = F_63 () ;
if ( F_58 ( V_17 , V_97 ) ) {
F_56 ( V_17 , V_97 ) ;
V_17 -> V_20 = V_5 -> V_8 ;
V_5 -> V_7 = V_17 -> V_18 ;
return 0 ;
}
if ( V_17 -> V_20 && V_17 -> V_20 != V_5 -> V_8 ) {
F_95 ( & V_5 -> V_120 , & V_17 -> V_68 ) ;
return 1 ;
}
if ( V_17 -> V_18 == 0 ) {
V_5 -> V_7 = 0 ;
return 0 ;
}
if ( V_17 -> V_18 > 0 ) {
V_5 -> V_7 = V_17 -> V_18 ;
return 0 ;
}
F_20 (r->res_nodeid == -1 , dlm_dump_rsb(r);) ;
V_246 = F_62 ( V_17 ) ;
if ( V_246 != V_248 ) {
V_17 -> V_20 = V_5 -> V_8 ;
F_171 ( V_17 , V_5 ) ;
return 1 ;
}
for ( V_157 = 0 ; V_157 < 2 ; V_157 ++ ) {
error = F_172 ( V_26 , V_248 , V_17 -> V_22 ,
V_17 -> V_66 , & V_247 ) ;
if ( ! error )
break;
F_40 ( V_26 , L_34 , error , V_17 -> V_22 ) ;
F_173 () ;
}
if ( error && error != - V_90 )
return error ;
if ( V_247 == V_248 ) {
V_17 -> V_20 = 0 ;
V_17 -> V_18 = 0 ;
V_5 -> V_7 = 0 ;
} else {
V_17 -> V_20 = V_5 -> V_8 ;
V_17 -> V_18 = V_247 ;
V_5 -> V_7 = V_247 ;
}
return 0 ;
}
static void F_174 ( struct V_16 * V_17 )
{
struct V_4 * V_5 , * V_249 ;
F_161 (lkb, safe, &r->res_lookup, lkb_rsb_lookup) {
F_111 ( & V_5 -> V_120 ) ;
F_175 ( V_17 , V_5 ) ;
F_173 () ;
}
}
static void F_176 ( struct V_16 * V_17 , int error )
{
struct V_4 * V_5 ;
if ( ! V_17 -> V_20 )
return;
switch ( error ) {
case 0 :
case - V_250 :
V_17 -> V_20 = 0 ;
F_174 ( V_17 ) ;
break;
case - V_62 :
case - V_83 :
case - V_85 :
V_17 -> V_20 = 0 ;
if ( ! F_6 ( & V_17 -> V_68 ) ) {
V_5 = F_154 ( V_17 -> V_68 . V_218 , struct V_4 ,
V_120 ) ;
F_111 ( & V_5 -> V_120 ) ;
V_17 -> V_20 = V_5 -> V_8 ;
F_175 ( V_17 , V_5 ) ;
}
break;
default:
F_81 ( V_17 -> V_65 , L_35 , error ) ;
}
}
static int F_177 ( int V_135 , struct V_251 * V_252 , T_1 V_77 ,
int V_98 , unsigned long V_253 ,
void (* F_178) ( void * V_254 ) ,
void * V_254 ,
void (* F_179) ( void * V_254 , int V_135 ) ,
struct V_255 * args )
{
int V_39 = - V_101 ;
if ( V_135 < 0 || V_135 > V_243 )
goto V_95;
if ( ! ( V_77 & V_256 ) && ( V_98 > V_74 ) )
goto V_95;
if ( V_77 & V_257 )
goto V_95;
if ( V_77 & V_226 && ! ( V_77 & V_256 ) )
goto V_95;
if ( V_77 & V_231 && ! ( V_77 & V_256 ) )
goto V_95;
if ( V_77 & V_231 && V_77 & V_28 )
goto V_95;
if ( V_77 & V_225 && V_77 & V_256 )
goto V_95;
if ( V_77 & V_225 && V_77 & V_226 )
goto V_95;
if ( V_77 & V_225 && V_77 & V_28 )
goto V_95;
if ( V_77 & V_225 && V_135 != V_213 )
goto V_95;
if ( ! F_178 || ! V_252 )
goto V_95;
if ( V_77 & V_203 && ! V_252 -> V_258 )
goto V_95;
if ( V_77 & V_256 && ! V_252 -> V_259 )
goto V_95;
args -> V_77 = V_77 ;
args -> V_260 = F_178 ;
args -> V_254 = V_254 ;
args -> V_261 = F_179 ;
args -> V_262 = V_253 ;
args -> V_135 = V_135 ;
args -> V_252 = V_252 ;
V_39 = 0 ;
V_95:
return V_39 ;
}
static int F_180 ( T_1 V_77 , void * V_263 , struct V_255 * args )
{
if ( V_77 & ~ ( V_257 | V_203 | V_206 |
V_264 ) )
return - V_101 ;
if ( V_77 & V_257 && V_77 & V_264 )
return - V_101 ;
args -> V_77 = V_77 ;
args -> V_254 = V_263 ;
return 0 ;
}
static int F_181 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_255 * args )
{
int V_39 = - V_101 ;
if ( args -> V_77 & V_256 ) {
if ( V_5 -> V_11 & V_34 )
goto V_95;
if ( args -> V_77 & V_226 &&
! V_265 [ V_5 -> V_14 + 1 ] [ args -> V_135 + 1 ] )
goto V_95;
V_39 = - V_170 ;
if ( V_5 -> V_12 != V_33 )
goto V_95;
if ( V_5 -> V_15 )
goto V_95;
if ( F_27 ( V_5 ) )
goto V_95;
}
V_5 -> V_10 = args -> V_77 ;
V_5 -> V_30 = 0 ;
V_5 -> V_266 = args -> V_260 ;
V_5 -> V_267 = args -> V_254 ;
V_5 -> V_244 = args -> V_261 ;
V_5 -> V_13 = args -> V_135 ;
V_5 -> V_268 = args -> V_252 ;
V_5 -> V_131 = args -> V_252 -> V_258 ;
V_5 -> V_269 = ( int ) V_270 -> V_271 ;
V_5 -> V_197 = args -> V_262 ;
V_39 = 0 ;
V_95:
if ( V_39 )
F_40 ( V_26 , L_36 ,
V_39 , V_5 -> V_8 , V_5 -> V_11 , args -> V_77 ,
V_5 -> V_12 , V_5 -> V_15 ,
V_5 -> V_114 -> V_22 ) ;
return V_39 ;
}
static int F_182 ( struct V_4 * V_5 , struct V_255 * args )
{
struct V_25 * V_26 = V_5 -> V_114 -> V_65 ;
int V_39 = - V_101 ;
if ( V_5 -> V_11 & V_34 ) {
F_81 ( V_26 , L_37 , V_5 -> V_8 ) ;
F_2 ( V_5 ) ;
goto V_95;
}
if ( V_5 -> V_11 & V_272 ) {
F_40 ( V_26 , L_38 , V_5 -> V_8 ) ;
V_39 = - V_130 ;
goto V_95;
}
if ( ! F_6 ( & V_5 -> V_120 ) ) {
if ( args -> V_77 & ( V_257 | V_264 ) ) {
F_40 ( V_26 , L_39 , V_5 -> V_8 ) ;
F_111 ( & V_5 -> V_120 ) ;
F_28 ( V_5 -> V_114 , V_5 ,
args -> V_77 & V_257 ?
- V_40 : - V_46 ) ;
F_90 ( V_5 ) ;
}
V_39 = - V_170 ;
goto V_95;
}
if ( args -> V_77 & V_257 ) {
if ( V_5 -> V_10 & V_257 )
goto V_95;
if ( F_27 ( V_5 ) )
goto V_95;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_179 ) {
V_5 -> V_11 |= V_38 ;
V_39 = - V_170 ;
goto V_95;
}
if ( V_5 -> V_12 == V_33 &&
! V_5 -> V_15 ) {
V_39 = - V_170 ;
goto V_95;
}
switch ( V_5 -> V_15 ) {
case V_153 :
case V_145 :
V_5 -> V_11 |= V_38 ;
V_39 = - V_170 ;
goto V_95;
case V_149 :
case V_151 :
goto V_95;
}
goto V_273;
}
if ( args -> V_77 & V_264 ) {
if ( V_5 -> V_10 & V_264 )
goto V_95;
if ( F_25 ( V_5 ) )
goto V_95;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_179 ) {
V_5 -> V_11 |= V_37 ;
V_39 = - V_170 ;
goto V_95;
}
switch ( V_5 -> V_15 ) {
case V_153 :
case V_145 :
V_5 -> V_11 |= V_37 ;
V_39 = - V_170 ;
goto V_95;
case V_149 :
goto V_95;
}
goto V_273;
}
V_39 = - V_170 ;
if ( V_5 -> V_15 || V_5 -> V_171 )
goto V_95;
V_273:
V_5 -> V_10 |= args -> V_77 ;
V_5 -> V_30 = 0 ;
V_5 -> V_267 = args -> V_254 ;
V_39 = 0 ;
V_95:
if ( V_39 )
F_40 ( V_26 , L_40 , V_39 ,
V_5 -> V_8 , V_5 -> V_11 , V_5 -> V_10 ,
args -> V_77 , V_5 -> V_15 ,
V_5 -> V_114 -> V_22 ) ;
return V_39 ;
}
static int F_183 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error = 0 ;
if ( F_159 ( V_17 , V_5 , 1 , NULL ) ) {
F_147 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , 0 ) ;
goto V_95;
}
if ( F_14 ( V_5 ) ) {
error = - V_250 ;
F_93 ( V_17 , V_5 , V_140 ) ;
F_126 ( V_5 ) ;
goto V_95;
}
error = - V_62 ;
F_28 ( V_17 , V_5 , - V_62 ) ;
V_95:
return error ;
}
static void F_184 ( struct V_16 * V_17 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case - V_62 :
if ( F_15 ( V_5 ) )
F_169 ( V_17 , V_5 ) ;
break;
case - V_250 :
F_168 ( V_17 , V_5 ) ;
break;
}
}
static int F_185 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error = 0 ;
int V_240 = 0 ;
if ( F_159 ( V_17 , V_5 , 1 , & V_240 ) ) {
F_147 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , 0 ) ;
goto V_95;
}
if ( V_240 ) {
F_144 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , - V_44 ) ;
error = - V_44 ;
goto V_95;
}
if ( F_16 ( V_5 ) ) {
F_160 ( V_17 , V_117 , NULL ) ;
if ( F_158 ( V_17 , V_5 , 1 ) ) {
F_147 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , 0 ) ;
goto V_95;
}
}
if ( F_14 ( V_5 ) ) {
error = - V_250 ;
F_96 ( V_17 , V_5 ) ;
F_93 ( V_17 , V_5 , V_142 ) ;
F_126 ( V_5 ) ;
goto V_95;
}
error = - V_62 ;
F_28 ( V_17 , V_5 , - V_62 ) ;
V_95:
return error ;
}
static void F_186 ( struct V_16 * V_17 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case 0 :
F_165 ( V_17 ) ;
break;
case - V_62 :
if ( F_15 ( V_5 ) )
F_169 ( V_17 , V_5 ) ;
break;
case - V_250 :
F_168 ( V_17 , V_5 ) ;
break;
}
}
static int F_187 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
F_142 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , - V_46 ) ;
return - V_46 ;
}
static void F_188 ( struct V_16 * V_17 , struct V_4 * V_5 ,
int error )
{
F_165 ( V_17 ) ;
}
static int V_194 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error ;
error = F_144 ( V_17 , V_5 ) ;
if ( error ) {
F_28 ( V_17 , V_5 , - V_40 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_189 ( struct V_16 * V_17 , struct V_4 * V_5 ,
int error )
{
if ( error )
F_165 ( V_17 ) ;
}
static int F_175 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error ;
error = F_170 ( V_17 , V_5 ) ;
if ( error < 0 )
goto V_95;
if ( error ) {
error = 0 ;
goto V_95;
}
if ( F_19 ( V_17 ) ) {
error = F_190 ( V_17 , V_5 ) ;
} else {
error = F_183 ( V_17 , V_5 ) ;
F_184 ( V_17 , V_5 , error ) ;
}
V_95:
return error ;
}
static int F_191 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_17 ) ) {
error = F_192 ( V_17 , V_5 ) ;
} else {
error = F_185 ( V_17 , V_5 ) ;
F_186 ( V_17 , V_5 , error ) ;
}
return error ;
}
static int F_193 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_17 ) ) {
error = F_194 ( V_17 , V_5 ) ;
} else {
error = F_187 ( V_17 , V_5 ) ;
F_188 ( V_17 , V_5 , error ) ;
}
return error ;
}
static int F_131 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_17 ) ) {
error = F_195 ( V_17 , V_5 ) ;
} else {
error = V_194 ( V_17 , V_5 ) ;
F_189 ( V_17 , V_5 , error ) ;
}
return error ;
}
static int F_196 ( struct V_25 * V_26 , struct V_4 * V_5 , char * V_59 ,
int V_60 , struct V_255 * args )
{
struct V_16 * V_17 ;
int error ;
error = F_181 ( V_26 , V_5 , args ) ;
if ( error )
goto V_95;
error = F_59 ( V_26 , V_59 , V_60 , V_102 , & V_17 ) ;
if ( error )
goto V_95;
F_129 ( V_17 ) ;
F_74 ( V_17 , V_5 ) ;
V_5 -> V_268 -> V_259 = V_5 -> V_8 ;
error = F_175 ( V_17 , V_5 ) ;
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
V_95:
return error ;
}
static int F_197 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_255 * args )
{
struct V_16 * V_17 ;
int error ;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_181 ( V_26 , V_5 , args ) ;
if ( error )
goto V_95;
error = F_191 ( V_17 , V_5 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
return error ;
}
static int F_198 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_255 * args )
{
struct V_16 * V_17 ;
int error ;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_182 ( V_5 , args ) ;
if ( error )
goto V_95;
error = F_193 ( V_17 , V_5 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
return error ;
}
static int F_199 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_255 * args )
{
struct V_16 * V_17 ;
int error ;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_182 ( V_5 , args ) ;
if ( error )
goto V_95;
error = F_131 ( V_17 , V_5 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
return error ;
}
int F_200 ( T_7 * V_274 ,
int V_135 ,
struct V_251 * V_252 ,
T_1 V_77 ,
void * V_59 ,
unsigned int V_98 ,
T_1 V_275 ,
void (* F_178) ( void * V_263 ) ,
void * V_263 ,
void (* F_179) ( void * V_263 , int V_135 ) )
{
struct V_25 * V_26 ;
struct V_4 * V_5 ;
struct V_255 args ;
int error , V_276 = V_77 & V_256 ;
V_26 = F_201 ( V_274 ) ;
if ( ! V_26 )
return - V_101 ;
F_8 ( V_26 ) ;
if ( V_276 )
error = F_82 ( V_26 , V_252 -> V_259 , & V_5 ) ;
else
error = F_76 ( V_26 , & V_5 ) ;
if ( error )
goto V_95;
error = F_177 ( V_135 , V_252 , V_77 , V_98 , 0 , F_178 ,
V_263 , F_179 , & args ) ;
if ( error )
goto V_277;
if ( V_276 )
error = F_197 ( V_26 , V_5 , & args ) ;
else
error = F_196 ( V_26 , V_5 , V_59 , V_98 , & args ) ;
if ( error == - V_250 )
error = 0 ;
V_277:
if ( V_276 || error )
F_85 ( V_26 , V_5 ) ;
if ( error == - V_62 || error == - V_44 )
error = 0 ;
V_95:
F_10 ( V_26 ) ;
F_202 ( V_26 ) ;
return error ;
}
int F_203 ( T_7 * V_274 ,
T_1 V_129 ,
T_1 V_77 ,
struct V_251 * V_252 ,
void * V_263 )
{
struct V_25 * V_26 ;
struct V_4 * V_5 ;
struct V_255 args ;
int error ;
V_26 = F_201 ( V_274 ) ;
if ( ! V_26 )
return - V_101 ;
F_8 ( V_26 ) ;
error = F_82 ( V_26 , V_129 , & V_5 ) ;
if ( error )
goto V_95;
error = F_180 ( V_77 , V_263 , & args ) ;
if ( error )
goto V_277;
if ( V_77 & V_257 )
error = F_199 ( V_26 , V_5 , & args ) ;
else
error = F_198 ( V_26 , V_5 , & args ) ;
if ( error == - V_46 || error == - V_40 )
error = 0 ;
if ( error == - V_170 && ( V_77 & ( V_257 | V_264 ) ) )
error = 0 ;
V_277:
F_88 ( V_5 ) ;
V_95:
F_10 ( V_26 ) ;
F_202 ( V_26 ) ;
return error ;
}
static int F_204 ( struct V_25 * V_26 , int V_278 ,
int V_169 , int V_144 ,
struct V_174 * * V_279 ,
struct V_280 * * V_281 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
char * V_283 ;
V_282 = F_205 ( V_169 , V_278 , V_127 , & V_283 ) ;
if ( ! V_282 )
return - V_284 ;
memset ( V_283 , 0 , V_278 ) ;
V_175 = (struct V_174 * ) V_283 ;
V_175 -> V_285 . V_286 = ( V_287 | V_288 ) ;
V_175 -> V_285 . V_289 = V_26 -> V_290 ;
V_175 -> V_285 . V_291 = F_63 () ;
V_175 -> V_285 . V_292 = V_278 ;
V_175 -> V_285 . V_293 = V_294 ;
V_175 -> V_182 = V_144 ;
* V_281 = V_282 ;
* V_279 = V_175 ;
return 0 ;
}
static int F_206 ( struct V_16 * V_17 , struct V_4 * V_5 ,
int V_169 , int V_144 ,
struct V_174 * * V_279 ,
struct V_280 * * V_281 )
{
int V_278 = sizeof( struct V_174 ) ;
switch ( V_144 ) {
case V_145 :
case V_153 :
case V_295 :
V_278 += V_17 -> V_66 ;
break;
case V_147 :
case V_149 :
case V_146 :
case V_148 :
case V_214 :
if ( V_5 && V_5 -> V_131 )
V_278 += V_17 -> V_65 -> V_201 ;
break;
}
return F_204 ( V_17 -> V_65 , V_278 , V_169 , V_144 ,
V_279 , V_281 ) ;
}
static int F_207 ( struct V_280 * V_282 , struct V_174 * V_175 )
{
F_208 ( V_175 ) ;
F_209 ( V_282 ) ;
return 0 ;
}
static void F_210 ( struct V_16 * V_17 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
V_175 -> V_296 = V_5 -> V_7 ;
V_175 -> V_297 = V_5 -> V_269 ;
V_175 -> V_298 = V_5 -> V_8 ;
V_175 -> V_299 = V_5 -> V_9 ;
V_175 -> V_300 = V_5 -> V_10 ;
V_175 -> V_301 = V_5 -> V_30 ;
V_175 -> V_180 = V_5 -> V_11 ;
V_175 -> V_211 = V_5 -> V_204 ;
V_175 -> V_302 = V_5 -> V_12 ;
V_175 -> V_303 = V_5 -> V_14 ;
V_175 -> V_304 = V_5 -> V_13 ;
V_175 -> V_305 = V_17 -> V_107 ;
if ( V_5 -> V_244 )
V_175 -> V_306 |= V_48 ;
if ( V_5 -> V_266 )
V_175 -> V_306 |= V_45 ;
switch ( V_175 -> V_182 ) {
case V_145 :
case V_153 :
memcpy ( V_175 -> V_210 , V_17 -> V_22 , V_17 -> V_66 ) ;
break;
case V_147 :
case V_149 :
case V_146 :
case V_148 :
case V_214 :
if ( ! V_5 -> V_131 )
break;
memcpy ( V_175 -> V_210 , V_5 -> V_131 , V_17 -> V_65 -> V_201 ) ;
break;
}
}
static int F_211 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_144 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int V_169 , error ;
V_169 = V_17 -> V_18 ;
error = F_109 ( V_5 , V_144 , V_169 ) ;
if ( error )
return error ;
error = F_206 ( V_17 , V_5 , V_169 , V_144 , & V_175 , & V_282 ) ;
if ( error )
goto V_307;
F_210 ( V_17 , V_5 , V_175 ) ;
error = F_207 ( V_282 , V_175 ) ;
if ( error )
goto V_307;
return 0 ;
V_307:
F_112 ( V_5 , F_98 ( V_144 ) ) ;
return error ;
}
static int F_190 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
return F_211 ( V_17 , V_5 , V_145 ) ;
}
static int F_192 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
int error ;
error = F_211 ( V_17 , V_5 , V_147 ) ;
if ( ! error && F_24 ( V_5 ) ) {
F_112 ( V_5 , V_148 ) ;
V_17 -> V_65 -> V_308 . V_180 = V_181 ;
V_17 -> V_65 -> V_308 . V_182 = V_148 ;
V_17 -> V_65 -> V_308 . V_178 = 0 ;
F_212 ( V_17 , V_5 , & V_17 -> V_65 -> V_308 ) ;
}
return error ;
}
static int F_194 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
return F_211 ( V_17 , V_5 , V_149 ) ;
}
static int F_195 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
return F_211 ( V_17 , V_5 , V_151 ) ;
}
static int F_150 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int V_169 , error ;
V_169 = V_5 -> V_7 ;
error = F_206 ( V_17 , V_5 , V_169 , V_214 , & V_175 , & V_282 ) ;
if ( error )
goto V_95;
F_210 ( V_17 , V_5 , V_175 ) ;
V_175 -> V_178 = 0 ;
error = F_207 ( V_282 , V_175 ) ;
V_95:
return error ;
}
static int F_33 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_135 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int V_169 , error ;
V_169 = V_5 -> V_7 ;
error = F_206 ( V_17 , NULL , V_169 , V_309 , & V_175 , & V_282 ) ;
if ( error )
goto V_95;
F_210 ( V_17 , V_5 , V_175 ) ;
V_175 -> V_310 = V_135 ;
error = F_207 ( V_282 , V_175 ) ;
V_95:
return error ;
}
static int F_171 ( struct V_16 * V_17 , struct V_4 * V_5 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int V_169 , error ;
V_169 = F_62 ( V_17 ) ;
error = F_109 ( V_5 , V_153 , V_169 ) ;
if ( error )
return error ;
error = F_206 ( V_17 , NULL , V_169 , V_153 , & V_175 , & V_282 ) ;
if ( error )
goto V_307;
F_210 ( V_17 , V_5 , V_175 ) ;
error = F_207 ( V_282 , V_175 ) ;
if ( error )
goto V_307;
return 0 ;
V_307:
F_112 ( V_5 , V_154 ) ;
return error ;
}
static int F_115 ( struct V_16 * V_17 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int V_169 , error ;
V_169 = F_62 ( V_17 ) ;
error = F_206 ( V_17 , NULL , V_169 , V_295 , & V_175 , & V_282 ) ;
if ( error )
goto V_95;
memcpy ( V_175 -> V_210 , V_17 -> V_22 , V_17 -> V_66 ) ;
V_175 -> V_305 = V_17 -> V_107 ;
error = F_207 ( V_282 , V_175 ) ;
V_95:
return error ;
}
static int F_213 ( struct V_16 * V_17 , struct V_4 * V_5 ,
int V_144 , int V_39 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int V_169 , error ;
V_169 = V_5 -> V_7 ;
error = F_206 ( V_17 , V_5 , V_169 , V_144 , & V_175 , & V_282 ) ;
if ( error )
goto V_95;
F_210 ( V_17 , V_5 , V_175 ) ;
V_175 -> V_178 = V_39 ;
error = F_207 ( V_282 , V_175 ) ;
V_95:
return error ;
}
static int F_214 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_39 )
{
return F_213 ( V_17 , V_5 , V_146 , V_39 ) ;
}
static int F_215 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_39 )
{
return F_213 ( V_17 , V_5 , V_148 , V_39 ) ;
}
static int F_216 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_39 )
{
return F_213 ( V_17 , V_5 , V_150 , V_39 ) ;
}
static int F_217 ( struct V_16 * V_17 , struct V_4 * V_5 , int V_39 )
{
return F_213 ( V_17 , V_5 , V_152 , V_39 ) ;
}
static int F_218 ( struct V_25 * V_26 , struct V_174 * V_311 ,
int V_247 , int V_39 )
{
struct V_16 * V_17 = & V_26 -> V_312 ;
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int error , V_109 = V_311 -> V_285 . V_291 ;
error = F_206 ( V_17 , NULL , V_109 , V_154 , & V_175 , & V_282 ) ;
if ( error )
goto V_95;
V_175 -> V_298 = V_311 -> V_298 ;
V_175 -> V_178 = V_39 ;
V_175 -> V_296 = V_247 ;
error = F_207 ( V_282 , V_175 ) ;
V_95:
return error ;
}
static void F_219 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
V_5 -> V_10 = V_175 -> V_300 ;
V_5 -> V_30 = V_175 -> V_301 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_175 -> V_180 & 0x0000FFFF ) ;
}
static void F_220 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
if ( V_175 -> V_180 == V_181 )
return;
V_5 -> V_30 = V_175 -> V_301 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_175 -> V_180 & 0x0000FFFF ) ;
}
static int F_140 ( struct V_174 * V_175 )
{
return ( V_175 -> V_285 . V_292 - sizeof( struct V_174 ) ) ;
}
static int F_221 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
int V_60 ;
if ( V_5 -> V_10 & V_203 ) {
if ( ! V_5 -> V_131 )
V_5 -> V_131 = F_137 ( V_26 ) ;
if ( ! V_5 -> V_131 )
return - V_58 ;
V_60 = F_140 ( V_175 ) ;
if ( V_60 > V_74 )
V_60 = V_74 ;
memcpy ( V_5 -> V_131 , V_175 -> V_210 , V_60 ) ;
}
return 0 ;
}
static void F_222 ( void * V_254 , int V_135 )
{
F_49 ( L_41 ) ;
}
static void F_223 ( void * V_254 )
{
F_49 ( L_42 ) ;
}
static int F_224 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
V_5 -> V_7 = V_175 -> V_285 . V_291 ;
V_5 -> V_269 = V_175 -> V_297 ;
V_5 -> V_9 = V_175 -> V_298 ;
V_5 -> V_14 = V_117 ;
V_5 -> V_13 = V_175 -> V_304 ;
V_5 -> V_244 = ( V_175 -> V_306 & V_48 ) ? & F_222 : NULL ;
V_5 -> V_266 = ( V_175 -> V_306 & V_45 ) ? & F_223 : NULL ;
if ( V_5 -> V_10 & V_203 ) {
V_5 -> V_131 = F_137 ( V_26 ) ;
if ( ! V_5 -> V_131 )
return - V_58 ;
}
return 0 ;
}
static int F_225 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
if ( V_5 -> V_12 != V_33 )
return - V_170 ;
if ( F_221 ( V_26 , V_5 , V_175 ) )
return - V_58 ;
V_5 -> V_13 = V_175 -> V_304 ;
V_5 -> V_204 = V_175 -> V_211 ;
return 0 ;
}
static int F_226 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
if ( F_221 ( V_26 , V_5 , V_175 ) )
return - V_58 ;
return 0 ;
}
static void F_227 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 = & V_26 -> V_313 ;
V_5 -> V_7 = V_175 -> V_285 . V_291 ;
V_5 -> V_9 = V_175 -> V_298 ;
}
static int F_228 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
int V_314 = V_175 -> V_285 . V_291 ;
int error = 0 ;
switch ( V_175 -> V_182 ) {
case V_147 :
case V_149 :
case V_151 :
if ( ! F_22 ( V_5 ) || V_5 -> V_7 != V_314 )
error = - V_101 ;
break;
case V_148 :
case V_150 :
case V_152 :
case V_214 :
case V_309 :
if ( ! F_21 ( V_5 ) || V_5 -> V_7 != V_314 )
error = - V_101 ;
break;
case V_146 :
if ( ! F_21 ( V_5 ) )
error = - V_101 ;
else if ( V_5 -> V_7 != - 1 && V_5 -> V_7 != V_314 )
error = - V_101 ;
break;
default:
error = - V_101 ;
}
if ( error )
F_81 ( V_5 -> V_114 -> V_65 ,
L_43 ,
V_175 -> V_182 , V_314 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_11 , V_5 -> V_7 ) ;
return error ;
}
static void F_229 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error , V_98 ;
error = F_76 ( V_26 , & V_5 ) ;
if ( error )
goto V_307;
F_219 ( V_5 , V_175 ) ;
V_5 -> V_11 |= V_34 ;
error = F_224 ( V_26 , V_5 , V_175 ) ;
if ( error ) {
F_85 ( V_26 , V_5 ) ;
goto V_307;
}
V_98 = F_140 ( V_175 ) ;
error = F_59 ( V_26 , V_175 -> V_210 , V_98 , V_84 , & V_17 ) ;
if ( error ) {
F_85 ( V_26 , V_5 ) ;
goto V_307;
}
F_129 ( V_17 ) ;
F_74 ( V_17 , V_5 ) ;
error = F_183 ( V_17 , V_5 ) ;
F_214 ( V_17 , V_5 , error ) ;
F_184 ( V_17 , V_5 , error ) ;
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
if ( error == - V_250 )
error = 0 ;
if ( error )
F_88 ( V_5 ) ;
return;
V_307:
F_227 ( V_26 , V_175 ) ;
F_214 ( & V_26 -> V_312 , & V_26 -> V_313 , error ) ;
}
static void F_230 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error , V_315 = 1 ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error )
goto V_307;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
F_219 ( V_5 , V_175 ) ;
error = F_225 ( V_26 , V_5 , V_175 ) ;
if ( error ) {
F_215 ( V_17 , V_5 , error ) ;
goto V_95;
}
V_315 = ! F_24 ( V_5 ) ;
error = F_185 ( V_17 , V_5 ) ;
if ( V_315 )
F_215 ( V_17 , V_5 , error ) ;
F_186 ( V_17 , V_5 , error ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
return;
V_307:
F_227 ( V_26 , V_175 ) ;
F_215 ( & V_26 -> V_312 , & V_26 -> V_313 , error ) ;
}
static void F_231 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error )
goto V_307;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
F_219 ( V_5 , V_175 ) ;
error = F_226 ( V_26 , V_5 , V_175 ) ;
if ( error ) {
F_216 ( V_17 , V_5 , error ) ;
goto V_95;
}
error = F_187 ( V_17 , V_5 ) ;
F_216 ( V_17 , V_5 , error ) ;
F_188 ( V_17 , V_5 , error ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
return;
V_307:
F_227 ( V_26 , V_175 ) ;
F_216 ( & V_26 -> V_312 , & V_26 -> V_313 , error ) ;
}
static void F_232 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error )
goto V_307;
F_219 ( V_5 , V_175 ) ;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
error = V_194 ( V_17 , V_5 ) ;
F_217 ( V_17 , V_5 , error ) ;
F_189 ( V_17 , V_5 , error ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
return;
V_307:
F_227 ( V_26 , V_175 ) ;
F_217 ( & V_26 -> V_312 , & V_26 -> V_313 , error ) ;
}
static void F_233 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error ) {
F_40 ( V_26 , L_44 ,
V_175 -> V_285 . V_291 , V_175 -> V_299 ) ;
return;
}
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
F_220 ( V_5 , V_175 ) ;
if ( F_17 ( V_5 ) )
F_152 ( V_5 , V_175 ) ;
F_148 ( V_17 , V_5 , V_175 ) ;
F_28 ( V_17 , V_5 , 0 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
}
static void F_234 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error ) {
F_40 ( V_26 , L_45 ,
V_175 -> V_285 . V_291 , V_175 -> V_299 ) ;
return;
}
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
F_32 ( V_17 , V_5 , V_175 -> V_310 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
}
static void F_235 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
int V_60 , error , V_247 , V_246 , V_316 , V_248 ;
V_316 = V_175 -> V_285 . V_291 ;
V_248 = F_63 () ;
V_60 = F_140 ( V_175 ) ;
V_246 = F_236 ( V_26 , V_175 -> V_305 ) ;
if ( V_246 != V_248 ) {
F_81 ( V_26 , L_46 ,
V_246 , V_316 ) ;
error = - V_101 ;
V_247 = - 1 ;
goto V_95;
}
error = F_172 ( V_26 , V_316 , V_175 -> V_210 , V_60 , & V_247 ) ;
if ( ! error && V_247 == V_248 ) {
F_229 ( V_26 , V_175 ) ;
return;
}
V_95:
F_218 ( V_26 , V_175 , V_247 , error ) ;
}
static void F_237 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
int V_60 , V_246 , V_316 ;
V_316 = V_175 -> V_285 . V_291 ;
V_60 = F_140 ( V_175 ) ;
V_246 = F_236 ( V_26 , V_175 -> V_305 ) ;
if ( V_246 != F_63 () ) {
F_81 ( V_26 , L_47 ,
V_246 , V_316 ) ;
return;
}
F_116 ( V_26 , V_316 , V_175 -> V_210 , V_60 ) ;
}
static void F_238 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
F_239 ( V_26 , V_175 -> V_296 , V_175 -> V_297 ) ;
}
static void F_240 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error , V_144 , V_317 ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error ) {
F_40 ( V_26 , L_48 ,
V_175 -> V_285 . V_291 , V_175 -> V_299 ) ;
return;
}
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
V_144 = V_5 -> V_15 ;
error = F_112 ( V_5 , V_146 ) ;
if ( error )
goto V_95;
if ( V_144 == V_153 ) {
V_17 -> V_18 = V_175 -> V_285 . V_291 ;
V_5 -> V_7 = V_17 -> V_18 ;
}
V_317 = V_175 -> V_178 ;
switch ( V_317 ) {
case - V_62 :
F_28 ( V_17 , V_5 , - V_62 ) ;
F_176 ( V_17 , - V_62 ) ;
F_90 ( V_5 ) ;
break;
case - V_250 :
case 0 :
F_220 ( V_5 , V_175 ) ;
V_5 -> V_9 = V_175 -> V_298 ;
if ( F_17 ( V_5 ) )
F_152 ( V_5 , V_175 ) ;
if ( V_317 ) {
F_93 ( V_17 , V_5 , V_140 ) ;
F_126 ( V_5 ) ;
} else {
F_148 ( V_17 , V_5 , V_175 ) ;
F_28 ( V_17 , V_5 , 0 ) ;
}
F_176 ( V_17 , V_317 ) ;
break;
case - V_83 :
case - V_85 :
F_40 ( V_26 , L_49 ,
V_5 -> V_8 , V_5 -> V_11 , V_17 -> V_18 , V_317 ) ;
V_17 -> V_18 = - 1 ;
V_5 -> V_7 = - 1 ;
if ( F_27 ( V_5 ) ) {
F_31 ( V_17 , V_5 ) ;
F_176 ( V_17 , V_317 ) ;
F_90 ( V_5 ) ;
} else
F_175 ( V_17 , V_5 ) ;
break;
default:
F_81 ( V_26 , L_50 ,
V_5 -> V_8 , V_317 ) ;
}
if ( F_25 ( V_5 ) && ( V_317 == 0 || V_317 == - V_250 ) ) {
F_40 ( V_26 , L_51 ,
V_5 -> V_8 , V_317 ) ;
V_5 -> V_11 &= ~ V_37 ;
V_5 -> V_11 &= ~ V_38 ;
F_194 ( V_17 , V_5 ) ;
} else if ( F_26 ( V_5 ) && ( V_317 == - V_250 ) ) {
F_40 ( V_26 , L_52 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_37 ;
V_5 -> V_11 &= ~ V_38 ;
F_195 ( V_17 , V_5 ) ;
} else {
V_5 -> V_11 &= ~ V_38 ;
V_5 -> V_11 &= ~ V_37 ;
}
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
}
static void F_212 ( struct V_16 * V_17 , struct V_4 * V_5 ,
struct V_174 * V_175 )
{
switch ( V_175 -> V_178 ) {
case - V_62 :
F_28 ( V_17 , V_5 , - V_62 ) ;
break;
case - V_44 :
F_220 ( V_5 , V_175 ) ;
F_145 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , - V_44 ) ;
break;
case - V_250 :
F_220 ( V_5 , V_175 ) ;
if ( F_16 ( V_5 ) )
F_151 ( V_5 ) ;
F_96 ( V_17 , V_5 ) ;
F_93 ( V_17 , V_5 , V_142 ) ;
F_126 ( V_5 ) ;
break;
case 0 :
F_220 ( V_5 , V_175 ) ;
if ( F_16 ( V_5 ) )
F_151 ( V_5 ) ;
F_148 ( V_17 , V_5 , V_175 ) ;
F_28 ( V_17 , V_5 , 0 ) ;
break;
default:
F_81 ( V_17 -> V_65 , L_53 ,
V_5 -> V_8 , V_175 -> V_178 ) ;
}
}
static void F_241 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
struct V_16 * V_17 = V_5 -> V_114 ;
int error ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
error = F_113 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
F_212 ( V_17 , V_5 , V_175 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
}
static void F_242 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error ) {
F_40 ( V_26 , L_54 ,
V_175 -> V_285 . V_291 , V_175 -> V_299 ) ;
return;
}
F_241 ( V_5 , V_175 ) ;
F_88 ( V_5 ) ;
}
static void F_243 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
struct V_16 * V_17 = V_5 -> V_114 ;
int error ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
error = F_113 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
switch ( V_175 -> V_178 ) {
case - V_46 :
F_220 ( V_5 , V_175 ) ;
F_143 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , - V_46 ) ;
break;
case - V_130 :
break;
default:
F_81 ( V_17 -> V_65 , L_55 ,
V_5 -> V_8 , V_175 -> V_178 ) ;
}
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
}
static void F_244 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error ) {
F_40 ( V_26 , L_56 ,
V_175 -> V_285 . V_291 , V_175 -> V_299 ) ;
return;
}
F_243 ( V_5 , V_175 ) ;
F_88 ( V_5 ) ;
}
static void F_245 ( struct V_4 * V_5 , struct V_174 * V_175 )
{
struct V_16 * V_17 = V_5 -> V_114 ;
int error ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_228 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
error = F_113 ( V_5 , V_175 ) ;
if ( error )
goto V_95;
switch ( V_175 -> V_178 ) {
case - V_40 :
F_220 ( V_5 , V_175 ) ;
F_145 ( V_17 , V_5 ) ;
F_28 ( V_17 , V_5 , - V_40 ) ;
break;
case 0 :
break;
default:
F_81 ( V_17 -> V_65 , L_57 ,
V_5 -> V_8 , V_175 -> V_178 ) ;
}
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
}
static void F_246 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
int error ;
error = F_82 ( V_26 , V_175 -> V_299 , & V_5 ) ;
if ( error ) {
F_40 ( V_26 , L_58 ,
V_175 -> V_285 . V_291 , V_175 -> V_299 ) ;
return;
}
F_245 ( V_5 , V_175 ) ;
F_88 ( V_5 ) ;
}
static void F_247 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error , V_247 ;
error = F_82 ( V_26 , V_175 -> V_298 , & V_5 ) ;
if ( error ) {
F_81 ( V_26 , L_59 ) ;
return;
}
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_112 ( V_5 , V_154 ) ;
if ( error )
goto V_95;
V_247 = V_175 -> V_296 ;
if ( V_247 == F_63 () ) {
V_17 -> V_18 = 0 ;
V_247 = 0 ;
V_17 -> V_20 = 0 ;
} else {
V_17 -> V_18 = V_247 ;
}
if ( F_27 ( V_5 ) ) {
F_40 ( V_26 , L_60 ,
V_5 -> V_8 , V_5 -> V_11 ) ;
F_31 ( V_17 , V_5 ) ;
F_90 ( V_5 ) ;
goto V_318;
}
F_175 ( V_17 , V_5 ) ;
V_318:
if ( ! V_247 )
F_174 ( V_17 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
}
static void F_248 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
if ( ! F_249 ( V_26 , V_175 -> V_285 . V_291 ) ) {
F_40 ( V_26 , L_61 ,
V_175 -> V_182 , V_175 -> V_285 . V_291 , V_175 -> V_298 ,
V_175 -> V_299 , V_175 -> V_178 ) ;
return;
}
switch ( V_175 -> V_182 ) {
case V_145 :
F_229 ( V_26 , V_175 ) ;
break;
case V_147 :
F_230 ( V_26 , V_175 ) ;
break;
case V_149 :
F_231 ( V_26 , V_175 ) ;
break;
case V_151 :
F_232 ( V_26 , V_175 ) ;
break;
case V_146 :
F_240 ( V_26 , V_175 ) ;
break;
case V_148 :
F_242 ( V_26 , V_175 ) ;
break;
case V_150 :
F_244 ( V_26 , V_175 ) ;
break;
case V_152 :
F_246 ( V_26 , V_175 ) ;
break;
case V_214 :
F_233 ( V_26 , V_175 ) ;
break;
case V_309 :
F_234 ( V_26 , V_175 ) ;
break;
case V_153 :
F_235 ( V_26 , V_175 ) ;
break;
case V_295 :
F_237 ( V_26 , V_175 ) ;
break;
case V_154 :
F_247 ( V_26 , V_175 ) ;
break;
case V_319 :
F_238 ( V_26 , V_175 ) ;
break;
default:
F_81 ( V_26 , L_62 , V_175 -> V_182 ) ;
}
}
static void F_250 ( struct V_25 * V_26 , struct V_174 * V_175 ,
int V_109 )
{
if ( F_124 ( V_26 ) ) {
F_251 ( V_26 , V_109 , V_175 ) ;
} else {
F_252 ( V_26 ) ;
F_248 ( V_26 , V_175 ) ;
}
}
void F_253 ( struct V_25 * V_26 , struct V_174 * V_175 )
{
F_248 ( V_26 , V_175 ) ;
}
void F_254 ( union V_320 * V_321 , int V_109 )
{
struct V_322 * V_323 = & V_321 -> V_324 ;
struct V_25 * V_26 ;
int type = 0 ;
switch ( V_323 -> V_293 ) {
case V_294 :
F_255 ( & V_321 -> V_325 ) ;
type = V_321 -> V_325 . V_182 ;
break;
case V_326 :
F_256 ( & V_321 -> V_327 ) ;
type = V_321 -> V_327 . V_328 ;
break;
default:
F_49 ( L_63 , V_323 -> V_293 , V_109 ) ;
return;
}
if ( V_323 -> V_291 != V_109 ) {
F_49 ( L_64 ,
V_323 -> V_291 , V_109 , V_323 -> V_289 ) ;
return;
}
V_26 = F_257 ( V_323 -> V_289 ) ;
if ( ! V_26 ) {
if ( V_54 . V_329 )
F_49 ( L_65 ,
V_323 -> V_289 , V_109 , V_323 -> V_293 , type ) ;
if ( V_323 -> V_293 == V_326 && type == V_330 )
F_258 ( V_109 , & V_321 -> V_327 ) ;
return;
}
F_9 ( & V_26 -> V_331 ) ;
if ( V_323 -> V_293 == V_294 )
F_250 ( V_26 , & V_321 -> V_325 , V_109 ) ;
else
F_259 ( V_26 , & V_321 -> V_327 , V_109 ) ;
F_11 ( & V_26 -> V_331 ) ;
F_202 ( V_26 ) ;
}
static void F_260 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_174 * V_332 )
{
if ( F_23 ( V_5 ) ) {
F_89 ( V_5 ) ;
memset ( V_332 , 0 , sizeof( struct V_174 ) ) ;
V_332 -> V_180 = V_181 ;
V_332 -> V_182 = V_148 ;
V_332 -> V_178 = - V_250 ;
V_332 -> V_285 . V_291 = V_5 -> V_7 ;
F_241 ( V_5 , V_332 ) ;
V_5 -> V_14 = V_117 ;
F_57 ( V_5 -> V_114 , V_333 ) ;
F_90 ( V_5 ) ;
} else if ( V_5 -> V_13 >= V_5 -> V_14 ) {
V_5 -> V_11 |= V_179 ;
}
}
static int F_261 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
if ( F_262 ( V_26 , V_5 -> V_7 ) )
return 1 ;
if ( ! F_55 ( V_26 ) )
return 0 ;
if ( F_62 ( V_5 -> V_114 ) != V_5 -> V_7 )
return 1 ;
return 0 ;
}
void F_263 ( struct V_25 * V_26 )
{
struct V_4 * V_5 , * V_249 ;
struct V_174 * V_332 ;
int V_334 , V_335 , V_336 ;
V_332 = F_264 ( sizeof( struct V_174 ) , V_167 ) ;
if ( ! V_332 ) {
F_81 ( V_26 , L_66 ) ;
return;
}
F_102 ( & V_26 -> V_164 ) ;
F_161 (lkb, safe, &ls->ls_waiters, lkb_wait_reply) {
if ( V_5 -> V_15 != V_149 ) {
F_40 ( V_26 , L_67
L_68 , V_5 -> V_8 , V_5 -> V_7 ,
V_5 -> V_15 , V_5 -> V_168 ) ;
}
if ( V_5 -> V_15 == V_153 ) {
V_5 -> V_11 |= V_179 ;
continue;
}
if ( ! F_261 ( V_26 , V_5 ) )
continue;
V_334 = V_5 -> V_15 ;
V_335 = - V_46 ;
V_336 = - V_40 ;
if ( ! V_334 ) {
if ( F_26 ( V_5 ) ) {
V_334 = V_151 ;
if ( V_5 -> V_14 == V_117 )
V_336 = 0 ;
}
if ( F_25 ( V_5 ) ) {
V_334 = V_149 ;
if ( V_5 -> V_14 == V_117 )
V_335 = - V_130 ;
}
F_40 ( V_26 , L_69 ,
V_5 -> V_8 , V_5 -> V_11 , V_334 ,
V_336 , V_335 ) ;
}
switch ( V_334 ) {
case V_145 :
V_5 -> V_11 |= V_179 ;
break;
case V_147 :
F_260 ( V_26 , V_5 , V_332 ) ;
break;
case V_149 :
F_89 ( V_5 ) ;
memset ( V_332 , 0 , sizeof( struct V_174 ) ) ;
V_332 -> V_180 = V_181 ;
V_332 -> V_182 = V_150 ;
V_332 -> V_178 = V_335 ;
V_332 -> V_285 . V_291 = V_5 -> V_7 ;
F_243 ( V_5 , V_332 ) ;
F_88 ( V_5 ) ;
break;
case V_151 :
F_89 ( V_5 ) ;
memset ( V_332 , 0 , sizeof( struct V_174 ) ) ;
V_332 -> V_180 = V_181 ;
V_332 -> V_182 = V_152 ;
V_332 -> V_178 = V_336 ;
V_332 -> V_285 . V_291 = V_5 -> V_7 ;
F_245 ( V_5 , V_332 ) ;
F_88 ( V_5 ) ;
break;
default:
F_81 ( V_26 , L_70 ,
V_5 -> V_15 , V_334 ) ;
}
F_173 () ;
}
F_107 ( & V_26 -> V_164 ) ;
F_108 ( V_332 ) ;
}
static struct V_4 * F_265 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
int V_82 = 0 ;
F_102 ( & V_26 -> V_164 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( V_5 -> V_11 & V_179 ) {
F_89 ( V_5 ) ;
V_82 = 1 ;
break;
}
}
F_107 ( & V_26 -> V_164 ) ;
if ( ! V_82 )
V_5 = NULL ;
return V_5 ;
}
int F_266 ( struct V_25 * V_26 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 ;
int error = 0 , V_144 , V_228 , V_337 , V_338 ;
while ( 1 ) {
if ( F_124 ( V_26 ) ) {
F_40 ( V_26 , L_71 ) ;
error = - V_339 ;
break;
}
V_5 = F_265 ( V_26 ) ;
if ( ! V_5 )
break;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
V_144 = V_5 -> V_15 ;
V_337 = F_26 ( V_5 ) ;
V_338 = F_25 ( V_5 ) ;
V_228 = 0 ;
F_40 ( V_26 , L_72 ,
V_5 -> V_8 , V_5 -> V_7 , V_144 , V_17 -> V_18 ) ;
V_5 -> V_11 &= ~ V_179 ;
V_5 -> V_11 &= ~ V_37 ;
V_5 -> V_11 &= ~ V_38 ;
V_5 -> V_15 = 0 ;
V_5 -> V_171 = 0 ;
F_102 ( & V_26 -> V_164 ) ;
F_111 ( & V_5 -> V_172 ) ;
F_107 ( & V_26 -> V_164 ) ;
F_90 ( V_5 ) ;
if ( V_337 || V_338 ) {
switch ( V_144 ) {
case V_153 :
case V_145 :
F_28 ( V_17 , V_5 , V_338 ? - V_46 :
- V_40 ) ;
F_90 ( V_5 ) ;
break;
case V_147 :
if ( V_337 ) {
F_28 ( V_17 , V_5 , - V_40 ) ;
} else {
V_5 -> V_10 |= V_264 ;
F_193 ( V_17 , V_5 ) ;
}
break;
default:
V_228 = 1 ;
}
} else {
switch ( V_144 ) {
case V_153 :
case V_145 :
F_175 ( V_17 , V_5 ) ;
if ( F_121 ( V_17 ) )
F_176 ( V_17 , 0 ) ;
break;
case V_147 :
F_191 ( V_17 , V_5 ) ;
break;
default:
V_228 = 1 ;
}
}
if ( V_228 )
F_81 ( V_26 , L_73 ,
V_5 -> V_8 , V_144 , V_5 -> V_11 , V_337 , V_338 ) ;
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
}
return error ;
}
static void F_267 ( struct V_16 * V_17 , struct V_132 * V_340 ,
int (* F_268)( struct V_25 * V_26 , struct V_4 * V_5 ) )
{
struct V_25 * V_26 = V_17 -> V_65 ;
struct V_4 * V_5 , * V_249 ;
F_161 (lkb, safe, queue, lkb_statequeue) {
if ( F_268 ( V_26 , V_5 ) ) {
F_57 ( V_17 , V_341 ) ;
F_96 ( V_17 , V_5 ) ;
if ( ! F_88 ( V_5 ) )
F_81 ( V_26 , L_74 ) ;
}
}
}
static int F_269 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
return ( F_22 ( V_5 ) && F_262 ( V_26 , V_5 -> V_7 ) ) ;
}
static int F_270 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
return F_22 ( V_5 ) ;
}
static void F_271 ( struct V_16 * V_17 )
{
F_267 ( V_17 , & V_17 -> V_69 , & F_269 ) ;
F_267 ( V_17 , & V_17 -> V_70 , & F_269 ) ;
F_267 ( V_17 , & V_17 -> V_71 , & F_269 ) ;
}
void F_272 ( struct V_16 * V_17 )
{
F_267 ( V_17 , & V_17 -> V_69 , & F_270 ) ;
F_267 ( V_17 , & V_17 -> V_70 , & F_270 ) ;
F_267 ( V_17 , & V_17 -> V_71 , & F_270 ) ;
}
int F_273 ( struct V_25 * V_26 )
{
struct V_16 * V_17 ;
F_40 ( V_26 , L_75 ) ;
F_274 ( & V_26 -> V_342 ) ;
F_7 (r, &ls->ls_root_list, res_root_list) {
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
if ( F_121 ( V_17 ) )
F_271 ( V_17 ) ;
F_132 ( V_17 ) ;
F_72 ( V_17 ) ;
F_173 () ;
}
F_275 ( & V_26 -> V_342 ) ;
return 0 ;
}
static struct V_16 * F_276 ( struct V_25 * V_26 , int V_100 )
{
struct V_64 * V_183 ;
struct V_16 * V_17 , * V_61 = NULL ;
F_35 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
for ( V_183 = F_118 ( & V_26 -> V_92 [ V_100 ] . V_93 ) ; V_183 ; V_183 = F_119 ( V_183 ) ) {
V_17 = F_47 ( V_183 , struct V_16 , V_63 ) ;
if ( ! F_58 ( V_17 , V_341 ) )
continue;
F_64 ( V_17 ) ;
F_56 ( V_17 , V_341 ) ;
V_61 = V_17 ;
break;
}
F_36 ( & V_26 -> V_92 [ V_100 ] . V_105 ) ;
return V_61 ;
}
void F_277 ( struct V_25 * V_26 )
{
struct V_16 * V_17 ;
int V_100 = 0 ;
while ( 1 ) {
V_17 = F_276 ( V_26 , V_100 ) ;
if ( ! V_17 ) {
if ( V_100 == V_26 -> V_103 - 1 )
break;
V_100 ++ ;
continue;
}
F_129 ( V_17 ) ;
if ( F_121 ( V_17 ) ) {
F_165 ( V_17 ) ;
F_176 ( V_17 , 0 ) ;
}
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_173 () ;
}
}
static struct V_4 * F_278 ( struct V_132 * V_134 , int V_109 ,
T_1 V_343 )
{
struct V_4 * V_5 ;
F_7 (lkb, head, lkb_statequeue) {
if ( V_5 -> V_7 == V_109 && V_5 -> V_9 == V_343 )
return V_5 ;
}
return NULL ;
}
static struct V_4 * F_279 ( struct V_16 * V_17 , int V_109 ,
T_1 V_343 )
{
struct V_4 * V_5 ;
V_5 = F_278 ( & V_17 -> V_69 , V_109 , V_343 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_278 ( & V_17 -> V_70 , V_109 , V_343 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_278 ( & V_17 -> V_71 , V_109 , V_343 ) ;
if ( V_5 )
return V_5 ;
return NULL ;
}
static int F_280 ( struct V_25 * V_26 , struct V_4 * V_5 ,
struct V_16 * V_17 , struct V_344 * V_79 )
{
struct V_345 * V_346 = (struct V_345 * ) V_79 -> V_347 ;
V_5 -> V_7 = V_79 -> V_348 . V_291 ;
V_5 -> V_269 = F_281 ( V_346 -> V_349 ) ;
V_5 -> V_9 = F_281 ( V_346 -> V_350 ) ;
V_5 -> V_10 = F_281 ( V_346 -> V_351 ) ;
V_5 -> V_11 = F_281 ( V_346 -> V_352 ) & 0x0000FFFF ;
V_5 -> V_11 |= V_34 ;
V_5 -> V_204 = F_281 ( V_346 -> V_353 ) ;
V_5 -> V_13 = V_346 -> V_354 ;
V_5 -> V_14 = V_346 -> V_355 ;
V_5 -> V_244 = ( V_346 -> V_356 & V_48 ) ? & F_222 : NULL ;
V_5 -> V_266 = ( V_346 -> V_356 & V_45 ) ? & F_223 : NULL ;
if ( V_5 -> V_10 & V_203 ) {
int V_357 = V_79 -> V_348 . V_292 - sizeof( struct V_344 ) -
sizeof( struct V_345 ) ;
if ( V_357 > V_26 -> V_201 )
return - V_101 ;
V_5 -> V_131 = F_137 ( V_26 ) ;
if ( ! V_5 -> V_131 )
return - V_58 ;
memcpy ( V_5 -> V_131 , V_346 -> V_358 , V_357 ) ;
}
if ( V_346 -> V_359 == F_282 ( V_147 ) &&
F_23 ( V_5 ) ) {
V_346 -> V_360 = V_142 ;
V_5 -> V_14 = V_117 ;
F_57 ( V_17 , V_333 ) ;
}
return 0 ;
}
int F_283 ( struct V_25 * V_26 , struct V_344 * V_79 )
{
struct V_345 * V_346 = (struct V_345 * ) V_79 -> V_347 ;
struct V_16 * V_17 ;
struct V_4 * V_5 ;
int error ;
if ( V_346 -> V_361 ) {
error = - V_362 ;
goto V_95;
}
error = F_59 ( V_26 , V_346 -> V_363 , F_284 ( V_346 -> V_364 ) ,
V_84 , & V_17 ) ;
if ( error )
goto V_95;
F_129 ( V_17 ) ;
V_5 = F_279 ( V_17 , V_79 -> V_348 . V_291 , F_281 ( V_346 -> V_350 ) ) ;
if ( V_5 ) {
error = - V_90 ;
goto V_365;
}
error = F_76 ( V_26 , & V_5 ) ;
if ( error )
goto V_106;
error = F_280 ( V_26 , V_5 , V_17 , V_79 ) ;
if ( error ) {
F_85 ( V_26 , V_5 ) ;
goto V_106;
}
F_74 ( V_17 , V_5 ) ;
F_93 ( V_17 , V_5 , V_346 -> V_360 ) ;
error = 0 ;
V_365:
V_346 -> V_366 = F_285 ( V_5 -> V_8 ) ;
V_106:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
V_95:
if ( error )
F_40 ( V_26 , L_76 , error ,
F_281 ( V_346 -> V_350 ) ) ;
V_346 -> V_367 = F_285 ( error ) ;
return error ;
}
int F_286 ( struct V_25 * V_26 , struct V_344 * V_79 )
{
struct V_345 * V_346 = (struct V_345 * ) V_79 -> V_347 ;
struct V_16 * V_17 ;
struct V_4 * V_5 ;
int error ;
error = F_82 ( V_26 , F_281 ( V_346 -> V_350 ) , & V_5 ) ;
if ( error ) {
F_81 ( V_26 , L_77 ,
F_281 ( V_346 -> V_350 ) ) ;
return error ;
}
F_20 (is_process_copy(lkb), dlm_print_lkb(lkb);) ;
error = F_281 ( V_346 -> V_367 ) ;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
switch ( error ) {
case - V_83 :
F_40 ( V_26 , L_78 , V_5 -> V_8 ,
( unsigned long ) V_17 , V_17 -> V_22 ) ;
F_287 ( V_17 , V_5 ) ;
goto V_95;
case - V_90 :
F_40 ( V_26 , L_79 , V_5 -> V_8 ) ;
case 0 :
V_5 -> V_9 = F_281 ( V_346 -> V_366 ) ;
break;
default:
F_81 ( V_26 , L_80 ,
error , V_5 -> V_8 ) ;
}
F_288 ( V_17 ) ;
V_95:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
F_88 ( V_5 ) ;
return 0 ;
}
int F_289 ( struct V_25 * V_26 , struct V_368 * V_369 ,
int V_135 , T_1 V_77 , void * V_59 , unsigned int V_98 ,
unsigned long V_253 )
{
struct V_4 * V_5 ;
struct V_255 args ;
int error ;
F_8 ( V_26 ) ;
error = F_76 ( V_26 , & V_5 ) ;
if ( error ) {
F_108 ( V_369 ) ;
goto V_95;
}
if ( V_77 & V_203 ) {
V_369 -> V_252 . V_258 = F_106 ( V_370 , V_127 ) ;
if ( ! V_369 -> V_252 . V_258 ) {
F_108 ( V_369 ) ;
F_85 ( V_26 , V_5 ) ;
error = - V_58 ;
goto V_95;
}
}
error = F_177 ( V_135 , & V_369 -> V_252 , V_77 , V_98 , V_253 ,
F_223 , V_369 , F_222 , & args ) ;
V_5 -> V_11 |= V_371 ;
if ( error ) {
F_85 ( V_26 , V_5 ) ;
goto V_95;
}
error = F_196 ( V_26 , V_5 , V_59 , V_98 , & args ) ;
switch ( error ) {
case 0 :
break;
case - V_250 :
error = 0 ;
break;
case - V_62 :
error = 0 ;
default:
F_85 ( V_26 , V_5 ) ;
goto V_95;
}
F_35 ( & V_369 -> V_372 -> V_373 ) ;
F_89 ( V_5 ) ;
F_95 ( & V_5 -> V_119 , & V_369 -> V_372 -> V_374 ) ;
F_36 ( & V_369 -> V_372 -> V_373 ) ;
V_95:
F_10 ( V_26 ) ;
return error ;
}
int F_290 ( struct V_25 * V_26 , struct V_368 * V_375 ,
int V_135 , T_1 V_77 , T_1 V_129 , char * V_376 ,
unsigned long V_253 )
{
struct V_4 * V_5 ;
struct V_255 args ;
struct V_368 * V_369 ;
int error ;
F_8 ( V_26 ) ;
error = F_82 ( V_26 , V_129 , & V_5 ) ;
if ( error )
goto V_95;
V_369 = V_5 -> V_377 ;
if ( V_77 & V_203 && ! V_369 -> V_252 . V_258 ) {
V_369 -> V_252 . V_258 = F_106 ( V_370 , V_127 ) ;
if ( ! V_369 -> V_252 . V_258 ) {
error = - V_58 ;
goto V_277;
}
}
if ( V_376 && V_369 -> V_252 . V_258 )
memcpy ( V_369 -> V_252 . V_258 , V_376 , V_370 ) ;
V_369 -> V_378 = V_375 -> V_378 ;
V_369 -> V_379 = V_375 -> V_379 ;
V_369 -> V_380 = V_375 -> V_380 ;
V_369 -> V_381 = V_375 -> V_381 ;
V_369 -> V_382 = V_375 -> V_382 ;
V_369 -> V_383 = V_375 -> V_383 ;
error = F_177 ( V_135 , & V_369 -> V_252 , V_77 , 0 , V_253 ,
F_223 , V_369 , F_222 , & args ) ;
if ( error )
goto V_277;
error = F_197 ( V_26 , V_5 , & args ) ;
if ( error == - V_250 || error == - V_62 || error == - V_44 )
error = 0 ;
V_277:
F_88 ( V_5 ) ;
V_95:
F_10 ( V_26 ) ;
F_108 ( V_375 ) ;
return error ;
}
int F_291 ( struct V_25 * V_26 , struct V_368 * V_375 ,
T_1 V_77 , T_1 V_129 , char * V_376 )
{
struct V_4 * V_5 ;
struct V_255 args ;
struct V_368 * V_369 ;
int error ;
F_8 ( V_26 ) ;
error = F_82 ( V_26 , V_129 , & V_5 ) ;
if ( error )
goto V_95;
V_369 = V_5 -> V_377 ;
if ( V_376 && V_369 -> V_252 . V_258 )
memcpy ( V_369 -> V_252 . V_258 , V_376 , V_370 ) ;
if ( V_375 -> V_379 )
V_369 -> V_379 = V_375 -> V_379 ;
V_369 -> V_383 = V_375 -> V_383 ;
error = F_180 ( V_77 , V_369 , & args ) ;
if ( error )
goto V_277;
error = F_198 ( V_26 , V_5 , & args ) ;
if ( error == - V_46 )
error = 0 ;
if ( error == - V_170 && ( V_77 & V_264 ) )
error = 0 ;
if ( error )
goto V_277;
F_35 ( & V_369 -> V_372 -> V_373 ) ;
if ( ! F_6 ( & V_5 -> V_119 ) )
F_292 ( & V_5 -> V_119 , & V_369 -> V_372 -> V_384 ) ;
F_36 ( & V_369 -> V_372 -> V_373 ) ;
V_277:
F_88 ( V_5 ) ;
V_95:
F_10 ( V_26 ) ;
F_108 ( V_375 ) ;
return error ;
}
int F_293 ( struct V_25 * V_26 , struct V_368 * V_375 ,
T_1 V_77 , T_1 V_129 )
{
struct V_4 * V_5 ;
struct V_255 args ;
struct V_368 * V_369 ;
int error ;
F_8 ( V_26 ) ;
error = F_82 ( V_26 , V_129 , & V_5 ) ;
if ( error )
goto V_95;
V_369 = V_5 -> V_377 ;
if ( V_375 -> V_379 )
V_369 -> V_379 = V_375 -> V_379 ;
V_369 -> V_383 = V_375 -> V_383 ;
error = F_180 ( V_77 , V_369 , & args ) ;
if ( error )
goto V_277;
error = F_199 ( V_26 , V_5 , & args ) ;
if ( error == - V_40 )
error = 0 ;
if ( error == - V_170 )
error = 0 ;
V_277:
F_88 ( V_5 ) ;
V_95:
F_10 ( V_26 ) ;
F_108 ( V_375 ) ;
return error ;
}
int F_294 ( struct V_25 * V_26 , T_1 V_77 , T_1 V_129 )
{
struct V_4 * V_5 ;
struct V_255 args ;
struct V_368 * V_369 ;
struct V_16 * V_17 ;
int error ;
F_8 ( V_26 ) ;
error = F_82 ( V_26 , V_129 , & V_5 ) ;
if ( error )
goto V_95;
V_369 = V_5 -> V_377 ;
error = F_180 ( V_77 , V_369 , & args ) ;
if ( error )
goto V_277;
V_17 = V_5 -> V_114 ;
F_64 ( V_17 ) ;
F_129 ( V_17 ) ;
error = F_182 ( V_5 , & args ) ;
if ( error )
goto V_385;
V_5 -> V_11 |= V_43 ;
error = F_131 ( V_17 , V_5 ) ;
V_385:
F_132 ( V_17 ) ;
F_69 ( V_17 ) ;
if ( error == - V_40 )
error = 0 ;
if ( error == - V_170 )
error = 0 ;
V_277:
F_88 ( V_5 ) ;
V_95:
F_10 ( V_26 ) ;
return error ;
}
static int F_295 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
struct V_255 args ;
int error ;
F_89 ( V_5 ) ;
F_102 ( & V_26 -> V_386 ) ;
F_95 ( & V_5 -> V_119 , & V_26 -> V_387 ) ;
F_107 ( & V_26 -> V_386 ) ;
F_180 ( 0 , V_5 -> V_377 , & args ) ;
error = F_199 ( V_26 , V_5 , & args ) ;
if ( error == - V_40 )
error = 0 ;
return error ;
}
static int F_296 ( struct V_25 * V_26 , struct V_4 * V_5 )
{
struct V_255 args ;
int error ;
F_180 ( V_264 , V_5 -> V_377 , & args ) ;
error = F_198 ( V_26 , V_5 , & args ) ;
if ( error == - V_46 )
error = 0 ;
return error ;
}
static struct V_4 * F_297 ( struct V_25 * V_26 ,
struct V_388 * V_372 )
{
struct V_4 * V_5 = NULL ;
F_102 ( & V_26 -> V_389 ) ;
if ( F_6 ( & V_372 -> V_374 ) )
goto V_95;
V_5 = F_154 ( V_372 -> V_374 . V_218 , struct V_4 , V_119 ) ;
F_111 ( & V_5 -> V_119 ) ;
if ( V_5 -> V_10 & V_390 )
V_5 -> V_11 |= V_391 ;
else
V_5 -> V_11 |= V_392 ;
V_95:
F_107 ( & V_26 -> V_389 ) ;
return V_5 ;
}
void F_298 ( struct V_25 * V_26 , struct V_388 * V_372 )
{
struct V_4 * V_5 , * V_249 ;
F_8 ( V_26 ) ;
while ( 1 ) {
V_5 = F_297 ( V_26 , V_372 ) ;
if ( ! V_5 )
break;
F_29 ( V_5 ) ;
if ( V_5 -> V_10 & V_390 )
F_295 ( V_26 , V_5 ) ;
else
F_296 ( V_26 , V_5 ) ;
F_88 ( V_5 ) ;
}
F_102 ( & V_26 -> V_389 ) ;
F_161 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_111 ( & V_5 -> V_119 ) ;
V_5 -> V_11 |= V_392 ;
F_88 ( V_5 ) ;
}
F_161 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_393 , 0 ,
sizeof( struct V_394 ) * V_395 ) ;
F_111 ( & V_5 -> V_122 ) ;
F_88 ( V_5 ) ;
}
F_107 ( & V_26 -> V_389 ) ;
F_10 ( V_26 ) ;
}
static void F_299 ( struct V_25 * V_26 , struct V_388 * V_372 )
{
struct V_4 * V_5 , * V_249 ;
while ( 1 ) {
V_5 = NULL ;
F_35 ( & V_372 -> V_373 ) ;
if ( ! F_6 ( & V_372 -> V_374 ) ) {
V_5 = F_154 ( V_372 -> V_374 . V_218 , struct V_4 ,
V_119 ) ;
F_111 ( & V_5 -> V_119 ) ;
}
F_36 ( & V_372 -> V_373 ) ;
if ( ! V_5 )
break;
V_5 -> V_11 |= V_392 ;
F_296 ( V_26 , V_5 ) ;
F_88 ( V_5 ) ;
}
F_35 ( & V_372 -> V_373 ) ;
F_161 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_111 ( & V_5 -> V_119 ) ;
V_5 -> V_11 |= V_392 ;
F_88 ( V_5 ) ;
}
F_36 ( & V_372 -> V_373 ) ;
F_35 ( & V_372 -> V_396 ) ;
F_161 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_393 , 0 ,
sizeof( struct V_394 ) * V_395 ) ;
F_111 ( & V_5 -> V_122 ) ;
F_88 ( V_5 ) ;
}
F_36 ( & V_372 -> V_396 ) ;
}
static void F_239 ( struct V_25 * V_26 , int V_109 , int V_271 )
{
struct V_4 * V_5 , * V_249 ;
F_102 ( & V_26 -> V_386 ) ;
F_161 (lkb, safe, &ls->ls_orphans, lkb_ownqueue) {
if ( V_271 && V_5 -> V_269 != V_271 )
continue;
F_296 ( V_26 , V_5 ) ;
F_111 ( & V_5 -> V_119 ) ;
F_88 ( V_5 ) ;
}
F_107 ( & V_26 -> V_386 ) ;
}
static int F_300 ( struct V_25 * V_26 , int V_109 , int V_271 )
{
struct V_174 * V_175 ;
struct V_280 * V_282 ;
int error ;
error = F_204 ( V_26 , sizeof( struct V_174 ) , V_109 ,
V_319 , & V_175 , & V_282 ) ;
if ( error )
return error ;
V_175 -> V_296 = V_109 ;
V_175 -> V_297 = V_271 ;
return F_207 ( V_282 , V_175 ) ;
}
int F_301 ( struct V_25 * V_26 , struct V_388 * V_372 ,
int V_109 , int V_271 )
{
int error = 0 ;
if ( V_109 != F_63 () ) {
error = F_300 ( V_26 , V_109 , V_271 ) ;
} else {
F_8 ( V_26 ) ;
if ( V_271 == V_270 -> V_271 )
F_299 ( V_26 , V_372 ) ;
else
F_239 ( V_26 , V_109 , V_271 ) ;
F_10 ( V_26 ) ;
}
return error ;
}
