static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 -> V_5 + V_7
+ V_2 -> V_8 * V_9 ;
F_2 ( V_4 , V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_10 V_11 )
{
static const char * const V_12 [] = { L_1 , L_2 , L_3 } ;
F_4 ( & V_2 -> V_6 -> V_13 -> V_14 , L_4 ,
V_2 -> V_8 , V_12 [ V_11 ] ) ;
switch ( V_11 ) {
case V_15 :
F_1 ( V_2 , V_16 ,
V_2 -> V_17 == V_18 ?
V_19 : V_20 ) ;
break;
case V_21 :
F_1 ( V_2 , V_16 ,
V_2 -> V_17 == V_18 ?
V_22 : V_23 ) ;
break;
case V_24 :
F_1 ( V_2 , V_16 ,
V_2 -> V_17 == V_18 ?
V_20 : V_19 ) ;
break;
}
}
static void F_5 ( struct V_1 * V_2 , int V_25 )
{
unsigned long V_26 ;
T_1 V_4 ;
F_6 ( & V_2 -> V_6 -> V_27 , V_26 ) ;
V_4 = F_7 ( V_2 -> V_6 -> V_5 + V_28 ) ;
if ( V_25 )
V_4 |= 1 << V_2 -> V_8 ;
else
V_4 &= ~ ( 1 << V_2 -> V_8 ) ;
F_2 ( V_4 , V_2 -> V_6 -> V_5 + V_28 ) ;
F_8 ( & V_2 -> V_6 -> V_27 , V_26 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! V_2 -> V_30 ) {
F_10 ( & V_2 -> V_6 -> V_13 -> V_14 ) ;
V_29 = F_11 ( V_2 -> V_6 -> V_31 ) ;
if ( V_29 ) {
F_12 ( & V_2 -> V_6 -> V_13 -> V_14 , L_5 ) ;
return V_29 ;
}
V_2 -> V_30 = true ;
}
F_3 ( V_2 , V_15 ) ;
F_5 ( V_2 , false ) ;
F_1 ( V_2 , V_32 , V_33 | V_34 |
V_2 -> V_35 ) ;
F_1 ( V_2 , V_36 , V_37 ) ;
F_3 ( V_2 , V_21 ) ;
F_1 ( V_2 , V_38 , V_2 -> V_39 ) ;
F_1 ( V_2 , V_40 , V_2 -> V_41 ) ;
F_4 ( & V_2 -> V_6 -> V_13 -> V_14 , L_6 ,
V_2 -> V_8 , V_2 -> V_39 , V_2 -> V_41 ) ;
F_5 ( V_2 , true ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_30 )
return;
F_5 ( V_2 , false ) ;
F_14 ( V_2 -> V_6 -> V_31 ) ;
F_15 ( & V_2 -> V_6 -> V_13 -> V_14 ) ;
V_2 -> V_30 = false ;
}
static int F_16 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_46 * V_6 = F_17 ( V_43 ) ;
struct V_1 * V_2 ;
if ( V_45 -> V_47 >= V_48 )
return - V_49 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_50 ) ;
if ( V_2 == NULL )
return - V_51 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = V_45 -> V_47 ;
V_2 -> V_17 = V_6 -> V_52 [ V_2 -> V_8 ] ;
V_2 -> V_35 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_30 = false ;
F_19 ( V_45 , V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
F_13 ( V_2 ) ;
F_22 ( V_2 ) ;
}
static int F_23 ( struct V_42 * V_43 , struct V_44 * V_45 ,
int V_53 , int V_54 )
{
static const unsigned int V_55 [] = { 1 , 4 , 16 , 64 } ;
struct V_1 * V_2 = F_21 ( V_45 ) ;
struct V_46 * V_6 = F_17 ( V_43 ) ;
unsigned int V_35 ;
bool V_56 = false ;
T_3 V_57 ;
T_3 V_41 ;
T_3 V_39 ;
int V_29 ;
V_57 = F_24 ( V_6 -> V_31 ) ;
for ( V_35 = 0 ; V_35 < F_25 ( V_55 ) ; ++ V_35 ) {
V_41 = V_57 / V_55 [ V_35 ]
/ ( V_58 / V_54 ) ;
if ( V_41 <= 0xffff )
break;
}
if ( V_35 == F_25 ( V_55 ) || V_41 == 0 ) {
F_12 ( & V_6 -> V_13 -> V_14 , L_7 ) ;
return - V_59 ;
}
if ( V_53 ) {
V_39 = V_57 / V_55 [ V_35 ]
/ ( V_58 / V_53 ) ;
if ( V_39 > V_41 )
return - V_49 ;
} else {
V_39 = 0 ;
}
F_4 ( & V_6 -> V_13 -> V_14 ,
L_8 ,
V_57 , V_55 [ V_35 ] , V_41 , V_39 ) ;
if ( V_2 -> V_35 == V_35 && V_2 -> V_41 == V_41 )
V_56 = true ;
V_2 -> V_35 = V_35 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_39 = V_39 ;
if ( ! F_26 ( V_60 , & V_45 -> V_26 ) )
return 0 ;
if ( V_56 && V_2 -> V_30 ) {
F_1 ( V_2 , V_38 , V_2 -> V_39 ) ;
F_4 ( & V_6 -> V_13 -> V_14 , L_9 , V_2 -> V_8 ,
V_2 -> V_39 ) ;
} else {
V_29 = F_9 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_39 == 0 || V_39 == V_41 ) {
F_3 ( V_2 , V_39 ? V_24 : V_15 ) ;
F_13 ( V_2 ) ;
}
return 0 ;
}
static int F_27 ( struct V_42 * V_43 , struct V_44 * V_45 ,
enum V_61 V_17 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
V_2 -> V_17 = V_17 ;
return 0 ;
}
static int F_28 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
int V_29 ;
V_29 = F_9 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_2 -> V_39 == 0 || V_2 -> V_39 == V_2 -> V_41 ) {
F_3 ( V_2 , V_2 -> V_39 ?
V_24 : V_15 ) ;
F_13 ( V_2 ) ;
}
return 0 ;
}
static void F_29 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
F_9 ( V_2 ) ;
F_3 ( V_2 , V_15 ) ;
F_13 ( V_2 ) ;
}
static void F_30 ( struct V_46 * V_6 )
{
struct V_62 * V_63 = V_6 -> V_13 -> V_14 . V_64 ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < F_25 ( V_6 -> V_52 ) ; ++ V_65 )
V_6 -> V_52 [ V_65 ] = V_63 ? V_63 -> V_66 [ V_65 ] . V_17
: V_67 ;
}
static int F_31 ( struct V_68 * V_13 )
{
struct V_46 * V_6 ;
struct V_69 * V_70 ;
int V_29 ;
V_6 = F_32 ( & V_13 -> V_14 , sizeof( * V_6 ) , V_50 ) ;
if ( V_6 == NULL ) {
F_12 ( & V_13 -> V_14 , L_10 ) ;
return - V_51 ;
}
F_33 ( & V_6 -> V_27 ) ;
V_6 -> V_13 = V_13 ;
F_30 ( V_6 ) ;
V_70 = F_34 ( V_13 , V_71 , 0 ) ;
V_6 -> V_5 = F_35 ( & V_13 -> V_14 , V_70 ) ;
if ( F_36 ( V_6 -> V_5 ) )
return F_37 ( V_6 -> V_5 ) ;
V_6 -> V_31 = F_38 ( & V_13 -> V_14 , NULL ) ;
if ( F_36 ( V_6 -> V_31 ) ) {
F_12 ( & V_13 -> V_14 , L_11 ) ;
return F_37 ( V_6 -> V_31 ) ;
}
F_39 ( V_13 , V_6 ) ;
V_6 -> V_43 . V_14 = & V_13 -> V_14 ;
V_6 -> V_43 . V_72 = & V_73 ;
V_6 -> V_43 . V_74 = V_75 ;
V_6 -> V_43 . V_76 = 3 ;
V_6 -> V_43 . V_5 = - 1 ;
V_6 -> V_43 . V_77 = V_48 ;
V_29 = F_40 ( & V_6 -> V_43 ) ;
if ( V_29 < 0 ) {
F_12 ( & V_13 -> V_14 , L_12 ) ;
return V_29 ;
}
F_41 ( & V_13 -> V_14 , L_13 , V_6 -> V_13 -> V_78 ) ;
F_42 ( & V_13 -> V_14 ) ;
return 0 ;
}
static int F_43 ( struct V_68 * V_13 )
{
struct V_46 * V_6 = F_44 ( V_13 ) ;
int V_29 ;
V_29 = F_45 ( & V_6 -> V_43 ) ;
if ( V_29 )
return V_29 ;
F_46 ( & V_13 -> V_14 ) ;
return 0 ;
}
