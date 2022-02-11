int F_1 ( void )
{
int V_1 ;
F_2 ( & V_2 ) ;
V_1 = F_3 () ;
if ( V_1 )
goto exit;
V_1 = F_4 () ;
if ( V_1 )
goto exit;
return 0 ;
exit:
F_5 () ;
return V_1 ;
}
void F_5 ( void )
{
struct V_3 * V_4 , * V_5 ;
F_6 (llc_engine, n, &llc_engines, entry) {
F_7 ( & V_4 -> V_6 ) ;
F_8 ( V_4 -> V_7 ) ;
F_8 ( V_4 ) ;
}
}
int F_9 ( const char * V_7 , struct V_8 * V_9 )
{
struct V_3 * V_4 ;
V_4 = F_10 ( sizeof( struct V_3 ) , V_10 ) ;
if ( V_4 == NULL )
return - V_11 ;
V_4 -> V_7 = F_11 ( V_7 , V_10 ) ;
if ( V_4 -> V_7 == NULL ) {
F_8 ( V_4 ) ;
return - V_11 ;
}
V_4 -> V_9 = V_9 ;
F_2 ( & V_4 -> V_6 ) ;
F_12 ( & V_4 -> V_6 , & V_2 ) ;
return 0 ;
}
static struct V_3 * F_13 ( const char * V_7 )
{
struct V_3 * V_4 ;
F_14 (llc_engine, &llc_engines, entry) {
if ( strcmp ( V_4 -> V_7 , V_7 ) == 0 )
return V_4 ;
}
return NULL ;
}
void F_15 ( const char * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_13 ( V_7 ) ;
if ( V_4 == NULL )
return;
F_7 ( & V_4 -> V_6 ) ;
F_8 ( V_4 -> V_7 ) ;
F_8 ( V_4 ) ;
}
struct V_12 * F_16 ( const char * V_7 , struct V_13 * V_14 ,
T_1 V_15 ,
T_2 V_16 , int V_17 ,
int V_18 , T_3 V_19 )
{
struct V_3 * V_4 ;
struct V_12 * V_20 ;
V_4 = F_13 ( V_7 ) ;
if ( V_4 == NULL )
return NULL ;
V_20 = F_10 ( sizeof( struct V_12 ) , V_10 ) ;
if ( V_20 == NULL )
return NULL ;
V_20 -> V_21 = V_4 -> V_9 -> V_22 ( V_14 , V_15 , V_16 ,
V_17 , V_18 ,
& V_20 -> V_23 , & V_20 -> V_24 ,
V_19 ) ;
if ( V_20 -> V_21 == NULL ) {
F_8 ( V_20 ) ;
return NULL ;
}
V_20 -> V_9 = V_4 -> V_9 ;
return V_20 ;
}
void F_17 ( struct V_12 * V_20 )
{
V_20 -> V_9 -> V_25 ( V_20 ) ;
F_8 ( V_20 ) ;
}
inline void F_18 ( struct V_12 * V_20 , int * V_23 ,
int * V_24 )
{
* V_23 = V_20 -> V_23 ;
* V_24 = V_20 -> V_24 ;
}
inline int F_19 ( struct V_12 * V_20 )
{
return V_20 -> V_9 -> V_26 ( V_20 ) ;
}
inline int F_20 ( struct V_12 * V_20 )
{
return V_20 -> V_9 -> V_27 ( V_20 ) ;
}
inline void F_21 ( struct V_12 * V_20 , struct V_28 * V_29 )
{
V_20 -> V_9 -> V_30 ( V_20 , V_29 ) ;
}
inline int F_22 ( struct V_12 * V_20 , struct V_28 * V_29 )
{
return V_20 -> V_9 -> V_31 ( V_20 , V_29 ) ;
}
inline void * F_23 ( struct V_12 * V_20 )
{
return V_20 -> V_21 ;
}
