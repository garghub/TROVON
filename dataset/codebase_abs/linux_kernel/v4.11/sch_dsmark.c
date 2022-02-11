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
int V_49 = F_19 ( V_46 ) ;
switch ( F_20 ( V_46 ) ) {
case F_21 ( V_50 ) :
V_49 += sizeof( struct V_51 ) ;
if ( ! F_22 ( V_46 , V_49 ) ||
F_23 ( V_46 , V_49 ) )
goto V_52;
V_46 -> V_53 = F_24 ( F_25 ( V_46 ) )
& ~ V_54 ;
break;
case F_21 ( V_55 ) :
V_49 += sizeof( struct V_56 ) ;
if ( ! F_22 ( V_46 , V_49 ) ||
F_23 ( V_46 , V_49 ) )
goto V_52;
V_46 -> V_53 = F_26 ( F_27 ( V_46 ) )
& ~ V_54 ;
break;
default:
V_46 -> V_53 = 0 ;
break;
}
}
if ( F_28 ( V_46 -> V_57 ) == V_6 -> V_13 )
V_46 -> V_53 = F_9 ( V_46 -> V_57 ) ;
else {
struct V_58 V_59 ;
struct V_43 * V_60 = F_29 ( V_2 -> V_44 ) ;
int V_61 = F_30 ( V_46 , V_60 , & V_59 , false ) ;
F_4 ( L_6 , V_61 , V_59 . V_16 ) ;
switch ( V_61 ) {
#ifdef F_31
case V_62 :
case V_63 :
F_32 ( V_46 , V_47 ) ;
return V_64 | V_65 ;
case V_66 :
goto V_52;
#endif
case V_67 :
V_46 -> V_53 = F_9 ( V_59 . V_16 ) ;
break;
default:
if ( V_2 -> V_68 != V_69 )
V_46 -> V_53 = V_2 -> V_68 ;
break;
}
}
V_25 = F_33 ( V_46 , V_2 -> V_15 , V_47 ) ;
if ( V_25 != V_64 ) {
if ( F_34 ( V_25 ) )
F_35 ( V_6 ) ;
return V_25 ;
}
F_36 ( V_6 , V_46 ) ;
V_6 -> V_15 . V_70 ++ ;
return V_64 ;
V_52:
F_37 ( V_46 , V_6 , V_47 ) ;
return V_64 | V_71 ;
}
static struct V_45 * F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_45 * V_46 ;
T_2 V_3 ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
V_46 = F_39 ( V_2 -> V_15 ) ;
if ( V_46 == NULL )
return NULL ;
F_40 ( V_6 , V_46 ) ;
F_41 ( V_6 , V_46 ) ;
V_6 -> V_15 . V_70 -- ;
V_3 = V_46 -> V_53 & ( V_2 -> V_4 - 1 ) ;
F_4 ( L_8 , V_46 -> V_53 , V_3 ) ;
switch ( F_20 ( V_46 ) ) {
case F_21 ( V_50 ) :
F_42 ( F_25 ( V_46 ) , V_2 -> V_31 [ V_3 ] . V_34 ,
V_2 -> V_31 [ V_3 ] . V_32 ) ;
break;
case F_21 ( V_55 ) :
F_43 ( F_27 ( V_46 ) , V_2 -> V_31 [ V_3 ] . V_34 ,
V_2 -> V_31 [ V_3 ] . V_32 ) ;
break;
default:
if ( V_2 -> V_31 [ V_3 ] . V_34 != 0xff || V_2 -> V_31 [ V_3 ] . V_32 )
F_44 ( L_9 ,
V_10 , F_45 ( F_20 ( V_46 ) ) ) ;
break;
}
return V_46 ;
}
static struct V_45 * F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
return V_2 -> V_15 -> V_72 -> V_73 ( V_2 -> V_15 ) ;
}
static int F_47 ( struct V_5 * V_6 , struct V_19 * V_21 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_23 [ V_24 + 1 ] ;
int V_25 = - V_26 ;
T_2 V_68 = V_69 ;
T_1 V_4 ;
int V_37 ;
F_4 ( L_10 , V_10 , V_6 , V_2 , V_21 ) ;
if ( ! V_21 )
goto V_28;
V_25 = F_13 ( V_23 , V_24 , V_21 , V_29 ) ;
if ( V_25 < 0 )
goto V_28;
V_25 = - V_26 ;
V_4 = F_48 ( V_23 [ V_74 ] ) ;
if ( F_49 ( V_4 ) != 1 )
goto V_28;
if ( V_23 [ V_75 ] )
V_68 = F_48 ( V_23 [ V_75 ] ) ;
if ( V_4 <= V_76 )
V_2 -> V_31 = V_2 -> V_77 ;
else
V_2 -> V_31 = F_50 ( V_4 , sizeof( * V_2 -> V_31 ) , V_78 ) ;
if ( ! V_2 -> V_31 ) {
V_25 = - V_79 ;
goto V_28;
}
for ( V_37 = 0 ; V_37 < V_4 ; V_37 ++ ) {
V_2 -> V_31 [ V_37 ] . V_34 = 0xff ;
V_2 -> V_31 [ V_37 ] . V_32 = 0 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_68 = V_68 ;
V_2 -> V_48 = F_51 ( V_23 [ V_80 ] ) ;
V_2 -> V_15 = F_5 ( V_6 -> V_11 , & V_12 , V_6 -> V_13 ) ;
if ( V_2 -> V_15 == NULL )
V_2 -> V_15 = & V_14 ;
F_4 ( L_11 , V_10 , V_2 -> V_15 ) ;
V_25 = 0 ;
V_28:
return V_25 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_53 ( V_2 -> V_15 ) ;
V_6 -> V_81 . V_82 = 0 ;
V_6 -> V_15 . V_70 = 0 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
F_4 ( L_7 , V_10 , V_6 , V_2 ) ;
F_55 ( & V_2 -> V_44 ) ;
F_56 ( V_2 -> V_15 ) ;
if ( V_2 -> V_31 != V_2 -> V_77 )
F_57 ( V_2 -> V_31 ) ;
}
static int F_58 ( struct V_5 * V_6 , unsigned long V_18 ,
struct V_45 * V_46 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_85 = NULL ;
F_4 ( L_12 , V_10 , V_6 , V_2 , V_18 ) ;
if ( ! F_1 ( V_2 , V_18 ) )
return - V_26 ;
V_84 -> V_86 = F_59 ( F_28 ( V_6 -> V_13 ) , V_18 - 1 ) ;
V_84 -> V_87 = V_2 -> V_15 -> V_13 ;
V_85 = F_60 ( V_46 , V_22 ) ;
if ( V_85 == NULL )
goto V_88;
if ( F_61 ( V_46 , V_33 , V_2 -> V_31 [ V_18 - 1 ] . V_34 ) ||
F_61 ( V_46 , V_30 , V_2 -> V_31 [ V_18 - 1 ] . V_32 ) )
goto V_88;
return F_62 ( V_46 , V_85 ) ;
V_88:
F_63 ( V_46 , V_85 ) ;
return - V_89 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_3 ( V_6 ) ;
struct V_19 * V_85 = NULL ;
V_85 = F_60 ( V_46 , V_22 ) ;
if ( V_85 == NULL )
goto V_88;
if ( F_65 ( V_46 , V_74 , V_2 -> V_4 ) )
goto V_88;
if ( V_2 -> V_68 != V_69 &&
F_65 ( V_46 , V_75 , V_2 -> V_68 ) )
goto V_88;
if ( V_2 -> V_48 &&
F_66 ( V_46 , V_80 ) )
goto V_88;
return F_62 ( V_46 , V_85 ) ;
V_88:
F_63 ( V_46 , V_85 ) ;
return - V_89 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_90 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_90 ) ;
}
