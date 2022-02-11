static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_4 ( V_2 -> V_3 ) ;
}
struct V_1 * F_5 ( const char * V_4 )
{
struct V_1 * V_5 , * V_2 = NULL ;
if ( ! V_4 )
return NULL ;
F_6 ( & V_6 ) ;
F_7 (q, &crypto_alg_list, cra_list) {
if ( ! ( strcmp ( V_5 -> V_7 , V_4 ) ) ) {
if ( F_1 ( V_5 ) )
V_2 = V_5 ;
break;
}
}
F_8 ( & V_6 ) ;
return V_2 ;
}
static int F_9 ( struct V_8 * V_9 , T_1 V_10 )
{
V_9 -> V_11 = 0 ;
switch ( F_10 ( V_9 ) ) {
case V_12 :
return F_11 ( V_9 , V_10 ) ;
case V_13 :
return F_12 ( V_9 , V_10 ) ;
case V_14 :
return F_13 ( V_9 , V_10 ) ;
default:
break;
}
F_14 () ;
return - V_15 ;
}
static int F_15 ( struct V_8 * V_9 )
{
switch ( F_10 ( V_9 ) ) {
case V_12 :
return F_16 ( V_9 ) ;
case V_13 :
return F_17 ( V_9 ) ;
case V_14 :
return F_18 ( V_9 ) ;
default:
break;
}
F_14 () ;
return - V_15 ;
}
static void F_19 ( struct V_8 * V_9 )
{
switch ( F_10 ( V_9 ) ) {
case V_12 :
F_20 ( V_9 ) ;
break;
case V_13 :
F_21 ( V_9 ) ;
break;
case V_14 :
F_22 ( V_9 ) ;
break;
default:
F_14 () ;
}
}
struct V_8 * F_23 ( const char * V_4 , T_1 V_10 )
{
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 ;
V_2 = F_24 ( V_4 ) ;
if ( V_2 == NULL )
goto V_16;
V_9 = F_25 ( sizeof( * V_9 ) + V_2 -> V_17 , V_18 ) ;
if ( V_9 == NULL )
goto V_19;
V_9 -> V_20 = V_2 ;
if ( F_9 ( V_9 , V_10 ) )
goto V_21;
if ( F_15 ( V_9 ) ) {
F_19 ( V_9 ) ;
goto V_21;
}
goto V_16;
V_21:
F_26 ( V_9 ) ;
V_9 = NULL ;
V_19:
F_3 ( V_2 ) ;
V_16:
return V_9 ;
}
void F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_20 ;
int V_22 = sizeof( * V_9 ) + V_2 -> V_17 ;
F_19 ( V_9 ) ;
F_3 ( V_2 ) ;
memset ( V_9 , 0 , V_22 ) ;
F_26 ( V_9 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
struct V_1 * V_5 ;
F_29 ( & V_6 ) ;
F_7 (q, &crypto_alg_list, cra_list) {
if ( ! ( strcmp ( V_5 -> V_7 , V_2 -> V_7 ) ) ) {
V_23 = - V_24 ;
goto V_16;
}
}
F_30 ( & V_2 -> V_25 , & V_26 ) ;
V_16:
F_31 ( & V_6 ) ;
return V_23 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_23 = - V_27 ;
struct V_1 * V_5 ;
F_33 ( ! V_2 -> V_3 ) ;
F_29 ( & V_6 ) ;
F_7 (q, &crypto_alg_list, cra_list) {
if ( V_2 == V_5 ) {
F_34 ( & V_2 -> V_25 ) ;
V_23 = 0 ;
goto V_16;
}
}
V_16:
F_31 ( & V_6 ) ;
return V_23 ;
}
int F_35 ( const char * V_4 , T_1 V_10 )
{
int V_23 = 0 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( V_2 ) {
F_3 ( V_2 ) ;
V_23 = 1 ;
}
return V_23 ;
}
static int T_2 F_36 ( void )
{
F_37 ( V_28 L_1 ) ;
F_38 () ;
return 0 ;
}
