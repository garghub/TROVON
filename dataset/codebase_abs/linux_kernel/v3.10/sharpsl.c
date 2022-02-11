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
static int F_8 ( struct V_25 * V_26 )
{
struct V_7 * V_27 ;
struct V_28 * V_29 ;
int V_30 = 0 ;
struct V_5 * V_6 ;
struct V_31 * V_32 = V_26 -> V_33 . V_34 ;
if ( ! V_32 ) {
F_9 ( & V_26 -> V_33 , L_1 ) ;
return - V_35 ;
}
V_6 = F_10 ( sizeof( struct V_5 ) , V_36 ) ;
if ( ! V_6 ) {
F_11 ( L_2 ) ;
return - V_37 ;
}
V_29 = F_12 ( V_26 , V_38 , 0 ) ;
if ( ! V_29 ) {
F_9 ( & V_26 -> V_33 , L_3 ) ;
V_30 = - V_39 ;
goto V_40;
}
V_6 -> V_12 = F_13 ( V_29 -> V_41 , F_14 ( V_29 ) ) ;
if ( ! V_6 -> V_12 ) {
F_11 ( L_4 ) ;
V_30 = - V_42 ;
goto V_43;
}
V_27 = (struct V_7 * ) ( & V_6 -> V_8 ) ;
V_6 -> V_2 . V_9 = V_27 ;
V_6 -> V_2 . V_44 = V_45 ;
F_15 ( V_26 , V_6 ) ;
F_3 ( F_4 ( V_6 -> V_12 + V_13 ) | V_46 , V_6 -> V_12 + V_13 ) ;
V_27 -> V_47 = V_6 -> V_12 + V_48 ;
V_27 -> V_15 = V_6 -> V_12 + V_48 ;
V_27 -> V_49 = F_1 ;
V_27 -> V_50 = F_5 ;
V_27 -> V_51 = 15 ;
V_27 -> V_52 . V_17 = V_53 ;
V_27 -> V_52 . V_54 = 256 ;
V_27 -> V_52 . V_55 = 3 ;
V_27 -> V_52 . V_56 = 1 ;
V_27 -> V_57 = V_32 -> V_57 ;
V_27 -> V_52 . V_58 = V_32 -> V_59 ;
V_27 -> V_52 . V_60 = F_6 ;
V_27 -> V_52 . V_61 = F_7 ;
V_27 -> V_52 . V_62 = V_63 ;
V_30 = F_16 ( & V_6 -> V_2 , 1 ) ;
if ( V_30 )
goto V_64;
V_6 -> V_2 . V_65 = L_5 ;
V_30 = F_17 ( & V_6 -> V_2 , NULL , NULL ,
V_32 -> V_66 , V_32 -> V_67 ) ;
if ( V_30 )
goto V_68;
return 0 ;
V_68:
F_18 ( & V_6 -> V_2 ) ;
V_64:
F_15 ( V_26 , NULL ) ;
F_19 ( V_6 -> V_12 ) ;
V_43:
V_40:
F_20 ( V_6 ) ;
return V_30 ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_22 ( V_26 ) ;
F_18 ( & V_6 -> V_2 ) ;
F_15 ( V_26 , NULL ) ;
F_19 ( V_6 -> V_12 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
