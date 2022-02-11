static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
void T_2 * V_4 = V_2 -> V_5 + V_3 ;
return F_2 ( V_4 ) | ( F_2 ( V_4 + 1 ) << 8 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
void T_2 * V_4 = V_2 -> V_5 + V_3 ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 + 1 , V_6 >> 8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
void T_2 * V_4 = V_2 -> V_5 + 0x40 ;
T_3 * V_7 = V_2 -> V_8 ;
int V_9 = V_10 ;
while ( V_9 -- )
* V_7 ++ = F_2 ( V_4 ++ ) ;
V_2 -> V_8 = V_7 ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_2 * V_4 = V_2 -> V_5 + 0x40 ;
T_3 * V_11 = V_2 -> V_8 ;
int V_9 = V_10 ;
while ( V_9 -- )
F_4 ( V_4 ++ , * V_11 ++ ) ;
V_2 -> V_8 = V_11 ;
}
static T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
return F_8 ( V_2 -> V_5 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
F_10 ( V_2 -> V_5 + V_3 , V_6 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_9 = V_10 / 2 ;
T_1 * V_7 = V_2 -> V_8 ;
while ( V_9 -- )
* V_7 ++ = F_12 ( V_2 -> V_5 + 0x40 ) ;
V_2 -> V_8 = V_7 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_9 = V_10 / 2 ;
T_1 * V_11 = V_2 -> V_8 ;
while ( V_9 -- )
F_14 ( V_2 -> V_5 + 0x40 , * V_11 ++ ) ;
V_2 -> V_8 = V_11 ;
}
static T_1 F_15 ( struct V_1 * V_2 , int V_3 )
{
return F_12 ( V_2 -> V_5 + V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
F_14 ( V_2 -> V_5 + V_3 , V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_9 = V_10 / 2 ;
T_1 * V_7 = V_2 -> V_8 ;
while ( V_9 -- )
* V_7 ++ = F_8 ( V_2 -> V_5 + 0x40 ) ;
V_2 -> V_8 = V_7 ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_9 = V_10 / 2 ;
T_1 * V_11 = V_2 -> V_8 ;
while ( V_9 -- )
F_10 ( V_2 -> V_5 + 0x40 , * V_11 ++ ) ;
V_2 -> V_8 = V_11 ;
}
static inline T_1 F_19 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_12 -> V_13 ( V_2 , V_3 ) ;
}
static inline T_4 F_20 ( struct V_1 * V_2 , int V_3 )
{
return F_19 ( V_2 , V_3 ) | ( F_19 ( V_2 , V_3 + 2 ) << 16 ) ;
}
static inline void F_21 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
V_2 -> V_12 -> V_14 ( V_2 , V_3 , V_6 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , int V_3 , T_4 V_6 )
{
F_21 ( V_2 , V_3 , V_6 ) ;
F_21 ( V_2 , V_3 + 2 , V_6 >> 16 ) ;
}
static void F_23 ( void * V_15 , int V_16 )
{
const char * V_17 = V_15 ;
int V_9 , V_18 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 += 16 ) {
F_24 ( V_19 L_1 , V_9 ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
if ( ! ( V_18 % 4 ) )
F_24 ( L_2 ) ;
F_24 ( L_3 , V_17 [ V_9 + V_18 ] ) ;
}
F_24 ( L_2 ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ )
F_24 ( L_4 , isprint ( V_17 [ V_9 + V_18 ] ) ? V_17 [ V_9 + V_18 ] : '.' ) ;
F_24 ( L_5 ) ;
}
}
static inline void F_23 ( void * V_15 , int V_16 )
{
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_20 ,
L_6
L_7
L_8 ,
F_20 ( V_2 , V_21 ) ,
F_19 ( V_2 , V_22 ) ,
F_19 ( V_2 , V_23 ) ,
F_20 ( V_2 , V_24 ) ,
F_20 ( V_2 , V_25 ) ,
F_19 ( V_2 , V_26 ) ,
F_20 ( V_2 , V_27 ) ,
F_20 ( V_2 , V_28 ) , F_19 ( V_2 , V_29 ) ) ;
}
void F_27 ( T_1 * V_30 )
{
#if F_28 ( V_31 )
int V_9 ;
for ( V_9 = 0 ; V_9 < V_32 ; V_9 ++ , V_30 ++ )
* V_30 = F_29 ( * V_30 ) ;
#endif
}
static inline void F_30 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_20 , L_9 ) ;
F_32 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = 0 ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_20 , L_10 ) ;
if ( V_2 -> V_35 == V_36 )
F_32 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = 0 ;
}
struct V_37 * F_34 ( struct V_38 * V_39 )
{
struct V_37 * V_40 ;
while ( ( V_40 = F_35 ( V_39 ) ) != NULL ) {
if ( V_40 -> V_41 == V_42 )
break;
F_36 ( V_40 ) ;
F_37 ( V_40 , - V_43 ) ;
}
return V_40 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_37 * V_40 ;
T_4 V_44 ;
T_1 V_6 ;
int V_45 ;
#if F_28 ( V_46 )
F_31 ( V_2 -> V_20 , L_11 ,
V_2 -> V_47 , V_2 -> V_48 ) ;
#endif
V_44 = F_20 ( V_2 , V_24 ) ;
if ( ( V_44 & V_49 ) == 0 ) {
V_2 -> V_47 = V_50 ;
V_2 -> V_51 = 1 ;
F_39 ( V_2 -> V_52 , 0 ) ;
F_26 ( V_2 -> V_20 , L_12 ) ;
if ( V_2 -> V_40 ) {
F_37 ( V_2 -> V_40 , - V_43 ) ;
V_2 -> V_40 = NULL ;
}
while ( ( V_40 = F_40 ( V_2 -> V_53 ) ) != NULL )
F_37 ( V_40 , - V_43 ) ;
V_2 -> V_47 = V_50 ;
V_2 -> V_54 = - V_43 ;
while ( V_2 -> V_48 ) {
F_41 ( & V_2 -> V_55 ) ;
V_2 -> V_48 -- ;
}
}
switch ( V_2 -> V_47 ) {
case V_50 :
if ( V_2 -> V_48 || F_34 ( V_2 -> V_53 ) ) {
V_2 -> V_56 ++ ;
V_2 -> V_47 = V_57 ;
F_42 ( & V_2 -> V_58 , V_59 + V_60 ) ;
if ( ! F_43 ( & V_2 -> V_58 ) )
F_44 ( & V_2 -> V_58 ) ;
break;
}
F_45 ( & V_2 -> V_58 ) ;
V_2 -> V_34 = 0 ;
break;
case V_57 :
if ( F_19 ( V_2 , V_24 ) & V_61 ) {
V_2 -> V_47 = V_62 ;
break;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_63 ) ;
V_2 -> V_47 = V_64 ;
break;
case V_64 :
if ( F_19 ( V_2 , V_24 ) & V_61 ) {
V_2 -> V_47 = V_62 ;
break;
}
F_30 ( V_2 ) ;
break;
case V_62 :
V_44 = F_20 ( V_2 , V_24 ) ;
if ( ! ( V_44 & V_65 ) ||
( V_44 & V_66 ) ) {
F_30 ( V_2 ) ;
break;
}
if ( V_2 -> V_48 )
V_2 -> V_47 = V_67 ;
else
V_2 -> V_47 = V_68 ;
break;
case V_67 :
V_2 -> V_69 = V_70 ;
V_2 -> V_8 = V_2 -> V_71 ;
V_2 -> V_72 = V_73 ;
F_21 ( V_2 , V_22 , V_74 ) ;
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_75 ) ;
V_2 -> V_47 = V_76 ;
F_33 ( V_2 ) ;
break;
case V_76 :
V_44 = F_20 ( V_2 , V_24 ) ;
if ( V_44 & V_66 ) {
F_31 ( V_2 -> V_20 , L_13 ,
V_2 -> V_69 , V_2 -> V_56 ,
V_2 -> V_72 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_44 & V_77 ) ) {
F_30 ( V_2 ) ;
break;
}
V_2 -> V_12 -> V_78 ( V_2 ) ;
V_2 -> V_72 -- ;
if ( V_2 -> V_72 != 0 ) {
F_33 ( V_2 ) ;
break;
}
F_31 ( V_2 -> V_20 , L_14 ) ;
V_2 -> V_47 = V_79 ;
break;
case V_79 :
F_27 ( V_2 -> V_71 ) ;
F_23 ( V_2 -> V_71 , 512 ) ;
if ( V_2 -> V_80 ) {
V_2 -> V_51 = 1 ;
F_39 ( V_2 -> V_52 , 0 ) ;
F_46 ( V_2 -> V_20 , L_15 ,
V_2 -> V_80 ) ;
} else {
V_2 -> V_51 = 0 ;
F_39 ( V_2 -> V_52 ,
F_47 ( V_2 -> V_71 , V_81 ) ) ;
F_26 ( V_2 -> V_20 , L_16 ,
F_47 ( V_2 -> V_71 , V_81 ) ) ;
}
V_2 -> V_47 = V_50 ;
V_2 -> V_54 = V_2 -> V_80 ;
while ( V_2 -> V_48 ) {
F_41 ( & V_2 -> V_55 ) ;
V_2 -> V_48 -- ;
}
break;
case V_68 :
V_40 = F_34 ( V_2 -> V_53 ) ;
if ( ! V_40 ) {
V_2 -> V_47 = V_50 ;
break;
}
F_36 ( V_40 ) ;
F_31 ( V_2 -> V_20 ,
L_17 ,
( unsigned long long ) F_48 ( V_40 ) ,
F_49 ( V_40 ) , F_50 ( V_40 ) ,
F_51 ( V_40 ) ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_8 = V_40 -> V_82 ;
V_2 -> V_72 = F_50 ( V_40 ) * V_73 ;
F_22 ( V_2 , V_25 , F_48 ( V_40 ) & 0x0FFFFFFF ) ;
V_45 = F_49 ( V_40 ) ;
if ( F_51 ( V_40 ) ) {
F_31 ( V_2 -> V_20 , L_18 ) ;
V_2 -> V_69 = V_83 ;
F_21 ( V_2 , V_22 ,
V_45 | V_84 ) ;
} else {
F_31 ( V_2 -> V_20 , L_19 ) ;
V_2 -> V_69 = V_85 ;
F_21 ( V_2 , V_22 ,
V_45 | V_86 ) ;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_75 ) ;
V_2 -> V_47 = V_87 ;
if ( V_2 -> V_69 == V_85 )
F_33 ( V_2 ) ;
break;
case V_87 :
V_44 = F_20 ( V_2 , V_24 ) ;
if ( V_44 & V_66 ) {
F_31 ( V_2 -> V_20 ,
L_20 ,
V_2 -> V_69 , V_2 -> V_56 ,
F_50 ( V_2 -> V_40 ) * 16 ,
V_2 -> V_72 , V_2 -> V_88 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_44 & V_77 ) ) {
F_31 ( V_2 -> V_20 ,
L_21 ,
V_2 -> V_69 , V_2 -> V_56 ,
F_50 ( V_2 -> V_40 ) * 16 ,
V_2 -> V_72 , V_2 -> V_88 ) ;
F_33 ( V_2 ) ;
break;
}
if ( V_2 -> V_69 == V_83 )
V_2 -> V_12 -> V_89 ( V_2 ) ;
else
V_2 -> V_12 -> V_78 ( V_2 ) ;
V_2 -> V_72 -- ;
if ( V_2 -> V_72 != 0 ) {
F_33 ( V_2 ) ;
break;
}
if ( F_52 ( V_2 -> V_40 , 0 ) ) {
V_2 -> V_8 = V_2 -> V_40 -> V_82 ;
V_2 -> V_72 = F_50 ( V_2 -> V_40 ) * 16 ;
F_33 ( V_2 ) ;
break;
}
V_2 -> V_47 = V_90 ;
break;
case V_90 :
V_2 -> V_40 = NULL ;
V_2 -> V_47 = V_50 ;
break;
default:
V_2 -> V_47 = V_50 ;
break;
}
}
static void F_53 ( unsigned long V_91 )
{
struct V_1 * V_2 = ( void * ) V_91 ;
unsigned long V_92 ;
F_54 ( & V_2 -> V_93 , V_92 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_38 ( V_2 ) ;
F_55 ( & V_2 -> V_93 , V_92 ) ;
}
static void F_56 ( unsigned long V_91 )
{
struct V_1 * V_2 = ( void * ) V_91 ;
unsigned long V_92 ;
F_57 ( V_2 -> V_20 ,
L_22 ,
V_2 -> V_47 , V_2 -> V_69 , V_2 -> V_56 ,
V_2 -> V_72 ) ;
F_54 ( & V_2 -> V_93 , V_92 ) ;
F_42 ( & V_2 -> V_58 , V_59 + V_60 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_38 ( V_2 ) ;
F_55 ( & V_2 -> V_93 , V_92 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_4 V_94 = F_20 ( V_2 , V_24 ) ;
T_1 V_95 = F_19 ( V_2 , V_21 ) ;
if ( ( V_94 & ( V_96 | V_97 ) ) &&
( V_95 & V_98 ) ) {
F_46 ( V_2 -> V_20 , L_23 ) ;
F_25 ( V_2 ) ;
return - V_43 ;
}
return 0 ;
}
static T_5 F_59 ( int V_35 , void * V_99 )
{
T_1 V_95 ;
struct V_1 * V_2 = V_99 ;
F_60 ( & V_2 -> V_93 ) ;
V_2 -> V_88 = 1 ;
V_95 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_95 | V_100 ) ;
F_21 ( V_2 , V_21 , V_95 ) ;
if ( F_58 ( V_2 ) )
V_2 -> V_80 = - V_43 ;
if ( V_2 -> V_69 == 0 ) {
F_46 ( V_2 -> V_20 ,
L_24 ,
F_20 ( V_2 , V_24 ) , F_20 ( V_2 , V_21 ) ,
F_19 ( V_2 , V_22 ) ) ;
F_46 ( V_2 -> V_20 , L_25 ,
V_2 -> V_69 , V_2 -> V_47 , V_2 -> V_72 ) ;
}
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_38 ( V_2 ) ;
V_2 -> V_88 = 0 ;
F_61 ( & V_2 -> V_93 ) ;
return V_101 ;
}
static void F_62 ( struct V_38 * V_39 )
{
struct V_37 * V_40 ;
struct V_1 * V_2 ;
V_40 = F_34 ( V_39 ) ;
if ( V_40 ) {
V_2 = V_40 -> V_102 -> V_103 ;
F_32 ( & V_2 -> V_33 ) ;
}
}
static unsigned int F_63 ( struct V_104 * V_52 , unsigned int V_105 )
{
struct V_1 * V_2 = V_52 -> V_103 ;
F_31 ( V_2 -> V_20 , L_26 , V_2 -> V_51 ) ;
return V_2 -> V_51 ? V_106 : 0 ;
}
static int F_64 ( struct V_104 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_103 ;
unsigned long V_92 ;
F_31 ( V_2 -> V_20 , L_27 ) ;
if ( V_2 -> V_51 ) {
F_31 ( V_2 -> V_20 , L_28 ) ;
F_54 ( & V_2 -> V_93 , V_92 ) ;
V_2 -> V_48 ++ ;
F_55 ( & V_2 -> V_93 , V_92 ) ;
F_32 ( & V_2 -> V_33 ) ;
F_65 ( & V_2 -> V_55 ) ;
}
F_31 ( V_2 -> V_20 , L_29 ) ;
return V_2 -> V_54 ;
}
static int F_66 ( struct V_107 * V_108 , T_6 V_109 )
{
struct V_1 * V_2 = V_108 -> V_110 -> V_103 ;
unsigned long V_92 ;
F_31 ( V_2 -> V_20 , L_30 , V_2 -> V_111 + 1 ) ;
F_67 ( & V_112 ) ;
F_54 ( & V_2 -> V_93 , V_92 ) ;
V_2 -> V_111 ++ ;
F_55 ( & V_2 -> V_93 , V_92 ) ;
F_68 ( V_108 ) ;
F_69 ( & V_112 ) ;
return 0 ;
}
static int F_70 ( struct V_104 * V_113 , T_6 V_109 )
{
struct V_1 * V_2 = V_113 -> V_103 ;
unsigned long V_92 ;
T_1 V_6 ;
F_31 ( V_2 -> V_20 , L_31 , V_2 -> V_111 - 1 ) ;
F_67 ( & V_112 ) ;
F_54 ( & V_2 -> V_93 , V_92 ) ;
V_2 -> V_111 -- ;
if ( V_2 -> V_111 == 0 ) {
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 & ~ V_63 ) ;
}
F_55 ( & V_2 -> V_93 , V_92 ) ;
F_69 ( & V_112 ) ;
return 0 ;
}
static int F_71 ( struct V_107 * V_108 , struct V_114 * V_115 )
{
struct V_1 * V_2 = V_108 -> V_110 -> V_103 ;
T_1 * V_71 = V_2 -> V_71 ;
F_31 ( V_2 -> V_20 , L_32 ) ;
V_115 -> V_116 = V_71 [ V_117 ] ;
V_115 -> V_118 = V_71 [ V_119 ] ;
V_115 -> V_120 = V_71 [ V_121 ] ;
return 0 ;
}
static int T_7 F_72 ( struct V_1 * V_2 )
{
T_1 V_122 ;
T_1 V_6 ;
int V_123 ;
F_31 ( V_2 -> V_20 , L_33 , V_2 ) ;
F_31 ( V_2 -> V_20 , L_34 ,
( unsigned long long ) V_2 -> V_124 , V_2 -> V_35 ) ;
F_73 ( & V_2 -> V_93 ) ;
F_74 ( & V_2 -> V_55 ) ;
V_2 -> V_5 = F_75 ( V_2 -> V_124 , 0x80 ) ;
if ( ! V_2 -> V_5 )
goto V_125;
F_76 ( & V_2 -> V_33 , F_53 , ( unsigned long ) V_2 ) ;
F_77 ( & V_2 -> V_58 , F_56 , ( unsigned long ) V_2 ) ;
V_2 -> V_53 = F_78 ( F_62 , & V_2 -> V_93 ) ;
if ( V_2 -> V_53 == NULL )
goto V_126;
F_79 ( V_2 -> V_53 , 512 ) ;
V_2 -> V_52 = F_80 ( V_127 ) ;
if ( ! V_2 -> V_52 )
goto V_128;
V_2 -> V_52 -> V_129 = V_130 ;
V_2 -> V_52 -> V_131 = V_2 -> V_30 * V_127 ;
V_2 -> V_52 -> V_132 = & V_133 ;
V_2 -> V_52 -> V_53 = V_2 -> V_53 ;
V_2 -> V_52 -> V_103 = V_2 ;
snprintf ( V_2 -> V_52 -> V_134 , 32 , L_35 , V_2 -> V_30 + 'a' ) ;
if ( V_2 -> V_135 == V_136 ) {
F_16 ( V_2 , V_26 , 0x0101 ) ;
if ( F_15 ( V_2 , V_26 ) == 0x0001 )
V_2 -> V_12 = & V_137 ;
else
V_2 -> V_12 = & V_138 ;
} else {
F_3 ( V_2 , V_26 , 0x00 ) ;
V_2 -> V_12 = & V_139 ;
}
V_122 = F_19 ( V_2 , V_23 ) ;
if ( ( V_122 == 0 ) || ( V_122 == 0xFFFF ) )
goto V_140;
F_21 ( V_2 , V_21 , V_141 |
V_142 | V_98 ) ;
if ( V_2 -> V_35 != V_36 ) {
V_123 = F_81 ( V_2 -> V_35 , F_59 , 0 , L_36 , V_2 ) ;
if ( V_123 ) {
F_46 ( V_2 -> V_20 , L_37 ) ;
V_2 -> V_35 = V_36 ;
}
}
V_6 = F_19 ( V_2 , V_21 ) ;
V_6 |= V_142 | V_98 ;
F_21 ( V_2 , V_21 , V_6 ) ;
F_26 ( V_2 -> V_20 , L_38 ,
( V_122 >> 12 ) & 0xf , ( V_122 >> 8 ) & 0x0f , V_122 & 0xff ) ;
F_31 ( V_2 -> V_20 , L_39 ,
( unsigned long long ) V_2 -> V_124 , V_2 -> V_5 , V_2 -> V_35 ) ;
V_2 -> V_51 = 1 ;
F_64 ( V_2 -> V_52 ) ;
F_82 ( V_2 -> V_52 ) ;
return 0 ;
V_140:
F_83 ( V_2 -> V_52 ) ;
V_128:
F_84 ( V_2 -> V_53 ) ;
V_126:
F_85 ( V_2 -> V_5 ) ;
V_125:
F_26 ( V_2 -> V_20 , L_40 ,
( unsigned long long ) V_2 -> V_124 ) ;
return - V_143 ;
}
static void T_8 F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 ) {
F_87 ( V_2 -> V_52 ) ;
F_83 ( V_2 -> V_52 ) ;
}
if ( V_2 -> V_53 )
F_84 ( V_2 -> V_53 ) ;
F_88 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_35 != V_36 )
F_89 ( V_2 -> V_35 , V_2 ) ;
F_85 ( V_2 -> V_5 ) ;
}
static int T_7
F_90 ( struct V_144 * V_20 , int V_30 , T_9 V_124 ,
int V_35 , int V_135 )
{
struct V_1 * V_2 ;
int V_123 ;
F_31 ( V_20 , L_41 , V_20 ) ;
if ( ! V_124 ) {
V_123 = - V_145 ;
goto V_146;
}
V_2 = F_91 ( sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_2 ) {
V_123 = - V_143 ;
goto V_148;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_135 = V_135 ;
V_123 = F_72 ( V_2 ) ;
if ( V_123 )
goto V_149;
F_92 ( V_20 , V_2 ) ;
return 0 ;
V_149:
F_92 ( V_20 , NULL ) ;
F_93 ( V_2 ) ;
V_148:
V_146:
F_46 ( V_20 , L_42 , V_123 ) ;
return V_123 ;
}
static void T_8 F_94 ( struct V_144 * V_20 )
{
struct V_1 * V_2 = F_95 ( V_20 ) ;
F_31 ( V_20 , L_43 , V_20 ) ;
if ( V_2 ) {
F_86 ( V_2 ) ;
F_92 ( V_20 , NULL ) ;
F_93 ( V_2 ) ;
}
}
static int T_7 F_96 ( struct V_150 * V_20 )
{
T_9 V_124 = 0 ;
int V_135 = V_136 ;
T_4 V_30 = V_20 -> V_30 ;
int V_35 = V_36 ;
int V_9 ;
F_31 ( & V_20 -> V_20 , L_44 , V_20 ) ;
F_97 ( V_20 -> V_20 . V_151 , L_45 , & V_30 ) ;
if ( V_30 < 0 )
V_30 = 0 ;
if ( F_98 ( V_20 -> V_20 . V_151 , L_46 , NULL ) )
V_135 = V_152 ;
for ( V_9 = 0 ; V_9 < V_20 -> V_153 ; V_9 ++ ) {
if ( V_20 -> V_154 [ V_9 ] . V_92 & V_155 )
V_124 = V_20 -> V_154 [ V_9 ] . V_156 ;
if ( V_20 -> V_154 [ V_9 ] . V_92 & V_157 )
V_35 = V_20 -> V_154 [ V_9 ] . V_156 ;
}
return F_90 ( & V_20 -> V_20 , V_30 , V_124 , V_35 , V_135 ) ;
}
static int T_8 F_99 ( struct V_150 * V_20 )
{
F_94 ( & V_20 -> V_20 ) ;
return 0 ;
}
static int T_10 F_100 ( void )
{
int V_123 ;
V_130 = F_101 ( V_130 , L_47 ) ;
if ( V_130 <= 0 ) {
V_123 = - V_143 ;
goto V_158;
}
V_123 = F_102 ( & V_159 ) ;
if ( V_123 )
goto V_160;
F_103 ( L_48 , V_130 ) ;
return 0 ;
V_160:
F_104 ( V_130 , L_47 ) ;
V_158:
F_24 ( V_161 L_49 , V_123 ) ;
return V_123 ;
}
static void T_11 F_105 ( void )
{
F_106 ( L_50 ) ;
F_107 ( & V_159 ) ;
F_104 ( V_130 , L_47 ) ;
}
