static int F_1 ( void T_1 * V_1 )
{
unsigned V_2 = V_3 ;
do {
if ( ! ( F_2 ( V_1 ) & V_4 ) )
return 0 ;
F_3 () ;
} while ( -- V_2 );
return - V_5 ;
}
static void F_4 ( struct V_6 * V_7 )
{
void T_1 * V_1 = V_7 -> V_8 + V_9 ;
if ( F_1 ( V_1 ) )
F_5 ( V_7 -> V_10 -> V_11 . V_12 ,
L_1 ) ;
F_6 ( V_7 -> V_13 | V_7 -> V_14 , V_1 ) ;
}
static void F_7 ( struct V_15 * V_16 , bool V_17 )
{
struct V_6 * V_7 = F_8 ( V_16 -> V_10 ) ;
T_2 V_18 = 1U << ( 2 * V_16 -> V_19 ) ;
F_9 ( V_7 -> V_10 -> V_11 . V_12 , L_2 , V_16 -> V_19 ) ;
if ( V_17 )
V_7 -> V_13 |= V_18 ;
else
V_7 -> V_13 &= ~ V_18 ;
F_4 ( V_7 ) ;
}
static void F_10 ( struct V_6 * V_7 , int V_20 )
{
if ( V_20 == V_7 -> V_21 ) return;
V_7 -> V_21 = V_20 ;
if ( V_20 >= V_7 -> V_22 / 2 )
V_7 -> V_14 = 0 ;
else
V_7 -> V_14 = ( ( V_7 -> V_22 / 2 / V_20 ) - 1 ) << 27 ;
F_4 ( V_7 ) ;
F_9 ( V_7 -> V_10 -> V_11 . V_12 , L_3 ,
V_20 , V_7 -> V_14 ) ;
}
static int F_11 ( struct V_23 * V_10 , struct V_15 * V_16 ,
struct V_24 * V_25 )
{
struct V_6 * V_7 = F_8 ( V_10 ) ;
void T_1 * V_1 = V_7 -> V_8 + V_9 ;
void T_1 * V_26 = V_7 -> V_8 + V_27 ;
T_2 V_28 ;
const unsigned char * V_29 ;
unsigned char * V_30 ;
unsigned int V_31 ;
unsigned int V_32 ;
F_10 ( V_7 , V_25 -> V_21 ) ;
V_28 = V_7 -> V_13 | V_7 -> V_14 | V_33 ;
V_29 = V_25 -> V_34 ;
V_30 = V_25 -> V_35 ;
V_31 = V_25 -> V_31 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( F_1 ( V_1 ) )
break;
F_6 ( V_29 ? * V_29 ++ : 0 , V_26 ) ;
F_6 ( V_28 , V_1 ) ;
if ( F_1 ( V_1 ) )
break;
if ( V_30 )
* V_30 ++ = F_2 ( V_26 ) ;
}
F_12 ( V_10 ) ;
if ( V_32 < V_31 )
return - V_36 ;
return 0 ;
}
static int F_13 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_11 . V_41 ;
struct V_6 * V_7 ;
struct V_23 * V_10 ;
struct V_42 * V_43 ;
T_2 V_22 ;
struct V_44 * V_44 ;
int V_45 = - V_46 ;
V_10 = F_14 ( & V_38 -> V_11 , sizeof( struct V_6 ) ) ;
if ( ! V_10 )
return V_45 ;
V_10 -> V_47 = 3 ;
V_10 -> V_48 = V_49 | V_50 | V_51 ;
V_10 -> V_52 = F_11 ;
V_10 -> V_53 = F_7 ;
V_10 -> V_11 . V_41 = V_40 ;
V_10 -> V_54 = V_38 -> V_55 ;
V_7 = F_8 ( V_10 ) ;
V_7 -> V_10 = V_10 ;
F_15 ( V_38 , V_7 ) ;
V_43 = F_16 ( V_38 , V_56 , 0 ) ;
if ( ! V_43 )
goto V_57;
if ( ! F_17 ( & V_38 -> V_11 , V_43 -> V_58 ,
F_18 ( V_43 ) , V_38 -> V_59 ) )
goto V_57;
V_7 -> V_8 = F_19 ( & V_38 -> V_11 , V_43 -> V_58 ,
F_18 ( V_43 ) ) ;
if ( ! V_7 -> V_8 )
goto V_57;
V_22 = 50000000 ;
V_44 = F_20 ( & V_38 -> V_11 , L_4 ) ;
if ( ! F_21 ( V_44 ) ) {
if ( F_22 ( V_44 ) == 0 )
V_22 = F_23 ( V_44 ) ;
else
F_24 ( & V_38 -> V_11 , L_5 ) ;
}
V_7 -> V_22 = V_22 ;
V_7 -> V_13 = V_60 ;
F_10 ( V_7 , 400000 ) ;
V_45 = F_25 ( & V_38 -> V_11 , V_10 ) ;
if ( V_45 )
goto exit;
return 0 ;
V_57:
V_45 = - V_5 ;
exit:
F_26 ( V_10 ) ;
return V_45 ;
}
