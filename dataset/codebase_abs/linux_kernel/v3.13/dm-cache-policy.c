static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (t, &register_list, list)
if ( ! strcmp ( V_3 -> V_2 , V_2 ) )
return V_3 ;
return NULL ;
}
static struct V_1 * F_3 ( const char * V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
if ( V_3 && ! F_4 ( V_3 -> V_4 ) ) {
F_5 ( L_1 , V_2 ) ;
V_3 = F_6 ( - V_5 ) ;
}
return V_3 ;
}
static struct V_1 * F_7 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_8 ( & V_6 ) ;
V_3 = F_3 ( V_2 ) ;
F_9 ( & V_6 ) ;
return V_3 ;
}
static struct V_1 * F_10 ( const char * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( F_11 ( V_3 ) )
return NULL ;
if ( V_3 )
return V_3 ;
F_12 ( L_2 , V_2 ) ;
V_3 = F_7 ( V_2 ) ;
if ( F_11 ( V_3 ) )
return NULL ;
return V_3 ;
}
static void F_13 ( struct V_1 * V_3 )
{
F_14 ( V_3 -> V_4 ) ;
}
int F_15 ( struct V_1 * type )
{
int V_7 ;
if ( type -> V_8 != 0 && type -> V_8 != 4 ) {
F_5 ( L_3 , ( unsigned long long ) type -> V_8 ) ;
return - V_5 ;
}
F_8 ( & V_6 ) ;
if ( F_1 ( type -> V_2 ) ) {
F_5 ( L_4 , type -> V_2 ) ;
V_7 = - V_5 ;
} else {
F_16 ( & type -> V_9 , & V_10 ) ;
V_7 = 0 ;
}
F_9 ( & V_6 ) ;
return V_7 ;
}
void F_17 ( struct V_1 * type )
{
F_8 ( & V_6 ) ;
F_18 ( & type -> V_9 ) ;
F_9 ( & V_6 ) ;
}
struct V_11 * F_19 ( const char * V_2 ,
T_1 V_12 ,
T_2 V_13 ,
T_2 V_14 )
{
struct V_11 * V_15 = NULL ;
struct V_1 * type ;
type = F_10 ( V_2 ) ;
if ( ! type ) {
F_5 ( L_5 ) ;
return F_6 ( - V_5 ) ;
}
V_15 = type -> V_16 ( V_12 , V_13 , V_14 ) ;
if ( ! V_15 ) {
F_13 ( type ) ;
return F_6 ( - V_17 ) ;
}
V_15 -> V_18 = type ;
return V_15 ;
}
void F_20 ( struct V_11 * V_15 )
{
struct V_1 * V_3 = V_15 -> V_18 ;
V_15 -> V_19 ( V_15 ) ;
F_13 ( V_3 ) ;
}
const char * F_21 ( struct V_11 * V_15 )
{
struct V_1 * V_3 = V_15 -> V_18 ;
return V_3 -> V_2 ;
}
const unsigned * F_22 ( struct V_11 * V_15 )
{
struct V_1 * V_3 = V_15 -> V_18 ;
return V_3 -> V_20 ;
}
T_3 F_23 ( struct V_11 * V_15 )
{
struct V_1 * V_3 = V_15 -> V_18 ;
return V_3 -> V_8 ;
}
