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
V_20 = - V_25 ;
goto V_22;
}
V_4 = (struct V_3 * ) ( ( * V_12 ) -> V_13 ) ;
if ( F_22 ( V_4 -> V_26 ) != V_27 ) {
V_20 = - V_28 ;
goto V_22;
}
if ( ! F_6 ( V_2 , V_4 ) ) {
V_20 = - V_29 ;
goto V_22;
}
return 0 ;
V_22:
F_23 ( * V_12 ) ;
* V_12 = NULL ;
F_24 ( V_2 , L_1 ,
V_20 , V_19 ) ;
return V_20 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_30 , unsigned int line , const char * V_31 )
{
F_26 ( V_2 , V_30 , line , L_2 , V_31 ) ;
F_26 ( V_2 , V_30 , line ,
L_3
L_4 ,
( long long unsigned int ) F_27 ( V_4 -> V_32 ) ,
V_4 -> V_33 , V_4 -> V_34 ) ;
}
static int F_28 ( void * V_35 )
{
struct V_1 * V_2 = ( (struct V_36 * ) V_35 ) -> V_2 ;
struct V_11 * V_12 = ( (struct V_36 * ) V_35 ) -> V_12 ;
struct V_37 * V_38 = F_2 ( V_2 ) -> V_39 ;
struct V_3 * V_4 ;
T_3 V_19 ;
T_4 V_40 = 0 ;
unsigned long V_41 = 0 ;
int V_42 = F_29 ( V_38 -> V_43 ) ;
unsigned V_44 ;
unsigned long V_45 ;
unsigned long V_46 ;
int V_47 ;
V_19 = F_27 ( V_38 -> V_48 ) ;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
V_4 -> V_32 = F_30 ( F_31 () ) ;
V_44 = F_32 ( V_49 * V_42 ,
V_50 ) ;
V_4 -> V_44 = F_33 ( V_44 ) ;
F_34 ( V_12 -> V_51 , V_4 -> V_34 ) ;
memcpy ( V_4 -> V_33 , F_35 () -> V_52 ,
sizeof( V_4 -> V_33 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_40 > V_53 )
V_40 = 1 ;
V_4 -> V_54 = F_5 ( V_40 ) ;
V_4 -> V_32 = F_30 ( F_31 () ) ;
V_45 = V_55 ;
V_47 = F_9 ( V_2 , V_12 ) ;
if ( V_47 ) {
if ( ( V_41 % 60 ) == 0 )
F_37 ( V_2 , L_5 ) ;
V_41 ++ ;
}
if ( ! ( F_22 ( V_38 -> V_56 ) &
V_57 ) ) {
F_24 ( V_2 , L_6
L_7 ) ;
goto V_58;
}
if ( V_2 -> V_59 & V_60 ) {
F_24 ( V_2 , L_8
L_9 ) ;
goto V_58;
}
V_46 = V_55 - V_45 ;
if ( V_46 < V_42 * V_61 )
F_38 ( V_42 *
V_61 - V_46 ) ;
V_46 = V_55 - V_45 ;
if ( V_46 > V_44 * V_61 ) {
struct V_11 * V_62 = NULL ;
struct V_3 * V_63 ;
V_47 = F_19 ( V_2 , & V_62 , V_19 ) ;
if ( V_47 ) {
F_37 ( V_2 , L_10 ,
V_47 ) ;
goto V_58;
}
V_63 = (struct V_3 * ) ( V_62 -> V_13 ) ;
if ( V_4 -> V_54 != V_63 -> V_54 ||
memcmp ( V_4 -> V_33 , V_63 -> V_33 ,
sizeof( V_4 -> V_33 ) ) ) {
F_39 ( V_2 , V_63 ,
L_11
L_12
L_13 ) ;
F_37 ( V_2 , L_14 ) ;
F_40 ( V_62 ) ;
V_47 = - V_64 ;
goto V_58;
}
F_40 ( V_62 ) ;
}
V_44 = F_32 ( F_41 ( V_49 * V_46 / V_61 ,
V_65 ) ,
V_50 ) ;
V_4 -> V_44 = F_33 ( V_44 ) ;
}
V_4 -> V_54 = F_5 ( V_66 ) ;
V_4 -> V_32 = F_30 ( F_31 () ) ;
V_47 = F_9 ( V_2 , V_12 ) ;
V_58:
F_2 ( V_2 ) -> V_67 = NULL ;
F_42 ( V_35 ) ;
F_23 ( V_12 ) ;
return V_47 ;
}
static unsigned int F_43 ( void )
{
T_4 V_68 ;
do {
V_68 = F_44 () ;
} while ( V_68 > V_53 );
return V_68 ;
}
int F_45 ( struct V_1 * V_2 ,
T_3 V_19 )
{
struct V_37 * V_38 = F_2 ( V_2 ) -> V_39 ;
struct V_11 * V_12 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_36 * V_36 ;
T_4 V_40 ;
unsigned int V_44 = F_29 ( V_38 -> V_43 ) ;
unsigned int V_69 = 0 ;
int V_47 ;
if ( V_19 < F_22 ( V_38 -> V_70 ) ||
V_19 >= F_46 ( V_38 ) ) {
F_24 ( V_2 , L_15 ) ;
goto V_71;
}
V_47 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_47 )
goto V_71;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_44 < V_50 )
V_44 = V_50 ;
if ( F_29 ( V_4 -> V_44 ) > V_44 )
V_44 = F_29 ( V_4 -> V_44 ) ;
V_40 = F_22 ( V_4 -> V_54 ) ;
if ( V_40 == V_66 )
goto V_72;
if ( V_40 == V_73 ) {
F_39 ( V_2 , V_4 , L_16 ) ;
goto V_71;
}
V_69 = F_41 ( V_44 * 2 + 1 ,
V_44 + 60 ) ;
if ( V_69 > V_50 * 4 )
F_24 ( V_2 , L_17
L_18 , V_69 * 2 ) ;
if ( F_38 ( V_61 * V_69 ) != 0 ) {
F_24 ( V_2 , L_19 ) ;
goto V_71;
}
V_47 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_47 )
goto V_71;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_40 != F_22 ( V_4 -> V_54 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_71;
}
V_72:
V_40 = F_43 () ;
V_4 -> V_54 = F_5 ( V_40 ) ;
V_47 = F_9 ( V_2 , V_12 ) ;
if ( V_47 )
goto V_71;
if ( F_38 ( V_61 * V_69 ) != 0 ) {
F_24 ( V_2 , L_21 ) ;
goto V_71;
}
V_47 = F_19 ( V_2 , & V_12 , V_19 ) ;
if ( V_47 )
goto V_71;
V_4 = (struct V_3 * ) ( V_12 -> V_13 ) ;
if ( V_40 != F_22 ( V_4 -> V_54 ) ) {
F_39 ( V_2 , V_4 ,
L_20 ) ;
goto V_71;
}
V_36 = F_47 ( sizeof( struct V_36 ) , V_74 ) ;
if ( ! V_36 ) {
F_24 ( V_2 , L_22 ) ;
goto V_71;
}
V_36 -> V_2 = V_2 ;
V_36 -> V_12 = V_12 ;
F_2 ( V_2 ) -> V_67 = F_48 ( F_28 , V_36 , L_23 ,
F_34 ( V_12 -> V_51 ,
V_4 -> V_34 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_67 ) ) {
F_2 ( V_2 ) -> V_67 = NULL ;
F_42 ( V_36 ) ;
F_24 ( V_2 , L_24 ,
V_2 -> V_75 ) ;
goto V_71;
}
return 0 ;
V_71:
F_23 ( V_12 ) ;
return 1 ;
}
