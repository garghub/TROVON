static struct V_1 * F_1 ( unsigned long V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static void F_3 ( struct V_1 * V_5 )
{
V_5 -> V_6 ++ ;
}
static void F_4 ( struct V_1 * V_5 )
{
if ( -- V_5 -> V_6 == 0 ) {
unsigned long V_7 ;
F_5 ( V_5 -> V_2 , 0 , 0 , & V_7 ) ;
V_5 -> V_8 = V_5 -> V_9 = 0 ;
}
}
int F_6 ( unsigned long V_2 , unsigned long V_8 ,
unsigned long * V_9 )
{
struct V_1 * V_5 ;
unsigned long V_10 ;
int V_11 ;
F_7 ( & V_12 , V_10 ) ;
V_5 = F_1 ( V_2 ) ;
V_11 = - V_13 ;
if ( V_5 ) {
if ( V_5 -> V_6 ) {
V_11 = - V_13 ;
if ( V_5 -> V_8 == V_8 ) {
* V_9 = V_5 -> V_9 ;
V_11 = 0 ;
}
} else {
unsigned long V_14 ;
unsigned long V_15 ;
V_15 = F_5 ( V_2 , V_8 , * V_9 ,
& V_14 ) ;
V_11 = - V_13 ;
if ( V_15 == V_16 ) {
* V_9 = V_14 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_9 = V_14 ;
V_11 = 0 ;
} else if ( V_15 == V_17 ||
V_15 == V_18 ) {
if ( V_5 -> V_10 & V_19 ) {
if ( V_8 == 1 ) {
V_5 -> V_8 = 1 ;
V_5 -> V_9 = 0 ;
* V_9 = 0 ;
V_11 = 0 ;
}
}
}
}
if ( V_11 == 0 )
F_3 ( V_5 ) ;
}
F_8 ( & V_12 , V_10 ) ;
return V_11 ;
}
void F_9 ( unsigned long V_2 )
{
struct V_1 * V_5 ;
unsigned long V_10 ;
F_7 ( & V_12 , V_10 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
F_4 ( V_5 ) ;
F_8 ( & V_12 , V_10 ) ;
}
int F_10 ( unsigned long V_2 ,
unsigned long * V_8 ,
unsigned long * V_9 )
{
struct V_1 * V_5 ;
unsigned long V_10 ;
int V_11 ;
F_7 ( & V_12 , V_10 ) ;
V_11 = - V_13 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 && V_5 -> V_6 ) {
* V_8 = V_5 -> V_8 ;
* V_9 = V_5 -> V_9 ;
V_11 = 0 ;
}
F_8 ( & V_12 , V_10 ) ;
return V_11 ;
}
void T_1 F_11 ( void )
{
unsigned long V_2 , V_8 , V_9 ;
V_2 = V_20 ;
V_8 = 1 ;
V_9 = 0 ;
if ( F_6 ( V_2 , V_8 , & V_9 ) )
goto V_21;
V_2 = V_22 ;
V_8 = 1 ;
V_9 = 1 ;
if ( F_6 ( V_2 , V_8 , & V_9 ) )
goto V_21;
return;
V_21:
F_12 ( L_1
L_2 ,
V_2 , V_8 , V_9 ) ;
F_13 () ;
}
