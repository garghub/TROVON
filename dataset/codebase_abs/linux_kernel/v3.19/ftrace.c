static int F_1 ( void * V_1 )
{
int * V_2 = V_1 ;
F_2 () ;
F_3 ( * V_2 ) ;
F_4 () ;
return 0 ;
}
void F_5 ( int V_2 )
{
F_6 ( F_1 , & V_2 , NULL ) ;
}
static unsigned long F_7 ( struct V_3 * V_4 )
{
return V_4 -> V_5 . V_6 ? V_7 : V_8 ;
}
static unsigned long F_8 ( struct V_3 * V_4 , unsigned long V_9 )
{
if ( ! V_4 -> V_5 . V_6 )
return V_9 ;
if ( V_9 == V_10 )
V_9 = V_11 ;
else if ( V_9 == V_12 )
V_9 = V_13 ;
return V_9 ;
}
static unsigned long F_7 ( struct V_3 * V_4 )
{
return V_8 ;
}
static unsigned long F_8 ( struct V_3 * V_4 , unsigned long V_9 )
{
return V_9 ;
}
int F_9 ( void )
{
F_10 () ;
return 0 ;
}
int F_11 ( void )
{
F_12 () ;
F_13 () ;
return 0 ;
}
static unsigned long F_14 ( unsigned long V_14 , unsigned long V_9 )
{
return F_15 ( V_14 , V_9 ) ;
}
static int F_16 ( unsigned long V_14 , unsigned long V_15 ,
unsigned long V_16 , bool V_17 )
{
unsigned long V_18 ;
if ( F_17 ( V_19 ) ) {
V_15 = F_18 ( V_15 ) ;
V_16 = F_18 ( V_16 ) ;
} else {
V_15 = F_19 ( V_15 ) ;
V_16 = F_19 ( V_16 ) ;
}
if ( V_17 ) {
if ( F_20 ( & V_18 , ( void * ) V_14 , V_20 ) )
return - V_21 ;
if ( V_18 != V_15 )
return - V_22 ;
}
if ( F_21 ( ( void * ) V_14 , & V_16 , V_20 ) )
return - V_23 ;
F_22 ( V_14 , V_14 + V_20 ) ;
return 0 ;
}
int F_23 ( T_1 V_24 )
{
unsigned long V_14 ;
unsigned long V_16 ;
int V_25 ;
V_14 = ( unsigned long ) & V_26 ;
V_16 = F_14 ( V_14 , ( unsigned long ) V_24 ) ;
V_25 = F_16 ( V_14 , 0 , V_16 , false ) ;
#ifdef F_24
if ( ! V_25 ) {
V_14 = ( unsigned long ) & V_27 ;
V_16 = F_14 ( V_14 , ( unsigned long ) V_24 ) ;
V_25 = F_16 ( V_14 , 0 , V_16 , false ) ;
}
#endif
return V_25 ;
}
int F_25 ( struct V_3 * V_4 , unsigned long V_9 )
{
unsigned long V_16 , V_15 ;
unsigned long V_28 = V_4 -> V_28 ;
V_15 = F_7 ( V_4 ) ;
V_16 = F_14 ( V_28 , F_8 ( V_4 , V_9 ) ) ;
return F_16 ( V_4 -> V_28 , V_15 , V_16 , true ) ;
}
int F_26 ( struct V_29 * V_30 ,
struct V_3 * V_4 , unsigned long V_9 )
{
unsigned long V_28 = V_4 -> V_28 ;
unsigned long V_15 ;
unsigned long V_16 ;
int V_25 ;
V_15 = F_14 ( V_28 , F_8 ( V_4 , V_9 ) ) ;
V_16 = F_7 ( V_4 ) ;
V_25 = F_16 ( V_28 , V_15 , V_16 , true ) ;
#ifdef F_24
if ( V_25 == - V_22 && V_9 == V_10 ) {
V_4 -> V_5 . V_6 = true ;
V_15 = F_14 ( V_28 , F_8 ( V_4 , V_9 ) ) ;
V_16 = F_7 ( V_4 ) ;
V_25 = F_16 ( V_28 , V_15 , V_16 , true ) ;
}
#endif
return V_25 ;
}
int T_2 F_27 ( void )
{
return 0 ;
}
void F_28 ( unsigned long * V_31 , unsigned long V_32 ,
unsigned long V_33 )
{
unsigned long V_34 = ( unsigned long ) & V_35 ;
struct V_36 V_37 ;
unsigned long V_15 ;
int V_38 ;
if ( F_29 ( F_30 ( & V_39 -> V_40 ) ) )
return;
V_15 = * V_31 ;
* V_31 = V_34 ;
V_37 . V_24 = V_32 ;
V_37 . V_41 = V_39 -> V_42 + 1 ;
if ( ! F_31 ( & V_37 ) ) {
* V_31 = V_15 ;
return;
}
V_38 = F_32 ( V_15 , V_32 , & V_37 . V_41 ,
V_33 ) ;
if ( V_38 == - V_43 ) {
* V_31 = V_15 ;
return;
}
}
static int F_33 ( unsigned long * V_44 ,
void (* V_24) ( void ) , bool V_45 )
{
unsigned long V_46 = ( unsigned long ) V_24 ;
unsigned long V_14 = ( unsigned long ) V_44 ;
unsigned long V_47 = F_34 ( V_14 , V_46 ) ;
unsigned long V_48 = 0xe1a00000 ;
unsigned long V_15 = V_45 ? V_48 : V_47 ;
unsigned long V_16 = V_45 ? V_47 : V_48 ;
return F_16 ( V_14 , V_15 , V_16 , true ) ;
}
static int F_35 ( bool V_45 )
{
int V_25 ;
V_25 = F_33 ( & V_49 ,
V_50 ,
V_45 ) ;
#ifdef F_24
if ( ! V_25 )
V_25 = F_33 ( & V_51 ,
V_52 ,
V_45 ) ;
#endif
return V_25 ;
}
int F_36 ( void )
{
return F_35 ( true ) ;
}
int F_37 ( void )
{
return F_35 ( false ) ;
}
