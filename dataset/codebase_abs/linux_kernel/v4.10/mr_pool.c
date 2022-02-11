struct V_1 * F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
unsigned long V_7 ;
F_2 ( & V_3 -> V_8 , V_7 ) ;
V_6 = F_3 ( V_5 , struct V_1 , V_9 ) ;
if ( V_6 ) {
F_4 ( & V_6 -> V_9 ) ;
V_3 -> V_10 ++ ;
}
F_5 ( & V_3 -> V_8 , V_7 ) ;
return V_6 ;
}
void F_6 ( struct V_2 * V_3 , struct V_4 * V_5 , struct V_1 * V_6 )
{
unsigned long V_7 ;
F_2 ( & V_3 -> V_8 , V_7 ) ;
F_7 ( & V_6 -> V_9 , V_5 ) ;
V_3 -> V_10 -- ;
F_5 ( & V_3 -> V_8 , V_7 ) ;
}
int F_8 ( struct V_2 * V_3 , struct V_4 * V_5 , int V_11 ,
enum V_12 type , T_1 V_13 )
{
struct V_1 * V_6 ;
unsigned long V_7 ;
int V_14 , V_15 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
V_6 = F_9 ( V_3 -> V_16 , type , V_13 ) ;
if ( F_10 ( V_6 ) ) {
V_14 = F_11 ( V_6 ) ;
goto V_17;
}
F_2 ( & V_3 -> V_8 , V_7 ) ;
F_12 ( & V_6 -> V_9 , V_5 ) ;
F_5 ( & V_3 -> V_8 , V_7 ) ;
}
return 0 ;
V_17:
F_13 ( V_3 , V_5 ) ;
return V_14 ;
}
void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
unsigned long V_7 ;
F_2 ( & V_3 -> V_8 , V_7 ) ;
while ( ! F_14 ( V_5 ) ) {
V_6 = F_15 ( V_5 , struct V_1 , V_9 ) ;
F_4 ( & V_6 -> V_9 ) ;
F_5 ( & V_3 -> V_8 , V_7 ) ;
F_16 ( V_6 ) ;
F_2 ( & V_3 -> V_8 , V_7 ) ;
}
F_5 ( & V_3 -> V_8 , V_7 ) ;
}
