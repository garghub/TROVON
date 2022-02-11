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
static int F_12 ( struct V_34 * V_34 ,
T_1 V_12 ,
T_1 V_35 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
if ( V_35 <= 20 ) {
V_43 = V_12 ;
V_44 = V_12 ;
} else {
V_43 = V_12 - V_35 / 2 + 10 ;
V_44 = V_12 + V_35 / 2 - 10 ;
}
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return - V_45 ;
if ( V_24 -> V_39 & V_40 )
return 1 ;
}
return 0 ;
}
int F_13 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_46 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return - V_45 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return - V_45 ;
V_46 = F_12 ( V_34 , V_2 -> V_11 ,
V_9 ) ;
if ( V_46 )
return V_46 ;
if ( ! V_2 -> V_7 )
return 0 ;
return F_12 ( V_34 , V_2 -> V_7 ,
V_9 ) ;
}
static bool F_14 ( struct V_34 * V_34 ,
T_1 V_12 , T_1 V_35 ,
T_1 V_47 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
if ( V_35 <= 20 ) {
V_43 = V_12 ;
V_44 = V_12 ;
} else {
V_43 = V_12 - V_35 / 2 + 10 ;
V_44 = V_12 + V_35 / 2 - 10 ;
}
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return false ;
if ( ( V_47 & V_24 -> V_39 & V_40 ) &&
( V_24 -> V_37 != V_48 ) )
return false ;
if ( V_24 -> V_39 & V_47 & ~ V_40 )
return false ;
}
return true ;
}
bool F_15 ( struct V_34 * V_34 ,
const struct V_1 * V_2 ,
T_1 V_47 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_1 V_9 , V_18 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_50 = & V_34 -> V_53 [ V_2 -> V_4 -> V_54 ] -> V_50 ;
V_52 = & V_34 -> V_53 [ V_2 -> V_4 -> V_54 ] -> V_52 ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_19 :
V_9 = 5 ;
break;
case V_20 :
V_9 = 10 ;
break;
case V_14 :
if ( ! V_50 -> V_55 )
return false ;
case V_10 :
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
if ( ! V_50 -> V_55 )
return false ;
if ( ! ( V_50 -> V_56 & V_57 ) ||
V_50 -> V_56 & V_58 )
return false ;
if ( V_2 -> V_11 < V_18 &&
V_2 -> V_4 -> V_39 & V_59 )
return false ;
if ( V_2 -> V_11 > V_18 &&
V_2 -> V_4 -> V_39 & V_60 )
return false ;
break;
case V_21 :
if ( ! ( V_52 -> V_56 & V_61 ) )
return false ;
case V_22 :
if ( ! V_52 -> V_62 )
return false ;
V_47 |= V_63 ;
V_9 = 80 ;
break;
case V_23 :
if ( ! V_52 -> V_62 )
return false ;
if ( ! ( V_52 -> V_56 & V_64 ) )
return false ;
V_47 |= V_65 ;
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return false ;
}
if ( V_9 > 20 )
V_47 |= V_66 ;
if ( V_9 < 20 )
V_47 |= V_66 ;
if ( ! F_14 ( V_34 , V_2 -> V_11 ,
V_9 , V_47 ) )
return false ;
if ( ! V_2 -> V_7 )
return true ;
return F_14 ( V_34 , V_2 -> V_7 ,
V_9 , V_47 ) ;
}
bool F_16 ( struct V_34 * V_34 ,
struct V_1 * V_2 )
{
bool V_67 ;
F_17 ( V_34 , V_2 ) ;
V_67 = F_15 ( V_34 , V_2 ,
V_68 |
V_69 |
V_70 |
V_40 ) ;
F_18 ( V_67 ) ;
return V_67 ;
}
int F_19 ( struct V_71 * V_72 ,
struct V_1 * V_2 )
{
if ( ! V_72 -> V_73 -> V_74 )
return - V_75 ;
if ( ! F_20 ( V_72 ) )
return - V_76 ;
return F_21 ( V_72 , V_2 ) ;
}
void
F_22 ( struct V_77 * V_78 ,
struct V_3 * * V_4 ,
enum V_79 * V_80 )
{
* V_4 = NULL ;
* V_80 = V_81 ;
F_23 ( V_78 ) ;
if ( V_78 -> V_82 && ! F_24 ( V_78 -> V_82 ) )
return;
switch ( V_78 -> V_83 ) {
case V_84 :
if ( V_78 -> V_85 ) {
* V_4 = V_78 -> V_85 -> V_86 . V_87 ;
* V_80 = ( V_78 -> V_88 &&
! V_78 -> V_89 )
? V_90
: V_91 ;
return;
}
case V_92 :
case V_93 :
if ( V_78 -> V_85 ) {
* V_4 = V_78 -> V_85 -> V_86 . V_87 ;
* V_80 = V_90 ;
return;
}
break;
case V_94 :
case V_95 :
if ( V_78 -> V_96 ) {
* V_4 = V_78 -> V_87 ;
* V_80 = V_90 ;
} else if ( V_78 -> V_97 ) {
* V_4 = V_78 -> V_87 ;
* V_80 = V_90 ;
}
return;
case V_98 :
if ( V_78 -> V_99 ) {
* V_4 = V_78 -> V_87 ;
* V_80 = V_90 ;
}
return;
case V_100 :
case V_101 :
case V_102 :
return;
case V_103 :
if ( V_78 -> V_34 -> V_104 &
V_105 )
* V_80 = V_91 ;
return;
case V_106 :
case V_107 :
F_2 ( 1 ) ;
}
return;
}
