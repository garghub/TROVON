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
if ( ( ( V_7 -> V_11 > 5 || V_7 -> V_12 == V_13 ) ^
( V_8 == V_14 ) ) == 0 )
V_9 |= V_15 ;
else
V_9 &= ~ V_15 ;
F_4 ( V_7 -> V_1 , V_10 , V_9 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
F_6 ( V_7 , V_16 ) ;
if ( V_7 -> V_17 >= 0 )
F_8 ( V_7 -> V_17 , V_7 ) ;
F_9 ( V_7 -> V_18 ) ;
F_10 ( V_7 -> V_18 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = V_20 -> V_21 ;
return F_7 ( V_7 ) ;
}
static T_2 F_13 ( int V_17 , void * V_22 )
{
T_3 V_23 ;
struct V_6 * V_7 = V_22 ;
struct V_24 * V_25 ;
V_23 = F_14 ( V_7 -> V_1 + V_26 ) ;
if ( ! V_23 )
return V_27 ;
F_2 ( V_23 , V_7 -> V_1 + V_26 ) ;
if ( V_23 & V_28 ) {
if ( V_7 -> V_29 && V_7 -> V_30 ) {
V_25 = V_7 -> V_30 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_15 ( V_7 -> V_30 ) ;
F_16 ( L_1 ) ;
}
}
if ( V_23 & V_34 ) {
if ( V_7 -> V_29 && V_7 -> V_35 ) {
V_25 = V_7 -> V_35 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_15 ( V_7 -> V_35 ) ;
F_16 ( L_2 ) ;
}
}
return V_36 ;
}
static T_2 F_17 ( int V_17 , void * V_22 )
{
T_3 V_37 , V_38 , V_39 ;
struct V_6 * V_7 = V_22 ;
struct V_24 * V_25 ;
V_37 = F_14 ( V_7 -> V_1 + V_40 ) ;
V_38 = F_14 ( V_7 -> V_1 + V_41 ) ;
V_39 = F_14 ( V_7 -> V_1 + V_42 ) ;
if ( ( V_37 == 0 ) && ( ( V_38 & 0x80 ) == 0 ) && ( ( V_39 & 0x01 ) == 0 ) )
return V_27 ;
if ( V_37 & V_28 ) {
if ( V_7 -> V_29 && V_7 -> V_30 ) {
F_2 ( V_28 , V_7 -> V_1 + V_40 ) ;
V_25 = V_7 -> V_30 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_15 ( V_7 -> V_30 ) ;
F_16 ( L_1 ) ;
}
}
if ( V_37 & V_34 ) {
if ( V_7 -> V_29 && V_7 -> V_35 ) {
F_2 ( V_34 , V_7 -> V_1 + V_40 ) ;
V_25 = V_7 -> V_35 -> V_31 -> V_32 ;
V_25 -> V_33 ^= 1 ;
F_15 ( V_7 -> V_35 ) ;
F_16 ( L_2 ) ;
}
}
return V_36 ;
}
static void F_18 ( struct V_43 * V_18 )
{
F_19 ( F_20 ( V_18 ) ) ;
}
static unsigned short F_21 ( struct V_44 * V_45 ,
unsigned short V_2 )
{
int V_46 ;
struct V_6 * V_7 = V_45 -> V_32 ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( ( F_14 ( V_7 -> V_1 + V_47 ) & ( V_48 ) ) == 0 )
break;
F_22 ( 10 ) ;
}
F_5 ( ( V_2 << 24 ) | ( 1 << 31 ) , V_7 -> V_1 + V_49 ) ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( ( F_14 ( V_7 -> V_1 + V_47 ) & ( V_50 ) ) != 0 )
break;
F_22 ( 10 ) ;
}
return F_23 ( V_7 -> V_1 + V_51 ) ;
}
static void F_24 ( struct V_44 * V_45 ,
unsigned short V_2 , unsigned short V_5 )
{
int V_46 ;
struct V_6 * V_7 = V_45 -> V_32 ;
for ( V_46 = 0 ; V_46 < 1000 ; V_46 ++ ) {
if ( ( F_14 ( V_7 -> V_1 + V_47 ) & ( V_48 ) ) == 0 )
break;
F_22 ( 10 ) ;
}
F_5 ( ( V_2 << 24 ) | V_5 , V_7 -> V_1 + V_49 ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_52 * V_53 ;
struct V_54 V_45 ;
int V_55 ;
static struct V_56 V_57 = {
. V_58 = F_24 ,
. V_59 = F_21 ,
} ;
if ( ( V_55 = V_52 ( V_7 -> V_60 , 0 , & V_57 , NULL , & V_53 ) ) < 0 )
return V_55 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_32 = V_7 ;
return F_26 ( V_53 , & V_45 , & V_7 -> V_45 ) ;
}
static int F_27 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
struct V_24 * V_25 = F_29 ( sizeof( * V_25 ) ,
V_64 ) ;
if ( ! V_25 )
return - V_65 ;
V_7 -> V_30 = V_62 ;
V_31 -> V_66 = V_67 ;
V_31 -> V_32 = V_25 ;
V_25 -> V_68 = V_69 ;
V_25 -> V_70 = V_71 ;
return 0 ;
}
static int F_30 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_24 * V_25 ;
V_25 = V_62 -> V_31 -> V_32 ;
F_11 ( V_25 ) ;
V_7 -> V_30 = NULL ;
F_31 ( V_62 ) ;
return 0 ;
}
static int F_32 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
struct V_24 * V_25 = F_29 ( sizeof( * V_25 ) ,
V_64 ) ;
if ( ! V_25 )
return - V_65 ;
V_7 -> V_35 = V_62 ;
V_31 -> V_66 = V_72 ;
V_31 -> V_32 = V_25 ;
V_25 -> V_68 = V_73 ;
V_25 -> V_70 = V_74 ;
return 0 ;
}
static int F_33 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_24 * V_25 ;
V_25 = V_62 -> V_31 -> V_32 ;
F_11 ( V_25 ) ;
V_7 -> V_35 = NULL ;
F_31 ( V_62 ) ;
return 0 ;
}
static int F_34 ( struct V_61 * V_62 ,
struct V_75 * V_76 )
{
return F_35 ( V_62 ,
F_36 ( V_76 ) ) ;
}
static int F_37 ( struct V_61 * V_62 )
{
return F_31 ( V_62 ) ;
}
static int F_38 ( struct V_61 * V_62 )
{
T_1 V_9 ;
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
unsigned short V_77 = F_39 ( V_62 ) ;
unsigned short V_78 = F_40 ( V_62 ) ;
F_41 ( & V_7 -> V_79 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_69 ) ;
V_9 &= ~ V_80 ;
F_16 ( L_3 ,
V_77 , V_78 ) ;
V_9 &= 0xffff0000 ;
V_9 |= V_77 - 1 ;
F_4 ( V_7 -> V_1 , V_69 , V_9 ) ;
F_4 ( V_7 -> V_1 , V_81 ,
V_31 -> V_82 ) ;
F_4 ( V_7 -> V_1 , V_83 ,
V_31 -> V_82 + V_78 - 1 ) ;
F_42 ( & V_7 -> V_79 ) ;
return 0 ;
}
static int F_43 ( struct V_61 * V_62 )
{
T_1 V_9 ;
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_63 * V_31 = V_62 -> V_31 ;
unsigned short V_77 = F_39 ( V_62 ) ;
unsigned short V_78 = F_40 ( V_62 ) ;
F_41 ( & V_7 -> V_79 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_73 ) ;
V_9 &= ~ V_80 ;
F_16 ( L_3 , V_77 ,
V_78 ) ;
V_9 &= 0xffff0000 ;
V_9 |= V_77 - 1 ;
F_4 ( V_7 -> V_1 , V_73 , V_9 ) ;
F_4 ( V_7 -> V_1 , V_84 ,
V_31 -> V_82 ) ;
F_4 ( V_7 -> V_1 , V_85 ,
V_31 -> V_82 + V_78 - 1 ) ;
F_42 ( & V_7 -> V_79 ) ;
return 0 ;
}
static int F_44 ( struct V_61 * V_62 , int V_8 )
{
struct V_6 * V_7 = F_28 ( V_62 ) ;
T_1 V_9 ;
struct V_24 * V_25 ;
unsigned short V_2 ;
int V_86 = 0 ;
V_25 = V_62 -> V_31 -> V_32 ;
V_2 = V_25 -> V_68 ;
F_45 ( & V_7 -> V_79 ) ;
switch ( V_8 ) {
case V_87 :
case V_88 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
V_25 -> V_33 = 1 ;
F_4 ( V_7 -> V_1 , V_2 , V_9 | V_80 ) ;
F_16 ( L_4 ) ;
break;
case V_89 :
case V_90 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
F_4 ( V_7 -> V_1 , V_2 , V_9 & ~ V_80 ) ;
F_16 ( L_5 ) ;
break;
case V_91 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
F_4 ( V_7 -> V_1 , V_2 , V_9 | V_92 ) ;
F_16 ( L_6 ) ;
break;
case V_93 :
V_9 = F_1 ( V_7 -> V_1 , V_2 ) ;
F_4 ( V_7 -> V_1 , V_2 , V_9 & ~ V_92 ) ;
F_16 ( L_7 ) ;
break;
default:
F_16 ( L_8 ) ;
V_86 = - V_94 ;
}
F_46 ( & V_7 -> V_79 ) ;
return V_86 ;
}
static T_4 F_47 ( struct V_61 * V_62 )
{
T_5 V_95 ;
struct V_6 * V_7 = F_28 ( V_62 ) ;
struct V_24 * V_25 ;
unsigned short V_77 ;
V_25 = V_62 -> V_31 -> V_32 ;
V_77 = F_39 ( V_62 ) ;
F_45 ( & V_7 -> V_79 ) ;
V_95 = ( T_5 ) F_1 ( V_7 -> V_1 ,
V_25 -> V_70 ) + 4 ;
F_46 ( & V_7 -> V_79 ) ;
if ( V_95 > V_77 )
V_95 = 0 ;
else
V_95 = V_77 - V_95 ;
if ( V_25 -> V_33 == 0 )
V_95 += V_77 ;
F_16 ( L_9 , V_95 ) ;
return F_48 ( V_62 -> V_31 , V_95 ) ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_96 * V_29 ;
int V_55 ;
V_55 = F_50 ( V_7 -> V_60 , L_10 , 0 , 1 , 1 , & V_29 ) ;
if ( V_55 < 0 )
return V_55 ;
V_29 -> V_32 = V_7 ;
strcpy ( V_29 -> V_97 , L_10 ) ;
V_7 -> V_29 = V_29 ;
F_51 ( V_29 , V_98 ,
& V_99 ) ;
F_51 ( V_29 , V_100 ,
& V_101 ) ;
F_52 ( V_29 , V_102 ,
F_53 ( V_7 -> V_18 ) , 64 * 1024 , 64 * 1024 ) ;
return 0 ;
}
static void F_54 ( struct V_6 * V_7 )
{
unsigned long V_103 ;
T_1 V_9 ;
F_55 ( & V_7 -> V_79 , V_103 ) ;
V_7 -> V_11 = ( F_1 ( V_7 -> V_1 , V_10 ) >> 16 )
& 0x0000000F ;
V_9 = F_1 ( V_7 -> V_1 , V_104 ) ;
F_4 ( V_7 -> V_1 , V_104 ,
( V_9 | V_105 )
& ~ V_106 ) ;
F_6 ( V_7 , V_14 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_10 ) ;
F_4 ( V_7 -> V_1 , V_10 ,
V_9 | V_107 | V_108 ) ;
F_4 ( V_7 -> V_1 , V_109 , 0 ) ;
V_9 = F_1 ( V_7 -> V_1 , V_69 ) ;
F_4 ( V_7 -> V_1 , V_69 ,
V_9 & ~ V_80 ) ;
F_56 ( & V_7 -> V_79 , V_103 ) ;
}
static int F_57 ( struct V_110 * V_60 ,
struct V_43 * V_18 , int V_12 ,
struct V_6 * * V_111 )
{
struct V_6 * V_7 ;
void * V_112 ;
int V_55 ;
static struct V_113 V_57 = {
. V_114 = F_12 ,
} ;
* V_111 = NULL ;
if ( ( V_55 = F_58 ( V_18 ) ) < 0 )
return V_55 ;
if ( F_59 ( V_18 , F_60 ( 28 ) ) < 0 ||
F_61 ( V_18 , F_60 ( 28 ) ) < 0 ) {
F_62 ( V_60 -> V_115 , L_11 ) ;
F_10 ( V_18 ) ;
return - V_116 ;
}
F_63 ( V_18 ) ;
V_7 = F_29 ( sizeof( * V_7 ) , V_64 ) ;
if ( V_7 == NULL ) {
F_10 ( V_18 ) ;
return - V_65 ;
}
V_7 -> V_60 = V_60 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_17 = - 1 ;
V_7 -> V_12 = V_12 ;
F_64 ( & V_7 -> V_79 ) ;
if ( ( V_55 = F_65 ( V_18 , L_10 ) ) < 0 ) {
F_11 ( V_7 ) ;
F_10 ( V_18 ) ;
return V_55 ;
}
V_7 -> V_1 = F_66 ( V_18 , 0 ) ;
if ( V_7 -> V_12 == V_13 )
V_112 = F_17 ;
else
V_112 = F_13 ;
if ( F_67 ( V_18 -> V_17 , V_112 , V_117 ,
V_118 , V_7 ) ) {
F_62 ( V_60 -> V_115 , L_12 , V_18 -> V_17 ) ;
F_7 ( V_7 ) ;
return - V_119 ;
}
V_7 -> V_17 = V_18 -> V_17 ;
F_54 ( V_7 ) ;
V_55 = F_25 ( V_7 ) ;
if ( V_55 < 0 ) {
F_62 ( V_60 -> V_115 , L_13 ) ;
F_7 ( V_7 ) ;
return V_55 ;
}
if ( ( V_55 = F_49 ( V_7 ) ) < 0 ) {
F_62 ( V_60 -> V_115 , L_14 ) ;
F_7 ( V_7 ) ;
return V_55 ;
}
if ( ( V_55 = F_68 ( V_60 , V_120 ,
V_7 , & V_57 ) ) < 0 ) {
F_7 ( V_7 ) ;
return V_55 ;
}
* V_111 = V_7 ;
return 0 ;
}
static int F_69 ( struct V_20 * V_115 )
{
struct V_43 * V_18 = F_70 ( V_115 ) ;
struct V_110 * V_60 = F_71 ( V_115 ) ;
struct V_6 * V_7 = V_60 -> V_32 ;
F_72 ( V_60 , V_121 ) ;
F_73 ( V_7 -> V_29 ) ;
F_74 ( V_7 -> V_45 ) ;
F_10 ( V_18 ) ;
F_75 ( V_18 ) ;
F_76 ( V_18 , V_122 ) ;
return 0 ;
}
static int F_77 ( struct V_20 * V_115 )
{
struct V_43 * V_18 = F_70 ( V_115 ) ;
struct V_110 * V_60 = F_71 ( V_115 ) ;
struct V_6 * V_7 = V_60 -> V_32 ;
F_76 ( V_18 , V_123 ) ;
F_78 ( V_18 ) ;
if ( F_58 ( V_18 ) < 0 ) {
F_62 ( V_115 , L_15 ) ;
F_79 ( V_60 ) ;
return - V_124 ;
}
F_63 ( V_18 ) ;
F_54 ( V_7 ) ;
F_80 ( V_7 -> V_45 ) ;
F_72 ( V_60 , V_125 ) ;
return 0 ;
}
static int F_81 ( struct V_43 * V_18 ,
const struct V_126 * V_127 )
{
static int V_115 ;
struct V_110 * V_60 ;
struct V_6 * V_7 ;
int V_55 , V_12 ;
if ( V_115 >= V_128 )
return - V_129 ;
if ( ! V_130 [ V_115 ] ) {
V_115 ++ ;
return - V_131 ;
}
V_55 = F_82 ( & V_18 -> V_115 , V_132 [ V_115 ] , V_133 [ V_115 ] , V_134 ,
0 , & V_60 ) ;
if ( V_55 < 0 )
return V_55 ;
V_12 = V_127 -> V_135 ;
if ( ( V_55 = F_57 ( V_60 , V_18 , V_12 , & V_7 ) ) < 0 ) {
F_19 ( V_60 ) ;
return V_55 ;
}
V_60 -> V_32 = V_7 ;
strcpy ( V_60 -> V_136 , L_10 ) ;
if ( V_7 -> V_12 == V_13 )
sprintf ( V_60 -> V_137 , L_16 , V_7 -> V_11 ) ;
else
sprintf ( V_60 -> V_137 , L_17 , 'A' +
V_7 -> V_11 - 1 ) ;
sprintf ( V_60 -> V_138 , L_18 ,
V_60 -> V_137 , V_7 -> V_1 , V_7 -> V_17 ) ;
if ( ( V_55 = F_83 ( V_60 ) ) < 0 ) {
F_19 ( V_60 ) ;
return V_55 ;
}
F_84 ( V_18 , V_60 ) ;
V_115 ++ ;
return 0 ;
}
