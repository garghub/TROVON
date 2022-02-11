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
struct V_8 * V_9 = F_17 ( V_12 ) ;
struct V_25 * V_26 = V_9 -> V_26 ;
F_9 ( L_3 , V_12 , V_26 ) ;
if ( V_9 -> V_22 ) {
F_13 ( V_9 -> V_22 ) ; V_9 -> V_22 = NULL ;
}
F_18 ( V_26 ) ;
F_19 ( V_26 ) ;
if ( F_14 ( V_40 , & V_9 -> V_33 ) )
V_9 -> V_23 -> V_41 ( V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
F_9 ( L_4 , V_12 ) ;
if ( ! F_21 ( V_39 , & V_12 -> V_33 ) )
return 0 ;
F_16 ( V_12 ) ;
V_12 -> V_41 = NULL ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = (struct V_11 * ) V_21 -> V_42 ;
struct V_8 * V_9 ;
if ( ! V_12 ) {
F_23 ( L_5 ) ;
return - V_43 ;
}
if ( ! F_14 ( V_39 , & V_12 -> V_33 ) )
return - V_44 ;
V_9 = F_17 ( V_12 ) ;
F_9 ( L_6 , V_12 -> V_38 , F_12 ( V_21 ) -> V_10 , V_21 -> V_31 ) ;
V_9 -> V_23 -> V_45 ( V_9 , V_21 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_46 ;
F_9 ( L_7 , V_26 ) ;
if ( V_9 )
return - V_7 ;
if ( V_26 -> V_34 -> V_35 == NULL )
return - V_47 ;
if ( ! ( V_9 = F_25 ( sizeof( struct V_8 ) , V_48 ) ) ) {
F_23 ( L_8 ) ;
return - V_49 ;
}
V_26 -> V_46 = V_9 ;
V_9 -> V_26 = V_26 ;
V_26 -> V_50 = 65536 ;
F_26 ( & V_9 -> V_51 ) ;
if ( V_26 -> V_52 -> V_34 -> V_53 )
V_26 -> V_52 -> V_34 -> V_53 ( V_26 ) ;
F_19 ( V_26 ) ;
return 0 ;
}
static void F_27 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_46 ;
F_9 ( L_7 , V_26 ) ;
V_26 -> V_46 = NULL ;
if ( V_9 ) {
struct V_11 * V_12 = V_9 -> V_12 ;
if ( V_12 )
F_20 ( V_12 ) ;
if ( F_21 ( V_40 , & V_9 -> V_33 ) ) {
if ( V_12 ) {
F_28 ( V_12 ) ;
F_29 ( V_12 ) ;
}
V_9 -> V_23 -> V_54 ( V_9 ) ;
}
F_30 ( V_9 ) ;
}
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_46 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return;
F_10 ( V_32 , & V_26 -> V_33 ) ;
if ( V_26 != V_9 -> V_26 )
return;
if ( F_14 ( V_40 , & V_9 -> V_33 ) )
F_6 ( V_9 ) ;
}
static void F_32 ( struct V_25 * V_26 , const T_1 * V_36 , char * V_33 , int V_55 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_46 ;
if ( ! V_9 || V_26 != V_9 -> V_26 )
return;
if ( ! F_14 ( V_40 , & V_9 -> V_33 ) )
return;
F_33 ( & V_9 -> V_51 ) ;
V_9 -> V_23 -> V_56 ( V_9 , ( void * ) V_36 , V_55 ) ;
V_9 -> V_12 -> V_14 . V_57 += V_55 ;
F_34 ( & V_9 -> V_51 ) ;
F_35 ( V_26 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_9 ( L_1 ) ;
V_12 = F_37 () ;
if ( ! V_12 ) {
F_23 ( L_9 ) ;
return - V_58 ;
}
V_9 -> V_12 = V_12 ;
V_12 -> V_59 = V_60 ;
F_38 ( V_12 , V_9 ) ;
V_12 -> V_61 = F_15 ;
V_12 -> V_54 = F_20 ;
V_12 -> V_41 = F_16 ;
V_12 -> V_62 = F_22 ;
F_39 ( V_12 , V_9 -> V_26 -> V_42 ) ;
if ( F_14 ( V_63 , & V_9 -> V_64 ) )
F_8 ( V_65 , & V_12 -> V_66 ) ;
if ( ! F_14 ( V_67 , & V_9 -> V_64 ) )
F_8 ( V_68 , & V_12 -> V_66 ) ;
if ( F_14 ( V_69 , & V_9 -> V_64 ) )
V_12 -> V_70 = V_71 ;
else
V_12 -> V_70 = V_72 ;
if ( F_40 ( V_12 ) < 0 ) {
F_23 ( L_10 ) ;
F_29 ( V_12 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_41 ( struct V_8 * V_9 , int V_3 )
{
struct V_1 * V_2 ;
int V_73 ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_2 )
return - V_74 ;
V_73 = V_2 -> V_61 ( V_9 ) ;
if ( V_73 )
return V_73 ;
V_9 -> V_23 = V_2 ;
V_73 = F_36 ( V_9 ) ;
if ( V_73 ) {
V_2 -> V_54 ( V_9 ) ;
return V_73 ;
}
return 0 ;
}
static int F_42 ( struct V_25 * V_26 , struct V_75 * V_75 ,
unsigned int V_76 , unsigned long V_77 )
{
struct V_8 * V_9 = ( void * ) V_26 -> V_46 ;
int V_73 = 0 ;
F_9 ( L_1 ) ;
if ( ! V_9 )
return - V_78 ;
switch ( V_76 ) {
case V_79 :
if ( ! F_7 ( V_40 , & V_9 -> V_33 ) ) {
V_73 = F_41 ( V_9 , V_77 ) ;
if ( V_73 ) {
F_10 ( V_40 , & V_9 -> V_33 ) ;
return V_73 ;
}
} else
return - V_44 ;
break;
case V_80 :
if ( F_14 ( V_40 , & V_9 -> V_33 ) )
return V_9 -> V_23 -> V_3 ;
return - V_81 ;
case V_82 :
if ( F_14 ( V_40 , & V_9 -> V_33 ) )
return V_9 -> V_12 -> V_3 ;
return - V_81 ;
case V_83 :
if ( F_14 ( V_40 , & V_9 -> V_33 ) )
return - V_44 ;
V_9 -> V_64 = V_77 ;
break;
case V_84 :
return V_9 -> V_64 ;
default:
V_73 = F_43 ( V_26 , V_75 , V_76 , V_77 ) ;
break;
} ;
return V_73 ;
}
static T_2 F_44 ( struct V_25 * V_26 , struct V_75 * V_75 ,
unsigned char T_3 * V_85 , T_4 V_86 )
{
return 0 ;
}
static T_2 F_45 ( struct V_25 * V_26 , struct V_75 * V_75 ,
const unsigned char * V_36 , T_4 V_55 )
{
return 0 ;
}
static unsigned int F_46 ( struct V_25 * V_26 ,
struct V_75 * V_87 , T_5 * V_88 )
{
return 0 ;
}
static int T_6 F_47 ( void )
{
static struct V_89 V_90 ;
int V_73 ;
F_48 ( L_11 , V_91 ) ;
memset ( & V_90 , 0 , sizeof ( V_90 ) ) ;
V_90 . V_92 = V_93 ;
V_90 . V_38 = L_12 ;
V_90 . V_61 = F_24 ;
V_90 . V_54 = F_27 ;
V_90 . V_94 = F_44 ;
V_90 . V_35 = F_45 ;
V_90 . V_95 = F_42 ;
V_90 . V_96 = F_46 ;
V_90 . V_97 = F_32 ;
V_90 . V_98 = F_31 ;
V_90 . V_99 = V_100 ;
if ( ( V_73 = F_49 ( V_101 , & V_90 ) ) ) {
F_23 ( L_13 , V_73 ) ;
return V_73 ;
}
#ifdef F_50
F_51 () ;
#endif
#ifdef F_52
F_53 () ;
#endif
#ifdef F_54
F_55 () ;
#endif
#ifdef F_56
F_57 () ;
#endif
return 0 ;
}
static void T_7 F_58 ( void )
{
int V_73 ;
#ifdef F_50
F_59 () ;
#endif
#ifdef F_52
F_60 () ;
#endif
#ifdef F_54
F_61 () ;
#endif
#ifdef F_56
F_62 () ;
#endif
if ( ( V_73 = F_63 ( V_101 ) ) )
F_23 ( L_14 , V_73 ) ;
}
