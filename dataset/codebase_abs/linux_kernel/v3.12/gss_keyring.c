static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( & V_2 -> V_3 ) ;
#endif
}
static inline void F_4 ( struct V_1 * V_2 )
{
#ifdef F_2
F_5 ( & V_2 -> V_3 ) ;
#endif
}
static inline void F_6 ( struct V_4 * V_4 )
{
F_7 ( V_5 , & V_4 -> V_6 ) ;
}
static void F_8 ( unsigned long V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
struct V_4 * V_4 = F_9 ( V_9 ) -> V_10 ;
F_10 ( L_1 , V_9 , V_4 ) ;
F_11 ( V_4 ) ;
F_12 ( V_9 ) ;
F_6 ( V_4 ) ;
}
static
void F_13 ( struct V_8 * V_9 , long V_11 )
{
struct V_12 * V_13 = F_9 ( V_9 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
F_11 ( V_15 ) ;
F_14 ( V_17 , L_2 , V_9 , V_11 ) ;
V_11 = V_11 * V_18 + F_15 () ;
F_16 ( V_15 ) ;
V_15 -> V_19 = V_11 ;
V_15 -> V_7 = ( unsigned long ) V_9 ;
V_15 -> V_20 = F_8 ;
F_17 ( V_15 ) ;
}
static
void F_18 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_9 ( V_9 ) ;
struct V_14 * V_15 = V_13 -> V_16 ;
if ( V_15 == NULL )
return;
F_14 ( V_17 , L_1 , V_9 , V_13 -> V_10 ) ;
V_13 -> V_16 = NULL ;
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
}
static
struct V_8 * F_21 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
F_22 ( V_13 ) ;
if ( V_13 == NULL )
return NULL ;
F_22 ( V_13 -> V_16 ) ;
if ( V_13 -> V_16 == NULL ) {
F_20 ( V_13 ) ;
return NULL ;
}
F_16 ( V_13 -> V_16 ) ;
V_9 = & V_13 -> V_25 . V_26 ;
if ( F_23 ( V_22 , V_9 , & V_27 , V_24 ) ) {
F_20 ( V_13 -> V_16 ) ;
F_20 ( V_13 ) ;
return NULL ;
}
V_9 -> V_28 = F_24 () + V_29 ;
F_25 ( V_30 , & V_9 -> V_31 ) ;
F_26 ( & V_9 -> V_32 ) ;
return V_9 ;
}
static void F_27 ( struct V_8 * V_9 )
{
struct V_21 * V_22 = V_9 -> V_33 ;
struct V_12 * V_13 = F_9 ( V_9 ) ;
F_14 ( V_17 , L_3 , V_9 ) ;
F_11 ( V_22 ) ;
F_11 ( F_28 ( & V_22 -> V_34 ) > 0 ) ;
F_11 ( F_28 ( & V_22 -> V_35 ) > 0 ) ;
F_11 ( F_29 ( V_36 , & V_9 -> V_31 ) == 0 ) ;
F_11 ( V_13 -> V_10 == NULL ) ;
F_18 ( V_9 ) ;
F_11 ( V_13 -> V_16 == NULL ) ;
if ( F_30 ( V_22 , V_9 ) )
return;
F_20 ( V_13 ) ;
F_31 ( & V_22 -> V_35 ) ;
F_32 ( V_22 ) ;
}
static void F_33 ( struct V_8 * V_9 , int V_37 )
{
if ( V_37 ) {
F_27 ( V_9 ) ;
} else {
F_26 ( & V_9 -> V_32 ) ;
F_34 ( V_9 ) ;
}
}
static void F_35 ( struct V_8 * V_9 , int V_37 )
{
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
if ( F_36 ( & V_9 -> V_32 ) )
F_33 ( V_9 , V_37 ) ;
}
static inline void F_37 ( T_1 * V_38 , int V_39 )
{
if ( V_39 )
F_38 ( V_38 ) ;
}
static inline void F_39 ( T_1 * V_38 , int V_39 )
{
if ( V_39 )
F_40 ( V_38 ) ;
}
static void F_41 ( struct V_8 * V_9 , int V_40 , int V_41 )
{
struct V_21 * V_22 = V_9 -> V_33 ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
F_11 ( ! F_29 ( V_36 , & V_9 -> V_31 ) ) ;
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_37 ( & V_22 -> V_42 , ! V_41 ) ;
F_26 ( & V_9 -> V_32 ) ;
F_7 ( V_36 , & V_9 -> V_31 ) ;
F_43 ( & V_9 -> V_43 , & V_2 -> V_44 ) ;
if ( V_40 )
V_2 -> V_45 = V_9 ;
F_39 ( & V_22 -> V_42 , ! V_41 ) ;
}
static int F_44 ( struct V_8 * V_9 , int V_41 )
{
struct V_21 * V_22 = V_9 -> V_33 ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
if ( F_45 ( V_36 , & V_9 -> V_31 ) == 0 )
return 0 ;
F_37 ( & V_22 -> V_42 , ! V_41 ) ;
if ( V_2 -> V_45 == V_9 )
V_2 -> V_45 = NULL ;
F_46 ( & V_9 -> V_43 ) ;
F_31 ( & V_9 -> V_32 ) ;
F_39 ( & V_22 -> V_42 , ! V_41 ) ;
return 1 ;
}
static void F_47 ( struct V_4 * V_4 , struct V_8 * V_9 )
{
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( F_28 ( & V_4 -> V_46 ) > 0 ) ;
F_11 ( F_9 ( V_9 ) -> V_10 == NULL ) ;
F_11 ( V_4 -> V_47 . V_7 == NULL ) ;
F_48 ( V_4 ) ;
F_26 ( & V_9 -> V_32 ) ;
F_9 ( V_9 ) -> V_10 = V_4 ;
V_4 -> V_47 . V_7 = V_9 ;
}
static void F_49 ( struct V_4 * V_4 , struct V_8 * V_9 )
{
F_11 ( V_4 -> V_47 . V_7 == V_9 ) ;
F_11 ( F_29 ( V_36 , & V_9 -> V_31 ) == 0 ) ;
F_6 ( V_4 ) ;
V_4 -> V_47 . V_7 = NULL ;
F_9 ( V_9 ) -> V_10 = NULL ;
F_18 ( V_9 ) ;
F_35 ( V_9 , 1 ) ;
F_50 ( V_4 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_4 * V_4 = F_9 ( V_9 ) -> V_10 ;
if ( V_4 ) {
F_11 ( V_4 -> V_47 . V_7 == V_9 ) ;
F_48 ( V_4 ) ;
F_52 ( & V_4 -> V_48 ) ;
F_49 ( V_4 , V_9 ) ;
F_53 ( & V_4 -> V_48 ) ;
F_50 ( V_4 ) ;
}
}
static void F_54 ( struct V_4 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_47 . V_7 ;
if ( V_9 )
F_49 ( V_4 , V_9 ) ;
}
static void F_55 ( struct V_8 * V_9 )
{
if ( F_44 ( V_9 , 0 ) )
F_51 ( V_9 ) ;
}
static void F_56 ( struct V_4 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_47 . V_7 ;
if ( V_9 && F_44 ( V_9 , 0 ) )
F_54 ( V_4 ) ;
}
static void F_57 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_8 * V_9 ;
struct V_53 * V_54 ;
F_58 (ctx, next, freelist, cc_cache) {
F_46 ( & V_9 -> V_43 ) ;
V_54 = F_59 ( V_9 ) ;
if ( ! F_60 ( & V_54 -> V_55 ) &&
F_61 ( V_54 -> V_26 . V_33 ) ) {
F_62 ( & V_54 -> V_55 ,
( V_56 ) F_28 ( & V_54 -> V_57 ) ) ;
}
F_63 ( V_9 ) ;
F_51 ( V_9 ) ;
F_35 ( V_9 , 0 ) ;
}
}
static
struct V_8 * F_64 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_8 * V_9 = NULL ;
F_38 ( & V_22 -> V_42 ) ;
V_9 = V_2 -> V_45 ;
if ( V_9 == NULL && F_65 ( F_61 ( V_22 ) ) ) {
struct V_8 * V_58 ;
F_66 (tmp, &gsec_kr->gsk_clist, cc_cache) {
if ( V_9 == NULL || V_9 -> V_28 == 0 ||
V_9 -> V_28 > V_58 -> V_28 ) {
V_9 = V_58 ;
V_2 -> V_45 = V_9 ;
}
}
}
if ( V_9 ) {
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( ! F_67 ( & V_2 -> V_44 ) ) ;
F_26 ( & V_9 -> V_32 ) ;
}
F_40 ( & V_22 -> V_42 ) ;
return V_9 ;
}
static
void F_68 ( struct V_21 * V_22 ,
struct V_8 * V_59 ,
struct V_4 * V_4 )
{
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_8 * V_9 ;
T_2 V_60 ;
F_11 ( F_61 ( V_22 ) ) ;
F_38 ( & V_22 -> V_42 ) ;
V_60 = F_24 () ;
F_66 (ctx, &gsec_kr->gsk_clist, cc_cache) {
if ( V_9 -> V_28 > V_60 + V_61 ) {
V_9 -> V_62 = 1 ;
V_9 -> V_28 = V_60 + V_61 ;
}
}
F_41 ( V_59 , V_2 -> V_45 ? 0 : 1 , 1 ) ;
if ( V_4 )
F_47 ( V_4 , V_59 ) ;
F_40 ( & V_22 -> V_42 ) ;
}
static void F_69 ( void * V_63 , int V_64 ,
struct V_21 * V_22 , T_3 V_65 )
{
snprintf ( V_63 , V_64 , L_4 , V_65 , V_22 -> V_66 ) ;
( ( char * ) V_63 ) [ V_64 - 1 ] = '\0' ;
}
static
struct V_21 * F_70 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 ;
F_71 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return NULL ;
F_72 ( & V_2 -> V_44 ) ;
V_2 -> V_45 = NULL ;
F_73 ( & V_2 -> V_73 ) ;
#ifdef F_2
F_73 ( & V_2 -> V_3 ) ;
#endif
if ( F_74 ( & V_2 -> V_74 , & V_75 ,
V_68 , V_70 , V_72 ) )
goto V_76;
if ( V_70 != NULL &&
F_75 ( & V_2 -> V_74 . V_77 , V_70 ) ) {
F_76 ( & V_2 -> V_74 ) ;
goto V_76;
}
return & V_2 -> V_74 . V_77 ;
V_76:
F_77 ( V_2 , sizeof( * V_2 ) ) ;
return NULL ;
}
static
void F_78 ( struct V_21 * V_22 )
{
struct V_78 * V_79 = F_79 ( V_22 ) ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
F_14 ( V_17 , L_5 , V_22 -> V_80 -> V_81 , V_22 ) ;
F_11 ( F_67 ( & V_2 -> V_44 ) ) ;
F_11 ( V_2 -> V_45 == NULL ) ;
F_76 ( V_79 ) ;
F_77 ( V_2 , sizeof( * V_2 ) ) ;
}
static inline int F_80 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
if ( F_81 ( V_22 ) || ( V_24 -> V_82 == 0 ) )
return 1 ;
else
return 0 ;
}
static void F_82 ( struct V_4 * V_4 )
{
struct V_83 * V_84 = V_85 ;
struct V_4 * V_86 ;
switch ( F_83 ( V_84 ) -> V_87 ) {
case V_88 :
case V_89 :
V_86 = F_48 ( F_83 ( V_84 ) -> V_90 ) ;
if ( V_86 )
break;
case V_91 :
V_86 = F_48 ( F_84 ( V_84 ) -> V_92 ) ;
if ( V_86 )
break;
case V_93 :
F_85 () ;
V_86 = F_48 ( F_86 ( F_84 ( V_84 )
-> V_94 ) ) ;
F_87 () ;
if ( V_86 )
break;
case V_95 :
V_86 = F_48 ( F_83 ( V_84 ) -> V_96 -> V_94 ) ;
break;
case V_97 :
V_86 = F_48 ( F_83 ( V_84 ) -> V_96 -> V_98 ) ;
break;
case V_99 :
default:
F_88 () ;
}
F_11 ( V_86 ) ;
F_89 ( V_86 , V_4 ) ;
F_50 ( V_86 ) ;
}
static
struct V_8 * F_90 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
int V_100 , int V_101 )
{
struct V_67 * V_68 = V_22 -> V_102 ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_8 * V_9 = NULL ;
unsigned int V_40 = 0 , V_103 = 0 ;
struct V_4 * V_4 ;
char V_104 [ 24 ] ;
char * V_105 ;
int V_106 ;
char * V_107 = L_6 ;
F_11 ( V_68 != NULL ) ;
V_40 = F_80 ( V_22 , V_24 ) ;
if ( V_40 ) {
V_9 = F_64 ( V_22 ) ;
if ( V_9 || F_61 ( V_22 ) )
return V_9 ;
}
F_11 ( V_100 != 0 ) ;
if ( V_40 ) {
F_3 ( & V_2 -> V_73 ) ;
V_9 = F_64 ( V_22 ) ;
if ( V_9 )
goto V_108;
F_79 ( V_22 ) -> V_109 = F_91 () ;
switch ( V_22 -> V_110 ) {
case V_111 :
V_107 = L_7 ;
break;
case V_112 :
V_107 = L_8 ;
break;
case V_113 :
V_107 = L_9 ;
break;
case V_114 :
V_107 = L_10 ;
break;
case V_115 :
default:
F_88 () ;
}
}
F_69 ( V_104 , sizeof( V_104 ) , V_22 , V_24 -> V_82 ) ;
V_106 = sizeof( struct V_116 ) + V_117 + 64 ;
F_71 ( V_105 , V_106 ) ;
if ( V_105 == NULL )
goto V_108;
snprintf ( V_105 , V_106 , L_11 V_118 L_12 ,
V_22 -> V_66 , F_79 ( V_22 ) -> V_119 -> V_120 ,
V_24 -> V_82 , V_24 -> V_121 ,
V_107 , F_92 ( V_68 ) ,
V_68 -> V_122 -> V_123 . V_124 , V_68 -> V_125 -> V_126 ) ;
F_14 ( V_17 , L_13 , V_104 ) ;
F_1 ( V_2 ) ;
V_4 = F_93 ( & V_127 , V_104 , V_105 ) ;
F_4 ( V_2 ) ;
F_77 ( V_105 , V_106 ) ;
if ( F_94 ( V_4 ) ) {
F_95 ( L_14 , F_96 ( V_4 ) ) ;
goto V_108;
}
F_14 ( V_17 , L_15 , V_4 -> V_128 , V_104 ) ;
F_52 ( & V_4 -> V_48 ) ;
if ( F_97 ( V_4 -> V_47 . V_7 != NULL ) ) {
V_9 = V_4 -> V_47 . V_7 ;
F_11 ( F_28 ( & V_9 -> V_32 ) >= 1 ) ;
F_11 ( F_9 ( V_9 ) -> V_10 == V_4 ) ;
F_11 ( F_28 ( & V_4 -> V_46 ) >= 2 ) ;
F_26 ( & V_9 -> V_32 ) ;
} else {
V_9 = F_21 ( V_22 , V_24 ) ;
if ( V_9 != NULL ) {
F_41 ( V_9 , V_40 , 0 ) ;
F_47 ( V_4 , V_9 ) ;
F_13 ( V_9 , V_29 ) ;
F_14 ( V_17 , L_16 ,
V_4 , V_9 , V_22 ) ;
} else {
F_6 ( V_4 ) ;
}
V_103 = 1 ;
}
F_53 ( & V_4 -> V_48 ) ;
if ( V_40 && V_103 )
F_82 ( V_4 ) ;
F_50 ( V_4 ) ;
V_108:
if ( V_40 )
F_5 ( & V_2 -> V_73 ) ;
return V_9 ;
}
static
void F_98 ( struct V_21 * V_22 ,
struct V_8 * V_9 ,
int V_37 )
{
F_11 ( F_28 ( & V_22 -> V_34 ) > 0 ) ;
F_11 ( F_28 ( & V_9 -> V_32 ) == 0 ) ;
F_33 ( V_9 , V_37 ) ;
}
static
void F_99 ( struct V_21 * V_22 ,
T_3 V_65 ,
int V_129 , int V_130 )
{
struct V_4 * V_4 ;
char V_104 [ 24 ] ;
if ( F_61 ( V_22 ) || F_81 ( V_22 ) )
return;
F_69 ( V_104 , sizeof( V_104 ) , V_22 , V_65 ) ;
for (; ; ) {
V_4 = F_93 ( & V_127 , V_104 , NULL ) ;
if ( F_94 ( V_4 ) ) {
F_14 ( V_17 , L_17 ) ;
break;
}
F_52 ( & V_4 -> V_48 ) ;
F_56 ( V_4 ) ;
F_6 ( V_4 ) ;
F_53 ( & V_4 -> V_48 ) ;
F_50 ( V_4 ) ;
}
}
static
void F_100 ( struct V_21 * V_22 ,
T_3 V_65 ,
int V_129 , int V_130 )
{
struct V_1 * V_2 ;
struct V_49 V_50 = V_131 ;
struct V_51 * V_52 ;
struct V_8 * V_9 ;
V_2 = F_42 ( V_22 ) ;
F_38 ( & V_22 -> V_42 ) ;
F_58 (ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
if ( V_65 != - 1 && V_65 != V_9 -> V_132 . V_82 )
continue;
if ( F_28 ( & V_9 -> V_32 ) > 2 ) {
if ( ! V_130 )
continue;
F_10 ( L_18 ,
V_9 , V_9 -> V_132 . V_82 ,
F_101 ( V_9 -> V_33 ) ,
F_28 ( & V_9 -> V_32 ) - 2 ) ;
}
F_7 ( V_133 , & V_9 -> V_31 ) ;
if ( ! V_129 )
F_25 ( V_134 , & V_9 -> V_31 ) ;
F_26 ( & V_9 -> V_32 ) ;
if ( F_44 ( V_9 , 1 ) ) {
F_43 ( & V_9 -> V_43 , & V_50 ) ;
} else {
F_11 ( F_28 ( & V_9 -> V_32 ) >= 2 ) ;
F_31 ( & V_9 -> V_32 ) ;
}
}
F_40 ( & V_22 -> V_42 ) ;
F_57 ( & V_50 ) ;
}
static
int F_102 ( struct V_21 * V_22 ,
T_3 V_65 , int V_129 , int V_130 )
{
F_14 ( V_17 , L_19 ,
V_22 , F_28 ( & V_22 -> V_34 ) ,
F_28 ( & V_22 -> V_35 ) ,
V_65 , V_129 , V_130 ) ;
if ( V_65 != - 1 && V_65 != 0 )
F_99 ( V_22 , V_65 , V_129 , V_130 ) ;
else
F_100 ( V_22 , V_65 , V_129 , V_130 ) ;
return 0 ;
}
static
void F_103 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_49 V_50 = V_131 ;
struct V_51 * V_52 ;
struct V_8 * V_9 ;
F_10 ( L_20 ) ;
F_38 ( & V_22 -> V_42 ) ;
F_58 (ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_26 ( & V_9 -> V_32 ) ;
if ( F_104 ( V_9 ) && F_44 ( V_9 , 1 ) ) {
F_43 ( & V_9 -> V_43 , & V_50 ) ;
F_10 ( L_21 , V_9 ) ;
} else {
F_11 ( F_28 ( & V_9 -> V_32 ) >= 2 ) ;
F_31 ( & V_9 -> V_32 ) ;
}
}
F_40 ( & V_22 -> V_42 ) ;
F_57 ( & V_50 ) ;
}
static
int F_105 ( struct V_21 * V_22 , struct V_135 * V_136 )
{
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_51 * V_52 ;
struct V_8 * V_9 ;
struct V_53 * V_54 ;
T_4 V_60 = F_24 () ;
F_38 ( & V_22 -> V_42 ) ;
F_58 (ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
struct V_4 * V_4 ;
char V_137 [ 40 ] ;
char V_138 [ 40 ] ;
V_54 = F_59 ( V_9 ) ;
V_4 = F_9 ( V_9 ) -> V_10 ;
F_106 ( V_9 -> V_31 ,
V_137 , sizeof( V_137 ) ) ;
if ( V_54 -> V_139 )
F_107 ( V_54 -> V_139 , V_138 , sizeof( V_138 ) ) ;
else
snprintf ( V_138 , sizeof( V_138 ) , L_22 ) ;
V_138 [ sizeof( V_138 ) - 1 ] = '\0' ;
F_108 ( V_136 , L_23
L_24
L_25 V_118 L_26 V_118 L_27 ,
V_9 , V_9 -> V_132 . V_82 ,
F_28 ( & V_9 -> V_32 ) ,
V_9 -> V_28 ,
V_9 -> V_28 ? V_9 -> V_28 - V_60 : 0 ,
V_137 ,
F_28 ( & V_54 -> V_57 ) ,
V_54 -> V_140 ,
V_4 ? V_4 -> V_128 : 0 ,
V_4 ? F_28 ( & V_4 -> V_46 ) : 0 ,
F_109 ( & V_54 -> V_141 ) ,
F_109 ( & V_54 -> V_55 ) ,
V_138 ) ;
}
F_40 ( & V_22 -> V_42 ) ;
return 0 ;
}
static
int F_110 ( struct V_8 * V_9 )
{
return 0 ;
}
static
int F_111 ( struct V_8 * V_9 )
{
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( V_9 -> V_33 ) ;
if ( F_104 ( V_9 ) ) {
F_55 ( V_9 ) ;
return 1 ;
}
if ( F_112 ( V_9 ) )
return 0 ;
return 1 ;
}
static
void F_113 ( struct V_8 * V_9 , int V_129 )
{
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( V_9 -> V_33 ) ;
F_12 ( V_9 ) ;
F_55 ( V_9 ) ;
}
static
int F_75 ( struct V_21 * V_22 ,
struct V_69 * V_142 )
{
struct V_8 * V_143 ;
struct V_23 V_24 = { 0 , 0 } ;
int V_144 ;
F_11 ( V_22 ) ;
F_11 ( V_142 ) ;
V_143 = F_21 ( V_22 , & V_24 ) ;
if ( V_143 == NULL )
return - V_145 ;
V_144 = F_114 ( V_143 , V_142 ) ;
if ( V_144 ) {
F_95 ( L_28 , V_144 ) ;
F_35 ( V_143 , 1 ) ;
return V_144 ;
}
F_68 ( V_22 , V_143 , NULL ) ;
F_35 ( V_143 , 1 ) ;
return 0 ;
}
static
int F_115 ( struct V_146 * V_147 )
{
return F_116 ( & V_75 , V_147 ) ;
}
static
int F_117 ( struct V_67 * V_68 ,
struct V_69 * V_142 )
{
struct V_21 * V_22 ;
int V_144 ;
V_22 = F_118 ( V_68 ) ;
F_11 ( V_22 ) ;
V_144 = F_75 ( V_22 , V_142 ) ;
F_32 ( V_22 ) ;
return V_144 ;
}
static
int F_119 ( struct V_4 * V_4 , const void * V_7 , T_5 V_148 )
{
int V_144 ;
if ( V_7 != NULL || V_148 != 0 ) {
F_95 ( L_29 , V_7 , ( long ) V_148 ) ;
return - V_149 ;
}
if ( V_4 -> V_47 . V_7 != 0 ) {
F_95 ( L_30 ) ;
return - V_149 ;
}
F_11 ( F_84 ( V_85 ) -> V_94 ) ;
F_120 () ;
V_144 = F_121 ( F_84 ( V_85 ) -> V_94 , V_4 ) ;
F_122 () ;
if ( F_65 ( V_144 ) ) {
F_95 ( L_31 ,
V_4 -> V_128 ,
F_84 ( V_85 ) -> V_94 -> V_128 , V_144 ) ;
return V_144 ;
}
F_14 ( V_17 , L_32 , V_4 , V_4 -> V_47 . V_7 ) ;
return 0 ;
}
static
int F_123 ( struct V_4 * V_4 , const void * V_7 , T_5 V_148 )
{
struct V_8 * V_9 = V_4 -> V_47 . V_7 ;
struct V_53 * V_54 ;
T_6 V_150 = V_151 ;
V_56 V_152 = ( V_56 ) V_148 ;
int V_144 ;
if ( V_7 == NULL || V_148 == 0 ) {
F_10 ( L_29 , V_7 , ( long ) V_148 ) ;
return - V_149 ;
}
if ( V_9 == NULL ) {
F_14 ( V_17 , L_33 ,
V_4 , V_4 -> V_128 , V_4 -> V_6 ) ;
V_144 = F_124 ( V_4 ) ;
if ( V_144 == 0 )
return - V_153 ;
else
return V_144 ;
}
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( V_9 -> V_33 ) ;
F_18 ( V_9 ) ;
if ( F_125 ( V_9 ) ) {
F_10 ( L_34 ) ;
return 0 ;
}
F_126 ( V_9 ) ;
V_54 = F_59 ( V_9 ) ;
V_144 = F_127 ( & V_7 , & V_152 , & V_54 -> V_140 ,
sizeof( V_54 -> V_140 ) ) ;
if ( V_144 ) {
F_95 ( L_35 ) ;
goto V_108;
}
if ( V_54 -> V_140 == 0 ) {
V_56 V_154 , V_155 ;
V_144 = F_127 ( & V_7 , & V_152 , & V_154 ,
sizeof( V_154 ) ) ;
if ( V_144 ) {
F_95 ( L_36 ) ;
goto V_108;
}
V_144 = F_127 ( & V_7 , & V_152 , & V_155 ,
sizeof( V_155 ) ) ;
if ( V_144 ) {
F_95 ( L_37 ) ;
goto V_108;
}
F_95 ( L_38 ,
V_154 , V_155 ) ;
V_144 = V_154 ? V_154 : - V_156 ;
} else {
V_144 = F_128 ( & V_54 -> V_141 ,
( V_56 * * ) & V_7 , & V_152 ) ;
if ( V_144 ) {
F_95 ( L_39 ) ;
goto V_108;
}
V_144 = F_129 ( & V_150 , ( V_56 * * ) & V_7 , & V_152 ) ;
if ( V_144 ) {
F_95 ( L_40 ) ;
goto V_108;
}
V_144 = F_130 ( & V_150 ,
F_79 ( V_9 -> V_33 ) -> V_119 ,
& V_54 -> V_139 ) ;
if ( V_144 != V_157 )
F_95 ( L_41 ) ;
else
V_144 = 0 ;
}
V_108:
if ( V_144 == 0 ) {
F_131 ( V_54 ) ;
} else {
F_56 ( V_4 ) ;
F_12 ( V_9 ) ;
if ( V_144 != - V_158 )
F_7 ( V_159 , & V_9 -> V_31 ) ;
}
F_132 ( V_9 , 1 ) ;
return 0 ;
}
static
int F_133 ( const struct V_4 * V_4 , const void * V_104 )
{
return ( strcmp ( V_4 -> V_160 , ( const char * ) V_104 ) == 0 ) ;
}
static
void F_134 ( struct V_4 * V_4 )
{
F_11 ( V_4 -> V_47 . V_7 == NULL ) ;
F_14 ( V_17 , L_42 , V_4 ) ;
}
static
void F_135 ( const struct V_4 * V_4 , struct V_135 * V_161 )
{
if ( V_4 -> V_160 == NULL )
F_136 ( V_161 , L_43 ) ;
else
F_136 ( V_161 , V_4 -> V_160 ) ;
}
int T_7 F_137 ( void )
{
int V_144 ;
V_144 = F_138 ( & V_127 ) ;
if ( V_144 ) {
F_95 ( L_44 , V_144 ) ;
return V_144 ;
}
V_144 = F_139 ( & V_75 ) ;
if ( V_144 ) {
F_140 ( & V_127 ) ;
return V_144 ;
}
return 0 ;
}
void T_8 F_141 ( void )
{
F_140 ( & V_127 ) ;
F_142 ( & V_75 ) ;
}
