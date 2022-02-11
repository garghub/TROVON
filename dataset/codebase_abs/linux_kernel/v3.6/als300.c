static inline T_1 F_1 ( unsigned long V_1 , unsigned short V_2 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
return F_3 ( V_1 + V_4 ) ;
}
static inline void F_4 ( unsigned long V_1 ,
unsigned short V_2 , T_1 V_5 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
F_5 ( V_5 , V_1 + V_4 ) ;
}
static void F_6 ( struct V_6 * V_7 , int V_8 )
{
T_1 V_9 = F_1 ( V_7 -> V_1 , V_10 ) ;
F_7 () ;
if ( ( ( V_7 -> V_11 > 5 || V_7 -> V_12 == V_13 ) ^
( V_8 == V_14 ) ) == 0 )
V_9 |= V_15 ;
else
V_9 &= ~ V_15 ;
F_4 ( V_7 -> V_1 , V_10 , V_9 ) ;
F_8 () ;
}
static int F_9 ( struct V_6 * V_7 )
{
F_7 () ;
F_6 ( V_7 , V_16 ) ;
if ( V_7 -> V_17 >= 0 )
F_10 ( V_7 -> V_17 , V_7 ) ;
F_11 ( V_7 -> V_18 ) ;
F_12 ( V_7 -> V_18 ) ;
F_13 ( V_7 ) ;
F_8 () ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = V_20 -> V_21 ;
return F_9 ( V_7 ) ;
}
static T_2 F_15 ( int V_17 , void * V_22 )
{
T_3 V_23 ;
struct V_6 * V_7 = V_22 ;
struct V_24 * V_25 ;
V_23 = F_16 ( V_7 -> V_1 + V_26 ) ;
if ( ! V_23 )
return V_27 ;
F_2 ( V_23 , V_7 -> V_1 + V_26 ) ;
if ( V_23 & V_28 ) {
if ( V_7 -> V_29 && V_7 -> V_30 ) {
V_25 = V_7 -> V_30 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_17 ( V_7 -> V_30 ) ;
F_18 ( L_1 ) ;
}
}
if ( V_23 & V_34 ) {
if ( V_7 -> V_29 && V_7 -> V_35 ) {
V_25 = V_7 -> V_35 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_17 ( V_7 -> V_35 ) ;
F_18 ( L_2 ) ;
}
}
return V_36 ;
}
static T_2 F_19 ( int V_17 , void * V_22 )
{
T_3 V_37 , V_38 , V_39 ;
struct V_6 * V_7 = V_22 ;
struct V_24 * V_25 ;
V_37 = F_16 ( V_7 -> V_1 + V_40 ) ;
V_38 = F_16 ( V_7 -> V_1 + V_41 ) ;
V_39 = F_16 ( V_7 -> V_1 + V_42 ) ;
if ( ( V_37 == 0 ) && ( ( V_38 & 0x80 ) == 0 ) && ( ( V_39 & 0x01 ) == 0 ) )
return V_27 ;
if ( V_37 & V_28 ) {
if ( V_7 -> V_29 && V_7 -> V_30 ) {
F_2 ( V_28 , V_7 -> V_1 + V_40 ) ;
V_25 = V_7 -> V_30 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_17 ( V_7 -> V_30 ) ;
F_18 ( L_1 ) ;
}
}
if ( V_37 & V_34 ) {
if ( V_7 -> V_29 && V_7 -> V_35 ) {
F_2 ( V_34 , V_7 -> V_1 + V_40 ) ;
V_25 = V_7 -> V_35 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_17 ( V_7 -> V_35 ) ;
F_18 ( L_2 ) ;
}
}
return V_36 ;
}
static void T_4 F_20 ( struct V_43 * V_18 )
{
F_7 () ;
F_21 ( F_22 ( V_18 ) ) ;
F_23 ( V_18 , NULL ) ;
F_8 () ;
}
static unsigned short F_24 ( struct V_44 * V_45 ,
unsigned short V_2 )
{
int V_46 ;
struct V_6 * V_7 = V_45 -> V_32 ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( ( F_16 ( V_7 -> V_1 + V_47 ) & ( V_48 ) ) == 0 )
break;
F_25 ( 10 ) ;
}
F_5 ( ( V_2 << 24 ) | ( 1 << 31 ) , V_7 -> V_1 + V_49 ) ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( ( F_16 ( V_7 -> V_1 + V_47 ) & ( V_50 ) ) != 0 )
break;
F_25 ( 10 ) ;
}
return F_26 ( V_7 -> V_1 + V_51 ) ;
}
static void F_27 ( struct V_44 * V_45 ,
unsigned short V_2 , unsigned short V_5 )
{
int V_46 ;
struct V_6 * V_7 = V_45 -> V_32 ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( ( F_16 ( V_7 -> V_1 + V_47 ) & ( V_48 ) ) == 0 )
break;
F_25 ( 10 ) ;
}
F_5 ( ( V_2 << 24 ) | V_5 , V_7 -> V_1 + V_49 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_52 * V_53 ;
struct V_54 V_45 ;
int V_55 ;
static struct V_56 V_57 = {
. V_58 = F_27 ,
. V_59 = F_24 ,
} ;
F_7 () ;
if ( ( V_55 = V_52 ( V_7 -> V_60 , 0 , & V_57 , NULL , & V_53 ) ) < 0 )
return V_55 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_32 = V_7 ;
F_8 () ;
return F_29 ( V_53 , & V_45 , & V_7 -> V_45 ) ;
}
static int F_30 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
struct V_24 * V_25 = F_32 ( sizeof( * V_25 ) ,
V_64 ) ;
F_7 () ;
V_7 -> V_30 = V_62 ;
V_31 -> V_65 = V_66 ;
V_31 -> V_32 = V_25 ;
V_25 -> V_67 = V_68 ;
V_25 -> V_69 = V_70 ;
F_8 () ;
return 0 ;
}
static int F_33 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_24 * V_25 ;
V_25 = V_62 -> V_31 -> V_32 ;
F_7 () ;
F_13 ( V_25 ) ;
V_7 -> V_30 = NULL ;
F_34 ( V_62 ) ;
F_8 () ;
return 0 ;
}
static int F_35 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
struct V_24 * V_25 = F_32 ( sizeof( * V_25 ) ,
V_64 ) ;
F_7 () ;
V_7 -> V_35 = V_62 ;
V_31 -> V_65 = V_71 ;
V_31 -> V_32 = V_25 ;
V_25 -> V_67 = V_72 ;
V_25 -> V_69 = V_73 ;
F_8 () ;
return 0 ;
}
static int F_36 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_24 * V_25 ;
V_25 = V_62 -> V_31 -> V_32 ;
F_7 () ;
F_13 ( V_25 ) ;
V_7 -> V_35 = NULL ;
F_34 ( V_62 ) ;
F_8 () ;
return 0 ;
}
static int F_37 ( struct V_61 * V_62 ,
struct V_74 * V_75 )
{
return F_38 ( V_62 ,
F_39 ( V_75 ) ) ;
}
static int F_40 ( struct V_61 * V_62 )
{
return F_34 ( V_62 ) ;
}
static int F_41 ( struct V_61 * V_62 )
{
T_1 V_9 ;
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
unsigned short V_76 = F_42 ( V_62 ) ;
unsigned short V_77 = F_43 ( V_62 ) ;
F_7 () ;
F_44 ( & V_7 -> V_78 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_68 ) ;
V_9 &= ~ V_79 ;
F_18 ( L_3 ,
V_76 , V_77 ) ;
V_9 &= 0xffff0000 ;
V_9 |= V_76 - 1 ;
F_4 ( V_7 -> V_1 , V_68 , V_9 ) ;
F_4 ( V_7 -> V_1 , V_80 ,
V_31 -> V_81 ) ;
F_4 ( V_7 -> V_1 , V_82 ,
V_31 -> V_81 + V_77 - 1 ) ;
F_45 ( & V_7 -> V_78 ) ;
F_8 () ;
return 0 ;
}
static int F_46 ( struct V_61 * V_62 )
{
T_1 V_9 ;
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
unsigned short V_76 = F_42 ( V_62 ) ;
unsigned short V_77 = F_43 ( V_62 ) ;
F_7 () ;
F_44 ( & V_7 -> V_78 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_72 ) ;
V_9 &= ~ V_79 ;
F_18 ( L_3 , V_76 ,
V_77 ) ;
V_9 &= 0xffff0000 ;
V_9 |= V_76 - 1 ;
F_4 ( V_7 -> V_1 , V_72 , V_9 ) ;
F_4 ( V_7 -> V_1 , V_83 ,
V_31 -> V_81 ) ;
F_4 ( V_7 -> V_1 , V_84 ,
V_31 -> V_81 + V_77 - 1 ) ;
F_45 ( & V_7 -> V_78 ) ;
F_8 () ;
return 0 ;
}
static int F_47 ( struct V_61 * V_62 , int V_8 )
{
struct V_6 * V_7 = F_31 ( V_62 ) ;
T_1 V_9 ;
struct V_24 * V_25 ;
unsigned short V_2 ;
int V_85 = 0 ;
V_25 = V_62 -> V_31 -> V_32 ;
V_2 = V_25 -> V_67 ;
F_7 () ;
F_48 ( & V_7 -> V_78 ) ;
switch ( V_8 ) {
case V_86 :
case V_87 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
V_25 -> V_33 = 1 ;
F_4 ( V_7 -> V_1 , V_2 , V_9 | V_79 ) ;
F_18 ( L_4 ) ;
break;
case V_88 :
case V_89 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
F_4 ( V_7 -> V_1 , V_2 , V_9 & ~ V_79 ) ;
F_18 ( L_5 ) ;
break;
case V_90 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
F_4 ( V_7 -> V_1 , V_2 , V_9 | V_91 ) ;
F_18 ( L_6 ) ;
break;
case V_92 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
F_4 ( V_7 -> V_1 , V_2 , V_9 & ~ V_91 ) ;
F_18 ( L_7 ) ;
break;
default:
F_18 ( L_8 ) ;
V_85 = - V_93 ;
}
F_49 ( & V_7 -> V_78 ) ;
F_8 () ;
return V_85 ;
}
static T_5 F_50 ( struct V_61 * V_62 )
{
T_6 V_94 ;
struct V_6 * V_7 = F_31 ( V_62 ) ;
struct V_24 * V_25 ;
unsigned short V_76 ;
V_25 = V_62 -> V_31 -> V_32 ;
V_76 = F_42 ( V_62 ) ;
F_7 () ;
F_48 ( & V_7 -> V_78 ) ;
V_94 = ( T_6 ) F_1 ( V_7 -> V_1 ,
V_25 -> V_69 ) + 4 ;
F_49 ( & V_7 -> V_78 ) ;
if ( V_94 > V_76 )
V_94 = 0 ;
else
V_94 = V_76 - V_94 ;
if ( V_25 -> V_33 == 0 )
V_94 += V_76 ;
F_18 ( L_9 , V_94 ) ;
F_8 () ;
return F_51 ( V_62 -> V_31 , V_94 ) ;
}
static int T_7 F_52 ( struct V_6 * V_7 )
{
struct V_95 * V_29 ;
int V_55 ;
F_7 () ;
V_55 = F_53 ( V_7 -> V_60 , L_10 , 0 , 1 , 1 , & V_29 ) ;
if ( V_55 < 0 )
return V_55 ;
V_29 -> V_32 = V_7 ;
strcpy ( V_29 -> V_96 , L_10 ) ;
V_7 -> V_29 = V_29 ;
F_54 ( V_29 , V_97 ,
& V_98 ) ;
F_54 ( V_29 , V_99 ,
& V_100 ) ;
F_55 ( V_29 , V_101 ,
F_56 ( V_7 -> V_18 ) , 64 * 1024 , 64 * 1024 ) ;
F_8 () ;
return 0 ;
}
static void F_57 ( struct V_6 * V_7 )
{
unsigned long V_102 ;
T_1 V_9 ;
F_7 () ;
F_58 ( & V_7 -> V_78 , V_102 ) ;
V_7 -> V_11 = ( F_1 ( V_7 -> V_1 , V_10 ) >> 16 )
& 0x0000000F ;
V_9 = F_1 ( V_7 -> V_1 , V_103 ) ;
F_4 ( V_7 -> V_1 , V_103 ,
( V_9 | V_104 )
& ~ V_105 ) ;
F_6 ( V_7 , V_14 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_10 ) ;
F_4 ( V_7 -> V_1 , V_10 ,
V_9 | V_106 | V_107 ) ;
F_4 ( V_7 -> V_1 , V_108 , 0 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_68 ) ;
F_4 ( V_7 -> V_1 , V_68 ,
V_9 & ~ V_79 ) ;
F_59 ( & V_7 -> V_78 , V_102 ) ;
F_8 () ;
}
static int T_7 F_60 ( struct V_109 * V_60 ,
struct V_43 * V_18 , int V_12 ,
struct V_6 * * V_110 )
{
struct V_6 * V_7 ;
void * V_111 ;
int V_55 ;
static struct V_112 V_57 = {
. V_113 = F_14 ,
} ;
* V_110 = NULL ;
F_7 () ;
if ( ( V_55 = F_61 ( V_18 ) ) < 0 )
return V_55 ;
if ( F_62 ( V_18 , F_63 ( 28 ) ) < 0 ||
F_64 ( V_18 , F_63 ( 28 ) ) < 0 ) {
F_65 ( V_114 L_11 ) ;
F_12 ( V_18 ) ;
return - V_115 ;
}
F_66 ( V_18 ) ;
V_7 = F_32 ( sizeof( * V_7 ) , V_64 ) ;
if ( V_7 == NULL ) {
F_12 ( V_18 ) ;
return - V_116 ;
}
V_7 -> V_60 = V_60 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_17 = - 1 ;
V_7 -> V_12 = V_12 ;
F_67 ( & V_7 -> V_78 ) ;
if ( ( V_55 = F_68 ( V_18 , L_10 ) ) < 0 ) {
F_13 ( V_7 ) ;
F_12 ( V_18 ) ;
return V_55 ;
}
V_7 -> V_1 = F_69 ( V_18 , 0 ) ;
if ( V_7 -> V_12 == V_13 )
V_111 = F_19 ;
else
V_111 = F_15 ;
if ( F_70 ( V_18 -> V_17 , V_111 , V_117 ,
V_118 , V_7 ) ) {
F_71 ( V_114 L_12 , V_18 -> V_17 ) ;
F_9 ( V_7 ) ;
return - V_119 ;
}
V_7 -> V_17 = V_18 -> V_17 ;
F_57 ( V_7 ) ;
V_55 = F_28 ( V_7 ) ;
if ( V_55 < 0 ) {
F_71 ( V_120 L_13 ) ;
F_9 ( V_7 ) ;
return V_55 ;
}
if ( ( V_55 = F_52 ( V_7 ) ) < 0 ) {
F_71 ( V_120 L_14 ) ;
F_9 ( V_7 ) ;
return V_55 ;
}
if ( ( V_55 = F_72 ( V_60 , V_121 ,
V_7 , & V_57 ) ) < 0 ) {
F_9 ( V_7 ) ;
return V_55 ;
}
F_73 ( V_60 , & V_18 -> V_122 ) ;
* V_110 = V_7 ;
F_8 () ;
return 0 ;
}
static int F_74 ( struct V_20 * V_122 )
{
struct V_43 * V_18 = F_75 ( V_122 ) ;
struct V_109 * V_60 = F_76 ( V_122 ) ;
struct V_6 * V_7 = V_60 -> V_32 ;
F_77 ( V_60 , V_123 ) ;
F_78 ( V_7 -> V_29 ) ;
F_79 ( V_7 -> V_45 ) ;
F_12 ( V_18 ) ;
F_80 ( V_18 ) ;
F_81 ( V_18 , V_124 ) ;
return 0 ;
}
static int F_82 ( struct V_20 * V_122 )
{
struct V_43 * V_18 = F_75 ( V_122 ) ;
struct V_109 * V_60 = F_76 ( V_122 ) ;
struct V_6 * V_7 = V_60 -> V_32 ;
F_81 ( V_18 , V_125 ) ;
F_83 ( V_18 ) ;
if ( F_61 ( V_18 ) < 0 ) {
F_65 ( V_114 L_15
L_16 ) ;
F_84 ( V_60 ) ;
return - V_126 ;
}
F_66 ( V_18 ) ;
F_57 ( V_7 ) ;
F_85 ( V_7 -> V_45 ) ;
F_77 ( V_60 , V_127 ) ;
return 0 ;
}
static int T_7 F_86 ( struct V_43 * V_18 ,
const struct V_128 * V_129 )
{
static int V_122 ;
struct V_109 * V_60 ;
struct V_6 * V_7 ;
int V_55 , V_12 ;
if ( V_122 >= V_130 )
return - V_131 ;
if ( ! V_132 [ V_122 ] ) {
V_122 ++ ;
return - V_133 ;
}
V_55 = F_87 ( V_134 [ V_122 ] , V_135 [ V_122 ] , V_136 , 0 , & V_60 ) ;
if ( V_55 < 0 )
return V_55 ;
V_12 = V_129 -> V_137 ;
if ( ( V_55 = F_60 ( V_60 , V_18 , V_12 , & V_7 ) ) < 0 ) {
F_21 ( V_60 ) ;
return V_55 ;
}
V_60 -> V_32 = V_7 ;
strcpy ( V_60 -> V_138 , L_10 ) ;
if ( V_7 -> V_12 == V_13 )
sprintf ( V_60 -> V_139 , L_17 , V_7 -> V_11 ) ;
else
sprintf ( V_60 -> V_139 , L_18 , 'A' +
V_7 -> V_11 - 1 ) ;
sprintf ( V_60 -> V_140 , L_19 ,
V_60 -> V_139 , V_7 -> V_1 , V_7 -> V_17 ) ;
if ( ( V_55 = F_88 ( V_60 ) ) < 0 ) {
F_21 ( V_60 ) ;
return V_55 ;
}
F_23 ( V_18 , V_60 ) ;
V_122 ++ ;
return 0 ;
}
