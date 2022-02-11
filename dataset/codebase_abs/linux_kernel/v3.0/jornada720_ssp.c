T_1 inline F_1 ( T_1 V_1 )
{
return
( ( 0x80 & V_1 ) >> 7 ) |
( ( 0x40 & V_1 ) >> 5 ) |
( ( 0x20 & V_1 ) >> 3 ) |
( ( 0x10 & V_1 ) >> 1 ) |
( ( 0x08 & V_1 ) << 1 ) |
( ( 0x04 & V_1 ) << 3 ) |
( ( 0x02 & V_1 ) << 5 ) |
( ( 0x01 & V_1 ) << 7 ) ;
}
int F_2 ( T_1 V_1 )
{
int V_2 = 400000 ;
T_2 V_3 ;
while ( ( V_4 & V_5 ) ) {
if ( ! -- V_2 ) {
F_3 ( V_6 L_1 ) ;
return - V_7 ;
}
F_4 () ;
}
V_3 = F_1 ( V_1 ) << 8 ;
F_5 ( V_3 ) ;
F_6 ( & V_3 ) ;
return F_1 ( V_3 ) ;
}
int F_7 ( T_1 V_1 )
{
int V_3 , V_8 ;
if ( V_1 != V_9 ) {
V_3 = F_2 ( V_1 ) ;
if ( V_3 != V_9 ) {
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ )
if ( F_2 ( V_9 ) == - 1 )
break;
return - V_7 ;
}
} else
V_3 = F_2 ( V_9 ) ;
return V_3 ;
}
void F_8 ( void )
{
F_9 ( & V_10 , V_11 ) ;
V_12 = V_13 ;
F_10 ( 50 ) ;
return;
}
void F_11 ( void )
{
V_14 = V_13 ;
F_12 ( & V_10 , V_11 ) ;
return;
}
static int T_3 F_13 ( struct V_15 * V_16 )
{
int V_3 ;
V_14 = V_13 ;
V_3 = F_14 () ;
if ( ! V_3 ) {
F_3 ( V_17 L_2 ) ;
return V_3 ;
}
F_3 ( V_6 L_3 ) ;
V_18 = 0 ;
V_19 = 0x0387 ;
V_20 = 0x18 ;
F_15 () ;
F_8 () ;
V_3 = F_7 ( V_21 ) ;
if ( V_3 == V_9 )
F_7 ( V_9 ) ;
F_11 () ;
if ( V_3 == - V_7 ) {
F_3 ( V_6 L_4 ) ;
F_16 () ;
return - V_22 ;
}
F_3 ( V_17 L_5 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 )
{
V_14 = V_13 ;
F_16 () ;
return 0 ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_23 ) ;
}
