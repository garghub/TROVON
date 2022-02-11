static void F_1 ( struct V_1 * log ,
int (* F_2)( struct V_2 * ) )
{
struct V_3 * V_4 ;
F_3 (sbi, &log->sb_list, log_list) {
F_2 ( V_4 -> V_5 -> V_6 ) ;
F_2 ( V_4 -> V_7 -> V_6 ) ;
F_2 ( V_4 -> V_8 -> V_6 ) ;
}
}
int F_4 ( struct V_1 * log , struct V_9 * V_10 , struct V_11 * V_11 ,
struct V_12 * V_13 )
{
int V_14 ;
int V_15 , V_16 ;
struct V_17 * V_18 = NULL ;
unsigned long V_19 ;
F_5 ( L_1 ,
log , V_10 , V_11 , V_13 ) ;
F_6 ( log ) ;
if ( V_10 == NULL )
goto V_20;
if ( V_13 == NULL ||
V_13 -> type & V_21 || ( V_18 = V_13 -> V_18 ) == NULL )
goto V_20;
V_14 = log -> V_14 ;
F_7 ( log , V_19 ) ;
if ( V_18 -> V_14 == 0 ) {
V_18 -> log = log ;
V_18 -> V_14 = V_14 ;
log -> V_22 ++ ;
F_8 ( & V_18 -> V_23 , & log -> V_23 ) ;
}
if ( V_10 -> V_14 == 0 ) {
V_10 -> V_14 = V_18 -> V_14 ;
log -> V_22 ++ ;
F_9 ( & V_10 -> V_23 , & V_18 -> V_23 ) ;
}
else {
F_10 ( V_15 , V_18 -> V_14 , log ) ;
F_10 ( V_16 , V_10 -> V_14 , log ) ;
if ( V_15 < V_16 ) {
V_10 -> V_14 = V_18 -> V_14 ;
F_11 ( & V_10 -> V_23 , & V_18 -> V_23 ) ;
}
}
F_12 ( log , V_19 ) ;
V_20:
V_14 = F_13 ( log , V_10 , V_11 , V_13 ) ;
F_10 ( V_15 , V_14 , log ) ;
if ( V_15 >= log -> V_24 )
V_14 = F_14 ( log , 0 ) ;
log -> V_14 = V_14 ;
F_15 ( log ) ;
return V_14 ;
}
static int
F_13 ( struct V_1 * log , struct V_9 * V_10 , struct V_11 * V_11 ,
struct V_12 * V_13 )
{
int V_14 = 0 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_1 V_29 ;
int V_30 ;
int V_31 ;
T_1 V_32 ;
T_1 V_33 ;
int V_34 ;
int V_35 ;
int V_36 ;
int V_37 ;
struct V_38 * V_38 ;
struct V_39 * V_39 ;
struct V_40 * V_40 ;
int V_41 ;
V_37 = 0 ;
V_26 = (struct V_25 * ) log -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_30 = log -> V_43 ;
if ( V_13 == NULL )
goto V_44;
if ( V_13 -> V_45 & V_46 ) {
V_32 = ( T_1 ) ( V_13 -> V_18 -> V_47 ) ;
V_38 = (struct V_38 * ) & V_13 -> V_48 ;
}
else if ( V_13 -> V_45 & V_49 ) {
if ( V_13 -> type & V_50 )
V_32 = ( T_1 ) & F_16 ( V_13 -> V_51 ) -> V_52 ;
else
V_32 = ( T_1 ) & F_16 ( V_13 -> V_51 ) -> V_53 ;
V_38 = (struct V_38 * ) & V_13 -> V_48 ;
}
#ifdef F_17
else if ( V_13 -> V_45 & V_54 ) {
V_55 = (struct V_55 * ) & V_13 ;
V_32 = ( T_1 ) & V_55 -> V_56 ;
V_38 = (struct V_38 * ) & V_13 ;
}
#endif
else {
F_18 ( L_2 , V_13 ) ;
return 0 ;
}
V_41 = V_38 -> V_41 ;
V_57:
ASSERT ( V_38 -> V_58 <= V_38 -> V_59 ) ;
V_39 = V_38 -> V_39 ;
for ( V_36 = 0 ; V_36 < V_38 -> V_58 ; V_36 ++ , V_39 ++ ) {
if ( V_39 -> V_60 == 0 )
continue;
if ( V_30 >= V_61 - V_62 ) {
F_19 ( log ) ;
V_26 = log -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_30 = V_63 ;
}
V_33 = ( V_64 * ) V_32 + ( V_39 -> V_65 << V_41 ) ;
V_34 = V_39 -> V_60 << V_41 ;
V_37 += V_34 ;
while ( V_34 > 0 ) {
V_31 = ( V_61 - V_62 ) - V_30 ;
V_35 = F_20 ( V_31 , V_34 ) ;
V_29 = ( T_1 ) V_28 + V_30 ;
memcpy ( V_29 , V_33 , V_35 ) ;
V_30 += V_35 ;
if ( V_30 < V_61 - V_62 )
break;
F_19 ( log ) ;
V_26 = (struct V_25 * ) log -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_30 = V_63 ;
V_34 -= V_35 ;
V_33 += V_35 ;
}
V_37 += 4 ;
V_40 = (struct V_40 * ) ( ( T_1 ) V_28 + V_30 ) ;
V_40 -> V_65 = F_21 ( V_39 -> V_65 ) ;
V_40 -> V_60 = F_21 ( V_39 -> V_60 ) ;
V_30 += 4 ;
F_5 ( L_3 ,
V_39 -> V_65 , V_39 -> V_60 ) ;
}
if ( ( V_36 = V_38 -> V_66 ) ) {
V_38 = (struct V_38 * ) F_22 ( V_36 ) ;
goto V_57;
}
V_44:
V_11 -> V_60 = F_21 ( V_37 ) ;
V_33 = ( T_1 ) V_11 ;
V_34 = V_67 ;
while ( V_34 > 0 ) {
V_31 = ( V_61 - V_62 ) - V_30 ;
V_35 = F_20 ( V_31 , V_34 ) ;
V_29 = ( T_1 ) V_28 + V_30 ;
memcpy ( V_29 , V_33 , V_35 ) ;
V_30 += V_35 ;
V_34 -= V_35 ;
if ( V_34 )
goto V_68;
log -> V_43 = V_30 ;
V_26 -> V_69 = V_30 ;
V_14 = ( log -> V_70 << V_71 ) + V_30 ;
if ( V_11 -> type & F_21 ( V_72 ) ) {
V_10 -> V_73 = V_14 ;
F_5 ( L_4 , V_10 -> V_73 ,
V_26 -> V_69 ) ;
F_23 ( V_74 . V_75 ) ;
F_24 ( log ) ;
V_10 -> V_45 = V_76 ;
V_10 -> V_26 = log -> V_26 ;
V_10 -> V_77 = log -> V_70 ;
V_10 -> V_43 = log -> V_43 ;
F_8 ( & V_10 -> V_78 , & log -> V_78 ) ;
F_25 ( log ) ;
}
F_5 ( L_5 ,
F_26 ( V_11 -> type ) , log -> V_26 , log -> V_70 , V_30 ) ;
if ( V_30 < V_61 - V_62 )
return V_14 ;
V_68:
F_19 ( log ) ;
V_26 = (struct V_25 * ) log -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_30 = V_63 ;
V_33 += V_35 ;
}
return V_14 ;
}
static int F_19 ( struct V_1 * log )
{
struct V_27 * V_28 ;
int V_79 ;
int V_77 ;
struct V_25 * V_26 ;
struct V_25 * V_80 ;
struct V_9 * V_10 ;
V_77 = log -> V_70 ;
V_26 = log -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_79 = F_27 ( V_28 -> V_81 . V_70 ) ;
F_24 ( log ) ;
if ( F_28 ( & log -> V_78 ) )
V_10 = NULL ;
else
V_10 = F_29 ( log -> V_78 . V_82 , struct V_9 , V_78 ) ;
if ( V_10 && V_10 -> V_77 == V_77 ) {
V_10 -> V_45 |= V_83 ;
if ( log -> V_84 & V_85 ) {
if ( V_26 -> V_86 == NULL )
F_30 ( log , V_26 , 0 , 0 ) ;
} else {
log -> V_84 |= V_85 ;
F_31 ( log , 0 ) ;
}
}
else {
V_26 -> V_87 = V_26 -> V_69 ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_26 -> V_87 ) ;
F_30 ( log , V_26 , V_89 | V_90 | V_91 , 0 ) ;
}
F_25 ( log ) ;
log -> V_70 = ( V_77 == log -> V_92 - 1 ) ? 2 : V_77 + 1 ;
log -> V_43 = V_63 ;
V_80 = F_32 ( log , log -> V_70 ) ;
V_80 -> V_69 = log -> V_43 ;
log -> V_26 = V_80 ;
V_28 = (struct V_27 * ) V_80 -> V_42 ;
V_28 -> V_81 . V_70 = V_28 -> V_88 . V_70 = F_33 ( V_79 + 1 ) ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_63 ) ;
return 0 ;
}
int F_34 ( struct V_1 * log , struct V_9 * V_10 )
{
int V_93 = 0 ;
F_24 ( log ) ;
if ( V_10 -> V_45 & V_94 ) {
if ( V_10 -> V_45 & V_95 )
V_93 = - V_96 ;
F_25 ( log ) ;
return V_93 ;
}
F_5 ( L_6 , V_10 , log -> V_97 ) ;
if ( V_10 -> V_98 & V_99 )
V_10 -> V_45 |= V_100 ;
if ( ( ! ( log -> V_84 & V_85 ) ) && ( ! F_28 ( & log -> V_78 ) ) &&
( ! ( V_10 -> V_98 & V_99 ) || F_35 ( V_101 , & log -> V_45 )
|| V_102 ) ) {
log -> V_84 |= V_85 ;
F_31 ( log , 0 ) ;
}
if ( V_10 -> V_98 & V_99 ) {
F_25 ( log ) ;
return 0 ;
}
if ( V_10 -> V_45 & V_94 ) {
if ( V_10 -> V_45 & V_95 )
V_93 = - V_96 ;
F_25 ( log ) ;
return V_93 ;
}
log -> V_97 ++ ;
V_10 -> V_45 |= V_103 ;
F_36 ( V_10 -> V_104 , ( V_10 -> V_45 & V_94 ) ,
F_24 ( log ) , F_25 ( log ) ) ;
if ( V_10 -> V_45 & V_95 )
V_93 = - V_96 ;
F_25 ( log ) ;
return V_93 ;
}
static void F_31 ( struct V_1 * log , int V_105 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_106 ;
struct V_9 * V_10 ;
struct V_9 * V_107 = NULL ;
V_106 = F_29 ( log -> V_78 . V_66 , struct V_9 , V_78 ) -> V_77 ;
F_3 (tblk, &log->cqueue, cqueue) {
if ( V_10 -> V_77 != V_106 )
break;
V_107 = V_10 ;
V_10 -> V_45 |= V_108 ;
}
V_10 = V_107 ;
V_26 = (struct V_25 * ) V_10 -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
if ( V_10 -> V_45 & V_83 ) {
V_10 -> V_45 &= ~ V_83 ;
V_10 -> V_45 |= V_109 ;
V_26 -> V_87 = V_26 -> V_69 ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_26 -> V_87 ) ;
F_30 ( log , V_26 , V_89 | V_90 | V_110 ,
V_105 ) ;
F_23 ( V_74 . V_111 ) ;
}
else {
V_26 -> V_87 = V_10 -> V_43 ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_26 -> V_87 ) ;
F_30 ( log , V_26 , V_89 | V_110 , V_105 ) ;
F_23 ( V_74 . V_112 ) ;
}
}
static void F_37 ( struct V_25 * V_26 )
{
unsigned long V_19 ;
struct V_1 * log = V_26 -> V_113 ;
struct V_27 * V_28 ;
struct V_9 * V_10 , * V_114 ;
F_38 ( & log -> V_115 , V_19 ) ;
F_39 (tblk, temp, &log->cqueue, cqueue) {
if ( ! ( V_10 -> V_45 & V_108 ) )
break;
if ( V_26 -> V_116 & V_117 )
V_10 -> V_45 |= V_95 ;
F_40 ( & V_10 -> V_78 ) ;
V_10 -> V_45 &= ~ V_76 ;
if ( V_10 == log -> V_118 ) {
F_41 ( V_101 , & log -> V_45 ) ;
log -> V_118 = NULL ;
}
F_5 ( L_7 , V_10 ,
V_10 -> V_45 ) ;
if ( ! ( V_10 -> V_98 & V_119 ) )
F_42 ( V_10 ) ;
else {
V_10 -> V_45 |= V_94 ;
if ( V_10 -> V_45 & V_103 )
log -> V_97 -- ;
F_43 ( V_10 ) ;
}
if ( V_10 -> V_45 & V_109 )
F_44 ( V_26 ) ;
else if ( V_10 -> V_45 & V_83 ) {
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_26 -> V_87 = V_26 -> V_69 ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_26 -> V_69 ) ;
F_5 ( L_8 ) ;
F_30 ( log , V_26 , V_89 | V_90 | V_91 ,
1 ) ;
}
}
if ( ( ! F_28 ( & log -> V_78 ) ) &&
( ( log -> V_97 > 0 ) || ( V_10 -> V_26 -> V_86 != NULL ) ||
F_35 ( V_101 , & log -> V_45 ) || V_102 ) )
F_31 ( log , 1 ) ;
else
log -> V_84 &= ~ V_85 ;
F_45 ( & log -> V_115 , V_19 ) ;
return;
}
static int F_14 ( struct V_1 * log , int V_120 )
{
int V_121 ;
int V_122 ;
int free ;
int V_123 ;
int V_124 ;
struct V_11 V_11 ;
int V_14 ;
struct V_125 * V_28 ;
unsigned long V_19 ;
if ( V_120 )
F_1 ( log , V_126 ) ;
else
F_1 ( log , V_127 ) ;
if ( log -> V_128 == log -> V_129 ) {
F_7 ( log , V_19 ) ;
if ( F_28 ( & log -> V_23 ) )
log -> V_128 = log -> V_14 ;
else {
V_28 = F_29 ( log -> V_23 . V_66 ,
struct V_125 , V_23 ) ;
log -> V_128 = V_28 -> V_14 ;
}
F_12 ( log , V_19 ) ;
}
if ( log -> V_128 != log -> V_129 ) {
V_11 . V_130 = 0 ;
V_11 . V_131 = 0 ;
V_11 . type = F_21 ( V_132 ) ;
V_11 . V_60 = 0 ;
V_11 . log . V_129 . V_128 = F_33 ( log -> V_128 ) ;
V_14 = F_13 ( log , NULL , & V_11 , NULL ) ;
log -> V_129 = log -> V_128 ;
} else
V_14 = log -> V_14 ;
V_121 = log -> V_121 ;
F_10 ( V_122 , V_14 , log ) ;
free = V_121 - V_122 ;
V_123 = F_46 ( V_121 ) ;
V_124 = F_20 ( free / 2 , V_123 ) ;
if ( V_124 < 2 * V_61 ) {
F_47 ( L_9 ) ;
log -> V_129 = log -> V_128 = V_14 ;
log -> V_24 = V_123 ;
} else
log -> V_24 = V_122 + V_124 ;
if ( ! F_35 ( V_133 , & log -> V_45 ) &&
( V_122 > F_48 ( V_121 ) ) && log -> V_134 ) {
F_49 ( V_133 , & log -> V_45 ) ;
F_5 ( L_10 , V_14 ,
log -> V_129 ) ;
F_50 ( log , 0 ) ;
}
return V_14 ;
}
void F_51 ( struct V_1 * log , int V_120 )
{ F_6 ( log ) ;
F_14 ( log , V_120 ) ;
F_15 ( log ) ;
}
int F_52 ( struct V_135 * V_136 )
{
int V_93 ;
struct V_137 * V_138 ;
struct V_1 * log ;
struct V_3 * V_4 = F_53 ( V_136 ) ;
if ( V_4 -> V_45 & V_139 )
return F_54 ( V_136 ) ;
if ( V_4 -> V_140 & V_141 )
return F_55 ( V_136 ) ;
F_56 ( & V_142 ) ;
F_3 (log, &jfs_external_logs, journal_list) {
if ( log -> V_138 -> V_143 == V_4 -> V_144 ) {
if ( memcmp ( log -> V_145 , V_4 -> V_146 ,
sizeof( log -> V_145 ) ) ) {
F_47 ( L_11 ) ;
F_57 ( & V_142 ) ;
return - V_147 ;
}
if ( ( V_93 = F_58 ( log , V_4 , 1 ) ) ) {
F_57 ( & V_142 ) ;
return V_93 ;
}
goto V_148;
}
}
if ( ! ( log = F_59 ( sizeof( struct V_1 ) , V_149 ) ) ) {
F_57 ( & V_142 ) ;
return - V_150 ;
}
F_60 ( & log -> V_151 ) ;
F_61 ( & log -> V_152 ) ;
V_138 = F_62 ( V_4 -> V_144 , V_153 | V_154 | V_155 ,
log ) ;
if ( F_63 ( V_138 ) ) {
V_93 = F_64 ( V_138 ) ;
goto free;
}
log -> V_138 = V_138 ;
memcpy ( log -> V_145 , V_4 -> V_146 , sizeof( log -> V_145 ) ) ;
if ( ( V_93 = F_65 ( log ) ) )
goto V_156;
F_9 ( & log -> V_157 , & V_158 ) ;
if ( ( V_93 = F_58 ( log , V_4 , 1 ) ) )
goto V_159;
V_148:
F_6 ( log ) ;
F_9 ( & V_4 -> V_160 , & log -> V_151 ) ;
V_4 -> log = log ;
F_15 ( log ) ;
F_57 ( & V_142 ) ;
return 0 ;
V_159:
F_40 ( & log -> V_157 ) ;
F_66 ( log ) ;
V_156:
F_67 ( V_138 , V_153 | V_154 | V_155 ) ;
free:
F_57 ( & V_142 ) ;
F_68 ( log ) ;
F_47 ( L_12 , V_93 ) ;
return V_93 ;
}
static int F_55 ( struct V_135 * V_136 )
{
struct V_1 * log ;
int V_93 ;
if ( ! ( log = F_59 ( sizeof( struct V_1 ) , V_149 ) ) )
return - V_150 ;
F_60 ( & log -> V_151 ) ;
F_61 ( & log -> V_152 ) ;
F_49 ( V_161 , & log -> V_45 ) ;
log -> V_138 = V_136 -> V_162 ;
log -> V_163 = F_69 ( & F_53 ( V_136 ) -> V_164 ) ;
log -> V_92 = F_70 ( & F_53 ( V_136 ) -> V_164 ) >>
( V_71 - V_136 -> V_165 ) ;
log -> V_166 = V_136 -> V_165 ;
ASSERT ( V_71 >= V_136 -> V_165 ) ;
if ( ( V_93 = F_65 ( log ) ) ) {
F_68 ( log ) ;
F_47 ( L_12 , V_93 ) ;
return V_93 ;
}
F_9 ( & F_53 ( V_136 ) -> V_160 , & log -> V_151 ) ;
F_53 ( V_136 ) -> log = log ;
return V_93 ;
}
static int F_54 ( struct V_135 * V_136 )
{
int V_93 ;
F_56 ( & V_142 ) ;
if ( ! V_167 ) {
V_167 = F_59 ( sizeof( struct V_1 ) , V_149 ) ;
if ( ! V_167 ) {
F_57 ( & V_142 ) ;
return - V_150 ;
}
F_60 ( & V_167 -> V_151 ) ;
F_61 ( & V_167 -> V_152 ) ;
V_167 -> V_168 = 1 ;
V_167 -> V_163 = 0 ;
V_167 -> V_92 = 1024 ;
V_93 = F_65 ( V_167 ) ;
if ( V_93 ) {
F_68 ( V_167 ) ;
V_167 = NULL ;
F_57 ( & V_142 ) ;
return V_93 ;
}
}
F_6 ( V_167 ) ;
F_9 ( & F_53 ( V_136 ) -> V_160 , & V_167 -> V_151 ) ;
F_53 ( V_136 ) -> log = V_167 ;
F_15 ( V_167 ) ;
F_57 ( & V_142 ) ;
return 0 ;
}
int F_65 ( struct V_1 * log )
{
int V_93 = 0 ;
struct V_11 V_11 ;
struct V_169 * V_169 ;
struct V_25 * V_170 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_14 = 0 ;
F_5 ( L_13 , log ) ;
F_71 ( log ) ;
F_72 ( log ) ;
F_73 ( log ) ;
F_60 ( & log -> V_23 ) ;
F_60 ( & log -> V_78 ) ;
log -> V_118 = NULL ;
log -> V_22 = 0 ;
if ( ( V_93 = F_74 ( log ) ) )
return V_93 ;
if ( ! F_35 ( V_161 , & log -> V_45 ) )
log -> V_166 = V_71 ;
if ( log -> V_168 ) {
V_26 = F_32 ( log , 0 ) ;
log -> V_26 = V_26 ;
V_26 -> V_171 = V_26 -> V_69 = 0 ;
} else {
if ( ( V_93 = F_75 ( log , 1 , & V_170 ) ) )
goto V_172;
V_169 = (struct V_169 * ) V_170 -> V_42 ;
if ( V_169 -> V_173 != F_33 ( V_174 ) ) {
F_47 ( L_14 ) ;
V_93 = - V_147 ;
goto V_175;
}
if ( V_169 -> V_176 != F_33 ( V_177 ) ) {
F_47 ( L_15 ) ;
V_93 = - V_147 ;
goto V_175;
}
if ( F_35 ( V_161 , & log -> V_45 ) ) {
if ( log -> V_92 != F_27 ( V_169 -> V_92 ) ) {
V_93 = - V_147 ;
goto V_175;
}
F_5 ( L_16
L_17 , log ,
( unsigned long long ) log -> V_163 , log -> V_92 ) ;
} else {
if ( memcmp ( V_169 -> V_145 , log -> V_145 , 16 ) ) {
F_47 ( L_18 ) ;
goto V_175;
}
log -> V_92 = F_27 ( V_169 -> V_92 ) ;
log -> V_166 = F_27 ( V_169 -> V_166 ) ;
F_5 ( L_19
L_17 , log ,
( unsigned long long ) log -> V_163 , log -> V_92 ) ;
}
log -> V_70 = F_27 ( V_169 -> V_178 ) / V_61 ;
log -> V_43 = F_27 ( V_169 -> V_178 ) - ( V_61 * log -> V_70 ) ;
if ( ( V_93 = F_75 ( log , log -> V_70 , & V_26 ) ) )
goto V_175;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
F_5 ( L_20 ,
F_27 ( V_169 -> V_178 ) , log -> V_70 , log -> V_43 ,
F_26 ( V_28 -> V_81 . V_43 ) ) ;
log -> V_26 = V_26 ;
V_26 -> V_171 = log -> V_70 ;
V_26 -> V_69 = log -> V_43 ;
if ( log -> V_43 >= V_61 - V_62 )
F_19 ( log ) ;
V_11 . V_130 = 0 ;
V_11 . V_131 = 0 ;
V_11 . type = F_21 ( V_132 ) ;
V_11 . V_60 = 0 ;
V_11 . log . V_129 . V_128 = 0 ;
V_14 = F_13 ( log , NULL , & V_11 , NULL ) ;
V_26 = log -> V_26 ;
V_26 -> V_87 = V_26 -> V_69 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_26 -> V_69 ) ;
F_30 ( log , V_26 , V_89 | V_179 , 0 ) ;
if ( ( V_93 = F_76 ( V_26 , 0 ) ) )
goto V_180;
V_169 -> V_176 = F_33 ( V_181 ) ;
log -> V_182 = F_27 ( V_169 -> V_182 ) + 1 ;
V_169 -> V_182 = F_33 ( log -> V_182 ) ;
F_77 ( log , V_170 , V_89 | V_90 | V_179 ) ;
if ( ( V_93 = F_76 ( V_170 , V_91 ) ) )
goto V_180;
}
log -> V_121 = ( log -> V_92 - 2 ) << V_71 ;
log -> V_14 = V_14 ;
log -> V_129 = V_14 ;
log -> V_128 = log -> V_129 ;
log -> V_24 = F_46 ( log -> V_121 ) ;
F_5 ( L_21 ,
log -> V_14 , log -> V_129 , log -> V_128 ) ;
log -> V_73 = V_14 ;
return 0 ;
V_180:
log -> V_183 = NULL ;
V_26 -> V_86 = NULL ;
F_44 ( V_26 ) ;
V_175:
F_44 ( V_170 ) ;
V_172:
F_66 ( log ) ;
F_47 ( L_22 , V_93 ) ;
return V_93 ;
}
int F_78 ( struct V_135 * V_136 )
{
struct V_3 * V_4 = F_53 ( V_136 ) ;
struct V_1 * log = V_4 -> log ;
struct V_137 * V_138 ;
int V_93 = 0 ;
F_5 ( L_23 , log ) ;
F_56 ( & V_142 ) ;
F_6 ( log ) ;
F_40 ( & V_4 -> V_160 ) ;
F_15 ( log ) ;
V_4 -> log = NULL ;
F_79 ( V_136 -> V_162 ) ;
if ( F_35 ( V_161 , & log -> V_45 ) ) {
V_93 = F_80 ( log ) ;
F_68 ( log ) ;
goto V_184;
}
if ( ! log -> V_168 )
F_58 ( log , V_4 , 0 ) ;
if ( ! F_28 ( & log -> V_151 ) )
goto V_184;
if ( log -> V_168 )
goto V_184;
F_40 ( & log -> V_157 ) ;
V_138 = log -> V_138 ;
V_93 = F_80 ( log ) ;
F_67 ( V_138 , V_153 | V_154 | V_155 ) ;
F_68 ( log ) ;
V_184:
F_57 ( & V_142 ) ;
F_5 ( L_24 , V_93 ) ;
return V_93 ;
}
void F_50 ( struct V_1 * log , int V_185 )
{
int V_36 ;
struct V_9 * V_186 = NULL ;
if ( ! log )
return;
F_5 ( L_25 , log , V_185 ) ;
F_24 ( log ) ;
if ( ! F_28 ( & log -> V_78 ) ) {
V_186 = F_29 ( log -> V_78 . V_82 , struct V_9 , V_78 ) ;
if ( F_35 ( V_101 , & log -> V_45 ) ) {
if ( log -> V_118 )
log -> V_118 = V_186 ;
} else {
log -> V_118 = V_186 ;
F_49 ( V_101 , & log -> V_45 ) ;
if ( ! ( log -> V_84 & V_85 ) ) {
log -> V_84 |= V_85 ;
F_31 ( log , 0 ) ;
}
}
}
if ( ( V_185 > 1 ) || F_35 ( V_133 , & log -> V_45 ) ) {
F_49 ( V_101 , & log -> V_45 ) ;
log -> V_118 = NULL ;
}
if ( V_185 && V_186 && ! ( V_186 -> V_45 & V_94 ) ) {
F_81 ( V_187 , V_188 ) ;
F_82 ( & V_186 -> V_104 , & V_187 ) ;
F_83 ( V_189 ) ;
F_25 ( log ) ;
F_84 () ;
F_85 ( V_190 ) ;
F_24 ( log ) ;
F_86 ( & V_186 -> V_104 , & V_187 ) ;
}
F_25 ( log ) ;
if ( V_185 < 2 )
return;
F_1 ( log , V_126 ) ;
if ( ( ! F_28 ( & log -> V_78 ) ) || ! F_28 ( & log -> V_23 ) ) {
for ( V_36 = 0 ; V_36 < 200 ; V_36 ++ ) {
F_87 ( 250 ) ;
F_1 ( log , V_126 ) ;
if ( F_28 ( & log -> V_78 ) &&
F_28 ( & log -> V_23 ) )
break;
}
}
assert ( F_28 ( & log -> V_78 ) ) ;
#ifdef F_88
if ( ! F_28 ( & log -> V_23 ) ) {
struct V_125 * V_28 ;
F_89 ( V_191 L_26 ) ;
F_3 (lp, &log->synclist, synclist) {
if ( V_28 -> V_98 & V_192 ) {
struct V_17 * V_18 = (struct V_17 * ) V_28 ;
F_90 ( V_191 , L_27 ,
V_193 , 16 , 4 ,
V_18 , sizeof( struct V_17 ) , 0 ) ;
F_90 ( V_191 , L_28 ,
V_193 , 16 ,
sizeof( long ) , V_18 -> V_70 ,
sizeof( struct V_70 ) , 0 ) ;
} else
F_90 ( V_191 , L_29 ,
V_193 , 16 , 4 ,
V_28 , sizeof( struct V_9 ) , 0 ) ;
}
}
#else
F_91 ( ! F_28 ( & log -> V_23 ) ) ;
#endif
F_41 ( V_101 , & log -> V_45 ) ;
}
int F_80 ( struct V_1 * log )
{
int V_93 ;
struct V_11 V_11 ;
int V_14 ;
struct V_169 * V_169 ;
struct V_25 * V_170 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
F_5 ( L_30 , log ) ;
F_50 ( log , 2 ) ;
V_11 . V_130 = 0 ;
V_11 . V_131 = 0 ;
V_11 . type = F_21 ( V_132 ) ;
V_11 . V_60 = 0 ;
V_11 . log . V_129 . V_128 = 0 ;
V_14 = F_13 ( log , NULL , & V_11 , NULL ) ;
V_26 = log -> V_26 ;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_26 -> V_69 ) ;
F_30 ( log , log -> V_26 , V_89 | V_90 | V_179 , 0 ) ;
F_76 ( log -> V_26 , V_91 ) ;
log -> V_26 = NULL ;
if ( ( V_93 = F_75 ( log , 1 , & V_170 ) ) )
goto V_184;
V_169 = (struct V_169 * ) V_170 -> V_42 ;
V_169 -> V_176 = F_33 ( V_177 ) ;
V_169 -> V_178 = F_33 ( V_14 ) ;
F_77 ( log , V_170 , V_89 | V_90 | V_179 ) ;
V_93 = F_76 ( V_170 , V_91 ) ;
F_5 ( L_31 ,
V_14 , log -> V_70 , log -> V_43 ) ;
V_184:
F_66 ( log ) ;
if ( V_93 ) {
F_47 ( L_32 , V_93 ) ;
}
return V_93 ;
}
static int F_58 ( struct V_1 * log , struct V_3 * V_4 ,
int V_194 )
{
int V_93 = 0 ;
int V_36 ;
struct V_169 * V_169 ;
struct V_25 * V_170 ;
char * V_145 = V_4 -> V_145 ;
if ( ( V_93 = F_75 ( log , 1 , & V_170 ) ) )
return V_93 ;
V_169 = (struct V_169 * ) V_170 -> V_42 ;
if ( V_194 ) {
for ( V_36 = 0 ; V_36 < V_195 ; V_36 ++ )
if ( ! memcmp ( V_169 -> V_134 [ V_36 ] . V_145 , V_196 , 16 ) ) {
memcpy ( V_169 -> V_134 [ V_36 ] . V_145 , V_145 , 16 ) ;
V_4 -> V_197 = V_36 ;
break;
}
if ( V_36 == V_195 ) {
F_47 ( L_33 ) ;
F_44 ( V_170 ) ;
return - V_198 ;
}
} else {
for ( V_36 = 0 ; V_36 < V_195 ; V_36 ++ )
if ( ! memcmp ( V_169 -> V_134 [ V_36 ] . V_145 , V_145 , 16 ) ) {
memcpy ( V_169 -> V_134 [ V_36 ] . V_145 , V_196 , 16 ) ;
break;
}
if ( V_36 == V_195 ) {
F_47 ( L_34 ) ;
F_44 ( V_170 ) ;
return - V_96 ;
}
}
F_77 ( log , V_170 , V_89 | V_90 | V_179 ) ;
V_93 = F_76 ( V_170 , V_91 ) ;
return V_93 ;
}
static int F_74 ( struct V_1 * log )
{
int V_36 ;
struct V_25 * V_25 ;
F_5 ( L_35 , log ) ;
log -> V_26 = NULL ;
log -> V_183 = NULL ;
F_61 ( & log -> V_199 ) ;
log -> V_200 = NULL ;
for ( V_36 = 0 ; V_36 < V_201 ; ) {
char * V_202 ;
T_2 V_65 ;
struct V_70 * V_70 ;
V_202 = ( char * ) F_92 ( V_149 ) ;
if ( V_202 == NULL )
goto error;
V_70 = F_93 ( V_202 ) ;
for ( V_65 = 0 ; V_65 < V_203 ; V_65 += V_61 ) {
V_25 = F_94 ( sizeof( struct V_25 ) , V_149 ) ;
if ( V_25 == NULL ) {
if ( V_65 == 0 )
F_95 ( ( unsigned long ) V_202 ) ;
goto error;
}
if ( V_65 )
F_96 ( V_70 ) ;
V_25 -> V_204 = V_65 ;
V_25 -> V_42 = V_202 + V_65 ;
V_25 -> V_205 = V_70 ;
V_25 -> V_113 = log ;
F_61 ( & V_25 -> V_206 ) ;
V_25 -> V_207 = log -> V_200 ;
log -> V_200 = V_25 ;
V_36 ++ ;
}
}
return ( 0 ) ;
error:
F_66 ( log ) ;
return - V_150 ;
}
static void F_66 ( struct V_1 * log )
{
struct V_25 * V_25 ;
F_5 ( L_36 , log ) ;
V_25 = log -> V_200 ;
while ( V_25 ) {
struct V_25 * V_66 = V_25 -> V_207 ;
F_97 ( V_25 -> V_205 ) ;
F_68 ( V_25 ) ;
V_25 = V_66 ;
}
}
static struct V_25 * F_32 ( struct V_1 * log , int V_77 )
{
struct V_25 * V_26 ;
unsigned long V_19 ;
F_98 ( V_19 ) ;
F_99 ( log -> V_199 , ( V_26 = log -> V_200 ) , V_19 ) ;
log -> V_200 = V_26 -> V_207 ;
F_100 ( V_19 ) ;
V_26 -> V_116 = 0 ;
V_26 -> V_86 = NULL ;
V_26 -> V_207 = NULL ;
V_26 -> V_171 = V_77 ;
V_26 -> V_208 = log -> V_163 + ( V_77 << ( V_71 - log -> V_166 ) ) ;
V_26 -> V_87 = 0 ;
return V_26 ;
}
static void F_44 ( struct V_25 * V_26 )
{
unsigned long V_19 ;
F_98 ( V_19 ) ;
F_101 ( V_26 ) ;
F_100 ( V_19 ) ;
}
static void F_101 ( struct V_25 * V_26 )
{
struct V_1 * log = V_26 -> V_113 ;
assert ( V_26 -> V_86 == NULL ) ;
V_26 -> V_207 = log -> V_200 ;
log -> V_200 = V_26 ;
F_102 ( & log -> V_199 ) ;
return;
}
static inline void F_103 ( struct V_25 * V_26 )
{
unsigned long V_19 ;
F_38 ( & V_209 , V_19 ) ;
V_26 -> V_210 = V_211 ;
V_211 = V_26 ;
F_45 ( & V_209 , V_19 ) ;
F_104 ( V_212 ) ;
}
static int F_75 ( struct V_1 * log , int V_77 , struct V_25 * * V_213 )
{
struct V_214 * V_214 ;
struct V_25 * V_26 ;
* V_213 = V_26 = F_32 ( log , V_77 ) ;
F_5 ( L_37 , V_26 , V_77 ) ;
V_26 -> V_116 |= V_215 ;
V_214 = F_105 ( V_216 , 1 ) ;
V_214 -> V_217 = V_26 -> V_208 << ( log -> V_166 - 9 ) ;
V_214 -> V_218 = log -> V_138 ;
V_214 -> V_219 [ 0 ] . V_220 = V_26 -> V_205 ;
V_214 -> V_219 [ 0 ] . V_221 = V_61 ;
V_214 -> V_219 [ 0 ] . V_222 = V_26 -> V_204 ;
V_214 -> V_223 = 1 ;
V_214 -> V_224 = 0 ;
V_214 -> V_225 = V_61 ;
V_214 -> V_226 = V_227 ;
V_214 -> V_228 = V_26 ;
F_106 ( V_229 , V_214 ) ;
F_107 ( V_26 -> V_206 , ( V_26 -> V_116 != V_215 ) ) ;
return 0 ;
}
static void F_30 ( struct V_1 * log , struct V_25 * V_26 , int V_45 ,
int V_230 )
{
struct V_25 * V_231 ;
unsigned long V_19 ;
F_5 ( L_38 , V_26 , V_45 , V_26 -> V_171 ) ;
V_26 -> V_208 =
log -> V_163 + ( V_26 -> V_171 << ( V_71 - log -> V_166 ) ) ;
F_98 ( V_19 ) ;
V_26 -> V_116 = V_45 ;
V_231 = log -> V_183 ;
if ( V_26 -> V_86 == NULL ) {
if ( V_231 == NULL ) {
log -> V_183 = V_26 ;
V_26 -> V_86 = V_26 ;
} else {
log -> V_183 = V_26 ;
V_26 -> V_86 = V_231 -> V_86 ;
V_231 -> V_86 = V_26 ;
}
V_231 = V_26 ;
}
if ( ( V_26 != V_231 -> V_86 ) || ! ( V_45 & V_89 ) ) {
F_100 ( V_19 ) ;
return;
}
F_100 ( V_19 ) ;
if ( V_230 )
F_103 ( V_26 ) ;
else if ( V_45 & V_179 )
F_108 ( V_26 ) ;
else {
F_25 ( log ) ;
F_108 ( V_26 ) ;
F_24 ( log ) ;
}
}
static void F_77 ( struct V_1 * log , struct V_25 * V_26 , int V_45 )
{
F_5 ( L_39 ,
V_26 , V_45 , V_26 -> V_171 ) ;
V_26 -> V_116 = V_45 | V_232 ;
V_26 -> V_208 =
log -> V_163 + ( V_26 -> V_171 << ( V_71 - log -> V_166 ) ) ;
F_108 ( V_26 ) ;
}
static void F_108 ( struct V_25 * V_26 )
{
struct V_214 * V_214 ;
struct V_1 * log = V_26 -> V_113 ;
F_5 ( L_40 ) ;
V_214 = F_105 ( V_216 , 1 ) ;
V_214 -> V_217 = V_26 -> V_208 << ( log -> V_166 - 9 ) ;
V_214 -> V_218 = log -> V_138 ;
V_214 -> V_219 [ 0 ] . V_220 = V_26 -> V_205 ;
V_214 -> V_219 [ 0 ] . V_221 = V_61 ;
V_214 -> V_219 [ 0 ] . V_222 = V_26 -> V_204 ;
V_214 -> V_223 = 1 ;
V_214 -> V_224 = 0 ;
V_214 -> V_225 = V_61 ;
V_214 -> V_226 = V_227 ;
V_214 -> V_228 = V_26 ;
if ( log -> V_168 ) {
V_214 -> V_225 = 0 ;
V_227 ( V_214 , 0 ) ;
} else {
F_106 ( V_233 , V_214 ) ;
F_23 ( V_74 . V_234 ) ;
}
}
static int F_76 ( struct V_25 * V_26 , int V_45 )
{
unsigned long V_19 ;
int V_93 = 0 ;
F_5 ( L_41 , V_26 , V_26 -> V_116 , V_45 ) ;
F_98 ( V_19 ) ;
F_99 ( V_26 -> V_206 , ( V_26 -> V_116 & V_235 ) , V_19 ) ;
V_93 = ( V_26 -> V_116 & V_117 ) ? - V_96 : 0 ;
if ( V_45 & V_91 )
F_101 ( V_26 ) ;
F_100 ( V_19 ) ;
F_5 ( L_42 , V_26 , V_26 -> V_116 , V_45 ) ;
return V_93 ;
}
static void V_227 ( struct V_214 * V_214 , int error )
{
struct V_25 * V_26 = V_214 -> V_228 ;
struct V_25 * V_80 , * V_231 ;
struct V_1 * log ;
unsigned long V_19 ;
F_5 ( L_43 , V_26 , V_26 -> V_116 ) ;
F_98 ( V_19 ) ;
V_26 -> V_116 |= V_235 ;
if ( ! F_35 ( V_236 , & V_214 -> V_237 ) ) {
V_26 -> V_116 |= V_117 ;
F_18 ( L_44 ) ;
}
F_109 ( V_214 ) ;
if ( V_26 -> V_116 & V_215 ) {
V_26 -> V_116 &= ~ V_215 ;
F_100 ( V_19 ) ;
F_110 ( & V_26 -> V_206 ) ;
return;
}
V_26 -> V_116 &= ~ V_89 ;
F_23 ( V_74 . V_238 ) ;
log = V_26 -> V_113 ;
log -> V_73 = ( V_26 -> V_171 << V_71 ) + V_26 -> V_87 ;
if ( V_26 -> V_116 & V_232 ) {
F_110 ( & V_26 -> V_206 ) ;
F_100 ( V_19 ) ;
return;
}
V_231 = log -> V_183 ;
if ( V_26 == V_231 ) {
if ( V_26 -> V_116 & V_90 ) {
log -> V_183 = NULL ;
V_26 -> V_86 = NULL ;
}
}
else {
if ( V_26 -> V_116 & V_90 ) {
V_80 = V_231 -> V_86 = V_26 -> V_86 ;
V_26 -> V_86 = NULL ;
if ( V_80 -> V_116 & V_89 ) {
F_103 ( V_80 ) ;
}
}
}
if ( V_26 -> V_116 & V_179 ) {
F_100 ( V_19 ) ;
F_110 ( & V_26 -> V_206 ) ;
}
else if ( V_26 -> V_116 & V_110 ) {
F_100 ( V_19 ) ;
F_37 ( V_26 ) ;
}
else {
assert ( V_26 -> V_116 & V_90 ) ;
assert ( V_26 -> V_116 & V_91 ) ;
F_101 ( V_26 ) ;
F_100 ( V_19 ) ;
}
}
int F_111 ( void * V_239 )
{
struct V_25 * V_26 ;
do {
F_112 ( & V_209 ) ;
while ( ( V_26 = V_211 ) ) {
V_211 = V_26 -> V_210 ;
V_26 -> V_210 = NULL ;
F_113 ( & V_209 ) ;
F_108 ( V_26 ) ;
F_112 ( & V_209 ) ;
}
if ( F_114 ( V_188 ) ) {
F_113 ( & V_209 ) ;
F_115 () ;
} else {
F_83 ( V_240 ) ;
F_113 ( & V_209 ) ;
F_84 () ;
F_85 ( V_190 ) ;
}
} while ( ! F_116 () );
F_5 ( L_45 ) ;
return 0 ;
}
int F_117 ( struct V_1 * log , T_3 V_241 , int V_242 )
{
int V_93 = - V_96 ;
struct V_3 * V_4 ;
struct V_169 * V_169 ;
struct V_27 * V_28 ;
int V_79 ;
struct V_11 * V_243 ;
int V_244 = 0 ;
struct V_25 * V_26 ;
F_5 ( L_46 ,
( long long ) V_241 , V_242 ) ;
V_4 = F_29 ( log -> V_151 . V_66 , struct V_3 , V_160 ) ;
V_26 = F_32 ( log , 1 ) ;
V_244 = V_242 >> V_4 -> V_245 ;
V_169 = (struct V_169 * ) V_26 -> V_42 ;
V_169 -> V_173 = F_33 ( V_174 ) ;
V_169 -> V_246 = F_33 ( V_247 ) ;
V_169 -> V_176 = F_33 ( V_177 ) ;
V_169 -> V_45 = F_33 ( V_4 -> V_140 ) ;
V_169 -> V_92 = F_33 ( V_244 ) ;
V_169 -> V_248 = F_33 ( V_4 -> V_248 ) ;
V_169 -> V_166 = F_33 ( V_4 -> V_166 ) ;
V_169 -> V_178 = F_33 ( 2 * V_61 + V_63 + V_67 ) ;
V_26 -> V_116 = V_89 | V_179 | V_232 ;
V_26 -> V_208 = V_241 + V_4 -> V_249 ;
F_108 ( V_26 ) ;
if ( ( V_93 = F_76 ( V_26 , 0 ) ) )
goto exit;
V_28 = (struct V_27 * ) V_26 -> V_42 ;
V_28 -> V_81 . V_70 = V_28 -> V_88 . V_70 = F_33 ( V_244 - 3 ) ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_63 + V_67 ) ;
V_243 = (struct V_11 * ) & V_28 -> V_47 ;
V_243 -> V_130 = 0 ;
V_243 -> V_131 = 0 ;
V_243 -> type = F_21 ( V_132 ) ;
V_243 -> V_60 = 0 ;
V_243 -> log . V_129 . V_128 = 0 ;
V_26 -> V_208 += V_4 -> V_249 ;
V_26 -> V_116 = V_89 | V_179 | V_232 ;
F_108 ( V_26 ) ;
if ( ( V_93 = F_76 ( V_26 , 0 ) ) )
goto exit;
for ( V_79 = 0 ; V_79 < V_244 - 3 ; V_79 ++ ) {
V_28 -> V_81 . V_70 = V_28 -> V_88 . V_70 = F_33 ( V_79 ) ;
V_28 -> V_81 . V_43 = V_28 -> V_88 . V_43 = F_21 ( V_63 ) ;
V_26 -> V_208 += V_4 -> V_249 ;
V_26 -> V_116 = V_89 | V_179 | V_232 ;
F_108 ( V_26 ) ;
if ( ( V_93 = F_76 ( V_26 , 0 ) ) )
goto exit;
}
V_93 = 0 ;
exit:
F_44 ( V_26 ) ;
return V_93 ;
}
static int F_118 ( struct V_250 * V_251 , void * V_252 )
{
F_119 ( V_251 ,
L_47
L_48
L_49
L_50
L_51
L_52
L_53 ,
V_74 . V_75 ,
V_74 . V_234 ,
V_74 . V_238 ,
V_74 . V_111 ,
V_74 . V_112 ) ;
return 0 ;
}
static int F_120 ( struct V_253 * V_253 , struct V_254 * V_254 )
{
return F_121 ( V_254 , F_118 , NULL ) ;
}
