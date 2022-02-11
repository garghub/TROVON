static int F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
return F_2 ( V_1 , & V_3 ) ;
}
bool F_3 ( void )
{
return V_4 ;
}
static bool F_4 ( void )
{
return V_3 ;
}
static void F_5 ( void )
{
if ( ! F_6 ( V_5 ) ) {
if ( ! V_3 && ! F_7 () )
return;
} else {
if ( ! V_3 )
return;
}
V_4 = true ;
}
static inline void F_8 ( struct V_6 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_9 ( V_6 ) ;
if ( F_10 ( ! V_7 ) )
return;
F_11 ( V_8 , & V_7 -> V_9 ) ;
}
static inline void F_12 ( struct V_6 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_9 ( V_6 ) ;
if ( F_10 ( ! V_7 ) )
return;
F_13 ( V_8 , & V_7 -> V_9 ) ;
}
bool F_14 ( struct V_6 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_9 ( V_6 ) ;
if ( F_10 ( ! V_7 ) )
return false ;
return F_15 ( V_8 , & V_7 -> V_9 ) ;
}
static void F_16 ( struct V_6 * V_6 )
{
void * V_10 = F_17 ( V_6 ) ;
F_8 ( V_6 ) ;
memset ( V_10 , V_11 , V_12 ) ;
F_18 ( V_10 ) ;
}
static void F_19 ( struct V_6 * V_6 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_16 ( V_6 + V_14 ) ;
}
static bool F_20 ( unsigned char V_15 , unsigned char V_16 )
{
unsigned char error = V_15 ^ V_16 ;
return error && ! ( error & ( error - 1 ) ) ;
}
static void F_21 ( unsigned char * V_17 , T_1 V_18 )
{
static F_22 ( V_19 , 5 * V_20 , 10 ) ;
unsigned char * V_21 ;
unsigned char * V_22 ;
if ( F_6 ( V_23 ) )
return;
V_21 = F_23 ( V_17 , V_11 , V_18 ) ;
if ( ! V_21 )
return;
for ( V_22 = V_17 + V_18 - 1 ; V_22 > V_21 ; V_22 -- ) {
if ( * V_22 != V_11 )
break;
}
if ( ! F_24 ( & V_19 ) )
return;
else if ( V_21 == V_22 && F_20 ( * V_21 , V_11 ) )
F_25 ( L_1 ) ;
else
F_25 ( L_2 ) ;
F_26 ( V_24 , L_3 , V_25 , 16 , 1 , V_21 ,
V_22 - V_21 + 1 , 1 ) ;
F_27 () ;
}
static void F_28 ( struct V_6 * V_6 )
{
void * V_10 ;
if ( ! F_14 ( V_6 ) )
return;
V_10 = F_17 ( V_6 ) ;
F_21 ( V_10 , V_12 ) ;
F_12 ( V_6 ) ;
F_18 ( V_10 ) ;
}
static void F_29 ( struct V_6 * V_6 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_28 ( V_6 + V_14 ) ;
}
void F_30 ( struct V_6 * V_6 , int V_26 , int V_27 )
{
if ( ! F_3 () )
return;
if ( V_27 )
F_29 ( V_6 , V_26 ) ;
else
F_19 ( V_6 , V_26 ) ;
}
void F_31 ( struct V_6 * V_6 , int V_26 , int V_27 )
{
}
