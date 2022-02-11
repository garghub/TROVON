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
F_3 ( V_1 , V_20 , V_18 ) ;
if ( V_18 & V_22 )
F_7 ( V_1 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ )
if ( V_18 & F_8 ( V_19 ) )
F_9 ( V_1 , V_19 ) ;
if ( V_18 & V_24 )
F_10 ( V_1 ) ;
if ( V_18 & V_25 ) {
F_11 ( V_1 ) ;
F_4 ( V_1 ) ;
}
if ( V_18 & V_26 )
F_12 ( V_1 ) ;
if ( V_18 & V_27 )
F_13 ( V_1 ) ;
return V_28 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = V_1 -> V_30 ;
if ( V_1 -> V_31 . V_32 )
F_15 ( & V_1 -> V_31 ) ;
if ( V_1 -> V_33 ) {
F_16 ( V_1 ) ;
F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
F_23 ( V_1 ) ;
F_24 ( V_1 , ~ 0 ) ;
F_25 ( V_30 -> V_16 , V_1 ) ;
F_26 ( V_30 , V_1 -> V_33 ) ;
}
F_27 ( V_30 ) ;
F_28 ( V_30 ) ;
F_29 ( & V_1 -> V_34 ) ;
F_30 ( V_30 , NULL ) ;
F_31 ( V_1 ) ;
}
static T_3 F_32 ( struct V_35 * V_31 , struct V_36 * V_37 ,
const char * V_38 , T_4 V_39 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
T_5 * V_40 = ( T_5 * ) V_38 ;
int V_19 ;
if ( V_39 & 0x1 )
F_34 ( V_31 , L_1 ) ;
if ( ! V_41 && V_39 > 64 ) {
F_34 ( V_31 , L_2 ) ;
V_39 = 64 ;
} else if ( V_41 && V_39 > 128 ) {
F_34 ( V_31 , L_3 ) ;
V_39 = 128 ;
}
F_35 ( V_1 , 1 ) ;
for ( V_19 = V_41 ? 0 : 32 ; V_19 < F_36 ( ( int ) ( V_41 ? 64 : 32 ) ,
( int ) ( V_39 / 2 ) ) ; V_19 ++ )
F_37 ( V_1 , V_19 , F_38 ( V_40 [ V_19 ] ) ) ;
F_35 ( V_1 , 0 ) ;
return V_39 ;
}
static T_3 F_39 ( struct V_35 * V_31 , struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
T_5 * V_40 = ( T_5 * ) V_38 ;
int V_39 = ( V_41 ? 128 : 64 ) ;
int V_19 ;
for ( V_19 = ( V_41 ? 0 : 32 ) ; V_19 < ( V_39 / 2 ) ; V_19 ++ )
V_40 [ V_19 ] = F_40 ( F_41 ( V_1 , V_19 ) ) ;
return V_39 ;
}
static T_3 F_42 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
return sprintf ( V_38 , L_4 , V_1 -> V_42 ) ;
}
static T_3 F_43 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
return sprintf ( V_38 , L_5 , V_1 -> V_43 >> 20 ) ;
}
static T_3 F_44 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
return sprintf ( V_38 , L_6 ,
F_45 ( V_1 -> V_44 ) ,
F_45 ( V_1 -> V_45 ) ,
F_45 ( V_1 -> V_46 ) ) ;
}
static T_3 F_46 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
unsigned int V_47 ;
char * V_48 = V_38 ;
V_47 = F_5 ( V_1 , V_49 ) ;
V_48 += sprintf ( V_48 , L_7 , V_47 & 0x1f ) ;
V_48 += sprintf ( V_48 , L_8 , ( V_47 >> 5 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_9 , ( V_47 >> 10 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_10 , ( V_47 >> 15 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_11 , ( V_47 >> 20 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_12 , ( V_47 >> 25 ) & 0x1f ) ;
V_47 = F_5 ( V_1 , V_50 ) ;
V_48 += sprintf ( V_48 , L_13 , V_47 & 0x1f ) ;
V_48 += sprintf ( V_48 , L_14 , ( V_47 >> 5 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_15 , ( V_47 >> 10 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_16 , ( V_47 >> 15 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_17 , ( V_47 >> 20 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_18 , ( V_47 >> 25 ) & 0x1f ) ;
V_47 = F_5 ( V_1 , V_51 ) ;
V_48 += sprintf ( V_48 , L_19 , V_47 & 0x1f ) ;
V_48 += sprintf ( V_48 , L_20 , ( V_47 >> 5 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_21 , ( V_47 >> 10 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_22 , ( V_47 >> 15 ) & 0x1f ) ;
V_48 += sprintf ( V_48 , L_23 , ( V_47 >> 20 ) & 0x1f ) ;
return V_48 - V_38 ;
}
static T_3 F_47 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
const char * V_38 , T_4 V_39 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
unsigned long V_52 ;
int V_53 = F_48 ( V_38 , 10 , & V_52 ) ;
if ( V_53 < 0 || V_52 > 200 )
return - V_54 ;
V_1 -> V_55 = F_49 ( V_52 ) ;
return V_39 ;
}
static T_3 F_50 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
return sprintf ( V_38 , L_24 , F_51 ( V_1 -> V_55 ) ) ;
}
static T_3 F_52 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
char * V_48 = V_38 ;
int V_56 = V_1 -> V_56 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_1 -> V_57 ; V_19 ++ ) {
V_48 += sprintf ( V_48 , L_25 ,
V_19 , V_1 -> V_58 [ V_19 ] -> V_59 , V_56 ,
F_5 ( V_1 , F_53 ( V_19 ) ) ) ;
}
return V_48 - V_38 ;
}
static T_3 F_54 ( struct V_35 * V_31 ,
struct V_36 * V_37 ,
char * V_38 )
{
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
char * V_48 = V_38 ;
V_48 += sprintf ( V_48 , L_26 ,
V_60 ,
V_61 ) ;
V_48 += sprintf ( V_48 , L_27 ,
V_62 ,
F_55 ( V_1 ) ,
F_56 ( V_1 ) ,
F_55 ( V_1 ) /
F_56 ( V_1 ) ) ;
V_48 += sprintf ( V_48 , L_28 ,
F_57 ( V_1 ) ,
V_63 ) ;
V_48 += sprintf ( V_48 , L_29 ,
F_58 ( V_1 ) ,
V_64 ) ;
V_48 += sprintf ( V_48 , L_30 ,
F_59 ( V_1 ) ,
F_60 ( V_1 ) ,
V_65 ,
F_60 ( V_1 ) / V_65 ) ;
V_48 += sprintf ( V_48 , L_31 ,
F_61 ( V_1 ) ,
F_62 ( V_1 ) ,
V_66 ,
F_62 ( V_1 ) / V_66 ) ;
V_48 += sprintf ( V_48 , L_32 ,
F_63 ( V_1 ) ,
F_64 ( V_1 ) ) ;
V_48 += sprintf ( V_48 , L_33 ,
F_65 ( V_1 ) ,
F_66 ( V_1 ) ) ;
return V_48 - V_38 ;
}
static T_3 F_67 ( struct V_67 * V_67 , struct V_68 * V_69 ,
struct V_70 * V_71 , char * V_38 ,
T_6 V_72 , T_4 V_39 )
{
struct V_35 * V_31 = F_33 ( V_69 , struct V_35 , V_69 ) ;
struct V_1 * V_1 =
F_33 ( V_31 , struct V_1 , V_31 ) ;
const int V_73 = V_1 -> V_43 ;
if ( V_72 >= V_73 )
return 0 ;
if ( V_72 + V_39 > V_73 )
V_39 = V_73 - V_72 ;
if ( F_68 ( V_1 , 0 , V_38 , V_72 , V_39 , 0 , 0 ) )
return - V_74 ;
return V_39 ;
}
static void F_69 ( struct V_35 * V_31 )
{
}
static int F_70 ( struct V_1 * V_1 )
{
struct V_70 * V_75 = & V_1 -> V_75 ;
struct V_35 * V_31 = & V_1 -> V_31 ;
const char * V_76 ;
int V_19 ;
if ( V_1 -> type == V_12 )
V_76 = L_34 ;
else
V_76 = L_35 ;
V_31 -> V_77 = F_69 ;
V_31 -> V_32 = & V_1 -> V_30 -> V_31 ;
F_71 ( V_31 , F_72 ( & V_1 -> V_30 -> V_31 ) ) ;
F_73 ( V_31 , L_36 , V_76 , V_1 -> V_78 -> V_79 ,
V_1 -> V_57 ) ;
if ( F_74 ( V_31 ) ) {
V_31 -> V_32 = NULL ;
return - V_80 ;
}
for ( V_19 = 0 ; V_19 < F_75 ( V_81 ) ; V_19 ++ ) {
if ( F_76 ( V_31 , & V_81 [ V_19 ] ) ) {
F_15 ( V_31 ) ;
return - V_80 ;
}
}
F_77 ( & V_75 -> V_37 ) ;
V_75 -> V_37 . V_82 = L_37 ;
V_75 -> V_37 . V_83 = 0440 ;
V_75 -> V_84 = F_67 ;
V_75 -> V_73 = V_1 -> V_43 ;
if ( F_78 ( V_31 , V_75 ) ) {
F_15 ( V_31 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_79 ( struct V_29 * V_30 , const struct V_85 * V_86 )
{
struct V_1 * V_1 ;
int V_53 ;
T_7 V_87 ;
V_1 = F_80 ( sizeof( * V_1 ) , V_88 ) ;
if ( V_1 == NULL )
return - V_80 ;
if ( V_86 -> V_89 == V_90 )
F_81 ( & V_30 -> V_31 , L_38 ) ;
else
F_81 ( & V_30 -> V_31 , L_39 ) ;
V_1 -> type = V_86 -> V_89 ;
V_1 -> V_30 = V_30 ;
V_53 = F_82 ( & V_30 -> V_31 , & V_1 -> V_34 ) ;
if ( V_53 )
goto V_91;
V_1 -> V_55 = F_49 ( 100 ) ;
V_53 = F_83 ( V_30 ) ;
if ( V_53 )
goto V_91;
F_84 ( V_30 ) ;
F_85 ( V_30 , 0x40 , 0x00 ) ;
F_85 ( V_30 , 0x41 , 0x00 ) ;
V_53 = F_86 ( V_30 , V_92 ) ;
if ( V_53 )
goto V_91;
V_1 -> V_33 = F_87 ( V_30 , 0 ) ;
if ( V_1 -> V_33 == NULL ) {
V_53 = - V_80 ;
goto V_91;
}
V_87 = F_5 ( V_1 , V_93 ) &
V_94 ;
switch ( V_87 ) {
case 7 :
V_1 -> V_57 = 16 ;
V_1 -> V_95 = 5 ;
break;
case 6 :
V_1 -> V_57 = 8 ;
V_1 -> V_95 = 2 ;
break;
default:
F_34 ( & V_30 -> V_31 , L_40 ,
V_87 ) ;
case 5 :
V_1 -> V_57 = 4 ;
V_1 -> V_95 = 1 ;
}
F_24 ( V_1 , ~ 0 ) ;
if ( V_1 -> type == V_90 ) {
V_1 -> V_96 = 108 ;
V_1 -> V_97 = V_98
| F_88 ( 25 )
| F_89 ( V_1 -> V_96 * 2 - 2 )
| F_90 ( 3 ) ;
F_3 ( V_1 , V_99 , V_1 -> V_97 ) ;
} else {
T_1 V_100 , V_101 ;
V_1 -> V_96 = 135 ;
if ( V_1 -> V_96 < 125 ) {
V_100 = 3 ;
V_101 = ( V_1 -> V_96 * 4 ) / 3 - 1 ;
} else {
V_100 = 2 ;
V_101 = ( V_1 -> V_96 * 2 ) / 3 - 1 ;
}
F_3 ( V_1 , V_102 ,
( 1 << 20 ) |
( 8 << 15 ) |
( V_100 << 12 ) |
( V_101 << 4 ) |
( 1 << 1 ) ) ;
V_1 -> V_97 = V_98 ;
}
F_3 ( V_1 , V_99 , V_1 -> V_97 ) ;
F_3 ( V_1 , V_103 ,
V_1 -> V_96 - 1 ) ;
F_91 ( 1 ) ;
V_53 = F_92 ( V_30 -> V_16 , F_6 , V_104 , V_92 ,
V_1 ) ;
if ( V_53 )
goto V_91;
F_93 ( V_1 , V_22 ) ;
V_53 = F_94 ( V_1 ) ;
if ( V_53 )
goto V_91;
F_3 ( V_1 , V_105 ,
F_95 ( 1 ) |
F_96 ( 2 ) |
V_106 |
V_107 |
F_97 ( 1 ) ) ;
F_3 ( V_1 , V_108 ,
V_1 -> type == V_90 ? 0x100 : 0x300 ) ;
if ( V_1 -> type != V_90 ) {
V_1 -> V_14 = 0x3f ;
F_1 ( V_1 ) ;
}
F_3 ( V_1 , V_109 , 0 ) ;
V_53 = F_98 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_53 = F_99 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_53 = F_100 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_53 = F_101 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_53 = F_102 ( V_1 , V_110 ) ;
if ( V_53 )
goto V_91;
V_53 = F_103 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_53 = F_104 ( V_1 , V_110 ) ;
if ( V_53 )
goto V_91;
V_53 = F_105 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_53 = F_70 ( V_1 ) ;
if ( V_53 )
goto V_91;
V_1 -> V_55 = F_49 ( 20 ) ;
return 0 ;
V_91:
F_14 ( V_1 ) ;
return V_53 ;
}
static void F_106 ( struct V_29 * V_30 )
{
struct V_111 * V_34 = F_107 ( V_30 ) ;
struct V_1 * V_1 = F_33 ( V_34 , struct V_1 , V_34 ) ;
F_14 ( V_1 ) ;
}
