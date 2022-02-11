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
F_14 ( V_25 , V_18 | V_19 , * V_12 ) ;
F_15 ( * V_12 ) ;
if ( ! F_18 ( * V_12 ) ) {
V_21 = - V_26 ;
goto V_23;
}
V_4 = (struct V_3 * ) ( ( * V_12 ) -> V_13 ) ;
if ( F_22 ( V_4 -> V_27 ) != V_28 ) {
V_21 = - V_29 ;
goto V_23;
}
if ( ! F_6 ( V_2 , V_4 ) ) {
V_21 = - V_30 ;
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
const char * V_31 , unsigned int line , const char * V_32 )
{
F_26 ( V_2 , V_31 , line , L_2 , V_32 ) ;
F_26 ( V_2 , V_31 , line ,
L_3
L_4 ,
( long long unsigned int ) F_27 ( V_4 -> V_33 ) ,
V_4 -> V_34 , V_4 -> V_35 ) ;
}
static int F_28 ( void * V_36 )
{
struct V_1 * V_2 = ( (struct V_37 * ) V_36 ) -> V_2 ;
struct V_11 * V_12 = ( (struct V_37 * ) V_36 ) -> V_12 ;
struct V_38 * V_39 = F_2 ( V_2 ) -> V_40 ;
struct V_3 * V_4 ;
T_3 V_20 ;
T_4 V_41 = 0 ;
unsigned long V_42 = 0 ;
int V_43 = F_29 ( V_39 -> V_44 ) ;
unsigned V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
int V_48 ;
V_20 = F_27 ( V_39 -> V_49 ) ;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
V_4 -> V_33 = F_30 ( F_31 () ) ;
V_45 = F_32 ( V_50 * V_43 ,
V_51 ) ;
V_4 -> V_45 = F_33 ( V_45 ) ;
F_34 ( V_12 -> V_52 , V_4 -> V_35 ) ;
memcpy ( V_4 -> V_34 , F_35 () -> V_53 ,
sizeof( V_4 -> V_34 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_41 > V_54 )
V_41 = 1 ;
V_4 -> V_55 = F_5 ( V_41 ) ;
V_4 -> V_33 = F_30 ( F_31 () ) ;
V_46 = V_56 ;
V_48 = F_9 ( V_2 , V_12 ) ;
if ( V_48 ) {
if ( ( V_42 % 60 ) == 0 )
F_37 ( V_2 , L_5 ) ;
V_42 ++ ;
}
if ( ! ( F_22 ( V_39 -> V_57 ) &
V_58 ) ) {
F_24 ( V_2 , L_6
L_7 ) ;
goto V_59;
}
if ( V_2 -> V_60 & V_61 ) {
F_24 ( V_2 , L_8
L_9 ) ;
goto V_59;
}
V_47 = V_56 - V_46 ;
if ( V_47 < V_43 * V_62 )
F_38 ( V_43 *
V_62 - V_47 ) ;
V_47 = V_56 - V_46 ;
if ( V_47 > V_45 * V_62 ) {
struct V_11 * V_63 = NULL ;
struct V_3 * V_64 ;
V_48 = F_19 ( V_2 , & V_63 , V_20 ) ;
if ( V_48 ) {
F_37 ( V_2 , L_10 ,
V_48 ) ;
goto V_59;
}
V_64 = (struct V_3 * ) ( V_63 -> V_13 ) ;
if ( V_4 -> V_55 != V_64 -> V_55 ||
memcmp ( V_4 -> V_34 , V_64 -> V_34 ,
sizeof( V_4 -> V_34 ) ) ) {
F_39 ( V_2 , V_64 ,
L_11
L_12
L_13 ) ;
F_37 ( V_2 , L_14 ) ;
F_40 ( V_63 ) ;
V_48 = - V_65 ;
goto V_59;
}
F_40 ( V_63 ) ;
}
V_45 = F_32 ( F_41 ( V_50 * V_47 / V_62 ,
V_66 ) ,
V_51 ) ;
V_4 -> V_45 = F_33 ( V_45 ) ;
}
V_4 -> V_55 = F_5 ( V_67 ) ;
V_4 -> V_33 = F_30 ( F_31 () ) ;
V_48 = F_9 ( V_2 , V_12 ) ;
V_59:
F_2 ( V_2 ) -> V_68 = NULL ;
F_42 ( V_36 ) ;
F_23 ( V_12 ) ;
return V_48 ;
}
static unsigned int F_43 ( void )
{
T_4 V_69 ;
do {
V_69 = F_44 () ;
} while ( V_69 > V_54 );
return V_69 ;
}
int F_45 ( struct V_1 * V_2 ,
T_3 V_20 )
{
struct V_38 * V_39 = F_2 ( V_2 ) -> V_40 ;
struct V_11 * V_12 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_37 * V_37 ;
T_4 V_41 ;
unsigned int V_45 = F_29 ( V_39 -> V_44 ) ;
unsigned int V_70 = 0 ;
int V_48 ;
if ( V_20 < F_22 ( V_39 -> V_71 ) ||
V_20 >= F_46 ( V_39 ) ) {
F_24 ( V_2 , L_15 ) ;
goto V_72;
}
V_48 = F_19 ( V_2 , & V_12 , V_20 ) ;
if ( V_48 )
goto V_72;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_45 < V_51 )
V_45 = V_51 ;
if ( F_29 ( V_4 -> V_45 ) > V_45 )
V_45 = F_29 ( V_4 -> V_45 ) ;
V_41 = F_22 ( V_4 -> V_55 ) ;
if ( V_41 == V_67 )
goto V_73;
if ( V_41 == V_74 ) {
F_39 ( V_2 , V_4 , L_16 ) ;
goto V_72;
}
V_70 = F_41 ( V_45 * 2 + 1 ,
V_45 + 60 ) ;
if ( V_70 > V_51 * 4 )
F_24 ( V_2 , L_17
L_18 , V_70 * 2 ) ;
if ( F_38 ( V_62 * V_70 ) != 0 ) {
F_24 ( V_2 , L_19 ) ;
goto V_72;
}
V_48 = F_19 ( V_2 , & V_12 , V_20 ) ;
if ( V_48 )
goto V_72;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_41 != F_22 ( V_4 -> V_55 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_72;
}
V_73:
V_41 = F_43 () ;
V_4 -> V_55 = F_5 ( V_41 ) ;
V_48 = F_9 ( V_2 , V_12 ) ;
if ( V_48 )
goto V_72;
if ( F_38 ( V_62 * V_70 ) != 0 ) {
F_24 ( V_2 , L_21 ) ;
goto V_72;
}
V_48 = F_19 ( V_2 , & V_12 , V_20 ) ;
if ( V_48 )
goto V_72;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_41 != F_22 ( V_4 -> V_55 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_72;
}
V_37 = F_47 ( sizeof( struct V_37 ) , V_75 ) ;
if ( ! V_37 ) {
F_24 ( V_2 , L_22 ) ;
goto V_72;
}
V_37 -> V_2 = V_2 ;
V_37 -> V_12 = V_12 ;
F_2 ( V_2 ) -> V_68 = F_48 ( F_28 , V_37 , L_23 ,
F_34 ( V_12 -> V_52 ,
V_4 -> V_35 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_68 ) ) {
F_2 ( V_2 ) -> V_68 = NULL ;
F_42 ( V_37 ) ;
F_24 ( V_2 , L_24 ,
V_2 -> V_76 ) ;
goto V_72;
}
return 0 ;
V_72:
F_23 ( V_12 ) ;
return 1 ;
}
