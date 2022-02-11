T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_5 = 0 ;
T_2 V_6 , V_7 ;
T_3 V_8 ;
V_7 = F_2 ( V_2 , V_9 ) ;
V_8 = ( ( V_7 & V_10 ) >>
V_11 ) ;
V_4 -> V_8 = ( 1 << V_8 ) * V_12 ;
V_6 = F_2 ( V_2 , V_13 ) ;
if ( V_6 & V_14 ) {
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = false ;
} else {
V_4 -> V_17 = true ;
V_5 = V_18 ;
F_3 ( V_2 , V_19 , L_1 ) ;
}
return V_5 ;
}
T_1 F_4 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
T_1 V_5 = 0 ;
T_4 V_22 , V_15 ;
T_4 V_23 = 0 ;
if ( V_2 -> V_4 . V_17 )
goto V_24;
V_5 = F_5 ( V_2 , V_25 , V_21 ,
0 , & V_23 , NULL ) ;
V_22 = F_2 ( V_2 , V_26 ) ;
V_2 -> V_4 . V_27 = F_6 ( V_23 ) + V_22 ;
if ( V_5 )
F_3 ( V_2 , V_19 ,
L_2 ,
V_21 , V_23 , V_5 , V_2 -> V_28 . V_29 ) ;
if ( V_5 && V_23 ) {
V_15 = F_6 ( V_16 ) + V_22 ;
while ( ( V_22 < V_15 ) && V_23 ) {
F_7 ( 10000 , 20000 ) ;
V_22 = F_2 ( V_2 , V_26 ) ;
V_5 = F_5 ( V_2 ,
V_25 ,
V_21 , 0 , & V_23 ,
NULL ) ;
if ( ! V_5 ) {
V_2 -> V_4 . V_27 =
F_6 ( V_23 ) + V_22 ;
break;
}
}
if ( V_5 ) {
V_2 -> V_4 . V_27 = 0 ;
F_3 ( V_2 , V_19 ,
L_3 ,
V_23 , V_5 , V_2 -> V_28 . V_29 ) ;
}
}
V_24:
return V_5 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_17 )
F_9 ( V_2 , V_25 , 0 , NULL ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_5 = V_30 ;
T_2 V_31 , V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 = F_2 ( V_2 , V_34 ) ;
if ( V_31 & V_35 ) {
V_5 = 0 ;
break;
}
F_11 ( 5 ) ;
}
if ( V_5 == V_30 )
F_3 ( V_2 , V_19 , L_4 ) ;
return V_5 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_37 )
{
T_1 V_5 = V_30 ;
T_2 V_38 ;
if ( V_36 >= V_2 -> V_4 . V_8 ) {
F_3 ( V_2 , V_19 ,
L_5 ,
V_36 , V_2 -> V_4 . V_8 ) ;
V_5 = V_39 ;
goto V_40;
}
V_5 = F_10 ( V_2 ) ;
if ( ! V_5 ) {
V_38 = ( T_2 ) ( V_36 << V_41 ) |
( 1 << V_42 ) ;
F_13 ( V_2 , V_34 , V_38 ) ;
V_5 = F_10 ( V_2 ) ;
if ( ! V_5 ) {
V_38 = F_2 ( V_2 , V_43 ) ;
* V_37 = ( T_5 ) ( ( V_38 &
V_44 )
>> V_45 ) ;
}
}
if ( V_5 )
F_3 ( V_2 , V_19 ,
L_6 ,
V_36 ) ;
V_40:
return V_5 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_37 )
{
return F_12 ( V_2 , V_36 , V_37 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_46 , T_5 * V_37 )
{
T_1 V_5 = 0 ;
T_5 V_47 , V_48 ;
for ( V_48 = 0 ; V_48 < * V_46 ; V_48 ++ ) {
V_47 = V_36 + V_48 ;
V_5 = F_12 ( V_2 , V_47 , & V_37 [ V_48 ] ) ;
if ( V_5 )
break;
}
* V_46 = V_48 ;
return V_5 ;
}
T_1 F_16 ( struct V_1 * V_2 , T_5 V_36 ,
T_5 * V_46 , T_5 * V_37 )
{
return F_15 ( V_2 , V_36 , V_46 , V_37 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_3 V_49 ,
T_2 V_36 , T_5 V_46 , void * V_37 ,
bool V_50 )
{
T_1 V_5 = V_51 ;
if ( ( V_36 + V_46 ) > V_2 -> V_4 . V_8 )
F_3 ( V_2 , V_19 ,
L_7 ,
( V_36 + V_46 ) , V_2 -> V_4 . V_8 ) ;
else if ( V_46 > V_52 )
F_3 ( V_2 , V_19 ,
L_8 ,
V_46 , V_52 ) ;
else if ( ( ( V_36 + ( V_46 - 1 ) ) / V_52 )
!= ( V_36 / V_52 ) )
F_3 ( V_2 , V_19 ,
L_9 ,
V_36 , V_46 ) ;
else
V_5 = F_18 ( V_2 , V_49 ,
2 * V_36 ,
2 * V_46 ,
V_37 , V_50 , NULL ) ;
return V_5 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
T_5 * V_53 )
{
T_1 V_5 = 0 ;
struct V_54 V_55 ;
T_5 V_56 = 0 ;
T_5 V_57 = 0 ;
T_5 V_58 = 0 ;
T_5 * V_37 ;
T_5 V_59 = 0 ;
V_5 = F_20 ( V_2 , & V_55 ,
V_52 * sizeof( T_5 ) ) ;
if ( V_5 )
goto V_60;
V_37 = ( T_5 * ) V_55 . V_61 ;
V_5 = F_14 ( V_2 , V_62 , & V_58 ) ;
if ( V_5 ) {
V_5 = V_63 ;
goto V_60;
}
V_5 = F_14 ( V_2 , V_64 ,
& V_56 ) ;
if ( V_5 ) {
V_5 = V_63 ;
goto V_60;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_4 . V_8 ; V_59 ++ ) {
if ( ( V_59 % V_52 ) == 0 ) {
T_5 V_46 = V_52 ;
V_5 = F_16 ( V_2 , V_59 , & V_46 , V_37 ) ;
if ( V_5 ) {
V_5 = V_63 ;
goto V_60;
}
}
if ( V_59 == V_65 )
continue;
if ( ( V_59 >= ( T_2 ) V_58 ) &&
( V_59 < ( ( T_2 ) V_58 +
( V_66 / 2 ) ) ) ) {
continue;
}
if ( ( V_59 >= ( T_2 ) V_56 ) &&
( V_59 < ( ( T_2 ) V_56 +
( V_67 / 2 ) ) ) ) {
continue;
}
V_57 += V_37 [ V_59 % V_52 ] ;
}
* V_53 = ( T_5 ) V_68 - V_57 ;
V_60:
F_21 ( V_2 , & V_55 ) ;
return V_5 ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
T_5 V_53 ;
V_5 = F_19 ( V_2 , & V_53 ) ;
if ( ! V_5 )
V_5 = F_17 ( V_2 , 0x00 , V_65 ,
1 , & V_53 , true ) ;
return V_5 ;
}
T_1 F_23 ( struct V_1 * V_2 ,
T_5 * V_53 )
{
T_1 V_5 = 0 ;
T_5 V_69 = 0 ;
T_5 V_57 = 0 ;
V_5 = F_19 ( V_2 , & V_57 ) ;
if ( V_5 )
goto V_70;
F_14 ( V_2 , V_65 , & V_69 ) ;
if ( V_57 != V_69 )
V_5 = V_63 ;
if ( V_53 )
* V_53 = V_57 ;
V_70:
return V_5 ;
}
static inline T_3 F_24 ( T_2 V_71 )
{
return ( T_3 ) ( V_71 & V_72 ) ;
}
static inline T_3 F_25 ( T_2 V_71 )
{
return ( T_3 ) ( ( V_71 & V_73 ) >> V_74 ) ;
}
T_1 F_26 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 * V_77 , int * V_78 )
{
T_1 V_79 ;
* V_78 = 0 ;
switch ( V_2 -> V_80 ) {
case V_81 :
V_79 = F_27 ( V_2 , V_76 , V_77 , V_78 ) ;
break;
case V_82 :
V_79 = F_28 ( V_2 , V_76 , V_77 , V_78 ) ;
break;
case V_83 :
V_79 = F_29 ( V_2 , V_76 , V_77 , V_78 ) ;
break;
default:
F_3 ( V_2 , V_19 ,
L_10 , V_2 -> V_80 ) ;
V_79 = V_84 ;
* V_78 = - V_85 ;
break;
}
return V_79 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 * V_77 , int * V_78 )
{
T_1 V_79 = 0 ;
enum V_86 V_87 ;
V_87 = F_30 ( V_2 , V_76 , V_78 ) ;
switch ( V_87 ) {
case V_88 :
V_79 = F_4 ( V_2 , V_89 ) ;
if ( V_79 ) {
* V_78 = F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_79 = F_32 ( V_2 , V_76 , V_77 , V_78 ) ;
F_8 ( V_2 ) ;
}
break;
case V_90 :
V_79 = F_4 ( V_2 , V_89 ) ;
if ( V_79 ) {
* V_78 = F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_79 = F_32 ( V_2 , V_76 , V_77 , V_78 ) ;
if ( V_79 )
F_8 ( V_2 ) ;
else
V_2 -> V_80 = V_82 ;
}
break;
case V_91 :
V_79 = F_4 ( V_2 , V_92 ) ;
if ( V_79 ) {
* V_78 = F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_79 = F_33 ( V_2 , V_76 , V_78 ) ;
if ( V_79 )
F_8 ( V_2 ) ;
else
V_2 -> V_28 . V_93 = true ;
}
break;
case V_94 :
V_79 = F_4 ( V_2 , V_92 ) ;
if ( V_79 ) {
* V_78 = F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_79 = F_34 ( V_2 , V_76 , V_77 , V_78 ) ;
if ( V_79 )
F_8 ( V_2 ) ;
else
V_2 -> V_28 . V_93 = true ;
}
break;
case V_95 :
V_79 = F_4 ( V_2 , V_92 ) ;
if ( V_79 ) {
* V_78 = F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_79 = F_34 ( V_2 , V_76 , V_77 , V_78 ) ;
if ( V_79 )
F_8 ( V_2 ) ;
else
V_2 -> V_80 = V_83 ;
}
break;
case V_96 :
V_79 = F_4 ( V_2 , V_92 ) ;
if ( V_79 ) {
* V_78 = F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_79 = F_22 ( V_2 ) ;
if ( V_79 ) {
* V_78 = V_2 -> V_28 . V_29 ?
F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) :
- V_97 ;
F_8 ( V_2 ) ;
} else {
V_2 -> V_28 . V_93 = true ;
}
}
break;
default:
F_3 ( V_2 , V_19 ,
L_11 ,
V_98 [ V_87 ] ) ;
V_79 = V_51 ;
* V_78 = - V_85 ;
break;
}
return V_79 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 * V_77 , int * V_78 )
{
T_1 V_79 ;
enum V_86 V_87 ;
V_87 = F_30 ( V_2 , V_76 , V_78 ) ;
switch ( V_87 ) {
case V_88 :
case V_99 :
V_79 = F_32 ( V_2 , V_76 , V_77 , V_78 ) ;
break;
case V_100 :
V_79 = F_32 ( V_2 , V_76 , V_77 , V_78 ) ;
F_8 ( V_2 ) ;
V_2 -> V_80 = V_81 ;
break;
default:
F_3 ( V_2 , V_19 ,
L_12 ,
V_98 [ V_87 ] ) ;
V_79 = V_84 ;
* V_78 = - V_85 ;
break;
}
return V_79 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 * V_77 , int * V_78 )
{
T_1 V_79 ;
enum V_86 V_87 ;
bool V_101 = false ;
V_87 = F_30 ( V_2 , V_76 , V_78 ) ;
V_102:
switch ( V_87 ) {
case V_103 :
V_79 = F_34 ( V_2 , V_76 , V_77 , V_78 ) ;
break;
case V_104 :
V_79 = F_34 ( V_2 , V_76 , V_77 , V_78 ) ;
if ( ! V_79 )
V_2 -> V_28 . V_93 = true ;
V_2 -> V_80 = V_81 ;
break;
case V_105 :
V_79 = F_22 ( V_2 ) ;
if ( V_79 ) {
* V_78 = V_2 -> V_28 . V_29 ?
F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) :
- V_97 ;
V_2 -> V_80 = V_81 ;
}
break;
case V_106 :
V_79 = F_22 ( V_2 ) ;
if ( V_79 )
* V_78 = V_2 -> V_28 . V_29 ?
F_31 ( V_79 ,
V_2 -> V_28 . V_29 ) :
- V_97 ;
else
V_2 -> V_28 . V_93 = true ;
V_2 -> V_80 = V_81 ;
break;
default:
F_3 ( V_2 , V_19 ,
L_13 ,
V_98 [ V_87 ] ) ;
V_79 = V_84 ;
* V_78 = - V_85 ;
break;
}
if ( V_79 && ( V_2 -> V_28 . V_29 == V_107 ) &&
! V_101 ) {
T_1 V_108 = V_79 ;
T_2 V_109 = V_2 -> V_28 . V_29 ;
T_2 V_22 ;
V_22 = F_2 ( V_2 , V_26 ) ;
if ( V_22 >= V_2 -> V_4 . V_27 ) {
F_3 ( V_2 , V_110 ,
L_14 ,
V_22 , V_2 -> V_4 . V_27 ) ;
F_8 ( V_2 ) ;
V_79 = F_4 ( V_2 , V_92 ) ;
if ( V_79 ) {
F_3 ( V_2 , V_110 ,
L_15 ,
V_2 -> V_28 . V_29 ) ;
V_79 = V_108 ;
V_2 -> V_28 . V_29 = V_109 ;
} else {
V_101 = true ;
goto V_102;
}
}
}
return V_79 ;
}
static enum V_86 F_30 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
int * V_78 )
{
enum V_86 V_87 ;
T_3 V_111 ;
V_87 = V_112 ;
V_111 = F_25 ( V_76 -> V_113 ) ;
if ( ( V_76 -> V_114 < 1 ) ||
( V_76 -> V_114 > V_115 ) ) {
F_3 ( V_2 , V_19 ,
L_16 ,
V_76 -> V_114 ) ;
* V_78 = - V_116 ;
return V_112 ;
}
switch ( V_76 -> V_117 ) {
case V_118 :
switch ( V_111 ) {
case V_119 :
V_87 = V_99 ;
break;
case V_120 :
V_87 = V_90 ;
break;
case V_121 :
V_87 = V_100 ;
break;
case V_122 :
V_87 = V_88 ;
break;
}
break;
case V_123 :
switch ( V_111 ) {
case V_119 :
V_87 = V_103 ;
break;
case V_120 :
V_87 = V_95 ;
break;
case V_121 :
V_87 = V_104 ;
break;
case V_122 :
V_87 = V_94 ;
break;
case V_124 :
V_87 = V_91 ;
break;
case V_125 :
V_87 = V_105 ;
break;
case ( V_125 | V_122 ) :
V_87 = V_96 ;
break;
case ( V_125 | V_121 ) :
V_87 = V_106 ;
break;
}
break;
}
F_3 ( V_2 , V_19 , L_17 ,
V_98 [ V_87 ] ,
V_2 -> V_80 ,
V_2 -> V_28 . V_93 ) ;
if ( V_87 == V_112 ) {
* V_78 = - V_116 ;
F_3 ( V_2 , V_19 ,
L_18 ,
V_87 , * V_78 ) ;
}
return V_87 ;
}
static T_1 F_32 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 * V_77 , int * V_78 )
{
T_1 V_79 ;
T_3 V_126 , V_111 ;
bool V_127 ;
V_111 = F_25 ( V_76 -> V_113 ) ;
V_126 = F_24 ( V_76 -> V_113 ) ;
V_127 = ( V_111 == V_121 ) || ( V_111 == V_122 ) ;
V_79 = F_35 ( V_2 , V_126 , V_76 -> V_36 , ( T_5 ) V_76 -> V_114 ,
V_77 , V_127 , NULL ) ;
if ( V_79 ) {
F_3 ( V_2 , V_19 ,
L_19 ,
V_126 , V_76 -> V_36 , V_76 -> V_114 ) ;
F_3 ( V_2 , V_19 ,
L_20 ,
V_79 , V_2 -> V_28 . V_29 ) ;
* V_78 = F_31 ( V_79 , V_2 -> V_28 . V_29 ) ;
}
return V_79 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
int * V_78 )
{
T_1 V_79 = 0 ;
T_3 V_126 , V_111 ;
bool V_127 ;
V_111 = F_25 ( V_76 -> V_113 ) ;
V_126 = F_24 ( V_76 -> V_113 ) ;
V_127 = ( V_111 & V_121 ) ;
V_79 = F_36 ( V_2 , V_126 , V_76 -> V_36 , ( T_5 ) V_76 -> V_114 ,
V_127 , NULL ) ;
if ( V_79 ) {
F_3 ( V_2 , V_19 ,
L_21 ,
V_126 , V_76 -> V_36 , V_76 -> V_114 ) ;
F_3 ( V_2 , V_19 ,
L_22 ,
V_79 , V_2 -> V_28 . V_29 ) ;
* V_78 = F_31 ( V_79 , V_2 -> V_28 . V_29 ) ;
}
return V_79 ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 * V_77 , int * V_78 )
{
T_1 V_79 = 0 ;
T_3 V_126 , V_111 ;
bool V_127 ;
V_111 = F_25 ( V_76 -> V_113 ) ;
V_126 = F_24 ( V_76 -> V_113 ) ;
V_127 = ( V_111 & V_121 ) ;
V_79 = F_18 ( V_2 , V_126 , V_76 -> V_36 ,
( T_5 ) V_76 -> V_114 , V_77 , V_127 , NULL ) ;
if ( V_79 ) {
F_3 ( V_2 , V_19 ,
L_23 ,
V_126 , V_76 -> V_36 , V_76 -> V_114 ) ;
F_3 ( V_2 , V_19 ,
L_24 ,
V_79 , V_2 -> V_28 . V_29 ) ;
* V_78 = F_31 ( V_79 , V_2 -> V_28 . V_29 ) ;
}
return V_79 ;
}
