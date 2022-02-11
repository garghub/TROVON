int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( V_6 [ V_2 -> V_3 ] )
return - V_7 ;
V_6 [ V_2 -> V_3 ] = V_2 ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( ! V_6 [ V_2 -> V_3 ] )
return - V_5 ;
V_6 [ V_2 -> V_3 ] = NULL ;
return 0 ;
}
static struct V_1 * F_3 ( unsigned int V_3 )
{
if ( V_3 >= V_4 )
return NULL ;
return V_6 [ V_3 ] ;
}
static inline void F_4 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
switch ( V_10 ) {
case V_13 :
V_12 -> V_14 . V_15 ++ ;
break;
case V_16 :
V_12 -> V_14 . V_17 ++ ;
break;
case V_18 :
V_12 -> V_14 . V_19 ++ ;
break;
}
}
static inline struct V_20 * F_5 ( struct V_8 * V_9 )
{
struct V_20 * V_21 = V_9 -> V_22 ;
if ( ! V_21 )
V_21 = V_9 -> V_23 -> V_24 ( V_9 ) ;
else
V_9 -> V_22 = NULL ;
return V_21 ;
}
int F_6 ( struct V_8 * V_9 )
{
if ( F_7 ( V_25 , & V_9 -> V_26 ) ) {
F_8 ( V_27 , & V_9 -> V_26 ) ;
return 0 ;
}
F_9 ( L_1 ) ;
F_10 ( & V_9 -> V_28 ) ;
return 0 ;
}
static void F_11 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = F_12 ( V_30 , struct V_8 , V_28 ) ;
struct V_31 * V_32 = V_9 -> V_32 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_20 * V_21 ;
V_33:
F_13 ( V_27 , & V_9 -> V_26 ) ;
while ( ( V_21 = F_5 ( V_9 ) ) ) {
int V_34 ;
F_8 ( V_35 , & V_32 -> V_36 ) ;
V_34 = V_32 -> V_37 -> V_38 ( V_32 , V_21 -> V_39 , V_21 -> V_34 ) ;
V_12 -> V_14 . V_40 += V_34 ;
F_14 ( V_21 , V_34 ) ;
if ( V_21 -> V_34 ) {
V_9 -> V_22 = V_21 ;
break;
}
F_4 ( V_9 , F_15 ( V_21 ) -> V_10 ) ;
F_16 ( V_21 ) ;
}
if ( F_17 ( V_27 , & V_9 -> V_26 ) )
goto V_33;
F_13 ( V_25 , & V_9 -> V_26 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = F_12 ( V_30 , struct V_8 , V_41 ) ;
int V_42 ;
if ( ! F_19 ( V_43 , & V_9 -> V_44 ) )
return;
V_42 = F_20 ( V_9 -> V_12 ) ;
if ( V_42 < 0 ) {
F_21 ( L_2 ) ;
F_22 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
V_9 -> V_23 -> V_45 ( V_9 ) ;
}
F_8 ( V_46 , & V_9 -> V_36 ) ;
}
int F_23 ( struct V_8 * V_9 )
{
if ( ! F_17 ( V_43 , & V_9 -> V_44 ) )
return - V_47 ;
F_10 ( & V_9 -> V_41 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_12 )
{
F_9 ( L_3 , V_12 -> V_48 , V_12 ) ;
F_8 ( V_49 , & V_12 -> V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_26 ( V_12 ) ;
struct V_31 * V_32 = V_9 -> V_32 ;
F_9 ( L_4 , V_12 , V_32 ) ;
if ( V_9 -> V_22 ) {
F_16 ( V_9 -> V_22 ) ; V_9 -> V_22 = NULL ;
}
F_27 ( V_32 ) ;
F_28 ( V_32 ) ;
if ( F_17 ( V_50 , & V_9 -> V_36 ) )
V_9 -> V_23 -> V_51 ( V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
F_9 ( L_5 , V_12 ) ;
if ( ! F_19 ( V_49 , & V_12 -> V_36 ) )
return 0 ;
F_25 ( V_12 ) ;
V_12 -> V_51 = NULL ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_8 * V_9 = F_26 ( V_12 ) ;
if ( ! F_17 ( V_49 , & V_12 -> V_36 ) )
return - V_52 ;
F_9 ( L_6 , V_12 -> V_48 , F_15 ( V_21 ) -> V_10 , V_21 -> V_34 ) ;
V_9 -> V_23 -> V_53 ( V_9 , V_21 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
struct V_8 * V_9 ;
F_9 ( L_7 , V_32 ) ;
if ( V_32 -> V_37 -> V_38 == NULL )
return - V_54 ;
V_9 = F_32 ( sizeof( struct V_8 ) , V_55 ) ;
if ( ! V_9 ) {
F_21 ( L_8 ) ;
return - V_56 ;
}
V_32 -> V_57 = V_9 ;
V_9 -> V_32 = V_32 ;
V_32 -> V_58 = 65536 ;
F_33 ( & V_9 -> V_41 , F_18 ) ;
F_33 ( & V_9 -> V_28 , F_11 ) ;
F_34 ( & V_9 -> V_59 ) ;
if ( V_32 -> V_60 -> V_37 -> V_61 )
V_32 -> V_60 -> V_37 -> V_61 ( V_32 ) ;
F_28 ( V_32 ) ;
return 0 ;
}
static void F_35 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = ( void * ) V_32 -> V_57 ;
struct V_11 * V_12 ;
F_9 ( L_7 , V_32 ) ;
V_32 -> V_57 = NULL ;
if ( ! V_9 )
return;
V_12 = V_9 -> V_12 ;
if ( V_12 )
F_29 ( V_12 ) ;
F_36 ( & V_9 -> V_28 ) ;
if ( F_19 ( V_50 , & V_9 -> V_36 ) ) {
if ( V_12 ) {
if ( F_17 ( V_46 , & V_9 -> V_36 ) )
F_37 ( V_12 ) ;
F_22 ( V_12 ) ;
}
V_9 -> V_23 -> V_45 ( V_9 ) ;
}
F_38 ( V_9 ) ;
}
static void F_39 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = ( void * ) V_32 -> V_57 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return;
F_13 ( V_35 , & V_32 -> V_36 ) ;
if ( V_32 != V_9 -> V_32 )
return;
if ( F_17 ( V_50 , & V_9 -> V_36 ) )
F_6 ( V_9 ) ;
}
static void F_40 ( struct V_31 * V_32 , const T_1 * V_39 , char * V_36 , int V_62 )
{
struct V_8 * V_9 = ( void * ) V_32 -> V_57 ;
if ( ! V_9 || V_32 != V_9 -> V_32 )
return;
if ( ! F_17 ( V_50 , & V_9 -> V_36 ) )
return;
F_41 ( & V_9 -> V_59 ) ;
V_9 -> V_23 -> V_63 ( V_9 , ( void * ) V_39 , V_62 ) ;
if ( V_9 -> V_12 )
V_9 -> V_12 -> V_14 . V_64 += V_62 ;
F_42 ( & V_9 -> V_59 ) ;
F_43 ( V_32 ) ;
}
static int F_44 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_9 ( L_1 ) ;
V_12 = F_45 () ;
if ( ! V_12 ) {
F_21 ( L_9 ) ;
return - V_65 ;
}
V_9 -> V_12 = V_12 ;
V_12 -> V_66 = V_67 ;
F_46 ( V_12 , V_9 ) ;
V_12 -> V_68 = F_24 ;
V_12 -> V_45 = F_29 ;
V_12 -> V_51 = F_25 ;
V_12 -> V_69 = F_30 ;
F_47 ( V_12 , V_9 -> V_32 -> V_70 ) ;
if ( F_17 ( V_71 , & V_9 -> V_44 ) )
F_8 ( V_72 , & V_12 -> V_73 ) ;
if ( F_17 ( V_74 , & V_9 -> V_44 ) )
F_8 ( V_75 , & V_12 -> V_73 ) ;
if ( ! F_17 ( V_76 , & V_9 -> V_44 ) )
F_8 ( V_77 , & V_12 -> V_73 ) ;
if ( F_17 ( V_78 , & V_9 -> V_44 ) )
V_12 -> V_79 = V_80 ;
else
V_12 -> V_79 = V_81 ;
if ( F_17 ( V_43 , & V_9 -> V_44 ) )
return 0 ;
if ( F_20 ( V_12 ) < 0 ) {
F_21 ( L_2 ) ;
F_22 ( V_12 ) ;
return - V_82 ;
}
F_8 ( V_46 , & V_9 -> V_36 ) ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , int V_3 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_2 )
return - V_83 ;
V_42 = V_2 -> V_68 ( V_9 ) ;
if ( V_42 )
return V_42 ;
V_9 -> V_23 = V_2 ;
V_42 = F_44 ( V_9 ) ;
if ( V_42 ) {
V_2 -> V_45 ( V_9 ) ;
return V_42 ;
}
return 0 ;
}
static int F_49 ( struct V_8 * V_9 , unsigned long V_36 )
{
unsigned long V_84 = F_50 ( V_71 ) |
F_50 ( V_76 ) |
F_50 ( V_78 ) |
F_50 ( V_43 ) |
F_50 ( V_74 ) ;
if ( ( V_36 & ~ V_84 ) )
return - V_5 ;
V_9 -> V_44 = V_36 ;
return 0 ;
}
static int F_51 ( struct V_31 * V_32 , struct V_85 * V_85 ,
unsigned int V_86 , unsigned long V_87 )
{
struct V_8 * V_9 = ( void * ) V_32 -> V_57 ;
int V_42 = 0 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return - V_88 ;
switch ( V_86 ) {
case V_89 :
if ( ! F_7 ( V_50 , & V_9 -> V_36 ) ) {
V_42 = F_48 ( V_9 , V_87 ) ;
if ( V_42 ) {
F_13 ( V_50 , & V_9 -> V_36 ) ;
return V_42 ;
}
} else
return - V_52 ;
break;
case V_90 :
if ( F_17 ( V_50 , & V_9 -> V_36 ) )
return V_9 -> V_23 -> V_3 ;
return - V_91 ;
case V_92 :
if ( F_17 ( V_46 , & V_9 -> V_36 ) )
return V_9 -> V_12 -> V_3 ;
return - V_91 ;
case V_93 :
if ( F_17 ( V_50 , & V_9 -> V_36 ) )
return - V_52 ;
V_42 = F_49 ( V_9 , V_87 ) ;
if ( V_42 )
return V_42 ;
break;
case V_94 :
return V_9 -> V_44 ;
default:
V_42 = F_52 ( V_32 , V_85 , V_86 , V_87 ) ;
break;
}
return V_42 ;
}
static T_2 F_53 ( struct V_31 * V_32 , struct V_85 * V_85 ,
unsigned char T_3 * V_95 , T_4 V_96 )
{
return 0 ;
}
static T_2 F_54 ( struct V_31 * V_32 , struct V_85 * V_85 ,
const unsigned char * V_39 , T_4 V_62 )
{
return 0 ;
}
static unsigned int F_55 ( struct V_31 * V_32 ,
struct V_85 * V_97 , T_5 * V_98 )
{
return 0 ;
}
static int T_6 F_56 ( void )
{
static struct V_99 V_100 ;
int V_42 ;
F_57 ( L_10 , V_101 ) ;
memset ( & V_100 , 0 , sizeof ( V_100 ) ) ;
V_100 . V_102 = V_103 ;
V_100 . V_48 = L_11 ;
V_100 . V_68 = F_31 ;
V_100 . V_45 = F_35 ;
V_100 . V_104 = F_53 ;
V_100 . V_38 = F_54 ;
V_100 . V_105 = F_51 ;
V_100 . V_106 = F_55 ;
V_100 . V_107 = F_40 ;
V_100 . V_108 = F_39 ;
V_100 . V_109 = V_110 ;
V_42 = F_58 ( V_111 , & V_100 ) ;
if ( V_42 ) {
F_21 ( L_12 , V_42 ) ;
return V_42 ;
}
#ifdef F_59
F_60 () ;
#endif
#ifdef F_61
F_62 () ;
#endif
#ifdef F_63
F_64 () ;
#endif
#ifdef F_65
F_66 () ;
#endif
#ifdef F_67
F_68 () ;
#endif
return 0 ;
}
static void T_7 F_69 ( void )
{
int V_42 ;
#ifdef F_59
F_70 () ;
#endif
#ifdef F_61
F_71 () ;
#endif
#ifdef F_63
F_72 () ;
#endif
#ifdef F_65
F_73 () ;
#endif
#ifdef F_67
F_74 () ;
#endif
V_42 = F_75 ( V_111 ) ;
if ( V_42 )
F_21 ( L_13 , V_42 ) ;
}
