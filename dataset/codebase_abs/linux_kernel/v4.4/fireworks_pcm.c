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
static void
F_11 ( struct V_22 * V_23 )
{
V_23 -> V_26 = 2 ;
V_23 -> V_27 = V_20 ;
V_23 -> V_28 = 4 * V_23 -> V_25 ;
V_23 -> V_29 = V_23 -> V_28 * 2048 ;
V_23 -> V_30 = V_23 -> V_29 * V_23 -> V_26 ;
}
static int
F_12 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_37 * V_38 ;
unsigned int * V_11 ;
int V_39 ;
V_36 -> V_23 . V_40 = V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 ;
if ( V_34 -> V_47 == V_48 ) {
V_36 -> V_23 . V_49 = V_50 ;
V_38 = & V_32 -> V_51 ;
V_11 = V_32 -> V_52 ;
} else {
V_36 -> V_23 . V_49 = V_53 ;
V_38 = & V_32 -> V_54 ;
V_11 = V_32 -> V_55 ;
}
V_36 -> V_23 . V_56 = V_32 -> V_57 ,
F_13 ( V_36 ) ;
F_10 ( & V_36 -> V_23 , V_11 ) ;
F_11 ( & V_36 -> V_23 ) ;
V_39 = F_14 ( V_36 , 0 , V_17 ,
F_9 , V_11 ,
V_15 , - 1 ) ;
if ( V_39 < 0 )
goto V_58;
V_39 = F_14 ( V_36 , 0 , V_15 ,
F_4 , V_11 ,
V_17 , - 1 ) ;
if ( V_39 < 0 )
goto V_58;
V_39 = F_15 ( V_38 , V_36 ) ;
V_58:
return V_39 ;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
unsigned int V_2 ;
enum V_60 V_61 ;
int V_39 ;
V_39 = F_17 ( V_32 ) ;
if ( V_39 < 0 )
goto V_58;
V_39 = F_12 ( V_32 , V_34 ) ;
if ( V_39 < 0 )
goto V_62;
V_39 = F_18 ( V_32 , & V_61 ) ;
if ( V_39 < 0 )
goto V_62;
if ( ( V_61 != V_63 ) ||
F_19 ( & V_32 -> V_51 ) ||
F_19 ( & V_32 -> V_54 ) ) {
V_39 = F_20 ( V_32 , & V_2 ) ;
if ( V_39 < 0 )
goto V_62;
V_34 -> V_36 -> V_23 . V_64 = V_2 ;
V_34 -> V_36 -> V_23 . V_65 = V_2 ;
}
F_21 ( V_34 ) ;
V_58:
return V_39 ;
V_62:
F_22 ( V_32 ) ;
return V_39 ;
}
static int F_23 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
F_22 ( V_32 ) ;
return 0 ;
}
static int F_24 ( struct V_33 * V_34 ,
struct V_7 * V_66 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
int V_39 ;
V_39 = F_25 ( V_34 ,
F_26 ( V_66 ) ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_34 -> V_36 -> V_67 -> V_68 == V_69 )
F_27 ( & V_32 -> V_70 ) ;
F_28 ( & V_32 -> V_51 , F_29 ( V_66 ) ) ;
return 0 ;
}
static int F_30 ( struct V_33 * V_34 ,
struct V_7 * V_66 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
int V_39 ;
V_39 = F_25 ( V_34 ,
F_26 ( V_66 ) ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_34 -> V_36 -> V_67 -> V_68 == V_69 )
F_27 ( & V_32 -> V_71 ) ;
F_28 ( & V_32 -> V_54 , F_29 ( V_66 ) ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
if ( V_34 -> V_36 -> V_67 -> V_68 != V_69 )
F_32 ( & V_32 -> V_70 ) ;
F_33 ( V_32 ) ;
return F_34 ( V_34 ) ;
}
static int F_35 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
if ( V_34 -> V_36 -> V_67 -> V_68 != V_69 )
F_32 ( & V_32 -> V_71 ) ;
F_33 ( V_32 ) ;
return F_34 ( V_34 ) ;
}
static int F_36 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
struct V_35 * V_36 = V_34 -> V_36 ;
int V_39 ;
V_39 = F_37 ( V_32 , V_36 -> V_72 ) ;
if ( V_39 >= 0 )
F_38 ( & V_32 -> V_51 ) ;
return V_39 ;
}
static int F_39 ( struct V_33 * V_34 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
struct V_35 * V_36 = V_34 -> V_36 ;
int V_39 ;
V_39 = F_37 ( V_32 , V_36 -> V_72 ) ;
if ( V_39 >= 0 )
F_38 ( & V_32 -> V_54 ) ;
return V_39 ;
}
static int F_40 ( struct V_33 * V_34 , int V_73 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
switch ( V_73 ) {
case V_74 :
F_41 ( & V_32 -> V_51 , V_34 ) ;
break;
case V_75 :
F_41 ( & V_32 -> V_51 , NULL ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_42 ( struct V_33 * V_34 , int V_73 )
{
struct V_31 * V_32 = V_34 -> V_59 ;
switch ( V_73 ) {
case V_74 :
F_41 ( & V_32 -> V_54 , V_34 ) ;
break;
case V_75 :
F_41 ( & V_32 -> V_54 , NULL ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static T_1 F_43 ( struct V_33 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_59 ;
return F_44 ( & V_32 -> V_51 ) ;
}
static T_1 F_45 ( struct V_33 * V_76 )
{
struct V_31 * V_32 = V_76 -> V_59 ;
return F_44 ( & V_32 -> V_54 ) ;
}
int F_46 ( struct V_31 * V_32 )
{
struct V_77 * V_78 ;
int V_39 ;
V_39 = F_47 ( V_32 -> V_79 , V_32 -> V_79 -> V_80 , 0 , 1 , 1 , & V_78 ) ;
if ( V_39 < 0 )
goto V_58;
V_78 -> V_59 = V_32 ;
snprintf ( V_78 -> V_81 , sizeof( V_78 -> V_81 ) , L_1 , V_32 -> V_79 -> V_82 ) ;
F_48 ( V_78 , V_83 , & V_84 ) ;
F_48 ( V_78 , V_48 , & V_85 ) ;
V_58:
return V_39 ;
}
