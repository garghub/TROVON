static int F_1 ( int V_1 , int V_2 ,
void (* F_2) ( int V_1 , unsigned char V_3 ) ,
void (* F_3) ( int V_1 )
)
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
unsigned long V_6 ;
if ( V_4 == NULL )
return - V_7 ;
F_4 ( & V_4 -> V_8 , V_6 ) ;
if ( V_4 -> V_9 )
{
F_5 ( & V_4 -> V_8 , V_6 ) ;
return - V_10 ;
}
V_4 -> V_9 = 1 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = 0 ;
F_6 ( V_4 ) ;
if ( ! F_7 ( V_4 , 0x35 ) )
{
V_4 -> V_9 = 0 ;
return - V_14 ;
}
V_4 -> V_15 = 1 ;
if ( V_2 & V_16 )
{
V_4 -> V_17 = 1 ;
V_4 -> V_18 = F_2 ;
}
return 0 ;
}
static void F_8 ( int V_1 )
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
unsigned long V_6 ;
if ( V_4 == NULL )
return;
F_4 ( & V_4 -> V_8 , V_6 ) ;
F_6 ( V_4 ) ;
V_4 -> V_15 = 0 ;
V_4 -> V_17 = 0 ;
V_4 -> V_9 = 0 ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
}
static int F_9 ( int V_1 , unsigned char V_19 )
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
if ( V_4 == NULL )
return 1 ;
if ( V_4 -> V_13 )
return 1 ;
if ( ! F_7 ( V_4 , V_19 ) )
{
V_4 -> V_13 = 1 ;
return 1 ;
}
return 1 ;
}
static int F_10 ( int V_1 )
{
return 0 ;
}
static int F_11 ( int V_1 )
{
T_1 * V_4 = V_5 [ V_1 ] -> V_4 ;
if ( V_4 == NULL )
return - V_7 ;
F_6 ( V_4 ) ;
V_4 -> V_15 = 0 ;
return 0 ;
}
static int F_12 ( int V_1 , unsigned V_20 , void T_2 * V_21 )
{
return - V_22 ;
}
void F_13 ( T_1 * V_4 )
{
unsigned long V_6 ;
unsigned char V_3 ;
if ( V_4 == NULL )
return;
F_4 ( & V_4 -> V_8 , V_6 ) ;
V_3 = F_14 ( V_23 ) ;
if ( V_4 -> V_17 )
V_4 -> V_18 ( V_4 -> V_24 , V_3 ) ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
}
void F_15 ( T_1 * V_4 , struct V_25 * V_26 )
{
int V_1 ;
if ( V_4 -> V_27 < 2 )
return;
V_1 = F_16 () ;
if ( V_1 == - 1 )
{
F_17 ( V_28 L_1 ) ;
return;
}
V_29 . V_30 = V_4 -> V_24 = V_1 ;
V_5 [ V_1 ] = F_18 ( sizeof( struct V_31 ) , V_32 ) ;
if ( V_5 [ V_1 ] == NULL )
{
F_17 ( V_33 L_2 ) ;
F_19 ( V_1 ) ;
return;
}
memcpy ( ( char * ) V_5 [ V_1 ] , ( char * ) & V_34 ,
sizeof( struct V_31 ) ) ;
if ( V_26 )
V_5 [ V_1 ] -> V_26 = V_26 ;
V_5 [ V_1 ] -> V_4 = V_4 ;
V_5 [ V_1 ] -> V_35 = F_18 ( sizeof( struct V_36 ) , V_32 ) ;
if ( V_5 [ V_1 ] -> V_35 == NULL )
{
F_17 ( V_33 L_2 ) ;
F_20 ( V_5 [ V_1 ] ) ;
F_19 ( V_1 ) ;
return;
}
memcpy ( ( char * ) V_5 [ V_1 ] -> V_35 , ( char * ) & V_29 ,
sizeof( struct V_36 ) ) ;
V_5 [ V_1 ] -> V_35 -> V_37 = L_3 ;
F_21 () ;
}
