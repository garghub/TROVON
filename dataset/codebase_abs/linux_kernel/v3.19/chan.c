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
T_1 * V_25 , T_1 * V_26 )
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
const struct V_1 * V_2 ,
enum V_46 V_47 )
{
int V_9 ;
int V_48 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return - V_45 ;
switch ( V_47 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return - V_45 ;
V_48 = F_14 ( V_34 ,
V_2 -> V_11 ,
V_9 ) ;
if ( V_48 < 0 )
return V_48 ;
else if ( V_48 > 0 )
return F_16 ( V_2 -> V_9 ) ;
if ( ! V_2 -> V_7 )
return 0 ;
V_48 = F_14 ( V_34 ,
V_2 -> V_7 ,
V_9 ) ;
if ( V_48 < 0 )
return V_48 ;
else if ( V_48 > 0 )
return F_16 ( V_2 -> V_9 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
break;
case V_60 :
case V_61 :
F_2 ( 1 ) ;
}
return 0 ;
}
static int F_17 ( struct V_34 * V_34 ,
T_1 V_12 ,
T_1 V_35 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
int V_62 = 0 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return - V_45 ;
if ( V_24 -> V_39 & V_63 )
return - V_45 ;
if ( V_24 -> V_39 & V_40 ) {
if ( V_24 -> V_37 == V_64 )
return - V_45 ;
if ( V_24 -> V_37 == V_65 )
V_62 ++ ;
}
}
return V_62 ;
}
bool F_18 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_66 , V_67 = 0 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return false ;
V_66 = F_17 ( V_34 , V_2 -> V_11 ,
V_9 ) ;
if ( V_66 < 0 )
return false ;
switch ( V_2 -> V_9 ) {
case V_21 :
F_2 ( ! V_2 -> V_7 ) ;
V_67 = F_17 ( V_34 ,
V_2 -> V_7 ,
V_9 ) ;
if ( V_67 < 0 )
return false ;
break;
default:
F_2 ( V_2 -> V_7 ) ;
break;
}
return ( V_66 + V_67 > 0 ) ;
}
static bool F_19 ( struct V_34 * V_34 ,
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
if ( V_24 -> V_39 & V_63 )
return false ;
if ( ( V_24 -> V_39 & V_40 ) &&
( V_24 -> V_37 != V_68 ) )
return false ;
}
return true ;
}
static bool F_20 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
int V_69 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return false ;
V_69 = F_19 ( V_34 , V_2 -> V_11 ,
V_9 ) ;
if ( ! V_69 )
return V_69 ;
switch ( V_2 -> V_9 ) {
case V_21 :
F_2 ( ! V_2 -> V_7 ) ;
V_69 = F_19 ( V_34 ,
V_2 -> V_7 ,
V_9 ) ;
default:
F_2 ( V_2 -> V_7 ) ;
break;
}
return V_69 ;
}
static unsigned int F_21 ( struct V_34 * V_34 ,
T_1 V_12 ,
T_1 V_35 )
{
struct V_3 * V_24 ;
T_1 V_43 , V_44 , V_38 ;
unsigned int V_70 = 0 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 )
return 0 ;
if ( V_24 -> V_39 & V_63 )
return 0 ;
if ( ! ( V_24 -> V_39 & V_40 ) )
continue;
if ( V_24 -> V_70 > V_70 )
V_70 = V_24 -> V_70 ;
}
return V_70 ;
}
unsigned int
F_22 ( struct V_34 * V_34 ,
const struct V_1 * V_2 )
{
int V_9 ;
unsigned int V_71 = 0 , V_72 = 0 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return 0 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 )
return 0 ;
V_71 = F_21 ( V_34 ,
V_2 -> V_11 ,
V_9 ) ;
if ( ! V_2 -> V_7 )
return V_71 ;
V_72 = F_21 ( V_34 ,
V_2 -> V_7 ,
V_9 ) ;
return F_23 ( V_71 , V_72 ) ;
}
static bool F_24 ( struct V_34 * V_34 ,
T_1 V_12 , T_1 V_35 ,
T_1 V_73 )
{
struct V_3 * V_24 ;
T_1 V_38 , V_43 , V_44 ;
V_43 = F_12 ( V_12 , V_35 ) ;
V_44 = F_13 ( V_12 , V_35 ) ;
for ( V_38 = V_43 ; V_38 <= V_44 ; V_38 += 20 ) {
V_24 = F_10 ( V_34 , V_38 ) ;
if ( ! V_24 || V_24 -> V_39 & V_73 )
return false ;
}
return true ;
}
bool F_25 ( struct V_34 * V_34 ,
const struct V_1 * V_2 ,
T_1 V_73 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 ;
T_1 V_9 , V_18 , V_78 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return false ;
V_75 = & V_34 -> V_79 [ V_2 -> V_4 -> V_80 ] -> V_75 ;
V_77 = & V_34 -> V_79 [ V_2 -> V_4 -> V_80 ] -> V_77 ;
V_18 = V_2 -> V_4 -> V_12 ;
switch ( V_2 -> V_9 ) {
case V_19 :
V_9 = 5 ;
break;
case V_20 :
V_73 |= V_81 ;
V_9 = 10 ;
break;
case V_14 :
if ( ! V_75 -> V_82 )
return false ;
case V_10 :
V_73 |= V_83 ;
V_9 = 20 ;
break;
case V_16 :
V_9 = 40 ;
if ( ! V_75 -> V_82 )
return false ;
if ( ! ( V_75 -> V_78 & V_84 ) ||
V_75 -> V_78 & V_85 )
return false ;
if ( V_2 -> V_11 < V_18 &&
V_2 -> V_4 -> V_39 & V_86 )
return false ;
if ( V_2 -> V_11 > V_18 &&
V_2 -> V_4 -> V_39 & V_87 )
return false ;
break;
case V_21 :
V_78 = V_77 -> V_78 & V_88 ;
if ( V_78 != V_89 )
return false ;
case V_22 :
if ( ! V_77 -> V_90 )
return false ;
V_73 |= V_91 ;
V_9 = 80 ;
break;
case V_23 :
if ( ! V_77 -> V_90 )
return false ;
V_78 = V_77 -> V_78 & V_88 ;
if ( V_78 != V_92 &&
V_78 != V_89 )
return false ;
V_73 |= V_93 ;
V_9 = 160 ;
break;
default:
F_5 ( 1 ) ;
return false ;
}
if ( V_9 > 20 )
V_73 |= V_94 ;
if ( V_9 < 20 )
V_73 |= V_94 ;
if ( ! F_24 ( V_34 , V_2 -> V_11 ,
V_9 , V_73 ) )
return false ;
if ( ! V_2 -> V_7 )
return true ;
return F_24 ( V_34 , V_2 -> V_7 ,
V_9 , V_73 ) ;
}
static bool F_26 ( struct V_95 * V_96 ,
struct V_3 * V_4 )
{
struct V_97 * V_98 ;
struct V_34 * V_34 = F_27 ( V_96 -> V_99 ) ;
F_28 () ;
if ( ! F_29 ( V_100 ) ||
! ( V_34 -> V_101 & V_102 ) )
return false ;
if ( F_30 () &&
( V_4 -> V_39 & V_103 ) )
return true ;
if ( ! ( V_4 -> V_39 & V_104 ) )
return false ;
F_31 (wdev_iter, &rdev->wdev_list, list) {
struct V_3 * V_105 = NULL ;
int V_66 , V_67 ;
if ( V_98 -> V_47 != V_53 ||
! F_32 ( V_98 -> V_106 ) )
continue;
F_33 ( V_98 ) ;
if ( V_98 -> V_107 )
V_105 = V_98 -> V_107 -> V_108 . V_109 ;
F_34 ( V_98 ) ;
if ( ! V_105 )
continue;
if ( V_4 == V_105 )
return true ;
if ( V_4 -> V_80 != V_110 )
continue;
V_66 = F_35 ( V_4 -> V_12 ) ;
V_67 = F_35 ( V_105 -> V_12 ) ;
if ( V_66 != - V_45 && V_66 == V_67 ) {
if ( V_4 -> V_12 == 5825 &&
V_105 -> V_12 != 5825 )
continue;
return true ;
}
}
return false ;
}
bool F_36 ( struct V_34 * V_34 ,
struct V_1 * V_2 ,
enum V_46 V_47 )
{
struct V_95 * V_96 = F_37 ( V_34 ) ;
bool V_111 ;
T_1 V_73 = V_63 |
V_40 ;
F_38 ( V_34 , V_2 , V_47 ) ;
if ( V_47 != V_51 ||
! F_26 ( V_96 , V_2 -> V_4 ) )
V_73 |= V_112 ;
if ( F_15 ( V_34 , V_2 , V_47 ) > 0 &&
F_20 ( V_34 , V_2 ) ) {
V_73 = V_63 ;
}
V_111 = F_25 ( V_34 , V_2 , V_73 ) ;
F_39 ( V_111 ) ;
return V_111 ;
}
int F_40 ( struct V_95 * V_96 ,
struct V_1 * V_2 )
{
if ( ! V_96 -> V_113 -> V_114 )
return - V_115 ;
if ( ! F_41 ( V_96 ) )
return - V_116 ;
return F_42 ( V_96 , V_2 ) ;
}
void
F_43 ( struct V_97 * V_117 ,
struct V_3 * * V_4 ,
enum V_118 * V_119 ,
T_2 * V_120 )
{
int V_48 ;
* V_4 = NULL ;
* V_119 = V_121 ;
F_44 ( V_117 ) ;
if ( V_117 -> V_106 && ! F_32 ( V_117 -> V_106 ) )
return;
switch ( V_117 -> V_47 ) {
case V_49 :
if ( V_117 -> V_107 ) {
* V_4 = V_117 -> V_107 -> V_108 . V_109 ;
* V_119 = ( V_117 -> V_122 &&
! V_117 -> V_123 )
? V_124
: V_125 ;
if ( V_117 -> V_123 )
* V_120 |= F_16 ( V_117 -> V_2 . V_9 ) ;
return;
}
break;
case V_53 :
case V_55 :
if ( V_117 -> V_107 ) {
* V_4 = V_117 -> V_107 -> V_108 . V_109 ;
* V_119 = V_124 ;
return;
}
break;
case V_50 :
case V_51 :
if ( V_117 -> V_126 ) {
* V_4 = V_117 -> V_2 . V_4 ;
* V_119 = V_124 ;
* V_120 |= F_16 ( V_117 -> V_2 . V_9 ) ;
} else if ( V_117 -> V_127 ) {
* V_4 = V_117 -> V_2 . V_4 ;
* V_119 = V_124 ;
V_48 = F_15 ( V_117 -> V_34 ,
& V_117 -> V_2 ,
V_117 -> V_47 ) ;
F_2 ( V_48 < 0 ) ;
if ( V_48 > 0 )
* V_120 |= F_16 ( V_117 -> V_2 . V_9 ) ;
}
return;
case V_52 :
if ( V_117 -> V_128 ) {
* V_4 = V_117 -> V_2 . V_4 ;
* V_119 = V_124 ;
V_48 = F_15 ( V_117 -> V_34 ,
& V_117 -> V_2 ,
V_117 -> V_47 ) ;
F_2 ( V_48 < 0 ) ;
if ( V_48 > 0 )
* V_120 |= F_16 ( V_117 -> V_2 . V_9 ) ;
}
return;
case V_54 :
if ( V_117 -> V_2 . V_4 ) {
* V_4 = V_117 -> V_2 . V_4 ;
* V_119 = V_124 ;
return;
}
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
return;
case V_60 :
case V_61 :
F_2 ( 1 ) ;
}
}
