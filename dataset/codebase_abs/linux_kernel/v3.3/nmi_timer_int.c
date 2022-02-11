static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_2 -> V_7 . V_8 = 0 ;
F_2 ( V_6 , 0 ) ;
}
static int F_3 ( int V_9 )
{
struct V_1 * V_2 = F_4 ( V_10 , V_9 ) ;
if ( ! V_2 ) {
V_2 = F_5 ( & V_11 , V_9 , NULL ,
F_1 , NULL ) ;
if ( F_6 ( V_2 ) )
return F_7 ( V_2 ) ;
F_4 ( V_10 , V_9 ) = V_2 ;
}
if ( V_2 && V_12 )
F_8 ( V_2 ) ;
return 0 ;
}
static void F_9 ( int V_9 )
{
struct V_1 * V_2 = F_4 ( V_10 , V_9 ) ;
if ( V_2 && V_12 )
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_13 * V_14 , unsigned long V_15 ,
void * V_4 )
{
int V_9 = ( unsigned long ) V_4 ;
switch ( V_15 ) {
case V_16 :
case V_17 :
F_3 ( V_9 ) ;
break;
case V_18 :
F_9 ( V_9 ) ;
break;
}
return V_19 ;
}
static int F_12 ( void )
{
int V_9 ;
F_13 () ;
V_12 = 1 ;
F_14 (cpu)
F_3 ( V_9 ) ;
F_15 () ;
return 0 ;
}
static void F_16 ( void )
{
int V_9 ;
F_13 () ;
F_14 (cpu)
F_9 ( V_9 ) ;
V_12 = 0 ;
F_15 () ;
}
static void F_17 ( void )
{
struct V_1 * V_2 ;
int V_9 ;
F_13 () ;
F_18 ( & V_20 ) ;
F_19 (cpu) {
V_2 = F_4 ( V_10 , V_9 ) ;
if ( ! V_2 )
continue;
F_10 ( V_2 ) ;
F_4 ( V_10 , V_9 ) = NULL ;
F_20 ( V_2 ) ;
}
F_15 () ;
}
static int F_21 ( void )
{
int V_9 , V_21 ;
T_1 V_22 ;
V_22 = ( T_1 ) V_23 * 1000 ;
F_22 ( V_22 , V_24 ) ;
V_11 . V_25 = V_22 ;
F_13 () ;
V_21 = F_23 ( & V_20 ) ;
if ( V_21 )
goto V_26;
F_14 (cpu) {
V_21 = F_3 ( V_9 ) ;
if ( V_21 )
break;
}
if ( V_21 )
F_17 () ;
V_26:
F_15 () ;
return V_21 ;
}
int T_2 F_24 ( struct V_27 * V_28 )
{
int V_21 = 0 ;
V_21 = F_21 () ;
if ( V_21 )
return V_21 ;
F_17 () ;
V_28 -> V_29 = NULL ;
V_28 -> V_30 = F_21 ;
V_28 -> V_31 = F_17 ;
V_28 -> V_32 = F_12 ;
V_28 -> V_33 = F_16 ;
V_28 -> V_34 = L_1 ;
F_25 ( V_35 L_2 ) ;
return 0 ;
}
