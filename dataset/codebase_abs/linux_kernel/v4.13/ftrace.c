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
#ifdef F_25
if ( ! V_25 ) {
V_14 = ( unsigned long ) & V_28 ;
V_16 = F_14 ( V_14 , ( unsigned long ) V_24 ) ;
V_25 = F_16 ( V_14 , 0 , V_16 , false ) ;
}
#endif
return V_25 ;
}
int F_26 ( struct V_3 * V_4 , unsigned long V_9 )
{
unsigned long V_16 , V_15 ;
unsigned long V_29 = V_4 -> V_29 ;
V_15 = F_7 ( V_4 ) ;
V_16 = F_14 ( V_29 , F_8 ( V_4 , V_9 ) ) ;
return F_16 ( V_4 -> V_29 , V_15 , V_16 , true ) ;
}
int F_27 ( struct V_3 * V_4 , unsigned long V_30 ,
unsigned long V_9 )
{
unsigned long V_16 , V_15 ;
unsigned long V_29 = V_4 -> V_29 ;
V_15 = F_14 ( V_29 , F_8 ( V_4 , V_30 ) ) ;
V_16 = F_14 ( V_29 , F_8 ( V_4 , V_9 ) ) ;
return F_16 ( V_4 -> V_29 , V_15 , V_16 , true ) ;
}
int F_28 ( struct V_31 * V_32 ,
struct V_3 * V_4 , unsigned long V_9 )
{
unsigned long V_29 = V_4 -> V_29 ;
unsigned long V_15 ;
unsigned long V_16 ;
int V_25 ;
V_15 = F_14 ( V_29 , F_8 ( V_4 , V_9 ) ) ;
V_16 = F_7 ( V_4 ) ;
V_25 = F_16 ( V_29 , V_15 , V_16 , true ) ;
#ifdef F_25
if ( V_25 == - V_22 && V_9 == V_10 ) {
V_4 -> V_5 . V_6 = true ;
V_15 = F_14 ( V_29 , F_8 ( V_4 , V_9 ) ) ;
V_16 = F_7 ( V_4 ) ;
V_25 = F_16 ( V_29 , V_15 , V_16 , true ) ;
}
#endif
return V_25 ;
}
int T_2 F_29 ( void )
{
return 0 ;
}
void F_30 ( unsigned long * V_33 , unsigned long V_34 ,
unsigned long V_35 )
{
unsigned long V_36 = ( unsigned long ) & V_37 ;
struct V_38 V_39 ;
unsigned long V_15 ;
int V_40 ;
if ( F_31 ( F_32 ( & V_41 -> V_42 ) ) )
return;
V_15 = * V_33 ;
* V_33 = V_36 ;
V_39 . V_24 = V_34 ;
V_39 . V_43 = V_41 -> V_44 + 1 ;
if ( ! F_33 ( & V_39 ) ) {
* V_33 = V_15 ;
return;
}
V_40 = F_34 ( V_15 , V_34 , & V_39 . V_43 ,
V_35 , NULL ) ;
if ( V_40 == - V_45 ) {
* V_33 = V_15 ;
return;
}
}
static int F_35 ( unsigned long * V_46 ,
void (* V_24) ( void ) , bool V_47 )
{
unsigned long V_48 = ( unsigned long ) V_24 ;
unsigned long V_14 = ( unsigned long ) V_46 ;
unsigned long V_49 = F_36 ( V_14 , V_48 ) ;
unsigned long V_50 = 0xe1a00000 ;
unsigned long V_15 = V_47 ? V_50 : V_49 ;
unsigned long V_16 = V_47 ? V_49 : V_50 ;
return F_16 ( V_14 , V_15 , V_16 , true ) ;
}
static int F_37 ( bool V_47 )
{
int V_25 ;
V_25 = F_35 ( & V_51 ,
V_52 ,
V_47 ) ;
#ifdef F_24
if ( ! V_25 )
V_25 = F_35 ( & V_53 ,
V_54 ,
V_47 ) ;
#endif
#ifdef F_25
if ( ! V_25 )
V_25 = F_35 ( & V_55 ,
V_56 ,
V_47 ) ;
#endif
return V_25 ;
}
int F_38 ( void )
{
return F_37 ( true ) ;
}
int F_39 ( void )
{
return F_37 ( false ) ;
}
