static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 )
return - V_6 ;
memcpy ( V_4 , V_5 , sizeof( * V_5 ) ) ;
return 0 ;
}
static int
F_3 ( struct V_7 * V_8 , unsigned int V_9 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_8 , V_10 , V_9 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int
F_5 ( struct V_7 * V_8 , unsigned int V_11 , unsigned int V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_6 ( V_8 -> V_16 , V_11 ) ;
if ( F_7 ( V_14 ) )
return F_8 ( V_14 ) ;
V_15 = F_9 ( V_14 , V_12 ) ;
if ( V_15 ) {
F_10 ( V_14 ) ;
return V_15 ;
}
V_15 = F_11 ( V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_15 )
return 0 ;
return F_12 ( V_8 ) ;
}
static int
F_13 ( struct V_17 * V_17 , unsigned int V_9 ,
unsigned int V_18 )
{
struct V_7 * V_8 = F_14 ( V_17 ) ;
struct V_3 V_5 ;
int V_15 ;
if ( V_18 < 2 )
return - V_6 ;
F_15 ( & V_8 -> V_19 ) ;
F_16 () ;
V_15 = F_3 ( V_8 , V_9 , & V_5 ) ;
F_17 () ;
if ( V_15 )
goto V_20;
if ( V_5 . V_21 || V_5 . V_22 % V_18 ) {
V_15 = - V_6 ;
goto V_20;
}
V_15 = F_5 ( V_8 , V_5 . V_23 ,
V_5 . V_22 / V_18 ) ;
V_20:
F_18 ( & V_8 -> V_19 ) ;
return V_15 ;
}
static int
F_19 ( struct V_17 * V_17 , unsigned int V_9 )
{
struct V_7 * V_8 = F_14 ( V_17 ) ;
struct V_3 V_5 ;
int V_15 ;
F_15 ( & V_8 -> V_19 ) ;
F_16 () ;
V_15 = F_3 ( V_8 , V_9 , & V_5 ) ;
F_17 () ;
if ( V_15 )
goto V_20;
if ( ! V_5 . V_21 ) {
V_15 = - V_6 ;
goto V_20;
}
V_15 = F_5 ( V_8 , V_5 . V_23 , V_5 . V_22 ) ;
V_20:
F_18 ( & V_8 -> V_19 ) ;
return V_15 ;
}
static int F_20 ( struct V_17 * V_17 , T_1 * V_24 )
{
struct V_7 * V_8 = F_14 ( V_17 ) ;
int V_15 ;
F_15 ( & V_8 -> V_19 ) ;
if ( ! V_8 -> V_25 ) {
V_15 = - V_26 ;
goto V_20;
}
V_15 = F_21 ( V_8 -> V_25 , V_24 ) ;
V_20:
F_18 ( & V_8 -> V_19 ) ;
return V_15 ;
}
int F_22 ( struct V_27 * V_25 , struct V_1 * V_2 )
{
struct V_3 V_5 ;
struct V_17 * V_17 ;
int V_15 ;
F_16 () ;
V_15 = F_1 ( V_2 , & V_5 ) ;
F_17 () ;
if ( V_15 )
return V_15 ;
F_23 ( & V_2 -> V_28 , V_2 -> V_29 ) ;
if ( V_5 . V_21 )
F_24 ( & V_2 -> V_28 , V_5 . V_30 ) ;
V_17 = F_25 ( V_25 -> V_8 ) ;
return F_26 ( V_17 , & V_2 -> V_28 , V_2 -> V_31 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_28 ) ;
}
