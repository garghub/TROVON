int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_4 ;
V_5 ;
F_2 ( & ( V_2 -> V_6 ) , 0 ) ;
F_2 ( & ( V_2 -> V_7 ) , 0 ) ;
F_3 ( & ( V_2 -> V_8 ) ) ;
V_2 -> V_9 = 1 ;
V_2 -> V_10 = F_4 ( V_11 + V_12 ) ;
if ( V_2 -> V_10 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_2 -> V_14 = V_2 -> V_10 + V_12 - ( ( V_15 ) ( V_2 -> V_10 ) & ( V_12 - 1 ) ) ;
V_2 -> V_16 = F_4 ( V_17 + 4 ) ;
if ( V_2 -> V_16 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_2 -> V_18 = V_2 -> V_16 + 4 - ( ( V_15 ) ( V_2 -> V_16 ) & 3 ) ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
exit:
V_22 ;
return V_3 ;
}
int F_5 ( struct V_23 * V_24 )
{
int V_3 = V_4 ;
V_5 ;
F_6 ( & V_24 -> V_25 , 0 ) ;
V_24 -> V_26 = 0 ;
F_7 ( & V_24 -> V_27 , V_28 , NULL ) ;
V_24 -> V_29 = false ;
V_24 -> V_30 = F_8 ( V_31 + 1 ) ;
V_22 ;
return V_3 ;
}
void F_9 ( struct V_23 * V_24 )
{
V_5 ;
F_10 ( V_32 , V_33 , ( L_1 ) ) ;
F_11 ( & V_24 -> V_27 ) ;
while ( V_24 -> V_29 )
F_12 ( 10 ) ;
while ( ! F_13 ( V_24 -> V_30 ) ) {
void * V_34 = F_14 ( V_24 -> V_30 ) ;
if ( V_34 != NULL && V_34 != ( void * ) V_24 )
F_15 ( V_34 ) ;
}
F_10 ( V_32 , V_33 , ( L_2 ) ) ;
V_22 ;
}
void F_16 ( struct V_1 * V_2 )
{
V_5 ;
if ( V_2 ) {
F_17 ( & ( V_2 -> V_8 . V_35 ) ) ;
F_18 ( & ( V_2 -> V_6 ) ) ;
F_18 ( & ( V_2 -> V_7 ) ) ;
if ( V_2 -> V_10 )
F_15 ( V_2 -> V_10 ) ;
if ( V_2 -> V_16 )
F_15 ( V_2 -> V_16 ) ;
}
V_22 ;
}
int F_19 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
unsigned long V_40 ;
V_5 ;
if ( V_39 == NULL )
goto exit;
F_20 ( & V_37 -> V_35 , & V_40 ) ;
F_21 ( & V_39 -> V_41 , & V_37 -> V_37 ) ;
F_22 ( & V_37 -> V_35 , & V_40 ) ;
exit:
V_22 ;
return V_4 ;
}
struct V_38 * F_23 ( struct V_36 * V_37 )
{
unsigned long V_40 ;
struct V_38 * V_39 ;
V_5 ;
F_20 ( & V_37 -> V_35 , & V_40 ) ;
if ( F_24 ( & ( V_37 -> V_37 ) ) ) {
V_39 = NULL ;
} else {
V_39 = F_25 ( F_26 ( & ( V_37 -> V_37 ) ) , struct V_38 , V_41 ) ;
F_27 ( & V_39 -> V_41 ) ;
}
F_22 ( & V_37 -> V_35 , & V_40 ) ;
V_22 ;
return V_39 ;
}
T_1 F_28 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_5 ;
V_3 = F_1 ( V_2 ) ;
V_22 ;
return V_3 ;
}
T_1 F_29 ( struct V_23 * V_24 )
{
int V_3 ;
V_5 ;
V_3 = F_5 ( V_24 ) ;
V_22 ;
return V_3 ;
}
void F_30 ( struct V_1 * V_2 )
{
V_5 ;
F_10 ( V_32 , V_33 , ( L_3 ) ) ;
F_16 ( V_2 ) ;
V_22 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
T_2 V_42 = false ;
if ( ( V_2 -> V_43 -> V_44 . V_45 ) &&
( ! V_2 -> V_43 -> V_46 . V_47 ) ) {
if ( V_38 -> V_48 == F_32 ( V_49 ) ) {
struct V_50 * V_51 = (struct V_50 * ) V_38 -> V_52 ;
if ( V_51 -> V_53 == V_54 )
V_42 = true ;
}
}
if ( V_38 -> V_48 == F_32 ( V_55 ) )
V_42 = true ;
if ( ( ! V_2 -> V_43 -> V_56 && ! V_42 ) ||
! V_2 -> V_57 )
return V_13 ;
return V_4 ;
}
T_1 F_33 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
int V_3 = V_13 ;
struct V_58 * V_43 = V_2 -> V_43 ;
V_5 ;
if ( V_38 == NULL )
goto exit;
V_38 -> V_43 = V_43 ;
V_3 = F_31 ( V_2 , V_38 ) ;
if ( V_13 == V_3 ) {
F_34 ( V_38 ) ;
goto exit;
}
V_3 = F_19 ( & V_2 -> V_8 , V_38 ) ;
if ( V_3 == V_4 )
F_35 ( & V_2 -> V_6 ) ;
exit:
V_22 ;
return V_3 ;
}
struct V_38 * F_36 ( struct V_1 * V_2 )
{
struct V_38 * V_38 ;
V_5 ;
V_38 = F_23 ( & V_2 -> V_8 ) ;
V_22 ;
return V_38 ;
}
void F_37 ( struct V_1 * V_2 )
{
V_5 ;
V_2 -> V_20 ++ ;
V_22 ;
}
void F_34 ( struct V_38 * V_59 )
{
V_5 ;
if ( ( V_59 -> V_48 != V_60 ) && ( V_59 -> V_48 != V_61 ) ) {
F_15 ( V_59 -> V_52 ) ;
}
if ( V_59 -> V_62 != NULL ) {
if ( V_59 -> V_63 != 0 ) {
F_15 ( V_59 -> V_62 ) ;
}
}
F_15 ( V_59 ) ;
V_22 ;
}
int F_38 ( void * V_64 )
{
T_2 V_65 ;
struct V_38 * V_59 ;
T_2 * V_66 ;
T_2 (* F_39)( struct V_58 * V_43 , T_2 * V_67 );
void (* F_40)( struct V_58 * V_68 , struct V_38 * V_59 );
struct V_58 * V_43 = (struct V_58 * ) V_64 ;
struct V_1 * V_2 = & ( V_43 -> V_69 ) ;
V_5 ;
F_41 ( L_4 ) ;
V_66 = V_2 -> V_14 ;
V_2 -> V_57 = true ;
F_35 ( & V_2 -> V_7 ) ;
F_10 ( V_32 , V_33 , ( L_5 ) ) ;
while ( 1 ) {
if ( F_42 ( & V_2 -> V_6 ) == V_13 )
break;
if ( V_43 -> V_70 ||
V_43 -> V_71 ) {
F_43 ( L_6 ,
V_72 , V_43 -> V_70 , V_43 -> V_71 , __LINE__ ) ;
break;
}
V_73:
if ( V_43 -> V_70 ||
V_43 -> V_71 ) {
F_43 ( L_6 ,
V_72 , V_43 -> V_70 , V_43 -> V_71 , __LINE__ ) ;
break;
}
V_59 = F_36 ( V_2 ) ;
if ( ! V_59 )
continue;
if ( V_13 == F_31 ( V_2 , V_59 ) ) {
V_59 -> V_3 = V_74 ;
goto V_75;
}
V_2 -> V_19 ++ ;
V_59 -> V_76 = F_44 ( ( V_59 -> V_76 ) ) ;
memcpy ( V_66 , V_59 -> V_52 , V_59 -> V_76 ) ;
if ( V_59 -> V_48 < F_45 ( V_77 ) ) {
F_39 = V_77 [ V_59 -> V_48 ] . V_78 ;
if ( F_39 ) {
V_65 = F_39 ( V_59 -> V_43 , V_66 ) ;
V_59 -> V_3 = V_65 ;
}
V_2 -> V_9 ++ ;
} else {
V_59 -> V_3 = V_79 ;
}
F_39 = NULL ;
V_75:
if ( V_59 -> V_48 < F_45 ( V_80 ) ) {
F_40 = V_80 [ V_59 -> V_48 ] . V_81 ;
if ( F_40 == NULL ) {
F_10 ( V_32 , V_33 , ( L_7 , F_40 , V_59 -> V_48 ) ) ;
F_34 ( V_59 ) ;
} else {
F_40 ( V_59 -> V_43 , V_59 ) ;
}
} else {
F_10 ( V_32 , V_82 , ( L_8 , V_72 , V_59 -> V_48 ) ) ;
F_34 ( V_59 ) ;
}
F_46 () ;
goto V_73;
}
V_2 -> V_57 = false ;
do {
V_59 = F_36 ( V_2 ) ;
if ( V_59 == NULL )
break;
F_34 ( V_59 ) ;
} while ( 1 );
F_35 ( & V_2 -> V_7 ) ;
V_22 ;
F_47 () ;
}
T_2 F_48 ( struct V_58 * V_43 , T_3 V_83 )
{
struct V_38 * V_84 ;
struct V_85 * V_86 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_65 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_65 = V_13 ;
goto exit;
}
V_86 = (struct V_85 * ) F_4 ( sizeof( struct V_85 ) ) ;
if ( V_86 == NULL ) {
F_15 ( V_84 ) ;
V_65 = V_13 ;
goto exit;
}
V_86 -> V_83 = V_83 ;
F_49 ( V_84 , V_86 , F_32 ( V_87 ) ) ;
V_65 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_65 ;
}
T_2 F_50 ( struct V_58 * V_43 , struct V_88 * V_89 , int V_90 ,
struct V_91 * V_92 , int V_93 )
{
T_2 V_3 = V_13 ;
struct V_38 * V_84 ;
struct V_94 * V_95 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( F_51 ( V_97 , V_99 ) == true ) {
F_52 ( V_43 , V_100 , 1 ) ;
}
if ( F_51 ( V_97 , V_99 ) == true ) {
F_53 ( V_43 , V_101 , 1 ) ;
}
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL )
return V_13 ;
V_95 = (struct V_94 * ) F_4 ( sizeof( struct V_94 ) ) ;
if ( V_95 == NULL ) {
F_15 ( V_84 ) ;
return V_13 ;
}
F_54 ( V_43 , false ) ;
F_10 ( V_32 , V_33 , ( L_9 , V_72 ) ) ;
F_49 ( V_84 , V_95 , F_32 ( V_102 ) ) ;
V_95 -> V_103 = V_97 -> V_103 ;
if ( V_89 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_90 && V_104 < V_105 ; V_104 ++ ) {
if ( V_89 [ V_104 ] . V_106 ) {
memcpy ( & V_95 -> V_89 [ V_104 ] , & V_89 [ V_104 ] , sizeof( struct V_88 ) ) ;
V_95 -> V_90 ++ ;
if ( 0 )
F_43 ( V_107 L_10 , F_55 ( V_43 ) ,
V_95 -> V_89 [ V_104 ] . V_108 , V_95 -> V_89 [ V_104 ] . V_106 ) ;
}
}
}
if ( V_92 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_93 && V_104 < V_109 ; V_104 ++ ) {
if ( V_92 [ V_104 ] . V_110 && ! ( V_92 [ V_104 ] . V_111 & V_112 ) ) {
memcpy ( & V_95 -> V_92 [ V_104 ] , & V_92 [ V_104 ] , sizeof( struct V_91 ) ) ;
V_95 -> V_93 ++ ;
if ( 0 )
F_43 ( V_107 L_11 , F_55 ( V_43 ) ,
V_95 -> V_92 [ V_104 ] . V_110 ) ;
}
}
}
F_56 ( V_97 , V_113 ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
if ( V_3 == V_4 ) {
V_97 -> V_114 = F_57 () ;
F_58 ( & V_97 -> V_115 , V_116 ) ;
F_59 ( V_43 , V_117 ) ;
V_97 -> V_118 = V_119 ;
} else {
F_60 ( V_97 , V_113 ) ;
}
V_22 ;
return V_3 ;
}
T_2 F_61 ( struct V_58 * V_43 , T_2 * V_120 )
{
struct V_38 * V_84 ;
struct V_121 * V_122 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_122 = (struct V_121 * ) F_4 ( sizeof( struct V_121 ) ) ;
if ( V_122 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_122 , F_32 ( V_123 ) ) ;
V_122 -> V_124 = 5 ;
memcpy ( V_122 -> V_125 , V_120 , V_126 ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_62 ( struct V_58 * V_43 , T_2 * V_120 )
{
struct V_38 * V_84 ;
struct V_127 * V_128 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_128 = (struct V_127 * ) F_4 ( sizeof( struct V_127 ) ) ;
if ( V_128 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_128 , V_129 ) ;
memcpy ( V_128 -> V_130 , V_120 , V_126 ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_63 ( struct V_58 * V_43 , T_2 V_131 , T_2 V_92 )
{
struct V_38 * V_84 ;
struct V_132 * V_133 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_133 = (struct V_132 * ) F_4 ( sizeof( struct V_132 ) ) ;
if ( V_133 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_133 , V_134 ) ;
F_10 ( V_32 , V_33 , ( L_12 , V_92 , V_131 ) ) ;
V_133 -> V_131 = V_131 ;
V_133 -> V_135 = V_92 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_64 ( struct V_58 * V_43 , T_2 V_136 , T_2 V_137 )
{
struct V_38 * V_84 ;
struct V_138 * V_139 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_139 = (struct V_138 * ) F_4 ( sizeof( struct V_138 ) ) ;
if ( V_139 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_139 , F_32 ( V_140 ) ) ;
V_139 -> V_136 = V_136 ;
V_139 -> V_141 = V_137 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_65 ( struct V_58 * V_43 , T_2 V_136 , T_2 * V_142 )
{
struct V_38 * V_84 ;
struct V_143 * V_144 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_144 = (struct V_143 * ) F_4 ( sizeof( struct V_143 ) ) ;
if ( V_144 == NULL ) {
F_15 ( V_84 ) ;
return V_13 ;
}
F_66 ( & V_84 -> V_41 ) ;
V_84 -> V_48 = F_32 ( V_145 ) ;
V_84 -> V_52 = ( unsigned char * ) V_144 ;
V_84 -> V_76 = sizeof( struct V_143 ) ;
V_84 -> V_62 = V_142 ;
V_84 -> V_63 = sizeof( struct V_146 ) ;
V_144 -> V_136 = V_136 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_67 ( struct V_58 * V_43 , T_2 V_136 , T_1 V_137 )
{
struct V_38 * V_84 ;
struct V_147 * V_148 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_148 = (struct V_147 * ) F_4 ( sizeof( struct V_147 ) ) ;
if ( V_148 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_148 , F_32 ( V_149 ) ) ;
V_148 -> V_136 = V_136 ;
V_148 -> V_141 = V_137 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_68 ( struct V_58 * V_43 , T_2 V_136 , T_2 * V_142 )
{
struct V_38 * V_84 ;
struct V_150 * V_151 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_151 = (struct V_150 * ) F_4 ( sizeof( struct V_150 ) ) ;
if ( V_151 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_66 ( & V_84 -> V_41 ) ;
V_84 -> V_48 = F_32 ( V_152 ) ;
V_84 -> V_52 = ( unsigned char * ) V_151 ;
V_84 -> V_76 = sizeof( struct V_150 ) ;
V_84 -> V_62 = V_142 ;
V_84 -> V_63 = sizeof( struct V_153 ) ;
V_151 -> V_136 = V_136 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
void F_69 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
V_5 ;
F_15 ( V_59 -> V_52 ) ;
F_15 ( V_59 ) ;
if ( V_43 -> V_46 . V_154 == 1 )
V_43 -> V_155 . V_156 . V_157 = true ;
V_22 ;
}
void F_70 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
V_5 ;
F_15 ( V_59 -> V_52 ) ;
F_15 ( V_59 ) ;
if ( V_43 -> V_46 . V_154 == 1 )
V_43 -> V_155 . V_156 . V_157 = true ;
V_22 ;
}
T_2 F_71 ( struct V_58 * V_43 )
{
struct V_38 * V_59 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_158 * V_159 = & V_43 -> V_46 . V_160 ;
T_2 V_3 = V_4 ;
V_5 ;
F_59 ( V_43 , V_161 ) ;
if ( V_97 -> V_162 . V_106 == 0 )
F_10 ( V_32 , V_33 , ( L_13 , V_97 -> V_162 . V_108 ) ) ;
else
F_10 ( V_32 , V_33 , ( L_14 , V_97 -> V_162 . V_108 ) ) ;
V_59 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_59 == NULL ) {
V_3 = V_13 ;
goto exit;
}
F_66 ( & V_59 -> V_41 ) ;
V_59 -> V_48 = V_61 ;
V_59 -> V_52 = ( unsigned char * ) V_159 ;
V_59 -> V_76 = F_72 ( (struct V_158 * ) V_159 ) ;
V_59 -> V_62 = NULL ;
V_59 -> V_63 = 0 ;
V_159 -> V_163 = V_59 -> V_76 ;
V_3 = F_33 ( V_2 , V_59 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_73 ( struct V_58 * V_43 , unsigned char * V_164 , unsigned int V_165 )
{
struct V_38 * V_59 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_59 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_59 == NULL ) {
V_3 = V_13 ;
goto exit;
}
F_66 ( & V_59 -> V_41 ) ;
V_59 -> V_48 = F_32 ( V_166 ) ;
V_59 -> V_52 = V_164 ;
V_59 -> V_76 = V_165 ;
V_59 -> V_62 = NULL ;
V_59 -> V_63 = 0 ;
V_3 = F_33 ( V_2 , V_59 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_74 ( struct V_58 * V_43 , struct V_167 * V_168 )
{
T_2 V_3 = V_4 ;
T_3 V_169 = 0 ;
struct V_158 * V_170 ;
struct V_38 * V_59 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_171 * V_172 = & V_97 -> V_173 ;
struct V_174 * V_175 = & V_43 -> V_176 ;
struct V_177 * V_178 = & V_43 -> V_46 ;
struct V_179 * V_180 = & V_97 -> V_181 ;
enum V_182 V_183 = V_168 -> V_184 . V_185 ;
struct V_186 * V_187 = & V_43 -> V_188 ;
struct V_189 * V_190 = & ( V_187 -> V_191 ) ;
V_5 ;
F_59 ( V_43 , V_161 ) ;
if ( V_97 -> V_162 . V_106 == 0 ) {
F_10 ( V_32 , V_33 , ( L_15 ) ) ;
} else {
F_10 ( V_32 , V_192 , ( L_16 , V_97 -> V_162 . V_108 ) ) ;
}
V_59 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_59 == NULL ) {
V_3 = V_13 ;
F_10 ( V_32 , V_82 , ( L_17 ) ) ;
goto exit;
}
V_169 = sizeof( struct V_158 ) ;
if ( ! F_51 ( V_97 , V_193 | V_194 ) ) {
switch ( V_183 ) {
case V_195 :
F_56 ( V_97 , V_194 ) ;
break;
case V_196 :
F_56 ( V_97 , V_193 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
break;
}
}
V_170 = (struct V_158 * ) & V_175 -> V_200 ;
if ( V_170 == NULL ) {
if ( V_59 != NULL )
F_15 ( V_59 ) ;
V_3 = V_13 ;
F_10 ( V_32 , V_82 , ( L_18 ) ) ;
goto exit;
}
F_75 ( V_170 , 0 , V_169 ) ;
memcpy ( V_170 , & V_168 -> V_184 , F_72 ( & V_168 -> V_184 ) ) ;
V_175 -> V_201 [ 0 ] = ( unsigned char ) V_170 -> V_202 ;
if ( ( V_170 -> V_202 - 12 ) < ( 256 - 1 ) ) {
memcpy ( & V_175 -> V_201 [ 1 ] , & V_170 -> V_203 [ 12 ] , V_170 -> V_202 - 12 ) ;
} else {
memcpy ( & V_175 -> V_201 [ 1 ] , & V_170 -> V_203 [ 12 ] , ( 256 - 1 ) ) ;
}
V_170 -> V_202 = 0 ;
if ( ! V_97 -> V_204 )
memcpy ( & V_97 -> V_205 [ 0 ] , & V_168 -> V_184 . V_206 [ 0 ] , V_207 ) ;
V_170 -> V_202 = F_76 ( V_43 , & V_168 -> V_184 . V_203 [ 0 ] , & V_170 -> V_203 [ 0 ] , V_168 -> V_184 . V_202 ) ;
V_172 -> V_208 = 0 ;
if ( V_178 -> V_209 ) {
T_1 V_210 ;
V_210 = F_77 ( V_43 , & V_168 -> V_184 . V_203 [ 0 ] , & V_170 -> V_203 [ 0 ] , V_168 -> V_184 . V_202 , V_170 -> V_202 ) ;
if ( V_170 -> V_202 != V_210 ) {
V_170 -> V_202 = V_210 ;
V_172 -> V_208 = 1 ;
} else {
V_172 -> V_208 = 0 ;
}
}
V_180 -> V_211 = false ;
if ( V_178 -> V_212 ) {
if ( ( V_43 -> V_176 . V_213 != V_214 ) &&
( V_43 -> V_176 . V_213 != V_215 ) &&
( V_43 -> V_176 . V_213 != V_216 ) ) {
F_78 ( V_43 , & V_168 -> V_184 . V_203 [ 0 ] , & V_170 -> V_203 [ 0 ] ,
V_168 -> V_184 . V_202 , & V_170 -> V_202 ) ;
}
}
V_190 -> V_217 = F_79 ( V_168 -> V_184 . V_203 , V_168 -> V_184 . V_202 ) ;
if ( V_190 -> V_217 == V_218 )
V_43 -> V_44 . V_219 = 0 ;
else
V_43 -> V_44 . V_219 = V_43 -> V_46 . V_219 ;
F_43 ( L_19 , V_72 , V_43 -> V_44 . V_219 ) ;
V_59 -> V_76 = F_72 ( V_170 ) ;
F_66 ( & V_59 -> V_41 ) ;
V_59 -> V_48 = V_60 ;
V_59 -> V_52 = ( unsigned char * ) V_170 ;
V_59 -> V_62 = NULL ;
V_59 -> V_63 = 0 ;
V_3 = F_33 ( V_2 , V_59 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_80 ( struct V_58 * V_43 , T_1 V_220 , bool V_221 )
{
struct V_38 * V_222 = NULL ;
struct V_223 * V_224 = NULL ;
struct V_1 * V_69 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_192 , ( L_20 ) ) ;
V_224 = (struct V_223 * ) F_4 ( sizeof( * V_224 ) ) ;
if ( V_224 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_224 -> V_220 = V_220 ;
if ( V_221 ) {
V_222 = (struct V_38 * ) F_4 ( sizeof( * V_222 ) ) ;
if ( V_222 == NULL ) {
V_3 = V_13 ;
F_15 ( V_224 ) ;
goto exit;
}
F_49 ( V_222 , V_224 , V_225 ) ;
V_3 = F_33 ( V_69 , V_222 ) ;
} else {
if ( V_226 != F_81 ( V_43 , ( T_2 * ) V_224 ) )
V_3 = V_13 ;
F_15 ( V_224 ) ;
}
exit:
V_22 ;
return V_3 ;
}
T_2 F_82 ( struct V_58 * V_43 , enum V_182 V_227 )
{
struct V_38 * V_84 ;
struct V_228 * V_229 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = false ;
goto exit;
}
V_229 = (struct V_228 * ) F_4 ( sizeof( struct V_228 ) ) ;
if ( V_229 == NULL ) {
F_15 ( V_84 ) ;
V_3 = false ;
goto exit;
}
F_49 ( V_84 , V_229 , V_230 ) ;
V_229 -> V_231 = ( T_2 ) V_227 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_83 ( struct V_58 * V_43 , T_2 * V_232 , T_2 V_233 )
{
struct V_38 * V_84 ;
struct V_234 * V_235 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_236 * V_237 = NULL ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_174 * V_175 = & V_43 -> V_176 ;
struct V_238 * V_239 = (struct V_238 * ) V_232 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_235 = (struct V_234 * ) F_4 ( sizeof( struct V_234 ) ) ;
if ( V_235 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_237 = (struct V_236 * ) F_4 ( sizeof( struct V_236 ) ) ;
if ( V_237 == NULL ) {
F_15 ( V_84 ) ;
F_15 ( V_235 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_235 , V_240 ) ;
V_84 -> V_62 = ( T_2 * ) V_237 ;
V_84 -> V_63 = sizeof( struct V_236 ) ;
memcpy ( V_235 -> V_241 , V_239 -> V_242 , V_207 ) ;
if ( F_51 ( V_97 , V_193 ) )
V_235 -> V_243 = ( unsigned char ) V_175 -> V_213 ;
else
F_84 ( V_175 , V_239 , V_235 -> V_243 , false ) ;
if ( V_233 )
memcpy ( & V_235 -> V_244 , & V_239 -> V_245 , 16 ) ;
else
memcpy ( & V_235 -> V_244 , & V_175 -> V_246 [ V_175 -> V_247 ] . V_248 , 16 ) ;
V_43 -> V_176 . V_249 = true ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_85 ( struct V_58 * V_43 , T_2 * V_232 , T_2 V_250 , T_2 V_221 )
{
struct V_38 * V_84 ;
struct V_234 * V_235 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_236 * V_237 = NULL ;
struct V_238 * V_239 = (struct V_238 * ) V_232 ;
T_2 V_3 = V_4 ;
V_5 ;
if ( ! V_221 ) {
F_86 ( V_43 , V_250 ) ;
} else {
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_235 = (struct V_234 * ) F_4 ( sizeof( struct V_234 ) ) ;
if ( V_235 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_237 = (struct V_236 * ) F_4 ( sizeof( struct V_236 ) ) ;
if ( V_237 == NULL ) {
F_15 ( V_84 ) ;
F_15 ( V_235 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_235 , V_240 ) ;
V_84 -> V_62 = ( T_2 * ) V_237 ;
V_84 -> V_63 = sizeof( struct V_236 ) ;
memcpy ( V_235 -> V_241 , V_239 -> V_242 , V_207 ) ;
V_235 -> V_243 = V_251 ;
V_235 -> V_252 = V_250 ;
V_3 = F_33 ( V_2 , V_84 ) ;
}
exit:
V_22 ;
return V_3 ;
}
T_2 F_87 ( struct V_58 * V_43 , struct V_253 * V_254 )
{
struct V_38 * V_84 ;
struct V_253 * V_255 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_255 = (struct V_253 * ) F_4 ( sizeof( struct V_253 ) ) ;
if ( V_255 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_84 , V_255 , F_32 ( V_256 ) ) ;
memcpy ( V_255 , V_254 , sizeof( struct V_253 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_88 ( struct V_58 * V_43 , struct V_257 * V_142 )
{
struct V_38 * V_84 ;
struct V_258 * V_259 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_259 = (struct V_258 * ) F_4 ( sizeof( struct V_258 ) ) ;
if ( V_259 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_66 ( & V_84 -> V_41 ) ;
V_84 -> V_48 = F_32 ( V_260 ) ;
V_84 -> V_52 = ( unsigned char * ) V_259 ;
V_84 -> V_76 = sizeof( struct V_258 ) ;
V_84 -> V_62 = ( T_2 * ) V_142 ;
V_84 -> V_63 = sizeof( struct V_257 ) ;
V_259 -> V_261 = 0x0 ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_89 ( struct V_58 * V_43 , T_2 * V_262 )
{
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_38 * V_84 ;
struct V_263 * V_264 ;
struct V_236 * V_265 = NULL ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_264 = (struct V_263 * ) F_4 ( sizeof( struct V_263 ) ) ;
if ( V_264 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_265 = (struct V_236 * ) F_4 ( sizeof( struct V_266 ) ) ;
if ( V_265 == NULL ) {
F_15 ( V_84 ) ;
F_15 ( V_264 ) ;
return V_13 ;
}
F_49 ( V_84 , V_264 , V_267 ) ;
V_84 -> V_62 = ( T_2 * ) V_265 ;
V_84 -> V_63 = sizeof( struct V_266 ) ;
memcpy ( V_264 -> V_241 , V_262 , V_207 ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_90 ( struct V_58 * V_43 , T_2 V_268 , T_2 * V_241 )
{
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_38 * V_84 ;
struct V_269 * V_270 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_270 = (struct V_269 * ) F_4 ( sizeof( struct V_269 ) ) ;
if ( V_270 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_270 -> V_268 = V_268 ;
memcpy ( V_270 -> V_241 , V_241 , V_207 ) ;
F_49 ( V_84 , V_270 , F_32 ( V_271 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_91 ( struct V_58 * V_43 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_272 ;
V_51 -> V_273 = 0 ;
V_51 -> V_67 = ( T_2 * ) V_43 ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_92 ( struct V_58 * V_43 , T_2 V_92 , T_2 V_274 , T_2 V_275 , T_2 V_221 )
{
struct V_38 * V_276 ;
struct V_277 * V_277 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_43 ( V_278 L_21 ,
F_93 ( V_43 -> V_279 ) , V_92 , V_274 , V_275 ) ;
V_277 = (struct V_277 * ) F_4 ( sizeof( * V_277 ) ) ;
if ( V_277 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_277 -> V_92 = V_92 ;
V_277 -> V_274 = V_274 ;
V_277 -> V_275 = V_275 ;
if ( V_221 ) {
V_276 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_276 == NULL ) {
F_15 ( V_277 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_276 , V_277 , F_32 ( V_280 ) ) ;
V_3 = F_33 ( V_2 , V_276 ) ;
} else {
if ( V_226 != F_94 ( V_43 , ( T_2 * ) V_277 ) )
V_3 = V_13 ;
F_15 ( V_277 ) ;
}
exit:
F_43 ( V_278 L_22 , F_93 ( V_43 -> V_279 ) , V_3 ) ;
V_22 ;
return V_3 ;
}
T_2 F_95 ( struct V_58 * V_43 , T_2 V_281 , T_2 V_221 )
{
struct V_38 * V_276 ;
struct V_282 * V_283 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_192 , ( L_23 ) ) ;
if ( ! F_96 ( V_281 ) ) {
V_3 = V_13 ;
goto exit;
}
V_283 = (struct V_282 * ) F_4 ( sizeof( struct V_282 ) ) ;
if ( V_283 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_283 -> V_284 = V_281 ;
if ( V_221 ) {
V_276 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_276 == NULL ) {
F_15 ( V_283 ) ;
V_3 = V_13 ;
goto exit;
}
F_49 ( V_276 , V_283 , F_32 ( V_55 ) ) ;
V_3 = F_33 ( V_2 , V_276 ) ;
} else {
if ( V_226 != F_97 ( V_43 , ( unsigned char * ) V_283 ) )
V_3 = V_13 ;
F_15 ( V_283 ) ;
}
if ( V_3 == V_4 )
V_43 -> V_98 . V_285 = V_281 ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_98 ( struct V_58 * V_43 , struct V_286 * V_287 )
{
struct V_38 * V_276 ;
struct V_288 * V_289 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_192 , ( L_24 ) ) ;
V_276 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_276 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_289 = (struct V_288 * ) F_4 ( sizeof( struct V_288 ) ) ;
if ( V_289 == NULL ) {
F_15 ( V_276 ) ;
V_3 = V_13 ;
goto exit;
}
V_289 -> V_287 = V_287 ;
F_49 ( V_276 , V_289 , F_32 ( V_290 ) ) ;
V_3 = F_33 ( V_2 , V_276 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_99 ( struct V_58 * V_43 , T_2 V_291 )
{
struct V_38 * V_276 ;
struct V_292 * V_293 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_192 , ( L_25 ) ) ;
V_276 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_276 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_293 = (struct V_292 * ) F_4 ( sizeof( struct V_292 ) ) ;
if ( V_293 == NULL ) {
F_15 ( V_276 ) ;
V_3 = V_13 ;
goto exit;
}
V_293 -> V_291 = V_291 ;
F_49 ( V_276 , V_293 , F_32 ( V_294 ) ) ;
V_3 = F_33 ( V_2 , V_276 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_100 ( struct V_58 * V_43 , T_2 * V_241 , T_2 V_295 )
{
return V_4 ;
}
static void F_101 ( struct V_58 * V_43 )
{
T_2 V_296 ;
T_2 V_297 = false , V_298 = false , V_299 = false ;
T_2 V_300 = false , V_301 = false , V_302 = false ;
struct V_96 * V_97 = & ( V_43 -> V_98 ) ;
if ( F_51 ( V_97 , V_99 ) ) {
if ( V_97 -> V_303 . V_304 > 100 ||
V_97 -> V_303 . V_305 > 100 ) {
V_297 = true ;
if ( V_97 -> V_303 . V_304 > V_97 -> V_303 . V_305 )
V_299 = true ;
else
V_298 = true ;
}
if ( V_97 -> V_303 . V_304 > 4000 ||
V_97 -> V_303 . V_305 > 4000 ) {
V_300 = true ;
if ( V_97 -> V_303 . V_304 > V_97 -> V_303 . V_305 )
V_301 = true ;
else
V_302 = true ;
}
if ( ( ( V_97 -> V_303 . V_306 + V_97 -> V_303 . V_305 ) > 8 ) ||
( V_97 -> V_303 . V_306 > 2 ) )
V_296 = false ;
else
V_296 = true ;
if ( V_296 )
F_102 ( V_43 ) ;
else
F_103 ( V_43 ) ;
} else {
F_103 ( V_43 ) ;
}
V_97 -> V_303 . V_304 = 0 ;
V_97 -> V_303 . V_305 = 0 ;
V_97 -> V_303 . V_306 = 0 ;
V_97 -> V_303 . V_297 = V_297 ;
V_97 -> V_303 . V_298 = V_298 ;
V_97 -> V_303 . V_299 = V_299 ;
V_97 -> V_303 . V_300 = V_300 ;
V_97 -> V_303 . V_301 = V_301 ;
V_97 -> V_303 . V_302 = V_302 ;
}
static void F_104 ( struct V_58 * V_43 , T_2 * V_67 , int V_165 )
{
struct V_96 * V_97 ;
V_43 = (struct V_58 * ) V_67 ;
V_97 = & ( V_43 -> V_98 ) ;
#ifdef F_105
if ( F_51 ( V_97 , V_307 ) == true )
F_106 ( V_43 ) ;
#endif
F_107 ( V_43 ) ;
F_108 ( V_43 ) ;
F_101 ( V_43 ) ;
F_109 ( V_43 ) ;
}
static void F_110 ( struct V_58 * V_43 , T_2 V_308 )
{
struct V_309 * V_310 = & V_43 -> V_44 ;
struct V_96 * V_97 = & ( V_43 -> V_98 ) ;
T_2 V_311 ;
V_5 ;
if ( ( F_51 ( V_97 , V_312 ) == true ) ||
( F_51 ( V_97 , V_194 ) == true ) )
return;
switch ( V_308 ) {
case V_100 :
if ( F_51 ( V_97 , V_99 ) == true ) {
F_103 ( V_43 ) ;
}
break;
case V_313 :
F_103 ( V_43 ) ;
break;
case V_314 :
V_311 = 1 ;
V_43 -> V_44 . V_315 = 0 ;
F_111 ( V_43 , V_316 , ( T_2 * ) ( & V_311 ) ) ;
break;
case V_317 :
V_311 = 0 ;
F_103 ( V_43 ) ;
F_111 ( V_43 , V_316 , ( T_2 * ) ( & V_311 ) ) ;
break;
case V_318 :
V_310 -> V_319 = F_57 () ;
F_103 ( V_43 ) ;
break;
case V_320 :
F_103 ( V_43 ) ;
break;
default:
break;
}
V_22 ;
}
T_2 F_52 ( struct V_58 * V_43 , T_2 V_308 , T_2 V_221 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
if ( V_221 ) {
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_321 ;
V_51 -> V_273 = V_308 ;
V_51 -> V_67 = NULL ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
} else {
F_110 ( V_43 , V_308 ) ;
}
exit:
V_22 ;
return V_3 ;
}
static void F_112 ( struct V_58 * V_43 , T_4 V_322 )
{
F_111 ( V_43 , V_323 , ( T_2 * ) ( & V_322 ) ) ;
}
T_2 F_113 ( struct V_58 * V_43 , T_4 V_322 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_324 ;
V_51 -> V_273 = V_322 ;
V_51 -> V_67 = NULL ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
static void F_114 ( struct V_58 * V_43 , T_2 V_325 )
{
F_111 ( V_43 , V_326 , ( T_2 * ) ( & V_325 ) ) ;
}
T_2 F_115 ( struct V_58 * V_43 , T_2 V_325 , T_2 V_221 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_327 ;
T_2 V_3 = V_4 ;
V_5 ;
F_116 ( V_43 , V_328 , & V_327 ) ;
if ( ! V_327 )
return V_3 ;
if ( V_221 ) {
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_329 ;
V_51 -> V_273 = V_325 ;
V_51 -> V_67 = NULL ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
} else {
F_114 ( V_43 , V_325 ) ;
}
exit:
V_22 ;
return V_3 ;
}
static void F_117 ( struct V_58 * V_43 , T_2 * V_67 , int V_165 )
{
F_118 ( V_43 ) ;
}
T_2 F_119 ( struct V_58 * V_43 , int V_330 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_331 * V_332 = & ( V_43 -> V_333 ) ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
if ( F_120 ( V_332 , V_334 ) )
return V_3 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_335 ;
V_51 -> V_273 = V_330 ;
V_51 -> V_67 = NULL ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_121 ( struct V_58 * V_43 )
{
struct V_38 * V_336 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_336 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_336 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_336 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_54 ;
V_51 -> V_67 = NULL ;
F_49 ( V_336 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_336 ) ;
exit:
V_22 ;
return V_3 ;
}
static void F_122 ( struct V_58 * V_43 )
{
int V_337 = 0 ;
struct V_238 * V_338 ;
struct V_339 * V_340 = & V_43 -> V_341 ;
V_338 = F_123 ( V_43 ) ;
if ( ! V_338 )
return;
if ( V_338 -> V_342 == 0 ) {
T_2 V_137 = 0 ;
F_124 ( V_43 , V_343 , & V_137 ) ;
while ( ! V_137 ) {
F_12 ( 100 ) ;
V_337 ++ ;
if ( V_337 > 10 )
break;
F_124 ( V_43 , V_343 , & V_137 ) ;
}
if ( V_337 <= 10 ) {
V_340 -> V_344 &= ~ F_125 ( 0 ) ;
V_340 -> V_345 &= ~ F_125 ( 0 ) ;
F_126 ( V_43 , V_346 , NULL , false ) ;
} else {
F_127 ( V_43 ) ;
}
}
}
T_2 F_127 ( struct V_58 * V_43 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_347 ;
V_51 -> V_273 = 0 ;
V_51 -> V_67 = NULL ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
return V_3 ;
}
T_2 F_128 ( struct V_58 * V_43 , T_2 * V_348 )
{
struct V_38 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_84 = (struct V_38 * ) F_4 ( sizeof( struct V_38 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_349 ;
V_51 -> V_273 = V_348 ? 16 : 0 ;
V_51 -> V_67 = V_348 ;
F_49 ( V_84 , V_51 , F_32 ( V_49 ) ) ;
V_3 = F_33 ( V_2 , V_84 ) ;
exit:
return V_3 ;
}
static T_5 F_129 ( struct V_58 * V_58 , struct V_350 * V_348 , T_6 V_351 )
{
T_5 V_65 = V_13 ;
T_2 V_352 [ 16 ] ;
if ( ! V_348 ) {
if ( F_130 ( V_58 , V_352 ) == V_4 ) {
V_348 = (struct V_350 * ) V_352 ;
if ( V_351 && V_351 ( V_348 -> V_252 ) == false )
goto exit;
V_65 = F_131 ( V_58 , V_348 ) ;
}
} else {
if ( V_351 && V_351 ( V_348 -> V_252 ) == false )
goto exit;
V_65 = F_131 ( V_58 , V_348 ) ;
}
exit:
return V_65 ;
}
static void V_28 ( struct V_353 * V_354 )
{
struct V_23 * V_355 = F_132 ( V_354 , struct V_23 , V_27 ) ;
struct V_58 * V_58 = F_132 ( V_355 , struct V_58 , V_355 ) ;
struct V_350 * V_348 ;
T_6 V_356 = F_133 ( V_58 ) ;
V_355 -> V_29 = true ;
while ( ! F_13 ( V_355 -> V_30 ) ) {
if ( ( V_348 = (struct V_350 * ) F_14 ( V_355 -> V_30 ) ) != NULL ) {
F_134 ( V_58 ) ;
} else if ( ( V_348 = (struct V_350 * ) F_135 ( 16 ) ) != NULL ) {
if ( F_130 ( V_58 , ( T_2 * ) V_348 ) != V_4 )
continue;
}
if ( ( void * ) V_348 == ( void * ) V_355 )
continue;
if ( ! F_136 ( V_348 ) ) {
F_15 ( V_348 ) ;
continue;
}
if ( V_356 ( V_348 -> V_252 ) == true ) {
F_131 ( V_58 , V_348 ) ;
F_15 ( V_348 ) ;
} else {
#ifdef F_137
F_128 ( V_58 , ( T_2 * ) V_348 ) ;
#endif
}
}
V_355 -> V_29 = false ;
}
T_2 F_138 ( struct V_58 * V_43 , unsigned char * V_67 )
{
struct V_50 * V_357 ;
if ( ! V_67 )
return V_79 ;
V_357 = (struct V_50 * ) V_67 ;
switch ( V_357 -> V_53 ) {
case V_272 :
F_104 ( V_43 , V_357 -> V_67 , V_357 -> V_273 ) ;
break;
case V_54 :
F_117 ( V_43 , V_357 -> V_67 , V_357 -> V_273 ) ;
break;
case V_321 :
F_110 ( V_43 , ( T_2 ) V_357 -> V_273 ) ;
break;
case V_324 :
F_112 ( V_43 , V_357 -> V_273 ) ;
break;
case V_329 :
F_114 ( V_43 , V_357 -> V_273 ) ;
break;
#ifdef F_137
case V_358 :
F_139 ( V_43 , V_357 -> V_273 ) ;
break;
case V_335 :
F_140 ( V_43 , V_357 -> V_273 ) ;
break;
#endif
#ifdef F_105
case V_347 :
F_122 ( V_43 ) ;
break;
#endif
case V_349 :
F_129 ( V_43 , (struct V_350 * ) V_357 -> V_67 , NULL ) ;
break;
default:
break;
}
if ( V_357 -> V_67 && V_357 -> V_273 > 0 )
F_15 ( V_357 -> V_67 ) ;
return V_226 ;
}
void F_141 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( V_59 -> V_3 == V_74 ) {
F_58 ( & V_97 -> V_115 , 1 ) ;
} else if ( V_59 -> V_3 != V_226 ) {
F_58 ( & V_97 -> V_115 , 1 ) ;
F_10 ( V_32 , V_82 , ( L_26 ) ) ;
}
F_34 ( V_59 ) ;
V_22 ;
}
void F_142 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
unsigned long V_40 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( V_59 -> V_3 != V_226 ) {
F_143 ( & V_97 -> V_35 , & V_40 ) ;
F_56 ( V_97 , V_99 ) ;
F_144 ( & V_97 -> V_35 , & V_40 ) ;
F_10 ( V_32 , V_82 , ( L_27 ) ) ;
goto exit;
} else
F_145 ( V_43 ) ;
F_34 ( V_59 ) ;
exit:
V_22 ;
}
void F_146 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( V_59 -> V_3 == V_74 ) {
F_58 ( & V_97 -> V_359 , 1 ) ;
} else if ( V_59 -> V_3 != V_226 ) {
F_10 ( V_32 , V_82 , ( L_28 ) ) ;
F_58 ( & V_97 -> V_359 , 1 ) ;
}
F_34 ( V_59 ) ;
V_22 ;
}
void F_147 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
unsigned long V_40 ;
T_2 V_360 ;
struct V_238 * V_232 = NULL ;
struct V_167 * V_361 = NULL ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_158 * V_168 = (struct V_158 * ) V_59 -> V_52 ;
struct V_167 * V_362 = & ( V_97 -> V_363 ) ;
V_5 ;
if ( ( V_59 -> V_3 != V_226 ) ) {
F_10 ( V_32 , V_82 , ( L_29 ) ) ;
F_58 ( & V_97 -> V_359 , 1 ) ;
}
F_148 ( & V_97 -> V_359 , & V_360 ) ;
F_143 ( & V_97 -> V_35 , & V_40 ) ;
if ( F_51 ( V_97 , V_307 ) ) {
V_232 = F_149 ( & V_43 -> V_341 , V_168 -> V_206 ) ;
if ( ! V_232 ) {
V_232 = F_150 ( & V_43 -> V_341 , V_168 -> V_206 ) ;
if ( V_232 == NULL ) {
F_10 ( V_32 , V_82 , ( L_30 ) ) ;
goto V_364 ;
}
}
F_151 ( V_43 ) ;
} else {
unsigned long V_40 ;
V_361 = F_152 ( V_97 ) ;
F_143 ( & ( V_97 -> V_365 . V_35 ) , & V_40 ) ;
if ( V_361 == NULL ) {
V_361 = F_153 ( & V_97 -> V_365 ) ;
if ( V_361 == NULL ) {
F_10 ( V_32 , V_82 , ( L_31 ) ) ;
F_144 ( & ( V_97 -> V_365 . V_35 ) , & V_40 ) ;
goto V_364;
}
V_361 -> V_366 = F_57 () ;
} else {
F_21 ( & ( V_361 -> V_41 ) , & V_97 -> V_365 . V_37 ) ;
}
V_168 -> V_163 = F_72 ( V_168 ) ;
memcpy ( & ( V_361 -> V_184 ) , V_168 , V_168 -> V_163 ) ;
memcpy ( & V_362 -> V_184 , V_168 , ( F_72 ( V_168 ) ) ) ;
F_60 ( V_97 , V_367 ) ;
F_144 ( & ( V_97 -> V_365 . V_35 ) , & V_40 ) ;
}
V_364:
F_144 ( & V_97 -> V_35 , & V_40 ) ;
F_34 ( V_59 ) ;
V_22 ;
}
void F_154 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
struct V_339 * V_340 = & V_43 -> V_341 ;
struct V_236 * V_237 = (struct V_236 * ) ( V_59 -> V_62 ) ;
struct V_238 * V_232 = F_149 ( V_340 , V_237 -> V_241 ) ;
V_5 ;
if ( V_232 == NULL ) {
F_10 ( V_32 , V_82 , ( L_32 ) ) ;
goto exit;
}
exit:
F_34 ( V_59 ) ;
V_22 ;
}
void F_155 ( struct V_58 * V_43 , struct V_38 * V_59 )
{
unsigned long V_40 ;
struct V_339 * V_340 = & V_43 -> V_341 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_263 * V_368 = (struct V_263 * ) ( V_59 -> V_52 ) ;
struct V_266 * V_369 = (struct V_266 * ) ( V_59 -> V_62 ) ;
struct V_238 * V_232 = F_149 ( V_340 , V_368 -> V_241 ) ;
V_5 ;
if ( V_232 == NULL ) {
F_10 ( V_32 , V_82 , ( L_33 ) ) ;
goto exit;
}
V_232 -> V_370 = V_369 -> V_371 ;
V_232 -> V_124 = V_369 -> V_371 ;
F_143 ( & V_97 -> V_35 , & V_40 ) ;
if ( ( F_51 ( V_97 , V_372 ) == true ) && ( F_51 ( V_97 , V_367 ) == true ) )
F_60 ( V_97 , V_367 ) ;
F_56 ( V_97 , V_99 ) ;
F_144 ( & V_97 -> V_35 , & V_40 ) ;
exit:
F_34 ( V_59 ) ;
V_22 ;
}
