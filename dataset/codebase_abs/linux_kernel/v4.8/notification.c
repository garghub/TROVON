T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
bool F_3 ( struct V_2 * V_3 )
{
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
return F_6 ( & V_3 -> V_5 ) ? true : false ;
}
void F_7 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
if ( ! V_7 || V_7 -> V_8 == V_9 )
return;
F_8 ( ! F_6 ( & V_7 -> V_10 ) ) ;
V_3 -> V_11 -> V_12 ( V_7 ) ;
}
int F_9 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
int (* F_10)( struct V_13 * ,
struct V_6 * ) )
{
int V_14 = 0 ;
struct V_13 * V_10 = & V_3 -> V_5 ;
F_11 ( L_1 , V_15 , V_3 , V_7 ) ;
F_12 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_16 ) {
F_13 ( & V_3 -> V_4 ) ;
return 2 ;
}
if ( V_3 -> V_17 >= V_3 -> V_18 ) {
V_14 = 2 ;
if ( ! F_6 ( & V_3 -> V_19 -> V_10 ) ) {
F_13 ( & V_3 -> V_4 ) ;
return V_14 ;
}
V_7 = V_3 -> V_19 ;
goto V_20;
}
if ( ! F_6 ( V_10 ) && F_10 ) {
V_14 = F_10 ( V_10 , V_7 ) ;
if ( V_14 ) {
F_13 ( & V_3 -> V_4 ) ;
return V_14 ;
}
}
V_20:
V_3 -> V_17 ++ ;
F_14 ( & V_7 -> V_10 , V_10 ) ;
F_13 ( & V_3 -> V_4 ) ;
F_15 ( & V_3 -> V_21 ) ;
F_16 ( & V_3 -> V_22 , V_23 , V_24 ) ;
return V_14 ;
}
struct V_6 * F_17 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
F_11 ( L_2 , V_15 , V_3 ) ;
V_7 = F_18 ( & V_3 -> V_5 ,
struct V_6 , V_10 ) ;
F_19 ( & V_7 -> V_10 ) ;
V_3 -> V_17 -- ;
return V_7 ;
}
struct V_6 * F_20 ( struct V_2 * V_3 )
{
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
return F_18 ( & V_3 -> V_5 ,
struct V_6 , V_10 ) ;
}
void F_21 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
F_12 ( & V_3 -> V_4 ) ;
while ( ! F_3 ( V_3 ) ) {
V_7 = F_17 ( V_3 ) ;
F_7 ( V_3 , V_7 ) ;
}
F_13 ( & V_3 -> V_4 ) ;
}
void F_22 ( struct V_6 * V_7 , struct V_25 * V_25 ,
T_1 V_8 )
{
F_23 ( & V_7 -> V_10 ) ;
V_7 -> V_25 = V_25 ;
V_7 -> V_8 = V_8 ;
}
