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
F_8 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
bool V_35 )
{
T_2 V_5 = V_24 -> V_36 [ V_24 -> V_37 ] ;
T_1 V_1 = ( V_35 ?
F_3 ( V_5 , V_38 ) :
F_3 ( V_5 , V_39 ) ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
int V_25 = V_1 > V_40 ;
bool V_41 = F_4 ( V_1 ) ;
bool V_42 = V_41 && V_24 -> V_43 [ V_25 ] == 0 ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_42 ) {
T_1 V_44 = F_3 ( V_5 , V_45 ) ;
T_1 V_46 , V_47 ;
if ( V_6 == V_16 ) {
F_9 ( L_1 ) ;
return false ;
}
if ( V_35 ||
F_3 ( V_5 , V_48 ) != V_49 ) {
F_9 ( L_2 ) ;
return false ;
}
V_46 = F_2 ( V_5 ) ;
if ( V_46 == ~ 0 ) {
F_9 ( L_3 ) ;
return false ;
}
V_47 = V_24 -> V_50 [ V_46 ] ;
if ( V_47 == ~ 0 ) {
F_9 ( L_3 ) ;
return false ;
}
V_24 -> V_33 [ V_25 ] . V_34 [ 1 ] =
V_47 ;
if ( ! ( V_44 == V_14 && V_10 == V_51 ) &&
! ( V_44 == V_15 && V_12 == V_51 ) ) {
F_9 ( L_4 ) ;
return false ;
}
V_24 -> V_33 [ V_25 ] . V_42 = true ;
} else {
if ( V_10 == V_51 || ( V_6 != V_16 &&
V_12 == V_51 ) ) {
F_9 ( L_5
L_6 ) ;
return false ;
}
}
if ( V_24 -> V_43 [ V_25 ] >= 4 ) {
F_9 ( L_7 ,
V_25 ) ;
return false ;
}
V_24 -> V_33 [ V_25 ] . V_34 [ V_24 -> V_43 [ V_25 ] ] =
V_22 -> V_52 ;
V_24 -> V_43 [ V_25 ] ++ ;
if ( ! V_42 ) {
if ( V_24 -> V_53 ) {
F_9 ( L_8 ) ;
return false ;
}
V_22 -> V_52 += 4 ;
}
if ( V_41 ) {
if ( ! F_6 ( V_22 ,
V_24 , V_25 ) ) {
return false ;
}
V_24 -> V_43 [ V_25 ] = 0 ;
}
return true ;
}
static bool F_10 ( struct V_21 * V_22 )
{
T_1 V_54 = V_22 -> V_55 ;
T_1 V_56 = V_22 -> V_52 / 4 ;
V_22 -> V_57 =
F_7 ( V_22 -> V_57 ,
( V_54 + 1 ) *
sizeof( * V_22 -> V_57 ) ,
V_32 ) ;
if ( ! V_22 -> V_57 )
return false ;
V_22 -> V_57 [ V_54 ] = V_56 ;
V_22 -> V_55 ++ ;
return true ;
}
static bool
F_11 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
bool V_35 )
{
T_2 V_5 = V_24 -> V_36 [ V_24 -> V_37 ] ;
T_3 V_44 = F_3 ( V_5 , V_45 ) ;
T_3 V_10 = F_3 ( V_5 , V_11 ) ;
T_3 V_12 = F_3 ( V_5 , V_13 ) ;
T_3 V_58 = F_2 ( V_5 ) ;
T_3 V_59 = V_22 -> V_52 + 4 ;
switch ( F_3 ( V_5 , V_7 ) ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
break;
default:
F_9 ( L_9
L_10 ) ;
return false ;
}
if ( V_35 || F_3 ( V_5 , V_48 ) != V_49 ) {
F_9 ( L_11 ) ;
return false ;
}
if ( F_3 ( V_5 , V_65 ) != V_66 ) {
F_9 ( L_12 ) ;
return false ;
}
if ( F_3 ( V_5 , V_67 ) != V_68 &&
! ( V_5 & V_69 ) ) {
F_9 ( L_13 ) ;
return false ;
}
if ( V_58 == - 1 ) {
F_9 ( L_14
L_15 ) ;
return false ;
}
if ( V_24 -> V_70 [ V_58 ] != V_59 ) {
F_9 ( L_16 ,
V_24 -> V_70 [ V_58 ] ,
V_59 ) ;
return false ;
}
if ( ! ( V_44 == V_14 && V_10 == V_51 ) &&
! ( V_44 == V_15 && V_12 == V_51 ) ) {
F_9 ( L_17
L_18 ) ;
return false ;
}
V_24 -> V_53 = false ;
V_24 -> V_71 = false ;
return F_10 ( V_22 ) ;
}
static bool
F_12 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
bool V_35 )
{
T_2 V_5 = V_24 -> V_36 [ V_24 -> V_37 ] ;
T_1 V_1 = ( V_35 ?
F_3 ( V_5 , V_38 ) :
F_3 ( V_5 , V_39 ) ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
bool V_72 = V_5 & V_73 ;
bool V_2 = V_35 ^ V_72 ;
T_3 V_74 = F_1 ( V_1 , V_2 ) ;
if ( V_74 != - 1 ) {
T_1 V_75 = F_3 ( V_5 , V_65 ) ;
T_1 V_76 = F_3 ( V_5 , V_77 ) ;
if ( V_6 == V_78 &&
F_3 ( V_5 , V_67 ) == V_68 &&
( ( V_35 && V_76 == V_66 ) ||
( ! V_35 && V_75 == V_66 ) ) ) {
V_24 -> V_70 [ V_74 ] =
F_3 ( V_5 , V_79 ) ;
} else {
V_24 -> V_70 [ V_74 ] = ~ 0 ;
}
}
switch ( V_1 ) {
case V_80 :
if ( V_2 ) {
F_9 ( L_19
L_20 ) ;
return false ;
}
return F_11 ( V_22 ,
V_24 ,
V_35 ) ;
case V_81 :
case V_82 :
case V_83 :
return true ;
case V_18 :
case V_84 :
case V_85 :
case V_40 :
case V_19 :
case V_86 :
case V_87 :
case V_20 :
return F_8 ( V_22 , V_24 ,
V_35 ) ;
case V_88 :
case V_89 :
case V_90 :
case V_91 :
F_9 ( L_21 , V_1 ) ;
return false ;
case V_92 :
F_9 ( L_22 ) ;
return false ;
case V_93 :
case V_94 :
return true ;
case V_95 :
return true ;
}
return true ;
}
static void
F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
T_2 V_5 = V_24 -> V_36 [ V_24 -> V_37 ] ;
T_1 V_96 = F_3 ( V_5 , V_48 ) ;
T_1 V_97 = F_3 ( V_5 , V_39 ) ;
T_1 V_98 = F_3 ( V_5 , V_38 ) ;
T_1 V_75 = F_3 ( V_5 , V_65 ) ;
T_1 V_8 = F_3 ( V_5 , V_9 ) ;
T_1 V_44 = F_3 ( V_5 , V_45 ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
bool V_72 = V_5 & V_73 ;
T_1 V_99 , V_100 , V_101 ;
bool V_102 ;
V_99 = F_2 ( V_5 ) ;
V_102 = ( V_99 != ~ 0 &&
V_24 -> V_103 [ V_99 ] ) ;
V_100 = F_1 ( V_97 , V_72 ) ;
V_101 = F_1 ( V_98 , ! V_72 ) ;
if ( V_101 != ~ 0 ) {
V_24 -> V_103 [ V_101 ] = false ;
V_24 -> V_50 [ V_101 ] = ~ 0 ;
}
if ( V_100 != ~ 0 ) {
V_24 -> V_103 [ V_100 ] = false ;
V_24 -> V_50 [ V_100 ] = ~ 0 ;
} else {
return;
}
if ( V_75 != V_66 )
return;
if ( V_96 == V_104 ) {
if ( V_6 != V_16 || V_12 != 0 ||
( V_8 != V_15 && V_44 != V_15 ) ) {
return;
}
V_24 -> V_103 [ V_100 ] = true ;
} else if ( V_96 == V_105 ) {
if ( ! V_102 )
return;
if ( ! ( V_44 == V_14 && V_10 == V_51 ) &&
! ( V_44 == V_15 && V_12 == V_51 &&
V_6 != V_16 ) ) {
return;
}
V_24 -> V_50 [ V_100 ] =
V_22 -> V_52 ;
}
}
static bool
F_14 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
T_2 V_5 = V_24 -> V_36 [ V_24 -> V_37 ] ;
T_1 V_97 = F_3 ( V_5 , V_39 ) ;
T_1 V_98 = F_3 ( V_5 , V_38 ) ;
bool V_106 ;
if ( F_5 ( V_97 ) && F_5 ( V_98 ) ) {
F_9 ( L_23 ) ;
return false ;
}
V_106 = ( F_12 ( V_22 , V_24 , false ) &&
F_12 ( V_22 , V_24 , true ) ) ;
F_13 ( V_22 , V_24 ) ;
return V_106 ;
}
static bool
F_15 ( T_2 V_5 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
int V_37 )
{
T_4 V_107 = F_3 ( V_5 , V_108 ) ;
T_1 V_97 = F_3 ( V_5 , V_39 ) ;
T_1 V_98 = F_3 ( V_5 , V_38 ) ;
if ( ( int ) V_107 < 0 )
V_24 -> V_71 = true ;
if ( V_97 != V_109 || V_98 != V_109 ) {
F_9 ( L_24 ,
V_24 -> V_37 ) ;
return false ;
}
return true ;
}
static bool
F_16 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
T_2 V_5 = V_24 -> V_36 [ V_24 -> V_37 ] ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_10 == V_51 ||
( V_12 == V_51 && V_6 != V_16 ) ) {
V_22 -> V_52 += 4 ;
if ( V_24 -> V_53 ) {
F_9 ( L_25
L_26 ) ;
return false ;
}
}
return true ;
}
static bool
F_17 ( struct V_23 * V_24 )
{
T_1 V_110 = 0 ;
bool V_111 = false ;
int V_37 ;
int V_112 = 0 ;
int V_113 = - 2 ;
for ( V_37 = 0 ; V_37 < V_24 -> V_114 ; V_37 ++ ) {
T_2 V_5 = V_24 -> V_36 [ V_37 ] ;
T_4 V_107 = F_3 ( V_5 , V_108 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
T_1 V_115 = V_37 + 4 ;
T_1 V_116 ;
if ( V_6 == V_117 ) {
V_112 = V_37 ;
V_111 = true ;
continue;
}
if ( V_6 != V_118 )
continue;
if ( V_37 - V_113 < 4 ) {
F_9 ( L_27 , V_37 ) ;
return false ;
}
V_113 = V_37 ;
if ( V_5 & V_119 ) {
F_9 ( L_28
L_29 ) ;
return false ;
}
if ( ! ( V_5 & V_120 ) ) {
F_9 ( L_30 ) ;
return false ;
}
if ( V_107 % sizeof( V_5 ) != 0 ) {
F_9 ( L_31 ) ;
return false ;
}
V_116 = V_115 + ( V_107 >> 3 ) ;
if ( V_116 >= V_24 -> V_114 ) {
F_9 ( L_32 ,
V_37 , V_116 ,
V_24 -> V_114 ) ;
return false ;
}
F_18 ( V_116 , V_24 -> V_121 ) ;
if ( V_115 >= V_24 -> V_114 ) {
F_9 ( L_33
L_34 ,
V_37 , V_115 , V_24 -> V_114 ) ;
return false ;
}
F_18 ( V_115 , V_24 -> V_121 ) ;
V_110 = F_19 ( V_110 , V_115 ) ;
if ( V_111 && V_37 == V_112 + 2 )
break;
}
if ( V_110 > V_112 ) {
F_9 ( L_35 ) ;
return false ;
}
return true ;
}
static void
F_20 ( struct V_23 * V_24 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
V_24 -> V_33 [ V_28 / 4 ] . V_34 [ V_28 % 4 ] = ~ 0 ;
for ( V_28 = 0 ; V_28 < V_122 ; V_28 ++ ) {
V_24 -> V_50 [ V_28 ] = ~ 0 ;
V_24 -> V_103 [ V_28 ] = false ;
V_24 -> V_70 [ V_28 ] = ~ 0 ;
}
}
static bool
F_21 ( struct V_23 * V_24 )
{
return ( V_24 -> V_43 [ 0 ] != 0 ||
V_24 -> V_43 [ 1 ] != 0 ) ;
}
static bool
F_22 ( struct V_23 * V_24 )
{
T_1 V_37 = V_24 -> V_37 ;
if ( ! F_23 ( V_37 , V_24 -> V_121 ) )
return true ;
if ( F_21 ( V_24 ) ) {
F_9 ( L_36 ) ;
return false ;
}
F_20 ( V_24 ) ;
V_24 -> V_53 = true ;
return true ;
}
struct V_21 *
F_24 ( struct V_123 * V_124 )
{
bool V_111 = false ;
int V_112 = 0 ;
T_1 V_37 ;
struct V_21 * V_22 = NULL ;
struct V_23 V_24 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_36 = V_124 -> V_125 ;
V_24 . V_114 = V_124 -> V_126 . V_127 / sizeof( T_2 ) ;
F_20 ( & V_24 ) ;
V_24 . V_121 =
F_25 ( F_26 ( V_24 . V_114 ) ,
sizeof( unsigned long ) , V_32 ) ;
if ( ! V_24 . V_121 )
goto V_128;
V_22 = F_25 ( 1 , sizeof( * V_22 ) , V_32 ) ;
if ( ! V_22 )
goto V_128;
if ( ! F_17 ( & V_24 ) )
goto V_128;
for ( V_37 = 0 ; V_37 < V_24 . V_114 ; V_37 ++ ) {
T_2 V_5 = V_24 . V_36 [ V_37 ] ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
V_24 . V_37 = V_37 ;
if ( ! F_22 ( & V_24 ) )
goto V_128;
switch ( V_6 ) {
case V_60 :
case V_129 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_117 :
case V_16 :
if ( ! F_14 ( V_22 ,
& V_24 ) ) {
F_9 ( L_37 , V_37 ) ;
goto V_128;
}
if ( ! F_16 ( V_22 ,
& V_24 ) )
goto V_128;
if ( V_6 == V_117 ) {
V_111 = true ;
V_112 = V_37 ;
}
break;
case V_78 :
if ( ! F_14 ( V_22 ,
& V_24 ) ) {
F_9 ( L_38 , V_37 ) ;
goto V_128;
}
break;
case V_118 :
if ( ! F_15 ( V_5 , V_22 ,
& V_24 , V_37 ) )
goto V_128;
break;
default:
F_9 ( L_39
L_40 , V_6 , V_37 ) ;
goto V_128;
}
if ( V_111 && V_37 == V_112 + 2 )
break;
}
if ( V_37 == V_24 . V_114 ) {
F_9 ( L_41
L_42 ,
V_124 -> V_126 . V_127 ) ;
goto V_128;
}
if ( V_24 . V_71 ) {
if ( ! F_10 ( V_22 ) )
goto V_128;
V_22 -> V_52 += 4 ;
}
V_22 -> V_130 =
( V_22 -> V_52 +
4 * V_22 -> V_27 ) ;
F_27 ( V_24 . V_121 ) ;
return V_22 ;
V_128:
F_27 ( V_24 . V_121 ) ;
if ( V_22 ) {
F_27 ( V_22 -> V_31 ) ;
F_27 ( V_22 ) ;
}
return NULL ;
}
