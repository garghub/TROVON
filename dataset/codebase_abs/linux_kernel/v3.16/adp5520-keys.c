static void F_1 ( struct V_1 * V_2 ,
unsigned short V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_3 & ( 1 << V_5 ) )
F_2 ( V_2 -> V_7 , V_2 -> V_8 [ V_5 ] , V_4 ) ;
F_3 ( V_2 -> V_7 ) ;
}
static int F_4 ( struct V_9 * V_10 ,
unsigned long V_11 , void * V_12 )
{
struct V_1 * V_2 ;
T_1 V_13 , V_14 ;
unsigned short V_3 ;
V_2 = F_5 ( V_10 , struct V_1 , V_15 ) ;
if ( V_11 & V_16 ) {
F_6 ( V_2 -> V_17 , V_18 , & V_13 ) ;
F_6 ( V_2 -> V_17 , V_19 , & V_14 ) ;
V_3 = ( V_14 << 8 ) | V_13 ;
F_6 ( V_2 -> V_17 , V_18 , & V_13 ) ;
F_6 ( V_2 -> V_17 , V_19 , & V_14 ) ;
V_3 |= ( V_14 << 8 ) | V_13 ;
F_1 ( V_2 , V_3 , 1 ) ;
}
if ( V_11 & V_20 ) {
F_6 ( V_2 -> V_17 , V_21 , & V_13 ) ;
F_6 ( V_2 -> V_17 , V_22 , & V_14 ) ;
V_3 = ( V_14 << 8 ) | V_13 ;
F_6 ( V_2 -> V_17 , V_21 , & V_13 ) ;
F_6 ( V_2 -> V_17 , V_22 , & V_14 ) ;
V_3 |= ( V_14 << 8 ) | V_13 ;
F_1 ( V_2 , V_3 , 0 ) ;
}
return 0 ;
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_8 ( & V_24 -> V_2 ) ;
struct V_27 * V_7 ;
struct V_1 * V_2 ;
int V_28 , V_5 ;
unsigned char V_29 , V_30 = 0 ;
if ( V_24 -> V_31 != V_32 ) {
F_9 ( & V_24 -> V_2 , L_1 ) ;
return - V_33 ;
}
if ( ! V_26 ) {
F_9 ( & V_24 -> V_2 , L_2 ) ;
return - V_33 ;
}
if ( ! ( V_26 -> V_34 && V_26 -> V_35 ) )
return - V_33 ;
V_2 = F_10 ( & V_24 -> V_2 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 ) {
F_9 ( & V_24 -> V_2 , L_3 ) ;
return - V_37 ;
}
V_7 = F_11 ( & V_24 -> V_2 ) ;
if ( ! V_7 )
return - V_37 ;
V_2 -> V_17 = V_24 -> V_2 . V_38 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_39 = V_24 -> V_39 ;
V_7 -> V_40 = L_4 ;
V_7 -> V_2 . V_38 = & V_24 -> V_2 ;
F_12 ( V_7 , V_2 ) ;
V_7 -> V_31 . V_41 = V_42 ;
V_7 -> V_31 . V_43 = 0x0001 ;
V_7 -> V_31 . V_44 = 0x5520 ;
V_7 -> V_31 . V_45 = 0x0001 ;
V_7 -> V_46 = sizeof( V_2 -> V_8 [ 0 ] ) ;
V_7 -> V_47 = V_26 -> V_48 ;
V_7 -> V_8 = V_2 -> V_8 ;
memcpy ( V_2 -> V_8 , V_26 -> V_49 ,
V_26 -> V_48 * V_7 -> V_46 ) ;
F_13 ( V_50 , V_7 -> V_51 ) ;
if ( V_26 -> V_52 )
F_13 ( V_53 , V_7 -> V_51 ) ;
for ( V_5 = 0 ; V_5 < V_7 -> V_47 ; V_5 ++ )
F_13 ( V_2 -> V_8 [ V_5 ] , V_7 -> V_54 ) ;
F_14 ( V_55 , V_7 -> V_54 ) ;
V_28 = F_15 ( V_7 ) ;
if ( V_28 ) {
F_9 ( & V_24 -> V_2 , L_5 ) ;
return V_28 ;
}
V_29 = V_26 -> V_34 | V_26 -> V_35 ;
V_28 = F_16 ( V_2 -> V_17 , V_56 , V_29 ) ;
if ( V_29 & V_57 )
V_30 |= V_58 ;
if ( V_29 & V_59 )
V_30 |= V_60 ;
if ( V_30 )
V_28 |= F_16 ( V_2 -> V_17 , V_61 ,
V_30 ) ;
V_28 |= F_16 ( V_2 -> V_17 , V_62 ,
V_26 -> V_34 ) ;
if ( V_28 ) {
F_9 ( & V_24 -> V_2 , L_6 ) ;
return - V_63 ;
}
V_2 -> V_15 . V_64 = F_4 ;
V_28 = F_17 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_65 | V_66 ) ;
if ( V_28 ) {
F_9 ( & V_24 -> V_2 , L_7 ) ;
return V_28 ;
}
F_18 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
F_21 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_65 | V_66 ) ;
return 0 ;
}
