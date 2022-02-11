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
static void F_11 ( struct V_20 * V_21 )
{
V_21 -> V_29 = 2 ;
V_21 -> V_30 = V_15 ;
V_21 -> V_31 = 4 * V_21 -> V_25 ;
V_21 -> V_32 = V_21 -> V_31 * 2048 ;
V_21 -> V_33 = V_21 -> V_32 * V_21 -> V_29 ;
}
static int F_12 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_40 * V_41 ;
const unsigned int * V_6 ;
int V_42 ;
V_39 -> V_21 . V_43 = V_44 |
V_45 |
V_46 |
V_47 |
V_48 |
V_49 ;
if ( V_37 -> V_50 == V_51 ) {
V_39 -> V_21 . V_52 = V_53 ;
V_41 = & V_35 -> V_54 ;
V_6 = V_35 -> V_55 -> V_56 ;
} else {
V_39 -> V_21 . V_52 = V_53 ;
V_41 = & V_35 -> V_57 ;
V_6 = V_35 -> V_55 -> V_58 ;
}
F_9 ( & V_39 -> V_21 , V_6 ) ;
F_11 ( & V_39 -> V_21 ) ;
V_42 = F_13 ( V_39 , 0 , V_12 ,
F_8 , ( void * ) V_6 ,
V_10 , - 1 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_13 ( V_39 , 0 , V_10 ,
F_2 , ( void * ) V_6 ,
V_12 , - 1 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_14 ( V_41 , V_39 ) ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
unsigned int V_22 ;
enum V_60 V_61 ;
int V_17 , V_42 ;
V_42 = F_16 ( V_35 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_12 ( V_35 , V_37 ) ;
if ( V_42 < 0 ) {
F_17 ( V_35 ) ;
return V_42 ;
}
V_42 = V_35 -> V_55 -> V_62 -> V_63 ( V_35 , & V_22 , & V_61 ) ;
if ( V_42 < 0 ) {
F_17 ( V_35 ) ;
return V_42 ;
}
if ( V_61 != V_64 ) {
for ( V_17 = 0 ; V_17 < V_65 ; ++ V_17 ) {
if ( V_19 [ V_17 ] == V_22 )
break;
}
if ( V_17 >= V_65 ) {
F_17 ( V_35 ) ;
return - V_66 ;
}
V_37 -> V_39 -> V_21 . V_26 = V_22 ;
V_37 -> V_39 -> V_21 . V_27 = V_22 ;
} else {
if ( F_18 ( & V_35 -> V_57 ) ||
F_18 ( & V_35 -> V_54 ) ) {
V_22 = V_19 [ V_35 -> V_57 . V_67 ] ;
V_37 -> V_39 -> V_21 . V_26 = V_22 ;
V_37 -> V_39 -> V_21 . V_27 = V_22 ;
}
}
F_19 ( V_37 ) ;
return 0 ;
}
static int F_20 ( struct V_36 * V_37 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
F_17 ( V_35 ) ;
return 0 ;
}
static int F_21 ( struct V_36 * V_37 ,
struct V_2 * V_68 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
int V_42 ;
V_42 = F_22 ( V_37 ,
F_23 ( V_68 ) ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_37 -> V_39 -> V_69 -> V_70 == V_71 ) {
F_24 ( & V_35 -> V_72 ) ;
V_35 -> V_73 ++ ;
F_25 ( & V_35 -> V_72 ) ;
}
return 0 ;
}
static int F_26 ( struct V_36 * V_37 ,
struct V_2 * V_68 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
int V_42 ;
V_42 = F_22 ( V_37 ,
F_23 ( V_68 ) ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_37 -> V_39 -> V_69 -> V_70 == V_71 ) {
F_24 ( & V_35 -> V_72 ) ;
V_35 -> V_73 ++ ;
F_25 ( & V_35 -> V_72 ) ;
}
return 0 ;
}
static int F_27 ( struct V_36 * V_37 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
F_24 ( & V_35 -> V_72 ) ;
if ( V_37 -> V_39 -> V_69 -> V_70 != V_71 )
V_35 -> V_73 -- ;
F_28 ( V_35 ) ;
F_25 ( & V_35 -> V_72 ) ;
return F_29 ( V_37 ) ;
}
static int F_30 ( struct V_36 * V_37 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
F_24 ( & V_35 -> V_72 ) ;
if ( V_37 -> V_39 -> V_69 -> V_70 != V_71 )
V_35 -> V_73 -- ;
F_28 ( V_35 ) ;
F_25 ( & V_35 -> V_72 ) ;
return F_29 ( V_37 ) ;
}
static int F_31 ( struct V_36 * V_37 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
struct V_38 * V_39 = V_37 -> V_39 ;
int V_42 ;
F_24 ( & V_35 -> V_72 ) ;
V_42 = F_32 ( V_35 , V_39 -> V_22 ) ;
if ( V_42 >= 0 )
F_33 ( & V_35 -> V_54 ) ;
F_25 ( & V_35 -> V_72 ) ;
return V_42 ;
}
static int F_34 ( struct V_36 * V_37 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
struct V_38 * V_39 = V_37 -> V_39 ;
int V_42 ;
F_24 ( & V_35 -> V_72 ) ;
V_42 = F_32 ( V_35 , V_39 -> V_22 ) ;
if ( V_42 >= 0 )
F_33 ( & V_35 -> V_57 ) ;
F_25 ( & V_35 -> V_72 ) ;
return V_42 ;
}
static int F_35 ( struct V_36 * V_37 , int V_74 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
switch ( V_74 ) {
case V_75 :
F_36 ( & V_35 -> V_54 , V_37 ) ;
break;
case V_76 :
F_36 ( & V_35 -> V_54 , NULL ) ;
break;
default:
return - V_77 ;
}
return 0 ;
}
static int F_37 ( struct V_36 * V_37 , int V_74 )
{
struct V_34 * V_35 = V_37 -> V_59 ;
switch ( V_74 ) {
case V_75 :
F_36 ( & V_35 -> V_57 , V_37 ) ;
break;
case V_76 :
F_36 ( & V_35 -> V_57 , NULL ) ;
break;
default:
return - V_77 ;
}
return 0 ;
}
static T_1 F_38 ( struct V_36 * V_78 )
{
struct V_34 * V_35 = V_78 -> V_59 ;
return F_39 ( & V_35 -> V_54 ) ;
}
static T_1 F_40 ( struct V_36 * V_78 )
{
struct V_34 * V_35 = V_78 -> V_59 ;
return F_39 ( & V_35 -> V_57 ) ;
}
int F_41 ( struct V_34 * V_35 )
{
struct V_79 * V_80 ;
int V_42 ;
V_42 = F_42 ( V_35 -> V_81 , V_35 -> V_81 -> V_82 , 0 , 1 , 1 , & V_80 ) ;
if ( V_42 < 0 )
return V_42 ;
V_80 -> V_59 = V_35 ;
snprintf ( V_80 -> V_83 , sizeof( V_80 -> V_83 ) ,
L_1 , V_35 -> V_81 -> V_84 ) ;
F_43 ( V_80 , V_85 , & V_86 ) ;
F_43 ( V_80 , V_51 , & V_87 ) ;
return 0 ;
}
