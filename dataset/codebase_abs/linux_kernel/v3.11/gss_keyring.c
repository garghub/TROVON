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
V_61 ;
F_11 ( F_61 ( V_22 ) ) ;
F_38 ( & V_22 -> V_42 ) ;
V_60 = F_24 () ;
F_66 (ctx, &gsec_kr->gsk_clist, cc_cache) {
if ( V_9 -> V_28 > V_60 + V_62 ) {
V_9 -> V_63 = 1 ;
V_9 -> V_28 = V_60 + V_62 ;
}
}
F_41 ( V_59 , V_2 -> V_45 ? 0 : 1 , 1 ) ;
if ( V_4 )
F_47 ( V_4 , V_59 ) ;
F_40 ( & V_22 -> V_42 ) ;
}
static void F_69 ( void * V_64 , int V_65 ,
struct V_21 * V_22 , T_3 V_66 )
{
snprintf ( V_64 , V_65 , L_4 , V_66 , V_22 -> V_67 ) ;
( ( char * ) V_64 ) [ V_65 - 1 ] = '\0' ;
}
static
struct V_21 * F_70 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 ;
V_61 ;
F_71 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( NULL ) ;
F_72 ( & V_2 -> V_44 ) ;
V_2 -> V_45 = NULL ;
F_73 ( & V_2 -> V_74 ) ;
#ifdef F_2
F_73 ( & V_2 -> V_3 ) ;
#endif
if ( F_74 ( & V_2 -> V_75 , & V_76 ,
V_69 , V_71 , V_73 ) )
goto V_77;
if ( V_71 != NULL &&
F_75 ( & V_2 -> V_75 . V_78 , V_71 ) ) {
F_76 ( & V_2 -> V_75 ) ;
goto V_77;
}
RETURN ( & V_2 -> V_75 . V_78 ) ;
V_77:
F_77 ( V_2 , sizeof( * V_2 ) ) ;
RETURN ( NULL ) ;
}
static
void F_78 ( struct V_21 * V_22 )
{
struct V_79 * V_80 = F_79 ( V_22 ) ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
F_14 ( V_17 , L_5 , V_22 -> V_81 -> V_82 , V_22 ) ;
F_11 ( F_67 ( & V_2 -> V_44 ) ) ;
F_11 ( V_2 -> V_45 == NULL ) ;
F_76 ( V_80 ) ;
F_77 ( V_2 , sizeof( * V_2 ) ) ;
}
static inline int F_80 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
if ( F_81 ( V_22 ) || ( V_24 -> V_83 == 0 ) )
return 1 ;
else
return 0 ;
}
static void F_82 ( struct V_4 * V_4 )
{
struct V_84 * V_85 = V_86 ;
struct V_4 * V_87 ;
switch ( F_83 ( V_85 ) -> V_88 ) {
case V_89 :
case V_90 :
V_87 = F_48 ( F_83 ( V_85 ) -> V_91 ) ;
if ( V_87 )
break;
case V_92 :
V_87 = F_48 ( F_84 ( V_85 ) -> V_93 ) ;
if ( V_87 )
break;
case V_94 :
F_85 () ;
V_87 = F_48 ( F_86 ( F_84 ( V_85 )
-> V_95 ) ) ;
F_87 () ;
if ( V_87 )
break;
case V_96 :
V_87 = F_48 ( F_83 ( V_85 ) -> V_97 -> V_95 ) ;
break;
case V_98 :
V_87 = F_48 ( F_83 ( V_85 ) -> V_97 -> V_99 ) ;
break;
case V_100 :
default:
F_88 () ;
}
F_11 ( V_87 ) ;
F_89 ( V_87 , V_4 ) ;
F_50 ( V_87 ) ;
}
static
struct V_8 * F_90 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
int V_101 , int V_102 )
{
struct V_68 * V_69 = V_22 -> V_103 ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_8 * V_9 = NULL ;
unsigned int V_40 = 0 , V_104 = 0 ;
struct V_4 * V_4 ;
char V_105 [ 24 ] ;
char * V_106 ;
int V_107 ;
char * V_108 = L_6 ;
V_61 ;
F_11 ( V_69 != NULL ) ;
V_40 = F_80 ( V_22 , V_24 ) ;
if ( V_40 ) {
V_9 = F_64 ( V_22 ) ;
if ( V_9 || F_61 ( V_22 ) )
RETURN ( V_9 ) ;
}
F_11 ( V_101 != 0 ) ;
if ( V_40 ) {
F_3 ( & V_2 -> V_74 ) ;
V_9 = F_64 ( V_22 ) ;
if ( V_9 )
goto V_109;
F_79 ( V_22 ) -> V_110 = F_91 () ;
switch ( V_22 -> V_111 ) {
case V_112 :
V_108 = L_7 ;
break;
case V_113 :
V_108 = L_8 ;
break;
case V_114 :
V_108 = L_9 ;
break;
case V_115 :
V_108 = L_10 ;
break;
case V_116 :
default:
F_88 () ;
}
}
F_69 ( V_105 , sizeof( V_105 ) , V_22 , V_24 -> V_83 ) ;
V_107 = sizeof( struct V_117 ) + V_118 + 64 ;
F_71 ( V_106 , V_107 ) ;
if ( V_106 == NULL )
goto V_109;
snprintf ( V_106 , V_107 , L_11 V_119 L_12 ,
V_22 -> V_67 , F_79 ( V_22 ) -> V_120 -> V_121 ,
V_24 -> V_83 , V_24 -> V_122 ,
V_108 , F_92 ( V_69 ) ,
V_69 -> V_123 -> V_124 . V_125 , V_69 -> V_126 -> V_127 ) ;
F_14 ( V_17 , L_13 , V_105 ) ;
F_1 ( V_2 ) ;
V_4 = F_93 ( & V_128 , V_105 , V_106 ) ;
F_4 ( V_2 ) ;
F_77 ( V_106 , V_107 ) ;
if ( F_94 ( V_4 ) ) {
F_95 ( L_14 , F_96 ( V_4 ) ) ;
goto V_109;
}
F_14 ( V_17 , L_15 , V_4 -> V_129 , V_105 ) ;
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
V_104 = 1 ;
}
F_53 ( & V_4 -> V_48 ) ;
if ( V_40 && V_104 )
F_82 ( V_4 ) ;
F_50 ( V_4 ) ;
V_109:
if ( V_40 )
F_5 ( & V_2 -> V_74 ) ;
RETURN ( V_9 ) ;
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
T_3 V_66 ,
int V_130 , int V_131 )
{
struct V_4 * V_4 ;
char V_105 [ 24 ] ;
if ( F_61 ( V_22 ) || F_81 ( V_22 ) )
return;
F_69 ( V_105 , sizeof( V_105 ) , V_22 , V_66 ) ;
for (; ; ) {
V_4 = F_93 ( & V_128 , V_105 , NULL ) ;
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
T_3 V_66 ,
int V_130 , int V_131 )
{
struct V_1 * V_2 ;
struct V_49 V_50 = V_132 ;
struct V_51 * V_52 ;
struct V_8 * V_9 ;
V_61 ;
V_2 = F_42 ( V_22 ) ;
F_38 ( & V_22 -> V_42 ) ;
F_58 (ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
if ( V_66 != - 1 && V_66 != V_9 -> V_133 . V_83 )
continue;
if ( F_28 ( & V_9 -> V_32 ) > 2 ) {
if ( ! V_131 )
continue;
F_10 ( L_18 ,
V_9 , V_9 -> V_133 . V_83 ,
F_101 ( V_9 -> V_33 ) ,
F_28 ( & V_9 -> V_32 ) - 2 ) ;
}
F_7 ( V_134 , & V_9 -> V_31 ) ;
if ( ! V_130 )
F_25 ( V_135 , & V_9 -> V_31 ) ;
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
EXIT ;
}
static
int F_102 ( struct V_21 * V_22 ,
T_3 V_66 , int V_130 , int V_131 )
{
V_61 ;
F_14 ( V_17 , L_19 ,
V_22 , F_28 ( & V_22 -> V_34 ) ,
F_28 ( & V_22 -> V_35 ) ,
V_66 , V_130 , V_131 ) ;
if ( V_66 != - 1 && V_66 != 0 )
F_99 ( V_22 , V_66 , V_130 , V_131 ) ;
else
F_100 ( V_22 , V_66 , V_130 , V_131 ) ;
RETURN ( 0 ) ;
}
static
void F_103 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_49 V_50 = V_132 ;
struct V_51 * V_52 ;
struct V_8 * V_9 ;
V_61 ;
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
EXIT ;
return;
}
static
int F_105 ( struct V_21 * V_22 , struct V_136 * V_137 )
{
struct V_1 * V_2 = F_42 ( V_22 ) ;
struct V_51 * V_52 ;
struct V_8 * V_9 ;
struct V_53 * V_54 ;
T_4 V_60 = F_24 () ;
V_61 ;
F_38 ( & V_22 -> V_42 ) ;
F_58 (ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
struct V_4 * V_4 ;
char V_138 [ 40 ] ;
char V_139 [ 40 ] ;
V_54 = F_59 ( V_9 ) ;
V_4 = F_9 ( V_9 ) -> V_10 ;
F_106 ( V_9 -> V_31 ,
V_138 , sizeof( V_138 ) ) ;
if ( V_54 -> V_140 )
F_107 ( V_54 -> V_140 , V_139 , sizeof( V_139 ) ) ;
else
snprintf ( V_139 , sizeof( V_139 ) , L_22 ) ;
V_139 [ sizeof( V_139 ) - 1 ] = '\0' ;
F_108 ( V_137 , L_23
L_24
L_25 V_119 L_26 V_119 L_27 ,
V_9 , V_9 -> V_133 . V_83 ,
F_28 ( & V_9 -> V_32 ) ,
V_9 -> V_28 ,
V_9 -> V_28 ? V_9 -> V_28 - V_60 : 0 ,
V_138 ,
F_28 ( & V_54 -> V_57 ) ,
V_54 -> V_141 ,
V_4 ? V_4 -> V_129 : 0 ,
V_4 ? F_28 ( & V_4 -> V_46 ) : 0 ,
F_109 ( & V_54 -> V_142 ) ,
F_109 ( & V_54 -> V_55 ) ,
V_139 ) ;
}
F_40 ( & V_22 -> V_42 ) ;
RETURN ( 0 ) ;
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
void F_113 ( struct V_8 * V_9 , int V_130 )
{
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( V_9 -> V_33 ) ;
F_12 ( V_9 ) ;
F_55 ( V_9 ) ;
}
static
int F_75 ( struct V_21 * V_22 ,
struct V_70 * V_143 )
{
struct V_8 * V_144 ;
struct V_23 V_24 = { 0 , 0 } ;
int V_145 ;
F_11 ( V_22 ) ;
F_11 ( V_143 ) ;
V_144 = F_21 ( V_22 , & V_24 ) ;
if ( V_144 == NULL )
return - V_146 ;
V_145 = F_114 ( V_144 , V_143 ) ;
if ( V_145 ) {
F_95 ( L_28 , V_145 ) ;
F_35 ( V_144 , 1 ) ;
return V_145 ;
}
F_68 ( V_22 , V_144 , NULL ) ;
F_35 ( V_144 , 1 ) ;
return 0 ;
}
static
int F_115 ( struct V_147 * V_148 )
{
return F_116 ( & V_76 , V_148 ) ;
}
static
int F_117 ( struct V_68 * V_69 ,
struct V_70 * V_143 )
{
struct V_21 * V_22 ;
int V_145 ;
V_22 = F_118 ( V_69 ) ;
F_11 ( V_22 ) ;
V_145 = F_75 ( V_22 , V_143 ) ;
F_32 ( V_22 ) ;
return V_145 ;
}
static
int F_119 ( struct V_4 * V_4 , const void * V_7 , T_5 V_149 )
{
int V_145 ;
V_61 ;
if ( V_7 != NULL || V_149 != 0 ) {
F_95 ( L_29 , V_7 , ( long ) V_149 ) ;
RETURN ( - V_150 ) ;
}
if ( V_4 -> V_47 . V_7 != 0 ) {
F_95 ( L_30 ) ;
RETURN ( - V_150 ) ;
}
F_11 ( F_84 ( V_86 ) -> V_95 ) ;
F_120 () ;
V_145 = F_121 ( F_84 ( V_86 ) -> V_95 , V_4 ) ;
F_122 () ;
if ( F_65 ( V_145 ) ) {
F_95 ( L_31 ,
V_4 -> V_129 ,
F_84 ( V_86 ) -> V_95 -> V_129 , V_145 ) ;
RETURN ( V_145 ) ;
}
F_14 ( V_17 , L_32 , V_4 , V_4 -> V_47 . V_7 ) ;
RETURN ( 0 ) ;
}
static
int F_123 ( struct V_4 * V_4 , const void * V_7 , T_5 V_149 )
{
struct V_8 * V_9 = V_4 -> V_47 . V_7 ;
struct V_53 * V_54 ;
T_6 V_151 = V_152 ;
V_56 V_153 = ( V_56 ) V_149 ;
int V_145 ;
V_61 ;
if ( V_7 == NULL || V_149 == 0 ) {
F_10 ( L_29 , V_7 , ( long ) V_149 ) ;
RETURN ( - V_150 ) ;
}
if ( V_9 == NULL ) {
F_14 ( V_17 , L_33 ,
V_4 , V_4 -> V_129 , V_4 -> V_6 ) ;
V_145 = F_124 ( V_4 ) ;
if ( V_145 == 0 )
RETURN ( - V_154 ) ;
else
RETURN ( V_145 ) ;
}
F_11 ( F_28 ( & V_9 -> V_32 ) > 0 ) ;
F_11 ( V_9 -> V_33 ) ;
F_18 ( V_9 ) ;
if ( F_125 ( V_9 ) ) {
F_10 ( L_34 ) ;
RETURN ( 0 ) ;
}
F_126 ( V_9 ) ;
V_54 = F_59 ( V_9 ) ;
V_145 = F_127 ( & V_7 , & V_153 , & V_54 -> V_141 ,
sizeof( V_54 -> V_141 ) ) ;
if ( V_145 ) {
F_95 ( L_35 ) ;
goto V_109;
}
if ( V_54 -> V_141 == 0 ) {
V_56 V_155 , V_156 ;
V_145 = F_127 ( & V_7 , & V_153 , & V_155 ,
sizeof( V_155 ) ) ;
if ( V_145 ) {
F_95 ( L_36 ) ;
goto V_109;
}
V_145 = F_127 ( & V_7 , & V_153 , & V_156 ,
sizeof( V_156 ) ) ;
if ( V_145 ) {
F_95 ( L_37 ) ;
goto V_109;
}
F_95 ( L_38 ,
V_155 , V_156 ) ;
V_145 = V_155 ? V_155 : - V_157 ;
} else {
V_145 = F_128 ( & V_54 -> V_142 ,
( V_56 * * ) & V_7 , & V_153 ) ;
if ( V_145 ) {
F_95 ( L_39 ) ;
goto V_109;
}
V_145 = F_129 ( & V_151 , ( V_56 * * ) & V_7 , & V_153 ) ;
if ( V_145 ) {
F_95 ( L_40 ) ;
goto V_109;
}
V_145 = F_130 ( & V_151 ,
F_79 ( V_9 -> V_33 ) -> V_120 ,
& V_54 -> V_140 ) ;
if ( V_145 != V_158 )
F_95 ( L_41 ) ;
else
V_145 = 0 ;
}
V_109:
if ( V_145 == 0 ) {
F_131 ( V_54 ) ;
} else {
F_56 ( V_4 ) ;
F_12 ( V_9 ) ;
if ( V_145 != - V_159 )
F_7 ( V_160 , & V_9 -> V_31 ) ;
}
F_132 ( V_9 , 1 ) ;
RETURN ( 0 ) ;
}
static
int F_133 ( const struct V_4 * V_4 , const void * V_105 )
{
return ( strcmp ( V_4 -> V_161 , ( const char * ) V_105 ) == 0 ) ;
}
static
void F_134 ( struct V_4 * V_4 )
{
V_61 ;
F_11 ( V_4 -> V_47 . V_7 == NULL ) ;
F_14 ( V_17 , L_42 , V_4 ) ;
EXIT ;
}
static
void F_135 ( const struct V_4 * V_4 , struct V_136 * V_162 )
{
if ( V_4 -> V_161 == NULL )
F_136 ( V_162 , L_43 ) ;
else
F_136 ( V_162 , V_4 -> V_161 ) ;
}
int T_7 F_137 ( void )
{
int V_145 ;
V_145 = F_138 ( & V_128 ) ;
if ( V_145 ) {
F_95 ( L_44 , V_145 ) ;
return V_145 ;
}
V_145 = F_139 ( & V_76 ) ;
if ( V_145 ) {
F_140 ( & V_128 ) ;
return V_145 ;
}
return 0 ;
}
void T_8 F_141 ( void )
{
F_140 ( & V_128 ) ;
F_142 ( & V_76 ) ;
}
