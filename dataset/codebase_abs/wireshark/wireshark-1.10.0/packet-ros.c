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
static T_3 F_8 ( const char * V_1 , T_9 * V_20 , T_10 * V_21 , T_11 * V_22 )
{
T_4 * V_9 ;
T_6 V_11 = 0 ;
const T_12 * V_23 = NULL ;
const T_12 * V_24 = NULL ;
T_5 V_25 = NULL ;
const T_13 * V_26 ;
T_14 * V_27 = NULL ;
T_11 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
V_30 = ( (struct V_29 * ) ( V_21 -> V_31 ) ) ;
if( ( V_30 != NULL ) && ( ( V_9 = ( T_4 * ) F_9 ( V_10 , V_1 ) ) != NULL ) ) {
if( V_22 ) {
V_27 = F_10 ( V_22 , * ( V_9 -> T_2 ) , V_20 , 0 , - 1 , V_32 ) ;
V_28 = F_11 ( V_27 , * ( V_9 -> V_33 ) ) ;
}
F_12 ( V_21 -> V_34 , V_35 , V_9 -> V_4 ) ;
if( ( V_30 -> V_36 & V_37 ) == V_38 ) {
if( ( V_30 -> V_36 & V_39 ) == V_40 )
V_11 = V_41 ;
else
V_11 = V_42 ;
} else
V_11 = V_30 -> V_36 & V_43 ;
V_26 = V_9 -> V_44 ;
switch( V_30 -> V_36 & V_39 ) {
case V_45 :
V_25 = F_6 ( V_11 , V_9 -> V_46 , TRUE ) ;
V_24 = L_2 ;
break;
case V_47 :
V_25 = F_6 ( V_11 , V_9 -> V_46 , FALSE ) ;
V_24 = L_3 ;
break;
case V_40 :
V_25 = F_7 ( V_11 , V_9 -> V_48 ) ;
V_26 = V_9 -> V_49 ;
break;
default:
break;
}
if( V_25 ) {
V_23 = F_13 ( V_11 , V_26 , L_4 ) ;
if ( F_14 ( V_21 -> V_34 , V_50 ) ) {
F_12 ( V_21 -> V_34 , V_50 , V_23 ) ;
if( V_24 )
F_15 ( V_21 -> V_34 , V_50 , V_24 ) ;
}
(* V_25)( V_20 , V_21 , V_28 , NULL ) ;
return TRUE ;
}
}
return FALSE ;
}
int
F_16 ( const char * V_1 , T_9 * V_20 , int V_51 , T_10 * V_21 , T_11 * V_22 )
{
T_9 * V_52 ;
V_52 = F_17 ( V_20 , V_51 ) ;
if( ! F_8 ( V_1 , V_52 , V_21 , V_22 ) &&
! F_18 ( V_53 , V_1 , V_52 , V_21 , V_22 ) ) {
T_14 * V_27 = F_19 ( V_22 , V_52 , 0 , F_20 ( V_20 , V_51 ) , L_5 , V_1 ) ;
T_11 * V_54 = F_11 ( V_27 , V_55 ) ;
F_21 ( V_21 , V_27 , V_56 , V_57 ,
L_6 , V_1 ) ;
F_22 ( V_21 , V_52 , V_51 , V_54 ) ;
}
V_51 += F_20 ( V_20 , V_51 ) ;
return V_51 ;
}
static T_15
F_23 ( T_16 V_58 )
{
const T_17 * V_59 = ( const T_17 * ) V_58 ;
return V_59 -> V_60 ;
}
static T_18
F_24 ( T_16 V_61 , T_16 V_62 )
{
const T_17 * V_63 = ( const T_17 * ) V_61 ;
const T_17 * V_64 = ( const T_17 * ) V_62 ;
if( V_63 -> V_65 && V_64 -> V_65 && ( V_63 -> V_65 != V_64 -> V_65 ) ) {
return 0 ;
}
return V_63 -> V_60 == V_64 -> V_60 ;
}
static T_15
F_25 ( T_16 V_58 )
{
const T_17 * V_59 = ( const T_17 * ) V_58 ;
return V_59 -> V_60 ;
}
static T_18
F_26 ( T_16 V_61 , T_16 V_62 )
{
const T_17 * V_63 = ( const T_17 * ) V_61 ;
const T_17 * V_64 = ( const T_17 * ) V_62 ;
return V_63 -> V_60 == V_64 -> V_60 ;
}
static T_17 *
F_27 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_22 , T_15 V_60 , T_3 V_66 )
{
T_17 V_67 , * V_68 = NULL ;
T_19 * V_69 = V_70 ;
V_67 . V_60 = V_60 ;
V_67 . V_71 = V_66 ;
if( V_66 ) {
V_67 . V_65 = V_21 -> V_72 -> V_73 ;
V_67 . V_74 = 0 ;
} else {
V_67 . V_65 = 0 ;
V_67 . V_74 = V_21 -> V_72 -> V_73 ;
}
V_68 = ( T_17 * ) F_9 ( V_69 -> V_75 , & V_67 ) ;
if( V_68 ) {
V_68 -> V_71 = V_67 . V_71 ;
} else {
if( V_66 ) {
V_67 . V_60 = V_60 ;
V_68 = ( T_17 * ) F_9 ( V_69 -> V_76 , & V_67 ) ;
if( V_68 ) {
F_28 ( V_69 -> V_76 , V_68 ) ;
}
if( ! V_68 ) {
V_68 = F_29 ( T_17 ) ;
}
V_68 -> V_60 = V_60 ;
V_68 -> V_65 = V_21 -> V_72 -> V_73 ;
V_68 -> V_77 = V_21 -> V_72 -> V_78 ;
V_68 -> V_74 = 0 ;
V_68 -> V_71 = TRUE ;
F_3 ( V_69 -> V_76 , V_68 , V_68 ) ;
return NULL ;
} else {
V_67 . V_60 = V_60 ;
V_68 = ( T_17 * ) F_9 ( V_69 -> V_76 , & V_67 ) ;
if( V_68 ) {
if( ! V_68 -> V_74 ) {
F_28 ( V_69 -> V_76 , V_68 ) ;
V_68 -> V_74 = V_21 -> V_72 -> V_73 ;
V_68 -> V_71 = FALSE ;
F_3 ( V_69 -> V_75 , V_68 , V_68 ) ;
}
}
}
}
if( V_68 ) {
T_14 * V_27 = NULL ;
if( V_68 -> V_71 ) {
V_27 = F_30 ( V_22 , V_79 , V_20 , 0 , 0 , V_68 -> V_74 ) ;
F_31 ( V_27 ) ;
} else {
T_20 V_80 ;
V_27 = F_30 ( V_22 , V_81 , V_20 , 0 , 0 , V_68 -> V_65 ) ;
F_31 ( V_27 ) ;
F_32 ( & V_80 , & V_21 -> V_72 -> V_78 , & V_68 -> V_77 ) ;
V_27 = F_33 ( V_22 , V_82 , V_20 , 0 , 0 , & V_80 ) ;
F_31 ( V_27 ) ;
}
}
return V_68 ;
}
static int
F_34 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_83 ) ;
return V_51 ;
}
static int
F_36 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_37 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ) ;
return V_51 ;
}
int
F_38 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_39 ( T_23 , V_22 , V_20 , V_51 ,
V_84 , T_24 , V_85 ,
NULL ) ;
return V_51 ;
}
static int
F_40 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
NULL ) ;
return V_51 ;
}
static int
F_41 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_15 ) ;
return V_51 ;
}
static int
F_42 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 30 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_7 ) ;
F_27 ( V_20 , T_23 -> V_21 , V_22 , V_83 , TRUE ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_87 | V_45 ) ;
V_30 -> V_36 |= V_15 ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_44 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_51 ,
V_89 , T_24 , V_90 ) ;
return V_51 ;
}
static int
F_46 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 47 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_8 ) ;
F_27 ( V_20 , T_23 -> V_21 , V_22 , V_83 , FALSE ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_87 | V_47 ) ;
V_30 -> V_36 |= V_15 ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_47 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_51 ,
V_91 , T_24 , V_92 ) ;
return V_51 ;
}
static int
F_48 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_51 ,
V_93 , T_24 , V_94 ) ;
return V_51 ;
}
static int
F_49 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_15 ) ;
return V_51 ;
}
static int
F_50 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 64 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_8 ) ;
F_27 ( V_20 , T_23 -> V_21 , V_22 , V_83 , FALSE ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_87 | V_40 ) ;
V_30 -> V_36 |= V_15 ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_51 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_51 ,
V_95 , T_24 , V_96 ) ;
return V_51 ;
}
static int
F_52 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 169 "../../asn1/ros/ros.cnf"
T_25 V_97 ;
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_97 ) ;
if ( F_14 ( T_23 -> V_21 -> V_34 , V_50 ) ) {
F_53 ( T_23 -> V_21 -> V_34 , V_50 , L_9 , F_13 ( V_97 , V_98 , L_10 ) ) ;
}
return V_51 ;
}
static int
F_54 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 181 "../../asn1/ros/ros.cnf"
T_25 V_97 ;
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_97 ) ;
if ( F_14 ( T_23 -> V_21 -> V_34 , V_50 ) ) {
F_53 ( T_23 -> V_21 -> V_34 , V_50 , L_9 , F_13 ( V_97 , V_99 , L_11 ) ) ;
}
return V_51 ;
}
static int
F_55 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 193 "../../asn1/ros/ros.cnf"
T_25 V_97 ;
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_97 ) ;
if ( F_14 ( T_23 -> V_21 -> V_34 , V_50 ) ) {
F_53 ( T_23 -> V_21 -> V_34 , V_50 , L_9 , F_13 ( V_97 , V_100 , L_12 ) ) ;
}
return V_51 ;
}
static int
F_56 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 205 "../../asn1/ros/ros.cnf"
T_25 V_97 ;
V_51 = F_35 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 ,
& V_97 ) ;
if ( F_14 ( T_23 -> V_21 -> V_34 , V_50 ) ) {
F_53 ( T_23 -> V_21 -> V_34 , V_50 , L_9 , F_13 ( V_97 , V_101 , L_13 ) ) ;
}
return V_51 ;
}
static int
F_57 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_39 ( T_23 , V_22 , V_20 , V_51 ,
V_102 , T_24 , V_103 ,
NULL ) ;
return V_51 ;
}
static int
F_58 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_45 ( T_21 , T_23 , V_22 , V_20 , V_51 ,
V_104 , T_24 , V_105 ) ;
return V_51 ;
}
static int
F_59 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 161 "../../asn1/ros/ros.cnf"
if( F_14 ( T_23 -> V_21 -> V_34 , V_50 ) )
F_12 ( T_23 -> V_21 -> V_34 , V_50 , L_14 ) ;
V_51 = F_58 ( T_21 , V_20 , V_51 , T_23 , V_22 , T_24 ) ;
return V_51 ;
}
static int
F_60 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 81 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_15 ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_38 | V_45 ) ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_61 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 94 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_16 ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_38 | V_47 ) ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_62 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 107 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_17 ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_38 | V_40 ) ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_63 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 121 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_18 ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_106 | V_45 ) ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_64 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 135 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_19 ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_106 | V_47 ) ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
static int
F_65 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
#line 148 "../../asn1/ros/ros.cnf"
char * V_1 ;
struct V_29 * V_30 = (struct V_29 * ) T_23 -> V_21 -> V_31 ;
F_19 ( V_22 , V_20 , V_51 , - 1 , L_20 ) ;
if( V_30 && V_30 -> V_86 && ( V_1 = F_43 ( T_23 -> V_21 , V_30 -> V_86 ) ) ) {
V_30 -> V_36 = ( V_106 | V_40 ) ;
V_51 = F_16 ( V_1 , V_20 , V_51 , T_23 -> V_21 , V_88 ) ;
}
return V_51 ;
}
int
F_66 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_39 ( T_23 , V_22 , V_20 , V_51 ,
V_107 , T_24 , V_108 ,
NULL ) ;
return V_51 ;
}
static int
F_67 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_68 ( T_21 , T_23 , V_22 , V_20 , V_51 , T_24 , NULL ) ;
return V_51 ;
}
int
F_69 ( T_3 T_21 V_3 , T_9 * V_20 V_3 , int V_51 V_3 , T_22 * T_23 V_3 , T_11 * V_22 V_3 , int T_24 V_3 ) {
V_51 = F_39 ( T_23 , V_22 , V_20 , V_51 ,
V_109 , T_24 , V_110 ,
NULL ) ;
return V_51 ;
}
static void
F_70 ( T_9 * V_20 , T_10 * V_21 , T_11 * V_111 )
{
int V_51 = 0 ;
int V_112 ;
T_14 * V_27 = NULL ;
T_11 * V_22 = NULL ;
T_11 * V_54 = NULL ;
T_26 * V_113 ;
T_19 * V_69 = NULL ;
T_22 V_114 ;
F_71 ( & V_114 , V_115 , TRUE , V_21 ) ;
V_88 = V_111 ;
if( ! V_21 -> V_31 ) {
if( V_111 ) {
F_19 ( V_111 , V_20 , V_51 , - 1 ,
L_21 ) ;
}
return ;
}
V_113 = F_72 ( V_21 ) ;
V_69 = ( T_19 * ) F_73 ( V_113 , V_116 ) ;
if ( V_69 == NULL ) {
V_69 = ( T_19 * ) F_74 ( sizeof( T_19 ) ) ;
V_69 -> V_75 = F_75 ( F_23 , F_24 ) ;
V_69 -> V_76 = F_75 ( F_25 , F_26 ) ;
F_76 ( V_113 , V_116 , V_69 ) ;
V_69 -> V_117 = V_70 ;
V_70 = V_69 ;
}
if( V_111 ) {
V_27 = F_10 ( V_111 , V_116 , V_20 , 0 , - 1 , V_32 ) ;
V_22 = F_11 ( V_27 , V_118 ) ;
}
F_12 ( V_21 -> V_34 , V_35 , L_22 ) ;
F_77 ( V_21 -> V_34 , V_50 ) ;
while ( F_78 ( V_20 , V_51 ) > 0 ) {
V_112 = V_51 ;
V_51 = F_66 ( FALSE , V_20 , V_51 , & V_114 , V_22 , - 1 ) ;
if( V_51 == V_112 ) {
V_27 = F_19 ( V_22 , V_20 , V_51 , - 1 , L_23 ) ;
if( V_27 ) {
F_21 ( V_21 , V_27 , V_56 , V_57 , L_23 ) ;
V_54 = F_11 ( V_27 , V_55 ) ;
F_22 ( V_21 , V_20 , V_51 , V_54 ) ;
}
break;
}
}
}
static void
F_79 ( void )
{
T_19 * V_69 ;
for ( V_69 = V_70 ; V_69 != NULL ; ) {
T_19 * V_119 ;
F_80 ( V_69 -> V_75 ) ;
V_69 -> V_75 = NULL ;
F_80 ( V_69 -> V_76 ) ;
V_69 -> V_76 = NULL ;
V_119 = V_69 ;
V_69 = V_69 -> V_117 ;
F_81 ( V_119 ) ;
}
V_70 = NULL ;
}
void F_82 ( void ) {
static T_27 V_120 [] =
{
{ & V_79 ,
{ L_24 , L_25 ,
V_121 , V_122 , NULL , 0x0 ,
L_26 , V_123 } } ,
{ & V_81 ,
{ L_27 , L_28 ,
V_121 , V_122 , NULL , 0x0 ,
L_29 , V_123 } } ,
{ & V_82 ,
{ L_30 , L_31 ,
V_124 , V_122 , NULL , 0x0 ,
L_32 , V_123 } } ,
#line 1 "../../asn1/ros/packet-ros-hfarr.c"
{ & V_125 ,
{ L_33 , L_34 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_127 ,
{ L_35 , L_36 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_128 ,
{ L_37 , L_38 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_129 ,
{ L_39 , L_40 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_130 ,
{ L_15 , L_41 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_131 ,
{ L_16 , L_42 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_132 ,
{ L_17 , L_43 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_133 ,
{ L_18 , L_44 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_134 ,
{ L_19 , L_45 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_135 ,
{ L_20 , L_46 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_136 ,
{ L_47 , L_48 ,
V_137 , V_138 , F_83 ( V_139 ) , 0 ,
NULL , V_123 } } ,
{ & V_140 ,
{ L_49 , L_50 ,
V_141 , V_138 , NULL , 0 ,
L_51 , V_123 } } ,
{ & V_142 ,
{ L_52 , L_53 ,
V_141 , V_138 , NULL , 0 ,
L_54 , V_123 } } ,
{ & V_143 ,
{ L_55 , L_56 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_144 ,
{ L_57 , L_58 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_145 ,
{ L_57 , L_58 ,
V_126 , V_122 , NULL , 0 ,
L_59 , V_123 } } ,
{ & V_146 ,
{ L_60 , L_61 ,
V_141 , V_138 , NULL , 0 ,
L_62 , V_123 } } ,
{ & V_147 ,
{ L_63 , L_64 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_148 ,
{ L_65 , L_66 ,
V_137 , V_138 , F_83 ( V_149 ) , 0 ,
NULL , V_123 } } ,
{ & V_150 ,
{ L_67 , L_68 ,
V_141 , V_138 , F_83 ( V_98 ) , 0 ,
L_69 , V_123 } } ,
{ & V_151 ,
{ L_33 , L_34 ,
V_141 , V_138 , F_83 ( V_99 ) , 0 ,
L_70 , V_123 } } ,
{ & V_152 ,
{ L_35 , L_36 ,
V_141 , V_138 , F_83 ( V_100 ) , 0 ,
L_71 , V_123 } } ,
{ & V_153 ,
{ L_37 , L_38 ,
V_141 , V_138 , F_83 ( V_101 ) , 0 ,
L_72 , V_123 } } ,
{ & V_154 ,
{ L_73 , L_74 ,
V_141 , V_138 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_155 ,
{ L_75 , L_76 ,
V_126 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_156 ,
{ L_77 , L_78 ,
V_141 , V_138 , NULL , 0 ,
L_51 , V_123 } } ,
{ & V_157 ,
{ L_79 , L_80 ,
V_158 , V_122 , NULL , 0 ,
L_81 , V_123 } } ,
#line 490 "../../asn1/ros/packet-ros-template.c"
} ;
static T_18 * V_159 [] = {
& V_118 ,
& V_55 ,
#line 1 "../../asn1/ros/packet-ros-ettarr.c"
& V_108 ,
& V_90 ,
& V_94 ,
& V_92 ,
& V_96 ,
& V_105 ,
& V_103 ,
& V_85 ,
& V_110 ,
#line 497 "../../asn1/ros/packet-ros-template.c"
} ;
V_116 = F_84 ( V_160 , V_161 , V_162 ) ;
F_85 ( L_82 , F_70 , V_116 ) ;
F_86 ( V_116 , V_120 , F_87 ( V_120 ) ) ;
F_88 ( V_159 , F_87 ( V_159 ) ) ;
V_53 = F_89 ( L_1 , L_83 , V_163 , V_122 ) ;
V_6 = F_75 ( V_164 , V_165 ) ;
V_10 = F_75 ( V_164 , V_165 ) ;
V_8 = F_90 ( L_82 ) ;
F_91 ( F_79 ) ;
}
void F_92 ( void ) {
}
