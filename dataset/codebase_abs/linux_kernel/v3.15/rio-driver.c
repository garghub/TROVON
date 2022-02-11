static const struct V_1 * F_1 ( const struct V_1
* V_2 ,
const struct V_3 * V_4 )
{
while ( V_2 -> V_5 || V_2 -> V_6 ) {
if ( ( ( V_2 -> V_5 == V_7 ) || ( V_2 -> V_5 == V_4 -> V_5 ) ) &&
( ( V_2 -> V_8 == V_7 ) || ( V_2 -> V_8 == V_4 -> V_8 ) ) &&
( ( V_2 -> V_6 == V_7 )
|| ( V_2 -> V_6 == V_4 -> V_6 ) )
&& ( ( V_2 -> V_9 == V_7 )
|| ( V_2 -> V_9 == V_4 -> V_9 ) ) )
return V_2 ;
V_2 ++ ;
}
return NULL ;
}
struct V_3 * F_2 ( struct V_3 * V_4 )
{
if ( V_4 )
F_3 ( & V_4 -> V_10 ) ;
return V_4 ;
}
void F_4 ( struct V_3 * V_4 )
{
if ( V_4 )
F_5 ( & V_4 -> V_10 ) ;
}
static int F_6 ( struct V_11 * V_10 )
{
struct V_12 * V_13 = F_7 ( V_10 -> V_14 ) ;
struct V_3 * V_4 = F_8 ( V_10 ) ;
int error = - V_15 ;
const struct V_1 * V_2 ;
if ( ! V_4 -> V_14 && V_13 -> V_16 ) {
if ( ! V_13 -> V_17 )
return error ;
V_2 = F_1 ( V_13 -> V_17 , V_4 ) ;
F_2 ( V_4 ) ;
if ( V_2 )
error = V_13 -> V_16 ( V_4 , V_2 ) ;
if ( error >= 0 ) {
V_4 -> V_14 = V_13 ;
error = 0 ;
} else
F_4 ( V_4 ) ;
}
return error ;
}
static int F_9 ( struct V_11 * V_10 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_4 -> V_14 ;
if ( V_13 ) {
if ( V_13 -> remove )
V_13 -> remove ( V_4 ) ;
V_4 -> V_14 = NULL ;
}
F_4 ( V_4 ) ;
return 0 ;
}
int F_10 ( struct V_12 * V_13 )
{
V_13 -> V_14 . V_18 = V_13 -> V_18 ;
V_13 -> V_14 . V_19 = & V_20 ;
return F_11 ( & V_13 -> V_14 ) ;
}
void F_12 ( struct V_12 * V_13 )
{
F_13 ( & V_13 -> V_14 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_19 = & V_20 ;
}
static int F_15 ( struct V_11 * V_10 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
struct V_12 * V_13 = F_7 ( V_22 ) ;
const struct V_1 * V_2 = V_13 -> V_17 ;
const struct V_1 * V_23 ;
if ( ! V_2 )
goto V_24;
V_23 = F_1 ( V_2 , V_4 ) ;
if ( V_23 )
return 1 ;
V_24: return 0 ;
}
static int F_16 ( struct V_11 * V_10 , struct V_25 * V_26 )
{
struct V_3 * V_4 ;
if ( ! V_10 )
return - V_15 ;
V_4 = F_8 ( V_10 ) ;
if ( ! V_4 )
return - V_15 ;
if ( F_17 ( V_26 , L_1 ,
V_4 -> V_5 , V_4 -> V_8 , V_4 -> V_6 , V_4 -> V_9 ) )
return - V_27 ;
return 0 ;
}
static int T_1 F_18 ( void )
{
int V_28 ;
V_28 = F_19 ( & V_29 ) ;
if ( ! V_28 ) {
V_28 = F_20 ( & V_20 ) ;
if ( V_28 )
F_21 ( & V_29 ) ;
}
return V_28 ;
}
