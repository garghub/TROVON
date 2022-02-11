static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 ,
T_1 V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( V_4 > V_9 || V_4 < 0 )
return 0 ;
V_5 = F_3 ( int , V_5 , V_9 - V_4 ) ;
if ( F_4 ( V_8 ) == 0 ) {
if ( V_6 ) {
F_5 ( V_8 -> V_10 , V_11 ) ;
F_5 ( V_8 -> V_10 , V_4 ) ;
F_6 ( V_8 -> V_10 , V_3 , V_5 ) ;
} else {
F_5 ( V_8 -> V_10 , V_12 ) ;
F_5 ( V_8 -> V_10 , V_4 ) ;
V_5 = F_7 ( V_8 -> V_10 , V_3 , V_5 ) ;
}
}
return V_5 ;
}
int F_8 ( struct V_1 * V_2 , char * V_3 , int V_4 , T_1 V_5 ,
int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
int V_13 ;
if ( ! V_2 )
return - V_14 ;
F_9 ( & V_8 -> V_10 -> V_15 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_10 ( & V_8 -> V_10 -> V_15 ) ;
return V_13 ;
}
int F_11 ( struct V_1 * V_2 , int V_4 , int V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_2 )
return - V_17 ;
F_9 ( & V_8 -> V_10 -> V_15 ) ;
if ( F_4 ( V_8 ) == 0 ) {
F_5 ( V_8 -> V_10 , V_16 ) ;
F_5 ( V_8 -> V_10 , V_4 ) ;
}
F_10 ( & V_8 -> V_10 -> V_15 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_18 * V_19 , struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_3 ,
T_3 V_24 , T_1 V_5 )
{
struct V_1 * V_2 = F_2 ( V_21 , struct V_1 , V_21 ) ;
return F_8 ( V_2 , V_3 , V_24 , V_5 , 0 ) ;
}
static int F_13 ( struct V_7 * V_8 )
{
int V_13 ;
struct V_25 * V_26 ;
V_26 = F_14 ( L_1 , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
V_26 -> V_2 . V_29 = & V_8 -> V_2 ;
V_13 = F_15 ( V_26 ) ;
if ( V_13 )
goto V_30;
F_16 ( & V_8 -> V_2 , V_26 ) ;
return 0 ;
V_30:
F_17 ( V_26 ) ;
return V_13 ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_25 * V_26 = F_19 ( & V_8 -> V_2 ) ;
F_20 ( V_26 ) ;
}
