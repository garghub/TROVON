int F_1 ( T_1 * V_1 , unsigned int V_2 )
{
if ( ( V_2 & V_3 ) && ! F_2 ( V_1 ) )
return 0 ;
if ( ( V_2 & V_4 ) && ! F_3 ( V_1 ) )
return 0 ;
#ifndef F_4
if ( ( V_2 & V_5 ) && ! F_5 ( V_1 ) )
return 0 ;
#endif
#ifndef F_6
if ( ( V_2 & V_6 ) && ! F_7 ( V_1 ) )
return 0 ;
#endif
#ifndef F_8
if ( ( V_2 & V_7 ) && ! F_9 ( V_1 ) )
return 0 ;
#endif
#ifndef F_10
if ( ( V_2 & V_8 ) && ! F_11 ( V_1 ) )
return 0 ;
#endif
if ( ( V_2 & V_9 ) && ! F_12 ( V_1 ) )
return 0 ;
if ( ( V_2 & V_10 )
&& ! F_13 ( V_1 ) )
return 0 ;
if ( ( V_2 & V_11 )
&& ! F_14 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_15 ( const char * V_12 , int V_13 , void * V_14 )
{
unsigned int * V_15 = V_14 ;
if ( V_12 == NULL )
return 0 ;
if ( strncmp ( V_12 , L_1 , V_13 ) == 0 )
* V_15 |= V_16 ;
else if ( strncmp ( V_12 , L_2 , V_13 ) == 0 )
* V_15 |= V_5 ;
else if ( strncmp ( V_12 , L_3 , V_13 ) == 0 )
* V_15 |= V_6 ;
else if ( strncmp ( V_12 , L_4 , V_13 ) == 0 )
* V_15 |= V_7 ;
else if ( strncmp ( V_12 , L_5 , V_13 ) == 0 )
* V_15 |= V_8 ;
else if ( strncmp ( V_12 , L_6 , V_13 ) == 0 )
* V_15 |= V_9 ;
else if ( strncmp ( V_12 , L_7 , V_13 ) == 0 )
* V_15 |= V_3 ;
else if ( strncmp ( V_12 , L_8 , V_13 ) == 0 )
* V_15 |= V_4 ;
else if ( strncmp ( V_12 , L_9 , V_13 ) == 0 )
* V_15 |= V_10 | V_11 ;
else if ( strncmp ( V_12 , L_10 , V_13 ) == 0 )
* V_15 |= V_10 ;
else if ( strncmp ( V_12 , L_11 , V_13 ) == 0 )
* V_15 |= V_11 ;
else
return 0 ;
return 1 ;
}
int F_16 ( T_1 * V_1 , const char * V_17 )
{
unsigned int V_2 = 0 ;
if ( ! F_17 ( V_17 , ',' , 1 , F_15 , & V_2 ) ) {
F_18 ( V_18 ,
V_19 ) ;
F_19 ( 2 , L_12 , V_17 ) ;
return 0 ;
}
return F_1 ( V_1 , V_2 ) ;
}
int F_20 ( T_1 * V_1 )
{
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
#ifndef F_4
F_23 ( V_1 ) ;
#endif
#ifndef F_6
F_24 ( V_1 ) ;
#endif
#ifndef F_8
F_25 ( V_1 ) ;
#endif
#ifndef F_10
F_26 ( V_1 ) ;
#endif
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
return 1 ;
}
int F_29 ( void )
{
T_1 * V_1 ;
for ( V_1 = F_30 () ; V_1 ; V_1 = F_31 ( V_1 ) )
if ( ! ( V_1 -> V_2 & V_20 ) )
F_20 ( V_1 ) ;
return 1 ;
}
