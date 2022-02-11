static void F_1 ( struct V_1 * V_1 )
{
struct V_2 V_3 ;
F_2 ( & V_3 ) ;
F_3 ( V_1 , V_4 , V_3 . V_5 ) ;
F_3 ( V_1 , V_6 , V_3 . V_7 / V_8 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
T_1 V_9 , V_10 ;
struct V_2 V_3 ;
long V_11 ;
if ( V_1 -> type != V_12 )
return;
if ( ++ V_1 -> V_13 < 60 )
return;
V_1 -> V_13 = 0 ;
V_9 = F_5 ( V_1 , V_4 ) ;
V_10 = F_5 ( V_1 , V_6 ) ;
F_2 ( & V_3 ) ;
V_11 = ( long ) V_3 . V_5 - ( long ) V_9 ;
V_11 = ( V_11 * 1000000 )
+ ( ( long ) ( V_3 . V_7 / V_8 ) - ( long ) V_10 ) ;
if ( V_11 > 1000 || V_11 < - 1000 ) {
F_1 ( V_1 ) ;
} else if ( V_11 ) {
long V_14 = V_1 -> V_14 ;
V_14 -= V_11 / 4 ;
if ( V_14 < 0 )
V_14 = 0 ;
else if ( V_14 > 255 )
V_14 = 255 ;
V_1 -> V_14 = V_14 ;
F_3 ( V_1 , V_15 ,
V_1 -> V_14 ) ;
}
}
static T_2 F_6 ( int V_16 , void * V_17 )
{
struct V_1 * V_1 = V_17 ;
T_1 V_18 ;
int V_19 ;
V_18 = F_5 ( V_1 , V_20 ) ;
if ( ! V_18 )
return V_21 ;
if ( V_18 & ~ V_1 -> V_22 ) {
F_3 ( V_1 , V_20 ,
V_18 & ~ V_1 -> V_22 ) ;
V_18 &= V_1 -> V_22 ;
}
if ( V_18 & V_23 )
F_7 ( V_1 ) ;
for ( V_19 = 0 ; V_19 < V_24 ; V_19 ++ )
if ( V_18 & F_8 ( V_19 ) )
F_9 ( V_1 , V_19 ) ;
if ( V_18 & V_25 )
F_10 ( V_1 ) ;
if ( V_18 & V_26 ) {
F_11 ( V_1 ) ;
F_4 ( V_1 ) ;
}
if ( V_18 & V_27 )
F_12 ( V_1 ) ;
if ( V_18 & V_28 )
F_13 ( V_1 ) ;
F_3 ( V_1 , V_20 , V_18 ) ;
return V_29 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_30 * V_31 ;
if ( ! V_1 )
return;
if ( V_1 -> V_32 . V_33 )
F_15 ( & V_1 -> V_32 ) ;
V_31 = V_1 -> V_31 ;
if ( ! V_31 ) {
F_16 ( V_1 ) ;
return;
}
if ( V_1 -> V_34 ) {
F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 ( V_1 ) ;
F_24 ( V_1 ) ;
F_25 ( V_1 , ~ 0 ) ;
F_26 ( V_31 , V_1 -> V_34 ) ;
if ( V_31 -> V_16 )
F_27 ( V_31 -> V_16 , V_1 ) ;
}
F_28 ( V_31 ) ;
F_29 ( V_31 ) ;
F_30 ( & V_1 -> V_35 ) ;
F_31 ( V_31 , NULL ) ;
F_16 ( V_1 ) ;
}
static T_3 F_32 ( struct V_36 * V_32 , struct V_37 * V_38 ,
const char * V_39 , T_4 V_40 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
unsigned short * V_41 = ( unsigned short * ) V_39 ;
int V_19 ;
if ( V_40 & 0x1 )
F_34 ( V_32 , L_1 ) ;
if ( ! V_42 && V_40 > 64 ) {
F_34 ( V_32 , L_2 ) ;
V_40 = 64 ;
} else if ( V_42 && V_40 > 128 ) {
F_34 ( V_32 , L_3 ) ;
V_40 = 128 ;
}
F_35 ( V_1 , 1 ) ;
for ( V_19 = V_42 ? 0 : 32 ; V_19 < F_36 ( ( int ) ( V_42 ? 64 : 32 ) ,
( int ) ( V_40 / 2 ) ) ; V_19 ++ )
F_37 ( V_1 , V_19 , F_38 ( V_41 [ V_19 ] ) ) ;
F_35 ( V_1 , 0 ) ;
return V_40 ;
}
static T_3 F_39 ( struct V_36 * V_32 , struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
unsigned short * V_41 = ( unsigned short * ) V_39 ;
int V_40 = ( V_42 ? 128 : 64 ) ;
int V_19 ;
for ( V_19 = ( V_42 ? 0 : 32 ) ; V_19 < ( V_40 / 2 ) ; V_19 ++ )
V_41 [ V_19 ] = F_40 ( F_41 ( V_1 , V_19 ) ) ;
return V_40 ;
}
static T_3 F_42 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
return sprintf ( V_39 , L_4 , V_1 -> V_43 ) ;
}
static T_3 F_43 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
return sprintf ( V_39 , L_5 , V_1 -> V_44 >> 20 ) ;
}
static T_3 F_44 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
return sprintf ( V_39 , L_6 ,
F_45 ( V_1 -> V_45 ) ,
F_45 ( V_1 -> V_46 ) ,
F_45 ( V_1 -> V_47 ) ) ;
}
static T_3 F_46 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
unsigned int V_48 ;
char * V_49 = V_39 ;
V_48 = F_5 ( V_1 , V_50 ) ;
V_49 += sprintf ( V_49 , L_7 , V_48 & 0x1f ) ;
V_49 += sprintf ( V_49 , L_8 , ( V_48 >> 5 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_9 , ( V_48 >> 10 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_10 , ( V_48 >> 15 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_11 , ( V_48 >> 20 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_12 , ( V_48 >> 25 ) & 0x1f ) ;
V_48 = F_5 ( V_1 , V_51 ) ;
V_49 += sprintf ( V_49 , L_13 , V_48 & 0x1f ) ;
V_49 += sprintf ( V_49 , L_14 , ( V_48 >> 5 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_15 , ( V_48 >> 10 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_16 , ( V_48 >> 15 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_17 , ( V_48 >> 20 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_18 , ( V_48 >> 25 ) & 0x1f ) ;
V_48 = F_5 ( V_1 , V_52 ) ;
V_49 += sprintf ( V_49 , L_19 , V_48 & 0x1f ) ;
V_49 += sprintf ( V_49 , L_20 , ( V_48 >> 5 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_21 , ( V_48 >> 10 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_22 , ( V_48 >> 15 ) & 0x1f ) ;
V_49 += sprintf ( V_49 , L_23 , ( V_48 >> 20 ) & 0x1f ) ;
return V_49 - V_39 ;
}
static T_3 F_47 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
const char * V_39 , T_4 V_40 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
unsigned long V_53 ;
int V_54 = F_48 ( V_39 , 10 , & V_53 ) ;
if ( V_54 < 0 || V_53 > 200 )
return - V_55 ;
V_1 -> V_56 = F_49 ( V_53 ) ;
return V_40 ;
}
static T_3 F_50 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
return sprintf ( V_39 , L_24 , F_51 ( V_1 -> V_56 ) ) ;
}
static T_3 F_52 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
char * V_49 = V_39 ;
int V_57 = V_1 -> V_57 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_58 ; V_19 ++ ) {
V_49 += sprintf ( V_49 , L_25 ,
V_19 , V_1 -> V_59 [ V_19 ] -> V_60 , V_57 ,
F_5 ( V_1 , F_53 ( V_19 ) ) ) ;
}
return V_49 - V_39 ;
}
static T_3 F_54 ( struct V_36 * V_32 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
char * V_49 = V_39 ;
V_49 += sprintf ( V_49 , L_26 ,
V_61 ,
V_62 ) ;
V_49 += sprintf ( V_49 , L_27 ,
V_63 ,
F_55 ( V_1 ) ,
F_56 ( V_1 ) ,
F_55 ( V_1 ) /
F_56 ( V_1 ) ) ;
V_49 += sprintf ( V_49 , L_28 ,
F_57 ( V_1 ) ,
V_64 ) ;
V_49 += sprintf ( V_49 , L_29 ,
F_58 ( V_1 ) ,
V_65 ) ;
V_49 += sprintf ( V_49 , L_30 ,
F_59 ( V_1 ) ,
F_60 ( V_1 ) ,
V_66 ,
F_60 ( V_1 ) / V_66 ) ;
V_49 += sprintf ( V_49 , L_31 ,
F_61 ( V_1 ) ,
F_62 ( V_1 ) ,
V_67 ,
F_62 ( V_1 ) / V_67 ) ;
V_49 += sprintf ( V_49 , L_32 ,
F_63 ( V_1 ) ,
F_64 ( V_1 ) ) ;
V_49 += sprintf ( V_49 , L_33 ,
F_65 ( V_1 ) ,
F_66 ( V_1 ) ) ;
return V_49 - V_39 ;
}
static T_3 F_67 ( struct V_68 * V_68 , struct V_69 * V_70 ,
struct V_71 * V_72 , char * V_39 ,
T_5 V_73 , T_4 V_40 )
{
struct V_36 * V_32 = F_33 ( V_70 , struct V_36 , V_70 ) ;
struct V_1 * V_1 =
F_33 ( V_32 , struct V_1 , V_32 ) ;
const int V_74 = V_1 -> V_44 ;
if ( V_73 >= V_74 )
return 0 ;
if ( V_73 + V_40 > V_74 )
V_40 = V_74 - V_73 ;
if ( F_68 ( V_1 , 0 , V_39 , V_73 , V_40 , 0 , 0 ) )
return - V_75 ;
return V_40 ;
}
static void F_69 ( struct V_36 * V_32 )
{
}
static int F_70 ( struct V_1 * V_1 )
{
struct V_71 * V_76 = & V_1 -> V_76 ;
struct V_36 * V_32 = & V_1 -> V_32 ;
const char * V_77 ;
int V_19 ;
if ( V_1 -> type == V_12 )
V_77 = L_34 ;
else
V_77 = L_35 ;
V_32 -> V_78 = F_69 ;
V_32 -> V_33 = & V_1 -> V_31 -> V_32 ;
F_71 ( V_32 , F_72 ( & V_1 -> V_31 -> V_32 ) ) ;
F_73 ( V_32 , L_36 , V_77 , V_1 -> V_79 -> V_80 ,
V_1 -> V_58 ) ;
if ( F_74 ( V_32 ) ) {
V_32 -> V_33 = NULL ;
return - V_81 ;
}
for ( V_19 = 0 ; V_19 < F_75 ( V_82 ) ; V_19 ++ ) {
if ( F_76 ( V_32 , & V_82 [ V_19 ] ) ) {
F_15 ( V_32 ) ;
return - V_81 ;
}
}
F_77 ( & V_76 -> V_38 ) ;
V_76 -> V_38 . V_83 = L_37 ;
V_76 -> V_38 . V_84 = 0440 ;
V_76 -> V_85 = F_67 ;
V_76 -> V_74 = V_1 -> V_44 ;
if ( F_78 ( V_32 , V_76 ) ) {
F_15 ( V_32 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_79 ( struct V_30 * V_31 , const struct V_86 * V_87 )
{
struct V_1 * V_1 ;
int V_54 ;
T_6 V_88 ;
V_1 = F_80 ( sizeof( * V_1 ) , V_89 ) ;
if ( V_1 == NULL )
return - V_81 ;
if ( V_87 -> V_90 == V_91 )
F_81 ( & V_31 -> V_32 , L_38 ) ;
else
F_81 ( & V_31 -> V_32 , L_39 ) ;
V_1 -> type = V_87 -> V_90 ;
V_1 -> V_31 = V_31 ;
F_82 ( & V_1 -> V_92 ) ;
V_54 = F_83 ( & V_31 -> V_32 , & V_1 -> V_35 ) ;
if ( V_54 )
goto V_93;
V_1 -> V_56 = F_49 ( 100 ) ;
V_54 = F_84 ( V_31 ) ;
if ( V_54 )
goto V_93;
F_85 ( V_31 ) ;
F_86 ( V_31 , 0x40 , 0x00 ) ;
F_86 ( V_31 , 0x41 , 0x00 ) ;
V_54 = F_87 ( V_31 , V_94 ) ;
if ( V_54 )
goto V_93;
V_1 -> V_34 = F_88 ( V_31 , 0 ) ;
if ( V_1 -> V_34 == NULL ) {
V_54 = - V_81 ;
goto V_93;
}
V_88 = F_5 ( V_1 , V_95 ) &
V_96 ;
switch ( V_88 ) {
case 7 :
V_1 -> V_58 = 16 ;
V_1 -> V_97 = 5 ;
break;
case 6 :
V_1 -> V_58 = 8 ;
V_1 -> V_97 = 2 ;
break;
default:
F_34 ( & V_31 -> V_32 , L_40 ,
V_88 ) ;
case 5 :
V_1 -> V_58 = 4 ;
V_1 -> V_97 = 1 ;
}
F_25 ( V_1 , ~ 0 ) ;
if ( V_1 -> type == V_91 ) {
V_1 -> V_98 = 108 ;
V_1 -> V_99 = V_100
| F_89 ( 25 )
| F_90 ( V_1 -> V_98 * 2 - 2 )
| F_91 ( 3 ) ;
F_3 ( V_1 , V_101 , V_1 -> V_99 ) ;
} else {
T_1 V_102 , V_103 ;
V_1 -> V_98 = 135 ;
if ( V_1 -> V_98 < 125 ) {
V_102 = 3 ;
V_103 = ( V_1 -> V_98 * 4 ) / 3 - 1 ;
} else {
V_102 = 2 ;
V_103 = ( V_1 -> V_98 * 2 ) / 3 - 1 ;
}
F_3 ( V_1 , V_104 ,
( 1 << 20 ) |
( 8 << 15 ) |
( V_102 << 12 ) |
( V_103 << 4 ) |
( 1 << 1 ) ) ;
V_1 -> V_99 = V_100 ;
}
F_3 ( V_1 , V_101 , V_1 -> V_99 ) ;
F_3 ( V_1 , V_105 ,
V_1 -> V_98 - 1 ) ;
F_92 ( 1 ) ;
V_54 = F_93 ( V_31 -> V_16 , F_6 , V_106 , V_94 ,
V_1 ) ;
if ( V_54 )
goto V_93;
F_94 ( V_1 , V_23 ) ;
V_54 = F_95 ( V_1 ) ;
if ( V_54 )
goto V_93;
F_3 ( V_1 , V_107 ,
F_96 ( 1 ) |
F_97 ( 2 ) |
V_108 |
V_109 |
F_98 ( 1 ) ) ;
F_3 ( V_1 , V_110 ,
V_1 -> type == V_91 ? 0x100 : 0x300 ) ;
if ( V_1 -> type != V_91 ) {
V_1 -> V_14 = 0x3f ;
F_1 ( V_1 ) ;
}
F_3 ( V_1 , V_111 , 0 ) ;
V_54 = F_99 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_54 = F_100 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_54 = F_101 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_54 = F_102 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_54 = F_103 ( V_1 , V_112 ) ;
if ( V_54 )
goto V_93;
V_54 = F_104 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_54 = F_105 ( V_1 , V_112 ) ;
if ( V_54 )
goto V_93;
V_54 = F_106 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_54 = F_70 ( V_1 ) ;
if ( V_54 )
goto V_93;
V_1 -> V_56 = F_49 ( 20 ) ;
return 0 ;
V_93:
F_14 ( V_1 ) ;
return V_54 ;
}
static void F_107 ( struct V_30 * V_31 )
{
struct V_113 * V_35 = F_108 ( V_31 ) ;
struct V_1 * V_1 = F_33 ( V_35 , struct V_1 , V_35 ) ;
F_14 ( V_1 ) ;
}
