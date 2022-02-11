static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 ,
const char * V_5 , const char * V_6 )
{
struct V_7 V_8 ;
struct V_1 * V_1 ;
int V_9 ;
if ( V_4 < 0 )
return F_2 ( - V_10 ) ;
V_9 = F_3 ( V_3 , L_1 , L_2 , V_4 ,
& V_8 ) ;
if ( V_9 )
return F_2 ( V_9 ) ;
V_1 = F_4 ( & V_8 , V_5 , V_6 ) ;
F_5 ( V_8 . V_3 ) ;
return V_1 ;
}
struct V_1 * F_6 ( struct V_2 * V_3 , int V_4 )
{
return F_1 ( V_3 , V_4 , V_3 -> V_11 , NULL ) ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 ,
const char * V_5 ,
const char * V_12 )
{
struct V_1 * V_1 = F_2 ( - V_13 ) ;
while ( V_3 ) {
int V_4 = 0 ;
if ( V_12 )
V_4 = F_8 ( V_3 , L_3 , V_12 ) ;
V_1 = F_1 ( V_3 , V_4 , V_5 , V_12 ) ;
if ( ! F_9 ( V_1 ) ) {
break;
} else if ( V_12 && V_4 >= 0 ) {
if ( F_10 ( V_1 ) != - V_14 )
F_11 ( L_4 ,
V_3 -> V_11 , V_12 ? V_12 : L_5 , V_4 ) ;
return V_1 ;
}
V_3 = V_3 -> V_15 ;
if ( V_3 && ! F_12 ( V_3 , L_6 , NULL ) )
break;
}
return V_1 ;
}
struct V_1 * F_13 ( struct V_2 * V_3 , const char * V_12 )
{
if ( ! V_3 )
return F_2 ( - V_13 ) ;
return F_7 ( V_3 , V_3 -> V_11 , V_12 ) ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 ,
const char * V_5 ,
const char * V_12 )
{
return F_2 ( - V_13 ) ;
}
static struct V_16 * F_14 ( const char * V_5 , const char * V_6 )
{
struct V_16 * V_17 , * V_18 = NULL ;
int V_19 , V_20 = 0 , V_21 = 0 ;
if ( V_5 )
V_21 += 2 ;
if ( V_6 )
V_21 += 1 ;
F_15 (p, &clocks, node) {
V_19 = 0 ;
if ( V_17 -> V_5 ) {
if ( ! V_5 || strcmp ( V_17 -> V_5 , V_5 ) )
continue;
V_19 += 2 ;
}
if ( V_17 -> V_6 ) {
if ( ! V_6 || strcmp ( V_17 -> V_6 , V_6 ) )
continue;
V_19 += 1 ;
}
if ( V_19 > V_20 ) {
V_18 = V_17 ;
if ( V_19 != V_21 )
V_20 = V_19 ;
else
break;
}
}
return V_18 ;
}
struct V_1 * F_16 ( const char * V_5 , const char * V_6 )
{
struct V_16 * V_18 ;
struct V_1 * V_1 = NULL ;
F_17 ( & V_22 ) ;
V_18 = F_14 ( V_5 , V_6 ) ;
if ( ! V_18 )
goto V_23;
V_1 = F_18 ( V_18 -> V_24 , V_5 , V_6 ) ;
if ( F_9 ( V_1 ) )
goto V_23;
if ( ! F_19 ( V_1 ) ) {
F_20 ( V_1 ) ;
V_18 = NULL ;
goto V_23;
}
V_23:
F_21 ( & V_22 ) ;
return V_18 ? V_1 : F_2 ( - V_13 ) ;
}
struct V_1 * F_22 ( struct V_25 * V_26 , const char * V_6 )
{
const char * V_5 = V_26 ? F_23 ( V_26 ) : NULL ;
struct V_1 * V_1 ;
if ( V_26 ) {
V_1 = F_7 ( V_26 -> V_27 , V_5 , V_6 ) ;
if ( ! F_9 ( V_1 ) || F_10 ( V_1 ) == - V_14 )
return V_1 ;
}
return F_16 ( V_5 , V_6 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
F_25 ( V_1 ) ;
}
static void F_26 ( struct V_16 * V_18 )
{
F_17 ( & V_22 ) ;
F_27 ( & V_18 -> V_28 , & V_29 ) ;
F_21 ( & V_22 ) ;
}
void F_28 ( struct V_16 * V_18 )
{
if ( ! V_18 -> V_24 )
V_18 -> V_24 = F_29 ( V_18 -> V_1 ) ;
F_26 ( V_18 ) ;
}
void F_30 ( struct V_16 * V_18 , T_1 V_30 )
{
F_17 ( & V_22 ) ;
while ( V_30 -- ) {
V_18 -> V_24 = F_29 ( V_18 -> V_1 ) ;
F_27 ( & V_18 -> V_28 , & V_29 ) ;
V_18 ++ ;
}
F_21 ( & V_22 ) ;
}
static struct V_16 * T_2
F_31 ( struct V_24 * V_31 , const char * V_6 , const char * V_32 ,
T_3 V_33 )
{
struct V_34 * V_35 ;
V_35 = F_32 ( sizeof( * V_35 ) ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_18 . V_24 = V_31 ;
if ( V_6 ) {
F_33 ( V_35 -> V_6 , V_6 , sizeof( V_35 -> V_6 ) ) ;
V_35 -> V_18 . V_6 = V_35 -> V_6 ;
}
if ( V_32 ) {
F_34 ( V_35 -> V_5 , sizeof( V_35 -> V_5 ) , V_32 , V_33 ) ;
V_35 -> V_18 . V_5 = V_35 -> V_5 ;
}
return & V_35 -> V_18 ;
}
static struct V_16 *
F_35 ( struct V_24 * V_31 , const char * V_6 , const char * V_32 ,
T_3 V_33 )
{
struct V_16 * V_18 ;
V_18 = F_31 ( V_31 , V_6 , V_32 , V_33 ) ;
if ( V_18 )
F_26 ( V_18 ) ;
return V_18 ;
}
struct V_16 * T_2
F_36 ( struct V_1 * V_1 , const char * V_6 , const char * V_32 , ... )
{
struct V_16 * V_18 ;
T_3 V_33 ;
va_start ( V_33 , V_32 ) ;
V_18 = F_31 ( F_29 ( V_1 ) , V_6 , V_32 , V_33 ) ;
va_end ( V_33 ) ;
return V_18 ;
}
struct V_16 * F_37 ( struct V_1 * V_1 , const char * V_6 ,
const char * V_32 , ... )
{
struct V_16 * V_18 ;
T_3 V_33 ;
va_start ( V_33 , V_32 ) ;
V_18 = F_35 ( F_29 ( V_1 ) , V_6 , V_32 , V_33 ) ;
va_end ( V_33 ) ;
return V_18 ;
}
int F_38 ( const char * V_36 , const char * V_37 ,
const char * V_6 , struct V_25 * V_26 )
{
struct V_1 * V_38 = F_22 ( V_26 , V_6 ) ;
struct V_16 * V_39 ;
if ( F_9 ( V_38 ) )
return F_10 ( V_38 ) ;
V_39 = F_37 ( V_38 , V_36 , V_37 ? L_7 : NULL ,
V_37 ) ;
F_24 ( V_38 ) ;
return V_39 ? 0 : - V_40 ;
}
void F_39 ( struct V_16 * V_18 )
{
F_17 ( & V_22 ) ;
F_40 ( & V_18 -> V_28 ) ;
F_21 ( & V_22 ) ;
F_41 ( V_18 ) ;
}
static struct V_16 * F_42 ( struct V_24 * V_31 ,
const char * V_6 ,
const char * V_5 , ... )
{
struct V_16 * V_18 ;
T_3 V_33 ;
va_start ( V_33 , V_5 ) ;
V_18 = F_35 ( V_31 , V_6 , V_5 , V_33 ) ;
va_end ( V_33 ) ;
return V_18 ;
}
int F_43 ( struct V_1 * V_1 , const char * V_6 ,
const char * V_5 )
{
struct V_16 * V_18 ;
if ( F_9 ( V_1 ) )
return F_10 ( V_1 ) ;
if ( V_5 )
V_18 = F_42 ( F_29 ( V_1 ) , V_6 , L_7 ,
V_5 ) ;
else
V_18 = F_42 ( F_29 ( V_1 ) , V_6 , NULL ) ;
return V_18 ? 0 : - V_41 ;
}
int F_44 ( struct V_1 * V_1 , struct V_16 * V_18 , T_1 V_30 )
{
unsigned V_42 ;
if ( F_9 ( V_1 ) )
return F_10 ( V_1 ) ;
for ( V_42 = 0 ; V_42 < V_30 ; V_42 ++ , V_18 ++ ) {
V_18 -> V_24 = F_29 ( V_1 ) ;
F_26 ( V_18 ) ;
}
return 0 ;
}
