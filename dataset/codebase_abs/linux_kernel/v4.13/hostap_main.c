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
V_7 -> V_18 = true ;
sprintf ( V_7 -> V_6 , L_1 , V_5 , V_6 ) ;
if ( ! V_4 )
F_7 () ;
F_8 ( V_7 , V_8 -> V_7 . V_19 ) ;
V_11 = F_9 ( V_7 ) ;
if ( ! V_4 )
F_10 () ;
if ( V_11 < 0 ) {
F_11 ( V_20 L_2 ,
V_7 -> V_6 ) ;
F_12 ( V_7 ) ;
return NULL ;
}
F_11 ( V_21 L_3 ,
V_8 -> V_6 , V_7 -> V_6 ) ;
return V_7 ;
}
void F_13 ( struct V_1 * V_7 , int V_4 ,
int V_22 )
{
struct V_9 * V_10 ;
if ( ! V_7 )
return;
V_10 = F_3 ( V_7 ) ;
if ( V_22 ) {
F_14 ( & V_10 -> V_12 ) ;
}
if ( V_7 == V_10 -> V_3 -> V_23 )
V_10 -> V_3 -> V_23 = NULL ;
else if ( V_7 == V_10 -> V_3 -> V_24 )
V_10 -> V_3 -> V_24 = NULL ;
else if ( V_7 == V_10 -> V_3 -> V_25 )
V_10 -> V_3 -> V_25 = NULL ;
if ( V_4 )
F_15 ( V_7 ) ;
else
F_16 ( V_7 ) ;
}
static inline int F_17 ( T_1 * V_26 )
{
if ( V_26 [ 0 ] || V_26 [ 1 ] || V_26 [ 2 ] || V_26 [ 3 ] || V_26 [ 4 ] || V_26 [ 5 ] )
return 0 ;
return 1 ;
}
int F_18 ( T_2 * V_3 , T_1 * V_27 ,
int V_4 )
{
struct V_1 * V_7 ;
struct V_28 * V_29 ;
struct V_9 * V_10 , * V_30 , * V_31 ;
V_30 = V_31 = NULL ;
F_19 ( & V_3 -> V_32 ) ;
F_20 (ptr, &local->hostap_interfaces) {
V_10 = F_21 ( V_29 , struct V_9 , V_12 ) ;
if ( V_10 -> type != V_33 )
continue;
if ( F_17 ( V_10 -> V_34 . V_35 . V_27 ) )
V_30 = V_10 ;
else if ( F_22 ( V_10 -> V_34 . V_35 . V_27 , V_27 ) ) {
V_31 = V_10 ;
break;
}
}
if ( ! V_31 && V_30 && ! F_17 ( V_27 ) ) {
memcpy ( V_30 -> V_34 . V_35 . V_27 , V_27 , V_36 ) ;
F_23 ( & V_3 -> V_32 ) ;
F_11 ( V_21 L_4 ,
V_3 -> V_7 -> V_6 , V_30 -> V_7 -> V_6 ) ;
return 0 ;
}
F_23 ( & V_3 -> V_32 ) ;
if ( ! F_17 ( V_27 ) ) {
if ( V_31 )
return - V_37 ;
F_24 ( V_3 -> V_38 , V_27 ) ;
}
if ( V_3 -> V_39 >= V_3 -> V_40 )
return - V_41 ;
if ( strlen ( V_3 -> V_7 -> V_6 ) >= V_42 - 5 ) {
F_11 ( V_21 L_5 ,
V_3 -> V_7 -> V_6 ) ;
return - V_43 ;
}
V_7 = F_1 ( V_3 , V_33 , V_4 ,
V_3 -> V_23 -> V_6 , L_6 ) ;
if ( V_7 == NULL )
return - V_44 ;
V_10 = F_3 ( V_7 ) ;
memcpy ( V_10 -> V_34 . V_35 . V_27 , V_27 , V_36 ) ;
V_3 -> V_39 ++ ;
return 0 ;
}
int F_25 ( T_2 * V_3 , T_1 * V_27 ,
int V_4 , int V_45 )
{
unsigned long V_46 ;
struct V_28 * V_29 ;
struct V_9 * V_10 , * V_47 = NULL ;
F_26 ( & V_3 -> V_32 , V_46 ) ;
F_20 (ptr, &local->hostap_interfaces) {
V_10 = F_21 ( V_29 , struct V_9 , V_12 ) ;
if ( V_10 -> type != V_33 )
continue;
if ( F_22 ( V_10 -> V_34 . V_35 . V_27 , V_27 ) ) {
V_47 = V_10 ;
break;
}
}
if ( V_47 && ! V_45 )
F_14 ( & V_47 -> V_12 ) ;
F_27 ( & V_3 -> V_32 , V_46 ) ;
if ( V_47 ) {
if ( V_45 )
F_28 ( V_47 -> V_34 . V_35 . V_27 ) ;
else {
F_13 ( V_47 -> V_7 , V_4 , 0 ) ;
V_3 -> V_39 -- ;
}
}
return V_47 ? 0 : - V_48 ;
}
T_3 F_29 ( T_2 * V_3 ,
void (* F_30)( struct V_49 * , int V_50 , void * ) ,
void * V_51 )
{
unsigned long V_46 ;
struct V_52 * V_53 ;
V_53 = F_31 ( sizeof( * V_53 ) , V_54 ) ;
if ( V_53 == NULL )
return 0 ;
V_53 -> F_30 = F_30 ;
V_53 -> V_51 = V_51 ;
F_32 ( & V_3 -> V_55 , V_46 ) ;
V_53 -> V_56 = V_3 -> V_57 ? V_3 -> V_57 -> V_56 + 1 : 1 ;
V_53 -> V_58 = V_3 -> V_57 ;
V_3 -> V_57 = V_53 ;
F_33 ( & V_3 -> V_55 , V_46 ) ;
return V_53 -> V_56 ;
}
int F_34 ( T_2 * V_3 , T_3 V_56 )
{
unsigned long V_46 ;
struct V_52 * V_59 , * V_60 = NULL ;
F_32 ( & V_3 -> V_55 , V_46 ) ;
V_59 = V_3 -> V_57 ;
while ( V_59 != NULL && V_59 -> V_56 != V_56 ) {
V_60 = V_59 ;
V_59 = V_59 -> V_58 ;
}
if ( V_59 ) {
if ( V_60 == NULL )
V_3 -> V_57 = V_59 -> V_58 ;
else
V_60 -> V_58 = V_59 -> V_58 ;
F_35 ( V_59 ) ;
}
F_33 ( & V_3 -> V_55 , V_46 ) ;
return V_59 ? 0 : - 1 ;
}
int F_36 ( struct V_1 * V_7 , int V_61 , T_3 V_62 )
{
struct V_9 * V_10 ;
T_4 V_63 = F_37 ( V_62 ) ;
V_10 = F_3 ( V_7 ) ;
return V_10 -> V_3 -> F_30 -> V_64 ( V_7 , V_61 , & V_63 , 2 ) ;
}
int F_38 ( struct V_1 * V_7 , int V_61 , const char * V_62 )
{
struct V_9 * V_10 ;
char V_65 [ V_66 + 2 ] ;
int V_67 ;
V_10 = F_3 ( V_7 ) ;
V_67 = strlen ( V_62 ) ;
if ( V_67 > V_66 )
return - 1 ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
V_65 [ 0 ] = V_67 ;
memcpy ( V_65 + 2 , V_62 , V_67 ) ;
return V_10 -> V_3 -> F_30 -> V_64 ( V_7 , V_61 , & V_65 , V_66 + 2 ) ;
}
T_3 F_39 ( T_2 * V_3 )
{
if ( V_3 -> V_68 == V_69 && V_3 -> V_70 )
return V_71 ;
if ( V_3 -> V_68 == V_69 )
return V_72 ;
if ( V_3 -> V_68 == V_73 )
return V_74 ;
if ( V_3 -> V_68 == V_75 )
return V_76 ;
if ( V_3 -> V_68 == V_77 )
return V_71 ;
return V_78 ;
}
int F_40 ( T_2 * V_3 )
{
T_3 V_62 , V_79 ;
int V_80 , V_81 , V_67 , V_56 ;
char V_82 [ V_83 + 1 ] ;
enum { V_84 , V_85 , V_86 } V_87 ;
V_56 = V_3 -> V_88 . V_89 ;
if ( V_3 -> V_88 . V_90 [ V_56 ] == NULL ||
V_3 -> V_88 . V_90 [ V_56 ] -> V_91 == NULL )
V_87 = V_84 ;
else if ( strcmp ( V_3 -> V_88 . V_90 [ V_56 ] -> V_91 -> V_6 , L_7 ) == 0 )
V_87 = V_85 ;
else
V_87 = V_86 ;
if ( V_3 -> F_30 -> V_92 ( V_3 -> V_7 , V_93 , & V_62 , 2 ,
1 ) < 0 ) {
F_11 ( V_21 L_8 ) ;
goto V_94;
}
F_41 ( & V_62 ) ;
V_79 = V_62 ;
if ( V_87 != V_84 || V_3 -> V_95 )
V_62 |= V_96 ;
else
V_62 &= ~ V_96 ;
if ( V_3 -> V_97 || V_87 == V_84 ||
( ( V_3 -> V_98 || V_3 -> V_99 ) && V_3 -> V_100 ) )
V_62 &= ~ V_101 ;
else
V_62 |= V_101 ;
if ( ( V_87 != V_84 || V_3 -> V_95 ) &&
( V_87 == V_86 || V_3 -> V_102 ) )
V_62 |= V_103 ;
else
V_62 &= ~ V_103 ;
if ( ( V_87 != V_84 || V_3 -> V_95 ) &&
( V_87 == V_86 || V_3 -> V_100 ) )
V_62 |= V_104 ;
else
V_62 &= ~ V_104 ;
if ( V_62 != V_79 &&
F_36 ( V_3 -> V_7 , V_93 , V_62 ) ) {
F_11 ( V_21 L_9 ,
V_62 ) ;
goto V_94;
}
if ( V_87 != V_85 )
return 0 ;
V_81 = 6 ;
V_67 = V_3 -> V_88 . V_90 [ V_56 ] -> V_91 -> V_105 ( V_82 , sizeof( V_82 ) , NULL ,
V_3 -> V_88 . V_90 [ V_56 ] -> V_106 ) ;
if ( V_56 >= 0 && V_56 < V_107 && V_67 > 5 )
V_81 = V_83 + 1 ;
for ( V_80 = 0 ; V_80 < V_107 ; V_80 ++ ) {
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
if ( V_3 -> V_88 . V_90 [ V_80 ] ) {
( void ) V_3 -> V_88 . V_90 [ V_80 ] -> V_91 -> V_105 (
V_82 , sizeof( V_82 ) ,
NULL , V_3 -> V_88 . V_90 [ V_80 ] -> V_106 ) ;
}
if ( V_3 -> F_30 -> V_64 ( V_3 -> V_7 ,
V_108 + V_80 ,
V_82 , V_81 ) ) {
F_11 ( V_21 L_10 ,
V_80 , V_81 ) ;
goto V_94;
}
}
if ( F_36 ( V_3 -> V_7 , V_109 , V_56 ) ) {
F_11 ( V_21 L_11 , V_56 ) ;
goto V_94;
}
return 0 ;
V_94:
F_11 ( V_21 L_12 , V_3 -> V_7 -> V_6 ) ;
return - 1 ;
}
int F_42 ( T_2 * V_3 )
{
T_3 V_62 ;
int V_11 = 0 ;
if ( V_3 -> V_110 != V_111 &&
V_3 -> F_30 -> V_112 ( V_3 -> V_7 , V_113 ,
V_114 ,
NULL , & V_62 ) == 0 ) {
V_62 &= ~ ( F_43 ( 2 ) | F_43 ( 1 ) ) ;
switch ( V_3 -> V_110 ) {
case V_115 :
V_62 |= F_43 ( 1 ) ;
break;
case V_116 :
break;
case V_117 :
V_62 |= F_43 ( 2 ) ;
break;
}
if ( V_3 -> F_30 -> V_112 ( V_3 -> V_7 , V_118 ,
V_114 , & V_62 , NULL ) ) {
F_11 ( V_119 L_13 ,
V_3 -> V_7 -> V_6 ) ;
V_11 = - 1 ;
}
}
if ( V_3 -> V_120 != V_111 &&
V_3 -> F_30 -> V_112 ( V_3 -> V_7 , V_113 ,
V_121 ,
NULL , & V_62 ) == 0 ) {
V_62 &= ~ ( F_43 ( 1 ) | F_43 ( 0 ) ) ;
switch ( V_3 -> V_120 ) {
case V_115 :
break;
case V_116 :
V_62 |= F_43 ( 0 ) ;
break;
case V_117 :
V_62 |= F_43 ( 0 ) | F_43 ( 1 ) ;
break;
}
if ( V_3 -> F_30 -> V_112 ( V_3 -> V_7 , V_118 ,
V_121 , & V_62 , NULL ) ) {
F_11 ( V_119 L_14 ,
V_3 -> V_7 -> V_6 ) ;
V_11 = - 1 ;
}
}
return V_11 ;
}
int F_44 ( T_2 * V_3 )
{
T_3 V_62 ;
switch ( V_3 -> V_122 ) {
case 1 :
V_62 = V_123 ;
break;
case 2 :
V_62 = V_124 ;
break;
case 0 :
default:
V_62 = V_125 ;
break;
}
return F_36 ( V_3 -> V_7 , V_126 , V_62 ) ;
}
int F_45 ( T_2 * V_3 )
{
int V_62 = V_3 -> V_127 ;
if ( V_3 -> V_128 < F_46 ( 0 , 7 , 0 ) &&
V_62 != V_129 && V_62 != V_130 )
V_62 = V_129 ;
if ( F_36 ( V_3 -> V_7 , V_131 , V_62 ) ) {
F_11 ( V_119 L_15
L_16 , V_3 -> V_7 -> V_6 , V_3 -> V_127 ) ;
return - V_43 ;
}
return 0 ;
}
void F_47 ( const char * V_6 , const struct V_132 * V_133 )
{
T_3 V_134 , V_135 ;
V_134 = F_48 ( V_133 -> V_134 ) ;
F_11 ( V_21 L_17
L_18
L_19 ,
V_6 , V_134 , ( V_134 >> 8 ) & 0x07 , V_134 >> 13 , V_134 & 1 ,
V_133 -> V_136 , V_133 -> signal , V_133 -> V_137 , V_133 -> V_138 , V_139 ) ;
V_135 = F_48 ( V_133 -> V_140 ) ;
F_11 ( V_21 L_20
L_21 ,
V_135 , ( V_135 & V_141 ) >> 2 ,
( V_135 & V_142 ) >> 4 ,
F_48 ( V_133 -> V_143 ) , F_48 ( V_133 -> V_144 ) ,
F_48 ( V_133 -> V_145 ) ,
V_135 & V_146 ? L_22 : L_23 ,
V_135 & V_147 ? L_24 : L_23 ) ;
F_11 ( V_21 L_25 ,
V_133 -> V_148 , V_133 -> V_149 , V_133 -> V_150 , V_133 -> V_151 ) ;
F_11 ( V_21 L_26 ,
V_133 -> V_152 , V_133 -> V_153 ,
F_49 ( V_133 -> V_67 ) ) ;
}
void F_50 ( const char * V_6 , const struct V_154 * V_155 )
{
T_3 V_135 ;
F_11 ( V_21 L_27
L_28 ,
V_6 , F_48 ( V_155 -> V_134 ) , V_155 -> V_156 , V_155 -> V_157 ,
F_48 ( V_155 -> V_158 ) , V_139 ) ;
V_135 = F_48 ( V_155 -> V_140 ) ;
F_11 ( V_21 L_20
L_21 ,
V_135 , ( V_135 & V_141 ) >> 2 ,
( V_135 & V_142 ) >> 4 ,
F_48 ( V_155 -> V_143 ) , F_48 ( V_155 -> V_144 ) ,
F_48 ( V_155 -> V_145 ) ,
V_135 & V_146 ? L_22 : L_23 ,
V_135 & V_147 ? L_24 : L_23 ) ;
F_11 ( V_21 L_25 ,
V_155 -> V_148 , V_155 -> V_149 , V_155 -> V_150 , V_155 -> V_151 ) ;
F_11 ( V_21 L_26 ,
V_155 -> V_152 , V_155 -> V_153 ,
F_49 ( V_155 -> V_67 ) ) ;
}
static int F_51 ( const struct V_49 * V_159 ,
unsigned char * V_160 )
{
memcpy ( V_160 , F_52 ( V_159 ) + 10 , V_36 ) ;
return V_36 ;
}
int F_53 ( T_4 V_135 )
{
if ( F_54 ( V_135 ) && F_55 ( V_135 ) )
return 30 ;
else if ( F_56 ( V_135 ) || F_57 ( V_135 ) )
return 10 ;
else if ( F_58 ( V_135 ) )
return 16 ;
return 24 ;
}
static int F_59 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
F_60 ( V_161 , L_29 , V_7 -> V_6 ) ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_7 == V_3 -> V_23 ) {
F_61 ( V_3 , V_162 ) ;
}
#ifndef F_62
if ( ! V_3 -> V_163 && V_7 == V_3 -> V_7 &&
( ! V_3 -> F_30 -> V_164 || V_3 -> F_30 -> V_164 ( V_3 ) ) &&
V_3 -> V_165 && V_3 -> V_38 && V_3 -> V_68 == V_166 )
F_63 ( V_7 , V_3 -> V_38 , 1 ) ;
#endif
if ( V_7 == V_3 -> V_7 ) {
V_3 -> F_30 -> V_167 ( V_7 , V_168 ) ;
}
if ( F_64 ( V_7 ) ) {
F_65 ( V_7 ) ;
F_66 ( V_7 ) ;
}
F_67 ( & V_3 -> V_169 ) ;
F_67 ( & V_3 -> V_170 ) ;
F_67 ( & V_3 -> V_171 ) ;
#ifndef F_68
F_67 ( & V_3 -> V_172 ) ;
#endif
F_67 ( & V_3 -> V_173 ) ;
F_69 ( V_3 -> V_174 ) ;
V_3 -> V_175 -- ;
if ( V_7 != V_3 -> V_7 && V_3 -> V_7 -> V_46 & V_176 &&
V_3 -> V_177 && V_3 -> V_175 == 1 ) {
F_70 ( V_3 -> V_7 ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
F_60 ( V_161 , L_30 , V_7 -> V_6 ) ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_3 -> V_178 ) {
F_11 ( V_21 L_31
L_32 , V_7 -> V_6 ) ;
return - V_48 ;
}
if ( ( V_3 -> F_30 -> V_164 && ! V_3 -> F_30 -> V_164 ( V_3 ) ) ||
V_3 -> V_179 )
return - V_48 ;
if ( ! F_72 ( V_3 -> V_174 ) )
return - V_48 ;
V_3 -> V_175 ++ ;
if ( ! V_3 -> V_180 && V_3 -> F_30 -> V_181 ( V_7 , 1 ) ) {
F_11 ( V_20 L_33 ,
V_7 -> V_6 ) ;
F_59 ( V_7 ) ;
return - V_48 ;
}
if ( ! V_3 -> V_180 )
F_73 ( V_3 , V_182 ) ;
V_3 -> V_180 = 1 ;
if ( V_7 != V_3 -> V_7 && ! ( V_3 -> V_7 -> V_46 & V_176 ) ) {
V_3 -> V_177 = 1 ;
F_74 ( V_3 -> V_7 ) ;
}
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_7 , void * V_183 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
struct V_28 * V_29 ;
struct V_184 * V_26 = V_183 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( V_3 -> F_30 -> V_64 ( V_7 , V_185 , V_26 -> V_186 ,
V_36 ) < 0 || V_3 -> F_30 -> V_187 ( V_7 ) )
return - V_43 ;
F_19 ( & V_3 -> V_32 ) ;
F_20 (ptr, &local->hostap_interfaces) {
V_10 = F_21 ( V_29 , struct V_9 , V_12 ) ;
memcpy ( V_10 -> V_7 -> V_188 , V_26 -> V_186 , V_36 ) ;
}
memcpy ( V_3 -> V_7 -> V_188 , V_26 -> V_186 , V_36 ) ;
F_23 ( & V_3 -> V_32 ) ;
return 0 ;
}
void F_78 ( struct V_189 * V_190 )
{
T_2 * V_3 =
F_79 ( V_190 , T_2 , V_170 ) ;
struct V_1 * V_7 = V_3 -> V_7 ;
if ( F_36 ( V_7 , V_191 ,
V_3 -> V_192 ) ) {
F_11 ( V_119 L_34 ,
V_7 -> V_6 , V_3 -> V_192 ? L_35 : L_36 ) ;
}
}
static void F_80 ( struct V_1 * V_7 )
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
static void F_81 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
struct V_193 V_194 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
F_11 ( V_20 L_37 , V_7 -> V_6 ) ;
F_65 ( V_3 -> V_7 ) ;
V_3 -> F_30 -> V_195 ( V_7 , & V_194 ) ;
F_11 ( V_21 L_38
L_39 ,
V_7 -> V_6 , V_194 . V_112 , V_194 . V_196 , V_194 . V_197 , V_194 . V_198 ,
V_194 . V_199 ) ;
V_3 -> F_30 -> V_200 ( V_3 ) ;
}
void F_6 ( struct V_1 * V_7 , T_2 * V_3 ,
int type )
{
struct V_9 * V_10 ;
V_10 = F_3 ( V_7 ) ;
F_82 ( V_7 ) ;
V_7 -> V_201 = V_202 ;
V_7 -> V_203 = V_204 ;
V_7 -> V_205 &= ~ V_206 ;
if ( V_10 ) {
V_10 -> V_207 . V_208 = & V_10 -> V_208 ;
V_7 -> V_207 = & V_10 -> V_207 ;
}
V_7 -> V_209 = & V_210 ;
V_7 -> V_211 = V_212 ;
switch( type ) {
case V_213 :
V_7 -> V_205 |= V_214 ;
V_7 -> V_215 = & V_216 ;
V_7 -> type = V_217 ;
V_7 -> V_218 = & V_219 ;
break;
case V_220 :
V_7 -> V_215 = & V_221 ;
break;
default:
V_7 -> V_205 |= V_214 ;
V_7 -> V_215 = & V_222 ;
}
V_7 -> V_223 = V_3 -> V_223 ;
V_7 -> V_224 = & V_225 ;
}
static int F_83 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
if ( V_3 -> V_24 )
return - V_37 ;
F_11 ( V_21 L_40 , V_7 -> V_6 ) ;
V_3 -> V_24 = F_1 ( V_3 , V_213 ,
V_4 , V_3 -> V_23 -> V_6 ,
L_41 ) ;
if ( V_3 -> V_24 == NULL )
return - V_44 ;
return 0 ;
}
static int F_84 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
F_11 ( V_21 L_42 , V_7 -> V_6 ) ;
F_13 ( V_3 -> V_24 , V_4 , 1 ) ;
V_3 -> V_24 = NULL ;
return 0 ;
}
static int F_85 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
if ( V_3 -> V_25 )
return - V_37 ;
F_11 ( V_21 L_43 , V_7 -> V_6 ) ;
V_3 -> V_25 = F_1 ( V_3 , V_226 ,
V_4 , V_3 -> V_23 -> V_6 ,
L_44 ) ;
if ( V_3 -> V_25 == NULL )
return - V_44 ;
return 0 ;
}
static int F_86 ( T_2 * V_3 , int V_4 )
{
struct V_1 * V_7 = V_3 -> V_7 ;
F_11 ( V_21 L_42 , V_7 -> V_6 ) ;
F_13 ( V_3 -> V_25 , V_4 , 1 ) ;
V_3 -> V_25 = NULL ;
return 0 ;
}
int F_87 ( T_2 * V_3 , int V_62 , int V_4 )
{
int V_11 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_43 ;
if ( V_3 -> V_163 == V_62 )
return 0 ;
if ( V_62 ) {
V_11 = F_83 ( V_3 , V_4 ) ;
if ( V_11 == 0 )
V_3 -> V_163 = 1 ;
} else {
V_3 -> V_163 = 0 ;
V_11 = F_84 ( V_3 , V_4 ) ;
if ( V_11 != 0 )
V_3 -> V_163 = 1 ;
}
return V_11 ;
}
int F_88 ( T_2 * V_3 , int V_62 , int V_4 )
{
int V_11 ;
if ( V_62 < 0 || V_62 > 1 )
return - V_43 ;
if ( V_3 -> V_227 == V_62 )
return 0 ;
if ( V_62 ) {
V_11 = F_85 ( V_3 , V_4 ) ;
if ( V_11 == 0 )
V_3 -> V_227 = 1 ;
} else {
V_3 -> V_227 = 0 ;
V_11 = F_86 ( V_3 , V_4 ) ;
if ( V_11 != 0 )
V_3 -> V_227 = 1 ;
}
return V_11 ;
}
int F_89 ( struct V_1 * V_7 )
{
struct V_9 * V_10 ;
T_2 * V_3 ;
int V_11 = 0 ;
struct V_228 V_229 ;
V_10 = F_3 ( V_7 ) ;
V_3 = V_10 -> V_3 ;
if ( ! V_3 -> V_128 )
V_11 = - 1 ;
else if ( V_3 -> V_128 >= F_46 ( 1 , 3 , 1 ) ) {
if ( V_3 -> F_30 -> V_92 ( V_3 -> V_7 ,
V_230 ,
& V_229 , sizeof( V_229 ) , 1 ) >= 0 ) {
V_3 -> V_231 = ( V_232 ) F_90 ( V_229 . V_233 ) ;
V_3 -> V_234 = ( V_232 ) F_90 ( V_229 . V_235 ) ;
V_3 -> V_236 = ( V_232 ) F_90 ( V_229 . V_237 ) ;
V_3 -> V_238 = V_139 ;
} else
V_11 = - 1 ;
} else {
if ( V_3 -> F_30 -> V_92 ( V_3 -> V_7 , V_239 ,
& V_229 , sizeof( V_229 ) , 1 ) >= 0 ) {
V_3 -> V_231 = F_90 ( V_229 . V_233 ) ;
V_3 -> V_234 = F_91 (
F_90 ( V_229 . V_235 ) ) ;
V_3 -> V_236 = F_91 (
F_90 ( V_229 . V_237 ) ) ;
V_3 -> V_238 = V_139 ;
} else
V_11 = - 1 ;
}
return V_11 ;
}
int F_92 ( T_2 * V_3 , T_1 * V_240 , T_3 V_241 ,
T_1 * V_242 , T_5 V_243 )
{
struct V_49 * V_159 ;
struct V_244 * V_245 ;
struct V_246 * V_247 ;
struct V_1 * V_7 = V_3 -> V_7 ;
V_159 = F_93 ( V_248 + V_243 ) ;
if ( V_159 == NULL )
return - V_44 ;
V_245 = F_94 ( V_159 , V_248 ) ;
V_245 -> V_140 = F_37 ( V_249 | V_241 ) ;
memcpy ( V_245 -> V_250 , V_240 , V_36 ) ;
memcpy ( V_245 -> V_251 , V_7 -> V_188 , V_36 ) ;
memcpy ( V_245 -> V_252 , V_240 , V_36 ) ;
if ( V_242 )
F_95 ( V_159 , V_242 , V_243 ) ;
V_247 = (struct V_246 * ) V_159 -> V_59 ;
memset ( V_247 , 0 , sizeof( * V_247 ) ) ;
V_247 -> V_253 = V_254 ;
V_247 -> V_10 = F_3 ( V_7 ) ;
V_159 -> V_7 = V_7 ;
F_96 ( V_159 ) ;
F_97 ( V_159 ) ;
F_98 ( V_159 ) ;
return 0 ;
}
int F_61 ( T_2 * V_3 , T_3 V_255 )
{
union V_256 V_257 ;
int V_11 ;
T_4 V_62 = F_37 ( V_255 ) ;
if ( V_3 -> V_68 != V_73 ||
F_99 ( V_3 -> V_252 ) ||
F_22 ( V_3 -> V_252 , L_45 ) )
return 0 ;
V_11 = F_92 ( V_3 , V_3 -> V_252 , V_258 ,
( T_1 * ) & V_62 , 2 ) ;
F_28 ( V_257 . V_259 . V_186 ) ;
F_100 ( V_3 -> V_7 , V_260 , & V_257 , NULL ) ;
return V_11 ;
}
static int T_6 F_101 ( void )
{
if ( V_261 . V_262 != NULL ) {
V_263 = F_102 ( L_46 , V_261 . V_262 ) ;
if ( ! V_263 )
F_11 ( V_20 L_47
L_48 ) ;
} else
V_263 = NULL ;
return 0 ;
}
static void T_7 F_103 ( void )
{
if ( V_263 != NULL ) {
V_263 = NULL ;
F_104 ( L_46 , V_261 . V_262 ) ;
}
}
