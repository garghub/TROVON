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
static int F_11 ( struct V_25 * V_26 ,
struct V_33 * V_34 )
{
struct V_27 * V_28 = V_34 -> V_28 ;
struct V_29 * V_30 = & V_28 -> V_30 ;
struct V_35 * V_36 ;
struct V_5 * V_6 ;
int V_37 ;
if ( V_34 -> V_36 == V_38 ) {
V_30 -> V_6 = V_39 ;
V_36 = & V_26 -> V_40 ;
V_6 = & V_26 -> V_41 ;
} else {
V_30 -> V_6 = V_39 ;
V_36 = & V_26 -> V_42 ;
V_6 = & V_26 -> V_43 ;
}
F_8 ( V_26 , V_28 , V_6 ) ;
V_37 = F_12 ( V_28 , 0 , V_12 ,
F_1 , V_6 ,
V_10 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_12 ( V_28 , 0 , V_10 ,
F_7 , V_6 ,
V_12 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_13 ( V_36 , V_28 ) ;
}
static int F_14 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
const struct V_45 * const V_46 = V_26 -> V_47 -> V_46 ;
enum V_48 V_49 ;
unsigned int V_19 ;
int V_37 ;
V_37 = F_15 ( V_26 ) ;
if ( V_37 < 0 )
return V_37 ;
F_16 ( & V_26 -> V_50 ) ;
V_37 = F_17 ( V_26 ) ;
if ( V_37 < 0 )
goto V_51;
V_37 = F_11 ( V_26 , V_34 ) ;
if ( V_37 < 0 )
goto V_51;
V_37 = V_46 -> V_52 ( V_26 , & V_49 ) ;
if ( V_37 < 0 )
goto V_51;
if ( V_49 != V_53 ||
F_18 ( & V_26 -> V_40 ) ||
F_18 ( & V_26 -> V_42 ) ) {
V_37 = V_46 -> V_54 ( V_26 , & V_19 ) ;
if ( V_37 < 0 )
goto V_51;
V_34 -> V_28 -> V_30 . V_55 = V_19 ;
V_34 -> V_28 -> V_30 . V_56 = V_19 ;
}
F_19 ( V_34 ) ;
F_20 ( & V_26 -> V_50 ) ;
return V_37 ;
V_51:
F_20 ( & V_26 -> V_50 ) ;
F_21 ( V_26 ) ;
return V_37 ;
}
static int F_22 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
F_21 ( V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 ,
struct V_1 * V_57 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
V_37 = F_24 ( V_34 ,
F_25 ( V_57 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_34 -> V_28 -> V_58 -> V_59 == V_60 ) {
F_16 ( & V_26 -> V_50 ) ;
V_26 -> V_61 ++ ;
F_20 ( & V_26 -> V_50 ) ;
}
return 0 ;
}
static int F_26 ( struct V_33 * V_34 ,
struct V_1 * V_57 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
V_37 = F_24 ( V_34 ,
F_25 ( V_57 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_34 -> V_28 -> V_58 -> V_59 == V_60 ) {
F_16 ( & V_26 -> V_50 ) ;
V_26 -> V_62 ++ ;
F_20 ( & V_26 -> V_50 ) ;
}
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
F_16 ( & V_26 -> V_50 ) ;
if ( V_34 -> V_28 -> V_58 -> V_59 != V_60 )
V_26 -> V_61 -- ;
F_28 ( V_26 ) ;
F_20 ( & V_26 -> V_50 ) ;
return F_29 ( V_34 ) ;
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
F_16 ( & V_26 -> V_50 ) ;
if ( V_34 -> V_28 -> V_58 -> V_59 != V_60 )
V_26 -> V_62 -- ;
F_28 ( V_26 ) ;
F_20 ( & V_26 -> V_50 ) ;
return F_29 ( V_34 ) ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
F_16 ( & V_26 -> V_50 ) ;
V_37 = F_32 ( V_26 , V_34 -> V_28 -> V_19 ) ;
F_20 ( & V_26 -> V_50 ) ;
if ( V_37 >= 0 )
F_33 ( & V_26 -> V_40 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
F_16 ( & V_26 -> V_50 ) ;
V_37 = F_32 ( V_26 , V_34 -> V_28 -> V_19 ) ;
F_20 ( & V_26 -> V_50 ) ;
if ( V_37 >= 0 )
F_33 ( & V_26 -> V_42 ) ;
return V_37 ;
}
static int F_35 ( struct V_33 * V_34 , int V_63 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
switch ( V_63 ) {
case V_64 :
F_36 ( & V_26 -> V_40 , V_34 ) ;
break;
case V_65 :
F_36 ( & V_26 -> V_40 , NULL ) ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_37 ( struct V_33 * V_34 , int V_63 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
switch ( V_63 ) {
case V_64 :
F_36 ( & V_26 -> V_42 , V_34 ) ;
break;
case V_65 :
F_36 ( & V_26 -> V_42 , NULL ) ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static T_1 F_38 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_39 ( & V_26 -> V_40 ) ;
}
static T_1 F_40 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_39 ( & V_26 -> V_42 ) ;
}
static int F_41 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_42 ( & V_26 -> V_40 ) ;
}
static int F_43 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_42 ( & V_26 -> V_42 ) ;
}
int F_44 ( struct V_25 * V_26 )
{
static const struct V_67 V_68 = {
. V_69 = F_14 ,
. V_70 = F_22 ,
. V_71 = V_72 ,
. V_57 = F_23 ,
. V_73 = F_27 ,
. V_74 = F_31 ,
. V_75 = F_35 ,
. V_76 = F_38 ,
. V_77 = F_41 ,
. V_78 = V_79 ,
. V_80 = V_81 ,
} ;
static const struct V_67 V_82 = {
. V_69 = F_14 ,
. V_70 = F_22 ,
. V_71 = V_72 ,
. V_57 = F_26 ,
. V_73 = F_30 ,
. V_74 = F_34 ,
. V_75 = F_37 ,
. V_76 = F_40 ,
. V_77 = F_43 ,
. V_78 = V_79 ,
. V_80 = V_81 ,
} ;
struct V_83 * V_84 ;
int V_37 ;
V_37 = F_45 ( V_26 -> V_85 , V_26 -> V_85 -> V_86 , 0 , 1 , 1 , & V_84 ) ;
if ( V_37 < 0 )
return V_37 ;
V_84 -> V_44 = V_26 ;
strcpy ( V_84 -> V_87 , V_26 -> V_85 -> V_88 ) ;
F_46 ( V_84 , V_38 , & V_68 ) ;
F_46 ( V_84 , V_89 , & V_82 ) ;
return 0 ;
}
