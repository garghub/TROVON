static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
T_1 V_6 ;
int V_7 ;
struct V_8 * V_9 ;
T_2 V_10 = V_2 -> V_11 ;
int V_12 = V_2 -> V_12 ;
T_3 V_13 = V_2 -> V_13 ;
int V_14 ;
bool V_15 ;
if ( F_3 ( F_4 ( V_2 ) -> V_16 &
~ ( V_17 |
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
if ( F_3 ( ! F_5 ( V_2 , sizeof( * V_9 ) ) ) )
goto V_25;
V_9 = (struct V_8 * ) F_6 ( V_2 ) ;
V_7 = F_7 ( V_2 ) - F_6 ( V_2 ) ;
if ( F_3 ( V_7 < sizeof( * V_9 ) ) )
goto V_25;
V_15 = ! ! ( V_9 -> V_27 & V_28 ) ;
if ( V_15 )
V_2 -> V_29 = 1 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_26 = 0 ;
if ( F_3 ( ! F_5 ( V_2 , V_7 ) ) )
goto V_25;
F_8 ( V_2 , V_7 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
V_2 -> V_12 = F_11 ( V_2 ) ;
V_6 = V_2 -> V_30 -> V_31 & V_3 ;
V_4 = F_12 ( V_2 , V_6 ) ;
if ( F_13 ( V_4 ) ) {
F_14 ( V_2 , V_13 , V_7 , V_10 , V_12 ) ;
goto V_25;
}
V_2 = V_4 ;
V_14 = F_15 ( V_2 ) ;
do {
F_16 ( V_2 , V_7 ) ;
if ( V_15 ) {
T_4 * V_32 ;
if ( F_17 ( V_2 ) ) {
int V_33 ;
V_33 = F_18 ( V_2 ) ;
if ( V_33 ) {
F_19 ( V_4 ) ;
V_4 = F_2 ( V_33 ) ;
goto V_25;
}
}
F_20 ( V_2 ) ;
V_9 = (struct V_8 * )
F_6 ( V_2 ) ;
V_32 = ( T_4 * ) ( V_9 + 1 ) ;
* V_32 = 0 ;
* ( V_34 * ) V_32 = F_21 ( V_2 , 0 ) ;
}
F_16 ( V_2 , V_14 - V_7 ) ;
F_22 ( V_2 ) ;
V_2 -> V_26 = 1 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_13 ;
} while ( ( V_2 = V_2 -> V_35 ) );
V_25:
return V_4 ;
}
static struct V_1 * * F_23 ( struct V_1 * * V_36 ,
struct V_1 * V_2 )
{
struct V_1 * * V_37 = NULL ;
struct V_1 * V_38 ;
const struct V_8 * V_9 ;
unsigned int V_39 , V_40 ;
unsigned int V_41 ;
int V_42 = 1 ;
struct V_43 * V_44 ;
T_3 type ;
V_41 = F_24 ( V_2 ) ;
V_39 = V_41 + sizeof( * V_9 ) ;
V_9 = F_25 ( V_2 , V_41 ) ;
if ( F_26 ( V_2 , V_39 ) ) {
V_9 = F_27 ( V_2 , V_39 , V_41 ) ;
if ( F_3 ( ! V_9 ) )
goto V_25;
}
if ( ( V_9 -> V_27 & ~ ( V_45 | V_28 ) ) != 0 )
goto V_25;
type = V_9 -> V_13 ;
F_28 () ;
V_44 = F_29 ( type ) ;
if ( ! V_44 )
goto V_46;
V_40 = V_47 ;
if ( V_9 -> V_27 & V_45 )
V_40 += V_47 ;
if ( V_9 -> V_27 & V_28 )
V_40 += V_47 ;
V_39 = V_41 + V_40 ;
if ( F_26 ( V_2 , V_39 ) ) {
V_9 = F_27 ( V_2 , V_39 , V_41 ) ;
if ( F_3 ( ! V_9 ) )
goto V_46;
}
if ( ( V_9 -> V_27 & V_28 ) && ! F_30 ( V_2 ) -> V_42 ) {
if ( F_31 ( V_2 ) )
goto V_46;
F_32 ( V_2 , V_48 , 0 ,
V_49 ) ;
}
V_42 = 0 ;
for ( V_38 = * V_36 ; V_38 ; V_38 = V_38 -> V_35 ) {
const struct V_8 * V_50 ;
if ( ! F_30 ( V_38 ) -> V_51 )
continue;
V_50 = (struct V_8 * ) ( V_38 -> V_52 + V_41 ) ;
if ( V_50 -> V_27 != V_9 -> V_27 ||
V_50 -> V_13 != V_9 -> V_13 ) {
F_30 ( V_38 ) -> V_51 = 0 ;
continue;
}
if ( V_9 -> V_27 & V_45 ) {
if ( * ( T_4 * ) ( V_50 + 1 ) != * ( T_4 * ) ( V_9 + 1 ) ) {
F_30 ( V_38 ) -> V_51 = 0 ;
continue;
}
}
}
F_33 ( V_2 , V_40 ) ;
F_34 ( V_2 , V_9 , V_40 ) ;
V_37 = V_44 -> V_53 . V_54 ( V_36 , V_2 ) ;
V_46:
F_35 () ;
V_25:
F_30 ( V_2 ) -> V_42 |= V_42 ;
return V_37 ;
}
static int F_36 ( struct V_1 * V_2 , int V_55 )
{
struct V_8 * V_9 = (struct V_8 * ) ( V_2 -> V_52 + V_55 ) ;
struct V_43 * V_44 ;
unsigned int V_40 = sizeof( * V_9 ) ;
int V_33 = - V_56 ;
T_3 type ;
V_2 -> V_26 = 1 ;
F_4 ( V_2 ) -> V_16 = V_22 ;
type = V_9 -> V_13 ;
if ( V_9 -> V_27 & V_45 )
V_40 += V_47 ;
if ( V_9 -> V_27 & V_28 )
V_40 += V_47 ;
F_28 () ;
V_44 = F_37 ( type ) ;
if ( V_44 )
V_33 = V_44 -> V_53 . V_57 ( V_2 , V_55 + V_40 ) ;
F_35 () ;
F_38 ( V_2 , V_55 + V_40 ) ;
return V_33 ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_58 , V_48 ) ;
}
