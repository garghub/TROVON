void
F_1 ( char * V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
( * ( V_4 -> V_5 ) ) ( V_1 ) ;
F_3 () ;
F_4 ( & V_3 , V_2 ) ;
}
void
F_5 ( char * V_6 )
{
unsigned long V_2 ;
if( ! V_6 || V_6 [ 0 ] == 0 )
return;
F_2 ( & V_3 , V_2 ) ;
if( V_7 == V_8 )
( * ( V_4 -> V_9 . V_10 ) ) ( strlen ( V_6 ) , V_6 ) ;
else
( * ( V_4 -> V_9 . V_11 ) ) ( V_6 ) ;
F_3 () ;
F_4 ( & V_3 , V_2 ) ;
}
void
F_6 ( void )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
( * ( V_4 -> V_12 ) ) ( ) ;
F_3 () ;
F_4 ( & V_3 , V_2 ) ;
F_7 ( V_13 , 0 ) ;
}
void T_1
F_8 ( void )
{
unsigned long V_2 ;
V_14:
F_2 ( & V_3 , V_2 ) ;
( * ( V_4 -> V_15 ) ) ( ) ;
F_3 () ;
F_4 ( & V_3 , V_2 ) ;
goto V_14;
}
void
F_9 ( T_2 V_16 )
{
if( ! V_16 ) return;
* V_4 -> V_17 = V_16 ;
}
unsigned char
F_10 ( char * V_18 , int V_19 )
{
int V_20 ;
V_20 = F_11 ( V_21 , L_1 ) ;
if( ( V_20 > V_19 ) || ( V_20 == - 1 ) ) return 0xff ;
if( ! F_12 ( V_21 , L_1 , V_18 , V_19 ) )
return V_18 [ 0 ] ;
return 0xff ;
}
int
F_13 ( void )
{
return V_4 -> V_22 ;
}
int
F_14 ( void )
{
return V_23 ;
}
int
F_15 ( void )
{
return V_24 ;
}
