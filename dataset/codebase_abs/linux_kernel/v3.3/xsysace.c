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
if ( ! V_2 -> V_35 )
F_32 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = 0 ;
}
struct V_36 * F_34 ( struct V_37 * V_38 )
{
struct V_36 * V_39 ;
while ( ( V_39 = F_35 ( V_38 ) ) != NULL ) {
if ( V_39 -> V_40 == V_41 )
break;
F_36 ( V_39 ) ;
F_37 ( V_39 , - V_42 ) ;
}
return V_39 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_36 * V_39 ;
T_4 V_43 ;
T_1 V_6 ;
int V_44 ;
#if F_28 ( V_45 )
F_31 ( V_2 -> V_20 , L_11 ,
V_2 -> V_46 , V_2 -> V_47 ) ;
#endif
V_43 = F_20 ( V_2 , V_24 ) ;
if ( ( V_43 & V_48 ) == 0 ) {
V_2 -> V_46 = V_49 ;
V_2 -> V_50 = 1 ;
F_39 ( V_2 -> V_51 , 0 ) ;
F_26 ( V_2 -> V_20 , L_12 ) ;
if ( V_2 -> V_39 ) {
F_37 ( V_2 -> V_39 , - V_42 ) ;
V_2 -> V_39 = NULL ;
}
while ( ( V_39 = F_40 ( V_2 -> V_52 ) ) != NULL )
F_37 ( V_39 , - V_42 ) ;
V_2 -> V_46 = V_49 ;
V_2 -> V_53 = - V_42 ;
while ( V_2 -> V_47 ) {
F_41 ( & V_2 -> V_54 ) ;
V_2 -> V_47 -- ;
}
}
switch ( V_2 -> V_46 ) {
case V_49 :
if ( V_2 -> V_47 || F_34 ( V_2 -> V_52 ) ) {
V_2 -> V_55 ++ ;
V_2 -> V_46 = V_56 ;
F_42 ( & V_2 -> V_57 , V_58 + V_59 ) ;
if ( ! F_43 ( & V_2 -> V_57 ) )
F_44 ( & V_2 -> V_57 ) ;
break;
}
F_45 ( & V_2 -> V_57 ) ;
V_2 -> V_34 = 0 ;
break;
case V_56 :
if ( F_19 ( V_2 , V_24 ) & V_60 ) {
V_2 -> V_46 = V_61 ;
break;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_62 ) ;
V_2 -> V_46 = V_63 ;
break;
case V_63 :
if ( F_19 ( V_2 , V_24 ) & V_60 ) {
V_2 -> V_46 = V_61 ;
break;
}
F_30 ( V_2 ) ;
break;
case V_61 :
V_43 = F_20 ( V_2 , V_24 ) ;
if ( ! ( V_43 & V_64 ) ||
( V_43 & V_65 ) ) {
F_30 ( V_2 ) ;
break;
}
if ( V_2 -> V_47 )
V_2 -> V_46 = V_66 ;
else
V_2 -> V_46 = V_67 ;
break;
case V_66 :
V_2 -> V_68 = V_69 ;
V_2 -> V_8 = V_2 -> V_70 ;
V_2 -> V_71 = V_72 ;
F_21 ( V_2 , V_22 , V_73 ) ;
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_74 ) ;
V_2 -> V_46 = V_75 ;
F_33 ( V_2 ) ;
break;
case V_75 :
V_43 = F_20 ( V_2 , V_24 ) ;
if ( V_43 & V_65 ) {
F_31 ( V_2 -> V_20 , L_13 ,
V_2 -> V_68 , V_2 -> V_55 ,
V_2 -> V_71 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_43 & V_76 ) ) {
F_30 ( V_2 ) ;
break;
}
V_2 -> V_12 -> V_77 ( V_2 ) ;
V_2 -> V_71 -- ;
if ( V_2 -> V_71 != 0 ) {
F_33 ( V_2 ) ;
break;
}
F_31 ( V_2 -> V_20 , L_14 ) ;
V_2 -> V_46 = V_78 ;
break;
case V_78 :
F_27 ( V_2 -> V_70 ) ;
F_23 ( V_2 -> V_70 , 512 ) ;
if ( V_2 -> V_79 ) {
V_2 -> V_50 = 1 ;
F_39 ( V_2 -> V_51 , 0 ) ;
F_46 ( V_2 -> V_20 , L_15 ,
V_2 -> V_79 ) ;
} else {
V_2 -> V_50 = 0 ;
F_39 ( V_2 -> V_51 ,
F_47 ( V_2 -> V_70 , V_80 ) ) ;
F_26 ( V_2 -> V_20 , L_16 ,
F_47 ( V_2 -> V_70 , V_80 ) ) ;
}
V_2 -> V_46 = V_49 ;
V_2 -> V_53 = V_2 -> V_79 ;
while ( V_2 -> V_47 ) {
F_41 ( & V_2 -> V_54 ) ;
V_2 -> V_47 -- ;
}
break;
case V_67 :
V_39 = F_34 ( V_2 -> V_52 ) ;
if ( ! V_39 ) {
V_2 -> V_46 = V_49 ;
break;
}
F_36 ( V_39 ) ;
F_31 ( V_2 -> V_20 ,
L_17 ,
( unsigned long long ) F_48 ( V_39 ) ,
F_49 ( V_39 ) , F_50 ( V_39 ) ,
F_51 ( V_39 ) ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_8 = V_39 -> V_81 ;
V_2 -> V_71 = F_50 ( V_39 ) * V_72 ;
F_22 ( V_2 , V_25 , F_48 ( V_39 ) & 0x0FFFFFFF ) ;
V_44 = F_49 ( V_39 ) ;
if ( F_51 ( V_39 ) ) {
F_31 ( V_2 -> V_20 , L_18 ) ;
V_2 -> V_68 = V_82 ;
F_21 ( V_2 , V_22 ,
V_44 | V_83 ) ;
} else {
F_31 ( V_2 -> V_20 , L_19 ) ;
V_2 -> V_68 = V_84 ;
F_21 ( V_2 , V_22 ,
V_44 | V_85 ) ;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_74 ) ;
V_2 -> V_46 = V_86 ;
if ( V_2 -> V_68 == V_84 )
F_33 ( V_2 ) ;
break;
case V_86 :
V_43 = F_20 ( V_2 , V_24 ) ;
if ( V_43 & V_65 ) {
F_31 ( V_2 -> V_20 ,
L_20 ,
V_2 -> V_68 , V_2 -> V_55 ,
F_50 ( V_2 -> V_39 ) * 16 ,
V_2 -> V_71 , V_2 -> V_87 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_43 & V_76 ) ) {
F_31 ( V_2 -> V_20 ,
L_21 ,
V_2 -> V_68 , V_2 -> V_55 ,
F_50 ( V_2 -> V_39 ) * 16 ,
V_2 -> V_71 , V_2 -> V_87 ) ;
F_33 ( V_2 ) ;
break;
}
if ( V_2 -> V_68 == V_82 )
V_2 -> V_12 -> V_88 ( V_2 ) ;
else
V_2 -> V_12 -> V_77 ( V_2 ) ;
V_2 -> V_71 -- ;
if ( V_2 -> V_71 != 0 ) {
F_33 ( V_2 ) ;
break;
}
if ( F_52 ( V_2 -> V_39 , 0 ) ) {
V_2 -> V_8 = V_2 -> V_39 -> V_81 ;
V_2 -> V_71 = F_50 ( V_2 -> V_39 ) * 16 ;
F_33 ( V_2 ) ;
break;
}
V_2 -> V_46 = V_89 ;
break;
case V_89 :
V_2 -> V_39 = NULL ;
V_2 -> V_46 = V_49 ;
break;
default:
V_2 -> V_46 = V_49 ;
break;
}
}
static void F_53 ( unsigned long V_90 )
{
struct V_1 * V_2 = ( void * ) V_90 ;
unsigned long V_91 ;
F_54 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_38 ( V_2 ) ;
F_55 ( & V_2 -> V_92 , V_91 ) ;
}
static void F_56 ( unsigned long V_90 )
{
struct V_1 * V_2 = ( void * ) V_90 ;
unsigned long V_91 ;
F_57 ( V_2 -> V_20 ,
L_22 ,
V_2 -> V_46 , V_2 -> V_68 , V_2 -> V_55 ,
V_2 -> V_71 ) ;
F_54 ( & V_2 -> V_92 , V_91 ) ;
F_42 ( & V_2 -> V_57 , V_58 + V_59 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_38 ( V_2 ) ;
F_55 ( & V_2 -> V_92 , V_91 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_4 V_93 = F_20 ( V_2 , V_24 ) ;
T_1 V_94 = F_19 ( V_2 , V_21 ) ;
if ( ( V_93 & ( V_95 | V_96 ) ) &&
( V_94 & V_97 ) ) {
F_46 ( V_2 -> V_20 , L_23 ) ;
F_25 ( V_2 ) ;
return - V_42 ;
}
return 0 ;
}
static T_5 F_59 ( int V_35 , void * V_98 )
{
T_1 V_94 ;
struct V_1 * V_2 = V_98 ;
F_60 ( & V_2 -> V_92 ) ;
V_2 -> V_87 = 1 ;
V_94 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_94 | V_99 ) ;
F_21 ( V_2 , V_21 , V_94 ) ;
if ( F_58 ( V_2 ) )
V_2 -> V_79 = - V_42 ;
if ( V_2 -> V_68 == 0 ) {
F_46 ( V_2 -> V_20 ,
L_24 ,
F_20 ( V_2 , V_24 ) , F_20 ( V_2 , V_21 ) ,
F_19 ( V_2 , V_22 ) ) ;
F_46 ( V_2 -> V_20 , L_25 ,
V_2 -> V_68 , V_2 -> V_46 , V_2 -> V_71 ) ;
}
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_38 ( V_2 ) ;
V_2 -> V_87 = 0 ;
F_61 ( & V_2 -> V_92 ) ;
return V_100 ;
}
static void F_62 ( struct V_37 * V_38 )
{
struct V_36 * V_39 ;
struct V_1 * V_2 ;
V_39 = F_34 ( V_38 ) ;
if ( V_39 ) {
V_2 = V_39 -> V_101 -> V_102 ;
F_32 ( & V_2 -> V_33 ) ;
}
}
static unsigned int F_63 ( struct V_103 * V_51 , unsigned int V_104 )
{
struct V_1 * V_2 = V_51 -> V_102 ;
F_31 ( V_2 -> V_20 , L_26 , V_2 -> V_50 ) ;
return V_2 -> V_50 ? V_105 : 0 ;
}
static int F_64 ( struct V_103 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_102 ;
unsigned long V_91 ;
F_31 ( V_2 -> V_20 , L_27 ) ;
if ( V_2 -> V_50 ) {
F_31 ( V_2 -> V_20 , L_28 ) ;
F_54 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_47 ++ ;
F_55 ( & V_2 -> V_92 , V_91 ) ;
F_32 ( & V_2 -> V_33 ) ;
F_65 ( & V_2 -> V_54 ) ;
}
F_31 ( V_2 -> V_20 , L_29 ) ;
return V_2 -> V_53 ;
}
static int F_66 ( struct V_106 * V_107 , T_6 V_108 )
{
struct V_1 * V_2 = V_107 -> V_109 -> V_102 ;
unsigned long V_91 ;
F_31 ( V_2 -> V_20 , L_30 , V_2 -> V_110 + 1 ) ;
F_67 ( & V_111 ) ;
F_54 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_110 ++ ;
F_55 ( & V_2 -> V_92 , V_91 ) ;
F_68 ( V_107 ) ;
F_69 ( & V_111 ) ;
return 0 ;
}
static int F_70 ( struct V_103 * V_112 , T_6 V_108 )
{
struct V_1 * V_2 = V_112 -> V_102 ;
unsigned long V_91 ;
T_1 V_6 ;
F_31 ( V_2 -> V_20 , L_31 , V_2 -> V_110 - 1 ) ;
F_67 ( & V_111 ) ;
F_54 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_110 -- ;
if ( V_2 -> V_110 == 0 ) {
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 & ~ V_62 ) ;
}
F_55 ( & V_2 -> V_92 , V_91 ) ;
F_69 ( & V_111 ) ;
return 0 ;
}
static int F_71 ( struct V_106 * V_107 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_107 -> V_109 -> V_102 ;
T_1 * V_70 = V_2 -> V_70 ;
F_31 ( V_2 -> V_20 , L_32 ) ;
V_114 -> V_115 = V_70 [ V_116 ] ;
V_114 -> V_117 = V_70 [ V_118 ] ;
V_114 -> V_119 = V_70 [ V_120 ] ;
return 0 ;
}
static int T_7 F_72 ( struct V_1 * V_2 )
{
T_1 V_121 ;
T_1 V_6 ;
int V_122 ;
F_31 ( V_2 -> V_20 , L_33 , V_2 ) ;
F_31 ( V_2 -> V_20 , L_34 ,
( unsigned long long ) V_2 -> V_123 , V_2 -> V_35 ) ;
F_73 ( & V_2 -> V_92 ) ;
F_74 ( & V_2 -> V_54 ) ;
V_2 -> V_5 = F_75 ( V_2 -> V_123 , 0x80 ) ;
if ( ! V_2 -> V_5 )
goto V_124;
F_76 ( & V_2 -> V_33 , F_53 , ( unsigned long ) V_2 ) ;
F_77 ( & V_2 -> V_57 , F_56 , ( unsigned long ) V_2 ) ;
V_2 -> V_52 = F_78 ( F_62 , & V_2 -> V_92 ) ;
if ( V_2 -> V_52 == NULL )
goto V_125;
F_79 ( V_2 -> V_52 , 512 ) ;
V_2 -> V_51 = F_80 ( V_126 ) ;
if ( ! V_2 -> V_51 )
goto V_127;
V_2 -> V_51 -> V_128 = V_129 ;
V_2 -> V_51 -> V_130 = V_2 -> V_30 * V_126 ;
V_2 -> V_51 -> V_131 = & V_132 ;
V_2 -> V_51 -> V_52 = V_2 -> V_52 ;
V_2 -> V_51 -> V_102 = V_2 ;
snprintf ( V_2 -> V_51 -> V_133 , 32 , L_35 , V_2 -> V_30 + 'a' ) ;
if ( V_2 -> V_134 == V_135 ) {
F_16 ( V_2 , V_26 , 0x0101 ) ;
if ( F_15 ( V_2 , V_26 ) == 0x0001 )
V_2 -> V_12 = & V_136 ;
else
V_2 -> V_12 = & V_137 ;
} else {
F_3 ( V_2 , V_26 , 0x00 ) ;
V_2 -> V_12 = & V_138 ;
}
V_121 = F_19 ( V_2 , V_23 ) ;
if ( ( V_121 == 0 ) || ( V_121 == 0xFFFF ) )
goto V_139;
F_21 ( V_2 , V_21 , V_140 |
V_141 | V_97 ) ;
if ( V_2 -> V_35 ) {
V_122 = F_81 ( V_2 -> V_35 , F_59 , 0 , L_36 , V_2 ) ;
if ( V_122 ) {
F_46 ( V_2 -> V_20 , L_37 ) ;
V_2 -> V_35 = 0 ;
}
}
V_6 = F_19 ( V_2 , V_21 ) ;
V_6 |= V_141 | V_97 ;
F_21 ( V_2 , V_21 , V_6 ) ;
F_26 ( V_2 -> V_20 , L_38 ,
( V_121 >> 12 ) & 0xf , ( V_121 >> 8 ) & 0x0f , V_121 & 0xff ) ;
F_31 ( V_2 -> V_20 , L_39 ,
( unsigned long long ) V_2 -> V_123 , V_2 -> V_5 , V_2 -> V_35 ) ;
V_2 -> V_50 = 1 ;
F_64 ( V_2 -> V_51 ) ;
F_82 ( V_2 -> V_51 ) ;
return 0 ;
V_139:
F_83 ( V_2 -> V_51 ) ;
V_127:
F_84 ( V_2 -> V_52 ) ;
V_125:
F_85 ( V_2 -> V_5 ) ;
V_124:
F_26 ( V_2 -> V_20 , L_40 ,
( unsigned long long ) V_2 -> V_123 ) ;
return - V_142 ;
}
static void T_8 F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 ) {
F_87 ( V_2 -> V_51 ) ;
F_83 ( V_2 -> V_51 ) ;
}
if ( V_2 -> V_52 )
F_84 ( V_2 -> V_52 ) ;
F_88 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_35 )
F_89 ( V_2 -> V_35 , V_2 ) ;
F_85 ( V_2 -> V_5 ) ;
}
static int T_7
F_90 ( struct V_143 * V_20 , int V_30 , T_9 V_123 ,
int V_35 , int V_134 )
{
struct V_1 * V_2 ;
int V_122 ;
F_31 ( V_20 , L_41 , V_20 ) ;
if ( ! V_123 ) {
V_122 = - V_144 ;
goto V_145;
}
V_2 = F_91 ( sizeof( struct V_1 ) , V_146 ) ;
if ( ! V_2 ) {
V_122 = - V_142 ;
goto V_147;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_123 = V_123 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_134 = V_134 ;
V_122 = F_72 ( V_2 ) ;
if ( V_122 )
goto V_148;
F_92 ( V_20 , V_2 ) ;
return 0 ;
V_148:
F_92 ( V_20 , NULL ) ;
F_93 ( V_2 ) ;
V_147:
V_145:
F_46 ( V_20 , L_42 , V_122 ) ;
return V_122 ;
}
static void T_8 F_94 ( struct V_143 * V_20 )
{
struct V_1 * V_2 = F_95 ( V_20 ) ;
F_31 ( V_20 , L_43 , V_20 ) ;
if ( V_2 ) {
F_86 ( V_2 ) ;
F_92 ( V_20 , NULL ) ;
F_93 ( V_2 ) ;
}
}
static int T_7 F_96 ( struct V_149 * V_20 )
{
T_9 V_123 = 0 ;
int V_134 = V_135 ;
T_4 V_30 = V_20 -> V_30 ;
int V_35 = 0 ;
int V_9 ;
F_31 ( & V_20 -> V_20 , L_44 , V_20 ) ;
F_97 ( V_20 -> V_20 . V_150 , L_45 , & V_30 ) ;
if ( V_30 < 0 )
V_30 = 0 ;
if ( F_98 ( V_20 -> V_20 . V_150 , L_46 , NULL ) )
V_134 = V_151 ;
for ( V_9 = 0 ; V_9 < V_20 -> V_152 ; V_9 ++ ) {
if ( V_20 -> V_153 [ V_9 ] . V_91 & V_154 )
V_123 = V_20 -> V_153 [ V_9 ] . V_155 ;
if ( V_20 -> V_153 [ V_9 ] . V_91 & V_156 )
V_35 = V_20 -> V_153 [ V_9 ] . V_155 ;
}
return F_90 ( & V_20 -> V_20 , V_30 , V_123 , V_35 , V_134 ) ;
}
static int T_8 F_99 ( struct V_149 * V_20 )
{
F_94 ( & V_20 -> V_20 ) ;
return 0 ;
}
static int T_10 F_100 ( void )
{
int V_122 ;
V_129 = F_101 ( V_129 , L_47 ) ;
if ( V_129 <= 0 ) {
V_122 = - V_142 ;
goto V_157;
}
V_122 = F_102 ( & V_158 ) ;
if ( V_122 )
goto V_159;
F_103 ( L_48 , V_129 ) ;
return 0 ;
V_159:
F_104 ( V_129 , L_47 ) ;
V_157:
F_24 ( V_160 L_49 , V_122 ) ;
return V_122 ;
}
static void T_11 F_105 ( void )
{
F_106 ( L_50 ) ;
F_107 ( & V_158 ) ;
F_104 ( V_129 , L_47 ) ;
}
