static bool F_1 ( void )
{
if ( ! F_2 () )
return false ;
return true ;
}
static void F_3 ( void )
{
if ( ! F_2 () )
return;
V_1 = true ;
}
static inline void F_4 ( struct V_2 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_5 ( V_2 ) ;
F_6 ( V_4 , & V_3 -> V_5 ) ;
}
static inline void F_7 ( struct V_2 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_5 ( V_2 ) ;
F_8 ( V_4 , & V_3 -> V_5 ) ;
}
static inline bool F_9 ( struct V_2 * V_2 )
{
struct V_3 * V_3 ;
V_3 = F_5 ( V_2 ) ;
return F_10 ( V_4 , & V_3 -> V_5 ) ;
}
static void F_11 ( struct V_2 * V_2 )
{
void * V_6 = F_12 ( V_2 ) ;
F_4 ( V_2 ) ;
memset ( V_6 , V_7 , V_8 ) ;
F_13 ( V_6 ) ;
}
static void F_14 ( struct V_2 * V_2 , int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_11 ( V_2 + V_10 ) ;
}
static bool F_15 ( unsigned char V_11 , unsigned char V_12 )
{
unsigned char error = V_11 ^ V_12 ;
return error && ! ( error & ( error - 1 ) ) ;
}
static void F_16 ( unsigned char * V_13 , T_1 V_14 )
{
static F_17 ( V_15 , 5 * V_16 , 10 ) ;
unsigned char * V_17 ;
unsigned char * V_18 ;
V_17 = F_18 ( V_13 , V_7 , V_14 ) ;
if ( ! V_17 )
return;
for ( V_18 = V_13 + V_14 - 1 ; V_18 > V_17 ; V_18 -- ) {
if ( * V_18 != V_7 )
break;
}
if ( ! F_19 ( & V_15 ) )
return;
else if ( V_17 == V_18 && F_15 ( * V_17 , V_7 ) )
F_20 ( V_19 L_1 ) ;
else
F_20 ( V_19 L_2 ) ;
F_21 ( V_19 , L_3 , V_20 , 16 , 1 , V_17 ,
V_18 - V_17 + 1 , 1 ) ;
F_22 () ;
}
static void F_23 ( struct V_2 * V_2 )
{
void * V_6 ;
if ( ! F_9 ( V_2 ) )
return;
V_6 = F_12 ( V_2 ) ;
F_16 ( V_6 , V_8 ) ;
F_7 ( V_2 ) ;
F_13 ( V_6 ) ;
}
static void F_24 ( struct V_2 * V_2 , int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
F_23 ( V_2 + V_10 ) ;
}
void F_25 ( struct V_2 * V_2 , int V_21 , int V_22 )
{
if ( ! V_1 )
return;
if ( V_22 )
F_24 ( V_2 , V_21 ) ;
else
F_14 ( V_2 , V_21 ) ;
}
