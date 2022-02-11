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
if ( V_2 -> V_54 . type == V_55 )
return F_17 ( V_2 , V_36 , V_37 ) ;
return F_13 ( V_2 , V_36 , V_37 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_47 , T_5 * V_37 )
{
T_1 V_5 = 0 ;
T_5 V_56 , V_57 ;
for ( V_57 = 0 ; V_57 < * V_47 ; V_57 ++ ) {
V_56 = V_36 + V_57 ;
V_5 = F_13 ( V_2 , V_56 , & V_37 [ V_57 ] ) ;
if ( V_5 )
break;
}
* V_47 = V_57 ;
return V_5 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_47 , T_5 * V_37 )
{
T_1 V_5 ;
T_5 V_58 = * V_47 ;
bool V_59 = false ;
T_5 V_60 = 0 ;
T_5 V_61 = 0 ;
do {
if ( V_36 % V_52 )
V_58 = F_22 ( * V_47 ,
( T_5 ) ( V_52 -
( V_36 % V_52 ) ) ) ;
else
V_58 = F_22 ( ( * V_47 - V_60 ) ,
V_52 ) ;
if ( ( V_60 + V_58 ) >= * V_47 )
V_59 = true ;
V_5 = F_15 ( V_2 , 0x0 , V_36 , V_58 ,
V_37 + V_60 , V_59 ) ;
if ( V_5 )
goto V_62;
V_60 += V_58 ;
V_36 += V_58 ;
} while ( V_60 < * V_47 );
for ( V_61 = 0 ; V_61 < * V_47 ; V_61 ++ )
V_37 [ V_61 ] = F_18 ( ( ( V_53 * ) V_37 ) [ V_61 ] ) ;
V_62:
* V_47 = V_60 ;
return V_5 ;
}
T_1 F_23 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_47 , T_5 * V_37 )
{
if ( V_2 -> V_54 . type == V_55 )
return F_21 ( V_2 , V_36 , V_47 , V_37 ) ;
return F_20 ( V_2 , V_36 , V_47 , V_37 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_3 V_46 ,
T_2 V_36 , T_5 V_47 , void * V_37 ,
bool V_48 )
{
T_1 V_5 = V_49 ;
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
V_37 , V_48 , NULL ) ;
return V_5 ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
T_5 * V_63 )
{
T_1 V_5 = 0 ;
struct V_64 V_65 ;
T_5 V_66 = 0 ;
T_5 V_67 = 0 ;
T_5 V_68 = 0 ;
T_5 * V_37 ;
T_5 V_61 = 0 ;
V_5 = F_27 ( V_2 , & V_65 ,
V_52 * sizeof( T_5 ) ) ;
if ( V_5 )
goto V_69;
V_37 = ( T_5 * ) V_65 . V_70 ;
V_5 = F_19 ( V_2 , V_71 , & V_68 ) ;
if ( V_5 ) {
V_5 = V_72 ;
goto V_69;
}
V_5 = F_19 ( V_2 , V_73 ,
& V_66 ) ;
if ( V_5 ) {
V_5 = V_72 ;
goto V_69;
}
for ( V_61 = 0 ; V_61 < V_2 -> V_4 . V_8 ; V_61 ++ ) {
if ( ( V_61 % V_52 ) == 0 ) {
T_5 V_47 = V_52 ;
V_5 = F_23 ( V_2 , V_61 , & V_47 , V_37 ) ;
if ( V_5 ) {
V_5 = V_72 ;
goto V_69;
}
}
if ( V_61 == V_74 )
continue;
if ( ( V_61 >= ( T_2 ) V_68 ) &&
( V_61 < ( ( T_2 ) V_68 +
( V_75 / 2 ) ) ) ) {
continue;
}
if ( ( V_61 >= ( T_2 ) V_66 ) &&
( V_61 < ( ( T_2 ) V_66 +
( V_76 / 2 ) ) ) ) {
continue;
}
V_67 += V_37 [ V_61 % V_52 ] ;
}
* V_63 = ( T_5 ) V_77 - V_67 ;
V_69:
F_28 ( V_2 , & V_65 ) ;
return V_5 ;
}
T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
T_5 V_63 ;
V_5 = F_26 ( V_2 , & V_63 ) ;
if ( ! V_5 )
V_5 = F_24 ( V_2 , 0x00 , V_74 ,
1 , & V_63 , true ) ;
return V_5 ;
}
T_1 F_30 ( struct V_1 * V_2 ,
T_5 * V_63 )
{
T_1 V_5 = 0 ;
T_5 V_78 = 0 ;
T_5 V_67 = 0 ;
V_5 = F_26 ( V_2 , & V_67 ) ;
if ( V_5 )
goto V_79;
F_19 ( V_2 , V_74 , & V_78 ) ;
if ( V_67 != V_78 )
V_5 = V_72 ;
if ( V_63 )
* V_63 = V_67 ;
V_79:
return V_5 ;
}
static inline T_3 F_31 ( T_2 V_80 )
{
return ( T_3 ) ( V_80 & V_81 ) ;
}
static inline T_3 F_32 ( T_2 V_80 )
{
return ( T_3 ) ( ( V_80 & V_82 ) >> V_83 ) ;
}
T_1 F_33 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_86 , int * V_87 )
{
T_1 V_88 ;
* V_87 = 0 ;
switch ( V_2 -> V_89 ) {
case V_90 :
V_88 = F_34 ( V_2 , V_85 , V_86 , V_87 ) ;
break;
case V_91 :
V_88 = F_35 ( V_2 , V_85 , V_86 , V_87 ) ;
break;
case V_92 :
V_88 = F_36 ( V_2 , V_85 , V_86 , V_87 ) ;
break;
default:
F_4 ( V_2 , V_19 ,
L_10 , V_2 -> V_89 ) ;
V_88 = V_93 ;
* V_87 = - V_94 ;
break;
}
return V_88 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_86 , int * V_87 )
{
T_1 V_88 = 0 ;
enum V_95 V_96 ;
V_96 = F_37 ( V_2 , V_85 , V_87 ) ;
switch ( V_96 ) {
case V_97 :
V_88 = F_5 ( V_2 , V_98 ) ;
if ( V_88 ) {
* V_87 = F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_88 = F_39 ( V_2 , V_85 , V_86 , V_87 ) ;
F_9 ( V_2 ) ;
}
break;
case V_99 :
V_88 = F_5 ( V_2 , V_98 ) ;
if ( V_88 ) {
* V_87 = F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_88 = F_39 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_88 )
F_9 ( V_2 ) ;
else
V_2 -> V_89 = V_91 ;
}
break;
case V_100 :
V_88 = F_5 ( V_2 , V_101 ) ;
if ( V_88 ) {
* V_87 = F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_88 = F_40 ( V_2 , V_85 , V_87 ) ;
if ( V_88 )
F_9 ( V_2 ) ;
else
V_2 -> V_28 . V_102 = true ;
}
break;
case V_103 :
V_88 = F_5 ( V_2 , V_101 ) ;
if ( V_88 ) {
* V_87 = F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_88 = F_41 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_88 )
F_9 ( V_2 ) ;
else
V_2 -> V_28 . V_102 = true ;
}
break;
case V_104 :
V_88 = F_5 ( V_2 , V_101 ) ;
if ( V_88 ) {
* V_87 = F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_88 = F_41 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_88 )
F_9 ( V_2 ) ;
else
V_2 -> V_89 = V_92 ;
}
break;
case V_105 :
V_88 = F_5 ( V_2 , V_101 ) ;
if ( V_88 ) {
* V_87 = F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_88 = F_29 ( V_2 ) ;
if ( V_88 ) {
* V_87 = V_2 -> V_28 . V_29 ?
F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) :
- V_106 ;
F_9 ( V_2 ) ;
} else {
V_2 -> V_28 . V_102 = true ;
}
}
break;
default:
F_4 ( V_2 , V_19 ,
L_11 ,
V_107 [ V_96 ] ) ;
V_88 = V_49 ;
* V_87 = - V_94 ;
break;
}
return V_88 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_86 , int * V_87 )
{
T_1 V_88 ;
enum V_95 V_96 ;
V_96 = F_37 ( V_2 , V_85 , V_87 ) ;
switch ( V_96 ) {
case V_97 :
case V_108 :
V_88 = F_39 ( V_2 , V_85 , V_86 , V_87 ) ;
break;
case V_109 :
V_88 = F_39 ( V_2 , V_85 , V_86 , V_87 ) ;
F_9 ( V_2 ) ;
V_2 -> V_89 = V_90 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_12 ,
V_107 [ V_96 ] ) ;
V_88 = V_93 ;
* V_87 = - V_94 ;
break;
}
return V_88 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_86 , int * V_87 )
{
T_1 V_88 ;
enum V_95 V_96 ;
bool V_110 = false ;
V_96 = F_37 ( V_2 , V_85 , V_87 ) ;
V_111:
switch ( V_96 ) {
case V_112 :
V_88 = F_41 ( V_2 , V_85 , V_86 , V_87 ) ;
break;
case V_113 :
V_88 = F_41 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( ! V_88 )
V_2 -> V_28 . V_102 = true ;
V_2 -> V_89 = V_90 ;
break;
case V_114 :
V_88 = F_29 ( V_2 ) ;
if ( V_88 ) {
* V_87 = V_2 -> V_28 . V_29 ?
F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) :
- V_106 ;
V_2 -> V_89 = V_90 ;
}
break;
case V_115 :
V_88 = F_29 ( V_2 ) ;
if ( V_88 )
* V_87 = V_2 -> V_28 . V_29 ?
F_38 ( V_88 ,
V_2 -> V_28 . V_29 ) :
- V_106 ;
else
V_2 -> V_28 . V_102 = true ;
V_2 -> V_89 = V_90 ;
break;
default:
F_4 ( V_2 , V_19 ,
L_13 ,
V_107 [ V_96 ] ) ;
V_88 = V_93 ;
* V_87 = - V_94 ;
break;
}
if ( V_88 && ( V_2 -> V_28 . V_29 == V_116 ) &&
! V_110 ) {
T_1 V_117 = V_88 ;
T_2 V_118 = V_2 -> V_28 . V_29 ;
T_2 V_22 ;
V_22 = F_2 ( V_2 , V_26 ) ;
if ( V_22 >= V_2 -> V_4 . V_27 ) {
F_4 ( V_2 , V_119 ,
L_14 ,
V_22 , V_2 -> V_4 . V_27 ) ;
F_9 ( V_2 ) ;
V_88 = F_5 ( V_2 , V_101 ) ;
if ( V_88 ) {
F_4 ( V_2 , V_119 ,
L_15 ,
V_2 -> V_28 . V_29 ) ;
V_88 = V_117 ;
V_2 -> V_28 . V_29 = V_118 ;
} else {
V_110 = true ;
goto V_111;
}
}
}
return V_88 ;
}
static enum V_95 F_37 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
int * V_87 )
{
enum V_95 V_96 ;
T_3 V_120 ;
V_96 = V_121 ;
V_120 = F_32 ( V_85 -> V_122 ) ;
if ( ( V_85 -> V_123 < 1 ) ||
( V_85 -> V_123 > V_124 ) ) {
F_4 ( V_2 , V_19 ,
L_16 ,
V_85 -> V_123 ) ;
* V_87 = - V_125 ;
return V_121 ;
}
switch ( V_85 -> V_126 ) {
case V_127 :
switch ( V_120 ) {
case V_128 :
V_96 = V_108 ;
break;
case V_129 :
V_96 = V_99 ;
break;
case V_130 :
V_96 = V_109 ;
break;
case V_131 :
V_96 = V_97 ;
break;
}
break;
case V_132 :
switch ( V_120 ) {
case V_128 :
V_96 = V_112 ;
break;
case V_129 :
V_96 = V_104 ;
break;
case V_130 :
V_96 = V_113 ;
break;
case V_131 :
V_96 = V_103 ;
break;
case V_133 :
V_96 = V_100 ;
break;
case V_134 :
V_96 = V_114 ;
break;
case ( V_134 | V_131 ) :
V_96 = V_105 ;
break;
case ( V_134 | V_130 ) :
V_96 = V_115 ;
break;
}
break;
}
F_4 ( V_2 , V_19 , L_17 ,
V_107 [ V_96 ] ,
V_2 -> V_89 ,
V_2 -> V_28 . V_102 ) ;
if ( V_96 == V_121 ) {
* V_87 = - V_125 ;
F_4 ( V_2 , V_19 ,
L_18 ,
V_96 , * V_87 ) ;
}
return V_96 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_86 , int * V_87 )
{
T_1 V_88 ;
T_3 V_135 , V_120 ;
bool V_136 ;
V_120 = F_32 ( V_85 -> V_122 ) ;
V_135 = F_31 ( V_85 -> V_122 ) ;
V_136 = ( V_120 == V_130 ) || ( V_120 == V_131 ) ;
V_88 = F_16 ( V_2 , V_135 , V_85 -> V_36 , ( T_5 ) V_85 -> V_123 ,
V_86 , V_136 , NULL ) ;
if ( V_88 ) {
F_4 ( V_2 , V_19 ,
L_19 ,
V_135 , V_85 -> V_36 , V_85 -> V_123 ) ;
F_4 ( V_2 , V_19 ,
L_20 ,
V_88 , V_2 -> V_28 . V_29 ) ;
* V_87 = F_38 ( V_88 , V_2 -> V_28 . V_29 ) ;
}
return V_88 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
int * V_87 )
{
T_1 V_88 = 0 ;
T_3 V_135 , V_120 ;
bool V_136 ;
V_120 = F_32 ( V_85 -> V_122 ) ;
V_135 = F_31 ( V_85 -> V_122 ) ;
V_136 = ( V_120 & V_130 ) ;
V_88 = F_42 ( V_2 , V_135 , V_85 -> V_36 , ( T_5 ) V_85 -> V_123 ,
V_136 , NULL ) ;
if ( V_88 ) {
F_4 ( V_2 , V_19 ,
L_21 ,
V_135 , V_85 -> V_36 , V_85 -> V_123 ) ;
F_4 ( V_2 , V_19 ,
L_22 ,
V_88 , V_2 -> V_28 . V_29 ) ;
* V_87 = F_38 ( V_88 , V_2 -> V_28 . V_29 ) ;
}
return V_88 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_86 , int * V_87 )
{
T_1 V_88 = 0 ;
T_3 V_135 , V_120 ;
bool V_136 ;
V_120 = F_32 ( V_85 -> V_122 ) ;
V_135 = F_31 ( V_85 -> V_122 ) ;
V_136 = ( V_120 & V_130 ) ;
V_88 = F_25 ( V_2 , V_135 , V_85 -> V_36 ,
( T_5 ) V_85 -> V_123 , V_86 , V_136 , NULL ) ;
if ( V_88 ) {
F_4 ( V_2 , V_19 ,
L_23 ,
V_135 , V_85 -> V_36 , V_85 -> V_123 ) ;
F_4 ( V_2 , V_19 ,
L_24 ,
V_88 , V_2 -> V_28 . V_29 ) ;
* V_87 = F_38 ( V_88 , V_2 -> V_28 . V_29 ) ;
}
return V_88 ;
}
