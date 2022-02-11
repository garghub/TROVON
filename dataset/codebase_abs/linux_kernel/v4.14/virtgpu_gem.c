void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 )
F_3 ( & V_4 ) ;
}
struct V_3 * F_4 ( struct V_5 * V_6 ,
T_1 V_7 , bool V_8 ,
bool V_9 )
{
struct V_10 * V_11 = V_6 -> V_12 ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_5 ( V_11 , V_7 , V_8 , V_9 , & V_4 ) ;
if ( V_13 )
return F_6 ( V_13 ) ;
return V_4 ;
}
int F_7 ( struct V_14 * V_15 ,
struct V_5 * V_6 ,
T_2 V_7 ,
struct V_1 * * V_16 ,
T_3 * V_17 )
{
struct V_3 * V_4 ;
int V_13 ;
T_4 V_18 ;
V_4 = F_4 ( V_6 , V_7 , false , false ) ;
if ( F_8 ( V_4 ) )
return F_9 ( V_4 ) ;
V_13 = F_10 ( V_15 , & V_4 -> V_19 , & V_18 ) ;
if ( V_13 ) {
F_11 ( & V_4 -> V_19 ) ;
return V_13 ;
}
* V_16 = & V_4 -> V_19 ;
F_12 ( & V_4 -> V_19 ) ;
* V_17 = V_18 ;
return 0 ;
}
int F_13 ( struct V_14 * V_20 ,
struct V_5 * V_6 ,
struct V_21 * args )
{
struct V_10 * V_11 = V_6 -> V_12 ;
struct V_1 * V_22 ;
struct V_3 * V_4 ;
int V_13 ;
T_3 V_23 ;
T_3 V_24 ;
T_3 V_25 ;
V_23 = args -> V_26 * ( ( args -> V_27 + 1 ) / 8 ) ;
args -> V_7 = V_23 * args -> V_28 ;
args -> V_7 = F_14 ( args -> V_7 , V_29 ) ;
V_13 = F_7 ( V_20 , V_6 , args -> V_7 , & V_22 ,
& args -> V_18 ) ;
if ( V_13 )
goto V_30;
V_25 = F_15 ( V_31 ) ;
F_16 ( V_11 , & V_24 ) ;
F_17 ( V_11 , V_24 , V_25 ,
args -> V_26 , args -> V_28 ) ;
V_4 = F_2 ( V_22 ) ;
V_13 = F_18 ( V_11 , V_4 , V_24 , NULL ) ;
if ( V_13 )
goto V_30;
V_4 -> V_32 = true ;
args -> V_23 = V_23 ;
return V_13 ;
V_30:
return V_13 ;
}
int F_19 ( struct V_14 * V_20 ,
struct V_5 * V_6 ,
T_3 V_18 , T_2 * V_33 )
{
struct V_1 * V_22 ;
struct V_3 * V_4 ;
F_20 ( ! V_33 ) ;
V_22 = F_21 ( V_20 , V_18 ) ;
if ( V_22 == NULL )
return - V_34 ;
V_4 = F_2 ( V_22 ) ;
* V_33 = F_22 ( V_4 ) ;
F_12 ( V_22 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_4 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = V_4 -> V_6 -> V_12 ;
struct V_35 * V_36 = V_15 -> V_37 ;
struct V_3 * V_38 = F_2 ( V_4 ) ;
int V_39 ;
if ( ! V_11 -> V_40 )
return 0 ;
V_39 = F_24 ( V_38 , false ) ;
if ( V_39 )
return V_39 ;
F_25 ( V_11 , V_36 -> V_41 ,
V_38 -> V_42 ) ;
F_26 ( V_38 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_4 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = V_4 -> V_6 -> V_12 ;
struct V_35 * V_36 = V_15 -> V_37 ;
struct V_3 * V_38 = F_2 ( V_4 ) ;
int V_39 ;
if ( ! V_11 -> V_40 )
return;
V_39 = F_24 ( V_38 , false ) ;
if ( V_39 )
return;
F_28 ( V_11 , V_36 -> V_41 ,
V_38 -> V_42 ) ;
F_26 ( V_38 ) ;
}
