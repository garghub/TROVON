static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_2 ( V_6 , F_3 ( V_6 , 0 ) , V_8 ,
V_9 , V_4 , V_3 , NULL , 0 ,
F_4 ( V_10 ) ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 = F_2 ( V_6 , F_6 ( V_6 , 0 ) , V_12 ,
V_13 , 0 , V_3 , V_4 , 2 ,
F_4 ( V_10 ) ) ;
return V_11 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
T_1 V_14 ;
V_11 = F_5 ( V_2 , V_15 , & V_14 ) ;
if ( F_8 ( V_11 != 2 ) ) {
V_11 = - V_16 ;
goto error;
}
V_14 |= ( V_17 | V_18 ) ;
V_14 &= ~ V_19 ;
V_14 &= ~ V_20 ;
V_11 = F_1 ( V_2 , V_15 , V_14 ) ;
if ( F_8 ( V_11 ) )
goto error;
V_14 &= ~ V_17 ;
V_11 = F_1 ( V_2 , V_15 , V_14 ) ;
if ( F_8 ( V_11 ) )
goto error;
V_14 &= ~ V_18 ;
V_11 = F_1 ( V_2 , V_15 , V_14 ) ;
if ( F_8 ( V_11 ) )
goto error;
V_11 = 0 ;
error:
return V_11 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
F_10 ( L_1 ) ;
return 1 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
F_10 ( L_1 ) ;
return 1 ;
}
static inline int F_12 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
T_1 V_14 ;
const char * V_21 ;
V_21 = L_2 ;
V_11 = F_5 ( V_2 , V_22 , & V_14 ) ;
if( F_8 ( V_11 != 2 ) )
goto error;
V_14 |= V_23 ;
V_11 = F_1 ( V_2 , V_22 , V_14 ) ;
if( F_8 ( V_11 ) )
goto error;
V_14 = 0 ;
V_11 = F_1 ( V_2 , V_24 , V_14 ) ;
if( F_8 ( V_11 ) )
goto error;
V_11 = F_5 ( V_2 , V_22 , & V_14 ) ;
if( F_8 ( V_11 != 2 ) )
goto error;
V_14 &= ~ V_25 ;
if( V_2 -> V_26 )
V_14 |= V_27 ;
else
V_14 &= ~ V_27 ;
V_14 &= ~ ( V_28 | V_29 ) ;
V_14 &= ~ V_30 ;
V_14 |= V_31 ;
V_2 -> V_32 = 9600 ;
V_2 -> V_33 = 0 ;
V_14 &= ~ V_34 ;
V_14 |= V_35 | V_36 ;
V_11 = F_1 ( V_2 , V_22 , V_14 ) ;
if( F_8 ( V_11 ) )
goto error;
V_21 = L_3 ;
switch ( V_2 -> V_37 ) {
case V_38 :
V_11 = F_7 ( V_2 ) ;
break;
case V_39 :
V_11 = F_11 ( V_2 ) ;
break;
case V_40 :
V_11 = F_9 ( V_2 ) ;
break;
default:
F_10 ( L_4 ,
V_2 -> V_37 ) ;
V_11 = 1 ;
}
if ( F_8 ( V_11 ) )
goto error;
if ( V_2 -> V_37 != V_39 ) {
V_11 = F_5 ( V_2 , V_15 , & V_14 ) ;
if ( F_8 ( V_11 != 2 ) )
goto error;
if ( V_2 -> V_41 )
V_14 |= V_42 ;
else
V_14 &= ~ V_42 ;
V_11 = F_1 ( V_2 , V_15 , V_14 ) ;
if ( F_8 ( V_11 ) )
goto error;
}
V_21 = L_5 ;
V_11 = F_5 ( V_2 , V_22 , & V_14 ) ;
if ( F_8 ( V_11 != 2 ) )
goto error;
V_14 &= ~ V_43 ;
V_11 = F_1 ( V_2 , V_22 , V_14 ) ;
if ( F_8 ( V_11 ) )
goto error;
else
return V_11 ;
error:
F_13 ( L_6 , V_21 ) ;
return V_11 ;
}
static inline int F_14 ( struct V_44 * V_45 , T_2 * V_46 )
{
int V_47 ;
V_47 = F_15 ( V_45 , V_46 + 2 , 4094 ) ;
V_47 += 2 ;
V_46 [ 0 ] = V_47 & 0xff ;
V_46 [ 1 ] = ( V_47 >> 8 ) & 0xff ;
return V_47 ;
}
static unsigned F_16 ( const struct V_44 * V_45 , T_2 * V_46 )
{
unsigned int V_48 = 0 ;
T_3 V_49 = ~ ( F_17 ( ~ 0 , V_45 -> V_50 , V_45 -> V_48 ) ) ;
V_48 = V_45 -> V_48 + 6 ;
V_46 [ 0 ] = V_48 & 0xff ;
V_46 [ 1 ] = ( V_48 >> 8 ) & 0xff ;
F_18 ( V_45 , V_46 + 2 , V_45 -> V_48 ) ;
V_46 [ V_48 - 4 ] = V_49 & 0xff ;
V_46 [ V_48 - 3 ] = ( V_49 >> 8 ) & 0xff ;
V_46 [ V_48 - 2 ] = ( V_49 >> 16 ) & 0xff ;
V_46 [ V_48 - 1 ] = ( V_49 >> 24 ) & 0xff ;
return V_48 ;
}
static unsigned F_19 ( const struct V_44 * V_45 , T_2 * V_46 )
{
T_1 V_49 = 0 ;
int V_48 = V_45 -> V_48 + 4 ;
V_49 = ~ ( F_20 ( ~ V_49 , V_45 -> V_50 , V_45 -> V_48 ) ) ;
V_46 [ 0 ] = V_48 & 0xff ;
V_46 [ 1 ] = ( V_48 >> 8 ) & 0xff ;
F_18 ( V_45 , V_46 + 2 , V_45 -> V_48 ) ;
V_46 [ V_48 - 2 ] = V_49 & 0xff ;
V_46 [ V_48 - 1 ] = ( V_49 >> 8 ) & 0xff ;
return V_48 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 * V_46 , int V_48 )
{
T_1 V_49 ;
int V_51 ;
struct V_44 * V_45 ;
V_51 = V_48 - 2 ;
if( F_8 ( V_51 <= 0 ) ) {
F_13 ( L_7 ,
V_2 -> V_52 -> V_53 , V_51 ) ;
++ V_2 -> V_52 -> V_54 . V_55 ;
++ V_2 -> V_52 -> V_54 . V_56 ;
return;
}
V_49 = 0 ;
V_49 = F_20 ( ~ V_49 , V_46 , V_48 ) ;
if( V_49 != V_57 ) {
F_13 ( L_8 ,
V_49 , V_51 ) ;
V_2 -> V_52 -> V_54 . V_55 ++ ;
V_2 -> V_52 -> V_54 . V_58 ++ ;
return;
}
V_45 = F_22 ( V_51 + 1 ) ;
if( F_8 ( ! V_45 ) ) {
++ V_2 -> V_52 -> V_54 . V_59 ;
return;
}
F_23 ( V_45 , 1 ) ;
F_24 ( V_45 , V_46 , V_51 ) ;
F_25 ( V_45 , V_51 ) ;
F_26 ( V_45 ) ;
V_45 -> V_60 = F_27 ( V_61 ) ;
V_45 -> V_6 = V_2 -> V_52 ;
F_28 ( V_45 ) ;
V_2 -> V_52 -> V_54 . V_62 ++ ;
V_2 -> V_52 -> V_54 . V_63 += V_51 ;
}
static void F_29 ( struct V_1 * V_2 , T_2 * V_46 , int V_48 )
{
T_3 V_49 ;
int V_51 ;
struct V_44 * V_45 ;
V_51 = V_48 - 4 ;
if( F_8 ( V_51 <= 0 ) ) {
F_13 ( L_7 ,
V_2 -> V_52 -> V_53 , V_51 ) ;
++ V_2 -> V_52 -> V_54 . V_55 ;
++ V_2 -> V_52 -> V_54 . V_56 ;
return;
}
V_49 = ~ ( F_17 ( ~ 0 , V_46 , V_51 ) ) ;
if( V_49 != F_30 ( V_46 + V_51 ) ) {
F_13 ( L_8 ,
V_49 , V_51 ) ;
V_2 -> V_52 -> V_54 . V_55 ++ ;
V_2 -> V_52 -> V_54 . V_58 ++ ;
return;
}
V_45 = F_22 ( V_51 + 1 ) ;
if( F_8 ( ! V_45 ) ) {
++ V_2 -> V_52 -> V_54 . V_59 ;
return;
}
F_23 ( V_45 , 1 ) ;
F_24 ( V_45 , V_46 , V_51 ) ;
F_25 ( V_45 , V_51 ) ;
F_26 ( V_45 ) ;
V_45 -> V_60 = F_27 ( V_61 ) ;
V_45 -> V_6 = V_2 -> V_52 ;
F_28 ( V_45 ) ;
V_2 -> V_52 -> V_54 . V_62 ++ ;
V_2 -> V_52 -> V_54 . V_63 += V_51 ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
V_2 -> V_64 = NULL ;
V_2 -> V_65 = F_32 ( 0 , V_66 ) ;
if ( ! V_2 -> V_65 )
return 0 ;
V_2 -> V_64 = F_32 ( 0 , V_66 ) ;
if ( ! V_2 -> V_64 ) {
F_33 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
return 0 ;
}
return 1 ;
}
static inline int F_34 ( struct V_1 * V_2 )
{
V_2 -> V_67 . V_68 = FALSE ;
V_2 -> V_67 . V_69 = V_70 ;
F_35 ( V_2 -> V_64 , V_2 -> V_7 ,
F_36 ( V_2 -> V_7 , V_2 -> V_71 ) ,
V_2 -> V_72 , 4096 , V_73 , V_2 ) ;
V_2 -> V_64 -> V_74 = 0 ;
return F_37 ( V_2 -> V_64 , V_66 ) ;
}
static inline int F_38 ( struct V_1 * V_2 ,
struct V_75 * V_76 , int V_77 )
{
int V_78 ;
int V_11 = 0 ;
if ( ! V_76 )
return V_11 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
if ( V_76 [ V_78 ] . V_79 . V_80 & V_81 )
V_2 -> V_71 = V_76 [ V_78 ] . V_79 . V_80 ;
else
V_2 -> V_82 = V_76 [ V_78 ] . V_79 . V_80 ;
if ( ( V_2 -> V_71 != 0 ) && ( V_2 -> V_82 != 0 ) ) {
V_11 = 1 ;
break;
}
}
return V_11 ;
}
static void F_39 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_40 ( V_84 , struct V_1 , V_84 ) ;
struct V_85 * V_52 = V_2 -> V_52 ;
F_41 ( V_2 ) ;
F_42 ( V_52 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
int V_86 = 0 ;
int V_87 = 0 ;
T_1 V_88 ;
T_1 V_14 ;
V_88 = V_89 [ ( V_2 -> V_33 >> 8 ) & 0x0f ] ;
do {
F_5 ( V_2 , V_90 , & V_14 ) ;
} while( V_87 ++ < 100 && ( V_14 & V_91 ) );
if ( V_87 > 100 ) {
F_13 ( L_9 ) ;
V_11 = - V_16 ;
goto error;
}
F_5 ( V_2 , V_22 , & V_14 ) ;
if ( V_2 -> V_33 <= 115200 ) {
V_14 &= ~ V_25 ;
if ( ( V_86 = ( V_2 -> V_32 > 115200 ) ) )
F_1 ( V_2 , V_24 , 0 ) ;
} else if ( V_2 -> V_33 <= 1152000 ) {
V_14 &= ~ V_25 ;
if ( ( V_86 = ! ( V_2 -> V_32 == 576000 || V_2 -> V_32 == 1152000 ) ) )
F_1 ( V_2 , V_24 , 5 ) ;
} else {
V_14 |= V_25 ;
if ( ( V_86 = ( V_2 -> V_32 != 4000000 ) ) )
F_1 ( V_2 , V_24 , 5 ) ;
}
V_14 &= ~ V_30 ;
V_14 |= V_88 ;
V_11 = F_1 ( V_2 , V_22 , V_14 ) ;
if ( F_8 ( V_11 ) )
goto error;
if ( V_86 )
switch ( V_2 -> V_37 ) {
case V_38 :
V_11 = F_7 ( V_2 ) ;
break;
case V_39 :
V_11 = F_11 ( V_2 ) ;
break;
case V_40 :
V_11 = F_9 ( V_2 ) ;
break;
default:
V_11 = 1 ;
F_10 ( L_4 ,
V_2 -> V_37 ) ;
}
if ( F_8 ( V_11 ) )
goto error;
F_5 ( V_2 , V_22 , & V_14 ) ;
V_14 &= ~ V_43 ;
V_11 = F_1 ( V_2 , V_22 , V_14 ) ;
V_2 -> V_32 = V_2 -> V_33 ;
error:
V_2 -> V_33 = 0 ;
return V_11 ;
}
static int F_43 ( struct V_85 * V_52 , struct V_92 * V_93 , int V_94 )
{
int V_11 = 0 ;
switch ( V_94 ) {
default:
V_11 = - V_95 ;
}
return V_11 ;
}
static int F_44 ( struct V_85 * V_52 )
{
int V_11 = 0 ;
struct V_1 * V_2 = F_45 ( V_52 ) ;
F_46 ( V_52 ) ;
F_47 ( V_2 -> V_67 . V_45 ) ;
F_48 ( V_2 -> V_64 ) ;
F_33 ( V_2 -> V_64 ) ;
F_48 ( V_2 -> V_65 ) ;
F_33 ( V_2 -> V_65 ) ;
if ( V_2 -> V_96 )
F_49 ( V_2 -> V_96 ) ;
V_2 -> V_96 = NULL ;
return V_11 ;
}
static int F_50 ( struct V_85 * V_52 )
{
struct V_1 * V_2 = F_45 ( V_52 ) ;
char V_97 [ 16 ] ;
int V_11 = 0 ;
V_11 = F_51 ( V_2 -> V_7 ,
F_52 ( V_2 -> V_7 , V_2 -> V_71 ) ) ;
if ( V_11 )
goto V_98;
V_11 = F_51 ( V_2 -> V_7 ,
F_36 ( V_2 -> V_7 , V_2 -> V_82 ) ) ;
if ( V_11 )
goto V_98;
V_11 = F_12 ( V_2 ) ;
if ( V_11 )
goto V_98;
V_11 = - V_99 ;
V_2 -> V_100 = 0 ;
V_2 -> V_67 . V_101 = V_102 ;
V_2 -> V_67 . V_45 = F_22 ( V_102 ) ;
if ( ! V_2 -> V_67 . V_45 )
goto V_98;
F_23 ( V_2 -> V_67 . V_45 , 1 ) ;
V_2 -> V_67 . V_103 = V_2 -> V_67 . V_45 -> V_50 ;
sprintf ( V_97 , L_10 , V_2 -> V_7 -> V_104 ) ;
V_2 -> V_96 = F_53 ( V_52 , & V_2 -> V_105 , V_97 ) ;
if ( ! V_2 -> V_96 ) {
F_13 ( L_11 ) ;
goto V_106;
}
if ( ! F_31 ( V_2 ) )
goto V_107;
V_11 = F_34 ( V_2 ) ;
if ( V_11 )
goto V_108;
F_54 ( V_52 ) ;
return 0 ;
V_108:
F_33 ( V_2 -> V_64 ) ;
F_33 ( V_2 -> V_65 ) ;
V_107:
F_49 ( V_2 -> V_96 ) ;
V_106:
F_47 ( V_2 -> V_67 . V_45 ) ;
V_98:
return V_11 ;
}
static void V_73 ( struct V_109 * V_109 )
{
T_2 * V_110 ;
struct V_1 * V_2 = V_109 -> V_111 ;
int V_78 ;
int V_11 ;
if ( ! F_55 ( V_2 -> V_52 ) )
return;
if ( V_109 -> V_74 )
return;
if ( V_109 -> V_112 > 0 ) {
V_110 = V_109 -> V_113 ;
if( V_2 -> V_32 < 576000 ) {
F_56 ( V_2 -> V_52 , & V_2 -> V_52 -> V_54 ,
& V_2 -> V_67 , 0xc0 ) ;
for ( V_78 = 0 ; V_78 < V_109 -> V_112 ; V_78 ++ )
F_56 ( V_2 -> V_52 , & V_2 -> V_52 -> V_54 ,
& V_2 -> V_67 , V_110 [ V_78 ] ) ;
F_56 ( V_2 -> V_52 , & V_2 -> V_52 -> V_54 ,
& V_2 -> V_67 , 0xc1 ) ;
}
else if( V_2 -> V_32 == 576000 || V_2 -> V_32 == 1152000 ) {
F_21 ( V_2 , V_109 -> V_113 ,
V_109 -> V_112 ) ;
}
else {
F_29 ( V_2 , V_109 -> V_113 ,
V_109 -> V_112 ) ;
}
}
V_11 = F_37 ( V_109 , V_114 ) ;
}
static void F_57 ( struct V_109 * V_109 )
{
struct V_1 * V_2 = V_109 -> V_111 ;
struct V_85 * V_115 = V_2 -> V_52 ;
if ( F_8 ( V_2 -> V_33 ) )
F_58 ( & V_2 -> V_84 ) ;
else
F_42 ( V_115 ) ;
}
static T_4 F_59 ( struct V_44 * V_45 ,
struct V_85 * V_115 )
{
unsigned long V_116 ;
struct V_1 * V_2 ;
int V_47 ;
int V_11 = 0 ;
F_46 ( V_115 ) ;
V_2 = F_45 ( V_115 ) ;
F_60 ( & V_2 -> V_117 , V_116 ) ;
V_2 -> V_33 = F_61 ( V_45 ) ;
if ( F_62 ( V_2 -> V_33 == V_2 -> V_32 ) )
V_2 -> V_33 = 0 ;
if( V_2 -> V_32 < 576000 ) {
V_47 = F_14 ( V_45 , V_2 -> V_118 ) ;
}
else if( V_2 -> V_32 == 576000 || V_2 -> V_32 == 1152000 ) {
V_47 = F_19 ( V_45 , V_2 -> V_118 ) ;
}
else {
V_47 = F_16 ( V_45 , V_2 -> V_118 ) ;
}
F_35 ( V_2 -> V_65 , V_2 -> V_7 ,
F_52 ( V_2 -> V_7 , V_2 -> V_82 ) ,
V_2 -> V_118 , V_47 , F_57 , V_2 ) ;
if ( ( V_11 = F_37 ( V_2 -> V_65 , V_114 ) ) ) {
F_13 ( L_12 , V_11 ) ;
switch ( V_11 ) {
case - V_119 :
case - V_120 :
break;
default:
V_2 -> V_52 -> V_54 . V_121 ++ ;
F_54 ( V_115 ) ;
}
} else {
V_2 -> V_52 -> V_54 . V_122 ++ ;
V_2 -> V_52 -> V_54 . V_123 += V_45 -> V_48 ;
}
F_63 ( V_45 ) ;
F_64 ( & V_2 -> V_117 , V_116 ) ;
return V_124 ;
}
static int F_65 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
struct V_5 * V_129 = F_66 ( V_126 ) ;
struct V_85 * V_115 = NULL ;
struct V_1 * V_2 ;
int V_11 = - V_99 ;
V_115 = F_67 ( sizeof( * V_2 ) ) ;
if ( ! V_115 )
goto V_98;
F_68 ( L_13 , V_129 -> V_104 ) ;
F_69 ( V_115 , & V_126 -> V_6 ) ;
V_11 = F_70 ( V_129 ) ;
if ( V_11 != 0 ) {
F_13 ( L_14 ) ;
goto V_106;
}
V_2 = F_45 ( V_115 ) ;
V_2 -> V_7 = V_129 ;
V_2 -> V_52 = V_115 ;
F_71 ( & V_2 -> V_117 ) ;
F_72 ( & V_2 -> V_105 ) ;
V_2 -> V_105 . V_130 . V_131 &=
V_132 | V_133 | V_134 | V_135 | V_136 | V_137
| V_138 | V_139 | ( V_140 << 8 ) ;
V_2 -> V_105 . V_141 . V_131 &= V_142 ;
F_73 ( & V_2 -> V_105 ) ;
F_74 ( & V_2 -> V_84 , F_39 ) ;
V_115 -> V_143 = & V_144 ;
if ( ! V_126 -> V_145 ) {
V_11 = - V_99 ;
goto V_106;
}
V_11 = F_38 ( V_2 , V_126 -> V_145 -> V_146 ,
V_126 -> V_145 -> V_79 . V_147 ) ;
if ( ! V_11 ) {
V_11 = - V_119 ;
goto V_106;
}
V_11 = F_75 ( V_115 ) ;
if ( V_11 != 0 )
goto V_106;
F_68 ( L_15 ,
V_115 -> V_53 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_41 = V_41 ;
F_76 ( V_126 , V_2 ) ;
return 0 ;
V_106:
F_77 ( V_115 ) ;
V_98:
return V_11 ;
}
static void F_78 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_79 ( V_126 ) ;
if ( ! V_2 )
return;
F_80 ( & V_2 -> V_84 ) ;
F_81 ( V_2 -> V_52 ) ;
F_77 ( V_2 -> V_52 ) ;
F_76 ( V_126 , NULL ) ;
F_68 ( L_16 ) ;
}
