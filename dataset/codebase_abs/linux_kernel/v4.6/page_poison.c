static int F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
if ( strcmp ( V_1 , L_1 ) == 0 )
V_3 = true ;
else if ( strcmp ( V_1 , L_2 ) == 0 )
V_3 = false ;
return 0 ;
}
bool F_2 ( void )
{
return V_4 ;
}
static bool F_3 ( void )
{
return V_3 ;
}
static void F_4 ( void )
{
if ( ! F_5 ( V_5 ) ) {
if ( ! V_3 && ! F_6 () )
return;
} else {
if ( ! V_3 )
return;
}
V_4 = true ;
}
static inline void F_7 ( struct V_6 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( V_6 ) ;
F_9 ( V_8 , & V_7 -> V_9 ) ;
}
static inline void F_10 ( struct V_6 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( V_6 ) ;
F_11 ( V_8 , & V_7 -> V_9 ) ;
}
bool F_12 ( struct V_6 * V_6 )
{
struct V_7 * V_7 ;
V_7 = F_8 ( V_6 ) ;
if ( ! V_7 )
return false ;
return F_13 ( V_8 , & V_7 -> V_9 ) ;
}
static void F_14 ( struct V_6 * V_6 )
{
void * V_10 = F_15 ( V_6 ) ;
F_7 ( V_6 ) ;
memset ( V_10 , V_11 , V_12 ) ;
F_16 ( V_10 ) ;
}
static void F_17 ( struct V_6 * V_6 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_14 ( V_6 + V_14 ) ;
}
static bool F_18 ( unsigned char V_15 , unsigned char V_16 )
{
unsigned char error = V_15 ^ V_16 ;
return error && ! ( error & ( error - 1 ) ) ;
}
static void F_19 ( unsigned char * V_17 , T_1 V_18 )
{
static F_20 ( V_19 , 5 * V_20 , 10 ) ;
unsigned char * V_21 ;
unsigned char * V_22 ;
if ( F_5 ( V_23 ) )
return;
V_21 = F_21 ( V_17 , V_11 , V_18 ) ;
if ( ! V_21 )
return;
for ( V_22 = V_17 + V_18 - 1 ; V_22 > V_21 ; V_22 -- ) {
if ( * V_22 != V_11 )
break;
}
if ( ! F_22 ( & V_19 ) )
return;
else if ( V_21 == V_22 && F_18 ( * V_21 , V_11 ) )
F_23 ( L_3 ) ;
else
F_23 ( L_4 ) ;
F_24 ( V_24 , L_5 , V_25 , 16 , 1 , V_21 ,
V_22 - V_21 + 1 , 1 ) ;
F_25 () ;
}
static void F_26 ( struct V_6 * V_6 )
{
void * V_10 ;
if ( ! F_12 ( V_6 ) )
return;
V_10 = F_15 ( V_6 ) ;
F_19 ( V_10 , V_12 ) ;
F_10 ( V_6 ) ;
F_16 ( V_10 ) ;
}
static void F_27 ( struct V_6 * V_6 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
F_26 ( V_6 + V_14 ) ;
}
void F_28 ( struct V_6 * V_6 , int V_26 , int V_27 )
{
if ( ! F_2 () )
return;
if ( V_27 )
F_27 ( V_6 , V_26 ) ;
else
F_17 ( V_6 , V_26 ) ;
}
void F_29 ( struct V_6 * V_6 , int V_26 , int V_27 )
{
}
