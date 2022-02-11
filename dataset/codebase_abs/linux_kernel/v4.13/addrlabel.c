static inline
struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ) ;
}
static inline void F_3 ( struct V_2 * V_5 )
{
F_4 ( V_5 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
F_3 ( F_6 ( V_7 , struct V_2 , V_8 ) ) ;
}
static bool F_7 ( struct V_2 * V_5 )
{
return F_8 ( & V_5 -> V_9 ) ;
}
static inline void F_9 ( struct V_2 * V_5 )
{
if ( F_10 ( & V_5 -> V_9 ) )
F_11 ( & V_5 -> V_8 , F_5 ) ;
}
static bool F_12 ( struct V_1 * V_1 ,
const struct V_2 * V_5 ,
const struct V_10 * V_11 ,
int V_12 , int V_13 )
{
if ( ! F_13 ( F_1 ( V_5 ) , V_1 ) )
return false ;
if ( V_5 -> V_13 && V_5 -> V_13 != V_13 )
return false ;
if ( V_5 -> V_12 && V_5 -> V_12 != V_12 )
return false ;
if ( ! F_14 ( V_11 , & V_5 -> V_14 , V_5 -> V_15 ) )
return false ;
return true ;
}
static struct V_2 * F_15 ( struct V_1 * V_1 ,
const struct V_10 * V_11 ,
int type , int V_13 )
{
struct V_2 * V_5 ;
F_16 (p, &ip6addrlbl_table.head, list) {
if ( F_12 ( V_1 , V_5 , V_11 , type , V_13 ) )
return V_5 ;
}
return NULL ;
}
T_1 F_17 ( struct V_1 * V_1 ,
const struct V_10 * V_11 , int type , int V_13 )
{
T_1 V_16 ;
struct V_2 * V_5 ;
type &= V_17 | V_18 | V_19 ;
F_18 () ;
V_5 = F_15 ( V_1 , V_11 , type , V_13 ) ;
V_16 = V_5 ? V_5 -> V_16 : V_20 ;
F_19 () ;
F_20 ( V_21 L_1 ,
V_22 , V_11 , type , V_13 , V_16 ) ;
return V_16 ;
}
static struct V_2 * F_21 ( struct V_1 * V_1 ,
const struct V_10 * V_14 ,
int V_15 , int V_13 ,
T_1 V_16 )
{
struct V_2 * V_23 ;
int V_12 ;
F_20 ( V_21 L_2 ,
V_22 , V_14 , V_15 , V_13 , ( unsigned int ) V_16 ) ;
V_12 = F_22 ( V_14 ) & ( V_17 | V_18 | V_19 ) ;
switch ( V_12 ) {
case V_17 :
if ( V_15 > 96 )
return F_23 ( - V_24 ) ;
if ( V_15 < 96 )
V_12 = 0 ;
break;
case V_18 :
if ( V_15 != 96 )
V_12 = 0 ;
break;
case V_19 :
if ( V_15 != 128 )
V_12 = 0 ;
break;
}
V_23 = F_24 ( sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 )
return F_23 ( - V_26 ) ;
F_25 ( & V_23 -> V_14 , V_14 , V_15 ) ;
V_23 -> V_15 = V_15 ;
V_23 -> V_13 = V_13 ;
V_23 -> V_12 = V_12 ;
V_23 -> V_16 = V_16 ;
F_26 ( & V_23 -> V_27 ) ;
F_27 ( & V_23 -> V_4 , V_1 ) ;
F_28 ( & V_23 -> V_9 , 1 ) ;
return V_23 ;
}
static int F_29 ( struct V_2 * V_23 , int V_28 )
{
struct V_29 * V_30 ;
struct V_2 * V_31 = NULL , * V_5 = NULL ;
int V_32 = 0 ;
F_20 ( V_21 L_3 , V_22 , V_23 ,
V_28 ) ;
F_30 (p, n, &ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_23 -> V_15 &&
F_13 ( F_1 ( V_5 ) , F_1 ( V_23 ) ) &&
V_5 -> V_13 == V_23 -> V_13 &&
F_31 ( & V_5 -> V_14 , & V_23 -> V_14 ) ) {
if ( ! V_28 ) {
V_32 = - V_33 ;
goto V_34;
}
F_32 ( & V_5 -> V_27 , & V_23 -> V_27 ) ;
F_9 ( V_5 ) ;
goto V_34;
} else if ( ( V_5 -> V_15 == V_23 -> V_15 && ! V_5 -> V_13 ) ||
( V_5 -> V_15 < V_23 -> V_15 ) ) {
F_33 ( & V_23 -> V_27 , & V_5 -> V_27 ) ;
goto V_34;
}
V_31 = V_5 ;
}
if ( V_31 )
F_34 ( & V_23 -> V_27 , & V_31 -> V_27 ) ;
else
F_35 ( & V_23 -> V_27 , & V_35 . V_36 ) ;
V_34:
if ( ! V_32 )
V_35 . V_37 ++ ;
return V_32 ;
}
static int F_36 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 , T_1 V_16 , int V_28 )
{
struct V_2 * V_23 ;
int V_32 = 0 ;
F_20 ( V_21 L_4 ,
V_22 , V_14 , V_15 , V_13 , ( unsigned int ) V_16 ,
V_28 ) ;
V_23 = F_21 ( V_1 , V_14 , V_15 , V_13 , V_16 ) ;
if ( F_37 ( V_23 ) )
return F_38 ( V_23 ) ;
F_39 ( & V_35 . V_38 ) ;
V_32 = F_29 ( V_23 , V_28 ) ;
F_40 ( & V_35 . V_38 ) ;
if ( V_32 )
F_3 ( V_23 ) ;
return V_32 ;
}
static int F_41 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_2 * V_5 = NULL ;
struct V_29 * V_30 ;
int V_32 = - V_39 ;
F_20 ( V_21 L_5 ,
V_22 , V_14 , V_15 , V_13 ) ;
F_30 (p, n, &ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_15 &&
F_13 ( F_1 ( V_5 ) , V_1 ) &&
V_5 -> V_13 == V_13 &&
F_31 ( & V_5 -> V_14 , V_14 ) ) {
F_42 ( & V_5 -> V_27 ) ;
F_9 ( V_5 ) ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
static int F_43 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_10 V_40 ;
int V_32 ;
F_20 ( V_21 L_5 ,
V_22 , V_14 , V_15 , V_13 ) ;
F_25 ( & V_40 , V_14 , V_15 ) ;
F_39 ( & V_35 . V_38 ) ;
V_32 = F_41 ( V_1 , & V_40 , V_15 , V_13 ) ;
F_40 ( & V_35 . V_38 ) ;
return V_32 ;
}
static int T_2 F_44 ( struct V_1 * V_1 )
{
int V_41 = 0 ;
int V_42 ;
F_20 ( V_21 L_6 , V_22 ) ;
for ( V_42 = 0 ; V_42 < F_45 ( V_43 ) ; V_42 ++ ) {
int V_32 = F_36 ( V_1 ,
V_43 [ V_42 ] . V_14 ,
V_43 [ V_42 ] . V_15 ,
0 ,
V_43 [ V_42 ] . V_16 , 0 ) ;
if ( V_32 && ( ! V_41 || V_41 != - V_26 ) )
V_41 = V_32 ;
}
return V_41 ;
}
static void T_3 F_46 ( struct V_1 * V_1 )
{
struct V_2 * V_5 = NULL ;
struct V_29 * V_30 ;
F_39 ( & V_35 . V_38 ) ;
F_30 (p, n, &ip6addrlbl_table.head, list) {
if ( F_13 ( F_1 ( V_5 ) , V_1 ) ) {
F_42 ( & V_5 -> V_27 ) ;
F_9 ( V_5 ) ;
}
}
F_40 ( & V_35 . V_38 ) ;
}
int T_4 F_47 ( void )
{
F_48 ( & V_35 . V_38 ) ;
return F_49 ( & V_44 ) ;
}
void F_50 ( void )
{
F_51 ( & V_44 ) ;
}
static int F_52 ( struct V_45 * V_46 , struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_53 ( V_46 -> V_51 ) ;
struct V_52 * V_53 ;
struct V_54 * V_55 [ V_56 + 1 ] ;
struct V_10 * V_57 ;
T_1 V_16 ;
int V_41 = 0 ;
V_41 = F_54 ( V_48 , sizeof( * V_53 ) , V_55 , V_56 , V_58 ,
V_50 ) ;
if ( V_41 < 0 )
return V_41 ;
V_53 = F_55 ( V_48 ) ;
if ( V_53 -> V_59 != V_60 ||
V_53 -> V_61 > 128 )
return - V_24 ;
if ( ! V_55 [ V_62 ] )
return - V_24 ;
V_57 = F_56 ( V_55 [ V_62 ] ) ;
if ( ! V_55 [ V_63 ] )
return - V_24 ;
V_16 = F_57 ( V_55 [ V_63 ] ) ;
if ( V_16 == V_20 )
return - V_24 ;
switch ( V_48 -> V_64 ) {
case V_65 :
if ( V_53 -> V_66 &&
! F_58 ( V_1 , V_53 -> V_66 ) )
return - V_24 ;
V_41 = F_36 ( V_1 , V_57 , V_53 -> V_61 ,
V_53 -> V_66 , V_16 ,
V_48 -> V_67 & V_68 ) ;
break;
case V_69 :
V_41 = F_43 ( V_1 , V_57 , V_53 -> V_61 ,
V_53 -> V_66 ) ;
break;
default:
V_41 = - V_70 ;
}
return V_41 ;
}
static void F_59 ( struct V_47 * V_48 ,
int V_15 , int V_13 , T_1 V_71 )
{
struct V_52 * V_53 = F_55 ( V_48 ) ;
V_53 -> V_59 = V_60 ;
V_53 -> V_61 = V_15 ;
V_53 -> V_72 = 0 ;
V_53 -> V_66 = V_13 ;
V_53 -> V_73 = V_71 ;
}
static int F_60 ( struct V_45 * V_46 ,
struct V_2 * V_5 ,
T_1 V_71 ,
T_1 V_74 , T_1 V_37 , int V_75 ,
unsigned int V_76 )
{
struct V_47 * V_48 = F_61 ( V_46 , V_74 , V_37 , V_75 ,
sizeof( struct V_52 ) , V_76 ) ;
if ( ! V_48 )
return - V_77 ;
F_59 ( V_48 , V_5 -> V_15 , V_5 -> V_13 , V_71 ) ;
if ( F_62 ( V_46 , V_62 , & V_5 -> V_14 ) < 0 ||
F_63 ( V_46 , V_63 , V_5 -> V_16 ) < 0 ) {
F_64 ( V_46 , V_48 ) ;
return - V_77 ;
}
F_65 ( V_46 , V_48 ) ;
return 0 ;
}
static int F_66 ( struct V_45 * V_46 , struct V_78 * V_79 )
{
struct V_1 * V_1 = F_53 ( V_46 -> V_51 ) ;
struct V_2 * V_5 ;
int V_80 = 0 , V_81 = V_79 -> args [ 0 ] ;
int V_41 ;
F_18 () ;
F_16 (p, &ip6addrlbl_table.head, list) {
if ( V_80 >= V_81 &&
F_13 ( F_1 ( V_5 ) , V_1 ) ) {
V_41 = F_60 ( V_46 , V_5 ,
V_35 . V_37 ,
F_67 ( V_79 -> V_46 ) . V_74 ,
V_79 -> V_48 -> V_82 ,
V_65 ,
V_83 ) ;
if ( V_41 < 0 )
break;
}
V_80 ++ ;
}
F_19 () ;
V_79 -> args [ 0 ] = V_80 ;
return V_46 -> V_84 ;
}
static inline int F_68 ( void )
{
return F_69 ( sizeof( struct V_52 ) )
+ F_70 ( 16 )
+ F_70 ( 4 ) ;
}
static int F_71 ( struct V_45 * V_85 , struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_53 ( V_85 -> V_51 ) ;
struct V_52 * V_53 ;
struct V_54 * V_55 [ V_56 + 1 ] ;
struct V_10 * V_11 ;
T_1 V_71 ;
int V_41 = 0 ;
struct V_2 * V_5 ;
struct V_45 * V_46 ;
V_41 = F_54 ( V_48 , sizeof( * V_53 ) , V_55 , V_56 , V_58 ,
V_50 ) ;
if ( V_41 < 0 )
return V_41 ;
V_53 = F_55 ( V_48 ) ;
if ( V_53 -> V_59 != V_60 ||
V_53 -> V_61 != 128 )
return - V_24 ;
if ( V_53 -> V_66 &&
! F_58 ( V_1 , V_53 -> V_66 ) )
return - V_24 ;
if ( ! V_55 [ V_62 ] )
return - V_24 ;
V_11 = F_56 ( V_55 [ V_62 ] ) ;
F_18 () ;
V_5 = F_15 ( V_1 , V_11 , F_22 ( V_11 ) , V_53 -> V_66 ) ;
if ( V_5 && ! F_7 ( V_5 ) )
V_5 = NULL ;
V_71 = V_35 . V_37 ;
F_19 () ;
if ( ! V_5 ) {
V_41 = - V_39 ;
goto V_34;
}
V_46 = F_72 ( F_68 () , V_25 ) ;
if ( ! V_46 ) {
F_9 ( V_5 ) ;
return - V_86 ;
}
V_41 = F_60 ( V_46 , V_5 , V_71 ,
F_67 ( V_85 ) . V_74 , V_48 -> V_82 ,
V_65 , 0 ) ;
F_9 ( V_5 ) ;
if ( V_41 < 0 ) {
F_73 ( V_41 == - V_77 ) ;
F_74 ( V_46 ) ;
goto V_34;
}
V_41 = F_75 ( V_46 , V_1 , F_67 ( V_85 ) . V_74 ) ;
V_34:
return V_41 ;
}
void T_4 F_76 ( void )
{
F_77 ( V_87 , V_65 , F_52 ,
NULL , NULL ) ;
F_77 ( V_87 , V_69 , F_52 ,
NULL , NULL ) ;
F_77 ( V_87 , V_88 , F_71 ,
F_66 , NULL ) ;
}
