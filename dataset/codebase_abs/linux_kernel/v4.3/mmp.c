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
int V_20 ;
if ( * V_12 )
F_20 ( * V_12 ) ;
if ( ! * V_12 ) {
* V_12 = F_21 ( V_2 , V_19 ) ;
if ( ! * V_12 ) {
V_20 = - V_21 ;
goto V_22;
}
}
F_13 ( * V_12 ) ;
F_12 ( * V_12 ) ;
( * V_12 ) -> V_14 = V_23 ;
F_14 ( V_24 | V_17 | V_18 , * V_12 ) ;
F_15 ( * V_12 ) ;
if ( ! F_18 ( * V_12 ) ) {
F_22 ( * V_12 ) ;
* V_12 = NULL ;
V_20 = - V_25 ;
goto V_22;
}
V_4 = (struct V_3 * ) ( ( * V_12 ) -> V_13 ) ;
if ( F_23 ( V_4 -> V_26 ) == V_27 &&
F_6 ( V_2 , V_4 ) )
return 0 ;
V_20 = - V_28 ;
V_22:
F_24 ( V_2 , L_1 ,
V_20 , V_19 ) ;
return V_20 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_29 , unsigned int line , const char * V_30 )
{
F_26 ( V_2 , V_29 , line , L_2 , V_30 ) ;
F_26 ( V_2 , V_29 , line ,
L_3
L_4 ,
( long long unsigned int ) F_27 ( V_4 -> V_31 ) ,
V_4 -> V_32 , V_4 -> V_33 ) ;
}
static int F_28 ( void * V_34 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 ) -> V_2 ;
struct V_11 * V_12 = ( (struct V_35 * ) V_34 ) -> V_12 ;
struct V_36 * V_37 = F_2 ( V_2 ) -> V_38 ;
struct V_3 * V_4 ;
T_3 V_19 ;
T_4 V_39 = 0 ;
unsigned long V_40 = 0 ;
int V_41 = F_29 ( V_37 -> V_42 ) ;
unsigned V_43 ;
unsigned long V_44 ;
unsigned long V_45 ;
int V_46 ;
V_19 = F_27 ( V_37 -> V_47 ) ;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
V_4 -> V_31 = F_30 ( F_31 () ) ;
V_43 = F_32 ( V_48 * V_41 ,
V_49 ) ;
V_4 -> V_43 = F_33 ( V_43 ) ;
F_34 ( V_12 -> V_50 , V_4 -> V_33 ) ;
memcpy ( V_4 -> V_32 , F_35 () -> V_51 ,
sizeof( V_4 -> V_32 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_39 > V_52 )
V_39 = 1 ;
V_4 -> V_53 = F_5 ( V_39 ) ;
V_4 -> V_31 = F_30 ( F_31 () ) ;
V_44 = V_54 ;
V_46 = F_9 ( V_2 , V_12 ) ;
if ( V_46 ) {
if ( ( V_40 % 60 ) == 0 )
F_37 ( V_2 , L_5 ) ;
V_40 ++ ;
}
if ( ! ( F_23 ( V_37 -> V_55 ) &
V_56 ) ) {
F_24 ( V_2 , L_6
L_7 ) ;
F_2 ( V_2 ) -> V_57 = NULL ;
goto V_58;
}
if ( V_2 -> V_59 & V_60 ) {
F_24 ( V_2 , L_8
L_9 ) ;
F_2 ( V_2 ) -> V_57 = NULL ;
goto V_58;
}
V_45 = V_54 - V_44 ;
if ( V_45 < V_41 * V_61 )
F_38 ( V_41 *
V_61 - V_45 ) ;
V_45 = V_54 - V_44 ;
if ( V_45 > V_43 * V_61 ) {
struct V_11 * V_62 = NULL ;
struct V_3 * V_63 ;
V_46 = F_19 ( V_2 , & V_62 , V_19 ) ;
if ( V_46 ) {
F_37 ( V_2 , L_10 ,
V_46 ) ;
F_2 ( V_2 ) -> V_57 = NULL ;
goto V_58;
}
V_63 = (struct V_3 * ) ( V_62 -> V_13 ) ;
if ( V_4 -> V_53 != V_63 -> V_53 ||
memcmp ( V_4 -> V_32 , V_63 -> V_32 ,
sizeof( V_4 -> V_32 ) ) ) {
F_39 ( V_2 , V_63 ,
L_11
L_12
L_13 ) ;
F_37 ( V_2 , L_14 ) ;
goto V_58;
}
F_40 ( V_62 ) ;
}
V_43 = F_32 ( F_41 ( V_48 * V_45 / V_61 ,
V_64 ) ,
V_49 ) ;
V_4 -> V_43 = F_33 ( V_43 ) ;
}
V_4 -> V_53 = F_5 ( V_65 ) ;
V_4 -> V_31 = F_30 ( F_31 () ) ;
V_46 = F_9 ( V_2 , V_12 ) ;
V_58:
F_42 ( V_34 ) ;
F_22 ( V_12 ) ;
return V_46 ;
}
static unsigned int F_43 ( void )
{
T_4 V_66 ;
do {
V_66 = F_44 () ;
} while ( V_66 > V_52 );
return V_66 ;
}
int F_45 ( struct V_1 * V_2 ,
T_3 V_19 )
{
struct V_36 * V_37 = F_2 ( V_2 ) -> V_38 ;
struct V_11 * V_12 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_35 * V_35 ;
T_4 V_39 ;
unsigned int V_43 = F_29 ( V_37 -> V_42 ) ;
unsigned int V_67 = 0 ;
int V_46 ;
if ( V_19 < F_23 ( V_37 -> V_68 ) ||
V_19 >= F_46 ( V_37 ) ) {
F_24 ( V_2 , L_15 ) ;
goto V_58;
}
V_46 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_46 )
goto V_58;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_43 < V_49 )
V_43 = V_49 ;
if ( F_29 ( V_4 -> V_43 ) > V_43 )
V_43 = F_29 ( V_4 -> V_43 ) ;
V_39 = F_23 ( V_4 -> V_53 ) ;
if ( V_39 == V_65 )
goto V_69;
if ( V_39 == V_70 ) {
F_39 ( V_2 , V_4 , L_16 ) ;
goto V_58;
}
V_67 = F_41 ( V_43 * 2 + 1 ,
V_43 + 60 ) ;
if ( V_67 > V_49 * 4 )
F_24 ( V_2 , L_17
L_18 , V_67 * 2 ) ;
if ( F_38 ( V_61 * V_67 ) != 0 ) {
F_24 ( V_2 , L_19 ) ;
goto V_58;
}
V_46 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_46 )
goto V_58;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_39 != F_23 ( V_4 -> V_53 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_58;
}
V_69:
V_39 = F_43 () ;
V_4 -> V_53 = F_5 ( V_39 ) ;
V_46 = F_9 ( V_2 , V_12 ) ;
if ( V_46 )
goto V_58;
if ( F_38 ( V_61 * V_67 ) != 0 ) {
F_24 ( V_2 , L_19 ) ;
goto V_58;
}
V_46 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_46 )
goto V_58;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_39 != F_23 ( V_4 -> V_53 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_58;
}
V_35 = F_47 ( sizeof( struct V_35 ) , V_71 ) ;
if ( ! V_35 ) {
F_24 ( V_2 , L_21 ) ;
goto V_58;
}
V_35 -> V_2 = V_2 ;
V_35 -> V_12 = V_12 ;
F_2 ( V_2 ) -> V_57 = F_48 ( F_28 , V_35 , L_22 ,
F_34 ( V_12 -> V_50 ,
V_4 -> V_33 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_57 ) ) {
F_2 ( V_2 ) -> V_57 = NULL ;
F_42 ( V_35 ) ;
F_24 ( V_2 , L_23 ,
V_2 -> V_72 ) ;
goto V_58;
}
return 0 ;
V_58:
F_22 ( V_12 ) ;
return 1 ;
}
