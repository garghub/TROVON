static void F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 V_4 )
{
if ( V_4 )
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
}
static bool F_2 ( struct V_5 * V_6 )
{
T_2 V_7 ;
V_7 = F_3 ( V_6 , V_8 ) ;
return ( V_7 & V_9 ) ;
}
static void F_4 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_12 * V_13 = (struct V_12 * ) ( & V_2 -> V_13 ) ;
if ( V_2 -> V_4 )
F_5 ( V_11 -> V_6 , V_2 -> V_3 , V_2 -> V_4 ) ;
F_6 ( V_11 -> V_6 , V_14 ,
V_13 -> V_15 ) ;
F_6 ( V_11 -> V_6 , V_8 ,
V_13 -> V_16 | V_9 ) ;
}
int F_7 ( struct V_5 * V_6 , bool V_17 )
{
int V_18 ;
if ( ! V_6 -> V_19 . V_20 )
return 0 ;
if ( V_17 )
V_18 = V_6 -> V_19 . V_20 ( V_6 ) ;
else
V_18 = V_6 -> V_19 . V_21 ( V_6 ) ;
return V_18 ;
}
static struct V_1 * F_8 ( struct V_10 * V_11 ,
T_3 V_22 )
{
struct V_1 * V_2 = NULL ;
struct V_12 * V_13 = (struct V_12 * ) ( & V_22 ) ;
if ( F_9 ( & V_11 -> V_23 ) ) {
F_10 ( V_11 -> V_24 , L_1 ,
V_13 -> V_16 ) ;
goto V_25;
}
V_2 = F_11 ( & V_11 -> V_23 , struct V_1 , V_26 ) ;
V_25:
return V_2 ;
}
static int F_12 ( struct V_10 * V_11 ,
struct V_12 V_13 )
{
struct V_27 * V_28 = F_13 ( V_11 , struct V_27 , V_11 ) ;
if ( F_14 ( V_13 . V_16 ) ) {
switch ( F_15 ( V_13 . V_16 ) ) {
case V_29 :
F_10 ( V_11 -> V_24 , L_2 , V_13 . V_16 ) ;
break;
case V_30 :
F_10 ( V_11 -> V_24 , L_3 ,
V_13 . V_16 ) ;
break;
case V_31 :
V_28 -> V_32 = true ;
F_16 ( & V_28 -> V_33 ) ;
break;
case V_34 :
F_17 ( V_11 -> V_24 , L_4 ) ;
V_28 -> V_35 ( V_11 -> V_24 , false ) ;
V_28 -> V_36 = true ;
break;
default:
F_10 ( V_11 -> V_24 , L_5 ,
V_13 . V_16 ) ;
break;
}
}
return 0 ;
}
static void F_18 ( struct V_10 * V_11 ,
struct V_12 V_13 )
{
struct V_1 * V_2 ;
T_2 V_37 = V_13 . V_16 & V_38 ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
V_2 = F_8 ( V_11 , * V_22 ) ;
if ( V_2 == NULL ) {
F_17 ( V_11 -> V_24 , L_6 ) ;
return;
}
switch ( V_37 ) {
case V_39 :
F_17 ( V_11 -> V_24 , L_7 , V_13 . V_16 ) ;
F_19 ( V_11 -> V_6 , V_2 -> V_40 , V_2 -> V_41 ) ;
break;
case V_42 :
F_10 ( V_11 -> V_24 , L_8 , V_13 . V_16 ) ;
V_2 -> V_43 = - V_44 ;
break;
case V_45 :
F_10 ( V_11 -> V_24 , L_9 , V_13 . V_16 ) ;
V_2 -> V_43 = - V_46 ;
break;
default:
F_10 ( V_11 -> V_24 , L_10 , V_37 ) ;
V_2 -> V_43 = - V_47 ;
break;
}
if ( V_37 != V_39 ) {
F_10 ( V_11 -> V_24 , L_11 , V_37 ) ;
F_10 ( V_11 -> V_24 , L_12 ,
V_11 -> V_6 -> V_19 . V_48 ( V_11 -> V_6 ) ) ;
}
F_20 ( & V_2 -> V_26 ) ;
F_21 ( V_11 , V_2 ) ;
}
T_4 F_22 ( int V_49 , void * V_50 )
{
struct V_5 * V_6 = V_50 ;
struct V_27 * V_28 = F_23 ( V_6 ) ;
struct V_10 * V_11 = & V_28 -> V_11 ;
struct V_12 V_13 = { 0 } ;
T_2 V_51 , V_52 , V_53 ;
int V_54 = 0 ;
if ( V_6 -> V_55 & V_56 )
F_24 ( V_6 ) ;
if ( ! ( V_6 -> V_55 & V_57 ) )
return V_58 ;
V_51 = F_3 ( V_6 , V_14 ) ;
V_52 = F_3 ( V_6 , V_59 ) ;
if ( V_51 & V_60 ) {
F_25 ( V_6 , V_61 ,
V_62 , 0 ) ;
F_26 ( V_6 , V_14 ,
V_60 , V_60 ) ;
V_54 = 1 ;
F_25 ( V_6 , V_61 ,
V_62 , V_62 ) ;
}
if ( V_52 & V_63 ) {
V_53 = F_3 ( V_6 , V_64 ) ;
V_13 . V_16 = V_52 ;
V_13 . V_15 = V_53 ;
F_17 ( V_6 -> V_24 , L_13 ,
V_13 . V_16 ) ;
F_17 ( V_6 -> V_24 , L_14 ,
V_13 . V_15 ) ;
if ( F_27 ( V_13 . V_16 ) ) {
F_18 ( V_11 , V_13 ) ;
} else {
F_17 ( V_6 -> V_24 , L_15 ) ;
F_12 ( V_11 , V_13 ) ;
}
F_26 ( V_6 , V_59 ,
V_63 , V_63 ) ;
V_54 = 1 ;
}
if ( V_54 == 0 )
return V_58 ;
F_28 ( V_6 ) ;
F_29 ( & V_11 -> V_65 ) ;
return V_66 ;
}
void F_28 ( struct V_5 * V_67 )
{
F_25 ( V_67 , V_68 ,
V_69 , V_69 ) ;
}
void F_30 ( struct V_5 * V_67 )
{
F_31 ( V_67 , V_68 ,
V_69 , 0 ) ;
}
void F_32 ( struct V_5 * V_67 )
{
F_25 ( V_67 , V_61 ,
V_62 , V_62 ) ;
F_25 ( V_67 , V_61 ,
V_70 , V_70 ) ;
}
void F_33 ( struct V_5 * V_67 )
{
F_31 ( V_67 , V_61 ,
V_62 , 0 ) ;
F_31 ( V_67 , V_61 ,
V_70 , 0 ) ;
}
bool F_34 ( struct V_5 * V_67 )
{
return F_3 ( V_67 ,
V_71 ) & V_57 ;
}
int F_35 ( struct V_72 * V_24 , struct V_27 * V_28 )
{
struct V_10 * V_11 ;
int V_73 ;
V_11 = & V_28 -> V_11 ;
V_11 -> V_6 = V_28 -> V_6 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_74 = V_75 ;
V_11 -> V_76 = V_77 ;
V_73 = F_36 ( V_11 ) ;
if ( V_73 )
return V_73 ;
V_11 -> V_78 . V_79 = F_4 ;
V_11 -> V_78 . V_80 = F_1 ;
V_11 -> V_78 . V_81 = F_2 ;
return 0 ;
}
void F_37 ( struct V_10 * V_11 )
{
F_25 ( V_11 -> V_6 , V_61 ,
V_62 , 0 ) ;
F_25 ( V_11 -> V_6 , V_61 ,
V_70 , 0 ) ;
F_38 ( V_11 ) ;
}
int F_39 ( struct V_10 * V_11 ,
T_5 V_82 , T_6 V_83 , T_6 V_84 , T_6 V_85 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_88 ) ;
V_13 . V_16 |= F_43 ( V_84 ) ;
V_13 . V_16 |= F_44 ( V_83 ) ;
V_13 . V_16 |= F_45 ( V_82 ) ;
V_13 . V_15 = F_46 ( V_85 ) ;
F_17 ( V_11 -> V_24 , L_16 , V_89 , V_13 . V_16 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_17 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
int F_48 ( struct V_10 * V_11 , T_6 V_84 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_90 ) ;
V_13 . V_16 |= F_43 ( V_84 ) ;
F_17 ( V_11 -> V_24 , L_16 , V_89 , V_13 . V_16 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_18 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
int F_49 ( struct V_10 * V_11 ,
T_6 V_84 , enum V_91 V_17 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_92 ) ;
V_13 . V_16 |= F_43 ( V_84 ) ;
V_13 . V_16 |= F_50 ( V_17 ) ;
F_17 ( V_11 -> V_24 , L_16 , V_89 , V_13 . V_16 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_19 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
int
F_51 ( struct V_10 * V_11 , T_6 V_84 , int V_93 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_94 ) ;
V_13 . V_16 |= F_43 ( V_84 ) ;
V_13 . V_15 = F_52 ( V_93 ) ;
F_17 ( V_11 -> V_24 , L_16 , V_89 , V_13 . V_16 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_20 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
int F_53 ( struct V_10 * V_11 , T_6 V_84 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_95 ) ;
V_13 . V_16 |= F_43 ( V_84 ) ;
F_17 ( V_11 -> V_24 , L_16 , V_89 , V_13 . V_16 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_21 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
int F_54 ( struct V_10 * V_11 , T_6 V_84 ,
T_5 V_96 , struct V_97 * V_98 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_99 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_100 ) ;
V_13 . V_16 |= F_55 ( V_84 ) ;
V_13 . V_16 |= F_56 ( V_96 ) ;
F_17 ( V_11 -> V_24 , L_22 , V_89 ,
V_13 . V_16 , V_13 . V_15 ) ;
V_18 = F_47 ( V_11 , * V_22 ,
V_98 , sizeof( * V_98 ) , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_23 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
int F_57 ( struct V_10 * V_11 ,
struct V_101 * V_2 , void * V_102 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
T_2 * V_103 = ( T_2 * ) V_102 ;
T_5 V_104 = V_2 -> V_105 / sizeof( T_2 ) ;
F_58 ( L_24 , V_106 ,
16 , 4 , V_103 , V_104 , false ) ;
V_13 . V_16 = F_40 ( V_99 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_107 ) ;
V_13 . V_16 |= F_55 ( V_2 -> V_84 ) ;
V_13 . V_16 |= F_56 ( V_2 -> V_96 ) ;
V_13 . V_15 = F_59 ( V_2 -> V_108 ) ;
V_13 . V_15 |= F_60 ( V_2 -> V_109 ) ;
V_13 . V_15 |= F_61 ( V_104 ) ;
V_13 . V_15 |= F_62 ( V_2 -> V_110 ) ;
F_17 ( V_11 -> V_24 , L_22 , V_89 ,
V_13 . V_16 , V_13 . V_15 ) ;
V_18 = F_47 ( V_11 , * V_22 , V_102 ,
V_2 -> V_105 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_25 ) ;
return V_18 ;
}
return V_18 ;
}
int F_63 ( struct V_10 * V_11 ,
struct V_111 * V_2 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
T_6 V_112 = V_2 -> V_113 ? V_114 : V_115 ;
int V_18 ;
V_13 . V_16 = F_40 ( V_99 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_112 ) ;
V_13 . V_16 |= F_55 ( V_2 -> V_84 ) ;
V_13 . V_16 |= F_56 ( V_2 -> V_96 ) ;
V_13 . V_15 = F_64 ( V_2 -> V_116 ) ;
V_13 . V_15 |= F_65 ( V_2 -> V_117 ) ;
V_13 . V_15 |= F_66 ( V_2 -> V_118 ) ;
V_13 . V_15 |= F_67 ( V_2 -> V_119 ) ;
F_17 ( V_11 -> V_24 , L_26 , V_89 , V_13 . V_16 ,
V_13 . V_15 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 , L_27 ) ;
return V_18 ;
}
return V_18 ;
}
int F_68 ( struct V_10 * V_11 ,
T_6 V_120 , void * V_121 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_122 ) ;
V_13 . V_16 |= F_69 ( V_120 ) ;
V_18 = F_47 ( V_11 , * V_22 , V_121 ,
( sizeof( T_5 ) * V_120 ) , NULL , 0 ) ;
if ( V_18 < 0 )
F_10 ( V_11 -> V_24 , L_28 , V_18 ) ;
return V_18 ;
}
int F_70 ( struct V_10 * V_11 , T_6 V_120 ,
void * V_121 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_123 ) ;
V_13 . V_16 |= F_69 ( V_120 ) ;
V_18 = F_47 ( V_11 , * V_22 , V_121 ,
( sizeof( T_5 ) * V_120 ) , NULL , 0 ) ;
if ( V_18 < 0 )
F_10 ( V_11 -> V_24 , L_29 , V_18 ) ;
return V_18 ;
}
int F_71 ( struct V_10 * V_11 ,
struct V_124 * V_2 , T_2 * V_125 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 = 0 ;
T_1 V_126 , V_4 , V_127 ;
V_13 . V_16 = F_40 ( V_99 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_128 ) ;
V_13 . V_16 |= F_55 ( V_2 -> V_84 ) ;
V_13 . V_16 |= F_56 ( V_2 -> V_96 ) ;
V_13 . V_15 = F_72 ( V_2 -> V_105 ) ;
V_13 . V_15 |= F_73 ( V_2 -> V_129 ) ;
V_13 . V_15 |= F_74 ( 0 ) ;
V_13 . V_15 |= F_75 ( 1 ) ;
V_126 = V_2 -> V_105 ;
V_127 = 0 ;
while ( V_126 != 0 ) {
V_4 = V_126 > V_75
? V_75 : V_126 ;
if ( V_4 == V_126 )
V_13 . V_15 |= F_74 ( 1 ) ;
F_17 ( V_11 -> V_24 , L_30 , V_89 ,
V_13 . V_16 , V_13 . V_15 ) ;
F_17 ( V_11 -> V_24 , L_31 ,
( unsigned ) V_127 , ( unsigned ) V_4 ) ;
V_18 = F_47 ( V_11 , * V_22 ,
( ( char * ) V_125 ) + V_127 ,
V_4 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 ,
L_32 , V_18 ) ;
return V_18 ;
}
V_126 -= V_4 ;
V_127 = V_2 -> V_105 - V_126 ;
V_13 . V_15 &= V_130 ;
V_13 . V_15 &= V_131 ;
V_13 . V_15 |= F_75 ( 0 ) ;
V_13 . V_15 |= F_72 ( V_127 ) ;
}
return V_18 ;
}
int F_76 ( struct V_10 * V_11 ,
struct V_124 * V_2 , T_2 * V_125 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 = 0 ;
T_1 V_126 , V_41 , V_127 ;
V_13 . V_16 = F_40 ( V_99 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_132 ) ;
V_13 . V_16 |= F_55 ( V_2 -> V_84 ) ;
V_13 . V_16 |= F_56 ( V_2 -> V_96 ) ;
V_13 . V_15 = F_72 ( V_2 -> V_105 ) ;
V_13 . V_15 |= F_73 ( V_2 -> V_129 ) ;
V_13 . V_15 |= F_74 ( 1 ) ;
V_13 . V_15 |= F_75 ( 1 ) ;
V_126 = V_2 -> V_105 ;
V_127 = 0 ;
while ( V_126 != 0 ) {
V_41 = V_126 > V_75
? V_75 : V_126 ;
if ( V_41 == V_126 )
V_13 . V_15 |= F_74 ( 1 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 ,
( ( char * ) V_125 ) + V_127 ,
V_2 -> V_105 ) ;
if ( V_18 < 0 ) {
F_10 ( V_11 -> V_24 ,
L_33 , V_18 ) ;
return V_18 ;
}
V_126 -= V_41 ;
V_127 = V_2 -> V_105 - V_126 ;
V_13 . V_15 &= V_130 ;
V_13 . V_15 &= V_131 ;
V_13 . V_15 |= F_75 ( 1 ) ;
V_13 . V_15 |= F_72 ( V_127 ) ;
}
return V_18 ;
}
int F_77 ( struct V_10 * V_11 ,
T_6 V_93 , T_6 V_133 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 = 0 ;
V_13 . V_16 = F_40 ( V_86 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_134 ) ;
V_13 . V_16 |= F_55 ( V_133 ) ;
V_13 . V_16 |= F_56 ( V_93 ) ;
V_18 = F_47 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 )
F_10 ( V_11 -> V_24 , L_34 ) ;
return V_18 ;
}
int F_78 ( struct V_10 * V_11 , struct V_135 * V_2 )
{
struct V_12 V_13 = { 0 } ;
T_3 * V_22 = ( T_3 * ) ( & V_13 ) ;
int V_18 ;
V_13 . V_16 = F_40 ( V_99 ) ;
V_13 . V_16 |= F_41 ( V_87 ) ;
V_13 . V_16 |= F_42 ( V_136 ) ;
V_13 . V_16 |= F_55 ( V_2 -> V_84 ) ;
V_13 . V_16 |= F_56 ( V_2 -> V_96 ) ;
V_13 . V_15 = F_79 ( V_2 -> V_137 ) ;
V_13 . V_15 |= F_80 ( V_2 -> V_138 ) ;
F_17 ( V_11 -> V_24 , L_35 , V_89 ,
V_13 . V_16 , V_13 . V_15 ) ;
V_18 = F_81 ( V_11 , * V_22 , NULL , 0 , NULL , 0 ) ;
if ( V_18 < 0 )
F_10 ( V_11 -> V_24 , L_36 , V_18 ) ;
return V_18 ;
}
