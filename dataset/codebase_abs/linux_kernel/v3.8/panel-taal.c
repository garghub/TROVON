static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = F_2 ( V_3 ) ;
V_2 -> V_5 = V_6 + V_2 -> V_4 ;
}
static void V_4 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_2 -> V_5 - V_6 ;
if ( ( long ) V_7 > 0 && V_7 <= V_2 -> V_4 ) {
F_3 ( V_8 ) ;
F_4 ( V_7 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , T_1 V_9 , T_1 * V_10 )
{
int V_11 ;
T_1 V_12 [ 1 ] ;
V_11 = F_6 ( V_2 -> V_13 , V_2 -> V_14 , V_9 , V_12 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_10 = V_12 [ 0 ] ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
return F_8 ( V_2 -> V_13 , V_2 -> V_14 , & V_9 , 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_15 )
{
T_1 V_12 [ 2 ] ;
V_12 [ 0 ] = V_9 ;
V_12 [ 1 ] = V_15 ;
return F_8 ( V_2 -> V_13 , V_2 -> V_14 , V_12 , 2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_16 ;
int V_11 ;
V_4 ( V_2 ) ;
V_16 = V_17 ;
V_11 = F_11 ( V_2 -> V_13 , V_2 -> V_14 , & V_16 , 1 ) ;
if ( V_11 )
return V_11 ;
F_1 ( V_2 , 120 ) ;
if ( V_2 -> V_18 -> V_19 . V_20 )
F_12 ( V_2 -> V_18 -> V_19 . V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_11 ;
V_4 ( V_2 ) ;
V_11 = F_7 ( V_2 , V_21 ) ;
if ( V_11 )
return V_11 ;
F_1 ( V_2 , 120 ) ;
if ( V_2 -> V_18 -> V_19 . V_22 )
F_12 ( V_2 -> V_18 -> V_19 . V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_23 , T_1 * V_24 , T_1 * V_25 )
{
int V_11 ;
V_11 = F_5 ( V_2 , V_26 , V_23 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_2 , V_27 , V_24 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_2 , V_28 , V_25 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_29 , bool V_30 )
{
int V_11 ;
T_1 V_31 ;
int V_32 , V_33 , V_34 ;
V_11 = F_5 ( V_2 , V_35 , & V_31 ) ;
if ( V_11 )
return V_11 ;
switch ( V_29 ) {
default:
case 0 :
V_34 = 0 ;
V_33 = 0 ;
V_32 = 0 ;
break;
case 1 :
V_34 = 0 ;
V_33 = 1 ;
V_32 = 1 ;
break;
case 2 :
V_34 = 1 ;
V_33 = 1 ;
V_32 = 0 ;
break;
case 3 :
V_34 = 1 ;
V_33 = 0 ;
V_32 = 1 ;
break;
}
if ( V_30 )
V_33 = ! V_33 ;
V_31 &= ~ ( ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ) ;
V_31 |= ( V_34 << 7 ) | ( V_33 << 6 ) | ( V_32 << 5 ) ;
return F_9 ( V_2 , V_36 , V_31 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
T_2 V_37 , T_2 V_38 , T_2 V_39 , T_2 V_40 )
{
int V_11 ;
T_2 V_41 = V_37 ;
T_2 V_42 = V_37 + V_39 - 1 ;
T_2 y1 = V_38 ;
T_2 V_43 = V_38 + V_40 - 1 ;
T_1 V_12 [ 5 ] ;
V_12 [ 0 ] = V_44 ;
V_12 [ 1 ] = ( V_41 >> 8 ) & 0xff ;
V_12 [ 2 ] = ( V_41 >> 0 ) & 0xff ;
V_12 [ 3 ] = ( V_42 >> 8 ) & 0xff ;
V_12 [ 4 ] = ( V_42 >> 0 ) & 0xff ;
V_11 = F_11 ( V_2 -> V_13 , V_2 -> V_14 , V_12 , sizeof( V_12 ) ) ;
if ( V_11 )
return V_11 ;
V_12 [ 0 ] = V_45 ;
V_12 [ 1 ] = ( y1 >> 8 ) & 0xff ;
V_12 [ 2 ] = ( y1 >> 0 ) & 0xff ;
V_12 [ 3 ] = ( V_43 >> 8 ) & 0xff ;
V_12 [ 4 ] = ( V_43 >> 0 ) & 0xff ;
V_11 = F_11 ( V_2 -> V_13 , V_2 -> V_14 , V_12 , sizeof( V_12 ) ) ;
if ( V_11 )
return V_11 ;
F_17 ( V_2 -> V_13 , V_2 -> V_14 ) ;
return V_11 ;
}
static void F_18 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
if ( V_2 -> V_48 > 0 )
F_20 ( V_2 -> V_49 , & V_2 -> V_50 ,
F_2 ( V_2 -> V_48 ) ) ;
}
static void F_21 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
F_22 ( & V_2 -> V_50 ) ;
}
static void F_23 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
if ( V_2 -> V_51 > 0 )
F_20 ( V_2 -> V_49 , & V_2 -> V_52 ,
F_2 ( V_2 -> V_51 ) ) ;
}
static void F_24 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
F_22 ( & V_2 -> V_52 ) ;
}
static int F_25 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
if ( V_2 -> V_53 )
return 0 ;
F_24 ( V_13 ) ;
V_11 = F_26 ( V_13 , false ) ;
if ( V_11 )
goto V_54;
if ( F_27 ( V_2 -> V_55 ) )
F_28 ( F_29 ( V_2 -> V_55 ) ) ;
F_30 ( V_13 , false , true ) ;
V_2 -> V_53 = true ;
return 0 ;
V_54:
F_31 ( & V_13 -> V_47 , L_1 ) ;
F_32 ( V_13 ) ;
V_2 -> V_53 = false ;
F_23 ( V_13 ) ;
return V_11 ;
}
static int F_33 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
if ( ! V_2 -> V_53 )
return 0 ;
V_11 = F_34 ( V_13 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_2 ) ;
goto V_56;
}
F_35 ( V_13 , V_2 -> V_14 , true ) ;
V_11 = F_26 ( V_13 , true ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_3 ) ;
goto V_57;
}
if ( F_27 ( V_2 -> V_55 ) )
F_36 ( F_29 ( V_2 -> V_55 ) ) ;
F_23 ( V_13 ) ;
V_2 -> V_53 = false ;
return 0 ;
V_57:
F_31 ( & V_13 -> V_47 , L_4 ) ;
V_11 = F_32 ( V_13 ) ;
if ( ! V_11 ) {
if ( F_27 ( V_2 -> V_55 ) )
F_36 ( F_29 ( V_2 -> V_55 ) ) ;
V_2 -> V_53 = false ;
}
V_56:
F_23 ( V_13 ) ;
return V_11 ;
}
static int F_37 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
if ( V_2 -> V_53 )
return F_33 ( V_13 ) ;
F_24 ( V_13 ) ;
F_23 ( V_13 ) ;
return 0 ;
}
static int F_38 ( struct V_58 * V_47 )
{
struct V_46 * V_13 = F_19 ( & V_47 -> V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
int V_59 ;
if ( V_47 -> V_60 . V_61 == V_62 &&
V_47 -> V_60 . V_63 == V_62 )
V_59 = V_47 -> V_60 . V_64 ;
else
V_59 = 0 ;
F_39 ( & V_13 -> V_47 , L_5 , V_59 ) ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_66 ) {
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_2 , V_67 , V_59 ) ;
F_42 ( V_13 ) ;
} else {
V_11 = 0 ;
}
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_44 ( struct V_58 * V_47 )
{
if ( V_47 -> V_60 . V_61 == V_62 &&
V_47 -> V_60 . V_63 == V_62 )
return V_47 -> V_60 . V_64 ;
return 0 ;
}
static void F_45 ( struct V_46 * V_13 ,
T_2 * V_68 , T_2 * V_69 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
if ( V_2 -> V_29 == 0 || V_2 -> V_29 == 2 ) {
* V_68 = V_13 -> V_70 . V_71 . V_72 ;
* V_69 = V_13 -> V_70 . V_71 . V_73 ;
} else {
* V_69 = V_13 -> V_70 . V_71 . V_72 ;
* V_68 = V_13 -> V_70 . V_71 . V_73 ;
}
}
static T_3 F_46 ( struct V_74 * V_47 ,
struct V_75 * V_76 , char * V_12 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
T_1 V_77 = 0 ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_66 ) {
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_2 , V_78 , & V_77 ) ;
F_42 ( V_13 ) ;
} else {
V_11 = - V_79 ;
}
F_43 ( & V_2 -> V_65 ) ;
if ( V_11 )
return V_11 ;
return snprintf ( V_12 , V_80 , L_6 , V_77 ) ;
}
static T_3 F_48 ( struct V_74 * V_47 ,
struct V_75 * V_76 , char * V_12 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
T_1 V_23 , V_24 , V_25 ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_66 ) {
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( ! V_11 )
V_11 = F_14 ( V_2 , & V_23 , & V_24 , & V_25 ) ;
F_42 ( V_13 ) ;
} else {
V_11 = - V_79 ;
}
F_43 ( & V_2 -> V_65 ) ;
if ( V_11 )
return V_11 ;
return snprintf ( V_12 , V_80 , L_7 , V_23 , V_24 , V_25 ) ;
}
static T_3 F_49 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
char * V_12 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
const char * V_81 ;
int V_31 ;
int V_82 ;
V_31 = V_2 -> V_83 ;
V_81 = L_8 ;
if ( V_31 >= 0 && V_31 < F_50 ( V_84 ) )
V_81 = V_84 [ V_31 ] ;
V_82 = snprintf ( V_12 , V_80 , L_9 , V_81 ) ;
return V_82 < V_80 - 1 ? V_82 : V_80 - 1 ;
}
static T_3 F_51 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
const char * V_12 , T_4 V_85 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_86 ;
int V_11 ;
for ( V_86 = 0 ; V_86 < F_50 ( V_84 ) ; V_86 ++ ) {
if ( F_52 ( V_84 [ V_86 ] , V_12 ) )
break;
}
if ( V_86 == F_50 ( V_84 ) )
return - V_87 ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_66 ) {
F_41 ( V_13 ) ;
if ( ! V_2 -> V_88 ) {
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_54;
V_11 = F_9 ( V_2 , V_89 , V_86 ) ;
if ( V_11 )
goto V_54;
}
F_42 ( V_13 ) ;
}
V_2 -> V_83 = V_86 ;
F_43 ( & V_2 -> V_65 ) ;
return V_85 ;
V_54:
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static T_3 F_53 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
char * V_12 )
{
int V_82 ;
int V_86 ;
for ( V_86 = 0 , V_82 = 0 ;
V_82 < V_80 && V_86 < F_50 ( V_84 ) ; V_86 ++ )
V_82 += snprintf ( & V_12 [ V_82 ] , V_80 - V_82 , L_10 ,
V_86 ? L_11 : L_12 , V_84 [ V_86 ] ,
V_86 == F_50 ( V_84 ) - 1 ? L_13 : L_12 ) ;
return V_82 < V_80 ? V_82 : V_80 - 1 ;
}
static T_3 F_54 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
const char * V_12 , T_4 V_85 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
unsigned long V_90 ;
int V_11 ;
V_11 = F_55 ( V_12 , 10 , & V_90 ) ;
if ( V_11 )
return V_11 ;
F_40 ( & V_2 -> V_65 ) ;
F_21 ( V_13 ) ;
V_2 -> V_48 = V_90 ;
if ( V_2 -> V_66 )
F_18 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_85 ;
}
static T_3 F_56 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
char * V_12 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
unsigned V_90 ;
F_40 ( & V_2 -> V_65 ) ;
V_90 = V_2 -> V_48 ;
F_43 ( & V_2 -> V_65 ) ;
return snprintf ( V_12 , V_80 , L_14 , V_90 ) ;
}
static T_3 F_57 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
const char * V_12 , T_4 V_85 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
unsigned long V_90 ;
int V_11 ;
V_11 = F_55 ( V_12 , 10 , & V_90 ) ;
if ( V_11 )
return V_11 ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_66 ) {
F_41 ( V_13 ) ;
if ( V_90 )
V_11 = F_25 ( V_13 ) ;
else
V_11 = F_37 ( V_13 ) ;
F_42 ( V_13 ) ;
}
F_43 ( & V_2 -> V_65 ) ;
if ( V_11 )
return V_11 ;
return V_85 ;
}
static T_3 F_58 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
char * V_12 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
unsigned V_90 ;
F_40 ( & V_2 -> V_65 ) ;
V_90 = V_2 -> V_53 ;
F_43 ( & V_2 -> V_65 ) ;
return snprintf ( V_12 , V_80 , L_14 , V_90 ) ;
}
static T_3 F_59 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
const char * V_12 , T_4 V_85 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
unsigned long V_90 ;
int V_11 ;
V_11 = F_55 ( V_12 , 10 , & V_90 ) ;
if ( V_11 )
return V_11 ;
F_40 ( & V_2 -> V_65 ) ;
V_2 -> V_51 = V_90 ;
if ( V_2 -> V_66 ) {
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
F_42 ( V_13 ) ;
}
F_43 ( & V_2 -> V_65 ) ;
if ( V_11 )
return V_11 ;
return V_85 ;
}
static T_3 F_60 ( struct V_74 * V_47 ,
struct V_75 * V_76 ,
char * V_12 )
{
struct V_46 * V_13 = F_47 ( V_47 ) ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
unsigned V_90 ;
F_40 ( & V_2 -> V_65 ) ;
V_90 = V_2 -> V_51 ;
F_43 ( & V_2 -> V_65 ) ;
return snprintf ( V_12 , V_80 , L_14 , V_90 ) ;
}
static void F_61 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
if ( ! F_27 ( V_2 -> V_91 ) )
return;
F_62 ( V_2 -> V_91 , 1 ) ;
if ( V_2 -> V_18 -> V_92 . V_93 )
F_63 ( V_2 -> V_18 -> V_92 . V_93 ) ;
F_62 ( V_2 -> V_91 , 0 ) ;
if ( V_2 -> V_18 -> V_92 . V_94 )
F_63 ( V_2 -> V_18 -> V_92 . V_94 ) ;
F_62 ( V_2 -> V_91 , 1 ) ;
if ( V_2 -> V_18 -> V_19 . V_95 )
F_12 ( V_2 -> V_18 -> V_19 . V_95 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
const struct V_96 * V_97 )
{
V_2 -> V_91 = V_97 -> V_91 ;
if ( V_97 -> V_98 )
V_2 -> V_55 = V_97 -> V_55 ;
else
V_2 -> V_55 = - 1 ;
V_2 -> V_48 = V_97 -> V_48 ;
V_2 -> V_51 = V_97 -> V_51 ;
V_2 -> V_99 = V_97 -> V_99 ;
V_2 -> V_100 = V_97 -> V_100 ;
}
static int F_65 ( struct V_46 * V_13 )
{
struct V_101 V_60 ;
struct V_1 * V_2 ;
struct V_58 * V_102 = NULL ;
int V_11 , V_86 ;
const char * V_103 ;
F_39 ( & V_13 -> V_47 , L_15 ) ;
V_2 = F_66 ( & V_13 -> V_47 , sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
F_67 ( & V_13 -> V_47 , V_2 ) ;
V_2 -> V_13 = V_13 ;
if ( V_13 -> V_10 ) {
const struct V_96 * V_97 = V_13 -> V_10 ;
F_64 ( V_2 , V_97 ) ;
V_103 = V_97 -> V_106 ;
} else {
return - V_79 ;
}
if ( V_103 == NULL )
return - V_87 ;
for ( V_86 = 0 ; V_86 < F_50 ( V_107 ) ; V_86 ++ ) {
if ( strcmp ( V_103 , V_107 [ V_86 ] . V_106 ) == 0 ) {
V_2 -> V_18 = & V_107 [ V_86 ] ;
break;
}
}
if ( ! V_2 -> V_18 )
return - V_87 ;
V_13 -> V_70 . V_71 = V_2 -> V_18 -> V_71 ;
V_13 -> V_70 . V_108 = V_109 ;
V_13 -> V_110 = V_111 |
V_112 ;
F_68 ( & V_2 -> V_65 ) ;
F_69 ( & V_2 -> V_113 , 0 ) ;
if ( F_27 ( V_2 -> V_91 ) ) {
V_11 = F_70 ( & V_13 -> V_47 , V_2 -> V_91 ,
V_114 , L_16 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_17 ) ;
return V_11 ;
}
}
if ( F_27 ( V_2 -> V_55 ) ) {
V_11 = F_70 ( & V_13 -> V_47 , V_2 -> V_55 ,
V_115 , L_18 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_19 ) ;
return V_11 ;
}
V_11 = F_71 ( & V_13 -> V_47 , F_29 ( V_2 -> V_55 ) ,
V_116 ,
V_117 ,
L_20 , V_13 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_21 ) ;
return V_11 ;
}
F_72 ( & V_2 -> V_118 ,
V_119 ) ;
F_39 ( & V_13 -> V_47 , L_22 ) ;
}
V_2 -> V_49 = F_73 ( L_23 ) ;
if ( V_2 -> V_49 == NULL ) {
F_31 ( & V_13 -> V_47 , L_24 ) ;
return - V_105 ;
}
F_72 ( & V_2 -> V_50 , V_120 ) ;
F_74 ( & V_2 -> V_52 , V_121 ) ;
F_61 ( V_13 ) ;
if ( V_2 -> V_99 ) {
memset ( & V_60 , 0 , sizeof( struct V_101 ) ) ;
V_60 . V_122 = 255 ;
V_60 . type = V_123 ;
V_102 = F_75 ( F_76 ( & V_13 -> V_47 ) ,
& V_13 -> V_47 , V_13 , & V_124 , & V_60 ) ;
if ( F_77 ( V_102 ) ) {
V_11 = F_78 ( V_102 ) ;
goto V_125;
}
V_2 -> V_102 = V_102 ;
V_102 -> V_60 . V_61 = V_62 ;
V_102 -> V_60 . V_63 = V_62 ;
V_102 -> V_60 . V_64 = 255 ;
F_38 ( V_102 ) ;
}
V_11 = F_79 ( V_13 , & V_2 -> V_14 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_25 ) ;
goto V_126;
}
V_11 = F_80 ( V_13 , V_2 -> V_14 , V_127 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_26 ) ;
goto V_128;
}
V_11 = F_81 ( & V_13 -> V_47 . V_129 , & V_130 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_27 ) ;
goto V_128;
}
return 0 ;
V_128:
F_82 ( V_13 , V_2 -> V_14 ) ;
V_126:
if ( V_102 != NULL )
F_83 ( V_102 ) ;
V_125:
F_84 ( V_2 -> V_49 ) ;
return V_11 ;
}
static void T_5 F_85 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
struct V_58 * V_102 ;
F_39 ( & V_13 -> V_47 , L_28 ) ;
F_86 ( & V_13 -> V_47 . V_129 , & V_130 ) ;
F_82 ( V_13 , V_2 -> V_14 ) ;
V_102 = V_2 -> V_102 ;
if ( V_102 != NULL ) {
V_102 -> V_60 . V_63 = V_131 ;
F_38 ( V_102 ) ;
F_83 ( V_102 ) ;
}
F_24 ( V_13 ) ;
F_21 ( V_13 ) ;
F_84 ( V_2 -> V_49 ) ;
F_61 ( V_13 ) ;
}
static int F_87 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
T_1 V_23 , V_24 , V_25 ;
int V_11 ;
V_11 = F_88 ( V_13 , & V_2 -> V_100 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_29 ) ;
goto V_132;
} ;
F_89 ( V_13 , V_13 -> V_70 . V_71 . V_72 ,
V_13 -> V_70 . V_71 . V_73 ) ;
F_90 ( V_13 , V_109 ) ;
F_91 ( V_13 , V_133 ) ;
V_11 = F_92 ( V_13 , 216000000 , 10000000 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_30 ) ;
goto V_132;
}
V_11 = F_34 ( V_13 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_2 ) ;
goto V_132;
}
F_61 ( V_13 ) ;
F_35 ( V_13 , V_2 -> V_14 , false ) ;
V_11 = F_13 ( V_2 ) ;
if ( V_11 )
goto V_54;
V_11 = F_14 ( V_2 , & V_23 , & V_24 , & V_25 ) ;
if ( V_11 )
goto V_54;
if ( V_2 -> V_18 -> type == V_134 &&
( V_24 == 0x00 || V_24 == 0xff || V_24 == 0x81 ) )
V_2 -> V_88 = true ;
V_11 = F_9 ( V_2 , V_67 , 0xff ) ;
if ( V_11 )
goto V_54;
V_11 = F_9 ( V_2 , V_135 ,
( 1 << 2 ) | ( 1 << 5 ) ) ;
if ( V_11 )
goto V_54;
V_11 = F_9 ( V_2 , V_136 ,
V_137 ) ;
if ( V_11 )
goto V_54;
V_11 = F_15 ( V_2 , V_2 -> V_29 , V_2 -> V_30 ) ;
if ( V_11 )
goto V_54;
if ( ! V_2 -> V_88 ) {
V_11 = F_9 ( V_2 , V_89 , V_2 -> V_83 ) ;
if ( V_11 )
goto V_54;
}
V_11 = F_7 ( V_2 , V_138 ) ;
if ( V_11 )
goto V_54;
V_11 = F_26 ( V_13 , V_2 -> V_139 ) ;
if ( V_11 )
goto V_54;
V_11 = F_93 ( V_13 , V_2 -> V_14 ) ;
if ( V_11 )
goto V_54;
V_2 -> V_66 = 1 ;
if ( ! V_2 -> V_140 ) {
F_94 ( & V_13 -> V_47 , L_31 ,
V_2 -> V_18 -> V_106 , V_23 , V_24 , V_25 ) ;
if ( V_2 -> V_88 )
F_94 ( & V_13 -> V_47 ,
L_32 ) ;
V_2 -> V_140 = true ;
}
F_35 ( V_13 , V_2 -> V_14 , true ) ;
return 0 ;
V_54:
F_31 ( & V_13 -> V_47 , L_33 ) ;
F_61 ( V_13 ) ;
F_30 ( V_13 , true , false ) ;
V_132:
return V_11 ;
}
static void F_95 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_96 ( V_13 , V_2 -> V_14 ) ;
V_11 = F_7 ( V_2 , V_141 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_2 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 ,
L_34 ) ;
F_61 ( V_13 ) ;
}
F_30 ( V_13 , true , false ) ;
V_2 -> V_66 = 0 ;
}
static int F_32 ( struct V_46 * V_13 )
{
F_31 ( & V_13 -> V_47 , L_35 ) ;
F_95 ( V_13 ) ;
F_61 ( V_13 ) ;
return F_87 ( V_13 ) ;
}
static int F_97 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_39 ( & V_13 -> V_47 , L_36 ) ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_13 -> V_142 != V_143 ) {
V_11 = - V_87 ;
goto V_54;
}
F_41 ( V_13 ) ;
V_11 = F_87 ( V_13 ) ;
F_42 ( V_13 ) ;
if ( V_11 )
goto V_54;
F_18 ( V_13 ) ;
V_13 -> V_142 = V_144 ;
F_43 ( & V_2 -> V_65 ) ;
return 0 ;
V_54:
F_39 ( & V_13 -> V_47 , L_37 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static void F_98 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
F_39 ( & V_13 -> V_47 , L_38 ) ;
F_40 ( & V_2 -> V_65 ) ;
F_24 ( V_13 ) ;
F_21 ( V_13 ) ;
F_41 ( V_13 ) ;
if ( V_13 -> V_142 == V_144 ) {
int V_11 ;
V_11 = F_37 ( V_13 ) ;
if ( ! V_11 )
F_95 ( V_13 ) ;
}
F_42 ( V_13 ) ;
V_13 -> V_142 = V_143 ;
F_43 ( & V_2 -> V_65 ) ;
}
static void F_99 ( int V_54 , void * V_10 )
{
struct V_46 * V_13 = V_10 ;
F_39 ( & V_13 -> V_47 , L_39 , V_54 ) ;
F_42 ( V_13 ) ;
}
static T_6 V_116 ( int V_145 , void * V_10 )
{
struct V_46 * V_13 = V_10 ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_146 ;
int V_11 ;
V_146 = F_100 ( & V_2 -> V_113 , 1 , 0 ) ;
if ( V_146 ) {
F_22 ( & V_2 -> V_118 ) ;
V_11 = F_101 ( V_13 , V_2 -> V_14 , F_99 ,
V_13 ) ;
if ( V_11 )
goto V_54;
}
return V_147 ;
V_54:
F_31 ( & V_13 -> V_47 , L_40 ) ;
F_42 ( V_13 ) ;
return V_147 ;
}
static void V_119 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_102 ( V_149 , struct V_1 ,
V_118 . V_149 ) ;
struct V_46 * V_13 = V_2 -> V_13 ;
F_31 ( & V_13 -> V_47 , L_41 ) ;
F_69 ( & V_2 -> V_113 , 0 ) ;
F_42 ( V_13 ) ;
}
static int F_103 ( struct V_46 * V_13 ,
T_2 V_37 , T_2 V_38 , T_2 V_39 , T_2 V_40 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_39 ( & V_13 -> V_47 , L_42 , V_37 , V_38 , V_39 , V_40 ) ;
F_40 ( & V_2 -> V_65 ) ;
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_54;
if ( ! V_2 -> V_66 ) {
V_11 = 0 ;
goto V_54;
}
V_11 = F_16 ( V_2 , 0 , 0 ,
V_2 -> V_18 -> V_71 . V_72 ,
V_2 -> V_18 -> V_71 . V_73 ) ;
if ( V_11 )
goto V_54;
if ( V_2 -> V_139 && F_27 ( V_2 -> V_55 ) ) {
F_104 ( & V_2 -> V_118 ,
F_2 ( 250 ) ) ;
F_69 ( & V_2 -> V_113 , 1 ) ;
} else {
V_11 = F_101 ( V_13 , V_2 -> V_14 , F_99 ,
V_13 ) ;
if ( V_11 )
goto V_54;
}
F_43 ( & V_2 -> V_65 ) ;
return 0 ;
V_54:
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_105 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
F_39 ( & V_13 -> V_47 , L_43 ) ;
F_40 ( & V_2 -> V_65 ) ;
F_41 ( V_13 ) ;
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
F_39 ( & V_13 -> V_47 , L_44 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_13 , bool V_150 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
if ( V_150 )
V_11 = F_9 ( V_2 , V_151 , 0 ) ;
else
V_11 = F_7 ( V_2 , V_152 ) ;
if ( ! F_27 ( V_2 -> V_55 ) )
F_106 ( V_13 , V_150 ) ;
if ( V_2 -> V_18 -> V_19 . V_153 )
F_12 ( V_2 -> V_18 -> V_19 . V_153 ) ;
return V_11 ;
}
static int F_107 ( struct V_46 * V_13 , bool V_150 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_139 == V_150 )
goto V_154;
F_41 ( V_13 ) ;
if ( V_2 -> V_66 ) {
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_54;
V_11 = F_26 ( V_13 , V_150 ) ;
if ( V_11 )
goto V_54;
}
V_2 -> V_139 = V_150 ;
F_42 ( V_13 ) ;
V_154:
F_43 ( & V_2 -> V_65 ) ;
return 0 ;
V_54:
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_108 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
V_11 = V_2 -> V_139 ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_109 ( struct V_46 * V_13 , T_1 V_29 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
T_2 V_155 , V_156 ;
int V_11 ;
F_39 ( & V_13 -> V_47 , L_45 , V_29 ) ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_29 == V_29 )
goto V_154;
F_41 ( V_13 ) ;
if ( V_2 -> V_66 ) {
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_54;
V_11 = F_15 ( V_2 , V_29 , V_2 -> V_30 ) ;
if ( V_11 )
goto V_54;
}
if ( V_29 == 0 || V_29 == 2 ) {
V_155 = V_13 -> V_70 . V_71 . V_72 ;
V_156 = V_13 -> V_70 . V_71 . V_73 ;
} else {
V_155 = V_13 -> V_70 . V_71 . V_73 ;
V_156 = V_13 -> V_70 . V_71 . V_72 ;
}
F_89 ( V_13 , V_155 , V_156 ) ;
V_2 -> V_29 = V_29 ;
F_42 ( V_13 ) ;
V_154:
F_43 ( & V_2 -> V_65 ) ;
return 0 ;
V_54:
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static T_1 F_110 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
V_11 = V_2 -> V_29 ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_111 ( struct V_46 * V_13 , bool V_150 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_39 ( & V_13 -> V_47 , L_46 , V_150 ) ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_30 == V_150 )
goto V_154;
F_41 ( V_13 ) ;
if ( V_2 -> V_66 ) {
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_54;
V_11 = F_15 ( V_2 , V_2 -> V_29 , V_150 ) ;
if ( V_11 )
goto V_54;
}
V_2 -> V_30 = V_150 ;
F_42 ( V_13 ) ;
V_154:
F_43 ( & V_2 -> V_65 ) ;
return 0 ;
V_54:
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static bool F_112 ( struct V_46 * V_13 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
V_11 = V_2 -> V_30 ;
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_113 ( struct V_46 * V_13 , int V_157 )
{
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
T_1 V_23 , V_24 , V_25 ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
if ( ! V_2 -> V_66 ) {
V_11 = - V_79 ;
goto V_56;
}
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_57;
V_11 = F_5 ( V_2 , V_26 , & V_23 ) ;
if ( V_11 )
goto V_57;
V_11 = F_5 ( V_2 , V_27 , & V_24 ) ;
if ( V_11 )
goto V_57;
V_11 = F_5 ( V_2 , V_28 , & V_25 ) ;
if ( V_11 )
goto V_57;
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return 0 ;
V_57:
F_42 ( V_13 ) ;
V_56:
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static int F_114 ( struct V_46 * V_13 ,
void * V_12 , T_4 V_158 ,
T_2 V_37 , T_2 V_38 , T_2 V_39 , T_2 V_40 )
{
int V_11 ;
int V_159 = 1 ;
int V_160 ;
unsigned V_161 = 0 ;
struct V_1 * V_2 = F_19 ( & V_13 -> V_47 ) ;
if ( V_158 < V_39 * V_40 * 3 )
return - V_105 ;
F_40 ( & V_2 -> V_65 ) ;
if ( ! V_2 -> V_66 ) {
V_11 = - V_79 ;
goto V_56;
}
V_158 = F_115 ( V_39 * V_40 * 3 ,
V_13 -> V_70 . V_71 . V_72 *
V_13 -> V_70 . V_71 . V_73 * 3 ) ;
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( V_11 )
goto V_57;
if ( V_158 % 2 )
V_160 = 1 ;
else
V_160 = 2 ;
F_16 ( V_2 , V_37 , V_38 , V_39 , V_40 ) ;
V_11 = F_116 ( V_13 , V_2 -> V_14 , V_160 ) ;
if ( V_11 )
goto V_57;
while ( V_161 < V_158 ) {
T_1 V_9 = V_159 ? 0x2e : 0x3e ;
V_159 = 0 ;
V_11 = F_6 ( V_13 , V_2 -> V_14 , V_9 ,
V_12 + V_161 , V_158 - V_161 ) ;
if ( V_11 < 0 ) {
F_31 ( & V_13 -> V_47 , L_47 ) ;
goto V_162;
}
V_161 += V_11 ;
if ( V_11 < V_160 ) {
F_31 ( & V_13 -> V_47 , L_48 ) ;
break;
}
if ( F_117 ( V_163 ) ) {
F_31 ( & V_13 -> V_47 , L_49
L_50 ) ;
V_11 = - V_164 ;
goto V_162;
}
}
V_11 = V_161 ;
V_162:
F_116 ( V_13 , V_2 -> V_14 , 1 ) ;
V_57:
F_42 ( V_13 ) ;
V_56:
F_43 ( & V_2 -> V_65 ) ;
return V_11 ;
}
static void V_121 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_102 ( V_149 , struct V_1 ,
V_52 . V_149 ) ;
struct V_46 * V_13 = V_2 -> V_13 ;
F_40 ( & V_2 -> V_65 ) ;
if ( V_13 -> V_142 != V_144 || ! V_2 -> V_66 ) {
F_43 ( & V_2 -> V_65 ) ;
return;
}
F_41 ( V_13 ) ;
F_25 ( V_13 ) ;
F_42 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
}
static void V_120 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_102 ( V_149 , struct V_1 ,
V_50 . V_149 ) ;
struct V_46 * V_13 = V_2 -> V_13 ;
T_1 V_165 , V_166 ;
int V_11 ;
F_40 ( & V_2 -> V_65 ) ;
if ( ! V_2 -> V_66 ) {
F_43 ( & V_2 -> V_65 ) ;
return;
}
F_41 ( V_13 ) ;
V_11 = F_37 ( V_13 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_51 ) ;
goto V_54;
}
V_11 = F_5 ( V_2 , V_167 , & V_165 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_52 ) ;
goto V_54;
}
V_11 = F_13 ( V_2 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_53 ) ;
goto V_54;
}
V_11 = F_5 ( V_2 , V_167 , & V_166 ) ;
if ( V_11 ) {
F_31 ( & V_13 -> V_47 , L_52 ) ;
goto V_54;
}
if ( ! ( ( V_165 ^ V_166 ) & ( 1 << 6 ) ) ) {
F_31 ( & V_13 -> V_47 , L_54 ) ;
goto V_54;
}
if ( V_2 -> V_139 && F_27 ( V_2 -> V_55 ) ) {
V_11 = F_9 ( V_2 , V_151 , 0 ) ;
if ( V_11 )
goto V_54;
}
F_42 ( V_13 ) ;
F_18 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
return;
V_54:
F_31 ( & V_13 -> V_47 , L_35 ) ;
F_32 ( V_13 ) ;
F_42 ( V_13 ) ;
F_18 ( V_13 ) ;
F_43 ( & V_2 -> V_65 ) ;
}
static int T_7 F_118 ( void )
{
F_119 ( & V_168 ) ;
return 0 ;
}
static void T_5 F_120 ( void )
{
F_121 ( & V_168 ) ;
}
