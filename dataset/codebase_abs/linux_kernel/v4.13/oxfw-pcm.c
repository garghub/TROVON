static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * * V_5 = V_4 -> V_6 ;
struct V_7 * V_8 =
F_2 ( V_2 , V_9 ) ;
const struct V_7 * V_10 =
F_3 ( V_2 , V_11 ) ;
struct V_7 V_12 = {
. V_13 = V_14 , . V_15 = 0 , . integer = 1
} ;
struct V_16 V_17 ;
int V_18 , V_19 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_5 [ V_18 ] == NULL )
continue;
V_19 = F_4 ( V_5 [ V_18 ] , & V_17 ) ;
if ( V_19 < 0 )
continue;
if ( ! F_5 ( V_10 , V_17 . V_21 ) )
continue;
V_12 . V_13 = V_13 ( V_12 . V_13 , V_17 . V_22 ) ;
V_12 . V_15 = V_15 ( V_12 . V_15 , V_17 . V_22 ) ;
}
return F_6 ( V_8 , & V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * * V_5 = V_4 -> V_6 ;
struct V_7 * V_10 =
F_2 ( V_2 , V_11 ) ;
const struct V_7 * V_8 =
F_3 ( V_2 , V_9 ) ;
struct V_16 V_17 ;
int V_18 , V_23 , V_19 ;
unsigned int V_24 , V_25 [ V_20 ] = { 0 } ;
V_24 = 0 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_5 [ V_18 ] == NULL )
break;
V_19 = F_4 ( V_5 [ V_18 ] , & V_17 ) ;
if ( V_19 < 0 )
continue;
if ( ! F_5 ( V_8 , V_17 . V_22 ) )
continue;
if ( V_25 [ V_24 ] == V_17 . V_21 )
continue;
for ( V_23 = 0 ; V_23 < F_8 ( V_25 ) ; V_23 ++ ) {
if ( V_25 [ V_23 ] == V_17 . V_21 )
break;
}
if ( V_23 == F_8 ( V_25 ) ) {
V_25 [ V_24 ] = V_17 . V_21 ;
if ( ++ V_24 == F_8 ( V_25 ) )
break;
}
}
return F_9 ( V_10 , V_24 , V_25 , 0 ) ;
}
static void F_10 ( struct V_26 * V_27 , T_1 * * V_5 )
{
struct V_16 V_17 ;
int V_18 , V_19 ;
V_27 -> V_28 = V_14 ;
V_27 -> V_29 = 0 ;
V_27 -> V_30 = V_14 ;
V_27 -> V_31 = 0 ;
V_27 -> V_32 = 0 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_5 [ V_18 ] == NULL )
break;
V_19 = F_4 ( V_5 [ V_18 ] , & V_17 ) ;
if ( V_19 < 0 )
continue;
V_27 -> V_28 = V_13 ( V_27 -> V_28 , V_17 . V_21 ) ;
V_27 -> V_29 = V_15 ( V_27 -> V_29 , V_17 . V_21 ) ;
V_27 -> V_30 = V_13 ( V_27 -> V_30 , V_17 . V_22 ) ;
V_27 -> V_31 = V_15 ( V_27 -> V_31 , V_17 . V_22 ) ;
V_27 -> V_32 |= F_11 ( V_17 . V_22 ) ;
}
}
static int F_12 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
T_1 * * V_5 ;
struct V_39 * V_40 ;
int V_19 ;
if ( V_36 -> V_40 == V_41 ) {
V_38 -> V_27 . V_5 = V_42 ;
V_40 = & V_34 -> V_43 ;
V_5 = V_34 -> V_44 ;
} else {
V_38 -> V_27 . V_5 = V_45 ;
V_40 = & V_34 -> V_46 ;
V_5 = V_34 -> V_47 ;
}
F_10 ( & V_38 -> V_27 , V_5 ) ;
V_19 = F_13 ( V_38 , 0 , V_11 ,
F_7 , V_5 ,
V_9 , - 1 ) ;
if ( V_19 < 0 )
goto V_48;
V_19 = F_13 ( V_38 , 0 , V_9 ,
F_1 , V_5 ,
V_11 , - 1 ) ;
if ( V_19 < 0 )
goto V_48;
V_19 = F_14 ( V_40 , V_38 ) ;
V_48:
return V_19 ;
}
static int F_15 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
struct V_16 V_17 ;
enum V_50 V_51 ;
int V_19 ;
if ( V_36 -> V_40 == V_41 )
V_51 = V_52 ;
else
V_51 = V_53 ;
V_19 = F_16 ( V_34 , V_51 , & V_17 ) ;
if ( V_19 < 0 )
goto V_48;
V_36 -> V_38 -> V_27 . V_28 = V_17 . V_21 ;
V_36 -> V_38 -> V_27 . V_29 = V_17 . V_21 ;
V_36 -> V_38 -> V_27 . V_30 = V_17 . V_22 ;
V_36 -> V_38 -> V_27 . V_31 = V_17 . V_22 ;
V_48:
return V_19 ;
}
static int F_17 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
int V_19 ;
V_19 = F_18 ( V_34 ) ;
if ( V_19 < 0 )
goto V_48;
V_19 = F_12 ( V_34 , V_36 ) ;
if ( V_19 < 0 )
goto V_54;
if ( F_19 ( & V_34 -> V_43 ) ||
F_19 ( & V_34 -> V_46 ) ) {
V_19 = F_15 ( V_36 ) ;
if ( V_19 < 0 )
goto V_48;
}
F_20 ( V_36 ) ;
V_48:
return V_19 ;
V_54:
F_21 ( V_34 ) ;
return V_19 ;
}
static int F_22 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
F_21 ( V_34 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_1 * V_55 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
int V_19 ;
V_19 = F_24 ( V_36 ,
F_25 ( V_55 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_36 -> V_38 -> V_56 -> V_57 == V_58 ) {
F_26 ( & V_34 -> V_59 ) ;
V_34 -> V_60 ++ ;
F_27 ( & V_34 -> V_59 ) ;
}
return 0 ;
}
static int F_28 ( struct V_35 * V_36 ,
struct V_1 * V_55 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
int V_19 ;
V_19 = F_24 ( V_36 ,
F_25 ( V_55 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_36 -> V_38 -> V_56 -> V_57 == V_58 ) {
F_26 ( & V_34 -> V_59 ) ;
V_34 -> V_61 ++ ;
F_27 ( & V_34 -> V_59 ) ;
}
return 0 ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
F_26 ( & V_34 -> V_59 ) ;
if ( V_36 -> V_38 -> V_56 -> V_57 != V_58 )
V_34 -> V_60 -- ;
F_30 ( V_34 , & V_34 -> V_43 ) ;
F_27 ( & V_34 -> V_59 ) ;
return F_31 ( V_36 ) ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
F_26 ( & V_34 -> V_59 ) ;
if ( V_36 -> V_38 -> V_56 -> V_57 != V_58 )
V_34 -> V_61 -- ;
F_30 ( V_34 , & V_34 -> V_46 ) ;
F_27 ( & V_34 -> V_59 ) ;
return F_31 ( V_36 ) ;
}
static int F_33 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
struct V_37 * V_38 = V_36 -> V_38 ;
int V_19 ;
F_26 ( & V_34 -> V_59 ) ;
V_19 = F_34 ( V_34 , & V_34 -> V_43 ,
V_38 -> V_22 , V_38 -> V_62 ) ;
F_27 ( & V_34 -> V_59 ) ;
if ( V_19 < 0 )
goto V_48;
F_35 ( & V_34 -> V_43 ) ;
V_48:
return V_19 ;
}
static int F_36 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
struct V_37 * V_38 = V_36 -> V_38 ;
int V_19 ;
F_26 ( & V_34 -> V_59 ) ;
V_19 = F_34 ( V_34 , & V_34 -> V_46 ,
V_38 -> V_22 , V_38 -> V_62 ) ;
F_27 ( & V_34 -> V_59 ) ;
if ( V_19 < 0 )
goto V_48;
F_35 ( & V_34 -> V_46 ) ;
V_48:
return V_19 ;
}
static int F_37 ( struct V_35 * V_36 , int V_63 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
struct V_35 * V_21 ;
switch ( V_63 ) {
case V_64 :
V_21 = V_36 ;
break;
case V_65 :
V_21 = NULL ;
break;
default:
return - V_66 ;
}
F_38 ( & V_34 -> V_43 , V_21 ) ;
return 0 ;
}
static int F_39 ( struct V_35 * V_36 , int V_63 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
struct V_35 * V_21 ;
switch ( V_63 ) {
case V_64 :
V_21 = V_36 ;
break;
case V_65 :
V_21 = NULL ;
break;
default:
return - V_66 ;
}
F_38 ( & V_34 -> V_46 , V_21 ) ;
return 0 ;
}
static T_2 F_40 ( struct V_35 * V_67 )
{
struct V_33 * V_34 = V_67 -> V_49 ;
return F_41 ( & V_34 -> V_43 ) ;
}
static T_2 F_42 ( struct V_35 * V_67 )
{
struct V_33 * V_34 = V_67 -> V_49 ;
return F_41 ( & V_34 -> V_46 ) ;
}
static int F_43 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
return F_44 ( & V_34 -> V_43 ) ;
}
static int F_45 ( struct V_35 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_49 ;
return F_44 ( & V_34 -> V_46 ) ;
}
int F_46 ( struct V_33 * V_34 )
{
static const struct V_68 V_69 = {
. V_70 = F_17 ,
. V_71 = F_22 ,
. V_72 = V_73 ,
. V_55 = F_23 ,
. V_74 = F_29 ,
. V_75 = F_33 ,
. V_76 = F_37 ,
. V_77 = F_40 ,
. V_78 = F_43 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
} ;
static const struct V_68 V_83 = {
. V_70 = F_17 ,
. V_71 = F_22 ,
. V_72 = V_73 ,
. V_55 = F_28 ,
. V_74 = F_32 ,
. V_75 = F_36 ,
. V_76 = F_39 ,
. V_77 = F_42 ,
. V_78 = F_45 ,
. V_79 = V_80 ,
. V_81 = V_82 ,
} ;
struct V_84 * V_21 ;
unsigned int V_85 = 0 ;
int V_19 ;
if ( V_34 -> V_86 )
V_85 = 1 ;
V_19 = F_47 ( V_34 -> V_87 , V_34 -> V_87 -> V_88 , 0 , 1 , V_85 , & V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_21 -> V_49 = V_34 ;
strcpy ( V_21 -> V_89 , V_34 -> V_87 -> V_90 ) ;
F_48 ( V_21 , V_91 , & V_83 ) ;
if ( V_85 > 0 )
F_48 ( V_21 , V_41 , & V_69 ) ;
return 0 ;
}
