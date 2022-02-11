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
void * V_11 ;
int V_12 ;
V_11 = F_6 ( sizeof( T_1 ) , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
V_12 = F_2 ( V_6 , F_7 ( V_6 , 0 ) , V_15 ,
V_16 , 0 , V_3 , V_11 , 2 ,
F_4 ( V_10 ) ) ;
memcpy ( V_4 , V_11 , sizeof( T_1 ) ) ;
F_8 ( V_11 ) ;
return V_12 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
T_1 V_17 ;
V_12 = F_5 ( V_2 , V_18 , & V_17 ) ;
if ( F_10 ( V_12 != 2 ) ) {
V_12 = - V_19 ;
goto error;
}
V_17 |= ( V_20 | V_21 ) ;
V_17 &= ~ V_22 ;
V_17 &= ~ V_23 ;
V_12 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( F_10 ( V_12 ) )
goto error;
V_17 &= ~ V_20 ;
V_12 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( F_10 ( V_12 ) )
goto error;
V_17 &= ~ V_21 ;
V_12 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( F_10 ( V_12 ) )
goto error;
V_12 = 0 ;
error:
return V_12 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
F_12 ( L_1 ) ;
return 1 ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
F_12 ( L_1 ) ;
return 1 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
T_1 V_17 ;
const char * V_24 ;
V_24 = L_2 ;
V_12 = F_5 ( V_2 , V_25 , & V_17 ) ;
if( F_10 ( V_12 != 2 ) )
goto error;
V_17 |= V_26 ;
V_12 = F_1 ( V_2 , V_25 , V_17 ) ;
if( F_10 ( V_12 ) )
goto error;
V_17 = 0 ;
V_12 = F_1 ( V_2 , V_27 , V_17 ) ;
if( F_10 ( V_12 ) )
goto error;
V_12 = F_5 ( V_2 , V_25 , & V_17 ) ;
if( F_10 ( V_12 != 2 ) )
goto error;
V_17 &= ~ V_28 ;
if( V_2 -> V_29 )
V_17 |= V_30 ;
else
V_17 &= ~ V_30 ;
V_17 &= ~ ( V_31 | V_32 ) ;
V_17 &= ~ V_33 ;
V_17 |= V_34 ;
V_2 -> V_35 = 9600 ;
V_2 -> V_36 = 0 ;
V_17 &= ~ V_37 ;
V_17 |= V_38 | V_39 ;
V_12 = F_1 ( V_2 , V_25 , V_17 ) ;
if( F_10 ( V_12 ) )
goto error;
V_24 = L_3 ;
switch ( V_2 -> V_40 ) {
case V_41 :
V_12 = F_9 ( V_2 ) ;
break;
case V_42 :
V_12 = F_13 ( V_2 ) ;
break;
case V_43 :
V_12 = F_11 ( V_2 ) ;
break;
default:
F_12 ( L_4 ,
V_2 -> V_40 ) ;
V_12 = 1 ;
}
if ( F_10 ( V_12 ) )
goto error;
if ( V_2 -> V_40 != V_42 ) {
V_12 = F_5 ( V_2 , V_18 , & V_17 ) ;
if ( F_10 ( V_12 != 2 ) )
goto error;
if ( V_2 -> V_44 )
V_17 |= V_45 ;
else
V_17 &= ~ V_45 ;
V_12 = F_1 ( V_2 , V_18 , V_17 ) ;
if ( F_10 ( V_12 ) )
goto error;
}
V_24 = L_5 ;
V_12 = F_5 ( V_2 , V_25 , & V_17 ) ;
if ( F_10 ( V_12 != 2 ) )
goto error;
V_17 &= ~ V_46 ;
V_12 = F_1 ( V_2 , V_25 , V_17 ) ;
if ( F_10 ( V_12 ) )
goto error;
else
return V_12 ;
error:
F_15 ( L_6 , V_24 ) ;
return V_12 ;
}
static inline int F_16 ( struct V_47 * V_48 , T_2 * V_49 )
{
int V_50 ;
V_50 = F_17 ( V_48 , V_49 + 2 , 4094 ) ;
V_50 += 2 ;
V_49 [ 0 ] = V_50 & 0xff ;
V_49 [ 1 ] = ( V_50 >> 8 ) & 0xff ;
return V_50 ;
}
static unsigned F_18 ( const struct V_47 * V_48 , T_2 * V_49 )
{
unsigned int V_51 = 0 ;
T_3 V_52 = ~ ( F_19 ( ~ 0 , V_48 -> V_53 , V_48 -> V_51 ) ) ;
V_51 = V_48 -> V_51 + 6 ;
V_49 [ 0 ] = V_51 & 0xff ;
V_49 [ 1 ] = ( V_51 >> 8 ) & 0xff ;
F_20 ( V_48 , V_49 + 2 , V_48 -> V_51 ) ;
V_49 [ V_51 - 4 ] = V_52 & 0xff ;
V_49 [ V_51 - 3 ] = ( V_52 >> 8 ) & 0xff ;
V_49 [ V_51 - 2 ] = ( V_52 >> 16 ) & 0xff ;
V_49 [ V_51 - 1 ] = ( V_52 >> 24 ) & 0xff ;
return V_51 ;
}
static unsigned F_21 ( const struct V_47 * V_48 , T_2 * V_49 )
{
T_1 V_52 = 0 ;
int V_51 = V_48 -> V_51 + 4 ;
V_52 = ~ ( F_22 ( ~ V_52 , V_48 -> V_53 , V_48 -> V_51 ) ) ;
V_49 [ 0 ] = V_51 & 0xff ;
V_49 [ 1 ] = ( V_51 >> 8 ) & 0xff ;
F_20 ( V_48 , V_49 + 2 , V_48 -> V_51 ) ;
V_49 [ V_51 - 2 ] = V_52 & 0xff ;
V_49 [ V_51 - 1 ] = ( V_52 >> 8 ) & 0xff ;
return V_51 ;
}
static void F_23 ( struct V_1 * V_2 , T_2 * V_49 , int V_51 )
{
T_1 V_52 ;
int V_54 ;
struct V_47 * V_48 ;
V_54 = V_51 - 2 ;
if( F_10 ( V_54 <= 0 ) ) {
F_15 ( L_7 ,
V_2 -> V_55 -> V_56 , V_54 ) ;
++ V_2 -> V_55 -> V_57 . V_58 ;
++ V_2 -> V_55 -> V_57 . V_59 ;
return;
}
V_52 = 0 ;
V_52 = F_22 ( ~ V_52 , V_49 , V_51 ) ;
if( V_52 != V_60 ) {
F_15 ( L_8 ,
V_52 , V_54 ) ;
V_2 -> V_55 -> V_57 . V_58 ++ ;
V_2 -> V_55 -> V_57 . V_61 ++ ;
return;
}
V_48 = F_24 ( V_54 + 1 ) ;
if( F_10 ( ! V_48 ) ) {
++ V_2 -> V_55 -> V_57 . V_62 ;
return;
}
F_25 ( V_48 , 1 ) ;
F_26 ( V_48 , V_49 , V_54 ) ;
F_27 ( V_48 , V_54 ) ;
F_28 ( V_48 ) ;
V_48 -> V_63 = F_29 ( V_64 ) ;
V_48 -> V_6 = V_2 -> V_55 ;
F_30 ( V_48 ) ;
V_2 -> V_55 -> V_57 . V_65 ++ ;
V_2 -> V_55 -> V_57 . V_66 += V_54 ;
}
static void F_31 ( struct V_1 * V_2 , T_2 * V_49 , int V_51 )
{
T_3 V_52 ;
int V_54 ;
struct V_47 * V_48 ;
V_54 = V_51 - 4 ;
if( F_10 ( V_54 <= 0 ) ) {
F_15 ( L_7 ,
V_2 -> V_55 -> V_56 , V_54 ) ;
++ V_2 -> V_55 -> V_57 . V_58 ;
++ V_2 -> V_55 -> V_57 . V_59 ;
return;
}
V_52 = ~ ( F_19 ( ~ 0 , V_49 , V_54 ) ) ;
if( V_52 != F_32 ( V_49 + V_54 ) ) {
F_15 ( L_8 ,
V_52 , V_54 ) ;
V_2 -> V_55 -> V_57 . V_58 ++ ;
V_2 -> V_55 -> V_57 . V_61 ++ ;
return;
}
V_48 = F_24 ( V_54 + 1 ) ;
if( F_10 ( ! V_48 ) ) {
++ V_2 -> V_55 -> V_57 . V_62 ;
return;
}
F_25 ( V_48 , 1 ) ;
F_26 ( V_48 , V_49 , V_54 ) ;
F_27 ( V_48 , V_54 ) ;
F_28 ( V_48 ) ;
V_48 -> V_63 = F_29 ( V_64 ) ;
V_48 -> V_6 = V_2 -> V_55 ;
F_30 ( V_48 ) ;
V_2 -> V_55 -> V_57 . V_65 ++ ;
V_2 -> V_55 -> V_57 . V_66 += V_54 ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
V_2 -> V_67 = NULL ;
V_2 -> V_68 = F_34 ( 0 , V_13 ) ;
if ( ! V_2 -> V_68 )
return 0 ;
V_2 -> V_67 = F_34 ( 0 , V_13 ) ;
if ( ! V_2 -> V_67 ) {
F_35 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
return 0 ;
}
return 1 ;
}
static inline int F_36 ( struct V_1 * V_2 )
{
V_2 -> V_69 . V_70 = FALSE ;
V_2 -> V_69 . V_71 = V_72 ;
F_37 ( V_2 -> V_67 , V_2 -> V_7 ,
F_38 ( V_2 -> V_7 , V_2 -> V_73 ) ,
V_2 -> V_74 , 4096 , V_75 , V_2 ) ;
V_2 -> V_67 -> V_76 = 0 ;
return F_39 ( V_2 -> V_67 , V_13 ) ;
}
static inline int F_40 ( struct V_1 * V_2 ,
struct V_77 * V_78 , int V_79 )
{
int V_80 ;
int V_12 = 0 ;
if ( ! V_78 )
return V_12 ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
if ( V_78 [ V_80 ] . V_81 . V_82 & V_83 )
V_2 -> V_73 = V_78 [ V_80 ] . V_81 . V_82 ;
else
V_2 -> V_84 = V_78 [ V_80 ] . V_81 . V_82 ;
if ( ( V_2 -> V_73 != 0 ) && ( V_2 -> V_84 != 0 ) ) {
V_12 = 1 ;
break;
}
}
return V_12 ;
}
static void F_41 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_42 ( V_86 , struct V_1 , V_86 ) ;
struct V_87 * V_55 = V_2 -> V_55 ;
F_43 ( V_2 ) ;
F_44 ( V_55 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
int V_88 = 0 ;
int V_89 = 0 ;
T_1 V_90 ;
T_1 V_17 ;
V_90 = V_91 [ ( V_2 -> V_36 >> 8 ) & 0x0f ] ;
do {
F_5 ( V_2 , V_92 , & V_17 ) ;
} while( V_89 ++ < 100 && ( V_17 & V_93 ) );
if ( V_89 > 100 ) {
F_15 ( L_9 ) ;
V_12 = - V_19 ;
goto error;
}
F_5 ( V_2 , V_25 , & V_17 ) ;
if ( V_2 -> V_36 <= 115200 ) {
V_17 &= ~ V_28 ;
if ( ( V_88 = ( V_2 -> V_35 > 115200 ) ) )
F_1 ( V_2 , V_27 , 0 ) ;
} else if ( V_2 -> V_36 <= 1152000 ) {
V_17 &= ~ V_28 ;
if ( ( V_88 = ! ( V_2 -> V_35 == 576000 || V_2 -> V_35 == 1152000 ) ) )
F_1 ( V_2 , V_27 , 5 ) ;
} else {
V_17 |= V_28 ;
if ( ( V_88 = ( V_2 -> V_35 != 4000000 ) ) )
F_1 ( V_2 , V_27 , 5 ) ;
}
V_17 &= ~ V_33 ;
V_17 |= V_90 ;
V_12 = F_1 ( V_2 , V_25 , V_17 ) ;
if ( F_10 ( V_12 ) )
goto error;
if ( V_88 )
switch ( V_2 -> V_40 ) {
case V_41 :
V_12 = F_9 ( V_2 ) ;
break;
case V_42 :
V_12 = F_13 ( V_2 ) ;
break;
case V_43 :
V_12 = F_11 ( V_2 ) ;
break;
default:
V_12 = 1 ;
F_12 ( L_4 ,
V_2 -> V_40 ) ;
}
if ( F_10 ( V_12 ) )
goto error;
F_5 ( V_2 , V_25 , & V_17 ) ;
V_17 &= ~ V_46 ;
V_12 = F_1 ( V_2 , V_25 , V_17 ) ;
V_2 -> V_35 = V_2 -> V_36 ;
error:
V_2 -> V_36 = 0 ;
return V_12 ;
}
static int F_45 ( struct V_87 * V_55 , struct V_94 * V_95 , int V_96 )
{
int V_12 = 0 ;
switch ( V_96 ) {
default:
V_12 = - V_97 ;
}
return V_12 ;
}
static int F_46 ( struct V_87 * V_55 )
{
int V_12 = 0 ;
struct V_1 * V_2 = F_47 ( V_55 ) ;
F_48 ( V_55 ) ;
F_49 ( V_2 -> V_69 . V_48 ) ;
F_50 ( V_2 -> V_67 ) ;
F_35 ( V_2 -> V_67 ) ;
F_50 ( V_2 -> V_68 ) ;
F_35 ( V_2 -> V_68 ) ;
if ( V_2 -> V_98 )
F_51 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
return V_12 ;
}
static int F_52 ( struct V_87 * V_55 )
{
struct V_1 * V_2 = F_47 ( V_55 ) ;
char V_99 [ 16 ] ;
int V_12 = 0 ;
V_12 = F_53 ( V_2 -> V_7 ,
F_54 ( V_2 -> V_7 , V_2 -> V_73 ) ) ;
if ( V_12 )
goto V_100;
V_12 = F_53 ( V_2 -> V_7 ,
F_38 ( V_2 -> V_7 , V_2 -> V_84 ) ) ;
if ( V_12 )
goto V_100;
V_12 = F_14 ( V_2 ) ;
if ( V_12 )
goto V_100;
V_12 = - V_14 ;
V_2 -> V_101 = 0 ;
V_2 -> V_69 . V_102 = V_103 ;
V_2 -> V_69 . V_48 = F_24 ( V_103 ) ;
if ( ! V_2 -> V_69 . V_48 )
goto V_100;
F_25 ( V_2 -> V_69 . V_48 , 1 ) ;
V_2 -> V_69 . V_104 = V_2 -> V_69 . V_48 -> V_53 ;
sprintf ( V_99 , L_10 , V_2 -> V_7 -> V_105 ) ;
V_2 -> V_98 = F_55 ( V_55 , & V_2 -> V_106 , V_99 ) ;
if ( ! V_2 -> V_98 ) {
F_15 ( L_11 ) ;
goto V_107;
}
if ( ! F_33 ( V_2 ) )
goto V_108;
V_12 = F_36 ( V_2 ) ;
if ( V_12 )
goto V_109;
F_56 ( V_55 ) ;
return 0 ;
V_109:
F_35 ( V_2 -> V_67 ) ;
F_35 ( V_2 -> V_68 ) ;
V_108:
F_51 ( V_2 -> V_98 ) ;
V_107:
F_49 ( V_2 -> V_69 . V_48 ) ;
V_100:
return V_12 ;
}
static void V_75 ( struct V_110 * V_110 )
{
T_2 * V_111 ;
struct V_1 * V_2 = V_110 -> V_112 ;
int V_80 ;
int V_12 ;
if ( ! F_57 ( V_2 -> V_55 ) )
return;
if ( V_110 -> V_76 )
return;
if ( V_110 -> V_113 > 0 ) {
V_111 = V_110 -> V_114 ;
if( V_2 -> V_35 < 576000 ) {
F_58 ( V_2 -> V_55 , & V_2 -> V_55 -> V_57 ,
& V_2 -> V_69 , 0xc0 ) ;
for ( V_80 = 0 ; V_80 < V_110 -> V_113 ; V_80 ++ )
F_58 ( V_2 -> V_55 , & V_2 -> V_55 -> V_57 ,
& V_2 -> V_69 , V_111 [ V_80 ] ) ;
F_58 ( V_2 -> V_55 , & V_2 -> V_55 -> V_57 ,
& V_2 -> V_69 , 0xc1 ) ;
}
else if( V_2 -> V_35 == 576000 || V_2 -> V_35 == 1152000 ) {
F_23 ( V_2 , V_110 -> V_114 ,
V_110 -> V_113 ) ;
}
else {
F_31 ( V_2 , V_110 -> V_114 ,
V_110 -> V_113 ) ;
}
}
V_12 = F_39 ( V_110 , V_115 ) ;
}
static void F_59 ( struct V_110 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_112 ;
struct V_87 * V_116 = V_2 -> V_55 ;
if ( F_10 ( V_2 -> V_36 ) )
F_60 ( & V_2 -> V_86 ) ;
else
F_44 ( V_116 ) ;
}
static T_4 F_61 ( struct V_47 * V_48 ,
struct V_87 * V_116 )
{
unsigned long V_117 ;
struct V_1 * V_2 ;
int V_50 ;
int V_12 = 0 ;
F_48 ( V_116 ) ;
V_2 = F_47 ( V_116 ) ;
F_62 ( & V_2 -> V_118 , V_117 ) ;
V_2 -> V_36 = F_63 ( V_48 ) ;
if ( F_64 ( V_2 -> V_36 == V_2 -> V_35 ) )
V_2 -> V_36 = 0 ;
if( V_2 -> V_35 < 576000 ) {
V_50 = F_16 ( V_48 , V_2 -> V_119 ) ;
}
else if( V_2 -> V_35 == 576000 || V_2 -> V_35 == 1152000 ) {
V_50 = F_21 ( V_48 , V_2 -> V_119 ) ;
}
else {
V_50 = F_18 ( V_48 , V_2 -> V_119 ) ;
}
F_37 ( V_2 -> V_68 , V_2 -> V_7 ,
F_54 ( V_2 -> V_7 , V_2 -> V_84 ) ,
V_2 -> V_119 , V_50 , F_59 , V_2 ) ;
if ( ( V_12 = F_39 ( V_2 -> V_68 , V_115 ) ) ) {
F_15 ( L_12 , V_12 ) ;
switch ( V_12 ) {
case - V_120 :
case - V_121 :
break;
default:
V_2 -> V_55 -> V_57 . V_122 ++ ;
F_56 ( V_116 ) ;
}
} else {
V_2 -> V_55 -> V_57 . V_123 ++ ;
V_2 -> V_55 -> V_57 . V_124 += V_48 -> V_51 ;
}
F_65 ( V_48 ) ;
F_66 ( & V_2 -> V_118 , V_117 ) ;
return V_125 ;
}
static int F_67 ( struct V_126 * V_127 ,
const struct V_128 * V_129 )
{
struct V_5 * V_130 = F_68 ( V_127 ) ;
struct V_87 * V_116 = NULL ;
struct V_1 * V_2 ;
int V_12 = - V_14 ;
V_116 = F_69 ( sizeof( * V_2 ) ) ;
if ( ! V_116 )
goto V_100;
F_70 ( L_13 , V_130 -> V_105 ) ;
F_71 ( V_116 , & V_127 -> V_6 ) ;
V_12 = F_72 ( V_130 ) ;
if ( V_12 != 0 ) {
F_15 ( L_14 ) ;
goto V_107;
}
V_2 = F_47 ( V_116 ) ;
V_2 -> V_7 = V_130 ;
V_2 -> V_55 = V_116 ;
F_73 ( & V_2 -> V_118 ) ;
F_74 ( & V_2 -> V_106 ) ;
V_2 -> V_106 . V_131 . V_132 &=
V_133 | V_134 | V_135 | V_136 | V_137 | V_138
| V_139 | V_140 | ( V_141 << 8 ) ;
V_2 -> V_106 . V_142 . V_132 &= V_143 ;
F_75 ( & V_2 -> V_106 ) ;
F_76 ( & V_2 -> V_86 , F_41 ) ;
V_116 -> V_144 = & V_145 ;
if ( ! V_127 -> V_146 ) {
V_12 = - V_14 ;
goto V_107;
}
V_12 = F_40 ( V_2 , V_127 -> V_146 -> V_147 ,
V_127 -> V_146 -> V_81 . V_148 ) ;
if ( ! V_12 ) {
V_12 = - V_120 ;
goto V_107;
}
V_12 = F_77 ( V_116 ) ;
if ( V_12 != 0 )
goto V_107;
F_70 ( L_15 ,
V_116 -> V_56 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_44 = V_44 ;
F_78 ( V_127 , V_2 ) ;
return 0 ;
V_107:
F_79 ( V_116 ) ;
V_100:
return V_12 ;
}
static void F_80 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_81 ( V_127 ) ;
if ( ! V_2 )
return;
F_82 ( & V_2 -> V_86 ) ;
F_83 ( V_2 -> V_55 ) ;
F_79 ( V_2 -> V_55 ) ;
F_78 ( V_127 , NULL ) ;
F_70 ( L_16 ) ;
}
