static inline int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_3 == V_4 ||
V_2 -> V_3 == V_5 ) )
return V_6 * V_7 ;
else
return V_7 ;
}
static int F_3 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
unsigned long V_13 ;
int V_14 = 0 ;
F_5 ( & V_12 -> V_15 , V_13 ) ;
if ( V_12 -> V_16 )
V_14 = - V_17 ;
else if ( V_10 <= V_18 || V_10 > V_19 )
V_14 = - V_20 ;
else
V_9 -> V_21 = V_10 ;
F_6 ( & V_12 -> V_15 , V_13 ) ;
return V_14 ;
}
static void F_7 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
F_8 ( V_23 -> V_24 , L_1 , sizeof( V_23 -> V_24 ) ) ;
F_8 ( V_23 -> V_25 , V_26 , sizeof( V_23 -> V_25 ) ) ;
F_8 ( V_23 -> V_27 , V_12 -> V_2 -> V_28 , sizeof( V_23 -> V_27 ) ) ;
F_8 ( V_23 -> V_29 , F_9 ( & V_12 -> V_2 -> V_12 ) , sizeof( V_23 -> V_29 ) ) ;
}
static void F_10 ( struct V_11 * V_12 , int V_30 )
{
if ( F_11 ( V_30 , & V_12 -> V_31 ) )
return;
if ( ! F_12 ( & V_12 -> V_32 ) )
ERROR ( V_12 , L_2 , V_30 ) ;
else
F_13 ( V_12 , L_3 , V_30 ) ;
}
static int
F_14 ( struct V_11 * V_12 , struct V_33 * V_34 , T_1 V_35 )
{
struct V_36 * V_37 ;
int V_38 = - V_39 ;
T_2 V_40 = 0 ;
struct V_41 * V_42 ;
unsigned long V_13 ;
F_5 ( & V_12 -> V_15 , V_13 ) ;
if ( V_12 -> V_16 )
V_42 = V_12 -> V_16 -> V_43 ;
else
V_42 = NULL ;
F_6 ( & V_12 -> V_15 , V_13 ) ;
if ( ! V_42 )
return - V_44 ;
V_40 += sizeof( struct V_45 ) + V_12 -> V_9 -> V_21 + V_46 ;
V_40 += V_12 -> V_16 -> V_47 ;
V_40 += V_42 -> V_48 - 1 ;
V_40 -= V_40 % V_42 -> V_48 ;
if ( V_12 -> V_16 -> V_49 )
V_40 = F_15 ( T_2 , V_40 , V_12 -> V_16 -> V_50 ) ;
V_37 = F_16 ( V_40 + V_51 , V_35 ) ;
if ( V_37 == NULL ) {
F_13 ( V_12 , L_4 ) ;
goto V_52;
}
F_17 ( V_37 , V_51 ) ;
V_34 -> V_53 = V_37 -> V_54 ;
V_34 -> V_55 = V_40 ;
V_34 -> V_56 = V_57 ;
V_34 -> V_58 = V_37 ;
V_38 = F_18 ( V_42 , V_34 , V_35 ) ;
if ( V_38 == - V_39 )
V_52:
F_10 ( V_12 , V_59 ) ;
if ( V_38 ) {
F_13 ( V_12 , L_5 , V_38 ) ;
if ( V_37 )
F_19 ( V_37 ) ;
F_5 ( & V_12 -> V_60 , V_13 ) ;
F_20 ( & V_34 -> V_61 , & V_12 -> V_62 ) ;
F_6 ( & V_12 -> V_60 , V_13 ) ;
}
return V_38 ;
}
static void V_57 ( struct V_41 * V_63 , struct V_33 * V_34 )
{
struct V_36 * V_37 = V_34 -> V_58 , * V_64 ;
struct V_11 * V_12 = V_63 -> V_65 ;
int V_14 = V_34 -> V_14 ;
switch ( V_14 ) {
case 0 :
F_21 ( V_37 , V_34 -> V_66 ) ;
if ( V_12 -> V_67 ) {
unsigned long V_13 ;
F_5 ( & V_12 -> V_15 , V_13 ) ;
if ( V_12 -> V_16 ) {
V_14 = V_12 -> V_67 ( V_12 -> V_16 ,
V_37 ,
& V_12 -> V_68 ) ;
} else {
F_19 ( V_37 ) ;
V_14 = - V_44 ;
}
F_6 ( & V_12 -> V_15 , V_13 ) ;
} else {
F_22 ( & V_12 -> V_68 , V_37 ) ;
}
V_37 = NULL ;
V_64 = F_23 ( & V_12 -> V_68 ) ;
while ( V_64 ) {
if ( V_14 < 0
|| V_18 > V_64 -> V_69
|| V_64 -> V_69 > V_70 ) {
V_12 -> V_9 -> V_71 . V_72 ++ ;
V_12 -> V_9 -> V_71 . V_73 ++ ;
F_13 ( V_12 , L_6 , V_64 -> V_69 ) ;
F_19 ( V_64 ) ;
goto V_74;
}
V_64 -> V_75 = F_24 ( V_64 , V_12 -> V_9 ) ;
V_12 -> V_9 -> V_71 . V_76 ++ ;
V_12 -> V_9 -> V_71 . V_77 += V_64 -> V_69 ;
V_14 = F_25 ( V_64 ) ;
V_74:
V_64 = F_23 ( & V_12 -> V_68 ) ;
}
break;
case - V_78 :
case - V_79 :
F_26 ( V_12 , L_7 , V_14 ) ;
goto V_80;
case - V_81 :
F_13 ( V_12 , L_8 , V_63 -> V_28 ) ;
F_10 ( V_12 , V_59 ) ;
V_80:
F_19 ( V_37 ) ;
goto V_82;
case - V_83 :
V_12 -> V_9 -> V_71 . V_84 ++ ;
default:
V_12 -> V_9 -> V_71 . V_72 ++ ;
F_13 ( V_12 , L_9 , V_14 ) ;
break;
}
if ( V_37 )
F_19 ( V_37 ) ;
if ( ! F_27 ( V_12 -> V_9 ) ) {
V_82:
F_28 ( & V_12 -> V_60 ) ;
F_20 ( & V_34 -> V_61 , & V_12 -> V_62 ) ;
F_29 ( & V_12 -> V_60 ) ;
V_34 = NULL ;
}
if ( V_34 )
F_14 ( V_12 , V_34 , V_85 ) ;
}
static int F_30 ( struct V_86 * V_61 , struct V_41 * V_63 , unsigned V_87 )
{
unsigned V_88 ;
struct V_33 * V_34 ;
if ( ! V_87 )
return - V_39 ;
V_88 = V_87 ;
F_31 (req, list, list) {
if ( V_88 -- == 0 )
goto V_89;
}
while ( V_88 -- ) {
V_34 = F_32 ( V_63 , V_85 ) ;
if ( ! V_34 )
return F_33 ( V_61 ) ? - V_39 : 0 ;
F_20 ( & V_34 -> V_61 , V_61 ) ;
}
return 0 ;
V_89:
for (; ; ) {
struct V_86 * V_90 ;
V_90 = V_34 -> V_61 . V_90 ;
F_34 ( & V_34 -> V_61 ) ;
F_35 ( V_63 , V_34 ) ;
if ( V_90 == V_61 )
break;
V_34 = F_36 ( V_90 , struct V_33 , V_61 ) ;
}
return 0 ;
}
static int F_37 ( struct V_11 * V_12 , struct V_91 * V_92 , unsigned V_87 )
{
int V_14 ;
F_28 ( & V_12 -> V_60 ) ;
V_14 = F_30 ( & V_12 -> V_93 , V_92 -> V_94 , V_87 ) ;
if ( V_14 < 0 )
goto V_95;
V_14 = F_30 ( & V_12 -> V_62 , V_92 -> V_43 , V_87 ) ;
if ( V_14 < 0 )
goto V_95;
goto V_96;
V_95:
F_13 ( V_12 , L_10 ) ;
V_96:
F_29 ( & V_12 -> V_60 ) ;
return V_14 ;
}
static void F_38 ( struct V_11 * V_12 , T_1 V_35 )
{
struct V_33 * V_34 ;
unsigned long V_13 ;
F_5 ( & V_12 -> V_60 , V_13 ) ;
while ( ! F_33 ( & V_12 -> V_62 ) ) {
V_34 = F_36 ( V_12 -> V_62 . V_90 ,
struct V_33 , V_61 ) ;
F_39 ( & V_34 -> V_61 ) ;
F_6 ( & V_12 -> V_60 , V_13 ) ;
if ( F_14 ( V_12 , V_34 , V_35 ) < 0 ) {
F_10 ( V_12 , V_59 ) ;
return;
}
F_5 ( & V_12 -> V_60 , V_13 ) ;
}
F_6 ( & V_12 -> V_60 , V_13 ) ;
}
static void F_40 ( struct V_97 * V_32 )
{
struct V_11 * V_12 = F_36 ( V_32 , struct V_11 , V_32 ) ;
if ( F_41 ( V_59 , & V_12 -> V_31 ) ) {
if ( F_27 ( V_12 -> V_9 ) )
F_38 ( V_12 , V_98 ) ;
}
if ( V_12 -> V_31 )
F_13 ( V_12 , L_11 , V_12 -> V_31 ) ;
}
static void F_42 ( struct V_41 * V_63 , struct V_33 * V_34 )
{
struct V_36 * V_37 = V_34 -> V_58 ;
struct V_11 * V_12 = V_63 -> V_65 ;
switch ( V_34 -> V_14 ) {
default:
V_12 -> V_9 -> V_71 . V_99 ++ ;
F_26 ( V_12 , L_12 , V_34 -> V_14 ) ;
case - V_78 :
case - V_79 :
break;
case 0 :
V_12 -> V_9 -> V_71 . V_100 += V_37 -> V_69 ;
}
V_12 -> V_9 -> V_71 . V_101 ++ ;
F_28 ( & V_12 -> V_60 ) ;
F_20 ( & V_34 -> V_61 , & V_12 -> V_93 ) ;
F_29 ( & V_12 -> V_60 ) ;
F_19 ( V_37 ) ;
F_43 ( & V_12 -> V_102 ) ;
if ( F_44 ( V_12 -> V_9 ) )
F_45 ( V_12 -> V_9 ) ;
}
static inline int F_46 ( T_3 V_103 )
{
return V_103 & V_104 ;
}
static T_4 F_47 ( struct V_36 * V_37 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
int V_55 = V_37 -> V_69 ;
int V_38 ;
struct V_33 * V_34 = NULL ;
unsigned long V_13 ;
struct V_41 * V_105 ;
T_3 V_103 ;
F_5 ( & V_12 -> V_15 , V_13 ) ;
if ( V_12 -> V_16 ) {
V_105 = V_12 -> V_16 -> V_94 ;
V_103 = V_12 -> V_16 -> V_103 ;
} else {
V_105 = NULL ;
V_103 = 0 ;
}
F_6 ( & V_12 -> V_15 , V_13 ) ;
if ( ! V_105 ) {
F_19 ( V_37 ) ;
return V_106 ;
}
if ( ! F_46 ( V_103 ) ) {
T_5 * V_107 = V_37 -> V_54 ;
if ( F_48 ( V_107 ) ) {
T_3 type ;
if ( F_49 ( V_107 ) )
type = V_108 ;
else
type = V_109 ;
if ( ! ( V_103 & type ) ) {
F_19 ( V_37 ) ;
return V_106 ;
}
}
}
F_5 ( & V_12 -> V_60 , V_13 ) ;
if ( F_33 ( & V_12 -> V_93 ) ) {
F_6 ( & V_12 -> V_60 , V_13 ) ;
return V_110 ;
}
V_34 = F_36 ( V_12 -> V_93 . V_90 , struct V_33 , V_61 ) ;
F_34 ( & V_34 -> V_61 ) ;
if ( F_33 ( & V_12 -> V_93 ) )
F_50 ( V_9 ) ;
F_6 ( & V_12 -> V_60 , V_13 ) ;
if ( V_12 -> V_111 ) {
unsigned long V_13 ;
F_5 ( & V_12 -> V_15 , V_13 ) ;
if ( V_12 -> V_16 )
V_37 = V_12 -> V_111 ( V_12 -> V_16 , V_37 ) ;
F_6 ( & V_12 -> V_15 , V_13 ) ;
if ( ! V_37 )
goto V_112;
V_55 = V_37 -> V_69 ;
}
V_34 -> V_53 = V_37 -> V_54 ;
V_34 -> V_58 = V_37 ;
V_34 -> V_56 = F_42 ;
if ( V_12 -> V_16 -> V_49 &&
V_55 == V_12 -> V_16 -> V_113 &&
( V_55 % V_105 -> V_48 ) == 0 )
V_34 -> V_114 = 0 ;
else
V_34 -> V_114 = 1 ;
if ( V_34 -> V_114 && ! V_12 -> V_115 && ( V_55 % V_105 -> V_48 ) == 0 )
V_55 ++ ;
V_34 -> V_55 = V_55 ;
if ( F_2 ( V_12 -> V_2 ) )
V_34 -> V_116 = ( V_12 -> V_2 -> V_3 == V_4 ||
V_12 -> V_2 -> V_3 == V_5 )
? ( ( F_51 ( & V_12 -> V_102 ) % V_6 ) != 0 )
: 0 ;
V_38 = F_18 ( V_105 , V_34 , V_85 ) ;
switch ( V_38 ) {
default:
F_13 ( V_12 , L_13 , V_38 ) ;
break;
case 0 :
V_9 -> V_117 = V_118 ;
F_52 ( & V_12 -> V_102 ) ;
}
if ( V_38 ) {
F_19 ( V_37 ) ;
V_112:
V_12 -> V_9 -> V_71 . V_119 ++ ;
F_5 ( & V_12 -> V_60 , V_13 ) ;
if ( F_33 ( & V_12 -> V_93 ) )
F_53 ( V_9 ) ;
F_20 ( & V_34 -> V_61 , & V_12 -> V_93 ) ;
F_6 ( & V_12 -> V_60 , V_13 ) ;
}
return V_106 ;
}
static void F_54 ( struct V_11 * V_12 , T_1 V_35 )
{
F_13 ( V_12 , L_14 , V_120 ) ;
F_38 ( V_12 , V_35 ) ;
F_55 ( & V_12 -> V_102 , 0 ) ;
F_45 ( V_12 -> V_9 ) ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
struct V_91 * V_92 ;
F_13 ( V_12 , L_14 , V_120 ) ;
if ( F_44 ( V_12 -> V_9 ) )
F_54 ( V_12 , V_98 ) ;
F_57 ( & V_12 -> V_15 ) ;
V_92 = V_12 -> V_16 ;
if ( V_92 && V_92 -> V_121 )
V_92 -> V_121 ( V_92 ) ;
F_58 ( & V_12 -> V_15 ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_4 ( V_9 ) ;
unsigned long V_13 ;
F_26 ( V_12 , L_14 , V_120 ) ;
F_50 ( V_9 ) ;
F_13 ( V_12 , L_15 ,
V_12 -> V_9 -> V_71 . V_76 , V_12 -> V_9 -> V_71 . V_101 ,
V_12 -> V_9 -> V_71 . V_72 , V_12 -> V_9 -> V_71 . V_99
) ;
F_5 ( & V_12 -> V_15 , V_13 ) ;
if ( V_12 -> V_16 ) {
struct V_91 * V_92 = V_12 -> V_16 ;
const struct V_122 * V_105 ;
const struct V_122 * V_42 ;
if ( V_92 -> V_123 )
V_92 -> V_123 ( V_92 ) ;
V_105 = V_92 -> V_94 -> V_124 ;
V_42 = V_92 -> V_43 -> V_124 ;
F_60 ( V_92 -> V_94 ) ;
F_60 ( V_92 -> V_43 ) ;
if ( F_44 ( V_9 ) ) {
F_13 ( V_12 , L_16 ) ;
V_92 -> V_94 -> V_124 = V_105 ;
V_92 -> V_43 -> V_124 = V_42 ;
F_61 ( V_92 -> V_94 ) ;
F_61 ( V_92 -> V_43 ) ;
}
}
F_6 ( & V_12 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_62 ( const char * V_125 , T_5 * V_126 )
{
if ( V_125 ) {
unsigned V_88 ;
for ( V_88 = 0 ; V_88 < 6 ; V_88 ++ ) {
unsigned char V_127 ;
if ( ( * V_125 == '.' ) || ( * V_125 == ':' ) )
V_125 ++ ;
V_127 = F_63 ( * V_125 ++ ) << 4 ;
V_127 |= F_63 ( * V_125 ++ ) ;
V_126 [ V_88 ] = V_127 ;
}
if ( F_64 ( V_126 ) )
return 0 ;
}
F_65 ( V_126 ) ;
return 1 ;
}
struct V_11 * F_66 ( struct V_1 * V_128 , T_5 V_129 [ V_130 ] ,
const char * V_131 )
{
struct V_11 * V_12 ;
struct V_8 * V_9 ;
int V_14 ;
V_9 = F_67 ( sizeof *V_12 ) ;
if ( ! V_9 )
return F_68 ( - V_39 ) ;
V_12 = F_4 ( V_9 ) ;
F_69 ( & V_12 -> V_15 ) ;
F_69 ( & V_12 -> V_60 ) ;
F_70 ( & V_12 -> V_32 , F_40 ) ;
F_71 ( & V_12 -> V_93 ) ;
F_71 ( & V_12 -> V_62 ) ;
F_72 ( & V_12 -> V_68 ) ;
V_12 -> V_9 = V_9 ;
snprintf ( V_9 -> V_28 , sizeof( V_9 -> V_28 ) , L_17 , V_131 ) ;
if ( F_62 ( V_126 , V_9 -> V_126 ) )
F_73 ( & V_128 -> V_12 ,
L_18 , L_19 ) ;
if ( F_62 ( V_132 , V_12 -> V_133 ) )
F_73 ( & V_128 -> V_12 ,
L_18 , L_20 ) ;
if ( V_129 )
memcpy ( V_129 , V_12 -> V_133 , V_130 ) ;
V_9 -> V_134 = & V_135 ;
F_74 ( V_9 , & V_136 ) ;
V_12 -> V_2 = V_128 ;
F_75 ( V_9 , & V_128 -> V_12 ) ;
F_76 ( V_9 , & V_137 ) ;
V_14 = F_77 ( V_9 ) ;
if ( V_14 < 0 ) {
F_78 ( & V_128 -> V_12 , L_21 , V_14 ) ;
F_79 ( V_9 ) ;
V_12 = F_68 ( V_14 ) ;
} else {
F_80 ( V_12 , L_22 , V_9 -> V_126 ) ;
F_80 ( V_12 , L_23 , V_12 -> V_133 ) ;
F_81 ( V_9 ) ;
}
return V_12 ;
}
void F_82 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_83 ( V_12 -> V_9 ) ;
F_84 ( & V_12 -> V_32 ) ;
F_79 ( V_12 -> V_9 ) ;
}
struct V_8 * F_85 ( struct V_91 * V_92 )
{
struct V_11 * V_12 = V_92 -> V_138 ;
int V_139 = 0 ;
if ( ! V_12 )
return F_68 ( - V_140 ) ;
V_92 -> V_94 -> V_65 = V_12 ;
V_139 = F_61 ( V_92 -> V_94 ) ;
if ( V_139 != 0 ) {
F_13 ( V_12 , L_24 ,
V_92 -> V_94 -> V_28 , V_139 ) ;
goto V_141;
}
V_92 -> V_43 -> V_65 = V_12 ;
V_139 = F_61 ( V_92 -> V_43 ) ;
if ( V_139 != 0 ) {
F_13 ( V_12 , L_24 ,
V_92 -> V_43 -> V_28 , V_139 ) ;
goto V_142;
}
if ( V_139 == 0 )
V_139 = F_37 ( V_12 , V_92 , F_1 ( V_12 -> V_2 ) ) ;
if ( V_139 == 0 ) {
V_12 -> V_115 = V_92 -> V_143 ;
F_13 ( V_12 , L_25 , F_1 ( V_12 -> V_2 ) ) ;
V_12 -> V_47 = V_92 -> V_47 ;
V_12 -> V_67 = V_92 -> V_67 ;
V_12 -> V_111 = V_92 -> V_111 ;
F_28 ( & V_12 -> V_15 ) ;
V_12 -> V_16 = V_92 ;
if ( F_27 ( V_12 -> V_9 ) ) {
if ( V_92 -> V_121 )
V_92 -> V_121 ( V_92 ) ;
} else {
if ( V_92 -> V_123 )
V_92 -> V_123 ( V_92 ) ;
}
F_29 ( & V_12 -> V_15 ) ;
F_86 ( V_12 -> V_9 ) ;
if ( F_27 ( V_12 -> V_9 ) )
F_54 ( V_12 , V_85 ) ;
} else {
( void ) F_60 ( V_92 -> V_43 ) ;
V_142:
( void ) F_60 ( V_92 -> V_94 ) ;
}
V_141:
if ( V_139 < 0 )
return F_68 ( V_139 ) ;
return V_12 -> V_9 ;
}
void F_87 ( struct V_91 * V_92 )
{
struct V_11 * V_12 = V_92 -> V_138 ;
struct V_33 * V_34 ;
F_88 ( ! V_12 ) ;
if ( ! V_12 )
return;
F_13 ( V_12 , L_14 , V_120 ) ;
F_50 ( V_12 -> V_9 ) ;
F_81 ( V_12 -> V_9 ) ;
F_60 ( V_92 -> V_94 ) ;
F_28 ( & V_12 -> V_60 ) ;
while ( ! F_33 ( & V_12 -> V_93 ) ) {
V_34 = F_36 ( V_12 -> V_93 . V_90 ,
struct V_33 , V_61 ) ;
F_34 ( & V_34 -> V_61 ) ;
F_29 ( & V_12 -> V_60 ) ;
F_35 ( V_92 -> V_94 , V_34 ) ;
F_28 ( & V_12 -> V_60 ) ;
}
F_29 ( & V_12 -> V_60 ) ;
V_92 -> V_94 -> V_65 = NULL ;
V_92 -> V_94 -> V_124 = NULL ;
F_60 ( V_92 -> V_43 ) ;
F_28 ( & V_12 -> V_60 ) ;
while ( ! F_33 ( & V_12 -> V_62 ) ) {
V_34 = F_36 ( V_12 -> V_62 . V_90 ,
struct V_33 , V_61 ) ;
F_34 ( & V_34 -> V_61 ) ;
F_29 ( & V_12 -> V_60 ) ;
F_35 ( V_92 -> V_43 , V_34 ) ;
F_28 ( & V_12 -> V_60 ) ;
}
F_29 ( & V_12 -> V_60 ) ;
V_92 -> V_43 -> V_65 = NULL ;
V_92 -> V_43 -> V_124 = NULL ;
V_12 -> V_47 = 0 ;
V_12 -> V_67 = NULL ;
V_12 -> V_111 = NULL ;
F_28 ( & V_12 -> V_15 ) ;
V_12 -> V_16 = NULL ;
F_29 ( & V_12 -> V_15 ) ;
}
