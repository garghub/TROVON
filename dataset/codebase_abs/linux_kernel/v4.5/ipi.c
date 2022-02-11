void F_1 ( int V_1 , int V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
F_3 ( F_4 ( V_4 , V_1 ) ,
V_2 , V_5 ) ;
F_5 ( V_3 ) ;
}
void F_6 ( const struct V_6 * V_7 , int V_2 )
{
unsigned long V_8 ;
unsigned long V_3 ;
F_2 ( V_3 ) ;
F_7 (query_cpu, mask) {
F_3 ( F_4 ( V_4 ,
V_8 ) , V_2 , V_5 ) ;
}
F_5 ( V_3 ) ;
}
void F_8 ( const struct V_6 * V_7 ,
int V_2 )
{
unsigned int V_9 = F_9 () ;
unsigned int V_8 ;
unsigned long V_3 ;
F_2 ( V_3 ) ;
F_7 (query_cpu, mask) {
if ( V_8 == V_9 )
continue;
F_3 ( F_4 ( V_4 ,
V_8 ) , V_2 , V_5 ) ;
}
F_5 ( V_3 ) ;
}
void F_10 ( int V_1 , int V_2 )
{
V_10 -> V_11 ( F_11 ( V_1 ) , V_2 ) ;
}
void F_12 ( const struct V_6 * V_7 ,
int V_2 )
{
unsigned long V_3 ;
unsigned int V_8 ;
F_2 ( V_3 ) ;
F_7 (query_cpu, mask)
F_3 (
F_13 ( V_12 , V_8 ) ,
V_2 , V_10 -> V_13 ) ;
F_5 ( V_3 ) ;
}
void F_14 ( const struct V_6 * V_7 ,
int V_2 )
{
unsigned long V_3 ;
unsigned int V_8 ;
unsigned int V_9 = F_9 () ;
F_2 ( V_3 ) ;
F_7 (query_cpu, mask) {
if ( V_8 == V_9 )
continue;
F_3 (
F_13 ( V_12 , V_8 ) ,
V_2 , V_10 -> V_13 ) ;
}
F_5 ( V_3 ) ;
}
void F_15 ( const struct V_6 * V_6 , int V_2 )
{
unsigned long V_7 = F_16 ( V_6 ) [ 0 ] ;
unsigned long V_3 ;
if ( ! V_7 )
return;
F_2 ( V_3 ) ;
F_17 ( V_7 & ~ F_16 ( V_14 ) [ 0 ] ) ;
F_3 ( V_7 , V_2 , V_10 -> V_13 ) ;
F_5 ( V_3 ) ;
}
void F_18 ( int V_2 )
{
if ( ! ( F_19 () > 1 ) )
return;
F_20 ( V_2 ) ;
}
void F_21 ( int V_2 )
{
F_22 ( V_2 ) ;
}
void F_23 ( int V_2 )
{
F_24 ( V_15 , V_2 , V_10 -> V_13 ) ;
}
static int F_25 ( int V_16 )
{
int V_17 ;
F_26 (i) {
if ( F_4 ( V_4 , V_17 ) == V_16 )
return V_17 ;
}
return - 1 ;
}
int F_27 ( void )
{
int V_18 , V_19 ;
if ( ! V_20 )
return 0 ;
V_18 = F_28 () ;
if ( V_18 == V_21 )
return 0 ;
V_19 = F_25 ( V_18 ) ;
return V_19 >= 0 ? V_19 : 0 ;
}
