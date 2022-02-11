static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 , V_5 ;
V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 & V_7 )
F_3 ( & V_2 -> V_8 ,
L_1
L_2 ) ;
V_5 &= ~ ( V_7 | V_9 | V_10 ) ;
V_3 = F_4 ( V_2 , V_6 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_2 ( V_2 , V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 &= ~ ( V_12 | V_13 ) ;
V_4 |= V_14 ;
return F_4 ( V_2 , V_11 , V_4 ) ;
}
static int F_5 ( struct V_15 * V_8 , struct V_16 * time )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
int V_3 ;
T_1 V_17 [ 7 ] ;
unsigned int V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
unsigned int V_24 , V_25 , V_26 ;
unsigned int V_27 , V_28 = 0 ;
V_3 = F_7 ( V_2 , V_29 , 7 , V_17 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 < 7 )
return - V_30 ;
V_23 = V_17 [ 0 ] ;
V_22 = V_17 [ 1 ] ;
V_21 = V_17 [ 2 ] ;
V_24 = V_17 [ 3 ] ;
V_20 = V_17 [ 4 ] ;
V_19 = V_17 [ 5 ] ;
V_18 = V_17 [ 6 ] ;
V_25 = V_21 & 0x40 ;
V_26 = V_21 & 0x20 ;
V_27 = V_19 & 0x80 ;
time -> V_31 = F_8 ( V_23 ) ;
time -> V_32 = F_8 ( V_22 ) ;
if ( V_25 ) {
if ( V_26 )
time -> V_33 = F_8 ( V_21 & 0x1F ) + 12 ;
else
time -> V_33 = F_8 ( V_21 & 0x1F ) ;
} else {
time -> V_33 = F_8 ( V_21 ) ;
}
time -> V_34 = F_8 ( V_24 ) - 1 ;
time -> V_35 = F_8 ( V_20 ) ;
time -> V_36 = F_8 ( V_19 & 0x7F ) - 1 ;
if ( V_27 )
V_28 = 100 ;
time -> V_37 = F_8 ( V_18 ) + V_28 ;
return F_9 ( time ) ;
}
static int F_10 ( struct V_15 * V_8 , struct V_16 * time )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
T_1 V_17 [ 7 ] ;
V_17 [ 0 ] = F_11 ( time -> V_31 ) ;
V_17 [ 1 ] = F_11 ( time -> V_32 ) ;
V_17 [ 2 ] = F_11 ( time -> V_33 ) ;
V_17 [ 3 ] = F_11 ( time -> V_34 + 1 ) ;
V_17 [ 4 ] = F_11 ( time -> V_35 ) ;
V_17 [ 5 ] = F_11 ( time -> V_36 + 1 ) ;
if ( time -> V_37 >= 100 ) {
V_17 [ 5 ] |= 0x80 ;
V_17 [ 6 ] = F_11 ( time -> V_37 - 100 ) ;
} else {
V_17 [ 6 ] = F_11 ( time -> V_37 ) ;
}
return F_12 ( V_2 ,
V_29 , 7 , V_17 ) ;
}
static int F_13 ( struct V_15 * V_8 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_40 * V_40 = F_14 ( V_2 ) ;
int V_4 , V_5 ;
int V_3 ;
T_1 V_17 [ 4 ] ;
F_15 ( & V_40 -> V_41 ) ;
V_3 = F_2 ( V_2 , V_6 ) ;
if ( V_3 < 0 )
goto V_42;
V_5 = V_3 ;
V_3 = F_2 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
goto V_42;
V_4 = V_3 ;
V_3 = F_7 ( V_2 , V_43 , 4 , V_17 ) ;
if ( V_3 < 0 )
goto V_42;
V_39 -> time . V_31 = F_8 ( V_17 [ 0 ] & 0x7F ) ;
V_39 -> time . V_32 = F_8 ( V_17 [ 1 ] & 0x7F ) ;
V_39 -> time . V_33 = F_8 ( V_17 [ 2 ] & 0x7F ) ;
V_39 -> time . V_35 = F_8 ( V_17 [ 3 ] & 0x7F ) ;
V_39 -> time . V_36 = - 1 ;
V_39 -> time . V_37 = - 1 ;
V_39 -> time . V_34 = - 1 ;
V_39 -> time . V_44 = - 1 ;
V_39 -> time . V_45 = - 1 ;
V_39 -> V_46 = ! ! ( V_4 & V_12 ) ;
V_39 -> V_47 = ! ! ( V_5 & V_9 ) ;
V_3 = 0 ;
V_42:
F_16 ( & V_40 -> V_41 ) ;
return V_3 ;
}
static int F_17 ( struct V_15 * V_8 , struct V_38 * V_39 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_40 * V_40 = F_14 ( V_2 ) ;
int V_4 , V_5 ;
int V_3 ;
T_1 V_17 [ 4 ] ;
if ( V_2 -> V_48 <= 0 )
return - V_49 ;
F_15 ( & V_40 -> V_41 ) ;
V_17 [ 0 ] = F_11 ( V_39 -> time . V_31 ) ;
V_17 [ 1 ] = F_11 ( V_39 -> time . V_32 ) ;
V_17 [ 2 ] = F_11 ( V_39 -> time . V_33 ) ;
V_17 [ 3 ] = F_11 ( V_39 -> time . V_35 ) ;
V_3 = F_2 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
goto V_42;
V_4 = V_3 ;
V_4 &= ~ ( V_12 | V_13 ) ;
V_3 = F_4 ( V_2 , V_11 , V_4 ) ;
if ( V_3 < 0 )
goto V_42;
V_3 = F_2 ( V_2 , V_6 ) ;
if ( V_3 < 0 )
goto V_42;
V_5 = V_3 ;
V_5 &= ~ ( V_9 | V_10 ) ;
V_3 = F_4 ( V_2 , V_6 , V_5 ) ;
if ( V_3 < 0 )
goto V_42;
V_3 = F_12 ( V_2 , V_43 , 4 , V_17 ) ;
if ( V_39 -> V_46 ) {
V_4 |= V_12 ;
V_3 = F_4 ( V_2 , V_11 , V_4 ) ;
}
V_42:
F_16 ( & V_40 -> V_41 ) ;
return V_3 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_40 * V_40 = F_14 ( V_2 ) ;
int V_4 ;
int V_3 ;
T_1 V_17 [ 4 ] ;
F_15 ( & V_40 -> V_41 ) ;
V_3 = F_7 ( V_2 , V_43 , 4 , V_17 ) ;
if ( V_3 < 0 )
goto V_50;
V_17 [ 0 ] = F_8 ( V_17 [ 0 ] ) < 0 || ( V_40 -> V_51 -> V_52 & V_53 ) ?
0x80 : V_17 [ 0 ] ;
V_17 [ 1 ] = F_8 ( V_17 [ 1 ] ) < 0 || ( V_40 -> V_51 -> V_52 & V_53 ) ?
0x80 : V_17 [ 1 ] ;
V_17 [ 2 ] = F_8 ( V_17 [ 2 ] ) < 0 || ( V_40 -> V_51 -> V_52 & V_53 ) ?
0x80 : V_17 [ 2 ] ;
V_17 [ 3 ] = F_8 ( V_17 [ 3 ] ) < 0 || ( V_40 -> V_51 -> V_52 & V_53 ) ?
0x80 : V_17 [ 3 ] ;
V_3 = F_12 ( V_2 , V_43 , 4 , V_17 ) ;
if ( V_3 < 0 )
goto V_50;
V_4 = F_2 ( V_2 , V_11 ) ;
if ( V_4 < 0 )
goto V_50;
if ( V_40 -> V_51 -> V_52 & ( V_54 | V_53 ) )
V_4 |= V_12 ;
else
V_4 &= ~ ( V_12 ) ;
F_4 ( V_2 , V_11 , V_4 ) ;
V_50:
F_16 ( & V_40 -> V_41 ) ;
}
static int F_19 ( struct V_15 * V_8 , unsigned int V_46 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_40 * V_40 = F_14 ( V_2 ) ;
if ( V_2 -> V_48 <= 0 )
return - V_49 ;
if ( V_46 )
V_40 -> V_51 -> V_52 |= V_54 ;
else
V_40 -> V_51 -> V_52 &= ~ V_54 ;
F_18 ( V_2 ) ;
return 0 ;
}
static T_2 F_20 ( int V_48 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
struct V_40 * V_40 = F_14 ( V_2 ) ;
F_21 ( V_48 ) ;
F_22 ( & V_40 -> V_56 ) ;
return V_57 ;
}
static void F_23 ( struct V_58 * V_56 )
{
struct V_40 * V_40 = F_24 ( V_56 , struct V_40 , V_56 ) ;
struct V_1 * V_2 = V_40 -> V_2 ;
int V_5 , V_4 ;
F_15 ( & V_40 -> V_41 ) ;
V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_5 < 0 )
goto V_50;
if ( V_5 & V_9 ) {
V_4 = F_2 ( V_2 , V_11 ) ;
if ( V_4 < 0 )
goto V_42;
V_4 &= ~ ( V_12 ) ;
F_4 ( V_2 , V_11 , V_4 ) ;
V_5 &= ~ V_9 ;
F_4 ( V_2 , V_6 , V_5 ) ;
F_25 ( V_40 -> V_51 , 1 , V_54 | V_59 ) ;
}
V_42:
if ( ! V_40 -> V_60 )
F_26 ( V_2 -> V_48 ) ;
V_50:
F_16 ( & V_40 -> V_41 ) ;
}
static int T_3 F_27 ( struct V_1 * V_2 ,
const struct V_61 * V_62 )
{
struct V_40 * V_40 ;
int V_3 ;
V_40 = F_28 ( sizeof( struct V_40 ) , V_63 ) ;
if ( ! V_40 )
return - V_64 ;
V_40 -> V_2 = V_2 ;
F_29 ( V_2 , V_40 ) ;
F_30 ( & V_40 -> V_56 , F_23 ) ;
F_31 ( & V_40 -> V_41 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_65;
V_40 -> V_51 = F_32 ( V_2 -> V_66 , & V_2 -> V_8 ,
& V_67 , V_68 ) ;
if ( F_33 ( V_40 -> V_51 ) ) {
V_3 = F_34 ( V_40 -> V_51 ) ;
F_35 ( & V_2 -> V_8 , L_3 ) ;
goto V_69;
}
if ( V_2 -> V_48 >= 0 ) {
V_3 = F_36 ( V_2 -> V_48 , F_20 , 0 ,
L_4 , V_2 ) ;
if ( V_3 ) {
F_35 ( & V_2 -> V_8 , L_5 ) ;
goto V_65;
}
}
return 0 ;
V_69:
if ( V_2 -> V_48 >= 0 )
F_37 ( V_2 -> V_48 , V_2 ) ;
V_65:
F_38 ( V_40 ) ;
return V_3 ;
}
static int T_4 F_39 ( struct V_1 * V_2 )
{
struct V_40 * V_40 = F_14 ( V_2 ) ;
if ( V_2 -> V_48 >= 0 ) {
F_15 ( & V_40 -> V_41 ) ;
V_40 -> V_60 = 1 ;
F_16 ( & V_40 -> V_41 ) ;
F_37 ( V_2 -> V_48 , V_2 ) ;
F_40 ( & V_40 -> V_56 ) ;
}
F_41 ( V_40 -> V_51 ) ;
F_38 ( V_40 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_70 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_70 ) ;
}
