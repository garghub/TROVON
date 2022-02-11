static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_3 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 -> V_8 , L_1 , V_3 ) ;
return V_5 ;
}
F_4 ( & V_2 -> V_6 ) ;
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_7 ( V_2 -> V_7 , V_3 , V_4 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static bool F_8 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_10 , V_11 ;
switch ( V_2 -> V_12 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_10 = V_17 ;
V_11 = V_18 ;
break;
case V_19 :
V_10 = V_20 ;
V_11 = V_21 ;
break;
default:
return false ;
}
return ( V_9 >= V_10 && V_9 <= V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_22 , V_9 ;
int V_23 , V_5 ;
struct V_24 * V_25 = V_2 -> V_26 ;
V_22 = V_25 -> V_27 ;
V_5 = F_6 ( V_2 , V_28 , V_22 ) ;
if ( V_5 )
return V_5 ;
V_22 = V_25 -> V_29 ;
V_5 = F_6 ( V_2 , V_30 , V_22 ) ;
if ( V_5 )
return V_5 ;
if ( V_25 -> V_31 && V_25 -> V_32 ) {
for ( V_23 = 0 ; V_23 < V_25 -> V_32 ; V_23 ++ ) {
V_9 = V_25 -> V_33 [ V_23 ] . V_9 ;
V_22 = V_25 -> V_33 [ V_23 ] . V_22 ;
if ( ! F_8 ( V_2 , V_9 ) )
continue;
V_5 = F_6 ( V_2 , V_9 , V_22 ) ;
if ( V_5 )
return V_5 ;
}
}
return V_5 ;
}
static int F_10 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
enum V_36 V_37 = V_2 -> V_26 -> V_37 ;
if ( V_35 -> V_38 . V_39 & V_40 )
V_35 -> V_38 . V_41 = 0 ;
if ( V_37 == V_42 ) {
struct V_43 * V_25 = & V_2 -> V_26 -> V_44 ;
int V_45 = V_35 -> V_38 . V_41 ;
int V_46 = V_35 -> V_38 . V_47 ;
if ( V_25 -> V_48 )
V_25 -> V_48 ( V_45 , V_46 ) ;
} else if ( V_37 == V_49 ) {
T_1 V_22 = V_35 -> V_38 . V_41 ;
F_6 ( V_2 , V_28 , V_22 ) ;
}
return 0 ;
}
static int F_12 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_11 ( V_35 ) ;
enum V_36 V_37 = V_2 -> V_26 -> V_37 ;
if ( V_37 == V_42 ) {
struct V_43 * V_25 = & V_2 -> V_26 -> V_44 ;
int V_46 = V_35 -> V_38 . V_47 ;
if ( V_25 -> V_50 )
V_35 -> V_38 . V_41 = V_25 -> V_50 ( V_46 ) ;
} else if ( V_37 == V_49 ) {
T_1 V_22 = 0 ;
F_1 ( V_2 , V_28 , & V_22 ) ;
V_35 -> V_38 . V_41 = V_22 ;
}
return V_35 -> V_38 . V_41 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_51 V_38 ;
struct V_24 * V_26 = V_2 -> V_26 ;
char * V_52 = V_26 -> V_52 ? : V_53 ;
V_38 . type = V_54 ;
V_38 . V_47 = V_55 ;
if ( V_26 -> V_27 > V_38 . V_47 )
V_26 -> V_27 = V_38 . V_47 ;
V_38 . V_41 = V_26 -> V_27 ;
V_35 = F_14 ( V_52 , V_2 -> V_8 , V_2 ,
& V_56 , & V_38 ) ;
if ( F_15 ( V_35 ) )
return F_16 ( V_35 ) ;
V_2 -> V_35 = V_35 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 )
F_18 ( V_2 -> V_35 ) ;
}
static T_2 F_19 ( struct V_57 * V_8 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_1 * V_2 = F_20 ( V_8 ) ;
return F_21 ( V_60 , V_61 , L_2 , V_2 -> V_62 ) ;
}
static T_2 F_22 ( struct V_57 * V_8 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_1 * V_2 = F_20 ( V_8 ) ;
enum V_36 V_37 = V_2 -> V_26 -> V_37 ;
char * V_63 = NULL ;
if ( V_37 == V_42 )
V_63 = L_3 ;
else if ( V_37 == V_49 )
V_63 = L_4 ;
return F_21 ( V_60 , V_61 , L_2 , V_63 ) ;
}
static int F_23 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
struct V_1 * V_2 ;
struct V_24 * V_26 = V_65 -> V_8 . V_68 ;
enum V_36 V_37 ;
int V_5 ;
if ( ! V_26 ) {
F_5 ( & V_65 -> V_8 , L_5 ) ;
return - V_69 ;
}
if ( ! F_24 ( V_65 -> V_70 , V_71 ) )
return - V_72 ;
V_2 = F_25 ( & V_65 -> V_8 , sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_37 = V_26 -> V_37 ;
V_2 -> V_7 = V_65 ;
V_2 -> V_8 = & V_65 -> V_8 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_62 = V_67 -> V_52 ;
V_2 -> V_12 = V_67 -> V_75 ;
F_26 ( V_65 , V_2 ) ;
F_27 ( & V_2 -> V_6 ) ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 ) {
F_5 ( V_2 -> V_8 , L_6 , V_5 ) ;
if ( V_37 == V_49 )
goto V_76;
}
V_5 = F_13 ( V_2 ) ;
if ( V_5 ) {
F_5 ( V_2 -> V_8 ,
L_7 , V_5 ) ;
goto V_76;
}
V_5 = F_28 ( & V_2 -> V_8 -> V_77 , & V_78 ) ;
if ( V_5 ) {
F_5 ( V_2 -> V_8 , L_8 , V_5 ) ;
goto V_79;
}
F_29 ( V_2 -> V_35 ) ;
return 0 ;
V_79:
F_17 ( V_2 ) ;
V_76:
return V_5 ;
}
static int T_3 F_30 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_31 ( V_65 ) ;
V_2 -> V_35 -> V_38 . V_41 = 0 ;
F_29 ( V_2 -> V_35 ) ;
F_32 ( & V_2 -> V_8 -> V_77 , & V_78 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
