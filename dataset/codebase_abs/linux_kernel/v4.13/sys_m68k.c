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
int V_21 = - V_22 ;
if ( V_7 < V_15 || V_7 > V_11 ||
V_8 & ~ V_14 )
goto V_23;
if ( V_7 == V_11 ) {
V_21 = - V_24 ;
if ( ! F_8 ( V_25 ) )
goto V_23;
} else {
struct V_26 * V_27 ;
if ( V_1 + V_2 < V_1 )
goto V_23;
F_9 ( & V_28 -> V_29 -> V_30 ) ;
V_27 = F_10 ( V_28 -> V_29 , V_1 ) ;
if ( ! V_27 || V_1 < V_27 -> V_31 || V_1 + V_2 > V_27 -> V_32 )
goto V_33;
}
if ( V_34 ) {
if ( V_7 == V_15 && V_2 < 256 ) {
unsigned long V_35 ;
__asm__ ("movec %%cacr, %0" : "=r" (cacr));
if ( V_8 & V_13 )
V_35 |= 4 ;
if ( V_8 & V_12 )
V_35 |= 0x400 ;
V_2 >>= 2 ;
while ( V_2 -- ) {
__asm__ __volatile__ ("movec %1, %%caar\n\t"
"movec %0, %%cacr"
:
: "r" (cacr), "r" (addr));
V_1 += 4 ;
}
} else {
unsigned long V_35 ;
__asm__ ("movec %%cacr, %0" : "=r" (cacr));
if ( V_8 & V_13 )
V_35 |= 8 ;
if ( V_8 & V_12 )
V_35 |= 0x800 ;
__asm__ __volatile__ ("movec %0, %%cacr" : : "r" (cacr));
}
V_21 = 0 ;
goto V_33;
} else {
if ( V_2 >= 3 * V_18 && V_7 < V_19 )
V_7 = V_19 ;
if ( V_2 >= 10 * V_18 && V_7 < V_11 )
V_7 = V_11 ;
if ( V_36 ) {
V_21 = F_3 ( V_1 , V_7 , V_8 , V_2 ) ;
} else if ( V_37 ) {
V_21 = F_5 ( V_1 , V_7 , V_8 , V_2 ) ;
}
}
V_33:
F_11 ( & V_28 -> V_29 -> V_30 ) ;
V_23:
return V_21 ;
}
T_1 int
F_12 ( unsigned long V_38 , int V_39 , int V_40 , int V_41 , int V_42 ,
unsigned long T_2 * V_43 )
{
for (; ; ) {
struct V_44 * V_29 = V_28 -> V_29 ;
T_3 * V_45 ;
T_4 * V_46 ;
T_5 * V_47 ;
T_6 * V_48 ;
unsigned long V_49 ;
F_9 ( & V_29 -> V_30 ) ;
V_45 = F_13 ( V_29 , ( unsigned long ) V_43 ) ;
if ( ! F_14 ( * V_45 ) )
goto V_50;
V_46 = F_15 ( V_45 , ( unsigned long ) V_43 ) ;
if ( ! F_16 ( * V_46 ) )
goto V_50;
V_47 = F_17 ( V_29 , V_46 , ( unsigned long ) V_43 , & V_48 ) ;
if ( ! F_18 ( * V_47 ) || ! F_19 ( * V_47 )
|| ! F_20 ( * V_47 ) ) {
F_21 ( V_47 , V_48 ) ;
goto V_50;
}
F_22 ( V_49 , V_43 ) ;
if ( V_49 == V_39 )
F_23 ( V_38 , V_43 ) ;
F_21 ( V_47 , V_48 ) ;
F_11 ( & V_29 -> V_30 ) ;
return V_49 ;
V_50:
F_11 ( & V_29 -> V_30 ) ;
{
struct V_51 * V_52 = (struct V_51 * ) & V_38 ;
if ( F_24 ( V_52 , ( unsigned long ) V_43 , 3 ) )
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
F_12 ( unsigned long V_38 , int V_39 , int V_40 , int V_41 , int V_42 ,
unsigned long T_2 * V_43 )
{
struct V_44 * V_29 = V_28 -> V_29 ;
unsigned long V_49 ;
F_9 ( & V_29 -> V_30 ) ;
V_49 = * V_43 ;
if ( V_49 == V_39 )
* V_43 = V_38 ;
F_11 ( & V_29 -> V_30 ) ;
return V_49 ;
}
T_1 int F_26 ( void )
{
return V_18 ;
}
T_1 unsigned long F_27 ( void )
{
return F_28 () -> V_53 ;
}
T_1 int F_29 ( unsigned long V_54 )
{
F_28 () -> V_53 = V_54 ;
return 0 ;
}
T_1 int F_30 ( void )
{
return 0 ;
}
