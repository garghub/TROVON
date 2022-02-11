static int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( F_2 ( V_4 , 0 ) < 0 || F_3 ( V_4 , V_2 -> V_5 ) >= 0 )
return - V_6 ;
return F_4 ( V_3 , V_4 , V_2 -> V_7 , V_2 -> V_5 ) ;
}
static int F_5 ( const struct V_1 * V_2 , T_1 V_4 , T_1 V_3 )
{
if ( F_2 ( V_3 , 0 ) < 0 || F_3 ( V_3 , V_2 -> V_5 ) >= 0 )
return - V_6 ;
return F_4 ( V_4 , V_3 , V_2 -> V_8 , V_2 -> V_5 ) ;
}
static int F_6 ( const struct V_1 * V_2 , T_1 V_9 , T_1 V_4 )
{
if ( F_2 ( V_4 , 0 ) < 0 || F_3 ( V_4 , V_2 -> V_5 ) >= 0 )
return - V_6 ;
return F_4 ( V_9 , V_4 , V_2 -> V_8 , V_2 -> V_5 ) ;
}
static int F_7 ( const struct V_1 * V_2 , T_1 V_4 , T_1 V_9 )
{
if ( F_2 ( V_9 , 0 ) < 0 || F_3 ( V_9 , V_2 -> V_5 ) >= 0 )
return - V_6 ;
return F_4 ( V_4 , V_9 , V_2 -> V_7 , V_2 -> V_5 ) ;
}
static inline struct V_1 * F_8 ( struct V_10 * V_11 )
{
return F_9 ( V_11 ) ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_11 ( V_13 ) ;
const struct V_1 * V_14 = F_8 ( V_11 ) ;
T_1 V_4 , V_3 = F_12 ( 0 ) ;
int V_15 = 0 ;
int V_16 ;
if ( ! V_3 )
return - V_17 ;
if ( F_13 ( ! V_14 -> V_5 || ! V_14 -> V_7 ) ) {
V_15 = - V_6 ;
goto V_18;
}
if ( V_13 -> V_19 < F_14 ( V_14 -> V_5 ) ) {
V_13 -> V_19 = F_14 ( V_14 -> V_5 ) ;
V_15 = - V_20 ;
goto V_18;
}
V_4 = F_15 ( V_13 -> V_21 , V_13 -> V_22 ) ;
if ( ! V_4 ) {
V_15 = - V_17 ;
goto V_18;
}
V_15 = F_1 ( V_14 , V_3 , V_4 ) ;
if ( V_15 )
goto V_23;
V_15 = F_16 ( V_3 , V_13 -> V_24 , V_13 -> V_19 , & V_13 -> V_19 , & V_16 ) ;
if ( V_15 )
goto V_23;
if ( V_16 < 0 ) {
V_15 = - V_25 ;
goto V_23;
}
V_23:
F_17 ( V_4 ) ;
V_18:
F_17 ( V_3 ) ;
return V_15 ;
}
static int F_18 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_11 ( V_13 ) ;
const struct V_1 * V_14 = F_8 ( V_11 ) ;
T_1 V_3 , V_4 = F_12 ( 0 ) ;
int V_15 = 0 ;
int V_16 ;
if ( ! V_4 )
return - V_17 ;
if ( F_13 ( ! V_14 -> V_5 || ! V_14 -> V_8 ) ) {
V_15 = - V_6 ;
goto V_23;
}
if ( V_13 -> V_19 < F_14 ( V_14 -> V_5 ) ) {
V_13 -> V_19 = F_14 ( V_14 -> V_5 ) ;
V_15 = - V_20 ;
goto V_23;
}
V_3 = F_15 ( V_13 -> V_21 , V_13 -> V_22 ) ;
if ( ! V_3 ) {
V_15 = - V_17 ;
goto V_23;
}
V_15 = F_5 ( V_14 , V_4 , V_3 ) ;
if ( V_15 )
goto V_18;
V_15 = F_16 ( V_4 , V_13 -> V_24 , V_13 -> V_19 , & V_13 -> V_19 , & V_16 ) ;
if ( V_15 )
goto V_18;
if ( V_16 < 0 ) {
V_15 = - V_25 ;
goto V_18;
}
V_18:
F_17 ( V_3 ) ;
V_23:
F_17 ( V_4 ) ;
return V_15 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_11 ( V_13 ) ;
const struct V_1 * V_14 = F_8 ( V_11 ) ;
T_1 V_4 , V_9 = F_12 ( 0 ) ;
int V_15 = 0 ;
int V_16 ;
if ( ! V_9 )
return - V_17 ;
if ( F_13 ( ! V_14 -> V_5 || ! V_14 -> V_8 ) ) {
V_15 = - V_6 ;
goto V_26;
}
if ( V_13 -> V_19 < F_14 ( V_14 -> V_5 ) ) {
V_13 -> V_19 = F_14 ( V_14 -> V_5 ) ;
V_15 = - V_20 ;
goto V_26;
}
V_4 = F_15 ( V_13 -> V_21 , V_13 -> V_22 ) ;
if ( ! V_4 ) {
V_15 = - V_17 ;
goto V_26;
}
V_15 = F_6 ( V_14 , V_9 , V_4 ) ;
if ( V_15 )
goto V_23;
V_15 = F_16 ( V_9 , V_13 -> V_24 , V_13 -> V_19 , & V_13 -> V_19 , & V_16 ) ;
if ( V_15 )
goto V_23;
if ( V_16 < 0 ) {
V_15 = - V_25 ;
goto V_23;
}
V_23:
F_17 ( V_4 ) ;
V_26:
F_17 ( V_9 ) ;
return V_15 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_11 ( V_13 ) ;
const struct V_1 * V_14 = F_8 ( V_11 ) ;
T_1 V_9 , V_4 = F_12 ( 0 ) ;
int V_15 = 0 ;
int V_16 ;
if ( ! V_4 )
return - V_17 ;
if ( F_13 ( ! V_14 -> V_5 || ! V_14 -> V_7 ) ) {
V_15 = - V_6 ;
goto V_23;
}
if ( V_13 -> V_19 < F_14 ( V_14 -> V_5 ) ) {
V_13 -> V_19 = F_14 ( V_14 -> V_5 ) ;
V_15 = - V_20 ;
goto V_23;
}
V_9 = F_15 ( V_13 -> V_21 , V_13 -> V_22 ) ;
if ( ! V_9 ) {
V_15 = - V_17 ;
goto V_23;
}
V_15 = F_7 ( V_14 , V_4 , V_9 ) ;
if ( V_15 )
goto V_26;
V_15 = F_16 ( V_4 , V_13 -> V_24 , V_13 -> V_19 , & V_13 -> V_19 , & V_16 ) ;
if ( V_15 )
goto V_26;
if ( V_16 < 0 ) {
V_15 = - V_25 ;
goto V_26;
}
V_26:
F_17 ( V_9 ) ;
V_23:
F_17 ( V_4 ) ;
return V_15 ;
}
static int F_21 ( struct V_10 * V_11 , const void * V_2 ,
unsigned int V_27 )
{
struct V_1 * V_14 = F_9 ( V_11 ) ;
return F_22 ( V_14 , V_2 , V_27 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
struct V_1 * V_14 = F_9 ( V_11 ) ;
F_24 ( V_14 ) ;
}
static int F_25 ( void )
{
return F_26 ( & V_28 ) ;
}
static void F_27 ( void )
{
F_28 ( & V_28 ) ;
}
