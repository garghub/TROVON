static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void F_3 ( struct V_1 * V_5 )
{
F_4 ( & V_5 -> V_6 ) ;
F_5 ( & V_5 -> V_4 ) ;
}
int F_6 ( struct V_1 * V_5 , const char * V_7 , ... )
{
int error = 0 ;
int V_8 = V_9 ;
int V_10 ;
T_1 args ;
char * V_11 ;
va_start ( args , V_7 ) ;
V_10 = vsnprintf ( V_5 -> V_12 , V_8 , V_7 , args ) ;
va_end ( args ) ;
if ( V_10 < V_8 )
V_11 = V_5 -> V_12 ;
else {
V_8 = V_10 + 1 ;
V_11 = F_7 ( V_8 , V_13 ) ;
if ( ! V_11 ) {
error = - V_14 ;
goto V_15;
}
va_start ( args , V_7 ) ;
V_10 = vsnprintf ( V_11 , V_8 , V_7 , args ) ;
va_end ( args ) ;
if ( V_10 >= V_8 ) {
F_8 ( V_11 ) ;
error = - V_16 ;
goto V_15;
}
}
if ( V_5 -> V_17 && V_5 -> V_17 != V_5 -> V_12 )
F_8 ( V_5 -> V_17 ) ;
V_5 -> V_17 = V_11 ;
V_15:
return error ;
}
void F_9 ( struct V_1 * V_5 ,
const char * V_11 ,
struct V_18 * type )
{
F_6 ( V_5 , V_11 ) ;
V_5 -> V_19 = type ;
F_3 ( V_5 ) ;
}
void F_10 ( struct V_20 * V_21 , const char * V_11 ,
struct V_18 * type )
{
F_6 ( & V_21 -> V_22 , V_11 ) ;
V_21 -> V_22 . V_19 = type ;
F_11 ( V_21 ) ;
}
struct V_1 * F_12 ( struct V_1 * V_5 )
{
if ( V_5 )
F_13 ( & V_5 -> V_6 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_5 )
{
struct V_18 * V_23 = V_5 -> V_19 ;
struct V_20 * V_24 = V_5 -> V_25 ;
struct V_1 * V_26 = V_5 -> V_27 ;
F_15 ( L_1 , F_16 ( V_5 ) ) ;
if ( V_5 -> V_17 != V_5 -> V_12 )
F_8 ( V_5 -> V_17 ) ;
V_5 -> V_17 = NULL ;
if ( V_23 && V_23 -> V_28 && V_23 -> V_28 -> V_29 )
V_23 -> V_28 -> V_29 ( V_5 ) ;
if ( V_24 )
F_17 ( V_24 ) ;
if ( V_26 )
F_18 ( V_26 ) ;
}
static void F_19 ( struct V_30 * V_30 )
{
F_14 ( F_2 ( V_30 , struct V_1 , V_6 ) ) ;
}
void F_18 ( struct V_1 * V_5 )
{
if ( V_5 )
F_20 ( & V_5 -> V_6 , F_19 ) ;
}
void F_11 ( struct V_20 * V_21 )
{
F_3 ( & V_21 -> V_22 ) ;
F_5 ( & V_21 -> V_31 ) ;
}
struct V_1 * F_21 ( struct V_20 * V_21 ,
const char * V_11 )
{
struct V_2 * V_3 ;
struct V_1 * V_32 = NULL ;
F_22 (entry,&group->cg_children) {
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( F_16 ( V_5 ) &&
! strcmp ( F_16 ( V_5 ) , V_11 ) ) {
V_32 = F_12 ( V_5 ) ;
break;
}
}
return V_32 ;
}
