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
static T_3
F_10 ( T_4 * V_41 , unsigned long V_42 )
{
unsigned long V_9 = 0 ;
while ( * V_41 ++ != 0 && V_9 < V_42 )
V_9 ++ ;
return V_9 ;
}
static T_5 F_11 ( T_4 * V_43 ,
T_6 * V_44 , V_12 * V_45 ,
unsigned long * V_46 ,
void * V_41 )
{
struct V_47 V_48 = {
. V_49 = V_6 . V_50 -> V_11 ,
. V_51 = V_6 . V_52 -> V_11 ,
. V_53 = ( V_12 ) * V_46 ,
} ;
T_5 V_54 = V_55 ;
unsigned long V_56 ;
T_3 V_57 = F_10 ( V_43 , V_10 / 2 ) ;
int V_17 ;
if ( V_57 >= V_10 / 2 )
return V_58 ;
F_12 ( & V_6 . V_59 , V_56 ) ;
memcpy ( & V_48 . V_60 , V_44 , sizeof( V_48 . V_60 ) ) ;
memset ( V_6 . V_50 -> V_5 , 0 , V_6 . V_50 -> V_9 ) ;
memcpy ( V_6 . V_50 -> V_5 , V_43 , V_57 * 2 ) ;
memset ( V_6 . V_52 -> V_5 , 0 , V_6 . V_52 -> V_9 ) ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
memcpy ( V_6 . V_61 -> V_5 , & V_48 , sizeof( V_48 ) ) ;
V_17 = F_9 ( V_62 , V_63 ) ;
if ( V_17 < 0 ) {
F_3 ( V_4 L_11 ) ;
V_54 = V_64 ;
} else if ( V_17 == 1 ) {
V_54 = V_65 ;
} else {
memcpy ( & V_48 , V_6 . V_61 -> V_5 , sizeof( V_48 ) ) ;
* V_46 = F_13 ( * V_46 , V_6 . V_52 -> V_9 ) ;
* V_46 = F_14 (unsigned long, *data_size, param.data_len) ;
memcpy ( V_41 , V_6 . V_52 -> V_5 , * V_46 ) ;
* V_45 = V_66 |
V_67 |
V_68 ;
}
F_15 ( & V_6 . V_59 , V_56 ) ;
return V_54 ;
}
static T_5 F_16 ( unsigned long * V_69 ,
T_4 * V_43 ,
T_6 * V_44 )
{
struct V_70 V_48 = {
. V_49 = V_6 . V_50 -> V_11 ,
. V_57 = V_6 . V_50 -> V_9 ,
} ;
T_5 V_54 = V_55 ;
int V_17 ;
unsigned long V_56 ;
if ( * V_69 != V_10 )
return V_58 ;
if ( F_10 ( V_43 , V_10 / 2 ) == V_10 / 2 )
return V_71 ;
F_12 ( & V_6 . V_59 , V_56 ) ;
memcpy ( & V_48 . V_60 , V_44 , sizeof( V_48 . V_60 ) ) ;
memcpy ( V_6 . V_50 -> V_5 , V_43 , * V_69 ) ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
memcpy ( V_6 . V_61 -> V_5 , & V_48 , sizeof( V_48 ) ) ;
V_17 = F_9 ( V_62 , V_72 ) ;
if ( V_17 < 0 ) {
F_3 ( V_4 L_12 ) ;
V_54 = V_64 ;
} else if ( V_17 == 1 ) {
V_54 = V_65 ;
} else {
memcpy ( & V_48 , V_6 . V_61 -> V_5 , sizeof( V_48 ) ) ;
memcpy ( V_43 , V_6 . V_50 -> V_5 , V_10 ) ;
* V_69 = F_10 ( V_43 , V_10 / 2 ) * 2 ;
memcpy ( V_44 , & V_48 . V_60 , sizeof( V_48 . V_60 ) ) ;
V_54 = V_55 ;
}
F_15 ( & V_6 . V_59 , V_56 ) ;
return V_54 ;
}
static T_5 F_17 ( T_4 * V_43 ,
T_6 * V_44 ,
unsigned long V_45 ,
unsigned long V_46 ,
void * V_41 )
{
struct V_47 V_48 = {
. V_49 = V_6 . V_50 -> V_11 ,
. V_51 = V_6 . V_52 -> V_11 ,
. V_53 = ( V_12 ) V_46 ,
. V_73 = V_66 |
V_67 |
V_68 ,
} ;
T_3 V_57 = F_10 ( V_43 , V_10 / 2 ) ;
T_5 V_54 = V_55 ;
int V_17 ;
unsigned long V_56 ;
if ( V_57 >= V_10 / 2 )
return V_58 ;
F_12 ( & V_6 . V_59 , V_56 ) ;
memcpy ( & V_48 . V_60 , V_44 , sizeof( V_48 . V_60 ) ) ;
memset ( V_6 . V_50 -> V_5 , 0 , V_6 . V_50 -> V_9 ) ;
memcpy ( V_6 . V_50 -> V_5 , V_43 , V_57 * 2 ) ;
memset ( V_6 . V_52 -> V_5 , 0 , V_6 . V_52 -> V_9 ) ;
memcpy ( V_6 . V_52 -> V_5 , V_41 , V_46 ) ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
memcpy ( V_6 . V_61 -> V_5 , & V_48 , sizeof( V_48 ) ) ;
V_17 = F_9 ( V_62 , V_74 ) ;
if ( V_17 < 0 ) {
F_3 ( V_4 L_13 ) ;
V_54 = V_71 ;
}
F_15 ( & V_6 . V_59 , V_56 ) ;
return V_54 ;
}
static T_7 F_18 ( struct V_75 * V_76 , struct V_77 * V_78 ,
struct V_79 * V_80 ,
char * V_81 , T_8 V_82 , T_3 V_83 )
{
struct V_84 V_48 = {
. V_51 = V_6 . V_52 -> V_11 ,
} ;
int V_17 = 0 ;
unsigned long V_56 ;
if ( V_83 < sizeof( V_12 ) )
return - V_24 ;
V_48 . type = * ( V_12 * ) V_81 ;
V_83 -= sizeof( V_12 ) ;
V_81 += sizeof( V_12 ) ;
if ( V_83 > V_6 . V_52 -> V_9 )
return - V_24 ;
V_48 . V_53 = V_83 - sizeof( V_12 ) ;
F_12 ( & V_6 . V_59 , V_56 ) ;
memset ( V_6 . V_52 -> V_5 , 0 , V_6 . V_52 -> V_9 ) ;
memcpy ( V_6 . V_52 -> V_5 , V_81 , V_48 . V_53 ) ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
memcpy ( V_6 . V_61 -> V_5 , & V_48 , sizeof( V_48 ) ) ;
V_17 = F_9 ( V_62 , V_85 ) ;
if ( V_17 < 0 )
F_3 ( V_4 L_14 ) ;
F_15 ( & V_6 . V_59 , V_56 ) ;
return V_17 ;
}
static T_7 F_19 ( struct V_77 * V_78 ,
struct V_86 * V_45 ,
const char * V_81 , T_3 V_83 )
{
int V_17 ;
unsigned long V_56 ;
unsigned long V_87 ;
struct {
V_12 V_88 ;
V_12 V_89 ;
} V_48 ;
V_17 = F_20 ( V_81 , 0 , & V_87 ) ;
if ( V_17 )
return V_17 ;
if ( V_87 > 100 )
return - V_24 ;
V_48 . V_88 = V_87 ;
V_48 . V_89 = 0 ;
F_12 ( & V_6 . V_59 , V_56 ) ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
memcpy ( V_6 . V_61 -> V_5 , & V_48 , sizeof( V_48 ) ) ;
V_17 = F_9 ( V_62 , V_90 ) ;
F_15 ( & V_6 . V_59 , V_56 ) ;
if ( V_17 )
return V_17 ;
return V_83 ;
}
static T_7 F_21 ( struct V_77 * V_78 ,
struct V_86 * V_45 ,
const char * V_81 , T_3 V_83 )
{
int V_17 ;
unsigned long V_56 ;
F_12 ( & V_6 . V_59 , V_56 ) ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
V_17 = F_9 ( V_62 , V_91 ) ;
F_15 ( & V_6 . V_59 , V_56 ) ;
if ( V_17 )
return V_17 ;
return V_83 ;
}
static int F_22 ( int V_92 )
{
struct V_93 V_94 = {
. type = V_95 ,
. V_96 = V_92 ,
} ;
struct V_84 V_48 = {
. V_53 = sizeof( V_94 ) ,
. type = 1 ,
} ;
static int V_97 ;
int V_17 = 0 ;
unsigned long V_56 ;
if ( V_97 & ( 1 << V_92 ) )
return 0 ;
F_12 ( & V_6 . V_59 , V_56 ) ;
V_97 |= ( 1 << V_92 ) ;
memset ( V_6 . V_52 -> V_5 , 0 , V_6 . V_52 -> V_9 ) ;
memcpy ( V_6 . V_52 -> V_5 , & V_94 , sizeof( V_94 ) ) ;
V_48 . V_51 = V_6 . V_52 -> V_11 ;
memset ( V_6 . V_61 -> V_5 , 0 , V_6 . V_61 -> V_9 ) ;
memcpy ( V_6 . V_61 -> V_5 , & V_48 , sizeof( V_48 ) ) ;
V_17 = F_9 ( V_62 , V_85 ) ;
F_15 ( & V_6 . V_59 , V_56 ) ;
if ( V_17 < 0 )
F_3 ( V_4 L_15 ) ;
else
F_3 ( V_98 L_16 ,
V_92 ) ;
return V_17 ;
}
static int F_23 ( struct V_99 * V_100 ,
unsigned long V_92 , void * V_101 )
{
F_22 ( V_102 ) ;
return V_103 ;
}
static int F_24 ( struct V_99 * V_100 ,
unsigned long V_92 , void * V_101 )
{
if ( V_92 == V_104 )
F_22 ( V_105 ) ;
return V_103 ;
}
static int F_25 ( struct V_99 * V_100 ,
unsigned long V_92 , void * V_101 )
{
F_22 ( V_106 ) ;
return V_103 ;
}
static T_9 T_10 F_26 ( T_9 V_87 , unsigned V_107 )
{
T_9 V_108 = V_87 ;
T_9 V_109 = V_108 ;
V_109 <<= 18 ;
V_108 -= V_109 ;
V_109 <<= 33 ;
V_108 -= V_109 ;
V_109 <<= 3 ;
V_108 += V_109 ;
V_109 <<= 3 ;
V_108 -= V_109 ;
V_109 <<= 4 ;
V_108 += V_109 ;
V_109 <<= 2 ;
V_108 += V_109 ;
return V_108 >> ( 64 - V_107 ) ;
}
static V_12 T_10 F_27 ( char V_110 [ 8 ] )
{
T_9 V_111 ;
memcpy ( & V_111 , V_110 , 8 ) ;
return F_26 ( V_111 , 32 ) ;
}
static T_10 int F_28 ( void )
{
V_12 V_108 ;
if ( ! F_29 ( V_112 ) )
return - V_113 ;
if ( ! strncmp ( V_114 . V_115 . V_116 , L_17 , 4 ) ) {
F_3 ( V_117 L_18 ) ;
return - V_113 ;
}
V_108 = F_27 ( V_114 . V_115 . V_116 ) ;
if ( V_108 == V_118 ) {
const char * V_119 = F_30 ( V_120 ) ;
if ( strncmp ( V_119 , L_19 , 3 ) == 0 ) {
F_31 ( L_20 ,
V_119 ) ;
return - V_113 ;
}
}
if ( V_114 . V_121 == 0 ) {
F_31 ( L_21 ) ;
return - V_113 ;
}
return 0 ;
}
static T_10 int F_32 ( void )
{
unsigned long V_56 ;
int V_54 ;
V_54 = F_28 () ;
if ( V_54 )
return V_54 ;
V_6 . V_122 = V_114 . V_121 ;
V_6 . V_123 = F_33 ( L_22 , - 1 , NULL , 0 ) ;
if ( F_34 ( V_6 . V_123 ) ) {
F_3 ( V_4 L_23 ) ;
return F_35 ( V_6 . V_123 ) ;
}
F_36 ( & V_6 . V_59 ) ;
V_6 . V_123 -> V_124 . V_125 = F_37 ( 32 ) ;
V_6 . V_123 -> V_124 . V_126 =
& V_6 . V_123 -> V_124 . V_125 ;
V_54 = - V_26 ;
V_6 . V_7 = F_38 ( L_22 , & V_6 . V_123 -> V_124 ,
V_10 , V_127 , 0 ) ;
if ( ! V_6 . V_7 )
goto V_128;
V_6 . V_50 = F_1 () ;
if ( ! V_6 . V_50 ) {
F_3 ( V_4 L_2 ) ;
goto V_128;
}
V_6 . V_52 = F_1 () ;
if ( ! V_6 . V_52 ) {
F_3 ( V_4 L_24 ) ;
goto V_128;
}
V_6 . V_61 = F_1 () ;
if ( ! V_6 . V_61 ) {
F_3 ( V_4 L_25 ) ;
goto V_128;
}
F_12 ( & V_6 . V_59 , V_56 ) ;
V_6 . V_18 = V_20 ;
V_6 . V_18 =
F_9 ( V_62 , V_29 ) ;
if ( V_6 . V_18 == - V_30 )
V_6 . V_18 = V_39 ;
F_15 ( & V_6 . V_59 , V_56 ) ;
if ( V_6 . V_18 == - V_40 ) {
F_3 ( V_117 L_26 V_129
L_27 ) ;
V_54 = - V_113 ;
goto V_128;
}
F_3 ( V_117 L_26 V_129 L_28 ) ;
V_54 = - V_26 ;
V_130 = F_39 ( L_22 , V_131 ) ;
if ( ! V_130 ) {
F_3 ( V_117 L_29 ) ;
goto V_128;
}
V_54 = F_40 ( V_130 , & V_132 ) ;
if ( V_54 ) {
F_3 ( V_117 L_30 ) ;
goto V_128;
}
V_54 = F_41 ( V_130 , V_133 ) ;
if ( V_54 ) {
F_3 ( V_117 L_31 ) ;
goto V_128;
}
if ( F_42 ( & V_134 , & V_135 , V_130 ) ) {
F_3 ( V_117 L_32 ) ;
goto V_128;
}
F_43 ( & V_136 ) ;
F_44 ( & V_137 ) ;
F_45 ( & V_138 ,
& V_139 ) ;
return 0 ;
V_128:
F_46 ( V_130 ) ;
F_7 ( V_6 . V_61 ) ;
F_7 ( V_6 . V_52 ) ;
F_7 ( V_6 . V_50 ) ;
if ( V_6 . V_7 )
F_47 ( V_6 . V_7 ) ;
F_48 ( V_6 . V_123 ) ;
F_31 ( L_33 , V_54 ) ;
return V_54 ;
}
static void T_11 F_49 ( void )
{
F_50 ( & V_136 ) ;
F_51 ( & V_137 ) ;
F_52 ( & V_138 ,
& V_139 ) ;
F_53 ( & V_134 ) ;
F_46 ( V_130 ) ;
F_7 ( V_6 . V_61 ) ;
F_7 ( V_6 . V_52 ) ;
F_7 ( V_6 . V_50 ) ;
F_47 ( V_6 . V_7 ) ;
F_48 ( V_6 . V_123 ) ;
}
