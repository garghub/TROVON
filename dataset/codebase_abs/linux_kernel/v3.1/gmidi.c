static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 type , unsigned V_4 )
{
int V_5 ;
if ( V_4 != 0 ) {
return - V_6 ;
}
V_5 = F_2 ( & V_7 ,
V_3 , V_8 , V_9 ) ;
if ( V_5 < 0 ) {
return V_5 ;
}
( (struct V_10 * ) V_3 ) -> V_11 = type ;
return V_5 ;
}
static struct V_12 * F_3 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_12 * V_16 ;
V_16 = F_4 ( V_14 , V_17 ) ;
if ( V_16 ) {
V_16 -> V_15 = V_15 ;
V_16 -> V_3 = F_5 ( V_15 , V_17 ) ;
if ( ! V_16 -> V_3 ) {
F_6 ( V_14 , V_16 ) ;
V_16 = NULL ;
}
}
return V_16 ;
}
static void F_7 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
F_8 ( V_16 -> V_3 ) ;
F_6 ( V_14 , V_16 ) ;
}
static void F_9 ( struct V_13 * V_14 , int V_18 ,
T_2 * V_19 , int V_15 )
{
struct V_20 * V_21 = V_14 -> V_22 ;
if ( ! V_21 -> V_23 ) {
return;
}
if ( ! F_10 ( V_21 -> V_23 -> V_24 , & V_21 -> V_25 ) ) {
return;
}
F_11 ( V_21 -> V_23 , V_19 , V_15 ) ;
}
static void F_12 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
unsigned V_26 ;
T_1 * V_3 = V_16 -> V_3 ;
for ( V_26 = 0 ; V_26 + 3 < V_16 -> V_27 ; V_26 += 4 ) {
if ( V_3 [ V_26 ] != 0 ) {
int V_18 = V_3 [ V_26 ] >> 4 ;
int V_15 = V_28 [ V_3 [ V_26 ] & 0x0f ] ;
F_9 ( V_14 , V_18 , & V_3 [ V_26 + 1 ] , V_15 ) ;
}
}
}
static void F_13 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
struct V_20 * V_21 = V_14 -> V_22 ;
int V_29 = V_16 -> V_29 ;
switch ( V_29 ) {
case 0 :
if ( V_14 == V_21 -> V_30 ) {
F_12 ( V_14 , V_16 ) ;
} else if ( V_14 == V_21 -> V_31 ) {
F_14 ( V_21 , V_16 ) ;
return;
}
break;
case - V_32 :
case - V_33 :
case - V_34 :
F_15 ( V_21 , L_1 , V_14 -> V_35 , V_29 ,
V_16 -> V_27 , V_16 -> V_15 ) ;
if ( V_14 == V_21 -> V_30 ) {
F_12 ( V_14 , V_16 ) ;
}
F_7 ( V_14 , V_16 ) ;
return;
case - V_36 :
default:
F_16 ( V_21 , L_2 , V_14 -> V_35 ,
V_29 , V_16 -> V_27 , V_16 -> V_15 ) ;
break;
case - V_37 :
break;
}
V_29 = F_17 ( V_14 , V_16 , V_17 ) ;
if ( V_29 ) {
ERROR ( V_21 , L_3 ,
V_14 -> V_35 , V_16 -> V_15 , V_29 ) ;
F_18 ( V_14 ) ;
}
}
static int F_19 ( struct V_20 * V_21 , T_3 V_38 )
{
int V_39 = 0 ;
struct V_12 * V_16 ;
struct V_13 * V_14 ;
unsigned V_26 ;
V_21 -> V_31 -> V_40 = & V_41 ;
V_39 = F_20 ( V_21 -> V_31 ) ;
if ( V_39 ) {
ERROR ( V_21 , L_4 , V_21 -> V_31 -> V_35 , V_39 ) ;
goto V_42;
}
V_21 -> V_31 -> V_22 = V_21 ;
V_21 -> V_30 -> V_40 = & V_43 ;
V_39 = F_20 ( V_21 -> V_30 ) ;
if ( V_39 ) {
ERROR ( V_21 , L_4 , V_21 -> V_30 -> V_35 , V_39 ) ;
goto V_42;
}
V_21 -> V_30 -> V_22 = V_21 ;
V_14 = V_21 -> V_30 ;
for ( V_26 = 0 ; V_26 < V_44 && V_39 == 0 ; V_26 ++ ) {
V_16 = F_3 ( V_14 , V_45 ) ;
if ( V_16 ) {
V_16 -> V_46 = F_13 ;
V_39 = F_17 ( V_14 , V_16 , V_17 ) ;
if ( V_39 ) {
F_16 ( V_21 , L_5 , V_14 -> V_35 , V_39 ) ;
}
} else {
V_39 = - V_47 ;
}
}
V_42:
return V_39 ;
}
static void F_21 ( struct V_20 * V_21 )
{
if ( V_21 -> V_48 == 0 ) {
return;
}
F_16 ( V_21 , L_6 ) ;
F_22 ( V_21 -> V_31 ) ;
F_22 ( V_21 -> V_30 ) ;
V_21 -> V_48 = 0 ;
}
static int
F_23 ( struct V_20 * V_21 , unsigned V_24 , T_3 V_38 )
{
int V_49 = 0 ;
struct V_1 * V_2 = V_21 -> V_2 ;
#if 0
if (number == dev->config) {
return 0;
}
#endif
F_21 ( V_21 ) ;
switch ( V_24 ) {
case V_50 :
V_49 = F_19 ( V_21 , V_38 ) ;
break;
default:
V_49 = - V_6 ;
case 0 :
return V_49 ;
}
if ( ! V_49 && ( ! V_21 -> V_31 || ! V_21 -> V_30 ) ) {
V_49 = - V_51 ;
}
if ( V_49 ) {
F_21 ( V_21 ) ;
} else {
char * V_52 ;
switch ( V_2 -> V_52 ) {
case V_53 : V_52 = L_7 ; break;
case V_54 : V_52 = L_8 ; break;
case V_55 : V_52 = L_9 ; break;
default: V_52 = L_10 ; break;
}
V_21 -> V_48 = V_24 ;
F_24 ( V_21 , L_11 , V_52 ) ;
}
return V_49 ;
}
static void F_25 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
if ( V_16 -> V_29 || V_16 -> V_27 != V_16 -> V_15 ) {
F_16 ( (struct V_20 * ) V_14 -> V_22 ,
L_12 ,
V_16 -> V_29 , V_16 -> V_27 , V_16 -> V_15 ) ;
}
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_56 * V_57 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
struct V_12 * V_16 = V_21 -> V_16 ;
int V_58 = - V_59 ;
T_4 V_60 = F_28 ( V_57 -> V_61 ) ;
T_4 V_62 = F_28 ( V_57 -> V_63 ) ;
T_4 V_64 = F_28 ( V_57 -> V_65 ) ;
V_16 -> V_66 = 0 ;
switch ( V_57 -> V_67 ) {
case V_68 :
if ( V_57 -> V_69 != V_70 ) {
goto V_71;
}
switch ( V_62 >> 8 ) {
case V_72 :
V_73 . V_74 = V_2 -> V_75 -> V_76 ;
V_58 = F_29 ( V_64 , ( T_4 ) sizeof( V_73 ) ) ;
memcpy ( V_16 -> V_3 , & V_73 , V_58 ) ;
break;
case V_77 :
V_58 = F_1 ( V_2 , V_16 -> V_3 ,
V_62 >> 8 ,
V_62 & 0xff ) ;
if ( V_58 >= 0 ) {
V_58 = F_29 ( V_64 , ( T_4 ) V_58 ) ;
}
break;
case V_78 :
V_58 = F_30 ( & V_79 ,
V_62 & 0xff , V_16 -> V_3 ) ;
if ( V_58 >= 0 ) {
V_58 = F_29 ( V_64 , ( T_4 ) V_58 ) ;
}
break;
}
break;
case V_80 :
if ( V_57 -> V_69 != 0 ) {
goto V_71;
}
if ( V_2 -> V_81 ) {
F_16 ( V_21 , L_13 ) ;
} else if ( V_2 -> V_82 ) {
F_16 ( V_21 , L_14 ) ;
} else {
F_15 ( V_21 , L_15 ) ;
}
F_31 ( & V_21 -> V_83 ) ;
V_58 = F_23 ( V_21 , V_62 , V_17 ) ;
F_32 ( & V_21 -> V_83 ) ;
break;
case V_84 :
if ( V_57 -> V_69 != V_70 ) {
goto V_71;
}
* ( T_1 * ) V_16 -> V_3 = V_21 -> V_48 ;
V_58 = F_29 ( V_64 , ( T_4 ) 1 ) ;
break;
case V_85 :
if ( V_57 -> V_69 != V_86 ) {
goto V_71;
}
F_31 ( & V_21 -> V_83 ) ;
if ( V_21 -> V_48 && V_60 < V_87
&& V_62 == 0 )
{
T_1 V_48 = V_21 -> V_48 ;
F_21 ( V_21 ) ;
F_23 ( V_21 , V_48 , V_17 ) ;
V_58 = 0 ;
}
F_32 ( & V_21 -> V_83 ) ;
break;
case V_88 :
if ( V_57 -> V_69 != ( V_70 | V_86 ) ) {
goto V_71;
}
if ( ! V_21 -> V_48 ) {
break;
}
if ( V_60 >= V_87 ) {
V_58 = - V_89 ;
break;
}
* ( T_1 * ) V_16 -> V_3 = 0 ;
V_58 = F_29 ( V_64 , ( T_4 ) 1 ) ;
break;
default:
V_71:
F_15 ( V_21 , L_16 ,
V_57 -> V_69 , V_57 -> V_67 ,
V_62 , V_60 , V_64 ) ;
}
if ( V_58 >= 0 ) {
V_16 -> V_15 = V_58 ;
V_16 -> V_66 = V_58 < V_64 ;
V_58 = F_17 ( V_2 -> V_75 , V_16 , V_17 ) ;
if ( V_58 < 0 ) {
F_16 ( V_21 , L_17 , V_58 ) ;
V_16 -> V_29 = 0 ;
F_25 ( V_2 -> V_75 , V_16 ) ;
}
}
return V_58 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
unsigned long V_90 ;
F_34 ( & V_21 -> V_83 , V_90 ) ;
F_21 ( V_21 ) ;
F_35 ( & V_21 -> V_83 , V_90 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
struct V_91 * V_92 ;
F_16 ( V_21 , L_18 ) ;
V_92 = V_21 -> V_92 ;
V_21 -> V_92 = NULL ;
if ( V_92 ) {
F_37 ( V_92 ) ;
}
if ( V_21 -> V_16 ) {
V_21 -> V_16 -> V_15 = V_8 ;
F_7 ( V_2 -> V_75 , V_21 -> V_16 ) ;
}
F_8 ( V_21 ) ;
F_38 ( V_2 , NULL ) ;
}
static int F_39 ( struct V_93 * V_94 )
{
return 0 ;
}
static void F_40 ( struct V_12 * V_16 , T_2 V_95 ,
T_2 V_96 , T_2 V_97 , T_2 V_98 )
{
unsigned V_15 = V_16 -> V_15 ;
T_1 * V_3 = ( T_1 * ) V_16 -> V_3 + V_15 ;
V_3 [ 0 ] = V_95 ;
V_3 [ 1 ] = V_96 ;
V_3 [ 2 ] = V_97 ;
V_3 [ 3 ] = V_98 ;
V_16 -> V_15 = V_15 + 4 ;
}
static void F_41 ( struct V_12 * V_16 ,
struct V_99 * V_100 , T_2 V_101 )
{
T_2 V_95 = V_100 -> V_18 ;
if ( V_101 >= 0xf8 ) {
F_40 ( V_16 , V_95 | 0x0f , V_101 , 0 , 0 ) ;
} else if ( V_101 >= 0xf0 ) {
switch ( V_101 ) {
case 0xf0 :
V_100 -> V_19 [ 0 ] = V_101 ;
V_100 -> V_102 = V_103 ;
break;
case 0xf1 :
case 0xf3 :
V_100 -> V_19 [ 0 ] = V_101 ;
V_100 -> V_102 = V_104 ;
break;
case 0xf2 :
V_100 -> V_19 [ 0 ] = V_101 ;
V_100 -> V_102 = V_105 ;
break;
case 0xf4 :
case 0xf5 :
V_100 -> V_102 = V_106 ;
break;
case 0xf6 :
F_40 ( V_16 , V_95 | 0x05 , 0xf6 , 0 , 0 ) ;
V_100 -> V_102 = V_106 ;
break;
case 0xf7 :
switch ( V_100 -> V_102 ) {
case V_107 :
F_40 ( V_16 ,
V_95 | 0x05 , 0xf7 , 0 , 0 ) ;
break;
case V_103 :
F_40 ( V_16 ,
V_95 | 0x06 , V_100 -> V_19 [ 0 ] , 0xf7 , 0 ) ;
break;
case V_108 :
F_40 ( V_16 ,
V_95 | 0x07 , V_100 -> V_19 [ 0 ] ,
V_100 -> V_19 [ 1 ] , 0xf7 ) ;
break;
}
V_100 -> V_102 = V_106 ;
break;
}
} else if ( V_101 >= 0x80 ) {
V_100 -> V_19 [ 0 ] = V_101 ;
if ( V_101 >= 0xc0 && V_101 <= 0xdf )
V_100 -> V_102 = V_104 ;
else
V_100 -> V_102 = V_105 ;
} else {
switch ( V_100 -> V_102 ) {
case V_104 :
if ( V_100 -> V_19 [ 0 ] < 0xf0 ) {
V_95 |= V_100 -> V_19 [ 0 ] >> 4 ;
} else {
V_95 |= 0x02 ;
V_100 -> V_102 = V_106 ;
}
F_40 ( V_16 , V_95 , V_100 -> V_19 [ 0 ] , V_101 , 0 ) ;
break;
case V_105 :
V_100 -> V_19 [ 1 ] = V_101 ;
V_100 -> V_102 = V_109 ;
break;
case V_109 :
if ( V_100 -> V_19 [ 0 ] < 0xf0 ) {
V_95 |= V_100 -> V_19 [ 0 ] >> 4 ;
V_100 -> V_102 = V_105 ;
} else {
V_95 |= 0x03 ;
V_100 -> V_102 = V_106 ;
}
F_40 ( V_16 ,
V_95 , V_100 -> V_19 [ 0 ] , V_100 -> V_19 [ 1 ] , V_101 ) ;
break;
case V_107 :
V_100 -> V_19 [ 0 ] = V_101 ;
V_100 -> V_102 = V_103 ;
break;
case V_103 :
V_100 -> V_19 [ 1 ] = V_101 ;
V_100 -> V_102 = V_108 ;
break;
case V_108 :
F_40 ( V_16 ,
V_95 | 0x04 , V_100 -> V_19 [ 0 ] , V_100 -> V_19 [ 1 ] , V_101 ) ;
V_100 -> V_102 = V_107 ;
break;
}
}
}
static void F_14 ( struct V_20 * V_21 , struct V_12 * V_16 )
{
struct V_13 * V_14 = V_21 -> V_31 ;
struct V_99 * V_100 = & V_21 -> V_110 ;
if ( ! V_14 ) {
return;
}
if ( ! V_16 ) {
V_16 = F_3 ( V_14 , V_45 ) ;
}
if ( ! V_16 ) {
ERROR ( V_21 , L_19 ) ;
return;
}
V_16 -> V_15 = 0 ;
V_16 -> V_46 = F_13 ;
if ( V_100 -> V_111 ) {
while ( V_16 -> V_15 + 3 < V_45 ) {
T_2 V_101 ;
if ( F_42 ( V_21 -> V_112 , & V_101 , 1 )
!= 1 )
{
V_100 -> V_111 = 0 ;
break;
}
F_41 ( V_16 , V_100 , V_101 ) ;
}
}
if ( V_16 -> V_15 > 0 ) {
F_17 ( V_14 , V_16 , V_17 ) ;
} else {
F_7 ( V_14 , V_16 ) ;
}
}
static void F_43 ( unsigned long V_19 )
{
struct V_20 * V_21 = (struct V_20 * ) V_19 ;
F_14 ( V_21 , NULL ) ;
}
static int F_44 ( struct V_113 * V_114 )
{
struct V_20 * V_21 = V_114 -> V_115 -> V_116 ;
F_15 ( V_21 , L_20 ) ;
V_21 -> V_112 = V_114 ;
V_21 -> V_110 . V_102 = V_106 ;
return 0 ;
}
static int F_45 ( struct V_113 * V_114 )
{
struct V_20 * V_21 = V_114 -> V_115 -> V_116 ;
F_15 ( V_21 , L_21 ) ;
return 0 ;
}
static void F_46 ( struct V_113 * V_114 , int V_117 )
{
struct V_20 * V_21 = V_114 -> V_115 -> V_116 ;
F_15 ( V_21 , L_22 , V_117 ) ;
V_21 -> V_110 . V_111 = V_117 ;
if ( V_117 ) {
F_47 ( & V_21 -> V_118 ) ;
}
}
static int F_48 ( struct V_113 * V_114 )
{
struct V_20 * V_21 = V_114 -> V_115 -> V_116 ;
F_15 ( V_21 , L_23 ) ;
V_21 -> V_23 = V_114 ;
return 0 ;
}
static int F_49 ( struct V_113 * V_114 )
{
struct V_20 * V_21 = V_114 -> V_115 -> V_116 ;
F_15 ( V_21 , L_24 ) ;
return 0 ;
}
static void F_50 ( struct V_113 * V_114 , int V_117 )
{
struct V_20 * V_21 = V_114 -> V_115 -> V_116 ;
F_15 ( V_21 , L_25 , V_117 ) ;
if ( V_117 ) {
F_51 ( V_114 -> V_24 , & V_21 -> V_25 ) ;
} else {
F_52 ( V_114 -> V_24 , & V_21 -> V_25 ) ;
}
}
static int F_53 ( struct V_20 * V_21 )
{
struct V_91 * V_92 ;
struct V_119 * V_115 ;
int V_39 ;
int V_120 = 1 ;
int V_121 = 1 ;
static struct V_122 V_123 = {
. V_124 = F_39 ,
} ;
V_39 = F_54 ( V_4 , V_125 , V_126 , 0 , & V_92 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_26 ) ;
goto V_42;
}
V_21 -> V_92 = V_92 ;
V_39 = F_55 ( V_92 , V_127 , V_21 , & V_123 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_27 , V_39 ) ;
goto V_42;
}
strcpy ( V_92 -> V_128 , V_129 ) ;
strcpy ( V_92 -> V_129 , V_129 ) ;
strcpy ( V_92 -> V_130 , V_130 ) ;
V_21 -> V_110 . V_21 = V_21 ;
V_21 -> V_110 . V_111 = 0 ;
F_56 ( V_92 , L_28 ) ;
V_39 = F_57 ( V_92 , L_29 , 0 ,
V_120 , V_121 , & V_115 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_30 , V_39 ) ;
goto V_42;
}
V_21 -> V_115 = V_115 ;
strcpy ( V_115 -> V_35 , V_92 -> V_130 ) ;
V_115 -> V_131 = V_132 |
V_133 |
V_134 ;
V_115 -> V_116 = V_21 ;
F_58 ( V_115 , V_135 , & V_136 ) ;
F_58 ( V_115 , V_137 , & V_138 ) ;
F_59 ( V_92 , & V_21 -> V_2 -> V_21 ) ;
V_39 = F_60 ( V_92 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_31 ) ;
goto V_42;
}
F_15 ( V_21 , L_32 ) ;
return 0 ;
V_42:
if ( V_21 -> V_92 ) {
F_37 ( V_21 -> V_92 ) ;
V_21 -> V_92 = NULL ;
}
return V_39 ;
}
static int T_5 F_61 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_13 * V_31 , * V_30 ;
int V_139 , V_39 = 0 ;
if ( V_140 ) {
if ( ! V_141 ) {
F_62 ( L_33 ) ;
return - V_51 ;
}
V_73 . V_140 = F_63 ( V_140 ) ;
V_73 . V_141 = F_63 ( V_141 ) ;
if ( V_142 ) {
V_73 . V_142 = F_63 ( V_142 ) ;
}
}
if ( V_143 ) {
F_64 ( V_144 , V_143 , sizeof( V_144 ) ) ;
} else {
snprintf ( V_144 , sizeof( V_144 ) , L_34 ,
F_65 () -> V_145 , F_65 () -> V_146 ,
V_2 -> V_35 ) ;
}
if ( V_147 ) {
F_64 ( V_148 , V_147 , sizeof( V_148 ) ) ;
}
if ( V_149 ) {
V_73 . V_149 = V_150 ,
F_64 ( V_151 , V_149 , sizeof( V_151 ) ) ;
}
F_66 ( V_2 ) ;
V_31 = F_67 ( V_2 , & V_41 ) ;
if ( ! V_31 ) {
V_152:
F_62 ( L_35 ,
V_130 , V_2 -> V_35 ) ;
return - V_51 ;
}
V_153 = V_31 -> V_35 ;
V_31 -> V_22 = V_31 ;
V_30 = F_67 ( V_2 , & V_43 ) ;
if ( ! V_30 ) {
goto V_152;
}
V_154 = V_30 -> V_35 ;
V_30 -> V_22 = V_30 ;
V_139 = F_68 ( V_2 ) ;
if ( V_139 >= 0 ) {
V_73 . V_142 = F_63 ( 0x0200 + V_139 ) ;
} else {
F_69 ( L_36 ,
V_130 , V_2 -> V_35 ) ;
V_73 . V_142 = F_63 ( 0x9999 ) ;
}
V_21 = F_70 ( sizeof( * V_21 ) , V_155 ) ;
if ( ! V_21 ) {
return - V_47 ;
}
F_71 ( & V_21 -> V_83 ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_30 = V_30 ;
F_38 ( V_2 , V_21 ) ;
F_72 ( & V_21 -> V_118 , F_43 , ( unsigned long ) V_21 ) ;
V_21 -> V_16 = F_3 ( V_2 -> V_75 , V_8 ) ;
if ( ! V_21 -> V_16 ) {
V_39 = - V_47 ;
goto V_42;
}
V_21 -> V_16 -> V_46 = F_25 ;
V_2 -> V_75 -> V_22 = V_21 ;
F_24 ( V_21 , L_37 V_156 L_38 , V_129 ) ;
F_24 ( V_21 , L_39 , V_2 -> V_35 ,
V_154 , V_153 ) ;
V_39 = F_53 ( V_21 ) ;
if ( V_39 < 0 ) {
goto V_42;
}
F_15 ( V_21 , L_40 ) ;
return 0 ;
V_42:
F_36 ( V_2 ) ;
return V_39 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
if ( V_2 -> V_52 == V_157 ) {
return;
}
F_16 ( V_21 , L_41 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
F_16 ( V_21 , L_42 ) ;
}
static int T_5 F_75 ( void )
{
return F_76 ( & V_158 , F_61 ) ;
}
static void T_6 F_77 ( void )
{
F_78 ( & V_158 ) ;
}
