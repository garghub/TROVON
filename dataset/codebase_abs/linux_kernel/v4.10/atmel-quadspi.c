static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_6 * V_7 )
{
void T_2 * V_8 ;
V_8 = V_2 -> V_9 ;
if ( V_7 -> V_10 . V_11 . V_12 )
V_8 += V_7 -> V_12 ;
if ( V_7 -> V_13 )
F_6 ( V_8 , V_7 -> V_13 , V_7 -> V_14 ) ;
else
F_7 ( V_7 -> V_15 , V_8 , V_7 -> V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_6 * V_7 ,
T_1 V_16 )
{
T_3 V_17 [ V_18 ] ;
T_4 V_19 = 0 ;
int V_20 ;
if ( V_7 -> V_10 . V_11 . V_21 )
V_17 [ V_19 ++ ] = V_7 -> V_21 ;
for ( V_20 = V_7 -> V_10 . V_11 . V_12 - 1 ; V_20 >= 0 ; -- V_20 )
V_17 [ V_19 ++ ] = ( V_7 -> V_12 >> ( V_20 << 3 ) ) & 0xff ;
if ( V_7 -> V_10 . V_11 . V_22 )
V_17 [ V_19 ++ ] = V_7 -> V_22 ;
if ( V_7 -> V_10 . V_11 . V_23 ) {
int V_24 = V_7 -> V_25 ;
switch ( V_16 & V_26 ) {
case V_27 :
case V_28 :
case V_29 :
V_24 >>= 3 ;
break;
case V_30 :
case V_31 :
V_24 >>= 2 ;
break;
case V_32 :
case V_33 :
V_24 >>= 1 ;
break;
default:
return;
}
for ( V_20 = 0 ; V_20 < V_24 ; ++ V_20 )
V_17 [ V_19 ++ ] = 0 ;
}
F_9 ( V_34 , L_1 , V_35 ,
32 , 1 , V_17 , V_19 , false ) ;
#ifdef F_10
if ( V_7 -> V_10 . V_11 . V_36 && V_7 -> V_13 )
F_9 ( V_34 , L_2 , V_35 ,
32 , 1 , V_7 -> V_13 , V_7 -> V_14 , false ) ;
#endif
}
static int F_11 ( struct V_1 * V_2 ,
const struct V_6 * V_7 ,
T_1 V_37 , T_1 V_38 )
{
T_1 V_39 , V_40 , V_16 , V_41 ;
int V_42 = 0 ;
V_39 = 0 ;
V_40 = 0 ;
V_16 = V_37 | V_38 ;
if ( V_7 -> V_10 . V_11 . V_21 ) {
V_40 |= F_12 ( V_7 -> V_21 ) ;
V_16 |= V_43 ;
}
switch ( V_7 -> V_10 . V_11 . V_12 ) {
case 4 :
V_16 |= V_44 ;
case 3 :
V_39 = ( V_7 -> V_10 . V_11 . V_36 ) ? 0 : V_7 -> V_12 ;
V_16 |= V_45 ;
break;
case 0 :
break;
default:
return - V_46 ;
}
if ( V_7 -> V_10 . V_11 . V_22 && V_7 -> V_47 ) {
T_1 V_48 , V_49 ;
V_40 |= F_13 ( V_7 -> V_22 ) ;
V_16 |= V_50 ;
switch ( V_16 & V_26 ) {
case V_27 :
case V_28 :
case V_29 :
V_48 = 1 ;
break;
case V_30 :
case V_31 :
V_48 = 2 ;
break;
case V_32 :
case V_33 :
V_48 = 4 ;
break;
default:
return - V_46 ;
}
V_49 = V_7 -> V_47 * V_48 ;
switch ( V_49 ) {
case 1 :
V_16 |= V_51 ;
break;
case 2 :
V_16 |= V_52 ;
break;
case 4 :
V_16 |= V_53 ;
break;
case 8 :
V_16 |= V_54 ;
break;
default:
return - V_46 ;
}
}
if ( V_7 -> V_10 . V_11 . V_23 )
V_16 |= F_14 ( V_7 -> V_25 ) ;
if ( V_7 -> V_10 . V_11 . V_36 ) {
V_16 |= V_55 ;
if ( ! V_7 -> V_13 && ! V_7 -> V_15 )
V_16 |= V_56 ;
}
( void ) F_1 ( V_2 , V_57 ) ;
F_8 ( V_2 , V_7 , V_16 ) ;
F_3 ( V_2 , V_58 , V_39 ) ;
F_3 ( V_2 , V_59 , V_40 ) ;
F_3 ( V_2 , V_60 , V_16 ) ;
if ( ! V_7 -> V_10 . V_11 . V_36 )
goto V_61;
( void ) F_1 ( V_2 , V_60 ) ;
if ( ! V_7 -> V_13 && ! V_7 -> V_15 )
return 0 ;
V_42 = F_5 ( V_2 , V_7 ) ;
F_3 ( V_2 , V_62 , V_63 ) ;
if ( V_42 )
return V_42 ;
#if F_15 ( V_64 ) && F_15 ( F_10 )
if ( V_7 -> V_15 )
F_9 ( V_34 , L_3 , V_35 ,
32 , 1 , V_7 -> V_15 , V_7 -> V_14 , false ) ;
#endif
V_61:
V_41 = F_1 ( V_2 , V_57 ) ;
if ( ( V_41 & V_65 ) == V_65 )
return V_42 ;
F_16 ( & V_2 -> V_66 ) ;
V_2 -> V_67 = V_41 & V_65 ;
F_3 ( V_2 , V_68 , V_65 ) ;
if ( ! F_17 ( & V_2 -> V_66 ,
F_18 ( 1000 ) ) )
V_42 = - V_69 ;
F_3 ( V_2 , V_70 , V_65 ) ;
return V_42 ;
}
static int F_19 ( struct V_71 * V_72 , T_3 V_73 ,
T_3 * V_74 , int V_19 )
{
struct V_1 * V_2 = V_72 -> V_75 ;
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_36 = 1 ;
V_7 . V_21 = V_73 ;
V_7 . V_15 = V_74 ;
V_7 . V_14 = V_19 ;
return F_11 ( V_2 , & V_7 , V_76 ,
V_27 ) ;
}
static int F_20 ( struct V_71 * V_72 , T_3 V_73 ,
T_3 * V_74 , int V_19 )
{
struct V_1 * V_2 = V_72 -> V_75 ;
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_36 = ( V_74 != NULL && V_19 > 0 ) ;
V_7 . V_21 = V_73 ;
V_7 . V_13 = V_74 ;
V_7 . V_14 = V_19 ;
return F_11 ( V_2 , & V_7 , V_77 ,
V_27 ) ;
}
static T_5 F_21 ( struct V_71 * V_72 , T_6 V_78 , T_4 V_19 ,
const T_7 * V_79 )
{
struct V_1 * V_2 = V_72 -> V_75 ;
struct V_6 V_7 ;
T_5 V_80 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_12 = V_72 -> V_81 ;
V_7 . V_10 . V_11 . V_36 = 1 ;
V_7 . V_21 = V_72 -> V_82 ;
V_7 . V_12 = ( T_1 ) V_78 ;
V_7 . V_13 = V_79 ;
V_7 . V_14 = V_19 ;
V_80 = F_11 ( V_2 , & V_7 , V_83 ,
V_27 ) ;
return ( V_80 < 0 ) ? V_80 : V_19 ;
}
static int F_22 ( struct V_71 * V_72 , T_6 V_84 )
{
struct V_1 * V_2 = V_72 -> V_75 ;
struct V_6 V_7 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_12 = V_72 -> V_81 ;
V_7 . V_21 = V_72 -> V_85 ;
V_7 . V_12 = ( T_1 ) V_84 ;
return F_11 ( V_2 , & V_7 , V_77 ,
V_27 ) ;
}
static T_5 F_23 ( struct V_71 * V_72 , T_6 V_86 , T_4 V_19 ,
T_7 * V_87 )
{
struct V_1 * V_2 = V_72 -> V_75 ;
struct V_6 V_7 ;
T_3 V_47 , V_25 ;
T_1 V_38 ;
T_5 V_80 ;
switch ( V_72 -> V_88 ) {
case V_89 :
case V_90 :
V_38 = V_27 ;
break;
case V_91 :
V_38 = V_28 ;
break;
case V_92 :
V_38 = V_29 ;
break;
default:
return - V_46 ;
}
if ( V_72 -> V_93 >= 2 ) {
V_47 = 2 ;
V_25 = V_72 -> V_93 - 2 ;
} else {
V_47 = V_72 -> V_93 ;
V_25 = 0 ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_10 . V_11 . V_21 = 1 ;
V_7 . V_10 . V_11 . V_12 = V_72 -> V_81 ;
V_7 . V_10 . V_11 . V_22 = ( V_47 > 0 ) ;
V_7 . V_10 . V_11 . V_23 = ( V_25 > 0 ) ;
V_7 . V_10 . V_11 . V_36 = 1 ;
V_7 . V_21 = V_72 -> V_94 ;
V_7 . V_12 = ( T_1 ) V_86 ;
V_7 . V_22 = 0xff ;
V_7 . V_47 = V_47 ;
V_7 . V_25 = V_25 ;
V_7 . V_15 = V_87 ;
V_7 . V_14 = V_19 ;
V_80 = F_11 ( V_2 , & V_7 , V_95 ,
V_38 ) ;
return ( V_80 < 0 ) ? V_80 : V_19 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned long V_96 ;
T_1 V_97 , V_98 , V_99 ;
F_3 ( V_2 , V_62 , V_100 ) ;
V_97 = F_25 ( 8 ) | V_101 ;
F_3 ( V_2 , V_102 , V_97 ) ;
V_96 = F_26 ( V_2 -> V_103 ) ;
if ( ! V_96 )
return - V_46 ;
V_99 = F_27 ( V_96 , V_2 -> V_104 ) ;
if ( V_99 > 0 )
V_99 -- ;
V_98 = F_28 ( V_99 ) ;
F_3 ( V_2 , V_105 , V_98 ) ;
F_3 ( V_2 , V_62 , V_106 ) ;
return 0 ;
}
static T_8 F_29 ( int V_107 , void * V_108 )
{
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
T_1 V_109 , V_110 , V_67 ;
V_109 = F_1 ( V_2 , V_57 ) ;
V_110 = F_1 ( V_2 , V_111 ) ;
V_67 = V_109 & V_110 ;
if ( ! V_67 )
return V_112 ;
V_2 -> V_67 |= V_67 ;
if ( ( V_2 -> V_67 & V_65 ) == V_65 )
F_30 ( & V_2 -> V_66 ) ;
return V_113 ;
}
static int F_31 ( struct V_114 * V_115 )
{
struct V_116 * V_117 , * V_118 = V_115 -> V_119 . V_120 ;
struct V_1 * V_2 ;
struct V_121 * V_122 ;
struct V_71 * V_72 ;
struct V_123 * V_124 ;
int V_107 , V_42 = 0 ;
if ( F_32 ( V_118 ) != 1 )
return - V_125 ;
V_117 = F_33 ( V_118 , NULL ) ;
V_2 = F_34 ( & V_115 -> V_119 , sizeof( * V_2 ) , V_126 ) ;
if ( ! V_2 ) {
V_42 = - V_127 ;
goto exit;
}
F_35 ( V_115 , V_2 ) ;
F_36 ( & V_2 -> V_66 ) ;
V_2 -> V_115 = V_115 ;
V_122 = F_37 ( V_115 , V_128 , L_4 ) ;
V_2 -> V_4 = F_38 ( & V_115 -> V_119 , V_122 ) ;
if ( F_39 ( V_2 -> V_4 ) ) {
F_40 ( & V_115 -> V_119 , L_5 ) ;
V_42 = F_41 ( V_2 -> V_4 ) ;
goto exit;
}
V_122 = F_37 ( V_115 , V_128 , L_6 ) ;
V_2 -> V_9 = F_38 ( & V_115 -> V_119 , V_122 ) ;
if ( F_39 ( V_2 -> V_9 ) ) {
F_40 ( & V_115 -> V_119 , L_7 ) ;
V_42 = F_41 ( V_2 -> V_9 ) ;
goto exit;
}
V_2 -> V_103 = F_42 ( & V_115 -> V_119 , NULL ) ;
if ( F_39 ( V_2 -> V_103 ) ) {
F_40 ( & V_115 -> V_119 , L_8 ) ;
V_42 = F_41 ( V_2 -> V_103 ) ;
goto exit;
}
V_42 = F_43 ( V_2 -> V_103 ) ;
if ( V_42 ) {
F_40 ( & V_115 -> V_119 , L_9 ) ;
goto exit;
}
V_107 = F_44 ( V_115 , 0 ) ;
if ( V_107 < 0 ) {
F_40 ( & V_115 -> V_119 , L_10 ) ;
V_42 = V_107 ;
goto V_129;
}
V_42 = F_45 ( & V_115 -> V_119 , V_107 , F_29 ,
0 , F_46 ( & V_115 -> V_119 ) , V_2 ) ;
if ( V_42 )
goto V_129;
V_72 = & V_2 -> V_72 ;
V_124 = & V_72 -> V_124 ;
V_72 -> V_119 = & V_115 -> V_119 ;
F_47 ( V_72 , V_117 ) ;
V_72 -> V_75 = V_2 ;
V_124 -> V_75 = V_72 ;
V_72 -> V_130 = F_19 ;
V_72 -> V_131 = F_20 ;
V_72 -> V_132 = F_23 ;
V_72 -> V_133 = F_21 ;
V_72 -> V_134 = F_22 ;
V_42 = F_48 ( V_117 , L_11 , & V_2 -> V_104 ) ;
if ( V_42 < 0 )
goto V_129;
V_42 = F_24 ( V_2 ) ;
if ( V_42 )
goto V_129;
V_42 = F_49 ( V_72 , NULL , V_92 ) ;
if ( V_42 )
goto V_129;
V_42 = F_50 ( V_124 , NULL , 0 ) ;
if ( V_42 )
goto V_129;
F_51 ( V_117 ) ;
return 0 ;
V_129:
F_52 ( V_2 -> V_103 ) ;
exit:
F_51 ( V_117 ) ;
return V_42 ;
}
static int F_53 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_54 ( V_115 ) ;
F_55 ( & V_2 -> V_72 . V_124 ) ;
F_3 ( V_2 , V_62 , V_135 ) ;
F_52 ( V_2 -> V_103 ) ;
return 0 ;
}
