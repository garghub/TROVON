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
if ( V_2 -> V_10 )
F_15 ( V_2 -> V_10 ) ;
if ( V_2 -> V_16 )
F_15 ( V_2 -> V_16 ) ;
}
V_22 ;
}
int F_17 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
unsigned long V_39 ;
V_5 ;
if ( V_38 == NULL )
goto exit;
F_18 ( & V_36 -> V_40 , V_39 ) ;
F_19 ( & V_38 -> V_41 , & V_36 -> V_36 ) ;
F_20 ( & V_36 -> V_40 , V_39 ) ;
exit:
V_22 ;
return V_4 ;
}
struct V_37 * F_21 ( struct V_35 * V_36 )
{
unsigned long V_39 ;
struct V_37 * V_38 ;
V_5 ;
F_18 ( & V_36 -> V_40 , V_39 ) ;
if ( F_22 ( & ( V_36 -> V_36 ) ) ) {
V_38 = NULL ;
} else {
V_38 = F_23 ( F_24 ( & ( V_36 -> V_36 ) ) , struct V_37 , V_41 ) ;
F_25 ( & V_38 -> V_41 ) ;
}
F_20 ( & V_36 -> V_40 , V_39 ) ;
V_22 ;
return V_38 ;
}
T_1 F_26 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_5 ;
V_3 = F_1 ( V_2 ) ;
V_22 ;
return V_3 ;
}
T_1 F_27 ( struct V_23 * V_24 )
{
int V_3 ;
V_5 ;
V_3 = F_5 ( V_24 ) ;
V_22 ;
return V_3 ;
}
void F_28 ( struct V_1 * V_2 )
{
V_5 ;
F_10 ( V_32 , V_33 , ( L_3 ) ) ;
F_16 ( V_2 ) ;
V_22 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
T_2 V_42 = false ;
if ( ( V_2 -> V_43 -> V_44 . V_45 ) &&
( ! V_2 -> V_43 -> V_46 . V_47 ) ) {
if ( V_37 -> V_48 == F_30 ( V_49 ) ) {
struct V_50 * V_51 = (struct V_50 * ) V_37 -> V_52 ;
if ( V_51 -> V_53 == V_54 )
V_42 = true ;
}
}
if ( V_37 -> V_48 == F_30 ( V_55 ) )
V_42 = true ;
if ( ( ! V_2 -> V_43 -> V_56 && ! V_42 ) ||
! V_2 -> V_57 )
return V_13 ;
return V_4 ;
}
T_1 F_31 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
int V_3 = V_13 ;
struct V_58 * V_43 = V_2 -> V_43 ;
V_5 ;
if ( V_37 == NULL )
goto exit;
V_37 -> V_43 = V_43 ;
V_3 = F_29 ( V_2 , V_37 ) ;
if ( V_13 == V_3 ) {
F_32 ( V_37 ) ;
goto exit;
}
V_3 = F_17 ( & V_2 -> V_8 , V_37 ) ;
if ( V_3 == V_4 )
F_33 ( & V_2 -> V_6 ) ;
exit:
V_22 ;
return V_3 ;
}
struct V_37 * F_34 ( struct V_1 * V_2 )
{
struct V_37 * V_37 ;
V_5 ;
V_37 = F_21 ( & V_2 -> V_8 ) ;
V_22 ;
return V_37 ;
}
void F_35 ( struct V_1 * V_2 )
{
V_5 ;
V_2 -> V_20 ++ ;
V_22 ;
}
void F_32 ( struct V_37 * V_59 )
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
int F_36 ( void * V_64 )
{
T_2 V_65 ;
struct V_37 * V_59 ;
T_2 * V_66 ;
T_2 (* F_37)( struct V_58 * V_43 , T_2 * V_67 );
void (* F_38)( struct V_58 * V_68 , struct V_37 * V_59 );
struct V_58 * V_43 = (struct V_58 * ) V_64 ;
struct V_1 * V_2 = & ( V_43 -> V_69 ) ;
V_5 ;
F_39 ( L_4 ) ;
V_66 = V_2 -> V_14 ;
V_2 -> V_57 = true ;
F_33 ( & V_2 -> V_7 ) ;
F_10 ( V_32 , V_33 , ( L_5 ) ) ;
while ( 1 ) {
if ( F_40 ( & V_2 -> V_6 ) == V_13 )
break;
if ( V_43 -> V_70 ||
V_43 -> V_71 ) {
F_41 ( L_6 ,
V_72 , V_43 -> V_70 , V_43 -> V_71 , __LINE__ ) ;
break;
}
V_73:
if ( V_43 -> V_70 ||
V_43 -> V_71 ) {
F_41 ( L_6 ,
V_72 , V_43 -> V_70 , V_43 -> V_71 , __LINE__ ) ;
break;
}
V_59 = F_34 ( V_2 ) ;
if ( ! V_59 )
continue;
if ( V_13 == F_29 ( V_2 , V_59 ) ) {
V_59 -> V_3 = V_74 ;
goto V_75;
}
V_2 -> V_19 ++ ;
V_59 -> V_76 = F_42 ( ( V_59 -> V_76 ) ) ;
memcpy ( V_66 , V_59 -> V_52 , V_59 -> V_76 ) ;
if ( V_59 -> V_48 < F_43 ( V_77 ) ) {
F_37 = V_77 [ V_59 -> V_48 ] . V_78 ;
if ( F_37 ) {
V_65 = F_37 ( V_59 -> V_43 , V_66 ) ;
V_59 -> V_3 = V_65 ;
}
V_2 -> V_9 ++ ;
} else {
V_59 -> V_3 = V_79 ;
}
F_37 = NULL ;
V_75:
if ( V_59 -> V_48 < F_43 ( V_80 ) ) {
F_38 = V_80 [ V_59 -> V_48 ] . V_81 ;
if ( F_38 == NULL ) {
F_10 ( V_32 , V_33 , ( L_7 , F_38 , V_59 -> V_48 ) ) ;
F_32 ( V_59 ) ;
} else {
F_38 ( V_59 -> V_43 , V_59 ) ;
}
} else {
F_10 ( V_32 , V_82 , ( L_8 , V_72 , V_59 -> V_48 ) ) ;
F_32 ( V_59 ) ;
}
F_44 () ;
goto V_73;
}
V_2 -> V_57 = false ;
do {
V_59 = F_34 ( V_2 ) ;
if ( V_59 == NULL )
break;
F_32 ( V_59 ) ;
} while ( 1 );
F_33 ( & V_2 -> V_7 ) ;
V_22 ;
F_45 ( NULL , 0 ) ;
}
T_2 F_46 ( struct V_58 * V_43 , T_3 V_83 )
{
struct V_37 * V_84 ;
struct V_85 * V_86 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_65 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
F_47 ( V_84 , V_86 , F_30 ( V_87 ) ) ;
V_65 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_65 ;
}
T_2 F_48 ( struct V_58 * V_43 , struct V_88 * V_89 , int V_90 ,
struct V_91 * V_92 , int V_93 )
{
T_2 V_3 = V_13 ;
struct V_37 * V_84 ;
struct V_94 * V_95 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( F_49 ( V_97 , V_99 ) == true ) {
F_50 ( V_43 , V_100 , 1 ) ;
}
if ( F_49 ( V_97 , V_99 ) == true ) {
F_51 ( V_43 , V_101 , 1 ) ;
}
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL )
return V_13 ;
V_95 = (struct V_94 * ) F_4 ( sizeof( struct V_94 ) ) ;
if ( V_95 == NULL ) {
F_15 ( V_84 ) ;
return V_13 ;
}
F_52 ( V_43 , false ) ;
F_10 ( V_32 , V_33 , ( L_9 , V_72 ) ) ;
F_47 ( V_84 , V_95 , F_30 ( V_102 ) ) ;
V_95 -> V_103 = V_97 -> V_103 ;
if ( V_89 ) {
int V_104 ;
for ( V_104 = 0 ; V_104 < V_90 && V_104 < V_105 ; V_104 ++ ) {
if ( V_89 [ V_104 ] . V_106 ) {
memcpy ( & V_95 -> V_89 [ V_104 ] , & V_89 [ V_104 ] , sizeof( struct V_88 ) ) ;
V_95 -> V_90 ++ ;
if ( 0 )
F_41 ( V_107 L_10 , F_53 ( V_43 ) ,
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
F_41 ( V_107 L_11 , F_53 ( V_43 ) ,
V_95 -> V_92 [ V_104 ] . V_110 ) ;
}
}
}
F_54 ( V_97 , V_113 ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
if ( V_3 == V_4 ) {
V_97 -> V_114 = V_115 ;
F_55 ( & V_97 -> V_116 , V_117 ) ;
F_56 ( V_43 , V_118 ) ;
V_97 -> V_119 = V_120 ;
} else {
F_57 ( V_97 , V_113 ) ;
}
V_22 ;
return V_3 ;
}
T_2 F_58 ( struct V_58 * V_43 , T_2 * V_121 )
{
struct V_37 * V_84 ;
struct V_122 * V_123 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_123 = (struct V_122 * ) F_4 ( sizeof( struct V_122 ) ) ;
if ( V_123 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_123 , F_30 ( V_124 ) ) ;
V_123 -> V_125 = 5 ;
memcpy ( V_123 -> V_126 , V_121 , V_127 ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_59 ( struct V_58 * V_43 , T_2 * V_121 )
{
struct V_37 * V_84 ;
struct V_128 * V_129 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_129 = (struct V_128 * ) F_4 ( sizeof( struct V_128 ) ) ;
if ( V_129 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_129 , V_130 ) ;
memcpy ( V_129 -> V_131 , V_121 , V_127 ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_60 ( struct V_58 * V_43 , T_2 V_132 , T_2 V_92 )
{
struct V_37 * V_84 ;
struct V_133 * V_134 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_134 = (struct V_133 * ) F_4 ( sizeof( struct V_133 ) ) ;
if ( V_134 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_134 , V_135 ) ;
F_10 ( V_32 , V_33 , ( L_12 , V_92 , V_132 ) ) ;
V_134 -> V_132 = V_132 ;
V_134 -> V_136 = V_92 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_61 ( struct V_58 * V_43 , T_2 V_137 , T_2 V_138 )
{
struct V_37 * V_84 ;
struct V_139 * V_140 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_140 = (struct V_139 * ) F_4 ( sizeof( struct V_139 ) ) ;
if ( V_140 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_140 , F_30 ( V_141 ) ) ;
V_140 -> V_137 = V_137 ;
V_140 -> V_142 = V_138 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_62 ( struct V_58 * V_43 , T_2 V_137 , T_2 * V_143 )
{
struct V_37 * V_84 ;
struct V_144 * V_145 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_145 = (struct V_144 * ) F_4 ( sizeof( struct V_144 ) ) ;
if ( V_145 == NULL ) {
F_15 ( V_84 ) ;
return V_13 ;
}
F_63 ( & V_84 -> V_41 ) ;
V_84 -> V_48 = F_30 ( V_146 ) ;
V_84 -> V_52 = ( unsigned char * ) V_145 ;
V_84 -> V_76 = sizeof( struct V_144 ) ;
V_84 -> V_62 = V_143 ;
V_84 -> V_63 = sizeof( struct V_147 ) ;
V_145 -> V_137 = V_137 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_64 ( struct V_58 * V_43 , T_2 V_137 , T_1 V_138 )
{
struct V_37 * V_84 ;
struct V_148 * V_149 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_149 = (struct V_148 * ) F_4 ( sizeof( struct V_148 ) ) ;
if ( V_149 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_149 , F_30 ( V_150 ) ) ;
V_149 -> V_137 = V_137 ;
V_149 -> V_142 = V_138 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_65 ( struct V_58 * V_43 , T_2 V_137 , T_2 * V_143 )
{
struct V_37 * V_84 ;
struct V_151 * V_152 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_152 = (struct V_151 * ) F_4 ( sizeof( struct V_151 ) ) ;
if ( V_152 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_63 ( & V_84 -> V_41 ) ;
V_84 -> V_48 = F_30 ( V_153 ) ;
V_84 -> V_52 = ( unsigned char * ) V_152 ;
V_84 -> V_76 = sizeof( struct V_151 ) ;
V_84 -> V_62 = V_143 ;
V_84 -> V_63 = sizeof( struct V_154 ) ;
V_152 -> V_137 = V_137 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
void F_66 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
V_5 ;
F_15 ( V_59 -> V_52 ) ;
F_15 ( V_59 ) ;
if ( V_43 -> V_46 . V_155 == 1 )
V_43 -> V_156 . V_157 . V_158 = true ;
V_22 ;
}
void F_67 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
V_5 ;
F_15 ( V_59 -> V_52 ) ;
F_15 ( V_59 ) ;
if ( V_43 -> V_46 . V_155 == 1 )
V_43 -> V_156 . V_157 . V_158 = true ;
V_22 ;
}
T_2 F_68 ( struct V_58 * V_43 )
{
struct V_37 * V_59 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_159 * V_160 = & V_43 -> V_46 . V_161 ;
T_2 V_3 = V_4 ;
V_5 ;
F_56 ( V_43 , V_162 ) ;
if ( V_97 -> V_163 . V_106 == 0 )
F_10 ( V_32 , V_33 , ( L_13 , V_97 -> V_163 . V_108 ) ) ;
else
F_10 ( V_32 , V_33 , ( L_14 , V_97 -> V_163 . V_108 ) ) ;
V_59 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_59 == NULL ) {
V_3 = V_13 ;
goto exit;
}
F_63 ( & V_59 -> V_41 ) ;
V_59 -> V_48 = V_61 ;
V_59 -> V_52 = ( unsigned char * ) V_160 ;
V_59 -> V_76 = F_69 ( (struct V_159 * ) V_160 ) ;
V_59 -> V_62 = NULL ;
V_59 -> V_63 = 0 ;
V_160 -> V_164 = V_59 -> V_76 ;
V_3 = F_31 ( V_2 , V_59 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_70 ( struct V_58 * V_43 , unsigned char * V_165 , unsigned int V_166 )
{
struct V_37 * V_59 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_59 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_59 == NULL ) {
V_3 = V_13 ;
goto exit;
}
F_63 ( & V_59 -> V_41 ) ;
V_59 -> V_48 = F_30 ( V_167 ) ;
V_59 -> V_52 = V_165 ;
V_59 -> V_76 = V_166 ;
V_59 -> V_62 = NULL ;
V_59 -> V_63 = 0 ;
V_3 = F_31 ( V_2 , V_59 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_71 ( struct V_58 * V_43 , struct V_168 * V_169 )
{
T_2 V_3 = V_4 ;
T_3 V_170 = 0 ;
struct V_159 * V_171 ;
struct V_37 * V_59 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_172 * V_173 = & V_97 -> V_174 ;
struct V_175 * V_176 = & V_43 -> V_177 ;
struct V_178 * V_179 = & V_43 -> V_46 ;
struct V_180 * V_181 = & V_97 -> V_182 ;
enum V_183 V_184 = V_169 -> V_185 . V_186 ;
struct V_187 * V_188 = & V_43 -> V_189 ;
struct V_190 * V_191 = & ( V_188 -> V_192 ) ;
V_5 ;
F_56 ( V_43 , V_162 ) ;
if ( V_97 -> V_163 . V_106 == 0 ) {
F_10 ( V_32 , V_33 , ( L_15 ) ) ;
} else {
F_10 ( V_32 , V_193 , ( L_16 , V_97 -> V_163 . V_108 ) ) ;
}
V_59 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_59 == NULL ) {
V_3 = V_13 ;
F_10 ( V_32 , V_82 , ( L_17 ) ) ;
goto exit;
}
V_170 = sizeof( struct V_159 ) ;
if ( ! F_49 ( V_97 , V_194 | V_195 ) ) {
switch ( V_184 ) {
case V_196 :
F_54 ( V_97 , V_195 ) ;
break;
case V_197 :
F_54 ( V_97 , V_194 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
break;
}
}
V_171 = (struct V_159 * ) & V_176 -> V_201 ;
if ( V_171 == NULL ) {
if ( V_59 != NULL )
F_15 ( V_59 ) ;
V_3 = V_13 ;
F_10 ( V_32 , V_82 , ( L_18 ) ) ;
goto exit;
}
F_72 ( V_171 , 0 , V_170 ) ;
memcpy ( V_171 , & V_169 -> V_185 , F_69 ( & V_169 -> V_185 ) ) ;
V_176 -> V_202 [ 0 ] = ( unsigned char ) V_171 -> V_203 ;
if ( ( V_171 -> V_203 - 12 ) < ( 256 - 1 ) ) {
memcpy ( & V_176 -> V_202 [ 1 ] , & V_171 -> V_204 [ 12 ] , V_171 -> V_203 - 12 ) ;
} else {
memcpy ( & V_176 -> V_202 [ 1 ] , & V_171 -> V_204 [ 12 ] , ( 256 - 1 ) ) ;
}
V_171 -> V_203 = 0 ;
if ( ! V_97 -> V_205 )
memcpy ( & V_97 -> V_206 [ 0 ] , & V_169 -> V_185 . V_207 [ 0 ] , V_208 ) ;
V_171 -> V_203 = F_73 ( V_43 , & V_169 -> V_185 . V_204 [ 0 ] , & V_171 -> V_204 [ 0 ] , V_169 -> V_185 . V_203 ) ;
V_173 -> V_209 = 0 ;
if ( V_179 -> V_210 ) {
T_1 V_211 ;
V_211 = F_74 ( V_43 , & V_169 -> V_185 . V_204 [ 0 ] , & V_171 -> V_204 [ 0 ] , V_169 -> V_185 . V_203 , V_171 -> V_203 ) ;
if ( V_171 -> V_203 != V_211 ) {
V_171 -> V_203 = V_211 ;
V_173 -> V_209 = 1 ;
} else {
V_173 -> V_209 = 0 ;
}
}
V_181 -> V_212 = false ;
if ( V_179 -> V_213 ) {
if ( ( V_43 -> V_177 . V_214 != V_215 ) &&
( V_43 -> V_177 . V_214 != V_216 ) &&
( V_43 -> V_177 . V_214 != V_217 ) ) {
F_75 ( V_43 , & V_169 -> V_185 . V_204 [ 0 ] , & V_171 -> V_204 [ 0 ] ,
V_169 -> V_185 . V_203 , & V_171 -> V_203 ) ;
}
}
V_191 -> V_218 = F_76 ( V_169 -> V_185 . V_204 , V_169 -> V_185 . V_203 ) ;
if ( V_191 -> V_218 == V_219 )
V_43 -> V_44 . V_220 = 0 ;
else
V_43 -> V_44 . V_220 = V_43 -> V_46 . V_220 ;
F_41 ( L_19 , V_72 , V_43 -> V_44 . V_220 ) ;
V_59 -> V_76 = F_69 ( V_171 ) ;
F_63 ( & V_59 -> V_41 ) ;
V_59 -> V_48 = V_60 ;
V_59 -> V_52 = ( unsigned char * ) V_171 ;
V_59 -> V_62 = NULL ;
V_59 -> V_63 = 0 ;
V_3 = F_31 ( V_2 , V_59 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_77 ( struct V_58 * V_43 , T_1 V_221 , bool V_222 )
{
struct V_37 * V_223 = NULL ;
struct V_224 * V_225 = NULL ;
struct V_1 * V_69 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_193 , ( L_20 ) ) ;
V_225 = (struct V_224 * ) F_4 ( sizeof( * V_225 ) ) ;
if ( V_225 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_225 -> V_221 = V_221 ;
if ( V_222 ) {
V_223 = (struct V_37 * ) F_4 ( sizeof( * V_223 ) ) ;
if ( V_223 == NULL ) {
V_3 = V_13 ;
F_15 ( V_225 ) ;
goto exit;
}
F_47 ( V_223 , V_225 , V_226 ) ;
V_3 = F_31 ( V_69 , V_223 ) ;
} else {
if ( V_227 != F_78 ( V_43 , ( T_2 * ) V_225 ) )
V_3 = V_13 ;
F_15 ( V_225 ) ;
}
exit:
V_22 ;
return V_3 ;
}
T_2 F_79 ( struct V_58 * V_43 , enum V_183 V_228 )
{
struct V_37 * V_84 ;
struct V_229 * V_230 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = false ;
goto exit;
}
V_230 = (struct V_229 * ) F_4 ( sizeof( struct V_229 ) ) ;
if ( V_230 == NULL ) {
F_15 ( V_84 ) ;
V_3 = false ;
goto exit;
}
F_47 ( V_84 , V_230 , V_231 ) ;
V_230 -> V_232 = ( T_2 ) V_228 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_80 ( struct V_58 * V_43 , T_2 * V_233 , T_2 V_234 )
{
struct V_37 * V_84 ;
struct V_235 * V_236 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_237 * V_238 = NULL ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_175 * V_176 = & V_43 -> V_177 ;
struct V_239 * V_240 = (struct V_239 * ) V_233 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_236 = (struct V_235 * ) F_4 ( sizeof( struct V_235 ) ) ;
if ( V_236 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_238 = (struct V_237 * ) F_4 ( sizeof( struct V_237 ) ) ;
if ( V_238 == NULL ) {
F_15 ( V_84 ) ;
F_15 ( V_236 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_236 , V_241 ) ;
V_84 -> V_62 = ( T_2 * ) V_238 ;
V_84 -> V_63 = sizeof( struct V_237 ) ;
memcpy ( V_236 -> V_242 , V_240 -> V_243 , V_208 ) ;
if ( F_49 ( V_97 , V_194 ) )
V_236 -> V_244 = ( unsigned char ) V_176 -> V_214 ;
else
F_81 ( V_176 , V_240 , V_236 -> V_244 , false ) ;
if ( V_234 )
memcpy ( & V_236 -> V_245 , & V_240 -> V_246 , 16 ) ;
else
memcpy ( & V_236 -> V_245 , & V_176 -> V_247 [ V_176 -> V_248 ] . V_249 , 16 ) ;
V_43 -> V_177 . V_250 = true ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_82 ( struct V_58 * V_43 , T_2 * V_233 , T_2 V_251 , T_2 V_222 )
{
struct V_37 * V_84 ;
struct V_235 * V_236 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_237 * V_238 = NULL ;
struct V_239 * V_240 = (struct V_239 * ) V_233 ;
T_2 V_3 = V_4 ;
V_5 ;
if ( ! V_222 ) {
F_83 ( V_43 , V_251 ) ;
} else {
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_236 = (struct V_235 * ) F_4 ( sizeof( struct V_235 ) ) ;
if ( V_236 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_238 = (struct V_237 * ) F_4 ( sizeof( struct V_237 ) ) ;
if ( V_238 == NULL ) {
F_15 ( V_84 ) ;
F_15 ( V_236 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_236 , V_241 ) ;
V_84 -> V_62 = ( T_2 * ) V_238 ;
V_84 -> V_63 = sizeof( struct V_237 ) ;
memcpy ( V_236 -> V_242 , V_240 -> V_243 , V_208 ) ;
V_236 -> V_244 = V_252 ;
V_236 -> V_253 = V_251 ;
V_3 = F_31 ( V_2 , V_84 ) ;
}
exit:
V_22 ;
return V_3 ;
}
T_2 F_84 ( struct V_58 * V_43 , struct V_254 * V_255 )
{
struct V_37 * V_84 ;
struct V_254 * V_256 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_256 = (struct V_254 * ) F_4 ( sizeof( struct V_254 ) ) ;
if ( V_256 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_84 , V_256 , F_30 ( V_257 ) ) ;
memcpy ( V_256 , V_255 , sizeof( struct V_254 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_85 ( struct V_58 * V_43 , struct V_258 * V_143 )
{
struct V_37 * V_84 ;
struct V_259 * V_260 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_260 = (struct V_259 * ) F_4 ( sizeof( struct V_259 ) ) ;
if ( V_260 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
F_63 ( & V_84 -> V_41 ) ;
V_84 -> V_48 = F_30 ( V_261 ) ;
V_84 -> V_52 = ( unsigned char * ) V_260 ;
V_84 -> V_76 = sizeof( struct V_259 ) ;
V_84 -> V_62 = ( T_2 * ) V_143 ;
V_84 -> V_63 = sizeof( struct V_258 ) ;
V_260 -> V_262 = 0x0 ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_86 ( struct V_58 * V_43 , T_2 * V_263 )
{
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_37 * V_84 ;
struct V_264 * V_265 ;
struct V_237 * V_266 = NULL ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_265 = (struct V_264 * ) F_4 ( sizeof( struct V_264 ) ) ;
if ( V_265 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_266 = (struct V_237 * ) F_4 ( sizeof( struct V_267 ) ) ;
if ( V_266 == NULL ) {
F_15 ( V_84 ) ;
F_15 ( V_265 ) ;
return V_13 ;
}
F_47 ( V_84 , V_265 , V_268 ) ;
V_84 -> V_62 = ( T_2 * ) V_266 ;
V_84 -> V_63 = sizeof( struct V_267 ) ;
memcpy ( V_265 -> V_242 , V_263 , V_208 ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_87 ( struct V_58 * V_43 , T_2 V_269 , T_2 * V_242 )
{
struct V_1 * V_2 = & V_43 -> V_69 ;
struct V_37 * V_84 ;
struct V_270 * V_271 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_84 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_271 = (struct V_270 * ) F_4 ( sizeof( struct V_270 ) ) ;
if ( V_271 == NULL ) {
F_15 ( V_84 ) ;
V_3 = V_13 ;
goto exit;
}
V_271 -> V_269 = V_269 ;
memcpy ( V_271 -> V_242 , V_242 , V_208 ) ;
F_47 ( V_84 , V_271 , F_30 ( V_272 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_88 ( struct V_58 * V_43 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_273 ;
V_51 -> V_274 = 0 ;
V_51 -> V_67 = ( T_2 * ) V_43 ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_89 ( struct V_58 * V_43 , T_2 V_92 , T_2 V_275 , T_2 V_276 , T_2 V_222 )
{
struct V_37 * V_277 ;
struct V_278 * V_278 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_41 ( V_279 L_21 ,
F_90 ( V_43 -> V_280 ) , V_92 , V_275 , V_276 ) ;
V_278 = (struct V_278 * ) F_4 ( sizeof( * V_278 ) ) ;
if ( V_278 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_278 -> V_92 = V_92 ;
V_278 -> V_275 = V_275 ;
V_278 -> V_276 = V_276 ;
if ( V_222 ) {
V_277 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_277 == NULL ) {
F_15 ( V_278 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_277 , V_278 , F_30 ( V_281 ) ) ;
V_3 = F_31 ( V_2 , V_277 ) ;
} else {
if ( V_227 != F_91 ( V_43 , ( T_2 * ) V_278 ) )
V_3 = V_13 ;
F_15 ( V_278 ) ;
}
exit:
F_41 ( V_279 L_22 , F_90 ( V_43 -> V_280 ) , V_3 ) ;
V_22 ;
return V_3 ;
}
T_2 F_92 ( struct V_58 * V_43 , T_2 V_282 , T_2 V_222 )
{
struct V_37 * V_277 ;
struct V_283 * V_284 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_193 , ( L_23 ) ) ;
if ( ! F_93 ( V_282 ) ) {
V_3 = V_13 ;
goto exit;
}
V_284 = (struct V_283 * ) F_4 ( sizeof( struct V_283 ) ) ;
if ( V_284 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_284 -> V_285 = V_282 ;
if ( V_222 ) {
V_277 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_277 == NULL ) {
F_15 ( V_284 ) ;
V_3 = V_13 ;
goto exit;
}
F_47 ( V_277 , V_284 , F_30 ( V_55 ) ) ;
V_3 = F_31 ( V_2 , V_277 ) ;
} else {
if ( V_227 != F_94 ( V_43 , ( unsigned char * ) V_284 ) )
V_3 = V_13 ;
F_15 ( V_284 ) ;
}
if ( V_3 == V_4 )
V_43 -> V_98 . V_286 = V_282 ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_95 ( struct V_58 * V_43 , struct V_287 * V_288 )
{
struct V_37 * V_277 ;
struct V_289 * V_290 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_193 , ( L_24 ) ) ;
V_277 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_277 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_290 = (struct V_289 * ) F_4 ( sizeof( struct V_289 ) ) ;
if ( V_290 == NULL ) {
F_15 ( V_277 ) ;
V_3 = V_13 ;
goto exit;
}
V_290 -> V_288 = V_288 ;
F_47 ( V_277 , V_290 , F_30 ( V_291 ) ) ;
V_3 = F_31 ( V_2 , V_277 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_96 ( struct V_58 * V_43 , T_2 V_292 )
{
struct V_37 * V_277 ;
struct V_293 * V_294 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
F_10 ( V_32 , V_193 , ( L_25 ) ) ;
V_277 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_277 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_294 = (struct V_293 * ) F_4 ( sizeof( struct V_293 ) ) ;
if ( V_294 == NULL ) {
F_15 ( V_277 ) ;
V_3 = V_13 ;
goto exit;
}
V_294 -> V_292 = V_292 ;
F_47 ( V_277 , V_294 , F_30 ( V_295 ) ) ;
V_3 = F_31 ( V_2 , V_277 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_97 ( struct V_58 * V_43 , T_2 * V_242 , T_2 V_296 )
{
return V_4 ;
}
static void F_98 ( struct V_58 * V_43 )
{
T_2 V_297 ;
T_2 V_298 = false , V_299 = false , V_300 = false ;
T_2 V_301 = false , V_302 = false , V_303 = false ;
struct V_96 * V_97 = & ( V_43 -> V_98 ) ;
if ( F_49 ( V_97 , V_99 ) ) {
if ( V_97 -> V_304 . V_305 > 100 ||
V_97 -> V_304 . V_306 > 100 ) {
V_298 = true ;
if ( V_97 -> V_304 . V_305 > V_97 -> V_304 . V_306 )
V_300 = true ;
else
V_299 = true ;
}
if ( V_97 -> V_304 . V_305 > 4000 ||
V_97 -> V_304 . V_306 > 4000 ) {
V_301 = true ;
if ( V_97 -> V_304 . V_305 > V_97 -> V_304 . V_306 )
V_302 = true ;
else
V_303 = true ;
}
if ( ( ( V_97 -> V_304 . V_307 + V_97 -> V_304 . V_306 ) > 8 ) ||
( V_97 -> V_304 . V_307 > 2 ) )
V_297 = false ;
else
V_297 = true ;
if ( V_297 )
F_99 ( V_43 ) ;
else
F_100 ( V_43 ) ;
} else {
F_100 ( V_43 ) ;
}
V_97 -> V_304 . V_305 = 0 ;
V_97 -> V_304 . V_306 = 0 ;
V_97 -> V_304 . V_307 = 0 ;
V_97 -> V_304 . V_298 = V_298 ;
V_97 -> V_304 . V_299 = V_299 ;
V_97 -> V_304 . V_300 = V_300 ;
V_97 -> V_304 . V_301 = V_301 ;
V_97 -> V_304 . V_302 = V_302 ;
V_97 -> V_304 . V_303 = V_303 ;
}
static void F_101 ( struct V_58 * V_43 , T_2 * V_67 , int V_166 )
{
struct V_96 * V_97 ;
V_43 = (struct V_58 * ) V_67 ;
V_97 = & ( V_43 -> V_98 ) ;
#ifdef F_102
if ( F_49 ( V_97 , V_308 ) == true )
F_103 ( V_43 ) ;
#endif
F_104 ( V_43 ) ;
F_105 ( V_43 ) ;
F_98 ( V_43 ) ;
F_106 ( V_43 ) ;
}
static void F_107 ( struct V_58 * V_43 , T_2 V_309 )
{
struct V_310 * V_311 = & V_43 -> V_44 ;
struct V_96 * V_97 = & ( V_43 -> V_98 ) ;
T_2 V_312 ;
V_5 ;
if ( ( F_49 ( V_97 , V_313 ) == true ) ||
( F_49 ( V_97 , V_195 ) == true ) )
return;
switch ( V_309 ) {
case V_100 :
if ( F_49 ( V_97 , V_99 ) == true ) {
F_100 ( V_43 ) ;
}
break;
case V_314 :
F_100 ( V_43 ) ;
break;
case V_315 :
V_312 = 1 ;
V_43 -> V_44 . V_316 = 0 ;
F_108 ( V_43 , V_317 , ( T_2 * ) ( & V_312 ) ) ;
break;
case V_318 :
V_312 = 0 ;
F_100 ( V_43 ) ;
F_108 ( V_43 , V_317 , ( T_2 * ) ( & V_312 ) ) ;
break;
case V_319 :
V_311 -> V_320 = V_115 ;
F_100 ( V_43 ) ;
break;
case V_321 :
F_100 ( V_43 ) ;
break;
default:
break;
}
V_22 ;
}
T_2 F_50 ( struct V_58 * V_43 , T_2 V_309 , T_2 V_222 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
if ( V_222 ) {
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_322 ;
V_51 -> V_274 = V_309 ;
V_51 -> V_67 = NULL ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
} else {
F_107 ( V_43 , V_309 ) ;
}
exit:
V_22 ;
return V_3 ;
}
static void F_109 ( struct V_58 * V_43 , T_4 V_323 )
{
F_108 ( V_43 , V_324 , ( T_2 * ) ( & V_323 ) ) ;
}
T_2 F_110 ( struct V_58 * V_43 , T_4 V_323 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_325 ;
V_51 -> V_274 = V_323 ;
V_51 -> V_67 = NULL ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
static void F_111 ( struct V_58 * V_43 , T_2 V_326 )
{
F_108 ( V_43 , V_327 , ( T_2 * ) ( & V_326 ) ) ;
}
T_2 F_112 ( struct V_58 * V_43 , T_2 V_326 , T_2 V_222 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_328 ;
T_2 V_3 = V_4 ;
V_5 ;
F_113 ( V_43 , V_329 , & V_328 ) ;
if ( ! V_328 )
return V_3 ;
if ( V_222 ) {
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_330 ;
V_51 -> V_274 = V_326 ;
V_51 -> V_67 = NULL ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
} else {
F_111 ( V_43 , V_326 ) ;
}
exit:
V_22 ;
return V_3 ;
}
static void F_114 ( struct V_58 * V_43 , T_2 * V_67 , int V_166 )
{
F_115 ( V_43 ) ;
}
T_2 F_116 ( struct V_58 * V_43 , int V_331 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_332 * V_333 = & ( V_43 -> V_334 ) ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
if ( F_117 ( V_333 , V_335 ) )
return V_3 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_336 ;
V_51 -> V_274 = V_331 ;
V_51 -> V_67 = NULL ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
V_22 ;
return V_3 ;
}
T_2 F_118 ( struct V_58 * V_43 )
{
struct V_37 * V_337 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_5 ;
V_337 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
if ( V_337 == NULL ) {
V_3 = V_13 ;
goto exit;
}
V_51 = (struct V_50 * ) F_4 ( sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_15 ( V_337 ) ;
V_3 = V_13 ;
goto exit;
}
V_51 -> V_53 = V_54 ;
V_51 -> V_67 = NULL ;
F_47 ( V_337 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_337 ) ;
exit:
V_22 ;
return V_3 ;
}
static void F_119 ( struct V_58 * V_43 )
{
int V_338 = 0 ;
struct V_239 * V_339 ;
struct V_340 * V_341 = & V_43 -> V_342 ;
V_339 = F_120 ( V_43 ) ;
if ( ! V_339 )
return;
if ( V_339 -> V_343 == 0 ) {
T_2 V_138 = 0 ;
F_121 ( V_43 , V_344 , & V_138 ) ;
while ( ! V_138 ) {
F_12 ( 100 ) ;
V_338 ++ ;
if ( V_338 > 10 )
break;
F_121 ( V_43 , V_344 , & V_138 ) ;
}
if ( V_338 <= 10 ) {
V_341 -> V_345 &= ~ F_122 ( 0 ) ;
V_341 -> V_346 &= ~ F_122 ( 0 ) ;
F_123 ( V_43 , V_347 , NULL , false ) ;
} else {
F_124 ( V_43 ) ;
}
}
}
T_2 F_124 ( struct V_58 * V_43 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_348 ;
V_51 -> V_274 = 0 ;
V_51 -> V_67 = NULL ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
return V_3 ;
}
T_2 F_125 ( struct V_58 * V_43 , T_2 * V_349 )
{
struct V_37 * V_84 ;
struct V_50 * V_51 ;
struct V_1 * V_2 = & V_43 -> V_69 ;
T_2 V_3 = V_4 ;
V_84 = (struct V_37 * ) F_4 ( sizeof( struct V_37 ) ) ;
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
V_51 -> V_53 = V_350 ;
V_51 -> V_274 = V_349 ? 16 : 0 ;
V_51 -> V_67 = V_349 ;
F_47 ( V_84 , V_51 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( V_2 , V_84 ) ;
exit:
return V_3 ;
}
static T_5 F_126 ( struct V_58 * V_58 , struct V_351 * V_349 , T_6 V_352 )
{
T_5 V_65 = V_13 ;
T_2 V_353 [ 16 ] ;
if ( ! V_349 ) {
if ( F_127 ( V_58 , V_353 ) == V_4 ) {
V_349 = (struct V_351 * ) V_353 ;
if ( V_352 && V_352 ( V_349 -> V_253 ) == false )
goto exit;
V_65 = F_128 ( V_58 , V_349 ) ;
}
} else {
if ( V_352 && V_352 ( V_349 -> V_253 ) == false )
goto exit;
V_65 = F_128 ( V_58 , V_349 ) ;
}
exit:
return V_65 ;
}
static void V_28 ( struct V_354 * V_355 )
{
struct V_23 * V_356 = F_129 ( V_355 , struct V_23 , V_27 ) ;
struct V_58 * V_58 = F_129 ( V_356 , struct V_58 , V_356 ) ;
struct V_351 * V_349 ;
T_6 V_357 = F_130 ( V_58 ) ;
V_356 -> V_29 = true ;
while ( ! F_13 ( V_356 -> V_30 ) ) {
if ( ( V_349 = (struct V_351 * ) F_14 ( V_356 -> V_30 ) ) != NULL ) {
F_131 ( V_58 ) ;
} else if ( ( V_349 = (struct V_351 * ) F_132 ( 16 ) ) != NULL ) {
if ( F_127 ( V_58 , ( T_2 * ) V_349 ) != V_4 )
continue;
}
if ( ( void * ) V_349 == ( void * ) V_356 )
continue;
if ( ! F_133 ( V_349 ) ) {
F_15 ( V_349 ) ;
continue;
}
if ( V_357 ( V_349 -> V_253 ) == true ) {
F_128 ( V_58 , V_349 ) ;
F_15 ( V_349 ) ;
} else {
#ifdef F_134
F_125 ( V_58 , ( T_2 * ) V_349 ) ;
#endif
}
}
V_356 -> V_29 = false ;
}
T_2 F_135 ( struct V_58 * V_43 , unsigned char * V_67 )
{
struct V_50 * V_358 ;
if ( ! V_67 )
return V_79 ;
V_358 = (struct V_50 * ) V_67 ;
switch ( V_358 -> V_53 ) {
case V_273 :
F_101 ( V_43 , V_358 -> V_67 , V_358 -> V_274 ) ;
break;
case V_54 :
F_114 ( V_43 , V_358 -> V_67 , V_358 -> V_274 ) ;
break;
case V_322 :
F_107 ( V_43 , ( T_2 ) V_358 -> V_274 ) ;
break;
case V_325 :
F_109 ( V_43 , V_358 -> V_274 ) ;
break;
case V_330 :
F_111 ( V_43 , V_358 -> V_274 ) ;
break;
#ifdef F_134
case V_359 :
F_136 ( V_43 , V_358 -> V_274 ) ;
break;
case V_336 :
F_137 ( V_43 , V_358 -> V_274 ) ;
break;
#endif
#ifdef F_102
case V_348 :
F_119 ( V_43 ) ;
break;
#endif
case V_350 :
F_126 ( V_43 , (struct V_351 * ) V_358 -> V_67 , NULL ) ;
break;
default:
break;
}
if ( V_358 -> V_67 && V_358 -> V_274 > 0 )
F_15 ( V_358 -> V_67 ) ;
return V_227 ;
}
void F_138 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( V_59 -> V_3 == V_74 ) {
F_55 ( & V_97 -> V_116 , 1 ) ;
} else if ( V_59 -> V_3 != V_227 ) {
F_55 ( & V_97 -> V_116 , 1 ) ;
F_10 ( V_32 , V_82 , ( L_26 ) ) ;
}
F_32 ( V_59 ) ;
V_22 ;
}
void F_139 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( V_59 -> V_3 != V_227 ) {
F_140 ( & V_97 -> V_40 ) ;
F_54 ( V_97 , V_99 ) ;
F_141 ( & V_97 -> V_40 ) ;
F_10 ( V_32 , V_82 , ( L_27 ) ) ;
goto exit;
} else
F_142 ( V_43 ) ;
F_32 ( V_59 ) ;
exit:
V_22 ;
}
void F_143 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
struct V_96 * V_97 = & V_43 -> V_98 ;
V_5 ;
if ( V_59 -> V_3 == V_74 ) {
F_55 ( & V_97 -> V_360 , 1 ) ;
} else if ( V_59 -> V_3 != V_227 ) {
F_10 ( V_32 , V_82 , ( L_28 ) ) ;
F_55 ( & V_97 -> V_360 , 1 ) ;
}
F_32 ( V_59 ) ;
V_22 ;
}
void F_144 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
T_2 V_361 ;
struct V_239 * V_233 = NULL ;
struct V_168 * V_362 = NULL ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_159 * V_169 = (struct V_159 * ) V_59 -> V_52 ;
struct V_168 * V_363 = & ( V_97 -> V_364 ) ;
V_5 ;
if ( ( V_59 -> V_3 != V_227 ) ) {
F_10 ( V_32 , V_82 , ( L_29 ) ) ;
F_55 ( & V_97 -> V_360 , 1 ) ;
}
F_145 ( & V_97 -> V_360 , & V_361 ) ;
F_140 ( & V_97 -> V_40 ) ;
if ( F_49 ( V_97 , V_308 ) ) {
V_233 = F_146 ( & V_43 -> V_342 , V_169 -> V_207 ) ;
if ( ! V_233 ) {
V_233 = F_147 ( & V_43 -> V_342 , V_169 -> V_207 ) ;
if ( V_233 == NULL ) {
F_10 ( V_32 , V_82 , ( L_30 ) ) ;
goto V_365 ;
}
}
F_148 ( V_43 ) ;
} else {
V_362 = F_149 ( V_97 ) ;
F_140 ( & ( V_97 -> V_366 . V_40 ) ) ;
if ( V_362 == NULL ) {
V_362 = F_150 ( & V_97 -> V_366 ) ;
if ( V_362 == NULL ) {
F_10 ( V_32 , V_82 , ( L_31 ) ) ;
F_141 ( & V_97 -> V_366 . V_40 ) ;
goto V_365;
}
V_362 -> V_367 = V_115 ;
} else {
F_19 ( & ( V_362 -> V_41 ) , & V_97 -> V_366 . V_36 ) ;
}
V_169 -> V_164 = F_69 ( V_169 ) ;
memcpy ( & ( V_362 -> V_185 ) , V_169 , V_169 -> V_164 ) ;
memcpy ( & V_363 -> V_185 , V_169 , ( F_69 ( V_169 ) ) ) ;
F_57 ( V_97 , V_368 ) ;
F_141 ( & V_97 -> V_366 . V_40 ) ;
}
V_365:
F_141 ( & V_97 -> V_40 ) ;
F_32 ( V_59 ) ;
V_22 ;
}
void F_151 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
struct V_340 * V_341 = & V_43 -> V_342 ;
struct V_237 * V_238 = (struct V_237 * ) ( V_59 -> V_62 ) ;
struct V_239 * V_233 = F_146 ( V_341 , V_238 -> V_242 ) ;
V_5 ;
if ( V_233 == NULL ) {
F_10 ( V_32 , V_82 , ( L_32 ) ) ;
goto exit;
}
exit:
F_32 ( V_59 ) ;
V_22 ;
}
void F_152 ( struct V_58 * V_43 , struct V_37 * V_59 )
{
struct V_340 * V_341 = & V_43 -> V_342 ;
struct V_96 * V_97 = & V_43 -> V_98 ;
struct V_264 * V_369 = (struct V_264 * ) ( V_59 -> V_52 ) ;
struct V_267 * V_370 = (struct V_267 * ) ( V_59 -> V_62 ) ;
struct V_239 * V_233 = F_146 ( V_341 , V_369 -> V_242 ) ;
V_5 ;
if ( V_233 == NULL ) {
F_10 ( V_32 , V_82 , ( L_33 ) ) ;
goto exit;
}
V_233 -> V_371 = V_370 -> V_372 ;
V_233 -> V_125 = V_370 -> V_372 ;
F_140 ( & V_97 -> V_40 ) ;
if ( ( F_49 ( V_97 , V_373 ) == true ) && ( F_49 ( V_97 , V_368 ) == true ) )
F_57 ( V_97 , V_368 ) ;
F_54 ( V_97 , V_99 ) ;
F_141 ( & V_97 -> V_40 ) ;
exit:
F_32 ( V_59 ) ;
V_22 ;
}
