static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 ,
unsigned V_8 )
{
return F_4 ( V_7 , V_8 , V_8 ) ;
}
static void F_5 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
F_6 ( V_9 -> V_10 ) ;
F_7 ( V_7 , V_9 ) ;
}
static void F_8 ( struct V_6 * V_7 , int V_11 ,
T_1 * V_12 , int V_8 )
{
struct V_1 * V_13 = V_7 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 [ V_11 ] ;
if ( ! V_16 )
return;
if ( ! F_9 ( V_11 , & V_13 -> V_18 ) )
return;
F_10 ( V_16 , V_12 , V_8 ) ;
}
static void F_11 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
unsigned int V_19 ;
T_2 * V_10 = V_9 -> V_10 ;
for ( V_19 = 0 ; V_19 + 3 < V_9 -> V_20 ; V_19 += 4 )
if ( V_10 [ V_19 ] != 0 ) {
int V_11 = V_10 [ V_19 ] >> 4 ;
int V_8 = V_21 [ V_10 [ V_19 ] & 0x0f ] ;
F_8 ( V_7 , V_11 , & V_10 [ V_19 + 1 ] , V_8 ) ;
}
}
static void
F_12 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
struct V_1 * V_13 = V_7 -> V_14 ;
struct V_22 * V_23 = V_13 -> V_4 . V_24 -> V_23 ;
int V_25 = V_9 -> V_25 ;
switch ( V_25 ) {
case 0 :
if ( V_7 == V_13 -> V_26 ) {
F_11 ( V_7 , V_9 ) ;
} else if ( V_7 == V_13 -> V_27 ) {
F_13 ( V_13 , V_9 ) ;
return;
}
break;
case - V_28 :
case - V_29 :
case - V_30 :
F_14 ( V_23 , L_1 , V_7 -> V_31 , V_25 ,
V_9 -> V_20 , V_9 -> V_8 ) ;
if ( V_7 == V_13 -> V_26 )
F_11 ( V_7 , V_9 ) ;
F_5 ( V_7 , V_9 ) ;
return;
case - V_32 :
default:
F_15 ( V_23 , L_2 , V_7 -> V_31 ,
V_25 , V_9 -> V_20 , V_9 -> V_8 ) ;
break;
case - V_33 :
break;
}
V_25 = F_16 ( V_7 , V_9 , V_34 ) ;
if ( V_25 ) {
ERROR ( V_23 , L_3 ,
V_7 -> V_31 , V_9 -> V_8 , V_25 ) ;
F_17 ( V_7 ) ;
}
}
static int F_18 ( struct V_1 * V_13 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_35 ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
if ( V_7 -> V_14 )
F_19 ( V_7 ) ;
V_35 = F_20 ( V_13 -> V_36 , V_3 , V_7 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_4 , V_7 -> V_31 , V_35 ) ;
return V_35 ;
}
V_35 = F_21 ( V_7 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_5 , V_7 -> V_31 , V_35 ) ;
return V_35 ;
}
V_7 -> V_14 = V_13 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_37 , unsigned V_38 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
unsigned V_19 ;
int V_35 ;
V_35 = F_18 ( V_13 , V_3 , V_13 -> V_27 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_18 ( V_13 , V_3 , V_13 -> V_26 ) ;
if ( V_35 )
return V_35 ;
if ( V_13 -> V_26 -> V_14 )
F_19 ( V_13 -> V_26 ) ;
V_35 = F_20 ( V_13 -> V_36 , V_3 , V_13 -> V_26 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_4 ,
V_13 -> V_26 -> V_31 , V_35 ) ;
return V_35 ;
}
V_35 = F_21 ( V_13 -> V_26 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_5 ,
V_13 -> V_26 -> V_31 , V_35 ) ;
return V_35 ;
}
V_13 -> V_26 -> V_14 = V_13 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_39 && V_35 == 0 ; V_19 ++ ) {
struct V_5 * V_9 =
F_3 ( V_13 -> V_26 , V_13 -> V_40 ) ;
if ( V_9 == NULL )
return - V_41 ;
V_9 -> V_42 = F_12 ;
V_35 = F_16 ( V_13 -> V_26 , V_9 , V_34 ) ;
if ( V_35 ) {
ERROR ( V_13 , L_6 ,
V_13 -> V_26 -> V_31 , V_35 ) ;
}
}
return 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
F_15 ( V_23 , L_7 ) ;
F_19 ( V_13 -> V_27 ) ;
F_19 ( V_13 -> V_26 ) ;
}
static void F_24 ( struct V_43 * V_44 , struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_45 * V_46 ;
F_15 ( V_23 , L_8 ) ;
F_23 ( V_3 ) ;
V_46 = V_13 -> V_46 ;
V_13 -> V_46 = NULL ;
if ( V_46 )
F_25 ( V_46 ) ;
F_6 ( V_13 -> V_47 ) ;
V_13 -> V_47 = NULL ;
F_26 ( V_3 ) ;
F_6 ( V_13 ) ;
}
static int F_27 ( struct V_48 * V_49 )
{
return 0 ;
}
static void F_28 ( struct V_5 * V_9 , T_1 V_50 ,
T_1 V_51 , T_1 V_52 , T_1 V_53 )
{
unsigned V_8 = V_9 -> V_8 ;
T_2 * V_10 = ( T_2 * ) V_9 -> V_10 + V_8 ;
V_10 [ 0 ] = V_50 ;
V_10 [ 1 ] = V_51 ;
V_10 [ 2 ] = V_52 ;
V_10 [ 3 ] = V_53 ;
V_9 -> V_8 = V_8 + 4 ;
}
static void F_29 ( struct V_5 * V_9 ,
struct V_54 * V_55 , T_1 V_56 )
{
T_1 V_50 = V_55 -> V_11 << 4 ;
if ( V_56 >= 0xf8 ) {
F_28 ( V_9 , V_50 | 0x0f , V_56 , 0 , 0 ) ;
} else if ( V_56 >= 0xf0 ) {
switch ( V_56 ) {
case 0xf0 :
V_55 -> V_12 [ 0 ] = V_56 ;
V_55 -> V_57 = V_58 ;
break;
case 0xf1 :
case 0xf3 :
V_55 -> V_12 [ 0 ] = V_56 ;
V_55 -> V_57 = V_59 ;
break;
case 0xf2 :
V_55 -> V_12 [ 0 ] = V_56 ;
V_55 -> V_57 = V_60 ;
break;
case 0xf4 :
case 0xf5 :
V_55 -> V_57 = V_61 ;
break;
case 0xf6 :
F_28 ( V_9 , V_50 | 0x05 , 0xf6 , 0 , 0 ) ;
V_55 -> V_57 = V_61 ;
break;
case 0xf7 :
switch ( V_55 -> V_57 ) {
case V_62 :
F_28 ( V_9 ,
V_50 | 0x05 , 0xf7 , 0 , 0 ) ;
break;
case V_58 :
F_28 ( V_9 ,
V_50 | 0x06 , V_55 -> V_12 [ 0 ] , 0xf7 , 0 ) ;
break;
case V_63 :
F_28 ( V_9 ,
V_50 | 0x07 , V_55 -> V_12 [ 0 ] ,
V_55 -> V_12 [ 1 ] , 0xf7 ) ;
break;
}
V_55 -> V_57 = V_61 ;
break;
}
} else if ( V_56 >= 0x80 ) {
V_55 -> V_12 [ 0 ] = V_56 ;
if ( V_56 >= 0xc0 && V_56 <= 0xdf )
V_55 -> V_57 = V_59 ;
else
V_55 -> V_57 = V_60 ;
} else {
switch ( V_55 -> V_57 ) {
case V_59 :
if ( V_55 -> V_12 [ 0 ] < 0xf0 ) {
V_50 |= V_55 -> V_12 [ 0 ] >> 4 ;
} else {
V_50 |= 0x02 ;
V_55 -> V_57 = V_61 ;
}
F_28 ( V_9 , V_50 , V_55 -> V_12 [ 0 ] , V_56 , 0 ) ;
break;
case V_60 :
V_55 -> V_12 [ 1 ] = V_56 ;
V_55 -> V_57 = V_64 ;
break;
case V_64 :
if ( V_55 -> V_12 [ 0 ] < 0xf0 ) {
V_50 |= V_55 -> V_12 [ 0 ] >> 4 ;
V_55 -> V_57 = V_60 ;
} else {
V_50 |= 0x03 ;
V_55 -> V_57 = V_61 ;
}
F_28 ( V_9 ,
V_50 , V_55 -> V_12 [ 0 ] , V_55 -> V_12 [ 1 ] , V_56 ) ;
break;
case V_62 :
V_55 -> V_12 [ 0 ] = V_56 ;
V_55 -> V_57 = V_58 ;
break;
case V_58 :
V_55 -> V_12 [ 1 ] = V_56 ;
V_55 -> V_57 = V_63 ;
break;
case V_63 :
F_28 ( V_9 ,
V_50 | 0x04 , V_55 -> V_12 [ 0 ] , V_55 -> V_12 [ 1 ] , V_56 ) ;
V_55 -> V_57 = V_62 ;
break;
}
}
}
static void F_13 ( struct V_1 * V_13 , struct V_5 * V_9 )
{
struct V_6 * V_7 = V_13 -> V_27 ;
int V_19 ;
if ( ! V_7 )
return;
if ( ! V_9 )
V_9 = F_3 ( V_7 , V_13 -> V_40 ) ;
if ( ! V_9 ) {
ERROR ( V_13 , L_9 ) ;
return;
}
V_9 -> V_8 = 0 ;
V_9 -> V_42 = F_12 ;
for ( V_19 = 0 ; V_19 < V_65 ; V_19 ++ ) {
struct V_54 * V_55 = V_13 -> V_66 [ V_19 ] ;
struct V_15 * V_16 = V_13 -> V_67 [ V_19 ] ;
if ( ! V_55 || ! V_55 -> V_68 || ! V_16 )
continue;
while ( V_9 -> V_8 + 3 < V_13 -> V_40 ) {
T_1 V_56 ;
if ( F_30 ( V_16 , & V_56 , 1 ) != 1 ) {
V_55 -> V_68 = 0 ;
break;
}
F_29 ( V_9 , V_55 , V_56 ) ;
}
}
if ( V_9 -> V_8 > 0 )
F_16 ( V_7 , V_9 , V_34 ) ;
else
F_5 ( V_7 , V_9 ) ;
}
static void F_31 ( unsigned long V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
F_13 ( V_13 , NULL ) ;
}
static int F_32 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_69 -> V_70 ;
if ( ! V_13 -> V_66 [ V_16 -> V_71 ] )
return - V_72 ;
F_14 ( V_13 , L_10 , V_73 ) ;
V_13 -> V_67 [ V_16 -> V_71 ] = V_16 ;
V_13 -> V_66 [ V_16 -> V_71 ] -> V_57 = V_61 ;
return 0 ;
}
static int F_33 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_69 -> V_70 ;
F_14 ( V_13 , L_10 , V_73 ) ;
return 0 ;
}
static void F_34 ( struct V_15 * V_16 , int V_74 )
{
struct V_1 * V_13 = V_16 -> V_69 -> V_70 ;
if ( ! V_13 -> V_66 [ V_16 -> V_71 ] )
return;
F_14 ( V_13 , L_11 , V_73 , V_74 ) ;
V_13 -> V_66 [ V_16 -> V_71 ] -> V_68 = V_74 ;
if ( V_74 )
F_35 ( & V_13 -> V_75 ) ;
}
static int F_36 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_69 -> V_70 ;
if ( V_16 -> V_71 >= V_65 )
return - V_72 ;
F_14 ( V_13 , L_10 , V_73 ) ;
V_13 -> V_17 [ V_16 -> V_71 ] = V_16 ;
return 0 ;
}
static int F_37 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_69 -> V_70 ;
F_14 ( V_13 , L_10 , V_73 ) ;
return 0 ;
}
static void F_38 ( struct V_15 * V_16 , int V_74 )
{
struct V_1 * V_13 = V_16 -> V_69 -> V_70 ;
F_14 ( V_13 , L_10 , V_73 ) ;
if ( V_74 )
F_39 ( V_16 -> V_71 , & V_13 -> V_18 ) ;
else
F_40 ( V_16 -> V_71 , & V_13 -> V_18 ) ;
}
static int F_41 ( struct V_1 * V_13 )
{
struct V_45 * V_46 ;
struct V_76 * V_69 ;
int V_35 ;
static struct V_77 V_78 = {
. V_79 = F_27 ,
} ;
V_35 = F_42 ( V_13 -> V_80 , V_13 -> V_47 , V_81 , 0 , & V_46 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_12 ) ;
goto V_82;
}
V_13 -> V_46 = V_46 ;
V_35 = F_43 ( V_46 , V_83 , V_13 , & V_78 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_13 , V_35 ) ;
goto V_82;
}
strcpy ( V_46 -> V_84 , V_85 ) ;
strcpy ( V_46 -> V_86 , V_85 ) ;
strcpy ( V_46 -> V_87 , V_88 ) ;
F_44 ( V_46 , L_14 ) ;
V_35 = F_45 ( V_46 , V_46 -> V_86 , 0 ,
V_13 -> V_89 , V_13 -> V_90 , & V_69 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_15 , V_35 ) ;
goto V_82;
}
V_13 -> V_69 = V_69 ;
strcpy ( V_69 -> V_31 , V_46 -> V_87 ) ;
V_69 -> V_91 = V_92 |
V_93 |
V_94 ;
V_69 -> V_70 = V_13 ;
F_46 ( V_69 , V_95 , & V_96 ) ;
F_46 ( V_69 , V_97 , & V_98 ) ;
F_47 ( V_46 , & V_13 -> V_36 -> V_99 ) ;
V_35 = F_48 ( V_46 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_16 ) ;
goto V_82;
}
F_14 ( V_13 , L_17 , V_73 ) ;
return 0 ;
V_82:
if ( V_13 -> V_46 ) {
F_25 ( V_13 -> V_46 ) ;
V_13 -> V_46 = NULL ;
}
return V_35 ;
}
static int T_3
F_49 ( struct V_43 * V_44 , struct V_2 * V_3 )
{
struct V_100 * * V_101 ;
struct V_102 V_103 [ V_65 ] ;
struct V_102 V_104 [ V_65 ] ;
struct V_105 V_106 [ V_65 ] ;
struct V_105 V_107 [ V_65 ] ;
struct V_22 * V_23 = V_44 -> V_23 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_25 , V_108 , V_109 = 1 , V_19 = 0 ;
if ( V_110 [ 0 ] . V_47 == 0 ) {
V_25 = F_50 ( V_44 -> V_23 ) ;
if ( V_25 < 0 )
goto V_82;
V_110 [ 0 ] . V_47 = V_25 ;
}
V_25 = F_51 ( V_44 , V_3 ) ;
if ( V_25 < 0 )
goto V_82;
V_111 . V_112 = V_25 ;
V_25 = F_51 ( V_44 , V_3 ) ;
if ( V_25 < 0 )
goto V_82;
V_113 . V_112 = V_25 ;
V_114 . V_115 [ 0 ] = V_25 ;
V_25 = - V_116 ;
V_13 -> V_27 = F_52 ( V_23 -> V_36 , & V_117 ) ;
if ( ! V_13 -> V_27 )
goto V_82;
V_13 -> V_27 -> V_14 = V_23 ;
V_13 -> V_26 = F_52 ( V_23 -> V_36 , & V_118 ) ;
if ( ! V_13 -> V_26 )
goto V_82;
V_13 -> V_26 -> V_14 = V_23 ;
V_101 = F_53 ( ( V_65 * 4 ) + 9 , sizeof( * V_101 ) ,
V_119 ) ;
if ( ! V_101 ) {
V_25 = - V_41 ;
goto V_82;
}
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_111 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_114 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_113 ;
V_108 = V_120
+ ( V_13 -> V_90 + V_13 -> V_89 ) *
( V_121 + F_54 ( 1 ) ) ;
V_122 . V_123 = F_55 ( V_108 ) ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_122 ;
for ( V_108 = 0 ; V_108 < V_13 -> V_90 ; V_108 ++ ) {
struct V_102 * V_124 = & V_103 [ V_108 ] ;
struct V_105 * V_125 = & V_107 [ V_108 ] ;
V_124 -> V_126 = V_121 ;
V_124 -> V_127 = V_128 ;
V_124 -> V_129 = V_130 ;
V_124 -> V_131 = V_132 ;
V_124 -> V_133 = V_109 ++ ;
V_124 -> V_134 = 0 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) V_124 ;
V_125 -> V_126 = F_54 ( 1 ) ;
V_125 -> V_127 = V_128 ;
V_125 -> V_129 = V_135 ;
V_125 -> V_131 = V_136 ;
V_125 -> V_133 = V_109 ++ ;
V_125 -> V_137 = 1 ;
V_125 -> V_138 [ 0 ] . V_139 = 1 ;
V_125 -> V_138 [ 0 ] . V_140 = V_124 -> V_133 ;
V_125 -> V_134 = 0 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) V_125 ;
V_141 . V_142 [ V_108 ] = V_125 -> V_133 ;
}
for ( V_108 = 0 ; V_108 < V_13 -> V_89 ; V_108 ++ ) {
struct V_102 * V_143 = & V_104 [ V_108 ] ;
struct V_105 * V_144 = & V_106 [ V_108 ] ;
V_143 -> V_126 = V_121 ;
V_143 -> V_127 = V_128 ;
V_143 -> V_129 = V_130 ;
V_143 -> V_131 = V_136 ;
V_143 -> V_133 = V_109 ++ ;
V_143 -> V_134 = 0 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) V_143 ;
V_144 -> V_126 = F_54 ( 1 ) ;
V_144 -> V_127 = V_128 ;
V_144 -> V_129 = V_135 ;
V_144 -> V_131 = V_132 ;
V_144 -> V_133 = V_109 ++ ;
V_144 -> V_137 = 1 ;
V_144 -> V_134 = 0 ;
V_144 -> V_138 [ 0 ] . V_140 = V_143 -> V_133 ;
V_144 -> V_138 [ 0 ] . V_139 = 1 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) V_144 ;
V_145 . V_142 [ V_108 ] = V_143 -> V_133 ;
}
V_145 . V_126 = F_56 ( V_13 -> V_90 ) ;
V_145 . V_146 = V_13 -> V_90 ;
V_141 . V_126 = F_56 ( V_13 -> V_89 ) ;
V_141 . V_146 = V_13 -> V_89 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_118 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_145 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_117 ;
V_101 [ V_19 ++ ] = (struct V_100 * ) & V_141 ;
V_101 [ V_19 ++ ] = NULL ;
V_3 -> V_147 = F_57 ( V_101 ) ;
if ( ! V_3 -> V_147 )
goto V_148;
if ( F_58 ( V_44 -> V_23 -> V_36 ) ) {
V_117 . V_149 = F_55 ( 512 ) ;
V_118 . V_149 = F_55 ( 512 ) ;
V_3 -> V_150 = F_57 ( V_101 ) ;
if ( ! V_3 -> V_150 )
goto V_148;
}
F_6 ( V_101 ) ;
return 0 ;
V_148:
F_6 ( V_101 ) ;
F_59 ( V_3 -> V_150 ) ;
V_82:
if ( V_13 -> V_26 )
V_13 -> V_26 -> V_14 = NULL ;
if ( V_13 -> V_27 )
V_13 -> V_27 -> V_14 = NULL ;
ERROR ( V_23 , L_18 , V_3 -> V_31 , V_25 ) ;
return V_25 ;
}
int T_3 F_60 ( struct V_43 * V_44 ,
int V_80 , char * V_47 ,
unsigned int V_90 ,
unsigned int V_89 ,
unsigned int V_40 ,
unsigned int V_39 )
{
struct V_1 * V_13 ;
int V_25 , V_19 ;
if ( V_90 > V_65 || V_89 > V_65 )
return - V_72 ;
V_13 = F_61 ( sizeof *V_13 , V_119 ) ;
if ( ! V_13 ) {
V_25 = - V_41 ;
goto V_82;
}
for ( V_19 = 0 ; V_19 < V_90 ; V_19 ++ ) {
struct V_54 * V_55 = F_61 ( sizeof( * V_55 ) , V_119 ) ;
if ( ! V_55 ) {
V_25 = - V_41 ;
goto V_151;
}
V_55 -> V_13 = V_13 ;
V_55 -> V_68 = 0 ;
V_55 -> V_11 = V_19 ;
V_13 -> V_66 [ V_19 ] = V_55 ;
}
V_13 -> V_36 = V_44 -> V_23 -> V_36 ;
F_62 ( & V_13 -> V_75 , F_31 , ( unsigned long ) V_13 ) ;
V_13 -> V_90 = V_90 ;
V_13 -> V_89 = V_89 ;
V_25 = F_41 ( V_13 ) ;
if ( V_25 < 0 )
goto V_151;
V_13 -> V_4 . V_31 = L_19 ;
V_13 -> V_4 . V_152 = V_153 ;
V_13 -> V_4 . V_154 = F_49 ;
V_13 -> V_4 . V_155 = F_24 ;
V_13 -> V_4 . V_156 = F_22 ;
V_13 -> V_4 . V_157 = F_23 ;
V_13 -> V_47 = F_63 ( V_47 , V_119 ) ;
V_13 -> V_80 = V_80 ;
V_13 -> V_40 = V_40 ;
V_13 -> V_39 = V_39 ;
V_25 = F_64 ( V_44 , & V_13 -> V_4 ) ;
if ( V_25 )
goto V_151;
return 0 ;
V_151:
for ( -- V_19 ; V_19 >= 0 ; V_19 -- )
F_6 ( V_13 -> V_66 [ V_19 ] ) ;
F_6 ( V_13 ) ;
V_82:
return V_25 ;
}
