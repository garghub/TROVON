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
V_3 -> V_10 -> V_11 ( V_7 ) ;
}
int F_8 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
int (* F_9)( struct V_12 * ,
struct V_6 * ) )
{
int V_13 = 0 ;
struct V_12 * V_14 = & V_3 -> V_5 ;
F_10 ( L_1 , V_15 , V_3 , V_7 ) ;
F_11 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_16 >= V_3 -> V_17 ) {
V_13 = 2 ;
if ( ! F_6 ( & V_3 -> V_18 -> V_14 ) ) {
F_12 ( & V_3 -> V_4 ) ;
return V_13 ;
}
V_7 = V_3 -> V_18 ;
goto V_19;
}
if ( ! F_6 ( V_14 ) && F_9 ) {
V_13 = F_9 ( V_14 , V_7 ) ;
if ( V_13 ) {
F_12 ( & V_3 -> V_4 ) ;
return V_13 ;
}
}
V_19:
V_3 -> V_16 ++ ;
F_13 ( & V_7 -> V_14 , V_14 ) ;
F_12 ( & V_3 -> V_4 ) ;
F_14 ( & V_3 -> V_20 ) ;
F_15 ( & V_3 -> V_21 , V_22 , V_23 ) ;
return V_13 ;
}
struct V_6 * F_16 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
F_10 ( L_2 , V_15 , V_3 ) ;
V_7 = F_17 ( & V_3 -> V_5 ,
struct V_6 , V_14 ) ;
F_18 ( & V_7 -> V_14 ) ;
V_3 -> V_16 -- ;
return V_7 ;
}
struct V_6 * F_19 ( struct V_2 * V_3 )
{
F_4 ( ! F_5 ( & V_3 -> V_4 ) ) ;
return F_17 ( & V_3 -> V_5 ,
struct V_6 , V_14 ) ;
}
void F_20 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
F_11 ( & V_3 -> V_4 ) ;
while ( ! F_3 ( V_3 ) ) {
V_7 = F_16 ( V_3 ) ;
F_7 ( V_3 , V_7 ) ;
}
F_12 ( & V_3 -> V_4 ) ;
}
void F_21 ( struct V_6 * V_7 , struct V_24 * V_24 ,
T_1 V_8 )
{
F_22 ( & V_7 -> V_14 ) ;
V_7 -> V_24 = V_24 ;
V_7 -> V_8 = V_8 ;
}
