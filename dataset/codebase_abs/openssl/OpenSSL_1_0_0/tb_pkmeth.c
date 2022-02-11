void F_1 ( T_1 * V_1 )
{
F_2 ( & V_2 , V_1 ) ;
}
static void F_3 ( void )
{
F_4 ( & V_2 ) ;
}
int F_5 ( T_1 * V_1 )
{
if( V_1 -> V_3 )
{
const int * V_4 ;
int V_5 = V_1 -> V_3 ( V_1 , NULL , & V_4 , 0 ) ;
if( V_5 > 0 )
return F_6 ( & V_2 ,
F_3 , V_1 , V_4 ,
V_5 , 0 ) ;
}
return 1 ;
}
void F_7 ()
{
T_1 * V_1 ;
for( V_1 = F_8 () ; V_1 ; V_1 = F_9 ( V_1 ) )
F_5 ( V_1 ) ;
}
int F_10 ( T_1 * V_1 )
{
if( V_1 -> V_3 )
{
const int * V_4 ;
int V_5 = V_1 -> V_3 ( V_1 , NULL , & V_4 , 0 ) ;
if( V_5 > 0 )
return F_6 ( & V_2 ,
F_3 , V_1 , V_4 ,
V_5 , 1 ) ;
}
return 1 ;
}
T_1 * F_11 ( int V_6 )
{
return F_12 ( & V_2 , V_6 ) ;
}
const T_2 * F_13 ( T_1 * V_1 , int V_6 )
{
T_2 * V_7 ;
T_3 V_8 = F_14 ( V_1 ) ;
if( ! V_8 || ! V_8 ( V_1 , & V_7 , NULL , V_6 ) )
{
F_15 ( V_9 ,
V_10 ) ;
return NULL ;
}
return V_7 ;
}
T_3 F_14 ( const T_1 * V_1 )
{
return V_1 -> V_3 ;
}
int F_16 ( T_1 * V_1 , T_3 V_11 )
{
V_1 -> V_3 = V_11 ;
return 1 ;
}
void F_17 ( T_1 * V_1 )
{
int V_12 ;
T_2 * V_13 ;
if ( V_1 -> V_3 )
{
const int * V_14 ;
int V_15 ;
V_15 = V_1 -> V_3 ( V_1 , NULL , & V_14 , 0 ) ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ )
{
if ( V_1 -> V_3 ( V_1 , & V_13 , NULL , V_14 [ V_12 ] ) )
{
F_18 ( V_13 ) ;
}
}
}
}
