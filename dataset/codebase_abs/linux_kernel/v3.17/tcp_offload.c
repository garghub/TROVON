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
struct V_1 * F_4 ( struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_1 * V_11 = F_5 ( - V_12 ) ;
unsigned int V_13 = 0 ;
struct V_14 * V_15 ;
unsigned int V_16 ;
unsigned int V_4 ;
T_2 V_17 ;
unsigned int V_18 ;
unsigned int V_5 ;
struct V_1 * V_19 = V_2 ;
T_3 V_20 ;
bool V_21 , V_22 ;
if ( ! F_6 ( V_2 , sizeof( * V_15 ) ) )
goto V_23;
V_15 = F_7 ( V_2 ) ;
V_16 = V_15 -> V_24 * 4 ;
if ( V_16 < sizeof( * V_15 ) )
goto V_23;
if ( ! F_6 ( V_2 , V_16 ) )
goto V_23;
V_18 = ( V_25 ) ~ V_2 -> V_26 ;
F_8 ( V_2 , V_16 ) ;
V_5 = F_9 ( V_2 ) ;
if ( F_10 ( V_2 -> V_26 <= V_5 ) )
goto V_23;
if ( F_11 ( V_2 , V_10 | V_27 ) ) {
int type = F_3 ( V_2 ) -> V_28 ;
if ( F_10 ( type &
~ ( V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
0 ) ||
! ( type & ( V_29 | V_32 ) ) ) )
goto V_23;
F_3 ( V_2 ) -> V_40 = F_12 ( V_2 -> V_26 , V_5 ) ;
V_11 = NULL ;
goto V_23;
}
V_22 = V_19 -> V_41 == V_42 ;
V_21 = V_19 -> V_21 ;
V_2 -> V_21 = 0 ;
V_11 = F_13 ( V_2 , V_10 ) ;
if ( F_14 ( V_11 ) )
goto V_23;
V_11 -> V_21 = V_21 ;
V_17 = F_15 ( V_18 + ( V_16 + V_5 ) ) ;
V_2 = V_11 ;
V_15 = F_7 ( V_2 ) ;
V_4 = F_16 ( V_15 -> V_4 ) ;
if ( F_10 ( F_3 ( V_19 ) -> V_6 & V_7 ) )
F_1 ( V_11 , F_3 ( V_19 ) -> V_8 , V_4 , V_5 ) ;
V_20 = ~ F_17 ( ( V_43 V_44 ) ( ( V_43 V_45 ) V_15 -> V_46 +
( V_43 V_45 ) V_17 ) ) ;
do {
V_15 -> V_47 = V_15 -> V_48 = 0 ;
V_15 -> V_46 = V_20 ;
if ( V_2 -> V_49 != V_50 )
V_15 -> V_46 = F_18 ( V_2 , ~ V_15 -> V_46 ) ;
V_4 += V_5 ;
if ( V_22 ) {
V_2 -> V_41 = V_19 -> V_41 ;
V_2 -> V_51 = V_19 -> V_51 ;
V_13 += V_2 -> V_52 ;
}
V_2 = V_2 -> V_9 ;
V_15 = F_7 ( V_2 ) ;
V_15 -> V_4 = F_15 ( V_4 ) ;
V_15 -> V_53 = 0 ;
} while ( V_2 -> V_9 );
if ( V_22 ) {
F_19 ( V_19 -> V_51 , V_2 -> V_51 ) ;
F_19 ( V_19 -> V_41 , V_2 -> V_41 ) ;
V_13 += V_2 -> V_52 ;
F_20 ( V_13 - V_19 -> V_52 ,
& V_2 -> V_51 -> V_54 ) ;
}
V_17 = F_15 ( V_18 + ( F_21 ( V_2 ) -
F_22 ( V_2 ) ) +
V_2 -> V_55 ) ;
V_15 -> V_46 = ~ F_17 ( ( V_43 V_44 ) ( ( V_43 V_45 ) V_15 -> V_46 +
( V_43 V_45 ) V_17 ) ) ;
if ( V_2 -> V_49 != V_50 )
V_15 -> V_46 = F_18 ( V_2 , ~ V_15 -> V_46 ) ;
V_23:
return V_11 ;
}
struct V_1 * * F_23 ( struct V_1 * * V_56 , struct V_1 * V_2 )
{
struct V_1 * * V_57 = NULL ;
struct V_1 * V_58 ;
struct V_14 * V_15 ;
struct V_14 * V_59 ;
unsigned int V_26 ;
unsigned int V_16 ;
T_2 V_60 ;
unsigned int V_5 = 1 ;
unsigned int V_61 ;
unsigned int V_62 ;
int V_63 = 1 ;
int V_64 ;
V_62 = F_24 ( V_2 ) ;
V_61 = V_62 + sizeof( * V_15 ) ;
V_15 = F_25 ( V_2 , V_62 ) ;
if ( F_26 ( V_2 , V_61 ) ) {
V_15 = F_27 ( V_2 , V_61 , V_62 ) ;
if ( F_10 ( ! V_15 ) )
goto V_23;
}
V_16 = V_15 -> V_24 * 4 ;
if ( V_16 < sizeof( * V_15 ) )
goto V_23;
V_61 = V_62 + V_16 ;
if ( F_26 ( V_2 , V_61 ) ) {
V_15 = F_27 ( V_2 , V_61 , V_62 ) ;
if ( F_10 ( ! V_15 ) )
goto V_23;
}
F_28 ( V_2 , V_16 ) ;
V_26 = F_29 ( V_2 ) ;
V_60 = F_30 ( V_15 ) ;
for (; ( V_58 = * V_56 ) ; V_56 = & V_58 -> V_9 ) {
if ( ! F_31 ( V_58 ) -> V_65 )
continue;
V_59 = F_7 ( V_58 ) ;
if ( * ( V_45 * ) & V_15 -> V_66 ^ * ( V_45 * ) & V_59 -> V_66 ) {
F_31 ( V_58 ) -> V_65 = 0 ;
continue;
}
goto V_67;
}
goto V_68;
V_67:
V_63 = F_31 ( V_58 ) -> V_63 | F_31 ( V_58 ) -> V_69 ;
V_63 |= ( V_43 int ) ( V_60 & V_70 ) ;
V_63 |= ( V_43 int ) ( ( V_60 ^ F_30 ( V_59 ) ) &
~ ( V_70 | V_71 | V_72 ) ) ;
V_63 |= ( V_43 int ) ( V_15 -> V_73 ^ V_59 -> V_73 ) ;
for ( V_64 = sizeof( * V_15 ) ; V_64 < V_16 ; V_64 += 4 )
V_63 |= * ( V_45 * ) ( ( V_74 * ) V_15 + V_64 ) ^
* ( V_45 * ) ( ( V_74 * ) V_59 + V_64 ) ;
V_5 = F_9 ( V_58 ) ;
V_63 |= ( V_26 - 1 ) >= V_5 ;
V_63 |= ( F_16 ( V_59 -> V_4 ) + F_29 ( V_58 ) ) ^ F_16 ( V_15 -> V_4 ) ;
if ( V_63 || F_32 ( V_56 , V_2 ) ) {
V_5 = 1 ;
goto V_68;
}
V_58 = * V_56 ;
V_59 = F_7 ( V_58 ) ;
F_30 ( V_59 ) |= V_60 & ( V_71 | V_72 ) ;
V_68:
V_63 = V_26 < V_5 ;
V_63 |= ( V_43 int ) ( V_60 & ( V_75 | V_72 |
V_76 | V_77 |
V_71 ) ) ;
if ( V_58 && ( ! F_31 ( V_2 ) -> V_65 || V_63 ) )
V_57 = V_56 ;
V_23:
F_31 ( V_2 ) -> V_63 |= ( V_63 != 0 ) ;
return V_57 ;
}
int F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
V_2 -> V_78 = ( unsigned char * ) V_15 - V_2 -> V_56 ;
V_2 -> V_79 = F_34 ( struct V_14 , V_46 ) ;
V_2 -> V_49 = V_50 ;
F_3 ( V_2 ) -> V_40 = F_31 ( V_2 ) -> V_80 ;
if ( V_15 -> V_53 )
F_3 ( V_2 ) -> V_28 |= V_31 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
const struct V_81 * V_82 ;
struct V_14 * V_15 ;
if ( ! F_6 ( V_2 , sizeof( * V_15 ) ) )
return - V_12 ;
V_82 = F_36 ( V_2 ) ;
V_15 = F_7 ( V_2 ) ;
V_15 -> V_46 = 0 ;
V_2 -> V_49 = V_50 ;
F_37 ( V_2 , V_82 -> V_83 , V_82 -> V_84 ) ;
return 0 ;
}
static struct V_1 * * F_38 ( struct V_1 * * V_56 , struct V_1 * V_2 )
{
const struct V_81 * V_82 = F_39 ( V_2 ) ;
V_44 V_85 ;
if ( F_31 ( V_2 ) -> V_63 )
goto V_86;
V_85 = F_31 ( V_2 ) -> V_87 ;
switch ( V_2 -> V_49 ) {
case V_88 :
V_85 = F_40 ( V_2 , F_24 ( V_2 ) , F_29 ( V_2 ) ,
0 ) ;
case V_89 :
if ( ! F_41 ( F_29 ( V_2 ) , V_82 -> V_83 , V_82 -> V_84 ,
V_85 ) ) {
V_2 -> V_49 = V_90 ;
break;
}
F_31 ( V_2 ) -> V_63 = 1 ;
return NULL ;
}
V_86:
return F_23 ( V_56 , V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 , int V_91 )
{
const struct V_81 * V_82 = F_36 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_2 ) ;
V_15 -> V_46 = ~ F_41 ( V_2 -> V_26 - V_91 , V_82 -> V_83 ,
V_82 -> V_84 , 0 ) ;
F_3 ( V_2 ) -> V_28 |= V_29 ;
return F_33 ( V_2 ) ;
}
int T_4 F_43 ( void )
{
return F_44 ( & V_92 , V_93 ) ;
}
