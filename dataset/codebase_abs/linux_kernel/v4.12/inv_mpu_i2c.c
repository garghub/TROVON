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
static const char * F_9 ( struct V_21 * V_22 ,
enum V_23 * V_24 )
{
const struct V_25 * V_26 ;
V_26 = F_10 ( V_22 -> V_27 -> V_28 , V_22 ) ;
if ( ! V_26 )
return NULL ;
* V_24 = ( int ) V_26 -> V_29 ;
return F_11 ( V_22 ) ;
}
static int F_12 ( struct V_30 * V_31 ,
const struct V_32 * V_26 )
{
struct V_6 * V_7 ;
int V_33 ;
enum V_23 V_34 ;
struct V_35 * V_35 ;
const char * V_36 ;
if ( ! F_13 ( V_31 -> V_37 ,
V_38 ) )
return - V_39 ;
if ( V_31 -> V_22 . V_40 ) {
V_34 = (enum V_23 )
F_14 ( & V_31 -> V_22 ) ;
V_36 = V_31 -> V_36 ;
} else if ( V_26 ) {
V_34 = (enum V_23 )
V_26 -> V_29 ;
V_36 = V_26 -> V_36 ;
} else if ( F_15 ( & V_31 -> V_22 ) ) {
V_36 = F_9 ( & V_31 -> V_22 , & V_34 ) ;
if ( ! V_36 )
return - V_41 ;
} else {
return - V_42 ;
}
V_35 = F_16 ( V_31 , & V_43 ) ;
if ( F_17 ( V_35 ) ) {
F_18 ( & V_31 -> V_22 , L_1 ,
( int ) F_19 ( V_35 ) ) ;
return F_19 ( V_35 ) ;
}
V_33 = F_20 ( V_35 , V_31 -> V_44 , V_36 ,
NULL , V_34 ) ;
if ( V_33 < 0 )
return V_33 ;
V_7 = F_3 ( F_21 ( & V_31 -> V_22 ) ) ;
V_7 -> V_2 = F_22 ( V_31 -> V_37 , & V_31 -> V_22 ,
1 , 0 , V_45 | V_46 ,
F_1 ,
F_8 ) ;
if ( ! V_7 -> V_2 ) {
V_33 = - V_47 ;
goto V_48;
}
V_7 -> V_2 -> V_49 = F_21 ( & V_31 -> V_22 ) ;
V_33 = F_23 ( V_7 -> V_2 , 0 , 0 , 0 ) ;
if ( V_33 )
goto V_48;
V_33 = F_24 ( V_31 ) ;
if ( V_33 )
goto V_50;
return 0 ;
V_50:
F_25 ( V_7 -> V_2 ) ;
V_48:
F_26 ( & V_31 -> V_22 ) ;
return V_33 ;
}
static int F_27 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_28 ( V_31 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_29 ( V_31 ) ;
F_25 ( V_7 -> V_2 ) ;
return F_26 ( & V_31 -> V_22 ) ;
}
