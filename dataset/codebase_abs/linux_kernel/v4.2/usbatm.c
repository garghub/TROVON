static inline unsigned int F_1 ( unsigned int V_1 )
{
V_1 += V_2 - 1 + V_3 ;
return V_1 - V_1 % V_2 ;
}
static inline void F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
if ( V_5 -> V_8 )
V_5 -> V_8 ( V_5 , V_7 ) ;
else
F_3 ( V_7 ) ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 )
{
struct V_9 * V_9 ;
F_5 ( & V_11 -> V_12 ) ;
if ( F_6 ( & V_11 -> V_13 ) ) {
F_7 ( & V_11 -> V_12 ) ;
return NULL ;
}
V_9 = F_8 ( V_11 -> V_13 . V_14 , struct V_9 , V_15 ) ;
F_9 ( & V_9 -> V_15 ) ;
F_7 ( & V_11 -> V_12 ) ;
return V_9 ;
}
static int F_10 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_16 ;
int V_17 ;
V_17 = F_11 ( V_9 , V_18 ) ;
if ( V_17 ) {
if ( F_12 () )
F_13 ( V_11 -> V_19 , L_1 ,
V_20 , V_9 , V_17 ) ;
V_9 -> V_21 = - V_22 ;
F_5 ( & V_11 -> V_12 ) ;
F_14 ( & V_9 -> V_15 , & V_11 -> V_13 ) ;
F_7 ( & V_11 -> V_12 ) ;
F_15 ( & V_11 -> V_23 , V_24 + F_16 ( V_25 ) ) ;
}
return V_17 ;
}
static void F_17 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_16 ;
unsigned long V_26 ;
int V_21 = V_9 -> V_21 ;
F_18 ( & V_11 -> V_12 , V_26 ) ;
F_19 ( & V_9 -> V_15 , & V_11 -> V_13 ) ;
F_20 ( & V_11 -> V_12 , V_26 ) ;
if ( F_21 ( V_21 ) &&
( ! ( V_11 -> V_19 -> V_26 & V_27 ) ||
V_21 != - V_28 ) ) {
if ( V_21 == - V_29 )
return;
if ( F_12 () )
F_13 ( V_11 -> V_19 , L_2 ,
V_20 , V_9 , V_21 ) ;
F_15 ( & V_11 -> V_23 , V_24 + F_16 ( V_25 ) ) ;
} else
F_22 ( & V_11 -> V_30 ) ;
}
static inline struct V_31 * F_23 ( struct V_32 * V_33 ,
short V_34 , int V_35 )
{
struct V_31 * V_36 ;
F_24 (vcc_data, &instance->vcc_list, list)
if ( ( V_36 -> V_35 == V_35 ) && ( V_36 -> V_34 == V_34 ) )
return V_36 ;
return NULL ;
}
static void F_25 ( struct V_32 * V_33 , unsigned char * V_37 )
{
struct V_4 * V_5 ;
struct V_6 * V_38 ;
short V_34 = ( ( V_37 [ 0 ] & 0x0f ) << 4 ) | ( V_37 [ 1 ] >> 4 ) ;
int V_35 = ( ( V_37 [ 1 ] & 0x0f ) << 12 ) | ( V_37 [ 2 ] << 4 ) | ( V_37 [ 3 ] >> 4 ) ;
T_1 V_39 = ( ( V_37 [ 3 ] & 0xe ) >> 1 ) ;
if ( ( V_35 != V_33 -> V_40 ) || ( V_34 != V_33 -> V_41 ) ) {
V_33 -> V_41 = V_34 ;
V_33 -> V_40 = V_35 ;
V_33 -> V_42 = F_23 ( V_33 , V_34 , V_35 ) ;
if ( ! V_33 -> V_42 )
F_26 ( V_33 , L_3 , V_20 , V_34 , V_35 ) ;
}
if ( ! V_33 -> V_42 )
return;
V_5 = V_33 -> V_42 -> V_5 ;
if ( V_39 == V_43 ) {
if ( F_12 () )
F_13 ( V_33 , L_4 ,
V_20 , V_34 , V_35 ) ;
F_27 ( & V_5 -> V_44 -> V_45 ) ;
return;
}
V_38 = V_33 -> V_42 -> V_38 ;
if ( V_38 -> V_46 + V_2 > V_38 -> V_47 ) {
F_26 ( V_33 , L_5 ,
V_20 , V_38 -> V_48 , V_5 ) ;
F_28 ( V_38 , 0 ) ;
}
memcpy ( F_29 ( V_38 ) , V_37 + V_49 , V_2 ) ;
F_30 ( V_38 , V_2 ) ;
if ( V_39 & 1 ) {
struct V_6 * V_7 ;
unsigned int V_1 ;
unsigned int V_50 ;
V_1 = ( V_37 [ V_51 - 6 ] << 8 ) + V_37 [ V_51 - 5 ] ;
if ( V_1 > V_52 ) {
F_26 ( V_33 , L_6 ,
V_20 , V_1 , V_5 ) ;
F_27 ( & V_5 -> V_44 -> V_45 ) ;
goto V_53;
}
V_50 = F_1 ( V_1 ) ;
if ( V_38 -> V_48 < V_50 ) {
F_26 ( V_33 , L_7 ,
V_20 , V_50 , V_38 -> V_48 , V_5 ) ;
F_27 ( & V_5 -> V_44 -> V_45 ) ;
goto V_53;
}
if ( F_31 ( ~ 0 , F_29 ( V_38 ) - V_50 , V_50 ) != 0xc704dd7b ) {
F_26 ( V_33 , L_8 ,
V_20 , V_5 ) ;
F_27 ( & V_5 -> V_44 -> V_45 ) ;
goto V_53;
}
F_32 ( & V_33 -> V_54 -> V_55 ,
L_9 ,
V_20 , V_1 , V_50 , V_5 ) ;
V_7 = F_33 ( V_1 ) ;
if ( ! V_7 ) {
if ( F_12 () )
F_34 ( V_33 , L_10 ,
V_20 , V_1 ) ;
F_27 ( & V_5 -> V_44 -> V_56 ) ;
goto V_53;
}
F_32 ( & V_33 -> V_54 -> V_55 ,
L_11 ,
V_20 , V_7 , V_7 -> V_57 ) ;
if ( ! F_35 ( V_5 , V_7 -> V_57 ) ) {
F_26 ( V_33 , L_12 ,
V_20 , V_7 -> V_57 ) ;
F_3 ( V_7 ) ;
goto V_53;
}
F_36 ( V_7 ,
F_29 ( V_38 ) - V_50 ,
V_1 ) ;
F_30 ( V_7 , V_1 ) ;
F_32 ( & V_33 -> V_54 -> V_55 ,
L_13 ,
V_20 , V_7 , V_7 -> V_48 , V_7 -> V_57 ) ;
F_37 ( V_33 , V_7 -> V_58 , V_7 -> V_48 ) ;
V_5 -> V_59 ( V_5 , V_7 ) ;
F_27 ( & V_5 -> V_44 -> V_60 ) ;
V_53:
F_28 ( V_38 , 0 ) ;
}
}
static void F_38 ( struct V_32 * V_33 ,
unsigned char * V_37 , unsigned int V_61 )
{
unsigned int V_62 = V_33 -> V_63 . V_62 ;
unsigned int V_64 = V_33 -> V_64 ;
if ( V_64 > 0 ) {
unsigned char * V_65 = V_33 -> V_65 ;
unsigned int V_66 = V_62 - V_64 ;
if ( V_61 >= V_66 ) {
memcpy ( V_65 + V_64 , V_37 , V_66 ) ;
V_37 += V_66 ;
V_61 -= V_66 ;
F_25 ( V_33 , V_65 ) ;
V_33 -> V_64 = 0 ;
} else {
memcpy ( V_65 + V_64 , V_37 , V_61 ) ;
V_33 -> V_64 = V_64 + V_61 ;
return;
}
}
for (; V_61 >= V_62 ; V_61 -= V_62 , V_37 += V_62 )
F_25 ( V_33 , V_37 ) ;
if ( V_61 > 0 ) {
memcpy ( V_33 -> V_65 , V_37 , V_61 ) ;
V_33 -> V_64 = V_61 ;
}
}
static unsigned int F_39 ( struct V_32 * V_33 ,
struct V_6 * V_7 ,
T_1 * V_67 , unsigned int V_68 )
{
struct V_69 * V_70 = F_40 ( V_7 ) ;
struct V_4 * V_5 = V_70 -> V_71 . V_5 ;
unsigned int V_72 ;
unsigned int V_62 = V_33 -> V_73 . V_62 ;
for ( V_72 = 0 ; V_72 < V_68 && V_70 -> V_48 ;
V_72 += V_62 , V_67 += V_62 ) {
unsigned int V_74 = F_41 (unsigned int, skb->len, ATM_CELL_PAYLOAD) ;
unsigned int V_75 = V_2 - V_74 ;
T_1 * V_76 = V_67 ;
V_76 [ 0 ] = V_5 -> V_34 >> 4 ;
V_76 [ 1 ] = ( V_5 -> V_34 << 4 ) | ( V_5 -> V_35 >> 12 ) ;
V_76 [ 2 ] = V_5 -> V_35 >> 4 ;
V_76 [ 3 ] = V_5 -> V_35 << 4 ;
V_76 [ 4 ] = 0xec ;
V_76 += V_49 ;
F_42 ( V_7 , V_76 , V_74 ) ;
V_76 += V_74 ;
F_43 ( V_7 , V_74 ) ;
if ( ! V_75 )
continue;
memset ( V_76 , 0 , V_75 ) ;
if ( V_75 >= V_3 ) {
T_1 * V_77 = V_67 + V_51 - V_3 ;
V_77 [ 2 ] = V_70 -> V_48 >> 8 ;
V_77 [ 3 ] = V_70 -> V_48 ;
V_70 -> V_78 = ~ F_31 ( V_70 -> V_78 , V_76 , V_75 - 4 ) ;
V_77 [ 4 ] = V_70 -> V_78 >> 24 ;
V_77 [ 5 ] = V_70 -> V_78 >> 16 ;
V_77 [ 6 ] = V_70 -> V_78 >> 8 ;
V_77 [ 7 ] = V_70 -> V_78 ;
V_67 [ 3 ] |= 0x2 ;
V_70 -> V_48 = 0 ;
} else
V_70 -> V_78 = F_31 ( V_70 -> V_78 , V_76 , V_75 ) ;
}
return V_72 ;
}
static void F_44 ( unsigned long V_58 )
{
struct V_32 * V_33 = (struct V_32 * ) V_58 ;
struct V_9 * V_9 ;
while ( ( V_9 = F_4 ( & V_33 -> V_63 ) ) ) {
F_32 ( & V_33 -> V_54 -> V_55 ,
L_14 , V_20 , V_9 ) ;
if ( F_45 ( V_9 -> V_79 ) ) {
unsigned char * V_80 = NULL ;
unsigned int V_81 = 0 ;
const unsigned int V_82 = V_33 -> V_63 . V_82 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_9 -> V_84 ; V_83 ++ ) {
if ( ! V_9 -> V_85 [ V_83 ] . V_21 ) {
unsigned int V_86 = V_9 -> V_85 [ V_83 ] . V_86 ;
if ( ! V_81 )
V_80 = ( unsigned char * ) V_9 -> V_87 + V_9 -> V_85 [ V_83 ] . V_88 ;
V_81 += V_86 ;
if ( V_81 && ( V_86 < V_82 ) ) {
F_38 ( V_33 , V_80 , V_81 ) ;
V_81 = 0 ;
}
} else {
F_26 ( V_33 , L_15 , V_20 , V_9 -> V_21 , V_83 ) ;
if ( V_81 )
F_38 ( V_33 , V_80 , V_81 ) ;
V_81 = 0 ;
V_33 -> V_64 = 0 ;
}
}
if ( V_81 )
F_38 ( V_33 , V_80 , V_81 ) ;
} else
if ( ! V_9 -> V_21 )
F_38 ( V_33 , V_9 -> V_87 , V_9 -> V_86 ) ;
else
V_33 -> V_64 = 0 ;
if ( F_10 ( V_9 ) )
return;
}
}
static void F_46 ( unsigned long V_58 )
{
struct V_32 * V_33 = (struct V_32 * ) V_58 ;
struct V_6 * V_7 = V_33 -> V_89 ;
struct V_9 * V_9 = NULL ;
const unsigned int V_90 = V_33 -> V_73 . V_90 ;
unsigned int V_72 = 0 ;
T_1 * V_91 = NULL ;
if ( ! V_7 )
V_7 = F_47 ( & V_33 -> V_92 ) ;
while ( V_7 ) {
if ( ! V_9 ) {
V_9 = F_4 ( & V_33 -> V_73 ) ;
if ( ! V_9 )
break;
V_91 = V_9 -> V_87 ;
V_72 = ( V_9 -> V_21 == - V_22 ) ?
V_9 -> V_93 : 0 ;
}
V_72 += F_39 ( V_33 , V_7 ,
V_91 + V_72 ,
V_90 - V_72 ) ;
F_32 ( & V_33 -> V_54 -> V_55 ,
L_16 ,
V_20 , V_72 , V_7 , V_9 ) ;
if ( ! F_40 ( V_7 ) -> V_48 ) {
struct V_4 * V_5 = F_40 ( V_7 ) -> V_71 . V_5 ;
F_2 ( V_5 , V_7 ) ;
F_27 ( & V_5 -> V_44 -> V_94 ) ;
V_7 = F_47 ( & V_33 -> V_92 ) ;
}
if ( V_72 == V_90 || ( ! V_7 && V_72 ) ) {
V_9 -> V_93 = V_72 ;
if ( F_10 ( V_9 ) )
break;
V_9 = NULL ;
}
}
V_33 -> V_89 = V_7 ;
}
static void F_48 ( struct V_32 * V_33 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 , * V_95 ;
F_5 ( & V_33 -> V_92 . V_12 ) ;
F_49 (&instance->sndqueue, skb, n) {
if ( F_40 ( V_7 ) -> V_71 . V_5 == V_5 ) {
F_50 ( V_33 , L_17 , V_20 , V_7 ) ;
F_51 ( V_7 , & V_33 -> V_92 ) ;
F_2 ( V_5 , V_7 ) ;
}
}
F_7 ( & V_33 -> V_92 . V_12 ) ;
F_52 ( & V_33 -> V_73 . V_30 ) ;
if ( ( V_7 = V_33 -> V_89 ) && ( F_40 ( V_7 ) -> V_71 . V_5 == V_5 ) ) {
F_50 ( V_33 , L_18 , V_20 , V_7 ) ;
V_33 -> V_89 = NULL ;
F_2 ( V_5 , V_7 ) ;
}
F_53 ( & V_33 -> V_73 . V_30 ) ;
}
static int F_54 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_32 * V_33 = V_5 -> V_55 -> V_96 ;
struct V_69 * V_70 = F_40 ( V_7 ) ;
int V_97 ;
if ( ! V_33 || V_33 -> V_98 ) {
#ifdef F_55
F_56 ( V_99 L_19 , V_20 , V_33 ? L_20 : L_21 ) ;
#endif
V_97 = - V_100 ;
goto V_101;
}
if ( V_5 -> V_102 . V_103 != V_104 ) {
F_26 ( V_33 , L_22 , V_20 , V_5 -> V_102 . V_103 ) ;
V_97 = - V_105 ;
goto V_101;
}
if ( V_7 -> V_48 > V_52 ) {
F_26 ( V_33 , L_23 ,
V_20 , V_7 -> V_48 , V_52 ) ;
V_97 = - V_105 ;
goto V_101;
}
F_37 ( V_33 , V_7 -> V_58 , V_7 -> V_48 ) ;
V_70 -> V_71 . V_5 = V_5 ;
V_70 -> V_48 = V_7 -> V_48 ;
V_70 -> V_78 = F_31 ( ~ 0 , V_7 -> V_58 , V_7 -> V_48 ) ;
F_57 ( & V_33 -> V_92 , V_7 ) ;
F_22 ( & V_33 -> V_73 . V_30 ) ;
return 0 ;
V_101:
F_2 ( V_5 , V_7 ) ;
return V_97 ;
}
static void F_58 ( struct V_106 * V_106 )
{
struct V_32 * V_33 = F_59 ( V_106 , struct V_32 , V_107 ) ;
F_60 ( & V_33 -> V_63 . V_30 ) ;
F_60 ( & V_33 -> V_73 . V_30 ) ;
F_61 ( V_33 -> V_108 ) ;
F_62 ( V_33 ) ;
}
static void F_63 ( struct V_32 * V_33 )
{
F_64 ( & V_33 -> V_107 ) ;
}
static void F_65 ( struct V_32 * V_33 )
{
F_66 ( & V_33 -> V_107 , F_58 ) ;
}
static void F_67 ( struct V_109 * V_109 )
{
struct V_32 * V_33 = V_109 -> V_96 ;
if ( ! V_33 )
return;
V_109 -> V_96 = NULL ;
F_65 ( V_33 ) ;
}
static int F_68 ( struct V_109 * V_109 , T_2 * V_110 , char * V_111 )
{
struct V_32 * V_33 = V_109 -> V_96 ;
int V_75 = * V_110 ;
if ( ! V_33 )
return - V_100 ;
if ( ! V_75 -- )
return sprintf ( V_111 , L_24 , V_33 -> V_112 ) ;
if ( ! V_75 -- )
return sprintf ( V_111 , L_25 , V_109 -> V_113 ) ;
if ( ! V_75 -- )
return sprintf ( V_111 ,
L_26 ,
F_69 ( & V_109 -> V_44 . V_114 . V_94 ) ,
F_69 ( & V_109 -> V_44 . V_114 . V_115 ) ,
F_69 ( & V_109 -> V_44 . V_114 . V_60 ) ,
F_69 ( & V_109 -> V_44 . V_114 . V_45 ) ,
F_69 ( & V_109 -> V_44 . V_114 . V_56 ) ) ;
if ( ! V_75 -- ) {
if ( V_33 -> V_98 )
return sprintf ( V_111 , L_27 ) ;
else
switch ( V_109 -> signal ) {
case V_116 :
return sprintf ( V_111 , L_28 ) ;
case V_117 :
return sprintf ( V_111 , L_29 ) ;
default:
return sprintf ( V_111 , L_30 ) ;
}
}
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = V_5 -> V_55 -> V_96 ;
struct V_31 * V_118 = NULL ;
int V_17 ;
int V_35 = V_5 -> V_35 ;
short V_34 = V_5 -> V_34 ;
if ( ! V_33 )
return - V_100 ;
if ( ( V_5 -> V_102 . V_103 != V_104 ) ) {
F_13 ( V_33 , L_22 , V_20 , V_5 -> V_102 . V_103 ) ;
return - V_105 ;
}
if ( ( V_5 -> V_102 . V_119 . V_120 < 0 ) || ( V_5 -> V_102 . V_119 . V_120 > V_52 ) ) {
F_50 ( V_33 , L_31 , V_20 , V_5 -> V_102 . V_119 . V_120 ) ;
return - V_105 ;
}
F_71 ( & V_33 -> V_121 ) ;
if ( V_33 -> V_98 ) {
F_50 ( V_33 , L_32 , V_20 ) ;
V_17 = - V_100 ;
goto V_101;
}
if ( F_23 ( V_33 , V_34 , V_35 ) ) {
F_50 ( V_33 , L_33 , V_20 , V_34 , V_35 ) ;
V_17 = - V_122 ;
goto V_101;
}
V_118 = F_72 ( sizeof( struct V_31 ) , V_123 ) ;
if ( ! V_118 ) {
F_34 ( V_33 , L_34 , V_20 ) ;
V_17 = - V_124 ;
goto V_101;
}
V_118 -> V_5 = V_5 ;
V_118 -> V_34 = V_34 ;
V_118 -> V_35 = V_35 ;
V_118 -> V_38 = F_73 ( F_1 ( V_5 -> V_102 . V_119 . V_120 ) , V_123 ) ;
if ( ! V_118 -> V_38 ) {
F_34 ( V_33 , L_35 , V_20 ) ;
V_17 = - V_124 ;
goto V_101;
}
V_5 -> V_96 = V_118 ;
F_52 ( & V_33 -> V_63 . V_30 ) ;
V_33 -> V_42 = V_118 ;
V_33 -> V_41 = V_34 ;
V_33 -> V_40 = V_35 ;
F_14 ( & V_118 -> V_13 , & V_33 -> V_125 ) ;
F_53 ( & V_33 -> V_63 . V_30 ) ;
F_74 ( V_126 , & V_5 -> V_26 ) ;
F_74 ( V_127 , & V_5 -> V_26 ) ;
F_74 ( V_128 , & V_5 -> V_26 ) ;
F_75 ( & V_33 -> V_121 ) ;
F_50 ( V_33 , L_36 , V_20 , V_118 ) ;
return 0 ;
V_101:
F_62 ( V_118 ) ;
F_75 ( & V_33 -> V_121 ) ;
return V_17 ;
}
static void F_76 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = V_5 -> V_55 -> V_96 ;
struct V_31 * V_36 = V_5 -> V_96 ;
if ( ! V_33 || ! V_36 )
return;
F_48 ( V_33 , V_5 ) ;
F_71 ( & V_33 -> V_121 ) ;
F_52 ( & V_33 -> V_63 . V_30 ) ;
if ( V_33 -> V_42 == V_36 ) {
V_33 -> V_42 = NULL ;
V_33 -> V_41 = V_129 ;
V_33 -> V_40 = V_130 ;
}
F_9 ( & V_36 -> V_13 ) ;
F_53 ( & V_33 -> V_63 . V_30 ) ;
F_77 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
F_62 ( V_36 ) ;
V_5 -> V_96 = NULL ;
V_5 -> V_34 = V_129 ;
V_5 -> V_35 = V_130 ;
F_78 ( V_128 , & V_5 -> V_26 ) ;
F_78 ( V_127 , & V_5 -> V_26 ) ;
F_78 ( V_126 , & V_5 -> V_26 ) ;
F_75 ( & V_33 -> V_121 ) ;
}
static int F_79 ( struct V_109 * V_109 , unsigned int V_131 ,
void T_3 * V_132 )
{
struct V_32 * V_33 = V_109 -> V_96 ;
if ( ! V_33 || V_33 -> V_98 )
return - V_100 ;
switch ( V_131 ) {
case V_133 :
return F_80 ( V_134 , ( int T_3 * ) V_132 ) ? - V_135 : 0 ;
default:
return - V_136 ;
}
}
static int F_81 ( struct V_32 * V_33 )
{
struct V_109 * V_109 ;
int V_17 , V_83 ;
V_109 = F_82 ( V_33 -> V_137 ,
& V_33 -> V_54 -> V_55 , & V_138 ,
- 1 , NULL ) ;
if ( ! V_109 ) {
F_83 ( V_33 , L_37 , V_20 ) ;
return - 1 ;
}
V_33 -> V_109 = V_109 ;
V_109 -> V_139 . V_140 = V_141 ;
V_109 -> V_139 . V_142 = V_141 ;
V_109 -> signal = V_143 ;
V_109 -> V_144 = 128 * 1000 / 424 ;
if ( V_33 -> V_145 -> V_146 && ( ( V_17 = V_33 -> V_145 -> V_146 ( V_33 , V_109 ) ) < 0 ) ) {
F_34 ( V_33 , L_38 , V_20 , V_17 ) ;
goto V_101;
}
F_63 ( V_33 ) ;
F_84 () ;
V_109 -> V_96 = V_33 ;
for ( V_83 = 0 ; V_83 < V_147 ; V_83 ++ )
F_10 ( V_33 -> V_148 [ V_83 ] ) ;
return 0 ;
V_101:
V_33 -> V_109 = NULL ;
F_85 ( V_109 ) ;
return V_17 ;
}
static int F_86 ( void * V_132 )
{
struct V_32 * V_33 = V_132 ;
int V_17 ;
F_87 ( V_149 ) ;
F_88 ( & V_33 -> V_150 ) ;
V_17 = V_33 -> V_145 -> V_151 ( V_33 , V_33 -> V_54 ) ;
if ( ! V_17 )
V_17 = F_81 ( V_33 ) ;
F_71 ( & V_33 -> V_121 ) ;
V_33 -> V_152 = NULL ;
F_75 ( & V_33 -> V_121 ) ;
F_89 ( & V_33 -> V_153 , V_17 ) ;
}
static int F_90 ( struct V_32 * V_33 )
{
struct V_154 * V_155 ;
V_155 = F_91 ( F_86 , V_33 , L_39 ,
V_33 -> V_145 -> V_137 ) ;
if ( F_92 ( V_155 ) ) {
F_83 ( V_33 , L_40 ,
V_20 , F_93 ( V_155 ) ) ;
return F_93 ( V_155 ) ;
}
V_33 -> V_152 = V_155 ;
F_94 ( V_155 ) ;
F_95 ( & V_33 -> V_150 ) ;
return 0 ;
}
static void F_96 ( unsigned long V_58 )
{
F_22 ( (struct V_156 * ) V_58 ) ;
}
static void F_97 ( struct V_10 * V_11 )
{
F_98 ( & V_11 -> V_12 ) ;
F_99 ( & V_11 -> V_13 ) ;
V_11 -> V_23 . V_157 = F_96 ;
V_11 -> V_23 . V_58 = ( unsigned long ) & V_11 -> V_30 ;
F_100 ( & V_11 -> V_23 ) ;
}
int F_101 ( struct V_158 * V_159 , const struct V_160 * V_161 ,
struct V_162 * V_145 )
{
struct V_163 * V_55 = & V_159 -> V_55 ;
struct V_164 * V_108 = F_102 ( V_159 ) ;
struct V_32 * V_33 ;
char * V_165 ;
int error = - V_124 ;
int V_83 , V_1 ;
unsigned int V_166 , V_167 ;
V_33 = F_72 ( sizeof( * V_33 ) + sizeof( struct V_9 * ) * ( V_147 + V_168 ) , V_123 ) ;
if ( ! V_33 ) {
F_103 ( V_55 , L_41 , V_20 ) ;
return - V_124 ;
}
V_33 -> V_145 = V_145 ;
F_104 ( V_33 -> V_137 , V_145 -> V_137 ,
sizeof( V_33 -> V_137 ) ) ;
V_33 -> V_108 = V_108 ;
V_33 -> V_54 = V_159 ;
V_165 = V_33 -> V_112 ;
V_1 = sizeof( V_33 -> V_112 ) ;
if ( ( V_83 = F_105 ( V_108 , V_108 -> V_169 . V_170 , V_165 , V_1 ) ) < 0 )
goto V_171;
V_165 += V_83 ;
V_1 -= V_83 ;
V_83 = F_106 ( V_165 , V_1 , L_42 ) ;
V_165 += V_83 ;
V_1 -= V_83 ;
if ( V_1 <= 0 || ( V_83 = F_107 ( V_108 , V_165 , V_1 ) ) < 0 )
goto V_171;
V_165 += V_83 ;
V_1 -= V_83 ;
snprintf ( V_165 , V_1 , L_43 ) ;
V_171:
if ( V_145 -> V_171 && ( error = V_145 -> V_171 ( V_33 , V_159 , V_161 ) ) < 0 ) {
F_103 ( V_55 , L_44 , V_20 , error ) ;
goto V_172;
}
F_108 ( & V_33 -> V_107 ) ;
F_109 ( & V_33 -> V_121 ) ;
V_33 -> V_152 = NULL ;
F_110 ( & V_33 -> V_150 ) ;
F_110 ( & V_33 -> V_153 ) ;
F_99 ( & V_33 -> V_125 ) ;
F_111 ( & V_33 -> V_92 ) ;
F_97 ( & V_33 -> V_63 ) ;
F_97 ( & V_33 -> V_73 ) ;
F_112 ( & V_33 -> V_63 . V_30 , F_44 , ( unsigned long ) V_33 ) ;
F_112 ( & V_33 -> V_73 . V_30 , F_46 , ( unsigned long ) V_33 ) ;
V_33 -> V_63 . V_62 = V_51 + V_145 -> V_173 ;
V_33 -> V_73 . V_62 = V_51 + V_145 -> V_174 ;
V_33 -> V_63 . V_19 = V_33 -> V_73 . V_19 = V_33 ;
if ( ( V_33 -> V_26 & V_175 ) && V_145 -> V_176 )
V_33 -> V_63 . V_177 = F_113 ( V_108 , V_145 -> V_176 ) ;
else
V_33 -> V_63 . V_177 = F_114 ( V_108 , V_145 -> V_178 ) ;
V_33 -> V_73 . V_177 = F_115 ( V_108 , V_145 -> V_179 ) ;
V_33 -> V_73 . V_90 = F_116 ( V_33 -> V_73 . V_62 ,
V_180 - ( V_180 % V_33 -> V_73 . V_62 ) ) ;
V_166 = F_117 ( V_108 , V_33 -> V_63 . V_177 , 0 ) ;
if ( ( V_166 < 1 ) || ( V_166 > V_181 ) ) {
F_103 ( V_55 , L_45 , V_20 ,
F_118 ( V_33 -> V_63 . V_177 ) ) ;
error = - V_105 ;
goto V_182;
}
V_167 = F_116 ( 1U , ( V_183 + V_166 / 2 ) / V_166 ) ;
if ( V_167 * V_166 > V_181 )
V_167 -- ;
V_33 -> V_63 . V_90 = V_167 * V_166 ;
V_33 -> V_63 . V_82 = V_166 ;
for ( V_83 = 0 ; V_83 < 2 ; V_83 ++ ) {
struct V_10 * V_11 = V_83 ?
& V_33 -> V_73 : & V_33 -> V_63 ;
F_119 ( V_55 , L_46 ,
V_20 , V_11 -> V_90 , V_83 ? L_47 : L_48 , V_11 ) ;
}
for ( V_83 = 0 ; V_83 < V_147 + V_168 ; V_83 ++ ) {
T_1 * V_91 ;
struct V_10 * V_11 = V_83 < V_147 ?
& V_33 -> V_63 : & V_33 -> V_73 ;
struct V_9 * V_9 ;
unsigned int V_184 = F_45 ( V_11 -> V_177 ) ? V_11 -> V_90 / V_11 -> V_82 : 0 ;
V_9 = F_120 ( V_184 , V_123 ) ;
if ( ! V_9 ) {
F_103 ( V_55 , L_49 , V_20 , V_83 ) ;
error = - V_124 ;
goto V_182;
}
V_33 -> V_148 [ V_83 ] = V_9 ;
V_91 = F_72 ( V_11 -> V_90 , V_123 ) ;
if ( ! V_91 ) {
F_103 ( V_55 , L_50 , V_20 , V_83 ) ;
error = - V_124 ;
goto V_182;
}
F_121 ( V_9 , V_33 -> V_108 , V_11 -> V_177 ,
V_91 , V_11 -> V_90 , F_17 , V_11 ) ;
if ( V_184 ) {
int V_185 ;
V_9 -> V_186 = 1 ;
V_9 -> V_187 = V_188 ;
V_9 -> V_84 = V_184 ;
for ( V_185 = 0 ; V_185 < V_184 ; V_185 ++ ) {
V_9 -> V_85 [ V_185 ] . V_88 = V_11 -> V_82 * V_185 ;
V_9 -> V_85 [ V_185 ] . V_1 = V_11 -> V_82 ;
}
}
if ( V_83 >= V_147 )
F_19 ( & V_9 -> V_15 , & V_11 -> V_13 ) ;
F_32 ( & V_159 -> V_55 , L_51 ,
V_20 , V_9 -> V_87 , V_9 -> V_93 , V_9 ) ;
}
V_33 -> V_41 = V_129 ;
V_33 -> V_40 = V_130 ;
V_33 -> V_65 = F_122 ( V_33 -> V_63 . V_62 , V_123 ) ;
if ( ! V_33 -> V_65 ) {
F_103 ( V_55 , L_52 , V_20 ) ;
error = - V_124 ;
goto V_182;
}
if ( ! ( V_33 -> V_26 & V_189 ) && V_145 -> V_151 ) {
error = F_90 ( V_33 ) ;
} else {
F_88 ( & V_33 -> V_153 ) ;
error = F_81 ( V_33 ) ;
}
if ( error < 0 )
goto V_182;
F_123 ( V_108 ) ;
F_124 ( V_159 , V_33 ) ;
return 0 ;
V_182:
if ( V_33 -> V_145 -> V_190 )
V_33 -> V_145 -> V_190 ( V_33 , V_159 ) ;
V_172:
F_62 ( V_33 -> V_65 ) ;
for ( V_83 = 0 ; V_83 < V_147 + V_168 ; V_83 ++ ) {
if ( V_33 -> V_148 [ V_83 ] )
F_62 ( V_33 -> V_148 [ V_83 ] -> V_87 ) ;
F_125 ( V_33 -> V_148 [ V_83 ] ) ;
}
F_62 ( V_33 ) ;
return error ;
}
void F_126 ( struct V_158 * V_159 )
{
struct V_163 * V_55 = & V_159 -> V_55 ;
struct V_32 * V_33 = F_127 ( V_159 ) ;
struct V_31 * V_36 ;
int V_83 ;
if ( ! V_33 ) {
F_119 ( V_55 , L_53 , V_20 ) ;
return;
}
F_124 ( V_159 , NULL ) ;
F_71 ( & V_33 -> V_121 ) ;
V_33 -> V_98 = 1 ;
if ( V_33 -> V_152 != NULL )
F_128 ( V_149 , V_33 -> V_152 , 1 ) ;
F_75 ( & V_33 -> V_121 ) ;
F_95 ( & V_33 -> V_153 ) ;
F_71 ( & V_33 -> V_121 ) ;
F_24 (vcc_data, &instance->vcc_list, list)
F_129 ( V_36 -> V_5 , - V_191 ) ;
F_75 ( & V_33 -> V_121 ) ;
F_52 ( & V_33 -> V_63 . V_30 ) ;
F_52 ( & V_33 -> V_73 . V_30 ) ;
for ( V_83 = 0 ; V_83 < V_147 + V_168 ; V_83 ++ )
F_130 ( V_33 -> V_148 [ V_83 ] ) ;
F_131 ( & V_33 -> V_63 . V_23 ) ;
F_131 ( & V_33 -> V_73 . V_23 ) ;
F_99 ( & V_33 -> V_63 . V_13 ) ;
F_99 ( & V_33 -> V_73 . V_13 ) ;
F_53 ( & V_33 -> V_63 . V_30 ) ;
F_53 ( & V_33 -> V_73 . V_30 ) ;
if ( V_33 -> V_109 && V_33 -> V_145 -> V_192 )
V_33 -> V_145 -> V_192 ( V_33 , V_33 -> V_109 ) ;
if ( V_33 -> V_145 -> V_190 )
V_33 -> V_145 -> V_190 ( V_33 , V_159 ) ;
V_33 -> V_193 = NULL ;
for ( V_83 = 0 ; V_83 < V_147 + V_168 ; V_83 ++ ) {
F_62 ( V_33 -> V_148 [ V_83 ] -> V_87 ) ;
F_125 ( V_33 -> V_148 [ V_83 ] ) ;
}
F_62 ( V_33 -> V_65 ) ;
if ( V_33 -> V_109 ) {
F_85 ( V_33 -> V_109 ) ;
V_33 -> V_109 = NULL ;
}
F_65 ( V_33 ) ;
}
static int T_4 F_132 ( void )
{
if ( sizeof( struct V_69 ) > F_133 ( struct V_6 , V_194 ) ) {
F_134 ( V_195 L_54 , V_196 ) ;
return - V_197 ;
}
if ( ( V_147 > V_198 )
|| ( V_168 > V_199 )
|| ( V_183 < 1 )
|| ( V_183 > V_181 )
|| ( V_180 < 1 )
|| ( V_180 > V_181 ) )
return - V_105 ;
return 0 ;
}
static void T_5 F_135 ( void )
{
}
static int F_136 ( struct V_32 * V_33 ,
const unsigned char * V_58 , int V_48 )
{
unsigned char V_91 [ 256 ] ;
int V_83 = 0 , V_185 = 0 ;
for ( V_83 = 0 ; V_83 < V_48 ; ) {
V_91 [ 0 ] = '\0' ;
sprintf ( V_91 , L_55 , V_83 ) ;
for ( V_185 = 0 ; ( V_185 < 16 ) && ( V_83 < V_48 ) ; V_185 ++ , V_83 ++ )
sprintf ( V_91 , L_56 , V_91 , V_58 [ V_83 ] ) ;
F_119 ( & V_33 -> V_54 -> V_55 , L_39 , V_91 ) ;
}
return V_83 ;
}
