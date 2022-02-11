T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_3 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
return ( V_1 ) ;
}
void F_4 ( T_1 * V_4 )
{
if ( V_4 == NULL ) return;
if ( V_4 -> V_4 ) F_5 ( V_4 -> V_4 ) ;
if ( V_4 -> V_5 ) F_5 ( V_4 -> V_5 ) ;
F_6 ( V_4 ) ;
}
int F_7 ( T_1 * V_6 , unsigned char * * V_7 )
{
int V_8 = 0 , V_9 ;
T_2 V_10 , V_11 ;
unsigned char * V_12 ;
V_10 . V_13 = F_2 ( F_8 ( V_6 -> V_4 ) / 8 + 1 ) ;
if ( V_10 . V_13 == NULL )
{
F_3 ( V_14 , V_3 ) ;
return ( 0 ) ;
}
V_10 . type = V_15 ;
V_10 . V_16 = F_9 ( V_6 -> V_4 , V_10 . V_13 ) ;
V_11 . V_13 = F_2 ( F_8 ( V_6 -> V_5 ) / 8 + 1 ) ;
if ( V_11 . V_13 == NULL )
{
F_6 ( V_10 . V_13 ) ;
F_3 ( V_14 , V_3 ) ;
return ( 0 ) ;
}
V_11 . type = V_15 ;
V_11 . V_16 = F_9 ( V_6 -> V_5 , V_11 . V_13 ) ;
V_9 = F_10 ( & V_10 , NULL ) ;
V_9 += F_10 ( & V_11 , NULL ) ;
if ( V_7 )
{
V_12 = * V_7 ;
F_11 ( & V_12 , 1 , V_9 , V_17 , V_18 ) ;
F_10 ( & V_10 , & V_12 ) ;
F_10 ( & V_11 , & V_12 ) ;
}
V_8 = F_12 ( 1 , V_9 , V_17 ) ;
F_6 ( V_10 . V_13 ) ;
F_6 ( V_11 . V_13 ) ;
return ( V_8 ) ;
}
T_1 * F_13 ( T_1 * * V_19 , unsigned char * * V_7 , long V_16 )
{
int V_20 = V_21 ;
T_2 * V_22 = NULL ;
F_14 ( V_19 , T_1 * , F_1 ) ;
F_15 () ;
F_16 () ;
F_17 ( V_22 , V_23 ) ;
if ( ( V_1 -> V_4 = F_18 ( V_22 -> V_13 , V_22 -> V_16 , V_1 -> V_4 ) ) == NULL )
goto V_24;
F_17 ( V_22 , V_23 ) ;
if ( ( V_1 -> V_5 = F_18 ( V_22 -> V_13 , V_22 -> V_16 , V_1 -> V_5 ) ) == NULL )
goto V_24;
F_19 ( V_22 ) ;
F_20 ( V_19 ) ;
V_24:
V_20 = V_25 ;
V_26:
F_3 ( V_27 , V_20 ) ;
if ( ( V_1 != NULL ) && ( ( V_19 == NULL ) || ( * V_19 != V_1 ) ) ) F_4 ( V_1 ) ;
if ( V_22 != NULL ) F_19 ( V_22 ) ;
return ( NULL ) ;
}
