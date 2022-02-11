int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
struct V_3 * V_6 , * V_7 ;
unsigned long V_8 ;
F_2 ( & V_2 -> V_9 , V_8 ) ;
V_6 = V_2 -> V_10 ;
V_7 = V_6 ? V_6 -> V_11 : V_4 ;
V_4 -> V_11 = V_7 ;
if ( V_6 )
V_6 -> V_11 = V_4 ;
V_2 -> V_10 = V_4 ;
F_3 ( & V_2 -> V_9 , V_8 ) ;
if ( V_5 )
F_4 ( V_2 ) ;
return 0 ;
}
struct V_3 *
F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
unsigned long V_8 ;
struct V_3 * V_6 , * V_13 = NULL ;
F_2 ( & V_2 -> V_9 , V_8 ) ;
V_6 = V_2 -> V_10 ;
if ( V_6 ) {
struct V_3 * V_14 = V_6 , * V_15 = V_14 -> V_11 ;
while ( 1 ) {
if ( V_15 -> V_12 == V_12 ) {
V_14 -> V_11 = V_15 -> V_11 ;
if ( V_15 == V_6 )
V_2 -> V_10 = V_14 == V_15 ? NULL : V_14 ;
V_13 = V_15 ;
break;
}
if ( V_15 == V_6 )
break;
V_14 = V_15 ;
V_15 = V_14 -> V_11 ;
}
}
F_3 ( & V_2 -> V_9 , V_8 ) ;
return V_13 ;
}
void F_6 ( void )
{
struct V_1 * V_2 = V_16 ;
struct V_3 * V_15 , * V_14 ;
while ( 1 ) {
F_7 ( & V_2 -> V_9 ) ;
V_15 = V_2 -> V_10 ;
V_2 -> V_10 = NULL ;
F_8 ( & V_2 -> V_9 ) ;
if ( F_9 ( ! V_15 ) )
return;
V_14 = V_15 -> V_11 ;
V_15 -> V_11 = NULL ;
while ( V_14 ) {
V_15 = V_14 -> V_11 ;
V_14 -> V_12 ( V_14 ) ;
V_14 = V_15 ;
F_10 () ;
}
}
}
