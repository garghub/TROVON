void F_1 ( unsigned int * V_1 , unsigned int V_2 )
{
* V_1 = V_2 ;
asm ("dcbst 0, %0; sync; icbi 0,%0; sync; isync" : : "r" (addr));
}
void F_2 ( unsigned int * V_1 , unsigned long V_3 , int V_4 )
{
F_1 ( V_1 , F_3 ( V_1 , V_3 , V_4 ) ) ;
}
unsigned int F_3 ( const unsigned int * V_1 ,
unsigned long V_3 , int V_4 )
{
unsigned int V_5 ;
long V_6 ;
V_6 = V_3 ;
if ( ! ( V_4 & V_7 ) )
V_6 = V_6 - ( unsigned long ) V_1 ;
if ( V_6 < - 0x2000000 || V_6 > 0x1fffffc || V_6 & 0x3 )
return 0 ;
V_5 = 0x48000000 | ( V_4 & 0x3 ) | ( V_6 & 0x03FFFFFC ) ;
return V_5 ;
}
unsigned int F_4 ( const unsigned int * V_1 ,
unsigned long V_3 , int V_4 )
{
unsigned int V_5 ;
long V_6 ;
V_6 = V_3 ;
if ( ! ( V_4 & V_7 ) )
V_6 = V_6 - ( unsigned long ) V_1 ;
if ( V_6 < - 0x8000 || V_6 > 0x7FFF || V_6 & 0x3 )
return 0 ;
V_5 = 0x40000000 | ( V_4 & 0x3FF0003 ) | ( V_6 & 0xFFFC ) ;
return V_5 ;
}
static unsigned int F_5 ( unsigned int V_2 )
{
return ( V_2 >> 26 ) & 0x3F ;
}
static int F_6 ( unsigned int V_2 )
{
return F_5 ( V_2 ) == 18 ;
}
static int F_7 ( unsigned int V_2 )
{
return F_5 ( V_2 ) == 16 ;
}
int F_8 ( unsigned int V_2 )
{
if ( V_2 & V_7 )
return 0 ;
return F_6 ( V_2 ) || F_7 ( V_2 ) ;
}
static unsigned long F_9 ( const unsigned int * V_2 )
{
signed long V_8 ;
V_8 = * V_2 & 0x3FFFFFC ;
if ( V_8 & 0x2000000 )
V_8 -= 0x4000000 ;
if ( ( * V_2 & V_7 ) == 0 )
V_8 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_8 ;
}
static unsigned long F_10 ( const unsigned int * V_2 )
{
signed long V_8 ;
V_8 = * V_2 & 0xFFFC ;
if ( V_8 & 0x8000 )
V_8 -= 0x10000 ;
if ( ( * V_2 & V_7 ) == 0 )
V_8 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_8 ;
}
unsigned long F_11 ( const unsigned int * V_2 )
{
if ( F_6 ( * V_2 ) )
return F_9 ( V_2 ) ;
else if ( F_7 ( * V_2 ) )
return F_10 ( V_2 ) ;
return 0 ;
}
int F_12 ( const unsigned int * V_2 , unsigned long V_1 )
{
if ( F_6 ( * V_2 ) || F_7 ( * V_2 ) )
return F_11 ( V_2 ) == V_1 ;
return 0 ;
}
unsigned int F_13 ( const unsigned int * V_9 , const unsigned int * V_10 )
{
unsigned long V_3 ;
V_3 = F_11 ( V_10 ) ;
if ( F_6 ( * V_10 ) )
return F_3 ( V_9 , V_3 , * V_10 ) ;
else if ( F_7 ( * V_10 ) )
return F_4 ( V_9 , V_3 , * V_10 ) ;
return 0 ;
}
static void T_1 F_14 ( void )
{
asm ("nop;\n");
}
static void T_1 F_15 ( void )
{
unsigned int V_2 ;
unsigned long V_1 ;
V_1 = ( unsigned long ) & V_2 ;
F_16 ( F_6 ( 0x48000000 ) ) ;
F_16 ( F_6 ( 0x4bffffff ) ) ;
F_16 ( ! F_6 ( 0xcbffffff ) ) ;
F_16 ( ! F_6 ( 0x7bffffff ) ) ;
F_16 ( F_6 ( 0x48000001 ) ) ;
F_16 ( F_6 ( 0x4bfffffd ) ) ;
F_16 ( F_6 ( 0x4bff00fd ) ) ;
F_16 ( ! F_6 ( 0x7bfffffd ) ) ;
V_2 = 0x48000103 ;
F_16 ( F_12 ( & V_2 , 0x100 ) ) ;
V_2 = 0x480420ff ;
F_16 ( F_12 ( & V_2 , 0x420fc ) ) ;
V_2 = 0x49fffffc ;
F_16 ( F_12 ( & V_2 , V_1 + 0x1FFFFFC ) ) ;
V_2 = 0x4bfffffc ;
F_16 ( F_12 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x4a000000 ;
F_16 ( F_12 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_3 ( & V_2 , V_1 , V_11 ) ;
F_16 ( F_12 ( & V_2 , V_1 ) ) ;
V_2 = F_3 ( & V_2 , V_1 - 0x100 , V_11 ) ;
F_16 ( F_12 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_3 ( & V_2 , V_1 + 0x100 , 0 ) ;
F_16 ( F_12 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_3 ( & V_2 , V_1 - 0x2000000 , V_11 ) ;
F_16 ( F_12 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_3 ( & V_2 , V_1 - 0x2000004 , V_11 ) ;
F_16 ( V_2 == 0 ) ;
V_2 = F_3 ( & V_2 , V_1 + 0x2000000 , V_11 ) ;
F_16 ( V_2 == 0 ) ;
V_2 = F_3 ( & V_2 , V_1 + 3 , V_11 ) ;
F_16 ( V_2 == 0 ) ;
V_2 = F_3 ( & V_2 , V_1 , 0xFFFFFFFC ) ;
F_16 ( F_12 ( & V_2 , V_1 ) ) ;
F_16 ( V_2 == 0x48000000 ) ;
}
static void T_1 F_17 ( void )
{
unsigned int * V_12 ;
unsigned long V_9 ;
V_12 = ( unsigned int * ) F_18 ( F_14 ) ;
V_9 = F_18 ( F_17 ) ;
F_1 ( V_12 , F_3 ( V_12 , V_9 , V_11 ) ) ;
F_16 ( F_12 ( V_12 , V_9 ) ) ;
}
static void T_1 F_19 ( void )
{
unsigned long V_1 ;
unsigned int * V_12 , V_2 , V_4 ;
V_12 = & V_2 ;
V_1 = ( unsigned long ) V_12 ;
F_16 ( F_7 ( 0x40000000 ) ) ;
F_16 ( F_7 ( 0x43ffffff ) ) ;
F_16 ( ! F_7 ( 0xc3ffffff ) ) ;
F_16 ( ! F_7 ( 0x7bffffff ) ) ;
V_2 = 0x43ff0103 ;
F_16 ( F_12 ( & V_2 , 0x100 ) ) ;
V_2 = 0x43ff20ff ;
F_16 ( F_12 ( & V_2 , 0x20fc ) ) ;
V_2 = 0x43ff7ffc ;
F_16 ( F_12 ( & V_2 , V_1 + 0x7FFC ) ) ;
V_2 = 0x43fffffc ;
F_16 ( F_12 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x43ff8000 ;
F_16 ( F_12 ( & V_2 , V_1 - 0x8000 ) ) ;
V_4 = 0x3ff000 | V_11 ;
V_2 = F_4 ( V_12 , V_1 , V_4 ) ;
F_16 ( F_12 ( & V_2 , V_1 ) ) ;
V_2 = F_4 ( V_12 , V_1 - 0x100 , V_4 ) ;
F_16 ( F_12 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_4 ( V_12 , V_1 + 0x100 , V_4 ) ;
F_16 ( F_12 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_4 ( V_12 , V_1 - 0x8000 , V_4 ) ;
F_16 ( F_12 ( & V_2 , V_1 - 0x8000 ) ) ;
V_2 = F_4 ( V_12 , V_1 - 0x8004 , V_4 ) ;
F_16 ( V_2 == 0 ) ;
V_2 = F_4 ( V_12 , V_1 + 0x8000 , V_4 ) ;
F_16 ( V_2 == 0 ) ;
V_2 = F_4 ( V_12 , V_1 + 3 , V_4 ) ;
F_16 ( V_2 == 0 ) ;
V_2 = F_4 ( V_12 , V_1 , 0xFFFFFFFC ) ;
F_16 ( F_12 ( & V_2 , V_1 ) ) ;
F_16 ( V_2 == 0x43FF0000 ) ;
}
static void T_1 F_20 ( void )
{
unsigned long V_1 ;
unsigned int * V_13 , * V_14 ;
void * V_15 ;
V_15 = F_21 ( F_22 ( 0x2000000 + 1 ) ) ;
F_16 ( V_15 ) ;
if ( ! V_15 )
return;
V_13 = V_15 ;
V_1 = ( unsigned long ) V_13 ;
F_2 ( V_13 , V_1 , 0 ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
V_14 = V_13 + 1 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
V_13 = V_15 ;
V_1 = ( unsigned long ) V_13 ;
F_2 ( V_13 , V_1 , 0 ) ;
V_14 = V_15 + 0x2000000 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
F_16 ( * V_14 == 0x4a000000 ) ;
V_13 = V_15 + 0x2000000 ;
V_1 = ( unsigned long ) V_13 ;
F_2 ( V_13 , V_1 , 0 ) ;
V_14 = V_15 + 4 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
F_16 ( * V_14 == 0x49fffffc ) ;
V_13 = V_15 ;
V_1 = 0x1000000 + ( unsigned long ) V_15 ;
F_2 ( V_13 , V_1 , V_11 ) ;
V_14 = V_15 + 0x1400000 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
V_13 = V_15 + 0x1000000 ;
V_1 = 0x2000000 + ( unsigned long ) V_15 ;
F_2 ( V_13 , V_1 , 0 ) ;
V_14 = V_15 + 4 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
V_13 = V_15 ;
V_1 = ( unsigned long ) V_13 ;
F_1 ( V_13 , F_4 ( V_13 , V_1 , 0 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
V_14 = V_13 + 1 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
V_13 = V_15 ;
V_1 = ( unsigned long ) V_13 ;
F_1 ( V_13 , F_4 ( V_13 , V_1 , 0xFFFFFFFC ) ) ;
V_14 = V_15 + 0x8000 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
F_16 ( * V_14 == 0x43ff8000 ) ;
V_13 = V_15 + 0x8000 ;
V_1 = ( unsigned long ) V_13 ;
F_1 ( V_13 , F_4 ( V_13 , V_1 , 0xFFFFFFFC ) ) ;
V_14 = V_15 + 4 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
F_16 ( * V_14 == 0x43ff7ffc ) ;
V_13 = V_15 ;
V_1 = 0x3000 + ( unsigned long ) V_15 ;
F_1 ( V_13 , F_4 ( V_13 , V_1 , V_11 ) ) ;
V_14 = V_15 + 0x5000 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
V_13 = V_15 + 0x2000 ;
V_1 = 0x4000 + ( unsigned long ) V_15 ;
F_1 ( V_13 , F_4 ( V_13 , V_1 , 0 ) ) ;
V_14 = V_15 + 4 ;
F_1 ( V_14 , F_13 ( V_14 , V_13 ) ) ;
F_16 ( F_12 ( V_13 , V_1 ) ) ;
F_16 ( F_12 ( V_14 , V_1 ) ) ;
F_23 ( V_15 ) ;
}
static int T_1 F_24 ( void )
{
F_25 ( V_16 L_1 ) ;
F_15 () ;
F_19 () ;
F_17 () ;
F_20 () ;
return 0 ;
}
