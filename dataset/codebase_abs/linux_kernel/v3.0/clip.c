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
struct V_20 * V_21 ;
struct V_49 * V_39 ;
int V_65 ;
unsigned long V_66 ;
F_2 ( L_16 , V_9 ) ;
if ( ! F_62 ( V_9 ) ) {
F_63 ( L_17 ) ;
F_22 ( V_9 ) ;
V_29 -> V_60 . V_92 ++ ;
return V_93 ;
}
if ( ! F_62 ( V_9 ) -> V_34 ) {
#if 0
skb_dst(skb)->neighbour = clip_find_neighbour(skb_dst(skb), 1);
if (!skb_dst(skb)->neighbour) {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return 0;
}
#endif
F_63 ( L_18 ) ;
F_22 ( V_9 ) ;
V_29 -> V_60 . V_92 ++ ;
return V_93 ;
}
V_21 = F_16 ( F_62 ( V_9 ) -> V_34 ) ;
if ( ! V_21 -> V_25 ) {
if ( F_17 ( V_27 , V_21 -> V_31 ) ) {
V_21 -> V_31 = V_27 + V_94 * V_48 ;
F_1 ( V_69 , F_42 ( V_29 ) -> V_70 , V_21 -> V_3 ) ;
}
if ( V_21 -> V_22 -> V_42 . V_95 < V_96 )
F_7 ( & V_21 -> V_22 -> V_42 , V_9 ) ;
else {
F_22 ( V_9 ) ;
V_29 -> V_60 . V_92 ++ ;
}
return V_93 ;
}
F_2 ( L_19 , V_21 , V_21 -> V_25 ) ;
F_29 ( V_9 ) -> V_39 = V_39 = V_21 -> V_25 -> V_39 ;
F_2 ( L_20 , F_62 ( V_9 ) -> V_34 , V_39 ) ;
if ( V_21 -> V_25 -> V_52 ) {
void * V_97 ;
V_97 = F_64 ( V_9 , V_53 ) ;
memcpy ( V_97 , V_55 , sizeof( V_55 ) ) ;
( ( V_58 * ) V_97 ) [ 3 ] = V_9 -> V_56 ;
}
F_65 ( V_9 -> V_15 , & F_6 ( V_39 ) -> V_98 ) ;
F_29 ( V_9 ) -> V_99 = V_39 -> V_99 ;
V_21 -> V_25 -> V_37 = V_27 ;
F_2 ( L_21 , V_9 , V_39 , V_39 -> V_29 ) ;
V_65 = F_44 ( & V_21 -> V_25 -> V_23 , 1 ) ;
if ( V_65 ) {
F_66 ( L_22 ) ;
return V_93 ;
}
V_29 -> V_60 . V_100 ++ ;
V_29 -> V_60 . V_101 += V_9 -> V_18 ;
V_39 -> V_102 ( V_39 , V_9 ) ;
if ( F_43 ( V_39 , 0 ) ) {
V_21 -> V_25 -> V_23 = 0 ;
return V_93 ;
}
F_41 ( & V_91 -> V_68 , V_66 ) ;
F_67 ( V_29 ) ;
F_68 () ;
if ( ! V_21 -> V_25 -> V_23 )
F_69 ( V_29 ) ;
F_45 ( & V_91 -> V_68 , V_66 ) ;
return V_93 ;
}
static int F_70 ( struct V_49 * V_39 , int V_103 )
{
struct V_104 * V_105 , V_106 ;
struct V_19 * V_19 ;
struct V_8 * V_9 , * V_107 ;
unsigned long V_66 ;
if ( ! V_39 -> V_108 )
return - V_109 ;
V_19 = F_71 ( sizeof( struct V_19 ) , V_110 ) ;
if ( ! V_19 )
return - V_13 ;
F_2 ( L_23 , V_19 , V_39 ) ;
V_19 -> V_39 = V_39 ;
V_39 -> V_111 = V_19 ;
F_72 ( V_112 , & V_39 -> V_66 ) ;
V_19 -> V_21 = NULL ;
V_19 -> V_23 = 0 ;
V_19 -> V_52 = 1 ;
V_19 -> V_37 = V_27 ;
V_19 -> V_38 = V_103 * V_48 ;
V_19 -> V_50 = V_39 -> V_108 ;
V_19 -> V_67 = V_39 -> V_113 ;
V_39 -> V_108 = F_33 ;
V_39 -> V_113 = F_40 ;
F_73 ( & V_106 ) ;
V_105 = & F_6 ( V_39 ) -> V_16 ;
F_41 ( & V_105 -> V_45 , V_66 ) ;
F_74 ( V_105 , & V_106 ) ;
F_45 ( & V_105 -> V_45 , V_66 ) ;
F_75 (&queue, skb, tmp) {
if ( ! V_51 ) {
F_35 ( V_39 , V_9 -> V_15 ) ;
F_50 ( V_9 ) ;
} else {
struct V_64 * V_29 = V_9 -> V_29 ;
unsigned int V_18 = V_9 -> V_18 ;
F_76 ( V_9 ) ;
F_33 ( V_39 , V_9 ) ;
V_29 -> V_60 . V_61 -- ;
V_29 -> V_60 . V_62 -= V_18 ;
F_50 ( V_9 ) ;
}
}
return 0 ;
}
static int F_77 ( struct V_49 * V_39 , T_1 V_3 )
{
struct V_34 * V_22 ;
struct V_20 * V_21 ;
int error ;
struct V_19 * V_19 ;
struct V_114 * V_115 ;
if ( V_39 -> V_108 != F_33 ) {
F_66 ( L_24 ) ;
return - V_116 ;
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
V_115 = F_78 ( & V_77 , V_3 , 0 , 1 , 0 ) ;
if ( F_79 ( V_115 ) )
return F_80 ( V_115 ) ;
V_22 = F_81 ( & V_44 , & V_3 , V_115 -> V_117 . V_29 , 1 ) ;
F_82 ( V_115 ) ;
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
error = F_13 ( V_22 , V_55 , V_118 ,
V_119 | V_33 ) ;
F_83 ( V_22 ) ;
return error ;
}
static void F_84 ( struct V_64 * V_29 )
{
V_29 -> V_120 = & V_121 ;
V_29 -> type = V_122 ;
V_29 -> V_123 = V_53 ;
V_29 -> V_124 = V_125 ;
V_29 -> V_126 = 100 ;
V_29 -> V_127 &= ~ V_128 ;
}
static int F_85 ( int V_70 )
{
struct V_64 * V_29 ;
struct V_91 * V_91 ;
int error ;
if ( V_70 != - 1 ) {
for ( V_29 = V_51 ; V_29 ; V_29 = F_42 ( V_29 ) -> V_24 )
if ( F_42 ( V_29 ) -> V_70 == V_70 )
return - V_129 ;
} else {
V_70 = 0 ;
for ( V_29 = V_51 ; V_29 ; V_29 = F_42 ( V_29 ) -> V_24 )
if ( F_42 ( V_29 ) -> V_70 >= V_70 )
V_70 = F_42 ( V_29 ) -> V_70 + 1 ;
}
V_29 = F_86 ( sizeof( struct V_91 ) , L_29 , F_84 ) ;
if ( ! V_29 )
return - V_13 ;
V_91 = F_42 ( V_29 ) ;
sprintf ( V_29 -> V_130 , L_30 , V_70 ) ;
F_87 ( & V_91 -> V_68 ) ;
V_91 -> V_70 = V_70 ;
error = F_88 ( V_29 ) ;
if ( error ) {
F_89 ( V_29 ) ;
return error ;
}
V_91 -> V_24 = V_51 ;
V_51 = V_29 ;
F_2 ( L_31 , V_29 -> V_130 ) ;
return V_70 ;
}
static int F_90 ( struct V_131 * V_132 , unsigned long V_133 ,
void * V_134 )
{
struct V_64 * V_29 = V_134 ;
if ( ! F_91 ( F_92 ( V_29 ) , & V_77 ) )
return V_135 ;
if ( V_133 == V_136 ) {
F_93 ( & V_44 , V_29 ) ;
return V_135 ;
}
if ( V_29 -> type != V_122 || V_29 -> V_120 != & V_121 )
return V_135 ;
switch ( V_133 ) {
case V_137 :
F_2 ( L_32 ) ;
F_1 ( V_138 , F_42 ( V_29 ) -> V_70 , 0 ) ;
break;
case V_139 :
F_2 ( L_33 ) ;
F_1 ( V_140 , F_42 ( V_29 ) -> V_70 , 0 ) ;
break;
case V_141 :
case V_142 :
F_2 ( L_34 ) ;
F_1 ( V_143 , F_42 ( V_29 ) -> V_70 , 0 ) ;
break;
}
return V_135 ;
}
static int F_94 ( struct V_131 * V_132 , unsigned long V_133 ,
void * V_144 )
{
struct V_73 * V_74 ;
V_74 = ( (struct V_145 * ) V_144 ) -> V_146 ;
if ( V_133 != V_137 )
return V_135 ;
return F_90 ( V_132 , V_141 , V_74 -> V_29 ) ;
}
static void F_95 ( struct V_49 * V_39 )
{
F_2 ( L_9 ) ;
F_96 () ;
V_10 = NULL ;
F_97 ( & F_6 ( V_39 ) -> V_16 ) ;
F_98 () ;
F_2 ( L_35 ) ;
F_99 ( V_147 ) ;
}
static int F_100 ( struct V_49 * V_39 )
{
F_96 () ;
if ( V_10 ) {
F_98 () ;
return - V_148 ;
}
F_26 ( & V_46 , V_27 + V_47 * V_48 ) ;
V_10 = V_39 ;
F_72 ( V_149 , & V_39 -> V_66 ) ;
F_72 ( V_150 , & V_39 -> V_66 ) ;
V_39 -> V_29 = & V_151 ;
F_101 ( F_6 ( V_39 ) ) ;
V_39 -> V_108 = NULL ;
V_39 -> V_113 = NULL ;
V_39 -> V_152 = NULL ;
F_98 () ;
return 0 ;
}
static int F_102 ( struct V_153 * V_4 , unsigned int V_154 , unsigned long V_134 )
{
struct V_49 * V_39 = F_103 ( V_4 ) ;
int V_155 = 0 ;
switch ( V_154 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
if ( ! F_104 ( V_161 ) )
return - V_162 ;
break;
default:
return - V_163 ;
}
switch ( V_154 ) {
case V_156 :
V_155 = F_85 ( V_134 ) ;
break;
case V_157 :
V_155 = F_100 ( V_39 ) ;
if ( ! V_155 ) {
V_4 -> V_164 = V_165 ;
F_105 ( V_147 ) ;
}
break;
case V_158 :
V_155 = F_70 ( V_39 , V_134 ) ;
break;
case V_159 :
V_155 = F_77 ( V_39 , ( V_166 T_1 ) V_134 ) ;
break;
case V_160 :
V_155 = F_60 ( V_39 , V_134 ) ;
break;
}
return V_155 ;
}
static void F_106 ( struct V_167 * V_168 , struct V_169 * V_170 )
{
static int V_171 [] = { 1 , 2 , 10 , 6 , 1 , 0 } ;
static int V_172 [] = { 1 , 8 , 4 , 6 , 1 , 0 } ;
if ( * V_170 -> V_173 . V_174 ) {
F_107 ( V_168 , L_36 , V_170 -> V_173 . V_174 ) ;
if ( * V_170 -> V_173 . V_175 )
F_108 ( V_168 , '+' ) ;
} else if ( ! * V_170 -> V_173 . V_175 ) {
F_107 ( V_168 , L_36 , L_37 ) ;
return;
}
if ( * V_170 -> V_173 . V_175 ) {
unsigned char * V_175 = V_170 -> V_173 . V_175 ;
int * V_176 ;
int V_177 , V_178 ;
V_176 = * V_175 == V_179 ? V_172 : V_171 ;
for ( V_177 = 0 ; V_176 [ V_177 ] ; V_177 ++ ) {
for ( V_178 = V_176 [ V_177 ] ; V_178 ; V_178 -- )
F_107 ( V_168 , L_38 , * V_175 ++ ) ;
if ( V_176 [ V_177 + 1 ] )
F_108 ( V_168 , '.' ) ;
}
}
}
static void F_109 ( struct V_167 * V_168 , struct V_64 * V_29 ,
struct V_20 * V_21 , struct V_19 * V_19 )
{
unsigned long exp ;
char V_180 [ 17 ] ;
int V_181 , V_182 , V_183 ;
V_181 = ( ( V_19 == V_184 ) ||
( F_6 ( V_19 -> V_39 ) -> V_185 == V_186 ) ) ;
V_182 = ( ( V_19 == V_184 ) || V_19 -> V_52 ) ;
if ( V_19 == V_184 )
exp = V_21 -> V_22 -> V_26 ;
else
exp = V_19 -> V_37 ;
exp = ( V_27 - exp ) / V_48 ;
F_107 ( V_168 , L_39 ,
V_29 -> V_130 , V_181 ? L_40 : L_41 , V_182 ? L_42 : L_43 , exp ) ;
V_183 = F_110 ( V_180 , sizeof( V_180 ) - 1 , L_44 ,
& V_21 -> V_3 ) ;
while ( V_183 < 16 )
V_180 [ V_183 ++ ] = ' ' ;
V_180 [ V_183 ] = '\0' ;
F_107 ( V_168 , L_36 , V_180 ) ;
if ( V_19 == V_184 ) {
if ( F_19 ( V_27 , V_21 -> V_31 ) )
F_107 ( V_168 , L_45 ) ;
else
F_107 ( V_168 , L_46 ,
F_20 ( & V_21 -> V_22 -> V_41 ) ) ;
} else if ( ! V_181 ) {
F_107 ( V_168 , L_47 ,
V_19 -> V_39 -> V_29 -> V_70 ,
V_19 -> V_39 -> V_187 , V_19 -> V_39 -> V_188 ) ;
} else {
F_106 ( V_168 , & V_19 -> V_39 -> V_189 ) ;
F_108 ( V_168 , '\n' ) ;
}
}
static struct V_19 * F_111 ( struct V_20 * V_190 ,
struct V_19 * V_191 )
{
if ( ! V_191 ) {
V_191 = V_190 -> V_25 ;
if ( ! V_191 )
return V_184 ;
return V_191 ;
}
if ( V_191 == V_184 )
return NULL ;
V_191 = V_191 -> V_24 ;
return V_191 ;
}
static void * F_112 ( struct V_192 * V_164 ,
struct V_20 * V_190 , T_5 * V_193 )
{
struct V_19 * V_39 = V_164 -> V_39 ;
V_39 = F_111 ( V_190 , V_39 ) ;
if ( V_39 && V_193 != NULL ) {
while ( * V_193 ) {
V_39 = F_111 ( V_190 , V_39 ) ;
if ( ! V_39 )
break;
-- ( * V_193 ) ;
}
}
V_164 -> V_39 = V_39 ;
return V_39 ;
}
static void * F_113 ( struct V_194 * V_195 ,
struct V_34 * V_35 , T_5 * V_193 )
{
struct V_192 * V_164 = (struct V_192 * ) V_195 ;
return F_112 ( V_164 , F_16 ( V_35 ) , V_193 ) ;
}
static void * F_114 ( struct V_167 * V_168 , T_5 * V_193 )
{
struct V_192 * V_164 = V_168 -> V_196 ;
V_164 -> V_197 . V_198 = F_113 ;
return F_115 ( V_168 , V_193 , & V_44 , V_199 ) ;
}
static int F_116 ( struct V_167 * V_168 , void * V_200 )
{
static char V_201 [] =
L_48 ;
if ( V_200 == V_202 ) {
F_117 ( V_168 , V_201 ) ;
} else {
struct V_192 * V_164 = V_168 -> V_196 ;
struct V_34 * V_35 = V_200 ;
struct V_19 * V_39 = V_164 -> V_39 ;
F_109 ( V_168 , V_35 -> V_29 , F_16 ( V_35 ) , V_39 ) ;
}
return 0 ;
}
static int F_118 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_119 ( V_203 , V_204 , & V_205 ,
sizeof( struct V_192 ) ) ;
}
static int T_6 F_120 ( void )
{
F_121 ( & V_44 ) ;
V_206 = & V_44 ;
F_122 ( & V_207 ) ;
F_123 ( & V_208 ) ;
F_124 ( & V_209 ) ;
F_125 ( & V_46 , F_23 , 0 ) ;
#ifdef F_126
{
struct V_210 * V_211 ;
V_211 = F_127 ( L_49 , V_212 , V_213 , & V_214 ) ;
if ( ! V_211 ) {
F_63 ( L_50 ) ;
F_128 () ;
return - V_13 ;
}
}
#endif
return 0 ;
}
static void F_128 ( void )
{
struct V_64 * V_29 , * V_24 ;
F_129 ( & V_209 ) ;
F_130 ( & V_208 ) ;
F_131 ( & V_207 ) ;
F_132 ( & V_46 ) ;
F_93 ( & V_44 , NULL ) ;
V_29 = V_51 ;
while ( V_29 ) {
V_24 = F_42 ( V_29 ) -> V_24 ;
F_133 ( V_29 ) ;
F_89 ( V_29 ) ;
V_29 = V_24 ;
}
F_134 ( & V_44 ) ;
V_206 = NULL ;
}
static void T_7 F_135 ( void )
{
F_136 ( L_49 , V_213 ) ;
F_128 () ;
}
