static inline unsigned int
F_1 ( unsigned int V_1 )
{
return ( ( int ) V_1 - 1 ) / 2 ;
}
int F_2 ( unsigned int V_2 , unsigned int * V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] == V_2 ) {
* V_3 = F_1 ( V_4 ) ;
return 0 ;
}
}
return - V_6 ;
}
static int
F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned int * V_11 = V_10 -> V_12 ;
struct V_13 * V_14 =
F_5 ( V_8 , V_15 ) ;
const struct V_13 * V_16 =
F_6 ( V_8 , V_17 ) ;
struct V_13 V_18 = {
. V_19 = V_20 , . V_21 = 0 , . integer = 1
} ;
unsigned int V_4 , V_3 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
V_3 = F_1 ( V_4 ) ;
if ( ! F_7 ( V_16 , V_11 [ V_3 ] ) )
continue;
V_18 . V_19 = V_19 ( V_18 . V_19 , V_5 [ V_4 ] ) ;
V_18 . V_21 = V_21 ( V_18 . V_21 , V_5 [ V_4 ] ) ;
}
return F_8 ( V_14 , & V_18 ) ;
}
static int
F_9 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned int * V_11 = V_10 -> V_12 ;
struct V_13 * V_16 =
F_5 ( V_8 , V_17 ) ;
const struct V_13 * V_14 =
F_6 ( V_8 , V_15 ) ;
struct V_13 V_18 = {
. V_19 = V_20 , . V_21 = 0 , . integer = 1
} ;
unsigned int V_4 , V_3 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
V_3 = F_1 ( V_4 ) ;
if ( ! F_7 ( V_14 , V_5 [ V_4 ] ) )
continue;
V_18 . V_19 = V_19 ( V_18 . V_19 , V_11 [ V_3 ] ) ;
V_18 . V_21 = V_21 ( V_18 . V_21 , V_11 [ V_3 ] ) ;
}
return F_8 ( V_16 , & V_18 ) ;
}
static void
F_10 ( struct V_22 * V_23 , unsigned int * V_11 )
{
unsigned int V_4 , V_3 ;
V_23 -> V_24 = V_20 ;
V_23 -> V_25 = 0 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
V_3 = F_1 ( V_4 ) ;
if ( V_11 [ V_3 ] == 0 )
continue;
V_23 -> V_24 = V_19 ( V_23 -> V_24 , V_11 [ V_3 ] ) ;
V_23 -> V_25 = V_21 ( V_23 -> V_25 , V_11 [ V_3 ] ) ;
}
}
static int
F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_32 * V_33 ;
unsigned int * V_11 ;
int V_34 ;
if ( V_29 -> V_35 == V_36 ) {
V_31 -> V_23 . V_37 = V_38 ;
V_33 = & V_27 -> V_39 ;
V_11 = V_27 -> V_40 ;
} else {
V_31 -> V_23 . V_37 = V_41 ;
V_33 = & V_27 -> V_42 ;
V_11 = V_27 -> V_43 ;
}
V_31 -> V_23 . V_44 = V_27 -> V_45 ,
F_12 ( V_31 ) ;
F_10 ( & V_31 -> V_23 , V_11 ) ;
V_34 = F_13 ( V_31 , 0 , V_17 ,
F_9 , V_11 ,
V_15 , - 1 ) ;
if ( V_34 < 0 )
goto V_46;
V_34 = F_13 ( V_31 , 0 , V_15 ,
F_4 , V_11 ,
V_17 , - 1 ) ;
if ( V_34 < 0 )
goto V_46;
V_34 = F_14 ( V_33 , V_31 ) ;
V_46:
return V_34 ;
}
static int F_15 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
unsigned int V_2 ;
enum V_48 V_49 ;
int V_34 ;
V_34 = F_16 ( V_27 ) ;
if ( V_34 < 0 )
goto V_46;
V_34 = F_11 ( V_27 , V_29 ) ;
if ( V_34 < 0 )
goto V_50;
V_34 = F_17 ( V_27 , & V_49 ) ;
if ( V_34 < 0 )
goto V_50;
if ( ( V_49 != V_51 ) ||
F_18 ( & V_27 -> V_39 ) ||
F_18 ( & V_27 -> V_42 ) ) {
V_34 = F_19 ( V_27 , & V_2 ) ;
if ( V_34 < 0 )
goto V_50;
V_29 -> V_31 -> V_23 . V_52 = V_2 ;
V_29 -> V_31 -> V_23 . V_53 = V_2 ;
}
F_20 ( V_29 ) ;
V_46:
return V_34 ;
V_50:
F_21 ( V_27 ) ;
return V_34 ;
}
static int F_22 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
F_21 ( V_27 ) ;
return 0 ;
}
static int F_23 ( struct V_28 * V_29 ,
struct V_7 * V_54 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
int V_34 ;
V_34 = F_24 ( V_29 ,
F_25 ( V_54 ) ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_29 -> V_31 -> V_55 -> V_56 == V_57 ) {
F_26 ( & V_27 -> V_58 ) ;
V_27 -> V_59 ++ ;
F_27 ( & V_27 -> V_58 ) ;
}
return 0 ;
}
static int F_28 ( struct V_28 * V_29 ,
struct V_7 * V_54 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
int V_34 ;
V_34 = F_24 ( V_29 ,
F_25 ( V_54 ) ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_29 -> V_31 -> V_55 -> V_56 == V_57 ) {
F_26 ( & V_27 -> V_58 ) ;
V_27 -> V_60 ++ ;
F_27 ( & V_27 -> V_58 ) ;
}
return 0 ;
}
static int F_29 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
if ( V_29 -> V_31 -> V_55 -> V_56 != V_57 ) {
F_26 ( & V_27 -> V_58 ) ;
V_27 -> V_59 -- ;
F_27 ( & V_27 -> V_58 ) ;
}
F_30 ( V_27 ) ;
return F_31 ( V_29 ) ;
}
static int F_32 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
if ( V_29 -> V_31 -> V_55 -> V_56 != V_57 ) {
F_26 ( & V_27 -> V_58 ) ;
V_27 -> V_60 -- ;
F_27 ( & V_27 -> V_58 ) ;
}
F_30 ( V_27 ) ;
return F_31 ( V_29 ) ;
}
static int F_33 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
struct V_30 * V_31 = V_29 -> V_31 ;
int V_34 ;
V_34 = F_34 ( V_27 , V_31 -> V_61 ) ;
if ( V_34 >= 0 )
F_35 ( & V_27 -> V_39 ) ;
return V_34 ;
}
static int F_36 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
struct V_30 * V_31 = V_29 -> V_31 ;
int V_34 ;
V_34 = F_34 ( V_27 , V_31 -> V_61 ) ;
if ( V_34 >= 0 )
F_35 ( & V_27 -> V_42 ) ;
return V_34 ;
}
static int F_37 ( struct V_28 * V_29 , int V_62 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
switch ( V_62 ) {
case V_63 :
F_38 ( & V_27 -> V_39 , V_29 ) ;
break;
case V_64 :
F_38 ( & V_27 -> V_39 , NULL ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_39 ( struct V_28 * V_29 , int V_62 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
switch ( V_62 ) {
case V_63 :
F_38 ( & V_27 -> V_42 , V_29 ) ;
break;
case V_64 :
F_38 ( & V_27 -> V_42 , NULL ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static T_1 F_40 ( struct V_28 * V_65 )
{
struct V_26 * V_27 = V_65 -> V_47 ;
return F_41 ( & V_27 -> V_39 ) ;
}
static T_1 F_42 ( struct V_28 * V_65 )
{
struct V_26 * V_27 = V_65 -> V_47 ;
return F_41 ( & V_27 -> V_42 ) ;
}
static int F_43 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
return F_44 ( & V_27 -> V_39 ) ;
}
static int F_45 ( struct V_28 * V_29 )
{
struct V_26 * V_27 = V_29 -> V_47 ;
return F_44 ( & V_27 -> V_42 ) ;
}
int F_46 ( struct V_26 * V_27 )
{
static const struct V_66 V_67 = {
. V_68 = F_15 ,
. V_69 = F_22 ,
. V_70 = V_71 ,
. V_54 = F_23 ,
. V_72 = F_29 ,
. V_73 = F_33 ,
. V_74 = F_37 ,
. V_75 = F_40 ,
. V_76 = F_43 ,
. V_77 = V_78 ,
} ;
static const struct V_66 V_79 = {
. V_68 = F_15 ,
. V_69 = F_22 ,
. V_70 = V_71 ,
. V_54 = F_28 ,
. V_72 = F_32 ,
. V_73 = F_36 ,
. V_74 = F_39 ,
. V_75 = F_42 ,
. V_76 = F_45 ,
. V_77 = V_78 ,
. V_80 = V_81 ,
} ;
struct V_82 * V_83 ;
int V_34 ;
V_34 = F_47 ( V_27 -> V_84 , V_27 -> V_84 -> V_85 , 0 , 1 , 1 , & V_83 ) ;
if ( V_34 < 0 )
goto V_46;
V_83 -> V_47 = V_27 ;
snprintf ( V_83 -> V_86 , sizeof( V_83 -> V_86 ) , L_1 , V_27 -> V_84 -> V_87 ) ;
F_48 ( V_83 , V_88 , & V_79 ) ;
F_48 ( V_83 , V_36 , & V_67 ) ;
V_46:
return V_34 ;
}
