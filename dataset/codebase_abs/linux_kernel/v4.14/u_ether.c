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
struct V_1 * V_26 = V_13 -> V_2 ;
struct V_27 * V_28 ;
int V_29 = - V_30 ;
T_2 V_31 = 0 ;
struct V_32 * V_33 ;
unsigned long V_34 ;
F_12 ( & V_13 -> V_35 , V_34 ) ;
if ( V_13 -> V_36 )
V_33 = V_13 -> V_36 -> V_37 ;
else
V_33 = NULL ;
F_13 ( & V_13 -> V_35 , V_34 ) ;
if ( ! V_33 )
return - V_38 ;
V_31 += sizeof( struct V_39 ) + V_13 -> V_9 -> V_40 + V_41 ;
V_31 += V_13 -> V_36 -> V_42 ;
if ( V_26 -> V_43 ) {
V_31 += V_33 -> V_44 - 1 ;
V_31 -= V_31 % V_33 -> V_44 ;
}
if ( V_13 -> V_36 -> V_45 )
V_31 = F_14 ( T_2 , V_31 , V_13 -> V_36 -> V_46 ) ;
V_28 = F_15 ( V_13 -> V_9 , V_31 + V_47 , V_25 ) ;
if ( V_28 == NULL ) {
F_10 ( V_13 , L_4 ) ;
goto V_48;
}
if ( F_16 ( ! V_13 -> V_49 ) )
F_17 ( V_28 , V_47 ) ;
V_24 -> V_50 = V_28 -> V_51 ;
V_24 -> V_52 = V_31 ;
V_24 -> V_53 = V_54 ;
V_24 -> V_55 = V_28 ;
V_29 = F_18 ( V_33 , V_24 , V_25 ) ;
if ( V_29 == - V_30 )
V_48:
F_7 ( V_13 , V_56 ) ;
if ( V_29 ) {
F_10 ( V_13 , L_5 , V_29 ) ;
if ( V_28 )
F_19 ( V_28 ) ;
F_12 ( & V_13 -> V_57 , V_34 ) ;
F_20 ( & V_24 -> V_58 , & V_13 -> V_59 ) ;
F_13 ( & V_13 -> V_57 , V_34 ) ;
}
return V_29 ;
}
static void V_54 ( struct V_32 * V_60 , struct V_23 * V_24 )
{
struct V_27 * V_28 = V_24 -> V_55 , * V_61 ;
struct V_12 * V_13 = V_60 -> V_62 ;
int V_63 = V_24 -> V_63 ;
switch ( V_63 ) {
case 0 :
F_21 ( V_28 , V_24 -> V_64 ) ;
if ( V_13 -> V_65 ) {
unsigned long V_34 ;
F_12 ( & V_13 -> V_35 , V_34 ) ;
if ( V_13 -> V_36 ) {
V_63 = V_13 -> V_65 ( V_13 -> V_36 ,
V_28 ,
& V_13 -> V_66 ) ;
} else {
F_19 ( V_28 ) ;
V_63 = - V_38 ;
}
F_13 ( & V_13 -> V_35 , V_34 ) ;
} else {
F_22 ( & V_13 -> V_66 , V_28 ) ;
}
V_28 = NULL ;
V_61 = F_23 ( & V_13 -> V_66 ) ;
while ( V_61 ) {
if ( V_63 < 0
|| V_67 > V_61 -> V_68
|| V_61 -> V_68 > V_69 ) {
V_13 -> V_9 -> V_70 . V_71 ++ ;
V_13 -> V_9 -> V_70 . V_72 ++ ;
F_10 ( V_13 , L_6 , V_61 -> V_68 ) ;
F_19 ( V_61 ) ;
goto V_73;
}
V_61 -> V_74 = F_24 ( V_61 , V_13 -> V_9 ) ;
V_13 -> V_9 -> V_70 . V_75 ++ ;
V_13 -> V_9 -> V_70 . V_76 += V_61 -> V_68 ;
V_63 = F_25 ( V_61 ) ;
V_73:
V_61 = F_23 ( & V_13 -> V_66 ) ;
}
break;
case - V_77 :
case - V_78 :
F_26 ( V_13 , L_7 , V_63 ) ;
goto V_79;
case - V_80 :
F_10 ( V_13 , L_8 , V_60 -> V_18 ) ;
F_7 ( V_13 , V_56 ) ;
V_79:
F_19 ( V_28 ) ;
goto V_81;
case - V_82 :
V_13 -> V_9 -> V_70 . V_83 ++ ;
default:
V_13 -> V_9 -> V_70 . V_71 ++ ;
F_10 ( V_13 , L_9 , V_63 ) ;
break;
}
if ( V_28 )
F_19 ( V_28 ) ;
if ( ! F_27 ( V_13 -> V_9 ) ) {
V_81:
F_28 ( & V_13 -> V_57 ) ;
F_20 ( & V_24 -> V_58 , & V_13 -> V_59 ) ;
F_29 ( & V_13 -> V_57 ) ;
V_24 = NULL ;
}
if ( V_24 )
F_11 ( V_13 , V_24 , V_84 ) ;
}
static int F_30 ( struct V_85 * V_58 , struct V_32 * V_60 , unsigned V_86 )
{
unsigned V_87 ;
struct V_23 * V_24 ;
if ( ! V_86 )
return - V_30 ;
V_87 = V_86 ;
F_31 (req, list, list) {
if ( V_87 -- == 0 )
goto V_88;
}
while ( V_87 -- ) {
V_24 = F_32 ( V_60 , V_84 ) ;
if ( ! V_24 )
return F_33 ( V_58 ) ? - V_30 : 0 ;
F_20 ( & V_24 -> V_58 , V_58 ) ;
}
return 0 ;
V_88:
for (; ; ) {
struct V_85 * V_89 ;
V_89 = V_24 -> V_58 . V_89 ;
F_34 ( & V_24 -> V_58 ) ;
F_35 ( V_60 , V_24 ) ;
if ( V_89 == V_58 )
break;
V_24 = F_36 ( V_89 , struct V_23 , V_58 ) ;
}
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , struct V_90 * V_91 , unsigned V_86 )
{
int V_63 ;
F_28 ( & V_13 -> V_57 ) ;
V_63 = F_30 ( & V_13 -> V_92 , V_91 -> V_93 , V_86 ) ;
if ( V_63 < 0 )
goto V_94;
V_63 = F_30 ( & V_13 -> V_59 , V_91 -> V_37 , V_86 ) ;
if ( V_63 < 0 )
goto V_94;
goto V_95;
V_94:
F_10 ( V_13 , L_10 ) ;
V_95:
F_29 ( & V_13 -> V_57 ) ;
return V_63 ;
}
static void F_38 ( struct V_12 * V_13 , T_1 V_25 )
{
struct V_23 * V_24 ;
struct V_23 * V_96 ;
unsigned long V_34 ;
F_12 ( & V_13 -> V_57 , V_34 ) ;
F_39 (req, tmp, &dev->rx_reqs, list) {
F_40 ( & V_24 -> V_58 ) ;
F_13 ( & V_13 -> V_57 , V_34 ) ;
if ( F_11 ( V_13 , V_24 , V_25 ) < 0 ) {
F_7 ( V_13 , V_56 ) ;
return;
}
F_12 ( & V_13 -> V_57 , V_34 ) ;
}
F_13 ( & V_13 -> V_57 , V_34 ) ;
}
static void F_41 ( struct V_97 * V_22 )
{
struct V_12 * V_13 = F_36 ( V_22 , struct V_12 , V_22 ) ;
if ( F_42 ( V_56 , & V_13 -> V_21 ) ) {
if ( F_27 ( V_13 -> V_9 ) )
F_38 ( V_13 , V_98 ) ;
}
if ( V_13 -> V_21 )
F_10 ( V_13 , L_11 , V_13 -> V_21 ) ;
}
static void F_43 ( struct V_32 * V_60 , struct V_23 * V_24 )
{
struct V_27 * V_28 = V_24 -> V_55 ;
struct V_12 * V_13 = V_60 -> V_62 ;
switch ( V_24 -> V_63 ) {
default:
V_13 -> V_9 -> V_70 . V_99 ++ ;
F_26 ( V_13 , L_12 , V_24 -> V_63 ) ;
case - V_77 :
case - V_78 :
F_19 ( V_28 ) ;
break;
case 0 :
V_13 -> V_9 -> V_70 . V_100 += V_28 -> V_68 ;
F_44 ( V_28 ) ;
}
V_13 -> V_9 -> V_70 . V_101 ++ ;
F_28 ( & V_13 -> V_57 ) ;
F_20 ( & V_24 -> V_58 , & V_13 -> V_92 ) ;
F_29 ( & V_13 -> V_57 ) ;
F_45 ( & V_13 -> V_102 ) ;
if ( F_46 ( V_13 -> V_9 ) )
F_47 ( V_13 -> V_9 ) ;
}
static inline int F_48 ( T_3 V_103 )
{
return V_103 & V_104 ;
}
static T_4 F_49 ( struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
int V_52 = 0 ;
int V_29 ;
struct V_23 * V_24 = NULL ;
unsigned long V_34 ;
struct V_32 * V_105 ;
T_3 V_103 ;
F_12 ( & V_13 -> V_35 , V_34 ) ;
if ( V_13 -> V_36 ) {
V_105 = V_13 -> V_36 -> V_93 ;
V_103 = V_13 -> V_36 -> V_103 ;
} else {
V_105 = NULL ;
V_103 = 0 ;
}
F_13 ( & V_13 -> V_35 , V_34 ) ;
if ( V_28 && ! V_105 ) {
F_19 ( V_28 ) ;
return V_106 ;
}
if ( V_28 && ! F_48 ( V_103 ) ) {
T_5 * V_107 = V_28 -> V_51 ;
if ( F_50 ( V_107 ) ) {
T_3 type ;
if ( F_51 ( V_107 ) )
type = V_108 ;
else
type = V_109 ;
if ( ! ( V_103 & type ) ) {
F_19 ( V_28 ) ;
return V_106 ;
}
}
}
F_12 ( & V_13 -> V_57 , V_34 ) ;
if ( F_33 ( & V_13 -> V_92 ) ) {
F_13 ( & V_13 -> V_57 , V_34 ) ;
return V_110 ;
}
V_24 = F_52 ( & V_13 -> V_92 , struct V_23 , V_58 ) ;
F_34 ( & V_24 -> V_58 ) ;
if ( F_33 ( & V_13 -> V_92 ) )
F_53 ( V_9 ) ;
F_13 ( & V_13 -> V_57 , V_34 ) ;
if ( V_13 -> V_111 ) {
unsigned long V_34 ;
F_12 ( & V_13 -> V_35 , V_34 ) ;
if ( V_13 -> V_36 )
V_28 = V_13 -> V_111 ( V_13 -> V_36 , V_28 ) ;
F_13 ( & V_13 -> V_35 , V_34 ) ;
if ( ! V_28 ) {
if ( V_13 -> V_36 &&
V_13 -> V_36 -> V_112 )
goto V_113;
goto V_114;
}
}
V_52 = V_28 -> V_68 ;
V_24 -> V_50 = V_28 -> V_51 ;
V_24 -> V_55 = V_28 ;
V_24 -> V_53 = F_43 ;
if ( V_13 -> V_36 &&
V_13 -> V_36 -> V_45 &&
V_52 == V_13 -> V_36 -> V_115 &&
( V_52 % V_105 -> V_44 ) == 0 )
V_24 -> V_116 = 0 ;
else
V_24 -> V_116 = 1 ;
if ( V_24 -> V_116 && ! V_13 -> V_117 && ( V_52 % V_105 -> V_44 ) == 0 )
V_52 ++ ;
V_24 -> V_52 = V_52 ;
V_29 = F_18 ( V_105 , V_24 , V_84 ) ;
switch ( V_29 ) {
default:
F_10 ( V_13 , L_13 , V_29 ) ;
break;
case 0 :
F_54 ( V_9 ) ;
F_55 ( & V_13 -> V_102 ) ;
}
if ( V_29 ) {
F_19 ( V_28 ) ;
V_114:
V_13 -> V_9 -> V_70 . V_118 ++ ;
V_113:
F_12 ( & V_13 -> V_57 , V_34 ) ;
if ( F_33 ( & V_13 -> V_92 ) )
F_56 ( V_9 ) ;
F_20 ( & V_24 -> V_58 , & V_13 -> V_92 ) ;
F_13 ( & V_13 -> V_57 , V_34 ) ;
}
return V_106 ;
}
static void F_57 ( struct V_12 * V_13 , T_1 V_25 )
{
F_10 ( V_13 , L_14 , V_119 ) ;
F_38 ( V_13 , V_25 ) ;
F_58 ( & V_13 -> V_102 , 0 ) ;
F_47 ( V_13 -> V_9 ) ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
struct V_90 * V_91 ;
F_10 ( V_13 , L_14 , V_119 ) ;
if ( F_46 ( V_13 -> V_9 ) )
F_57 ( V_13 , V_98 ) ;
F_60 ( & V_13 -> V_35 ) ;
V_91 = V_13 -> V_36 ;
if ( V_91 && V_91 -> V_120 )
V_91 -> V_120 ( V_91 ) ;
F_61 ( & V_13 -> V_35 ) ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_4 ( V_9 ) ;
unsigned long V_34 ;
F_26 ( V_13 , L_14 , V_119 ) ;
F_53 ( V_9 ) ;
F_10 ( V_13 , L_15 ,
V_13 -> V_9 -> V_70 . V_75 , V_13 -> V_9 -> V_70 . V_101 ,
V_13 -> V_9 -> V_70 . V_71 , V_13 -> V_9 -> V_70 . V_99
) ;
F_12 ( & V_13 -> V_35 , V_34 ) ;
if ( V_13 -> V_36 ) {
struct V_90 * V_91 = V_13 -> V_36 ;
const struct V_121 * V_105 ;
const struct V_121 * V_33 ;
if ( V_91 -> V_122 )
V_91 -> V_122 ( V_91 ) ;
V_105 = V_91 -> V_93 -> V_123 ;
V_33 = V_91 -> V_37 -> V_123 ;
F_63 ( V_91 -> V_93 ) ;
F_63 ( V_91 -> V_37 ) ;
if ( F_46 ( V_9 ) ) {
F_10 ( V_13 , L_16 ) ;
V_91 -> V_93 -> V_123 = V_105 ;
V_91 -> V_37 -> V_123 = V_33 ;
F_64 ( V_91 -> V_93 ) ;
F_64 ( V_91 -> V_37 ) ;
}
}
F_13 ( & V_13 -> V_35 , V_34 ) ;
return 0 ;
}
static int F_65 ( const char * V_124 , T_5 * V_125 )
{
if ( V_124 ) {
unsigned V_87 ;
for ( V_87 = 0 ; V_87 < 6 ; V_87 ++ ) {
unsigned char V_126 ;
if ( ( * V_124 == '.' ) || ( * V_124 == ':' ) )
V_124 ++ ;
V_126 = F_66 ( * V_124 ++ ) << 4 ;
V_126 |= F_66 ( * V_124 ++ ) ;
V_125 [ V_87 ] = V_126 ;
}
if ( F_67 ( V_125 ) )
return 0 ;
}
F_68 ( V_125 ) ;
return 1 ;
}
static int F_69 ( T_5 V_125 [ V_127 ] , char * V_124 , int V_68 )
{
if ( V_68 < 18 )
return - V_128 ;
snprintf ( V_124 , V_68 , L_17 , V_125 ) ;
return 18 ;
}
struct V_12 * F_70 ( struct V_1 * V_26 ,
const char * V_125 , const char * V_129 ,
T_5 V_130 [ V_127 ] , unsigned V_3 , const char * V_131 )
{
struct V_12 * V_13 ;
struct V_8 * V_9 ;
int V_63 ;
V_9 = F_71 ( sizeof *V_13 ) ;
if ( ! V_9 )
return F_72 ( - V_30 ) ;
V_13 = F_4 ( V_9 ) ;
F_73 ( & V_13 -> V_35 ) ;
F_73 ( & V_13 -> V_57 ) ;
F_74 ( & V_13 -> V_22 , F_41 ) ;
F_75 ( & V_13 -> V_92 ) ;
F_75 ( & V_13 -> V_59 ) ;
F_76 ( & V_13 -> V_66 ) ;
V_13 -> V_9 = V_9 ;
V_13 -> V_3 = V_3 ;
snprintf ( V_9 -> V_18 , sizeof( V_9 -> V_18 ) , L_18 , V_131 ) ;
if ( F_65 ( V_125 , V_9 -> V_125 ) )
F_77 ( & V_26 -> V_13 ,
L_19 , L_20 ) ;
if ( F_65 ( V_129 , V_13 -> V_132 ) )
F_77 ( & V_26 -> V_13 ,
L_19 , L_21 ) ;
if ( V_130 )
memcpy ( V_130 , V_13 -> V_132 , V_127 ) ;
V_9 -> V_133 = & V_134 ;
V_9 -> V_135 = & V_136 ;
V_9 -> V_137 = V_67 ;
V_9 -> V_138 = V_69 ;
V_13 -> V_2 = V_26 ;
F_78 ( V_9 , & V_26 -> V_13 ) ;
F_79 ( V_9 , & V_139 ) ;
V_63 = F_80 ( V_9 ) ;
if ( V_63 < 0 ) {
F_81 ( & V_26 -> V_13 , L_22 , V_63 ) ;
F_82 ( V_9 ) ;
V_13 = F_72 ( V_63 ) ;
} else {
F_83 ( V_13 , L_23 , V_9 -> V_125 ) ;
F_83 ( V_13 , L_24 , V_13 -> V_132 ) ;
F_84 ( V_9 ) ;
}
return V_13 ;
}
struct V_8 * F_85 ( const char * V_131 )
{
struct V_8 * V_9 ;
struct V_12 * V_13 ;
V_9 = F_71 ( sizeof( * V_13 ) ) ;
if ( ! V_9 )
return F_72 ( - V_30 ) ;
V_13 = F_4 ( V_9 ) ;
F_73 ( & V_13 -> V_35 ) ;
F_73 ( & V_13 -> V_57 ) ;
F_74 ( & V_13 -> V_22 , F_41 ) ;
F_75 ( & V_13 -> V_92 ) ;
F_75 ( & V_13 -> V_59 ) ;
F_76 ( & V_13 -> V_66 ) ;
V_13 -> V_9 = V_9 ;
V_13 -> V_3 = V_140 ;
snprintf ( V_9 -> V_18 , sizeof( V_9 -> V_18 ) , L_18 , V_131 ) ;
F_68 ( V_13 -> V_141 ) ;
F_86 ( L_19 , L_20 ) ;
F_68 ( V_13 -> V_132 ) ;
F_86 ( L_19 , L_21 ) ;
V_9 -> V_133 = & V_134 ;
V_9 -> V_135 = & V_136 ;
F_79 ( V_9 , & V_139 ) ;
return V_9 ;
}
int F_87 ( struct V_8 * V_9 )
{
struct V_12 * V_13 ;
struct V_1 * V_26 ;
struct V_142 V_143 ;
int V_63 ;
if ( ! V_9 -> V_13 . V_144 )
return - V_128 ;
V_13 = F_4 ( V_9 ) ;
V_26 = V_13 -> V_2 ;
V_63 = F_80 ( V_9 ) ;
if ( V_63 < 0 ) {
F_81 ( & V_26 -> V_13 , L_22 , V_63 ) ;
return V_63 ;
} else {
F_83 ( V_13 , L_24 , V_13 -> V_132 ) ;
F_84 ( V_9 ) ;
}
V_143 . V_145 = V_9 -> type ;
memcpy ( V_143 . V_146 , V_13 -> V_141 , V_127 ) ;
F_88 () ;
V_63 = F_89 ( V_9 , & V_143 ) ;
F_90 () ;
if ( V_63 )
F_86 ( L_25 , V_63 ) ;
else
F_83 ( V_13 , L_23 , V_13 -> V_141 ) ;
return V_63 ;
}
void F_91 ( struct V_8 * V_9 , struct V_1 * V_26 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
V_13 -> V_2 = V_26 ;
F_78 ( V_9 , & V_26 -> V_13 ) ;
}
int F_92 ( struct V_8 * V_9 , const char * V_125 )
{
struct V_12 * V_13 ;
T_5 V_147 [ V_127 ] ;
V_13 = F_4 ( V_9 ) ;
if ( F_65 ( V_125 , V_147 ) )
return - V_128 ;
memcpy ( V_13 -> V_141 , V_147 , V_127 ) ;
return 0 ;
}
int F_93 ( struct V_8 * V_9 , char * V_125 , int V_68 )
{
struct V_12 * V_13 ;
int V_148 ;
V_13 = F_4 ( V_9 ) ;
V_148 = F_69 ( V_13 -> V_141 , V_125 , V_68 ) ;
if ( V_148 + 1 < V_68 ) {
V_125 [ V_148 ++ ] = '\n' ;
V_125 [ V_148 ] = '\0' ;
}
return V_148 ;
}
int F_94 ( struct V_8 * V_9 , const char * V_129 )
{
struct V_12 * V_13 ;
T_5 V_147 [ V_127 ] ;
V_13 = F_4 ( V_9 ) ;
if ( F_65 ( V_129 , V_147 ) )
return - V_128 ;
memcpy ( V_13 -> V_132 , V_147 , V_127 ) ;
return 0 ;
}
int F_95 ( struct V_8 * V_9 , char * V_129 , int V_68 )
{
struct V_12 * V_13 ;
int V_148 ;
V_13 = F_4 ( V_9 ) ;
V_148 = F_69 ( V_13 -> V_132 , V_129 , V_68 ) ;
if ( V_148 + 1 < V_68 ) {
V_129 [ V_148 ++ ] = '\n' ;
V_129 [ V_148 ] = '\0' ;
}
return V_148 ;
}
int F_96 ( struct V_8 * V_9 , char * V_129 , int V_68 )
{
struct V_12 * V_13 ;
if ( V_68 < 13 )
return - V_128 ;
V_13 = F_4 ( V_9 ) ;
snprintf ( V_129 , V_68 , L_26 , V_13 -> V_132 ) ;
return strlen ( V_129 ) ;
}
void F_97 ( struct V_8 * V_9 , T_5 V_132 [ V_127 ] )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
memcpy ( V_132 , V_13 -> V_132 , V_127 ) ;
}
void F_98 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
V_13 -> V_3 = V_3 ;
}
unsigned F_99 ( struct V_8 * V_9 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 ) ;
return V_13 -> V_3 ;
}
int F_100 ( struct V_8 * V_9 , char * V_18 , int V_68 )
{
int V_148 ;
F_88 () ;
V_148 = snprintf ( V_18 , V_68 , L_14 , F_101 ( V_9 ) ) ;
F_90 () ;
return V_148 < V_68 ? V_148 : V_68 ;
}
void F_102 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_103 ( V_13 -> V_9 ) ;
F_104 ( & V_13 -> V_22 ) ;
F_82 ( V_13 -> V_9 ) ;
}
struct V_8 * F_105 ( struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_149 ;
int V_150 = 0 ;
if ( ! V_13 )
return F_72 ( - V_128 ) ;
V_91 -> V_93 -> V_62 = V_13 ;
V_150 = F_64 ( V_91 -> V_93 ) ;
if ( V_150 != 0 ) {
F_10 ( V_13 , L_27 ,
V_91 -> V_93 -> V_18 , V_150 ) ;
goto V_151;
}
V_91 -> V_37 -> V_62 = V_13 ;
V_150 = F_64 ( V_91 -> V_37 ) ;
if ( V_150 != 0 ) {
F_10 ( V_13 , L_27 ,
V_91 -> V_37 -> V_18 , V_150 ) ;
goto V_152;
}
if ( V_150 == 0 )
V_150 = F_37 ( V_13 , V_91 , F_1 ( V_13 -> V_2 ,
V_13 -> V_3 ) ) ;
if ( V_150 == 0 ) {
V_13 -> V_117 = V_91 -> V_153 ;
V_13 -> V_49 = F_106 ( V_13 -> V_2 ) ;
F_10 ( V_13 , L_28 , F_1 ( V_13 -> V_2 , V_13 -> V_3 ) ) ;
V_13 -> V_42 = V_91 -> V_42 ;
V_13 -> V_65 = V_91 -> V_65 ;
V_13 -> V_111 = V_91 -> V_111 ;
F_28 ( & V_13 -> V_35 ) ;
V_13 -> V_36 = V_91 ;
if ( F_27 ( V_13 -> V_9 ) ) {
if ( V_91 -> V_120 )
V_91 -> V_120 ( V_91 ) ;
} else {
if ( V_91 -> V_122 )
V_91 -> V_122 ( V_91 ) ;
}
F_29 ( & V_13 -> V_35 ) ;
F_107 ( V_13 -> V_9 ) ;
if ( F_27 ( V_13 -> V_9 ) )
F_57 ( V_13 , V_84 ) ;
} else {
( void ) F_63 ( V_91 -> V_37 ) ;
V_152:
( void ) F_63 ( V_91 -> V_93 ) ;
}
V_151:
if ( V_150 < 0 )
return F_72 ( V_150 ) ;
return V_13 -> V_9 ;
}
void F_108 ( struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_149 ;
struct V_23 * V_24 ;
struct V_23 * V_96 ;
F_109 ( ! V_13 ) ;
if ( ! V_13 )
return;
F_10 ( V_13 , L_14 , V_119 ) ;
F_53 ( V_13 -> V_9 ) ;
F_84 ( V_13 -> V_9 ) ;
F_63 ( V_91 -> V_93 ) ;
F_28 ( & V_13 -> V_57 ) ;
F_39 (req, tmp, &dev->tx_reqs, list) {
F_34 ( & V_24 -> V_58 ) ;
F_29 ( & V_13 -> V_57 ) ;
F_35 ( V_91 -> V_93 , V_24 ) ;
F_28 ( & V_13 -> V_57 ) ;
}
F_29 ( & V_13 -> V_57 ) ;
V_91 -> V_93 -> V_123 = NULL ;
F_63 ( V_91 -> V_37 ) ;
F_28 ( & V_13 -> V_57 ) ;
F_39 (req, tmp, &dev->rx_reqs, list) {
F_34 ( & V_24 -> V_58 ) ;
F_29 ( & V_13 -> V_57 ) ;
F_35 ( V_91 -> V_37 , V_24 ) ;
F_28 ( & V_13 -> V_57 ) ;
}
F_29 ( & V_13 -> V_57 ) ;
V_91 -> V_37 -> V_123 = NULL ;
V_13 -> V_42 = 0 ;
V_13 -> V_65 = NULL ;
V_13 -> V_111 = NULL ;
F_28 ( & V_13 -> V_35 ) ;
V_13 -> V_36 = NULL ;
F_29 ( & V_13 -> V_35 ) ;
}
