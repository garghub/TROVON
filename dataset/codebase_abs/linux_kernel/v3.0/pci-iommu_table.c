static struct V_1 * T_1
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
if ( ! V_4 )
return NULL ;
for ( V_5 = V_2 ; V_5 < V_3 ; V_5 ++ )
if ( V_5 -> V_6 == V_4 -> V_7 )
return V_5 ;
return NULL ;
}
void T_1 F_2 ( struct V_1 * V_2 ,
struct V_1 * V_3 ) {
struct V_1 * V_5 , * V_4 , V_8 ;
for ( V_5 = V_2 ; V_5 < V_3 ; V_5 ++ ) {
V_9:
V_4 = F_1 ( V_2 , V_3 , V_5 ) ;
if ( V_4 > V_5 ) {
V_8 = * V_5 ;
memmove ( V_5 , V_4 , sizeof( * V_5 ) ) ;
* V_4 = V_8 ;
goto V_9;
}
}
}
void T_1 F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_1 * V_5 , * V_4 , * V_10 ;
for ( V_5 = V_2 ; V_5 < V_3 ; V_5 ++ ) {
V_4 = F_1 ( V_2 , V_3 , V_5 ) ;
V_10 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_5 == V_10 ) {
F_4 ( V_11 L_1 ,
V_5 -> V_6 , V_4 -> V_6 ) ;
V_10 -> V_7 = 0 ;
}
}
for ( V_5 = V_2 ; V_5 < V_3 ; V_5 ++ ) {
V_4 = F_1 ( V_5 , V_3 , V_5 ) ;
if ( V_4 && V_4 > V_5 ) {
F_4 ( V_11 L_2 ,
V_5 -> V_6 , V_4 -> V_6 ) ;
}
}
}
inline void F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
}
