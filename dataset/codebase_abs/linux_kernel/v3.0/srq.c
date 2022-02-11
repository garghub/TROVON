void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & F_2 ( V_2 ) -> V_6 ;
struct V_7 * V_8 ;
F_3 ( & V_6 -> V_9 ) ;
V_8 = F_4 ( & V_6 -> V_10 , V_3 & ( V_2 -> V_11 . V_12 - 1 ) ) ;
if ( V_8 )
F_5 ( & V_8 -> V_13 ) ;
F_6 ( & V_6 -> V_9 ) ;
if ( ! V_8 ) {
F_7 ( V_2 , L_1 , V_3 ) ;
return;
}
V_8 -> V_14 ( V_8 , V_4 ) ;
if ( F_8 ( & V_8 -> V_13 ) )
F_9 ( & V_8 -> free ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 )
{
return F_11 ( V_2 , V_16 -> V_18 , V_17 , 0 , V_19 ,
V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 )
{
return F_13 ( V_2 , 0 , V_16 ? V_16 -> V_18 : 0 , V_17 ,
V_16 ? 0 : 1 , V_21 ,
V_20 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_17 , int V_22 )
{
return F_11 ( V_2 , V_22 , V_17 , 0 , V_23 ,
V_24 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 )
{
return F_13 ( V_2 , 0 , V_16 -> V_18 , V_17 , 0 , V_25 ,
V_20 ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_26 , struct V_27 * V_28 ,
T_2 V_29 , struct V_7 * V_8 )
{
struct V_5 * V_6 = & F_2 ( V_2 ) -> V_6 ;
struct V_15 * V_16 ;
struct V_30 * V_31 ;
T_2 V_32 ;
int V_33 ;
V_8 -> V_3 = F_17 ( & V_6 -> V_34 ) ;
if ( V_8 -> V_3 == - 1 )
return - V_35 ;
V_33 = F_18 ( V_2 , & V_6 -> V_36 , V_8 -> V_3 ) ;
if ( V_33 )
goto V_37;
V_33 = F_18 ( V_2 , & V_6 -> V_38 , V_8 -> V_3 ) ;
if ( V_33 )
goto V_39;
F_19 ( & V_6 -> V_9 ) ;
V_33 = F_20 ( & V_6 -> V_10 , V_8 -> V_3 , V_8 ) ;
F_21 ( & V_6 -> V_9 ) ;
if ( V_33 )
goto V_40;
V_16 = F_22 ( V_2 ) ;
if ( F_23 ( V_16 ) ) {
V_33 = F_24 ( V_16 ) ;
goto V_41;
}
V_31 = V_16 -> V_42 ;
memset ( V_31 , 0 , sizeof *V_31 ) ;
V_31 -> V_43 = F_25 ( ( F_26 ( V_8 -> V_44 ) << 24 ) |
V_8 -> V_3 ) ;
V_31 -> V_45 = V_8 -> V_46 - 4 ;
V_31 -> V_47 = V_28 -> V_48 - V_49 ;
V_32 = F_27 ( V_2 , V_28 ) ;
V_31 -> V_50 = V_32 >> 32 ;
V_31 -> V_51 = F_25 ( V_32 & 0xffffffff ) ;
V_31 -> V_52 = F_25 ( V_26 ) ;
V_31 -> V_53 = F_28 ( V_29 ) ;
V_33 = F_10 ( V_2 , V_16 , V_8 -> V_3 ) ;
F_29 ( V_2 , V_16 ) ;
if ( V_33 )
goto V_41;
F_30 ( & V_8 -> V_13 , 1 ) ;
F_31 ( & V_8 -> free ) ;
return 0 ;
V_41:
F_19 ( & V_6 -> V_9 ) ;
F_32 ( & V_6 -> V_10 , V_8 -> V_3 ) ;
F_21 ( & V_6 -> V_9 ) ;
V_40:
F_33 ( V_2 , & V_6 -> V_38 , V_8 -> V_3 ) ;
V_39:
F_33 ( V_2 , & V_6 -> V_36 , V_8 -> V_3 ) ;
V_37:
F_34 ( & V_6 -> V_34 , V_8 -> V_3 ) ;
return V_33 ;
}
void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_5 * V_6 = & F_2 ( V_2 ) -> V_6 ;
int V_33 ;
V_33 = F_12 ( V_2 , NULL , V_8 -> V_3 ) ;
if ( V_33 )
F_7 ( V_2 , L_2 , V_33 , V_8 -> V_3 ) ;
F_19 ( & V_6 -> V_9 ) ;
F_32 ( & V_6 -> V_10 , V_8 -> V_3 ) ;
F_21 ( & V_6 -> V_9 ) ;
if ( F_8 ( & V_8 -> V_13 ) )
F_9 ( & V_8 -> free ) ;
F_36 ( & V_8 -> free ) ;
F_33 ( V_2 , & V_6 -> V_36 , V_8 -> V_3 ) ;
F_34 ( & V_6 -> V_34 , V_8 -> V_3 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_7 * V_8 , int V_22 )
{
return F_14 ( V_2 , V_8 -> V_3 , V_22 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_7 * V_8 , int * V_22 )
{
struct V_15 * V_16 ;
struct V_30 * V_31 ;
int V_33 ;
V_16 = F_22 ( V_2 ) ;
if ( F_23 ( V_16 ) )
return F_24 ( V_16 ) ;
V_31 = V_16 -> V_42 ;
V_33 = F_15 ( V_2 , V_16 , V_8 -> V_3 ) ;
if ( V_33 )
goto V_37;
* V_22 = F_39 ( V_31 -> V_22 ) ;
V_37:
F_29 ( V_2 , V_16 ) ;
return V_33 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & F_2 ( V_2 ) -> V_6 ;
int V_33 ;
F_41 ( & V_6 -> V_9 ) ;
F_42 ( & V_6 -> V_10 , V_54 ) ;
V_33 = F_43 ( & V_6 -> V_34 , V_2 -> V_11 . V_12 ,
V_2 -> V_11 . V_12 - 1 , V_2 -> V_11 . V_55 , 0 ) ;
if ( V_33 )
return V_33 ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( & F_2 ( V_2 ) -> V_6 . V_34 ) ;
}
