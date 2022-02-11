static void F_1 ( int V_1 , T_1 V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
F_2 ( & V_5 -> V_6 ) ;
}
static T_2 F_3 ( int V_7 , void * V_8 )
{
struct V_4 * V_5 = V_8 ;
F_2 ( & V_5 -> V_9 ) ;
return V_10 ;
}
static inline unsigned short F_4 ( struct V_4 * V_5 , int V_11 )
{
return F_5 ( V_5 -> V_12 . V_13 + V_11 ) ;
}
static inline void F_6 ( struct V_4 * V_5 , unsigned short V_14 ,
int V_11 )
{
F_7 ( V_14 , V_5 -> V_12 . V_13 + V_11 ) ;
}
static void F_8 ( char * V_15 , int V_16 , unsigned int V_17 , unsigned int V_18 )
{
F_9 ( V_19 L_1 ,
V_15 , V_16 , V_17 , V_18 ) ;
}
static void F_10 ( char * V_15 , int V_16 , unsigned int V_17 ,
unsigned int V_18 )
{
F_9 ( V_20 L_2
L_3 , V_15 , V_16 , V_17 , V_18 ) ;
}
static int F_11 ( struct V_21 * V_22 , int V_16 )
{
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
unsigned int V_18 = 0 ;
unsigned int V_17 , V_26 ;
unsigned long V_27 ;
T_3 V_28 ;
if ( V_16 == V_29 || V_16 == V_30 ||
V_16 == V_31 ) {
int V_32 = 21 ;
unsigned int V_33 = V_34 ;
switch ( V_16 ) {
case V_29 :
V_33 |= V_35 ;
break;
case V_30 :
V_33 |= V_36 ;
break;
case V_31 :
V_32 = 101 ;
break;
}
while ( -- V_32 ) {
F_13 ( 1 ) ;
V_18 = F_4 ( V_5 , V_37 ) ;
if ( V_18 & V_34 )
break;
}
V_17 = F_4 ( V_5 , V_38 ) ;
if ( V_17 & V_39 ) {
F_8 ( L_4 , V_16 , V_17 , V_18 ) ;
return - V_40 ;
}
if ( ( V_18 & V_33 ) == V_33 )
return 0 ;
}
if ( V_16 != V_41 ) {
int V_42 ;
V_28 = F_4 ( V_5 , V_43 ) ;
if ( ! ( V_28 & V_44 ) ) {
V_28 |= V_44 ;
F_6 ( V_5 , V_28 , V_43 ) ;
if ( V_5 -> V_45 & V_46 )
V_28 = F_4 ( V_5 , V_43 ) ;
}
F_14 ( & V_5 -> V_9 ) ;
if ( V_5 -> V_47 ) {
V_42 = F_15 ( V_5 -> V_47 ) ;
if ( V_42 == - 1 ) {
V_17 = F_4 ( V_5 , V_38 ) ;
V_18 = F_4 ( V_5 , V_37 ) ;
F_8 ( L_5 , V_16 , V_17 , V_18 ) ;
return - V_40 ;
}
} else
V_42 = 0 ;
if ( V_42 == 0 ) {
int V_48 = 0 ;
V_49:
V_42 = F_16 ( & V_5 -> V_9 ,
F_17 ( 20 ) ) ;
if ( V_42 == 0 ) {
V_17 = F_4 ( V_5 , V_38 ) ;
if ( V_17 & V_50 &&
! V_24 -> V_51 ) {
V_48 += 1 ;
if ( V_48 < 3 )
goto V_49;
V_18 = F_4 ( V_5 ,
V_37 ) ;
F_8 ( L_6 , V_16 , V_17 , V_18 ) ;
return - V_40 ;
}
V_18 = F_4 ( V_5 , V_37 ) ;
if ( ( V_18 & V_34 ) == 0 )
F_10 ( L_6 , V_16 , V_17 , V_18 ) ;
}
}
} else {
int V_48 = 0 ;
V_28 = F_4 ( V_5 , V_43 ) ;
V_28 &= ~ V_44 ;
F_6 ( V_5 , V_28 , V_43 ) ;
V_27 = V_52 + F_17 ( 20 ) ;
while ( 1 ) {
if ( F_18 ( V_52 , V_27 ) ) {
V_18 = F_4 ( V_5 , V_37 ) ;
if ( V_18 & V_34 )
break;
} else {
V_17 = F_4 ( V_5 , V_38 ) ;
if ( V_17 & V_50 ) {
V_48 += 1 ;
if ( V_48 < 3 ) {
V_27 = V_52 +
F_17 ( 20 ) ;
continue;
}
}
break;
}
}
}
V_18 = F_4 ( V_5 , V_37 ) ;
V_17 = F_4 ( V_5 , V_38 ) ;
if ( V_18 & V_53 ) {
int V_54 = F_4 ( V_5 , V_55 ) ;
if ( V_54 ) {
unsigned int V_56 , V_57 ;
V_56 = F_4 ( V_5 , V_58 ) ;
V_57 = F_4 ( V_5 , V_59 ) ;
if ( V_54 & V_60 ) {
F_9 ( V_19 L_7
L_8 ,
V_54 , V_56 , V_57 ) ;
V_22 -> V_61 . V_62 ++ ;
return - V_63 ;
} else if ( V_54 & V_64 ) {
F_9 ( V_65 L_9
L_10
L_11 , V_54 , V_56 , V_57 ) ;
V_22 -> V_61 . V_66 ++ ;
}
}
} else if ( V_16 == V_41 ) {
F_8 ( L_6 , V_16 , V_17 , V_18 ) ;
return - V_40 ;
}
if ( V_17 & V_39 ) {
F_8 ( L_4 , V_16 , V_17 , V_18 ) ;
if ( V_17 & V_67 )
F_9 ( V_19 L_12
L_13 ) ;
return - V_40 ;
}
V_26 = 0xFE9F ;
if ( V_24 -> V_51 )
V_26 &= ~ 0x8000 ;
if ( V_17 & V_26 )
F_10 ( L_14 , V_16 , V_17 , V_18 ) ;
return 0 ;
}
static inline int F_19 ( struct V_21 * V_22 , int V_68 )
{
struct V_23 * V_24 = V_22 -> V_25 ;
if ( F_20 ( V_24 ) ) {
if ( V_68 == V_69 )
return V_24 -> V_70 ;
if ( V_68 == V_71 )
return V_22 -> V_72 ;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_22 , int V_68 ,
unsigned char * V_73 , int V_74 ,
T_4 V_75 )
{
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_76 , V_77 ;
int V_78 ;
unsigned long V_27 ;
void * V_79 = ( void * ) V_73 ;
T_4 V_80 ;
volatile unsigned * V_81 ;
V_78 = F_19 ( V_22 , V_68 ) + V_68 + V_74 ;
if ( V_78 & 3 || ( T_4 ) V_79 & 3 || V_75 < 384 )
goto V_82;
if ( F_22 () || V_83 )
goto V_82;
if ( V_79 >= V_84 ) {
struct V_85 * V_86 ;
if ( ( ( T_4 ) V_79 & V_87 ) !=
( ( T_4 ) ( V_79 + V_75 - 1 ) & V_87 ) )
goto V_82;
V_86 = F_23 ( V_79 ) ;
if ( ! V_86 )
goto V_82;
V_79 = F_24 ( V_86 ) + ( ( T_4 ) V_79 & ~ V_87 ) ;
}
V_80 = V_75 & 3 ;
if ( V_80 ) {
V_75 -= V_80 ;
memcpy ( V_79 + V_75 , V_24 -> V_13 + V_78 + V_75 , V_80 ) ;
}
V_76 = V_5 -> V_88 + V_78 ;
V_77 = F_25 ( & V_5 -> V_89 -> V_90 , V_79 , V_75 , V_91 ) ;
if ( F_26 ( & V_5 -> V_89 -> V_90 , V_77 ) ) {
F_27 ( & V_5 -> V_89 -> V_90 ,
L_15 ,
V_75 ) ;
goto V_82;
}
F_28 ( V_5 -> V_92 , V_93 ,
V_75 >> 2 , 1 , 0 , 0 , 0 ) ;
F_29 ( V_5 -> V_92 , 0 , V_94 ,
V_76 , 0 , 0 ) ;
F_30 ( V_5 -> V_92 , 0 , V_94 ,
V_77 , 0 , 0 ) ;
F_14 ( & V_5 -> V_6 ) ;
F_31 ( V_5 -> V_92 ) ;
V_27 = V_52 + F_17 ( 20 ) ;
V_81 = & V_5 -> V_6 . V_81 ;
while ( F_18 ( V_52 , V_27 ) )
if ( * V_81 )
break;
F_32 ( & V_5 -> V_89 -> V_90 , V_77 , V_75 , V_91 ) ;
if ( ! * V_81 ) {
F_27 ( & V_5 -> V_89 -> V_90 , L_16 ) ;
goto V_82;
}
return 0 ;
V_82:
memcpy ( V_79 , V_24 -> V_13 + V_78 , V_75 ) ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , int V_68 ,
const unsigned char * V_73 ,
int V_74 , T_4 V_75 )
{
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_76 , V_77 ;
int V_78 ;
unsigned long V_27 ;
void * V_79 = ( void * ) V_73 ;
volatile unsigned * V_81 ;
V_78 = F_19 ( V_22 , V_68 ) + V_68 + V_74 ;
if ( V_78 & 3 || ( T_4 ) V_79 & 3 || V_75 < 384 )
goto V_82;
if ( F_22 () || V_83 )
goto V_82;
if ( V_79 >= V_84 ) {
struct V_85 * V_86 ;
if ( ( ( T_4 ) V_79 & V_87 ) !=
( ( T_4 ) ( V_79 + V_75 - 1 ) & V_87 ) )
goto V_82;
V_86 = F_23 ( V_79 ) ;
if ( ! V_86 )
goto V_82;
V_79 = F_24 ( V_86 ) + ( ( T_4 ) V_79 & ~ V_87 ) ;
}
V_76 = F_25 ( & V_5 -> V_89 -> V_90 , V_79 , V_75 , V_95 ) ;
V_77 = V_5 -> V_88 + V_78 ;
if ( F_26 ( & V_5 -> V_89 -> V_90 , V_76 ) ) {
F_27 ( & V_5 -> V_89 -> V_90 ,
L_15 ,
V_75 ) ;
return - 1 ;
}
F_28 ( V_5 -> V_92 , V_93 ,
V_75 >> 2 , 1 , 0 , 0 , 0 ) ;
F_29 ( V_5 -> V_92 , 0 , V_94 ,
V_76 , 0 , 0 ) ;
F_30 ( V_5 -> V_92 , 0 , V_94 ,
V_77 , 0 , 0 ) ;
F_14 ( & V_5 -> V_6 ) ;
F_31 ( V_5 -> V_92 ) ;
V_27 = V_52 + F_17 ( 20 ) ;
V_81 = & V_5 -> V_6 . V_81 ;
while ( F_18 ( V_52 , V_27 ) )
if ( * V_81 )
break;
F_32 ( & V_5 -> V_89 -> V_90 , V_76 , V_75 , V_95 ) ;
if ( ! * V_81 ) {
F_27 ( & V_5 -> V_89 -> V_90 , L_16 ) ;
goto V_82;
}
return 0 ;
V_82:
memcpy ( V_24 -> V_13 + V_78 , V_79 , V_75 ) ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 , int V_68 ,
unsigned char * V_73 , int V_74 ,
T_4 V_75 )
{
return - V_96 ;
}
static int F_33 ( struct V_21 * V_22 , int V_68 ,
const unsigned char * V_73 ,
int V_74 , T_4 V_75 )
{
return - V_96 ;
}
static int F_34 ( struct V_21 * V_22 , int V_68 ,
unsigned char * V_73 , int V_74 ,
T_4 V_75 )
{
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_76 , V_77 ;
int V_78 ;
V_78 = F_19 ( V_22 , V_68 ) + V_68 + V_74 ;
if ( 1 || ( V_5 -> V_92 < 0 ) ||
( ( void * ) V_73 >= ( void * ) V_84 ) || ( V_78 & 3 ) ||
( ( ( unsigned int ) V_73 ) & 3 ) || ( V_75 < 1024 ) || ( V_75 & 3 ) ) {
memcpy ( V_73 , ( V_97 void * ) ( V_24 -> V_13 + V_78 ) ,
V_75 ) ;
return 0 ;
}
V_76 = V_5 -> V_88 + V_78 ;
V_77 = F_25 ( & V_5 -> V_89 -> V_90 , V_73 , V_75 ,
V_91 ) ;
if ( F_26 ( & V_5 -> V_89 -> V_90 , V_77 ) ) {
F_27 ( & V_5 -> V_89 -> V_90 ,
L_15 ,
V_75 ) ;
return - 1 ;
}
F_28 ( V_5 -> V_92 , V_93 ,
V_75 / 4 , 1 , 0 , 0 , 0 ) ;
F_29 ( V_5 -> V_92 , 0 , V_94 ,
V_76 , 0 , 0 ) ;
F_30 ( V_5 -> V_92 , 0 , V_94 ,
V_77 , 0 , 0 ) ;
F_14 ( & V_5 -> V_6 ) ;
F_31 ( V_5 -> V_92 ) ;
F_35 ( & V_5 -> V_6 ) ;
F_32 ( & V_5 -> V_89 -> V_90 , V_77 , V_75 , V_91 ) ;
return 0 ;
}
static int F_36 ( struct V_21 * V_22 , int V_68 ,
const unsigned char * V_73 ,
int V_74 , T_4 V_75 )
{
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
T_5 V_76 , V_77 ;
int V_78 ;
V_78 = F_19 ( V_22 , V_68 ) + V_68 + V_74 ;
if ( 1 || ( V_5 -> V_92 < 0 ) ||
( ( void * ) V_73 >= ( void * ) V_84 ) || ( V_78 & 3 ) ||
( ( ( unsigned int ) V_73 ) & 3 ) || ( V_75 < 1024 ) || ( V_75 & 3 ) ) {
memcpy ( ( V_97 void * ) ( V_24 -> V_13 + V_78 ) , V_73 ,
V_75 ) ;
return 0 ;
}
V_76 = F_25 ( & V_5 -> V_89 -> V_90 , ( void * ) V_73 , V_75 ,
V_95 ) ;
V_77 = V_5 -> V_88 + V_78 ;
if ( F_26 ( & V_5 -> V_89 -> V_90 , V_76 ) ) {
F_27 ( & V_5 -> V_89 -> V_90 ,
L_15 ,
V_75 ) ;
return - 1 ;
}
F_28 ( V_5 -> V_92 , V_98 ,
V_75 / 2 , 1 , 0 , 0 , 0 ) ;
F_29 ( V_5 -> V_92 , 0 , V_94 ,
V_76 , 0 , 0 ) ;
F_30 ( V_5 -> V_92 , 0 , V_94 ,
V_77 , 0 , 0 ) ;
F_14 ( & V_5 -> V_6 ) ;
F_31 ( V_5 -> V_92 ) ;
F_35 ( & V_5 -> V_6 ) ;
F_32 ( & V_5 -> V_89 -> V_90 , V_76 , V_75 , V_95 ) ;
return 0 ;
}
static int F_34 ( struct V_21 * V_22 , int V_68 ,
unsigned char * V_73 , int V_74 ,
T_4 V_75 )
{
return - V_96 ;
}
static int F_36 ( struct V_21 * V_22 , int V_68 ,
const unsigned char * V_73 ,
int V_74 , T_4 V_75 )
{
return - V_96 ;
}
static void F_37 ( struct V_99 * V_89 )
{
struct V_4 * V_5 = F_38 ( & V_89 -> V_90 ) ;
memset ( ( V_97 void * ) V_5 -> V_12 . V_13 , 0 , V_100 ) ;
}
static int F_39 ( struct V_21 * V_22 )
{
int V_101 ;
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
V_101 = F_40 ( V_5 -> V_102 ) ;
if ( V_101 != 0 )
F_27 ( & V_5 -> V_89 -> V_90 , L_17 ) ;
return V_101 ;
}
static int F_41 ( struct V_21 * V_22 )
{
int V_101 ;
struct V_4 * V_5 = F_12 ( V_22 , struct V_4 , V_22 ) ;
V_101 = F_42 ( V_5 -> V_102 ) ;
if ( V_101 != 0 )
F_27 ( & V_5 -> V_89 -> V_90 , L_18 ) ;
return V_101 ;
}
static int F_43 ( struct V_99 * V_89 )
{
struct V_103 * V_104 ;
struct V_4 * V_5 ;
struct V_23 * V_24 ;
int V_105 ;
struct V_106 * V_107 ;
V_104 = F_44 ( & V_89 -> V_90 ) ;
if ( V_104 == NULL ) {
F_27 ( & V_89 -> V_90 , L_19 ) ;
return - V_108 ;
}
V_5 = F_45 ( sizeof( struct V_4 ) , V_109 ) ;
if ( ! V_5 )
return - V_110 ;
F_46 ( & V_5 -> V_9 ) ;
F_46 ( & V_5 -> V_6 ) ;
V_5 -> V_45 = V_104 -> V_45 ;
V_5 -> V_111 = V_104 -> V_112 ;
V_5 -> V_47 = V_104 -> V_47 ;
V_5 -> V_92 = V_104 -> V_92 ;
if ( V_5 -> V_92 < 0 ) {
V_5 -> V_47 = 0 ;
}
V_107 = F_47 ( V_89 , V_113 , 0 ) ;
if ( V_107 == NULL ) {
V_105 = - V_114 ;
F_27 ( & V_89 -> V_90 , L_20 ) ;
goto V_115;
}
V_5 -> V_88 = V_107 -> V_116 ;
V_5 -> V_117 = F_48 ( V_107 ) ;
if ( F_49 ( V_5 -> V_88 , V_5 -> V_117 ,
V_89 -> V_90 . V_118 -> V_119 ) == NULL ) {
F_27 ( & V_89 -> V_90 , L_21 ,
V_5 -> V_88 , V_5 -> V_117 ) ;
V_105 = - V_120 ;
goto V_115;
}
V_5 -> V_12 . V_13 = F_50 ( V_5 -> V_88 , V_5 -> V_117 ) ;
if ( V_5 -> V_12 . V_13 == NULL ) {
V_105 = - V_110 ;
goto V_121;
}
if ( V_104 -> V_122 != NULL ) {
V_105 = V_104 -> V_122 ( V_5 -> V_12 . V_13 , & V_5 -> V_123 ) ;
if ( V_105 < 0 ) {
F_27 ( & V_89 -> V_90 , L_22
L_23 , V_105 ) ;
goto V_124;
}
V_5 -> V_125 = V_104 -> V_122 ;
}
if ( V_5 -> V_47 ) {
if ( ( V_105 = F_51 ( V_5 -> V_47 , L_24 ) ) < 0 ) {
F_27 ( & V_89 -> V_90 , L_25
L_26 , V_5 -> V_47 ) ;
goto V_124;
}
F_52 ( V_5 -> V_47 ) ;
if ( ( V_105 = F_53 ( F_54 ( V_5 -> V_47 ) ,
F_3 , V_126 ,
V_89 -> V_90 . V_118 -> V_119 , V_5 ) ) < 0 )
goto V_127;
}
if ( V_5 -> V_92 >= 0 ) {
V_105 = F_55 ( 0 , V_89 -> V_90 . V_118 -> V_119 ,
F_1 , ( void * ) V_5 ,
& V_5 -> V_92 ) ;
if ( V_105 == 0 ) {
F_56 ( V_5 -> V_92 ,
V_128 ) ;
F_57 ( V_5 -> V_92 , 1 ) ;
F_58 ( V_5 -> V_92 ,
V_129 ) ;
F_59 ( V_5 -> V_92 , 1 ) ;
F_60 ( V_5 -> V_92 ,
V_129 ) ;
} else {
F_61 ( & V_89 -> V_90 ,
L_27
L_28 ) ;
V_5 -> V_92 = - 1 ;
}
}
F_61 ( & V_89 -> V_90 , L_29
L_30 , V_5 -> V_111 , V_5 -> V_88 ,
V_5 -> V_12 . V_13 , V_5 -> V_123 ) ;
V_5 -> V_89 = V_89 ;
V_5 -> V_22 . V_25 = & V_5 -> V_12 ;
V_5 -> V_22 . V_90 . V_130 = & V_89 -> V_90 ;
F_62 ( & V_5 -> V_22 , V_104 -> V_131 ) ;
V_24 = & V_5 -> V_12 ;
if ( V_5 -> V_92 >= 0 ) {
V_24 -> V_132 = F_11 ;
if ( V_5 -> V_45 & V_46 ) {
V_24 -> V_133 = F_21 ;
V_24 -> V_134 = F_33 ;
} else {
V_24 -> V_133 = F_34 ;
V_24 -> V_134 = F_36 ;
}
}
if ( V_104 -> V_135 ) {
V_5 -> V_102 = F_63 ( & V_89 -> V_90 , L_31 ) ;
if ( F_64 ( V_5 -> V_102 ) ) {
F_27 ( & V_89 -> V_90 , L_32 ) ;
V_105 = F_65 ( V_5 -> V_102 ) ;
goto V_136;
}
V_5 -> V_12 . V_137 = F_39 ;
V_5 -> V_12 . V_138 = F_41 ;
}
if ( V_104 -> V_139 )
V_24 -> V_140 |= V_141 ;
if ( ( V_105 = F_66 ( & V_5 -> V_22 , 1 ) ) < 0 )
goto V_142;
V_105 = F_67 ( & V_5 -> V_22 , V_104 ? V_104 -> V_143 : NULL ,
V_104 ? V_104 -> V_144 : 0 ) ;
if ( V_105 )
goto V_145;
F_68 ( V_89 , V_5 ) ;
return 0 ;
V_145:
F_69 ( & V_5 -> V_22 ) ;
V_142:
F_70 ( V_5 -> V_102 ) ;
V_136:
if ( V_5 -> V_92 != - 1 )
F_71 ( V_5 -> V_92 ) ;
if ( V_5 -> V_47 )
F_72 ( F_54 ( V_5 -> V_47 ) , V_5 ) ;
V_127:
if ( V_5 -> V_47 )
F_73 ( V_5 -> V_47 ) ;
V_124:
F_74 ( V_5 -> V_12 . V_13 ) ;
V_121:
F_75 ( V_5 -> V_88 , V_5 -> V_117 ) ;
V_115:
F_76 ( V_5 ) ;
return V_105 ;
}
static int F_77 ( struct V_99 * V_89 )
{
struct V_4 * V_5 = F_38 ( & V_89 -> V_90 ) ;
F_69 ( & V_5 -> V_22 ) ;
F_70 ( V_5 -> V_102 ) ;
if ( V_5 -> V_92 != - 1 )
F_71 ( V_5 -> V_92 ) ;
F_37 ( V_89 ) ;
if ( V_5 -> V_47 ) {
F_72 ( F_54 ( V_5 -> V_47 ) , V_5 ) ;
F_73 ( V_5 -> V_47 ) ;
}
F_74 ( V_5 -> V_12 . V_13 ) ;
F_75 ( V_5 -> V_88 , V_5 -> V_117 ) ;
F_76 ( V_5 ) ;
return 0 ;
}
