int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = NULL ;
T_1 V_10 , V_11 ;
int V_12 ;
if ( V_13 ) {
V_10 = V_14 ;
V_11 = V_15 ;
} else {
V_10 = V_16 ;
V_11 = V_17 ;
}
V_12 = F_2 ( V_4 , V_18 , 0 , V_10 , 0 , 0 , & V_9 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_3 ( V_9 , V_11 ) ;
if ( V_12 )
goto V_19;
V_12 = F_4 ( V_9 ) ;
if ( V_12 )
goto V_19;
if ( V_6 -> V_20 >= V_21 ) {
V_12 = F_5 ( V_9 , V_2 -> V_22 , & V_2 -> V_23 ) ;
if ( V_12 )
goto V_19;
}
V_12 = F_6 ( & V_2 -> V_24 , 0 , V_9 -> V_25 . V_26 . V_27 ) ;
if ( V_12 )
goto V_19;
V_2 -> V_28 = V_9 ;
V_19:
if ( V_12 ) {
F_7 ( V_9 , & V_2 -> V_23 ) ;
F_8 ( V_9 -> V_29 ) ;
}
return V_12 ;
}
void
F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_2 -> V_28 )
return;
F_7 ( V_2 -> V_28 , & V_2 -> V_23 ) ;
F_10 ( V_2 -> V_28 ) ;
F_11 ( & V_4 -> V_30 ) ;
F_12 ( V_2 -> V_28 ) ;
F_13 ( & V_4 -> V_30 ) ;
F_8 ( V_2 -> V_28 -> V_29 ) ;
F_14 ( & V_2 -> V_24 ) ;
}
static void
F_15 ( struct V_3 * V_4 ,
struct V_31 * V_32 )
{
F_16 ( V_4 , L_1 ) ;
if ( V_32 -> V_33 )
F_17 ( V_32 -> V_33 ) ;
}
int
F_18 ( struct V_1 * V_2 , T_1 V_34 ,
int V_27 , T_1 V_35 , T_1 V_36 ,
T_1 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_31 * V_38 = NULL ;
struct V_39 * V_26 ;
T_1 V_40 ;
int V_41 , V_12 ;
V_26 = F_19 ( & V_2 -> V_24 , V_27 , 0 ,
V_35 , V_36 , 0 ) ;
if ( V_26 )
V_26 = F_20 ( V_26 , V_27 , 0 , V_35 , V_36 ) ;
if ( ! V_26 ) {
F_21 ( V_4 , L_2 , V_2 -> V_42 ) ;
return - V_43 ;
}
if ( V_6 -> V_20 < V_21 ) {
if ( V_2 -> V_28 -> V_25 . V_26 . V_44 == V_45 )
V_41 = V_46 ;
else
V_41 = V_47 ;
V_40 = V_2 -> V_28 -> V_25 . V_40 ;
} else {
V_41 = V_48 ;
V_40 = V_2 -> V_23 . V_40 ;
}
V_40 += V_26 -> V_35 ;
V_12 = F_22 ( V_2 , V_49 , V_40 ,
V_26 -> V_27 , V_50 , V_41 ,
& V_38 ) ;
if ( V_12 ) {
F_17 ( V_26 ) ;
F_21 ( V_4 , L_3 , V_12 ) ;
return V_12 ;
}
V_38 -> V_51 = F_15 ;
V_38 -> V_33 = V_26 ;
V_12 = F_23 ( V_2 , V_34 , V_38 ) ;
F_24 ( NULL , & V_38 ) ;
if ( V_12 ) {
F_17 ( V_26 ) ;
F_21 ( V_4 , L_4 , V_12 ) ;
return V_12 ;
}
* V_37 = V_26 -> V_35 ;
return 0 ;
}
int
F_25 ( struct V_31 * V_38 , T_1 * V_52 )
{
if ( ! V_38 || V_38 -> V_51 != F_15 )
return - V_53 ;
if ( V_52 ) {
struct V_39 * V_26 = V_38 -> V_33 ;
if ( * V_52 >= V_26 -> V_27 )
return false ;
* V_52 += V_26 -> V_35 ;
}
return 0 ;
}
int
F_26 ( struct V_3 * V_4 , void * V_54 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_57 * V_58 = V_54 ;
struct V_1 * V_2 ;
int V_12 ;
if ( F_27 ( V_6 -> V_20 >= V_59 ) )
return - V_53 ;
V_2 = F_28 ( V_56 , V_58 -> V_60 ) ;
if ( F_29 ( V_2 ) )
return F_30 ( V_2 ) ;
V_12 = F_18 ( V_2 , V_58 -> V_34 , V_58 -> V_27 , 0 , 0x1000 ,
& V_58 -> V_40 ) ;
F_31 ( & V_2 ) ;
return V_12 ;
}
