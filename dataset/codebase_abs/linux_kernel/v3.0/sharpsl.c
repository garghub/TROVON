static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_4 & V_10 ) {
unsigned char V_11 = V_4 & 0x07 ;
V_11 |= ( V_4 & 0x01 ) << 4 ;
V_11 ^= 0x11 ;
F_3 ( ( F_4 ( V_6 -> V_12 + V_13 ) & ~ 0x17 ) | V_11 , V_6 -> V_12 + V_13 ) ;
}
if ( V_3 != V_14 )
F_3 ( V_3 , V_8 -> V_15 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ! ( ( F_4 ( V_6 -> V_12 + V_13 ) & V_16 ) == 0 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( 0 , V_6 -> V_12 + V_18 ) ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_19 , T_1 * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_20 [ 0 ] = ~ F_4 ( V_6 -> V_12 + V_21 ) ;
V_20 [ 1 ] = ~ F_4 ( V_6 -> V_12 + V_22 ) ;
V_20 [ 2 ] = ( ~ F_4 ( V_6 -> V_12 + V_23 ) << 2 ) | 0x03 ;
return F_4 ( V_6 -> V_12 + V_24 ) != 0 ;
}
static int T_2 F_8 ( struct V_25 * V_26 )
{
struct V_7 * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
struct V_31 * V_32 ;
int V_33 = 0 ;
struct V_5 * V_6 ;
struct V_34 * V_35 = V_26 -> V_36 . V_37 ;
if ( ! V_35 ) {
F_9 ( & V_26 -> V_36 , L_1 ) ;
return - V_38 ;
}
V_6 = F_10 ( sizeof( struct V_5 ) , V_39 ) ;
if ( ! V_6 ) {
F_11 ( L_2 ) ;
return - V_40 ;
}
V_32 = F_12 ( V_26 , V_41 , 0 ) ;
if ( ! V_32 ) {
F_9 ( & V_26 -> V_36 , L_3 ) ;
V_33 = - V_42 ;
goto V_43;
}
V_6 -> V_12 = F_13 ( V_32 -> V_44 , F_14 ( V_32 ) ) ;
if ( ! V_6 -> V_12 ) {
F_11 ( L_4 ) ;
V_33 = - V_45 ;
goto V_46;
}
V_27 = (struct V_7 * ) ( & V_6 -> V_8 ) ;
V_6 -> V_2 . V_9 = V_27 ;
V_6 -> V_2 . V_47 = V_48 ;
F_15 ( V_26 , V_6 ) ;
F_3 ( F_4 ( V_6 -> V_12 + V_13 ) | V_49 , V_6 -> V_12 + V_13 ) ;
V_27 -> V_50 = V_6 -> V_12 + V_51 ;
V_27 -> V_15 = V_6 -> V_12 + V_51 ;
V_27 -> V_52 = F_1 ;
V_27 -> V_53 = F_5 ;
V_27 -> V_54 = 15 ;
V_27 -> V_55 . V_17 = V_56 ;
V_27 -> V_55 . V_57 = 256 ;
V_27 -> V_55 . V_58 = 3 ;
V_27 -> V_59 = V_35 -> V_59 ;
V_27 -> V_55 . V_60 = V_35 -> V_61 ;
V_27 -> V_55 . V_62 = F_6 ;
V_27 -> V_55 . V_63 = F_7 ;
V_27 -> V_55 . V_64 = V_65 ;
V_33 = F_16 ( & V_6 -> V_2 , 1 ) ;
if ( V_33 )
goto V_66;
V_6 -> V_2 . V_67 = L_5 ;
V_30 = F_17 ( & V_6 -> V_2 , V_68 , & V_29 , 0 ) ;
if ( V_30 <= 0 ) {
V_30 = V_35 -> V_30 ;
V_29 = V_35 -> V_69 ;
}
V_33 = F_18 ( & V_6 -> V_2 , V_29 ,
V_30 ) ;
if ( V_33 )
goto V_70;
return 0 ;
V_70:
F_19 ( & V_6 -> V_2 ) ;
V_66:
F_15 ( V_26 , NULL ) ;
F_20 ( V_6 -> V_12 ) ;
V_46:
V_43:
F_21 ( V_6 ) ;
return V_33 ;
}
static int T_3 F_22 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_23 ( V_26 ) ;
F_19 ( & V_6 -> V_2 ) ;
F_15 ( V_26 , NULL ) ;
F_20 ( V_6 -> V_12 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_71 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_71 ) ;
}
