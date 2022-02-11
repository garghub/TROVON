static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (desc, &wdm_device_list, device_list)
if ( V_4 -> V_3 == V_3 )
goto V_6;
V_4 = NULL ;
V_6:
F_4 ( & V_5 ) ;
return V_4 ;
}
static struct V_1 * F_5 ( int V_7 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (desc, &wdm_device_list, device_list)
if ( V_4 -> V_3 -> V_7 == V_7 )
goto V_6;
V_4 = NULL ;
V_6:
F_4 ( & V_5 ) ;
return V_4 ;
}
static void F_6 ( struct V_8 * V_8 )
{
struct V_1 * V_4 ;
V_4 = V_8 -> V_9 ;
F_2 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = V_8 -> V_12 ;
F_4 ( & V_4 -> V_10 ) ;
F_7 ( V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_9 ( & V_4 -> V_16 ) ;
}
static void F_10 ( struct V_8 * V_8 )
{
struct V_1 * V_4 = V_8 -> V_9 ;
int V_12 = V_8 -> V_12 ;
F_2 ( & V_4 -> V_10 ) ;
F_8 ( V_17 , & V_4 -> V_15 ) ;
if ( V_12 ) {
switch ( V_12 ) {
case - V_18 :
F_11 ( & V_4 -> V_3 -> V_19 ,
L_1 ) ;
goto V_20;
case - V_21 :
F_11 ( & V_4 -> V_3 -> V_19 ,
L_2 ) ;
goto V_20;
case - V_22 :
F_11 ( & V_4 -> V_3 -> V_19 ,
L_3 ) ;
goto V_20;
case - V_23 :
F_12 ( & V_4 -> V_3 -> V_19 ,
L_4 ) ;
break;
default:
F_12 ( & V_4 -> V_3 -> V_19 ,
L_5 , V_12 ) ;
break;
}
}
V_4 -> V_24 = V_12 ;
V_4 -> V_25 = V_8 -> V_26 ;
memmove ( V_4 -> V_27 + V_4 -> V_28 , V_4 -> V_29 , V_4 -> V_25 ) ;
V_4 -> V_28 += V_4 -> V_25 ;
V_20:
F_9 ( & V_4 -> V_16 ) ;
F_13 ( V_30 , & V_4 -> V_15 ) ;
F_4 ( & V_4 -> V_10 ) ;
}
static void F_14 ( struct V_8 * V_8 )
{
int V_31 = 0 ;
int V_12 = V_8 -> V_12 ;
struct V_1 * V_4 ;
struct V_32 * V_33 ;
V_4 = V_8 -> V_9 ;
V_33 = (struct V_32 * ) V_4 -> V_34 ;
if ( V_12 ) {
switch ( V_12 ) {
case - V_22 :
case - V_18 :
case - V_21 :
return;
case - V_23 :
F_13 ( V_35 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_19 , L_6 ) ;
goto V_36;
default:
F_12 ( & V_4 -> V_3 -> V_19 ,
L_7 , V_12 ) ;
break;
}
}
if ( V_8 -> V_26 < sizeof( struct V_32 ) ) {
F_12 ( & V_4 -> V_3 -> V_19 , L_8 ,
V_8 -> V_26 ) ;
goto exit;
}
switch ( V_33 -> V_37 ) {
case V_38 :
F_11 ( & V_4 -> V_3 -> V_19 ,
L_9 ,
V_33 -> V_39 , V_33 -> V_40 ) ;
break;
case V_41 :
F_11 ( & V_4 -> V_3 -> V_19 ,
L_10 ,
V_33 -> V_42 ? L_11 : L_12 ) ;
goto exit;
default:
F_8 ( V_43 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_19 ,
L_13 ,
V_33 -> V_37 , V_33 -> V_39 , V_33 -> V_40 ) ;
goto exit;
}
F_2 ( & V_4 -> V_10 ) ;
F_8 ( V_30 , & V_4 -> V_15 ) ;
F_13 ( V_17 , & V_4 -> V_15 ) ;
if ( ! F_15 ( V_44 , & V_4 -> V_15 )
&& ! F_15 ( V_45 , & V_4 -> V_15 ) ) {
V_31 = F_16 ( V_4 -> V_46 , V_47 ) ;
F_11 ( & V_4 -> V_3 -> V_19 , L_14 ,
V_48 , V_31 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
if ( V_31 < 0 ) {
F_8 ( V_17 , & V_4 -> V_15 ) ;
if ( V_31 == - V_49 )
return;
if ( V_31 == - V_50 ) {
V_36:
V_31 = F_17 ( & V_4 -> V_51 ) ;
if ( V_31 )
F_12 ( & V_4 -> V_3 -> V_19 ,
L_15 ) ;
}
}
exit:
V_31 = F_16 ( V_8 , V_47 ) ;
if ( V_31 )
F_12 ( & V_4 -> V_3 -> V_19 ,
L_16 ,
V_48 , V_31 ) ;
}
static void F_18 ( struct V_1 * V_4 )
{
F_19 ( V_4 -> V_52 ) ;
F_19 ( V_4 -> V_53 ) ;
F_19 ( V_4 -> V_46 ) ;
}
static void F_20 ( struct V_1 * V_4 )
{
F_21 ( V_4 -> V_53 ) ;
F_21 ( V_4 -> V_46 ) ;
F_21 ( V_4 -> V_52 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_34 ) ;
F_7 ( V_4 -> V_29 ) ;
F_7 ( V_4 -> V_54 ) ;
F_7 ( V_4 -> V_55 ) ;
F_7 ( V_4 -> V_27 ) ;
F_20 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_23
( struct V_56 * V_56 , const char T_2 * V_57 , T_3 V_58 , T_4 * V_59 )
{
T_5 * V_60 ;
int V_31 = - V_61 , V_62 , V_63 ;
struct V_1 * V_4 = V_56 -> V_64 ;
struct V_65 * V_66 ;
if ( V_58 > V_4 -> V_67 )
V_58 = V_4 -> V_67 ;
F_24 ( & V_4 -> V_10 ) ;
V_63 = V_4 -> V_11 ;
V_4 -> V_11 = 0 ;
F_25 ( & V_4 -> V_10 ) ;
if ( V_63 < 0 )
return - V_68 ;
V_60 = F_26 ( V_58 , V_69 ) ;
if ( ! V_60 ) {
V_31 = - V_50 ;
goto V_70;
}
V_62 = F_27 ( V_60 , V_57 , V_58 ) ;
if ( V_62 > 0 ) {
F_7 ( V_60 ) ;
V_31 = - V_71 ;
goto V_70;
}
V_62 = F_28 ( & V_4 -> V_72 ) ;
V_31 = - V_73 ;
if ( V_62 ) {
F_7 ( V_60 ) ;
goto V_70;
}
if ( F_15 ( V_44 , & V_4 -> V_15 ) ) {
F_7 ( V_60 ) ;
V_31 = - V_74 ;
goto V_75;
}
V_62 = F_29 ( V_4 -> V_3 ) ;
if ( V_62 < 0 ) {
F_7 ( V_60 ) ;
V_31 = F_30 ( V_62 ) ;
goto V_75;
}
if ( ! ( V_56 -> V_76 & V_77 ) )
V_62 = F_31 ( V_4 -> V_16 , ! F_15 ( V_14 ,
& V_4 -> V_15 ) ) ;
else
if ( F_15 ( V_14 , & V_4 -> V_15 ) )
V_62 = - V_78 ;
if ( F_15 ( V_79 , & V_4 -> V_15 ) )
V_62 = - V_68 ;
if ( V_62 < 0 ) {
F_7 ( V_60 ) ;
V_31 = V_62 ;
goto V_80;
}
V_66 = V_4 -> V_54 ;
F_32 (
V_4 -> V_52 ,
F_33 ( V_4 -> V_3 ) ,
F_34 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_66 ,
V_60 ,
V_58 ,
F_6 ,
V_4
) ;
V_66 -> V_81 = ( V_82 | V_83 |
V_84 ) ;
V_66 -> V_85 = V_86 ;
V_66 -> V_42 = 0 ;
V_66 -> V_39 = V_4 -> V_87 ;
V_66 -> V_40 = F_35 ( V_58 ) ;
F_13 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_60 ;
V_31 = F_16 ( V_4 -> V_52 , V_69 ) ;
if ( V_31 < 0 ) {
F_7 ( V_60 ) ;
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_19 , L_17 , V_31 ) ;
V_31 = F_30 ( V_31 ) ;
} else {
F_11 ( & V_4 -> V_3 -> V_19 , L_18 ,
V_66 -> V_39 ) ;
}
V_80:
F_36 ( V_4 -> V_3 ) ;
V_75:
F_37 ( & V_4 -> V_72 ) ;
V_70:
return V_31 < 0 ? V_31 : V_58 ;
}
static T_1 F_38
( struct V_56 * V_56 , char T_2 * V_57 , T_3 V_58 , T_4 * V_59 )
{
int V_31 , V_88 ;
int V_89 = 0 ;
struct V_1 * V_4 = V_56 -> V_64 ;
V_31 = F_28 ( & V_4 -> V_90 ) ;
if ( V_31 < 0 )
return - V_73 ;
V_88 = F_39 ( V_4 -> V_28 ) ;
if ( V_88 == 0 ) {
V_4 -> V_91 = 0 ;
V_92:
if ( F_15 ( V_44 , & V_4 -> V_15 ) ) {
V_31 = - V_74 ;
goto V_93;
}
V_89 ++ ;
if ( V_56 -> V_76 & V_77 ) {
if ( ! F_15 ( V_30 , & V_4 -> V_15 ) ) {
V_31 = V_88 ? V_88 : - V_78 ;
goto V_93;
}
V_31 = 0 ;
} else {
V_31 = F_31 ( V_4 -> V_16 ,
F_15 ( V_30 , & V_4 -> V_15 ) ) ;
}
if ( F_15 ( V_44 , & V_4 -> V_15 ) ) {
V_31 = - V_74 ;
goto V_93;
}
if ( F_15 ( V_79 , & V_4 -> V_15 ) ) {
V_31 = - V_68 ;
goto V_93;
}
F_40 ( F_33 ( V_4 -> V_3 ) ) ;
if ( V_31 < 0 ) {
V_31 = - V_73 ;
goto V_93;
}
F_24 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_24 ) {
V_4 -> V_24 = 0 ;
F_25 ( & V_4 -> V_10 ) ;
V_31 = - V_68 ;
goto V_93;
}
if ( ! F_15 ( V_30 , & V_4 -> V_15 ) ) {
F_25 ( & V_4 -> V_10 ) ;
goto V_92;
}
if ( ! V_4 -> V_25 ) {
F_11 ( & V_4 -> V_3 -> V_19 , L_19 , V_48 ) ;
F_8 ( V_30 , & V_4 -> V_15 ) ;
F_25 ( & V_4 -> V_10 ) ;
goto V_92;
}
V_88 = V_4 -> V_28 ;
F_25 ( & V_4 -> V_10 ) ;
}
if ( V_88 > V_58 )
V_88 = V_58 ;
V_31 = F_41 ( V_57 , V_4 -> V_27 , V_88 ) ;
if ( V_31 > 0 ) {
V_31 = - V_71 ;
goto V_93;
}
F_24 ( & V_4 -> V_10 ) ;
for ( V_89 = 0 ; V_89 < V_4 -> V_28 - V_88 ; V_89 ++ )
V_4 -> V_27 [ V_89 ] = V_4 -> V_27 [ V_89 + V_88 ] ;
V_4 -> V_28 -= V_88 ;
if ( ! V_4 -> V_28 )
F_8 ( V_30 , & V_4 -> V_15 ) ;
F_25 ( & V_4 -> V_10 ) ;
V_31 = V_88 ;
V_93:
F_37 ( & V_4 -> V_90 ) ;
return V_31 ;
}
static int F_42 ( struct V_56 * V_56 , T_6 V_94 )
{
struct V_1 * V_4 = V_56 -> V_64 ;
F_43 ( V_4 -> V_16 , ! F_15 ( V_14 , & V_4 -> V_15 ) ) ;
if ( V_4 -> V_11 < 0 && ! F_15 ( V_44 , & V_4 -> V_15 ) )
F_12 ( & V_4 -> V_3 -> V_19 , L_20 ,
V_4 -> V_11 ) ;
return F_30 ( V_4 -> V_11 ) ;
}
static unsigned int F_44 ( struct V_56 * V_56 , struct V_95 * V_16 )
{
struct V_1 * V_4 = V_56 -> V_64 ;
unsigned long V_15 ;
unsigned int V_96 = 0 ;
F_45 ( & V_4 -> V_10 , V_15 ) ;
if ( F_15 ( V_44 , & V_4 -> V_15 ) ) {
V_96 = V_97 | V_98 ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
goto V_99;
}
if ( F_15 ( V_30 , & V_4 -> V_15 ) )
V_96 = V_100 | V_101 ;
if ( V_4 -> V_24 || V_4 -> V_11 )
V_96 |= V_98 ;
if ( ! F_15 ( V_14 , & V_4 -> V_15 ) )
V_96 |= V_102 | V_103 ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
F_47 ( V_56 , & V_4 -> V_16 , V_16 ) ;
V_99:
return V_96 ;
}
static int F_48 ( struct V_104 * V_104 , struct V_56 * V_56 )
{
int V_7 = F_49 ( V_104 ) ;
int V_31 = - V_74 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_50 ( & V_105 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ! V_4 )
goto V_80;
V_3 = V_4 -> V_3 ;
if ( F_15 ( V_44 , & V_4 -> V_15 ) )
goto V_80;
V_56 -> V_64 = V_4 ;
V_31 = F_29 ( V_4 -> V_3 ) ;
if ( V_31 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_19 , L_21 , V_31 ) ;
goto V_80;
}
F_50 ( & V_4 -> V_72 ) ;
if ( ! V_4 -> V_58 ++ ) {
V_4 -> V_11 = 0 ;
V_4 -> V_24 = 0 ;
V_31 = F_16 ( V_4 -> V_53 , V_69 ) ;
if ( V_31 < 0 ) {
V_4 -> V_58 -- ;
F_12 ( & V_4 -> V_3 -> V_19 ,
L_22 , V_31 ) ;
V_31 = F_30 ( V_31 ) ;
}
} else {
V_31 = 0 ;
}
F_37 ( & V_4 -> V_72 ) ;
if ( V_4 -> V_58 == 1 )
V_4 -> V_106 ( V_3 , 1 ) ;
F_36 ( V_4 -> V_3 ) ;
V_80:
F_37 ( & V_105 ) ;
return V_31 ;
}
static int F_51 ( struct V_104 * V_104 , struct V_56 * V_56 )
{
struct V_1 * V_4 = V_56 -> V_64 ;
F_50 ( & V_105 ) ;
F_50 ( & V_4 -> V_72 ) ;
V_4 -> V_58 -- ;
F_37 ( & V_4 -> V_72 ) ;
if ( ! V_4 -> V_58 ) {
if ( ! F_15 ( V_44 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_19 , L_23 ) ;
F_18 ( V_4 ) ;
V_4 -> V_106 ( V_4 -> V_3 , 0 ) ;
} else {
F_52 ( V_107 L_24 , V_48 ) ;
F_22 ( V_4 ) ;
}
}
F_37 ( & V_105 ) ;
return 0 ;
}
static void F_53 ( struct V_108 * V_109 )
{
struct V_1 * V_4 = F_54 ( V_109 , struct V_1 , V_51 ) ;
unsigned long V_15 ;
int V_31 ;
F_45 ( & V_4 -> V_10 , V_15 ) ;
if ( F_15 ( V_44 , & V_4 -> V_15 ) ) {
F_46 ( & V_4 -> V_10 , V_15 ) ;
} else {
F_46 ( & V_4 -> V_10 , V_15 ) ;
V_31 = F_16 ( V_4 -> V_46 , V_69 ) ;
if ( V_31 < 0 && V_31 != - V_49 ) {
F_45 ( & V_4 -> V_10 , V_15 ) ;
if ( ! F_15 ( V_44 , & V_4 -> V_15 ) )
F_17 ( & V_4 -> V_51 ) ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
}
}
}
static int F_55 ( struct V_2 * V_3 , struct V_110 * V_111 ,
T_7 V_112 , int (* V_106)( struct V_2 * , int ) )
{
int V_31 = - V_50 ;
struct V_1 * V_4 ;
V_4 = F_56 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_4 )
goto V_80;
F_57 ( & V_4 -> V_113 ) ;
F_58 ( & V_4 -> V_90 ) ;
F_58 ( & V_4 -> V_72 ) ;
F_59 ( & V_4 -> V_10 ) ;
F_60 ( & V_4 -> V_16 ) ;
V_4 -> V_67 = V_112 ;
V_4 -> V_87 = F_35 ( ( T_7 ) V_3 -> V_114 -> V_4 . V_115 ) ;
V_4 -> V_3 = V_3 ;
F_61 ( & V_4 -> V_51 , F_53 ) ;
V_31 = - V_116 ;
if ( ! F_62 ( V_111 ) )
goto V_93;
V_4 -> V_117 = F_63 ( V_111 ) ;
V_4 -> V_54 = F_26 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_4 -> V_54 )
goto V_93;
V_4 -> V_55 = F_26 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_4 -> V_55 )
goto V_93;
V_4 -> V_53 = F_64 ( 0 , V_69 ) ;
if ( ! V_4 -> V_53 )
goto V_93;
V_4 -> V_46 = F_64 ( 0 , V_69 ) ;
if ( ! V_4 -> V_46 )
goto V_93;
V_4 -> V_52 = F_64 ( 0 , V_69 ) ;
if ( ! V_4 -> V_52 )
goto V_93;
V_4 -> V_27 = F_26 ( V_4 -> V_67 , V_69 ) ;
if ( ! V_4 -> V_27 )
goto V_93;
V_4 -> V_34 = F_26 ( V_4 -> V_117 , V_69 ) ;
if ( ! V_4 -> V_34 )
goto V_93;
V_4 -> V_29 = F_26 ( V_4 -> V_67 , V_69 ) ;
if ( ! V_4 -> V_29 )
goto V_93;
F_65 (
V_4 -> V_53 ,
F_33 ( V_3 ) ,
F_66 ( F_33 ( V_3 ) , V_111 -> V_118 ) ,
V_4 -> V_34 ,
V_4 -> V_117 ,
F_14 ,
V_4 ,
V_111 -> V_119
) ;
V_4 -> V_55 -> V_81 = ( V_120 | V_83 | V_84 ) ;
V_4 -> V_55 -> V_85 = V_121 ;
V_4 -> V_55 -> V_42 = 0 ;
V_4 -> V_55 -> V_39 = V_4 -> V_87 ;
V_4 -> V_55 -> V_40 = F_35 ( V_4 -> V_67 ) ;
F_32 (
V_4 -> V_46 ,
F_33 ( V_3 ) ,
F_67 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_55 ,
V_4 -> V_29 ,
V_4 -> V_67 ,
F_10 ,
V_4
) ;
V_4 -> V_106 = V_106 ;
F_2 ( & V_5 ) ;
F_68 ( & V_4 -> V_113 , & V_122 ) ;
F_4 ( & V_5 ) ;
V_31 = F_69 ( V_3 , & V_123 ) ;
if ( V_31 < 0 )
goto V_93;
else
F_70 ( & V_3 -> V_19 , L_25 , F_71 ( V_3 -> V_124 ) ) ;
V_80:
return V_31 ;
V_93:
F_2 ( & V_5 ) ;
F_72 ( & V_4 -> V_113 ) ;
F_4 ( & V_5 ) ;
F_22 ( V_4 ) ;
return V_31 ;
}
static int F_73 ( struct V_2 * V_3 , int V_125 )
{
int V_31 = F_29 ( V_3 ) ;
if ( V_31 < 0 )
goto V_93;
V_3 -> V_126 = V_125 ;
F_36 ( V_3 ) ;
V_93:
return V_31 ;
}
static int F_74 ( struct V_2 * V_3 , const struct V_127 * V_94 )
{
int V_31 = - V_116 ;
struct V_128 * V_129 ;
struct V_110 * V_111 ;
struct V_130 * V_131 ;
T_5 * V_57 = V_3 -> V_132 -> V_133 ;
int V_134 = V_3 -> V_132 -> V_135 ;
T_7 V_136 = V_137 ;
if ( ! V_57 )
goto V_93;
while ( V_134 > 2 ) {
if ( V_57 [ 1 ] != V_138 ) {
F_12 ( & V_3 -> V_19 , L_26 ) ;
goto V_139;
}
switch ( V_57 [ 2 ] ) {
case V_140 :
break;
case V_141 :
V_131 = (struct V_130 * ) V_57 ;
V_136 = F_75 ( V_131 -> V_67 ) ;
F_11 ( & V_3 -> V_19 ,
L_27 , V_136 ) ;
break;
default:
F_12 ( & V_3 -> V_19 ,
L_28 ,
V_57 [ 2 ] , V_57 [ 0 ] ) ;
break;
}
V_139:
V_134 -= V_57 [ 0 ] ;
V_57 += V_57 [ 0 ] ;
}
V_129 = V_3 -> V_114 ;
if ( V_129 -> V_4 . V_142 != 1 )
goto V_93;
V_111 = & V_129 -> V_143 [ 0 ] . V_4 ;
V_31 = F_55 ( V_3 , V_111 , V_136 , & F_73 ) ;
V_93:
return V_31 ;
}
struct V_144 * F_76 ( struct V_2 * V_3 ,
struct V_110 * V_111 ,
int V_112 ,
int (* V_106)( struct V_2 * , int ) )
{
int V_31 = - V_116 ;
V_31 = F_55 ( V_3 , V_111 , V_112 , V_106 ) ;
if ( V_31 < 0 )
goto V_93;
return & V_145 ;
V_93:
return F_77 ( V_31 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_79 ( V_3 , & V_123 ) ;
V_4 = F_1 ( V_3 ) ;
F_50 ( & V_105 ) ;
F_45 ( & V_4 -> V_10 , V_15 ) ;
F_13 ( V_44 , & V_4 -> V_15 ) ;
F_13 ( V_30 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
F_80 ( & V_4 -> V_16 ) ;
F_50 ( & V_4 -> V_90 ) ;
F_50 ( & V_4 -> V_72 ) ;
F_18 ( V_4 ) ;
F_81 ( & V_4 -> V_51 ) ;
F_37 ( & V_4 -> V_72 ) ;
F_37 ( & V_4 -> V_90 ) ;
F_2 ( & V_5 ) ;
F_72 ( & V_4 -> V_113 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_58 )
F_22 ( V_4 ) ;
else
F_11 ( & V_3 -> V_19 , L_29 , V_48 , V_4 -> V_58 ) ;
F_37 ( & V_105 ) ;
}
static int F_82 ( struct V_2 * V_3 , T_8 V_146 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_31 = 0 ;
F_11 ( & V_4 -> V_3 -> V_19 , L_30 , V_3 -> V_7 ) ;
if ( ! F_83 ( V_146 ) ) {
F_50 ( & V_4 -> V_90 ) ;
F_50 ( & V_4 -> V_72 ) ;
}
F_24 ( & V_4 -> V_10 ) ;
if ( F_83 ( V_146 ) &&
( F_15 ( V_14 , & V_4 -> V_15 )
|| F_15 ( V_17 , & V_4 -> V_15 ) ) ) {
F_25 ( & V_4 -> V_10 ) ;
V_31 = - V_147 ;
} else {
F_13 ( V_45 , & V_4 -> V_15 ) ;
F_25 ( & V_4 -> V_10 ) ;
F_18 ( V_4 ) ;
F_81 ( & V_4 -> V_51 ) ;
}
if ( ! F_83 ( V_146 ) ) {
F_37 ( & V_4 -> V_72 ) ;
F_37 ( & V_4 -> V_90 ) ;
}
return V_31 ;
}
static int F_84 ( struct V_1 * V_4 )
{
int V_31 = 0 ;
if ( V_4 -> V_58 ) {
V_31 = F_16 ( V_4 -> V_53 , V_148 ) ;
if ( V_31 < 0 )
F_12 ( & V_4 -> V_3 -> V_19 ,
L_31 , V_31 ) ;
}
return V_31 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_31 ;
F_11 ( & V_4 -> V_3 -> V_19 , L_32 , V_3 -> V_7 ) ;
F_8 ( V_45 , & V_4 -> V_15 ) ;
V_31 = F_84 ( V_4 ) ;
return V_31 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_24 ( & V_4 -> V_10 ) ;
F_13 ( V_79 , & V_4 -> V_15 ) ;
F_13 ( V_30 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_24 = - V_149 ;
F_25 ( & V_4 -> V_10 ) ;
F_80 ( & V_4 -> V_16 ) ;
F_50 ( & V_4 -> V_90 ) ;
F_50 ( & V_4 -> V_72 ) ;
F_18 ( V_4 ) ;
F_81 ( & V_4 -> V_51 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_31 ;
F_8 ( V_79 , & V_4 -> V_15 ) ;
V_31 = F_84 ( V_4 ) ;
F_37 ( & V_4 -> V_72 ) ;
F_37 ( & V_4 -> V_90 ) ;
return 0 ;
}
