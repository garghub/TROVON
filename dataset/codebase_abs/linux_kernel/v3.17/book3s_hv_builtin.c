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
V_10 = F_9 ( V_13 , V_7 , F_10 ( V_7 ) ) ;
if ( ! V_10 )
goto V_14;
F_11 ( & V_11 -> V_15 , 1 ) ;
V_11 -> V_16 = F_12 ( V_10 ) ;
return V_11 ;
V_14:
F_13 ( V_11 ) ;
return NULL ;
}
void F_14 ( struct V_9 * V_11 )
{
if ( F_15 ( & V_11 -> V_15 ) ) {
F_16 ( V_13 , F_17 ( V_11 -> V_16 ) , V_7 ) ;
F_13 ( V_11 ) ;
}
}
static int T_1 F_18 ( char * V_3 )
{
F_4 ( L_1 , V_5 , V_3 ) ;
if ( ! V_3 )
return - V_6 ;
return F_19 ( V_3 , 0 , & V_17 ) ;
}
struct V_10 * F_20 ( unsigned long V_18 )
{
unsigned long V_19 = V_20 ;
F_21 ( F_10 ( V_18 ) < V_21 - V_8 ) ;
if ( ! F_2 ( V_2 ) )
V_19 = V_18 ;
return F_9 ( V_13 , V_18 , F_10 ( V_19 ) ) ;
}
void F_22 ( struct V_10 * V_10 , unsigned long V_18 )
{
F_16 ( V_13 , V_10 , V_18 ) ;
}
void T_1 F_23 ( void )
{
unsigned long V_22 ;
struct V_23 * V_24 ;
T_2 V_25 = 0 ;
F_24 (memory, reg)
V_25 += F_25 ( V_24 ) -
F_26 ( V_24 ) ;
V_25 = ( V_25 * V_17 / 100 ) << V_8 ;
if ( V_25 ) {
F_4 ( L_3 , V_5 ,
( unsigned long ) V_25 / V_26 ) ;
if ( ! F_2 ( V_2 ) )
V_22 = F_27 ( V_25 ) ;
else
V_22 = V_20 << V_8 ;
V_22 = F_28 ( V_7 << V_8 , V_22 ) ;
F_29 ( 0 , V_25 , 0 , V_22 ,
V_21 - V_8 , false , & V_13 ) ;
}
}
void F_30 ( void )
{
F_31 () ;
F_32 ( & V_27 ) ;
F_33 () ;
}
void F_34 ( void )
{
F_31 () ;
F_35 ( & V_27 ) ;
F_33 () ;
}
bool F_36 ( void )
{
return F_37 ( & V_27 ) != 0 ;
}
int F_38 ( unsigned long V_28 )
{
V_28 /= 4 ;
if ( V_28 < V_29 - V_30 &&
V_30 [ V_28 ] )
return 1 ;
return 0 ;
}
