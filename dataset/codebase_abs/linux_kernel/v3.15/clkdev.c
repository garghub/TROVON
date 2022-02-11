struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 V_6 ;
struct V_1 * V_1 ;
int V_7 ;
if ( V_4 < 0 )
return F_2 ( - V_8 ) ;
V_7 = F_3 ( V_3 , L_1 , L_2 , V_4 ,
& V_6 ) ;
if ( V_7 )
return F_2 ( V_7 ) ;
F_4 () ;
V_1 = F_5 ( & V_6 ) ;
if ( ! F_6 ( V_1 ) && ! F_7 ( V_1 ) )
V_1 = F_2 ( - V_9 ) ;
F_8 () ;
F_9 ( V_6 . V_3 ) ;
return V_1 ;
}
struct V_1 * F_10 ( struct V_2 * V_3 , const char * V_10 )
{
struct V_1 * V_1 = F_2 ( - V_9 ) ;
while ( V_3 ) {
int V_4 = 0 ;
if ( V_10 )
V_4 = F_11 ( V_3 , L_3 , V_10 ) ;
V_1 = F_1 ( V_3 , V_4 ) ;
if ( ! F_6 ( V_1 ) )
break;
else if ( V_10 && V_4 >= 0 ) {
F_12 ( L_4 ,
V_3 -> V_11 , V_10 ? V_10 : L_5 , V_4 ) ;
return V_1 ;
}
V_3 = V_3 -> V_12 ;
if ( V_3 && ! F_13 ( V_3 , L_6 , NULL ) )
break;
}
return V_1 ;
}
static struct V_13 * F_14 ( const char * V_14 , const char * V_15 )
{
struct V_13 * V_16 , * V_17 = NULL ;
int V_18 , V_19 = 0 , V_20 = 0 ;
if ( V_14 )
V_20 += 2 ;
if ( V_15 )
V_20 += 1 ;
F_15 (p, &clocks, node) {
V_18 = 0 ;
if ( V_16 -> V_14 ) {
if ( ! V_14 || strcmp ( V_16 -> V_14 , V_14 ) )
continue;
V_18 += 2 ;
}
if ( V_16 -> V_15 ) {
if ( ! V_15 || strcmp ( V_16 -> V_15 , V_15 ) )
continue;
V_18 += 1 ;
}
if ( V_18 > V_19 ) {
V_17 = V_16 ;
if ( V_18 != V_20 )
V_19 = V_18 ;
else
break;
}
}
return V_17 ;
}
struct V_1 * F_16 ( const char * V_14 , const char * V_15 )
{
struct V_13 * V_17 ;
F_17 ( & V_21 ) ;
V_17 = F_14 ( V_14 , V_15 ) ;
if ( V_17 && ! F_7 ( V_17 -> V_1 ) )
V_17 = NULL ;
F_18 ( & V_21 ) ;
return V_17 ? V_17 -> V_1 : F_2 ( - V_9 ) ;
}
struct V_1 * F_19 ( struct V_22 * V_23 , const char * V_15 )
{
const char * V_14 = V_23 ? F_20 ( V_23 ) : NULL ;
struct V_1 * V_1 ;
if ( V_23 ) {
V_1 = F_10 ( V_23 -> V_24 , V_15 ) ;
if ( ! F_6 ( V_1 ) )
return V_1 ;
if ( F_21 ( V_1 ) == - V_25 )
return V_1 ;
}
return F_16 ( V_14 , V_15 ) ;
}
void F_22 ( struct V_1 * V_1 )
{
F_23 ( V_1 ) ;
}
void F_24 ( struct V_13 * V_17 )
{
F_17 ( & V_21 ) ;
F_25 ( & V_17 -> V_26 , & V_27 ) ;
F_18 ( & V_21 ) ;
}
void T_1 F_26 ( struct V_13 * V_17 , T_2 V_28 )
{
F_17 ( & V_21 ) ;
while ( V_28 -- ) {
F_25 ( & V_17 -> V_26 , & V_27 ) ;
V_17 ++ ;
}
F_18 ( & V_21 ) ;
}
static struct V_13 * T_3
F_27 ( struct V_1 * V_1 , const char * V_15 , const char * V_29 ,
T_4 V_30 )
{
struct V_31 * V_32 ;
V_32 = F_28 ( sizeof( * V_32 ) ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_17 . V_1 = V_1 ;
if ( V_15 ) {
F_29 ( V_32 -> V_15 , V_15 , sizeof( V_32 -> V_15 ) ) ;
V_32 -> V_17 . V_15 = V_32 -> V_15 ;
}
if ( V_29 ) {
F_30 ( V_32 -> V_14 , sizeof( V_32 -> V_14 ) , V_29 , V_30 ) ;
V_32 -> V_17 . V_14 = V_32 -> V_14 ;
}
return & V_32 -> V_17 ;
}
struct V_13 * T_3
F_31 ( struct V_1 * V_1 , const char * V_15 , const char * V_29 , ... )
{
struct V_13 * V_17 ;
T_4 V_30 ;
va_start ( V_30 , V_29 ) ;
V_17 = F_27 ( V_1 , V_15 , V_29 , V_30 ) ;
va_end ( V_30 ) ;
return V_17 ;
}
int F_32 ( const char * V_33 , const char * V_34 , char * V_35 ,
struct V_22 * V_23 )
{
struct V_1 * V_36 = F_19 ( V_23 , V_35 ) ;
struct V_13 * V_37 ;
if ( F_6 ( V_36 ) )
return F_21 ( V_36 ) ;
V_37 = F_31 ( V_36 , V_33 , V_34 ) ;
F_22 ( V_36 ) ;
if ( ! V_37 )
return - V_38 ;
F_24 ( V_37 ) ;
return 0 ;
}
void F_33 ( struct V_13 * V_17 )
{
F_17 ( & V_21 ) ;
F_34 ( & V_17 -> V_26 ) ;
F_18 ( & V_21 ) ;
F_35 ( V_17 ) ;
}
int F_36 ( struct V_1 * V_1 , const char * V_15 ,
const char * V_29 , ... )
{
struct V_13 * V_17 ;
T_4 V_30 ;
if ( F_6 ( V_1 ) )
return F_21 ( V_1 ) ;
va_start ( V_30 , V_29 ) ;
V_17 = F_27 ( V_1 , V_15 , V_29 , V_30 ) ;
va_end ( V_30 ) ;
if ( ! V_17 )
return - V_39 ;
F_24 ( V_17 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 , struct V_13 * V_17 , T_2 V_28 )
{
unsigned V_40 ;
if ( F_6 ( V_1 ) )
return F_21 ( V_1 ) ;
for ( V_40 = 0 ; V_40 < V_28 ; V_40 ++ , V_17 ++ ) {
V_17 -> V_1 = V_1 ;
F_24 ( V_17 ) ;
}
return 0 ;
}
