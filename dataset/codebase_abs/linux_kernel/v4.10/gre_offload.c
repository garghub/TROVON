static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 = F_2 ( V_2 ) - F_3 ( V_2 ) ;
struct V_1 * V_5 = F_4 ( - V_6 ) ;
T_2 V_7 = V_2 -> V_8 ;
T_3 V_9 = V_2 -> V_9 ;
T_2 V_10 = V_2 -> V_10 ;
int V_11 , V_12 ;
bool V_13 , V_14 , V_15 ;
if ( ! V_2 -> V_16 )
goto V_17;
if ( F_5 ( V_4 < sizeof( struct V_18 ) ) )
goto V_17;
if ( F_5 ( ! F_6 ( V_2 , V_4 ) ) )
goto V_17;
V_2 -> V_16 = 0 ;
F_7 ( V_2 ) -> V_19 = 0 ;
F_8 ( V_2 , V_4 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
V_2 -> V_10 = F_11 ( V_2 ) ;
V_2 -> V_9 = V_2 -> V_20 ;
V_13 = ! ! ( F_12 ( V_2 ) -> V_21 & V_22 ) ;
V_2 -> V_23 = V_13 ;
V_14 = ! ! ( F_12 ( V_2 ) -> V_21 & V_24 ) ;
V_3 &= V_2 -> V_25 -> V_26 ;
if ( V_14 ) {
V_3 &= ~ V_27 ;
if ( ! V_13 )
V_3 |= V_28 ;
}
V_5 = F_13 ( V_2 , V_3 ) ;
if ( F_14 ( V_5 ) ) {
F_15 ( V_2 , V_9 , V_4 , V_7 ,
V_10 ) ;
goto V_17;
}
V_15 = ! ! ( F_12 ( V_5 ) -> V_21 & V_29 ) ;
V_12 = F_16 ( V_2 ) ;
V_11 = V_12 - V_4 ;
V_2 = V_5 ;
do {
struct V_18 * V_30 ;
T_4 * V_31 ;
if ( V_2 -> V_32 == V_33 ) {
F_17 ( V_2 ) ;
V_2 -> V_16 = 1 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
F_18 ( V_2 , V_12 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_10 ) ;
F_19 ( V_2 , V_11 ) ;
if ( ! V_13 )
continue;
V_30 = (struct V_18 * ) F_3 ( V_2 ) ;
V_31 = ( T_4 * ) ( V_30 + 1 ) ;
if ( V_15 ) {
unsigned int V_34 ;
V_34 = V_2 -> V_35 + F_20 ( V_2 ) -
F_7 ( V_2 ) -> V_36 -
F_12 ( V_2 ) -> V_37 ;
* V_31 = ~ F_21 ( ( V_38 V_39 ) F_22 ( V_34 ) ) ;
} else {
* V_31 = 0 ;
}
* ( V_31 + 1 ) = 0 ;
* V_31 = F_23 ( V_2 , 0 ) ;
} while ( ( V_2 = V_2 -> V_40 ) );
V_17:
return V_5 ;
}
static struct V_1 * * F_24 ( struct V_1 * * V_41 ,
struct V_1 * V_2 )
{
struct V_1 * * V_42 = NULL ;
struct V_1 * V_43 ;
const struct V_18 * V_30 ;
unsigned int V_44 , V_45 ;
unsigned int V_46 ;
int V_47 = 1 ;
struct V_48 * V_49 ;
T_3 type ;
if ( F_25 ( V_2 ) -> V_50 )
goto V_17;
F_25 ( V_2 ) -> V_50 = 1 ;
V_46 = F_26 ( V_2 ) ;
V_44 = V_46 + sizeof( * V_30 ) ;
V_30 = F_27 ( V_2 , V_46 ) ;
if ( F_28 ( V_2 , V_44 ) ) {
V_30 = F_29 ( V_2 , V_44 , V_46 ) ;
if ( F_5 ( ! V_30 ) )
goto V_17;
}
if ( ( V_30 -> V_51 & ~ ( V_52 | V_53 ) ) != 0 )
goto V_17;
if ( ( V_30 -> V_51 & V_53 ) && F_25 ( V_2 ) -> V_54 )
goto V_17;
type = V_30 -> V_9 ;
F_30 () ;
V_49 = F_31 ( type ) ;
if ( ! V_49 )
goto V_55;
V_45 = V_56 ;
if ( V_30 -> V_51 & V_52 )
V_45 += V_56 ;
if ( V_30 -> V_51 & V_53 )
V_45 += V_56 ;
V_44 = V_46 + V_45 ;
if ( F_28 ( V_2 , V_44 ) ) {
V_30 = F_29 ( V_2 , V_44 , V_46 ) ;
if ( F_5 ( ! V_30 ) )
goto V_55;
}
if ( ( V_30 -> V_51 & V_53 ) && ! F_25 ( V_2 ) -> V_47 ) {
if ( F_32 ( V_2 ) )
goto V_55;
F_33 ( V_2 , V_57 , 0 ,
V_58 ) ;
}
for ( V_43 = * V_41 ; V_43 ; V_43 = V_43 -> V_40 ) {
const struct V_18 * V_59 ;
if ( ! F_25 ( V_43 ) -> V_60 )
continue;
V_59 = (struct V_18 * ) ( V_43 -> V_61 + V_46 ) ;
if ( V_59 -> V_51 != V_30 -> V_51 ||
V_59 -> V_9 != V_30 -> V_9 ) {
F_25 ( V_43 ) -> V_60 = 0 ;
continue;
}
if ( V_30 -> V_51 & V_52 ) {
if ( * ( V_62 * ) ( V_59 + 1 ) != * ( V_62 * ) ( V_30 + 1 ) ) {
F_25 ( V_43 ) -> V_60 = 0 ;
continue;
}
}
}
F_34 ( V_2 , V_45 ) ;
F_35 ( V_2 , V_30 , V_45 ) ;
V_42 = F_36 ( V_49 -> V_63 . V_64 , V_41 , V_2 ) ;
V_47 = 0 ;
V_55:
F_37 () ;
V_17:
F_25 ( V_2 ) -> V_47 |= V_47 ;
return V_42 ;
}
static int F_38 ( struct V_1 * V_2 , int V_65 )
{
struct V_18 * V_30 = (struct V_18 * ) ( V_2 -> V_61 + V_65 ) ;
struct V_48 * V_49 ;
unsigned int V_45 = sizeof( * V_30 ) ;
int V_66 = - V_67 ;
T_3 type ;
V_2 -> V_16 = 1 ;
F_12 ( V_2 ) -> V_21 = V_68 ;
type = V_30 -> V_9 ;
if ( V_30 -> V_51 & V_52 )
V_45 += V_56 ;
if ( V_30 -> V_51 & V_53 )
V_45 += V_56 ;
F_30 () ;
V_49 = F_39 ( type ) ;
if ( V_49 )
V_66 = V_49 -> V_63 . V_69 ( V_2 , V_65 + V_45 ) ;
F_37 () ;
F_40 ( V_2 , V_65 + V_45 ) ;
return V_66 ;
}
static int T_5 F_41 ( void )
{
int V_66 ;
V_66 = F_42 ( & V_70 , V_57 ) ;
#if F_43 ( V_71 )
if ( V_66 )
return V_66 ;
V_66 = F_44 ( & V_70 , V_57 ) ;
if ( V_66 )
F_45 ( & V_70 , V_57 ) ;
#endif
return V_66 ;
}
