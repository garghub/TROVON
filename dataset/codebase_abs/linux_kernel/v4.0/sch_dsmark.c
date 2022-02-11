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
switch ( F_22 ( V_46 ) ) {
case F_23 ( V_48 ) :
if ( F_24 ( V_46 , sizeof( struct V_49 ) ) )
goto V_50;
V_46 -> V_51 = F_25 ( F_26 ( V_46 ) )
& ~ V_52 ;
break;
case F_23 ( V_53 ) :
if ( F_24 ( V_46 , sizeof( struct V_54 ) ) )
goto V_50;
V_46 -> V_51 = F_27 ( F_28 ( V_46 ) )
& ~ V_52 ;
break;
default:
V_46 -> V_51 = 0 ;
break;
}
}
if ( F_29 ( V_46 -> V_55 ) == V_6 -> V_13 )
V_46 -> V_51 = F_12 ( V_46 -> V_55 ) ;
else {
struct V_56 V_57 ;
struct V_43 * V_58 = F_30 ( V_2 -> V_44 ) ;
int V_59 = F_31 ( V_46 , V_58 , & V_57 ) ;
F_4 ( L_6 , V_59 , V_57 . V_17 ) ;
switch ( V_59 ) {
#ifdef F_32
case V_60 :
case V_61 :
F_33 ( V_46 ) ;
return V_62 | V_63 ;
case V_64 :
goto V_50;
#endif
case V_65 :
V_46 -> V_51 = F_12 ( V_57 . V_17 ) ;
break;
default:
if ( V_2 -> V_66 != V_67 )
V_46 -> V_51 = V_2 -> V_66 ;
break;
}
}
V_26 = F_34 ( V_46 , V_2 -> V_15 ) ;
if ( V_26 != V_62 ) {
if ( F_35 ( V_26 ) )
F_36 ( V_6 ) ;
return V_26 ;
}
V_6 -> V_15 . V_16 ++ ;
return V_62 ;
V_50:
F_37 ( V_46 , V_6 ) ;
return V_62 | V_68 ;
}
static struct V_45 * F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_45 * V_46 ;
T_2 V_3 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
V_46 = V_2 -> V_15 -> V_69 -> V_70 ( V_2 -> V_15 ) ;
if ( V_46 == NULL )
return NULL ;
F_39 ( V_6 , V_46 ) ;
V_6 -> V_15 . V_16 -- ;
V_3 = V_46 -> V_51 & ( V_2 -> V_4 - 1 ) ;
F_4 ( L_8 , V_46 -> V_51 , V_3 ) ;
switch ( F_22 ( V_46 ) ) {
case F_23 ( V_48 ) :
F_40 ( F_26 ( V_46 ) , V_2 -> V_28 [ V_3 ] ,
V_2 -> V_34 [ V_3 ] ) ;
break;
case F_23 ( V_53 ) :
F_41 ( F_28 ( V_46 ) , V_2 -> V_28 [ V_3 ] ,
V_2 -> V_34 [ V_3 ] ) ;
break;
default:
if ( V_2 -> V_28 [ V_3 ] != 0xff || V_2 -> V_34 [ V_3 ] )
F_42 ( L_9 ,
V_10 , F_43 ( F_22 ( V_46 ) ) ) ;
break;
}
return V_46 ;
}
static struct V_45 * F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
return V_2 -> V_15 -> V_69 -> V_71 ( V_2 -> V_15 ) ;
}
static unsigned int F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
unsigned int V_72 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
if ( V_2 -> V_15 -> V_69 -> V_50 == NULL )
return 0 ;
V_72 = V_2 -> V_15 -> V_69 -> V_50 ( V_2 -> V_15 ) ;
if ( V_72 )
V_6 -> V_15 . V_16 -- ;
return V_72 ;
}
static int F_46 ( struct V_5 * V_6 , struct V_20 * V_22 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_24 [ V_25 + 1 ] ;
int V_26 = - V_27 ;
T_2 V_66 = V_67 ;
T_1 V_4 ;
T_3 * V_28 ;
F_4 ( L_10 , V_10 , V_6 , V_2 , V_22 ) ;
if ( ! V_22 )
goto V_30;
V_26 = F_16 ( V_24 , V_25 , V_22 , V_31 ) ;
if ( V_26 < 0 )
goto V_30;
V_26 = - V_27 ;
V_4 = F_47 ( V_24 [ V_73 ] ) ;
if ( F_48 ( V_4 ) != 1 )
goto V_30;
if ( V_24 [ V_74 ] )
V_66 = F_47 ( V_24 [ V_74 ] ) ;
V_28 = F_49 ( V_4 * 2 , V_75 ) ;
if ( V_28 == NULL ) {
V_26 = - V_76 ;
goto V_30;
}
V_2 -> V_28 = V_28 ;
memset ( V_2 -> V_28 , 0xff , V_4 ) ;
V_2 -> V_34 = V_2 -> V_28 + V_4 ;
memset ( V_2 -> V_34 , 0 , V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_47 = F_50 ( V_24 [ V_77 ] ) ;
V_2 -> V_15 = F_5 ( V_6 -> V_11 , & V_12 , V_6 -> V_13 ) ;
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = & V_14 ;
F_4 ( L_11 , V_10 , V_2 -> V_15 ) ;
V_26 = 0 ;
V_30:
return V_26 ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_8 ( V_2 -> V_15 ) ;
V_6 -> V_15 . V_16 = 0 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_53 ( & V_2 -> V_44 ) ;
F_54 ( V_2 -> V_15 ) ;
F_55 ( V_2 -> V_28 ) ;
}
static int F_56 ( struct V_5 * V_6 , unsigned long V_19 ,
struct V_45 * V_46 , struct V_78 * V_79 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_80 = NULL ;
F_4 ( L_12 , V_10 , V_6 , V_2 , V_19 ) ;
if ( ! F_1 ( V_2 , V_19 ) )
return - V_27 ;
V_79 -> V_81 = F_57 ( F_29 ( V_6 -> V_13 ) , V_19 - 1 ) ;
V_79 -> V_82 = V_2 -> V_15 -> V_13 ;
V_80 = F_58 ( V_46 , V_23 ) ;
if ( V_80 == NULL )
goto V_83;
if ( F_59 ( V_46 , V_32 , V_2 -> V_28 [ V_19 - 1 ] ) ||
F_59 ( V_46 , V_33 , V_2 -> V_34 [ V_19 - 1 ] ) )
goto V_83;
return F_60 ( V_46 , V_80 ) ;
V_83:
F_61 ( V_46 , V_80 ) ;
return - V_84 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_80 = NULL ;
V_80 = F_58 ( V_46 , V_23 ) ;
if ( V_80 == NULL )
goto V_83;
if ( F_63 ( V_46 , V_73 , V_2 -> V_4 ) )
goto V_83;
if ( V_2 -> V_66 != V_67 &&
F_63 ( V_46 , V_74 , V_2 -> V_66 ) )
goto V_83;
if ( V_2 -> V_47 &&
F_64 ( V_46 , V_77 ) )
goto V_83;
return F_60 ( V_46 , V_80 ) ;
V_83:
F_61 ( V_46 , V_80 ) ;
return - V_84 ;
}
static int T_5 F_65 ( void )
{
return F_66 ( & V_85 ) ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_85 ) ;
}
