static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 ) {
F_3 ( V_4 L_1 ) ;
return NULL ;
}
V_2 -> V_5 = F_4 ( V_6 . V_7 , V_3 ,
& V_2 -> V_8 ) ;
if ( ! V_2 -> V_5 ) {
F_3 ( V_4 L_2 ) ;
F_5 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = ( V_12 ) F_6 ( V_2 -> V_5 ) ;
return V_2 ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( V_2 -> V_5 )
F_8 ( V_6 . V_7 , V_2 -> V_5 ,
V_2 -> V_8 ) ;
F_5 ( V_2 ) ;
}
}
static int F_9 ( T_1 V_13 , T_1 V_14 )
{
T_2 V_15 = ( V_14 << 8 ) | V_13 ;
T_2 V_16 = 0 ;
int V_17 = 0 ;
if ( V_6 . V_18 == V_19 ) {
asm volatile (
"stc\n"
"outb %%al, %%dx\n"
"1: jc 1b\n"
: "=a" (result)
: "0" (cmd),
"d" (gsmi_dev.smi_cmd),
"b" (gsmi_dev.param_buf->address)
: "memory", "cc"
);
} else if ( V_6 . V_18 == V_20 ) {
asm volatile (
"outb %%al, %%dx\n"
"1: loop 1b\n"
: "=a" (result)
: "0" (cmd),
"d" (gsmi_dev.smi_cmd),
"b" (gsmi_dev.param_buf->address),
"c" (spincount)
: "memory", "cc"
);
} else {
asm volatile (
"outb %%al, %%dx\n\t"
: "=a" (result)
: "0" (cmd),
"d" (gsmi_dev.smi_cmd),
"b" (gsmi_dev.param_buf->address)
: "memory", "cc"
);
}
switch ( V_16 ) {
case V_21 :
break;
case V_22 :
V_17 = 1 ;
break;
case V_23 :
F_3 ( V_4 L_3 , V_15 ) ;
V_17 = - V_24 ;
break;
case V_25 :
F_3 ( V_4 L_4 , V_15 ) ;
V_17 = - V_26 ;
break;
case V_27 :
case V_28 :
if ( V_14 != V_29 )
F_3 ( V_4 L_5 ,
V_15 ) ;
V_17 = - V_30 ;
break;
case V_31 :
F_3 ( V_4 L_6 , V_15 ) ;
V_17 = - V_32 ;
break;
case V_33 :
F_3 ( V_4 L_7 , V_15 ) ;
V_17 = - V_34 ;
break;
case V_35 :
F_3 ( V_4 L_8 , V_15 ) ;
V_17 = - V_36 ;
break;
case V_37 :
F_3 ( V_4 L_9 , V_15 ) ;
V_17 = - V_38 ;
break;
case V_19 :
case V_20 :
case V_39 :
V_17 = V_16 ;
break;
default:
F_3 ( V_4 L_10 ,
V_15 , V_16 ) ;
V_17 = - V_40 ;
}
return V_17 ;
}
static T_3 F_10 ( T_4 * V_41 ,
T_5 * V_42 , V_12 * V_43 ,
unsigned long * V_44 ,
void * V_45 )
{
struct V_46 V_47 = {
. V_48 = V_6 . V_49 -> V_11 ,
. V_50 = V_6 . V_51 -> V_11 ,
. V_52 = ( V_12 ) * V_44 ,
} ;
T_3 V_53 = V_54 ;
unsigned long V_55 ;
T_6 V_56 = F_11 ( V_41 , V_10 / 2 ) ;
int V_17 ;
if ( V_56 >= V_10 / 2 )
return V_57 ;
F_12 ( & V_6 . V_58 , V_55 ) ;
memcpy ( & V_47 . V_59 , V_42 , sizeof( V_47 . V_59 ) ) ;
memset ( V_6 . V_49 -> V_5 , 0 , V_6 . V_49 -> V_9 ) ;
memcpy ( V_6 . V_49 -> V_5 , V_41 , V_56 * 2 ) ;
memset ( V_6 . V_51 -> V_5 , 0 , V_6 . V_51 -> V_9 ) ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
memcpy ( V_6 . V_60 -> V_5 , & V_47 , sizeof( V_47 ) ) ;
V_17 = F_9 ( V_61 , V_62 ) ;
if ( V_17 < 0 ) {
F_3 ( V_4 L_11 ) ;
V_53 = V_63 ;
} else if ( V_17 == 1 ) {
V_53 = V_64 ;
} else {
memcpy ( & V_47 , V_6 . V_60 -> V_5 , sizeof( V_47 ) ) ;
* V_44 = F_13 (unsigned long, *data_size,
gsmi_dev.data_buf->length) ;
* V_44 = F_13 (unsigned long, *data_size, param.data_len) ;
memcpy ( V_45 , V_6 . V_51 -> V_5 , * V_44 ) ;
* V_43 = V_65 |
V_66 |
V_67 ;
}
F_14 ( & V_6 . V_58 , V_55 ) ;
return V_53 ;
}
static T_3 F_15 ( unsigned long * V_68 ,
T_4 * V_41 ,
T_5 * V_42 )
{
struct V_69 V_47 = {
. V_48 = V_6 . V_49 -> V_11 ,
. V_56 = V_6 . V_49 -> V_9 ,
} ;
T_3 V_53 = V_54 ;
int V_17 ;
unsigned long V_55 ;
if ( * V_68 != V_10 )
return V_57 ;
if ( F_11 ( V_41 , V_10 / 2 ) == V_10 / 2 )
return V_70 ;
F_12 ( & V_6 . V_58 , V_55 ) ;
memcpy ( & V_47 . V_59 , V_42 , sizeof( V_47 . V_59 ) ) ;
memcpy ( V_6 . V_49 -> V_5 , V_41 , * V_68 ) ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
memcpy ( V_6 . V_60 -> V_5 , & V_47 , sizeof( V_47 ) ) ;
V_17 = F_9 ( V_61 , V_71 ) ;
if ( V_17 < 0 ) {
F_3 ( V_4 L_12 ) ;
V_53 = V_63 ;
} else if ( V_17 == 1 ) {
V_53 = V_64 ;
} else {
memcpy ( & V_47 , V_6 . V_60 -> V_5 , sizeof( V_47 ) ) ;
memcpy ( V_41 , V_6 . V_49 -> V_5 , V_10 ) ;
* V_68 = F_11 ( V_41 , V_10 / 2 ) * 2 ;
memcpy ( V_42 , & V_47 . V_59 , sizeof( V_47 . V_59 ) ) ;
V_53 = V_54 ;
}
F_14 ( & V_6 . V_58 , V_55 ) ;
return V_53 ;
}
static T_3 F_16 ( T_4 * V_41 ,
T_5 * V_42 ,
V_12 V_43 ,
unsigned long V_44 ,
void * V_45 )
{
struct V_46 V_47 = {
. V_48 = V_6 . V_49 -> V_11 ,
. V_50 = V_6 . V_51 -> V_11 ,
. V_52 = ( V_12 ) V_44 ,
. V_72 = V_65 |
V_66 |
V_67 ,
} ;
T_6 V_56 = F_11 ( V_41 , V_10 / 2 ) ;
T_3 V_53 = V_54 ;
int V_17 ;
unsigned long V_55 ;
if ( V_56 >= V_10 / 2 )
return V_57 ;
F_12 ( & V_6 . V_58 , V_55 ) ;
memcpy ( & V_47 . V_59 , V_42 , sizeof( V_47 . V_59 ) ) ;
memset ( V_6 . V_49 -> V_5 , 0 , V_6 . V_49 -> V_9 ) ;
memcpy ( V_6 . V_49 -> V_5 , V_41 , V_56 * 2 ) ;
memset ( V_6 . V_51 -> V_5 , 0 , V_6 . V_51 -> V_9 ) ;
memcpy ( V_6 . V_51 -> V_5 , V_45 , V_44 ) ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
memcpy ( V_6 . V_60 -> V_5 , & V_47 , sizeof( V_47 ) ) ;
V_17 = F_9 ( V_61 , V_73 ) ;
if ( V_17 < 0 ) {
F_3 ( V_4 L_13 ) ;
V_53 = V_70 ;
}
F_14 ( & V_6 . V_58 , V_55 ) ;
return V_53 ;
}
static T_7 F_17 ( struct V_74 * V_75 , struct V_76 * V_77 ,
struct V_78 * V_79 ,
char * V_80 , T_8 V_81 , T_6 V_82 )
{
struct V_83 V_47 = {
. V_50 = V_6 . V_51 -> V_11 ,
} ;
int V_17 = 0 ;
unsigned long V_55 ;
if ( V_82 < sizeof( V_12 ) )
return - V_24 ;
V_47 . type = * ( V_12 * ) V_80 ;
V_82 -= sizeof( V_12 ) ;
V_80 += sizeof( V_12 ) ;
if ( V_82 > V_6 . V_51 -> V_9 )
return - V_24 ;
V_47 . V_52 = V_82 - sizeof( V_12 ) ;
F_12 ( & V_6 . V_58 , V_55 ) ;
memset ( V_6 . V_51 -> V_5 , 0 , V_6 . V_51 -> V_9 ) ;
memcpy ( V_6 . V_51 -> V_5 , V_80 , V_47 . V_52 ) ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
memcpy ( V_6 . V_60 -> V_5 , & V_47 , sizeof( V_47 ) ) ;
V_17 = F_9 ( V_61 , V_84 ) ;
if ( V_17 < 0 )
F_3 ( V_4 L_14 ) ;
F_14 ( & V_6 . V_58 , V_55 ) ;
return V_17 ;
}
static T_7 F_18 ( struct V_76 * V_77 ,
struct V_85 * V_43 ,
const char * V_80 , T_6 V_82 )
{
int V_17 ;
unsigned long V_55 ;
unsigned long V_86 ;
struct {
V_12 V_87 ;
V_12 V_88 ;
} V_47 ;
V_17 = F_19 ( V_80 , 0 , & V_86 ) ;
if ( V_17 )
return V_17 ;
if ( V_86 > 100 )
return - V_24 ;
V_47 . V_87 = V_86 ;
V_47 . V_88 = 0 ;
F_12 ( & V_6 . V_58 , V_55 ) ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
memcpy ( V_6 . V_60 -> V_5 , & V_47 , sizeof( V_47 ) ) ;
V_17 = F_9 ( V_61 , V_89 ) ;
F_14 ( & V_6 . V_58 , V_55 ) ;
if ( V_17 )
return V_17 ;
return V_82 ;
}
static T_7 F_20 ( struct V_76 * V_77 ,
struct V_85 * V_43 ,
const char * V_80 , T_6 V_82 )
{
int V_17 ;
unsigned long V_55 ;
F_12 ( & V_6 . V_58 , V_55 ) ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
V_17 = F_9 ( V_61 , V_90 ) ;
F_14 ( & V_6 . V_58 , V_55 ) ;
if ( V_17 )
return V_17 ;
return V_82 ;
}
static int F_21 ( int V_91 )
{
struct V_92 V_93 = {
. type = V_94 ,
. V_95 = V_91 ,
} ;
struct V_83 V_47 = {
. V_52 = sizeof( V_93 ) ,
. type = 1 ,
} ;
static int V_96 ;
int V_17 = 0 ;
unsigned long V_55 ;
if ( V_96 & ( 1 << V_91 ) )
return 0 ;
F_12 ( & V_6 . V_58 , V_55 ) ;
V_96 |= ( 1 << V_91 ) ;
memset ( V_6 . V_51 -> V_5 , 0 , V_6 . V_51 -> V_9 ) ;
memcpy ( V_6 . V_51 -> V_5 , & V_93 , sizeof( V_93 ) ) ;
V_47 . V_50 = V_6 . V_51 -> V_11 ;
memset ( V_6 . V_60 -> V_5 , 0 , V_6 . V_60 -> V_9 ) ;
memcpy ( V_6 . V_60 -> V_5 , & V_47 , sizeof( V_47 ) ) ;
V_17 = F_9 ( V_61 , V_84 ) ;
F_14 ( & V_6 . V_58 , V_55 ) ;
if ( V_17 < 0 )
F_3 ( V_4 L_15 ) ;
else
F_3 ( V_97 L_16 ,
V_91 ) ;
return V_17 ;
}
static int F_22 ( struct V_98 * V_99 ,
unsigned long V_91 , void * V_100 )
{
F_21 ( V_101 ) ;
return V_102 ;
}
static int F_23 ( struct V_98 * V_99 ,
unsigned long V_91 , void * V_100 )
{
if ( V_91 == V_103 )
F_21 ( V_104 ) ;
return V_102 ;
}
static int F_24 ( struct V_98 * V_99 ,
unsigned long V_91 , void * V_100 )
{
F_21 ( V_105 ) ;
return V_102 ;
}
static T_9 T_10 F_25 ( T_9 V_86 , unsigned V_106 )
{
T_9 V_107 = V_86 ;
T_9 V_108 = V_107 ;
V_108 <<= 18 ;
V_107 -= V_108 ;
V_108 <<= 33 ;
V_107 -= V_108 ;
V_108 <<= 3 ;
V_107 += V_108 ;
V_108 <<= 3 ;
V_107 -= V_108 ;
V_108 <<= 4 ;
V_107 += V_108 ;
V_108 <<= 2 ;
V_107 += V_108 ;
return V_107 >> ( 64 - V_106 ) ;
}
static V_12 T_10 F_26 ( char V_109 [ 8 ] )
{
T_9 V_110 ;
memcpy ( & V_110 , V_109 , 8 ) ;
return F_25 ( V_110 , 32 ) ;
}
static T_10 int F_27 ( void )
{
V_12 V_107 ;
if ( ! F_28 ( V_111 ) )
return - V_112 ;
if ( ! strncmp ( V_113 . V_114 . V_115 , L_17 , 4 ) ) {
F_3 ( V_116 L_18 ) ;
return - V_112 ;
}
V_107 = F_26 ( V_113 . V_114 . V_115 ) ;
if ( V_107 == V_117 ) {
const char * V_118 = F_29 ( V_119 ) ;
if ( strncmp ( V_118 , L_19 , 3 ) == 0 ) {
F_30 ( L_20 ,
V_118 ) ;
return - V_112 ;
}
}
if ( V_113 . V_120 == 0 ) {
F_30 ( L_21 ) ;
return - V_112 ;
}
return 0 ;
}
static T_10 int F_31 ( void )
{
unsigned long V_55 ;
int V_53 ;
V_53 = F_27 () ;
if ( V_53 )
return V_53 ;
V_6 . V_121 = V_113 . V_120 ;
V_6 . V_122 = F_32 ( & V_123 ) ;
if ( F_33 ( V_6 . V_122 ) ) {
F_3 ( V_4 L_22 ) ;
return F_34 ( V_6 . V_122 ) ;
}
F_35 ( & V_6 . V_58 ) ;
V_53 = - V_26 ;
V_6 . V_7 = F_36 ( L_23 , & V_6 . V_122 -> V_124 ,
V_10 , V_125 , 0 ) ;
if ( ! V_6 . V_7 )
goto V_126;
V_6 . V_49 = F_1 () ;
if ( ! V_6 . V_49 ) {
F_3 ( V_4 L_2 ) ;
goto V_126;
}
V_6 . V_51 = F_1 () ;
if ( ! V_6 . V_51 ) {
F_3 ( V_4 L_24 ) ;
goto V_126;
}
V_6 . V_60 = F_1 () ;
if ( ! V_6 . V_60 ) {
F_3 ( V_4 L_25 ) ;
goto V_126;
}
F_12 ( & V_6 . V_58 , V_55 ) ;
V_6 . V_18 = V_20 ;
V_6 . V_18 =
F_9 ( V_61 , V_29 ) ;
if ( V_6 . V_18 == - V_30 )
V_6 . V_18 = V_39 ;
F_14 ( & V_6 . V_58 , V_55 ) ;
if ( V_6 . V_18 == - V_40 ) {
F_3 ( V_116 L_26 V_127
L_27 ) ;
V_53 = - V_112 ;
goto V_126;
}
V_53 = - V_26 ;
V_128 = F_37 ( L_23 , V_129 ) ;
if ( ! V_128 ) {
F_3 ( V_116 L_28 ) ;
goto V_126;
}
V_53 = F_38 ( V_128 , & V_130 ) ;
if ( V_53 ) {
F_3 ( V_116 L_29 ) ;
goto V_126;
}
V_53 = F_39 ( V_128 , V_131 ) ;
if ( V_53 ) {
F_3 ( V_116 L_30 ) ;
goto V_132;
}
V_53 = F_40 ( & V_133 , & V_134 , V_128 ) ;
if ( V_53 ) {
F_3 ( V_116 L_31 ) ;
goto V_135;
}
F_41 ( & V_136 ) ;
F_42 ( & V_137 ) ;
F_43 ( & V_138 ,
& V_139 ) ;
F_3 ( V_116 L_26 V_127 L_32 ) ;
return 0 ;
V_135:
F_44 ( V_128 , V_131 ) ;
V_132:
F_45 ( V_128 , & V_130 ) ;
V_126:
F_46 ( V_128 ) ;
F_7 ( V_6 . V_60 ) ;
F_7 ( V_6 . V_51 ) ;
F_7 ( V_6 . V_49 ) ;
if ( V_6 . V_7 )
F_47 ( V_6 . V_7 ) ;
F_48 ( V_6 . V_122 ) ;
F_30 ( L_33 , V_53 ) ;
return V_53 ;
}
static void T_11 F_49 ( void )
{
F_50 ( & V_136 ) ;
F_51 ( & V_137 ) ;
F_52 ( & V_138 ,
& V_139 ) ;
F_53 ( & V_133 ) ;
F_44 ( V_128 , V_131 ) ;
F_45 ( V_128 , & V_130 ) ;
F_46 ( V_128 ) ;
F_7 ( V_6 . V_60 ) ;
F_7 ( V_6 . V_51 ) ;
F_7 ( V_6 . V_49 ) ;
F_47 ( V_6 . V_7 ) ;
F_48 ( V_6 . V_122 ) ;
}
