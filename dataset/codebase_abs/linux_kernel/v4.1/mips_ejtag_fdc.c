static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static struct V_6 F_5 ( const char * * V_7 ,
unsigned int * V_8 ,
unsigned int V_9 )
{
struct V_6 V_10 = { 0 , 0 } ;
const char * * V_11 = V_7 + V_9 ;
for (; V_7 < V_11 ; ++ V_7 ) {
const char * V_12 = * ( V_7 ++ ) ;
const char * V_13 = V_12 + * ( V_8 ++ ) ;
for (; V_12 < V_13 ; ++ V_12 ) {
V_10 . V_10 |= ( V_14 ) * V_12 << ( 8 * V_10 . V_15 ) ;
++ V_10 . V_15 ;
if ( V_10 . V_15 == 4 )
goto V_16;
}
}
V_16:
switch ( V_10 . V_15 ) {
case 4 :
if ( ( V_10 . V_10 >> 8 ) != 0x808080 &&
( V_10 . V_10 >> 16 ) != 0x8181 &&
( V_10 . V_10 >> 24 ) != 0x82 )
break;
V_10 . V_15 = 3 ;
V_10 . V_10 &= 0x00ffffff ;
case 3 :
V_10 . V_10 |= 0x82000000 ;
break;
case 2 :
V_10 . V_10 |= 0x81810000 ;
break;
case 1 :
V_10 . V_10 |= 0x80808000 ;
break;
}
return V_10 ;
}
static unsigned int F_6 ( T_1 V_10 , char * V_17 )
{
V_17 [ 0 ] = ( V_14 ) V_10 ;
V_10 >>= 8 ;
if ( V_10 == 0x808080 )
return 1 ;
V_17 [ 1 ] = ( V_14 ) V_10 ;
V_10 >>= 8 ;
if ( V_10 == 0x8181 )
return 2 ;
V_17 [ 2 ] = ( V_14 ) V_10 ;
V_10 >>= 8 ;
if ( V_10 == 0x82 )
return 3 ;
V_17 [ 3 ] = ( V_14 ) V_10 ;
return 4 ;
}
static void F_7 ( struct V_18 * V_19 , const char * V_20 ,
unsigned int V_21 )
{
struct V_22 * V_23 =
F_8 ( V_19 , struct V_22 , V_23 ) ;
void T_2 * V_24 ;
struct V_6 V_10 ;
unsigned long V_25 ;
unsigned int V_26 , V_27 , V_28 ;
bool V_29 = false ;
char V_17 [ 4 ] ;
const char * V_30 = V_17 ;
V_14 V_31 [ 4 ] ;
F_9 ( V_25 ) ;
V_28 = F_10 () ;
V_24 = V_23 -> V_24 [ V_28 ] ;
if ( ! V_24 ) {
V_24 = F_11 ( 0xfd ) ;
V_23 -> V_24 [ V_28 ] = V_24 ;
}
if ( F_12 ( V_24 ) )
goto V_32;
while ( V_21 ) {
for ( V_27 = 0 , V_26 = 0 ; V_27 < 4 && V_26 < V_21 ; ++ V_27 ) {
if ( V_20 [ V_26 ] == '\n' && ! V_29 ) {
V_17 [ V_27 ] = '\r' ;
V_29 = true ;
} else {
V_17 [ V_27 ] = V_20 [ V_26 ] ;
V_29 = false ;
++ V_26 ;
}
V_31 [ V_27 ] = V_26 ;
}
V_10 = F_5 ( & V_30 , & V_27 , 1 ) ;
V_21 -= V_31 [ V_10 . V_15 - 1 ] ;
V_20 += V_31 [ V_10 . V_15 - 1 ] ;
while ( F_4 ( V_24 + V_33 ) & V_34 )
;
F_2 ( V_10 . V_10 , V_24 + F_13 ( V_19 -> V_35 ) ) ;
}
V_32:
F_14 ( V_25 ) ;
}
static struct V_36 * F_15 ( struct V_18 * V_19 ,
int * V_35 )
{
struct V_22 * V_23 =
F_8 ( V_19 , struct V_22 , V_23 ) ;
* V_35 = V_19 -> V_35 ;
return V_23 -> V_37 ;
}
static int T_3 F_16 ( struct V_22 * V_19 )
{
void T_2 * V_24 ;
unsigned long V_25 ;
int V_38 = 0 ;
F_17 ( & V_19 -> V_39 , V_25 ) ;
if ( V_19 -> V_40 )
goto V_32;
V_24 = F_11 ( 0xfd ) ;
if ( F_12 ( V_24 ) ) {
V_38 = F_18 ( V_24 ) ;
goto V_32;
}
V_19 -> V_40 = true ;
V_19 -> V_24 [ F_10 () ] = V_24 ;
F_19 ( & V_19 -> V_23 ) ;
V_32:
F_20 ( & V_19 -> V_39 , V_25 ) ;
return V_38 ;
}
static unsigned int F_21 ( struct V_1 * V_2 ,
unsigned int V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
const char * V_7 [ 2 ] ;
unsigned int V_8 [ 2 ] = { 0 } ;
struct V_6 V_10 = { . V_15 = 0 } ;
unsigned long V_25 ;
V_43 = & V_2 -> V_46 [ V_41 ] ;
F_22 ( & V_43 -> V_47 ) ;
if ( V_43 -> V_48 ) {
V_7 [ 0 ] = V_43 -> V_49 . V_50 + V_43 -> V_51 ;
V_8 [ 0 ] = F_23 (unsigned int,
priv->xmit_size - dport->xmit_tail,
dport->xmit_cnt) ;
V_7 [ 1 ] = V_43 -> V_49 . V_50 ;
V_8 [ 1 ] = V_43 -> V_48 - V_8 [ 0 ] ;
V_10 = F_5 ( V_7 , V_8 , 1 + ! ! V_8 [ 1 ] ) ;
F_24 ( V_2 -> V_52 , L_1 ,
V_2 -> V_53 , V_41 , V_10 . V_10 ,
F_23 ( int , V_10 . V_15 , V_8 [ 0 ] ) , V_7 [ 0 ] ,
F_25 ( int , 0 , V_10 . V_15 - V_8 [ 0 ] ) , V_7 [ 1 ] ) ;
F_9 ( V_25 ) ;
if ( F_3 ( V_2 , V_33 ) & V_34 )
V_10 . V_15 = 0 ;
else
F_1 ( V_2 , F_13 ( V_41 ) , V_10 . V_10 ) ;
F_14 ( V_25 ) ;
V_43 -> V_48 -= V_10 . V_15 ;
if ( ! V_43 -> V_48 ) {
V_43 -> V_54 = 0 ;
V_43 -> V_51 = 0 ;
F_26 ( & V_43 -> V_55 ) ;
} else {
V_43 -> V_51 += V_10 . V_15 ;
if ( V_43 -> V_51 >= V_2 -> V_56 )
V_43 -> V_51 -= V_2 -> V_56 ;
}
F_27 ( V_10 . V_15 , & V_2 -> V_57 ) ;
}
F_28 ( & V_43 -> V_47 ) ;
if ( V_8 [ 0 ] && V_10 . V_15 ) {
V_45 = F_29 ( & V_43 -> V_49 ) ;
if ( V_45 ) {
F_30 ( V_45 ) ;
F_31 ( V_45 ) ;
}
}
return V_10 . V_15 ;
}
static int F_32 ( void * V_58 )
{
struct V_1 * V_2 = V_58 ;
struct V_42 * V_43 ;
unsigned int V_38 ;
T_1 V_59 ;
F_33 ( V_60 ) ;
while ( ! F_34 () ) {
F_35 ( V_2 -> V_61 ,
F_36 ( & V_2 -> V_57 ) ||
F_34 () ) ;
if ( F_34 () )
break;
F_37 ( & V_2 -> V_39 ) ;
if ( F_3 ( V_2 , V_33 ) & V_34 ) {
V_2 -> V_62 = true ;
if ( V_2 -> V_63 >= 0 ) {
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ V_65 ;
V_59 |= V_66 ;
F_1 ( V_2 , V_64 , V_59 ) ;
}
}
F_38 ( & V_2 -> V_39 ) ;
F_35 ( V_2 -> V_61 ,
! ( F_3 ( V_2 , V_33 )
& V_34 ) ||
F_34 () ) ;
if ( F_34 () )
break;
for (; ; ) {
V_43 = & V_2 -> V_46 [ V_2 -> V_67 ] ;
F_22 ( & V_43 -> V_47 ) ;
V_38 = V_43 -> V_48 ;
F_28 ( & V_43 -> V_47 ) ;
if ( V_38 )
break;
++ V_2 -> V_67 ;
if ( V_2 -> V_67 >= V_68 )
V_2 -> V_67 = 0 ;
}
V_38 = F_21 ( V_2 , V_2 -> V_67 ) ;
if ( V_38 ) {
++ V_2 -> V_67 ;
if ( V_2 -> V_67 >= V_68 )
V_2 -> V_67 = 0 ;
}
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
unsigned int V_69 , V_70 , V_4 , V_59 , V_26 , V_71 ;
int V_72 ;
char V_17 [ 4 ] ;
for (; ; ) {
V_69 = F_3 ( V_2 , V_33 ) ;
if ( V_69 & V_73 )
break;
V_70 = ( V_69 & V_74 ) >> V_75 ;
V_43 = & V_2 -> V_46 [ V_70 ] ;
F_40 ( & V_43 -> V_76 ) ;
V_4 = F_3 ( V_2 , V_77 ) ;
V_72 = F_6 ( V_4 , V_17 ) ;
F_24 ( V_2 -> V_52 , L_2 ,
V_2 -> V_53 , V_70 , V_4 , V_72 , V_17 ) ;
V_71 = 0 ;
for ( V_26 = 0 ; V_26 < V_72 ; ++ V_26 ) {
#ifdef F_41
#ifdef F_42
if ( V_70 == V_78 ) {
if ( V_17 [ V_26 ] == '\x03' ) {
F_43 ( 'g' ) ;
continue;
}
}
#endif
if ( V_70 == V_79 . V_23 . V_35 ) {
if ( V_17 [ V_26 ] == '\x0f' ) {
V_2 -> V_80 =
! V_2 -> V_80 ;
if ( V_2 -> V_80 )
continue;
} else if ( V_2 -> V_80 ) {
F_43 ( V_17 [ V_26 ] ) ;
V_2 -> V_80 = false ;
continue;
}
}
#endif
if ( ! V_43 -> V_81 )
continue;
V_71 += F_44 ( & V_43 -> V_49 , V_17 [ V_26 ] ,
V_82 ) ;
}
if ( V_71 )
F_45 ( & V_43 -> V_49 ) ;
F_46 ( & V_43 -> V_76 ) ;
}
F_40 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_62 && ! ( V_69 & V_34 ) ) {
V_2 -> V_62 = false ;
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ V_65 ;
V_59 |= V_83 ;
F_1 ( V_2 , V_64 , V_59 ) ;
F_47 ( & V_2 -> V_61 ) ;
}
F_46 ( & V_2 -> V_39 ) ;
}
static T_4 F_48 ( int V_63 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
if ( F_10 () != V_2 -> V_28 )
return V_85 ;
if ( ! ( F_49 () & V_86 ) )
return V_85 ;
F_39 ( V_2 ) ;
return V_87 ;
}
static void F_50 ( unsigned long V_88 )
{
struct V_1 * V_2 = ( void * ) V_88 ;
F_39 ( V_2 ) ;
if ( ! V_2 -> V_89 )
F_51 ( & V_2 -> V_90 , V_91 + V_92 ) ;
}
static int F_52 ( struct V_93 * V_49 ,
struct V_44 * V_45 )
{
struct V_42 * V_43 =
F_8 ( V_49 , struct V_42 , V_49 ) ;
void * V_81 ;
if ( F_53 ( V_49 ) < 0 )
goto V_94;
V_81 = F_54 ( V_95 , V_96 ) ;
if ( ! V_81 )
goto V_97;
F_37 ( & V_43 -> V_76 ) ;
V_43 -> V_81 = V_81 ;
F_38 ( & V_43 -> V_76 ) ;
return 0 ;
V_97:
F_55 ( V_49 ) ;
V_94:
return - V_98 ;
}
static void F_56 ( struct V_93 * V_49 )
{
struct V_42 * V_43 =
F_8 ( V_49 , struct V_42 , V_49 ) ;
struct V_1 * V_2 = V_43 -> V_99 ;
void * V_81 ;
unsigned int V_21 ;
F_22 ( & V_43 -> V_47 ) ;
V_21 = V_43 -> V_48 ;
F_28 ( & V_43 -> V_47 ) ;
if ( V_21 ) {
F_47 ( & V_2 -> V_61 ) ;
F_57 ( & V_43 -> V_55 ) ;
}
F_37 ( & V_43 -> V_76 ) ;
V_81 = V_43 -> V_81 ;
V_43 -> V_81 = NULL ;
F_38 ( & V_43 -> V_76 ) ;
F_58 ( V_81 ) ;
F_55 ( V_49 ) ;
}
static int F_59 ( struct V_36 * V_99 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_99 -> V_100 ;
V_45 -> V_101 = & V_2 -> V_46 [ V_45 -> V_35 ] ;
return F_60 ( & V_2 -> V_46 [ V_45 -> V_35 ] . V_49 , V_99 , V_45 ) ;
}
static int F_61 ( struct V_44 * V_45 , struct V_102 * V_103 )
{
return F_62 ( V_45 -> V_49 , V_45 , V_103 ) ;
}
static void F_63 ( struct V_44 * V_45 , struct V_102 * V_103 )
{
return F_64 ( V_45 -> V_49 , V_45 , V_103 ) ;
}
static void F_65 ( struct V_44 * V_45 )
{
struct V_42 * V_43 = V_45 -> V_101 ;
struct V_1 * V_2 = V_43 -> V_99 ;
F_22 ( & V_43 -> V_47 ) ;
if ( V_43 -> V_48 ) {
F_27 ( V_43 -> V_48 , & V_2 -> V_57 ) ;
V_43 -> V_48 = 0 ;
V_43 -> V_54 = 0 ;
V_43 -> V_51 = 0 ;
F_26 ( & V_43 -> V_55 ) ;
}
F_28 ( & V_43 -> V_47 ) ;
F_66 ( V_45 -> V_49 ) ;
}
static int F_67 ( struct V_44 * V_45 ,
const unsigned char * V_17 , int V_104 )
{
int V_21 , V_105 ;
struct V_42 * V_43 = V_45 -> V_101 ;
struct V_1 * V_2 = V_43 -> V_99 ;
F_22 ( & V_43 -> V_47 ) ;
V_104 = F_68 ( V_104 , ( int ) ( V_2 -> V_56 - V_43 -> V_48 ) ) ;
F_69 ( V_104 , & V_2 -> V_57 ) ;
V_43 -> V_48 += V_104 ;
for ( V_21 = V_104 ; V_21 ; V_21 -= V_105 ) {
V_105 = F_68 ( V_21 , ( int ) ( V_2 -> V_56 - V_43 -> V_54 ) ) ;
memcpy ( V_43 -> V_49 . V_50 + V_43 -> V_54 , V_17 , V_105 ) ;
V_43 -> V_54 += V_105 ;
if ( V_43 -> V_54 >= V_2 -> V_56 )
V_43 -> V_54 -= V_2 -> V_56 ;
V_17 += V_105 ;
}
V_21 = V_43 -> V_48 ;
if ( V_21 )
F_70 ( & V_43 -> V_55 ) ;
F_28 ( & V_43 -> V_47 ) ;
if ( V_104 )
F_47 ( & V_2 -> V_61 ) ;
return V_104 ;
}
static int F_71 ( struct V_44 * V_45 )
{
struct V_42 * V_43 = V_45 -> V_101 ;
struct V_1 * V_2 = V_43 -> V_99 ;
int V_106 ;
F_22 ( & V_43 -> V_47 ) ;
V_106 = V_2 -> V_56 - V_43 -> V_48 ;
F_28 ( & V_43 -> V_47 ) ;
return V_106 ;
}
static int F_72 ( struct V_44 * V_45 )
{
struct V_42 * V_43 = V_45 -> V_101 ;
int V_107 ;
F_22 ( & V_43 -> V_47 ) ;
V_107 = V_43 -> V_48 ;
F_28 ( & V_43 -> V_47 ) ;
return V_107 ;
}
static int F_73 ( struct V_108 * V_52 )
{
int V_38 , V_109 ;
struct V_42 * V_43 ;
struct V_1 * V_2 ;
struct V_36 * V_99 ;
unsigned int V_59 , V_110 ;
V_2 = F_74 ( & V_52 -> V_52 , sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 )
return - V_98 ;
V_2 -> V_28 = V_52 -> V_28 ;
V_2 -> V_52 = & V_52 -> V_52 ;
F_75 ( V_52 , V_2 ) ;
F_76 ( & V_2 -> V_57 , 0 ) ;
F_77 ( & V_2 -> V_39 ) ;
V_2 -> V_5 = F_78 ( V_2 -> V_52 , V_52 -> V_111 . V_112 ,
F_79 ( & V_52 -> V_111 ) ) ;
if ( ! V_2 -> V_5 ) {
F_80 ( V_2 -> V_52 , L_3 ,
& V_52 -> V_111 ) ;
return - V_98 ;
}
V_59 = F_3 ( V_2 , V_64 ) ;
V_110 = ( V_59 & V_113 ) >> V_114 ;
V_59 &= ~ ( V_65 | V_115 ) ;
V_59 |= V_83 ;
V_59 |= V_116 ;
F_1 ( V_2 , V_64 , V_59 ) ;
V_2 -> V_56 = F_68 ( V_110 * 4 , ( unsigned int ) V_117 ) ;
V_99 = F_81 ( V_68 , V_118 ) ;
if ( F_12 ( V_99 ) )
return F_18 ( V_99 ) ;
V_2 -> V_99 = V_99 ;
V_99 -> V_53 = L_4 ;
snprintf ( V_2 -> V_119 , sizeof( V_2 -> V_119 ) , L_5 , V_52 -> V_28 ) ;
snprintf ( V_2 -> V_53 , sizeof( V_2 -> V_53 ) , L_6 ,
V_2 -> V_119 ) ;
V_99 -> V_120 = V_2 -> V_53 ;
V_99 -> V_121 = 0 ;
V_99 -> V_122 = 0 ;
V_99 -> type = V_123 ;
V_99 -> V_124 = V_125 ;
V_99 -> V_126 = V_127 ;
V_99 -> V_126 . V_128 |= V_129 ;
V_99 -> V_100 = V_2 ;
F_82 ( V_99 , & V_130 ) ;
for ( V_109 = 0 ; V_109 < V_68 ; V_109 ++ ) {
V_43 = & V_2 -> V_46 [ V_109 ] ;
V_43 -> V_99 = V_2 ;
F_83 ( & V_43 -> V_49 ) ;
V_43 -> V_49 . V_131 = & V_132 ;
F_77 ( & V_43 -> V_76 ) ;
F_84 ( & V_43 -> V_47 ) ;
F_85 ( & V_43 -> V_55 ) ;
F_26 ( & V_43 -> V_55 ) ;
}
V_79 . V_24 [ V_52 -> V_28 ] = V_2 -> V_5 ;
if ( V_52 -> V_28 == 0 )
V_79 . V_37 = V_99 ;
F_86 ( & V_2 -> V_61 ) ;
V_2 -> V_133 = F_87 ( F_32 , V_2 , V_2 -> V_119 ) ;
if ( F_12 ( V_2 -> V_133 ) ) {
V_38 = F_18 ( V_2 -> V_133 ) ;
F_80 ( V_2 -> V_52 , L_7 , V_38 ) ;
goto V_134;
}
F_88 ( V_2 -> V_133 , V_52 -> V_28 ) ;
F_89 ( V_2 -> V_133 ) ;
V_2 -> V_63 = - 1 ;
if ( V_135 )
V_2 -> V_63 = V_135 () ;
if ( V_2 -> V_63 >= 0 ) {
V_38 = F_90 ( V_2 -> V_52 , V_2 -> V_63 , F_48 ,
V_136 | V_137 |
V_138 | V_139 ,
V_2 -> V_119 , V_2 ) ;
if ( V_38 )
V_2 -> V_63 = - 1 ;
}
if ( V_2 -> V_63 >= 0 ) {
F_37 ( & V_2 -> V_39 ) ;
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ V_115 ;
V_59 |= V_140 ;
F_1 ( V_2 , V_64 , V_59 ) ;
F_38 ( & V_2 -> V_39 ) ;
} else {
F_91 ( & V_2 -> V_90 , F_50 ,
( unsigned long ) V_2 ) ;
V_2 -> V_90 . V_141 = V_91 + V_92 ;
F_92 ( & V_2 -> V_90 , V_52 -> V_28 ) ;
F_93 ( V_2 -> V_52 , L_8 ) ;
}
V_38 = F_94 ( V_99 ) ;
if ( V_38 < 0 ) {
F_80 ( V_2 -> V_52 , L_9 , V_38 ) ;
goto V_142;
}
return 0 ;
V_142:
if ( V_2 -> V_63 >= 0 ) {
F_37 ( & V_2 -> V_39 ) ;
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ ( V_65 | V_115 ) ;
V_59 |= V_83 ;
V_59 |= V_116 ;
F_1 ( V_2 , V_64 , V_59 ) ;
F_38 ( & V_2 -> V_39 ) ;
} else {
V_2 -> V_89 = true ;
F_95 ( & V_2 -> V_90 ) ;
}
F_96 ( V_2 -> V_133 ) ;
V_134:
if ( V_52 -> V_28 == 0 )
V_79 . V_37 = NULL ;
for ( V_109 = 0 ; V_109 < V_68 ; V_109 ++ ) {
V_43 = & V_2 -> V_46 [ V_109 ] ;
F_97 ( & V_43 -> V_49 ) ;
}
F_98 ( V_2 -> V_99 ) ;
return V_38 ;
}
static int F_99 ( struct V_108 * V_52 )
{
struct V_1 * V_2 = F_100 ( V_52 ) ;
struct V_42 * V_43 ;
int V_109 ;
unsigned int V_59 ;
if ( V_2 -> V_63 >= 0 ) {
F_37 ( & V_2 -> V_39 ) ;
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ ( V_65 | V_115 ) ;
V_59 |= V_83 ;
V_59 |= V_116 ;
F_1 ( V_2 , V_64 , V_59 ) ;
F_38 ( & V_2 -> V_39 ) ;
} else {
V_2 -> V_89 = true ;
F_95 ( & V_2 -> V_90 ) ;
}
F_96 ( V_2 -> V_133 ) ;
if ( V_52 -> V_28 == 0 )
V_79 . V_37 = NULL ;
F_101 ( V_2 -> V_99 ) ;
for ( V_109 = 0 ; V_109 < V_68 ; V_109 ++ ) {
V_43 = & V_2 -> V_46 [ V_109 ] ;
F_97 ( & V_43 -> V_49 ) ;
}
F_98 ( V_2 -> V_99 ) ;
return 0 ;
}
static int F_102 ( struct V_108 * V_52 )
{
struct V_1 * V_2 = F_100 ( V_52 ) ;
unsigned int V_59 ;
if ( V_2 -> V_63 >= 0 ) {
F_37 ( & V_2 -> V_39 ) ;
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ ( V_65 | V_115 ) ;
V_59 |= V_83 ;
V_59 |= V_116 ;
F_1 ( V_2 , V_64 , V_59 ) ;
F_38 ( & V_2 -> V_39 ) ;
} else {
V_2 -> V_89 = true ;
F_95 ( & V_2 -> V_90 ) ;
}
F_96 ( V_2 -> V_133 ) ;
return 0 ;
}
static int F_103 ( struct V_108 * V_52 )
{
struct V_1 * V_2 = F_100 ( V_52 ) ;
unsigned int V_59 ;
int V_38 = 0 ;
if ( V_2 -> V_63 >= 0 ) {
F_37 ( & V_2 -> V_39 ) ;
V_59 = F_3 ( V_2 , V_64 ) ;
V_59 &= ~ ( V_65 | V_115 ) ;
V_59 |= V_83 ;
V_59 |= V_140 ;
F_1 ( V_2 , V_64 , V_59 ) ;
F_38 ( & V_2 -> V_39 ) ;
} else {
V_2 -> V_89 = false ;
F_92 ( & V_2 -> V_90 , V_52 -> V_28 ) ;
}
V_2 -> V_133 = F_87 ( F_32 , V_2 , V_2 -> V_119 ) ;
if ( F_12 ( V_2 -> V_133 ) ) {
V_38 = F_18 ( V_2 -> V_133 ) ;
F_80 ( V_2 -> V_52 , L_10 , V_38 ) ;
goto V_32;
}
F_88 ( V_2 -> V_133 , V_52 -> V_28 ) ;
F_89 ( V_2 -> V_133 ) ;
V_32:
return V_38 ;
}
static int T_3 F_104 ( void )
{
return F_16 ( & V_79 ) ;
}
int T_3 F_105 ( void )
{
return F_16 ( & V_143 ) ;
}
static void T_2 * F_106 ( void )
{
void T_2 * V_24 ;
unsigned int V_28 ;
V_28 = F_10 () ;
V_24 = V_79 . V_24 [ V_28 ] ;
if ( ! V_24 ) {
V_24 = F_11 ( 0xfd ) ;
V_79 . V_24 [ V_28 ] = V_24 ;
}
if ( F_12 ( V_24 ) )
return V_24 ;
return V_24 ;
}
static int F_107 ( void )
{
unsigned int V_69 , V_70 , V_4 ;
void T_2 * V_24 ;
if ( V_144 >= V_145 ) {
V_144 = 0 ;
V_145 = 0 ;
V_24 = F_106 () ;
if ( F_12 ( V_24 ) )
return V_146 ;
do {
V_69 = F_4 ( V_24 + V_33 ) ;
if ( V_69 & V_73 )
return V_146 ;
V_70 = ( V_69 & V_74 ) >>
V_75 ;
V_4 = F_4 ( V_24 + V_77 ) ;
} while ( V_70 != V_78 );
V_145 = F_6 ( V_4 , V_147 ) ;
}
F_108 ( L_11 , V_147 [ V_144 ] ) ;
return V_147 [ V_144 ++ ] ;
}
static void F_109 ( void )
{
const char * V_148 [ 1 ] = { V_149 } ;
struct V_6 V_10 ;
void T_2 * V_24 ;
unsigned int V_26 ;
V_10 = F_5 ( V_148 , & V_150 , 1 ) ;
V_150 -= V_10 . V_15 ;
for ( V_26 = 0 ; V_26 < V_150 ; ++ V_26 )
V_149 [ V_26 ] = V_149 [ V_26 + V_10 . V_15 ] ;
V_24 = F_106 () ;
if ( F_12 ( V_24 ) )
return;
while ( F_4 ( V_24 + V_33 ) & V_34 )
;
F_2 ( V_10 . V_10 ,
V_24 + F_13 ( V_78 ) ) ;
}
static void F_110 ( void )
{
while ( V_150 )
F_109 () ;
}
static void F_111 ( V_14 V_151 )
{
F_108 ( L_12 , V_151 ) ;
V_149 [ V_150 ++ ] = V_151 ;
if ( V_150 >= sizeof( V_149 ) )
F_109 () ;
}
static int T_3 F_112 ( void )
{
F_113 ( & V_152 ) ;
return 0 ;
}
