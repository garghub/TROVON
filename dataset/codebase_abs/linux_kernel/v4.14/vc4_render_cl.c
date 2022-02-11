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
F_3 ( V_2 , ( V_14 -> V_42 +
( V_20 * V_14 -> V_43 + V_19 ) * 32 ) ) ;
}
if ( V_2 -> V_44 ) {
bool V_45 = ( ! V_2 -> V_46 &&
! V_2 -> V_47 &&
! V_2 -> V_48 ) ;
T_4 V_37 = V_35 ;
if ( ! V_45 )
V_37 |= V_49 ;
else if ( V_27 )
V_37 |= V_50 ;
F_1 ( V_2 , V_51 ) ;
F_3 ( V_2 ,
F_6 ( V_14 , V_2 -> V_44 ,
& args -> V_44 , V_19 , V_20 ) |
V_37 ) ;
}
if ( V_2 -> V_46 ) {
bool V_45 = ( ! V_2 -> V_47 &&
! V_2 -> V_48 ) ;
T_4 V_37 = V_39 ;
if ( V_2 -> V_44 )
F_8 ( V_2 , V_19 , V_20 ) ;
if ( ! V_45 )
V_37 |= V_49 ;
else if ( V_27 )
V_37 |= V_50 ;
F_1 ( V_2 , V_51 ) ;
F_3 ( V_2 ,
F_6 ( V_14 , V_2 -> V_46 ,
& args -> V_46 , V_19 , V_20 ) |
V_37 ) ;
}
if ( V_2 -> V_47 ) {
bool V_45 = ! V_2 -> V_48 ;
if ( V_2 -> V_44 || V_2 -> V_46 )
F_8 ( V_2 , V_19 , V_20 ) ;
F_1 ( V_2 , V_7 ) ;
F_2 ( V_2 , args -> V_47 . V_37 |
( V_45 ?
0 : V_10 ) ) ;
F_3 ( V_2 ,
( V_2 -> V_47 -> V_21 + args -> V_47 . V_22 ) |
( ( V_27 && V_45 ) ?
V_52 : 0 ) ) ;
}
if ( V_2 -> V_48 ) {
if ( V_2 -> V_44 || V_2 -> V_46 ||
V_2 -> V_47 ) {
F_8 ( V_2 , V_19 , V_20 ) ;
}
if ( V_27 )
F_1 ( V_2 , V_53 ) ;
else
F_1 ( V_2 , V_54 ) ;
}
}
static int F_10 ( struct V_55 * V_56 , struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_28 * args = V_14 -> args ;
bool V_29 = args -> V_30 != 0 ;
T_5 V_57 = args -> V_57 ;
T_5 V_58 = args -> V_58 ;
T_5 V_59 = args -> V_59 ;
T_5 V_60 = args -> V_60 ;
T_5 V_61 = V_59 - V_57 + 1 ;
T_5 V_62 = V_60 - V_58 + 1 ;
T_5 V_63 , V_64 ;
T_4 V_65 , V_66 ;
bool V_67 = true ;
bool V_68 = true ;
if ( args -> V_32 & V_69 ) {
if ( ! ( args -> V_32 & V_70 ) )
V_67 = false ;
if ( ! ( args -> V_32 & V_71 ) )
V_68 = false ;
}
V_65 = V_72 ;
V_66 = V_73 ;
if ( args -> V_32 & V_74 ) {
V_65 += V_75 +
V_73 +
V_76 ;
}
if ( V_2 -> V_31 ) {
if ( args -> V_31 . V_32 &
V_33 ) {
V_66 += V_77 ;
} else {
V_66 += V_78 ;
}
}
if ( V_2 -> V_38 ) {
if ( args -> V_38 . V_32 &
V_33 ) {
V_66 += V_77 ;
} else {
if ( V_2 -> V_31 &&
! ( args -> V_31 . V_32 &
V_33 ) ) {
V_66 += V_73 ;
V_66 += V_76 ;
}
V_66 += V_78 ;
}
}
if ( V_29 ) {
V_65 += V_79 ;
V_66 += V_80 ;
}
if ( V_2 -> V_44 )
V_66 += V_81 ;
if ( V_2 -> V_46 )
V_66 += V_81 ;
if ( V_2 -> V_47 )
V_66 += V_76 ;
if ( V_2 -> V_48 )
V_66 += V_82 ;
V_66 += V_73 *
( ( V_2 -> V_44 != NULL ) +
( V_2 -> V_46 != NULL ) +
( V_2 -> V_48 != NULL ) +
( V_2 -> V_47 != NULL ) - 1 ) ;
V_65 += V_61 * V_62 * V_66 ;
V_2 -> V_4 = & F_11 ( V_56 , V_65 , true , V_83 ) -> V_84 ;
if ( F_12 ( V_2 -> V_4 ) )
return F_13 ( V_2 -> V_4 ) ;
F_14 ( & F_15 ( & V_2 -> V_4 -> V_84 ) -> V_85 ,
& V_14 -> V_86 ) ;
if ( args -> V_32 & V_74 ) {
F_1 ( V_2 , V_87 ) ;
F_3 ( V_2 , args -> V_88 [ 0 ] ) ;
F_3 ( V_2 , args -> V_88 [ 1 ] ) ;
F_3 ( V_2 , args -> V_89 ) ;
F_1 ( V_2 , args -> V_90 ) ;
F_8 ( V_2 , 0 , 0 ) ;
F_1 ( V_2 , V_7 ) ;
F_2 ( V_2 , V_8 ) ;
F_3 ( V_2 , 0 ) ;
}
F_1 ( V_2 , V_91 ) ;
F_3 ( V_2 ,
( V_2 -> V_48 ? ( V_2 -> V_48 -> V_21 +
args -> V_48 . V_22 ) :
0 ) ) ;
F_2 ( V_2 , args -> V_24 ) ;
F_2 ( V_2 , args -> V_92 ) ;
F_2 ( V_2 , args -> V_48 . V_37 ) ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
int V_20 = V_68 ? V_58 + V_64 : V_60 - V_64 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
int V_19 = V_67 ? V_57 + V_63 : V_59 - V_63 ;
bool V_26 = ( V_63 == 0 && V_64 == 0 ) ;
bool V_27 = ( V_63 == V_61 - 1 && V_64 == V_62 - 1 ) ;
F_9 ( V_14 , V_2 , V_19 , V_20 , V_26 , V_27 ) ;
}
}
F_16 ( V_2 -> V_6 != V_65 ) ;
V_14 -> V_93 = V_2 -> V_4 -> V_21 ;
V_14 -> V_94 = V_2 -> V_4 -> V_21 + V_2 -> V_6 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_15 * V_95 ,
struct V_17 * V_18 )
{
struct V_28 * args = V_14 -> args ;
T_3 V_96 = F_7 ( V_14 -> args -> V_24 , 32 ) ;
if ( V_18 -> V_22 > V_95 -> V_84 . V_65 ) {
F_18 ( L_1 ,
V_18 -> V_22 , V_95 -> V_84 . V_65 ) ;
return - V_97 ;
}
if ( ( V_95 -> V_84 . V_65 - V_18 -> V_22 ) / V_23 <
V_96 * args -> V_60 + args -> V_59 ) {
F_18 ( L_2
L_3 ,
args -> V_59 , args -> V_60 ,
V_95 -> V_84 . V_65 ,
V_18 -> V_22 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_19 ( struct V_13 * V_14 ,
struct V_15 * * V_95 ,
struct V_17 * V_18 )
{
if ( V_18 -> V_32 != 0 || V_18 -> V_37 != 0 ) {
F_18 ( L_4 ) ;
return - V_97 ;
}
if ( V_18 -> V_98 == ~ 0 )
return 0 ;
* V_95 = F_20 ( V_14 , V_18 -> V_98 ) ;
if ( ! * V_95 )
return - V_97 ;
V_14 -> V_99 [ V_14 -> V_100 ++ ] = * V_95 ;
if ( V_18 -> V_22 & 0xf ) {
F_18 ( L_5 ) ;
return - V_97 ;
}
return F_17 ( V_14 , * V_95 , V_18 ) ;
}
static int F_21 ( struct V_13 * V_14 ,
struct V_15 * * V_95 ,
struct V_17 * V_18 ,
bool V_101 )
{
T_5 V_102 = F_22 ( V_18 -> V_37 ,
V_103 ) ;
T_5 V_104 = F_22 ( V_18 -> V_37 ,
V_9 ) ;
T_5 V_105 = F_22 ( V_18 -> V_37 ,
V_106 ) ;
int V_107 ;
int V_108 ;
if ( V_18 -> V_32 & ~ V_33 ) {
F_18 ( L_6 ) ;
return - V_97 ;
}
if ( V_18 -> V_98 == ~ 0 )
return 0 ;
* V_95 = F_20 ( V_14 , V_18 -> V_98 ) ;
if ( ! * V_95 )
return - V_97 ;
if ( V_101 )
V_14 -> V_99 [ V_14 -> V_100 ++ ] = * V_95 ;
if ( V_18 -> V_32 & V_33 ) {
if ( V_18 == & V_14 -> args -> V_47 ) {
F_18 ( L_7 ) ;
return - V_97 ;
}
if ( V_18 -> V_37 != 0 ) {
F_18 ( L_8
L_9 ) ;
return - V_97 ;
}
V_108 = F_17 ( V_14 , * V_95 , V_18 ) ;
if ( V_108 )
return V_108 ;
return 0 ;
}
if ( V_18 -> V_37 & ~ ( V_109 |
V_110 |
V_111 ) ) {
F_18 ( L_10 ,
V_18 -> V_37 ) ;
return - V_97 ;
}
if ( V_102 > V_112 ) {
F_18 ( L_11 ) ;
return - V_97 ;
}
if ( V_104 == V_113 ) {
if ( V_105 != 0 ) {
F_18 ( L_12 ) ;
return - V_97 ;
}
V_107 = 4 ;
} else if ( V_104 == V_114 ) {
switch ( V_105 ) {
case V_115 :
case V_116 :
V_107 = 2 ;
break;
case V_117 :
V_107 = 4 ;
break;
default:
F_18 ( L_13 ) ;
return - V_97 ;
}
} else {
F_18 ( L_14 , V_104 ) ;
return - V_97 ;
}
if ( V_18 -> V_22 & 0xf ) {
F_18 ( L_15 ) ;
return - V_97 ;
}
if ( ! F_23 ( V_14 , * V_95 , V_18 -> V_22 , V_102 ,
V_14 -> args -> V_24 , V_14 -> args -> V_92 , V_107 ) ) {
return - V_97 ;
}
return 0 ;
}
static int
F_24 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_15 * * V_95 ,
struct V_17 * V_18 )
{
T_5 V_102 = F_22 ( V_18 -> V_37 ,
V_118 ) ;
T_5 V_105 = F_22 ( V_18 -> V_37 ,
V_119 ) ;
int V_107 ;
if ( V_18 -> V_32 != 0 ) {
F_18 ( L_16 ) ;
return - V_97 ;
}
if ( V_18 -> V_37 & ~ ( V_120 |
V_121 |
V_122 |
V_123 ) ) {
F_18 ( L_17 ,
V_18 -> V_37 ) ;
return - V_97 ;
}
if ( V_18 -> V_98 == ~ 0 )
return 0 ;
* V_95 = F_20 ( V_14 , V_18 -> V_98 ) ;
if ( ! * V_95 )
return - V_97 ;
V_14 -> V_99 [ V_14 -> V_100 ++ ] = * V_95 ;
if ( V_102 > V_112 ) {
F_18 ( L_11 ) ;
return - V_97 ;
}
switch ( V_105 ) {
case V_124 :
case V_125 :
V_107 = 2 ;
break;
case V_126 :
V_107 = 4 ;
break;
default:
F_18 ( L_13 ) ;
return - V_97 ;
}
if ( ! F_23 ( V_14 , * V_95 , V_18 -> V_22 , V_102 ,
V_14 -> args -> V_24 , V_14 -> args -> V_92 , V_107 ) ) {
return - V_97 ;
}
return 0 ;
}
int F_25 ( struct V_55 * V_56 , struct V_13 * V_14 )
{
struct V_1 V_2 = { 0 } ;
struct V_28 * args = V_14 -> args ;
bool V_29 = args -> V_30 != 0 ;
int V_108 ;
if ( args -> V_57 > args -> V_59 ||
args -> V_58 > args -> V_60 ) {
F_18 ( L_18 ,
args -> V_57 , args -> V_58 ,
args -> V_59 , args -> V_60 ) ;
return - V_97 ;
}
if ( V_29 &&
( args -> V_59 > V_14 -> V_43 ||
args -> V_60 > V_14 -> V_127 ) ) {
F_18 ( L_19
L_20 ,
args -> V_59 , args -> V_60 ,
V_14 -> V_43 , V_14 -> V_127 ) ;
return - V_97 ;
}
V_108 = F_24 ( V_14 , & V_2 ,
& V_2 . V_48 ,
& args -> V_48 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_21 ( V_14 , & V_2 . V_31 , & args -> V_31 ,
false ) ;
if ( V_108 )
return V_108 ;
V_108 = F_21 ( V_14 , & V_2 . V_38 , & args -> V_38 ,
false ) ;
if ( V_108 )
return V_108 ;
V_108 = F_21 ( V_14 , & V_2 . V_47 , & args -> V_47 ,
true ) ;
if ( V_108 )
return V_108 ;
V_108 = F_19 ( V_14 , & V_2 . V_44 ,
& args -> V_44 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_19 ( V_14 , & V_2 . V_46 ,
& args -> V_46 ) ;
if ( V_108 )
return V_108 ;
if ( ! V_2 . V_48 && ! V_2 . V_47 &&
! V_2 . V_44 && ! V_2 . V_46 ) {
F_18 ( L_21 ) ;
return - V_97 ;
}
return F_10 ( V_56 , V_14 , & V_2 ) ;
}
