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
V_23 = args -> V_25 * ( ( args -> V_26 + 1 ) / 8 ) ;
args -> V_7 = V_23 * args -> V_27 ;
args -> V_7 = F_14 ( args -> V_7 , V_28 ) ;
V_13 = F_7 ( V_20 , V_6 , args -> V_7 , & V_22 ,
& args -> V_18 ) ;
if ( V_13 )
goto V_29;
F_15 ( V_11 , & V_24 ) ;
F_16 ( V_11 , V_24 ,
2 , args -> V_25 , args -> V_27 ) ;
V_4 = F_2 ( V_22 ) ;
V_13 = F_17 ( V_11 , V_4 , V_24 , NULL ) ;
if ( V_13 )
goto V_29;
V_4 -> V_30 = true ;
args -> V_23 = V_23 ;
return V_13 ;
V_29:
return V_13 ;
}
int F_18 ( struct V_14 * V_20 ,
struct V_5 * V_6 ,
T_3 V_18 )
{
return F_19 ( V_20 , V_18 ) ;
}
int F_20 ( struct V_14 * V_20 ,
struct V_5 * V_6 ,
T_3 V_18 , T_2 * V_31 )
{
struct V_1 * V_22 ;
struct V_3 * V_4 ;
F_21 ( ! V_31 ) ;
V_22 = F_22 ( V_6 , V_20 , V_18 ) ;
if ( V_22 == NULL )
return - V_32 ;
V_4 = F_2 ( V_22 ) ;
* V_31 = F_23 ( V_4 ) ;
F_12 ( V_22 ) ;
return 0 ;
}
