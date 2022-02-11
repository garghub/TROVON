int F_1 ( struct V_1 * V_2 , int V_3 , unsigned long * V_4 )
{
int V_5 ;
F_2 ( ! V_2 ) ;
F_2 ( ! V_4 && V_3 == V_6 ) ;
if ( V_3 == V_6 )
V_5 = F_3 ( & V_2 -> V_7 , * V_4 ) ;
else if ( V_3 == V_8 )
V_5 = F_4 ( & V_2 -> V_7 ) ;
else
V_5 = F_5 ( & V_2 -> V_7 ) ;
if ( ! V_5 )
return - V_9 ;
V_5 = V_2 -> V_10 -> V_11 ( V_2 ) ;
if ( ! V_5 ) {
if ( V_3 == V_6 )
F_6 ( & V_2 -> V_7 , * V_4 ) ;
else if ( V_3 == V_8 )
F_7 ( & V_2 -> V_7 ) ;
else
F_8 ( & V_2 -> V_7 ) ;
return - V_9 ;
}
F_9 () ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_12 ,
int V_3 , unsigned long * V_4 )
{
int V_5 ;
unsigned long V_13 ;
V_13 = F_11 ( V_12 ) + V_14 ;
for (; ; ) {
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - V_9 )
break;
if ( F_12 ( V_13 ) )
return - V_15 ;
if ( V_2 -> V_10 -> V_16 )
V_2 -> V_10 -> V_16 ( V_2 ) ;
}
return V_5 ;
}
void F_13 ( struct V_1 * V_2 , int V_3 , unsigned long * V_4 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! V_4 && V_3 == V_6 ) ;
F_9 () ;
V_2 -> V_10 -> V_17 ( V_2 ) ;
if ( V_3 == V_6 )
F_6 ( & V_2 -> V_7 , * V_4 ) ;
else if ( V_3 == V_8 )
F_7 ( & V_2 -> V_7 ) ;
else
F_8 ( & V_2 -> V_7 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
int V_5 ;
if ( ! V_2 || ! V_2 -> V_10 ||
! V_2 -> V_10 -> V_11 || ! V_2 -> V_10 -> V_17 ) {
F_15 ( L_1 ) ;
return - V_19 ;
}
F_16 ( & V_2 -> V_7 ) ;
F_17 ( & V_20 ) ;
V_5 = F_18 ( & V_21 , V_2 -> V_22 , V_2 ) ;
if ( V_5 )
goto V_23;
V_18 = F_19 ( & V_21 , V_2 -> V_22 ,
V_24 ) ;
F_20 ( V_18 != V_2 ) ;
V_23:
F_8 ( & V_20 ) ;
return V_5 ;
}
struct V_1 * F_21 ( unsigned int V_22 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
F_17 ( & V_20 ) ;
V_5 = F_22 ( & V_21 , V_22 , V_24 ) ;
if ( V_5 == 0 ) {
F_15 ( L_2 , V_22 ) ;
goto V_23;
}
V_2 = F_23 ( & V_21 , V_22 ) ;
if ( ! V_2 ) {
F_15 ( L_3 , V_22 ) ;
goto V_23;
}
V_23:
F_8 ( & V_20 ) ;
return V_2 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
int V_5 ;
if ( ! F_25 ( V_2 -> V_25 ) ) {
F_26 ( V_2 -> V_26 , L_4 , V_27 ) ;
return - V_19 ;
}
V_5 = F_27 ( V_2 -> V_26 ) ;
if ( V_5 < 0 ) {
F_26 ( V_2 -> V_26 , L_5 , V_27 ) ;
return V_5 ;
}
V_18 = F_28 ( & V_21 , V_2 -> V_22 ,
V_24 ) ;
F_20 ( V_18 != V_2 ) ;
return V_5 ;
}
int F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
F_15 ( L_6 ) ;
return - V_19 ;
}
return V_2 -> V_22 ;
}
struct V_1 * F_30 ( void )
{
struct V_1 * V_2 ;
int V_5 ;
F_17 ( & V_20 ) ;
V_5 = F_31 ( & V_21 , ( void * * ) & V_2 ,
0 , 1 , V_24 ) ;
if ( V_5 == 0 ) {
F_32 ( L_7 ) ;
V_2 = NULL ;
goto V_23;
}
F_20 ( V_5 > 1 ) ;
V_5 = F_24 ( V_2 ) ;
if ( V_5 < 0 )
V_2 = NULL ;
V_23:
F_8 ( & V_20 ) ;
return V_2 ;
}
struct V_1 * F_33 ( unsigned int V_22 )
{
struct V_1 * V_2 ;
int V_5 ;
F_17 ( & V_20 ) ;
V_2 = F_34 ( & V_21 , V_22 ) ;
if ( ! V_2 ) {
F_32 ( L_8 , V_22 ) ;
goto V_23;
}
F_20 ( V_2 -> V_22 != V_22 ) ;
V_5 = F_22 ( & V_21 , V_22 , V_24 ) ;
if ( V_5 == 0 ) {
F_32 ( L_9 , V_22 ) ;
V_2 = NULL ;
goto V_23;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 < 0 )
V_2 = NULL ;
V_23:
F_8 ( & V_20 ) ;
return V_2 ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_1 * V_18 ;
int V_5 ;
if ( ! V_2 ) {
F_15 ( L_6 ) ;
return - V_19 ;
}
F_17 ( & V_20 ) ;
V_5 = F_22 ( & V_21 , V_2 -> V_22 ,
V_24 ) ;
if ( V_5 == 1 ) {
F_26 ( V_2 -> V_26 , L_10 , V_27 ) ;
F_36 () ;
V_5 = - V_19 ;
goto V_23;
}
V_5 = F_37 ( V_2 -> V_26 ) ;
if ( V_5 < 0 )
goto V_23;
V_18 = F_19 ( & V_21 , V_2 -> V_22 ,
V_24 ) ;
F_20 ( V_18 != V_2 ) ;
F_38 ( V_2 -> V_25 ) ;
V_23:
F_8 ( & V_20 ) ;
return V_5 ;
}
