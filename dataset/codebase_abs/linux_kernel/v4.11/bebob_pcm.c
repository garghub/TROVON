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
static void
F_9 ( struct V_21 * V_22 )
{
V_22 -> V_28 = 2 ;
V_22 -> V_29 = V_15 ;
V_22 -> V_30 = 4 * V_22 -> V_24 ;
V_22 -> V_31 = V_22 -> V_30 * 2048 ;
V_22 -> V_32 = V_22 -> V_31 * V_22 -> V_28 ;
}
static int
F_10 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_39 * V_40 ;
struct V_5 * V_6 ;
int V_41 ;
V_38 -> V_22 . V_42 = V_43 |
V_44 |
V_45 |
V_46 |
V_47 |
V_48 ;
if ( V_36 -> V_49 == V_50 ) {
V_38 -> V_22 . V_51 = V_52 ;
V_40 = & V_34 -> V_53 ;
V_6 = V_34 -> V_54 ;
} else {
V_38 -> V_22 . V_51 = V_55 ;
V_40 = & V_34 -> V_56 ;
V_6 = V_34 -> V_57 ;
}
F_7 ( & V_38 -> V_22 , V_6 ) ;
F_9 ( & V_38 -> V_22 ) ;
V_41 = F_11 ( V_38 , 0 , V_12 ,
F_6 , V_6 ,
V_10 , - 1 ) ;
if ( V_41 < 0 )
goto V_58;
V_41 = F_11 ( V_38 , 0 , V_10 ,
F_1 , V_6 ,
V_12 , - 1 ) ;
if ( V_41 < 0 )
goto V_58;
V_41 = F_12 ( V_40 , V_38 ) ;
V_58:
return V_41 ;
}
static int
F_13 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
const struct V_60 * V_61 = V_34 -> V_61 -> V_62 ;
unsigned int V_63 ;
enum V_64 V_65 ;
int V_41 ;
V_41 = F_14 ( V_34 ) ;
if ( V_41 < 0 )
goto V_58;
V_41 = F_10 ( V_34 , V_36 ) ;
if ( V_41 < 0 )
goto V_66;
V_41 = F_15 ( V_34 , & V_65 ) ;
if ( V_41 < 0 )
goto V_66;
if ( V_65 == V_67 ||
F_16 ( & V_34 -> V_53 ) ||
F_16 ( & V_34 -> V_56 ) ) {
V_41 = V_61 -> V_68 ( V_34 , & V_63 ) ;
if ( V_41 < 0 ) {
F_17 ( & V_34 -> V_69 -> V_70 ,
L_1 , V_41 ) ;
goto V_66;
}
V_36 -> V_38 -> V_22 . V_25 = V_63 ;
V_36 -> V_38 -> V_22 . V_26 = V_63 ;
}
F_18 ( V_36 ) ;
V_58:
return V_41 ;
V_66:
F_19 ( V_34 ) ;
return V_41 ;
}
static int
F_20 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
F_19 ( V_34 ) ;
return 0 ;
}
static int
F_21 ( struct V_35 * V_36 ,
struct V_1 * V_71 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
int V_41 ;
V_41 = F_22 ( V_36 ,
F_23 ( V_71 ) ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_36 -> V_38 -> V_72 -> V_73 == V_74 ) {
F_24 ( & V_34 -> V_75 ) ;
V_34 -> V_76 ++ ;
F_25 ( & V_34 -> V_75 ) ;
}
F_26 ( & V_34 -> V_53 , F_27 ( V_71 ) ) ;
return 0 ;
}
static int
F_28 ( struct V_35 * V_36 ,
struct V_1 * V_71 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
int V_41 ;
V_41 = F_22 ( V_36 ,
F_23 ( V_71 ) ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_36 -> V_38 -> V_72 -> V_73 == V_74 ) {
F_24 ( & V_34 -> V_75 ) ;
V_34 -> V_76 ++ ;
F_25 ( & V_34 -> V_75 ) ;
}
F_26 ( & V_34 -> V_56 , F_27 ( V_71 ) ) ;
return 0 ;
}
static int
F_29 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
if ( V_36 -> V_38 -> V_72 -> V_73 != V_74 ) {
F_24 ( & V_34 -> V_75 ) ;
V_34 -> V_76 -- ;
F_25 ( & V_34 -> V_75 ) ;
}
F_30 ( V_34 ) ;
return F_31 ( V_36 ) ;
}
static int
F_32 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
if ( V_36 -> V_38 -> V_72 -> V_73 != V_74 ) {
F_24 ( & V_34 -> V_75 ) ;
V_34 -> V_76 -- ;
F_25 ( & V_34 -> V_75 ) ;
}
F_30 ( V_34 ) ;
return F_31 ( V_36 ) ;
}
static int
F_33 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
struct V_37 * V_38 = V_36 -> V_38 ;
int V_41 ;
V_41 = F_34 ( V_34 , V_38 -> V_62 ) ;
if ( V_41 >= 0 )
F_35 ( & V_34 -> V_53 ) ;
return V_41 ;
}
static int
F_36 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
struct V_37 * V_38 = V_36 -> V_38 ;
int V_41 ;
V_41 = F_34 ( V_34 , V_38 -> V_62 ) ;
if ( V_41 >= 0 )
F_35 ( & V_34 -> V_56 ) ;
return V_41 ;
}
static int
F_37 ( struct V_35 * V_36 , int V_77 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
switch ( V_77 ) {
case V_78 :
F_38 ( & V_34 -> V_53 , V_36 ) ;
break;
case V_79 :
F_38 ( & V_34 -> V_53 , NULL ) ;
break;
default:
return - V_80 ;
}
return 0 ;
}
static int
F_39 ( struct V_35 * V_36 , int V_77 )
{
struct V_33 * V_34 = V_36 -> V_59 ;
switch ( V_77 ) {
case V_78 :
F_38 ( & V_34 -> V_56 , V_36 ) ;
break;
case V_79 :
F_38 ( & V_34 -> V_56 , NULL ) ;
break;
default:
return - V_80 ;
}
return 0 ;
}
static T_1
F_40 ( struct V_35 * V_81 )
{
struct V_33 * V_34 = V_81 -> V_59 ;
return F_41 ( & V_34 -> V_53 ) ;
}
static T_1
F_42 ( struct V_35 * V_81 )
{
struct V_33 * V_34 = V_81 -> V_59 ;
return F_41 ( & V_34 -> V_56 ) ;
}
int F_43 ( struct V_33 * V_34 )
{
static const struct V_82 V_83 = {
. V_84 = F_13 ,
. V_85 = F_20 ,
. V_86 = V_87 ,
. V_71 = F_21 ,
. V_88 = F_29 ,
. V_89 = F_33 ,
. V_90 = F_37 ,
. V_91 = F_40 ,
. V_92 = V_93 ,
} ;
static const struct V_82 V_94 = {
. V_84 = F_13 ,
. V_85 = F_20 ,
. V_86 = V_87 ,
. V_71 = F_28 ,
. V_88 = F_32 ,
. V_89 = F_36 ,
. V_90 = F_39 ,
. V_91 = F_42 ,
. V_92 = V_93 ,
. V_95 = V_96 ,
} ;
struct V_97 * V_19 ;
int V_41 ;
V_41 = F_44 ( V_34 -> V_98 , V_34 -> V_98 -> V_99 , 0 , 1 , 1 , & V_19 ) ;
if ( V_41 < 0 )
goto V_58;
V_19 -> V_59 = V_34 ;
snprintf ( V_19 -> V_100 , sizeof( V_19 -> V_100 ) ,
L_2 , V_34 -> V_98 -> V_101 ) ;
F_45 ( V_19 , V_102 , & V_94 ) ;
F_45 ( V_19 , V_50 , & V_83 ) ;
V_58:
return V_41 ;
}
