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
V_29 = V_26 -> V_37 == V_38 ;
V_28 = V_26 -> V_28 ;
V_2 -> V_28 = 0 ;
V_21 = F_15 ( V_2 , V_10 ) ;
if ( F_16 ( V_21 ) )
goto V_31;
V_21 -> V_28 = V_28 ;
if ( F_17 ( V_21 ) )
V_5 *= F_3 ( V_21 ) -> V_36 ;
V_24 = F_18 ( V_25 + ( V_23 + V_5 ) ) ;
V_2 = V_21 ;
V_17 = F_9 ( V_2 ) ;
V_4 = F_19 ( V_17 -> V_4 ) ;
if ( F_7 ( F_3 ( V_26 ) -> V_6 & V_7 ) )
F_1 ( V_21 , F_3 ( V_26 ) -> V_8 , V_4 , V_5 ) ;
V_27 = ~ F_20 ( ( V_39 V_40 ) ( ( V_39 V_41 ) V_17 -> V_18 +
( V_39 V_41 ) V_24 ) ) ;
while ( V_2 -> V_9 ) {
V_17 -> V_42 = V_17 -> V_43 = 0 ;
V_17 -> V_18 = V_27 ;
if ( V_2 -> V_13 == V_14 )
F_21 ( V_2 , ~ V_17 -> V_18 ) ;
else
V_17 -> V_18 = F_22 ( V_2 , ~ V_17 -> V_18 ) ;
V_4 += V_5 ;
if ( V_29 ) {
V_2 -> V_37 = V_26 -> V_37 ;
V_2 -> V_44 = V_26 -> V_44 ;
V_22 += V_2 -> V_45 ;
}
V_2 = V_2 -> V_9 ;
V_17 = F_9 ( V_2 ) ;
V_17 -> V_4 = F_18 ( V_4 ) ;
V_17 -> V_46 = 0 ;
}
if ( V_29 ) {
int V_24 ;
F_23 ( V_26 -> V_44 , V_2 -> V_44 ) ;
F_23 ( V_26 -> V_37 , V_2 -> V_37 ) ;
V_22 += V_2 -> V_45 ;
V_24 = V_22 - V_26 -> V_45 ;
if ( F_24 ( V_24 >= 0 ) )
F_25 ( V_24 , & V_2 -> V_44 -> V_47 ) ;
else
F_26 ( F_27 ( - V_24 , & V_2 -> V_44 -> V_47 ) ) ;
}
V_24 = F_18 ( V_25 + ( F_28 ( V_2 ) -
F_29 ( V_2 ) ) +
V_2 -> V_48 ) ;
V_17 -> V_18 = ~ F_20 ( ( V_39 V_40 ) ( ( V_39 V_41 ) V_17 -> V_18 +
( V_39 V_41 ) V_24 ) ) ;
if ( V_2 -> V_13 == V_14 )
F_21 ( V_2 , ~ V_17 -> V_18 ) ;
else
V_17 -> V_18 = F_22 ( V_2 , ~ V_17 -> V_18 ) ;
V_31:
return V_21 ;
}
struct V_1 * * F_30 ( struct V_1 * * V_49 , struct V_1 * V_2 )
{
struct V_1 * * V_50 = NULL ;
struct V_1 * V_51 ;
struct V_11 * V_17 ;
struct V_11 * V_52 ;
unsigned int V_33 ;
unsigned int V_23 ;
T_2 V_53 ;
unsigned int V_5 = 1 ;
unsigned int V_54 ;
unsigned int V_55 ;
int V_56 = 1 ;
int V_57 ;
V_55 = F_31 ( V_2 ) ;
V_54 = V_55 + sizeof( * V_17 ) ;
V_17 = F_32 ( V_2 , V_55 ) ;
if ( F_33 ( V_2 , V_54 ) ) {
V_17 = F_34 ( V_2 , V_54 , V_55 ) ;
if ( F_7 ( ! V_17 ) )
goto V_31;
}
V_23 = V_17 -> V_30 * 4 ;
if ( V_23 < sizeof( * V_17 ) )
goto V_31;
V_54 = V_55 + V_23 ;
if ( F_33 ( V_2 , V_54 ) ) {
V_17 = F_34 ( V_2 , V_54 , V_55 ) ;
if ( F_7 ( ! V_17 ) )
goto V_31;
}
F_35 ( V_2 , V_23 ) ;
V_33 = F_36 ( V_2 ) ;
V_53 = F_37 ( V_17 ) ;
for (; ( V_51 = * V_49 ) ; V_49 = & V_51 -> V_9 ) {
if ( ! F_38 ( V_51 ) -> V_58 )
continue;
V_52 = F_9 ( V_51 ) ;
if ( * ( V_41 * ) & V_17 -> V_59 ^ * ( V_41 * ) & V_52 -> V_59 ) {
F_38 ( V_51 ) -> V_58 = 0 ;
continue;
}
goto V_60;
}
goto V_61;
V_60:
V_56 = F_38 ( V_51 ) -> V_56 ;
V_56 |= ( V_39 int ) ( V_53 & V_62 ) ;
V_56 |= ( V_39 int ) ( ( V_53 ^ F_37 ( V_52 ) ) &
~ ( V_62 | V_63 | V_64 ) ) ;
V_56 |= ( V_39 int ) ( V_17 -> V_65 ^ V_52 -> V_65 ) ;
for ( V_57 = sizeof( * V_17 ) ; V_57 < V_23 ; V_57 += 4 )
V_56 |= * ( V_41 * ) ( ( V_66 * ) V_17 + V_57 ) ^
* ( V_41 * ) ( ( V_66 * ) V_52 + V_57 ) ;
if ( F_38 ( V_51 ) -> V_67 != 1 ||
F_38 ( V_51 ) -> V_68 != 1 ||
! F_38 ( V_51 ) -> V_69 )
V_56 |= F_38 ( V_51 ) -> V_67 ;
else
F_38 ( V_51 ) -> V_69 = false ;
V_5 = F_3 ( V_51 ) -> V_34 ;
V_56 |= ( V_33 - 1 ) >= V_5 ;
V_56 |= ( F_19 ( V_52 -> V_4 ) + F_36 ( V_51 ) ) ^ F_19 ( V_17 -> V_4 ) ;
if ( V_56 || F_39 ( V_49 , V_2 ) ) {
V_5 = 1 ;
goto V_61;
}
V_51 = * V_49 ;
V_52 = F_9 ( V_51 ) ;
F_37 ( V_52 ) |= V_53 & ( V_63 | V_64 ) ;
V_61:
V_56 = V_33 < V_5 ;
V_56 |= ( V_39 int ) ( V_53 & ( V_70 | V_64 |
V_71 | V_72 |
V_63 ) ) ;
if ( V_51 && ( ! F_38 ( V_2 ) -> V_58 || V_56 ) )
V_50 = V_49 ;
V_31:
F_38 ( V_2 ) -> V_56 |= ( V_56 != 0 ) ;
return V_50 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_2 -> V_73 = ( unsigned char * ) V_17 - V_2 -> V_49 ;
V_2 -> V_74 = F_41 ( struct V_11 , V_18 ) ;
V_2 -> V_13 = V_14 ;
F_3 ( V_2 ) -> V_36 = F_38 ( V_2 ) -> V_68 ;
if ( V_17 -> V_46 )
F_3 ( V_2 ) -> V_75 |= V_76 ;
return 0 ;
}
static struct V_1 * * F_42 ( struct V_1 * * V_49 , struct V_1 * V_2 )
{
if ( ! F_38 ( V_2 ) -> V_56 &&
F_43 ( V_2 , V_77 ,
V_78 ) ) {
F_38 ( V_2 ) -> V_56 = 1 ;
return NULL ;
}
return F_30 ( V_49 , V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_79 )
{
const struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_17 -> V_18 = ~ F_45 ( V_2 -> V_33 - V_79 , V_16 -> V_19 ,
V_16 -> V_20 , 0 ) ;
F_3 ( V_2 ) -> V_75 |= V_80 ;
if ( F_38 ( V_2 ) -> V_69 )
F_3 ( V_2 ) -> V_75 |= V_81 ;
return F_40 ( V_2 ) ;
}
int T_4 F_46 ( void )
{
return F_47 ( & V_82 , V_77 ) ;
}
