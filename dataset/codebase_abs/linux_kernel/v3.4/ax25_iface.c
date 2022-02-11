void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
V_2 -> V_4 = V_5 ;
V_5 = V_2 ;
F_3 ( & V_3 ) ;
}
void F_4 ( unsigned int V_6 )
{
struct V_1 * V_7 ;
F_2 ( & V_3 ) ;
V_7 = V_5 ;
if ( V_7 == NULL )
goto V_8;
if ( V_7 -> V_6 == V_6 ) {
V_5 = V_7 -> V_4 ;
goto V_8;
}
while ( V_7 != NULL && V_7 -> V_4 != NULL ) {
if ( V_7 -> V_4 -> V_6 == V_6 ) {
V_7 -> V_4 = V_7 -> V_4 -> V_4 ;
goto V_8;
}
V_7 = V_7 -> V_4 ;
}
V_8:
F_3 ( & V_3 ) ;
}
void F_5 ( struct V_9 * V_10 )
{
F_6 ( & V_11 ) ;
F_7 ( & V_10 -> V_12 , & V_13 ) ;
F_8 ( & V_11 ) ;
}
void F_9 ( struct V_9 * V_10 )
{
F_6 ( & V_11 ) ;
F_10 ( & V_10 -> V_12 ) ;
F_8 ( & V_11 ) ;
}
int F_11 ( T_1 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
if ( F_12 ( V_14 , V_16 ) )
return 0 ;
if ( ( V_18 = F_13 ( sizeof( * V_18 ) , V_19 ) ) == NULL )
return - V_20 ;
V_18 -> V_14 = * V_14 ;
V_18 -> V_16 = V_16 ;
F_6 ( & V_21 ) ;
V_18 -> V_4 = V_22 ;
V_22 = V_18 ;
F_8 ( & V_21 ) ;
return 0 ;
}
void F_14 ( T_1 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_23 , * V_18 ;
F_6 ( & V_21 ) ;
V_18 = V_22 ;
if ( V_18 == NULL ) {
F_8 ( & V_21 ) ;
return;
}
if ( F_15 ( & V_18 -> V_14 , V_14 ) == 0 && V_18 -> V_16 == V_16 ) {
V_22 = V_18 -> V_4 ;
F_8 ( & V_21 ) ;
F_16 ( V_18 ) ;
return;
}
while ( V_18 != NULL && V_18 -> V_4 != NULL ) {
if ( F_15 ( & V_18 -> V_4 -> V_14 , V_14 ) == 0 && V_18 -> V_4 -> V_16 == V_16 ) {
V_23 = V_18 -> V_4 ;
V_18 -> V_4 = V_18 -> V_4 -> V_4 ;
F_8 ( & V_21 ) ;
F_16 ( V_23 ) ;
return;
}
V_18 = V_18 -> V_4 ;
}
F_8 ( & V_21 ) ;
}
void F_17 ( T_2 * V_24 , int V_25 )
{
struct V_9 * V_10 ;
struct V_26 * V_27 ;
F_6 ( & V_11 ) ;
F_18 (lf, node, &ax25_linkfail_list, lf_node)
V_10 -> V_28 ( V_24 , V_25 ) ;
F_8 ( & V_11 ) ;
}
int F_19 ( unsigned int V_6 )
{
struct V_1 * V_7 ;
int V_29 = 0 ;
F_20 ( & V_3 ) ;
for ( V_7 = V_5 ; V_7 != NULL ; V_7 = V_7 -> V_4 )
if ( V_7 -> V_6 == V_6 ) {
V_29 = 1 ;
break;
}
F_21 ( & V_3 ) ;
return V_29 ;
}
