static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 =
F_2 ( V_2 , V_10 ) ;
struct V_8 * V_11 =
F_3 ( V_2 , V_12 ) ;
struct V_8 V_13 = {
. V_14 = V_15 , . V_16 = 0 , . integer = 1
} ;
unsigned int V_17 , V_18 , V_19 , V_20 ;
for ( V_17 = 0 ; V_17 < F_4 ( V_21 ) ; ++ V_17 ) {
V_19 = V_21 [ V_17 ] ;
V_20 = V_17 / 2 ;
V_18 = V_6 -> V_22 [ V_20 ] +
V_6 -> V_23 [ V_20 ] ;
if ( ! F_5 ( V_9 , V_18 ) )
continue;
V_13 . V_14 = V_14 ( V_13 . V_14 , V_19 ) ;
V_13 . V_16 = V_16 ( V_13 . V_16 , V_19 ) ;
}
return F_6 ( V_11 , & V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_11 =
F_2 ( V_2 , V_12 ) ;
struct V_8 * V_9 =
F_3 ( V_2 , V_10 ) ;
struct V_8 V_24 = {
. V_14 = V_15 , . V_16 = 0 , . integer = 1
} ;
unsigned int V_17 , V_18 , V_19 , V_20 ;
for ( V_17 = 0 ; V_17 < F_4 ( V_21 ) ; ++ V_17 ) {
V_19 = V_21 [ V_17 ] ;
V_20 = V_17 / 2 ;
if ( ! F_5 ( V_11 , V_19 ) )
continue;
V_18 = V_6 -> V_22 [ V_20 ] +
V_6 -> V_23 [ V_20 ] ;
V_24 . V_14 = V_14 ( V_24 . V_14 , V_18 ) ;
V_24 . V_16 = V_16 ( V_24 . V_16 , V_18 ) ;
}
return F_6 ( V_9 , & V_24 ) ;
}
static void F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_29 * V_30 = & V_28 -> V_30 ;
unsigned int V_17 , V_18 , V_19 , V_20 ;
V_30 -> V_31 = V_15 ;
V_30 -> V_32 = 0 ;
for ( V_17 = 0 ; V_17 < F_4 ( V_21 ) ; ++ V_17 ) {
V_19 = V_21 [ V_17 ] ;
V_20 = V_17 / 2 ;
V_18 = V_6 -> V_22 [ V_20 ] +
V_6 -> V_23 [ V_20 ] ;
if ( V_18 == 0 )
continue;
V_30 -> V_13 |= F_9 ( V_19 ) ;
V_30 -> V_31 = V_14 ( V_30 -> V_31 , V_18 ) ;
V_30 -> V_32 = V_16 ( V_30 -> V_32 , V_18 ) ;
}
F_10 ( V_28 ) ;
}
static void F_11 ( struct V_29 * V_30 )
{
V_30 -> V_33 = 2 ;
V_30 -> V_34 = V_15 ;
V_30 -> V_35 = 4 * V_30 -> V_32 ;
V_30 -> V_36 = V_30 -> V_35 * 2048 ;
V_30 -> V_37 = V_30 -> V_36 * V_30 -> V_33 ;
}
static int F_12 ( struct V_25 * V_26 ,
struct V_38 * V_39 )
{
struct V_27 * V_28 = V_39 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_30 ;
struct V_40 * V_41 ;
struct V_5 * V_6 ;
int V_42 ;
V_30 -> V_43 = V_44 |
V_45 |
V_46 |
V_47 |
V_48 |
V_49 ;
if ( V_39 -> V_41 == V_50 ) {
V_30 -> V_6 = V_51 ;
V_41 = & V_26 -> V_52 ;
V_6 = & V_26 -> V_53 ;
} else {
V_30 -> V_6 = V_51 ;
V_41 = & V_26 -> V_54 ;
V_6 = & V_26 -> V_55 ;
}
F_8 ( V_26 , V_28 , V_6 ) ;
F_11 ( V_30 ) ;
V_42 = F_13 ( V_28 , 0 , V_12 ,
F_1 , V_6 ,
V_10 , - 1 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_13 ( V_28 , 0 , V_10 ,
F_7 , V_6 ,
V_12 , - 1 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_14 ( V_41 , V_28 ) ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
const struct V_57 * const V_58 = V_26 -> V_59 -> V_58 ;
enum V_60 V_61 ;
unsigned int V_19 ;
int V_42 ;
V_42 = F_16 ( V_26 ) ;
if ( V_42 < 0 )
return V_42 ;
F_17 ( & V_26 -> V_62 ) ;
V_42 = V_58 -> V_63 ( V_26 ) ;
if ( V_42 < 0 )
goto V_64;
V_42 = F_12 ( V_26 , V_39 ) ;
if ( V_42 < 0 )
goto V_64;
V_42 = V_58 -> V_65 ( V_26 , & V_61 ) ;
if ( V_42 < 0 )
goto V_64;
if ( V_61 != V_66 ||
F_18 ( & V_26 -> V_52 ) ||
F_18 ( & V_26 -> V_54 ) ) {
V_42 = V_58 -> V_67 ( V_26 , & V_19 ) ;
if ( V_42 < 0 )
goto V_64;
V_39 -> V_28 -> V_30 . V_68 = V_19 ;
V_39 -> V_28 -> V_30 . V_69 = V_19 ;
}
F_19 ( V_39 ) ;
F_20 ( & V_26 -> V_62 ) ;
return V_42 ;
V_64:
F_20 ( & V_26 -> V_62 ) ;
F_21 ( V_26 ) ;
return V_42 ;
}
static int F_22 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
F_21 ( V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 ,
struct V_1 * V_70 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
int V_42 ;
V_42 = F_24 ( V_39 ,
F_25 ( V_70 ) ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_39 -> V_28 -> V_71 -> V_72 == V_73 ) {
F_17 ( & V_26 -> V_62 ) ;
V_26 -> V_74 ++ ;
F_20 ( & V_26 -> V_62 ) ;
}
return 0 ;
}
static int F_26 ( struct V_38 * V_39 ,
struct V_1 * V_70 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
int V_42 ;
V_42 = F_24 ( V_39 ,
F_25 ( V_70 ) ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_39 -> V_28 -> V_71 -> V_72 == V_73 ) {
F_17 ( & V_26 -> V_62 ) ;
V_26 -> V_75 ++ ;
F_20 ( & V_26 -> V_62 ) ;
}
return 0 ;
}
static int F_27 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
F_17 ( & V_26 -> V_62 ) ;
if ( V_39 -> V_28 -> V_71 -> V_72 != V_73 )
V_26 -> V_74 -- ;
F_28 ( V_26 ) ;
F_20 ( & V_26 -> V_62 ) ;
return F_29 ( V_39 ) ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
F_17 ( & V_26 -> V_62 ) ;
if ( V_39 -> V_28 -> V_71 -> V_72 != V_73 )
V_26 -> V_75 -- ;
F_28 ( V_26 ) ;
F_20 ( & V_26 -> V_62 ) ;
return F_29 ( V_39 ) ;
}
static int F_31 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
int V_42 ;
F_17 ( & V_26 -> V_62 ) ;
V_42 = F_32 ( V_26 , V_39 -> V_28 -> V_19 ) ;
F_20 ( & V_26 -> V_62 ) ;
if ( V_42 >= 0 )
F_33 ( & V_26 -> V_52 ) ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
int V_42 ;
F_17 ( & V_26 -> V_62 ) ;
V_42 = F_32 ( V_26 , V_39 -> V_28 -> V_19 ) ;
F_20 ( & V_26 -> V_62 ) ;
if ( V_42 >= 0 )
F_33 ( & V_26 -> V_54 ) ;
return V_42 ;
}
static int F_35 ( struct V_38 * V_39 , int V_76 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
switch ( V_76 ) {
case V_77 :
F_36 ( & V_26 -> V_52 , V_39 ) ;
break;
case V_78 :
F_36 ( & V_26 -> V_52 , NULL ) ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_37 ( struct V_38 * V_39 , int V_76 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
switch ( V_76 ) {
case V_77 :
F_36 ( & V_26 -> V_54 , V_39 ) ;
break;
case V_78 :
F_36 ( & V_26 -> V_54 , NULL ) ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static T_1 F_38 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
return F_39 ( & V_26 -> V_52 ) ;
}
static T_1 F_40 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_56 ;
return F_39 ( & V_26 -> V_54 ) ;
}
int F_41 ( struct V_25 * V_26 )
{
static struct V_80 V_81 = {
. V_82 = F_15 ,
. V_83 = F_22 ,
. V_84 = V_85 ,
. V_70 = F_23 ,
. V_86 = F_27 ,
. V_87 = F_31 ,
. V_88 = F_35 ,
. V_89 = F_38 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
} ;
static struct V_80 V_94 = {
. V_82 = F_15 ,
. V_83 = F_22 ,
. V_84 = V_85 ,
. V_70 = F_26 ,
. V_86 = F_30 ,
. V_87 = F_34 ,
. V_88 = F_37 ,
. V_89 = F_40 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
} ;
struct V_95 * V_96 ;
int V_42 ;
V_42 = F_42 ( V_26 -> V_97 , V_26 -> V_97 -> V_98 , 0 , 1 , 1 , & V_96 ) ;
if ( V_42 < 0 )
return V_42 ;
V_96 -> V_56 = V_26 ;
strcpy ( V_96 -> V_99 , V_26 -> V_97 -> V_100 ) ;
F_43 ( V_96 , V_50 , & V_81 ) ;
F_43 ( V_96 , V_101 , & V_94 ) ;
return 0 ;
}
