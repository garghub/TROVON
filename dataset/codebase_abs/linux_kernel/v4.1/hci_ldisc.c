int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( V_6 [ V_2 -> V_3 ] )
return - V_7 ;
V_6 [ V_2 -> V_3 ] = V_2 ;
F_2 ( L_1 , V_2 -> V_8 ) ;
return 0 ;
}
int F_3 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( ! V_6 [ V_2 -> V_3 ] )
return - V_5 ;
V_6 [ V_2 -> V_3 ] = NULL ;
return 0 ;
}
static const struct V_1 * F_4 ( unsigned int V_3 )
{
if ( V_3 >= V_4 )
return NULL ;
return V_6 [ V_3 ] ;
}
static inline void F_5 ( struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
switch ( V_11 ) {
case V_14 :
V_13 -> V_15 . V_16 ++ ;
break;
case V_17 :
V_13 -> V_15 . V_18 ++ ;
break;
case V_19 :
V_13 -> V_15 . V_20 ++ ;
break;
}
}
static inline struct V_21 * F_6 ( struct V_9 * V_10 )
{
struct V_21 * V_22 = V_10 -> V_23 ;
if ( ! V_22 )
V_22 = V_10 -> V_24 -> V_25 ( V_10 ) ;
else
V_10 -> V_23 = NULL ;
return V_22 ;
}
int F_7 ( struct V_9 * V_10 )
{
if ( F_8 ( V_26 , & V_10 -> V_27 ) ) {
F_9 ( V_28 , & V_10 -> V_27 ) ;
return 0 ;
}
F_10 ( L_2 ) ;
F_11 ( & V_10 -> V_29 ) ;
return 0 ;
}
static void F_12 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_13 ( V_31 , struct V_9 , V_29 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_21 * V_22 ;
V_34:
F_14 ( V_28 , & V_10 -> V_27 ) ;
while ( ( V_22 = F_6 ( V_10 ) ) ) {
int V_35 ;
F_9 ( V_36 , & V_33 -> V_37 ) ;
V_35 = V_33 -> V_38 -> V_39 ( V_33 , V_22 -> V_40 , V_22 -> V_35 ) ;
V_13 -> V_15 . V_41 += V_35 ;
F_15 ( V_22 , V_35 ) ;
if ( V_22 -> V_35 ) {
V_10 -> V_23 = V_22 ;
break;
}
F_5 ( V_10 , F_16 ( V_22 ) -> V_11 ) ;
F_17 ( V_22 ) ;
}
if ( F_18 ( V_28 , & V_10 -> V_27 ) )
goto V_34;
F_14 ( V_26 , & V_10 -> V_27 ) ;
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = F_13 ( V_31 , struct V_9 , V_42 ) ;
int V_43 ;
if ( ! F_20 ( V_44 , & V_10 -> V_45 ) )
return;
V_43 = F_21 ( V_10 -> V_13 ) ;
if ( V_43 < 0 ) {
F_22 ( L_3 ) ;
F_23 ( V_10 -> V_13 ) ;
V_10 -> V_13 = NULL ;
V_10 -> V_24 -> V_46 ( V_10 ) ;
}
F_9 ( V_47 , & V_10 -> V_37 ) ;
}
int F_24 ( struct V_9 * V_10 )
{
if ( ! F_18 ( V_44 , & V_10 -> V_45 ) )
return - V_48 ;
F_11 ( & V_10 -> V_42 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
F_10 ( L_4 , V_13 -> V_8 , V_13 ) ;
F_9 ( V_49 , & V_13 -> V_37 ) ;
return 0 ;
}
static int F_26 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
struct V_32 * V_33 = V_10 -> V_33 ;
F_10 ( L_5 , V_13 , V_33 ) ;
if ( V_10 -> V_23 ) {
F_17 ( V_10 -> V_23 ) ; V_10 -> V_23 = NULL ;
}
F_28 ( V_33 ) ;
F_29 ( V_33 ) ;
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
V_10 -> V_24 -> V_51 ( V_10 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_13 )
{
F_10 ( L_6 , V_13 ) ;
if ( ! F_20 ( V_49 , & V_13 -> V_37 ) )
return 0 ;
F_26 ( V_13 ) ;
V_13 -> V_51 = NULL ;
return 0 ;
}
static int F_31 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
if ( ! F_18 ( V_49 , & V_13 -> V_37 ) )
return - V_52 ;
F_10 ( L_7 , V_13 -> V_8 , F_16 ( V_22 ) -> V_11 , V_22 -> V_35 ) ;
V_10 -> V_24 -> V_53 ( V_10 , V_22 ) ;
F_7 ( V_10 ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_27 ( V_13 ) ;
struct V_54 * V_55 ;
struct V_21 * V_22 ;
if ( V_10 -> V_24 -> V_56 )
return V_10 -> V_24 -> V_56 ( V_10 ) ;
if ( ! F_18 ( V_57 , & V_10 -> V_45 ) )
return 0 ;
V_22 = F_33 ( V_13 , V_58 , 0 , NULL ,
V_59 ) ;
if ( F_34 ( V_22 ) ) {
F_22 ( L_8 ,
V_13 -> V_8 , F_35 ( V_22 ) ) ;
return 0 ;
}
if ( V_22 -> V_35 != sizeof( * V_55 ) ) {
F_22 ( L_9 ,
V_13 -> V_8 ) ;
goto V_60;
}
V_55 = (struct V_54 * ) V_22 -> V_40 ;
switch ( F_36 ( V_55 -> V_61 ) ) {
#ifdef F_37
case 2 :
V_13 -> V_62 = V_63 ;
F_38 ( V_13 ) ;
break;
#endif
#ifdef F_39
case 15 :
V_13 -> V_62 = V_64 ;
F_40 ( V_13 ) ;
break;
#endif
}
V_60:
F_17 ( V_22 ) ;
return 0 ;
}
static int F_41 ( struct V_32 * V_33 )
{
struct V_9 * V_10 ;
F_10 ( L_10 , V_33 ) ;
if ( V_33 -> V_38 -> V_39 == NULL )
return - V_65 ;
V_10 = F_42 ( sizeof( struct V_9 ) , V_66 ) ;
if ( ! V_10 ) {
F_22 ( L_11 ) ;
return - V_67 ;
}
V_33 -> V_68 = V_10 ;
V_10 -> V_33 = V_33 ;
V_33 -> V_69 = 65536 ;
F_43 ( & V_10 -> V_42 , F_19 ) ;
F_43 ( & V_10 -> V_29 , F_12 ) ;
F_44 ( & V_10 -> V_70 ) ;
if ( V_33 -> V_71 -> V_38 -> V_72 )
V_33 -> V_71 -> V_38 -> V_72 ( V_33 ) ;
F_29 ( V_33 ) ;
return 0 ;
}
static void F_45 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = V_33 -> V_68 ;
struct V_12 * V_13 ;
F_10 ( L_10 , V_33 ) ;
V_33 -> V_68 = NULL ;
if ( ! V_10 )
return;
V_13 = V_10 -> V_13 ;
if ( V_13 )
F_30 ( V_13 ) ;
F_46 ( & V_10 -> V_29 ) ;
if ( F_20 ( V_50 , & V_10 -> V_37 ) ) {
if ( V_13 ) {
if ( F_18 ( V_47 , & V_10 -> V_37 ) )
F_47 ( V_13 ) ;
F_23 ( V_13 ) ;
}
V_10 -> V_24 -> V_46 ( V_10 ) ;
}
F_48 ( V_10 ) ;
}
static void F_49 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = V_33 -> V_68 ;
F_10 ( L_2 ) ;
if ( ! V_10 )
return;
F_14 ( V_36 , & V_33 -> V_37 ) ;
if ( V_33 != V_10 -> V_33 )
return;
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
F_7 ( V_10 ) ;
}
static void F_50 ( struct V_32 * V_33 , const T_1 * V_40 ,
char * V_37 , int V_73 )
{
struct V_9 * V_10 = V_33 -> V_68 ;
if ( ! V_10 || V_33 != V_10 -> V_33 )
return;
if ( ! F_18 ( V_50 , & V_10 -> V_37 ) )
return;
F_51 ( & V_10 -> V_70 ) ;
V_10 -> V_24 -> V_74 ( V_10 , V_40 , V_73 ) ;
if ( V_10 -> V_13 )
V_10 -> V_13 -> V_15 . V_75 += V_73 ;
F_52 ( & V_10 -> V_70 ) ;
F_53 ( V_33 ) ;
}
static int F_54 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
F_10 ( L_2 ) ;
V_13 = F_55 () ;
if ( ! V_13 ) {
F_22 ( L_12 ) ;
return - V_76 ;
}
V_10 -> V_13 = V_13 ;
V_13 -> V_77 = V_78 ;
F_56 ( V_13 , V_10 ) ;
V_13 -> V_79 = F_25 ;
V_13 -> V_46 = F_30 ;
V_13 -> V_51 = F_26 ;
V_13 -> V_80 = F_31 ;
V_13 -> V_56 = F_32 ;
F_57 ( V_13 , V_10 -> V_33 -> V_81 ) ;
if ( F_18 ( V_82 , & V_10 -> V_45 ) )
F_9 ( V_83 , & V_13 -> V_84 ) ;
if ( F_18 ( V_85 , & V_10 -> V_45 ) )
F_9 ( V_86 , & V_13 -> V_84 ) ;
if ( ! F_18 ( V_87 , & V_10 -> V_45 ) )
F_9 ( V_88 , & V_13 -> V_84 ) ;
if ( F_18 ( V_89 , & V_10 -> V_45 ) )
V_13 -> V_90 = V_91 ;
else
V_13 -> V_90 = V_92 ;
if ( F_18 ( V_44 , & V_10 -> V_45 ) )
return 0 ;
if ( F_21 ( V_13 ) < 0 ) {
F_22 ( L_3 ) ;
F_23 ( V_13 ) ;
return - V_93 ;
}
F_9 ( V_47 , & V_10 -> V_37 ) ;
return 0 ;
}
static int F_58 ( struct V_9 * V_10 , int V_3 )
{
const struct V_1 * V_2 ;
int V_43 ;
V_2 = F_4 ( V_3 ) ;
if ( ! V_2 )
return - V_94 ;
V_43 = V_2 -> V_79 ( V_10 ) ;
if ( V_43 )
return V_43 ;
V_10 -> V_24 = V_2 ;
V_43 = F_54 ( V_10 ) ;
if ( V_43 ) {
V_2 -> V_46 ( V_10 ) ;
return V_43 ;
}
return 0 ;
}
static int F_59 ( struct V_9 * V_10 , unsigned long V_37 )
{
unsigned long V_95 = F_60 ( V_82 ) |
F_60 ( V_87 ) |
F_60 ( V_89 ) |
F_60 ( V_44 ) |
F_60 ( V_85 ) |
F_60 ( V_57 ) ;
if ( V_37 & ~ V_95 )
return - V_5 ;
V_10 -> V_45 = V_37 ;
return 0 ;
}
static int F_61 ( struct V_32 * V_33 , struct V_96 * V_96 ,
unsigned int V_97 , unsigned long V_98 )
{
struct V_9 * V_10 = V_33 -> V_68 ;
int V_43 = 0 ;
F_10 ( L_2 ) ;
if ( ! V_10 )
return - V_99 ;
switch ( V_97 ) {
case V_100 :
if ( ! F_8 ( V_50 , & V_10 -> V_37 ) ) {
V_43 = F_58 ( V_10 , V_98 ) ;
if ( V_43 ) {
F_14 ( V_50 , & V_10 -> V_37 ) ;
return V_43 ;
}
} else
return - V_52 ;
break;
case V_101 :
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
return V_10 -> V_24 -> V_3 ;
return - V_102 ;
case V_103 :
if ( F_18 ( V_47 , & V_10 -> V_37 ) )
return V_10 -> V_13 -> V_3 ;
return - V_102 ;
case V_104 :
if ( F_18 ( V_50 , & V_10 -> V_37 ) )
return - V_52 ;
V_43 = F_59 ( V_10 , V_98 ) ;
if ( V_43 )
return V_43 ;
break;
case V_105 :
return V_10 -> V_45 ;
default:
V_43 = F_62 ( V_33 , V_96 , V_97 , V_98 ) ;
break;
}
return V_43 ;
}
static T_2 F_63 ( struct V_32 * V_33 , struct V_96 * V_96 ,
unsigned char T_3 * V_106 , T_4 V_107 )
{
return 0 ;
}
static T_2 F_64 ( struct V_32 * V_33 , struct V_96 * V_96 ,
const unsigned char * V_40 , T_4 V_73 )
{
return 0 ;
}
static unsigned int F_65 ( struct V_32 * V_33 ,
struct V_96 * V_108 , T_5 * V_109 )
{
return 0 ;
}
static int T_6 F_66 ( void )
{
static struct V_110 V_111 ;
int V_43 ;
F_2 ( L_13 , V_112 ) ;
memset ( & V_111 , 0 , sizeof ( V_111 ) ) ;
V_111 . V_113 = V_114 ;
V_111 . V_8 = L_14 ;
V_111 . V_79 = F_41 ;
V_111 . V_46 = F_45 ;
V_111 . V_115 = F_63 ;
V_111 . V_39 = F_64 ;
V_111 . V_116 = F_61 ;
V_111 . V_117 = F_65 ;
V_111 . V_118 = F_50 ;
V_111 . V_119 = F_49 ;
V_111 . V_120 = V_121 ;
V_43 = F_67 ( V_122 , & V_111 ) ;
if ( V_43 ) {
F_22 ( L_15 , V_43 ) ;
return V_43 ;
}
#ifdef F_68
F_69 () ;
#endif
#ifdef F_70
F_71 () ;
#endif
#ifdef F_72
F_73 () ;
#endif
#ifdef F_74
F_75 () ;
#endif
#ifdef F_76
F_77 () ;
#endif
#ifdef F_39
F_78 () ;
#endif
return 0 ;
}
static void T_7 F_79 ( void )
{
int V_43 ;
#ifdef F_68
F_80 () ;
#endif
#ifdef F_70
F_81 () ;
#endif
#ifdef F_72
F_82 () ;
#endif
#ifdef F_74
F_83 () ;
#endif
#ifdef F_76
F_84 () ;
#endif
#ifdef F_39
F_85 () ;
#endif
V_43 = F_86 ( V_122 ) ;
if ( V_43 )
F_22 ( L_16 , V_43 ) ;
}
