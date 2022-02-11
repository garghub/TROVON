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
T_1 F_12 ( struct V_1 * V_2 , T_5 V_36 ,
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
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_49 ,
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
V_5 = F_16 ( V_2 , V_49 ,
2 * V_36 ,
2 * V_46 ,
V_37 , V_50 , NULL ) ;
return V_5 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
T_5 * V_53 )
{
T_1 V_5 = 0 ;
T_5 V_54 = 0 ;
T_5 V_55 = 0 ;
T_5 V_56 = 0 ;
T_5 V_48 = 0 ;
T_2 V_57 = 0 ;
V_5 = F_12 ( V_2 , V_58 , & V_56 ) ;
if ( V_5 ) {
V_5 = V_59 ;
goto V_60;
}
V_5 = F_12 ( V_2 , V_61 ,
& V_54 ) ;
if ( V_5 ) {
V_5 = V_59 ;
goto V_60;
}
for ( V_57 = 0 ; V_57 < V_2 -> V_4 . V_8 ; V_57 ++ ) {
if ( V_57 == V_62 )
V_57 ++ ;
if ( V_57 == ( T_2 ) V_56 ) {
V_57 += ( V_63 / 2 ) ;
if ( V_57 >= V_2 -> V_4 . V_8 )
break;
}
if ( V_57 == ( T_2 ) V_54 ) {
V_57 += ( V_64 / 2 ) ;
if ( V_57 >= V_2 -> V_4 . V_8 )
break;
}
V_5 = F_12 ( V_2 , ( T_5 ) V_57 , & V_48 ) ;
if ( V_5 ) {
V_5 = V_59 ;
goto V_60;
}
V_55 += V_48 ;
}
* V_53 = ( T_5 ) V_65 - V_55 ;
V_60:
return V_5 ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
T_5 V_53 ;
V_5 = F_17 ( V_2 , & V_53 ) ;
if ( ! V_5 )
V_5 = F_15 ( V_2 , 0x00 , V_62 ,
1 , & V_53 , true ) ;
return V_5 ;
}
T_1 F_19 ( struct V_1 * V_2 ,
T_5 * V_53 )
{
T_1 V_5 = 0 ;
T_5 V_66 = 0 ;
T_5 V_55 = 0 ;
V_5 = F_17 ( V_2 , & V_55 ) ;
if ( V_5 )
goto V_67;
F_12 ( V_2 , V_62 , & V_66 ) ;
if ( V_55 != V_66 )
V_5 = V_59 ;
if ( V_53 )
* V_53 = V_55 ;
V_67:
return V_5 ;
}
static inline T_3 F_20 ( T_2 V_68 )
{
return ( T_3 ) ( V_68 & V_69 ) ;
}
static inline T_3 F_21 ( T_2 V_68 )
{
return ( T_3 ) ( ( V_68 & V_70 ) >> V_71 ) ;
}
T_1 F_22 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
T_3 * V_74 , int * V_75 )
{
T_1 V_76 ;
* V_75 = 0 ;
switch ( V_2 -> V_77 ) {
case V_78 :
V_76 = F_23 ( V_2 , V_73 , V_74 , V_75 ) ;
break;
case V_79 :
V_76 = F_24 ( V_2 , V_73 , V_74 , V_75 ) ;
break;
case V_80 :
V_76 = F_25 ( V_2 , V_73 , V_74 , V_75 ) ;
break;
default:
F_3 ( V_2 , V_19 ,
L_10 , V_2 -> V_77 ) ;
V_76 = V_81 ;
* V_75 = - V_82 ;
break;
}
return V_76 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
T_3 * V_74 , int * V_75 )
{
T_1 V_76 = 0 ;
enum V_83 V_84 ;
V_84 = F_26 ( V_2 , V_73 , V_75 ) ;
switch ( V_84 ) {
case V_85 :
V_76 = F_4 ( V_2 , V_86 ) ;
if ( V_76 ) {
* V_75 = F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_76 = F_28 ( V_2 , V_73 , V_74 , V_75 ) ;
F_8 ( V_2 ) ;
}
break;
case V_87 :
V_76 = F_4 ( V_2 , V_86 ) ;
if ( V_76 ) {
* V_75 = F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_76 = F_28 ( V_2 , V_73 , V_74 , V_75 ) ;
if ( V_76 )
F_8 ( V_2 ) ;
else
V_2 -> V_77 = V_79 ;
}
break;
case V_88 :
V_76 = F_4 ( V_2 , V_89 ) ;
if ( V_76 ) {
* V_75 = F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_76 = F_29 ( V_2 , V_73 , V_75 ) ;
if ( V_76 )
F_8 ( V_2 ) ;
else
V_2 -> V_28 . V_90 = true ;
}
break;
case V_91 :
V_76 = F_4 ( V_2 , V_89 ) ;
if ( V_76 ) {
* V_75 = F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_76 = F_30 ( V_2 , V_73 , V_74 , V_75 ) ;
if ( V_76 )
F_8 ( V_2 ) ;
else
V_2 -> V_28 . V_90 = true ;
}
break;
case V_92 :
V_76 = F_4 ( V_2 , V_89 ) ;
if ( V_76 ) {
* V_75 = F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_76 = F_30 ( V_2 , V_73 , V_74 , V_75 ) ;
if ( V_76 )
F_8 ( V_2 ) ;
else
V_2 -> V_77 = V_80 ;
}
break;
case V_93 :
V_76 = F_4 ( V_2 , V_89 ) ;
if ( V_76 ) {
* V_75 = F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) ;
} else {
V_76 = F_18 ( V_2 ) ;
if ( V_76 ) {
* V_75 = V_2 -> V_28 . V_29 ?
F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) :
- V_94 ;
F_8 ( V_2 ) ;
} else {
V_2 -> V_28 . V_90 = true ;
}
}
break;
default:
F_3 ( V_2 , V_19 ,
L_11 ,
V_95 [ V_84 ] ) ;
V_76 = V_51 ;
* V_75 = - V_82 ;
break;
}
return V_76 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
T_3 * V_74 , int * V_75 )
{
T_1 V_76 ;
enum V_83 V_84 ;
V_84 = F_26 ( V_2 , V_73 , V_75 ) ;
switch ( V_84 ) {
case V_85 :
case V_96 :
V_76 = F_28 ( V_2 , V_73 , V_74 , V_75 ) ;
break;
case V_97 :
V_76 = F_28 ( V_2 , V_73 , V_74 , V_75 ) ;
F_8 ( V_2 ) ;
V_2 -> V_77 = V_78 ;
break;
default:
F_3 ( V_2 , V_19 ,
L_12 ,
V_95 [ V_84 ] ) ;
V_76 = V_81 ;
* V_75 = - V_82 ;
break;
}
return V_76 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
T_3 * V_74 , int * V_75 )
{
T_1 V_76 ;
enum V_83 V_84 ;
bool V_98 = false ;
V_84 = F_26 ( V_2 , V_73 , V_75 ) ;
V_99:
switch ( V_84 ) {
case V_100 :
V_76 = F_30 ( V_2 , V_73 , V_74 , V_75 ) ;
break;
case V_101 :
V_76 = F_30 ( V_2 , V_73 , V_74 , V_75 ) ;
if ( ! V_76 )
V_2 -> V_28 . V_90 = true ;
V_2 -> V_77 = V_78 ;
break;
case V_102 :
V_76 = F_18 ( V_2 ) ;
if ( V_76 ) {
* V_75 = V_2 -> V_28 . V_29 ?
F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) :
- V_94 ;
V_2 -> V_77 = V_78 ;
}
break;
case V_103 :
V_76 = F_18 ( V_2 ) ;
if ( V_76 )
* V_75 = V_2 -> V_28 . V_29 ?
F_27 ( V_76 ,
V_2 -> V_28 . V_29 ) :
- V_94 ;
else
V_2 -> V_28 . V_90 = true ;
V_2 -> V_77 = V_78 ;
break;
default:
F_3 ( V_2 , V_19 ,
L_13 ,
V_95 [ V_84 ] ) ;
V_76 = V_81 ;
* V_75 = - V_82 ;
break;
}
if ( V_76 && ( V_2 -> V_28 . V_29 == V_104 ) &&
! V_98 ) {
T_1 V_105 = V_76 ;
T_2 V_106 = V_2 -> V_28 . V_29 ;
T_2 V_22 ;
V_22 = F_2 ( V_2 , V_26 ) ;
if ( V_22 >= V_2 -> V_4 . V_27 ) {
F_3 ( V_2 , V_107 ,
L_14 ,
V_22 , V_2 -> V_4 . V_27 ) ;
F_8 ( V_2 ) ;
V_76 = F_4 ( V_2 , V_89 ) ;
if ( V_76 ) {
F_3 ( V_2 , V_107 ,
L_15 ,
V_2 -> V_28 . V_29 ) ;
V_76 = V_105 ;
V_2 -> V_28 . V_29 = V_106 ;
} else {
V_98 = true ;
goto V_99;
}
}
}
return V_76 ;
}
static enum V_83 F_26 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
int * V_75 )
{
enum V_83 V_84 ;
T_3 V_108 , V_109 ;
V_84 = V_110 ;
V_108 = F_21 ( V_73 -> V_111 ) ;
V_109 = F_20 ( V_73 -> V_111 ) ;
if ( ( V_73 -> V_112 < 1 ) ||
( V_73 -> V_112 > V_113 ) ) {
F_3 ( V_2 , V_19 ,
L_16 ,
V_73 -> V_112 ) ;
* V_75 = - V_114 ;
return V_110 ;
}
switch ( V_73 -> V_115 ) {
case V_116 :
switch ( V_108 ) {
case V_117 :
V_84 = V_96 ;
break;
case V_118 :
V_84 = V_87 ;
break;
case V_119 :
V_84 = V_97 ;
break;
case V_120 :
V_84 = V_85 ;
break;
}
break;
case V_121 :
switch ( V_108 ) {
case V_117 :
V_84 = V_100 ;
break;
case V_118 :
V_84 = V_92 ;
break;
case V_119 :
V_84 = V_101 ;
break;
case V_120 :
V_84 = V_91 ;
break;
case V_122 :
V_84 = V_88 ;
break;
case V_123 :
V_84 = V_102 ;
break;
case ( V_123 | V_120 ) :
V_84 = V_93 ;
break;
case ( V_123 | V_119 ) :
V_84 = V_103 ;
break;
}
break;
}
F_3 ( V_2 , V_19 , L_17 ,
V_95 [ V_84 ] ,
V_2 -> V_77 ,
V_2 -> V_28 . V_90 ) ;
if ( V_84 == V_110 ) {
* V_75 = - V_114 ;
F_3 ( V_2 , V_19 ,
L_18 ,
V_84 , * V_75 ) ;
}
return V_84 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
T_3 * V_74 , int * V_75 )
{
T_1 V_76 ;
T_3 V_109 , V_108 ;
bool V_124 ;
V_108 = F_21 ( V_73 -> V_111 ) ;
V_109 = F_20 ( V_73 -> V_111 ) ;
V_124 = ( V_108 == V_119 ) || ( V_108 == V_120 ) ;
V_76 = F_31 ( V_2 , V_109 , V_73 -> V_36 , ( T_5 ) V_73 -> V_112 ,
V_74 , V_124 , NULL ) ;
if ( V_76 ) {
F_3 ( V_2 , V_19 ,
L_19 ,
V_109 , V_73 -> V_36 , V_73 -> V_112 ) ;
F_3 ( V_2 , V_19 ,
L_20 ,
V_76 , V_2 -> V_28 . V_29 ) ;
* V_75 = F_27 ( V_76 , V_2 -> V_28 . V_29 ) ;
}
return V_76 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
int * V_75 )
{
T_1 V_76 = 0 ;
T_3 V_109 , V_108 ;
bool V_124 ;
V_108 = F_21 ( V_73 -> V_111 ) ;
V_109 = F_20 ( V_73 -> V_111 ) ;
V_124 = ( V_108 & V_119 ) ;
V_76 = F_32 ( V_2 , V_109 , V_73 -> V_36 , ( T_5 ) V_73 -> V_112 ,
V_124 , NULL ) ;
if ( V_76 ) {
F_3 ( V_2 , V_19 ,
L_21 ,
V_109 , V_73 -> V_36 , V_73 -> V_112 ) ;
F_3 ( V_2 , V_19 ,
L_22 ,
V_76 , V_2 -> V_28 . V_29 ) ;
* V_75 = F_27 ( V_76 , V_2 -> V_28 . V_29 ) ;
}
return V_76 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
T_3 * V_74 , int * V_75 )
{
T_1 V_76 = 0 ;
T_3 V_109 , V_108 ;
bool V_124 ;
V_108 = F_21 ( V_73 -> V_111 ) ;
V_109 = F_20 ( V_73 -> V_111 ) ;
V_124 = ( V_108 & V_119 ) ;
V_76 = F_16 ( V_2 , V_109 , V_73 -> V_36 ,
( T_5 ) V_73 -> V_112 , V_74 , V_124 , NULL ) ;
if ( V_76 ) {
F_3 ( V_2 , V_19 ,
L_23 ,
V_109 , V_73 -> V_36 , V_73 -> V_112 ) ;
F_3 ( V_2 , V_19 ,
L_24 ,
V_76 , V_2 -> V_28 . V_29 ) ;
* V_75 = F_27 ( V_76 , V_2 -> V_28 . V_29 ) ;
}
return V_76 ;
}
