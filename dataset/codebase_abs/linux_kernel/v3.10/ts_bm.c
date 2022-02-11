static unsigned int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 , V_8 , V_9 = V_4 -> V_10 ;
const T_1 * V_11 ;
int V_12 = V_6 -> V_13 - 1 , V_14 ;
const T_1 V_15 = V_2 -> V_16 & V_17 ;
for (; ; ) {
V_8 = V_2 -> V_18 ( V_9 , & V_11 , V_2 , V_4 ) ;
if ( F_3 ( V_8 == 0 ) )
break;
while ( V_12 < V_8 ) {
F_4 ( L_1 ,
V_12 , V_11 [ V_12 ] ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_13 ; V_7 ++ )
if ( ( V_15 ? toupper ( V_11 [ V_12 - V_7 ] )
: V_11 [ V_12 - V_7 ] )
!= V_6 -> V_19 [ V_6 -> V_13 - 1 - V_7 ] )
goto V_20;
F_4 ( L_2 ) ;
return V_9 += ( V_12 - ( V_6 -> V_13 - 1 ) ) ;
V_20: V_14 = V_6 -> V_21 [ V_11 [ V_12 - V_7 ] ] ;
V_12 = F_5 ( int , V_12 - V_7 + V_14 , V_12 + V_6 -> V_22 [ V_7 ] ) ;
}
V_9 += V_8 ;
}
return V_23 ;
}
static int F_6 ( T_1 * V_19 , int V_7 , int V_24 , int V_25 )
{
int V_26 = V_7 + V_25 - 1 , V_27 = V_24 + V_25 - 1 , V_28 = 0 ;
while( V_19 [ V_26 -- ] == V_19 [ V_27 -- ] ) {
if ( V_27 < 0 ) {
V_28 = 1 ;
break;
}
if ( -- V_25 == 0 ) {
V_28 = V_19 [ V_7 - 1 ] != V_19 [ V_24 - 1 ] ;
break;
}
}
return V_28 ;
}
static void F_7 ( struct V_5 * V_6 , int V_16 )
{
int V_7 , V_24 , V_25 ;
for ( V_7 = 0 ; V_7 < V_29 ; V_7 ++ )
V_6 -> V_21 [ V_7 ] = V_6 -> V_13 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_13 - 1 ; V_7 ++ ) {
V_6 -> V_21 [ V_6 -> V_19 [ V_7 ] ] = V_6 -> V_13 - 1 - V_7 ;
if ( V_16 & V_17 )
V_6 -> V_21 [ tolower ( V_6 -> V_19 [ V_7 ] ) ]
= V_6 -> V_13 - 1 - V_7 ;
}
V_6 -> V_22 [ 0 ] = 1 ;
for ( V_7 = 1 ; V_7 < V_6 -> V_13 ; V_7 ++ )
V_6 -> V_22 [ V_7 ] = V_6 -> V_13 ;
for ( V_7 = V_6 -> V_13 - 1 , V_25 = 1 ; V_7 > 0 ; V_25 ++ , V_7 -- ) {
for ( V_24 = V_7 - 1 ; V_24 >= 1 - V_25 ; V_24 -- )
if ( F_6 ( V_6 -> V_19 , V_7 , V_24 , V_25 ) ) {
V_6 -> V_22 [ V_25 ] = V_6 -> V_13 - V_24 - V_25 ;
break;
}
}
}
static struct V_1 * F_8 ( const void * V_19 , unsigned int V_30 ,
T_2 V_31 , int V_16 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_7 ;
unsigned int V_32 = V_30 * sizeof( unsigned int ) ;
T_3 V_33 = sizeof( * V_6 ) + V_30 + V_32 ;
V_2 = F_9 ( V_33 , V_31 ) ;
if ( F_10 ( V_2 ) )
return V_2 ;
V_2 -> V_16 = V_16 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_13 = V_30 ;
V_6 -> V_19 = ( T_1 * ) V_6 -> V_22 + V_32 ;
if ( V_16 & V_17 )
for ( V_7 = 0 ; V_7 < V_30 ; V_7 ++ )
V_6 -> V_19 [ V_7 ] = toupper ( ( ( T_1 * ) V_19 ) [ V_7 ] ) ;
else
memcpy ( V_6 -> V_19 , V_19 , V_30 ) ;
F_7 ( V_6 , V_16 ) ;
return V_2 ;
}
static void * F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_19 ;
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_13 ;
}
static int T_4 F_13 ( void )
{
return F_14 ( & V_34 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_34 ) ;
}
