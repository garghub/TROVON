static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = F_3 ( struct V_3 , V_8 ) ;
T_2 V_9 ;
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
F_14 ( V_17 | V_18 | V_19 , V_13 ) ;
F_15 ( V_13 ) ;
F_16 ( V_2 ) ;
if ( F_17 ( ! F_18 ( V_13 ) ) )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_12 * * V_13 ,
T_3 V_20 )
{
struct V_3 * V_4 ;
if ( * V_13 )
F_20 ( * V_13 ) ;
if ( ! * V_13 )
* V_13 = F_21 ( V_2 , V_20 ) ;
if ( ! * V_13 )
return - V_21 ;
if ( * V_13 ) {
F_13 ( * V_13 ) ;
F_12 ( * V_13 ) ;
( * V_13 ) -> V_15 = V_22 ;
F_14 ( V_23 | V_18 | V_19 , * V_13 ) ;
F_15 ( * V_13 ) ;
if ( ! F_18 ( * V_13 ) ) {
F_22 ( * V_13 ) ;
* V_13 = NULL ;
}
}
if ( F_17 ( ! * V_13 ) ) {
F_23 ( V_2 , L_1 ,
V_20 ) ;
return - V_24 ;
}
V_4 = (struct V_3 * ) ( ( * V_13 ) -> V_14 ) ;
if ( F_24 ( V_4 -> V_25 ) != V_26 ||
! F_6 ( V_2 , V_4 ) )
return - V_27 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_28 , unsigned int line , const char * V_29 )
{
F_26 ( V_2 , V_28 , line , V_29 ) ;
F_26 ( V_2 , V_28 , line ,
L_2
L_3 ,
( long long unsigned int ) F_27 ( V_4 -> V_30 ) ,
V_4 -> V_31 , V_4 -> V_32 ) ;
}
static int F_28 ( void * V_33 )
{
struct V_1 * V_2 = ( (struct V_34 * ) V_33 ) -> V_2 ;
struct V_12 * V_13 = ( (struct V_34 * ) V_33 ) -> V_13 ;
struct V_35 * V_36 = F_2 ( V_2 ) -> V_37 ;
struct V_3 * V_4 ;
T_3 V_20 ;
T_4 V_38 = 0 ;
unsigned long V_39 = 0 ;
int V_40 = F_29 ( V_36 -> V_41 ) ;
unsigned V_42 ;
unsigned long V_43 ;
unsigned long V_44 ;
int V_45 ;
V_20 = F_27 ( V_36 -> V_46 ) ;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
V_4 -> V_30 = F_30 ( F_31 () ) ;
V_42 = F_32 ( V_47 * V_40 ,
V_48 ) ;
V_4 -> V_42 = F_33 ( V_42 ) ;
F_34 ( V_13 -> V_49 , V_4 -> V_32 ) ;
memcpy ( V_4 -> V_31 , F_35 () -> V_50 ,
sizeof( V_4 -> V_31 ) ) ;
while ( ! F_36 () ) {
if ( ++ V_38 > V_51 )
V_38 = 1 ;
V_4 -> V_52 = F_5 ( V_38 ) ;
V_4 -> V_30 = F_30 ( F_31 () ) ;
V_43 = V_53 ;
V_45 = F_9 ( V_2 , V_13 ) ;
if ( V_45 ) {
if ( ( V_39 % 60 ) == 0 )
F_37 ( V_2 , L_4 ) ;
V_39 ++ ;
}
if ( ! ( F_24 ( V_36 -> V_54 ) &
V_55 ) ) {
F_23 ( V_2 , L_5
L_6 ) ;
F_2 ( V_2 ) -> V_56 = NULL ;
goto V_57;
}
if ( V_2 -> V_58 & V_59 ) {
F_23 ( V_2 , L_7
L_8 ) ;
F_2 ( V_2 ) -> V_56 = NULL ;
goto V_57;
}
V_44 = V_53 - V_43 ;
if ( V_44 < V_40 * V_60 )
F_38 ( V_40 *
V_60 - V_44 ) ;
V_44 = V_53 - V_43 ;
if ( V_44 > V_42 * V_60 ) {
struct V_12 * V_61 = NULL ;
struct V_3 * V_62 ;
V_45 = F_19 ( V_2 , & V_61 , V_20 ) ;
if ( V_45 ) {
F_37 ( V_2 , L_9 ,
V_45 ) ;
F_2 ( V_2 ) -> V_56 = NULL ;
goto V_57;
}
V_62 = (struct V_3 * ) ( V_61 -> V_14 ) ;
if ( V_4 -> V_52 != V_62 -> V_52 ||
memcmp ( V_4 -> V_31 , V_62 -> V_31 ,
sizeof( V_4 -> V_31 ) ) ) {
F_39 ( V_2 , V_62 ,
L_10
L_11
L_12 ) ;
F_37 ( V_2 , L_13 ) ;
goto V_57;
}
F_40 ( V_61 ) ;
}
V_42 = F_32 ( F_41 ( V_47 * V_44 / V_60 ,
V_63 ) ,
V_48 ) ;
V_4 -> V_42 = F_33 ( V_42 ) ;
}
V_4 -> V_52 = F_5 ( V_64 ) ;
V_4 -> V_30 = F_30 ( F_31 () ) ;
V_45 = F_9 ( V_2 , V_13 ) ;
V_57:
F_42 ( V_33 ) ;
F_22 ( V_13 ) ;
return V_45 ;
}
static unsigned int F_43 ( void )
{
T_4 V_65 ;
do {
F_44 ( & V_65 , sizeof( T_4 ) ) ;
} while ( V_65 > V_51 );
return V_65 ;
}
int F_45 ( struct V_1 * V_2 ,
T_3 V_20 )
{
struct V_35 * V_36 = F_2 ( V_2 ) -> V_37 ;
struct V_12 * V_13 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_34 * V_34 ;
T_4 V_38 ;
unsigned int V_42 = F_29 ( V_36 -> V_41 ) ;
unsigned int V_66 = 0 ;
int V_45 ;
if ( V_20 < F_24 ( V_36 -> V_67 ) ||
V_20 >= F_46 ( V_36 ) ) {
F_23 ( V_2 , L_14 ) ;
goto V_57;
}
V_45 = F_19 ( V_2 , & V_13 , V_20 ) ;
if ( V_45 )
goto V_57;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_42 < V_48 )
V_42 = V_48 ;
if ( F_29 ( V_4 -> V_42 ) > V_42 )
V_42 = F_29 ( V_4 -> V_42 ) ;
V_38 = F_24 ( V_4 -> V_52 ) ;
if ( V_38 == V_64 )
goto V_68;
if ( V_38 == V_69 ) {
F_39 ( V_2 , V_4 , L_15 ) ;
goto V_57;
}
V_66 = F_41 ( V_42 * 2 + 1 ,
V_42 + 60 ) ;
if ( V_66 > V_48 * 4 )
F_23 ( V_2 , L_16
L_17 , V_66 * 2 ) ;
if ( F_38 ( V_60 * V_66 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_57;
}
V_45 = F_19 ( V_2 , & V_13 , V_20 ) ;
if ( V_45 )
goto V_57;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_38 != F_24 ( V_4 -> V_52 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_57;
}
V_68:
V_38 = F_43 () ;
V_4 -> V_52 = F_5 ( V_38 ) ;
V_45 = F_9 ( V_2 , V_13 ) ;
if ( V_45 )
goto V_57;
if ( F_38 ( V_60 * V_66 ) != 0 ) {
F_23 ( V_2 , L_18 ) ;
goto V_57;
}
V_45 = F_19 ( V_2 , & V_13 , V_20 ) ;
if ( V_45 )
goto V_57;
V_4 = (struct V_3 * ) ( V_13 -> V_14 ) ;
if ( V_38 != F_24 ( V_4 -> V_52 ) ) {
F_39 ( V_2 , V_4 ,
L_19 ) ;
goto V_57;
}
V_34 = F_47 ( sizeof( struct V_34 ) , V_70 ) ;
if ( ! V_34 ) {
F_23 ( V_2 , L_20 ) ;
goto V_57;
}
V_34 -> V_2 = V_2 ;
V_34 -> V_13 = V_13 ;
F_2 ( V_2 ) -> V_56 = F_48 ( F_28 , V_34 , L_21 ,
F_34 ( V_13 -> V_49 ,
V_4 -> V_32 ) ) ;
if ( F_49 ( F_2 ( V_2 ) -> V_56 ) ) {
F_2 ( V_2 ) -> V_56 = NULL ;
F_42 ( V_34 ) ;
F_23 ( V_2 , L_22 ,
V_2 -> V_71 ) ;
goto V_57;
}
return 0 ;
V_57:
F_22 ( V_13 ) ;
return 1 ;
}
