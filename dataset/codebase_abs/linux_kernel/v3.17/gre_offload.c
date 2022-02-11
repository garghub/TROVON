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
V_24 |
V_25 ) ) )
goto V_26;
if ( F_4 ( ! F_6 ( V_2 , sizeof( * V_10 ) ) ) )
goto V_26;
V_10 = (struct V_9 * ) F_7 ( V_2 ) ;
V_8 = F_8 ( V_2 ) - F_7 ( V_2 ) ;
if ( F_4 ( V_8 < sizeof( * V_10 ) ) )
goto V_26;
V_16 = ! ! ( V_10 -> V_27 & V_28 ) ;
if ( V_16 )
V_2 -> V_29 = 1 ;
if ( F_4 ( ! F_6 ( V_2 , V_8 ) ) )
goto V_26;
V_2 -> V_14 = V_10 -> V_14 ;
V_2 -> V_3 = 0 ;
F_9 ( V_2 , V_8 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 , F_12 ( V_2 ) ) ;
V_2 -> V_13 = F_12 ( V_2 ) ;
V_7 = V_2 -> V_30 -> V_31 & F_13 ( V_2 ) ;
V_6 = F_14 ( V_2 , V_7 ) ;
if ( F_15 ( V_6 ) ) {
F_16 ( V_2 , V_14 , V_8 , V_11 , V_13 ) ;
goto V_26;
}
V_2 = V_6 ;
V_15 = F_17 ( V_2 ) ;
do {
F_18 ( V_2 , V_8 ) ;
if ( V_16 ) {
T_4 * V_32 ;
if ( F_19 ( V_2 ) ) {
int V_33 ;
V_33 = F_20 ( V_2 ) ;
if ( V_33 ) {
F_21 ( V_6 ) ;
V_6 = F_3 ( V_33 ) ;
goto V_26;
}
}
F_22 ( V_2 ) ;
V_10 = (struct V_9 * )
F_7 ( V_2 ) ;
V_32 = ( T_4 * ) ( V_10 + 1 ) ;
* V_32 = 0 ;
* ( V_34 * ) V_32 = F_23 ( V_2 , 0 ) ;
}
F_18 ( V_2 , V_15 - V_8 ) ;
F_24 ( V_2 ) ;
V_2 -> V_3 = 1 ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_14 = V_14 ;
} while ( ( V_2 = V_2 -> V_35 ) );
V_26:
return V_6 ;
}
static V_34 F_25 ( struct V_1 * V_2 )
{
V_34 V_36 ;
V_2 -> V_16 = F_26 ( V_2 , 0 , V_2 -> V_37 , 0 ) ;
F_27 ( V_2 ) -> V_16 = F_28 ( V_2 -> V_16 ,
F_29 ( V_2 -> V_38 , F_30 ( V_2 ) , 0 ) ) ;
V_36 = F_31 ( F_27 ( V_2 ) -> V_16 ) ;
if ( F_4 ( V_2 -> V_39 == V_40 ) ) {
if ( F_4 ( ! V_36 ) && ! V_2 -> V_41 )
F_32 ( V_2 -> V_30 ) ;
} else {
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = 1 ;
}
return V_36 ;
}
static struct V_1 * * F_33 ( struct V_1 * * V_42 ,
struct V_1 * V_2 )
{
struct V_1 * * V_43 = NULL ;
struct V_1 * V_44 ;
const struct V_9 * V_10 ;
unsigned int V_45 , V_46 ;
unsigned int V_47 ;
int V_48 = 1 ;
struct V_49 * V_50 ;
T_3 type ;
V_47 = F_30 ( V_2 ) ;
V_45 = V_47 + sizeof( * V_10 ) ;
V_10 = F_34 ( V_2 , V_47 ) ;
if ( F_35 ( V_2 , V_45 ) ) {
V_10 = F_36 ( V_2 , V_45 , V_47 ) ;
if ( F_4 ( ! V_10 ) )
goto V_26;
}
if ( ( V_10 -> V_27 & ~ ( V_51 | V_28 ) ) != 0 )
goto V_26;
type = V_10 -> V_14 ;
F_37 () ;
V_50 = F_38 ( type ) ;
if ( V_50 == NULL )
goto V_52;
V_46 = V_53 ;
if ( V_10 -> V_27 & V_51 )
V_46 += V_53 ;
if ( V_10 -> V_27 & V_28 )
V_46 += V_53 ;
V_45 = V_47 + V_46 ;
if ( F_35 ( V_2 , V_45 ) ) {
V_10 = F_36 ( V_2 , V_45 , V_47 ) ;
if ( F_4 ( ! V_10 ) )
goto V_52;
}
if ( V_10 -> V_27 & V_28 ) {
V_34 V_16 = 0 ;
if ( V_2 -> V_39 == V_40 )
V_16 = F_31 ( F_27 ( V_2 ) -> V_16 ) ;
if ( V_2 -> V_39 == V_54 || V_16 != 0 )
V_16 = F_25 ( V_2 ) ;
if ( V_16 )
goto V_52;
}
V_48 = 0 ;
for ( V_44 = * V_42 ; V_44 ; V_44 = V_44 -> V_35 ) {
const struct V_9 * V_55 ;
if ( ! F_27 ( V_44 ) -> V_56 )
continue;
V_55 = (struct V_9 * ) ( V_44 -> V_38 + V_47 ) ;
if ( V_55 -> V_27 != V_10 -> V_27 ||
V_55 -> V_14 != V_10 -> V_14 ) {
F_27 ( V_44 ) -> V_56 = 0 ;
continue;
}
if ( V_10 -> V_27 & V_51 ) {
if ( * ( T_4 * ) ( V_55 + 1 ) != * ( T_4 * ) ( V_10 + 1 ) ) {
F_27 ( V_44 ) -> V_56 = 0 ;
continue;
}
}
}
F_39 ( V_2 , V_46 ) ;
F_40 ( V_2 , V_10 , V_46 ) ;
V_43 = V_50 -> V_57 . V_58 ( V_42 , V_2 ) ;
V_52:
F_41 () ;
V_26:
F_27 ( V_2 ) -> V_48 |= V_48 ;
return V_43 ;
}
static int F_42 ( struct V_1 * V_2 , int V_59 )
{
struct V_9 * V_10 = (struct V_9 * ) ( V_2 -> V_38 + V_59 ) ;
struct V_49 * V_50 ;
unsigned int V_46 = sizeof( * V_10 ) ;
int V_33 = - V_60 ;
T_3 type ;
V_2 -> V_3 = 1 ;
F_5 ( V_2 ) -> V_17 = V_23 ;
type = V_10 -> V_14 ;
if ( V_10 -> V_27 & V_51 )
V_46 += V_53 ;
if ( V_10 -> V_27 & V_28 )
V_46 += V_53 ;
F_37 () ;
V_50 = F_43 ( type ) ;
if ( V_50 != NULL )
V_33 = V_50 -> V_57 . V_61 ( V_2 , V_59 + V_46 ) ;
F_41 () ;
return V_33 ;
}
static int T_5 F_44 ( void )
{
return F_45 ( & V_62 , V_63 ) ;
}
