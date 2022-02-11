static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (desc, &wdm_device_list, device_list)
if ( V_4 -> V_3 == V_3 )
break;
F_4 ( & V_5 ) ;
return V_4 ;
}
static struct V_1 * F_5 ( int V_6 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (desc, &wdm_device_list, device_list)
if ( V_4 -> V_3 -> V_6 == V_6 )
break;
F_4 ( & V_5 ) ;
return V_4 ;
}
static void F_6 ( struct V_7 * V_7 )
{
struct V_1 * V_4 ;
V_4 = V_7 -> V_8 ;
F_2 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = V_7 -> V_11 ;
F_4 ( & V_4 -> V_9 ) ;
F_7 ( V_4 -> V_12 ) ;
V_4 -> V_12 = NULL ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
F_9 ( & V_4 -> V_15 ) ;
}
static void F_10 ( struct V_7 * V_7 )
{
struct V_1 * V_4 = V_7 -> V_8 ;
int V_11 = V_7 -> V_11 ;
F_2 ( & V_4 -> V_9 ) ;
F_8 ( V_16 , & V_4 -> V_14 ) ;
if ( V_11 ) {
switch ( V_11 ) {
case - V_17 :
F_11 ( & V_4 -> V_3 -> V_18 ,
L_1 ) ;
goto V_19;
case - V_20 :
F_11 ( & V_4 -> V_3 -> V_18 ,
L_2 ) ;
goto V_19;
case - V_21 :
F_11 ( & V_4 -> V_3 -> V_18 ,
L_3 ) ;
goto V_19;
case - V_22 :
F_12 ( & V_4 -> V_3 -> V_18 ,
L_4 ) ;
break;
default:
F_12 ( & V_4 -> V_3 -> V_18 ,
L_5 , V_11 ) ;
break;
}
}
V_4 -> V_23 = V_11 ;
V_4 -> V_24 = V_7 -> V_25 ;
memmove ( V_4 -> V_26 + V_4 -> V_27 , V_4 -> V_28 , V_4 -> V_24 ) ;
V_4 -> V_27 += V_4 -> V_24 ;
V_19:
F_9 ( & V_4 -> V_15 ) ;
F_13 ( V_29 , & V_4 -> V_14 ) ;
F_4 ( & V_4 -> V_9 ) ;
}
static void F_14 ( struct V_7 * V_7 )
{
int V_30 = 0 ;
int V_11 = V_7 -> V_11 ;
struct V_1 * V_4 ;
struct V_31 * V_32 ;
V_4 = V_7 -> V_8 ;
V_32 = (struct V_31 * ) V_4 -> V_33 ;
if ( V_11 ) {
switch ( V_11 ) {
case - V_21 :
case - V_17 :
case - V_20 :
return;
case - V_22 :
F_13 ( V_34 , & V_4 -> V_14 ) ;
F_12 ( & V_4 -> V_3 -> V_18 , L_6 ) ;
goto V_35;
default:
F_12 ( & V_4 -> V_3 -> V_18 ,
L_7 , V_11 ) ;
break;
}
}
if ( V_7 -> V_25 < sizeof( struct V_31 ) ) {
F_12 ( & V_4 -> V_3 -> V_18 , L_8 ,
V_7 -> V_25 ) ;
goto exit;
}
switch ( V_32 -> V_36 ) {
case V_37 :
F_11 ( & V_4 -> V_3 -> V_18 ,
L_9 ,
V_32 -> V_38 , V_32 -> V_39 ) ;
break;
case V_40 :
F_11 ( & V_4 -> V_3 -> V_18 ,
L_10 ,
V_32 -> V_41 ? L_11 : L_12 ) ;
goto exit;
default:
F_8 ( V_42 , & V_4 -> V_14 ) ;
F_12 ( & V_4 -> V_3 -> V_18 ,
L_13 ,
V_32 -> V_36 , V_32 -> V_38 , V_32 -> V_39 ) ;
goto exit;
}
F_2 ( & V_4 -> V_9 ) ;
F_8 ( V_29 , & V_4 -> V_14 ) ;
F_13 ( V_16 , & V_4 -> V_14 ) ;
if ( ! F_15 ( V_43 , & V_4 -> V_14 )
&& ! F_15 ( V_44 , & V_4 -> V_14 ) ) {
V_30 = F_16 ( V_4 -> V_45 , V_46 ) ;
F_11 ( & V_4 -> V_3 -> V_18 , L_14 ,
V_47 , V_30 ) ;
}
F_4 ( & V_4 -> V_9 ) ;
if ( V_30 < 0 ) {
F_8 ( V_16 , & V_4 -> V_14 ) ;
if ( V_30 == - V_48 )
return;
if ( V_30 == - V_49 ) {
V_35:
V_30 = F_17 ( & V_4 -> V_50 ) ;
if ( V_30 )
F_12 ( & V_4 -> V_3 -> V_18 ,
L_15 ) ;
}
}
exit:
V_30 = F_16 ( V_7 , V_46 ) ;
if ( V_30 )
F_12 ( & V_4 -> V_3 -> V_18 ,
L_16 ,
V_47 , V_30 ) ;
}
static void F_18 ( struct V_1 * V_4 )
{
F_19 ( V_4 -> V_51 ) ;
F_19 ( V_4 -> V_52 ) ;
F_19 ( V_4 -> V_45 ) ;
}
static void F_20 ( struct V_1 * V_4 )
{
F_21 ( V_4 -> V_52 ) ;
F_21 ( V_4 -> V_45 ) ;
F_21 ( V_4 -> V_51 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
F_23 ( & V_4 -> V_53 ) ;
F_4 ( & V_5 ) ;
F_7 ( V_4 -> V_33 ) ;
F_7 ( V_4 -> V_28 ) ;
F_7 ( V_4 -> V_54 ) ;
F_7 ( V_4 -> V_55 ) ;
F_7 ( V_4 -> V_26 ) ;
F_20 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_24
( struct V_56 * V_56 , const char T_2 * V_57 , T_3 V_58 , T_4 * V_59 )
{
T_5 * V_60 ;
int V_30 = - V_61 , V_62 , V_63 ;
struct V_1 * V_4 = V_56 -> V_64 ;
struct V_65 * V_66 ;
if ( V_58 > V_4 -> V_67 )
V_58 = V_4 -> V_67 ;
F_25 ( & V_4 -> V_9 ) ;
V_63 = V_4 -> V_10 ;
V_4 -> V_10 = 0 ;
F_26 ( & V_4 -> V_9 ) ;
if ( V_63 < 0 )
return - V_68 ;
V_60 = F_27 ( V_58 , V_69 ) ;
if ( ! V_60 ) {
V_30 = - V_49 ;
goto V_70;
}
V_62 = F_28 ( V_60 , V_57 , V_58 ) ;
if ( V_62 > 0 ) {
F_7 ( V_60 ) ;
V_30 = - V_71 ;
goto V_70;
}
V_62 = F_29 ( & V_4 -> V_72 ) ;
V_30 = - V_73 ;
if ( V_62 ) {
F_7 ( V_60 ) ;
goto V_70;
}
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
F_7 ( V_60 ) ;
V_30 = - V_74 ;
goto V_75;
}
V_62 = F_30 ( V_4 -> V_3 ) ;
if ( V_62 < 0 ) {
F_7 ( V_60 ) ;
goto V_75;
}
if ( ! ( V_56 -> V_76 & V_77 ) )
V_62 = F_31 ( V_4 -> V_15 , ! F_15 ( V_13 ,
& V_4 -> V_14 ) ) ;
else
if ( F_15 ( V_13 , & V_4 -> V_14 ) )
V_62 = - V_78 ;
if ( F_15 ( V_79 , & V_4 -> V_14 ) )
V_62 = - V_68 ;
if ( V_62 < 0 ) {
F_7 ( V_60 ) ;
goto V_80;
}
V_66 = V_4 -> V_54 ;
F_32 (
V_4 -> V_51 ,
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
V_66 -> V_41 = 0 ;
V_66 -> V_38 = V_4 -> V_87 ;
V_66 -> V_39 = F_35 ( V_58 ) ;
F_13 ( V_13 , & V_4 -> V_14 ) ;
V_4 -> V_12 = V_60 ;
V_30 = F_16 ( V_4 -> V_51 , V_69 ) ;
if ( V_30 < 0 ) {
F_7 ( V_60 ) ;
V_4 -> V_12 = NULL ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
F_12 ( & V_4 -> V_3 -> V_18 , L_17 , V_30 ) ;
} else {
F_11 ( & V_4 -> V_3 -> V_18 , L_18 ,
V_66 -> V_38 ) ;
}
V_80:
F_36 ( V_4 -> V_3 ) ;
V_75:
F_37 ( & V_4 -> V_72 ) ;
V_70:
return V_30 < 0 ? V_30 : V_58 ;
}
static T_1 F_38
( struct V_56 * V_56 , char T_2 * V_57 , T_3 V_58 , T_4 * V_59 )
{
int V_30 , V_88 ;
int V_89 = 0 ;
struct V_1 * V_4 = V_56 -> V_64 ;
V_30 = F_29 ( & V_4 -> V_90 ) ;
if ( V_30 < 0 )
return - V_73 ;
V_88 = F_39 ( V_4 -> V_27 ) ;
if ( V_88 == 0 ) {
V_4 -> V_91 = 0 ;
V_92:
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
V_30 = - V_74 ;
goto V_93;
}
V_89 ++ ;
if ( V_56 -> V_76 & V_77 ) {
if ( ! F_15 ( V_29 , & V_4 -> V_14 ) ) {
V_30 = V_88 ? V_88 : - V_78 ;
goto V_93;
}
V_30 = 0 ;
} else {
V_30 = F_31 ( V_4 -> V_15 ,
F_15 ( V_29 , & V_4 -> V_14 ) ) ;
}
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
V_30 = - V_74 ;
goto V_93;
}
if ( F_15 ( V_79 , & V_4 -> V_14 ) ) {
V_30 = - V_68 ;
goto V_93;
}
F_40 ( F_33 ( V_4 -> V_3 ) ) ;
if ( V_30 < 0 ) {
V_30 = - V_73 ;
goto V_93;
}
F_25 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_23 ) {
V_4 -> V_23 = 0 ;
F_26 ( & V_4 -> V_9 ) ;
V_30 = - V_68 ;
goto V_93;
}
if ( ! F_15 ( V_29 , & V_4 -> V_14 ) ) {
F_26 ( & V_4 -> V_9 ) ;
goto V_92;
}
if ( ! V_4 -> V_24 ) {
F_26 ( & V_4 -> V_9 ) ;
goto V_92;
}
V_88 = V_4 -> V_27 ;
F_26 ( & V_4 -> V_9 ) ;
}
if ( V_88 > V_58 )
V_88 = V_58 ;
V_30 = F_41 ( V_57 , V_4 -> V_26 , V_88 ) ;
if ( V_30 > 0 ) {
V_30 = - V_71 ;
goto V_93;
}
F_25 ( & V_4 -> V_9 ) ;
for ( V_89 = 0 ; V_89 < V_4 -> V_27 - V_88 ; V_89 ++ )
V_4 -> V_26 [ V_89 ] = V_4 -> V_26 [ V_89 + V_88 ] ;
V_4 -> V_27 -= V_88 ;
if ( ! V_4 -> V_27 )
F_8 ( V_29 , & V_4 -> V_14 ) ;
F_26 ( & V_4 -> V_9 ) ;
V_30 = V_88 ;
V_93:
F_37 ( & V_4 -> V_90 ) ;
return V_30 ;
}
static int F_42 ( struct V_56 * V_56 , T_6 V_94 )
{
struct V_1 * V_4 = V_56 -> V_64 ;
F_43 ( V_4 -> V_15 , ! F_15 ( V_13 , & V_4 -> V_14 ) ) ;
if ( V_4 -> V_10 < 0 )
F_12 ( & V_4 -> V_3 -> V_18 , L_19 ,
V_4 -> V_10 ) ;
return V_4 -> V_10 ;
}
static unsigned int F_44 ( struct V_56 * V_56 , struct V_95 * V_15 )
{
struct V_1 * V_4 = V_56 -> V_64 ;
unsigned long V_14 ;
unsigned int V_96 = 0 ;
F_45 ( & V_4 -> V_9 , V_14 ) ;
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
V_96 = V_97 ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
goto V_98;
}
if ( F_15 ( V_29 , & V_4 -> V_14 ) )
V_96 = V_99 | V_100 ;
if ( V_4 -> V_23 || V_4 -> V_10 )
V_96 |= V_97 ;
if ( ! F_15 ( V_13 , & V_4 -> V_14 ) )
V_96 |= V_101 | V_102 ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
F_47 ( V_56 , & V_4 -> V_15 , V_15 ) ;
V_98:
return V_96 ;
}
static int F_48 ( struct V_103 * V_103 , struct V_56 * V_56 )
{
int V_6 = F_49 ( V_103 ) ;
int V_30 = - V_74 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_50 ( & V_104 ) ;
V_4 = F_5 ( V_6 ) ;
if ( ! V_4 )
goto V_80;
V_3 = V_4 -> V_3 ;
if ( F_15 ( V_43 , & V_4 -> V_14 ) )
goto V_80;
V_56 -> V_64 = V_4 ;
V_30 = F_30 ( V_4 -> V_3 ) ;
if ( V_30 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_18 , L_20 , V_30 ) ;
goto V_80;
}
F_50 ( & V_4 -> V_72 ) ;
if ( ! V_4 -> V_58 ++ ) {
V_4 -> V_10 = 0 ;
V_4 -> V_23 = 0 ;
V_30 = F_16 ( V_4 -> V_52 , V_69 ) ;
if ( V_30 < 0 ) {
V_4 -> V_58 -- ;
F_12 ( & V_4 -> V_3 -> V_18 ,
L_21 , V_30 ) ;
}
} else {
V_30 = 0 ;
}
F_37 ( & V_4 -> V_72 ) ;
if ( V_4 -> V_58 == 1 )
V_4 -> V_105 ( V_3 , 1 ) ;
F_36 ( V_4 -> V_3 ) ;
V_80:
F_37 ( & V_104 ) ;
return V_30 ;
}
static int F_51 ( struct V_103 * V_103 , struct V_56 * V_56 )
{
struct V_1 * V_4 = V_56 -> V_64 ;
F_50 ( & V_104 ) ;
F_50 ( & V_4 -> V_72 ) ;
V_4 -> V_58 -- ;
F_37 ( & V_4 -> V_72 ) ;
if ( ! V_4 -> V_58 ) {
F_11 ( & V_4 -> V_3 -> V_18 , L_22 ) ;
F_18 ( V_4 ) ;
if ( ! F_15 ( V_43 , & V_4 -> V_14 ) )
V_4 -> V_105 ( V_4 -> V_3 , 0 ) ;
}
F_37 ( & V_104 ) ;
return 0 ;
}
static void F_52 ( struct V_106 * V_107 )
{
struct V_1 * V_4 = F_53 ( V_107 , struct V_1 , V_50 ) ;
unsigned long V_14 ;
int V_30 ;
F_45 ( & V_4 -> V_9 , V_14 ) ;
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
F_46 ( & V_4 -> V_9 , V_14 ) ;
} else {
F_46 ( & V_4 -> V_9 , V_14 ) ;
V_30 = F_16 ( V_4 -> V_45 , V_69 ) ;
if ( V_30 < 0 && V_30 != - V_48 ) {
F_45 ( & V_4 -> V_9 , V_14 ) ;
if ( ! F_15 ( V_43 , & V_4 -> V_14 ) )
F_17 ( & V_4 -> V_50 ) ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
}
}
}
static int F_54 ( struct V_2 * V_3 , struct V_108 * V_109 ,
T_7 V_110 , int (* V_105)( struct V_2 * , int ) )
{
int V_30 = - V_49 ;
struct V_1 * V_4 ;
V_4 = F_55 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_4 )
goto V_80;
F_56 ( & V_4 -> V_53 ) ;
F_57 ( & V_4 -> V_90 ) ;
F_57 ( & V_4 -> V_72 ) ;
F_58 ( & V_4 -> V_9 ) ;
F_59 ( & V_4 -> V_15 ) ;
V_4 -> V_67 = V_110 ;
V_4 -> V_87 = F_35 ( ( T_7 ) V_3 -> V_111 -> V_4 . V_112 ) ;
V_4 -> V_3 = V_3 ;
F_60 ( & V_4 -> V_50 , F_52 ) ;
V_30 = - V_113 ;
if ( ! F_61 ( V_109 ) )
goto V_93;
V_4 -> V_114 = F_62 ( V_109 ) ;
V_4 -> V_54 = F_27 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_4 -> V_54 )
goto V_93;
V_4 -> V_55 = F_27 ( sizeof( struct V_65 ) , V_69 ) ;
if ( ! V_4 -> V_55 )
goto V_93;
V_4 -> V_52 = F_63 ( 0 , V_69 ) ;
if ( ! V_4 -> V_52 )
goto V_93;
V_4 -> V_45 = F_63 ( 0 , V_69 ) ;
if ( ! V_4 -> V_45 )
goto V_93;
V_4 -> V_51 = F_63 ( 0 , V_69 ) ;
if ( ! V_4 -> V_51 )
goto V_93;
V_4 -> V_26 = F_27 ( V_4 -> V_67 , V_69 ) ;
if ( ! V_4 -> V_26 )
goto V_93;
V_4 -> V_33 = F_27 ( V_4 -> V_114 , V_69 ) ;
if ( ! V_4 -> V_33 )
goto V_93;
V_4 -> V_28 = F_27 ( V_4 -> V_67 , V_69 ) ;
if ( ! V_4 -> V_28 )
goto V_93;
F_64 (
V_4 -> V_52 ,
F_33 ( V_3 ) ,
F_65 ( F_33 ( V_3 ) , V_109 -> V_115 ) ,
V_4 -> V_33 ,
V_4 -> V_114 ,
F_14 ,
V_4 ,
V_109 -> V_116
) ;
V_4 -> V_55 -> V_81 = ( V_117 | V_83 | V_84 ) ;
V_4 -> V_55 -> V_85 = V_118 ;
V_4 -> V_55 -> V_41 = 0 ;
V_4 -> V_55 -> V_38 = V_4 -> V_87 ;
V_4 -> V_55 -> V_39 = F_35 ( V_4 -> V_67 ) ;
F_32 (
V_4 -> V_45 ,
F_33 ( V_3 ) ,
F_66 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_55 ,
V_4 -> V_28 ,
V_4 -> V_67 ,
F_10 ,
V_4
) ;
V_4 -> V_105 = V_105 ;
F_2 ( & V_5 ) ;
F_67 ( & V_4 -> V_53 , & V_119 ) ;
F_4 ( & V_5 ) ;
V_30 = F_68 ( V_3 , & V_120 ) ;
if ( V_30 < 0 )
goto V_93;
else
F_69 ( & V_3 -> V_18 , L_23 , F_70 ( V_3 -> V_121 ) ) ;
V_80:
return V_30 ;
V_93:
F_22 ( V_4 ) ;
return V_30 ;
}
static int F_71 ( struct V_2 * V_3 , int V_122 )
{
int V_30 = F_30 ( V_3 ) ;
if ( V_30 < 0 )
goto V_93;
V_3 -> V_123 = V_122 ;
F_36 ( V_3 ) ;
V_93:
return V_30 ;
}
static int F_72 ( struct V_2 * V_3 , const struct V_124 * V_94 )
{
int V_30 = - V_113 ;
struct V_125 * V_126 ;
struct V_108 * V_109 ;
struct V_127 * V_128 ;
T_5 * V_57 = V_3 -> V_129 -> V_130 ;
int V_131 = V_3 -> V_129 -> V_132 ;
T_7 V_133 = V_134 ;
if ( ! V_57 )
goto V_93;
while ( V_131 > 2 ) {
if ( V_57 [ 1 ] != V_135 ) {
F_12 ( & V_3 -> V_18 , L_24 ) ;
goto V_136;
}
switch ( V_57 [ 2 ] ) {
case V_137 :
break;
case V_138 :
V_128 = (struct V_127 * ) V_57 ;
V_133 = F_73 ( V_128 -> V_67 ) ;
F_11 ( & V_3 -> V_18 ,
L_25 , V_133 ) ;
break;
default:
F_12 ( & V_3 -> V_18 ,
L_26 ,
V_57 [ 2 ] , V_57 [ 0 ] ) ;
break;
}
V_136:
V_131 -= V_57 [ 0 ] ;
V_57 += V_57 [ 0 ] ;
}
V_126 = V_3 -> V_111 ;
if ( V_126 -> V_4 . V_139 != 1 )
goto V_93;
V_109 = & V_126 -> V_140 [ 0 ] . V_4 ;
V_30 = F_54 ( V_3 , V_109 , V_133 , & F_71 ) ;
V_93:
return V_30 ;
}
struct V_141 * F_74 ( struct V_2 * V_3 ,
struct V_108 * V_109 ,
int V_110 ,
int (* V_105)( struct V_2 * , int ) )
{
int V_30 = - V_113 ;
V_30 = F_54 ( V_3 , V_109 , V_110 , V_105 ) ;
if ( V_30 < 0 )
goto V_93;
return & V_142 ;
V_93:
return F_75 ( V_30 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_14 ;
F_77 ( V_3 , & V_120 ) ;
V_4 = F_1 ( V_3 ) ;
F_50 ( & V_104 ) ;
F_45 ( & V_4 -> V_9 , V_14 ) ;
F_13 ( V_43 , & V_4 -> V_14 ) ;
F_13 ( V_29 , & V_4 -> V_14 ) ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
F_78 ( & V_4 -> V_15 ) ;
F_50 ( & V_4 -> V_90 ) ;
F_50 ( & V_4 -> V_72 ) ;
F_18 ( V_4 ) ;
F_79 ( & V_4 -> V_50 ) ;
F_37 ( & V_4 -> V_72 ) ;
F_37 ( & V_4 -> V_90 ) ;
if ( ! V_4 -> V_58 )
F_22 ( V_4 ) ;
F_37 ( & V_104 ) ;
}
static int F_80 ( struct V_2 * V_3 , T_8 V_143 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_30 = 0 ;
F_11 ( & V_4 -> V_3 -> V_18 , L_27 , V_3 -> V_6 ) ;
if ( ! F_81 ( V_143 ) ) {
F_50 ( & V_4 -> V_90 ) ;
F_50 ( & V_4 -> V_72 ) ;
}
F_25 ( & V_4 -> V_9 ) ;
if ( F_81 ( V_143 ) &&
( F_15 ( V_13 , & V_4 -> V_14 )
|| F_15 ( V_16 , & V_4 -> V_14 ) ) ) {
F_26 ( & V_4 -> V_9 ) ;
V_30 = - V_144 ;
} else {
F_13 ( V_44 , & V_4 -> V_14 ) ;
F_26 ( & V_4 -> V_9 ) ;
F_18 ( V_4 ) ;
F_79 ( & V_4 -> V_50 ) ;
}
if ( ! F_81 ( V_143 ) ) {
F_37 ( & V_4 -> V_72 ) ;
F_37 ( & V_4 -> V_90 ) ;
}
return V_30 ;
}
static int F_82 ( struct V_1 * V_4 )
{
int V_30 = 0 ;
if ( V_4 -> V_58 ) {
V_30 = F_16 ( V_4 -> V_52 , V_145 ) ;
if ( V_30 < 0 )
F_12 ( & V_4 -> V_3 -> V_18 ,
L_28 , V_30 ) ;
}
return V_30 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_30 ;
F_11 ( & V_4 -> V_3 -> V_18 , L_29 , V_3 -> V_6 ) ;
F_8 ( V_44 , & V_4 -> V_14 ) ;
V_30 = F_82 ( V_4 ) ;
return V_30 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_25 ( & V_4 -> V_9 ) ;
F_13 ( V_79 , & V_4 -> V_14 ) ;
F_13 ( V_29 , & V_4 -> V_14 ) ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
V_4 -> V_23 = - V_146 ;
F_26 ( & V_4 -> V_9 ) ;
F_78 ( & V_4 -> V_15 ) ;
F_50 ( & V_4 -> V_90 ) ;
F_50 ( & V_4 -> V_72 ) ;
F_18 ( V_4 ) ;
F_79 ( & V_4 -> V_50 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_30 ;
F_8 ( V_79 , & V_4 -> V_14 ) ;
V_30 = F_82 ( V_4 ) ;
F_37 ( & V_4 -> V_72 ) ;
F_37 ( & V_4 -> V_90 ) ;
return 0 ;
}
