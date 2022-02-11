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
struct V_16 * V_17 ;
struct V_2 * V_5 ;
F_18 (p, pos, &ip6addrlbl_table.head, list) {
if ( F_14 ( V_1 , V_5 , V_11 , type , V_13 ) )
return V_5 ;
}
return NULL ;
}
T_1 F_19 ( struct V_1 * V_1 ,
const struct V_10 * V_11 , int type , int V_13 )
{
T_1 V_18 ;
struct V_2 * V_5 ;
type &= V_19 | V_20 | V_21 ;
F_20 () ;
V_5 = F_17 ( V_1 , V_11 , type , V_13 ) ;
V_18 = V_5 ? V_5 -> V_18 : V_22 ;
F_21 () ;
F_22 ( V_23 L_1 ,
V_24 , V_11 , type , V_13 , V_18 ) ;
return V_18 ;
}
static struct V_2 * F_23 ( struct V_1 * V_1 ,
const struct V_10 * V_14 ,
int V_15 , int V_13 ,
T_1 V_18 )
{
struct V_2 * V_25 ;
int V_12 ;
F_22 ( V_23 L_2 ,
V_24 , V_14 , V_15 , V_13 , ( unsigned int ) V_18 ) ;
V_12 = F_24 ( V_14 ) & ( V_19 | V_20 | V_21 ) ;
switch ( V_12 ) {
case V_19 :
if ( V_15 > 96 )
return F_25 ( - V_26 ) ;
if ( V_15 < 96 )
V_12 = 0 ;
break;
case V_20 :
if ( V_15 != 96 )
V_12 = 0 ;
break;
case V_21 :
if ( V_15 != 128 )
V_12 = 0 ;
break;
}
V_25 = F_26 ( sizeof( * V_25 ) , V_27 ) ;
if ( ! V_25 )
return F_25 ( - V_28 ) ;
F_27 ( & V_25 -> V_14 , V_14 , V_15 ) ;
V_25 -> V_15 = V_15 ;
V_25 -> V_13 = V_13 ;
V_25 -> V_12 = V_12 ;
V_25 -> V_18 = V_18 ;
F_28 ( & V_25 -> V_29 ) ;
#ifdef F_4
V_25 -> V_4 = F_29 ( V_1 ) ;
#endif
F_30 ( & V_25 -> V_9 , 1 ) ;
return V_25 ;
}
static int F_31 ( struct V_2 * V_25 , int V_30 )
{
int V_31 = 0 ;
F_22 ( V_23 L_3 ,
V_24 ,
V_25 , V_30 ) ;
if ( F_32 ( & V_32 . V_33 ) ) {
F_33 ( & V_25 -> V_29 , & V_32 . V_33 ) ;
} else {
struct V_16 * V_17 , * V_34 ;
struct V_2 * V_5 = NULL ;
F_34 (p, pos, n,
&ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_25 -> V_15 &&
F_15 ( F_1 ( V_5 ) , F_1 ( V_25 ) ) &&
V_5 -> V_13 == V_25 -> V_13 &&
F_35 ( & V_5 -> V_14 , & V_25 -> V_14 ) ) {
if ( ! V_30 ) {
V_31 = - V_35 ;
goto V_36;
}
F_36 ( & V_5 -> V_29 , & V_25 -> V_29 ) ;
F_11 ( V_5 ) ;
goto V_36;
} else if ( ( V_5 -> V_15 == V_25 -> V_15 && ! V_5 -> V_13 ) ||
( V_5 -> V_15 < V_25 -> V_15 ) ) {
F_37 ( & V_25 -> V_29 , & V_5 -> V_29 ) ;
goto V_36;
}
}
F_38 ( & V_5 -> V_29 , & V_25 -> V_29 ) ;
}
V_36:
if ( ! V_31 )
V_32 . V_37 ++ ;
return V_31 ;
}
static int F_39 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 , T_1 V_18 , int V_30 )
{
struct V_2 * V_25 ;
int V_31 = 0 ;
F_22 ( V_23 L_4 ,
V_24 , V_14 , V_15 , V_13 , ( unsigned int ) V_18 ,
V_30 ) ;
V_25 = F_23 ( V_1 , V_14 , V_15 , V_13 , V_18 ) ;
if ( F_40 ( V_25 ) )
return F_41 ( V_25 ) ;
F_42 ( & V_32 . V_38 ) ;
V_31 = F_31 ( V_25 , V_30 ) ;
F_43 ( & V_32 . V_38 ) ;
if ( V_31 )
F_3 ( V_25 ) ;
return V_31 ;
}
static int F_44 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_2 * V_5 = NULL ;
struct V_16 * V_17 , * V_34 ;
int V_31 = - V_39 ;
F_22 ( V_23 L_5 ,
V_24 , V_14 , V_15 , V_13 ) ;
F_34 (p, pos, n, &ip6addrlbl_table.head, list) {
if ( V_5 -> V_15 == V_15 &&
F_15 ( F_1 ( V_5 ) , V_1 ) &&
V_5 -> V_13 == V_13 &&
F_35 ( & V_5 -> V_14 , V_14 ) ) {
F_45 ( & V_5 -> V_29 ) ;
F_11 ( V_5 ) ;
V_31 = 0 ;
break;
}
}
return V_31 ;
}
static int F_46 ( struct V_1 * V_1 ,
const struct V_10 * V_14 , int V_15 ,
int V_13 )
{
struct V_10 V_40 ;
int V_31 ;
F_22 ( V_23 L_5 ,
V_24 , V_14 , V_15 , V_13 ) ;
F_27 ( & V_40 , V_14 , V_15 ) ;
F_42 ( & V_32 . V_38 ) ;
V_31 = F_44 ( V_1 , & V_40 , V_15 , V_13 ) ;
F_43 ( & V_32 . V_38 ) ;
return V_31 ;
}
static int T_2 F_47 ( struct V_1 * V_1 )
{
int V_41 = 0 ;
int V_42 ;
F_22 ( V_23 L_6 , V_24 ) ;
for ( V_42 = 0 ; V_42 < F_48 ( V_43 ) ; V_42 ++ ) {
int V_31 = F_39 ( V_1 ,
V_43 [ V_42 ] . V_14 ,
V_43 [ V_42 ] . V_15 ,
0 ,
V_43 [ V_42 ] . V_18 , 0 ) ;
if ( V_31 && ( ! V_41 || V_41 != - V_28 ) )
V_41 = V_31 ;
}
return V_41 ;
}
static void T_3 F_49 ( struct V_1 * V_1 )
{
struct V_2 * V_5 = NULL ;
struct V_16 * V_17 , * V_34 ;
F_42 ( & V_32 . V_38 ) ;
F_34 (p, pos, n, &ip6addrlbl_table.head, list) {
if ( F_15 ( F_1 ( V_5 ) , V_1 ) ) {
F_45 ( & V_5 -> V_29 ) ;
F_11 ( V_5 ) ;
}
}
F_43 ( & V_32 . V_38 ) ;
}
int T_4 F_50 ( void )
{
F_51 ( & V_32 . V_38 ) ;
return F_52 ( & V_44 ) ;
}
void F_53 ( void )
{
F_54 ( & V_44 ) ;
}
static int F_55 ( struct V_45 * V_46 , struct V_47 * V_48 ,
void * V_49 )
{
struct V_1 * V_1 = F_56 ( V_46 -> V_50 ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 [ V_55 + 1 ] ;
struct V_10 * V_56 ;
T_1 V_18 ;
int V_41 = 0 ;
V_41 = F_57 ( V_48 , sizeof( * V_52 ) , V_54 , V_55 , V_57 ) ;
if ( V_41 < 0 )
return V_41 ;
V_52 = F_58 ( V_48 ) ;
if ( V_52 -> V_58 != V_59 ||
V_52 -> V_60 > 128 )
return - V_26 ;
if ( ! V_54 [ V_61 ] )
return - V_26 ;
V_56 = F_59 ( V_54 [ V_61 ] ) ;
if ( ! V_56 )
return - V_26 ;
if ( ! V_54 [ V_62 ] )
return - V_26 ;
V_18 = F_60 ( V_54 [ V_62 ] ) ;
if ( V_18 == V_22 )
return - V_26 ;
switch( V_48 -> V_63 ) {
case V_64 :
if ( V_52 -> V_65 &&
! F_61 ( V_1 , V_52 -> V_65 ) )
return - V_26 ;
V_41 = F_39 ( V_1 , V_56 , V_52 -> V_60 ,
V_52 -> V_65 , V_18 ,
V_48 -> V_66 & V_67 ) ;
break;
case V_68 :
V_41 = F_46 ( V_1 , V_56 , V_52 -> V_60 ,
V_52 -> V_65 ) ;
break;
default:
V_41 = - V_69 ;
}
return V_41 ;
}
static void F_62 ( struct V_47 * V_48 ,
int V_15 , int V_13 , T_1 V_70 )
{
struct V_51 * V_52 = F_58 ( V_48 ) ;
V_52 -> V_58 = V_59 ;
V_52 -> V_60 = V_15 ;
V_52 -> V_71 = 0 ;
V_52 -> V_65 = V_13 ;
V_52 -> V_72 = V_70 ;
}
static int F_63 ( struct V_45 * V_46 ,
struct V_2 * V_5 ,
T_1 V_70 ,
T_1 V_73 , T_1 V_37 , int V_74 ,
unsigned int V_75 )
{
struct V_47 * V_48 = F_64 ( V_46 , V_73 , V_37 , V_74 ,
sizeof( struct V_51 ) , V_75 ) ;
if ( ! V_48 )
return - V_76 ;
F_62 ( V_48 , V_5 -> V_15 , V_5 -> V_13 , V_70 ) ;
if ( F_65 ( V_46 , V_61 , 16 , & V_5 -> V_14 ) < 0 ||
F_66 ( V_46 , V_62 , V_5 -> V_18 ) < 0 ) {
F_67 ( V_46 , V_48 ) ;
return - V_76 ;
}
return F_68 ( V_46 , V_48 ) ;
}
static int F_69 ( struct V_45 * V_46 , struct V_77 * V_78 )
{
struct V_1 * V_1 = F_56 ( V_46 -> V_50 ) ;
struct V_2 * V_5 ;
struct V_16 * V_17 ;
int V_79 = 0 , V_80 = V_78 -> args [ 0 ] ;
int V_41 ;
F_20 () ;
F_18 (p, pos, &ip6addrlbl_table.head, list) {
if ( V_79 >= V_80 &&
F_15 ( F_1 ( V_5 ) , V_1 ) ) {
if ( ( V_41 = F_63 ( V_46 , V_5 ,
V_32 . V_37 ,
F_70 ( V_78 -> V_46 ) . V_73 ,
V_78 -> V_48 -> V_81 ,
V_64 ,
V_82 ) ) <= 0 )
break;
}
V_79 ++ ;
}
F_21 () ;
V_78 -> args [ 0 ] = V_79 ;
return V_46 -> V_83 ;
}
static inline int F_71 ( void )
{
return F_72 ( sizeof( struct V_51 ) )
+ F_73 ( 16 )
+ F_73 ( 4 ) ;
}
static int F_74 ( struct V_45 * V_84 , struct V_47 * V_48 ,
void * V_49 )
{
struct V_1 * V_1 = F_56 ( V_84 -> V_50 ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 [ V_55 + 1 ] ;
struct V_10 * V_11 ;
T_1 V_70 ;
int V_41 = 0 ;
struct V_2 * V_5 ;
struct V_45 * V_46 ;
V_41 = F_57 ( V_48 , sizeof( * V_52 ) , V_54 , V_55 , V_57 ) ;
if ( V_41 < 0 )
return V_41 ;
V_52 = F_58 ( V_48 ) ;
if ( V_52 -> V_58 != V_59 ||
V_52 -> V_60 != 128 )
return - V_26 ;
if ( V_52 -> V_65 &&
! F_61 ( V_1 , V_52 -> V_65 ) )
return - V_26 ;
if ( ! V_54 [ V_61 ] )
return - V_26 ;
V_11 = F_59 ( V_54 [ V_61 ] ) ;
if ( ! V_11 )
return - V_26 ;
F_20 () ;
V_5 = F_17 ( V_1 , V_11 , F_24 ( V_11 ) , V_52 -> V_65 ) ;
if ( V_5 && F_9 ( V_5 ) )
V_5 = NULL ;
V_70 = V_32 . V_37 ;
F_21 () ;
if ( ! V_5 ) {
V_41 = - V_39 ;
goto V_36;
}
if ( ! ( V_46 = F_75 ( F_71 () , V_27 ) ) ) {
F_11 ( V_5 ) ;
return - V_85 ;
}
V_41 = F_63 ( V_46 , V_5 , V_70 ,
F_70 ( V_84 ) . V_73 , V_48 -> V_81 ,
V_64 , 0 ) ;
F_11 ( V_5 ) ;
if ( V_41 < 0 ) {
F_76 ( V_41 == - V_76 ) ;
F_77 ( V_46 ) ;
goto V_36;
}
V_41 = F_78 ( V_46 , V_1 , F_70 ( V_84 ) . V_73 ) ;
V_36:
return V_41 ;
}
void T_4 F_79 ( void )
{
F_80 ( V_86 , V_64 , F_55 ,
NULL , NULL ) ;
F_80 ( V_86 , V_68 , F_55 ,
NULL , NULL ) ;
F_80 ( V_86 , V_87 , F_74 ,
F_69 , NULL ) ;
}
