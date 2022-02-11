static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 -> V_5 ) ;
if ( V_6 ) {
F_6 ( V_2 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static inline void F_7 ( struct V_3 * V_4 , T_1 V_7 ,
T_1 V_8 )
{
F_8 ( V_7 , V_4 -> V_9 + V_8 ) ;
}
static inline T_1 F_9 ( struct V_3 * V_4 , T_1 V_8 )
{
return F_10 ( V_4 -> V_9 + V_8 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
T_1 V_10 , V_11 , V_12 ;
V_10 = F_9 ( V_4 , V_13 ) &
~ V_14 ;
V_11 = F_9 ( V_4 , V_15 ) ;
V_12 = F_9 ( V_4 , V_16 ) ;
F_12 ( V_4 -> V_17 ) ;
F_13 ( V_4 -> V_17 ) ;
F_7 ( V_4 , V_10 , V_13 ) ;
F_7 ( V_4 , V_11 , V_15 ) ;
F_7 ( V_4 , V_12 , V_16 ) ;
}
static int F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
V_21 -> type = V_22 ;
V_21 -> V_23 = 1 ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 ,
struct V_24 * V_25 )
{
V_25 -> V_26 . V_27 . V_28 [ 0 ] = 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 1 ] = 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 2 ] = 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 3 ] = 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 4 ] = 0xff ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 ,
struct V_24 * V_25 )
{
struct V_29 * V_30 = F_17 ( V_19 ) ;
struct V_3 * V_4 = F_18 ( V_30 ) ;
T_1 V_8 ;
unsigned long V_31 ;
F_19 ( & V_4 -> V_32 , V_31 ) ;
V_8 = F_9 ( V_4 , V_15 ) ;
V_25 -> V_26 . V_27 . V_28 [ 0 ] = V_8 & 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 1 ] = ( V_8 >> 8 ) & 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 2 ] = ( V_8 >> 16 ) & 0xff ;
V_25 -> V_26 . V_27 . V_28 [ 3 ] = ( V_8 >> 24 ) & 0xff ;
V_8 = F_9 ( V_4 , V_16 ) ;
V_25 -> V_26 . V_27 . V_28 [ 4 ] =
( V_8 & V_33 ) >>
V_34 ;
F_20 ( & V_4 -> V_32 , V_31 ) ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 ,
struct V_24 * V_25 )
{
struct V_29 * V_30 = F_17 ( V_19 ) ;
struct V_3 * V_4 = F_18 ( V_30 ) ;
T_1 V_8 ;
unsigned long V_31 ;
V_8 = ( ( T_1 ) V_25 -> V_26 . V_27 . V_28 [ 3 ] << 24 ) ;
V_8 |= ( ( T_1 ) V_25 -> V_26 . V_27 . V_28 [ 2 ] << 16 ) ;
V_8 |= ( ( T_1 ) V_25 -> V_26 . V_27 . V_28 [ 1 ] << 8 ) ;
V_8 |= ( T_1 ) V_25 -> V_26 . V_27 . V_28 [ 0 ] ;
F_19 ( & V_4 -> V_32 , V_31 ) ;
F_7 ( V_4 , V_8 , V_15 ) ;
V_8 = F_9 ( V_4 , V_16 ) ;
V_8 &= ~ V_33 ;
V_8 |= ( T_1 ) V_25 -> V_26 . V_27 . V_28 [ 4 ] <<
V_34 ;
F_7 ( V_4 , V_8 , V_16 ) ;
F_20 ( & V_4 -> V_32 , V_31 ) ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 , int V_37 ,
struct V_29 * V_38 )
{
struct V_3 * V_4 = F_18 ( V_38 ) ;
T_1 V_8 ;
unsigned long V_31 ;
switch ( V_37 ) {
case V_39 :
case V_40 :
case V_41 :
V_8 = F_9 ( V_4 , V_13 ) ;
V_8 |= V_14 ;
F_7 ( V_4 , V_8 , V_13 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
F_19 ( & V_4 -> V_32 , V_31 ) ;
F_11 ( V_4 ) ;
F_20 ( & V_4 -> V_32 , V_31 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_46 * V_47 , struct V_29 * V_38 )
{
struct V_3 * V_4 = F_18 ( V_38 ) ;
unsigned int V_48 ;
long V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ;
T_1 V_8 ;
T_2 V_55 ;
V_53 = F_24 ( V_47 ) ;
V_55 = F_25 ( V_47 ) ;
V_48 = F_26 ( V_47 ) ;
F_27 ( V_4 -> V_2 , L_2 ,
V_53 , V_48 , V_55 ) ;
if ( V_55 != V_56 )
return - V_45 ;
if ( V_48 != 2 )
return - V_45 ;
V_49 = F_28 ( V_4 -> V_5 , V_53 * 256 ) ;
if ( V_49 < 0 )
return V_49 ;
V_50 = F_28 ( V_4 -> V_5 , V_53 * 384 ) ;
if ( V_50 < 0 )
return V_50 ;
V_51 = abs ( ( V_49 / 256 ) - V_53 ) ;
V_52 = abs ( ( V_50 / 384 ) - V_53 ) ;
if ( V_51 > V_52 )
F_29 ( V_4 -> V_5 , V_50 ) ;
else
F_29 ( V_4 -> V_5 , V_49 ) ;
V_54 = F_30 ( V_4 -> V_5 ) ;
V_51 = abs ( ( V_54 / 256 ) - V_53 ) ;
V_52 = abs ( ( V_54 / 384 ) - V_53 ) ;
V_8 = F_9 ( V_4 , V_13 ) ;
if ( V_51 <= V_52 )
V_8 &= ~ V_57 ;
else
V_8 |= V_57 ;
F_7 ( V_4 , V_8 , V_13 ) ;
return 0 ;
}
static int F_31 ( struct V_29 * V_38 )
{
struct V_3 * V_4 = F_18 ( V_38 ) ;
F_32 ( V_38 , & V_4 -> V_58 , NULL ) ;
F_33 ( V_38 , V_59 ,
F_34 ( V_59 ) ) ;
return 0 ;
}
static int F_35 ( struct V_60 * V_61 )
{
struct V_3 * V_4 ;
struct V_62 * V_63 ;
void T_3 * V_9 ;
int V_6 ;
struct V_1 * V_2 = & V_61 -> V_2 ;
V_4 = F_36 ( & V_61 -> V_2 , sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
F_37 ( V_61 , V_4 ) ;
V_4 -> V_2 = & V_61 -> V_2 ;
V_63 = F_38 ( V_61 , V_66 , 0 ) ;
V_9 = F_39 ( & V_61 -> V_2 , V_63 ) ;
if ( F_40 ( V_9 ) )
return F_41 ( V_9 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_17 = F_42 ( & V_61 -> V_2 , L_3 ) ;
if ( F_40 ( V_4 -> V_17 ) ) {
if ( F_41 ( V_4 -> V_17 ) != - V_67 )
F_6 ( & V_61 -> V_2 , L_4 ) ;
return F_41 ( V_4 -> V_17 ) ;
}
V_4 -> V_68 = F_43 ( & V_61 -> V_2 , L_5 ) ;
if ( F_40 ( V_4 -> V_68 ) ) {
if ( F_41 ( V_4 -> V_68 ) != - V_67 )
F_6 ( V_2 , L_6 ) ;
return F_41 ( V_4 -> V_68 ) ;
}
V_4 -> V_5 = F_43 ( & V_61 -> V_2 , L_7 ) ;
if ( F_40 ( V_4 -> V_5 ) ) {
if ( F_41 ( V_4 -> V_5 ) != - V_67 )
F_6 ( V_2 , L_8 ) ;
return F_41 ( V_4 -> V_5 ) ;
}
V_6 = F_5 ( V_4 -> V_68 ) ;
if ( V_6 )
return V_6 ;
F_7 ( V_4 , V_69 ,
V_13 ) ;
F_11 ( V_4 ) ;
F_44 ( & V_61 -> V_2 ) ;
if ( ! F_45 ( & V_61 -> V_2 ) ) {
V_6 = F_4 ( & V_61 -> V_2 ) ;
if ( V_6 )
goto V_70;
}
F_46 ( & V_4 -> V_32 ) ;
V_4 -> V_58 . V_71 = V_63 -> V_72 + V_73 ;
V_4 -> V_58 . V_74 = 4 ;
V_4 -> V_58 . V_75 = 4 ;
V_6 = F_47 ( & V_61 -> V_2 ,
& V_76 ,
& V_77 , 1 ) ;
if ( V_6 )
goto V_78;
V_6 = F_48 ( & V_61 -> V_2 , NULL , 0 ) ;
if ( V_6 )
goto V_78;
F_27 ( & V_61 -> V_2 , L_9 ) ;
return 0 ;
V_78:
if ( ! F_49 ( & V_61 -> V_2 ) )
F_1 ( & V_61 -> V_2 ) ;
V_70:
F_50 ( & V_61 -> V_2 ) ;
F_3 ( V_4 -> V_68 ) ;
return V_6 ;
}
static int F_51 ( struct V_60 * V_61 )
{
struct V_3 * V_4 = F_52 ( V_61 ) ;
F_50 ( & V_61 -> V_2 ) ;
if ( ! F_49 ( & V_61 -> V_2 ) )
F_1 ( & V_61 -> V_2 ) ;
F_3 ( V_4 -> V_68 ) ;
return 0 ;
}
