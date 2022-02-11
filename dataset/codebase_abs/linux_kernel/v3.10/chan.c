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
case V_19 :
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
case V_20 :
if ( V_2 -> V_11 != V_18 + 30 &&
V_2 -> V_11 != V_18 + 10 &&
V_2 -> V_11 != V_18 - 10 &&
V_2 -> V_11 != V_18 - 30 )
return false ;
if ( V_2 -> V_7 )
return false ;
break;
case V_21 :
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
static void F_4 ( const struct V_1 * V_22 ,
int * V_23 , int * V_24 )
{
int V_25 ;
switch ( V_22 -> V_9 ) {
case V_16 :
* V_23 = V_22 -> V_11 ;
* V_24 = 0 ;
break;
case V_20 :
case V_19 :
* V_24 = V_22 -> V_11 ;
V_25 = ( 30 + V_22 -> V_4 -> V_12 - V_22 -> V_11 ) / 20 ;
V_25 /= 2 ;
* V_23 = V_22 -> V_11 - 20 + 40 * V_25 ;
break;
case V_21 :
V_25 = ( 70 + V_22 -> V_4 -> V_12 - V_22 -> V_11 ) / 20 ;
V_25 /= 2 ;
* V_23 = V_22 -> V_11 - 60 + 40 * V_25 ;
V_25 /= 2 ;
* V_24 = V_22 -> V_11 - 40 + 80 * V_25 ;
break;
default:
F_5 ( 1 ) ;
}
}
static int F_6 ( const struct V_1 * V_22 )
{
int V_9 ;
switch ( V_22 -> V_9 ) {
case V_14 :
case V_10 :
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
break;
case V_19 :
case V_20 :
V_9 = 80 ;
break;
case V_21 :
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return - 1 ;
}
return V_9 ;
}
const struct V_1 *
F_7 ( const struct V_1 * V_26 ,
const struct V_1 * V_27 )
{
T_1 V_28 , V_29 , V_30 , V_31 ;
if ( F_8 ( V_26 , V_27 ) )
return V_26 ;
if ( V_26 -> V_4 != V_27 -> V_4 )
return NULL ;
if ( V_26 -> V_9 == V_27 -> V_9 )
return NULL ;
if ( V_26 -> V_9 == V_10 ||
V_26 -> V_9 == V_14 )
return V_27 ;
if ( V_27 -> V_9 == V_10 ||
V_27 -> V_9 == V_14 )
return V_26 ;
F_4 ( V_26 , & V_28 , & V_29 ) ;
F_4 ( V_27 , & V_30 , & V_31 ) ;
if ( V_28 != V_30 )
return NULL ;
F_2 ( ! V_29 && ! V_31 ) ;
if ( V_29 && V_31 && V_29 != V_31 )
return NULL ;
if ( V_26 -> V_9 > V_27 -> V_9 )
return V_26 ;
return V_27 ;
}
static void F_9 ( struct V_32 * V_32 , T_1 V_12 ,
T_1 V_33 ,
enum V_34 V_35 )
{
struct V_3 * V_22 ;
T_1 V_36 ;
for ( V_36 = V_12 - V_33 / 2 + 10 ;
V_36 <= V_12 + V_33 / 2 - 10 ;
V_36 += 20 ) {
V_22 = F_10 ( V_32 , V_36 ) ;
if ( ! V_22 || ! ( V_22 -> V_37 & V_38 ) )
continue;
V_22 -> V_35 = V_35 ;
V_22 -> V_39 = V_40 ;
}
}
void F_11 ( struct V_32 * V_32 ,
const struct V_1 * V_2 ,
enum V_34 V_35 )
{
int V_9 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return;
F_9 ( V_32 , V_2 -> V_11 ,
V_9 , V_35 ) ;
if ( ! V_2 -> V_7 )
return;
F_9 ( V_32 , V_2 -> V_7 ,
V_9 , V_35 ) ;
}
static int F_12 ( struct V_32 * V_32 ,
T_1 V_12 ,
T_1 V_33 )
{
struct V_3 * V_22 ;
T_1 V_36 ;
for ( V_36 = V_12 - V_33 / 2 + 10 ;
V_36 <= V_12 + V_33 / 2 - 10 ;
V_36 += 20 ) {
V_22 = F_10 ( V_32 , V_36 ) ;
if ( ! V_22 )
return - V_41 ;
if ( V_22 -> V_37 & V_38 )
return 1 ;
}
return 0 ;
}
int F_13 ( struct V_32 * V_32 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_42 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return - V_41 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return - V_41 ;
V_42 = F_12 ( V_32 , V_2 -> V_11 ,
V_9 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_2 -> V_7 )
return 0 ;
return F_12 ( V_32 , V_2 -> V_7 ,
V_9 ) ;
}
static bool F_14 ( struct V_32 * V_32 ,
T_1 V_12 , T_1 V_33 ,
T_1 V_43 )
{
struct V_3 * V_22 ;
T_1 V_36 ;
for ( V_36 = V_12 - V_33 / 2 + 10 ;
V_36 <= V_12 + V_33 / 2 - 10 ;
V_36 += 20 ) {
V_22 = F_10 ( V_32 , V_36 ) ;
if ( ! V_22 )
return false ;
if ( ( V_43 & V_22 -> V_37 & V_38 ) &&
( V_22 -> V_35 != V_44 ) )
return false ;
if ( V_22 -> V_37 & V_43 & ~ V_38 )
return false ;
}
return true ;
}
bool F_15 ( struct V_32 * V_32 ,
const struct V_1 * V_2 ,
T_1 V_43 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_1 V_9 , V_18 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_46 = & V_32 -> V_49 [ V_2 -> V_4 -> V_50 ] -> V_46 ;
V_48 = & V_32 -> V_49 [ V_2 -> V_4 -> V_50 ] -> V_48 ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_14 :
if ( ! V_46 -> V_51 )
return false ;
case V_10 :
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
if ( ! V_46 -> V_51 )
return false ;
if ( ! ( V_46 -> V_52 & V_53 ) ||
V_46 -> V_52 & V_54 )
return false ;
if ( V_2 -> V_11 < V_18 &&
V_2 -> V_4 -> V_37 & V_55 )
return false ;
if ( V_2 -> V_11 > V_18 &&
V_2 -> V_4 -> V_37 & V_56 )
return false ;
break;
case V_19 :
if ( ! ( V_48 -> V_52 & V_57 ) )
return false ;
case V_20 :
if ( ! V_48 -> V_58 )
return false ;
V_43 |= V_59 ;
V_9 = 80 ;
break;
case V_21 :
if ( ! V_48 -> V_58 )
return false ;
if ( ! ( V_48 -> V_52 & V_60 ) )
return false ;
V_43 |= V_61 ;
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return false ;
}
if ( V_9 > 20 )
V_43 |= V_62 ;
if ( ! F_14 ( V_32 , V_2 -> V_11 ,
V_9 , V_43 ) )
return false ;
if ( ! V_2 -> V_7 )
return true ;
return F_14 ( V_32 , V_2 -> V_7 ,
V_9 , V_43 ) ;
}
bool F_16 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
bool V_63 ;
F_17 ( V_32 , V_2 ) ;
V_63 = F_15 ( V_32 , V_2 ,
V_64 |
V_65 |
V_66 |
V_38 ) ;
F_18 ( V_63 ) ;
return V_63 ;
}
int F_19 ( struct V_67 * V_68 ,
struct V_1 * V_2 )
{
if ( ! V_68 -> V_69 -> V_70 )
return - V_71 ;
if ( ! F_20 ( V_68 ) )
return - V_72 ;
return F_21 ( V_68 , V_2 ) ;
}
void
F_22 ( struct V_73 * V_74 ,
struct V_3 * * V_4 ,
enum V_75 * V_76 )
{
* V_4 = NULL ;
* V_76 = V_77 ;
F_23 ( V_74 ) ;
if ( V_74 -> V_78 && ! F_24 ( V_74 -> V_78 ) )
return;
switch ( V_74 -> V_79 ) {
case V_80 :
if ( V_74 -> V_81 ) {
* V_4 = V_74 -> V_81 -> V_82 . V_83 ;
* V_76 = V_74 -> V_84
? V_85
: V_86 ;
return;
}
case V_87 :
case V_88 :
if ( V_74 -> V_81 ) {
* V_4 = V_74 -> V_81 -> V_82 . V_83 ;
* V_76 = V_85 ;
return;
}
break;
case V_89 :
case V_90 :
if ( V_74 -> V_91 ) {
* V_4 = V_74 -> V_83 ;
* V_76 = V_85 ;
} else if ( V_74 -> V_92 ) {
* V_4 = V_74 -> V_83 ;
* V_76 = V_85 ;
}
return;
case V_93 :
if ( V_74 -> V_94 ) {
* V_4 = V_74 -> V_83 ;
* V_76 = V_85 ;
}
return;
case V_95 :
case V_96 :
case V_97 :
return;
case V_98 :
if ( V_74 -> V_32 -> V_99 &
V_100 )
* V_76 = V_86 ;
return;
case V_101 :
case V_102 :
F_2 ( 1 ) ;
}
return;
}
