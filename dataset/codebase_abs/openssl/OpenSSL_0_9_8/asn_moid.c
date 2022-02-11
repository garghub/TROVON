static int F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
int V_3 ;
const char * V_4 ;
F_2 ( V_5 ) * V_6 ;
V_5 * V_7 ;
V_4 = F_3 ( V_1 ) ;
if( ! ( V_6 = F_4 ( V_2 , V_4 ) ) )
{
F_5 ( V_8 , V_9 ) ;
return 0 ;
}
for( V_3 = 0 ; V_3 < F_6 ( V_6 ) ; V_3 ++ )
{
V_7 = F_7 ( V_6 , V_3 ) ;
if( ! F_8 ( V_7 -> V_10 , V_7 -> V_11 ) )
{
F_5 ( V_8 , V_12 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_9 ( T_1 * V_1 )
{
F_10 () ;
}
void F_11 ( void )
{
F_12 ( L_1 , F_1 , F_9 ) ;
}
static int F_8 ( char * V_10 , char * V_11 )
{
int V_13 ;
T_3 * V_14 ;
char * V_15 , * V_16 , * V_17 , * V_18 ;
V_17 = strrchr ( V_10 , ',' ) ;
if ( ! V_17 )
{
V_15 = V_11 ;
V_16 = V_10 ;
}
else
{
V_15 = NULL ;
V_16 = V_17 + 1 ;
if ( ! * V_16 )
return 0 ;
while( isspace ( ( unsigned char ) * V_16 ) ) V_16 ++ ;
}
V_13 = F_13 ( V_16 , V_11 , V_15 ) ;
if ( V_13 == V_19 )
return 0 ;
if ( V_17 )
{
V_15 = V_10 ;
while( isspace ( ( unsigned char ) * V_15 ) ) V_15 ++ ;
V_17 -- ;
while( isspace ( ( unsigned char ) * V_17 ) )
{
if ( V_17 == V_15 )
return 0 ;
V_17 -- ;
}
V_17 ++ ;
V_18 = F_14 ( ( V_17 - V_15 ) + 1 ) ;
if ( V_18 == NULL )
return 0 ;
memcpy ( V_18 , V_15 , V_17 - V_15 ) ;
V_18 [ V_17 - V_15 + 1 ] = 0 ;
V_14 = F_15 ( V_13 ) ;
V_14 -> V_15 = V_18 ;
}
return 1 ;
}
