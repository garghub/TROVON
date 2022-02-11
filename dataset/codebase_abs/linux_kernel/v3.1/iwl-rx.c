int F_1 ( const struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - V_2 -> V_5 ;
if ( V_3 <= 0 )
V_3 += V_6 ;
V_3 -= 2 ;
if ( V_3 < 0 )
V_3 = 0 ;
return V_3 ;
}
void
F_2 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
unsigned long V_9 ;
T_1 V_10 = V_8 -> V_11 . V_10 ;
T_1 V_12 ;
F_3 ( & V_2 -> V_13 , V_9 ) ;
if ( V_2 -> V_14 == 0 )
goto V_15;
if ( F_4 ( V_16 , & V_8 -> V_17 ) ) {
V_12 = F_5 ( V_8 , V_18 ) ;
if ( V_12 & V_19 ) {
F_6 ( V_8 ,
L_1
L_2 , V_12 ) ;
F_7 ( V_8 , V_20 ,
V_21 ) ;
goto V_15;
}
V_2 -> V_22 = ( V_2 -> V_5 & ~ 0x7 ) ;
F_8 ( V_8 , V_10 ,
V_2 -> V_22 ) ;
} else {
V_2 -> V_22 = ( V_2 -> V_5 & ~ 0x7 ) ;
F_8 ( V_8 , V_10 ,
V_2 -> V_22 ) ;
}
V_2 -> V_14 = 0 ;
V_15:
F_9 ( & V_2 -> V_13 , V_9 ) ;
}
int F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_23 = & V_8 -> V_23 ;
struct V_24 * V_25 = & V_8 -> V_26 -> V_25 ;
int V_27 ;
F_11 ( & V_23 -> V_13 ) ;
F_12 ( & V_23 -> V_28 ) ;
F_12 ( & V_23 -> V_29 ) ;
V_23 -> V_30 = F_13 ( V_25 , 4 * V_6 , & V_23 -> V_31 ,
V_32 ) ;
if ( ! V_23 -> V_30 )
goto V_33;
V_23 -> V_34 = F_13 ( V_25 , sizeof( struct V_35 ) ,
& V_23 -> V_36 , V_32 ) ;
if ( ! V_23 -> V_34 )
goto V_37;
for ( V_27 = 0 ; V_27 < V_38 + V_6 ; V_27 ++ )
F_14 ( & V_23 -> V_39 [ V_27 ] . V_40 , & V_23 -> V_29 ) ;
V_23 -> V_4 = V_23 -> V_5 = 0 ;
V_23 -> V_22 = 0 ;
V_23 -> V_41 = 0 ;
V_23 -> V_14 = 0 ;
return 0 ;
V_37:
F_15 ( & V_8 -> V_26 -> V_25 , 4 * V_6 , V_23 -> V_30 ,
V_23 -> V_31 ) ;
V_33:
return - V_42 ;
}
void F_16 ( struct V_7 * V_8 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = F_17 ( V_44 ) ;
struct V_47 * V_48 = & ( V_46 -> V_49 . V_50 ) ;
if ( ! V_48 -> V_51 ) {
F_18 ( V_8 ,
L_3 ) ;
return;
}
memcpy ( & V_8 -> V_52 , V_48 , sizeof( * V_48 ) ) ;
V_8 -> V_53 |= V_54 ;
}
int F_19 ( struct V_7 * V_8 ,
struct V_55 * V_56 ,
T_1 V_57 ,
struct V_58 * V_59 )
{
T_2 V_60 = F_20 ( V_56 -> V_61 ) ;
if ( V_8 -> V_62 [ V_63 ] . V_64 . V_65 &
V_66 )
return 0 ;
if ( ! ( V_60 & V_67 ) )
return 0 ;
F_21 ( V_8 , L_4 , V_57 ) ;
switch ( V_57 & V_68 ) {
case V_69 :
if ( ( V_57 & V_70 ) ==
V_71 )
break;
case V_72 :
if ( ( V_57 & V_70 ) ==
V_73 ) {
F_21 ( V_8 , L_5 ) ;
return - 1 ;
}
case V_74 :
if ( ( V_57 & V_70 ) ==
V_75 ) {
F_21 ( V_8 , L_6 ) ;
V_59 -> V_76 |= V_77 ;
}
break;
default:
break;
}
return 0 ;
}
