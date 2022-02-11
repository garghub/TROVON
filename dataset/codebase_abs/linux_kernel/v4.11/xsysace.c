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
static void F_27 ( T_1 * V_30 )
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
static struct V_36 * F_34 ( struct V_37 * V_38 )
{
struct V_36 * V_39 ;
while ( ( V_39 = F_35 ( V_38 ) ) != NULL ) {
if ( ! F_36 ( V_39 ) )
break;
F_37 ( V_39 ) ;
F_38 ( V_39 , - V_40 ) ;
}
return V_39 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_36 * V_39 ;
T_4 V_41 ;
T_1 V_6 ;
int V_42 ;
#if F_28 ( V_43 )
F_31 ( V_2 -> V_20 , L_11 ,
V_2 -> V_44 , V_2 -> V_45 ) ;
#endif
V_41 = F_20 ( V_2 , V_24 ) ;
if ( ( V_41 & V_46 ) == 0 ) {
V_2 -> V_44 = V_47 ;
V_2 -> V_48 = 1 ;
F_40 ( V_2 -> V_49 , 0 ) ;
F_26 ( V_2 -> V_20 , L_12 ) ;
if ( V_2 -> V_39 ) {
F_38 ( V_2 -> V_39 , - V_40 ) ;
V_2 -> V_39 = NULL ;
}
while ( ( V_39 = F_41 ( V_2 -> V_50 ) ) != NULL )
F_38 ( V_39 , - V_40 ) ;
V_2 -> V_44 = V_47 ;
V_2 -> V_51 = - V_40 ;
while ( V_2 -> V_45 ) {
F_42 ( & V_2 -> V_52 ) ;
V_2 -> V_45 -- ;
}
}
switch ( V_2 -> V_44 ) {
case V_47 :
if ( V_2 -> V_45 || F_34 ( V_2 -> V_50 ) ) {
V_2 -> V_53 ++ ;
V_2 -> V_44 = V_54 ;
F_43 ( & V_2 -> V_55 , V_56 + V_57 ) ;
if ( ! F_44 ( & V_2 -> V_55 ) )
F_45 ( & V_2 -> V_55 ) ;
break;
}
F_46 ( & V_2 -> V_55 ) ;
V_2 -> V_34 = 0 ;
break;
case V_54 :
if ( F_19 ( V_2 , V_24 ) & V_58 ) {
V_2 -> V_44 = V_59 ;
break;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_60 ) ;
V_2 -> V_44 = V_61 ;
break;
case V_61 :
if ( F_19 ( V_2 , V_24 ) & V_58 ) {
V_2 -> V_44 = V_59 ;
break;
}
F_30 ( V_2 ) ;
break;
case V_59 :
V_41 = F_20 ( V_2 , V_24 ) ;
if ( ! ( V_41 & V_62 ) ||
( V_41 & V_63 ) ) {
F_30 ( V_2 ) ;
break;
}
if ( V_2 -> V_45 )
V_2 -> V_44 = V_64 ;
else
V_2 -> V_44 = V_65 ;
break;
case V_64 :
V_2 -> V_66 = V_67 ;
V_2 -> V_8 = V_2 -> V_68 ;
V_2 -> V_69 = V_70 ;
F_21 ( V_2 , V_22 , V_71 ) ;
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_72 ) ;
V_2 -> V_44 = V_73 ;
F_33 ( V_2 ) ;
break;
case V_73 :
V_41 = F_20 ( V_2 , V_24 ) ;
if ( V_41 & V_63 ) {
F_31 ( V_2 -> V_20 , L_13 ,
V_2 -> V_66 , V_2 -> V_53 ,
V_2 -> V_69 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_41 & V_74 ) ) {
F_30 ( V_2 ) ;
break;
}
V_2 -> V_12 -> V_75 ( V_2 ) ;
V_2 -> V_69 -- ;
if ( V_2 -> V_69 != 0 ) {
F_33 ( V_2 ) ;
break;
}
F_31 ( V_2 -> V_20 , L_14 ) ;
V_2 -> V_44 = V_76 ;
break;
case V_76 :
F_27 ( V_2 -> V_68 ) ;
F_23 ( V_2 -> V_68 , 512 ) ;
if ( V_2 -> V_77 ) {
V_2 -> V_48 = 1 ;
F_40 ( V_2 -> V_49 , 0 ) ;
F_47 ( V_2 -> V_20 , L_15 ,
V_2 -> V_77 ) ;
} else {
V_2 -> V_48 = 0 ;
F_40 ( V_2 -> V_49 ,
F_48 ( V_2 -> V_68 , V_78 ) ) ;
F_26 ( V_2 -> V_20 , L_16 ,
F_48 ( V_2 -> V_68 , V_78 ) ) ;
}
V_2 -> V_44 = V_47 ;
V_2 -> V_51 = V_2 -> V_77 ;
while ( V_2 -> V_45 ) {
F_42 ( & V_2 -> V_52 ) ;
V_2 -> V_45 -- ;
}
break;
case V_65 :
V_39 = F_34 ( V_2 -> V_50 ) ;
if ( ! V_39 ) {
V_2 -> V_44 = V_47 ;
break;
}
F_37 ( V_39 ) ;
F_31 ( V_2 -> V_20 ,
L_17 ,
( unsigned long long ) F_49 ( V_39 ) ,
F_50 ( V_39 ) , F_51 ( V_39 ) ,
F_52 ( V_39 ) ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_8 = F_53 ( V_39 -> V_79 ) ;
V_2 -> V_69 = F_51 ( V_39 ) * V_70 ;
F_22 ( V_2 , V_25 , F_49 ( V_39 ) & 0x0FFFFFFF ) ;
V_42 = F_50 ( V_39 ) ;
if ( F_52 ( V_39 ) ) {
F_31 ( V_2 -> V_20 , L_18 ) ;
V_2 -> V_66 = V_80 ;
F_21 ( V_2 , V_22 ,
V_42 | V_81 ) ;
} else {
F_31 ( V_2 -> V_20 , L_19 ) ;
V_2 -> V_66 = V_82 ;
F_21 ( V_2 , V_22 ,
V_42 | V_83 ) ;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_72 ) ;
V_2 -> V_44 = V_84 ;
if ( V_2 -> V_66 == V_82 )
F_33 ( V_2 ) ;
break;
case V_84 :
V_41 = F_20 ( V_2 , V_24 ) ;
if ( V_41 & V_63 ) {
F_31 ( V_2 -> V_20 ,
L_20 ,
V_2 -> V_66 , V_2 -> V_53 ,
F_51 ( V_2 -> V_39 ) * 16 ,
V_2 -> V_69 , V_2 -> V_85 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_41 & V_74 ) ) {
F_31 ( V_2 -> V_20 ,
L_21 ,
V_2 -> V_66 , V_2 -> V_53 ,
F_51 ( V_2 -> V_39 ) * 16 ,
V_2 -> V_69 , V_2 -> V_85 ) ;
F_33 ( V_2 ) ;
break;
}
if ( V_2 -> V_66 == V_80 )
V_2 -> V_12 -> V_86 ( V_2 ) ;
else
V_2 -> V_12 -> V_75 ( V_2 ) ;
V_2 -> V_69 -- ;
if ( V_2 -> V_69 != 0 ) {
F_33 ( V_2 ) ;
break;
}
if ( F_54 ( V_2 -> V_39 , 0 ) ) {
V_2 -> V_8 = F_53 ( V_2 -> V_39 -> V_79 ) ;
V_2 -> V_69 = F_51 ( V_2 -> V_39 ) * 16 ;
F_33 ( V_2 ) ;
break;
}
V_2 -> V_44 = V_87 ;
break;
case V_87 :
V_2 -> V_39 = NULL ;
V_2 -> V_44 = V_47 ;
break;
default:
V_2 -> V_44 = V_47 ;
break;
}
}
static void F_55 ( unsigned long V_88 )
{
struct V_1 * V_2 = ( void * ) V_88 ;
unsigned long V_89 ;
F_56 ( & V_2 -> V_90 , V_89 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_39 ( V_2 ) ;
F_57 ( & V_2 -> V_90 , V_89 ) ;
}
static void F_58 ( unsigned long V_88 )
{
struct V_1 * V_2 = ( void * ) V_88 ;
unsigned long V_89 ;
F_59 ( V_2 -> V_20 ,
L_22 ,
V_2 -> V_44 , V_2 -> V_66 , V_2 -> V_53 ,
V_2 -> V_69 ) ;
F_56 ( & V_2 -> V_90 , V_89 ) ;
F_43 ( & V_2 -> V_55 , V_56 + V_57 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_39 ( V_2 ) ;
F_57 ( & V_2 -> V_90 , V_89 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_4 V_91 = F_20 ( V_2 , V_24 ) ;
T_1 V_92 = F_19 ( V_2 , V_21 ) ;
if ( ( V_91 & ( V_93 | V_94 ) ) &&
( V_92 & V_95 ) ) {
F_47 ( V_2 -> V_20 , L_23 ) ;
F_25 ( V_2 ) ;
return - V_40 ;
}
return 0 ;
}
static T_5 F_61 ( int V_35 , void * V_96 )
{
T_1 V_92 ;
struct V_1 * V_2 = V_96 ;
F_62 ( & V_2 -> V_90 ) ;
V_2 -> V_85 = 1 ;
V_92 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_92 | V_97 ) ;
F_21 ( V_2 , V_21 , V_92 ) ;
if ( F_60 ( V_2 ) )
V_2 -> V_77 = - V_40 ;
if ( V_2 -> V_66 == 0 ) {
F_47 ( V_2 -> V_20 ,
L_24 ,
F_20 ( V_2 , V_24 ) , F_20 ( V_2 , V_21 ) ,
F_19 ( V_2 , V_22 ) ) ;
F_47 ( V_2 -> V_20 , L_25 ,
V_2 -> V_66 , V_2 -> V_44 , V_2 -> V_69 ) ;
}
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_39 ( V_2 ) ;
V_2 -> V_85 = 0 ;
F_63 ( & V_2 -> V_90 ) ;
return V_98 ;
}
static void F_64 ( struct V_37 * V_38 )
{
struct V_36 * V_39 ;
struct V_1 * V_2 ;
V_39 = F_34 ( V_38 ) ;
if ( V_39 ) {
V_2 = V_39 -> V_99 -> V_100 ;
F_32 ( & V_2 -> V_33 ) ;
}
}
static unsigned int F_65 ( struct V_101 * V_49 , unsigned int V_102 )
{
struct V_1 * V_2 = V_49 -> V_100 ;
F_31 ( V_2 -> V_20 , L_26 , V_2 -> V_48 ) ;
return V_2 -> V_48 ? V_103 : 0 ;
}
static int F_66 ( struct V_101 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_100 ;
unsigned long V_89 ;
F_31 ( V_2 -> V_20 , L_27 ) ;
if ( V_2 -> V_48 ) {
F_31 ( V_2 -> V_20 , L_28 ) ;
F_56 ( & V_2 -> V_90 , V_89 ) ;
V_2 -> V_45 ++ ;
F_57 ( & V_2 -> V_90 , V_89 ) ;
F_32 ( & V_2 -> V_33 ) ;
F_67 ( & V_2 -> V_52 ) ;
}
F_31 ( V_2 -> V_20 , L_29 ) ;
return V_2 -> V_51 ;
}
static int F_68 ( struct V_104 * V_105 , T_6 V_106 )
{
struct V_1 * V_2 = V_105 -> V_107 -> V_100 ;
unsigned long V_89 ;
F_31 ( V_2 -> V_20 , L_30 , V_2 -> V_108 + 1 ) ;
F_69 ( & V_109 ) ;
F_56 ( & V_2 -> V_90 , V_89 ) ;
V_2 -> V_108 ++ ;
F_57 ( & V_2 -> V_90 , V_89 ) ;
F_70 ( V_105 ) ;
F_71 ( & V_109 ) ;
return 0 ;
}
static void F_72 ( struct V_101 * V_110 , T_6 V_106 )
{
struct V_1 * V_2 = V_110 -> V_100 ;
unsigned long V_89 ;
T_1 V_6 ;
F_31 ( V_2 -> V_20 , L_31 , V_2 -> V_108 - 1 ) ;
F_69 ( & V_109 ) ;
F_56 ( & V_2 -> V_90 , V_89 ) ;
V_2 -> V_108 -- ;
if ( V_2 -> V_108 == 0 ) {
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 & ~ V_60 ) ;
}
F_57 ( & V_2 -> V_90 , V_89 ) ;
F_71 ( & V_109 ) ;
}
static int F_73 ( struct V_104 * V_105 , struct V_111 * V_112 )
{
struct V_1 * V_2 = V_105 -> V_107 -> V_100 ;
T_1 * V_68 = V_2 -> V_68 ;
F_31 ( V_2 -> V_20 , L_32 ) ;
V_112 -> V_113 = V_68 [ V_114 ] ;
V_112 -> V_115 = V_68 [ V_116 ] ;
V_112 -> V_117 = V_68 [ V_118 ] ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_1 V_119 ;
T_1 V_6 ;
int V_120 ;
F_31 ( V_2 -> V_20 , L_33 , V_2 ) ;
F_31 ( V_2 -> V_20 , L_34 ,
( unsigned long long ) V_2 -> V_121 , V_2 -> V_35 ) ;
F_75 ( & V_2 -> V_90 ) ;
F_76 ( & V_2 -> V_52 ) ;
V_2 -> V_5 = F_77 ( V_2 -> V_121 , 0x80 ) ;
if ( ! V_2 -> V_5 )
goto V_122;
F_78 ( & V_2 -> V_33 , F_55 , ( unsigned long ) V_2 ) ;
F_79 ( & V_2 -> V_55 , F_58 , ( unsigned long ) V_2 ) ;
V_2 -> V_50 = F_80 ( F_64 , & V_2 -> V_90 ) ;
if ( V_2 -> V_50 == NULL )
goto V_123;
F_81 ( V_2 -> V_50 , 512 ) ;
V_2 -> V_49 = F_82 ( V_124 ) ;
if ( ! V_2 -> V_49 )
goto V_125;
V_2 -> V_49 -> V_126 = V_127 ;
V_2 -> V_49 -> V_128 = V_2 -> V_30 * V_124 ;
V_2 -> V_49 -> V_129 = & V_130 ;
V_2 -> V_49 -> V_50 = V_2 -> V_50 ;
V_2 -> V_49 -> V_100 = V_2 ;
snprintf ( V_2 -> V_49 -> V_131 , 32 , L_35 , V_2 -> V_30 + 'a' ) ;
if ( V_2 -> V_132 == V_133 ) {
F_16 ( V_2 , V_26 , 0x0101 ) ;
if ( F_15 ( V_2 , V_26 ) == 0x0001 )
V_2 -> V_12 = & V_134 ;
else
V_2 -> V_12 = & V_135 ;
} else {
F_3 ( V_2 , V_26 , 0x00 ) ;
V_2 -> V_12 = & V_136 ;
}
V_119 = F_19 ( V_2 , V_23 ) ;
if ( ( V_119 == 0 ) || ( V_119 == 0xFFFF ) )
goto V_137;
F_21 ( V_2 , V_21 , V_138 |
V_139 | V_95 ) ;
if ( V_2 -> V_35 ) {
V_120 = F_83 ( V_2 -> V_35 , F_61 , 0 , L_36 , V_2 ) ;
if ( V_120 ) {
F_47 ( V_2 -> V_20 , L_37 ) ;
V_2 -> V_35 = 0 ;
}
}
V_6 = F_19 ( V_2 , V_21 ) ;
V_6 |= V_139 | V_95 ;
F_21 ( V_2 , V_21 , V_6 ) ;
F_26 ( V_2 -> V_20 , L_38 ,
( V_119 >> 12 ) & 0xf , ( V_119 >> 8 ) & 0x0f , V_119 & 0xff ) ;
F_31 ( V_2 -> V_20 , L_39 ,
( unsigned long long ) V_2 -> V_121 , V_2 -> V_5 , V_2 -> V_35 ) ;
V_2 -> V_48 = 1 ;
F_66 ( V_2 -> V_49 ) ;
F_84 ( V_2 -> V_49 ) ;
return 0 ;
V_137:
F_85 ( V_2 -> V_49 ) ;
V_125:
F_86 ( V_2 -> V_50 ) ;
V_123:
F_87 ( V_2 -> V_5 ) ;
V_122:
F_26 ( V_2 -> V_20 , L_40 ,
( unsigned long long ) V_2 -> V_121 ) ;
return - V_140 ;
}
static void F_88 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 ) {
F_89 ( V_2 -> V_49 ) ;
F_85 ( V_2 -> V_49 ) ;
}
if ( V_2 -> V_50 )
F_86 ( V_2 -> V_50 ) ;
F_90 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_35 )
F_91 ( V_2 -> V_35 , V_2 ) ;
F_87 ( V_2 -> V_5 ) ;
}
static int F_92 ( struct V_141 * V_20 , int V_30 , T_7 V_121 ,
int V_35 , int V_132 )
{
struct V_1 * V_2 ;
int V_120 ;
F_31 ( V_20 , L_41 , V_20 ) ;
if ( ! V_121 ) {
V_120 = - V_142 ;
goto V_143;
}
V_2 = F_93 ( sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_2 ) {
V_120 = - V_140 ;
goto V_145;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_121 = V_121 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_132 = V_132 ;
V_120 = F_74 ( V_2 ) ;
if ( V_120 )
goto V_146;
F_94 ( V_20 , V_2 ) ;
return 0 ;
V_146:
F_94 ( V_20 , NULL ) ;
F_95 ( V_2 ) ;
V_145:
V_143:
F_47 ( V_20 , L_42 , V_120 ) ;
return V_120 ;
}
static void F_96 ( struct V_141 * V_20 )
{
struct V_1 * V_2 = F_97 ( V_20 ) ;
F_31 ( V_20 , L_43 , V_20 ) ;
if ( V_2 ) {
F_88 ( V_2 ) ;
F_94 ( V_20 , NULL ) ;
F_95 ( V_2 ) ;
}
}
static int F_98 ( struct V_147 * V_20 )
{
T_7 V_121 = 0 ;
int V_132 = V_133 ;
T_4 V_30 = V_20 -> V_30 ;
int V_35 = 0 ;
int V_9 ;
F_31 ( & V_20 -> V_20 , L_44 , V_20 ) ;
if ( F_99 ( V_20 -> V_20 . V_148 , L_45 , & V_30 ) )
V_30 = 0 ;
if ( F_100 ( V_20 -> V_20 . V_148 , L_46 , NULL ) )
V_132 = V_149 ;
for ( V_9 = 0 ; V_9 < V_20 -> V_150 ; V_9 ++ ) {
if ( V_20 -> V_151 [ V_9 ] . V_89 & V_152 )
V_121 = V_20 -> V_151 [ V_9 ] . V_153 ;
if ( V_20 -> V_151 [ V_9 ] . V_89 & V_154 )
V_35 = V_20 -> V_151 [ V_9 ] . V_153 ;
}
return F_92 ( & V_20 -> V_20 , V_30 , V_121 , V_35 , V_132 ) ;
}
static int F_101 ( struct V_147 * V_20 )
{
F_96 ( & V_20 -> V_20 ) ;
return 0 ;
}
static int T_8 F_102 ( void )
{
int V_120 ;
V_127 = F_103 ( V_127 , L_47 ) ;
if ( V_127 <= 0 ) {
V_120 = - V_140 ;
goto V_155;
}
V_120 = F_104 ( & V_156 ) ;
if ( V_120 )
goto V_157;
F_105 ( L_48 , V_127 ) ;
return 0 ;
V_157:
F_106 ( V_127 , L_47 ) ;
V_155:
F_24 ( V_158 L_49 , V_120 ) ;
return V_120 ;
}
static void T_9 F_107 ( void )
{
F_108 ( L_50 ) ;
F_109 ( & V_156 ) ;
F_106 ( V_127 , L_47 ) ;
}
