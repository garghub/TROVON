static char * F_1 ( T_1 * V_1 ,
T_2 * V_2 )
{
char * V_3 ;
if( ! V_2 || ! V_2 -> V_4 ) return NULL ;
V_3 = Malloc ( V_2 -> V_4 + 1 ) ;
memcpy ( V_3 , V_2 -> V_5 , V_2 -> V_4 ) ;
V_3 [ V_2 -> V_4 ] = 0 ;
return V_3 ;
}
static T_2 * F_2 ( T_1 * V_1 ,
T_3 * V_6 , char * V_7 )
{
T_2 * V_2 ;
if( ! V_7 ) {
F_3 ( V_8 , V_9 ) ;
return NULL ;
}
if( ! ( V_2 = F_4 () ) ) goto V_10;
if( ! F_5 ( ( V_11 * ) V_2 , ( unsigned char * ) V_7 ,
strlen ( V_7 ) ) ) {
F_6 ( V_2 ) ;
goto V_10;
}
#ifdef F_7
F_8 ( V_2 -> V_5 , V_2 -> V_5 , V_2 -> V_4 ) ;
#endif
return V_2 ;
V_10:
F_3 ( V_8 , V_12 ) ;
return NULL ;
}
