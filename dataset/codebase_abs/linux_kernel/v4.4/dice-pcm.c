static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
const struct V_11 * V_12 =
F_2 ( V_2 , V_13 ) ;
struct V_11 * V_14 =
F_3 ( V_2 , V_15 ) ;
struct V_11 V_16 = {
. V_17 = V_18 , . V_19 = 0 , . integer = 1
} ;
unsigned int V_20 , V_21 , V_22 , * V_23 ;
if ( V_6 -> V_24 == V_25 )
V_23 = V_9 -> V_26 ;
else
V_23 = V_9 -> V_27 ;
for ( V_20 = 0 ; V_20 < F_4 ( V_28 ) ; ++ V_20 ) {
V_21 = V_28 [ V_20 ] ;
if ( F_5 ( V_9 , V_21 , & V_22 ) < 0 )
continue;
if ( ! F_6 ( V_12 , V_23 [ V_22 ] ) )
continue;
V_16 . V_17 = V_17 ( V_16 . V_17 , V_21 ) ;
V_16 . V_19 = V_19 ( V_16 . V_19 , V_21 ) ;
}
return F_7 ( V_14 , & V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
const struct V_11 * V_14 =
F_2 ( V_2 , V_15 ) ;
struct V_11 * V_12 =
F_3 ( V_2 , V_13 ) ;
struct V_11 V_29 = {
. V_17 = V_18 , . V_19 = 0 , . integer = 1
} ;
unsigned int V_20 , V_21 , V_22 , * V_23 ;
if ( V_6 -> V_24 == V_25 )
V_23 = V_9 -> V_26 ;
else
V_23 = V_9 -> V_27 ;
for ( V_20 = 0 ; V_20 < F_4 ( V_28 ) ; ++ V_20 ) {
V_21 = V_28 [ V_20 ] ;
if ( F_5 ( V_9 , V_21 , & V_22 ) < 0 )
continue;
if ( ! F_6 ( V_14 , V_21 ) )
continue;
V_29 . V_17 = V_17 ( V_29 . V_17 , V_23 [ V_22 ] ) ;
V_29 . V_19 = V_19 ( V_29 . V_19 , V_23 [ V_22 ] ) ;
}
return F_7 ( V_12 , & V_29 ) ;
}
static void F_9 ( struct V_8 * V_9 ,
struct V_30 * V_31 ,
unsigned int * V_23 )
{
struct V_32 * V_33 = & V_31 -> V_33 ;
unsigned int V_20 , V_21 , V_22 ;
V_33 -> V_34 = V_18 ;
V_33 -> V_35 = 0 ;
for ( V_20 = 0 ; V_20 < F_4 ( V_28 ) ; ++ V_20 ) {
V_21 = V_28 [ V_20 ] ;
if ( F_5 ( V_9 , V_21 , & V_22 ) < 0 )
continue;
V_33 -> V_16 |= F_10 ( V_21 ) ;
if ( V_23 [ V_22 ] == 0 )
continue;
V_33 -> V_34 = V_17 ( V_33 -> V_34 , V_23 [ V_22 ] ) ;
V_33 -> V_35 = V_19 ( V_33 -> V_35 , V_23 [ V_22 ] ) ;
}
F_11 ( V_31 ) ;
}
static void F_12 ( struct V_32 * V_33 )
{
V_33 -> V_36 = 2 ;
V_33 -> V_37 = V_18 ;
V_33 -> V_38 = 4 * V_33 -> V_35 ;
V_33 -> V_39 = V_33 -> V_38 * 2048 ;
V_33 -> V_40 = V_33 -> V_39 * V_33 -> V_36 ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_5 * V_6 )
{
struct V_30 * V_31 = V_6 -> V_31 ;
struct V_32 * V_33 = & V_31 -> V_33 ;
struct V_41 * V_24 ;
unsigned int * V_23 ;
int V_42 ;
V_33 -> V_43 = V_44 |
V_45 |
V_46 |
V_47 |
V_48 |
V_49 ;
if ( V_6 -> V_24 == V_25 ) {
V_33 -> V_50 = V_51 ;
V_24 = & V_9 -> V_52 ;
V_23 = V_9 -> V_26 ;
} else {
V_33 -> V_50 = V_53 ;
V_24 = & V_9 -> V_54 ;
V_23 = V_9 -> V_27 ;
}
F_9 ( V_9 , V_31 , V_23 ) ;
F_12 ( V_33 ) ;
V_42 = F_14 ( V_31 , 0 , V_15 ,
F_1 , V_6 ,
V_13 , - 1 ) ;
if ( V_42 < 0 )
goto V_55;
V_42 = F_14 ( V_31 , 0 , V_13 ,
F_8 , V_6 ,
V_15 , - 1 ) ;
if ( V_42 < 0 )
goto V_55;
V_42 = F_15 ( V_24 , V_31 ) ;
V_55:
return V_42 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 , V_21 ;
bool V_57 ;
int V_42 ;
V_42 = F_17 ( V_9 ) ;
if ( V_42 < 0 )
goto V_55;
V_42 = F_13 ( V_9 , V_6 ) ;
if ( V_42 < 0 )
goto V_58;
V_42 = F_18 ( V_9 , & V_56 ) ;
if ( V_42 < 0 )
goto V_58;
switch ( V_56 ) {
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
V_57 = false ;
break;
default:
V_57 = true ;
break;
}
if ( ! V_57 ||
F_19 ( & V_9 -> V_52 ) ||
F_19 ( & V_9 -> V_54 ) ) {
V_42 = F_20 ( V_9 , & V_21 ) ;
if ( V_42 < 0 )
goto V_58;
V_6 -> V_31 -> V_33 . V_67 = V_21 ;
V_6 -> V_31 -> V_33 . V_68 = V_21 ;
}
F_21 ( V_6 ) ;
V_55:
return V_42 ;
V_58:
F_22 ( V_9 ) ;
return V_42 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_22 ( V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_1 * V_69 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_42 ;
V_42 = F_25 ( V_6 ,
F_26 ( V_69 ) ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_6 -> V_31 -> V_70 -> V_71 == V_72 ) {
F_27 ( & V_9 -> V_73 ) ;
V_9 -> V_74 ++ ;
F_28 ( & V_9 -> V_73 ) ;
}
F_29 ( & V_9 -> V_52 , F_30 ( V_69 ) ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 ,
struct V_1 * V_69 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_42 ;
V_42 = F_25 ( V_6 ,
F_26 ( V_69 ) ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_6 -> V_31 -> V_70 -> V_71 == V_72 ) {
F_27 ( & V_9 -> V_73 ) ;
V_9 -> V_74 ++ ;
F_28 ( & V_9 -> V_73 ) ;
}
F_29 ( & V_9 -> V_54 , F_30 ( V_69 ) ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_27 ( & V_9 -> V_73 ) ;
if ( V_6 -> V_31 -> V_70 -> V_71 != V_72 )
V_9 -> V_74 -- ;
F_33 ( V_9 ) ;
F_28 ( & V_9 -> V_73 ) ;
return F_34 ( V_6 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_27 ( & V_9 -> V_73 ) ;
if ( V_6 -> V_31 -> V_70 -> V_71 != V_72 )
V_9 -> V_74 -- ;
F_33 ( V_9 ) ;
F_28 ( & V_9 -> V_73 ) ;
return F_34 ( V_6 ) ;
}
static int F_36 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_42 ;
F_27 ( & V_9 -> V_73 ) ;
V_42 = F_37 ( V_9 , V_6 -> V_31 -> V_21 ) ;
F_28 ( & V_9 -> V_73 ) ;
if ( V_42 >= 0 )
F_38 ( & V_9 -> V_52 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_42 ;
F_27 ( & V_9 -> V_73 ) ;
V_42 = F_37 ( V_9 , V_6 -> V_31 -> V_21 ) ;
F_28 ( & V_9 -> V_73 ) ;
if ( V_42 >= 0 )
F_38 ( & V_9 -> V_54 ) ;
return V_42 ;
}
static int F_40 ( struct V_5 * V_6 , int V_75 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
switch ( V_75 ) {
case V_76 :
F_41 ( & V_9 -> V_52 , V_6 ) ;
break;
case V_77 :
F_41 ( & V_9 -> V_52 , NULL ) ;
break;
default:
return - V_78 ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_6 , int V_75 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
switch ( V_75 ) {
case V_76 :
F_41 ( & V_9 -> V_54 , V_6 ) ;
break;
case V_77 :
F_41 ( & V_9 -> V_54 , NULL ) ;
break;
default:
return - V_78 ;
}
return 0 ;
}
static T_1 F_43 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
return F_44 ( & V_9 -> V_52 ) ;
}
static T_1 F_45 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
return F_44 ( & V_9 -> V_54 ) ;
}
int F_46 ( struct V_8 * V_9 )
{
static struct V_79 V_80 = {
. V_81 = F_16 ,
. V_82 = F_23 ,
. V_83 = V_84 ,
. V_69 = F_24 ,
. V_85 = F_32 ,
. V_86 = F_36 ,
. V_87 = F_40 ,
. V_88 = F_43 ,
. V_89 = V_90 ,
. V_91 = V_92 ,
} ;
static struct V_79 V_93 = {
. V_81 = F_16 ,
. V_82 = F_23 ,
. V_83 = V_84 ,
. V_69 = F_31 ,
. V_85 = F_35 ,
. V_86 = F_39 ,
. V_87 = F_42 ,
. V_88 = F_45 ,
. V_89 = V_90 ,
. V_91 = V_92 ,
} ;
struct V_94 * V_95 ;
unsigned int V_20 , V_96 , V_97 ;
int V_42 ;
V_96 = V_97 = 0 ;
for ( V_20 = 0 ; V_20 < 3 ; V_20 ++ ) {
if ( V_9 -> V_26 [ V_20 ] > 0 )
V_96 = 1 ;
if ( V_9 -> V_27 [ V_20 ] > 0 )
V_97 = 1 ;
}
V_42 = F_47 ( V_9 -> V_98 , L_1 , 0 , V_97 , V_96 , & V_95 ) ;
if ( V_42 < 0 )
return V_42 ;
V_95 -> V_10 = V_9 ;
strcpy ( V_95 -> V_99 , V_9 -> V_98 -> V_100 ) ;
if ( V_96 > 0 )
F_48 ( V_95 , V_25 , & V_80 ) ;
if ( V_97 > 0 )
F_48 ( V_95 , V_101 , & V_93 ) ;
return 0 ;
}
