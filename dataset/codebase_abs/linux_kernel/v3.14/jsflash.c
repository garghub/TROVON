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
static void F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_7 ( V_14 ) ;
while ( V_16 ) {
struct V_17 * V_18 = V_16 -> V_19 -> V_20 ;
unsigned long V_21 = F_8 ( V_16 ) << 9 ;
T_3 V_22 = F_9 ( V_16 ) ;
int V_23 = - V_24 ;
if ( ( V_21 + V_22 ) > V_18 -> V_25 )
goto V_26;
if ( F_10 ( V_16 ) != V_27 ) {
F_11 ( V_28 L_1 ) ;
goto V_26;
}
if ( ( V_18 -> V_29 & 0xff000000 ) != 0x20000000 ) {
F_11 ( V_28 L_2 , ( int ) V_18 -> V_29 ) ;
goto V_26;
}
F_5 ( V_16 -> V_30 , V_18 -> V_29 + V_21 , V_22 ) ;
V_23 = 0 ;
V_26:
if ( ! F_12 ( V_16 , V_23 ) )
V_16 = F_7 ( V_14 ) ;
}
}
static T_5 F_13 ( struct V_31 * V_31 , T_5 V_21 , int V_32 )
{
T_5 V_33 ;
F_14 ( & V_34 ) ;
switch ( V_32 ) {
case 0 :
V_31 -> V_35 = V_21 ;
V_33 = V_31 -> V_35 ;
break;
case 1 :
V_31 -> V_35 += V_21 ;
V_33 = V_31 -> V_35 ;
break;
default:
V_33 = - V_36 ;
}
F_15 ( & V_34 ) ;
return V_33 ;
}
static T_6 F_16 ( struct V_31 * V_31 , char T_7 * V_8 ,
T_3 V_9 , T_5 * V_37 )
{
unsigned long V_4 = * V_37 ;
char T_7 * V_38 = V_8 ;
union T_4 {
char V_10 [ 4 ] ;
unsigned int V_11 ;
} V_12 ;
if ( V_4 < V_39 || V_4 >= V_40 ) {
return 0 ;
}
if ( ( V_4 + V_9 ) < V_4
|| ( V_4 + V_9 ) >= V_40 ) {
V_9 = V_40 - V_4 ;
}
if ( V_4 < V_39 && V_9 != 0 ) {
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
if ( F_17 ( V_38 , V_12 . V_10 , 4 ) )
return - V_41 ;
V_38 += 4 ;
V_4 += 4 ;
}
* V_37 = V_4 ;
return V_38 - V_8 ;
}
static T_6 F_18 ( struct V_31 * V_31 , const char T_7 * V_8 ,
T_3 V_42 , T_5 * V_37 )
{
return - V_43 ;
}
static int F_19 ( unsigned long V_44 )
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
static int F_20 ( void T_7 * V_44 )
{
struct V_45 V_46 ;
char T_7 * V_47 ;
unsigned long V_4 ;
unsigned int V_9 ;
union {
unsigned int V_11 ;
char V_10 [ 4 ] ;
} V_12 ;
if ( F_21 ( & V_46 , V_44 , V_48 ) )
return - V_41 ;
V_4 = V_46 . V_49 ;
V_9 = V_46 . V_50 ;
if ( ( V_9 & 3 ) || ( V_4 & 3 ) ) return - V_36 ;
V_47 = ( char T_7 * ) ( unsigned long ) V_46 . V_3 ;
while ( V_9 != 0 ) {
V_9 -= 4 ;
if ( F_21 ( & V_12 . V_10 [ 0 ] , V_47 , 4 ) )
return - V_41 ;
F_4 ( V_4 , V_12 . V_11 ) ;
V_4 += 4 ;
V_47 += 4 ;
}
return 0 ;
}
static long F_22 ( struct V_31 * V_51 , unsigned int V_52 , unsigned long V_44 )
{
F_14 ( & V_34 ) ;
int error = - V_53 ;
void T_7 * V_54 = ( void T_7 * ) V_44 ;
if ( ! F_23 ( V_55 ) ) {
F_15 ( & V_34 ) ;
return - V_56 ;
}
switch ( V_52 ) {
case V_57 :
if ( F_17 ( V_54 , & V_58 . V_59 , V_60 ) ) {
F_15 ( & V_34 ) ;
return - V_41 ;
}
break;
case V_61 :
error = F_19 ( V_44 ) ;
break;
case V_62 :
error = F_20 ( V_54 ) ;
break;
}
F_15 ( & V_34 ) ;
return error ;
}
static int F_24 ( struct V_31 * V_31 , struct V_63 * V_64 )
{
return - V_65 ;
}
static int F_25 ( struct V_66 * V_66 , struct V_31 * V_67 )
{
F_14 ( & V_34 ) ;
if ( V_58 . V_68 == 0 ) {
F_15 ( & V_34 ) ;
return - V_65 ;
}
if ( F_26 ( 0 , ( void * ) & V_58 . V_69 ) != 0 ) {
F_15 ( & V_34 ) ;
return - V_70 ;
}
F_15 ( & V_34 ) ;
return 0 ;
}
static int F_27 ( struct V_66 * V_66 , struct V_31 * V_31 )
{
V_58 . V_69 = 0 ;
return 0 ;
}
static int F_28 ( void )
{
int V_71 ;
struct V_72 * V_73 ;
T_8 V_74 ;
char V_75 [ 128 ] ;
struct V_76 V_77 ;
V_74 = F_29 ( V_78 ) ;
V_74 = F_30 ( V_74 , L_3 ) ;
if ( V_74 != 0 && ( V_79 ) V_74 != - 1 ) {
if ( F_31 ( V_74 , L_4 ,
( char * ) & V_77 , sizeof( V_77 ) ) == - 1 ) {
F_11 ( L_5 ) ;
return - V_65 ;
}
if ( V_77 . V_80 != 0 ) {
F_11 ( L_6 ,
V_77 . V_80 , V_77 . V_81 ) ;
return - V_65 ;
}
#if 0
if ((reg0.phys_addr >> 24) != 0x20) {
printk("jsflash: suspicious address: 0x%x:%x\n",
reg0.which_io, reg0.phys_addr);
return -ENXIO;
}
#endif
if ( ( int ) V_77 . V_82 <= 0 ) {
F_11 ( L_7 , ( int ) V_77 . V_82 ) ;
return - V_65 ;
}
} else {
F_11 ( L_8 ) ;
F_31 ( V_78 , L_9 , V_75 , 128 ) ;
if ( strcmp ( V_75 , L_10 ) != 0 &&
strcmp ( V_75 , L_11 ) != 0 ) {
return - V_65 ;
}
V_77 . V_80 = 0 ;
V_77 . V_81 = 0x20400000 ;
V_77 . V_82 = 0x00800000 ;
}
if ( V_83 != V_84 ) {
return - V_65 ;
}
if ( V_58 . V_68 == 0 ) {
V_73 = & V_58 ;
V_73 -> V_68 = V_77 . V_81 ;
V_73 -> V_50 = V_77 . V_82 ;
V_73 -> V_59 . V_49 = V_39 ;
V_73 -> V_59 . V_50 = 0x01000000 ;
strcpy ( V_73 -> V_59 . V_85 , L_12 ) ;
V_73 -> V_86 [ 0 ] . V_29 = V_73 -> V_68 ;
V_73 -> V_86 [ 0 ] . V_25 = V_73 -> V_50 ;
V_73 -> V_86 [ 1 ] . V_29 = V_73 -> V_68 + 1024 ;
V_73 -> V_86 [ 1 ] . V_25 = V_73 -> V_50 - 1024 ;
V_73 -> V_86 [ 2 ] . V_29 = V_39 ;
V_73 -> V_86 [ 2 ] . V_25 = 0x01000000 ;
F_11 ( L_13 , V_73 -> V_68 ,
( int ) ( V_73 -> V_50 / ( 1024 * 1024 ) ) ) ;
}
if ( ( V_71 = F_32 ( & V_87 ) ) != 0 ) {
F_11 ( V_28 L_14 ,
V_88 ) ;
V_58 . V_68 = 0 ;
return V_71 ;
}
return 0 ;
}
static int F_33 ( void )
{
static F_34 ( V_89 ) ;
struct V_72 * V_73 ;
struct V_17 * V_18 ;
int V_23 ;
int V_90 ;
if ( V_58 . V_68 == 0 )
return - V_65 ;
V_23 = - V_91 ;
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
struct V_93 * V_94 = F_35 ( 1 ) ;
if ( ! V_94 )
goto V_95;
V_96 [ V_90 ] = V_94 ;
}
if ( F_36 ( V_97 , L_15 ) ) {
V_23 = - V_24 ;
goto V_95;
}
V_98 = F_37 ( F_6 , & V_89 ) ;
if ( ! V_98 ) {
V_23 = - V_91 ;
F_38 ( V_97 , L_15 ) ;
goto V_95;
}
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
struct V_93 * V_94 = V_96 [ V_90 ] ;
if ( ( V_90 & V_99 ) >= V_100 ) continue;
V_73 = & V_58 ;
V_18 = & V_73 -> V_86 [ V_90 & V_99 ] ;
V_94 -> V_101 = V_97 ;
V_94 -> V_102 = V_90 ;
sprintf ( V_94 -> V_103 , L_16 , V_90 ) ;
V_94 -> V_104 = & V_105 ;
F_39 ( V_94 , V_18 -> V_25 >> 9 ) ;
V_94 -> V_20 = V_18 ;
V_94 -> V_106 = V_98 ;
F_40 ( V_94 ) ;
F_41 ( V_94 , 1 ) ;
}
return 0 ;
V_95:
while ( V_90 -- )
F_42 ( V_96 [ V_90 ] ) ;
return V_23 ;
}
static int T_9 F_43 ( void ) {
int V_71 ;
if ( ( V_71 = F_28 () ) == 0 ) {
F_33 () ;
return 0 ;
}
return V_71 ;
}
static void T_10 F_44 ( void )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
if ( ( V_90 & V_99 ) >= V_100 ) continue;
F_45 ( V_96 [ V_90 ] ) ;
F_42 ( V_96 [ V_90 ] ) ;
}
if ( V_58 . V_69 )
F_11 ( L_17 ) ;
V_58 . V_68 = 0 ;
V_58 . V_69 = 0 ;
F_46 ( & V_87 ) ;
F_38 ( V_97 , L_15 ) ;
F_47 ( V_98 ) ;
}
