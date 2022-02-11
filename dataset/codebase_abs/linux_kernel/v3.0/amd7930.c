static T_1 void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_7 ) ;
F_3 ( 0 , V_2 -> V_6 + V_8 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static T_1 void F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_9 , V_2 -> V_6 + V_8 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static T_1 void F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
F_3 ( V_5 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_9 | V_10 , V_2 -> V_6 + V_8 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
F_3 ( V_13 , V_2 -> V_6 + V_7 ) ;
F_3 ( ( ( V_12 -> V_14 >> 0 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( ( ( V_12 -> V_14 >> 8 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( V_15 , V_2 -> V_6 + V_7 ) ;
F_3 ( ( ( V_12 -> V_16 >> 0 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( ( ( V_12 -> V_16 >> 8 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( V_17 , V_2 -> V_6 + V_7 ) ;
F_3 ( ( ( V_12 -> V_18 >> 0 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( ( ( V_12 -> V_18 >> 8 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( V_19 , V_2 -> V_6 + V_7 ) ;
F_3 ( ( ( V_12 -> V_20 >> 0 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( ( ( V_12 -> V_20 >> 8 ) & 0xff ) , V_2 -> V_6 + V_8 ) ;
F_3 ( V_21 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_12 -> V_22 , V_2 -> V_6 + V_8 ) ;
F_3 ( V_23 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_12 -> V_24 , V_2 -> V_6 + V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
int V_25 ;
V_12 -> V_14 = V_26 [ V_2 -> V_27 ] ;
V_12 -> V_18 = V_26 [ V_2 -> V_28 ] ;
V_25 = ( V_2 -> V_29 * ( 256 + F_9 ( V_30 ) ) ) >> 8 ;
if ( V_25 >= 256 ) {
V_12 -> V_20 = V_30 [ V_25 - 256 ] ;
V_12 -> V_16 = V_26 [ 255 ] ;
} else {
V_12 -> V_20 = V_30 [ 0 ] ;
V_12 -> V_16 = V_26 [ V_25 ] ;
}
F_7 ( V_2 ) ;
}
static T_2 F_10 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
unsigned int V_33 ;
T_3 V_34 ;
F_11 ( & V_2 -> V_4 ) ;
V_33 = 0 ;
V_34 = F_12 ( V_2 -> V_6 + V_35 ) ;
if ( V_34 & V_36 ) {
T_3 V_37 ;
if ( V_2 -> V_3 & V_38 ) {
if ( V_2 -> V_39 > 0 ) {
V_37 = * ( V_2 -> V_40 ++ ) ;
V_2 -> V_39 -- ;
F_3 ( V_37 , V_2 -> V_6 + V_41 ) ;
if ( V_2 -> V_39 == 0 )
V_33 |= V_38 ;
} else
F_3 ( 0 , V_2 -> V_6 + V_41 ) ;
} else if ( V_2 -> V_3 & V_42 ) {
V_37 = F_12 ( V_2 -> V_6 + V_43 ) ;
if ( V_2 -> V_44 > 0 ) {
* ( V_2 -> V_45 ++ ) = V_37 ;
V_2 -> V_44 -- ;
if ( V_2 -> V_44 == 0 )
V_33 |= V_42 ;
}
}
}
F_13 ( & V_2 -> V_4 ) ;
if ( V_33 & V_38 )
F_14 ( V_2 -> V_46 ) ;
else
F_14 ( V_2 -> V_47 ) ;
return V_48 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_49 , int V_50 )
{
unsigned long V_3 ;
int V_51 = 0 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( V_50 == V_52 ) {
if ( ! ( V_2 -> V_3 & V_49 ) ) {
V_2 -> V_3 |= V_49 ;
F_3 ( V_53 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_54 , V_2 -> V_6 + V_8 ) ;
}
} else if ( V_50 == V_55 ) {
if ( V_2 -> V_3 & V_49 ) {
V_2 -> V_3 &= ~ V_49 ;
F_3 ( V_53 , V_2 -> V_6 + V_7 ) ;
F_3 ( 0 , V_2 -> V_6 + V_8 ) ;
}
} else {
V_51 = - V_56 ;
}
F_4 ( & V_2 -> V_4 , V_3 ) ;
return V_51 ;
}
static int F_16 ( struct V_57 * V_58 ,
int V_50 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
return F_15 ( V_2 , V_38 , V_50 ) ;
}
static int F_18 ( struct V_57 * V_58 ,
int V_50 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
return F_15 ( V_2 , V_42 , V_50 ) ;
}
static int F_19 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
struct V_59 * V_60 = V_58 -> V_60 ;
unsigned int V_61 = F_20 ( V_58 ) ;
unsigned long V_3 ;
T_3 V_62 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
V_2 -> V_3 |= V_38 ;
V_2 -> V_63 = V_2 -> V_40 = V_60 -> V_64 ;
V_2 -> V_39 = V_61 ;
V_62 = V_2 -> V_12 . V_22 ;
if ( V_60 -> V_65 == V_66 )
V_62 |= V_67 ;
else
V_62 &= ~ V_67 ;
if ( V_62 != V_2 -> V_12 . V_22 ) {
V_2 -> V_12 . V_22 = V_62 ;
F_8 ( V_2 ) ;
}
F_4 ( & V_2 -> V_4 , V_3 ) ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
struct V_59 * V_60 = V_58 -> V_60 ;
unsigned int V_61 = F_20 ( V_58 ) ;
unsigned long V_3 ;
T_3 V_62 ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
V_2 -> V_3 |= V_42 ;
V_2 -> V_68 = V_2 -> V_45 = V_60 -> V_64 ;
V_2 -> V_44 = V_61 ;
V_62 = V_2 -> V_12 . V_22 ;
if ( V_60 -> V_65 == V_66 )
V_62 |= V_67 ;
else
V_62 &= ~ V_67 ;
if ( V_62 != V_2 -> V_12 . V_22 ) {
V_2 -> V_12 . V_22 = V_62 ;
F_8 ( V_2 ) ;
}
F_4 ( & V_2 -> V_4 , V_3 ) ;
return 0 ;
}
static T_4 F_22 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
T_5 V_69 ;
if ( ! ( V_2 -> V_3 & V_38 ) )
return 0 ;
V_69 = V_2 -> V_40 - V_2 -> V_63 ;
return F_23 ( V_58 -> V_60 , V_69 ) ;
}
static T_4 F_24 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
T_5 V_69 ;
if ( ! ( V_2 -> V_3 & V_42 ) )
return 0 ;
V_69 = V_2 -> V_45 - V_2 -> V_68 ;
return F_23 ( V_58 -> V_60 , V_69 ) ;
}
static int F_25 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
struct V_59 * V_60 = V_58 -> V_60 ;
V_2 -> V_46 = V_58 ;
V_60 -> V_70 = V_71 ;
return 0 ;
}
static int F_26 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
struct V_59 * V_60 = V_58 -> V_60 ;
V_2 -> V_47 = V_58 ;
V_60 -> V_70 = V_71 ;
return 0 ;
}
static int F_27 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
V_2 -> V_46 = NULL ;
return 0 ;
}
static int F_28 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
V_2 -> V_47 = NULL ;
return 0 ;
}
static int F_29 ( struct V_57 * V_58 ,
struct V_72 * V_73 )
{
return F_30 ( V_58 , F_31 ( V_73 ) ) ;
}
static int F_32 ( struct V_57 * V_58 )
{
return F_33 ( V_58 ) ;
}
static int T_6 F_34 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
int V_76 ;
if ( ( V_76 = F_35 ( V_2 -> V_77 ,
L_1 ,
0 ,
1 ,
1 , & V_75 ) ) < 0 )
return V_76 ;
F_36 ( V_75 , V_78 , & V_79 ) ;
F_36 ( V_75 , V_80 , & V_81 ) ;
V_75 -> V_82 = V_2 ;
V_75 -> V_83 = 0 ;
strcpy ( V_75 -> V_84 , V_2 -> V_77 -> V_85 ) ;
V_2 -> V_75 = V_75 ;
F_37 ( V_75 , V_86 ,
F_38 ( V_87 ) ,
64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static int F_39 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
V_91 -> type = V_92 ;
V_91 -> V_93 = 1 ;
V_91 -> V_94 . integer . V_95 = 0 ;
V_91 -> V_94 . integer . V_96 = 255 ;
return 0 ;
}
static int F_40 ( struct V_88 * V_89 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_41 ( V_89 ) ;
int type = V_89 -> V_99 ;
int * V_100 ;
switch ( type ) {
case V_101 :
V_100 = & V_2 -> V_28 ;
break;
case V_102 :
V_100 = & V_2 -> V_27 ;
break;
case V_103 :
default:
V_100 = & V_2 -> V_29 ;
break;
} ;
V_98 -> V_94 . integer . V_94 [ 0 ] = * V_100 ;
return 0 ;
}
static int F_42 ( struct V_88 * V_89 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_41 ( V_89 ) ;
unsigned long V_3 ;
int type = V_89 -> V_99 ;
int * V_100 , V_104 ;
switch ( type ) {
case V_101 :
V_100 = & V_2 -> V_28 ;
break;
case V_102 :
V_100 = & V_2 -> V_27 ;
break;
case V_103 :
default:
V_100 = & V_2 -> V_29 ;
break;
} ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
if ( * V_100 != V_98 -> V_94 . integer . V_94 [ 0 ] ) {
* V_100 = V_98 -> V_94 . integer . V_94 [ 0 ] & 0xff ;
F_8 ( V_2 ) ;
V_104 = 1 ;
} else
V_104 = 0 ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
return V_104 ;
}
static int T_6 F_43 ( struct V_1 * V_2 )
{
struct V_105 * V_77 ;
int V_106 , V_76 ;
if ( F_44 ( ! V_2 || ! V_2 -> V_77 ) )
return - V_56 ;
V_77 = V_2 -> V_77 ;
strcpy ( V_77 -> V_107 , V_77 -> V_85 ) ;
for ( V_106 = 0 ; V_106 < F_9 ( V_108 ) ; V_106 ++ ) {
if ( ( V_76 = F_45 ( V_77 ,
F_46 ( & V_108 [ V_106 ] , V_2 ) ) ) < 0 )
return V_76 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = V_2 -> V_110 ;
F_1 ( V_2 ) ;
if ( V_2 -> V_31 )
F_48 ( V_2 -> V_31 , V_2 ) ;
if ( V_2 -> V_6 )
F_49 ( & V_110 -> V_111 [ 0 ] , V_2 -> V_6 ,
F_50 ( & V_110 -> V_111 [ 0 ] ) ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_114 ;
return F_47 ( V_2 ) ;
}
static int T_6 F_53 ( struct V_105 * V_77 ,
struct V_109 * V_110 ,
int V_31 , int V_115 ,
struct V_1 * * V_116 )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
int V_76 ;
* V_116 = NULL ;
V_2 = F_54 ( sizeof( * V_2 ) , V_87 ) ;
if ( V_2 == NULL )
return - V_117 ;
F_55 ( & V_2 -> V_4 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_110 = V_110 ;
V_2 -> V_6 = F_56 ( & V_110 -> V_111 [ 0 ] , 0 ,
F_50 ( & V_110 -> V_111 [ 0 ] ) , L_2 ) ;
if ( ! V_2 -> V_6 ) {
F_57 ( V_118
L_3 , V_115 ) ;
return - V_119 ;
}
F_1 ( V_2 ) ;
if ( F_58 ( V_31 , F_10 ,
V_120 | V_121 , L_2 , V_2 ) ) {
F_57 ( V_118 L_4 ,
V_115 , V_31 ) ;
F_47 ( V_2 ) ;
return - V_122 ;
}
V_2 -> V_31 = V_31 ;
F_5 ( V_2 ) ;
F_2 ( & V_2 -> V_4 , V_3 ) ;
V_2 -> V_27 = 128 ;
V_2 -> V_29 = 200 ;
V_2 -> V_28 = 0 ;
memset ( & V_2 -> V_12 , 0 , sizeof( V_2 -> V_12 ) ) ;
V_2 -> V_12 . V_22 = ( V_123 | V_124 |
V_125 | V_126 ) ;
V_2 -> V_12 . V_24 = ( V_127 | V_128 ) ;
F_8 ( V_2 ) ;
F_3 ( V_129 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_130 | ( V_131 << 4 ) ,
V_2 -> V_6 + V_8 ) ;
F_4 ( & V_2 -> V_4 , V_3 ) ;
if ( ( V_76 = F_59 ( V_77 , V_132 ,
V_2 , & V_133 ) ) < 0 ) {
F_47 ( V_2 ) ;
return V_76 ;
}
* V_116 = V_2 ;
return 0 ;
}
static int T_6 F_60 ( struct V_109 * V_110 )
{
struct V_111 * V_134 = & V_110 -> V_111 [ 0 ] ;
static int V_135 ;
struct V_105 * V_77 ;
struct V_1 * V_2 ;
int V_76 , V_31 ;
V_31 = V_110 -> V_136 . V_137 [ 0 ] ;
if ( V_135 >= V_138 )
return - V_139 ;
if ( ! V_140 [ V_135 ] ) {
V_135 ++ ;
return - V_141 ;
}
V_76 = F_61 ( V_142 [ V_135 ] , V_143 [ V_135 ] , V_144 , 0 ,
& V_77 ) ;
if ( V_76 < 0 )
return V_76 ;
strcpy ( V_77 -> V_145 , L_5 ) ;
strcpy ( V_77 -> V_85 , L_6 ) ;
sprintf ( V_77 -> V_146 , L_7 ,
V_77 -> V_85 ,
V_134 -> V_3 & 0xffL ,
( unsigned long long ) V_134 -> V_147 ,
V_31 ) ;
if ( ( V_76 = F_53 ( V_77 , V_110 ,
V_31 , V_135 , & V_2 ) ) < 0 )
goto V_148;
if ( ( V_76 = F_34 ( V_2 ) ) < 0 )
goto V_148;
if ( ( V_76 = F_43 ( V_2 ) ) < 0 )
goto V_148;
if ( ( V_76 = F_62 ( V_77 ) ) < 0 )
goto V_148;
V_2 -> V_149 = V_150 ;
V_150 = V_2 ;
V_135 ++ ;
return 0 ;
V_148:
F_63 ( V_77 ) ;
return V_76 ;
}
static int T_7 F_64 ( void )
{
return F_65 ( & V_151 ) ;
}
static void T_8 F_66 ( void )
{
struct V_1 * V_152 = V_150 ;
while ( V_152 != NULL ) {
struct V_1 * V_149 = V_152 -> V_149 ;
F_63 ( V_152 -> V_77 ) ;
V_152 = V_149 ;
}
V_150 = NULL ;
F_67 ( & V_151 ) ;
}
