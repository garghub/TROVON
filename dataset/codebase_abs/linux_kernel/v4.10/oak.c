static inline int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
T_1 T_2 * V_5 = V_2 -> V_6 ;
F_2 ( L_1 , V_3 , V_4 ) ;
while( 1 )
{
int V_7 ;
while ( ( ( V_7 = F_3 ( V_5 + V_8 ) ) & 0x100 ) == 0 ) ;
}
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
T_1 T_2 * V_5 = V_2 -> V_6 ;
F_2 ( L_2 , V_3 , V_4 ) ;
while( V_4 > 0 )
{
unsigned int V_7 , V_9 ;
unsigned long V_10 ;
V_9 = 0x01FFFFFF ;
while ( ( ( V_7 = F_3 ( V_5 + V_8 ) ) & 0x100 ) == 0 )
{
V_9 -- ;
if( V_7 & 0x200 || ! V_9 )
{
F_2 ( L_3 , V_7 ) ;
return - 1 ;
}
}
if( V_4 >= 128 )
{
F_5 ( V_5 + V_11 , V_3 , 128 ) ;
V_3 += 128 ;
V_4 -= 128 ;
}
else
{
V_10 = ( unsigned long ) F_3 ( V_5 + V_11 ) ;
* V_3 ++ = V_10 ;
V_4 -= 1 ;
if( V_4 )
* V_3 ++ = V_10 >> 8 ;
V_4 -= 1 ;
}
}
return 0 ;
}
static int F_6 ( struct V_12 * V_13 , const struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_18 = - V_19 ;
V_18 = F_7 ( V_13 ) ;
if ( V_18 )
goto V_20;
V_17 = F_8 ( & V_21 , sizeof( struct V_1 ) ) ;
if ( ! V_17 ) {
V_18 = - V_19 ;
goto V_22;
}
F_9 ( V_17 ) -> V_6 = F_10 ( F_11 ( V_13 , V_23 ) ,
F_12 ( V_13 , V_23 ) ) ;
if ( ! F_9 ( V_17 ) -> V_6 ) {
V_18 = - V_19 ;
goto V_24;
}
V_17 -> V_25 = V_26 ;
V_18 = F_13 ( V_17 , V_27 | V_28 ) ;
if ( V_18 )
goto V_29;
F_14 ( V_17 ) ;
V_18 = F_15 ( V_17 , & V_13 -> V_30 ) ;
if ( V_18 )
goto V_31;
F_16 ( V_17 ) ;
goto V_20;
V_31:
F_17 ( V_17 ) ;
V_29:
F_18 ( F_9 ( V_17 ) -> V_6 ) ;
V_24:
F_19 ( V_17 ) ;
V_22:
F_20 ( V_13 ) ;
V_20:
return V_18 ;
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = F_22 ( V_13 ) ;
void T_2 * V_5 = F_9 ( V_17 ) -> V_6 ;
F_23 ( V_13 , NULL ) ;
F_24 ( V_17 ) ;
F_17 ( V_17 ) ;
F_19 ( V_17 ) ;
F_18 ( V_5 ) ;
F_20 ( V_13 ) ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_32 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_32 ) ;
}
