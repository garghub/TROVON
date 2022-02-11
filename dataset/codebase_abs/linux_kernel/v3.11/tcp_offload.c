struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
struct V_6 * V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
T_2 V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
struct V_1 * V_13 = V_2 ;
T_3 V_14 ;
bool V_15 , V_16 ;
if ( ! F_3 ( V_2 , sizeof( * V_7 ) ) )
goto V_17;
V_7 = F_4 ( V_2 ) ;
V_8 = V_7 -> V_18 * 4 ;
if ( V_8 < sizeof( * V_7 ) )
goto V_17;
if ( ! F_3 ( V_2 , V_8 ) )
goto V_17;
V_11 = ( V_19 ) ~ V_2 -> V_20 ;
F_5 ( V_2 , V_8 ) ;
V_12 = F_6 ( V_2 ) ;
if ( F_7 ( V_2 -> V_20 <= V_12 ) )
goto V_17;
if ( F_8 ( V_2 , V_3 | V_21 ) ) {
int type = F_9 ( V_2 ) -> V_22 ;
if ( F_7 ( type &
~ ( V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 |
V_29 |
0 ) ||
! ( type & ( V_23 | V_26 ) ) ) )
goto V_17;
F_9 ( V_2 ) -> V_30 = F_10 ( V_2 -> V_20 , V_12 ) ;
V_4 = NULL ;
goto V_17;
}
V_16 = V_13 -> V_31 == V_32 ;
V_15 = V_13 -> V_15 ;
V_2 -> V_15 = 0 ;
V_4 = F_11 ( V_2 , V_3 ) ;
if ( F_12 ( V_4 ) )
goto V_17;
V_4 -> V_15 = V_15 ;
V_10 = F_13 ( V_11 + ( V_8 + V_12 ) ) ;
V_2 = V_4 ;
V_7 = F_4 ( V_2 ) ;
V_9 = F_14 ( V_7 -> V_9 ) ;
V_14 = ~ F_15 ( ( V_33 V_34 ) ( ( V_33 V_35 ) V_7 -> V_36 +
( V_33 V_35 ) V_10 ) ) ;
do {
V_7 -> V_37 = V_7 -> V_38 = 0 ;
V_7 -> V_36 = V_14 ;
if ( V_2 -> V_39 != V_40 )
V_7 -> V_36 =
F_15 ( F_16 ( F_17 ( V_2 ) ,
V_8 , V_2 -> V_41 ) ) ;
V_9 += V_12 ;
if ( V_16 ) {
V_2 -> V_31 = V_13 -> V_31 ;
V_2 -> V_42 = V_13 -> V_42 ;
V_2 -> V_43 = V_12 ;
V_13 -> V_43 -= V_12 ;
}
V_2 = V_2 -> V_44 ;
V_7 = F_4 ( V_2 ) ;
V_7 -> V_9 = F_13 ( V_9 ) ;
V_7 -> V_45 = 0 ;
} while ( V_2 -> V_44 );
if ( V_16 ) {
F_18 ( V_13 -> V_42 , V_2 -> V_42 ) ;
F_18 ( V_13 -> V_31 , V_2 -> V_31 ) ;
F_18 ( V_13 -> V_43 , V_2 -> V_43 ) ;
}
V_10 = F_13 ( V_11 + ( F_19 ( V_2 ) -
F_17 ( V_2 ) ) +
V_2 -> V_46 ) ;
V_7 -> V_36 = ~ F_15 ( ( V_33 V_34 ) ( ( V_33 V_35 ) V_7 -> V_36 +
( V_33 V_35 ) V_10 ) ) ;
if ( V_2 -> V_39 != V_40 )
V_7 -> V_36 = F_15 ( F_16 ( F_17 ( V_2 ) ,
V_8 , V_2 -> V_41 ) ) ;
V_17:
return V_4 ;
}
struct V_1 * * F_20 ( struct V_1 * * V_47 , struct V_1 * V_2 )
{
struct V_1 * * V_48 = NULL ;
struct V_1 * V_49 ;
struct V_6 * V_7 ;
struct V_6 * V_50 ;
unsigned int V_20 ;
unsigned int V_8 ;
T_2 V_51 ;
unsigned int V_12 = 1 ;
unsigned int V_52 ;
unsigned int V_53 ;
int V_54 = 1 ;
int V_55 ;
V_53 = F_21 ( V_2 ) ;
V_52 = V_53 + sizeof( * V_7 ) ;
V_7 = F_22 ( V_2 , V_53 ) ;
if ( F_23 ( V_2 , V_52 ) ) {
V_7 = F_24 ( V_2 , V_52 , V_53 ) ;
if ( F_7 ( ! V_7 ) )
goto V_17;
}
V_8 = V_7 -> V_18 * 4 ;
if ( V_8 < sizeof( * V_7 ) )
goto V_17;
V_52 = V_53 + V_8 ;
if ( F_23 ( V_2 , V_52 ) ) {
V_7 = F_24 ( V_2 , V_52 , V_53 ) ;
if ( F_7 ( ! V_7 ) )
goto V_17;
}
F_25 ( V_2 , V_8 ) ;
V_20 = F_26 ( V_2 ) ;
V_51 = F_27 ( V_7 ) ;
for (; ( V_49 = * V_47 ) ; V_47 = & V_49 -> V_44 ) {
if ( ! F_28 ( V_49 ) -> V_56 )
continue;
V_50 = F_4 ( V_49 ) ;
if ( * ( V_35 * ) & V_7 -> V_57 ^ * ( V_35 * ) & V_50 -> V_57 ) {
F_28 ( V_49 ) -> V_56 = 0 ;
continue;
}
goto V_58;
}
goto V_59;
V_58:
V_54 = F_28 ( V_49 ) -> V_54 ;
V_54 |= ( V_33 int ) ( V_51 & V_60 ) ;
V_54 |= ( V_33 int ) ( ( V_51 ^ F_27 ( V_50 ) ) &
~ ( V_60 | V_61 | V_62 ) ) ;
V_54 |= ( V_33 int ) ( V_7 -> V_63 ^ V_50 -> V_63 ) ;
for ( V_55 = sizeof( * V_7 ) ; V_55 < V_8 ; V_55 += 4 )
V_54 |= * ( V_35 * ) ( ( V_64 * ) V_7 + V_55 ) ^
* ( V_35 * ) ( ( V_64 * ) V_50 + V_55 ) ;
V_12 = F_6 ( V_49 ) ;
V_54 |= ( V_20 - 1 ) >= V_12 ;
V_54 |= ( F_14 ( V_50 -> V_9 ) + F_26 ( V_49 ) ) ^ F_14 ( V_7 -> V_9 ) ;
if ( V_54 || F_29 ( V_47 , V_2 ) ) {
V_12 = 1 ;
goto V_59;
}
V_49 = * V_47 ;
V_50 = F_4 ( V_49 ) ;
F_27 ( V_50 ) |= V_51 & ( V_61 | V_62 ) ;
V_59:
V_54 = V_20 < V_12 ;
V_54 |= ( V_33 int ) ( V_51 & ( V_65 | V_62 |
V_66 | V_67 |
V_61 ) ) ;
if ( V_49 && ( ! F_28 ( V_2 ) -> V_56 || V_54 ) )
V_48 = V_47 ;
V_17:
F_28 ( V_2 ) -> V_54 |= V_54 ;
return V_48 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_2 -> V_68 = F_17 ( V_2 ) - V_2 -> V_47 ;
V_2 -> V_69 = F_31 ( struct V_6 , V_36 ) ;
V_2 -> V_39 = V_40 ;
F_9 ( V_2 ) -> V_30 = F_28 ( V_2 ) -> V_70 ;
if ( V_7 -> V_45 )
F_9 ( V_2 ) -> V_22 |= V_25 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 ;
struct V_6 * V_7 ;
if ( ! F_3 ( V_2 , sizeof( * V_7 ) ) )
return - V_5 ;
V_72 = F_33 ( V_2 ) ;
V_7 = F_4 ( V_2 ) ;
V_7 -> V_36 = 0 ;
V_2 -> V_39 = V_40 ;
F_34 ( V_2 , V_72 -> V_73 , V_72 -> V_74 ) ;
return 0 ;
}
static struct V_1 * * F_35 ( struct V_1 * * V_47 , struct V_1 * V_2 )
{
const struct V_71 * V_72 = F_36 ( V_2 ) ;
V_34 V_75 ;
T_3 V_76 ;
switch ( V_2 -> V_39 ) {
case V_77 :
if ( ! F_37 ( F_26 ( V_2 ) , V_72 -> V_73 , V_72 -> V_74 ,
V_2 -> V_41 ) ) {
V_2 -> V_39 = V_78 ;
break;
}
V_54:
F_28 ( V_2 ) -> V_54 = 1 ;
return NULL ;
case V_79 :
V_75 = F_38 ( V_72 -> V_73 , V_72 -> V_74 ,
F_26 ( V_2 ) , V_80 , 0 ) ;
V_76 = F_15 ( F_39 ( V_2 ,
F_21 ( V_2 ) ,
F_26 ( V_2 ) ,
V_75 ) ) ;
if ( V_76 )
goto V_54;
V_2 -> V_39 = V_78 ;
break;
}
return F_20 ( V_47 , V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
const struct V_71 * V_72 = F_33 ( V_2 ) ;
struct V_6 * V_7 = F_4 ( V_2 ) ;
V_7 -> V_36 = ~ F_37 ( V_2 -> V_20 - F_41 ( V_2 ) ,
V_72 -> V_73 , V_72 -> V_74 , 0 ) ;
F_9 ( V_2 ) -> V_22 = V_23 ;
return F_30 ( V_2 ) ;
}
int T_4 F_42 ( void )
{
return F_43 ( & V_81 , V_80 ) ;
}
