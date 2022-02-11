static inline int F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_3 = ( F_2 ( V_5 -> V_7 ) & 0x7F ) * V_8 ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_13 = F_5 ( V_12 ) ;
struct V_4 * V_5 = V_13 -> V_6 ;
unsigned int V_14 = 0 ;
V_14 = F_2 ( V_5 -> V_7 ) ;
F_6 ( V_14 & ~ V_5 -> V_15 , V_5 -> V_7 ) ;
F_7 ( V_5 -> V_16 ) ;
F_8 ( V_10 , L_1 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_13 = F_5 ( V_12 ) ;
struct V_4 * V_5 = V_13 -> V_6 ;
unsigned int V_14 = 0 ;
int V_17 = 0 ;
V_17 = F_10 ( V_5 -> V_16 ) ;
if ( V_17 ) {
F_11 ( & V_12 -> V_10 , L_2 ) ;
return V_17 ;
}
V_14 = F_2 ( V_5 -> V_7 ) ;
F_6 ( V_14 | V_5 -> V_15 , V_5 -> V_7 ) ;
F_8 ( V_10 , L_3 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_13 = NULL ;
struct V_4 * V_5 ;
struct V_18 * V_19 = V_12 -> V_10 . V_20 ;
struct V_21 * V_22 ;
int V_17 = 0 , V_23 ;
if ( ! V_19 || ! F_13 ( V_19 , L_4 , & V_23 ) ) {
F_11 ( & V_12 -> V_10 , L_5 ) ;
return - V_24 ;
}
V_5 = F_14 ( & V_12 -> V_10 , sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return - V_26 ;
V_22 = F_15 ( V_12 , V_27 , 0 ) ;
V_5 -> V_7 = F_16 ( & V_12 -> V_10 , V_22 ) ;
if ( F_17 ( V_5 -> V_7 ) )
return F_18 ( V_5 -> V_7 ) ;
V_5 -> V_16 = F_19 ( & V_12 -> V_10 , NULL ) ;
if ( F_17 ( V_5 -> V_16 ) ) {
F_11 ( & V_12 -> V_10 , L_6 ) ;
return F_18 ( V_5 -> V_16 ) ;
}
V_17 = F_10 ( V_5 -> V_16 ) ;
if ( V_17 ) {
F_11 ( & V_12 -> V_10 , L_2 ) ;
return V_17 ;
}
V_5 -> V_15 = V_23 ;
F_6 ( V_5 -> V_15 , V_5 -> V_7 ) ;
V_13 = F_20 ( L_7 , 0 , 0 ,
V_5 , & V_28 , NULL , 0 , 0 ) ;
if ( F_17 ( V_13 ) ) {
F_11 ( & V_12 -> V_10 , L_8 ) ;
V_17 = F_18 ( V_13 ) ;
goto V_29;
}
F_21 ( V_12 , V_13 ) ;
F_8 ( & V_13 -> V_9 , L_9 ,
V_5 -> V_7 ) ;
return 0 ;
V_29:
F_7 ( V_5 -> V_16 ) ;
return V_17 ;
}
static int F_22 ( struct V_11 * V_12 )
{
unsigned int V_14 = 0 ;
struct V_1 * V_13 = F_5 ( V_12 ) ;
struct V_4 * V_5 = V_13 -> V_6 ;
F_23 ( V_13 ) ;
V_14 = F_2 ( V_5 -> V_7 ) ;
F_6 ( V_14 & ~ V_5 -> V_15 , V_5 -> V_7 ) ;
F_7 ( V_5 -> V_16 ) ;
return 0 ;
}
