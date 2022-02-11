struct V_1 * F_1 ( const char * V_2 , T_1 V_3 )
{
struct V_1 * V_4 = malloc ( sizeof( * V_4 ) ) ;
if ( V_4 != NULL ) {
int V_5 ;
if ( V_6 <= 0 )
return V_4 ;
F_2 ( & V_5 , NULL ) ;
V_5 -= 4 ;
F_3 ( V_5 , 1 , V_2 ) ;
V_4 -> V_7 = F_4 ( NULL , NULL , 0 ) ;
if ( V_4 -> V_7 == NULL )
goto V_8;
V_4 -> V_9 = F_5 ( 0 , 0 , V_5 , V_3 ) ;
if ( V_4 -> V_9 == NULL )
goto V_10;
F_6 ( V_4 -> V_7 , V_4 -> V_9 ) ;
F_7 () ;
}
return V_4 ;
V_10:
F_8 ( V_4 -> V_7 ) ;
V_8:
free ( V_4 ) ;
return NULL ;
}
void F_9 ( struct V_1 * V_4 , T_1 V_11 )
{
if ( V_6 <= 0 )
return;
F_10 ( V_4 -> V_9 , V_11 ) ;
F_7 () ;
}
void F_11 ( struct V_1 * V_4 )
{
if ( V_6 > 0 ) {
F_8 ( V_4 -> V_7 ) ;
F_12 () ;
}
free ( V_4 ) ;
}
