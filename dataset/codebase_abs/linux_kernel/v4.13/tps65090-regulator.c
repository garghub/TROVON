static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_4 -> V_6 , V_4 -> V_7 -> V_8 ,
V_9 << V_10 ,
V_2 -> V_11 << V_10 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_12 , L_1 ,
V_4 -> V_7 -> V_8 ) ;
}
return V_5 ;
}
static int F_4 ( struct V_3 * V_4 )
{
unsigned int V_13 ;
int V_5 , V_14 ;
V_5 = F_2 ( V_4 -> V_6 , V_4 -> V_7 -> V_8 ,
V_4 -> V_7 -> V_15 ,
V_4 -> V_7 -> V_15 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_12 , L_2 ,
V_4 -> V_7 -> V_8 ) ;
return V_5 ;
}
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
V_5 = F_5 ( V_4 -> V_6 , V_4 -> V_7 -> V_8 ,
& V_13 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! ( V_13 & F_6 ( V_17 ) ) )
break;
F_7 ( 1000 , 1500 ) ;
}
if ( ! ( V_13 & F_6 ( V_18 ) ) )
return - V_19 ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_5 , V_20 ;
V_20 = 0 ;
while ( true ) {
V_5 = F_4 ( V_4 ) ;
if ( ! V_5 )
break;
if ( V_5 != - V_19 || V_20 == V_21 )
goto V_22;
V_5 = F_2 ( V_4 -> V_6 , V_4 -> V_7 -> V_8 ,
V_4 -> V_7 -> V_15 , 0 ) ;
if ( V_5 )
goto V_22;
V_20 ++ ;
}
if ( V_20 )
F_9 ( & V_4 -> V_12 , L_3 ,
V_4 -> V_7 -> V_8 , V_20 ) ;
return 0 ;
V_22:
F_9 ( & V_4 -> V_12 , L_4 , V_4 -> V_7 -> V_8 ) ;
F_10 ( 1 ) ;
return V_5 ;
}
static inline bool F_11 ( int V_23 )
{
switch ( V_23 ) {
case V_24 :
case V_25 :
case V_26 :
return true ;
default:
return false ;
}
}
static int F_12 (
struct V_1 * V_2 , bool V_27 )
{
int V_5 ;
struct V_28 * V_29 = V_2 -> V_12 -> V_29 ;
unsigned int V_30 = V_2 -> V_7 -> V_8 ;
if ( V_27 )
V_5 = F_13 ( V_29 , V_30 , 1 ) ;
else
V_5 = F_14 ( V_29 , V_30 , 1 ) ;
if ( V_5 < 0 )
F_3 ( V_2 -> V_12 , L_5 , V_30 ) ;
return V_5 ;
}
static int F_15 (
struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_5 = 0 ;
struct V_28 * V_29 = V_2 -> V_12 -> V_29 ;
unsigned int V_30 = V_2 -> V_7 -> V_8 ;
if ( V_32 -> V_33 -> V_34 . V_35 ||
V_32 -> V_33 -> V_34 . V_36 ) {
V_5 = F_13 ( V_29 , V_30 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_12 , L_6 , V_30 ) ;
return V_5 ;
}
}
return F_12 ( V_2 , false ) ;
}
static void F_16 (
struct V_31 * V_32 ,
struct V_37 * V_38 )
{
if ( F_17 ( V_32 -> V_39 ) ) {
int V_40 = V_41 ;
if ( V_32 -> V_33 -> V_34 . V_35 ||
V_32 -> V_33 -> V_34 . V_36 )
V_40 = V_42 ;
V_38 -> V_43 = V_32 -> V_39 ;
V_38 -> V_44 = true ;
V_38 -> V_45 = V_40 ;
} else {
V_38 -> V_43 = - V_46 ;
V_38 -> V_44 = false ;
}
}
static struct V_47 * F_18 (
struct V_48 * V_49 ,
struct V_50 * * V_51 )
{
struct V_47 * V_52 ;
struct V_53 * V_54 = V_49 -> V_12 . V_29 -> V_55 ;
struct V_53 * V_56 ;
int V_57 = 0 , V_5 ;
struct V_31 * V_58 ;
V_52 = F_19 ( & V_49 -> V_12 , sizeof( * V_52 ) ,
V_59 ) ;
if ( ! V_52 )
return F_20 ( - V_60 ) ;
V_58 = F_19 ( & V_49 -> V_12 , V_61 *
sizeof( * V_58 ) , V_59 ) ;
if ( ! V_58 )
return F_20 ( - V_60 ) ;
V_56 = F_21 ( V_54 , L_7 ) ;
if ( ! V_56 ) {
F_3 ( & V_49 -> V_12 , L_8 ) ;
return F_20 ( - V_62 ) ;
}
V_5 = V_50 ( & V_49 -> V_12 , V_56 , V_63 ,
F_22 ( V_63 ) ) ;
F_23 ( V_56 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_49 -> V_12 ,
L_9 , V_5 ) ;
return F_20 ( V_5 ) ;
}
* V_51 = V_63 ;
for ( V_57 = 0 ; V_57 < F_22 ( V_63 ) ; V_57 ++ ) {
struct V_64 * V_65 ;
struct V_31 * V_66 ;
V_66 = & V_58 [ V_57 ] ;
V_65 = V_63 [ V_57 ] . V_67 ;
if ( ! V_65 || ! V_63 [ V_57 ] . V_55 )
continue;
V_66 -> V_33 = V_65 ;
V_66 -> V_68 = F_24 (
V_63 [ V_57 ] . V_55 ,
L_10 ) ;
if ( V_66 -> V_68 )
V_66 -> V_39 = F_25 ( V_54 ,
L_11 , 0 ) ;
if ( F_26 ( V_63 [ V_57 ] . V_55 ,
L_12 ,
& V_66 -> V_11 ) == 0 )
V_66 -> V_69 = true ;
V_52 -> V_58 [ V_57 ] = V_66 ;
}
return V_52 ;
}
static inline struct V_47 * F_18 (
struct V_48 * V_49 ,
struct V_50 * * V_51 )
{
* V_51 = NULL ;
return NULL ;
}
static int F_27 ( struct V_48 * V_49 )
{
struct V_70 * V_71 = F_28 ( V_49 -> V_12 . V_29 ) ;
struct V_1 * V_2 = NULL ;
struct V_37 V_38 = { } ;
struct V_3 * V_4 ;
struct V_31 * V_32 ;
struct V_1 * V_72 ;
struct V_47 * V_52 ;
struct V_50 * V_51 = NULL ;
int V_73 ;
int V_5 ;
F_29 ( & V_49 -> V_12 , L_13 ) ;
V_52 = F_30 ( V_49 -> V_12 . V_29 ) ;
if ( ! V_52 && V_71 -> V_12 -> V_55 )
V_52 = F_18 ( V_49 ,
& V_51 ) ;
if ( F_31 ( V_52 ) ) {
F_3 ( & V_49 -> V_12 , L_14 ) ;
return V_52 ? F_32 ( V_52 ) : - V_46 ;
}
V_72 = F_19 ( & V_49 -> V_12 , V_61 * sizeof( * V_72 ) ,
V_59 ) ;
if ( ! V_72 )
return - V_60 ;
for ( V_73 = 0 ; V_73 < V_61 ; V_73 ++ ) {
V_32 = V_52 -> V_58 [ V_73 ] ;
V_2 = & V_72 [ V_73 ] ;
V_2 -> V_12 = & V_49 -> V_12 ;
V_2 -> V_7 = & V_74 [ V_73 ] ;
if ( V_32 ) {
V_2 -> V_69 =
V_32 -> V_69 ;
V_2 -> V_11 = V_32 -> V_11 ;
}
if ( V_32 && F_11 ( V_73 ) && V_32 -> V_33 ) {
if ( V_32 -> V_68 ) {
F_16 (
V_32 , & V_38 ) ;
V_2 -> V_7 -> V_75 = & V_76 ;
} else {
V_5 = F_15 (
V_2 , V_32 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_49 -> V_12 ,
L_15 ) ;
return V_5 ;
}
}
}
V_38 . V_12 = V_49 -> V_12 . V_29 ;
V_38 . V_77 = V_2 ;
V_38 . V_6 = V_71 -> V_78 ;
if ( V_32 )
V_38 . V_67 = V_32 -> V_33 ;
else
V_38 . V_67 = NULL ;
if ( V_51 )
V_38 . V_55 = V_51 [ V_73 ] . V_55 ;
else
V_38 . V_55 = NULL ;
V_4 = F_33 ( & V_49 -> V_12 , V_2 -> V_7 , & V_38 ) ;
if ( F_34 ( V_4 ) ) {
F_3 ( & V_49 -> V_12 , L_16 ,
V_2 -> V_7 -> V_79 ) ;
return F_32 ( V_4 ) ;
}
V_2 -> V_4 = V_4 ;
if ( V_2 -> V_69 ) {
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_32 && F_11 ( V_73 ) && V_32 -> V_33 &&
V_32 -> V_68 ) {
V_5 = F_12 ( V_2 , true ) ;
if ( V_5 < 0 )
return V_5 ;
}
}
F_35 ( V_49 , V_72 ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_80 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_80 ) ;
}
