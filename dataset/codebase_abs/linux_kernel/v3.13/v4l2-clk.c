static struct V_1 * F_1 ( const char * V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
F_2 (clk, &clk_list, list) {
if ( strcmp ( V_2 , V_4 -> V_2 ) )
continue;
if ( ! V_3 || ! V_4 -> V_3 || ! strcmp ( V_4 -> V_3 , V_3 ) )
return V_4 ;
}
return F_3 ( - V_5 ) ;
}
struct V_1 * F_4 ( struct V_6 * V_7 , const char * V_3 )
{
struct V_1 * V_4 ;
F_5 ( & V_8 ) ;
V_4 = F_1 ( F_6 ( V_7 ) , V_3 ) ;
if ( ! F_7 ( V_4 ) )
F_8 ( & V_4 -> V_9 ) ;
F_9 ( & V_8 ) ;
return V_4 ;
}
void F_10 ( struct V_1 * V_4 )
{
struct V_1 * V_10 ;
if ( F_7 ( V_4 ) )
return;
F_5 ( & V_8 ) ;
F_2 (tmp, &clk_list, list)
if ( V_10 == V_4 )
F_11 ( & V_4 -> V_9 ) ;
F_9 ( & V_8 ) ;
}
static int F_12 ( struct V_1 * V_4 )
{
struct V_1 * V_10 ;
int V_11 = - V_5 ;
F_5 ( & V_8 ) ;
F_2 (tmp, &clk_list, list)
if ( V_10 == V_4 ) {
V_11 = ! F_13 ( V_4 -> V_12 -> V_13 ) ;
if ( V_11 )
V_11 = - V_14 ;
break;
}
F_9 ( & V_8 ) ;
return V_11 ;
}
static void F_14 ( struct V_1 * V_4 )
{
F_15 ( V_4 -> V_12 -> V_13 ) ;
}
int F_16 ( struct V_1 * V_4 )
{
int V_11 = F_12 ( V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
F_5 ( & V_4 -> V_15 ) ;
if ( ++ V_4 -> V_16 == 1 && V_4 -> V_12 -> V_16 ) {
V_11 = V_4 -> V_12 -> V_16 ( V_4 ) ;
if ( V_11 < 0 )
V_4 -> V_16 -- ;
}
F_9 ( & V_4 -> V_15 ) ;
return V_11 ;
}
void F_17 ( struct V_1 * V_4 )
{
int V_16 ;
F_5 ( & V_4 -> V_15 ) ;
V_16 = -- V_4 -> V_16 ;
if ( F_18 ( V_16 < 0 , L_1 , V_17 ,
V_4 -> V_2 , V_4 -> V_3 ) )
V_4 -> V_16 ++ ;
else if ( ! V_16 && V_4 -> V_12 -> V_18 )
V_4 -> V_12 -> V_18 ( V_4 ) ;
F_9 ( & V_4 -> V_15 ) ;
F_14 ( V_4 ) ;
}
unsigned long F_19 ( struct V_1 * V_4 )
{
int V_11 = F_12 ( V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
F_5 ( & V_4 -> V_15 ) ;
if ( ! V_4 -> V_12 -> V_19 )
V_11 = - V_20 ;
else
V_11 = V_4 -> V_12 -> V_19 ( V_4 ) ;
F_9 ( & V_4 -> V_15 ) ;
F_14 ( V_4 ) ;
return V_11 ;
}
int F_20 ( struct V_1 * V_4 , unsigned long V_21 )
{
int V_11 = F_12 ( V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
F_5 ( & V_4 -> V_15 ) ;
if ( ! V_4 -> V_12 -> V_22 )
V_11 = - V_20 ;
else
V_11 = V_4 -> V_12 -> V_22 ( V_4 , V_21 ) ;
F_9 ( & V_4 -> V_15 ) ;
F_14 ( V_4 ) ;
return V_11 ;
}
struct V_1 * F_21 ( const struct V_23 * V_12 ,
const char * V_2 ,
const char * V_3 , void * V_24 )
{
struct V_1 * V_4 ;
int V_11 ;
if ( ! V_12 || ! V_2 )
return F_3 ( - V_25 ) ;
V_4 = F_22 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_4 )
return F_3 ( - V_27 ) ;
V_4 -> V_3 = F_23 ( V_3 , V_26 ) ;
V_4 -> V_2 = F_23 ( V_2 , V_26 ) ;
if ( ( V_3 && ! V_4 -> V_3 ) || ! V_4 -> V_2 ) {
V_11 = - V_27 ;
goto V_28;
}
V_4 -> V_12 = V_12 ;
V_4 -> V_24 = V_24 ;
F_24 ( & V_4 -> V_9 , 0 ) ;
F_25 ( & V_4 -> V_15 ) ;
F_5 ( & V_8 ) ;
if ( ! F_7 ( F_1 ( V_2 , V_3 ) ) ) {
F_9 ( & V_8 ) ;
V_11 = - V_29 ;
goto V_30;
}
F_26 ( & V_4 -> V_31 , & V_32 ) ;
F_9 ( & V_8 ) ;
return V_4 ;
V_30:
V_28:
F_27 ( V_4 -> V_3 ) ;
F_27 ( V_4 -> V_2 ) ;
F_27 ( V_4 ) ;
return F_3 ( V_11 ) ;
}
void F_28 ( struct V_1 * V_4 )
{
if ( F_18 ( F_29 ( & V_4 -> V_9 ) ,
L_2 ,
V_17 , V_4 -> V_2 , V_4 -> V_3 ) )
return;
F_5 ( & V_8 ) ;
F_30 ( & V_4 -> V_31 ) ;
F_9 ( & V_8 ) ;
F_27 ( V_4 -> V_3 ) ;
F_27 ( V_4 -> V_2 ) ;
F_27 ( V_4 ) ;
}
static unsigned long F_31 ( struct V_1 * V_4 )
{
struct V_33 * V_24 = V_4 -> V_24 ;
return V_24 -> V_21 ;
}
struct V_1 * F_32 ( const char * V_2 ,
const char * V_3 , unsigned long V_21 , struct V_34 * V_13 )
{
struct V_1 * V_4 ;
struct V_33 * V_24 = F_22 ( sizeof( * V_24 ) , V_26 ) ;
if ( ! V_24 )
return F_3 ( - V_27 ) ;
V_24 -> V_21 = V_21 ;
V_24 -> V_12 . V_19 = F_31 ;
V_24 -> V_12 . V_13 = V_13 ;
V_4 = F_21 ( & V_24 -> V_12 , V_2 , V_3 , V_24 ) ;
if ( F_7 ( V_4 ) )
F_27 ( V_24 ) ;
return V_4 ;
}
void F_33 ( struct V_1 * V_4 )
{
F_27 ( V_4 -> V_24 ) ;
F_28 ( V_4 ) ;
}
