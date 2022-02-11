static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
}
static int F_4 ( struct V_5 * V_6 , int V_7 , int V_8 )
{
int V_9 , V_10 ;
if ( V_7 < 1 )
V_7 = 1 ;
V_9 = 0 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
V_9 += F_5 ( V_6 , V_8 ) ;
V_9 /= V_7 ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_11 V_12 ,
union V_13 * V_14 )
{
struct V_15 * V_16 = F_7 ( V_2 , struct V_15 , V_2 ) ;
if ( ! V_16 ) {
F_8 ( V_2 -> V_17 , L_1 , V_18 ) ;
return - V_19 ;
}
if ( V_16 -> V_20 < 0 ||
F_9 ( V_21 - V_16 -> V_22 ) >
V_23 ) {
V_16 -> V_20 = F_4 ( V_16 -> V_6 ,
V_16 -> V_24 -> V_25 ,
V_16 -> V_24 -> V_26 ) ;
V_16 -> V_20 *= V_16 -> V_24 -> V_27 ;
V_16 -> V_22 = V_21 ;
}
switch ( V_12 ) {
case V_28 :
V_14 -> V_29 = V_16 -> V_20 ;
return 0 ;
case V_30 :
V_14 -> V_29 = V_16 -> V_24 -> V_31 ;
return 0 ;
case V_32 :
V_14 -> V_29 = V_16 -> V_24 -> V_33 ;
return 0 ;
default:
return - V_19 ;
}
}
static int F_10 ( int V_34 , int V_35 , int V_36 )
{
return V_34 + V_35 * V_36 / 1000 ;
}
static int F_11 ( struct V_15 * V_16 )
{
return V_16 -> V_24 -> V_37 ?
! F_12 ( V_16 -> V_24 -> V_38 ) :
F_12 ( V_16 -> V_24 -> V_38 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_11 V_12 ,
union V_13 * V_14 )
{
struct V_15 * V_16 = F_7 ( V_2 , struct V_15 , V_2 ) ;
int V_39 ;
int V_40 ;
const struct V_41 * V_42 = V_16 -> V_24 -> V_43 ;
unsigned int V_44 = V_16 -> V_24 -> V_45 ;
if ( ! V_16 ) {
F_8 ( V_2 -> V_17 , L_2 ) ;
return - V_19 ;
}
if ( V_16 -> V_20 < 0 || V_16 -> V_46 < 0 ||
F_9 ( V_21 - V_16 -> V_22 ) >
V_23 ) {
V_16 -> V_20 = F_4 ( V_16 -> V_6 ,
V_16 -> V_24 -> V_47 ,
V_16 -> V_24 -> V_48 ) * V_16 -> V_24 -> V_49 ;
V_16 -> V_46 = F_4 ( V_16 -> V_6 ,
V_16 -> V_24 -> V_50 ,
V_16 -> V_24 -> V_51 ) * V_16 -> V_24 -> V_52 ;
V_16 -> V_22 = V_21 ;
}
if ( V_16 -> V_53 &&
( ( V_16 -> V_24 -> V_38 < 0 ) ||
! F_11 ( V_16 ) ) ) {
V_42 = V_16 -> V_24 -> V_54 ;
V_44 = V_16 -> V_24 -> V_55 ;
}
V_39 = 100000 ;
V_40 = F_10 ( ( V_16 -> V_20 / 1000 ) ,
( V_16 -> V_46 / 1000 ) , V_16 -> V_24 -> V_56 ) ;
if ( V_40 < F_10 ( V_42 -> V_57 , V_42 -> V_58 ,
V_16 -> V_24 -> V_56 ) ) {
V_44 -- ;
while ( V_44 -- ) {
int V_59 ;
int V_60 ;
V_59 = F_10 ( V_42 [ 0 ] . V_57 , V_42 [ 0 ] . V_58 ,
V_16 -> V_24 -> V_56 ) ;
V_60 = F_10 ( V_42 [ 1 ] . V_57 , V_42 [ 1 ] . V_58 ,
V_16 -> V_24 -> V_56 ) ;
if ( V_40 < V_59 && V_40 >= V_60 ) {
V_39 = ( V_42 [ 1 ] . V_61 +
( V_42 [ 0 ] . V_61 - V_42 [ 1 ] . V_61 ) *
( V_40 - V_60 ) /
( V_59 - V_60 ) ) * 1000 ;
break;
}
V_39 = V_42 [ 1 ] . V_61 * 1000 ;
V_42 ++ ;
}
}
V_16 -> V_61 = V_39 ;
switch ( V_12 ) {
case V_62 :
if ( V_16 -> V_24 -> V_38 < 0 )
V_14 -> V_29 = V_16 -> V_61 == 100000 ?
V_63 : V_16 -> V_64 ;
else
V_14 -> V_29 = V_16 -> V_64 ;
return 0 ;
case V_65 :
V_14 -> V_29 = 100000 ;
return 0 ;
case V_66 :
V_14 -> V_29 = 0 ;
return 0 ;
case V_67 :
V_14 -> V_29 = V_16 -> V_61 ;
return 0 ;
case V_28 :
V_14 -> V_29 = V_16 -> V_20 ;
return 0 ;
case V_68 :
V_14 -> V_29 = V_16 -> V_46 ;
return 0 ;
default:
return - V_19 ;
}
}
static void F_14 ( struct V_69 * V_70 )
{
struct V_15 * V_16 = & V_71 ;
int V_72 ;
int V_73 ;
static int V_74 ;
V_73 = F_15 ( & V_16 -> V_2 ) ;
V_16 -> V_53 = V_73 ;
if ( V_73 != V_74 ) {
V_74 = V_73 ;
if ( V_73 ) {
if ( V_16 -> V_24 -> V_75 )
V_16 -> V_24 -> V_75 () ;
V_16 -> V_64 = V_76 ;
} else {
if ( V_16 -> V_24 -> V_77 )
V_16 -> V_24 -> V_77 () ;
V_16 -> V_64 = V_78 ;
}
} else {
if ( ( V_16 -> V_24 -> V_38 >= 0 ) && V_73 ) {
V_72 = F_11 ( & V_71 ) ;
if ( V_72 ) {
if ( V_16 -> V_24 -> V_77 )
V_16 -> V_24 -> V_77 () ;
V_16 -> V_64 = V_63 ;
} else {
if ( V_16 -> V_24 -> V_75 )
V_16 -> V_24 -> V_75 () ;
V_16 -> V_64 = V_76 ;
}
}
}
F_16 ( & V_16 -> V_2 ) ;
}
static T_1 F_17 ( int V_79 , void * V_80 )
{
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
return V_81 ;
}
static int T_2 F_18 ( struct V_82 * V_83 )
{
struct V_5 * V_6 ;
struct V_84 * V_24 = V_83 -> V_17 . V_85 ;
int V_86 ;
V_6 = F_19 ( V_83 , NULL , NULL , 0 ) ;
if ( F_20 ( V_6 ) ) {
F_8 ( & V_83 -> V_17 , L_3 ) ;
return F_21 ( V_6 ) ;
}
F_22 ( V_83 , V_6 ) ;
V_71 . V_6 = V_6 ;
V_71 . V_24 = V_24 ;
V_71 . V_20 = - 1 ;
V_71 . V_46 = - 1 ;
V_71 . V_53 = 0 ;
V_71 . V_64 = V_78 ;
V_86 = F_23 ( & V_83 -> V_17 , & V_71 . V_2 ) ;
if ( V_86 )
goto V_87;
if ( V_24 -> V_27 ) {
V_88 . V_6 = V_6 ;
V_88 . V_24 = V_83 -> V_17 . V_85 ;
V_88 . V_20 = - 1 ;
V_86 = F_23 ( & V_83 -> V_17 , & V_88 . V_2 ) ;
if ( V_86 )
goto V_89;
}
F_24 ( & V_3 , F_14 ) ;
if ( V_24 -> V_38 >= 0 ) {
V_86 = F_25 ( V_24 -> V_38 , L_4 ) ;
if ( V_86 )
goto V_90;
V_86 = F_26 ( F_27 ( V_24 -> V_38 ) ,
F_17 ,
V_91 | V_92 ,
L_5 , NULL ) ;
if ( V_86 )
goto V_93;
}
if ( V_24 -> V_94 ) {
V_86 = V_24 -> V_94 () ;
if ( V_86 )
goto V_95;
}
F_28 ( & V_83 -> V_17 , L_6 ) ;
F_29 ( & V_83 -> V_17 , 1 ) ;
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
return 0 ;
V_95:
if ( V_24 -> V_38 >= 0 )
F_30 ( F_27 ( V_24 -> V_38 ) , NULL ) ;
V_93:
if ( V_24 -> V_38 >= 0 )
F_31 ( V_24 -> V_38 ) ;
V_90:
if ( V_24 -> V_27 )
F_32 ( & V_88 . V_2 ) ;
V_89:
F_32 ( & V_71 . V_2 ) ;
V_87:
return V_86 ;
}
static int F_33 ( struct V_82 * V_83 )
{
struct V_5 * V_6 = F_34 ( V_83 ) ;
struct V_84 * V_24 = V_83 -> V_17 . V_85 ;
F_32 ( & V_71 . V_2 ) ;
if ( V_24 -> V_27 )
F_32 ( & V_88 . V_2 ) ;
F_35 ( V_6 ) ;
if ( V_24 -> V_38 >= 0 ) {
F_30 ( F_27 ( V_24 -> V_38 ) , NULL ) ;
F_31 ( V_24 -> V_38 ) ;
}
F_36 ( & V_3 ) ;
if ( V_24 -> exit )
V_24 -> exit () ;
return 0 ;
}
static int F_37 ( struct V_82 * V_83 ,
T_3 V_96 )
{
struct V_84 * V_24 = V_83 -> V_17 . V_85 ;
if ( V_24 -> V_38 >= 0 ) {
if ( F_38 ( & V_83 -> V_17 ) )
F_39 (
F_27 ( V_24 -> V_38 ) ) ;
else {
F_40 ( F_27 ( V_24 -> V_38 ) ) ;
V_71 . V_24 -> V_77 () ;
}
}
return 0 ;
}
static int F_41 ( struct V_82 * V_83 )
{
struct V_84 * V_24 = V_83 -> V_17 . V_85 ;
if ( V_24 -> V_38 >= 0 ) {
if ( F_38 ( & V_83 -> V_17 ) )
F_42 (
F_27 ( V_24 -> V_38 ) ) ;
else
F_43 ( F_27 ( V_24 -> V_38 ) ) ;
}
F_2 ( & V_3 ,
F_3 ( V_4 ) ) ;
return 0 ;
}
