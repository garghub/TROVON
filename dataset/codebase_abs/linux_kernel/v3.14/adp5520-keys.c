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
if ( V_26 == NULL ) {
F_9 ( & V_24 -> V_2 , L_2 ) ;
return - V_33 ;
}
if ( ! ( V_26 -> V_34 && V_26 -> V_35 ) )
return - V_33 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_36 ) ;
if ( V_2 == NULL ) {
F_9 ( & V_24 -> V_2 , L_3 ) ;
return - V_37 ;
}
V_7 = F_11 () ;
if ( ! V_7 ) {
V_28 = - V_37 ;
goto V_38;
}
V_2 -> V_17 = V_24 -> V_2 . V_39 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_40 = V_24 -> V_40 ;
V_7 -> V_41 = L_4 ;
V_7 -> V_2 . V_39 = & V_24 -> V_2 ;
F_12 ( V_7 , V_2 ) ;
V_7 -> V_31 . V_42 = V_43 ;
V_7 -> V_31 . V_44 = 0x0001 ;
V_7 -> V_31 . V_45 = 0x5520 ;
V_7 -> V_31 . V_46 = 0x0001 ;
V_7 -> V_47 = sizeof( V_2 -> V_8 [ 0 ] ) ;
V_7 -> V_48 = V_26 -> V_49 ;
V_7 -> V_8 = V_2 -> V_8 ;
memcpy ( V_2 -> V_8 , V_26 -> V_50 ,
V_26 -> V_49 * V_7 -> V_47 ) ;
F_13 ( V_51 , V_7 -> V_52 ) ;
if ( V_26 -> V_53 )
F_13 ( V_54 , V_7 -> V_52 ) ;
for ( V_5 = 0 ; V_5 < V_7 -> V_48 ; V_5 ++ )
F_13 ( V_2 -> V_8 [ V_5 ] , V_7 -> V_55 ) ;
F_14 ( V_56 , V_7 -> V_55 ) ;
V_28 = F_15 ( V_7 ) ;
if ( V_28 ) {
F_9 ( & V_24 -> V_2 , L_5 ) ;
goto V_38;
}
V_29 = V_26 -> V_34 | V_26 -> V_35 ;
V_28 = F_16 ( V_2 -> V_17 , V_57 , V_29 ) ;
if ( V_29 & V_58 )
V_30 |= V_59 ;
if ( V_29 & V_60 )
V_30 |= V_61 ;
if ( V_30 )
V_28 |= F_16 ( V_2 -> V_17 , V_62 ,
V_30 ) ;
V_28 |= F_16 ( V_2 -> V_17 , V_63 ,
V_26 -> V_34 ) ;
if ( V_28 ) {
F_9 ( & V_24 -> V_2 , L_6 ) ;
V_28 = - V_64 ;
goto V_65;
}
V_2 -> V_15 . V_66 = F_4 ;
V_28 = F_17 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_67 | V_68 ) ;
if ( V_28 ) {
F_9 ( & V_24 -> V_2 , L_7 ) ;
goto V_65;
}
F_18 ( V_24 , V_2 ) ;
return 0 ;
V_65:
F_19 ( V_7 ) ;
V_7 = NULL ;
V_38:
F_20 ( V_7 ) ;
F_21 ( V_2 ) ;
return V_28 ;
}
static int F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_23 ( V_24 ) ;
F_24 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_67 | V_68 ) ;
F_19 ( V_2 -> V_7 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
