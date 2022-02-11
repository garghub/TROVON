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
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_15 * V_16 = V_5 -> V_17 ;
T_2 V_18 ;
if ( ! V_14 ) {
F_5 ( L_4 ) ;
return;
}
F_8 ( V_14 , V_19 , 0xd8 , 1 ,
true ) ;
F_8 ( V_14 , V_20 , 0x33 , 1 , true ) ;
V_18 = V_21 | V_22 |
V_23 ;
if ( V_3 == 1 )
V_18 |= V_22 | V_24
| V_25 ;
if ( V_3 == 1 )
V_18 |= V_26 ;
V_16 -> V_27 = V_18 ;
F_8 ( V_14 , V_28 , ( V_29 ) V_18 ,
1 , true ) ;
F_8 ( V_14 , V_30 , V_31 , 1 , true ) ;
}
void F_9 ( struct V_4 * V_5 , int V_12 , int V_32 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_10 * V_11 ;
T_2 V_18 = 0 ;
int V_33 = V_34 ;
if ( ! V_5 || ( V_12 != 0 && V_12 != 2 ) ) {
F_5 ( L_5 ) ;
return;
}
V_33 = F_10 ( V_5 , 0 ) ;
V_16 = V_5 -> V_17 ;
if ( V_12 )
V_11 = V_16 -> V_35 [ 1 ] ;
else
V_11 = V_16 -> V_35 [ 0 ] ;
V_14 = F_7 ( V_11 ) ;
if ( ! V_14 ) {
F_5 ( L_4 ) ;
return;
}
V_18 = ( V_32 * 0xff / V_36 ) & 0xff ;
F_11 ( V_14 -> V_5 -> V_5 , L_6 ,
V_12 , V_18 ) ;
if ( V_33 == V_34 ) {
F_8 ( V_14 , V_37 ,
( V_29 ) V_18 , 1 , true ) ;
} else {
F_8 ( V_14 , V_19 ,
( V_29 ) V_18 , 1 , true ) ;
if ( V_32 == 0 )
V_18 = 0 ;
else
V_18 = V_16 -> V_27 ;
F_8 ( V_14 , V_28 ,
( V_29 ) V_18 , 1 , true ) ;
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
struct V_56 * V_57 =
F_21 ( V_54 -> V_58 ) ;
bool V_59 ;
T_3 V_60 ;
if ( ! V_57 )
goto V_61;
switch ( V_52 ) {
case V_62 :
break;
case V_63 :
break;
case V_64 :
break;
default:
goto V_61;
}
if ( F_22 ( V_43 , V_51 , & V_60 ) )
goto V_61;
if ( V_60 == V_52 )
goto V_65;
if ( F_23 ( V_43 ,
V_51 , V_52 ) )
goto V_61;
V_59 = ( V_60 == V_63 ) ||
( V_52 == V_63 ) ;
if ( V_57 -> V_66 . V_67 != 0 &&
V_57 -> V_66 . V_68 != 0 ) {
if ( V_59 ) {
if ( ! F_24 ( V_54 -> V_58 ,
& V_57 -> V_66 ,
V_54 -> V_58 -> V_69 ,
V_54 -> V_58 -> V_70 ,
V_54 -> V_58 -> V_71 ) )
goto V_61;
} else {
struct V_72 * V_73 =
V_54 -> V_74 ;
V_73 -> V_75 ( V_54 ,
& V_57 -> V_66 ,
& V_57 -> V_76 ) ;
}
}
} else if ( ! strcmp ( V_51 -> V_55 , L_9 ) && V_54 ) {
if ( F_23 ( V_43 , V_51 ,
V_52 ) )
goto V_61;
else {
#ifdef F_25
struct V_77 * V_78 ;
V_78 = F_26 () ;
if ( V_78 ) {
V_78 -> V_79 . V_80 = V_52 ;
F_27 ( V_78 ) ;
}
#endif
}
}
V_65:
return 0 ;
V_61:
return - 1 ;
}
static void F_28 ( struct V_42 * V_43 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_13 * V_14 ;
if ( ! V_47 )
return;
F_29 ( V_43 ) ;
F_30 ( V_43 ) ;
V_14 = V_47 -> V_81 ;
F_31 ( V_14 ) ;
F_32 ( V_47 ) ;
}
static int F_33 ( struct V_42 * V_43 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_10 * V_11 =
F_34 ( V_47 ) ;
struct V_82 * V_83 = V_11 -> V_83 ;
struct V_82 * V_84 = NULL ;
struct V_4 * V_5 = V_43 -> V_5 ;
V_43 -> V_85 . V_86 = 0 ;
V_43 -> V_85 . V_87 = 200 ;
V_43 -> V_85 . V_88 = 0 ;
V_43 -> V_85 . V_89 = 200 ;
if ( V_83 ) {
F_11 ( V_5 -> V_5 , L_10 ,
V_83 -> V_67 , V_83 -> V_68 ) ;
V_84 = F_35 ( V_5 , V_83 ) ;
F_36 ( V_43 , V_84 ) ;
return 1 ;
}
F_5 ( L_11 ) ;
return 0 ;
}
static int F_37 ( struct V_42 * V_43 ,
struct V_82 * V_41 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_10 * V_11 =
F_34 ( V_47 ) ;
struct V_82 * V_83 = V_11 -> V_83 ;
if ( V_41 -> V_90 & V_91 )
return V_92 ;
if ( V_41 -> V_90 & V_93 )
return V_94 ;
if ( V_83 ) {
if ( V_41 -> V_67 != V_83 -> V_67 )
return V_95 ;
if ( V_41 -> V_68 != V_83 -> V_68 )
return V_95 ;
}
return V_96 ;
}
static void F_38 ( struct V_42 * V_43 , int V_41 )
{
if ( V_41 == V_43 -> V_97 )
return;
F_39 ( V_43 , V_41 ) ;
}
static struct V_53 * F_40 (
struct V_42 * V_43 )
{
struct V_46 * V_47 =
V_46 ( V_43 ) ;
struct V_10 * V_11 =
F_34 ( V_47 ) ;
return & V_11 -> V_54 -> V_98 . V_98 ;
}
static int F_41 ( struct V_4 * V_5 ,
struct V_10 * V_99 , int V_12 )
{
if ( ! V_5 || ! V_99 ) {
F_5 ( L_12 ) ;
return - V_2 ;
}
V_99 -> V_100 = 24 ;
if ( F_10 ( V_5 , V_12 ) == V_101 )
V_99 -> V_102 = 4 ;
else
V_99 -> V_102 = 2 ;
V_99 -> V_103 = 0 ;
if ( F_10 ( V_5 , V_12 ) == V_34 )
V_99 -> V_104 = V_105 ;
else if ( F_10 ( V_5 , V_12 ) == V_101 )
V_99 -> V_104 =
V_106 ;
else
V_99 -> V_104 = V_107 ;
return 0 ;
}
int F_42 ( int V_12 )
{
unsigned V_108 ;
int V_109 = 0 ;
switch ( V_12 ) {
case 0 :
V_108 = 128 ;
break;
case 2 :
V_108 = 34 ;
break;
default:
F_5 ( L_13 ) ;
return - V_2 ;
}
V_109 = F_43 ( V_108 , L_14 ) ;
if ( V_109 ) {
F_5 ( L_15 ) ;
return V_109 ;
}
V_109 = F_44 ( V_108 , 1 ) ;
if ( V_109 ) {
F_5 ( L_16 ) ;
goto V_110;
}
F_45 ( 128 ) ;
V_110:
if ( F_46 ( V_108 ) )
F_47 ( V_108 ) ;
return V_109 ;
}
void F_48 ( struct V_4 * V_5 ,
int V_12 ,
const struct V_111 * V_112 )
{
struct V_10 * V_11 ;
struct V_46 * V_47 ;
struct V_42 * V_43 ;
struct V_113 * V_54 ;
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_114 V_115 ;
T_2 V_116 , V_117 ;
F_11 ( V_5 -> V_5 , L_17 , V_12 ) ;
if ( ! V_5 || ( ( V_12 != 0 ) && ( V_12 != 2 ) ) ) {
F_5 ( L_5 ) ;
return;
}
V_47 = F_49 ( sizeof( struct V_46 ) , V_118 ) ;
if ( ! V_47 ) {
F_5 ( L_18 ) ;
return;
}
V_47 -> V_12 = V_12 ;
V_11 = F_49 ( sizeof( struct V_10 ) ,
V_118 ) ;
if ( ! V_11 ) {
F_5 ( L_19 ) ;
goto V_119;
}
F_41 ( V_5 , V_11 , V_12 ) ;
V_47 -> V_120 = V_11 ;
V_11 -> V_121 = 1 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_83 = V_112 -> V_122 ( V_5 ) ;
if ( V_112 -> V_123 ( V_5 , V_12 , & V_115 ) )
goto V_119;
V_116 = V_115 . V_116 ;
V_117 = V_115 . V_117 ;
V_11 -> V_41 = V_11 -> V_83 ;
V_11 -> V_43 = V_47 ;
if ( ! V_11 -> V_83 ) {
F_5 ( L_20 ) ;
goto V_119;
}
if ( V_12 && V_16 -> V_35 [ 0 ] ) {
V_11 -> V_124 = 0 ;
V_16 -> V_35 [ 1 ] = V_11 ;
} else if ( V_12 == 0 ) {
V_11 -> V_124 = 1 ;
V_16 -> V_35 [ 0 ] = V_11 ;
} else {
F_5 ( L_21 ) ;
goto V_119;
}
V_43 = & V_47 -> V_98 . V_98 ;
F_50 ( V_5 , V_43 , & V_125 ,
V_126 ) ;
F_51 ( V_43 , & V_127 ) ;
V_43 -> V_85 . V_128 = V_129 ;
V_43 -> V_85 . V_116 = V_116 ;
V_43 -> V_85 . V_117 = V_117 ;
V_43 -> V_130 = false ;
V_43 -> V_131 = false ;
F_52 ( V_43 ,
V_5 -> V_132 . V_133 ,
V_62 ) ;
F_52 ( V_43 ,
V_16 -> V_134 ,
V_36 ) ;
if ( F_53 ( V_47 , V_12 ) ) {
F_5 ( L_22 ,
V_12 ) ;
goto V_119;
}
V_54 = F_54 ( V_5 , V_47 , V_112 ) ;
if ( ! V_54 ) {
F_5 ( L_23 ) ;
goto V_135;
}
V_54 -> V_120 = V_11 ;
V_11 -> V_54 = V_54 ;
V_54 -> V_98 . type = ( V_12 == 0 ) ? V_136 :
V_137 ;
F_55 ( V_43 ) ;
return;
V_135:
F_31 ( V_47 -> V_81 ) ;
F_30 ( V_43 ) ;
F_32 ( V_11 -> V_83 ) ;
F_32 ( V_11 ) ;
V_119:
F_32 ( V_47 ) ;
}
