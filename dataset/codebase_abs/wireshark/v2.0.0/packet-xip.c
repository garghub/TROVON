static inline T_1
F_1 ( T_2 V_1 )
{
return V_1 & V_2 ;
}
static inline T_1
F_2 ( const struct V_3 * V_4 )
{
return V_4 -> V_5 . V_6 & V_7 ;
}
static inline T_1
F_3 ( T_2 V_1 )
{
return ( V_1 & V_8 ) == V_8 ;
}
static inline T_1
F_4 ( T_3 V_9 )
{
return V_9 == V_10 ;
}
static T_1
F_5 ( const struct V_3 * V_4 ,
T_2 V_11 , T_2 V_12 , T_4 * V_13 )
{
const T_2 * V_14 ;
T_4 V_15 , V_16 ;
T_1 V_6 ;
if ( F_2 ( V_4 ) ) {
return - V_17 ;
}
V_14 = V_4 -> V_5 . V_18 ;
V_15 = F_6 ( V_4 -> V_5 . V_6 ) ;
V_16 = 0xffffffff ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ , V_14 ++ ) {
T_2 V_1 ;
V_1 = * V_14 ;
if ( V_1 == V_8 ) {
if ( ( V_15 & V_16 ) !=
( V_20 & V_16 ) )
return - V_21 ;
else
break;
} else if ( V_1 >= V_12 ) {
return - V_22 ;
} else if ( V_11 < ( V_12 - 1 ) && V_1 <= V_11 ) {
return - V_23 ;
}
V_16 >>= 8 ;
* V_13 |= 1 << V_1 ;
}
return 0 ;
}
static T_1
F_7 ( const struct V_24 * V_25 )
{
T_1 V_6 , V_26 ;
T_1 V_27 = 0 ;
T_4 V_28 = 0 ;
V_26 = V_29 ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
T_3 V_9 ;
V_9 = V_25 -> V_30 [ V_6 ] . V_31 . V_32 ;
if ( V_27 ) {
if ( ! F_4 ( V_9 ) )
return - V_33 ;
} else if ( F_4 ( V_9 ) ) {
V_26 = V_6 ;
V_27 = 1 ;
}
}
for ( V_6 = 0 ; V_6 < V_26 ; V_6 ++ ) {
T_1 V_34 ;
V_34 = F_5 ( & V_25 -> V_30 [ V_6 ] , V_6 , V_26 , & V_28 ) ;
if ( V_34 )
return V_34 ;
}
if ( V_26 >= 1 ) {
T_4 V_15 ;
V_15 = V_25 -> V_30 [ V_26 - 1 ] . V_5 . V_6 ;
if ( V_15 == V_20 )
return - V_35 ;
if ( V_28 != ( ( 1U << V_26 ) - 1 ) )
return - V_36 ;
}
return V_26 ;
}
static inline T_5
F_8 ( T_2 V_1 )
{
const T_5 * V_37 = L_1 ;
V_1 &= ~ V_2 ;
if ( V_1 < V_38 )
return V_37 [ V_1 ] ;
else if ( F_3 ( V_1 ) )
return '*' ;
else
return '+' ;
}
static void
F_9 ( T_1 V_39 , T_6 * V_40 , const T_2 * V_41 )
{
T_1 V_6 ;
F_10 ( V_40 , '-' ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
if ( V_39 && V_41 [ V_6 ] == V_8 )
return;
if ( F_1 ( V_41 [ V_6 ] ) )
F_10 ( V_40 , '>' ) ;
F_10 ( V_40 , F_8 ( V_41 [ V_6 ] ) ) ;
}
}
static void
F_11 ( T_3 V_9 , T_6 * V_40 )
{
const T_5 * V_42 ;
T_7 V_43 = F_12 ( V_40 ) ;
if ( V_44 - V_43 - 1 < V_45 )
return;
V_42 = F_13 ( V_9 , V_46 ) ;
if ( V_42 )
F_14 ( V_40 , L_2 , V_42 ) ;
else
F_14 ( V_40 , L_3 , V_9 ) ;
}
static inline void
F_15 ( const struct V_47 * V_48 , T_6 * V_40 )
{
F_14 ( V_40 , L_4 ,
V_48 -> V_49 [ 0 ] ,
V_48 -> V_49 [ 1 ] ,
V_48 -> V_49 [ 2 ] ,
V_48 -> V_49 [ 3 ] ,
V_48 -> V_49 [ 4 ] ) ;
}
static int
F_16 ( const struct V_24 * V_48 , T_6 * V_40 )
{
T_1 V_39 , V_6 ;
V_39 = F_7 ( V_48 ) >= 1 ;
if ( ! V_39 )
F_10 ( V_40 , '!' ) ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
const struct V_3 * V_4 = & V_48 -> V_30 [ V_6 ] ;
if ( F_4 ( V_4 -> V_31 . V_32 ) )
break;
if ( V_6 > 0 )
F_17 ( V_40 , L_5 ) ;
F_11 ( V_4 -> V_31 . V_32 , V_40 ) ;
F_15 ( & V_4 -> V_31 , V_40 ) ;
F_9 ( V_39 , V_40 , V_4 -> V_5 . V_18 ) ;
}
return 0 ;
}
static void
F_18 ( T_8 * V_50 , T_9 * V_51 ,
const T_1 V_52 , const T_1 V_53 , const T_1 V_54 ,
const T_2 V_55 , T_2 V_56 )
{
T_9 * V_57 ;
T_10 * V_58 ;
struct V_24 V_59 ;
T_6 * V_40 ;
const T_5 * V_60 ;
T_11 V_6 , V_61 ;
T_2 V_62 = V_56 ;
V_58 = F_19 ( V_51 , V_53 , V_50 , V_56 ,
V_55 * V_63 , V_64 ) ;
V_40 = F_20 ( F_21 () ,
V_44 , V_44 ) ;
V_57 = F_22 ( V_58 , V_52 ) ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
for ( V_6 = 0 ; V_6 < V_55 ; V_6 ++ ) {
struct V_3 * V_4 = & V_59 . V_30 [ V_6 ] ;
V_4 -> V_31 . V_32 = F_23 ( V_50 , V_56 ) ;
V_56 += V_65 ;
for ( V_61 = 0 ; V_61 < V_66 / V_67 ; V_61 ++ ) {
V_4 -> V_31 . V_49 [ V_61 ] = F_23 ( V_50 , V_56 ) ;
V_56 += V_67 ;
}
F_24 ( V_50 , V_4 -> V_5 . V_18 , V_56 , V_68 ) ;
V_56 += V_68 ;
}
F_16 ( & V_59 , V_40 ) ;
V_60 = F_25 ( V_40 ) ;
F_26 ( V_57 , V_54 , V_50 , V_62 ,
V_63 * V_55 , V_60 , L_6 , V_60 ) ;
}
static T_1
F_27 ( T_8 * V_50 , T_12 * V_69 , T_9 * V_70 ,
T_1 V_56 , T_2 V_71 )
{
T_8 * V_72 ;
switch ( V_71 ) {
case V_73 :
case V_74 :
V_72 = F_28 ( V_50 , V_56 ) ;
return F_29 ( V_75 , V_72 , V_69 , V_70 ) ;
default:
return 0 ;
}
}
static T_1
F_30 ( T_8 * V_50 , T_12 * V_69 , T_9 * V_70 ,
T_10 * V_76 , T_1 V_56 )
{
T_8 * V_72 ;
T_2 V_77 = F_31 ( V_50 , V_78 ) ;
switch ( V_77 ) {
case V_79 :
V_72 = F_28 ( V_50 , V_56 ) ;
return F_29 ( V_80 , V_72 , V_69 , V_70 ) ;
default:
F_32 ( V_69 , V_76 , & V_81 ,
L_7 , V_77 ) ;
return 0 ;
}
}
static void
F_33 ( T_8 * V_50 , T_12 * V_69 , T_9 * V_70 )
{
T_9 * V_51 = NULL ;
T_10 * V_58 = NULL ;
T_10 * V_82 = NULL ;
T_10 * V_76 = NULL ;
T_10 * V_83 = NULL ;
T_1 V_56 ;
T_13 V_84 , V_85 ;
T_2 V_86 , V_87 , V_88 ;
V_86 = F_31 ( V_50 , V_89 ) ;
V_87 = F_31 ( V_50 , V_90 ) ;
V_84 = 8 + ( V_63 * V_86 ) +
( V_63 * V_87 ) ;
V_58 = F_19 ( V_70 , V_91 , V_50 , 0 , V_84 , V_92 ) ;
V_51 = F_22 ( V_58 , V_93 ) ;
F_19 ( V_51 , V_94 , V_50 ,
V_95 , 1 , V_64 ) ;
V_76 = F_19 ( V_51 , V_96 , V_50 ,
V_78 , 1 , V_64 ) ;
V_85 = F_34 ( V_50 , V_97 ) ;
V_82 = F_35 ( V_51 , V_98 ,
V_50 , V_97 , 2 , V_85 , L_8 ,
V_85 ) ;
if ( F_36 ( V_50 , V_84 ) != V_85 )
F_32 ( V_69 , V_82 , & V_99 ,
L_9 ,
V_85 , F_36 ( V_50 , V_84 ) ) ;
F_19 ( V_51 , V_100 , V_50 ,
V_101 , 1 , V_64 ) ;
V_83 = F_19 ( V_51 , V_102 , V_50 ,
V_89 , 1 , V_64 ) ;
if ( V_86 > V_29 ) {
F_32 ( V_69 , V_83 , & V_103 ,
L_10 ,
V_86 , V_29 ) ;
V_86 = V_29 ;
}
V_83 = F_19 ( V_51 , V_104 , V_50 ,
V_90 , 1 , V_64 ) ;
if ( V_87 > V_29 ) {
F_32 ( V_69 , V_83 , & V_105 ,
L_11 ,
V_87 , V_29 ) ;
V_87 = V_29 ;
}
V_88 = F_31 ( V_50 , V_106 ) ;
F_37 ( V_51 , V_107 , V_50 ,
V_106 , 1 , V_88 , L_12 , V_88 ,
V_88 == V_108 ? L_13 : L_14 ) ;
if ( V_86 > 0 )
F_18 ( V_50 , V_51 , V_109 ,
V_110 , V_111 ,
V_86 , V_112 ) ;
if ( V_87 > 0 )
F_18 ( V_50 , V_51 , V_113 ,
V_114 , V_115 ,
V_87 ,
V_112 + V_86 * V_63 ) ;
V_56 = V_112 + V_63 * ( V_86 + V_87 ) ;
V_56 += F_27 ( V_50 , V_69 , V_70 , V_56 ,
F_23 ( V_50 , V_112 +
( V_86 - 1 ) * V_63 ) ) ;
F_30 ( V_50 , V_69 , V_70 , V_76 , V_56 ) ;
}
static T_1
F_38 ( T_8 * V_50 , T_12 * V_69 , T_9 * V_70 ,
void * T_14 V_116 )
{
if ( F_39 ( V_50 ) < V_117 )
return 0 ;
F_40 ( V_69 -> V_118 , V_119 , L_15 ) ;
F_40 ( V_69 -> V_118 , V_120 , L_16 ) ;
F_33 ( V_50 , V_69 , V_70 ) ;
return F_41 ( V_50 ) ;
}
void
F_42 ( void )
{
static T_15 V_53 [] = {
{ & V_94 ,
{ L_17 , L_18 , V_121 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_96 ,
{ L_19 , L_20 , V_121 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_98 ,
{ L_21 , L_22 , V_124 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_100 ,
{ L_23 , L_24 , V_121 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_102 ,
{ L_25 , L_26 , V_121 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_104 ,
{ L_27 , L_28 , V_121 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_107 ,
{ L_29 , L_30 , V_121 ,
V_122 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_110 ,
{ L_31 , L_32 , V_125 ,
V_126 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_111 ,
{ L_33 , L_34 , V_127 ,
V_126 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_114 ,
{ L_35 , L_36 , V_125 ,
V_126 , NULL , 0x0 , NULL , V_123 } } ,
{ & V_115 ,
{ L_37 , L_38 , V_127 ,
V_126 , NULL , 0x0 , NULL , V_123 } }
} ;
static T_1 * V_52 [] = {
& V_93 ,
& V_109 ,
& V_113
} ;
static T_16 V_128 [] = {
{ & V_99 ,
{ L_39 , V_129 , V_130 ,
L_40 , V_131 } } ,
{ & V_81 ,
{ L_41 , V_129 , V_130 ,
L_42 , V_131 } } ,
{ & V_103 ,
{ L_43 , V_129 , V_130 ,
L_44 , V_131 } } ,
{ & V_105 ,
{ L_45 , V_129 , V_130 ,
L_46 , V_131 } }
} ;
T_17 * V_132 ;
V_91 = F_43 (
L_47 ,
L_15 ,
L_48 ) ;
F_44 ( L_48 , F_38 , V_91 ) ;
F_45 ( V_91 , V_53 , F_46 ( V_53 ) ) ;
F_47 ( V_52 , F_46 ( V_52 ) ) ;
V_132 = F_48 ( V_91 ) ;
F_49 ( V_132 , V_128 , F_46 ( V_128 ) ) ;
}
void
F_50 ( void )
{
T_18 V_133 ;
V_133 = F_51 ( F_38 , V_91 ) ;
F_52 ( L_49 , V_134 , V_133 ) ;
V_75 = F_53 ( L_50 ) ;
V_80 = F_53 ( L_51 ) ;
}
