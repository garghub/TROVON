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
int F_4 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
V_8 -> V_21 = V_14 -> V_22 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , T_3 * V_23 )
{
struct V_10 * V_11 = F_3 ( V_8 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
T_3 * V_24 ;
if ( F_3 ( V_8 -> V_12 ) -> V_25 == 0 )
V_24 = V_14 -> V_19 -> V_26 ;
else
V_24 = V_14 -> V_19 -> V_27 ;
memcpy ( V_23 , V_24 , V_28 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
struct V_7 * V_8 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
void T_4 * V_33 ;
int V_34 ;
int V_35 = 0 ;
T_1 V_36 ;
if ( ! V_11 -> V_12 . V_15 ) {
F_7 ( & V_11 -> V_12 , L_1 ) ;
V_35 = - V_37 ;
goto V_38;
}
V_32 = F_8 ( V_11 , V_39 , 0 ) ;
if ( V_32 == NULL ) {
F_7 ( & V_11 -> V_12 , L_2 ) ;
V_35 = - V_40 ;
goto V_38;
}
V_33 = F_9 ( V_32 -> V_41 , F_10 ( V_32 ) ) ;
if ( V_33 == NULL ) {
F_7 ( & V_11 -> V_12 , L_3 ) ;
V_35 = - V_42 ;
goto V_38;
}
V_32 = F_8 ( V_11 , V_43 , 0 ) ;
if ( V_32 == NULL ) {
F_7 ( & V_11 -> V_12 , L_4 ) ;
V_35 = - V_40 ;
goto V_38;
}
V_34 = V_32 -> V_41 ;
V_30 = F_11 ( sizeof( struct V_7 ) , & V_44 ) ;
if ( V_30 == NULL ) {
F_7 ( & V_11 -> V_12 , L_5 ) ;
V_35 = - V_42 ;
goto V_38;
}
V_8 = V_30 -> V_9 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_12 = & V_11 -> V_12 ;
V_8 -> V_45 = V_33 ;
V_8 -> V_34 = V_34 ;
V_8 -> V_22 = V_14 -> V_22 ;
if ( V_14 -> V_22 >= V_46 ) {
V_36 = F_12 ( ( void T_4 * ) V_47 ) ;
V_36 |= V_48 ;
F_13 ( V_36 , ( void T_4 * ) V_47 ) ;
V_36 = F_12 ( ( void T_4 * ) V_49 ) ;
V_36 |= V_50 ;
F_13 ( V_36 , ( void T_4 * ) V_49 ) ;
} else {
V_36 = F_12 ( ( void T_4 * ) V_51 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_25 == 0 )
V_36 |= V_52 ;
else
V_36 |= V_53 ;
F_13 ( V_36 , ( void T_4 * ) V_51 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_25 == 0 &&
( V_14 -> V_19 -> V_54 & ( V_55 | V_56 ) ) ==
( V_56 | V_55 ) )
V_8 -> V_57 . V_58 = true ;
else
V_8 -> V_57 . V_58 = false ;
}
V_35 = F_14 ( V_8 , & V_59 ) ;
if ( V_35 != 0 ) {
F_7 ( & V_11 -> V_12 , L_6 , V_35 ) ;
V_35 = - V_60 ;
goto V_61;
}
F_15 ( V_11 , V_30 ) ;
return 0 ;
V_61:
F_16 ( V_30 ) ;
F_15 ( V_11 , NULL ) ;
V_38:
return V_35 ;
}
static int F_17 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_12 . V_15 ;
struct V_29 * V_30 = F_18 ( V_11 ) ;
struct V_7 * V_8 ;
T_1 V_36 ;
if ( ! V_30 )
return 0 ;
V_8 = V_30 -> V_9 ;
if ( V_14 -> V_22 >= V_46 ) {
V_36 = F_12 ( ( void T_4 * ) V_47 ) ;
V_36 &= ~ V_48 ;
F_13 ( V_36 , ( void T_4 * ) V_47 ) ;
} else {
V_36 = F_12 ( ( void T_4 * ) V_51 ) ;
if ( F_3 ( V_8 -> V_12 ) -> V_25 == 0 )
V_36 &= ~ V_52 ;
else
V_36 &= ~ V_53 ;
F_13 ( V_36 , ( void T_4 * ) V_51 ) ;
}
F_19 ( V_8 ) ;
F_15 ( V_11 , NULL ) ;
F_16 ( V_30 ) ;
return 0 ;
}
static int T_5
F_20 ( void )
{
return F_21 ( & V_62 ) ;
}
static void T_6
F_22 ( void )
{
F_23 ( & V_62 ) ;
}
