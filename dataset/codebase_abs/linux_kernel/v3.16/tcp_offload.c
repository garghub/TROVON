struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
unsigned int V_6 = 0 ;
struct V_7 * V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
T_2 V_11 ;
unsigned int V_12 ;
unsigned int V_13 ;
struct V_1 * V_14 = V_2 ;
T_3 V_15 ;
bool V_16 , V_17 ;
if ( ! F_3 ( V_2 , sizeof( * V_8 ) ) )
goto V_18;
V_8 = F_4 ( V_2 ) ;
V_9 = V_8 -> V_19 * 4 ;
if ( V_9 < sizeof( * V_8 ) )
goto V_18;
if ( ! F_3 ( V_2 , V_9 ) )
goto V_18;
V_12 = ( V_20 ) ~ V_2 -> V_21 ;
F_5 ( V_2 , V_9 ) ;
V_13 = F_6 ( V_2 ) ;
if ( F_7 ( V_2 -> V_21 <= V_13 ) )
goto V_18;
if ( F_8 ( V_2 , V_3 | V_22 ) ) {
int type = F_9 ( V_2 ) -> V_23 ;
if ( F_7 ( type &
~ ( V_24 |
V_25 |
V_26 |
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
0 ) ||
! ( type & ( V_24 | V_27 ) ) ) )
goto V_18;
F_9 ( V_2 ) -> V_35 = F_10 ( V_2 -> V_21 , V_13 ) ;
V_4 = NULL ;
goto V_18;
}
V_17 = V_14 -> V_36 == V_37 ;
V_16 = V_14 -> V_16 ;
V_2 -> V_16 = 0 ;
V_4 = F_11 ( V_2 , V_3 ) ;
if ( F_12 ( V_4 ) )
goto V_18;
V_4 -> V_16 = V_16 ;
V_11 = F_13 ( V_12 + ( V_9 + V_13 ) ) ;
V_2 = V_4 ;
V_8 = F_4 ( V_2 ) ;
V_10 = F_14 ( V_8 -> V_10 ) ;
V_15 = ~ F_15 ( ( V_38 V_39 ) ( ( V_38 V_40 ) V_8 -> V_41 +
( V_38 V_40 ) V_11 ) ) ;
do {
V_8 -> V_42 = V_8 -> V_43 = 0 ;
V_8 -> V_41 = V_15 ;
if ( V_2 -> V_44 != V_45 )
V_8 -> V_41 = F_16 ( V_2 , ~ V_8 -> V_41 ) ;
V_10 += V_13 ;
if ( V_17 ) {
V_2 -> V_36 = V_14 -> V_36 ;
V_2 -> V_46 = V_14 -> V_46 ;
V_6 += V_2 -> V_47 ;
}
V_2 = V_2 -> V_48 ;
V_8 = F_4 ( V_2 ) ;
V_8 -> V_10 = F_13 ( V_10 ) ;
V_8 -> V_49 = 0 ;
} while ( V_2 -> V_48 );
if ( V_17 ) {
F_17 ( V_14 -> V_46 , V_2 -> V_46 ) ;
F_17 ( V_14 -> V_36 , V_2 -> V_36 ) ;
V_6 += V_2 -> V_47 ;
F_18 ( V_6 - V_14 -> V_47 ,
& V_2 -> V_46 -> V_50 ) ;
}
V_11 = F_13 ( V_12 + ( F_19 ( V_2 ) -
F_20 ( V_2 ) ) +
V_2 -> V_51 ) ;
V_8 -> V_41 = ~ F_15 ( ( V_38 V_39 ) ( ( V_38 V_40 ) V_8 -> V_41 +
( V_38 V_40 ) V_11 ) ) ;
if ( V_2 -> V_44 != V_45 )
V_8 -> V_41 = F_16 ( V_2 , ~ V_8 -> V_41 ) ;
V_18:
return V_4 ;
}
struct V_1 * * F_21 ( struct V_1 * * V_52 , struct V_1 * V_2 )
{
struct V_1 * * V_53 = NULL ;
struct V_1 * V_54 ;
struct V_7 * V_8 ;
struct V_7 * V_55 ;
unsigned int V_21 ;
unsigned int V_9 ;
T_2 V_56 ;
unsigned int V_13 = 1 ;
unsigned int V_57 ;
unsigned int V_58 ;
int V_59 = 1 ;
int V_60 ;
V_58 = F_22 ( V_2 ) ;
V_57 = V_58 + sizeof( * V_8 ) ;
V_8 = F_23 ( V_2 , V_58 ) ;
if ( F_24 ( V_2 , V_57 ) ) {
V_8 = F_25 ( V_2 , V_57 , V_58 ) ;
if ( F_7 ( ! V_8 ) )
goto V_18;
}
V_9 = V_8 -> V_19 * 4 ;
if ( V_9 < sizeof( * V_8 ) )
goto V_18;
V_57 = V_58 + V_9 ;
if ( F_24 ( V_2 , V_57 ) ) {
V_8 = F_25 ( V_2 , V_57 , V_58 ) ;
if ( F_7 ( ! V_8 ) )
goto V_18;
}
F_26 ( V_2 , V_9 ) ;
V_21 = F_27 ( V_2 ) ;
V_56 = F_28 ( V_8 ) ;
for (; ( V_54 = * V_52 ) ; V_52 = & V_54 -> V_48 ) {
if ( ! F_29 ( V_54 ) -> V_61 )
continue;
V_55 = F_4 ( V_54 ) ;
if ( * ( V_40 * ) & V_8 -> V_62 ^ * ( V_40 * ) & V_55 -> V_62 ) {
F_29 ( V_54 ) -> V_61 = 0 ;
continue;
}
goto V_63;
}
goto V_64;
V_63:
V_59 = F_29 ( V_54 ) -> V_59 | F_29 ( V_54 ) -> V_65 ;
V_59 |= ( V_38 int ) ( V_56 & V_66 ) ;
V_59 |= ( V_38 int ) ( ( V_56 ^ F_28 ( V_55 ) ) &
~ ( V_66 | V_67 | V_68 ) ) ;
V_59 |= ( V_38 int ) ( V_8 -> V_69 ^ V_55 -> V_69 ) ;
for ( V_60 = sizeof( * V_8 ) ; V_60 < V_9 ; V_60 += 4 )
V_59 |= * ( V_40 * ) ( ( V_70 * ) V_8 + V_60 ) ^
* ( V_40 * ) ( ( V_70 * ) V_55 + V_60 ) ;
V_13 = F_6 ( V_54 ) ;
V_59 |= ( V_21 - 1 ) >= V_13 ;
V_59 |= ( F_14 ( V_55 -> V_10 ) + F_27 ( V_54 ) ) ^ F_14 ( V_8 -> V_10 ) ;
if ( V_59 || F_30 ( V_52 , V_2 ) ) {
V_13 = 1 ;
goto V_64;
}
V_54 = * V_52 ;
V_55 = F_4 ( V_54 ) ;
F_28 ( V_55 ) |= V_56 & ( V_67 | V_68 ) ;
V_64:
V_59 = V_21 < V_13 ;
V_59 |= ( V_38 int ) ( V_56 & ( V_71 | V_68 |
V_72 | V_73 |
V_67 ) ) ;
if ( V_54 && ( ! F_29 ( V_2 ) -> V_61 || V_59 ) )
V_53 = V_52 ;
V_18:
F_29 ( V_2 ) -> V_59 |= ( V_59 != 0 ) ;
return V_53 ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_4 ( V_2 ) ;
V_2 -> V_74 = ( unsigned char * ) V_8 - V_2 -> V_52 ;
V_2 -> V_75 = F_32 ( struct V_7 , V_41 ) ;
V_2 -> V_44 = V_45 ;
F_9 ( V_2 ) -> V_35 = F_29 ( V_2 ) -> V_76 ;
if ( V_8 -> V_49 )
F_9 ( V_2 ) -> V_23 |= V_26 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
const struct V_77 * V_78 ;
struct V_7 * V_8 ;
if ( ! F_3 ( V_2 , sizeof( * V_8 ) ) )
return - V_5 ;
V_78 = F_34 ( V_2 ) ;
V_8 = F_4 ( V_2 ) ;
V_8 -> V_41 = 0 ;
V_2 -> V_44 = V_45 ;
F_35 ( V_2 , V_78 -> V_79 , V_78 -> V_80 ) ;
return 0 ;
}
static struct V_1 * * F_36 ( struct V_1 * * V_52 , struct V_1 * V_2 )
{
const struct V_77 * V_78 = F_37 ( V_2 ) ;
V_39 V_81 ;
if ( F_29 ( V_2 ) -> V_59 )
goto V_82;
V_81 = F_29 ( V_2 ) -> V_83 ;
switch ( V_2 -> V_44 ) {
case V_84 :
V_81 = F_38 ( V_2 , F_22 ( V_2 ) , F_27 ( V_2 ) ,
0 ) ;
case V_85 :
if ( ! F_39 ( F_27 ( V_2 ) , V_78 -> V_79 , V_78 -> V_80 ,
V_81 ) ) {
V_2 -> V_44 = V_86 ;
break;
}
F_29 ( V_2 ) -> V_59 = 1 ;
return NULL ;
}
V_82:
return F_21 ( V_52 , V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_87 )
{
const struct V_77 * V_78 = F_34 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_2 ) ;
V_8 -> V_41 = ~ F_39 ( V_2 -> V_21 - V_87 , V_78 -> V_79 ,
V_78 -> V_80 , 0 ) ;
F_9 ( V_2 ) -> V_23 |= V_24 ;
return F_31 ( V_2 ) ;
}
int T_4 F_41 ( void )
{
return F_42 ( & V_88 , V_89 ) ;
}
