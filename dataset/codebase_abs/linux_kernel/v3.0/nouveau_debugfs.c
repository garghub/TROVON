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
F_2 ( V_2 , L_14 , V_8 -> V_21 . V_22 ) ;
F_2 ( V_2 , L_15 , V_8 -> V_21 . V_23 ) ;
return 0 ;
}
int
F_4 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_8 -> V_26 -> V_30 ;
int V_31 ;
if ( ! V_25 -> V_32 . V_33 ) {
V_25 -> V_32 . V_33 =
F_5 ( L_16 , V_29 -> V_34 ) ;
if ( ! V_25 -> V_32 . V_33 )
return - V_35 ;
}
snprintf ( V_8 -> V_32 . V_36 , 32 , L_17 , V_8 -> V_10 ) ;
V_8 -> V_32 . V_37 . V_36 = V_8 -> V_32 . V_36 ;
V_8 -> V_32 . V_37 . V_38 = F_1 ;
V_8 -> V_32 . V_37 . V_39 = 0 ;
V_8 -> V_32 . V_37 . V_3 = V_8 ;
V_31 = F_6 ( & V_8 -> V_32 . V_37 , 1 ,
V_25 -> V_32 . V_33 ,
V_8 -> V_26 -> V_30 ) ;
if ( V_31 == 0 )
V_8 -> V_32 . V_40 = true ;
return V_31 ;
}
void
F_7 ( struct V_7 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_26 -> V_27 ;
if ( ! V_8 -> V_32 . V_40 )
return;
F_8 ( & V_8 -> V_32 . V_37 , 1 , V_8 -> V_26 -> V_30 ) ;
V_8 -> V_32 . V_40 = false ;
if ( V_8 == V_25 -> V_41 ) {
F_9 ( V_25 -> V_32 . V_33 ) ;
V_25 -> V_32 . V_33 = NULL ;
}
}
static int
F_10 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_28 * V_29 = V_5 -> V_29 ;
struct V_42 * V_26 = V_29 -> V_26 ;
struct V_24 * V_25 = V_26 -> V_27 ;
T_1 V_43 ;
V_43 = F_11 ( V_26 , V_25 -> V_44 >= 0x40 ? 0x88000 : 0x1800 ) ;
F_2 ( V_2 , L_18 , F_11 ( V_26 , V_45 ) ) ;
F_2 ( V_2 , L_19 ,
V_43 & 0xffff , V_43 >> 16 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_28 * V_29 = V_5 -> V_29 ;
struct V_24 * V_25 = V_29 -> V_26 -> V_27 ;
F_2 ( V_2 , L_20 , ( int ) ( V_25 -> V_46 >> 10 ) ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_24 * V_25 = V_5 -> V_29 -> V_26 -> V_27 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_25 -> V_48 . V_49 ; V_47 ++ )
F_2 ( V_2 , L_21 , V_25 -> V_48 . V_3 [ V_47 ] ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_24 * V_25 = V_5 -> V_29 -> V_26 -> V_27 ;
int V_31 ;
V_31 = F_15 ( & V_25 -> V_50 . V_51 , V_52 ) ;
if ( V_31 )
F_2 ( V_2 , L_22 , V_31 ) ;
else
F_2 ( V_2 , L_23 ) ;
return 0 ;
}
int
F_16 ( struct V_28 * V_29 )
{
F_6 ( V_53 , V_54 ,
V_29 -> V_34 , V_29 ) ;
return 0 ;
}
void
F_17 ( struct V_28 * V_29 )
{
F_8 ( V_53 , V_54 ,
V_29 ) ;
}
