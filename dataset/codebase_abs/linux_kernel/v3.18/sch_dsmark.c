static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_3 <= V_2 -> V_4 && V_3 > 0 ;
}
static int F_2 ( struct V_5 * V_6 , unsigned long V_7 ,
struct V_5 * V_8 , struct V_5 * * V_9 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_1 ,
V_10 , V_6 , V_2 , V_8 , V_9 ) ;
if ( V_8 == NULL ) {
V_8 = F_5 ( V_6 -> V_11 , & V_12 ,
V_6 -> V_13 ) ;
if ( V_8 == NULL )
V_8 = & V_14 ;
}
F_6 ( V_6 ) ;
* V_9 = V_2 -> V_15 ;
V_2 -> V_15 = V_8 ;
F_7 ( * V_9 , ( * V_9 ) -> V_15 . V_16 ) ;
F_8 ( * V_9 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static struct V_5 * F_10 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return V_2 -> V_15 ;
}
static unsigned long F_11 ( struct V_5 * V_6 , T_2 V_17 )
{
F_4 ( L_2 ,
V_10 , V_6 , F_3 ( V_6 ) , V_17 ) ;
return F_12 ( V_17 ) + 1 ;
}
static unsigned long F_13 ( struct V_5 * V_6 ,
unsigned long V_18 , T_2 V_17 )
{
return F_11 ( V_6 , V_17 ) ;
}
static void F_14 ( struct V_5 * V_6 , unsigned long V_19 )
{
}
static int F_15 ( struct V_5 * V_6 , T_2 V_17 , T_2 V_18 ,
struct V_20 * * V_21 , unsigned long * V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_22 = V_21 [ V_23 ] ;
struct V_20 * V_24 [ V_25 + 1 ] ;
int V_26 = - V_27 ;
T_3 V_28 = 0 ;
F_4 ( L_3 ,
V_10 , V_6 , V_2 , V_17 , V_18 , * V_7 ) ;
if ( ! F_1 ( V_2 , * V_7 ) ) {
V_26 = - V_29 ;
goto V_30;
}
if ( ! V_22 )
goto V_30;
V_26 = F_16 ( V_24 , V_25 , V_22 , V_31 ) ;
if ( V_26 < 0 )
goto V_30;
if ( V_24 [ V_32 ] )
V_28 = F_17 ( V_24 [ V_32 ] ) ;
if ( V_24 [ V_33 ] )
V_2 -> V_34 [ * V_7 - 1 ] = F_17 ( V_24 [ V_33 ] ) ;
if ( V_24 [ V_32 ] )
V_2 -> V_28 [ * V_7 - 1 ] = V_28 ;
V_26 = 0 ;
V_30:
return V_26 ;
}
static int F_18 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
if ( ! F_1 ( V_2 , V_7 ) )
return - V_27 ;
V_2 -> V_28 [ V_7 - 1 ] = 0xff ;
V_2 -> V_34 [ V_7 - 1 ] = 0 ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_37 ;
F_4 ( L_4 ,
V_10 , V_6 , V_2 , V_36 ) ;
if ( V_36 -> V_38 )
return;
for ( V_37 = 0 ; V_37 < V_2 -> V_4 ; V_37 ++ ) {
if ( V_2 -> V_28 [ V_37 ] == 0xff && ! V_2 -> V_34 [ V_37 ] )
goto V_39;
if ( V_36 -> V_40 >= V_36 -> V_41 ) {
if ( V_36 -> V_42 ( V_6 , V_37 + 1 , V_36 ) < 0 ) {
V_36 -> V_38 = 1 ;
break;
}
}
V_39:
V_36 -> V_40 ++ ;
}
}
static inline struct V_43 T_4 * * F_20 ( struct V_5 * V_6 ,
unsigned long V_19 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return & V_2 -> V_44 ;
}
static int F_21 ( struct V_45 * V_46 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_26 ;
F_4 ( L_5 , V_10 , V_46 , V_6 , V_2 ) ;
if ( V_2 -> V_47 ) {
switch ( V_46 -> V_48 ) {
case F_22 ( V_49 ) :
if ( F_23 ( V_46 , sizeof( struct V_50 ) ) )
goto V_51;
V_46 -> V_52 = F_24 ( F_25 ( V_46 ) )
& ~ V_53 ;
break;
case F_22 ( V_54 ) :
if ( F_23 ( V_46 , sizeof( struct V_55 ) ) )
goto V_51;
V_46 -> V_52 = F_26 ( F_27 ( V_46 ) )
& ~ V_53 ;
break;
default:
V_46 -> V_52 = 0 ;
break;
}
}
if ( F_28 ( V_46 -> V_56 ) == V_6 -> V_13 )
V_46 -> V_52 = F_12 ( V_46 -> V_56 ) ;
else {
struct V_57 V_58 ;
struct V_43 * V_59 = F_29 ( V_2 -> V_44 ) ;
int V_60 = F_30 ( V_46 , V_59 , & V_58 ) ;
F_4 ( L_6 , V_60 , V_58 . V_17 ) ;
switch ( V_60 ) {
#ifdef F_31
case V_61 :
case V_62 :
F_32 ( V_46 ) ;
return V_63 | V_64 ;
case V_65 :
goto V_51;
#endif
case V_66 :
V_46 -> V_52 = F_12 ( V_58 . V_17 ) ;
break;
default:
if ( V_2 -> V_67 != V_68 )
V_46 -> V_52 = V_2 -> V_67 ;
break;
}
}
V_26 = F_33 ( V_46 , V_2 -> V_15 ) ;
if ( V_26 != V_63 ) {
if ( F_34 ( V_26 ) )
F_35 ( V_6 ) ;
return V_26 ;
}
V_6 -> V_15 . V_16 ++ ;
return V_63 ;
V_51:
F_36 ( V_46 , V_6 ) ;
return V_63 | V_69 ;
}
static struct V_45 * F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_45 * V_46 ;
T_2 V_3 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
V_46 = V_2 -> V_15 -> V_70 -> V_71 ( V_2 -> V_15 ) ;
if ( V_46 == NULL )
return NULL ;
F_38 ( V_6 , V_46 ) ;
V_6 -> V_15 . V_16 -- ;
V_3 = V_46 -> V_52 & ( V_2 -> V_4 - 1 ) ;
F_4 ( L_8 , V_46 -> V_52 , V_3 ) ;
switch ( V_46 -> V_48 ) {
case F_22 ( V_49 ) :
F_39 ( F_25 ( V_46 ) , V_2 -> V_28 [ V_3 ] ,
V_2 -> V_34 [ V_3 ] ) ;
break;
case F_22 ( V_54 ) :
F_40 ( F_27 ( V_46 ) , V_2 -> V_28 [ V_3 ] ,
V_2 -> V_34 [ V_3 ] ) ;
break;
default:
if ( V_2 -> V_28 [ V_3 ] != 0xff || V_2 -> V_34 [ V_3 ] )
F_41 ( L_9 ,
V_10 , F_42 ( V_46 -> V_48 ) ) ;
break;
}
return V_46 ;
}
static struct V_45 * F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
return V_2 -> V_15 -> V_70 -> V_72 ( V_2 -> V_15 ) ;
}
static unsigned int F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned int V_73 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
if ( V_2 -> V_15 -> V_70 -> V_51 == NULL )
return 0 ;
V_73 = V_2 -> V_15 -> V_70 -> V_51 ( V_2 -> V_15 ) ;
if ( V_73 )
V_6 -> V_15 . V_16 -- ;
return V_73 ;
}
static int F_45 ( struct V_5 * V_6 , struct V_20 * V_22 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_24 [ V_25 + 1 ] ;
int V_26 = - V_27 ;
T_2 V_67 = V_68 ;
T_1 V_4 ;
T_3 * V_28 ;
F_4 ( L_10 , V_10 , V_6 , V_2 , V_22 ) ;
if ( ! V_22 )
goto V_30;
V_26 = F_16 ( V_24 , V_25 , V_22 , V_31 ) ;
if ( V_26 < 0 )
goto V_30;
V_26 = - V_27 ;
V_4 = F_46 ( V_24 [ V_74 ] ) ;
if ( F_47 ( V_4 ) != 1 )
goto V_30;
if ( V_24 [ V_75 ] )
V_67 = F_46 ( V_24 [ V_75 ] ) ;
V_28 = F_48 ( V_4 * 2 , V_76 ) ;
if ( V_28 == NULL ) {
V_26 = - V_77 ;
goto V_30;
}
V_2 -> V_28 = V_28 ;
memset ( V_2 -> V_28 , 0xff , V_4 ) ;
V_2 -> V_34 = V_2 -> V_28 + V_4 ;
memset ( V_2 -> V_34 , 0 , V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_47 = F_49 ( V_24 [ V_78 ] ) ;
V_2 -> V_15 = F_5 ( V_6 -> V_11 , & V_12 , V_6 -> V_13 ) ;
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = & V_14 ;
F_4 ( L_11 , V_10 , V_2 -> V_15 ) ;
V_26 = 0 ;
V_30:
return V_26 ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_8 ( V_2 -> V_15 ) ;
V_6 -> V_15 . V_16 = 0 ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_52 ( & V_2 -> V_44 ) ;
F_53 ( V_2 -> V_15 ) ;
F_54 ( V_2 -> V_28 ) ;
}
static int F_55 ( struct V_5 * V_6 , unsigned long V_19 ,
struct V_45 * V_46 , struct V_79 * V_80 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_81 = NULL ;
F_4 ( L_12 , V_10 , V_6 , V_2 , V_19 ) ;
if ( ! F_1 ( V_2 , V_19 ) )
return - V_27 ;
V_80 -> V_82 = F_56 ( F_28 ( V_6 -> V_13 ) , V_19 - 1 ) ;
V_80 -> V_83 = V_2 -> V_15 -> V_13 ;
V_81 = F_57 ( V_46 , V_23 ) ;
if ( V_81 == NULL )
goto V_84;
if ( F_58 ( V_46 , V_32 , V_2 -> V_28 [ V_19 - 1 ] ) ||
F_58 ( V_46 , V_33 , V_2 -> V_34 [ V_19 - 1 ] ) )
goto V_84;
return F_59 ( V_46 , V_81 ) ;
V_84:
F_60 ( V_46 , V_81 ) ;
return - V_85 ;
}
static int F_61 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_81 = NULL ;
V_81 = F_57 ( V_46 , V_23 ) ;
if ( V_81 == NULL )
goto V_84;
if ( F_62 ( V_46 , V_74 , V_2 -> V_4 ) )
goto V_84;
if ( V_2 -> V_67 != V_68 &&
F_62 ( V_46 , V_75 , V_2 -> V_67 ) )
goto V_84;
if ( V_2 -> V_47 &&
F_63 ( V_46 , V_78 ) )
goto V_84;
return F_59 ( V_46 , V_81 ) ;
V_84:
F_60 ( V_46 , V_81 ) ;
return - V_85 ;
}
static int T_5 F_64 ( void )
{
return F_65 ( & V_86 ) ;
}
static void T_6 F_66 ( void )
{
F_67 ( & V_86 ) ;
}
