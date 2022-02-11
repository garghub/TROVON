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
V_37 = V_46 -> V_51 ( V_26 ) ;
if ( V_37 < 0 )
goto V_52;
V_37 = F_11 ( V_26 , V_34 ) ;
if ( V_37 < 0 )
goto V_52;
V_37 = V_46 -> V_53 ( V_26 , & V_49 ) ;
if ( V_37 < 0 )
goto V_52;
if ( V_49 != V_54 ||
F_17 ( & V_26 -> V_40 ) ||
F_17 ( & V_26 -> V_42 ) ) {
V_37 = V_46 -> V_55 ( V_26 , & V_19 ) ;
if ( V_37 < 0 )
goto V_52;
V_34 -> V_28 -> V_30 . V_56 = V_19 ;
V_34 -> V_28 -> V_30 . V_57 = V_19 ;
}
F_18 ( V_34 ) ;
F_19 ( & V_26 -> V_50 ) ;
return V_37 ;
V_52:
F_19 ( & V_26 -> V_50 ) ;
F_20 ( V_26 ) ;
return V_37 ;
}
static int F_21 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
F_20 ( V_26 ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_1 * V_58 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
V_37 = F_23 ( V_34 ,
F_24 ( V_58 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_34 -> V_28 -> V_59 -> V_60 == V_61 ) {
F_16 ( & V_26 -> V_50 ) ;
V_26 -> V_62 ++ ;
F_19 ( & V_26 -> V_50 ) ;
}
return 0 ;
}
static int F_25 ( struct V_33 * V_34 ,
struct V_1 * V_58 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
V_37 = F_23 ( V_34 ,
F_24 ( V_58 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_34 -> V_28 -> V_59 -> V_60 == V_61 ) {
F_16 ( & V_26 -> V_50 ) ;
V_26 -> V_63 ++ ;
F_19 ( & V_26 -> V_50 ) ;
}
return 0 ;
}
static int F_26 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
F_16 ( & V_26 -> V_50 ) ;
if ( V_34 -> V_28 -> V_59 -> V_60 != V_61 )
V_26 -> V_62 -- ;
F_27 ( V_26 ) ;
F_19 ( & V_26 -> V_50 ) ;
return F_28 ( V_34 ) ;
}
static int F_29 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
F_16 ( & V_26 -> V_50 ) ;
if ( V_34 -> V_28 -> V_59 -> V_60 != V_61 )
V_26 -> V_63 -- ;
F_27 ( V_26 ) ;
F_19 ( & V_26 -> V_50 ) ;
return F_28 ( V_34 ) ;
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
F_16 ( & V_26 -> V_50 ) ;
V_37 = F_31 ( V_26 , V_34 -> V_28 -> V_19 ) ;
F_19 ( & V_26 -> V_50 ) ;
if ( V_37 >= 0 )
F_32 ( & V_26 -> V_40 ) ;
return 0 ;
}
static int F_33 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
int V_37 ;
F_16 ( & V_26 -> V_50 ) ;
V_37 = F_31 ( V_26 , V_34 -> V_28 -> V_19 ) ;
F_19 ( & V_26 -> V_50 ) ;
if ( V_37 >= 0 )
F_32 ( & V_26 -> V_42 ) ;
return V_37 ;
}
static int F_34 ( struct V_33 * V_34 , int V_64 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
switch ( V_64 ) {
case V_65 :
F_35 ( & V_26 -> V_40 , V_34 ) ;
break;
case V_66 :
F_35 ( & V_26 -> V_40 , NULL ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_36 ( struct V_33 * V_34 , int V_64 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
switch ( V_64 ) {
case V_65 :
F_35 ( & V_26 -> V_42 , V_34 ) ;
break;
case V_66 :
F_35 ( & V_26 -> V_42 , NULL ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_38 ( & V_26 -> V_40 ) ;
}
static T_1 F_39 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_38 ( & V_26 -> V_42 ) ;
}
static int F_40 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_41 ( & V_26 -> V_40 ) ;
}
static int F_42 ( struct V_33 * V_34 )
{
struct V_25 * V_26 = V_34 -> V_44 ;
return F_41 ( & V_26 -> V_42 ) ;
}
int F_43 ( struct V_25 * V_26 )
{
static struct V_68 V_69 = {
. V_70 = F_14 ,
. V_71 = F_21 ,
. V_72 = V_73 ,
. V_58 = F_22 ,
. V_74 = F_26 ,
. V_75 = F_30 ,
. V_76 = F_34 ,
. V_77 = F_37 ,
. V_78 = F_40 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
} ;
static struct V_68 V_83 = {
. V_70 = F_14 ,
. V_71 = F_21 ,
. V_72 = V_73 ,
. V_58 = F_25 ,
. V_74 = F_29 ,
. V_75 = F_33 ,
. V_76 = F_36 ,
. V_77 = F_39 ,
. V_78 = F_42 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
} ;
struct V_84 * V_85 ;
int V_37 ;
V_37 = F_44 ( V_26 -> V_86 , V_26 -> V_86 -> V_87 , 0 , 1 , 1 , & V_85 ) ;
if ( V_37 < 0 )
return V_37 ;
V_85 -> V_44 = V_26 ;
strcpy ( V_85 -> V_88 , V_26 -> V_86 -> V_89 ) ;
F_45 ( V_85 , V_38 , & V_69 ) ;
F_45 ( V_85 , V_90 , & V_83 ) ;
return 0 ;
}
