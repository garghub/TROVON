static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_8 = 0 ;
F_4 ( & V_5 -> V_9 ) ;
if ( ! V_7 -> V_10 ) {
V_8 = F_5 ( V_7 -> V_11 , V_7 -> V_12 -> V_13 , 0 ) ;
if ( V_8 )
goto V_14;
F_6 ( V_15 ,
V_16 ) ;
}
if ( ! V_8 ) {
V_7 -> V_10 ++ ;
V_8 = F_5 ( V_7 -> V_11 , V_7 -> V_12 -> V_17 ,
V_18 |
V_19 ) ;
}
V_14:
F_7 ( & V_5 -> V_9 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_4 ( & V_5 -> V_9 ) ;
F_5 ( V_7 -> V_11 , V_7 -> V_12 -> V_17 , V_18 ) ;
V_7 -> V_10 -- ;
if ( ! V_7 -> V_10 )
F_5 ( V_7 -> V_11 , V_7 -> V_12 -> V_13 ,
V_20 ) ;
F_7 ( & V_5 -> V_9 ) ;
return 0 ;
}
static const char * F_9 ( struct V_21 * V_22 , int * V_23 )
{
const struct V_24 * V_25 ;
V_25 = F_10 ( V_22 -> V_26 -> V_27 , V_22 ) ;
if ( ! V_25 )
return NULL ;
* V_23 = ( int ) V_25 -> V_28 ;
return F_11 ( V_22 ) ;
}
static int F_12 ( struct V_29 * V_30 ,
const struct V_31 * V_25 )
{
struct V_6 * V_7 ;
int V_32 , V_33 ;
struct V_34 * V_34 ;
const char * V_35 ;
if ( ! F_13 ( V_30 -> V_36 ,
V_37 ) )
return - V_38 ;
if ( V_25 ) {
V_33 = ( int ) V_25 -> V_28 ;
V_35 = V_25 -> V_35 ;
} else if ( F_14 ( & V_30 -> V_22 ) ) {
V_35 = F_9 ( & V_30 -> V_22 , & V_33 ) ;
if ( ! V_35 )
return - V_39 ;
} else {
return - V_40 ;
}
V_34 = F_15 ( V_30 , & V_41 ) ;
if ( F_16 ( V_34 ) ) {
F_17 ( & V_30 -> V_22 , L_1 ,
( int ) F_18 ( V_34 ) ) ;
return F_18 ( V_34 ) ;
}
V_32 = F_19 ( V_34 , V_30 -> V_42 , V_35 ,
NULL , V_33 ) ;
if ( V_32 < 0 )
return V_32 ;
V_7 = F_3 ( F_20 ( & V_30 -> V_22 ) ) ;
V_7 -> V_2 = F_21 ( V_30 -> V_36 , & V_30 -> V_22 ,
1 , 0 , V_43 | V_44 ,
F_1 ,
F_8 ) ;
if ( ! V_7 -> V_2 ) {
V_32 = - V_45 ;
goto V_46;
}
V_7 -> V_2 -> V_47 = F_20 ( & V_30 -> V_22 ) ;
V_32 = F_22 ( V_7 -> V_2 , 0 , 0 , 0 ) ;
if ( V_32 )
goto V_46;
V_32 = F_23 ( V_30 ) ;
if ( V_32 )
goto V_48;
return 0 ;
V_48:
F_24 ( V_7 -> V_2 ) ;
V_46:
F_25 ( & V_30 -> V_22 ) ;
return V_32 ;
}
static int F_26 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_27 ( V_30 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_28 ( V_30 ) ;
F_24 ( V_7 -> V_2 ) ;
return F_25 ( & V_30 -> V_22 ) ;
}
