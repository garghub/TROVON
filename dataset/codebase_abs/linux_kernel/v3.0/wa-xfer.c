static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 )
{
F_2 ( & V_6 -> V_7 ) ;
F_4 ( & V_6 -> V_8 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_6 ( struct V_4 * V_10 )
{
struct V_5 * V_6 = F_7 ( V_10 , struct V_5 , V_7 ) ;
if ( V_6 -> V_2 ) {
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
if ( V_6 -> V_13 )
F_8 ( V_6 -> V_2 [ V_11 ] -> V_14 ) ;
F_8 ( & V_6 -> V_2 [ V_11 ] -> V_3 ) ;
}
}
F_9 ( V_6 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
F_11 ( & V_6 -> V_7 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
F_13 ( & V_6 -> V_7 , F_6 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
unsigned long V_15 ;
F_15 ( & V_6 -> V_16 -> V_17 , V_15 ) ;
F_16 ( & V_6 -> V_8 ) ;
F_17 ( & V_6 -> V_16 -> V_17 , V_15 ) ;
F_18 ( V_6 -> V_16 -> V_18 , V_6 -> V_3 , V_6 -> V_19 ) ;
F_19 ( V_6 -> V_16 ) ;
F_12 ( V_6 ) ;
}
static void F_20 ( struct V_5 * V_6 )
{
if ( V_6 -> V_20 )
F_21 ( V_6 -> V_20 ) ;
F_22 ( V_6 -> V_21 -> V_22 ) ;
F_14 ( V_6 ) ;
}
static unsigned F_23 ( struct V_5 * V_6 )
{
struct V_23 * V_24 = & V_6 -> V_16 -> V_25 -> V_24 ;
unsigned V_19 , V_11 ;
struct V_1 * V_2 ;
struct V_3 * V_3 = V_6 -> V_3 ;
unsigned V_26 = 0 ;
V_19 = V_6 -> V_27 == V_6 -> V_28 ;
if ( V_19 == 0 )
goto V_29;
V_3 -> V_30 = 0 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_2 = V_6 -> V_2 [ V_11 ] ;
switch ( V_2 -> V_31 ) {
case V_32 :
if ( V_26 && V_2 -> V_19 > 0 ) {
F_24 ( V_24 , L_1 ,
V_6 , V_11 , V_2 -> V_19 ) ;
V_3 -> V_31 = - V_33 ;
goto V_29;
}
V_3 -> V_30 += V_2 -> V_19 ;
if ( V_2 -> V_19 < V_6 -> V_34
&& V_11 != V_6 -> V_12 - 1 )
V_26 = 1 ;
F_24 ( V_24 , L_2
L_3 ,
V_6 , V_2 -> V_35 , V_26 , V_2 -> V_19 ,
V_3 -> V_30 ) ;
break;
case V_36 :
V_6 -> V_19 = V_2 -> V_19 ;
F_24 ( V_24 , L_4 ,
V_6 , V_2 -> V_35 , V_2 -> V_19 ) ;
goto V_29;
case V_37 :
F_24 ( V_24 , L_5 ,
V_6 , V_2 -> V_35 , V_3 -> V_31 ) ;
V_6 -> V_19 = V_3 -> V_31 ;
goto V_29;
default:
F_25 ( V_24 , L_6 ,
V_6 , V_11 , V_2 -> V_31 ) ;
V_6 -> V_19 = - V_33 ;
goto V_29;
}
}
V_6 -> V_19 = 0 ;
V_29:
return V_19 ;
}
static void F_26 ( struct V_5 * V_6 )
{
V_6 -> V_38 = F_27 ( 1 , & V_6 -> V_16 -> V_39 ) ;
}
static T_1 F_28 ( struct V_5 * V_6 )
{
return V_6 -> V_38 ;
}
static struct V_5 * F_29 ( struct V_40 * V_16 , T_1 V_38 )
{
unsigned long V_15 ;
struct V_5 * V_41 ;
F_15 ( & V_16 -> V_17 , V_15 ) ;
F_30 (xfer_itr, &wa->xfer_list, list_node) {
if ( V_38 == V_41 -> V_38 ) {
F_10 ( V_41 ) ;
goto V_29;
}
}
V_41 = NULL ;
V_29:
F_17 ( & V_16 -> V_17 , V_15 ) ;
return V_41 ;
}
static void F_31 ( struct V_3 * V_3 )
{
struct V_42 * V_43 = V_3 -> V_44 ;
F_8 ( & V_43 -> V_3 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
int V_19 ;
struct V_23 * V_24 = & V_6 -> V_16 -> V_25 -> V_24 ;
struct V_42 * V_43 ;
struct V_45 * V_46 = V_6 -> V_21 -> V_22 ;
V_43 = F_33 ( sizeof( * V_43 ) , V_47 ) ;
if ( V_43 == NULL )
goto V_48;
V_43 -> V_49 . V_50 = sizeof( V_43 -> V_49 ) ;
V_43 -> V_49 . V_51 = V_52 ;
V_43 -> V_49 . V_53 = V_46 -> V_54 . V_55 ;
V_43 -> V_49 . V_56 = F_28 ( V_6 ) ;
F_34 ( & V_43 -> V_3 ) ;
F_35 ( & V_43 -> V_3 , V_6 -> V_16 -> V_57 ,
F_36 ( V_6 -> V_16 -> V_57 ,
V_6 -> V_16 -> V_58 -> V_59 ) ,
& V_43 -> V_49 , sizeof( V_43 -> V_49 ) , F_31 , V_43 ) ;
V_19 = F_37 ( & V_43 -> V_3 , V_47 ) ;
if ( V_19 < 0 )
goto V_60;
return;
V_60:
if ( F_38 () )
F_39 ( V_24 , L_7 ,
V_6 , V_19 ) ;
F_9 ( V_43 ) ;
V_48:
return;
}
static T_2 F_40 ( struct V_5 * V_6 ,
enum V_61 * V_62 )
{
T_2 V_19 ;
struct V_23 * V_24 = & V_6 -> V_16 -> V_25 -> V_24 ;
T_3 V_63 ;
struct V_3 * V_3 = V_6 -> V_3 ;
struct V_45 * V_46 = V_6 -> V_21 -> V_22 ;
switch ( V_46 -> V_54 . V_64 & 0x3 ) {
case V_65 :
* V_62 = V_66 ;
V_19 = sizeof( struct V_67 ) ;
break;
case V_68 :
case V_69 :
* V_62 = V_70 ;
V_19 = sizeof( struct V_71 ) ;
break;
case V_72 :
F_39 ( V_24 , L_8 ) ;
V_19 = - V_73 ;
goto error;
default:
F_41 () ;
V_19 = - V_33 ;
} ;
V_6 -> V_13 = V_3 -> V_74 & V_75 ? 1 : 0 ;
V_6 -> V_76 = V_3 -> V_77 & V_78 ? 1 : 0 ;
V_6 -> V_34 = F_42 ( V_46 -> V_54 . V_79 )
* 1 << ( V_6 -> V_16 -> V_80 -> V_81 - 1 ) ;
V_63 = F_42 ( V_46 -> V_54 . V_82 ) ;
if ( V_6 -> V_34 < V_63 ) {
F_39 ( V_24 , L_9
L_10 , V_6 -> V_34 , V_63 ) ;
V_19 = - V_33 ;
goto error;
}
V_6 -> V_34 = ( V_6 -> V_34 / V_63 ) * V_63 ;
V_6 -> V_12 = ( V_3 -> V_83 + V_6 -> V_34 - 1 )
/ V_6 -> V_34 ;
if ( V_6 -> V_12 >= V_84 ) {
F_39 ( V_24 , L_11 ,
( int ) ( V_3 -> V_83 / V_6 -> V_34 ) ,
V_84 ) ;
V_19 = - V_33 ;
goto error;
}
if ( V_6 -> V_12 == 0 && * V_62 == V_66 )
V_6 -> V_12 = 1 ;
error:
return V_19 ;
}
static void F_43 ( struct V_5 * V_6 ,
struct V_85 * V_86 ,
enum V_61 V_87 ,
T_3 V_88 )
{
struct V_45 * V_46 = V_6 -> V_21 -> V_22 ;
V_86 = & V_6 -> V_2 [ 0 ] -> V_89 ;
V_86 -> V_50 = V_88 ;
V_86 -> V_51 = V_87 ;
V_86 -> V_53 = V_46 -> V_54 . V_55 ;
V_86 -> V_56 = F_28 ( V_6 ) ;
V_86 -> V_90 = 0 ;
switch ( V_87 ) {
case V_66 : {
struct V_67 * V_91 =
F_7 ( V_86 , struct V_67 , V_92 ) ;
V_91 -> V_64 = V_6 -> V_13 ? 1 : 0 ;
memcpy ( & V_91 -> V_93 , V_6 -> V_3 -> V_94 ,
sizeof( V_91 -> V_93 ) ) ;
break;
}
case V_70 :
break;
case V_95 :
F_44 ( V_96 L_8 ) ;
default:
F_41 () ;
} ;
}
static void F_45 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_40 * V_16 ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
unsigned long V_15 ;
unsigned V_97 = 0 ;
T_4 V_98 = 0 ;
switch ( V_3 -> V_31 ) {
case 0 :
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_16 = V_6 -> V_16 ;
V_24 = & V_16 -> V_25 -> V_24 ;
F_24 ( V_24 , L_12 ,
V_6 , V_2 -> V_35 , V_3 -> V_30 ) ;
if ( V_2 -> V_31 < V_99 )
V_2 -> V_31 = V_99 ;
V_2 -> V_19 = V_3 -> V_30 ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
break;
case - V_100 :
case - V_101 :
break;
default:
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_16 = V_6 -> V_16 ;
V_24 = & V_16 -> V_25 -> V_24 ;
V_46 = V_6 -> V_21 -> V_22 ;
F_24 ( V_24 , L_13 ,
V_6 , V_2 -> V_35 , V_3 -> V_31 ) ;
if ( F_46 ( & V_16 -> V_102 , V_103 ,
V_104 ) ) {
F_39 ( V_24 , L_14
L_15 ) ;
F_47 ( V_16 ) ;
}
if ( V_2 -> V_31 != V_36 ) {
V_2 -> V_31 = V_36 ;
V_2 -> V_19 = V_3 -> V_31 ;
V_6 -> V_27 ++ ;
F_32 ( V_6 ) ;
V_97 = F_48 ( V_46 ) ;
V_98 = F_23 ( V_6 ) ;
}
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
}
}
static void F_50 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_40 * V_16 ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
unsigned long V_15 ;
unsigned V_97 ;
T_4 V_98 = 0 ;
switch ( V_3 -> V_31 ) {
case 0 :
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_16 = V_6 -> V_16 ;
V_24 = & V_16 -> V_25 -> V_24 ;
F_24 ( V_24 , L_16 , V_6 , V_2 -> V_35 ) ;
if ( V_6 -> V_13 && V_2 -> V_31 < V_99 )
V_2 -> V_31 = V_99 ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
break;
case - V_100 :
case - V_101 :
break;
default:
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_16 = V_6 -> V_16 ;
V_24 = & V_16 -> V_25 -> V_24 ;
V_46 = V_6 -> V_21 -> V_22 ;
if ( F_38 () )
F_39 ( V_24 , L_17 ,
V_6 , V_2 -> V_35 , V_3 -> V_31 ) ;
if ( F_46 ( & V_16 -> V_102 , V_103 ,
V_104 ) ) {
F_39 ( V_24 , L_14
L_15 ) ;
F_47 ( V_16 ) ;
}
F_51 ( V_2 -> V_14 ) ;
V_2 -> V_31 = V_36 ;
V_2 -> V_19 = V_3 -> V_31 ;
V_6 -> V_27 ++ ;
F_32 ( V_6 ) ;
V_97 = F_48 ( V_46 ) ;
V_98 = F_23 ( V_6 ) ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
}
}
static int F_52 ( struct V_5 * V_6 , T_3 V_88 )
{
int V_19 , V_11 ;
T_3 V_105 = sizeof( * V_6 -> V_2 [ 0 ] )
- sizeof( V_6 -> V_2 [ 0 ] -> V_89 ) + V_88 ;
struct V_106 * V_57 = V_6 -> V_16 -> V_57 ;
const struct V_107 * V_58 = V_6 -> V_16 -> V_58 ;
struct V_1 * V_2 ;
T_3 V_108 , V_109 , V_110 ;
V_19 = - V_111 ;
V_6 -> V_2 = F_53 ( V_6 -> V_12 , sizeof( V_6 -> V_2 [ 0 ] ) , V_47 ) ;
if ( V_6 -> V_2 == NULL )
goto V_112;
V_108 = 0 ;
V_109 = V_6 -> V_3 -> V_83 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_2 = V_6 -> V_2 [ V_11 ] = F_54 ( V_105 , V_47 ) ;
if ( V_2 == NULL )
goto V_113;
F_1 ( V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_35 = V_11 ;
F_35 ( & V_2 -> V_3 , V_57 ,
F_36 ( V_57 ,
V_58 -> V_59 ) ,
& V_2 -> V_89 , V_88 ,
F_50 , V_2 ) ;
V_110 = V_109 > V_6 -> V_34 ?
V_6 -> V_34 : V_109 ;
if ( V_6 -> V_13 == 0 && V_109 > 0 ) {
V_2 -> V_14 = F_55 ( 0 , V_47 ) ;
if ( V_2 -> V_14 == NULL )
goto V_114;
F_35 (
V_2 -> V_14 , V_57 ,
F_36 ( V_57 ,
V_58 -> V_59 ) ,
NULL , 0 , F_45 , V_2 ) ;
if ( V_6 -> V_76 ) {
V_2 -> V_14 -> V_115 =
V_6 -> V_3 -> V_115 + V_108 ;
V_2 -> V_14 -> V_77 |=
V_78 ;
} else
V_2 -> V_14 -> V_116 =
V_6 -> V_3 -> V_116 + V_108 ;
V_2 -> V_14 -> V_83 = V_110 ;
}
V_2 -> V_31 = V_117 ;
V_108 += V_110 ;
V_109 -= V_110 ;
}
return 0 ;
V_114:
F_9 ( V_6 -> V_2 [ V_11 ] ) ;
V_11 -- ;
V_113:
for (; V_11 > 0 ; V_11 -- ) {
if ( V_6 -> V_13 == 0 )
F_9 ( V_6 -> V_2 [ V_11 ] -> V_14 ) ;
F_9 ( V_6 -> V_2 [ V_11 ] ) ;
}
V_112:
return V_19 ;
}
static int F_56 ( struct V_5 * V_6 , struct V_3 * V_3 )
{
int V_19 ;
struct V_23 * V_24 = & V_6 -> V_16 -> V_25 -> V_24 ;
enum V_61 V_87 = 0 ;
T_3 V_88 , V_11 , V_118 ;
struct V_85 * V_86 , * V_89 ;
V_19 = F_40 ( V_6 , & V_87 ) ;
if ( V_19 < 0 )
goto V_119;
V_88 = V_19 ;
V_19 = F_52 ( V_6 , V_88 ) ;
if ( V_19 < 0 ) {
F_39 ( V_24 , L_18 ,
V_6 , V_6 -> V_12 , V_19 ) ;
goto V_120;
}
V_86 = & V_6 -> V_2 [ 0 ] -> V_89 ;
F_26 ( V_6 ) ;
F_43 ( V_6 , V_86 , V_87 , V_88 ) ;
V_89 = V_86 ;
V_118 = V_3 -> V_83 ;
V_86 -> V_121 = V_118 > V_6 -> V_34 ?
V_6 -> V_34 : V_118 ;
V_118 -= V_6 -> V_34 ;
for ( V_11 = 1 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_89 = & V_6 -> V_2 [ V_11 ] -> V_89 ;
memcpy ( V_89 , V_86 , V_88 ) ;
V_89 -> V_90 = V_11 ;
V_89 -> V_121 = V_118 > V_6 -> V_34 ?
F_57 ( V_6 -> V_34 )
: F_57 ( V_118 ) ;
V_6 -> V_2 [ V_11 ] -> V_31 = V_117 ;
V_118 -= V_6 -> V_34 ;
}
V_89 -> V_90 |= 0x80 ;
V_19 = 0 ;
V_120:
V_119:
return V_19 ;
}
static int F_58 ( struct V_45 * V_46 , struct V_5 * V_6 ,
struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_37 ( & V_2 -> V_3 , V_47 ) ;
if ( V_19 < 0 ) {
F_44 ( V_96 L_19 ,
V_6 , V_2 -> V_35 , V_19 ) ;
goto V_122;
}
if ( V_2 -> V_14 ) {
V_19 = F_37 ( V_2 -> V_14 , V_47 ) ;
if ( V_19 < 0 ) {
F_44 ( V_96 L_20 ,
V_6 , V_2 -> V_35 , V_19 ) ;
goto V_123;
}
}
V_2 -> V_31 = V_124 ;
F_59 ( V_46 ) ;
return 0 ;
V_123:
F_51 ( & V_2 -> V_3 ) ;
V_122:
V_2 -> V_31 = V_36 ;
V_2 -> V_19 = V_19 ;
return V_19 ;
}
static void F_49 ( struct V_45 * V_46 )
{
int V_19 ;
struct V_23 * V_24 = & V_46 -> V_16 -> V_25 -> V_24 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_15 ;
F_15 ( & V_46 -> V_125 , V_15 ) ;
while ( F_60 ( & V_46 -> V_126 ) > 0
&& ! F_61 ( & V_46 -> V_127 ) ) {
V_2 = F_62 ( V_46 -> V_127 . V_128 , struct V_1 ,
V_8 ) ;
F_63 ( & V_2 -> V_8 ) ;
V_6 = V_2 -> V_6 ;
V_19 = F_58 ( V_46 , V_6 , V_2 ) ;
F_24 ( V_24 , L_21 ,
V_6 , V_2 -> V_35 , F_60 ( & V_46 -> V_126 ) , V_19 ) ;
if ( F_64 ( V_19 < 0 ) ) {
F_17 ( & V_46 -> V_125 , V_15 ) ;
F_15 ( & V_6 -> V_9 , V_15 ) ;
F_32 ( V_6 ) ;
V_6 -> V_27 ++ ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
F_15 ( & V_46 -> V_125 , V_15 ) ;
}
}
F_17 ( & V_46 -> V_125 , V_15 ) ;
}
static int F_65 ( struct V_5 * V_6 )
{
int V_19 ;
struct V_40 * V_16 = V_6 -> V_16 ;
struct V_23 * V_24 = & V_16 -> V_25 -> V_24 ;
unsigned V_11 ;
struct V_1 * V_2 ;
unsigned long V_15 ;
struct V_45 * V_46 = V_6 -> V_21 -> V_22 ;
T_3 V_129 = F_42 ( V_46 -> V_54 . V_130 ) ;
T_4 V_131 ;
T_4 V_132 ;
F_15 ( & V_16 -> V_17 , V_15 ) ;
F_66 ( & V_6 -> V_8 , & V_16 -> V_133 ) ;
F_17 ( & V_16 -> V_17 , V_15 ) ;
F_67 ( F_60 ( & V_46 -> V_126 ) > V_129 ) ;
V_19 = 0 ;
F_15 ( & V_46 -> V_125 , V_15 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_131 = F_60 ( & V_46 -> V_126 ) ;
V_132 = F_61 ( & V_46 -> V_127 ) ;
V_2 = V_6 -> V_2 [ V_11 ] ;
F_24 ( V_24 , L_22 ,
V_6 , V_11 , V_131 , V_132 ,
V_131 == 0 || ! V_132 ? L_23 : L_24 ) ;
if ( V_131 == 0 || ! V_132 ) {
F_24 ( V_24 , L_25 , V_6 , V_11 ) ;
V_2 -> V_31 = V_134 ;
F_66 ( & V_2 -> V_8 , & V_46 -> V_127 ) ;
} else {
V_19 = F_58 ( V_46 , V_6 , V_2 ) ;
if ( V_19 < 0 ) {
F_32 ( V_6 ) ;
goto V_122;
}
}
V_6 -> V_28 ++ ;
}
V_122:
F_17 ( & V_46 -> V_125 , V_15 ) ;
return V_19 ;
}
static void F_68 ( struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_15 ;
struct V_3 * V_3 = V_6 -> V_3 ;
struct V_40 * V_16 = V_6 -> V_16 ;
struct V_135 * V_135 = V_16 -> V_18 ;
struct V_20 * V_20 ;
unsigned V_98 ;
V_19 = F_69 ( V_16 , V_6 -> V_21 , V_3 , V_6 -> V_136 ) ;
if ( V_19 < 0 )
goto V_137;
V_19 = - V_138 ;
F_70 ( & V_135 -> V_139 ) ;
if ( V_3 -> V_24 == NULL ) {
F_71 ( & V_135 -> V_139 ) ;
goto V_140;
}
V_20 = F_72 ( V_135 , V_3 -> V_24 ) ;
if ( V_20 == NULL ) {
F_71 ( & V_135 -> V_139 ) ;
goto V_140;
}
F_71 ( & V_135 -> V_139 ) ;
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_6 -> V_20 = V_20 ;
V_19 = V_3 -> V_31 ;
if ( V_3 -> V_31 != - V_141 )
goto V_142;
V_19 = F_56 ( V_6 , V_3 ) ;
if ( V_19 < 0 )
goto V_143;
V_19 = F_65 ( V_6 ) ;
if ( V_19 < 0 )
goto V_144;
F_17 ( & V_6 -> V_9 , V_15 ) ;
return;
V_143:
V_142:
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_20 )
F_21 ( V_20 ) ;
V_140:
F_22 ( V_6 -> V_21 -> V_22 ) ;
V_137:
V_6 -> V_19 = V_19 ;
F_14 ( V_6 ) ;
return;
V_144:
V_98 = F_23 ( V_6 ) ;
V_6 -> V_19 = V_19 ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
}
void F_73 ( struct V_145 * V_146 )
{
struct V_40 * V_16 = F_7 ( V_146 , struct V_40 , V_147 ) ;
struct V_5 * V_6 , * V_128 ;
struct V_3 * V_3 ;
F_74 ( & V_16 -> V_17 ) ;
F_75 (xfer, next, &wa->xfer_delayed_list,
list_node) {
F_16 ( & V_6 -> V_8 ) ;
F_76 ( & V_16 -> V_17 ) ;
V_3 = V_6 -> V_3 ;
F_68 ( V_6 ) ;
F_8 ( V_3 ) ;
F_74 ( & V_16 -> V_17 ) ;
}
F_76 ( & V_16 -> V_17 ) ;
}
int F_77 ( struct V_40 * V_16 , struct V_148 * V_21 ,
struct V_3 * V_3 , T_5 V_136 )
{
int V_19 ;
struct V_23 * V_24 = & V_16 -> V_25 -> V_24 ;
struct V_5 * V_6 ;
unsigned long V_149 ;
unsigned V_150 = F_78 () | F_79 () ;
if ( V_3 -> V_116 == NULL
&& ! ( V_3 -> V_77 & V_78 )
&& V_3 -> V_83 != 0 ) {
F_39 ( V_24 , L_26 , V_3 ) ;
F_80 () ;
}
V_19 = - V_111 ;
V_6 = F_54 ( sizeof( * V_6 ) , V_136 ) ;
if ( V_6 == NULL )
goto V_48;
V_19 = - V_101 ;
if ( V_3 -> V_31 != - V_141 )
goto V_142;
F_3 ( V_6 ) ;
V_6 -> V_16 = F_81 ( V_16 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_136 = V_136 ;
V_6 -> V_21 = V_21 ;
V_3 -> V_22 = V_6 ;
F_24 ( V_24 , L_27 ,
V_6 , V_3 , V_3 -> V_74 , V_3 -> V_83 ,
V_3 -> V_77 & V_78 ? L_28 : L_29 ,
V_3 -> V_74 & V_75 ? L_30 : L_31 ,
V_150 ? L_32 : L_33 ) ;
if ( V_150 ) {
F_82 ( V_3 ) ;
F_15 ( & V_16 -> V_17 , V_149 ) ;
F_66 ( & V_6 -> V_8 , & V_16 -> V_151 ) ;
F_17 ( & V_16 -> V_17 , V_149 ) ;
F_83 ( V_152 , & V_16 -> V_147 ) ;
} else {
F_68 ( V_6 ) ;
}
return 0 ;
V_142:
F_9 ( V_6 ) ;
V_48:
return V_19 ;
}
int F_84 ( struct V_40 * V_16 , struct V_3 * V_3 )
{
unsigned long V_15 , V_153 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
unsigned V_11 ;
unsigned V_97 = 0 ;
V_6 = V_3 -> V_22 ;
if ( V_6 == NULL ) {
F_67 ( V_3 -> V_31 == - V_141 ) ;
goto V_29;
}
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_46 = V_6 -> V_21 -> V_22 ;
F_15 ( & V_16 -> V_17 , V_153 ) ;
if ( ! F_61 ( & V_6 -> V_8 ) && V_6 -> V_2 == NULL )
goto V_154;
F_17 ( & V_16 -> V_17 , V_153 ) ;
if ( V_6 -> V_2 == NULL )
goto V_155;
F_32 ( V_6 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_12 ; V_11 ++ ) {
V_2 = V_6 -> V_2 [ V_11 ] ;
switch ( V_2 -> V_31 ) {
case V_156 :
case V_117 :
F_44 ( V_96 L_34 ,
V_6 , V_11 , V_2 -> V_31 ) ;
F_85 ( 1 ) ;
break;
case V_134 :
V_2 -> V_31 = V_37 ;
F_15 ( & V_46 -> V_125 , V_153 ) ;
F_63 ( & V_2 -> V_8 ) ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
F_17 ( & V_46 -> V_125 , V_153 ) ;
break;
case V_124 :
V_2 -> V_31 = V_37 ;
F_51 ( & V_2 -> V_3 ) ;
if ( V_6 -> V_13 == 0 )
F_51 ( V_2 -> V_14 ) ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
break;
case V_99 :
V_2 -> V_31 = V_37 ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
break;
case V_157 :
F_51 ( V_16 -> V_158 ) ;
V_2 -> V_31 = V_37 ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
break;
case V_32 :
case V_36 :
case V_37 :
break;
}
}
V_6 -> V_19 = V_3 -> V_31 ;
F_23 ( V_6 ) ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
return 0 ;
V_155:
F_17 ( & V_6 -> V_9 , V_15 ) ;
V_29:
return 0 ;
V_154:
F_16 ( & V_6 -> V_8 ) ;
F_17 ( & V_16 -> V_17 , V_153 ) ;
V_6 -> V_19 = V_3 -> V_31 ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
F_14 ( V_6 ) ;
F_8 ( V_3 ) ;
return 0 ;
}
static int F_86 ( T_4 V_31 )
{
int V_159 ;
T_4 V_160 = V_31 ;
static int V_161 [] = {
[ V_162 ] = 0 ,
[ V_163 ] = - V_164 ,
[ V_165 ] = - V_166 ,
[ V_167 ] = - V_168 ,
[ V_169 ] = V_33 ,
[ V_170 ] = 0 ,
[ V_171 ] = - V_111 ,
[ V_172 ] = - V_173 ,
[ V_174 ] = - V_175 ,
[ V_176 ] = V_33 ,
[ V_177 ] = V_33 ,
[ V_178 ] = V_33 ,
[ V_179 ] = V_33 ,
} ;
V_31 &= 0x3f ;
if ( V_31 == 0 )
return 0 ;
if ( V_31 >= F_87 ( V_161 ) ) {
if ( F_38 () )
F_44 ( V_96 L_35
L_36 ,
V_180 , V_160 ) ;
return - V_33 ;
}
V_159 = V_161 [ V_31 ] ;
if ( F_64 ( V_159 > 0 ) ) {
if ( F_38 () )
F_44 ( V_96 L_35
L_37 ,
V_180 , V_160 ) ;
V_159 = - V_159 ;
}
return V_159 ;
}
static void F_88 ( struct V_40 * V_16 , struct V_5 * V_6 )
{
int V_19 ;
struct V_23 * V_24 = & V_16 -> V_25 -> V_24 ;
unsigned long V_15 ;
T_4 V_181 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_182 * V_183 = V_16 -> V_183 ;
T_4 V_98 = 0 ;
T_4 V_184 ;
unsigned V_97 = 0 ;
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_181 = V_183 -> V_90 & 0x7f ;
if ( F_64 ( V_181 >= V_6 -> V_12 ) )
goto V_185;
V_2 = V_6 -> V_2 [ V_181 ] ;
V_46 = V_6 -> V_21 -> V_22 ;
V_184 = V_183 -> V_186 ;
F_24 ( V_24 , L_38 ,
V_6 , V_181 , V_184 , V_2 -> V_31 ) ;
if ( V_2 -> V_31 == V_37
|| V_2 -> V_31 == V_36 )
goto V_187;
if ( V_2 -> V_31 == V_124 )
V_2 -> V_31 = V_99 ;
if ( V_2 -> V_31 != V_99 ) {
if ( F_38 () )
F_39 ( V_24 , L_39 ,
V_6 , V_181 , V_2 -> V_31 ) ;
V_2 -> V_31 = V_99 ;
}
if ( V_184 & 0x80 ) {
V_2 -> V_19 = F_86 ( V_184 ) ;
F_39 ( V_24 , L_40 ,
V_6 , V_2 -> V_35 , V_184 ) ;
goto V_188;
}
if ( V_184 & 0x40 )
V_184 = 0 ;
if ( V_6 -> V_13 ) {
V_2 -> V_31 = V_157 ;
F_67 ( V_16 -> V_189 -> V_31 == - V_141 ) ;
if ( V_6 -> V_76 ) {
V_16 -> V_189 -> V_115 =
V_6 -> V_3 -> V_115
+ V_181 * V_6 -> V_34 ;
V_16 -> V_189 -> V_77
|= V_78 ;
} else {
V_16 -> V_189 -> V_116 =
V_6 -> V_3 -> V_116
+ V_181 * V_6 -> V_34 ;
V_16 -> V_189 -> V_77
&= ~ V_78 ;
}
V_16 -> V_189 -> V_83 =
F_89 ( V_183 -> V_121 ) ;
V_16 -> V_189 -> V_44 = V_2 ;
V_19 = F_37 ( V_16 -> V_189 , V_47 ) ;
if ( V_19 < 0 )
goto V_190;
} else {
V_2 -> V_31 = V_32 ;
V_2 -> V_19 = F_89 ( V_183 -> V_121 ) ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
V_98 = F_23 ( V_6 ) ;
}
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
return;
V_190:
if ( F_46 ( & V_16 -> V_191 , V_103 , V_104 ) ) {
F_39 ( V_24 , L_41
L_15 ) ;
F_47 ( V_16 ) ;
}
if ( F_38 () )
F_39 ( V_24 , L_42 ,
V_6 , V_181 , V_19 ) ;
V_2 -> V_19 = V_19 ;
V_188:
V_2 -> V_31 = V_36 ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
F_32 ( V_6 ) ;
V_98 = F_23 ( V_6 ) ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
return;
V_185:
F_17 ( & V_6 -> V_9 , V_15 ) ;
F_84 ( V_16 , V_6 -> V_3 ) ;
if ( F_38 () )
F_39 ( V_24 , L_43 , V_6 , V_181 ) ;
if ( F_46 ( & V_16 -> V_191 , V_103 , V_104 ) ) {
F_39 ( V_24 , L_41
L_15 ) ;
F_47 ( V_16 ) ;
}
return;
V_187:
F_17 ( & V_6 -> V_9 , V_15 ) ;
}
static void F_90 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_44 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_40 * V_16 ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
unsigned V_97 ;
unsigned long V_15 ;
T_4 V_98 = 0 ;
switch ( V_3 -> V_31 ) {
case 0 :
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_16 = V_6 -> V_16 ;
V_24 = & V_16 -> V_25 -> V_24 ;
V_46 = V_6 -> V_21 -> V_22 ;
F_24 ( V_24 , L_44 ,
V_6 , V_2 -> V_35 , ( T_3 ) V_3 -> V_30 ) ;
V_2 -> V_31 = V_32 ;
V_2 -> V_19 = V_3 -> V_30 ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
V_98 = F_23 ( V_6 ) ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
break;
case - V_100 :
case - V_101 :
break;
default:
F_15 ( & V_6 -> V_9 , V_15 ) ;
V_16 = V_6 -> V_16 ;
V_24 = & V_16 -> V_25 -> V_24 ;
V_46 = V_6 -> V_21 -> V_22 ;
if ( F_38 () )
F_39 ( V_24 , L_45 ,
V_6 , V_2 -> V_35 , V_3 -> V_31 ) ;
if ( F_46 ( & V_16 -> V_102 , V_103 ,
V_104 ) ) {
F_39 ( V_24 , L_14
L_15 ) ;
F_47 ( V_16 ) ;
}
V_2 -> V_31 = V_36 ;
V_2 -> V_19 = V_3 -> V_31 ;
V_6 -> V_27 ++ ;
V_97 = F_48 ( V_46 ) ;
F_32 ( V_6 ) ;
V_98 = F_23 ( V_6 ) ;
F_17 ( & V_6 -> V_9 , V_15 ) ;
if ( V_98 )
F_20 ( V_6 ) ;
if ( V_97 )
F_49 ( V_46 ) ;
}
}
static void F_91 ( struct V_3 * V_3 )
{
int V_19 ;
struct V_40 * V_16 = V_3 -> V_44 ;
struct V_23 * V_24 = & V_16 -> V_25 -> V_24 ;
struct V_182 * V_183 ;
T_1 V_192 ;
struct V_5 * V_6 ;
T_4 V_184 ;
F_67 ( V_16 -> V_158 != V_3 ) ;
switch ( V_16 -> V_158 -> V_31 ) {
case 0 :
F_24 ( V_24 , L_46 ,
V_3 -> V_30 , V_3 -> V_116 ) ;
if ( V_16 -> V_158 -> V_30 != sizeof( * V_183 ) ) {
F_39 ( V_24 , L_47
L_48 ,
V_3 -> V_30 , sizeof( * V_183 ) ) ;
break;
}
V_183 = V_16 -> V_183 ;
if ( V_183 -> V_92 . V_50 != sizeof( * V_183 ) ) {
F_39 ( V_24 , L_49
L_50 ,
V_183 -> V_92 . V_50 ) ;
break;
}
if ( V_183 -> V_92 . V_193 != V_194 ) {
F_39 ( V_24 , L_49
L_51 ,
V_183 -> V_92 . V_193 ) ;
break;
}
V_184 = V_183 -> V_186 & 0x3f ;
if ( V_184 == V_174
|| V_184 == V_170 )
break;
V_192 = V_183 -> V_56 ;
V_6 = F_29 ( V_16 , V_192 ) ;
if ( V_6 == NULL ) {
F_39 ( V_24 , L_49
L_52 ,
V_192 , V_184 ) ;
break;
}
F_88 ( V_16 , V_6 ) ;
F_12 ( V_6 ) ;
break;
case - V_101 :
case - V_195 :
F_24 ( V_24 , L_53 , V_3 -> V_31 ) ;
goto V_29;
default:
if ( F_46 ( & V_16 -> V_191 , V_103 ,
V_104 ) ) {
F_39 ( V_24 , L_41
L_15 ) ;
F_47 ( V_16 ) ;
goto V_29;
}
if ( F_38 () )
F_39 ( V_24 , L_54 , V_3 -> V_31 ) ;
break;
}
V_19 = F_37 ( V_16 -> V_158 , V_47 ) ;
if ( V_19 < 0 ) {
F_39 ( V_24 , L_55
L_56 , V_19 ) ;
F_47 ( V_16 ) ;
}
V_29:
return;
}
void F_92 ( struct V_40 * V_16 , struct V_196 * V_197 )
{
int V_19 ;
struct V_23 * V_24 = & V_16 -> V_25 -> V_24 ;
struct V_198 * V_199 ;
const struct V_107 * V_200 = V_16 -> V_200 ;
V_199 = F_7 ( V_197 , struct V_198 , V_92 ) ;
F_67 ( V_197 -> V_193 != V_201 ) ;
if ( ( 0x80 | V_199 -> V_202 ) != V_200 -> V_59 ) {
F_39 ( V_24 , L_57 ,
V_199 -> V_202 , V_200 -> V_59 ) ;
goto error;
}
if ( V_16 -> V_158 != NULL )
goto V_29;
V_16 -> V_158 = F_55 ( 0 , V_203 ) ;
if ( V_16 -> V_158 == NULL ) {
F_39 ( V_24 , L_58 ) ;
goto V_204;
}
F_35 (
V_16 -> V_158 , V_16 -> V_57 ,
F_93 ( V_16 -> V_57 , 0x80 | V_199 -> V_202 ) ,
V_16 -> V_183 , V_16 -> V_205 ,
F_91 , V_16 ) ;
V_16 -> V_189 = F_55 ( 0 , V_203 ) ;
if ( V_16 -> V_189 == NULL ) {
F_39 ( V_24 , L_59 ) ;
goto V_206;
}
F_35 (
V_16 -> V_189 , V_16 -> V_57 ,
F_93 ( V_16 -> V_57 , 0x80 | V_199 -> V_202 ) ,
NULL , 0 , F_90 , V_16 ) ;
V_19 = F_37 ( V_16 -> V_158 , V_203 ) ;
if ( V_19 < 0 ) {
F_39 ( V_24 , L_55
L_56 , V_19 ) ;
goto V_207;
}
V_29:
return;
V_207:
F_8 ( V_16 -> V_189 ) ;
V_206:
F_8 ( V_16 -> V_158 ) ;
V_16 -> V_158 = NULL ;
V_204:
error:
F_47 ( V_16 ) ;
}
