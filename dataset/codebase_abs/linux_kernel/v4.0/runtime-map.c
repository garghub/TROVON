static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_5 , char * V_6 )
{
return snprintf ( V_6 , V_7 , L_1 , V_5 -> V_8 . type ) ;
}
static inline struct V_4 * F_4 ( struct V_9 * V_10 )
{
return F_2 ( V_10 , struct V_4 , V_10 ) ;
}
static T_1 F_5 ( struct V_9 * V_10 , struct V_2 * V_3 ,
char * V_6 )
{
struct V_4 * V_5 = F_4 ( V_10 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
return V_11 -> V_12 ( V_5 , V_6 ) ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_4 * V_5 ;
V_5 = F_4 ( V_10 ) ;
F_7 ( V_5 ) ;
}
static struct V_4 *
F_8 ( struct V_9 * V_10 , int V_13 )
{
int V_14 ;
struct V_4 * V_5 ;
if ( ! V_15 ) {
V_15 = F_9 ( L_2 , NULL , V_10 ) ;
if ( ! V_15 )
return F_10 ( - V_16 ) ;
}
V_5 = F_11 ( sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 ) {
F_12 ( V_15 ) ;
return V_5 ;
}
memcpy ( & V_5 -> V_8 , V_18 + V_13 * V_19 ,
sizeof( V_20 ) ) ;
F_13 ( & V_5 -> V_10 , & V_21 ) ;
V_5 -> V_10 . V_22 = V_15 ;
V_14 = F_14 ( & V_5 -> V_10 , NULL , L_3 , V_13 ) ;
if ( V_14 ) {
F_15 ( & V_5 -> V_10 ) ;
F_12 ( V_15 ) ;
return F_10 ( V_14 ) ;
}
return V_5 ;
}
int F_16 ( void )
{
return V_23 * V_19 ;
}
int F_17 ( void )
{
return V_19 ;
}
int F_18 ( void * V_6 , T_2 V_24 )
{
T_2 V_25 = F_16 () ;
if ( V_25 > V_24 )
V_25 = V_24 ;
memcpy ( V_6 , V_18 , V_25 ) ;
return 0 ;
}
void F_19 ( void * V_26 , int V_27 , T_3 V_28 )
{
V_18 = V_26 ;
V_23 = V_27 ;
V_19 = V_28 ;
}
int T_4 F_20 ( struct V_9 * V_29 )
{
int V_30 , V_31 , V_14 = 0 ;
struct V_4 * V_5 ;
if ( ! V_18 )
return 0 ;
V_32 = F_11 ( V_23 * sizeof( V_5 ) , V_17 ) ;
if ( ! V_32 ) {
V_14 = - V_16 ;
goto V_33;
}
for ( V_30 = 0 ; V_30 < V_23 ; V_30 ++ ) {
V_5 = F_8 ( V_29 , V_30 ) ;
if ( F_21 ( V_5 ) ) {
V_14 = F_22 ( V_5 ) ;
goto V_34;
}
* ( V_32 + V_30 ) = V_5 ;
}
return 0 ;
V_34:
for ( V_31 = V_30 - 1 ; V_31 >= 0 ; V_31 -- ) {
V_5 = * ( V_32 + V_31 ) ;
F_15 ( & V_5 -> V_10 ) ;
}
if ( V_15 )
F_12 ( V_15 ) ;
V_33:
return V_14 ;
}
