int F_1 ( void )
{
unsigned long V_1 ;
T_1 V_2 = F_2 () ;
#if F_3 ( V_3 ) || F_3 ( V_4 )
unsigned char V_5 [ V_6 ] ;
int V_7 = 0 ;
#endif
#ifdef V_3
static const char * V_8 [] = { V_3 , NULL } ;
const char * * V_9 = NULL ;
int V_10 ;
#endif
#ifdef V_4
static const char * V_11 [] = { V_4 , NULL } ;
const char * * V_12 = NULL ;
#endif
#ifdef V_3
for ( V_9 = V_8 ; * V_9 && V_7 < V_6 ; V_9 ++ )
{
if ( ( V_10 = F_4 ( * V_9 , V_13 | V_14
#ifdef F_5
| F_5
#endif
#ifdef F_6
| F_6
#endif
) ) >= 0 )
{
struct V_15 V_16 = { 0 , 10 * 1000 } ;
int V_17 ;
T_2 V_18 ;
do
{
F_7 ( & V_18 ) ;
F_8 ( V_10 , & V_18 ) ;
V_17 = - 1 ;
if ( F_9 ( V_10 + 1 , & V_18 , NULL , NULL , & V_16 ) < 0 )
V_16 . V_19 = 0 ;
else if ( F_10 ( V_10 , & V_18 ) )
{
V_17 = F_11 ( V_10 , ( unsigned char * ) V_5 + V_7 ,
V_6 - V_7 ) ;
if ( V_17 > 0 )
V_7 += V_17 ;
}
if ( V_16 . V_19 == 10 * 1000 )
V_16 . V_19 = 0 ;
}
while ( ( V_17 > 0 || ( V_20 == V_21 || V_20 == V_22 ) )
&& V_16 . V_19 != 0 && V_7 < V_6 );
F_12 ( V_10 ) ;
}
}
#endif
#ifdef V_4
for ( V_12 = V_11 ; * V_12 && V_7 < V_6 ; V_12 ++ )
{
int V_17 ;
V_17 = F_13 ( * V_12 , ( unsigned char * ) V_5 + V_7 ,
V_6 - V_7 ) ;
if ( V_17 > 0 )
V_7 += V_17 ;
}
#endif
#if F_3 ( V_3 ) || F_3 ( V_4 )
if ( V_7 > 0 )
{
F_14 ( V_5 , sizeof V_5 , V_7 ) ;
F_15 ( V_5 , V_7 ) ;
}
#endif
V_1 = V_2 ;
F_14 ( & V_1 , sizeof( V_1 ) , 0 ) ;
V_1 = F_16 () ;
F_14 ( & V_1 , sizeof( V_1 ) , 0 ) ;
V_1 = time ( NULL ) ;
F_14 ( & V_1 , sizeof( V_1 ) , 0 ) ;
#if F_3 ( V_3 ) || F_3 ( V_4 )
return 1 ;
#else
return 0 ;
#endif
}
int F_1 ( void )
{
return 0 ;
}
