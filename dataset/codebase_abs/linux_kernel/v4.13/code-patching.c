static int F_1 ( unsigned int * V_1 , unsigned int V_2 )
{
int V_3 ;
F_2 ( V_2 , V_1 , 4 , V_3 ) ;
if ( V_3 )
return V_3 ;
asm ("dcbst 0, %0; sync; icbi 0,%0; sync; isync" :: "r" (addr));
return 0 ;
}
static int F_3 ( unsigned int V_4 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( V_7 , V_8 ) ;
if ( ! V_6 ) {
F_5 ( 1 , L_1 ,
V_4 ) ;
return - 1 ;
}
F_6 ( V_9 , V_6 ) ;
return 0 ;
}
static int F_7 ( unsigned int V_4 )
{
F_8 ( F_9 ( V_9 ) ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
F_11 ( ! F_12 ( V_10 ,
L_2 , F_3 ,
F_7 ) ) ;
return 0 ;
}
static int F_13 ( void * V_1 , unsigned long V_11 )
{
unsigned long V_12 ;
int V_3 ;
if ( F_14 ( V_1 ) )
V_12 = F_15 ( V_1 ) ;
else
V_12 = F_16 ( V_1 ) >> V_13 ;
V_3 = F_17 ( V_11 , ( V_12 << V_13 ) ,
F_18 ( V_14 ) ) ;
F_19 ( L_3 , V_11 , V_12 , V_3 ) ;
if ( V_3 )
return - 1 ;
return 0 ;
}
static inline int F_20 ( unsigned long V_1 )
{
T_2 * V_15 ;
T_3 * V_16 ;
T_4 * V_17 ;
T_5 * V_18 ;
V_18 = F_21 ( V_1 ) ;
if ( F_22 ( ! V_18 ) )
return - V_19 ;
V_17 = F_23 ( V_18 , V_1 ) ;
if ( F_22 ( ! V_17 ) )
return - V_19 ;
V_16 = F_24 ( V_17 , V_1 ) ;
if ( F_22 ( ! V_16 ) )
return - V_19 ;
V_15 = F_25 ( V_16 , V_1 ) ;
if ( F_22 ( ! V_15 ) )
return - V_19 ;
F_19 ( L_4 , & V_20 , V_15 , V_1 ) ;
F_26 ( & V_20 , V_1 , V_15 ) ;
F_27 ( V_1 , V_1 + V_7 ) ;
return 0 ;
}
int F_28 ( unsigned int * V_1 , unsigned int V_2 )
{
int V_3 ;
unsigned int * V_21 = NULL ;
unsigned long V_22 ;
unsigned long V_11 ;
unsigned long V_23 = ( unsigned long ) V_1 ;
if ( ! F_29 () || ! F_9 ( V_9 ) )
return F_1 ( V_1 , V_2 ) ;
F_30 ( V_22 ) ;
V_11 = ( unsigned long ) F_31 ( V_9 ) -> V_1 ;
if ( F_13 ( V_1 , V_11 ) ) {
V_3 = - 1 ;
goto V_24;
}
V_21 = ( unsigned int * ) ( V_11 ) +
( ( V_23 & ~ V_25 ) / sizeof( unsigned int ) ) ;
F_2 ( V_2 , V_21 , 4 , V_3 ) ;
if ( ! V_3 )
asm ("dcbst 0, %0; sync; icbi 0,%0; icbi 0,%1; sync; isync"
::"r" (dest), "r"(addr));
V_3 = F_20 ( V_11 ) ;
if ( V_3 )
F_32 ( L_5 , V_11 ) ;
V_24:
F_33 ( V_22 ) ;
return V_3 ;
}
int F_28 ( unsigned int * V_1 , unsigned int V_2 )
{
return F_1 ( V_1 , V_2 ) ;
}
int F_34 ( unsigned int * V_1 , unsigned long V_26 , int V_22 )
{
return F_28 ( V_1 , F_35 ( V_1 , V_26 , V_22 ) ) ;
}
bool F_36 ( long V_27 )
{
return ( V_27 >= - 0x2000000 && V_27 <= 0x1fffffc && ! ( V_27 & 0x3 ) ) ;
}
bool F_37 ( unsigned int V_2 )
{
unsigned int V_28 = V_2 >> 26 ;
if ( V_28 == 16 )
return true ;
if ( V_28 == 19 ) {
switch ( ( V_2 >> 1 ) & 0x3ff ) {
case 16 :
case 528 :
case 560 :
return true ;
}
}
return false ;
}
unsigned int F_35 ( const unsigned int * V_1 ,
unsigned long V_26 , int V_22 )
{
unsigned int V_29 ;
long V_27 ;
V_27 = V_26 ;
if ( ! ( V_22 & V_30 ) )
V_27 = V_27 - ( unsigned long ) V_1 ;
if ( ! F_36 ( V_27 ) )
return 0 ;
V_29 = 0x48000000 | ( V_22 & 0x3 ) | ( V_27 & 0x03FFFFFC ) ;
return V_29 ;
}
unsigned int F_38 ( const unsigned int * V_1 ,
unsigned long V_26 , int V_22 )
{
unsigned int V_29 ;
long V_27 ;
V_27 = V_26 ;
if ( ! ( V_22 & V_30 ) )
V_27 = V_27 - ( unsigned long ) V_1 ;
if ( V_27 < - 0x8000 || V_27 > 0x7FFF || V_27 & 0x3 )
return 0 ;
V_29 = 0x40000000 | ( V_22 & 0x3FF0003 ) | ( V_27 & 0xFFFC ) ;
return V_29 ;
}
static unsigned int F_39 ( unsigned int V_2 )
{
return ( V_2 >> 26 ) & 0x3F ;
}
static int F_40 ( unsigned int V_2 )
{
return F_39 ( V_2 ) == 18 ;
}
static int F_41 ( unsigned int V_2 )
{
return F_39 ( V_2 ) == 16 ;
}
int F_42 ( unsigned int V_2 )
{
if ( V_2 & V_30 )
return 0 ;
return F_40 ( V_2 ) || F_41 ( V_2 ) ;
}
static unsigned long F_43 ( const unsigned int * V_2 )
{
signed long V_31 ;
V_31 = * V_2 & 0x3FFFFFC ;
if ( V_31 & 0x2000000 )
V_31 -= 0x4000000 ;
if ( ( * V_2 & V_30 ) == 0 )
V_31 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_31 ;
}
static unsigned long F_44 ( const unsigned int * V_2 )
{
signed long V_31 ;
V_31 = * V_2 & 0xFFFC ;
if ( V_31 & 0x8000 )
V_31 -= 0x10000 ;
if ( ( * V_2 & V_30 ) == 0 )
V_31 += ( unsigned long ) V_2 ;
return ( unsigned long ) V_31 ;
}
unsigned long F_45 ( const unsigned int * V_2 )
{
if ( F_40 ( * V_2 ) )
return F_43 ( V_2 ) ;
else if ( F_41 ( * V_2 ) )
return F_44 ( V_2 ) ;
return 0 ;
}
int F_46 ( const unsigned int * V_2 , unsigned long V_1 )
{
if ( F_40 ( * V_2 ) || F_41 ( * V_2 ) )
return F_45 ( V_2 ) == V_1 ;
return 0 ;
}
unsigned int F_47 ( const unsigned int * V_21 , const unsigned int * V_32 )
{
unsigned long V_26 ;
V_26 = F_45 ( V_32 ) ;
if ( F_40 ( * V_32 ) )
return F_35 ( V_21 , V_26 , * V_32 ) ;
else if ( F_41 ( * V_32 ) )
return F_38 ( V_21 , V_26 , * V_32 ) ;
return 0 ;
}
void F_48 ( int V_33 , unsigned long V_1 )
{
extern unsigned int V_34 ;
unsigned int * V_35 = & V_34 ;
F_34 ( V_35 + ( V_33 / 4 ) + 1 , V_1 , 0 ) ;
}
static void T_1 F_49 ( void )
{
asm ("nop;\n");
}
static void T_1 F_50 ( void )
{
unsigned int V_2 ;
unsigned long V_1 ;
V_1 = ( unsigned long ) & V_2 ;
F_51 ( F_40 ( 0x48000000 ) ) ;
F_51 ( F_40 ( 0x4bffffff ) ) ;
F_51 ( ! F_40 ( 0xcbffffff ) ) ;
F_51 ( ! F_40 ( 0x7bffffff ) ) ;
F_51 ( F_40 ( 0x48000001 ) ) ;
F_51 ( F_40 ( 0x4bfffffd ) ) ;
F_51 ( F_40 ( 0x4bff00fd ) ) ;
F_51 ( ! F_40 ( 0x7bfffffd ) ) ;
V_2 = 0x48000103 ;
F_51 ( F_46 ( & V_2 , 0x100 ) ) ;
V_2 = 0x480420ff ;
F_51 ( F_46 ( & V_2 , 0x420fc ) ) ;
V_2 = 0x49fffffc ;
F_51 ( F_46 ( & V_2 , V_1 + 0x1FFFFFC ) ) ;
V_2 = 0x4bfffffc ;
F_51 ( F_46 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x4a000000 ;
F_51 ( F_46 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_35 ( & V_2 , V_1 , V_36 ) ;
F_51 ( F_46 ( & V_2 , V_1 ) ) ;
V_2 = F_35 ( & V_2 , V_1 - 0x100 , V_36 ) ;
F_51 ( F_46 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_35 ( & V_2 , V_1 + 0x100 , 0 ) ;
F_51 ( F_46 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_35 ( & V_2 , V_1 - 0x2000000 , V_36 ) ;
F_51 ( F_46 ( & V_2 , V_1 - 0x2000000 ) ) ;
V_2 = F_35 ( & V_2 , V_1 - 0x2000004 , V_36 ) ;
F_51 ( V_2 == 0 ) ;
V_2 = F_35 ( & V_2 , V_1 + 0x2000000 , V_36 ) ;
F_51 ( V_2 == 0 ) ;
V_2 = F_35 ( & V_2 , V_1 + 3 , V_36 ) ;
F_51 ( V_2 == 0 ) ;
V_2 = F_35 ( & V_2 , V_1 , 0xFFFFFFFC ) ;
F_51 ( F_46 ( & V_2 , V_1 ) ) ;
F_51 ( V_2 == 0x48000000 ) ;
}
static void T_1 F_52 ( void )
{
unsigned int * V_37 ;
unsigned long V_21 ;
V_37 = ( unsigned int * ) F_53 ( F_49 ) ;
V_21 = F_53 ( F_52 ) ;
F_28 ( V_37 , F_35 ( V_37 , V_21 , V_36 ) ) ;
F_51 ( F_46 ( V_37 , V_21 ) ) ;
}
static void T_1 F_54 ( void )
{
unsigned long V_1 ;
unsigned int * V_37 , V_2 , V_22 ;
V_37 = & V_2 ;
V_1 = ( unsigned long ) V_37 ;
F_51 ( F_41 ( 0x40000000 ) ) ;
F_51 ( F_41 ( 0x43ffffff ) ) ;
F_51 ( ! F_41 ( 0xc3ffffff ) ) ;
F_51 ( ! F_41 ( 0x7bffffff ) ) ;
V_2 = 0x43ff0103 ;
F_51 ( F_46 ( & V_2 , 0x100 ) ) ;
V_2 = 0x43ff20ff ;
F_51 ( F_46 ( & V_2 , 0x20fc ) ) ;
V_2 = 0x43ff7ffc ;
F_51 ( F_46 ( & V_2 , V_1 + 0x7FFC ) ) ;
V_2 = 0x43fffffc ;
F_51 ( F_46 ( & V_2 , V_1 - 4 ) ) ;
V_2 = 0x43ff8000 ;
F_51 ( F_46 ( & V_2 , V_1 - 0x8000 ) ) ;
V_22 = 0x3ff000 | V_36 ;
V_2 = F_38 ( V_37 , V_1 , V_22 ) ;
F_51 ( F_46 ( & V_2 , V_1 ) ) ;
V_2 = F_38 ( V_37 , V_1 - 0x100 , V_22 ) ;
F_51 ( F_46 ( & V_2 , V_1 - 0x100 ) ) ;
V_2 = F_38 ( V_37 , V_1 + 0x100 , V_22 ) ;
F_51 ( F_46 ( & V_2 , V_1 + 0x100 ) ) ;
V_2 = F_38 ( V_37 , V_1 - 0x8000 , V_22 ) ;
F_51 ( F_46 ( & V_2 , V_1 - 0x8000 ) ) ;
V_2 = F_38 ( V_37 , V_1 - 0x8004 , V_22 ) ;
F_51 ( V_2 == 0 ) ;
V_2 = F_38 ( V_37 , V_1 + 0x8000 , V_22 ) ;
F_51 ( V_2 == 0 ) ;
V_2 = F_38 ( V_37 , V_1 + 3 , V_22 ) ;
F_51 ( V_2 == 0 ) ;
V_2 = F_38 ( V_37 , V_1 , 0xFFFFFFFC ) ;
F_51 ( F_46 ( & V_2 , V_1 ) ) ;
F_51 ( V_2 == 0x43FF0000 ) ;
}
static void T_1 F_55 ( void )
{
unsigned long V_1 ;
unsigned int * V_38 , * V_39 ;
void * V_40 ;
V_40 = F_56 ( F_57 ( 0x2000000 + 1 ) ) ;
F_51 ( V_40 ) ;
if ( ! V_40 )
return;
V_38 = V_40 ;
V_1 = ( unsigned long ) V_38 ;
F_34 ( V_38 , V_1 , 0 ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
V_39 = V_38 + 1 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
V_38 = V_40 ;
V_1 = ( unsigned long ) V_38 ;
F_34 ( V_38 , V_1 , 0 ) ;
V_39 = V_40 + 0x2000000 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
F_51 ( * V_39 == 0x4a000000 ) ;
V_38 = V_40 + 0x2000000 ;
V_1 = ( unsigned long ) V_38 ;
F_34 ( V_38 , V_1 , 0 ) ;
V_39 = V_40 + 4 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
F_51 ( * V_39 == 0x49fffffc ) ;
V_38 = V_40 ;
V_1 = 0x1000000 + ( unsigned long ) V_40 ;
F_34 ( V_38 , V_1 , V_36 ) ;
V_39 = V_40 + 0x1400000 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
V_38 = V_40 + 0x1000000 ;
V_1 = 0x2000000 + ( unsigned long ) V_40 ;
F_34 ( V_38 , V_1 , 0 ) ;
V_39 = V_40 + 4 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
V_38 = V_40 ;
V_1 = ( unsigned long ) V_38 ;
F_28 ( V_38 , F_38 ( V_38 , V_1 , 0 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
V_39 = V_38 + 1 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
V_38 = V_40 ;
V_1 = ( unsigned long ) V_38 ;
F_28 ( V_38 , F_38 ( V_38 , V_1 , 0xFFFFFFFC ) ) ;
V_39 = V_40 + 0x8000 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
F_51 ( * V_39 == 0x43ff8000 ) ;
V_38 = V_40 + 0x8000 ;
V_1 = ( unsigned long ) V_38 ;
F_28 ( V_38 , F_38 ( V_38 , V_1 , 0xFFFFFFFC ) ) ;
V_39 = V_40 + 4 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
F_51 ( * V_39 == 0x43ff7ffc ) ;
V_38 = V_40 ;
V_1 = 0x3000 + ( unsigned long ) V_40 ;
F_28 ( V_38 , F_38 ( V_38 , V_1 , V_36 ) ) ;
V_39 = V_40 + 0x5000 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
V_38 = V_40 + 0x2000 ;
V_1 = 0x4000 + ( unsigned long ) V_40 ;
F_28 ( V_38 , F_38 ( V_38 , V_1 , 0 ) ) ;
V_39 = V_40 + 4 ;
F_28 ( V_39 , F_47 ( V_39 , V_38 ) ) ;
F_51 ( F_46 ( V_38 , V_1 ) ) ;
F_51 ( F_46 ( V_39 , V_1 ) ) ;
F_58 ( V_40 ) ;
}
static int T_1 F_59 ( void )
{
F_60 ( V_41 L_6 ) ;
F_50 () ;
F_54 () ;
F_52 () ;
F_55 () ;
return 0 ;
}
