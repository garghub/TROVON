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
static int
F_8 ( const char * V_1 , T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , struct V_23 * V_24 )
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
return (* V_27)( V_20 , V_21 , V_30 , NULL ) ;
}
}
return 0 ;
}
int
F_15 ( const char * V_1 , T_9 * V_20 , int V_50 , T_10 * V_21 , T_11 * V_22 , struct V_23 * V_24 )
{
T_9 * V_51 ;
int V_52 ;
V_51 = F_16 ( V_20 , V_50 ) ;
if( ( ( V_52 = F_8 ( V_1 , V_51 , V_21 , V_22 , V_24 ) ) == 0 ) &&
( ( V_52 = F_17 ( V_53 , V_1 , V_51 , V_21 , V_22 , V_24 ) ) == 0 ) ) {
T_14 * V_29 ;
T_11 * V_54 ;
V_54 = F_18 ( V_22 , V_51 , 0 , - 1 , V_55 , & V_29 ,
L_5 , V_1 ) ;
F_19 ( V_21 , V_29 , & V_56 ,
L_6 , V_1 ) ;
V_52 = F_20 ( V_21 , V_51 , V_50 , V_54 ) ;
}
V_50 += V_52 ;
return V_50 ;
}
static T_15
F_21 ( T_16 V_57 )
{
const T_17 * V_58 = ( const T_17 * ) V_57 ;
return V_58 -> V_59 ;
}
static T_18
F_22 ( T_16 V_60 , T_16 V_61 )
{
const T_17 * V_62 = ( const T_17 * ) V_60 ;
const T_17 * V_63 = ( const T_17 * ) V_61 ;
if( V_62 -> V_64 && V_63 -> V_64 && ( V_62 -> V_64 != V_63 -> V_64 ) ) {
return 0 ;
}
return V_62 -> V_59 == V_63 -> V_59 ;
}
static T_15
F_23 ( T_16 V_57 )
{
const T_17 * V_58 = ( const T_17 * ) V_57 ;
return V_58 -> V_59 ;
}
static T_18
F_24 ( T_16 V_60 , T_16 V_61 )
{
const T_17 * V_62 = ( const T_17 * ) V_60 ;
const T_17 * V_63 = ( const T_17 * ) V_61 ;
return V_62 -> V_59 == V_63 -> V_59 ;
}
static T_17 *
F_25 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , T_15 V_59 , T_3 V_65 )
{
T_17 V_66 , * V_67 = NULL ;
T_19 * V_68 = V_69 ;
V_66 . V_59 = V_59 ;
V_66 . V_70 = V_65 ;
if( V_65 ) {
V_66 . V_64 = V_21 -> V_71 -> V_72 ;
V_66 . V_73 = 0 ;
} else {
V_66 . V_64 = 0 ;
V_66 . V_73 = V_21 -> V_71 -> V_72 ;
}
V_67 = ( T_17 * ) F_9 ( V_68 -> V_74 , & V_66 ) ;
if( V_67 ) {
V_67 -> V_70 = V_66 . V_70 ;
} else {
if( V_65 ) {
V_66 . V_59 = V_59 ;
V_67 = ( T_17 * ) F_9 ( V_68 -> V_75 , & V_66 ) ;
if( V_67 ) {
F_26 ( V_68 -> V_75 , V_67 ) ;
}
if( ! V_67 ) {
V_67 = F_27 ( F_28 () , T_17 ) ;
}
V_67 -> V_59 = V_59 ;
V_67 -> V_64 = V_21 -> V_71 -> V_72 ;
V_67 -> V_76 = V_21 -> V_71 -> V_77 ;
V_67 -> V_73 = 0 ;
V_67 -> V_70 = TRUE ;
F_3 ( V_68 -> V_75 , V_67 , V_67 ) ;
return NULL ;
} else {
V_66 . V_59 = V_59 ;
V_67 = ( T_17 * ) F_9 ( V_68 -> V_75 , & V_66 ) ;
if( V_67 ) {
if( ! V_67 -> V_73 ) {
F_26 ( V_68 -> V_75 , V_67 ) ;
V_67 -> V_73 = V_21 -> V_71 -> V_72 ;
V_67 -> V_70 = FALSE ;
F_3 ( V_68 -> V_74 , V_67 , V_67 ) ;
}
}
}
}
if( V_67 ) {
T_14 * V_29 = NULL ;
if( V_67 -> V_70 ) {
V_29 = F_29 ( V_22 , V_78 , V_20 , 0 , 0 , V_67 -> V_73 ) ;
F_30 ( V_29 ) ;
} else {
T_20 V_79 ;
V_29 = F_29 ( V_22 , V_80 , V_20 , 0 , 0 , V_67 -> V_64 ) ;
F_30 ( V_29 ) ;
F_31 ( & V_79 , & V_21 -> V_71 -> V_77 , & V_67 -> V_76 ) ;
V_29 = F_32 ( V_22 , V_81 , V_20 , 0 , 0 , & V_79 ) ;
F_30 ( V_29 ) ;
}
}
return V_67 ;
}
static int
F_33 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_82 ) ;
return V_50 ;
}
static int
F_35 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_36 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ) ;
return V_50 ;
}
int
F_37 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_38 ( T_23 , V_22 , V_20 , V_50 ,
V_83 , T_24 , V_84 ,
NULL ) ;
return V_50 ;
}
static int
F_39 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
NULL ) ;
return V_50 ;
}
static int
F_40 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_15 ) ;
return V_50 ;
}
static int
F_41 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 30 "../../asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_85 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
V_85 = F_42 ( V_22 , V_20 , V_50 , - 1 , V_87 , NULL , L_7 ) ;
F_25 ( V_20 , T_23 -> V_21 , V_85 , V_82 , TRUE ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_89 | V_44 ) ;
V_24 -> V_35 |= V_15 ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_44 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_91 , T_24 , V_92 ) ;
return V_50 ;
}
static int
F_46 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 48 "../../asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_85 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
V_85 = F_42 ( V_22 , V_20 , V_50 , - 1 , V_93 , NULL , L_8 ) ;
F_25 ( V_20 , T_23 -> V_21 , V_85 , V_82 , FALSE ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_89 | V_46 ) ;
V_24 -> V_35 |= V_15 ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_47 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_94 , T_24 , V_95 ) ;
return V_50 ;
}
static int
F_48 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_96 , T_24 , V_97 ) ;
return V_50 ;
}
static int
F_49 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_15 ) ;
return V_50 ;
}
static int
F_50 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 66 "../../asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_85 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
V_85 = F_42 ( V_22 , V_20 , V_50 , - 1 , V_93 , NULL , L_8 ) ;
F_25 ( V_20 , T_23 -> V_21 , V_85 , V_82 , FALSE ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_89 | V_39 ) ;
V_24 -> V_35 |= V_15 ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_51 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_98 , T_24 , V_99 ) ;
return V_50 ;
}
static int
F_52 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 171 "../../asn1/ros/ros.cnf"
T_25 V_100 ;
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_100 ) ;
F_53 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_100 , V_101 , L_10 ) ) ;
return V_50 ;
}
static int
F_54 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 181 "../../asn1/ros/ros.cnf"
T_25 V_100 ;
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_100 ) ;
F_53 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_100 , V_102 , L_11 ) ) ;
return V_50 ;
}
static int
F_55 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 191 "../../asn1/ros/ros.cnf"
T_25 V_100 ;
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_100 ) ;
F_53 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_100 , V_103 , L_12 ) ) ;
return V_50 ;
}
static int
F_56 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 201 "../../asn1/ros/ros.cnf"
T_25 V_100 ;
V_50 = F_34 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 ,
& V_100 ) ;
F_53 ( T_23 -> V_21 -> V_33 , V_49 , L_9 , F_13 ( V_100 , V_104 , L_13 ) ) ;
return V_50 ;
}
static int
F_57 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_38 ( T_23 , V_22 , V_20 , V_50 ,
V_105 , T_24 , V_106 ,
NULL ) ;
return V_50 ;
}
static int
F_58 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_50 ,
V_107 , T_24 , V_108 ) ;
return V_50 ;
}
static int
F_59 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 164 "../../asn1/ros/ros.cnf"
F_12 ( T_23 -> V_21 -> V_33 , V_49 , L_14 ) ;
V_50 = F_58 ( T_21 , V_20 , V_50 , T_23 , V_22 , T_24 ) ;
return V_50 ;
}
static int
F_60 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 84 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
F_42 ( V_22 , V_20 , V_50 , - 1 , V_109 , NULL , L_15 ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_37 | V_44 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_61 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 97 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
F_42 ( V_22 , V_20 , V_50 , - 1 , V_109 , NULL , L_16 ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_37 | V_46 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_62 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 110 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
F_42 ( V_22 , V_20 , V_50 , - 1 , V_110 , NULL , L_17 ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_37 | V_39 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_63 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 124 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
F_42 ( V_22 , V_20 , V_50 , - 1 , V_111 , NULL , L_18 ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_112 | V_44 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_64 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 138 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
F_42 ( V_22 , V_20 , V_50 , - 1 , V_113 , NULL , L_19 ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_112 | V_46 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
static int
F_65 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 151 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_23 * V_24 = (struct V_23 * ) T_23 -> V_86 ;
F_42 ( V_22 , V_20 , V_50 , - 1 , V_114 , NULL , L_20 ) ;
if( V_24 && V_24 -> V_88 && ( V_1 = F_43 ( T_23 -> V_21 , V_24 -> V_88 ) ) ) {
V_24 -> V_35 = ( V_112 | V_39 ) ;
V_50 = F_15 ( V_1 , V_20 , V_50 , T_23 -> V_21 , V_90 , V_24 ) ;
}
return V_50 ;
}
int
F_66 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_38 ( T_23 , V_22 , V_20 , V_50 ,
V_115 , T_24 , V_116 ,
NULL ) ;
return V_50 ;
}
static int
F_67 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_68 ( T_21 , T_23 , V_22 , V_20 , V_50 , T_24 , NULL ) ;
return V_50 ;
}
int
F_69 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_50 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_50 = F_38 ( T_23 , V_22 , V_20 , V_50 ,
V_117 , T_24 , V_118 ,
NULL ) ;
return V_50 ;
}
static int
F_70 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_119 , void * V_120 )
{
int V_50 = 0 ;
int V_121 ;
T_14 * V_29 ;
T_11 * V_22 ;
T_11 * V_54 = NULL ;
T_26 * V_122 ;
T_19 * V_68 = NULL ;
T_22 V_123 ;
F_71 ( & V_123 , V_124 , TRUE , V_21 ) ;
if ( V_120 == NULL )
return 0 ;
V_123 . V_86 = V_120 ;
V_90 = V_119 ;
V_122 = F_72 ( V_21 ) ;
V_68 = ( T_19 * ) F_73 ( V_122 , V_125 ) ;
if ( V_68 == NULL ) {
V_68 = ( T_19 * ) F_74 ( sizeof( T_19 ) ) ;
V_68 -> V_74 = F_75 ( F_21 , F_22 ) ;
V_68 -> V_75 = F_75 ( F_23 , F_24 ) ;
F_76 ( V_122 , V_125 , V_68 ) ;
V_68 -> V_126 = V_69 ;
V_69 = V_68 ;
}
V_29 = F_10 ( V_119 , V_125 , V_20 , 0 , - 1 , V_31 ) ;
V_22 = F_11 ( V_29 , V_127 ) ;
F_12 ( V_21 -> V_33 , V_34 , L_21 ) ;
F_77 ( V_21 -> V_33 , V_49 ) ;
while ( F_78 ( V_20 , V_50 ) > 0 ) {
V_121 = V_50 ;
V_50 = F_66 ( FALSE , V_20 , V_50 , & V_123 , V_22 , - 1 ) ;
if( V_50 == V_121 ) {
V_54 = F_42 ( V_22 , V_20 , V_50 , - 1 , V_55 , & V_29 , L_22 ) ;
F_79 ( V_21 , V_29 , & V_128 ) ;
F_20 ( V_21 , V_20 , V_50 , V_54 ) ;
break;
}
}
return F_80 ( V_20 ) ;
}
static void
F_81 ( void )
{
T_19 * V_68 ;
for ( V_68 = V_69 ; V_68 != NULL ; ) {
T_19 * V_129 ;
F_82 ( V_68 -> V_74 ) ;
V_68 -> V_74 = NULL ;
F_82 ( V_68 -> V_75 ) ;
V_68 -> V_75 = NULL ;
V_129 = V_68 ;
V_68 = V_68 -> V_126 ;
F_83 ( V_129 ) ;
}
V_69 = NULL ;
}
void F_84 ( void ) {
static T_27 V_130 [] =
{
{ & V_78 ,
{ L_23 , L_24 ,
V_131 , V_132 , NULL , 0x0 ,
L_25 , V_133 } } ,
{ & V_80 ,
{ L_26 , L_27 ,
V_131 , V_132 , NULL , 0x0 ,
L_28 , V_133 } } ,
{ & V_81 ,
{ L_29 , L_30 ,
V_134 , V_132 , NULL , 0x0 ,
L_31 , V_133 } } ,
#line 1 "../../asn1/ros/packet-ros-hfarr.c"
{ & V_135 ,
{ L_32 , L_33 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_137 ,
{ L_34 , L_35 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_138 ,
{ L_36 , L_37 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_139 ,
{ L_38 , L_39 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_140 ,
{ L_15 , L_40 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_141 ,
{ L_16 , L_41 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_142 ,
{ L_17 , L_42 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_143 ,
{ L_18 , L_43 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_144 ,
{ L_19 , L_44 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_145 ,
{ L_20 , L_45 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_146 ,
{ L_46 , L_47 ,
V_147 , V_148 , F_85 ( V_149 ) , 0 ,
NULL , V_133 } } ,
{ & V_150 ,
{ L_48 , L_49 ,
V_151 , V_148 , NULL , 0 ,
L_50 , V_133 } } ,
{ & V_152 ,
{ L_51 , L_52 ,
V_151 , V_148 , NULL , 0 ,
L_53 , V_133 } } ,
{ & V_153 ,
{ L_54 , L_55 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_154 ,
{ L_56 , L_57 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_155 ,
{ L_56 , L_57 ,
V_136 , V_132 , NULL , 0 ,
L_58 , V_133 } } ,
{ & V_156 ,
{ L_59 , L_60 ,
V_151 , V_148 , NULL , 0 ,
L_61 , V_133 } } ,
{ & V_157 ,
{ L_62 , L_63 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_158 ,
{ L_64 , L_65 ,
V_147 , V_148 , F_85 ( V_159 ) , 0 ,
NULL , V_133 } } ,
{ & V_160 ,
{ L_66 , L_67 ,
V_151 , V_148 , F_85 ( V_101 ) , 0 ,
L_68 , V_133 } } ,
{ & V_161 ,
{ L_32 , L_69 ,
V_151 , V_148 , F_85 ( V_102 ) , 0 ,
L_70 , V_133 } } ,
{ & V_162 ,
{ L_34 , L_71 ,
V_151 , V_148 , F_85 ( V_103 ) , 0 ,
L_72 , V_133 } } ,
{ & V_163 ,
{ L_36 , L_73 ,
V_151 , V_148 , F_85 ( V_104 ) , 0 ,
L_74 , V_133 } } ,
{ & V_164 ,
{ L_75 , L_76 ,
V_151 , V_148 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_165 ,
{ L_77 , L_78 ,
V_136 , V_132 , NULL , 0 ,
NULL , V_133 } } ,
{ & V_166 ,
{ L_79 , L_80 ,
V_151 , V_148 , NULL , 0 ,
L_50 , V_133 } } ,
{ & V_167 ,
{ L_81 , L_82 ,
V_168 , V_132 , NULL , 0 ,
L_83 , V_133 } } ,
#line 482 "../../asn1/ros/packet-ros-template.c"
} ;
static T_18 * V_169 [] = {
& V_127 ,
& V_55 ,
& V_87 ,
& V_93 ,
& V_170 ,
& V_109 ,
& V_110 ,
& V_111 ,
& V_113 ,
& V_114 ,
#line 1 "../../asn1/ros/packet-ros-ettarr.c"
& V_116 ,
& V_92 ,
& V_97 ,
& V_95 ,
& V_99 ,
& V_108 ,
& V_106 ,
& V_84 ,
& V_118 ,
#line 498 "../../asn1/ros/packet-ros-template.c"
} ;
static T_28 V_171 [] = {
{ & V_56 , { L_84 , V_172 , V_173 , L_85 , V_174 } } ,
{ & V_128 , { L_86 , V_172 , V_173 , L_22 , V_174 } } ,
} ;
T_29 * V_175 ;
V_125 = F_86 ( V_176 , V_177 , V_178 ) ;
F_87 ( L_87 , F_70 , V_125 ) ;
F_88 ( V_125 , V_130 , F_89 ( V_130 ) ) ;
F_90 ( V_169 , F_89 ( V_169 ) ) ;
V_175 = F_91 ( V_125 ) ;
F_92 ( V_175 , V_171 , F_89 ( V_171 ) ) ;
V_53 = F_93 ( L_1 , L_88 , V_179 , V_132 ) ;
V_6 = F_75 ( V_180 , V_181 ) ;
V_10 = F_75 ( V_180 , V_181 ) ;
V_8 = F_94 ( L_87 ) ;
F_95 ( F_81 ) ;
}
void F_96 ( void ) {
}
