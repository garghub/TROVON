static void F_1 ( int V_1 , char * V_2 )
{
struct V_3 V_4 ;
if ( V_1 < 0 )
return;
F_2 ( V_1 , & V_4 ) ;
F_3 ( V_5 L_1 ,
V_2 , V_1 , V_4 . V_6 , V_4 . V_7 , V_4 . V_8 , V_4 . V_9 ) ;
F_3 ( V_5 L_2 ,
V_4 . V_10 , V_4 . V_11 , V_4 . V_12 , V_4 . V_13 ) ;
}
static void F_1 ( int V_1 , char * V_2 )
{
}
static void F_4 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
struct V_20 * V_18 = V_15 -> V_18 ;
V_17 -> V_21 ++ ;
if ( F_5 ( V_17 -> V_21 >= V_18 -> V_22 ) )
V_17 -> V_21 = 0 ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
V_17 -> V_21 = 0 ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
struct V_20 * V_18 = V_15 -> V_18 ;
unsigned int V_23 ;
unsigned int V_24 ;
T_1 V_25 ;
T_1 V_7 , V_9 ;
unsigned short V_26 , V_27 ;
unsigned short V_28 , V_29 ;
unsigned int V_30 ;
unsigned short V_31 ;
unsigned int V_32 ;
unsigned int V_33 ;
V_23 = F_8 ( V_15 ) ;
V_24 = V_17 -> V_21 * V_23 ;
V_25 = V_18 -> V_34 + V_24 ;
V_33 = V_17 -> V_35 -> V_33 ;
F_9 ( L_3
L_4 , V_17 -> V_36 [ 0 ] , V_25 ,
V_23 ) ;
V_30 = V_17 -> V_35 -> V_30 ;
V_32 = V_23 / V_30 ;
if ( V_33 )
V_32 /= V_33 ;
if ( V_15 -> V_37 == V_38 ) {
V_7 = V_25 ;
V_9 = V_17 -> V_35 -> V_34 ;
V_26 = V_30 ;
V_27 = 4 ;
V_28 = V_30 * V_33 ;
V_29 = 0 ;
} else {
V_7 = V_17 -> V_35 -> V_34 ;
V_9 = V_25 ;
V_26 = 0 ;
V_27 = V_30 ;
V_28 = 0 ;
V_29 = V_30 * V_33 ;
}
V_31 = V_17 -> V_35 -> V_31 ;
F_10 ( V_17 -> V_36 [ 0 ] , V_7 , V_39 , V_40 ) ;
F_11 ( V_17 -> V_36 [ 0 ] , V_9 , V_39 , V_40 ) ;
F_12 ( V_17 -> V_36 [ 0 ] , V_26 , V_28 ) ;
F_13 ( V_17 -> V_36 [ 0 ] , V_27 , V_29 ) ;
if ( ! V_33 )
F_14 ( V_17 -> V_36 [ 0 ] , V_31 , V_32 , 1 , 0 ,
V_41 ) ;
else
F_14 ( V_17 -> V_36 [ 0 ] , V_31 ,
V_33 ,
V_32 , V_33 ,
V_42 ) ;
}
static void F_15 ( unsigned V_43 , T_2 V_44 , void * V_45 )
{
struct V_14 * V_15 = V_45 ;
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
F_1 ( V_17 -> V_46 , L_5 ) ;
F_9 ( L_6 , V_43 , V_44 ) ;
if ( F_5 ( V_44 != V_47 ) )
return;
if ( F_16 ( V_15 ) ) {
F_17 ( & V_17 -> V_48 ) ;
if ( V_17 -> V_46 < 0 ) {
F_7 ( V_15 ) ;
}
F_4 ( V_15 ) ;
F_18 ( & V_17 -> V_48 ) ;
F_19 ( V_15 ) ;
}
}
static int F_20 ( struct V_14 * V_15 ,
struct V_49 * V_50 , unsigned V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = & V_15 -> V_56 ;
struct V_54 * V_57 = NULL ;
T_1 V_58 = 0 ;
void * V_59 = NULL ;
if ( V_55 -> V_19 || ! V_51 )
return 0 ;
V_53 -> V_60 = V_51 ;
V_59 = F_21 ( V_50 , V_51 , & V_58 ) ;
if ( ! V_59 )
goto V_61;
V_57 = F_22 ( sizeof( * V_57 ) , V_62 ) ;
if ( ! V_57 )
goto V_63;
V_57 -> V_64 = V_59 ;
V_57 -> V_65 = V_58 ;
memset ( V_57 -> V_64 , 0 , V_51 ) ;
V_57 -> V_66 = V_51 ;
V_55 -> V_19 = V_57 ;
return 0 ;
V_63:
if ( V_59 )
F_23 ( V_50 , ( unsigned ) V_59 , V_51 ) ;
V_61:
return - V_67 ;
}
static void F_24 ( struct V_14 * V_15 ,
struct V_54 * V_57 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
struct V_49 * V_50 = V_17 -> V_35 -> V_50 ;
F_23 ( V_50 , ( unsigned ) V_57 -> V_64 , V_57 -> V_66 ) ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_49 * V_50 , unsigned V_51 ,
struct V_52 * V_53 )
{
return 0 ;
}
static void F_24 ( struct V_14 * V_15 ,
struct V_54 * V_57 )
{
}
static int F_25 ( struct V_14 * V_15 )
{
unsigned short V_68 , V_69 ;
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 = V_18 -> V_19 ;
struct V_54 * V_57 =
(struct V_54 * ) V_15 -> V_56 . V_19 ;
struct V_70 * V_35 = V_17 -> V_35 ;
unsigned int V_30 = V_35 -> V_30 ;
unsigned int V_31 = V_35 -> V_31 ;
unsigned int V_71 = F_8 ( V_15 ) >> 1 ;
unsigned int V_33 = V_17 -> V_35 -> V_33 ;
unsigned int V_32 ;
if ( ( V_30 == 0 ) || ( V_30 > 4 ) ) {
F_3 ( V_72 L_7 , V_73 , V_30 ) ;
return - V_74 ;
}
if ( V_15 -> V_37 == V_38 ) {
T_1 V_75 = V_57 -> V_65 + V_71 ;
V_68 = V_71 ;
V_69 = - V_71 ;
F_10 ( V_17 -> V_36 [ 1 ] , V_75 , V_39 , V_40 ) ;
F_12 ( V_17 -> V_36 [ 0 ] , V_30 ,
V_30 * V_33 ) ;
F_12 ( V_17 -> V_36 [ 1 ] , V_30 ,
V_30 * V_33 ) ;
F_10 ( V_17 -> V_76 , V_18 -> V_34 , V_39 , V_77 ) ;
} else {
T_1 V_78 = V_57 -> V_65 + V_71 ;
V_68 = - V_71 ;
V_69 = V_71 ;
F_11 ( V_17 -> V_36 [ 1 ] , V_78 , V_39 , V_40 ) ;
F_13 ( V_17 -> V_36 [ 0 ] , V_30 ,
V_30 * V_33 ) ;
F_13 ( V_17 -> V_36 [ 1 ] , V_30 ,
V_30 * V_33 ) ;
F_11 ( V_17 -> V_76 , V_18 -> V_34 , V_39 , V_77 ) ;
}
if ( ! V_33 ) {
V_32 = V_71 / V_30 ;
F_14 ( V_17 -> V_36 [ 0 ] , V_31 , V_32 ,
1 , 0 , V_41 ) ;
F_14 ( V_17 -> V_36 [ 1 ] , V_31 , V_32 ,
1 , 0 , V_41 ) ;
} else {
V_32 = V_71 / ( V_30 * V_33 ) ;
F_14 ( V_17 -> V_36 [ 0 ] , V_31 , V_33 ,
V_32 , V_33 , V_42 ) ;
F_14 ( V_17 -> V_36 [ 1 ] , V_31 , V_33 ,
V_32 , V_33 , V_42 ) ;
}
F_12 ( V_17 -> V_76 , V_71 , V_68 ) ;
F_13 ( V_17 -> V_76 , V_71 , V_69 ) ;
F_14 ( V_17 -> V_76 , V_71 , 2 ,
V_18 -> V_22 , 2 , V_41 ) ;
F_2 ( V_17 -> V_36 [ 0 ] , & V_17 -> V_79 ) ;
F_2 ( V_17 -> V_76 , & V_17 -> V_80 ) ;
if ( V_15 -> V_37 == V_38 ) {
struct V_3 V_81 ;
V_17 -> V_80 . V_8 = ( 1 << 16 ) | ( V_71 << 1 ) ;
V_17 -> V_80 . V_10 = ( V_71 << 1 ) ;
V_17 -> V_80 . V_12 = ( V_71 << 1 ) ;
V_17 -> V_80 . V_13 = 1 ;
F_2 ( V_17 -> V_76 , & V_81 ) ;
V_81 . V_7 += ( V_71 << 1 ) ;
V_81 . V_13 -= 1 ;
F_26 ( V_17 -> V_82 , & V_81 ) ;
V_17 -> V_80 . V_11 =
F_27 ( V_17 -> V_82 ) << 5 ;
}
return 0 ;
}
static int F_28 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_54 * V_57 )
{
T_1 V_83 ;
T_1 V_84 ;
int V_85 ;
struct V_70 * V_35 = V_17 -> V_35 ;
V_85 = V_17 -> V_46 = F_29 ( V_86 ,
F_15 , V_15 ,
V_17 -> V_35 -> V_87 ) ;
if ( V_85 < 0 )
goto V_61;
V_85 = V_17 -> V_76 = F_30 (
F_31 ( V_17 -> V_46 ) , V_88 ) ;
if ( V_85 < 0 )
goto V_63;
V_85 = V_17 -> V_36 [ 1 ] = F_30 (
F_31 ( V_17 -> V_89 ) , V_88 ) ;
if ( V_85 < 0 )
goto V_90;
V_17 -> V_82 = - 1 ;
if ( V_15 -> V_37 == V_38 ) {
V_85 = V_17 -> V_82 = F_30 (
F_31 ( V_17 -> V_46 ) , V_88 ) ;
if ( V_85 < 0 )
goto V_91;
}
F_32 ( V_17 -> V_36 [ 0 ] , V_17 -> V_36 [ 1 ] ) ;
F_32 ( V_17 -> V_36 [ 1 ] , V_17 -> V_36 [ 0 ] ) ;
F_32 ( V_17 -> V_76 , V_17 -> V_76 ) ;
if ( V_15 -> V_37 == V_38 ) {
V_83 = V_57 -> V_65 ;
V_84 = V_35 -> V_34 ;
} else {
V_83 = V_35 -> V_34 ;
V_84 = V_57 -> V_65 ;
}
F_10 ( V_17 -> V_36 [ 0 ] , V_83 , V_39 , V_92 ) ;
F_11 ( V_17 -> V_36 [ 0 ] , V_84 , V_39 , V_92 ) ;
F_12 ( V_17 -> V_36 [ 0 ] , 0 , 0 ) ;
F_13 ( V_17 -> V_36 [ 0 ] , 0 , 0 ) ;
F_2 ( V_17 -> V_36 [ 0 ] , & V_17 -> V_79 ) ;
V_17 -> V_79 . V_6 &= ~ ( V_93 | F_33 ( 0x3f ) | V_94 ) ;
V_17 -> V_79 . V_6 |= V_95 |
F_33 ( V_17 -> V_46 & 0x3f ) ;
F_26 ( V_17 -> V_36 [ 0 ] , & V_17 -> V_79 ) ;
F_10 ( V_17 -> V_36 [ 1 ] , V_83 , V_39 , V_92 ) ;
F_11 ( V_17 -> V_36 [ 1 ] , V_84 , V_39 , V_92 ) ;
F_12 ( V_17 -> V_36 [ 1 ] , 0 , 0 ) ;
F_13 ( V_17 -> V_36 [ 1 ] , 0 , 0 ) ;
F_2 ( V_17 -> V_36 [ 1 ] , & V_17 -> V_79 ) ;
V_17 -> V_79 . V_6 &= ~ ( V_93 | F_33 ( 0x3f ) ) ;
V_17 -> V_79 . V_6 |= V_94 | V_95 |
F_33 ( V_17 -> V_46 & 0x3f ) ;
F_26 ( V_17 -> V_36 [ 1 ] , & V_17 -> V_79 ) ;
F_10 ( V_17 -> V_76 , V_57 -> V_65 , V_39 , V_77 ) ;
F_11 ( V_17 -> V_76 , V_57 -> V_65 , V_39 , V_77 ) ;
F_9 ( L_8
L_9 , V_73 ,
V_17 -> V_46 , V_17 -> V_76 , V_17 -> V_82 ,
V_17 -> V_89 , V_17 -> V_36 [ 0 ] ,
V_17 -> V_36 [ 1 ] ) ;
return 0 ;
V_91:
F_34 ( V_17 -> V_36 [ 1 ] ) ;
V_17 -> V_36 [ 1 ] = - 1 ;
V_90:
F_34 ( V_17 -> V_76 ) ;
V_17 -> V_76 = - 1 ;
V_63:
F_34 ( V_17 -> V_46 ) ;
V_17 -> V_46 = - 1 ;
V_61:
return V_85 ;
}
static int F_35 ( struct V_14 * V_15 )
{
struct V_54 * V_57 ;
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
struct V_70 * V_35 = V_17 -> V_35 ;
int V_85 ;
if ( ! V_35 )
return - V_96 ;
V_85 = V_17 -> V_89 = F_29 ( V_35 -> V_97 ,
F_15 , V_15 ,
V_17 -> V_35 -> V_98 ) ;
if ( V_85 < 0 )
goto V_61;
V_85 = V_17 -> V_36 [ 0 ] = F_30 (
F_31 ( V_17 -> V_89 ) , V_88 ) ;
if ( V_85 < 0 )
goto V_63;
V_57 = (struct V_54 * ) V_15 -> V_56 . V_19 ;
if ( V_57 ) {
if ( F_28 ( V_15 , V_17 , V_57 ) == 0 )
return 0 ;
F_3 ( V_99 L_10
L_11 , V_73 ) ;
}
F_2 ( V_17 -> V_36 [ 0 ] , & V_17 -> V_79 ) ;
V_17 -> V_79 . V_6 |= V_94 |
F_33 ( F_27 ( V_17 -> V_89 ) ) ;
V_17 -> V_79 . V_11 = F_27 ( V_17 -> V_36 [ 0 ] ) << 5 ;
F_26 ( V_17 -> V_36 [ 0 ] , & V_17 -> V_79 ) ;
return 0 ;
V_63:
F_34 ( V_17 -> V_89 ) ;
V_17 -> V_89 = - 1 ;
V_61:
return V_85 ;
}
static int F_36 ( struct V_14 * V_15 , int V_100 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
int V_85 = 0 ;
F_17 ( & V_17 -> V_48 ) ;
switch ( V_100 ) {
case V_101 :
F_37 ( V_17 -> V_89 ) ;
if ( V_15 -> V_37 == V_38 &&
V_17 -> V_46 >= 0 ) {
F_37 ( V_17 -> V_46 ) ;
}
break;
case V_102 :
case V_103 :
F_38 ( V_17 -> V_89 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
F_39 ( V_17 -> V_89 ) ;
break;
default:
V_85 = - V_74 ;
break;
}
F_18 ( & V_17 -> V_48 ) ;
return V_85 ;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
F_6 ( V_15 ) ;
if ( V_17 -> V_46 >= 0 ) {
int V_85 = F_25 ( V_15 ) ;
if ( V_85 < 0 )
return V_85 ;
F_26 ( V_17 -> V_46 , & V_17 -> V_80 ) ;
F_26 ( V_17 -> V_89 , & V_17 -> V_79 ) ;
F_1 ( V_17 -> V_46 , L_12 ) ;
F_1 ( V_17 -> V_76 , L_13 ) ;
F_1 ( V_17 -> V_82 , L_14 ) ;
F_1 ( V_17 -> V_89 , L_15 ) ;
F_1 ( V_17 -> V_36 [ 0 ] , L_16 ) ;
F_1 ( V_17 -> V_36 [ 1 ] , L_17 ) ;
F_4 ( V_15 ) ;
F_4 ( V_15 ) ;
return 0 ;
}
F_7 ( V_15 ) ;
F_4 ( V_15 ) ;
F_2 ( V_17 -> V_36 [ 0 ] , & V_17 -> V_79 ) ;
F_26 ( V_17 -> V_89 , & V_17 -> V_79 ) ;
F_7 ( V_15 ) ;
F_4 ( V_15 ) ;
return 0 ;
}
static T_3
F_41 ( struct V_14 * V_15 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 = V_18 -> V_19 ;
unsigned int V_107 ;
int V_108 ;
unsigned int V_23 = F_8 ( V_15 ) ;
F_17 ( & V_17 -> V_48 ) ;
V_108 = V_17 -> V_21 - 2 ;
F_18 ( & V_17 -> V_48 ) ;
if ( V_108 < 0 )
V_108 += V_18 -> V_22 ;
V_108 *= V_23 ;
V_107 = F_42 ( V_18 , V_108 ) ;
if ( V_107 >= V_18 -> V_109 )
V_107 = 0 ;
return V_107 ;
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 ;
struct V_52 * V_53 ;
int V_85 = 0 ;
struct V_110 * V_111 = V_15 -> V_19 ;
struct V_70 * V_112 ;
struct V_70 * V_35 ;
V_112 = F_44 ( V_111 -> V_113 , V_15 ) ;
if ( ! V_112 )
return - V_96 ;
V_35 = & V_112 [ V_15 -> V_37 ] ;
V_53 = ( V_15 -> V_37 == V_38 ) ?
& V_114 : & V_115 ;
F_20 ( V_15 , V_35 -> V_50 , V_35 -> V_116 , V_53 ) ;
F_45 ( V_15 , V_53 ) ;
V_85 = F_46 ( V_18 ,
V_117 ) ;
if ( V_85 < 0 )
return V_85 ;
V_17 = F_22 ( sizeof( struct V_16 ) , V_62 ) ;
if ( V_17 == NULL )
return - V_67 ;
F_47 ( & V_17 -> V_48 ) ;
V_17 -> V_35 = V_35 ;
V_17 -> V_89 = - 1 ;
V_17 -> V_36 [ 0 ] = V_17 -> V_36 [ 1 ] = - 1 ;
V_17 -> V_46 = - 1 ;
V_17 -> V_76 = - 1 ;
V_17 -> V_82 = - 1 ;
V_18 -> V_19 = V_17 ;
V_85 = F_35 ( V_15 ) ;
if ( V_85 ) {
F_3 ( V_72 L_18 ) ;
F_48 ( V_17 ) ;
}
return V_85 ;
}
static int F_49 ( struct V_14 * V_15 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 = V_18 -> V_19 ;
if ( V_17 -> V_46 >= 0 )
F_50 ( V_17 -> V_46 ) ;
if ( V_17 -> V_89 >= 0 )
F_50 ( V_17 -> V_89 ) ;
if ( V_17 -> V_36 [ 0 ] >= 0 )
F_51 ( V_17 -> V_36 [ 0 ] ) ;
if ( V_17 -> V_36 [ 1 ] >= 0 )
F_51 ( V_17 -> V_36 [ 1 ] ) ;
if ( V_17 -> V_76 >= 0 )
F_51 ( V_17 -> V_76 ) ;
if ( V_17 -> V_36 [ 0 ] >= 0 )
F_52 ( V_17 -> V_36 [ 0 ] ) ;
if ( V_17 -> V_36 [ 1 ] >= 0 )
F_52 ( V_17 -> V_36 [ 1 ] ) ;
if ( V_17 -> V_89 >= 0 )
F_34 ( V_17 -> V_89 ) ;
if ( V_17 -> V_76 >= 0 )
F_52 ( V_17 -> V_76 ) ;
if ( V_17 -> V_82 >= 0 )
F_52 ( V_17 -> V_82 ) ;
if ( V_17 -> V_46 >= 0 )
F_34 ( V_17 -> V_46 ) ;
F_48 ( V_17 ) ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 ,
struct V_118 * V_119 )
{
return F_54 ( V_15 ,
F_55 ( V_119 ) ) ;
}
static int F_56 ( struct V_14 * V_15 )
{
return F_57 ( V_15 ) ;
}
static int F_58 ( struct V_14 * V_15 ,
struct V_120 * V_121 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
return F_59 ( V_15 -> V_122 -> V_123 -> V_124 , V_121 ,
V_18 -> V_125 ,
V_18 -> V_34 ,
V_18 -> V_126 ) ;
}
static int F_60 ( struct V_127 * V_122 , int V_37 ,
T_4 V_51 )
{
struct V_14 * V_15 = V_122 -> V_128 [ V_37 ] . V_15 ;
struct V_54 * V_55 = & V_15 -> V_56 ;
V_55 -> V_124 . type = V_129 ;
V_55 -> V_124 . V_124 = V_122 -> V_123 -> V_124 ;
V_55 -> V_19 = NULL ;
V_55 -> V_64 = F_61 ( V_122 -> V_123 -> V_124 , V_51 ,
& V_55 -> V_65 , V_62 ) ;
F_9 ( L_19
L_20 , ( void * ) V_55 -> V_64 , ( void * ) V_55 -> V_65 , V_51 ) ;
if ( ! V_55 -> V_64 )
return - V_67 ;
V_55 -> V_66 = V_51 ;
return 0 ;
}
static void F_62 ( struct V_127 * V_122 )
{
struct V_14 * V_15 ;
struct V_54 * V_55 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
struct V_54 * V_57 ;
V_15 = V_122 -> V_128 [ V_37 ] . V_15 ;
if ( ! V_15 )
continue;
V_55 = & V_15 -> V_56 ;
if ( ! V_55 -> V_64 )
continue;
F_63 ( V_122 -> V_123 -> V_124 , V_55 -> V_66 ,
V_55 -> V_64 , V_55 -> V_65 ) ;
V_55 -> V_64 = NULL ;
V_57 = V_55 -> V_19 ;
if ( V_57 ) {
F_24 ( V_15 , V_57 ) ;
F_48 ( V_57 ) ;
}
}
}
static int F_64 ( struct V_110 * V_111 )
{
struct V_130 * V_123 = V_111 -> V_123 -> V_130 ;
struct V_127 * V_122 = V_111 -> V_122 ;
int V_85 ;
V_85 = F_65 ( V_123 -> V_124 , F_66 ( 32 ) ) ;
if ( V_85 )
return V_85 ;
if ( V_122 -> V_128 [ V_38 ] . V_15 ) {
V_85 = F_60 ( V_122 ,
V_38 ,
V_114 . V_131 ) ;
if ( V_85 )
return V_85 ;
}
if ( V_122 -> V_128 [ V_132 ] . V_15 ) {
V_85 = F_60 ( V_122 ,
V_132 ,
V_115 . V_131 ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
int F_67 ( struct V_133 * V_124 )
{
return F_68 ( V_124 , & V_134 ) ;
}
