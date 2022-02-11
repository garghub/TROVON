T_1 F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 ) {
T_1 V_4 = (struct V_5 * ) F_2 ( sizeof( struct V_5 ) ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_6 = FALSE ;
F_3 ( V_7 , V_4 ) ;
return * ( F_4 ( V_1 , V_4 ) ) ;
}
T_1 F_5 ( T_3 * V_2 , T_4 * V_3 )
{
T_1 V_8 = ( T_1 ) F_2 ( sizeof( struct V_5 ) ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = FALSE ;
return V_8 ;
}
static T_4 *
F_6 ( T_2 * V_1 , T_1 V_8 , T_5 V_9 , const int V_10 ,
const T_6 type , const T_7 V_11 , T_8 * V_12 )
{
T_8 V_13 = 0 ;
T_4 * V_3 = NULL ;
T_8 V_14 = 0 ;
switch( type ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
{
T_9 * V_20 = F_7 () ;
V_3 = F_8 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 ,
V_9 -> V_23 , V_9 -> V_24 , V_11 ,
V_20 , & V_14 , & V_13 ) ;
if ( V_13 == 0 ) {
F_9 ( V_1 , V_20 ) ;
F_10 ( V_1 , V_14 ) ;
}
}
break;
case V_25 :
case V_26 :
{
T_10 * V_27 = ( T_10 * ) F_11 ( sizeof( T_10 ) ) ;
V_3 = F_12 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 ,
V_9 -> V_23 , V_9 -> V_24 , V_11 ,
V_27 , & V_14 , & V_13 ) ;
if ( V_13 == 0 ) {
F_13 ( V_1 , V_27 ) ;
F_10 ( V_1 , V_14 ) ;
}
}
break;
case V_28 :
case V_29 :
default:
V_3 = F_14 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_11 ) ;
F_15 ( V_1 ) ;
F_15 ( V_1 ) ;
break;
}
if ( V_12 ) * V_12 = V_13 ;
return V_3 ;
}
T_11 F_16 ( T_2 * V_1 ) {
#define F_17 2
#define F_18 3
#define F_19 4
#define F_20 5
volatile T_5 V_9 ;
T_12 V_30 ;
int V_10 ;
volatile int V_31 ;
T_6 type ;
T_1 V_8 = F_21 ( V_1 , 1 ) ;
T_7 V_11 ;
T_4 * V_3 = NULL ;
volatile int V_32 ;
volatile T_8 V_13 = 0 ;
const char * volatile error = NULL ;
if ( ! V_8 ) {
return F_22 ( V_1 , L_1 ) ;
}
if ( V_8 -> V_6 ) {
F_22 ( V_1 , L_2 ) ;
return 0 ;
}
if ( ! ( V_30 = F_23 ( V_1 , 1 ) ) ) {
F_22 ( V_1 , L_3 ) ;
return 0 ;
}
V_10 = V_30 -> V_10 ;
type = V_30 -> type ;
V_31 = V_30 -> V_31 ;
V_9 = F_24 ( V_1 , 1 ) ;
if ( ! V_9 ) {
V_9 = F_25 ( F_26 () , struct V_33 ) ;
V_9 -> V_21 = F_25 ( F_26 () , struct V_34 ) ;
V_9 -> V_21 -> V_22 = V_35 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
}
V_11 = F_27 ( V_1 , 1 ) ;
F_28 ( V_1 , 1 ) ;
V_32 = F_29 ( V_1 ) ;
if ( type == V_36 ) {
switch ( V_11 & V_37 ) {
case V_38 :
case V_39 :
V_9 -> V_24 = F_30 ( V_9 -> V_21 -> V_22 , V_9 -> V_23 ) ;
break;
default:
if ( F_31 ( V_9 -> V_21 -> V_22 , V_9 -> V_23 , - 1 , 0 ) == - 1 ) {
F_22 ( V_1 , L_4 ) ;
return 0 ;
}
V_9 -> V_24 = F_32 ( V_9 -> V_21 -> V_22 , V_9 -> V_23 ) ;
break;
}
}
F_33 {
T_8 V_40 = 0 ;
V_3 = F_6 ( V_1 , V_8 , V_9 , V_10 , type , V_11 , & V_40 ) ;
V_13 = V_40 ;
} F_34 {
F_35 ( V_9 -> V_21 -> V_22 , V_41 , V_8 -> V_2 , V_42 , V_43 ) ;
error = L_5 ;
} V_44 ;
if ( error ) { F_36 ( F_16 , error ) ; }
if ( V_13 != 0 ) {
F_15 ( V_1 ) ;
F_15 ( V_1 ) ;
}
while( V_32 ) {
const T_13 * V_45 ;
V_45 = F_37 ( V_1 , 1 ) ;
if ( V_45 ) F_38 ( V_3 , L_6 , V_45 ) ;
F_28 ( V_1 , 1 ) ;
V_32 -- ;
}
F_1 ( V_1 , F_39 ( V_3 , V_31 > 0 ? V_31 : V_46 ) , V_3 ) ;
F_40 ( V_1 , 1 ) ;
F_41 ( 3 ) ;
}
static int F_42 ( T_2 * V_1 , T_14 V_47 ) {
T_5 V_9 ;
T_15 V_48 ;
T_12 V_30 ;
int V_10 = - 1 ;
int V_31 = - 1 ;
T_6 type = V_28 ;
T_1 V_8 = F_21 ( V_1 , 1 ) ;
T_4 * V_3 = NULL ;
if ( ! V_8 ) {
return F_22 ( V_1 , L_1 ) ;
}
if ( V_8 -> V_6 ) {
F_22 ( V_1 , L_2 ) ;
return 0 ;
}
if ( ! ( V_30 = F_23 ( V_1 , 1 ) ) ) {
if ( ( V_48 = F_43 ( V_1 , 1 ) ) ) {
V_10 = V_48 -> V_10 ;
type = V_29 ;
V_31 = V_48 -> V_31 ;
}
} else {
V_10 = V_30 -> V_10 ;
type = V_30 -> type ;
V_31 = V_30 -> V_31 ;
}
V_9 = F_24 ( V_1 , 1 ) ;
if ( ! V_9 ) {
V_9 = F_25 ( F_26 () , struct V_33 ) ;
V_9 -> V_21 = F_25 ( F_26 () , struct V_34 ) ;
V_9 -> V_21 -> V_22 = V_35 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
}
if ( V_10 > 0 ) {
if ( type == V_36 ) {
if ( F_31 ( V_9 -> V_21 -> V_22 , V_9 -> V_23 , - 1 , 0 ) == - 1 ) {
F_22 ( V_1 , L_4 ) ;
return 0 ;
}
V_9 -> V_24 = F_32 ( V_9 -> V_21 -> V_22 , V_9 -> V_23 ) ;
}
if ( F_29 ( V_1 ) ) {
switch( type ) {
case V_29 :
V_3 = F_14 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_49 ) ;
F_44 ( V_1 , 0 ) ;
F_40 ( V_1 , 1 ) ;
break;
case V_50 :
{
T_16 V_51 = ( T_16 ) ( F_45 ( V_1 , 1 ) ) ;
V_3 = F_46 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_51 ) ;
}
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_3 = F_47 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_48 ( V_1 , 1 ) ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_3 = F_49 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_48 ( V_1 , 1 ) ) ;
break;
case V_61 :
V_3 = F_50 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( float ) F_51 ( V_1 , 1 ) ) ;
break;
case V_62 :
V_3 = F_52 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( double ) F_51 ( V_1 , 1 ) ) ;
break;
case V_25 :
case V_26 :
V_3 = F_53 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_54 ( V_1 , 1 ) ) ;
break;
case V_63 :
case V_36 :
V_3 = F_55 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_56 ( V_1 , 1 ) ) ;
break;
case V_15 :
V_3 = F_57 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( const V_64 * ) F_56 ( V_1 , 1 ) ) ;
break;
case V_65 :
V_3 = F_58 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_59 ( V_1 , 1 ) ) ;
break;
case V_66 :
V_3 = F_60 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_61 ( V_1 , 1 ) ) ;
break;
case V_67 :
V_3 = F_62 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , * ( ( const T_16 * ) ( F_63 ( V_1 , 1 ) -> V_68 ) ) ) ;
break;
case V_69 :
case V_16 :
case V_70 :
case V_71 :
case V_72 :
case V_17 :
case V_18 :
case V_19 :
case V_73 :
case V_74 :
default:
F_22 ( V_1 , L_7 ) ;
return 0 ;
}
F_28 ( V_1 , 1 ) ;
} else {
if ( type == V_56 ) {
F_22 ( V_1 , L_8 ) ;
return 0 ;
}
V_3 = F_14 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_47 ? V_75 : V_76 ) ;
}
if ( F_29 ( V_1 ) ) {
const T_13 * V_45 = F_37 ( V_1 , 1 ) ;
if ( V_45 ) F_64 ( V_3 , L_9 , V_45 ) ;
F_28 ( V_1 , 1 ) ;
}
} else {
if ( F_29 ( V_1 ) ) {
const T_13 * V_45 = F_37 ( V_1 , 1 ) ;
const int V_77 = F_65 () ;
if ( V_77 > - 1 ) {
V_3 = F_14 ( V_8 -> V_2 , V_77 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_49 ) ;
F_64 ( V_3 , L_9 , V_45 ) ;
} else {
F_22 ( V_1 , L_10 ) ;
}
F_28 ( V_1 , 1 ) ;
} else {
F_22 ( V_1 , L_11 ) ;
}
}
while( F_29 ( V_1 ) ) {
const T_13 * V_45 = F_37 ( V_1 , 1 ) ;
if ( V_45 ) F_38 ( V_3 , L_6 , V_45 ) ;
F_28 ( V_1 , 1 ) ;
}
F_1 ( V_1 , F_39 ( V_3 , V_31 > 0 ? V_31 : V_46 ) , V_3 ) ;
return 1 ;
}
T_11 F_66 ( T_2 * V_1 ) {
#define F_67 2
#define F_68 3
#define F_69 4
#define F_70 5
F_41 ( F_42 ( V_1 , FALSE ) ) ;
}
T_11 F_71 ( T_2 * V_1 ) {
#define F_72 2
#define F_73 3
#define F_74 4
#define F_75 5
F_41 ( F_42 ( V_1 , TRUE ) ) ;
}
static int F_76 ( T_2 * V_1 ) {
T_1 V_4 = F_77 ( V_1 , 1 ) ;
T_13 V_78 [ V_79 + 1 ] ;
T_13 * V_80 ;
T_17 * V_81 = F_78 ( V_4 -> V_3 ) ;
if( V_81 ) {
if ( ! V_81 -> V_82 ) {
V_80 = V_78 ;
F_79 ( V_81 , V_78 ) ;
} else
V_80 = V_81 -> V_82 -> V_83 ;
if ( V_80 ) {
F_80 ( V_1 , V_80 ) ;
} else {
F_15 ( V_1 ) ;
}
} else {
F_15 ( V_1 ) ;
}
return 1 ;
}
T_11 F_81 ( T_2 * V_1 ) {
#define F_82 2
T_1 V_4 = F_77 ( V_1 , 1 ) ;
const T_13 * V_45 = F_56 ( V_1 , F_82 ) ;
F_64 ( V_4 -> V_3 , L_9 , V_45 ) ;
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_84 ( T_2 * V_1 ) {
#define F_85 2
T_1 V_4 = F_77 ( V_1 , 1 ) ;
const T_13 * V_45 = F_56 ( V_1 , F_85 ) ;
F_38 ( V_4 -> V_3 , L_9 , V_45 ) ;
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_86 ( T_2 * V_1 ) {
#define F_87 2
T_1 V_4 = F_77 ( V_1 , 1 ) ;
const T_13 * V_45 = F_56 ( V_1 , F_87 ) ;
F_88 ( V_4 -> V_3 , L_9 , V_45 ) ;
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_89 ( T_2 * V_1 ) {
#define F_90 2
#define F_91 3
#define F_92 4
T_1 V_4 = F_77 ( V_1 , 1 ) ;
int V_84 = ( int ) F_93 ( V_1 , F_90 , V_85 ) ;
int V_86 = ( int ) F_93 ( V_1 , F_91 , V_87 ) ;
T_18 * V_88 = F_94 ( V_84 , V_86 ) ;
const T_13 * V_89 ;
if ( F_29 ( V_1 ) >= F_92 ) {
V_89 = F_95 ( V_1 , F_92 ) ;
F_96 ( V_41 , V_4 -> V_3 , V_88 , L_9 , V_89 ) ;
} else {
F_97 ( V_41 , V_4 -> V_3 , V_88 ) ;
}
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_98 ( T_2 * V_1 ) {
#define F_99 2
#define F_100 3
T_1 V_4 = F_77 ( V_1 , 1 ) ;
T_19 V_90 = F_101 ( V_1 , F_99 ) ;
const T_13 * V_89 ;
if ( V_90 -> V_91 . V_92 == V_93 || V_90 -> V_91 . V_77 == V_94 ) {
F_22 ( V_1 , L_12 ) ;
return 0 ;
}
if ( F_29 ( V_1 ) >= F_100 ) {
V_89 = F_95 ( V_1 , F_100 ) ;
F_96 ( V_41 , V_4 -> V_3 , & V_90 -> V_91 , L_9 , V_89 ) ;
} else {
F_97 ( V_41 , V_4 -> V_3 , & V_90 -> V_91 ) ;
}
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_102 ( T_2 * V_1 ) {
#define F_103 2
#define F_104 3
#define F_105 4
T_1 V_4 = F_77 ( V_1 , 1 ) ;
T_19 V_90 = F_101 ( V_1 , F_99 ) ;
T_5 V_9 ;
const T_13 * V_89 ;
if ( V_90 -> V_91 . V_92 == V_93 || V_90 -> V_91 . V_77 == V_94 ) {
F_22 ( V_1 , L_12 ) ;
return 0 ;
}
V_9 = F_24 ( V_1 , F_104 ) ;
if ( ! V_9 ) {
V_9 = F_25 ( F_26 () , struct V_33 ) ;
V_9 -> V_21 = F_106 ( V_1 , F_104 ) ;
if ( ! V_9 -> V_21 ) {
V_9 -> V_21 = F_25 ( F_26 () , struct V_34 ) ;
}
V_9 -> V_21 -> V_22 = V_35 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
}
if ( F_29 ( V_1 ) >= F_100 ) {
V_89 = F_95 ( V_1 , F_100 ) ;
F_107 ( V_4 -> V_2 , V_41 , & V_90 -> V_91 ,
V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 ,
L_9 , V_89 ) ;
} else {
F_108 ( V_4 -> V_2 , V_41 , & V_90 -> V_91 ,
V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 ) ;
}
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
static int F_109 ( T_2 * V_1 ) {
T_1 V_4 = F_77 ( V_1 , 1 ) ;
if ( V_4 -> V_2 ) {
F_110 ( V_1 , F_111 ( V_4 -> V_2 ) -> V_95 ) ;
}
else {
F_110 ( V_1 , FALSE ) ;
}
return 1 ;
}
static int F_112 ( T_2 * V_1 ) {
T_1 V_4 = F_77 ( V_1 , 1 ) ;
F_110 ( V_1 , F_113 ( V_4 -> V_3 ) ) ;
return 1 ;
}
T_11 F_114 ( T_2 * V_1 ) {
#define F_115 2
T_1 V_4 = F_77 ( V_1 , 1 ) ;
T_14 V_96 = F_116 ( V_1 , F_115 , TRUE ) ;
if ( V_96 ) {
F_117 ( V_4 -> V_3 ) ;
} else {
if ( V_4 -> V_3 )
F_118 ( F_78 ( V_4 -> V_3 ) , V_97 ) ;
}
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
static int F_119 ( T_2 * V_1 ) {
T_1 V_4 = F_77 ( V_1 , 1 ) ;
F_110 ( V_1 , F_120 ( V_4 -> V_3 ) ) ;
return 1 ;
}
T_11 F_121 ( T_2 * V_1 ) {
#define F_122 2
T_1 V_4 = F_77 ( V_1 , 1 ) ;
T_14 V_96 = F_116 ( V_1 , F_122 , TRUE ) ;
if ( V_96 ) {
F_123 ( V_4 -> V_3 ) ;
} else {
F_124 ( V_4 -> V_3 ) ;
}
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
static int F_125 ( T_2 * V_1 ) {
T_1 V_4 = F_77 ( V_1 , 1 ) ;
int V_24 = 0 ;
V_24 = F_126 ( V_4 -> V_3 ) ;
F_10 ( V_1 , V_24 > 0 ? V_24 : 0 ) ;
return 1 ;
}
T_11 F_127 ( T_2 * V_1 ) {
#define F_128 2
T_1 V_4 = F_77 ( V_1 , 1 ) ;
T_8 V_24 = ( int ) F_129 ( V_1 , F_128 ) ;
F_130 ( V_4 -> V_3 , V_24 ) ;
F_83 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_20 F_131 ( T_2 * V_1 ) {
T_1 V_4 = F_132 ( V_1 , 1 ) ;
if ( V_4 ) {
F_133 ( V_1 ,
L_13 ,
V_4 -> V_6 ? L_14 : L_15 ,
V_4 -> V_3 ? L_14 : L_15 ,
V_4 -> V_2 ? L_14 : L_15 ,
( V_4 -> V_2 == V_4 -> V_3 ) ? L_16 : L_17 ) ;
}
else {
F_80 ( V_1 , L_18 ) ;
}
return 1 ;
}
static int F_134 ( T_2 * V_1 ) {
T_1 V_4 = F_132 ( V_1 , 1 ) ;
if ( ! V_4 ) return 0 ;
if ( ! V_4 -> V_6 )
V_4 -> V_6 = TRUE ;
else
F_135 ( V_4 ) ;
return 0 ;
}
int F_136 ( T_2 * V_1 ) {
T_8 * V_98 [] = { & V_46 } ;
V_46 = - 1 ;
F_137 ( T_1 ) ;
F_138 ( T_1 ) ;
V_7 = F_139 () ;
F_140 ( V_98 , 1 ) ;
return 0 ;
}
