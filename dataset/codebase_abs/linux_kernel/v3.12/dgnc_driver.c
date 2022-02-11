int F_1 ( void )
{
int V_1 = 0 ;
F_2 ( ( L_1 , V_2 , V_3 ) ) ;
V_1 = F_3 () ;
if ( V_1 < 0 ) {
return ( V_1 ) ;
}
V_1 = F_4 () ;
if ( V_1 < 0 ) {
if ( V_4 )
F_5 ( & V_5 ) ;
else
F_6 ( L_2 ) ;
F_7 () ;
}
else {
F_8 ( & V_5 ) ;
}
F_9 ( ( L_3 , V_1 ) ) ;
return ( V_1 ) ;
}
static int F_3 ( void )
{
int V_1 = 0 ;
unsigned long V_6 ;
if ( V_7 == FALSE ) {
V_7 = TRUE ;
F_10 () ;
V_4 = 0 ;
F_2 ( ( L_4 ) ) ;
if ( ! V_8 ) {
V_1 = F_11 ( 0 , L_5 , & V_9 ) ;
if ( V_1 <= 0 ) {
F_2 ( ( L_6 , V_1 ) ) ;
V_1 = - V_10 ;
return ( V_1 ) ;
}
V_11 = V_1 ;
V_12 = F_12 ( V_13 , L_7 ) ;
#if V_14 < F_13 ( 2 , 6 , 28 )
F_14 ( V_12 , NULL ,
F_15 ( V_11 , 0 ) ,
NULL , L_7 ) ;
#else
F_16 ( V_12 , NULL ,
F_15 ( V_11 , 0 ) ,
NULL , L_7 ) ;
#endif
V_8 = TRUE ;
}
V_1 = F_17 () ;
if ( V_1 < 0 ) {
F_2 ( ( L_8 , V_1 ) ) ;
return ( V_1 ) ;
}
F_18 ( V_15 , V_6 ) ;
F_19 ( & V_16 ) ;
V_16 . V_17 = V_18 ;
V_16 . V_19 = 0 ;
V_20 = V_21 + F_20 ( V_22 ) ;
V_16 . V_23 = V_20 ;
F_21 ( V_15 , V_6 ) ;
F_22 ( & V_16 ) ;
V_24 = V_25 ;
}
return ( V_1 ) ;
}
static int F_4 ( void )
{
return F_23 ( & V_5 ) ;
}
static int F_24 ( struct V_26 * V_27 , const struct V_28 * V_29 )
{
int V_1 ;
V_1 = F_25 ( V_27 ) ;
if ( V_1 < 0 ) {
V_1 = - V_30 ;
} else {
V_1 = F_26 ( V_27 , V_29 -> V_31 ) ;
if ( V_1 == 0 ) {
V_4 ++ ;
F_9 ( ( L_9 , V_4 ) ) ;
}
}
return V_1 ;
}
static int F_26 ( struct V_26 * V_27 , int V_32 )
{
return F_27 ( V_27 , V_32 ) ;
}
static void F_28 ( struct V_26 * V_33 )
{
}
void F_7 ( void )
{
int V_34 ;
T_1 V_35 ;
F_18 ( V_15 , V_35 ) ;
V_36 = 1 ;
F_21 ( V_15 , V_35 ) ;
F_29 ( & V_16 ) ;
F_30 ( & V_5 ) ;
if ( V_8 ) {
F_31 ( V_12 , F_15 ( V_11 , 0 ) ) ;
F_32 ( V_12 ) ;
F_33 ( V_11 , L_5 ) ;
}
for ( V_34 = 0 ; V_34 < V_4 ; ++ V_34 ) {
F_34 ( V_37 [ V_34 ] ) ;
F_35 ( V_37 [ V_34 ] ) ;
F_36 ( V_37 [ V_34 ] ) ;
}
F_37 () ;
#if F_38 ( V_38 )
F_39 () ;
#endif
if ( V_4 )
F_5 ( & V_5 ) ;
}
static void F_36 ( struct V_39 * V_40 )
{
int V_34 = 0 ;
if( ! V_40 || V_40 -> V_41 != V_42 )
return;
switch ( V_40 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
F_40 ( 0 , V_40 -> V_48 + 0x4c ) ;
break;
default:
break;
}
if ( V_40 -> V_49 )
F_41 ( V_40 -> V_49 , V_40 ) ;
F_42 ( & V_40 -> V_50 ) ;
if ( V_40 -> V_51 ) {
F_43 ( V_40 -> V_51 ) ;
V_40 -> V_51 = NULL ;
}
if ( V_40 -> V_52 ) {
unsigned long V_6 ;
F_18 ( V_53 , V_6 ) ;
V_40 -> V_54 = NULL ;
F_6 ( L_10 , V_40 -> V_52 ) ;
F_44 ( V_40 -> V_52 ) ;
V_40 -> V_52 = NULL ;
F_21 ( V_53 , V_6 ) ;
}
for ( V_34 = 0 ; V_34 < V_55 ; V_34 ++ ) {
if ( V_40 -> V_56 [ V_34 ] ) {
if ( V_40 -> V_56 [ V_34 ] -> V_57 )
F_44 ( V_40 -> V_56 [ V_34 ] -> V_57 ) ;
if ( V_40 -> V_56 [ V_34 ] -> V_58 )
F_44 ( V_40 -> V_56 [ V_34 ] -> V_58 ) ;
if ( V_40 -> V_56 [ V_34 ] -> V_59 )
F_44 ( V_40 -> V_56 [ V_34 ] -> V_59 ) ;
F_44 ( V_40 -> V_56 [ V_34 ] ) ;
V_40 -> V_56 [ V_34 ] = NULL ;
}
}
if ( V_40 -> V_60 )
F_44 ( V_40 -> V_60 ) ;
V_37 [ V_40 -> V_61 ] = NULL ;
F_44 ( V_40 ) ;
}
static int F_27 ( struct V_26 * V_27 , int V_62 )
{
struct V_39 * V_40 ;
unsigned int V_63 ;
int V_34 = 0 ;
int V_1 = 0 ;
unsigned long V_6 ;
V_40 = V_37 [ V_4 ] =
(struct V_39 * ) F_45 ( sizeof( struct V_39 ) , V_64 ) ;
if ( ! V_40 ) {
F_2 ( ( L_11 ) ) ;
return ( - V_65 ) ;
}
V_40 -> V_54 = V_40 -> V_52 =
( char * ) F_45 ( sizeof( char ) * 8192 , V_64 ) ;
if ( ! V_40 -> V_54 ) {
F_44 ( V_40 ) ;
F_2 ( ( L_12 ) ) ;
return ( - V_65 ) ;
}
V_40 -> V_41 = V_42 ;
V_40 -> V_61 = V_4 ;
V_40 -> V_66 = V_67 [ V_62 ] . V_66 ;
V_40 -> V_43 = V_67 [ V_62 ] . V_43 ;
V_40 -> V_27 = V_27 ;
V_40 -> V_68 = V_27 -> V_69 -> V_70 ;
V_40 -> V_71 = F_46 ( V_27 -> V_72 ) ;
V_40 -> V_73 = V_74 [ V_62 ] . V_73 ;
V_40 -> V_75 = V_74 [ V_62 ] . V_75 ;
if ( V_74 [ V_34 ] . V_76 )
V_40 -> V_77 |= V_78 ;
V_40 -> V_79 = V_80 ;
F_47 ( & V_40 -> V_81 ) ;
F_48 ( V_40 -> V_82 ) ;
F_48 ( V_40 -> V_83 ) ;
V_40 -> V_84 = V_85 ;
for ( V_34 = 0 ; V_34 < V_55 ; V_34 ++ ) {
V_40 -> V_56 [ V_34 ] = NULL ;
}
F_49 ( V_27 , V_86 , & V_40 -> V_87 ) ;
F_49 ( V_27 , V_88 , & V_40 -> V_89 ) ;
F_50 ( V_27 , V_90 , & V_40 -> V_91 ) ;
V_63 = V_27 -> V_49 ;
V_40 -> V_49 = V_63 ;
switch( V_40 -> V_43 ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
V_40 -> V_92 = V_93 | V_94 ;
F_9 ( ( L_13 ) ) ;
V_40 -> V_95 = F_51 ( V_27 , 4 ) ;
if ( ! V_40 -> V_95 ) {
F_2 ( ( L_14 ) ) ;
return - V_96 ;
}
V_40 -> V_97 = F_52 ( V_27 , 4 ) ;
if ( V_40 -> V_95 & 1 )
V_40 -> V_95 &= ~ 3 ;
else
V_40 -> V_95 &= ~ 15 ;
V_40 -> V_48 = F_51 ( V_27 , 1 ) ;
V_40 -> V_98 = F_52 ( V_27 , 1 ) ;
V_40 -> V_48 = ( ( unsigned int ) ( V_40 -> V_48 ) ) & 0xFFFE ;
V_40 -> V_99 = & V_100 ;
V_40 -> V_101 = 0x8 ;
V_40 -> V_102 = 921600 ;
F_53 ( V_40 ) ;
V_40 -> V_99 -> V_103 ( V_40 ) ;
F_40 ( 0x43 , V_40 -> V_48 + 0x4c ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
if ( V_40 -> V_77 & V_78 )
V_40 -> V_92 = V_117 | V_94 ;
else
V_40 -> V_92 = V_118 | V_94 ;
F_9 ( ( L_15 ) ) ;
V_40 -> V_95 = F_51 ( V_27 , 0 ) ;
V_40 -> V_97 = F_52 ( V_27 , 0 ) ;
if ( V_40 -> V_95 & 1 )
V_40 -> V_95 &= ~ 3 ;
else
V_40 -> V_95 &= ~ 15 ;
V_40 -> V_99 = & V_119 ;
V_40 -> V_101 = 0x200 ;
V_40 -> V_102 = 921600 ;
F_53 ( V_40 ) ;
if ( V_40 -> V_51 ) {
V_40 -> V_120 = F_54 ( V_40 -> V_51 + 0x8D ) ;
V_40 -> V_99 -> V_103 ( V_40 ) ;
}
break;
default:
F_2 ( ( L_16 ) ) ;
return ( - V_10 ) ;
}
V_1 = F_55 ( V_40 ) ;
if ( V_1 < 0 ) {
F_35 ( V_40 ) ;
F_2 ( ( L_17 , V_1 ) ) ;
V_40 -> V_84 = V_121 ;
V_40 -> V_79 = V_80 ;
goto V_122;
}
V_1 = F_56 ( V_40 ) ;
if ( V_1 < 0 ) {
F_2 ( ( L_18 , V_1 ) ) ;
V_40 -> V_84 = V_121 ;
V_40 -> V_79 = V_80 ;
goto V_122;
}
V_1 = F_57 ( V_40 ) ;
if ( V_1 < 0 ) {
F_35 ( V_40 ) ;
F_2 ( ( L_19 , V_1 ) ) ;
V_40 -> V_84 = V_121 ;
V_40 -> V_79 = V_80 ;
goto V_122;
}
V_40 -> V_84 = V_123 ;
V_40 -> V_79 = V_124 ;
F_58 ( V_40 ) ;
F_59 ( & V_40 -> V_50 , V_40 -> V_99 -> V_125 , ( unsigned long ) V_40 ) ;
F_9 ( ( L_20 , V_34 ) ) ;
F_18 ( V_53 , V_6 ) ;
V_40 -> V_54 = NULL ;
F_6 ( L_10 , V_40 -> V_52 ) ;
F_44 ( V_40 -> V_52 ) ;
V_40 -> V_52 = NULL ;
F_21 ( V_53 , V_6 ) ;
V_40 -> V_60 = F_45 ( V_126 , V_64 ) ;
F_60 ( & V_40 -> V_81 ) ;
return ( 0 ) ;
V_122:
return ( - V_10 ) ;
}
static int F_56 ( struct V_39 * V_40 ) {
int V_1 = 0 ;
F_9 ( ( L_21 ) ) ;
if ( ! V_40 || V_40 -> V_41 != V_42 )
return ( - V_96 ) ;
F_9 ( ( L_22 ) ) ;
if ( V_40 -> V_49 ) {
V_1 = F_61 ( V_40 -> V_49 , V_40 -> V_99 -> V_127 , V_128 , L_23 , V_40 ) ;
if ( V_1 ) {
F_6 ( L_24 , V_40 -> V_49 ) ;
V_40 -> V_84 = V_121 ;
V_40 -> V_79 = V_80 ;
V_1 = - V_96 ;
} else {
F_9 ( ( L_25 , V_40 -> V_49 ) ) ;
}
}
return ( V_1 ) ;
}
static void F_53 ( struct V_39 * V_40 )
{
if ( ! V_40 || V_40 -> V_41 != V_42 )
return;
V_40 -> V_51 = F_62 ( V_40 -> V_95 , 0x1000 ) ;
F_9 ( ( L_26 , V_40 -> V_51 ) ) ;
}
static void V_18 ( T_1 V_129 )
{
struct V_39 * V_40 ;
unsigned long V_35 ;
int V_34 ;
unsigned long V_130 ;
V_131 ++ ;
if ( V_24 != V_25 ) {
goto V_132;
}
for ( V_34 = 0 ; V_34 < V_4 ; V_34 ++ ) {
V_40 = V_37 [ V_34 ] ;
F_18 ( V_40 -> V_82 , V_35 ) ;
if ( V_40 -> V_84 == V_121 ) {
F_21 ( V_40 -> V_82 , V_35 ) ;
continue;
}
F_63 ( & V_40 -> V_50 ) ;
F_21 ( V_40 -> V_82 , V_35 ) ;
}
V_132:
F_18 ( V_15 , V_35 ) ;
V_20 += F_20 ( V_22 ) ;
V_130 = V_20 - V_21 ;
if ( ( T_1 ) V_130 >= 2 * V_22 ) {
V_20 = V_21 + F_20 ( V_22 ) ;
}
F_19 ( & V_16 ) ;
V_16 . V_17 = V_18 ;
V_16 . V_19 = 0 ;
V_16 . V_23 = V_20 ;
F_21 ( V_15 , V_35 ) ;
if ( ! V_36 )
F_22 ( & V_16 ) ;
}
static void F_10 ( void )
{
int V_34 = 0 ;
V_133 = V_134 ;
V_135 = V_136 ;
V_137 = V_138 ;
for ( V_34 = 0 ; V_34 < V_139 ; V_34 ++ ) {
V_37 [ V_34 ] = NULL ;
}
F_19 ( & V_16 ) ;
}
int F_64 ( T_1 V_140 )
{
V_141 -> V_84 = V_142 ;
F_65 ( ( V_140 * V_143 ) / 1000 ) ;
return ( F_66 ( V_141 ) ) ;
}
char * F_67 ( int V_144 )
{
switch( V_144 ) {
case V_145 : return ( L_27 ) ;
case V_146 : return ( L_28 ) ;
case V_147 : return ( L_29 ) ;
case V_148 : return ( L_30 ) ;
case V_149 : return ( L_31 ) ;
case V_150 : return ( L_32 ) ;
case V_151 : return ( L_33 ) ;
case V_152 : return ( L_34 ) ;
case V_153 : return ( L_35 ) ;
case V_154 : return ( L_36 ) ;
case V_155 : return ( L_37 ) ;
case V_156 : return ( L_38 ) ;
case V_157 : return ( L_39 ) ;
case V_158 : return ( L_40 ) ;
case V_159 : return ( L_41 ) ;
case V_160 : return ( L_42 ) ;
case V_161 : return ( L_43 ) ;
case V_162 : return ( L_44 ) ;
case V_163 : return ( L_45 ) ;
case V_164 : return ( L_46 ) ;
case V_165 : return ( L_47 ) ;
case V_166 : return ( L_48 ) ;
case V_167 : return ( L_49 ) ;
case V_168 : return ( L_50 ) ;
case V_169 : return ( L_51 ) ;
case V_170 : return ( L_52 ) ;
case V_171 : return ( L_53 ) ;
case V_172 : return ( L_54 ) ;
case V_173 : return ( L_55 ) ;
case V_174 : return ( L_56 ) ;
case V_175 : return ( L_57 ) ;
case V_176 : return ( L_58 ) ;
case V_177 : return ( L_59 ) ;
case V_178 : return ( L_60 ) ;
case V_179 : return ( L_61 ) ;
case V_180 : return ( L_62 ) ;
default: return ( L_63 ) ;
}
}
