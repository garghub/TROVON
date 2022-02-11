static char * F_1 ( T_1 * V_1 ,
T_2 * V_2 )
{
char * V_3 ;
if ( ! V_2 || ! V_2 -> V_4 )
return NULL ;
if ( ! ( V_3 = F_2 ( V_2 -> V_4 + 1 ) ) ) {
F_3 ( V_5 , V_6 ) ;
return NULL ;
}
memcpy ( V_3 , V_2 -> V_7 , V_2 -> V_4 ) ;
V_3 [ V_2 -> V_4 ] = 0 ;
return V_3 ;
}
static T_2 * F_4 ( T_1 * V_1 ,
T_3 * V_8 , char * V_9 )
{
T_2 * V_2 ;
if ( ! V_9 ) {
F_3 ( V_10 ,
V_11 ) ;
return NULL ;
}
if ( ! ( V_2 = F_5 () ) )
goto V_12;
if ( ! F_6 ( ( V_13 * ) V_2 , ( unsigned char * ) V_9 ,
strlen ( V_9 ) ) ) {
F_7 ( V_2 ) ;
goto V_12;
}
#ifdef F_8
F_9 ( V_2 -> V_7 , V_2 -> V_7 , V_2 -> V_4 ) ;
#endif
return V_2 ;
V_12:
F_3 ( V_10 , V_6 ) ;
return NULL ;
}
