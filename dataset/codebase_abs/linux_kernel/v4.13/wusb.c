static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 = V_2 / 32 ;
T_1 V_4 = 1 << ( V_2 % 32 ) ;
F_2 ( V_4 , V_1 -> V_5 + V_6 + V_3 ) ;
return F_3 ( & V_1 -> V_7 -> V_8 ,
V_1 -> V_5 + V_6 + V_3 , V_4 , 0 ,
100 , L_1 ) ;
}
int F_4 ( struct V_9 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_6 ( V_1 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
void F_8 ( struct V_9 * V_9 , int V_10 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
T_1 V_11 , V_12 ;
int V_13 ;
F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
V_12 = F_11 ( V_1 -> V_5 + V_14 ) & V_15 ;
V_11 = ( V_12 + ( ( V_10 * 8 ) << 7 ) ) & 0x00ffffff ;
V_13 = F_12 ( V_1 , V_16 , V_11 , NULL , 0 ) ;
if ( V_13 == 0 )
F_13 ( V_10 ) ;
}
int F_14 ( struct V_9 * V_9 , T_2 V_17 , T_2 V_18 ,
T_2 V_19 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
T_1 V_22 ;
V_22 = ( V_17 << 24 )
| ( V_18 << 16 )
| ( V_21 -> V_23 << 8 )
| V_19 ;
return F_12 ( V_1 , V_24 , V_22 , V_21 , V_21 -> V_23 ) ;
}
int F_15 ( struct V_9 * V_9 , T_2 V_19 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
T_1 V_22 ;
V_22 = V_19 ;
return F_12 ( V_1 , V_25 , V_22 , NULL , 0 ) ;
}
int F_16 ( struct V_9 * V_9 , T_3 V_26 , const struct V_27 * V_28 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
if ( V_26 >= 0 )
F_17 ( V_1 , V_29 , F_18 ( V_26 ) ) ;
return F_12 ( V_1 , V_30 , 0 , ( void * ) V_28 , sizeof( * V_28 ) ) ;
}
int F_19 ( struct V_9 * V_9 , struct V_31 * V_31 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
int V_2 = V_31 -> V_32 ;
struct V_33 * V_34 = & V_1 -> V_35 [ V_2 ] ;
int V_13 ;
F_20 ( & V_1 -> V_36 ) ;
F_21 ( V_34 -> V_37 , & V_31 -> V_38 ) ;
V_34 -> V_39 &= ~ ( V_40 | V_41 ) ;
V_34 -> V_39 |= F_22 ( V_31 -> V_42 ) ;
V_13 = F_1 ( V_1 , V_2 ) ;
F_23 ( & V_1 -> V_36 ) ;
return V_13 ;
}
int F_24 ( struct V_9 * V_9 , T_2 V_17 , T_2 V_43 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
T_1 V_44 ;
V_44 = V_45
| F_25 ( V_17 )
| F_26 ( V_43 ) ;
F_2 ( V_44 , V_1 -> V_5 + V_46 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_1 , T_2 V_47 , T_4 V_48 ,
const void * V_49 , T_5 V_50 , bool V_51 )
{
T_4 V_52 ;
T_4 V_53 [ 4 ] ;
int V_54 ;
int V_13 ;
memcpy ( V_53 , V_49 , V_50 ) ;
V_52 = V_55 | F_28 ( V_47 ) ;
if ( V_51 )
V_52 |= V_56 ;
F_2 ( V_48 , V_1 -> V_5 + V_57 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ )
F_2 ( V_53 [ V_54 ] , V_1 -> V_5 + V_58 + 4 * V_54 ) ;
F_2 ( V_52 , V_1 -> V_5 + V_59 ) ;
V_13 = F_3 ( & V_1 -> V_7 -> V_8 , V_1 -> V_5 + V_59 ,
V_55 , 0 , 100 , L_2 ) ;
return V_13 ;
}
int F_29 ( struct V_9 * V_9 , T_2 V_32 , T_1 V_48 ,
const void * V_60 , T_5 V_50 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
struct V_33 * V_34 = & V_1 -> V_35 [ V_32 ] ;
int V_13 ;
F_20 ( & V_1 -> V_36 ) ;
if ( V_60 ) {
V_13 = F_27 ( V_1 , V_32 , V_48 , V_60 , V_50 , false ) ;
if ( V_13 )
goto V_61;
V_34 -> V_39 &= ~ V_62 ;
V_34 -> V_39 |= V_63 | F_30 ( V_32 ) ;
} else
V_34 -> V_39 &= ~ V_63 ;
V_13 = F_1 ( V_1 , V_32 ) ;
V_61:
F_23 ( & V_1 -> V_36 ) ;
return V_13 ;
}
int F_31 ( struct V_9 * V_9 , T_1 V_48 ,
const void * V_64 , T_5 V_50 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
int V_13 ;
F_20 ( & V_1 -> V_36 ) ;
V_13 = F_27 ( V_1 , V_1 -> V_65 , V_48 , V_64 , V_50 , true ) ;
F_23 ( & V_1 -> V_36 ) ;
return V_13 ;
}
int F_32 ( struct V_1 * V_1 , T_2 V_66 )
{
F_17 ( V_1 , V_67 , F_33 ( V_66 ) ) ;
return 0 ;
}
