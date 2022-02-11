static inline int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
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
struct V_21 * V_22 = F_13 ( V_12 , V_23 , 0 ) ;
int V_17 = 0 , V_24 ;
if ( ! V_19 || ! F_14 ( V_19 , L_4 , & V_24 ) ) {
F_11 ( & V_12 -> V_10 , L_5 ) ;
return - V_25 ;
}
if ( ! V_22 ) {
F_11 ( & V_12 -> V_10 , L_6 ) ;
return - V_26 ;
}
V_5 = F_15 ( & V_12 -> V_10 , sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 ) {
F_11 ( & V_12 -> V_10 , L_7 ) ;
return - V_28 ;
}
V_5 -> V_7 = F_16 ( & V_12 -> V_10 , V_22 -> V_29 ,
F_17 ( V_22 ) ) ;
if ( ! V_5 -> V_7 ) {
F_11 ( & V_12 -> V_10 , L_8 ) ;
return - V_28 ;
}
V_5 -> V_16 = F_18 ( & V_12 -> V_10 , NULL ) ;
if ( F_19 ( V_5 -> V_16 ) ) {
F_11 ( & V_12 -> V_10 , L_9 ) ;
return F_20 ( V_5 -> V_16 ) ;
}
V_17 = F_10 ( V_5 -> V_16 ) ;
if ( V_17 ) {
F_11 ( & V_12 -> V_10 , L_2 ) ;
goto V_30;
}
V_5 -> V_15 = V_24 ;
F_6 ( V_5 -> V_15 , V_5 -> V_7 ) ;
V_13 = F_21 ( L_10 , 0 , 0 ,
V_5 , & V_31 , 0 , 0 ) ;
if ( F_19 ( V_13 ) ) {
F_11 ( & V_12 -> V_10 , L_11 ) ;
V_17 = F_20 ( V_13 ) ;
goto V_32;
}
F_22 ( V_12 , V_13 ) ;
F_8 ( & V_13 -> V_9 , L_12 ,
V_5 -> V_7 ) ;
return 0 ;
V_32:
F_7 ( V_5 -> V_16 ) ;
V_30:
F_23 ( V_5 -> V_16 ) ;
return V_17 ;
}
static int F_24 ( struct V_11 * V_12 )
{
unsigned int V_14 = 0 ;
struct V_1 * V_13 = F_5 ( V_12 ) ;
struct V_4 * V_5 = V_13 -> V_6 ;
F_25 ( V_13 ) ;
F_22 ( V_12 , NULL ) ;
V_14 = F_2 ( V_5 -> V_7 ) ;
F_6 ( V_14 & ~ V_5 -> V_15 , V_5 -> V_7 ) ;
F_7 ( V_5 -> V_16 ) ;
F_23 ( V_5 -> V_16 ) ;
return 0 ;
}
