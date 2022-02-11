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
F_4 ( L_3 ,
V_10 , V_6 , V_2 , V_17 , V_18 , * V_7 ) ;
if ( ! F_1 ( V_2 , * V_7 ) ) {
V_26 = - V_28 ;
goto V_29;
}
if ( ! V_22 )
goto V_29;
V_26 = F_16 ( V_24 , V_25 , V_22 , V_30 ) ;
if ( V_26 < 0 )
goto V_29;
if ( V_24 [ V_31 ] )
V_2 -> V_32 [ * V_7 - 1 ] . V_33 = F_17 ( V_24 [ V_31 ] ) ;
if ( V_24 [ V_34 ] )
V_2 -> V_32 [ * V_7 - 1 ] . V_35 = F_17 ( V_24 [ V_34 ] ) ;
V_26 = 0 ;
V_29:
return V_26 ;
}
static int F_18 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
if ( ! F_1 ( V_2 , V_7 ) )
return - V_27 ;
V_2 -> V_32 [ V_7 - 1 ] . V_35 = 0xff ;
V_2 -> V_32 [ V_7 - 1 ] . V_33 = 0 ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_38 ;
F_4 ( L_4 ,
V_10 , V_6 , V_2 , V_37 ) ;
if ( V_37 -> V_39 )
return;
for ( V_38 = 0 ; V_38 < V_2 -> V_4 ; V_38 ++ ) {
if ( V_2 -> V_32 [ V_38 ] . V_35 == 0xff && ! V_2 -> V_32 [ V_38 ] . V_33 )
goto V_40;
if ( V_37 -> V_41 >= V_37 -> V_42 ) {
if ( V_37 -> V_43 ( V_6 , V_38 + 1 , V_37 ) < 0 ) {
V_37 -> V_39 = 1 ;
break;
}
}
V_40:
V_37 -> V_41 ++ ;
}
}
static inline struct V_44 T_3 * * F_20 ( struct V_5 * V_6 ,
unsigned long V_19 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return & V_2 -> V_45 ;
}
static int F_21 ( struct V_46 * V_47 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_26 ;
F_4 ( L_5 , V_10 , V_47 , V_6 , V_2 ) ;
if ( V_2 -> V_48 ) {
switch ( F_22 ( V_47 ) ) {
case F_23 ( V_49 ) :
if ( F_24 ( V_47 , sizeof( struct V_50 ) ) )
goto V_51;
V_47 -> V_52 = F_25 ( F_26 ( V_47 ) )
& ~ V_53 ;
break;
case F_23 ( V_54 ) :
if ( F_24 ( V_47 , sizeof( struct V_55 ) ) )
goto V_51;
V_47 -> V_52 = F_27 ( F_28 ( V_47 ) )
& ~ V_53 ;
break;
default:
V_47 -> V_52 = 0 ;
break;
}
}
if ( F_29 ( V_47 -> V_56 ) == V_6 -> V_13 )
V_47 -> V_52 = F_12 ( V_47 -> V_56 ) ;
else {
struct V_57 V_58 ;
struct V_44 * V_59 = F_30 ( V_2 -> V_45 ) ;
int V_60 = F_31 ( V_47 , V_59 , & V_58 , false ) ;
F_4 ( L_6 , V_60 , V_58 . V_17 ) ;
switch ( V_60 ) {
#ifdef F_32
case V_61 :
case V_62 :
F_33 ( V_47 ) ;
return V_63 | V_64 ;
case V_65 :
goto V_51;
#endif
case V_66 :
V_47 -> V_52 = F_12 ( V_58 . V_17 ) ;
break;
default:
if ( V_2 -> V_67 != V_68 )
V_47 -> V_52 = V_2 -> V_67 ;
break;
}
}
V_26 = F_34 ( V_47 , V_2 -> V_15 ) ;
if ( V_26 != V_63 ) {
if ( F_35 ( V_26 ) )
F_36 ( V_6 ) ;
return V_26 ;
}
V_6 -> V_15 . V_16 ++ ;
return V_63 ;
V_51:
F_37 ( V_47 , V_6 ) ;
return V_63 | V_69 ;
}
static struct V_46 * F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_46 * V_47 ;
T_2 V_3 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
V_47 = V_2 -> V_15 -> V_70 -> V_71 ( V_2 -> V_15 ) ;
if ( V_47 == NULL )
return NULL ;
F_39 ( V_6 , V_47 ) ;
V_6 -> V_15 . V_16 -- ;
V_3 = V_47 -> V_52 & ( V_2 -> V_4 - 1 ) ;
F_4 ( L_8 , V_47 -> V_52 , V_3 ) ;
switch ( F_22 ( V_47 ) ) {
case F_23 ( V_49 ) :
F_40 ( F_26 ( V_47 ) , V_2 -> V_32 [ V_3 ] . V_35 ,
V_2 -> V_32 [ V_3 ] . V_33 ) ;
break;
case F_23 ( V_54 ) :
F_41 ( F_28 ( V_47 ) , V_2 -> V_32 [ V_3 ] . V_35 ,
V_2 -> V_32 [ V_3 ] . V_33 ) ;
break;
default:
if ( V_2 -> V_32 [ V_3 ] . V_35 != 0xff || V_2 -> V_32 [ V_3 ] . V_33 )
F_42 ( L_9 ,
V_10 , F_43 ( F_22 ( V_47 ) ) ) ;
break;
}
return V_47 ;
}
static struct V_46 * F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
return V_2 -> V_15 -> V_70 -> V_72 ( V_2 -> V_15 ) ;
}
static unsigned int F_45 ( struct V_5 * V_6 )
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
static int F_46 ( struct V_5 * V_6 , struct V_20 * V_22 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_24 [ V_25 + 1 ] ;
int V_26 = - V_27 ;
T_2 V_67 = V_68 ;
T_1 V_4 ;
int V_38 ;
F_4 ( L_10 , V_10 , V_6 , V_2 , V_22 ) ;
if ( ! V_22 )
goto V_29;
V_26 = F_16 ( V_24 , V_25 , V_22 , V_30 ) ;
if ( V_26 < 0 )
goto V_29;
V_26 = - V_27 ;
V_4 = F_47 ( V_24 [ V_74 ] ) ;
if ( F_48 ( V_4 ) != 1 )
goto V_29;
if ( V_24 [ V_75 ] )
V_67 = F_47 ( V_24 [ V_75 ] ) ;
if ( V_4 <= V_76 )
V_2 -> V_32 = V_2 -> V_77 ;
else
V_2 -> V_32 = F_49 ( V_4 , sizeof( * V_2 -> V_32 ) , V_78 ) ;
if ( ! V_2 -> V_32 ) {
V_26 = - V_79 ;
goto V_29;
}
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ ) {
V_2 -> V_32 [ V_38 ] . V_35 = 0xff ;
V_2 -> V_32 [ V_38 ] . V_33 = 0 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_48 = F_50 ( V_24 [ V_80 ] ) ;
V_2 -> V_15 = F_5 ( V_6 -> V_11 , & V_12 , V_6 -> V_13 ) ;
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = & V_14 ;
F_4 ( L_11 , V_10 , V_2 -> V_15 ) ;
V_26 = 0 ;
V_29:
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
F_53 ( & V_2 -> V_45 ) ;
F_54 ( V_2 -> V_15 ) ;
if ( V_2 -> V_32 != V_2 -> V_77 )
F_55 ( V_2 -> V_32 ) ;
}
static int F_56 ( struct V_5 * V_6 , unsigned long V_19 ,
struct V_46 * V_47 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_83 = NULL ;
F_4 ( L_12 , V_10 , V_6 , V_2 , V_19 ) ;
if ( ! F_1 ( V_2 , V_19 ) )
return - V_27 ;
V_82 -> V_84 = F_57 ( F_29 ( V_6 -> V_13 ) , V_19 - 1 ) ;
V_82 -> V_85 = V_2 -> V_15 -> V_13 ;
V_83 = F_58 ( V_47 , V_23 ) ;
if ( V_83 == NULL )
goto V_86;
if ( F_59 ( V_47 , V_34 , V_2 -> V_32 [ V_19 - 1 ] . V_35 ) ||
F_59 ( V_47 , V_31 , V_2 -> V_32 [ V_19 - 1 ] . V_33 ) )
goto V_86;
return F_60 ( V_47 , V_83 ) ;
V_86:
F_61 ( V_47 , V_83 ) ;
return - V_87 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_20 * V_83 = NULL ;
V_83 = F_58 ( V_47 , V_23 ) ;
if ( V_83 == NULL )
goto V_86;
if ( F_63 ( V_47 , V_74 , V_2 -> V_4 ) )
goto V_86;
if ( V_2 -> V_67 != V_68 &&
F_63 ( V_47 , V_75 , V_2 -> V_67 ) )
goto V_86;
if ( V_2 -> V_48 &&
F_64 ( V_47 , V_80 ) )
goto V_86;
return F_60 ( V_47 , V_83 ) ;
V_86:
F_61 ( V_47 , V_83 ) ;
return - V_87 ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_88 ) ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_88 ) ;
}
