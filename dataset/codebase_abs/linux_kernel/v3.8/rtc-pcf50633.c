static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = F_2 ( V_4 -> time [ V_6 ] ) ;
V_2 -> V_7 = F_2 ( V_4 -> time [ V_8 ] ) ;
V_2 -> V_9 = F_2 ( V_4 -> time [ V_10 ] ) ;
V_2 -> V_11 = F_2 ( V_4 -> time [ V_12 ] ) ;
V_2 -> V_13 = F_2 ( V_4 -> time [ V_14 ] ) ;
V_2 -> V_15 = F_2 ( V_4 -> time [ V_16 ] ) - 1 ;
V_2 -> V_17 = F_2 ( V_4 -> time [ V_18 ] ) + 100 ;
}
static void F_3 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
V_4 -> time [ V_6 ] = F_4 ( V_2 -> V_5 ) ;
V_4 -> time [ V_8 ] = F_4 ( V_2 -> V_7 ) ;
V_4 -> time [ V_10 ] = F_4 ( V_2 -> V_9 ) ;
V_4 -> time [ V_12 ] = F_4 ( V_2 -> V_11 ) ;
V_4 -> time [ V_14 ] = F_4 ( V_2 -> V_13 ) ;
V_4 -> time [ V_16 ] = F_4 ( V_2 -> V_15 + 1 ) ;
V_4 -> time [ V_18 ] = F_4 ( V_2 -> V_17 % 100 ) ;
}
static int
F_5 ( struct V_19 * V_20 , unsigned int V_21 )
{
struct V_22 * V_2 = F_6 ( V_20 ) ;
int V_23 ;
if ( V_21 )
V_23 = F_7 ( V_2 -> V_4 , V_24 ) ;
else
V_23 = F_8 ( V_2 -> V_4 , V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_25 = V_21 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 , struct V_1 * V_26 )
{
struct V_22 * V_2 ;
struct V_3 V_27 ;
int V_28 ;
V_2 = F_6 ( V_20 ) ;
V_28 = F_10 ( V_2 -> V_4 , V_29 ,
V_30 ,
& V_27 . time [ 0 ] ) ;
if ( V_28 != V_30 ) {
F_11 ( V_20 , L_1 ) ;
return - V_31 ;
}
F_12 ( V_20 , L_2 ,
V_27 . time [ V_14 ] ,
V_27 . time [ V_16 ] ,
V_27 . time [ V_18 ] ,
V_27 . time [ V_10 ] ,
V_27 . time [ V_8 ] ,
V_27 . time [ V_6 ] ) ;
F_1 ( V_26 , & V_27 ) ;
F_12 ( V_20 , L_3 ,
V_26 -> V_13 , V_26 -> V_15 , V_26 -> V_17 ,
V_26 -> V_9 , V_26 -> V_7 , V_26 -> V_5 ) ;
return F_13 ( V_26 ) ;
}
static int F_14 ( struct V_19 * V_20 , struct V_1 * V_26 )
{
struct V_22 * V_2 ;
struct V_3 V_27 ;
int V_32 , V_28 = 0 ;
V_2 = F_6 ( V_20 ) ;
F_12 ( V_20 , L_3 ,
V_26 -> V_13 , V_26 -> V_15 , V_26 -> V_17 ,
V_26 -> V_9 , V_26 -> V_7 , V_26 -> V_5 ) ;
F_3 ( & V_27 , V_26 ) ;
F_12 ( V_20 , L_2 ,
V_27 . time [ V_14 ] ,
V_27 . time [ V_16 ] ,
V_27 . time [ V_18 ] ,
V_27 . time [ V_10 ] ,
V_27 . time [ V_8 ] ,
V_27 . time [ V_6 ] ) ;
V_32 = F_15 ( V_2 -> V_4 , V_24 ) ;
if ( ! V_32 )
F_8 ( V_2 -> V_4 , V_24 ) ;
V_28 = F_16 ( V_2 -> V_4 , V_29 ,
V_30 ,
& V_27 . time [ 0 ] ) ;
if ( ! V_32 )
F_7 ( V_2 -> V_4 , V_24 ) ;
return V_28 ;
}
static int F_17 ( struct V_19 * V_20 , struct V_33 * V_34 )
{
struct V_22 * V_2 ;
struct V_3 V_27 ;
int V_28 = 0 ;
V_2 = F_6 ( V_20 ) ;
V_34 -> V_21 = V_2 -> V_25 ;
V_34 -> V_35 = V_2 -> V_36 ;
V_28 = F_10 ( V_2 -> V_4 , V_37 ,
V_30 , & V_27 . time [ 0 ] ) ;
if ( V_28 != V_30 ) {
F_11 ( V_20 , L_1 ) ;
return - V_31 ;
}
F_1 ( & V_34 -> time , & V_27 ) ;
return F_13 ( & V_34 -> time ) ;
}
static int F_18 ( struct V_19 * V_20 , struct V_33 * V_34 )
{
struct V_22 * V_2 ;
struct V_3 V_27 ;
int V_32 , V_28 = 0 ;
V_2 = F_6 ( V_20 ) ;
F_3 ( & V_27 , & V_34 -> time ) ;
V_27 . time [ V_12 ] = 7 ;
V_32 = F_15 ( V_2 -> V_4 , V_24 ) ;
if ( ! V_32 )
F_8 ( V_2 -> V_4 , V_24 ) ;
V_28 = F_16 ( V_2 -> V_4 , V_37 ,
V_30 , & V_27 . time [ 0 ] ) ;
if ( ! V_34 -> V_21 )
V_2 -> V_36 = 0 ;
if ( ! V_32 || V_34 -> V_21 )
F_7 ( V_2 -> V_4 , V_24 ) ;
V_2 -> V_25 = V_34 -> V_21 ;
return V_28 ;
}
static void F_19 ( int V_38 , void * V_39 )
{
struct V_22 * V_2 = V_39 ;
F_20 ( V_2 -> V_40 , 1 , V_41 | V_42 ) ;
V_2 -> V_36 = 1 ;
}
static int F_21 ( struct V_43 * V_44 )
{
struct V_22 * V_2 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_4 = F_23 ( V_44 -> V_20 . V_47 ) ;
F_24 ( V_44 , V_2 ) ;
V_2 -> V_40 = F_25 ( L_4 , & V_44 -> V_20 ,
& V_48 , V_49 ) ;
if ( F_26 ( V_2 -> V_40 ) ) {
int V_28 = F_27 ( V_2 -> V_40 ) ;
F_28 ( V_2 ) ;
return V_28 ;
}
F_29 ( V_2 -> V_4 , V_24 ,
F_19 , V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_43 * V_44 )
{
struct V_22 * V_2 ;
V_2 = F_31 ( V_44 ) ;
F_32 ( V_2 -> V_4 , V_24 ) ;
F_33 ( V_2 -> V_40 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
