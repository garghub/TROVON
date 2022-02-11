static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
if ( ! strcasecmp ( V_1 , L_1 ) )
V_3 = 0 ;
else if ( ! strcasecmp ( V_1 , L_2 ) )
V_3 = 1 ;
return 0 ;
}
void F_2 ( struct V_4 * V_5 , T_2 V_6 ,
T_2 V_7 )
{
T_2 V_8 ;
for ( V_8 = 0 ;
V_8 < V_9 ;
V_8 ++ ) {
if ( ( F_3 ( V_6 ) & V_7 ) == V_7 )
break;
F_4 ( 100 ) ;
}
if ( V_8 == V_9 )
F_5 ( L_3 ,
V_6 ) ;
}
void F_6 ( struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 =
F_7 ( V_11 ) ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
T_2 V_17 ;
if ( ! V_14 ) {
F_5 ( L_4 ) ;
return;
}
V_5 = V_14 -> V_5 ;
V_16 = V_5 -> V_18 ;
F_8 ( V_14 , V_19 , 0xd8 , 1 ,
true ) ;
F_8 ( V_14 , V_20 , 0x33 , 1 , true ) ;
V_17 = V_21 | V_22 |
V_23 ;
if ( V_3 == 1 )
V_17 |= V_22 | V_24
| V_25 ;
if ( V_3 == 1 )
V_17 |= V_26 ;
V_16 -> V_27 = V_17 ;
F_8 ( V_14 , V_28 , ( V_29 ) V_17 ,
1 , true ) ;
F_8 ( V_14 , V_30 , V_31 , 1 , true ) ;
}
void F_9 ( struct V_4 * V_5 , int V_12 , int V_32 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_10 * V_11 ;
T_2 V_17 = 0 ;
int V_33 = V_34 ;
if ( ! V_5 || ( V_12 != 0 && V_12 != 2 ) ) {
F_5 ( L_5 ) ;
return;
}
V_33 = F_10 ( V_5 , 0 ) ;
V_16 = V_5 -> V_18 ;
if ( V_12 )
V_11 = V_16 -> V_35 [ 1 ] ;
else
V_11 = V_16 -> V_35 [ 0 ] ;
V_14 = F_7 ( V_11 ) ;
if ( ! V_14 ) {
F_5 ( L_4 ) ;
return;
}
V_17 = ( V_32 * 0xff / V_36 ) & 0xff ;
F_11 ( V_14 -> V_5 -> V_5 , L_6 ,
V_12 , V_17 ) ;
if ( V_33 == V_34 ) {
F_8 ( V_14 , V_37 ,
( V_29 ) V_17 , 1 , true ) ;
} else {
F_8 ( V_14 , V_19 ,
( V_29 ) V_17 , 1 , true ) ;
if ( V_32 == 0 )
V_17 = 0 ;
else
V_17 = V_16 -> V_27 ;
F_8 ( V_14 , V_28 ,
( V_29 ) V_17 , 1 , true ) ;
}
}
static int F_12 ( struct V_10 * V_11 ,
V_29 V_38 , T_2 * V_39 , bool V_40 )
{
struct V_13 * V_14
= F_7 ( V_11 ) ;
if ( ! V_14 || ! V_39 ) {
F_5 ( L_5 ) ;
return - V_2 ;
}
return F_13 ( V_14 , V_38 , V_39 , 1 , V_40 ) ;
}
int F_14 ( struct V_10 * V_11 , T_2 * V_41 ,
bool V_40 )
{
if ( ! V_11 || ! V_41 ) {
F_5 ( L_5 ) ;
return - V_2 ;
}
return F_12 ( V_11 , 0x0a , V_41 , V_40 ) ;
}
void F_15 ( struct V_10 * V_11 , int V_12 )
{
if ( ! V_11 || ( ( V_12 != 0 ) && ( V_12 != 2 ) ) ) {
F_5 ( L_7 ) ;
return;
}
F_16 ( V_11 , V_12 ) ;
}
static void F_17 ( struct V_42 * V_43 )
{
}
static void F_18 ( struct V_42 * V_43 )
{
}
static enum V_44
F_19 ( struct V_42 * V_43 , bool V_45 )
{
struct V_46 * V_47
= V_46 ( V_43 ) ;
V_47 -> V_48 = V_49 ;
return V_47 -> V_48 ;
}
static int F_20 ( struct V_42 * V_43 ,
struct V_50 * V_51 ,
T_3 V_52 )
{
struct V_53 * V_54 = V_43 -> V_54 ;
if ( ! strcmp ( V_51 -> V_55 , L_8 ) && V_54 ) {
struct V_56 * V_56 = F_21 ( V_54 -> V_57 ) ;
bool V_58 ;
T_3 V_59 ;
if ( ! V_56 )
goto V_60;
switch ( V_52 ) {
case V_61 :
break;
case V_62 :
break;
case V_63 :
break;
default:
goto V_60;
}
if ( F_22 ( & V_43 -> V_64 , V_51 , & V_59 ) )
goto V_60;
if ( V_59 == V_52 )
goto V_65;
if ( F_23 ( & V_43 -> V_64 ,
V_51 , V_52 ) )
goto V_60;
V_58 = ( V_59 == V_62 ) ||
( V_52 == V_62 ) ;
if ( V_56 -> V_66 . V_67 != 0 &&
V_56 -> V_66 . V_68 != 0 ) {
if ( V_58 ) {
if ( ! F_24 ( V_54 -> V_57 ,
& V_56 -> V_66 ,
V_54 -> V_57 -> V_69 ,
V_54 -> V_57 -> V_70 ,
V_54 -> V_57 -> V_71 -> V_72 ) )
goto V_60;
} else {
const struct V_73 * V_74 =
V_54 -> V_75 ;
V_74 -> V_76 ( V_54 ,
& V_56 -> V_66 ,
& V_56 -> V_77 ) ;
}
}
} else if ( ! strcmp ( V_51 -> V_55 , L_9 ) && V_54 ) {
if ( F_23 ( & V_43 -> V_64 , V_51 ,
V_52 ) )
goto V_60;
else
F_25 ( V_54 -> V_5 , V_52 ) ;
}
V_65:
return 0 ;
V_60:
return - 1 ;
}
static void F_26 ( struct V_42 * V_43 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_13 * V_14 ;
if ( ! V_47 )
return;
F_27 ( V_43 ) ;
F_28 ( V_43 ) ;
V_14 = V_47 -> V_78 ;
F_29 ( V_14 ) ;
F_30 ( V_47 ) ;
}
static int F_31 ( struct V_42 * V_43 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_10 * V_11 =
F_32 ( V_47 ) ;
struct V_79 * V_80 = V_11 -> V_80 ;
struct V_79 * V_81 = NULL ;
struct V_4 * V_5 = V_43 -> V_5 ;
V_43 -> V_82 . V_83 = 0 ;
V_43 -> V_82 . V_84 = 200 ;
V_43 -> V_82 . V_85 = 0 ;
V_43 -> V_82 . V_86 = 200 ;
if ( V_80 ) {
F_11 ( V_5 -> V_5 , L_10 ,
V_80 -> V_67 , V_80 -> V_68 ) ;
V_81 = F_33 ( V_5 , V_80 ) ;
F_34 ( V_43 , V_81 ) ;
return 1 ;
}
F_5 ( L_11 ) ;
return 0 ;
}
static int F_35 ( struct V_42 * V_43 ,
struct V_79 * V_41 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_10 * V_11 =
F_32 ( V_47 ) ;
struct V_79 * V_80 = V_11 -> V_80 ;
if ( V_41 -> V_87 & V_88 )
return V_89 ;
if ( V_41 -> V_87 & V_90 )
return V_91 ;
if ( V_80 ) {
if ( V_41 -> V_67 != V_80 -> V_67 )
return V_92 ;
if ( V_41 -> V_68 != V_80 -> V_68 )
return V_92 ;
}
return V_93 ;
}
static void F_36 ( struct V_42 * V_43 , int V_41 )
{
if ( V_41 == V_43 -> V_94 )
return;
F_37 ( V_43 , V_41 ) ;
}
static struct V_53 * F_38 (
struct V_42 * V_43 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_10 * V_11 =
F_32 ( V_47 ) ;
return & V_11 -> V_54 -> V_64 . V_64 ;
}
static int F_39 ( struct V_4 * V_5 ,
struct V_10 * V_95 , int V_12 )
{
if ( ! V_5 || ! V_95 ) {
F_5 ( L_12 ) ;
return - V_2 ;
}
V_95 -> V_96 = 24 ;
if ( F_10 ( V_5 , V_12 ) == V_97 )
V_95 -> V_98 = 4 ;
else
V_95 -> V_98 = 2 ;
V_95 -> V_99 = 0 ;
if ( F_10 ( V_5 , V_12 ) == V_34 )
V_95 -> V_100 = V_101 ;
else if ( F_10 ( V_5 , V_12 ) == V_97 )
V_95 -> V_100 =
V_102 ;
else
V_95 -> V_100 = V_103 ;
return 0 ;
}
int F_40 ( int V_12 )
{
unsigned V_104 ;
int V_105 = 0 ;
switch ( V_12 ) {
case 0 :
V_104 = 128 ;
break;
case 2 :
V_104 = 34 ;
break;
default:
F_5 ( L_13 ) ;
return - V_2 ;
}
V_105 = F_41 ( V_104 , L_14 ) ;
if ( V_105 ) {
F_5 ( L_15 ) ;
return V_105 ;
}
V_105 = F_42 ( V_104 , 1 ) ;
if ( V_105 ) {
F_5 ( L_16 ) ;
goto V_106;
}
F_43 ( 128 ) ;
V_106:
if ( F_44 ( V_104 ) )
F_45 ( V_104 ) ;
return V_105 ;
}
void F_46 ( struct V_4 * V_5 ,
int V_12 ,
const struct V_107 * V_108 )
{
struct V_10 * V_11 ;
struct V_46 * V_47 ;
struct V_42 * V_43 ;
struct V_109 * V_54 ;
struct V_15 * V_16 = V_5 -> V_18 ;
struct V_110 V_111 ;
T_2 V_112 , V_113 ;
F_11 ( V_5 -> V_5 , L_17 , V_12 ) ;
if ( V_12 != 0 && V_12 != 2 ) {
F_5 ( L_5 ) ;
return;
}
V_47 = F_47 ( sizeof( struct V_46 ) , V_114 ) ;
if ( ! V_47 ) {
F_5 ( L_18 ) ;
return;
}
V_47 -> V_12 = V_12 ;
V_11 = F_47 ( sizeof( struct V_10 ) ,
V_114 ) ;
if ( ! V_11 ) {
F_5 ( L_19 ) ;
goto V_115;
}
F_39 ( V_5 , V_11 , V_12 ) ;
V_47 -> V_116 = V_11 ;
V_11 -> V_117 = 1 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_80 = V_108 -> V_118 ( V_5 ) ;
if ( V_108 -> V_119 ( V_5 , V_12 , & V_111 ) )
goto V_115;
V_112 = V_111 . V_112 ;
V_113 = V_111 . V_113 ;
V_11 -> V_41 = V_11 -> V_80 ;
V_11 -> V_43 = V_47 ;
if ( ! V_11 -> V_80 ) {
F_5 ( L_20 ) ;
goto V_115;
}
if ( V_12 && V_16 -> V_35 [ 0 ] ) {
V_11 -> V_120 = 0 ;
V_16 -> V_35 [ 1 ] = V_11 ;
} else if ( V_12 == 0 ) {
V_11 -> V_120 = 1 ;
V_16 -> V_35 [ 0 ] = V_11 ;
} else {
F_5 ( L_21 ) ;
goto V_115;
}
V_43 = & V_47 -> V_64 . V_64 ;
V_47 -> V_64 . V_121 = F_17 ;
V_47 -> V_64 . V_122 = F_18 ;
F_48 ( V_5 , V_43 , & V_123 ,
V_124 ) ;
F_49 ( V_43 , & V_125 ) ;
V_43 -> V_82 . V_126 = V_127 ;
V_43 -> V_82 . V_112 = V_112 ;
V_43 -> V_82 . V_113 = V_113 ;
V_43 -> V_128 = false ;
V_43 -> V_129 = false ;
F_50 ( & V_43 -> V_64 ,
V_5 -> V_130 . V_131 ,
V_61 ) ;
F_50 ( & V_43 -> V_64 ,
V_16 -> V_132 ,
V_36 ) ;
if ( F_51 ( V_47 , V_12 ) ) {
F_5 ( L_22 ,
V_12 ) ;
goto V_115;
}
V_54 = F_52 ( V_5 , V_47 , V_108 ) ;
if ( ! V_54 ) {
F_5 ( L_23 ) ;
goto V_133;
}
V_54 -> V_116 = V_11 ;
V_11 -> V_54 = V_54 ;
V_54 -> V_64 . type = ( V_12 == 0 ) ? V_134 :
V_135 ;
F_53 ( V_43 ) ;
return;
V_133:
F_29 ( V_47 -> V_78 ) ;
F_28 ( V_43 ) ;
F_30 ( V_11 -> V_80 ) ;
F_30 ( V_11 ) ;
V_115:
F_30 ( V_47 ) ;
}
