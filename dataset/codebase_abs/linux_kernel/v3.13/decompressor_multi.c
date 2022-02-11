int F_1 ( void )
{
return V_1 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_3 ( & V_5 -> V_6 ) ;
F_4 ( & V_3 -> V_7 , & V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_6 ) ;
F_6 ( & V_5 -> V_9 ) ;
}
void * F_7 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 = NULL ;
int V_13 = - V_14 ;
V_5 = F_8 ( sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 )
goto V_16;
V_5 -> V_12 = V_12 ;
F_9 ( & V_5 -> V_6 ) ;
F_10 ( & V_5 -> V_8 ) ;
F_11 ( & V_5 -> V_9 ) ;
V_3 = F_12 ( sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
goto V_16;
V_3 -> V_5 = V_11 -> V_17 -> V_18 ( V_11 ,
V_5 -> V_12 ) ;
if ( F_13 ( V_3 -> V_5 ) ) {
V_13 = F_14 ( V_3 -> V_5 ) ;
goto V_16;
}
F_4 ( & V_3 -> V_7 , & V_5 -> V_8 ) ;
V_5 -> V_19 = 1 ;
return V_5 ;
V_16:
F_15 ( V_3 ) ;
F_15 ( V_5 ) ;
return F_16 ( V_13 ) ;
}
void F_17 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = V_11 -> V_5 ;
if ( V_5 ) {
struct V_2 * V_3 ;
while ( ! F_18 ( & V_5 -> V_8 ) ) {
V_3 = F_19 ( V_5 -> V_8 . V_20 ,
struct V_2 , V_7 ) ;
F_20 ( & V_3 -> V_7 ) ;
V_11 -> V_17 -> free ( V_3 -> V_5 ) ;
F_15 ( V_3 ) ;
V_5 -> V_19 -- ;
}
F_21 ( V_5 -> V_19 ) ;
F_15 ( V_5 -> V_12 ) ;
F_15 ( V_5 ) ;
}
}
static struct V_2 * F_22 ( struct V_10 * V_11 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 ;
while ( 1 ) {
F_3 ( & V_5 -> V_6 ) ;
if ( ! F_18 ( & V_5 -> V_8 ) ) {
V_3 = F_19 ( V_5 -> V_8 . V_20 ,
struct V_2 , V_7 ) ;
F_20 ( & V_3 -> V_7 ) ;
F_5 ( & V_5 -> V_6 ) ;
break;
}
if ( V_5 -> V_19 >= V_1 )
goto V_9;
V_3 = F_12 ( sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
goto V_9;
V_3 -> V_5 = V_11 -> V_17 -> V_18 ( V_11 ,
V_5 -> V_12 ) ;
if ( F_13 ( V_3 -> V_5 ) ) {
F_15 ( V_3 ) ;
goto V_9;
}
V_5 -> V_19 ++ ;
F_21 ( V_5 -> V_19 > V_1 ) ;
F_5 ( & V_5 -> V_6 ) ;
break;
V_9:
F_5 ( & V_5 -> V_6 ) ;
F_23 ( V_5 -> V_9 ,
! F_18 ( & V_5 -> V_8 ) ) ;
}
return V_3 ;
}
int F_24 ( struct V_10 * V_11 , struct V_21 * * V_22 ,
int V_23 , int V_24 , int V_25 , struct V_26 * V_27 )
{
int V_28 ;
struct V_4 * V_5 = V_11 -> V_5 ;
struct V_2 * V_2 = F_22 ( V_11 , V_5 ) ;
V_28 = V_11 -> V_17 -> V_29 ( V_11 , V_2 -> V_5 ,
V_22 , V_23 , V_24 , V_25 , V_27 ) ;
F_2 ( V_2 , V_5 ) ;
if ( V_28 < 0 )
ERROR ( L_1 ,
V_11 -> V_17 -> V_30 ) ;
return V_28 ;
}
