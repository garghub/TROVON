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
V_15 = - V_17 ;
V_4 = F_14 ( V_13 -> V_19 , V_13 -> V_20 ) ;
if ( ! V_4 )
goto V_18;
V_15 = F_1 ( V_14 , V_3 , V_4 ) ;
if ( V_15 )
goto V_21;
V_15 = F_15 ( V_3 , V_13 -> V_22 , V_13 -> V_23 , & V_16 ) ;
if ( V_15 )
goto V_21;
if ( V_16 < 0 )
V_15 = - V_24 ;
V_21:
F_16 ( V_4 ) ;
V_18:
F_16 ( V_3 ) ;
return V_15 ;
}
static int F_17 ( struct V_12 * V_13 )
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
goto V_21;
}
V_15 = - V_17 ;
V_3 = F_14 ( V_13 -> V_19 , V_13 -> V_20 ) ;
if ( ! V_3 )
goto V_21;
V_15 = F_5 ( V_14 , V_4 , V_3 ) ;
if ( V_15 )
goto V_18;
V_15 = F_15 ( V_4 , V_13 -> V_22 , V_13 -> V_23 , & V_16 ) ;
if ( V_15 )
goto V_18;
if ( V_16 < 0 )
V_15 = - V_24 ;
V_18:
F_16 ( V_3 ) ;
V_21:
F_16 ( V_4 ) ;
return V_15 ;
}
static int F_18 ( struct V_12 * V_13 )
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
goto V_25;
}
V_15 = - V_17 ;
V_4 = F_14 ( V_13 -> V_19 , V_13 -> V_20 ) ;
if ( ! V_4 )
goto V_25;
V_15 = F_6 ( V_14 , V_9 , V_4 ) ;
if ( V_15 )
goto V_21;
V_15 = F_15 ( V_9 , V_13 -> V_22 , V_13 -> V_23 , & V_16 ) ;
if ( V_15 )
goto V_21;
if ( V_16 < 0 )
V_15 = - V_24 ;
V_21:
F_16 ( V_4 ) ;
V_25:
F_16 ( V_9 ) ;
return V_15 ;
}
static int F_19 ( struct V_12 * V_13 )
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
goto V_21;
}
V_15 = - V_17 ;
V_9 = F_14 ( V_13 -> V_19 , V_13 -> V_20 ) ;
if ( ! V_9 ) {
V_15 = - V_17 ;
goto V_21;
}
V_15 = F_7 ( V_14 , V_4 , V_9 ) ;
if ( V_15 )
goto V_25;
V_15 = F_15 ( V_4 , V_13 -> V_22 , V_13 -> V_23 , & V_16 ) ;
if ( V_15 )
goto V_25;
if ( V_16 < 0 )
V_15 = - V_24 ;
V_25:
F_16 ( V_9 ) ;
V_21:
F_16 ( V_4 ) ;
return V_15 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_8 ) ;
F_16 ( V_2 -> V_7 ) ;
F_16 ( V_2 -> V_5 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_5 = NULL ;
}
static int F_21 ( unsigned int V_26 )
{
switch ( V_26 ) {
case 512 :
case 1024 :
case 1536 :
case 2048 :
case 3072 :
case 4096 :
return 0 ;
}
return - V_6 ;
}
static int F_22 ( struct V_10 * V_11 , const void * V_2 ,
unsigned int V_27 )
{
struct V_1 * V_28 = F_9 ( V_11 ) ;
struct V_29 V_30 = { 0 } ;
int V_15 ;
F_20 ( V_28 ) ;
V_15 = F_23 ( & V_30 , V_2 , V_27 ) ;
if ( V_15 )
return V_15 ;
V_28 -> V_7 = F_24 ( V_30 . V_7 , V_30 . V_31 ) ;
if ( ! V_28 -> V_7 )
goto V_32;
V_28 -> V_5 = F_24 ( V_30 . V_5 , V_30 . V_33 ) ;
if ( ! V_28 -> V_5 )
goto V_32;
if ( F_21 ( F_25 ( V_28 -> V_5 ) << 3 ) ) {
F_20 ( V_28 ) ;
return - V_6 ;
}
return 0 ;
V_32:
F_20 ( V_28 ) ;
return - V_17 ;
}
static int F_26 ( struct V_10 * V_11 , const void * V_2 ,
unsigned int V_27 )
{
struct V_1 * V_28 = F_9 ( V_11 ) ;
struct V_29 V_30 = { 0 } ;
int V_15 ;
F_20 ( V_28 ) ;
V_15 = F_27 ( & V_30 , V_2 , V_27 ) ;
if ( V_15 )
return V_15 ;
V_28 -> V_8 = F_24 ( V_30 . V_8 , V_30 . V_34 ) ;
if ( ! V_28 -> V_8 )
goto V_32;
V_28 -> V_7 = F_24 ( V_30 . V_7 , V_30 . V_31 ) ;
if ( ! V_28 -> V_7 )
goto V_32;
V_28 -> V_5 = F_24 ( V_30 . V_5 , V_30 . V_33 ) ;
if ( ! V_28 -> V_5 )
goto V_32;
if ( F_21 ( F_25 ( V_28 -> V_5 ) << 3 ) ) {
F_20 ( V_28 ) ;
return - V_6 ;
}
return 0 ;
V_32:
F_20 ( V_28 ) ;
return - V_17 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_1 * V_14 = F_9 ( V_11 ) ;
return V_14 -> V_5 ? F_25 ( V_14 -> V_5 ) : - V_6 ;
}
static void F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_14 = F_9 ( V_11 ) ;
F_20 ( V_14 ) ;
}
static int F_30 ( void )
{
int V_32 ;
V_32 = F_31 ( & V_35 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_32 ( & V_36 ) ;
if ( V_32 ) {
F_33 ( & V_35 ) ;
return V_32 ;
}
return 0 ;
}
static void F_34 ( void )
{
F_35 ( & V_36 ) ;
F_33 ( & V_35 ) ;
}
