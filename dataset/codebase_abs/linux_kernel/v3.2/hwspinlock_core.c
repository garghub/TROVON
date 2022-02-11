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
V_5 = V_2 -> V_10 -> V_11 -> V_12 ( V_2 ) ;
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
int F_10 ( struct V_1 * V_2 , unsigned int V_13 ,
int V_3 , unsigned long * V_4 )
{
int V_5 ;
unsigned long V_14 ;
V_14 = F_11 ( V_13 ) + V_15 ;
for (; ; ) {
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_5 != - V_9 )
break;
if ( F_12 ( V_14 ) )
return - V_16 ;
if ( V_2 -> V_10 -> V_11 -> V_17 )
V_2 -> V_10 -> V_11 -> V_17 ( V_2 ) ;
}
return V_5 ;
}
void F_13 ( struct V_1 * V_2 , int V_3 , unsigned long * V_4 )
{
F_2 ( ! V_2 ) ;
F_2 ( ! V_4 && V_3 == V_6 ) ;
F_9 () ;
V_2 -> V_10 -> V_11 -> V_18 ( V_2 ) ;
if ( V_3 == V_6 )
F_6 ( & V_2 -> V_7 , * V_4 ) ;
else if ( V_3 == V_8 )
F_7 ( & V_2 -> V_7 ) ;
else
F_8 ( & V_2 -> V_7 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_19 )
{
struct V_1 * V_20 ;
int V_5 ;
F_15 ( & V_21 ) ;
V_5 = F_16 ( & V_22 , V_19 , V_2 ) ;
if ( V_5 ) {
if ( V_5 == - V_23 )
F_17 ( L_1 , V_19 ) ;
goto V_24;
}
V_20 = F_18 ( & V_22 , V_19 , V_25 ) ;
F_19 ( V_20 != V_2 ) ;
V_24:
F_20 ( & V_21 ) ;
return 0 ;
}
static struct V_1 * F_21 ( unsigned int V_19 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
F_15 ( & V_21 ) ;
V_5 = F_22 ( & V_22 , V_19 , V_25 ) ;
if ( V_5 == 0 ) {
F_17 ( L_2 , V_19 ) ;
goto V_24;
}
V_2 = F_23 ( & V_22 , V_19 ) ;
if ( ! V_2 ) {
F_17 ( L_3 , V_19 ) ;
goto V_24;
}
V_24:
F_20 ( & V_21 ) ;
return V_2 ;
}
int F_24 ( struct V_26 * V_10 , struct V_27 * V_28 ,
const struct V_29 * V_11 , int V_30 , int V_31 )
{
struct V_1 * V_2 ;
int V_5 = 0 , V_32 ;
if ( ! V_10 || ! V_11 || ! V_28 || ! V_31 || ! V_11 -> V_12 ||
! V_11 -> V_18 ) {
F_17 ( L_4 ) ;
return - V_33 ;
}
V_10 -> V_28 = V_28 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_30 = V_30 ;
V_10 -> V_31 = V_31 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_2 = & V_10 -> V_7 [ V_32 ] ;
F_25 ( & V_2 -> V_7 ) ;
V_2 -> V_10 = V_10 ;
V_5 = F_14 ( V_2 , V_32 ) ;
if ( V_5 )
goto V_34;
}
return 0 ;
V_34:
while ( -- V_32 >= 0 )
F_21 ( V_32 ) ;
return V_5 ;
}
int F_26 ( struct V_26 * V_10 )
{
struct V_1 * V_2 , * V_20 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_10 -> V_31 ; V_32 ++ ) {
V_2 = & V_10 -> V_7 [ V_32 ] ;
V_20 = F_21 ( V_10 -> V_30 + V_32 ) ;
if ( ! V_20 )
return - V_9 ;
F_19 ( V_20 != V_2 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_10 -> V_28 ;
struct V_1 * V_20 ;
int V_5 ;
if ( ! F_28 ( V_28 -> V_35 -> V_36 ) ) {
F_29 ( V_28 , L_5 , V_37 ) ;
return - V_33 ;
}
V_5 = F_30 ( V_28 ) ;
if ( V_5 < 0 ) {
F_29 ( V_28 , L_6 , V_37 ) ;
return V_5 ;
}
V_20 = F_31 ( & V_22 , F_32 ( V_2 ) ,
V_25 ) ;
F_19 ( V_20 != V_2 ) ;
return V_5 ;
}
int F_33 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
F_17 ( L_7 ) ;
return - V_33 ;
}
return F_32 ( V_2 ) ;
}
struct V_1 * F_34 ( void )
{
struct V_1 * V_2 ;
int V_5 ;
F_15 ( & V_21 ) ;
V_5 = F_35 ( & V_22 , ( void * * ) & V_2 ,
0 , 1 , V_25 ) ;
if ( V_5 == 0 ) {
F_36 ( L_8 ) ;
V_2 = NULL ;
goto V_24;
}
F_19 ( V_5 > 1 ) ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 < 0 )
V_2 = NULL ;
V_24:
F_20 ( & V_21 ) ;
return V_2 ;
}
struct V_1 * F_37 ( unsigned int V_19 )
{
struct V_1 * V_2 ;
int V_5 ;
F_15 ( & V_21 ) ;
V_2 = F_38 ( & V_22 , V_19 ) ;
if ( ! V_2 ) {
F_36 ( L_9 , V_19 ) ;
goto V_24;
}
F_19 ( F_32 ( V_2 ) != V_19 ) ;
V_5 = F_22 ( & V_22 , V_19 , V_25 ) ;
if ( V_5 == 0 ) {
F_36 ( L_10 , V_19 ) ;
V_2 = NULL ;
goto V_24;
}
V_5 = F_27 ( V_2 ) ;
if ( V_5 < 0 )
V_2 = NULL ;
V_24:
F_20 ( & V_21 ) ;
return V_2 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_10 -> V_28 ;
struct V_1 * V_20 ;
int V_5 ;
if ( ! V_2 ) {
F_17 ( L_7 ) ;
return - V_33 ;
}
F_15 ( & V_21 ) ;
V_5 = F_22 ( & V_22 , F_32 ( V_2 ) ,
V_25 ) ;
if ( V_5 == 1 ) {
F_29 ( V_28 , L_11 , V_37 ) ;
F_40 () ;
V_5 = - V_33 ;
goto V_24;
}
V_5 = F_41 ( V_28 ) ;
if ( V_5 < 0 )
goto V_24;
V_20 = F_18 ( & V_22 , F_32 ( V_2 ) ,
V_25 ) ;
F_19 ( V_20 != V_2 ) ;
F_42 ( V_28 -> V_35 -> V_36 ) ;
V_24:
F_20 ( & V_21 ) ;
return V_5 ;
}
