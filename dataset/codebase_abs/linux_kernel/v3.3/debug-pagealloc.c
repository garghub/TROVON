static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_2 , & V_1 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_1 )
{
F_4 ( V_2 , & V_1 -> V_3 ) ;
}
static inline bool F_5 ( struct V_1 * V_1 )
{
return F_6 ( V_2 , & V_1 -> V_3 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
void * V_4 = F_8 ( V_1 ) ;
F_1 ( V_1 ) ;
memset ( V_4 , V_5 , V_6 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_1 * V_1 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_7 ( V_1 + V_8 ) ;
}
static bool F_11 ( unsigned char V_9 , unsigned char V_10 )
{
unsigned char error = V_9 ^ V_10 ;
return error && ! ( error & ( error - 1 ) ) ;
}
static void F_12 ( unsigned char * V_11 , T_1 V_12 )
{
static F_13 ( V_13 , 5 * V_14 , 10 ) ;
unsigned char * V_15 ;
unsigned char * V_16 ;
V_15 = F_14 ( V_11 , V_5 , V_12 ) ;
if ( ! V_15 )
return;
for ( V_16 = V_11 + V_12 - 1 ; V_16 > V_15 ; V_16 -- ) {
if ( * V_16 != V_5 )
break;
}
if ( ! F_15 ( & V_13 ) )
return;
else if ( V_15 == V_16 && F_11 ( * V_15 , V_5 ) )
F_16 ( V_17 L_1 ) ;
else
F_16 ( V_17 L_2 ) ;
F_17 ( V_17 , L_3 , V_18 , 16 , 1 , V_15 ,
V_16 - V_15 + 1 , 1 ) ;
F_18 () ;
}
static void F_19 ( struct V_1 * V_1 )
{
void * V_4 ;
if ( ! F_5 ( V_1 ) )
return;
V_4 = F_8 ( V_1 ) ;
F_12 ( V_4 , V_6 ) ;
F_3 ( V_1 ) ;
F_9 ( V_4 ) ;
}
static void F_20 ( struct V_1 * V_1 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_19 ( V_1 + V_8 ) ;
}
void F_21 ( struct V_1 * V_1 , int V_19 , int V_20 )
{
if ( V_20 )
F_20 ( V_1 , V_19 ) ;
else
F_10 ( V_1 , V_19 ) ;
}
