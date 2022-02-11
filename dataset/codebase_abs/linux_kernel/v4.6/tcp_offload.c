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
int type = F_3 ( V_2 ) -> V_36 ;
if ( F_7 ( type &
~ ( V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 |
V_47 |
0 ) ||
! ( type & ( V_37 | V_40 ) ) ) )
goto V_31;
F_3 ( V_2 ) -> V_48 = F_14 ( V_2 -> V_33 , V_5 ) ;
V_21 = NULL ;
goto V_31;
}
V_29 = V_26 -> V_49 == V_50 ;
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
V_27 = ~ F_19 ( ( V_51 V_52 ) ( ( V_51 V_53 ) V_17 -> V_18 +
( V_51 V_53 ) V_24 ) ) ;
do {
V_17 -> V_54 = V_17 -> V_55 = 0 ;
V_17 -> V_18 = V_27 ;
if ( V_2 -> V_13 == V_14 )
F_20 ( V_2 , ~ V_17 -> V_18 ) ;
else
V_17 -> V_18 = F_21 ( V_2 , ~ V_17 -> V_18 ) ;
V_4 += V_5 ;
if ( V_29 ) {
V_2 -> V_49 = V_26 -> V_49 ;
V_2 -> V_56 = V_26 -> V_56 ;
V_22 += V_2 -> V_57 ;
}
V_2 = V_2 -> V_9 ;
V_17 = F_9 ( V_2 ) ;
V_17 -> V_4 = F_17 ( V_4 ) ;
V_17 -> V_58 = 0 ;
} while ( V_2 -> V_9 );
if ( V_29 ) {
F_22 ( V_26 -> V_56 , V_2 -> V_56 ) ;
F_22 ( V_26 -> V_49 , V_2 -> V_49 ) ;
V_22 += V_2 -> V_57 ;
F_23 ( V_22 - V_26 -> V_57 ,
& V_2 -> V_56 -> V_59 ) ;
}
V_24 = F_17 ( V_25 + ( F_24 ( V_2 ) -
F_25 ( V_2 ) ) +
V_2 -> V_60 ) ;
V_17 -> V_18 = ~ F_19 ( ( V_51 V_52 ) ( ( V_51 V_53 ) V_17 -> V_18 +
( V_51 V_53 ) V_24 ) ) ;
if ( V_2 -> V_13 == V_14 )
F_20 ( V_2 , ~ V_17 -> V_18 ) ;
else
V_17 -> V_18 = F_21 ( V_2 , ~ V_17 -> V_18 ) ;
V_31:
return V_21 ;
}
struct V_1 * * F_26 ( struct V_1 * * V_61 , struct V_1 * V_2 )
{
struct V_1 * * V_62 = NULL ;
struct V_1 * V_63 ;
struct V_11 * V_17 ;
struct V_11 * V_64 ;
unsigned int V_33 ;
unsigned int V_23 ;
T_2 V_65 ;
unsigned int V_5 = 1 ;
unsigned int V_66 ;
unsigned int V_67 ;
int V_68 = 1 ;
int V_69 ;
V_67 = F_27 ( V_2 ) ;
V_66 = V_67 + sizeof( * V_17 ) ;
V_17 = F_28 ( V_2 , V_67 ) ;
if ( F_29 ( V_2 , V_66 ) ) {
V_17 = F_30 ( V_2 , V_66 , V_67 ) ;
if ( F_7 ( ! V_17 ) )
goto V_31;
}
V_23 = V_17 -> V_30 * 4 ;
if ( V_23 < sizeof( * V_17 ) )
goto V_31;
V_66 = V_67 + V_23 ;
if ( F_29 ( V_2 , V_66 ) ) {
V_17 = F_30 ( V_2 , V_66 , V_67 ) ;
if ( F_7 ( ! V_17 ) )
goto V_31;
}
F_31 ( V_2 , V_23 ) ;
V_33 = F_32 ( V_2 ) ;
V_65 = F_33 ( V_17 ) ;
for (; ( V_63 = * V_61 ) ; V_61 = & V_63 -> V_9 ) {
if ( ! F_34 ( V_63 ) -> V_70 )
continue;
V_64 = F_9 ( V_63 ) ;
if ( * ( V_53 * ) & V_17 -> V_71 ^ * ( V_53 * ) & V_64 -> V_71 ) {
F_34 ( V_63 ) -> V_70 = 0 ;
continue;
}
goto V_72;
}
goto V_73;
V_72:
V_68 = F_34 ( V_63 ) -> V_68 | F_34 ( V_63 ) -> V_74 ;
V_68 |= ( V_51 int ) ( V_65 & V_75 ) ;
V_68 |= ( V_51 int ) ( ( V_65 ^ F_33 ( V_64 ) ) &
~ ( V_75 | V_76 | V_77 ) ) ;
V_68 |= ( V_51 int ) ( V_17 -> V_78 ^ V_64 -> V_78 ) ;
for ( V_69 = sizeof( * V_17 ) ; V_69 < V_23 ; V_69 += 4 )
V_68 |= * ( V_53 * ) ( ( V_79 * ) V_17 + V_69 ) ^
* ( V_53 * ) ( ( V_79 * ) V_64 + V_69 ) ;
V_5 = F_3 ( V_63 ) -> V_34 ;
V_68 |= ( V_33 - 1 ) >= V_5 ;
V_68 |= ( F_18 ( V_64 -> V_4 ) + F_32 ( V_63 ) ) ^ F_18 ( V_17 -> V_4 ) ;
if ( V_68 || F_35 ( V_61 , V_2 ) ) {
V_5 = 1 ;
goto V_73;
}
V_63 = * V_61 ;
V_64 = F_9 ( V_63 ) ;
F_33 ( V_64 ) |= V_65 & ( V_76 | V_77 ) ;
V_73:
V_68 = V_33 < V_5 ;
V_68 |= ( V_51 int ) ( V_65 & ( V_80 | V_77 |
V_81 | V_82 |
V_76 ) ) ;
if ( V_63 && ( ! F_34 ( V_2 ) -> V_70 || V_68 ) )
V_62 = V_61 ;
V_31:
F_34 ( V_2 ) -> V_68 |= ( V_68 != 0 ) ;
return V_62 ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_2 -> V_83 = ( unsigned char * ) V_17 - V_2 -> V_61 ;
V_2 -> V_84 = F_37 ( struct V_11 , V_18 ) ;
V_2 -> V_13 = V_14 ;
F_3 ( V_2 ) -> V_48 = F_34 ( V_2 ) -> V_85 ;
if ( V_17 -> V_58 )
F_3 ( V_2 ) -> V_36 |= V_39 ;
return 0 ;
}
static struct V_1 * * F_38 ( struct V_1 * * V_61 , struct V_1 * V_2 )
{
if ( ! F_34 ( V_2 ) -> V_68 &&
F_39 ( V_2 , V_86 ,
V_87 ) ) {
F_34 ( V_2 ) -> V_68 = 1 ;
return NULL ;
}
return F_26 ( V_61 , V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_88 )
{
const struct V_15 * V_16 = F_8 ( V_2 ) ;
struct V_11 * V_17 = F_9 ( V_2 ) ;
V_17 -> V_18 = ~ F_41 ( V_2 -> V_33 - V_88 , V_16 -> V_19 ,
V_16 -> V_20 , 0 ) ;
F_3 ( V_2 ) -> V_36 |= V_37 ;
return F_36 ( V_2 ) ;
}
int T_4 F_42 ( void )
{
return F_43 ( & V_89 , V_86 ) ;
}
