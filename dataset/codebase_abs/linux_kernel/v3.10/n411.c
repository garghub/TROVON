static void F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned
char V_4 )
{
switch ( V_3 ) {
case V_5 :
if ( V_4 )
V_6 &= ~ ( V_5 ) ;
else
V_6 |= V_5 ;
break;
case V_7 :
if ( V_4 )
V_6 &= ~ ( V_7 ) ;
else
V_6 |= V_7 ;
break;
}
F_2 ( V_6 , V_8 ) ;
}
static unsigned char F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned char V_10 )
{
F_2 ( V_10 , V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_12 )
{
int V_13 ;
unsigned char V_14 ;
V_13 = 500 ;
do {
V_14 = F_3 ( V_2 ) ;
if ( ( V_14 & V_15 ) && ( ! V_12 ) )
return;
else if ( ! ( V_14 & V_15 ) && ( V_12 ) )
return;
F_7 ( 1 ) ;
} while ( V_13 -- );
F_8 ( V_16 L_1 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned char V_14 ;
V_6 = V_17 | V_18 | V_5 ;
F_1 ( V_2 , V_7 , 1 ) ;
V_14 = F_3 ( V_2 ) ;
if ( V_14 & V_15 ) {
F_8 ( V_16 L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_9 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_21 ( V_2 , V_22 ) ;
V_2 -> V_23 ( V_2 , 0x81 ) ;
F_7 ( 1000 ) ;
if ( ! V_24 ) {
V_2 -> V_21 ( V_2 , V_25 ) ;
V_2 -> V_23 ( V_2 , V_26 ) ;
}
return 0 ;
}
static int T_1 F_11 ( void )
{
int V_27 ;
if ( ! V_11 || ! V_8 || ! V_9 ) {
F_8 ( V_28 L_3 ) ;
return - V_29 ;
}
F_12 ( L_4 ) ;
V_30 = F_13 ( L_4 , - 1 ) ;
if ( ! V_30 )
return - V_31 ;
F_14 ( V_30 , & V_32 , sizeof( V_32 ) ) ;
V_27 = F_15 ( V_30 ) ;
if ( V_27 )
F_16 ( V_30 ) ;
return V_27 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_30 ) ;
}
