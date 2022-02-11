static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( struct V_3 , V_8 ) ;
T_2 V_9 ;
V_9 = F_4 ( V_6 , V_6 -> V_10 , ( char * ) V_4 , V_7 ) ;
return F_5 ( V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_7 ( V_2 ) )
return 1 ;
return V_4 -> V_8 == F_1 ( V_2 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_7 ( V_2 ) )
return;
V_4 -> V_8 = F_1 ( V_2 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
F_10 ( V_2 ) ;
F_8 ( V_2 , V_4 ) ;
F_11 ( V_12 ) ;
F_12 ( V_12 ) ;
V_12 -> V_14 = V_15 ;
F_13 ( V_12 ) ;
F_14 ( V_16 | V_17 | V_18 , V_12 ) ;
F_15 ( V_12 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( ! F_18 ( V_12 ) ) )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_11 * * V_12 ,
T_3 V_19 )
{
struct V_3 * V_4 ;
if ( * V_12 )
F_20 ( * V_12 ) ;
if ( ! * V_12 )
* V_12 = F_21 ( V_2 , V_19 ) ;
if ( ! * V_12 )
return - V_20 ;
if ( * V_12 ) {
F_13 ( * V_12 ) ;
F_12 ( * V_12 ) ;
( * V_12 ) -> V_14 = V_21 ;
F_14 ( V_22 | V_17 | V_18 , * V_12 ) ;
F_15 ( * V_12 ) ;
if ( ! F_18 ( * V_12 ) ) {
F_22 ( * V_12 ) ;
* V_12 = NULL ;
}
}
if ( F_17 ( ! * V_12 ) ) {
F_23 ( V_2 , L_1 ,
V_19 ) ;
return - V_23 ;
}
V_4 = (struct V_3 * ) ( ( * V_12 ) -> V_13 ) ;
if ( F_24 ( V_4 -> V_24 ) != V_25 ||
! F_6 ( V_2 , V_4 ) )
return - V_26 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_27 , unsigned int line , const char * V_28 )
{
F_26 ( V_2 , V_27 , line , V_28 ) ;
F_26 ( V_2 , V_27 , line ,
L_2
L_3 ,
( long long unsigned int ) F_27 ( V_4 -> V_29 ) ,
V_4 -> V_30 , V_4 -> V_31 ) ;
}
static int F_28 ( void * V_32 )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_32 ) -> V_2 ;
struct V_11 * V_12 = ( (struct V_33 * ) V_32 ) -> V_12 ;
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
struct V_3 * V_4 ;
T_3 V_19 ;
T_4 V_37 = 0 ;
unsigned long V_38 = 0 ;
int V_39 = F_29 ( V_35 -> V_40 ) ;
unsigned V_41 ;
unsigned long V_42 ;
unsigned long V_43 ;
int V_44 ;
V_19 = F_27 ( V_35 -> V_45 ) ;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
V_4 -> V_29 = F_30 ( F_31 () ) ;
V_41 = F_32 ( V_46 * V_39 ,
V_47 ) ;
V_4 -> V_41 = F_33 ( V_41 ) ;
F_34 ( V_12 -> V_48 , V_4 -> V_31 ) ;
memcpy ( V_4 -> V_30 , F_35 () -> V_49 ,
sizeof( V_4 -> V_30 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_37 > V_50 )
V_37 = 1 ;
V_4 -> V_51 = F_5 ( V_37 ) ;
V_4 -> V_29 = F_30 ( F_31 () ) ;
V_42 = V_52 ;
V_44 = F_9 ( V_2 , V_12 ) ;
if ( V_44 ) {
if ( ( V_38 % 60 ) == 0 )
F_37 ( V_2 , L_4 ) ;
V_38 ++ ;
}
if ( ! ( F_24 ( V_35 -> V_53 ) &
V_54 ) ) {
F_23 ( V_2 , L_5
L_6 ) ;
F_2 ( V_2 ) -> V_55 = NULL ;
goto V_56;
}
if ( V_2 -> V_57 & V_58 ) {
F_23 ( V_2 , L_7
L_8 ) ;
F_2 ( V_2 ) -> V_55 = NULL ;
goto V_56;
}
V_43 = V_52 - V_42 ;
if ( V_43 < V_39 * V_59 )
F_38 ( V_39 *
V_59 - V_43 ) ;
V_43 = V_52 - V_42 ;
if ( V_43 > V_41 * V_59 ) {
struct V_11 * V_60 = NULL ;
struct V_3 * V_61 ;
V_44 = F_19 ( V_2 , & V_60 , V_19 ) ;
if ( V_44 ) {
F_37 ( V_2 , L_9 ,
V_44 ) ;
F_2 ( V_2 ) -> V_55 = NULL ;
goto V_56;
}
V_61 = (struct V_3 * ) ( V_60 -> V_13 ) ;
if ( V_4 -> V_51 != V_61 -> V_51 ||
memcmp ( V_4 -> V_30 , V_61 -> V_30 ,
sizeof( V_4 -> V_30 ) ) ) {
F_39 ( V_2 , V_61 ,
L_10
L_11
L_12 ) ;
F_37 ( V_2 , L_13 ) ;
goto V_56;
}
F_40 ( V_60 ) ;
}
V_41 = F_32 ( F_41 ( V_46 * V_43 / V_59 ,
V_62 ) ,
V_47 ) ;
V_4 -> V_41 = F_33 ( V_41 ) ;
}
V_4 -> V_51 = F_5 ( V_63 ) ;
V_4 -> V_29 = F_30 ( F_31 () ) ;
V_44 = F_9 ( V_2 , V_12 ) ;
V_56:
F_42 ( V_32 ) ;
F_22 ( V_12 ) ;
return V_44 ;
}
static unsigned int F_43 ( void )
{
T_4 V_64 ;
do {
V_64 = F_44 () ;
} while ( V_64 > V_50 );
return V_64 ;
}
int F_45 ( struct V_1 * V_2 ,
T_3 V_19 )
{
struct V_34 * V_35 = F_2 ( V_2 ) -> V_36 ;
struct V_11 * V_12 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_33 * V_33 ;
T_4 V_37 ;
unsigned int V_41 = F_29 ( V_35 -> V_40 ) ;
unsigned int V_65 = 0 ;
int V_44 ;
if ( V_19 < F_24 ( V_35 -> V_66 ) ||
V_19 >= F_46 ( V_35 ) ) {
F_23 ( V_2 , L_14 ) ;
goto V_56;
}
V_44 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_44 )
goto V_56;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_41 < V_47 )
V_41 = V_47 ;
if ( F_29 ( V_4 -> V_41 ) > V_41 )
V_41 = F_29 ( V_4 -> V_41 ) ;
V_37 = F_24 ( V_4 -> V_51 ) ;
if ( V_37 == V_63 )
goto V_67;
if ( V_37 == V_68 ) {
F_39 ( V_2 , V_4 , L_15 ) ;
goto V_56;
}
V_65 = F_41 ( V_41 * 2 + 1 ,
V_41 + 60 ) ;
if ( V_65 > V_47 * 4 )
F_23 ( V_2 , L_16
L_17 , V_65 * 2 ) ;
if ( F_38 ( V_59 * V_65 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_56;
}
V_44 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_44 )
goto V_56;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_37 != F_24 ( V_4 -> V_51 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_56;
}
V_67:
V_37 = F_43 () ;
V_4 -> V_51 = F_5 ( V_37 ) ;
V_44 = F_9 ( V_2 , V_12 ) ;
if ( V_44 )
goto V_56;
if ( F_38 ( V_59 * V_65 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_56;
}
V_44 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_44 )
goto V_56;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_37 != F_24 ( V_4 -> V_51 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_56;
}
V_33 = F_47 ( sizeof( struct V_33 ) , V_69 ) ;
if ( ! V_33 ) {
F_23 ( V_2 , L_20 ) ;
goto V_56;
}
V_33 -> V_2 = V_2 ;
V_33 -> V_12 = V_12 ;
F_2 ( V_2 ) -> V_55 = F_48 ( F_28 , V_33 , L_21 ,
F_34 ( V_12 -> V_48 ,
V_4 -> V_31 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_55 ) ) {
F_2 ( V_2 ) -> V_55 = NULL ;
F_42 ( V_33 ) ;
F_23 ( V_2 , L_22 ,
V_2 -> V_70 ) ;
goto V_56;
}
return 0 ;
V_56:
F_22 ( V_12 ) ;
return 1 ;
}
