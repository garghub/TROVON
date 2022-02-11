T_1 F_1 ( struct V_1 * V_1 )
{
int V_2 = sizeof( * V_1 ) - F_2 ( struct V_1 , V_3 ) ;
return F_3 ( & V_1 -> V_3 , V_2 , 0 ) ;
}
void F_4 ( unsigned long V_4 , unsigned long V_2 )
{
V_1 . V_5 = ( V_6 ) ( unsigned long ) V_4 ;
V_1 . V_7 = ( V_6 ) ( unsigned long ) V_2 ;
V_1 . V_8 = F_1 ( & V_1 ) ;
}
void F_5 ( int V_9 , void * V_10 , V_6 V_2 )
{
V_1 . V_11 [ V_9 ] . V_12 = ( V_6 ) ( unsigned long ) V_10 ;
V_1 . V_11 [ V_9 ] . V_2 = V_2 ;
V_1 . V_11 [ V_9 ] . V_8 = F_3 ( V_10 , V_2 , 0 ) ;
V_1 . V_8 = F_1 ( & V_1 ) ;
}
void T_2 F_6 ( void )
{
void * V_10 = & V_1 ;
V_1 . V_3 = V_13 ;
V_1 . V_14 = V_15 ;
V_1 . V_16 = V_17 ;
V_1 . V_8 = F_1 ( & V_1 ) ;
F_7 ( V_18 . V_1 , ( unsigned long ) V_10 ) ;
}
static void F_8 ( int V_9 , int V_19 )
{
unsigned long V_12 , V_2 = 0 ;
char * V_20 , * V_21 , * V_22 ;
T_1 V_8 ;
V_12 = V_23 -> V_11 [ V_9 ] . V_12 ;
if ( ! V_12 ) {
V_22 = L_1 ;
goto V_24;
}
V_2 = V_23 -> V_11 [ V_9 ] . V_2 ;
V_20 = F_9 ( V_2 + V_19 - 1 , V_25 ) ;
if ( ! V_20 ) {
V_22 = L_2 ;
goto V_24;
}
V_21 = F_10 ( V_20 , V_19 ) ;
if ( F_11 ( V_21 , ( void * ) V_12 , V_2 ) ) {
V_22 = L_3 ;
goto V_26;
}
V_8 = F_3 ( V_21 , V_2 , 0 ) ;
if ( V_8 != V_23 -> V_11 [ V_9 ] . V_8 ) {
V_22 = L_4 ;
goto V_26;
}
V_23 -> V_11 [ V_9 ] . V_12 = ( V_6 ) ( unsigned long ) V_21 ;
V_22 = L_5 ;
goto V_27;
V_26:
F_12 ( V_20 ) ;
V_24:
V_23 -> V_11 [ V_9 ] . V_12 = 0 ;
V_27:
F_13 ( L_6 ,
V_9 , V_22 , V_12 , V_2 ) ;
}
static void F_14 ( void )
{
static int F_6 ;
unsigned long V_12 ;
if ( F_6 )
return;
if ( ! V_28 )
goto V_24;
if ( F_11 ( & V_12 , & V_18 . V_1 , sizeof( V_12 ) ) )
goto V_24;
if ( V_12 == 0 || V_12 % V_29 )
goto V_24;
V_23 = F_15 ( sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 )
goto V_24;
if ( F_11 ( V_23 , ( void * ) V_12 , sizeof( * V_23 ) ) )
goto V_26;
if ( V_23 -> V_16 != V_17 )
goto V_26;
if ( V_23 -> V_8 != F_1 ( V_23 ) )
goto V_26;
if ( V_23 -> V_3 > V_13 )
goto V_26;
F_8 ( V_30 , 1 ) ;
F_8 ( V_31 , 1 ) ;
F_13 ( L_7 ,
( unsigned long ) V_23 -> V_5 ,
( unsigned long ) V_23 -> V_7 ) ;
F_6 = 1 ;
return;
V_26:
F_12 ( V_23 ) ;
V_24:
F_6 = 1 ;
V_23 = NULL ;
}
void * F_16 ( int V_9 , unsigned long * V_2 )
{
F_14 () ;
if ( ! V_23 )
return NULL ;
if ( ! V_23 -> V_11 [ V_9 ] . V_12 )
return NULL ;
* V_2 = ( unsigned long ) V_23 -> V_11 [ V_9 ] . V_2 ;
return ( void * ) ( unsigned long ) V_23 -> V_11 [ V_9 ] . V_12 ;
}
