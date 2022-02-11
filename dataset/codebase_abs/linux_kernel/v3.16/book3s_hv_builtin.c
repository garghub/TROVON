static inline int F_1 ( unsigned long V_1 )
{
switch ( V_1 ) {
case 32ul << 20 :
if ( F_2 ( V_2 ) )
return 8 ;
return - 1 ;
case 64ul << 20 :
return 3 ;
case 128ul << 20 :
return 7 ;
case 256ul << 20 :
return 4 ;
case 1ul << 30 :
return 2 ;
case 16ul << 30 :
return 1 ;
case 256ul << 30 :
return 0 ;
default:
return - 1 ;
}
}
static int T_1 F_3 ( char * V_3 )
{
unsigned long V_4 ;
F_4 ( L_1 , V_5 , V_3 ) ;
if ( ! V_3 )
return - V_6 ;
V_4 = F_5 ( V_3 , & V_3 ) ;
if ( F_1 ( V_4 ) < 0 ) {
F_6 ( L_2 , V_4 ) ;
return - V_6 ;
}
V_7 = V_4 >> V_8 ;
return 0 ;
}
struct V_9 * F_7 ()
{
struct V_10 * V_10 ;
struct V_9 * V_11 ;
V_11 = F_8 ( sizeof( struct V_9 ) , V_12 ) ;
if ( ! V_11 )
return NULL ;
V_10 = F_9 ( V_7 , V_7 ) ;
if ( ! V_10 )
goto V_13;
F_10 ( & V_11 -> V_14 , 1 ) ;
V_11 -> V_15 = F_11 ( V_10 ) ;
return V_11 ;
V_13:
F_12 ( V_11 ) ;
return NULL ;
}
void F_13 ( struct V_9 * V_11 )
{
if ( F_14 ( & V_11 -> V_14 ) ) {
F_15 ( F_16 ( V_11 -> V_15 ) , V_7 ) ;
F_12 ( V_11 ) ;
}
}
static int T_1 F_17 ( char * V_3 )
{
F_4 ( L_1 , V_5 , V_3 ) ;
if ( ! V_3 )
return - V_6 ;
return F_18 ( V_3 , 0 , & V_16 ) ;
}
struct V_10 * F_19 ( unsigned long V_17 )
{
unsigned long V_18 = V_19 ;
if ( ! F_2 ( V_2 ) )
V_18 = V_17 ;
return F_9 ( V_17 , V_18 ) ;
}
void F_20 ( struct V_10 * V_10 , unsigned long V_17 )
{
F_15 ( V_10 , V_17 ) ;
}
void T_1 F_21 ( void )
{
unsigned long V_20 ;
struct V_21 * V_22 ;
T_2 V_23 = 0 ;
F_22 (memory, reg)
V_23 += F_23 ( V_22 ) -
F_24 ( V_22 ) ;
V_23 = ( V_23 * V_16 / 100 ) << V_8 ;
if ( V_23 ) {
F_4 ( L_3 , V_5 ,
( unsigned long ) V_23 / V_24 ) ;
if ( ! F_2 ( V_2 ) )
V_20 = F_25 ( V_23 ) ;
else
V_20 = V_19 << V_8 ;
V_20 = F_26 ( V_7 << V_8 , V_20 ) ;
F_27 ( V_23 , V_20 ) ;
}
}
void F_28 ( void )
{
F_29 () ;
F_30 ( & V_25 ) ;
F_31 () ;
}
void F_32 ( void )
{
F_29 () ;
F_33 ( & V_25 ) ;
F_31 () ;
}
bool F_34 ( void )
{
return F_35 ( & V_25 ) != 0 ;
}
