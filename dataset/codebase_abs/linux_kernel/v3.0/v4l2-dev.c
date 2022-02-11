static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( int ) sizeof( V_7 -> V_9 ) , V_7 -> V_9 ) ;
}
static inline unsigned long * F_4 ( int V_10 )
{
int V_11 = ( V_10 > V_12 ) ? V_13 - 1 : V_10 ;
return V_14 [ V_11 ] ;
}
static inline unsigned long * F_4 ( int V_10 )
{
return V_14 [ V_10 ] ;
}
static inline void F_5 ( struct V_6 * V_7 )
{
F_6 ( V_7 -> V_15 , F_4 ( V_7 -> V_10 ) ) ;
}
static inline void F_7 ( struct V_6 * V_7 )
{
F_8 ( V_7 -> V_15 , F_4 ( V_7 -> V_10 ) ) ;
}
static inline int F_9 ( struct V_6 * V_7 , int V_16 , int V_17 )
{
return F_10 ( F_4 ( V_7 -> V_10 ) , V_17 , V_16 ) ;
}
struct V_6 * F_11 ( void )
{
return F_12 ( sizeof( struct V_6 ) , V_18 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_7 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
}
static inline void F_16 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_19 ) ;
}
static inline void F_18 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
F_21 ( & V_22 ) ;
if ( V_6 [ V_7 -> V_23 ] != V_7 ) {
F_22 ( & V_22 ) ;
F_23 ( 1 ) ;
return;
}
V_6 [ V_7 -> V_23 ] = NULL ;
F_24 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
F_7 ( V_7 ) ;
F_22 ( & V_22 ) ;
#if F_25 ( V_25 )
if ( V_7 -> V_21 && V_7 -> V_21 -> V_26 &&
V_7 -> V_10 != V_27 )
F_26 ( & V_7 -> V_28 ) ;
#endif
V_7 -> V_29 ( V_7 ) ;
if ( V_21 )
F_27 ( V_21 ) ;
}
struct V_6 * F_28 ( struct V_30 * V_30 )
{
return V_6 [ F_29 ( V_30 -> V_31 . V_32 -> V_33 ) ] ;
}
static inline bool F_30 ( enum V_34 V_35 )
{
return V_35 == V_36 ||
V_35 == V_37 ||
V_35 == V_38 ;
}
void F_31 ( struct V_39 * V_40 )
{
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
}
int F_32 ( struct V_39 * V_40 , enum V_34 * V_41 ,
enum V_34 V_42 )
{
if ( ! F_30 ( V_42 ) )
return - V_43 ;
if ( * V_41 == V_42 )
return 0 ;
F_33 ( & V_40 -> V_44 [ V_42 ] ) ;
if ( F_30 ( * V_41 ) )
F_34 ( & V_40 -> V_44 [ * V_41 ] ) ;
* V_41 = V_42 ;
return 0 ;
}
void F_35 ( struct V_39 * V_40 , enum V_34 * V_41 )
{
F_32 ( V_40 , V_41 , V_45 ) ;
}
void F_36 ( struct V_39 * V_40 , enum V_34 V_41 )
{
if ( F_30 ( V_41 ) )
F_34 ( & V_40 -> V_44 [ V_41 ] ) ;
}
enum V_34 F_37 ( struct V_39 * V_40 )
{
if ( F_38 ( & V_40 -> V_44 [ V_38 ] ) > 0 )
return V_38 ;
if ( F_38 ( & V_40 -> V_44 [ V_37 ] ) > 0 )
return V_37 ;
if ( F_38 ( & V_40 -> V_44 [ V_36 ] ) > 0 )
return V_36 ;
return V_46 ;
}
int F_39 ( struct V_39 * V_40 , enum V_34 V_41 )
{
return ( V_41 < F_37 ( V_40 ) ) ? - V_47 : 0 ;
}
static T_1 F_40 ( struct V_30 * V_48 , char T_2 * V_5 ,
T_3 V_49 , T_4 * V_50 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( ! V_7 -> V_53 -> V_54 )
return - V_43 ;
if ( V_7 -> V_55 && F_41 ( V_7 -> V_55 ) )
return - V_56 ;
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_54 ( V_48 , V_5 , V_49 , V_50 ) ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
return V_51 ;
}
static T_1 F_43 ( struct V_30 * V_48 , const char T_2 * V_5 ,
T_3 V_49 , T_4 * V_50 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( ! V_7 -> V_53 -> V_57 )
return - V_43 ;
if ( V_7 -> V_55 && F_41 ( V_7 -> V_55 ) )
return - V_56 ;
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_57 ( V_48 , V_5 , V_49 , V_50 ) ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
return V_51 ;
}
static unsigned int F_44 ( struct V_30 * V_48 , struct V_58 * V_59 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = V_60 | V_61 ;
if ( ! V_7 -> V_53 -> V_59 )
return V_62 ;
if ( V_7 -> V_55 )
F_21 ( V_7 -> V_55 ) ;
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_59 ( V_48 , V_59 ) ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
return V_51 ;
}
static long F_45 ( struct V_30 * V_48 , unsigned int V_63 , unsigned long V_64 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( V_7 -> V_53 -> V_65 ) {
if ( V_7 -> V_55 && F_41 ( V_7 -> V_55 ) )
return - V_56 ;
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_65 ( V_48 , V_63 , V_64 ) ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
} else if ( V_7 -> V_53 -> V_66 ) {
static F_46 ( V_67 ) ;
struct V_68 * V_69 = V_7 -> V_21 ?
& V_7 -> V_21 -> V_70 : & V_67 ;
if ( V_63 != V_71 && F_41 ( V_69 ) )
return - V_56 ;
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_66 ( V_48 , V_63 , V_64 ) ;
if ( V_63 != V_71 )
F_22 ( V_69 ) ;
} else
V_51 = - V_72 ;
return V_51 ;
}
static unsigned long F_47 ( struct V_30 * V_48 ,
unsigned long V_73 , unsigned long V_74 , unsigned long V_75 ,
unsigned long V_76 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
if ( ! V_7 -> V_53 -> V_77 )
return - V_78 ;
if ( ! F_42 ( V_7 ) )
return - V_52 ;
return V_7 -> V_53 -> V_77 ( V_48 , V_73 , V_74 , V_75 , V_76 ) ;
}
static int F_48 ( struct V_30 * V_48 , struct V_79 * V_80 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = - V_52 ;
if ( ! V_7 -> V_53 -> V_81 )
return V_51 ;
if ( V_7 -> V_55 && F_41 ( V_7 -> V_55 ) )
return - V_56 ;
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_81 ( V_48 , V_80 ) ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
return V_51 ;
}
static int F_49 ( struct V_82 * V_82 , struct V_30 * V_48 )
{
struct V_6 * V_7 ;
int V_51 = 0 ;
F_21 ( & V_22 ) ;
V_7 = F_28 ( V_48 ) ;
if ( V_7 == NULL || ! F_42 ( V_7 ) ) {
F_22 ( & V_22 ) ;
return - V_52 ;
}
F_16 ( V_7 ) ;
F_22 ( & V_22 ) ;
if ( V_7 -> V_53 -> V_83 ) {
if ( V_7 -> V_55 && F_41 ( V_7 -> V_55 ) ) {
V_51 = - V_56 ;
goto V_84;
}
if ( F_42 ( V_7 ) )
V_51 = V_7 -> V_53 -> V_83 ( V_48 ) ;
else
V_51 = - V_52 ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
}
V_84:
if ( V_51 )
F_18 ( V_7 ) ;
return V_51 ;
}
static int F_50 ( struct V_82 * V_82 , struct V_30 * V_48 )
{
struct V_6 * V_7 = F_28 ( V_48 ) ;
int V_51 = 0 ;
if ( V_7 -> V_53 -> V_29 ) {
if ( V_7 -> V_55 )
F_21 ( V_7 -> V_55 ) ;
V_7 -> V_53 -> V_29 ( V_48 ) ;
if ( V_7 -> V_55 )
F_22 ( V_7 -> V_55 ) ;
}
F_18 ( V_7 ) ;
return V_51 ;
}
static int F_51 ( struct V_6 * V_7 )
{
static F_52 ( V_85 , V_86 ) ;
int V_87 ;
if ( V_7 -> V_88 == NULL )
return 0 ;
F_53 ( V_85 , V_86 ) ;
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ ) {
if ( V_6 [ V_87 ] != NULL &&
V_6 [ V_87 ] -> V_88 == V_7 -> V_88 ) {
F_6 ( V_6 [ V_87 ] -> V_8 , V_85 ) ;
}
}
return F_54 ( V_85 , V_86 ) ;
}
int F_55 ( struct V_6 * V_7 , int type , int V_89 ,
int V_90 , struct V_91 * V_92 )
{
int V_87 = 0 ;
int V_51 ;
int V_93 = 0 ;
int V_94 = V_86 ;
const char * V_95 ;
V_7 -> V_23 = - 1 ;
F_23 ( ! V_7 -> V_29 ) ;
if ( ! V_7 -> V_29 )
return - V_43 ;
F_56 ( & V_7 -> V_96 ) ;
F_57 ( & V_7 -> V_97 ) ;
switch ( type ) {
case V_98 :
V_95 = L_3 ;
break;
case V_99 :
V_95 = L_4 ;
break;
case V_12 :
V_95 = L_5 ;
break;
case V_27 :
V_95 = L_6 ;
break;
default:
F_58 ( V_100 L_7 ,
V_101 , type ) ;
return - V_43 ;
}
V_7 -> V_10 = type ;
V_7 -> V_24 = NULL ;
if ( V_7 -> V_21 ) {
if ( V_7 -> V_21 -> V_19 )
V_7 -> V_88 = V_7 -> V_21 -> V_19 ;
if ( V_7 -> V_102 == NULL )
V_7 -> V_102 = V_7 -> V_21 -> V_102 ;
if ( V_7 -> V_35 == NULL )
V_7 -> V_35 = & V_7 -> V_21 -> V_35 ;
}
#ifdef F_59
switch ( type ) {
case V_98 :
V_93 = 0 ;
V_94 = 64 ;
break;
case V_12 :
V_93 = 64 ;
V_94 = 64 ;
break;
case V_99 :
V_93 = 224 ;
V_94 = 32 ;
break;
default:
V_93 = 128 ;
V_94 = 64 ;
break;
}
#endif
F_21 ( & V_22 ) ;
V_89 = F_9 ( V_7 , V_89 == - 1 ? 0 : V_89 , V_94 ) ;
if ( V_89 == V_94 )
V_89 = F_9 ( V_7 , 0 , V_94 ) ;
if ( V_89 == V_94 ) {
F_58 ( V_100 L_8 ) ;
F_22 ( & V_22 ) ;
return - V_103 ;
}
#ifdef F_59
V_87 = V_89 ;
#else
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ )
if ( V_6 [ V_87 ] == NULL )
break;
if ( V_87 == V_86 ) {
F_22 ( & V_22 ) ;
F_58 ( V_100 L_9 ) ;
return - V_103 ;
}
#endif
V_7 -> V_23 = V_87 + V_93 ;
V_7 -> V_15 = V_89 ;
F_5 ( V_7 ) ;
F_23 ( V_6 [ V_7 -> V_23 ] != NULL ) ;
V_7 -> V_8 = F_51 ( V_7 ) ;
F_22 ( & V_22 ) ;
V_7 -> V_24 = F_60 () ;
if ( V_7 -> V_24 == NULL ) {
V_51 = - V_104 ;
goto V_105;
}
V_7 -> V_24 -> V_106 = & V_107 ;
V_7 -> V_24 -> V_92 = V_92 ;
V_51 = F_61 ( V_7 -> V_24 , F_62 ( V_108 , V_7 -> V_23 ) , 1 ) ;
if ( V_51 < 0 ) {
F_58 ( V_100 L_10 , V_101 ) ;
F_14 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
goto V_105;
}
V_7 -> V_19 . V_109 = & V_110 ;
V_7 -> V_19 . V_111 = F_62 ( V_108 , V_7 -> V_23 ) ;
if ( V_7 -> V_88 )
V_7 -> V_19 . V_88 = V_7 -> V_88 ;
F_63 ( & V_7 -> V_19 , L_11 , V_95 , V_7 -> V_15 ) ;
V_51 = F_64 ( & V_7 -> V_19 ) ;
if ( V_51 < 0 ) {
F_58 ( V_100 L_12 , V_101 ) ;
goto V_105;
}
V_7 -> V_19 . V_29 = F_20 ;
if ( V_89 != - 1 && V_89 != V_7 -> V_15 && V_90 )
F_58 ( V_112 L_13 , V_101 ,
V_95 , V_89 , F_65 ( V_7 ) ) ;
if ( V_7 -> V_21 )
F_66 ( V_7 -> V_21 ) ;
#if F_25 ( V_25 )
if ( V_7 -> V_21 && V_7 -> V_21 -> V_26 &&
V_7 -> V_10 != V_27 ) {
V_7 -> V_28 . type = V_113 ;
V_7 -> V_28 . V_9 = V_7 -> V_9 ;
V_7 -> V_28 . V_114 . V_115 = V_108 ;
V_7 -> V_28 . V_114 . V_23 = V_7 -> V_23 ;
V_51 = F_67 ( V_7 -> V_21 -> V_26 ,
& V_7 -> V_28 ) ;
if ( V_51 < 0 )
F_58 ( V_112
L_14 ,
V_101 ) ;
}
#endif
F_6 ( V_116 , & V_7 -> V_76 ) ;
F_21 ( & V_22 ) ;
V_6 [ V_7 -> V_23 ] = V_7 ;
F_22 ( & V_22 ) ;
return 0 ;
V_105:
F_21 ( & V_22 ) ;
if ( V_7 -> V_24 )
F_24 ( V_7 -> V_24 ) ;
F_7 ( V_7 ) ;
F_22 ( & V_22 ) ;
V_7 -> V_23 = - 1 ;
return V_51 ;
}
void F_68 ( struct V_6 * V_7 )
{
if ( ! V_7 || ! F_42 ( V_7 ) )
return;
F_21 ( & V_22 ) ;
F_8 ( V_116 , & V_7 -> V_76 ) ;
F_22 ( & V_22 ) ;
F_69 ( & V_7 -> V_19 ) ;
}
static int T_5 F_70 ( void )
{
T_6 V_19 = F_62 ( V_108 , 0 ) ;
int V_51 ;
F_58 ( V_117 L_15 ) ;
V_51 = F_71 ( V_19 , V_86 , V_118 ) ;
if ( V_51 < 0 ) {
F_58 ( V_112 L_16 ,
V_108 ) ;
return V_51 ;
}
V_51 = F_72 ( & V_110 ) ;
if ( V_51 < 0 ) {
F_73 ( V_19 , V_86 ) ;
F_58 ( V_112 L_17 ) ;
return - V_119 ;
}
return 0 ;
}
static void T_7 F_74 ( void )
{
T_6 V_19 = F_62 ( V_108 , 0 ) ;
F_75 ( & V_110 ) ;
F_73 ( V_19 , V_86 ) ;
}
