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
static void F_10 ( struct V_11 * V_10 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
struct V_12 * V_13 = V_4 -> V_14 ;
F_11 ( V_10 , L_1 , V_18 ) ;
if ( V_13 && V_13 -> V_19 )
V_13 -> V_19 ( V_4 ) ;
}
int F_12 ( struct V_12 * V_13 )
{
V_13 -> V_14 . V_20 = V_13 -> V_20 ;
V_13 -> V_14 . V_21 = & V_22 ;
return F_13 ( & V_13 -> V_14 ) ;
}
void F_14 ( struct V_12 * V_13 )
{
F_15 ( & V_13 -> V_14 ) ;
}
void F_16 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_21 = & V_22 ;
}
static int F_17 ( struct V_11 * V_10 , struct V_23 * V_24 )
{
struct V_3 * V_4 = F_8 ( V_10 ) ;
struct V_12 * V_13 = F_7 ( V_24 ) ;
const struct V_1 * V_2 = V_13 -> V_17 ;
const struct V_1 * V_25 ;
if ( ! V_2 )
goto V_26;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( V_25 )
return 1 ;
V_26: return 0 ;
}
static int F_18 ( struct V_11 * V_10 , struct V_27 * V_28 )
{
struct V_3 * V_4 ;
if ( ! V_10 )
return - V_15 ;
V_4 = F_8 ( V_10 ) ;
if ( ! V_4 )
return - V_15 ;
if ( F_19 ( V_28 , L_2 ,
V_4 -> V_5 , V_4 -> V_8 , V_4 -> V_6 , V_4 -> V_9 ) )
return - V_29 ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_30 ;
V_30 = F_21 ( & V_31 ) ;
if ( ! V_30 ) {
V_30 = F_22 ( & V_22 ) ;
if ( V_30 )
F_23 ( & V_31 ) ;
}
return V_30 ;
}
