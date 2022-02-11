static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_3 ;
F_2 ( V_2 , L_1 , V_8 -> V_10 ) ;
F_2 ( V_2 , L_2 ) ;
F_2 ( V_2 , L_3 , V_8 -> V_11 ) ;
F_2 ( V_2 , L_4 , V_8 -> V_12 . V_13 << 2 ) ;
F_2 ( V_2 , L_5 , V_8 -> V_12 . V_14 << 2 ) ;
F_2 ( V_2 , L_6 , V_8 -> V_12 . V_15 << 2 ) ;
F_2 ( V_2 , L_7 , V_8 -> V_12 . free << 2 ) ;
if ( V_8 -> V_12 . V_16 ) {
F_2 ( V_2 , L_8 , V_8 -> V_12 . V_16 ) ;
F_2 ( V_2 , L_9 , V_8 -> V_12 . V_17 ) ;
F_2 ( V_2 , L_10 , V_8 -> V_12 . V_18 ) ;
}
F_2 ( V_2 , L_11 ) ;
F_2 ( V_2 , L_12 ,
F_3 ( V_8 , V_8 -> V_19 ) ) ;
F_2 ( V_2 , L_6 ,
F_3 ( V_8 , V_8 -> V_20 ) ) ;
if ( V_8 -> V_12 . V_16 ) {
F_2 ( V_2 , L_13 ,
F_3 ( V_8 , 0x88 ) ) ;
F_2 ( V_2 , L_9 ,
F_3 ( V_8 , 0x8c ) ) ;
}
return 0 ;
}
int
F_4 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = V_8 -> V_23 -> V_24 ;
struct V_25 * V_26 = V_8 -> V_23 -> V_27 ;
int V_28 ;
if ( ! V_22 -> V_29 . V_30 ) {
V_22 -> V_29 . V_30 =
F_5 ( L_14 , V_26 -> V_31 ) ;
if ( ! V_22 -> V_29 . V_30 )
return - V_32 ;
}
snprintf ( V_8 -> V_29 . V_33 , 32 , L_15 , V_8 -> V_10 ) ;
V_8 -> V_29 . V_34 . V_33 = V_8 -> V_29 . V_33 ;
V_8 -> V_29 . V_34 . V_35 = F_1 ;
V_8 -> V_29 . V_34 . V_36 = 0 ;
V_8 -> V_29 . V_34 . V_3 = V_8 ;
V_28 = F_6 ( & V_8 -> V_29 . V_34 , 1 ,
V_22 -> V_29 . V_30 ,
V_8 -> V_23 -> V_27 ) ;
if ( V_28 == 0 )
V_8 -> V_29 . V_37 = true ;
return V_28 ;
}
void
F_7 ( struct V_7 * V_8 )
{
struct V_21 * V_22 = V_8 -> V_23 -> V_24 ;
if ( ! V_8 -> V_29 . V_37 )
return;
F_8 ( & V_8 -> V_29 . V_34 , 1 , V_8 -> V_23 -> V_27 ) ;
V_8 -> V_29 . V_37 = false ;
if ( V_8 == V_22 -> V_38 ) {
F_9 ( V_22 -> V_29 . V_30 ) ;
V_22 -> V_29 . V_30 = NULL ;
}
}
static int
F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_25 * V_26 = V_5 -> V_26 ;
struct V_39 * V_23 = V_26 -> V_23 ;
struct V_21 * V_22 = V_23 -> V_24 ;
T_1 V_40 ;
V_40 = F_11 ( V_23 , V_22 -> V_41 >= 0x40 ? 0x88000 : 0x1800 ) ;
F_2 ( V_2 , L_16 , F_11 ( V_23 , V_42 ) ) ;
F_2 ( V_2 , L_17 ,
V_40 & 0xffff , V_40 >> 16 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_25 * V_26 = V_5 -> V_26 ;
struct V_21 * V_22 = V_26 -> V_23 -> V_24 ;
F_2 ( V_2 , L_18 , ( int ) ( V_22 -> V_43 >> 10 ) ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_21 * V_22 = V_5 -> V_26 -> V_23 -> V_24 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_22 -> V_45 . V_46 ; V_44 ++ )
F_2 ( V_2 , L_19 , V_22 -> V_45 . V_3 [ V_44 ] ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_21 * V_22 = V_5 -> V_26 -> V_23 -> V_24 ;
int V_28 ;
V_28 = F_15 ( & V_22 -> V_47 . V_48 , V_49 ) ;
if ( V_28 )
F_2 ( V_2 , L_20 , V_28 ) ;
else
F_2 ( V_2 , L_21 ) ;
return 0 ;
}
int
F_16 ( struct V_25 * V_26 )
{
F_6 ( V_50 , V_51 ,
V_26 -> V_31 , V_26 ) ;
return 0 ;
}
void
F_17 ( struct V_25 * V_26 )
{
F_8 ( V_50 , V_51 ,
V_26 ) ;
}
