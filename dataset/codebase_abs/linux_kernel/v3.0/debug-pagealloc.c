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
}
static void F_8 ( struct V_1 * V_1 )
{
void * V_4 ;
if ( F_9 ( V_1 ) ) {
F_7 ( V_1 ) ;
return;
}
F_1 ( V_1 ) ;
V_4 = F_10 ( V_1 ) ;
memset ( V_4 , V_5 , V_6 ) ;
}
static void F_11 ( struct V_1 * V_1 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_8 ( V_1 + V_8 ) ;
}
static bool F_12 ( unsigned char V_9 , unsigned char V_10 )
{
unsigned char error = V_9 ^ V_10 ;
return error && ! ( error & ( error - 1 ) ) ;
}
static void F_13 ( unsigned char * V_11 , T_1 V_12 )
{
unsigned char * V_13 ;
unsigned char * V_14 ;
for ( V_13 = V_11 ; V_13 < V_11 + V_12 ; V_13 ++ ) {
if ( * V_13 != V_5 )
break;
}
if ( V_13 == V_11 + V_12 )
return;
for ( V_14 = V_11 + V_12 - 1 ; V_14 > V_13 ; V_14 -- ) {
if ( * V_14 != V_5 )
break;
}
if ( ! F_14 () )
return;
else if ( V_13 == V_14 && F_12 ( * V_13 , V_5 ) )
F_15 ( V_15 L_1 ) ;
else
F_15 ( V_15 L_2 ) ;
F_16 ( V_15 , L_3 , V_16 , 16 , 1 , V_13 ,
V_14 - V_13 + 1 , 1 ) ;
F_17 () ;
}
static void F_18 ( struct V_1 * V_1 )
{
F_19 ( F_5 ( V_1 ) ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
if ( F_9 ( V_1 ) ) {
F_18 ( V_1 ) ;
return;
}
if ( F_5 ( V_1 ) ) {
void * V_4 = F_10 ( V_1 ) ;
F_13 ( V_4 , V_6 ) ;
F_3 ( V_1 ) ;
}
}
static void F_21 ( struct V_1 * V_1 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_20 ( V_1 + V_8 ) ;
}
void F_22 ( struct V_1 * V_1 , int V_17 , int V_18 )
{
if ( ! V_19 )
return;
if ( V_18 )
F_21 ( V_1 , V_17 ) ;
else
F_11 ( V_1 , V_17 ) ;
}
