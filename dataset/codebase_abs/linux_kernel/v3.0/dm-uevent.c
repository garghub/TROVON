static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 ) ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_3 , V_6 ) ;
if ( ! V_2 )
return NULL ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_5 = V_5 ;
return V_2 ;
}
static struct V_1 * F_6 ( struct V_4 * V_5 ,
struct V_8 * V_9 ,
enum V_10 V_11 ,
const char * V_12 ,
const char * V_13 ,
unsigned V_14 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_5 ) ;
if ( ! V_2 ) {
F_7 ( L_1 , V_15 ) ;
goto V_16;
}
V_2 -> V_11 = V_11 ;
if ( F_8 ( & V_2 -> V_17 , L_2 , V_9 -> type -> V_18 ) ) {
F_7 ( L_3 ,
V_15 ) ;
goto V_19;
}
if ( F_8 ( & V_2 -> V_17 , L_4 , V_12 ) ) {
F_7 ( L_5 ,
V_15 ) ;
goto V_19;
}
if ( F_8 ( & V_2 -> V_17 , L_6 ,
F_9 ( V_5 ) ) ) {
F_7 ( L_7 ,
V_15 ) ;
goto V_19;
}
if ( F_8 ( & V_2 -> V_17 , L_8 , V_13 ) ) {
F_7 ( L_9 , V_15 ) ;
goto V_19;
}
if ( F_8 ( & V_2 -> V_17 , L_10 ,
V_14 ) ) {
F_7 ( L_11 ,
V_15 ) ;
goto V_19;
}
return V_2 ;
V_19:
F_1 ( V_2 ) ;
V_16:
return F_10 ( - V_20 ) ;
}
void F_11 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
int V_25 ;
struct V_1 * V_2 , * V_26 ;
F_12 (event, next, events, elist) {
F_13 ( & V_2 -> V_7 ) ;
if ( F_14 ( V_2 -> V_5 , V_2 -> V_18 ,
V_2 -> V_27 ) ) {
F_15 ( L_12 ,
V_15 ) ;
goto V_28;
}
if ( F_8 ( & V_2 -> V_17 , L_13 , V_2 -> V_18 ) ) {
F_7 ( L_14 ,
V_15 ) ;
goto V_28;
}
if ( F_8 ( & V_2 -> V_17 , L_15 , V_2 -> V_27 ) ) {
F_7 ( L_16 ,
V_15 ) ;
goto V_28;
}
V_25 = F_16 ( V_24 , V_2 -> V_11 , V_2 -> V_17 . V_29 ) ;
if ( V_25 )
F_7 ( L_17 , V_15 ) ;
V_28:
F_1 ( V_2 ) ;
}
}
void F_17 ( enum V_30 V_31 , struct V_8 * V_9 ,
const char * V_13 , unsigned V_14 )
{
struct V_4 * V_5 = F_18 ( V_9 -> V_32 ) ;
struct V_1 * V_2 ;
if ( V_31 >= F_19 ( V_33 ) ) {
F_7 ( L_18 , V_15 , V_31 ) ;
return;
}
V_2 = F_6 ( V_5 , V_9 ,
V_33 [ V_31 ] . V_11 ,
V_33 [ V_31 ] . V_18 ,
V_13 , V_14 ) ;
if ( F_20 ( V_2 ) )
return;
F_21 ( V_5 , & V_2 -> V_7 ) ;
}
int F_22 ( void )
{
V_3 = F_23 ( V_1 , 0 ) ;
if ( ! V_3 )
return - V_20 ;
F_15 ( L_19 ) ;
return 0 ;
}
void F_24 ( void )
{
F_25 ( V_3 ) ;
}
