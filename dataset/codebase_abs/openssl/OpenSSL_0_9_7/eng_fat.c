int F_1 ( T_1 * V_1 , unsigned int V_2 )
{
if( ( V_2 & V_3 ) && ! F_2 ( V_1 ) )
return 0 ;
if( ( V_2 & V_4 ) && ! F_3 ( V_1 ) )
return 0 ;
#ifndef F_4
if( ( V_2 & V_5 ) & ! F_5 ( V_1 ) )
return 0 ;
#endif
#ifndef F_6
if( ( V_2 & V_6 ) & ! F_7 ( V_1 ) )
return 0 ;
#endif
#ifndef F_8
if( ( V_2 & V_7 ) & ! F_9 ( V_1 ) )
return 0 ;
#endif
if( ( V_2 & V_8 ) & ! F_10 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_11 ( const char * V_9 , int V_10 , void * V_11 )
{
unsigned int * V_12 = V_11 ;
if ( ! strncmp ( V_9 , L_1 , V_10 ) )
* V_12 |= V_13 ;
else if ( ! strncmp ( V_9 , L_2 , V_10 ) )
* V_12 |= V_5 ;
else if ( ! strncmp ( V_9 , L_3 , V_10 ) )
* V_12 |= V_6 ;
else if ( ! strncmp ( V_9 , L_4 , V_10 ) )
* V_12 |= V_7 ;
else if ( ! strncmp ( V_9 , L_5 , V_10 ) )
* V_12 |= V_8 ;
else if ( ! strncmp ( V_9 , L_6 , V_10 ) )
* V_12 |= V_3 ;
else if ( ! strncmp ( V_9 , L_7 , V_10 ) )
* V_12 |= V_4 ;
else
return 0 ;
return 1 ;
}
int F_12 ( T_1 * V_1 , const char * V_14 )
{
unsigned int V_2 = 0 ;
if ( ! F_13 ( V_14 , ',' , 1 , F_11 , & V_2 ) )
{
F_14 ( V_15 ,
V_16 ) ;
F_15 ( 2 , L_8 , V_14 ) ;
return 0 ;
}
return F_1 ( V_1 , V_2 ) ;
}
int F_16 ( T_1 * V_1 )
{
F_17 ( V_1 ) ;
F_18 ( V_1 ) ;
#ifndef F_4
F_19 ( V_1 ) ;
#endif
#ifndef F_6
F_20 ( V_1 ) ;
#endif
#ifndef F_8
F_21 ( V_1 ) ;
#endif
F_22 ( V_1 ) ;
return 1 ;
}
int F_23 ( void )
{
T_1 * V_1 ;
for( V_1 = F_24 () ; V_1 ; V_1 = F_25 ( V_1 ) )
F_16 ( V_1 ) ;
return 1 ;
}
