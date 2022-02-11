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
int V_23 = V_17 -> V_24 [ 0 ] ;
unsigned int V_25 ;
unsigned int V_26 ;
T_1 V_27 ;
T_1 V_7 , V_9 ;
unsigned short V_28 , V_29 ;
unsigned short V_30 , V_31 ;
unsigned int V_32 ;
unsigned short V_33 ;
unsigned int V_34 ;
unsigned int V_35 ;
V_25 = F_8 ( V_15 ) ;
V_26 = V_17 -> V_21 * V_25 ;
V_27 = V_18 -> V_36 + V_26 ;
V_35 = V_17 -> V_37 -> V_35 ;
F_9 ( L_3
L_4 , V_23 , V_27 , V_25 ) ;
V_32 = V_17 -> V_37 -> V_32 ;
V_34 = V_25 / V_32 ;
if ( V_35 )
V_34 /= V_35 ;
if ( V_15 -> V_38 == V_39 ) {
V_7 = V_27 ;
V_9 = V_17 -> V_37 -> V_36 ;
V_28 = V_32 ;
V_29 = 0 ;
V_30 = V_32 * V_35 ;
V_31 = 0 ;
} else {
V_7 = V_17 -> V_37 -> V_36 ;
V_9 = V_27 ;
V_28 = 0 ;
V_29 = V_32 ;
V_30 = 0 ;
V_31 = V_32 * V_35 ;
}
V_33 = V_17 -> V_37 -> V_33 ;
F_10 ( V_23 , V_7 , V_40 , V_41 ) ;
F_11 ( V_23 , V_9 , V_40 , V_41 ) ;
F_12 ( V_23 , V_28 , V_30 ) ;
F_13 ( V_23 , V_29 , V_31 ) ;
if ( ! V_35 )
F_14 ( V_23 , V_33 , V_34 , 1 , 0 , V_42 ) ;
else
F_14 ( V_23 , V_33 , V_35 , V_34 ,
V_35 , V_43 ) ;
}
static void F_15 ( unsigned V_23 , T_2 V_44 , void * V_45 )
{
struct V_14 * V_15 = V_45 ;
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
F_1 ( V_17 -> V_46 , L_5 ) ;
F_9 ( L_6 , V_23 , V_44 ) ;
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
static int F_20 ( struct V_14 * V_15 , unsigned V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = & V_15 -> V_54 ;
struct V_52 * V_55 = NULL ;
T_1 V_56 = 0 ;
void * V_57 = NULL ;
if ( V_53 -> V_19 || ! V_49 )
return 0 ;
V_51 -> V_58 = V_49 ;
V_57 = F_21 ( V_49 , & V_56 ) ;
if ( ! V_57 )
goto V_59;
V_55 = F_22 ( sizeof( * V_55 ) , V_60 ) ;
if ( ! V_55 )
goto V_61;
V_55 -> V_62 = V_57 ;
V_55 -> V_63 = V_56 ;
memset ( V_55 -> V_62 , 0 , V_49 ) ;
V_55 -> V_64 = V_49 ;
V_53 -> V_19 = V_55 ;
return 0 ;
V_61:
if ( V_57 )
F_23 ( V_57 , V_49 ) ;
V_59:
return - V_65 ;
}
static int F_24 ( struct V_14 * V_15 )
{
unsigned short V_66 , V_67 ;
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 = V_18 -> V_19 ;
struct V_52 * V_55 =
(struct V_52 * ) V_15 -> V_54 . V_19 ;
struct V_68 * V_37 = V_17 -> V_37 ;
unsigned int V_32 = V_37 -> V_32 ;
unsigned int V_33 = V_37 -> V_33 ;
unsigned int V_69 = F_8 ( V_15 ) >> 1 ;
int V_23 = V_17 -> V_24 [ 1 ] ;
unsigned int V_35 = V_17 -> V_37 -> V_35 ;
unsigned int V_34 ;
if ( ( V_32 == 0 ) || ( V_32 > 4 ) ) {
F_3 ( V_70 L_7 , V_71 , V_32 ) ;
return - V_72 ;
}
if ( V_15 -> V_38 == V_39 ) {
T_1 V_73 = V_55 -> V_63 + V_69 ;
V_66 = V_69 ;
V_67 = - V_69 ;
F_10 ( V_23 , V_73 , V_40 , V_41 ) ;
V_23 = V_17 -> V_24 [ 0 ] ;
F_12 ( V_23 , V_32 , V_32 * V_35 ) ;
V_23 = V_17 -> V_24 [ 1 ] ;
F_12 ( V_23 , V_32 , V_32 * V_35 ) ;
V_23 = V_17 -> V_74 ;
F_10 ( V_23 , V_18 -> V_36 , V_40 , V_75 ) ;
} else {
T_1 V_76 = V_55 -> V_63 + V_69 ;
V_66 = - V_69 ;
V_67 = V_69 ;
F_11 ( V_23 , V_76 , V_40 , V_41 ) ;
V_23 = V_17 -> V_24 [ 0 ] ;
F_13 ( V_23 , V_32 , V_32 * V_35 ) ;
V_23 = V_17 -> V_24 [ 1 ] ;
F_13 ( V_23 , V_32 , V_32 * V_35 ) ;
V_23 = V_17 -> V_74 ;
F_11 ( V_23 , V_18 -> V_36 , V_40 , V_75 ) ;
}
if ( ! V_35 ) {
V_34 = V_69 / V_32 ;
F_14 ( V_17 -> V_24 [ 0 ] , V_33 , V_34 ,
1 , 0 , V_42 ) ;
F_14 ( V_17 -> V_24 [ 1 ] , V_33 , V_34 ,
1 , 0 , V_42 ) ;
} else {
V_34 = V_69 / ( V_32 * V_35 ) ;
F_14 ( V_17 -> V_24 [ 0 ] , V_33 , V_35 ,
V_34 , V_35 , V_43 ) ;
F_14 ( V_17 -> V_24 [ 1 ] , V_33 , V_35 ,
V_34 , V_35 , V_43 ) ;
}
V_23 = V_17 -> V_74 ;
F_12 ( V_23 , V_69 , V_66 ) ;
F_13 ( V_23 , V_69 , V_67 ) ;
F_14 ( V_23 , V_69 , 2 ,
V_18 -> V_22 , 2 , V_42 ) ;
F_2 ( V_17 -> V_24 [ 0 ] , & V_17 -> V_77 ) ;
F_2 ( V_17 -> V_74 , & V_17 -> V_78 ) ;
if ( V_15 -> V_38 == V_39 ) {
struct V_3 V_79 ;
V_17 -> V_78 . V_8 = ( 1 << 16 ) | ( V_69 << 1 ) ;
V_17 -> V_78 . V_10 = ( V_69 << 1 ) ;
V_17 -> V_78 . V_12 = ( V_69 << 1 ) ;
V_17 -> V_78 . V_13 = 1 ;
F_2 ( V_17 -> V_74 , & V_79 ) ;
V_79 . V_7 += ( V_69 << 1 ) ;
V_79 . V_13 -= 1 ;
F_25 ( V_17 -> V_80 , & V_79 ) ;
V_17 -> V_78 . V_11 =
F_26 ( V_17 -> V_80 ) << 5 ;
}
return 0 ;
}
static int F_27 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_52 * V_55 )
{
T_1 V_81 ;
T_1 V_82 ;
int V_23 ;
struct V_68 * V_37 = V_17 -> V_37 ;
V_23 = V_17 -> V_46 = F_28 ( V_83 ,
F_15 , V_15 ,
V_17 -> V_37 -> V_84 ) ;
if ( V_23 < 0 )
goto V_59;
V_23 = V_17 -> V_74 = F_29 (
F_30 ( V_17 -> V_46 ) , V_85 ) ;
if ( V_23 < 0 )
goto V_61;
V_23 = V_17 -> V_24 [ 1 ] = F_29 (
F_30 ( V_17 -> V_86 ) , V_85 ) ;
if ( V_23 < 0 )
goto V_87;
V_17 -> V_80 = - 1 ;
if ( V_15 -> V_38 == V_39 ) {
V_23 = V_17 -> V_80 = F_29 (
F_30 ( V_17 -> V_46 ) , V_85 ) ;
if ( V_23 < 0 )
goto V_88;
}
F_31 ( V_17 -> V_24 [ 0 ] , V_17 -> V_24 [ 1 ] ) ;
F_31 ( V_17 -> V_24 [ 1 ] , V_17 -> V_24 [ 0 ] ) ;
F_31 ( V_17 -> V_74 , V_17 -> V_74 ) ;
if ( V_15 -> V_38 == V_39 ) {
V_81 = V_55 -> V_63 ;
V_82 = V_37 -> V_36 ;
} else {
V_81 = V_37 -> V_36 ;
V_82 = V_55 -> V_63 ;
}
V_23 = V_17 -> V_24 [ 0 ] ;
F_10 ( V_23 , V_81 , V_40 , V_89 ) ;
F_11 ( V_23 , V_82 , V_40 , V_89 ) ;
F_12 ( V_23 , 0 , 0 ) ;
F_13 ( V_23 , 0 , 0 ) ;
F_2 ( V_23 , & V_17 -> V_77 ) ;
V_17 -> V_77 . V_6 &= ~ ( V_90 | F_32 ( 0x3f ) | V_91 ) ;
V_17 -> V_77 . V_6 |= V_92 |
F_32 ( V_17 -> V_46 & 0x3f ) ;
F_25 ( V_23 , & V_17 -> V_77 ) ;
V_23 = V_17 -> V_24 [ 1 ] ;
F_10 ( V_23 , V_81 , V_40 , V_89 ) ;
F_11 ( V_23 , V_82 , V_40 , V_89 ) ;
F_12 ( V_23 , 0 , 0 ) ;
F_13 ( V_23 , 0 , 0 ) ;
F_2 ( V_23 , & V_17 -> V_77 ) ;
V_17 -> V_77 . V_6 &= ~ ( V_90 | F_32 ( 0x3f ) ) ;
V_17 -> V_77 . V_6 |= V_91 | V_92 |
F_32 ( V_17 -> V_46 & 0x3f ) ;
F_25 ( V_23 , & V_17 -> V_77 ) ;
V_23 = V_17 -> V_74 ;
F_10 ( V_23 , V_55 -> V_63 , V_40 , V_75 ) ;
F_11 ( V_23 , V_55 -> V_63 , V_40 , V_75 ) ;
F_9 ( L_8
L_9 , V_71 ,
V_17 -> V_46 , V_17 -> V_74 , V_17 -> V_80 ,
V_17 -> V_86 , V_17 -> V_24 [ 0 ] ,
V_17 -> V_24 [ 1 ] ) ;
return 0 ;
V_88:
F_33 ( V_17 -> V_24 [ 1 ] ) ;
V_17 -> V_24 [ 1 ] = - 1 ;
V_87:
F_33 ( V_17 -> V_74 ) ;
V_17 -> V_74 = - 1 ;
V_61:
F_33 ( V_17 -> V_46 ) ;
V_17 -> V_46 = - 1 ;
V_59:
return V_23 ;
}
static int F_34 ( struct V_14 * V_15 )
{
struct V_52 * V_55 ;
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
struct V_68 * V_37 = V_17 -> V_37 ;
int V_23 ;
if ( ! V_37 )
return - V_93 ;
V_23 = V_17 -> V_86 = F_28 ( V_37 -> V_94 ,
F_15 , V_15 ,
V_17 -> V_37 -> V_95 ) ;
if ( V_23 < 0 )
goto V_59;
V_23 = V_17 -> V_24 [ 0 ] = F_29 (
F_30 ( V_17 -> V_86 ) , V_85 ) ;
if ( V_23 < 0 )
goto V_61;
V_55 = (struct V_52 * ) V_15 -> V_54 . V_19 ;
if ( V_55 ) {
if ( F_27 ( V_15 , V_17 , V_55 ) == 0 )
return 0 ;
F_3 ( V_96 L_10
L_11 , V_71 ) ;
}
F_2 ( V_23 , & V_17 -> V_77 ) ;
V_17 -> V_77 . V_6 |= V_91 |
F_32 ( F_26 ( V_17 -> V_86 ) ) ;
V_17 -> V_77 . V_11 = F_26 ( V_23 ) << 5 ;
F_25 ( V_23 , & V_17 -> V_77 ) ;
return 0 ;
V_61:
F_33 ( V_17 -> V_86 ) ;
V_17 -> V_86 = - 1 ;
V_59:
return V_23 ;
}
static int F_35 ( struct V_14 * V_15 , int V_97 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
int V_98 = 0 ;
F_17 ( & V_17 -> V_48 ) ;
switch ( V_97 ) {
case V_99 :
F_36 ( V_17 -> V_86 ) ;
if ( V_15 -> V_38 == V_39 &&
V_17 -> V_46 >= 0 ) {
F_36 ( V_17 -> V_46 ) ;
}
break;
case V_100 :
case V_101 :
F_37 ( V_17 -> V_86 ) ;
break;
case V_102 :
case V_103 :
case V_104 :
F_38 ( V_17 -> V_86 ) ;
break;
default:
V_98 = - V_72 ;
break;
}
F_18 ( & V_17 -> V_48 ) ;
return V_98 ;
}
static int F_39 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 -> V_19 ;
F_6 ( V_15 ) ;
if ( V_17 -> V_46 >= 0 ) {
int V_98 = F_24 ( V_15 ) ;
if ( V_98 < 0 )
return V_98 ;
F_25 ( V_17 -> V_46 , & V_17 -> V_78 ) ;
F_25 ( V_17 -> V_86 , & V_17 -> V_77 ) ;
F_1 ( V_17 -> V_46 , L_12 ) ;
F_1 ( V_17 -> V_74 , L_13 ) ;
F_1 ( V_17 -> V_80 , L_14 ) ;
F_1 ( V_17 -> V_86 , L_15 ) ;
F_1 ( V_17 -> V_24 [ 0 ] , L_16 ) ;
F_1 ( V_17 -> V_24 [ 1 ] , L_17 ) ;
F_4 ( V_15 ) ;
F_4 ( V_15 ) ;
return 0 ;
}
F_7 ( V_15 ) ;
F_4 ( V_15 ) ;
F_2 ( V_17 -> V_24 [ 0 ] , & V_17 -> V_77 ) ;
F_25 ( V_17 -> V_86 , & V_17 -> V_77 ) ;
F_7 ( V_15 ) ;
F_4 ( V_15 ) ;
return 0 ;
}
static T_3
F_40 ( struct V_14 * V_15 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 = V_18 -> V_19 ;
unsigned int V_105 ;
int V_106 ;
unsigned int V_25 = F_8 ( V_15 ) ;
F_17 ( & V_17 -> V_48 ) ;
V_106 = V_17 -> V_21 - 2 ;
F_18 ( & V_17 -> V_48 ) ;
if ( V_106 < 0 )
V_106 += V_18 -> V_22 ;
V_106 *= V_25 ;
V_105 = F_41 ( V_18 , V_106 ) ;
if ( V_105 >= V_18 -> V_107 )
V_105 = 0 ;
return V_105 ;
}
static int F_42 ( struct V_14 * V_15 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 ;
struct V_50 * V_51 ;
int V_98 = 0 ;
struct V_108 * V_109 = V_15 -> V_19 ;
struct V_68 * V_110 ;
struct V_68 * V_37 ;
V_110 = F_43 ( V_109 -> V_111 , V_15 ) ;
if ( ! V_110 )
return - V_93 ;
V_37 = & V_110 [ V_15 -> V_38 ] ;
V_51 = ( V_15 -> V_38 == V_39 ) ?
& V_112 : & V_113 ;
F_20 ( V_15 , V_37 -> V_114 , V_51 ) ;
F_44 ( V_15 , V_51 ) ;
V_98 = F_45 ( V_18 ,
V_115 ) ;
if ( V_98 < 0 )
return V_98 ;
V_17 = F_22 ( sizeof( struct V_16 ) , V_60 ) ;
if ( V_17 == NULL )
return - V_65 ;
F_46 ( & V_17 -> V_48 ) ;
V_17 -> V_37 = V_37 ;
V_17 -> V_86 = - 1 ;
V_17 -> V_24 [ 0 ] = V_17 -> V_24 [ 1 ] = - 1 ;
V_17 -> V_46 = - 1 ;
V_17 -> V_74 = - 1 ;
V_17 -> V_80 = - 1 ;
V_18 -> V_19 = V_17 ;
V_98 = F_34 ( V_15 ) ;
if ( V_98 ) {
F_3 ( V_70 L_18 ) ;
F_47 ( V_17 ) ;
}
return V_98 ;
}
static int F_48 ( struct V_14 * V_15 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
struct V_16 * V_17 = V_18 -> V_19 ;
if ( V_17 -> V_46 >= 0 )
F_49 ( V_17 -> V_46 ) ;
if ( V_17 -> V_86 >= 0 )
F_49 ( V_17 -> V_86 ) ;
if ( V_17 -> V_24 [ 0 ] >= 0 )
F_50 ( V_17 -> V_24 [ 0 ] ) ;
if ( V_17 -> V_24 [ 1 ] >= 0 )
F_50 ( V_17 -> V_24 [ 1 ] ) ;
if ( V_17 -> V_74 >= 0 )
F_50 ( V_17 -> V_74 ) ;
if ( V_17 -> V_24 [ 0 ] >= 0 )
F_51 ( V_17 -> V_24 [ 0 ] ) ;
if ( V_17 -> V_24 [ 1 ] >= 0 )
F_51 ( V_17 -> V_24 [ 1 ] ) ;
if ( V_17 -> V_86 >= 0 )
F_33 ( V_17 -> V_86 ) ;
if ( V_17 -> V_74 >= 0 )
F_51 ( V_17 -> V_74 ) ;
if ( V_17 -> V_80 >= 0 )
F_51 ( V_17 -> V_80 ) ;
if ( V_17 -> V_46 >= 0 )
F_33 ( V_17 -> V_46 ) ;
F_47 ( V_17 ) ;
return 0 ;
}
static int F_52 ( struct V_14 * V_15 ,
struct V_116 * V_117 )
{
return F_53 ( V_15 ,
F_54 ( V_117 ) ) ;
}
static int F_55 ( struct V_14 * V_15 )
{
return F_56 ( V_15 ) ;
}
static int F_57 ( struct V_14 * V_15 ,
struct V_118 * V_119 )
{
struct V_20 * V_18 = V_15 -> V_18 ;
return F_58 ( V_15 -> V_120 -> V_121 -> V_122 , V_119 ,
V_18 -> V_123 ,
V_18 -> V_36 ,
V_18 -> V_124 ) ;
}
static int F_59 ( struct V_125 * V_120 , int V_38 ,
T_4 V_49 )
{
struct V_14 * V_15 = V_120 -> V_126 [ V_38 ] . V_15 ;
struct V_52 * V_53 = & V_15 -> V_54 ;
V_53 -> V_122 . type = V_127 ;
V_53 -> V_122 . V_122 = V_120 -> V_121 -> V_122 ;
V_53 -> V_19 = NULL ;
V_53 -> V_62 = F_60 ( V_120 -> V_121 -> V_122 , V_49 ,
& V_53 -> V_63 , V_60 ) ;
F_9 ( L_19
L_20 , ( void * ) V_53 -> V_62 , ( void * ) V_53 -> V_63 , V_49 ) ;
if ( ! V_53 -> V_62 )
return - V_65 ;
V_53 -> V_64 = V_49 ;
return 0 ;
}
static void F_61 ( struct V_125 * V_120 )
{
struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
struct V_52 * V_55 ;
V_15 = V_120 -> V_126 [ V_38 ] . V_15 ;
if ( ! V_15 )
continue;
V_53 = & V_15 -> V_54 ;
if ( ! V_53 -> V_62 )
continue;
F_62 ( V_120 -> V_121 -> V_122 , V_53 -> V_64 ,
V_53 -> V_62 , V_53 -> V_63 ) ;
V_53 -> V_62 = NULL ;
V_55 = V_53 -> V_19 ;
if ( V_55 ) {
F_23 ( V_55 -> V_62 , V_55 -> V_64 ) ;
F_47 ( V_55 ) ;
}
}
}
static int F_63 ( struct V_108 * V_109 )
{
struct V_128 * V_121 = V_109 -> V_121 -> V_128 ;
struct V_129 * V_130 = V_109 -> V_111 ;
struct V_125 * V_120 = V_109 -> V_120 ;
int V_98 ;
if ( ! V_121 -> V_122 -> V_131 )
V_121 -> V_122 -> V_131 = & V_132 ;
if ( ! V_121 -> V_122 -> V_133 )
V_121 -> V_122 -> V_133 = 0xffffffff ;
if ( V_130 -> V_134 -> V_135 . V_136 ) {
V_98 = F_59 ( V_120 ,
V_39 ,
V_112 . V_137 ) ;
if ( V_98 )
return V_98 ;
}
if ( V_130 -> V_134 -> V_138 . V_136 ) {
V_98 = F_59 ( V_120 ,
V_139 ,
V_113 . V_137 ) ;
if ( V_98 )
return V_98 ;
}
return 0 ;
}
static int T_5 F_64 ( struct V_140 * V_141 )
{
return F_65 ( & V_141 -> V_122 , & V_142 ) ;
}
static int T_6 F_66 ( struct V_140 * V_141 )
{
F_67 ( & V_141 -> V_122 ) ;
return 0 ;
}
static int T_7 F_68 ( void )
{
return F_69 ( & V_143 ) ;
}
static void T_8 F_70 ( void )
{
F_71 ( & V_143 ) ;
}
