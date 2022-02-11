T_1 F_1 ( struct V_1 * V_1 )
{
int V_2 = sizeof( * V_1 ) - F_2 ( struct V_1 , V_3 ) ;
return ( V_4 T_1 ) F_3 ( & V_1 -> V_3 , V_2 , 0 ) ;
}
void F_4 ( unsigned long V_5 , unsigned long V_2 )
{
V_1 . V_6 = ( V_7 ) ( unsigned long ) V_5 ;
V_1 . V_8 = ( V_7 ) ( unsigned long ) V_2 ;
V_1 . V_9 = F_1 ( & V_1 ) ;
}
void F_5 ( int V_10 , void * V_11 , V_7 V_2 )
{
V_1 . V_12 [ V_10 ] . V_13 = ( V_7 ) ( unsigned long ) V_11 ;
V_1 . V_12 [ V_10 ] . V_2 = V_2 ;
V_1 . V_12 [ V_10 ] . V_9 = ( V_4 T_1 ) F_3 ( V_11 , V_2 , 0 ) ;
V_1 . V_9 = F_1 ( & V_1 ) ;
}
void T_2 F_6 ( void )
{
void * V_11 = & V_1 ;
V_1 . V_3 = V_14 ;
V_1 . V_15 = V_16 ;
V_1 . V_17 = V_18 ;
V_1 . V_9 = F_1 ( & V_1 ) ;
F_7 ( V_19 . V_1 , ( unsigned long ) V_11 ) ;
}
static void F_8 ( int V_10 , int V_20 )
{
unsigned long V_13 , V_2 = 0 ;
char * V_21 , * V_22 , * V_23 ;
T_1 V_9 ;
V_13 = V_24 -> V_12 [ V_10 ] . V_13 ;
if ( ! V_13 ) {
V_23 = L_1 ;
goto V_25;
}
V_2 = V_24 -> V_12 [ V_10 ] . V_2 ;
V_21 = F_9 ( V_2 + V_20 - 1 , V_26 ) ;
if ( ! V_21 ) {
V_23 = L_2 ;
goto V_25;
}
V_22 = F_10 ( V_21 , V_20 ) ;
if ( F_11 ( V_22 , ( void * ) V_13 , V_2 ) ) {
V_23 = L_3 ;
goto V_27;
}
V_9 = ( V_4 T_1 ) F_3 ( V_22 , V_2 , 0 ) ;
if ( V_9 != V_24 -> V_12 [ V_10 ] . V_9 ) {
V_23 = L_4 ;
goto V_27;
}
V_24 -> V_12 [ V_10 ] . V_13 = ( V_7 ) ( unsigned long ) V_22 ;
V_23 = L_5 ;
goto V_28;
V_27:
F_12 ( V_21 ) ;
V_25:
V_24 -> V_12 [ V_10 ] . V_13 = 0 ;
V_28:
F_13 ( L_6 ,
V_10 , V_23 , V_13 , V_2 ) ;
}
static void F_14 ( void )
{
static int F_6 ;
unsigned long V_13 ;
if ( F_6 )
return;
if ( ! V_29 )
goto V_25;
if ( F_11 ( & V_13 , & V_19 . V_1 , sizeof( V_13 ) ) )
goto V_25;
if ( V_13 == 0 || V_13 % V_30 )
goto V_25;
V_24 = F_15 ( sizeof( * V_24 ) , V_26 ) ;
if ( ! V_24 )
goto V_25;
if ( F_11 ( V_24 , ( void * ) V_13 ,
sizeof( * V_24 ) ) )
goto V_27;
if ( V_24 -> V_17 != V_18 )
goto V_27;
if ( V_24 -> V_9 != F_1 ( V_24 ) )
goto V_27;
if ( V_24 -> V_3 > V_14 )
goto V_27;
F_8 ( V_31 , 1 ) ;
F_8 ( V_32 , 1 ) ;
F_13 ( L_7 ,
( unsigned long ) V_24 -> V_6 ,
( unsigned long ) V_24 -> V_8 ) ;
F_6 = 1 ;
return;
V_27:
F_12 ( V_24 ) ;
V_25:
F_6 = 1 ;
V_24 = NULL ;
}
void * F_16 ( int V_10 , unsigned long * V_2 )
{
F_14 () ;
if ( ! V_24 )
return NULL ;
if ( ! V_24 -> V_12 [ V_10 ] . V_13 )
return NULL ;
* V_2 = ( unsigned long ) V_24 -> V_12 [ V_10 ] . V_2 ;
return ( void * ) ( unsigned long ) V_24 -> V_12 [ V_10 ] . V_13 ;
}
