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
F_11 ( & V_4 -> V_3 -> V_21 ,
L_4 ) ;
break;
default:
F_12 ( & V_4 -> V_3 -> V_21 ,
L_5 , V_12 ) ;
break;
}
}
if ( V_4 -> V_26 == 0 )
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
if ( ! V_4 -> V_32 ) {
if ( ! V_17 ) {
V_4 -> V_26 = 0 ;
goto V_33;
}
F_11 ( & V_4 -> V_3 -> V_21 , L_6 , V_17 ) ;
F_13 ( V_19 , & V_4 -> V_15 ) ;
F_15 ( V_4 -> V_34 , V_35 ) ;
}
V_22:
F_13 ( V_36 , & V_4 -> V_15 ) ;
F_9 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_26 ) {
F_16 ( V_4 ) ;
}
V_33:
F_4 ( & V_4 -> V_10 ) ;
}
static void F_17 ( struct V_8 * V_8 )
{
int V_37 = 0 ;
int V_38 ;
int V_12 = V_8 -> V_12 ;
struct V_1 * V_4 ;
struct V_39 * V_40 ;
V_4 = V_8 -> V_9 ;
V_40 = (struct V_39 * ) V_4 -> V_41 ;
if ( V_12 ) {
switch ( V_12 ) {
case - V_24 :
case - V_20 :
case - V_23 :
return;
case - V_25 :
F_13 ( V_42 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_7 ) ;
goto V_43;
default:
F_12 ( & V_4 -> V_3 -> V_21 ,
L_8 , V_12 ) ;
break;
}
}
if ( V_8 -> V_18 < sizeof( struct V_39 ) ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_9 ,
V_8 -> V_18 ) ;
goto exit;
}
switch ( V_40 -> V_44 ) {
case V_45 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_10 ,
F_18 ( V_40 -> V_46 ) , F_18 ( V_40 -> V_47 ) ) ;
break;
case V_48 :
F_11 ( & V_4 -> V_3 -> V_21 ,
L_11 ,
V_40 -> V_49 ? L_12 : L_13 ) ;
goto exit;
case V_50 :
F_11 ( & V_4 -> V_3 -> V_21 , L_14 ,
V_8 -> V_18 ) ;
goto exit;
default:
F_8 ( V_51 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_15 ,
V_40 -> V_44 ,
F_18 ( V_40 -> V_46 ) ,
F_18 ( V_40 -> V_47 ) ) ;
goto exit;
}
F_2 ( & V_4 -> V_10 ) ;
V_38 = F_19 ( V_19 , & V_4 -> V_15 ) ;
if ( ! V_4 -> V_32 ++ && ! V_38
&& ! F_14 ( V_52 , & V_4 -> V_15 )
&& ! F_14 ( V_53 , & V_4 -> V_15 ) ) {
V_37 = F_15 ( V_4 -> V_34 , V_35 ) ;
F_11 ( & V_4 -> V_3 -> V_21 , L_16 , V_37 ) ;
}
F_4 ( & V_4 -> V_10 ) ;
if ( V_37 < 0 ) {
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( V_37 == - V_54 )
return;
if ( V_37 == - V_55 ) {
V_43:
V_37 = F_20 ( & V_4 -> V_56 ) ;
if ( V_37 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_17 ) ;
}
}
exit:
V_37 = F_15 ( V_8 , V_35 ) ;
if ( V_37 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_18 ,
V_57 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_4 )
{
F_22 ( V_4 -> V_58 ) ;
F_22 ( V_4 -> V_59 ) ;
F_22 ( V_4 -> V_34 ) ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_24 ( V_4 -> V_59 ) ;
F_24 ( V_4 -> V_34 ) ;
F_24 ( V_4 -> V_58 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_41 ) ;
F_7 ( V_4 -> V_30 ) ;
F_7 ( V_4 -> V_60 ) ;
F_7 ( V_4 -> V_61 ) ;
F_7 ( V_4 -> V_29 ) ;
F_23 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_26
( struct V_62 * V_62 , const char T_2 * V_63 , T_3 V_64 , T_4 * V_65 )
{
T_5 * V_66 ;
int V_37 = - V_67 , V_68 , V_69 ;
struct V_1 * V_4 = V_62 -> V_70 ;
struct V_71 * V_72 ;
if ( V_64 > V_4 -> V_27 )
V_64 = V_4 -> V_27 ;
F_27 ( & V_4 -> V_10 ) ;
V_69 = V_4 -> V_11 ;
V_4 -> V_11 = 0 ;
F_28 ( & V_4 -> V_10 ) ;
if ( V_69 < 0 )
return F_29 ( V_69 ) ;
V_66 = F_30 ( V_64 , V_73 ) ;
if ( ! V_66 ) {
V_37 = - V_55 ;
goto V_74;
}
V_68 = F_31 ( V_66 , V_63 , V_64 ) ;
if ( V_68 > 0 ) {
V_37 = - V_75 ;
goto V_76;
}
V_68 = F_32 ( & V_4 -> V_77 ) ;
V_37 = - V_78 ;
if ( V_68 )
goto V_76;
if ( F_14 ( V_52 , & V_4 -> V_15 ) ) {
V_37 = - V_79 ;
goto V_80;
}
V_68 = F_33 ( V_4 -> V_3 ) ;
if ( V_68 < 0 ) {
V_37 = F_29 ( V_68 ) ;
goto V_80;
}
if ( ! ( V_62 -> V_81 & V_82 ) )
V_68 = F_34 ( V_4 -> V_16 , ! F_14 ( V_14 ,
& V_4 -> V_15 ) ) ;
else
if ( F_14 ( V_14 , & V_4 -> V_15 ) )
V_68 = - V_83 ;
if ( F_14 ( V_84 , & V_4 -> V_15 ) )
V_68 = - V_85 ;
if ( V_68 < 0 ) {
V_37 = V_68 ;
goto V_86;
}
V_72 = V_4 -> V_60 ;
F_35 (
V_4 -> V_58 ,
F_36 ( V_4 -> V_3 ) ,
F_37 ( F_36 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_72 ,
V_66 ,
V_64 ,
F_6 ,
V_4
) ;
V_72 -> V_87 = ( V_88 | V_89 |
V_90 ) ;
V_72 -> V_91 = V_92 ;
V_72 -> V_49 = 0 ;
V_72 -> V_46 = V_4 -> V_93 ;
V_72 -> V_47 = F_38 ( V_64 ) ;
F_13 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_13 = V_66 ;
V_37 = F_15 ( V_4 -> V_58 , V_73 ) ;
if ( V_37 < 0 ) {
V_4 -> V_13 = NULL ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_12 ( & V_4 -> V_3 -> V_21 , L_19 , V_37 ) ;
V_37 = F_29 ( V_37 ) ;
goto V_86;
} else {
F_11 ( & V_4 -> V_3 -> V_21 , L_20 ,
F_18 ( V_72 -> V_46 ) ) ;
}
F_39 ( V_4 -> V_3 ) ;
F_40 ( & V_4 -> V_77 ) ;
V_74:
return V_37 < 0 ? V_37 : V_64 ;
V_86:
F_39 ( V_4 -> V_3 ) ;
V_80:
F_40 ( & V_4 -> V_77 ) ;
V_76:
F_7 ( V_66 ) ;
return V_37 ;
}
static int F_16 ( struct V_1 * V_4 )
{
int V_37 = 0 ;
if ( ! V_4 -> V_32 || ! -- V_4 -> V_32 )
goto V_94;
F_13 ( V_19 , & V_4 -> V_15 ) ;
F_28 ( & V_4 -> V_10 ) ;
V_37 = F_15 ( V_4 -> V_34 , V_73 ) ;
F_27 ( & V_4 -> V_10 ) ;
if ( V_37 ) {
F_12 ( & V_4 -> V_3 -> V_21 ,
L_21 , V_37 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
V_4 -> V_32 = 0 ;
}
V_94:
return V_37 ;
}
static T_1 F_41
( struct V_62 * V_62 , char T_2 * V_63 , T_3 V_64 , T_4 * V_65 )
{
int V_37 , V_95 ;
int V_96 = 0 ;
struct V_1 * V_4 = V_62 -> V_70 ;
V_37 = F_32 ( & V_4 -> V_97 ) ;
if ( V_37 < 0 )
return - V_78 ;
V_95 = F_42 ( V_4 -> V_17 ) ;
if ( V_95 == 0 ) {
V_4 -> V_98 = 0 ;
V_99:
if ( F_14 ( V_52 , & V_4 -> V_15 ) ) {
V_37 = - V_79 ;
goto V_100;
}
if ( F_14 ( V_28 , & V_4 -> V_15 ) ) {
F_8 ( V_28 , & V_4 -> V_15 ) ;
V_37 = - V_101 ;
goto V_100;
}
V_96 ++ ;
if ( V_62 -> V_81 & V_82 ) {
if ( ! F_14 ( V_36 , & V_4 -> V_15 ) ) {
V_37 = - V_83 ;
goto V_100;
}
V_37 = 0 ;
} else {
V_37 = F_34 ( V_4 -> V_16 ,
F_14 ( V_36 , & V_4 -> V_15 ) ) ;
}
if ( F_14 ( V_52 , & V_4 -> V_15 ) ) {
V_37 = - V_79 ;
goto V_100;
}
if ( F_14 ( V_84 , & V_4 -> V_15 ) ) {
V_37 = - V_85 ;
goto V_100;
}
F_43 ( F_36 ( V_4 -> V_3 ) ) ;
if ( V_37 < 0 ) {
V_37 = - V_78 ;
goto V_100;
}
F_27 ( & V_4 -> V_10 ) ;
if ( V_4 -> V_26 ) {
V_37 = F_29 ( V_4 -> V_26 ) ;
V_4 -> V_26 = 0 ;
F_28 ( & V_4 -> V_10 ) ;
goto V_100;
}
if ( ! F_14 ( V_36 , & V_4 -> V_15 ) ) {
F_28 ( & V_4 -> V_10 ) ;
goto V_99;
}
if ( ! V_4 -> V_31 ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_22 ) ;
F_8 ( V_36 , & V_4 -> V_15 ) ;
V_37 = F_16 ( V_4 ) ;
F_28 ( & V_4 -> V_10 ) ;
if ( V_37 < 0 )
goto V_100;
goto V_99;
}
V_95 = V_4 -> V_17 ;
F_28 ( & V_4 -> V_10 ) ;
}
if ( V_95 > V_64 )
V_95 = V_64 ;
V_37 = F_44 ( V_63 , V_4 -> V_29 , V_95 ) ;
if ( V_37 > 0 ) {
V_37 = - V_75 ;
goto V_100;
}
F_27 ( & V_4 -> V_10 ) ;
for ( V_96 = 0 ; V_96 < V_4 -> V_17 - V_95 ; V_96 ++ )
V_4 -> V_29 [ V_96 ] = V_4 -> V_29 [ V_96 + V_95 ] ;
V_4 -> V_17 -= V_95 ;
if ( ! V_4 -> V_17 ) {
F_8 ( V_36 , & V_4 -> V_15 ) ;
F_16 ( V_4 ) ;
}
F_28 ( & V_4 -> V_10 ) ;
V_37 = V_95 ;
V_100:
F_40 ( & V_4 -> V_97 ) ;
return V_37 ;
}
static int F_45 ( struct V_62 * V_62 , T_6 V_102 )
{
struct V_1 * V_4 = V_62 -> V_70 ;
F_46 ( V_4 -> V_16 , ! F_14 ( V_14 , & V_4 -> V_15 ) ) ;
if ( V_4 -> V_11 < 0 && ! F_14 ( V_52 , & V_4 -> V_15 ) )
F_12 ( & V_4 -> V_3 -> V_21 , L_23 ,
V_4 -> V_11 ) ;
return F_29 ( V_4 -> V_11 ) ;
}
static unsigned int F_47 ( struct V_62 * V_62 , struct V_103 * V_16 )
{
struct V_1 * V_4 = V_62 -> V_70 ;
unsigned long V_15 ;
unsigned int V_104 = 0 ;
F_48 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_52 , & V_4 -> V_15 ) ) {
V_104 = V_105 | V_106 ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
goto V_107;
}
if ( F_14 ( V_36 , & V_4 -> V_15 ) )
V_104 = V_108 | V_109 ;
if ( V_4 -> V_26 || V_4 -> V_11 )
V_104 |= V_106 ;
if ( ! F_14 ( V_14 , & V_4 -> V_15 ) )
V_104 |= V_110 | V_111 ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
F_50 ( V_62 , & V_4 -> V_16 , V_16 ) ;
V_107:
return V_104 ;
}
static int F_51 ( struct V_112 * V_112 , struct V_62 * V_62 )
{
int V_7 = F_52 ( V_112 ) ;
int V_37 = - V_79 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
F_53 ( & V_113 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ! V_4 )
goto V_94;
V_3 = V_4 -> V_3 ;
if ( F_14 ( V_52 , & V_4 -> V_15 ) )
goto V_94;
V_62 -> V_70 = V_4 ;
V_37 = F_33 ( V_4 -> V_3 ) ;
if ( V_37 < 0 ) {
F_12 ( & V_4 -> V_3 -> V_21 , L_24 , V_37 ) ;
goto V_94;
}
F_53 ( & V_4 -> V_77 ) ;
if ( ! V_4 -> V_64 ++ ) {
V_4 -> V_11 = 0 ;
V_4 -> V_26 = 0 ;
V_37 = F_15 ( V_4 -> V_59 , V_73 ) ;
if ( V_37 < 0 ) {
V_4 -> V_64 -- ;
F_12 ( & V_4 -> V_3 -> V_21 ,
L_25 , V_37 ) ;
V_37 = F_29 ( V_37 ) ;
} else if ( F_14 ( V_114 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_26 ) ;
F_13 ( V_19 , & V_4 -> V_15 ) ;
V_37 = F_15 ( V_4 -> V_34 , V_73 ) ;
}
} else {
V_37 = 0 ;
}
F_40 ( & V_4 -> V_77 ) ;
if ( V_4 -> V_64 == 1 )
V_4 -> V_115 ( V_3 , 1 ) ;
F_39 ( V_4 -> V_3 ) ;
V_94:
F_40 ( & V_113 ) ;
return V_37 ;
}
static int F_54 ( struct V_112 * V_112 , struct V_62 * V_62 )
{
struct V_1 * V_4 = V_62 -> V_70 ;
F_53 ( & V_113 ) ;
F_53 ( & V_4 -> V_77 ) ;
V_4 -> V_64 -- ;
F_40 ( & V_4 -> V_77 ) ;
if ( ! V_4 -> V_64 ) {
if ( ! F_14 ( V_52 , & V_4 -> V_15 ) ) {
F_11 ( & V_4 -> V_3 -> V_21 , L_27 ) ;
F_21 ( V_4 ) ;
F_27 ( & V_4 -> V_10 ) ;
V_4 -> V_32 = 0 ;
F_28 ( & V_4 -> V_10 ) ;
V_4 -> V_115 ( V_4 -> V_3 , 0 ) ;
} else {
F_55 ( V_116 L_28 , V_57 ) ;
F_25 ( V_4 ) ;
}
}
F_40 ( & V_113 ) ;
return 0 ;
}
static long F_56 ( struct V_62 * V_62 , unsigned int V_117 , unsigned long V_118 )
{
struct V_1 * V_4 = V_62 -> V_70 ;
int V_37 = 0 ;
switch ( V_117 ) {
case V_119 :
if ( F_44 ( ( void T_2 * ) V_118 , & V_4 -> V_27 , sizeof( V_4 -> V_27 ) ) )
V_37 = - V_75 ;
break;
default:
V_37 = - V_120 ;
}
return V_37 ;
}
static void F_57 ( struct V_121 * V_122 )
{
struct V_1 * V_4 = F_58 ( V_122 , struct V_1 , V_56 ) ;
unsigned long V_15 ;
int V_37 = 0 ;
int V_38 ;
F_48 ( & V_4 -> V_10 , V_15 ) ;
if ( F_14 ( V_52 , & V_4 -> V_15 ) ) {
F_49 ( & V_4 -> V_10 , V_15 ) ;
} else {
V_38 = F_19 ( V_19 , & V_4 -> V_15 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
if ( ! V_38 )
V_37 = F_15 ( V_4 -> V_34 , V_73 ) ;
if ( V_37 < 0 && V_37 != - V_54 ) {
F_48 ( & V_4 -> V_10 , V_15 ) ;
F_8 ( V_19 , & V_4 -> V_15 ) ;
if ( ! F_14 ( V_52 , & V_4 -> V_15 ) )
F_20 ( & V_4 -> V_56 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
}
}
}
static int F_59 ( struct V_2 * V_3 , struct V_123 * V_124 ,
T_7 V_125 , int (* V_115)( struct V_2 * , int ) ,
bool V_126 )
{
int V_37 = - V_55 ;
struct V_1 * V_4 ;
V_4 = F_60 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_4 )
goto V_94;
F_61 ( & V_4 -> V_127 ) ;
F_62 ( & V_4 -> V_97 ) ;
F_62 ( & V_4 -> V_77 ) ;
F_63 ( & V_4 -> V_10 ) ;
F_64 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = V_125 ;
V_4 -> V_93 = F_38 ( ( T_7 ) V_3 -> V_128 -> V_4 . V_129 ) ;
V_4 -> V_3 = V_3 ;
F_65 ( & V_4 -> V_56 , F_57 ) ;
V_37 = - V_130 ;
if ( ! F_66 ( V_124 ) )
goto V_100;
V_4 -> V_131 = F_67 ( V_124 ) ;
V_4 -> V_60 = F_30 ( sizeof( struct V_71 ) , V_73 ) ;
if ( ! V_4 -> V_60 )
goto V_100;
V_4 -> V_61 = F_30 ( sizeof( struct V_71 ) , V_73 ) ;
if ( ! V_4 -> V_61 )
goto V_100;
V_4 -> V_59 = F_68 ( 0 , V_73 ) ;
if ( ! V_4 -> V_59 )
goto V_100;
V_4 -> V_34 = F_68 ( 0 , V_73 ) ;
if ( ! V_4 -> V_34 )
goto V_100;
V_4 -> V_58 = F_68 ( 0 , V_73 ) ;
if ( ! V_4 -> V_58 )
goto V_100;
V_4 -> V_29 = F_30 ( V_4 -> V_27 , V_73 ) ;
if ( ! V_4 -> V_29 )
goto V_100;
V_4 -> V_41 = F_30 ( V_4 -> V_131 , V_73 ) ;
if ( ! V_4 -> V_41 )
goto V_100;
V_4 -> V_30 = F_30 ( V_4 -> V_27 , V_73 ) ;
if ( ! V_4 -> V_30 )
goto V_100;
F_69 (
V_4 -> V_59 ,
F_36 ( V_3 ) ,
F_70 ( F_36 ( V_3 ) , V_124 -> V_132 ) ,
V_4 -> V_41 ,
V_4 -> V_131 ,
F_17 ,
V_4 ,
V_124 -> V_133
) ;
V_4 -> V_61 -> V_87 = ( V_134 | V_89 | V_90 ) ;
V_4 -> V_61 -> V_91 = V_135 ;
V_4 -> V_61 -> V_49 = 0 ;
V_4 -> V_61 -> V_46 = V_4 -> V_93 ;
V_4 -> V_61 -> V_47 = F_38 ( V_4 -> V_27 ) ;
F_35 (
V_4 -> V_34 ,
F_36 ( V_3 ) ,
F_71 ( F_36 ( V_4 -> V_3 ) , 0 ) ,
( unsigned char * ) V_4 -> V_61 ,
V_4 -> V_30 ,
V_4 -> V_27 ,
F_10 ,
V_4
) ;
V_4 -> V_115 = V_115 ;
if ( V_126 )
F_13 ( V_114 , & V_4 -> V_15 ) ;
F_2 ( & V_5 ) ;
F_72 ( & V_4 -> V_127 , & V_136 ) ;
F_4 ( & V_5 ) ;
V_37 = F_73 ( V_3 , & V_137 ) ;
if ( V_37 < 0 )
goto V_100;
else
F_74 ( & V_3 -> V_21 , L_29 , F_75 ( V_3 -> V_138 ) ) ;
V_94:
return V_37 ;
V_100:
F_2 ( & V_5 ) ;
F_76 ( & V_4 -> V_127 ) ;
F_4 ( & V_5 ) ;
F_25 ( V_4 ) ;
return V_37 ;
}
static int F_77 ( struct V_2 * V_3 , int V_139 )
{
int V_37 = F_33 ( V_3 ) ;
V_3 -> V_140 = V_139 ;
if ( ! V_37 )
F_39 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 , const struct V_141 * V_102 )
{
int V_37 = - V_130 ;
struct V_142 * V_143 ;
struct V_123 * V_124 ;
struct V_144 V_145 ;
T_5 * V_63 = V_3 -> V_146 -> V_147 ;
int V_148 = V_3 -> V_146 -> V_149 ;
T_7 V_150 = V_151 ;
if ( ! V_63 )
goto V_100;
F_79 ( & V_145 , V_3 , V_63 , V_148 ) ;
if ( V_145 . V_152 )
V_150 = F_18 ( V_145 . V_152 -> V_27 ) ;
V_143 = V_3 -> V_128 ;
if ( V_143 -> V_4 . V_153 != 1 )
goto V_100;
V_124 = & V_143 -> V_154 [ 0 ] . V_4 ;
V_37 = F_59 ( V_3 , V_124 , V_150 , & F_77 , false ) ;
V_100:
return V_37 ;
}
struct V_155 * F_80 ( struct V_2 * V_3 ,
struct V_123 * V_124 ,
int V_125 ,
int (* V_115)( struct V_2 * , int ) )
{
int V_37 = - V_130 ;
V_37 = F_59 ( V_3 , V_124 , V_125 , V_115 , true ) ;
if ( V_37 < 0 )
goto V_100;
return & V_156 ;
V_100:
return F_81 ( V_37 ) ;
}
static void F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_83 ( V_3 , & V_137 ) ;
V_4 = F_1 ( V_3 ) ;
F_53 ( & V_113 ) ;
F_48 ( & V_4 -> V_10 , V_15 ) ;
F_13 ( V_52 , & V_4 -> V_15 ) ;
F_13 ( V_36 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
F_49 ( & V_4 -> V_10 , V_15 ) ;
F_84 ( & V_4 -> V_16 ) ;
F_53 ( & V_4 -> V_97 ) ;
F_53 ( & V_4 -> V_77 ) ;
F_21 ( V_4 ) ;
F_85 ( & V_4 -> V_56 ) ;
F_40 ( & V_4 -> V_77 ) ;
F_40 ( & V_4 -> V_97 ) ;
F_2 ( & V_5 ) ;
F_76 ( & V_4 -> V_127 ) ;
F_4 ( & V_5 ) ;
if ( ! V_4 -> V_64 )
F_25 ( V_4 ) ;
else
F_11 ( & V_3 -> V_21 , L_30 , V_4 -> V_64 ) ;
F_40 ( & V_113 ) ;
}
static int F_86 ( struct V_2 * V_3 , T_8 V_157 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_37 = 0 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_31 , V_3 -> V_7 ) ;
if ( ! F_87 ( V_157 ) ) {
F_53 ( & V_4 -> V_97 ) ;
F_53 ( & V_4 -> V_77 ) ;
}
F_27 ( & V_4 -> V_10 ) ;
if ( F_87 ( V_157 ) &&
( F_14 ( V_14 , & V_4 -> V_15 )
|| F_14 ( V_19 , & V_4 -> V_15 ) ) ) {
F_28 ( & V_4 -> V_10 ) ;
V_37 = - V_158 ;
} else {
F_13 ( V_53 , & V_4 -> V_15 ) ;
F_28 ( & V_4 -> V_10 ) ;
F_21 ( V_4 ) ;
F_85 ( & V_4 -> V_56 ) ;
}
if ( ! F_87 ( V_157 ) ) {
F_40 ( & V_4 -> V_77 ) ;
F_40 ( & V_4 -> V_97 ) ;
}
return V_37 ;
}
static int F_88 ( struct V_1 * V_4 )
{
int V_37 = 0 ;
if ( V_4 -> V_64 ) {
V_37 = F_15 ( V_4 -> V_59 , V_159 ) ;
if ( V_37 < 0 )
F_12 ( & V_4 -> V_3 -> V_21 ,
L_32 , V_37 ) ;
}
return V_37 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_37 ;
F_11 ( & V_4 -> V_3 -> V_21 , L_33 , V_3 -> V_7 ) ;
F_8 ( V_53 , & V_4 -> V_15 ) ;
V_37 = F_88 ( V_4 ) ;
return V_37 ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_27 ( & V_4 -> V_10 ) ;
F_13 ( V_84 , & V_4 -> V_15 ) ;
F_13 ( V_36 , & V_4 -> V_15 ) ;
F_8 ( V_14 , & V_4 -> V_15 ) ;
V_4 -> V_26 = - V_160 ;
F_28 ( & V_4 -> V_10 ) ;
F_84 ( & V_4 -> V_16 ) ;
F_53 ( & V_4 -> V_97 ) ;
F_53 ( & V_4 -> V_77 ) ;
F_21 ( V_4 ) ;
F_85 ( & V_4 -> V_56 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_37 ;
F_8 ( V_28 , & V_4 -> V_15 ) ;
F_8 ( V_84 , & V_4 -> V_15 ) ;
V_37 = F_88 ( V_4 ) ;
F_40 ( & V_4 -> V_77 ) ;
F_40 ( & V_4 -> V_97 ) ;
return 0 ;
}
