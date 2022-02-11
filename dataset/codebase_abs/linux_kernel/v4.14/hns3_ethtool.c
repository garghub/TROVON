static void F_1 ( T_1 V_1 , struct V_2 * V_3 ,
bool V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( ! ( V_1 & V_6 [ V_5 ] . V_7 ) )
continue;
if ( V_4 ) {
F_3 ( V_3 ,
V_8 ) ;
F_4 ( V_6 [ V_5 ] . V_9 ,
V_3 -> V_10 . V_8 ) ;
} else {
F_3 ( V_3 ,
V_11 ) ;
F_4 ( V_6 [ V_5 ] . V_9 ,
V_3 -> V_10 . V_11 ) ;
}
}
}
static int F_5 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
const struct V_20 * V_21 = V_18 -> V_22 -> V_21 ;
if ( ! V_21 -> V_23 )
return - V_24 ;
switch ( V_14 ) {
case V_25 :
return ( ( V_26 * V_18 -> V_27 . V_28 ) +
V_21 -> V_23 ( V_18 , V_14 ) ) ;
case V_29 :
return V_21 -> V_23 ( V_18 , V_14 ) ;
}
return 0 ;
}
static void * F_7 ( T_2 * V_30 , const struct V_31 * V_32 ,
T_1 V_33 , T_1 V_28 )
{
#define F_8 (8 + 4)
T_1 V_34 ;
T_1 V_5 , V_35 ;
T_1 V_36 ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
V_30 [ V_37 - 1 ] = '\0' ;
V_36 = snprintf ( V_30 , F_8 , L_1 , V_5 ) ;
V_36 = F_9 ( V_38 , V_36 , F_8 - 1 ) ;
V_34 = ( V_37 - 1 ) - V_36 ;
strncat ( V_30 , V_32 [ V_35 ] . V_39 , V_34 ) ;
V_30 += V_37 ;
}
}
return V_30 ;
}
static T_2 * F_10 ( struct V_17 * V_40 , T_2 * V_30 )
{
struct V_41 * V_27 = & V_40 -> V_27 ;
V_30 = F_7 ( V_30 , V_42 , V_43 ,
V_27 -> V_28 ) ;
V_30 = F_7 ( V_30 , V_44 , V_45 ,
V_27 -> V_28 ) ;
return V_30 ;
}
static void F_11 ( struct V_12 * V_13 , T_1 V_14 , T_2 * V_30 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
const struct V_20 * V_21 = V_18 -> V_22 -> V_21 ;
char * V_46 = ( char * ) V_30 ;
if ( ! V_21 -> V_47 )
return;
switch ( V_14 ) {
case V_25 :
V_46 = F_10 ( V_18 , V_46 ) ;
V_18 -> V_22 -> V_21 -> V_47 ( V_18 , V_14 , ( T_2 * ) V_46 ) ;
break;
case V_29 :
V_21 -> V_47 ( V_18 , V_14 , V_30 ) ;
break;
}
}
static T_3 * F_12 ( struct V_17 * V_40 , T_3 * V_30 )
{
struct V_15 * V_48 = (struct V_15 * ) V_40 -> V_16 ;
struct V_41 * V_27 = & V_40 -> V_27 ;
struct V_49 * V_50 ;
T_2 * V_51 ;
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < V_27 -> V_28 ; V_5 ++ ) {
V_50 = V_48 -> V_52 [ V_5 ] . V_50 ;
for ( V_5 = 0 ; V_5 < V_43 ; V_5 ++ ) {
V_51 = ( T_2 * ) V_50 + V_42 [ V_5 ] . V_53 ;
* V_30 ++ = * ( T_3 * ) V_51 ;
}
}
for ( V_5 = 0 ; V_5 < V_27 -> V_28 ; V_5 ++ ) {
V_50 = V_48 -> V_52 [ V_5 + V_27 -> V_28 ] . V_50 ;
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ ) {
V_51 = ( T_2 * ) V_50 + V_44 [ V_5 ] . V_53 ;
* V_30 ++ = * ( T_3 * ) V_51 ;
}
}
return V_30 ;
}
void F_13 ( struct V_12 * V_13 , struct V_54 * V_32 ,
T_3 * V_30 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_3 * V_55 = V_30 ;
if ( ! V_18 -> V_22 -> V_21 -> V_56 || ! V_18 -> V_22 -> V_21 -> V_57 ) {
F_14 ( V_13 , L_2 ) ;
return;
}
V_18 -> V_22 -> V_21 -> V_57 ( V_18 , & V_13 -> V_32 ) ;
V_55 = F_12 ( V_18 , V_55 ) ;
V_18 -> V_22 -> V_21 -> V_56 ( V_18 , V_55 ) ;
}
static void F_15 ( struct V_12 * V_13 ,
struct V_58 * V_59 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
strncpy ( V_59 -> V_60 , V_61 ,
sizeof( V_59 -> V_60 ) ) ;
V_59 -> V_60 [ sizeof( V_59 -> V_60 ) - 1 ] = '\0' ;
strncpy ( V_59 -> V_62 , V_18 -> V_63 -> V_62 -> V_64 ,
sizeof( V_59 -> V_62 ) ) ;
V_59 -> V_62 [ sizeof( V_59 -> V_62 ) - 1 ] = '\0' ;
strncpy ( V_59 -> V_65 , F_16 ( V_18 -> V_63 ) ,
sizeof( V_59 -> V_65 ) ) ;
V_59 -> V_65 [ V_66 - 1 ] = '\0' ;
snprintf ( V_59 -> V_67 , sizeof( V_59 -> V_67 ) , L_3 ,
V_16 -> V_19 -> V_22 -> V_21 -> V_68 ( V_18 ) ) ;
}
static T_1 F_17 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 ;
V_18 = V_16 -> V_19 ;
if ( V_18 -> V_22 && V_18 -> V_22 -> V_21 && V_18 -> V_22 -> V_21 -> V_69 )
return V_18 -> V_22 -> V_21 -> V_69 ( V_18 ) ;
else
return 0 ;
}
static void F_18 ( struct V_12 * V_13 ,
struct V_70 * V_71 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
int V_72 = V_16 -> V_19 -> V_27 . V_28 ;
V_71 -> V_73 = V_74 ;
V_71 -> V_75 = V_74 ;
V_71 -> V_76 = V_16 -> V_52 [ 0 ] . V_50 -> V_77 ;
V_71 -> V_78 = V_16 -> V_52 [ V_72 ] . V_50 -> V_77 ;
}
static void F_19 ( struct V_12 * V_13 ,
struct V_79 * V_71 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( V_18 -> V_22 && V_18 -> V_22 -> V_21 && V_18 -> V_22 -> V_21 -> V_80 )
V_18 -> V_22 -> V_21 -> V_80 ( V_18 , & V_71 -> V_81 ,
& V_71 -> V_82 , & V_71 -> V_83 ) ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_1 V_84 ;
T_1 V_85 ;
T_2 V_86 = V_87 ;
T_2 V_88 ;
T_2 V_89 ;
T_2 V_90 ;
T_1 V_91 ;
if ( ! V_18 -> V_22 || ! V_18 -> V_22 -> V_21 )
return - V_24 ;
if ( V_18 -> V_22 -> V_21 -> V_92 ) {
V_18 -> V_22 -> V_21 -> V_92 ( V_18 , & V_89 ,
& V_91 , & V_90 ) ;
V_3 -> V_93 . V_81 = V_89 ;
V_3 -> V_93 . V_91 = V_91 ;
V_3 -> V_93 . V_90 = V_90 ;
V_88 = F_17 ( V_13 ) ;
if ( ! V_88 ) {
V_3 -> V_93 . V_91 = ( T_1 ) V_94 ;
V_3 -> V_93 . V_90 = V_95 ;
}
}
if ( V_18 -> V_22 -> V_21 -> V_96 ) {
V_18 -> V_22 -> V_21 -> V_96 ( V_18 , & V_86 ) ;
switch ( V_86 ) {
case V_97 :
V_3 -> V_93 . V_98 = V_99 ;
V_84 = V_100 |
V_101 |
V_102 |
V_103 ;
V_85 = V_84 ;
break;
case V_104 :
V_3 -> V_93 . V_98 = V_105 ;
V_84 = V_106 |
V_101 |
V_102 |
V_103 |
V_107 |
V_108 |
V_109 |
V_110 ;
V_85 = V_84 ;
break;
case V_111 :
V_3 -> V_93 . V_98 = V_112 ;
V_84 = V_113 |
V_102 |
V_101 |
V_103 |
V_107 |
V_108 |
V_109 |
V_110 ;
V_85 = V_84 ;
break;
case V_87 :
default:
V_3 -> V_93 . V_98 = V_114 ;
V_84 = 0 ;
V_85 = 0 ;
break;
}
F_1 ( V_84 , V_3 , false ) ;
F_1 ( V_85 , V_3 , true ) ;
}
if ( V_18 -> V_22 -> V_21 -> V_115 )
V_18 -> V_22 -> V_21 -> V_115 ( V_18 , & V_3 -> V_93 . V_116 ,
& V_3 -> V_93 . V_117 ) ;
V_3 -> V_93 . V_118 = V_119 ;
return 0 ;
}
static T_1 F_21 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( ! V_18 -> V_22 || ! V_18 -> V_22 -> V_21 ||
! V_18 -> V_22 -> V_21 -> V_120 )
return - V_24 ;
return V_18 -> V_22 -> V_21 -> V_120 ( V_18 ) ;
}
static T_1 F_22 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( ! V_18 -> V_22 || ! V_18 -> V_22 -> V_21 ||
! V_18 -> V_22 -> V_21 -> V_121 )
return - V_24 ;
return V_18 -> V_22 -> V_21 -> V_121 ( V_18 ) ;
}
static int F_23 ( struct V_12 * V_13 , T_1 * V_122 , T_2 * V_123 ,
T_2 * V_124 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( ! V_18 -> V_22 || ! V_18 -> V_22 -> V_21 || ! V_18 -> V_22 -> V_21 -> V_125 )
return - V_24 ;
return V_18 -> V_22 -> V_21 -> V_125 ( V_18 , V_122 , V_123 , V_124 ) ;
}
static int F_24 ( struct V_12 * V_13 , const T_1 * V_122 ,
const T_2 * V_123 , const T_2 V_124 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( ! V_18 -> V_22 || ! V_18 -> V_22 -> V_21 || ! V_18 -> V_22 -> V_21 -> V_126 )
return - V_24 ;
if ( ( V_124 != V_127 ) && ( V_124 != V_128 ) ) {
F_14 ( V_13 ,
L_4 ) ;
return - V_24 ;
}
if ( ! V_122 ) {
F_14 ( V_13 ,
L_5 ) ;
return - V_24 ;
}
return V_18 -> V_22 -> V_21 -> V_126 ( V_18 , V_122 , V_123 , V_124 ) ;
}
static int F_25 ( struct V_12 * V_13 ,
struct V_129 * V_3 ,
T_1 * V_130 )
{
struct V_15 * V_16 = F_6 ( V_13 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
if ( ! V_18 -> V_22 || ! V_18 -> V_22 -> V_21 || ! V_18 -> V_22 -> V_21 -> V_131 )
return - V_24 ;
switch ( V_3 -> V_3 ) {
case V_132 :
V_3 -> V_30 = V_18 -> V_22 -> V_21 -> V_131 ( V_18 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
void F_26 ( struct V_12 * V_13 )
{
V_13 -> V_133 = & V_134 ;
}
