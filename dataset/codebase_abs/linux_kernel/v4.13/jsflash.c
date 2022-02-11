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
T_5 V_29 = V_30 ;
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
V_29 = V_37 ;
V_32:
if ( ! F_14 ( V_22 , V_29 ) )
V_22 = F_6 () ;
}
}
static void F_15 ( struct V_14 * V_15 )
{
F_8 () ;
}
static T_6 F_16 ( struct V_38 * V_38 , T_6 V_27 , int V_39 )
{
T_6 V_40 ;
F_17 ( & V_41 ) ;
switch ( V_39 ) {
case 0 :
V_38 -> V_42 = V_27 ;
V_40 = V_38 -> V_42 ;
break;
case 1 :
V_38 -> V_42 += V_27 ;
V_40 = V_38 -> V_42 ;
break;
default:
V_40 = - V_43 ;
}
F_18 ( & V_41 ) ;
return V_40 ;
}
static T_7 F_19 ( struct V_38 * V_38 , char T_8 * V_8 ,
T_3 V_9 , T_6 * V_44 )
{
unsigned long V_4 = * V_44 ;
char T_8 * V_45 = V_8 ;
union T_4 {
char V_10 [ 4 ] ;
unsigned int V_11 ;
} V_12 ;
if ( V_4 < V_46 || V_4 >= V_47 ) {
return 0 ;
}
if ( ( V_4 + V_9 ) < V_4
|| ( V_4 + V_9 ) >= V_47 ) {
V_9 = V_47 - V_4 ;
}
if ( V_4 < V_46 && V_9 != 0 ) {
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
if ( F_20 ( V_45 , V_12 . V_10 , 4 ) )
return - V_48 ;
V_45 += 4 ;
V_4 += 4 ;
}
* V_44 = V_4 ;
return V_45 - V_8 ;
}
static T_7 F_21 ( struct V_38 * V_38 , const char T_8 * V_8 ,
T_3 V_49 , T_6 * V_44 )
{
return - V_50 ;
}
static int F_22 ( unsigned long V_51 )
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
static int F_23 ( void T_8 * V_51 )
{
struct V_52 V_53 ;
char T_8 * V_54 ;
unsigned long V_4 ;
unsigned int V_9 ;
union {
unsigned int V_11 ;
char V_10 [ 4 ] ;
} V_12 ;
if ( F_24 ( & V_53 , V_51 , V_55 ) )
return - V_48 ;
V_4 = V_53 . V_56 ;
V_9 = V_53 . V_57 ;
if ( ( V_9 & 3 ) || ( V_4 & 3 ) ) return - V_43 ;
V_54 = ( char T_8 * ) ( unsigned long ) V_53 . V_3 ;
while ( V_9 != 0 ) {
V_9 -= 4 ;
if ( F_24 ( & V_12 . V_10 [ 0 ] , V_54 , 4 ) )
return - V_48 ;
F_4 ( V_4 , V_12 . V_11 ) ;
V_4 += 4 ;
V_54 += 4 ;
}
return 0 ;
}
static long F_25 ( struct V_38 * V_58 , unsigned int V_59 , unsigned long V_51 )
{
F_17 ( & V_41 ) ;
int error = - V_60 ;
void T_8 * V_61 = ( void T_8 * ) V_51 ;
if ( ! F_26 ( V_62 ) ) {
F_18 ( & V_41 ) ;
return - V_63 ;
}
switch ( V_59 ) {
case V_64 :
if ( F_20 ( V_61 , & V_65 . V_66 , V_67 ) ) {
F_18 ( & V_41 ) ;
return - V_48 ;
}
break;
case V_68 :
error = F_22 ( V_51 ) ;
break;
case V_69 :
error = F_23 ( V_61 ) ;
break;
}
F_18 ( & V_41 ) ;
return error ;
}
static int F_27 ( struct V_38 * V_38 , struct V_70 * V_71 )
{
return - V_72 ;
}
static int F_28 ( struct V_73 * V_73 , struct V_38 * V_74 )
{
F_17 ( & V_41 ) ;
if ( V_65 . V_75 == 0 ) {
F_18 ( & V_41 ) ;
return - V_72 ;
}
if ( F_29 ( 0 , ( void * ) & V_65 . V_76 ) != 0 ) {
F_18 ( & V_41 ) ;
return - V_77 ;
}
F_18 ( & V_41 ) ;
return 0 ;
}
static int F_30 ( struct V_73 * V_73 , struct V_38 * V_38 )
{
V_65 . V_76 = 0 ;
return 0 ;
}
static int F_31 ( void )
{
int V_78 ;
struct V_79 * V_80 ;
T_9 V_81 ;
char V_82 [ 128 ] ;
struct V_83 V_84 ;
V_81 = F_32 ( V_85 ) ;
V_81 = F_33 ( V_81 , L_3 ) ;
if ( V_81 != 0 && ( V_86 ) V_81 != - 1 ) {
if ( F_34 ( V_81 , L_4 ,
( char * ) & V_84 , sizeof( V_84 ) ) == - 1 ) {
F_12 ( L_5 ) ;
return - V_72 ;
}
if ( V_84 . V_87 != 0 ) {
F_12 ( L_6 ,
V_84 . V_87 , V_84 . V_88 ) ;
return - V_72 ;
}
#if 0
if ((reg0.phys_addr >> 24) != 0x20) {
printk("jsflash: suspicious address: 0x%x:%x\n",
reg0.which_io, reg0.phys_addr);
return -ENXIO;
}
#endif
if ( ( int ) V_84 . V_89 <= 0 ) {
F_12 ( L_7 , ( int ) V_84 . V_89 ) ;
return - V_72 ;
}
} else {
F_12 ( L_8 ) ;
F_34 ( V_85 , L_9 , V_82 , 128 ) ;
if ( strcmp ( V_82 , L_10 ) != 0 &&
strcmp ( V_82 , L_11 ) != 0 ) {
return - V_72 ;
}
V_84 . V_87 = 0 ;
V_84 . V_88 = 0x20400000 ;
V_84 . V_89 = 0x00800000 ;
}
if ( V_90 != V_91 ) {
return - V_72 ;
}
if ( V_65 . V_75 == 0 ) {
V_80 = & V_65 ;
V_80 -> V_75 = V_84 . V_88 ;
V_80 -> V_57 = V_84 . V_89 ;
V_80 -> V_66 . V_56 = V_46 ;
V_80 -> V_66 . V_57 = 0x01000000 ;
strcpy ( V_80 -> V_66 . V_92 , L_12 ) ;
V_80 -> V_93 [ 0 ] . V_35 = V_80 -> V_75 ;
V_80 -> V_93 [ 0 ] . V_31 = V_80 -> V_57 ;
V_80 -> V_93 [ 1 ] . V_35 = V_80 -> V_75 + 1024 ;
V_80 -> V_93 [ 1 ] . V_31 = V_80 -> V_57 - 1024 ;
V_80 -> V_93 [ 2 ] . V_35 = V_46 ;
V_80 -> V_93 [ 2 ] . V_31 = 0x01000000 ;
F_12 ( L_13 , V_80 -> V_75 ,
( int ) ( V_80 -> V_57 / ( 1024 * 1024 ) ) ) ;
}
if ( ( V_78 = F_35 ( & V_94 ) ) != 0 ) {
F_12 ( V_34 L_14 ,
V_95 ) ;
V_65 . V_75 = 0 ;
return V_78 ;
}
return 0 ;
}
static int F_36 ( void )
{
static F_37 ( V_96 ) ;
struct V_79 * V_80 ;
struct V_23 * V_24 ;
int V_29 ;
int V_97 ;
if ( V_65 . V_75 == 0 )
return - V_72 ;
V_29 = - V_98 ;
for ( V_97 = 0 ; V_97 < V_21 ; V_97 ++ ) {
struct V_99 * V_100 = F_38 ( 1 ) ;
if ( ! V_100 )
goto V_101;
V_100 -> V_20 = F_39 ( F_15 , & V_96 ) ;
if ( ! V_100 -> V_20 ) {
F_40 ( V_100 ) ;
goto V_101;
}
F_41 ( V_100 -> V_20 , V_102 ) ;
V_19 [ V_97 ] = V_100 ;
}
if ( F_42 ( V_103 , L_15 ) ) {
V_29 = - V_104 ;
goto V_101;
}
for ( V_97 = 0 ; V_97 < V_21 ; V_97 ++ ) {
struct V_99 * V_100 = V_19 [ V_97 ] ;
if ( ( V_97 & V_105 ) >= V_106 ) continue;
V_80 = & V_65 ;
V_24 = & V_80 -> V_93 [ V_97 & V_105 ] ;
V_100 -> V_107 = V_103 ;
V_100 -> V_108 = V_97 ;
sprintf ( V_100 -> V_109 , L_16 , V_97 ) ;
V_100 -> V_110 = & V_111 ;
F_43 ( V_100 , V_24 -> V_31 >> 9 ) ;
V_100 -> V_26 = V_24 ;
F_44 ( V_100 ) ;
F_45 ( V_100 , 1 ) ;
}
return 0 ;
V_101:
while ( V_97 -- )
F_40 ( V_19 [ V_97 ] ) ;
return V_29 ;
}
static int T_10 F_46 ( void ) {
int V_78 ;
if ( ( V_78 = F_31 () ) == 0 ) {
F_36 () ;
return 0 ;
}
return V_78 ;
}
static void T_11 F_47 ( void )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_21 ; V_97 ++ ) {
if ( ( V_97 & V_105 ) >= V_106 ) continue;
F_48 ( V_19 [ V_97 ] ) ;
F_49 ( V_19 [ V_97 ] -> V_20 ) ;
F_40 ( V_19 [ V_97 ] ) ;
}
if ( V_65 . V_76 )
F_12 ( L_17 ) ;
V_65 . V_75 = 0 ;
V_65 . V_76 = 0 ;
F_50 ( & V_94 ) ;
F_51 ( V_103 , L_15 ) ;
}
