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
T_2 V_190 ;
T_2 V_191 = 0 ;
T_3 V_192 = 0 ;
T_3 V_193 = 0 ;
int V_188 = 0 ;
int * V_189 = NULL ;
if ( ! V_65 . V_194 )
return;
F_113 ( & V_30 -> V_195 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( ! V_5 -> V_196 )
continue;
V_192 ++ ;
V_190 = F_114 ( F_115 ( F_106 () , V_5 -> V_196 ) ) ;
if ( V_190 < V_65 . V_194 )
continue;
V_5 -> V_196 = 0 ;
V_193 ++ ;
if ( V_190 > V_191 )
V_191 = V_190 ;
if ( ! V_188 ) {
V_188 = V_30 -> V_132 ;
V_189 = F_116 ( V_188 * sizeof( int ) , V_197 ) ;
}
if ( ! V_189 )
continue;
if ( F_111 ( V_5 -> V_16 , V_188 , V_189 ) )
continue;
F_60 ( V_30 , L_35
L_36 , V_5 -> V_8 , ( long long ) V_190 ,
V_65 . V_194 , V_5 -> V_16 ) ;
}
F_117 ( & V_30 -> V_195 ) ;
F_118 ( V_189 ) ;
if ( V_193 )
F_46 ( V_30 , L_37 ,
V_192 , V_193 ,
V_65 . V_194 , ( long long ) V_191 ) ;
}
static int F_119 ( struct V_4 * V_5 , int V_176 , int V_198 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int error = 0 ;
F_113 ( & V_30 -> V_195 ) ;
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
error = - V_199 ;
goto V_111;
}
V_5 -> V_200 ++ ;
F_101 ( V_5 ) ;
F_46 ( V_30 , L_38 ,
V_5 -> V_8 , V_5 -> V_15 , V_176 ,
V_5 -> V_200 , V_5 -> V_11 ) ;
goto V_111;
}
F_20 (!lkb->lkb_wait_count,
dlm_print_lkb(lkb);
printk(L_39, lkb->lkb_wait_count);) ;
V_5 -> V_200 ++ ;
V_5 -> V_15 = V_176 ;
V_5 -> V_196 = F_106 () ;
V_5 -> V_16 = V_198 ;
F_101 ( V_5 ) ;
F_44 ( & V_5 -> V_201 , & V_30 -> V_202 ) ;
V_111:
if ( error )
F_60 ( V_30 , L_40 ,
V_5 -> V_8 , error , V_5 -> V_11 , V_176 ,
V_5 -> V_15 , V_5 -> V_146 -> V_26 ) ;
F_117 ( & V_30 -> V_195 ) ;
return error ;
}
static int F_120 ( struct V_4 * V_5 , int V_176 ,
struct V_203 * V_204 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int V_205 = 0 ;
if ( F_25 ( V_5 ) && ( V_176 == V_182 ) ) {
F_46 ( V_30 , L_41 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_41 ;
V_205 = 1 ;
goto V_206;
}
if ( F_26 ( V_5 ) && ( V_176 == V_184 ) ) {
F_46 ( V_30 , L_42 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_42 ;
V_205 = 1 ;
goto V_206;
}
if ( ( V_176 == V_184 ) &&
( V_5 -> V_15 != V_183 ) ) {
F_46 ( V_30 , L_43 ,
V_5 -> V_8 , V_5 -> V_15 ) ;
return - 1 ;
}
if ( ( V_176 == V_180 ) &&
( V_5 -> V_15 == V_179 ) &&
F_26 ( V_5 ) && V_204 && ! V_204 -> V_207 ) {
F_46 ( V_30 , L_44 ,
V_5 -> V_8 ) ;
V_5 -> V_15 = 0 ;
V_5 -> V_11 &= ~ V_42 ;
V_5 -> V_200 -- ;
goto V_206;
}
if ( V_5 -> V_15 ) {
V_5 -> V_15 = 0 ;
goto V_206;
}
F_60 ( V_30 , L_45 ,
V_5 -> V_8 , V_204 ? V_204 -> V_208 . V_209 : 0 , V_5 -> V_9 ,
V_176 , V_5 -> V_11 ) ;
return - 1 ;
V_206:
if ( V_205 && V_5 -> V_15 ) {
F_60 ( V_30 , L_46 ,
V_5 -> V_8 , V_176 , V_5 -> V_15 ) ;
V_5 -> V_200 -- ;
V_5 -> V_15 = 0 ;
}
F_20 (lkb->lkb_wait_count, dlm_print_lkb(lkb);) ;
V_5 -> V_11 &= ~ V_210 ;
V_5 -> V_200 -- ;
if ( ! V_5 -> V_200 )
F_121 ( & V_5 -> V_201 ) ;
F_102 ( V_5 ) ;
return 0 ;
}
static int F_122 ( struct V_4 * V_5 , int V_176 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int error ;
F_113 ( & V_30 -> V_195 ) ;
error = F_120 ( V_5 , V_176 , NULL ) ;
F_117 ( & V_30 -> V_195 ) ;
return error ;
}
static int F_123 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int error ;
if ( V_204 -> V_211 != V_212 )
F_113 ( & V_30 -> V_195 ) ;
error = F_120 ( V_5 , V_204 -> V_213 , V_204 ) ;
if ( V_204 -> V_211 != V_212 )
F_117 ( & V_30 -> V_195 ) ;
return error ;
}
static void F_124 ( struct V_18 * V_19 )
{
struct V_29 * V_30 = V_19 -> V_54 ;
V_214:
F_38 ( & V_30 -> V_215 ) ;
if ( V_30 -> V_216 &&
! F_51 ( V_19 , V_30 -> V_217 , V_30 -> V_216 ) ) {
F_46 ( V_30 , L_47 ,
V_19 -> V_22 , V_19 -> V_26 ) ;
F_40 ( & V_30 -> V_215 ) ;
F_125 ( 1 ) ;
goto V_214;
}
F_40 ( & V_30 -> V_215 ) ;
}
static void F_126 ( struct V_29 * V_30 , int V_99 )
{
struct V_75 * V_140 , * V_218 ;
struct V_18 * V_19 ;
char * V_70 ;
int V_103 = F_59 () ;
int V_219 = 0 ;
int V_220 = 0 ;
int V_141 , V_71 , V_43 ;
memset ( & V_30 -> V_221 , 0 , sizeof( int ) * V_222 ) ;
F_38 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
if ( ! ( V_30 -> V_57 [ V_99 ] . V_102 & V_144 ) ) {
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
return;
}
for ( V_140 = F_79 ( & V_30 -> V_57 [ V_99 ] . V_115 ) ; V_140 ; V_140 = V_218 ) {
V_218 = F_80 ( V_140 ) ;
V_19 = F_53 ( V_140 , struct V_18 , V_74 ) ;
if ( ! F_70 ( V_30 ) &&
( V_19 -> V_21 != V_103 ) &&
( F_127 ( V_19 ) == V_103 ) ) {
continue;
}
V_220 = 1 ;
if ( ! F_128 ( V_138 , V_19 -> V_137 +
V_65 . V_223 * V_224 ) ) {
continue;
}
if ( ! F_70 ( V_30 ) &&
( V_19 -> V_21 == V_103 ) &&
( F_127 ( V_19 ) != V_103 ) ) {
V_30 -> V_221 [ V_219 ] = V_19 -> V_76 ;
memcpy ( V_30 -> V_225 [ V_219 ] , V_19 -> V_26 ,
V_84 ) ;
V_219 ++ ;
if ( V_219 >= V_222 )
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
if ( V_220 )
V_30 -> V_57 [ V_99 ] . V_102 |= V_144 ;
else
V_30 -> V_57 [ V_99 ] . V_102 &= ~ V_144 ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
for ( V_141 = 0 ; V_141 < V_219 ; V_141 ++ ) {
V_70 = V_30 -> V_225 [ V_141 ] ;
V_71 = V_30 -> V_221 [ V_141 ] ;
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
if ( ! F_128 ( V_138 , V_19 -> V_137 +
V_65 . V_223 * V_224 ) ) {
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
F_38 ( & V_30 -> V_215 ) ;
V_30 -> V_216 = V_71 ;
memcpy ( V_30 -> V_217 , V_70 , V_84 ) ;
F_40 ( & V_30 -> V_215 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
F_129 ( V_19 ) ;
F_38 ( & V_30 -> V_215 ) ;
V_30 -> V_216 = 0 ;
memset ( V_30 -> V_217 , 0 , V_84 ) ;
F_40 ( & V_30 -> V_215 ) ;
F_65 ( V_19 ) ;
}
}
void F_130 ( struct V_29 * V_30 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < V_30 -> V_124 ; V_141 ++ ) {
F_126 ( V_30 , V_141 ) ;
if ( F_131 ( V_30 ) )
break;
F_132 () ;
}
}
static void F_133 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
if ( F_22 ( V_5 ) )
return;
if ( F_134 ( V_226 , & V_30 -> V_227 ) &&
! ( V_5 -> V_10 & V_228 ) ) {
V_5 -> V_11 |= V_229 ;
goto V_230;
}
if ( V_5 -> V_10 & V_231 )
goto V_230;
return;
V_230:
F_20 (list_empty(&lkb->lkb_time_list), dlm_print_lkb(lkb);) ;
F_113 ( & V_30 -> V_232 ) ;
F_101 ( V_5 ) ;
F_107 ( & V_5 -> V_152 , & V_30 -> V_233 ) ;
F_117 ( & V_30 -> V_232 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
F_113 ( & V_30 -> V_232 ) ;
if ( ! F_6 ( & V_5 -> V_152 ) ) {
F_121 ( & V_5 -> V_152 ) ;
F_102 ( V_5 ) ;
}
F_117 ( & V_30 -> V_232 ) ;
}
void F_135 ( struct V_29 * V_30 )
{
struct V_18 * V_19 ;
struct V_4 * V_5 ;
int V_234 , V_235 ;
T_2 V_236 ;
for (; ; ) {
if ( F_131 ( V_30 ) )
break;
V_234 = 0 ;
V_235 = 0 ;
F_113 ( & V_30 -> V_232 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list) {
V_236 = F_114 ( F_115 ( F_106 () ,
V_5 -> V_171 ) ) ;
if ( ( V_5 -> V_10 & V_231 ) &&
V_236 >= ( V_5 -> V_237 * 10000 ) )
V_234 = 1 ;
if ( ( V_5 -> V_11 & V_229 ) &&
V_236 >= V_65 . V_238 * 10000 )
V_235 = 1 ;
if ( ! V_234 && ! V_235 )
continue;
F_101 ( V_5 ) ;
break;
}
F_117 ( & V_30 -> V_232 ) ;
if ( ! V_234 && ! V_235 )
break;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
if ( V_235 ) {
V_5 -> V_11 &= ~ V_229 ;
if ( ! ( V_5 -> V_10 & V_231 ) )
F_29 ( V_5 ) ;
F_136 ( V_5 ) ;
}
if ( V_234 ) {
F_46 ( V_30 , L_54 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_26 ) ;
V_5 -> V_11 &= ~ V_229 ;
V_5 -> V_11 |= V_45 ;
F_29 ( V_5 ) ;
F_137 ( V_19 , V_5 ) ;
}
F_77 ( V_19 ) ;
F_84 ( V_19 ) ;
F_100 ( V_5 ) ;
}
}
void F_138 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
T_4 V_239 = F_139 ( V_138 - V_30 -> V_240 ) ;
V_30 -> V_240 = 0 ;
F_113 ( & V_30 -> V_232 ) ;
F_7 (lkb, &ls->ls_timeout, lkb_time_list)
V_5 -> V_171 = F_140 ( V_5 -> V_171 , V_239 ) ;
F_117 ( & V_30 -> V_232 ) ;
if ( ! V_65 . V_194 )
return;
F_113 ( & V_30 -> V_195 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( F_114 ( V_5 -> V_196 ) )
V_5 -> V_196 = F_106 () ;
}
F_117 ( & V_30 -> V_195 ) ;
}
static void F_141 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_99 , V_71 = V_19 -> V_54 -> V_241 ;
V_99 = V_242 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_99 == 1 ) {
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_243 ) )
return;
if ( ! V_19 -> V_145 )
return;
memcpy ( V_5 -> V_163 , V_19 -> V_145 , V_71 ) ;
V_5 -> V_244 = V_19 -> V_245 ;
} else if ( V_99 == 0 ) {
if ( V_5 -> V_10 & V_246 ) {
F_62 ( V_19 , V_247 ) ;
return;
}
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_243 ) )
return;
if ( ! V_19 -> V_145 )
V_19 -> V_145 = F_142 ( V_19 -> V_54 ) ;
if ( ! V_19 -> V_145 )
return;
memcpy ( V_19 -> V_145 , V_5 -> V_163 , V_71 ) ;
V_19 -> V_245 ++ ;
V_5 -> V_244 = V_19 -> V_245 ;
F_61 ( V_19 , V_247 ) ;
}
if ( F_143 ( V_19 , V_247 ) )
V_5 -> V_34 |= V_248 ;
}
static void F_144 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 < V_249 )
return;
if ( V_5 -> V_10 & V_246 ) {
F_62 ( V_19 , V_247 ) ;
return;
}
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_243 ) )
return;
if ( ! V_19 -> V_145 )
V_19 -> V_145 = F_142 ( V_19 -> V_54 ) ;
if ( ! V_19 -> V_145 )
return;
memcpy ( V_19 -> V_145 , V_5 -> V_163 , V_19 -> V_54 -> V_241 ) ;
V_19 -> V_245 ++ ;
F_61 ( V_19 , V_247 ) ;
}
static void F_145 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
int V_99 ;
if ( ! V_5 -> V_163 )
return;
if ( ! ( V_5 -> V_10 & V_243 ) )
return;
V_99 = V_242 [ V_5 -> V_14 + 1 ] [ V_5 -> V_13 + 1 ] ;
if ( V_99 == 1 ) {
int V_71 = F_146 ( V_204 ) ;
if ( V_71 > V_19 -> V_54 -> V_241 )
V_71 = V_19 -> V_54 -> V_241 ;
memcpy ( V_5 -> V_163 , V_204 -> V_250 , V_71 ) ;
V_5 -> V_244 = V_204 -> V_251 ;
}
}
static void F_147 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_108 ( V_19 , V_5 ) ;
V_5 -> V_14 = V_148 ;
F_102 ( V_5 ) ;
}
static void F_148 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_144 ( V_19 , V_5 ) ;
F_147 ( V_19 , V_5 ) ;
}
static void F_149 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_147 ( V_19 , V_5 ) ;
}
static int F_150 ( struct V_18 * V_19 , struct V_4 * V_5 )
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
static int F_151 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_150 ( V_19 , V_5 ) ;
}
static void F_152 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
if ( V_5 -> V_14 != V_5 -> V_13 ) {
V_5 -> V_14 = V_5 -> V_13 ;
if ( V_5 -> V_12 )
F_109 ( V_19 , V_5 , V_37 ) ;
else
F_105 ( V_19 , V_5 , V_37 ) ;
}
V_5 -> V_13 = V_148 ;
V_5 -> V_252 = 0 ;
}
static void F_153 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_141 ( V_19 , V_5 ) ;
F_152 ( V_19 , V_5 ) ;
}
static void F_154 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
F_145 ( V_19 , V_5 , V_204 ) ;
F_152 ( V_19 , V_5 ) ;
}
static void F_155 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_153 ( V_19 , V_5 ) ;
if ( F_22 ( V_5 ) )
F_156 ( V_19 , V_5 ) ;
else
F_28 ( V_19 , V_5 , 0 ) ;
}
static void F_157 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 == V_148 || V_5 -> V_14 == V_148 ) {
F_55 ( L_56 ,
V_5 -> V_8 , V_5 -> V_14 , V_5 -> V_13 ) ;
return;
}
V_5 -> V_14 = V_253 ;
}
static void F_158 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
if ( V_204 -> V_213 != V_178 &&
V_204 -> V_213 != V_254 ) {
F_55 ( L_57 ,
V_5 -> V_8 , V_204 -> V_213 ) ;
return;
}
if ( V_5 -> V_10 & V_255 )
V_5 -> V_13 = V_39 ;
else if ( V_5 -> V_10 & V_256 )
V_5 -> V_13 = V_40 ;
else {
F_55 ( L_58 , V_5 -> V_10 ) ;
F_2 ( V_5 ) ;
}
}
static inline int F_159 ( struct V_4 * V_5 , struct V_164 * V_166 )
{
struct V_4 * V_257 = F_160 ( V_166 -> V_218 , struct V_4 ,
V_168 ) ;
if ( V_5 -> V_8 == V_257 -> V_8 )
return 1 ;
return 0 ;
}
static int F_161 ( struct V_164 * V_166 , struct V_4 * V_5 )
{
struct V_4 * V_258 ;
F_7 (this, head, lkb_statequeue) {
if ( V_258 == V_5 )
continue;
if ( ! F_162 ( V_258 , V_5 ) )
return 1 ;
}
return 0 ;
}
static int F_163 ( struct V_18 * V_19 , struct V_4 * V_259 )
{
struct V_4 * V_260 ;
int V_261 = 0 ;
F_7 (lkb1, &r->res_convertqueue, lkb_statequeue) {
if ( V_260 == V_259 ) {
V_261 = 1 ;
continue;
}
if ( ! V_261 ) {
if ( ! F_162 ( V_259 , V_260 ) )
return 1 ;
} else {
if ( ! F_162 ( V_259 , V_260 ) &&
! F_162 ( V_260 , V_259 ) )
return 1 ;
}
}
return 0 ;
}
static int F_164 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_262 ,
int V_121 )
{
T_5 V_263 = ( V_5 -> V_14 != V_148 ) ;
if ( V_5 -> V_10 & V_264 )
return 1 ;
if ( F_161 ( & V_19 -> V_79 , V_5 ) )
return 0 ;
if ( F_161 ( & V_19 -> V_80 , V_5 ) )
return 0 ;
if ( V_263 && V_121 )
return 1 ;
if ( V_262 && V_263 && ! ( V_5 -> V_10 & V_265 ) )
return 1 ;
if ( V_262 && V_263 && ( V_5 -> V_10 & V_265 ) ) {
if ( F_6 ( & V_19 -> V_80 ) )
return 1 ;
else
return 0 ;
}
if ( V_5 -> V_10 & V_266 )
return 1 ;
if ( ! V_262 && V_263 && F_159 ( V_5 , & V_19 -> V_80 ) )
return 1 ;
if ( V_262 && ! V_263 && F_6 ( & V_19 -> V_80 ) &&
F_6 ( & V_19 -> V_81 ) )
return 1 ;
if ( ! V_262 && ! V_263 && F_6 ( & V_19 -> V_80 ) &&
F_159 ( V_5 , & V_19 -> V_81 ) )
return 1 ;
return 0 ;
}
static int F_165 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_262 ,
int V_121 , int * V_267 )
{
int V_43 ;
T_5 V_268 = 0 , V_51 = V_5 -> V_13 ;
T_5 V_269 = ( V_5 -> V_14 != V_148 ) ;
if ( V_267 )
* V_267 = 0 ;
V_43 = F_164 ( V_19 , V_5 , V_262 , V_121 ) ;
if ( V_43 )
goto V_111;
if ( V_269 && F_14 ( V_5 ) &&
F_163 ( V_19 , V_5 ) ) {
if ( V_5 -> V_10 & V_270 ) {
V_5 -> V_14 = V_253 ;
V_5 -> V_34 |= V_35 ;
} else if ( ! ( V_5 -> V_10 & V_228 ) ) {
if ( V_267 )
* V_267 = - V_48 ;
else {
F_55 ( L_59 ,
V_5 -> V_8 , V_262 ) ;
F_5 ( V_19 ) ;
}
}
goto V_111;
}
if ( V_51 != V_39 && ( V_5 -> V_10 & V_255 ) )
V_268 = V_39 ;
else if ( V_51 != V_40 && ( V_5 -> V_10 & V_256 ) )
V_268 = V_40 ;
if ( V_268 ) {
V_5 -> V_13 = V_268 ;
V_43 = F_164 ( V_19 , V_5 , V_262 , 0 ) ;
if ( V_43 )
V_5 -> V_34 |= V_36 ;
else
V_5 -> V_13 = V_51 ;
}
V_111:
return V_43 ;
}
static int F_166 ( struct V_18 * V_19 , int V_271 , int * V_272 ,
unsigned int * V_62 )
{
struct V_4 * V_5 , * V_273 ;
int V_121 = F_143 ( V_19 , V_274 ) ;
int V_275 , V_276 , V_277 , V_278 , V_279 ;
int V_280 ;
V_277 = 0 ;
V_214:
V_278 = 0 ;
V_279 = 0 ;
V_275 = V_148 ;
F_167 (lkb, s, &r->res_convertqueue, lkb_statequeue) {
V_276 = F_16 ( V_5 ) ;
V_280 = 0 ;
if ( F_165 ( V_19 , V_5 , 0 , V_121 , & V_280 ) ) {
F_155 ( V_19 , V_5 ) ;
V_278 = 1 ;
if ( V_62 )
( * V_62 ) ++ ;
continue;
}
if ( ! V_276 && F_16 ( V_5 ) ) {
F_55 ( L_60 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_26 ) ;
V_279 = 1 ;
continue;
}
if ( V_280 ) {
F_55 ( L_61 ,
V_5 -> V_8 , V_5 -> V_7 , V_19 -> V_26 ) ;
F_5 ( V_19 ) ;
continue;
}
V_275 = F_168 ( int , V_5 -> V_13 , V_275 ) ;
if ( V_272 && V_5 -> V_13 == V_40 )
* V_272 = 1 ;
}
if ( V_278 )
goto V_214;
if ( V_279 && ! V_277 ) {
V_277 = 1 ;
goto V_214;
}
return F_168 ( int , V_271 , V_275 ) ;
}
static int F_169 ( struct V_18 * V_19 , int V_271 , int * V_272 ,
unsigned int * V_62 )
{
struct V_4 * V_5 , * V_273 ;
F_167 (lkb, s, &r->res_waitqueue, lkb_statequeue) {
if ( F_165 ( V_19 , V_5 , 0 , 0 , NULL ) ) {
F_155 ( V_19 , V_5 ) ;
if ( V_62 )
( * V_62 ) ++ ;
} else {
V_271 = F_168 ( int , V_5 -> V_13 , V_271 ) ;
if ( V_5 -> V_13 == V_40 )
* V_272 = 1 ;
}
}
return V_271 ;
}
static int F_170 ( struct V_4 * V_281 , int V_271 , int V_272 )
{
if ( V_281 -> V_14 == V_39 && V_272 ) {
if ( V_281 -> V_252 < V_282 )
return 1 ;
return 0 ;
}
if ( V_281 -> V_252 < V_271 &&
! V_3 [ V_281 -> V_14 + 1 ] [ V_271 + 1 ] )
return 1 ;
return 0 ;
}
static void F_171 ( struct V_18 * V_19 , unsigned int * V_62 )
{
struct V_4 * V_5 , * V_273 ;
int V_271 = V_148 ;
int V_272 = 0 ;
if ( ! F_172 ( V_19 ) ) {
F_55 ( L_62 , V_19 -> V_20 ) ;
F_5 ( V_19 ) ;
return;
}
V_271 = F_166 ( V_19 , V_271 , & V_272 , V_62 ) ;
V_271 = F_169 ( V_19 , V_271 , & V_272 , V_62 ) ;
if ( V_271 == V_148 )
return;
F_167 (lkb, s, &r->res_grantqueue, lkb_statequeue) {
if ( V_5 -> V_283 && F_170 ( V_5 , V_271 , V_272 ) ) {
if ( V_272 && V_271 == V_39 &&
V_5 -> V_14 == V_39 )
F_32 ( V_19 , V_5 , V_40 ) ;
else
F_32 ( V_19 , V_5 , V_271 ) ;
V_5 -> V_252 = V_271 ;
}
}
}
static int F_173 ( struct V_4 * V_281 , struct V_4 * V_284 )
{
if ( ( V_281 -> V_14 == V_39 && V_284 -> V_13 == V_40 ) ||
( V_281 -> V_14 == V_40 && V_284 -> V_13 == V_39 ) ) {
if ( V_281 -> V_252 < V_282 )
return 1 ;
return 0 ;
}
if ( V_281 -> V_252 < V_284 -> V_13 && ! F_162 ( V_281 , V_284 ) )
return 1 ;
return 0 ;
}
static void F_174 ( struct V_18 * V_19 , struct V_164 * V_166 ,
struct V_4 * V_5 )
{
struct V_4 * V_281 ;
F_7 (gr, head, lkb_statequeue) {
if ( V_281 == V_5 )
continue;
if ( V_281 -> V_283 && F_173 ( V_281 , V_5 ) ) {
F_32 ( V_19 , V_281 , V_5 -> V_13 ) ;
V_281 -> V_252 = V_5 -> V_13 ;
}
}
}
static void F_175 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_174 ( V_19 , & V_19 -> V_79 , V_5 ) ;
}
static void F_176 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_174 ( V_19 , & V_19 -> V_79 , V_5 ) ;
F_174 ( V_19 , & V_19 -> V_80 , V_5 ) ;
}
static int F_177 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int V_103 = F_59 () ;
if ( F_143 ( V_19 , V_118 ) ) {
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
if ( F_127 ( V_19 ) == V_103 ) {
F_46 ( V_19 -> V_54 , L_63 ,
V_5 -> V_8 , V_19 -> V_21 , V_19 -> V_22 ,
V_19 -> V_26 ) ;
V_19 -> V_21 = V_103 ;
V_19 -> V_20 = 0 ;
V_5 -> V_7 = 0 ;
return 0 ;
}
F_124 ( V_19 ) ;
V_19 -> V_24 = V_5 -> V_8 ;
F_178 ( V_19 , V_5 ) ;
return 1 ;
}
static void F_179 ( struct V_18 * V_19 )
{
struct V_4 * V_5 , * V_285 ;
F_167 (lkb, safe, &r->res_lookup, lkb_rsb_lookup) {
F_121 ( & V_5 -> V_151 ) ;
F_180 ( V_19 , V_5 ) ;
F_181 () ;
}
}
static void F_182 ( struct V_18 * V_19 , int error )
{
struct V_4 * V_5 ;
if ( ! V_19 -> V_24 )
return;
switch ( error ) {
case 0 :
case - V_286 :
V_19 -> V_24 = 0 ;
F_179 ( V_19 ) ;
break;
case - V_73 :
case - V_92 :
case - V_117 :
V_19 -> V_24 = 0 ;
if ( ! F_6 ( & V_19 -> V_78 ) ) {
V_5 = F_160 ( V_19 -> V_78 . V_218 , struct V_4 ,
V_151 ) ;
F_121 ( & V_5 -> V_151 ) ;
V_19 -> V_24 = V_5 -> V_8 ;
F_180 ( V_19 , V_5 ) ;
}
break;
default:
F_60 ( V_19 -> V_54 , L_64 , error ) ;
}
}
static int F_183 ( int V_167 , struct V_287 * V_288 , T_1 V_102 ,
int V_289 , unsigned long V_290 ,
void (* F_184) ( void * V_291 ) ,
void * V_291 ,
void (* F_185) ( void * V_291 , int V_167 ) ,
struct V_292 * args )
{
int V_43 = - V_123 ;
if ( V_167 < 0 || V_167 > V_282 )
goto V_111;
if ( ! ( V_102 & V_293 ) && ( V_289 > V_84 ) )
goto V_111;
if ( V_102 & V_294 )
goto V_111;
if ( V_102 & V_265 && ! ( V_102 & V_293 ) )
goto V_111;
if ( V_102 & V_270 && ! ( V_102 & V_293 ) )
goto V_111;
if ( V_102 & V_270 && V_102 & V_32 )
goto V_111;
if ( V_102 & V_264 && V_102 & V_293 )
goto V_111;
if ( V_102 & V_264 && V_102 & V_265 )
goto V_111;
if ( V_102 & V_264 && V_102 & V_32 )
goto V_111;
if ( V_102 & V_264 && V_167 != V_253 )
goto V_111;
if ( ! F_184 || ! V_288 )
goto V_111;
if ( V_102 & V_243 && ! V_288 -> V_295 )
goto V_111;
if ( V_102 & V_293 && ! V_288 -> V_296 )
goto V_111;
args -> V_102 = V_102 ;
args -> V_297 = F_184 ;
args -> V_291 = V_291 ;
args -> V_298 = F_185 ;
args -> V_299 = V_290 ;
args -> V_167 = V_167 ;
args -> V_288 = V_288 ;
V_43 = 0 ;
V_111:
return V_43 ;
}
static int F_186 ( T_1 V_102 , void * V_300 , struct V_292 * args )
{
if ( V_102 & ~ ( V_294 | V_243 | V_246 |
V_301 ) )
return - V_123 ;
if ( V_102 & V_294 && V_102 & V_301 )
return - V_123 ;
args -> V_102 = V_102 ;
args -> V_291 = V_300 ;
return 0 ;
}
static int F_187 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_292 * args )
{
int V_43 = - V_123 ;
if ( args -> V_102 & V_293 ) {
if ( V_5 -> V_11 & V_38 )
goto V_111;
if ( args -> V_102 & V_265 &&
! V_302 [ V_5 -> V_14 + 1 ] [ args -> V_167 + 1 ] )
goto V_111;
V_43 = - V_199 ;
if ( V_5 -> V_12 != V_37 )
goto V_111;
if ( V_5 -> V_15 )
goto V_111;
if ( F_27 ( V_5 ) )
goto V_111;
}
V_5 -> V_10 = args -> V_102 ;
V_5 -> V_34 = 0 ;
V_5 -> V_303 = args -> V_297 ;
V_5 -> V_304 = args -> V_291 ;
V_5 -> V_283 = args -> V_298 ;
V_5 -> V_13 = args -> V_167 ;
V_5 -> V_305 = args -> V_288 ;
V_5 -> V_163 = args -> V_288 -> V_295 ;
V_5 -> V_306 = ( int ) V_307 -> V_308 ;
V_5 -> V_237 = args -> V_299 ;
V_43 = 0 ;
V_111:
if ( V_43 )
F_46 ( V_30 , L_65 ,
V_43 , V_5 -> V_8 , V_5 -> V_11 , args -> V_102 ,
V_5 -> V_12 , V_5 -> V_15 ,
V_5 -> V_146 -> V_26 ) ;
return V_43 ;
}
static int F_188 ( struct V_4 * V_5 , struct V_292 * args )
{
struct V_29 * V_30 = V_5 -> V_146 -> V_54 ;
int V_43 = - V_123 ;
if ( V_5 -> V_11 & V_38 ) {
F_60 ( V_30 , L_66 , V_5 -> V_8 ) ;
F_2 ( V_5 ) ;
goto V_111;
}
if ( V_5 -> V_11 & V_309 ) {
F_46 ( V_30 , L_67 , V_5 -> V_8 ) ;
V_43 = - V_162 ;
goto V_111;
}
if ( ! F_6 ( & V_5 -> V_151 ) ) {
if ( args -> V_102 & ( V_294 | V_301 ) ) {
F_46 ( V_30 , L_68 , V_5 -> V_8 ) ;
F_121 ( & V_5 -> V_151 ) ;
F_28 ( V_5 -> V_146 , V_5 ,
args -> V_102 & V_294 ?
- V_44 : - V_50 ) ;
F_102 ( V_5 ) ;
}
V_43 = - V_199 ;
goto V_111;
}
if ( args -> V_102 & V_294 ) {
if ( V_5 -> V_10 & V_294 )
goto V_111;
if ( F_27 ( V_5 ) )
goto V_111;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_210 ) {
V_5 -> V_11 |= V_42 ;
V_43 = - V_199 ;
goto V_111;
}
if ( V_5 -> V_12 == V_37 &&
! V_5 -> V_15 ) {
V_43 = - V_199 ;
goto V_111;
}
switch ( V_5 -> V_15 ) {
case V_185 :
case V_177 :
V_5 -> V_11 |= V_42 ;
V_43 = - V_199 ;
goto V_111;
case V_181 :
case V_183 :
goto V_111;
}
goto V_310;
}
if ( args -> V_102 & V_301 ) {
if ( V_5 -> V_10 & V_301 )
goto V_111;
if ( F_25 ( V_5 ) )
goto V_111;
F_29 ( V_5 ) ;
if ( V_5 -> V_11 & V_210 ) {
V_5 -> V_11 |= V_41 ;
V_43 = - V_199 ;
goto V_111;
}
switch ( V_5 -> V_15 ) {
case V_185 :
case V_177 :
V_5 -> V_11 |= V_41 ;
V_43 = - V_199 ;
goto V_111;
case V_181 :
goto V_111;
}
goto V_310;
}
V_43 = - V_199 ;
if ( V_5 -> V_15 || V_5 -> V_200 )
goto V_111;
V_310:
V_5 -> V_10 |= args -> V_102 ;
V_5 -> V_34 = 0 ;
V_5 -> V_304 = args -> V_291 ;
V_43 = 0 ;
V_111:
if ( V_43 )
F_46 ( V_30 , L_69 , V_43 ,
V_5 -> V_8 , V_5 -> V_11 , V_5 -> V_10 ,
args -> V_102 , V_5 -> V_15 ,
V_5 -> V_146 -> V_26 ) ;
return V_43 ;
}
static int F_189 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error = 0 ;
if ( F_165 ( V_19 , V_5 , 1 , 0 , NULL ) ) {
F_153 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_111;
}
if ( F_14 ( V_5 ) ) {
error = - V_286 ;
F_105 ( V_19 , V_5 , V_172 ) ;
F_133 ( V_5 ) ;
goto V_111;
}
error = - V_73 ;
F_28 ( V_19 , V_5 , - V_73 ) ;
V_111:
return error ;
}
static void F_190 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
switch ( error ) {
case - V_73 :
if ( F_15 ( V_5 ) )
F_176 ( V_19 , V_5 ) ;
break;
case - V_286 :
F_175 ( V_19 , V_5 ) ;
break;
}
}
static int F_191 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error = 0 ;
int V_280 = 0 ;
if ( F_165 ( V_19 , V_5 , 1 , 0 , & V_280 ) ) {
F_153 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_111;
}
if ( V_280 ) {
F_150 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_48 ) ;
error = - V_48 ;
goto V_111;
}
if ( F_16 ( V_5 ) ) {
F_166 ( V_19 , V_148 , NULL , NULL ) ;
if ( F_164 ( V_19 , V_5 , 1 , 0 ) ) {
F_153 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
goto V_111;
}
}
if ( F_14 ( V_5 ) ) {
error = - V_286 ;
F_108 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_174 ) ;
F_133 ( V_5 ) ;
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
case 0 :
F_171 ( V_19 , NULL ) ;
break;
case - V_73 :
if ( F_15 ( V_5 ) )
F_176 ( V_19 , V_5 ) ;
break;
case - V_286 :
F_175 ( V_19 , V_5 ) ;
break;
}
}
static int F_193 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
F_148 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_50 ) ;
return - V_50 ;
}
static void F_194 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
F_171 ( V_19 , NULL ) ;
}
static int V_234 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_150 ( V_19 , V_5 ) ;
if ( error ) {
F_28 ( V_19 , V_5 , - V_44 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_195 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int error )
{
if ( error )
F_171 ( V_19 , NULL ) ;
}
static int F_180 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_177 ( V_19 , V_5 ) ;
if ( error < 0 )
goto V_111;
if ( error ) {
error = 0 ;
goto V_111;
}
if ( F_19 ( V_19 ) ) {
error = F_196 ( V_19 , V_5 ) ;
} else {
error = F_189 ( V_19 , V_5 ) ;
F_190 ( V_19 , V_5 , error ) ;
}
V_111:
return error ;
}
static int F_197 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_198 ( V_19 , V_5 ) ;
} else {
error = F_191 ( V_19 , V_5 ) ;
F_192 ( V_19 , V_5 , error ) ;
}
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
static int F_137 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
if ( F_19 ( V_19 ) ) {
error = F_201 ( V_19 , V_5 ) ;
} else {
error = V_234 ( V_19 , V_5 ) ;
F_195 ( V_19 , V_5 , error ) ;
}
return error ;
}
static int F_202 ( struct V_29 * V_30 , struct V_4 * V_5 , char * V_70 ,
int V_71 , struct V_292 * args )
{
struct V_18 * V_19 ;
int error ;
error = F_187 ( V_30 , V_5 , args ) ;
if ( error )
return error ;
error = F_67 ( V_30 , V_70 , V_71 , 0 , V_109 , & V_19 ) ;
if ( error )
return error ;
F_73 ( V_19 ) ;
F_86 ( V_19 , V_5 ) ;
V_5 -> V_305 -> V_296 = V_5 -> V_8 ;
error = F_180 ( V_19 , V_5 ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
static int F_203 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_292 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_187 ( V_30 , V_5 , args ) ;
if ( error )
goto V_111;
error = F_197 ( V_19 , V_5 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
static int F_204 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_292 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_188 ( V_5 , args ) ;
if ( error )
goto V_111;
error = F_199 ( V_19 , V_5 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
static int F_205 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_292 * args )
{
struct V_18 * V_19 ;
int error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_188 ( V_5 , args ) ;
if ( error )
goto V_111;
error = F_137 ( V_19 , V_5 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
return error ;
}
int F_206 ( T_6 * V_311 ,
int V_167 ,
struct V_287 * V_288 ,
T_1 V_102 ,
void * V_70 ,
unsigned int V_289 ,
T_1 V_312 ,
void (* F_184) ( void * V_300 ) ,
void * V_300 ,
void (* F_185) ( void * V_300 , int V_167 ) )
{
struct V_29 * V_30 ;
struct V_4 * V_5 ;
struct V_292 args ;
int error , V_313 = V_102 & V_293 ;
V_30 = F_207 ( V_311 ) ;
if ( ! V_30 )
return - V_123 ;
F_8 ( V_30 ) ;
if ( V_313 )
error = F_94 ( V_30 , V_288 -> V_296 , & V_5 ) ;
else
error = F_88 ( V_30 , & V_5 ) ;
if ( error )
goto V_111;
error = F_183 ( V_167 , V_288 , V_102 , V_289 , 0 , F_184 ,
V_300 , F_185 , & args ) ;
if ( error )
goto V_314;
if ( V_313 )
error = F_203 ( V_30 , V_5 , & args ) ;
else
error = F_202 ( V_30 , V_5 , V_70 , V_289 , & args ) ;
if ( error == - V_286 )
error = 0 ;
V_314:
if ( V_313 || error )
F_97 ( V_30 , V_5 ) ;
if ( error == - V_73 || error == - V_48 )
error = 0 ;
V_111:
F_10 ( V_30 ) ;
F_208 ( V_30 ) ;
return error ;
}
int F_209 ( T_6 * V_311 ,
T_1 V_161 ,
T_1 V_102 ,
struct V_287 * V_288 ,
void * V_300 )
{
struct V_29 * V_30 ;
struct V_4 * V_5 ;
struct V_292 args ;
int error ;
V_30 = F_207 ( V_311 ) ;
if ( ! V_30 )
return - V_123 ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
error = F_186 ( V_102 , V_300 , & args ) ;
if ( error )
goto V_314;
if ( V_102 & V_294 )
error = F_205 ( V_30 , V_5 , & args ) ;
else
error = F_204 ( V_30 , V_5 , & args ) ;
if ( error == - V_50 || error == - V_44 )
error = 0 ;
if ( error == - V_199 && ( V_102 & ( V_294 | V_301 ) ) )
error = 0 ;
V_314:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_208 ( V_30 ) ;
return error ;
}
static int F_210 ( struct V_29 * V_30 , int V_315 ,
int V_198 , int V_176 ,
struct V_203 * * V_316 ,
struct V_317 * * V_318 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
char * V_320 ;
V_319 = F_211 ( V_198 , V_315 , V_157 , & V_320 ) ;
if ( ! V_319 )
return - V_321 ;
memset ( V_320 , 0 , V_315 ) ;
V_204 = (struct V_203 * ) V_320 ;
V_204 -> V_208 . V_322 = ( V_323 | V_324 ) ;
V_204 -> V_208 . V_325 = V_30 -> V_326 ;
V_204 -> V_208 . V_209 = F_59 () ;
V_204 -> V_208 . V_327 = V_315 ;
V_204 -> V_208 . V_328 = V_329 ;
V_204 -> V_213 = V_176 ;
* V_318 = V_319 ;
* V_316 = V_204 ;
return 0 ;
}
static int F_212 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_198 , int V_176 ,
struct V_203 * * V_316 ,
struct V_317 * * V_318 )
{
int V_315 = sizeof( struct V_203 ) ;
switch ( V_176 ) {
case V_177 :
case V_185 :
case V_330 :
V_315 += V_19 -> V_76 ;
break;
case V_179 :
case V_181 :
case V_178 :
case V_180 :
case V_254 :
if ( V_5 && V_5 -> V_163 )
V_315 += V_19 -> V_54 -> V_241 ;
break;
}
return F_210 ( V_19 -> V_54 , V_315 , V_198 , V_176 ,
V_316 , V_318 ) ;
}
static int F_213 ( struct V_317 * V_319 , struct V_203 * V_204 )
{
F_214 ( V_204 ) ;
F_215 ( V_319 ) ;
return 0 ;
}
static void F_216 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
V_204 -> V_331 = V_5 -> V_7 ;
V_204 -> V_332 = V_5 -> V_306 ;
V_204 -> V_333 = V_5 -> V_8 ;
V_204 -> V_334 = V_5 -> V_9 ;
V_204 -> V_335 = V_5 -> V_10 ;
V_204 -> V_336 = V_5 -> V_34 ;
V_204 -> V_211 = V_5 -> V_11 ;
V_204 -> V_251 = V_5 -> V_244 ;
V_204 -> V_337 = V_5 -> V_12 ;
V_204 -> V_338 = V_5 -> V_14 ;
V_204 -> V_339 = V_5 -> V_13 ;
V_204 -> V_340 = V_19 -> V_119 ;
if ( V_5 -> V_283 )
V_204 -> V_341 |= V_52 ;
if ( V_5 -> V_303 )
V_204 -> V_341 |= V_49 ;
switch ( V_204 -> V_213 ) {
case V_177 :
case V_185 :
memcpy ( V_204 -> V_250 , V_19 -> V_26 , V_19 -> V_76 ) ;
break;
case V_179 :
case V_181 :
case V_178 :
case V_180 :
case V_254 :
if ( ! V_5 -> V_163 )
break;
memcpy ( V_204 -> V_250 , V_5 -> V_163 , V_19 -> V_54 -> V_241 ) ;
break;
}
}
static int F_217 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_176 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int V_198 , error ;
V_198 = V_19 -> V_20 ;
error = F_119 ( V_5 , V_176 , V_198 ) ;
if ( error )
return error ;
error = F_212 ( V_19 , V_5 , V_198 , V_176 , & V_204 , & V_319 ) ;
if ( error )
goto V_342;
F_216 ( V_19 , V_5 , V_204 ) ;
error = F_213 ( V_319 , V_204 ) ;
if ( error )
goto V_342;
return 0 ;
V_342:
F_122 ( V_5 , F_110 ( V_176 ) ) ;
return error ;
}
static int F_196 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_217 ( V_19 , V_5 , V_177 ) ;
}
static int F_198 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
int error ;
error = F_217 ( V_19 , V_5 , V_179 ) ;
if ( ! error && F_24 ( V_5 ) ) {
F_122 ( V_5 , V_180 ) ;
V_19 -> V_54 -> V_343 . V_211 = V_212 ;
V_19 -> V_54 -> V_343 . V_213 = V_180 ;
V_19 -> V_54 -> V_343 . V_207 = 0 ;
F_218 ( V_19 , V_5 , & V_19 -> V_54 -> V_343 ) ;
}
return error ;
}
static int F_200 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_217 ( V_19 , V_5 , V_181 ) ;
}
static int F_201 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
return F_217 ( V_19 , V_5 , V_183 ) ;
}
static int F_156 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int V_198 , error ;
V_198 = V_5 -> V_7 ;
error = F_212 ( V_19 , V_5 , V_198 , V_254 , & V_204 , & V_319 ) ;
if ( error )
goto V_111;
F_216 ( V_19 , V_5 , V_204 ) ;
V_204 -> V_207 = 0 ;
error = F_213 ( V_319 , V_204 ) ;
V_111:
return error ;
}
static int F_33 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_167 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int V_198 , error ;
V_198 = V_5 -> V_7 ;
error = F_212 ( V_19 , NULL , V_198 , V_344 , & V_204 , & V_319 ) ;
if ( error )
goto V_111;
F_216 ( V_19 , V_5 , V_204 ) ;
V_204 -> V_345 = V_167 ;
error = F_213 ( V_319 , V_204 ) ;
V_111:
return error ;
}
static int F_178 ( struct V_18 * V_19 , struct V_4 * V_5 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int V_198 , error ;
V_198 = F_127 ( V_19 ) ;
error = F_119 ( V_5 , V_185 , V_198 ) ;
if ( error )
return error ;
error = F_212 ( V_19 , NULL , V_198 , V_185 , & V_204 , & V_319 ) ;
if ( error )
goto V_342;
F_216 ( V_19 , V_5 , V_204 ) ;
error = F_213 ( V_319 , V_204 ) ;
if ( error )
goto V_342;
return 0 ;
V_342:
F_122 ( V_5 , V_186 ) ;
return error ;
}
static int F_129 ( struct V_18 * V_19 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int V_198 , error ;
V_198 = F_127 ( V_19 ) ;
error = F_212 ( V_19 , NULL , V_198 , V_330 , & V_204 , & V_319 ) ;
if ( error )
goto V_111;
memcpy ( V_204 -> V_250 , V_19 -> V_26 , V_19 -> V_76 ) ;
V_204 -> V_340 = V_19 -> V_119 ;
error = F_213 ( V_319 , V_204 ) ;
V_111:
return error ;
}
static int F_219 ( struct V_18 * V_19 , struct V_4 * V_5 ,
int V_176 , int V_43 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int V_198 , error ;
V_198 = V_5 -> V_7 ;
error = F_212 ( V_19 , V_5 , V_198 , V_176 , & V_204 , & V_319 ) ;
if ( error )
goto V_111;
F_216 ( V_19 , V_5 , V_204 ) ;
V_204 -> V_207 = V_43 ;
error = F_213 ( V_319 , V_204 ) ;
V_111:
return error ;
}
static int F_220 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_219 ( V_19 , V_5 , V_178 , V_43 ) ;
}
static int F_221 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_219 ( V_19 , V_5 , V_180 , V_43 ) ;
}
static int F_222 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_219 ( V_19 , V_5 , V_182 , V_43 ) ;
}
static int F_223 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_43 )
{
return F_219 ( V_19 , V_5 , V_184 , V_43 ) ;
}
static int F_224 ( struct V_29 * V_30 , struct V_203 * V_346 ,
int V_347 , int V_43 )
{
struct V_18 * V_19 = & V_30 -> V_348 ;
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int error , V_187 = V_346 -> V_208 . V_209 ;
error = F_212 ( V_19 , NULL , V_187 , V_186 , & V_204 , & V_319 ) ;
if ( error )
goto V_111;
V_204 -> V_333 = V_346 -> V_333 ;
V_204 -> V_207 = V_43 ;
V_204 -> V_331 = V_347 ;
error = F_213 ( V_319 , V_204 ) ;
V_111:
return error ;
}
static void F_225 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
V_5 -> V_10 = V_204 -> V_335 ;
V_5 -> V_34 = V_204 -> V_336 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_204 -> V_211 & 0x0000FFFF ) ;
}
static void F_226 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
if ( V_204 -> V_211 == V_212 )
return;
V_5 -> V_34 = V_204 -> V_336 ;
V_5 -> V_11 = ( V_5 -> V_11 & 0xFFFF0000 ) |
( V_204 -> V_211 & 0x0000FFFF ) ;
}
static int F_146 ( struct V_203 * V_204 )
{
return ( V_204 -> V_208 . V_327 - sizeof( struct V_203 ) ) ;
}
static int F_227 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
int V_71 ;
if ( V_5 -> V_10 & V_243 ) {
if ( ! V_5 -> V_163 )
V_5 -> V_163 = F_142 ( V_30 ) ;
if ( ! V_5 -> V_163 )
return - V_69 ;
V_71 = F_146 ( V_204 ) ;
if ( V_71 > V_30 -> V_241 )
V_71 = V_30 -> V_241 ;
memcpy ( V_5 -> V_163 , V_204 -> V_250 , V_71 ) ;
}
return 0 ;
}
static void F_228 ( void * V_291 , int V_167 )
{
F_55 ( L_70 ) ;
}
static void F_229 ( void * V_291 )
{
F_55 ( L_71 ) ;
}
static int F_230 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
V_5 -> V_7 = V_204 -> V_208 . V_209 ;
V_5 -> V_306 = V_204 -> V_332 ;
V_5 -> V_9 = V_204 -> V_333 ;
V_5 -> V_14 = V_148 ;
V_5 -> V_13 = V_204 -> V_339 ;
V_5 -> V_283 = ( V_204 -> V_341 & V_52 ) ? & F_228 : NULL ;
V_5 -> V_303 = ( V_204 -> V_341 & V_49 ) ? & F_229 : NULL ;
if ( V_5 -> V_10 & V_243 ) {
V_5 -> V_163 = F_142 ( V_30 ) ;
if ( ! V_5 -> V_163 )
return - V_69 ;
}
return 0 ;
}
static int F_231 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
if ( V_5 -> V_12 != V_37 )
return - V_199 ;
if ( F_227 ( V_30 , V_5 , V_204 ) )
return - V_69 ;
V_5 -> V_13 = V_204 -> V_339 ;
V_5 -> V_244 = V_204 -> V_251 ;
return 0 ;
}
static int F_232 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
if ( F_227 ( V_30 , V_5 , V_204 ) )
return - V_69 ;
return 0 ;
}
static void F_233 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 = & V_30 -> V_349 ;
V_5 -> V_7 = V_204 -> V_208 . V_209 ;
V_5 -> V_9 = V_204 -> V_333 ;
}
static int F_234 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
int V_350 = V_204 -> V_208 . V_209 ;
int error = 0 ;
switch ( V_204 -> V_213 ) {
case V_179 :
case V_181 :
case V_183 :
if ( ! F_22 ( V_5 ) || V_5 -> V_7 != V_350 )
error = - V_123 ;
break;
case V_180 :
case V_182 :
case V_184 :
case V_254 :
case V_344 :
if ( ! F_21 ( V_5 ) || V_5 -> V_7 != V_350 )
error = - V_123 ;
break;
case V_178 :
if ( ! F_21 ( V_5 ) )
error = - V_123 ;
else if ( V_5 -> V_7 != - 1 && V_5 -> V_7 != V_350 )
error = - V_123 ;
break;
default:
error = - V_123 ;
}
if ( error )
F_60 ( V_5 -> V_146 -> V_54 ,
L_72 ,
V_204 -> V_213 , V_350 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_11 , V_5 -> V_7 ) ;
return error ;
}
static void F_235 ( struct V_29 * V_30 , char * V_351 , int V_71 )
{
char V_70 [ V_84 + 1 ] ;
struct V_203 * V_204 ;
struct V_317 * V_319 ;
struct V_18 * V_19 ;
T_1 V_98 , V_99 ;
int V_43 , V_100 ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
memcpy ( V_70 , V_351 , V_71 ) ;
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
F_38 ( & V_30 -> V_215 ) ;
V_30 -> V_216 = V_71 ;
memcpy ( V_30 -> V_217 , V_70 , V_84 ) ;
F_40 ( & V_30 -> V_215 ) ;
F_40 ( & V_30 -> V_57 [ V_99 ] . V_58 ) ;
V_43 = F_210 ( V_30 , sizeof( struct V_203 ) + V_71 ,
V_100 , V_330 , & V_204 , & V_319 ) ;
if ( V_43 )
return;
memcpy ( V_204 -> V_250 , V_70 , V_71 ) ;
V_204 -> V_340 = V_98 ;
F_213 ( V_319 , V_204 ) ;
F_38 ( & V_30 -> V_215 ) ;
V_30 -> V_216 = 0 ;
memset ( V_30 -> V_217 , 0 , V_84 ) ;
F_40 ( & V_30 -> V_215 ) ;
}
static int F_236 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int V_101 ;
int error , V_289 = 0 ;
V_101 = V_204 -> V_208 . V_209 ;
error = F_88 ( V_30 , & V_5 ) ;
if ( error )
goto V_342;
F_225 ( V_5 , V_204 ) ;
V_5 -> V_11 |= V_38 ;
error = F_230 ( V_30 , V_5 , V_204 ) ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_342;
}
V_289 = F_146 ( V_204 ) ;
error = F_67 ( V_30 , V_204 -> V_250 , V_289 , V_101 ,
V_108 , & V_19 ) ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_342;
}
F_73 ( V_19 ) ;
if ( V_19 -> V_21 != F_59 () ) {
error = F_71 ( V_30 , V_19 , V_101 ) ;
if ( error ) {
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_97 ( V_30 , V_5 ) ;
goto V_342;
}
}
F_86 ( V_19 , V_5 ) ;
error = F_189 ( V_19 , V_5 ) ;
F_220 ( V_19 , V_5 , error ) ;
F_190 ( V_19 , V_5 , error ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
if ( error == - V_286 )
error = 0 ;
if ( error )
F_100 ( V_5 ) ;
return 0 ;
V_342:
if ( error != - V_117 ) {
F_75 ( V_30 , L_76 ,
V_204 -> V_333 , V_101 , error ) ;
}
if ( V_289 && error == - V_92 ) {
F_235 ( V_30 , V_204 -> V_250 , V_289 ) ;
F_125 ( 1000 ) ;
}
F_233 ( V_30 , V_204 ) ;
F_220 ( & V_30 -> V_348 , & V_30 -> V_349 , error ) ;
return error ;
}
static int F_237 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_352 = 1 ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
goto V_342;
if ( V_5 -> V_9 != V_204 -> V_333 ) {
F_60 ( V_30 , L_77
L_78 , V_5 -> V_8 , V_5 -> V_9 ,
( unsigned long long ) V_5 -> V_17 ,
V_204 -> V_208 . V_209 , V_204 -> V_333 ) ;
error = - V_162 ;
goto V_342;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
F_225 ( V_5 , V_204 ) ;
error = F_231 ( V_30 , V_5 , V_204 ) ;
if ( error ) {
F_221 ( V_19 , V_5 , error ) ;
goto V_111;
}
V_352 = ! F_24 ( V_5 ) ;
error = F_191 ( V_19 , V_5 ) ;
if ( V_352 )
F_221 ( V_19 , V_5 , error ) ;
F_192 ( V_19 , V_5 , error ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
V_342:
F_233 ( V_30 , V_204 ) ;
F_221 ( & V_30 -> V_348 , & V_30 -> V_349 , error ) ;
return error ;
}
static int F_238 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
goto V_342;
if ( V_5 -> V_9 != V_204 -> V_333 ) {
F_60 ( V_30 , L_79 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_204 -> V_208 . V_209 , V_204 -> V_333 ) ;
error = - V_162 ;
goto V_342;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
F_225 ( V_5 , V_204 ) ;
error = F_232 ( V_30 , V_5 , V_204 ) ;
if ( error ) {
F_222 ( V_19 , V_5 , error ) ;
goto V_111;
}
error = F_193 ( V_19 , V_5 ) ;
F_222 ( V_19 , V_5 , error ) ;
F_194 ( V_19 , V_5 , error ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
V_342:
F_233 ( V_30 , V_204 ) ;
F_222 ( & V_30 -> V_348 , & V_30 -> V_349 , error ) ;
return error ;
}
static int F_239 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
goto V_342;
F_225 ( V_5 , V_204 ) ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
error = V_234 ( V_19 , V_5 ) ;
F_223 ( V_19 , V_5 , error ) ;
F_195 ( V_19 , V_5 , error ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
V_342:
F_233 ( V_30 , V_204 ) ;
F_223 ( & V_30 -> V_348 , & V_30 -> V_349 , error ) ;
return error ;
}
static int F_240 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
F_226 ( V_5 , V_204 ) ;
if ( F_17 ( V_5 ) )
F_158 ( V_5 , V_204 ) ;
F_154 ( V_19 , V_5 , V_204 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static int F_241 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
F_32 ( V_19 , V_5 , V_204 -> V_345 ) ;
V_5 -> V_252 = V_204 -> V_345 ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_242 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
int V_71 , error , V_347 , V_101 , V_103 ;
V_101 = V_204 -> V_208 . V_209 ;
V_103 = F_59 () ;
V_71 = F_146 ( V_204 ) ;
error = F_72 ( V_30 , V_101 , V_204 -> V_250 , V_71 , 0 ,
& V_347 , NULL ) ;
if ( ! error && V_347 == V_103 ) {
F_236 ( V_30 , V_204 ) ;
return;
}
F_224 ( V_30 , V_204 , V_347 , error ) ;
}
static void F_243 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
char V_70 [ V_84 + 1 ] ;
struct V_18 * V_19 ;
T_1 V_98 , V_99 ;
int V_43 , V_71 , V_100 , V_101 ;
V_101 = V_204 -> V_208 . V_209 ;
V_71 = F_146 ( V_204 ) ;
if ( V_71 > V_84 ) {
F_60 ( V_30 , L_80 ,
V_101 , V_71 ) ;
return;
}
V_100 = F_69 ( V_30 , V_204 -> V_340 ) ;
if ( V_100 != F_59 () ) {
F_60 ( V_30 , L_81 ,
V_101 , V_100 ) ;
return;
}
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
memcpy ( V_70 , V_204 -> V_250 , V_71 ) ;
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
static void F_244 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
F_245 ( V_30 , V_204 -> V_331 , V_204 -> V_332 ) ;
}
static int F_246 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_176 , V_126 ;
int V_101 = V_204 -> V_208 . V_209 ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
return error ;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
V_176 = V_5 -> V_15 ;
error = F_122 ( V_5 , V_178 ) ;
if ( error ) {
F_60 ( V_30 , L_87 ,
V_5 -> V_8 , V_101 , V_204 -> V_333 , V_204 -> V_207 ) ;
F_5 ( V_19 ) ;
goto V_111;
}
if ( V_176 == V_185 ) {
V_19 -> V_21 = V_101 ;
V_19 -> V_20 = V_101 ;
V_5 -> V_7 = V_101 ;
}
V_126 = V_204 -> V_207 ;
switch ( V_126 ) {
case - V_73 :
F_28 ( V_19 , V_5 , - V_73 ) ;
F_182 ( V_19 , - V_73 ) ;
F_102 ( V_5 ) ;
break;
case - V_286 :
case 0 :
F_226 ( V_5 , V_204 ) ;
V_5 -> V_9 = V_204 -> V_333 ;
if ( F_17 ( V_5 ) )
F_158 ( V_5 , V_204 ) ;
if ( V_126 ) {
F_105 ( V_19 , V_5 , V_172 ) ;
F_133 ( V_5 ) ;
} else {
F_154 ( V_19 , V_5 , V_204 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
}
F_182 ( V_19 , V_126 ) ;
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
F_182 ( V_19 , V_126 ) ;
F_102 ( V_5 ) ;
} else {
F_180 ( V_19 , V_5 ) ;
if ( V_19 -> V_21 == F_59 () )
F_182 ( V_19 , 0 ) ;
}
break;
default:
F_60 ( V_30 , L_90 ,
V_5 -> V_8 , V_126 ) ;
}
if ( F_25 ( V_5 ) && ( V_126 == 0 || V_126 == - V_286 ) ) {
F_46 ( V_30 , L_91 ,
V_5 -> V_8 , V_126 ) ;
V_5 -> V_11 &= ~ V_41 ;
V_5 -> V_11 &= ~ V_42 ;
F_200 ( V_19 , V_5 ) ;
} else if ( F_26 ( V_5 ) && ( V_126 == - V_286 ) ) {
F_46 ( V_30 , L_92 , V_5 -> V_8 ) ;
V_5 -> V_11 &= ~ V_41 ;
V_5 -> V_11 &= ~ V_42 ;
F_201 ( V_19 , V_5 ) ;
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
static void F_218 ( struct V_18 * V_19 , struct V_4 * V_5 ,
struct V_203 * V_204 )
{
switch ( V_204 -> V_207 ) {
case - V_73 :
F_28 ( V_19 , V_5 , - V_73 ) ;
break;
case - V_48 :
F_226 ( V_5 , V_204 ) ;
F_151 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_48 ) ;
break;
case - V_286 :
F_226 ( V_5 , V_204 ) ;
if ( F_16 ( V_5 ) )
F_157 ( V_5 ) ;
F_108 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_174 ) ;
F_133 ( V_5 ) ;
break;
case 0 :
F_226 ( V_5 , V_204 ) ;
if ( F_16 ( V_5 ) )
F_157 ( V_5 ) ;
F_154 ( V_19 , V_5 , V_204 ) ;
F_28 ( V_19 , V_5 , 0 ) ;
break;
default:
F_60 ( V_19 -> V_54 , L_93 ,
V_5 -> V_8 , V_204 -> V_208 . V_209 , V_204 -> V_333 ,
V_204 -> V_207 ) ;
F_4 ( V_19 ) ;
F_2 ( V_5 ) ;
}
}
static void F_247 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
struct V_18 * V_19 = V_5 -> V_146 ;
int error ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
error = F_123 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
F_218 ( V_19 , V_5 , V_204 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static int F_248 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
return error ;
F_247 ( V_5 , V_204 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_249 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
struct V_18 * V_19 = V_5 -> V_146 ;
int error ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
error = F_123 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
switch ( V_204 -> V_207 ) {
case - V_50 :
F_226 ( V_5 , V_204 ) ;
F_149 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_50 ) ;
break;
case - V_162 :
break;
default:
F_60 ( V_19 -> V_54 , L_94 ,
V_5 -> V_8 , V_204 -> V_207 ) ;
}
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static int F_250 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
return error ;
F_249 ( V_5 , V_204 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_251 ( struct V_4 * V_5 , struct V_203 * V_204 )
{
struct V_18 * V_19 = V_5 -> V_146 ;
int error ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_234 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
error = F_123 ( V_5 , V_204 ) ;
if ( error )
goto V_111;
switch ( V_204 -> V_207 ) {
case - V_44 :
F_226 ( V_5 , V_204 ) ;
F_151 ( V_19 , V_5 ) ;
F_28 ( V_19 , V_5 , - V_44 ) ;
break;
case 0 :
break;
default:
F_60 ( V_19 -> V_54 , L_95 ,
V_5 -> V_8 , V_204 -> V_207 ) ;
}
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
}
static int F_252 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
int error ;
error = F_94 ( V_30 , V_204 -> V_334 , & V_5 ) ;
if ( error )
return error ;
F_251 ( V_5 , V_204 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
static void F_253 ( struct V_29 * V_30 , struct V_203 * V_204 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error , V_347 ;
int V_353 = 0 ;
error = F_94 ( V_30 , V_204 -> V_333 , & V_5 ) ;
if ( error ) {
F_60 ( V_30 , L_96 , V_204 -> V_333 ) ;
return;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_122 ( V_5 , V_186 ) ;
if ( error )
goto V_111;
V_347 = V_204 -> V_331 ;
if ( V_19 -> V_21 && ( V_19 -> V_21 != V_347 ) ) {
F_60 ( V_30 , L_97
L_98 ,
V_5 -> V_8 , V_204 -> V_208 . V_209 , V_347 ,
V_19 -> V_21 , V_19 -> V_22 ,
F_59 () , V_19 -> V_24 , V_19 -> V_26 ) ;
}
if ( V_347 == F_59 () ) {
V_19 -> V_21 = V_347 ;
V_19 -> V_20 = 0 ;
V_353 = 1 ;
V_19 -> V_24 = 0 ;
} else if ( V_347 == - 1 ) {
F_60 ( V_30 , L_99 ,
V_5 -> V_8 , V_204 -> V_208 . V_209 ) ;
V_19 -> V_21 = 0 ;
V_19 -> V_20 = - 1 ;
V_5 -> V_7 = - 1 ;
} else {
V_19 -> V_21 = V_347 ;
V_19 -> V_20 = V_347 ;
}
if ( F_27 ( V_5 ) ) {
F_46 ( V_30 , L_100 ,
V_5 -> V_8 , V_5 -> V_11 ) ;
F_31 ( V_19 , V_5 ) ;
F_102 ( V_5 ) ;
goto V_354;
}
F_180 ( V_19 , V_5 ) ;
V_354:
if ( V_353 )
F_179 ( V_19 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
}
static void F_254 ( struct V_29 * V_30 , struct V_203 * V_204 ,
T_1 V_355 )
{
int error = 0 , V_356 = 0 ;
if ( ! F_255 ( V_30 , V_204 -> V_208 . V_209 ) ) {
F_75 ( V_30 , L_101 ,
V_204 -> V_213 , V_204 -> V_208 . V_209 , V_204 -> V_333 ,
V_204 -> V_334 , V_204 -> V_207 ) ;
return;
}
switch ( V_204 -> V_213 ) {
case V_177 :
error = F_236 ( V_30 , V_204 ) ;
break;
case V_179 :
error = F_237 ( V_30 , V_204 ) ;
break;
case V_181 :
error = F_238 ( V_30 , V_204 ) ;
break;
case V_183 :
V_356 = 1 ;
error = F_239 ( V_30 , V_204 ) ;
break;
case V_178 :
error = F_246 ( V_30 , V_204 ) ;
break;
case V_180 :
error = F_248 ( V_30 , V_204 ) ;
break;
case V_182 :
error = F_250 ( V_30 , V_204 ) ;
break;
case V_184 :
error = F_252 ( V_30 , V_204 ) ;
break;
case V_254 :
V_356 = 1 ;
error = F_240 ( V_30 , V_204 ) ;
break;
case V_344 :
V_356 = 1 ;
error = F_241 ( V_30 , V_204 ) ;
break;
case V_185 :
F_242 ( V_30 , V_204 ) ;
break;
case V_330 :
F_243 ( V_30 , V_204 ) ;
break;
case V_186 :
F_253 ( V_30 , V_204 ) ;
break;
case V_357 :
F_244 ( V_30 , V_204 ) ;
break;
default:
F_60 ( V_30 , L_102 , V_204 -> V_213 ) ;
}
if ( error == - V_162 && V_356 ) {
F_46 ( V_30 , L_103 ,
V_204 -> V_213 , V_204 -> V_334 , V_204 -> V_208 . V_209 ,
V_204 -> V_333 , V_355 ) ;
} else if ( error == - V_162 ) {
F_60 ( V_30 , L_103 ,
V_204 -> V_213 , V_204 -> V_334 , V_204 -> V_208 . V_209 ,
V_204 -> V_333 , V_355 ) ;
if ( V_204 -> V_213 == V_179 )
F_78 ( V_30 , V_204 -> V_340 ) ;
}
if ( error == - V_123 ) {
F_60 ( V_30 , L_104
L_105 ,
V_204 -> V_213 , V_204 -> V_208 . V_209 ,
V_204 -> V_333 , V_204 -> V_334 , V_355 ) ;
}
}
static void F_256 ( struct V_29 * V_30 , struct V_203 * V_204 ,
int V_187 )
{
if ( F_131 ( V_30 ) ) {
if ( ! V_30 -> V_358 ) {
F_75 ( V_30 , L_106 ,
V_204 -> V_213 , V_187 ) ;
return;
}
F_257 ( V_30 , V_187 , V_204 ) ;
} else {
F_258 ( V_30 ) ;
F_254 ( V_30 , V_204 , 0 ) ;
}
}
void F_259 ( struct V_29 * V_30 , struct V_203 * V_204 ,
T_1 V_355 )
{
F_254 ( V_30 , V_204 , V_355 ) ;
}
void F_260 ( union V_359 * V_360 , int V_187 )
{
struct V_361 * V_362 = & V_360 -> V_363 ;
struct V_29 * V_30 ;
int type = 0 ;
switch ( V_362 -> V_328 ) {
case V_329 :
F_261 ( & V_360 -> V_364 ) ;
type = V_360 -> V_364 . V_213 ;
break;
case V_365 :
F_262 ( & V_360 -> V_366 ) ;
type = V_360 -> V_366 . V_367 ;
break;
default:
F_55 ( L_107 , V_362 -> V_328 , V_187 ) ;
return;
}
if ( V_362 -> V_209 != V_187 ) {
F_55 ( L_108 ,
V_362 -> V_209 , V_187 , V_362 -> V_325 ) ;
return;
}
V_30 = F_263 ( V_362 -> V_325 ) ;
if ( ! V_30 ) {
if ( V_65 . V_368 ) {
F_264 ( V_369 L_109
L_110 ,
V_362 -> V_325 , V_187 , V_362 -> V_328 , type ) ;
}
if ( V_362 -> V_328 == V_365 && type == V_370 )
F_265 ( V_187 , & V_360 -> V_366 ) ;
return;
}
F_9 ( & V_30 -> V_371 ) ;
if ( V_362 -> V_328 == V_329 )
F_256 ( V_30 , & V_360 -> V_364 , V_187 ) ;
else
F_266 ( V_30 , & V_360 -> V_366 , V_187 ) ;
F_11 ( & V_30 -> V_371 ) ;
F_208 ( V_30 ) ;
}
static void F_267 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_203 * V_372 )
{
if ( F_23 ( V_5 ) ) {
F_101 ( V_5 ) ;
memset ( V_372 , 0 , sizeof( struct V_203 ) ) ;
V_372 -> V_211 = V_212 ;
V_372 -> V_213 = V_180 ;
V_372 -> V_207 = - V_286 ;
V_372 -> V_208 . V_209 = V_5 -> V_7 ;
F_247 ( V_5 , V_372 ) ;
V_5 -> V_14 = V_148 ;
F_62 ( V_5 -> V_146 , V_373 ) ;
F_102 ( V_5 ) ;
} else if ( V_5 -> V_13 >= V_5 -> V_14 ) {
V_5 -> V_11 |= V_210 ;
}
}
static int F_268 ( struct V_29 * V_30 , struct V_4 * V_5 ,
int V_100 )
{
if ( F_70 ( V_30 ) )
return 1 ;
if ( F_74 ( V_30 , V_5 -> V_16 ) )
return 1 ;
return 0 ;
}
void F_269 ( struct V_29 * V_30 )
{
struct V_4 * V_5 , * V_285 ;
struct V_203 * V_372 ;
int V_374 , V_375 , V_376 ;
int V_100 ;
V_372 = F_270 ( sizeof( struct V_203 ) , V_197 ) ;
if ( ! V_372 ) {
F_60 ( V_30 , L_111 ) ;
return;
}
F_113 ( & V_30 -> V_195 ) ;
F_167 (lkb, safe, &ls->ls_waiters, lkb_wait_reply) {
V_100 = F_127 ( V_5 -> V_146 ) ;
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
V_5 -> V_11 |= V_210 ;
continue;
}
if ( ! F_268 ( V_30 , V_5 , V_100 ) )
continue;
V_374 = V_5 -> V_15 ;
V_375 = - V_50 ;
V_376 = - V_44 ;
if ( ! V_374 ) {
if ( F_26 ( V_5 ) ) {
V_374 = V_183 ;
if ( V_5 -> V_14 == V_148 )
V_376 = 0 ;
}
if ( F_25 ( V_5 ) ) {
V_374 = V_181 ;
if ( V_5 -> V_14 == V_148 )
V_375 = - V_162 ;
}
F_46 ( V_30 , L_114 ,
V_5 -> V_8 , V_5 -> V_11 , V_374 ,
V_376 , V_375 ) ;
}
switch ( V_374 ) {
case V_177 :
V_5 -> V_11 |= V_210 ;
break;
case V_179 :
F_267 ( V_30 , V_5 , V_372 ) ;
break;
case V_181 :
F_101 ( V_5 ) ;
memset ( V_372 , 0 , sizeof( struct V_203 ) ) ;
V_372 -> V_211 = V_212 ;
V_372 -> V_213 = V_182 ;
V_372 -> V_207 = V_375 ;
V_372 -> V_208 . V_209 = V_5 -> V_7 ;
F_249 ( V_5 , V_372 ) ;
F_100 ( V_5 ) ;
break;
case V_183 :
F_101 ( V_5 ) ;
memset ( V_372 , 0 , sizeof( struct V_203 ) ) ;
V_372 -> V_211 = V_212 ;
V_372 -> V_213 = V_184 ;
V_372 -> V_207 = V_376 ;
V_372 -> V_208 . V_209 = V_5 -> V_7 ;
F_251 ( V_5 , V_372 ) ;
F_100 ( V_5 ) ;
break;
default:
F_60 ( V_30 , L_115 ,
V_5 -> V_15 , V_374 ) ;
}
F_181 () ;
}
F_117 ( & V_30 -> V_195 ) ;
F_118 ( V_372 ) ;
}
static struct V_4 * F_271 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
int V_91 = 0 ;
F_113 ( & V_30 -> V_195 ) ;
F_7 (lkb, &ls->ls_waiters, lkb_wait_reply) {
if ( V_5 -> V_11 & V_210 ) {
F_101 ( V_5 ) ;
V_91 = 1 ;
break;
}
}
F_117 ( & V_30 -> V_195 ) ;
if ( ! V_91 )
V_5 = NULL ;
return V_5 ;
}
int F_272 ( struct V_29 * V_30 )
{
struct V_4 * V_5 ;
struct V_18 * V_19 ;
int error = 0 , V_176 , V_267 , V_377 , V_378 ;
while ( 1 ) {
if ( F_131 ( V_30 ) ) {
F_46 ( V_30 , L_116 ) ;
error = - V_379 ;
break;
}
V_5 = F_271 ( V_30 ) ;
if ( ! V_5 )
break;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
V_176 = V_5 -> V_15 ;
V_377 = F_26 ( V_5 ) ;
V_378 = F_25 ( V_5 ) ;
V_267 = 0 ;
F_46 ( V_30 , L_112
L_117
L_118 , V_5 -> V_8 , V_5 -> V_9 , V_176 ,
V_19 -> V_20 , V_5 -> V_7 , V_5 -> V_16 ,
F_127 ( V_19 ) , V_377 , V_378 ) ;
V_5 -> V_11 &= ~ V_210 ;
V_5 -> V_11 &= ~ V_41 ;
V_5 -> V_11 &= ~ V_42 ;
V_5 -> V_15 = 0 ;
V_5 -> V_200 = 0 ;
F_113 ( & V_30 -> V_195 ) ;
F_121 ( & V_5 -> V_201 ) ;
F_117 ( & V_30 -> V_195 ) ;
F_102 ( V_5 ) ;
if ( V_377 || V_378 ) {
switch ( V_176 ) {
case V_185 :
case V_177 :
F_28 ( V_19 , V_5 , V_378 ? - V_50 :
- V_44 ) ;
F_102 ( V_5 ) ;
break;
case V_179 :
if ( V_377 ) {
F_28 ( V_19 , V_5 , - V_44 ) ;
} else {
V_5 -> V_10 |= V_301 ;
F_199 ( V_19 , V_5 ) ;
}
break;
default:
V_267 = 1 ;
}
} else {
switch ( V_176 ) {
case V_185 :
case V_177 :
F_180 ( V_19 , V_5 ) ;
if ( F_172 ( V_19 ) )
F_182 ( V_19 , 0 ) ;
break;
case V_179 :
F_197 ( V_19 , V_5 ) ;
break;
default:
V_267 = 1 ;
}
}
if ( V_267 ) {
F_60 ( V_30 , L_119
L_120 ,
V_5 -> V_8 , V_176 , V_19 -> V_20 ,
F_127 ( V_19 ) , V_377 , V_378 ) ;
}
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
}
return error ;
}
static void F_273 ( struct V_29 * V_30 , struct V_18 * V_19 ,
struct V_164 * V_380 )
{
struct V_4 * V_5 , * V_285 ;
F_167 (lkb, safe, list, lkb_statequeue) {
if ( ! F_22 ( V_5 ) )
continue;
if ( V_5 -> V_17 == V_30 -> V_381 )
continue;
F_108 ( V_19 , V_5 ) ;
if ( ! F_100 ( V_5 ) )
F_60 ( V_30 , L_121 ) ;
}
}
void F_274 ( struct V_18 * V_19 )
{
struct V_29 * V_30 = V_19 -> V_54 ;
F_273 ( V_30 , V_19 , & V_19 -> V_79 ) ;
F_273 ( V_30 , V_19 , & V_19 -> V_80 ) ;
F_273 ( V_30 , V_19 , & V_19 -> V_81 ) ;
}
static void F_275 ( struct V_29 * V_30 , struct V_18 * V_19 ,
struct V_164 * V_380 ,
int V_382 , unsigned int * V_62 )
{
struct V_4 * V_5 , * V_285 ;
F_167 (lkb, safe, list, lkb_statequeue) {
if ( ! F_22 ( V_5 ) )
continue;
if ( ( V_5 -> V_7 == V_382 ) ||
F_74 ( V_30 , V_5 -> V_7 ) ) {
if ( ( V_5 -> V_10 & V_243 ) &&
( V_5 -> V_14 >= V_249 ) ) {
F_62 ( V_19 , V_383 ) ;
}
F_108 ( V_19 , V_5 ) ;
if ( ! F_100 ( V_5 ) )
F_60 ( V_30 , L_122 ) ;
F_62 ( V_19 , V_274 ) ;
( * V_62 ) ++ ;
}
}
}
void F_276 ( struct V_29 * V_30 )
{
struct V_18 * V_19 ;
struct V_384 * V_385 ;
int V_386 = 0 ;
int V_382 = 0 ;
unsigned int V_387 = 0 ;
F_7 (memb, &ls->ls_nodes_gone, list) {
V_386 ++ ;
V_382 = V_385 -> V_187 ;
}
if ( ! V_386 )
return;
F_277 ( & V_30 -> V_388 ) ;
F_7 (r, &ls->ls_root_list, res_root_list) {
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
if ( F_172 ( V_19 ) ) {
F_275 ( V_30 , V_19 , & V_19 -> V_79 ,
V_382 , & V_387 ) ;
F_275 ( V_30 , V_19 , & V_19 -> V_80 ,
V_382 , & V_387 ) ;
F_275 ( V_30 , V_19 , & V_19 -> V_81 ,
V_382 , & V_387 ) ;
}
F_77 ( V_19 ) ;
F_84 ( V_19 ) ;
F_132 () ;
}
F_278 ( & V_30 -> V_388 ) ;
if ( V_387 )
F_279 ( V_30 , L_123 ,
V_387 , V_386 ) ;
}
static struct V_18 * F_280 ( struct V_29 * V_30 , int V_55 )
{
struct V_75 * V_140 ;
struct V_18 * V_19 ;
F_38 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
for ( V_140 = F_79 ( & V_30 -> V_57 [ V_55 ] . V_112 ) ; V_140 ; V_140 = F_80 ( V_140 ) ) {
V_19 = F_53 ( V_140 , struct V_18 , V_74 ) ;
if ( ! F_143 ( V_19 , V_274 ) )
continue;
if ( ! F_172 ( V_19 ) ) {
F_61 ( V_19 , V_274 ) ;
continue;
}
F_34 ( V_19 ) ;
F_40 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
return V_19 ;
}
F_40 ( & V_30 -> V_57 [ V_55 ] . V_58 ) ;
return NULL ;
}
void F_281 ( struct V_29 * V_30 )
{
struct V_18 * V_19 ;
int V_55 = 0 ;
unsigned int V_62 = 0 ;
unsigned int V_389 = 0 ;
unsigned int V_387 = 0 ;
while ( 1 ) {
V_19 = F_280 ( V_30 , V_55 ) ;
if ( ! V_19 ) {
if ( V_55 == V_30 -> V_124 - 1 )
break;
V_55 ++ ;
continue;
}
V_389 ++ ;
V_62 = 0 ;
F_73 ( V_19 ) ;
F_171 ( V_19 , & V_62 ) ;
F_61 ( V_19 , V_274 ) ;
V_387 += V_62 ;
F_182 ( V_19 , 0 ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_132 () ;
}
if ( V_387 )
F_279 ( V_30 , L_124 ,
V_387 , V_389 ) ;
}
static struct V_4 * F_282 ( struct V_164 * V_166 , int V_187 ,
T_1 V_390 )
{
struct V_4 * V_5 ;
F_7 (lkb, head, lkb_statequeue) {
if ( V_5 -> V_7 == V_187 && V_5 -> V_9 == V_390 )
return V_5 ;
}
return NULL ;
}
static struct V_4 * F_283 ( struct V_18 * V_19 , int V_187 ,
T_1 V_390 )
{
struct V_4 * V_5 ;
V_5 = F_282 ( & V_19 -> V_79 , V_187 , V_390 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_282 ( & V_19 -> V_80 , V_187 , V_390 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_282 ( & V_19 -> V_81 , V_187 , V_390 ) ;
if ( V_5 )
return V_5 ;
return NULL ;
}
static int F_284 ( struct V_29 * V_30 , struct V_4 * V_5 ,
struct V_18 * V_19 , struct V_391 * V_88 )
{
struct V_392 * V_393 = (struct V_392 * ) V_88 -> V_394 ;
V_5 -> V_7 = V_88 -> V_395 . V_209 ;
V_5 -> V_306 = F_285 ( V_393 -> V_396 ) ;
V_5 -> V_9 = F_285 ( V_393 -> V_397 ) ;
V_5 -> V_10 = F_285 ( V_393 -> V_398 ) ;
V_5 -> V_11 = F_285 ( V_393 -> V_399 ) & 0x0000FFFF ;
V_5 -> V_11 |= V_38 ;
V_5 -> V_244 = F_285 ( V_393 -> V_400 ) ;
V_5 -> V_13 = V_393 -> V_401 ;
V_5 -> V_14 = V_393 -> V_402 ;
V_5 -> V_283 = ( V_393 -> V_403 & V_52 ) ? & F_228 : NULL ;
V_5 -> V_303 = ( V_393 -> V_403 & V_49 ) ? & F_229 : NULL ;
if ( V_5 -> V_10 & V_243 ) {
int V_404 = V_88 -> V_395 . V_327 - sizeof( struct V_391 ) -
sizeof( struct V_392 ) ;
if ( V_404 > V_30 -> V_241 )
return - V_123 ;
V_5 -> V_163 = F_142 ( V_30 ) ;
if ( ! V_5 -> V_163 )
return - V_69 ;
memcpy ( V_5 -> V_163 , V_393 -> V_405 , V_404 ) ;
}
if ( V_393 -> V_406 == F_286 ( V_179 ) &&
F_23 ( V_5 ) ) {
V_393 -> V_407 = V_174 ;
V_5 -> V_14 = V_148 ;
F_62 ( V_19 , V_373 ) ;
}
return 0 ;
}
int F_287 ( struct V_29 * V_30 , struct V_391 * V_88 )
{
struct V_392 * V_393 = (struct V_392 * ) V_88 -> V_394 ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
T_1 V_390 = 0 ;
int V_101 = V_88 -> V_395 . V_209 ;
int error ;
if ( V_393 -> V_408 ) {
error = - V_409 ;
goto V_111;
}
V_390 = F_285 ( V_393 -> V_397 ) ;
error = F_67 ( V_30 , V_393 -> V_410 , F_288 ( V_393 -> V_411 ) ,
V_101 , V_122 , & V_19 ) ;
if ( error )
goto V_111;
F_73 ( V_19 ) ;
if ( F_70 ( V_30 ) && ( F_127 ( V_19 ) != F_59 () ) ) {
F_60 ( V_30 , L_125 ,
V_101 , V_390 ) ;
error = - V_92 ;
goto V_114;
}
V_5 = F_283 ( V_19 , V_101 , V_390 ) ;
if ( V_5 ) {
error = - V_97 ;
goto V_412;
}
error = F_88 ( V_30 , & V_5 ) ;
if ( error )
goto V_114;
error = F_284 ( V_30 , V_5 , V_19 , V_88 ) ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_114;
}
F_86 ( V_19 , V_5 ) ;
F_105 ( V_19 , V_5 , V_393 -> V_407 ) ;
error = 0 ;
V_30 -> V_413 ++ ;
if ( ! F_6 ( & V_19 -> V_81 ) || ! F_6 ( & V_19 -> V_80 ) )
F_62 ( V_19 , V_274 ) ;
V_412:
V_393 -> V_414 = F_289 ( V_5 -> V_8 ) ;
V_5 -> V_17 = V_30 -> V_381 ;
V_114:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
V_111:
if ( error && error != - V_97 )
F_279 ( V_30 , L_126 ,
V_101 , V_390 , error ) ;
V_393 -> V_415 = F_289 ( error ) ;
return error ;
}
int F_290 ( struct V_29 * V_30 , struct V_391 * V_88 )
{
struct V_392 * V_393 = (struct V_392 * ) V_88 -> V_394 ;
struct V_18 * V_19 ;
struct V_4 * V_5 ;
T_1 V_161 , V_390 ;
int error , V_126 ;
V_161 = F_285 ( V_393 -> V_397 ) ;
V_390 = F_285 ( V_393 -> V_414 ) ;
V_126 = F_285 ( V_393 -> V_415 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error ) {
F_60 ( V_30 , L_127 ,
V_161 , V_88 -> V_395 . V_209 , V_390 , V_126 ) ;
return error ;
}
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
if ( ! F_21 ( V_5 ) ) {
F_60 ( V_30 , L_128 ,
V_161 , V_88 -> V_395 . V_209 , V_390 , V_126 ) ;
F_5 ( V_19 ) ;
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return - V_123 ;
}
switch ( V_126 ) {
case - V_92 :
F_46 ( V_30 , L_129 ,
V_161 , V_88 -> V_395 . V_209 , V_390 , V_126 ) ;
F_291 ( V_19 , V_5 ) ;
goto V_111;
case - V_97 :
case 0 :
V_5 -> V_9 = V_390 ;
break;
default:
F_60 ( V_30 , L_130 ,
V_161 , V_88 -> V_395 . V_209 , V_390 , V_126 ) ;
}
F_292 ( V_19 ) ;
V_111:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
F_100 ( V_5 ) ;
return 0 ;
}
int F_293 ( struct V_29 * V_30 , struct V_416 * V_417 ,
int V_167 , T_1 V_102 , void * V_70 , unsigned int V_289 ,
unsigned long V_290 )
{
struct V_4 * V_5 ;
struct V_292 args ;
int error ;
F_8 ( V_30 ) ;
error = F_88 ( V_30 , & V_5 ) ;
if ( error ) {
F_118 ( V_417 ) ;
goto V_111;
}
if ( V_102 & V_243 ) {
V_417 -> V_288 . V_295 = F_116 ( V_418 , V_157 ) ;
if ( ! V_417 -> V_288 . V_295 ) {
F_118 ( V_417 ) ;
F_97 ( V_30 , V_5 ) ;
error = - V_69 ;
goto V_111;
}
}
error = F_183 ( V_167 , & V_417 -> V_288 , V_102 , V_289 , V_290 ,
F_229 , V_417 , F_228 , & args ) ;
V_5 -> V_11 |= V_419 ;
if ( error ) {
F_97 ( V_30 , V_5 ) ;
goto V_111;
}
error = F_202 ( V_30 , V_5 , V_70 , V_289 , & args ) ;
switch ( error ) {
case 0 :
break;
case - V_286 :
error = 0 ;
break;
case - V_73 :
error = 0 ;
default:
F_97 ( V_30 , V_5 ) ;
goto V_111;
}
F_38 ( & V_417 -> V_420 -> V_421 ) ;
F_101 ( V_5 ) ;
F_107 ( & V_5 -> V_150 , & V_417 -> V_420 -> V_422 ) ;
F_40 ( & V_417 -> V_420 -> V_421 ) ;
V_111:
F_10 ( V_30 ) ;
return error ;
}
int F_294 ( struct V_29 * V_30 , struct V_416 * V_423 ,
int V_167 , T_1 V_102 , T_1 V_161 , char * V_424 ,
unsigned long V_290 )
{
struct V_4 * V_5 ;
struct V_292 args ;
struct V_416 * V_417 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_417 = V_5 -> V_425 ;
if ( V_102 & V_243 && ! V_417 -> V_288 . V_295 ) {
V_417 -> V_288 . V_295 = F_116 ( V_418 , V_157 ) ;
if ( ! V_417 -> V_288 . V_295 ) {
error = - V_69 ;
goto V_314;
}
}
if ( V_424 && V_417 -> V_288 . V_295 )
memcpy ( V_417 -> V_288 . V_295 , V_424 , V_418 ) ;
V_417 -> V_426 = V_423 -> V_426 ;
V_417 -> V_427 = V_423 -> V_427 ;
V_417 -> V_428 = V_423 -> V_428 ;
V_417 -> V_429 = V_423 -> V_429 ;
V_417 -> V_430 = V_423 -> V_430 ;
V_417 -> V_431 = V_423 -> V_431 ;
error = F_183 ( V_167 , & V_417 -> V_288 , V_102 , 0 , V_290 ,
F_229 , V_417 , F_228 , & args ) ;
if ( error )
goto V_314;
error = F_203 ( V_30 , V_5 , & args ) ;
if ( error == - V_286 || error == - V_73 || error == - V_48 )
error = 0 ;
V_314:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_118 ( V_423 ) ;
return error ;
}
int F_295 ( struct V_29 * V_30 , struct V_416 * V_423 ,
int V_167 , T_1 V_102 , void * V_70 , unsigned int V_289 ,
unsigned long V_290 , T_1 * V_161 )
{
struct V_4 * V_5 ;
struct V_416 * V_417 ;
int V_432 = 0 ;
int V_91 = 0 ;
int V_43 = 0 ;
F_113 ( & V_30 -> V_433 ) ;
F_7 (lkb, &ls->ls_orphans, lkb_ownqueue) {
if ( V_5 -> V_146 -> V_76 != V_289 )
continue;
if ( memcmp ( V_5 -> V_146 -> V_26 , V_70 , V_289 ) )
continue;
if ( V_5 -> V_14 != V_167 ) {
V_432 = 1 ;
continue;
}
V_91 = 1 ;
F_121 ( & V_5 -> V_150 ) ;
V_5 -> V_11 &= ~ V_434 ;
* V_161 = V_5 -> V_8 ;
break;
}
F_117 ( & V_30 -> V_433 ) ;
if ( ! V_91 && V_432 ) {
V_43 = - V_73 ;
goto V_111;
}
if ( ! V_91 ) {
V_43 = - V_162 ;
goto V_111;
}
V_5 -> V_10 = V_102 ;
V_5 -> V_306 = ( int ) V_307 -> V_308 ;
V_417 = V_5 -> V_425 ;
V_417 -> V_420 = V_423 -> V_420 ;
V_417 -> V_426 = V_423 -> V_426 ;
V_417 -> V_427 = V_423 -> V_427 ;
V_417 -> V_428 = V_423 -> V_428 ;
V_417 -> V_429 = V_423 -> V_429 ;
V_417 -> V_430 = V_423 -> V_430 ;
V_417 -> V_431 = V_423 -> V_431 ;
F_38 ( & V_417 -> V_420 -> V_421 ) ;
F_107 ( & V_5 -> V_150 , & V_417 -> V_420 -> V_422 ) ;
F_40 ( & V_417 -> V_420 -> V_421 ) ;
V_111:
F_118 ( V_423 ) ;
return V_43 ;
}
int F_296 ( struct V_29 * V_30 , struct V_416 * V_423 ,
T_1 V_102 , T_1 V_161 , char * V_424 )
{
struct V_4 * V_5 ;
struct V_292 args ;
struct V_416 * V_417 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_417 = V_5 -> V_425 ;
if ( V_424 && V_417 -> V_288 . V_295 )
memcpy ( V_417 -> V_288 . V_295 , V_424 , V_418 ) ;
if ( V_423 -> V_427 )
V_417 -> V_427 = V_423 -> V_427 ;
V_417 -> V_431 = V_423 -> V_431 ;
error = F_186 ( V_102 , V_417 , & args ) ;
if ( error )
goto V_314;
error = F_204 ( V_30 , V_5 , & args ) ;
if ( error == - V_50 )
error = 0 ;
if ( error == - V_199 && ( V_102 & V_301 ) )
error = 0 ;
if ( error )
goto V_314;
F_38 ( & V_417 -> V_420 -> V_421 ) ;
if ( ! F_6 ( & V_5 -> V_150 ) )
F_297 ( & V_5 -> V_150 , & V_417 -> V_420 -> V_435 ) ;
F_40 ( & V_417 -> V_420 -> V_421 ) ;
V_314:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_118 ( V_423 ) ;
return error ;
}
int F_298 ( struct V_29 * V_30 , struct V_416 * V_423 ,
T_1 V_102 , T_1 V_161 )
{
struct V_4 * V_5 ;
struct V_292 args ;
struct V_416 * V_417 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_417 = V_5 -> V_425 ;
if ( V_423 -> V_427 )
V_417 -> V_427 = V_423 -> V_427 ;
V_417 -> V_431 = V_423 -> V_431 ;
error = F_186 ( V_102 , V_417 , & args ) ;
if ( error )
goto V_314;
error = F_205 ( V_30 , V_5 , & args ) ;
if ( error == - V_44 )
error = 0 ;
if ( error == - V_199 )
error = 0 ;
V_314:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
F_118 ( V_423 ) ;
return error ;
}
int F_299 ( struct V_29 * V_30 , T_1 V_102 , T_1 V_161 )
{
struct V_4 * V_5 ;
struct V_292 args ;
struct V_416 * V_417 ;
struct V_18 * V_19 ;
int error ;
F_8 ( V_30 ) ;
error = F_94 ( V_30 , V_161 , & V_5 ) ;
if ( error )
goto V_111;
V_417 = V_5 -> V_425 ;
error = F_186 ( V_102 , V_417 , & args ) ;
if ( error )
goto V_314;
V_19 = V_5 -> V_146 ;
F_34 ( V_19 ) ;
F_73 ( V_19 ) ;
error = F_188 ( V_5 , & args ) ;
if ( error )
goto V_436;
V_5 -> V_11 |= V_47 ;
error = F_137 ( V_19 , V_5 ) ;
V_436:
F_77 ( V_19 ) ;
F_37 ( V_19 ) ;
if ( error == - V_44 )
error = 0 ;
if ( error == - V_199 )
error = 0 ;
V_314:
F_100 ( V_5 ) ;
V_111:
F_10 ( V_30 ) ;
return error ;
}
static int F_300 ( struct V_29 * V_30 , struct V_4 * V_5 )
{
struct V_292 args ;
int error ;
F_101 ( V_5 ) ;
F_113 ( & V_30 -> V_433 ) ;
F_107 ( & V_5 -> V_150 , & V_30 -> V_437 ) ;
F_117 ( & V_30 -> V_433 ) ;
F_186 ( 0 , V_5 -> V_425 , & args ) ;
error = F_205 ( V_30 , V_5 , & args ) ;
if ( error == - V_44 )
error = 0 ;
return error ;
}
static int F_301 ( struct V_29 * V_30 , struct V_4 * V_5 )
{
struct V_292 args ;
int error ;
F_186 ( V_301 | V_246 ,
V_5 -> V_425 , & args ) ;
error = F_204 ( V_30 , V_5 , & args ) ;
if ( error == - V_50 )
error = 0 ;
return error ;
}
static struct V_4 * F_302 ( struct V_29 * V_30 ,
struct V_438 * V_420 )
{
struct V_4 * V_5 = NULL ;
F_113 ( & V_30 -> V_439 ) ;
if ( F_6 ( & V_420 -> V_422 ) )
goto V_111;
V_5 = F_160 ( V_420 -> V_422 . V_218 , struct V_4 , V_150 ) ;
F_121 ( & V_5 -> V_150 ) ;
if ( V_5 -> V_10 & V_440 )
V_5 -> V_11 |= V_434 ;
else
V_5 -> V_11 |= V_441 ;
V_111:
F_117 ( & V_30 -> V_439 ) ;
return V_5 ;
}
void F_303 ( struct V_29 * V_30 , struct V_438 * V_420 )
{
struct V_4 * V_5 , * V_285 ;
F_8 ( V_30 ) ;
while ( 1 ) {
V_5 = F_302 ( V_30 , V_420 ) ;
if ( ! V_5 )
break;
F_29 ( V_5 ) ;
if ( V_5 -> V_10 & V_440 )
F_300 ( V_30 , V_5 ) ;
else
F_301 ( V_30 , V_5 ) ;
F_100 ( V_5 ) ;
}
F_113 ( & V_30 -> V_439 ) ;
F_167 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_121 ( & V_5 -> V_150 ) ;
V_5 -> V_11 |= V_441 ;
F_100 ( V_5 ) ;
}
F_167 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_442 , 0 ,
sizeof( struct V_443 ) * V_444 ) ;
F_121 ( & V_5 -> V_153 ) ;
F_100 ( V_5 ) ;
}
F_117 ( & V_30 -> V_439 ) ;
F_10 ( V_30 ) ;
}
static void F_304 ( struct V_29 * V_30 , struct V_438 * V_420 )
{
struct V_4 * V_5 , * V_285 ;
while ( 1 ) {
V_5 = NULL ;
F_38 ( & V_420 -> V_421 ) ;
if ( ! F_6 ( & V_420 -> V_422 ) ) {
V_5 = F_160 ( V_420 -> V_422 . V_218 , struct V_4 ,
V_150 ) ;
F_121 ( & V_5 -> V_150 ) ;
}
F_40 ( & V_420 -> V_421 ) ;
if ( ! V_5 )
break;
V_5 -> V_11 |= V_441 ;
F_301 ( V_30 , V_5 ) ;
F_100 ( V_5 ) ;
}
F_38 ( & V_420 -> V_421 ) ;
F_167 (lkb, safe, &proc->unlocking, lkb_ownqueue) {
F_121 ( & V_5 -> V_150 ) ;
V_5 -> V_11 |= V_441 ;
F_100 ( V_5 ) ;
}
F_40 ( & V_420 -> V_421 ) ;
F_38 ( & V_420 -> V_445 ) ;
F_167 (lkb, safe, &proc->asts, lkb_cb_list) {
memset ( & V_5 -> V_442 , 0 ,
sizeof( struct V_443 ) * V_444 ) ;
F_121 ( & V_5 -> V_153 ) ;
F_100 ( V_5 ) ;
}
F_40 ( & V_420 -> V_445 ) ;
}
static void F_245 ( struct V_29 * V_30 , int V_187 , int V_308 )
{
struct V_4 * V_5 , * V_285 ;
F_113 ( & V_30 -> V_433 ) ;
F_167 (lkb, safe, &ls->ls_orphans, lkb_ownqueue) {
if ( V_308 && V_5 -> V_306 != V_308 )
continue;
F_301 ( V_30 , V_5 ) ;
F_121 ( & V_5 -> V_150 ) ;
F_100 ( V_5 ) ;
}
F_117 ( & V_30 -> V_433 ) ;
}
static int F_305 ( struct V_29 * V_30 , int V_187 , int V_308 )
{
struct V_203 * V_204 ;
struct V_317 * V_319 ;
int error ;
error = F_210 ( V_30 , sizeof( struct V_203 ) , V_187 ,
V_357 , & V_204 , & V_319 ) ;
if ( error )
return error ;
V_204 -> V_331 = V_187 ;
V_204 -> V_332 = V_308 ;
return F_213 ( V_319 , V_204 ) ;
}
int F_306 ( struct V_29 * V_30 , struct V_438 * V_420 ,
int V_187 , int V_308 )
{
int error = 0 ;
if ( V_187 && ( V_187 != F_59 () ) ) {
error = F_305 ( V_30 , V_187 , V_308 ) ;
} else {
F_8 ( V_30 ) ;
if ( V_308 == V_307 -> V_308 )
F_304 ( V_30 , V_420 ) ;
else
F_245 ( V_30 , V_187 , V_308 ) ;
F_10 ( V_30 ) ;
}
return error ;
}
