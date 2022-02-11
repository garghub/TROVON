static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return - V_4 ;
return 0 ;
}
static struct V_1 * F_2 ( struct V_1 * V_2 ,
T_1 V_5 )
{
struct V_1 * V_6 = F_3 ( - V_4 ) ;
T_1 V_7 ;
int V_8 ;
struct V_9 * V_10 ;
T_2 V_11 = V_2 -> V_12 ;
int V_13 = V_2 -> V_13 ;
T_3 V_14 = V_2 -> V_14 ;
int V_15 ;
bool V_16 ;
if ( F_4 ( F_5 ( V_2 ) -> V_17 &
~ ( V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 ) ) )
goto V_25;
if ( F_4 ( ! F_6 ( V_2 , sizeof( * V_10 ) ) ) )
goto V_25;
V_10 = (struct V_9 * ) F_7 ( V_2 ) ;
V_8 = F_8 ( V_2 ) - F_7 ( V_2 ) ;
if ( F_4 ( V_8 < sizeof( * V_10 ) ) )
goto V_25;
V_16 = ! ! ( V_10 -> V_26 & V_27 ) ;
if ( F_4 ( ! F_6 ( V_2 , V_8 ) ) )
goto V_25;
V_2 -> V_14 = V_10 -> V_14 ;
V_2 -> V_3 = 0 ;
F_9 ( V_2 , V_8 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 , F_12 ( V_2 ) ) ;
V_2 -> V_13 = F_12 ( V_2 ) ;
V_7 = V_2 -> V_28 -> V_29 & F_13 ( V_2 ) ;
V_6 = F_14 ( V_2 , V_7 ) ;
if ( ! V_6 || F_15 ( V_6 ) ) {
F_16 ( V_2 , V_14 , V_8 , V_11 , V_13 ) ;
goto V_25;
}
V_2 = V_6 ;
V_15 = F_17 ( V_2 ) ;
do {
F_18 ( V_2 , V_8 ) ;
if ( V_16 ) {
T_4 * V_30 ;
if ( F_19 ( V_2 ) ) {
int V_31 ;
V_31 = F_20 ( V_2 ) ;
if ( V_31 ) {
F_21 ( V_6 ) ;
V_6 = F_3 ( V_31 ) ;
goto V_25;
}
}
V_10 = (struct V_9 * ) ( V_2 -> V_32 ) ;
V_30 = ( T_4 * ) ( V_10 + 1 ) ;
* V_30 = 0 ;
* ( V_33 * ) V_30 = F_22 ( F_23 ( V_2 , 0 , V_2 -> V_34 , 0 ) ) ;
}
F_18 ( V_2 , V_15 - V_8 ) ;
F_24 ( V_2 ) ;
V_2 -> V_3 = 1 ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_14 = V_14 ;
} while ( ( V_2 = V_2 -> V_35 ) );
V_25:
return V_6 ;
}
static V_33 F_25 ( struct V_1 * V_2 )
{
V_33 V_36 ;
V_2 -> V_16 = F_23 ( V_2 , 0 , V_2 -> V_34 , 0 ) ;
F_26 ( V_2 ) -> V_16 = F_27 ( V_2 -> V_16 ,
F_28 ( V_2 -> V_32 , F_29 ( V_2 ) , 0 ) ) ;
V_36 = F_22 ( F_26 ( V_2 ) -> V_16 ) ;
if ( F_4 ( V_2 -> V_37 == V_38 ) ) {
if ( F_4 ( ! V_36 ) )
F_30 ( V_2 -> V_28 ) ;
} else
V_2 -> V_37 = V_38 ;
return V_36 ;
}
static struct V_1 * * F_31 ( struct V_1 * * V_39 ,
struct V_1 * V_2 )
{
struct V_1 * * V_40 = NULL ;
struct V_1 * V_41 ;
const struct V_9 * V_10 ;
unsigned int V_42 , V_43 ;
unsigned int V_44 ;
int V_45 = 1 ;
struct V_46 * V_47 ;
T_3 type ;
V_44 = F_29 ( V_2 ) ;
V_42 = V_44 + sizeof( * V_10 ) ;
V_10 = F_32 ( V_2 , V_44 ) ;
if ( F_33 ( V_2 , V_42 ) ) {
V_10 = F_34 ( V_2 , V_42 , V_44 ) ;
if ( F_4 ( ! V_10 ) )
goto V_25;
}
if ( ( V_10 -> V_26 & ~ ( V_48 | V_27 ) ) != 0 )
goto V_25;
type = V_10 -> V_14 ;
F_35 () ;
V_47 = F_36 ( type ) ;
if ( V_47 == NULL )
goto V_49;
V_43 = V_50 ;
if ( V_10 -> V_26 & V_48 )
V_43 += V_50 ;
if ( V_10 -> V_26 & V_27 )
V_43 += V_50 ;
V_42 = V_44 + V_43 ;
if ( F_33 ( V_2 , V_42 ) ) {
V_10 = F_34 ( V_2 , V_42 , V_44 ) ;
if ( F_4 ( ! V_10 ) )
goto V_49;
}
if ( V_10 -> V_26 & V_27 ) {
V_33 V_16 = 0 ;
if ( V_2 -> V_37 == V_38 )
V_16 = F_22 ( F_26 ( V_2 ) -> V_16 ) ;
if ( V_2 -> V_37 == V_51 || V_16 != 0 )
V_16 = F_25 ( V_2 ) ;
if ( V_16 )
goto V_49;
}
V_45 = 0 ;
for ( V_41 = * V_39 ; V_41 ; V_41 = V_41 -> V_35 ) {
const struct V_9 * V_52 ;
if ( ! F_26 ( V_41 ) -> V_53 )
continue;
V_52 = (struct V_9 * ) ( V_41 -> V_32 + V_44 ) ;
if ( V_52 -> V_26 != V_10 -> V_26 ||
V_52 -> V_14 != V_10 -> V_14 ) {
F_26 ( V_41 ) -> V_53 = 0 ;
continue;
}
if ( V_10 -> V_26 & V_48 ) {
if ( * ( T_4 * ) ( V_52 + 1 ) != * ( T_4 * ) ( V_10 + 1 ) ) {
F_26 ( V_41 ) -> V_53 = 0 ;
continue;
}
}
}
F_37 ( V_2 , V_43 ) ;
F_38 ( V_2 , V_10 , V_43 ) ;
V_40 = V_47 -> V_54 . V_55 ( V_39 , V_2 ) ;
V_49:
F_39 () ;
V_25:
F_26 ( V_2 ) -> V_45 |= V_45 ;
return V_40 ;
}
static int F_40 ( struct V_1 * V_2 , int V_56 )
{
struct V_9 * V_10 = (struct V_9 * ) ( V_2 -> V_32 + V_56 ) ;
struct V_46 * V_47 ;
unsigned int V_43 = sizeof( * V_10 ) ;
int V_31 = - V_57 ;
T_3 type ;
type = V_10 -> V_14 ;
if ( V_10 -> V_26 & V_48 )
V_43 += V_50 ;
if ( V_10 -> V_26 & V_27 )
V_43 += V_50 ;
F_35 () ;
V_47 = F_41 ( type ) ;
if ( V_47 != NULL )
V_31 = V_47 -> V_54 . V_58 ( V_2 , V_56 + V_43 ) ;
F_39 () ;
return V_31 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_59 , V_60 ) ;
}
