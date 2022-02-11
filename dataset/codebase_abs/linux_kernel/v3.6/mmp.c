static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( struct V_3 , V_8 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_6 , V_6 -> V_10 , ( char * ) V_4 , V_7 ) ;
return F_5 ( V_9 ) ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_7 ( V_2 ,
V_11 ) )
return 1 ;
return V_4 -> V_8 == F_1 ( V_2 , V_4 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_7 ( V_2 ,
V_11 ) )
return;
V_4 -> V_8 = F_1 ( V_2 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
F_10 ( V_2 ) ;
F_8 ( V_2 , V_4 ) ;
F_11 ( V_13 ) ;
F_12 ( V_13 ) ;
V_13 -> V_15 = V_16 ;
F_13 ( V_13 ) ;
F_14 ( V_17 , V_13 ) ;
F_15 ( V_13 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( ! F_18 ( V_13 ) ) )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_12 * * V_13 ,
T_2 V_18 )
{
struct V_3 * V_4 ;
if ( * V_13 )
F_20 ( * V_13 ) ;
if ( ! * V_13 )
* V_13 = F_21 ( V_2 , V_18 ) ;
if ( * V_13 ) {
F_13 ( * V_13 ) ;
F_12 ( * V_13 ) ;
( * V_13 ) -> V_15 = V_19 ;
F_14 ( V_20 , * V_13 ) ;
F_15 ( * V_13 ) ;
if ( ! F_18 ( * V_13 ) ) {
F_22 ( * V_13 ) ;
* V_13 = NULL ;
}
}
if ( ! * V_13 ) {
F_23 ( V_2 , L_1 ,
V_18 ) ;
return - V_21 ;
}
V_4 = (struct V_3 * ) ( ( * V_13 ) -> V_14 ) ;
if ( F_24 ( V_4 -> V_22 ) != V_23 ||
! F_6 ( V_2 , V_4 ) )
return - V_24 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_25 , unsigned int line , const char * V_26 )
{
F_26 ( V_2 , V_25 , line , V_26 ) ;
F_26 ( V_2 , V_25 , line ,
L_2
L_3 ,
( long long unsigned int ) F_27 ( V_4 -> V_27 ) ,
V_4 -> V_28 , V_4 -> V_29 ) ;
}
static int F_28 ( void * V_30 )
{
struct V_1 * V_2 = ( (struct V_31 * ) V_30 ) -> V_2 ;
struct V_12 * V_13 = ( (struct V_31 * ) V_30 ) -> V_13 ;
struct V_32 * V_33 = F_2 ( V_2 ) -> V_34 ;
struct V_3 * V_4 ;
T_2 V_18 ;
T_3 V_35 = 0 ;
unsigned long V_36 = 0 ;
int V_37 = F_29 ( V_33 -> V_38 ) ;
unsigned V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
int V_42 ;
V_18 = F_27 ( V_33 -> V_43 ) ;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
V_4 -> V_27 = F_30 ( F_31 () ) ;
V_39 = F_32 ( V_44 * V_37 ,
V_45 ) ;
V_4 -> V_39 = F_33 ( V_39 ) ;
F_34 ( V_13 -> V_46 , V_4 -> V_29 ) ;
memcpy ( V_4 -> V_28 , F_35 () -> V_47 ,
sizeof( V_4 -> V_28 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_35 > V_48 )
V_35 = 1 ;
V_4 -> V_49 = F_5 ( V_35 ) ;
V_4 -> V_27 = F_30 ( F_31 () ) ;
V_40 = V_50 ;
V_42 = F_9 ( V_2 , V_13 ) ;
if ( V_42 ) {
if ( ( V_36 % 60 ) == 0 )
F_37 ( V_2 , L_4 ) ;
V_36 ++ ;
}
if ( ! ( F_24 ( V_33 -> V_51 ) &
V_52 ) ) {
F_23 ( V_2 , L_5
L_6 ) ;
F_2 ( V_2 ) -> V_53 = NULL ;
goto V_54;
}
if ( V_2 -> V_55 & V_56 ) {
F_23 ( V_2 , L_7
L_8 ) ;
F_2 ( V_2 ) -> V_53 = NULL ;
goto V_54;
}
V_41 = V_50 - V_40 ;
if ( V_41 < V_37 * V_57 )
F_38 ( V_37 *
V_57 - V_41 ) ;
V_41 = V_50 - V_40 ;
if ( V_41 > V_39 * V_57 ) {
struct V_12 * V_58 = NULL ;
struct V_3 * V_59 ;
V_42 = F_19 ( V_2 , & V_58 , V_18 ) ;
if ( V_42 ) {
F_37 ( V_2 , L_9 ,
V_42 ) ;
F_2 ( V_2 ) -> V_53 = NULL ;
goto V_54;
}
V_59 = (struct V_3 * ) ( V_58 -> V_14 ) ;
if ( V_4 -> V_49 != V_59 -> V_49 ||
memcmp ( V_4 -> V_28 , V_59 -> V_28 ,
sizeof( V_4 -> V_28 ) ) ) {
F_39 ( V_2 , V_59 ,
L_10
L_11
L_12 ) ;
F_37 ( V_2 , L_13 ) ;
goto V_54;
}
F_40 ( V_58 ) ;
}
V_39 = F_32 ( F_41 ( V_44 * V_41 / V_57 ,
V_60 ) ,
V_45 ) ;
V_4 -> V_39 = F_33 ( V_39 ) ;
}
V_4 -> V_49 = F_5 ( V_61 ) ;
V_4 -> V_27 = F_30 ( F_31 () ) ;
V_42 = F_9 ( V_2 , V_13 ) ;
V_54:
F_42 ( V_30 ) ;
F_22 ( V_13 ) ;
return V_42 ;
}
static unsigned int F_43 ( void )
{
T_3 V_62 ;
do {
F_44 ( & V_62 , sizeof( T_3 ) ) ;
} while ( V_62 > V_48 );
return V_62 ;
}
int F_45 ( struct V_1 * V_2 ,
T_2 V_18 )
{
struct V_32 * V_33 = F_2 ( V_2 ) -> V_34 ;
struct V_12 * V_13 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_31 * V_31 ;
T_3 V_35 ;
unsigned int V_39 = F_29 ( V_33 -> V_38 ) ;
unsigned int V_63 = 0 ;
int V_42 ;
if ( V_18 < F_24 ( V_33 -> V_64 ) ||
V_18 >= F_46 ( V_33 ) ) {
F_23 ( V_2 , L_14 ) ;
goto V_54;
}
V_42 = F_19 ( V_2 , & V_13 , V_18 ) ;
if ( V_42 )
goto V_54;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_39 < V_45 )
V_39 = V_45 ;
if ( F_29 ( V_4 -> V_39 ) > V_39 )
V_39 = F_29 ( V_4 -> V_39 ) ;
V_35 = F_24 ( V_4 -> V_49 ) ;
if ( V_35 == V_61 )
goto V_65;
if ( V_35 == V_66 ) {
F_39 ( V_2 , V_4 , L_15 ) ;
goto V_54;
}
V_63 = F_41 ( V_39 * 2 + 1 ,
V_39 + 60 ) ;
if ( V_63 > V_45 * 4 )
F_23 ( V_2 , L_16
L_17 , V_63 * 2 ) ;
if ( F_38 ( V_57 * V_63 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_54;
}
V_42 = F_19 ( V_2 , & V_13 , V_18 ) ;
if ( V_42 )
goto V_54;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_35 != F_24 ( V_4 -> V_49 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_54;
}
V_65:
V_35 = F_43 () ;
V_4 -> V_49 = F_5 ( V_35 ) ;
V_42 = F_9 ( V_2 , V_13 ) ;
if ( V_42 )
goto V_54;
if ( F_38 ( V_57 * V_63 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_54;
}
V_42 = F_19 ( V_2 , & V_13 , V_18 ) ;
if ( V_42 )
goto V_54;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_35 != F_24 ( V_4 -> V_49 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_54;
}
V_31 = F_47 ( sizeof( struct V_31 ) , V_67 ) ;
if ( ! V_31 ) {
F_23 ( V_2 , L_20 ) ;
goto V_54;
}
V_31 -> V_2 = V_2 ;
V_31 -> V_13 = V_13 ;
F_2 ( V_2 ) -> V_53 = F_48 ( F_28 , V_31 , L_21 ,
F_34 ( V_13 -> V_46 ,
V_4 -> V_29 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_53 ) ) {
F_2 ( V_2 ) -> V_53 = NULL ;
F_42 ( V_31 ) ;
F_23 ( V_2 , L_22 ,
V_2 -> V_68 ) ;
goto V_54;
}
return 0 ;
V_54:
F_22 ( V_13 ) ;
return 1 ;
}
