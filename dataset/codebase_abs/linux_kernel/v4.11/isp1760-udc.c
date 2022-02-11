static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static inline struct V_7 * F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_9 , struct V_7 , V_9 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_10 , T_2 V_11 )
{
return F_6 ( V_10 -> V_12 , V_11 ) ;
}
static inline void F_7 ( struct V_1 * V_10 , T_2 V_11 , T_1 V_13 )
{
F_8 ( V_10 -> V_12 , V_11 , V_13 ) ;
}
static struct V_4 * F_9 ( struct V_1 * V_10 ,
T_2 V_14 )
{
unsigned int V_15 ;
if ( V_14 == 0 )
return & V_10 -> V_6 [ 0 ] ;
for ( V_15 = 1 ; V_15 < F_10 ( V_10 -> V_6 ) ; ++ V_15 ) {
if ( V_10 -> V_6 [ V_15 ] . V_16 == V_14 )
return V_10 -> V_6 [ V_15 ] . V_17 ? & V_10 -> V_6 [ V_15 ] : NULL ;
}
return NULL ;
}
static void F_11 ( struct V_4 * V_6 , int V_18 )
{
F_7 ( V_6 -> V_10 , V_19 ,
F_12 ( V_6 -> V_16 & V_20 ) |
( V_18 == V_21 ? V_22 : 0 ) ) ;
}
static void F_13 ( struct V_4 * V_6 )
{
F_11 ( V_6 , V_6 -> V_16 & V_23 ) ;
}
static void F_14 ( struct V_4 * V_6 , int V_18 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
F_7 ( V_10 , V_19 , F_12 ( 0 ) |
( V_18 == V_21 ? 0 : V_22 ) ) ;
F_7 ( V_10 , V_24 , V_25 ) ;
V_10 -> V_26 = V_27 ;
}
static void F_15 ( struct V_4 * V_6 ,
struct V_7 * V_9 ,
int V_28 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
unsigned long V_29 ;
F_16 ( V_6 -> V_10 -> V_30 -> V_31 , L_1 ,
V_9 , V_28 ) ;
V_9 -> V_6 = NULL ;
V_9 -> V_9 . V_28 = V_28 ;
V_9 -> V_9 . V_32 ( & V_6 -> V_6 , & V_9 -> V_9 ) ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
if ( V_28 == 0 && V_6 -> V_16 == 0 && V_10 -> V_34 == V_35 )
F_14 ( V_6 , V_35 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
}
static void F_19 ( struct V_4 * V_6 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
unsigned long V_29 ;
F_16 ( V_6 -> V_10 -> V_30 -> V_31 , L_2 , V_36 , V_6 -> V_16 ) ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
F_11 ( V_6 , V_35 ) ;
F_7 ( V_10 , V_24 , V_37 ) ;
F_11 ( V_6 , V_21 ) ;
F_7 ( V_10 , V_24 , V_37 ) ;
V_10 -> V_26 = V_27 ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
}
static bool F_20 ( struct V_4 * V_6 ,
struct V_7 * V_9 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
unsigned int V_38 ;
T_1 * V_39 ;
int V_15 ;
F_13 ( V_6 ) ;
V_38 = F_5 ( V_10 , V_40 ) & V_41 ;
F_16 ( V_10 -> V_30 -> V_31 , L_3 ,
V_36 , V_38 , V_9 -> V_9 . V_42 , V_9 -> V_9 . V_43 ) ;
V_38 = F_21 ( V_38 , V_9 -> V_9 . V_43 - V_9 -> V_9 . V_42 ) ;
if ( ! V_38 ) {
F_7 ( V_10 , V_24 , V_44 ) ;
return false ;
}
V_39 = V_9 -> V_9 . V_39 + V_9 -> V_9 . V_42 ;
for ( V_15 = V_38 ; V_15 > 2 ; V_15 -= 4 , ++ V_39 )
* V_39 = F_22 ( F_5 ( V_10 , V_45 ) ) ;
if ( V_15 > 0 )
* ( T_2 * ) V_39 = F_23 ( F_24 ( V_10 -> V_12 + V_45 ) ) ;
V_9 -> V_9 . V_42 += V_38 ;
F_16 ( V_10 -> V_30 -> V_31 ,
L_4 ,
V_36 , V_9 , V_9 -> V_9 . V_42 , V_9 -> V_9 . V_43 , V_6 -> V_46 ,
V_38 ) ;
V_6 -> V_47 = false ;
if ( V_9 -> V_9 . V_42 == V_9 -> V_9 . V_43 || V_38 < V_6 -> V_46 ) {
F_25 ( & V_9 -> V_48 ) ;
return true ;
}
return false ;
}
static void F_26 ( struct V_4 * V_6 ,
struct V_7 * V_9 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
T_1 * V_39 = V_9 -> V_9 . V_39 + V_9 -> V_9 . V_42 ;
int V_15 ;
V_9 -> V_49 = F_21 ( V_9 -> V_9 . V_43 - V_9 -> V_9 . V_42 ,
V_6 -> V_46 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_5 ,
V_36 , V_9 -> V_49 , V_9 -> V_9 . V_42 ,
V_9 -> V_9 . V_43 ) ;
F_11 ( V_6 , V_21 ) ;
if ( V_9 -> V_49 )
F_7 ( V_10 , V_40 , V_9 -> V_49 ) ;
for ( V_15 = V_9 -> V_49 ; V_15 > 2 ; V_15 -= 4 , ++ V_39 )
F_7 ( V_10 , V_45 , F_27 ( * V_39 ) ) ;
if ( V_15 > 0 )
F_28 ( F_29 ( * ( T_2 * ) V_39 ) , V_10 -> V_12 + V_45 ) ;
if ( V_6 -> V_16 == 0 )
F_7 ( V_10 , V_24 , V_50 ) ;
if ( ! V_9 -> V_49 )
F_7 ( V_10 , V_24 , V_51 ) ;
}
static void F_30 ( struct V_4 * V_6 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
struct V_7 * V_9 ;
bool V_32 ;
F_31 ( & V_10 -> V_33 ) ;
if ( V_6 -> V_16 == 0 && V_10 -> V_26 != V_52 ) {
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_6 , V_36 ,
V_10 -> V_26 ) ;
return;
}
if ( V_6 -> V_16 != 0 && ! V_6 -> V_17 ) {
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_7 , V_36 ,
V_6 -> V_16 ) ;
return;
}
if ( F_33 ( & V_6 -> V_48 ) ) {
V_6 -> V_47 = true ;
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_8 ,
V_36 , V_6 -> V_16 , V_6 ) ;
return;
}
V_9 = F_34 ( & V_6 -> V_48 , struct V_7 ,
V_48 ) ;
V_32 = F_20 ( V_6 , V_9 ) ;
F_32 ( & V_10 -> V_33 ) ;
if ( V_32 )
F_15 ( V_6 , V_9 , 0 ) ;
}
static void F_35 ( struct V_4 * V_6 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
struct V_7 * V_32 = NULL ;
struct V_7 * V_9 ;
bool V_53 ;
F_31 ( & V_10 -> V_33 ) ;
if ( V_6 -> V_16 == 0 && V_10 -> V_26 != V_54 ) {
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_9 ,
V_10 -> V_26 ) ;
return;
}
if ( F_33 ( & V_6 -> V_48 ) ) {
if ( V_6 -> V_16 == 0 ) {
F_14 ( V_6 , V_21 ) ;
F_32 ( & V_10 -> V_33 ) ;
return;
}
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_10 ,
V_36 , V_6 -> V_16 ) ;
return;
}
V_9 = F_34 ( & V_6 -> V_48 , struct V_7 ,
V_48 ) ;
V_9 -> V_9 . V_42 += V_9 -> V_49 ;
V_53 = V_9 -> V_9 . V_42 == V_9 -> V_9 . V_43 &&
! ( V_9 -> V_9 . V_43 % V_6 -> V_46 ) &&
V_9 -> V_49 && V_9 -> V_9 . V_55 ;
F_16 ( V_10 -> V_30 -> V_31 ,
L_11 ,
V_9 , V_9 -> V_9 . V_42 , V_9 -> V_9 . V_43 , V_6 -> V_46 ,
V_9 -> V_49 , V_9 -> V_9 . V_55 , V_53 ) ;
if ( V_9 -> V_9 . V_42 == V_9 -> V_9 . V_43 && ! V_53 ) {
V_32 = V_9 ;
F_25 ( & V_9 -> V_48 ) ;
if ( V_6 -> V_16 == 0 )
F_14 ( V_6 , V_21 ) ;
if ( ! F_33 ( & V_6 -> V_48 ) )
V_9 = F_34 ( & V_6 -> V_48 ,
struct V_7 , V_48 ) ;
else
V_9 = NULL ;
}
if ( V_9 )
F_26 ( V_6 , V_9 ) ;
F_32 ( & V_10 -> V_33 ) ;
if ( V_32 )
F_15 ( V_6 , V_32 , 0 ) ;
}
static int F_36 ( struct V_4 * V_6 , bool V_56 )
{
struct V_1 * V_10 = V_6 -> V_10 ;
F_16 ( V_10 -> V_30 -> V_31 , L_12 , V_36 ,
V_56 ? L_13 : L_14 , V_6 -> V_16 ) ;
if ( V_6 -> V_17 && F_37 ( V_6 -> V_17 ) ) {
F_16 ( V_10 -> V_30 -> V_31 , L_15 , V_36 ,
V_6 -> V_16 ) ;
return - V_57 ;
}
F_13 ( V_6 ) ;
F_7 ( V_10 , V_24 , V_56 ? V_37 : 0 ) ;
if ( V_6 -> V_16 == 0 ) {
F_11 ( V_6 , V_21 ) ;
F_7 ( V_10 , V_24 , V_56 ? V_37 : 0 ) ;
} else if ( ! V_56 ) {
T_2 V_58 = F_5 ( V_10 , V_59 ) ;
F_7 ( V_10 , V_59 , V_58 & ~ V_60 ) ;
F_7 ( V_10 , V_59 , V_58 ) ;
if ( ( V_6 -> V_16 & V_21 ) && ! F_33 ( & V_6 -> V_48 ) ) {
struct V_7 * V_9 ;
V_9 = F_34 ( & V_6 -> V_48 ,
struct V_7 , V_48 ) ;
F_26 ( V_6 , V_9 ) ;
}
}
V_6 -> V_61 = V_56 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_10 ,
const struct V_62 * V_9 )
{
struct V_4 * V_6 ;
T_2 V_28 ;
if ( V_9 -> V_63 != F_29 ( 2 ) || V_9 -> V_64 != F_29 ( 0 ) )
return - V_57 ;
switch ( V_9 -> V_65 ) {
case V_21 | V_66 :
V_28 = V_10 -> V_67 ;
break;
case V_21 | V_68 :
V_28 = 0 ;
break;
case V_21 | V_69 :
V_6 = F_9 ( V_10 , F_23 ( V_9 -> V_70 ) ) ;
if ( ! V_6 )
return - V_57 ;
V_28 = 0 ;
if ( V_6 -> V_61 )
V_28 |= 1 << V_71 ;
break;
default:
return - V_57 ;
}
F_7 ( V_10 , V_19 , F_12 ( 0 ) | V_22 ) ;
F_7 ( V_10 , V_40 , 2 ) ;
F_28 ( F_29 ( V_28 ) , V_10 -> V_12 + V_45 ) ;
F_7 ( V_10 , V_24 , V_50 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_16 , V_36 , V_28 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_10 , T_2 V_16 )
{
if ( V_16 > 127 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_17 , V_16 ) ;
return - V_57 ;
}
if ( V_10 -> V_3 . V_72 != V_73 &&
V_10 -> V_3 . V_72 != V_74 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_18 ,
V_10 -> V_3 . V_72 ) ;
return - V_57 ;
}
F_40 ( & V_10 -> V_3 , V_16 ? V_74 :
V_73 ) ;
F_7 ( V_10 , V_75 , V_76 | V_16 ) ;
F_31 ( & V_10 -> V_33 ) ;
F_14 ( & V_10 -> V_6 [ 0 ] , V_35 ) ;
F_32 ( & V_10 -> V_33 ) ;
return 0 ;
}
static bool F_41 ( struct V_1 * V_10 ,
struct V_62 * V_9 )
{
bool V_77 ;
switch ( V_9 -> V_78 ) {
case V_79 :
return F_38 ( V_10 , V_9 ) ;
case V_80 :
switch ( V_9 -> V_65 ) {
case V_35 | V_66 : {
return true ;
}
case V_35 | V_69 : {
T_2 V_14 = F_23 ( V_9 -> V_70 ) ;
struct V_4 * V_6 ;
if ( V_9 -> V_63 != F_29 ( 0 ) ||
V_9 -> V_64 != F_29 ( V_71 ) )
return true ;
V_6 = F_9 ( V_10 , V_14 ) ;
if ( ! V_6 )
return true ;
F_31 ( & V_10 -> V_33 ) ;
if ( ! V_6 -> V_81 )
V_77 = F_36 ( V_6 , false ) ;
else
V_77 = false ;
if ( ! V_77 )
F_14 ( & V_10 -> V_6 [ 0 ] ,
V_35 ) ;
F_32 ( & V_10 -> V_33 ) ;
return V_77 ;
}
default:
return true ;
}
break;
case V_82 :
switch ( V_9 -> V_65 ) {
case V_35 | V_66 : {
return true ;
}
case V_35 | V_69 : {
T_2 V_14 = F_23 ( V_9 -> V_70 ) ;
struct V_4 * V_6 ;
if ( V_9 -> V_63 != F_29 ( 0 ) ||
V_9 -> V_64 != F_29 ( V_71 ) )
return true ;
V_6 = F_9 ( V_10 , V_14 ) ;
if ( ! V_6 )
return true ;
F_31 ( & V_10 -> V_33 ) ;
V_77 = F_36 ( V_6 , true ) ;
if ( ! V_77 )
F_14 ( & V_10 -> V_6 [ 0 ] ,
V_35 ) ;
F_32 ( & V_10 -> V_33 ) ;
return V_77 ;
}
default:
return true ;
}
break;
case V_83 :
if ( V_9 -> V_65 != ( V_35 | V_66 ) )
return true ;
return F_39 ( V_10 , F_23 ( V_9 -> V_64 ) ) ;
case V_84 :
if ( V_9 -> V_65 != ( V_35 | V_66 ) )
return true ;
if ( V_10 -> V_3 . V_72 != V_74 &&
V_10 -> V_3 . V_72 != V_85 )
return true ;
V_77 = V_10 -> V_86 -> V_87 ( & V_10 -> V_3 , V_9 ) < 0 ;
if ( V_77 )
return true ;
F_40 ( & V_10 -> V_3 , V_9 -> V_64 ?
V_85 : V_74 ) ;
return false ;
default:
return V_10 -> V_86 -> V_87 ( & V_10 -> V_3 , V_9 ) < 0 ;
}
}
static void F_42 ( struct V_1 * V_10 )
{
union {
struct V_62 V_88 ;
T_1 V_89 [ 2 ] ;
} V_9 ;
unsigned int V_90 ;
bool V_77 = false ;
F_31 ( & V_10 -> V_33 ) ;
F_7 ( V_10 , V_19 , V_91 ) ;
V_90 = F_5 ( V_10 , V_40 ) & V_41 ;
if ( V_90 != sizeof( V_9 ) ) {
F_32 ( & V_10 -> V_33 ) ;
F_43 ( V_10 -> V_30 -> V_31 , L_19 ,
V_90 ) ;
F_19 ( & V_10 -> V_6 [ 0 ] ) ;
return;
}
V_9 . V_89 [ 0 ] = F_5 ( V_10 , V_45 ) ;
V_9 . V_89 [ 1 ] = F_5 ( V_10 , V_45 ) ;
if ( V_10 -> V_26 != V_27 ) {
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_20 ) ;
return;
}
if ( ! V_9 . V_88 . V_63 )
V_10 -> V_26 = V_92 ;
else if ( V_9 . V_88 . V_65 & V_21 )
V_10 -> V_26 = V_54 ;
else
V_10 -> V_26 = V_52 ;
V_10 -> V_34 = V_9 . V_88 . V_65 & V_21 ;
V_10 -> V_93 = F_23 ( V_9 . V_88 . V_63 ) ;
F_32 ( & V_10 -> V_33 ) ;
F_16 ( V_10 -> V_30 -> V_31 ,
L_21 ,
V_36 , V_9 . V_88 . V_65 , V_9 . V_88 . V_78 ,
F_23 ( V_9 . V_88 . V_64 ) , F_23 ( V_9 . V_88 . V_70 ) ,
F_23 ( V_9 . V_88 . V_63 ) ) ;
if ( ( V_9 . V_88 . V_65 & V_94 ) == V_95 )
V_77 = F_41 ( V_10 , & V_9 . V_88 ) ;
else
V_77 = V_10 -> V_86 -> V_87 ( & V_10 -> V_3 , & V_9 . V_88 ) < 0 ;
if ( V_77 )
F_19 ( & V_10 -> V_6 [ 0 ] ) ;
}
static int F_44 ( struct V_5 * V_6 ,
const struct V_96 * V_17 )
{
struct V_4 * V_97 = F_3 ( V_6 ) ;
struct V_1 * V_10 = V_97 -> V_10 ;
unsigned long V_29 ;
unsigned int type ;
F_16 ( V_97 -> V_10 -> V_30 -> V_31 , L_22 , V_36 ) ;
if ( V_17 -> V_98 != V_99 ||
V_17 -> V_100 == 0 ||
V_17 -> V_100 != V_97 -> V_16 ||
F_23 ( V_17 -> V_101 ) > V_6 -> V_46 ) {
F_16 ( V_10 -> V_30 -> V_31 ,
L_23 ,
V_36 , V_17 -> V_98 ,
V_17 -> V_100 , V_97 -> V_16 ,
F_23 ( V_17 -> V_101 ) , V_6 -> V_46 ) ;
return - V_57 ;
}
switch ( F_45 ( V_17 ) ) {
case V_102 :
type = V_103 ;
break;
case V_104 :
type = V_105 ;
break;
case V_106 :
type = V_107 ;
break;
case V_108 :
default:
F_16 ( V_10 -> V_30 -> V_31 , L_24 ,
V_36 ) ;
return - V_57 ;
}
F_17 ( & V_10 -> V_33 , V_29 ) ;
V_97 -> V_17 = V_17 ;
V_97 -> V_46 = F_23 ( V_17 -> V_101 ) ;
V_97 -> V_47 = false ;
V_97 -> V_61 = false ;
V_97 -> V_81 = false ;
F_13 ( V_97 ) ;
F_7 ( V_10 , V_109 , V_97 -> V_46 ) ;
F_7 ( V_10 , V_40 , V_97 -> V_46 ) ;
F_7 ( V_10 , V_59 , V_60 | type ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_4 * V_97 = F_3 ( V_6 ) ;
struct V_1 * V_10 = V_97 -> V_10 ;
struct V_7 * V_9 , * V_110 ;
F_47 ( V_111 ) ;
unsigned long V_29 ;
F_16 ( V_10 -> V_30 -> V_31 , L_22 , V_36 ) ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
if ( ! V_97 -> V_17 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_25 , V_36 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
return - V_57 ;
}
V_97 -> V_17 = NULL ;
V_97 -> V_46 = 0 ;
F_13 ( V_97 ) ;
F_7 ( V_10 , V_59 , 0 ) ;
F_48 ( & V_97 -> V_48 , & V_111 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
F_49 (req, nreq, &req_list, queue) {
F_25 ( & V_9 -> V_48 ) ;
F_15 ( V_97 , V_9 , - V_112 ) ;
}
return 0 ;
}
static struct V_8 * F_50 ( struct V_5 * V_6 ,
T_3 V_113 )
{
struct V_7 * V_9 ;
V_9 = F_51 ( sizeof( * V_9 ) , V_113 ) ;
if ( ! V_9 )
return NULL ;
return & V_9 -> V_9 ;
}
static void F_52 ( struct V_5 * V_6 , struct V_8 * V_114 )
{
struct V_7 * V_9 = F_4 ( V_114 ) ;
F_53 ( V_9 ) ;
}
static int F_54 ( struct V_5 * V_6 , struct V_8 * V_114 ,
T_3 V_113 )
{
struct V_7 * V_9 = F_4 ( V_114 ) ;
struct V_4 * V_97 = F_3 ( V_6 ) ;
struct V_1 * V_10 = V_97 -> V_10 ;
bool V_32 = false ;
unsigned long V_29 ;
int V_115 = 0 ;
V_114 -> V_28 = - V_116 ;
V_114 -> V_42 = 0 ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
F_16 ( V_10 -> V_30 -> V_31 ,
L_26 , V_36 , V_114 ,
V_114 -> V_43 , V_114 -> V_55 ? L_27 : L_28 , V_97 , V_97 -> V_16 ) ;
V_9 -> V_6 = V_97 ;
if ( V_97 -> V_16 == 0 ) {
if ( V_114 -> V_43 != V_10 -> V_93 &&
V_10 -> V_26 != V_54 ) {
F_16 ( V_10 -> V_30 -> V_31 ,
L_29 ,
V_36 , V_114 -> V_43 , V_9 ) ;
V_115 = - V_57 ;
goto V_117;
}
switch ( V_10 -> V_26 ) {
case V_54 :
F_16 ( V_10 -> V_30 -> V_31 , L_30 ,
V_36 , V_9 ) ;
F_55 ( & V_9 -> V_48 , & V_97 -> V_48 ) ;
F_26 ( V_97 , V_9 ) ;
break;
case V_52 :
F_55 ( & V_9 -> V_48 , & V_97 -> V_48 ) ;
F_11 ( V_97 , V_35 ) ;
F_7 ( V_10 , V_24 , V_50 ) ;
break;
case V_92 :
V_32 = true ;
break;
default:
F_16 ( V_10 -> V_30 -> V_31 , L_31 ,
V_36 ) ;
V_115 = - V_57 ;
break;
}
} else if ( V_97 -> V_17 ) {
bool V_118 = F_33 ( & V_97 -> V_48 ) ;
F_55 ( & V_9 -> V_48 , & V_97 -> V_48 ) ;
if ( ( V_97 -> V_16 & V_21 ) && ! V_97 -> V_61 && V_118 )
F_26 ( V_97 , V_9 ) ;
else if ( ! ( V_97 -> V_16 & V_21 ) && V_97 -> V_47 )
V_32 = F_20 ( V_97 , V_9 ) ;
} else {
F_16 ( V_10 -> V_30 -> V_31 ,
L_32 ,
V_36 , V_97 -> V_16 ) ;
V_115 = - V_112 ;
}
V_117:
if ( V_115 < 0 )
V_9 -> V_6 = NULL ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
if ( V_32 )
F_15 ( V_97 , V_9 , 0 ) ;
return V_115 ;
}
static int F_56 ( struct V_5 * V_6 , struct V_8 * V_114 )
{
struct V_7 * V_9 = F_4 ( V_114 ) ;
struct V_4 * V_97 = F_3 ( V_6 ) ;
struct V_1 * V_10 = V_97 -> V_10 ;
unsigned long V_29 ;
F_16 ( V_97 -> V_10 -> V_30 -> V_31 , L_2 , V_36 , V_97 -> V_16 ) ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
if ( V_9 -> V_6 != V_97 )
V_9 = NULL ;
else
F_25 ( & V_9 -> V_48 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
if ( ! V_9 )
return - V_57 ;
F_15 ( V_97 , V_9 , - V_119 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_97 , bool V_77 , bool V_120 )
{
struct V_1 * V_10 = V_97 -> V_10 ;
int V_115 ;
if ( ! V_97 -> V_16 ) {
if ( F_58 ( V_10 -> V_26 == V_27 || ! V_77 ||
V_120 ) ) {
return - V_57 ;
}
}
if ( V_97 -> V_16 && ! V_97 -> V_17 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_7 , V_36 ,
V_97 -> V_16 ) ;
return - V_57 ;
}
if ( V_97 -> V_16 & V_21 ) {
if ( ! F_33 ( & V_97 -> V_48 ) ) {
F_16 ( V_10 -> V_30 -> V_31 ,
L_33 , V_36 ,
V_97 -> V_16 ) ;
return - V_121 ;
}
}
V_115 = F_36 ( V_97 , V_77 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( ! V_97 -> V_16 ) {
V_10 -> V_26 = V_27 ;
return 0 ;
}
if ( V_120 )
V_97 -> V_81 = true ;
else if ( ! V_77 )
V_97 -> V_81 = false ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , int V_122 )
{
struct V_4 * V_97 = F_3 ( V_6 ) ;
unsigned long V_29 ;
int V_115 ;
F_16 ( V_97 -> V_10 -> V_30 -> V_31 , L_12 , V_36 ,
V_122 ? L_13 : L_14 , V_97 -> V_16 ) ;
F_17 ( & V_97 -> V_10 -> V_33 , V_29 ) ;
V_115 = F_57 ( V_97 , V_122 , false ) ;
F_18 ( & V_97 -> V_10 -> V_33 , V_29 ) ;
return V_115 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_4 * V_97 = F_3 ( V_6 ) ;
unsigned long V_29 ;
int V_115 ;
F_16 ( V_97 -> V_10 -> V_30 -> V_31 , L_34 , V_36 ,
V_97 -> V_16 ) ;
F_17 ( & V_97 -> V_10 -> V_33 , V_29 ) ;
V_115 = F_57 ( V_97 , true , true ) ;
F_18 ( & V_97 -> V_10 -> V_33 , V_29 ) ;
return V_115 ;
}
static void F_61 ( struct V_5 * V_6 )
{
struct V_4 * V_97 = F_3 ( V_6 ) ;
struct V_1 * V_10 = V_97 -> V_10 ;
unsigned long V_29 ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
F_13 ( V_97 ) ;
F_7 ( V_10 , V_24 , V_44 ) ;
F_7 ( V_10 , V_24 , V_44 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
}
static void F_62 ( struct V_1 * V_10 )
{
F_40 ( & V_10 -> V_3 , V_123 ) ;
F_63 ( & V_10 -> V_124 , V_125 + V_126 ) ;
}
static void F_64 ( struct V_1 * V_10 )
{
if ( V_10 -> V_3 . V_72 < V_123 )
return;
F_16 ( V_10 -> V_30 -> V_31 , L_35 ,
V_10 -> V_3 . V_72 ) ;
V_10 -> V_3 . V_127 = V_128 ;
F_40 ( & V_10 -> V_3 , V_129 ) ;
if ( V_10 -> V_86 -> V_130 )
V_10 -> V_86 -> V_130 ( & V_10 -> V_3 ) ;
F_65 ( & V_10 -> V_124 ) ;
}
static void F_66 ( struct V_1 * V_10 )
{
F_7 ( V_10 , V_131 , V_132 | V_133 |
V_134 ) ;
F_7 ( V_10 , V_135 , F_67 ( 7 ) | F_67 ( 6 ) |
F_67 ( 5 ) | F_67 ( 4 ) | F_67 ( 3 ) |
F_67 ( 2 ) | F_67 ( 1 ) | F_67 ( 0 ) |
V_136 | V_137 | V_138 | V_139 |
V_140 | V_141 ) ;
if ( V_10 -> V_142 )
F_68 ( V_10 -> V_30 , true ) ;
F_7 ( V_10 , V_75 , V_76 ) ;
}
static void F_69 ( struct V_1 * V_10 )
{
unsigned long V_29 ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
F_66 ( V_10 ) ;
V_10 -> V_26 = V_27 ;
V_10 -> V_3 . V_127 = V_143 ;
F_70 ( & V_10 -> V_3 , V_10 -> V_86 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
}
static void F_71 ( struct V_1 * V_10 )
{
if ( V_10 -> V_3 . V_72 < V_73 )
return;
if ( V_10 -> V_86 -> V_144 )
V_10 -> V_86 -> V_144 ( & V_10 -> V_3 ) ;
}
static void F_72 ( struct V_1 * V_10 )
{
if ( V_10 -> V_3 . V_72 < V_73 )
return;
if ( V_10 -> V_86 -> V_145 )
V_10 -> V_86 -> V_145 ( & V_10 -> V_3 ) ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
return F_5 ( V_10 , V_146 ) & ( ( 1 << 11 ) - 1 ) ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_22 , V_36 ) ;
return - V_147 ;
}
static int F_75 ( struct V_2 * V_3 ,
int V_148 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_148 )
V_10 -> V_67 |= 1 << V_149 ;
else
V_10 -> V_67 &= ~ ( 1 << V_149 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 , int V_150 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_68 ( V_10 -> V_30 , V_150 ) ;
V_10 -> V_142 = V_150 ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_151 * V_86 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned long V_29 ;
if ( V_86 -> V_152 < V_143 ) {
F_43 ( V_10 -> V_30 -> V_31 , L_36 ) ;
return - V_57 ;
}
F_17 ( & V_10 -> V_33 , V_29 ) ;
if ( V_10 -> V_86 ) {
F_43 ( V_10 -> V_30 -> V_31 , L_37 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
return - V_153 ;
}
V_10 -> V_86 = V_86 ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_38 ,
V_86 -> V_154 ) ;
V_10 -> V_67 = 0 ;
V_10 -> V_142 = true ;
F_40 ( & V_10 -> V_3 , V_129 ) ;
F_7 ( V_10 , V_155 , V_156 ) ;
F_66 ( V_10 ) ;
F_16 ( V_10 -> V_30 -> V_31 , L_39 ,
V_86 -> V_154 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned long V_29 ;
F_16 ( V_10 -> V_30 -> V_31 , L_22 , V_36 ) ;
F_79 ( & V_10 -> V_124 ) ;
F_7 ( V_10 , V_155 , 0 ) ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
V_10 -> V_86 = NULL ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
return 0 ;
}
static T_4 F_80 ( int V_157 , void * V_31 )
{
struct V_1 * V_10 = V_31 ;
unsigned int V_15 ;
T_1 V_28 ;
V_28 = F_5 ( V_10 , V_158 )
& F_5 ( V_10 , V_135 ) ;
F_7 ( V_10 , V_158 , V_28 ) ;
if ( V_28 & V_137 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_40 , V_36 ) ;
F_31 ( & V_10 -> V_33 ) ;
F_62 ( V_10 ) ;
F_32 ( & V_10 -> V_33 ) ;
}
if ( V_28 & V_141 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_41 , V_36 ) ;
F_69 ( V_10 ) ;
}
for ( V_15 = 0 ; V_15 <= 7 ; ++ V_15 ) {
struct V_4 * V_6 = & V_10 -> V_6 [ V_15 * 2 ] ;
if ( V_28 & F_81 ( V_15 ) ) {
F_16 ( V_10 -> V_30 -> V_31 , L_42 , V_36 , V_15 ) ;
F_35 ( V_6 ) ;
}
if ( V_28 & F_82 ( V_15 ) ) {
F_16 ( V_10 -> V_30 -> V_31 , L_43 , V_36 , V_15 ) ;
F_30 ( V_15 ? V_6 - 1 : V_6 ) ;
}
}
if ( V_28 & V_136 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_44 , V_36 ) ;
F_42 ( V_10 ) ;
}
if ( V_28 & V_138 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_45 , V_36 ) ;
F_72 ( V_10 ) ;
}
if ( V_28 & V_139 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_46 , V_36 ) ;
F_31 ( & V_10 -> V_33 ) ;
if ( ! ( F_5 ( V_10 , V_155 ) & V_159 ) )
F_64 ( V_10 ) ;
else
F_71 ( V_10 ) ;
F_32 ( & V_10 -> V_33 ) ;
}
if ( V_28 & V_140 ) {
F_16 ( V_10 -> V_30 -> V_31 , L_47 , V_36 ) ;
V_10 -> V_3 . V_127 = V_160 ;
}
return V_28 ? V_161 : V_162 ;
}
static void F_83 ( unsigned long V_89 )
{
struct V_1 * V_10 = (struct V_1 * ) V_89 ;
unsigned long V_29 ;
F_17 ( & V_10 -> V_33 , V_29 ) ;
if ( ! ( F_5 ( V_10 , V_155 ) & V_159 ) )
F_64 ( V_10 ) ;
else if ( V_10 -> V_3 . V_72 >= V_123 )
F_63 ( & V_10 -> V_124 ,
V_125 + V_126 ) ;
F_18 ( & V_10 -> V_33 , V_29 ) ;
}
static void F_84 ( struct V_1 * V_10 )
{
unsigned int V_15 ;
F_85 ( & V_10 -> V_3 . V_163 ) ;
for ( V_15 = 0 ; V_15 < F_10 ( V_10 -> V_6 ) ; ++ V_15 ) {
struct V_4 * V_6 = & V_10 -> V_6 [ V_15 ] ;
unsigned int V_164 = ( V_15 + 1 ) / 2 ;
bool V_165 = ! ( V_15 & 1 ) ;
V_6 -> V_10 = V_10 ;
F_85 ( & V_6 -> V_48 ) ;
V_6 -> V_16 = ( V_164 && V_165 ? V_21 : V_35 )
| V_164 ;
V_6 -> V_17 = NULL ;
sprintf ( V_6 -> V_166 , L_48 , V_164 ,
V_164 ? ( V_165 ? L_49 : L_50 ) : L_28 ) ;
V_6 -> V_6 . V_167 = & V_168 ;
V_6 -> V_6 . V_166 = V_6 -> V_166 ;
if ( V_164 == 0 ) {
F_86 ( & V_6 -> V_6 , 64 ) ;
V_6 -> V_6 . V_169 . V_170 = true ;
V_6 -> V_6 . V_169 . V_171 = true ;
V_6 -> V_6 . V_169 . V_172 = true ;
V_6 -> V_46 = 64 ;
V_10 -> V_3 . V_173 = & V_6 -> V_6 ;
} else {
F_86 ( & V_6 -> V_6 , 512 ) ;
V_6 -> V_6 . V_169 . V_174 = true ;
V_6 -> V_6 . V_169 . V_175 = true ;
V_6 -> V_6 . V_169 . V_176 = true ;
V_6 -> V_46 = 0 ;
F_55 ( & V_6 -> V_6 . V_163 , & V_10 -> V_3 . V_163 ) ;
}
if ( V_165 )
V_6 -> V_6 . V_169 . V_171 = true ;
else
V_6 -> V_6 . V_169 . V_172 = true ;
}
}
static int F_87 ( struct V_1 * V_10 )
{
T_2 V_177 ;
T_1 V_178 ;
F_7 ( V_10 , V_179 , 0xbabe ) ;
V_178 = F_5 ( V_10 , V_180 ) ;
V_177 = F_5 ( V_10 , V_179 ) ;
if ( V_177 != 0xbabe ) {
F_43 ( V_10 -> V_30 -> V_31 ,
L_51 ,
V_177 , V_178 ) ;
return - V_181 ;
}
if ( V_178 != 0x00011582 && V_178 != 0x00158210 ) {
F_43 ( V_10 -> V_30 -> V_31 , L_52 , V_178 ) ;
return - V_181 ;
}
F_7 ( V_10 , V_155 , V_182 ) ;
F_88 ( 10000 , 11000 ) ;
F_7 ( V_10 , V_155 , 0 ) ;
F_88 ( 10000 , 11000 ) ;
return 0 ;
}
int F_89 ( struct V_183 * V_30 , int V_157 ,
unsigned long V_184 )
{
struct V_1 * V_10 = & V_30 -> V_10 ;
const char * V_185 ;
int V_115 ;
V_10 -> V_157 = - 1 ;
V_10 -> V_30 = V_30 ;
V_10 -> V_12 = V_30 -> V_12 ;
F_90 ( & V_10 -> V_33 ) ;
F_91 ( & V_10 -> V_124 , F_83 ,
( unsigned long ) V_10 ) ;
V_115 = F_87 ( V_10 ) ;
if ( V_115 < 0 )
return V_115 ;
V_185 = F_92 ( V_30 -> V_31 ) ;
V_10 -> V_186 = F_93 ( strlen ( V_185 ) + 7 , V_187 ) ;
if ( ! V_10 -> V_186 )
return - V_188 ;
sprintf ( V_10 -> V_186 , L_53 , V_185 ) ;
V_115 = F_94 ( V_157 , F_80 , V_189 | V_184 ,
V_10 -> V_186 , V_10 ) ;
if ( V_115 < 0 )
goto error;
V_10 -> V_157 = V_157 ;
V_10 -> V_3 . V_167 = & V_190 ;
V_10 -> V_3 . V_127 = V_128 ;
V_10 -> V_3 . V_152 = V_160 ;
V_10 -> V_3 . V_166 = L_54 ;
F_84 ( V_10 ) ;
V_115 = F_95 ( V_30 -> V_31 , & V_10 -> V_3 ) ;
if ( V_115 < 0 )
goto error;
return 0 ;
error:
if ( V_10 -> V_157 >= 0 )
F_96 ( V_10 -> V_157 , V_10 ) ;
F_53 ( V_10 -> V_186 ) ;
return V_115 ;
}
void F_97 ( struct V_183 * V_30 )
{
struct V_1 * V_10 = & V_30 -> V_10 ;
if ( ! V_10 -> V_30 )
return;
F_98 ( & V_10 -> V_3 ) ;
F_96 ( V_10 -> V_157 , V_10 ) ;
F_53 ( V_10 -> V_186 ) ;
}
