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
F_38 ( V_39 , V_40 ) ;
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
F_38 ( V_2 -> V_39 , V_40 ) ;
V_2 -> V_39 = NULL ;
}
while ( ( V_39 = F_41 ( V_2 -> V_50 ) ) != NULL )
F_38 ( V_39 , V_40 ) ;
V_2 -> V_44 = V_47 ;
V_2 -> V_51 = - V_52 ;
while ( V_2 -> V_45 ) {
F_42 ( & V_2 -> V_53 ) ;
V_2 -> V_45 -- ;
}
}
switch ( V_2 -> V_44 ) {
case V_47 :
if ( V_2 -> V_45 || F_34 ( V_2 -> V_50 ) ) {
V_2 -> V_54 ++ ;
V_2 -> V_44 = V_55 ;
F_43 ( & V_2 -> V_56 , V_57 + V_58 ) ;
if ( ! F_44 ( & V_2 -> V_56 ) )
F_45 ( & V_2 -> V_56 ) ;
break;
}
F_46 ( & V_2 -> V_56 ) ;
V_2 -> V_34 = 0 ;
break;
case V_55 :
if ( F_19 ( V_2 , V_24 ) & V_59 ) {
V_2 -> V_44 = V_60 ;
break;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_61 ) ;
V_2 -> V_44 = V_62 ;
break;
case V_62 :
if ( F_19 ( V_2 , V_24 ) & V_59 ) {
V_2 -> V_44 = V_60 ;
break;
}
F_30 ( V_2 ) ;
break;
case V_60 :
V_41 = F_20 ( V_2 , V_24 ) ;
if ( ! ( V_41 & V_63 ) ||
( V_41 & V_64 ) ) {
F_30 ( V_2 ) ;
break;
}
if ( V_2 -> V_45 )
V_2 -> V_44 = V_65 ;
else
V_2 -> V_44 = V_66 ;
break;
case V_65 :
V_2 -> V_67 = V_68 ;
V_2 -> V_8 = V_2 -> V_69 ;
V_2 -> V_70 = V_71 ;
F_21 ( V_2 , V_22 , V_72 ) ;
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_73 ) ;
V_2 -> V_44 = V_74 ;
F_33 ( V_2 ) ;
break;
case V_74 :
V_41 = F_20 ( V_2 , V_24 ) ;
if ( V_41 & V_64 ) {
F_31 ( V_2 -> V_20 , L_13 ,
V_2 -> V_67 , V_2 -> V_54 ,
V_2 -> V_70 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_41 & V_75 ) ) {
F_30 ( V_2 ) ;
break;
}
V_2 -> V_12 -> V_76 ( V_2 ) ;
V_2 -> V_70 -- ;
if ( V_2 -> V_70 != 0 ) {
F_33 ( V_2 ) ;
break;
}
F_31 ( V_2 -> V_20 , L_14 ) ;
V_2 -> V_44 = V_77 ;
break;
case V_77 :
F_27 ( V_2 -> V_69 ) ;
F_23 ( V_2 -> V_69 , 512 ) ;
if ( V_2 -> V_78 ) {
V_2 -> V_48 = 1 ;
F_40 ( V_2 -> V_49 , 0 ) ;
F_47 ( V_2 -> V_20 , L_15 ,
V_2 -> V_78 ) ;
} else {
V_2 -> V_48 = 0 ;
F_40 ( V_2 -> V_49 ,
F_48 ( V_2 -> V_69 , V_79 ) ) ;
F_26 ( V_2 -> V_20 , L_16 ,
F_48 ( V_2 -> V_69 , V_79 ) ) ;
}
V_2 -> V_44 = V_47 ;
V_2 -> V_51 = V_2 -> V_78 ;
while ( V_2 -> V_45 ) {
F_42 ( & V_2 -> V_53 ) ;
V_2 -> V_45 -- ;
}
break;
case V_66 :
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
V_2 -> V_8 = F_53 ( V_39 -> V_80 ) ;
V_2 -> V_70 = F_51 ( V_39 ) * V_71 ;
F_22 ( V_2 , V_25 , F_49 ( V_39 ) & 0x0FFFFFFF ) ;
V_42 = F_50 ( V_39 ) ;
if ( F_52 ( V_39 ) ) {
F_31 ( V_2 -> V_20 , L_18 ) ;
V_2 -> V_67 = V_81 ;
F_21 ( V_2 , V_22 ,
V_42 | V_82 ) ;
} else {
F_31 ( V_2 -> V_20 , L_19 ) ;
V_2 -> V_67 = V_83 ;
F_21 ( V_2 , V_22 ,
V_42 | V_84 ) ;
}
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 | V_73 ) ;
V_2 -> V_44 = V_85 ;
if ( V_2 -> V_67 == V_83 )
F_33 ( V_2 ) ;
break;
case V_85 :
V_41 = F_20 ( V_2 , V_24 ) ;
if ( V_41 & V_64 ) {
F_31 ( V_2 -> V_20 ,
L_20 ,
V_2 -> V_67 , V_2 -> V_54 ,
F_51 ( V_2 -> V_39 ) * 16 ,
V_2 -> V_70 , V_2 -> V_86 ) ;
F_30 ( V_2 ) ;
break;
}
if ( ! ( V_41 & V_75 ) ) {
F_31 ( V_2 -> V_20 ,
L_21 ,
V_2 -> V_67 , V_2 -> V_54 ,
F_51 ( V_2 -> V_39 ) * 16 ,
V_2 -> V_70 , V_2 -> V_86 ) ;
F_33 ( V_2 ) ;
break;
}
if ( V_2 -> V_67 == V_81 )
V_2 -> V_12 -> V_87 ( V_2 ) ;
else
V_2 -> V_12 -> V_76 ( V_2 ) ;
V_2 -> V_70 -- ;
if ( V_2 -> V_70 != 0 ) {
F_33 ( V_2 ) ;
break;
}
if ( F_54 ( V_2 -> V_39 , V_88 ) ) {
V_2 -> V_8 = F_53 ( V_2 -> V_39 -> V_80 ) ;
V_2 -> V_70 = F_51 ( V_2 -> V_39 ) * 16 ;
F_33 ( V_2 ) ;
break;
}
V_2 -> V_44 = V_89 ;
break;
case V_89 :
V_2 -> V_39 = NULL ;
V_2 -> V_44 = V_47 ;
break;
default:
V_2 -> V_44 = V_47 ;
break;
}
}
static void F_55 ( unsigned long V_90 )
{
struct V_1 * V_2 = ( void * ) V_90 ;
unsigned long V_91 ;
F_56 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_39 ( V_2 ) ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
}
static void F_58 ( unsigned long V_90 )
{
struct V_1 * V_2 = ( void * ) V_90 ;
unsigned long V_91 ;
F_59 ( V_2 -> V_20 ,
L_22 ,
V_2 -> V_44 , V_2 -> V_67 , V_2 -> V_54 ,
V_2 -> V_70 ) ;
F_56 ( & V_2 -> V_92 , V_91 ) ;
F_43 ( & V_2 -> V_56 , V_57 + V_58 ) ;
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_39 ( V_2 ) ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_4 V_93 = F_20 ( V_2 , V_24 ) ;
T_1 V_94 = F_19 ( V_2 , V_21 ) ;
if ( ( V_93 & ( V_95 | V_96 ) ) &&
( V_94 & V_97 ) ) {
F_47 ( V_2 -> V_20 , L_23 ) ;
F_25 ( V_2 ) ;
return - V_52 ;
}
return 0 ;
}
static T_5 F_61 ( int V_35 , void * V_98 )
{
T_1 V_94 ;
struct V_1 * V_2 = V_98 ;
F_62 ( & V_2 -> V_92 ) ;
V_2 -> V_86 = 1 ;
V_94 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_94 | V_99 ) ;
F_21 ( V_2 , V_21 , V_94 ) ;
if ( F_60 ( V_2 ) )
V_2 -> V_78 = - V_52 ;
if ( V_2 -> V_67 == 0 ) {
F_47 ( V_2 -> V_20 ,
L_24 ,
F_20 ( V_2 , V_24 ) , F_20 ( V_2 , V_21 ) ,
F_19 ( V_2 , V_22 ) ) ;
F_47 ( V_2 -> V_20 , L_25 ,
V_2 -> V_67 , V_2 -> V_44 , V_2 -> V_70 ) ;
}
V_2 -> V_34 = 1 ;
while ( V_2 -> V_34 )
F_39 ( V_2 ) ;
V_2 -> V_86 = 0 ;
F_63 ( & V_2 -> V_92 ) ;
return V_100 ;
}
static void F_64 ( struct V_37 * V_38 )
{
struct V_36 * V_39 ;
struct V_1 * V_2 ;
V_39 = F_34 ( V_38 ) ;
if ( V_39 ) {
V_2 = V_39 -> V_101 -> V_102 ;
F_32 ( & V_2 -> V_33 ) ;
}
}
static unsigned int F_65 ( struct V_103 * V_49 , unsigned int V_104 )
{
struct V_1 * V_2 = V_49 -> V_102 ;
F_31 ( V_2 -> V_20 , L_26 , V_2 -> V_48 ) ;
return V_2 -> V_48 ? V_105 : 0 ;
}
static int F_66 ( struct V_103 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_102 ;
unsigned long V_91 ;
F_31 ( V_2 -> V_20 , L_27 ) ;
if ( V_2 -> V_48 ) {
F_31 ( V_2 -> V_20 , L_28 ) ;
F_56 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_45 ++ ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
F_32 ( & V_2 -> V_33 ) ;
F_67 ( & V_2 -> V_53 ) ;
}
F_31 ( V_2 -> V_20 , L_29 ) ;
return V_2 -> V_51 ;
}
static int F_68 ( struct V_106 * V_107 , T_6 V_108 )
{
struct V_1 * V_2 = V_107 -> V_109 -> V_102 ;
unsigned long V_91 ;
F_31 ( V_2 -> V_20 , L_30 , V_2 -> V_110 + 1 ) ;
F_69 ( & V_111 ) ;
F_56 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_110 ++ ;
F_57 ( & V_2 -> V_92 , V_91 ) ;
F_70 ( V_107 ) ;
F_71 ( & V_111 ) ;
return 0 ;
}
static void F_72 ( struct V_103 * V_112 , T_6 V_108 )
{
struct V_1 * V_2 = V_112 -> V_102 ;
unsigned long V_91 ;
T_1 V_6 ;
F_31 ( V_2 -> V_20 , L_31 , V_2 -> V_110 - 1 ) ;
F_69 ( & V_111 ) ;
F_56 ( & V_2 -> V_92 , V_91 ) ;
V_2 -> V_110 -- ;
if ( V_2 -> V_110 == 0 ) {
V_6 = F_19 ( V_2 , V_21 ) ;
F_21 ( V_2 , V_21 , V_6 & ~ V_61 ) ;
}
F_57 ( & V_2 -> V_92 , V_91 ) ;
F_71 ( & V_111 ) ;
}
static int F_73 ( struct V_106 * V_107 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_107 -> V_109 -> V_102 ;
T_1 * V_69 = V_2 -> V_69 ;
F_31 ( V_2 -> V_20 , L_32 ) ;
V_114 -> V_115 = V_69 [ V_116 ] ;
V_114 -> V_117 = V_69 [ V_118 ] ;
V_114 -> V_119 = V_69 [ V_120 ] ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
T_1 V_121 ;
T_1 V_6 ;
int V_122 ;
F_31 ( V_2 -> V_20 , L_33 , V_2 ) ;
F_31 ( V_2 -> V_20 , L_34 ,
( unsigned long long ) V_2 -> V_123 , V_2 -> V_35 ) ;
F_75 ( & V_2 -> V_92 ) ;
F_76 ( & V_2 -> V_53 ) ;
V_2 -> V_5 = F_77 ( V_2 -> V_123 , 0x80 ) ;
if ( ! V_2 -> V_5 )
goto V_124;
F_78 ( & V_2 -> V_33 , F_55 , ( unsigned long ) V_2 ) ;
F_79 ( & V_2 -> V_56 , F_58 , ( unsigned long ) V_2 ) ;
V_2 -> V_50 = F_80 ( F_64 , & V_2 -> V_92 ) ;
if ( V_2 -> V_50 == NULL )
goto V_125;
F_81 ( V_2 -> V_50 , 512 ) ;
F_82 ( V_2 -> V_50 , V_126 ) ;
V_2 -> V_49 = F_83 ( V_127 ) ;
if ( ! V_2 -> V_49 )
goto V_128;
V_2 -> V_49 -> V_129 = V_130 ;
V_2 -> V_49 -> V_131 = V_2 -> V_30 * V_127 ;
V_2 -> V_49 -> V_132 = & V_133 ;
V_2 -> V_49 -> V_50 = V_2 -> V_50 ;
V_2 -> V_49 -> V_102 = V_2 ;
snprintf ( V_2 -> V_49 -> V_134 , 32 , L_35 , V_2 -> V_30 + 'a' ) ;
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
V_121 = F_19 ( V_2 , V_23 ) ;
if ( ( V_121 == 0 ) || ( V_121 == 0xFFFF ) )
goto V_140;
F_21 ( V_2 , V_21 , V_141 |
V_142 | V_97 ) ;
if ( V_2 -> V_35 ) {
V_122 = F_84 ( V_2 -> V_35 , F_61 , 0 , L_36 , V_2 ) ;
if ( V_122 ) {
F_47 ( V_2 -> V_20 , L_37 ) ;
V_2 -> V_35 = 0 ;
}
}
V_6 = F_19 ( V_2 , V_21 ) ;
V_6 |= V_142 | V_97 ;
F_21 ( V_2 , V_21 , V_6 ) ;
F_26 ( V_2 -> V_20 , L_38 ,
( V_121 >> 12 ) & 0xf , ( V_121 >> 8 ) & 0x0f , V_121 & 0xff ) ;
F_31 ( V_2 -> V_20 , L_39 ,
( unsigned long long ) V_2 -> V_123 , V_2 -> V_5 , V_2 -> V_35 ) ;
V_2 -> V_48 = 1 ;
F_66 ( V_2 -> V_49 ) ;
F_85 ( V_2 -> V_49 ) ;
return 0 ;
V_140:
F_86 ( V_2 -> V_49 ) ;
V_128:
F_87 ( V_2 -> V_50 ) ;
V_125:
F_88 ( V_2 -> V_5 ) ;
V_124:
F_26 ( V_2 -> V_20 , L_40 ,
( unsigned long long ) V_2 -> V_123 ) ;
return - V_143 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 ) {
F_90 ( V_2 -> V_49 ) ;
F_86 ( V_2 -> V_49 ) ;
}
if ( V_2 -> V_50 )
F_87 ( V_2 -> V_50 ) ;
F_91 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_35 )
F_92 ( V_2 -> V_35 , V_2 ) ;
F_88 ( V_2 -> V_5 ) ;
}
static int F_93 ( struct V_144 * V_20 , int V_30 , T_7 V_123 ,
int V_35 , int V_135 )
{
struct V_1 * V_2 ;
int V_122 ;
F_31 ( V_20 , L_41 , V_20 ) ;
if ( ! V_123 ) {
V_122 = - V_145 ;
goto V_146;
}
V_2 = F_94 ( sizeof( struct V_1 ) , V_147 ) ;
if ( ! V_2 ) {
V_122 = - V_143 ;
goto V_148;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_123 = V_123 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_135 = V_135 ;
V_122 = F_74 ( V_2 ) ;
if ( V_122 )
goto V_149;
F_95 ( V_20 , V_2 ) ;
return 0 ;
V_149:
F_95 ( V_20 , NULL ) ;
F_96 ( V_2 ) ;
V_148:
V_146:
F_47 ( V_20 , L_42 , V_122 ) ;
return V_122 ;
}
static void F_97 ( struct V_144 * V_20 )
{
struct V_1 * V_2 = F_98 ( V_20 ) ;
F_31 ( V_20 , L_43 , V_20 ) ;
if ( V_2 ) {
F_89 ( V_2 ) ;
F_95 ( V_20 , NULL ) ;
F_96 ( V_2 ) ;
}
}
static int F_99 ( struct V_150 * V_20 )
{
T_7 V_123 = 0 ;
int V_135 = V_136 ;
T_4 V_30 = V_20 -> V_30 ;
int V_35 = 0 ;
int V_9 ;
F_31 ( & V_20 -> V_20 , L_44 , V_20 ) ;
if ( F_100 ( V_20 -> V_20 . V_151 , L_45 , & V_30 ) )
V_30 = 0 ;
if ( F_101 ( V_20 -> V_20 . V_151 , L_46 , NULL ) )
V_135 = V_152 ;
for ( V_9 = 0 ; V_9 < V_20 -> V_153 ; V_9 ++ ) {
if ( V_20 -> V_154 [ V_9 ] . V_91 & V_155 )
V_123 = V_20 -> V_154 [ V_9 ] . V_156 ;
if ( V_20 -> V_154 [ V_9 ] . V_91 & V_157 )
V_35 = V_20 -> V_154 [ V_9 ] . V_156 ;
}
return F_93 ( & V_20 -> V_20 , V_30 , V_123 , V_35 , V_135 ) ;
}
static int F_102 ( struct V_150 * V_20 )
{
F_97 ( & V_20 -> V_20 ) ;
return 0 ;
}
static int T_8 F_103 ( void )
{
int V_122 ;
V_130 = F_104 ( V_130 , L_47 ) ;
if ( V_130 <= 0 ) {
V_122 = - V_143 ;
goto V_158;
}
V_122 = F_105 ( & V_159 ) ;
if ( V_122 )
goto V_160;
F_106 ( L_48 , V_130 ) ;
return 0 ;
V_160:
F_107 ( V_130 , L_47 ) ;
V_158:
F_24 ( V_161 L_49 , V_122 ) ;
return V_122 ;
}
static void T_9 F_108 ( void )
{
F_109 ( L_50 ) ;
F_110 ( & V_159 ) ;
F_107 ( V_130 , L_47 ) ;
}
