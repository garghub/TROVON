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
static inline int
F_14 ( const struct V_19 * V_20 )
{
if ( F_15 ( V_20 -> V_21 != 1 ) )
return - V_22 ;
return V_20 -> args [ 0 ] ;
}
int F_16 ( struct V_23 * V_24 , int V_25 )
{
struct V_19 args ;
struct V_1 * V_2 ;
struct V_26 V_27 ;
void * * V_28 ;
int V_29 ;
int V_5 ;
V_5 = F_17 ( V_24 , L_1 , L_2 , V_25 ,
& args ) ;
if ( V_5 )
return V_5 ;
V_5 = - V_30 ;
F_18 () ;
F_19 (slot, &hwspinlock_tree, &iter, 0 ) {
V_2 = F_20 ( V_28 ) ;
if ( F_21 ( ! V_2 ) )
continue;
if ( V_2 -> V_10 -> V_31 -> V_32 == args . V_24 ) {
V_5 = 0 ;
break;
}
}
F_22 () ;
if ( V_5 < 0 )
goto V_33;
V_29 = F_14 ( & args ) ;
if ( V_29 < 0 || V_29 >= V_2 -> V_10 -> V_34 ) {
V_5 = - V_22 ;
goto V_33;
}
V_29 += V_2 -> V_10 -> V_35 ;
V_33:
F_23 ( args . V_24 ) ;
return V_5 ? V_5 : V_29 ;
}
static int F_24 ( struct V_1 * V_2 , int V_29 )
{
struct V_1 * V_36 ;
int V_5 ;
F_25 ( & V_37 ) ;
V_5 = F_26 ( & V_38 , V_29 , V_2 ) ;
if ( V_5 ) {
if ( V_5 == - V_39 )
F_27 ( L_3 , V_29 ) ;
goto V_33;
}
V_36 = F_28 ( & V_38 , V_29 , V_40 ) ;
F_15 ( V_36 != V_2 ) ;
V_33:
F_29 ( & V_37 ) ;
return 0 ;
}
static struct V_1 * F_30 ( unsigned int V_29 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
F_25 ( & V_37 ) ;
V_5 = F_31 ( & V_38 , V_29 , V_40 ) ;
if ( V_5 == 0 ) {
F_27 ( L_4 , V_29 ) ;
goto V_33;
}
V_2 = F_32 ( & V_38 , V_29 ) ;
if ( ! V_2 ) {
F_27 ( L_5 , V_29 ) ;
goto V_33;
}
V_33:
F_29 ( & V_37 ) ;
return V_2 ;
}
int F_33 ( struct V_41 * V_10 , struct V_42 * V_31 ,
const struct V_43 * V_11 , int V_35 , int V_34 )
{
struct V_1 * V_2 ;
int V_5 = 0 , V_44 ;
if ( ! V_10 || ! V_11 || ! V_31 || ! V_34 || ! V_11 -> V_12 ||
! V_11 -> V_18 ) {
F_27 ( L_6 ) ;
return - V_22 ;
}
V_10 -> V_31 = V_31 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_35 = V_35 ;
V_10 -> V_34 = V_34 ;
for ( V_44 = 0 ; V_44 < V_34 ; V_44 ++ ) {
V_2 = & V_10 -> V_7 [ V_44 ] ;
F_34 ( & V_2 -> V_7 ) ;
V_2 -> V_10 = V_10 ;
V_5 = F_24 ( V_2 , V_35 + V_44 ) ;
if ( V_5 )
goto V_45;
}
return 0 ;
V_45:
while ( -- V_44 >= 0 )
F_30 ( V_35 + V_44 ) ;
return V_5 ;
}
int F_35 ( struct V_41 * V_10 )
{
struct V_1 * V_2 , * V_36 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_10 -> V_34 ; V_44 ++ ) {
V_2 = & V_10 -> V_7 [ V_44 ] ;
V_36 = F_30 ( V_10 -> V_35 + V_44 ) ;
if ( ! V_36 )
return - V_9 ;
F_15 ( V_36 != V_2 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_42 * V_31 = V_2 -> V_10 -> V_31 ;
struct V_1 * V_36 ;
int V_5 ;
if ( ! F_37 ( V_31 -> V_46 -> V_47 ) ) {
F_38 ( V_31 , L_7 , V_48 ) ;
return - V_22 ;
}
V_5 = F_39 ( V_31 ) ;
if ( V_5 < 0 ) {
F_38 ( V_31 , L_8 , V_48 ) ;
F_40 ( V_31 ) ;
F_41 ( V_31 -> V_46 -> V_47 ) ;
return V_5 ;
}
V_36 = F_42 ( & V_38 , F_43 ( V_2 ) ,
V_40 ) ;
F_15 ( V_36 != V_2 ) ;
return V_5 ;
}
int F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
F_27 ( L_9 ) ;
return - V_22 ;
}
return F_43 ( V_2 ) ;
}
struct V_1 * F_45 ( void )
{
struct V_1 * V_2 ;
int V_5 ;
F_25 ( & V_37 ) ;
V_5 = F_46 ( & V_38 , ( void * * ) & V_2 ,
0 , 1 , V_40 ) ;
if ( V_5 == 0 ) {
F_47 ( L_10 ) ;
V_2 = NULL ;
goto V_33;
}
F_15 ( V_5 > 1 ) ;
V_5 = F_36 ( V_2 ) ;
if ( V_5 < 0 )
V_2 = NULL ;
V_33:
F_29 ( & V_37 ) ;
return V_2 ;
}
struct V_1 * F_48 ( unsigned int V_29 )
{
struct V_1 * V_2 ;
int V_5 ;
F_25 ( & V_37 ) ;
V_2 = F_49 ( & V_38 , V_29 ) ;
if ( ! V_2 ) {
F_47 ( L_11 , V_29 ) ;
goto V_33;
}
F_15 ( F_43 ( V_2 ) != V_29 ) ;
V_5 = F_31 ( & V_38 , V_29 , V_40 ) ;
if ( V_5 == 0 ) {
F_47 ( L_12 , V_29 ) ;
V_2 = NULL ;
goto V_33;
}
V_5 = F_36 ( V_2 ) ;
if ( V_5 < 0 )
V_2 = NULL ;
V_33:
F_29 ( & V_37 ) ;
return V_2 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_42 * V_31 ;
struct V_1 * V_36 ;
int V_5 ;
if ( ! V_2 ) {
F_27 ( L_9 ) ;
return - V_22 ;
}
V_31 = V_2 -> V_10 -> V_31 ;
F_25 ( & V_37 ) ;
V_5 = F_31 ( & V_38 , F_43 ( V_2 ) ,
V_40 ) ;
if ( V_5 == 1 ) {
F_38 ( V_31 , L_13 , V_48 ) ;
F_51 () ;
V_5 = - V_22 ;
goto V_33;
}
V_5 = F_52 ( V_31 ) ;
if ( V_5 < 0 )
goto V_33;
V_36 = F_28 ( & V_38 , F_43 ( V_2 ) ,
V_40 ) ;
F_15 ( V_36 != V_2 ) ;
F_41 ( V_31 -> V_46 -> V_47 ) ;
V_33:
F_29 ( & V_37 ) ;
return V_5 ;
}
