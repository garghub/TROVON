static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
unsigned long V_6 ;
int V_7 ;
if ( ! V_2 || ! V_5 )
return - V_8 ;
F_2 ( & V_2 -> V_9 . V_10 , V_6 ) ;
if ( F_3 ( V_2 , V_2 -> V_9 . V_11 ,
L_1 ) ) {
F_4 ( & V_2 -> V_9 . V_10 , V_6 ) ;
return - V_12 ;
}
V_7 = F_5 ( V_2 , V_5 ) ;
if ( ! V_7 )
V_2 -> V_9 . V_11 = V_5 ;
F_4 ( & V_2 -> V_9 . V_10 , V_6 ) ;
return V_7 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_7 ;
if ( V_3 < 0 )
return - V_8 ;
V_5 = F_7 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return - V_14 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_7 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_7 )
F_8 ( V_5 ) ;
return V_7 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
unsigned long V_6 ;
if ( ! V_5 )
return;
F_2 ( & V_2 -> V_9 . V_10 , V_6 ) ;
F_10 ( V_2 ) ;
V_2 -> V_9 . V_11 = NULL ;
F_4 ( & V_2 -> V_9 . V_10 , V_6 ) ;
if ( V_5 -> V_15 & V_16 ) {
F_11 ( V_5 -> V_3 , V_5 ) ;
V_5 -> V_15 &= ~ V_17 ;
}
F_8 ( V_5 ) ;
}
static T_1 F_12 ( int V_3 , void * V_18 )
{
struct V_4 * V_5 = V_18 ;
int V_19 ;
if ( F_13 ( F_14 ( V_3 ) ) ) {
F_15 ( V_5 -> V_2 , 0 ) ;
return V_20 ;
}
V_19 = F_16 ( V_5 -> V_2 ) ;
if ( V_19 < 0 )
F_17 ( V_5 -> V_2 ,
L_2 , V_19 ) ;
return V_20 ;
}
int F_18 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_7 ;
if ( V_3 < 0 )
return - V_8 ;
V_5 = F_7 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return - V_14 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
F_19 ( V_3 , V_21 ) ;
F_19 ( V_3 , V_22 ) ;
V_7 = F_20 ( V_3 , NULL , F_12 ,
V_23 , F_21 ( V_2 ) , V_5 ) ;
if ( V_7 )
goto V_24;
V_7 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_7 )
goto V_25;
V_5 -> V_15 = V_16 ;
return V_7 ;
V_25:
F_11 ( V_3 , V_5 ) ;
V_24:
F_8 ( V_5 ) ;
return V_7 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
if ( V_5 && ( V_5 -> V_15 & V_16 ) )
F_23 ( V_5 -> V_3 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
if ( V_5 && ( V_5 -> V_15 & V_16 ) )
F_25 ( V_5 -> V_3 ) ;
}
void F_26 ( struct V_1 * V_2 ,
bool V_26 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
if ( ! V_5 || ! ( ( V_5 -> V_15 & V_17 ) ) )
return;
if ( F_27 ( V_5 -> V_15 & V_27 ) ) {
goto V_28;
} else if ( V_26 ) {
V_5 -> V_15 |= V_27 ;
goto V_28;
}
return;
V_28:
F_23 ( V_5 -> V_3 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_9 . V_11 ;
if ( ! V_5 || ! ( ( V_5 -> V_15 & V_17 ) ) )
return;
if ( V_5 -> V_15 & V_27 )
F_25 ( V_5 -> V_3 ) ;
}
void F_29 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
if ( F_30 ( V_5 -> V_2 ) ) {
if ( V_5 -> V_15 & V_16 )
F_23 ( V_5 -> V_3 ) ;
F_31 ( V_5 -> V_3 ) ;
}
}
void F_32 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
if ( F_30 ( V_5 -> V_2 ) ) {
F_33 ( V_5 -> V_3 ) ;
if ( V_5 -> V_15 & V_16 )
F_25 ( V_5 -> V_3 ) ;
}
}
