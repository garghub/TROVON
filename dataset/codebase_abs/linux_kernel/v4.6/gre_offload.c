static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 = F_2 ( V_2 ) - F_3 ( V_2 ) ;
struct V_1 * V_5 = F_4 ( - V_6 ) ;
T_2 V_7 = V_2 -> V_8 ;
T_3 V_9 = V_2 -> V_9 ;
T_2 V_10 = V_2 -> V_10 ;
int V_11 , V_12 ;
bool V_13 , V_14 ;
if ( F_5 ( F_6 ( V_2 ) -> V_15 &
~ ( V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 ) ) )
goto V_25;
if ( ! V_2 -> V_26 )
goto V_25;
if ( F_5 ( V_4 < sizeof( struct V_27 ) ) )
goto V_25;
if ( F_5 ( ! F_7 ( V_2 , V_4 ) ) )
goto V_25;
V_2 -> V_26 = 0 ;
F_8 ( V_2 ) -> V_28 = 0 ;
F_9 ( V_2 , V_4 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 , F_12 ( V_2 ) ) ;
V_2 -> V_10 = F_12 ( V_2 ) ;
V_2 -> V_9 = V_2 -> V_29 ;
V_13 = ! ! ( F_6 ( V_2 ) -> V_15 & V_22 ) ;
V_2 -> V_30 = V_13 ;
V_14 = ! ! ( F_6 ( V_2 ) -> V_15 & V_18 ) ;
V_3 &= V_2 -> V_31 -> V_32 ;
if ( V_14 ) {
V_3 &= ~ V_33 ;
if ( ! V_13 )
V_3 |= V_34 ;
}
V_5 = F_13 ( V_2 , V_3 ) ;
if ( F_14 ( V_5 ) ) {
F_15 ( V_2 , V_9 , V_4 , V_7 ,
V_10 ) ;
goto V_25;
}
V_12 = F_16 ( V_2 ) ;
V_11 = V_12 - V_4 ;
V_2 = V_5 ;
do {
struct V_27 * V_35 ;
T_4 * V_36 ;
if ( V_2 -> V_37 == V_38 ) {
F_17 ( V_2 ) ;
V_2 -> V_26 = 1 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
F_18 ( V_2 , V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_10 ) ;
F_19 ( V_2 , V_11 ) ;
if ( ! V_13 )
continue;
V_35 = (struct V_27 * ) F_3 ( V_2 ) ;
V_36 = ( T_4 * ) ( V_35 + 1 ) ;
* V_36 = 0 ;
* ( V_39 * ) V_36 = F_20 ( V_2 , 0 ) ;
} while ( ( V_2 = V_2 -> V_40 ) );
V_25:
return V_5 ;
}
static struct V_1 * * F_21 ( struct V_1 * * V_41 ,
struct V_1 * V_2 )
{
struct V_1 * * V_42 = NULL ;
struct V_1 * V_43 ;
const struct V_27 * V_35 ;
unsigned int V_44 , V_45 ;
unsigned int V_46 ;
int V_47 = 1 ;
struct V_48 * V_49 ;
T_3 type ;
if ( F_22 ( V_2 ) -> V_50 )
goto V_25;
F_22 ( V_2 ) -> V_50 = 1 ;
V_46 = F_23 ( V_2 ) ;
V_44 = V_46 + sizeof( * V_35 ) ;
V_35 = F_24 ( V_2 , V_46 ) ;
if ( F_25 ( V_2 , V_44 ) ) {
V_35 = F_26 ( V_2 , V_44 , V_46 ) ;
if ( F_5 ( ! V_35 ) )
goto V_25;
}
if ( ( V_35 -> V_51 & ~ ( V_52 | V_53 ) ) != 0 )
goto V_25;
if ( ( V_35 -> V_51 & V_53 ) && F_22 ( V_2 ) -> V_54 )
goto V_25;
type = V_35 -> V_9 ;
F_27 () ;
V_49 = F_28 ( type ) ;
if ( ! V_49 )
goto V_55;
V_45 = V_56 ;
if ( V_35 -> V_51 & V_52 )
V_45 += V_56 ;
if ( V_35 -> V_51 & V_53 )
V_45 += V_56 ;
V_44 = V_46 + V_45 ;
if ( F_25 ( V_2 , V_44 ) ) {
V_35 = F_26 ( V_2 , V_44 , V_46 ) ;
if ( F_5 ( ! V_35 ) )
goto V_55;
}
if ( ( V_35 -> V_51 & V_53 ) && ! F_22 ( V_2 ) -> V_47 ) {
if ( F_29 ( V_2 ) )
goto V_55;
F_30 ( V_2 , V_57 , 0 ,
V_58 ) ;
}
for ( V_43 = * V_41 ; V_43 ; V_43 = V_43 -> V_40 ) {
const struct V_27 * V_59 ;
if ( ! F_22 ( V_43 ) -> V_60 )
continue;
V_59 = (struct V_27 * ) ( V_43 -> V_61 + V_46 ) ;
if ( V_59 -> V_51 != V_35 -> V_51 ||
V_59 -> V_9 != V_35 -> V_9 ) {
F_22 ( V_43 ) -> V_60 = 0 ;
continue;
}
if ( V_35 -> V_51 & V_52 ) {
if ( * ( T_4 * ) ( V_59 + 1 ) != * ( T_4 * ) ( V_35 + 1 ) ) {
F_22 ( V_43 ) -> V_60 = 0 ;
continue;
}
}
}
F_31 ( V_2 , V_45 ) ;
F_32 ( V_2 , V_35 , V_45 ) ;
V_42 = V_49 -> V_62 . V_63 ( V_41 , V_2 ) ;
V_47 = 0 ;
V_55:
F_33 () ;
V_25:
F_22 ( V_2 ) -> V_47 |= V_47 ;
return V_42 ;
}
static int F_34 ( struct V_1 * V_2 , int V_64 )
{
struct V_27 * V_35 = (struct V_27 * ) ( V_2 -> V_61 + V_64 ) ;
struct V_48 * V_49 ;
unsigned int V_45 = sizeof( * V_35 ) ;
int V_65 = - V_66 ;
T_3 type ;
V_2 -> V_26 = 1 ;
F_6 ( V_2 ) -> V_15 = V_21 ;
type = V_35 -> V_9 ;
if ( V_35 -> V_51 & V_52 )
V_45 += V_56 ;
if ( V_35 -> V_51 & V_53 )
V_45 += V_56 ;
F_27 () ;
V_49 = F_35 ( type ) ;
if ( V_49 )
V_65 = V_49 -> V_62 . V_67 ( V_2 , V_64 + V_45 ) ;
F_33 () ;
F_36 ( V_2 , V_64 + V_45 ) ;
return V_65 ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_68 , V_57 ) ;
}
