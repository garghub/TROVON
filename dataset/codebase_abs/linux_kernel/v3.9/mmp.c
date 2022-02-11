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
if ( ! * V_13 )
return - V_19 ;
if ( * V_13 ) {
F_13 ( * V_13 ) ;
F_12 ( * V_13 ) ;
( * V_13 ) -> V_15 = V_20 ;
F_14 ( V_21 , * V_13 ) ;
F_15 ( * V_13 ) ;
if ( ! F_18 ( * V_13 ) ) {
F_22 ( * V_13 ) ;
* V_13 = NULL ;
}
}
if ( F_17 ( ! * V_13 ) ) {
F_23 ( V_2 , L_1 ,
V_18 ) ;
return - V_22 ;
}
V_4 = (struct V_3 * ) ( ( * V_13 ) -> V_14 ) ;
if ( F_24 ( V_4 -> V_23 ) != V_24 ||
! F_6 ( V_2 , V_4 ) )
return - V_25 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_26 , unsigned int line , const char * V_27 )
{
F_26 ( V_2 , V_26 , line , V_27 ) ;
F_26 ( V_2 , V_26 , line ,
L_2
L_3 ,
( long long unsigned int ) F_27 ( V_4 -> V_28 ) ,
V_4 -> V_29 , V_4 -> V_30 ) ;
}
static int F_28 ( void * V_31 )
{
struct V_1 * V_2 = ( (struct V_32 * ) V_31 ) -> V_2 ;
struct V_12 * V_13 = ( (struct V_32 * ) V_31 ) -> V_13 ;
struct V_33 * V_34 = F_2 ( V_2 ) -> V_35 ;
struct V_3 * V_4 ;
T_2 V_18 ;
T_3 V_36 = 0 ;
unsigned long V_37 = 0 ;
int V_38 = F_29 ( V_34 -> V_39 ) ;
unsigned V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
int V_43 ;
V_18 = F_27 ( V_34 -> V_44 ) ;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
V_4 -> V_28 = F_30 ( F_31 () ) ;
V_40 = F_32 ( V_45 * V_38 ,
V_46 ) ;
V_4 -> V_40 = F_33 ( V_40 ) ;
F_34 ( V_13 -> V_47 , V_4 -> V_30 ) ;
memcpy ( V_4 -> V_29 , F_35 () -> V_48 ,
sizeof( V_4 -> V_29 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_36 > V_49 )
V_36 = 1 ;
V_4 -> V_50 = F_5 ( V_36 ) ;
V_4 -> V_28 = F_30 ( F_31 () ) ;
V_41 = V_51 ;
V_43 = F_9 ( V_2 , V_13 ) ;
if ( V_43 ) {
if ( ( V_37 % 60 ) == 0 )
F_37 ( V_2 , L_4 ) ;
V_37 ++ ;
}
if ( ! ( F_24 ( V_34 -> V_52 ) &
V_53 ) ) {
F_23 ( V_2 , L_5
L_6 ) ;
F_2 ( V_2 ) -> V_54 = NULL ;
goto V_55;
}
if ( V_2 -> V_56 & V_57 ) {
F_23 ( V_2 , L_7
L_8 ) ;
F_2 ( V_2 ) -> V_54 = NULL ;
goto V_55;
}
V_42 = V_51 - V_41 ;
if ( V_42 < V_38 * V_58 )
F_38 ( V_38 *
V_58 - V_42 ) ;
V_42 = V_51 - V_41 ;
if ( V_42 > V_40 * V_58 ) {
struct V_12 * V_59 = NULL ;
struct V_3 * V_60 ;
V_43 = F_19 ( V_2 , & V_59 , V_18 ) ;
if ( V_43 ) {
F_37 ( V_2 , L_9 ,
V_43 ) ;
F_2 ( V_2 ) -> V_54 = NULL ;
goto V_55;
}
V_60 = (struct V_3 * ) ( V_59 -> V_14 ) ;
if ( V_4 -> V_50 != V_60 -> V_50 ||
memcmp ( V_4 -> V_29 , V_60 -> V_29 ,
sizeof( V_4 -> V_29 ) ) ) {
F_39 ( V_2 , V_60 ,
L_10
L_11
L_12 ) ;
F_37 ( V_2 , L_13 ) ;
goto V_55;
}
F_40 ( V_59 ) ;
}
V_40 = F_32 ( F_41 ( V_45 * V_42 / V_58 ,
V_61 ) ,
V_46 ) ;
V_4 -> V_40 = F_33 ( V_40 ) ;
}
V_4 -> V_50 = F_5 ( V_62 ) ;
V_4 -> V_28 = F_30 ( F_31 () ) ;
V_43 = F_9 ( V_2 , V_13 ) ;
V_55:
F_42 ( V_31 ) ;
F_22 ( V_13 ) ;
return V_43 ;
}
static unsigned int F_43 ( void )
{
T_3 V_63 ;
do {
F_44 ( & V_63 , sizeof( T_3 ) ) ;
} while ( V_63 > V_49 );
return V_63 ;
}
int F_45 ( struct V_1 * V_2 ,
T_2 V_18 )
{
struct V_33 * V_34 = F_2 ( V_2 ) -> V_35 ;
struct V_12 * V_13 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_32 * V_32 ;
T_3 V_36 ;
unsigned int V_40 = F_29 ( V_34 -> V_39 ) ;
unsigned int V_64 = 0 ;
int V_43 ;
if ( V_18 < F_24 ( V_34 -> V_65 ) ||
V_18 >= F_46 ( V_34 ) ) {
F_23 ( V_2 , L_14 ) ;
goto V_55;
}
V_43 = F_19 ( V_2 , & V_13 , V_18 ) ;
if ( V_43 )
goto V_55;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_40 < V_46 )
V_40 = V_46 ;
if ( F_29 ( V_4 -> V_40 ) > V_40 )
V_40 = F_29 ( V_4 -> V_40 ) ;
V_36 = F_24 ( V_4 -> V_50 ) ;
if ( V_36 == V_62 )
goto V_66;
if ( V_36 == V_67 ) {
F_39 ( V_2 , V_4 , L_15 ) ;
goto V_55;
}
V_64 = F_41 ( V_40 * 2 + 1 ,
V_40 + 60 ) ;
if ( V_64 > V_46 * 4 )
F_23 ( V_2 , L_16
L_17 , V_64 * 2 ) ;
if ( F_38 ( V_58 * V_64 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_55;
}
V_43 = F_19 ( V_2 , & V_13 , V_18 ) ;
if ( V_43 )
goto V_55;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_36 != F_24 ( V_4 -> V_50 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_55;
}
V_66:
V_36 = F_43 () ;
V_4 -> V_50 = F_5 ( V_36 ) ;
V_43 = F_9 ( V_2 , V_13 ) ;
if ( V_43 )
goto V_55;
if ( F_38 ( V_58 * V_64 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_55;
}
V_43 = F_19 ( V_2 , & V_13 , V_18 ) ;
if ( V_43 )
goto V_55;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_36 != F_24 ( V_4 -> V_50 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_55;
}
V_32 = F_47 ( sizeof( struct V_32 ) , V_68 ) ;
if ( ! V_32 ) {
F_23 ( V_2 , L_20 ) ;
goto V_55;
}
V_32 -> V_2 = V_2 ;
V_32 -> V_13 = V_13 ;
F_2 ( V_2 ) -> V_54 = F_48 ( F_28 , V_32 , L_21 ,
F_34 ( V_13 -> V_47 ,
V_4 -> V_30 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_54 ) ) {
F_2 ( V_2 ) -> V_54 = NULL ;
F_42 ( V_32 ) ;
F_23 ( V_2 , L_22 ,
V_2 -> V_69 ) ;
goto V_55;
}
return 0 ;
V_55:
F_22 ( V_13 ) ;
return 1 ;
}
