static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_2 ( V_2 [ V_3 - V_4 - 1 ] . V_5 ) ;
F_3 ( V_2 [ V_3 - V_4 - 1 ] . V_5 ) ;
}
}
static int F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 , int V_3 )
{
int V_8 , V_4 , V_9 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
struct V_5 * V_10 ;
V_10 = F_5 ( & V_7 -> V_11 , V_2 [ V_4 ] . V_12 ) ;
if ( F_6 ( V_10 ) ) {
F_7 ( & V_7 -> V_11 , L_1 ,
V_2 [ V_4 ] . V_12 ) ;
V_8 = F_8 ( V_10 ) ;
goto V_13;
}
V_9 = F_9 ( V_10 ) ;
if ( V_9 < V_2 [ V_4 ] . V_14 || V_9 > V_2 [ V_4 ] . V_15 ) {
V_8 = F_10 ( V_10 , V_2 [ V_4 ] . V_14 ,
V_2 [ V_4 ] . V_15 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 ,
L_2 ,
V_2 [ V_4 ] . V_12 ) ;
F_3 ( V_10 ) ;
goto V_13;
}
}
V_8 = F_11 ( V_10 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_3 ,
V_2 [ V_4 ] . V_12 ) ;
F_3 ( V_10 ) ;
goto V_13;
}
V_2 [ V_4 ] . V_5 = V_10 ;
}
return 0 ;
V_13:
F_1 ( V_2 , V_4 ) ;
return V_8 ;
}
static inline struct V_16
* F_12 ( const struct V_6 * V_7 )
{
return (struct V_16 * ) V_7 -> V_17 ;
}
static void F_13 ( struct V_18 * V_19 , int V_20 )
{
V_19 -> V_21 = F_14 ( V_20 ) ;
V_19 -> V_22 = V_23 + V_19 -> V_21 ;
}
static void V_21 ( struct V_18 * V_19 )
{
unsigned long V_24 = V_19 -> V_22 - V_23 ;
if ( ( long ) V_24 > 0 && V_24 <= V_19 -> V_21 ) {
F_15 ( V_25 ) ;
F_16 ( V_24 ) ;
}
}
static int F_17 ( struct V_18 * V_19 , T_1 V_26 , T_1 * V_17 )
{
int V_8 ;
T_1 V_27 [ 1 ] ;
V_8 = F_18 ( V_19 -> V_7 , V_19 -> V_28 , V_26 , V_27 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_17 = V_27 [ 0 ] ;
return 0 ;
}
static int F_19 ( struct V_18 * V_19 , T_1 V_26 )
{
return F_20 ( V_19 -> V_7 , V_19 -> V_28 , & V_26 , 1 ) ;
}
static int F_21 ( struct V_18 * V_19 , T_1 V_26 , T_1 V_29 )
{
T_1 V_27 [ 2 ] ;
V_27 [ 0 ] = V_26 ;
V_27 [ 1 ] = V_29 ;
return F_20 ( V_19 -> V_7 , V_19 -> V_28 , V_27 , 2 ) ;
}
static int F_22 ( struct V_18 * V_19 )
{
T_1 V_30 ;
int V_8 ;
V_21 ( V_19 ) ;
V_30 = V_31 ;
V_8 = F_23 ( V_19 -> V_7 , V_19 -> V_28 , & V_30 , 1 ) ;
if ( V_8 )
return V_8 ;
F_13 ( V_19 , 120 ) ;
if ( V_19 -> V_32 -> V_33 . V_34 )
F_24 ( V_19 -> V_32 -> V_33 . V_34 ) ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 )
{
int V_8 ;
V_21 ( V_19 ) ;
V_8 = F_19 ( V_19 , V_35 ) ;
if ( V_8 )
return V_8 ;
F_13 ( V_19 , 120 ) ;
if ( V_19 -> V_32 -> V_33 . V_36 )
F_24 ( V_19 -> V_32 -> V_33 . V_36 ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , T_1 * V_37 , T_1 * V_38 , T_1 * V_39 )
{
int V_8 ;
V_8 = F_17 ( V_19 , V_40 , V_37 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_19 , V_41 , V_38 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_19 , V_42 , V_39 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , T_1 V_43 , bool V_44 )
{
int V_8 ;
T_1 V_45 ;
int V_46 , V_47 , V_48 ;
V_8 = F_17 ( V_19 , V_49 , & V_45 ) ;
if ( V_8 )
return V_8 ;
switch ( V_43 ) {
default:
case 0 :
V_48 = 0 ;
V_47 = 0 ;
V_46 = 0 ;
break;
case 1 :
V_48 = 0 ;
V_47 = 1 ;
V_46 = 1 ;
break;
case 2 :
V_48 = 1 ;
V_47 = 1 ;
V_46 = 0 ;
break;
case 3 :
V_48 = 1 ;
V_47 = 0 ;
V_46 = 1 ;
break;
}
if ( V_44 )
V_47 = ! V_47 ;
V_45 &= ~ ( ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ) ;
V_45 |= ( V_48 << 7 ) | ( V_47 << 6 ) | ( V_46 << 5 ) ;
return F_21 ( V_19 , V_50 , V_45 ) ;
}
static int F_28 ( struct V_18 * V_19 ,
T_2 V_51 , T_2 V_52 , T_2 V_53 , T_2 V_54 )
{
int V_8 ;
T_2 V_55 = V_51 ;
T_2 V_56 = V_51 + V_53 - 1 ;
T_2 y1 = V_52 ;
T_2 V_57 = V_52 + V_54 - 1 ;
T_1 V_27 [ 5 ] ;
V_27 [ 0 ] = V_58 ;
V_27 [ 1 ] = ( V_55 >> 8 ) & 0xff ;
V_27 [ 2 ] = ( V_55 >> 0 ) & 0xff ;
V_27 [ 3 ] = ( V_56 >> 8 ) & 0xff ;
V_27 [ 4 ] = ( V_56 >> 0 ) & 0xff ;
V_8 = F_23 ( V_19 -> V_7 , V_19 -> V_28 , V_27 , sizeof( V_27 ) ) ;
if ( V_8 )
return V_8 ;
V_27 [ 0 ] = V_59 ;
V_27 [ 1 ] = ( y1 >> 8 ) & 0xff ;
V_27 [ 2 ] = ( y1 >> 0 ) & 0xff ;
V_27 [ 3 ] = ( V_57 >> 8 ) & 0xff ;
V_27 [ 4 ] = ( V_57 >> 0 ) & 0xff ;
V_8 = F_23 ( V_19 -> V_7 , V_19 -> V_28 , V_27 , sizeof( V_27 ) ) ;
if ( V_8 )
return V_8 ;
F_29 ( V_19 -> V_7 , V_19 -> V_28 ) ;
return V_8 ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
if ( V_19 -> V_60 > 0 )
F_32 ( V_19 -> V_61 , & V_19 -> V_62 ,
F_14 ( V_19 -> V_60 ) ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
F_34 ( & V_19 -> V_62 ) ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
if ( V_19 -> V_63 > 0 )
F_32 ( V_19 -> V_61 , & V_19 -> V_64 ,
F_14 ( V_19 -> V_63 ) ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
F_34 ( & V_19 -> V_64 ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
int V_8 ;
if ( V_19 -> V_66 )
return 0 ;
F_36 ( V_7 ) ;
V_8 = F_38 ( V_7 , false ) ;
if ( V_8 )
goto V_13;
F_39 ( F_40 ( V_65 -> V_67 ) ) ;
F_41 ( V_7 , false , true ) ;
V_19 -> V_66 = true ;
return 0 ;
V_13:
F_7 ( & V_7 -> V_11 , L_4 ) ;
F_42 ( V_7 ) ;
V_19 -> V_66 = false ;
F_35 ( V_7 ) ;
return V_8 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
int V_8 ;
if ( ! V_19 -> V_66 )
return 0 ;
V_8 = F_44 ( V_7 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_5 ) ;
goto V_68;
}
F_45 ( V_7 , V_19 -> V_28 , true ) ;
V_8 = F_38 ( V_7 , true ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_6 ) ;
goto V_69;
}
F_46 ( F_40 ( V_65 -> V_67 ) ) ;
F_35 ( V_7 ) ;
V_19 -> V_66 = false ;
return 0 ;
V_69:
F_7 ( & V_7 -> V_11 , L_7 ) ;
V_8 = F_42 ( V_7 ) ;
if ( ! V_8 ) {
F_46 ( F_40 ( V_65 -> V_67 ) ) ;
V_19 -> V_66 = false ;
}
V_68:
F_35 ( V_7 ) ;
return V_8 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
if ( V_19 -> V_66 )
return F_43 ( V_7 ) ;
F_36 ( V_7 ) ;
F_35 ( V_7 ) ;
return 0 ;
}
static int F_48 ( struct V_70 * V_11 )
{
struct V_6 * V_7 = F_31 ( & V_11 -> V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
int V_71 ;
if ( V_11 -> V_72 . V_73 == V_74 &&
V_11 -> V_72 . V_75 == V_74 )
V_71 = V_11 -> V_72 . V_76 ;
else
V_71 = 0 ;
F_49 ( & V_7 -> V_11 , L_8 , V_71 ) ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_78 ) {
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_21 ( V_19 , V_79 , V_71 ) ;
F_52 ( V_7 ) ;
} else {
V_8 = 0 ;
}
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_54 ( struct V_70 * V_11 )
{
if ( V_11 -> V_72 . V_73 == V_74 &&
V_11 -> V_72 . V_75 == V_74 )
return V_11 -> V_72 . V_76 ;
return 0 ;
}
static void F_55 ( struct V_6 * V_7 ,
struct V_80 * V_81 )
{
* V_81 = V_7 -> V_82 . V_81 ;
}
static void F_56 ( struct V_6 * V_7 ,
T_2 * V_83 , T_2 * V_84 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
if ( V_19 -> V_43 == 0 || V_19 -> V_43 == 2 ) {
* V_83 = V_7 -> V_82 . V_81 . V_85 ;
* V_84 = V_7 -> V_82 . V_81 . V_86 ;
} else {
* V_84 = V_7 -> V_82 . V_81 . V_85 ;
* V_83 = V_7 -> V_82 . V_81 . V_86 ;
}
}
static T_3 F_57 ( struct V_87 * V_11 ,
struct V_88 * V_89 , char * V_27 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
T_1 V_90 ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_78 ) {
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_17 ( V_19 , V_91 , & V_90 ) ;
F_52 ( V_7 ) ;
} else {
V_8 = - V_92 ;
}
F_53 ( & V_19 -> V_77 ) ;
if ( V_8 )
return V_8 ;
return snprintf ( V_27 , V_93 , L_9 , V_90 ) ;
}
static T_3 F_59 ( struct V_87 * V_11 ,
struct V_88 * V_89 , char * V_27 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
T_1 V_37 , V_38 , V_39 ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_78 ) {
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_26 ( V_19 , & V_37 , & V_38 , & V_39 ) ;
F_52 ( V_7 ) ;
} else {
V_8 = - V_92 ;
}
F_53 ( & V_19 -> V_77 ) ;
if ( V_8 )
return V_8 ;
return snprintf ( V_27 , V_93 , L_10 , V_37 , V_38 , V_39 ) ;
}
static T_3 F_60 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
char * V_27 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
const char * V_94 ;
int V_45 ;
int V_95 ;
V_45 = V_19 -> V_96 ;
V_94 = L_11 ;
if ( V_45 >= 0 && V_45 < F_61 ( V_97 ) )
V_94 = V_97 [ V_45 ] ;
V_95 = snprintf ( V_27 , V_93 , L_12 , V_94 ) ;
return V_95 < V_93 - 1 ? V_95 : V_93 - 1 ;
}
static T_3 F_62 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
const char * V_27 , T_4 V_98 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_4 ;
int V_8 ;
for ( V_4 = 0 ; V_4 < F_61 ( V_97 ) ; V_4 ++ ) {
if ( F_63 ( V_97 [ V_4 ] , V_27 ) )
break;
}
if ( V_4 == F_61 ( V_97 ) )
return - V_99 ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_78 ) {
F_51 ( V_7 ) ;
if ( ! V_19 -> V_100 ) {
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_13;
V_8 = F_21 ( V_19 , V_101 , V_4 ) ;
if ( V_8 )
goto V_13;
}
F_52 ( V_7 ) ;
}
V_19 -> V_96 = V_4 ;
F_53 ( & V_19 -> V_77 ) ;
return V_98 ;
V_13:
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static T_3 F_64 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
char * V_27 )
{
int V_95 ;
int V_4 ;
for ( V_4 = 0 , V_95 = 0 ;
V_95 < V_93 && V_4 < F_61 ( V_97 ) ; V_4 ++ )
V_95 += snprintf ( & V_27 [ V_95 ] , V_93 - V_95 , L_13 ,
V_4 ? L_14 : L_15 , V_97 [ V_4 ] ,
V_4 == F_61 ( V_97 ) - 1 ? L_16 : L_15 ) ;
return V_95 < V_93 ? V_95 : V_93 - 1 ;
}
static T_3 F_65 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
const char * V_27 , T_4 V_98 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
unsigned long V_102 ;
int V_8 ;
V_8 = F_66 ( V_27 , 10 , & V_102 ) ;
if ( V_8 )
return V_8 ;
F_50 ( & V_19 -> V_77 ) ;
F_33 ( V_7 ) ;
V_19 -> V_60 = V_102 ;
if ( V_19 -> V_78 )
F_30 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_98 ;
}
static T_3 F_67 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
char * V_27 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
unsigned V_102 ;
F_50 ( & V_19 -> V_77 ) ;
V_102 = V_19 -> V_60 ;
F_53 ( & V_19 -> V_77 ) ;
return snprintf ( V_27 , V_93 , L_17 , V_102 ) ;
}
static T_3 F_68 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
const char * V_27 , T_4 V_98 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
unsigned long V_102 ;
int V_8 ;
V_8 = F_66 ( V_27 , 10 , & V_102 ) ;
if ( V_8 )
return V_8 ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_78 ) {
F_51 ( V_7 ) ;
if ( V_102 )
V_8 = F_37 ( V_7 ) ;
else
V_8 = F_47 ( V_7 ) ;
F_52 ( V_7 ) ;
}
F_53 ( & V_19 -> V_77 ) ;
if ( V_8 )
return V_8 ;
return V_98 ;
}
static T_3 F_69 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
char * V_27 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
unsigned V_102 ;
F_50 ( & V_19 -> V_77 ) ;
V_102 = V_19 -> V_66 ;
F_53 ( & V_19 -> V_77 ) ;
return snprintf ( V_27 , V_93 , L_17 , V_102 ) ;
}
static T_3 F_70 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
const char * V_27 , T_4 V_98 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
unsigned long V_102 ;
int V_8 ;
V_8 = F_66 ( V_27 , 10 , & V_102 ) ;
if ( V_8 )
return V_8 ;
F_50 ( & V_19 -> V_77 ) ;
V_19 -> V_63 = V_102 ;
if ( V_19 -> V_78 ) {
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
F_52 ( V_7 ) ;
}
F_53 ( & V_19 -> V_77 ) ;
if ( V_8 )
return V_8 ;
return V_98 ;
}
static T_3 F_71 ( struct V_87 * V_11 ,
struct V_88 * V_89 ,
char * V_27 )
{
struct V_6 * V_7 = F_58 ( V_11 ) ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
unsigned V_102 ;
F_50 ( & V_19 -> V_77 ) ;
V_102 = V_19 -> V_63 ;
F_53 ( & V_19 -> V_77 ) ;
return snprintf ( V_27 , V_93 , L_17 , V_102 ) ;
}
static void F_72 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
if ( V_65 -> V_103 == - 1 )
return;
F_73 ( V_65 -> V_103 , 1 ) ;
if ( V_19 -> V_32 -> V_104 . V_105 )
F_74 ( V_19 -> V_32 -> V_104 . V_105 ) ;
F_73 ( V_65 -> V_103 , 0 ) ;
if ( V_19 -> V_32 -> V_104 . V_106 )
F_74 ( V_19 -> V_32 -> V_104 . V_106 ) ;
F_73 ( V_65 -> V_103 , 1 ) ;
if ( V_19 -> V_32 -> V_33 . V_107 )
F_24 ( V_19 -> V_32 -> V_33 . V_107 ) ;
}
static int F_75 ( struct V_6 * V_7 )
{
struct V_108 V_72 ;
struct V_18 * V_19 ;
struct V_70 * V_109 = NULL ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
struct V_32 * V_32 = NULL ;
int V_8 , V_4 ;
F_49 ( & V_7 -> V_11 , L_18 ) ;
if ( ! V_65 || ! V_65 -> V_12 ) {
V_8 = - V_99 ;
goto V_13;
}
for ( V_4 = 0 ; V_4 < F_61 ( V_110 ) ; V_4 ++ ) {
if ( strcmp ( V_65 -> V_12 , V_110 [ V_4 ] . V_12 ) == 0 ) {
V_32 = & V_110 [ V_4 ] ;
break;
}
}
if ( ! V_32 ) {
V_8 = - V_99 ;
goto V_13;
}
V_7 -> V_82 . V_111 = V_112 ;
V_7 -> V_82 . V_81 = V_32 -> V_81 ;
V_7 -> V_82 . V_113 = V_114 ;
V_19 = F_76 ( sizeof( * V_19 ) , V_115 ) ;
if ( ! V_19 ) {
V_8 = - V_116 ;
goto V_13;
}
V_19 -> V_7 = V_7 ;
V_19 -> V_32 = V_32 ;
V_19 -> V_60 = V_65 -> V_60 ;
V_19 -> V_66 = false ;
V_19 -> V_63 = V_65 -> V_63 ;
F_77 ( & V_19 -> V_77 ) ;
F_78 ( & V_19 -> V_117 , 0 ) ;
V_8 = F_4 ( V_7 , V_32 -> V_2 ,
V_32 -> V_118 ) ;
if ( V_8 )
goto V_119;
V_19 -> V_61 = F_79 ( L_19 ) ;
if ( V_19 -> V_61 == NULL ) {
F_7 ( & V_7 -> V_11 , L_20 ) ;
V_8 = - V_116 ;
goto V_120;
}
F_80 ( & V_19 -> V_62 , V_121 ) ;
F_81 ( & V_19 -> V_64 , V_122 ) ;
F_82 ( & V_7 -> V_11 , V_19 ) ;
F_72 ( V_7 ) ;
if ( V_65 -> V_123 ) {
memset ( & V_72 , 0 , sizeof( struct V_108 ) ) ;
V_72 . V_124 = 255 ;
V_72 . type = V_125 ;
V_109 = F_83 ( F_84 ( & V_7 -> V_11 ) ,
& V_7 -> V_11 , V_7 , & V_126 , & V_72 ) ;
if ( F_6 ( V_109 ) ) {
V_8 = F_8 ( V_109 ) ;
goto V_127;
}
V_19 -> V_109 = V_109 ;
V_109 -> V_72 . V_73 = V_74 ;
V_109 -> V_72 . V_75 = V_74 ;
V_109 -> V_72 . V_76 = 255 ;
F_48 ( V_109 ) ;
}
if ( V_65 -> V_128 ) {
int V_129 = V_65 -> V_67 ;
V_8 = F_85 ( V_129 , L_21 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_22 ) ;
goto V_130;
}
F_86 ( V_129 ) ;
V_8 = F_87 ( F_40 ( V_129 ) , V_131 ,
V_132 ,
L_23 , V_7 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_24 ) ;
F_88 ( V_129 ) ;
goto V_133;
}
F_80 ( & V_19 -> V_134 ,
V_135 ) ;
F_49 ( & V_7 -> V_11 , L_25 ) ;
}
V_8 = F_89 ( V_7 , & V_19 -> V_28 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_26 ) ;
goto V_136;
}
V_8 = F_90 ( V_7 , V_19 -> V_28 , V_137 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_27 ) ;
goto V_138;
}
V_8 = F_91 ( & V_7 -> V_11 . V_139 , & V_140 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_28 ) ;
goto V_138;
}
return 0 ;
V_138:
F_92 ( V_7 , V_19 -> V_28 ) ;
V_136:
if ( V_65 -> V_128 )
F_93 ( F_40 ( V_65 -> V_67 ) , V_7 ) ;
V_133:
if ( V_65 -> V_128 )
F_88 ( V_65 -> V_67 ) ;
V_130:
if ( V_109 != NULL )
F_94 ( V_109 ) ;
V_127:
F_95 ( V_19 -> V_61 ) ;
V_120:
F_1 ( V_32 -> V_2 , V_32 -> V_118 ) ;
V_119:
F_96 ( V_19 ) ;
V_13:
return V_8 ;
}
static void T_5 F_97 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
struct V_70 * V_109 ;
F_49 ( & V_7 -> V_11 , L_29 ) ;
F_98 ( & V_7 -> V_11 . V_139 , & V_140 ) ;
F_92 ( V_7 , V_19 -> V_28 ) ;
if ( V_65 -> V_128 ) {
int V_129 = V_65 -> V_67 ;
F_93 ( F_40 ( V_129 ) , V_7 ) ;
F_88 ( V_129 ) ;
}
V_109 = V_19 -> V_109 ;
if ( V_109 != NULL ) {
V_109 -> V_72 . V_75 = V_141 ;
F_48 ( V_109 ) ;
F_94 ( V_109 ) ;
}
F_36 ( V_7 ) ;
F_33 ( V_7 ) ;
F_95 ( V_19 -> V_61 ) ;
F_72 ( V_7 ) ;
F_1 ( V_19 -> V_32 -> V_2 ,
V_19 -> V_32 -> V_118 ) ;
F_96 ( V_19 ) ;
}
static int F_99 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
T_1 V_37 , V_38 , V_39 ;
int V_8 ;
V_8 = F_44 ( V_7 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_5 ) ;
goto V_142;
}
F_72 ( V_7 ) ;
F_45 ( V_7 , V_19 -> V_28 , false ) ;
V_8 = F_25 ( V_19 ) ;
if ( V_8 )
goto V_13;
V_8 = F_26 ( V_19 , & V_37 , & V_38 , & V_39 ) ;
if ( V_8 )
goto V_13;
if ( V_19 -> V_32 -> type == V_143 &&
( V_38 == 0x00 || V_38 == 0xff || V_38 == 0x81 ) )
V_19 -> V_100 = true ;
V_8 = F_21 ( V_19 , V_79 , 0xff ) ;
if ( V_8 )
goto V_13;
V_8 = F_21 ( V_19 , V_144 ,
( 1 << 2 ) | ( 1 << 5 ) ) ;
if ( V_8 )
goto V_13;
V_8 = F_21 ( V_19 , V_145 ,
V_146 ) ;
if ( V_8 )
goto V_13;
V_8 = F_27 ( V_19 , V_19 -> V_43 , V_19 -> V_44 ) ;
if ( V_8 )
goto V_13;
if ( ! V_19 -> V_100 ) {
V_8 = F_21 ( V_19 , V_101 , V_19 -> V_96 ) ;
if ( V_8 )
goto V_13;
}
V_8 = F_19 ( V_19 , V_147 ) ;
if ( V_8 )
goto V_13;
V_8 = F_38 ( V_7 , V_19 -> V_148 ) ;
if ( V_8 )
goto V_13;
V_8 = F_100 ( V_7 , V_19 -> V_28 ) ;
if ( V_8 )
goto V_13;
V_19 -> V_78 = 1 ;
if ( ! V_19 -> V_149 ) {
F_101 ( & V_7 -> V_11 , L_30 ,
V_19 -> V_32 -> V_12 , V_37 , V_38 , V_39 ) ;
if ( V_19 -> V_100 )
F_101 ( & V_7 -> V_11 ,
L_31 ) ;
V_19 -> V_149 = true ;
}
F_45 ( V_7 , V_19 -> V_28 , true ) ;
return 0 ;
V_13:
F_7 ( & V_7 -> V_11 , L_32 ) ;
F_72 ( V_7 ) ;
F_41 ( V_7 , true , false ) ;
V_142:
return V_8 ;
}
static void F_102 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_103 ( V_7 , V_19 -> V_28 ) ;
V_8 = F_19 ( V_19 , V_150 ) ;
if ( ! V_8 )
V_8 = F_22 ( V_19 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 ,
L_33 ) ;
F_72 ( V_7 ) ;
}
F_41 ( V_7 , true , false ) ;
V_19 -> V_78 = 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
F_7 ( & V_7 -> V_11 , L_34 ) ;
F_102 ( V_7 ) ;
F_72 ( V_7 ) ;
return F_99 ( V_7 ) ;
}
static int F_104 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_49 ( & V_7 -> V_11 , L_35 ) ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_7 -> V_151 != V_152 ) {
V_8 = - V_99 ;
goto V_13;
}
F_51 ( V_7 ) ;
V_8 = F_99 ( V_7 ) ;
F_52 ( V_7 ) ;
if ( V_8 )
goto V_13;
F_30 ( V_7 ) ;
V_7 -> V_151 = V_153 ;
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_13:
F_49 ( & V_7 -> V_11 , L_36 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static void F_105 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
F_49 ( & V_7 -> V_11 , L_37 ) ;
F_50 ( & V_19 -> V_77 ) ;
F_36 ( V_7 ) ;
F_33 ( V_7 ) ;
F_51 ( V_7 ) ;
if ( V_7 -> V_151 == V_153 ) {
int V_8 ;
V_8 = F_47 ( V_7 ) ;
if ( ! V_8 )
F_102 ( V_7 ) ;
}
F_52 ( V_7 ) ;
V_7 -> V_151 = V_152 ;
F_53 ( & V_19 -> V_77 ) ;
}
static int F_106 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_49 ( & V_7 -> V_11 , L_38 ) ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_7 -> V_151 != V_153 ) {
V_8 = - V_99 ;
goto V_13;
}
F_36 ( V_7 ) ;
F_33 ( V_7 ) ;
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( ! V_8 )
F_102 ( V_7 ) ;
F_52 ( V_7 ) ;
V_7 -> V_151 = V_154 ;
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_13:
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_107 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_49 ( & V_7 -> V_11 , L_39 ) ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_7 -> V_151 != V_154 ) {
V_8 = - V_99 ;
goto V_13;
}
F_51 ( V_7 ) ;
V_8 = F_99 ( V_7 ) ;
F_52 ( V_7 ) ;
if ( V_8 ) {
V_7 -> V_151 = V_152 ;
} else {
V_7 -> V_151 = V_153 ;
F_30 ( V_7 ) ;
}
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
V_13:
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static void F_108 ( int V_13 , void * V_17 )
{
struct V_6 * V_7 = V_17 ;
F_49 ( & V_7 -> V_11 , L_40 , V_13 ) ;
F_52 ( V_7 ) ;
}
static T_6 V_131 ( int V_155 , void * V_17 )
{
struct V_6 * V_7 = V_17 ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_156 ;
int V_8 ;
V_156 = F_109 ( & V_19 -> V_117 , 1 , 0 ) ;
if ( V_156 ) {
F_34 ( & V_19 -> V_134 ) ;
V_8 = F_110 ( V_7 , V_19 -> V_28 , F_108 ,
V_7 ) ;
if ( V_8 )
goto V_13;
}
return V_157 ;
V_13:
F_7 ( & V_7 -> V_11 , L_41 ) ;
F_52 ( V_7 ) ;
return V_157 ;
}
static void V_135 ( struct V_158 * V_159 )
{
struct V_18 * V_19 = F_111 ( V_159 , struct V_18 ,
V_134 . V_159 ) ;
struct V_6 * V_7 = V_19 -> V_7 ;
F_7 ( & V_7 -> V_11 , L_42 ) ;
F_78 ( & V_19 -> V_117 , 0 ) ;
F_52 ( V_7 ) ;
}
static int F_112 ( struct V_6 * V_7 ,
T_2 V_51 , T_2 V_52 , T_2 V_53 , T_2 V_54 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
int V_8 ;
F_49 ( & V_7 -> V_11 , L_43 , V_51 , V_52 , V_53 , V_54 ) ;
F_50 ( & V_19 -> V_77 ) ;
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_13;
if ( ! V_19 -> V_78 ) {
V_8 = 0 ;
goto V_13;
}
V_8 = F_28 ( V_19 , 0 , 0 ,
V_19 -> V_32 -> V_81 . V_85 ,
V_19 -> V_32 -> V_81 . V_86 ) ;
if ( V_8 )
goto V_13;
if ( V_19 -> V_148 && V_65 -> V_128 ) {
F_113 ( & V_19 -> V_134 ,
F_14 ( 250 ) ) ;
F_78 ( & V_19 -> V_117 , 1 ) ;
} else {
V_8 = F_110 ( V_7 , V_19 -> V_28 , F_108 ,
V_7 ) ;
if ( V_8 )
goto V_13;
}
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_13:
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_114 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
F_49 ( & V_7 -> V_11 , L_44 ) ;
F_50 ( & V_19 -> V_77 ) ;
F_51 ( V_7 ) ;
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
F_49 ( & V_7 -> V_11 , L_45 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , bool V_160 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
int V_8 ;
if ( V_160 )
V_8 = F_21 ( V_19 , V_161 , 0 ) ;
else
V_8 = F_19 ( V_19 , V_162 ) ;
if ( ! V_65 -> V_128 )
F_115 ( V_7 , V_160 ) ;
if ( V_19 -> V_32 -> V_33 . V_163 )
F_24 ( V_19 -> V_32 -> V_33 . V_163 ) ;
return V_8 ;
}
static int F_116 ( struct V_6 * V_7 , bool V_160 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_148 == V_160 )
goto V_164;
F_51 ( V_7 ) ;
if ( V_19 -> V_78 ) {
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_13;
V_8 = F_38 ( V_7 , V_160 ) ;
if ( V_8 )
goto V_13;
}
V_19 -> V_148 = V_160 ;
F_52 ( V_7 ) ;
V_164:
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_13:
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_117 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
V_8 = V_19 -> V_148 ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_118 ( struct V_6 * V_7 , T_1 V_43 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_49 ( & V_7 -> V_11 , L_46 , V_43 ) ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_43 == V_43 )
goto V_164;
F_51 ( V_7 ) ;
if ( V_19 -> V_78 ) {
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_13;
V_8 = F_27 ( V_19 , V_43 , V_19 -> V_44 ) ;
if ( V_8 )
goto V_13;
}
V_19 -> V_43 = V_43 ;
F_52 ( V_7 ) ;
V_164:
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_13:
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static T_1 F_119 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
V_8 = V_19 -> V_43 ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_120 ( struct V_6 * V_7 , bool V_160 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_49 ( & V_7 -> V_11 , L_47 , V_160 ) ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_19 -> V_44 == V_160 )
goto V_164;
F_51 ( V_7 ) ;
if ( V_19 -> V_78 ) {
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_13;
V_8 = F_27 ( V_19 , V_19 -> V_43 , V_160 ) ;
if ( V_8 )
goto V_13;
}
V_19 -> V_44 = V_160 ;
F_52 ( V_7 ) ;
V_164:
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_13:
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static bool F_121 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
V_8 = V_19 -> V_44 ;
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_122 ( struct V_6 * V_7 , int V_165 )
{
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
T_1 V_37 , V_38 , V_39 ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
if ( ! V_19 -> V_78 ) {
V_8 = - V_92 ;
goto V_68;
}
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_69;
V_8 = F_17 ( V_19 , V_40 , & V_37 ) ;
if ( V_8 )
goto V_69;
V_8 = F_17 ( V_19 , V_41 , & V_38 ) ;
if ( V_8 )
goto V_69;
V_8 = F_17 ( V_19 , V_42 , & V_39 ) ;
if ( V_8 )
goto V_69;
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return 0 ;
V_69:
F_52 ( V_7 ) ;
V_68:
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static int F_123 ( struct V_6 * V_7 ,
void * V_27 , T_4 V_166 ,
T_2 V_51 , T_2 V_52 , T_2 V_53 , T_2 V_54 )
{
int V_8 ;
int V_167 = 1 ;
int V_168 ;
unsigned V_169 = 0 ;
struct V_18 * V_19 = F_31 ( & V_7 -> V_11 ) ;
if ( V_166 < V_53 * V_54 * 3 )
return - V_116 ;
F_50 ( & V_19 -> V_77 ) ;
if ( ! V_19 -> V_78 ) {
V_8 = - V_92 ;
goto V_68;
}
V_166 = F_124 ( V_53 * V_54 * 3 ,
V_7 -> V_82 . V_81 . V_85 *
V_7 -> V_82 . V_81 . V_86 * 3 ) ;
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( V_8 )
goto V_69;
if ( V_166 % 2 )
V_168 = 1 ;
else
V_168 = 2 ;
F_28 ( V_19 , V_51 , V_52 , V_53 , V_54 ) ;
V_8 = F_125 ( V_7 , V_19 -> V_28 , V_168 ) ;
if ( V_8 )
goto V_69;
while ( V_169 < V_166 ) {
T_1 V_26 = V_167 ? 0x2e : 0x3e ;
V_167 = 0 ;
V_8 = F_18 ( V_7 , V_19 -> V_28 , V_26 ,
V_27 + V_169 , V_166 - V_169 ) ;
if ( V_8 < 0 ) {
F_7 ( & V_7 -> V_11 , L_48 ) ;
goto V_170;
}
V_169 += V_8 ;
if ( V_8 < V_168 ) {
F_7 ( & V_7 -> V_11 , L_49 ) ;
break;
}
if ( F_126 ( V_171 ) ) {
F_7 ( & V_7 -> V_11 , L_50
L_51 ) ;
V_8 = - V_172 ;
goto V_170;
}
}
V_8 = V_169 ;
V_170:
F_125 ( V_7 , V_19 -> V_28 , 1 ) ;
V_69:
F_52 ( V_7 ) ;
V_68:
F_53 ( & V_19 -> V_77 ) ;
return V_8 ;
}
static void V_122 ( struct V_158 * V_159 )
{
struct V_18 * V_19 = F_111 ( V_159 , struct V_18 ,
V_64 . V_159 ) ;
struct V_6 * V_7 = V_19 -> V_7 ;
F_50 ( & V_19 -> V_77 ) ;
if ( V_7 -> V_151 != V_153 || ! V_19 -> V_78 ) {
F_53 ( & V_19 -> V_77 ) ;
return;
}
F_51 ( V_7 ) ;
F_37 ( V_7 ) ;
F_52 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
}
static void V_121 ( struct V_158 * V_159 )
{
struct V_18 * V_19 = F_111 ( V_159 , struct V_18 ,
V_62 . V_159 ) ;
struct V_6 * V_7 = V_19 -> V_7 ;
struct V_16 * V_65 = F_12 ( V_7 ) ;
T_1 V_173 , V_174 ;
int V_8 ;
F_50 ( & V_19 -> V_77 ) ;
if ( ! V_19 -> V_78 ) {
F_53 ( & V_19 -> V_77 ) ;
return;
}
F_51 ( V_7 ) ;
V_8 = F_47 ( V_7 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_52 ) ;
goto V_13;
}
V_8 = F_17 ( V_19 , V_175 , & V_173 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_53 ) ;
goto V_13;
}
V_8 = F_25 ( V_19 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_54 ) ;
goto V_13;
}
V_8 = F_17 ( V_19 , V_175 , & V_174 ) ;
if ( V_8 ) {
F_7 ( & V_7 -> V_11 , L_53 ) ;
goto V_13;
}
if ( ! ( ( V_173 ^ V_174 ) & ( 1 << 6 ) ) ) {
F_7 ( & V_7 -> V_11 , L_55 ) ;
goto V_13;
}
if ( V_19 -> V_148 && V_65 -> V_128 ) {
V_8 = F_21 ( V_19 , V_161 , 0 ) ;
if ( V_8 )
goto V_13;
}
F_52 ( V_7 ) ;
F_30 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
return;
V_13:
F_7 ( & V_7 -> V_11 , L_34 ) ;
F_42 ( V_7 ) ;
F_52 ( V_7 ) ;
F_30 ( V_7 ) ;
F_53 ( & V_19 -> V_77 ) ;
}
static int T_7 F_127 ( void )
{
F_128 ( & V_176 ) ;
return 0 ;
}
static void T_5 F_129 ( void )
{
F_130 ( & V_176 ) ;
}
