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
F_5 ( V_7 , V_8 ) ;
V_7 -> V_14 = V_8 -> V_14 ;
V_7 -> V_15 = V_8 -> V_15 ;
V_7 -> V_16 = V_8 -> V_16 ;
V_7 -> V_17 = V_8 -> V_17 ;
F_6 ( V_7 , V_3 , type ) ;
V_7 -> V_18 = V_19 ;
sprintf ( V_7 -> V_6 , L_1 , V_5 , V_6 ) ;
if ( ! V_4 )
F_7 () ;
F_8 ( V_7 , V_8 -> V_7 . V_20 ) ;
V_11 = F_9 ( V_7 ) ;
if ( ! V_4 )
F_10 () ;
if ( V_11 < 0 ) {
F_11 ( V_21 L_2 ,
V_7 -> V_6 ) ;
V_19 ( V_7 ) ;
return NULL ;
}
F_11 ( V_22 L_3 ,
V_8 -> V_6 , V_7 -> V_6 ) ;
return V_7 ;
}
void F_12 ( struct V_1 * V_7 , int V_4 ,
int V_23 )
{
struct V_9 * V_10 ;
if ( ! V_7 )
return;
V_10 = F_3 ( V_7 ) ;
if ( V_23 ) {
F_13 ( & V_10 -> V_12 ) ;
}
if ( V_7 == V_10 -> V_3 -> V_24 )
V_10 -> V_3 -> V_24 = NULL ;
else if ( V_7 == V_10 -> V_3 -> V_25 )
V_10 -> V_3 -> V_25 = NULL ;
else if ( V_7 == V_10 -> V_3 -> V_26 )
V_10 -> V_3 -> V_26 = NULL ;
if ( V_4 )
F_14 ( V_7 ) ;
else
F_15 ( V_7 ) ;
}
static inline int F_16 ( T_1 * V_27 )
{
if ( V_27 [ 0 ] || V_27 [ 1 ] || V_27 [ 2 ] || V_27 [ 3 ] || V_27 [ 4 ] || V_27 [ 5 ] )
return 0 ;
return 1 ;
}
int F_17 ( T_2 * V_3 , T_1 * V_28 ,
int V_4 )
{
struct V_1 * V_7 ;
struct V_29 * V_30 ;
struct V_9 * V_10 , * V_31 , * V_32 ;
V_31 = V_32 = NULL ;
F_18 ( & V_3 -> V_33 ) ;
F_19 (ptr, &local->hostap_interfaces) {
V_10 = F_20 ( V_30 , struct V_9 , V_12 ) ;
if ( V_10 -> type != V_34 )
continue;
if ( F_16 ( V_10 -> V_35 . V_36 . V_28 ) )
V_31 = V_10 ;
else if ( F_21 ( V_10 -> V_35 . V_36 . V_28 , V_28 ) ) {
V_32 = V_10 ;
break;
}
}
if ( ! V_32 && V_31 && ! F_16 ( V_28 ) ) {
memcpy ( V_31 -> V_35 . V_36 . V_28 , V_28 , V_37 ) ;
F_22 ( & V_3 -> V_33 ) ;
F_11 ( V_22 L_4 ,
V_3 -> V_7 -> V_6 , V_31 -> V_7 -> V_6 ) ;
return 0 ;
}
F_22 ( & V_3 -> V_33 ) ;
if ( ! F_16 ( V_28 ) ) {
if ( V_32 )
return - V_38 ;
F_23 ( V_3 -> V_39 , V_28 ) ;
}
if ( V_3 -> V_40 >= V_3 -> V_41 )
return - V_42 ;
if ( strlen ( V_3 -> V_7 -> V_6 ) >= V_43 - 5 ) {
F_11 ( V_22 L_5 ,
V_3 -> V_7 -> V_6 ) ;
return - V_44 ;
}
V_7 = F_1 ( V_3 , V_34 , V_4 ,
V_3 -> V_24 -> V_6 , L_6 ) ;
if ( V_7 == NULL )
return - V_45 ;
V_10 = F_3 ( V_7 ) ;
memcpy ( V_10 -> V_35 . V_36 . V_28 , V_28 , V_37 ) ;
V_3 -> V_40 ++ ;
return 0 ;
}
int F_24 ( T_2 * V_3 , T_1 * V_28 ,
int V_4 , int V_46 )
{
unsigned long V_47 ;
struct V_29 * V_30 ;
struct V_9 * V_10 , * V_48 = NULL ;
F_25 ( & V_3 -> V_33 , V_47 ) ;
F_19 (ptr, &local->hostap_interfaces) {
V_10 = F_20 ( V_30 , struct V_9 , V_12 ) ;
if ( V_10 -> type != V_34 )
continue;
if ( F_21 ( V_10 -> V_35 . V_36 . V_28 , V_28 ) ) {
V_48 = V_10 ;
break;
}
}
if ( V_48 && ! V_46 )
F_13 ( & V_48 -> V_12 ) ;
F_26 ( & V_3 -> V_33 , V_47 ) ;
if ( V_48 ) {
if ( V_46 )
memset ( V_48 -> V_35 . V_36 . V_28 , 0 , V_37 ) ;
else {
F_12 ( V_48 -> V_7 , V_4 , 0 ) ;
V_3 -> V_40 -- ;
}
}
return V_48 ? 0 : - V_49 ;
}
T_3 F_27 ( T_2 * V_3 ,
void (* F_28)( struct V_50 * , int V_51 , void * ) ,
void * V_52 )
{
unsigned long V_47 ;
struct V_53 * V_54 ;
V_54 = F_29 ( sizeof( * V_54 ) , V_55 ) ;
if ( V_54 == NULL )
return 0 ;
V_54 -> F_28 = F_28 ;
V_54 -> V_52 = V_52 ;
F_30 ( & V_3 -> V_56 , V_47 ) ;
V_54 -> V_57 = V_3 -> V_58 ? V_3 -> V_58 -> V_57 + 1 : 1 ;
V_54 -> V_59 = V_3 -> V_58 ;
V_3 -> V_58 = V_54 ;
F_31 ( & V_3 -> V_56 , V_47 ) ;
return V_54 -> V_57 ;
}
int F_32 ( T_2 * V_3 , T_3 V_57 )
{
unsigned long V_47 ;
struct V_53 * V_60 , * V_61 = NULL ;
F_30 ( & V_3 -> V_56 , V_47 ) ;
V_60 = V_3 -> V_58 ;
while ( V_60 != NULL && V_60 -> V_57 != V_57 ) {
V_61 = V_60 ;
V_60 = V_60 -> V_59 ;
}
if ( V_60 ) {
if ( V_61 == NULL )
V_3 -> V_58 = V_60 -> V_59 ;
else
V_61 -> V_59 = V_60 -> V_59 ;
F_33 ( V_60 ) ;
}
F_31 ( & V_3 -> V_56 , V_47 ) ;
return V_60 ? 0 : - 1 ;
}
int F_34 ( struct V_1 * V_7 , int V_62 , T_3 V_63 )
{
struct V_9 * V_10 ;
T_4 V_64 = F_35 ( V_63 ) ;
V_10 = F_3 ( V_7 ) ;
return V_10 -> V_3 -> F_28 -> V_65 ( V_7 , V_62 , & V_64 , 2 ) ;
}
int F_36 ( struct V_1 * V_7 , int V_62 , const char * V_63 )
{
struct V_9 * V_10 ;
char V_66 [ V_67 + 2 ] ;
int V_68 ;
V_10 = F_3 ( V_7 ) ;
V_68 = strlen ( V_63 ) ;
if ( V_68 > V_67 )
return - 1 ;
memset ( V_66 , 0 , sizeof( V_66 ) ) ;
V_66 [ 0 ] = V_68 ;
memcpy ( V_66 + 2 , V_63 , V_68 ) ;
return V_10 -> V_3 -> F_28 -> V_65 ( V_7 , V_62 , & V_66 , V_67 + 2 ) ;
}
T_3 F_37 ( T_2 * V_3 )
{
if ( V_3 -> V_69 == V_70 && V_3 -> V_71 )
return V_72 ;
if ( V_3 -> V_69 == V_70 )
return V_73 ;
if ( V_3 -> V_69 == V_74 )
return V_75 ;
if ( V_3 -> V_69 == V_76 )
return V_77 ;
if ( V_3 -> V_69 == V_78 )
return V_72 ;
return V_79 ;
}
int F_38 ( T_2 * V_3 )
{
T_3 V_63 , V_80 ;
int V_81 , V_82 , V_68 , V_57 ;
char V_83 [ V_84 + 1 ] ;
enum { V_85 , V_86 , V_87 } V_88 ;
V_57 = V_3 -> V_89 . V_90 ;
if ( V_3 -> V_89 . V_91 [ V_57 ] == NULL ||
V_3 -> V_89 . V_91 [ V_57 ] -> V_92 == NULL )
V_88 = V_85 ;
else if ( strcmp ( V_3 -> V_89 . V_91 [ V_57 ] -> V_92 -> V_6 , L_7 ) == 0 )
V_88 = V_86 ;
else
V_88 = V_87 ;
if ( V_3 -> F_28 -> V_93 ( V_3 -> V_7 , V_94 , & V_63 , 2 ,
1 ) < 0 ) {
F_11 ( V_22 L_8 ) ;
goto V_95;
}
F_39 ( & V_63 ) ;
V_80 = V_63 ;
if ( V_88 != V_85 || V_3 -> V_96 )
V_63 |= V_97 ;
else
V_63 &= ~ V_97 ;
if ( V_3 -> V_98 || V_88 == V_85 ||
( ( V_3 -> V_99 || V_3 -> V_100 ) && V_3 -> V_101 ) )
V_63 &= ~ V_102 ;
else
V_63 |= V_102 ;
if ( ( V_88 != V_85 || V_3 -> V_96 ) &&
( V_88 == V_87 || V_3 -> V_103 ) )
V_63 |= V_104 ;
else
V_63 &= ~ V_104 ;
if ( ( V_88 != V_85 || V_3 -> V_96 ) &&
( V_88 == V_87 || V_3 -> V_101 ) )
V_63 |= V_105 ;
else
V_63 &= ~ V_105 ;
if ( V_63 != V_80 &&
F_34 ( V_3 -> V_7 , V_94 , V_63 ) ) {
F_11 ( V_22 L_9 ,
V_63 ) ;
goto V_95;
}
if ( V_88 != V_86 )
return 0 ;
V_82 = 6 ;
V_68 = V_3 -> V_89 . V_91 [ V_57 ] -> V_92 -> V_106 ( V_83 , sizeof( V_83 ) , NULL ,
V_3 -> V_89 . V_91 [ V_57 ] -> V_107 ) ;
if ( V_57 >= 0 && V_57 < V_108 && V_68 > 5 )
V_82 = V_84 + 1 ;
for ( V_81 = 0 ; V_81 < V_108 ; V_81 ++ ) {
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
if ( V_3 -> V_89 . V_91 [ V_81 ] ) {
( void ) V_3 -> V_89 . V_91 [ V_81 ] -> V_92 -> V_106 (
V_83 , sizeof( V_83 ) ,
NULL , V_3 -> V_89 . V_91 [ V_81 ] -> V_107 ) ;
}
if ( V_3 -> F_28 -> V_65 ( V_3 -> V_7 ,
V_109 + V_81 ,
V_83 , V_82 ) ) {
F_11 ( V_22 L_10 ,
V_81 , V_82 ) ;
goto V_95;
}
}
if ( F_34 ( V_3 -> V_7 , V_110 , V_57 ) ) {
F_11 ( V_22 L_11 , V_57 ) ;
goto V_95;
}
return 0 ;
V_95:
F_11 ( V_22 L_12 , V_3 -> V_7 -> V_6 ) ;
return - 1 ;
}
int F_40 ( T_2 * V_3 )
{
T_3 V_63 ;
int V_11 = 0 ;
if ( V_3 -> V_111 != V_112 &&
V_3 -> F_28 -> V_113 ( V_3 -> V_7 , V_114 ,
V_115 ,
NULL , & V_63 ) == 0 ) {
V_63 &= ~ ( F_41 ( 2 ) | F_41 ( 1 ) ) ;
switch ( V_3 -> V_111 ) {
case V_116 :
V_63 |= F_41 ( 1 ) ;
break;
case V_117 :
break;
case V_118 :
V_63 |= F_41 ( 2 ) ;
break;
}
if ( V_3 -> F_28 -> V_113 ( V_3 -> V_7 , V_119 ,
V_115 , & V_63 , NULL ) ) {
F_11 ( V_120 L_13 ,
V_3 -> V_7 -> V_6 ) ;
V_11 = - 1 ;
}
}
if ( V_3 -> V_121 != V_112 &&
V_3 -> F_28 -> V_113 ( V_3 -> V_7 , V_114 ,
V_122 ,
NULL , & V_63 ) == 0 ) {
V_63 &= ~ ( F_41 ( 1 ) | F_41 ( 0 ) ) ;
switch ( V_3 -> V_121 ) {
case V_116 :
break;
case V_117 :
V_63 |= F_41 ( 0 ) ;
break;
case V_118 :
V_63 |= F_41 ( 0 ) | F_41 ( 1 ) ;
break;
}
if ( V_3 -> F_28 -> V_113 ( V_3 -> V_7 , V_119 ,
V_122 , & V_63 , NULL ) ) {
F_11 ( V_120 L_14 ,
V_3 -> V_7 -> V_6 ) ;
V_11 = - 1 ;
}
}
return V_11 ;
}
int F_42 ( T_2 * V_3 )
{
T_3 V_63 ;
switch ( V_3 -> V_123 ) {
case 1 :
V_63 = V_124 ;
break;
case 2 :
V_63 = V_125 ;
break;
case 0 :
default:
V_63 = V_126 ;
break;
}
return F_34 ( V_3 -> V_7 , V_127 , V_63 ) ;
}
int F_43 ( T_2 * V_3 )
{
int V_63 = V_3 -> V_128 ;
if ( V_3 -> V_129 < F_44 ( 0 , 7 , 0 ) &&
V_63 != V_130 && V_63 != V_131 )
V_63 = V_130 ;
if ( F_34 ( V_3 -> V_7 , V_132 , V_63 ) ) {
F_11 ( V_120 L_15
L_16 , V_3 -> V_7 -> V_6 , V_3 -> V_128 ) ;
return - V_44 ;
}
return 0 ;
}
void F_45 ( const char * V_6 , const struct V_133 * V_134 )
{
T_3 V_135 , V_136 ;
V_135 = F_46 ( V_134 -> V_135 ) ;
F_11 ( V_22 L_17
L_18
L_19 ,
V_6 , V_135 , ( V_135 >> 8 ) & 0x07 , V_135 >> 13 , V_135 & 1 ,
V_134 -> V_137 , V_134 -> signal , V_134 -> V_138 , V_134 -> V_139 , V_140 ) ;
V_136 = F_46 ( V_134 -> V_141 ) ;
F_11 ( V_22 L_20
L_21 ,
V_136 , ( V_136 & V_142 ) >> 2 ,
( V_136 & V_143 ) >> 4 ,
F_46 ( V_134 -> V_144 ) , F_46 ( V_134 -> V_145 ) ,
F_46 ( V_134 -> V_146 ) ,
V_136 & V_147 ? L_22 : L_23 ,
V_136 & V_148 ? L_24 : L_23 ) ;
F_11 ( V_22 L_25 ,
V_134 -> V_149 , V_134 -> V_150 , V_134 -> V_151 , V_134 -> V_152 ) ;
F_11 ( V_22 L_26 ,
V_134 -> V_153 , V_134 -> V_154 ,
F_47 ( V_134 -> V_68 ) ) ;
}
void F_48 ( const char * V_6 , const struct V_155 * V_156 )
{
T_3 V_136 ;
F_11 ( V_22 L_27
L_28 ,
V_6 , F_46 ( V_156 -> V_135 ) , V_156 -> V_157 , V_156 -> V_158 ,
F_46 ( V_156 -> V_159 ) , V_140 ) ;
V_136 = F_46 ( V_156 -> V_141 ) ;
F_11 ( V_22 L_20
L_21 ,
V_136 , ( V_136 & V_142 ) >> 2 ,
( V_136 & V_143 ) >> 4 ,
F_46 ( V_156 -> V_144 ) , F_46 ( V_156 -> V_145 ) ,
F_46 ( V_156 -> V_146 ) ,
V_136 & V_147 ? L_22 : L_23 ,
V_136 & V_148 ? L_24 : L_23 ) ;
F_11 ( V_22 L_25 ,
V_156 -> V_149 , V_156 -> V_150 , V_156 -> V_151 , V_156 -> V_152 ) ;
F_11 ( V_22 L_26 ,
V_156 -> V_153 , V_156 -> V_154 ,
F_47 ( V_156 -> V_68 ) ) ;
}
static int F_49 ( const struct V_50 * V_160 ,
unsigned char * V_161 )
{
memcpy ( V_161 , F_50 ( V_160 ) + 10 , V_37 ) ;
return V_37 ;
}
int F_51 ( T_4 V_136 )
{
if ( F_52 ( V_136 ) && F_53 ( V_136 ) )
return 30 ;
else if ( F_54 ( V_136 ) || F_55 ( V_136 ) )
return 10 ;
else if ( F_56 ( V_136 ) )
return 16 ;
return 24 ;
}
static int F_57 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
F_58 ( V_162 , L_29 , V_7 -> V_6 ) ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_7 == V_3 -> V_24 ) {
F_59 ( V_3 , V_163 ) ;
}
#ifndef F_60
if ( ! V_3 -> V_164 && V_7 == V_3 -> V_7 &&
( ! V_3 -> F_28 -> V_165 || V_3 -> F_28 -> V_165 ( V_3 ) ) &&
V_3 -> V_166 && V_3 -> V_39 && V_3 -> V_69 == V_167 )
F_61 ( V_7 , V_3 -> V_39 , 1 ) ;
#endif
if ( V_7 == V_3 -> V_7 ) {
V_3 -> F_28 -> V_168 ( V_7 , V_169 ) ;
}
if ( F_62 ( V_7 ) ) {
F_63 ( V_7 ) ;
F_64 ( V_7 ) ;
}
F_65 ( & V_3 -> V_170 ) ;
F_65 ( & V_3 -> V_171 ) ;
F_65 ( & V_3 -> V_172 ) ;
#ifndef F_66
F_65 ( & V_3 -> V_173 ) ;
#endif
F_65 ( & V_3 -> V_174 ) ;
F_67 ( V_3 -> V_175 ) ;
V_3 -> V_176 -- ;
if ( V_7 != V_3 -> V_7 && V_3 -> V_7 -> V_47 & V_177 &&
V_3 -> V_178 && V_3 -> V_176 == 1 ) {
F_68 ( V_3 -> V_7 ) ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
F_58 ( V_162 , L_30 , V_7 -> V_6 ) ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_3 -> V_179 ) {
F_11 ( V_22 L_31
L_32 , V_7 -> V_6 ) ;
return - V_49 ;
}
if ( ( V_3 -> F_28 -> V_165 && ! V_3 -> F_28 -> V_165 ( V_3 ) ) ||
V_3 -> V_180 )
return - V_49 ;
if ( ! F_70 ( V_3 -> V_175 ) )
return - V_49 ;
V_3 -> V_176 ++ ;
if ( ! V_3 -> V_181 && V_3 -> F_28 -> V_182 ( V_7 , 1 ) ) {
F_11 ( V_21 L_33 ,
V_7 -> V_6 ) ;
F_57 ( V_7 ) ;
return - V_49 ;
}
if ( ! V_3 -> V_181 )
F_71 ( V_3 , V_183 ) ;
V_3 -> V_181 = 1 ;
if ( V_7 != V_3 -> V_7 && ! ( V_3 -> V_7 -> V_47 & V_177 ) ) {
V_3 -> V_178 = 1 ;
F_72 ( V_3 -> V_7 ) ;
}
F_73 ( V_7 ) ;
F_74 ( V_7 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_7 , void * V_184 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
struct V_29 * V_30 ;
struct V_185 * V_27 = V_184 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_3 -> F_28 -> V_65 ( V_7 , V_186 , V_27 -> V_187 ,
V_37 ) < 0 || V_3 -> F_28 -> V_188 ( V_7 ) )
return - V_44 ;
F_18 ( & V_3 -> V_33 ) ;
F_19 (ptr, &local->hostap_interfaces) {
V_10 = F_20 ( V_30 , struct V_9 , V_12 ) ;
memcpy ( V_10 -> V_7 -> V_189 , V_27 -> V_187 , V_37 ) ;
}
memcpy ( V_3 -> V_7 -> V_189 , V_27 -> V_187 , V_37 ) ;
F_22 ( & V_3 -> V_33 ) ;
return 0 ;
}
void F_76 ( struct V_190 * V_191 )
{
T_2 * V_3 =
F_77 ( V_191 , T_2 , V_171 ) ;
struct V_1 * V_7 = V_3 -> V_7 ;
if ( F_34 ( V_7 , V_192 ,
V_3 -> V_193 ) ) {
F_11 ( V_120 L_34 ,
V_7 -> V_6 , V_3 -> V_193 ? L_35 : L_36 ) ;
}
}
static void F_78 ( struct V_1 * V_7 )
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
static int F_79 ( struct V_1 * V_7 , int V_194 )
{
if ( V_194 < V_195 || V_194 > V_196 )
return - V_44 ;
V_7 -> V_197 = V_194 ;
return 0 ;
}
static void F_80 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
struct V_198 V_199 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
F_11 ( V_21 L_37 , V_7 -> V_6 ) ;
F_63 ( V_3 -> V_7 ) ;
V_3 -> F_28 -> V_200 ( V_7 , & V_199 ) ;
F_11 ( V_22 L_38
L_39 ,
V_7 -> V_6 , V_199 . V_113 , V_199 . V_201 , V_199 . V_202 , V_199 . V_203 ,
V_199 . V_204 ) ;
V_3 -> F_28 -> V_205 ( V_3 ) ;
}
void F_6 ( struct V_1 * V_7 , T_2 * V_3 ,
int type )
{
struct V_9 * V_10 ;
V_10 = F_3 ( V_7 ) ;
F_81 ( V_7 ) ;
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
F_82 ( V_7 , & V_224 ) ;
}
static int F_83 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
if ( V_3 -> V_25 )
return - V_38 ;
F_11 ( V_22 L_40 , V_7 -> V_6 ) ;
V_3 -> V_25 = F_1 ( V_3 , V_214 ,
V_4 , V_3 -> V_24 -> V_6 ,
L_41 ) ;
if ( V_3 -> V_25 == NULL )
return - V_45 ;
return 0 ;
}
static int F_84 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
F_11 ( V_22 L_42 , V_7 -> V_6 ) ;
F_12 ( V_3 -> V_25 , V_4 , 1 ) ;
V_3 -> V_25 = NULL ;
return 0 ;
}
static int F_85 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
if ( V_3 -> V_26 )
return - V_38 ;
F_11 ( V_22 L_43 , V_7 -> V_6 ) ;
V_3 -> V_26 = F_1 ( V_3 , V_225 ,
V_4 , V_3 -> V_24 -> V_6 ,
L_44 ) ;
if ( V_3 -> V_26 == NULL )
return - V_45 ;
return 0 ;
}
static int F_86 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
F_11 ( V_22 L_42 , V_7 -> V_6 ) ;
F_12 ( V_3 -> V_26 , V_4 , 1 ) ;
V_3 -> V_26 = NULL ;
return 0 ;
}
int F_87 ( T_2 * V_3 , int V_63 , int V_4 )
{
int V_11 ;
if ( V_63 < 0 || V_63 > 1 )
return - V_44 ;
if ( V_3 -> V_164 == V_63 )
return 0 ;
if ( V_63 ) {
V_11 = F_83 ( V_3 , V_4 ) ;
if ( V_11 == 0 )
V_3 -> V_164 = 1 ;
} else {
V_3 -> V_164 = 0 ;
V_11 = F_84 ( V_3 , V_4 ) ;
if ( V_11 != 0 )
V_3 -> V_164 = 1 ;
}
return V_11 ;
}
int F_88 ( T_2 * V_3 , int V_63 , int V_4 )
{
int V_11 ;
if ( V_63 < 0 || V_63 > 1 )
return - V_44 ;
if ( V_3 -> V_226 == V_63 )
return 0 ;
if ( V_63 ) {
V_11 = F_85 ( V_3 , V_4 ) ;
if ( V_11 == 0 )
V_3 -> V_226 = 1 ;
} else {
V_3 -> V_226 = 0 ;
V_11 = F_86 ( V_3 , V_4 ) ;
if ( V_11 != 0 )
V_3 -> V_226 = 1 ;
}
return V_11 ;
}
int F_89 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
int V_11 = 0 ;
struct V_227 V_228 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( ! V_3 -> V_129 )
V_11 = - 1 ;
else if ( V_3 -> V_129 >= F_44 ( 1 , 3 , 1 ) ) {
if ( V_3 -> F_28 -> V_93 ( V_3 -> V_7 ,
V_229 ,
& V_228 , sizeof( V_228 ) , 1 ) >= 0 ) {
V_3 -> V_230 = ( V_231 ) F_90 ( V_228 . V_232 ) ;
V_3 -> V_233 = ( V_231 ) F_90 ( V_228 . V_234 ) ;
V_3 -> V_235 = ( V_231 ) F_90 ( V_228 . V_236 ) ;
V_3 -> V_237 = V_140 ;
} else
V_11 = - 1 ;
} else {
if ( V_3 -> F_28 -> V_93 ( V_3 -> V_7 , V_238 ,
& V_228 , sizeof( V_228 ) , 1 ) >= 0 ) {
V_3 -> V_230 = F_90 ( V_228 . V_232 ) ;
V_3 -> V_233 = F_91 (
F_90 ( V_228 . V_234 ) ) ;
V_3 -> V_235 = F_91 (
F_90 ( V_228 . V_236 ) ) ;
V_3 -> V_237 = V_140 ;
} else
V_11 = - 1 ;
}
return V_11 ;
}
int F_92 ( T_2 * V_3 , T_1 * V_239 , T_3 V_240 ,
T_1 * V_241 , T_5 V_242 )
{
struct V_50 * V_160 ;
struct V_243 * V_244 ;
struct V_245 * V_246 ;
struct V_1 * V_7 = V_3 -> V_7 ;
V_160 = F_93 ( V_247 + V_242 ) ;
if ( V_160 == NULL )
return - V_45 ;
V_244 = (struct V_243 * )
F_94 ( V_160 , V_247 ) ;
memset ( V_244 , 0 , V_247 ) ;
V_244 -> V_141 = F_35 ( V_248 | V_240 ) ;
memcpy ( V_244 -> V_249 , V_239 , V_37 ) ;
memcpy ( V_244 -> V_250 , V_7 -> V_189 , V_37 ) ;
memcpy ( V_244 -> V_251 , V_239 , V_37 ) ;
if ( V_241 )
memcpy ( F_94 ( V_160 , V_242 ) , V_241 , V_242 ) ;
V_246 = (struct V_245 * ) V_160 -> V_60 ;
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_252 = V_253 ;
V_246 -> V_10 = F_3 ( V_7 ) ;
V_160 -> V_7 = V_7 ;
F_95 ( V_160 ) ;
F_96 ( V_160 ) ;
F_97 ( V_160 ) ;
return 0 ;
}
int F_59 ( T_2 * V_3 , T_3 V_254 )
{
union V_255 V_256 ;
int V_11 ;
T_4 V_63 = F_35 ( V_254 ) ;
if ( V_3 -> V_69 != V_74 ||
F_98 ( V_3 -> V_251 ) ||
F_21 ( V_3 -> V_251 , L_45 ) )
return 0 ;
V_11 = F_92 ( V_3 , V_3 -> V_251 , V_257 ,
( T_1 * ) & V_63 , 2 ) ;
memset ( V_256 . V_258 . V_187 , 0 , V_37 ) ;
F_99 ( V_3 -> V_7 , V_259 , & V_256 , NULL ) ;
return V_11 ;
}
static int T_6 F_100 ( void )
{
if ( V_260 . V_261 != NULL ) {
V_262 = F_101 ( L_46 , V_260 . V_261 ) ;
if ( ! V_262 )
F_11 ( V_21 L_47
L_48 ) ;
} else
V_262 = NULL ;
return 0 ;
}
static void T_7 F_102 ( void )
{
if ( V_262 != NULL ) {
V_262 = NULL ;
F_103 ( L_46 , V_260 . V_261 ) ;
}
}
