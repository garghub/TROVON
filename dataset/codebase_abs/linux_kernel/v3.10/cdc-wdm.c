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
int V_17 = V_8 -> V_18 ;
F_2 ( & V_4 -> V_10 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( V_12 ) {
switch ( V_12 ) {
case - V_20 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_1 ) ;
goto V_22;
case - V_23 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_2 ) ;
goto V_22;
case - V_24 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_3 ) ;
goto V_22;
case - V_25 :
F_12 ( & V_4 -> V_3 -> V_21 ,
L_4 ) ;
break;
default:
F_12 ( & V_4 -> V_3 -> V_21 ,
L_5 , V_12 ) ;
break;
}
}
V_4 -> V_26 = V_12 ;
if ( V_17 + V_4 -> V_17 > V_4 -> V_27 ) {
F_13 ( V_28 , & V_4 -> V_15 ) ;
} else {
if ( ! F_14 ( V_28 , & V_4 -> V_15 ) ) {
memmove ( V_4 -> V_29 + V_4 -> V_17 , V_4 -> V_30 , V_17 ) ;
V_4 -> V_17 += V_17 ;
V_4 -> V_31 = V_17 ;
}
}
V_22:
F_9 ( & V_4 -> V_16 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_4 ( & V_4 -> V_10 ) ;
}
static void F_15 ( struct V_8 * V_8 )
{
int V_33 = 0 ;
int V_12 = V_8 -> V_12 ;
struct V_1 * V_4 ;
struct V_34 * V_35 ;
V_4 = V_8 -> V_9 ;
V_35 = (struct V_34 * ) V_4 -> V_36 ;
if ( V_12 ) {
switch ( V_12 ) {
case - V_24 :
case - V_20 :
case - V_23 :
return;
case - V_25 :
F_13 ( V_37 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_6 ) ;
goto V_38;
default:
F_12 ( & V_4 -> V_3 -> V_21 ,
L_7 , V_12 ) ;
break;
}
}
if ( V_8 -> V_18 < sizeof( struct V_34 ) ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_8 ,
V_8 -> V_18 ) ;
goto exit;
}
switch ( V_35 -> V_39 ) {
case V_40 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_9 ,
V_35 -> V_41 , V_35 -> V_42 ) ;
break;
case V_43 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_10 ,
V_35 -> V_44 ? L_11 : L_12 ) ;
goto exit;
default:
F_8 ( V_45 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_13 ,
V_35 -> V_39 , V_35 -> V_41 , V_35 -> V_42 ) ;
goto exit;
}
F_2 ( & V_4 -> V_10 ) ;
F_8 ( V_32 , & V_4 -> V_15 ) ;
F_13 ( V_19 , & V_4 -> V_15 ) ;
if ( ! F_14 ( V_46 , & V_4 -> V_15 )
&& ! F_14 ( V_47 , & V_4 -> V_15 ) ) {
V_33 = F_16 ( V_4 -> V_48 , V_49 ) ;
F_11 ( & V_4 -> V_3 -> V_21 , L_14 ,
V_50 , V_33 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
if ( V_33 < 0 ) {
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( V_33 == - V_51 )
return;
if ( V_33 == - V_52 ) {
V_38:
V_33 = F_17 ( & V_4 -> V_53 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_15 ) ;
}
}
exit:
V_33 = F_16 ( V_8 , V_49 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_16 ,
V_50 , V_33 ) ;
}
static void F_18 ( struct V_1 * V_4 )
{
F_19 ( V_4 -> V_54 ) ;
F_19 ( V_4 -> V_55 ) ;
F_19 ( V_4 -> V_48 ) ;
}
static void F_20 ( struct V_1 * V_4 )
{
F_21 ( V_4 -> V_55 ) ;
F_21 ( V_4 -> V_48 ) ;
F_21 ( V_4 -> V_54 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_36 ) ;
F_7 ( V_4 -> V_30 ) ;
F_7 ( V_4 -> V_56 ) ;
F_7 ( V_4 -> V_57 ) ;
F_7 ( V_4 -> V_29 ) ;
F_20 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_23
( struct V_58 * V_58 , const char T_2 * V_59 , T_3 V_60 , T_4 * V_61 )
{
T_5 * V_62 ;
int V_33 = - V_63 , V_64 , V_65 ;
struct V_1 * V_4 = V_58 -> V_66 ;
struct V_67 * V_68 ;
if ( V_60 > V_4 -> V_27 )
V_60 = V_4 -> V_27 ;
F_24 ( & V_4 -> V_10 ) ;
V_65 = V_4 -> V_11 ;
V_4 -> V_11 = 0 ;
F_25 ( & V_4 -> V_10 ) ;
if ( V_65 < 0 )
return - V_69 ;
V_62 = F_26 ( V_60 , V_70 ) ;
if ( ! V_62 ) {
V_33 = - V_52 ;
goto V_71;
}
V_64 = F_27 ( V_62 , V_59 , V_60 ) ;
if ( V_64 > 0 ) {
F_7 ( V_62 ) ;
V_33 = - V_72 ;
goto V_71;
}
V_64 = F_28 ( & V_4 -> V_73 ) ;
V_33 = - V_74 ;
if ( V_64 ) {
F_7 ( V_62 ) ;
goto V_71;
}
if ( F_14 ( V_46 , & V_4 -> V_15 ) ) {
F_7 ( V_62 ) ;
V_33 = - V_75 ;
goto V_76;
}
V_64 = F_29 ( V_4 -> V_3 ) ;
if ( V_64 < 0 ) {
F_7 ( V_62 ) ;
V_33 = F_30 ( V_64 ) ;
goto V_76;
}
if ( ! ( V_58 -> V_77 & V_78 ) )
V_64 = F_31 ( V_4 -> V_16 , ! F_14 ( V_14 ,
& V_4 -> V_15 ) ) ;
else
if ( F_14 ( V_14 , & V_4 -> V_15 ) )
V_64 = - V_79 ;
if ( F_14 ( V_80 , & V_4 -> V_15 ) )
V_64 = - V_69 ;
if ( V_64 < 0 ) {
F_7 ( V_62 ) ;
V_33 = V_64 ;
goto V_81;
}
V_68 = V_4 -> V_56 ;
F_32 (
V_4 -> V_54 ,
F_33 ( V_4 -> V_3 ) ,
F_34 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_68 ,
V_62 ,
V_60 ,
F_6 ,
V_4
) ;
V_68 -> V_82 = ( V_83 | V_84 |
V_85 ) ;
V_68 -> V_86 = V_87 ;
V_68 -> V_44 = 0 ;
V_68 -> V_41 = V_4 -> V_88 ;
V_68 -> V_42 = F_35 ( V_60 ) ;
F_13 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_62 ;
V_33 = F_16 ( V_4 -> V_54 , V_70 ) ;
if ( V_33 < 0 ) {
F_7 ( V_62 ) ;
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_17 , V_33 ) ;
V_33 = F_30 ( V_33 ) ;
} else {
F_11 ( & V_4 -> V_3 -> V_21 , L_18 ,
V_68 -> V_41 ) ;
}
V_81:
F_36 ( V_4 -> V_3 ) ;
V_76:
F_37 ( & V_4 -> V_73 ) ;
V_71:
return V_33 < 0 ? V_33 : V_60 ;
}
static T_1 F_38
( struct V_58 * V_58 , char T_2 * V_59 , T_3 V_60 , T_4 * V_61 )
{
int V_33 , V_89 ;
int V_90 = 0 ;
struct V_1 * V_4 = V_58 -> V_66 ;
V_33 = F_28 ( & V_4 -> V_91 ) ;
if ( V_33 < 0 )
return - V_74 ;
V_89 = F_39 ( V_4 -> V_17 ) ;
if ( V_89 == 0 ) {
V_4 -> V_92 = 0 ;
V_93:
if ( F_14 ( V_46 , & V_4 -> V_15 ) ) {
V_33 = - V_75 ;
goto V_94;
}
if ( F_14 ( V_28 , & V_4 -> V_15 ) ) {
F_8 ( V_28 , & V_4 -> V_15 ) ;
V_33 = - V_95 ;
goto V_94;
}
V_90 ++ ;
if ( V_58 -> V_77 & V_78 ) {
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
V_33 = V_89 ? V_89 : - V_79 ;
goto V_94;
}
V_33 = 0 ;
} else {
V_33 = F_31 ( V_4 -> V_16 ,
F_14 ( V_32 , & V_4 -> V_15 ) ) ;
}
if ( F_14 ( V_46 , & V_4 -> V_15 ) ) {
V_33 = - V_75 ;
goto V_94;
}
if ( F_14 ( V_80 , & V_4 -> V_15 ) ) {
V_33 = - V_69 ;
goto V_94;
}
F_40 ( F_33 ( V_4 -> V_3 ) ) ;
if ( V_33 < 0 ) {
V_33 = - V_74 ;
goto V_94;
}
F_24 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_26 ) {
V_4 -> V_26 = 0 ;
F_25 ( & V_4 -> V_10 ) ;
V_33 = - V_69 ;
goto V_94;
}
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
F_25 ( & V_4 -> V_10 ) ;
goto V_93;
}
if ( ! V_4 -> V_31 ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_19 , V_50 ) ;
F_8 ( V_32 , & V_4 -> V_15 ) ;
F_25 ( & V_4 -> V_10 ) ;
goto V_93;
}
V_89 = V_4 -> V_17 ;
F_25 ( & V_4 -> V_10 ) ;
}
if ( V_89 > V_60 )
V_89 = V_60 ;
V_33 = F_41 ( V_59 , V_4 -> V_29 , V_89 ) ;
if ( V_33 > 0 ) {
V_33 = - V_72 ;
goto V_94;
}
F_24 ( & V_4 -> V_10 ) ;
for ( V_90 = 0 ; V_90 < V_4 -> V_17 - V_89 ; V_90 ++ )
V_4 -> V_29 [ V_90 ] = V_4 -> V_29 [ V_90 + V_89 ] ;
V_4 -> V_17 -= V_89 ;
if ( ! V_4 -> V_17 )
F_8 ( V_32 , & V_4 -> V_15 ) ;
F_25 ( & V_4 -> V_10 ) ;
V_33 = V_89 ;
V_94:
F_37 ( & V_4 -> V_91 ) ;
return V_33 ;
}
static int F_42 ( struct V_58 * V_58 , T_6 V_96 )
{
struct V_1 * V_4 = V_58 -> V_66 ;
F_43 ( V_4 -> V_16 , ! F_14 ( V_14 , & V_4 -> V_15 ) ) ;
if ( V_4 -> V_11 < 0 && ! F_14 ( V_46 , & V_4 -> V_15 ) )
F_12 ( & V_4 -> V_3 -> V_21 , L_20 ,
V_4 -> V_11 ) ;
return F_30 ( V_4 -> V_11 ) ;
}
static unsigned int F_44 ( struct V_58 * V_58 , struct V_97 * V_16 )
{
struct V_1 * V_4 = V_58 -> V_66 ;
unsigned long V_15 ;
unsigned int V_98 = 0 ;
F_45 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_46 , & V_4 -> V_15 ) ) {
V_98 = V_99 | V_100 ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
goto V_101;
}
if ( F_14 ( V_32 , & V_4 -> V_15 ) )
V_98 = V_102 | V_103 ;
if ( V_4 -> V_26 || V_4 -> V_11 )
V_98 |= V_100 ;
if ( ! F_14 ( V_14 , & V_4 -> V_15 ) )
V_98 |= V_104 | V_105 ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
F_47 ( V_58 , & V_4 -> V_16 , V_16 ) ;
V_101:
return V_98 ;
}
static int F_48 ( struct V_106 * V_106 , struct V_58 * V_58 )
{
int V_7 = F_49 ( V_106 ) ;
int V_33 = - V_75 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_50 ( & V_107 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ! V_4 )
goto V_81;
V_3 = V_4 -> V_3 ;
if ( F_14 ( V_46 , & V_4 -> V_15 ) )
goto V_81;
V_58 -> V_66 = V_4 ;
V_33 = F_29 ( V_4 -> V_3 ) ;
if ( V_33 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_21 , V_33 ) ;
goto V_81;
}
F_50 ( & V_4 -> V_73 ) ;
if ( ! V_4 -> V_60 ++ ) {
V_4 -> V_11 = 0 ;
V_4 -> V_26 = 0 ;
V_33 = F_16 ( V_4 -> V_55 , V_70 ) ;
if ( V_33 < 0 ) {
V_4 -> V_60 -- ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_22 , V_33 ) ;
V_33 = F_30 ( V_33 ) ;
}
} else {
V_33 = 0 ;
}
F_37 ( & V_4 -> V_73 ) ;
if ( V_4 -> V_60 == 1 )
V_4 -> V_108 ( V_3 , 1 ) ;
F_36 ( V_4 -> V_3 ) ;
V_81:
F_37 ( & V_107 ) ;
return V_33 ;
}
static int F_51 ( struct V_106 * V_106 , struct V_58 * V_58 )
{
struct V_1 * V_4 = V_58 -> V_66 ;
F_50 ( & V_107 ) ;
F_50 ( & V_4 -> V_73 ) ;
V_4 -> V_60 -- ;
F_37 ( & V_4 -> V_73 ) ;
if ( ! V_4 -> V_60 ) {
if ( ! F_14 ( V_46 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_23 ) ;
F_18 ( V_4 ) ;
V_4 -> V_108 ( V_4 -> V_3 , 0 ) ;
} else {
F_52 ( V_109 L_24 , V_50 ) ;
F_22 ( V_4 ) ;
}
}
F_37 ( & V_107 ) ;
return 0 ;
}
static long F_53 ( struct V_58 * V_58 , unsigned int V_110 , unsigned long V_111 )
{
struct V_1 * V_4 = V_58 -> V_66 ;
int V_33 = 0 ;
switch ( V_110 ) {
case V_112 :
if ( F_41 ( ( void T_2 * ) V_111 , & V_4 -> V_27 , sizeof( V_4 -> V_27 ) ) )
V_33 = - V_72 ;
break;
default:
V_33 = - V_113 ;
}
return V_33 ;
}
static void F_54 ( struct V_114 * V_115 )
{
struct V_1 * V_4 = F_55 ( V_115 , struct V_1 , V_53 ) ;
unsigned long V_15 ;
int V_33 ;
F_45 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_46 , & V_4 -> V_15 ) ) {
F_46 ( & V_4 -> V_10 , V_15 ) ;
} else {
F_46 ( & V_4 -> V_10 , V_15 ) ;
V_33 = F_16 ( V_4 -> V_48 , V_70 ) ;
if ( V_33 < 0 && V_33 != - V_51 ) {
F_45 ( & V_4 -> V_10 , V_15 ) ;
if ( ! F_14 ( V_46 , & V_4 -> V_15 ) )
F_17 ( & V_4 -> V_53 ) ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
}
}
}
static int F_56 ( struct V_2 * V_3 , struct V_116 * V_117 ,
T_7 V_118 , int (* V_108)( struct V_2 * , int ) )
{
int V_33 = - V_52 ;
struct V_1 * V_4 ;
V_4 = F_57 ( sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_4 )
goto V_81;
F_58 ( & V_4 -> V_119 ) ;
F_59 ( & V_4 -> V_91 ) ;
F_59 ( & V_4 -> V_73 ) ;
F_60 ( & V_4 -> V_10 ) ;
F_61 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = V_118 ;
V_4 -> V_88 = F_35 ( ( T_7 ) V_3 -> V_120 -> V_4 . V_121 ) ;
V_4 -> V_3 = V_3 ;
F_62 ( & V_4 -> V_53 , F_54 ) ;
V_33 = - V_122 ;
if ( ! F_63 ( V_117 ) )
goto V_94;
V_4 -> V_123 = F_64 ( V_117 ) ;
V_4 -> V_56 = F_26 ( sizeof( struct V_67 ) , V_70 ) ;
if ( ! V_4 -> V_56 )
goto V_94;
V_4 -> V_57 = F_26 ( sizeof( struct V_67 ) , V_70 ) ;
if ( ! V_4 -> V_57 )
goto V_94;
V_4 -> V_55 = F_65 ( 0 , V_70 ) ;
if ( ! V_4 -> V_55 )
goto V_94;
V_4 -> V_48 = F_65 ( 0 , V_70 ) ;
if ( ! V_4 -> V_48 )
goto V_94;
V_4 -> V_54 = F_65 ( 0 , V_70 ) ;
if ( ! V_4 -> V_54 )
goto V_94;
V_4 -> V_29 = F_26 ( V_4 -> V_27 , V_70 ) ;
if ( ! V_4 -> V_29 )
goto V_94;
V_4 -> V_36 = F_26 ( V_4 -> V_123 , V_70 ) ;
if ( ! V_4 -> V_36 )
goto V_94;
V_4 -> V_30 = F_26 ( V_4 -> V_27 , V_70 ) ;
if ( ! V_4 -> V_30 )
goto V_94;
F_66 (
V_4 -> V_55 ,
F_33 ( V_3 ) ,
F_67 ( F_33 ( V_3 ) , V_117 -> V_124 ) ,
V_4 -> V_36 ,
V_4 -> V_123 ,
F_15 ,
V_4 ,
V_117 -> V_125
) ;
V_4 -> V_57 -> V_82 = ( V_126 | V_84 | V_85 ) ;
V_4 -> V_57 -> V_86 = V_127 ;
V_4 -> V_57 -> V_44 = 0 ;
V_4 -> V_57 -> V_41 = V_4 -> V_88 ;
V_4 -> V_57 -> V_42 = F_35 ( V_4 -> V_27 ) ;
F_32 (
V_4 -> V_48 ,
F_33 ( V_3 ) ,
F_68 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_57 ,
V_4 -> V_30 ,
V_4 -> V_27 ,
F_10 ,
V_4
) ;
V_4 -> V_108 = V_108 ;
F_2 ( & V_5 ) ;
F_69 ( & V_4 -> V_119 , & V_128 ) ;
F_4 ( & V_5 ) ;
V_33 = F_70 ( V_3 , & V_129 ) ;
if ( V_33 < 0 )
goto V_94;
else
F_71 ( & V_3 -> V_21 , L_25 , F_72 ( V_3 -> V_130 ) ) ;
V_81:
return V_33 ;
V_94:
F_2 ( & V_5 ) ;
F_73 ( & V_4 -> V_119 ) ;
F_4 ( & V_5 ) ;
F_22 ( V_4 ) ;
return V_33 ;
}
static int F_74 ( struct V_2 * V_3 , int V_131 )
{
int V_33 = F_29 ( V_3 ) ;
if ( V_33 < 0 )
goto V_94;
V_3 -> V_132 = V_131 ;
F_36 ( V_3 ) ;
V_94:
return V_33 ;
}
static int F_75 ( struct V_2 * V_3 , const struct V_133 * V_96 )
{
int V_33 = - V_122 ;
struct V_134 * V_135 ;
struct V_116 * V_117 ;
struct V_136 * V_137 ;
T_5 * V_59 = V_3 -> V_138 -> V_139 ;
int V_140 = V_3 -> V_138 -> V_141 ;
T_7 V_142 = V_143 ;
if ( ! V_59 )
goto V_94;
while ( V_140 > 2 ) {
if ( V_59 [ 1 ] != V_144 ) {
F_12 ( & V_3 -> V_21 , L_26 ) ;
goto V_145;
}
switch ( V_59 [ 2 ] ) {
case V_146 :
break;
case V_147 :
V_137 = (struct V_136 * ) V_59 ;
V_142 = F_76 ( V_137 -> V_27 ) ;
F_11 ( & V_3 -> V_21 ,
L_27 , V_142 ) ;
break;
default:
F_12 ( & V_3 -> V_21 ,
L_28 ,
V_59 [ 2 ] , V_59 [ 0 ] ) ;
break;
}
V_145:
V_140 -= V_59 [ 0 ] ;
V_59 += V_59 [ 0 ] ;
}
V_135 = V_3 -> V_120 ;
if ( V_135 -> V_4 . V_148 != 1 )
goto V_94;
V_117 = & V_135 -> V_149 [ 0 ] . V_4 ;
V_33 = F_56 ( V_3 , V_117 , V_142 , & F_74 ) ;
V_94:
return V_33 ;
}
struct V_150 * F_77 ( struct V_2 * V_3 ,
struct V_116 * V_117 ,
int V_118 ,
int (* V_108)( struct V_2 * , int ) )
{
int V_33 = - V_122 ;
V_33 = F_56 ( V_3 , V_117 , V_118 , V_108 ) ;
if ( V_33 < 0 )
goto V_94;
return & V_151 ;
V_94:
return F_78 ( V_33 ) ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_80 ( V_3 , & V_129 ) ;
V_4 = F_1 ( V_3 ) ;
F_50 ( & V_107 ) ;
F_45 ( & V_4 -> V_10 , V_15 ) ;
F_13 ( V_46 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
F_81 ( & V_4 -> V_16 ) ;
F_50 ( & V_4 -> V_91 ) ;
F_50 ( & V_4 -> V_73 ) ;
F_18 ( V_4 ) ;
F_82 ( & V_4 -> V_53 ) ;
F_37 ( & V_4 -> V_73 ) ;
F_37 ( & V_4 -> V_91 ) ;
F_2 ( & V_5 ) ;
F_73 ( & V_4 -> V_119 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_60 )
F_22 ( V_4 ) ;
else
F_11 ( & V_3 -> V_21 , L_29 , V_50 , V_4 -> V_60 ) ;
F_37 ( & V_107 ) ;
}
static int F_83 ( struct V_2 * V_3 , T_8 V_152 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 = 0 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_30 , V_3 -> V_7 ) ;
if ( ! F_84 ( V_152 ) ) {
F_50 ( & V_4 -> V_91 ) ;
F_50 ( & V_4 -> V_73 ) ;
}
F_24 ( & V_4 -> V_10 ) ;
if ( F_84 ( V_152 ) &&
( F_14 ( V_14 , & V_4 -> V_15 )
|| F_14 ( V_19 , & V_4 -> V_15 ) ) ) {
F_25 ( & V_4 -> V_10 ) ;
V_33 = - V_153 ;
} else {
F_13 ( V_47 , & V_4 -> V_15 ) ;
F_25 ( & V_4 -> V_10 ) ;
F_18 ( V_4 ) ;
F_82 ( & V_4 -> V_53 ) ;
}
if ( ! F_84 ( V_152 ) ) {
F_37 ( & V_4 -> V_73 ) ;
F_37 ( & V_4 -> V_91 ) ;
}
return V_33 ;
}
static int F_85 ( struct V_1 * V_4 )
{
int V_33 = 0 ;
if ( V_4 -> V_60 ) {
V_33 = F_16 ( V_4 -> V_55 , V_154 ) ;
if ( V_33 < 0 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_31 , V_33 ) ;
}
return V_33 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_32 , V_3 -> V_7 ) ;
F_8 ( V_47 , & V_4 -> V_15 ) ;
V_33 = F_85 ( V_4 ) ;
return V_33 ;
}
static int F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_24 ( & V_4 -> V_10 ) ;
F_13 ( V_80 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_26 = - V_155 ;
F_25 ( & V_4 -> V_10 ) ;
F_81 ( & V_4 -> V_16 ) ;
F_50 ( & V_4 -> V_91 ) ;
F_50 ( & V_4 -> V_73 ) ;
F_18 ( V_4 ) ;
F_82 ( & V_4 -> V_53 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_8 ( V_28 , & V_4 -> V_15 ) ;
F_8 ( V_80 , & V_4 -> V_15 ) ;
V_33 = F_85 ( V_4 ) ;
F_37 ( & V_4 -> V_73 ) ;
F_37 ( & V_4 -> V_91 ) ;
return 0 ;
}
