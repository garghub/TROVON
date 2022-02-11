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
if ( ! V_2 -> V_15 )
goto V_16;
if ( F_5 ( V_4 < sizeof( struct V_17 ) ) )
goto V_16;
if ( F_5 ( ! F_6 ( V_2 , V_4 ) ) )
goto V_16;
V_2 -> V_15 = 0 ;
F_7 ( V_2 ) -> V_18 = 0 ;
F_8 ( V_2 , V_4 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
V_2 -> V_10 = F_11 ( V_2 ) ;
V_2 -> V_9 = V_2 -> V_19 ;
V_13 = ! ! ( F_12 ( V_2 ) -> V_20 & V_21 ) ;
V_2 -> V_22 = V_13 ;
V_14 = ! ! ( F_12 ( V_2 ) -> V_20 & V_23 ) ;
V_3 &= V_2 -> V_24 -> V_25 ;
if ( V_14 ) {
V_3 &= ~ V_26 ;
if ( ! V_13 )
V_3 |= V_27 ;
}
V_5 = F_13 ( V_2 , V_3 ) ;
if ( F_14 ( V_5 ) ) {
F_15 ( V_2 , V_9 , V_4 , V_7 ,
V_10 ) ;
goto V_16;
}
V_12 = F_16 ( V_2 ) ;
V_11 = V_12 - V_4 ;
V_2 = V_5 ;
do {
struct V_17 * V_28 ;
T_4 * V_29 ;
if ( V_2 -> V_30 == V_31 ) {
F_17 ( V_2 ) ;
V_2 -> V_15 = 1 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_9 = V_9 ;
F_18 ( V_2 , V_12 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_10 ) ;
F_19 ( V_2 , V_11 ) ;
if ( ! V_13 )
continue;
V_28 = (struct V_17 * ) F_3 ( V_2 ) ;
V_29 = ( T_4 * ) ( V_28 + 1 ) ;
if ( F_20 ( V_2 ) ) {
unsigned int V_32 ;
V_32 = V_2 -> V_33 + F_21 ( V_2 ) -
F_7 ( V_2 ) -> V_34 -
F_12 ( V_2 ) -> V_35 ;
* V_29 = ~ F_22 ( ( V_36 V_37 ) F_23 ( V_32 ) ) ;
} else {
* V_29 = 0 ;
}
* ( V_29 + 1 ) = 0 ;
* V_29 = F_24 ( V_2 , 0 ) ;
} while ( ( V_2 = V_2 -> V_38 ) );
V_16:
return V_5 ;
}
static struct V_1 * * F_25 ( struct V_1 * * V_39 ,
struct V_1 * V_2 )
{
struct V_1 * * V_40 = NULL ;
struct V_1 * V_41 ;
const struct V_17 * V_28 ;
unsigned int V_42 , V_43 ;
unsigned int V_44 ;
int V_45 = 1 ;
struct V_46 * V_47 ;
T_3 type ;
if ( F_26 ( V_2 ) -> V_48 )
goto V_16;
F_26 ( V_2 ) -> V_48 = 1 ;
V_44 = F_27 ( V_2 ) ;
V_42 = V_44 + sizeof( * V_28 ) ;
V_28 = F_28 ( V_2 , V_44 ) ;
if ( F_29 ( V_2 , V_42 ) ) {
V_28 = F_30 ( V_2 , V_42 , V_44 ) ;
if ( F_5 ( ! V_28 ) )
goto V_16;
}
if ( ( V_28 -> V_49 & ~ ( V_50 | V_51 ) ) != 0 )
goto V_16;
if ( ( V_28 -> V_49 & V_51 ) && F_26 ( V_2 ) -> V_52 )
goto V_16;
type = V_28 -> V_9 ;
F_31 () ;
V_47 = F_32 ( type ) ;
if ( ! V_47 )
goto V_53;
V_43 = V_54 ;
if ( V_28 -> V_49 & V_50 )
V_43 += V_54 ;
if ( V_28 -> V_49 & V_51 )
V_43 += V_54 ;
V_42 = V_44 + V_43 ;
if ( F_29 ( V_2 , V_42 ) ) {
V_28 = F_30 ( V_2 , V_42 , V_44 ) ;
if ( F_5 ( ! V_28 ) )
goto V_53;
}
if ( ( V_28 -> V_49 & V_51 ) && ! F_26 ( V_2 ) -> V_45 ) {
if ( F_33 ( V_2 ) )
goto V_53;
F_34 ( V_2 , V_55 , 0 ,
V_56 ) ;
}
for ( V_41 = * V_39 ; V_41 ; V_41 = V_41 -> V_38 ) {
const struct V_17 * V_57 ;
if ( ! F_26 ( V_41 ) -> V_58 )
continue;
V_57 = (struct V_17 * ) ( V_41 -> V_59 + V_44 ) ;
if ( V_57 -> V_49 != V_28 -> V_49 ||
V_57 -> V_9 != V_28 -> V_9 ) {
F_26 ( V_41 ) -> V_58 = 0 ;
continue;
}
if ( V_28 -> V_49 & V_50 ) {
if ( * ( V_60 * ) ( V_57 + 1 ) != * ( V_60 * ) ( V_28 + 1 ) ) {
F_26 ( V_41 ) -> V_58 = 0 ;
continue;
}
}
}
F_35 ( V_2 , V_43 ) ;
F_36 ( V_2 , V_28 , V_43 ) ;
V_40 = V_47 -> V_61 . V_62 ( V_39 , V_2 ) ;
V_45 = 0 ;
V_53:
F_37 () ;
V_16:
F_26 ( V_2 ) -> V_45 |= V_45 ;
return V_40 ;
}
static int F_38 ( struct V_1 * V_2 , int V_63 )
{
struct V_17 * V_28 = (struct V_17 * ) ( V_2 -> V_59 + V_63 ) ;
struct V_46 * V_47 ;
unsigned int V_43 = sizeof( * V_28 ) ;
int V_64 = - V_65 ;
T_3 type ;
V_2 -> V_15 = 1 ;
F_12 ( V_2 ) -> V_20 = V_66 ;
type = V_28 -> V_9 ;
if ( V_28 -> V_49 & V_50 )
V_43 += V_54 ;
if ( V_28 -> V_49 & V_51 )
V_43 += V_54 ;
F_31 () ;
V_47 = F_39 ( type ) ;
if ( V_47 )
V_64 = V_47 -> V_61 . V_67 ( V_2 , V_63 + V_43 ) ;
F_37 () ;
F_40 ( V_2 , V_63 + V_43 ) ;
return V_64 ;
}
static int T_5 F_41 ( void )
{
int V_64 ;
V_64 = F_42 ( & V_68 , V_55 ) ;
#if F_43 ( V_69 )
if ( V_64 )
return V_64 ;
V_64 = F_44 ( & V_68 , V_55 ) ;
if ( V_64 )
F_45 ( & V_68 , V_55 ) ;
#endif
return V_64 ;
}
