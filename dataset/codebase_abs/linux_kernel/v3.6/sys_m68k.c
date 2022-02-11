T_1 long F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static inline int
F_3 ( unsigned long V_1 , int V_7 , int V_8 , unsigned long V_2 )
{
unsigned long V_9 , V_10 ;
switch ( V_7 )
{
case V_11 :
switch ( V_8 )
{
case V_12 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpusha %dc\n\t"
".chip 68k");
break;
case V_13 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpusha %ic\n\t"
".chip 68k");
break;
default:
case V_14 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpusha %bc\n\t"
".chip 68k");
break;
}
break;
case V_15 :
if ( ( V_9 = F_4 ( V_1 ) ) ) {
V_9 += V_1 & ~ ( V_16 | 15 ) ;
V_2 = ( V_2 + ( V_1 & 15 ) + 15 ) >> 4 ;
} else {
unsigned long V_17 = V_18 - ( V_1 & ~ V_16 ) ;
if ( V_2 <= V_17 )
return 0 ;
V_1 += V_17 ;
V_2 -= V_17 ;
V_17 = V_18 ;
for (; ; )
{
if ( ( V_9 = F_4 ( V_1 ) ) )
break;
if ( V_2 <= V_17 )
return 0 ;
V_1 += V_17 ;
V_2 -= V_17 ;
}
V_2 = ( V_2 + 15 ) >> 4 ;
}
V_10 = ( V_18 - ( V_9 & ~ V_16 ) ) >> 4 ;
while ( V_2 -- )
{
switch ( V_8 )
{
case V_12 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushl %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case V_13 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushl %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case V_14 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
if ( ! -- V_10 && V_2 )
{
V_1 += V_18 ;
V_10 = V_18 / 16 ;
for (; ; )
{
if ( ( V_9 = F_4 ( V_1 ) ) )
break;
if ( V_2 <= V_10 )
return 0 ;
V_2 -= V_10 ;
V_1 += V_18 ;
}
}
else
V_9 += 16 ;
}
break;
default:
case V_19 :
V_2 += ( V_1 & ~ V_16 ) + ( V_18 - 1 ) ;
for ( V_2 >>= V_20 ; V_2 -- ; V_1 += V_18 )
{
if ( ! ( V_9 = F_4 ( V_1 ) ) )
continue;
switch ( V_8 )
{
case V_12 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushp %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case V_13 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushp %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case V_14 :
__asm__ __volatile__ ("nop\n\t"
".chip 68040\n\t"
"cpushp %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
}
break;
}
return 0 ;
}
static inline int
F_5 ( unsigned long V_1 , int V_7 , int V_8 , unsigned long V_2 )
{
unsigned long V_9 , V_10 ;
switch ( V_7 )
{
case V_11 :
switch ( V_8 )
{
case V_12 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpusha %dc\n\t"
".chip 68k");
break;
case V_13 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpusha %ic\n\t"
".chip 68k");
break;
default:
case V_14 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpusha %bc\n\t"
".chip 68k");
break;
}
break;
case V_15 :
V_2 += V_1 & 15 ;
V_1 &= - 16 ;
if ( ! ( V_9 = F_6 ( V_1 ) ) ) {
unsigned long V_17 = V_18 - ( V_1 & ~ V_16 ) ;
if ( V_2 <= V_17 )
return 0 ;
V_1 += V_17 ;
V_2 -= V_17 ;
V_17 = V_18 ;
for (; ; )
{
if ( ( V_9 = F_6 ( V_1 ) ) )
break;
if ( V_2 <= V_17 )
return 0 ;
V_1 += V_17 ;
V_2 -= V_17 ;
}
}
V_2 = ( V_2 + 15 ) >> 4 ;
V_10 = ( V_18 - ( V_9 & ~ V_16 ) ) >> 4 ;
while ( V_2 -- )
{
switch ( V_8 )
{
case V_12 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case V_13 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case V_14 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpushl %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
if ( ! -- V_10 && V_2 )
{
V_1 += V_18 ;
V_1 &= V_16 ;
V_10 = V_18 / 16 ;
for (; ; )
{
if ( ( V_9 = F_6 ( V_1 ) ) )
break;
if ( V_2 <= V_10 )
return 0 ;
V_2 -= V_10 ;
V_1 += V_18 ;
}
}
else
V_9 += 16 ;
}
break;
default:
case V_19 :
V_2 += ( V_1 & ~ V_16 ) + ( V_18 - 1 ) ;
V_1 &= V_16 ;
for ( V_2 >>= V_20 ; V_2 -- ; V_1 += V_18 )
{
if ( ! ( V_9 = F_6 ( V_1 ) ) )
continue;
switch ( V_8 )
{
case V_12 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpushp %%dc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
case V_13 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpushp %%ic,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
default:
case V_14 :
__asm__ __volatile__ (".chip 68060\n\t"
"cpushp %%bc,(%0)\n\t"
".chip 68k"
: : "a" (paddr));
break;
}
}
break;
}
return 0 ;
}
T_1 int
F_7 ( unsigned long V_1 , int V_7 , int V_8 , unsigned long V_2 )
{
struct V_21 * V_22 ;
int V_23 = - V_24 ;
if ( V_7 < V_15 || V_7 > V_11 ||
V_8 & ~ V_14 )
goto V_25;
if ( V_7 == V_11 ) {
V_23 = - V_26 ;
if ( ! F_8 ( V_27 ) )
goto V_25;
} else {
V_22 = F_9 ( V_28 -> V_29 , V_1 ) ;
V_23 = - V_24 ;
if ( V_1 + V_2 < V_1 )
goto V_25;
if ( V_22 == NULL || V_1 < V_22 -> V_30 || V_1 + V_2 > V_22 -> V_31 )
goto V_25;
}
if ( V_32 ) {
if ( V_7 == V_15 && V_2 < 256 ) {
unsigned long V_33 ;
__asm__ ("movec %%cacr, %0" : "=r" (cacr));
if ( V_8 & V_13 )
V_33 |= 4 ;
if ( V_8 & V_12 )
V_33 |= 0x400 ;
V_2 >>= 2 ;
while ( V_2 -- ) {
__asm__ __volatile__ ("movec %1, %%caar\n\t"
"movec %0, %%cacr"
:
: "r" (cacr), "r" (addr));
V_1 += 4 ;
}
} else {
unsigned long V_33 ;
__asm__ ("movec %%cacr, %0" : "=r" (cacr));
if ( V_8 & V_13 )
V_33 |= 8 ;
if ( V_8 & V_12 )
V_33 |= 0x800 ;
__asm__ __volatile__ ("movec %0, %%cacr" : : "r" (cacr));
}
V_23 = 0 ;
goto V_25;
} else {
if ( V_2 >= 3 * V_18 && V_7 < V_19 )
V_7 = V_19 ;
if ( V_2 >= 10 * V_18 && V_7 < V_11 )
V_7 = V_11 ;
if ( V_34 ) {
V_23 = F_3 ( V_1 , V_7 , V_8 , V_2 ) ;
} else if ( V_35 ) {
V_23 = F_5 ( V_1 , V_7 , V_8 , V_2 ) ;
}
}
V_25:
return V_23 ;
}
T_1 int
F_10 ( unsigned long V_36 , int V_37 , int V_38 , int V_39 , int V_40 ,
unsigned long T_2 * V_41 )
{
for (; ; ) {
struct V_42 * V_29 = V_28 -> V_29 ;
T_3 * V_43 ;
T_4 * V_44 ;
T_5 * V_45 ;
T_6 * V_46 ;
unsigned long V_47 ;
F_11 ( & V_29 -> V_48 ) ;
V_43 = F_12 ( V_29 , ( unsigned long ) V_41 ) ;
if ( ! F_13 ( * V_43 ) )
goto V_49;
V_44 = F_14 ( V_43 , ( unsigned long ) V_41 ) ;
if ( ! F_15 ( * V_44 ) )
goto V_49;
V_45 = F_16 ( V_29 , V_44 , ( unsigned long ) V_41 , & V_46 ) ;
if ( ! F_17 ( * V_45 ) || ! F_18 ( * V_45 )
|| ! F_19 ( * V_45 ) ) {
F_20 ( V_45 , V_46 ) ;
goto V_49;
}
F_21 ( V_47 , V_41 ) ;
if ( V_47 == V_37 )
F_22 ( V_36 , V_41 ) ;
F_20 ( V_45 , V_46 ) ;
F_23 ( & V_29 -> V_48 ) ;
return V_47 ;
V_49:
F_23 ( & V_29 -> V_48 ) ;
{
struct V_50 * V_51 = (struct V_50 * ) & V_36 ;
if ( F_24 ( V_51 , ( unsigned long ) V_41 , 3 ) )
return 0xdeadbeef ;
}
}
}
T_1 int
F_7 ( unsigned long V_1 , int V_7 , int V_8 , unsigned long V_2 )
{
F_25 () ;
return 0 ;
}
T_1 int
F_10 ( unsigned long V_36 , int V_37 , int V_38 , int V_39 , int V_40 ,
unsigned long T_2 * V_41 )
{
struct V_42 * V_29 = V_28 -> V_29 ;
unsigned long V_47 ;
F_11 ( & V_29 -> V_48 ) ;
V_47 = * V_41 ;
if ( V_47 == V_37 )
* V_41 = V_36 ;
F_23 ( & V_29 -> V_48 ) ;
return V_47 ;
}
T_1 int F_26 ( void )
{
return V_18 ;
}
int F_27 ( const char * V_52 ,
const char * const V_53 [] ,
const char * const V_54 [] )
{
register long T_7 V_55 ( L_1 ) = V_56 ;
register long T_8 V_55 ( L_2 ) = ( long ) ( V_52 ) ;
register long T_9 V_55 ( L_3 ) = ( long ) ( V_53 ) ;
register long T_10 V_55 ( L_4 ) = ( long ) ( V_54 ) ;
asm volatile ("trap #0" : "+d" (__res)
: "d" (__a), "d" (__b), "d" (__c));
return T_7 ;
}
T_1 unsigned long F_28 ( void )
{
return F_29 () -> V_57 ;
}
T_1 int F_30 ( unsigned long V_58 )
{
F_29 () -> V_57 = V_58 ;
return 0 ;
}
T_1 int F_31 ( void )
{
return 0 ;
}
