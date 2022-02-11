static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , int V_7 )
{
V_6 -> V_8 = F_3 ( V_7 ) ;
V_6 -> V_9 = V_10 + V_6 -> V_8 ;
}
static void V_8 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_6 -> V_9 - V_10 ;
if ( ( long ) V_11 > 0 && V_11 <= V_6 -> V_8 ) {
F_4 ( V_12 ) ;
F_5 ( V_11 ) ;
}
}
static int F_6 ( struct V_5 * V_6 , T_1 V_13 , T_1 * V_4 )
{
int V_14 ;
T_1 V_15 [ 1 ] ;
V_14 = F_7 ( V_6 -> V_3 , V_6 -> V_16 , V_13 , V_15 , 1 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_4 = V_15 [ 0 ] ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , T_1 V_13 )
{
return F_9 ( V_6 -> V_3 , V_6 -> V_16 , & V_13 , 1 ) ;
}
static int F_10 ( struct V_5 * V_6 , T_1 V_13 , T_1 V_17 )
{
T_1 V_15 [ 2 ] ;
V_15 [ 0 ] = V_13 ;
V_15 [ 1 ] = V_17 ;
return F_9 ( V_6 -> V_3 , V_6 -> V_16 , V_15 , 2 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
T_1 V_18 ;
int V_14 ;
V_8 ( V_6 ) ;
V_18 = V_19 ;
V_14 = F_12 ( V_6 -> V_3 , V_6 -> V_16 , & V_18 , 1 ) ;
if ( V_14 )
return V_14 ;
F_2 ( V_6 , 120 ) ;
if ( V_6 -> V_20 -> V_21 . V_22 )
F_13 ( V_6 -> V_20 -> V_21 . V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
int V_14 ;
V_8 ( V_6 ) ;
V_14 = F_8 ( V_6 , V_23 ) ;
if ( V_14 )
return V_14 ;
F_2 ( V_6 , 120 ) ;
if ( V_6 -> V_20 -> V_21 . V_24 )
F_13 ( V_6 -> V_20 -> V_21 . V_24 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , T_1 * V_25 , T_1 * V_26 , T_1 * V_27 )
{
int V_14 ;
V_14 = F_6 ( V_6 , V_28 , V_25 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_6 ( V_6 , V_29 , V_26 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_6 ( V_6 , V_30 , V_27 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , T_1 V_31 , bool V_32 )
{
int V_14 ;
T_1 V_33 ;
int V_34 , V_35 , V_36 ;
V_14 = F_6 ( V_6 , V_37 , & V_33 ) ;
if ( V_14 )
return V_14 ;
switch ( V_31 ) {
default:
case 0 :
V_36 = 0 ;
V_35 = 0 ;
V_34 = 0 ;
break;
case 1 :
V_36 = 0 ;
V_35 = 1 ;
V_34 = 1 ;
break;
case 2 :
V_36 = 1 ;
V_35 = 1 ;
V_34 = 0 ;
break;
case 3 :
V_36 = 1 ;
V_35 = 0 ;
V_34 = 1 ;
break;
}
if ( V_32 )
V_35 = ! V_35 ;
V_33 &= ~ ( ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ) ;
V_33 |= ( V_36 << 7 ) | ( V_35 << 6 ) | ( V_34 << 5 ) ;
return F_10 ( V_6 , V_38 , V_33 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
T_2 V_39 , T_2 V_40 , T_2 V_41 , T_2 V_42 )
{
int V_14 ;
T_2 V_43 = V_39 ;
T_2 V_44 = V_39 + V_41 - 1 ;
T_2 y1 = V_40 ;
T_2 V_45 = V_40 + V_42 - 1 ;
T_1 V_15 [ 5 ] ;
V_15 [ 0 ] = V_46 ;
V_15 [ 1 ] = ( V_43 >> 8 ) & 0xff ;
V_15 [ 2 ] = ( V_43 >> 0 ) & 0xff ;
V_15 [ 3 ] = ( V_44 >> 8 ) & 0xff ;
V_15 [ 4 ] = ( V_44 >> 0 ) & 0xff ;
V_14 = F_12 ( V_6 -> V_3 , V_6 -> V_16 , V_15 , sizeof( V_15 ) ) ;
if ( V_14 )
return V_14 ;
V_15 [ 0 ] = V_47 ;
V_15 [ 1 ] = ( y1 >> 8 ) & 0xff ;
V_15 [ 2 ] = ( y1 >> 0 ) & 0xff ;
V_15 [ 3 ] = ( V_45 >> 8 ) & 0xff ;
V_15 [ 4 ] = ( V_45 >> 0 ) & 0xff ;
V_14 = F_12 ( V_6 -> V_3 , V_6 -> V_16 , V_15 , sizeof( V_15 ) ) ;
if ( V_14 )
return V_14 ;
F_18 ( V_6 -> V_3 , V_6 -> V_16 ) ;
return V_14 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
if ( V_6 -> V_49 > 0 )
F_21 ( V_6 -> V_50 , & V_6 -> V_51 ,
F_3 ( V_6 -> V_49 ) ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
F_23 ( & V_6 -> V_51 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
if ( V_6 -> V_52 > 0 )
F_21 ( V_6 -> V_50 , & V_6 -> V_53 ,
F_3 ( V_6 -> V_52 ) ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
F_23 ( & V_6 -> V_53 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
int V_14 ;
if ( V_6 -> V_55 )
return 0 ;
F_25 ( V_3 ) ;
V_14 = F_27 ( V_3 , false ) ;
if ( V_14 )
goto V_56;
F_28 ( F_29 ( V_54 -> V_57 ) ) ;
F_30 ( V_3 , false , true ) ;
V_6 -> V_55 = true ;
return 0 ;
V_56:
F_31 ( & V_3 -> V_48 , L_1 ) ;
F_32 ( V_3 ) ;
V_6 -> V_55 = false ;
F_24 ( V_3 ) ;
return V_14 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
int V_14 ;
if ( ! V_6 -> V_55 )
return 0 ;
V_14 = F_34 ( V_3 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_2 ) ;
goto V_58;
}
F_35 ( V_3 , V_6 -> V_16 , true ) ;
V_14 = F_27 ( V_3 , true ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_3 ) ;
goto V_59;
}
F_36 ( F_29 ( V_54 -> V_57 ) ) ;
F_24 ( V_3 ) ;
V_6 -> V_55 = false ;
return 0 ;
V_59:
F_31 ( & V_3 -> V_48 , L_4 ) ;
V_14 = F_32 ( V_3 ) ;
if ( ! V_14 ) {
F_36 ( F_29 ( V_54 -> V_57 ) ) ;
V_6 -> V_55 = false ;
}
V_58:
F_24 ( V_3 ) ;
return V_14 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
if ( V_6 -> V_55 )
return F_33 ( V_3 ) ;
F_25 ( V_3 ) ;
F_24 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_60 * V_48 )
{
struct V_2 * V_3 = F_20 ( & V_48 -> V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
int V_61 ;
if ( V_48 -> V_62 . V_63 == V_64 &&
V_48 -> V_62 . V_65 == V_64 )
V_61 = V_48 -> V_62 . V_66 ;
else
V_61 = 0 ;
F_39 ( & V_3 -> V_48 , L_5 , V_61 ) ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_68 ) {
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( ! V_14 )
V_14 = F_10 ( V_6 , V_69 , V_61 ) ;
F_42 ( V_3 ) ;
} else {
V_14 = 0 ;
}
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_44 ( struct V_60 * V_48 )
{
if ( V_48 -> V_62 . V_63 == V_64 &&
V_48 -> V_62 . V_65 == V_64 )
return V_48 -> V_62 . V_66 ;
return 0 ;
}
static void F_45 ( struct V_2 * V_3 ,
T_2 * V_70 , T_2 * V_71 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
if ( V_6 -> V_31 == 0 || V_6 -> V_31 == 2 ) {
* V_70 = V_3 -> V_72 . V_73 . V_74 ;
* V_71 = V_3 -> V_72 . V_73 . V_75 ;
} else {
* V_71 = V_3 -> V_72 . V_73 . V_74 ;
* V_70 = V_3 -> V_72 . V_73 . V_75 ;
}
}
static T_3 F_46 ( struct V_76 * V_48 ,
struct V_77 * V_78 , char * V_15 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
T_1 V_79 = 0 ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_68 ) {
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( ! V_14 )
V_14 = F_6 ( V_6 , V_80 , & V_79 ) ;
F_42 ( V_3 ) ;
} else {
V_14 = - V_81 ;
}
F_43 ( & V_6 -> V_67 ) ;
if ( V_14 )
return V_14 ;
return snprintf ( V_15 , V_82 , L_6 , V_79 ) ;
}
static T_3 F_48 ( struct V_76 * V_48 ,
struct V_77 * V_78 , char * V_15 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
T_1 V_25 , V_26 , V_27 ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_68 ) {
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( ! V_14 )
V_14 = F_15 ( V_6 , & V_25 , & V_26 , & V_27 ) ;
F_42 ( V_3 ) ;
} else {
V_14 = - V_81 ;
}
F_43 ( & V_6 -> V_67 ) ;
if ( V_14 )
return V_14 ;
return snprintf ( V_15 , V_82 , L_7 , V_25 , V_26 , V_27 ) ;
}
static T_3 F_49 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
char * V_15 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
const char * V_83 ;
int V_33 ;
int V_84 ;
V_33 = V_6 -> V_85 ;
V_83 = L_8 ;
if ( V_33 >= 0 && V_33 < F_50 ( V_86 ) )
V_83 = V_86 [ V_33 ] ;
V_84 = snprintf ( V_15 , V_82 , L_9 , V_83 ) ;
return V_84 < V_82 - 1 ? V_84 : V_82 - 1 ;
}
static T_3 F_51 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
const char * V_15 , T_4 V_87 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_88 ;
int V_14 ;
for ( V_88 = 0 ; V_88 < F_50 ( V_86 ) ; V_88 ++ ) {
if ( F_52 ( V_86 [ V_88 ] , V_15 ) )
break;
}
if ( V_88 == F_50 ( V_86 ) )
return - V_89 ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_68 ) {
F_41 ( V_3 ) ;
if ( ! V_6 -> V_90 ) {
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_56;
V_14 = F_10 ( V_6 , V_91 , V_88 ) ;
if ( V_14 )
goto V_56;
}
F_42 ( V_3 ) ;
}
V_6 -> V_85 = V_88 ;
F_43 ( & V_6 -> V_67 ) ;
return V_87 ;
V_56:
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static T_3 F_53 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
char * V_15 )
{
int V_84 ;
int V_88 ;
for ( V_88 = 0 , V_84 = 0 ;
V_84 < V_82 && V_88 < F_50 ( V_86 ) ; V_88 ++ )
V_84 += snprintf ( & V_15 [ V_84 ] , V_82 - V_84 , L_10 ,
V_88 ? L_11 : L_12 , V_86 [ V_88 ] ,
V_88 == F_50 ( V_86 ) - 1 ? L_13 : L_12 ) ;
return V_84 < V_82 ? V_84 : V_82 - 1 ;
}
static T_3 F_54 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
const char * V_15 , T_4 V_87 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
unsigned long V_92 ;
int V_14 ;
V_14 = F_55 ( V_15 , 10 , & V_92 ) ;
if ( V_14 )
return V_14 ;
F_40 ( & V_6 -> V_67 ) ;
F_22 ( V_3 ) ;
V_6 -> V_49 = V_92 ;
if ( V_6 -> V_68 )
F_19 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_87 ;
}
static T_3 F_56 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
char * V_15 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
unsigned V_92 ;
F_40 ( & V_6 -> V_67 ) ;
V_92 = V_6 -> V_49 ;
F_43 ( & V_6 -> V_67 ) ;
return snprintf ( V_15 , V_82 , L_14 , V_92 ) ;
}
static T_3 F_57 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
const char * V_15 , T_4 V_87 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
unsigned long V_92 ;
int V_14 ;
V_14 = F_55 ( V_15 , 10 , & V_92 ) ;
if ( V_14 )
return V_14 ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_68 ) {
F_41 ( V_3 ) ;
if ( V_92 )
V_14 = F_26 ( V_3 ) ;
else
V_14 = F_37 ( V_3 ) ;
F_42 ( V_3 ) ;
}
F_43 ( & V_6 -> V_67 ) ;
if ( V_14 )
return V_14 ;
return V_87 ;
}
static T_3 F_58 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
char * V_15 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
unsigned V_92 ;
F_40 ( & V_6 -> V_67 ) ;
V_92 = V_6 -> V_55 ;
F_43 ( & V_6 -> V_67 ) ;
return snprintf ( V_15 , V_82 , L_14 , V_92 ) ;
}
static T_3 F_59 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
const char * V_15 , T_4 V_87 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
unsigned long V_92 ;
int V_14 ;
V_14 = F_55 ( V_15 , 10 , & V_92 ) ;
if ( V_14 )
return V_14 ;
F_40 ( & V_6 -> V_67 ) ;
V_6 -> V_52 = V_92 ;
if ( V_6 -> V_68 ) {
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
F_42 ( V_3 ) ;
}
F_43 ( & V_6 -> V_67 ) ;
if ( V_14 )
return V_14 ;
return V_87 ;
}
static T_3 F_60 ( struct V_76 * V_48 ,
struct V_77 * V_78 ,
char * V_15 )
{
struct V_2 * V_3 = F_47 ( V_48 ) ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
unsigned V_92 ;
F_40 ( & V_6 -> V_67 ) ;
V_92 = V_6 -> V_52 ;
F_43 ( & V_6 -> V_67 ) ;
return snprintf ( V_15 , V_82 , L_14 , V_92 ) ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
if ( V_54 -> V_93 == - 1 )
return;
F_62 ( V_54 -> V_93 , 1 ) ;
if ( V_6 -> V_20 -> V_94 . V_95 )
F_63 ( V_6 -> V_20 -> V_94 . V_95 ) ;
F_62 ( V_54 -> V_93 , 0 ) ;
if ( V_6 -> V_20 -> V_94 . V_96 )
F_63 ( V_6 -> V_20 -> V_94 . V_96 ) ;
F_62 ( V_54 -> V_93 , 1 ) ;
if ( V_6 -> V_20 -> V_21 . V_97 )
F_13 ( V_6 -> V_20 -> V_21 . V_97 ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_98 V_62 ;
struct V_5 * V_6 ;
struct V_60 * V_99 = NULL ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
struct V_20 * V_20 = NULL ;
int V_14 , V_88 ;
F_39 ( & V_3 -> V_48 , L_15 ) ;
if ( ! V_54 || ! V_54 -> V_100 ) {
V_14 = - V_89 ;
goto V_56;
}
for ( V_88 = 0 ; V_88 < F_50 ( V_101 ) ; V_88 ++ ) {
if ( strcmp ( V_54 -> V_100 , V_101 [ V_88 ] . V_100 ) == 0 ) {
V_20 = & V_101 [ V_88 ] ;
break;
}
}
if ( ! V_20 ) {
V_14 = - V_89 ;
goto V_56;
}
V_3 -> V_72 . V_73 = V_20 -> V_73 ;
V_3 -> V_72 . V_102 = V_103 ;
V_6 = F_65 ( sizeof( * V_6 ) , V_104 ) ;
if ( ! V_6 ) {
V_14 = - V_105 ;
goto V_56;
}
V_6 -> V_3 = V_3 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_49 = V_54 -> V_49 ;
V_6 -> V_55 = false ;
V_6 -> V_52 = V_54 -> V_52 ;
F_66 ( & V_6 -> V_67 ) ;
F_67 ( & V_6 -> V_106 , 0 ) ;
V_6 -> V_50 = F_68 ( L_16 ) ;
if ( V_6 -> V_50 == NULL ) {
F_31 ( & V_3 -> V_48 , L_17 ) ;
V_14 = - V_105 ;
goto V_107;
}
F_69 ( & V_6 -> V_51 , V_108 ) ;
F_70 ( & V_6 -> V_53 , V_109 ) ;
F_71 ( & V_3 -> V_48 , V_6 ) ;
if ( F_72 ( V_54 -> V_93 ) ) {
V_14 = F_73 ( V_54 -> V_93 , V_110 ,
L_18 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_19 ) ;
goto V_111;
}
}
F_61 ( V_3 ) ;
if ( V_54 -> V_112 ) {
memset ( & V_62 , 0 , sizeof( struct V_98 ) ) ;
V_62 . V_113 = 255 ;
V_62 . type = V_114 ;
V_99 = F_74 ( F_75 ( & V_3 -> V_48 ) ,
& V_3 -> V_48 , V_3 , & V_115 , & V_62 ) ;
if ( F_76 ( V_99 ) ) {
V_14 = F_77 ( V_99 ) ;
goto V_116;
}
V_6 -> V_99 = V_99 ;
V_99 -> V_62 . V_63 = V_64 ;
V_99 -> V_62 . V_65 = V_64 ;
V_99 -> V_62 . V_66 = 255 ;
F_38 ( V_99 ) ;
}
if ( V_54 -> V_117 ) {
int V_118 = V_54 -> V_57 ;
V_14 = F_73 ( V_118 , V_119 , L_20 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_21 ) ;
goto V_120;
}
V_14 = F_78 ( F_29 ( V_118 ) , V_121 ,
V_122 ,
L_22 , V_3 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_23 ) ;
F_79 ( V_118 ) ;
goto V_123;
}
F_69 ( & V_6 -> V_124 ,
V_125 ) ;
F_39 ( & V_3 -> V_48 , L_24 ) ;
}
V_14 = F_80 ( V_3 , & V_6 -> V_16 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_25 ) ;
goto V_126;
}
V_14 = F_81 ( V_3 , V_6 -> V_16 , V_127 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_26 ) ;
goto V_128;
}
V_14 = F_82 ( & V_3 -> V_48 . V_129 , & V_130 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_27 ) ;
goto V_128;
}
return 0 ;
V_128:
F_83 ( V_3 , V_6 -> V_16 ) ;
V_126:
if ( V_54 -> V_117 )
F_84 ( F_29 ( V_54 -> V_57 ) , V_3 ) ;
V_123:
if ( V_54 -> V_117 )
F_79 ( V_54 -> V_57 ) ;
V_120:
if ( V_99 != NULL )
F_85 ( V_99 ) ;
V_116:
if ( F_72 ( V_54 -> V_93 ) )
F_79 ( V_54 -> V_93 ) ;
V_111:
F_86 ( V_6 -> V_50 ) ;
V_107:
F_87 ( V_6 ) ;
V_56:
return V_14 ;
}
static void T_5 F_88 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
struct V_60 * V_99 ;
F_39 ( & V_3 -> V_48 , L_28 ) ;
F_89 ( & V_3 -> V_48 . V_129 , & V_130 ) ;
F_83 ( V_3 , V_6 -> V_16 ) ;
if ( V_54 -> V_117 ) {
int V_118 = V_54 -> V_57 ;
F_84 ( F_29 ( V_118 ) , V_3 ) ;
F_79 ( V_118 ) ;
}
V_99 = V_6 -> V_99 ;
if ( V_99 != NULL ) {
V_99 -> V_62 . V_65 = V_131 ;
F_38 ( V_99 ) ;
F_85 ( V_99 ) ;
}
F_25 ( V_3 ) ;
F_22 ( V_3 ) ;
F_86 ( V_6 -> V_50 ) ;
F_61 ( V_3 ) ;
if ( F_72 ( V_54 -> V_93 ) )
F_79 ( V_54 -> V_93 ) ;
F_87 ( V_6 ) ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
T_1 V_25 , V_26 , V_27 ;
int V_14 ;
V_14 = F_91 ( V_3 , & V_54 -> V_132 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_29 ) ;
goto V_133;
} ;
V_14 = F_34 ( V_3 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_2 ) ;
goto V_133;
}
F_61 ( V_3 ) ;
F_35 ( V_3 , V_6 -> V_16 , false ) ;
V_14 = F_14 ( V_6 ) ;
if ( V_14 )
goto V_56;
V_14 = F_15 ( V_6 , & V_25 , & V_26 , & V_27 ) ;
if ( V_14 )
goto V_56;
if ( V_6 -> V_20 -> type == V_134 &&
( V_26 == 0x00 || V_26 == 0xff || V_26 == 0x81 ) )
V_6 -> V_90 = true ;
V_14 = F_10 ( V_6 , V_69 , 0xff ) ;
if ( V_14 )
goto V_56;
V_14 = F_10 ( V_6 , V_135 ,
( 1 << 2 ) | ( 1 << 5 ) ) ;
if ( V_14 )
goto V_56;
V_14 = F_10 ( V_6 , V_136 ,
V_137 ) ;
if ( V_14 )
goto V_56;
V_14 = F_16 ( V_6 , V_6 -> V_31 , V_6 -> V_32 ) ;
if ( V_14 )
goto V_56;
if ( ! V_6 -> V_90 ) {
V_14 = F_10 ( V_6 , V_91 , V_6 -> V_85 ) ;
if ( V_14 )
goto V_56;
}
V_14 = F_8 ( V_6 , V_138 ) ;
if ( V_14 )
goto V_56;
V_14 = F_27 ( V_3 , V_6 -> V_139 ) ;
if ( V_14 )
goto V_56;
V_14 = F_92 ( V_3 , V_6 -> V_16 ) ;
if ( V_14 )
goto V_56;
V_6 -> V_68 = 1 ;
if ( ! V_6 -> V_140 ) {
F_93 ( & V_3 -> V_48 , L_30 ,
V_6 -> V_20 -> V_100 , V_25 , V_26 , V_27 ) ;
if ( V_6 -> V_90 )
F_93 ( & V_3 -> V_48 ,
L_31 ) ;
V_6 -> V_140 = true ;
}
F_35 ( V_3 , V_6 -> V_16 , true ) ;
return 0 ;
V_56:
F_31 ( & V_3 -> V_48 , L_32 ) ;
F_61 ( V_3 ) ;
F_30 ( V_3 , true , false ) ;
V_133:
return V_14 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_95 ( V_3 , V_6 -> V_16 ) ;
V_14 = F_8 ( V_6 , V_141 ) ;
if ( ! V_14 )
V_14 = F_11 ( V_6 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 ,
L_33 ) ;
F_61 ( V_3 ) ;
}
F_30 ( V_3 , true , false ) ;
V_6 -> V_68 = 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
F_31 ( & V_3 -> V_48 , L_34 ) ;
F_94 ( V_3 ) ;
F_61 ( V_3 ) ;
return F_90 ( V_3 ) ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_39 ( & V_3 -> V_48 , L_35 ) ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_3 -> V_142 != V_143 ) {
V_14 = - V_89 ;
goto V_56;
}
F_41 ( V_3 ) ;
V_14 = F_90 ( V_3 ) ;
F_42 ( V_3 ) ;
if ( V_14 )
goto V_56;
F_19 ( V_3 ) ;
V_3 -> V_142 = V_144 ;
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_56:
F_39 ( & V_3 -> V_48 , L_36 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
F_39 ( & V_3 -> V_48 , L_37 ) ;
F_40 ( & V_6 -> V_67 ) ;
F_25 ( V_3 ) ;
F_22 ( V_3 ) ;
F_41 ( V_3 ) ;
if ( V_3 -> V_142 == V_144 ) {
int V_14 ;
V_14 = F_37 ( V_3 ) ;
if ( ! V_14 )
F_94 ( V_3 ) ;
}
F_42 ( V_3 ) ;
V_3 -> V_142 = V_143 ;
F_43 ( & V_6 -> V_67 ) ;
}
static int F_98 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_39 ( & V_3 -> V_48 , L_38 ) ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_3 -> V_142 != V_144 ) {
V_14 = - V_89 ;
goto V_56;
}
F_25 ( V_3 ) ;
F_22 ( V_3 ) ;
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( ! V_14 )
F_94 ( V_3 ) ;
F_42 ( V_3 ) ;
V_3 -> V_142 = V_145 ;
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_56:
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_39 ( & V_3 -> V_48 , L_39 ) ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_3 -> V_142 != V_145 ) {
V_14 = - V_89 ;
goto V_56;
}
F_41 ( V_3 ) ;
V_14 = F_90 ( V_3 ) ;
F_42 ( V_3 ) ;
if ( V_14 ) {
V_3 -> V_142 = V_143 ;
} else {
V_3 -> V_142 = V_144 ;
F_19 ( V_3 ) ;
}
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
V_56:
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static void F_100 ( int V_56 , void * V_4 )
{
struct V_2 * V_3 = V_4 ;
F_39 ( & V_3 -> V_48 , L_40 , V_56 ) ;
F_42 ( V_3 ) ;
}
static T_6 V_121 ( int V_146 , void * V_4 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_147 ;
int V_14 ;
V_147 = F_101 ( & V_6 -> V_106 , 1 , 0 ) ;
if ( V_147 ) {
F_23 ( & V_6 -> V_124 ) ;
V_14 = F_102 ( V_3 , V_6 -> V_16 , F_100 ,
V_3 ) ;
if ( V_14 )
goto V_56;
}
return V_148 ;
V_56:
F_31 ( & V_3 -> V_48 , L_41 ) ;
F_42 ( V_3 ) ;
return V_148 ;
}
static void V_125 ( struct V_149 * V_150 )
{
struct V_5 * V_6 = F_103 ( V_150 , struct V_5 ,
V_124 . V_150 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
F_31 ( & V_3 -> V_48 , L_42 ) ;
F_67 ( & V_6 -> V_106 , 0 ) ;
F_42 ( V_3 ) ;
}
static int F_104 ( struct V_2 * V_3 ,
T_2 V_39 , T_2 V_40 , T_2 V_41 , T_2 V_42 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
int V_14 ;
F_39 ( & V_3 -> V_48 , L_43 , V_39 , V_40 , V_41 , V_42 ) ;
F_40 ( & V_6 -> V_67 ) ;
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_56;
if ( ! V_6 -> V_68 ) {
V_14 = 0 ;
goto V_56;
}
V_14 = F_17 ( V_6 , 0 , 0 ,
V_6 -> V_20 -> V_73 . V_74 ,
V_6 -> V_20 -> V_73 . V_75 ) ;
if ( V_14 )
goto V_56;
if ( V_6 -> V_139 && V_54 -> V_117 ) {
F_105 ( & V_6 -> V_124 ,
F_3 ( 250 ) ) ;
F_67 ( & V_6 -> V_106 , 1 ) ;
} else {
V_14 = F_102 ( V_3 , V_6 -> V_16 , F_100 ,
V_3 ) ;
if ( V_14 )
goto V_56;
}
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_56:
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
F_39 ( & V_3 -> V_48 , L_44 ) ;
F_40 ( & V_6 -> V_67 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
F_39 ( & V_3 -> V_48 , L_45 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , bool V_151 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
int V_14 ;
if ( V_151 )
V_14 = F_10 ( V_6 , V_152 , 0 ) ;
else
V_14 = F_8 ( V_6 , V_153 ) ;
if ( ! V_54 -> V_117 )
F_107 ( V_3 , V_151 ) ;
if ( V_6 -> V_20 -> V_21 . V_154 )
F_13 ( V_6 -> V_20 -> V_21 . V_154 ) ;
return V_14 ;
}
static int F_108 ( struct V_2 * V_3 , bool V_151 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_139 == V_151 )
goto V_155;
F_41 ( V_3 ) ;
if ( V_6 -> V_68 ) {
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_56;
V_14 = F_27 ( V_3 , V_151 ) ;
if ( V_14 )
goto V_56;
}
V_6 -> V_139 = V_151 ;
F_42 ( V_3 ) ;
V_155:
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_56:
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
V_14 = V_6 -> V_139 ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_110 ( struct V_2 * V_3 , T_1 V_31 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_39 ( & V_3 -> V_48 , L_46 , V_31 ) ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_31 == V_31 )
goto V_155;
F_41 ( V_3 ) ;
if ( V_6 -> V_68 ) {
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_56;
V_14 = F_16 ( V_6 , V_31 , V_6 -> V_32 ) ;
if ( V_14 )
goto V_56;
}
V_6 -> V_31 = V_31 ;
F_42 ( V_3 ) ;
V_155:
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_56:
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static T_1 F_111 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
V_14 = V_6 -> V_31 ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_112 ( struct V_2 * V_3 , bool V_151 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_39 ( & V_3 -> V_48 , L_47 , V_151 ) ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_6 -> V_32 == V_151 )
goto V_155;
F_41 ( V_3 ) ;
if ( V_6 -> V_68 ) {
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_56;
V_14 = F_16 ( V_6 , V_6 -> V_31 , V_151 ) ;
if ( V_14 )
goto V_56;
}
V_6 -> V_32 = V_151 ;
F_42 ( V_3 ) ;
V_155:
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_56:
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static bool F_113 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
V_14 = V_6 -> V_32 ;
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_114 ( struct V_2 * V_3 , int V_156 )
{
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
T_1 V_25 , V_26 , V_27 ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
if ( ! V_6 -> V_68 ) {
V_14 = - V_81 ;
goto V_58;
}
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_59;
V_14 = F_6 ( V_6 , V_28 , & V_25 ) ;
if ( V_14 )
goto V_59;
V_14 = F_6 ( V_6 , V_29 , & V_26 ) ;
if ( V_14 )
goto V_59;
V_14 = F_6 ( V_6 , V_30 , & V_27 ) ;
if ( V_14 )
goto V_59;
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return 0 ;
V_59:
F_42 ( V_3 ) ;
V_58:
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static int F_115 ( struct V_2 * V_3 ,
void * V_15 , T_4 V_157 ,
T_2 V_39 , T_2 V_40 , T_2 V_41 , T_2 V_42 )
{
int V_14 ;
int V_158 = 1 ;
int V_159 ;
unsigned V_160 = 0 ;
struct V_5 * V_6 = F_20 ( & V_3 -> V_48 ) ;
if ( V_157 < V_41 * V_42 * 3 )
return - V_105 ;
F_40 ( & V_6 -> V_67 ) ;
if ( ! V_6 -> V_68 ) {
V_14 = - V_81 ;
goto V_58;
}
V_157 = F_116 ( V_41 * V_42 * 3 ,
V_3 -> V_72 . V_73 . V_74 *
V_3 -> V_72 . V_73 . V_75 * 3 ) ;
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( V_14 )
goto V_59;
if ( V_157 % 2 )
V_159 = 1 ;
else
V_159 = 2 ;
F_17 ( V_6 , V_39 , V_40 , V_41 , V_42 ) ;
V_14 = F_117 ( V_3 , V_6 -> V_16 , V_159 ) ;
if ( V_14 )
goto V_59;
while ( V_160 < V_157 ) {
T_1 V_13 = V_158 ? 0x2e : 0x3e ;
V_158 = 0 ;
V_14 = F_7 ( V_3 , V_6 -> V_16 , V_13 ,
V_15 + V_160 , V_157 - V_160 ) ;
if ( V_14 < 0 ) {
F_31 ( & V_3 -> V_48 , L_48 ) ;
goto V_161;
}
V_160 += V_14 ;
if ( V_14 < V_159 ) {
F_31 ( & V_3 -> V_48 , L_49 ) ;
break;
}
if ( F_118 ( V_162 ) ) {
F_31 ( & V_3 -> V_48 , L_50
L_51 ) ;
V_14 = - V_163 ;
goto V_161;
}
}
V_14 = V_160 ;
V_161:
F_117 ( V_3 , V_6 -> V_16 , 1 ) ;
V_59:
F_42 ( V_3 ) ;
V_58:
F_43 ( & V_6 -> V_67 ) ;
return V_14 ;
}
static void V_109 ( struct V_149 * V_150 )
{
struct V_5 * V_6 = F_103 ( V_150 , struct V_5 ,
V_53 . V_150 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
F_40 ( & V_6 -> V_67 ) ;
if ( V_3 -> V_142 != V_144 || ! V_6 -> V_68 ) {
F_43 ( & V_6 -> V_67 ) ;
return;
}
F_41 ( V_3 ) ;
F_26 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
}
static void V_108 ( struct V_149 * V_150 )
{
struct V_5 * V_6 = F_103 ( V_150 , struct V_5 ,
V_51 . V_150 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_1 * V_54 = F_1 ( V_3 ) ;
T_1 V_164 , V_165 ;
int V_14 ;
F_40 ( & V_6 -> V_67 ) ;
if ( ! V_6 -> V_68 ) {
F_43 ( & V_6 -> V_67 ) ;
return;
}
F_41 ( V_3 ) ;
V_14 = F_37 ( V_3 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_52 ) ;
goto V_56;
}
V_14 = F_6 ( V_6 , V_166 , & V_164 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_53 ) ;
goto V_56;
}
V_14 = F_14 ( V_6 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_54 ) ;
goto V_56;
}
V_14 = F_6 ( V_6 , V_166 , & V_165 ) ;
if ( V_14 ) {
F_31 ( & V_3 -> V_48 , L_53 ) ;
goto V_56;
}
if ( ! ( ( V_164 ^ V_165 ) & ( 1 << 6 ) ) ) {
F_31 ( & V_3 -> V_48 , L_55 ) ;
goto V_56;
}
if ( V_6 -> V_139 && V_54 -> V_117 ) {
V_14 = F_10 ( V_6 , V_152 , 0 ) ;
if ( V_14 )
goto V_56;
}
F_42 ( V_3 ) ;
F_19 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
return;
V_56:
F_31 ( & V_3 -> V_48 , L_34 ) ;
F_32 ( V_3 ) ;
F_42 ( V_3 ) ;
F_19 ( V_3 ) ;
F_43 ( & V_6 -> V_67 ) ;
}
static int T_7 F_119 ( void )
{
F_120 ( & V_167 ) ;
return 0 ;
}
static void T_5 F_121 ( void )
{
F_122 ( & V_167 ) ;
}
