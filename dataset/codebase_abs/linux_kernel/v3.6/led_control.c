static T_1 F_1 ( T_2 * V_1 , T_3 V_2 )
{
T_1 V_3 = 0 ;
while ( V_2 -- ) {
V_3 += ( T_2 ) ~ ( * V_1 ) ;
V_1 ++ ;
}
return V_3 ;
}
BOOLEAN F_2 ( struct V_4 * V_5 , T_4 V_6 )
{
INT V_7 ;
V_7 = ( V_5 -> V_8 & V_6 ) ^ V_6 ;
if ( V_7 )
return FALSE ;
else
return TRUE ;
}
static INT F_3 ( struct V_4 * V_5 , T_4 V_9 , T_5 V_10 ,
T_6 V_11 , INT V_12 , T_7 V_13 )
{
int V_7 = V_14 ;
BOOLEAN V_15 = FALSE ;
if ( V_12 < 0 ) {
V_15 = TRUE ;
V_12 = 1 ;
}
while ( V_12 ) {
if ( V_13 == V_5 -> V_16 )
F_4 ( V_9 , V_10 ) ;
V_7 = F_5 (
V_5 -> V_17 . V_18 ,
V_13 != V_5 -> V_16 ||
F_6 () ,
F_7 ( V_11 ) ) ;
if ( F_6 () ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_1 ) ;
V_5 -> V_17 . V_22 =
V_23 ;
F_9 ( V_9 , V_10 ) ;
V_7 = V_24 ;
break;
}
if ( V_7 ) {
F_9 ( V_9 , V_10 ) ;
V_7 = V_24 ;
break;
}
F_9 ( V_9 , V_10 ) ;
V_7 = F_5 (
V_5 -> V_17 . V_18 ,
V_13 != V_5 -> V_16 ||
F_6 () ,
F_7 ( V_11 ) ) ;
if ( V_15 == FALSE )
V_12 -- ;
}
return V_7 ;
}
static INT F_10 ( T_6 V_25 )
{
if ( V_25 <= 3 )
return V_25 ;
else if ( ( V_25 > 3 ) && ( V_25 <= 100 ) )
return 5 ;
else if ( ( V_25 > 100 ) && ( V_25 <= 200 ) )
return 6 ;
else if ( ( V_25 > 200 ) && ( V_25 <= 300 ) )
return 7 ;
else if ( ( V_25 > 300 ) && ( V_25 <= 400 ) )
return 8 ;
else if ( ( V_25 > 400 ) && ( V_25 <= 500 ) )
return 9 ;
else if ( ( V_25 > 500 ) && ( V_25 <= 600 ) )
return 10 ;
else
return V_26 ;
}
static INT F_11 ( struct V_4 * V_5 , T_5 V_27 ,
T_5 V_28 , T_5 V_29 , T_5 V_30 ,
T_7 V_13 )
{
T_8 V_31 = 0 , V_32 = 0 ;
T_8 V_33 = 0 , V_34 = 0 ;
T_8 V_35 = 0 , V_36 = 0 ;
int V_7 = V_14 ;
INT V_12 = 0 , V_37 = 0 , V_38 = 0 ;
T_4 V_39 = 0 ;
BOOLEAN V_40 = TRUE ;
T_9 V_11 = 0 ;
V_31 = V_5 -> V_41 -> V_42 . V_43 ;
V_32 = V_5 -> V_41 -> V_42 . V_44 ;
V_37 = F_10 ( ( T_6 ) V_35 ) ;
V_38 = F_10 ( ( T_6 ) V_36 ) ;
while ( ( V_5 -> V_45 == FALSE ) ) {
V_11 = 50 ;
if ( V_40 ) {
if ( V_37 > V_38 )
V_12 = V_38 ;
else
V_12 = V_37 ;
if ( V_12 > 0 ) {
if ( F_3 ( V_5 , 1 << V_27 ,
V_28 , V_11 ,
V_12 , V_13 )
== V_24 )
return V_24 ;
if ( F_3 ( V_5 , 1 << V_29 ,
V_30 , V_11 ,
V_12 , V_13 )
== V_24 )
return V_24 ;
}
if ( V_12 == V_37 ) {
if ( F_3 ( V_5 , ( 1 << V_29 ) ,
V_30 , V_11 ,
V_38 - V_12 ,
V_13 )
== V_24 )
return V_24 ;
V_12 = V_38 ;
} else {
if ( F_3 ( V_5 , 1 << V_27 ,
V_28 , V_11 ,
V_37 - V_12 ,
V_13 )
== V_24 )
return V_24 ;
V_12 = V_37 ;
}
} else {
if ( V_12 == V_37 ) {
if ( F_3 ( V_5 , 1 << V_27 ,
V_28 , V_11 ,
V_12 , V_13 )
== V_24 )
return V_24 ;
} else {
if ( F_3 ( V_5 , 1 << V_29 ,
V_30 , V_11 ,
V_12 , V_13 )
== V_24 )
return V_24 ;
}
}
V_39 = V_26 - V_12 ;
if ( V_39 > 0 ) {
V_11 = 100 * V_39 ;
V_7 = F_5 (
V_5 -> V_17 . V_18 ,
V_13 != V_5 -> V_16
|| F_6 () ,
F_7 ( V_11 ) ) ;
if ( F_6 () ) {
F_8 ( V_5 , V_19 ,
V_20 , V_21 ,
L_1 ) ;
V_5 -> V_17 . V_22 =
V_23 ;
return V_24 ;
}
if ( V_7 )
return V_24 ;
}
F_9 ( 1 << V_27 , V_28 ) ;
F_9 ( 1 << V_29 , V_28 ) ;
V_33 = V_5 -> V_41 -> V_42 . V_43 ;
V_34 = V_5 -> V_41 -> V_42 . V_44 ;
V_35 = V_33 -
V_31 ;
V_36 = V_34 -
V_32 ;
V_31 = V_33 ;
V_32 = V_34 ;
V_37 =
F_10 ( ( T_6 ) V_35 ) ;
V_38 =
F_10 ( ( T_6 ) V_36 ) ;
}
return V_7 ;
}
static INT F_12 ( struct V_4 * V_5 , T_6 V_46 ,
T_10 V_47 )
{
INT V_7 = V_14 ;
T_11 V_48 = NULL ;
T_10 V_49 = 0 ;
T_10 V_50 = 0 ;
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_2 ,
V_46 , V_47 ) ;
V_48 = F_13 ( V_47 , V_51 ) ;
if ( ! V_48 ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_3 ) ;
return - V_52 ;
}
if ( V_14 != F_14 ( V_5 , ( V_53 ) V_48 ,
V_46 , V_47 ) ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_4 ) ;
V_7 = V_54 ;
goto exit;
}
V_50 = F_1 ( V_48 , V_47 ) ;
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_5 ,
V_50 ) ;
if ( V_14 != F_14 ( V_5 , ( V_53 ) & V_49 ,
V_46 + V_47 , 2 ) ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_4 ) ;
V_7 = V_54 ;
goto exit;
}
V_49 = F_15 ( V_49 ) ;
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_6 , V_49 ) ;
if ( V_50 ^ V_49 ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_7 ) ;
V_7 = V_54 ;
goto exit;
}
exit:
F_16 ( V_48 ) ;
return V_7 ;
}
static INT F_17 ( struct V_4 * V_5 , T_6 V_55 )
{
INT V_7 = V_14 ;
T_10 V_56 = 0 ;
V_55 += V_57 ;
F_14 ( V_5 , ( V_53 ) & V_56 , V_55 , 2 ) ;
V_56 = F_15 ( V_56 ) ;
if ( 0 == V_56 || V_56 > V_5 -> V_58 )
return V_54 ;
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_8 , V_56 ) ;
V_7 = F_12 ( V_5 , V_55 ,
V_56 ) ;
return V_7 ;
}
static int F_18 ( struct V_4 * V_5 ,
T_5 V_59 [] )
{
int V_7 = V_14 ;
T_6 V_60 = 0 ;
T_10 V_61 = 0 ;
T_10 V_62 = 0 ;
T_5 V_63 = 0 ;
T_5 V_64 [ 32 ] = { 0 } ;
F_14 ( V_5 , ( V_53 ) & V_62 ,
V_65 , 2 ) ;
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_9 ,
V_62 & 0xFF , ( ( V_62 >> 8 ) & 0xFF ) ) ;
if ( ( ( V_62 >> 8 ) & 0xFF ) < V_66 ) {
F_14 ( V_5 , ( V_53 ) & V_61 ,
V_67 , 2 ) ;
V_61 = F_15 ( V_61 ) ;
V_60 = V_61 ;
} else {
V_7 = F_12 ( V_5 ,
V_57 ,
V_68 ) ;
if ( V_7 != V_14 )
return V_7 ;
F_14 ( V_5 , ( V_53 ) & V_60 ,
V_69 , 4 ) ;
V_60 = F_19 ( V_60 ) ;
}
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_10 ,
V_60 ) ;
if ( V_60 < V_57 ||
V_60 > ( V_5 -> V_58 - V_57 ) )
return V_54 ;
V_7 = F_17 ( V_5 , V_60 ) ;
if ( V_7 )
return V_7 ;
V_60 +=
V_57 ;
V_60 += V_70 ;
F_14 ( V_5 , ( T_4 * ) V_64 , V_60 , 32 ) ;
for ( V_63 = 0 ; V_63 < 32 ; V_63 ++ ) {
switch ( V_64 [ V_63 ] ) {
case V_71 :
V_59 [ V_71 ] = V_63 ;
V_5 -> V_8 |= ( 1 << V_63 ) ;
break;
case V_72 :
V_59 [ V_72 ] = V_63 ;
V_5 -> V_8 |= ( 1 << V_63 ) ;
break;
case V_73 :
V_59 [ V_73 ] = V_63 ;
V_5 -> V_8 |= ( 1 << V_63 ) ;
break;
case V_74 :
V_59 [ V_74 ] = V_63 ;
V_5 -> V_8 |= ( 1 << V_63 ) ;
break;
default:
break;
}
}
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_11 , V_5 -> V_8 ) ;
return V_7 ;
}
static int F_20 ( struct V_4 * V_5 ,
BOOLEAN * V_75 )
{
int V_7 = V_14 ;
T_5 V_59 [ V_76 + 1 ] ;
T_4 V_77 = 0 ;
T_4 V_78 = 0 ;
T_11 V_79 = NULL ;
T_5 V_80 = 0 ;
memset ( V_59 , V_81 , V_76 + 1 ) ;
if ( ! V_5 -> V_82 || F_21 ( V_5 -> V_82 ) ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 , L_12 ) ;
return - V_83 ;
}
V_7 = F_18 ( V_5 , V_59 ) ;
if ( V_7 == V_54 ) {
* V_75 = FALSE ;
return V_14 ;
} else if ( V_7 ) {
* V_75 = FALSE ;
return V_7 ;
}
F_8 ( V_5 , V_19 , V_20 , V_21 ,
L_13 ) ;
V_79 = ( T_11 ) & V_5 -> V_82 -> V_84 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_80 = * V_79 ;
if ( V_80 & 0x80 ) {
V_5 -> V_17 . V_85 [ V_77 ] . V_86 = 0 ;
V_80 = V_80 & 0x7f ;
}
V_5 -> V_17 . V_85 [ V_77 ] . V_87 = V_80 ;
if ( V_80 <= V_76 )
V_5 -> V_17 . V_85 [ V_77 ] . V_9 =
V_59 [ V_80 ] ;
else
V_5 -> V_17 . V_85 [ V_77 ] . V_9 =
V_81 ;
V_79 ++ ;
V_80 = * V_79 ;
V_5 -> V_17 . V_85 [ V_77 ] . V_88 = V_80 ;
V_79 ++ ;
V_80 = * V_79 ;
V_5 -> V_17 . V_85 [ V_77 ] . V_89 = V_80 ;
V_79 ++ ;
}
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( ( V_5 -> V_17 . V_85 [ V_77 ] . V_87 == V_81 ) ||
( V_5 -> V_17 . V_85 [ V_77 ] . V_87 == 0x7f ) ||
( V_5 -> V_17 . V_85 [ V_77 ] . V_87 == 0 ) )
V_78 ++ ;
}
if ( V_78 >= V_76 )
* V_75 = FALSE ;
return V_7 ;
}
static VOID F_22 ( struct V_4 * V_5 )
{
T_4 V_90 = 0 ;
T_4 V_77 = 0 ;
if ( F_23 ( V_5 , V_91 , & V_90 ,
sizeof( V_90 ) ) < 0 )
F_8 ( V_5 , V_19 , V_20 ,
V_21 , L_14 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_9 !=
V_81 )
V_90 |= ( 1 << V_5 -> V_17 . V_85 [ V_77 ] . V_9 ) ;
F_9 ( 1 << V_5 -> V_17 . V_85 [ V_77 ] . V_9 ,
V_77 ) ;
}
if ( F_24 ( V_5 , V_91 , & V_90 ,
sizeof( V_90 ) ) < 0 )
F_8 ( V_5 , V_19 , V_20 ,
V_21 , L_15 ) ;
V_5 -> V_17 . V_92 = FALSE ;
}
static INT F_25 ( struct V_4 * V_5 , T_5 * V_93 ,
T_5 * V_94 , T_5 * V_95 , T_5 * V_96 ,
T_7 V_13 )
{
T_4 V_77 = 0 ;
* V_93 = V_81 ;
* V_94 = V_81 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( ( V_13 == V_97 ) ||
( V_13 == V_98 ) ||
( V_13 == V_99 ) ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_89 &
V_13 ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_9
!= V_81 ) {
if ( * V_93 == V_81 ) {
* V_93 = V_5 -> V_17 . V_85 [ V_77 ] . V_9 ;
* V_95 = V_77 ;
} else {
* V_94 = V_5 -> V_17 . V_85 [ V_77 ] . V_9 ;
* V_96 = V_77 ;
}
}
}
} else {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_88
& V_13 ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_9
!= V_81 ) {
* V_93 = V_5 -> V_17 . V_85 [ V_77 ] . V_9 ;
* V_95 = V_77 ;
}
}
}
}
return V_14 ;
}
static VOID F_26 ( struct V_4 * V_5 )
{
T_4 V_77 = 0 ;
T_5 V_100 = 0 ;
T_5 V_10 = 0 ;
T_4 V_90 = 0 ;
T_7 V_13 = 0 ;
T_9 V_11 = 0 ;
INT V_7 = 0 ;
T_5 V_101 = 0 ;
T_5 V_102 = 0 ;
V_5 -> V_17 . V_103 = FALSE ;
V_100 = V_81 ;
while ( TRUE ) {
if ( ( V_100 == V_81 )
||
( ( V_13 != V_99 ) &&
( V_13 != V_97 ) &&
( V_13 != V_104 ) )
||
( V_13 == V_105 ) )
V_7 = F_27 (
V_5 -> V_17 . V_18 ,
V_13 != V_5 -> V_16
|| F_6 () ) ;
if ( F_6 () || V_5 -> V_45 ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_1 ) ;
V_5 -> V_17 . V_22 =
V_23 ;
F_9 ( 1 << V_100 , V_10 ) ;
return;
}
if ( V_100 != V_81 )
F_9 ( 1 << V_100 , V_10 ) ;
if ( V_5 -> V_17 . V_106 == FALSE ) {
F_22 ( V_5 ) ;
V_5 -> V_17 . V_106 = TRUE ;
}
switch ( V_5 -> V_16 ) {
case V_107 :
V_13 = V_107 ;
F_25 ( V_5 , & V_100 , & V_101 ,
& V_10 , & V_102 , V_13 ) ;
if ( V_100 != V_81 )
F_4 ( 1 << V_100 , V_10 ) ;
break;
case V_99 :
V_13 = V_99 ;
F_25 ( V_5 , & V_100 , & V_101 ,
& V_10 , & V_102 , V_13 ) ;
if ( V_100 != V_81 ) {
V_11 = 50 ;
F_3 ( V_5 , 1 << V_100 , V_10 ,
V_11 , - 1 , V_13 ) ;
}
break;
case V_108 :
V_13 = V_108 ;
F_25 ( V_5 , & V_100 , & V_101 ,
& V_10 , & V_102 , V_13 ) ;
if ( V_100 != V_81 )
F_4 ( 1 << V_100 , V_10 ) ;
break;
case V_109 :
case V_110 :
V_13 = V_110 ;
F_25 ( V_5 , & V_100 , & V_101 ,
& V_10 , & V_101 , V_13 ) ;
if ( V_100 != V_81 )
F_4 ( 1 << V_100 , V_10 ) ;
break;
case V_97 :
{
T_5 V_93 = V_81 ;
T_5 V_94 = V_81 ;
T_5 V_111 = 0 ;
T_5 V_112 = 0 ;
V_13 = V_97 ;
V_5 -> V_17 . V_92 = FALSE ;
F_25 ( V_5 , & V_93 ,
& V_94 , & V_111 , & V_112 ,
V_13 ) ;
if ( ( V_93 == V_81 ) &&
( V_94 ==
V_81 ) ) {
V_100 = V_81 ;
} else {
if ( V_93 == V_81 ) {
V_93 = V_94 ;
V_111 = V_112 ;
} else if ( V_94 ==
V_81 ) {
V_94 = V_93 ;
V_112 = V_111 ;
}
F_11 ( V_5 ,
V_93 , V_111 ,
V_94 , V_112 ,
V_13 ) ;
}
}
break;
case V_104 :
V_13 = V_104 ;
if ( V_113 ==
V_5 -> V_114 ) {
V_90 = 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_9 != V_81 )
F_9 ( ( 1 << V_5 -> V_17 . V_85 [ V_77 ] . V_9 ) , V_77 ) ;
}
}
V_5 -> V_17 . V_106 = FALSE ;
V_5 -> V_17 . V_92 = TRUE ;
F_28 ( & V_5 -> V_17 . V_115 ) ;
V_100 = V_81 ;
break;
case V_116 :
V_13 = V_116 ;
V_100 = V_81 ;
break;
case V_98 :
break;
case V_117 :
V_13 = V_117 ;
V_100 = V_81 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_9
!= V_81 )
F_9 ( ( 1 << V_5 -> V_17 . V_85 [ V_77 ] . V_9 ) , V_77 ) ;
}
break;
case V_105 :
F_8 ( V_5 , V_19 , V_20 ,
V_21 , L_16 ) ;
V_13 = V_105 ;
V_5 -> V_17 . V_22 =
V_118 ;
V_5 -> V_17 . V_106 = FALSE ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
if ( V_5 -> V_17 . V_85 [ V_77 ] . V_9
!= V_81 )
F_9 ( ( 1 << V_5 -> V_17 . V_85 [ V_77 ] . V_9 ) , V_77 ) ;
}
break;
case V_119 :
F_8 ( V_5 , V_19 , V_20 ,
V_21 , L_17 ) ;
if ( V_5 -> V_120 == FALSE )
V_5 -> V_16 = V_110 ;
else
V_5 -> V_16 = V_97 ;
V_5 -> V_17 . V_22 =
V_121 ;
break;
default:
break;
}
}
V_5 -> V_17 . V_22 = V_23 ;
}
int F_29 ( struct V_4 * V_5 )
{
int V_7 = V_14 ;
BOOLEAN V_75 = TRUE ;
T_5 V_77 = 0 ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
V_5 -> V_17 . V_85 [ V_77 ] . V_86 = 1 ;
V_7 = F_20 ( V_5 , & V_75 ) ;
if ( V_14 != V_7 ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_18 ) ;
return V_7 ;
}
if ( V_5 -> V_17 . V_22 ) {
if ( V_75 ) {
;
} else {
V_5 -> V_16 = V_117 ;
F_28 ( & V_5 -> V_17 . V_18 ) ;
V_5 -> V_17 . V_22 =
V_23 ;
}
} else if ( V_75 ) {
F_30 ( & V_5 -> V_17 . V_18 ) ;
F_30 ( & V_5 -> V_17 . V_115 ) ;
V_5 -> V_17 . V_22 =
V_121 ;
V_5 -> V_17 . V_92 = FALSE ;
V_5 -> V_17 . V_122 =
F_31 ( ( int ( * ) ( void * ) ) F_26 ,
V_5 , L_19 ) ;
if ( F_21 ( V_5 -> V_17 . V_122 ) ) {
F_8 ( V_5 , V_19 , V_20 ,
V_21 ,
L_20 ) ;
V_5 -> V_17 . V_22 =
V_23 ;
return F_32 ( V_5 -> V_17 . V_122 ) ;
}
}
return V_7 ;
}
