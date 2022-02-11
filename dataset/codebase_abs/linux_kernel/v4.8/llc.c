int F_1 ( void )
{
int V_1 ;
V_1 = F_2 () ;
if ( V_1 )
goto exit;
V_1 = F_3 () ;
if ( V_1 )
goto exit;
return 0 ;
exit:
F_4 () ;
return V_1 ;
}
void F_4 ( void )
{
struct V_2 * V_3 , * V_4 ;
F_5 (llc_engine, n, &llc_engines, entry) {
F_6 ( & V_3 -> V_5 ) ;
F_7 ( V_3 -> V_6 ) ;
F_7 ( V_3 ) ;
}
}
int F_8 ( const char * V_6 , struct V_7 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_9 ( sizeof( struct V_2 ) , V_9 ) ;
if ( V_3 == NULL )
return - V_10 ;
V_3 -> V_6 = F_10 ( V_6 , V_9 ) ;
if ( V_3 -> V_6 == NULL ) {
F_7 ( V_3 ) ;
return - V_10 ;
}
V_3 -> V_8 = V_8 ;
F_11 ( & V_3 -> V_5 ) ;
F_12 ( & V_3 -> V_5 , & V_11 ) ;
return 0 ;
}
static struct V_2 * F_13 ( const char * V_6 )
{
struct V_2 * V_3 ;
F_14 (llc_engine, &llc_engines, entry) {
if ( strcmp ( V_3 -> V_6 , V_6 ) == 0 )
return V_3 ;
}
return NULL ;
}
void F_15 ( const char * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_13 ( V_6 ) ;
if ( V_3 == NULL )
return;
F_6 ( & V_3 -> V_5 ) ;
F_7 ( V_3 -> V_6 ) ;
F_7 ( V_3 ) ;
}
struct V_12 * F_16 ( const char * V_6 , struct V_13 * V_14 ,
T_1 V_15 ,
T_2 V_16 , int V_17 ,
int V_18 , T_3 V_19 )
{
struct V_2 * V_3 ;
struct V_12 * V_20 ;
V_3 = F_13 ( V_6 ) ;
if ( V_3 == NULL )
return NULL ;
V_20 = F_9 ( sizeof( struct V_12 ) , V_9 ) ;
if ( V_20 == NULL )
return NULL ;
V_20 -> V_21 = V_3 -> V_8 -> V_22 ( V_14 , V_15 , V_16 ,
V_17 , V_18 ,
& V_20 -> V_23 , & V_20 -> V_24 ,
V_19 ) ;
if ( V_20 -> V_21 == NULL ) {
F_7 ( V_20 ) ;
return NULL ;
}
V_20 -> V_8 = V_3 -> V_8 ;
return V_20 ;
}
void F_17 ( struct V_12 * V_20 )
{
V_20 -> V_8 -> V_25 ( V_20 ) ;
F_7 ( V_20 ) ;
}
int F_18 ( struct V_12 * V_20 )
{
return V_20 -> V_8 -> V_26 ( V_20 ) ;
}
int F_19 ( struct V_12 * V_20 )
{
return V_20 -> V_8 -> V_27 ( V_20 ) ;
}
void F_20 ( struct V_12 * V_20 , struct V_28 * V_29 )
{
V_20 -> V_8 -> V_30 ( V_20 , V_29 ) ;
}
int F_21 ( struct V_12 * V_20 , struct V_28 * V_29 )
{
return V_20 -> V_8 -> V_31 ( V_20 , V_29 ) ;
}
void * F_22 ( struct V_12 * V_20 )
{
return V_20 -> V_21 ;
}
