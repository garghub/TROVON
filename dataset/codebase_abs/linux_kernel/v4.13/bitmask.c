struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
V_3 = malloc ( sizeof( * V_3 ) ) ;
if ( V_3 == 0 )
return 0 ;
V_3 -> V_4 = V_2 ;
V_3 -> V_5 = calloc ( F_2 ( V_2 ) , sizeof( unsigned long ) ) ;
if ( V_3 -> V_5 == 0 ) {
free ( V_3 ) ;
return 0 ;
}
return V_3 ;
}
void F_3 ( struct V_1 * V_3 )
{
if ( V_3 == 0 )
return;
free ( V_3 -> V_5 ) ;
V_3 -> V_5 = ( unsigned long * ) 0xdeadcdef ;
free ( V_3 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_3 , unsigned int V_2 )
{
if ( V_2 < V_3 -> V_4 )
return ( V_3 -> V_5 [ V_2 / V_6 ] >> ( V_2 % V_6 ) ) & 1 ;
else
return 0 ;
}
static void F_5 ( struct V_1 * V_3 , unsigned int V_2 , unsigned int V_7 )
{
if ( V_2 < V_3 -> V_4 ) {
if ( V_7 )
V_3 -> V_5 [ V_2 / V_6 ] |= 1UL << ( V_2 % V_6 ) ;
else
V_3 -> V_5 [ V_2 / V_6 ] &=
~ ( 1UL << ( V_2 % V_6 ) ) ;
}
}
static int F_6 ( int V_8 , char V_9 , const char * V_10 )
{
return V_8 == 1 ||
( V_8 == 2 && strchr ( V_10 , V_9 ) != NULL ) ;
}
static const char * F_7 ( const char * V_11 , int V_12 )
{
if ( V_11 )
V_11 = strchr ( V_11 , V_12 ) ;
if ( V_11 )
V_11 ++ ;
return V_11 ;
}
struct V_1 * F_8 ( struct V_1 * V_3 , unsigned int V_13 )
{
F_5 ( V_3 , V_13 , 1 ) ;
return V_3 ;
}
struct V_1 * F_9 ( struct V_1 * V_3 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_4 ; V_13 ++ )
F_5 ( V_3 , V_13 , 1 ) ;
return V_3 ;
}
struct V_1 * F_10 ( struct V_1 * V_3 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_4 ; V_13 ++ )
F_5 ( V_3 , V_13 , 0 ) ;
return V_3 ;
}
int F_11 ( const struct V_1 * V_3 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_4 ; V_13 ++ )
if ( F_4 ( V_3 , V_13 ) )
return 0 ;
return 1 ;
}
int F_12 ( const struct V_1 * V_3 , unsigned int V_13 )
{
return F_4 ( V_3 , V_13 ) ;
}
unsigned int F_13 ( const struct V_1 * V_3 )
{
return F_14 ( V_3 , 0 ) ;
}
unsigned int F_15 ( const struct V_1 * V_3 )
{
unsigned int V_13 ;
unsigned int V_14 = V_3 -> V_4 ;
for ( V_13 = 0 ; V_13 < V_3 -> V_4 ; V_13 ++ )
if ( F_4 ( V_3 , V_13 ) )
V_14 = V_13 ;
return V_14 ;
}
unsigned int F_14 ( const struct V_1 * V_3 , unsigned int V_13 )
{
unsigned int V_2 ;
for ( V_2 = V_13 ; V_2 < V_3 -> V_4 ; V_2 ++ )
if ( F_4 ( V_3 , V_2 ) )
break;
return V_2 ;
}
int F_16 ( const char * V_15 , struct V_1 * V_3 )
{
const char * V_16 , * V_11 ;
F_10 ( V_3 ) ;
V_11 = V_15 ;
while ( V_16 = V_11 , V_11 = F_7 ( V_11 , ',' ) , V_16 ) {
unsigned int V_17 ;
unsigned int V_18 ;
unsigned int V_19 ;
const char * V_20 , * V_21 ;
char V_9 ;
int V_8 ;
V_8 = sscanf ( V_16 , L_1 , & V_17 , & V_9 ) ;
if ( ! F_6 ( V_8 , V_9 , L_2 ) )
goto V_22;
V_18 = V_17 ;
V_19 = 1 ;
V_20 = F_7 ( V_16 , '-' ) ;
V_21 = F_7 ( V_16 , ',' ) ;
if ( V_20 != NULL && ( V_21 == NULL || V_20 < V_21 ) ) {
V_8 = sscanf ( V_20 , L_1 , & V_18 , & V_9 ) ;
if ( ! F_6 ( V_8 , V_9 , L_3 ) )
goto V_22;
V_20 = F_7 ( V_20 , ':' ) ;
if ( V_20 != NULL && ( V_21 == NULL || V_20 < V_21 ) ) {
V_8 = sscanf ( V_20 , L_1 , & V_19 , & V_9 ) ;
if ( ! F_6 ( V_8 , V_9 , L_4 ) )
goto V_22;
}
}
if ( ! ( V_17 <= V_18 ) )
goto V_22;
if ( V_18 >= V_3 -> V_4 )
goto V_22;
while ( V_17 <= V_18 ) {
F_5 ( V_3 , V_17 , 1 ) ;
V_17 += V_19 ;
}
}
return 0 ;
V_22:
F_10 ( V_3 ) ;
return - 1 ;
}
static inline int F_17 ( char * V_15 , int V_23 , int V_24 , int V_25 , int V_26 )
{
if ( V_26 > 0 )
V_26 += snprintf ( V_15 + V_26 , F_18 ( V_23 - V_26 , 0 ) , L_4 ) ;
if ( V_24 == V_25 )
V_26 += snprintf ( V_15 + V_26 , F_18 ( V_23 - V_26 , 0 ) , L_5 , V_24 ) ;
else
V_26 += snprintf ( V_15 + V_26 , F_18 ( V_23 - V_26 , 0 ) , L_6 ,
V_24 , V_25 ) ;
return V_26 ;
}
int F_19 ( char * V_15 , int V_23 , const struct V_1 * V_3 )
{
int V_26 = 0 ;
unsigned int V_27 , V_24 , V_25 ;
if ( V_23 > 0 )
* V_15 = 0 ;
V_24 = V_27 = F_13 ( V_3 ) ;
while ( V_27 < V_3 -> V_4 ) {
V_25 = V_27 ;
V_27 = F_14 ( V_3 , V_27 + 1 ) ;
if ( V_27 >= V_3 -> V_4 || V_27 > V_25 + 1 ) {
V_26 = F_17 ( V_15 , V_23 , V_24 , V_25 , V_26 ) ;
V_24 = V_27 ;
}
}
return V_26 ;
}
