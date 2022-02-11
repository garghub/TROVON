static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
switch ( V_5 -> type ) {
case V_6 :
switch ( V_4 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 6 :
return - V_7 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
return F_5 ( V_5 , V_8 + V_4 ,
V_9 , V_9 ) ;
}
static int F_6 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_10 ;
V_10 = F_7 ( V_5 , V_8 + V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 & V_11 )
return 1 ;
else
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
unsigned V_4 , int V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
return F_5 ( V_5 , V_8 + V_4 ,
V_9 , 0 ) ;
}
static void F_9 ( struct V_2 * V_3 , unsigned V_4 , int V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
F_5 ( V_5 , V_8 + V_4 , V_11 , V_12 ) ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( ! V_5 -> V_13 )
return - V_7 ;
return V_5 -> V_13 + V_4 ;
}
static void F_11 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_17 ; V_16 ++ ) {
int V_18 = V_16 + V_3 -> V_19 ;
int V_20 ;
const char * V_21 ;
V_21 = F_12 ( V_3 , V_16 ) ;
if ( ! V_21 )
V_21 = L_1 ;
F_13 ( V_15 , L_2 , V_18 , V_21 ) ;
V_20 = F_7 ( V_5 , V_8 + V_16 ) ;
if ( V_20 < 0 ) {
F_14 ( V_5 -> V_22 ,
L_3 ,
V_18 , V_20 ) ;
F_13 ( V_15 , L_4 ) ;
continue;
}
F_13 ( V_15 , L_5 , V_20 ) ;
}
}
static int T_1 F_15 ( struct V_23 * V_24 )
{
struct V_5 * V_5 = F_16 ( V_24 -> V_22 . V_25 ) ;
struct V_26 * V_27 = V_5 -> V_22 -> V_28 ;
struct V_1 * V_1 ;
int V_10 ;
V_1 = F_17 ( sizeof( * V_1 ) , V_29 ) ;
if ( V_1 == NULL )
return - V_30 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_2 = V_31 ;
V_1 -> V_2 . V_17 = V_32 ;
V_1 -> V_2 . V_22 = & V_24 -> V_22 ;
if ( V_27 && V_27 -> V_33 )
V_1 -> V_2 . V_19 = V_27 -> V_33 ;
else
V_1 -> V_2 . V_19 = - 1 ;
V_10 = F_18 ( & V_1 -> V_2 ) ;
if ( V_10 < 0 ) {
F_14 ( & V_24 -> V_22 , L_6 ,
V_10 ) ;
goto V_34;
}
F_19 ( V_24 , V_1 ) ;
return V_10 ;
V_34:
F_20 ( V_1 ) ;
return V_10 ;
}
static int T_2 F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_1 = F_22 ( V_24 ) ;
int V_10 ;
V_10 = F_23 ( & V_1 -> V_2 ) ;
if ( V_10 == 0 )
F_20 ( V_1 ) ;
return V_10 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_35 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_35 ) ;
}
