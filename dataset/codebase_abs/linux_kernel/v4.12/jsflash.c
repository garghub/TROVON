static unsigned int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (addr), "i" (ASI_M_BYPASS));
return V_2 ;
}
static void F_2 ( unsigned long V_1 , T_1 V_3 )
{
__asm__ __volatile__("sta %0, [%1] %2\n\t" : :
"r" (data), "r" (addr), "i" (ASI_M_BYPASS) :
"memory");
}
static void F_3 ( unsigned long V_4 ) {
unsigned int V_5 , V_6 ;
for (; ; ) {
V_5 = F_1 ( V_4 ) ;
V_6 = F_1 ( V_4 ) ;
if ( ( V_5 & 0x40404040 ) == ( V_6 & 0x40404040 ) ) return;
}
}
static void F_4 ( unsigned long V_7 , T_2 V_3 ) {
F_2 ( V_7 , 0xAAAAAAAA ) ;
F_2 ( V_7 , 0x55555555 ) ;
F_2 ( V_7 , 0xA0A0A0A0 ) ;
F_2 ( V_7 , V_3 ) ;
F_3 ( V_7 ) ;
}
static void F_5 ( char * V_8 , unsigned long V_4 , T_3 V_9 ) {
union T_4 {
char V_10 [ 4 ] ;
unsigned int V_11 ;
} V_12 ;
while ( V_9 >= 4 ) {
V_9 -= 4 ;
V_12 . V_11 = F_1 ( V_4 ) ;
memcpy ( V_8 , V_12 . V_10 , 4 ) ;
V_4 += 4 ;
V_8 += 4 ;
}
}
static struct V_13 * F_6 ( void )
{
struct V_14 * V_15 ;
struct V_13 * V_16 ;
int V_17 = V_18 ;
do {
V_15 = V_19 [ V_18 ] -> V_20 ;
if ( ++ V_18 == V_21 )
V_18 = 0 ;
if ( V_15 ) {
V_16 = F_7 ( V_15 ) ;
if ( V_16 )
return V_16 ;
}
} while ( V_18 != V_17 );
return NULL ;
}
static void F_8 ( void )
{
struct V_13 * V_22 ;
V_22 = F_6 () ;
while ( V_22 ) {
struct V_23 * V_24 = V_22 -> V_25 -> V_26 ;
unsigned long V_27 = F_9 ( V_22 ) << 9 ;
T_3 V_28 = F_10 ( V_22 ) ;
int V_29 = - V_30 ;
if ( ( V_27 + V_28 ) > V_24 -> V_31 )
goto V_32;
if ( F_11 ( V_22 ) != V_33 ) {
F_12 ( V_34 L_1 ) ;
goto V_32;
}
if ( ( V_24 -> V_35 & 0xff000000 ) != 0x20000000 ) {
F_12 ( V_34 L_2 , ( int ) V_24 -> V_35 ) ;
goto V_32;
}
F_5 ( F_13 ( V_22 -> V_36 ) , V_24 -> V_35 + V_27 , V_28 ) ;
V_29 = 0 ;
V_32:
if ( ! F_14 ( V_22 , V_29 ) )
V_22 = F_6 () ;
}
}
static void F_15 ( struct V_14 * V_15 )
{
F_8 () ;
}
static T_5 F_16 ( struct V_37 * V_37 , T_5 V_27 , int V_38 )
{
T_5 V_39 ;
F_17 ( & V_40 ) ;
switch ( V_38 ) {
case 0 :
V_37 -> V_41 = V_27 ;
V_39 = V_37 -> V_41 ;
break;
case 1 :
V_37 -> V_41 += V_27 ;
V_39 = V_37 -> V_41 ;
break;
default:
V_39 = - V_42 ;
}
F_18 ( & V_40 ) ;
return V_39 ;
}
static T_6 F_19 ( struct V_37 * V_37 , char T_7 * V_8 ,
T_3 V_9 , T_5 * V_43 )
{
unsigned long V_4 = * V_43 ;
char T_7 * V_44 = V_8 ;
union T_4 {
char V_10 [ 4 ] ;
unsigned int V_11 ;
} V_12 ;
if ( V_4 < V_45 || V_4 >= V_46 ) {
return 0 ;
}
if ( ( V_4 + V_9 ) < V_4
|| ( V_4 + V_9 ) >= V_46 ) {
V_9 = V_46 - V_4 ;
}
if ( V_4 < V_45 && V_9 != 0 ) {
#if 0
size_t x = JSF_BASE_ALL - p;
if (x > togo) x = togo;
clear_user(tmp, x);
tmp += x;
p += x;
togo -= x;
#else
return 0 ;
#endif
}
while ( V_9 >= 4 ) {
V_9 -= 4 ;
V_12 . V_11 = F_1 ( V_4 ) ;
if ( F_20 ( V_44 , V_12 . V_10 , 4 ) )
return - V_47 ;
V_44 += 4 ;
V_4 += 4 ;
}
* V_43 = V_4 ;
return V_44 - V_8 ;
}
static T_6 F_21 ( struct V_37 * V_37 , const char T_7 * V_8 ,
T_3 V_48 , T_5 * V_43 )
{
return - V_49 ;
}
static int F_22 ( unsigned long V_50 )
{
unsigned long V_4 ;
V_4 = 0x20400000 ;
F_2 ( V_4 , 0xAAAAAAAA ) ;
F_2 ( V_4 , 0x55555555 ) ;
F_2 ( V_4 , 0x80808080 ) ;
F_2 ( V_4 , 0xAAAAAAAA ) ;
F_2 ( V_4 , 0x55555555 ) ;
F_2 ( V_4 , 0x10101010 ) ;
#if 0
{
int i;
__u32 x;
for (i = 0; i < 1000000; i++) {
x = jsf_inl(p);
if ((x & 0x80808080) == 0x80808080) break;
}
if ((x & 0x80808080) != 0x80808080) {
printk("jsf0: erase timeout with 0x%08x\n", x);
} else {
printk("jsf0: erase done with 0x%08x\n", x);
}
}
#else
F_3 ( V_4 ) ;
#endif
return 0 ;
}
static int F_23 ( void T_7 * V_50 )
{
struct V_51 V_52 ;
char T_7 * V_53 ;
unsigned long V_4 ;
unsigned int V_9 ;
union {
unsigned int V_11 ;
char V_10 [ 4 ] ;
} V_12 ;
if ( F_24 ( & V_52 , V_50 , V_54 ) )
return - V_47 ;
V_4 = V_52 . V_55 ;
V_9 = V_52 . V_56 ;
if ( ( V_9 & 3 ) || ( V_4 & 3 ) ) return - V_42 ;
V_53 = ( char T_7 * ) ( unsigned long ) V_52 . V_3 ;
while ( V_9 != 0 ) {
V_9 -= 4 ;
if ( F_24 ( & V_12 . V_10 [ 0 ] , V_53 , 4 ) )
return - V_47 ;
F_4 ( V_4 , V_12 . V_11 ) ;
V_4 += 4 ;
V_53 += 4 ;
}
return 0 ;
}
static long F_25 ( struct V_37 * V_57 , unsigned int V_58 , unsigned long V_50 )
{
F_17 ( & V_40 ) ;
int error = - V_59 ;
void T_7 * V_60 = ( void T_7 * ) V_50 ;
if ( ! F_26 ( V_61 ) ) {
F_18 ( & V_40 ) ;
return - V_62 ;
}
switch ( V_58 ) {
case V_63 :
if ( F_20 ( V_60 , & V_64 . V_65 , V_66 ) ) {
F_18 ( & V_40 ) ;
return - V_47 ;
}
break;
case V_67 :
error = F_22 ( V_50 ) ;
break;
case V_68 :
error = F_23 ( V_60 ) ;
break;
}
F_18 ( & V_40 ) ;
return error ;
}
static int F_27 ( struct V_37 * V_37 , struct V_69 * V_70 )
{
return - V_71 ;
}
static int F_28 ( struct V_72 * V_72 , struct V_37 * V_73 )
{
F_17 ( & V_40 ) ;
if ( V_64 . V_74 == 0 ) {
F_18 ( & V_40 ) ;
return - V_71 ;
}
if ( F_29 ( 0 , ( void * ) & V_64 . V_75 ) != 0 ) {
F_18 ( & V_40 ) ;
return - V_76 ;
}
F_18 ( & V_40 ) ;
return 0 ;
}
static int F_30 ( struct V_72 * V_72 , struct V_37 * V_37 )
{
V_64 . V_75 = 0 ;
return 0 ;
}
static int F_31 ( void )
{
int V_77 ;
struct V_78 * V_79 ;
T_8 V_80 ;
char V_81 [ 128 ] ;
struct V_82 V_83 ;
V_80 = F_32 ( V_84 ) ;
V_80 = F_33 ( V_80 , L_3 ) ;
if ( V_80 != 0 && ( V_85 ) V_80 != - 1 ) {
if ( F_34 ( V_80 , L_4 ,
( char * ) & V_83 , sizeof( V_83 ) ) == - 1 ) {
F_12 ( L_5 ) ;
return - V_71 ;
}
if ( V_83 . V_86 != 0 ) {
F_12 ( L_6 ,
V_83 . V_86 , V_83 . V_87 ) ;
return - V_71 ;
}
#if 0
if ((reg0.phys_addr >> 24) != 0x20) {
printk("jsflash: suspicious address: 0x%x:%x\n",
reg0.which_io, reg0.phys_addr);
return -ENXIO;
}
#endif
if ( ( int ) V_83 . V_88 <= 0 ) {
F_12 ( L_7 , ( int ) V_83 . V_88 ) ;
return - V_71 ;
}
} else {
F_12 ( L_8 ) ;
F_34 ( V_84 , L_9 , V_81 , 128 ) ;
if ( strcmp ( V_81 , L_10 ) != 0 &&
strcmp ( V_81 , L_11 ) != 0 ) {
return - V_71 ;
}
V_83 . V_86 = 0 ;
V_83 . V_87 = 0x20400000 ;
V_83 . V_88 = 0x00800000 ;
}
if ( V_89 != V_90 ) {
return - V_71 ;
}
if ( V_64 . V_74 == 0 ) {
V_79 = & V_64 ;
V_79 -> V_74 = V_83 . V_87 ;
V_79 -> V_56 = V_83 . V_88 ;
V_79 -> V_65 . V_55 = V_45 ;
V_79 -> V_65 . V_56 = 0x01000000 ;
strcpy ( V_79 -> V_65 . V_91 , L_12 ) ;
V_79 -> V_92 [ 0 ] . V_35 = V_79 -> V_74 ;
V_79 -> V_92 [ 0 ] . V_31 = V_79 -> V_56 ;
V_79 -> V_92 [ 1 ] . V_35 = V_79 -> V_74 + 1024 ;
V_79 -> V_92 [ 1 ] . V_31 = V_79 -> V_56 - 1024 ;
V_79 -> V_92 [ 2 ] . V_35 = V_45 ;
V_79 -> V_92 [ 2 ] . V_31 = 0x01000000 ;
F_12 ( L_13 , V_79 -> V_74 ,
( int ) ( V_79 -> V_56 / ( 1024 * 1024 ) ) ) ;
}
if ( ( V_77 = F_35 ( & V_93 ) ) != 0 ) {
F_12 ( V_34 L_14 ,
V_94 ) ;
V_64 . V_74 = 0 ;
return V_77 ;
}
return 0 ;
}
static int F_36 ( void )
{
static F_37 ( V_95 ) ;
struct V_78 * V_79 ;
struct V_23 * V_24 ;
int V_29 ;
int V_96 ;
if ( V_64 . V_74 == 0 )
return - V_71 ;
V_29 = - V_97 ;
for ( V_96 = 0 ; V_96 < V_21 ; V_96 ++ ) {
struct V_98 * V_99 = F_38 ( 1 ) ;
if ( ! V_99 )
goto V_100;
V_99 -> V_20 = F_39 ( F_15 , & V_95 ) ;
if ( ! V_99 -> V_20 ) {
F_40 ( V_99 ) ;
goto V_100;
}
V_19 [ V_96 ] = V_99 ;
}
if ( F_41 ( V_101 , L_15 ) ) {
V_29 = - V_30 ;
goto V_100;
}
for ( V_96 = 0 ; V_96 < V_21 ; V_96 ++ ) {
struct V_98 * V_99 = V_19 [ V_96 ] ;
if ( ( V_96 & V_102 ) >= V_103 ) continue;
V_79 = & V_64 ;
V_24 = & V_79 -> V_92 [ V_96 & V_102 ] ;
V_99 -> V_104 = V_101 ;
V_99 -> V_105 = V_96 ;
sprintf ( V_99 -> V_106 , L_16 , V_96 ) ;
V_99 -> V_107 = & V_108 ;
F_42 ( V_99 , V_24 -> V_31 >> 9 ) ;
V_99 -> V_26 = V_24 ;
F_43 ( V_99 ) ;
F_44 ( V_99 , 1 ) ;
}
return 0 ;
V_100:
while ( V_96 -- )
F_40 ( V_19 [ V_96 ] ) ;
return V_29 ;
}
static int T_9 F_45 ( void ) {
int V_77 ;
if ( ( V_77 = F_31 () ) == 0 ) {
F_36 () ;
return 0 ;
}
return V_77 ;
}
static void T_10 F_46 ( void )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_21 ; V_96 ++ ) {
if ( ( V_96 & V_102 ) >= V_103 ) continue;
F_47 ( V_19 [ V_96 ] ) ;
F_48 ( V_19 [ V_96 ] -> V_20 ) ;
F_40 ( V_19 [ V_96 ] ) ;
}
if ( V_64 . V_75 )
F_12 ( L_17 ) ;
V_64 . V_74 = 0 ;
V_64 . V_75 = 0 ;
F_49 ( & V_93 ) ;
F_50 ( V_101 , L_15 ) ;
}
