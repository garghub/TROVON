void F_1 ( unsigned int V_1 , int V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
F_2 () ;
V_4 = F_3 ( V_1 , V_2 , V_3 ) ;
F_4 ( V_5 , V_4 ) ;
}
void F_5 ( unsigned int V_6 , int V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
if ( F_6 ( V_2 == V_7 ) )
F_7 () ;
else
F_2 () ;
V_4 = F_8 ( V_6 ) ;
F_4 ( V_8 , V_4 ) ;
V_4 = F_3 ( 0 , V_2 , V_3 ) ;
F_4 ( V_5 , V_4 ) ;
}
void F_9 ( int V_9 , int V_2 )
{
unsigned long V_10 ;
F_10 ( V_10 ) ;
F_5 ( F_11 ( V_11 , V_9 ) ,
V_2 , V_12 ) ;
F_12 ( V_10 ) ;
}
void F_13 ( const struct V_13 * V_6 , int V_2 )
{
unsigned long V_14 ;
unsigned long V_10 ;
F_10 ( V_10 ) ;
F_14 (query_cpu, mask) {
F_5 ( F_11 ( V_11 ,
V_14 ) , V_2 , V_12 ) ;
}
F_12 ( V_10 ) ;
}
void F_15 ( const struct V_13 * V_6 ,
int V_2 )
{
unsigned int V_15 = F_16 () ;
unsigned int V_14 ;
unsigned long V_10 ;
F_10 ( V_10 ) ;
F_14 (query_cpu, mask) {
if ( V_14 == V_15 )
continue;
F_5 ( F_11 ( V_11 ,
V_14 ) , V_2 , V_12 ) ;
}
F_12 ( V_10 ) ;
}
void F_17 ( int V_9 , int V_2 )
{
V_16 -> V_17 ( F_18 ( V_9 ) , V_2 ) ;
}
void F_19 ( const struct V_13 * V_6 ,
int V_2 )
{
unsigned long V_10 ;
unsigned int V_14 ;
F_10 ( V_10 ) ;
F_14 (query_cpu, mask)
F_5 (
F_20 ( V_18 , V_14 ) ,
V_2 , V_16 -> V_19 ) ;
F_12 ( V_10 ) ;
}
void F_21 ( const struct V_13 * V_6 ,
int V_2 )
{
unsigned long V_10 ;
unsigned int V_14 ;
unsigned int V_15 = F_16 () ;
F_10 ( V_10 ) ;
F_14 (query_cpu, mask) {
if ( V_14 == V_15 )
continue;
F_5 (
F_20 ( V_18 , V_14 ) ,
V_2 , V_16 -> V_19 ) ;
}
F_12 ( V_10 ) ;
}
void F_22 ( const struct V_13 * V_13 , int V_2 )
{
unsigned long V_6 = F_23 ( V_13 ) [ 0 ] ;
unsigned long V_10 ;
if ( ! V_6 )
return;
F_10 ( V_10 ) ;
F_24 ( V_6 & ~ F_23 ( V_20 ) [ 0 ] ) ;
F_5 ( V_6 , V_2 , V_16 -> V_19 ) ;
F_12 ( V_10 ) ;
}
void F_25 ( int V_2 )
{
if ( ! ( F_26 () > 1 ) )
return;
F_27 ( V_2 ) ;
}
void F_28 ( int V_2 )
{
F_29 ( V_2 ) ;
}
void F_30 ( int V_2 )
{
F_1 ( V_21 , V_2 , V_16 -> V_19 ) ;
}
static int F_31 ( int V_22 )
{
int V_23 ;
F_32 (i) {
if ( F_11 ( V_11 , V_23 ) == V_22 )
return V_23 ;
}
return - 1 ;
}
int F_33 ( void )
{
int V_24 , V_25 ;
if ( ! F_34 ( V_26 ) )
return 0 ;
V_24 = F_35 () ;
if ( V_24 == V_27 )
return 0 ;
V_25 = F_31 ( V_24 ) ;
return V_25 >= 0 ? V_25 : 0 ;
}
