static int F_1 ( void * V_1 , T_1 V_2 )
{
T_1 V_3 = V_2 ;
return F_2 ( V_1 , & V_3 , 1 ) ;
}
static int F_3 ( void * V_1 , T_1 V_4 , T_1 V_2 )
{
T_1 V_3 [ 2 ] = { V_4 , V_2 } ;
return F_2 ( V_1 , V_3 , 2 ) ;
}
static int F_4 ( void * V_1 , T_1 V_4 , T_2 V_2 )
{
T_1 V_3 [ 3 ] = { V_4 , V_2 >> 8 , V_2 } ;
return F_2 ( V_1 , V_3 , 3 ) ;
}
static int F_5 ( void * V_1 )
{
int V_5 ;
T_1 V_3 ;
V_5 = F_6 ( V_1 , & V_3 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_3 ;
}
static int F_7 ( void * V_1 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 2 ] ;
F_3 ( V_1 , V_4 , 0 ) ;
V_5 = F_6 ( V_1 , V_6 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
}
static int F_8 ( void * V_1 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 3 ] ;
F_4 ( V_1 , V_4 , 0 ) ;
V_5 = F_6 ( V_1 , V_6 , 3 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_6 [ 1 ] << 8 ) | V_6 [ 2 ] ;
}
static const struct V_7 * F_9 ( const struct V_7 * V_8 ,
char * V_9 )
{
while ( V_8 -> V_9 && V_8 -> V_9 [ 0 ] ) {
if ( strcmp ( V_9 , V_8 -> V_9 ) == 0 )
return V_8 ;
V_8 ++ ;
}
return NULL ;
}
static int T_3 F_10 ( struct V_10 * V_11 )
{
char * V_9 = V_11 -> V_12 . V_13 ;
const struct V_7 * V_14 ;
struct V_15 V_16 = {
. V_1 = V_11 ,
. V_17 = & V_17 ,
} ;
V_14 = F_9 ( V_18 , V_9 ) ;
if ( V_14 == NULL ) {
F_11 ( & V_11 -> V_12 , L_1 , V_9 ) ;
return - V_19 ;
}
return F_12 ( & V_11 -> V_12 , & V_16 , V_14 ) ;
}
static int T_4 F_13 ( struct V_10 * V_11 )
{
return F_14 ( & V_11 -> V_12 ) ;
}
static int T_5 F_15 ( void )
{
return F_16 ( & V_20 ) ;
}
static void T_6 F_17 ( void )
{
F_18 ( & V_20 ) ;
}
