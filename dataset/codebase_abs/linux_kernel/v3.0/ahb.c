static void F_1 ( struct V_1 * V_2 , int * V_3 )
{
* V_3 = V_4 >> 2 ;
}
static bool
F_2 ( struct V_1 * V_2 , T_1 V_5 , T_2 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
T_2 * V_16 , * V_17 ;
V_14 = V_11 -> V_12 . V_15 ;
V_16 = ( T_2 * ) V_14 -> V_18 ;
V_17 = ( ( void * ) V_14 -> V_19 ) + V_20 ;
V_16 += V_5 ;
if ( V_16 > V_17 )
return false ;
* V_6 = * V_16 ;
return true ;
}
int F_4 ( struct V_21 * V_22 )
{
struct V_7 * V_8 = V_22 -> V_23 ;
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
V_22 -> V_24 = V_14 -> V_25 ;
return 0 ;
}
static int F_5 ( struct V_21 * V_22 , T_3 * V_26 )
{
struct V_7 * V_8 = V_22 -> V_23 ;
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
T_3 * V_27 ;
if ( F_3 ( V_8 -> V_12 ) -> V_28 == 0 )
V_27 = V_14 -> V_19 -> V_29 ;
else
V_27 = V_14 -> V_19 -> V_30 ;
memcpy ( V_26 , V_27 , V_31 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
struct V_7 * V_8 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
void T_4 * V_36 ;
int V_37 ;
int V_38 = 0 ;
T_1 V_39 ;
if ( ! V_11 -> V_12 . V_15 ) {
F_7 ( & V_11 -> V_12 , L_1 ) ;
V_38 = - V_40 ;
goto V_41;
}
V_35 = F_8 ( V_11 , V_42 , 0 ) ;
if ( V_35 == NULL ) {
F_7 ( & V_11 -> V_12 , L_2 ) ;
V_38 = - V_43 ;
goto V_41;
}
V_36 = F_9 ( V_35 -> V_44 , F_10 ( V_35 ) ) ;
if ( V_36 == NULL ) {
F_7 ( & V_11 -> V_12 , L_3 ) ;
V_38 = - V_45 ;
goto V_41;
}
V_35 = F_8 ( V_11 , V_46 , 0 ) ;
if ( V_35 == NULL ) {
F_7 ( & V_11 -> V_12 , L_4 ) ;
V_38 = - V_43 ;
goto V_41;
}
V_37 = V_35 -> V_44 ;
V_33 = F_11 ( sizeof( struct V_7 ) , & V_47 ) ;
if ( V_33 == NULL ) {
F_7 ( & V_11 -> V_12 , L_5 ) ;
V_38 = - V_45 ;
goto V_41;
}
V_8 = V_33 -> V_9 ;
V_8 -> V_33 = V_33 ;
V_8 -> V_12 = & V_11 -> V_12 ;
V_8 -> V_48 = V_36 ;
V_8 -> V_37 = V_37 ;
V_8 -> V_25 = V_14 -> V_25 ;
if ( V_14 -> V_25 >= V_49 ) {
V_39 = F_12 ( ( void T_4 * ) V_50 ) ;
V_39 |= V_51 ;
F_13 ( V_39 , ( void T_4 * ) V_50 ) ;
V_39 = F_12 ( ( void T_4 * ) V_52 ) ;
V_39 |= V_53 ;
F_13 ( V_39 , ( void T_4 * ) V_52 ) ;
} else {
V_39 = F_12 ( ( void T_4 * ) V_54 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_28 == 0 )
V_39 |= V_55 ;
else
V_39 |= V_56 ;
F_13 ( V_39 , ( void T_4 * ) V_54 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_28 == 0 &&
( V_14 -> V_19 -> V_57 & ( V_58 | V_59 ) ) ==
( V_59 | V_58 ) )
F_14 ( V_60 , V_8 -> V_61 ) ;
}
V_38 = F_15 ( V_8 , & V_62 ) ;
if ( V_38 != 0 ) {
F_7 ( & V_11 -> V_12 , L_6 , V_38 ) ;
V_38 = - V_63 ;
goto V_64;
}
F_16 ( V_11 , V_33 ) ;
return 0 ;
V_64:
F_17 ( V_33 ) ;
F_16 ( V_11 , NULL ) ;
V_41:
return V_38 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
struct V_32 * V_33 = F_19 ( V_11 ) ;
struct V_7 * V_8 ;
T_1 V_39 ;
if ( ! V_33 )
return 0 ;
V_8 = V_33 -> V_9 ;
if ( V_14 -> V_25 >= V_49 ) {
V_39 = F_12 ( ( void T_4 * ) V_50 ) ;
V_39 &= ~ V_51 ;
F_13 ( V_39 , ( void T_4 * ) V_50 ) ;
} else {
V_39 = F_12 ( ( void T_4 * ) V_54 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_28 == 0 )
V_39 &= ~ V_55 ;
else
V_39 &= ~ V_56 ;
F_13 ( V_39 , ( void T_4 * ) V_54 ) ;
}
F_20 ( V_8 ) ;
F_16 ( V_11 , NULL ) ;
return 0 ;
}
static int T_5
F_21 ( void )
{
return F_22 ( & V_65 ) ;
}
static void T_6
F_23 ( void )
{
F_24 ( & V_65 ) ;
}
