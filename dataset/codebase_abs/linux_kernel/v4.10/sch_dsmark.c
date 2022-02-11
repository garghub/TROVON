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
* V_9 = F_6 ( V_6 , V_8 , & V_2 -> V_15 ) ;
return 0 ;
}
static struct V_5 * F_7 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return V_2 -> V_15 ;
}
static unsigned long F_8 ( struct V_5 * V_6 , T_2 V_16 )
{
F_4 ( L_2 ,
V_10 , V_6 , F_3 ( V_6 ) , V_16 ) ;
return F_9 ( V_16 ) + 1 ;
}
static unsigned long F_10 ( struct V_5 * V_6 ,
unsigned long V_17 , T_2 V_16 )
{
return F_8 ( V_6 , V_16 ) ;
}
static void F_11 ( struct V_5 * V_6 , unsigned long V_18 )
{
}
static int F_12 ( struct V_5 * V_6 , T_2 V_16 , T_2 V_17 ,
struct V_19 * * V_20 , unsigned long * V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_21 = V_20 [ V_22 ] ;
struct V_19 * V_23 [ V_24 + 1 ] ;
int V_25 = - V_26 ;
F_4 ( L_3 ,
V_10 , V_6 , V_2 , V_16 , V_17 , * V_7 ) ;
if ( ! F_1 ( V_2 , * V_7 ) ) {
V_25 = - V_27 ;
goto V_28;
}
if ( ! V_21 )
goto V_28;
V_25 = F_13 ( V_23 , V_24 , V_21 , V_29 ) ;
if ( V_25 < 0 )
goto V_28;
if ( V_23 [ V_30 ] )
V_2 -> V_31 [ * V_7 - 1 ] . V_32 = F_14 ( V_23 [ V_30 ] ) ;
if ( V_23 [ V_33 ] )
V_2 -> V_31 [ * V_7 - 1 ] . V_34 = F_14 ( V_23 [ V_33 ] ) ;
V_25 = 0 ;
V_28:
return V_25 ;
}
static int F_15 ( struct V_5 * V_6 , unsigned long V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
if ( ! F_1 ( V_2 , V_7 ) )
return - V_26 ;
V_2 -> V_31 [ V_7 - 1 ] . V_34 = 0xff ;
V_2 -> V_31 [ V_7 - 1 ] . V_32 = 0 ;
return 0 ;
}
static void F_16 ( struct V_5 * V_6 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_37 ;
F_4 ( L_4 ,
V_10 , V_6 , V_2 , V_36 ) ;
if ( V_36 -> V_38 )
return;
for ( V_37 = 0 ; V_37 < V_2 -> V_4 ; V_37 ++ ) {
if ( V_2 -> V_31 [ V_37 ] . V_34 == 0xff && ! V_2 -> V_31 [ V_37 ] . V_32 )
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
static inline struct V_43 T_3 * * F_17 ( struct V_5 * V_6 ,
unsigned long V_18 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
return & V_2 -> V_44 ;
}
static int F_18 ( struct V_45 * V_46 , struct V_5 * V_6 ,
struct V_45 * * V_47 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
int V_25 ;
F_4 ( L_5 , V_10 , V_46 , V_6 , V_2 ) ;
if ( V_2 -> V_48 ) {
switch ( F_19 ( V_46 ) ) {
case F_20 ( V_49 ) :
if ( F_21 ( V_46 , sizeof( struct V_50 ) ) )
goto V_51;
V_46 -> V_52 = F_22 ( F_23 ( V_46 ) )
& ~ V_53 ;
break;
case F_20 ( V_54 ) :
if ( F_21 ( V_46 , sizeof( struct V_55 ) ) )
goto V_51;
V_46 -> V_52 = F_24 ( F_25 ( V_46 ) )
& ~ V_53 ;
break;
default:
V_46 -> V_52 = 0 ;
break;
}
}
if ( F_26 ( V_46 -> V_56 ) == V_6 -> V_13 )
V_46 -> V_52 = F_9 ( V_46 -> V_56 ) ;
else {
struct V_57 V_58 ;
struct V_43 * V_59 = F_27 ( V_2 -> V_44 ) ;
int V_60 = F_28 ( V_46 , V_59 , & V_58 , false ) ;
F_4 ( L_6 , V_60 , V_58 . V_16 ) ;
switch ( V_60 ) {
#ifdef F_29
case V_61 :
case V_62 :
F_30 ( V_46 , V_47 ) ;
return V_63 | V_64 ;
case V_65 :
goto V_51;
#endif
case V_66 :
V_46 -> V_52 = F_9 ( V_58 . V_16 ) ;
break;
default:
if ( V_2 -> V_67 != V_68 )
V_46 -> V_52 = V_2 -> V_67 ;
break;
}
}
V_25 = F_31 ( V_46 , V_2 -> V_15 , V_47 ) ;
if ( V_25 != V_63 ) {
if ( F_32 ( V_25 ) )
F_33 ( V_6 ) ;
return V_25 ;
}
F_34 ( V_6 , V_46 ) ;
V_6 -> V_15 . V_69 ++ ;
return V_63 ;
V_51:
F_35 ( V_46 , V_6 , V_47 ) ;
return V_63 | V_70 ;
}
static struct V_45 * F_36 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_45 * V_46 ;
T_2 V_3 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
V_46 = F_37 ( V_2 -> V_15 ) ;
if ( V_46 == NULL )
return NULL ;
F_38 ( V_6 , V_46 ) ;
F_39 ( V_6 , V_46 ) ;
V_6 -> V_15 . V_69 -- ;
V_3 = V_46 -> V_52 & ( V_2 -> V_4 - 1 ) ;
F_4 ( L_8 , V_46 -> V_52 , V_3 ) ;
switch ( F_19 ( V_46 ) ) {
case F_20 ( V_49 ) :
F_40 ( F_23 ( V_46 ) , V_2 -> V_31 [ V_3 ] . V_34 ,
V_2 -> V_31 [ V_3 ] . V_32 ) ;
break;
case F_20 ( V_54 ) :
F_41 ( F_25 ( V_46 ) , V_2 -> V_31 [ V_3 ] . V_34 ,
V_2 -> V_31 [ V_3 ] . V_32 ) ;
break;
default:
if ( V_2 -> V_31 [ V_3 ] . V_34 != 0xff || V_2 -> V_31 [ V_3 ] . V_32 )
F_42 ( L_9 ,
V_10 , F_43 ( F_19 ( V_46 ) ) ) ;
break;
}
return V_46 ;
}
static struct V_45 * F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
return V_2 -> V_15 -> V_71 -> V_72 ( V_2 -> V_15 ) ;
}
static int F_45 ( struct V_5 * V_6 , struct V_19 * V_21 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_23 [ V_24 + 1 ] ;
int V_25 = - V_26 ;
T_2 V_67 = V_68 ;
T_1 V_4 ;
int V_37 ;
F_4 ( L_10 , V_10 , V_6 , V_2 , V_21 ) ;
if ( ! V_21 )
goto V_28;
V_25 = F_13 ( V_23 , V_24 , V_21 , V_29 ) ;
if ( V_25 < 0 )
goto V_28;
V_25 = - V_26 ;
V_4 = F_46 ( V_23 [ V_73 ] ) ;
if ( F_47 ( V_4 ) != 1 )
goto V_28;
if ( V_23 [ V_74 ] )
V_67 = F_46 ( V_23 [ V_74 ] ) ;
if ( V_4 <= V_75 )
V_2 -> V_31 = V_2 -> V_76 ;
else
V_2 -> V_31 = F_48 ( V_4 , sizeof( * V_2 -> V_31 ) , V_77 ) ;
if ( ! V_2 -> V_31 ) {
V_25 = - V_78 ;
goto V_28;
}
for ( V_37 = 0 ; V_37 < V_4 ; V_37 ++ ) {
V_2 -> V_31 [ V_37 ] . V_34 = 0xff ;
V_2 -> V_31 [ V_37 ] . V_32 = 0 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_48 = F_49 ( V_23 [ V_79 ] ) ;
V_2 -> V_15 = F_5 ( V_6 -> V_11 , & V_12 , V_6 -> V_13 ) ;
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = & V_14 ;
F_4 ( L_11 , V_10 , V_2 -> V_15 ) ;
V_25 = 0 ;
V_28:
return V_25 ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_51 ( V_2 -> V_15 ) ;
V_6 -> V_80 . V_81 = 0 ;
V_6 -> V_15 . V_69 = 0 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_53 ( & V_2 -> V_44 ) ;
F_54 ( V_2 -> V_15 ) ;
if ( V_2 -> V_31 != V_2 -> V_76 )
F_55 ( V_2 -> V_31 ) ;
}
static int F_56 ( struct V_5 * V_6 , unsigned long V_18 ,
struct V_45 * V_46 , struct V_82 * V_83 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_84 = NULL ;
F_4 ( L_12 , V_10 , V_6 , V_2 , V_18 ) ;
if ( ! F_1 ( V_2 , V_18 ) )
return - V_26 ;
V_83 -> V_85 = F_57 ( F_26 ( V_6 -> V_13 ) , V_18 - 1 ) ;
V_83 -> V_86 = V_2 -> V_15 -> V_13 ;
V_84 = F_58 ( V_46 , V_22 ) ;
if ( V_84 == NULL )
goto V_87;
if ( F_59 ( V_46 , V_33 , V_2 -> V_31 [ V_18 - 1 ] . V_34 ) ||
F_59 ( V_46 , V_30 , V_2 -> V_31 [ V_18 - 1 ] . V_32 ) )
goto V_87;
return F_60 ( V_46 , V_84 ) ;
V_87:
F_61 ( V_46 , V_84 ) ;
return - V_88 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_84 = NULL ;
V_84 = F_58 ( V_46 , V_22 ) ;
if ( V_84 == NULL )
goto V_87;
if ( F_63 ( V_46 , V_73 , V_2 -> V_4 ) )
goto V_87;
if ( V_2 -> V_67 != V_68 &&
F_63 ( V_46 , V_74 , V_2 -> V_67 ) )
goto V_87;
if ( V_2 -> V_48 &&
F_64 ( V_46 , V_79 ) )
goto V_87;
return F_60 ( V_46 , V_84 ) ;
V_87:
F_61 ( V_46 , V_84 ) ;
return - V_88 ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_89 ) ;
}
static void T_5 F_67 ( void )
{
F_68 ( & V_89 ) ;
}
