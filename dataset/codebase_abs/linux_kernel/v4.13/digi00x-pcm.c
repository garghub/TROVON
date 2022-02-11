static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , V_7 ) ;
const struct V_5 * V_8 =
F_3 ( V_2 , V_9 ) ;
struct V_5 V_10 = {
. V_11 = V_12 , . V_13 = 0 , . integer = 1 ,
} ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! F_4 ( V_8 ,
V_16 [ V_14 ] ) )
continue;
V_10 . V_11 = V_11 ( V_10 . V_11 , V_17 [ V_14 ] ) ;
V_10 . V_13 = V_13 ( V_10 . V_13 , V_17 [ V_14 ] ) ;
}
return F_5 ( V_6 , & V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_8 =
F_2 ( V_2 , V_9 ) ;
const struct V_5 * V_6 =
F_3 ( V_2 , V_7 ) ;
struct V_5 V_10 = {
. V_11 = V_12 , . V_13 = 0 , . integer = 1 ,
} ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! F_4 ( V_6 , V_17 [ V_14 ] ) )
continue;
V_10 . V_11 = V_11 ( V_10 . V_11 , V_16 [ V_14 ] ) ;
V_10 . V_13 = V_13 ( V_10 . V_13 , V_16 [ V_14 ] ) ;
}
return F_5 ( V_8 , & V_10 ) ;
}
static int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_26 * V_27 ;
int V_28 ;
if ( V_21 -> V_29 == V_30 ) {
V_21 -> V_23 -> V_25 . V_31 = V_32 ;
V_27 = & V_19 -> V_33 ;
} else {
V_21 -> V_23 -> V_25 . V_31 = V_32 ;
V_27 = & V_19 -> V_34 ;
}
V_25 -> V_35 = 10 ;
V_25 -> V_36 = 18 ;
V_25 -> V_37 = V_38 |
V_39 |
V_40 |
V_41 ;
F_8 ( V_23 ) ;
V_28 = F_9 ( V_21 -> V_23 , 0 ,
V_9 ,
F_6 , NULL ,
V_7 , - 1 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_9 ( V_21 -> V_23 , 0 ,
V_7 ,
F_1 , NULL ,
V_9 , - 1 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_10 ( V_27 , V_21 -> V_23 ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
enum V_43 clock ;
bool V_44 ;
unsigned int V_45 ;
int V_28 ;
V_28 = F_12 ( V_19 ) ;
if ( V_28 < 0 )
goto V_46;
V_28 = F_7 ( V_19 , V_21 ) ;
if ( V_28 < 0 )
goto V_47;
V_28 = F_13 ( V_19 , & clock ) ;
if ( V_28 < 0 )
goto V_47;
if ( clock != V_48 ) {
V_28 = F_14 ( V_19 , & V_44 ) ;
if ( V_28 < 0 )
goto V_47;
if ( ! V_44 ) {
V_28 = - V_49 ;
goto V_47;
}
}
if ( ( clock != V_48 ) ||
F_15 ( & V_19 -> V_34 ) ||
F_15 ( & V_19 -> V_33 ) ) {
V_28 = F_16 ( V_19 , & V_45 ) ;
if ( V_28 < 0 )
goto V_47;
V_21 -> V_23 -> V_25 . V_50 = V_45 ;
V_21 -> V_23 -> V_25 . V_51 = V_45 ;
}
F_17 ( V_21 ) ;
V_46:
return V_28 ;
V_47:
F_18 ( V_19 ) ;
return V_28 ;
}
static int F_19 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
F_18 ( V_19 ) ;
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
struct V_1 * V_52 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
int V_28 ;
V_28 = F_21 ( V_21 ,
F_22 ( V_52 ) ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_21 -> V_23 -> V_53 -> V_54 == V_55 ) {
F_23 ( & V_19 -> V_56 ) ;
V_19 -> V_57 ++ ;
F_24 ( & V_19 -> V_56 ) ;
}
return 0 ;
}
static int F_25 ( struct V_20 * V_21 ,
struct V_1 * V_52 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
int V_28 ;
V_28 = F_21 ( V_21 ,
F_22 ( V_52 ) ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_21 -> V_23 -> V_53 -> V_54 == V_55 ) {
F_23 ( & V_19 -> V_56 ) ;
V_19 -> V_57 ++ ;
F_24 ( & V_19 -> V_56 ) ;
}
return 0 ;
}
static int F_26 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
F_23 ( & V_19 -> V_56 ) ;
if ( V_21 -> V_23 -> V_53 -> V_54 != V_55 )
V_19 -> V_57 -- ;
F_27 ( V_19 ) ;
F_24 ( & V_19 -> V_56 ) ;
return F_28 ( V_21 ) ;
}
static int F_29 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
F_23 ( & V_19 -> V_56 ) ;
if ( V_21 -> V_23 -> V_53 -> V_54 != V_55 )
V_19 -> V_57 -- ;
F_27 ( V_19 ) ;
F_24 ( & V_19 -> V_56 ) ;
return F_28 ( V_21 ) ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
struct V_22 * V_23 = V_21 -> V_23 ;
int V_28 ;
F_23 ( & V_19 -> V_56 ) ;
V_28 = F_31 ( V_19 , V_23 -> V_45 ) ;
if ( V_28 >= 0 )
F_32 ( & V_19 -> V_33 ) ;
F_24 ( & V_19 -> V_56 ) ;
return V_28 ;
}
static int F_33 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
struct V_22 * V_23 = V_21 -> V_23 ;
int V_28 ;
F_23 ( & V_19 -> V_56 ) ;
V_28 = F_31 ( V_19 , V_23 -> V_45 ) ;
if ( V_28 >= 0 ) {
F_32 ( & V_19 -> V_34 ) ;
F_34 ( & V_19 -> V_34 ) ;
}
F_24 ( & V_19 -> V_56 ) ;
return V_28 ;
}
static int F_35 ( struct V_20 * V_21 , int V_58 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
switch ( V_58 ) {
case V_59 :
F_36 ( & V_19 -> V_33 , V_21 ) ;
break;
case V_60 :
F_36 ( & V_19 -> V_33 , NULL ) ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_37 ( struct V_20 * V_21 , int V_58 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
switch ( V_58 ) {
case V_59 :
F_36 ( & V_19 -> V_34 , V_21 ) ;
break;
case V_60 :
F_36 ( & V_19 -> V_34 , NULL ) ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static T_1 F_38 ( struct V_20 * V_62 )
{
struct V_18 * V_19 = V_62 -> V_42 ;
return F_39 ( & V_19 -> V_33 ) ;
}
static T_1 F_40 ( struct V_20 * V_62 )
{
struct V_18 * V_19 = V_62 -> V_42 ;
return F_39 ( & V_19 -> V_34 ) ;
}
static int F_41 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
return F_42 ( & V_19 -> V_33 ) ;
}
static int F_43 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_42 ;
return F_42 ( & V_19 -> V_34 ) ;
}
int F_44 ( struct V_18 * V_19 )
{
static const struct V_63 V_64 = {
. V_65 = F_11 ,
. V_66 = F_19 ,
. V_67 = V_68 ,
. V_52 = F_20 ,
. V_69 = F_26 ,
. V_70 = F_30 ,
. V_71 = F_35 ,
. V_72 = F_38 ,
. V_73 = F_41 ,
. V_74 = V_75 ,
} ;
static const struct V_63 V_76 = {
. V_65 = F_11 ,
. V_66 = F_19 ,
. V_67 = V_68 ,
. V_52 = F_25 ,
. V_69 = F_29 ,
. V_70 = F_33 ,
. V_71 = F_37 ,
. V_72 = F_40 ,
. V_73 = F_43 ,
. V_74 = V_75 ,
. V_77 = V_78 ,
} ;
struct V_79 * V_80 ;
int V_28 ;
V_28 = F_45 ( V_19 -> V_81 , V_19 -> V_81 -> V_82 , 0 , 1 , 1 , & V_80 ) ;
if ( V_28 < 0 )
return V_28 ;
V_80 -> V_42 = V_19 ;
snprintf ( V_80 -> V_83 , sizeof( V_80 -> V_83 ) ,
L_1 , V_19 -> V_81 -> V_84 ) ;
F_46 ( V_80 , V_85 , & V_76 ) ;
F_46 ( V_80 , V_30 , & V_64 ) ;
return 0 ;
}
