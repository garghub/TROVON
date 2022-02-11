static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return V_5 & V_8 ? 1 : 0 ;
}
static struct V_1 * T_2
F_4 ( struct V_6 * V_6 ,
const char * V_9 ,
const char * * V_10 ,
int V_11 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_12 V_13 ;
int V_14 ;
if ( ! V_9 )
return F_5 ( - V_15 ) ;
if ( ! V_10 || ! V_11 )
return F_5 ( - V_15 ) ;
V_4 = F_6 ( sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return F_5 ( - V_17 ) ;
V_13 . V_9 = V_9 ;
V_13 . V_18 = & V_19 ;
V_13 . V_10 = V_10 ;
V_13 . V_11 = V_11 ;
V_13 . V_20 = 0 ;
V_4 -> V_2 . V_13 = & V_13 ;
V_4 -> V_6 = V_6 ;
V_2 = & V_4 -> V_2 ;
V_14 = F_7 ( NULL , & V_4 -> V_2 ) ;
if ( V_14 ) {
F_8 ( V_4 ) ;
V_2 = F_5 ( V_14 ) ;
}
return V_2 ;
}
static void T_2 F_9 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
const char * V_10 [ 2 ] ;
unsigned int V_11 ;
const char * V_9 = V_22 -> V_9 ;
struct V_6 * V_6 ;
V_11 = F_10 ( V_22 ) ;
if ( V_11 != 2 )
return;
F_11 ( V_22 , V_10 , V_11 ) ;
V_6 = F_12 ( F_13 ( V_22 ) ) ;
if ( F_14 ( V_6 ) )
return;
F_15 ( V_22 , L_1 , & V_9 ) ;
V_2 = F_4 ( V_6 , V_9 , V_10 ,
V_11 ) ;
if ( F_14 ( V_2 ) )
return;
F_16 ( V_22 , V_23 , V_2 ) ;
}
