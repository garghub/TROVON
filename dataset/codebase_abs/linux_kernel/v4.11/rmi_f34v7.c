static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_9 + V_2 -> V_10 . V_11 . V_12 ,
& V_3 ,
sizeof( V_3 ) ) ;
if ( V_5 < 0 ) {
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_1 , V_15 ) ;
return V_5 ;
}
V_2 -> V_10 . V_16 = V_3 >> 7 ;
V_2 -> V_10 . V_12 = V_3 & 0x1f ;
if ( V_2 -> V_10 . V_12 != 0x00 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_2 ,
V_15 , V_2 -> V_10 . V_12 , V_2 -> V_10 . V_4 ) ;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_9 + V_2 -> V_10 . V_11 . V_17 ,
& V_4 ,
sizeof( V_4 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_3 ,
V_15 ) ;
return V_5 ;
}
V_2 -> V_10 . V_4 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_18 )
{
int V_19 = 0 ;
int V_20 = ( ( V_18 * 1000 ) / V_21 ) + 1 ;
do {
F_6 ( V_22 , V_21 ) ;
V_19 ++ ;
F_1 ( V_2 ) ;
if ( ( V_2 -> V_10 . V_4 == V_23 )
&& ( V_2 -> V_10 . V_12 == 0x00 ) ) {
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_4 ) ;
return 0 ;
}
} while ( V_19 < V_20 );
F_4 ( & V_2 -> V_6 -> V_14 ,
L_5 , V_15 ) ;
return - V_24 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_25 )
{
int V_5 ;
T_1 V_26 ;
struct V_27 V_28 ;
V_26 = V_2 -> V_6 -> V_8 . V_9 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
switch ( V_25 ) {
case V_29 :
V_28 . V_30 = V_31 ;
V_28 . V_4 = V_32 ;
break;
case V_33 :
V_28 . V_30 = V_31 ;
V_28 . V_4 = V_34 ;
break;
case V_35 :
V_28 . V_30 = V_36 ;
V_28 . V_4 = V_34 ;
break;
case V_37 :
V_28 . V_30 = V_38 ;
V_28 . V_4 = V_34 ;
break;
case V_39 :
V_28 . V_30 = V_40 ;
V_28 . V_4 = V_34 ;
break;
case V_41 :
V_28 . V_30 = V_42 ;
V_28 . V_4 = V_34 ;
break;
case V_43 :
V_28 . V_30 = V_44 ;
V_28 . V_4 = V_34 ;
break;
case V_45 :
V_28 . V_30 = V_46 ;
V_28 . V_4 = V_47 ;
break;
}
V_28 . V_48 [ 0 ] = V_2 -> V_49 [ 0 ] ;
V_28 . V_48 [ 1 ] = V_2 -> V_49 [ 1 ] ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_30 ,
& V_28 , sizeof( V_28 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_6 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_5 ;
T_1 V_26 ;
T_1 V_4 ;
V_26 = V_2 -> V_6 -> V_8 . V_9 ;
switch ( V_25 ) {
case V_50 :
case V_51 :
case V_52 :
V_4 = V_53 ;
break;
case V_54 :
V_4 = V_55 ;
break;
case V_29 :
V_4 = V_32 ;
break;
case V_33 :
case V_35 :
case V_37 :
case V_39 :
case V_41 :
case V_43 :
V_4 = V_34 ;
break;
case V_45 :
V_4 = V_47 ;
break;
default:
F_4 ( & V_2 -> V_6 -> V_14 , L_7 ,
V_15 , V_25 ) ;
return - V_56 ;
}
V_2 -> V_10 . V_4 = V_4 ;
switch ( V_25 ) {
case V_29 :
case V_33 :
case V_35 :
case V_37 :
case V_39 :
case V_41 :
case V_43 :
case V_45 :
V_5 = F_7 ( V_2 , V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return 0 ;
default:
break;
}
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_8 ,
V_15 , V_4 ) ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_17 ,
& V_4 , sizeof( V_4 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_9 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_5 ;
T_1 V_26 ;
T_1 V_57 ;
V_26 = V_2 -> V_6 -> V_8 . V_9 ;
switch ( V_25 ) {
case V_50 :
V_57 = V_31 ;
break;
case V_51 :
case V_54 :
if ( V_2 -> V_10 . V_58 == V_59 )
V_57 = V_38 ;
else if ( V_2 -> V_10 . V_58 == V_60 )
V_57 = V_40 ;
else if ( V_2 -> V_10 . V_58 == V_61 )
V_57 = V_62 ;
else if ( V_2 -> V_10 . V_58 == V_63 )
V_57 = V_36 ;
else if ( V_2 -> V_10 . V_58 == V_64 )
V_57 = V_42 ;
break;
case V_52 :
V_57 = V_44 ;
break;
case V_29 :
V_57 = V_31 ;
break;
case V_35 :
V_57 = V_36 ;
break;
case V_37 :
V_57 = V_38 ;
break;
case V_39 :
V_57 = V_40 ;
break;
case V_41 :
V_57 = V_42 ;
break;
case V_43 :
V_57 = V_44 ;
break;
case V_45 :
V_57 = V_46 ;
break;
default:
F_4 ( & V_2 -> V_6 -> V_14 , L_7 ,
V_15 , V_25 ) ;
return - V_56 ;
}
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_30 ,
& V_57 , sizeof( V_57 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_10 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_26 ;
T_2 V_65 ;
T_3 V_66 = 0 ;
V_26 = V_2 -> V_6 -> V_8 . V_9 ;
V_2 -> V_10 . V_58 = V_64 ;
V_5 = F_10 ( V_2 , V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_66 ,
& V_66 , sizeof( V_66 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_11 ,
V_15 ) ;
return V_5 ;
}
F_12 ( V_2 -> V_10 . V_67 , & V_65 ) ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_68 ,
& V_65 , sizeof( V_65 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_12 ,
V_15 ) ;
return V_5 ;
}
V_5 = F_9 ( V_2 , V_54 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_13 ,
V_15 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 , V_69 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_14 ,
V_15 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_48 ,
V_2 -> V_10 . V_70 ,
V_2 -> V_10 . V_71 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_15 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
const void * V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
int V_77 ;
int V_78 ;
T_3 V_79 ;
T_3 V_75 ;
const struct V_72 * V_80 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_10 . V_81 ; V_77 ++ ) {
V_78 = V_77 * 8 + 2 ;
V_80 = V_72 + V_78 ;
V_79 = F_14 ( V_80 -> V_79 ) ;
V_75 = F_14 ( V_80 -> V_82 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_16 ,
V_15 , V_77 , sizeof( struct V_72 ) , V_80 ) ;
switch ( V_80 -> V_30 & 0x1f ) {
case V_31 :
V_74 -> V_83 = V_79 ;
V_76 -> V_83 = V_75 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_17 ,
V_15 , V_74 -> V_83 ) ;
break;
case V_38 :
V_74 -> V_84 = V_79 ;
V_76 -> V_84 = V_75 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_18 ,
V_15 , V_74 -> V_84 ) ;
break;
case V_40 :
V_74 -> V_85 = V_79 ;
V_76 -> V_85 = V_75 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_19 ,
V_15 , V_74 -> V_85 ) ;
break;
case V_42 :
V_74 -> V_86 = V_79 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_20 ,
V_15 , V_74 -> V_86 ) ;
break;
case V_44 :
V_74 -> V_87 = V_79 ;
V_76 -> V_87 = V_75 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_21 ,
V_15 , V_74 -> V_87 ) ;
break;
case V_62 :
V_74 -> V_88 = V_79 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_22 ,
V_15 , V_74 -> V_88 ) ;
break;
case V_36 :
V_74 -> V_89 = V_79 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_23 ,
V_15 , V_74 -> V_89 ) ;
break;
case V_90 :
V_74 -> V_91 = V_79 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_24 ,
V_15 , V_74 -> V_91 ) ;
break;
}
}
}
static int F_15 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_26 ;
int V_92 ;
T_1 V_93 ;
struct V_94 V_95 ;
V_26 = V_2 -> V_6 -> V_8 . V_96 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_26 ,
& V_93 ,
sizeof( V_93 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_25 , V_15 ) ;
return V_5 ;
}
V_92 = ( V_93 & 0x7 ) + 1 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_26 + V_92 ,
& V_95 ,
sizeof( V_95 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_26 ,
V_15 ) ;
return V_5 ;
}
V_2 -> V_49 [ 0 ] = V_95 . V_97 ;
V_2 -> V_49 [ 1 ] = V_95 . V_98 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_27 ,
V_2 -> V_49 [ 1 ] , V_2 -> V_49 [ 0 ] ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_5 ;
int V_77 , V_99 ;
T_1 V_26 ;
int V_92 ;
T_1 * V_80 ;
T_1 V_93 ;
struct V_94 V_95 ;
V_26 = V_2 -> V_6 -> V_8 . V_96 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_26 ,
& V_93 ,
sizeof( V_93 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_25 , V_15 ) ;
return V_5 ;
}
V_92 = ( V_93 & 0x07 ) + 1 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_26 + V_92 ,
& V_95 ,
sizeof( V_95 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_26 ,
V_15 ) ;
return V_5 ;
}
V_2 -> V_49 [ 0 ] = V_95 . V_97 ;
V_2 -> V_49 [ 1 ] = V_95 . V_98 ;
V_2 -> V_10 . V_100 = F_14 ( V_95 . V_100 ) ;
V_2 -> V_10 . V_67 =
F_14 ( V_95 . V_67 ) ;
V_2 -> V_10 . V_101 = F_14 ( V_95 . V_101 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_28 ,
V_15 , V_2 -> V_10 . V_100 ) ;
V_2 -> V_10 . V_11 . V_12 = V_102 ;
V_2 -> V_10 . V_11 . V_30 = V_103 ;
V_2 -> V_10 . V_11 . V_66 = V_104 ;
V_2 -> V_10 . V_11 . V_68 = V_105 ;
V_2 -> V_10 . V_11 . V_17 = V_106 ;
V_2 -> V_10 . V_11 . V_48 = V_107 ;
V_2 -> V_10 . V_108 = V_95 . V_109 [ 1 ] & V_110 ;
V_2 -> V_10 . V_111 =
V_95 . V_109 [ 1 ] & V_112 ;
if ( V_93 & V_113 ) {
char V_114 [ V_115 ] ;
int V_77 = 0 ;
T_1 * V_116 = V_2 -> V_117 ;
* V_116 = '\0' ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_118 ,
V_114 ,
sizeof( V_114 ) ) ;
if ( V_5 )
return V_5 ;
while ( V_77 < sizeof( V_114 ) && ! V_114 [ V_77 ] )
V_77 ++ ;
for (; V_77 < sizeof( V_114 ) ; V_77 ++ )
V_116 += snprintf ( V_116 , V_2 -> V_117
+ sizeof( V_2 -> V_117 ) - V_116 ,
L_29 , V_114 [ V_77 ] ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_30 ,
V_2 -> V_117 ) ;
}
V_2 -> V_10 . V_81 = 0 ;
for ( V_77 = 0 ; V_77 < sizeof( V_95 . V_109 ) ; V_77 ++ )
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ )
if ( V_95 . V_109 [ V_77 ] & ( 1 << V_99 ) )
V_2 -> V_10 . V_81 ++ ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_31 ,
V_15 , sizeof( V_95 . V_109 ) ,
V_95 . V_109 ) ;
V_2 -> V_10 . V_71 = V_2 -> V_10 . V_81 * 8 + 2 ;
V_2 -> V_10 . V_70 = F_17 ( & V_2 -> V_6 -> V_14 ,
V_2 -> V_10 . V_71 ,
V_119 ) ;
if ( ! V_2 -> V_10 . V_70 ) {
V_2 -> V_10 . V_120 = 0 ;
return - V_121 ;
}
V_2 -> V_10 . V_120 = V_2 -> V_10 . V_71 ;
V_80 = V_2 -> V_10 . V_70 ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_32 ,
V_15 ) ;
return V_5 ;
}
F_13 ( V_2 , V_80 ,
& V_2 -> V_10 . V_74 , & V_2 -> V_10 . V_76 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_3 V_73 ;
V_73 = V_2 -> V_10 . V_122 . V_83 . V_123 / V_2 -> V_10 . V_100 ;
V_2 -> V_124 += V_73 ;
if ( V_73 != V_2 -> V_10 . V_74 . V_83 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_33 ,
V_73 , V_2 -> V_10 . V_74 . V_83 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_3 V_73 ;
V_73 = V_2 -> V_10 . V_122 . V_84 . V_123 / V_2 -> V_10 . V_100 ;
V_2 -> V_124 += V_73 ;
if ( V_73 != V_2 -> V_10 . V_74 . V_84 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_34 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_3 V_73 ;
V_73 = V_2 -> V_10 . V_122 . V_85 . V_123 / V_2 -> V_10 . V_100 ;
V_2 -> V_124 += V_73 ;
if ( V_73 != V_2 -> V_10 . V_74 . V_85 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_35 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_3 V_73 ;
V_73 = V_2 -> V_10 . V_122 . V_87 . V_123 / V_2 -> V_10 . V_100 ;
V_2 -> V_124 += V_73 ;
if ( V_73 != V_2 -> V_10 . V_74 . V_87 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_36 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_3 V_73 ;
V_73 = V_2 -> V_10 . V_122 . V_89 . V_123 / V_2 -> V_10 . V_100 ;
V_2 -> V_124 += V_73 ;
if ( V_73 != V_2 -> V_10 . V_74 . V_89 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_37 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_5 ;
F_24 ( & V_2 -> V_6 -> V_14 , L_38 ) ;
switch ( V_2 -> V_10 . V_58 ) {
case V_59 :
V_5 = F_9 ( V_2 , V_37 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
case V_60 :
V_5 = F_9 ( V_2 , V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
case V_63 :
V_5 = F_9 ( V_2 , V_35 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
}
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
F_24 ( & V_2 -> V_6 -> V_14 , L_39 ) ;
V_5 = F_9 ( V_2 , V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 ;
F_24 ( & V_2 -> V_6 -> V_14 , L_40 ) ;
V_5 = F_9 ( V_2 , V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 . V_58 = V_59 ;
V_5 = F_23 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_10 . V_108 ) {
V_2 -> V_10 . V_58 = V_60 ;
V_5 = F_23 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_2 -> V_10 . V_126 && V_2 -> V_10 . V_111 ) {
V_5 = F_25 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_3 V_127 ,
T_1 V_4 )
{
int V_5 ;
T_1 V_26 ;
T_2 V_65 ;
T_3 V_128 ;
T_3 V_129 ;
T_3 V_130 = V_127 ;
T_3 V_66 = 0 ;
T_3 V_78 = 0 ;
V_26 = V_2 -> V_6 -> V_8 . V_9 ;
V_5 = F_10 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_66 ,
& V_66 , sizeof( V_66 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_11 ,
V_15 ) ;
return V_5 ;
}
V_129 = F_28 ( V_2 -> V_10 . V_101 ,
( T_3 ) ( V_131 / V_2 -> V_10 . V_100 ) ) ;
do {
V_128 = F_28 ( V_130 , V_129 ) ;
F_12 ( V_128 , & V_65 ) ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_68 ,
& V_65 , sizeof( V_65 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_41 ,
V_15 , V_130 ) ;
return V_5 ;
}
V_5 = F_9 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_42 ,
V_15 , V_130 ) ;
return V_5 ;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_48 ,
& V_2 -> V_10 . V_70 [ V_78 ] ,
V_128 * V_2 -> V_10 . V_100 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_43 ,
V_15 , V_130 ) ;
return V_5 ;
}
V_78 += ( V_128 * V_2 -> V_10 . V_100 ) ;
V_130 -= V_128 ;
} while ( V_130 );
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const void * V_132 , T_3 V_127 ,
T_1 V_4 )
{
int V_5 ;
T_1 V_26 ;
T_2 V_65 ;
T_3 V_128 ;
T_3 V_129 ;
T_3 V_130 = V_127 ;
T_3 V_66 = 0 ;
V_26 = V_2 -> V_6 -> V_8 . V_9 ;
V_5 = F_10 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_66 ,
& V_66 , sizeof( V_66 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_11 ,
V_15 ) ;
return V_5 ;
}
if ( V_2 -> V_10 . V_101 > ( V_131 / V_2 -> V_10 . V_100 ) )
V_129 = V_131 / V_2 -> V_10 . V_100 ;
else
V_129 = V_2 -> V_10 . V_101 ;
do {
V_128 = F_28 ( V_130 , V_129 ) ;
F_12 ( V_128 , & V_65 ) ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_68 ,
& V_65 , sizeof( V_65 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_41 ,
V_15 , V_130 ) ;
return V_5 ;
}
V_5 = F_9 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_8 ( V_2 -> V_6 -> V_7 ,
V_26 + V_2 -> V_10 . V_11 . V_48 ,
V_132 , V_128 * V_2 -> V_10 . V_100 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_44 ,
V_15 , V_130 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_45 ,
V_15 , V_130 ) ;
return V_5 ;
}
V_132 += ( V_128 * V_2 -> V_10 . V_100 ) ;
V_130 -= V_128 ;
V_2 -> V_133 += V_128 ;
V_2 -> V_134 = ( V_2 -> V_133 * 100 ) /
V_2 -> V_124 ;
} while ( V_130 );
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_29 ( V_2 , V_2 -> V_10 . V_135 ,
V_2 -> V_10 . V_136 ,
V_51 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_58 = V_59 ;
V_2 -> V_10 . V_135 = V_2 -> V_10 . V_122 . V_84 . V_137 ;
V_2 -> V_10 . V_138 = V_2 -> V_10 . V_122 . V_84 . V_123 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_138 / V_2 -> V_10 . V_100 ;
return F_30 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_58 = V_60 ;
V_2 -> V_10 . V_135 = V_2 -> V_10 . V_122 . V_85 . V_137 ;
V_2 -> V_10 . V_138 = V_2 -> V_10 . V_122 . V_85 . V_123 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_138 / V_2 -> V_10 . V_100 ;
return F_30 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_29 ( V_2 , V_2 -> V_10 . V_122 . V_87 . V_137 ,
V_2 -> V_10 . V_122 . V_87 . V_123 /
V_2 -> V_10 . V_100 ,
V_52 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_10 . V_58 = V_64 ;
V_2 -> V_10 . V_135 = V_2 -> V_10 . V_122 . V_86 . V_137 ;
V_2 -> V_10 . V_138 = V_2 -> V_10 . V_122 . V_86 . V_123 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_138 / V_2 -> V_10 . V_100 ;
if ( V_2 -> V_10 . V_136 != V_2 -> V_10 . V_74 . V_86 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_46 ,
V_15 ) ;
return - V_56 ;
}
V_5 = F_9 ( V_2 , V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_47 , V_15 ) ;
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_30 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_3 V_73 ;
int V_5 ;
V_73 = V_2 -> V_10 . V_74 . V_89 ;
V_2 -> V_10 . V_58 = V_63 ;
V_2 -> V_10 . V_138 = V_2 -> V_10 . V_100 * V_73 ;
F_36 ( & V_2 -> V_6 -> V_14 , V_2 -> V_10 . V_70 ) ;
V_2 -> V_10 . V_70 = F_17 ( & V_2 -> V_6 -> V_14 ,
V_2 -> V_10 . V_138 , V_119 ) ;
if ( ! V_2 -> V_10 . V_70 ) {
V_2 -> V_10 . V_120 = 0 ;
return - V_121 ;
}
V_2 -> V_10 . V_120 = V_2 -> V_10 . V_138 ;
V_5 = F_27 ( V_2 , V_73 , V_54 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_23 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_34 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 . V_58 = V_63 ;
V_2 -> V_10 . V_135 = V_2 -> V_10 . V_70 ;
V_2 -> V_10 . V_138 = V_2 -> V_10 . V_122 . V_89 . V_123 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_138 / V_2 -> V_10 . V_100 ;
V_5 = F_30 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_3 V_139 ;
V_139 = V_2 -> V_10 . V_122 . V_83 . V_123 / V_2 -> V_10 . V_100 ;
return F_29 ( V_2 , V_2 -> V_10 . V_122 . V_83 . V_137 ,
V_139 , V_50 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_76 . V_83 != V_2 -> V_10 . V_122 . V_76 . V_83 ) {
V_2 -> V_10 . V_126 = true ;
return;
}
if ( V_2 -> V_10 . V_76 . V_84 != V_2 -> V_10 . V_122 . V_76 . V_84 ) {
V_2 -> V_10 . V_126 = true ;
return;
}
if ( V_2 -> V_10 . V_108 &&
V_2 -> V_10 . V_76 . V_85 != V_2 -> V_10 . V_122 . V_76 . V_85 ) {
V_2 -> V_10 . V_126 = true ;
return;
}
if ( V_2 -> V_10 . V_111 &&
V_2 -> V_10 . V_76 . V_87 != V_2 -> V_10 . V_122 . V_76 . V_87 ) {
V_2 -> V_10 . V_126 = true ;
return;
}
V_2 -> V_10 . V_126 = false ;
}
static void F_39 ( struct V_1 * V_2 ,
const void * V_140 )
{
int V_77 ;
int V_141 ;
unsigned int V_142 ;
unsigned int V_143 ;
unsigned int V_65 ;
const void * V_144 ;
const struct V_145 * V_146 ;
V_141 = V_2 -> V_10 . V_122 . V_147 . V_123 / 4 - 1 ;
for ( V_77 = 1 ; V_77 <= V_141 ; V_77 ++ ) {
V_142 = F_40 ( V_2 -> V_10 . V_122 . V_147 . V_137 + V_77 * 4 ) ;
V_146 = V_140 + V_142 ;
V_143 = F_14 ( V_146 -> V_143 ) ;
V_144 = V_140 + F_41 ( V_146 -> V_148 ) ;
V_65 = F_41 ( V_146 -> V_149 ) ;
switch ( V_143 ) {
case V_150 :
case V_151 :
V_2 -> V_10 . V_122 . V_89 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_89 . V_123 = V_65 ;
break;
case V_152 :
case V_153 :
V_2 -> V_10 . V_122 . V_91 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_91 . V_123 = V_65 ;
break;
default:
break;
}
}
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned int V_77 ;
unsigned int V_141 ;
unsigned int V_142 ;
unsigned int V_92 ;
unsigned int V_143 ;
unsigned int V_65 ;
const void * V_140 = V_2 -> V_10 . V_140 ;
const T_1 * V_144 ;
const struct V_145 * V_146 ;
const struct V_154 * V_155 = V_140 ;
V_2 -> V_10 . V_122 . V_156 = F_41 ( V_155 -> V_156 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_48 ,
V_15 , V_2 -> V_10 . V_122 . V_156 ) ;
V_92 = F_41 ( V_155 -> V_157 ) ;
V_146 = V_140 + V_92 ;
V_92 = F_41 ( V_146 -> V_148 ) ;
V_141 = F_41 ( V_146 -> V_149 ) / 4 ;
for ( V_77 = 0 ; V_77 < V_141 ; V_77 ++ ) {
V_142 = F_40 ( V_140 + V_92 ) ;
V_92 += 4 ;
V_146 = V_140 + V_142 ;
V_143 = F_14 ( V_146 -> V_143 ) ;
V_144 = V_140 + F_41 ( V_146 -> V_148 ) ;
V_65 = F_41 ( V_146 -> V_149 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_49 , V_15 ,
V_143 , V_65 ) ;
switch ( V_143 ) {
case V_158 :
case V_159 :
V_2 -> V_10 . V_122 . V_83 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_83 . V_123 = V_65 ;
break;
case V_160 :
case V_161 :
V_2 -> V_10 . V_122 . V_84 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_84 . V_123 = V_65 ;
break;
case V_162 :
V_2 -> V_10 . V_122 . V_163 = * V_144 ;
V_2 -> V_10 . V_122 . V_147 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_147 . V_123 = V_65 ;
F_39 ( V_2 , V_140 ) ;
break;
case V_164 :
V_2 -> V_10 . V_122 . V_165 = true ;
V_2 -> V_10 . V_122 . V_87 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_87 . V_123 = V_65 ;
break;
case V_166 :
V_2 -> V_10 . V_122 . V_167 = true ;
V_2 -> V_10 . V_122 . V_85 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_85 . V_123 = V_65 ;
break;
case V_168 :
V_2 -> V_10 . V_122 . V_169 = true ;
V_2 -> V_10 . V_122 . V_86 . V_137 = V_144 ;
V_2 -> V_10 . V_122 . V_86 . V_123 = V_65 ;
break;
case V_170 :
V_2 -> V_10 . V_122 . V_171 = true ;
V_2 -> V_10 . V_122 . V_172 =
F_40 ( V_144 + 4 ) ;
break;
default:
break;
}
}
}
static int F_43 ( struct V_1 * V_2 )
{
const struct V_154 * V_155 = V_2 -> V_10 . V_140 ;
memset ( & V_2 -> V_10 . V_122 , 0x00 , sizeof( V_2 -> V_10 . V_122 ) ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_50 ,
V_15 , V_155 -> V_173 ) ;
switch ( V_155 -> V_173 ) {
case V_174 :
F_42 ( V_2 ) ;
break;
default:
F_4 ( & V_2 -> V_6 -> V_14 , L_51 ,
V_155 -> V_173 ) ;
return - V_56 ;
}
if ( ! V_2 -> V_10 . V_122 . V_169 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_52 ,
V_15 ) ;
return - V_56 ;
}
F_13 ( V_2 , V_2 -> V_10 . V_122 . V_86 . V_137 ,
& V_2 -> V_10 . V_122 . V_74 , & V_2 -> V_10 . V_122 . V_76 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 , const struct V_175 * V_176 )
{
int V_5 ;
F_15 ( V_2 ) ;
V_2 -> V_10 . V_140 = V_176 -> V_137 ;
V_2 -> V_133 = 0 ;
V_2 -> V_124 = 0 ;
V_5 = F_43 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
if ( ! V_2 -> V_10 . V_126 ) {
V_5 = F_18 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
V_5 = F_19 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
if ( V_2 -> V_10 . V_108 &&
V_2 -> V_10 . V_122 . V_167 ) {
V_5 = F_20 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
}
if ( V_2 -> V_10 . V_111 && V_2 -> V_10 . V_122 . V_165 ) {
V_5 = F_21 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
}
} else {
V_5 = F_22 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
}
V_5 = F_26 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
if ( V_2 -> V_10 . V_126 ) {
V_5 = F_35 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
F_24 ( & V_2 -> V_6 -> V_14 , L_53 ,
V_15 ) ;
}
F_24 ( & V_2 -> V_6 -> V_14 , L_54 ,
V_2 -> V_10 . V_122 . V_83 . V_123 ) ;
V_5 = F_37 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
F_24 ( & V_2 -> V_6 -> V_14 , L_55 ,
V_2 -> V_10 . V_122 . V_84 . V_123 ) ;
V_2 -> V_10 . V_58 = V_59 ;
V_5 = F_31 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
if ( V_2 -> V_10 . V_108 && V_2 -> V_10 . V_122 . V_167 ) {
F_24 ( & V_2 -> V_6 -> V_14 , L_56 ) ;
V_5 = F_32 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
}
if ( V_2 -> V_10 . V_126 ) {
if ( V_2 -> V_10 . V_111 && V_2 -> V_10 . V_122 . V_165 ) {
F_24 ( & V_2 -> V_6 -> V_14 , L_57 ) ;
V_5 = F_33 ( V_2 ) ;
if ( V_5 < 0 )
goto V_177;
}
}
V_177:
return V_5 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_10 . V_16 )
return 0 ;
V_5 = F_9 ( V_2 , V_45 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_125 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ! V_2 -> V_10 . V_16 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_58 , V_15 ) ;
return - V_56 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , const struct V_175 * V_176 )
{
int V_5 = 0 ;
V_2 -> V_10 . V_58 = V_59 ;
V_2 -> V_10 . V_140 = V_176 -> V_137 ;
V_5 = F_43 ( V_2 ) ;
if ( V_5 < 0 )
goto exit;
if ( ! V_2 -> V_10 . V_178 && V_2 -> V_10 . V_126 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_59 ,
V_15 ) ;
V_5 = - V_56 ;
goto exit;
}
F_24 ( & V_2 -> V_6 -> V_14 , L_60 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_2 -> V_10 . V_16 ) {
F_24 ( & V_2 -> V_6 -> V_14 , L_61 ,
V_15 ) ;
}
F_45 ( V_2 ) ;
return 0 ;
exit:
return V_5 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_96 + V_179 ,
V_2 -> V_49 ,
sizeof( V_2 -> V_49 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_62 ,
V_15 ) ;
return V_5 ;
}
if ( V_2 -> V_49 [ 1 ] == '5' ) {
V_2 -> V_163 = 5 ;
} else if ( V_2 -> V_49 [ 1 ] == '6' ) {
V_2 -> V_163 = 6 ;
} else if ( V_2 -> V_49 [ 1 ] == 7 ) {
V_2 -> V_163 = 7 ;
} else {
F_4 ( & V_2 -> V_6 -> V_14 , L_63 ,
V_15 ) ;
return - V_56 ;
}
memset ( & V_2 -> V_10 . V_74 , 0x00 , sizeof( V_2 -> V_10 . V_74 ) ) ;
memset ( & V_2 -> V_10 . V_76 , 0x00 , sizeof( V_2 -> V_10 . V_76 ) ) ;
F_16 ( V_2 ) ;
V_2 -> V_10 . V_178 = false ;
return 0 ;
}
