void F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( F_2 ( V_2 -> V_4 <= V_5 ) )
F_3 ( V_3 ) ;
else
F_4 ( V_3 ) ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
int V_4 = V_2 -> V_4 ;
void * V_3 ;
if ( F_2 ( V_4 <= V_5 ) )
V_3 = F_6 ( V_4 ) ;
else
V_3 = F_7 ( V_4 , V_6 ) ;
if ( ! V_3 )
return - V_7 ;
if ( V_2 -> V_8 )
if ( V_2 -> V_8 ( V_2 , V_3 ) ) {
F_1 ( V_2 , V_3 ) ;
return - V_7 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_9 , T_1 V_6 )
{
int V_10 , V_11 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_13 , V_12 ) ;
if ( V_2 -> V_9 == V_2 -> V_14 ) {
F_10 ( L_1 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
return V_2 -> V_9 ;
}
if ( V_9 + V_2 -> V_9 > V_2 -> V_14 ) {
F_10 ( L_2 ,
V_9 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
if ( ( V_9 + V_2 -> V_9 ) < V_2 -> V_9 ) {
F_10 ( L_3 ,
V_9 , V_2 -> V_9 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
V_10 = F_5 ( V_2 , V_6 ) ;
if ( V_10 < 0 )
break;
}
V_2 -> V_9 += V_11 ;
F_12 ( L_4 , V_11 , V_9 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
return V_11 ;
}
