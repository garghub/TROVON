void
F_1 ( const char * V_1 , T_1 V_2 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_3 ( V_6 , ( V_7 ) V_1 , ( V_7 ) V_4 ) ;
if( ! V_5 )
F_4 ( V_1 , V_8 , T_2 , V_4 ) ;
}
void
F_5 ( const char * V_1 , const T_4 * V_9 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_3 ( V_10 , ( V_7 ) V_1 , ( V_7 ) V_9 ) ;
F_3 ( V_6 , ( V_7 ) V_1 , ( V_7 ) V_4 ) ;
if( ! V_5 )
F_4 ( V_1 , V_8 , T_2 , V_4 ) ;
}
static T_5 F_6 ( T_6 V_11 , const T_7 * V_12 , T_3 V_13 )
{
if( V_12 ) {
for(; V_12 -> V_14 != ( T_5 ) ( - 1 ) ; V_12 ++ )
if( V_12 -> V_15 == V_11 )
return V_13 ? V_12 -> V_14 : V_12 -> V_16 ;
}
return NULL ;
}
static T_5 F_7 ( T_6 V_17 , const T_8 * V_18 )
{
if( V_18 ) {
for(; V_18 -> V_19 != ( T_5 ) ( - 1 ) ; V_18 ++ ) {
if( V_18 -> V_17 == V_17 )
return V_18 -> V_19 ;
}
}
return NULL ;
}
static T_3 F_8 ( const char * V_1 , T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , struct V_23 * V_24 )
{
T_4 * V_9 ;
T_6 V_11 = 0 ;
const T_12 * V_25 = NULL ;
const T_12 * V_26 = NULL ;
T_5 V_27 = NULL ;
const T_13 * V_28 ;
T_14 * V_29 = NULL ;
T_11 * V_30 = NULL ;
if( ( V_24 != NULL ) && ( ( V_9 = ( T_4 * ) F_9 ( V_10 , V_1 ) ) != NULL ) ) {
if( V_22 ) {
V_29 = F_10 ( V_22 , * ( V_9 -> T_2 ) , V_20 , 0 , - 1 , V_31 ) ;
V_30 = F_11 ( V_29 , * ( V_9 -> V_32 ) ) ;
}
F_12 ( V_21 -> V_33 , V_34 , V_9 -> V_4 ) ;
if( ( V_24 -> V_35 & V_36 ) == V_37 ) {
if( ( V_24 -> V_35 & V_38 ) == V_39 )
V_11 = V_40 ;
else
V_11 = V_41 ;
} else
V_11 = V_24 -> V_35 & V_42 ;
V_28 = V_9 -> V_43 ;
switch( V_24 -> V_35 & V_38 ) {
case V_44 :
V_27 = F_6 ( V_11 , V_9 -> V_45 , TRUE ) ;
V_26 = L_2 ;
break;
case V_46 :
V_27 = F_6 ( V_11 , V_9 -> V_45 , FALSE ) ;
V_26 = L_3 ;
break;
case V_39 :
V_27 = F_7 ( V_11 , V_9 -> V_47 ) ;
V_28 = V_9 -> V_48 ;
break;
default:
break;
}
if( V_27 ) {
V_25 = F_13 ( V_11 , V_28 , L_4 ) ;
F_12 ( V_21 -> V_33 , V_49 , V_25 ) ;
if( V_26 )
F_14 ( V_21 -> V_33 , V_49 , V_26 ) ;
(* V_27)( V_20 , V_21 , V_30 , NULL ) ;
return TRUE ;
}
}
return FALSE ;
}
int
F_15 ( const char * V_1 , T_9 * V_20 , int V_50 , T_10 * V_21 , T_11 * V_22 , struct V_23 * V_24 )
{
T_9 * V_51 ;
V_51 = F_16 ( V_20 , V_50 ) ;
if( ! F_8 ( V_1 , V_51 , V_21 , V_22 , V_24 ) &&
! F_17 ( V_52 , V_1 , V_51 , V_21 , V_22 , V_24 ) ) {
T_14 * V_29 ;
T_11 * V_53 ;
V_53 = F_18 ( V_22 , V_51 , 0 , - 1 , V_54 , & V_29 ,
L_5 , V_1 ) ;
F_19 ( V_21 , V_29 , & V_55 ,
L_6 , V_1 ) ;
F_20 ( V_21 , V_51 , V_50 , V_53 ) ;
}
V_50 += F_21 ( V_20 , V_50 ) ;
return V_50 ;
}
static T_15
F_22 ( T_16 V_56 )
{
const T_17 * V_57 = ( const T_17 * ) V_56 ;
return V_57 -> V_58 ;
}
static T_18
F_23 ( T_16 V_59 , T_16 V_60 )
{
const T_17 * V_61 = ( const T_17 * ) V_59 ;
const T_17 * V_62 = ( const T_17 * ) V_60 ;
if( V_61 -> V_63 && V_62 -> V_63 && ( V_61 -> V_63 != V_62 -> V_63 ) ) {
return 0 ;
}
return V_61 -> V_58 == V_62 -> V_58 ;
}
static T_15
F_24 ( T_16 V_56 )
{
const T_17 * V_57 = ( const T_17 * ) V_56 ;
return V_57 -> V_58 ;
}
static T_18
F_25 ( T_16 V_59 , T_16 V_60 )
{
const T_17 * V_61 = ( const T_17 * ) V_59 ;
const T_17 * V_62 = ( const T_17 * ) V_60 ;
return V_61 -> V_58 == V_62 -> V_58 ;
}
static T_17 *
F_26 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , T_15 V_58 , T_3 V_64 )
{
T_17 V_65 , * V_66 = NULL ;
T_19 * V_67 = V_68 ;
V_65 . V_58 = V_58 ;
V_65 . V_69 = V_64 ;
if( V_64 ) {
V_65 . V_63 = V_21 -> V_70 -> V_71 ;
V_65 . V_72 = 0 ;
} else {
V_65 . V_63 = 0 ;
V_65 . V_72 = V_21 -> V_70 -> V_71 ;
}
V_66 = ( T_17 * ) F_9 ( V_67 -> V_73 , & V_65 ) ;
if( V_66 ) {
V_66 -> V_69 = V_65 . V_69 ;
} else {
if( V_64 ) {
V_65 . V_58 = V_58 ;
V_66 = ( T_17 * ) F_9 ( V_67 -> V_74 , & V_65 ) ;
if( V_66 ) {
F_27 ( V_67 -> V_74 , V_66 ) ;
}
if( ! V_66 ) {
V_66 = F_28 ( F_29 () , T_17 ) ;
}
V_66 -> V_58 = V_58 ;
V_66 -> V_63 = V_21 -> V_70 -> V_71 ;
V_66 -> V_75 = V_21 -> V_70 -> V_76 ;
V_66 -> V_72 = 0 ;
V_66 -> V_69 = TRUE ;
F_3 ( V_67 -> V_74 , V_66 , V_66 ) ;
return NULL ;
} else {
V_65 . V_58 = V_58 ;
V_66 = ( T_17 * ) F_9 ( V_67 -> V_74 , & V_65 ) ;
if( V_66 ) {
if( ! V_66 -> V_72 ) {
F_27 ( V_67 -> V_74 , V_66 ) ;
V_66 -> V_72 = V_21 -> V_70 -> V_71 ;
V_66 -> V_69 = FALSE ;
F_3 ( V_67 -> V_73 , V_66 , V_66 ) ;
}
}
}
}
if( V_66 ) {
T_14 * V_29 = NULL ;
if( V_66 -> V_69 ) {
V_29 = F_30 ( V_22 , V_77 , V_20 , 0 , 0 , V_66 -> V_72 ) ;
F_31 ( V_29 ) ;
} else {
T_20 V_78 ;
V_29 = F_30 ( V_22 , V_79 , V_20 , 0 , 0 , V_66 -> V_63 ) ;
F_31 ( V_29 ) ;
F_32 ( & V_78 , & V_21 -> V_70 -> V_76 , & V_66 -> V_75 ) ;
V_29 = F_33 ( V_22 , V_80 , V_20 , 0 , 0 , & V_78 ) ;
F_31 ( V_29 ) ;
}
}
return V_66 ;
}
static int
F_34 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_81 ) ;
return V_50 ;
}
static int
F_36 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_37 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ) ;
return V_50 ;
}
int
F_38 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_39 ( T_23 , V_22 , V_20 , V_50 ,
V_82 , T_24 , V_83 ,
NULL ) ;
return V_50 ;
}
static int
F_40 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
NULL ) ;
return V_50 ;
}
static int
F_41 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_15 ) ;
return V_50 ;
}
static int
F_42 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 30 "../../asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_84 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
V_84 = F_43 ( V_22 , V_20 , V_50 , - 1 , V_86 , NULL , L_7 ) ;
F_26 ( V_20 , T_23 -> V_21 , V_84 , V_81 , TRUE ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_88 | V_44 ) ;
V_24 -> V_35 |= V_15 ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_45 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_46 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_90 , T_24 , V_91 ) ;
return V_50 ;
}
static int
F_47 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 48 "../../asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_84 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
V_84 = F_43 ( V_22 , V_20 , V_50 , - 1 , V_92 , NULL , L_8 ) ;
F_26 ( V_20 , T_23 -> V_21 , V_84 , V_81 , FALSE ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_88 | V_46 ) ;
V_24 -> V_35 |= V_15 ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_48 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_46 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_93 , T_24 , V_94 ) ;
return V_50 ;
}
static int
F_49 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_46 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_95 , T_24 , V_96 ) ;
return V_50 ;
}
static int
F_50 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_15 ) ;
return V_50 ;
}
static int
F_51 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 66 "../../asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_84 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
V_84 = F_43 ( V_22 , V_20 , V_50 , - 1 , V_92 , NULL , L_8 ) ;
F_26 ( V_20 , T_23 -> V_21 , V_84 , V_81 , FALSE ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_88 | V_39 ) ;
V_24 -> V_35 |= V_15 ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_52 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_46 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_97 , T_24 , V_98 ) ;
return V_50 ;
}
static int
F_53 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 171 "../../asn1/ros/ros.cnf"
T_25 V_99 ;
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_99 ) ;
F_54 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_99 , V_100 , L_10 ) ) ;
return V_50 ;
}
static int
F_55 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 181 "../../asn1/ros/ros.cnf"
T_25 V_99 ;
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_99 ) ;
F_54 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_99 , V_101 , L_11 ) ) ;
return V_50 ;
}
static int
F_56 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 191 "../../asn1/ros/ros.cnf"
T_25 V_99 ;
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_99 ) ;
F_54 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_99 , V_102 , L_12 ) ) ;
return V_50 ;
}
static int
F_57 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 201 "../../asn1/ros/ros.cnf"
T_25 V_99 ;
V_50 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_99 ) ;
F_54 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_99 , V_103 , L_13 ) ) ;
return V_50 ;
}
static int
F_58 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_39 ( T_23 , V_22 , V_20 , V_50 ,
V_104 , T_24 , V_105 ,
NULL ) ;
return V_50 ;
}
static int
F_59 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_46 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_106 , T_24 , V_107 ) ;
return V_50 ;
}
static int
F_60 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 164 "../../asn1/ros/ros.cnf"
F_12 ( T_23 -> V_21 -> V_33 , V_49 , L_14 ) ;
V_50 = F_59 ( T_21 , V_20 , V_50 , T_23 , V_22 , T_24 ) ;
return V_50 ;
}
static int
F_61 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 84 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
F_43 ( V_22 , V_20 , V_50 , - 1 , V_108 , NULL , L_15 ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_37 | V_44 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_62 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 97 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
F_43 ( V_22 , V_20 , V_50 , - 1 , V_108 , NULL , L_16 ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_37 | V_46 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_63 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 110 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
F_43 ( V_22 , V_20 , V_50 , - 1 , V_109 , NULL , L_17 ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_37 | V_39 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_64 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 124 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
F_43 ( V_22 , V_20 , V_50 , - 1 , V_110 , NULL , L_18 ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_111 | V_44 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_65 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 138 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
F_43 ( V_22 , V_20 , V_50 , - 1 , V_112 , NULL , L_19 ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_111 | V_46 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
static int
F_66 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 151 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_85 ;
F_43 ( V_22 , V_20 , V_50 , - 1 , V_113 , NULL , L_20 ) ;
if( V_24 && V_24 -> V_87 && ( V_1 = F_44 ( T_23 -> V_21 , V_24 -> V_87 ) ) ) {
V_24 -> V_35 = ( V_111 | V_39 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_89 , V_24 ) ;
}
return V_50 ;
}
int
F_67 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_39 ( T_23 , V_22 , V_20 , V_50 ,
V_114 , T_24 , V_115 ,
NULL ) ;
return V_50 ;
}
static int
F_68 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_69 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 , NULL ) ;
return V_50 ;
}
int
F_70 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_39 ( T_23 , V_22 , V_20 , V_50 ,
V_116 , T_24 , V_117 ,
NULL ) ;
return V_50 ;
}
static int
F_71 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_118 , void * V_119 )
{
int V_50 = 0 ;
int V_120 ;
T_14 * V_29 ;
T_11 * V_22 ;
T_11 * V_53 = NULL ;
T_26 * V_121 ;
T_19 * V_67 = NULL ;
T_22 V_122 ;
F_72 ( & V_122 , V_123 , TRUE , V_21 ) ;
if ( V_119 == NULL )
return 0 ;
V_122 . V_85 = V_119 ;
V_89 = V_118 ;
V_121 = F_73 ( V_21 ) ;
V_67 = ( T_19 * ) F_74 ( V_121 , V_124 ) ;
if ( V_67 == NULL ) {
V_67 = ( T_19 * ) F_75 ( sizeof( T_19 ) ) ;
V_67 -> V_73 = F_76 ( F_22 , F_23 ) ;
V_67 -> V_74 = F_76 ( F_24 , F_25 ) ;
F_77 ( V_121 , V_124 , V_67 ) ;
V_67 -> V_125 = V_68 ;
V_68 = V_67 ;
}
V_29 = F_10 ( V_118 , V_124 , V_20 , 0 , - 1 , V_31 ) ;
V_22 = F_11 ( V_29 , V_126 ) ;
F_12 ( V_21 -> V_33 , V_34 , L_21 ) ;
F_78 ( V_21 -> V_33 , V_49 ) ;
while ( F_79 ( V_20 , V_50 ) > 0 ) {
V_120 = V_50 ;
V_50 = F_67 ( FALSE , V_20 , V_50 , & V_122 , V_22 , - 1 ) ;
if( V_50 == V_120 ) {
V_53 = F_43 ( V_22 , V_20 , V_50 , - 1 , V_54 , & V_29 , L_22 ) ;
F_80 ( V_21 , V_29 , & V_127 ) ;
F_20 ( V_21 , V_20 , V_50 , V_53 ) ;
break;
}
}
return F_81 ( V_20 ) ;
}
static void
F_82 ( void )
{
T_19 * V_67 ;
for ( V_67 = V_68 ; V_67 != NULL ; ) {
T_19 * V_128 ;
F_83 ( V_67 -> V_73 ) ;
V_67 -> V_73 = NULL ;
F_83 ( V_67 -> V_74 ) ;
V_67 -> V_74 = NULL ;
V_128 = V_67 ;
V_67 = V_67 -> V_125 ;
F_84 ( V_128 ) ;
}
V_68 = NULL ;
}
void F_85 ( void ) {
static T_27 V_129 [] =
{
{ & V_77 ,
{ L_23 , L_24 ,
V_130 , V_131 , NULL , 0x0 ,
L_25 , V_132 } } ,
{ & V_79 ,
{ L_26 , L_27 ,
V_130 , V_131 , NULL , 0x0 ,
L_28 , V_132 } } ,
{ & V_80 ,
{ L_29 , L_30 ,
V_133 , V_131 , NULL , 0x0 ,
L_31 , V_132 } } ,
#line 1 "../../asn1/ros/packet-ros-hfarr.c"
{ & V_134 ,
{ L_32 , L_33 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_136 ,
{ L_34 , L_35 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_137 ,
{ L_36 , L_37 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_138 ,
{ L_38 , L_39 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_139 ,
{ L_15 , L_40 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_140 ,
{ L_16 , L_41 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_141 ,
{ L_17 , L_42 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_142 ,
{ L_18 , L_43 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_143 ,
{ L_19 , L_44 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_144 ,
{ L_20 , L_45 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_145 ,
{ L_46 , L_47 ,
V_146 , V_147 , F_86 ( V_148 ) , 0 ,
NULL , V_132 } } ,
{ & V_149 ,
{ L_48 , L_49 ,
V_150 , V_147 , NULL , 0 ,
L_50 , V_132 } } ,
{ & V_151 ,
{ L_51 , L_52 ,
V_150 , V_147 , NULL , 0 ,
L_53 , V_132 } } ,
{ & V_152 ,
{ L_54 , L_55 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_153 ,
{ L_56 , L_57 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_154 ,
{ L_56 , L_57 ,
V_135 , V_131 , NULL , 0 ,
L_58 , V_132 } } ,
{ & V_155 ,
{ L_59 , L_60 ,
V_150 , V_147 , NULL , 0 ,
L_61 , V_132 } } ,
{ & V_156 ,
{ L_62 , L_63 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_157 ,
{ L_64 , L_65 ,
V_146 , V_147 , F_86 ( V_158 ) , 0 ,
NULL , V_132 } } ,
{ & V_159 ,
{ L_66 , L_67 ,
V_150 , V_147 , F_86 ( V_100 ) , 0 ,
L_68 , V_132 } } ,
{ & V_160 ,
{ L_32 , L_69 ,
V_150 , V_147 , F_86 ( V_101 ) , 0 ,
L_70 , V_132 } } ,
{ & V_161 ,
{ L_34 , L_71 ,
V_150 , V_147 , F_86 ( V_102 ) , 0 ,
L_72 , V_132 } } ,
{ & V_162 ,
{ L_36 , L_73 ,
V_150 , V_147 , F_86 ( V_103 ) , 0 ,
L_74 , V_132 } } ,
{ & V_163 ,
{ L_75 , L_76 ,
V_150 , V_147 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_164 ,
{ L_77 , L_78 ,
V_135 , V_131 , NULL , 0 ,
NULL , V_132 } } ,
{ & V_165 ,
{ L_79 , L_80 ,
V_150 , V_147 , NULL , 0 ,
L_50 , V_132 } } ,
{ & V_166 ,
{ L_81 , L_82 ,
V_167 , V_131 , NULL , 0 ,
L_83 , V_132 } } ,
#line 488 "../../asn1/ros/packet-ros-template.c"
} ;
static T_18 * V_168 [] = {
& V_126 ,
& V_54 ,
& V_86 ,
& V_92 ,
& V_169 ,
& V_108 ,
& V_109 ,
& V_110 ,
& V_112 ,
& V_113 ,
#line 1 "../../asn1/ros/packet-ros-ettarr.c"
& V_115 ,
& V_91 ,
& V_96 ,
& V_94 ,
& V_98 ,
& V_107 ,
& V_105 ,
& V_83 ,
& V_117 ,
#line 504 "../../asn1/ros/packet-ros-template.c"
} ;
static T_28 V_170 [] = {
{ & V_55 , { L_84 , V_171 , V_172 , L_85 , V_173 } } ,
{ & V_127 , { L_86 , V_171 , V_172 , L_22 , V_173 } } ,
} ;
T_29 * V_174 ;
V_124 = F_87 ( V_175 , V_176 , V_177 ) ;
F_88 ( L_87 , F_71 , V_124 ) ;
F_89 ( V_124 , V_129 , F_90 ( V_129 ) ) ;
F_91 ( V_168 , F_90 ( V_168 ) ) ;
V_174 = F_92 ( V_124 ) ;
F_93 ( V_174 , V_170 , F_90 ( V_170 ) ) ;
V_52 = F_94 ( L_1 , L_88 , V_178 , V_131 ) ;
V_6 = F_76 ( V_179 , V_180 ) ;
V_10 = F_76 ( V_179 , V_180 ) ;
V_8 = F_95 ( L_87 ) ;
F_96 ( F_82 ) ;
}
void F_97 ( void ) {
}
