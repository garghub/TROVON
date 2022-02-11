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
int V_34 ;
int V_12 = V_8 -> V_12 ;
struct V_1 * V_4 ;
struct V_35 * V_36 ;
V_4 = V_8 -> V_9 ;
V_36 = (struct V_35 * ) V_4 -> V_37 ;
if ( V_12 ) {
switch ( V_12 ) {
case - V_24 :
case - V_20 :
case - V_23 :
return;
case - V_25 :
F_13 ( V_38 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_6 ) ;
goto V_39;
default:
F_12 ( & V_4 -> V_3 -> V_21 ,
L_7 , V_12 ) ;
break;
}
}
if ( V_8 -> V_18 < sizeof( struct V_35 ) ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_8 ,
V_8 -> V_18 ) ;
goto exit;
}
switch ( V_36 -> V_40 ) {
case V_41 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_9 ,
V_36 -> V_42 , V_36 -> V_43 ) ;
break;
case V_44 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_10 ,
V_36 -> V_45 ? L_11 : L_12 ) ;
goto exit;
default:
F_8 ( V_46 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_13 ,
V_36 -> V_40 , V_36 -> V_42 , V_36 -> V_43 ) ;
goto exit;
}
F_2 ( & V_4 -> V_10 ) ;
F_8 ( V_32 , & V_4 -> V_15 ) ;
V_34 = F_16 ( V_19 , & V_4 -> V_15 ) ;
if ( ! V_34 && ! F_14 ( V_47 , & V_4 -> V_15 )
&& ! F_14 ( V_48 , & V_4 -> V_15 ) ) {
V_33 = F_17 ( V_4 -> V_49 , V_50 ) ;
F_11 ( & V_4 -> V_3 -> V_21 , L_14 ,
V_51 , V_33 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
if ( V_33 < 0 ) {
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( V_33 == - V_52 )
return;
if ( V_33 == - V_53 ) {
V_39:
V_33 = F_18 ( & V_4 -> V_54 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_15 ) ;
}
}
exit:
V_33 = F_17 ( V_8 , V_50 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_16 ,
V_51 , V_33 ) ;
}
static void F_19 ( struct V_1 * V_4 )
{
F_20 ( V_4 -> V_55 ) ;
F_20 ( V_4 -> V_56 ) ;
F_20 ( V_4 -> V_49 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
F_22 ( V_4 -> V_56 ) ;
F_22 ( V_4 -> V_49 ) ;
F_22 ( V_4 -> V_55 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_37 ) ;
F_7 ( V_4 -> V_30 ) ;
F_7 ( V_4 -> V_57 ) ;
F_7 ( V_4 -> V_58 ) ;
F_7 ( V_4 -> V_29 ) ;
F_21 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_24
( struct V_59 * V_59 , const char T_2 * V_60 , T_3 V_61 , T_4 * V_62 )
{
T_5 * V_63 ;
int V_33 = - V_64 , V_65 , V_66 ;
struct V_1 * V_4 = V_59 -> V_67 ;
struct V_68 * V_69 ;
if ( V_61 > V_4 -> V_27 )
V_61 = V_4 -> V_27 ;
F_25 ( & V_4 -> V_10 ) ;
V_66 = V_4 -> V_11 ;
V_4 -> V_11 = 0 ;
F_26 ( & V_4 -> V_10 ) ;
if ( V_66 < 0 )
return - V_70 ;
V_63 = F_27 ( V_61 , V_71 ) ;
if ( ! V_63 ) {
V_33 = - V_53 ;
goto V_72;
}
V_65 = F_28 ( V_63 , V_60 , V_61 ) ;
if ( V_65 > 0 ) {
F_7 ( V_63 ) ;
V_33 = - V_73 ;
goto V_72;
}
V_65 = F_29 ( & V_4 -> V_74 ) ;
V_33 = - V_75 ;
if ( V_65 ) {
F_7 ( V_63 ) ;
goto V_72;
}
if ( F_14 ( V_47 , & V_4 -> V_15 ) ) {
F_7 ( V_63 ) ;
V_33 = - V_76 ;
goto V_77;
}
V_65 = F_30 ( V_4 -> V_3 ) ;
if ( V_65 < 0 ) {
F_7 ( V_63 ) ;
V_33 = F_31 ( V_65 ) ;
goto V_77;
}
if ( ! ( V_59 -> V_78 & V_79 ) )
V_65 = F_32 ( V_4 -> V_16 , ! F_14 ( V_14 ,
& V_4 -> V_15 ) ) ;
else
if ( F_14 ( V_14 , & V_4 -> V_15 ) )
V_65 = - V_80 ;
if ( F_14 ( V_81 , & V_4 -> V_15 ) )
V_65 = - V_70 ;
if ( V_65 < 0 ) {
F_7 ( V_63 ) ;
V_33 = V_65 ;
goto V_82;
}
V_69 = V_4 -> V_57 ;
F_33 (
V_4 -> V_55 ,
F_34 ( V_4 -> V_3 ) ,
F_35 ( F_34 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_69 ,
V_63 ,
V_61 ,
F_6 ,
V_4
) ;
V_69 -> V_83 = ( V_84 | V_85 |
V_86 ) ;
V_69 -> V_87 = V_88 ;
V_69 -> V_45 = 0 ;
V_69 -> V_42 = V_4 -> V_89 ;
V_69 -> V_43 = F_36 ( V_61 ) ;
F_13 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_63 ;
V_33 = F_17 ( V_4 -> V_55 , V_71 ) ;
if ( V_33 < 0 ) {
F_7 ( V_63 ) ;
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_17 , V_33 ) ;
V_33 = F_31 ( V_33 ) ;
} else {
F_11 ( & V_4 -> V_3 -> V_21 , L_18 ,
V_69 -> V_42 ) ;
}
V_82:
F_37 ( V_4 -> V_3 ) ;
V_77:
F_38 ( & V_4 -> V_74 ) ;
V_72:
return V_33 < 0 ? V_33 : V_61 ;
}
static T_1 F_39
( struct V_59 * V_59 , char T_2 * V_60 , T_3 V_61 , T_4 * V_62 )
{
int V_33 , V_90 ;
int V_91 = 0 ;
struct V_1 * V_4 = V_59 -> V_67 ;
V_33 = F_29 ( & V_4 -> V_92 ) ;
if ( V_33 < 0 )
return - V_75 ;
V_90 = F_40 ( V_4 -> V_17 ) ;
if ( V_90 == 0 ) {
V_4 -> V_93 = 0 ;
V_94:
if ( F_14 ( V_47 , & V_4 -> V_15 ) ) {
V_33 = - V_76 ;
goto V_95;
}
if ( F_14 ( V_28 , & V_4 -> V_15 ) ) {
F_8 ( V_28 , & V_4 -> V_15 ) ;
V_33 = - V_96 ;
goto V_95;
}
V_91 ++ ;
if ( V_59 -> V_78 & V_79 ) {
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
V_33 = V_90 ? V_90 : - V_80 ;
goto V_95;
}
V_33 = 0 ;
} else {
V_33 = F_32 ( V_4 -> V_16 ,
F_14 ( V_32 , & V_4 -> V_15 ) ) ;
}
if ( F_14 ( V_47 , & V_4 -> V_15 ) ) {
V_33 = - V_76 ;
goto V_95;
}
if ( F_14 ( V_81 , & V_4 -> V_15 ) ) {
V_33 = - V_70 ;
goto V_95;
}
F_41 ( F_34 ( V_4 -> V_3 ) ) ;
if ( V_33 < 0 ) {
V_33 = - V_75 ;
goto V_95;
}
F_25 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_26 ) {
V_4 -> V_26 = 0 ;
F_26 ( & V_4 -> V_10 ) ;
V_33 = - V_70 ;
goto V_95;
}
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
F_26 ( & V_4 -> V_10 ) ;
goto V_94;
}
if ( ! V_4 -> V_31 ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_19 , V_51 ) ;
F_8 ( V_32 , & V_4 -> V_15 ) ;
F_26 ( & V_4 -> V_10 ) ;
goto V_94;
}
V_90 = V_4 -> V_17 ;
F_26 ( & V_4 -> V_10 ) ;
}
if ( V_90 > V_61 )
V_90 = V_61 ;
V_33 = F_42 ( V_60 , V_4 -> V_29 , V_90 ) ;
if ( V_33 > 0 ) {
V_33 = - V_73 ;
goto V_95;
}
F_25 ( & V_4 -> V_10 ) ;
for ( V_91 = 0 ; V_91 < V_4 -> V_17 - V_90 ; V_91 ++ )
V_4 -> V_29 [ V_91 ] = V_4 -> V_29 [ V_91 + V_90 ] ;
V_4 -> V_17 -= V_90 ;
if ( ! V_4 -> V_17 )
F_8 ( V_32 , & V_4 -> V_15 ) ;
F_26 ( & V_4 -> V_10 ) ;
V_33 = V_90 ;
V_95:
F_38 ( & V_4 -> V_92 ) ;
return V_33 ;
}
static int F_43 ( struct V_59 * V_59 , T_6 V_97 )
{
struct V_1 * V_4 = V_59 -> V_67 ;
F_44 ( V_4 -> V_16 , ! F_14 ( V_14 , & V_4 -> V_15 ) ) ;
if ( V_4 -> V_11 < 0 && ! F_14 ( V_47 , & V_4 -> V_15 ) )
F_12 ( & V_4 -> V_3 -> V_21 , L_20 ,
V_4 -> V_11 ) ;
return F_31 ( V_4 -> V_11 ) ;
}
static unsigned int F_45 ( struct V_59 * V_59 , struct V_98 * V_16 )
{
struct V_1 * V_4 = V_59 -> V_67 ;
unsigned long V_15 ;
unsigned int V_99 = 0 ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_47 , & V_4 -> V_15 ) ) {
V_99 = V_100 | V_101 ;
F_47 ( & V_4 -> V_10 , V_15 ) ;
goto V_102;
}
if ( F_14 ( V_32 , & V_4 -> V_15 ) )
V_99 = V_103 | V_104 ;
if ( V_4 -> V_26 || V_4 -> V_11 )
V_99 |= V_101 ;
if ( ! F_14 ( V_14 , & V_4 -> V_15 ) )
V_99 |= V_105 | V_106 ;
F_47 ( & V_4 -> V_10 , V_15 ) ;
F_48 ( V_59 , & V_4 -> V_16 , V_16 ) ;
V_102:
return V_99 ;
}
static int F_49 ( struct V_107 * V_107 , struct V_59 * V_59 )
{
int V_7 = F_50 ( V_107 ) ;
int V_33 = - V_76 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_51 ( & V_108 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ! V_4 )
goto V_82;
V_3 = V_4 -> V_3 ;
if ( F_14 ( V_47 , & V_4 -> V_15 ) )
goto V_82;
V_59 -> V_67 = V_4 ;
V_33 = F_30 ( V_4 -> V_3 ) ;
if ( V_33 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_21 , V_33 ) ;
goto V_82;
}
F_51 ( & V_4 -> V_74 ) ;
if ( ! V_4 -> V_61 ++ ) {
V_4 -> V_11 = 0 ;
V_4 -> V_26 = 0 ;
V_33 = F_17 ( V_4 -> V_56 , V_71 ) ;
if ( V_33 < 0 ) {
V_4 -> V_61 -- ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_22 , V_33 ) ;
V_33 = F_31 ( V_33 ) ;
}
} else {
V_33 = 0 ;
}
F_38 ( & V_4 -> V_74 ) ;
if ( V_4 -> V_61 == 1 )
V_4 -> V_109 ( V_3 , 1 ) ;
F_37 ( V_4 -> V_3 ) ;
V_82:
F_38 ( & V_108 ) ;
return V_33 ;
}
static int F_52 ( struct V_107 * V_107 , struct V_59 * V_59 )
{
struct V_1 * V_4 = V_59 -> V_67 ;
F_51 ( & V_108 ) ;
F_51 ( & V_4 -> V_74 ) ;
V_4 -> V_61 -- ;
F_38 ( & V_4 -> V_74 ) ;
if ( ! V_4 -> V_61 ) {
if ( ! F_14 ( V_47 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_23 ) ;
F_19 ( V_4 ) ;
V_4 -> V_109 ( V_4 -> V_3 , 0 ) ;
} else {
F_53 ( V_110 L_24 , V_51 ) ;
F_23 ( V_4 ) ;
}
}
F_38 ( & V_108 ) ;
return 0 ;
}
static long F_54 ( struct V_59 * V_59 , unsigned int V_111 , unsigned long V_112 )
{
struct V_1 * V_4 = V_59 -> V_67 ;
int V_33 = 0 ;
switch ( V_111 ) {
case V_113 :
if ( F_42 ( ( void T_2 * ) V_112 , & V_4 -> V_27 , sizeof( V_4 -> V_27 ) ) )
V_33 = - V_73 ;
break;
default:
V_33 = - V_114 ;
}
return V_33 ;
}
static void F_55 ( struct V_115 * V_116 )
{
struct V_1 * V_4 = F_56 ( V_116 , struct V_1 , V_54 ) ;
unsigned long V_15 ;
int V_33 = 0 ;
int V_34 ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_47 , & V_4 -> V_15 ) ) {
F_47 ( & V_4 -> V_10 , V_15 ) ;
} else {
V_34 = F_16 ( V_19 , & V_4 -> V_15 ) ;
F_47 ( & V_4 -> V_10 , V_15 ) ;
if ( ! V_34 )
V_33 = F_17 ( V_4 -> V_49 , V_71 ) ;
if ( V_33 < 0 && V_33 != - V_52 ) {
F_46 ( & V_4 -> V_10 , V_15 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( ! F_14 ( V_47 , & V_4 -> V_15 ) )
F_18 ( & V_4 -> V_54 ) ;
F_47 ( & V_4 -> V_10 , V_15 ) ;
}
}
}
static int F_57 ( struct V_2 * V_3 , struct V_117 * V_118 ,
T_7 V_119 , int (* V_109)( struct V_2 * , int ) )
{
int V_33 = - V_53 ;
struct V_1 * V_4 ;
V_4 = F_58 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_4 )
goto V_82;
F_59 ( & V_4 -> V_120 ) ;
F_60 ( & V_4 -> V_92 ) ;
F_60 ( & V_4 -> V_74 ) ;
F_61 ( & V_4 -> V_10 ) ;
F_62 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = V_119 ;
V_4 -> V_89 = F_36 ( ( T_7 ) V_3 -> V_121 -> V_4 . V_122 ) ;
V_4 -> V_3 = V_3 ;
F_63 ( & V_4 -> V_54 , F_55 ) ;
V_33 = - V_123 ;
if ( ! F_64 ( V_118 ) )
goto V_95;
V_4 -> V_124 = F_65 ( V_118 ) ;
V_4 -> V_57 = F_27 ( sizeof( struct V_68 ) , V_71 ) ;
if ( ! V_4 -> V_57 )
goto V_95;
V_4 -> V_58 = F_27 ( sizeof( struct V_68 ) , V_71 ) ;
if ( ! V_4 -> V_58 )
goto V_95;
V_4 -> V_56 = F_66 ( 0 , V_71 ) ;
if ( ! V_4 -> V_56 )
goto V_95;
V_4 -> V_49 = F_66 ( 0 , V_71 ) ;
if ( ! V_4 -> V_49 )
goto V_95;
V_4 -> V_55 = F_66 ( 0 , V_71 ) ;
if ( ! V_4 -> V_55 )
goto V_95;
V_4 -> V_29 = F_27 ( V_4 -> V_27 , V_71 ) ;
if ( ! V_4 -> V_29 )
goto V_95;
V_4 -> V_37 = F_27 ( V_4 -> V_124 , V_71 ) ;
if ( ! V_4 -> V_37 )
goto V_95;
V_4 -> V_30 = F_27 ( V_4 -> V_27 , V_71 ) ;
if ( ! V_4 -> V_30 )
goto V_95;
F_67 (
V_4 -> V_56 ,
F_34 ( V_3 ) ,
F_68 ( F_34 ( V_3 ) , V_118 -> V_125 ) ,
V_4 -> V_37 ,
V_4 -> V_124 ,
F_15 ,
V_4 ,
V_118 -> V_126
) ;
V_4 -> V_58 -> V_83 = ( V_127 | V_85 | V_86 ) ;
V_4 -> V_58 -> V_87 = V_128 ;
V_4 -> V_58 -> V_45 = 0 ;
V_4 -> V_58 -> V_42 = V_4 -> V_89 ;
V_4 -> V_58 -> V_43 = F_36 ( V_4 -> V_27 ) ;
F_33 (
V_4 -> V_49 ,
F_34 ( V_3 ) ,
F_69 ( F_34 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_58 ,
V_4 -> V_30 ,
V_4 -> V_27 ,
F_10 ,
V_4
) ;
V_4 -> V_109 = V_109 ;
F_2 ( & V_5 ) ;
F_70 ( & V_4 -> V_120 , & V_129 ) ;
F_4 ( & V_5 ) ;
V_33 = F_71 ( V_3 , & V_130 ) ;
if ( V_33 < 0 )
goto V_95;
else
F_72 ( & V_3 -> V_21 , L_25 , F_73 ( V_3 -> V_131 ) ) ;
V_82:
return V_33 ;
V_95:
F_2 ( & V_5 ) ;
F_74 ( & V_4 -> V_120 ) ;
F_4 ( & V_5 ) ;
F_23 ( V_4 ) ;
return V_33 ;
}
static int F_75 ( struct V_2 * V_3 , int V_132 )
{
int V_33 = F_30 ( V_3 ) ;
if ( V_33 < 0 )
goto V_95;
V_3 -> V_133 = V_132 ;
F_37 ( V_3 ) ;
V_95:
return V_33 ;
}
static int F_76 ( struct V_2 * V_3 , const struct V_134 * V_97 )
{
int V_33 = - V_123 ;
struct V_135 * V_136 ;
struct V_117 * V_118 ;
struct V_137 * V_138 ;
T_5 * V_60 = V_3 -> V_139 -> V_140 ;
int V_141 = V_3 -> V_139 -> V_142 ;
T_7 V_143 = V_144 ;
if ( ! V_60 )
goto V_95;
while ( V_141 > 2 ) {
if ( V_60 [ 1 ] != V_145 ) {
F_12 ( & V_3 -> V_21 , L_26 ) ;
goto V_146;
}
switch ( V_60 [ 2 ] ) {
case V_147 :
break;
case V_148 :
V_138 = (struct V_137 * ) V_60 ;
V_143 = F_77 ( V_138 -> V_27 ) ;
F_11 ( & V_3 -> V_21 ,
L_27 , V_143 ) ;
break;
default:
F_12 ( & V_3 -> V_21 ,
L_28 ,
V_60 [ 2 ] , V_60 [ 0 ] ) ;
break;
}
V_146:
V_141 -= V_60 [ 0 ] ;
V_60 += V_60 [ 0 ] ;
}
V_136 = V_3 -> V_121 ;
if ( V_136 -> V_4 . V_149 != 1 )
goto V_95;
V_118 = & V_136 -> V_150 [ 0 ] . V_4 ;
V_33 = F_57 ( V_3 , V_118 , V_143 , & F_75 ) ;
V_95:
return V_33 ;
}
struct V_151 * F_78 ( struct V_2 * V_3 ,
struct V_117 * V_118 ,
int V_119 ,
int (* V_109)( struct V_2 * , int ) )
{
int V_33 = - V_123 ;
V_33 = F_57 ( V_3 , V_118 , V_119 , V_109 ) ;
if ( V_33 < 0 )
goto V_95;
return & V_152 ;
V_95:
return F_79 ( V_33 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_81 ( V_3 , & V_130 ) ;
V_4 = F_1 ( V_3 ) ;
F_51 ( & V_108 ) ;
F_46 ( & V_4 -> V_10 , V_15 ) ;
F_13 ( V_47 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_47 ( & V_4 -> V_10 , V_15 ) ;
F_82 ( & V_4 -> V_16 ) ;
F_51 ( & V_4 -> V_92 ) ;
F_51 ( & V_4 -> V_74 ) ;
F_19 ( V_4 ) ;
F_83 ( & V_4 -> V_54 ) ;
F_38 ( & V_4 -> V_74 ) ;
F_38 ( & V_4 -> V_92 ) ;
F_2 ( & V_5 ) ;
F_74 ( & V_4 -> V_120 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_61 )
F_23 ( V_4 ) ;
else
F_11 ( & V_3 -> V_21 , L_29 , V_51 , V_4 -> V_61 ) ;
F_38 ( & V_108 ) ;
}
static int F_84 ( struct V_2 * V_3 , T_8 V_153 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 = 0 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_30 , V_3 -> V_7 ) ;
if ( ! F_85 ( V_153 ) ) {
F_51 ( & V_4 -> V_92 ) ;
F_51 ( & V_4 -> V_74 ) ;
}
F_25 ( & V_4 -> V_10 ) ;
if ( F_85 ( V_153 ) &&
( F_14 ( V_14 , & V_4 -> V_15 )
|| F_14 ( V_19 , & V_4 -> V_15 ) ) ) {
F_26 ( & V_4 -> V_10 ) ;
V_33 = - V_154 ;
} else {
F_13 ( V_48 , & V_4 -> V_15 ) ;
F_26 ( & V_4 -> V_10 ) ;
F_19 ( V_4 ) ;
F_83 ( & V_4 -> V_54 ) ;
}
if ( ! F_85 ( V_153 ) ) {
F_38 ( & V_4 -> V_74 ) ;
F_38 ( & V_4 -> V_92 ) ;
}
return V_33 ;
}
static int F_86 ( struct V_1 * V_4 )
{
int V_33 = 0 ;
if ( V_4 -> V_61 ) {
V_33 = F_17 ( V_4 -> V_56 , V_155 ) ;
if ( V_33 < 0 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_31 , V_33 ) ;
}
return V_33 ;
}
static int F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_32 , V_3 -> V_7 ) ;
F_8 ( V_48 , & V_4 -> V_15 ) ;
V_33 = F_86 ( V_4 ) ;
return V_33 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_25 ( & V_4 -> V_10 ) ;
F_13 ( V_81 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_26 = - V_156 ;
F_26 ( & V_4 -> V_10 ) ;
F_82 ( & V_4 -> V_16 ) ;
F_51 ( & V_4 -> V_92 ) ;
F_51 ( & V_4 -> V_74 ) ;
F_19 ( V_4 ) ;
F_83 ( & V_4 -> V_54 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_8 ( V_28 , & V_4 -> V_15 ) ;
F_8 ( V_81 , & V_4 -> V_15 ) ;
V_33 = F_86 ( V_4 ) ;
F_38 ( & V_4 -> V_74 ) ;
F_38 ( & V_4 -> V_92 ) ;
return 0 ;
}
