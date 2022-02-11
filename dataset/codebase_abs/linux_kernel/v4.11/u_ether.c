static inline int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_4 == V_5 ||
V_2 -> V_4 == V_6 ) )
return V_3 * V_7 ;
else
return V_7 ;
}
static void F_3 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
F_5 ( V_11 -> V_14 , L_1 , sizeof( V_11 -> V_14 ) ) ;
F_5 ( V_11 -> V_15 , V_16 , sizeof( V_11 -> V_15 ) ) ;
F_5 ( V_11 -> V_17 , V_13 -> V_2 -> V_18 , sizeof( V_11 -> V_17 ) ) ;
F_5 ( V_11 -> V_19 , F_6 ( & V_13 -> V_2 -> V_13 ) , sizeof( V_11 -> V_19 ) ) ;
}
static void F_7 ( struct V_12 * V_13 , int V_20 )
{
if ( F_8 ( V_20 , & V_13 -> V_21 ) )
return;
if ( ! F_9 ( & V_13 -> V_22 ) )
ERROR ( V_13 , L_2 , V_20 ) ;
else
F_10 ( V_13 , L_3 , V_20 ) ;
}
static int
F_11 ( struct V_12 * V_13 , struct V_23 * V_24 , T_1 V_25 )
{
struct V_26 * V_27 ;
int V_28 = - V_29 ;
T_2 V_30 = 0 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
F_12 ( & V_13 -> V_34 , V_33 ) ;
if ( V_13 -> V_35 )
V_32 = V_13 -> V_35 -> V_36 ;
else
V_32 = NULL ;
F_13 ( & V_13 -> V_34 , V_33 ) ;
if ( ! V_32 )
return - V_37 ;
V_30 += sizeof( struct V_38 ) + V_13 -> V_9 -> V_39 + V_40 ;
V_30 += V_13 -> V_35 -> V_41 ;
V_30 += V_32 -> V_42 - 1 ;
V_30 -= V_30 % V_32 -> V_42 ;
if ( V_13 -> V_35 -> V_43 )
V_30 = F_14 ( T_2 , V_30 , V_13 -> V_35 -> V_44 ) ;
V_27 = F_15 ( V_13 -> V_9 , V_30 + V_45 , V_25 ) ;
if ( V_27 == NULL ) {
F_10 ( V_13 , L_4 ) ;
goto V_46;
}
if ( F_16 ( ! V_13 -> V_47 ) )
F_17 ( V_27 , V_45 ) ;
V_24 -> V_48 = V_27 -> V_49 ;
V_24 -> V_50 = V_30 ;
V_24 -> V_51 = V_52 ;
V_24 -> V_53 = V_27 ;
V_28 = F_18 ( V_32 , V_24 , V_25 ) ;
if ( V_28 == - V_29 )
V_46:
F_7 ( V_13 , V_54 ) ;
if ( V_28 ) {
F_10 ( V_13 , L_5 , V_28 ) ;
if ( V_27 )
F_19 ( V_27 ) ;
F_12 ( & V_13 -> V_55 , V_33 ) ;
F_20 ( & V_24 -> V_56 , & V_13 -> V_57 ) ;
F_13 ( & V_13 -> V_55 , V_33 ) ;
}
return V_28 ;
}
static void V_52 ( struct V_31 * V_58 , struct V_23 * V_24 )
{
struct V_26 * V_27 = V_24 -> V_53 , * V_59 ;
struct V_12 * V_13 = V_58 -> V_60 ;
int V_61 = V_24 -> V_61 ;
switch ( V_61 ) {
case 0 :
F_21 ( V_27 , V_24 -> V_62 ) ;
if ( V_13 -> V_63 ) {
unsigned long V_33 ;
F_12 ( & V_13 -> V_34 , V_33 ) ;
if ( V_13 -> V_35 ) {
V_61 = V_13 -> V_63 ( V_13 -> V_35 ,
V_27 ,
& V_13 -> V_64 ) ;
} else {
F_19 ( V_27 ) ;
V_61 = - V_37 ;
}
F_13 ( & V_13 -> V_34 , V_33 ) ;
} else {
F_22 ( & V_13 -> V_64 , V_27 ) ;
}
V_27 = NULL ;
V_59 = F_23 ( & V_13 -> V_64 ) ;
while ( V_59 ) {
if ( V_61 < 0
|| V_65 > V_59 -> V_66
|| V_59 -> V_66 > V_67 ) {
V_13 -> V_9 -> V_68 . V_69 ++ ;
V_13 -> V_9 -> V_68 . V_70 ++ ;
F_10 ( V_13 , L_6 , V_59 -> V_66 ) ;
F_19 ( V_59 ) ;
goto V_71;
}
V_59 -> V_72 = F_24 ( V_59 , V_13 -> V_9 ) ;
V_13 -> V_9 -> V_68 . V_73 ++ ;
V_13 -> V_9 -> V_68 . V_74 += V_59 -> V_66 ;
V_61 = F_25 ( V_59 ) ;
V_71:
V_59 = F_23 ( & V_13 -> V_64 ) ;
}
break;
case - V_75 :
case - V_76 :
F_26 ( V_13 , L_7 , V_61 ) ;
goto V_77;
case - V_78 :
F_10 ( V_13 , L_8 , V_58 -> V_18 ) ;
F_7 ( V_13 , V_54 ) ;
V_77:
F_19 ( V_27 ) ;
goto V_79;
case - V_80 :
V_13 -> V_9 -> V_68 . V_81 ++ ;
default:
V_13 -> V_9 -> V_68 . V_69 ++ ;
F_10 ( V_13 , L_9 , V_61 ) ;
break;
}
if ( V_27 )
F_19 ( V_27 ) ;
if ( ! F_27 ( V_13 -> V_9 ) ) {
V_79:
F_28 ( & V_13 -> V_55 ) ;
F_20 ( & V_24 -> V_56 , & V_13 -> V_57 ) ;
F_29 ( & V_13 -> V_55 ) ;
V_24 = NULL ;
}
if ( V_24 )
F_11 ( V_13 , V_24 , V_82 ) ;
}
static int F_30 ( struct V_83 * V_56 , struct V_31 * V_58 , unsigned V_84 )
{
unsigned V_85 ;
struct V_23 * V_24 ;
if ( ! V_84 )
return - V_29 ;
V_85 = V_84 ;
F_31 (req, list, list) {
if ( V_85 -- == 0 )
goto V_86;
}
while ( V_85 -- ) {
V_24 = F_32 ( V_58 , V_82 ) ;
if ( ! V_24 )
return F_33 ( V_56 ) ? - V_29 : 0 ;
F_20 ( & V_24 -> V_56 , V_56 ) ;
}
return 0 ;
V_86:
for (; ; ) {
struct V_83 * V_87 ;
V_87 = V_24 -> V_56 . V_87 ;
F_34 ( & V_24 -> V_56 ) ;
F_35 ( V_58 , V_24 ) ;
if ( V_87 == V_56 )
break;
V_24 = F_36 ( V_87 , struct V_23 , V_56 ) ;
}
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_88 * V_89 , unsigned V_84 )
{
int V_61 ;
F_28 ( & V_13 -> V_55 ) ;
V_61 = F_30 ( & V_13 -> V_90 , V_89 -> V_91 , V_84 ) ;
if ( V_61 < 0 )
goto V_92;
V_61 = F_30 ( & V_13 -> V_57 , V_89 -> V_36 , V_84 ) ;
if ( V_61 < 0 )
goto V_92;
goto V_93;
V_92:
F_10 ( V_13 , L_10 ) ;
V_93:
F_29 ( & V_13 -> V_55 ) ;
return V_61 ;
}
static void F_38 ( struct V_12 * V_13 , T_1 V_25 )
{
struct V_23 * V_24 ;
unsigned long V_33 ;
F_12 ( & V_13 -> V_55 , V_33 ) ;
while ( ! F_33 ( & V_13 -> V_57 ) ) {
V_24 = F_36 ( V_13 -> V_57 . V_87 ,
struct V_23 , V_56 ) ;
F_39 ( & V_24 -> V_56 ) ;
F_13 ( & V_13 -> V_55 , V_33 ) ;
if ( F_11 ( V_13 , V_24 , V_25 ) < 0 ) {
F_7 ( V_13 , V_54 ) ;
return;
}
F_12 ( & V_13 -> V_55 , V_33 ) ;
}
F_13 ( & V_13 -> V_55 , V_33 ) ;
}
static void F_40 ( struct V_94 * V_22 )
{
struct V_12 * V_13 = F_36 ( V_22 , struct V_12 , V_22 ) ;
if ( F_41 ( V_54 , & V_13 -> V_21 ) ) {
if ( F_27 ( V_13 -> V_9 ) )
F_38 ( V_13 , V_95 ) ;
}
if ( V_13 -> V_21 )
F_10 ( V_13 , L_11 , V_13 -> V_21 ) ;
}
static void F_42 ( struct V_31 * V_58 , struct V_23 * V_24 )
{
struct V_26 * V_27 = V_24 -> V_53 ;
struct V_12 * V_13 = V_58 -> V_60 ;
switch ( V_24 -> V_61 ) {
default:
V_13 -> V_9 -> V_68 . V_96 ++ ;
F_26 ( V_13 , L_12 , V_24 -> V_61 ) ;
case - V_75 :
case - V_76 :
F_19 ( V_27 ) ;
break;
case 0 :
V_13 -> V_9 -> V_68 . V_97 += V_27 -> V_66 ;
F_43 ( V_27 ) ;
}
V_13 -> V_9 -> V_68 . V_98 ++ ;
F_28 ( & V_13 -> V_55 ) ;
F_20 ( & V_24 -> V_56 , & V_13 -> V_90 ) ;
F_29 ( & V_13 -> V_55 ) ;
F_44 ( & V_13 -> V_99 ) ;
if ( F_45 ( V_13 -> V_9 ) )
F_46 ( V_13 -> V_9 ) ;
}
static inline int F_47 ( T_3 V_100 )
{
return V_100 & V_101 ;
}
static T_4 F_48 ( struct V_26 * V_27 ,
struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
int V_50 = 0 ;
int V_28 ;
struct V_23 * V_24 = NULL ;
unsigned long V_33 ;
struct V_31 * V_102 ;
T_3 V_100 ;
F_12 ( & V_13 -> V_34 , V_33 ) ;
if ( V_13 -> V_35 ) {
V_102 = V_13 -> V_35 -> V_91 ;
V_100 = V_13 -> V_35 -> V_100 ;
} else {
V_102 = NULL ;
V_100 = 0 ;
}
F_13 ( & V_13 -> V_34 , V_33 ) ;
if ( V_27 && ! V_102 ) {
F_19 ( V_27 ) ;
return V_103 ;
}
if ( V_27 && ! F_47 ( V_100 ) ) {
T_5 * V_104 = V_27 -> V_49 ;
if ( F_49 ( V_104 ) ) {
T_3 type ;
if ( F_50 ( V_104 ) )
type = V_105 ;
else
type = V_106 ;
if ( ! ( V_100 & type ) ) {
F_19 ( V_27 ) ;
return V_103 ;
}
}
}
F_12 ( & V_13 -> V_55 , V_33 ) ;
if ( F_33 ( & V_13 -> V_90 ) ) {
F_13 ( & V_13 -> V_55 , V_33 ) ;
return V_107 ;
}
V_24 = F_36 ( V_13 -> V_90 . V_87 , struct V_23 , V_56 ) ;
F_34 ( & V_24 -> V_56 ) ;
if ( F_33 ( & V_13 -> V_90 ) )
F_51 ( V_9 ) ;
F_13 ( & V_13 -> V_55 , V_33 ) ;
if ( V_13 -> V_108 ) {
unsigned long V_33 ;
F_12 ( & V_13 -> V_34 , V_33 ) ;
if ( V_13 -> V_35 )
V_27 = V_13 -> V_108 ( V_13 -> V_35 , V_27 ) ;
F_13 ( & V_13 -> V_34 , V_33 ) ;
if ( ! V_27 ) {
if ( V_13 -> V_35 &&
V_13 -> V_35 -> V_109 )
goto V_110;
goto V_111;
}
}
V_50 = V_27 -> V_66 ;
V_24 -> V_48 = V_27 -> V_49 ;
V_24 -> V_53 = V_27 ;
V_24 -> V_51 = F_42 ;
if ( V_13 -> V_35 &&
V_13 -> V_35 -> V_43 &&
V_50 == V_13 -> V_35 -> V_112 &&
( V_50 % V_102 -> V_42 ) == 0 )
V_24 -> V_113 = 0 ;
else
V_24 -> V_113 = 1 ;
if ( V_24 -> V_113 && ! V_13 -> V_114 && ( V_50 % V_102 -> V_42 ) == 0 )
V_50 ++ ;
V_24 -> V_50 = V_50 ;
V_28 = F_18 ( V_102 , V_24 , V_82 ) ;
switch ( V_28 ) {
default:
F_10 ( V_13 , L_13 , V_28 ) ;
break;
case 0 :
F_52 ( V_9 ) ;
F_53 ( & V_13 -> V_99 ) ;
}
if ( V_28 ) {
F_19 ( V_27 ) ;
V_111:
V_13 -> V_9 -> V_68 . V_115 ++ ;
V_110:
F_12 ( & V_13 -> V_55 , V_33 ) ;
if ( F_33 ( & V_13 -> V_90 ) )
F_54 ( V_9 ) ;
F_20 ( & V_24 -> V_56 , & V_13 -> V_90 ) ;
F_13 ( & V_13 -> V_55 , V_33 ) ;
}
return V_103 ;
}
static void F_55 ( struct V_12 * V_13 , T_1 V_25 )
{
F_10 ( V_13 , L_14 , V_116 ) ;
F_38 ( V_13 , V_25 ) ;
F_56 ( & V_13 -> V_99 , 0 ) ;
F_46 ( V_13 -> V_9 ) ;
}
static int F_57 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
struct V_88 * V_89 ;
F_10 ( V_13 , L_14 , V_116 ) ;
if ( F_45 ( V_13 -> V_9 ) )
F_55 ( V_13 , V_95 ) ;
F_58 ( & V_13 -> V_34 ) ;
V_89 = V_13 -> V_35 ;
if ( V_89 && V_89 -> V_117 )
V_89 -> V_117 ( V_89 ) ;
F_59 ( & V_13 -> V_34 ) ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
unsigned long V_33 ;
F_26 ( V_13 , L_14 , V_116 ) ;
F_51 ( V_9 ) ;
F_10 ( V_13 , L_15 ,
V_13 -> V_9 -> V_68 . V_73 , V_13 -> V_9 -> V_68 . V_98 ,
V_13 -> V_9 -> V_68 . V_69 , V_13 -> V_9 -> V_68 . V_96
) ;
F_12 ( & V_13 -> V_34 , V_33 ) ;
if ( V_13 -> V_35 ) {
struct V_88 * V_89 = V_13 -> V_35 ;
const struct V_118 * V_102 ;
const struct V_118 * V_32 ;
if ( V_89 -> V_119 )
V_89 -> V_119 ( V_89 ) ;
V_102 = V_89 -> V_91 -> V_120 ;
V_32 = V_89 -> V_36 -> V_120 ;
F_61 ( V_89 -> V_91 ) ;
F_61 ( V_89 -> V_36 ) ;
if ( F_45 ( V_9 ) ) {
F_10 ( V_13 , L_16 ) ;
V_89 -> V_91 -> V_120 = V_102 ;
V_89 -> V_36 -> V_120 = V_32 ;
F_62 ( V_89 -> V_91 ) ;
F_62 ( V_89 -> V_36 ) ;
}
}
F_13 ( & V_13 -> V_34 , V_33 ) ;
return 0 ;
}
static int F_63 ( const char * V_121 , T_5 * V_122 )
{
if ( V_121 ) {
unsigned V_85 ;
for ( V_85 = 0 ; V_85 < 6 ; V_85 ++ ) {
unsigned char V_123 ;
if ( ( * V_121 == '.' ) || ( * V_121 == ':' ) )
V_121 ++ ;
V_123 = F_64 ( * V_121 ++ ) << 4 ;
V_123 |= F_64 ( * V_121 ++ ) ;
V_122 [ V_85 ] = V_123 ;
}
if ( F_65 ( V_122 ) )
return 0 ;
}
F_66 ( V_122 ) ;
return 1 ;
}
static int F_67 ( T_5 V_122 [ V_124 ] , char * V_121 , int V_66 )
{
if ( V_66 < 18 )
return - V_125 ;
snprintf ( V_121 , V_66 , L_17 , V_122 ) ;
return 18 ;
}
struct V_12 * F_68 ( struct V_1 * V_126 ,
const char * V_122 , const char * V_127 ,
T_5 V_128 [ V_124 ] , unsigned V_3 , const char * V_129 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 ;
int V_61 ;
V_9 = F_69 ( sizeof *V_13 ) ;
if ( ! V_9 )
return F_70 ( - V_29 ) ;
V_13 = F_4 ( V_9 ) ;
F_71 ( & V_13 -> V_34 ) ;
F_71 ( & V_13 -> V_55 ) ;
F_72 ( & V_13 -> V_22 , F_40 ) ;
F_73 ( & V_13 -> V_90 ) ;
F_73 ( & V_13 -> V_57 ) ;
F_74 ( & V_13 -> V_64 ) ;
V_13 -> V_9 = V_9 ;
V_13 -> V_3 = V_3 ;
snprintf ( V_9 -> V_18 , sizeof( V_9 -> V_18 ) , L_18 , V_129 ) ;
if ( F_63 ( V_122 , V_9 -> V_122 ) )
F_75 ( & V_126 -> V_13 ,
L_19 , L_20 ) ;
if ( F_63 ( V_127 , V_13 -> V_130 ) )
F_75 ( & V_126 -> V_13 ,
L_19 , L_21 ) ;
if ( V_128 )
memcpy ( V_128 , V_13 -> V_130 , V_124 ) ;
V_9 -> V_131 = & V_132 ;
V_9 -> V_133 = & V_134 ;
V_9 -> V_135 = V_65 ;
V_9 -> V_136 = V_67 ;
V_13 -> V_2 = V_126 ;
F_76 ( V_9 , & V_126 -> V_13 ) ;
F_77 ( V_9 , & V_137 ) ;
V_61 = F_78 ( V_9 ) ;
if ( V_61 < 0 ) {
F_79 ( & V_126 -> V_13 , L_22 , V_61 ) ;
F_80 ( V_9 ) ;
V_13 = F_70 ( V_61 ) ;
} else {
F_81 ( V_13 , L_23 , V_9 -> V_122 ) ;
F_81 ( V_13 , L_24 , V_13 -> V_130 ) ;
F_82 ( V_9 ) ;
}
return V_13 ;
}
struct V_8 * F_83 ( const char * V_129 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
V_9 = F_69 ( sizeof( * V_13 ) ) ;
if ( ! V_9 )
return F_70 ( - V_29 ) ;
V_13 = F_4 ( V_9 ) ;
F_71 ( & V_13 -> V_34 ) ;
F_71 ( & V_13 -> V_55 ) ;
F_72 ( & V_13 -> V_22 , F_40 ) ;
F_73 ( & V_13 -> V_90 ) ;
F_73 ( & V_13 -> V_57 ) ;
F_74 ( & V_13 -> V_64 ) ;
V_13 -> V_9 = V_9 ;
V_13 -> V_3 = V_138 ;
snprintf ( V_9 -> V_18 , sizeof( V_9 -> V_18 ) , L_18 , V_129 ) ;
F_66 ( V_13 -> V_139 ) ;
F_84 ( L_19 , L_20 ) ;
F_66 ( V_13 -> V_130 ) ;
F_84 ( L_19 , L_21 ) ;
V_9 -> V_131 = & V_132 ;
V_9 -> V_133 = & V_134 ;
F_77 ( V_9 , & V_137 ) ;
return V_9 ;
}
int F_85 ( struct V_8 * V_9 )
{
struct V_12 * V_13 ;
struct V_1 * V_126 ;
struct V_140 V_141 ;
int V_61 ;
if ( ! V_9 -> V_13 . V_142 )
return - V_125 ;
V_13 = F_4 ( V_9 ) ;
V_126 = V_13 -> V_2 ;
V_61 = F_78 ( V_9 ) ;
if ( V_61 < 0 ) {
F_79 ( & V_126 -> V_13 , L_22 , V_61 ) ;
return V_61 ;
} else {
F_81 ( V_13 , L_24 , V_13 -> V_130 ) ;
F_82 ( V_9 ) ;
}
V_141 . V_143 = V_9 -> type ;
memcpy ( V_141 . V_144 , V_13 -> V_139 , V_124 ) ;
F_86 () ;
V_61 = F_87 ( V_9 , & V_141 ) ;
F_88 () ;
if ( V_61 )
F_84 ( L_25 , V_61 ) ;
else
F_81 ( V_13 , L_23 , V_13 -> V_139 ) ;
return V_61 ;
}
void F_89 ( struct V_8 * V_9 , struct V_1 * V_126 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
V_13 -> V_2 = V_126 ;
F_76 ( V_9 , & V_126 -> V_13 ) ;
}
int F_90 ( struct V_8 * V_9 , const char * V_122 )
{
struct V_12 * V_13 ;
T_5 V_145 [ V_124 ] ;
V_13 = F_4 ( V_9 ) ;
if ( F_63 ( V_122 , V_145 ) )
return - V_125 ;
memcpy ( V_13 -> V_139 , V_145 , V_124 ) ;
return 0 ;
}
int F_91 ( struct V_8 * V_9 , char * V_122 , int V_66 )
{
struct V_12 * V_13 ;
int V_146 ;
V_13 = F_4 ( V_9 ) ;
V_146 = F_67 ( V_13 -> V_139 , V_122 , V_66 ) ;
if ( V_146 + 1 < V_66 ) {
V_122 [ V_146 ++ ] = '\n' ;
V_122 [ V_146 ] = '\0' ;
}
return V_146 ;
}
int F_92 ( struct V_8 * V_9 , const char * V_127 )
{
struct V_12 * V_13 ;
T_5 V_145 [ V_124 ] ;
V_13 = F_4 ( V_9 ) ;
if ( F_63 ( V_127 , V_145 ) )
return - V_125 ;
memcpy ( V_13 -> V_130 , V_145 , V_124 ) ;
return 0 ;
}
int F_93 ( struct V_8 * V_9 , char * V_127 , int V_66 )
{
struct V_12 * V_13 ;
int V_146 ;
V_13 = F_4 ( V_9 ) ;
V_146 = F_67 ( V_13 -> V_130 , V_127 , V_66 ) ;
if ( V_146 + 1 < V_66 ) {
V_127 [ V_146 ++ ] = '\n' ;
V_127 [ V_146 ] = '\0' ;
}
return V_146 ;
}
int F_94 ( struct V_8 * V_9 , char * V_127 , int V_66 )
{
struct V_12 * V_13 ;
if ( V_66 < 13 )
return - V_125 ;
V_13 = F_4 ( V_9 ) ;
snprintf ( V_127 , V_66 , L_26 , V_13 -> V_130 ) ;
return strlen ( V_127 ) ;
}
void F_95 ( struct V_8 * V_9 , T_5 V_130 [ V_124 ] )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
memcpy ( V_130 , V_13 -> V_130 , V_124 ) ;
}
void F_96 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
V_13 -> V_3 = V_3 ;
}
unsigned F_97 ( struct V_8 * V_9 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
return V_13 -> V_3 ;
}
int F_98 ( struct V_8 * V_9 , char * V_18 , int V_66 )
{
int V_146 ;
F_86 () ;
V_146 = snprintf ( V_18 , V_66 , L_14 , F_99 ( V_9 ) ) ;
F_88 () ;
return V_146 < V_66 ? V_146 : V_66 ;
}
void F_100 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_101 ( V_13 -> V_9 ) ;
F_102 ( & V_13 -> V_22 ) ;
F_80 ( V_13 -> V_9 ) ;
}
struct V_8 * F_103 ( struct V_88 * V_89 )
{
struct V_12 * V_13 = V_89 -> V_147 ;
int V_148 = 0 ;
if ( ! V_13 )
return F_70 ( - V_125 ) ;
V_89 -> V_91 -> V_60 = V_13 ;
V_148 = F_62 ( V_89 -> V_91 ) ;
if ( V_148 != 0 ) {
F_10 ( V_13 , L_27 ,
V_89 -> V_91 -> V_18 , V_148 ) ;
goto V_149;
}
V_89 -> V_36 -> V_60 = V_13 ;
V_148 = F_62 ( V_89 -> V_36 ) ;
if ( V_148 != 0 ) {
F_10 ( V_13 , L_27 ,
V_89 -> V_36 -> V_18 , V_148 ) ;
goto V_150;
}
if ( V_148 == 0 )
V_148 = F_37 ( V_13 , V_89 , F_1 ( V_13 -> V_2 ,
V_13 -> V_3 ) ) ;
if ( V_148 == 0 ) {
V_13 -> V_114 = V_89 -> V_151 ;
V_13 -> V_47 = V_89 -> V_47 ;
F_10 ( V_13 , L_28 , F_1 ( V_13 -> V_2 , V_13 -> V_3 ) ) ;
V_13 -> V_41 = V_89 -> V_41 ;
V_13 -> V_63 = V_89 -> V_63 ;
V_13 -> V_108 = V_89 -> V_108 ;
F_28 ( & V_13 -> V_34 ) ;
V_13 -> V_35 = V_89 ;
if ( F_27 ( V_13 -> V_9 ) ) {
if ( V_89 -> V_117 )
V_89 -> V_117 ( V_89 ) ;
} else {
if ( V_89 -> V_119 )
V_89 -> V_119 ( V_89 ) ;
}
F_29 ( & V_13 -> V_34 ) ;
F_104 ( V_13 -> V_9 ) ;
if ( F_27 ( V_13 -> V_9 ) )
F_55 ( V_13 , V_82 ) ;
} else {
( void ) F_61 ( V_89 -> V_36 ) ;
V_150:
( void ) F_61 ( V_89 -> V_91 ) ;
}
V_149:
if ( V_148 < 0 )
return F_70 ( V_148 ) ;
return V_13 -> V_9 ;
}
void F_105 ( struct V_88 * V_89 )
{
struct V_12 * V_13 = V_89 -> V_147 ;
struct V_23 * V_24 ;
F_106 ( ! V_13 ) ;
if ( ! V_13 )
return;
F_10 ( V_13 , L_14 , V_116 ) ;
F_51 ( V_13 -> V_9 ) ;
F_82 ( V_13 -> V_9 ) ;
F_61 ( V_89 -> V_91 ) ;
F_28 ( & V_13 -> V_55 ) ;
while ( ! F_33 ( & V_13 -> V_90 ) ) {
V_24 = F_36 ( V_13 -> V_90 . V_87 ,
struct V_23 , V_56 ) ;
F_34 ( & V_24 -> V_56 ) ;
F_29 ( & V_13 -> V_55 ) ;
F_35 ( V_89 -> V_91 , V_24 ) ;
F_28 ( & V_13 -> V_55 ) ;
}
F_29 ( & V_13 -> V_55 ) ;
V_89 -> V_91 -> V_120 = NULL ;
F_61 ( V_89 -> V_36 ) ;
F_28 ( & V_13 -> V_55 ) ;
while ( ! F_33 ( & V_13 -> V_57 ) ) {
V_24 = F_36 ( V_13 -> V_57 . V_87 ,
struct V_23 , V_56 ) ;
F_34 ( & V_24 -> V_56 ) ;
F_29 ( & V_13 -> V_55 ) ;
F_35 ( V_89 -> V_36 , V_24 ) ;
F_28 ( & V_13 -> V_55 ) ;
}
F_29 ( & V_13 -> V_55 ) ;
V_89 -> V_36 -> V_120 = NULL ;
V_13 -> V_41 = 0 ;
V_13 -> V_63 = NULL ;
V_13 -> V_108 = NULL ;
F_28 ( & V_13 -> V_34 ) ;
V_13 -> V_35 = NULL ;
F_29 ( & V_13 -> V_34 ) ;
}
