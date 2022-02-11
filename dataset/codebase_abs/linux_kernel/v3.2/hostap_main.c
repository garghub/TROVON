struct V_1 * F_1 ( struct V_2 * V_3 ,
int type , int V_4 ,
const char * V_5 ,
const char * V_6 )
{
struct V_1 * V_7 , * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_7 = F_2 ( sizeof( struct V_9 ) ) ;
if ( V_7 == NULL )
return NULL ;
V_10 = F_3 ( V_7 ) ;
V_10 -> V_7 = V_7 ;
V_10 -> V_3 = V_3 ;
V_10 -> type = type ;
F_4 ( & V_10 -> V_12 , & V_3 -> V_13 ) ;
V_8 = V_3 -> V_7 ;
memcpy ( V_7 -> V_14 , V_8 -> V_14 , V_15 ) ;
V_7 -> V_16 = V_8 -> V_16 ;
V_7 -> V_17 = V_8 -> V_17 ;
V_7 -> V_18 = V_8 -> V_18 ;
V_7 -> V_19 = V_8 -> V_19 ;
F_5 ( V_7 , V_3 , type ) ;
V_7 -> V_20 = V_21 ;
sprintf ( V_7 -> V_6 , L_1 , V_5 , V_6 ) ;
if ( ! V_4 )
F_6 () ;
F_7 ( V_7 , V_8 -> V_7 . V_22 ) ;
V_11 = F_8 ( V_7 ) ;
if ( ! V_4 )
F_9 () ;
if ( V_11 < 0 ) {
F_10 ( V_23 L_2 ,
V_7 -> V_6 ) ;
V_21 ( V_7 ) ;
return NULL ;
}
F_10 ( V_24 L_3 ,
V_8 -> V_6 , V_7 -> V_6 ) ;
return V_7 ;
}
void F_11 ( struct V_1 * V_7 , int V_4 ,
int V_25 )
{
struct V_9 * V_10 ;
if ( ! V_7 )
return;
V_10 = F_3 ( V_7 ) ;
if ( V_25 ) {
F_12 ( & V_10 -> V_12 ) ;
}
if ( V_7 == V_10 -> V_3 -> V_26 )
V_10 -> V_3 -> V_26 = NULL ;
else if ( V_7 == V_10 -> V_3 -> V_27 )
V_10 -> V_3 -> V_27 = NULL ;
else if ( V_7 == V_10 -> V_3 -> V_28 )
V_10 -> V_3 -> V_28 = NULL ;
if ( V_4 )
F_13 ( V_7 ) ;
else
F_14 ( V_7 ) ;
}
static inline int F_15 ( T_1 * V_29 )
{
if ( V_29 [ 0 ] || V_29 [ 1 ] || V_29 [ 2 ] || V_29 [ 3 ] || V_29 [ 4 ] || V_29 [ 5 ] )
return 0 ;
return 1 ;
}
int F_16 ( T_2 * V_3 , T_1 * V_30 ,
int V_4 )
{
struct V_1 * V_7 ;
struct V_31 * V_32 ;
struct V_9 * V_10 , * V_33 , * V_34 ;
V_33 = V_34 = NULL ;
F_17 ( & V_3 -> V_35 ) ;
F_18 (ptr, &local->hostap_interfaces) {
V_10 = F_19 ( V_32 , struct V_9 , V_12 ) ;
if ( V_10 -> type != V_36 )
continue;
if ( F_15 ( V_10 -> V_37 . V_38 . V_30 ) )
V_33 = V_10 ;
else if ( memcmp ( V_10 -> V_37 . V_38 . V_30 , V_30 ,
V_15 ) == 0 ) {
V_34 = V_10 ;
break;
}
}
if ( ! V_34 && V_33 && ! F_15 ( V_30 ) ) {
memcpy ( V_33 -> V_37 . V_38 . V_30 , V_30 , V_15 ) ;
F_20 ( & V_3 -> V_35 ) ;
F_10 ( V_24 L_4 ,
V_3 -> V_7 -> V_6 , V_33 -> V_7 -> V_6 ) ;
return 0 ;
}
F_20 ( & V_3 -> V_35 ) ;
if ( ! F_15 ( V_30 ) ) {
if ( V_34 )
return - V_39 ;
F_21 ( V_3 -> V_40 , V_30 ) ;
}
if ( V_3 -> V_41 >= V_3 -> V_42 )
return - V_43 ;
if ( strlen ( V_3 -> V_7 -> V_6 ) >= V_44 - 5 ) {
F_10 ( V_24 L_5 ,
V_3 -> V_7 -> V_6 ) ;
return - V_45 ;
}
V_7 = F_1 ( V_3 , V_36 , V_4 ,
V_3 -> V_26 -> V_6 , L_6 ) ;
if ( V_7 == NULL )
return - V_46 ;
V_10 = F_3 ( V_7 ) ;
memcpy ( V_10 -> V_37 . V_38 . V_30 , V_30 , V_15 ) ;
V_3 -> V_41 ++ ;
return 0 ;
}
int F_22 ( T_2 * V_3 , T_1 * V_30 ,
int V_4 , int V_47 )
{
unsigned long V_48 ;
struct V_31 * V_32 ;
struct V_9 * V_10 , * V_49 = NULL ;
F_23 ( & V_3 -> V_35 , V_48 ) ;
F_18 (ptr, &local->hostap_interfaces) {
V_10 = F_19 ( V_32 , struct V_9 , V_12 ) ;
if ( V_10 -> type != V_36 )
continue;
if ( memcmp ( V_10 -> V_37 . V_38 . V_30 , V_30 ,
V_15 ) == 0 ) {
V_49 = V_10 ;
break;
}
}
if ( V_49 && ! V_47 )
F_12 ( & V_49 -> V_12 ) ;
F_24 ( & V_3 -> V_35 , V_48 ) ;
if ( V_49 ) {
if ( V_47 )
memset ( V_49 -> V_37 . V_38 . V_30 , 0 , V_15 ) ;
else {
F_11 ( V_49 -> V_7 , V_4 , 0 ) ;
V_3 -> V_41 -- ;
}
}
return V_49 ? 0 : - V_50 ;
}
T_3 F_25 ( T_2 * V_3 ,
void (* F_26)( struct V_51 * , int V_52 , void * ) ,
void * V_53 )
{
unsigned long V_48 ;
struct V_54 * V_55 ;
V_55 = F_27 ( sizeof( * V_55 ) ,
V_56 ) ;
if ( V_55 == NULL )
return 0 ;
V_55 -> F_26 = F_26 ;
V_55 -> V_53 = V_53 ;
F_28 ( & V_3 -> V_57 , V_48 ) ;
V_55 -> V_58 = V_3 -> V_59 ? V_3 -> V_59 -> V_58 + 1 : 1 ;
V_55 -> V_60 = V_3 -> V_59 ;
V_3 -> V_59 = V_55 ;
F_29 ( & V_3 -> V_57 , V_48 ) ;
return V_55 -> V_58 ;
}
int F_30 ( T_2 * V_3 , T_3 V_58 )
{
unsigned long V_48 ;
struct V_54 * V_61 , * V_62 = NULL ;
F_28 ( & V_3 -> V_57 , V_48 ) ;
V_61 = V_3 -> V_59 ;
while ( V_61 != NULL && V_61 -> V_58 != V_58 ) {
V_62 = V_61 ;
V_61 = V_61 -> V_60 ;
}
if ( V_61 ) {
if ( V_62 == NULL )
V_3 -> V_59 = V_61 -> V_60 ;
else
V_62 -> V_60 = V_61 -> V_60 ;
F_31 ( V_61 ) ;
}
F_29 ( & V_3 -> V_57 , V_48 ) ;
return V_61 ? 0 : - 1 ;
}
int F_32 ( struct V_1 * V_7 , int V_63 , T_3 V_64 )
{
struct V_9 * V_10 ;
T_4 V_65 = F_33 ( V_64 ) ;
V_10 = F_3 ( V_7 ) ;
return V_10 -> V_3 -> F_26 -> V_66 ( V_7 , V_63 , & V_65 , 2 ) ;
}
int F_34 ( struct V_1 * V_7 , int V_63 , const char * V_64 )
{
struct V_9 * V_10 ;
char V_67 [ V_68 + 2 ] ;
int V_69 ;
V_10 = F_3 ( V_7 ) ;
V_69 = strlen ( V_64 ) ;
if ( V_69 > V_68 )
return - 1 ;
memset ( V_67 , 0 , sizeof( V_67 ) ) ;
V_67 [ 0 ] = V_69 ;
memcpy ( V_67 + 2 , V_64 , V_69 ) ;
return V_10 -> V_3 -> F_26 -> V_66 ( V_7 , V_63 , & V_67 , V_68 + 2 ) ;
}
T_3 F_35 ( T_2 * V_3 )
{
if ( V_3 -> V_70 == V_71 && V_3 -> V_72 )
return V_73 ;
if ( V_3 -> V_70 == V_71 )
return V_74 ;
if ( V_3 -> V_70 == V_75 )
return V_76 ;
if ( V_3 -> V_70 == V_77 )
return V_78 ;
if ( V_3 -> V_70 == V_79 )
return V_73 ;
return V_80 ;
}
int F_36 ( T_2 * V_3 )
{
T_3 V_64 , V_81 ;
int V_82 , V_83 , V_69 , V_58 ;
char V_84 [ V_85 + 1 ] ;
enum { V_86 , V_87 , V_88 } V_89 ;
V_58 = V_3 -> V_90 . V_91 ;
if ( V_3 -> V_90 . V_92 [ V_58 ] == NULL ||
V_3 -> V_90 . V_92 [ V_58 ] -> V_93 == NULL )
V_89 = V_86 ;
else if ( strcmp ( V_3 -> V_90 . V_92 [ V_58 ] -> V_93 -> V_6 , L_7 ) == 0 )
V_89 = V_87 ;
else
V_89 = V_88 ;
if ( V_3 -> F_26 -> V_94 ( V_3 -> V_7 , V_95 , & V_64 , 2 ,
1 ) < 0 ) {
F_10 ( V_24 L_8 ) ;
goto V_96;
}
F_37 ( & V_64 ) ;
V_81 = V_64 ;
if ( V_89 != V_86 || V_3 -> V_97 )
V_64 |= V_98 ;
else
V_64 &= ~ V_98 ;
if ( V_3 -> V_99 || V_89 == V_86 ||
( ( V_3 -> V_100 || V_3 -> V_101 ) && V_3 -> V_102 ) )
V_64 &= ~ V_103 ;
else
V_64 |= V_103 ;
if ( ( V_89 != V_86 || V_3 -> V_97 ) &&
( V_89 == V_88 || V_3 -> V_104 ) )
V_64 |= V_105 ;
else
V_64 &= ~ V_105 ;
if ( ( V_89 != V_86 || V_3 -> V_97 ) &&
( V_89 == V_88 || V_3 -> V_102 ) )
V_64 |= V_106 ;
else
V_64 &= ~ V_106 ;
if ( V_64 != V_81 &&
F_32 ( V_3 -> V_7 , V_95 , V_64 ) ) {
F_10 ( V_24 L_9 ,
V_64 ) ;
goto V_96;
}
if ( V_89 != V_87 )
return 0 ;
V_83 = 6 ;
V_69 = V_3 -> V_90 . V_92 [ V_58 ] -> V_93 -> V_107 ( V_84 , sizeof( V_84 ) , NULL ,
V_3 -> V_90 . V_92 [ V_58 ] -> V_108 ) ;
if ( V_58 >= 0 && V_58 < V_109 && V_69 > 5 )
V_83 = V_85 + 1 ;
for ( V_82 = 0 ; V_82 < V_109 ; V_82 ++ ) {
memset ( V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_3 -> V_90 . V_92 [ V_82 ] ) {
( void ) V_3 -> V_90 . V_92 [ V_82 ] -> V_93 -> V_107 (
V_84 , sizeof( V_84 ) ,
NULL , V_3 -> V_90 . V_92 [ V_82 ] -> V_108 ) ;
}
if ( V_3 -> F_26 -> V_66 ( V_3 -> V_7 ,
V_110 + V_82 ,
V_84 , V_83 ) ) {
F_10 ( V_24 L_10 ,
V_82 , V_83 ) ;
goto V_96;
}
}
if ( F_32 ( V_3 -> V_7 , V_111 , V_58 ) ) {
F_10 ( V_24 L_11 , V_58 ) ;
goto V_96;
}
return 0 ;
V_96:
F_10 ( V_24 L_12 , V_3 -> V_7 -> V_6 ) ;
return - 1 ;
}
int F_38 ( T_2 * V_3 )
{
T_3 V_64 ;
int V_11 = 0 ;
if ( V_3 -> V_112 != V_113 &&
V_3 -> F_26 -> V_114 ( V_3 -> V_7 , V_115 ,
V_116 ,
NULL , & V_64 ) == 0 ) {
V_64 &= ~ ( F_39 ( 2 ) | F_39 ( 1 ) ) ;
switch ( V_3 -> V_112 ) {
case V_117 :
V_64 |= F_39 ( 1 ) ;
break;
case V_118 :
break;
case V_119 :
V_64 |= F_39 ( 2 ) ;
break;
}
if ( V_3 -> F_26 -> V_114 ( V_3 -> V_7 , V_120 ,
V_116 , & V_64 , NULL ) ) {
F_10 ( V_121 L_13 ,
V_3 -> V_7 -> V_6 ) ;
V_11 = - 1 ;
}
}
if ( V_3 -> V_122 != V_113 &&
V_3 -> F_26 -> V_114 ( V_3 -> V_7 , V_115 ,
V_123 ,
NULL , & V_64 ) == 0 ) {
V_64 &= ~ ( F_39 ( 1 ) | F_39 ( 0 ) ) ;
switch ( V_3 -> V_122 ) {
case V_117 :
break;
case V_118 :
V_64 |= F_39 ( 0 ) ;
break;
case V_119 :
V_64 |= F_39 ( 0 ) | F_39 ( 1 ) ;
break;
}
if ( V_3 -> F_26 -> V_114 ( V_3 -> V_7 , V_120 ,
V_123 , & V_64 , NULL ) ) {
F_10 ( V_121 L_14 ,
V_3 -> V_7 -> V_6 ) ;
V_11 = - 1 ;
}
}
return V_11 ;
}
int F_40 ( T_2 * V_3 )
{
T_3 V_64 ;
switch ( V_3 -> V_124 ) {
case 1 :
V_64 = V_125 ;
break;
case 2 :
V_64 = V_126 ;
break;
case 0 :
default:
V_64 = V_127 ;
break;
}
return F_32 ( V_3 -> V_7 , V_128 , V_64 ) ;
}
int F_41 ( T_2 * V_3 )
{
int V_64 = V_3 -> V_129 ;
if ( V_3 -> V_130 < F_42 ( 0 , 7 , 0 ) &&
V_64 != V_131 && V_64 != V_132 )
V_64 = V_131 ;
if ( F_32 ( V_3 -> V_7 , V_133 , V_64 ) ) {
F_10 ( V_121 L_15
L_16 , V_3 -> V_7 -> V_6 , V_3 -> V_129 ) ;
return - V_45 ;
}
return 0 ;
}
void F_43 ( const char * V_6 , const struct V_134 * V_135 )
{
T_3 V_136 , V_137 ;
V_136 = F_44 ( V_135 -> V_136 ) ;
F_10 ( V_24 L_17
L_18
L_19 ,
V_6 , V_136 , ( V_136 >> 8 ) & 0x07 , V_136 >> 13 , V_136 & 1 ,
V_135 -> V_138 , V_135 -> signal , V_135 -> V_139 , V_135 -> V_140 , V_141 ) ;
V_137 = F_44 ( V_135 -> V_142 ) ;
F_10 ( V_24 L_20
L_21 ,
V_137 , ( V_137 & V_143 ) >> 2 ,
( V_137 & V_144 ) >> 4 ,
F_44 ( V_135 -> V_145 ) , F_44 ( V_135 -> V_146 ) ,
F_44 ( V_135 -> V_147 ) ,
V_137 & V_148 ? L_22 : L_23 ,
V_137 & V_149 ? L_24 : L_23 ) ;
F_10 ( V_24 L_25 ,
V_135 -> V_150 , V_135 -> V_151 , V_135 -> V_152 , V_135 -> V_153 ) ;
F_10 ( V_24 L_26 ,
V_135 -> V_154 , V_135 -> V_155 ,
F_45 ( V_135 -> V_69 ) ) ;
}
void F_46 ( const char * V_6 , const struct V_156 * V_157 )
{
T_3 V_137 ;
F_10 ( V_24 L_27
L_28 ,
V_6 , F_44 ( V_157 -> V_136 ) , V_157 -> V_158 , V_157 -> V_159 ,
F_44 ( V_157 -> V_160 ) , V_141 ) ;
V_137 = F_44 ( V_157 -> V_142 ) ;
F_10 ( V_24 L_20
L_21 ,
V_137 , ( V_137 & V_143 ) >> 2 ,
( V_137 & V_144 ) >> 4 ,
F_44 ( V_157 -> V_145 ) , F_44 ( V_157 -> V_146 ) ,
F_44 ( V_157 -> V_147 ) ,
V_137 & V_148 ? L_22 : L_23 ,
V_137 & V_149 ? L_24 : L_23 ) ;
F_10 ( V_24 L_25 ,
V_157 -> V_150 , V_157 -> V_151 , V_157 -> V_152 , V_157 -> V_153 ) ;
F_10 ( V_24 L_26 ,
V_157 -> V_154 , V_157 -> V_155 ,
F_45 ( V_157 -> V_69 ) ) ;
}
static int F_47 ( const struct V_51 * V_161 ,
unsigned char * V_162 )
{
memcpy ( V_162 , F_48 ( V_161 ) + 10 , V_15 ) ;
return V_15 ;
}
int F_49 ( T_4 V_137 )
{
if ( F_50 ( V_137 ) && F_51 ( V_137 ) )
return 30 ;
else if ( F_52 ( V_137 ) || F_53 ( V_137 ) )
return 10 ;
else if ( F_54 ( V_137 ) )
return 16 ;
return 24 ;
}
static int F_55 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
F_56 ( V_163 , L_29 , V_7 -> V_6 ) ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_7 == V_3 -> V_26 ) {
F_57 ( V_3 , V_164 ) ;
}
#ifndef F_58
if ( ! V_3 -> V_165 && V_7 == V_3 -> V_7 &&
( ! V_3 -> F_26 -> V_166 || V_3 -> F_26 -> V_166 ( V_3 ) ) &&
V_3 -> V_167 && V_3 -> V_40 && V_3 -> V_70 == V_168 )
F_59 ( V_7 , V_3 -> V_40 , 1 ) ;
#endif
if ( V_7 == V_3 -> V_7 ) {
V_3 -> F_26 -> V_169 ( V_7 , V_170 ) ;
}
if ( F_60 ( V_7 ) ) {
F_61 ( V_7 ) ;
F_62 ( V_7 ) ;
}
F_63 ( & V_3 -> V_171 ) ;
F_63 ( & V_3 -> V_172 ) ;
F_63 ( & V_3 -> V_173 ) ;
#ifndef F_64
F_63 ( & V_3 -> V_174 ) ;
#endif
F_63 ( & V_3 -> V_175 ) ;
F_65 ( V_3 -> V_176 ) ;
V_3 -> V_177 -- ;
if ( V_7 != V_3 -> V_7 && V_3 -> V_7 -> V_48 & V_178 &&
V_3 -> V_179 && V_3 -> V_177 == 1 ) {
F_66 ( V_3 -> V_7 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
F_56 ( V_163 , L_30 , V_7 -> V_6 ) ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_3 -> V_180 ) {
F_10 ( V_24 L_31
L_32 , V_7 -> V_6 ) ;
return 1 ;
}
if ( ( V_3 -> F_26 -> V_166 && ! V_3 -> F_26 -> V_166 ( V_3 ) ) ||
V_3 -> V_181 )
return - V_50 ;
if ( ! F_68 ( V_3 -> V_176 ) )
return - V_50 ;
V_3 -> V_177 ++ ;
if ( ! V_3 -> V_182 && V_3 -> F_26 -> V_183 ( V_7 , 1 ) ) {
F_10 ( V_23 L_33 ,
V_7 -> V_6 ) ;
F_55 ( V_7 ) ;
return 1 ;
}
if ( ! V_3 -> V_182 )
F_69 ( V_3 , V_184 ) ;
V_3 -> V_182 = 1 ;
if ( V_7 != V_3 -> V_7 && ! ( V_3 -> V_7 -> V_48 & V_178 ) ) {
V_3 -> V_179 = 1 ;
F_70 ( V_3 -> V_7 ) ;
}
F_71 ( V_7 ) ;
F_72 ( V_7 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_7 , void * V_185 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
struct V_31 * V_32 ;
struct V_186 * V_29 = V_185 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_3 -> F_26 -> V_66 ( V_7 , V_187 , V_29 -> V_188 ,
V_15 ) < 0 || V_3 -> F_26 -> V_189 ( V_7 ) )
return - V_45 ;
F_17 ( & V_3 -> V_35 ) ;
F_18 (ptr, &local->hostap_interfaces) {
V_10 = F_19 ( V_32 , struct V_9 , V_12 ) ;
memcpy ( V_10 -> V_7 -> V_14 , V_29 -> V_188 , V_15 ) ;
}
memcpy ( V_3 -> V_7 -> V_14 , V_29 -> V_188 , V_15 ) ;
F_20 ( & V_3 -> V_35 ) ;
return 0 ;
}
void F_74 ( struct V_190 * V_191 )
{
T_2 * V_3 =
F_75 ( V_191 , T_2 , V_172 ) ;
struct V_1 * V_7 = V_3 -> V_7 ;
if ( F_32 ( V_7 , V_192 ,
V_3 -> V_193 ) ) {
F_10 ( V_121 L_34 ,
V_7 -> V_6 , V_3 -> V_193 ? L_35 : L_36 ) ;
}
}
static void F_76 ( struct V_1 * V_7 )
{
#if 0
struct hostap_interface *iface;
local_info_t *local;
iface = netdev_priv(dev);
local = iface->local;
if ((dev->flags & IFF_ALLMULTI) || (dev->flags & IFF_PROMISC)) {
local->is_promisc = 1;
} else {
local->is_promisc = 0;
}
schedule_work(&local->set_multicast_list_queue);
#endif
}
static int F_77 ( struct V_1 * V_7 , int V_194 )
{
if ( V_194 < V_195 || V_194 > V_196 )
return - V_45 ;
V_7 -> V_197 = V_194 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
struct V_198 V_199 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
F_10 ( V_23 L_37 , V_7 -> V_6 ) ;
F_61 ( V_3 -> V_7 ) ;
V_3 -> F_26 -> V_200 ( V_7 , & V_199 ) ;
F_10 ( V_24 L_38
L_39 ,
V_7 -> V_6 , V_199 . V_114 , V_199 . V_201 , V_199 . V_202 , V_199 . V_203 ,
V_199 . V_204 ) ;
V_3 -> F_26 -> V_205 ( V_3 ) ;
}
void F_5 ( struct V_1 * V_7 , T_2 * V_3 ,
int type )
{
struct V_9 * V_10 ;
V_10 = F_3 ( V_7 ) ;
F_79 ( V_7 ) ;
V_7 -> V_206 &= ~ V_207 ;
if ( V_10 ) {
V_10 -> V_208 . V_209 = & V_10 -> V_209 ;
V_7 -> V_208 = & V_10 -> V_208 ;
}
V_7 -> V_210 = & V_211 ;
V_7 -> V_212 = V_213 ;
switch( type ) {
case V_214 :
V_7 -> V_215 = 0 ;
V_7 -> V_216 = & V_217 ;
V_7 -> type = V_218 ;
V_7 -> V_219 = & V_220 ;
break;
case V_221 :
V_7 -> V_216 = & V_222 ;
break;
default:
V_7 -> V_215 = 0 ;
V_7 -> V_216 = & V_223 ;
}
V_7 -> V_197 = V_3 -> V_197 ;
F_80 ( V_7 , & V_224 ) ;
}
static int F_81 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
if ( V_3 -> V_27 )
return - V_39 ;
F_10 ( V_24 L_40 , V_7 -> V_6 ) ;
V_3 -> V_27 = F_1 ( V_3 , V_214 ,
V_4 , V_3 -> V_26 -> V_6 ,
L_41 ) ;
if ( V_3 -> V_27 == NULL )
return - V_46 ;
return 0 ;
}
static int F_82 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
F_10 ( V_24 L_42 , V_7 -> V_6 ) ;
F_11 ( V_3 -> V_27 , V_4 , 1 ) ;
V_3 -> V_27 = NULL ;
return 0 ;
}
static int F_83 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
if ( V_3 -> V_28 )
return - V_39 ;
F_10 ( V_24 L_43 , V_7 -> V_6 ) ;
V_3 -> V_28 = F_1 ( V_3 , V_225 ,
V_4 , V_3 -> V_26 -> V_6 ,
L_44 ) ;
if ( V_3 -> V_28 == NULL )
return - V_46 ;
return 0 ;
}
static int F_84 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
F_10 ( V_24 L_42 , V_7 -> V_6 ) ;
F_11 ( V_3 -> V_28 , V_4 , 1 ) ;
V_3 -> V_28 = NULL ;
return 0 ;
}
int F_85 ( T_2 * V_3 , int V_64 , int V_4 )
{
int V_11 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_45 ;
if ( V_3 -> V_165 == V_64 )
return 0 ;
if ( V_64 ) {
V_11 = F_81 ( V_3 , V_4 ) ;
if ( V_11 == 0 )
V_3 -> V_165 = 1 ;
} else {
V_3 -> V_165 = 0 ;
V_11 = F_82 ( V_3 , V_4 ) ;
if ( V_11 != 0 )
V_3 -> V_165 = 1 ;
}
return V_11 ;
}
int F_86 ( T_2 * V_3 , int V_64 , int V_4 )
{
int V_11 ;
if ( V_64 < 0 || V_64 > 1 )
return - V_45 ;
if ( V_3 -> V_226 == V_64 )
return 0 ;
if ( V_64 ) {
V_11 = F_83 ( V_3 , V_4 ) ;
if ( V_11 == 0 )
V_3 -> V_226 = 1 ;
} else {
V_3 -> V_226 = 0 ;
V_11 = F_84 ( V_3 , V_4 ) ;
if ( V_11 != 0 )
V_3 -> V_226 = 1 ;
}
return V_11 ;
}
int F_87 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
int V_11 = 0 ;
struct V_227 V_228 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( ! V_3 -> V_130 )
V_11 = - 1 ;
else if ( V_3 -> V_130 >= F_42 ( 1 , 3 , 1 ) ) {
if ( V_3 -> F_26 -> V_94 ( V_3 -> V_7 ,
V_229 ,
& V_228 , sizeof( V_228 ) , 1 ) >= 0 ) {
V_3 -> V_230 = ( V_231 ) F_88 ( V_228 . V_232 ) ;
V_3 -> V_233 = ( V_231 ) F_88 ( V_228 . V_234 ) ;
V_3 -> V_235 = ( V_231 ) F_88 ( V_228 . V_236 ) ;
V_3 -> V_237 = V_141 ;
} else
V_11 = - 1 ;
} else {
if ( V_3 -> F_26 -> V_94 ( V_3 -> V_7 , V_238 ,
& V_228 , sizeof( V_228 ) , 1 ) >= 0 ) {
V_3 -> V_230 = F_88 ( V_228 . V_232 ) ;
V_3 -> V_233 = F_89 (
F_88 ( V_228 . V_234 ) ) ;
V_3 -> V_235 = F_89 (
F_88 ( V_228 . V_236 ) ) ;
V_3 -> V_237 = V_141 ;
} else
V_11 = - 1 ;
}
return V_11 ;
}
int F_90 ( T_2 * V_3 , T_1 * V_239 , T_3 V_240 ,
T_1 * V_241 , T_5 V_242 )
{
struct V_51 * V_161 ;
struct V_243 * V_244 ;
struct V_245 * V_246 ;
struct V_1 * V_7 = V_3 -> V_7 ;
V_161 = F_91 ( V_247 + V_242 ) ;
if ( V_161 == NULL )
return - V_46 ;
V_244 = (struct V_243 * )
F_92 ( V_161 , V_247 ) ;
memset ( V_244 , 0 , V_247 ) ;
V_244 -> V_142 = F_33 ( V_248 | V_240 ) ;
memcpy ( V_244 -> V_249 , V_239 , V_15 ) ;
memcpy ( V_244 -> V_250 , V_7 -> V_14 , V_15 ) ;
memcpy ( V_244 -> V_251 , V_239 , V_15 ) ;
if ( V_241 )
memcpy ( F_92 ( V_161 , V_242 ) , V_241 , V_242 ) ;
V_246 = (struct V_245 * ) V_161 -> V_61 ;
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_252 = V_253 ;
V_246 -> V_10 = F_3 ( V_7 ) ;
V_161 -> V_7 = V_7 ;
F_93 ( V_161 ) ;
F_94 ( V_161 ) ;
F_95 ( V_161 ) ;
return 0 ;
}
int F_57 ( T_2 * V_3 , T_3 V_254 )
{
union V_255 V_256 ;
int V_11 ;
T_4 V_64 = F_33 ( V_254 ) ;
if ( V_3 -> V_70 != V_75 ||
memcmp ( V_3 -> V_251 , L_45 , V_15 ) == 0 ||
memcmp ( V_3 -> V_251 , L_46 , V_15 ) == 0 )
return 0 ;
V_11 = F_90 ( V_3 , V_3 -> V_251 , V_257 ,
( T_1 * ) & V_64 , 2 ) ;
memset ( V_256 . V_258 . V_188 , 0 , V_15 ) ;
F_96 ( V_3 -> V_7 , V_259 , & V_256 , NULL ) ;
return V_11 ;
}
static int T_6 F_97 ( void )
{
if ( V_260 . V_261 != NULL ) {
V_262 = F_98 ( L_47 , V_260 . V_261 ) ;
if ( ! V_262 )
F_10 ( V_23 L_48
L_49 ) ;
} else
V_262 = NULL ;
return 0 ;
}
static void T_7 F_99 ( void )
{
if ( V_262 != NULL ) {
V_262 = NULL ;
F_100 ( L_47 , V_260 . V_261 ) ;
}
}
