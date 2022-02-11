static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
* ( T_1 * ) ( V_2 -> V_4 -> V_5 + V_2 -> V_6 ) = V_3 ;
V_2 -> V_6 += 1 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_2 V_3 )
{
* ( T_2 * ) ( V_2 -> V_4 -> V_5 + V_2 -> V_6 ) = V_3 ;
V_2 -> V_6 += 2 ;
}
static inline void F_3 ( struct V_1 * V_2 , T_3 V_3 )
{
* ( T_3 * ) ( V_2 -> V_4 -> V_5 + V_2 -> V_6 ) = V_3 ;
V_2 -> V_6 += 4 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_7 ) ;
F_2 ( V_2 ,
F_5 ( V_8 ,
V_9 ) |
V_10 |
V_11 |
V_12 ) ;
F_3 ( V_2 , 0 ) ;
}
static T_4 F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_5 V_19 , T_5 V_20 )
{
return V_16 -> V_21 + V_18 -> V_22 + V_23 *
( F_7 ( V_14 -> args -> V_24 , 32 ) * V_20 + V_19 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
T_4 V_19 , T_4 V_20 )
{
F_1 ( V_2 , V_25 ) ;
F_1 ( V_2 , V_19 ) ;
F_1 ( V_2 , V_20 ) ;
}
static void F_9 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
T_5 V_19 , T_5 V_20 , bool V_26 , bool V_27 )
{
struct V_28 * args = V_14 -> args ;
bool V_29 = args -> V_30 != 0 ;
if ( V_2 -> V_31 ) {
if ( args -> V_31 . V_32 &
V_33 ) {
F_1 ( V_2 , V_34 ) ;
F_3 ( V_2 ,
F_6 ( V_14 , V_2 -> V_31 ,
& args -> V_31 , V_19 , V_20 ) |
V_35 ) ;
} else {
F_1 ( V_2 , V_36 ) ;
F_2 ( V_2 , args -> V_31 . V_37 ) ;
F_3 ( V_2 , V_2 -> V_31 -> V_21 +
args -> V_31 . V_22 ) ;
}
}
if ( V_2 -> V_38 ) {
if ( args -> V_38 . V_32 &
V_33 ) {
F_1 ( V_2 , V_34 ) ;
F_3 ( V_2 ,
F_6 ( V_14 , V_2 -> V_38 ,
& args -> V_38 , V_19 , V_20 ) |
V_39 ) ;
} else {
if ( V_2 -> V_31 ) {
F_8 ( V_2 , V_19 , V_20 ) ;
F_4 ( V_2 ) ;
}
F_1 ( V_2 , V_36 ) ;
F_2 ( V_2 , args -> V_38 . V_37 ) ;
F_3 ( V_2 , V_2 -> V_38 -> V_21 +
args -> V_38 . V_22 ) ;
}
}
F_8 ( V_2 , V_19 , V_20 ) ;
if ( V_26 && V_29 )
F_1 ( V_2 , V_40 ) ;
if ( V_29 ) {
F_1 ( V_2 , V_41 ) ;
F_3 ( V_2 , ( V_14 -> V_42 -> V_21 +
V_14 -> V_43 +
( V_20 * V_14 -> V_44 + V_19 ) * 32 ) ) ;
}
if ( V_2 -> V_45 ) {
bool V_46 = ( ! V_2 -> V_47 &&
! V_2 -> V_48 &&
! V_2 -> V_49 ) ;
T_4 V_37 = V_35 ;
if ( ! V_46 )
V_37 |= V_50 ;
else if ( V_27 )
V_37 |= V_51 ;
F_1 ( V_2 , V_52 ) ;
F_3 ( V_2 ,
F_6 ( V_14 , V_2 -> V_45 ,
& args -> V_45 , V_19 , V_20 ) |
V_37 ) ;
}
if ( V_2 -> V_47 ) {
bool V_46 = ( ! V_2 -> V_48 &&
! V_2 -> V_49 ) ;
T_4 V_37 = V_39 ;
if ( V_2 -> V_45 )
F_8 ( V_2 , V_19 , V_20 ) ;
if ( ! V_46 )
V_37 |= V_50 ;
else if ( V_27 )
V_37 |= V_51 ;
F_1 ( V_2 , V_52 ) ;
F_3 ( V_2 ,
F_6 ( V_14 , V_2 -> V_47 ,
& args -> V_47 , V_19 , V_20 ) |
V_37 ) ;
}
if ( V_2 -> V_48 ) {
bool V_46 = ! V_2 -> V_49 ;
if ( V_2 -> V_45 || V_2 -> V_47 )
F_8 ( V_2 , V_19 , V_20 ) ;
F_1 ( V_2 , V_7 ) ;
F_2 ( V_2 , args -> V_48 . V_37 |
( V_46 ?
0 : V_10 ) ) ;
F_3 ( V_2 ,
( V_2 -> V_48 -> V_21 + args -> V_48 . V_22 ) |
( ( V_27 && V_46 ) ?
V_53 : 0 ) ) ;
}
if ( V_2 -> V_49 ) {
if ( V_2 -> V_45 || V_2 -> V_47 ||
V_2 -> V_48 ) {
F_8 ( V_2 , V_19 , V_20 ) ;
}
if ( V_27 )
F_1 ( V_2 , V_54 ) ;
else
F_1 ( V_2 , V_55 ) ;
}
}
static int F_10 ( struct V_56 * V_57 , struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_28 * args = V_14 -> args ;
bool V_29 = args -> V_30 != 0 ;
T_5 V_58 = args -> V_58 ;
T_5 V_59 = args -> V_59 ;
T_5 V_60 = args -> V_60 ;
T_5 V_61 = args -> V_61 ;
T_5 V_62 = V_60 - V_58 + 1 ;
T_5 V_63 = V_61 - V_59 + 1 ;
T_5 V_19 , V_20 ;
T_4 V_64 , V_65 ;
V_64 = V_66 ;
V_65 = V_67 ;
if ( args -> V_32 & V_68 ) {
V_64 += V_69 +
V_67 +
V_70 ;
}
if ( V_2 -> V_31 ) {
if ( args -> V_31 . V_32 &
V_33 ) {
V_65 += V_71 ;
} else {
V_65 += V_72 ;
}
}
if ( V_2 -> V_38 ) {
if ( args -> V_38 . V_32 &
V_33 ) {
V_65 += V_71 ;
} else {
if ( V_2 -> V_31 &&
! ( args -> V_31 . V_32 &
V_33 ) ) {
V_65 += V_67 ;
V_65 += V_70 ;
}
V_65 += V_72 ;
}
}
if ( V_29 ) {
V_64 += V_73 ;
V_65 += V_74 ;
}
if ( V_2 -> V_45 )
V_65 += V_75 ;
if ( V_2 -> V_47 )
V_65 += V_75 ;
if ( V_2 -> V_48 )
V_65 += V_70 ;
if ( V_2 -> V_49 )
V_65 += V_76 ;
V_65 += V_67 *
( ( V_2 -> V_45 != NULL ) +
( V_2 -> V_47 != NULL ) +
( V_2 -> V_49 != NULL ) +
( V_2 -> V_48 != NULL ) - 1 ) ;
V_64 += V_62 * V_63 * V_65 ;
V_2 -> V_4 = & F_11 ( V_57 , V_64 , true ) -> V_77 ;
if ( F_12 ( V_2 -> V_4 ) )
return F_13 ( V_2 -> V_4 ) ;
F_14 ( & F_15 ( & V_2 -> V_4 -> V_77 ) -> V_78 ,
& V_14 -> V_79 ) ;
if ( args -> V_32 & V_68 ) {
F_1 ( V_2 , V_80 ) ;
F_3 ( V_2 , args -> V_81 [ 0 ] ) ;
F_3 ( V_2 , args -> V_81 [ 1 ] ) ;
F_3 ( V_2 , args -> V_82 ) ;
F_1 ( V_2 , args -> V_83 ) ;
F_8 ( V_2 , 0 , 0 ) ;
F_1 ( V_2 , V_7 ) ;
F_2 ( V_2 , V_8 ) ;
F_3 ( V_2 , 0 ) ;
}
F_1 ( V_2 , V_84 ) ;
F_3 ( V_2 ,
( V_2 -> V_49 ? ( V_2 -> V_49 -> V_21 +
args -> V_49 . V_22 ) :
0 ) ) ;
F_2 ( V_2 , args -> V_24 ) ;
F_2 ( V_2 , args -> V_85 ) ;
F_2 ( V_2 , args -> V_49 . V_37 ) ;
for ( V_20 = V_59 ; V_20 <= V_61 ; V_20 ++ ) {
for ( V_19 = V_58 ; V_19 <= V_60 ; V_19 ++ ) {
bool V_26 = ( V_19 == V_58 && V_20 == V_59 ) ;
bool V_27 = ( V_19 == V_60 && V_20 == V_61 ) ;
F_9 ( V_14 , V_2 , V_19 , V_20 , V_26 , V_27 ) ;
}
}
F_16 ( V_2 -> V_6 != V_64 ) ;
V_14 -> V_86 = V_2 -> V_4 -> V_21 ;
V_14 -> V_87 = V_2 -> V_4 -> V_21 + V_2 -> V_6 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_15 * V_88 ,
struct V_17 * V_18 )
{
struct V_28 * args = V_14 -> args ;
T_3 V_89 = F_7 ( V_14 -> args -> V_24 , 32 ) ;
if ( V_18 -> V_22 > V_88 -> V_77 . V_64 ) {
F_18 ( L_1 ,
V_18 -> V_22 , V_88 -> V_77 . V_64 ) ;
return - V_90 ;
}
if ( ( V_88 -> V_77 . V_64 - V_18 -> V_22 ) / V_23 <
V_89 * args -> V_61 + args -> V_60 ) {
F_18 ( L_2
L_3 ,
args -> V_60 , args -> V_61 ,
V_88 -> V_77 . V_64 ,
V_18 -> V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static int F_19 ( struct V_13 * V_14 ,
struct V_15 * * V_88 ,
struct V_17 * V_18 )
{
if ( V_18 -> V_32 != 0 || V_18 -> V_37 != 0 ) {
F_18 ( L_4 ) ;
return - V_90 ;
}
if ( V_18 -> V_91 == ~ 0 )
return 0 ;
* V_88 = F_20 ( V_14 , V_18 -> V_91 ) ;
if ( ! * V_88 )
return - V_90 ;
V_14 -> V_92 [ V_14 -> V_93 ++ ] = * V_88 ;
if ( V_18 -> V_22 & 0xf ) {
F_18 ( L_5 ) ;
return - V_90 ;
}
return F_17 ( V_14 , * V_88 , V_18 ) ;
}
static int F_21 ( struct V_13 * V_14 ,
struct V_15 * * V_88 ,
struct V_17 * V_18 ,
bool V_94 )
{
T_5 V_95 = F_22 ( V_18 -> V_37 ,
V_96 ) ;
T_5 V_97 = F_22 ( V_18 -> V_37 ,
V_9 ) ;
T_5 V_98 = F_22 ( V_18 -> V_37 ,
V_99 ) ;
int V_100 ;
int V_101 ;
if ( V_18 -> V_32 & ~ V_33 ) {
F_18 ( L_6 ) ;
return - V_90 ;
}
if ( V_18 -> V_91 == ~ 0 )
return 0 ;
* V_88 = F_20 ( V_14 , V_18 -> V_91 ) ;
if ( ! * V_88 )
return - V_90 ;
if ( V_94 )
V_14 -> V_92 [ V_14 -> V_93 ++ ] = * V_88 ;
if ( V_18 -> V_32 & V_33 ) {
if ( V_18 == & V_14 -> args -> V_48 ) {
F_18 ( L_7 ) ;
return - V_90 ;
}
if ( V_18 -> V_37 != 0 ) {
F_18 ( L_8
L_9 ) ;
return - V_90 ;
}
V_101 = F_17 ( V_14 , * V_88 , V_18 ) ;
if ( ! V_101 )
return V_101 ;
return 0 ;
}
if ( V_18 -> V_37 & ~ ( V_102 |
V_103 |
V_104 ) ) {
F_18 ( L_10 ,
V_18 -> V_37 ) ;
return - V_90 ;
}
if ( V_95 > V_105 ) {
F_18 ( L_11 ) ;
return - V_90 ;
}
if ( V_97 == V_106 ) {
if ( V_98 != 0 ) {
F_18 ( L_12 ) ;
return - V_90 ;
}
V_100 = 4 ;
} else if ( V_97 == V_107 ) {
switch ( V_98 ) {
case V_108 :
case V_109 :
V_100 = 2 ;
break;
case V_110 :
V_100 = 4 ;
break;
default:
F_18 ( L_13 ) ;
return - V_90 ;
}
} else {
F_18 ( L_14 , V_97 ) ;
return - V_90 ;
}
if ( V_18 -> V_22 & 0xf ) {
F_18 ( L_15 ) ;
return - V_90 ;
}
if ( ! F_23 ( V_14 , * V_88 , V_18 -> V_22 , V_95 ,
V_14 -> args -> V_24 , V_14 -> args -> V_85 , V_100 ) ) {
return - V_90 ;
}
return 0 ;
}
static int
F_24 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_15 * * V_88 ,
struct V_17 * V_18 )
{
T_5 V_95 = F_22 ( V_18 -> V_37 ,
V_111 ) ;
T_5 V_98 = F_22 ( V_18 -> V_37 ,
V_112 ) ;
int V_100 ;
if ( V_18 -> V_32 != 0 ) {
F_18 ( L_16 ) ;
return - V_90 ;
}
if ( V_18 -> V_37 & ~ ( V_113 |
V_114 |
V_115 |
V_116 ) ) {
F_18 ( L_17 ,
V_18 -> V_37 ) ;
return - V_90 ;
}
if ( V_18 -> V_91 == ~ 0 )
return 0 ;
* V_88 = F_20 ( V_14 , V_18 -> V_91 ) ;
if ( ! * V_88 )
return - V_90 ;
V_14 -> V_92 [ V_14 -> V_93 ++ ] = * V_88 ;
if ( V_95 > V_105 ) {
F_18 ( L_11 ) ;
return - V_90 ;
}
switch ( V_98 ) {
case V_117 :
case V_118 :
V_100 = 2 ;
break;
case V_119 :
V_100 = 4 ;
break;
default:
F_18 ( L_13 ) ;
return - V_90 ;
}
if ( ! F_23 ( V_14 , * V_88 , V_18 -> V_22 , V_95 ,
V_14 -> args -> V_24 , V_14 -> args -> V_85 , V_100 ) ) {
return - V_90 ;
}
return 0 ;
}
int F_25 ( struct V_56 * V_57 , struct V_13 * V_14 )
{
struct V_1 V_2 = { 0 } ;
struct V_28 * args = V_14 -> args ;
bool V_29 = args -> V_30 != 0 ;
int V_101 ;
if ( args -> V_58 > args -> V_60 ||
args -> V_59 > args -> V_61 ) {
F_18 ( L_18 ,
args -> V_58 , args -> V_59 ,
args -> V_60 , args -> V_61 ) ;
return - V_90 ;
}
if ( V_29 &&
( args -> V_60 > V_14 -> V_44 ||
args -> V_61 > V_14 -> V_120 ) ) {
F_18 ( L_19
L_20 ,
args -> V_60 , args -> V_61 ,
V_14 -> V_44 , V_14 -> V_120 ) ;
return - V_90 ;
}
V_101 = F_24 ( V_14 , & V_2 ,
& V_2 . V_49 ,
& args -> V_49 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_21 ( V_14 , & V_2 . V_31 , & args -> V_31 ,
false ) ;
if ( V_101 )
return V_101 ;
V_101 = F_21 ( V_14 , & V_2 . V_38 , & args -> V_38 ,
false ) ;
if ( V_101 )
return V_101 ;
V_101 = F_21 ( V_14 , & V_2 . V_48 , & args -> V_48 ,
true ) ;
if ( V_101 )
return V_101 ;
V_101 = F_19 ( V_14 , & V_2 . V_45 ,
& args -> V_45 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_19 ( V_14 , & V_2 . V_47 ,
& args -> V_47 ) ;
if ( V_101 )
return V_101 ;
if ( ! V_2 . V_49 && ! V_2 . V_48 &&
! V_2 . V_45 && ! V_2 . V_47 ) {
F_18 ( L_21 ) ;
return - V_90 ;
}
return F_10 ( V_57 , V_14 , & V_2 ) ;
}
