const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static inline int F_2 ( struct V_1 * V_3 , unsigned char * V_4 ,
int V_5 )
{
void T_1 * V_6 = F_3 ( V_3 ) -> V_6 ;
F_4 ( L_2 , V_4 , V_5 ) ;
if( ! V_5 ) return - 1 ;
while( 1 )
{
int V_7 ;
while ( ( ( V_7 = F_5 ( V_6 + V_8 ) ) & 0x100 ) == 0 ) ;
}
}
static inline int F_6 ( struct V_1 * V_3 , unsigned char * V_4 ,
int V_5 )
{
void T_1 * V_6 = F_3 ( V_3 ) -> V_6 ;
F_4 ( L_3 , V_4 , V_5 ) ;
while( V_5 > 0 )
{
unsigned int V_7 , V_9 ;
unsigned long V_10 ;
V_9 = 0x01FFFFFF ;
while ( ( ( V_7 = F_5 ( V_6 + V_8 ) ) & 0x100 ) == 0 )
{
V_9 -- ;
if( V_7 & 0x200 || ! V_9 )
{
F_4 ( L_4 , V_7 ) ;
return 1 ;
}
}
if( V_5 >= 128 )
{
F_7 ( V_6 + V_11 , V_4 , 128 ) ;
V_4 += 128 ;
V_5 -= 128 ;
}
else
{
V_10 = ( unsigned long ) F_5 ( V_6 + V_11 ) ;
* V_4 ++ = V_10 ;
V_5 -= 1 ;
if( V_5 )
* V_4 ++ = V_10 >> 8 ;
V_5 -= 1 ;
}
}
return 0 ;
}
static int F_8 ( struct V_12 * V_13 , const struct V_14 * V_15 )
{
struct V_1 * V_16 ;
int V_17 = - V_18 ;
V_17 = F_9 ( V_13 ) ;
if ( V_17 )
goto V_19;
V_16 = F_10 ( & V_20 , sizeof( struct V_21 ) ) ;
if ( ! V_16 ) {
V_17 = - V_18 ;
goto V_22;
}
F_3 ( V_16 ) -> V_6 = F_11 ( F_12 ( V_13 , V_23 ) ,
F_13 ( V_13 , V_23 ) ) ;
if ( ! F_3 ( V_16 ) -> V_6 ) {
V_17 = - V_18 ;
goto V_24;
}
V_16 -> V_25 = V_26 ;
V_16 -> V_27 = 255 ;
F_14 ( V_16 , 0 ) ;
F_4 ( L_5 ,
V_16 -> V_28 , V_16 -> V_29 ) ;
F_4 ( L_6 ,
V_16 -> V_30 , V_16 -> V_31 , V_32 ) ;
F_4 ( L_7 , V_16 -> V_28 ) ;
F_15 ( V_16 ) ;
F_4 ( L_8 ) ;
V_17 = F_16 ( V_16 , & V_13 -> V_33 ) ;
if ( V_17 )
goto V_34;
F_17 ( V_16 ) ;
goto V_19;
V_34:
F_18 ( F_3 ( V_16 ) -> V_6 ) ;
V_24:
F_19 ( V_16 ) ;
V_22:
F_20 ( V_13 ) ;
V_19:
return V_17 ;
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_1 * V_16 = F_22 ( V_13 ) ;
F_23 ( V_13 , NULL ) ;
F_24 ( V_16 ) ;
F_25 ( V_16 ) ;
F_18 ( F_3 ( V_16 ) -> V_6 ) ;
F_19 ( V_16 ) ;
F_20 ( V_13 ) ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_35 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_35 ) ;
}
