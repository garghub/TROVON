static struct V_1 * F_1 ( const char * V_2 , const char * V_3 )
{
struct V_1 * V_4 , * V_5 = NULL ;
int V_6 , V_7 = 0 , V_8 = 0 ;
if ( V_2 )
V_8 += 2 ;
if ( V_3 )
V_8 += 1 ;
F_2 (p, &clocks, node) {
V_6 = 0 ;
if ( V_4 -> V_2 ) {
if ( ! V_2 || strcmp ( V_4 -> V_2 , V_2 ) )
continue;
V_6 += 2 ;
}
if ( V_4 -> V_3 ) {
if ( ! V_3 || strcmp ( V_4 -> V_3 , V_3 ) )
continue;
V_6 += 1 ;
}
if ( V_6 > V_7 ) {
V_5 = V_4 ;
if ( V_6 != V_8 )
V_7 = V_6 ;
else
break;
}
}
return V_5 ;
}
struct V_9 * F_3 ( const char * V_2 , const char * V_3 )
{
struct V_1 * V_5 ;
F_4 ( & V_10 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_5 && ! F_5 ( V_5 -> V_9 ) )
V_5 = NULL ;
F_6 ( & V_10 ) ;
return V_5 ? V_5 -> V_9 : F_7 ( - V_11 ) ;
}
struct V_9 * F_8 ( struct V_12 * V_13 , const char * V_3 )
{
const char * V_2 = V_13 ? F_9 ( V_13 ) : NULL ;
return F_3 ( V_2 , V_3 ) ;
}
void F_10 ( struct V_9 * V_9 )
{
F_11 ( V_9 ) ;
}
static void F_12 ( struct V_12 * V_13 , void * V_14 )
{
F_10 ( * (struct V_9 * * ) V_14 ) ;
}
struct V_9 * F_13 ( struct V_12 * V_13 , const char * V_15 )
{
struct V_9 * * V_16 , * V_9 ;
V_16 = F_14 ( F_12 , sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return F_7 ( - V_18 ) ;
V_9 = F_8 ( V_13 , V_15 ) ;
if ( ! F_15 ( V_9 ) ) {
* V_16 = V_9 ;
F_16 ( V_13 , V_16 ) ;
} else {
F_17 ( V_16 ) ;
}
return V_9 ;
}
static int F_18 ( struct V_12 * V_13 , void * V_14 , void * V_19 )
{
struct V_9 * * V_20 = V_14 ;
if ( ! V_20 || ! * V_20 ) {
F_19 ( ! V_20 || ! * V_20 ) ;
return 0 ;
}
return * V_20 == V_19 ;
}
void F_20 ( struct V_12 * V_13 , struct V_9 * V_9 )
{
int V_21 ;
V_21 = F_21 ( V_13 , F_12 , F_18 , V_9 ) ;
F_19 ( V_21 ) ;
}
void F_22 ( struct V_1 * V_5 )
{
F_4 ( & V_10 ) ;
F_23 ( & V_5 -> V_22 , & V_23 ) ;
F_6 ( & V_10 ) ;
}
void T_1 F_24 ( struct V_1 * V_5 , T_2 V_24 )
{
F_4 ( & V_10 ) ;
while ( V_24 -- ) {
F_23 ( & V_5 -> V_22 , & V_23 ) ;
V_5 ++ ;
}
F_6 ( & V_10 ) ;
}
static struct V_1 * T_3
F_25 ( struct V_9 * V_9 , const char * V_3 , const char * V_25 ,
T_4 V_26 )
{
struct V_27 * V_28 ;
V_28 = F_26 ( sizeof( * V_28 ) ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_5 . V_9 = V_9 ;
if ( V_3 ) {
F_27 ( V_28 -> V_3 , V_3 , sizeof( V_28 -> V_3 ) ) ;
V_28 -> V_5 . V_3 = V_28 -> V_3 ;
}
if ( V_25 ) {
F_28 ( V_28 -> V_2 , sizeof( V_28 -> V_2 ) , V_25 , V_26 ) ;
V_28 -> V_5 . V_2 = V_28 -> V_2 ;
}
return & V_28 -> V_5 ;
}
struct V_1 * T_3
F_29 ( struct V_9 * V_9 , const char * V_3 , const char * V_25 , ... )
{
struct V_1 * V_5 ;
T_4 V_26 ;
va_start ( V_26 , V_25 ) ;
V_5 = F_25 ( V_9 , V_3 , V_25 , V_26 ) ;
va_end ( V_26 ) ;
return V_5 ;
}
int F_30 ( const char * V_29 , const char * V_30 , char * V_15 ,
struct V_12 * V_13 )
{
struct V_9 * V_31 = F_8 ( V_13 , V_15 ) ;
struct V_1 * V_32 ;
if ( F_15 ( V_31 ) )
return F_31 ( V_31 ) ;
V_32 = F_29 ( V_31 , V_29 , V_30 ) ;
F_10 ( V_31 ) ;
if ( ! V_32 )
return - V_33 ;
F_22 ( V_32 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_5 )
{
F_4 ( & V_10 ) ;
F_33 ( & V_5 -> V_22 ) ;
F_6 ( & V_10 ) ;
F_34 ( V_5 ) ;
}
int F_35 ( struct V_9 * V_9 , const char * V_3 ,
const char * V_25 , ... )
{
struct V_1 * V_5 ;
T_4 V_26 ;
if ( F_15 ( V_9 ) )
return F_31 ( V_9 ) ;
va_start ( V_26 , V_25 ) ;
V_5 = F_25 ( V_9 , V_3 , V_25 , V_26 ) ;
va_end ( V_26 ) ;
if ( ! V_5 )
return - V_18 ;
F_22 ( V_5 ) ;
return 0 ;
}
int F_36 ( struct V_9 * V_9 , struct V_1 * V_5 , T_2 V_24 )
{
unsigned V_34 ;
if ( F_15 ( V_9 ) )
return F_31 ( V_9 ) ;
for ( V_34 = 0 ; V_34 < V_24 ; V_34 ++ , V_5 ++ ) {
V_5 -> V_9 = V_9 ;
F_22 ( V_5 ) ;
}
return 0 ;
}
