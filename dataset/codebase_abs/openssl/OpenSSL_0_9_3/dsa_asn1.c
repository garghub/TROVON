T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = Malloc ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_2 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 = NULL ;
V_1 -> V_5 = NULL ;
return ( V_1 ) ;
}
void F_3 ( T_1 * V_4 )
{
if ( V_4 == NULL ) return;
if ( V_4 -> V_4 ) F_4 ( V_4 -> V_4 ) ;
if ( V_4 -> V_5 ) F_4 ( V_4 -> V_5 ) ;
Free ( V_4 ) ;
}
int F_5 ( T_1 * V_6 , unsigned char * * V_7 )
{
int V_8 = 0 , V_9 ;
T_2 V_10 , V_11 ;
unsigned char * V_12 ;
V_10 . V_13 = Malloc ( F_6 ( V_6 -> V_4 ) / 8 + 1 ) ;
if ( V_10 . V_13 == NULL )
{
F_2 ( V_14 , V_3 ) ;
return ( 0 ) ;
}
V_10 . type = V_15 ;
V_10 . V_16 = F_7 ( V_6 -> V_4 , V_10 . V_13 ) ;
V_11 . V_13 = Malloc ( F_6 ( V_6 -> V_5 ) / 8 + 1 ) ;
if ( V_11 . V_13 == NULL )
{
Free ( V_10 . V_13 ) ;
F_2 ( V_14 , V_3 ) ;
return ( 0 ) ;
}
V_11 . type = V_15 ;
V_11 . V_16 = F_7 ( V_6 -> V_5 , V_11 . V_13 ) ;
V_9 = F_8 ( & V_10 , NULL ) ;
V_9 += F_8 ( & V_11 , NULL ) ;
if ( V_7 )
{
V_12 = * V_7 ;
F_9 ( & V_12 , 1 , V_9 , V_17 , V_18 ) ;
F_8 ( & V_10 , & V_12 ) ;
F_8 ( & V_11 , & V_12 ) ;
}
V_8 = F_10 ( 1 , V_9 , V_17 ) ;
Free ( V_10 . V_13 ) ;
Free ( V_11 . V_13 ) ;
return ( V_8 ) ;
}
T_1 * F_11 ( T_1 * * V_19 , unsigned char * * V_7 , long V_16 )
{
int V_20 = V_21 ;
T_2 * V_22 = NULL ;
F_12 ( V_19 , T_1 * , F_1 ) ;
F_13 () ;
F_14 () ;
F_15 ( V_22 , V_23 ) ;
if ( ( V_1 -> V_4 = F_16 ( V_22 -> V_13 , V_22 -> V_16 , V_1 -> V_4 ) ) == NULL )
goto V_24;
F_15 ( V_22 , V_23 ) ;
if ( ( V_1 -> V_5 = F_16 ( V_22 -> V_13 , V_22 -> V_16 , V_1 -> V_5 ) ) == NULL )
goto V_24;
F_17 ( V_22 ) ;
F_18 ( V_19 ) ;
V_24:
V_20 = V_25 ;
V_26:
F_2 ( V_27 , V_20 ) ;
if ( ( V_1 != NULL ) && ( ( V_19 == NULL ) || ( * V_19 != V_1 ) ) ) F_3 ( V_1 ) ;
if ( V_22 != NULL ) F_17 ( V_22 ) ;
return ( NULL ) ;
}
