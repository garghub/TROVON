static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ? V_5 : V_6 ;
}
static unsigned long F_2 ( struct V_1 * V_2 , unsigned long V_7 )
{
if ( ! V_2 -> V_3 . V_4 )
return V_7 ;
if ( V_7 == V_8 )
V_7 = V_9 ;
else if ( V_7 == V_10 )
V_7 = V_11 ;
return V_7 ;
}
static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_6 ;
}
static unsigned long F_2 ( struct V_1 * V_2 , unsigned long V_7 )
{
return V_7 ;
}
int F_3 ( void )
{
F_4 () ;
return 0 ;
}
int F_5 ( void )
{
F_6 () ;
return 0 ;
}
static unsigned long F_7 ( unsigned long V_12 , unsigned long V_7 )
{
return F_8 ( V_12 , V_7 ) ;
}
static int F_9 ( unsigned long V_12 , unsigned long V_13 ,
unsigned long V_14 , bool V_15 )
{
unsigned long V_16 ;
if ( F_10 ( V_17 ) ) {
V_13 = F_11 ( V_13 ) ;
V_14 = F_11 ( V_14 ) ;
} else {
V_13 = F_12 ( V_13 ) ;
V_14 = F_12 ( V_14 ) ;
}
if ( V_15 ) {
if ( F_13 ( & V_16 , ( void * ) V_12 , V_18 ) )
return - V_19 ;
if ( V_16 != V_13 )
return - V_20 ;
}
if ( F_14 ( ( void * ) V_12 , & V_14 , V_18 ) )
return - V_21 ;
F_15 ( V_12 , V_12 + V_18 ) ;
return 0 ;
}
int F_16 ( T_1 V_22 )
{
unsigned long V_12 ;
unsigned long V_14 ;
int V_23 ;
V_12 = ( unsigned long ) & V_24 ;
V_14 = F_7 ( V_12 , ( unsigned long ) V_22 ) ;
V_23 = F_9 ( V_12 , 0 , V_14 , false ) ;
#ifdef F_17
if ( ! V_23 ) {
V_12 = ( unsigned long ) & V_25 ;
V_14 = F_7 ( V_12 , ( unsigned long ) V_22 ) ;
V_23 = F_9 ( V_12 , 0 , V_14 , false ) ;
}
#endif
return V_23 ;
}
int F_18 ( struct V_1 * V_2 , unsigned long V_7 )
{
unsigned long V_14 , V_13 ;
unsigned long V_26 = V_2 -> V_26 ;
V_13 = F_1 ( V_2 ) ;
V_14 = F_7 ( V_26 , F_2 ( V_2 , V_7 ) ) ;
return F_9 ( V_2 -> V_26 , V_13 , V_14 , true ) ;
}
int F_19 ( struct V_27 * V_28 ,
struct V_1 * V_2 , unsigned long V_7 )
{
unsigned long V_26 = V_2 -> V_26 ;
unsigned long V_13 ;
unsigned long V_14 ;
int V_23 ;
V_13 = F_7 ( V_26 , F_2 ( V_2 , V_7 ) ) ;
V_14 = F_1 ( V_2 ) ;
V_23 = F_9 ( V_26 , V_13 , V_14 , true ) ;
#ifdef F_17
if ( V_23 == - V_20 && V_7 == V_8 ) {
V_2 -> V_3 . V_4 = true ;
V_13 = F_7 ( V_26 , F_2 ( V_2 , V_7 ) ) ;
V_14 = F_1 ( V_2 ) ;
V_23 = F_9 ( V_26 , V_13 , V_14 , true ) ;
}
#endif
return V_23 ;
}
int T_2 F_20 ( void )
{
return 0 ;
}
void F_21 ( unsigned long * V_29 , unsigned long V_30 ,
unsigned long V_31 )
{
unsigned long V_32 = ( unsigned long ) & V_33 ;
struct V_34 V_35 ;
unsigned long V_13 ;
int V_36 ;
if ( F_22 ( F_23 ( & V_37 -> V_38 ) ) )
return;
V_13 = * V_29 ;
* V_29 = V_32 ;
V_35 . V_22 = V_30 ;
V_35 . V_39 = V_37 -> V_40 + 1 ;
if ( ! F_24 ( & V_35 ) ) {
* V_29 = V_13 ;
return;
}
V_36 = F_25 ( V_13 , V_30 , & V_35 . V_39 ,
V_31 ) ;
if ( V_36 == - V_41 ) {
* V_29 = V_13 ;
return;
}
}
static int F_26 ( unsigned long * V_42 ,
void (* V_22) ( void ) , bool V_43 )
{
unsigned long V_44 = ( unsigned long ) V_22 ;
unsigned long V_12 = ( unsigned long ) V_42 ;
unsigned long V_45 = F_27 ( V_12 , V_44 ) ;
unsigned long V_46 = 0xe1a00000 ;
unsigned long V_13 = V_43 ? V_46 : V_45 ;
unsigned long V_14 = V_43 ? V_45 : V_46 ;
return F_9 ( V_12 , V_13 , V_14 , true ) ;
}
static int F_28 ( bool V_43 )
{
int V_23 ;
V_23 = F_26 ( & V_47 ,
V_48 ,
V_43 ) ;
#ifdef F_17
if ( ! V_23 )
V_23 = F_26 ( & V_49 ,
V_50 ,
V_43 ) ;
#endif
return V_23 ;
}
int F_29 ( void )
{
return F_28 ( true ) ;
}
int F_30 ( void )
{
return F_28 ( false ) ;
}
