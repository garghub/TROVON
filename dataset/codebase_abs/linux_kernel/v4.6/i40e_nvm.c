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
V_2 -> V_28 . V_98 ,
V_90 -> V_99 , V_90 -> V_100 , V_90 -> V_36 , V_90 -> V_101 ) ;
if ( V_95 == V_102 ) {
* V_92 = - V_103 ;
F_4 ( V_2 , V_19 ,
L_11 ,
V_95 , * V_92 ) ;
}
if ( V_95 == V_104 ) {
V_91 [ 0 ] = V_2 -> V_97 ;
return 0 ;
}
switch ( V_2 -> V_97 ) {
case V_105 :
V_93 = F_36 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_106 :
V_93 = F_37 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_107 :
V_93 = F_38 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_108 :
case V_109 :
V_93 = V_110 ;
* V_92 = - V_111 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_12 , V_2 -> V_97 ) ;
V_93 = V_112 ;
* V_92 = - V_113 ;
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
case V_114 :
V_93 = F_5 ( V_2 , V_57 ) ;
if ( V_93 ) {
* V_92 = F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_40 ( V_2 , V_90 , V_91 , V_92 ) ;
F_9 ( V_2 ) ;
}
break;
case V_115 :
V_93 = F_5 ( V_2 , V_57 ) ;
if ( V_93 ) {
* V_92 = F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_40 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 )
F_9 ( V_2 ) ;
else
V_2 -> V_97 = V_106 ;
}
break;
case V_116 :
V_93 = F_5 ( V_2 , V_117 ) ;
if ( V_93 ) {
* V_92 = F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_41 ( V_2 , V_90 , V_92 ) ;
if ( V_93 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_28 . V_98 = true ;
V_2 -> V_97 = V_108 ;
}
}
break;
case V_118 :
V_93 = F_5 ( V_2 , V_117 ) ;
if ( V_93 ) {
* V_92 = F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_42 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 ) {
F_9 ( V_2 ) ;
} else {
V_2 -> V_28 . V_98 = true ;
V_2 -> V_97 = V_108 ;
}
}
break;
case V_119 :
V_93 = F_5 ( V_2 , V_117 ) ;
if ( V_93 ) {
* V_92 = F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_42 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 )
F_9 ( V_2 ) ;
else
V_2 -> V_97 = V_109 ;
}
break;
case V_120 :
V_93 = F_5 ( V_2 , V_117 ) ;
if ( V_93 ) {
* V_92 = F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_93 = F_29 ( V_2 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_121 ;
F_9 ( V_2 ) ;
} else {
V_2 -> V_28 . V_98 = true ;
V_2 -> V_97 = V_108 ;
}
}
break;
case V_122 :
V_93 = F_43 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_123 :
V_93 = F_44 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
default:
F_4 ( V_2 , V_19 ,
L_13 ,
V_96 [ V_95 ] ) ;
V_93 = V_49 ;
* V_92 = - V_113 ;
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
case V_114 :
case V_124 :
V_93 = F_40 ( V_2 , V_90 , V_91 , V_92 ) ;
break;
case V_125 :
V_93 = F_40 ( V_2 , V_90 , V_91 , V_92 ) ;
F_9 ( V_2 ) ;
V_2 -> V_97 = V_105 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_14 ,
V_96 [ V_95 ] ) ;
V_93 = V_112 ;
* V_92 = - V_113 ;
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
bool V_126 = false ;
V_95 = F_35 ( V_2 , V_90 , V_92 ) ;
V_127:
switch ( V_95 ) {
case V_128 :
V_93 = F_42 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( ! V_93 )
V_2 -> V_97 = V_109 ;
break;
case V_129 :
V_93 = F_42 ( V_2 , V_90 , V_91 , V_92 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_121 ;
V_2 -> V_97 = V_105 ;
} else {
V_2 -> V_28 . V_98 = true ;
V_2 -> V_97 = V_108 ;
}
break;
case V_130 :
V_93 = F_29 ( V_2 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_121 ;
V_2 -> V_97 = V_105 ;
} else {
V_2 -> V_97 = V_109 ;
}
break;
case V_131 :
V_93 = F_29 ( V_2 ) ;
if ( V_93 ) {
* V_92 = V_2 -> V_28 . V_29 ?
F_39 ( V_93 ,
V_2 -> V_28 . V_29 ) :
- V_121 ;
V_2 -> V_97 = V_105 ;
} else {
V_2 -> V_28 . V_98 = true ;
V_2 -> V_97 = V_108 ;
}
break;
default:
F_4 ( V_2 , V_19 ,
L_15 ,
V_96 [ V_95 ] ) ;
V_93 = V_112 ;
* V_92 = - V_113 ;
break;
}
if ( V_93 && ( V_2 -> V_28 . V_29 == V_132 ) &&
! V_126 ) {
T_1 V_133 = V_93 ;
T_2 V_134 = V_2 -> V_28 . V_29 ;
T_2 V_22 ;
V_22 = F_2 ( V_2 , V_26 ) ;
if ( V_22 >= V_2 -> V_4 . V_27 ) {
F_4 ( V_2 , V_135 ,
L_16 ,
V_22 , V_2 -> V_4 . V_27 ) ;
F_9 ( V_2 ) ;
V_93 = F_5 ( V_2 , V_117 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_135 ,
L_17 ,
V_2 -> V_28 . V_29 ) ;
V_93 = V_133 ;
V_2 -> V_28 . V_29 = V_134 ;
} else {
V_126 = true ;
goto V_127;
}
}
}
return V_93 ;
}
static enum V_94 F_35 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
int * V_92 )
{
enum V_94 V_95 ;
T_3 V_136 , V_137 ;
V_95 = V_102 ;
V_137 = F_33 ( V_90 -> V_100 ) ;
V_136 = F_32 ( V_90 -> V_100 ) ;
if ( ( V_90 -> V_101 < 1 ) ||
( V_90 -> V_101 > V_138 ) ) {
F_4 ( V_2 , V_19 ,
L_18 ,
V_90 -> V_101 ) ;
* V_92 = - V_103 ;
return V_102 ;
}
switch ( V_90 -> V_99 ) {
case V_139 :
switch ( V_137 ) {
case V_140 :
V_95 = V_124 ;
break;
case V_141 :
V_95 = V_115 ;
break;
case V_142 :
V_95 = V_125 ;
break;
case V_143 :
V_95 = V_114 ;
break;
case V_144 :
if ( V_136 == 0xf )
V_95 = V_104 ;
else if ( V_136 == 0 )
V_95 = V_123 ;
break;
}
break;
case V_145 :
switch ( V_137 ) {
case V_140 :
V_95 = V_128 ;
break;
case V_141 :
V_95 = V_119 ;
break;
case V_142 :
V_95 = V_129 ;
break;
case V_143 :
V_95 = V_118 ;
break;
case V_146 :
V_95 = V_116 ;
break;
case V_147 :
V_95 = V_130 ;
break;
case ( V_147 | V_143 ) :
V_95 = V_120 ;
break;
case ( V_147 | V_142 ) :
V_95 = V_131 ;
break;
case V_144 :
if ( V_136 == 0 )
V_95 = V_122 ;
break;
}
break;
}
return V_95 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
struct V_50 V_51 ;
T_1 V_93 ;
struct V_148 * V_149 ;
T_2 V_150 = 0 ;
T_3 * V_151 = NULL ;
T_2 V_152 ;
T_2 V_153 ;
F_4 ( V_2 , V_19 , L_19 , V_154 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_152 = sizeof( struct V_148 ) ;
memset ( & V_2 -> V_66 , 0 , V_152 ) ;
if ( V_90 -> V_101 < V_152 ) {
F_4 ( V_2 , V_19 ,
L_20 ,
V_90 -> V_101 , V_152 ) ;
* V_92 = - V_155 ;
return V_39 ;
}
V_149 = (struct V_148 * ) V_91 ;
V_153 = V_90 -> V_101 - V_152 ;
V_150 = F_45 ( T_2 , V_153 , F_18 ( V_149 -> V_156 ) ) ;
if ( V_150 ) {
if ( ! V_2 -> V_157 . V_74 ) {
V_93 = F_27 ( V_2 , & V_2 -> V_157 ,
V_2 -> V_28 . V_158 ) ;
if ( V_93 )
F_4 ( V_2 , V_19 ,
L_21 ,
V_93 ) ;
}
if ( V_2 -> V_157 . V_74 ) {
V_151 = V_2 -> V_157 . V_74 ;
memcpy ( V_151 , & V_91 [ V_152 ] , V_153 ) ;
}
}
V_93 = F_46 ( V_2 , V_149 , V_151 ,
V_150 , & V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_22 ,
F_47 ( V_2 , V_93 ) ,
F_48 ( V_2 , V_2 -> V_28 . V_29 ) ) ;
* V_92 = F_39 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_2 V_159 ;
T_2 V_152 ;
int V_160 ;
T_3 * V_151 ;
F_4 ( V_2 , V_19 , L_19 , V_154 ) ;
V_152 = sizeof( struct V_148 ) ;
V_159 = V_152 + F_18 ( V_2 -> V_66 . V_156 ) ;
if ( V_90 -> V_36 > V_159 ) {
F_4 ( V_2 , V_19 , L_23 ,
V_154 , V_90 -> V_36 , V_159 ) ;
* V_92 = - V_155 ;
return V_39 ;
}
if ( V_90 -> V_101 > ( V_159 - V_90 -> V_36 ) ) {
int V_161 = V_159 - V_90 -> V_36 ;
F_4 ( V_2 , V_19 , L_24 ,
V_154 , V_90 -> V_101 , V_161 ) ;
V_90 -> V_101 = V_161 ;
}
V_160 = V_90 -> V_101 ;
if ( V_90 -> V_36 < V_152 ) {
T_2 V_162 = V_152 - V_90 -> V_36 ;
V_162 = F_22 ( V_162 , V_90 -> V_101 ) ;
F_4 ( V_2 , V_19 , L_25 ,
V_154 , V_90 -> V_36 , V_90 -> V_36 + V_162 ) ;
V_151 = ( ( T_3 * ) & V_2 -> V_66 ) + V_90 -> V_36 ;
memcpy ( V_91 , V_151 , V_162 ) ;
V_91 += V_162 ;
V_160 -= V_162 ;
V_151 = V_2 -> V_157 . V_74 ;
} else {
V_151 = V_2 -> V_157 . V_74 + ( V_90 -> V_36 - V_152 ) ;
}
if ( V_160 > 0 ) {
int V_163 = V_151 - ( T_3 * ) V_2 -> V_157 . V_74 ;
F_4 ( V_2 , V_19 , L_26 ,
V_154 , V_163 , V_163 + V_160 ) ;
memcpy ( V_91 , V_151 , V_160 ) ;
}
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
struct V_50 V_51 ;
T_1 V_93 ;
T_3 V_136 , V_137 ;
bool V_164 ;
V_137 = F_33 ( V_90 -> V_100 ) ;
V_136 = F_32 ( V_90 -> V_100 ) ;
V_164 = ( V_137 == V_142 ) || ( V_137 == V_143 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_93 = F_16 ( V_2 , V_136 , V_90 -> V_36 , ( T_5 ) V_90 -> V_101 ,
V_91 , V_164 , & V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_27 ,
V_136 , V_90 -> V_36 , V_90 -> V_101 ) ;
F_4 ( V_2 , V_19 ,
L_28 ,
V_93 , V_2 -> V_28 . V_29 ) ;
* V_92 = F_39 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
int * V_92 )
{
T_1 V_93 = 0 ;
struct V_50 V_51 ;
T_3 V_136 , V_137 ;
bool V_164 ;
V_137 = F_33 ( V_90 -> V_100 ) ;
V_136 = F_32 ( V_90 -> V_100 ) ;
V_164 = ( V_137 & V_142 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_93 = F_49 ( V_2 , V_136 , V_90 -> V_36 , ( T_5 ) V_90 -> V_101 ,
V_164 , & V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_29 ,
V_136 , V_90 -> V_36 , V_90 -> V_101 ) ;
F_4 ( V_2 , V_19 ,
L_30 ,
V_93 , V_2 -> V_28 . V_29 ) ;
* V_92 = F_39 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_3 * V_91 , int * V_92 )
{
T_1 V_93 = 0 ;
struct V_50 V_51 ;
T_3 V_136 , V_137 ;
bool V_164 ;
V_137 = F_33 ( V_90 -> V_100 ) ;
V_136 = F_32 ( V_90 -> V_100 ) ;
V_164 = ( V_137 & V_142 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_65 = & V_2 -> V_66 ;
V_93 = F_25 ( V_2 , V_136 , V_90 -> V_36 ,
( T_5 ) V_90 -> V_101 , V_91 , V_164 ,
& V_51 ) ;
if ( V_93 ) {
F_4 ( V_2 , V_19 ,
L_31 ,
V_136 , V_90 -> V_36 , V_90 -> V_101 ) ;
F_4 ( V_2 , V_19 ,
L_32 ,
V_93 , V_2 -> V_28 . V_29 ) ;
* V_92 = F_39 ( V_93 , V_2 -> V_28 . V_29 ) ;
}
return V_93 ;
}
