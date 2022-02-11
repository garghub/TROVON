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
V_39 = F_20 ( V_21 -> V_31 , & V_40 ) ;
if ( V_39 ) {
ERROR ( V_21 , L_4 , V_21 -> V_31 -> V_35 , V_39 ) ;
goto V_41;
}
V_21 -> V_31 -> V_22 = V_21 ;
V_39 = F_20 ( V_21 -> V_30 , & V_42 ) ;
if ( V_39 ) {
ERROR ( V_21 , L_4 , V_21 -> V_30 -> V_35 , V_39 ) ;
goto V_41;
}
V_21 -> V_30 -> V_22 = V_21 ;
V_14 = V_21 -> V_30 ;
for ( V_26 = 0 ; V_26 < V_43 && V_39 == 0 ; V_26 ++ ) {
V_16 = F_3 ( V_14 , V_44 ) ;
if ( V_16 ) {
V_16 -> V_45 = F_13 ;
V_39 = F_17 ( V_14 , V_16 , V_17 ) ;
if ( V_39 ) {
F_16 ( V_21 , L_5 , V_14 -> V_35 , V_39 ) ;
}
} else {
V_39 = - V_46 ;
}
}
V_41:
return V_39 ;
}
static void F_21 ( struct V_20 * V_21 )
{
if ( V_21 -> V_47 == 0 ) {
return;
}
F_16 ( V_21 , L_6 ) ;
F_22 ( V_21 -> V_31 ) ;
F_22 ( V_21 -> V_30 ) ;
V_21 -> V_47 = 0 ;
}
static int
F_23 ( struct V_20 * V_21 , unsigned V_24 , T_3 V_38 )
{
int V_48 = 0 ;
struct V_1 * V_2 = V_21 -> V_2 ;
#if 0
if (number == dev->config) {
return 0;
}
#endif
F_21 ( V_21 ) ;
switch ( V_24 ) {
case V_49 :
V_48 = F_19 ( V_21 , V_38 ) ;
break;
default:
V_48 = - V_6 ;
case 0 :
return V_48 ;
}
if ( ! V_48 && ( ! V_21 -> V_31 || ! V_21 -> V_30 ) ) {
V_48 = - V_50 ;
}
if ( V_48 ) {
F_21 ( V_21 ) ;
} else {
char * V_51 ;
switch ( V_2 -> V_51 ) {
case V_52 : V_51 = L_7 ; break;
case V_53 : V_51 = L_8 ; break;
case V_54 : V_51 = L_9 ; break;
default: V_51 = L_10 ; break;
}
V_21 -> V_47 = V_24 ;
F_24 ( V_21 , L_11 , V_51 ) ;
}
return V_48 ;
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
const struct V_55 * V_56 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
struct V_12 * V_16 = V_21 -> V_16 ;
int V_57 = - V_58 ;
T_4 V_59 = F_28 ( V_56 -> V_60 ) ;
T_4 V_61 = F_28 ( V_56 -> V_62 ) ;
T_4 V_63 = F_28 ( V_56 -> V_64 ) ;
V_16 -> V_65 = 0 ;
switch ( V_56 -> V_66 ) {
case V_67 :
if ( V_56 -> V_68 != V_69 ) {
goto V_70;
}
switch ( V_61 >> 8 ) {
case V_71 :
V_57 = F_29 ( V_63 , ( T_4 ) sizeof( V_72 ) ) ;
memcpy ( V_16 -> V_3 , & V_72 , V_57 ) ;
break;
case V_73 :
V_57 = F_1 ( V_2 , V_16 -> V_3 ,
V_61 >> 8 ,
V_61 & 0xff ) ;
if ( V_57 >= 0 ) {
V_57 = F_29 ( V_63 , ( T_4 ) V_57 ) ;
}
break;
case V_74 :
V_57 = F_30 ( & V_75 ,
V_61 & 0xff , V_16 -> V_3 ) ;
if ( V_57 >= 0 ) {
V_57 = F_29 ( V_63 , ( T_4 ) V_57 ) ;
}
break;
}
break;
case V_76 :
if ( V_56 -> V_68 != 0 ) {
goto V_70;
}
if ( V_2 -> V_77 ) {
F_16 ( V_21 , L_13 ) ;
} else if ( V_2 -> V_78 ) {
F_16 ( V_21 , L_14 ) ;
} else {
F_15 ( V_21 , L_15 ) ;
}
F_31 ( & V_21 -> V_79 ) ;
V_57 = F_23 ( V_21 , V_61 , V_17 ) ;
F_32 ( & V_21 -> V_79 ) ;
break;
case V_80 :
if ( V_56 -> V_68 != V_69 ) {
goto V_70;
}
* ( T_1 * ) V_16 -> V_3 = V_21 -> V_47 ;
V_57 = F_29 ( V_63 , ( T_4 ) 1 ) ;
break;
case V_81 :
if ( V_56 -> V_68 != V_82 ) {
goto V_70;
}
F_31 ( & V_21 -> V_79 ) ;
if ( V_21 -> V_47 && V_59 < V_83
&& V_61 == 0 )
{
T_1 V_47 = V_21 -> V_47 ;
F_21 ( V_21 ) ;
F_23 ( V_21 , V_47 , V_17 ) ;
V_57 = 0 ;
}
F_32 ( & V_21 -> V_79 ) ;
break;
case V_84 :
if ( V_56 -> V_68 != ( V_69 | V_82 ) ) {
goto V_70;
}
if ( ! V_21 -> V_47 ) {
break;
}
if ( V_59 >= V_83 ) {
V_57 = - V_85 ;
break;
}
* ( T_1 * ) V_16 -> V_3 = 0 ;
V_57 = F_29 ( V_63 , ( T_4 ) 1 ) ;
break;
default:
V_70:
F_15 ( V_21 , L_16 ,
V_56 -> V_68 , V_56 -> V_66 ,
V_61 , V_59 , V_63 ) ;
}
if ( V_57 >= 0 ) {
V_16 -> V_15 = V_57 ;
V_16 -> V_65 = V_57 < V_63 ;
V_57 = F_17 ( V_2 -> V_86 , V_16 , V_17 ) ;
if ( V_57 < 0 ) {
F_16 ( V_21 , L_17 , V_57 ) ;
V_16 -> V_29 = 0 ;
F_25 ( V_2 -> V_86 , V_16 ) ;
}
}
return V_57 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
unsigned long V_87 ;
F_34 ( & V_21 -> V_79 , V_87 ) ;
F_21 ( V_21 ) ;
F_35 ( & V_21 -> V_79 , V_87 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
struct V_88 * V_89 ;
F_16 ( V_21 , L_18 ) ;
V_89 = V_21 -> V_89 ;
V_21 -> V_89 = NULL ;
if ( V_89 ) {
F_37 ( V_89 ) ;
}
if ( V_21 -> V_16 ) {
V_21 -> V_16 -> V_15 = V_8 ;
F_7 ( V_2 -> V_86 , V_21 -> V_16 ) ;
}
F_8 ( V_21 ) ;
F_38 ( V_2 , NULL ) ;
}
static int F_39 ( struct V_90 * V_91 )
{
return 0 ;
}
static void F_40 ( struct V_12 * V_16 , T_2 V_92 ,
T_2 V_93 , T_2 V_94 , T_2 V_95 )
{
unsigned V_15 = V_16 -> V_15 ;
T_1 * V_3 = ( T_1 * ) V_16 -> V_3 + V_15 ;
V_3 [ 0 ] = V_92 ;
V_3 [ 1 ] = V_93 ;
V_3 [ 2 ] = V_94 ;
V_3 [ 3 ] = V_95 ;
V_16 -> V_15 = V_15 + 4 ;
}
static void F_41 ( struct V_12 * V_16 ,
struct V_96 * V_97 , T_2 V_98 )
{
T_2 V_92 = V_97 -> V_18 ;
if ( V_98 >= 0xf8 ) {
F_40 ( V_16 , V_92 | 0x0f , V_98 , 0 , 0 ) ;
} else if ( V_98 >= 0xf0 ) {
switch ( V_98 ) {
case 0xf0 :
V_97 -> V_19 [ 0 ] = V_98 ;
V_97 -> V_99 = V_100 ;
break;
case 0xf1 :
case 0xf3 :
V_97 -> V_19 [ 0 ] = V_98 ;
V_97 -> V_99 = V_101 ;
break;
case 0xf2 :
V_97 -> V_19 [ 0 ] = V_98 ;
V_97 -> V_99 = V_102 ;
break;
case 0xf4 :
case 0xf5 :
V_97 -> V_99 = V_103 ;
break;
case 0xf6 :
F_40 ( V_16 , V_92 | 0x05 , 0xf6 , 0 , 0 ) ;
V_97 -> V_99 = V_103 ;
break;
case 0xf7 :
switch ( V_97 -> V_99 ) {
case V_104 :
F_40 ( V_16 ,
V_92 | 0x05 , 0xf7 , 0 , 0 ) ;
break;
case V_100 :
F_40 ( V_16 ,
V_92 | 0x06 , V_97 -> V_19 [ 0 ] , 0xf7 , 0 ) ;
break;
case V_105 :
F_40 ( V_16 ,
V_92 | 0x07 , V_97 -> V_19 [ 0 ] ,
V_97 -> V_19 [ 1 ] , 0xf7 ) ;
break;
}
V_97 -> V_99 = V_103 ;
break;
}
} else if ( V_98 >= 0x80 ) {
V_97 -> V_19 [ 0 ] = V_98 ;
if ( V_98 >= 0xc0 && V_98 <= 0xdf )
V_97 -> V_99 = V_101 ;
else
V_97 -> V_99 = V_102 ;
} else {
switch ( V_97 -> V_99 ) {
case V_101 :
if ( V_97 -> V_19 [ 0 ] < 0xf0 ) {
V_92 |= V_97 -> V_19 [ 0 ] >> 4 ;
} else {
V_92 |= 0x02 ;
V_97 -> V_99 = V_103 ;
}
F_40 ( V_16 , V_92 , V_97 -> V_19 [ 0 ] , V_98 , 0 ) ;
break;
case V_102 :
V_97 -> V_19 [ 1 ] = V_98 ;
V_97 -> V_99 = V_106 ;
break;
case V_106 :
if ( V_97 -> V_19 [ 0 ] < 0xf0 ) {
V_92 |= V_97 -> V_19 [ 0 ] >> 4 ;
V_97 -> V_99 = V_102 ;
} else {
V_92 |= 0x03 ;
V_97 -> V_99 = V_103 ;
}
F_40 ( V_16 ,
V_92 , V_97 -> V_19 [ 0 ] , V_97 -> V_19 [ 1 ] , V_98 ) ;
break;
case V_104 :
V_97 -> V_19 [ 0 ] = V_98 ;
V_97 -> V_99 = V_100 ;
break;
case V_100 :
V_97 -> V_19 [ 1 ] = V_98 ;
V_97 -> V_99 = V_105 ;
break;
case V_105 :
F_40 ( V_16 ,
V_92 | 0x04 , V_97 -> V_19 [ 0 ] , V_97 -> V_19 [ 1 ] , V_98 ) ;
V_97 -> V_99 = V_104 ;
break;
}
}
}
static void F_14 ( struct V_20 * V_21 , struct V_12 * V_16 )
{
struct V_13 * V_14 = V_21 -> V_31 ;
struct V_96 * V_97 = & V_21 -> V_107 ;
if ( ! V_14 ) {
return;
}
if ( ! V_16 ) {
V_16 = F_3 ( V_14 , V_44 ) ;
}
if ( ! V_16 ) {
ERROR ( V_21 , L_19 ) ;
return;
}
V_16 -> V_15 = 0 ;
V_16 -> V_45 = F_13 ;
if ( V_97 -> V_108 ) {
while ( V_16 -> V_15 + 3 < V_44 ) {
T_2 V_98 ;
if ( F_42 ( V_21 -> V_109 , & V_98 , 1 )
!= 1 )
{
V_97 -> V_108 = 0 ;
break;
}
F_41 ( V_16 , V_97 , V_98 ) ;
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
static int F_44 ( struct V_110 * V_111 )
{
struct V_20 * V_21 = V_111 -> V_112 -> V_113 ;
F_15 ( V_21 , L_20 ) ;
V_21 -> V_109 = V_111 ;
V_21 -> V_107 . V_99 = V_103 ;
return 0 ;
}
static int F_45 ( struct V_110 * V_111 )
{
struct V_20 * V_21 = V_111 -> V_112 -> V_113 ;
F_15 ( V_21 , L_21 ) ;
return 0 ;
}
static void F_46 ( struct V_110 * V_111 , int V_114 )
{
struct V_20 * V_21 = V_111 -> V_112 -> V_113 ;
F_15 ( V_21 , L_22 , V_114 ) ;
V_21 -> V_107 . V_108 = V_114 ;
if ( V_114 ) {
F_47 ( & V_21 -> V_115 ) ;
}
}
static int F_48 ( struct V_110 * V_111 )
{
struct V_20 * V_21 = V_111 -> V_112 -> V_113 ;
F_15 ( V_21 , L_23 ) ;
V_21 -> V_23 = V_111 ;
return 0 ;
}
static int F_49 ( struct V_110 * V_111 )
{
struct V_20 * V_21 = V_111 -> V_112 -> V_113 ;
F_15 ( V_21 , L_24 ) ;
return 0 ;
}
static void F_50 ( struct V_110 * V_111 , int V_114 )
{
struct V_20 * V_21 = V_111 -> V_112 -> V_113 ;
F_15 ( V_21 , L_25 , V_114 ) ;
if ( V_114 ) {
F_51 ( V_111 -> V_24 , & V_21 -> V_25 ) ;
} else {
F_52 ( V_111 -> V_24 , & V_21 -> V_25 ) ;
}
}
static int F_53 ( struct V_20 * V_21 )
{
struct V_88 * V_89 ;
struct V_116 * V_112 ;
int V_39 ;
int V_117 = 1 ;
int V_118 = 1 ;
static struct V_119 V_120 = {
. V_121 = F_39 ,
} ;
V_39 = F_54 ( V_4 , V_122 , V_123 , 0 , & V_89 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_26 ) ;
goto V_41;
}
V_21 -> V_89 = V_89 ;
V_39 = F_55 ( V_89 , V_124 , V_21 , & V_120 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_27 , V_39 ) ;
goto V_41;
}
strcpy ( V_89 -> V_125 , V_126 ) ;
strcpy ( V_89 -> V_126 , V_126 ) ;
strcpy ( V_89 -> V_127 , V_127 ) ;
V_21 -> V_107 . V_21 = V_21 ;
V_21 -> V_107 . V_108 = 0 ;
F_56 ( V_89 , L_28 ) ;
V_39 = F_57 ( V_89 , L_29 , 0 ,
V_117 , V_118 , & V_112 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_30 , V_39 ) ;
goto V_41;
}
V_21 -> V_112 = V_112 ;
strcpy ( V_112 -> V_35 , V_89 -> V_127 ) ;
V_112 -> V_128 = V_129 |
V_130 |
V_131 ;
V_112 -> V_113 = V_21 ;
F_58 ( V_112 , V_132 , & V_133 ) ;
F_58 ( V_112 , V_134 , & V_135 ) ;
F_59 ( V_89 , & V_21 -> V_2 -> V_21 ) ;
V_39 = F_60 ( V_89 ) ;
if ( V_39 < 0 ) {
ERROR ( V_21 , L_31 ) ;
goto V_41;
}
F_15 ( V_21 , L_32 ) ;
return 0 ;
V_41:
if ( V_21 -> V_89 ) {
F_37 ( V_21 -> V_89 ) ;
V_21 -> V_89 = NULL ;
}
return V_39 ;
}
static int T_5 F_61 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_13 * V_31 , * V_30 ;
int V_136 , V_39 = 0 ;
if ( V_137 ) {
if ( ! V_138 ) {
F_62 ( L_33 ) ;
return - V_50 ;
}
V_72 . V_137 = F_63 ( V_137 ) ;
V_72 . V_138 = F_63 ( V_138 ) ;
if ( V_139 ) {
V_72 . V_139 = F_63 ( V_139 ) ;
}
}
if ( V_140 ) {
F_64 ( V_141 , V_140 , sizeof( V_141 ) ) ;
} else {
snprintf ( V_141 , sizeof( V_141 ) , L_34 ,
F_65 () -> V_142 , F_65 () -> V_143 ,
V_2 -> V_35 ) ;
}
if ( V_144 ) {
F_64 ( V_145 , V_144 , sizeof( V_145 ) ) ;
}
if ( V_146 ) {
V_72 . V_146 = V_147 ,
F_64 ( V_148 , V_146 , sizeof( V_148 ) ) ;
}
F_66 ( V_2 ) ;
V_31 = F_67 ( V_2 , & V_40 ) ;
if ( ! V_31 ) {
V_149:
F_62 ( L_35 ,
V_127 , V_2 -> V_35 ) ;
return - V_50 ;
}
V_150 = V_31 -> V_35 ;
V_31 -> V_22 = V_31 ;
V_30 = F_67 ( V_2 , & V_42 ) ;
if ( ! V_30 ) {
goto V_149;
}
V_151 = V_30 -> V_35 ;
V_30 -> V_22 = V_30 ;
V_136 = F_68 ( V_2 ) ;
if ( V_136 >= 0 ) {
V_72 . V_139 = F_63 ( 0x0200 + V_136 ) ;
} else {
F_69 ( L_36 ,
V_127 , V_2 -> V_35 ) ;
V_72 . V_139 = F_63 ( 0x9999 ) ;
}
V_21 = F_70 ( sizeof( * V_21 ) , V_152 ) ;
if ( ! V_21 ) {
return - V_46 ;
}
F_71 ( & V_21 -> V_79 ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_30 = V_30 ;
F_38 ( V_2 , V_21 ) ;
F_72 ( & V_21 -> V_115 , F_43 , ( unsigned long ) V_21 ) ;
V_21 -> V_16 = F_3 ( V_2 -> V_86 , V_8 ) ;
if ( ! V_21 -> V_16 ) {
V_39 = - V_46 ;
goto V_41;
}
V_21 -> V_16 -> V_45 = F_25 ;
V_72 . V_153 = V_2 -> V_86 -> V_154 ;
V_2 -> V_86 -> V_22 = V_21 ;
F_24 ( V_21 , L_37 V_155 L_38 , V_126 ) ;
F_24 ( V_21 , L_39 , V_2 -> V_35 ,
V_151 , V_150 ) ;
V_39 = F_53 ( V_21 ) ;
if ( V_39 < 0 ) {
goto V_41;
}
F_15 ( V_21 , L_40 ) ;
return 0 ;
V_41:
F_36 ( V_2 ) ;
return V_39 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_27 ( V_2 ) ;
if ( V_2 -> V_51 == V_156 ) {
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
return F_76 ( & V_157 , F_61 ) ;
}
static void T_6 F_77 ( void )
{
F_78 ( & V_157 ) ;
}
