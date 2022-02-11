void
F_1 ( const char * V_1 , T_1 V_2 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
if( ! V_5 )
F_3 ( V_1 , V_6 , T_2 , V_4 ) ;
}
void
F_4 ( const char * V_1 , const T_4 * V_7 , int T_2 V_3 , const char * V_4 , T_3 V_5 )
{
F_5 ( V_8 , ( V_9 ) V_1 , ( V_9 ) V_7 ) ;
if( ! V_5 )
F_3 ( V_1 , V_6 , T_2 , V_4 ) ;
}
static T_5 F_6 ( T_6 V_10 , const T_7 * V_11 , T_3 V_12 )
{
if( V_11 ) {
for(; V_11 -> V_13 != ( T_5 ) ( - 1 ) ; V_11 ++ )
if( V_11 -> V_14 == V_10 )
return V_12 ? V_11 -> V_13 : V_11 -> V_15 ;
}
return NULL ;
}
static T_5 F_7 ( T_6 V_16 , const T_8 * V_17 )
{
if( V_17 ) {
for(; V_17 -> V_18 != ( T_5 ) ( - 1 ) ; V_17 ++ ) {
if( V_17 -> V_16 == V_16 )
return V_17 -> V_18 ;
}
}
return NULL ;
}
static int
F_8 ( const char * V_1 , T_9 * V_19 , T_10 * V_20 , T_11 * V_21 , struct V_22 * V_23 )
{
T_4 * V_7 ;
T_6 V_10 = 0 ;
const T_12 * V_24 = NULL ;
const T_12 * V_25 = NULL ;
T_5 V_26 = NULL ;
const T_13 * V_27 ;
T_14 * V_28 = NULL ;
T_11 * V_29 = NULL ;
if( ( V_23 != NULL ) && ( V_1 != NULL ) && ( ( V_7 = ( T_4 * ) F_9 ( V_8 , V_1 ) ) != NULL ) ) {
if( V_21 ) {
V_28 = F_10 ( V_21 , * ( V_7 -> T_2 ) , V_19 , 0 , - 1 , V_30 ) ;
V_29 = F_11 ( V_28 , * ( V_7 -> V_31 ) ) ;
}
F_12 ( V_20 -> V_32 , V_33 , V_7 -> V_4 ) ;
if( ( V_23 -> V_34 & V_35 ) == V_36 ) {
if( ( V_23 -> V_34 & V_37 ) == V_38 )
V_10 = V_39 ;
else
V_10 = V_40 ;
} else
V_10 = V_23 -> V_34 & V_41 ;
V_27 = V_7 -> V_42 ;
switch( V_23 -> V_34 & V_37 ) {
case V_43 :
V_26 = F_6 ( V_10 , V_7 -> V_44 , TRUE ) ;
V_25 = L_2 ;
break;
case V_45 :
V_26 = F_6 ( V_10 , V_7 -> V_44 , FALSE ) ;
V_25 = L_3 ;
break;
case V_38 :
V_26 = F_7 ( V_10 , V_7 -> V_46 ) ;
V_27 = V_7 -> V_47 ;
break;
default:
break;
}
if( V_26 ) {
V_24 = F_13 ( V_10 , V_27 , L_4 ) ;
F_12 ( V_20 -> V_32 , V_48 , V_24 ) ;
if( V_25 )
F_14 ( V_20 -> V_32 , V_48 , V_25 ) ;
return (* V_26)( V_19 , V_20 , V_29 , NULL ) ;
}
}
return 0 ;
}
int
F_15 ( const char * V_1 , T_9 * V_19 , int V_49 , T_10 * V_20 , T_11 * V_21 , struct V_22 * V_23 )
{
T_9 * V_50 ;
int V_51 ;
V_50 = F_16 ( V_19 , V_49 ) ;
if( ( ( V_51 = F_8 ( V_1 , V_50 , V_20 , V_21 , V_23 ) ) == 0 ) &&
( ( V_51 = F_17 ( V_52 , V_1 , V_50 , V_20 , V_21 , V_23 ) ) == 0 ) ) {
T_14 * V_28 ;
T_11 * V_53 ;
V_53 = F_18 ( V_21 , V_50 , 0 , - 1 , V_54 , & V_28 ,
L_5 , V_1 ) ;
F_19 ( V_20 , V_28 , & V_55 ,
L_6 , V_1 ) ;
V_51 = F_20 ( V_20 , V_50 , V_49 , V_53 ) ;
}
V_49 += V_51 ;
return V_49 ;
}
static T_15
F_21 ( T_16 V_56 )
{
const T_17 * V_57 = ( const T_17 * ) V_56 ;
return V_57 -> V_58 ;
}
static T_18
F_22 ( T_16 V_59 , T_16 V_60 )
{
const T_17 * V_61 = ( const T_17 * ) V_59 ;
const T_17 * V_62 = ( const T_17 * ) V_60 ;
if( V_61 -> V_63 && V_62 -> V_63 && ( V_61 -> V_63 != V_62 -> V_63 ) ) {
return 0 ;
}
return V_61 -> V_58 == V_62 -> V_58 ;
}
static T_15
F_23 ( T_16 V_56 )
{
const T_17 * V_57 = ( const T_17 * ) V_56 ;
return V_57 -> V_58 ;
}
static T_18
F_24 ( T_16 V_59 , T_16 V_60 )
{
const T_17 * V_61 = ( const T_17 * ) V_59 ;
const T_17 * V_62 = ( const T_17 * ) V_60 ;
return V_61 -> V_58 == V_62 -> V_58 ;
}
static T_17 *
F_25 ( T_9 * V_19 , T_10 * V_20 , T_11 * V_21 , T_15 V_58 , T_3 V_64 )
{
T_17 V_65 , * V_66 = NULL ;
T_19 * V_67 ;
T_20 * V_68 ;
V_68 = F_26 ( V_20 -> V_69 , & V_20 -> V_70 , & V_20 -> V_71 ,
V_20 -> V_72 , V_20 -> V_73 ,
V_20 -> V_74 , 0 ) ;
if ( V_68 == NULL )
return NULL ;
V_67 = ( T_19 * ) F_27 ( V_68 , V_75 ) ;
if ( V_67 == NULL )
return NULL ;
V_65 . V_58 = V_58 ;
V_65 . V_76 = V_64 ;
if( V_64 ) {
V_65 . V_63 = V_20 -> V_69 ;
V_65 . V_77 = 0 ;
} else {
V_65 . V_63 = 0 ;
V_65 . V_77 = V_20 -> V_69 ;
}
V_66 = ( T_17 * ) F_9 ( V_67 -> V_78 , & V_65 ) ;
if( V_66 ) {
V_66 -> V_76 = V_65 . V_76 ;
} else {
if( V_64 ) {
V_65 . V_58 = V_58 ;
V_66 = ( T_17 * ) F_9 ( V_67 -> V_79 , & V_65 ) ;
if( V_66 ) {
F_28 ( V_67 -> V_79 , V_66 ) ;
}
if( ! V_66 ) {
V_66 = F_29 ( F_30 () , T_17 ) ;
}
V_66 -> V_58 = V_58 ;
V_66 -> V_63 = V_20 -> V_69 ;
V_66 -> V_80 = V_20 -> V_81 ;
V_66 -> V_77 = 0 ;
V_66 -> V_76 = TRUE ;
F_5 ( V_67 -> V_79 , V_66 , V_66 ) ;
return NULL ;
} else {
V_65 . V_58 = V_58 ;
V_66 = ( T_17 * ) F_9 ( V_67 -> V_79 , & V_65 ) ;
if( V_66 ) {
if( ! V_66 -> V_77 ) {
F_28 ( V_67 -> V_79 , V_66 ) ;
V_66 -> V_77 = V_20 -> V_69 ;
V_66 -> V_76 = FALSE ;
F_5 ( V_67 -> V_78 , V_66 , V_66 ) ;
}
}
}
}
if( V_66 ) {
T_14 * V_28 = NULL ;
if( V_66 -> V_76 ) {
V_28 = F_31 ( V_21 , V_82 , V_19 , 0 , 0 , V_66 -> V_77 ) ;
F_32 ( V_28 ) ;
} else {
T_21 V_83 ;
V_28 = F_31 ( V_21 , V_84 , V_19 , 0 , 0 , V_66 -> V_63 ) ;
F_32 ( V_28 ) ;
F_33 ( & V_83 , & V_20 -> V_81 , & V_66 -> V_80 ) ;
V_28 = F_34 ( V_21 , V_85 , V_19 , 0 , 0 , & V_83 ) ;
F_32 ( V_28 ) ;
}
}
return V_66 ;
}
static int
F_35 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_86 ) ;
return V_49 ;
}
static int
F_37 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_38 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ) ;
return V_49 ;
}
int
F_39 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_40 ( T_24 , V_21 , V_19 , V_49 ,
V_87 , T_25 , V_88 ,
NULL ) ;
return V_49 ;
}
static int
F_41 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
NULL ) ;
return V_49 ;
}
static int
F_42 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_14 ) ;
return V_49 ;
}
static int
F_43 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 30 "./asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_89 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
V_89 = F_44 ( V_21 , V_19 , V_49 , - 1 , V_91 , NULL , L_7 ) ;
F_25 ( V_19 , T_24 -> V_20 , V_89 , V_86 , TRUE ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_93 | V_43 ) ;
V_23 -> V_34 |= V_14 ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_46 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_47 ( T_22 , T_24 , V_21 , V_19 , V_49 ,
V_95 , T_25 , V_96 ) ;
return V_49 ;
}
static int
F_48 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 48 "./asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_89 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
V_89 = F_44 ( V_21 , V_19 , V_49 , - 1 , V_97 , NULL , L_8 ) ;
F_25 ( V_19 , T_24 -> V_20 , V_89 , V_86 , FALSE ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_93 | V_45 ) ;
V_23 -> V_34 |= V_14 ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_49 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_47 ( T_22 , T_24 , V_21 , V_19 , V_49 ,
V_98 , T_25 , V_99 ) ;
return V_49 ;
}
static int
F_50 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_47 ( T_22 , T_24 , V_21 , V_19 , V_49 ,
V_100 , T_25 , V_101 ) ;
return V_49 ;
}
static int
F_51 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_14 ) ;
return V_49 ;
}
static int
F_52 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 66 "./asn1/ros/ros.cnf"
char * V_1 ;
T_11 * V_89 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
V_89 = F_44 ( V_21 , V_19 , V_49 , - 1 , V_97 , NULL , L_8 ) ;
F_25 ( V_19 , T_24 -> V_20 , V_89 , V_86 , FALSE ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_93 | V_38 ) ;
V_23 -> V_34 |= V_14 ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_53 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_47 ( T_22 , T_24 , V_21 , V_19 , V_49 ,
V_102 , T_25 , V_103 ) ;
return V_49 ;
}
static int
F_54 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 171 "./asn1/ros/ros.cnf"
T_26 V_104 ;
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_104 ) ;
F_55 ( T_24 -> V_20 -> V_32 , V_48 , L_9 , F_13 ( V_104 , V_105 , L_10 ) ) ;
return V_49 ;
}
static int
F_56 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 181 "./asn1/ros/ros.cnf"
T_26 V_104 ;
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_104 ) ;
F_55 ( T_24 -> V_20 -> V_32 , V_48 , L_9 , F_13 ( V_104 , V_106 , L_11 ) ) ;
return V_49 ;
}
static int
F_57 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 191 "./asn1/ros/ros.cnf"
T_26 V_104 ;
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_104 ) ;
F_55 ( T_24 -> V_20 -> V_32 , V_48 , L_9 , F_13 ( V_104 , V_107 , L_12 ) ) ;
return V_49 ;
}
static int
F_58 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 201 "./asn1/ros/ros.cnf"
T_26 V_104 ;
V_49 = F_36 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 ,
& V_104 ) ;
F_55 ( T_24 -> V_20 -> V_32 , V_48 , L_9 , F_13 ( V_104 , V_108 , L_13 ) ) ;
return V_49 ;
}
static int
F_59 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_40 ( T_24 , V_21 , V_19 , V_49 ,
V_109 , T_25 , V_110 ,
NULL ) ;
return V_49 ;
}
static int
F_60 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_47 ( T_22 , T_24 , V_21 , V_19 , V_49 ,
V_111 , T_25 , V_112 ) ;
return V_49 ;
}
static int
F_61 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 164 "./asn1/ros/ros.cnf"
F_12 ( T_24 -> V_20 -> V_32 , V_48 , L_14 ) ;
V_49 = F_60 ( T_22 , V_19 , V_49 , T_24 , V_21 , T_25 ) ;
return V_49 ;
}
static int
F_62 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 84 "./asn1/ros/ros.cnf"
char * V_1 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
F_44 ( V_21 , V_19 , V_49 , - 1 , V_113 , NULL , L_15 ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_36 | V_43 ) ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_63 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 97 "./asn1/ros/ros.cnf"
char * V_1 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
F_44 ( V_21 , V_19 , V_49 , - 1 , V_113 , NULL , L_16 ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_36 | V_45 ) ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_64 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 110 "./asn1/ros/ros.cnf"
char * V_1 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
F_44 ( V_21 , V_19 , V_49 , - 1 , V_114 , NULL , L_17 ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_36 | V_38 ) ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_65 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 124 "./asn1/ros/ros.cnf"
char * V_1 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
F_44 ( V_21 , V_19 , V_49 , - 1 , V_115 , NULL , L_18 ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_116 | V_43 ) ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_66 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 138 "./asn1/ros/ros.cnf"
char * V_1 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
F_44 ( V_21 , V_19 , V_49 , - 1 , V_117 , NULL , L_19 ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_116 | V_45 ) ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
static int
F_67 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
#line 151 "./asn1/ros/ros.cnf"
char * V_1 ;
struct V_22 * V_23 = (struct V_22 * ) T_24 -> V_90 ;
F_44 ( V_21 , V_19 , V_49 , - 1 , V_118 , NULL , L_20 ) ;
if( V_23 && V_23 -> V_92 && ( V_1 = F_45 ( T_24 -> V_20 , V_23 -> V_92 ) ) ) {
V_23 -> V_34 = ( V_116 | V_38 ) ;
V_49 = F_15 ( V_1 , V_19 , V_49 , T_24 -> V_20 , V_94 , V_23 ) ;
}
return V_49 ;
}
int
F_68 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_40 ( T_24 , V_21 , V_19 , V_49 ,
V_119 , T_25 , V_120 ,
NULL ) ;
return V_49 ;
}
static int
F_69 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_70 ( T_22 , T_24 , V_21 , V_19 , V_49 , T_25 , NULL ) ;
return V_49 ;
}
int
F_71 ( T_3 T_22 V_3 , T_9 * V_19 V_3 , int V_49 V_3 , T_23 * T_24 V_3 , T_11 * V_21 V_3 , int T_25 V_3 ) {
V_49 = F_40 ( T_24 , V_21 , V_19 , V_49 ,
V_121 , T_25 , V_122 ,
NULL ) ;
return V_49 ;
}
static int
F_72 ( T_9 * V_19 , T_10 * V_20 , T_11 * V_123 , void * V_124 )
{
int V_49 = 0 ;
int V_125 ;
T_14 * V_28 ;
T_11 * V_21 ;
T_11 * V_53 = NULL ;
T_20 * V_68 ;
T_19 * V_67 = NULL ;
T_23 V_126 ;
F_73 ( & V_126 , V_127 , TRUE , V_20 ) ;
if ( V_124 == NULL )
return 0 ;
V_126 . V_90 = V_124 ;
V_94 = V_123 ;
V_68 = F_74 ( V_20 ) ;
V_67 = ( T_19 * ) F_27 ( V_68 , V_75 ) ;
if ( V_67 == NULL ) {
V_67 = ( T_19 * ) F_75 ( F_30 () , T_19 ) ;
V_67 -> V_78 = F_76 ( F_30 () , F_21 , F_22 ) ;
V_67 -> V_79 = F_76 ( F_30 () , F_23 , F_24 ) ;
F_77 ( V_68 , V_75 , V_67 ) ;
}
V_28 = F_10 ( V_123 , V_75 , V_19 , 0 , - 1 , V_30 ) ;
V_21 = F_11 ( V_28 , V_128 ) ;
F_12 ( V_20 -> V_32 , V_33 , L_21 ) ;
F_78 ( V_20 -> V_32 , V_48 ) ;
while ( F_79 ( V_19 , V_49 ) > 0 ) {
V_125 = V_49 ;
V_49 = F_68 ( FALSE , V_19 , V_49 , & V_126 , V_21 , - 1 ) ;
if( V_49 == V_125 ) {
V_53 = F_44 ( V_21 , V_19 , V_49 , - 1 , V_54 , & V_28 , L_22 ) ;
F_80 ( V_20 , V_28 , & V_129 ) ;
F_20 ( V_20 , V_19 , V_49 , V_53 ) ;
break;
}
}
return F_81 ( V_19 ) ;
}
void F_82 ( void ) {
static T_27 V_130 [] =
{
{ & V_82 ,
{ L_23 , L_24 ,
V_131 , V_132 , NULL , 0x0 ,
L_25 , V_133 } } ,
{ & V_84 ,
{ L_26 , L_27 ,
V_131 , V_132 , NULL , 0x0 ,
L_28 , V_133 } } ,
{ & V_85 ,
{ L_29 , L_30 ,
V_134 , V_132 , NULL , 0x0 ,
L_31 , V_133 } } ,
#line 1 "./asn1/ros/packet-ros-hfarr.c"
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
V_147 , V_148 , F_83 ( V_149 ) , 0 ,
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
V_147 , V_148 , F_83 ( V_159 ) , 0 ,
NULL , V_133 } } ,
{ & V_160 ,
{ L_66 , L_67 ,
V_151 , V_148 , F_83 ( V_105 ) , 0 ,
L_68 , V_133 } } ,
{ & V_161 ,
{ L_32 , L_69 ,
V_151 , V_148 , F_83 ( V_106 ) , 0 ,
L_70 , V_133 } } ,
{ & V_162 ,
{ L_34 , L_71 ,
V_151 , V_148 , F_83 ( V_107 ) , 0 ,
L_72 , V_133 } } ,
{ & V_163 ,
{ L_36 , L_73 ,
V_151 , V_148 , F_83 ( V_108 ) , 0 ,
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
#line 460 "./asn1/ros/packet-ros-template.c"
} ;
static T_18 * V_169 [] = {
& V_128 ,
& V_54 ,
& V_91 ,
& V_97 ,
& V_170 ,
& V_113 ,
& V_114 ,
& V_115 ,
& V_117 ,
& V_118 ,
#line 1 "./asn1/ros/packet-ros-ettarr.c"
& V_120 ,
& V_96 ,
& V_101 ,
& V_99 ,
& V_103 ,
& V_112 ,
& V_110 ,
& V_88 ,
& V_122 ,
#line 476 "./asn1/ros/packet-ros-template.c"
} ;
static T_28 V_171 [] = {
{ & V_55 , { L_84 , V_172 , V_173 , L_85 , V_174 } } ,
{ & V_129 , { L_86 , V_172 , V_173 , L_22 , V_174 } } ,
} ;
T_29 * V_175 ;
V_75 = F_84 ( V_176 , V_177 , V_178 ) ;
V_6 = F_85 ( L_87 , F_72 , V_75 ) ;
F_86 ( V_75 , V_130 , F_87 ( V_130 ) ) ;
F_88 ( V_169 , F_87 ( V_169 ) ) ;
V_175 = F_89 ( V_75 ) ;
F_90 ( V_175 , V_171 , F_87 ( V_171 ) ) ;
V_52 = F_91 ( L_1 , L_88 , V_75 , V_179 , V_132 ) ;
V_8 = F_76 ( F_92 () , V_180 , V_181 ) ;
}
void F_93 ( void ) {
}
