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
int V_29 = 0 ;
F_22 ( V_21 L_3 ,
V_22 ,
V_23 , V_28 ) ;
if ( F_32 ( & V_30 . V_31 ) ) {
F_33 ( & V_23 -> V_27 , & V_30 . V_31 ) ;
} else {
struct V_32 * V_33 ;
struct V_2 * V_5 = NULL ;
F_34 (p, n,
&ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_23 -> V_15 &&
F_15 ( F_1 ( V_5 ) , F_1 ( V_23 ) ) &&
V_5 -> V_13 == V_23 -> V_13 &&
F_35 ( & V_5 -> V_14 , & V_23 -> V_14 ) ) {
if ( ! V_28 ) {
V_29 = - V_34 ;
goto V_35;
}
F_36 ( & V_5 -> V_27 , & V_23 -> V_27 ) ;
F_11 ( V_5 ) ;
goto V_35;
} else if ( ( V_5 -> V_15 == V_23 -> V_15 && ! V_5 -> V_13 ) ||
( V_5 -> V_15 < V_23 -> V_15 ) ) {
F_37 ( & V_23 -> V_27 , & V_5 -> V_27 ) ;
goto V_35;
}
}
F_38 ( & V_5 -> V_27 , & V_23 -> V_27 ) ;
}
V_35:
if ( ! V_29 )
V_30 . V_36 ++ ;
return V_29 ;
}
static int F_39 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 , T_1 V_16 , int V_28 )
{
struct V_2 * V_23 ;
int V_29 = 0 ;
F_22 ( V_21 L_4 ,
V_22 , V_14 , V_15 , V_13 , ( unsigned int ) V_16 ,
V_28 ) ;
V_23 = F_23 ( V_1 , V_14 , V_15 , V_13 , V_16 ) ;
if ( F_40 ( V_23 ) )
return F_41 ( V_23 ) ;
F_42 ( & V_30 . V_37 ) ;
V_29 = F_31 ( V_23 , V_28 ) ;
F_43 ( & V_30 . V_37 ) ;
if ( V_29 )
F_3 ( V_23 ) ;
return V_29 ;
}
static int F_44 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_2 * V_5 = NULL ;
struct V_32 * V_33 ;
int V_29 = - V_38 ;
F_22 ( V_21 L_5 ,
V_22 , V_14 , V_15 , V_13 ) ;
F_34 (p, n, &ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_15 &&
F_15 ( F_1 ( V_5 ) , V_1 ) &&
V_5 -> V_13 == V_13 &&
F_35 ( & V_5 -> V_14 , V_14 ) ) {
F_45 ( & V_5 -> V_27 ) ;
F_11 ( V_5 ) ;
V_29 = 0 ;
break;
}
}
return V_29 ;
}
static int F_46 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_10 V_39 ;
int V_29 ;
F_22 ( V_21 L_5 ,
V_22 , V_14 , V_15 , V_13 ) ;
F_27 ( & V_39 , V_14 , V_15 ) ;
F_42 ( & V_30 . V_37 ) ;
V_29 = F_44 ( V_1 , & V_39 , V_15 , V_13 ) ;
F_43 ( & V_30 . V_37 ) ;
return V_29 ;
}
static int T_2 F_47 ( struct V_1 * V_1 )
{
int V_40 = 0 ;
int V_41 ;
F_22 ( V_21 L_6 , V_22 ) ;
for ( V_41 = 0 ; V_41 < F_48 ( V_42 ) ; V_41 ++ ) {
int V_29 = F_39 ( V_1 ,
V_42 [ V_41 ] . V_14 ,
V_42 [ V_41 ] . V_15 ,
0 ,
V_42 [ V_41 ] . V_16 , 0 ) ;
if ( V_29 && ( ! V_40 || V_40 != - V_26 ) )
V_40 = V_29 ;
}
return V_40 ;
}
static void T_3 F_49 ( struct V_1 * V_1 )
{
struct V_2 * V_5 = NULL ;
struct V_32 * V_33 ;
F_42 ( & V_30 . V_37 ) ;
F_34 (p, n, &ip6addrlbl_table.head, list) {
if ( F_15 ( F_1 ( V_5 ) , V_1 ) ) {
F_45 ( & V_5 -> V_27 ) ;
F_11 ( V_5 ) ;
}
}
F_43 ( & V_30 . V_37 ) ;
}
int T_4 F_50 ( void )
{
F_51 ( & V_30 . V_37 ) ;
return F_52 ( & V_43 ) ;
}
void F_53 ( void )
{
F_54 ( & V_43 ) ;
}
static int F_55 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
struct V_1 * V_1 = F_56 ( V_45 -> V_48 ) ;
struct V_49 * V_50 ;
struct V_51 * V_52 [ V_53 + 1 ] ;
struct V_10 * V_54 ;
T_1 V_16 ;
int V_40 = 0 ;
V_40 = F_57 ( V_47 , sizeof( * V_50 ) , V_52 , V_53 , V_55 ) ;
if ( V_40 < 0 )
return V_40 ;
V_50 = F_58 ( V_47 ) ;
if ( V_50 -> V_56 != V_57 ||
V_50 -> V_58 > 128 )
return - V_24 ;
if ( ! V_52 [ V_59 ] )
return - V_24 ;
V_54 = F_59 ( V_52 [ V_59 ] ) ;
if ( ! V_52 [ V_60 ] )
return - V_24 ;
V_16 = F_60 ( V_52 [ V_60 ] ) ;
if ( V_16 == V_20 )
return - V_24 ;
switch( V_47 -> V_61 ) {
case V_62 :
if ( V_50 -> V_63 &&
! F_61 ( V_1 , V_50 -> V_63 ) )
return - V_24 ;
V_40 = F_39 ( V_1 , V_54 , V_50 -> V_58 ,
V_50 -> V_63 , V_16 ,
V_47 -> V_64 & V_65 ) ;
break;
case V_66 :
V_40 = F_46 ( V_1 , V_54 , V_50 -> V_58 ,
V_50 -> V_63 ) ;
break;
default:
V_40 = - V_67 ;
}
return V_40 ;
}
static void F_62 ( struct V_46 * V_47 ,
int V_15 , int V_13 , T_1 V_68 )
{
struct V_49 * V_50 = F_58 ( V_47 ) ;
V_50 -> V_56 = V_57 ;
V_50 -> V_58 = V_15 ;
V_50 -> V_69 = 0 ;
V_50 -> V_63 = V_13 ;
V_50 -> V_70 = V_68 ;
}
static int F_63 ( struct V_44 * V_45 ,
struct V_2 * V_5 ,
T_1 V_68 ,
T_1 V_71 , T_1 V_36 , int V_72 ,
unsigned int V_73 )
{
struct V_46 * V_47 = F_64 ( V_45 , V_71 , V_36 , V_72 ,
sizeof( struct V_49 ) , V_73 ) ;
if ( ! V_47 )
return - V_74 ;
F_62 ( V_47 , V_5 -> V_15 , V_5 -> V_13 , V_68 ) ;
if ( F_65 ( V_45 , V_59 , 16 , & V_5 -> V_14 ) < 0 ||
F_66 ( V_45 , V_60 , V_5 -> V_16 ) < 0 ) {
F_67 ( V_45 , V_47 ) ;
return - V_74 ;
}
return F_68 ( V_45 , V_47 ) ;
}
static int F_69 ( struct V_44 * V_45 , struct V_75 * V_76 )
{
struct V_1 * V_1 = F_56 ( V_45 -> V_48 ) ;
struct V_2 * V_5 ;
int V_77 = 0 , V_78 = V_76 -> args [ 0 ] ;
int V_40 ;
F_20 () ;
F_18 (p, &ip6addrlbl_table.head, list) {
if ( V_77 >= V_78 &&
F_15 ( F_1 ( V_5 ) , V_1 ) ) {
if ( ( V_40 = F_63 ( V_45 , V_5 ,
V_30 . V_36 ,
F_70 ( V_76 -> V_45 ) . V_71 ,
V_76 -> V_47 -> V_79 ,
V_62 ,
V_80 ) ) <= 0 )
break;
}
V_77 ++ ;
}
F_21 () ;
V_76 -> args [ 0 ] = V_77 ;
return V_45 -> V_81 ;
}
static inline int F_71 ( void )
{
return F_72 ( sizeof( struct V_49 ) )
+ F_73 ( 16 )
+ F_73 ( 4 ) ;
}
static int F_74 ( struct V_44 * V_82 , struct V_46 * V_47 )
{
struct V_1 * V_1 = F_56 ( V_82 -> V_48 ) ;
struct V_49 * V_50 ;
struct V_51 * V_52 [ V_53 + 1 ] ;
struct V_10 * V_11 ;
T_1 V_68 ;
int V_40 = 0 ;
struct V_2 * V_5 ;
struct V_44 * V_45 ;
V_40 = F_57 ( V_47 , sizeof( * V_50 ) , V_52 , V_53 , V_55 ) ;
if ( V_40 < 0 )
return V_40 ;
V_50 = F_58 ( V_47 ) ;
if ( V_50 -> V_56 != V_57 ||
V_50 -> V_58 != 128 )
return - V_24 ;
if ( V_50 -> V_63 &&
! F_61 ( V_1 , V_50 -> V_63 ) )
return - V_24 ;
if ( ! V_52 [ V_59 ] )
return - V_24 ;
V_11 = F_59 ( V_52 [ V_59 ] ) ;
F_20 () ;
V_5 = F_17 ( V_1 , V_11 , F_24 ( V_11 ) , V_50 -> V_63 ) ;
if ( V_5 && F_9 ( V_5 ) )
V_5 = NULL ;
V_68 = V_30 . V_36 ;
F_21 () ;
if ( ! V_5 ) {
V_40 = - V_38 ;
goto V_35;
}
if ( ! ( V_45 = F_75 ( F_71 () , V_25 ) ) ) {
F_11 ( V_5 ) ;
return - V_83 ;
}
V_40 = F_63 ( V_45 , V_5 , V_68 ,
F_70 ( V_82 ) . V_71 , V_47 -> V_79 ,
V_62 , 0 ) ;
F_11 ( V_5 ) ;
if ( V_40 < 0 ) {
F_76 ( V_40 == - V_74 ) ;
F_77 ( V_45 ) ;
goto V_35;
}
V_40 = F_78 ( V_45 , V_1 , F_70 ( V_82 ) . V_71 ) ;
V_35:
return V_40 ;
}
void T_4 F_79 ( void )
{
F_80 ( V_84 , V_62 , F_55 ,
NULL , NULL ) ;
F_80 ( V_84 , V_66 , F_55 ,
NULL , NULL ) ;
F_80 ( V_84 , V_85 , F_74 ,
F_69 , NULL ) ;
}
