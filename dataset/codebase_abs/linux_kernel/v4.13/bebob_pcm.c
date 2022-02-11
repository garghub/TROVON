static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_2 , V_10 ) ;
const struct V_8 * V_11 =
F_3 ( V_2 , V_12 ) ;
struct V_8 V_13 = {
. V_14 = V_15 , . V_16 = 0 , . integer = 1
} ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_6 [ V_17 ] . V_19 == 0 )
continue;
if ( ! F_4 ( V_11 , V_6 [ V_17 ] . V_19 ) )
continue;
V_13 . V_14 = V_14 ( V_13 . V_14 , V_20 [ V_17 ] ) ;
V_13 . V_16 = V_16 ( V_13 . V_16 , V_20 [ V_17 ] ) ;
}
return F_5 ( V_9 , & V_13 ) ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_11 =
F_2 ( V_2 , V_12 ) ;
const struct V_8 * V_9 =
F_3 ( V_2 , V_10 ) ;
struct V_8 V_13 = {
. V_14 = V_15 , . V_16 = 0 , . integer = 1
} ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_6 [ V_17 ] . V_19 == 0 )
continue;
if ( ! F_4 ( V_9 , V_20 [ V_17 ] ) )
continue;
V_13 . V_14 = V_14 ( V_13 . V_14 , V_6 [ V_17 ] . V_19 ) ;
V_13 . V_16 = V_16 ( V_13 . V_16 , V_6 [ V_17 ] . V_19 ) ;
}
return F_5 ( V_11 , & V_13 ) ;
}
static void
F_7 ( struct V_21 * V_22 ,
struct V_5 * V_6 )
{
unsigned int V_17 ;
V_22 -> V_23 = V_15 ;
V_22 -> V_24 = 0 ;
V_22 -> V_25 = V_15 ;
V_22 -> V_26 = 0 ;
V_22 -> V_27 = 0 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_6 [ V_17 ] . V_19 == 0 )
continue;
V_22 -> V_23 = V_14 ( V_22 -> V_23 , V_6 [ V_17 ] . V_19 ) ;
V_22 -> V_24 = V_16 ( V_22 -> V_24 , V_6 [ V_17 ] . V_19 ) ;
V_22 -> V_25 = V_14 ( V_22 -> V_25 , V_20 [ V_17 ] ) ;
V_22 -> V_26 = V_16 ( V_22 -> V_26 , V_20 [ V_17 ] ) ;
V_22 -> V_27 |= F_8 ( V_20 [ V_17 ] ) ;
}
}
static int
F_9 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_34 * V_35 ;
struct V_5 * V_6 ;
int V_36 ;
if ( V_31 -> V_37 == V_38 ) {
V_33 -> V_22 . V_39 = V_40 ;
V_35 = & V_29 -> V_41 ;
V_6 = V_29 -> V_42 ;
} else {
V_33 -> V_22 . V_39 = V_43 ;
V_35 = & V_29 -> V_44 ;
V_6 = V_29 -> V_45 ;
}
F_7 ( & V_33 -> V_22 , V_6 ) ;
V_36 = F_10 ( V_33 , 0 , V_12 ,
F_6 , V_6 ,
V_10 , - 1 ) ;
if ( V_36 < 0 )
goto V_46;
V_36 = F_10 ( V_33 , 0 , V_10 ,
F_1 , V_6 ,
V_12 , - 1 ) ;
if ( V_36 < 0 )
goto V_46;
V_36 = F_11 ( V_35 , V_33 ) ;
V_46:
return V_36 ;
}
static int
F_12 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
const struct V_48 * V_49 = V_29 -> V_49 -> V_50 ;
unsigned int V_51 ;
enum V_52 V_53 ;
int V_36 ;
V_36 = F_13 ( V_29 ) ;
if ( V_36 < 0 )
goto V_46;
V_36 = F_9 ( V_29 , V_31 ) ;
if ( V_36 < 0 )
goto V_54;
V_36 = F_14 ( V_29 , & V_53 ) ;
if ( V_36 < 0 )
goto V_54;
if ( V_53 == V_55 ||
F_15 ( & V_29 -> V_41 ) ||
F_15 ( & V_29 -> V_44 ) ) {
V_36 = V_49 -> V_56 ( V_29 , & V_51 ) ;
if ( V_36 < 0 ) {
F_16 ( & V_29 -> V_57 -> V_58 ,
L_1 , V_36 ) ;
goto V_54;
}
V_31 -> V_33 -> V_22 . V_25 = V_51 ;
V_31 -> V_33 -> V_22 . V_26 = V_51 ;
}
F_17 ( V_31 ) ;
V_46:
return V_36 ;
V_54:
F_18 ( V_29 ) ;
return V_36 ;
}
static int
F_19 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
F_18 ( V_29 ) ;
return 0 ;
}
static int
F_20 ( struct V_30 * V_31 ,
struct V_1 * V_59 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
int V_36 ;
V_36 = F_21 ( V_31 ,
F_22 ( V_59 ) ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_31 -> V_33 -> V_60 -> V_61 == V_62 ) {
F_23 ( & V_29 -> V_63 ) ;
V_29 -> V_64 ++ ;
F_24 ( & V_29 -> V_63 ) ;
}
return 0 ;
}
static int
F_25 ( struct V_30 * V_31 ,
struct V_1 * V_59 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
int V_36 ;
V_36 = F_21 ( V_31 ,
F_22 ( V_59 ) ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_31 -> V_33 -> V_60 -> V_61 == V_62 ) {
F_23 ( & V_29 -> V_63 ) ;
V_29 -> V_64 ++ ;
F_24 ( & V_29 -> V_63 ) ;
}
return 0 ;
}
static int
F_26 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
if ( V_31 -> V_33 -> V_60 -> V_61 != V_62 ) {
F_23 ( & V_29 -> V_63 ) ;
V_29 -> V_64 -- ;
F_24 ( & V_29 -> V_63 ) ;
}
F_27 ( V_29 ) ;
return F_28 ( V_31 ) ;
}
static int
F_29 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
if ( V_31 -> V_33 -> V_60 -> V_61 != V_62 ) {
F_23 ( & V_29 -> V_63 ) ;
V_29 -> V_64 -- ;
F_24 ( & V_29 -> V_63 ) ;
}
F_27 ( V_29 ) ;
return F_28 ( V_31 ) ;
}
static int
F_30 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
struct V_32 * V_33 = V_31 -> V_33 ;
int V_36 ;
V_36 = F_31 ( V_29 , V_33 -> V_50 ) ;
if ( V_36 >= 0 )
F_32 ( & V_29 -> V_41 ) ;
return V_36 ;
}
static int
F_33 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
struct V_32 * V_33 = V_31 -> V_33 ;
int V_36 ;
V_36 = F_31 ( V_29 , V_33 -> V_50 ) ;
if ( V_36 >= 0 )
F_32 ( & V_29 -> V_44 ) ;
return V_36 ;
}
static int
F_34 ( struct V_30 * V_31 , int V_65 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
switch ( V_65 ) {
case V_66 :
F_35 ( & V_29 -> V_41 , V_31 ) ;
break;
case V_67 :
F_35 ( & V_29 -> V_41 , NULL ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static int
F_36 ( struct V_30 * V_31 , int V_65 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
switch ( V_65 ) {
case V_66 :
F_35 ( & V_29 -> V_44 , V_31 ) ;
break;
case V_67 :
F_35 ( & V_29 -> V_44 , NULL ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static T_1
F_37 ( struct V_30 * V_69 )
{
struct V_28 * V_29 = V_69 -> V_47 ;
return F_38 ( & V_29 -> V_41 ) ;
}
static T_1
F_39 ( struct V_30 * V_69 )
{
struct V_28 * V_29 = V_69 -> V_47 ;
return F_38 ( & V_29 -> V_44 ) ;
}
static int F_40 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
return F_41 ( & V_29 -> V_41 ) ;
}
static int F_42 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_47 ;
return F_41 ( & V_29 -> V_44 ) ;
}
int F_43 ( struct V_28 * V_29 )
{
static const struct V_70 V_71 = {
. V_72 = F_12 ,
. V_73 = F_19 ,
. V_74 = V_75 ,
. V_59 = F_20 ,
. V_76 = F_26 ,
. V_77 = F_30 ,
. V_78 = F_34 ,
. V_79 = F_37 ,
. V_80 = F_40 ,
. V_81 = V_82 ,
} ;
static const struct V_70 V_83 = {
. V_72 = F_12 ,
. V_73 = F_19 ,
. V_74 = V_75 ,
. V_59 = F_25 ,
. V_76 = F_29 ,
. V_77 = F_33 ,
. V_78 = F_36 ,
. V_79 = F_39 ,
. V_80 = F_42 ,
. V_81 = V_82 ,
. V_84 = V_85 ,
} ;
struct V_86 * V_19 ;
int V_36 ;
V_36 = F_44 ( V_29 -> V_87 , V_29 -> V_87 -> V_88 , 0 , 1 , 1 , & V_19 ) ;
if ( V_36 < 0 )
goto V_46;
V_19 -> V_47 = V_29 ;
snprintf ( V_19 -> V_89 , sizeof( V_19 -> V_89 ) ,
L_2 , V_29 -> V_87 -> V_90 ) ;
F_45 ( V_19 , V_91 , & V_83 ) ;
F_45 ( V_19 , V_38 , & V_71 ) ;
V_46:
return V_36 ;
}
