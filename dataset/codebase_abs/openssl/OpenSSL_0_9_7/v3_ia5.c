static char * F_1 ( T_1 * V_1 ,
T_2 * V_2 )
{
char * V_3 ;
if( ! V_2 || ! V_2 -> V_4 ) return NULL ;
if ( ! ( V_3 = F_2 ( V_2 -> V_4 + 1 ) ) ) return NULL ;
memcpy ( V_3 , V_2 -> V_5 , V_2 -> V_4 ) ;
V_3 [ V_2 -> V_4 ] = 0 ;
return V_3 ;
}
static T_2 * F_3 ( T_1 * V_1 ,
T_3 * V_6 , char * V_7 )
{
T_2 * V_2 ;
if( ! V_7 ) {
F_4 ( V_8 , V_9 ) ;
return NULL ;
}
if( ! ( V_2 = F_5 () ) ) goto V_10;
if( ! F_6 ( ( V_11 * ) V_2 , ( unsigned char * ) V_7 ,
strlen ( V_7 ) ) ) {
F_7 ( V_2 ) ;
goto V_10;
}
#ifdef F_8
F_9 ( V_2 -> V_5 , V_2 -> V_5 , V_2 -> V_4 ) ;
#endif
return V_2 ;
V_10:
F_4 ( V_8 , V_12 ) ;
return NULL ;
}
