static T_1
F_1 ( T_1 V_1 , bool V_2 )
{
if ( V_1 < 32 ) {
if ( V_2 )
return 32 + V_1 ;
else
return V_1 ;
} else if ( V_1 <= V_3 ) {
return 64 + V_1 - V_4 ;
} else {
return ~ 0 ;
}
}
static T_1
F_2 ( T_2 V_5 )
{
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
T_1 V_8 = F_3 ( V_5 , V_9 ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
if ( V_8 == V_14 )
return V_10 ;
else if ( V_8 == V_15 && V_6 != V_16 )
return 32 + V_12 ;
else if ( V_8 <= V_17 )
return 64 + V_8 ;
else
return ~ 0 ;
}
static bool
F_4 ( T_1 V_1 )
{
return ( V_1 == V_18 ||
V_1 == V_19 ) ;
}
static bool
F_5 ( T_1 V_1 )
{
return ( V_1 >= V_18 &&
V_1 <= V_20 ) ;
}
static bool
F_6 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
int V_25 )
{
T_1 V_26 = V_22 -> V_27 ;
int V_28 ;
struct V_29 * V_30 ;
V_30 = F_7 ( V_22 -> V_31 ,
( V_26 + 1 ) * sizeof( * V_30 ) ,
V_32 ) ;
if ( ! V_30 )
return false ;
memcpy ( & V_30 [ V_26 ] ,
& V_24 -> V_33 [ V_25 ] ,
sizeof( * V_30 ) ) ;
V_22 -> V_27 = V_26 + 1 ;
V_22 -> V_31 = V_30 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ )
V_24 -> V_33 [ V_25 ] . V_34 [ V_28 ] = ~ 0 ;
return true ;
}
static bool
F_8 ( T_2 V_5 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
bool V_35 )
{
T_1 V_1 = ( V_35 ?
F_3 ( V_5 , V_36 ) :
F_3 ( V_5 , V_37 ) ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
int V_25 = V_1 > V_38 ;
bool V_39 = F_4 ( V_1 ) ;
bool V_40 = V_39 && V_24 -> V_41 [ V_25 ] == 0 ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_40 ) {
T_1 V_42 = F_3 ( V_5 , V_43 ) ;
T_1 V_44 , V_45 ;
if ( V_6 == V_16 ) {
F_9 ( L_1 ) ;
return false ;
}
if ( V_35 ||
F_3 ( V_5 , V_46 ) != V_47 ) {
F_9 ( L_2 ) ;
return false ;
}
V_44 = F_2 ( V_5 ) ;
if ( V_44 == ~ 0 ) {
F_9 ( L_3 ) ;
return false ;
}
V_45 = V_24 -> V_48 [ V_44 ] ;
if ( V_45 == ~ 0 ) {
F_9 ( L_3 ) ;
return false ;
}
V_24 -> V_33 [ V_25 ] . V_34 [ 1 ] =
V_45 ;
if ( ! ( V_42 == V_14 && V_10 == V_49 ) &&
! ( V_42 == V_15 && V_12 == V_49 ) ) {
F_9 ( L_4 ) ;
return false ;
}
V_24 -> V_33 [ V_25 ] . V_40 = true ;
} else {
if ( V_10 == V_49 || ( V_6 != V_16 &&
V_12 == V_49 ) ) {
F_9 ( L_5
L_6 ) ;
return false ;
}
}
if ( V_24 -> V_41 [ V_25 ] >= 4 ) {
F_9 ( L_7 ,
V_25 ) ;
return false ;
}
V_24 -> V_33 [ V_25 ] . V_34 [ V_24 -> V_41 [ V_25 ] ] =
V_22 -> V_50 ;
V_24 -> V_41 [ V_25 ] ++ ;
if ( ! V_40 )
V_22 -> V_50 += 4 ;
if ( V_39 ) {
if ( ! F_6 ( V_22 ,
V_24 , V_25 ) ) {
return false ;
}
V_24 -> V_41 [ V_25 ] = 0 ;
}
return true ;
}
static bool
F_10 ( T_2 V_5 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
bool V_35 )
{
T_1 V_1 = ( V_35 ?
F_3 ( V_5 , V_36 ) :
F_3 ( V_5 , V_37 ) ) ;
switch ( V_1 ) {
case V_51 :
F_9 ( L_8 ) ;
return false ;
case V_52 :
case V_53 :
case V_54 :
return true ;
case V_18 :
case V_55 :
case V_56 :
case V_38 :
case V_19 :
case V_57 :
case V_58 :
case V_20 :
return F_8 ( V_5 , V_22 , V_24 ,
V_35 ) ;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
F_9 ( L_9 , V_1 ) ;
return false ;
case V_63 :
F_9 ( L_10 ) ;
return false ;
case V_64 :
case V_65 :
return true ;
case V_66 :
return true ;
}
return true ;
}
static void
F_11 ( T_2 V_5 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
T_1 V_67 = F_3 ( V_5 , V_46 ) ;
T_1 V_68 = F_3 ( V_5 , V_37 ) ;
T_1 V_69 = F_3 ( V_5 , V_36 ) ;
T_1 V_70 = F_3 ( V_5 , V_71 ) ;
T_1 V_8 = F_3 ( V_5 , V_9 ) ;
T_1 V_42 = F_3 ( V_5 , V_43 ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
bool V_72 = V_5 & V_73 ;
T_1 V_74 , V_75 , V_76 ;
bool V_77 ;
V_74 = F_2 ( V_5 ) ;
V_77 = ( V_74 != ~ 0 &&
V_24 -> V_78 [ V_74 ] ) ;
V_75 = F_1 ( V_68 , V_72 ) ;
V_76 = F_1 ( V_69 , ! V_72 ) ;
if ( V_76 != ~ 0 ) {
V_24 -> V_78 [ V_76 ] = false ;
V_24 -> V_48 [ V_76 ] = ~ 0 ;
}
if ( V_75 != ~ 0 ) {
V_24 -> V_78 [ V_75 ] = false ;
V_24 -> V_48 [ V_75 ] = ~ 0 ;
} else {
return;
}
if ( V_70 != V_79 )
return;
if ( V_67 == V_80 ) {
if ( V_6 != V_16 || V_12 != 0 ||
( V_8 != V_15 && V_42 != V_15 ) ) {
return;
}
V_24 -> V_78 [ V_75 ] = true ;
} else if ( V_67 == V_81 ) {
if ( ! V_77 )
return;
if ( ! ( V_42 == V_14 && V_10 == V_49 ) &&
! ( V_42 == V_15 && V_12 == V_49 &&
V_6 != V_16 ) ) {
return;
}
V_24 -> V_48 [ V_75 ] =
V_22 -> V_50 ;
}
}
static bool
F_12 ( T_2 V_5 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
T_1 V_68 = F_3 ( V_5 , V_37 ) ;
T_1 V_69 = F_3 ( V_5 , V_36 ) ;
bool V_82 ;
if ( F_5 ( V_68 ) && F_5 ( V_69 ) ) {
F_9 ( L_11 ) ;
return false ;
}
V_82 = ( F_10 ( V_5 , V_22 , V_24 ,
false ) &&
F_10 ( V_5 , V_22 , V_24 ,
true ) ) ;
F_11 ( V_5 , V_22 , V_24 ) ;
return V_82 ;
}
static bool
F_13 ( T_2 V_5 ,
struct V_21 * V_22 )
{
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_10 == V_49 ||
( V_12 == V_49 && V_6 != V_16 ) ) {
V_22 -> V_50 += 4 ;
}
return true ;
}
struct V_21 *
F_14 ( struct V_83 * V_84 )
{
bool V_85 = false ;
int V_86 = 0 ;
T_1 V_87 , V_88 ;
T_2 * V_89 ;
struct V_21 * V_22 ;
struct V_23 V_24 ;
int V_28 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
V_24 . V_33 [ V_28 / 4 ] . V_34 [ V_28 % 4 ] = ~ 0 ;
for ( V_28 = 0 ; V_28 < F_15 ( V_24 . V_48 ) ; V_28 ++ )
V_24 . V_48 [ V_28 ] = ~ 0 ;
V_89 = V_84 -> V_90 ;
V_88 = V_84 -> V_91 . V_92 / sizeof( T_2 ) ;
V_22 = F_16 ( 1 , sizeof( * V_22 ) , V_32 ) ;
if ( ! V_22 )
return NULL ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
T_2 V_5 = V_89 [ V_87 ] ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
switch ( V_6 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_16 :
if ( ! F_12 ( V_5 , V_22 ,
& V_24 ) ) {
F_9 ( L_12 , V_87 ) ;
goto V_100;
}
if ( ! F_13 ( V_5 , V_22 ) )
goto V_100;
if ( V_6 == V_99 ) {
V_85 = true ;
V_86 = V_87 ;
}
break;
case V_101 :
if ( ! F_12 ( V_5 , V_22 ,
& V_24 ) ) {
F_9 ( L_13 , V_87 ) ;
goto V_100;
}
break;
default:
F_9 ( L_14
L_15 , V_6 , V_87 ) ;
goto V_100;
}
if ( V_85 && V_87 == V_86 + 2 )
break;
}
if ( V_87 == V_88 ) {
F_9 ( L_16
L_17 ,
V_84 -> V_91 . V_92 ) ;
goto V_100;
}
V_22 -> V_102 =
( V_22 -> V_50 +
4 * V_22 -> V_27 ) ;
return V_22 ;
V_100:
if ( V_22 ) {
F_17 ( V_22 -> V_31 ) ;
F_17 ( V_22 ) ;
}
return NULL ;
}
