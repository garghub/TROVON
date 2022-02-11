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
F_3 ( V_2 , L_1 ) ;
}
return V_5 ;
}
T_1 F_4 ( struct V_1 * V_2 ,
enum V_19 V_20 )
{
T_1 V_5 = 0 ;
T_4 V_21 , V_15 ;
T_4 time = 0 ;
if ( V_2 -> V_4 . V_17 )
goto V_22;
V_5 = F_5 ( V_2 , V_23 , V_20 ,
0 , & time , NULL ) ;
V_21 = F_2 ( V_2 , V_24 ) ;
V_2 -> V_4 . V_25 = F_6 ( time ) + V_21 ;
if ( V_5 ) {
if ( time > V_16 )
V_15 = F_6 ( V_16 )
+ V_21 ;
else
V_15 = V_2 -> V_4 . V_25 ;
while ( V_21 < V_15 ) {
F_7 ( 10000 , 20000 ) ;
V_5 = F_5 ( V_2 ,
V_23 ,
V_20 , 0 , & time ,
NULL ) ;
if ( ! V_5 ) {
V_2 -> V_4 . V_25 =
F_6 ( time ) + V_21 ;
break;
}
V_21 = F_2 ( V_2 , V_24 ) ;
}
if ( V_5 ) {
V_2 -> V_4 . V_25 = 0 ;
V_2 -> V_4 . V_26 =
F_6 ( time ) + V_21 ;
F_3 ( V_2 , L_2 ,
time ) ;
}
}
V_22:
return V_5 ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_17 )
F_9 ( V_2 , V_23 , 0 , NULL ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_5 = V_27 ;
T_2 V_28 , V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_28 = F_2 ( V_2 , V_31 ) ;
if ( V_28 & V_32 ) {
V_5 = 0 ;
break;
}
F_11 ( 5 ) ;
}
if ( V_5 == V_27 )
F_3 ( V_2 , L_3 ) ;
return V_5 ;
}
T_1 F_12 ( struct V_1 * V_2 , T_5 V_33 ,
T_5 * V_34 )
{
T_1 V_5 = V_27 ;
T_2 V_35 ;
if ( V_33 >= V_2 -> V_4 . V_8 ) {
F_3 ( V_2 , L_4 ) ;
V_5 = V_36 ;
goto V_37;
}
V_5 = F_10 ( V_2 ) ;
if ( ! V_5 ) {
V_35 = ( T_2 ) ( V_33 << V_38 ) |
( 1 << V_39 ) ;
F_13 ( V_2 , V_31 , V_35 ) ;
V_5 = F_10 ( V_2 ) ;
if ( ! V_5 ) {
V_35 = F_2 ( V_2 , V_40 ) ;
* V_34 = ( T_5 ) ( ( V_35 &
V_41 )
>> V_42 ) ;
}
}
if ( V_5 )
F_3 ( V_2 , L_5 ,
V_33 ) ;
V_37:
return V_5 ;
}
T_1 F_14 ( struct V_1 * V_2 , T_5 V_33 ,
T_5 * V_43 , T_5 * V_34 )
{
T_1 V_5 = 0 ;
T_5 V_44 , V_45 ;
for ( V_45 = 0 ; V_45 < * V_43 ; V_45 ++ ) {
V_44 = V_33 + V_45 ;
V_5 = F_12 ( V_2 , V_44 , & V_34 [ V_45 ] ) ;
if ( V_5 )
break;
}
* V_43 = V_45 ;
return V_5 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_3 V_46 ,
T_2 V_33 , T_5 V_43 , void * V_34 ,
bool V_47 )
{
T_1 V_5 = V_48 ;
if ( ( V_33 + V_43 ) > V_2 -> V_4 . V_8 )
F_3 ( V_2 , L_6 ) ;
else if ( V_43 > V_49 )
F_3 ( V_2 , L_7 ) ;
else if ( ( ( V_33 + ( V_43 - 1 ) ) / V_49 )
!= ( V_33 / V_49 ) )
F_3 ( V_2 , L_8 ) ;
else
V_5 = F_16 ( V_2 , V_46 ,
2 * V_33 ,
2 * V_43 ,
V_34 , V_47 , NULL ) ;
return V_5 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
T_5 * V_50 )
{
T_1 V_5 = 0 ;
T_5 V_51 = 0 ;
T_5 V_52 = 0 ;
T_5 V_53 = 0 ;
T_5 V_45 = 0 ;
T_2 V_54 = 0 ;
V_5 = F_12 ( V_2 , V_55 , & V_53 ) ;
if ( V_5 ) {
V_5 = V_56 ;
goto V_57;
}
V_5 = F_12 ( V_2 , V_58 ,
& V_51 ) ;
if ( V_5 ) {
V_5 = V_56 ;
goto V_57;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_4 . V_8 ; V_54 ++ ) {
if ( V_54 == V_59 )
V_54 ++ ;
if ( V_54 == ( T_2 ) V_53 ) {
V_54 += ( V_60 / 2 ) ;
if ( V_54 >= V_2 -> V_4 . V_8 )
break;
}
if ( V_54 == ( T_2 ) V_51 ) {
V_54 += ( V_61 / 2 ) ;
if ( V_54 >= V_2 -> V_4 . V_8 )
break;
}
V_5 = F_12 ( V_2 , ( T_5 ) V_54 , & V_45 ) ;
if ( V_5 ) {
V_5 = V_56 ;
goto V_57;
}
V_52 += V_45 ;
}
* V_50 = ( T_5 ) V_62 - V_52 ;
V_57:
return V_5 ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_5 = 0 ;
T_5 V_50 ;
V_5 = F_17 ( V_2 , & V_50 ) ;
if ( ! V_5 )
V_5 = F_15 ( V_2 , 0x00 , V_59 ,
1 , & V_50 , true ) ;
return V_5 ;
}
T_1 F_19 ( struct V_1 * V_2 ,
T_5 * V_50 )
{
T_1 V_5 = 0 ;
T_5 V_63 = 0 ;
T_5 V_52 = 0 ;
V_5 = F_17 ( V_2 , & V_52 ) ;
if ( V_5 )
goto V_64;
F_12 ( V_2 , V_59 , & V_63 ) ;
if ( V_52 != V_63 )
V_5 = V_56 ;
if ( V_50 )
* V_50 = V_52 ;
V_64:
return V_5 ;
}
static inline T_3 F_20 ( T_2 V_65 )
{
return ( T_3 ) ( V_65 & V_66 ) ;
}
static inline T_3 F_21 ( T_2 V_65 )
{
return ( T_3 ) ( ( V_65 & V_67 ) >> V_68 ) ;
}
T_1 F_22 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 * V_71 , int * V_72 )
{
T_1 V_73 ;
* V_72 = 0 ;
switch ( V_2 -> V_74 ) {
case V_75 :
V_73 = F_23 ( V_2 , V_70 , V_71 , V_72 ) ;
break;
case V_76 :
V_73 = F_24 ( V_2 , V_70 , V_71 , V_72 ) ;
break;
case V_77 :
V_73 = F_25 ( V_2 , V_70 , V_71 , V_72 ) ;
break;
default:
V_73 = V_78 ;
* V_72 = - V_79 ;
break;
}
return V_73 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 * V_71 , int * V_72 )
{
T_1 V_73 = 0 ;
enum V_80 V_81 ;
V_81 = F_26 ( V_2 , V_70 , V_72 ) ;
switch ( V_81 ) {
case V_82 :
V_73 = F_4 ( V_2 , V_83 ) ;
if ( V_73 ) {
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
} else {
V_73 = F_28 ( V_2 , V_70 , V_71 , V_72 ) ;
F_8 ( V_2 ) ;
}
break;
case V_86 :
V_73 = F_4 ( V_2 , V_83 ) ;
if ( V_73 ) {
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
} else {
V_73 = F_28 ( V_2 , V_70 , V_71 , V_72 ) ;
V_2 -> V_74 = V_76 ;
}
break;
case V_87 :
V_73 = F_4 ( V_2 , V_88 ) ;
if ( V_73 ) {
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
} else {
V_73 = F_29 ( V_2 , V_70 , V_72 ) ;
if ( V_73 )
F_8 ( V_2 ) ;
else
V_2 -> V_84 . V_89 = true ;
}
break;
case V_90 :
V_73 = F_4 ( V_2 , V_88 ) ;
if ( V_73 ) {
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
} else {
V_73 = F_30 ( V_2 , V_70 , V_71 , V_72 ) ;
if ( V_73 )
F_8 ( V_2 ) ;
else
V_2 -> V_84 . V_89 = true ;
}
break;
case V_91 :
V_73 = F_4 ( V_2 , V_88 ) ;
if ( V_73 ) {
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
} else {
V_73 = F_30 ( V_2 , V_70 , V_71 , V_72 ) ;
V_2 -> V_74 = V_77 ;
}
break;
case V_92 :
V_73 = F_4 ( V_2 , V_88 ) ;
if ( V_73 ) {
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
} else {
V_73 = F_18 ( V_2 ) ;
if ( V_73 ) {
* V_72 = V_2 -> V_84 . V_85 ?
F_27 ( V_2 -> V_84 . V_85 ) :
- V_93 ;
F_8 ( V_2 ) ;
} else {
V_2 -> V_84 . V_89 = true ;
}
}
break;
default:
V_73 = V_48 ;
* V_72 = - V_79 ;
break;
}
return V_73 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 * V_71 , int * V_72 )
{
T_1 V_73 ;
enum V_80 V_81 ;
V_81 = F_26 ( V_2 , V_70 , V_72 ) ;
switch ( V_81 ) {
case V_82 :
case V_94 :
V_73 = F_28 ( V_2 , V_70 , V_71 , V_72 ) ;
break;
case V_95 :
V_73 = F_28 ( V_2 , V_70 , V_71 , V_72 ) ;
F_8 ( V_2 ) ;
V_2 -> V_74 = V_75 ;
break;
default:
V_73 = V_78 ;
* V_72 = - V_79 ;
break;
}
return V_73 ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 * V_71 , int * V_72 )
{
T_1 V_73 ;
enum V_80 V_81 ;
V_81 = F_26 ( V_2 , V_70 , V_72 ) ;
switch ( V_81 ) {
case V_96 :
V_73 = F_30 ( V_2 , V_70 , V_71 , V_72 ) ;
break;
case V_97 :
V_73 = F_30 ( V_2 , V_70 , V_71 , V_72 ) ;
if ( ! V_73 ) {
V_2 -> V_84 . V_89 = true ;
V_2 -> V_74 = V_75 ;
}
break;
case V_98 :
V_73 = F_18 ( V_2 ) ;
if ( V_73 )
* V_72 = V_2 -> V_84 . V_85 ?
F_27 ( V_2 -> V_84 . V_85 ) :
- V_93 ;
break;
case V_99 :
V_73 = F_18 ( V_2 ) ;
if ( V_73 ) {
* V_72 = V_2 -> V_84 . V_85 ?
F_27 ( V_2 -> V_84 . V_85 ) :
- V_93 ;
} else {
V_2 -> V_84 . V_89 = true ;
V_2 -> V_74 = V_75 ;
}
break;
default:
V_73 = V_78 ;
* V_72 = - V_79 ;
break;
}
return V_73 ;
}
static enum V_80 F_26 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
int * V_72 )
{
enum V_80 V_81 ;
T_3 V_100 , V_101 ;
V_81 = V_102 ;
V_100 = F_21 ( V_70 -> V_103 ) ;
V_101 = F_20 ( V_70 -> V_103 ) ;
if ( ( V_70 -> V_104 < 1 ) ||
( V_70 -> V_104 > V_105 ) ) {
F_3 ( V_2 , L_9 ,
V_70 -> V_104 ) ;
* V_72 = - V_106 ;
return V_102 ;
}
switch ( V_70 -> V_107 ) {
case V_108 :
switch ( V_100 ) {
case V_109 :
V_81 = V_94 ;
break;
case V_110 :
V_81 = V_86 ;
break;
case V_111 :
V_81 = V_95 ;
break;
case V_112 :
V_81 = V_82 ;
break;
}
break;
case V_113 :
switch ( V_100 ) {
case V_109 :
V_81 = V_96 ;
break;
case V_110 :
V_81 = V_91 ;
break;
case V_111 :
V_81 = V_97 ;
break;
case V_112 :
V_81 = V_90 ;
break;
case V_114 :
V_81 = V_87 ;
break;
case V_115 :
V_81 = V_98 ;
break;
case ( V_115 | V_112 ) :
V_81 = V_92 ;
break;
case ( V_115 | V_111 ) :
V_81 = V_99 ;
break;
}
break;
}
if ( V_81 == V_102 ) {
* V_72 = - V_106 ;
F_3 ( V_2 ,
L_10 ,
V_81 , * V_72 ) ;
}
return V_81 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 * V_71 , int * V_72 )
{
T_1 V_73 ;
T_3 V_101 , V_100 ;
bool V_116 ;
V_100 = F_21 ( V_70 -> V_103 ) ;
V_101 = F_20 ( V_70 -> V_103 ) ;
V_116 = ( V_100 == V_111 ) || ( V_100 == V_112 ) ;
F_3 ( V_2 , L_11 ,
V_101 , V_70 -> V_33 , V_70 -> V_104 ) ;
V_73 = F_31 ( V_2 , V_101 , V_70 -> V_33 , ( T_5 ) V_70 -> V_104 ,
V_71 , V_116 , NULL ) ;
F_3 ( V_2 , L_12 , V_73 ) ;
if ( V_73 )
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
return V_73 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
int * V_72 )
{
T_1 V_73 = 0 ;
T_3 V_101 , V_100 ;
bool V_116 ;
V_100 = F_21 ( V_70 -> V_103 ) ;
V_101 = F_20 ( V_70 -> V_103 ) ;
V_116 = ( V_100 & V_111 ) ;
F_3 ( V_2 , L_13 ,
V_101 , V_70 -> V_33 , V_70 -> V_104 ) ;
V_73 = F_32 ( V_2 , V_101 , V_70 -> V_33 , ( T_5 ) V_70 -> V_104 ,
V_116 , NULL ) ;
F_3 ( V_2 , L_14 , V_73 ) ;
if ( V_73 )
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
return V_73 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 * V_71 , int * V_72 )
{
T_1 V_73 = 0 ;
T_3 V_101 , V_100 ;
bool V_116 ;
V_100 = F_21 ( V_70 -> V_103 ) ;
V_101 = F_20 ( V_70 -> V_103 ) ;
V_116 = ( V_100 & V_111 ) ;
F_3 ( V_2 , L_15 ,
V_101 , V_70 -> V_33 , V_70 -> V_104 ) ;
V_73 = F_16 ( V_2 , V_101 , V_70 -> V_33 ,
( T_5 ) V_70 -> V_104 , V_71 , V_116 , NULL ) ;
F_3 ( V_2 , L_16 , V_73 ) ;
if ( V_73 )
* V_72 = F_27 ( V_2 -> V_84 . V_85 ) ;
return V_73 ;
}
