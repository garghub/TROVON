static void F_1 ( unsigned int V_1 )
{
unsigned V_2 ;
V_2 = F_2 () ;
F_3 ( 1 ) ;
F_4 ( ( F_5 () & ~ V_3 ) | V_1 ) ;
F_3 ( V_2 ) ;
}
static unsigned int F_6 ( unsigned int V_4 )
{
int V_5 ;
if ( ! V_6 )
goto V_7;
V_4 >>= 16 ;
for ( V_5 = 0 ; V_5 < V_6 -> V_8 ; V_5 ++ )
if ( V_4 <= ( V_6 -> V_9 [ V_5 ] & 0xFFFF ) )
return V_6 -> V_9 [ V_5 ] >> 16 ;
V_7:
F_7 ( V_10 L_1 ) ;
return V_11 ;
}
static void F_8 ( void * V_12 )
{
unsigned long V_13 = 0 ;
unsigned long V_14 , V_15 , V_16 ;
unsigned int V_17 = F_9 () ;
F_10 ( V_13 ) ;
F_11 ( & V_14 , & V_15 , & V_16 ) ;
F_12 ( V_17 , V_18 ) ;
F_13 () ;
asm("IDLE;");
F_14 ( V_14 , V_15 , V_16 ) ;
F_15 ( V_13 ) ;
}
static void F_16 ( void )
{
F_17 ( F_8 , NULL , 0 ) ;
}
static void F_18 ( void )
{
unsigned int V_17 ;
unsigned int V_19 = F_9 () ;
T_1 V_20 ;
F_19 ( & V_20 , V_21 ) ;
F_20 ( V_19 , & V_20 ) ;
F_21 (cpu, &mask)
F_22 ( V_17 , V_18 ) ;
}
static void F_16 ( void ) {}
static void F_18 ( void ) {}
static int
F_23 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
struct V_26 * V_4 = V_25 ;
if ( V_4 -> V_17 != V_27 )
return 0 ;
if ( V_24 == V_28 && V_4 -> V_29 < V_4 -> V_30 ) {
F_16 () ;
F_1 ( F_6 ( V_4 -> V_30 ) ) ;
F_24 ( V_6 -> V_31 ) ;
F_18 () ;
} else if ( V_24 == V_32 && V_4 -> V_29 > V_4 -> V_30 ) {
F_16 () ;
F_1 ( F_6 ( V_4 -> V_30 ) ) ;
F_18 () ;
}
return 0 ;
}
static int F_25 ( struct V_33 * V_34 )
{
if ( V_34 -> V_35 . V_36 )
V_6 = V_34 -> V_35 . V_36 ;
else
return - V_37 ;
return F_26 ( & V_38 ,
V_39 ) ;
}
static int F_27 ( struct V_33 * V_34 )
{
V_6 = NULL ;
return F_28 ( & V_38 ,
V_39 ) ;
}
