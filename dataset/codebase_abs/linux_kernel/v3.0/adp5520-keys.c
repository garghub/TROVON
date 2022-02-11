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
static int T_2 F_7 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_2 . V_27 ;
struct V_28 * V_7 ;
struct V_1 * V_2 ;
int V_29 , V_5 ;
unsigned char V_30 , V_31 = 0 ;
if ( V_24 -> V_32 != V_33 ) {
F_8 ( & V_24 -> V_2 , L_1 ) ;
return - V_34 ;
}
if ( V_26 == NULL ) {
F_8 ( & V_24 -> V_2 , L_2 ) ;
return - V_34 ;
}
if ( ! ( V_26 -> V_35 && V_26 -> V_36 ) )
return - V_34 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_37 ) ;
if ( V_2 == NULL ) {
F_8 ( & V_24 -> V_2 , L_3 ) ;
return - V_38 ;
}
V_7 = F_10 () ;
if ( ! V_7 ) {
V_29 = - V_38 ;
goto V_39;
}
V_2 -> V_17 = V_24 -> V_2 . V_40 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_41 = V_24 -> V_41 ;
V_7 -> V_42 = L_4 ;
V_7 -> V_2 . V_40 = & V_24 -> V_2 ;
F_11 ( V_7 , V_2 ) ;
V_7 -> V_32 . V_43 = V_44 ;
V_7 -> V_32 . V_45 = 0x0001 ;
V_7 -> V_32 . V_46 = 0x5520 ;
V_7 -> V_32 . V_47 = 0x0001 ;
V_7 -> V_48 = sizeof( V_2 -> V_8 [ 0 ] ) ;
V_7 -> V_49 = V_26 -> V_50 ;
V_7 -> V_8 = V_2 -> V_8 ;
memcpy ( V_2 -> V_8 , V_26 -> V_51 ,
V_26 -> V_50 * V_7 -> V_48 ) ;
F_12 ( V_52 , V_7 -> V_53 ) ;
if ( V_26 -> V_54 )
F_12 ( V_55 , V_7 -> V_53 ) ;
for ( V_5 = 0 ; V_5 < V_7 -> V_49 ; V_5 ++ )
F_12 ( V_2 -> V_8 [ V_5 ] , V_7 -> V_56 ) ;
F_13 ( V_57 , V_7 -> V_56 ) ;
V_29 = F_14 ( V_7 ) ;
if ( V_29 ) {
F_8 ( & V_24 -> V_2 , L_5 ) ;
goto V_39;
}
V_30 = V_26 -> V_35 | V_26 -> V_36 ;
V_29 = F_15 ( V_2 -> V_17 , V_58 , V_30 ) ;
if ( V_30 & V_59 )
V_31 |= V_60 ;
if ( V_30 & V_61 )
V_31 |= V_62 ;
if ( V_31 )
V_29 |= F_15 ( V_2 -> V_17 , V_63 ,
V_31 ) ;
V_29 |= F_15 ( V_2 -> V_17 , V_64 ,
V_26 -> V_35 ) ;
if ( V_29 ) {
F_8 ( & V_24 -> V_2 , L_6 ) ;
V_29 = - V_65 ;
goto V_66;
}
V_2 -> V_15 . V_67 = F_4 ;
V_29 = F_16 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_68 | V_69 ) ;
if ( V_29 ) {
F_8 ( & V_24 -> V_2 , L_7 ) ;
goto V_66;
}
F_17 ( V_24 , V_2 ) ;
return 0 ;
V_66:
F_18 ( V_7 ) ;
V_7 = NULL ;
V_39:
F_19 ( V_7 ) ;
F_20 ( V_2 ) ;
return V_29 ;
}
static int T_3 F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
F_23 ( V_2 -> V_17 , & V_2 -> V_15 ,
V_68 | V_69 ) ;
F_18 ( V_2 -> V_7 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_70 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_70 ) ;
}
