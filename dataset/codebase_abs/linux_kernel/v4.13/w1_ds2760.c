static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 , T_1 V_5 ,
int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_2 )
return 0 ;
F_3 ( & V_8 -> V_9 -> V_10 ) ;
if ( V_4 > V_11 || V_4 < 0 ) {
V_5 = 0 ;
goto V_12;
}
if ( V_4 + V_5 > V_11 )
V_5 = V_11 - V_4 ;
if ( ! F_4 ( V_8 ) ) {
if ( ! V_6 ) {
F_5 ( V_8 -> V_9 , V_13 ) ;
F_5 ( V_8 -> V_9 , V_4 ) ;
V_5 = F_6 ( V_8 -> V_9 , V_3 , V_5 ) ;
} else {
F_5 ( V_8 -> V_9 , V_14 ) ;
F_5 ( V_8 -> V_9 , V_4 ) ;
F_7 ( V_8 -> V_9 , V_3 , V_5 ) ;
}
}
V_12:
F_8 ( & V_8 -> V_9 -> V_10 ) ;
return V_5 ;
}
int F_9 ( struct V_1 * V_2 , char * V_3 , int V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 , 0 ) ;
}
int F_10 ( struct V_1 * V_2 , char * V_3 , int V_4 , T_1 V_5 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 , 1 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_4 , int V_15 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( ! V_2 )
return - V_16 ;
F_3 ( & V_8 -> V_9 -> V_10 ) ;
if ( F_4 ( V_8 ) == 0 ) {
F_5 ( V_8 -> V_9 , V_15 ) ;
F_5 ( V_8 -> V_9 , V_4 ) ;
}
F_8 ( & V_8 -> V_9 -> V_10 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , int V_4 )
{
return F_11 ( V_2 , V_4 , V_17 ) ;
}
int F_13 ( struct V_1 * V_2 , int V_4 )
{
return F_11 ( V_2 , V_4 , V_18 ) ;
}
static T_2 F_14 ( struct V_19 * V_20 , struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_3 ,
T_3 V_25 , T_1 V_5 )
{
struct V_1 * V_2 = F_2 ( V_22 , struct V_1 , V_22 ) ;
return F_9 ( V_2 , V_3 , V_25 , V_5 ) ;
}
static int F_15 ( struct V_7 * V_8 )
{
int V_26 ;
struct V_27 * V_28 ;
V_28 = F_16 ( L_1 , V_29 ) ;
if ( ! V_28 )
return - V_30 ;
V_28 -> V_2 . V_31 = & V_8 -> V_2 ;
V_26 = F_17 ( V_28 ) ;
if ( V_26 )
goto V_32;
F_18 ( & V_8 -> V_2 , V_28 ) ;
return 0 ;
V_32:
F_19 ( V_28 ) ;
return V_26 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_27 * V_28 = F_21 ( & V_8 -> V_2 ) ;
F_22 ( V_28 ) ;
}
