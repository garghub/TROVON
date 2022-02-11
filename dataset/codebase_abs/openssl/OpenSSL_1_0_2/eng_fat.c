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
#ifndef F_12
if ( ( V_2 & V_9 ) && ! F_13 ( V_1 ) )
return 0 ;
#endif
if ( ( V_2 & V_10 ) && ! F_14 ( V_1 ) )
return 0 ;
if ( ( V_2 & V_11 )
&& ! F_15 ( V_1 ) )
return 0 ;
if ( ( V_2 & V_12 )
&& ! F_16 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_17 ( const char * V_13 , int V_14 , void * V_15 )
{
unsigned int * V_16 = V_15 ;
if ( ! strncmp ( V_13 , L_1 , V_14 ) )
* V_16 |= V_17 ;
else if ( ! strncmp ( V_13 , L_2 , V_14 ) )
* V_16 |= V_5 ;
else if ( ! strncmp ( V_13 , L_3 , V_14 ) )
* V_16 |= V_6 ;
else if ( ! strncmp ( V_13 , L_4 , V_14 ) )
* V_16 |= V_8 ;
else if ( ! strncmp ( V_13 , L_5 , V_14 ) )
* V_16 |= V_9 ;
else if ( ! strncmp ( V_13 , L_6 , V_14 ) )
* V_16 |= V_7 ;
else if ( ! strncmp ( V_13 , L_7 , V_14 ) )
* V_16 |= V_10 ;
else if ( ! strncmp ( V_13 , L_8 , V_14 ) )
* V_16 |= V_3 ;
else if ( ! strncmp ( V_13 , L_9 , V_14 ) )
* V_16 |= V_4 ;
else if ( ! strncmp ( V_13 , L_10 , V_14 ) )
* V_16 |= V_11 | V_12 ;
else if ( ! strncmp ( V_13 , L_11 , V_14 ) )
* V_16 |= V_11 ;
else if ( ! strncmp ( V_13 , L_12 , V_14 ) )
* V_16 |= V_12 ;
else
return 0 ;
return 1 ;
}
int F_18 ( T_1 * V_1 , const char * V_18 )
{
unsigned int V_2 = 0 ;
if ( ! F_19 ( V_18 , ',' , 1 , F_17 , & V_2 ) ) {
F_20 ( V_19 ,
V_20 ) ;
F_21 ( 2 , L_13 , V_18 ) ;
return 0 ;
}
return F_1 ( V_1 , V_2 ) ;
}
int F_22 ( T_1 * V_1 )
{
F_23 ( V_1 ) ;
F_24 ( V_1 ) ;
#ifndef F_4
F_25 ( V_1 ) ;
#endif
#ifndef F_6
F_26 ( V_1 ) ;
#endif
#ifndef F_8
F_27 ( V_1 ) ;
#endif
#ifndef F_10
F_28 ( V_1 ) ;
#endif
#ifndef F_12
F_29 ( V_1 ) ;
#endif
F_30 ( V_1 ) ;
F_31 ( V_1 ) ;
return 1 ;
}
int F_32 ( void )
{
T_1 * V_1 ;
for ( V_1 = F_33 () ; V_1 ; V_1 = F_34 ( V_1 ) )
if ( ! ( V_1 -> V_2 & V_21 ) )
F_22 ( V_1 ) ;
return 1 ;
}
