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
struct V_25 * V_26 = V_9 -> V_26 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_20 * V_21 ;
if ( F_7 ( V_27 , & V_9 -> V_28 ) ) {
F_8 ( V_29 , & V_9 -> V_28 ) ;
return 0 ;
}
F_9 ( L_1 ) ;
V_30:
F_10 ( V_29 , & V_9 -> V_28 ) ;
while ( ( V_21 = F_5 ( V_9 ) ) ) {
int V_31 ;
F_8 ( V_32 , & V_26 -> V_33 ) ;
V_31 = V_26 -> V_34 -> V_35 ( V_26 , V_21 -> V_36 , V_21 -> V_31 ) ;
V_12 -> V_14 . V_37 += V_31 ;
F_11 ( V_21 , V_31 ) ;
if ( V_21 -> V_31 ) {
V_9 -> V_22 = V_21 ;
break;
}
F_4 ( V_9 , F_12 ( V_21 ) -> V_10 ) ;
F_13 ( V_21 ) ;
}
if ( F_14 ( V_29 , & V_9 -> V_28 ) )
goto V_30;
F_10 ( V_27 , & V_9 -> V_28 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
F_9 ( L_2 , V_12 -> V_38 , V_12 ) ;
F_8 ( V_39 , & V_12 -> V_33 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = (struct V_8 * ) V_12 -> V_40 ;
struct V_25 * V_26 = V_9 -> V_26 ;
F_9 ( L_3 , V_12 , V_26 ) ;
if ( V_9 -> V_22 ) {
F_13 ( V_9 -> V_22 ) ; V_9 -> V_22 = NULL ;
}
F_17 ( V_26 ) ;
F_18 ( V_26 ) ;
if ( F_14 ( V_41 , & V_9 -> V_33 ) )
V_9 -> V_23 -> V_42 ( V_9 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
F_9 ( L_4 , V_12 ) ;
if ( ! F_20 ( V_39 , & V_12 -> V_33 ) )
return 0 ;
F_16 ( V_12 ) ;
V_12 -> V_42 = NULL ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = (struct V_11 * ) V_21 -> V_43 ;
struct V_8 * V_9 ;
if ( ! V_12 ) {
F_22 ( L_5 ) ;
return - V_44 ;
}
if ( ! F_14 ( V_39 , & V_12 -> V_33 ) )
return - V_45 ;
V_9 = (struct V_8 * ) V_12 -> V_40 ;
F_9 ( L_6 , V_12 -> V_38 , F_12 ( V_21 ) -> V_10 , V_21 -> V_31 ) ;
V_9 -> V_23 -> V_46 ( V_9 , V_21 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static void F_23 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_9 ( L_7 , V_12 -> V_38 ) ;
F_24 ( V_12 -> V_40 ) ;
}
static int F_25 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_47 ;
F_9 ( L_8 , V_26 ) ;
if ( V_9 )
return - V_7 ;
if ( V_26 -> V_34 -> V_35 == NULL )
return - V_48 ;
if ( ! ( V_9 = F_26 ( sizeof( struct V_8 ) , V_49 ) ) ) {
F_22 ( L_9 ) ;
return - V_50 ;
}
V_26 -> V_47 = V_9 ;
V_9 -> V_26 = V_26 ;
V_26 -> V_51 = 65536 ;
F_27 ( & V_9 -> V_52 ) ;
if ( V_26 -> V_53 -> V_34 -> V_54 )
V_26 -> V_53 -> V_34 -> V_54 ( V_26 ) ;
F_18 ( V_26 ) ;
return 0 ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_47 ;
F_9 ( L_8 , V_26 ) ;
V_26 -> V_47 = NULL ;
if ( V_9 ) {
struct V_11 * V_12 = V_9 -> V_12 ;
if ( V_12 )
F_19 ( V_12 ) ;
if ( F_20 ( V_41 , & V_9 -> V_33 ) ) {
V_9 -> V_23 -> V_55 ( V_9 ) ;
if ( V_12 ) {
F_29 ( V_12 ) ;
F_30 ( V_12 ) ;
}
}
}
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_47 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return;
F_10 ( V_32 , & V_26 -> V_33 ) ;
if ( V_26 != V_9 -> V_26 )
return;
if ( F_14 ( V_41 , & V_9 -> V_33 ) )
F_6 ( V_9 ) ;
}
static void F_32 ( struct V_25 * V_26 , const T_1 * V_36 , char * V_33 , int V_56 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_47 ;
if ( ! V_9 || V_26 != V_9 -> V_26 )
return;
if ( ! F_14 ( V_41 , & V_9 -> V_33 ) )
return;
F_33 ( & V_9 -> V_52 ) ;
V_9 -> V_23 -> V_57 ( V_9 , ( void * ) V_36 , V_56 ) ;
V_9 -> V_12 -> V_14 . V_58 += V_56 ;
F_34 ( & V_9 -> V_52 ) ;
F_35 ( V_26 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_9 ( L_1 ) ;
V_12 = F_37 () ;
if ( ! V_12 ) {
F_22 ( L_10 ) ;
return - V_59 ;
}
V_9 -> V_12 = V_12 ;
V_12 -> V_60 = V_61 ;
V_12 -> V_40 = V_9 ;
V_12 -> V_62 = F_15 ;
V_12 -> V_55 = F_19 ;
V_12 -> V_42 = F_16 ;
V_12 -> V_63 = F_21 ;
V_12 -> V_64 = F_23 ;
V_12 -> V_65 = V_9 -> V_26 -> V_43 ;
V_12 -> V_66 = V_67 ;
if ( ! V_68 )
F_8 ( V_69 , & V_12 -> V_70 ) ;
if ( F_14 ( V_71 , & V_9 -> V_72 ) )
F_8 ( V_73 , & V_12 -> V_70 ) ;
if ( F_38 ( V_12 ) < 0 ) {
F_22 ( L_11 ) ;
F_30 ( V_12 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_39 ( struct V_8 * V_9 , int V_3 )
{
struct V_1 * V_2 ;
int V_74 ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_2 )
return - V_75 ;
V_74 = V_2 -> V_62 ( V_9 ) ;
if ( V_74 )
return V_74 ;
V_9 -> V_23 = V_2 ;
V_74 = F_36 ( V_9 ) ;
if ( V_74 ) {
V_2 -> V_55 ( V_9 ) ;
return V_74 ;
}
return 0 ;
}
static int F_40 ( struct V_25 * V_26 , struct V_76 * V_76 ,
unsigned int V_77 , unsigned long V_78 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_47 ;
int V_74 = 0 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return - V_79 ;
switch ( V_77 ) {
case V_80 :
if ( ! F_7 ( V_41 , & V_9 -> V_33 ) ) {
V_74 = F_39 ( V_9 , V_78 ) ;
if ( V_74 ) {
F_10 ( V_41 , & V_9 -> V_33 ) ;
return V_74 ;
}
} else
return - V_45 ;
break;
case V_81 :
if ( F_14 ( V_41 , & V_9 -> V_33 ) )
return V_9 -> V_23 -> V_3 ;
return - V_82 ;
case V_83 :
if ( F_14 ( V_41 , & V_9 -> V_33 ) )
return V_9 -> V_12 -> V_3 ;
return - V_82 ;
case V_84 :
if ( F_14 ( V_41 , & V_9 -> V_33 ) )
return - V_45 ;
V_9 -> V_72 = V_78 ;
break;
case V_85 :
return V_9 -> V_72 ;
default:
V_74 = F_41 ( V_26 , V_76 , V_77 , V_78 ) ;
break;
} ;
return V_74 ;
}
static T_2 F_42 ( struct V_25 * V_26 , struct V_76 * V_76 ,
unsigned char T_3 * V_86 , T_4 V_87 )
{
return 0 ;
}
static T_2 F_43 ( struct V_25 * V_26 , struct V_76 * V_76 ,
const unsigned char * V_36 , T_4 V_56 )
{
return 0 ;
}
static unsigned int F_44 ( struct V_25 * V_26 ,
struct V_76 * V_88 , T_5 * V_89 )
{
return 0 ;
}
static int T_6 F_45 ( void )
{
static struct V_90 V_91 ;
int V_74 ;
F_46 ( L_12 , V_92 ) ;
memset ( & V_91 , 0 , sizeof ( V_91 ) ) ;
V_91 . V_93 = V_94 ;
V_91 . V_38 = L_13 ;
V_91 . V_62 = F_25 ;
V_91 . V_55 = F_28 ;
V_91 . V_95 = F_42 ;
V_91 . V_35 = F_43 ;
V_91 . V_96 = F_40 ;
V_91 . V_97 = F_44 ;
V_91 . V_98 = F_32 ;
V_91 . V_99 = F_31 ;
V_91 . V_66 = V_67 ;
if ( ( V_74 = F_47 ( V_100 , & V_91 ) ) ) {
F_22 ( L_14 , V_74 ) ;
return V_74 ;
}
#ifdef F_48
F_49 () ;
#endif
#ifdef F_50
F_51 () ;
#endif
#ifdef F_52
F_53 () ;
#endif
#ifdef F_54
F_55 () ;
#endif
return 0 ;
}
static void T_7 F_56 ( void )
{
int V_74 ;
#ifdef F_48
F_57 () ;
#endif
#ifdef F_50
F_58 () ;
#endif
#ifdef F_52
F_59 () ;
#endif
#ifdef F_54
F_60 () ;
#endif
if ( ( V_74 = F_61 ( V_100 ) ) )
F_22 ( L_15 , V_74 ) ;
}
