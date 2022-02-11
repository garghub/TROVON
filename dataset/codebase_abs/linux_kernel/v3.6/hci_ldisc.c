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
static void F_15 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = F_16 ( V_39 , struct V_8 , V_40 ) ;
int V_41 ;
if ( ! F_17 ( V_42 , & V_9 -> V_43 ) )
return;
V_41 = F_18 ( V_9 -> V_12 ) ;
if ( V_41 < 0 ) {
F_19 ( L_2 ) ;
F_20 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
V_9 -> V_23 -> V_44 ( V_9 ) ;
}
F_8 ( V_45 , & V_9 -> V_33 ) ;
}
int F_21 ( struct V_8 * V_9 )
{
if ( ! F_14 ( V_42 , & V_9 -> V_43 ) )
return - V_46 ;
F_22 ( & V_9 -> V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_11 * V_12 )
{
F_9 ( L_3 , V_12 -> V_47 , V_12 ) ;
F_8 ( V_48 , & V_12 -> V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_25 ( V_12 ) ;
struct V_25 * V_26 = V_9 -> V_26 ;
F_9 ( L_4 , V_12 , V_26 ) ;
if ( V_9 -> V_22 ) {
F_13 ( V_9 -> V_22 ) ; V_9 -> V_22 = NULL ;
}
F_26 ( V_26 ) ;
F_27 ( V_26 ) ;
if ( F_14 ( V_49 , & V_9 -> V_33 ) )
V_9 -> V_23 -> V_50 ( V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
F_9 ( L_5 , V_12 ) ;
if ( ! F_17 ( V_48 , & V_12 -> V_33 ) )
return 0 ;
F_24 ( V_12 ) ;
V_12 -> V_50 = NULL ;
return 0 ;
}
static int F_29 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = (struct V_11 * ) V_21 -> V_51 ;
struct V_8 * V_9 ;
if ( ! V_12 ) {
F_19 ( L_6 ) ;
return - V_52 ;
}
if ( ! F_14 ( V_48 , & V_12 -> V_33 ) )
return - V_53 ;
V_9 = F_25 ( V_12 ) ;
F_9 ( L_7 , V_12 -> V_47 , F_12 ( V_21 ) -> V_10 , V_21 -> V_31 ) ;
V_9 -> V_23 -> V_54 ( V_9 , V_21 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_55 ;
F_9 ( L_8 , V_26 ) ;
if ( V_9 )
return - V_7 ;
if ( V_26 -> V_34 -> V_35 == NULL )
return - V_56 ;
if ( ! ( V_9 = F_31 ( sizeof( struct V_8 ) , V_57 ) ) ) {
F_19 ( L_9 ) ;
return - V_58 ;
}
V_26 -> V_55 = V_9 ;
V_9 -> V_26 = V_26 ;
V_26 -> V_59 = 65536 ;
F_32 ( & V_9 -> V_40 , F_15 ) ;
F_33 ( & V_9 -> V_60 ) ;
if ( V_26 -> V_61 -> V_34 -> V_62 )
V_26 -> V_61 -> V_34 -> V_62 ( V_26 ) ;
F_27 ( V_26 ) ;
return 0 ;
}
static void F_34 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_55 ;
struct V_11 * V_12 ;
F_9 ( L_8 , V_26 ) ;
V_26 -> V_55 = NULL ;
if ( ! V_9 )
return;
V_12 = V_9 -> V_12 ;
if ( V_12 )
F_28 ( V_12 ) ;
if ( F_17 ( V_49 , & V_9 -> V_33 ) ) {
if ( V_12 ) {
if ( F_14 ( V_45 , & V_9 -> V_33 ) )
F_35 ( V_12 ) ;
F_20 ( V_12 ) ;
}
V_9 -> V_23 -> V_44 ( V_9 ) ;
}
F_36 ( V_9 ) ;
}
static void F_37 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_55 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return;
F_10 ( V_32 , & V_26 -> V_33 ) ;
if ( V_26 != V_9 -> V_26 )
return;
if ( F_14 ( V_49 , & V_9 -> V_33 ) )
F_6 ( V_9 ) ;
}
static void F_38 ( struct V_25 * V_26 , const T_1 * V_36 , char * V_33 , int V_63 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_55 ;
if ( ! V_9 || V_26 != V_9 -> V_26 )
return;
if ( ! F_14 ( V_49 , & V_9 -> V_33 ) )
return;
F_39 ( & V_9 -> V_60 ) ;
V_9 -> V_23 -> V_64 ( V_9 , ( void * ) V_36 , V_63 ) ;
V_9 -> V_12 -> V_14 . V_65 += V_63 ;
F_40 ( & V_9 -> V_60 ) ;
F_41 ( V_26 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_9 ( L_1 ) ;
V_12 = F_43 () ;
if ( ! V_12 ) {
F_19 ( L_10 ) ;
return - V_66 ;
}
V_9 -> V_12 = V_12 ;
V_12 -> V_67 = V_68 ;
F_44 ( V_12 , V_9 ) ;
V_12 -> V_69 = F_23 ;
V_12 -> V_44 = F_28 ;
V_12 -> V_50 = F_24 ;
V_12 -> V_70 = F_29 ;
F_45 ( V_12 , V_9 -> V_26 -> V_51 ) ;
if ( F_14 ( V_71 , & V_9 -> V_43 ) )
F_8 ( V_72 , & V_12 -> V_73 ) ;
if ( ! F_14 ( V_74 , & V_9 -> V_43 ) )
F_8 ( V_75 , & V_12 -> V_73 ) ;
if ( F_14 ( V_76 , & V_9 -> V_43 ) )
V_12 -> V_77 = V_78 ;
else
V_12 -> V_77 = V_79 ;
if ( F_14 ( V_42 , & V_9 -> V_43 ) )
return 0 ;
if ( F_18 ( V_12 ) < 0 ) {
F_19 ( L_2 ) ;
F_20 ( V_12 ) ;
return - V_52 ;
}
F_8 ( V_45 , & V_9 -> V_33 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 , int V_3 )
{
struct V_1 * V_2 ;
int V_41 ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_2 )
return - V_80 ;
V_41 = V_2 -> V_69 ( V_9 ) ;
if ( V_41 )
return V_41 ;
V_9 -> V_23 = V_2 ;
V_41 = F_42 ( V_9 ) ;
if ( V_41 ) {
V_2 -> V_44 ( V_9 ) ;
return V_41 ;
}
return 0 ;
}
static int F_47 ( struct V_25 * V_26 , struct V_81 * V_81 ,
unsigned int V_82 , unsigned long V_83 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_55 ;
int V_41 = 0 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return - V_84 ;
switch ( V_82 ) {
case V_85 :
if ( ! F_7 ( V_49 , & V_9 -> V_33 ) ) {
V_41 = F_46 ( V_9 , V_83 ) ;
if ( V_41 ) {
F_10 ( V_49 , & V_9 -> V_33 ) ;
return V_41 ;
}
} else
return - V_53 ;
break;
case V_86 :
if ( F_14 ( V_49 , & V_9 -> V_33 ) )
return V_9 -> V_23 -> V_3 ;
return - V_87 ;
case V_88 :
if ( F_14 ( V_49 , & V_9 -> V_33 ) )
return V_9 -> V_12 -> V_3 ;
return - V_87 ;
case V_89 :
if ( F_14 ( V_49 , & V_9 -> V_33 ) )
return - V_53 ;
V_9 -> V_43 = V_83 ;
break;
case V_90 :
return V_9 -> V_43 ;
default:
V_41 = F_48 ( V_26 , V_81 , V_82 , V_83 ) ;
break;
} ;
return V_41 ;
}
static T_2 F_49 ( struct V_25 * V_26 , struct V_81 * V_81 ,
unsigned char T_3 * V_91 , T_4 V_92 )
{
return 0 ;
}
static T_2 F_50 ( struct V_25 * V_26 , struct V_81 * V_81 ,
const unsigned char * V_36 , T_4 V_63 )
{
return 0 ;
}
static unsigned int F_51 ( struct V_25 * V_26 ,
struct V_81 * V_93 , T_5 * V_94 )
{
return 0 ;
}
static int T_6 F_52 ( void )
{
static struct V_95 V_96 ;
int V_41 ;
F_53 ( L_11 , V_97 ) ;
memset ( & V_96 , 0 , sizeof ( V_96 ) ) ;
V_96 . V_98 = V_99 ;
V_96 . V_47 = L_12 ;
V_96 . V_69 = F_30 ;
V_96 . V_44 = F_34 ;
V_96 . V_100 = F_49 ;
V_96 . V_35 = F_50 ;
V_96 . V_101 = F_47 ;
V_96 . V_102 = F_51 ;
V_96 . V_103 = F_38 ;
V_96 . V_104 = F_37 ;
V_96 . V_105 = V_106 ;
if ( ( V_41 = F_54 ( V_107 , & V_96 ) ) ) {
F_19 ( L_13 , V_41 ) ;
return V_41 ;
}
#ifdef F_55
F_56 () ;
#endif
#ifdef F_57
F_58 () ;
#endif
#ifdef F_59
F_60 () ;
#endif
#ifdef F_61
F_62 () ;
#endif
#ifdef F_63
F_64 () ;
#endif
return 0 ;
}
static void T_7 F_65 ( void )
{
int V_41 ;
#ifdef F_55
F_66 () ;
#endif
#ifdef F_57
F_67 () ;
#endif
#ifdef F_59
F_68 () ;
#endif
#ifdef F_61
F_69 () ;
#endif
#ifdef F_63
F_70 () ;
#endif
if ( ( V_41 = F_71 ( V_107 ) ) )
F_19 ( L_14 , V_41 ) ;
}
