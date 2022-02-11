static inline int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_4 == V_5 ||
V_2 -> V_4 == V_6 ) )
return V_3 * V_7 ;
else
return V_7 ;
}
static int F_3 ( struct V_8 * V_9 , int V_10 )
{
if ( V_10 <= V_11 || V_10 > V_12 )
return - V_13 ;
V_9 -> V_14 = V_10 ;
return 0 ;
}
static void F_4 ( struct V_8 * V_9 , struct V_15 * V_16 )
{
struct V_17 * V_18 = F_5 ( V_9 ) ;
F_6 ( V_16 -> V_19 , L_1 , sizeof( V_16 -> V_19 ) ) ;
F_6 ( V_16 -> V_20 , V_21 , sizeof( V_16 -> V_20 ) ) ;
F_6 ( V_16 -> V_22 , V_18 -> V_2 -> V_23 , sizeof( V_16 -> V_22 ) ) ;
F_6 ( V_16 -> V_24 , F_7 ( & V_18 -> V_2 -> V_18 ) , sizeof( V_16 -> V_24 ) ) ;
}
static void F_8 ( struct V_17 * V_18 , int V_25 )
{
if ( F_9 ( V_25 , & V_18 -> V_26 ) )
return;
if ( ! F_10 ( & V_18 -> V_27 ) )
ERROR ( V_18 , L_2 , V_25 ) ;
else
F_11 ( V_18 , L_3 , V_25 ) ;
}
static int
F_12 ( struct V_17 * V_18 , struct V_28 * V_29 , T_1 V_30 )
{
struct V_31 * V_32 ;
int V_33 = - V_34 ;
T_2 V_35 = 0 ;
struct V_36 * V_37 ;
unsigned long V_38 ;
F_13 ( & V_18 -> V_39 , V_38 ) ;
if ( V_18 -> V_40 )
V_37 = V_18 -> V_40 -> V_41 ;
else
V_37 = NULL ;
F_14 ( & V_18 -> V_39 , V_38 ) ;
if ( ! V_37 )
return - V_42 ;
V_35 += sizeof( struct V_43 ) + V_18 -> V_9 -> V_14 + V_44 ;
V_35 += V_18 -> V_40 -> V_45 ;
V_35 += V_37 -> V_46 - 1 ;
V_35 -= V_35 % V_37 -> V_46 ;
if ( V_18 -> V_40 -> V_47 )
V_35 = F_15 ( T_2 , V_35 , V_18 -> V_40 -> V_48 ) ;
V_32 = F_16 ( V_35 + V_49 , V_30 ) ;
if ( V_32 == NULL ) {
F_11 ( V_18 , L_4 ) ;
goto V_50;
}
F_17 ( V_32 , V_49 ) ;
V_29 -> V_51 = V_32 -> V_52 ;
V_29 -> V_53 = V_35 ;
V_29 -> V_54 = V_55 ;
V_29 -> V_56 = V_32 ;
V_33 = F_18 ( V_37 , V_29 , V_30 ) ;
if ( V_33 == - V_34 )
V_50:
F_8 ( V_18 , V_57 ) ;
if ( V_33 ) {
F_11 ( V_18 , L_5 , V_33 ) ;
if ( V_32 )
F_19 ( V_32 ) ;
F_13 ( & V_18 -> V_58 , V_38 ) ;
F_20 ( & V_29 -> V_59 , & V_18 -> V_60 ) ;
F_14 ( & V_18 -> V_58 , V_38 ) ;
}
return V_33 ;
}
static void V_55 ( struct V_36 * V_61 , struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_56 , * V_62 ;
struct V_17 * V_18 = V_61 -> V_63 ;
int V_64 = V_29 -> V_64 ;
switch ( V_64 ) {
case 0 :
F_21 ( V_32 , V_29 -> V_65 ) ;
if ( V_18 -> V_66 ) {
unsigned long V_38 ;
F_13 ( & V_18 -> V_39 , V_38 ) ;
if ( V_18 -> V_40 ) {
V_64 = V_18 -> V_66 ( V_18 -> V_40 ,
V_32 ,
& V_18 -> V_67 ) ;
} else {
F_19 ( V_32 ) ;
V_64 = - V_42 ;
}
F_14 ( & V_18 -> V_39 , V_38 ) ;
} else {
F_22 ( & V_18 -> V_67 , V_32 ) ;
}
V_32 = NULL ;
V_62 = F_23 ( & V_18 -> V_67 ) ;
while ( V_62 ) {
if ( V_64 < 0
|| V_11 > V_62 -> V_68
|| V_62 -> V_68 > V_12 ) {
V_18 -> V_9 -> V_69 . V_70 ++ ;
V_18 -> V_9 -> V_69 . V_71 ++ ;
F_11 ( V_18 , L_6 , V_62 -> V_68 ) ;
F_19 ( V_62 ) ;
goto V_72;
}
V_62 -> V_73 = F_24 ( V_62 , V_18 -> V_9 ) ;
V_18 -> V_9 -> V_69 . V_74 ++ ;
V_18 -> V_9 -> V_69 . V_75 += V_62 -> V_68 ;
V_64 = F_25 ( V_62 ) ;
V_72:
V_62 = F_23 ( & V_18 -> V_67 ) ;
}
break;
case - V_76 :
case - V_77 :
F_26 ( V_18 , L_7 , V_64 ) ;
goto V_78;
case - V_79 :
F_11 ( V_18 , L_8 , V_61 -> V_23 ) ;
F_8 ( V_18 , V_57 ) ;
V_78:
F_19 ( V_32 ) ;
goto V_80;
case - V_81 :
V_18 -> V_9 -> V_69 . V_82 ++ ;
default:
V_18 -> V_9 -> V_69 . V_70 ++ ;
F_11 ( V_18 , L_9 , V_64 ) ;
break;
}
if ( V_32 )
F_19 ( V_32 ) ;
if ( ! F_27 ( V_18 -> V_9 ) ) {
V_80:
F_28 ( & V_18 -> V_58 ) ;
F_20 ( & V_29 -> V_59 , & V_18 -> V_60 ) ;
F_29 ( & V_18 -> V_58 ) ;
V_29 = NULL ;
}
if ( V_29 )
F_12 ( V_18 , V_29 , V_83 ) ;
}
static int F_30 ( struct V_84 * V_59 , struct V_36 * V_61 , unsigned V_85 )
{
unsigned V_86 ;
struct V_28 * V_29 ;
if ( ! V_85 )
return - V_34 ;
V_86 = V_85 ;
F_31 (req, list, list) {
if ( V_86 -- == 0 )
goto V_87;
}
while ( V_86 -- ) {
V_29 = F_32 ( V_61 , V_83 ) ;
if ( ! V_29 )
return F_33 ( V_59 ) ? - V_34 : 0 ;
F_20 ( & V_29 -> V_59 , V_59 ) ;
}
return 0 ;
V_87:
for (; ; ) {
struct V_84 * V_88 ;
V_88 = V_29 -> V_59 . V_88 ;
F_34 ( & V_29 -> V_59 ) ;
F_35 ( V_61 , V_29 ) ;
if ( V_88 == V_59 )
break;
V_29 = F_36 ( V_88 , struct V_28 , V_59 ) ;
}
return 0 ;
}
static int F_37 ( struct V_17 * V_18 , struct V_89 * V_90 , unsigned V_85 )
{
int V_64 ;
F_28 ( & V_18 -> V_58 ) ;
V_64 = F_30 ( & V_18 -> V_91 , V_90 -> V_92 , V_85 ) ;
if ( V_64 < 0 )
goto V_93;
V_64 = F_30 ( & V_18 -> V_60 , V_90 -> V_41 , V_85 ) ;
if ( V_64 < 0 )
goto V_93;
goto V_94;
V_93:
F_11 ( V_18 , L_10 ) ;
V_94:
F_29 ( & V_18 -> V_58 ) ;
return V_64 ;
}
static void F_38 ( struct V_17 * V_18 , T_1 V_30 )
{
struct V_28 * V_29 ;
unsigned long V_38 ;
F_13 ( & V_18 -> V_58 , V_38 ) ;
while ( ! F_33 ( & V_18 -> V_60 ) ) {
V_29 = F_36 ( V_18 -> V_60 . V_88 ,
struct V_28 , V_59 ) ;
F_39 ( & V_29 -> V_59 ) ;
F_14 ( & V_18 -> V_58 , V_38 ) ;
if ( F_12 ( V_18 , V_29 , V_30 ) < 0 ) {
F_8 ( V_18 , V_57 ) ;
return;
}
F_13 ( & V_18 -> V_58 , V_38 ) ;
}
F_14 ( & V_18 -> V_58 , V_38 ) ;
}
static void F_40 ( struct V_95 * V_27 )
{
struct V_17 * V_18 = F_36 ( V_27 , struct V_17 , V_27 ) ;
if ( F_41 ( V_57 , & V_18 -> V_26 ) ) {
if ( F_27 ( V_18 -> V_9 ) )
F_38 ( V_18 , V_96 ) ;
}
if ( V_18 -> V_26 )
F_11 ( V_18 , L_11 , V_18 -> V_26 ) ;
}
static void F_42 ( struct V_36 * V_61 , struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_56 ;
struct V_17 * V_18 = V_61 -> V_63 ;
switch ( V_29 -> V_64 ) {
default:
V_18 -> V_9 -> V_69 . V_97 ++ ;
F_26 ( V_18 , L_12 , V_29 -> V_64 ) ;
case - V_76 :
case - V_77 :
break;
case 0 :
V_18 -> V_9 -> V_69 . V_98 += V_32 -> V_68 ;
}
V_18 -> V_9 -> V_69 . V_99 ++ ;
F_28 ( & V_18 -> V_58 ) ;
F_20 ( & V_29 -> V_59 , & V_18 -> V_91 ) ;
F_29 ( & V_18 -> V_58 ) ;
F_19 ( V_32 ) ;
F_43 ( & V_18 -> V_100 ) ;
if ( F_44 ( V_18 -> V_9 ) )
F_45 ( V_18 -> V_9 ) ;
}
static inline int F_46 ( T_3 V_101 )
{
return V_101 & V_102 ;
}
static T_4 F_47 ( struct V_31 * V_32 ,
struct V_8 * V_9 )
{
struct V_17 * V_18 = F_5 ( V_9 ) ;
int V_53 = 0 ;
int V_33 ;
struct V_28 * V_29 = NULL ;
unsigned long V_38 ;
struct V_36 * V_103 ;
T_3 V_101 ;
F_13 ( & V_18 -> V_39 , V_38 ) ;
if ( V_18 -> V_40 ) {
V_103 = V_18 -> V_40 -> V_92 ;
V_101 = V_18 -> V_40 -> V_101 ;
} else {
V_103 = NULL ;
V_101 = 0 ;
}
F_14 ( & V_18 -> V_39 , V_38 ) ;
if ( V_32 && ! V_103 ) {
F_19 ( V_32 ) ;
return V_104 ;
}
if ( V_32 && ! F_46 ( V_101 ) ) {
T_5 * V_105 = V_32 -> V_52 ;
if ( F_48 ( V_105 ) ) {
T_3 type ;
if ( F_49 ( V_105 ) )
type = V_106 ;
else
type = V_107 ;
if ( ! ( V_101 & type ) ) {
F_19 ( V_32 ) ;
return V_104 ;
}
}
}
F_13 ( & V_18 -> V_58 , V_38 ) ;
if ( F_33 ( & V_18 -> V_91 ) ) {
F_14 ( & V_18 -> V_58 , V_38 ) ;
return V_108 ;
}
V_29 = F_36 ( V_18 -> V_91 . V_88 , struct V_28 , V_59 ) ;
F_34 ( & V_29 -> V_59 ) ;
if ( F_33 ( & V_18 -> V_91 ) )
F_50 ( V_9 ) ;
F_14 ( & V_18 -> V_58 , V_38 ) ;
if ( V_18 -> V_109 ) {
unsigned long V_38 ;
F_13 ( & V_18 -> V_39 , V_38 ) ;
if ( V_18 -> V_40 )
V_32 = V_18 -> V_109 ( V_18 -> V_40 , V_32 ) ;
F_14 ( & V_18 -> V_39 , V_38 ) ;
if ( ! V_32 ) {
if ( V_18 -> V_40 -> V_110 )
goto V_111;
goto V_112;
}
}
V_53 = V_32 -> V_68 ;
V_29 -> V_51 = V_32 -> V_52 ;
V_29 -> V_56 = V_32 ;
V_29 -> V_54 = F_42 ;
if ( V_18 -> V_40 -> V_47 &&
V_53 == V_18 -> V_40 -> V_113 &&
( V_53 % V_103 -> V_46 ) == 0 )
V_29 -> V_114 = 0 ;
else
V_29 -> V_114 = 1 ;
if ( V_29 -> V_114 && ! V_18 -> V_115 && ( V_53 % V_103 -> V_46 ) == 0 )
V_53 ++ ;
V_29 -> V_53 = V_53 ;
if ( F_2 ( V_18 -> V_2 ) )
V_29 -> V_116 = ( V_18 -> V_2 -> V_4 == V_5 ||
V_18 -> V_2 -> V_4 == V_6 )
? ( ( F_51 ( & V_18 -> V_100 ) % V_18 -> V_3 ) != 0 )
: 0 ;
V_33 = F_18 ( V_103 , V_29 , V_83 ) ;
switch ( V_33 ) {
default:
F_11 ( V_18 , L_13 , V_33 ) ;
break;
case 0 :
V_9 -> V_117 = V_118 ;
F_52 ( & V_18 -> V_100 ) ;
}
if ( V_33 ) {
F_19 ( V_32 ) ;
V_112:
V_18 -> V_9 -> V_69 . V_119 ++ ;
V_111:
F_13 ( & V_18 -> V_58 , V_38 ) ;
if ( F_33 ( & V_18 -> V_91 ) )
F_53 ( V_9 ) ;
F_20 ( & V_29 -> V_59 , & V_18 -> V_91 ) ;
F_14 ( & V_18 -> V_58 , V_38 ) ;
}
return V_104 ;
}
static void F_54 ( struct V_17 * V_18 , T_1 V_30 )
{
F_11 ( V_18 , L_14 , V_120 ) ;
F_38 ( V_18 , V_30 ) ;
F_55 ( & V_18 -> V_100 , 0 ) ;
F_45 ( V_18 -> V_9 ) ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_5 ( V_9 ) ;
struct V_89 * V_90 ;
F_11 ( V_18 , L_14 , V_120 ) ;
if ( F_44 ( V_18 -> V_9 ) )
F_54 ( V_18 , V_96 ) ;
F_57 ( & V_18 -> V_39 ) ;
V_90 = V_18 -> V_40 ;
if ( V_90 && V_90 -> V_121 )
V_90 -> V_121 ( V_90 ) ;
F_58 ( & V_18 -> V_39 ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_5 ( V_9 ) ;
unsigned long V_38 ;
F_26 ( V_18 , L_14 , V_120 ) ;
F_50 ( V_9 ) ;
F_11 ( V_18 , L_15 ,
V_18 -> V_9 -> V_69 . V_74 , V_18 -> V_9 -> V_69 . V_99 ,
V_18 -> V_9 -> V_69 . V_70 , V_18 -> V_9 -> V_69 . V_97
) ;
F_13 ( & V_18 -> V_39 , V_38 ) ;
if ( V_18 -> V_40 ) {
struct V_89 * V_90 = V_18 -> V_40 ;
const struct V_122 * V_103 ;
const struct V_122 * V_37 ;
if ( V_90 -> V_123 )
V_90 -> V_123 ( V_90 ) ;
V_103 = V_90 -> V_92 -> V_124 ;
V_37 = V_90 -> V_41 -> V_124 ;
F_60 ( V_90 -> V_92 ) ;
F_60 ( V_90 -> V_41 ) ;
if ( F_44 ( V_9 ) ) {
F_11 ( V_18 , L_16 ) ;
V_90 -> V_92 -> V_124 = V_103 ;
V_90 -> V_41 -> V_124 = V_37 ;
F_61 ( V_90 -> V_92 ) ;
F_61 ( V_90 -> V_41 ) ;
}
}
F_14 ( & V_18 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_62 ( const char * V_125 , T_5 * V_126 )
{
if ( V_125 ) {
unsigned V_86 ;
for ( V_86 = 0 ; V_86 < 6 ; V_86 ++ ) {
unsigned char V_127 ;
if ( ( * V_125 == '.' ) || ( * V_125 == ':' ) )
V_125 ++ ;
V_127 = F_63 ( * V_125 ++ ) << 4 ;
V_127 |= F_63 ( * V_125 ++ ) ;
V_126 [ V_86 ] = V_127 ;
}
if ( F_64 ( V_126 ) )
return 0 ;
}
F_65 ( V_126 ) ;
return 1 ;
}
static int F_66 ( T_5 V_126 [ V_128 ] , char * V_125 , int V_68 )
{
if ( V_68 < 18 )
return - V_129 ;
snprintf ( V_125 , V_68 , L_17 , V_126 ) ;
return 18 ;
}
struct V_17 * F_67 ( struct V_1 * V_130 ,
const char * V_126 , const char * V_131 ,
T_5 V_132 [ V_128 ] , unsigned V_3 , const char * V_133 )
{
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_64 ;
V_9 = F_68 ( sizeof *V_18 ) ;
if ( ! V_9 )
return F_69 ( - V_34 ) ;
V_18 = F_5 ( V_9 ) ;
F_70 ( & V_18 -> V_39 ) ;
F_70 ( & V_18 -> V_58 ) ;
F_71 ( & V_18 -> V_27 , F_40 ) ;
F_72 ( & V_18 -> V_91 ) ;
F_72 ( & V_18 -> V_60 ) ;
F_73 ( & V_18 -> V_67 ) ;
V_18 -> V_9 = V_9 ;
V_18 -> V_3 = V_3 ;
snprintf ( V_9 -> V_23 , sizeof( V_9 -> V_23 ) , L_18 , V_133 ) ;
if ( F_62 ( V_126 , V_9 -> V_126 ) )
F_74 ( & V_130 -> V_18 ,
L_19 , L_20 ) ;
if ( F_62 ( V_131 , V_18 -> V_134 ) )
F_74 ( & V_130 -> V_18 ,
L_19 , L_21 ) ;
if ( V_132 )
memcpy ( V_132 , V_18 -> V_134 , V_128 ) ;
V_9 -> V_135 = & V_136 ;
V_9 -> V_137 = & V_138 ;
V_18 -> V_2 = V_130 ;
F_75 ( V_9 , & V_130 -> V_18 ) ;
F_76 ( V_9 , & V_139 ) ;
V_64 = F_77 ( V_9 ) ;
if ( V_64 < 0 ) {
F_78 ( & V_130 -> V_18 , L_22 , V_64 ) ;
F_79 ( V_9 ) ;
V_18 = F_69 ( V_64 ) ;
} else {
F_80 ( V_18 , L_23 , V_9 -> V_126 ) ;
F_80 ( V_18 , L_24 , V_18 -> V_134 ) ;
F_81 ( V_9 ) ;
}
return V_18 ;
}
struct V_8 * F_82 ( const char * V_133 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 ;
V_9 = F_68 ( sizeof( * V_18 ) ) ;
if ( ! V_9 )
return F_69 ( - V_34 ) ;
V_18 = F_5 ( V_9 ) ;
F_70 ( & V_18 -> V_39 ) ;
F_70 ( & V_18 -> V_58 ) ;
F_71 ( & V_18 -> V_27 , F_40 ) ;
F_72 ( & V_18 -> V_91 ) ;
F_72 ( & V_18 -> V_60 ) ;
F_73 ( & V_18 -> V_67 ) ;
V_18 -> V_9 = V_9 ;
V_18 -> V_3 = V_140 ;
snprintf ( V_9 -> V_23 , sizeof( V_9 -> V_23 ) , L_18 , V_133 ) ;
F_65 ( V_18 -> V_141 ) ;
F_83 ( L_19 , L_20 ) ;
F_65 ( V_18 -> V_134 ) ;
F_83 ( L_19 , L_21 ) ;
V_9 -> V_135 = & V_136 ;
V_9 -> V_137 = & V_138 ;
F_76 ( V_9 , & V_139 ) ;
return V_9 ;
}
int F_84 ( struct V_8 * V_9 )
{
struct V_17 * V_18 ;
struct V_1 * V_130 ;
struct V_142 V_143 ;
int V_64 ;
if ( ! V_9 -> V_18 . V_144 )
return - V_129 ;
V_18 = F_5 ( V_9 ) ;
V_130 = V_18 -> V_2 ;
V_64 = F_77 ( V_9 ) ;
if ( V_64 < 0 ) {
F_78 ( & V_130 -> V_18 , L_22 , V_64 ) ;
return V_64 ;
} else {
F_80 ( V_18 , L_24 , V_18 -> V_134 ) ;
F_81 ( V_9 ) ;
}
V_143 . V_145 = V_9 -> type ;
memcpy ( V_143 . V_146 , V_18 -> V_141 , V_128 ) ;
F_85 () ;
V_64 = F_86 ( V_9 , & V_143 ) ;
F_87 () ;
if ( V_64 )
F_83 ( L_25 , V_64 ) ;
else
F_80 ( V_18 , L_23 , V_18 -> V_141 ) ;
return V_64 ;
}
void F_88 ( struct V_8 * V_9 , struct V_1 * V_130 )
{
struct V_17 * V_18 ;
V_18 = F_5 ( V_9 ) ;
V_18 -> V_2 = V_130 ;
F_75 ( V_9 , & V_130 -> V_18 ) ;
}
int F_89 ( struct V_8 * V_9 , const char * V_126 )
{
struct V_17 * V_18 ;
T_5 V_147 [ V_128 ] ;
V_18 = F_5 ( V_9 ) ;
if ( F_62 ( V_126 , V_147 ) )
return - V_129 ;
memcpy ( V_18 -> V_141 , V_147 , V_128 ) ;
return 0 ;
}
int F_90 ( struct V_8 * V_9 , char * V_126 , int V_68 )
{
struct V_17 * V_18 ;
V_18 = F_5 ( V_9 ) ;
return F_66 ( V_18 -> V_141 , V_126 , V_68 ) ;
}
int F_91 ( struct V_8 * V_9 , const char * V_131 )
{
struct V_17 * V_18 ;
T_5 V_147 [ V_128 ] ;
V_18 = F_5 ( V_9 ) ;
if ( F_62 ( V_131 , V_147 ) )
return - V_129 ;
memcpy ( V_18 -> V_134 , V_147 , V_128 ) ;
return 0 ;
}
int F_92 ( struct V_8 * V_9 , char * V_131 , int V_68 )
{
struct V_17 * V_18 ;
V_18 = F_5 ( V_9 ) ;
return F_66 ( V_18 -> V_134 , V_131 , V_68 ) ;
}
int F_93 ( struct V_8 * V_9 , char * V_131 , int V_68 )
{
struct V_17 * V_18 ;
if ( V_68 < 13 )
return - V_129 ;
V_18 = F_5 ( V_9 ) ;
snprintf ( V_131 , V_68 , L_26 , V_18 -> V_134 ) ;
return strlen ( V_131 ) ;
}
void F_94 ( struct V_8 * V_9 , T_5 V_134 [ V_128 ] )
{
struct V_17 * V_18 ;
V_18 = F_5 ( V_9 ) ;
memcpy ( V_134 , V_18 -> V_134 , V_128 ) ;
}
void F_95 ( struct V_8 * V_9 , unsigned V_3 )
{
struct V_17 * V_18 ;
V_18 = F_5 ( V_9 ) ;
V_18 -> V_3 = V_3 ;
}
unsigned F_96 ( struct V_8 * V_9 )
{
struct V_17 * V_18 ;
V_18 = F_5 ( V_9 ) ;
return V_18 -> V_3 ;
}
int F_97 ( struct V_8 * V_9 , char * V_23 , int V_68 )
{
F_85 () ;
F_6 ( V_23 , F_98 ( V_9 ) , V_68 ) ;
F_87 () ;
return strlen ( V_23 ) ;
}
void F_99 ( struct V_17 * V_18 )
{
if ( ! V_18 )
return;
F_100 ( V_18 -> V_9 ) ;
F_101 ( & V_18 -> V_27 ) ;
F_79 ( V_18 -> V_9 ) ;
}
struct V_8 * F_102 ( struct V_89 * V_90 )
{
struct V_17 * V_18 = V_90 -> V_148 ;
int V_149 = 0 ;
if ( ! V_18 )
return F_69 ( - V_129 ) ;
V_90 -> V_92 -> V_63 = V_18 ;
V_149 = F_61 ( V_90 -> V_92 ) ;
if ( V_149 != 0 ) {
F_11 ( V_18 , L_27 ,
V_90 -> V_92 -> V_23 , V_149 ) ;
goto V_150;
}
V_90 -> V_41 -> V_63 = V_18 ;
V_149 = F_61 ( V_90 -> V_41 ) ;
if ( V_149 != 0 ) {
F_11 ( V_18 , L_27 ,
V_90 -> V_41 -> V_23 , V_149 ) ;
goto V_151;
}
if ( V_149 == 0 )
V_149 = F_37 ( V_18 , V_90 , F_1 ( V_18 -> V_2 ,
V_18 -> V_3 ) ) ;
if ( V_149 == 0 ) {
V_18 -> V_115 = V_90 -> V_152 ;
F_11 ( V_18 , L_28 , F_1 ( V_18 -> V_2 , V_18 -> V_3 ) ) ;
V_18 -> V_45 = V_90 -> V_45 ;
V_18 -> V_66 = V_90 -> V_66 ;
V_18 -> V_109 = V_90 -> V_109 ;
F_28 ( & V_18 -> V_39 ) ;
V_18 -> V_40 = V_90 ;
if ( F_27 ( V_18 -> V_9 ) ) {
if ( V_90 -> V_121 )
V_90 -> V_121 ( V_90 ) ;
} else {
if ( V_90 -> V_123 )
V_90 -> V_123 ( V_90 ) ;
}
F_29 ( & V_18 -> V_39 ) ;
F_103 ( V_18 -> V_9 ) ;
if ( F_27 ( V_18 -> V_9 ) )
F_54 ( V_18 , V_83 ) ;
} else {
( void ) F_60 ( V_90 -> V_41 ) ;
V_151:
( void ) F_60 ( V_90 -> V_92 ) ;
}
V_150:
if ( V_149 < 0 )
return F_69 ( V_149 ) ;
return V_18 -> V_9 ;
}
void F_104 ( struct V_89 * V_90 )
{
struct V_17 * V_18 = V_90 -> V_148 ;
struct V_28 * V_29 ;
F_105 ( ! V_18 ) ;
if ( ! V_18 )
return;
F_11 ( V_18 , L_14 , V_120 ) ;
F_50 ( V_18 -> V_9 ) ;
F_81 ( V_18 -> V_9 ) ;
F_60 ( V_90 -> V_92 ) ;
F_28 ( & V_18 -> V_58 ) ;
while ( ! F_33 ( & V_18 -> V_91 ) ) {
V_29 = F_36 ( V_18 -> V_91 . V_88 ,
struct V_28 , V_59 ) ;
F_34 ( & V_29 -> V_59 ) ;
F_29 ( & V_18 -> V_58 ) ;
F_35 ( V_90 -> V_92 , V_29 ) ;
F_28 ( & V_18 -> V_58 ) ;
}
F_29 ( & V_18 -> V_58 ) ;
V_90 -> V_92 -> V_124 = NULL ;
F_60 ( V_90 -> V_41 ) ;
F_28 ( & V_18 -> V_58 ) ;
while ( ! F_33 ( & V_18 -> V_60 ) ) {
V_29 = F_36 ( V_18 -> V_60 . V_88 ,
struct V_28 , V_59 ) ;
F_34 ( & V_29 -> V_59 ) ;
F_29 ( & V_18 -> V_58 ) ;
F_35 ( V_90 -> V_41 , V_29 ) ;
F_28 ( & V_18 -> V_58 ) ;
}
F_29 ( & V_18 -> V_58 ) ;
V_90 -> V_41 -> V_124 = NULL ;
V_18 -> V_45 = 0 ;
V_18 -> V_66 = NULL ;
V_18 -> V_109 = NULL ;
F_28 ( & V_18 -> V_39 ) ;
V_18 -> V_40 = NULL ;
F_29 ( & V_18 -> V_39 ) ;
}
