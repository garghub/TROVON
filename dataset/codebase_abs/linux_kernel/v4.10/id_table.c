T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
if ( V_4 >= V_2 -> V_7 )
V_4 = F_4 ( V_2 -> V_6 , V_2 -> V_7 ) ;
if ( V_4 < V_2 -> V_7 ) {
if ( V_2 -> V_3 & V_9 )
V_2 -> V_8 += F_5 () % V_10 ;
else
V_2 -> V_8 = V_4 + 1 ;
if ( V_2 -> V_8 >= V_2 -> V_7 )
V_2 -> V_8 = 0 ;
F_6 ( V_4 , V_2 -> V_6 ) ;
V_4 += V_2 -> V_11 ;
} else
V_4 = - 1 ;
F_7 ( & V_2 -> V_5 , V_3 ) ;
return V_4 ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_3 ;
V_4 -= V_2 -> V_11 ;
F_9 ( ( int ) V_4 < 0 ) ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
F_10 ( V_4 , V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_5 , V_3 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_3 )
{
int V_14 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_3 = V_3 ;
if ( V_3 & V_9 )
V_2 -> V_8 = F_5 () % V_10 ;
else
V_2 -> V_8 = 0 ;
V_2 -> V_7 = V_12 ;
F_12 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = F_13 ( F_14 ( V_12 ) * sizeof( long ) ,
V_15 ) ;
if ( ! V_2 -> V_6 )
return - V_16 ;
F_15 ( V_2 -> V_6 , V_12 ) ;
if ( ! ( V_2 -> V_3 & V_17 ) )
for ( V_14 = 0 ; V_14 < V_13 ; ++ V_14 )
F_6 ( V_14 , V_2 -> V_6 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_6 ) ;
}
