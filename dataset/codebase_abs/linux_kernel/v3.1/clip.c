static int F_1 ( enum V_1 type , int V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_2 ( L_1 , type ) ;
if ( ! V_10 )
return - V_11 ;
V_9 = F_3 ( sizeof( struct V_6 ) , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
V_7 = (struct V_6 * ) F_4 ( V_9 , sizeof( struct V_6 ) ) ;
V_7 -> type = type ;
V_7 -> V_14 = V_2 ;
V_7 -> V_3 = V_3 ;
F_5 ( V_10 , V_9 -> V_15 ) ;
V_5 = F_6 ( V_10 ) ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
V_5 -> V_17 ( V_5 , V_9 -> V_18 ) ;
return 0 ;
}
static void F_8 ( struct V_19 * V_19 , struct V_20 * V_21 )
{
F_2 ( L_2 , V_19 , V_21 , V_21 -> V_22 ) ;
V_19 -> V_21 = V_21 ;
V_19 -> V_23 = 0 ;
V_19 -> V_24 = V_21 -> V_25 ;
V_21 -> V_25 = V_19 ;
V_21 -> V_22 -> V_26 = V_27 ;
}
static void F_9 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_19 * * V_28 ;
if ( ! V_21 ) {
F_10 ( L_3 , V_19 ) ;
return;
}
F_11 ( V_21 -> V_22 -> V_29 ) ;
V_21 -> V_22 -> V_26 = V_27 ;
for ( V_28 = & V_21 -> V_25 ; * V_28 ; V_28 = & ( * V_28 ) -> V_24 )
if ( * V_28 == V_19 ) {
int error ;
* V_28 = V_19 -> V_24 ;
V_19 -> V_21 = NULL ;
if ( V_19 -> V_23 )
F_12 ( V_21 -> V_22 -> V_29 ) ;
if ( V_21 -> V_25 )
goto V_30;
V_21 -> V_31 = V_27 - 1 ;
error = F_13 ( V_21 -> V_22 , NULL , V_32 ,
V_33 ) ;
if ( error )
F_10 ( L_4 , error ) ;
goto V_30;
}
F_10 ( L_5 , V_21 , V_19 ) ;
V_30:
F_14 ( V_21 -> V_22 -> V_29 ) ;
}
static int F_15 ( struct V_34 * V_35 )
{
struct V_20 * V_21 = F_16 ( V_35 ) ;
struct V_19 * V_36 ;
for ( V_36 = V_21 -> V_25 ; V_36 ; V_36 = V_36 -> V_24 ) {
unsigned long exp = V_36 -> V_37 + V_36 -> V_38 ;
if ( V_36 -> V_38 && F_17 ( V_27 , exp ) ) {
F_2 ( L_6 ,
V_36 , V_36 -> V_39 , V_21 ) ;
F_18 ( V_36 -> V_39 , - V_40 ) ;
}
}
if ( V_21 -> V_25 || F_19 ( V_27 , V_21 -> V_31 ) )
return 0 ;
if ( F_20 ( & V_35 -> V_41 ) > 1 ) {
struct V_8 * V_9 ;
F_2 ( L_7 ,
F_20 ( & V_35 -> V_41 ) ) ;
while ( ( V_9 = F_21 ( & V_35 -> V_42 ) ) != NULL )
F_22 ( V_9 ) ;
return 0 ;
}
F_2 ( L_8 , V_35 ) ;
return 1 ;
}
static void F_23 ( unsigned long V_43 )
{
F_24 ( & V_44 . V_45 ) ;
F_25 ( & V_44 , F_15 ) ;
F_26 ( & V_46 , V_27 + V_47 * V_48 ) ;
F_27 ( & V_44 . V_45 ) ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_49 * V_39 ;
F_2 ( L_9 ) ;
V_39 = F_29 ( V_9 ) -> V_39 ;
if ( ! V_39 || ! F_30 ( V_39 , V_9 -> V_15 ) ) {
F_31 ( V_9 ) ;
return 0 ;
}
F_2 ( L_10 , V_39 ) ;
F_2 ( L_11 , F_32 ( V_39 ) -> V_50 ) ;
F_32 ( V_39 ) -> V_50 ( V_39 , V_9 ) ;
return 0 ;
}
static void F_33 ( struct V_49 * V_39 , struct V_8 * V_9 )
{
struct V_19 * V_19 = F_32 ( V_39 ) ;
F_2 ( L_9 ) ;
if ( ! V_9 ) {
F_2 ( L_12 , V_19 ) ;
if ( V_19 -> V_21 )
F_9 ( V_19 ) ;
V_19 -> V_50 ( V_39 , NULL ) ;
F_34 ( V_19 ) ;
return;
}
F_35 ( V_39 , V_9 -> V_15 ) ;
V_9 -> V_29 = V_19 -> V_21 ? V_19 -> V_21 -> V_22 -> V_29 : V_51 ;
if ( ! V_9 -> V_29 ) {
F_31 ( V_9 ) ;
return;
}
F_29 ( V_9 ) -> V_39 = V_39 ;
F_36 ( V_9 ) ;
if ( ! V_19 -> V_52 ||
V_9 -> V_18 < V_53 ||
memcmp ( V_9 -> V_54 , V_55 , sizeof( V_55 ) ) )
V_9 -> V_56 = F_37 ( V_57 ) ;
else {
V_9 -> V_56 = ( ( V_58 * ) V_9 -> V_54 ) [ 3 ] ;
F_38 ( V_9 , V_53 ) ;
if ( V_9 -> V_56 == F_37 ( V_59 ) ) {
V_9 -> V_29 -> V_60 . V_61 ++ ;
V_9 -> V_29 -> V_60 . V_62 += V_9 -> V_18 ;
F_28 ( V_9 ) ;
return;
}
}
V_19 -> V_37 = V_27 ;
V_9 -> V_29 -> V_60 . V_61 ++ ;
V_9 -> V_29 -> V_60 . V_62 += V_9 -> V_18 ;
memset ( F_29 ( V_9 ) , 0 , sizeof( struct V_63 ) ) ;
F_39 ( V_9 ) ;
}
static void F_40 ( struct V_49 * V_39 , struct V_8 * V_9 )
{
struct V_19 * V_19 = F_32 ( V_39 ) ;
struct V_64 * V_29 = V_9 -> V_29 ;
int V_65 ;
unsigned long V_66 ;
F_2 ( L_13 , V_39 ) ;
V_19 -> V_67 ( V_39 , V_9 ) ;
if ( ! V_29 )
return;
F_41 ( & F_42 ( V_29 ) -> V_68 , V_66 ) ;
if ( F_43 ( V_39 , 0 ) ) {
V_65 = F_44 ( & V_19 -> V_23 , 0 ) ;
if ( V_65 )
F_12 ( V_29 ) ;
}
F_45 ( & F_42 ( V_29 ) -> V_68 , V_66 ) ;
}
static void F_46 ( struct V_34 * V_22 , struct V_8 * V_9 )
{
F_2 ( L_14 , V_22 , V_9 ) ;
F_1 ( V_69 , F_42 ( V_22 -> V_29 ) -> V_70 , F_16 ( V_22 ) -> V_3 ) ;
}
static void F_47 ( struct V_34 * V_22 , struct V_8 * V_9 )
{
#ifndef F_48
F_49 ( V_9 , V_71 , V_72 , 0 ) ;
#endif
F_50 ( V_9 ) ;
}
static int F_51 ( struct V_34 * V_22 )
{
struct V_20 * V_21 = F_16 ( V_22 ) ;
struct V_64 * V_29 = V_22 -> V_29 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_2 ( L_15 , V_22 , V_21 ) ;
V_22 -> type = F_52 ( & V_77 , V_21 -> V_3 ) ;
if ( V_22 -> type != V_78 )
return - V_79 ;
F_53 () ;
V_74 = F_54 ( V_29 ) ;
if ( ! V_74 ) {
F_55 () ;
return - V_79 ;
}
V_76 = V_74 -> V_80 ;
F_56 ( V_22 -> V_76 ) ;
V_22 -> V_76 = F_57 ( V_76 ) ;
F_55 () ;
V_22 -> V_81 = & V_82 ;
V_22 -> V_83 = V_22 -> V_84 & V_85 ?
V_22 -> V_81 -> V_86 : V_22 -> V_81 -> V_83 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_25 = NULL ;
V_21 -> V_31 = V_27 - 1 ;
return 0 ;
}
static T_2 F_58 ( const void * V_87 , const struct V_64 * V_29 , T_3 V_88 )
{
return F_59 ( * ( T_2 * ) V_87 , V_29 -> V_89 , V_88 ) ;
}
static int F_60 ( struct V_49 * V_39 , int V_90 )
{
F_32 ( V_39 ) -> V_52 = V_90 ;
return 0 ;
}
static T_4 F_61 ( struct V_8 * V_9 ,
struct V_64 * V_29 )
{
struct V_91 * V_91 = F_42 ( V_29 ) ;
struct V_92 * V_93 = F_62 ( V_9 ) ;
struct V_20 * V_21 ;
struct V_34 * V_35 ;
struct V_49 * V_39 ;
int V_65 ;
unsigned long V_66 ;
F_2 ( L_16 , V_9 ) ;
if ( ! V_93 ) {
F_63 ( L_17 ) ;
F_22 ( V_9 ) ;
V_29 -> V_60 . V_94 ++ ;
return V_95 ;
}
V_35 = F_64 ( V_93 ) ;
if ( ! V_35 ) {
#if 0
n = clip_find_neighbour(skb_dst(skb), 1);
if (!n) {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return 0;
}
dst_set_neighbour(dst, n);
#endif
F_63 ( L_18 ) ;
F_22 ( V_9 ) ;
V_29 -> V_60 . V_94 ++ ;
return V_95 ;
}
V_21 = F_16 ( V_35 ) ;
if ( ! V_21 -> V_25 ) {
if ( F_17 ( V_27 , V_21 -> V_31 ) ) {
V_21 -> V_31 = V_27 + V_96 * V_48 ;
F_1 ( V_69 , F_42 ( V_29 ) -> V_70 , V_21 -> V_3 ) ;
}
if ( V_21 -> V_22 -> V_42 . V_97 < V_98 )
F_7 ( & V_21 -> V_22 -> V_42 , V_9 ) ;
else {
F_22 ( V_9 ) ;
V_29 -> V_60 . V_94 ++ ;
}
return V_95 ;
}
F_2 ( L_19 , V_21 , V_21 -> V_25 ) ;
F_29 ( V_9 ) -> V_39 = V_39 = V_21 -> V_25 -> V_39 ;
F_2 ( L_20 , V_35 , V_39 ) ;
if ( V_21 -> V_25 -> V_52 ) {
void * V_99 ;
V_99 = F_65 ( V_9 , V_53 ) ;
memcpy ( V_99 , V_55 , sizeof( V_55 ) ) ;
( ( V_58 * ) V_99 ) [ 3 ] = V_9 -> V_56 ;
}
F_66 ( V_9 -> V_15 , & F_6 ( V_39 ) -> V_100 ) ;
F_29 ( V_9 ) -> V_101 = V_39 -> V_101 ;
V_21 -> V_25 -> V_37 = V_27 ;
F_2 ( L_21 , V_9 , V_39 , V_39 -> V_29 ) ;
V_65 = F_44 ( & V_21 -> V_25 -> V_23 , 1 ) ;
if ( V_65 ) {
F_67 ( L_22 ) ;
return V_95 ;
}
V_29 -> V_60 . V_102 ++ ;
V_29 -> V_60 . V_103 += V_9 -> V_18 ;
V_39 -> V_104 ( V_39 , V_9 ) ;
if ( F_43 ( V_39 , 0 ) ) {
V_21 -> V_25 -> V_23 = 0 ;
return V_95 ;
}
F_41 ( & V_91 -> V_68 , V_66 ) ;
F_68 ( V_29 ) ;
F_69 () ;
if ( ! V_21 -> V_25 -> V_23 )
F_70 ( V_29 ) ;
F_45 ( & V_91 -> V_68 , V_66 ) ;
return V_95 ;
}
static int F_71 ( struct V_49 * V_39 , int V_105 )
{
struct V_106 * V_107 , V_108 ;
struct V_19 * V_19 ;
struct V_8 * V_9 , * V_109 ;
unsigned long V_66 ;
if ( ! V_39 -> V_110 )
return - V_111 ;
V_19 = F_72 ( sizeof( struct V_19 ) , V_112 ) ;
if ( ! V_19 )
return - V_13 ;
F_2 ( L_23 , V_19 , V_39 ) ;
V_19 -> V_39 = V_39 ;
V_39 -> V_113 = V_19 ;
F_73 ( V_114 , & V_39 -> V_66 ) ;
V_19 -> V_21 = NULL ;
V_19 -> V_23 = 0 ;
V_19 -> V_52 = 1 ;
V_19 -> V_37 = V_27 ;
V_19 -> V_38 = V_105 * V_48 ;
V_19 -> V_50 = V_39 -> V_110 ;
V_19 -> V_67 = V_39 -> V_115 ;
V_39 -> V_110 = F_33 ;
V_39 -> V_115 = F_40 ;
F_74 ( & V_108 ) ;
V_107 = & F_6 ( V_39 ) -> V_16 ;
F_41 ( & V_107 -> V_45 , V_66 ) ;
F_75 ( V_107 , & V_108 ) ;
F_45 ( & V_107 -> V_45 , V_66 ) ;
F_76 (&queue, skb, tmp) {
if ( ! V_51 ) {
F_35 ( V_39 , V_9 -> V_15 ) ;
F_50 ( V_9 ) ;
} else {
struct V_64 * V_29 = V_9 -> V_29 ;
unsigned int V_18 = V_9 -> V_18 ;
F_77 ( V_9 ) ;
F_33 ( V_39 , V_9 ) ;
V_29 -> V_60 . V_61 -- ;
V_29 -> V_60 . V_62 -= V_18 ;
F_50 ( V_9 ) ;
}
}
return 0 ;
}
static int F_78 ( struct V_49 * V_39 , T_1 V_3 )
{
struct V_34 * V_22 ;
struct V_20 * V_21 ;
int error ;
struct V_19 * V_19 ;
struct V_116 * V_117 ;
if ( V_39 -> V_110 != F_33 ) {
F_67 ( L_24 ) ;
return - V_118 ;
}
V_19 = F_32 ( V_39 ) ;
if ( ! V_3 ) {
if ( ! V_19 -> V_21 ) {
F_63 ( L_25 ) ;
return 0 ;
}
F_2 ( L_26 ) ;
F_9 ( V_19 ) ;
return 0 ;
}
V_117 = F_79 ( & V_77 , V_3 , 0 , 1 , 0 ) ;
if ( F_80 ( V_117 ) )
return F_81 ( V_117 ) ;
V_22 = F_82 ( & V_44 , & V_3 , V_117 -> V_93 . V_29 , 1 ) ;
F_83 ( V_117 ) ;
if ( ! V_22 )
return - V_13 ;
V_21 = F_16 ( V_22 ) ;
if ( V_21 != V_19 -> V_21 ) {
if ( ! V_19 -> V_21 )
F_2 ( L_27 ) ;
else {
F_2 ( L_28 ) ;
F_9 ( V_19 ) ;
}
F_8 ( V_19 , V_21 ) ;
}
error = F_13 ( V_22 , V_55 , V_119 ,
V_120 | V_33 ) ;
F_84 ( V_22 ) ;
return error ;
}
static void F_85 ( struct V_64 * V_29 )
{
V_29 -> V_121 = & V_122 ;
V_29 -> type = V_123 ;
V_29 -> V_124 = V_53 ;
V_29 -> V_125 = V_126 ;
V_29 -> V_127 = 100 ;
V_29 -> V_128 &= ~ V_129 ;
}
static int F_86 ( int V_70 )
{
struct V_64 * V_29 ;
struct V_91 * V_91 ;
int error ;
if ( V_70 != - 1 ) {
for ( V_29 = V_51 ; V_29 ; V_29 = F_42 ( V_29 ) -> V_24 )
if ( F_42 ( V_29 ) -> V_70 == V_70 )
return - V_130 ;
} else {
V_70 = 0 ;
for ( V_29 = V_51 ; V_29 ; V_29 = F_42 ( V_29 ) -> V_24 )
if ( F_42 ( V_29 ) -> V_70 >= V_70 )
V_70 = F_42 ( V_29 ) -> V_70 + 1 ;
}
V_29 = F_87 ( sizeof( struct V_91 ) , L_29 , F_85 ) ;
if ( ! V_29 )
return - V_13 ;
V_91 = F_42 ( V_29 ) ;
sprintf ( V_29 -> V_131 , L_30 , V_70 ) ;
F_88 ( & V_91 -> V_68 ) ;
V_91 -> V_70 = V_70 ;
error = F_89 ( V_29 ) ;
if ( error ) {
F_90 ( V_29 ) ;
return error ;
}
V_91 -> V_24 = V_51 ;
V_51 = V_29 ;
F_2 ( L_31 , V_29 -> V_131 ) ;
return V_70 ;
}
static int F_91 ( struct V_132 * V_133 , unsigned long V_134 ,
void * V_135 )
{
struct V_64 * V_29 = V_135 ;
if ( ! F_92 ( F_93 ( V_29 ) , & V_77 ) )
return V_136 ;
if ( V_134 == V_137 ) {
F_94 ( & V_44 , V_29 ) ;
return V_136 ;
}
if ( V_29 -> type != V_123 || V_29 -> V_121 != & V_122 )
return V_136 ;
switch ( V_134 ) {
case V_138 :
F_2 ( L_32 ) ;
F_1 ( V_139 , F_42 ( V_29 ) -> V_70 , 0 ) ;
break;
case V_140 :
F_2 ( L_33 ) ;
F_1 ( V_141 , F_42 ( V_29 ) -> V_70 , 0 ) ;
break;
case V_142 :
case V_143 :
F_2 ( L_34 ) ;
F_1 ( V_144 , F_42 ( V_29 ) -> V_70 , 0 ) ;
break;
}
return V_136 ;
}
static int F_95 ( struct V_132 * V_133 , unsigned long V_134 ,
void * V_145 )
{
struct V_73 * V_74 ;
V_74 = ( (struct V_146 * ) V_145 ) -> V_147 ;
if ( V_134 != V_138 )
return V_136 ;
return F_91 ( V_133 , V_142 , V_74 -> V_29 ) ;
}
static void F_96 ( struct V_49 * V_39 )
{
F_2 ( L_9 ) ;
F_97 () ;
V_10 = NULL ;
F_98 ( & F_6 ( V_39 ) -> V_16 ) ;
F_99 () ;
F_2 ( L_35 ) ;
F_100 ( V_148 ) ;
}
static int F_101 ( struct V_49 * V_39 )
{
F_97 () ;
if ( V_10 ) {
F_99 () ;
return - V_149 ;
}
F_26 ( & V_46 , V_27 + V_47 * V_48 ) ;
V_10 = V_39 ;
F_73 ( V_150 , & V_39 -> V_66 ) ;
F_73 ( V_151 , & V_39 -> V_66 ) ;
V_39 -> V_29 = & V_152 ;
F_102 ( F_6 ( V_39 ) ) ;
V_39 -> V_110 = NULL ;
V_39 -> V_115 = NULL ;
V_39 -> V_153 = NULL ;
F_99 () ;
return 0 ;
}
static int F_103 ( struct V_154 * V_4 , unsigned int V_155 , unsigned long V_135 )
{
struct V_49 * V_39 = F_104 ( V_4 ) ;
int V_156 = 0 ;
switch ( V_155 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
if ( ! F_105 ( V_162 ) )
return - V_163 ;
break;
default:
return - V_164 ;
}
switch ( V_155 ) {
case V_157 :
V_156 = F_86 ( V_135 ) ;
break;
case V_158 :
V_156 = F_101 ( V_39 ) ;
if ( ! V_156 ) {
V_4 -> V_165 = V_166 ;
F_106 ( V_148 ) ;
}
break;
case V_159 :
V_156 = F_71 ( V_39 , V_135 ) ;
break;
case V_160 :
V_156 = F_78 ( V_39 , ( V_167 T_1 ) V_135 ) ;
break;
case V_161 :
V_156 = F_60 ( V_39 , V_135 ) ;
break;
}
return V_156 ;
}
static void F_107 ( struct V_168 * V_169 , struct V_170 * V_171 )
{
static int V_172 [] = { 1 , 2 , 10 , 6 , 1 , 0 } ;
static int V_173 [] = { 1 , 8 , 4 , 6 , 1 , 0 } ;
if ( * V_171 -> V_174 . V_175 ) {
F_108 ( V_169 , L_36 , V_171 -> V_174 . V_175 ) ;
if ( * V_171 -> V_174 . V_176 )
F_109 ( V_169 , '+' ) ;
} else if ( ! * V_171 -> V_174 . V_176 ) {
F_108 ( V_169 , L_36 , L_37 ) ;
return;
}
if ( * V_171 -> V_174 . V_176 ) {
unsigned char * V_176 = V_171 -> V_174 . V_176 ;
int * V_177 ;
int V_178 , V_179 ;
V_177 = * V_176 == V_180 ? V_173 : V_172 ;
for ( V_178 = 0 ; V_177 [ V_178 ] ; V_178 ++ ) {
for ( V_179 = V_177 [ V_178 ] ; V_179 ; V_179 -- )
F_108 ( V_169 , L_38 , * V_176 ++ ) ;
if ( V_177 [ V_178 + 1 ] )
F_109 ( V_169 , '.' ) ;
}
}
}
static void F_110 ( struct V_168 * V_169 , struct V_64 * V_29 ,
struct V_20 * V_21 , struct V_19 * V_19 )
{
unsigned long exp ;
char V_181 [ 17 ] ;
int V_182 , V_183 , V_184 ;
V_182 = ( ( V_19 == V_185 ) ||
( F_6 ( V_19 -> V_39 ) -> V_186 == V_187 ) ) ;
V_183 = ( ( V_19 == V_185 ) || V_19 -> V_52 ) ;
if ( V_19 == V_185 )
exp = V_21 -> V_22 -> V_26 ;
else
exp = V_19 -> V_37 ;
exp = ( V_27 - exp ) / V_48 ;
F_108 ( V_169 , L_39 ,
V_29 -> V_131 , V_182 ? L_40 : L_41 , V_183 ? L_42 : L_43 , exp ) ;
V_184 = F_111 ( V_181 , sizeof( V_181 ) - 1 , L_44 ,
& V_21 -> V_3 ) ;
while ( V_184 < 16 )
V_181 [ V_184 ++ ] = ' ' ;
V_181 [ V_184 ] = '\0' ;
F_108 ( V_169 , L_36 , V_181 ) ;
if ( V_19 == V_185 ) {
if ( F_19 ( V_27 , V_21 -> V_31 ) )
F_108 ( V_169 , L_45 ) ;
else
F_108 ( V_169 , L_46 ,
F_20 ( & V_21 -> V_22 -> V_41 ) ) ;
} else if ( ! V_182 ) {
F_108 ( V_169 , L_47 ,
V_19 -> V_39 -> V_29 -> V_70 ,
V_19 -> V_39 -> V_188 , V_19 -> V_39 -> V_189 ) ;
} else {
F_107 ( V_169 , & V_19 -> V_39 -> V_190 ) ;
F_109 ( V_169 , '\n' ) ;
}
}
static struct V_19 * F_112 ( struct V_20 * V_191 ,
struct V_19 * V_192 )
{
if ( ! V_192 ) {
V_192 = V_191 -> V_25 ;
if ( ! V_192 )
return V_185 ;
return V_192 ;
}
if ( V_192 == V_185 )
return NULL ;
V_192 = V_192 -> V_24 ;
return V_192 ;
}
static void * F_113 ( struct V_193 * V_165 ,
struct V_20 * V_191 , T_5 * V_194 )
{
struct V_19 * V_39 = V_165 -> V_39 ;
V_39 = F_112 ( V_191 , V_39 ) ;
if ( V_39 && V_194 != NULL ) {
while ( * V_194 ) {
V_39 = F_112 ( V_191 , V_39 ) ;
if ( ! V_39 )
break;
-- ( * V_194 ) ;
}
}
V_165 -> V_39 = V_39 ;
return V_39 ;
}
static void * F_114 ( struct V_195 * V_196 ,
struct V_34 * V_35 , T_5 * V_194 )
{
struct V_193 * V_165 = (struct V_193 * ) V_196 ;
return F_113 ( V_165 , F_16 ( V_35 ) , V_194 ) ;
}
static void * F_115 ( struct V_168 * V_169 , T_5 * V_194 )
{
struct V_193 * V_165 = V_169 -> V_197 ;
V_165 -> V_198 . V_199 = F_114 ;
return F_116 ( V_169 , V_194 , & V_44 , V_200 ) ;
}
static int F_117 ( struct V_168 * V_169 , void * V_201 )
{
static char V_202 [] =
L_48 ;
if ( V_201 == V_203 ) {
F_118 ( V_169 , V_202 ) ;
} else {
struct V_193 * V_165 = V_169 -> V_197 ;
struct V_34 * V_35 = V_201 ;
struct V_19 * V_39 = V_165 -> V_39 ;
F_110 ( V_169 , V_35 -> V_29 , F_16 ( V_35 ) , V_39 ) ;
}
return 0 ;
}
static int F_119 ( struct V_204 * V_204 , struct V_205 * V_205 )
{
return F_120 ( V_204 , V_205 , & V_206 ,
sizeof( struct V_193 ) ) ;
}
static int T_6 F_121 ( void )
{
F_122 ( & V_44 ) ;
V_207 = & V_44 ;
F_123 ( & V_208 ) ;
F_124 ( & V_209 ) ;
F_125 ( & V_210 ) ;
F_126 ( & V_46 , F_23 , 0 ) ;
#ifdef F_127
{
struct V_211 * V_212 ;
V_212 = F_128 ( L_49 , V_213 , V_214 , & V_215 ) ;
if ( ! V_212 ) {
F_63 ( L_50 ) ;
F_129 () ;
return - V_13 ;
}
}
#endif
return 0 ;
}
static void F_129 ( void )
{
struct V_64 * V_29 , * V_24 ;
F_130 ( & V_210 ) ;
F_131 ( & V_209 ) ;
F_132 ( & V_208 ) ;
F_133 ( & V_46 ) ;
F_94 ( & V_44 , NULL ) ;
V_29 = V_51 ;
while ( V_29 ) {
V_24 = F_42 ( V_29 ) -> V_24 ;
F_134 ( V_29 ) ;
F_90 ( V_29 ) ;
V_29 = V_24 ;
}
F_135 ( & V_44 ) ;
V_207 = NULL ;
}
static void T_7 F_136 ( void )
{
F_137 ( L_49 , V_214 ) ;
F_129 () ;
}
