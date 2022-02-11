struct V_1 * F_1 ( struct V_2 * V_3 , const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
if ( ! strcmp ( V_6 [ V_5 ] . V_7 , V_4 ) )
return V_6 + V_5 ;
}
return F_3 ( - V_8 ) ;
}
void F_4 ( struct V_1 * V_1 )
{
}
int F_5 ( struct V_1 * V_1 )
{
unsigned V_4 = V_1 -> V_4 ;
unsigned V_9 = 1 ;
if ( V_1 -> V_10 == 0 )
V_1 -> V_11 = F_6 ( V_12 , & V_4 , & V_9 ) ;
if ( ( V_1 -> V_10 < V_13 ) && ( ! V_1 -> V_11 ) )
V_1 -> V_10 ++ ;
return V_1 -> V_11 ;
}
int F_7 ( struct V_1 * V_1 )
{
unsigned V_4 = V_1 -> V_4 ;
unsigned V_9 = 0 ;
if ( ! V_1 -> V_10 )
return 0 ;
if ( V_1 -> V_10 == 1 )
V_1 -> V_11 = F_6 ( V_12 , & V_4 , & V_9 ) ;
if ( ! V_1 -> V_11 )
V_1 -> V_10 -- ;
return V_1 -> V_11 ;
}
int F_8 ( struct V_1 * V_1 , unsigned V_14 )
{
unsigned V_4 = V_1 -> V_4 ;
V_1 -> V_11 = F_6 ( V_15 , & V_4 , & V_14 ) ;
return V_1 -> V_11 ;
}
static int F_9 ( void * V_16 , T_1 V_17 )
{
struct V_1 * V_1 = V_16 ;
switch ( V_17 ) {
case 0 :
F_7 ( V_1 ) ;
break;
case 1 :
F_5 ( V_1 ) ;
break;
default:
F_8 ( V_1 , V_17 ) ;
break;
}
return 0 ;
}
static int F_10 ( void * V_16 , T_1 * V_17 )
{
struct V_1 * V_1 = V_16 ;
if ( ! V_1 -> V_11 )
* V_17 = 0 ;
else
* V_17 = 1 ;
return 0 ;
}
static int F_11 ( void * V_16 , T_1 V_17 )
{
struct V_1 * V_1 = V_16 ;
if ( V_17 > V_13 )
V_17 = V_13 ;
V_1 -> V_10 = V_17 ;
return 0 ;
}
static int F_12 ( void * V_16 , T_1 * V_17 )
{
struct V_1 * V_1 = V_16 ;
* V_17 = V_1 -> V_10 ;
return 0 ;
}
static int T_2 F_13 ( void )
{
struct V_18 * V_19 ;
int V_5 ;
char V_7 [ 32 ] ;
const char * V_20 = L_1 ;
V_19 = F_14 ( L_2 , 0 ) ;
if ( F_15 ( V_19 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
( void ) F_16 ( V_6 [ V_5 ] . V_7 , 0644 ,
V_19 , V_6 + V_5 , & V_21 ) ;
F_17 ( V_7 , V_6 [ V_5 ] . V_7 , sizeof( V_7 ) ) ;
F_18 ( V_7 , V_20 , sizeof( V_7 ) ) ;
( void ) F_16 ( V_7 , 0644 ,
V_19 , V_6 + V_5 , & V_22 ) ;
}
return 0 ;
}
