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
F_3 ( V_6 L_3
L_4 ,
V_19 -> V_20 , V_19 -> V_21 , V_19 -> V_22 ,
V_19 -> V_23 , V_19 -> V_24 , V_19 -> V_25 ,
V_19 -> V_26 ) ;
}
void F_5 ( struct V_18 * V_19 )
{
struct V_4 * V_5 ;
F_4 ( V_19 ) ;
F_3 ( V_6 L_5 ,
F_6 ( & V_19 -> V_27 ) , F_6 ( & V_19 -> V_28 ) ) ;
F_3 ( V_6 L_6 ) ;
F_7 (lkb, &r->res_lookup, lkb_rsb_lookup)
F_2 ( V_5 ) ;
F_3 ( V_6 L_7 ) ;
F_7 (lkb, &r->res_grantqueue, lkb_statequeue)
F_2 ( V_5 ) ;
F_3 ( V_6 L_8 ) ;
F_7 (lkb, &r->res_convertqueue, lkb_statequeue)
F_2 ( V_5 ) ;
F_3 ( V_6 L_9 ) ;
F_7 (lkb, &r->res_waitqueue, lkb_statequeue)
F_2 ( V_5 ) ;
}
static inline void F_8 ( struct V_29 * V_30 )
{
F_9 ( & V_30 -> V_31 ) ;
}
void F_10 ( struct V_29 * V_30 )
{
F_11 ( & V_30 -> V_31 ) ;
}
int F_12 ( struct V_29 * V_30 )
{
return F_13 ( & V_30 -> V_31 ) ;
}
static inline int F_14 ( struct V_4 * V_5 )
{
return ! ( V_5 -> V_10 & V_32 ) ;
}
static inline int F_15 ( struct V_4 * V_5 )
{
return ( V_5 -> V_10 & V_33 ) ;
}
static inline int F_16 ( struct V_4 * V_5 )
{
return ( V_5 -> V_34 & V_35 ) ;
}
static inline int F_17 ( struct V_4 * V_5 )
{
return ( V_5 -> V_34 & V_36 ) ;
}
static inline int F_18 ( struct V_4 * V_5 )
{
return ( V_5 -> V_12 == V_37 ) ;
}
static inline int F_19 ( struct V_18 * V_19 )
{
F_20 (r->res_nodeid >= 0 , dlm_print_rsb(r);) ;
return ! ! V_19 -> V_20 ;
}
static inline int F_21 ( struct V_4 * V_5 )
{
return ( V_5 -> V_7 && ! ( V_5 -> V_11 & V_38 ) ) ;
}
static inline int F_22 ( struct V_4 * V_5 )
{
return ( V_5 -> V_11 & V_38 ) ? 1 : 0 ;
}
static inline int F_23 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_14 == V_39 && V_5 -> V_13 == V_40 ) ||
( V_5 -> V_13 == V_39 && V_5 -> V_14 == V_40 ) )
return 1 ;
return 0 ;
}
static inline int F_24 ( struct V_4 * V_5 )
{
return ( ! F_23 ( V_5 ) && V_5 -> V_13 < V_5 -> V_14 ) ;
}
static inline int F_25 ( struct V_4 * V_5 )
{
return V_5 -> V_11 & V_41 ;
}
static inline int F_26 ( struct V_4 * V_5 )
{
return V_5 -> V_11 & V_42 ;
}
static inline int F_27 ( struct V_4 * V_5 )
{
return ( V_5 -> V_11 & ( V_41 |
V_42 ) ) ;
}
static void F_28 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
if ( F_22 ( V_5 ) )
return;
F_29 ( V_5 ) ;
F_20 (lkb->lkb_lksb, dlm_print_lkb(lkb);) ;
if ( V_43 == - V_44 && ( V_5 -> V_11 & V_45 ) ) {
V_5 -> V_11 &= ~ V_45 ;
V_43 = - V_46 ;
}
if ( V_43 == - V_44 && ( V_5 -> V_11 & V_47 ) ) {
V_5 -> V_11 &= ~ V_47 ;
V_43 = - V_48 ;
}
F_30 ( V_5 , V_49 , V_5 -> V_14 , V_43 , V_5 -> V_34 ) ;
}
static inline void F_31 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_28 ( V_19 , V_5 ,
F_25 ( V_5 ) ? - V_50 : - V_44 ) ;
}
static void F_32 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_51 )
{
if ( F_22 ( V_5 ) ) {
F_33 ( V_19 , V_5 , V_51 ) ;
} else {
F_30 ( V_5 , V_52 , V_51 , 0 , 0 ) ;
}
}
static inline void F_34 ( struct V_18 * V_19 )
{
F_35 ( & V_19 -> V_53 ) ;
}
void F_36 ( struct V_18 * V_19 )
{
F_34 ( V_19 ) ;
}
static void F_37 ( struct V_18 * V_19 )
{
struct V_29 * V_30 = V_19 -> V_54 ;
T_1 V_55 = V_19 -> V_56 ;
F_38 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
F_39 ( & V_19 -> V_53 , V_59 ) ;
F_40 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
}
void F_41 ( struct V_18 * V_19 )
{
F_37 ( V_19 ) ;
}
static int F_42 ( struct V_29 * V_30 )
{
struct V_18 * V_60 , * V_61 ;
int V_62 = 0 ;
F_38 ( & V_30 -> V_63 ) ;
if ( V_30 -> V_64 > V_65 . V_66 / 2 ) {
F_40 ( & V_30 -> V_63 ) ;
return 0 ;
}
F_40 ( & V_30 -> V_63 ) ;
V_60 = F_43 ( V_30 ) ;
V_61 = F_43 ( V_30 ) ;
F_38 ( & V_30 -> V_63 ) ;
if ( V_60 ) {
F_44 ( & V_60 -> V_67 , & V_30 -> V_68 ) ;
V_30 -> V_64 ++ ;
}
if ( V_61 ) {
F_44 ( & V_61 -> V_67 , & V_30 -> V_68 ) ;
V_30 -> V_64 ++ ;
}
V_62 = V_30 -> V_64 ;
F_40 ( & V_30 -> V_63 ) ;
if ( ! V_62 )
return - V_69 ;
return 0 ;
}
static int F_45 ( struct V_29 * V_30 , char * V_70 , int V_71 ,
struct V_18 * * V_72 )
{
struct V_18 * V_19 ;
int V_62 ;
F_38 ( & V_30 -> V_63 ) ;
if ( F_6 ( & V_30 -> V_68 ) ) {
V_62 = V_30 -> V_64 ;
F_40 ( & V_30 -> V_63 ) ;
F_46 ( V_30 , L_10 ,
V_62 , V_65 . V_66 , V_70 ) ;
return - V_73 ;
}
V_19 = F_47 ( & V_30 -> V_68 , struct V_18 , V_67 ) ;
F_48 ( & V_19 -> V_67 ) ;
memset ( & V_19 -> V_74 , 0 , sizeof( struct V_75 ) ) ;
V_30 -> V_64 -- ;
F_40 ( & V_30 -> V_63 ) ;
V_19 -> V_54 = V_30 ;
V_19 -> V_76 = V_71 ;
memcpy ( V_19 -> V_26 , V_70 , V_71 ) ;
F_49 ( & V_19 -> V_77 ) ;
F_50 ( & V_19 -> V_78 ) ;
F_50 ( & V_19 -> V_79 ) ;
F_50 ( & V_19 -> V_80 ) ;
F_50 ( & V_19 -> V_81 ) ;
F_50 ( & V_19 -> V_27 ) ;
F_50 ( & V_19 -> V_28 ) ;
* V_72 = V_19 ;
return 0 ;
}
static int F_51 ( struct V_18 * V_19 , const char * V_70 , int V_82 )
{
char V_83 [ V_84 ] ;
memset ( V_83 , 0 , V_84 ) ;
memcpy ( V_83 , V_70 , V_82 ) ;
return memcmp ( V_19 -> V_26 , V_83 , V_84 ) ;
}
int F_52 ( struct V_85 * V_86 , char * V_70 , int V_71 ,
struct V_18 * * V_72 )
{
struct V_75 * V_87 = V_86 -> V_75 ;
struct V_18 * V_19 ;
int V_88 ;
while ( V_87 ) {
V_19 = F_53 ( V_87 , struct V_18 , V_74 ) ;
V_88 = F_51 ( V_19 , V_70 , V_71 ) ;
if ( V_88 < 0 )
V_87 = V_87 -> V_89 ;
else if ( V_88 > 0 )
V_87 = V_87 -> V_90 ;
else
goto V_91;
}
* V_72 = NULL ;
return - V_92 ;
V_91:
* V_72 = V_19 ;
return 0 ;
}
static int F_54 ( struct V_18 * V_93 , struct V_85 * V_86 )
{
struct V_75 * * V_94 = & V_86 -> V_75 ;
struct V_75 * V_95 = NULL ;
int V_88 ;
while ( * V_94 ) {
struct V_18 * V_96 = F_53 ( * V_94 , struct V_18 ,
V_74 ) ;
V_95 = * V_94 ;
V_88 = F_51 ( V_96 , V_93 -> V_26 , V_93 -> V_76 ) ;
if ( V_88 < 0 )
V_94 = & V_95 -> V_89 ;
else if ( V_88 > 0 )
V_94 = & V_95 -> V_90 ;
else {
F_55 ( L_11 ) ;
F_5 ( V_93 ) ;
F_5 ( V_96 ) ;
return - V_97 ;
}
}
F_56 ( & V_93 -> V_74 , V_95 , V_94 ) ;
F_57 ( & V_93 -> V_74 , V_86 ) ;
return 0 ;
}
static int F_58 ( struct V_29 * V_30 , char * V_70 , int V_71 ,
T_1 V_98 , T_1 V_99 ,
int V_100 , int V_101 ,
unsigned int V_102 , struct V_18 * * V_72 )
{
struct V_18 * V_19 = NULL ;
int V_103 = F_59 () ;
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 = 0 ;
int V_107 = 0 ;
int error ;
if ( V_102 & V_108 ) {
if ( V_101 == V_100 )
V_106 = 1 ;
else
V_105 = 1 ;
} else if ( V_102 & V_109 ) {
V_104 = 1 ;
}
if ( V_104 || V_106 ||
( V_105 && ( V_100 == V_103 ) ) ) {
V_107 = 1 ;
}
V_110:
if ( V_107 ) {
error = F_42 ( V_30 ) ;
if ( error < 0 )
goto V_111;
}
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_112 , V_70 , V_71 , & V_19 ) ;
if ( error )
goto V_113;
F_35 ( & V_19 -> V_53 ) ;
error = 0 ;
goto V_114;
V_113:
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( error )
goto V_116;
if ( ( V_19 -> V_21 != V_103 ) && V_105 ) {
F_46 ( V_30 , L_12 ,
V_101 , V_19 -> V_21 , V_100 ,
V_19 -> V_26 ) ;
error = - V_117 ;
goto V_114;
}
if ( ( V_19 -> V_21 != V_103 ) && V_106 ) {
F_60 ( V_30 , L_13 ,
V_101 , V_19 -> V_21 ) ;
F_4 ( V_19 ) ;
V_19 -> V_21 = V_103 ;
V_19 -> V_20 = 0 ;
F_61 ( V_19 , V_118 ) ;
V_19 -> V_24 = 0 ;
}
if ( V_104 && ( V_19 -> V_21 != V_103 ) ) {
F_62 ( V_19 , V_118 ) ;
V_19 -> V_24 = 0 ;
}
F_63 ( & V_19 -> V_74 , & V_30 -> V_57 [ V_99 ] . V_115 ) ;
error = F_54 ( V_19 , & V_30 -> V_57 [ V_99 ] . V_112 ) ;
goto V_114;
V_116:
if ( error == - V_92 && ! V_107 )
goto V_114;
error = F_45 ( V_30 , V_70 , V_71 , & V_19 ) ;
if ( error == - V_73 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
goto V_110;
}
if ( error )
goto V_114;
V_19 -> V_119 = V_98 ;
V_19 -> V_56 = V_99 ;
V_19 -> V_22 = V_100 ;
F_64 ( & V_19 -> V_53 ) ;
if ( V_106 ) {
F_46 ( V_30 , L_14 ,
V_101 , V_19 -> V_26 ) ;
V_19 -> V_21 = V_103 ;
V_19 -> V_20 = 0 ;
goto V_120;
}
if ( V_105 && ( V_100 != V_103 ) ) {
F_60 ( V_30 , L_15 ,
V_101 , V_100 , V_103 , V_19 -> V_26 ) ;
F_65 ( V_19 ) ;
V_19 = NULL ;
error = - V_117 ;
goto V_114;
}
if ( V_105 ) {
F_46 ( V_30 , L_16 ,
V_101 , V_100 , V_19 -> V_26 ) ;
}
if ( V_100 == V_103 ) {
V_19 -> V_21 = V_103 ;
V_19 -> V_20 = 0 ;
} else {
V_19 -> V_21 = 0 ;
V_19 -> V_20 = - 1 ;
}
V_120:
error = F_54 ( V_19 , & V_30 -> V_57 [ V_99 ] . V_112 ) ;
V_114:
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_111:
* V_72 = V_19 ;
return error ;
}
static int F_66 ( struct V_29 * V_30 , char * V_70 , int V_71 ,
T_1 V_98 , T_1 V_99 ,
int V_100 , int V_101 ,
unsigned int V_102 , struct V_18 * * V_72 )
{
struct V_18 * V_19 = NULL ;
int V_103 = F_59 () ;
int V_121 = ( V_102 & V_122 ) ;
int error ;
V_110:
error = F_42 ( V_30 ) ;
if ( error < 0 )
goto V_111;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_112 , V_70 , V_71 , & V_19 ) ;
if ( error )
goto V_113;
F_35 ( & V_19 -> V_53 ) ;
goto V_114;
V_113:
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( error )
goto V_116;
if ( ! V_121 && ( V_19 -> V_21 != V_103 ) && V_101 ) {
F_60 ( V_30 , L_17 ,
V_101 , V_19 -> V_21 , V_100 ) ;
F_4 ( V_19 ) ;
error = - V_117 ;
goto V_114;
}
if ( ! V_121 && ( V_19 -> V_21 != V_103 ) &&
( V_100 == V_103 ) ) {
F_60 ( V_30 , L_18 ,
V_103 , V_19 -> V_21 , V_100 ) ;
F_4 ( V_19 ) ;
V_19 -> V_21 = V_103 ;
V_19 -> V_20 = 0 ;
}
F_63 ( & V_19 -> V_74 , & V_30 -> V_57 [ V_99 ] . V_115 ) ;
error = F_54 ( V_19 , & V_30 -> V_57 [ V_99 ] . V_112 ) ;
goto V_114;
V_116:
error = F_45 ( V_30 , V_70 , V_71 , & V_19 ) ;
if ( error == - V_73 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
goto V_110;
}
if ( error )
goto V_114;
V_19 -> V_119 = V_98 ;
V_19 -> V_56 = V_99 ;
V_19 -> V_22 = V_100 ;
V_19 -> V_21 = V_100 ;
V_19 -> V_20 = ( V_100 == V_103 ) ? 0 : V_100 ;
F_64 ( & V_19 -> V_53 ) ;
error = F_54 ( V_19 , & V_30 -> V_57 [ V_99 ] . V_112 ) ;
V_114:
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_111:
* V_72 = V_19 ;
return error ;
}
static int F_67 ( struct V_29 * V_30 , char * V_70 , int V_71 , int V_101 ,
unsigned int V_102 , struct V_18 * * V_72 )
{
T_1 V_98 , V_99 ;
int V_100 ;
if ( V_71 > V_84 )
return - V_123 ;
V_98 = F_68 ( V_70 , V_71 , 0 ) ;
V_99 = V_98 & ( V_30 -> V_124 - 1 ) ;
V_100 = F_69 ( V_30 , V_98 ) ;
if ( F_70 ( V_30 ) )
return F_66 ( V_30 , V_70 , V_71 , V_98 , V_99 , V_100 ,
V_101 , V_102 , V_72 ) ;
else
return F_58 ( V_30 , V_70 , V_71 , V_98 , V_99 , V_100 ,
V_101 , V_102 , V_72 ) ;
}
static int F_71 ( struct V_29 * V_30 , struct V_18 * V_19 ,
int V_101 )
{
if ( F_70 ( V_30 ) ) {
F_60 ( V_30 , L_19 ,
V_101 , V_19 -> V_21 ,
V_19 -> V_22 ) ;
F_4 ( V_19 ) ;
return - V_117 ;
}
if ( V_101 != V_19 -> V_22 ) {
if ( V_19 -> V_21 ) {
F_46 ( V_30 , L_20
L_21 , V_101 ,
V_19 -> V_21 , V_19 -> V_22 ,
V_19 -> V_24 , V_19 -> V_26 ) ;
}
return - V_117 ;
} else {
if ( V_19 -> V_21 ) {
F_60 ( V_30 , L_22
L_23 ,
V_101 , V_19 -> V_21 ,
V_19 -> V_24 , V_19 -> V_26 ) ;
}
V_19 -> V_21 = F_59 () ;
V_19 -> V_20 = 0 ;
return 0 ;
}
}
int F_72 ( struct V_29 * V_30 , int V_101 , char * V_70 , int V_71 ,
unsigned int V_102 , int * V_125 , int * V_126 )
{
struct V_18 * V_19 = NULL ;
T_1 V_98 , V_99 ;
int V_127 = ( V_102 & V_128 ) ;
int V_129 = ( V_102 & V_130 ) ;
int V_103 = F_59 () ;
int V_100 , error , V_131 = 0 ;
if ( V_71 > V_84 )
return - V_123 ;
if ( V_101 == V_103 ) {
F_60 ( V_30 , L_24 ,
V_103 , V_102 ) ;
return - V_123 ;
}
V_98 = F_68 ( V_70 , V_71 , 0 ) ;
V_99 = V_98 & ( V_30 -> V_124 - 1 ) ;
V_100 = F_69 ( V_30 , V_98 ) ;
if ( V_100 != V_103 ) {
F_60 ( V_30 , L_25 ,
V_101 , V_100 , V_103 , V_98 ,
V_30 -> V_132 ) ;
* V_125 = - 1 ;
return - V_123 ;
}
V_110:
error = F_42 ( V_30 ) ;
if ( error < 0 )
return error ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_112 , V_70 , V_71 , & V_19 ) ;
if ( ! error ) {
F_34 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_73 ( V_19 ) ;
goto V_91;
}
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( error )
goto V_133;
V_131 = 1 ;
V_91:
if ( V_19 -> V_22 != V_103 ) {
F_60 ( V_30 , L_26 ,
V_19 -> V_22 , V_103 , V_19 -> V_26 ) ;
V_19 -> V_22 = V_103 ;
}
if ( V_129 && F_74 ( V_30 , V_19 -> V_21 ) ) {
V_19 -> V_21 = V_101 ;
V_19 -> V_20 = V_101 ;
F_62 ( V_19 , V_134 ) ;
if ( V_131 ) {
F_60 ( V_30 , L_27 ) ;
F_5 ( V_19 ) ;
}
}
if ( V_127 && ( V_19 -> V_21 != V_101 ) ) {
F_75 ( V_30 , L_28
L_29 ,
V_101 , V_19 -> V_21 , V_19 -> V_20 ,
V_19 -> V_24 , V_19 -> V_26 ) ;
if ( V_19 -> V_21 == V_103 ) {
F_60 ( V_30 , L_30 , V_101 ) ;
F_5 ( V_19 ) ;
F_76 ( V_19 , V_101 ) ;
goto V_135;
}
V_19 -> V_21 = V_101 ;
V_19 -> V_20 = V_101 ;
F_62 ( V_19 , V_134 ) ;
}
if ( ! V_19 -> V_21 ) {
F_46 ( V_30 , L_31 ,
V_101 , V_19 -> V_24 , V_19 -> V_26 ) ;
V_19 -> V_21 = V_101 ;
V_19 -> V_20 = V_101 ;
}
if ( ! V_127 && ! V_129 &&
( V_19 -> V_21 == V_101 ) ) {
F_75 ( V_30 , L_32
L_23 , V_101 , V_102 ,
V_19 -> V_24 , V_19 -> V_26 ) ;
}
V_135:
* V_125 = V_19 -> V_21 ;
if ( V_126 )
* V_126 = V_136 ;
if ( V_131 ) {
V_19 -> V_137 = V_138 ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
} else {
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
return 0 ;
V_133:
error = F_45 ( V_30 , V_70 , V_71 , & V_19 ) ;
if ( error == - V_73 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
goto V_110;
}
if ( error )
goto V_114;
V_19 -> V_119 = V_98 ;
V_19 -> V_56 = V_99 ;
V_19 -> V_22 = V_103 ;
V_19 -> V_21 = V_101 ;
V_19 -> V_20 = V_101 ;
F_64 ( & V_19 -> V_53 ) ;
V_19 -> V_137 = V_138 ;
error = F_54 ( V_19 , & V_30 -> V_57 [ V_99 ] . V_115 ) ;
if ( error ) {
F_65 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
goto V_110;
}
if ( V_126 )
* V_126 = V_139 ;
* V_125 = V_101 ;
error = 0 ;
V_114:
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return error ;
}
static void F_78 ( struct V_29 * V_30 , T_1 V_98 )
{
struct V_75 * V_140 ;
struct V_18 * V_19 ;
int V_141 ;
for ( V_141 = 0 ; V_141 < V_30 -> V_124 ; V_141 ++ ) {
F_38 ( & V_30 -> V_57 [ V_141 ] . V_58 ) ;
for ( V_140 = F_79 ( & V_30 -> V_57 [ V_141 ] . V_112 ) ; V_140 ; V_140 = F_80 ( V_140 ) ) {
V_19 = F_53 ( V_140 , struct V_18 , V_74 ) ;
if ( V_19 -> V_119 == V_98 )
F_5 ( V_19 ) ;
}
F_40 ( & V_30 -> V_57 [ V_141 ] . V_58 ) ;
}
}
void F_81 ( struct V_29 * V_30 , char * V_70 , int V_71 )
{
struct V_18 * V_19 = NULL ;
T_1 V_98 , V_99 ;
int error ;
V_98 = F_68 ( V_70 , V_71 , 0 ) ;
V_99 = V_98 & ( V_30 -> V_124 - 1 ) ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_112 , V_70 , V_71 , & V_19 ) ;
if ( ! error )
goto V_142;
error = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( error )
goto V_111;
V_142:
F_5 ( V_19 ) ;
V_111:
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
}
static void V_59 ( struct V_143 * V_143 )
{
struct V_18 * V_19 = F_82 ( V_143 , struct V_18 , V_53 ) ;
struct V_29 * V_30 = V_19 -> V_54 ;
F_20 (list_empty(&r->res_root_list), dlm_print_rsb(r);) ;
F_64 ( & V_19 -> V_53 ) ;
F_63 ( & V_19 -> V_74 , & V_30 -> V_57 [ V_19 -> V_56 ] . V_112 ) ;
F_54 ( V_19 , & V_30 -> V_57 [ V_19 -> V_56 ] . V_115 ) ;
V_19 -> V_137 = V_138 ;
V_30 -> V_57 [ V_19 -> V_56 ] . V_102 |= V_144 ;
if ( V_19 -> V_145 ) {
F_83 ( V_19 -> V_145 ) ;
V_19 -> V_145 = NULL ;
}
}
static void F_84 ( struct V_18 * V_19 )
{
int V_43 ;
V_43 = F_39 ( & V_19 -> V_53 , V_59 ) ;
F_20 (!rv, dlm_dump_rsb(r);) ;
}
static void F_85 ( struct V_143 * V_143 )
{
struct V_18 * V_19 = F_82 ( V_143 , struct V_18 , V_53 ) ;
F_20 (list_empty(&r->res_lookup), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_grantqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_convertqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_waitqueue), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_root_list), dlm_dump_rsb(r);) ;
F_20 (list_empty(&r->res_recover_list), dlm_dump_rsb(r);) ;
}
static void F_86 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_34 ( V_19 ) ;
V_5 -> V_146 = V_19 ;
}
static void F_87 ( struct V_4 * V_5 )
{
if ( V_5 -> V_146 ) {
F_37 ( V_5 -> V_146 ) ;
V_5 -> V_146 = NULL ;
}
}
static int F_88 ( struct V_29 * V_30 , struct V_4 * * V_147 )
{
struct V_4 * V_5 ;
int V_43 ;
V_5 = F_89 ( V_30 ) ;
if ( ! V_5 )
return - V_69 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_14 = V_148 ;
F_64 ( & V_5 -> V_149 ) ;
F_50 ( & V_5 -> V_150 ) ;
F_50 ( & V_5 -> V_151 ) ;
F_50 ( & V_5 -> V_152 ) ;
F_50 ( & V_5 -> V_153 ) ;
F_49 ( & V_5 -> V_154 ) ;
F_90 ( & V_5 -> V_155 , V_156 ) ;
F_91 ( V_157 ) ;
F_38 ( & V_30 -> V_158 ) ;
V_43 = F_92 ( & V_30 -> V_159 , V_5 , 1 , 0 , V_160 ) ;
if ( V_43 >= 0 )
V_5 -> V_8 = V_43 ;
F_40 ( & V_30 -> V_158 ) ;
F_93 () ;
if ( V_43 < 0 ) {
F_60 ( V_30 , L_33 , V_43 ) ;
return V_43 ;
}
* V_147 = V_5 ;
return 0 ;
}
static int F_94 ( struct V_29 * V_30 , T_1 V_161 , struct V_4 * * V_147 )
{
struct V_4 * V_5 ;
F_38 ( & V_30 -> V_158 ) ;
V_5 = F_95 ( & V_30 -> V_159 , V_161 ) ;
if ( V_5 )
F_35 ( & V_5 -> V_149 ) ;
F_40 ( & V_30 -> V_158 ) ;
* V_147 = V_5 ;
return V_5 ? 0 : - V_162 ;
}
static void F_96 ( struct V_143 * V_143 )
{
struct V_4 * V_5 = F_82 ( V_143 , struct V_4 , V_149 ) ;
F_20 (!lkb->lkb_status, dlm_print_lkb(lkb);) ;
}
static int F_97 ( struct V_29 * V_30 , struct V_4 * V_5 )
{
T_1 V_161 = V_5 -> V_8 ;
F_38 ( & V_30 -> V_158 ) ;
if ( F_39 ( & V_5 -> V_149 , F_96 ) ) {
F_98 ( & V_30 -> V_159 , V_161 ) ;
F_40 ( & V_30 -> V_158 ) ;
F_87 ( V_5 ) ;
if ( V_5 -> V_163 && F_22 ( V_5 ) )
F_83 ( V_5 -> V_163 ) ;
F_99 ( V_5 ) ;
return 1 ;
} else {
F_40 ( & V_30 -> V_158 ) ;
return 0 ;
}
}
int F_100 ( struct V_4 * V_5 )
{
struct V_29 * V_30 ;
F_20 (lkb->lkb_resource, dlm_print_lkb(lkb);) ;
F_20 (lkb->lkb_resource->res_ls, dlm_print_lkb(lkb);) ;
V_30 = V_5 -> V_146 -> V_54 ;
return F_97 ( V_30 , V_5 ) ;
}
static inline void F_101 ( struct V_4 * V_5 )
{
F_35 ( & V_5 -> V_149 ) ;
}
static inline void F_102 ( struct V_4 * V_5 )
{
int V_43 ;
V_43 = F_39 ( & V_5 -> V_149 , F_96 ) ;
F_20 (!rv, dlm_print_lkb(lkb);) ;
}
static void F_103 ( struct V_164 * V_165 , struct V_164 * V_166 ,
int V_167 )
{
struct V_4 * V_5 = NULL ;
F_7 (lkb, head, lkb_statequeue)
if ( V_5 -> V_13 < V_167 )
break;
F_104 ( V_165 , V_5 -> V_168 . V_169 , & V_5 -> V_168 ) ;
}
static void F_105 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_170 )
{
F_35 ( & V_5 -> V_149 ) ;
F_20 (!lkb->lkb_status, dlm_print_lkb(lkb);) ;
V_5 -> V_171 = F_106 () ;
V_5 -> V_12 = V_170 ;
switch ( V_170 ) {
case V_172 :
if ( V_5 -> V_10 & V_173 )
F_44 ( & V_5 -> V_168 , & V_19 -> V_81 ) ;
else
F_107 ( & V_5 -> V_168 , & V_19 -> V_81 ) ;
break;
case V_37 :
F_103 ( & V_5 -> V_168 , & V_19 -> V_79 ,
V_5 -> V_14 ) ;
break;
case V_174 :
if ( V_5 -> V_10 & V_173 )
F_44 ( & V_5 -> V_168 , & V_19 -> V_80 ) ;
else
F_107 ( & V_5 -> V_168 ,
& V_19 -> V_80 ) ;
break;
default:
F_20 ( 0 , dlm_print_lkb(lkb); printk(L_34, status);) ;
}
}
static void F_108 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
V_5 -> V_12 = 0 ;
F_48 ( & V_5 -> V_168 ) ;
F_102 ( V_5 ) ;
}
static void F_109 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_175 )
{
F_101 ( V_5 ) ;
F_108 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_175 ) ;
F_102 ( V_5 ) ;
}
static int F_110 ( int V_176 )
{
switch ( V_176 ) {
case V_177 :
return V_178 ;
case V_179 :
return V_180 ;
case V_181 :
return V_182 ;
case V_183 :
return V_184 ;
case V_185 :
return V_186 ;
}
return - 1 ;
}
static int F_111 ( int V_187 , int V_188 , int * V_189 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < V_188 ; V_141 ++ ) {
if ( ! V_189 [ V_141 ] ) {
V_189 [ V_141 ] = V_187 ;
return 0 ;
}
if ( V_189 [ V_141 ] == V_187 )
return 1 ;
}
return 0 ;
}
void F_112 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
T_2 V_190 = F_113 ( 0 , 0 ) ;
T_3 V_191 ;
T_3 V_192 = 0 ;
T_4 V_193 = 0 ;
T_4 V_194 = 0 ;
int V_188 = 0 ;
int * V_189 = NULL ;
if ( ! V_65 . V_195 )
return;
F_114 ( & V_30 -> V_196 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_115 ( V_5 -> V_197 , V_190 ) )
continue;
V_193 ++ ;
V_191 = F_116 ( F_117 ( F_106 () , V_5 -> V_197 ) ) ;
if ( V_191 < V_65 . V_195 )
continue;
V_5 -> V_197 = V_190 ;
V_194 ++ ;
if ( V_191 > V_192 )
V_192 = V_191 ;
if ( ! V_188 ) {
V_188 = V_30 -> V_132 ;
V_189 = F_118 ( V_188 * sizeof( int ) , V_198 ) ;
}
if ( ! V_189 )
continue;
if ( F_111 ( V_5 -> V_16 , V_188 , V_189 ) )
continue;
F_60 ( V_30 , L_35
L_36 , V_5 -> V_8 , ( long long ) V_191 ,
V_65 . V_195 , V_5 -> V_16 ) ;
}
F_119 ( & V_30 -> V_196 ) ;
F_120 ( V_189 ) ;
if ( V_194 )
F_46 ( V_30 , L_37 ,
V_193 , V_194 ,
V_65 . V_195 , ( long long ) V_192 ) ;
}
static int F_121 ( struct V_4 * V_5 , int V_176 , int V_199 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int error = 0 ;
F_114 ( & V_30 -> V_196 ) ;
if ( F_25 ( V_5 ) ||
( F_26 ( V_5 ) && ( V_176 == V_183 ) ) ) {
error = - V_123 ;
goto V_111;
}
if ( V_5 -> V_15 || F_26 ( V_5 ) ) {
switch ( V_176 ) {
case V_181 :
V_5 -> V_11 |= V_41 ;
break;
case V_183 :
V_5 -> V_11 |= V_42 ;
break;
default:
error = - V_200 ;
goto V_111;
}
V_5 -> V_201 ++ ;
F_101 ( V_5 ) ;
F_46 ( V_30 , L_38 ,
V_5 -> V_8 , V_5 -> V_15 , V_176 ,
V_5 -> V_201 , V_5 -> V_11 ) ;
goto V_111;
}
F_20 (!lkb->lkb_wait_count,
dlm_print_lkb(lkb);
printk(L_39, lkb->lkb_wait_count);) ;
V_5 -> V_201 ++ ;
V_5 -> V_15 = V_176 ;
V_5 -> V_197 = F_106 () ;
V_5 -> V_16 = V_199 ;
F_101 ( V_5 ) ;
F_44 ( & V_5 -> V_202 , & V_30 -> V_203 ) ;
V_111:
if ( error )
F_60 ( V_30 , L_40 ,
V_5 -> V_8 , error , V_5 -> V_11 , V_176 ,
V_5 -> V_15 , V_5 -> V_146 -> V_26 ) ;
F_119 ( & V_30 -> V_196 ) ;
return error ;
}
static int F_122 ( struct V_4 * V_5 , int V_176 ,
struct V_204 * V_205 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int V_206 = 0 ;
if ( F_25 ( V_5 ) && ( V_176 == V_182 ) ) {
F_46 ( V_30 , L_41 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_41 ;
V_206 = 1 ;
goto V_207;
}
if ( F_26 ( V_5 ) && ( V_176 == V_184 ) ) {
F_46 ( V_30 , L_42 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_42 ;
V_206 = 1 ;
goto V_207;
}
if ( ( V_176 == V_184 ) &&
( V_5 -> V_15 != V_183 ) ) {
F_46 ( V_30 , L_43 ,
V_5 -> V_8 , V_5 -> V_15 ) ;
return - 1 ;
}
if ( ( V_176 == V_180 ) &&
( V_5 -> V_15 == V_179 ) &&
F_26 ( V_5 ) && V_205 && ! V_205 -> V_208 ) {
F_46 ( V_30 , L_44 ,
V_5 -> V_8 ) ;
V_5 -> V_15 = 0 ;
V_5 -> V_11 &= ~ V_42 ;
V_5 -> V_201 -- ;
goto V_207;
}
if ( V_5 -> V_15 ) {
V_5 -> V_15 = 0 ;
goto V_207;
}
F_60 ( V_30 , L_45 ,
V_5 -> V_8 , V_205 ? V_205 -> V_209 . V_210 : 0 , V_5 -> V_9 ,
V_176 , V_5 -> V_11 ) ;
return - 1 ;
V_207:
if ( V_206 && V_5 -> V_15 ) {
F_60 ( V_30 , L_46 ,
V_5 -> V_8 , V_176 , V_5 -> V_15 ) ;
V_5 -> V_201 -- ;
V_5 -> V_15 = 0 ;
}
F_20 (lkb->lkb_wait_count, dlm_print_lkb(lkb);) ;
V_5 -> V_11 &= ~ V_211 ;
V_5 -> V_201 -- ;
if ( ! V_5 -> V_201 )
F_123 ( & V_5 -> V_202 ) ;
F_102 ( V_5 ) ;
return 0 ;
}
static int F_124 ( struct V_4 * V_5 , int V_176 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int error ;
F_114 ( & V_30 -> V_196 ) ;
error = F_122 ( V_5 , V_176 , NULL ) ;
F_119 ( & V_30 -> V_196 ) ;
return error ;
}
static int F_125 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int error ;
if ( V_205 -> V_212 != V_213 )
F_114 ( & V_30 -> V_196 ) ;
error = F_122 ( V_5 , V_205 -> V_214 , V_205 ) ;
if ( V_205 -> V_212 != V_213 )
F_119 ( & V_30 -> V_196 ) ;
return error ;
}
static void F_126 ( struct V_18 * V_19 )
{
struct V_29 * V_30 = V_19 -> V_54 ;
V_215:
F_38 ( & V_30 -> V_216 ) ;
if ( V_30 -> V_217 &&
! F_51 ( V_19 , V_30 -> V_218 , V_30 -> V_217 ) ) {
F_46 ( V_30 , L_47 ,
V_19 -> V_22 , V_19 -> V_26 ) ;
F_40 ( & V_30 -> V_216 ) ;
F_127 ( 1 ) ;
goto V_215;
}
F_40 ( & V_30 -> V_216 ) ;
}
static void F_128 ( struct V_29 * V_30 , int V_99 )
{
struct V_75 * V_140 , * V_219 ;
struct V_18 * V_19 ;
char * V_70 ;
int V_103 = F_59 () ;
int V_220 = 0 ;
int V_221 = 0 ;
int V_141 , V_71 , V_43 ;
memset ( & V_30 -> V_222 , 0 , sizeof( int ) * V_223 ) ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
if ( ! ( V_30 -> V_57 [ V_99 ] . V_102 & V_144 ) ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return;
}
for ( V_140 = F_79 ( & V_30 -> V_57 [ V_99 ] . V_115 ) ; V_140 ; V_140 = V_219 ) {
V_219 = F_80 ( V_140 ) ;
V_19 = F_53 ( V_140 , struct V_18 , V_74 ) ;
if ( ! F_70 ( V_30 ) &&
( V_19 -> V_21 != V_103 ) &&
( F_129 ( V_19 ) == V_103 ) ) {
continue;
}
V_221 = 1 ;
if ( ! F_130 ( V_138 , V_19 -> V_137 +
V_65 . V_224 * V_225 ) ) {
continue;
}
if ( ! F_70 ( V_30 ) &&
( V_19 -> V_21 == V_103 ) &&
( F_129 ( V_19 ) != V_103 ) ) {
V_30 -> V_222 [ V_220 ] = V_19 -> V_76 ;
memcpy ( V_30 -> V_226 [ V_220 ] , V_19 -> V_26 ,
V_84 ) ;
V_220 ++ ;
if ( V_220 >= V_223 )
break;
continue;
}
if ( ! F_39 ( & V_19 -> V_53 , F_85 ) ) {
F_60 ( V_30 , L_48 , V_19 -> V_26 ) ;
continue;
}
F_63 ( & V_19 -> V_74 , & V_30 -> V_57 [ V_99 ] . V_115 ) ;
F_65 ( V_19 ) ;
}
if ( V_221 )
V_30 -> V_57 [ V_99 ] . V_102 |= V_144 ;
else
V_30 -> V_57 [ V_99 ] . V_102 &= ~ V_144 ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
for ( V_141 = 0 ; V_141 < V_220 ; V_141 ++ ) {
V_70 = V_30 -> V_226 [ V_141 ] ;
V_71 = V_30 -> V_222 [ V_141 ] ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_43 = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( V_43 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_46 ( V_30 , L_49 , V_70 ) ;
continue;
}
if ( V_19 -> V_21 != V_103 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_46 ( V_30 , L_50 ,
V_19 -> V_21 , V_19 -> V_22 ,
V_103 , V_70 ) ;
continue;
}
if ( V_19 -> V_22 == V_103 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_60 ( V_30 , L_51 ,
V_19 -> V_22 , V_19 -> V_21 ,
V_103 , V_70 ) ;
continue;
}
if ( ! F_130 ( V_138 , V_19 -> V_137 +
V_65 . V_224 * V_225 ) ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_46 ( V_30 , L_52 ,
V_19 -> V_137 , V_138 , V_70 ) ;
continue;
}
if ( ! F_39 ( & V_19 -> V_53 , F_85 ) ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_60 ( V_30 , L_53 , V_70 ) ;
continue;
}
F_63 ( & V_19 -> V_74 , & V_30 -> V_57 [ V_99 ] . V_115 ) ;
F_38 ( & V_30 -> V_216 ) ;
V_30 -> V_217 = V_71 ;
memcpy ( V_30 -> V_218 , V_70 , V_84 ) ;
F_40 ( & V_30 -> V_216 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_131 ( V_19 ) ;
F_38 ( & V_30 -> V_216 ) ;
V_30 -> V_217 = 0 ;
memset ( V_30 -> V_218 , 0 , V_84 ) ;
F_40 ( & V_30 -> V_216 ) ;
F_65 ( V_19 ) ;
}
}
void F_132 ( struct V_29 * V_30 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < V_30 -> V_124 ; V_141 ++ ) {
F_128 ( V_30 , V_141 ) ;
if ( F_133 ( V_30 ) )
break;
F_134 () ;
}
}
static void F_135 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
if ( F_22 ( V_5 ) )
return;
if ( F_136 ( V_227 , & V_30 -> V_228 ) &&
! ( V_5 -> V_10 & V_229 ) ) {
V_5 -> V_11 |= V_230 ;
goto V_231;
}
if ( V_5 -> V_10 & V_232 )
goto V_231;
return;
V_231:
F_20 (list_empty(&lkb->lkb_time_list), dlm_print_lkb(lkb);) ;
F_114 ( & V_30 -> V_233 ) ;
F_101 ( V_5 ) ;
F_107 ( & V_5 -> V_152 , & V_30 -> V_234 ) ;
F_119 ( & V_30 -> V_233 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
F_114 ( & V_30 -> V_233 ) ;
if ( ! F_6 ( & V_5 -> V_152 ) ) {
F_123 ( & V_5 -> V_152 ) ;
F_102 ( V_5 ) ;
}
F_119 ( & V_30 -> V_233 ) ;
}
void F_137 ( struct V_29 * V_30 )
{
struct V_18 * V_19 ;
struct V_4 * V_5 ;
int V_235 , V_236 ;
T_3 V_237 ;
for (; ; ) {
if ( F_133 ( V_30 ) )
break;
V_235 = 0 ;
V_236 = 0 ;
F_114 ( & V_30 -> V_233 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list) {
V_237 = F_116 ( F_117 ( F_106 () ,
V_5 -> V_171 ) ) ;
if ( ( V_5 -> V_10 & V_232 ) &&
V_237 >= ( V_5 -> V_238 * 10000 ) )
V_235 = 1 ;
if ( ( V_5 -> V_11 & V_230 ) &&
V_237 >= V_65 . V_239 * 10000 )
V_236 = 1 ;
if ( ! V_235 && ! V_236 )
continue;
F_101 ( V_5 ) ;
break;
}
F_119 ( & V_30 -> V_233 ) ;
if ( ! V_235 && ! V_236 )
break;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
if ( V_236 ) {
V_5 -> V_11 &= ~ V_230 ;
if ( ! ( V_5 -> V_10 & V_232 ) )
F_29 ( V_5 ) ;
F_138 ( V_5 ) ;
}
if ( V_235 ) {
F_46 ( V_30 , L_54 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_26 ) ;
V_5 -> V_11 &= ~ V_230 ;
V_5 -> V_11 |= V_45 ;
F_29 ( V_5 ) ;
F_139 ( V_19 , V_5 ) ;
}
F_77 ( V_19 ) ;
F_84 ( V_19 ) ;
F_100 ( V_5 ) ;
}
}
void F_140 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
T_5 V_240 = F_141 ( V_138 - V_30 -> V_241 ) ;
V_30 -> V_241 = 0 ;
F_114 ( & V_30 -> V_233 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list)
V_5 -> V_171 = F_142 ( V_5 -> V_171 , V_240 ) ;
F_119 ( & V_30 -> V_233 ) ;
if ( ! V_65 . V_195 )
return;
F_114 ( & V_30 -> V_196 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_116 ( V_5 -> V_197 ) )
V_5 -> V_197 = F_106 () ;
}
F_119 ( & V_30 -> V_196 ) ;
}
static void F_143 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_99 , V_71 = V_19 -> V_54 -> V_242 ;
V_99 = V_243 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_99 == 1 ) {
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_244 ) )
return;
if ( ! V_19 -> V_145 )
return;
memcpy ( V_5 -> V_163 , V_19 -> V_145 , V_71 ) ;
V_5 -> V_245 = V_19 -> V_246 ;
} else if ( V_99 == 0 ) {
if ( V_5 -> V_10 & V_247 ) {
F_62 ( V_19 , V_248 ) ;
return;
}
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_244 ) )
return;
if ( ! V_19 -> V_145 )
V_19 -> V_145 = F_144 ( V_19 -> V_54 ) ;
if ( ! V_19 -> V_145 )
return;
memcpy ( V_19 -> V_145 , V_5 -> V_163 , V_71 ) ;
V_19 -> V_246 ++ ;
V_5 -> V_245 = V_19 -> V_246 ;
F_61 ( V_19 , V_248 ) ;
}
if ( F_145 ( V_19 , V_248 ) )
V_5 -> V_34 |= V_249 ;
}
static void F_146 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 < V_250 )
return;
if ( V_5 -> V_10 & V_247 ) {
F_62 ( V_19 , V_248 ) ;
return;
}
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_244 ) )
return;
if ( ! V_19 -> V_145 )
V_19 -> V_145 = F_144 ( V_19 -> V_54 ) ;
if ( ! V_19 -> V_145 )
return;
memcpy ( V_19 -> V_145 , V_5 -> V_163 , V_19 -> V_54 -> V_242 ) ;
V_19 -> V_246 ++ ;
F_61 ( V_19 , V_248 ) ;
}
static void F_147 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
int V_99 ;
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_244 ) )
return;
V_99 = V_243 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_99 == 1 ) {
int V_71 = F_148 ( V_205 ) ;
if ( V_71 > V_19 -> V_54 -> V_242 )
V_71 = V_19 -> V_54 -> V_242 ;
memcpy ( V_5 -> V_163 , V_205 -> V_251 , V_71 ) ;
V_5 -> V_245 = V_205 -> V_252 ;
}
}
static void F_149 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_108 ( V_19 , V_5 ) ;
V_5 -> V_14 = V_148 ;
F_102 ( V_5 ) ;
}
static void F_150 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_146 ( V_19 , V_5 ) ;
F_149 ( V_19 , V_5 ) ;
}
static void F_151 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_149 ( V_19 , V_5 ) ;
}
static int F_152 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_43 = 0 ;
V_5 -> V_13 = V_148 ;
switch ( V_5 -> V_12 ) {
case V_37 :
break;
case V_174 :
F_109 ( V_19 , V_5 , V_37 ) ;
V_43 = 1 ;
break;
case V_172 :
F_108 ( V_19 , V_5 ) ;
V_5 -> V_14 = V_148 ;
F_102 ( V_5 ) ;
V_43 = - 1 ;
break;
default:
F_55 ( L_55 , V_5 -> V_12 ) ;
}
return V_43 ;
}
static int F_153 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_152 ( V_19 , V_5 ) ;
}
static void F_154 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 != V_5 -> V_13 ) {
V_5 -> V_14 = V_5 -> V_13 ;
if ( V_5 -> V_12 )
F_109 ( V_19 , V_5 , V_37 ) ;
else
F_105 ( V_19 , V_5 , V_37 ) ;
}
V_5 -> V_13 = V_148 ;
V_5 -> V_253 = 0 ;
}
static void F_155 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_143 ( V_19 , V_5 ) ;
F_154 ( V_19 , V_5 ) ;
}
static void F_156 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
F_147 ( V_19 , V_5 , V_205 ) ;
F_154 ( V_19 , V_5 ) ;
}
static void F_157 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_155 ( V_19 , V_5 ) ;
if ( F_22 ( V_5 ) )
F_158 ( V_19 , V_5 ) ;
else
F_28 ( V_19 , V_5 , 0 ) ;
}
static void F_159 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 == V_148 || V_5 -> V_14 == V_148 ) {
F_55 ( L_56 ,
V_5 -> V_8 , V_5 -> V_14 , V_5 -> V_13 ) ;
return;
}
V_5 -> V_14 = V_254 ;
}
static void F_160 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
if ( V_205 -> V_214 != V_178 &&
V_205 -> V_214 != V_255 ) {
F_55 ( L_57 ,
V_5 -> V_8 , V_205 -> V_214 ) ;
return;
}
if ( V_5 -> V_10 & V_256 )
V_5 -> V_13 = V_39 ;
else if ( V_5 -> V_10 & V_257 )
V_5 -> V_13 = V_40 ;
else {
F_55 ( L_58 , V_5 -> V_10 ) ;
F_2 ( V_5 ) ;
}
}
static inline int F_161 ( struct V_4 * V_5 , struct V_164 * V_166 )
{
struct V_4 * V_258 = F_162 ( V_166 -> V_219 , struct V_4 ,
V_168 ) ;
if ( V_5 -> V_8 == V_258 -> V_8 )
return 1 ;
return 0 ;
}
static int F_163 ( struct V_164 * V_166 , struct V_4 * V_5 )
{
struct V_4 * V_259 ;
F_7 (this, head, lkb_statequeue) {
if ( V_259 == V_5 )
continue;
if ( ! F_164 ( V_259 , V_5 ) )
return 1 ;
}
return 0 ;
}
static int F_165 ( struct V_18 * V_19 , struct V_4 * V_260 )
{
struct V_4 * V_261 ;
int V_262 = 0 ;
F_7 (lkb1, &r->res_convertqueue, lkb_statequeue) {
if ( V_261 == V_260 ) {
V_262 = 1 ;
continue;
}
if ( ! V_262 ) {
if ( ! F_164 ( V_260 , V_261 ) )
return 1 ;
} else {
if ( ! F_164 ( V_260 , V_261 ) &&
! F_164 ( V_261 , V_260 ) )
return 1 ;
}
}
return 0 ;
}
static int F_166 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_263 ,
int V_121 )
{
T_6 V_264 = ( V_5 -> V_14 != V_148 ) ;
if ( V_5 -> V_10 & V_265 )
return 1 ;
if ( F_163 ( & V_19 -> V_79 , V_5 ) )
return 0 ;
if ( F_163 ( & V_19 -> V_80 , V_5 ) )
return 0 ;
if ( V_264 && V_121 )
return 1 ;
if ( V_263 && V_264 && ! ( V_5 -> V_10 & V_266 ) )
return 1 ;
if ( V_263 && V_264 && ( V_5 -> V_10 & V_266 ) ) {
if ( F_6 ( & V_19 -> V_80 ) )
return 1 ;
else
return 0 ;
}
if ( V_5 -> V_10 & V_267 )
return 1 ;
if ( ! V_263 && V_264 && F_161 ( V_5 , & V_19 -> V_80 ) )
return 1 ;
if ( V_263 && ! V_264 && F_6 ( & V_19 -> V_80 ) &&
F_6 ( & V_19 -> V_81 ) )
return 1 ;
if ( ! V_263 && ! V_264 && F_6 ( & V_19 -> V_80 ) &&
F_161 ( V_5 , & V_19 -> V_81 ) )
return 1 ;
return 0 ;
}
static int F_167 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_263 ,
int V_121 , int * V_268 )
{
int V_43 ;
T_6 V_269 = 0 , V_51 = V_5 -> V_13 ;
T_6 V_270 = ( V_5 -> V_14 != V_148 ) ;
if ( V_268 )
* V_268 = 0 ;
V_43 = F_166 ( V_19 , V_5 , V_263 , V_121 ) ;
if ( V_43 )
goto V_111;
if ( V_270 && F_14 ( V_5 ) &&
F_165 ( V_19 , V_5 ) ) {
if ( V_5 -> V_10 & V_271 ) {
V_5 -> V_14 = V_254 ;
V_5 -> V_34 |= V_35 ;
} else if ( ! ( V_5 -> V_10 & V_229 ) ) {
if ( V_268 )
* V_268 = - V_48 ;
else {
F_55 ( L_59 ,
V_5 -> V_8 , V_263 ) ;
F_5 ( V_19 ) ;
}
}
goto V_111;
}
if ( V_51 != V_39 && ( V_5 -> V_10 & V_256 ) )
V_269 = V_39 ;
else if ( V_51 != V_40 && ( V_5 -> V_10 & V_257 ) )
V_269 = V_40 ;
if ( V_269 ) {
V_5 -> V_13 = V_269 ;
V_43 = F_166 ( V_19 , V_5 , V_263 , 0 ) ;
if ( V_43 )
V_5 -> V_34 |= V_36 ;
else
V_5 -> V_13 = V_51 ;
}
V_111:
return V_43 ;
}
static int F_168 ( struct V_18 * V_19 , int V_272 , int * V_273 ,
unsigned int * V_62 )
{
struct V_4 * V_5 , * V_274 ;
int V_121 = F_145 ( V_19 , V_275 ) ;
int V_276 , V_277 , V_278 , V_279 , V_280 ;
int V_281 ;
V_278 = 0 ;
V_215:
V_279 = 0 ;
V_280 = 0 ;
V_276 = V_148 ;
F_169 (lkb, s, &r->res_convertqueue, lkb_statequeue) {
V_277 = F_16 ( V_5 ) ;
V_281 = 0 ;
if ( F_167 ( V_19 , V_5 , 0 , V_121 , & V_281 ) ) {
F_157 ( V_19 , V_5 ) ;
V_279 = 1 ;
if ( V_62 )
( * V_62 ) ++ ;
continue;
}
if ( ! V_277 && F_16 ( V_5 ) ) {
F_55 ( L_60 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_26 ) ;
V_280 = 1 ;
continue;
}
if ( V_281 ) {
F_55 ( L_61 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_26 ) ;
F_5 ( V_19 ) ;
continue;
}
V_276 = F_170 ( int , V_5 -> V_13 , V_276 ) ;
if ( V_273 && V_5 -> V_13 == V_40 )
* V_273 = 1 ;
}
if ( V_279 )
goto V_215;
if ( V_280 && ! V_278 ) {
V_278 = 1 ;
goto V_215;
}
return F_170 ( int , V_272 , V_276 ) ;
}
static int F_171 ( struct V_18 * V_19 , int V_272 , int * V_273 ,
unsigned int * V_62 )
{
struct V_4 * V_5 , * V_274 ;
F_169 (lkb, s, &r->res_waitqueue, lkb_statequeue) {
if ( F_167 ( V_19 , V_5 , 0 , 0 , NULL ) ) {
F_157 ( V_19 , V_5 ) ;
if ( V_62 )
( * V_62 ) ++ ;
} else {
V_272 = F_170 ( int , V_5 -> V_13 , V_272 ) ;
if ( V_5 -> V_13 == V_40 )
* V_273 = 1 ;
}
}
return V_272 ;
}
static int F_172 ( struct V_4 * V_282 , int V_272 , int V_273 )
{
if ( V_282 -> V_14 == V_39 && V_273 ) {
if ( V_282 -> V_253 < V_283 )
return 1 ;
return 0 ;
}
if ( V_282 -> V_253 < V_272 &&
! V_3 [ V_282 -> V_14 + 1 ] [ V_272 + 1 ] )
return 1 ;
return 0 ;
}
static void F_173 ( struct V_18 * V_19 , unsigned int * V_62 )
{
struct V_4 * V_5 , * V_274 ;
int V_272 = V_148 ;
int V_273 = 0 ;
if ( ! F_174 ( V_19 ) ) {
F_55 ( L_62 , V_19 -> V_20 ) ;
F_5 ( V_19 ) ;
return;
}
V_272 = F_168 ( V_19 , V_272 , & V_273 , V_62 ) ;
V_272 = F_171 ( V_19 , V_272 , & V_273 , V_62 ) ;
if ( V_272 == V_148 )
return;
F_169 (lkb, s, &r->res_grantqueue, lkb_statequeue) {
if ( V_5 -> V_284 && F_172 ( V_5 , V_272 , V_273 ) ) {
if ( V_273 && V_272 == V_39 &&
V_5 -> V_14 == V_39 )
F_32 ( V_19 , V_5 , V_40 ) ;
else
F_32 ( V_19 , V_5 , V_272 ) ;
V_5 -> V_253 = V_272 ;
}
}
}
static int F_175 ( struct V_4 * V_282 , struct V_4 * V_285 )
{
if ( ( V_282 -> V_14 == V_39 && V_285 -> V_13 == V_40 ) ||
( V_282 -> V_14 == V_40 && V_285 -> V_13 == V_39 ) ) {
if ( V_282 -> V_253 < V_283 )
return 1 ;
return 0 ;
}
if ( V_282 -> V_253 < V_285 -> V_13 && ! F_164 ( V_282 , V_285 ) )
return 1 ;
return 0 ;
}
static void F_176 ( struct V_18 * V_19 , struct V_164 * V_166 ,
struct V_4 * V_5 )
{
struct V_4 * V_282 ;
F_7 (gr, head, lkb_statequeue) {
if ( V_282 == V_5 )
continue;
if ( V_282 -> V_284 && F_175 ( V_282 , V_5 ) ) {
F_32 ( V_19 , V_282 , V_5 -> V_13 ) ;
V_282 -> V_253 = V_5 -> V_13 ;
}
}
}
static void F_177 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_176 ( V_19 , & V_19 -> V_79 , V_5 ) ;
}
static void F_178 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_176 ( V_19 , & V_19 -> V_79 , V_5 ) ;
F_176 ( V_19 , & V_19 -> V_80 , V_5 ) ;
}
static int F_179 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_103 = F_59 () ;
if ( F_145 ( V_19 , V_118 ) ) {
F_61 ( V_19 , V_118 ) ;
V_19 -> V_24 = V_5 -> V_8 ;
V_5 -> V_7 = V_19 -> V_20 ;
return 0 ;
}
if ( V_19 -> V_24 && V_19 -> V_24 != V_5 -> V_8 ) {
F_107 ( & V_5 -> V_151 , & V_19 -> V_78 ) ;
return 1 ;
}
if ( V_19 -> V_21 == V_103 ) {
V_5 -> V_7 = 0 ;
return 0 ;
}
if ( V_19 -> V_21 ) {
V_5 -> V_7 = V_19 -> V_21 ;
return 0 ;
}
if ( F_129 ( V_19 ) == V_103 ) {
F_46 ( V_19 -> V_54 , L_63 ,
V_5 -> V_8 , V_19 -> V_21 , V_19 -> V_22 ,
V_19 -> V_26 ) ;
V_19 -> V_21 = V_103 ;
V_19 -> V_20 = 0 ;
V_5 -> V_7 = 0 ;
return 0 ;
}
F_126 ( V_19 ) ;
V_19 -> V_24 = V_5 -> V_8 ;
F_180 ( V_19 , V_5 ) ;
return 1 ;
}
static void F_181 ( struct V_18 * V_19 )
{
struct V_4 * V_5 , * V_286 ;
F_169 (lkb, safe, &r->res_lookup, lkb_rsb_lookup) {
F_123 ( & V_5 -> V_151 ) ;
F_182 ( V_19 , V_5 ) ;
F_183 () ;
}
}
static void F_184 ( struct V_18 * V_19 , int error )
{
struct V_4 * V_5 ;
if ( ! V_19 -> V_24 )
return;
switch ( error ) {
case 0 :
case - V_287 :
V_19 -> V_24 = 0 ;
F_181 ( V_19 ) ;
break;
case - V_73 :
case - V_92 :
case - V_117 :
V_19 -> V_24 = 0 ;
if ( ! F_6 ( & V_19 -> V_78 ) ) {
V_5 = F_162 ( V_19 -> V_78 . V_219 , struct V_4 ,
V_151 ) ;
F_123 ( & V_5 -> V_151 ) ;
V_19 -> V_24 = V_5 -> V_8 ;
F_182 ( V_19 , V_5 ) ;
}
break;
default:
F_60 ( V_19 -> V_54 , L_64 , error ) ;
}
}
static int F_185 ( int V_167 , struct V_288 * V_289 , T_1 V_102 ,
int V_290 , unsigned long V_291 ,
void (* F_186) ( void * V_292 ) ,
void * V_292 ,
void (* F_187) ( void * V_292 , int V_167 ) ,
struct V_293 * args )
{
int V_43 = - V_123 ;
if ( V_167 < 0 || V_167 > V_283 )
goto V_111;
if ( ! ( V_102 & V_294 ) && ( V_290 > V_84 ) )
goto V_111;
if ( V_102 & V_295 )
goto V_111;
if ( V_102 & V_266 && ! ( V_102 & V_294 ) )
goto V_111;
if ( V_102 & V_271 && ! ( V_102 & V_294 ) )
goto V_111;
if ( V_102 & V_271 && V_102 & V_32 )
goto V_111;
if ( V_102 & V_265 && V_102 & V_294 )
goto V_111;
if ( V_102 & V_265 && V_102 & V_266 )
goto V_111;
if ( V_102 & V_265 && V_102 & V_32 )
goto V_111;
if ( V_102 & V_265 && V_167 != V_254 )
goto V_111;
if ( ! F_186 || ! V_289 )
goto V_111;
if ( V_102 & V_244 && ! V_289 -> V_296 )
goto V_111;
if ( V_102 & V_294 && ! V_289 -> V_297 )
goto V_111;
args -> V_102 = V_102 ;
args -> V_298 = F_186 ;
args -> V_292 = V_292 ;
args -> V_299 = F_187 ;
args -> V_300 = V_291 ;
args -> V_167 = V_167 ;
args -> V_289 = V_289 ;
V_43 = 0 ;
V_111:
return V_43 ;
}
static int F_188 ( T_1 V_102 , void * V_301 , struct V_293 * args )
{
if ( V_102 & ~ ( V_295 | V_244 | V_247 |
V_302 ) )
return - V_123 ;
if ( V_102 & V_295 && V_102 & V_302 )
return - V_123 ;
args -> V_102 = V_102 ;
args -> V_292 = V_301 ;
return 0 ;
}
static int F_189 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_293 * args )
{
int V_43 = - V_123 ;
if ( args -> V_102 & V_294 ) {
if ( V_5 -> V_11 & V_38 )
goto V_111;
if ( args -> V_102 & V_266 &&
! V_303 [ V_5 -> V_14 + 1 ] [ args -> V_167 + 1 ] )
goto V_111;
V_43 = - V_200 ;
if ( V_5 -> V_12 != V_37 )
goto V_111;
if ( V_5 -> V_15 )
goto V_111;
if ( F_27 ( V_5 ) )
goto V_111;
}
V_5 -> V_10 = args -> V_102 ;
V_5 -> V_34 = 0 ;
V_5 -> V_304 = args -> V_298 ;
V_5 -> V_305 = args -> V_292 ;
V_5 -> V_284 = args -> V_299 ;
V_5 -> V_13 = args -> V_167 ;
V_5 -> V_306 = args -> V_289 ;
V_5 -> V_163 = args -> V_289 -> V_296 ;
V_5 -> V_307 = ( int ) V_308 -> V_309 ;
V_5 -> V_238 = args -> V_300 ;
V_43 = 0 ;
V_111:
if ( V_43 )
F_46 ( V_30 , L_65 ,
V_43 , V_5 -> V_8 , V_5 -> V_11 , args -> V_102 ,
V_5 -> V_12 , V_5 -> V_15 ,
V_5 -> V_146 -> V_26 ) ;
return V_43 ;
}
static int F_190 ( struct V_4 * V_5 , struct V_293 * args )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int V_43 = - V_123 ;
if ( V_5 -> V_11 & V_38 ) {
F_60 ( V_30 , L_66 , V_5 -> V_8 ) ;
F_2 ( V_5 ) ;
goto V_111;
}
if ( V_5 -> V_11 & V_310 ) {
F_46 ( V_30 , L_67 , V_5 -> V_8 ) ;
V_43 = - V_162 ;
goto V_111;
}
if ( ! F_6 ( & V_5 -> V_151 ) ) {
if ( args -> V_102 & ( V_295 | V_302 ) ) {
F_46 ( V_30 , L_68 , V_5 -> V_8 ) ;
F_123 ( & V_5 -> V_151 ) ;
F_28 ( V_5 -> V_146 , V_5 ,
args -> V_102 & V_295 ?
- V_44 : - V_50 ) ;
F_102 ( V_5 ) ;
}
V_43 = - V_200 ;
goto V_111;
}
if ( args -> V_102 & V_295 ) {
if ( V_5 -> V_10 & V_295 )
goto V_111;
if ( F_27 ( V_5 ) )
goto V_111;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_211 ) {
V_5 -> V_11 |= V_42 ;
V_43 = - V_200 ;
goto V_111;
}
if ( V_5 -> V_12 == V_37 &&
! V_5 -> V_15 ) {
V_43 = - V_200 ;
goto V_111;
}
switch ( V_5 -> V_15 ) {
case V_185 :
case V_177 :
V_5 -> V_11 |= V_42 ;
V_43 = - V_200 ;
goto V_111;
case V_181 :
case V_183 :
goto V_111;
}
goto V_311;
}
if ( args -> V_102 & V_302 ) {
if ( V_5 -> V_10 & V_302 )
goto V_111;
if ( F_25 ( V_5 ) )
goto V_111;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_211 ) {
V_5 -> V_11 |= V_41 ;
V_43 = - V_200 ;
goto V_111;
}
switch ( V_5 -> V_15 ) {
case V_185 :
case V_177 :
V_5 -> V_11 |= V_41 ;
V_43 = - V_200 ;
goto V_111;
case V_181 :
goto V_111;
}
goto V_311;
}
V_43 = - V_200 ;
if ( V_5 -> V_15 || V_5 -> V_201 )
goto V_111;
V_311:
V_5 -> V_10 |= args -> V_102 ;
V_5 -> V_34 = 0 ;
V_5 -> V_305 = args -> V_292 ;
V_43 = 0 ;
V_111:
if ( V_43 )
F_46 ( V_30 , L_69 , V_43 ,
V_5 -> V_8 , V_5 -> V_11 , V_5 -> V_10 ,
args -> V_102 , V_5 -> V_15 ,
V_5 -> V_146 -> V_26 ) ;
return V_43 ;
}
static int F_191 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error = 0 ;
if ( F_167 ( V_19 , V_5 , 1 , 0 , NULL ) ) {
F_155 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_111;
}
if ( F_14 ( V_5 ) ) {
error = - V_287 ;
F_105 ( V_19 , V_5 , V_172 ) ;
F_135 ( V_5 ) ;
goto V_111;
}
error = - V_73 ;
F_28 ( V_19 , V_5 , - V_73 ) ;
V_111:
return error ;
}
static void F_192 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case - V_73 :
if ( F_15 ( V_5 ) )
F_178 ( V_19 , V_5 ) ;
break;
case - V_287 :
F_177 ( V_19 , V_5 ) ;
break;
}
}
static int F_193 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error = 0 ;
int V_281 = 0 ;
if ( F_167 ( V_19 , V_5 , 1 , 0 , & V_281 ) ) {
F_155 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_111;
}
if ( V_281 ) {
F_152 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_48 ) ;
error = - V_48 ;
goto V_111;
}
if ( F_16 ( V_5 ) ) {
F_168 ( V_19 , V_148 , NULL , NULL ) ;
if ( F_166 ( V_19 , V_5 , 1 , 0 ) ) {
F_155 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_111;
}
}
if ( F_14 ( V_5 ) ) {
error = - V_287 ;
F_108 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_174 ) ;
F_135 ( V_5 ) ;
goto V_111;
}
error = - V_73 ;
F_28 ( V_19 , V_5 , - V_73 ) ;
V_111:
return error ;
}
static void F_194 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case 0 :
F_173 ( V_19 , NULL ) ;
break;
case - V_73 :
if ( F_15 ( V_5 ) )
F_178 ( V_19 , V_5 ) ;
break;
case - V_287 :
F_177 ( V_19 , V_5 ) ;
break;
}
}
static int F_195 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_150 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_50 ) ;
return - V_50 ;
}
static void F_196 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
F_173 ( V_19 , NULL ) ;
}
static int V_235 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_152 ( V_19 , V_5 ) ;
if ( error ) {
F_28 ( V_19 , V_5 , - V_44 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_197 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
if ( error )
F_173 ( V_19 , NULL ) ;
}
static int F_182 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_179 ( V_19 , V_5 ) ;
if ( error < 0 )
goto V_111;
if ( error ) {
error = 0 ;
goto V_111;
}
if ( F_19 ( V_19 ) ) {
error = F_198 ( V_19 , V_5 ) ;
} else {
error = F_191 ( V_19 , V_5 ) ;
F_192 ( V_19 , V_5 , error ) ;
}
V_111:
return error ;
}
static int F_199 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_200 ( V_19 , V_5 ) ;
} else {
error = F_193 ( V_19 , V_5 ) ;
F_194 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_201 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_202 ( V_19 , V_5 ) ;
} else {
error = F_195 ( V_19 , V_5 ) ;
F_196 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_139 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_203 ( V_19 , V_5 ) ;
} else {
error = V_235 ( V_19 , V_5 ) ;
F_197 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_204 ( struct V_29 * V_30 , struct V_4 * V_5 , char * V_70 ,
int V_71 , struct V_293 * args )
{
struct V_18 * V_19 ;
int error ;
error = F_189 ( V_30 , V_5 , args ) ;
if ( error )
return error ;
error = F_67 ( V_30 , V_70 , V_71 , 0 , V_109 , & V_19 ) ;
if ( error )
return error ;
F_73 ( V_19 ) ;
F_86 ( V_19 , V_5 ) ;
V_5 -> V_306 -> V_297 = V_5 -> V_8 ;
error = F_182 ( V_19 , V_5 ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
static int F_205 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_293 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_189 ( V_30 , V_5 , args ) ;
if ( error )
goto V_111;
error = F_199 ( V_19 , V_5 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
static int F_206 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_293 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_190 ( V_5 , args ) ;
if ( error )
goto V_111;
error = F_201 ( V_19 , V_5 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
static int F_207 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_293 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_190 ( V_5 , args ) ;
if ( error )
goto V_111;
error = F_139 ( V_19 , V_5 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
int F_208 ( T_7 * V_312 ,
int V_167 ,
struct V_288 * V_289 ,
T_1 V_102 ,
void * V_70 ,
unsigned int V_290 ,
T_1 V_313 ,
void (* F_186) ( void * V_301 ) ,
void * V_301 ,
void (* F_187) ( void * V_301 , int V_167 ) )
{
struct V_29 * V_30 ;
struct V_4 * V_5 ;
struct V_293 args ;
int error , V_314 = V_102 & V_294 ;
V_30 = F_209 ( V_312 ) ;
if ( ! V_30 )
return - V_123 ;
F_8 ( V_30 ) ;
if ( V_314 )
error = F_94 ( V_30 , V_289 -> V_297 , & V_5 ) ;
else
error = F_88 ( V_30 , & V_5 ) ;
if ( error )
goto V_111;
error = F_185 ( V_167 , V_289 , V_102 , V_290 , 0 , F_186 ,
V_301 , F_187 , & args ) ;
if ( error )
goto V_315;
if ( V_314 )
error = F_205 ( V_30 , V_5 , & args ) ;
else
error = F_204 ( V_30 , V_5 , V_70 , V_290 , & args ) ;
if ( error == - V_287 )
error = 0 ;
V_315:
if ( V_314 || error )
F_97 ( V_30 , V_5 ) ;
if ( error == - V_73 || error == - V_48 )
error = 0 ;
V_111:
F_10 ( V_30 ) ;
F_210 ( V_30 ) ;
return error ;
}
int F_211 ( T_7 * V_312 ,
T_1 V_161 ,
T_1 V_102 ,
struct V_288 * V_289 ,
void * V_301 )
{
struct V_29 * V_30 ;
struct V_4 * V_5 ;
struct V_293 args ;
int error ;
V_30 = F_209 ( V_312 ) ;
if ( ! V_30 )
return - V_123 ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
error = F_188 ( V_102 , V_301 , & args ) ;
if ( error )
goto V_315;
if ( V_102 & V_295 )
error = F_207 ( V_30 , V_5 , & args ) ;
else
error = F_206 ( V_30 , V_5 , & args ) ;
if ( error == - V_50 || error == - V_44 )
error = 0 ;
if ( error == - V_200 && ( V_102 & ( V_295 | V_302 ) ) )
error = 0 ;
V_315:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_210 ( V_30 ) ;
return error ;
}
static int F_212 ( struct V_29 * V_30 , int V_316 ,
int V_199 , int V_176 ,
struct V_204 * * V_317 ,
struct V_318 * * V_319 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
char * V_321 ;
V_320 = F_213 ( V_199 , V_316 , V_157 , & V_321 ) ;
if ( ! V_320 )
return - V_322 ;
memset ( V_321 , 0 , V_316 ) ;
V_205 = (struct V_204 * ) V_321 ;
V_205 -> V_209 . V_323 = ( V_324 | V_325 ) ;
V_205 -> V_209 . V_326 = V_30 -> V_327 ;
V_205 -> V_209 . V_210 = F_59 () ;
V_205 -> V_209 . V_328 = V_316 ;
V_205 -> V_209 . V_329 = V_330 ;
V_205 -> V_214 = V_176 ;
* V_319 = V_320 ;
* V_317 = V_205 ;
return 0 ;
}
static int F_214 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_199 , int V_176 ,
struct V_204 * * V_317 ,
struct V_318 * * V_319 )
{
int V_316 = sizeof( struct V_204 ) ;
switch ( V_176 ) {
case V_177 :
case V_185 :
case V_331 :
V_316 += V_19 -> V_76 ;
break;
case V_179 :
case V_181 :
case V_178 :
case V_180 :
case V_255 :
if ( V_5 && V_5 -> V_163 )
V_316 += V_19 -> V_54 -> V_242 ;
break;
}
return F_212 ( V_19 -> V_54 , V_316 , V_199 , V_176 ,
V_317 , V_319 ) ;
}
static int F_215 ( struct V_318 * V_320 , struct V_204 * V_205 )
{
F_216 ( V_205 ) ;
F_217 ( V_320 ) ;
return 0 ;
}
static void F_218 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
V_205 -> V_332 = V_5 -> V_7 ;
V_205 -> V_333 = V_5 -> V_307 ;
V_205 -> V_334 = V_5 -> V_8 ;
V_205 -> V_335 = V_5 -> V_9 ;
V_205 -> V_336 = V_5 -> V_10 ;
V_205 -> V_337 = V_5 -> V_34 ;
V_205 -> V_212 = V_5 -> V_11 ;
V_205 -> V_252 = V_5 -> V_245 ;
V_205 -> V_338 = V_5 -> V_12 ;
V_205 -> V_339 = V_5 -> V_14 ;
V_205 -> V_340 = V_5 -> V_13 ;
V_205 -> V_341 = V_19 -> V_119 ;
if ( V_5 -> V_284 )
V_205 -> V_342 |= V_52 ;
if ( V_5 -> V_304 )
V_205 -> V_342 |= V_49 ;
switch ( V_205 -> V_214 ) {
case V_177 :
case V_185 :
memcpy ( V_205 -> V_251 , V_19 -> V_26 , V_19 -> V_76 ) ;
break;
case V_179 :
case V_181 :
case V_178 :
case V_180 :
case V_255 :
if ( ! V_5 -> V_163 )
break;
memcpy ( V_205 -> V_251 , V_5 -> V_163 , V_19 -> V_54 -> V_242 ) ;
break;
}
}
static int F_219 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_176 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int V_199 , error ;
V_199 = V_19 -> V_20 ;
error = F_121 ( V_5 , V_176 , V_199 ) ;
if ( error )
return error ;
error = F_214 ( V_19 , V_5 , V_199 , V_176 , & V_205 , & V_320 ) ;
if ( error )
goto V_343;
F_218 ( V_19 , V_5 , V_205 ) ;
error = F_215 ( V_320 , V_205 ) ;
if ( error )
goto V_343;
return 0 ;
V_343:
F_124 ( V_5 , F_110 ( V_176 ) ) ;
return error ;
}
static int F_198 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_219 ( V_19 , V_5 , V_177 ) ;
}
static int F_200 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_219 ( V_19 , V_5 , V_179 ) ;
if ( ! error && F_24 ( V_5 ) ) {
F_124 ( V_5 , V_180 ) ;
V_19 -> V_54 -> V_344 . V_212 = V_213 ;
V_19 -> V_54 -> V_344 . V_214 = V_180 ;
V_19 -> V_54 -> V_344 . V_208 = 0 ;
F_220 ( V_19 , V_5 , & V_19 -> V_54 -> V_344 ) ;
}
return error ;
}
static int F_202 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_219 ( V_19 , V_5 , V_181 ) ;
}
static int F_203 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_219 ( V_19 , V_5 , V_183 ) ;
}
static int F_158 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int V_199 , error ;
V_199 = V_5 -> V_7 ;
error = F_214 ( V_19 , V_5 , V_199 , V_255 , & V_205 , & V_320 ) ;
if ( error )
goto V_111;
F_218 ( V_19 , V_5 , V_205 ) ;
V_205 -> V_208 = 0 ;
error = F_215 ( V_320 , V_205 ) ;
V_111:
return error ;
}
static int F_33 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_167 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int V_199 , error ;
V_199 = V_5 -> V_7 ;
error = F_214 ( V_19 , NULL , V_199 , V_345 , & V_205 , & V_320 ) ;
if ( error )
goto V_111;
F_218 ( V_19 , V_5 , V_205 ) ;
V_205 -> V_346 = V_167 ;
error = F_215 ( V_320 , V_205 ) ;
V_111:
return error ;
}
static int F_180 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int V_199 , error ;
V_199 = F_129 ( V_19 ) ;
error = F_121 ( V_5 , V_185 , V_199 ) ;
if ( error )
return error ;
error = F_214 ( V_19 , NULL , V_199 , V_185 , & V_205 , & V_320 ) ;
if ( error )
goto V_343;
F_218 ( V_19 , V_5 , V_205 ) ;
error = F_215 ( V_320 , V_205 ) ;
if ( error )
goto V_343;
return 0 ;
V_343:
F_124 ( V_5 , V_186 ) ;
return error ;
}
static int F_131 ( struct V_18 * V_19 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int V_199 , error ;
V_199 = F_129 ( V_19 ) ;
error = F_214 ( V_19 , NULL , V_199 , V_331 , & V_205 , & V_320 ) ;
if ( error )
goto V_111;
memcpy ( V_205 -> V_251 , V_19 -> V_26 , V_19 -> V_76 ) ;
V_205 -> V_341 = V_19 -> V_119 ;
error = F_215 ( V_320 , V_205 ) ;
V_111:
return error ;
}
static int F_221 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_176 , int V_43 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int V_199 , error ;
V_199 = V_5 -> V_7 ;
error = F_214 ( V_19 , V_5 , V_199 , V_176 , & V_205 , & V_320 ) ;
if ( error )
goto V_111;
F_218 ( V_19 , V_5 , V_205 ) ;
V_205 -> V_208 = V_43 ;
error = F_215 ( V_320 , V_205 ) ;
V_111:
return error ;
}
static int F_222 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_221 ( V_19 , V_5 , V_178 , V_43 ) ;
}
static int F_223 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_221 ( V_19 , V_5 , V_180 , V_43 ) ;
}
static int F_224 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_221 ( V_19 , V_5 , V_182 , V_43 ) ;
}
static int F_225 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_221 ( V_19 , V_5 , V_184 , V_43 ) ;
}
static int F_226 ( struct V_29 * V_30 , struct V_204 * V_347 ,
int V_348 , int V_43 )
{
struct V_18 * V_19 = & V_30 -> V_349 ;
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int error , V_187 = V_347 -> V_209 . V_210 ;
error = F_214 ( V_19 , NULL , V_187 , V_186 , & V_205 , & V_320 ) ;
if ( error )
goto V_111;
V_205 -> V_334 = V_347 -> V_334 ;
V_205 -> V_208 = V_43 ;
V_205 -> V_332 = V_348 ;
error = F_215 ( V_320 , V_205 ) ;
V_111:
return error ;
}
static void F_227 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
V_5 -> V_10 = V_205 -> V_336 ;
V_5 -> V_34 = V_205 -> V_337 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_205 -> V_212 & 0x0000FFFF ) ;
}
static void F_228 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
if ( V_205 -> V_212 == V_213 )
return;
V_5 -> V_34 = V_205 -> V_337 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_205 -> V_212 & 0x0000FFFF ) ;
}
static int F_148 ( struct V_204 * V_205 )
{
return ( V_205 -> V_209 . V_328 - sizeof( struct V_204 ) ) ;
}
static int F_229 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
int V_71 ;
if ( V_5 -> V_10 & V_244 ) {
if ( ! V_5 -> V_163 )
V_5 -> V_163 = F_144 ( V_30 ) ;
if ( ! V_5 -> V_163 )
return - V_69 ;
V_71 = F_148 ( V_205 ) ;
if ( V_71 > V_30 -> V_242 )
V_71 = V_30 -> V_242 ;
memcpy ( V_5 -> V_163 , V_205 -> V_251 , V_71 ) ;
}
return 0 ;
}
static void F_230 ( void * V_292 , int V_167 )
{
F_55 ( L_70 ) ;
}
static void F_231 ( void * V_292 )
{
F_55 ( L_71 ) ;
}
static int F_232 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
V_5 -> V_7 = V_205 -> V_209 . V_210 ;
V_5 -> V_307 = V_205 -> V_333 ;
V_5 -> V_9 = V_205 -> V_334 ;
V_5 -> V_14 = V_148 ;
V_5 -> V_13 = V_205 -> V_340 ;
V_5 -> V_284 = ( V_205 -> V_342 & V_52 ) ? & F_230 : NULL ;
V_5 -> V_304 = ( V_205 -> V_342 & V_49 ) ? & F_231 : NULL ;
if ( V_5 -> V_10 & V_244 ) {
V_5 -> V_163 = F_144 ( V_30 ) ;
if ( ! V_5 -> V_163 )
return - V_69 ;
}
return 0 ;
}
static int F_233 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
if ( V_5 -> V_12 != V_37 )
return - V_200 ;
if ( F_229 ( V_30 , V_5 , V_205 ) )
return - V_69 ;
V_5 -> V_13 = V_205 -> V_340 ;
V_5 -> V_245 = V_205 -> V_252 ;
return 0 ;
}
static int F_234 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
if ( F_229 ( V_30 , V_5 , V_205 ) )
return - V_69 ;
return 0 ;
}
static void F_235 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 = & V_30 -> V_350 ;
V_5 -> V_7 = V_205 -> V_209 . V_210 ;
V_5 -> V_9 = V_205 -> V_334 ;
}
static int F_236 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
int V_351 = V_205 -> V_209 . V_210 ;
int error = 0 ;
switch ( V_205 -> V_214 ) {
case V_179 :
case V_181 :
case V_183 :
if ( ! F_22 ( V_5 ) || V_5 -> V_7 != V_351 )
error = - V_123 ;
break;
case V_180 :
case V_182 :
case V_184 :
case V_255 :
case V_345 :
if ( ! F_21 ( V_5 ) || V_5 -> V_7 != V_351 )
error = - V_123 ;
break;
case V_178 :
if ( ! F_21 ( V_5 ) )
error = - V_123 ;
else if ( V_5 -> V_7 != - 1 && V_5 -> V_7 != V_351 )
error = - V_123 ;
break;
default:
error = - V_123 ;
}
if ( error )
F_60 ( V_5 -> V_146 -> V_54 ,
L_72 ,
V_205 -> V_214 , V_351 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_11 , V_5 -> V_7 ) ;
return error ;
}
static void F_237 ( struct V_29 * V_30 , char * V_352 , int V_71 )
{
char V_70 [ V_84 + 1 ] ;
struct V_204 * V_205 ;
struct V_318 * V_320 ;
struct V_18 * V_19 ;
T_1 V_98 , V_99 ;
int V_43 , V_100 ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
memcpy ( V_70 , V_352 , V_71 ) ;
V_98 = F_68 ( V_70 , V_71 , 0 ) ;
V_99 = V_98 & ( V_30 -> V_124 - 1 ) ;
V_100 = F_69 ( V_30 , V_98 ) ;
F_60 ( V_30 , L_73 , V_100 , V_70 ) ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_43 = F_52 ( & V_30 -> V_57 [ V_99 ] . V_112 , V_70 , V_71 , & V_19 ) ;
if ( ! V_43 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_60 ( V_30 , L_74 , V_70 ) ;
return;
}
V_43 = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( ! V_43 ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_60 ( V_30 , L_75 , V_70 ) ;
return;
}
F_38 ( & V_30 -> V_216 ) ;
V_30 -> V_217 = V_71 ;
memcpy ( V_30 -> V_218 , V_70 , V_84 ) ;
F_40 ( & V_30 -> V_216 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_43 = F_212 ( V_30 , sizeof( struct V_204 ) + V_71 ,
V_100 , V_331 , & V_205 , & V_320 ) ;
if ( V_43 )
return;
memcpy ( V_205 -> V_251 , V_70 , V_71 ) ;
V_205 -> V_341 = V_98 ;
F_215 ( V_320 , V_205 ) ;
F_38 ( & V_30 -> V_216 ) ;
V_30 -> V_217 = 0 ;
memset ( V_30 -> V_218 , 0 , V_84 ) ;
F_40 ( & V_30 -> V_216 ) ;
}
static int F_238 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int V_101 ;
int error , V_290 = 0 ;
V_101 = V_205 -> V_209 . V_210 ;
error = F_88 ( V_30 , & V_5 ) ;
if ( error )
goto V_343;
F_227 ( V_5 , V_205 ) ;
V_5 -> V_11 |= V_38 ;
error = F_232 ( V_30 , V_5 , V_205 ) ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_343;
}
V_290 = F_148 ( V_205 ) ;
error = F_67 ( V_30 , V_205 -> V_251 , V_290 , V_101 ,
V_108 , & V_19 ) ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_343;
}
F_73 ( V_19 ) ;
if ( V_19 -> V_21 != F_59 () ) {
error = F_71 ( V_30 , V_19 , V_101 ) ;
if ( error ) {
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_97 ( V_30 , V_5 ) ;
goto V_343;
}
}
F_86 ( V_19 , V_5 ) ;
error = F_191 ( V_19 , V_5 ) ;
F_222 ( V_19 , V_5 , error ) ;
F_192 ( V_19 , V_5 , error ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
if ( error == - V_287 )
error = 0 ;
if ( error )
F_100 ( V_5 ) ;
return 0 ;
V_343:
if ( error != - V_117 ) {
F_75 ( V_30 , L_76 ,
V_205 -> V_334 , V_101 , error ) ;
}
if ( V_290 && error == - V_92 ) {
F_237 ( V_30 , V_205 -> V_251 , V_290 ) ;
F_127 ( 1000 ) ;
}
F_235 ( V_30 , V_205 ) ;
F_222 ( & V_30 -> V_349 , & V_30 -> V_350 , error ) ;
return error ;
}
static int F_239 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_353 = 1 ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
goto V_343;
if ( V_5 -> V_9 != V_205 -> V_334 ) {
F_60 ( V_30 , L_77
L_78 , V_5 -> V_8 , V_5 -> V_9 ,
( unsigned long long ) V_5 -> V_17 ,
V_205 -> V_209 . V_210 , V_205 -> V_334 ) ;
error = - V_162 ;
goto V_343;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
F_227 ( V_5 , V_205 ) ;
error = F_233 ( V_30 , V_5 , V_205 ) ;
if ( error ) {
F_223 ( V_19 , V_5 , error ) ;
goto V_111;
}
V_353 = ! F_24 ( V_5 ) ;
error = F_193 ( V_19 , V_5 ) ;
if ( V_353 )
F_223 ( V_19 , V_5 , error ) ;
F_194 ( V_19 , V_5 , error ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
V_343:
F_235 ( V_30 , V_205 ) ;
F_223 ( & V_30 -> V_349 , & V_30 -> V_350 , error ) ;
return error ;
}
static int F_240 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
goto V_343;
if ( V_5 -> V_9 != V_205 -> V_334 ) {
F_60 ( V_30 , L_79 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_205 -> V_209 . V_210 , V_205 -> V_334 ) ;
error = - V_162 ;
goto V_343;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
F_227 ( V_5 , V_205 ) ;
error = F_234 ( V_30 , V_5 , V_205 ) ;
if ( error ) {
F_224 ( V_19 , V_5 , error ) ;
goto V_111;
}
error = F_195 ( V_19 , V_5 ) ;
F_224 ( V_19 , V_5 , error ) ;
F_196 ( V_19 , V_5 , error ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
V_343:
F_235 ( V_30 , V_205 ) ;
F_224 ( & V_30 -> V_349 , & V_30 -> V_350 , error ) ;
return error ;
}
static int F_241 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
goto V_343;
F_227 ( V_5 , V_205 ) ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
error = V_235 ( V_19 , V_5 ) ;
F_225 ( V_19 , V_5 , error ) ;
F_197 ( V_19 , V_5 , error ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
V_343:
F_235 ( V_30 , V_205 ) ;
F_225 ( & V_30 -> V_349 , & V_30 -> V_350 , error ) ;
return error ;
}
static int F_242 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
F_228 ( V_5 , V_205 ) ;
if ( F_17 ( V_5 ) )
F_160 ( V_5 , V_205 ) ;
F_156 ( V_19 , V_5 , V_205 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static int F_243 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
F_32 ( V_19 , V_5 , V_205 -> V_346 ) ;
V_5 -> V_253 = V_205 -> V_346 ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_244 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
int V_71 , error , V_348 , V_101 , V_103 ;
V_101 = V_205 -> V_209 . V_210 ;
V_103 = F_59 () ;
V_71 = F_148 ( V_205 ) ;
error = F_72 ( V_30 , V_101 , V_205 -> V_251 , V_71 , 0 ,
& V_348 , NULL ) ;
if ( ! error && V_348 == V_103 ) {
F_238 ( V_30 , V_205 ) ;
return;
}
F_226 ( V_30 , V_205 , V_348 , error ) ;
}
static void F_245 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
char V_70 [ V_84 + 1 ] ;
struct V_18 * V_19 ;
T_1 V_98 , V_99 ;
int V_43 , V_71 , V_100 , V_101 ;
V_101 = V_205 -> V_209 . V_210 ;
V_71 = F_148 ( V_205 ) ;
if ( V_71 > V_84 ) {
F_60 ( V_30 , L_80 ,
V_101 , V_71 ) ;
return;
}
V_100 = F_69 ( V_30 , V_205 -> V_341 ) ;
if ( V_100 != F_59 () ) {
F_60 ( V_30 , L_81 ,
V_101 , V_100 ) ;
return;
}
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
memcpy ( V_70 , V_205 -> V_251 , V_71 ) ;
V_98 = F_68 ( V_70 , V_71 , 0 ) ;
V_99 = V_98 & ( V_30 -> V_124 - 1 ) ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_43 = F_52 ( & V_30 -> V_57 [ V_99 ] . V_115 , V_70 , V_71 , & V_19 ) ;
if ( V_43 ) {
V_43 = F_52 ( & V_30 -> V_57 [ V_99 ] . V_112 , V_70 , V_71 , & V_19 ) ;
if ( V_43 ) {
F_60 ( V_30 , L_82 ,
V_101 , V_70 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return;
}
if ( V_19 -> V_21 != V_101 ) {
F_60 ( V_30 , L_83 ,
V_101 , V_19 -> V_21 ) ;
F_4 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return;
}
F_46 ( V_30 , L_84 ,
V_101 , V_19 -> V_21 , V_19 -> V_24 ,
V_70 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return;
}
if ( V_19 -> V_21 != V_101 ) {
F_60 ( V_30 , L_85 ,
V_101 , V_19 -> V_21 ) ;
F_4 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return;
}
if ( F_39 ( & V_19 -> V_53 , F_85 ) ) {
F_63 ( & V_19 -> V_74 , & V_30 -> V_57 [ V_99 ] . V_115 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_65 ( V_19 ) ;
} else {
F_60 ( V_30 , L_86 ,
V_101 ) ;
F_4 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
}
}
static void F_246 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
F_247 ( V_30 , V_205 -> V_332 , V_205 -> V_333 ) ;
}
static int F_248 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_176 , V_126 ;
int V_101 = V_205 -> V_209 . V_210 ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
V_176 = V_5 -> V_15 ;
error = F_124 ( V_5 , V_178 ) ;
if ( error ) {
F_60 ( V_30 , L_87 ,
V_5 -> V_8 , V_101 , V_205 -> V_334 , V_205 -> V_208 ) ;
F_5 ( V_19 ) ;
goto V_111;
}
if ( V_176 == V_185 ) {
V_19 -> V_21 = V_101 ;
V_19 -> V_20 = V_101 ;
V_5 -> V_7 = V_101 ;
}
V_126 = V_205 -> V_208 ;
switch ( V_126 ) {
case - V_73 :
F_28 ( V_19 , V_5 , - V_73 ) ;
F_184 ( V_19 , - V_73 ) ;
F_102 ( V_5 ) ;
break;
case - V_287 :
case 0 :
F_228 ( V_5 , V_205 ) ;
V_5 -> V_9 = V_205 -> V_334 ;
if ( F_17 ( V_5 ) )
F_160 ( V_5 , V_205 ) ;
if ( V_126 ) {
F_105 ( V_19 , V_5 , V_172 ) ;
F_135 ( V_5 ) ;
} else {
F_156 ( V_19 , V_5 , V_205 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
}
F_184 ( V_19 , V_126 ) ;
break;
case - V_92 :
case - V_117 :
F_75 ( V_30 , L_88
L_89 , V_5 -> V_8 ,
V_101 , V_126 , V_19 -> V_21 ,
V_19 -> V_22 , V_19 -> V_24 , V_19 -> V_26 ) ;
if ( V_19 -> V_22 != F_59 () &&
V_19 -> V_21 != F_59 () ) {
V_19 -> V_21 = 0 ;
V_19 -> V_20 = - 1 ;
V_5 -> V_7 = - 1 ;
}
if ( F_27 ( V_5 ) ) {
F_31 ( V_19 , V_5 ) ;
F_184 ( V_19 , V_126 ) ;
F_102 ( V_5 ) ;
} else {
F_182 ( V_19 , V_5 ) ;
if ( V_19 -> V_21 == F_59 () )
F_184 ( V_19 , 0 ) ;
}
break;
default:
F_60 ( V_30 , L_90 ,
V_5 -> V_8 , V_126 ) ;
}
if ( F_25 ( V_5 ) && ( V_126 == 0 || V_126 == - V_287 ) ) {
F_46 ( V_30 , L_91 ,
V_5 -> V_8 , V_126 ) ;
V_5 -> V_11 &= ~ V_41 ;
V_5 -> V_11 &= ~ V_42 ;
F_202 ( V_19 , V_5 ) ;
} else if ( F_26 ( V_5 ) && ( V_126 == - V_287 ) ) {
F_46 ( V_30 , L_92 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_41 ;
V_5 -> V_11 &= ~ V_42 ;
F_203 ( V_19 , V_5 ) ;
} else {
V_5 -> V_11 &= ~ V_42 ;
V_5 -> V_11 &= ~ V_41 ;
}
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_220 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_204 * V_205 )
{
switch ( V_205 -> V_208 ) {
case - V_73 :
F_28 ( V_19 , V_5 , - V_73 ) ;
break;
case - V_48 :
F_228 ( V_5 , V_205 ) ;
F_153 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_48 ) ;
break;
case - V_287 :
F_228 ( V_5 , V_205 ) ;
if ( F_16 ( V_5 ) )
F_159 ( V_5 ) ;
F_108 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_174 ) ;
F_135 ( V_5 ) ;
break;
case 0 :
F_228 ( V_5 , V_205 ) ;
if ( F_16 ( V_5 ) )
F_159 ( V_5 ) ;
F_156 ( V_19 , V_5 , V_205 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
break;
default:
F_60 ( V_19 -> V_54 , L_93 ,
V_5 -> V_8 , V_205 -> V_209 . V_210 , V_205 -> V_334 ,
V_205 -> V_208 ) ;
F_4 ( V_19 ) ;
F_2 ( V_5 ) ;
}
}
static void F_249 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
struct V_18 * V_19 = V_5 -> V_146 ;
int error ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
error = F_125 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
F_220 ( V_19 , V_5 , V_205 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static int F_250 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
return error ;
F_249 ( V_5 , V_205 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_251 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
struct V_18 * V_19 = V_5 -> V_146 ;
int error ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
error = F_125 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
switch ( V_205 -> V_208 ) {
case - V_50 :
F_228 ( V_5 , V_205 ) ;
F_151 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_50 ) ;
break;
case - V_162 :
break;
default:
F_60 ( V_19 -> V_54 , L_94 ,
V_5 -> V_8 , V_205 -> V_208 ) ;
}
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static int F_252 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
return error ;
F_251 ( V_5 , V_205 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_253 ( struct V_4 * V_5 , struct V_204 * V_205 )
{
struct V_18 * V_19 = V_5 -> V_146 ;
int error ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_236 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
error = F_125 ( V_5 , V_205 ) ;
if ( error )
goto V_111;
switch ( V_205 -> V_208 ) {
case - V_44 :
F_228 ( V_5 , V_205 ) ;
F_153 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_44 ) ;
break;
case 0 :
break;
default:
F_60 ( V_19 -> V_54 , L_95 ,
V_5 -> V_8 , V_205 -> V_208 ) ;
}
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static int F_254 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
int error ;
error = F_94 ( V_30 , V_205 -> V_335 , & V_5 ) ;
if ( error )
return error ;
F_253 ( V_5 , V_205 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_255 ( struct V_29 * V_30 , struct V_204 * V_205 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_348 ;
int V_354 = 0 ;
error = F_94 ( V_30 , V_205 -> V_334 , & V_5 ) ;
if ( error ) {
F_60 ( V_30 , L_96 , V_205 -> V_334 ) ;
return;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_124 ( V_5 , V_186 ) ;
if ( error )
goto V_111;
V_348 = V_205 -> V_332 ;
if ( V_19 -> V_21 && ( V_19 -> V_21 != V_348 ) ) {
F_60 ( V_30 , L_97
L_98 ,
V_5 -> V_8 , V_205 -> V_209 . V_210 , V_348 ,
V_19 -> V_21 , V_19 -> V_22 ,
F_59 () , V_19 -> V_24 , V_19 -> V_26 ) ;
}
if ( V_348 == F_59 () ) {
V_19 -> V_21 = V_348 ;
V_19 -> V_20 = 0 ;
V_354 = 1 ;
V_19 -> V_24 = 0 ;
} else if ( V_348 == - 1 ) {
F_60 ( V_30 , L_99 ,
V_5 -> V_8 , V_205 -> V_209 . V_210 ) ;
V_19 -> V_21 = 0 ;
V_19 -> V_20 = - 1 ;
V_5 -> V_7 = - 1 ;
} else {
V_19 -> V_21 = V_348 ;
V_19 -> V_20 = V_348 ;
}
if ( F_27 ( V_5 ) ) {
F_46 ( V_30 , L_100 ,
V_5 -> V_8 , V_5 -> V_11 ) ;
F_31 ( V_19 , V_5 ) ;
F_102 ( V_5 ) ;
goto V_355;
}
F_182 ( V_19 , V_5 ) ;
V_355:
if ( V_354 )
F_181 ( V_19 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
}
static void F_256 ( struct V_29 * V_30 , struct V_204 * V_205 ,
T_1 V_356 )
{
int error = 0 , V_357 = 0 ;
if ( ! F_257 ( V_30 , V_205 -> V_209 . V_210 ) ) {
F_75 ( V_30 , L_101 ,
V_205 -> V_214 , V_205 -> V_209 . V_210 , V_205 -> V_334 ,
V_205 -> V_335 , V_205 -> V_208 ) ;
return;
}
switch ( V_205 -> V_214 ) {
case V_177 :
error = F_238 ( V_30 , V_205 ) ;
break;
case V_179 :
error = F_239 ( V_30 , V_205 ) ;
break;
case V_181 :
error = F_240 ( V_30 , V_205 ) ;
break;
case V_183 :
V_357 = 1 ;
error = F_241 ( V_30 , V_205 ) ;
break;
case V_178 :
error = F_248 ( V_30 , V_205 ) ;
break;
case V_180 :
error = F_250 ( V_30 , V_205 ) ;
break;
case V_182 :
error = F_252 ( V_30 , V_205 ) ;
break;
case V_184 :
error = F_254 ( V_30 , V_205 ) ;
break;
case V_255 :
V_357 = 1 ;
error = F_242 ( V_30 , V_205 ) ;
break;
case V_345 :
V_357 = 1 ;
error = F_243 ( V_30 , V_205 ) ;
break;
case V_185 :
F_244 ( V_30 , V_205 ) ;
break;
case V_331 :
F_245 ( V_30 , V_205 ) ;
break;
case V_186 :
F_255 ( V_30 , V_205 ) ;
break;
case V_358 :
F_246 ( V_30 , V_205 ) ;
break;
default:
F_60 ( V_30 , L_102 , V_205 -> V_214 ) ;
}
if ( error == - V_162 && V_357 ) {
F_46 ( V_30 , L_103 ,
V_205 -> V_214 , V_205 -> V_335 , V_205 -> V_209 . V_210 ,
V_205 -> V_334 , V_356 ) ;
} else if ( error == - V_162 ) {
F_60 ( V_30 , L_103 ,
V_205 -> V_214 , V_205 -> V_335 , V_205 -> V_209 . V_210 ,
V_205 -> V_334 , V_356 ) ;
if ( V_205 -> V_214 == V_179 )
F_78 ( V_30 , V_205 -> V_341 ) ;
}
if ( error == - V_123 ) {
F_60 ( V_30 , L_104
L_105 ,
V_205 -> V_214 , V_205 -> V_209 . V_210 ,
V_205 -> V_334 , V_205 -> V_335 , V_356 ) ;
}
}
static void F_258 ( struct V_29 * V_30 , struct V_204 * V_205 ,
int V_187 )
{
if ( F_133 ( V_30 ) ) {
if ( ! V_30 -> V_359 ) {
F_75 ( V_30 , L_106 ,
V_205 -> V_214 , V_187 ) ;
return;
}
F_259 ( V_30 , V_187 , V_205 ) ;
} else {
F_260 ( V_30 ) ;
F_256 ( V_30 , V_205 , 0 ) ;
}
}
void F_261 ( struct V_29 * V_30 , struct V_204 * V_205 ,
T_1 V_356 )
{
F_256 ( V_30 , V_205 , V_356 ) ;
}
void F_262 ( union V_360 * V_361 , int V_187 )
{
struct V_362 * V_363 = & V_361 -> V_364 ;
struct V_29 * V_30 ;
int type = 0 ;
switch ( V_363 -> V_329 ) {
case V_330 :
F_263 ( & V_361 -> V_365 ) ;
type = V_361 -> V_365 . V_214 ;
break;
case V_366 :
F_264 ( & V_361 -> V_367 ) ;
type = V_361 -> V_367 . V_368 ;
break;
default:
F_55 ( L_107 , V_363 -> V_329 , V_187 ) ;
return;
}
if ( V_363 -> V_210 != V_187 ) {
F_55 ( L_108 ,
V_363 -> V_210 , V_187 , V_363 -> V_326 ) ;
return;
}
V_30 = F_265 ( V_363 -> V_326 ) ;
if ( ! V_30 ) {
if ( V_65 . V_369 ) {
F_266 ( V_370 L_109
L_110 ,
V_363 -> V_326 , V_187 , V_363 -> V_329 , type ) ;
}
if ( V_363 -> V_329 == V_366 && type == V_371 )
F_267 ( V_187 , & V_361 -> V_367 ) ;
return;
}
F_9 ( & V_30 -> V_372 ) ;
if ( V_363 -> V_329 == V_330 )
F_258 ( V_30 , & V_361 -> V_365 , V_187 ) ;
else
F_268 ( V_30 , & V_361 -> V_367 , V_187 ) ;
F_11 ( & V_30 -> V_372 ) ;
F_210 ( V_30 ) ;
}
static void F_269 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_204 * V_373 )
{
if ( F_23 ( V_5 ) ) {
F_101 ( V_5 ) ;
memset ( V_373 , 0 , sizeof( struct V_204 ) ) ;
V_373 -> V_212 = V_213 ;
V_373 -> V_214 = V_180 ;
V_373 -> V_208 = - V_287 ;
V_373 -> V_209 . V_210 = V_5 -> V_7 ;
F_249 ( V_5 , V_373 ) ;
V_5 -> V_14 = V_148 ;
F_62 ( V_5 -> V_146 , V_374 ) ;
F_102 ( V_5 ) ;
} else if ( V_5 -> V_13 >= V_5 -> V_14 ) {
V_5 -> V_11 |= V_211 ;
}
}
static int F_270 ( struct V_29 * V_30 , struct V_4 * V_5 ,
int V_100 )
{
if ( F_70 ( V_30 ) )
return 1 ;
if ( F_74 ( V_30 , V_5 -> V_16 ) )
return 1 ;
return 0 ;
}
void F_271 ( struct V_29 * V_30 )
{
struct V_4 * V_5 , * V_286 ;
struct V_204 * V_373 ;
int V_375 , V_376 , V_377 ;
int V_100 ;
V_373 = F_272 ( sizeof( struct V_204 ) , V_198 ) ;
if ( ! V_373 ) {
F_60 ( V_30 , L_111 ) ;
return;
}
F_114 ( & V_30 -> V_196 ) ;
F_169 (lkb, safe, &ls->ls_waiters, lkb_wait_reply) {
V_100 = F_129 ( V_5 -> V_146 ) ;
if ( V_5 -> V_15 != V_181 ) {
F_46 ( V_30 , L_112
L_113 ,
V_5 -> V_8 ,
V_5 -> V_9 ,
V_5 -> V_15 ,
V_5 -> V_146 -> V_20 ,
V_5 -> V_7 ,
V_5 -> V_16 ,
V_100 ) ;
}
if ( V_5 -> V_15 == V_185 ) {
V_5 -> V_11 |= V_211 ;
continue;
}
if ( ! F_270 ( V_30 , V_5 , V_100 ) )
continue;
V_375 = V_5 -> V_15 ;
V_376 = - V_50 ;
V_377 = - V_44 ;
if ( ! V_375 ) {
if ( F_26 ( V_5 ) ) {
V_375 = V_183 ;
if ( V_5 -> V_14 == V_148 )
V_377 = 0 ;
}
if ( F_25 ( V_5 ) ) {
V_375 = V_181 ;
if ( V_5 -> V_14 == V_148 )
V_376 = - V_162 ;
}
F_46 ( V_30 , L_114 ,
V_5 -> V_8 , V_5 -> V_11 , V_375 ,
V_377 , V_376 ) ;
}
switch ( V_375 ) {
case V_177 :
V_5 -> V_11 |= V_211 ;
break;
case V_179 :
F_269 ( V_30 , V_5 , V_373 ) ;
break;
case V_181 :
F_101 ( V_5 ) ;
memset ( V_373 , 0 , sizeof( struct V_204 ) ) ;
V_373 -> V_212 = V_213 ;
V_373 -> V_214 = V_182 ;
V_373 -> V_208 = V_376 ;
V_373 -> V_209 . V_210 = V_5 -> V_7 ;
F_251 ( V_5 , V_373 ) ;
F_100 ( V_5 ) ;
break;
case V_183 :
F_101 ( V_5 ) ;
memset ( V_373 , 0 , sizeof( struct V_204 ) ) ;
V_373 -> V_212 = V_213 ;
V_373 -> V_214 = V_184 ;
V_373 -> V_208 = V_377 ;
V_373 -> V_209 . V_210 = V_5 -> V_7 ;
F_253 ( V_5 , V_373 ) ;
F_100 ( V_5 ) ;
break;
default:
F_60 ( V_30 , L_115 ,
V_5 -> V_15 , V_375 ) ;
}
F_183 () ;
}
F_119 ( & V_30 -> V_196 ) ;
F_120 ( V_373 ) ;
}
static struct V_4 * F_273 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
int V_91 = 0 ;
F_114 ( & V_30 -> V_196 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( V_5 -> V_11 & V_211 ) {
F_101 ( V_5 ) ;
V_91 = 1 ;
break;
}
}
F_119 ( & V_30 -> V_196 ) ;
if ( ! V_91 )
V_5 = NULL ;
return V_5 ;
}
int F_274 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error = 0 , V_176 , V_268 , V_378 , V_379 ;
while ( 1 ) {
if ( F_133 ( V_30 ) ) {
F_46 ( V_30 , L_116 ) ;
error = - V_380 ;
break;
}
V_5 = F_273 ( V_30 ) ;
if ( ! V_5 )
break;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
V_176 = V_5 -> V_15 ;
V_378 = F_26 ( V_5 ) ;
V_379 = F_25 ( V_5 ) ;
V_268 = 0 ;
F_46 ( V_30 , L_112
L_117
L_118 , V_5 -> V_8 , V_5 -> V_9 , V_176 ,
V_19 -> V_20 , V_5 -> V_7 , V_5 -> V_16 ,
F_129 ( V_19 ) , V_378 , V_379 ) ;
V_5 -> V_11 &= ~ V_211 ;
V_5 -> V_11 &= ~ V_41 ;
V_5 -> V_11 &= ~ V_42 ;
V_5 -> V_15 = 0 ;
V_5 -> V_201 = 0 ;
F_114 ( & V_30 -> V_196 ) ;
F_123 ( & V_5 -> V_202 ) ;
F_119 ( & V_30 -> V_196 ) ;
F_102 ( V_5 ) ;
if ( V_378 || V_379 ) {
switch ( V_176 ) {
case V_185 :
case V_177 :
F_28 ( V_19 , V_5 , V_379 ? - V_50 :
- V_44 ) ;
F_102 ( V_5 ) ;
break;
case V_179 :
if ( V_378 ) {
F_28 ( V_19 , V_5 , - V_44 ) ;
} else {
V_5 -> V_10 |= V_302 ;
F_201 ( V_19 , V_5 ) ;
}
break;
default:
V_268 = 1 ;
}
} else {
switch ( V_176 ) {
case V_185 :
case V_177 :
F_182 ( V_19 , V_5 ) ;
if ( F_174 ( V_19 ) )
F_184 ( V_19 , 0 ) ;
break;
case V_179 :
F_199 ( V_19 , V_5 ) ;
break;
default:
V_268 = 1 ;
}
}
if ( V_268 ) {
F_60 ( V_30 , L_119
L_120 ,
V_5 -> V_8 , V_176 , V_19 -> V_20 ,
F_129 ( V_19 ) , V_378 , V_379 ) ;
}
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
}
return error ;
}
static void F_275 ( struct V_29 * V_30 , struct V_18 * V_19 ,
struct V_164 * V_381 )
{
struct V_4 * V_5 , * V_286 ;
F_169 (lkb, safe, list, lkb_statequeue) {
if ( ! F_22 ( V_5 ) )
continue;
if ( V_5 -> V_17 == V_30 -> V_382 )
continue;
F_108 ( V_19 , V_5 ) ;
if ( ! F_100 ( V_5 ) )
F_60 ( V_30 , L_121 ) ;
}
}
void F_276 ( struct V_18 * V_19 )
{
struct V_29 * V_30 = V_19 -> V_54 ;
F_275 ( V_30 , V_19 , & V_19 -> V_79 ) ;
F_275 ( V_30 , V_19 , & V_19 -> V_80 ) ;
F_275 ( V_30 , V_19 , & V_19 -> V_81 ) ;
}
static void F_277 ( struct V_29 * V_30 , struct V_18 * V_19 ,
struct V_164 * V_381 ,
int V_383 , unsigned int * V_62 )
{
struct V_4 * V_5 , * V_286 ;
F_169 (lkb, safe, list, lkb_statequeue) {
if ( ! F_22 ( V_5 ) )
continue;
if ( ( V_5 -> V_7 == V_383 ) ||
F_74 ( V_30 , V_5 -> V_7 ) ) {
if ( ( V_5 -> V_10 & V_244 ) &&
( V_5 -> V_14 >= V_250 ) ) {
F_62 ( V_19 , V_384 ) ;
}
F_108 ( V_19 , V_5 ) ;
if ( ! F_100 ( V_5 ) )
F_60 ( V_30 , L_122 ) ;
F_62 ( V_19 , V_275 ) ;
( * V_62 ) ++ ;
}
}
}
void F_278 ( struct V_29 * V_30 )
{
struct V_18 * V_19 ;
struct V_385 * V_386 ;
int V_387 = 0 ;
int V_383 = 0 ;
unsigned int V_388 = 0 ;
F_7 (memb, &ls->ls_nodes_gone, list) {
V_387 ++ ;
V_383 = V_386 -> V_187 ;
}
if ( ! V_387 )
return;
F_279 ( & V_30 -> V_389 ) ;
F_7 (r, &ls->ls_root_list, res_root_list) {
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
if ( F_174 ( V_19 ) ) {
F_277 ( V_30 , V_19 , & V_19 -> V_79 ,
V_383 , & V_388 ) ;
F_277 ( V_30 , V_19 , & V_19 -> V_80 ,
V_383 , & V_388 ) ;
F_277 ( V_30 , V_19 , & V_19 -> V_81 ,
V_383 , & V_388 ) ;
}
F_77 ( V_19 ) ;
F_84 ( V_19 ) ;
F_134 () ;
}
F_280 ( & V_30 -> V_389 ) ;
if ( V_388 )
F_281 ( V_30 , L_123 ,
V_388 , V_387 ) ;
}
static struct V_18 * F_282 ( struct V_29 * V_30 , int V_55 )
{
struct V_75 * V_140 ;
struct V_18 * V_19 ;
F_38 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
for ( V_140 = F_79 ( & V_30 -> V_57 [ V_55 ] . V_112 ) ; V_140 ; V_140 = F_80 ( V_140 ) ) {
V_19 = F_53 ( V_140 , struct V_18 , V_74 ) ;
if ( ! F_145 ( V_19 , V_275 ) )
continue;
if ( ! F_174 ( V_19 ) ) {
F_61 ( V_19 , V_275 ) ;
continue;
}
F_34 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
return V_19 ;
}
F_40 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
return NULL ;
}
void F_283 ( struct V_29 * V_30 )
{
struct V_18 * V_19 ;
int V_55 = 0 ;
unsigned int V_62 = 0 ;
unsigned int V_390 = 0 ;
unsigned int V_388 = 0 ;
while ( 1 ) {
V_19 = F_282 ( V_30 , V_55 ) ;
if ( ! V_19 ) {
if ( V_55 == V_30 -> V_124 - 1 )
break;
V_55 ++ ;
continue;
}
V_390 ++ ;
V_62 = 0 ;
F_73 ( V_19 ) ;
F_173 ( V_19 , & V_62 ) ;
F_61 ( V_19 , V_275 ) ;
V_388 += V_62 ;
F_184 ( V_19 , 0 ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_134 () ;
}
if ( V_388 )
F_281 ( V_30 , L_124 ,
V_388 , V_390 ) ;
}
static struct V_4 * F_284 ( struct V_164 * V_166 , int V_187 ,
T_1 V_391 )
{
struct V_4 * V_5 ;
F_7 (lkb, head, lkb_statequeue) {
if ( V_5 -> V_7 == V_187 && V_5 -> V_9 == V_391 )
return V_5 ;
}
return NULL ;
}
static struct V_4 * F_285 ( struct V_18 * V_19 , int V_187 ,
T_1 V_391 )
{
struct V_4 * V_5 ;
V_5 = F_284 ( & V_19 -> V_79 , V_187 , V_391 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_284 ( & V_19 -> V_80 , V_187 , V_391 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_284 ( & V_19 -> V_81 , V_187 , V_391 ) ;
if ( V_5 )
return V_5 ;
return NULL ;
}
static int F_286 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_18 * V_19 , struct V_392 * V_88 )
{
struct V_393 * V_394 = (struct V_393 * ) V_88 -> V_395 ;
V_5 -> V_7 = V_88 -> V_396 . V_210 ;
V_5 -> V_307 = F_287 ( V_394 -> V_397 ) ;
V_5 -> V_9 = F_287 ( V_394 -> V_398 ) ;
V_5 -> V_10 = F_287 ( V_394 -> V_399 ) ;
V_5 -> V_11 = F_287 ( V_394 -> V_400 ) & 0x0000FFFF ;
V_5 -> V_11 |= V_38 ;
V_5 -> V_245 = F_287 ( V_394 -> V_401 ) ;
V_5 -> V_13 = V_394 -> V_402 ;
V_5 -> V_14 = V_394 -> V_403 ;
V_5 -> V_284 = ( V_394 -> V_404 & V_52 ) ? & F_230 : NULL ;
V_5 -> V_304 = ( V_394 -> V_404 & V_49 ) ? & F_231 : NULL ;
if ( V_5 -> V_10 & V_244 ) {
int V_405 = V_88 -> V_396 . V_328 - sizeof( struct V_392 ) -
sizeof( struct V_393 ) ;
if ( V_405 > V_30 -> V_242 )
return - V_123 ;
V_5 -> V_163 = F_144 ( V_30 ) ;
if ( ! V_5 -> V_163 )
return - V_69 ;
memcpy ( V_5 -> V_163 , V_394 -> V_406 , V_405 ) ;
}
if ( V_394 -> V_407 == F_288 ( V_179 ) &&
F_23 ( V_5 ) ) {
V_394 -> V_408 = V_174 ;
V_5 -> V_14 = V_148 ;
F_62 ( V_19 , V_374 ) ;
}
return 0 ;
}
int F_289 ( struct V_29 * V_30 , struct V_392 * V_88 )
{
struct V_393 * V_394 = (struct V_393 * ) V_88 -> V_395 ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
T_1 V_391 = 0 ;
int V_101 = V_88 -> V_396 . V_210 ;
int error ;
if ( V_394 -> V_409 ) {
error = - V_410 ;
goto V_111;
}
V_391 = F_287 ( V_394 -> V_398 ) ;
error = F_67 ( V_30 , V_394 -> V_411 , F_290 ( V_394 -> V_412 ) ,
V_101 , V_122 , & V_19 ) ;
if ( error )
goto V_111;
F_73 ( V_19 ) ;
if ( F_70 ( V_30 ) && ( F_129 ( V_19 ) != F_59 () ) ) {
F_60 ( V_30 , L_125 ,
V_101 , V_391 ) ;
error = - V_92 ;
goto V_114;
}
V_5 = F_285 ( V_19 , V_101 , V_391 ) ;
if ( V_5 ) {
error = - V_97 ;
goto V_413;
}
error = F_88 ( V_30 , & V_5 ) ;
if ( error )
goto V_114;
error = F_286 ( V_30 , V_5 , V_19 , V_88 ) ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_114;
}
F_86 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_394 -> V_408 ) ;
error = 0 ;
V_30 -> V_414 ++ ;
if ( ! F_6 ( & V_19 -> V_81 ) || ! F_6 ( & V_19 -> V_80 ) )
F_62 ( V_19 , V_275 ) ;
V_413:
V_394 -> V_415 = F_291 ( V_5 -> V_8 ) ;
V_5 -> V_17 = V_30 -> V_382 ;
V_114:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
V_111:
if ( error && error != - V_97 )
F_281 ( V_30 , L_126 ,
V_101 , V_391 , error ) ;
V_394 -> V_416 = F_291 ( error ) ;
return error ;
}
int F_292 ( struct V_29 * V_30 , struct V_392 * V_88 )
{
struct V_393 * V_394 = (struct V_393 * ) V_88 -> V_395 ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
T_1 V_161 , V_391 ;
int error , V_126 ;
V_161 = F_287 ( V_394 -> V_398 ) ;
V_391 = F_287 ( V_394 -> V_415 ) ;
V_126 = F_287 ( V_394 -> V_416 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error ) {
F_60 ( V_30 , L_127 ,
V_161 , V_88 -> V_396 . V_210 , V_391 , V_126 ) ;
return error ;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
if ( ! F_21 ( V_5 ) ) {
F_60 ( V_30 , L_128 ,
V_161 , V_88 -> V_396 . V_210 , V_391 , V_126 ) ;
F_5 ( V_19 ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return - V_123 ;
}
switch ( V_126 ) {
case - V_92 :
F_46 ( V_30 , L_129 ,
V_161 , V_88 -> V_396 . V_210 , V_391 , V_126 ) ;
F_293 ( V_19 , V_5 ) ;
goto V_111;
case - V_97 :
case 0 :
V_5 -> V_9 = V_391 ;
break;
default:
F_60 ( V_30 , L_130 ,
V_161 , V_88 -> V_396 . V_210 , V_391 , V_126 ) ;
}
F_294 ( V_19 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
int F_295 ( struct V_29 * V_30 , struct V_417 * V_418 ,
int V_167 , T_1 V_102 , void * V_70 , unsigned int V_290 ,
unsigned long V_291 )
{
struct V_4 * V_5 ;
struct V_293 args ;
int error ;
F_8 ( V_30 ) ;
error = F_88 ( V_30 , & V_5 ) ;
if ( error ) {
F_120 ( V_418 ) ;
goto V_111;
}
if ( V_102 & V_244 ) {
V_418 -> V_289 . V_296 = F_118 ( V_419 , V_157 ) ;
if ( ! V_418 -> V_289 . V_296 ) {
F_120 ( V_418 ) ;
F_97 ( V_30 , V_5 ) ;
error = - V_69 ;
goto V_111;
}
}
error = F_185 ( V_167 , & V_418 -> V_289 , V_102 , V_290 , V_291 ,
F_231 , V_418 , F_230 , & args ) ;
V_5 -> V_11 |= V_420 ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_111;
}
error = F_204 ( V_30 , V_5 , V_70 , V_290 , & args ) ;
switch ( error ) {
case 0 :
break;
case - V_287 :
error = 0 ;
break;
case - V_73 :
error = 0 ;
default:
F_97 ( V_30 , V_5 ) ;
goto V_111;
}
F_38 ( & V_418 -> V_421 -> V_422 ) ;
F_101 ( V_5 ) ;
F_107 ( & V_5 -> V_150 , & V_418 -> V_421 -> V_423 ) ;
F_40 ( & V_418 -> V_421 -> V_422 ) ;
V_111:
F_10 ( V_30 ) ;
return error ;
}
int F_296 ( struct V_29 * V_30 , struct V_417 * V_424 ,
int V_167 , T_1 V_102 , T_1 V_161 , char * V_425 ,
unsigned long V_291 )
{
struct V_4 * V_5 ;
struct V_293 args ;
struct V_417 * V_418 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_418 = V_5 -> V_426 ;
if ( V_102 & V_244 && ! V_418 -> V_289 . V_296 ) {
V_418 -> V_289 . V_296 = F_118 ( V_419 , V_157 ) ;
if ( ! V_418 -> V_289 . V_296 ) {
error = - V_69 ;
goto V_315;
}
}
if ( V_425 && V_418 -> V_289 . V_296 )
memcpy ( V_418 -> V_289 . V_296 , V_425 , V_419 ) ;
V_418 -> V_427 = V_424 -> V_427 ;
V_418 -> V_428 = V_424 -> V_428 ;
V_418 -> V_429 = V_424 -> V_429 ;
V_418 -> V_430 = V_424 -> V_430 ;
V_418 -> V_431 = V_424 -> V_431 ;
V_418 -> V_432 = V_424 -> V_432 ;
error = F_185 ( V_167 , & V_418 -> V_289 , V_102 , 0 , V_291 ,
F_231 , V_418 , F_230 , & args ) ;
if ( error )
goto V_315;
error = F_205 ( V_30 , V_5 , & args ) ;
if ( error == - V_287 || error == - V_73 || error == - V_48 )
error = 0 ;
V_315:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_120 ( V_424 ) ;
return error ;
}
int F_297 ( struct V_29 * V_30 , struct V_417 * V_424 ,
T_1 V_102 , T_1 V_161 , char * V_425 )
{
struct V_4 * V_5 ;
struct V_293 args ;
struct V_417 * V_418 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_418 = V_5 -> V_426 ;
if ( V_425 && V_418 -> V_289 . V_296 )
memcpy ( V_418 -> V_289 . V_296 , V_425 , V_419 ) ;
if ( V_424 -> V_428 )
V_418 -> V_428 = V_424 -> V_428 ;
V_418 -> V_432 = V_424 -> V_432 ;
error = F_188 ( V_102 , V_418 , & args ) ;
if ( error )
goto V_315;
error = F_206 ( V_30 , V_5 , & args ) ;
if ( error == - V_50 )
error = 0 ;
if ( error == - V_200 && ( V_102 & V_302 ) )
error = 0 ;
if ( error )
goto V_315;
F_38 ( & V_418 -> V_421 -> V_422 ) ;
if ( ! F_6 ( & V_5 -> V_150 ) )
F_298 ( & V_5 -> V_150 , & V_418 -> V_421 -> V_433 ) ;
F_40 ( & V_418 -> V_421 -> V_422 ) ;
V_315:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_120 ( V_424 ) ;
return error ;
}
int F_299 ( struct V_29 * V_30 , struct V_417 * V_424 ,
T_1 V_102 , T_1 V_161 )
{
struct V_4 * V_5 ;
struct V_293 args ;
struct V_417 * V_418 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_418 = V_5 -> V_426 ;
if ( V_424 -> V_428 )
V_418 -> V_428 = V_424 -> V_428 ;
V_418 -> V_432 = V_424 -> V_432 ;
error = F_188 ( V_102 , V_418 , & args ) ;
if ( error )
goto V_315;
error = F_207 ( V_30 , V_5 , & args ) ;
if ( error == - V_44 )
error = 0 ;
if ( error == - V_200 )
error = 0 ;
V_315:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_120 ( V_424 ) ;
return error ;
}
int F_300 ( struct V_29 * V_30 , T_1 V_102 , T_1 V_161 )
{
struct V_4 * V_5 ;
struct V_293 args ;
struct V_417 * V_418 ;
struct V_18 * V_19 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_418 = V_5 -> V_426 ;
error = F_188 ( V_102 , V_418 , & args ) ;
if ( error )
goto V_315;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_190 ( V_5 , & args ) ;
if ( error )
goto V_434;
V_5 -> V_11 |= V_47 ;
error = F_139 ( V_19 , V_5 ) ;
V_434:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
if ( error == - V_44 )
error = 0 ;
if ( error == - V_200 )
error = 0 ;
V_315:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
return error ;
}
static int F_301 ( struct V_29 * V_30 , struct V_4 * V_5 )
{
struct V_293 args ;
int error ;
F_101 ( V_5 ) ;
F_114 ( & V_30 -> V_435 ) ;
F_107 ( & V_5 -> V_150 , & V_30 -> V_436 ) ;
F_119 ( & V_30 -> V_435 ) ;
F_188 ( 0 , V_5 -> V_426 , & args ) ;
error = F_207 ( V_30 , V_5 , & args ) ;
if ( error == - V_44 )
error = 0 ;
return error ;
}
static int F_302 ( struct V_29 * V_30 , struct V_4 * V_5 )
{
struct V_293 args ;
int error ;
F_188 ( V_302 | V_247 ,
V_5 -> V_426 , & args ) ;
error = F_206 ( V_30 , V_5 , & args ) ;
if ( error == - V_50 )
error = 0 ;
return error ;
}
static struct V_4 * F_303 ( struct V_29 * V_30 ,
struct V_437 * V_421 )
{
struct V_4 * V_5 = NULL ;
F_114 ( & V_30 -> V_438 ) ;
if ( F_6 ( & V_421 -> V_423 ) )
goto V_111;
V_5 = F_162 ( V_421 -> V_423 . V_219 , struct V_4 , V_150 ) ;
F_123 ( & V_5 -> V_150 ) ;
if ( V_5 -> V_10 & V_439 )
V_5 -> V_11 |= V_440 ;
else
V_5 -> V_11 |= V_441 ;
V_111:
F_119 ( & V_30 -> V_438 ) ;
return V_5 ;
}
void F_304 ( struct V_29 * V_30 , struct V_437 * V_421 )
{
struct V_4 * V_5 , * V_286 ;
F_8 ( V_30 ) ;
while ( 1 ) {
V_5 = F_303 ( V_30 , V_421 ) ;
if ( ! V_5 )
break;
F_29 ( V_5 ) ;
if ( V_5 -> V_10 & V_439 )
F_301 ( V_30 , V_5 ) ;
else
F_302 ( V_30 , V_5 ) ;
F_100 ( V_5 ) ;
}
F_114 ( & V_30 -> V_438 ) ;
F_169 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_123 ( & V_5 -> V_150 ) ;
V_5 -> V_11 |= V_441 ;
F_100 ( V_5 ) ;
}
F_169 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_442 , 0 ,
sizeof( struct V_443 ) * V_444 ) ;
F_123 ( & V_5 -> V_153 ) ;
F_100 ( V_5 ) ;
}
F_119 ( & V_30 -> V_438 ) ;
F_10 ( V_30 ) ;
}
static void F_305 ( struct V_29 * V_30 , struct V_437 * V_421 )
{
struct V_4 * V_5 , * V_286 ;
while ( 1 ) {
V_5 = NULL ;
F_38 ( & V_421 -> V_422 ) ;
if ( ! F_6 ( & V_421 -> V_423 ) ) {
V_5 = F_162 ( V_421 -> V_423 . V_219 , struct V_4 ,
V_150 ) ;
F_123 ( & V_5 -> V_150 ) ;
}
F_40 ( & V_421 -> V_422 ) ;
if ( ! V_5 )
break;
V_5 -> V_11 |= V_441 ;
F_302 ( V_30 , V_5 ) ;
F_100 ( V_5 ) ;
}
F_38 ( & V_421 -> V_422 ) ;
F_169 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_123 ( & V_5 -> V_150 ) ;
V_5 -> V_11 |= V_441 ;
F_100 ( V_5 ) ;
}
F_40 ( & V_421 -> V_422 ) ;
F_38 ( & V_421 -> V_445 ) ;
F_169 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_442 , 0 ,
sizeof( struct V_443 ) * V_444 ) ;
F_123 ( & V_5 -> V_153 ) ;
F_100 ( V_5 ) ;
}
F_40 ( & V_421 -> V_445 ) ;
}
static void F_247 ( struct V_29 * V_30 , int V_187 , int V_309 )
{
struct V_4 * V_5 , * V_286 ;
F_114 ( & V_30 -> V_435 ) ;
F_169 (lkb, safe, &ls->ls_orphans, lkb_ownqueue) {
if ( V_309 && V_5 -> V_307 != V_309 )
continue;
F_302 ( V_30 , V_5 ) ;
F_123 ( & V_5 -> V_150 ) ;
F_100 ( V_5 ) ;
}
F_119 ( & V_30 -> V_435 ) ;
}
static int F_306 ( struct V_29 * V_30 , int V_187 , int V_309 )
{
struct V_204 * V_205 ;
struct V_318 * V_320 ;
int error ;
error = F_212 ( V_30 , sizeof( struct V_204 ) , V_187 ,
V_358 , & V_205 , & V_320 ) ;
if ( error )
return error ;
V_205 -> V_332 = V_187 ;
V_205 -> V_333 = V_309 ;
return F_215 ( V_320 , V_205 ) ;
}
int F_307 ( struct V_29 * V_30 , struct V_437 * V_421 ,
int V_187 , int V_309 )
{
int error = 0 ;
if ( V_187 != F_59 () ) {
error = F_306 ( V_30 , V_187 , V_309 ) ;
} else {
F_8 ( V_30 ) ;
if ( V_309 == V_308 -> V_309 )
F_305 ( V_30 , V_421 ) ;
else
F_247 ( V_30 , V_187 , V_309 ) ;
F_10 ( V_30 ) ;
}
return error ;
}
