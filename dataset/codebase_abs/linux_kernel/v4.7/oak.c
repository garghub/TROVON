static inline int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
void T_1 * V_5 = F_2 ( V_2 ) -> V_5 ;
F_3 ( L_1 , V_3 , V_4 ) ;
while( 1 )
{
int V_6 ;
while ( ( ( V_6 = F_4 ( V_5 + V_7 ) ) & 0x100 ) == 0 ) ;
}
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
void T_1 * V_5 = F_2 ( V_2 ) -> V_5 ;
F_3 ( L_2 , V_3 , V_4 ) ;
while( V_4 > 0 )
{
unsigned int V_6 , V_8 ;
unsigned long V_9 ;
V_8 = 0x01FFFFFF ;
while ( ( ( V_6 = F_4 ( V_5 + V_7 ) ) & 0x100 ) == 0 )
{
V_8 -- ;
if( V_6 & 0x200 || ! V_8 )
{
F_3 ( L_3 , V_6 ) ;
return - 1 ;
}
}
if( V_4 >= 128 )
{
F_6 ( V_5 + V_10 , V_3 , 128 ) ;
V_3 += 128 ;
V_4 -= 128 ;
}
else
{
V_9 = ( unsigned long ) F_4 ( V_5 + V_10 ) ;
* V_3 ++ = V_9 ;
V_4 -= 1 ;
if( V_4 )
* V_3 ++ = V_9 >> 8 ;
V_4 -= 1 ;
}
}
return 0 ;
}
static int F_7 ( struct V_11 * V_12 , const struct V_13 * V_14 )
{
struct V_1 * V_15 ;
int V_16 = - V_17 ;
V_16 = F_8 ( V_12 ) ;
if ( V_16 )
goto V_18;
V_15 = F_9 ( & V_19 , sizeof( struct V_20 ) ) ;
if ( ! V_15 ) {
V_16 = - V_17 ;
goto V_21;
}
F_2 ( V_15 ) -> V_5 = F_10 ( F_11 ( V_12 , V_22 ) ,
F_12 ( V_12 , V_22 ) ) ;
if ( ! F_2 ( V_15 ) -> V_5 ) {
V_16 = - V_17 ;
goto V_23;
}
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = 255 ;
V_16 = F_13 ( V_15 , V_27 | V_28 ) ;
if ( V_16 )
goto V_29;
F_14 ( V_15 ) ;
V_16 = F_15 ( V_15 , & V_12 -> V_30 ) ;
if ( V_16 )
goto V_31;
F_16 ( V_15 ) ;
goto V_18;
V_31:
F_17 ( V_15 ) ;
V_29:
F_18 ( F_2 ( V_15 ) -> V_5 ) ;
V_23:
F_19 ( V_15 ) ;
V_21:
F_20 ( V_12 ) ;
V_18:
return V_16 ;
}
static void F_21 ( struct V_11 * V_12 )
{
struct V_1 * V_15 = F_22 ( V_12 ) ;
F_23 ( V_12 , NULL ) ;
F_24 ( V_15 ) ;
F_17 ( V_15 ) ;
F_18 ( F_2 ( V_15 ) -> V_5 ) ;
F_19 ( V_15 ) ;
F_20 ( V_12 ) ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_32 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_32 ) ;
}
