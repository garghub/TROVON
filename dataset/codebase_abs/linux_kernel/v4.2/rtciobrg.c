void F_1 ( void )
{
while ( F_2 ( V_1 + V_2 ) )
F_3 () ;
}
void F_4 ( void )
{
unsigned long V_3 ;
F_5 ( & V_4 , V_3 ) ;
F_1 () ;
F_6 ( & V_4 , V_3 ) ;
}
T_1 F_7 ( T_1 V_5 )
{
F_1 () ;
F_8 ( 0x00 , V_1 + V_6 ) ;
F_8 ( V_5 , V_1 + V_7 ) ;
F_8 ( 0x01 , V_1 + V_2 ) ;
F_1 () ;
return F_2 ( V_1 + V_8 ) ;
}
T_1 F_9 ( T_1 V_5 )
{
unsigned long V_3 , V_9 ;
F_5 ( & V_4 , V_3 ) ;
V_9 = F_7 ( V_5 ) ;
F_6 ( & V_4 , V_3 ) ;
return V_9 ;
}
void F_10 ( T_1 V_9 , T_1 V_5 )
{
F_1 () ;
F_8 ( 0xf1 , V_1 + V_6 ) ;
F_8 ( V_5 , V_1 + V_7 ) ;
F_8 ( V_9 , V_1 + V_8 ) ;
}
void F_11 ( T_1 V_9 , T_1 V_5 )
{
unsigned long V_3 ;
F_5 ( & V_4 , V_3 ) ;
F_10 ( V_9 , V_5 ) ;
F_8 ( 0x01 , V_1 + V_2 ) ;
F_1 () ;
F_6 ( & V_4 , V_3 ) ;
}
static int F_12 ( void * V_10 , unsigned int V_11 ,
unsigned int V_9 )
{
F_11 ( V_9 , V_11 ) ;
return 0 ;
}
static int F_13 ( void * V_10 , unsigned int V_11 ,
unsigned int * V_9 )
{
* V_9 = ( T_1 ) F_9 ( V_11 ) ;
return 0 ;
}
struct V_12 * F_14 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
const struct V_17 * V_18 = & V_19 ;
return F_15 ( V_14 , V_18 , V_14 , V_16 ) ;
}
static int F_16 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_14 . V_24 ;
V_1 = F_17 ( V_23 , 0 ) ;
if ( ! V_1 )
F_18 ( L_1 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_25 ) ;
}
