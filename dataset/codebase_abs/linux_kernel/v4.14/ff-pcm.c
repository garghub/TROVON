static inline unsigned int F_1 ( unsigned int V_1 )
{
return ( ( int ) V_1 - 1 ) / 2 ;
}
static int F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
const unsigned int * V_6 = V_5 -> V_7 ;
struct V_8 * V_9 =
F_3 ( V_3 , V_10 ) ;
const struct V_8 * V_11 =
F_4 ( V_3 , V_12 ) ;
struct V_8 V_13 = {
. V_14 = V_15 , . V_16 = 0 , . integer = 1
} ;
unsigned int V_17 , V_18 ;
for ( V_17 = 0 ; V_17 < F_5 ( V_19 ) ; V_17 ++ ) {
V_18 = F_1 ( V_17 ) ;
if ( ! F_6 ( V_11 , V_6 [ V_18 ] ) )
continue;
V_13 . V_14 = V_14 ( V_13 . V_14 , V_19 [ V_17 ] ) ;
V_13 . V_16 = V_16 ( V_13 . V_16 , V_19 [ V_17 ] ) ;
}
return F_7 ( V_9 , & V_13 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
const unsigned int * V_6 = V_5 -> V_7 ;
struct V_8 * V_11 =
F_3 ( V_3 , V_12 ) ;
const struct V_8 * V_9 =
F_4 ( V_3 , V_10 ) ;
struct V_8 V_13 = {
. V_14 = V_15 , . V_16 = 0 , . integer = 1
} ;
unsigned int V_17 , V_18 ;
for ( V_17 = 0 ; V_17 < F_5 ( V_19 ) ; V_17 ++ ) {
V_18 = F_1 ( V_17 ) ;
if ( ! F_6 ( V_9 , V_19 [ V_17 ] ) )
continue;
V_13 . V_14 = V_14 ( V_13 . V_14 , V_6 [ V_18 ] ) ;
V_13 . V_16 = V_16 ( V_13 . V_16 , V_6 [ V_18 ] ) ;
}
return F_7 ( V_11 , & V_13 ) ;
}
static void F_9 ( struct V_20 * V_21 ,
const unsigned int * V_6 )
{
unsigned int V_18 ;
unsigned int V_22 , V_23 ;
int V_17 ;
V_21 -> V_24 = V_15 ;
V_21 -> V_25 = 0 ;
V_21 -> V_26 = V_15 ;
V_21 -> V_27 = 0 ;
for ( V_17 = 0 ; V_17 < F_5 ( V_19 ) ; V_17 ++ ) {
V_18 = F_1 ( V_17 ) ;
V_23 = V_6 [ V_18 ] ;
if ( V_6 [ V_18 ] == 0 )
continue;
V_21 -> V_24 = V_14 ( V_21 -> V_24 , V_23 ) ;
V_21 -> V_25 = V_16 ( V_21 -> V_25 , V_23 ) ;
V_22 = V_19 [ V_17 ] ;
V_21 -> V_28 |= F_10 ( V_22 ) ;
V_21 -> V_26 = V_14 ( V_21 -> V_26 , V_22 ) ;
V_21 -> V_27 = V_16 ( V_21 -> V_27 , V_22 ) ;
}
}
static int F_11 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_35 * V_36 ;
const unsigned int * V_6 ;
int V_37 ;
if ( V_32 -> V_38 == V_39 ) {
V_34 -> V_21 . V_40 = V_41 ;
V_36 = & V_30 -> V_42 ;
V_6 = V_30 -> V_43 -> V_44 ;
} else {
V_34 -> V_21 . V_40 = V_41 ;
V_36 = & V_30 -> V_45 ;
V_6 = V_30 -> V_43 -> V_46 ;
}
F_9 ( & V_34 -> V_21 , V_6 ) ;
V_37 = F_12 ( V_34 , 0 , V_12 ,
F_8 , ( void * ) V_6 ,
V_10 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_12 ( V_34 , 0 , V_10 ,
F_2 , ( void * ) V_6 ,
V_12 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_13 ( V_36 , V_34 ) ;
}
static int F_14 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
unsigned int V_22 ;
enum V_48 V_49 ;
int V_17 , V_37 ;
V_37 = F_15 ( V_30 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_11 ( V_30 , V_32 ) ;
if ( V_37 < 0 )
goto V_50;
V_37 = V_30 -> V_43 -> V_51 -> V_52 ( V_30 , & V_22 , & V_49 ) ;
if ( V_37 < 0 )
goto V_50;
if ( V_49 != V_53 ) {
for ( V_17 = 0 ; V_17 < V_54 ; ++ V_17 ) {
if ( V_19 [ V_17 ] == V_22 )
break;
}
if ( V_17 >= V_54 ) {
V_37 = - V_55 ;
goto V_50;
}
V_32 -> V_34 -> V_21 . V_26 = V_22 ;
V_32 -> V_34 -> V_21 . V_27 = V_22 ;
} else {
if ( F_16 ( & V_30 -> V_45 ) ||
F_16 ( & V_30 -> V_42 ) ) {
V_22 = V_19 [ V_30 -> V_45 . V_56 ] ;
V_32 -> V_34 -> V_21 . V_26 = V_22 ;
V_32 -> V_34 -> V_21 . V_27 = V_22 ;
}
}
F_17 ( V_32 ) ;
return 0 ;
V_50:
F_18 ( V_30 ) ;
return V_37 ;
}
static int F_19 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
F_18 ( V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_2 * V_57 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
int V_37 ;
V_37 = F_21 ( V_32 ,
F_22 ( V_57 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_32 -> V_34 -> V_58 -> V_59 == V_60 ) {
F_23 ( & V_30 -> V_61 ) ;
V_30 -> V_62 ++ ;
F_24 ( & V_30 -> V_61 ) ;
}
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_2 * V_57 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
int V_37 ;
V_37 = F_21 ( V_32 ,
F_22 ( V_57 ) ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_32 -> V_34 -> V_58 -> V_59 == V_60 ) {
F_23 ( & V_30 -> V_61 ) ;
V_30 -> V_62 ++ ;
F_24 ( & V_30 -> V_61 ) ;
}
return 0 ;
}
static int F_26 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
F_23 ( & V_30 -> V_61 ) ;
if ( V_32 -> V_34 -> V_58 -> V_59 != V_60 )
V_30 -> V_62 -- ;
F_27 ( V_30 ) ;
F_24 ( & V_30 -> V_61 ) ;
return F_28 ( V_32 ) ;
}
static int F_29 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
F_23 ( & V_30 -> V_61 ) ;
if ( V_32 -> V_34 -> V_58 -> V_59 != V_60 )
V_30 -> V_62 -- ;
F_27 ( V_30 ) ;
F_24 ( & V_30 -> V_61 ) ;
return F_28 ( V_32 ) ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
struct V_33 * V_34 = V_32 -> V_34 ;
int V_37 ;
F_23 ( & V_30 -> V_61 ) ;
V_37 = F_31 ( V_30 , V_34 -> V_22 ) ;
if ( V_37 >= 0 )
F_32 ( & V_30 -> V_42 ) ;
F_24 ( & V_30 -> V_61 ) ;
return V_37 ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
struct V_33 * V_34 = V_32 -> V_34 ;
int V_37 ;
F_23 ( & V_30 -> V_61 ) ;
V_37 = F_31 ( V_30 , V_34 -> V_22 ) ;
if ( V_37 >= 0 )
F_32 ( & V_30 -> V_45 ) ;
F_24 ( & V_30 -> V_61 ) ;
return V_37 ;
}
static int F_34 ( struct V_31 * V_32 , int V_63 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
switch ( V_63 ) {
case V_64 :
F_35 ( & V_30 -> V_42 , V_32 ) ;
break;
case V_65 :
F_35 ( & V_30 -> V_42 , NULL ) ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static int F_36 ( struct V_31 * V_32 , int V_63 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
switch ( V_63 ) {
case V_64 :
F_35 ( & V_30 -> V_45 , V_32 ) ;
break;
case V_65 :
F_35 ( & V_30 -> V_45 , NULL ) ;
break;
default:
return - V_66 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_31 * V_67 )
{
struct V_29 * V_30 = V_67 -> V_47 ;
return F_38 ( & V_30 -> V_42 ) ;
}
static T_1 F_39 ( struct V_31 * V_67 )
{
struct V_29 * V_30 = V_67 -> V_47 ;
return F_38 ( & V_30 -> V_45 ) ;
}
static int F_40 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
return F_41 ( & V_30 -> V_42 ) ;
}
static int F_42 ( struct V_31 * V_32 )
{
struct V_29 * V_30 = V_32 -> V_47 ;
return F_41 ( & V_30 -> V_45 ) ;
}
int F_43 ( struct V_29 * V_30 )
{
static const struct V_68 V_69 = {
. V_70 = F_14 ,
. V_71 = F_19 ,
. V_72 = V_73 ,
. V_57 = F_20 ,
. V_74 = F_26 ,
. V_75 = F_30 ,
. V_76 = F_34 ,
. V_77 = F_37 ,
. V_78 = F_40 ,
. V_79 = V_80 ,
} ;
static const struct V_68 V_81 = {
. V_70 = F_14 ,
. V_71 = F_19 ,
. V_72 = V_73 ,
. V_57 = F_25 ,
. V_74 = F_29 ,
. V_75 = F_33 ,
. V_76 = F_36 ,
. V_77 = F_39 ,
. V_78 = F_42 ,
. V_79 = V_80 ,
. V_82 = V_83 ,
} ;
struct V_84 * V_85 ;
int V_37 ;
V_37 = F_44 ( V_30 -> V_86 , V_30 -> V_86 -> V_87 , 0 , 1 , 1 , & V_85 ) ;
if ( V_37 < 0 )
return V_37 ;
V_85 -> V_47 = V_30 ;
snprintf ( V_85 -> V_88 , sizeof( V_85 -> V_88 ) ,
L_1 , V_30 -> V_86 -> V_89 ) ;
F_45 ( V_85 , V_90 , & V_81 ) ;
F_45 ( V_85 , V_39 , & V_69 ) ;
return 0 ;
}
