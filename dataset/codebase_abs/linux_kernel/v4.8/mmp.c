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
F_14 ( V_16 , V_17 | V_18 | V_19 , V_12 ) ;
F_15 ( V_12 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( ! F_18 ( V_12 ) ) )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_11 * * V_12 ,
T_3 V_20 )
{
struct V_3 * V_4 ;
int V_21 ;
if ( * V_12 )
F_20 ( * V_12 ) ;
if ( ! * V_12 ) {
* V_12 = F_21 ( V_2 , V_20 ) ;
if ( ! * V_12 ) {
V_21 = - V_22 ;
goto V_23;
}
}
F_13 ( * V_12 ) ;
F_12 ( * V_12 ) ;
( * V_12 ) -> V_14 = V_24 ;
F_14 ( V_25 , V_26 | V_18 | V_19 , * V_12 ) ;
F_15 ( * V_12 ) ;
if ( ! F_18 ( * V_12 ) ) {
V_21 = - V_27 ;
goto V_23;
}
V_4 = (struct V_3 * ) ( ( * V_12 ) -> V_13 ) ;
if ( F_22 ( V_4 -> V_28 ) != V_29 ) {
V_21 = - V_30 ;
goto V_23;
}
if ( ! F_6 ( V_2 , V_4 ) ) {
V_21 = - V_31 ;
goto V_23;
}
return 0 ;
V_23:
F_23 ( * V_12 ) ;
* V_12 = NULL ;
F_24 ( V_2 , L_1 ,
V_21 , V_20 ) ;
return V_21 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_32 , unsigned int line , const char * V_33 )
{
F_26 ( V_2 , V_32 , line , L_2 , V_33 ) ;
F_26 ( V_2 , V_32 , line ,
L_3
L_4 ,
( long long unsigned int ) F_27 ( V_4 -> V_34 ) ,
V_4 -> V_35 , V_4 -> V_36 ) ;
}
static int F_28 ( void * V_37 )
{
struct V_1 * V_2 = ( (struct V_38 * ) V_37 ) -> V_2 ;
struct V_11 * V_12 = ( (struct V_38 * ) V_37 ) -> V_12 ;
struct V_39 * V_40 = F_2 ( V_2 ) -> V_41 ;
struct V_3 * V_4 ;
T_3 V_20 ;
T_4 V_42 = 0 ;
unsigned long V_43 = 0 ;
int V_44 = F_29 ( V_40 -> V_45 ) ;
unsigned V_46 ;
unsigned long V_47 ;
unsigned long V_48 ;
int V_49 ;
V_20 = F_27 ( V_40 -> V_50 ) ;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
V_4 -> V_34 = F_30 ( F_31 () ) ;
V_46 = F_32 ( V_51 * V_44 ,
V_52 ) ;
V_4 -> V_46 = F_33 ( V_46 ) ;
F_34 ( V_12 -> V_53 , V_4 -> V_36 ) ;
memcpy ( V_4 -> V_35 , F_35 () -> V_54 ,
sizeof( V_4 -> V_35 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_42 > V_55 )
V_42 = 1 ;
V_4 -> V_56 = F_5 ( V_42 ) ;
V_4 -> V_34 = F_30 ( F_31 () ) ;
V_47 = V_57 ;
V_49 = F_9 ( V_2 , V_12 ) ;
if ( V_49 ) {
if ( ( V_43 % 60 ) == 0 )
F_37 ( V_2 , L_5 ) ;
V_43 ++ ;
}
if ( ! ( F_22 ( V_40 -> V_58 ) &
V_59 ) ) {
F_24 ( V_2 , L_6
L_7 ) ;
goto V_60;
}
if ( V_2 -> V_61 & V_62 ) {
F_24 ( V_2 , L_8
L_9 ) ;
goto V_60;
}
V_48 = V_57 - V_47 ;
if ( V_48 < V_44 * V_63 )
F_38 ( V_44 *
V_63 - V_48 ) ;
V_48 = V_57 - V_47 ;
if ( V_48 > V_46 * V_63 ) {
struct V_11 * V_64 = NULL ;
struct V_3 * V_65 ;
V_49 = F_19 ( V_2 , & V_64 , V_20 ) ;
if ( V_49 ) {
F_37 ( V_2 , L_10 ,
V_49 ) ;
goto V_60;
}
V_65 = (struct V_3 * ) ( V_64 -> V_13 ) ;
if ( V_4 -> V_56 != V_65 -> V_56 ||
memcmp ( V_4 -> V_35 , V_65 -> V_35 ,
sizeof( V_4 -> V_35 ) ) ) {
F_39 ( V_2 , V_65 ,
L_11
L_12
L_13 ) ;
F_37 ( V_2 , L_14 ) ;
F_40 ( V_64 ) ;
V_49 = - V_66 ;
goto V_60;
}
F_40 ( V_64 ) ;
}
V_46 = F_32 ( F_41 ( V_51 * V_48 / V_63 ,
V_67 ) ,
V_52 ) ;
V_4 -> V_46 = F_33 ( V_46 ) ;
}
V_4 -> V_56 = F_5 ( V_68 ) ;
V_4 -> V_34 = F_30 ( F_31 () ) ;
V_49 = F_9 ( V_2 , V_12 ) ;
V_60:
F_2 ( V_2 ) -> V_69 = NULL ;
F_42 ( V_37 ) ;
F_23 ( V_12 ) ;
return V_49 ;
}
static unsigned int F_43 ( void )
{
T_4 V_70 ;
do {
V_70 = F_44 () ;
} while ( V_70 > V_55 );
return V_70 ;
}
int F_45 ( struct V_1 * V_2 ,
T_3 V_20 )
{
struct V_39 * V_40 = F_2 ( V_2 ) -> V_41 ;
struct V_11 * V_12 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_38 * V_38 ;
T_4 V_42 ;
unsigned int V_46 = F_29 ( V_40 -> V_45 ) ;
unsigned int V_71 = 0 ;
int V_49 ;
if ( V_20 < F_22 ( V_40 -> V_72 ) ||
V_20 >= F_46 ( V_40 ) ) {
F_24 ( V_2 , L_15 ) ;
goto V_73;
}
V_49 = F_19 ( V_2 , & V_12 , V_20 ) ;
if ( V_49 )
goto V_73;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_46 < V_52 )
V_46 = V_52 ;
if ( F_29 ( V_4 -> V_46 ) > V_46 )
V_46 = F_29 ( V_4 -> V_46 ) ;
V_42 = F_22 ( V_4 -> V_56 ) ;
if ( V_42 == V_68 )
goto V_74;
if ( V_42 == V_75 ) {
F_39 ( V_2 , V_4 , L_16 ) ;
goto V_73;
}
V_71 = F_41 ( V_46 * 2 + 1 ,
V_46 + 60 ) ;
if ( V_71 > V_52 * 4 )
F_24 ( V_2 , L_17
L_18 , V_71 * 2 ) ;
if ( F_38 ( V_63 * V_71 ) != 0 ) {
F_24 ( V_2 , L_19 ) ;
goto V_73;
}
V_49 = F_19 ( V_2 , & V_12 , V_20 ) ;
if ( V_49 )
goto V_73;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_42 != F_22 ( V_4 -> V_56 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_73;
}
V_74:
V_42 = F_43 () ;
V_4 -> V_56 = F_5 ( V_42 ) ;
V_49 = F_9 ( V_2 , V_12 ) ;
if ( V_49 )
goto V_73;
if ( F_38 ( V_63 * V_71 ) != 0 ) {
F_24 ( V_2 , L_21 ) ;
goto V_73;
}
V_49 = F_19 ( V_2 , & V_12 , V_20 ) ;
if ( V_49 )
goto V_73;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_42 != F_22 ( V_4 -> V_56 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_73;
}
V_38 = F_47 ( sizeof( struct V_38 ) , V_76 ) ;
if ( ! V_38 ) {
F_24 ( V_2 , L_22 ) ;
goto V_73;
}
V_38 -> V_2 = V_2 ;
V_38 -> V_12 = V_12 ;
F_2 ( V_2 ) -> V_69 = F_48 ( F_28 , V_38 , L_23 ,
F_34 ( V_12 -> V_53 ,
V_4 -> V_36 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_69 ) ) {
F_2 ( V_2 ) -> V_69 = NULL ;
F_42 ( V_38 ) ;
F_24 ( V_2 , L_24 ,
V_2 -> V_77 ) ;
goto V_73;
}
return 0 ;
V_73:
F_23 ( V_12 ) ;
return 1 ;
}
