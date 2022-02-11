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
if ( ! V_2 -> V_4 . V_17 )
F_10 ( V_2 , V_25 , 0 , NULL ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_5 = V_30 ;
T_2 V_31 , V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 = F_2 ( V_2 , V_34 ) ;
if ( V_31 & V_35 ) {
V_5 = 0 ;
break;
}
F_12 ( 5 ) ;
}
if ( V_5 == V_30 )
F_4 ( V_2 , V_19 , L_4 ) ;
return V_5 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_37 )
{
T_1 V_5 = V_30 ;
T_2 V_38 ;
if ( V_36 >= V_2 -> V_4 . V_8 ) {
F_4 ( V_2 , V_19 ,
L_5 ,
V_36 , V_2 -> V_4 . V_8 ) ;
V_5 = V_39 ;
goto V_40;
}
V_5 = F_11 ( V_2 ) ;
if ( ! V_5 ) {
V_38 = ( ( T_2 ) V_36 << V_41 ) |
F_3 ( V_42 ) ;
F_14 ( V_2 , V_34 , V_38 ) ;
V_5 = F_11 ( V_2 ) ;
if ( ! V_5 ) {
V_38 = F_2 ( V_2 , V_43 ) ;
* V_37 = ( T_5 ) ( ( V_38 &
V_44 )
>> V_45 ) ;
}
}
if ( V_5 )
F_4 ( V_2 , V_19 ,
L_6 ,
V_36 ) ;
V_40:
return V_5 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_46 ,
T_2 V_36 , T_5 V_47 , void * V_37 ,
bool V_48 )
{
T_1 V_5 = V_49 ;
struct V_50 V_51 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
if ( ( V_36 + V_47 ) > V_2 -> V_4 . V_8 )
F_4 ( V_2 , V_19 ,
L_7 ,
( V_36 + V_47 ) , V_2 -> V_4 . V_8 ) ;
else if ( V_47 > V_52 )
F_4 ( V_2 , V_19 ,
L_8 ,
V_47 , V_52 ) ;
else if ( ( ( V_36 + ( V_47 - 1 ) ) / V_52 )
!= ( V_36 / V_52 ) )
F_4 ( V_2 , V_19 ,
L_9 ,
V_36 , V_47 ) ;
else
V_5 = F_16 ( V_2 , V_46 ,
2 * V_36 ,
2 * V_47 ,
V_37 , V_48 , & V_51 ) ;
return V_5 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_37 )
{
T_1 V_5 = V_30 ;
V_5 = F_15 ( V_2 , 0x0 , V_36 , 1 , V_37 , true ) ;
* V_37 = F_18 ( * ( V_53 * ) V_37 ) ;
return V_5 ;
}
T_1 F_19 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_37 )
{
enum V_54 V_5 = 0 ;
if ( V_2 -> V_55 & V_56 ) {
V_5 = F_5 ( V_2 , V_57 ) ;
if ( ! V_5 ) {
V_5 = F_17 ( V_2 , V_36 , V_37 ) ;
F_9 ( V_2 ) ;
}
} else {
V_5 = F_13 ( V_2 , V_36 , V_37 ) ;
}
return V_5 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_47 , T_5 * V_37 )
{
T_1 V_5 = 0 ;
T_5 V_58 , V_59 ;
for ( V_59 = 0 ; V_59 < * V_47 ; V_59 ++ ) {
V_58 = V_36 + V_59 ;
V_5 = F_13 ( V_2 , V_58 , & V_37 [ V_59 ] ) ;
if ( V_5 )
break;
}
* V_47 = V_59 ;
return V_5 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_47 , T_5 * V_37 )
{
T_1 V_5 ;
T_5 V_60 = * V_47 ;
bool V_61 = false ;
T_5 V_62 = 0 ;
T_5 V_63 = 0 ;
do {
if ( V_36 % V_52 )
V_60 = F_22 ( * V_47 ,
( T_5 ) ( V_52 -
( V_36 % V_52 ) ) ) ;
else
V_60 = F_22 ( ( * V_47 - V_62 ) ,
V_52 ) ;
if ( ( V_62 + V_60 ) >= * V_47 )
V_61 = true ;
V_5 = F_15 ( V_2 , 0x0 , V_36 , V_60 ,
V_37 + V_62 , V_61 ) ;
if ( V_5 )
goto V_64;
V_62 += V_60 ;
V_36 += V_60 ;
} while ( V_62 < * V_47 );
for ( V_63 = 0 ; V_63 < * V_47 ; V_63 ++ )
V_37 [ V_63 ] = F_18 ( ( ( V_53 * ) V_37 ) [ V_63 ] ) ;
V_64:
* V_47 = V_62 ;
return V_5 ;
}
T_1 F_23 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_47 , T_5 * V_37 )
{
enum V_54 V_5 = 0 ;
if ( V_2 -> V_55 & V_56 ) {
V_5 = F_5 ( V_2 , V_57 ) ;
if ( ! V_5 ) {
V_5 = F_21 ( V_2 , V_36 , V_47 ,
V_37 ) ;
F_9 ( V_2 ) ;
}
} else {
V_5 = F_20 ( V_2 , V_36 , V_47 , V_37 ) ;
}
return V_5 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_3 V_46 ,
T_2 V_36 , T_5 V_47 , void * V_37 ,
bool V_48 )
{
T_1 V_5 = V_49 ;
struct V_50 V_51 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
if ( ( V_36 + V_47 ) > V_2 -> V_4 . V_8 )
F_4 ( V_2 , V_19 ,
L_7 ,
( V_36 + V_47 ) , V_2 -> V_4 . V_8 ) ;
else if ( V_47 > V_52 )
F_4 ( V_2 , V_19 ,
L_8 ,
V_47 , V_52 ) ;
else if ( ( ( V_36 + ( V_47 - 1 ) ) / V_52 )
!= ( V_36 / V_52 ) )
F_4 ( V_2 , V_19 ,
L_9 ,
V_36 , V_47 ) ;
else
V_5 = F_25 ( V_2 , V_46 ,
2 * V_36 ,
2 * V_47 ,
V_37 , V_48 , & V_51 ) ;
return V_5 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
T_5 * V_67 )
{
T_1 V_5 ;
struct V_68 V_69 ;
T_5 V_70 = 0 ;
T_5 V_71 = 0 ;
T_5 V_72 = 0 ;
T_5 * V_37 ;
T_5 V_63 = 0 ;
V_5 = F_27 ( V_2 , & V_69 ,
V_52 * sizeof( T_5 ) ) ;
if ( V_5 )
goto V_73;
V_37 = ( T_5 * ) V_69 . V_74 ;
V_5 = F_19 ( V_2 , V_75 , & V_72 ) ;
if ( V_5 ) {
V_5 = V_76 ;
goto V_73;
}
V_5 = F_19 ( V_2 , V_77 ,
& V_70 ) ;
if ( V_5 ) {
V_5 = V_76 ;
goto V_73;
}
for ( V_63 = 0 ; V_63 < V_2 -> V_4 . V_8 ; V_63 ++ ) {
if ( ( V_63 % V_52 ) == 0 ) {
T_5 V_47 = V_52 ;
V_5 = F_23 ( V_2 , V_63 , & V_47 , V_37 ) ;
if ( V_5 ) {
V_5 = V_76 ;
goto V_73;
}
}
if ( V_63 == V_78 )
continue;
if ( ( V_63 >= ( T_2 ) V_72 ) &&
( V_63 < ( ( T_2 ) V_72 +
( V_79 / 2 ) ) ) ) {
continue;
}
if ( ( V_63 >= ( T_2 ) V_70 ) &&
( V_63 < ( ( T_2 ) V_70 +
( V_80 / 2 ) ) ) ) {
continue;
}
V_71 += V_37 [ V_63 % V_52 ] ;
}
* V_67 = ( T_5 ) V_81 - V_71 ;
V_73:
F_28 ( V_2 , & V_69 ) ;
return V_5 ;
}
T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_5 V_67 ;
V_53 V_82 ;
V_5 = F_26 ( V_2 , & V_67 ) ;
if ( ! V_5 ) {
V_82 = F_30 ( V_67 ) ;
V_5 = F_24 ( V_2 , 0x00 , V_78 ,
1 , & V_82 , true ) ;
}
return V_5 ;
}
T_1 F_31 ( struct V_1 * V_2 ,
T_5 * V_67 )
{
T_1 V_5 = 0 ;
T_5 V_83 = 0 ;
T_5 V_71 = 0 ;
V_5 = F_26 ( V_2 , & V_71 ) ;
if ( V_5 )
goto V_84;
F_19 ( V_2 , V_78 , & V_83 ) ;
if ( V_71 != V_83 )
V_5 = V_76 ;
if ( V_67 )
* V_67 = V_71 ;
V_84:
return V_5 ;
}
static inline T_3 F_32 ( T_2 V_85 )
{
return ( T_3 ) ( V_85 & V_86 ) ;
}
static inline T_3 F_33 ( T_2 V_85 )
{
return ( T_3 ) ( ( V_85 & V_87 ) >> V_88 ) ;
}
T_1 F_34 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_1 V_93 ;
enum V_94 V_95 ;
* V_92 = 0 ;
V_95 = F_35 ( V_2 , V_90 , V_92 ) ;
F_4 ( V_2 , V_19 , L_10 ,
V_96 [ V_95 ] ,
V_2 -> V_97 ,
V_2 -> V_98 , V_2 -> V_99 ,
V_90 -> V_100 , V_90 -> V_101 , V_90 -> V_36 , V_90 -> V_102 ) ;
if ( V_95 == V_103 ) {
* V_92 = - V_104 ;
F_4 ( V_2 , V_19 ,
L_11 ,
V_95 , * V_92 ) ;
}
if ( V_95 == V_105 ) {
if ( ! V_90 -> V_102 ) {
* V_92 = - V_104 ;
return V_106 ;
}
V_91 [ 0 ] = V_2 -> V_97 ;
if ( V_90 -> V_102 >= 4 ) {
V_91 [ 1 ] = 0 ;
* ( ( T_5 * ) & V_91 [ 2 ] ) = V_2 -> V_99 ;
}
return 0 ;
}
switch ( V_2 -> V_97 ) {
case V_107 :
V_93 = F_36 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_108 :
V_93 = F_37 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_109 :
V_93 = F_38 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_110 :
case V_111 :
if ( V_90 -> V_36 == 0xffff ) {
F_39 ( V_2 , V_2 -> V_99 ) ;
return 0 ;
}
V_93 = V_112 ;
* V_92 = - V_113 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_12 , V_2 -> V_97 ) ;
V_93 = V_114 ;
* V_92 = - V_115 ;
break;
}
return V_93 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_1 V_93 = 0 ;
enum V_94 V_95 ;
V_95 = F_35 ( V_2 , V_90 , V_92 ) ;
switch ( V_95 ) {
case V_116 :
V_93 = F_5 ( V_2 , V_57 ) ;
if ( V_93 ) {
* V_92 = F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_41 ( V_2 , V_90 , V_91 , V_92 ) ;
F_9 ( V_2 ) ;
}
break;
case V_117 :
V_93 = F_5 ( V_2 , V_57 ) ;
if ( V_93 ) {
* V_92 = F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_41 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 )
F_9 ( V_2 ) ;
else
V_2 -> V_97 = V_108 ;
}
break;
case V_118 :
V_93 = F_5 ( V_2 , V_119 ) ;
if ( V_93 ) {
* V_92 = F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_42 ( V_2 , V_90 , V_92 ) ;
if ( V_93 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_99 = V_120 ;
V_2 -> V_97 = V_110 ;
}
}
break;
case V_121 :
V_93 = F_5 ( V_2 , V_119 ) ;
if ( V_93 ) {
* V_92 = F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_43 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_110 ;
}
}
break;
case V_123 :
V_93 = F_5 ( V_2 , V_119 ) ;
if ( V_93 ) {
* V_92 = F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_43 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_111 ;
}
}
break;
case V_124 :
V_93 = F_5 ( V_2 , V_119 ) ;
if ( V_93 ) {
* V_92 = F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_29 ( V_2 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_125 ;
F_9 ( V_2 ) ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_110 ;
}
}
break;
case V_126 :
V_93 = F_44 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_127 :
V_93 = F_45 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
default:
F_4 ( V_2 , V_19 ,
L_13 ,
V_96 [ V_95 ] ) ;
V_93 = V_49 ;
* V_92 = - V_115 ;
break;
}
return V_93 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_1 V_93 = 0 ;
enum V_94 V_95 ;
V_95 = F_35 ( V_2 , V_90 , V_92 ) ;
switch ( V_95 ) {
case V_116 :
case V_128 :
V_93 = F_41 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_129 :
V_93 = F_41 ( V_2 , V_90 , V_91 , V_92 ) ;
F_9 ( V_2 ) ;
V_2 -> V_97 = V_107 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_14 ,
V_96 [ V_95 ] ) ;
V_93 = V_114 ;
* V_92 = - V_115 ;
break;
}
return V_93 ;
}
static T_1 F_38 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_1 V_93 = 0 ;
enum V_94 V_95 ;
bool V_130 = false ;
V_95 = F_35 ( V_2 , V_90 , V_92 ) ;
V_131:
switch ( V_95 ) {
case V_132 :
V_93 = F_43 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( ! V_93 ) {
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_111 ;
}
break;
case V_133 :
V_93 = F_43 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_125 ;
V_2 -> V_97 = V_107 ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_110 ;
}
break;
case V_134 :
V_93 = F_29 ( V_2 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_125 ;
V_2 -> V_97 = V_107 ;
} else {
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_111 ;
}
break;
case V_135 :
V_93 = F_29 ( V_2 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_40 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_125 ;
V_2 -> V_97 = V_107 ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_99 = V_122 ;
V_2 -> V_97 = V_110 ;
}
break;
default:
F_4 ( V_2 , V_19 ,
L_15 ,
V_96 [ V_95 ] ) ;
V_93 = V_114 ;
* V_92 = - V_115 ;
break;
}
if ( V_93 && ( V_2 -> V_28 . V_29 == V_136 ) &&
! V_130 ) {
T_1 V_137 = V_93 ;
T_2 V_138 = V_2 -> V_28 . V_29 ;
T_2 V_22 ;
V_22 = F_2 ( V_2 , V_26 ) ;
if ( V_22 >= V_2 -> V_4 . V_27 ) {
F_4 ( V_2 , V_139 ,
L_16 ,
V_22 , V_2 -> V_4 . V_27 ) ;
F_9 ( V_2 ) ;
V_93 = F_5 ( V_2 , V_119 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_139 ,
L_17 ,
V_2 -> V_28 . V_29 ) ;
V_93 = V_137 ;
V_2 -> V_28 . V_29 = V_138 ;
} else {
V_130 = true ;
goto V_131;
}
}
}
return V_93 ;
}
void F_39 ( struct V_1 * V_2 , T_5 V_140 )
{
if ( V_140 == V_2 -> V_99 ) {
F_4 ( V_2 , V_19 ,
L_18 , V_140 ) ;
if ( V_2 -> V_98 ) {
F_9 ( V_2 ) ;
V_2 -> V_98 = false ;
}
V_2 -> V_99 = 0 ;
switch ( V_2 -> V_97 ) {
case V_110 :
V_2 -> V_97 = V_107 ;
break;
case V_111 :
V_2 -> V_97 = V_109 ;
break;
default:
break;
}
}
}
static enum V_94 F_35 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
int * V_92 )
{
enum V_94 V_95 ;
T_3 V_141 , V_142 ;
V_95 = V_103 ;
V_142 = F_33 ( V_90 -> V_101 ) ;
V_141 = F_32 ( V_90 -> V_101 ) ;
if ( ( V_90 -> V_102 < 1 ) ||
( V_90 -> V_102 > V_143 ) ) {
F_4 ( V_2 , V_19 ,
L_19 ,
V_90 -> V_102 ) ;
* V_92 = - V_104 ;
return V_103 ;
}
switch ( V_90 -> V_100 ) {
case V_144 :
switch ( V_142 ) {
case V_145 :
V_95 = V_128 ;
break;
case V_146 :
V_95 = V_117 ;
break;
case V_147 :
V_95 = V_129 ;
break;
case V_148 :
V_95 = V_116 ;
break;
case V_149 :
if ( V_141 == 0xf )
V_95 = V_105 ;
else if ( V_141 == 0 )
V_95 = V_127 ;
break;
}
break;
case V_150 :
switch ( V_142 ) {
case V_145 :
V_95 = V_132 ;
break;
case V_146 :
V_95 = V_123 ;
break;
case V_147 :
V_95 = V_133 ;
break;
case V_148 :
V_95 = V_121 ;
break;
case V_151 :
V_95 = V_118 ;
break;
case V_152 :
V_95 = V_134 ;
break;
case ( V_152 | V_148 ) :
V_95 = V_124 ;
break;
case ( V_152 | V_147 ) :
V_95 = V_135 ;
break;
case V_149 :
if ( V_141 == 0 )
V_95 = V_126 ;
break;
}
break;
}
return V_95 ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
struct V_50 V_51 ;
T_1 V_93 ;
struct V_153 * V_154 ;
T_2 V_155 = 0 ;
T_3 * V_156 = NULL ;
T_2 V_157 ;
T_2 V_158 ;
F_4 ( V_2 , V_19 , L_20 , V_159 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_157 = sizeof( struct V_153 ) ;
memset ( & V_2 -> V_66 , 0 , V_157 ) ;
if ( V_90 -> V_102 < V_157 ) {
F_4 ( V_2 , V_19 ,
L_21 ,
V_90 -> V_102 , V_157 ) ;
* V_92 = - V_160 ;
return V_39 ;
}
V_154 = (struct V_153 * ) V_91 ;
V_158 = V_90 -> V_102 - V_157 ;
V_155 = F_46 ( T_2 , V_158 , F_18 ( V_154 -> V_161 ) ) ;
if ( V_155 ) {
if ( ! V_2 -> V_162 . V_74 ) {
V_93 = F_27 ( V_2 , & V_2 -> V_162 ,
V_2 -> V_28 . V_163 ) ;
if ( V_93 )
F_4 ( V_2 , V_19 ,
L_22 ,
V_93 ) ;
}
if ( V_2 -> V_162 . V_74 ) {
V_156 = V_2 -> V_162 . V_74 ;
memcpy ( V_156 , & V_91 [ V_157 ] , V_158 ) ;
}
}
V_93 = F_47 ( V_2 , V_154 , V_156 ,
V_155 , & V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_23 ,
F_48 ( V_2 , V_93 ) ,
F_49 ( V_2 , V_2 -> V_28 . V_29 ) ) ;
* V_92 = F_40 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
if ( V_90 -> V_36 ) {
V_2 -> V_99 = V_90 -> V_36 ;
V_2 -> V_97 = V_110 ;
}
return V_93 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_2 V_164 ;
T_2 V_157 ;
int V_165 ;
T_3 * V_156 ;
F_4 ( V_2 , V_19 , L_20 , V_159 ) ;
V_157 = sizeof( struct V_153 ) ;
V_164 = V_157 + F_18 ( V_2 -> V_66 . V_161 ) ;
if ( V_90 -> V_36 > V_164 ) {
F_4 ( V_2 , V_19 , L_24 ,
V_159 , V_90 -> V_36 , V_164 ) ;
* V_92 = - V_160 ;
return V_39 ;
}
if ( V_90 -> V_102 > ( V_164 - V_90 -> V_36 ) ) {
int V_166 = V_164 - V_90 -> V_36 ;
F_4 ( V_2 , V_19 , L_25 ,
V_159 , V_90 -> V_102 , V_166 ) ;
V_90 -> V_102 = V_166 ;
}
V_165 = V_90 -> V_102 ;
if ( V_90 -> V_36 < V_157 ) {
T_2 V_167 = V_157 - V_90 -> V_36 ;
V_167 = F_22 ( V_167 , V_90 -> V_102 ) ;
F_4 ( V_2 , V_19 , L_26 ,
V_159 , V_90 -> V_36 , V_90 -> V_36 + V_167 ) ;
V_156 = ( ( T_3 * ) & V_2 -> V_66 ) + V_90 -> V_36 ;
memcpy ( V_91 , V_156 , V_167 ) ;
V_91 += V_167 ;
V_165 -= V_167 ;
V_156 = V_2 -> V_162 . V_74 ;
} else {
V_156 = V_2 -> V_162 . V_74 + ( V_90 -> V_36 - V_157 ) ;
}
if ( V_165 > 0 ) {
int V_168 = V_156 - ( T_3 * ) V_2 -> V_162 . V_74 ;
F_4 ( V_2 , V_19 , L_27 ,
V_159 , V_168 , V_168 + V_165 ) ;
memcpy ( V_91 , V_156 , V_165 ) ;
}
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
struct V_50 V_51 ;
T_1 V_93 ;
T_3 V_141 , V_142 ;
bool V_169 ;
V_142 = F_33 ( V_90 -> V_101 ) ;
V_141 = F_32 ( V_90 -> V_101 ) ;
V_169 = ( V_142 == V_147 ) || ( V_142 == V_148 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_93 = F_16 ( V_2 , V_141 , V_90 -> V_36 , ( T_5 ) V_90 -> V_102 ,
V_91 , V_169 , & V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_28 ,
V_141 , V_90 -> V_36 , V_90 -> V_102 ) ;
F_4 ( V_2 , V_19 ,
L_29 ,
V_93 , V_2 -> V_28 . V_29 ) ;
* V_92 = F_40 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
int * V_92 )
{
T_1 V_93 = 0 ;
struct V_50 V_51 ;
T_3 V_141 , V_142 ;
bool V_169 ;
V_142 = F_33 ( V_90 -> V_101 ) ;
V_141 = F_32 ( V_90 -> V_101 ) ;
V_169 = ( V_142 & V_147 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_93 = F_50 ( V_2 , V_141 , V_90 -> V_36 , ( T_5 ) V_90 -> V_102 ,
V_169 , & V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_30 ,
V_141 , V_90 -> V_36 , V_90 -> V_102 ) ;
F_4 ( V_2 , V_19 ,
L_31 ,
V_93 , V_2 -> V_28 . V_29 ) ;
* V_92 = F_40 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_1 V_93 = 0 ;
struct V_50 V_51 ;
T_3 V_141 , V_142 ;
bool V_169 ;
V_142 = F_33 ( V_90 -> V_101 ) ;
V_141 = F_32 ( V_90 -> V_101 ) ;
V_169 = ( V_142 & V_147 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_93 = F_25 ( V_2 , V_141 , V_90 -> V_36 ,
( T_5 ) V_90 -> V_102 , V_91 , V_169 ,
& V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_32 ,
V_141 , V_90 -> V_36 , V_90 -> V_102 ) ;
F_4 ( V_2 , V_19 ,
L_33 ,
V_93 , V_2 -> V_28 . V_29 ) ;
* V_92 = F_40 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
