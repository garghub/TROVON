static inline int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && V_2 -> V_3 == V_4 )
return V_5 * V_6 ;
else
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 , int V_9 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
unsigned long V_12 ;
int V_13 = 0 ;
F_5 ( & V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_15 )
V_13 = - V_16 ;
else if ( V_9 <= V_17 || V_9 > V_18 )
V_13 = - V_19 ;
else
V_8 -> V_20 = V_9 ;
F_6 ( & V_11 -> V_14 , V_12 ) ;
return V_13 ;
}
static void F_7 ( struct V_7 * V_8 , struct V_21 * V_22 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
F_8 ( V_22 -> V_23 , L_1 , sizeof V_22 -> V_23 ) ;
F_8 ( V_22 -> V_24 , V_25 , sizeof V_22 -> V_24 ) ;
F_8 ( V_22 -> V_26 , V_11 -> V_2 -> V_27 , sizeof V_22 -> V_26 ) ;
F_8 ( V_22 -> V_28 , F_9 ( & V_11 -> V_2 -> V_11 ) , sizeof V_22 -> V_28 ) ;
}
static void F_10 ( struct V_10 * V_11 , int V_29 )
{
if ( F_11 ( V_29 , & V_11 -> V_30 ) )
return;
if ( ! F_12 ( & V_11 -> V_31 ) )
ERROR ( V_11 , L_2 , V_29 ) ;
else
F_13 ( V_11 , L_3 , V_29 ) ;
}
static int
F_14 ( struct V_10 * V_11 , struct V_32 * V_33 , T_1 V_34 )
{
struct V_35 * V_36 ;
int V_37 = - V_38 ;
T_2 V_39 = 0 ;
struct V_40 * V_41 ;
unsigned long V_12 ;
F_5 ( & V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_15 )
V_41 = V_11 -> V_15 -> V_42 ;
else
V_41 = NULL ;
F_6 ( & V_11 -> V_14 , V_12 ) ;
if ( ! V_41 )
return - V_43 ;
V_39 += sizeof( struct V_44 ) + V_11 -> V_8 -> V_20 + V_45 ;
V_39 += V_11 -> V_15 -> V_46 ;
V_39 += V_41 -> V_47 - 1 ;
V_39 -= V_39 % V_41 -> V_47 ;
if ( V_11 -> V_15 -> V_48 )
V_39 = F_15 ( T_2 , V_39 , V_11 -> V_15 -> V_49 ) ;
V_36 = F_16 ( V_39 + V_50 , V_34 ) ;
if ( V_36 == NULL ) {
F_13 ( V_11 , L_4 ) ;
goto V_51;
}
F_17 ( V_36 , V_50 ) ;
V_33 -> V_52 = V_36 -> V_53 ;
V_33 -> V_54 = V_39 ;
V_33 -> V_55 = V_56 ;
V_33 -> V_57 = V_36 ;
V_37 = F_18 ( V_41 , V_33 , V_34 ) ;
if ( V_37 == - V_38 )
V_51:
F_10 ( V_11 , V_58 ) ;
if ( V_37 ) {
F_13 ( V_11 , L_5 , V_37 ) ;
if ( V_36 )
F_19 ( V_36 ) ;
F_5 ( & V_11 -> V_59 , V_12 ) ;
F_20 ( & V_33 -> V_60 , & V_11 -> V_61 ) ;
F_6 ( & V_11 -> V_59 , V_12 ) ;
}
return V_37 ;
}
static void V_56 ( struct V_40 * V_62 , struct V_32 * V_33 )
{
struct V_35 * V_36 = V_33 -> V_57 , * V_63 ;
struct V_10 * V_11 = V_62 -> V_64 ;
int V_13 = V_33 -> V_13 ;
switch ( V_13 ) {
case 0 :
F_21 ( V_36 , V_33 -> V_65 ) ;
if ( V_11 -> V_66 ) {
unsigned long V_12 ;
F_5 ( & V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_15 ) {
V_13 = V_11 -> V_66 ( V_11 -> V_15 ,
V_36 ,
& V_11 -> V_67 ) ;
} else {
F_19 ( V_36 ) ;
V_13 = - V_43 ;
}
F_6 ( & V_11 -> V_14 , V_12 ) ;
} else {
F_22 ( & V_11 -> V_67 , V_36 ) ;
}
V_36 = NULL ;
V_63 = F_23 ( & V_11 -> V_67 ) ;
while ( V_63 ) {
if ( V_13 < 0
|| V_17 > V_63 -> V_68
|| V_63 -> V_68 > V_18 ) {
V_11 -> V_8 -> V_69 . V_70 ++ ;
V_11 -> V_8 -> V_69 . V_71 ++ ;
F_13 ( V_11 , L_6 , V_63 -> V_68 ) ;
F_19 ( V_63 ) ;
goto V_72;
}
V_63 -> V_73 = F_24 ( V_63 , V_11 -> V_8 ) ;
V_11 -> V_8 -> V_69 . V_74 ++ ;
V_11 -> V_8 -> V_69 . V_75 += V_63 -> V_68 ;
V_13 = F_25 ( V_63 ) ;
V_72:
V_63 = F_23 ( & V_11 -> V_67 ) ;
}
break;
case - V_76 :
case - V_77 :
F_26 ( V_11 , L_7 , V_13 ) ;
goto V_78;
case - V_79 :
F_13 ( V_11 , L_8 , V_62 -> V_27 ) ;
F_10 ( V_11 , V_58 ) ;
V_78:
F_19 ( V_36 ) ;
goto V_80;
case - V_81 :
V_11 -> V_8 -> V_69 . V_82 ++ ;
default:
V_11 -> V_8 -> V_69 . V_70 ++ ;
F_13 ( V_11 , L_9 , V_13 ) ;
break;
}
if ( V_36 )
F_19 ( V_36 ) ;
if ( ! F_27 ( V_11 -> V_8 ) ) {
V_80:
F_28 ( & V_11 -> V_59 ) ;
F_20 ( & V_33 -> V_60 , & V_11 -> V_61 ) ;
F_29 ( & V_11 -> V_59 ) ;
V_33 = NULL ;
}
if ( V_33 )
F_14 ( V_11 , V_33 , V_83 ) ;
}
static int F_30 ( struct V_84 * V_60 , struct V_40 * V_62 , unsigned V_85 )
{
unsigned V_86 ;
struct V_32 * V_33 ;
if ( ! V_85 )
return - V_38 ;
V_86 = V_85 ;
F_31 (req, list, list) {
if ( V_86 -- == 0 )
goto V_87;
}
while ( V_86 -- ) {
V_33 = F_32 ( V_62 , V_83 ) ;
if ( ! V_33 )
return F_33 ( V_60 ) ? - V_38 : 0 ;
F_20 ( & V_33 -> V_60 , V_60 ) ;
}
return 0 ;
V_87:
for (; ; ) {
struct V_84 * V_88 ;
V_88 = V_33 -> V_60 . V_88 ;
F_34 ( & V_33 -> V_60 ) ;
F_35 ( V_62 , V_33 ) ;
if ( V_88 == V_60 )
break;
V_33 = F_36 ( V_88 , struct V_32 , V_60 ) ;
}
return 0 ;
}
static int F_37 ( struct V_10 * V_11 , struct V_89 * V_90 , unsigned V_85 )
{
int V_13 ;
F_28 ( & V_11 -> V_59 ) ;
V_13 = F_30 ( & V_11 -> V_91 , V_90 -> V_92 , V_85 ) ;
if ( V_13 < 0 )
goto V_93;
V_13 = F_30 ( & V_11 -> V_61 , V_90 -> V_42 , V_85 ) ;
if ( V_13 < 0 )
goto V_93;
goto V_94;
V_93:
F_13 ( V_11 , L_10 ) ;
V_94:
F_29 ( & V_11 -> V_59 ) ;
return V_13 ;
}
static void F_38 ( struct V_10 * V_11 , T_1 V_34 )
{
struct V_32 * V_33 ;
unsigned long V_12 ;
F_5 ( & V_11 -> V_59 , V_12 ) ;
while ( ! F_33 ( & V_11 -> V_61 ) ) {
V_33 = F_36 ( V_11 -> V_61 . V_88 ,
struct V_32 , V_60 ) ;
F_39 ( & V_33 -> V_60 ) ;
F_6 ( & V_11 -> V_59 , V_12 ) ;
if ( F_14 ( V_11 , V_33 , V_34 ) < 0 ) {
F_10 ( V_11 , V_58 ) ;
return;
}
F_5 ( & V_11 -> V_59 , V_12 ) ;
}
F_6 ( & V_11 -> V_59 , V_12 ) ;
}
static void F_40 ( struct V_95 * V_31 )
{
struct V_10 * V_11 = F_36 ( V_31 , struct V_10 , V_31 ) ;
if ( F_41 ( V_58 , & V_11 -> V_30 ) ) {
if ( F_27 ( V_11 -> V_8 ) )
F_38 ( V_11 , V_96 ) ;
}
if ( V_11 -> V_30 )
F_13 ( V_11 , L_11 , V_11 -> V_30 ) ;
}
static void F_42 ( struct V_40 * V_62 , struct V_32 * V_33 )
{
struct V_35 * V_36 = V_33 -> V_57 ;
struct V_10 * V_11 = V_62 -> V_64 ;
switch ( V_33 -> V_13 ) {
default:
V_11 -> V_8 -> V_69 . V_97 ++ ;
F_26 ( V_11 , L_12 , V_33 -> V_13 ) ;
case - V_76 :
case - V_77 :
break;
case 0 :
V_11 -> V_8 -> V_69 . V_98 += V_36 -> V_68 ;
}
V_11 -> V_8 -> V_69 . V_99 ++ ;
F_28 ( & V_11 -> V_59 ) ;
F_20 ( & V_33 -> V_60 , & V_11 -> V_91 ) ;
F_29 ( & V_11 -> V_59 ) ;
F_19 ( V_36 ) ;
F_43 ( & V_11 -> V_100 ) ;
if ( F_44 ( V_11 -> V_8 ) )
F_45 ( V_11 -> V_8 ) ;
}
static inline int F_46 ( T_3 V_101 )
{
return V_101 & V_102 ;
}
static T_4 F_47 ( struct V_35 * V_36 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
int V_54 = V_36 -> V_68 ;
int V_37 ;
struct V_32 * V_33 = NULL ;
unsigned long V_12 ;
struct V_40 * V_103 ;
T_3 V_101 ;
F_5 ( & V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_15 ) {
V_103 = V_11 -> V_15 -> V_92 ;
V_101 = V_11 -> V_15 -> V_101 ;
} else {
V_103 = NULL ;
V_101 = 0 ;
}
F_6 ( & V_11 -> V_14 , V_12 ) ;
if ( ! V_103 ) {
F_19 ( V_36 ) ;
return V_104 ;
}
if ( ! F_46 ( V_101 ) ) {
T_5 * V_105 = V_36 -> V_53 ;
if ( F_48 ( V_105 ) ) {
T_3 type ;
if ( F_49 ( V_105 ) )
type = V_106 ;
else
type = V_107 ;
if ( ! ( V_101 & type ) ) {
F_19 ( V_36 ) ;
return V_104 ;
}
}
}
F_5 ( & V_11 -> V_59 , V_12 ) ;
if ( F_33 ( & V_11 -> V_91 ) ) {
F_6 ( & V_11 -> V_59 , V_12 ) ;
return V_108 ;
}
V_33 = F_36 ( V_11 -> V_91 . V_88 , struct V_32 , V_60 ) ;
F_34 ( & V_33 -> V_60 ) ;
if ( F_33 ( & V_11 -> V_91 ) )
F_50 ( V_8 ) ;
F_6 ( & V_11 -> V_59 , V_12 ) ;
if ( V_11 -> V_109 ) {
unsigned long V_12 ;
F_5 ( & V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_15 )
V_36 = V_11 -> V_109 ( V_11 -> V_15 , V_36 ) ;
F_6 ( & V_11 -> V_14 , V_12 ) ;
if ( ! V_36 )
goto V_110;
V_54 = V_36 -> V_68 ;
}
V_33 -> V_52 = V_36 -> V_53 ;
V_33 -> V_57 = V_36 ;
V_33 -> V_55 = F_42 ;
if ( V_11 -> V_15 -> V_48 &&
V_54 == V_11 -> V_15 -> V_111 &&
( V_54 % V_103 -> V_47 ) == 0 )
V_33 -> V_112 = 0 ;
else
V_33 -> V_112 = 1 ;
if ( V_33 -> V_112 && ! V_11 -> V_113 && ( V_54 % V_103 -> V_47 ) == 0 )
V_54 ++ ;
V_33 -> V_54 = V_54 ;
if ( F_2 ( V_11 -> V_2 ) )
V_33 -> V_114 = ( V_11 -> V_2 -> V_3 == V_4 )
? ( ( F_51 ( & V_11 -> V_100 ) % V_5 ) != 0 )
: 0 ;
V_37 = F_18 ( V_103 , V_33 , V_83 ) ;
switch ( V_37 ) {
default:
F_13 ( V_11 , L_13 , V_37 ) ;
break;
case 0 :
V_8 -> V_115 = V_116 ;
F_52 ( & V_11 -> V_100 ) ;
}
if ( V_37 ) {
F_19 ( V_36 ) ;
V_110:
V_11 -> V_8 -> V_69 . V_117 ++ ;
F_5 ( & V_11 -> V_59 , V_12 ) ;
if ( F_33 ( & V_11 -> V_91 ) )
F_53 ( V_8 ) ;
F_20 ( & V_33 -> V_60 , & V_11 -> V_91 ) ;
F_6 ( & V_11 -> V_59 , V_12 ) ;
}
return V_104 ;
}
static void F_54 ( struct V_10 * V_11 , T_1 V_34 )
{
F_13 ( V_11 , L_14 , V_118 ) ;
F_38 ( V_11 , V_34 ) ;
F_55 ( & V_11 -> V_100 , 0 ) ;
F_45 ( V_11 -> V_8 ) ;
}
static int F_56 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_89 * V_90 ;
F_13 ( V_11 , L_14 , V_118 ) ;
if ( F_44 ( V_11 -> V_8 ) )
F_54 ( V_11 , V_96 ) ;
F_57 ( & V_11 -> V_14 ) ;
V_90 = V_11 -> V_15 ;
if ( V_90 && V_90 -> V_119 )
V_90 -> V_119 ( V_90 ) ;
F_58 ( & V_11 -> V_14 ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
unsigned long V_12 ;
F_26 ( V_11 , L_14 , V_118 ) ;
F_50 ( V_8 ) ;
F_13 ( V_11 , L_15 ,
V_11 -> V_8 -> V_69 . V_74 , V_11 -> V_8 -> V_69 . V_99 ,
V_11 -> V_8 -> V_69 . V_70 , V_11 -> V_8 -> V_69 . V_97
) ;
F_5 ( & V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_15 ) {
struct V_89 * V_90 = V_11 -> V_15 ;
if ( V_90 -> V_120 )
V_90 -> V_120 ( V_90 ) ;
F_60 ( V_90 -> V_92 ) ;
F_60 ( V_90 -> V_42 ) ;
if ( F_44 ( V_8 ) ) {
F_13 ( V_11 , L_16 ) ;
F_61 ( V_90 -> V_92 , V_90 -> V_103 ) ;
F_61 ( V_90 -> V_42 , V_90 -> V_41 ) ;
}
}
F_6 ( & V_11 -> V_14 , V_12 ) ;
return 0 ;
}
static int F_62 ( const char * V_121 , T_5 * V_122 )
{
if ( V_121 ) {
unsigned V_86 ;
for ( V_86 = 0 ; V_86 < 6 ; V_86 ++ ) {
unsigned char V_123 ;
if ( ( * V_121 == '.' ) || ( * V_121 == ':' ) )
V_121 ++ ;
V_123 = F_63 ( * V_121 ++ ) << 4 ;
V_123 |= F_63 ( * V_121 ++ ) ;
V_122 [ V_86 ] = V_123 ;
}
if ( F_64 ( V_122 ) )
return 0 ;
}
F_65 ( V_122 ) ;
return 1 ;
}
int F_66 ( struct V_1 * V_124 , T_5 V_125 [ V_126 ] )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_13 ;
if ( V_127 )
return - V_16 ;
V_8 = F_67 ( sizeof *V_11 ) ;
if ( ! V_8 )
return - V_38 ;
V_11 = F_4 ( V_8 ) ;
F_68 ( & V_11 -> V_14 ) ;
F_68 ( & V_11 -> V_59 ) ;
F_69 ( & V_11 -> V_31 , F_40 ) ;
F_70 ( & V_11 -> V_91 ) ;
F_70 ( & V_11 -> V_61 ) ;
F_71 ( & V_11 -> V_67 ) ;
V_11 -> V_8 = V_8 ;
strcpy ( V_8 -> V_27 , L_17 ) ;
if ( F_62 ( V_122 , V_8 -> V_122 ) )
F_72 ( & V_124 -> V_11 ,
L_18 , L_19 ) ;
if ( F_62 ( V_128 , V_11 -> V_129 ) )
F_72 ( & V_124 -> V_11 ,
L_18 , L_20 ) ;
if ( V_125 )
memcpy ( V_125 , V_11 -> V_129 , V_126 ) ;
V_8 -> V_130 = & V_131 ;
F_73 ( V_8 , & V_132 ) ;
F_74 ( V_8 ) ;
V_11 -> V_2 = V_124 ;
F_75 ( V_8 , & V_124 -> V_11 ) ;
F_76 ( V_8 , & V_133 ) ;
V_13 = F_77 ( V_8 ) ;
if ( V_13 < 0 ) {
F_78 ( & V_124 -> V_11 , L_21 , V_13 ) ;
F_79 ( V_8 ) ;
} else {
F_80 ( V_11 , L_22 , V_8 -> V_122 ) ;
F_80 ( V_11 , L_23 , V_11 -> V_129 ) ;
V_127 = V_11 ;
}
return V_13 ;
}
void F_81 ( void )
{
if ( ! V_127 )
return;
F_82 ( V_127 -> V_8 ) ;
F_83 ( & V_127 -> V_31 ) ;
F_79 ( V_127 -> V_8 ) ;
V_127 = NULL ;
}
struct V_7 * F_84 ( struct V_89 * V_90 )
{
struct V_10 * V_11 = V_127 ;
int V_134 = 0 ;
if ( ! V_11 )
return F_85 ( - V_135 ) ;
V_90 -> V_92 -> V_64 = V_11 ;
V_134 = F_61 ( V_90 -> V_92 , V_90 -> V_103 ) ;
if ( V_134 != 0 ) {
F_13 ( V_11 , L_24 ,
V_90 -> V_92 -> V_27 , V_134 ) ;
goto V_136;
}
V_90 -> V_42 -> V_64 = V_11 ;
V_134 = F_61 ( V_90 -> V_42 , V_90 -> V_41 ) ;
if ( V_134 != 0 ) {
F_13 ( V_11 , L_24 ,
V_90 -> V_42 -> V_27 , V_134 ) ;
goto V_137;
}
if ( V_134 == 0 )
V_134 = F_37 ( V_11 , V_90 , F_1 ( V_11 -> V_2 ) ) ;
if ( V_134 == 0 ) {
V_11 -> V_113 = V_90 -> V_138 ;
F_13 ( V_11 , L_25 , F_1 ( V_11 -> V_2 ) ) ;
V_11 -> V_46 = V_90 -> V_46 ;
V_11 -> V_66 = V_90 -> V_66 ;
V_11 -> V_109 = V_90 -> V_109 ;
F_28 ( & V_11 -> V_14 ) ;
V_11 -> V_15 = V_90 ;
V_90 -> V_139 = V_11 ;
if ( F_27 ( V_11 -> V_8 ) ) {
if ( V_90 -> V_119 )
V_90 -> V_119 ( V_90 ) ;
} else {
if ( V_90 -> V_120 )
V_90 -> V_120 ( V_90 ) ;
}
F_29 ( & V_11 -> V_14 ) ;
F_86 ( V_11 -> V_8 ) ;
if ( F_27 ( V_11 -> V_8 ) )
F_54 ( V_11 , V_83 ) ;
} else {
( void ) F_60 ( V_90 -> V_42 ) ;
V_137:
( void ) F_60 ( V_90 -> V_92 ) ;
}
V_136:
if ( V_134 < 0 )
return F_85 ( V_134 ) ;
return V_11 -> V_8 ;
}
void F_87 ( struct V_89 * V_90 )
{
struct V_10 * V_11 = V_90 -> V_139 ;
struct V_32 * V_33 ;
F_88 ( ! V_11 ) ;
if ( ! V_11 )
return;
F_13 ( V_11 , L_14 , V_118 ) ;
F_50 ( V_11 -> V_8 ) ;
F_74 ( V_11 -> V_8 ) ;
F_60 ( V_90 -> V_92 ) ;
F_28 ( & V_11 -> V_59 ) ;
while ( ! F_33 ( & V_11 -> V_91 ) ) {
V_33 = F_36 ( V_11 -> V_91 . V_88 ,
struct V_32 , V_60 ) ;
F_34 ( & V_33 -> V_60 ) ;
F_29 ( & V_11 -> V_59 ) ;
F_35 ( V_90 -> V_92 , V_33 ) ;
F_28 ( & V_11 -> V_59 ) ;
}
F_29 ( & V_11 -> V_59 ) ;
V_90 -> V_92 -> V_64 = NULL ;
V_90 -> V_103 = NULL ;
F_60 ( V_90 -> V_42 ) ;
F_28 ( & V_11 -> V_59 ) ;
while ( ! F_33 ( & V_11 -> V_61 ) ) {
V_33 = F_36 ( V_11 -> V_61 . V_88 ,
struct V_32 , V_60 ) ;
F_34 ( & V_33 -> V_60 ) ;
F_29 ( & V_11 -> V_59 ) ;
F_35 ( V_90 -> V_42 , V_33 ) ;
F_28 ( & V_11 -> V_59 ) ;
}
F_29 ( & V_11 -> V_59 ) ;
V_90 -> V_42 -> V_64 = NULL ;
V_90 -> V_41 = NULL ;
V_11 -> V_46 = 0 ;
V_11 -> V_66 = NULL ;
V_11 -> V_109 = NULL ;
F_28 ( & V_11 -> V_14 ) ;
V_11 -> V_15 = NULL ;
V_90 -> V_139 = NULL ;
F_29 ( & V_11 -> V_14 ) ;
}
