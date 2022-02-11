static struct V_1 * F_1 ( struct V_2 * V_3 ,
const char * V_4 , const char * V_5 )
{
struct V_1 * V_1 ;
if ( ! V_3 )
return F_2 ( - V_6 ) ;
F_3 () ;
V_1 = F_4 ( V_3 , V_4 , V_5 ) ;
F_5 () ;
return V_1 ;
}
struct V_1 * F_6 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , NULL , V_7 ) ;
}
static struct V_1 * F_7 ( struct V_8 * V_9 , int V_10 ,
const char * V_4 , const char * V_5 )
{
struct V_2 V_3 ;
struct V_1 * V_1 ;
int V_11 ;
if ( V_10 < 0 )
return F_2 ( - V_6 ) ;
V_11 = F_8 ( V_9 , L_1 , L_2 , V_10 ,
& V_3 ) ;
if ( V_11 )
return F_2 ( V_11 ) ;
V_1 = F_1 ( & V_3 , V_4 , V_5 ) ;
F_9 ( V_3 . V_9 ) ;
return V_1 ;
}
struct V_1 * F_10 ( struct V_8 * V_9 , int V_10 )
{
return F_7 ( V_9 , V_10 , V_9 -> V_12 , NULL ) ;
}
static struct V_1 * F_11 ( struct V_8 * V_9 ,
const char * V_4 ,
const char * V_13 )
{
struct V_1 * V_1 = F_2 ( - V_14 ) ;
while ( V_9 ) {
int V_10 = 0 ;
if ( V_13 )
V_10 = F_12 ( V_9 , L_3 , V_13 ) ;
V_1 = F_7 ( V_9 , V_10 , V_4 , V_13 ) ;
if ( ! F_13 ( V_1 ) ) {
break;
} else if ( V_13 && V_10 >= 0 ) {
if ( F_14 ( V_1 ) != - V_15 )
F_15 ( L_4 ,
V_9 -> V_12 , V_13 ? V_13 : L_5 , V_10 ) ;
return V_1 ;
}
V_9 = V_9 -> V_16 ;
if ( V_9 && ! F_16 ( V_9 , L_6 , NULL ) )
break;
}
return V_1 ;
}
struct V_1 * F_17 ( struct V_8 * V_9 , const char * V_13 )
{
if ( ! V_9 )
return F_2 ( - V_14 ) ;
return F_11 ( V_9 , V_9 -> V_12 , V_13 ) ;
}
static struct V_1 * F_11 ( struct V_8 * V_9 ,
const char * V_4 ,
const char * V_13 )
{
return F_2 ( - V_14 ) ;
}
static struct V_17 * F_18 ( const char * V_4 , const char * V_5 )
{
struct V_17 * V_18 , * V_19 = NULL ;
int V_20 , V_21 = 0 , V_22 = 0 ;
if ( V_4 )
V_22 += 2 ;
if ( V_5 )
V_22 += 1 ;
F_19 (p, &clocks, node) {
V_20 = 0 ;
if ( V_18 -> V_4 ) {
if ( ! V_4 || strcmp ( V_18 -> V_4 , V_4 ) )
continue;
V_20 += 2 ;
}
if ( V_18 -> V_5 ) {
if ( ! V_5 || strcmp ( V_18 -> V_5 , V_5 ) )
continue;
V_20 += 1 ;
}
if ( V_20 > V_21 ) {
V_19 = V_18 ;
if ( V_20 != V_22 )
V_21 = V_20 ;
else
break;
}
}
return V_19 ;
}
struct V_1 * F_20 ( const char * V_4 , const char * V_5 )
{
struct V_17 * V_19 ;
struct V_1 * V_1 = NULL ;
F_21 ( & V_23 ) ;
V_19 = F_18 ( V_4 , V_5 ) ;
if ( ! V_19 )
goto V_24;
V_1 = F_22 ( F_23 ( V_19 -> V_1 ) , V_4 , V_5 ) ;
if ( F_13 ( V_1 ) )
goto V_24;
if ( ! F_24 ( V_1 ) ) {
F_25 ( V_1 ) ;
V_19 = NULL ;
goto V_24;
}
V_24:
F_26 ( & V_23 ) ;
return V_19 ? V_1 : F_2 ( - V_14 ) ;
}
struct V_1 * F_27 ( struct V_25 * V_26 , const char * V_5 )
{
const char * V_4 = V_26 ? F_28 ( V_26 ) : NULL ;
struct V_1 * V_1 ;
if ( V_26 ) {
V_1 = F_11 ( V_26 -> V_27 , V_4 , V_5 ) ;
if ( ! F_13 ( V_1 ) || F_14 ( V_1 ) == - V_15 )
return V_1 ;
}
return F_20 ( V_4 , V_5 ) ;
}
void F_29 ( struct V_1 * V_1 )
{
F_30 ( V_1 ) ;
}
void F_31 ( struct V_17 * V_19 )
{
F_21 ( & V_23 ) ;
F_32 ( & V_19 -> V_28 , & V_29 ) ;
F_26 ( & V_23 ) ;
}
void T_1 F_33 ( struct V_17 * V_19 , T_2 V_30 )
{
F_21 ( & V_23 ) ;
while ( V_30 -- ) {
F_32 ( & V_19 -> V_28 , & V_29 ) ;
V_19 ++ ;
}
F_26 ( & V_23 ) ;
}
static struct V_17 * T_3
F_34 ( struct V_1 * V_1 , const char * V_5 , const char * V_31 ,
T_4 V_32 )
{
struct V_33 * V_34 ;
V_34 = F_35 ( sizeof( * V_34 ) ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_19 . V_1 = V_1 ;
if ( V_5 ) {
F_36 ( V_34 -> V_5 , V_5 , sizeof( V_34 -> V_5 ) ) ;
V_34 -> V_19 . V_5 = V_34 -> V_5 ;
}
if ( V_31 ) {
F_37 ( V_34 -> V_4 , sizeof( V_34 -> V_4 ) , V_31 , V_32 ) ;
V_34 -> V_19 . V_4 = V_34 -> V_4 ;
}
return & V_34 -> V_19 ;
}
struct V_17 * T_3
F_38 ( struct V_1 * V_1 , const char * V_5 , const char * V_31 , ... )
{
struct V_17 * V_19 ;
T_4 V_32 ;
va_start ( V_32 , V_31 ) ;
V_19 = F_34 ( V_1 , V_5 , V_31 , V_32 ) ;
va_end ( V_32 ) ;
return V_19 ;
}
int F_39 ( const char * V_35 , const char * V_36 , char * V_37 ,
struct V_25 * V_26 )
{
struct V_1 * V_38 = F_27 ( V_26 , V_37 ) ;
struct V_17 * V_39 ;
if ( F_13 ( V_38 ) )
return F_14 ( V_38 ) ;
V_39 = F_38 ( V_38 , V_35 , V_36 ) ;
F_29 ( V_38 ) ;
if ( ! V_39 )
return - V_40 ;
F_31 ( V_39 ) ;
return 0 ;
}
void F_40 ( struct V_17 * V_19 )
{
F_21 ( & V_23 ) ;
F_41 ( & V_19 -> V_28 ) ;
F_26 ( & V_23 ) ;
F_42 ( V_19 ) ;
}
int F_43 ( struct V_1 * V_1 , const char * V_5 ,
const char * V_31 , ... )
{
struct V_17 * V_19 ;
T_4 V_32 ;
if ( F_13 ( V_1 ) )
return F_14 ( V_1 ) ;
va_start ( V_32 , V_31 ) ;
V_19 = F_34 ( V_1 , V_5 , V_31 , V_32 ) ;
va_end ( V_32 ) ;
if ( ! V_19 )
return - V_41 ;
F_31 ( V_19 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_1 , struct V_17 * V_19 , T_2 V_30 )
{
unsigned V_42 ;
if ( F_13 ( V_1 ) )
return F_14 ( V_1 ) ;
for ( V_42 = 0 ; V_42 < V_30 ; V_42 ++ , V_19 ++ ) {
V_19 -> V_1 = V_1 ;
F_31 ( V_19 ) ;
}
return 0 ;
}
