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
V_1 = F_18 ( F_19 ( V_18 -> V_1 ) , V_5 , V_6 ) ;
if ( F_9 ( V_1 ) )
goto V_23;
if ( ! F_20 ( V_1 ) ) {
F_21 ( V_1 ) ;
V_18 = NULL ;
goto V_23;
}
V_23:
F_22 ( & V_22 ) ;
return V_18 ? V_1 : F_2 ( - V_13 ) ;
}
struct V_1 * F_23 ( struct V_24 * V_25 , const char * V_6 )
{
const char * V_5 = V_25 ? F_24 ( V_25 ) : NULL ;
struct V_1 * V_1 ;
if ( V_25 ) {
V_1 = F_7 ( V_25 -> V_26 , V_5 , V_6 ) ;
if ( ! F_9 ( V_1 ) || F_10 ( V_1 ) == - V_14 )
return V_1 ;
}
return F_16 ( V_5 , V_6 ) ;
}
void F_25 ( struct V_1 * V_1 )
{
F_26 ( V_1 ) ;
}
void F_27 ( struct V_16 * V_18 )
{
F_17 ( & V_22 ) ;
F_28 ( & V_18 -> V_27 , & V_28 ) ;
F_22 ( & V_22 ) ;
}
void T_1 F_29 ( struct V_16 * V_18 , T_2 V_29 )
{
F_17 ( & V_22 ) ;
while ( V_29 -- ) {
F_28 ( & V_18 -> V_27 , & V_28 ) ;
V_18 ++ ;
}
F_22 ( & V_22 ) ;
}
static struct V_16 * T_3
F_30 ( struct V_1 * V_1 , const char * V_6 , const char * V_30 ,
T_4 V_31 )
{
struct V_32 * V_33 ;
V_33 = F_31 ( sizeof( * V_33 ) ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_18 . V_1 = V_1 ;
if ( V_6 ) {
F_32 ( V_33 -> V_6 , V_6 , sizeof( V_33 -> V_6 ) ) ;
V_33 -> V_18 . V_6 = V_33 -> V_6 ;
}
if ( V_30 ) {
F_33 ( V_33 -> V_5 , sizeof( V_33 -> V_5 ) , V_30 , V_31 ) ;
V_33 -> V_18 . V_5 = V_33 -> V_5 ;
}
return & V_33 -> V_18 ;
}
struct V_16 * T_3
F_34 ( struct V_1 * V_1 , const char * V_6 , const char * V_30 , ... )
{
struct V_16 * V_18 ;
T_4 V_31 ;
va_start ( V_31 , V_30 ) ;
V_18 = F_30 ( V_1 , V_6 , V_30 , V_31 ) ;
va_end ( V_31 ) ;
return V_18 ;
}
int F_35 ( const char * V_34 , const char * V_35 , char * V_36 ,
struct V_24 * V_25 )
{
struct V_1 * V_37 = F_23 ( V_25 , V_36 ) ;
struct V_16 * V_38 ;
if ( F_9 ( V_37 ) )
return F_10 ( V_37 ) ;
V_38 = F_34 ( V_37 , V_34 , V_35 ) ;
F_25 ( V_37 ) ;
if ( ! V_38 )
return - V_39 ;
F_27 ( V_38 ) ;
return 0 ;
}
void F_36 ( struct V_16 * V_18 )
{
F_17 ( & V_22 ) ;
F_37 ( & V_18 -> V_27 ) ;
F_22 ( & V_22 ) ;
F_38 ( V_18 ) ;
}
int F_39 ( struct V_1 * V_1 , const char * V_6 ,
const char * V_30 , ... )
{
struct V_16 * V_18 ;
T_4 V_31 ;
if ( F_9 ( V_1 ) )
return F_10 ( V_1 ) ;
va_start ( V_31 , V_30 ) ;
V_18 = F_30 ( V_1 , V_6 , V_30 , V_31 ) ;
va_end ( V_31 ) ;
if ( ! V_18 )
return - V_40 ;
F_27 ( V_18 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_1 , struct V_16 * V_18 , T_2 V_29 )
{
unsigned V_41 ;
if ( F_9 ( V_1 ) )
return F_10 ( V_1 ) ;
for ( V_41 = 0 ; V_41 < V_29 ; V_41 ++ , V_18 ++ ) {
V_18 -> V_1 = V_1 ;
F_27 ( V_18 ) ;
}
return 0 ;
}
