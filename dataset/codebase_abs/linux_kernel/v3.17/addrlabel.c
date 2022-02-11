static inline
struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( & V_3 -> V_4 ) ;
}
static inline void F_3 ( struct V_2 * V_5 )
{
#ifdef F_4
F_5 ( V_5 -> V_4 ) ;
#endif
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_3 ( F_8 ( V_7 , struct V_2 , V_8 ) ) ;
}
static bool F_9 ( struct V_2 * V_5 )
{
return F_10 ( & V_5 -> V_9 ) ;
}
static inline void F_11 ( struct V_2 * V_5 )
{
if ( F_12 ( & V_5 -> V_9 ) )
F_13 ( & V_5 -> V_8 , F_7 ) ;
}
static bool F_14 ( struct V_1 * V_1 ,
const struct V_2 * V_5 ,
const struct V_10 * V_11 ,
int V_12 , int V_13 )
{
if ( ! F_15 ( F_1 ( V_5 ) , V_1 ) )
return false ;
if ( V_5 -> V_13 && V_5 -> V_13 != V_13 )
return false ;
if ( V_5 -> V_12 && V_5 -> V_12 != V_12 )
return false ;
if ( ! F_16 ( V_11 , & V_5 -> V_14 , V_5 -> V_15 ) )
return false ;
return true ;
}
static struct V_2 * F_17 ( struct V_1 * V_1 ,
const struct V_10 * V_11 ,
int type , int V_13 )
{
struct V_2 * V_5 ;
F_18 (p, &ip6addrlbl_table.head, list) {
if ( F_14 ( V_1 , V_5 , V_11 , type , V_13 ) )
return V_5 ;
}
return NULL ;
}
T_1 F_19 ( struct V_1 * V_1 ,
const struct V_10 * V_11 , int type , int V_13 )
{
T_1 V_16 ;
struct V_2 * V_5 ;
type &= V_17 | V_18 | V_19 ;
F_20 () ;
V_5 = F_17 ( V_1 , V_11 , type , V_13 ) ;
V_16 = V_5 ? V_5 -> V_16 : V_20 ;
F_21 () ;
F_22 ( V_21 L_1 ,
V_22 , V_11 , type , V_13 , V_16 ) ;
return V_16 ;
}
static struct V_2 * F_23 ( struct V_1 * V_1 ,
const struct V_10 * V_14 ,
int V_15 , int V_13 ,
T_1 V_16 )
{
struct V_2 * V_23 ;
int V_12 ;
F_22 ( V_21 L_2 ,
V_22 , V_14 , V_15 , V_13 , ( unsigned int ) V_16 ) ;
V_12 = F_24 ( V_14 ) & ( V_17 | V_18 | V_19 ) ;
switch ( V_12 ) {
case V_17 :
if ( V_15 > 96 )
return F_25 ( - V_24 ) ;
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
V_23 = F_26 ( sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 )
return F_25 ( - V_26 ) ;
F_27 ( & V_23 -> V_14 , V_14 , V_15 ) ;
V_23 -> V_15 = V_15 ;
V_23 -> V_13 = V_13 ;
V_23 -> V_12 = V_12 ;
V_23 -> V_16 = V_16 ;
F_28 ( & V_23 -> V_27 ) ;
#ifdef F_4
V_23 -> V_4 = F_29 ( V_1 ) ;
#endif
F_30 ( & V_23 -> V_9 , 1 ) ;
return V_23 ;
}
static int F_31 ( struct V_2 * V_23 , int V_28 )
{
struct V_29 * V_30 ;
struct V_2 * V_31 = NULL , * V_5 = NULL ;
int V_32 = 0 ;
F_22 ( V_21 L_3 , V_22 , V_23 ,
V_28 ) ;
F_32 (p, n, &ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_23 -> V_15 &&
F_15 ( F_1 ( V_5 ) , F_1 ( V_23 ) ) &&
V_5 -> V_13 == V_23 -> V_13 &&
F_33 ( & V_5 -> V_14 , & V_23 -> V_14 ) ) {
if ( ! V_28 ) {
V_32 = - V_33 ;
goto V_34;
}
F_34 ( & V_5 -> V_27 , & V_23 -> V_27 ) ;
F_11 ( V_5 ) ;
goto V_34;
} else if ( ( V_5 -> V_15 == V_23 -> V_15 && ! V_5 -> V_13 ) ||
( V_5 -> V_15 < V_23 -> V_15 ) ) {
F_35 ( & V_23 -> V_27 , & V_5 -> V_27 ) ;
goto V_34;
}
V_31 = V_5 ;
}
if ( V_31 )
F_36 ( & V_23 -> V_27 , & V_31 -> V_27 ) ;
else
F_37 ( & V_23 -> V_27 , & V_35 . V_36 ) ;
V_34:
if ( ! V_32 )
V_35 . V_37 ++ ;
return V_32 ;
}
static int F_38 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 , T_1 V_16 , int V_28 )
{
struct V_2 * V_23 ;
int V_32 = 0 ;
F_22 ( V_21 L_4 ,
V_22 , V_14 , V_15 , V_13 , ( unsigned int ) V_16 ,
V_28 ) ;
V_23 = F_23 ( V_1 , V_14 , V_15 , V_13 , V_16 ) ;
if ( F_39 ( V_23 ) )
return F_40 ( V_23 ) ;
F_41 ( & V_35 . V_38 ) ;
V_32 = F_31 ( V_23 , V_28 ) ;
F_42 ( & V_35 . V_38 ) ;
if ( V_32 )
F_3 ( V_23 ) ;
return V_32 ;
}
static int F_43 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_2 * V_5 = NULL ;
struct V_29 * V_30 ;
int V_32 = - V_39 ;
F_22 ( V_21 L_5 ,
V_22 , V_14 , V_15 , V_13 ) ;
F_32 (p, n, &ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_15 &&
F_15 ( F_1 ( V_5 ) , V_1 ) &&
V_5 -> V_13 == V_13 &&
F_33 ( & V_5 -> V_14 , V_14 ) ) {
F_44 ( & V_5 -> V_27 ) ;
F_11 ( V_5 ) ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
static int F_45 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_10 V_40 ;
int V_32 ;
F_22 ( V_21 L_5 ,
V_22 , V_14 , V_15 , V_13 ) ;
F_27 ( & V_40 , V_14 , V_15 ) ;
F_41 ( & V_35 . V_38 ) ;
V_32 = F_43 ( V_1 , & V_40 , V_15 , V_13 ) ;
F_42 ( & V_35 . V_38 ) ;
return V_32 ;
}
static int T_2 F_46 ( struct V_1 * V_1 )
{
int V_41 = 0 ;
int V_42 ;
F_22 ( V_21 L_6 , V_22 ) ;
for ( V_42 = 0 ; V_42 < F_47 ( V_43 ) ; V_42 ++ ) {
int V_32 = F_38 ( V_1 ,
V_43 [ V_42 ] . V_14 ,
V_43 [ V_42 ] . V_15 ,
0 ,
V_43 [ V_42 ] . V_16 , 0 ) ;
if ( V_32 && ( ! V_41 || V_41 != - V_26 ) )
V_41 = V_32 ;
}
return V_41 ;
}
static void T_3 F_48 ( struct V_1 * V_1 )
{
struct V_2 * V_5 = NULL ;
struct V_29 * V_30 ;
F_41 ( & V_35 . V_38 ) ;
F_32 (p, n, &ip6addrlbl_table.head, list) {
if ( F_15 ( F_1 ( V_5 ) , V_1 ) ) {
F_44 ( & V_5 -> V_27 ) ;
F_11 ( V_5 ) ;
}
}
F_42 ( & V_35 . V_38 ) ;
}
int T_4 F_49 ( void )
{
F_50 ( & V_35 . V_38 ) ;
return F_51 ( & V_44 ) ;
}
void F_52 ( void )
{
F_53 ( & V_44 ) ;
}
static int F_54 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_1 * V_1 = F_55 ( V_46 -> V_49 ) ;
struct V_50 * V_51 ;
struct V_52 * V_53 [ V_54 + 1 ] ;
struct V_10 * V_55 ;
T_1 V_16 ;
int V_41 = 0 ;
V_41 = F_56 ( V_48 , sizeof( * V_51 ) , V_53 , V_54 , V_56 ) ;
if ( V_41 < 0 )
return V_41 ;
V_51 = F_57 ( V_48 ) ;
if ( V_51 -> V_57 != V_58 ||
V_51 -> V_59 > 128 )
return - V_24 ;
if ( ! V_53 [ V_60 ] )
return - V_24 ;
V_55 = F_58 ( V_53 [ V_60 ] ) ;
if ( ! V_53 [ V_61 ] )
return - V_24 ;
V_16 = F_59 ( V_53 [ V_61 ] ) ;
if ( V_16 == V_20 )
return - V_24 ;
switch ( V_48 -> V_62 ) {
case V_63 :
if ( V_51 -> V_64 &&
! F_60 ( V_1 , V_51 -> V_64 ) )
return - V_24 ;
V_41 = F_38 ( V_1 , V_55 , V_51 -> V_59 ,
V_51 -> V_64 , V_16 ,
V_48 -> V_65 & V_66 ) ;
break;
case V_67 :
V_41 = F_45 ( V_1 , V_55 , V_51 -> V_59 ,
V_51 -> V_64 ) ;
break;
default:
V_41 = - V_68 ;
}
return V_41 ;
}
static void F_61 ( struct V_47 * V_48 ,
int V_15 , int V_13 , T_1 V_69 )
{
struct V_50 * V_51 = F_57 ( V_48 ) ;
V_51 -> V_57 = V_58 ;
V_51 -> V_59 = V_15 ;
V_51 -> V_70 = 0 ;
V_51 -> V_64 = V_13 ;
V_51 -> V_71 = V_69 ;
}
static int F_62 ( struct V_45 * V_46 ,
struct V_2 * V_5 ,
T_1 V_69 ,
T_1 V_72 , T_1 V_37 , int V_73 ,
unsigned int V_74 )
{
struct V_47 * V_48 = F_63 ( V_46 , V_72 , V_37 , V_73 ,
sizeof( struct V_50 ) , V_74 ) ;
if ( ! V_48 )
return - V_75 ;
F_61 ( V_48 , V_5 -> V_15 , V_5 -> V_13 , V_69 ) ;
if ( F_64 ( V_46 , V_60 , 16 , & V_5 -> V_14 ) < 0 ||
F_65 ( V_46 , V_61 , V_5 -> V_16 ) < 0 ) {
F_66 ( V_46 , V_48 ) ;
return - V_75 ;
}
return F_67 ( V_46 , V_48 ) ;
}
static int F_68 ( struct V_45 * V_46 , struct V_76 * V_77 )
{
struct V_1 * V_1 = F_55 ( V_46 -> V_49 ) ;
struct V_2 * V_5 ;
int V_78 = 0 , V_79 = V_77 -> args [ 0 ] ;
int V_41 ;
F_20 () ;
F_18 (p, &ip6addrlbl_table.head, list) {
if ( V_78 >= V_79 &&
F_15 ( F_1 ( V_5 ) , V_1 ) ) {
V_41 = F_62 ( V_46 , V_5 ,
V_35 . V_37 ,
F_69 ( V_77 -> V_46 ) . V_72 ,
V_77 -> V_48 -> V_80 ,
V_63 ,
V_81 ) ;
if ( V_41 <= 0 )
break;
}
V_78 ++ ;
}
F_21 () ;
V_77 -> args [ 0 ] = V_78 ;
return V_46 -> V_82 ;
}
static inline int F_70 ( void )
{
return F_71 ( sizeof( struct V_50 ) )
+ F_72 ( 16 )
+ F_72 ( 4 ) ;
}
static int F_73 ( struct V_45 * V_83 , struct V_47 * V_48 )
{
struct V_1 * V_1 = F_55 ( V_83 -> V_49 ) ;
struct V_50 * V_51 ;
struct V_52 * V_53 [ V_54 + 1 ] ;
struct V_10 * V_11 ;
T_1 V_69 ;
int V_41 = 0 ;
struct V_2 * V_5 ;
struct V_45 * V_46 ;
V_41 = F_56 ( V_48 , sizeof( * V_51 ) , V_53 , V_54 , V_56 ) ;
if ( V_41 < 0 )
return V_41 ;
V_51 = F_57 ( V_48 ) ;
if ( V_51 -> V_57 != V_58 ||
V_51 -> V_59 != 128 )
return - V_24 ;
if ( V_51 -> V_64 &&
! F_60 ( V_1 , V_51 -> V_64 ) )
return - V_24 ;
if ( ! V_53 [ V_60 ] )
return - V_24 ;
V_11 = F_58 ( V_53 [ V_60 ] ) ;
F_20 () ;
V_5 = F_17 ( V_1 , V_11 , F_24 ( V_11 ) , V_51 -> V_64 ) ;
if ( V_5 && F_9 ( V_5 ) )
V_5 = NULL ;
V_69 = V_35 . V_37 ;
F_21 () ;
if ( ! V_5 ) {
V_41 = - V_39 ;
goto V_34;
}
V_46 = F_74 ( F_70 () , V_25 ) ;
if ( ! V_46 ) {
F_11 ( V_5 ) ;
return - V_84 ;
}
V_41 = F_62 ( V_46 , V_5 , V_69 ,
F_69 ( V_83 ) . V_72 , V_48 -> V_80 ,
V_63 , 0 ) ;
F_11 ( V_5 ) ;
if ( V_41 < 0 ) {
F_75 ( V_41 == - V_75 ) ;
F_76 ( V_46 ) ;
goto V_34;
}
V_41 = F_77 ( V_46 , V_1 , F_69 ( V_83 ) . V_72 ) ;
V_34:
return V_41 ;
}
void T_4 F_78 ( void )
{
F_79 ( V_85 , V_63 , F_54 ,
NULL , NULL ) ;
F_79 ( V_85 , V_67 , F_54 ,
NULL , NULL ) ;
F_79 ( V_85 , V_86 , F_73 ,
F_68 , NULL ) ;
}
