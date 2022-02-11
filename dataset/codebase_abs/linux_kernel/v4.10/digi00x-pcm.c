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
static const struct V_22 V_23 = {
. V_24 = V_25 |
V_26 |
V_27 |
V_28 |
V_29 |
V_30 ,
. V_31 = V_32 |
V_33 |
V_34 |
V_35 ,
. V_36 = 44100 ,
. V_37 = 96000 ,
. V_38 = 10 ,
. V_39 = 18 ,
. V_40 = 4 * 18 ,
. V_41 = 4 * 18 * 2048 ,
. V_42 = 4 * 18 * 2048 * 2 ,
. V_43 = 2 ,
. V_44 = V_12 ,
} ;
struct V_45 * V_46 ;
int V_47 ;
V_21 -> V_48 -> V_49 = V_23 ;
if ( V_21 -> V_50 == V_51 ) {
V_21 -> V_48 -> V_49 . V_52 = V_53 ;
V_46 = & V_19 -> V_54 ;
} else {
V_21 -> V_48 -> V_49 . V_52 = V_55 |
V_53 ;
V_46 = & V_19 -> V_56 ;
}
V_47 = F_8 ( V_21 -> V_48 , 0 ,
V_9 ,
F_6 , NULL ,
V_7 , - 1 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_8 ( V_21 -> V_48 , 0 ,
V_7 ,
F_1 , NULL ,
V_9 , - 1 ) ;
if ( V_47 < 0 )
return V_47 ;
return F_9 ( V_46 , V_21 -> V_48 ) ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
enum V_58 clock ;
bool V_59 ;
unsigned int V_60 ;
int V_47 ;
V_47 = F_11 ( V_19 ) ;
if ( V_47 < 0 )
goto V_61;
V_47 = F_7 ( V_19 , V_21 ) ;
if ( V_47 < 0 )
goto V_62;
V_47 = F_12 ( V_19 , & clock ) ;
if ( V_47 < 0 )
goto V_62;
if ( clock != V_63 ) {
V_47 = F_13 ( V_19 , & V_59 ) ;
if ( V_47 < 0 )
goto V_62;
if ( ! V_59 ) {
V_47 = - V_64 ;
goto V_62;
}
}
if ( ( clock != V_63 ) ||
F_14 ( & V_19 -> V_56 ) ||
F_14 ( & V_19 -> V_54 ) ) {
V_47 = F_15 ( V_19 , & V_60 ) ;
if ( V_47 < 0 )
goto V_62;
V_21 -> V_48 -> V_49 . V_36 = V_60 ;
V_21 -> V_48 -> V_49 . V_37 = V_60 ;
}
F_16 ( V_21 ) ;
V_61:
return V_47 ;
V_62:
F_17 ( V_19 ) ;
return V_47 ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
F_17 ( V_19 ) ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_1 * V_65 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
int V_47 ;
V_47 = F_20 ( V_21 ,
F_21 ( V_65 ) ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_21 -> V_48 -> V_66 -> V_67 == V_68 ) {
F_22 ( & V_19 -> V_69 ) ;
V_19 -> V_70 ++ ;
F_23 ( & V_19 -> V_69 ) ;
}
F_24 ( & V_19 -> V_54 , F_25 ( V_65 ) ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_21 ,
struct V_1 * V_65 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
int V_47 ;
V_47 = F_20 ( V_21 ,
F_21 ( V_65 ) ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_21 -> V_48 -> V_66 -> V_67 == V_68 ) {
F_22 ( & V_19 -> V_69 ) ;
V_19 -> V_70 ++ ;
F_23 ( & V_19 -> V_69 ) ;
}
F_24 ( & V_19 -> V_56 , F_25 ( V_65 ) ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
F_22 ( & V_19 -> V_69 ) ;
if ( V_21 -> V_48 -> V_66 -> V_67 != V_68 )
V_19 -> V_70 -- ;
F_28 ( V_19 ) ;
F_23 ( & V_19 -> V_69 ) ;
return F_29 ( V_21 ) ;
}
static int F_30 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
F_22 ( & V_19 -> V_69 ) ;
if ( V_21 -> V_48 -> V_66 -> V_67 != V_68 )
V_19 -> V_70 -- ;
F_28 ( V_19 ) ;
F_23 ( & V_19 -> V_69 ) ;
return F_29 ( V_21 ) ;
}
static int F_31 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
struct V_71 * V_48 = V_21 -> V_48 ;
int V_47 ;
F_22 ( & V_19 -> V_69 ) ;
V_47 = F_32 ( V_19 , V_48 -> V_60 ) ;
if ( V_47 >= 0 )
F_33 ( & V_19 -> V_54 ) ;
F_23 ( & V_19 -> V_69 ) ;
return V_47 ;
}
static int F_34 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
struct V_71 * V_48 = V_21 -> V_48 ;
int V_47 ;
F_22 ( & V_19 -> V_69 ) ;
V_47 = F_32 ( V_19 , V_48 -> V_60 ) ;
if ( V_47 >= 0 ) {
F_33 ( & V_19 -> V_56 ) ;
F_35 ( & V_19 -> V_56 ) ;
}
F_23 ( & V_19 -> V_69 ) ;
return V_47 ;
}
static int F_36 ( struct V_20 * V_21 , int V_72 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
switch ( V_72 ) {
case V_73 :
F_37 ( & V_19 -> V_54 , V_21 ) ;
break;
case V_74 :
F_37 ( & V_19 -> V_54 , NULL ) ;
break;
default:
return - V_75 ;
}
return 0 ;
}
static int F_38 ( struct V_20 * V_21 , int V_72 )
{
struct V_18 * V_19 = V_21 -> V_57 ;
switch ( V_72 ) {
case V_73 :
F_37 ( & V_19 -> V_56 , V_21 ) ;
break;
case V_74 :
F_37 ( & V_19 -> V_56 , NULL ) ;
break;
default:
return - V_75 ;
}
return 0 ;
}
static T_1 F_39 ( struct V_20 * V_76 )
{
struct V_18 * V_19 = V_76 -> V_57 ;
return F_40 ( & V_19 -> V_54 ) ;
}
static T_1 F_41 ( struct V_20 * V_76 )
{
struct V_18 * V_19 = V_76 -> V_57 ;
return F_40 ( & V_19 -> V_56 ) ;
}
int F_42 ( struct V_18 * V_19 )
{
struct V_77 * V_78 ;
int V_47 ;
V_47 = F_43 ( V_19 -> V_79 , V_19 -> V_79 -> V_80 , 0 , 1 , 1 , & V_78 ) ;
if ( V_47 < 0 )
return V_47 ;
V_78 -> V_57 = V_19 ;
snprintf ( V_78 -> V_81 , sizeof( V_78 -> V_81 ) ,
L_1 , V_19 -> V_79 -> V_82 ) ;
F_44 ( V_78 , V_83 , & V_84 ) ;
F_44 ( V_78 , V_51 , & V_85 ) ;
return 0 ;
}
