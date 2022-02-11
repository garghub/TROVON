static int F_1 ( int V_1 , int V_2 ,
void (* F_2) ( int V_1 , unsigned char V_3 ) ,
void (* F_3) ( int V_1 )
)
{
int V_4 ;
unsigned long V_5 ;
unsigned char V_6 ;
if ( V_7 )
return - V_8 ;
F_4 ( 0x20 | 0x40 ,
0x178b ) ;
F_5 ( & V_9 , V_5 ) ;
if ( ( V_4 = F_6 ( 0x10 ) ) < 0 )
{
F_7 ( & V_9 , V_5 ) ;
return V_4 ;
}
V_6 = 0 ;
V_10 = 0 ;
V_11 = F_2 ;
if ( V_2 == V_12 || V_2 == V_13 )
{
V_6 |= 0x04 ;
V_10 = 1 ;
}
if ( V_2 == V_14 || V_2 == V_13 )
{
V_6 |= 0x08 | 0x10 ;
}
F_4 ( V_6 , 0x178b ) ;
F_4 ( 0xff , 0x1B88 ) ;
F_7 ( & V_9 , V_5 ) ;
V_7 = 1 ;
V_15 = V_16 = V_17 = 0 ;
return 0 ;
}
static void F_8 ( int V_1 )
{
F_4 ( 0x20 | 0x40 , 0x178b ) ;
F_9 ( 0x10 ) ;
V_7 = 0 ;
}
static int F_10 ( unsigned char V_18 )
{
int V_19 , V_20 ;
V_19 = ( ( V_20 = F_11 ( 0x1B89 ) ) >> 4 ) & 0x0f ;
if ( V_19 < 2 && V_19 != 0 )
return 0 ;
F_4 ( V_18 , 0x178A ) ;
return 1 ;
}
static int F_12 ( int V_1 , unsigned char V_18 )
{
unsigned long V_5 ;
F_5 ( & V_9 , V_5 ) ;
while ( V_15 && F_10 ( V_21 [ V_16 ] ) )
{
V_15 -- ;
V_16 ++ ;
}
F_7 ( & V_9 , V_5 ) ;
if ( ! V_15 )
if ( F_10 ( V_18 ) )
return 1 ;
if ( V_15 >= 256 )
return 0 ;
F_5 ( & V_9 , V_5 ) ;
V_21 [ V_17 ] = V_18 ;
V_15 ++ ;
V_17 ++ ;
F_7 ( & V_9 , V_5 ) ;
return 1 ;
}
static int F_13 ( int V_1 )
{
return 0 ;
}
static int F_14 ( int V_1 )
{
return 0 ;
}
static void F_15 ( int V_1 )
{
}
static int F_16 ( int V_1 )
{
return V_15 ;
}
void T_1 F_17 ( void )
{
int V_1 = F_18 () ;
if ( V_1 == - 1 )
{
F_19 ( V_22 L_1 ) ;
return;
}
V_23 . V_24 = V_25 = V_1 ;
V_26 [ V_1 ] = & V_27 ;
V_28 = V_1 ;
F_20 () ;
}
void F_21 ( void )
{
unsigned char V_29 ;
int V_30 , V_31 ;
V_29 = F_11 ( 0x1B88 ) ;
if ( V_29 & 0x04 )
{
V_31 = F_11 ( 0x1B89 ) & 0x0f ;
if ( ! V_31 )
V_31 = 16 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
if ( V_10 )
{
V_11 ( V_25 , F_11 ( 0x178A ) ) ;
} else
F_11 ( 0x178A ) ;
}
if ( V_29 & ( 0x08 | 0x10 ) )
{
F_22 ( & V_9 ) ;
while ( V_15 && F_10 ( V_21 [ V_16 ] ) )
{
V_15 -- ;
V_16 ++ ;
}
F_23 ( & V_9 ) ;
}
if ( V_29 & 0x40 )
{
F_19 ( V_22 L_2 , F_11 ( 0x1B89 ) , V_29 ) ;
}
F_4 ( V_29 , 0x1B88 ) ;
}
