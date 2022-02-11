static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_2 * V_3 , int V_5 ,
unsigned int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_4 = F_3 ( V_3 ) ;
if ( V_6 & V_9 ) {
unsigned char V_10 = V_6 & 0x07 ;
V_10 |= ( V_6 & 0x01 ) << 4 ;
V_10 ^= 0x11 ;
F_5 ( ( F_6 ( V_7 -> V_11 + V_12 ) & ~ 0x17 ) | V_10 , V_7 -> V_11 + V_12 ) ;
}
if ( V_5 != V_13 )
F_5 ( V_5 , V_4 -> V_14 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return ! ( ( F_6 ( V_7 -> V_11 + V_12 ) & V_15 ) == 0 ) ;
}
static void F_8 ( struct V_2 * V_3 , int V_16 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_5 ( 0 , V_7 -> V_11 + V_17 ) ;
}
static int F_9 ( struct V_2 * V_3 , const T_1 * V_18 , T_1 * V_19 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_19 [ 0 ] = ~ F_6 ( V_7 -> V_11 + V_20 ) ;
V_19 [ 1 ] = ~ F_6 ( V_7 -> V_11 + V_21 ) ;
V_19 [ 2 ] = ( ~ F_6 ( V_7 -> V_11 + V_22 ) << 2 ) | 0x03 ;
return F_6 ( V_7 -> V_11 + V_23 ) != 0 ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_8 * V_26 ;
struct V_2 * V_3 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
struct V_1 * V_7 ;
struct V_30 * V_31 = F_11 ( & V_25 -> V_32 ) ;
if ( ! V_31 ) {
F_12 ( & V_25 -> V_32 , L_1 ) ;
return - V_33 ;
}
V_7 = F_13 ( sizeof( struct V_1 ) , V_34 ) ;
if ( ! V_7 )
return - V_35 ;
V_28 = F_14 ( V_25 , V_36 , 0 ) ;
if ( ! V_28 ) {
F_12 ( & V_25 -> V_32 , L_2 ) ;
V_29 = - V_37 ;
goto V_38;
}
V_7 -> V_11 = F_15 ( V_28 -> V_39 , F_16 ( V_28 ) ) ;
if ( ! V_7 -> V_11 ) {
F_12 ( & V_25 -> V_32 , L_3 ) ;
V_29 = - V_40 ;
goto V_41;
}
V_26 = (struct V_8 * ) ( & V_7 -> V_4 ) ;
V_3 = F_17 ( V_26 ) ;
V_3 -> V_32 . V_42 = & V_25 -> V_32 ;
F_18 ( V_25 , V_7 ) ;
F_5 ( F_6 ( V_7 -> V_11 + V_12 ) | V_43 , V_7 -> V_11 + V_12 ) ;
V_26 -> V_44 = V_7 -> V_11 + V_45 ;
V_26 -> V_14 = V_7 -> V_11 + V_45 ;
V_26 -> V_46 = F_4 ;
V_26 -> V_47 = F_7 ;
V_26 -> V_48 = 15 ;
V_26 -> V_49 . V_16 = V_50 ;
V_26 -> V_49 . V_51 = 256 ;
V_26 -> V_49 . V_52 = 3 ;
V_26 -> V_49 . V_53 = 1 ;
V_26 -> V_54 = V_31 -> V_54 ;
V_26 -> V_49 . V_55 = V_31 -> V_56 ;
V_26 -> V_49 . V_57 = F_8 ;
V_26 -> V_49 . V_58 = F_9 ;
V_26 -> V_49 . V_59 = V_60 ;
V_29 = F_19 ( V_3 , 1 ) ;
if ( V_29 )
goto V_61;
V_3 -> V_62 = L_4 ;
V_29 = F_20 ( V_3 , NULL , NULL ,
V_31 -> V_63 , V_31 -> V_64 ) ;
if ( V_29 )
goto V_65;
return 0 ;
V_65:
F_21 ( V_3 ) ;
V_61:
F_22 ( V_7 -> V_11 ) ;
V_41:
V_38:
F_23 ( V_7 ) ;
return V_29 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_7 = F_25 ( V_25 ) ;
F_21 ( F_17 ( & V_7 -> V_4 ) ) ;
F_22 ( V_7 -> V_11 ) ;
F_23 ( V_7 ) ;
return 0 ;
}
