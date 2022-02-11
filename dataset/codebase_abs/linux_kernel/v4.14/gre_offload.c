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
V_3 &= V_2 -> V_23 -> V_24 ;
V_5 = F_13 ( V_2 , V_3 ) ;
if ( F_14 ( V_5 ) ) {
F_15 ( V_2 , V_9 , V_4 , V_7 ,
V_10 ) ;
goto V_16;
}
V_14 = ! ! ( F_12 ( V_5 ) -> V_20 & V_25 ) ;
V_12 = F_16 ( V_2 ) ;
V_11 = V_12 - V_4 ;
V_2 = V_5 ;
do {
struct V_17 * V_26 ;
T_4 * V_27 ;
if ( V_2 -> V_28 == V_29 ) {
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
V_26 = (struct V_17 * ) F_3 ( V_2 ) ;
V_27 = ( T_4 * ) ( V_26 + 1 ) ;
if ( V_14 && F_20 ( V_2 ) ) {
unsigned int V_30 ;
V_30 = V_2 -> V_31 + F_21 ( V_2 ) -
F_7 ( V_2 ) -> V_32 -
F_12 ( V_2 ) -> V_33 ;
* V_27 = ~ F_22 ( ( V_34 V_35 ) F_23 ( V_30 ) ) ;
} else {
* V_27 = 0 ;
}
* ( V_27 + 1 ) = 0 ;
* V_27 = F_24 ( V_2 , 0 ) ;
} while ( ( V_2 = V_2 -> V_36 ) );
V_16:
return V_5 ;
}
static struct V_1 * * F_25 ( struct V_1 * * V_37 ,
struct V_1 * V_2 )
{
struct V_1 * * V_38 = NULL ;
struct V_1 * V_39 ;
const struct V_17 * V_26 ;
unsigned int V_40 , V_41 ;
unsigned int V_42 ;
int V_43 = 1 ;
struct V_44 * V_45 ;
T_3 type ;
if ( F_26 ( V_2 ) -> V_46 )
goto V_16;
F_26 ( V_2 ) -> V_46 = 1 ;
V_42 = F_27 ( V_2 ) ;
V_40 = V_42 + sizeof( * V_26 ) ;
V_26 = F_28 ( V_2 , V_42 ) ;
if ( F_29 ( V_2 , V_40 ) ) {
V_26 = F_30 ( V_2 , V_40 , V_42 ) ;
if ( F_5 ( ! V_26 ) )
goto V_16;
}
if ( ( V_26 -> V_47 & ~ ( V_48 | V_49 ) ) != 0 )
goto V_16;
if ( ( V_26 -> V_47 & V_49 ) && F_26 ( V_2 ) -> V_50 )
goto V_16;
type = V_26 -> V_9 ;
F_31 () ;
V_45 = F_32 ( type ) ;
if ( ! V_45 )
goto V_51;
V_41 = V_52 ;
if ( V_26 -> V_47 & V_48 )
V_41 += V_52 ;
if ( V_26 -> V_47 & V_49 )
V_41 += V_52 ;
V_40 = V_42 + V_41 ;
if ( F_29 ( V_2 , V_40 ) ) {
V_26 = F_30 ( V_2 , V_40 , V_42 ) ;
if ( F_5 ( ! V_26 ) )
goto V_51;
}
if ( ( V_26 -> V_47 & V_49 ) && ! F_26 ( V_2 ) -> V_43 ) {
if ( F_33 ( V_2 ) )
goto V_51;
F_34 ( V_2 , V_53 , 0 ,
V_54 ) ;
}
for ( V_39 = * V_37 ; V_39 ; V_39 = V_39 -> V_36 ) {
const struct V_17 * V_55 ;
if ( ! F_26 ( V_39 ) -> V_56 )
continue;
V_55 = (struct V_17 * ) ( V_39 -> V_57 + V_42 ) ;
if ( V_55 -> V_47 != V_26 -> V_47 ||
V_55 -> V_9 != V_26 -> V_9 ) {
F_26 ( V_39 ) -> V_56 = 0 ;
continue;
}
if ( V_26 -> V_47 & V_48 ) {
if ( * ( V_58 * ) ( V_55 + 1 ) != * ( V_58 * ) ( V_26 + 1 ) ) {
F_26 ( V_39 ) -> V_56 = 0 ;
continue;
}
}
}
F_35 ( V_2 , V_41 ) ;
F_36 ( V_2 , V_26 , V_41 ) ;
V_38 = F_37 ( V_45 -> V_59 . V_60 , V_37 , V_2 ) ;
V_43 = 0 ;
V_51:
F_38 () ;
V_16:
F_26 ( V_2 ) -> V_43 |= V_43 ;
return V_38 ;
}
static int F_39 ( struct V_1 * V_2 , int V_61 )
{
struct V_17 * V_26 = (struct V_17 * ) ( V_2 -> V_57 + V_61 ) ;
struct V_44 * V_45 ;
unsigned int V_41 = sizeof( * V_26 ) ;
int V_62 = - V_63 ;
T_3 type ;
V_2 -> V_15 = 1 ;
F_12 ( V_2 ) -> V_20 = V_64 ;
type = V_26 -> V_9 ;
if ( V_26 -> V_47 & V_48 )
V_41 += V_52 ;
if ( V_26 -> V_47 & V_49 )
V_41 += V_52 ;
F_31 () ;
V_45 = F_40 ( type ) ;
if ( V_45 )
V_62 = V_45 -> V_59 . V_65 ( V_2 , V_61 + V_41 ) ;
F_38 () ;
F_41 ( V_2 , V_61 + V_41 ) ;
return V_62 ;
}
static int T_5 F_42 ( void )
{
int V_62 ;
V_62 = F_43 ( & V_66 , V_53 ) ;
#if F_44 ( V_67 )
if ( V_62 )
return V_62 ;
V_62 = F_45 ( & V_66 , V_53 ) ;
if ( V_62 )
F_46 ( & V_66 , V_53 ) ;
#endif
return V_62 ;
}
