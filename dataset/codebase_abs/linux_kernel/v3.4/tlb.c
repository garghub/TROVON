void F_1 ( void )
{
int V_1 ;
unsigned long V_2 ;
V_2 = V_3 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
F_2 ( F_3 ( 0 ) , V_1 , 0 ) ;
F_2 ( F_4 ( 0 ) , V_1 , 0 ) ;
}
}
void F_5 ( struct V_4 * V_5 , unsigned long V_6 )
{
if ( V_7 )
F_6 ( V_6 ) ;
else
F_7 ( V_6 ) ;
if ( V_8 )
F_8 ( V_6 ) ;
else
F_9 ( V_6 ) ;
}
void F_10 ( struct V_4 * V_5 ,
unsigned long V_9 , unsigned long V_10 )
{
int V_6 ;
bool V_11 ;
bool V_12 ;
V_11 = V_7 ;
V_12 = V_8 ;
for ( V_6 = V_9 ; V_6 < V_10 ; V_6 += V_13 ) {
if ( V_11 )
F_6 ( V_6 ) ;
else
F_7 ( V_6 ) ;
if ( V_12 )
F_8 ( V_6 ) ;
else
F_9 ( V_6 ) ;
}
}
void F_11 ( struct V_14 * V_15 )
{
F_1 () ;
}
void F_12 ( struct V_14 * V_16 , struct V_14 * V_17 ,
struct V_18 * V_19 )
{
V_20 = V_17 -> V_21 ;
if ( V_16 != V_17 )
F_11 ( V_16 ) ;
}
int F_13 ( struct V_18 * V_22 , struct V_14 * V_15 )
{
V_15 -> V_23 = V_24 ;
return 0 ;
}
void F_14 ( struct V_14 * V_15 )
{
F_11 ( V_15 ) ;
}
void T_1 F_15 ( void )
{
}
