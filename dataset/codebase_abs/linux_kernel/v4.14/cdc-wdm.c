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
if ( V_4 -> V_26 == 0 && V_12 != - V_25 )
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
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_9 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_26 ) {
F_15 ( V_4 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
}
static void F_16 ( struct V_8 * V_8 )
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
F_17 ( V_36 -> V_42 ) , F_17 ( V_36 -> V_43 ) ) ;
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
F_17 ( V_36 -> V_42 ) ,
F_17 ( V_36 -> V_43 ) ) ;
goto exit;
}
F_2 ( & V_4 -> V_10 ) ;
V_34 = F_18 ( V_19 , & V_4 -> V_15 ) ;
if ( ! V_4 -> V_48 ++ && ! V_34
&& ! F_14 ( V_49 , & V_4 -> V_15 )
&& ! F_14 ( V_50 , & V_4 -> V_15 ) ) {
V_33 = F_19 ( V_4 -> V_51 , V_52 ) ;
F_11 ( & V_4 -> V_3 -> V_21 , L_15 , V_33 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
if ( V_33 < 0 ) {
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( V_33 == - V_53 )
return;
if ( V_33 == - V_54 ) {
V_39:
V_33 = F_20 ( & V_4 -> V_55 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_16 ) ;
}
}
exit:
V_33 = F_19 ( V_8 , V_52 ) ;
if ( V_33 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_17 ,
V_56 , V_33 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
F_22 ( V_4 -> V_57 ) ;
F_22 ( V_4 -> V_58 ) ;
F_22 ( V_4 -> V_51 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_24 ( V_4 -> V_58 ) ;
F_24 ( V_4 -> V_51 ) ;
F_24 ( V_4 -> V_57 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_37 ) ;
F_7 ( V_4 -> V_30 ) ;
F_7 ( V_4 -> V_59 ) ;
F_7 ( V_4 -> V_60 ) ;
F_7 ( V_4 -> V_29 ) ;
F_23 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_26
( struct V_61 * V_61 , const char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
T_5 * V_65 ;
int V_33 = - V_66 , V_67 , V_68 ;
struct V_1 * V_4 = V_61 -> V_69 ;
struct V_70 * V_71 ;
if ( V_63 > V_4 -> V_27 )
V_63 = V_4 -> V_27 ;
F_27 ( & V_4 -> V_10 ) ;
V_68 = V_4 -> V_11 ;
V_4 -> V_11 = 0 ;
F_28 ( & V_4 -> V_10 ) ;
if ( V_68 < 0 )
return F_29 ( V_68 ) ;
V_65 = F_30 ( V_62 , V_63 ) ;
if ( F_31 ( V_65 ) )
return F_32 ( V_65 ) ;
V_67 = F_33 ( & V_4 -> V_72 ) ;
V_33 = - V_73 ;
if ( V_67 )
goto V_74;
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_33 = - V_75 ;
goto V_76;
}
V_67 = F_34 ( V_4 -> V_3 ) ;
if ( V_67 < 0 ) {
V_33 = F_29 ( V_67 ) ;
goto V_76;
}
if ( ! ( V_61 -> V_77 & V_78 ) )
V_67 = F_35 ( V_4 -> V_16 , ! F_14 ( V_14 ,
& V_4 -> V_15 ) ) ;
else
if ( F_14 ( V_14 , & V_4 -> V_15 ) )
V_67 = - V_79 ;
if ( F_14 ( V_80 , & V_4 -> V_15 ) )
V_67 = - V_81 ;
if ( V_67 < 0 ) {
V_33 = V_67 ;
goto V_82;
}
V_71 = V_4 -> V_59 ;
F_36 (
V_4 -> V_57 ,
F_37 ( V_4 -> V_3 ) ,
F_38 ( F_37 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_71 ,
V_65 ,
V_63 ,
F_6 ,
V_4
) ;
V_71 -> V_83 = ( V_84 | V_85 |
V_86 ) ;
V_71 -> V_87 = V_88 ;
V_71 -> V_45 = 0 ;
V_71 -> V_42 = V_4 -> V_89 ;
V_71 -> V_43 = F_39 ( V_63 ) ;
F_13 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_65 ;
V_33 = F_19 ( V_4 -> V_57 , V_90 ) ;
if ( V_33 < 0 ) {
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_18 , V_33 ) ;
V_33 = F_29 ( V_33 ) ;
goto V_82;
} else {
F_11 ( & V_4 -> V_3 -> V_21 , L_19 ,
F_17 ( V_71 -> V_42 ) ) ;
}
F_40 ( V_4 -> V_3 ) ;
F_41 ( & V_4 -> V_72 ) ;
return V_63 ;
V_82:
F_40 ( V_4 -> V_3 ) ;
V_76:
F_41 ( & V_4 -> V_72 ) ;
V_74:
F_7 ( V_65 ) ;
return V_33 ;
}
static int F_15 ( struct V_1 * V_4 )
{
int V_33 = 0 ;
if ( ! V_4 -> V_48 || ! -- V_4 -> V_48 )
goto V_91;
F_13 ( V_19 , & V_4 -> V_15 ) ;
F_28 ( & V_4 -> V_10 ) ;
V_33 = F_19 ( V_4 -> V_51 , V_90 ) ;
F_27 ( & V_4 -> V_10 ) ;
if ( V_33 ) {
F_12 ( & V_4 -> V_3 -> V_21 ,
L_20 , V_33 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
V_4 -> V_48 = 0 ;
}
V_91:
return V_33 ;
}
static T_1 F_42
( struct V_61 * V_61 , char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
int V_33 , V_92 ;
int V_93 = 0 ;
struct V_1 * V_4 = V_61 -> V_69 ;
V_33 = F_33 ( & V_4 -> V_94 ) ;
if ( V_33 < 0 )
return - V_73 ;
V_92 = F_43 ( V_4 -> V_17 ) ;
if ( V_92 == 0 ) {
V_4 -> V_95 = 0 ;
V_96:
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_33 = - V_75 ;
goto V_97;
}
if ( F_14 ( V_28 , & V_4 -> V_15 ) ) {
F_8 ( V_28 , & V_4 -> V_15 ) ;
V_33 = - V_98 ;
goto V_97;
}
V_93 ++ ;
if ( V_61 -> V_77 & V_78 ) {
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
V_33 = - V_79 ;
goto V_97;
}
V_33 = 0 ;
} else {
V_33 = F_35 ( V_4 -> V_16 ,
F_14 ( V_32 , & V_4 -> V_15 ) ) ;
}
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_33 = - V_75 ;
goto V_97;
}
if ( F_14 ( V_80 , & V_4 -> V_15 ) ) {
V_33 = - V_81 ;
goto V_97;
}
F_44 ( F_37 ( V_4 -> V_3 ) ) ;
if ( V_33 < 0 ) {
V_33 = - V_73 ;
goto V_97;
}
F_27 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_26 ) {
V_33 = F_29 ( V_4 -> V_26 ) ;
V_4 -> V_26 = 0 ;
F_28 ( & V_4 -> V_10 ) ;
goto V_97;
}
if ( ! F_14 ( V_32 , & V_4 -> V_15 ) ) {
F_28 ( & V_4 -> V_10 ) ;
goto V_96;
}
if ( ! V_4 -> V_31 ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_21 ) ;
F_8 ( V_32 , & V_4 -> V_15 ) ;
V_33 = F_15 ( V_4 ) ;
F_28 ( & V_4 -> V_10 ) ;
if ( V_33 < 0 )
goto V_97;
goto V_96;
}
V_92 = V_4 -> V_17 ;
F_28 ( & V_4 -> V_10 ) ;
}
if ( V_92 > V_63 )
V_92 = V_63 ;
V_33 = F_45 ( V_62 , V_4 -> V_29 , V_92 ) ;
if ( V_33 > 0 ) {
V_33 = - V_99 ;
goto V_97;
}
F_27 ( & V_4 -> V_10 ) ;
for ( V_93 = 0 ; V_93 < V_4 -> V_17 - V_92 ; V_93 ++ )
V_4 -> V_29 [ V_93 ] = V_4 -> V_29 [ V_93 + V_92 ] ;
V_4 -> V_17 -= V_92 ;
if ( ! V_4 -> V_17 ) {
F_8 ( V_32 , & V_4 -> V_15 ) ;
F_15 ( V_4 ) ;
}
F_28 ( & V_4 -> V_10 ) ;
V_33 = V_92 ;
V_97:
F_41 ( & V_4 -> V_94 ) ;
return V_33 ;
}
static int F_46 ( struct V_61 * V_61 , T_6 V_100 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
F_47 ( V_4 -> V_16 , ! F_14 ( V_14 , & V_4 -> V_15 ) ) ;
if ( V_4 -> V_11 < 0 && ! F_14 ( V_49 , & V_4 -> V_15 ) )
F_12 ( & V_4 -> V_3 -> V_21 , L_22 ,
V_4 -> V_11 ) ;
return F_29 ( V_4 -> V_11 ) ;
}
static unsigned int F_48 ( struct V_61 * V_61 , struct V_101 * V_16 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
unsigned long V_15 ;
unsigned int V_102 = 0 ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
V_102 = V_103 | V_104 ;
F_50 ( & V_4 -> V_10 , V_15 ) ;
goto V_105;
}
if ( F_14 ( V_32 , & V_4 -> V_15 ) )
V_102 = V_106 | V_107 ;
if ( V_4 -> V_26 || V_4 -> V_11 )
V_102 |= V_104 ;
if ( ! F_14 ( V_14 , & V_4 -> V_15 ) )
V_102 |= V_108 | V_109 ;
F_50 ( & V_4 -> V_10 , V_15 ) ;
F_51 ( V_61 , & V_4 -> V_16 , V_16 ) ;
V_105:
return V_102 ;
}
static int F_52 ( struct V_110 * V_110 , struct V_61 * V_61 )
{
int V_7 = F_53 ( V_110 ) ;
int V_33 = - V_75 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_54 ( & V_111 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ! V_4 )
goto V_91;
V_3 = V_4 -> V_3 ;
if ( F_14 ( V_49 , & V_4 -> V_15 ) )
goto V_91;
V_61 -> V_69 = V_4 ;
V_33 = F_34 ( V_4 -> V_3 ) ;
if ( V_33 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_23 , V_33 ) ;
goto V_91;
}
F_54 ( & V_4 -> V_72 ) ;
if ( ! V_4 -> V_63 ++ ) {
V_4 -> V_11 = 0 ;
V_4 -> V_26 = 0 ;
V_33 = F_19 ( V_4 -> V_58 , V_90 ) ;
if ( V_33 < 0 ) {
V_4 -> V_63 -- ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_24 , V_33 ) ;
V_33 = F_29 ( V_33 ) ;
}
} else {
V_33 = 0 ;
}
F_41 ( & V_4 -> V_72 ) ;
if ( V_4 -> V_63 == 1 )
V_4 -> V_112 ( V_3 , 1 ) ;
F_40 ( V_4 -> V_3 ) ;
V_91:
F_41 ( & V_111 ) ;
return V_33 ;
}
static int F_55 ( struct V_110 * V_110 , struct V_61 * V_61 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
F_54 ( & V_111 ) ;
F_54 ( & V_4 -> V_72 ) ;
V_4 -> V_63 -- ;
F_41 ( & V_4 -> V_72 ) ;
if ( ! V_4 -> V_63 ) {
if ( ! F_14 ( V_49 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_25 ) ;
F_21 ( V_4 ) ;
F_27 ( & V_4 -> V_10 ) ;
V_4 -> V_48 = 0 ;
F_28 ( & V_4 -> V_10 ) ;
V_4 -> V_112 ( V_4 -> V_3 , 0 ) ;
} else {
F_56 ( V_113 L_26 , V_56 ) ;
F_25 ( V_4 ) ;
}
}
F_41 ( & V_111 ) ;
return 0 ;
}
static long F_57 ( struct V_61 * V_61 , unsigned int V_114 , unsigned long V_115 )
{
struct V_1 * V_4 = V_61 -> V_69 ;
int V_33 = 0 ;
switch ( V_114 ) {
case V_116 :
if ( F_45 ( ( void T_2 * ) V_115 , & V_4 -> V_27 , sizeof( V_4 -> V_27 ) ) )
V_33 = - V_99 ;
break;
default:
V_33 = - V_117 ;
}
return V_33 ;
}
static void F_58 ( struct V_118 * V_119 )
{
struct V_1 * V_4 = F_59 ( V_119 , struct V_1 , V_55 ) ;
unsigned long V_15 ;
int V_33 = 0 ;
int V_34 ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_49 , & V_4 -> V_15 ) ) {
F_50 ( & V_4 -> V_10 , V_15 ) ;
} else {
V_34 = F_18 ( V_19 , & V_4 -> V_15 ) ;
F_50 ( & V_4 -> V_10 , V_15 ) ;
if ( ! V_34 )
V_33 = F_19 ( V_4 -> V_51 , V_90 ) ;
if ( V_33 < 0 && V_33 != - V_53 ) {
F_49 ( & V_4 -> V_10 , V_15 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( ! F_14 ( V_49 , & V_4 -> V_15 ) )
F_20 ( & V_4 -> V_55 ) ;
F_50 ( & V_4 -> V_10 , V_15 ) ;
}
}
}
static int F_60 ( struct V_2 * V_3 , struct V_120 * V_121 ,
T_7 V_122 , int (* V_112)( struct V_2 * , int ) )
{
int V_33 = - V_54 ;
struct V_1 * V_4 ;
V_4 = F_61 ( sizeof( struct V_1 ) , V_90 ) ;
if ( ! V_4 )
goto V_91;
F_62 ( & V_4 -> V_123 ) ;
F_63 ( & V_4 -> V_94 ) ;
F_63 ( & V_4 -> V_72 ) ;
F_64 ( & V_4 -> V_10 ) ;
F_65 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = V_122 ;
V_4 -> V_89 = F_39 ( ( T_7 ) V_3 -> V_124 -> V_4 . V_125 ) ;
V_4 -> V_3 = V_3 ;
F_66 ( & V_4 -> V_55 , F_58 ) ;
V_33 = - V_126 ;
if ( ! F_67 ( V_121 ) )
goto V_97;
V_4 -> V_127 = F_68 ( V_121 ) ;
V_4 -> V_59 = F_69 ( sizeof( struct V_70 ) , V_90 ) ;
if ( ! V_4 -> V_59 )
goto V_97;
V_4 -> V_60 = F_69 ( sizeof( struct V_70 ) , V_90 ) ;
if ( ! V_4 -> V_60 )
goto V_97;
V_4 -> V_58 = F_70 ( 0 , V_90 ) ;
if ( ! V_4 -> V_58 )
goto V_97;
V_4 -> V_51 = F_70 ( 0 , V_90 ) ;
if ( ! V_4 -> V_51 )
goto V_97;
V_4 -> V_57 = F_70 ( 0 , V_90 ) ;
if ( ! V_4 -> V_57 )
goto V_97;
V_4 -> V_29 = F_69 ( V_4 -> V_27 , V_90 ) ;
if ( ! V_4 -> V_29 )
goto V_97;
V_4 -> V_37 = F_69 ( V_4 -> V_127 , V_90 ) ;
if ( ! V_4 -> V_37 )
goto V_97;
V_4 -> V_30 = F_69 ( V_4 -> V_27 , V_90 ) ;
if ( ! V_4 -> V_30 )
goto V_97;
F_71 (
V_4 -> V_58 ,
F_37 ( V_3 ) ,
F_72 ( F_37 ( V_3 ) , V_121 -> V_128 ) ,
V_4 -> V_37 ,
V_4 -> V_127 ,
F_16 ,
V_4 ,
V_121 -> V_129
) ;
V_4 -> V_60 -> V_83 = ( V_130 | V_85 | V_86 ) ;
V_4 -> V_60 -> V_87 = V_131 ;
V_4 -> V_60 -> V_45 = 0 ;
V_4 -> V_60 -> V_42 = V_4 -> V_89 ;
V_4 -> V_60 -> V_43 = F_39 ( V_4 -> V_27 ) ;
F_36 (
V_4 -> V_51 ,
F_37 ( V_3 ) ,
F_73 ( F_37 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_60 ,
V_4 -> V_30 ,
V_4 -> V_27 ,
F_10 ,
V_4
) ;
V_4 -> V_112 = V_112 ;
F_2 ( & V_5 ) ;
F_74 ( & V_4 -> V_123 , & V_132 ) ;
F_4 ( & V_5 ) ;
V_33 = F_75 ( V_3 , & V_133 ) ;
if ( V_33 < 0 )
goto V_97;
else
F_76 ( & V_3 -> V_21 , L_27 , F_77 ( V_3 -> V_134 ) ) ;
V_91:
return V_33 ;
V_97:
F_2 ( & V_5 ) ;
F_78 ( & V_4 -> V_123 ) ;
F_4 ( & V_5 ) ;
F_25 ( V_4 ) ;
return V_33 ;
}
static int F_79 ( struct V_2 * V_3 , int V_135 )
{
int V_33 = F_34 ( V_3 ) ;
V_3 -> V_136 = V_135 ;
if ( ! V_33 )
F_40 ( V_3 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 , const struct V_137 * V_100 )
{
int V_33 = - V_126 ;
struct V_138 * V_139 ;
struct V_120 * V_121 ;
struct V_140 V_141 ;
T_5 * V_62 = V_3 -> V_142 -> V_143 ;
int V_144 = V_3 -> V_142 -> V_145 ;
T_7 V_146 = V_147 ;
if ( ! V_62 )
goto V_97;
F_81 ( & V_141 , V_3 , V_62 , V_144 ) ;
if ( V_141 . V_148 )
V_146 = F_17 ( V_141 . V_148 -> V_27 ) ;
V_139 = V_3 -> V_124 ;
if ( V_139 -> V_4 . V_149 != 1 )
goto V_97;
V_121 = & V_139 -> V_150 [ 0 ] . V_4 ;
V_33 = F_60 ( V_3 , V_121 , V_146 , & F_79 ) ;
V_97:
return V_33 ;
}
struct V_151 * F_82 ( struct V_2 * V_3 ,
struct V_120 * V_121 ,
int V_122 ,
int (* V_112)( struct V_2 * , int ) )
{
int V_33 = - V_126 ;
V_33 = F_60 ( V_3 , V_121 , V_122 , V_112 ) ;
if ( V_33 < 0 )
goto V_97;
return & V_152 ;
V_97:
return F_83 ( V_33 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_85 ( V_3 , & V_133 ) ;
V_4 = F_1 ( V_3 ) ;
F_54 ( & V_111 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
F_13 ( V_49 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_50 ( & V_4 -> V_10 , V_15 ) ;
F_86 ( & V_4 -> V_16 ) ;
F_54 ( & V_4 -> V_94 ) ;
F_54 ( & V_4 -> V_72 ) ;
F_21 ( V_4 ) ;
F_87 ( & V_4 -> V_55 ) ;
F_41 ( & V_4 -> V_72 ) ;
F_41 ( & V_4 -> V_94 ) ;
F_2 ( & V_5 ) ;
F_78 ( & V_4 -> V_123 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_63 )
F_25 ( V_4 ) ;
else
F_11 ( & V_3 -> V_21 , L_28 , V_4 -> V_63 ) ;
F_41 ( & V_111 ) ;
}
static int F_88 ( struct V_2 * V_3 , T_8 V_153 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 = 0 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_29 , V_3 -> V_7 ) ;
if ( ! F_89 ( V_153 ) ) {
F_54 ( & V_4 -> V_94 ) ;
F_54 ( & V_4 -> V_72 ) ;
}
F_27 ( & V_4 -> V_10 ) ;
if ( F_89 ( V_153 ) &&
( F_14 ( V_14 , & V_4 -> V_15 )
|| F_14 ( V_19 , & V_4 -> V_15 ) ) ) {
F_28 ( & V_4 -> V_10 ) ;
V_33 = - V_154 ;
} else {
F_13 ( V_50 , & V_4 -> V_15 ) ;
F_28 ( & V_4 -> V_10 ) ;
F_21 ( V_4 ) ;
F_87 ( & V_4 -> V_55 ) ;
}
if ( ! F_89 ( V_153 ) ) {
F_41 ( & V_4 -> V_72 ) ;
F_41 ( & V_4 -> V_94 ) ;
}
return V_33 ;
}
static int F_90 ( struct V_1 * V_4 )
{
int V_33 = 0 ;
if ( V_4 -> V_63 ) {
V_33 = F_19 ( V_4 -> V_58 , V_155 ) ;
if ( V_33 < 0 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_30 , V_33 ) ;
}
return V_33 ;
}
static int F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_31 , V_3 -> V_7 ) ;
F_8 ( V_50 , & V_4 -> V_15 ) ;
V_33 = F_90 ( V_4 ) ;
return V_33 ;
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_27 ( & V_4 -> V_10 ) ;
F_13 ( V_80 , & V_4 -> V_15 ) ;
F_13 ( V_32 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_26 = - V_156 ;
F_28 ( & V_4 -> V_10 ) ;
F_86 ( & V_4 -> V_16 ) ;
F_54 ( & V_4 -> V_94 ) ;
F_54 ( & V_4 -> V_72 ) ;
F_21 ( V_4 ) ;
F_87 ( & V_4 -> V_55 ) ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_33 ;
F_8 ( V_28 , & V_4 -> V_15 ) ;
F_8 ( V_80 , & V_4 -> V_15 ) ;
V_33 = F_90 ( V_4 ) ;
F_41 ( & V_4 -> V_72 ) ;
F_41 ( & V_4 -> V_94 ) ;
return 0 ;
}
