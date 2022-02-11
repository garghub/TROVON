int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
if ( V_2 -> V_5 )
return - V_6 ;
if ( ! V_2 -> V_7 . V_8 )
return - V_9 ;
return V_2 -> V_7 . V_8 ( V_2 -> V_10 , V_3 , V_4 ) ;
}
static struct V_1 * F_2 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
F_3 ( & V_13 ) ;
F_4 (state, &smem_states, list) {
if ( V_2 -> V_14 == V_12 ) {
F_5 ( & V_2 -> V_15 ) ;
goto V_16;
}
}
V_2 = F_6 ( - V_17 ) ;
V_16:
F_7 ( & V_13 ) ;
return V_2 ;
}
struct V_1 * F_8 ( struct V_18 * V_19 ,
const char * V_20 ,
unsigned * V_21 )
{
struct V_1 * V_2 ;
struct V_22 args ;
int V_23 = 0 ;
int V_24 ;
if ( V_20 ) {
V_23 = F_9 ( V_19 -> V_14 ,
L_1 ,
V_20 ) ;
if ( V_23 < 0 ) {
F_10 ( V_19 , L_2 ) ;
return F_6 ( V_23 ) ;
}
}
V_24 = F_11 ( V_19 -> V_14 ,
L_3 ,
L_4 ,
V_23 ,
& args ) ;
if ( V_24 ) {
F_10 ( V_19 , L_5 ) ;
return F_6 ( V_24 ) ;
}
if ( args . V_25 != 1 ) {
F_10 ( V_19 , L_6 ) ;
return F_6 ( - V_26 ) ;
}
V_2 = F_2 ( args . V_12 ) ;
if ( F_12 ( V_2 ) )
goto V_27;
* V_21 = args . args [ 0 ] ;
V_27:
F_13 ( args . V_12 ) ;
return V_2 ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_15 ( V_29 , struct V_1 , V_15 ) ;
F_16 ( & V_2 -> V_30 ) ;
F_17 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_3 ( & V_13 ) ;
F_19 ( & V_2 -> V_15 , F_14 ) ;
F_7 ( & V_13 ) ;
}
struct V_1 * F_20 ( struct V_11 * V_14 ,
const struct V_31 * V_7 ,
void * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return F_6 ( - V_33 ) ;
F_22 ( & V_2 -> V_15 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_7 = * V_7 ;
V_2 -> V_10 = V_10 ;
F_3 ( & V_13 ) ;
F_23 ( & V_2 -> V_30 , & V_34 ) ;
F_7 ( & V_13 ) ;
return V_2 ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_5 = true ;
F_18 ( V_2 ) ;
}
