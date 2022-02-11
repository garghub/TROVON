static T_1 T_2 F_1 ( unsigned long V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 + 4 ) ;
F_3 ( 20 ) ;
V_2 = F_4 ( V_1 + 5 ) ;
F_3 ( 20 ) ;
return V_2 ;
}
static int T_2 F_5 ( struct V_3 * V_4 , const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
void T_3 * V_10 ;
unsigned long V_1 ;
T_4 V_11 ;
T_1 V_12 , V_13 , V_14 ;
int V_15 ;
extern int V_16 ;
V_9 = F_6 ( V_4 , 0 ) ;
if( V_9 == 0UL )
return 1 ;
V_10 = F_7 ( V_9 , 128 ) ;
if ( ! V_10 )
return 1 ;
V_11 = F_8 ( V_10 + 0x18 ) ;
F_9 ( V_10 ) ;
V_1 = 0x220 + 0x20 * ( V_11 & 3 ) ;
if( V_11 & ( 1 << 2 ) )
F_10 ( V_17 L_1 , V_1 ) ;
else
return 1 ;
if( V_11 & ( 1 << 5 ) )
F_10 ( V_17 L_2 ) ;
else if( V_11 & ( 1 << 6 ) )
F_10 ( V_17 L_3 ) ;
V_12 = F_1 ( V_1 , 0x80 ) & 0x0F ;
V_13 = F_1 ( V_1 , 0x81 ) ;
if( V_13 & 0x20 )
V_14 = 5 ;
else if( V_13 & 0x40 )
V_14 = 6 ;
else if( V_13 & 0x80 )
V_14 = 7 ;
else
{
F_10 ( V_18 L_4 ) ;
return 1 ;
}
if( V_13 & 0x01 )
V_13 = 0 ;
else if( V_13 & 0x02 )
V_13 = 1 ;
else if( V_13 & 0x08 )
V_13 = 3 ;
else
{
F_10 ( V_18 L_5 ) ;
return 1 ;
}
if( V_12 & 1 )
V_12 = 9 ;
else if( V_12 & 2 )
V_12 = 5 ;
else if( V_12 & 4 )
V_12 = 7 ;
else if( V_12 & 8 )
V_12 = 10 ;
else
{
F_10 ( V_18 L_6 ) ;
return 1 ;
}
F_10 ( V_17 L_7 ,
V_12 , V_13 , V_14 ) ;
V_8 = F_11 ( sizeof( struct V_7 ) , V_19 ) ;
if( V_8 == NULL )
{
F_10 ( V_18 L_8 ) ;
return 1 ;
}
F_12 ( V_4 , V_8 ) ;
V_8 -> V_20 = V_1 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_21 = V_13 ;
V_8 -> V_22 = V_14 ;
V_8 -> V_23 = L_9 ;
V_8 -> V_24 = V_25 | V_26 ;
if ( ! F_13 ( V_1 , 16 , L_10 ) )
goto V_27;
if( F_14 ( V_8 , 0 , 0 , NULL ) == 0 )
{
F_10 ( V_18 L_11 ) ;
F_15 ( V_1 , 16 ) ;
goto V_27;
}
V_15 = V_16 ;
V_16 = 1 ;
if( F_16 ( V_8 , V_28 ) )
{
V_16 = V_15 ;
goto V_27;
}
V_16 = V_15 ;
return 0 ;
V_27:
F_12 ( V_4 , NULL ) ;
F_17 ( V_8 ) ;
return 1 ;
}
static void T_5 F_18 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_19 ( V_4 ) ;
F_20 ( V_8 , 0 ) ;
F_12 ( V_4 , NULL ) ;
F_17 ( V_8 ) ;
}
static int T_6 F_21 ( void )
{
F_10 ( V_17 L_12 ) ;
return F_22 ( & V_29 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_29 ) ;
}
