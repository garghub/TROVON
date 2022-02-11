void F_1 ( const struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
F_2 ( V_5 ) ;
F_3 (query_cpu, mask) {
F_4 ( F_5 ( V_6 ,
V_4 ) , V_3 , V_7 ) ;
}
F_6 ( V_5 ) ;
}
void F_7 ( const struct V_1 * V_2 ,
int V_3 )
{
unsigned int V_8 = F_8 () ;
unsigned int V_4 ;
unsigned long V_5 ;
F_2 ( V_5 ) ;
F_3 (query_cpu, mask) {
if ( V_4 == V_8 )
continue;
F_4 ( F_5 ( V_6 ,
V_4 ) , V_3 , V_7 ) ;
}
F_6 ( V_5 ) ;
}
void F_9 ( const struct V_1 * V_2 ,
int V_3 )
{
unsigned long V_5 ;
unsigned int V_4 ;
F_2 ( V_5 ) ;
F_3 (query_cpu, mask)
F_4 (
F_10 ( V_9 , V_4 ) ,
V_3 , V_10 -> V_11 ) ;
F_6 ( V_5 ) ;
}
void F_11 ( const struct V_1 * V_2 ,
int V_3 )
{
unsigned long V_5 ;
unsigned int V_4 ;
unsigned int V_8 = F_8 () ;
F_2 ( V_5 ) ;
F_3 (query_cpu, mask) {
if ( V_4 == V_8 )
continue;
F_4 (
F_10 ( V_9 , V_4 ) ,
V_3 , V_10 -> V_11 ) ;
}
F_6 ( V_5 ) ;
}
void F_12 ( const struct V_1 * V_1 , int V_3 )
{
unsigned long V_2 = F_13 ( V_1 ) [ 0 ] ;
unsigned long V_5 ;
if ( F_14 ( ! V_2 , L_1 ) )
return;
F_2 ( V_5 ) ;
F_15 ( V_2 & ~ F_13 ( V_12 ) [ 0 ] ) ;
F_4 ( V_2 , V_3 , V_10 -> V_11 ) ;
F_6 ( V_5 ) ;
}
void F_16 ( int V_3 )
{
if ( ! ( F_17 () > 1 ) )
return;
F_18 ( V_3 ) ;
}
void F_19 ( int V_3 )
{
F_20 ( V_3 ) ;
}
void F_21 ( int V_3 )
{
F_22 ( V_13 , V_3 , V_10 -> V_11 ) ;
}
static int F_23 ( int V_14 )
{
int V_15 ;
F_24 (i) {
if ( F_5 ( V_6 , V_15 ) == V_14 )
return V_15 ;
}
return - 1 ;
}
int F_25 ( void )
{
int V_16 , V_17 ;
if ( ! V_18 )
return 0 ;
V_16 = F_26 () ;
if ( V_16 == V_19 )
return 0 ;
V_17 = F_23 ( V_16 ) ;
return V_17 >= 0 ? V_17 : 0 ;
}
