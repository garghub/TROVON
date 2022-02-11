void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
if ( F_2 ( ! V_4 ) )
return;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = 0 ;
switch ( V_6 ) {
case V_8 :
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_4 -> V_12 ;
break;
case V_13 :
V_2 -> V_9 = V_14 ;
V_2 -> V_11 = V_4 -> V_12 ;
break;
case V_15 :
V_2 -> V_9 = V_16 ;
V_2 -> V_11 = V_4 -> V_12 + 10 ;
break;
case V_17 :
V_2 -> V_9 = V_16 ;
V_2 -> V_11 = V_4 -> V_12 - 10 ;
break;
default:
F_2 ( 1 ) ;
}
}
bool F_3 ( const struct V_1 * V_2 )
{
T_1 V_18 ;
if ( ! V_2 -> V_4 )
return false ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_19 :
case V_20 :
case V_14 :
case V_10 :
if ( V_2 -> V_11 != V_18 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_16 :
if ( V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_21 :
if ( V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 )
return false ;
if ( ! V_2 -> V_7 )
return false ;
if ( V_2 -> V_11 - V_2 -> V_7 == 80 ||
V_2 -> V_7 - V_2 -> V_11 == 80 )
return false ;
break;
case V_22 :
if ( V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_23 :
if ( V_2 -> V_11 != V_18 + 70 &&
V_2 -> V_11 != V_18 + 50 &&
V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 &&
V_2 -> V_11 != V_18 - 50 &&
V_2 -> V_11 != V_18 - 70 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
default:
return false ;
}
return true ;
}
static void F_4 ( const struct V_1 * V_24 ,
int * V_25 , int * V_26 )
{
int V_27 ;
switch ( V_24 -> V_9 ) {
case V_16 :
* V_25 = V_24 -> V_11 ;
* V_26 = 0 ;
break;
case V_22 :
case V_21 :
* V_26 = V_24 -> V_11 ;
V_27 = ( 30 + V_24 -> V_4 -> V_12 - V_24 -> V_11 ) / 20 ;
V_27 /= 2 ;
* V_25 = V_24 -> V_11 - 20 + 40 * V_27 ;
break;
case V_23 :
V_27 = ( 70 + V_24 -> V_4 -> V_12 - V_24 -> V_11 ) / 20 ;
V_27 /= 2 ;
* V_25 = V_24 -> V_11 - 60 + 40 * V_27 ;
V_27 /= 2 ;
* V_26 = V_24 -> V_11 - 40 + 80 * V_27 ;
break;
default:
F_5 ( 1 ) ;
}
}
static int F_6 ( const struct V_1 * V_24 )
{
int V_9 ;
switch ( V_24 -> V_9 ) {
case V_19 :
V_9 = 5 ;
break;
case V_20 :
V_9 = 10 ;
break;
case V_14 :
case V_10 :
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
break;
case V_21 :
case V_22 :
V_9 = 80 ;
break;
case V_23 :
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return - 1 ;
}
return V_9 ;
}
const struct V_1 *
F_7 ( const struct V_1 * V_28 ,
const struct V_1 * V_29 )
{
T_1 V_30 , V_31 , V_32 , V_33 ;
if ( F_8 ( V_28 , V_29 ) )
return V_28 ;
if ( V_28 -> V_4 != V_29 -> V_4 )
return NULL ;
if ( V_28 -> V_9 == V_29 -> V_9 )
return NULL ;
if ( V_28 -> V_9 == V_19 ||
V_28 -> V_9 == V_20 ||
V_29 -> V_9 == V_19 ||
V_29 -> V_9 == V_20 )
return NULL ;
if ( V_28 -> V_9 == V_10 ||
V_28 -> V_9 == V_14 )
return V_29 ;
if ( V_29 -> V_9 == V_10 ||
V_29 -> V_9 == V_14 )
return V_28 ;
F_4 ( V_28 , & V_30 , & V_31 ) ;
F_4 ( V_29 , & V_32 , & V_33 ) ;
if ( V_30 != V_32 )
return NULL ;
F_2 ( ! V_31 && ! V_33 ) ;
if ( V_31 && V_33 && V_31 != V_33 )
return NULL ;
if ( V_28 -> V_9 > V_29 -> V_9 )
return V_28 ;
return V_29 ;
}
static void F_9 ( struct V_34 * V_34 , T_1 V_12 ,
T_1 V_35 ,
enum V_36 V_37 )
{
struct V_3 * V_24 ;
T_1 V_38 ;
for ( V_38 = V_12 - V_35 / 2 + 10 ;
V_38 <= V_12 + V_35 / 2 - 10 ;
V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 || ! ( V_24 -> V_39 & V_40 ) )
continue;
V_24 -> V_37 = V_37 ;
V_24 -> V_41 = V_42 ;
}
}
void F_11 ( struct V_34 * V_34 ,
const struct V_1 * V_2 ,
enum V_36 V_37 )
{
int V_9 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return;
F_9 ( V_34 , V_2 -> V_11 ,
V_9 , V_37 ) ;
if ( ! V_2 -> V_7 )
return;
F_9 ( V_34 , V_2 -> V_7 ,
V_9 , V_37 ) ;
}
static T_1 F_12 ( T_1 V_12 ,
T_1 V_35 )
{
T_1 V_43 ;
if ( V_35 <= 20 )
V_43 = V_12 ;
else
V_43 = V_12 - V_35 / 2 + 10 ;
return V_43 ;
}
static T_1 F_13 ( T_1 V_12 ,
T_1 V_35 )
{
T_1 V_44 ;
if ( V_35 <= 20 )
V_44 = V_12 ;
else
V_44 = V_12 + V_35 / 2 - 10 ;
return V_44 ;
}
static int F_14 ( struct V_34 * V_34 ,
T_1 V_12 ,
T_1 V_35 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return - V_45 ;
if ( V_24 -> V_39 & V_40 )
return 1 ;
}
return 0 ;
}
int F_15 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_46 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return - V_45 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return - V_45 ;
V_46 = F_14 ( V_34 , V_2 -> V_11 ,
V_9 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_2 -> V_7 )
return 0 ;
return F_14 ( V_34 , V_2 -> V_7 ,
V_9 ) ;
}
static int F_16 ( struct V_34 * V_34 ,
T_1 V_12 ,
T_1 V_35 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
int V_47 = 0 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return - V_45 ;
if ( V_24 -> V_39 & V_48 )
return - V_45 ;
if ( V_24 -> V_39 & V_40 ) {
if ( V_24 -> V_37 == V_49 )
return - V_45 ;
if ( V_24 -> V_37 == V_50 )
V_47 ++ ;
}
}
return V_47 ;
}
bool F_17 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_51 , V_52 = 0 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return false ;
V_51 = F_16 ( V_34 , V_2 -> V_11 ,
V_9 ) ;
if ( V_51 < 0 )
return false ;
switch ( V_2 -> V_9 ) {
case V_21 :
F_2 ( ! V_2 -> V_7 ) ;
V_52 = F_16 ( V_34 ,
V_2 -> V_7 ,
V_9 ) ;
if ( V_52 < 0 )
return false ;
break;
default:
F_2 ( V_2 -> V_7 ) ;
break;
}
return ( V_51 + V_52 > 0 ) ;
}
static bool F_18 ( struct V_34 * V_34 ,
T_1 V_12 ,
T_1 V_35 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return false ;
if ( V_24 -> V_39 & V_48 )
return false ;
if ( ( V_24 -> V_39 & V_40 ) &&
( V_24 -> V_37 != V_53 ) )
return false ;
}
return true ;
}
static bool F_19 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_46 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return false ;
V_46 = F_18 ( V_34 , V_2 -> V_11 ,
V_9 ) ;
if ( ! V_46 )
return V_46 ;
switch ( V_2 -> V_9 ) {
case V_21 :
F_2 ( ! V_2 -> V_7 ) ;
V_46 = F_18 ( V_34 ,
V_2 -> V_7 ,
V_9 ) ;
default:
F_2 ( V_2 -> V_7 ) ;
break;
}
return V_46 ;
}
static bool F_20 ( struct V_34 * V_34 ,
T_1 V_12 , T_1 V_35 ,
T_1 V_54 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 || V_24 -> V_39 & V_54 )
return false ;
}
return true ;
}
bool F_21 ( struct V_34 * V_34 ,
const struct V_1 * V_2 ,
T_1 V_54 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_1 V_9 , V_18 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_56 = & V_34 -> V_59 [ V_2 -> V_4 -> V_60 ] -> V_56 ;
V_58 = & V_34 -> V_59 [ V_2 -> V_4 -> V_60 ] -> V_58 ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_19 :
V_9 = 5 ;
break;
case V_20 :
V_9 = 10 ;
break;
case V_14 :
if ( ! V_56 -> V_61 )
return false ;
case V_10 :
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
if ( ! V_56 -> V_61 )
return false ;
if ( ! ( V_56 -> V_62 & V_63 ) ||
V_56 -> V_62 & V_64 )
return false ;
if ( V_2 -> V_11 < V_18 &&
V_2 -> V_4 -> V_39 & V_65 )
return false ;
if ( V_2 -> V_11 > V_18 &&
V_2 -> V_4 -> V_39 & V_66 )
return false ;
break;
case V_21 :
if ( ! ( V_58 -> V_62 & V_67 ) )
return false ;
case V_22 :
if ( ! V_58 -> V_68 )
return false ;
V_54 |= V_69 ;
V_9 = 80 ;
break;
case V_23 :
if ( ! V_58 -> V_68 )
return false ;
if ( ! ( V_58 -> V_62 & V_70 ) )
return false ;
V_54 |= V_71 ;
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return false ;
}
if ( V_9 > 20 )
V_54 |= V_72 ;
if ( V_9 < 20 )
V_54 |= V_72 ;
if ( ! F_20 ( V_34 , V_2 -> V_11 ,
V_9 , V_54 ) )
return false ;
if ( ! V_2 -> V_7 )
return true ;
return F_20 ( V_34 , V_2 -> V_7 ,
V_9 , V_54 ) ;
}
bool F_22 ( struct V_34 * V_34 ,
struct V_1 * V_2 )
{
bool V_73 ;
T_1 V_54 = V_48 |
V_74 |
V_40 ;
F_23 ( V_34 , V_2 ) ;
if ( F_15 ( V_34 , V_2 ) > 0 &&
F_19 ( V_34 , V_2 ) ) {
V_54 = V_48 ;
}
V_73 = F_21 ( V_34 , V_2 , V_54 ) ;
F_24 ( V_73 ) ;
return V_73 ;
}
int F_25 ( struct V_75 * V_76 ,
struct V_1 * V_2 )
{
if ( ! V_76 -> V_77 -> V_78 )
return - V_79 ;
if ( ! F_26 ( V_76 ) )
return - V_80 ;
return F_27 ( V_76 , V_2 ) ;
}
void
F_28 ( struct V_81 * V_82 ,
struct V_3 * * V_4 ,
enum V_83 * V_84 )
{
* V_4 = NULL ;
* V_84 = V_85 ;
F_29 ( V_82 ) ;
if ( V_82 -> V_86 && ! F_30 ( V_82 -> V_86 ) )
return;
switch ( V_82 -> V_87 ) {
case V_88 :
if ( V_82 -> V_89 ) {
* V_4 = V_82 -> V_89 -> V_90 . V_91 ;
* V_84 = ( V_82 -> V_92 &&
! V_82 -> V_93 )
? V_94
: V_95 ;
return;
}
break;
case V_96 :
case V_97 :
if ( V_82 -> V_89 ) {
* V_4 = V_82 -> V_89 -> V_90 . V_91 ;
* V_84 = V_94 ;
return;
}
break;
case V_98 :
case V_99 :
if ( V_82 -> V_100 ) {
* V_4 = V_82 -> V_91 ;
* V_84 = V_94 ;
} else if ( V_82 -> V_101 ) {
* V_4 = V_82 -> V_91 ;
* V_84 = V_94 ;
}
return;
case V_102 :
if ( V_82 -> V_103 ) {
* V_4 = V_82 -> V_91 ;
* V_84 = V_94 ;
}
return;
case V_104 :
case V_105 :
case V_106 :
return;
case V_107 :
if ( V_82 -> V_34 -> V_108 &
V_109 )
* V_84 = V_95 ;
return;
case V_110 :
case V_111 :
F_2 ( 1 ) ;
}
return;
}
