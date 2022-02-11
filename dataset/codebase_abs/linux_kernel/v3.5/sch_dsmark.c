static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( V_3 <= V_2 -> V_4 && V_3 > 0 ) ;
}
static int F_2 ( struct V_5 * V_6 , unsigned long V_7 ,
struct V_5 * V_8 , struct V_5 * * V_9 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_1 ,
V_6 , V_2 , V_8 , V_9 ) ;
if ( V_8 == NULL ) {
V_8 = F_5 ( V_6 -> V_10 , & V_11 ,
V_6 -> V_12 ) ;
if ( V_8 == NULL )
V_8 = & V_13 ;
}
F_6 ( V_6 ) ;
* V_9 = V_2 -> V_14 ;
V_2 -> V_14 = V_8 ;
F_7 ( * V_9 , ( * V_9 ) -> V_14 . V_15 ) ;
F_8 ( * V_9 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static struct V_5 * F_10 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return V_2 -> V_14 ;
}
static unsigned long F_11 ( struct V_5 * V_6 , T_2 V_16 )
{
F_4 ( L_2 ,
V_6 , F_3 ( V_6 ) , V_16 ) ;
return F_12 ( V_16 ) + 1 ;
}
static unsigned long F_13 ( struct V_5 * V_6 ,
unsigned long V_17 , T_2 V_16 )
{
return F_11 ( V_6 , V_16 ) ;
}
static void F_14 ( struct V_5 * V_6 , unsigned long V_18 )
{
}
static int F_15 ( struct V_5 * V_6 , T_2 V_16 , T_2 V_17 ,
struct V_19 * * V_20 , unsigned long * V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_21 = V_20 [ V_22 ] ;
struct V_19 * V_23 [ V_24 + 1 ] ;
int V_25 = - V_26 ;
T_3 V_27 = 0 ;
F_4 ( L_3
L_4 , V_6 , V_2 , V_16 , V_17 , * V_7 ) ;
if ( ! F_1 ( V_2 , * V_7 ) ) {
V_25 = - V_28 ;
goto V_29;
}
if ( ! V_21 )
goto V_29;
V_25 = F_16 ( V_23 , V_24 , V_21 , V_30 ) ;
if ( V_25 < 0 )
goto V_29;
if ( V_23 [ V_31 ] )
V_27 = F_17 ( V_23 [ V_31 ] ) ;
if ( V_23 [ V_32 ] )
V_2 -> V_33 [ * V_7 - 1 ] = F_17 ( V_23 [ V_32 ] ) ;
if ( V_23 [ V_31 ] )
V_2 -> V_27 [ * V_7 - 1 ] = V_27 ;
V_25 = 0 ;
V_29:
return V_25 ;
}
static int F_18 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
if ( ! F_1 ( V_2 , V_7 ) )
return - V_26 ;
V_2 -> V_27 [ V_7 - 1 ] = 0xff ;
V_2 -> V_33 [ V_7 - 1 ] = 0 ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 , struct V_34 * V_35 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_36 ;
F_4 ( L_5 , V_6 , V_2 , V_35 ) ;
if ( V_35 -> V_37 )
return;
for ( V_36 = 0 ; V_36 < V_2 -> V_4 ; V_36 ++ ) {
if ( V_2 -> V_27 [ V_36 ] == 0xff && ! V_2 -> V_33 [ V_36 ] )
goto V_38;
if ( V_35 -> V_39 >= V_35 -> V_40 ) {
if ( V_35 -> V_41 ( V_6 , V_36 + 1 , V_35 ) < 0 ) {
V_35 -> V_37 = 1 ;
break;
}
}
V_38:
V_35 -> V_39 ++ ;
}
}
static inline struct V_42 * * F_20 ( struct V_5 * V_6 ,
unsigned long V_18 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return & V_2 -> V_43 ;
}
static int F_21 ( struct V_44 * V_45 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_25 ;
F_4 ( L_6 , V_45 , V_6 , V_2 ) ;
if ( V_2 -> V_46 ) {
switch ( V_45 -> V_47 ) {
case F_22 ( V_48 ) :
if ( F_23 ( V_45 , sizeof( struct V_49 ) ) )
goto V_50;
V_45 -> V_51 = F_24 ( F_25 ( V_45 ) )
& ~ V_52 ;
break;
case F_22 ( V_53 ) :
if ( F_23 ( V_45 , sizeof( struct V_54 ) ) )
goto V_50;
V_45 -> V_51 = F_26 ( F_27 ( V_45 ) )
& ~ V_52 ;
break;
default:
V_45 -> V_51 = 0 ;
break;
}
}
if ( F_28 ( V_45 -> V_55 ) == V_6 -> V_12 )
V_45 -> V_51 = F_12 ( V_45 -> V_55 ) ;
else {
struct V_56 V_57 ;
int V_58 = F_29 ( V_45 , V_2 -> V_43 , & V_57 ) ;
F_4 ( L_7 , V_58 , V_57 . V_16 ) ;
switch ( V_58 ) {
#ifdef F_30
case V_59 :
case V_60 :
F_31 ( V_45 ) ;
return V_61 | V_62 ;
case V_63 :
goto V_50;
#endif
case V_64 :
V_45 -> V_51 = F_12 ( V_57 . V_16 ) ;
break;
default:
if ( V_2 -> V_65 != V_66 )
V_45 -> V_51 = V_2 -> V_65 ;
break;
}
}
V_25 = F_32 ( V_45 , V_2 -> V_14 ) ;
if ( V_25 != V_61 ) {
if ( F_33 ( V_25 ) )
V_6 -> V_67 . V_68 ++ ;
return V_25 ;
}
V_6 -> V_14 . V_15 ++ ;
return V_61 ;
V_50:
F_34 ( V_45 , V_6 ) ;
return V_61 | V_69 ;
}
static struct V_44 * F_35 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_44 * V_45 ;
T_2 V_3 ;
F_4 ( L_8 , V_6 , V_2 ) ;
V_45 = V_2 -> V_14 -> V_70 -> V_71 ( V_2 -> V_14 ) ;
if ( V_45 == NULL )
return NULL ;
F_36 ( V_6 , V_45 ) ;
V_6 -> V_14 . V_15 -- ;
V_3 = V_45 -> V_51 & ( V_2 -> V_4 - 1 ) ;
F_4 ( L_9 , V_45 -> V_51 , V_3 ) ;
switch ( V_45 -> V_47 ) {
case F_22 ( V_48 ) :
F_37 ( F_25 ( V_45 ) , V_2 -> V_27 [ V_3 ] ,
V_2 -> V_33 [ V_3 ] ) ;
break;
case F_22 ( V_53 ) :
F_38 ( F_27 ( V_45 ) , V_2 -> V_27 [ V_3 ] ,
V_2 -> V_33 [ V_3 ] ) ;
break;
default:
if ( V_2 -> V_27 [ V_3 ] != 0xff || V_2 -> V_33 [ V_3 ] )
F_39 ( L_10 ,
F_40 ( V_45 -> V_47 ) ) ;
break;
}
return V_45 ;
}
static struct V_44 * F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_11 , V_6 , V_2 ) ;
return V_2 -> V_14 -> V_70 -> V_72 ( V_2 -> V_14 ) ;
}
static unsigned int F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned int V_73 ;
F_4 ( L_12 , V_6 , V_2 ) ;
if ( V_2 -> V_14 -> V_70 -> V_50 == NULL )
return 0 ;
V_73 = V_2 -> V_14 -> V_70 -> V_50 ( V_2 -> V_14 ) ;
if ( V_73 )
V_6 -> V_14 . V_15 -- ;
return V_73 ;
}
static int F_43 ( struct V_5 * V_6 , struct V_19 * V_21 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_23 [ V_24 + 1 ] ;
int V_25 = - V_26 ;
T_2 V_65 = V_66 ;
T_1 V_4 ;
T_3 * V_27 ;
F_4 ( L_13 , V_6 , V_2 , V_21 ) ;
if ( ! V_21 )
goto V_29;
V_25 = F_16 ( V_23 , V_24 , V_21 , V_30 ) ;
if ( V_25 < 0 )
goto V_29;
V_25 = - V_26 ;
V_4 = F_44 ( V_23 [ V_74 ] ) ;
if ( F_45 ( V_4 ) != 1 )
goto V_29;
if ( V_23 [ V_75 ] )
V_65 = F_44 ( V_23 [ V_75 ] ) ;
V_27 = F_46 ( V_4 * 2 , V_76 ) ;
if ( V_27 == NULL ) {
V_25 = - V_77 ;
goto V_29;
}
V_2 -> V_27 = V_27 ;
memset ( V_2 -> V_27 , 0xff , V_4 ) ;
V_2 -> V_33 = V_2 -> V_27 + V_4 ;
memset ( V_2 -> V_33 , 0 , V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_46 = F_47 ( V_23 [ V_78 ] ) ;
V_2 -> V_14 = F_5 ( V_6 -> V_10 , & V_11 , V_6 -> V_12 ) ;
if ( V_2 -> V_14 == NULL )
V_2 -> V_14 = & V_13 ;
F_4 ( L_14 , V_2 -> V_14 ) ;
V_25 = 0 ;
V_29:
return V_25 ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_12 , V_6 , V_2 ) ;
F_8 ( V_2 -> V_14 ) ;
V_6 -> V_14 . V_15 = 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_15 , V_6 , V_2 ) ;
F_50 ( & V_2 -> V_43 ) ;
F_51 ( V_2 -> V_14 ) ;
F_52 ( V_2 -> V_27 ) ;
}
static int F_53 ( struct V_5 * V_6 , unsigned long V_18 ,
struct V_44 * V_45 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_81 = NULL ;
F_4 ( L_16 , V_6 , V_2 , V_18 ) ;
if ( ! F_1 ( V_2 , V_18 ) )
return - V_26 ;
V_80 -> V_82 = F_54 ( F_28 ( V_6 -> V_12 ) , V_18 - 1 ) ;
V_80 -> V_83 = V_2 -> V_14 -> V_12 ;
V_81 = F_55 ( V_45 , V_22 ) ;
if ( V_81 == NULL )
goto V_84;
if ( F_56 ( V_45 , V_31 , V_2 -> V_27 [ V_18 - 1 ] ) ||
F_56 ( V_45 , V_32 , V_2 -> V_33 [ V_18 - 1 ] ) )
goto V_84;
return F_57 ( V_45 , V_81 ) ;
V_84:
F_58 ( V_45 , V_81 ) ;
return - V_85 ;
}
static int F_59 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_81 = NULL ;
V_81 = F_55 ( V_45 , V_22 ) ;
if ( V_81 == NULL )
goto V_84;
if ( F_60 ( V_45 , V_74 , V_2 -> V_4 ) )
goto V_84;
if ( V_2 -> V_65 != V_66 &&
F_60 ( V_45 , V_75 , V_2 -> V_65 ) )
goto V_84;
if ( V_2 -> V_46 &&
F_61 ( V_45 , V_78 ) )
goto V_84;
return F_57 ( V_45 , V_81 ) ;
V_84:
F_58 ( V_45 , V_81 ) ;
return - V_85 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_86 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_86 ) ;
}
