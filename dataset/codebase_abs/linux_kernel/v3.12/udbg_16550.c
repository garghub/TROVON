static void F_1 ( void )
{
if ( ! V_1 )
return;
while ( ( V_1 ( V_2 ) & V_3 ) == 0 )
F_2 () ;
}
static void F_3 ( char V_4 )
{
if ( ! V_5 )
return;
if ( V_4 == '\n' )
F_3 ( '\r' ) ;
F_1 () ;
V_5 ( V_6 , V_4 ) ;
}
static int F_4 ( void )
{
if ( ! V_1 || ! ( V_1 ( V_2 ) & V_7 ) )
return V_1 ( V_8 ) ;
return - 1 ;
}
static int F_5 ( void )
{
if ( ! V_1 )
return - 1 ;
while ( ! ( V_1 ( V_2 ) & V_7 ) )
F_2 () ;
return V_1 ( V_8 ) ;
}
static void F_6 ( void )
{
V_9 = F_3 ;
V_10 = F_1 ;
V_11 = F_5 ;
V_12 = F_4 ;
}
void F_7 ( unsigned int V_13 , unsigned int clock )
{
unsigned int V_14 , V_15 ;
if ( ! V_5 )
return;
if ( clock == 0 )
clock = 1843200 ;
if ( V_13 == 0 )
V_13 = 9600 ;
V_15 = clock / 16 ;
V_14 = V_15 / V_13 ;
V_5 ( V_16 , 0x00 ) ;
V_5 ( V_17 , 0xff ) ;
V_5 ( V_17 , 0x00 ) ;
V_5 ( V_16 , V_18 ) ;
V_5 ( V_19 , V_14 & 0xff ) ;
V_5 ( V_20 , V_14 >> 8 ) ;
V_5 ( V_16 , 0x3 ) ;
V_5 ( V_21 , 0x3 ) ;
V_5 ( V_22 , 0x7 ) ;
}
unsigned int F_8 ( unsigned int clock )
{
unsigned int V_14 , V_23 , V_24 , V_25 , V_13 ;
T_1 V_26 ;
V_26 = V_1 ( V_16 ) ;
V_5 ( V_16 , V_26 | V_18 ) ;
V_14 = V_1 ( V_19 ) ;
V_23 = V_1 ( V_20 ) ;
V_24 = V_23 << 8 | V_14 ;
if ( V_1 ( V_21 ) & 0x80 )
V_25 = 4 ;
else
V_25 = 1 ;
V_5 ( V_16 , V_26 ) ;
V_13 = ( clock / V_25 ) / ( V_24 * 16 ) ;
if ( V_13 > ( clock / 16 ) )
V_13 = 9600 ;
return V_13 ;
}
static T_1 F_9 ( unsigned int V_27 )
{
return F_10 ( V_28 . V_29 + ( V_27 * V_30 ) ) ;
}
static void F_11 ( unsigned int V_27 , T_1 V_31 )
{
F_12 ( V_31 , V_28 . V_29 + ( V_27 * V_30 ) ) ;
}
void F_13 ( unsigned long V_32 , unsigned int V_33 )
{
if ( ! V_32 )
return;
V_28 . V_29 = V_32 ;
V_30 = V_33 ;
V_1 = F_9 ;
V_5 = F_11 ;
F_6 () ;
}
static T_1 F_14 ( unsigned int V_27 )
{
return F_15 ( V_28 . V_34 + ( V_27 * V_30 ) ) ;
}
static void F_16 ( unsigned int V_27 , T_1 V_31 )
{
F_17 ( V_28 . V_34 + ( V_27 * V_30 ) , V_31 ) ;
}
void F_18 ( void T_2 * V_35 , unsigned int V_33 )
{
if ( ! V_35 )
return;
V_28 . V_34 = V_35 ;
V_30 = V_33 ;
V_1 = F_14 ;
V_5 = F_16 ;
F_6 () ;
}
static T_1 F_19 ( unsigned int V_27 )
{
return F_20 ( V_36 + V_27 ) ;
}
static void F_21 ( unsigned int V_27 , T_1 V_37 )
{
F_22 ( V_37 , V_36 + V_27 ) ;
}
void T_3 F_23 ( void )
{
V_1 = F_19 ;
V_5 = F_21 ;
F_6 () ;
}
static T_1 F_24 ( unsigned int V_27 )
{
return F_25 ( V_38 + V_27 ) ;
}
static void F_26 ( unsigned int V_27 , T_1 V_37 )
{
F_27 ( V_37 , V_38 + V_27 ) ;
}
void T_3 F_28 ( void )
{
V_1 = F_24 ;
V_5 = F_26 ;
F_6 () ;
}
static T_1 F_29 ( unsigned int V_27 )
{
return F_30 ( ( void T_2 * ) V_39 + V_27 ) ;
}
static void F_31 ( unsigned int V_27 , T_1 V_37 )
{
F_32 ( V_37 , ( void T_2 * ) V_39 + V_27 ) ;
}
void T_3 F_33 ( void )
{
V_1 = F_29 ;
V_5 = F_31 ;
F_6 () ;
}
static T_1 F_34 ( unsigned int V_27 )
{
return F_20 ( ( void T_2 * ) V_40
+ V_27 ) ;
}
static void F_35 ( unsigned int V_27 , T_1 V_37 )
{
F_22 ( V_37 , ( void T_2 * ) V_40
+ V_27 ) ;
}
void T_3 F_36 ( void )
{
V_1 = F_34 ;
V_5 = F_35 ;
F_6 () ;
}
void T_3 F_37 ( void )
{
F_18 ( ( void * ) V_41 , 1 ) ;
F_7 ( 57600 , 50000000 ) ;
}
