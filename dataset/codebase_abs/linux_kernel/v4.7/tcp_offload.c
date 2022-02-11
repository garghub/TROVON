static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
while ( V_2 ) {
if ( F_2 ( V_3 , V_4 + V_5 ) ) {
F_3 ( V_2 ) -> V_6 |= V_7 ;
F_3 ( V_2 ) -> V_8 = V_3 ;
return;
}
V_2 = V_2 -> V_9 ;
V_4 += V_5 ;
}
}
static struct V_1 * F_4 ( struct V_1 * V_2 ,
T_1 V_10 )
{
if ( ! F_5 ( V_2 , sizeof( struct V_11 ) ) )
return F_6 ( - V_12 ) ;
if ( F_7 ( V_2 -> V_13 != V_14 ) ) {
const struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_17 -> V_18 = 0 ;
V_2 -> V_13 = V_14 ;
F_10 ( V_2 , V_16 -> V_19 , V_16 -> V_20 ) ;
}
return F_11 ( V_2 , V_10 ) ;
}
struct V_1 * F_11 ( struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_1 * V_21 = F_6 ( - V_12 ) ;
unsigned int V_22 = 0 ;
struct V_11 * V_17 ;
unsigned int V_23 ;
unsigned int V_4 ;
T_2 V_24 ;
unsigned int V_25 ;
unsigned int V_5 ;
struct V_1 * V_26 = V_2 ;
T_3 V_27 ;
bool V_28 , V_29 ;
V_17 = F_9 ( V_2 ) ;
V_23 = V_17 -> V_30 * 4 ;
if ( V_23 < sizeof( * V_17 ) )
goto V_31;
if ( ! F_5 ( V_2 , V_23 ) )
goto V_31;
V_25 = ( V_32 ) ~ V_2 -> V_33 ;
F_12 ( V_2 , V_23 ) ;
V_5 = F_3 ( V_2 ) -> V_34 ;
if ( F_7 ( V_2 -> V_33 <= V_5 ) )
goto V_31;
if ( F_13 ( V_2 , V_10 | V_35 ) ) {
F_3 ( V_2 ) -> V_36 = F_14 ( V_2 -> V_33 , V_5 ) ;
V_21 = NULL ;
goto V_31;
}
if ( V_10 & V_37 )
V_5 = V_2 -> V_33 - ( V_2 -> V_33 % V_5 ) ;
V_29 = V_26 -> V_38 == V_39 ;
V_28 = V_26 -> V_28 ;
V_2 -> V_28 = 0 ;
V_21 = F_15 ( V_2 , V_10 ) ;
if ( F_16 ( V_21 ) )
goto V_31;
V_21 -> V_28 = V_28 ;
V_24 = F_17 ( V_25 + ( V_23 + V_5 ) ) ;
V_2 = V_21 ;
V_17 = F_9 ( V_2 ) ;
V_4 = F_18 ( V_17 -> V_4 ) ;
if ( F_7 ( F_3 ( V_26 ) -> V_6 & V_7 ) )
F_1 ( V_21 , F_3 ( V_26 ) -> V_8 , V_4 , V_5 ) ;
V_27 = ~ F_19 ( ( V_40 V_41 ) ( ( V_40 V_42 ) V_17 -> V_18 +
( V_40 V_42 ) V_24 ) ) ;
while ( V_2 -> V_9 ) {
V_17 -> V_43 = V_17 -> V_44 = 0 ;
V_17 -> V_18 = V_27 ;
if ( V_2 -> V_13 == V_14 )
F_20 ( V_2 , ~ V_17 -> V_18 ) ;
else
V_17 -> V_18 = F_21 ( V_2 , ~ V_17 -> V_18 ) ;
V_4 += V_5 ;
if ( V_29 ) {
V_2 -> V_38 = V_26 -> V_38 ;
V_2 -> V_45 = V_26 -> V_45 ;
V_22 += V_2 -> V_46 ;
}
V_2 = V_2 -> V_9 ;
V_17 = F_9 ( V_2 ) ;
V_17 -> V_4 = F_17 ( V_4 ) ;
V_17 -> V_47 = 0 ;
}
if ( V_29 ) {
F_22 ( V_26 -> V_45 , V_2 -> V_45 ) ;
F_22 ( V_26 -> V_38 , V_2 -> V_38 ) ;
V_22 += V_2 -> V_46 ;
F_23 ( V_22 - V_26 -> V_46 ,
& V_2 -> V_45 -> V_48 ) ;
}
V_24 = F_17 ( V_25 + ( F_24 ( V_2 ) -
F_25 ( V_2 ) ) +
V_2 -> V_49 ) ;
V_17 -> V_18 = ~ F_19 ( ( V_40 V_41 ) ( ( V_40 V_42 ) V_17 -> V_18 +
( V_40 V_42 ) V_24 ) ) ;
if ( V_2 -> V_13 == V_14 )
F_20 ( V_2 , ~ V_17 -> V_18 ) ;
else
V_17 -> V_18 = F_21 ( V_2 , ~ V_17 -> V_18 ) ;
V_31:
return V_21 ;
}
struct V_1 * * F_26 ( struct V_1 * * V_50 , struct V_1 * V_2 )
{
struct V_1 * * V_51 = NULL ;
struct V_1 * V_52 ;
struct V_11 * V_17 ;
struct V_11 * V_53 ;
unsigned int V_33 ;
unsigned int V_23 ;
T_2 V_54 ;
unsigned int V_5 = 1 ;
unsigned int V_55 ;
unsigned int V_56 ;
int V_57 = 1 ;
int V_58 ;
V_56 = F_27 ( V_2 ) ;
V_55 = V_56 + sizeof( * V_17 ) ;
V_17 = F_28 ( V_2 , V_56 ) ;
if ( F_29 ( V_2 , V_55 ) ) {
V_17 = F_30 ( V_2 , V_55 , V_56 ) ;
if ( F_7 ( ! V_17 ) )
goto V_31;
}
V_23 = V_17 -> V_30 * 4 ;
if ( V_23 < sizeof( * V_17 ) )
goto V_31;
V_55 = V_56 + V_23 ;
if ( F_29 ( V_2 , V_55 ) ) {
V_17 = F_30 ( V_2 , V_55 , V_56 ) ;
if ( F_7 ( ! V_17 ) )
goto V_31;
}
F_31 ( V_2 , V_23 ) ;
V_33 = F_32 ( V_2 ) ;
V_54 = F_33 ( V_17 ) ;
for (; ( V_52 = * V_50 ) ; V_50 = & V_52 -> V_9 ) {
if ( ! F_34 ( V_52 ) -> V_59 )
continue;
V_53 = F_9 ( V_52 ) ;
if ( * ( V_42 * ) & V_17 -> V_60 ^ * ( V_42 * ) & V_53 -> V_60 ) {
F_34 ( V_52 ) -> V_59 = 0 ;
continue;
}
goto V_61;
}
goto V_62;
V_61:
V_57 = F_34 ( V_52 ) -> V_57 ;
V_57 |= ( V_40 int ) ( V_54 & V_63 ) ;
V_57 |= ( V_40 int ) ( ( V_54 ^ F_33 ( V_53 ) ) &
~ ( V_63 | V_64 | V_65 ) ) ;
V_57 |= ( V_40 int ) ( V_17 -> V_66 ^ V_53 -> V_66 ) ;
for ( V_58 = sizeof( * V_17 ) ; V_58 < V_23 ; V_58 += 4 )
V_57 |= * ( V_42 * ) ( ( V_67 * ) V_17 + V_58 ) ^
* ( V_42 * ) ( ( V_67 * ) V_53 + V_58 ) ;
if ( F_34 ( V_52 ) -> V_68 != 1 ||
F_34 ( V_52 ) -> V_69 != 1 ||
! F_34 ( V_52 ) -> V_70 )
V_57 |= F_34 ( V_52 ) -> V_68 ;
else
F_34 ( V_52 ) -> V_70 = false ;
V_5 = F_3 ( V_52 ) -> V_34 ;
V_57 |= ( V_33 - 1 ) >= V_5 ;
V_57 |= ( F_18 ( V_53 -> V_4 ) + F_32 ( V_52 ) ) ^ F_18 ( V_17 -> V_4 ) ;
if ( V_57 || F_35 ( V_50 , V_2 ) ) {
V_5 = 1 ;
goto V_62;
}
V_52 = * V_50 ;
V_53 = F_9 ( V_52 ) ;
F_33 ( V_53 ) |= V_54 & ( V_64 | V_65 ) ;
V_62:
V_57 = V_33 < V_5 ;
V_57 |= ( V_40 int ) ( V_54 & ( V_71 | V_65 |
V_72 | V_73 |
V_64 ) ) ;
if ( V_52 && ( ! F_34 ( V_2 ) -> V_59 || V_57 ) )
V_51 = V_50 ;
V_31:
F_34 ( V_2 ) -> V_57 |= ( V_57 != 0 ) ;
return V_51 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_2 -> V_74 = ( unsigned char * ) V_17 - V_2 -> V_50 ;
V_2 -> V_75 = F_37 ( struct V_11 , V_18 ) ;
V_2 -> V_13 = V_14 ;
F_3 ( V_2 ) -> V_36 = F_34 ( V_2 ) -> V_69 ;
if ( V_17 -> V_47 )
F_3 ( V_2 ) -> V_76 |= V_77 ;
return 0 ;
}
static struct V_1 * * F_38 ( struct V_1 * * V_50 , struct V_1 * V_2 )
{
if ( ! F_34 ( V_2 ) -> V_57 &&
F_39 ( V_2 , V_78 ,
V_79 ) ) {
F_34 ( V_2 ) -> V_57 = 1 ;
return NULL ;
}
return F_26 ( V_50 , V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_80 )
{
const struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_17 -> V_18 = ~ F_41 ( V_2 -> V_33 - V_80 , V_16 -> V_19 ,
V_16 -> V_20 , 0 ) ;
F_3 ( V_2 ) -> V_76 |= V_81 ;
if ( F_34 ( V_2 ) -> V_70 )
F_3 ( V_2 ) -> V_76 |= V_82 ;
return F_36 ( V_2 ) ;
}
int T_4 F_42 ( void )
{
return F_43 ( & V_83 , V_78 ) ;
}
