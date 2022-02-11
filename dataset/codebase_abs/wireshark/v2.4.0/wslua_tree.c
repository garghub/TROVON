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
} else if ( F_44 ( V_1 , 1 ) ) {
return F_22 ( V_1 , L_7 ) ;
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
F_45 ( V_1 , 0 ) ;
F_40 ( V_1 , 1 ) ;
break;
case V_50 :
{
T_16 V_51 = ( T_16 ) ( F_46 ( V_1 , 1 ) ) ;
V_3 = F_47 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_51 ) ;
}
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_3 = F_48 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_49 ( V_1 , 1 ) ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_3 = F_50 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_49 ( V_1 , 1 ) ) ;
break;
case V_61 :
V_3 = F_51 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( float ) F_52 ( V_1 , 1 ) ) ;
break;
case V_62 :
V_3 = F_53 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( double ) F_52 ( V_1 , 1 ) ) ;
break;
case V_25 :
case V_26 :
V_3 = F_54 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_55 ( V_1 , 1 ) ) ;
break;
case V_63 :
case V_36 :
V_3 = F_56 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_57 ( V_1 , 1 ) ) ;
break;
case V_15 :
V_3 = F_58 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( const V_64 * ) F_57 ( V_1 , 1 ) ) ;
break;
case V_65 :
V_3 = F_59 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_60 ( V_1 , 1 ) ) ;
break;
case V_66 :
V_3 = F_61 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , F_62 ( V_1 , 1 ) ) ;
break;
case V_67 :
{
T_17 V_68 = F_63 ( V_1 , 1 ) ;
if ( V_68 -> type != V_69 ) {
F_22 ( V_1 , L_8 ) ;
return 0 ;
}
V_3 = F_64 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , * ( ( const T_16 * ) ( V_68 -> V_70 ) ) ) ;
}
break;
case V_71 :
{
T_17 V_68 = F_63 ( V_1 , 1 ) ;
if ( V_68 -> type != V_72 ) {
F_22 ( V_1 , L_9 ) ;
return 0 ;
}
V_3 = F_65 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , (struct V_73 * ) V_68 -> V_70 ) ;
}
break;
case V_74 :
{
T_17 V_68 = F_63 ( V_1 , 1 ) ;
if ( V_68 -> type != V_75 ) {
F_22 ( V_1 , L_10 ) ;
return 0 ;
}
V_3 = F_66 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , ( const V_64 * ) V_68 -> V_70 ) ;
}
break;
case V_16 :
case V_76 :
case V_77 :
case V_17 :
case V_18 :
case V_19 :
case V_78 :
case V_79 :
default:
F_22 ( V_1 , L_11 ) ;
return 0 ;
}
F_28 ( V_1 , 1 ) ;
} else {
if ( type == V_56 ) {
F_22 ( V_1 , L_12 ) ;
return 0 ;
}
V_3 = F_14 ( V_8 -> V_2 , V_10 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_47 ? V_80 : V_81 ) ;
}
if ( F_29 ( V_1 ) ) {
const T_13 * V_45 = F_37 ( V_1 , 1 ) ;
if ( V_45 ) F_67 ( V_3 , L_13 , V_45 ) ;
F_28 ( V_1 , 1 ) ;
}
} else {
if ( F_29 ( V_1 ) ) {
const T_13 * V_45 = F_37 ( V_1 , 1 ) ;
const int V_82 = F_68 () ;
if ( V_82 > - 1 ) {
V_3 = F_14 ( V_8 -> V_2 , V_82 , V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 , V_49 ) ;
F_67 ( V_3 , L_13 , V_45 ) ;
} else {
F_22 ( V_1 , L_14 ) ;
}
F_28 ( V_1 , 1 ) ;
} else {
F_22 ( V_1 , L_15 ) ;
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
T_11 F_69 ( T_2 * V_1 ) {
#define F_70 2
#define F_71 3
#define F_72 4
#define F_73 5
F_41 ( F_42 ( V_1 , FALSE ) ) ;
}
T_11 F_74 ( T_2 * V_1 ) {
#define F_75 2
#define F_76 3
#define F_77 4
#define F_78 5
F_41 ( F_42 ( V_1 , TRUE ) ) ;
}
static int F_79 ( T_2 * V_1 ) {
T_1 V_4 = F_80 ( V_1 , 1 ) ;
T_13 V_83 [ V_84 + 1 ] ;
T_13 * V_85 ;
if ( V_4 -> V_3 ) {
T_18 * V_86 = F_81 ( V_4 -> V_3 ) ;
if ( ! V_86 -> V_87 ) {
V_85 = V_83 ;
F_82 ( V_86 , V_83 ) ;
} else
V_85 = V_86 -> V_87 -> V_88 ;
if ( V_85 ) {
F_83 ( V_1 , V_85 ) ;
} else {
F_15 ( V_1 ) ;
}
} else {
F_15 ( V_1 ) ;
}
return 1 ;
}
T_11 F_84 ( T_2 * V_1 ) {
#define F_85 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
const T_13 * V_45 = F_57 ( V_1 , F_85 ) ;
F_67 ( V_4 -> V_3 , L_13 , V_45 ) ;
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_87 ( T_2 * V_1 ) {
#define F_88 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
const T_13 * V_45 = F_57 ( V_1 , F_88 ) ;
F_38 ( V_4 -> V_3 , L_13 , V_45 ) ;
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_89 ( T_2 * V_1 ) {
#define F_90 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
const T_13 * V_45 = F_57 ( V_1 , F_90 ) ;
F_91 ( V_4 -> V_3 , L_13 , V_45 ) ;
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_92 ( T_2 * V_1 ) {
#define F_93 2
#define F_94 3
#define F_95 4
T_1 V_4 = F_80 ( V_1 , 1 ) ;
int V_89 = ( int ) F_96 ( V_1 , F_93 , V_90 ) ;
int V_91 = ( int ) F_96 ( V_1 , F_94 , V_92 ) ;
T_19 * V_93 = F_97 ( V_89 , V_91 ) ;
const T_13 * V_94 ;
if ( F_29 ( V_1 ) >= F_95 ) {
V_94 = F_98 ( V_1 , F_95 ) ;
F_99 ( V_41 , V_4 -> V_3 , V_93 , L_13 , V_94 ) ;
} else {
F_100 ( V_41 , V_4 -> V_3 , V_93 ) ;
}
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_101 ( T_2 * V_1 ) {
#define F_102 2
#define F_103 3
T_1 V_4 = F_80 ( V_1 , 1 ) ;
T_20 V_95 = F_104 ( V_1 , F_102 ) ;
const T_13 * V_94 ;
if ( V_95 -> V_96 . V_97 == V_98 || V_95 -> V_96 . V_82 == V_99 ) {
F_22 ( V_1 , L_16 ) ;
return 0 ;
}
if ( F_29 ( V_1 ) >= F_103 ) {
V_94 = F_98 ( V_1 , F_103 ) ;
F_99 ( V_41 , V_4 -> V_3 , & V_95 -> V_96 , L_13 , V_94 ) ;
} else {
F_100 ( V_41 , V_4 -> V_3 , & V_95 -> V_96 ) ;
}
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_105 ( T_2 * V_1 ) {
#define F_106 2
#define F_107 3
#define F_108 4
T_1 V_4 = F_80 ( V_1 , 1 ) ;
T_20 V_95 = F_104 ( V_1 , F_102 ) ;
T_5 V_9 ;
const T_13 * V_94 ;
if ( V_95 -> V_96 . V_97 == V_98 || V_95 -> V_96 . V_82 == V_99 ) {
F_22 ( V_1 , L_16 ) ;
return 0 ;
}
V_9 = F_24 ( V_1 , F_107 ) ;
if ( ! V_9 ) {
V_9 = F_25 ( F_26 () , struct V_33 ) ;
V_9 -> V_21 = F_109 ( V_1 , F_107 ) ;
if ( ! V_9 -> V_21 ) {
V_9 -> V_21 = F_25 ( F_26 () , struct V_34 ) ;
}
V_9 -> V_21 -> V_22 = V_35 ;
V_9 -> V_23 = 0 ;
V_9 -> V_24 = 0 ;
}
if ( F_29 ( V_1 ) >= F_103 ) {
V_94 = F_98 ( V_1 , F_103 ) ;
F_110 ( V_4 -> V_2 , V_41 , & V_95 -> V_96 ,
V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 ,
L_13 , V_94 ) ;
} else {
F_111 ( V_4 -> V_2 , V_41 , & V_95 -> V_96 ,
V_9 -> V_21 -> V_22 , V_9 -> V_23 , V_9 -> V_24 ) ;
}
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
static int F_112 ( T_2 * V_1 ) {
T_1 V_4 = F_80 ( V_1 , 1 ) ;
if ( V_4 -> V_2 ) {
F_113 ( V_1 , F_114 ( V_4 -> V_2 ) -> V_100 ) ;
}
else {
F_113 ( V_1 , FALSE ) ;
}
return 1 ;
}
static int F_115 ( T_2 * V_1 ) {
T_1 V_4 = F_80 ( V_1 , 1 ) ;
F_113 ( V_1 , F_116 ( V_4 -> V_3 ) ) ;
return 1 ;
}
T_11 F_117 ( T_2 * V_1 ) {
#define F_118 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
T_14 V_101 = F_119 ( V_1 , F_118 , TRUE ) ;
if ( V_101 ) {
F_120 ( V_4 -> V_3 ) ;
} else {
if ( V_4 -> V_3 )
F_121 ( F_81 ( V_4 -> V_3 ) , V_102 ) ;
}
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
static int F_122 ( T_2 * V_1 ) {
T_1 V_4 = F_80 ( V_1 , 1 ) ;
F_113 ( V_1 , F_123 ( V_4 -> V_3 ) ) ;
return 1 ;
}
T_11 F_124 ( T_2 * V_1 ) {
#define F_125 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
T_14 V_101 = F_119 ( V_1 , F_125 , TRUE ) ;
if ( V_101 ) {
F_126 ( V_4 -> V_3 ) ;
} else {
F_127 ( V_4 -> V_3 ) ;
}
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
static int F_128 ( T_2 * V_1 ) {
T_1 V_4 = F_80 ( V_1 , 1 ) ;
int V_24 = 0 ;
V_24 = F_129 ( V_4 -> V_3 ) ;
F_10 ( V_1 , V_24 > 0 ? V_24 : 0 ) ;
return 1 ;
}
T_11 F_130 ( T_2 * V_1 ) {
#define F_131 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
T_8 V_24 = ( int ) F_132 ( V_1 , F_131 ) ;
F_133 ( V_4 -> V_3 , V_24 ) ;
F_86 ( V_1 , 1 ) ;
F_41 ( 1 ) ;
}
T_11 F_134 ( T_2 * V_1 ) {
#define F_135 2
T_1 V_4 = F_80 ( V_1 , 1 ) ;
if ( ! V_4 ) return 0 ;
T_12 V_103 = F_23 ( V_1 , F_135 ) ;
if ( V_103 ) {
F_113 ( V_1 , F_136 ( V_4 -> V_2 , V_103 -> V_10 ) ) ;
}
else {
T_21 V_104 = F_137 ( V_1 , F_135 ) ;
if ( ! V_104 ) return 0 ;
F_113 ( V_1 , F_136 ( V_4 -> V_2 , F_138 ( V_104 ) ) ) ;
}
F_41 ( 1 ) ;
}
T_22 F_139 ( T_2 * V_1 ) {
T_1 V_4 = F_140 ( V_1 , 1 ) ;
if ( V_4 ) {
F_141 ( V_1 ,
L_17 ,
V_4 -> V_6 ? L_18 : L_19 ,
V_4 -> V_3 ? L_18 : L_19 ,
V_4 -> V_2 ? L_18 : L_19 ,
( V_4 -> V_2 == V_4 -> V_3 ) ? L_20 : L_21 ) ;
}
else {
F_83 ( V_1 , L_22 ) ;
}
return 1 ;
}
static int F_142 ( T_2 * V_1 ) {
T_1 V_4 = F_140 ( V_1 , 1 ) ;
if ( ! V_4 ) return 0 ;
if ( ! V_4 -> V_6 )
V_4 -> V_6 = TRUE ;
else
F_143 ( V_4 ) ;
return 0 ;
}
int F_144 ( T_2 * V_1 ) {
T_8 * V_105 [] = { & V_46 } ;
V_46 = - 1 ;
F_145 ( T_1 ) ;
F_146 ( T_1 ) ;
V_7 = F_147 () ;
F_148 ( V_105 , 1 ) ;
return 0 ;
}
