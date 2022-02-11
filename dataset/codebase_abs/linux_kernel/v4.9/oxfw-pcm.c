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
static void F_12 ( struct V_26 * V_27 )
{
V_27 -> V_33 = 2 ;
V_27 -> V_34 = V_14 ;
V_27 -> V_35 = 4 * V_27 -> V_29 ;
V_27 -> V_36 = V_27 -> V_35 * 2048 ;
V_27 -> V_37 = V_27 -> V_36 * V_27 -> V_33 ;
}
static int F_13 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
T_1 * * V_5 ;
struct V_44 * V_45 ;
int V_19 ;
V_43 -> V_27 . V_46 = V_47 |
V_48 |
V_49 |
V_50 |
V_51 |
V_52 ;
if ( V_41 -> V_45 == V_53 ) {
V_43 -> V_27 . V_5 = V_54 ;
V_45 = & V_39 -> V_55 ;
V_5 = V_39 -> V_56 ;
} else {
V_43 -> V_27 . V_5 = V_57 ;
V_45 = & V_39 -> V_58 ;
V_5 = V_39 -> V_59 ;
}
F_10 ( & V_43 -> V_27 , V_5 ) ;
F_12 ( & V_43 -> V_27 ) ;
V_19 = F_14 ( V_43 , 0 , V_11 ,
F_7 , V_5 ,
V_9 , - 1 ) ;
if ( V_19 < 0 )
goto V_60;
V_19 = F_14 ( V_43 , 0 , V_9 ,
F_1 , V_5 ,
V_11 , - 1 ) ;
if ( V_19 < 0 )
goto V_60;
V_19 = F_15 ( V_45 , V_43 ) ;
V_60:
return V_19 ;
}
static int F_16 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
struct V_16 V_17 ;
enum V_62 V_63 ;
int V_19 ;
if ( V_41 -> V_45 == V_53 )
V_63 = V_64 ;
else
V_63 = V_65 ;
V_19 = F_17 ( V_39 , V_63 , & V_17 ) ;
if ( V_19 < 0 )
goto V_60;
V_41 -> V_43 -> V_27 . V_28 = V_17 . V_21 ;
V_41 -> V_43 -> V_27 . V_29 = V_17 . V_21 ;
V_41 -> V_43 -> V_27 . V_30 = V_17 . V_22 ;
V_41 -> V_43 -> V_27 . V_31 = V_17 . V_22 ;
V_60:
return V_19 ;
}
static int F_18 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
int V_19 ;
V_19 = F_19 ( V_39 ) ;
if ( V_19 < 0 )
goto V_60;
V_19 = F_13 ( V_39 , V_41 ) ;
if ( V_19 < 0 )
goto V_66;
if ( F_20 ( & V_39 -> V_55 ) ||
F_20 ( & V_39 -> V_58 ) ) {
V_19 = F_16 ( V_41 ) ;
if ( V_19 < 0 )
goto V_60;
}
F_21 ( V_41 ) ;
V_60:
return V_19 ;
V_66:
F_22 ( V_39 ) ;
return V_19 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
F_22 ( V_39 ) ;
return 0 ;
}
static int F_24 ( struct V_40 * V_41 ,
struct V_1 * V_67 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
int V_19 ;
V_19 = F_25 ( V_41 ,
F_26 ( V_67 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_41 -> V_43 -> V_68 -> V_69 == V_70 ) {
F_27 ( & V_39 -> V_71 ) ;
V_39 -> V_72 ++ ;
F_28 ( & V_39 -> V_71 ) ;
}
F_29 ( & V_39 -> V_55 , F_30 ( V_67 ) ) ;
return 0 ;
}
static int F_31 ( struct V_40 * V_41 ,
struct V_1 * V_67 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
int V_19 ;
V_19 = F_25 ( V_41 ,
F_26 ( V_67 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_41 -> V_43 -> V_68 -> V_69 == V_70 ) {
F_27 ( & V_39 -> V_71 ) ;
V_39 -> V_73 ++ ;
F_28 ( & V_39 -> V_71 ) ;
}
F_29 ( & V_39 -> V_58 , F_30 ( V_67 ) ) ;
return 0 ;
}
static int F_32 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
F_27 ( & V_39 -> V_71 ) ;
if ( V_41 -> V_43 -> V_68 -> V_69 != V_70 )
V_39 -> V_72 -- ;
F_33 ( V_39 , & V_39 -> V_55 ) ;
F_28 ( & V_39 -> V_71 ) ;
return F_34 ( V_41 ) ;
}
static int F_35 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
F_27 ( & V_39 -> V_71 ) ;
if ( V_41 -> V_43 -> V_68 -> V_69 != V_70 )
V_39 -> V_73 -- ;
F_33 ( V_39 , & V_39 -> V_58 ) ;
F_28 ( & V_39 -> V_71 ) ;
return F_34 ( V_41 ) ;
}
static int F_36 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
struct V_42 * V_43 = V_41 -> V_43 ;
int V_19 ;
F_27 ( & V_39 -> V_71 ) ;
V_19 = F_37 ( V_39 , & V_39 -> V_55 ,
V_43 -> V_22 , V_43 -> V_74 ) ;
F_28 ( & V_39 -> V_71 ) ;
if ( V_19 < 0 )
goto V_60;
F_38 ( & V_39 -> V_55 ) ;
V_60:
return V_19 ;
}
static int F_39 ( struct V_40 * V_41 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
struct V_42 * V_43 = V_41 -> V_43 ;
int V_19 ;
F_27 ( & V_39 -> V_71 ) ;
V_19 = F_37 ( V_39 , & V_39 -> V_58 ,
V_43 -> V_22 , V_43 -> V_74 ) ;
F_28 ( & V_39 -> V_71 ) ;
if ( V_19 < 0 )
goto V_60;
F_38 ( & V_39 -> V_58 ) ;
V_60:
return V_19 ;
}
static int F_40 ( struct V_40 * V_41 , int V_75 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
struct V_40 * V_21 ;
switch ( V_75 ) {
case V_76 :
V_21 = V_41 ;
break;
case V_77 :
V_21 = NULL ;
break;
default:
return - V_78 ;
}
F_41 ( & V_39 -> V_55 , V_21 ) ;
return 0 ;
}
static int F_42 ( struct V_40 * V_41 , int V_75 )
{
struct V_38 * V_39 = V_41 -> V_61 ;
struct V_40 * V_21 ;
switch ( V_75 ) {
case V_76 :
V_21 = V_41 ;
break;
case V_77 :
V_21 = NULL ;
break;
default:
return - V_78 ;
}
F_41 ( & V_39 -> V_58 , V_21 ) ;
return 0 ;
}
static T_2 F_43 ( struct V_40 * V_79 )
{
struct V_38 * V_39 = V_79 -> V_61 ;
return F_44 ( & V_39 -> V_55 ) ;
}
static T_2 F_45 ( struct V_40 * V_79 )
{
struct V_38 * V_39 = V_79 -> V_61 ;
return F_44 ( & V_39 -> V_58 ) ;
}
int F_46 ( struct V_38 * V_39 )
{
static const struct V_80 V_81 = {
. V_82 = F_18 ,
. V_83 = F_23 ,
. V_84 = V_85 ,
. V_67 = F_24 ,
. V_86 = F_32 ,
. V_87 = F_36 ,
. V_88 = F_40 ,
. V_89 = F_43 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
} ;
static const struct V_80 V_94 = {
. V_82 = F_18 ,
. V_83 = F_23 ,
. V_84 = V_85 ,
. V_67 = F_31 ,
. V_86 = F_35 ,
. V_87 = F_39 ,
. V_88 = F_42 ,
. V_89 = F_45 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
} ;
struct V_95 * V_21 ;
unsigned int V_96 = 0 ;
int V_19 ;
if ( V_39 -> V_97 )
V_96 = 1 ;
V_19 = F_47 ( V_39 -> V_98 , V_39 -> V_98 -> V_99 , 0 , 1 , V_96 , & V_21 ) ;
if ( V_19 < 0 )
return V_19 ;
V_21 -> V_61 = V_39 ;
strcpy ( V_21 -> V_100 , V_39 -> V_98 -> V_101 ) ;
F_48 ( V_21 , V_102 , & V_94 ) ;
if ( V_96 > 0 )
F_48 ( V_21 , V_53 , & V_81 ) ;
return 0 ;
}
