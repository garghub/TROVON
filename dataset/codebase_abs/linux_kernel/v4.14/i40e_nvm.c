T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 = 0 ;
T_2 V_6 , V_7 ;
T_3 V_8 ;
V_7 = F_2 ( V_2 , V_9 ) ;
V_8 = ( ( V_7 & V_10 ) >>
V_11 ) ;
V_4 -> V_8 = F_3 ( V_8 ) * V_12 ;
V_6 = F_2 ( V_2 , V_13 ) ;
if ( V_6 & V_14 ) {
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = false ;
} else {
V_4 -> V_17 = true ;
V_5 = V_18 ;
F_4 ( V_2 , V_19 , L_1 ) ;
}
return V_5 ;
}
T_1 F_5 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
T_1 V_5 = 0 ;
T_4 V_22 , V_15 ;
T_4 V_23 = 0 ;
if ( V_2 -> V_4 . V_17 )
goto V_24;
V_5 = F_6 ( V_2 , V_25 , V_21 ,
0 , & V_23 , NULL ) ;
V_22 = F_2 ( V_2 , V_26 ) ;
V_2 -> V_4 . V_27 = F_7 ( V_23 ) + V_22 ;
if ( V_5 )
F_4 ( V_2 , V_19 ,
L_2 ,
V_21 , V_23 , V_5 , V_2 -> V_28 . V_29 ) ;
if ( V_5 && V_23 ) {
V_15 = F_7 ( V_16 ) + V_22 ;
while ( ( V_22 < V_15 ) && V_23 ) {
F_8 ( 10000 , 20000 ) ;
V_22 = F_2 ( V_2 , V_26 ) ;
V_5 = F_6 ( V_2 ,
V_25 ,
V_21 , 0 , & V_23 ,
NULL ) ;
if ( ! V_5 ) {
V_2 -> V_4 . V_27 =
F_7 ( V_23 ) + V_22 ;
break;
}
}
if ( V_5 ) {
V_2 -> V_4 . V_27 = 0 ;
F_4 ( V_2 , V_19 ,
L_3 ,
V_23 , V_5 , V_2 -> V_28 . V_29 ) ;
}
}
V_24:
return V_5 ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_5 = V_30 ;
T_2 V_31 = 0 ;
if ( V_2 -> V_4 . V_17 )
return;
V_5 = F_10 ( V_2 , V_25 , 0 , NULL ) ;
while ( ( V_5 == V_32 ) &&
( V_31 < V_2 -> V_28 . V_33 ) ) {
F_8 ( 1000 , 2000 ) ;
V_5 = F_10 ( V_2 ,
V_25 ,
0 , NULL ) ;
V_31 ++ ;
}
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_5 = V_34 ;
T_2 V_35 , V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_35 = F_2 ( V_2 , V_38 ) ;
if ( V_35 & V_39 ) {
V_5 = 0 ;
break;
}
F_12 ( 5 ) ;
}
if ( V_5 == V_34 )
F_4 ( V_2 , V_19 , L_4 ) ;
return V_5 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_5 V_40 ,
T_5 * V_41 )
{
T_1 V_5 = V_34 ;
T_2 V_42 ;
if ( V_40 >= V_2 -> V_4 . V_8 ) {
F_4 ( V_2 , V_19 ,
L_5 ,
V_40 , V_2 -> V_4 . V_8 ) ;
V_5 = V_43 ;
goto V_44;
}
V_5 = F_11 ( V_2 ) ;
if ( ! V_5 ) {
V_42 = ( ( T_2 ) V_40 << V_45 ) |
F_3 ( V_46 ) ;
F_14 ( V_2 , V_38 , V_42 ) ;
V_5 = F_11 ( V_2 ) ;
if ( ! V_5 ) {
V_42 = F_2 ( V_2 , V_47 ) ;
* V_41 = ( T_5 ) ( ( V_42 &
V_48 )
>> V_49 ) ;
}
}
if ( V_5 )
F_4 ( V_2 , V_19 ,
L_6 ,
V_40 ) ;
V_44:
return V_5 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_50 ,
T_2 V_40 , T_5 V_51 , void * V_41 ,
bool V_52 )
{
T_1 V_5 = V_53 ;
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = & V_2 -> V_57 ;
if ( ( V_40 + V_51 ) > V_2 -> V_4 . V_8 )
F_4 ( V_2 , V_19 ,
L_7 ,
( V_40 + V_51 ) , V_2 -> V_4 . V_8 ) ;
else if ( V_51 > V_58 )
F_4 ( V_2 , V_19 ,
L_8 ,
V_51 , V_58 ) ;
else if ( ( ( V_40 + ( V_51 - 1 ) ) / V_58 )
!= ( V_40 / V_58 ) )
F_4 ( V_2 , V_19 ,
L_9 ,
V_40 , V_51 ) ;
else
V_5 = F_16 ( V_2 , V_50 ,
2 * V_40 ,
2 * V_51 ,
V_41 , V_52 , & V_55 ) ;
return V_5 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_5 V_40 ,
T_5 * V_41 )
{
T_1 V_5 = V_34 ;
V_5 = F_15 ( V_2 , 0x0 , V_40 , 1 , V_41 , true ) ;
* V_41 = F_18 ( * ( V_59 * ) V_41 ) ;
return V_5 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
T_5 V_40 , T_5 * V_41 )
{
T_1 V_5 = 0 ;
if ( V_2 -> V_60 & V_61 )
V_5 = F_17 ( V_2 , V_40 , V_41 ) ;
else
V_5 = F_13 ( V_2 , V_40 , V_41 ) ;
return V_5 ;
}
T_1 F_20 ( struct V_1 * V_2 , T_5 V_40 ,
T_5 * V_41 )
{
T_1 V_5 = 0 ;
V_5 = F_5 ( V_2 , V_62 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_19 ( V_2 , V_40 , V_41 ) ;
F_9 ( V_2 ) ;
return V_5 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_5 V_40 ,
T_5 * V_51 , T_5 * V_41 )
{
T_1 V_5 = 0 ;
T_5 V_63 , V_64 ;
for ( V_64 = 0 ; V_64 < * V_51 ; V_64 ++ ) {
V_63 = V_40 + V_64 ;
V_5 = F_13 ( V_2 , V_63 , & V_41 [ V_64 ] ) ;
if ( V_5 )
break;
}
* V_51 = V_64 ;
return V_5 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_5 V_40 ,
T_5 * V_51 , T_5 * V_41 )
{
T_1 V_5 ;
T_5 V_65 = * V_51 ;
bool V_66 = false ;
T_5 V_67 = 0 ;
T_5 V_68 = 0 ;
do {
if ( V_40 % V_58 )
V_65 = F_23 ( * V_51 ,
( T_5 ) ( V_58 -
( V_40 % V_58 ) ) ) ;
else
V_65 = F_23 ( ( * V_51 - V_67 ) ,
V_58 ) ;
if ( ( V_67 + V_65 ) >= * V_51 )
V_66 = true ;
V_5 = F_15 ( V_2 , 0x0 , V_40 , V_65 ,
V_41 + V_67 , V_66 ) ;
if ( V_5 )
goto V_69;
V_67 += V_65 ;
V_40 += V_65 ;
} while ( V_67 < * V_51 );
for ( V_68 = 0 ; V_68 < * V_51 ; V_68 ++ )
V_41 [ V_68 ] = F_18 ( ( ( V_59 * ) V_41 ) [ V_68 ] ) ;
V_69:
* V_51 = V_67 ;
return V_5 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
T_5 V_40 , T_5 * V_51 ,
T_5 * V_41 )
{
T_1 V_5 = 0 ;
if ( V_2 -> V_60 & V_61 )
V_5 = F_22 ( V_2 , V_40 , V_51 , V_41 ) ;
else
V_5 = F_21 ( V_2 , V_40 , V_51 , V_41 ) ;
return V_5 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_3 V_50 ,
T_2 V_40 , T_5 V_51 , void * V_41 ,
bool V_52 )
{
T_1 V_5 = V_53 ;
struct V_54 V_55 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = & V_2 -> V_57 ;
if ( ( V_40 + V_51 ) > V_2 -> V_4 . V_8 )
F_4 ( V_2 , V_19 ,
L_7 ,
( V_40 + V_51 ) , V_2 -> V_4 . V_8 ) ;
else if ( V_51 > V_58 )
F_4 ( V_2 , V_19 ,
L_8 ,
V_51 , V_58 ) ;
else if ( ( ( V_40 + ( V_51 - 1 ) ) / V_58 )
!= ( V_40 / V_58 ) )
F_4 ( V_2 , V_19 ,
L_9 ,
V_40 , V_51 ) ;
else
V_5 = F_26 ( V_2 , V_50 ,
2 * V_40 ,
2 * V_51 ,
V_41 , V_52 , & V_55 ) ;
return V_5 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
T_5 * V_70 )
{
T_1 V_5 ;
struct V_71 V_72 ;
T_5 V_73 = 0 ;
T_5 V_74 = 0 ;
T_5 V_75 = 0 ;
T_5 * V_41 ;
T_5 V_68 = 0 ;
V_5 = F_28 ( V_2 , & V_72 ,
V_58 * sizeof( T_5 ) ) ;
if ( V_5 )
goto V_76;
V_41 = ( T_5 * ) V_72 . V_77 ;
V_5 = F_19 ( V_2 , V_78 , & V_75 ) ;
if ( V_5 ) {
V_5 = V_79 ;
goto V_76;
}
V_5 = F_19 ( V_2 , V_80 ,
& V_73 ) ;
if ( V_5 ) {
V_5 = V_79 ;
goto V_76;
}
for ( V_68 = 0 ; V_68 < V_2 -> V_4 . V_8 ; V_68 ++ ) {
if ( ( V_68 % V_58 ) == 0 ) {
T_5 V_51 = V_58 ;
V_5 = F_24 ( V_2 , V_68 , & V_51 , V_41 ) ;
if ( V_5 ) {
V_5 = V_79 ;
goto V_76;
}
}
if ( V_68 == V_81 )
continue;
if ( ( V_68 >= ( T_2 ) V_75 ) &&
( V_68 < ( ( T_2 ) V_75 +
( V_82 / 2 ) ) ) ) {
continue;
}
if ( ( V_68 >= ( T_2 ) V_73 ) &&
( V_68 < ( ( T_2 ) V_73 +
( V_83 / 2 ) ) ) ) {
continue;
}
V_74 += V_41 [ V_68 % V_58 ] ;
}
* V_70 = ( T_5 ) V_84 - V_74 ;
V_76:
F_29 ( V_2 , & V_72 ) ;
return V_5 ;
}
T_1 F_30 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_5 V_70 ;
V_59 V_85 ;
V_5 = F_27 ( V_2 , & V_70 ) ;
if ( ! V_5 ) {
V_85 = F_31 ( V_70 ) ;
V_5 = F_25 ( V_2 , 0x00 , V_81 ,
1 , & V_85 , true ) ;
}
return V_5 ;
}
T_1 F_32 ( struct V_1 * V_2 ,
T_5 * V_70 )
{
T_1 V_5 = 0 ;
T_5 V_86 = 0 ;
T_5 V_74 = 0 ;
V_5 = F_5 ( V_2 , V_62 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_27 ( V_2 , & V_74 ) ;
F_19 ( V_2 , V_81 , & V_86 ) ;
F_9 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_74 != V_86 )
V_5 = V_79 ;
if ( V_70 )
* V_70 = V_74 ;
return V_5 ;
}
static inline T_3 F_33 ( T_2 V_87 )
{
return ( T_3 ) ( V_87 & V_88 ) ;
}
static inline T_3 F_34 ( T_2 V_87 )
{
return ( T_3 ) ( ( V_87 & V_89 ) >> V_90 ) ;
}
T_1 F_35 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
T_1 V_95 ;
enum V_96 V_97 ;
* V_94 = 0 ;
V_97 = F_36 ( V_2 , V_92 , V_94 ) ;
F_4 ( V_2 , V_19 , L_10 ,
V_98 [ V_97 ] ,
V_2 -> V_99 ,
V_2 -> V_100 , V_2 -> V_101 ,
V_92 -> V_102 , V_92 -> V_103 , V_92 -> V_40 , V_92 -> V_104 ) ;
if ( V_97 == V_105 ) {
* V_94 = - V_106 ;
F_4 ( V_2 , V_19 ,
L_11 ,
V_97 , * V_94 ) ;
}
if ( V_97 == V_107 ) {
if ( ! V_92 -> V_104 ) {
* V_94 = - V_106 ;
return V_108 ;
}
V_93 [ 0 ] = V_2 -> V_99 ;
if ( V_92 -> V_104 >= 4 ) {
V_93 [ 1 ] = 0 ;
* ( ( T_5 * ) & V_93 [ 2 ] ) = V_2 -> V_101 ;
}
if ( V_2 -> V_99 == V_109 )
V_2 -> V_99 = V_110 ;
return 0 ;
}
if ( V_2 -> V_99 == V_109 ) {
F_4 ( V_2 , V_19 ,
L_12 ) ;
V_2 -> V_99 = V_110 ;
}
F_37 ( & V_2 -> V_28 . V_111 ) ;
switch ( V_2 -> V_99 ) {
case V_110 :
V_95 = F_38 ( V_2 , V_92 , V_93 , V_94 ) ;
break;
case V_112 :
V_95 = F_39 ( V_2 , V_92 , V_93 , V_94 ) ;
break;
case V_113 :
V_95 = F_40 ( V_2 , V_92 , V_93 , V_94 ) ;
break;
case V_114 :
case V_115 :
if ( V_92 -> V_40 == 0xffff ) {
F_41 ( V_2 , V_2 -> V_101 ) ;
V_95 = 0 ;
goto exit;
}
V_95 = V_116 ;
* V_94 = - V_117 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_13 , V_2 -> V_99 ) ;
V_95 = V_118 ;
* V_94 = - V_119 ;
break;
}
exit:
F_42 ( & V_2 -> V_28 . V_111 ) ;
return V_95 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
T_1 V_95 = 0 ;
enum V_96 V_97 ;
V_97 = F_36 ( V_2 , V_92 , V_94 ) ;
switch ( V_97 ) {
case V_120 :
V_95 = F_5 ( V_2 , V_62 ) ;
if ( V_95 ) {
* V_94 = F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_95 = F_44 ( V_2 , V_92 , V_93 , V_94 ) ;
F_9 ( V_2 ) ;
}
break;
case V_121 :
V_95 = F_5 ( V_2 , V_62 ) ;
if ( V_95 ) {
* V_94 = F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_95 = F_44 ( V_2 , V_92 , V_93 , V_94 ) ;
if ( V_95 )
F_9 ( V_2 ) ;
else
V_2 -> V_99 = V_112 ;
}
break;
case V_122 :
V_95 = F_5 ( V_2 , V_123 ) ;
if ( V_95 ) {
* V_94 = F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_95 = F_45 ( V_2 , V_92 , V_94 ) ;
if ( V_95 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_100 = true ;
V_2 -> V_101 = V_124 ;
V_2 -> V_99 = V_114 ;
}
}
break;
case V_125 :
V_95 = F_5 ( V_2 , V_123 ) ;
if ( V_95 ) {
* V_94 = F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_95 = F_46 ( V_2 , V_92 , V_93 , V_94 ) ;
if ( V_95 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_100 = true ;
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_114 ;
}
}
break;
case V_127 :
V_95 = F_5 ( V_2 , V_123 ) ;
if ( V_95 ) {
* V_94 = F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_95 = F_46 ( V_2 , V_92 , V_93 , V_94 ) ;
if ( V_95 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_115 ;
}
}
break;
case V_128 :
V_95 = F_5 ( V_2 , V_123 ) ;
if ( V_95 ) {
* V_94 = F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_95 = F_30 ( V_2 ) ;
if ( V_95 ) {
* V_94 = V_2 -> V_28 . V_29 ?
F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) :
- V_129 ;
F_9 ( V_2 ) ;
} else {
V_2 -> V_100 = true ;
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_114 ;
}
}
break;
case V_130 :
V_95 = F_47 ( V_2 , V_92 , V_93 , V_94 ) ;
break;
case V_131 :
V_95 = F_48 ( V_2 , V_92 , V_93 , V_94 ) ;
break;
default:
F_4 ( V_2 , V_19 ,
L_14 ,
V_98 [ V_97 ] ) ;
V_95 = V_53 ;
* V_94 = - V_119 ;
break;
}
return V_95 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
T_1 V_95 = 0 ;
enum V_96 V_97 ;
V_97 = F_36 ( V_2 , V_92 , V_94 ) ;
switch ( V_97 ) {
case V_120 :
case V_132 :
V_95 = F_44 ( V_2 , V_92 , V_93 , V_94 ) ;
break;
case V_133 :
V_95 = F_44 ( V_2 , V_92 , V_93 , V_94 ) ;
F_9 ( V_2 ) ;
V_2 -> V_99 = V_110 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_15 ,
V_98 [ V_97 ] ) ;
V_95 = V_118 ;
* V_94 = - V_119 ;
break;
}
return V_95 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
T_1 V_95 = 0 ;
enum V_96 V_97 ;
bool V_134 = false ;
V_97 = F_36 ( V_2 , V_92 , V_94 ) ;
V_135:
switch ( V_97 ) {
case V_136 :
V_95 = F_46 ( V_2 , V_92 , V_93 , V_94 ) ;
if ( ! V_95 ) {
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_115 ;
}
break;
case V_137 :
V_95 = F_46 ( V_2 , V_92 , V_93 , V_94 ) ;
if ( V_95 ) {
* V_94 = V_2 -> V_28 . V_29 ?
F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) :
- V_129 ;
V_2 -> V_99 = V_110 ;
} else {
V_2 -> V_100 = true ;
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_114 ;
}
break;
case V_138 :
V_95 = F_30 ( V_2 ) ;
if ( V_95 ) {
* V_94 = V_2 -> V_28 . V_29 ?
F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) :
- V_129 ;
V_2 -> V_99 = V_110 ;
} else {
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_115 ;
}
break;
case V_139 :
V_95 = F_30 ( V_2 ) ;
if ( V_95 ) {
* V_94 = V_2 -> V_28 . V_29 ?
F_43 ( V_95 ,
V_2 -> V_28 . V_29 ) :
- V_129 ;
V_2 -> V_99 = V_110 ;
} else {
V_2 -> V_100 = true ;
V_2 -> V_101 = V_126 ;
V_2 -> V_99 = V_114 ;
}
break;
default:
F_4 ( V_2 , V_19 ,
L_16 ,
V_98 [ V_97 ] ) ;
V_95 = V_118 ;
* V_94 = - V_119 ;
break;
}
if ( V_95 && ( V_2 -> V_28 . V_29 == V_140 ) &&
! V_134 ) {
T_1 V_141 = V_95 ;
T_2 V_142 = V_2 -> V_28 . V_29 ;
T_2 V_22 ;
V_22 = F_2 ( V_2 , V_26 ) ;
if ( V_22 >= V_2 -> V_4 . V_27 ) {
F_4 ( V_2 , V_143 ,
L_17 ,
V_22 , V_2 -> V_4 . V_27 ) ;
F_9 ( V_2 ) ;
V_95 = F_5 ( V_2 , V_123 ) ;
if ( V_95 ) {
F_4 ( V_2 , V_143 ,
L_18 ,
V_2 -> V_28 . V_29 ) ;
V_95 = V_141 ;
V_2 -> V_28 . V_29 = V_142 ;
} else {
V_134 = true ;
goto V_135;
}
}
}
return V_95 ;
}
void F_41 ( struct V_1 * V_2 , T_5 V_144 )
{
if ( V_144 == V_2 -> V_101 ) {
F_4 ( V_2 , V_19 ,
L_19 , V_144 ) ;
if ( V_2 -> V_100 ) {
F_9 ( V_2 ) ;
V_2 -> V_100 = false ;
}
V_2 -> V_101 = 0 ;
if ( V_2 -> V_28 . V_145 ) {
V_2 -> V_99 = V_109 ;
return;
}
switch ( V_2 -> V_99 ) {
case V_114 :
V_2 -> V_99 = V_110 ;
break;
case V_115 :
V_2 -> V_99 = V_113 ;
break;
default:
break;
}
}
}
static enum V_96 F_36 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
int * V_94 )
{
enum V_96 V_97 ;
T_3 V_146 , V_147 ;
V_97 = V_105 ;
V_147 = F_34 ( V_92 -> V_103 ) ;
V_146 = F_33 ( V_92 -> V_103 ) ;
if ( ( V_92 -> V_104 < 1 ) ||
( V_92 -> V_104 > V_148 ) ) {
F_4 ( V_2 , V_19 ,
L_20 ,
V_92 -> V_104 ) ;
* V_94 = - V_106 ;
return V_105 ;
}
switch ( V_92 -> V_102 ) {
case V_149 :
switch ( V_147 ) {
case V_150 :
V_97 = V_132 ;
break;
case V_151 :
V_97 = V_121 ;
break;
case V_152 :
V_97 = V_133 ;
break;
case V_153 :
V_97 = V_120 ;
break;
case V_154 :
if ( V_146 == 0xf )
V_97 = V_107 ;
else if ( V_146 == 0 )
V_97 = V_131 ;
break;
}
break;
case V_155 :
switch ( V_147 ) {
case V_150 :
V_97 = V_136 ;
break;
case V_151 :
V_97 = V_127 ;
break;
case V_152 :
V_97 = V_137 ;
break;
case V_153 :
V_97 = V_125 ;
break;
case V_156 :
V_97 = V_122 ;
break;
case V_157 :
V_97 = V_138 ;
break;
case ( V_157 | V_153 ) :
V_97 = V_128 ;
break;
case ( V_157 | V_152 ) :
V_97 = V_139 ;
break;
case V_154 :
if ( V_146 == 0 )
V_97 = V_130 ;
break;
}
break;
}
return V_97 ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
struct V_54 V_55 ;
T_1 V_95 ;
struct V_158 * V_159 ;
T_2 V_160 = 0 ;
T_3 * V_161 = NULL ;
T_2 V_162 ;
T_2 V_163 ;
F_4 ( V_2 , V_19 , L_21 , V_164 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = & V_2 -> V_57 ;
V_162 = sizeof( struct V_158 ) ;
memset ( & V_2 -> V_57 , 0 , V_162 ) ;
if ( V_92 -> V_104 < V_162 ) {
F_4 ( V_2 , V_19 ,
L_22 ,
V_92 -> V_104 , V_162 ) ;
* V_94 = - V_165 ;
return V_43 ;
}
V_159 = (struct V_158 * ) V_93 ;
V_163 = V_92 -> V_104 - V_162 ;
V_160 = F_49 ( T_2 , V_163 , F_18 ( V_159 -> V_166 ) ) ;
if ( V_160 ) {
if ( ! V_2 -> V_167 . V_77 ) {
V_95 = F_28 ( V_2 , & V_2 -> V_167 ,
V_2 -> V_28 . V_168 ) ;
if ( V_95 )
F_4 ( V_2 , V_19 ,
L_23 ,
V_95 ) ;
}
if ( V_2 -> V_167 . V_77 ) {
V_161 = V_2 -> V_167 . V_77 ;
memcpy ( V_161 , & V_93 [ V_162 ] , V_163 ) ;
}
}
V_95 = F_50 ( V_2 , V_159 , V_161 ,
V_160 , & V_55 ) ;
if ( V_95 ) {
F_4 ( V_2 , V_19 ,
L_24 ,
F_51 ( V_2 , V_95 ) ,
F_52 ( V_2 , V_2 -> V_28 . V_29 ) ) ;
* V_94 = F_43 ( V_95 , V_2 -> V_28 . V_29 ) ;
}
if ( V_92 -> V_40 ) {
V_2 -> V_101 = V_92 -> V_40 ;
V_2 -> V_99 = V_114 ;
}
return V_95 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
T_2 V_169 ;
T_2 V_162 ;
int V_170 ;
T_3 * V_161 ;
F_4 ( V_2 , V_19 , L_21 , V_164 ) ;
V_162 = sizeof( struct V_158 ) ;
V_169 = V_162 + F_18 ( V_2 -> V_57 . V_166 ) ;
if ( V_92 -> V_40 > V_169 ) {
F_4 ( V_2 , V_19 , L_25 ,
V_164 , V_92 -> V_40 , V_169 ) ;
* V_94 = - V_165 ;
return V_43 ;
}
if ( V_92 -> V_104 > ( V_169 - V_92 -> V_40 ) ) {
int V_171 = V_169 - V_92 -> V_40 ;
F_4 ( V_2 , V_19 , L_26 ,
V_164 , V_92 -> V_104 , V_171 ) ;
V_92 -> V_104 = V_171 ;
}
V_170 = V_92 -> V_104 ;
if ( V_92 -> V_40 < V_162 ) {
T_2 V_172 = V_162 - V_92 -> V_40 ;
V_172 = F_23 ( V_172 , V_92 -> V_104 ) ;
F_4 ( V_2 , V_19 , L_27 ,
V_164 , V_92 -> V_40 , V_92 -> V_40 + V_172 ) ;
V_161 = ( ( T_3 * ) & V_2 -> V_57 ) + V_92 -> V_40 ;
memcpy ( V_93 , V_161 , V_172 ) ;
V_93 += V_172 ;
V_170 -= V_172 ;
V_161 = V_2 -> V_167 . V_77 ;
} else {
V_161 = V_2 -> V_167 . V_77 + ( V_92 -> V_40 - V_162 ) ;
}
if ( V_170 > 0 ) {
int V_173 = V_161 - ( T_3 * ) V_2 -> V_167 . V_77 ;
F_4 ( V_2 , V_19 , L_28 ,
V_164 , V_173 , V_173 + V_170 ) ;
memcpy ( V_93 , V_161 , V_170 ) ;
}
return 0 ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
struct V_54 V_55 ;
T_1 V_95 ;
T_3 V_146 , V_147 ;
bool V_174 ;
V_147 = F_34 ( V_92 -> V_103 ) ;
V_146 = F_33 ( V_92 -> V_103 ) ;
V_174 = ( V_147 == V_152 ) || ( V_147 == V_153 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = & V_2 -> V_57 ;
V_95 = F_16 ( V_2 , V_146 , V_92 -> V_40 , ( T_5 ) V_92 -> V_104 ,
V_93 , V_174 , & V_55 ) ;
if ( V_95 ) {
F_4 ( V_2 , V_19 ,
L_29 ,
V_146 , V_92 -> V_40 , V_92 -> V_104 ) ;
F_4 ( V_2 , V_19 ,
L_30 ,
V_95 , V_2 -> V_28 . V_29 ) ;
* V_94 = F_43 ( V_95 , V_2 -> V_28 . V_29 ) ;
}
return V_95 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
int * V_94 )
{
T_1 V_95 = 0 ;
struct V_54 V_55 ;
T_3 V_146 , V_147 ;
bool V_174 ;
V_147 = F_34 ( V_92 -> V_103 ) ;
V_146 = F_33 ( V_92 -> V_103 ) ;
V_174 = ( V_147 & V_152 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = & V_2 -> V_57 ;
V_95 = F_53 ( V_2 , V_146 , V_92 -> V_40 , ( T_5 ) V_92 -> V_104 ,
V_174 , & V_55 ) ;
if ( V_95 ) {
F_4 ( V_2 , V_19 ,
L_31 ,
V_146 , V_92 -> V_40 , V_92 -> V_104 ) ;
F_4 ( V_2 , V_19 ,
L_32 ,
V_95 , V_2 -> V_28 . V_29 ) ;
* V_94 = F_43 ( V_95 , V_2 -> V_28 . V_29 ) ;
}
return V_95 ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
T_3 * V_93 , int * V_94 )
{
T_1 V_95 = 0 ;
struct V_54 V_55 ;
T_3 V_146 , V_147 ;
bool V_174 ;
V_147 = F_34 ( V_92 -> V_103 ) ;
V_146 = F_33 ( V_92 -> V_103 ) ;
V_174 = ( V_147 & V_152 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_56 = & V_2 -> V_57 ;
V_95 = F_26 ( V_2 , V_146 , V_92 -> V_40 ,
( T_5 ) V_92 -> V_104 , V_93 , V_174 ,
& V_55 ) ;
if ( V_95 ) {
F_4 ( V_2 , V_19 ,
L_33 ,
V_146 , V_92 -> V_40 , V_92 -> V_104 ) ;
F_4 ( V_2 , V_19 ,
L_34 ,
V_95 , V_2 -> V_28 . V_29 ) ;
* V_94 = F_43 ( V_95 , V_2 -> V_28 . V_29 ) ;
}
return V_95 ;
}
