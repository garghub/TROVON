static void F_1 ( struct V_1 * V_2 , int * V_3 )
{
* V_3 = V_4 >> 2 ;
}
static bool
F_2 ( struct V_1 * V_2 , T_1 V_5 , T_2 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = F_4 ( & V_11 -> V_12 ) ;
T_2 * V_15 , * V_16 ;
V_15 = ( T_2 * ) V_14 -> V_17 ;
V_16 = ( ( void * ) V_14 -> V_18 ) + V_19 ;
V_15 += V_5 ;
if ( V_15 > V_16 )
return false ;
* V_6 = * V_15 ;
return true ;
}
int F_5 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = F_4 ( & V_11 -> V_12 ) ;
V_8 -> V_20 = V_14 -> V_21 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 , T_3 * V_22 )
{
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = F_4 ( & V_11 -> V_12 ) ;
T_3 * V_23 ;
if ( F_3 ( V_8 -> V_12 ) -> V_24 == 0 )
V_23 = V_14 -> V_18 -> V_25 ;
else
V_23 = V_14 -> V_18 -> V_26 ;
memcpy ( V_22 , V_23 , V_27 ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_4 ( & V_11 -> V_12 ) ;
struct V_7 * V_8 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
void T_4 * V_32 ;
int V_33 ;
int V_34 = 0 ;
T_1 V_35 ;
if ( ! F_4 ( & V_11 -> V_12 ) ) {
F_8 ( & V_11 -> V_12 , L_1 ) ;
V_34 = - V_36 ;
goto V_37;
}
V_31 = F_9 ( V_11 , V_38 , 0 ) ;
if ( V_31 == NULL ) {
F_8 ( & V_11 -> V_12 , L_2 ) ;
V_34 = - V_39 ;
goto V_37;
}
V_32 = F_10 ( V_31 -> V_40 , F_11 ( V_31 ) ) ;
if ( V_32 == NULL ) {
F_8 ( & V_11 -> V_12 , L_3 ) ;
V_34 = - V_41 ;
goto V_37;
}
V_31 = F_9 ( V_11 , V_42 , 0 ) ;
if ( V_31 == NULL ) {
F_8 ( & V_11 -> V_12 , L_4 ) ;
V_34 = - V_39 ;
goto V_43;
}
V_33 = V_31 -> V_40 ;
V_29 = F_12 ( sizeof( struct V_7 ) , & V_44 ) ;
if ( V_29 == NULL ) {
F_8 ( & V_11 -> V_12 , L_5 ) ;
V_34 = - V_41 ;
goto V_43;
}
V_8 = V_29 -> V_9 ;
V_8 -> V_29 = V_29 ;
V_8 -> V_12 = & V_11 -> V_12 ;
V_8 -> V_45 = V_32 ;
V_8 -> V_33 = V_33 ;
V_8 -> V_21 = V_14 -> V_21 ;
if ( V_14 -> V_21 >= V_46 ) {
V_35 = F_13 ( ( void T_4 * ) V_47 ) ;
V_35 |= V_48 ;
F_14 ( V_35 , ( void T_4 * ) V_47 ) ;
V_35 = F_13 ( ( void T_4 * ) V_49 ) ;
V_35 |= V_50 ;
F_14 ( V_35 , ( void T_4 * ) V_49 ) ;
} else {
V_35 = F_13 ( ( void T_4 * ) V_51 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_24 == 0 )
V_35 |= V_52 ;
else
V_35 |= V_53 ;
F_14 ( V_35 , ( void T_4 * ) V_51 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_24 == 0 &&
( V_14 -> V_18 -> V_54 & ( V_55 | V_56 ) ) ==
( V_56 | V_55 ) )
V_8 -> V_57 . V_58 = true ;
else
V_8 -> V_57 . V_58 = false ;
}
V_34 = F_15 ( V_8 , & V_59 ) ;
if ( V_34 != 0 ) {
F_8 ( & V_11 -> V_12 , L_6 , V_34 ) ;
V_34 = - V_60 ;
goto V_61;
}
F_16 ( V_11 , V_29 ) ;
return 0 ;
V_61:
F_17 ( V_29 ) ;
V_43:
F_18 ( V_32 ) ;
V_37:
return V_34 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_4 ( & V_11 -> V_12 ) ;
struct V_28 * V_29 = F_20 ( V_11 ) ;
struct V_7 * V_8 ;
T_1 V_35 ;
if ( ! V_29 )
return 0 ;
V_8 = V_29 -> V_9 ;
if ( V_14 -> V_21 >= V_46 ) {
V_35 = F_13 ( ( void T_4 * ) V_47 ) ;
V_35 &= ~ V_48 ;
F_14 ( V_35 , ( void T_4 * ) V_47 ) ;
} else {
V_35 = F_13 ( ( void T_4 * ) V_51 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_24 == 0 )
V_35 &= ~ V_52 ;
else
V_35 &= ~ V_53 ;
F_14 ( V_35 , ( void T_4 * ) V_51 ) ;
}
F_21 ( V_8 ) ;
F_18 ( V_8 -> V_45 ) ;
F_17 ( V_29 ) ;
return 0 ;
}
