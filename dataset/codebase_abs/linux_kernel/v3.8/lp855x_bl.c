static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_7 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_5 ( V_2 -> V_6 , V_3 , V_4 ) ;
}
static bool F_6 ( struct V_1 * V_2 , T_1 V_8 )
{
T_1 V_9 , V_10 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_9 = V_16 ;
V_10 = V_17 ;
break;
case V_18 :
V_9 = V_19 ;
V_10 = V_20 ;
break;
default:
return false ;
}
return ( V_8 >= V_9 && V_8 <= V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_21 , V_8 ;
int V_22 , V_5 ;
struct V_23 * V_24 = V_2 -> V_25 ;
V_21 = V_24 -> V_26 ;
V_5 = F_4 ( V_2 , V_27 , V_21 ) ;
if ( V_5 )
return V_5 ;
V_21 = V_24 -> V_28 ;
V_5 = F_4 ( V_2 , V_29 , V_21 ) ;
if ( V_5 )
return V_5 ;
if ( V_24 -> V_30 && V_24 -> V_31 ) {
for ( V_22 = 0 ; V_22 < V_24 -> V_31 ; V_22 ++ ) {
V_8 = V_24 -> V_32 [ V_22 ] . V_8 ;
V_21 = V_24 -> V_32 [ V_22 ] . V_21 ;
if ( ! F_6 ( V_2 , V_8 ) )
continue;
V_5 = F_4 ( V_2 , V_8 , V_21 ) ;
if ( V_5 )
return V_5 ;
}
}
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 , int V_33 , int V_34 )
{
unsigned int V_35 = V_2 -> V_25 -> V_36 ;
unsigned int V_37 = V_33 * V_35 / V_34 ;
struct V_38 * V_39 ;
if ( ! V_2 -> V_39 ) {
V_39 = F_9 ( V_2 -> V_7 , V_2 -> V_40 ) ;
if ( F_10 ( V_39 ) )
return;
V_2 -> V_39 = V_39 ;
}
F_11 ( V_2 -> V_39 , V_37 , V_35 ) ;
if ( V_37 )
F_12 ( V_2 -> V_39 ) ;
else
F_13 ( V_2 -> V_39 ) ;
}
static int F_14 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_15 ( V_42 ) ;
enum V_43 V_44 = V_2 -> V_25 -> V_44 ;
if ( V_42 -> V_45 . V_46 & V_47 )
V_42 -> V_45 . V_48 = 0 ;
if ( V_44 == V_49 ) {
int V_33 = V_42 -> V_45 . V_48 ;
int V_34 = V_42 -> V_45 . V_50 ;
F_8 ( V_2 , V_33 , V_34 ) ;
} else if ( V_44 == V_51 ) {
T_1 V_21 = V_42 -> V_45 . V_48 ;
F_4 ( V_2 , V_27 , V_21 ) ;
}
return 0 ;
}
static int F_16 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_15 ( V_42 ) ;
enum V_43 V_44 = V_2 -> V_25 -> V_44 ;
if ( V_44 == V_51 ) {
T_1 V_21 = 0 ;
F_1 ( V_2 , V_27 , & V_21 ) ;
V_42 -> V_45 . V_48 = V_21 ;
}
return V_42 -> V_45 . V_48 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_52 V_45 ;
struct V_23 * V_25 = V_2 -> V_25 ;
char * V_53 = V_25 -> V_53 ? : V_54 ;
V_45 . type = V_55 ;
V_45 . V_50 = V_56 ;
if ( V_25 -> V_26 > V_45 . V_50 )
V_25 -> V_26 = V_45 . V_50 ;
V_45 . V_48 = V_25 -> V_26 ;
V_42 = F_18 ( V_53 , V_2 -> V_7 , V_2 ,
& V_57 , & V_45 ) ;
if ( F_10 ( V_42 ) )
return F_19 ( V_42 ) ;
V_2 -> V_42 = V_42 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 )
F_21 ( V_2 -> V_42 ) ;
}
static T_2 F_22 ( struct V_58 * V_7 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
return F_24 ( V_61 , V_62 , L_2 , V_2 -> V_40 ) ;
}
static T_2 F_25 ( struct V_58 * V_7 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
enum V_43 V_44 = V_2 -> V_25 -> V_44 ;
char * V_63 = NULL ;
if ( V_44 == V_49 )
V_63 = L_3 ;
else if ( V_44 == V_51 )
V_63 = L_4 ;
return F_24 ( V_61 , V_62 , L_2 , V_63 ) ;
}
static int F_26 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
struct V_1 * V_2 ;
struct V_23 * V_25 = V_65 -> V_7 . V_68 ;
enum V_43 V_44 ;
int V_5 ;
if ( ! V_25 ) {
F_3 ( & V_65 -> V_7 , L_5 ) ;
return - V_69 ;
}
if ( ! F_27 ( V_65 -> V_70 , V_71 ) )
return - V_72 ;
V_2 = F_28 ( & V_65 -> V_7 , sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_44 = V_25 -> V_44 ;
V_2 -> V_6 = V_65 ;
V_2 -> V_7 = & V_65 -> V_7 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_40 = V_67 -> V_53 ;
V_2 -> V_11 = V_67 -> V_75 ;
F_29 ( V_65 , V_2 ) ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_6 , V_5 ) ;
if ( V_44 == V_51 )
goto V_76;
}
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 ,
L_7 , V_5 ) ;
goto V_76;
}
V_5 = F_30 ( & V_2 -> V_7 -> V_77 , & V_78 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_8 , V_5 ) ;
goto V_79;
}
F_31 ( V_2 -> V_42 ) ;
return 0 ;
V_79:
F_20 ( V_2 ) ;
V_76:
return V_5 ;
}
static int F_32 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_33 ( V_65 ) ;
V_2 -> V_42 -> V_45 . V_48 = 0 ;
F_31 ( V_2 -> V_42 ) ;
F_34 ( & V_2 -> V_7 -> V_77 , & V_78 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
