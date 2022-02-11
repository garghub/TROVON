static int F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
return F_2 ( V_1 , & V_3 ) ;
}
bool F_3 ( void )
{
return ( V_3 ||
( ! F_4 ( V_4 ) &&
F_5 () ) ) ;
}
static void F_6 ( struct V_5 * V_5 )
{
void * V_6 = F_7 ( V_5 ) ;
memset ( V_6 , V_7 , V_8 ) ;
F_8 ( V_6 ) ;
}
static void F_9 ( struct V_5 * V_5 , int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_6 ( V_5 + V_10 ) ;
}
static bool F_10 ( unsigned char V_11 , unsigned char V_12 )
{
unsigned char error = V_11 ^ V_12 ;
return error && ! ( error & ( error - 1 ) ) ;
}
static void F_11 ( unsigned char * V_13 , T_1 V_14 )
{
static F_12 ( V_15 , 5 * V_16 , 10 ) ;
unsigned char * V_17 ;
unsigned char * V_18 ;
if ( F_4 ( V_19 ) )
return;
V_17 = F_13 ( V_13 , V_7 , V_14 ) ;
if ( ! V_17 )
return;
for ( V_18 = V_13 + V_14 - 1 ; V_18 > V_17 ; V_18 -- ) {
if ( * V_18 != V_7 )
break;
}
if ( ! F_14 ( & V_15 ) )
return;
else if ( V_17 == V_18 && F_10 ( * V_17 , V_7 ) )
F_15 ( L_1 ) ;
else
F_15 ( L_2 ) ;
F_16 ( V_20 , L_3 , V_21 , 16 , 1 , V_17 ,
V_18 - V_17 + 1 , 1 ) ;
F_17 () ;
}
static void F_18 ( struct V_5 * V_5 )
{
void * V_6 ;
V_6 = F_7 ( V_5 ) ;
F_11 ( V_6 , V_8 ) ;
F_8 ( V_6 ) ;
}
static void F_19 ( struct V_5 * V_5 , int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_18 ( V_5 + V_10 ) ;
}
void F_20 ( struct V_5 * V_5 , int V_22 , int V_23 )
{
if ( ! F_3 () )
return;
if ( V_23 )
F_19 ( V_5 , V_22 ) ;
else
F_9 ( V_5 , V_22 ) ;
}
void F_21 ( struct V_5 * V_5 , int V_22 , int V_23 )
{
}
