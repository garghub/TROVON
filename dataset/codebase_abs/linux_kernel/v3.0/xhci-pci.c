static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 ) )
F_3 ( V_2 , L_1 ) ;
F_3 ( V_2 , L_2 ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_6 -> V_7 . V_8 ) ;
int V_9 ;
T_1 V_10 ;
V_6 -> V_7 . V_11 = V_12 - 2 ;
if ( F_6 ( V_6 ) ) {
V_2 = F_7 ( sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
* ( (struct V_1 * * ) V_6 -> V_15 ) = V_2 ;
V_2 -> V_16 = V_6 ;
V_6 -> V_17 = V_18 ;
V_6 -> V_7 . V_19 -> V_17 = V_20 ;
V_6 -> V_21 = 1 ;
} else {
V_2 = F_8 ( V_6 ) ;
V_10 = F_9 ( V_2 , & V_2 -> V_22 -> V_23 ) ;
if ( F_10 ( V_10 ) ) {
F_3 ( V_2 , L_3 ) ;
F_11 ( V_6 -> V_7 . V_8 , F_12 ( 64 ) ) ;
} else {
F_11 ( V_6 -> V_7 . V_8 , F_12 ( 32 ) ) ;
}
return 0 ;
}
V_2 -> V_22 = V_6 -> V_24 ;
V_2 -> V_25 = V_6 -> V_24 +
F_13 ( F_9 ( V_2 , & V_2 -> V_22 -> V_26 ) ) ;
V_2 -> V_27 = V_6 -> V_24 +
( F_9 ( V_2 , & V_2 -> V_22 -> V_28 ) & V_29 ) ;
V_2 -> V_30 = F_9 ( V_2 , & V_2 -> V_22 -> V_30 ) ;
V_2 -> V_31 = F_9 ( V_2 , & V_2 -> V_22 -> V_31 ) ;
V_2 -> V_32 = F_9 ( V_2 , & V_2 -> V_22 -> V_32 ) ;
V_2 -> V_23 = F_9 ( V_2 , & V_2 -> V_22 -> V_26 ) ;
V_2 -> V_33 = F_14 ( V_2 -> V_23 ) ;
V_2 -> V_23 = F_9 ( V_2 , & V_2 -> V_22 -> V_23 ) ;
F_15 ( V_2 ) ;
if ( V_4 -> V_34 == V_35 &&
V_4 -> V_36 == V_37 ) {
if ( V_4 -> V_38 == 0x0 ) {
V_2 -> V_39 |= V_40 ;
F_3 ( V_2 , L_4
L_5 ) ;
}
V_2 -> V_39 |= V_41 ;
F_3 ( V_2 , L_6
L_7 ,
V_4 -> V_38 ) ;
}
if ( V_4 -> V_34 == V_42 )
V_2 -> V_39 |= V_43 ;
if ( V_4 -> V_34 == V_44 && F_16 () )
V_2 -> V_39 |= V_45 ;
if ( V_4 -> V_34 == V_46 &&
V_4 -> V_36 == V_47 ) {
V_2 -> V_39 |= V_48 ;
V_2 -> V_39 |= V_49 ;
V_2 -> V_50 = 64 ;
}
if ( V_4 -> V_34 == V_51 &&
V_4 -> V_36 == V_52 ) {
V_2 -> V_39 |= V_53 ;
F_3 ( V_2 , L_8 ) ;
}
V_9 = F_17 ( V_2 ) ;
if ( V_9 )
goto error;
F_3 ( V_2 , L_9 ) ;
V_9 = F_18 ( V_2 ) ;
if ( V_9 )
goto error;
F_3 ( V_2 , L_10 ) ;
V_10 = F_9 ( V_2 , & V_2 -> V_22 -> V_23 ) ;
if ( F_10 ( V_10 ) ) {
F_3 ( V_2 , L_3 ) ;
F_11 ( V_6 -> V_7 . V_8 , F_12 ( 64 ) ) ;
} else {
F_11 ( V_6 -> V_7 . V_8 , F_12 ( 32 ) ) ;
}
F_3 ( V_2 , L_11 ) ;
V_9 = F_19 ( V_6 ) ;
if ( V_9 )
goto error;
F_3 ( V_2 , L_12 ) ;
F_20 ( V_4 , V_54 , & V_2 -> V_55 ) ;
F_3 ( V_2 , L_13 , ( unsigned int ) V_2 -> V_55 ) ;
V_9 = F_1 ( V_2 , V_4 ) ;
if ( ! V_9 )
return V_9 ;
error:
F_21 ( V_2 ) ;
return V_9 ;
}
static int F_22 ( struct V_3 * V_56 , const struct V_57 * V_58 )
{
int V_9 ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_5 * V_6 ;
V_60 = (struct V_59 * ) V_58 -> V_61 ;
V_9 = F_23 ( V_56 , V_58 ) ;
if ( V_9 )
return V_9 ;
V_6 = F_24 ( & V_56 -> V_56 ) ;
V_2 = F_8 ( V_6 ) ;
V_2 -> V_62 = F_25 ( V_60 , & V_56 -> V_56 ,
F_26 ( V_56 ) , V_6 ) ;
if ( ! V_2 -> V_62 ) {
V_9 = - V_14 ;
goto V_63;
}
* ( (struct V_1 * * ) V_2 -> V_62 -> V_15 ) = V_2 ;
V_9 = F_27 ( V_2 -> V_62 , V_56 -> V_64 ,
V_65 | V_66 ) ;
if ( V_9 )
goto V_67;
return 0 ;
V_67:
F_28 ( V_2 -> V_62 ) ;
V_63:
F_29 ( V_56 ) ;
return V_9 ;
}
static void F_30 ( struct V_3 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( F_31 ( V_56 ) ) ;
if ( V_2 -> V_62 ) {
F_32 ( V_2 -> V_62 ) ;
F_28 ( V_2 -> V_62 ) ;
}
F_29 ( V_56 ) ;
F_21 ( V_2 ) ;
}
static int F_33 ( struct V_5 * V_6 , bool V_68 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
int V_9 = 0 ;
if ( V_6 -> V_69 != V_70 ||
V_2 -> V_62 -> V_69 != V_70 )
return - V_71 ;
V_9 = F_34 ( V_2 ) ;
return V_9 ;
}
static int F_35 ( struct V_5 * V_6 , bool V_72 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
struct V_3 * V_4 = F_5 ( V_6 -> V_7 . V_8 ) ;
int V_9 = 0 ;
if ( F_36 ( V_4 ) )
F_37 ( V_4 ) ;
V_9 = F_38 ( V_2 , V_72 ) ;
return V_9 ;
}
int F_39 ( void )
{
return F_40 ( & V_73 ) ;
}
void F_41 ( void )
{
F_42 ( & V_73 ) ;
}
