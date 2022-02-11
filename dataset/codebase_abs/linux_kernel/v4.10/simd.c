static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_7 = & V_6 -> V_8 -> V_9 ;
int V_10 ;
F_3 ( V_7 , V_11 ) ;
F_4 ( V_7 , F_5 ( V_2 ) &
V_11 ) ;
V_10 = F_6 ( V_7 , V_3 , V_4 ) ;
F_4 ( V_2 , F_5 ( V_7 ) &
V_12 ) ;
return V_10 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 * V_15 ;
struct V_1 * V_7 ;
V_15 = F_9 ( V_14 ) ;
* V_15 = * V_14 ;
if ( ! F_10 () ||
( F_11 () && F_12 ( V_6 -> V_8 ) ) )
V_7 = & V_6 -> V_8 -> V_9 ;
else
V_7 = F_13 ( V_6 -> V_8 ) ;
F_14 ( V_15 , V_7 ) ;
return F_15 ( V_15 ) ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 * V_15 ;
struct V_1 * V_7 ;
V_15 = F_9 ( V_14 ) ;
* V_15 = * V_14 ;
if ( ! F_10 () ||
( F_11 () && F_12 ( V_6 -> V_8 ) ) )
V_7 = & V_6 -> V_8 -> V_9 ;
else
V_7 = F_13 ( V_6 -> V_8 ) ;
F_14 ( V_15 , V_7 ) ;
return F_17 ( V_15 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 -> V_8 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_8 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
unsigned V_21 ;
V_20 = F_21 ( V_2 ) ;
V_18 = F_22 ( V_20 , struct V_17 , V_20 ) ;
V_8 = F_23 ( V_18 -> V_22 ,
V_23 ,
V_23 ) ;
if ( F_24 ( V_8 ) )
return F_25 ( V_8 ) ;
V_6 -> V_8 = V_8 ;
V_21 = sizeof( struct V_13 ) ;
V_21 += F_26 ( & V_8 -> V_9 ) ;
F_27 ( V_2 , V_21 ) ;
return 0 ;
}
struct V_17 * F_28 ( const char * V_24 ,
const char * V_25 ,
const char * V_26 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_19 * V_27 ;
struct V_19 * V_20 ;
int V_10 ;
V_2 = F_29 ( V_26 , V_23 ,
V_23 | V_28 ) ;
if ( F_24 ( V_2 ) )
return F_30 ( V_2 ) ;
V_27 = F_21 ( V_2 ) ;
V_18 = F_31 ( sizeof( * V_18 ) , V_29 ) ;
if ( ! V_18 ) {
V_18 = F_32 ( - V_30 ) ;
goto V_31;
}
V_18 -> V_22 = V_26 ;
V_20 = & V_18 -> V_20 ;
V_10 = - V_32 ;
if ( snprintf ( V_20 -> V_9 . V_33 , V_34 , L_1 , V_24 ) >=
V_34 )
goto V_35;
if ( snprintf ( V_20 -> V_9 . V_36 , V_34 , L_1 ,
V_25 ) >= V_34 )
goto V_35;
V_20 -> V_9 . V_37 = V_28 ;
V_20 -> V_9 . V_38 = V_27 -> V_9 . V_38 ;
V_20 -> V_9 . V_39 = V_27 -> V_9 . V_39 ;
V_20 -> V_9 . V_40 = V_27 -> V_9 . V_40 ;
V_20 -> V_9 . V_41 = V_27 -> V_9 . V_41 ;
V_20 -> V_9 . V_42 = sizeof( struct V_5 ) ;
V_20 -> V_43 = V_27 -> V_43 ;
V_20 -> V_44 = V_27 -> V_44 ;
V_20 -> V_45 = V_27 -> V_45 ;
V_20 -> V_46 = V_27 -> V_46 ;
V_20 -> V_47 = F_20 ;
V_20 -> exit = F_18 ;
V_20 -> V_48 = F_1 ;
V_20 -> V_49 = F_7 ;
V_20 -> V_50 = F_16 ;
V_10 = F_33 ( V_20 ) ;
if ( V_10 )
goto V_35;
V_31:
F_34 ( V_2 ) ;
return V_18 ;
V_35:
F_35 ( V_18 ) ;
V_18 = F_32 ( V_10 ) ;
goto V_31;
}
struct V_17 * F_36 ( const char * V_24 ,
const char * V_26 )
{
char V_25 [ V_34 ] ;
if ( snprintf ( V_25 , V_34 , L_2 , V_26 ) >=
V_34 )
return F_32 ( - V_32 ) ;
return F_28 ( V_24 , V_25 , V_26 ) ;
}
void F_37 ( struct V_17 * V_18 )
{
F_38 ( & V_18 -> V_20 ) ;
F_35 ( V_18 ) ;
}
