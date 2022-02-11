int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = NULL ;
T_1 V_7 , V_8 ;
int V_9 ;
if ( V_10 ) {
V_7 = V_11 ;
V_8 = V_12 ;
} else {
V_7 = V_13 ;
V_8 = V_14 ;
}
V_9 = F_2 ( V_4 , NULL , V_15 , 0 , V_7 , 0 , 0 , & V_6 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_6 , V_8 ) ;
if ( V_9 )
goto V_16;
V_9 = F_4 ( V_6 ) ;
if ( V_9 )
goto V_16;
V_9 = F_5 ( & V_2 -> V_17 , 0 , V_6 -> V_18 . V_19 . V_20 ) ;
if ( V_9 )
goto V_16;
V_2 -> V_21 = V_6 ;
V_16:
if ( V_9 )
F_6 ( V_6 -> V_22 ) ;
return V_9 ;
}
void
F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_2 -> V_21 )
return;
F_8 ( V_2 -> V_21 ) ;
F_9 ( & V_4 -> V_23 ) ;
F_10 ( V_2 -> V_21 ) ;
F_11 ( & V_4 -> V_23 ) ;
F_6 ( V_2 -> V_21 -> V_22 ) ;
F_12 ( & V_2 -> V_17 ) ;
}
static void
F_13 ( struct V_3 * V_4 ,
struct V_24 * V_25 )
{
F_14 ( V_4 , L_1 ) ;
if ( V_25 -> V_26 )
F_15 ( V_25 -> V_26 ) ;
}
int
F_16 ( struct V_1 * V_2 , T_1 V_27 ,
int V_20 , T_1 V_28 , T_1 V_29 ,
T_1 * V_30 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_31 * V_32 = V_4 -> V_33 ;
struct V_24 * V_34 = NULL ;
struct V_35 * V_19 ;
T_1 V_36 ;
int V_37 , V_9 ;
V_19 = F_17 ( & V_2 -> V_17 , V_20 , 0 ,
V_28 , V_29 , 0 ) ;
if ( V_19 )
V_19 = F_18 ( V_19 , V_20 , 0 , V_28 , V_29 ) ;
if ( ! V_19 ) {
F_19 ( V_4 , L_2 , V_2 -> V_38 ) ;
return - V_39 ;
}
if ( V_32 -> V_40 < V_41 ) {
if ( V_2 -> V_21 -> V_18 . V_19 . V_42 == V_43 )
V_37 = V_44 ;
else
V_37 = V_45 ;
V_36 = V_2 -> V_21 -> V_18 . V_19 . V_28 << V_46 ;
} else {
V_37 = V_47 ;
V_36 = V_2 -> V_21 -> V_48 . V_36 ;
}
V_36 += V_19 -> V_28 ;
V_9 = F_20 ( V_2 , V_49 , V_36 ,
V_19 -> V_20 , V_50 , V_37 ,
& V_34 ) ;
if ( V_9 ) {
F_15 ( V_19 ) ;
F_19 ( V_4 , L_3 , V_9 ) ;
return V_9 ;
}
V_34 -> V_51 = F_13 ;
V_34 -> V_26 = V_19 ;
V_9 = F_21 ( V_2 , V_27 , V_34 ) ;
F_22 ( NULL , & V_34 ) ;
if ( V_9 ) {
F_15 ( V_19 ) ;
F_19 ( V_4 , L_4 , V_9 ) ;
return V_9 ;
}
* V_30 = V_19 -> V_28 ;
return 0 ;
}
int
F_23 ( struct V_24 * V_34 , T_1 * V_52 )
{
if ( ! V_34 || V_34 -> V_51 != F_13 )
return - V_53 ;
if ( V_52 ) {
struct V_35 * V_19 = V_34 -> V_26 ;
if ( * V_52 >= V_19 -> V_20 )
return false ;
* V_52 += V_19 -> V_28 ;
}
return 0 ;
}
int
F_24 ( struct V_3 * V_4 , void * V_54 ,
struct V_55 * V_56 )
{
struct V_31 * V_32 = V_4 -> V_33 ;
struct V_57 * V_58 = V_54 ;
struct V_1 * V_2 ;
int V_9 ;
if ( F_25 ( V_32 -> V_40 >= V_59 ) )
return - V_53 ;
V_2 = F_26 ( V_4 , V_56 , V_58 -> V_60 ) ;
if ( F_27 ( V_2 ) )
return F_28 ( V_2 ) ;
V_9 = F_16 ( V_2 , V_58 -> V_27 , V_58 -> V_20 , 0 , 0x1000 ,
& V_58 -> V_36 ) ;
F_29 ( & V_2 ) ;
return V_9 ;
}
