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
F_4 ( T_1 V_18 )
{
return ( V_18 >= 16 && V_18 < 32 ) ||
( V_18 >= 32 + 16 && V_18 < 32 + 32 ) ;
}
static bool
F_5 ( T_1 V_1 )
{
return ( V_1 == V_19 ||
V_1 == V_20 ) ;
}
static bool
F_6 ( T_1 V_1 )
{
return ( V_1 >= V_19 &&
V_1 <= V_21 ) ;
}
static bool
F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
int V_26 )
{
T_1 V_27 = V_23 -> V_28 ;
int V_29 ;
struct V_30 * V_31 ;
V_31 = F_8 ( V_23 -> V_32 ,
( V_27 + 1 ) * sizeof( * V_31 ) ,
V_33 ) ;
if ( ! V_31 )
return false ;
memcpy ( & V_31 [ V_27 ] ,
& V_25 -> V_34 [ V_26 ] ,
sizeof( * V_31 ) ) ;
V_23 -> V_28 = V_27 + 1 ;
V_23 -> V_32 = V_31 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ )
V_25 -> V_34 [ V_26 ] . V_35 [ V_29 ] = ~ 0 ;
return true ;
}
static bool
F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_36 )
{
T_2 V_5 = V_25 -> V_37 [ V_25 -> V_38 ] ;
T_1 V_1 = ( V_36 ?
F_3 ( V_5 , V_39 ) :
F_3 ( V_5 , V_40 ) ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
int V_26 = V_1 > V_41 ;
bool V_42 = F_5 ( V_1 ) ;
bool V_43 = V_42 && V_25 -> V_44 [ V_26 ] == 0 ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_43 ) {
T_1 V_45 = F_3 ( V_5 , V_46 ) ;
T_1 V_47 , V_48 ;
if ( V_6 == V_16 ) {
F_10 ( L_1 ) ;
return false ;
}
if ( V_36 ||
F_3 ( V_5 , V_49 ) != V_50 ) {
F_10 ( L_2 ) ;
return false ;
}
V_47 = F_2 ( V_5 ) ;
if ( V_47 == ~ 0 ) {
F_10 ( L_3 ) ;
return false ;
}
V_48 = V_25 -> V_51 [ V_47 ] ;
if ( V_48 == ~ 0 ) {
F_10 ( L_3 ) ;
return false ;
}
V_25 -> V_34 [ V_26 ] . V_35 [ 1 ] =
V_48 ;
if ( ! ( V_45 == V_14 && V_10 == V_52 ) &&
! ( V_45 == V_15 && V_12 == V_52 ) ) {
F_10 ( L_4 ) ;
return false ;
}
V_25 -> V_34 [ V_26 ] . V_43 = true ;
} else {
if ( V_10 == V_52 || ( V_6 != V_16 &&
V_12 == V_52 ) ) {
F_10 ( L_5
L_6 ) ;
return false ;
}
}
if ( V_25 -> V_44 [ V_26 ] >= 4 ) {
F_10 ( L_7 ,
V_26 ) ;
return false ;
}
V_25 -> V_34 [ V_26 ] . V_35 [ V_25 -> V_44 [ V_26 ] ] =
V_23 -> V_53 ;
V_25 -> V_44 [ V_26 ] ++ ;
if ( ! V_43 ) {
if ( V_25 -> V_54 ) {
F_10 ( L_8 ) ;
return false ;
}
V_23 -> V_53 += 4 ;
}
if ( V_42 ) {
if ( ! F_7 ( V_23 ,
V_25 , V_26 ) ) {
return false ;
}
V_25 -> V_44 [ V_26 ] = 0 ;
}
return true ;
}
static bool F_11 ( struct V_22 * V_23 )
{
T_1 V_55 = V_23 -> V_56 ;
T_1 V_57 = V_23 -> V_53 / 4 ;
V_23 -> V_58 =
F_8 ( V_23 -> V_58 ,
( V_55 + 1 ) *
sizeof( * V_23 -> V_58 ) ,
V_33 ) ;
if ( ! V_23 -> V_58 )
return false ;
V_23 -> V_58 [ V_55 ] = V_57 ;
V_23 -> V_56 ++ ;
return true ;
}
static bool
F_12 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_36 )
{
T_2 V_5 = V_25 -> V_37 [ V_25 -> V_38 ] ;
T_3 V_45 = F_3 ( V_5 , V_46 ) ;
T_3 V_10 = F_3 ( V_5 , V_11 ) ;
T_3 V_12 = F_3 ( V_5 , V_13 ) ;
T_3 V_59 = F_2 ( V_5 ) ;
T_3 V_60 = V_23 -> V_53 + 4 ;
switch ( F_3 ( V_5 , V_7 ) ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
break;
default:
F_10 ( L_9
L_10 ) ;
return false ;
}
if ( V_36 || F_3 ( V_5 , V_49 ) != V_50 ) {
F_10 ( L_11 ) ;
return false ;
}
if ( F_3 ( V_5 , V_66 ) != V_67 ) {
F_10 ( L_12 ) ;
return false ;
}
if ( F_3 ( V_5 , V_68 ) != V_69 &&
! ( V_5 & V_70 ) ) {
F_10 ( L_13 ) ;
return false ;
}
if ( V_59 == - 1 ) {
F_10 ( L_14
L_15 ) ;
return false ;
}
if ( V_25 -> V_71 [ V_59 ] != V_60 ) {
F_10 ( L_16 ,
V_25 -> V_71 [ V_59 ] ,
V_60 ) ;
return false ;
}
if ( ! ( V_45 == V_14 && V_10 == V_52 ) &&
! ( V_45 == V_15 && V_12 == V_52 ) ) {
F_10 ( L_17
L_18 ) ;
return false ;
}
V_25 -> V_54 = false ;
V_25 -> V_72 = false ;
return F_11 ( V_23 ) ;
}
static bool
F_13 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
bool V_36 )
{
T_2 V_5 = V_25 -> V_37 [ V_25 -> V_38 ] ;
T_1 V_1 = ( V_36 ?
F_3 ( V_5 , V_39 ) :
F_3 ( V_5 , V_40 ) ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
bool V_73 = V_5 & V_74 ;
bool V_2 = V_36 ^ V_73 ;
T_3 V_18 = F_1 ( V_1 , V_2 ) ;
if ( V_18 != - 1 ) {
T_1 V_75 = F_3 ( V_5 , V_66 ) ;
T_1 V_76 = F_3 ( V_5 , V_77 ) ;
if ( V_6 == V_78 &&
F_3 ( V_5 , V_68 ) == V_69 &&
( ( V_36 && V_76 == V_67 ) ||
( ! V_36 && V_75 == V_67 ) ) ) {
V_25 -> V_71 [ V_18 ] =
F_3 ( V_5 , V_79 ) ;
} else {
V_25 -> V_71 [ V_18 ] = ~ 0 ;
}
if ( F_4 ( V_18 ) )
V_25 -> V_80 = true ;
}
switch ( V_1 ) {
case V_81 :
if ( V_2 ) {
F_10 ( L_19
L_20 ) ;
return false ;
}
return F_12 ( V_23 ,
V_25 ,
V_36 ) ;
case V_82 :
case V_83 :
case V_84 :
return true ;
case V_19 :
case V_85 :
case V_86 :
case V_41 :
case V_20 :
case V_87 :
case V_88 :
case V_21 :
return F_9 ( V_23 , V_25 ,
V_36 ) ;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
F_10 ( L_21 , V_1 ) ;
return false ;
case V_93 :
F_10 ( L_22 ) ;
return false ;
case V_94 :
case V_95 :
return true ;
case V_96 :
return true ;
}
return true ;
}
static void
F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
T_2 V_5 = V_25 -> V_37 [ V_25 -> V_38 ] ;
T_1 V_97 = F_3 ( V_5 , V_49 ) ;
T_1 V_98 = F_3 ( V_5 , V_40 ) ;
T_1 V_99 = F_3 ( V_5 , V_39 ) ;
T_1 V_75 = F_3 ( V_5 , V_66 ) ;
T_1 V_8 = F_3 ( V_5 , V_9 ) ;
T_1 V_45 = F_3 ( V_5 , V_46 ) ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
bool V_73 = V_5 & V_74 ;
T_1 V_100 , V_101 , V_102 ;
bool V_103 ;
V_100 = F_2 ( V_5 ) ;
V_103 = ( V_100 != ~ 0 &&
V_25 -> V_104 [ V_100 ] ) ;
V_101 = F_1 ( V_98 , V_73 ) ;
V_102 = F_1 ( V_99 , ! V_73 ) ;
if ( V_102 != ~ 0 ) {
V_25 -> V_104 [ V_102 ] = false ;
V_25 -> V_51 [ V_102 ] = ~ 0 ;
}
if ( V_101 != ~ 0 ) {
V_25 -> V_104 [ V_101 ] = false ;
V_25 -> V_51 [ V_101 ] = ~ 0 ;
} else {
return;
}
if ( V_75 != V_67 )
return;
if ( V_97 == V_105 ) {
if ( V_6 != V_16 || V_12 != 0 ||
( V_8 != V_15 && V_45 != V_15 ) ) {
return;
}
V_25 -> V_104 [ V_101 ] = true ;
} else if ( V_97 == V_106 ) {
if ( ! V_103 )
return;
if ( ! ( V_45 == V_14 && V_10 == V_52 ) &&
! ( V_45 == V_15 && V_12 == V_52 &&
V_6 != V_16 ) ) {
return;
}
V_25 -> V_51 [ V_101 ] =
V_23 -> V_53 ;
}
}
static bool
F_15 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
T_2 V_5 = V_25 -> V_37 [ V_25 -> V_38 ] ;
T_1 V_98 = F_3 ( V_5 , V_40 ) ;
T_1 V_99 = F_3 ( V_5 , V_39 ) ;
bool V_107 ;
if ( F_6 ( V_98 ) && F_6 ( V_99 ) ) {
F_10 ( L_23 ) ;
return false ;
}
V_107 = ( F_13 ( V_23 , V_25 , false ) &&
F_13 ( V_23 , V_25 , true ) ) ;
F_14 ( V_23 , V_25 ) ;
return V_107 ;
}
static bool
F_16 ( T_2 V_5 ,
struct V_22 * V_23 ,
struct V_24 * V_25 ,
int V_38 )
{
T_4 V_108 = F_3 ( V_5 , V_109 ) ;
T_1 V_98 = F_3 ( V_5 , V_40 ) ;
T_1 V_99 = F_3 ( V_5 , V_39 ) ;
if ( ( int ) V_108 < 0 )
V_25 -> V_72 = true ;
if ( V_98 != V_110 || V_99 != V_110 ) {
F_10 ( L_24 ,
V_25 -> V_38 ) ;
return false ;
}
return true ;
}
static bool
F_17 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
T_2 V_5 = V_25 -> V_37 [ V_25 -> V_38 ] ;
T_1 V_10 = F_3 ( V_5 , V_11 ) ;
T_1 V_12 = F_3 ( V_5 , V_13 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
if ( V_10 == V_52 ||
( V_12 == V_52 && V_6 != V_16 ) ) {
V_23 -> V_53 += 4 ;
if ( V_25 -> V_54 ) {
F_10 ( L_25
L_26 ) ;
return false ;
}
}
if ( ( V_10 >= 16 && V_10 < 32 ) ||
( V_12 >= 16 && V_12 < 32 && V_6 != V_16 ) ) {
V_25 -> V_80 = true ;
}
return true ;
}
static bool
F_18 ( struct V_24 * V_25 )
{
T_1 V_111 = 0 ;
int V_38 ;
int V_112 = - 2 ;
for ( V_38 = 0 ; V_38 < V_25 -> V_113 ; V_38 ++ ) {
T_2 V_5 = V_25 -> V_37 [ V_38 ] ;
T_4 V_108 = F_3 ( V_5 , V_109 ) ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
T_1 V_114 = V_38 + 4 ;
T_1 V_115 ;
if ( V_6 == V_116 ) {
V_25 -> V_113 = V_38 + 3 ;
continue;
}
if ( V_6 != V_117 )
continue;
if ( V_38 - V_112 < 4 ) {
F_10 ( L_27 , V_38 ) ;
return false ;
}
V_112 = V_38 ;
if ( V_5 & V_118 ) {
F_10 ( L_28
L_29 ) ;
return false ;
}
if ( ! ( V_5 & V_119 ) ) {
F_10 ( L_30 ) ;
return false ;
}
if ( V_108 % sizeof( V_5 ) != 0 ) {
F_10 ( L_31 ) ;
return false ;
}
V_115 = V_114 + ( V_108 >> 3 ) ;
if ( V_115 >= V_25 -> V_113 ) {
F_10 ( L_32 ,
V_38 , V_115 ,
V_25 -> V_113 ) ;
return false ;
}
F_19 ( V_115 , V_25 -> V_120 ) ;
if ( V_114 >= V_25 -> V_113 ) {
F_10 ( L_33
L_34 ,
V_38 , V_114 , V_25 -> V_113 ) ;
return false ;
}
F_19 ( V_114 , V_25 -> V_120 ) ;
V_111 = F_20 ( V_111 , V_114 ) ;
}
if ( V_111 > V_25 -> V_113 - 3 ) {
F_10 ( L_35 ) ;
return false ;
}
return true ;
}
static void
F_21 ( struct V_24 * V_25 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
V_25 -> V_34 [ V_29 / 4 ] . V_35 [ V_29 % 4 ] = ~ 0 ;
for ( V_29 = 0 ; V_29 < V_121 ; V_29 ++ ) {
V_25 -> V_51 [ V_29 ] = ~ 0 ;
V_25 -> V_104 [ V_29 ] = false ;
V_25 -> V_71 [ V_29 ] = ~ 0 ;
}
}
static bool
F_22 ( struct V_24 * V_25 )
{
return ( V_25 -> V_44 [ 0 ] != 0 ||
V_25 -> V_44 [ 1 ] != 0 ) ;
}
static bool
F_23 ( struct V_24 * V_25 )
{
T_1 V_38 = V_25 -> V_38 ;
if ( ! F_24 ( V_38 , V_25 -> V_120 ) )
return true ;
if ( F_22 ( V_25 ) ) {
F_10 ( L_36 ) ;
return false ;
}
F_21 ( V_25 ) ;
V_25 -> V_54 = true ;
return true ;
}
struct V_22 *
F_25 ( struct V_122 * V_123 )
{
bool V_124 = false ;
int V_125 = 0 ;
T_1 V_126 = - 3 ;
T_1 V_38 ;
struct V_22 * V_23 = NULL ;
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_37 = V_123 -> V_127 ;
V_25 . V_113 = V_123 -> V_128 . V_129 / sizeof( T_2 ) ;
F_21 ( & V_25 ) ;
V_25 . V_120 =
F_26 ( F_27 ( V_25 . V_113 ) ,
sizeof( unsigned long ) , V_33 ) ;
if ( ! V_25 . V_120 )
goto V_130;
V_23 = F_26 ( 1 , sizeof( * V_23 ) , V_33 ) ;
if ( ! V_23 )
goto V_130;
if ( ! F_18 ( & V_25 ) )
goto V_130;
for ( V_38 = 0 ; V_38 < V_25 . V_113 ; V_38 ++ ) {
T_2 V_5 = V_25 . V_37 [ V_38 ] ;
T_1 V_6 = F_3 ( V_5 , V_7 ) ;
V_25 . V_38 = V_38 ;
if ( ! F_23 ( & V_25 ) )
goto V_130;
if ( V_38 == V_126 + 3 ) {
int V_29 ;
for ( V_29 = 64 ; V_29 < V_121 ; V_29 ++ ) {
V_25 . V_51 [ V_29 ] = ~ 0 ;
V_25 . V_104 [ V_29 ] = false ;
V_25 . V_71 [ V_29 ] = ~ 0 ;
}
}
switch ( V_6 ) {
case V_61 :
case V_131 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_116 :
case V_16 :
case V_132 :
case V_133 :
if ( ! F_15 ( V_23 ,
& V_25 ) ) {
F_10 ( L_37 , V_38 ) ;
goto V_130;
}
if ( ! F_17 ( V_23 ,
& V_25 ) )
goto V_130;
if ( V_6 == V_116 ) {
V_124 = true ;
V_125 = V_38 ;
}
if ( V_6 == V_132 ||
V_6 == V_133 ) {
V_23 -> V_134 = true ;
if ( V_38 < V_126 + 3 ) {
F_10 ( L_38
L_39 , V_38 ) ;
goto V_130;
}
V_126 = V_38 ;
}
break;
case V_78 :
if ( ! F_15 ( V_23 ,
& V_25 ) ) {
F_10 ( L_40 , V_38 ) ;
goto V_130;
}
break;
case V_117 :
if ( ! F_16 ( V_5 , V_23 ,
& V_25 , V_38 ) )
goto V_130;
if ( V_38 < V_126 + 3 ) {
F_10 ( L_41 ,
V_38 ) ;
goto V_130;
}
break;
default:
F_10 ( L_42
L_43 , V_6 , V_38 ) ;
goto V_130;
}
if ( V_124 && V_38 == V_125 + 2 )
break;
}
if ( V_38 == V_25 . V_113 ) {
F_10 ( L_44
L_45 ,
V_123 -> V_128 . V_129 ) ;
goto V_130;
}
if ( V_23 -> V_134 &&
V_25 . V_80 ) {
F_10 ( L_46
L_47 ) ;
goto V_130;
}
if ( V_25 . V_72 ) {
if ( ! F_11 ( V_23 ) )
goto V_130;
V_23 -> V_53 += 4 ;
}
V_23 -> V_135 =
( V_23 -> V_53 +
4 * V_23 -> V_28 ) ;
F_28 ( V_25 . V_120 ) ;
return V_23 ;
V_130:
F_28 ( V_25 . V_120 ) ;
if ( V_23 ) {
F_28 ( V_23 -> V_32 ) ;
F_28 ( V_23 ) ;
}
return NULL ;
}
