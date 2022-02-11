static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
F_3 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 != V_8 ) {
V_5 = - V_9 ;
goto V_10;
}
if ( V_4 -> V_11 -> V_12 )
V_5 = V_4 -> V_11 -> V_12 ( V_4 -> V_13 , V_14 ) ;
V_4 -> V_7 = V_14 ;
V_10:
F_4 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
F_3 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_11 -> V_12 )
V_5 = V_4 -> V_11 -> V_12 ( V_4 -> V_13 , V_8 ) ;
V_4 -> V_7 = V_8 ;
F_4 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( ! V_4 -> V_11 -> V_17 ) {
V_5 = - V_18 ;
goto V_19;
}
if ( V_4 -> V_7 != V_14 ) {
V_5 = - V_20 ;
goto V_19;
}
V_5 = V_4 -> V_11 -> V_17 ( V_4 -> V_13 , V_16 ) ;
if ( V_5 < 0 )
F_7 ( V_16 ) ;
V_19:
return V_5 ;
}
int F_8 ( void * V_13 , struct V_21 * V_22 ,
struct V_23 * V_11 , unsigned int V_24 ,
struct V_1 * * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_9 ( V_22 , sizeof( struct V_3 ) , V_25 ) ;
if ( ! V_4 ) {
V_5 = - V_26 ;
goto V_27;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_24 = V_24 ;
F_10 ( & V_4 -> V_28 . V_29 , V_30 ) ;
F_11 ( & V_4 -> V_28 . V_31 ) ;
F_12 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_11 -> V_12 ) {
V_5 = V_4 -> V_11 -> V_12 ( V_4 -> V_13 , V_8 ) ;
if ( V_5 < 0 )
goto V_27;
}
V_4 -> V_7 = V_8 ;
V_4 -> V_2 = F_13 ( & V_32 , V_33 ,
V_34 , 0 ) ;
if ( ! V_4 -> V_2 ) {
V_5 = - V_26 ;
goto V_27;
}
F_14 ( V_4 -> V_2 , V_22 ) ;
F_15 ( V_4 -> V_2 , V_4 ) ;
V_5 = F_16 ( V_4 -> V_2 ) ;
if ( V_5 < 0 )
goto V_35;
* V_2 = V_4 -> V_2 ;
goto V_27;
V_35:
F_17 ( V_4 -> V_2 ) ;
V_27:
return V_5 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_7 == V_36 )
F_19 ( V_4 , - V_37 ) ;
F_20 ( & V_4 -> V_28 . V_29 ) ;
F_3 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_11 -> V_12 )
V_4 -> V_11 -> V_12 ( V_4 -> V_13 , V_8 ) ;
F_21 ( V_2 ) ;
F_17 ( V_2 ) ;
F_4 ( & V_4 -> V_6 ) ;
}
