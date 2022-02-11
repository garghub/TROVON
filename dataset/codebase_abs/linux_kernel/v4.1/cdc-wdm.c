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
F_16 ( V_36 -> V_42 ) , F_16 ( V_36 -> V_43 ) ) ;
break;
case V_44 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_10 ,
V_36 -> V_45 ? L_11 : L_12 ) ;
goto exit;
case V_46 :
F_11 ( & V_4 -> V_3 -> V_21 , L_13 ,
V_8 -> V_18 ) ;
goto exit;
default:
F_8 ( V_47 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_14 ,
V_36 -> V_40 ,
F_16 ( V_36 -> V_42 ) ,
F_16 ( V_36 -> V_43 ) ) ;
goto exit;
}
F_2 ( & V_4 -> V_10 ) ;
V_34 = F_17 ( V_19 , & V_4 -> V_15 ) ;
if ( ! V_4 -> V_48 ++ && ! V_34
&& ! F_14 ( V_49 , & V_4 -> V_15 )
&& ! F_14 ( V_50 , & V_4 -> V_15 ) ) {
V_33 = F_18 ( V_4 -> V_51 , V_52 ) ;
F_11 ( & V_4 -> V_3 -> V_21 , L_15 ,
V_53 , V_33 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
if ( V_33 < 0 ) {
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( V_33 == - V_54 )
return;
if ( V_33 == - V_55 ) {
V_39:
V_33 = F_19 ( & V_4 -> V_56 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_16 ) ;
}
}
exit:
V_33 = F_18 ( V_8 , V_52 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_17 ,
V_53 , V_33 ) ;
}
static void F_20 ( struct V_1 * V_4 )
{
F_21 ( V_4 -> V_57 ) ;
F_21 ( V_4 -> V_58 ) ;
F_21 ( V_4 -> V_51 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
F_23 ( V_4 -> V_58 ) ;
F_23 ( V_4 -> V_51 ) ;
F_23 ( V_4 -> V_57 ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_37 ) ;
F_7 ( V_4 -> V_30 ) ;
F_7 ( V_4 -> V_59 ) ;
F_7 ( V_4 -> V_60 ) ;
F_7 ( V_4 -> V_29 ) ;
F_22 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_25
( struct V_61 * V_61 , const char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
T_5 * V_65 ;
int V_33 = - V_66 , V_67 , V_68 ;
struct V_1 * V_4 = V_61 -> V_69 ;
struct V_70 * V_71 ;
if ( V_63 > V_4 -> V_27 )
V_63 = V_4 -> V_27 ;
F_26 ( & V_4 -> V_10 ) ;
V_68 = V_4 -> V_11 ;
V_4 -> V_11 = 0 ;
F_27 ( & V_4 -> V_10 ) ;
if ( V_68 < 0 )
return F_28 ( V_68 ) ;
V_65 = F_29 ( V_63 , V_72 ) ;
if ( ! V_65 ) {
V_33 = - V_55 ;
goto V_73;
}
V_67 = F_30 ( V_65 , V_62 , V_63 ) ;
if ( V_67 > 0 ) {
V_33 = - V_74 ;
goto V_75;
}
V_67 = F_31 ( & V_4 -> V_76 ) ;
V_33 = - V_77 ;
if ( V_67 )
goto V_75;
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_33 = - V_78 ;
goto V_79;
}
V_67 = F_32 ( V_4 -> V_3 ) ;
if ( V_67 < 0 ) {
V_33 = F_28 ( V_67 ) ;
goto V_79;
}
if ( ! ( V_61 -> V_80 & V_81 ) )
V_67 = F_33 ( V_4 -> V_16 , ! F_14 ( V_14 ,
& V_4 -> V_15 ) ) ;
else
if ( F_14 ( V_14 , & V_4 -> V_15 ) )
V_67 = - V_82 ;
if ( F_14 ( V_83 , & V_4 -> V_15 ) )
V_67 = - V_84 ;
if ( V_67 < 0 ) {
V_33 = V_67 ;
goto V_85;
}
V_71 = V_4 -> V_59 ;
F_34 (
V_4 -> V_57 ,
F_35 ( V_4 -> V_3 ) ,
F_36 ( F_35 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_71 ,
V_65 ,
V_63 ,
F_6 ,
V_4
) ;
V_71 -> V_86 = ( V_87 | V_88 |
V_89 ) ;
V_71 -> V_90 = V_91 ;
V_71 -> V_45 = 0 ;
V_71 -> V_42 = V_4 -> V_92 ;
V_71 -> V_43 = F_37 ( V_63 ) ;
F_13 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_65 ;
V_33 = F_18 ( V_4 -> V_57 , V_72 ) ;
if ( V_33 < 0 ) {
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_18 , V_33 ) ;
V_33 = F_28 ( V_33 ) ;
goto V_85;
} else {
F_11 ( & V_4 -> V_3 -> V_21 , L_19 ,
F_16 ( V_71 -> V_42 ) ) ;
}
F_38 ( V_4 -> V_3 ) ;
F_39 ( & V_4 -> V_76 ) ;
V_73:
return V_33 < 0 ? V_33 : V_63 ;
V_85:
F_38 ( V_4 -> V_3 ) ;
V_79:
F_39 ( & V_4 -> V_76 ) ;
V_75:
F_7 ( V_65 ) ;
return V_33 ;
}
static int F_40 ( struct V_1 * V_4 )
{
int V_33 = 0 ;
F_8 ( V_32 , & V_4 -> V_15 ) ;
if ( ! V_4 -> V_48 || ! -- V_4 -> V_48 )
goto V_93;
F_13 ( V_19 , & V_4 -> V_15 ) ;
F_27 ( & V_4 -> V_10 ) ;
V_33 = F_18 ( V_4 -> V_51 , V_72 ) ;
F_26 ( & V_4 -> V_10 ) ;
if ( V_33 ) {
F_12 ( & V_4 -> V_3 -> V_21 ,
L_20 , V_33 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
V_4 -> V_48 = 0 ;
}
V_93:
return V_33 ;
}
static T_1 F_41
( struct V_61 * V_61 , char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
int V_33 , V_94 ;
int V_95 = 0 ;
struct V_1 * V_4 = V_61 -> V_69 ;
V_33 = F_31 ( & V_4 -> V_96 ) ;
if ( V_33 < 0 )
return - V_77 ;
V_94 = F_42 ( V_4 -> V_17 ) ;
if ( V_94 == 0 ) {
V_4 -> V_97 = 0 ;
V_98:
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_33 = - V_78 ;
goto V_99;
}
if ( F_14 ( V_28 , & V_4 -> V_15 ) ) {
F_8 ( V_28 , & V_4 -> V_15 ) ;
V_33 = - V_100 ;
goto V_99;
}
V_95 ++ ;
if ( V_61 -> V_80 & V_81 ) {
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
V_33 = V_94 ? V_94 : - V_82 ;
goto V_99;
}
V_33 = 0 ;
} else {
V_33 = F_33 ( V_4 -> V_16 ,
F_14 ( V_32 , & V_4 -> V_15 ) ) ;
}
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_33 = - V_78 ;
goto V_99;
}
if ( F_14 ( V_83 , & V_4 -> V_15 ) ) {
V_33 = - V_84 ;
goto V_99;
}
F_43 ( F_35 ( V_4 -> V_3 ) ) ;
if ( V_33 < 0 ) {
V_33 = - V_77 ;
goto V_99;
}
F_26 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_26 ) {
V_33 = F_28 ( V_4 -> V_26 ) ;
V_4 -> V_26 = 0 ;
F_27 ( & V_4 -> V_10 ) ;
goto V_99;
}
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
F_27 ( & V_4 -> V_10 ) ;
goto V_98;
}
if ( ! V_4 -> V_31 ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_21 , V_53 ) ;
V_33 = F_40 ( V_4 ) ;
F_27 ( & V_4 -> V_10 ) ;
if ( V_33 < 0 )
goto V_99;
goto V_98;
}
V_94 = V_4 -> V_17 ;
F_27 ( & V_4 -> V_10 ) ;
}
if ( V_94 > V_63 )
V_94 = V_63 ;
V_33 = F_44 ( V_62 , V_4 -> V_29 , V_94 ) ;
if ( V_33 > 0 ) {
V_33 = - V_74 ;
goto V_99;
}
F_26 ( & V_4 -> V_10 ) ;
for ( V_95 = 0 ; V_95 < V_4 -> V_17 - V_94 ; V_95 ++ )
V_4 -> V_29 [ V_95 ] = V_4 -> V_29 [ V_95 + V_94 ] ;
V_4 -> V_17 -= V_94 ;
if ( ! V_4 -> V_17 )
F_40 ( V_4 ) ;
F_27 ( & V_4 -> V_10 ) ;
V_33 = V_94 ;
V_99:
F_39 ( & V_4 -> V_96 ) ;
return V_33 ;
}
static int F_45 ( struct V_61 * V_61 , T_6 V_101 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
F_46 ( V_4 -> V_16 , ! F_14 ( V_14 , & V_4 -> V_15 ) ) ;
if ( V_4 -> V_11 < 0 && ! F_14 ( V_49 , & V_4 -> V_15 ) )
F_12 ( & V_4 -> V_3 -> V_21 , L_22 ,
V_4 -> V_11 ) ;
return F_28 ( V_4 -> V_11 ) ;
}
static unsigned int F_47 ( struct V_61 * V_61 , struct V_102 * V_16 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
unsigned long V_15 ;
unsigned int V_103 = 0 ;
F_48 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_103 = V_104 | V_105 ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
goto V_106;
}
if ( F_14 ( V_32 , & V_4 -> V_15 ) )
V_103 = V_107 | V_108 ;
if ( V_4 -> V_26 || V_4 -> V_11 )
V_103 |= V_105 ;
if ( ! F_14 ( V_14 , & V_4 -> V_15 ) )
V_103 |= V_109 | V_110 ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
F_50 ( V_61 , & V_4 -> V_16 , V_16 ) ;
V_106:
return V_103 ;
}
static int F_51 ( struct V_111 * V_111 , struct V_61 * V_61 )
{
int V_7 = F_52 ( V_111 ) ;
int V_33 = - V_78 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_53 ( & V_112 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ! V_4 )
goto V_93;
V_3 = V_4 -> V_3 ;
if ( F_14 ( V_49 , & V_4 -> V_15 ) )
goto V_93;
V_61 -> V_69 = V_4 ;
V_33 = F_32 ( V_4 -> V_3 ) ;
if ( V_33 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_23 , V_33 ) ;
goto V_93;
}
F_53 ( & V_4 -> V_76 ) ;
if ( ! V_4 -> V_63 ++ ) {
V_4 -> V_11 = 0 ;
V_4 -> V_26 = 0 ;
V_33 = F_18 ( V_4 -> V_58 , V_72 ) ;
if ( V_33 < 0 ) {
V_4 -> V_63 -- ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_24 , V_33 ) ;
V_33 = F_28 ( V_33 ) ;
}
} else {
V_33 = 0 ;
}
F_39 ( & V_4 -> V_76 ) ;
if ( V_4 -> V_63 == 1 )
V_4 -> V_113 ( V_3 , 1 ) ;
F_38 ( V_4 -> V_3 ) ;
V_93:
F_39 ( & V_112 ) ;
return V_33 ;
}
static int F_54 ( struct V_111 * V_111 , struct V_61 * V_61 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
F_53 ( & V_112 ) ;
F_53 ( & V_4 -> V_76 ) ;
V_4 -> V_63 -- ;
F_39 ( & V_4 -> V_76 ) ;
if ( ! V_4 -> V_63 ) {
if ( ! F_14 ( V_49 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_25 ) ;
F_20 ( V_4 ) ;
F_26 ( & V_4 -> V_10 ) ;
V_4 -> V_48 = 0 ;
F_27 ( & V_4 -> V_10 ) ;
V_4 -> V_113 ( V_4 -> V_3 , 0 ) ;
} else {
F_55 ( V_114 L_26 , V_53 ) ;
F_24 ( V_4 ) ;
}
}
F_39 ( & V_112 ) ;
return 0 ;
}
static long F_56 ( struct V_61 * V_61 , unsigned int V_115 , unsigned long V_116 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
int V_33 = 0 ;
switch ( V_115 ) {
case V_117 :
if ( F_44 ( ( void T_2 * ) V_116 , & V_4 -> V_27 , sizeof( V_4 -> V_27 ) ) )
V_33 = - V_74 ;
break;
default:
V_33 = - V_118 ;
}
return V_33 ;
}
static void F_57 ( struct V_119 * V_120 )
{
struct V_1 * V_4 = F_58 ( V_120 , struct V_1 , V_56 ) ;
unsigned long V_15 ;
int V_33 = 0 ;
int V_34 ;
F_48 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
F_49 ( & V_4 -> V_10 , V_15 ) ;
} else {
V_34 = F_17 ( V_19 , & V_4 -> V_15 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
if ( ! V_34 )
V_33 = F_18 ( V_4 -> V_51 , V_72 ) ;
if ( V_33 < 0 && V_33 != - V_54 ) {
F_48 ( & V_4 -> V_10 , V_15 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( ! F_14 ( V_49 , & V_4 -> V_15 ) )
F_19 ( & V_4 -> V_56 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
}
}
}
static int F_59 ( struct V_2 * V_3 , struct V_121 * V_122 ,
T_7 V_123 , int (* V_113)( struct V_2 * , int ) )
{
int V_33 = - V_55 ;
struct V_1 * V_4 ;
V_4 = F_60 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_4 )
goto V_93;
F_61 ( & V_4 -> V_124 ) ;
F_62 ( & V_4 -> V_96 ) ;
F_62 ( & V_4 -> V_76 ) ;
F_63 ( & V_4 -> V_10 ) ;
F_64 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = V_123 ;
V_4 -> V_92 = F_37 ( ( T_7 ) V_3 -> V_125 -> V_4 . V_126 ) ;
V_4 -> V_3 = V_3 ;
F_65 ( & V_4 -> V_56 , F_57 ) ;
V_33 = - V_127 ;
if ( ! F_66 ( V_122 ) )
goto V_99;
V_4 -> V_128 = F_67 ( V_122 ) ;
V_4 -> V_59 = F_29 ( sizeof( struct V_70 ) , V_72 ) ;
if ( ! V_4 -> V_59 )
goto V_99;
V_4 -> V_60 = F_29 ( sizeof( struct V_70 ) , V_72 ) ;
if ( ! V_4 -> V_60 )
goto V_99;
V_4 -> V_58 = F_68 ( 0 , V_72 ) ;
if ( ! V_4 -> V_58 )
goto V_99;
V_4 -> V_51 = F_68 ( 0 , V_72 ) ;
if ( ! V_4 -> V_51 )
goto V_99;
V_4 -> V_57 = F_68 ( 0 , V_72 ) ;
if ( ! V_4 -> V_57 )
goto V_99;
V_4 -> V_29 = F_29 ( V_4 -> V_27 , V_72 ) ;
if ( ! V_4 -> V_29 )
goto V_99;
V_4 -> V_37 = F_29 ( V_4 -> V_128 , V_72 ) ;
if ( ! V_4 -> V_37 )
goto V_99;
V_4 -> V_30 = F_29 ( V_4 -> V_27 , V_72 ) ;
if ( ! V_4 -> V_30 )
goto V_99;
F_69 (
V_4 -> V_58 ,
F_35 ( V_3 ) ,
F_70 ( F_35 ( V_3 ) , V_122 -> V_129 ) ,
V_4 -> V_37 ,
V_4 -> V_128 ,
F_15 ,
V_4 ,
V_122 -> V_130
) ;
V_4 -> V_60 -> V_86 = ( V_131 | V_88 | V_89 ) ;
V_4 -> V_60 -> V_90 = V_132 ;
V_4 -> V_60 -> V_45 = 0 ;
V_4 -> V_60 -> V_42 = V_4 -> V_92 ;
V_4 -> V_60 -> V_43 = F_37 ( V_4 -> V_27 ) ;
F_34 (
V_4 -> V_51 ,
F_35 ( V_3 ) ,
F_71 ( F_35 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_60 ,
V_4 -> V_30 ,
V_4 -> V_27 ,
F_10 ,
V_4
) ;
V_4 -> V_113 = V_113 ;
F_2 ( & V_5 ) ;
F_72 ( & V_4 -> V_124 , & V_133 ) ;
F_4 ( & V_5 ) ;
V_33 = F_73 ( V_3 , & V_134 ) ;
if ( V_33 < 0 )
goto V_99;
else
F_74 ( & V_3 -> V_21 , L_27 , F_75 ( V_3 -> V_135 ) ) ;
V_93:
return V_33 ;
V_99:
F_2 ( & V_5 ) ;
F_76 ( & V_4 -> V_124 ) ;
F_4 ( & V_5 ) ;
F_24 ( V_4 ) ;
return V_33 ;
}
static int F_77 ( struct V_2 * V_3 , int V_136 )
{
int V_33 = F_32 ( V_3 ) ;
V_3 -> V_137 = V_136 ;
if ( ! V_33 )
F_38 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 , const struct V_138 * V_101 )
{
int V_33 = - V_127 ;
struct V_139 * V_140 ;
struct V_121 * V_122 ;
struct V_141 * V_142 ;
T_5 * V_62 = V_3 -> V_143 -> V_144 ;
int V_145 = V_3 -> V_143 -> V_146 ;
T_7 V_147 = V_148 ;
if ( ! V_62 )
goto V_99;
while ( V_145 > 2 ) {
if ( V_62 [ 1 ] != V_149 ) {
F_12 ( & V_3 -> V_21 , L_28 ) ;
goto V_150;
}
switch ( V_62 [ 2 ] ) {
case V_151 :
break;
case V_152 :
V_142 = (struct V_141 * ) V_62 ;
V_147 = F_16 ( V_142 -> V_27 ) ;
F_11 ( & V_3 -> V_21 ,
L_29 , V_147 ) ;
break;
default:
F_12 ( & V_3 -> V_21 ,
L_30 ,
V_62 [ 2 ] , V_62 [ 0 ] ) ;
break;
}
V_150:
V_145 -= V_62 [ 0 ] ;
V_62 += V_62 [ 0 ] ;
}
V_140 = V_3 -> V_125 ;
if ( V_140 -> V_4 . V_153 != 1 )
goto V_99;
V_122 = & V_140 -> V_154 [ 0 ] . V_4 ;
V_33 = F_59 ( V_3 , V_122 , V_147 , & F_77 ) ;
V_99:
return V_33 ;
}
struct V_155 * F_79 ( struct V_2 * V_3 ,
struct V_121 * V_122 ,
int V_123 ,
int (* V_113)( struct V_2 * , int ) )
{
int V_33 = - V_127 ;
V_33 = F_59 ( V_3 , V_122 , V_123 , V_113 ) ;
if ( V_33 < 0 )
goto V_99;
return & V_156 ;
V_99:
return F_80 ( V_33 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_82 ( V_3 , & V_134 ) ;
V_4 = F_1 ( V_3 ) ;
F_53 ( & V_112 ) ;
F_48 ( & V_4 -> V_10 , V_15 ) ;
F_13 ( V_49 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
F_83 ( & V_4 -> V_16 ) ;
F_53 ( & V_4 -> V_96 ) ;
F_53 ( & V_4 -> V_76 ) ;
F_20 ( V_4 ) ;
F_84 ( & V_4 -> V_56 ) ;
F_39 ( & V_4 -> V_76 ) ;
F_39 ( & V_4 -> V_96 ) ;
F_2 ( & V_5 ) ;
F_76 ( & V_4 -> V_124 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_63 )
F_24 ( V_4 ) ;
else
F_11 ( & V_3 -> V_21 , L_31 , V_53 , V_4 -> V_63 ) ;
F_39 ( & V_112 ) ;
}
static int F_85 ( struct V_2 * V_3 , T_8 V_157 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 = 0 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_32 , V_3 -> V_7 ) ;
if ( ! F_86 ( V_157 ) ) {
F_53 ( & V_4 -> V_96 ) ;
F_53 ( & V_4 -> V_76 ) ;
}
F_26 ( & V_4 -> V_10 ) ;
if ( F_86 ( V_157 ) &&
( F_14 ( V_14 , & V_4 -> V_15 )
|| F_14 ( V_19 , & V_4 -> V_15 ) ) ) {
F_27 ( & V_4 -> V_10 ) ;
V_33 = - V_158 ;
} else {
F_13 ( V_50 , & V_4 -> V_15 ) ;
F_27 ( & V_4 -> V_10 ) ;
F_20 ( V_4 ) ;
F_84 ( & V_4 -> V_56 ) ;
}
if ( ! F_86 ( V_157 ) ) {
F_39 ( & V_4 -> V_76 ) ;
F_39 ( & V_4 -> V_96 ) ;
}
return V_33 ;
}
static int F_87 ( struct V_1 * V_4 )
{
int V_33 = 0 ;
if ( V_4 -> V_63 ) {
V_33 = F_18 ( V_4 -> V_58 , V_159 ) ;
if ( V_33 < 0 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_33 , V_33 ) ;
}
return V_33 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_34 , V_3 -> V_7 ) ;
F_8 ( V_50 , & V_4 -> V_15 ) ;
V_33 = F_87 ( V_4 ) ;
return V_33 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_26 ( & V_4 -> V_10 ) ;
F_13 ( V_83 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_26 = - V_160 ;
F_27 ( & V_4 -> V_10 ) ;
F_83 ( & V_4 -> V_16 ) ;
F_53 ( & V_4 -> V_96 ) ;
F_53 ( & V_4 -> V_76 ) ;
F_20 ( V_4 ) ;
F_84 ( & V_4 -> V_56 ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_8 ( V_28 , & V_4 -> V_15 ) ;
F_8 ( V_83 , & V_4 -> V_15 ) ;
V_33 = F_87 ( V_4 ) ;
F_39 ( & V_4 -> V_76 ) ;
F_39 ( & V_4 -> V_96 ) ;
return 0 ;
}
