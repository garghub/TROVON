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
F_7 ( V_4 -> V_33 ) ;
F_7 ( V_4 -> V_28 ) ;
F_7 ( V_4 -> V_53 ) ;
F_7 ( V_4 -> V_54 ) ;
F_7 ( V_4 -> V_26 ) ;
F_20 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_23
( struct V_55 * V_55 , const char T_2 * V_56 , T_3 V_57 , T_4 * V_58 )
{
T_5 * V_59 ;
int V_30 = - V_60 , V_61 , V_62 ;
struct V_1 * V_4 = V_55 -> V_63 ;
struct V_64 * V_65 ;
if ( V_57 > V_4 -> V_66 )
V_57 = V_4 -> V_66 ;
F_24 ( & V_4 -> V_9 ) ;
V_62 = V_4 -> V_10 ;
V_4 -> V_10 = 0 ;
F_25 ( & V_4 -> V_9 ) ;
if ( V_62 < 0 )
return - V_67 ;
V_59 = F_26 ( V_57 , V_68 ) ;
if ( ! V_59 ) {
V_30 = - V_49 ;
goto V_69;
}
V_61 = F_27 ( V_59 , V_56 , V_57 ) ;
if ( V_61 > 0 ) {
F_7 ( V_59 ) ;
V_30 = - V_70 ;
goto V_69;
}
V_61 = F_28 ( & V_4 -> V_71 ) ;
V_30 = - V_72 ;
if ( V_61 ) {
F_7 ( V_59 ) ;
goto V_69;
}
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
F_7 ( V_59 ) ;
V_30 = - V_73 ;
goto V_74;
}
V_61 = F_29 ( V_4 -> V_3 ) ;
if ( V_61 < 0 ) {
F_7 ( V_59 ) ;
V_30 = F_30 ( V_61 ) ;
goto V_74;
}
if ( ! ( V_55 -> V_75 & V_76 ) )
V_61 = F_31 ( V_4 -> V_15 , ! F_15 ( V_13 ,
& V_4 -> V_14 ) ) ;
else
if ( F_15 ( V_13 , & V_4 -> V_14 ) )
V_61 = - V_77 ;
if ( F_15 ( V_78 , & V_4 -> V_14 ) )
V_61 = - V_67 ;
if ( V_61 < 0 ) {
F_7 ( V_59 ) ;
V_30 = V_61 ;
goto V_79;
}
V_65 = V_4 -> V_53 ;
F_32 (
V_4 -> V_51 ,
F_33 ( V_4 -> V_3 ) ,
F_34 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_65 ,
V_59 ,
V_57 ,
F_6 ,
V_4
) ;
V_65 -> V_80 = ( V_81 | V_82 |
V_83 ) ;
V_65 -> V_84 = V_85 ;
V_65 -> V_41 = 0 ;
V_65 -> V_38 = V_4 -> V_86 ;
V_65 -> V_39 = F_35 ( V_57 ) ;
F_13 ( V_13 , & V_4 -> V_14 ) ;
V_4 -> V_12 = V_59 ;
V_30 = F_16 ( V_4 -> V_51 , V_68 ) ;
if ( V_30 < 0 ) {
F_7 ( V_59 ) ;
V_4 -> V_12 = NULL ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
F_12 ( & V_4 -> V_3 -> V_18 , L_17 , V_30 ) ;
V_30 = F_30 ( V_30 ) ;
} else {
F_11 ( & V_4 -> V_3 -> V_18 , L_18 ,
V_65 -> V_38 ) ;
}
V_79:
F_36 ( V_4 -> V_3 ) ;
V_74:
F_37 ( & V_4 -> V_71 ) ;
V_69:
return V_30 < 0 ? V_30 : V_57 ;
}
static T_1 F_38
( struct V_55 * V_55 , char T_2 * V_56 , T_3 V_57 , T_4 * V_58 )
{
int V_30 , V_87 ;
int V_88 = 0 ;
struct V_1 * V_4 = V_55 -> V_63 ;
V_30 = F_28 ( & V_4 -> V_89 ) ;
if ( V_30 < 0 )
return - V_72 ;
V_87 = F_39 ( V_4 -> V_27 ) ;
if ( V_87 == 0 ) {
V_4 -> V_90 = 0 ;
V_91:
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
V_30 = - V_73 ;
goto V_92;
}
V_88 ++ ;
if ( V_55 -> V_75 & V_76 ) {
if ( ! F_15 ( V_29 , & V_4 -> V_14 ) ) {
V_30 = V_87 ? V_87 : - V_77 ;
goto V_92;
}
V_30 = 0 ;
} else {
V_30 = F_31 ( V_4 -> V_15 ,
F_15 ( V_29 , & V_4 -> V_14 ) ) ;
}
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
V_30 = - V_73 ;
goto V_92;
}
if ( F_15 ( V_78 , & V_4 -> V_14 ) ) {
V_30 = - V_67 ;
goto V_92;
}
F_40 ( F_33 ( V_4 -> V_3 ) ) ;
if ( V_30 < 0 ) {
V_30 = - V_72 ;
goto V_92;
}
F_24 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_23 ) {
V_4 -> V_23 = 0 ;
F_25 ( & V_4 -> V_9 ) ;
V_30 = - V_67 ;
goto V_92;
}
if ( ! F_15 ( V_29 , & V_4 -> V_14 ) ) {
F_25 ( & V_4 -> V_9 ) ;
goto V_91;
}
if ( ! V_4 -> V_24 ) {
F_11 ( & V_4 -> V_3 -> V_18 , L_19 , V_47 ) ;
F_8 ( V_29 , & V_4 -> V_14 ) ;
F_25 ( & V_4 -> V_9 ) ;
goto V_91;
}
V_87 = V_4 -> V_27 ;
F_25 ( & V_4 -> V_9 ) ;
}
if ( V_87 > V_57 )
V_87 = V_57 ;
V_30 = F_41 ( V_56 , V_4 -> V_26 , V_87 ) ;
if ( V_30 > 0 ) {
V_30 = - V_70 ;
goto V_92;
}
F_24 ( & V_4 -> V_9 ) ;
for ( V_88 = 0 ; V_88 < V_4 -> V_27 - V_87 ; V_88 ++ )
V_4 -> V_26 [ V_88 ] = V_4 -> V_26 [ V_88 + V_87 ] ;
V_4 -> V_27 -= V_87 ;
if ( ! V_4 -> V_27 )
F_8 ( V_29 , & V_4 -> V_14 ) ;
F_25 ( & V_4 -> V_9 ) ;
V_30 = V_87 ;
V_92:
F_37 ( & V_4 -> V_89 ) ;
return V_30 ;
}
static int F_42 ( struct V_55 * V_55 , T_6 V_93 )
{
struct V_1 * V_4 = V_55 -> V_63 ;
F_43 ( V_4 -> V_15 , ! F_15 ( V_13 , & V_4 -> V_14 ) ) ;
if ( V_4 -> V_10 < 0 && ! F_15 ( V_43 , & V_4 -> V_14 ) )
F_12 ( & V_4 -> V_3 -> V_18 , L_20 ,
V_4 -> V_10 ) ;
return F_30 ( V_4 -> V_10 ) ;
}
static unsigned int F_44 ( struct V_55 * V_55 , struct V_94 * V_15 )
{
struct V_1 * V_4 = V_55 -> V_63 ;
unsigned long V_14 ;
unsigned int V_95 = 0 ;
F_45 ( & V_4 -> V_9 , V_14 ) ;
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
V_95 = V_96 | V_97 ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
goto V_98;
}
if ( F_15 ( V_29 , & V_4 -> V_14 ) )
V_95 = V_99 | V_100 ;
if ( V_4 -> V_23 || V_4 -> V_10 )
V_95 |= V_97 ;
if ( ! F_15 ( V_13 , & V_4 -> V_14 ) )
V_95 |= V_101 | V_102 ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
F_47 ( V_55 , & V_4 -> V_15 , V_15 ) ;
V_98:
return V_95 ;
}
static int F_48 ( struct V_103 * V_103 , struct V_55 * V_55 )
{
int V_6 = F_49 ( V_103 ) ;
int V_30 = - V_73 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_50 ( & V_104 ) ;
V_4 = F_5 ( V_6 ) ;
if ( ! V_4 )
goto V_79;
V_3 = V_4 -> V_3 ;
if ( F_15 ( V_43 , & V_4 -> V_14 ) )
goto V_79;
V_55 -> V_63 = V_4 ;
V_30 = F_29 ( V_4 -> V_3 ) ;
if ( V_30 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_18 , L_21 , V_30 ) ;
goto V_79;
}
F_50 ( & V_4 -> V_71 ) ;
if ( ! V_4 -> V_57 ++ ) {
V_4 -> V_10 = 0 ;
V_4 -> V_23 = 0 ;
V_30 = F_16 ( V_4 -> V_52 , V_68 ) ;
if ( V_30 < 0 ) {
V_4 -> V_57 -- ;
F_12 ( & V_4 -> V_3 -> V_18 ,
L_22 , V_30 ) ;
V_30 = F_30 ( V_30 ) ;
}
} else {
V_30 = 0 ;
}
F_37 ( & V_4 -> V_71 ) ;
if ( V_4 -> V_57 == 1 )
V_4 -> V_105 ( V_3 , 1 ) ;
F_36 ( V_4 -> V_3 ) ;
V_79:
F_37 ( & V_104 ) ;
return V_30 ;
}
static int F_51 ( struct V_103 * V_103 , struct V_55 * V_55 )
{
struct V_1 * V_4 = V_55 -> V_63 ;
F_50 ( & V_104 ) ;
F_50 ( & V_4 -> V_71 ) ;
V_4 -> V_57 -- ;
F_37 ( & V_4 -> V_71 ) ;
if ( ! V_4 -> V_57 ) {
if ( ! F_15 ( V_43 , & V_4 -> V_14 ) ) {
F_11 ( & V_4 -> V_3 -> V_18 , L_23 ) ;
F_18 ( V_4 ) ;
V_4 -> V_105 ( V_4 -> V_3 , 0 ) ;
} else {
F_52 ( V_106 L_24 , V_47 ) ;
F_22 ( V_4 ) ;
}
}
F_37 ( & V_104 ) ;
return 0 ;
}
static void F_53 ( struct V_107 * V_108 )
{
struct V_1 * V_4 = F_54 ( V_108 , struct V_1 , V_50 ) ;
unsigned long V_14 ;
int V_30 ;
F_45 ( & V_4 -> V_9 , V_14 ) ;
if ( F_15 ( V_43 , & V_4 -> V_14 ) ) {
F_46 ( & V_4 -> V_9 , V_14 ) ;
} else {
F_46 ( & V_4 -> V_9 , V_14 ) ;
V_30 = F_16 ( V_4 -> V_45 , V_68 ) ;
if ( V_30 < 0 && V_30 != - V_48 ) {
F_45 ( & V_4 -> V_9 , V_14 ) ;
if ( ! F_15 ( V_43 , & V_4 -> V_14 ) )
F_17 ( & V_4 -> V_50 ) ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
}
}
}
static int F_55 ( struct V_2 * V_3 , struct V_109 * V_110 ,
T_7 V_111 , int (* V_105)( struct V_2 * , int ) )
{
int V_30 = - V_49 ;
struct V_1 * V_4 ;
V_4 = F_56 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_4 )
goto V_79;
F_57 ( & V_4 -> V_112 ) ;
F_58 ( & V_4 -> V_89 ) ;
F_58 ( & V_4 -> V_71 ) ;
F_59 ( & V_4 -> V_9 ) ;
F_60 ( & V_4 -> V_15 ) ;
V_4 -> V_66 = V_111 ;
V_4 -> V_86 = F_35 ( ( T_7 ) V_3 -> V_113 -> V_4 . V_114 ) ;
V_4 -> V_3 = V_3 ;
F_61 ( & V_4 -> V_50 , F_53 ) ;
V_30 = - V_115 ;
if ( ! F_62 ( V_110 ) )
goto V_92;
V_4 -> V_116 = F_63 ( V_110 ) ;
V_4 -> V_53 = F_26 ( sizeof( struct V_64 ) , V_68 ) ;
if ( ! V_4 -> V_53 )
goto V_92;
V_4 -> V_54 = F_26 ( sizeof( struct V_64 ) , V_68 ) ;
if ( ! V_4 -> V_54 )
goto V_92;
V_4 -> V_52 = F_64 ( 0 , V_68 ) ;
if ( ! V_4 -> V_52 )
goto V_92;
V_4 -> V_45 = F_64 ( 0 , V_68 ) ;
if ( ! V_4 -> V_45 )
goto V_92;
V_4 -> V_51 = F_64 ( 0 , V_68 ) ;
if ( ! V_4 -> V_51 )
goto V_92;
V_4 -> V_26 = F_26 ( V_4 -> V_66 , V_68 ) ;
if ( ! V_4 -> V_26 )
goto V_92;
V_4 -> V_33 = F_26 ( V_4 -> V_116 , V_68 ) ;
if ( ! V_4 -> V_33 )
goto V_92;
V_4 -> V_28 = F_26 ( V_4 -> V_66 , V_68 ) ;
if ( ! V_4 -> V_28 )
goto V_92;
F_65 (
V_4 -> V_52 ,
F_33 ( V_3 ) ,
F_66 ( F_33 ( V_3 ) , V_110 -> V_117 ) ,
V_4 -> V_33 ,
V_4 -> V_116 ,
F_14 ,
V_4 ,
V_110 -> V_118
) ;
V_4 -> V_54 -> V_80 = ( V_119 | V_82 | V_83 ) ;
V_4 -> V_54 -> V_84 = V_120 ;
V_4 -> V_54 -> V_41 = 0 ;
V_4 -> V_54 -> V_38 = V_4 -> V_86 ;
V_4 -> V_54 -> V_39 = F_35 ( V_4 -> V_66 ) ;
F_32 (
V_4 -> V_45 ,
F_33 ( V_3 ) ,
F_67 ( F_33 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_54 ,
V_4 -> V_28 ,
V_4 -> V_66 ,
F_10 ,
V_4
) ;
V_4 -> V_105 = V_105 ;
F_2 ( & V_5 ) ;
F_68 ( & V_4 -> V_112 , & V_121 ) ;
F_4 ( & V_5 ) ;
V_30 = F_69 ( V_3 , & V_122 ) ;
if ( V_30 < 0 )
goto V_92;
else
F_70 ( & V_3 -> V_18 , L_25 , F_71 ( V_3 -> V_123 ) ) ;
V_79:
return V_30 ;
V_92:
F_2 ( & V_5 ) ;
F_72 ( & V_4 -> V_112 ) ;
F_4 ( & V_5 ) ;
F_22 ( V_4 ) ;
return V_30 ;
}
static int F_73 ( struct V_2 * V_3 , int V_124 )
{
int V_30 = F_29 ( V_3 ) ;
if ( V_30 < 0 )
goto V_92;
V_3 -> V_125 = V_124 ;
F_36 ( V_3 ) ;
V_92:
return V_30 ;
}
static int F_74 ( struct V_2 * V_3 , const struct V_126 * V_93 )
{
int V_30 = - V_115 ;
struct V_127 * V_128 ;
struct V_109 * V_110 ;
struct V_129 * V_130 ;
T_5 * V_56 = V_3 -> V_131 -> V_132 ;
int V_133 = V_3 -> V_131 -> V_134 ;
T_7 V_135 = V_136 ;
if ( ! V_56 )
goto V_92;
while ( V_133 > 2 ) {
if ( V_56 [ 1 ] != V_137 ) {
F_12 ( & V_3 -> V_18 , L_26 ) ;
goto V_138;
}
switch ( V_56 [ 2 ] ) {
case V_139 :
break;
case V_140 :
V_130 = (struct V_129 * ) V_56 ;
V_135 = F_75 ( V_130 -> V_66 ) ;
F_11 ( & V_3 -> V_18 ,
L_27 , V_135 ) ;
break;
default:
F_12 ( & V_3 -> V_18 ,
L_28 ,
V_56 [ 2 ] , V_56 [ 0 ] ) ;
break;
}
V_138:
V_133 -= V_56 [ 0 ] ;
V_56 += V_56 [ 0 ] ;
}
V_128 = V_3 -> V_113 ;
if ( V_128 -> V_4 . V_141 != 1 )
goto V_92;
V_110 = & V_128 -> V_142 [ 0 ] . V_4 ;
V_30 = F_55 ( V_3 , V_110 , V_135 , & F_73 ) ;
V_92:
return V_30 ;
}
struct V_143 * F_76 ( struct V_2 * V_3 ,
struct V_109 * V_110 ,
int V_111 ,
int (* V_105)( struct V_2 * , int ) )
{
int V_30 = - V_115 ;
V_30 = F_55 ( V_3 , V_110 , V_111 , V_105 ) ;
if ( V_30 < 0 )
goto V_92;
return & V_144 ;
V_92:
return F_77 ( V_30 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_14 ;
F_79 ( V_3 , & V_122 ) ;
V_4 = F_1 ( V_3 ) ;
F_50 ( & V_104 ) ;
F_45 ( & V_4 -> V_9 , V_14 ) ;
F_13 ( V_43 , & V_4 -> V_14 ) ;
F_13 ( V_29 , & V_4 -> V_14 ) ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
F_46 ( & V_4 -> V_9 , V_14 ) ;
F_80 ( & V_4 -> V_15 ) ;
F_50 ( & V_4 -> V_89 ) ;
F_50 ( & V_4 -> V_71 ) ;
F_18 ( V_4 ) ;
F_81 ( & V_4 -> V_50 ) ;
F_37 ( & V_4 -> V_71 ) ;
F_37 ( & V_4 -> V_89 ) ;
F_2 ( & V_5 ) ;
F_72 ( & V_4 -> V_112 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_57 )
F_22 ( V_4 ) ;
else
F_11 ( & V_3 -> V_18 , L_29 , V_47 , V_4 -> V_57 ) ;
F_37 ( & V_104 ) ;
}
static int F_82 ( struct V_2 * V_3 , T_8 V_145 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_30 = 0 ;
F_11 ( & V_4 -> V_3 -> V_18 , L_30 , V_3 -> V_6 ) ;
if ( ! F_83 ( V_145 ) ) {
F_50 ( & V_4 -> V_89 ) ;
F_50 ( & V_4 -> V_71 ) ;
}
F_24 ( & V_4 -> V_9 ) ;
if ( F_83 ( V_145 ) &&
( F_15 ( V_13 , & V_4 -> V_14 )
|| F_15 ( V_16 , & V_4 -> V_14 ) ) ) {
F_25 ( & V_4 -> V_9 ) ;
V_30 = - V_146 ;
} else {
F_13 ( V_44 , & V_4 -> V_14 ) ;
F_25 ( & V_4 -> V_9 ) ;
F_18 ( V_4 ) ;
F_81 ( & V_4 -> V_50 ) ;
}
if ( ! F_83 ( V_145 ) ) {
F_37 ( & V_4 -> V_71 ) ;
F_37 ( & V_4 -> V_89 ) ;
}
return V_30 ;
}
static int F_84 ( struct V_1 * V_4 )
{
int V_30 = 0 ;
if ( V_4 -> V_57 ) {
V_30 = F_16 ( V_4 -> V_52 , V_147 ) ;
if ( V_30 < 0 )
F_12 ( & V_4 -> V_3 -> V_18 ,
L_31 , V_30 ) ;
}
return V_30 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_30 ;
F_11 ( & V_4 -> V_3 -> V_18 , L_32 , V_3 -> V_6 ) ;
F_8 ( V_44 , & V_4 -> V_14 ) ;
V_30 = F_84 ( V_4 ) ;
return V_30 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_24 ( & V_4 -> V_9 ) ;
F_13 ( V_78 , & V_4 -> V_14 ) ;
F_13 ( V_29 , & V_4 -> V_14 ) ;
F_8 ( V_13 , & V_4 -> V_14 ) ;
V_4 -> V_23 = - V_148 ;
F_25 ( & V_4 -> V_9 ) ;
F_80 ( & V_4 -> V_15 ) ;
F_50 ( & V_4 -> V_89 ) ;
F_50 ( & V_4 -> V_71 ) ;
F_18 ( V_4 ) ;
F_81 ( & V_4 -> V_50 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_30 ;
F_8 ( V_78 , & V_4 -> V_14 ) ;
V_30 = F_84 ( V_4 ) ;
F_37 ( & V_4 -> V_71 ) ;
F_37 ( & V_4 -> V_89 ) ;
return 0 ;
}
