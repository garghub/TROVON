static const T_1 *
F_1 ( T_2 * V_1 , T_3 V_2 , T_4 * V_3 )
{
T_4 V_4 ;
V_4 = F_2 ( V_1 , V_2 ) ;
if ( V_3 )
* V_3 = V_4 + 1 ;
if ( V_4 == 0xFFFF )
V_4 = 0 ;
return F_3 ( V_1 , V_2 + 2 , F_4 ( V_4 , V_5 ) ) ;
}
static void
F_5 ( T_2 * V_1 , T_5 * V_6 , T_6 * V_7 , T_7 * V_8 )
{
int V_9 = 0 ;
T_8 V_10 = 0 ;
int V_11 ;
if ( V_7 )
F_6 ( V_7 , V_12 , V_1 , V_9 , 2 , V_13 ) ;
V_9 += 2 ;
if ( V_7 )
F_6 ( V_7 , V_14 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
V_10 = F_7 ( V_1 , V_9 ) ;
F_8 ( V_6 -> V_16 , V_17 , F_9 ( V_10 , V_18 , L_1 ) ) ;
if ( V_7 )
F_6 ( V_7 , V_19 , V_1 , V_9 , 1 , V_15 ) ;
V_9 += 1 ;
switch ( V_10 ) {
case V_20 :
if ( V_7 )
F_6 ( V_7 , V_21 , V_1 , V_9 , 1 , V_15 ) ;
break;
case V_22 :
{
const T_1 * V_23 ;
T_4 V_24 ;
T_4 V_25 ;
T_4 V_26 ;
V_26 = F_2 ( V_1 , V_9 ) ;
F_10 ( V_6 -> V_16 , V_17 , L_2 , V_26 ) ;
if ( V_7 )
F_6 ( V_7 , V_27 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
V_23 = F_1 ( V_1 , V_9 , & V_24 ) ;
F_10 ( V_6 -> V_16 , V_17 , L_3 , V_23 ) ;
if ( V_7 )
F_11 ( V_7 , V_28 , V_1 , V_9 , V_24 + 2 , V_23 ) ;
V_9 += V_24 + 2 ;
V_25 = F_2 ( V_1 , V_9 ) ;
if ( V_7 )
F_6 ( V_7 , V_29 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
for( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
T_8 V_30 ;
T_8 V_31 ;
const T_1 * V_32 ;
T_4 V_33 , V_34 ;
const T_1 * V_35 = NULL ;
T_9 * V_36 ;
int V_37 = V_9 ;
V_30 = F_7 ( V_1 , V_9 ) ;
if ( V_30 == 0xA0 ) {
V_9 += 1 ;
V_31 = F_7 ( V_1 , V_9 ) ;
V_9 += 1 ;
if ( V_31 >= F_12 ( V_38 ) )
V_31 = 0 ;
V_32 = F_1 ( V_1 , V_9 , & V_33 ) ;
if ( V_7 ) {
V_36 = F_13 ( * V_38 [ V_31 ] ) ;
F_14 ( V_7 , * V_38 [ V_31 ] ,
V_1 , V_37 , 2 + V_33 + 2 , V_32 ,
L_4 , V_36 -> V_39 , V_32 ) ;
}
V_9 += V_33 + 2 ;
#if 0
if (hid == 0x08)
cl = 1;
#endif
} else {
V_35 = F_1 ( V_1 , V_9 , & V_34 ) ;
V_9 += V_34 + 2 ;
V_32 = F_1 ( V_1 , V_9 , & V_33 ) ;
if ( V_7 ) {
F_14 ( V_7 , V_40 ,
V_1 , V_37 , V_34 + 2 + V_33 + 2 ,
F_15 ( L_4 , V_35 , V_32 ) ,
L_4 , V_35 , V_32 ) ;
}
V_9 += V_33 + 2 ;
}
}
break;
}
case V_41 :
{
T_4 V_42 ;
V_42 = F_2 ( V_1 , V_9 ) ;
V_8 -> V_43 = V_42 ;
if ( V_7 )
F_6 ( V_7 , V_44 , V_1 , V_9 , 2 , V_15 ) ;
break;
}
case V_45 :
break;
default:
if ( V_7 )
F_6 ( V_7 , V_46 , V_1 , V_9 + 2 , - 1 , V_47 | V_13 ) ;
break;
}
}
static void
F_16 ( T_2 * V_1 , T_6 * V_7 , T_7 * V_8 )
{
T_4 V_43 ;
T_4 V_48 ;
int V_9 = 0 ;
F_6 ( V_7 , V_12 , V_1 , V_9 , 2 , V_13 ) ;
V_9 += 2 ;
V_48 = F_2 ( V_1 , V_9 ) ;
F_6 ( V_7 , V_14 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
if ( V_48 == 0 )
{
V_8 -> V_43 = 0 ;
return;
}
V_43 = F_2 ( V_1 , V_9 ) ;
if ( V_43 == 0 ) {
V_8 -> V_43 = 0 ;
return;
}
V_8 -> V_43 -= V_43 ;
F_6 ( V_7 , V_46 , V_1 , V_9 + 2 , V_43 , V_47 | V_13 ) ;
}
static void
F_17 ( T_2 * V_1 , T_5 * V_6 ,
T_6 * V_7 ,
T_7 * V_8 )
{
int V_9 = 0 ;
T_8 V_49 ;
T_8 V_50 ;
const T_1 * V_51 ;
T_4 V_52 ;
const T_1 * V_53 ;
T_4 V_54 ;
const T_1 * V_55 ;
T_4 V_56 ;
const T_1 * V_57 ;
T_4 V_58 ;
const T_1 * V_59 ;
T_4 V_60 ;
T_10 V_25 ;
T_10 V_11 ;
if ( V_7 )
F_6 ( V_7 , V_12 , V_1 , V_9 , 2 , V_13 ) ;
V_9 += 2 ;
if ( V_7 )
F_6 ( V_7 , V_14 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
V_50 = F_7 ( V_1 , 4 ) ;
if ( V_7 )
F_6 ( V_7 , V_19 , V_1 , V_9 , 1 , V_15 ) ;
V_9 += 1 ;
if ( V_50 == V_61 ) {
F_8 ( V_6 -> V_16 , V_17 , L_5 ) ;
return;
}
V_49 = F_7 ( V_1 , V_9 ) ;
F_8 ( V_6 -> V_16 , V_17 , F_9 ( V_49 , V_62 , L_6 ) ) ;
if ( V_7 )
F_6 ( V_7 , V_63 , V_1 , V_9 , 1 , V_15 ) ;
V_9 += 1 ;
V_51 = F_1 ( V_1 , V_9 , & V_52 ) ;
if ( V_7 )
F_11 ( V_7 , V_64 , V_1 , V_9 , V_52 + 2 , V_51 ) ;
V_9 = V_9 + V_52 + 2 ;
V_53 = F_1 ( V_1 , V_9 , & V_54 ) ;
if ( V_7 )
F_11 ( V_7 , V_65 , V_1 , V_9 , V_54 + 2 , V_53 ) ;
V_9 = V_9 + V_54 + 2 ;
F_10 ( V_6 -> V_16 , V_17 , L_7 , V_53 , V_51 ) ;
V_55 = F_1 ( V_1 , V_9 , & V_56 ) ;
if ( V_7 )
F_11 ( V_7 , V_66 , V_1 , V_9 , V_56 + 2 , V_55 ) ;
V_9 = V_9 + V_56 + 2 ;
V_57 = F_1 ( V_1 , V_9 , & V_58 ) ;
if ( V_7 )
F_11 ( V_7 , V_67 , V_1 , V_9 , V_58 + 2 , V_57 ) ;
V_9 = V_9 + V_58 + 2 ;
V_59 = F_1 ( V_1 , V_9 , & V_60 ) ;
if ( V_7 )
F_11 ( V_7 , V_68 , V_1 , V_9 , V_60 + 2 , V_59 ) ;
V_9 = V_9 + V_60 + 2 ;
if ( V_7 )
F_6 ( V_7 , V_69 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
if ( V_7 )
F_6 ( V_7 , V_70 , V_1 , V_9 , 1 , V_13 ) ;
V_9 += 1 ;
V_25 = F_2 ( V_1 , V_9 ) ;
if ( V_7 )
F_6 ( V_7 , V_29 , V_1 , V_9 , 2 , V_15 ) ;
V_9 += 2 ;
V_8 -> V_43 = 0 ;
for( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
T_8 V_30 ;
T_8 V_31 ;
const T_1 * V_35 = NULL ;
T_9 * V_36 ;
int V_37 = V_9 ;
int V_71 = 0 ;
const T_1 * V_32 ;
T_4 V_33 , V_34 ;
V_30 = F_7 ( V_1 , V_9 ) ;
if ( V_30 == 0xA0 ) {
V_9 += 1 ;
V_31 = F_7 ( V_1 , V_9 ) ;
V_9 += 1 ;
if ( V_31 >= F_12 ( V_72 ) )
V_31 = 0 ;
V_32 = F_1 ( V_1 , V_9 , & V_33 ) ;
if ( V_7 ) {
V_36 = F_13 ( * V_72 [ V_31 ] ) ;
F_14 ( V_7 , * V_72 [ V_31 ] ,
V_1 , V_37 , 2 + V_33 + 2 , V_32 ,
L_4 , V_36 -> V_39 , V_32 ) ;
}
V_9 += V_33 + 2 ;
if ( V_31 == 0x08 )
V_71 = 1 ;
} else {
V_35 = F_1 ( V_1 , V_9 , & V_34 ) ;
V_9 += V_34 + 2 ;
V_32 = F_1 ( V_1 , V_9 , & V_33 ) ;
if ( V_7 ) {
F_14 ( V_7 , V_40 ,
V_1 , V_37 , V_34 + 2 + V_33 + 2 ,
F_15 ( L_4 , V_35 , V_32 ) ,
L_4 , V_35 , V_32 ) ;
}
V_9 += V_33 + 2 ;
}
if ( V_71 ) {
V_71 = atoi ( V_32 ) ;
V_8 -> V_43 = V_71 ;
}
}
while( F_18 ( V_1 , V_9 ) > 0 ) {
T_8 V_73 ;
const T_1 * V_74 = NULL ;
const T_1 * V_75 ;
T_4 V_76 , V_77 ;
T_9 * V_36 ;
int V_78 = V_9 ;
V_73 = F_7 ( V_1 , V_9 ) ;
V_9 += 1 ;
if ( V_73 == 0xFF ) {
break;
}
if ( V_73 == 0x0A ) {
V_74 = F_1 ( V_1 , V_9 , & V_77 ) ;
V_9 += V_77 + 2 ;
V_75 = F_1 ( V_1 , V_9 , & V_76 ) ;
V_9 += V_76 + 2 ;
if ( V_7 ) {
F_14 ( V_7 , V_79 ,
V_1 , V_78 , 1 + V_77 + 2 + V_76 + 2 ,
F_15 ( L_4 , V_74 , V_75 ) ,
L_4 , V_74 , V_75 ) ;
}
} else if ( V_73 == 0x0B ) {
if ( V_7 ) {
F_19 ( V_7 , V_80 ,
V_1 , V_78 , 1 + 2 , F_2 ( V_1 , V_9 ) ) ;
}
V_9 += 2 ;
} else {
if ( V_73 >= F_12 ( V_81 ) )
V_73 = 0 ;
V_36 = F_13 ( * V_81 [ V_73 ] ) ;
V_75 = F_1 ( V_1 , V_9 , & V_76 ) ;
V_9 += V_76 + 2 ;
if ( V_7 ) {
F_14 ( V_7 , * V_81 [ V_73 ] ,
V_1 , V_78 , 1 + V_76 + 2 , V_75 ,
L_4 , V_36 -> V_39 , V_75 ) ;
}
}
}
}
static void
F_20 ( T_2 * V_1 , T_5 * V_6 , T_6 * V_82 )
{
T_4 V_83 ;
T_11 * V_84 = NULL ;
T_7 * V_8 = NULL ;
T_6 * V_7 = NULL ;
T_12 * V_85 = NULL ;
V_84 = F_21 ( V_6 ) ;
V_8 = ( T_7 * ) F_22 ( V_84 , V_86 ) ;
if ( ! V_8 ) {
V_8 = F_23 ( T_7 ) ;
V_8 -> V_43 = 0 ;
V_8 -> V_87 = FALSE ;
F_24 ( V_84 , V_86 , V_8 ) ;
}
V_85 = ( T_12 * ) F_25 ( V_6 -> V_85 , V_86 , 0 ) ;
if ( ! V_85 ) {
V_85 = F_23 ( T_12 ) ;
F_26 ( V_6 -> V_85 , V_86 , 0 , V_85 ) ;
V_85 -> V_88 = FALSE ;
if ( V_8 -> V_43 ) {
V_85 -> V_88 = TRUE ;
}
}
F_27 ( V_6 -> V_16 , V_17 ) ;
V_83 = F_2 ( V_1 , 0 ) ;
F_28 ( V_6 -> V_16 , V_89 , L_8 ) ;
if ( V_83 == 0x1234 && ! V_85 -> V_88 )
F_10 ( V_6 -> V_16 , V_17 , L_9 , V_84 -> V_90 ) ;
else if ( V_83 == 0x1234 && V_85 -> V_88 )
F_10 ( V_6 -> V_16 , V_17 , L_10 , V_84 -> V_90 ) ;
else if ( V_83 == 0x4142 )
F_10 ( V_6 -> V_16 , V_17 , L_11 , V_84 -> V_90 ) ;
else
F_28 ( V_6 -> V_16 , V_17 , L_12 ) ;
if ( V_82 ) {
T_13 * V_91 ;
V_91 = F_6 ( V_82 , V_86 , V_1 , 0 , - 1 , V_13 ) ;
V_7 = F_29 ( V_91 , V_92 ) ;
}
if ( V_83 == 0x1234 ) {
if ( V_85 -> V_88 )
F_16 ( V_1 , V_7 , V_8 ) ;
else
F_17 ( V_1 , V_6 , V_7 , V_8 ) ;
} else if ( V_83 == 0x4142 ) {
F_5 ( V_1 , V_6 , V_7 , V_8 ) ;
}
}
static T_10
F_30 ( T_5 * V_6 V_93 , T_2 * V_1 , int V_2 )
{
T_4 V_94 ;
V_94 = F_2 ( V_1 , V_2 + 2 ) ;
V_94 += 4 ;
return V_94 ;
}
static void
F_31 ( T_2 * V_1 , T_5 * V_6 , T_6 * V_82 )
{
F_32 ( V_1 , V_6 , V_82 ,
TRUE ,
4 ,
F_30 ,
F_20 ) ;
}
void
F_33 ( void )
{
static T_14 V_95 [] = {
{ & V_12 ,
{ L_13 , L_14 , V_96 , V_97 , NULL , 0x0 , L_15 ,
V_98 }
} ,
{ & V_14 ,
{ L_16 , L_17 , V_99 , V_100 , NULL , 0x0 , L_18 ,
V_98 }
} ,
{ & V_19 ,
{ L_19 , L_20 , V_101 , V_100 , F_34 ( V_18 ) , 0x0 , L_21 ,
V_98 }
} ,
{ & V_63 ,
{ L_22 , L_23 , V_102 , V_100 , F_34 ( V_62 ) , 0x0 , L_24 ,
V_98 }
} ,
{ & V_64 ,
{ L_25 , L_26 , V_103 , V_97 , NULL , 0x0 , L_27 ,
V_98 }
} ,
{ & V_65 ,
{ L_28 , L_29 , V_103 , V_97 , NULL , 0x0 , L_30 ,
V_98 }
} ,
{ & V_66 ,
{ L_31 , L_32 , V_103 , V_97 , NULL , 0x0 , L_33 ,
V_98 }
} ,
{ & V_67 ,
{ L_34 , L_35 , V_103 , V_97 , NULL , 0x0 , L_36 ,
V_98 }
} ,
{ & V_68 ,
{ L_37 , L_38 , V_103 , V_97 , NULL , 0x0 , L_39 ,
V_98 }
} ,
{ & V_69 ,
{ L_40 , L_41 , V_99 , V_100 , NULL , 0x0 , NULL ,
V_98 }
} ,
{ & V_70 ,
{ L_42 , L_43 , V_104 , V_97 , NULL , 0x0 , L_44 ,
V_98 }
} ,
{ & V_29 ,
{ L_45 , L_46 , V_99 , V_100 , NULL , 0x0 , L_47 ,
V_98 }
} ,
{ & V_105 ,
{ L_48 , L_49 , V_103 , V_97 , NULL , 0x0 , L_50 ,
V_98 }
} ,
{ & V_40 ,
{ L_51 , L_52 , V_103 , V_97 , NULL , 0x0 , L_53 ,
V_98 }
} ,
{ & V_106 ,
{ L_54 , L_55 , V_103 , V_97 , NULL , 0x0 , L_56 ,
V_98 }
} ,
{ & V_107 ,
{ L_57 , L_58 , V_103 , V_97 , NULL , 0x0 , L_59 ,
V_98 }
} ,
{ & V_108 ,
{ L_60 , L_61 , V_103 , V_97 , NULL , 0x0 , L_62 ,
V_98 }
} ,
{ & V_109 ,
{ L_63 , L_64 , V_103 , V_97 , NULL , 0x0 , L_65 ,
V_98 }
} ,
{ & V_110 ,
{ L_66 , L_67 , V_103 , V_97 , NULL , 0x0 , L_68 ,
V_98 }
} ,
{ & V_111 ,
{ L_69 , L_70 , V_103 , V_97 , NULL , 0x0 , L_71 ,
V_98 }
} ,
{ & V_112 ,
{ L_72 , L_73 , V_103 , V_97 , NULL , 0x0 , L_74 ,
V_98 }
} ,
{ & V_113 ,
{ L_75 , L_76 , V_103 , V_97 , NULL , 0x0 , L_77 ,
V_98 }
} ,
{ & V_114 ,
{ L_78 , L_79 , V_103 , V_97 , NULL , 0x0 , L_80 ,
V_98 }
} ,
{ & V_115 ,
{ L_81 , L_82 , V_103 , V_97 , NULL , 0x0 , L_83 ,
V_98 }
} ,
{ & V_116 ,
{ L_84 , L_85 , V_103 , V_97 , NULL , 0x0 , L_86 ,
V_98 }
} ,
{ & V_117 ,
{ L_87 , L_88 , V_103 , V_97 , NULL , 0x0 , L_89 ,
V_98 }
} ,
{ & V_118 ,
{ L_90 , L_91 , V_103 , V_97 , NULL , 0x0 , L_92 ,
V_98 }
} ,
{ & V_119 ,
{ L_93 , L_94 , V_103 , V_97 , NULL , 0x0 , L_95 ,
V_98 }
} ,
{ & V_120 ,
{ L_96 , L_97 , V_103 , V_97 , NULL , 0x0 , L_98 ,
V_98 }
} ,
{ & V_121 ,
{ L_99 , L_100 , V_103 , V_97 , NULL , 0x0 , L_101 ,
V_98 }
} ,
{ & V_122 ,
{ L_102 , L_103 , V_103 , V_97 , NULL , 0x0 , L_104 ,
V_98 }
} ,
{ & V_123 ,
{ L_105 , L_106 , V_103 , V_97 , NULL , 0x0 , L_107 ,
V_98 }
} ,
{ & V_124 ,
{ L_108 , L_109 , V_103 , V_97 , NULL , 0x0 , L_110 ,
V_98 }
} ,
{ & V_125 ,
{ L_111 , L_112 , V_103 , V_97 , NULL , 0x0 , L_113 ,
V_98 }
} ,
{ & V_126 ,
{ L_114 , L_115 , V_103 , V_97 , NULL , 0x0 , L_116 ,
V_98 }
} ,
{ & V_127 ,
{ L_117 , L_118 , V_103 , V_97 , NULL , 0x0 , L_119 ,
V_98 }
} ,
{ & V_128 ,
{ L_120 , L_121 , V_103 , V_97 , NULL , 0x0 , L_122 ,
V_98 }
} ,
{ & V_129 ,
{ L_123 , L_124 , V_103 , V_97 , NULL , 0x0 , L_125 ,
V_98 }
} ,
{ & V_79 ,
{ L_126 , L_127 , V_103 , V_97 , NULL , 0x0 , L_128 ,
V_98 }
} ,
{ & V_130 ,
{ L_129 , L_130 , V_103 , V_97 , NULL , 0x0 , L_131 ,
V_98 }
} ,
{ & V_131 ,
{ L_132 , L_133 , V_103 , V_97 , NULL , 0x0 , L_134 ,
V_98 }
} ,
{ & V_132 ,
{ L_135 , L_136 , V_103 , V_97 , NULL , 0x0 , L_137 ,
V_98 }
} ,
{ & V_133 ,
{ L_138 , L_139 , V_103 , V_97 , NULL , 0x0 , L_140 ,
V_98 }
} ,
{ & V_134 ,
{ L_141 , L_142 , V_103 , V_97 , NULL , 0x0 , L_143 ,
V_98 }
} ,
{ & V_135 ,
{ L_144 , L_145 , V_103 , V_97 , NULL , 0x0 , L_146 ,
V_98 }
} ,
{ & V_136 ,
{ L_147 , L_148 , V_103 , V_97 , NULL , 0x0 , L_149 ,
V_98 }
} ,
{ & V_137 ,
{ L_150 , L_151 , V_103 , V_97 , NULL , 0x0 , L_152 ,
V_98 }
} ,
{ & V_138 ,
{ L_153 , L_154 , V_103 , V_97 , NULL , 0x0 , L_155 ,
V_98 }
} ,
{ & V_80 ,
{ L_156 , L_157 , V_99 , V_100 , NULL , 0x0 , L_158 ,
V_98 }
} ,
{ & V_139 ,
{ L_159 , L_160 , V_103 , V_97 , NULL , 0x0 , L_161 ,
V_98 }
} ,
{ & V_140 ,
{ L_162 , L_163 , V_103 , V_97 , NULL , 0x0 , L_164 ,
V_98 }
} ,
{ & V_44 ,
{ L_165 , L_166 , V_99 , V_100 , NULL , 0x0 , L_167 ,
V_98 }
} ,
{ & V_21 ,
{ L_168 , L_169 , V_102 , V_100 , NULL , 0x0 , L_170 ,
V_98 }
} ,
{ & V_27 ,
{ L_171 , L_172 , V_99 , V_100 , NULL , 0x0 , L_173 ,
V_98 }
} ,
{ & V_28 ,
{ L_174 , L_175 , V_103 , V_97 , NULL , 0x0 , L_176 ,
V_98 }
} ,
{ & V_46 ,
{ L_177 , L_178 , V_103 , V_97 , NULL , 0x0 , NULL ,
V_98 }
} ,
} ;
static T_3 * V_141 [] = {
& V_92 ,
} ;
V_86 = F_35 ( L_179 , L_8 , L_180 ) ;
F_36 ( V_86 , V_95 , F_12 ( V_95 ) ) ;
F_37 ( V_141 , F_12 ( V_141 ) ) ;
}
void
F_38 ( void )
{
T_15 V_142 ;
V_142 = F_39 ( F_31 , V_86 ) ;
F_40 ( L_181 , 8009 , V_142 ) ;
}
