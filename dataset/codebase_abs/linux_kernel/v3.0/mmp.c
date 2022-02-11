static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
V_2 -> V_3 = V_4 ;
F_4 ( V_2 ) ;
F_5 ( V_5 , V_2 ) ;
F_6 ( V_2 ) ;
if ( F_7 ( ! F_8 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 , struct V_1 * * V_2 ,
T_1 V_8 )
{
struct V_9 * V_10 ;
if ( * V_2 )
F_10 ( * V_2 ) ;
if ( ! * V_2 )
* V_2 = F_11 ( V_7 , V_8 ) ;
if ( * V_2 ) {
F_4 ( * V_2 ) ;
F_3 ( * V_2 ) ;
( * V_2 ) -> V_3 = V_11 ;
F_5 ( V_12 , * V_2 ) ;
F_6 ( * V_2 ) ;
if ( ! F_8 ( * V_2 ) ) {
F_12 ( * V_2 ) ;
* V_2 = NULL ;
}
}
if ( ! * V_2 ) {
F_13 ( V_7 , L_1 ,
V_8 ) ;
return - V_13 ;
}
V_10 = (struct V_9 * ) ( ( * V_2 ) -> V_14 ) ;
if ( F_14 ( V_10 -> V_15 ) != V_16 )
return - V_17 ;
return 0 ;
}
void F_15 ( struct V_6 * V_7 , struct V_9 * V_10 ,
const char * V_18 , unsigned int line , const char * V_19 )
{
F_16 ( V_7 , V_18 , line , V_19 ) ;
F_16 ( V_7 , V_18 , line ,
L_2
L_3 ,
( long long unsigned int ) F_17 ( V_10 -> V_20 ) ,
V_10 -> V_21 , V_10 -> V_22 ) ;
}
static int F_18 ( void * V_23 )
{
struct V_6 * V_7 = ( (struct V_24 * ) V_23 ) -> V_7 ;
struct V_1 * V_2 = ( (struct V_24 * ) V_23 ) -> V_2 ;
struct V_25 * V_26 = F_19 ( V_7 ) -> V_27 ;
struct V_9 * V_10 ;
T_1 V_8 ;
T_2 V_28 = 0 ;
unsigned long V_29 = 0 ;
int V_30 = F_20 ( V_26 -> V_31 ) ;
unsigned V_32 ;
unsigned long V_33 ;
unsigned long V_34 ;
int V_35 ;
V_8 = F_17 ( V_26 -> V_36 ) ;
V_10 = (struct V_9 * ) ( V_2 -> V_14 ) ;
V_10 -> V_20 = F_21 ( F_22 () ) ;
V_32 = F_23 ( V_37 * V_30 ,
V_38 ) ;
V_10 -> V_32 = F_24 ( V_32 ) ;
F_25 ( V_2 -> V_39 , V_10 -> V_22 ) ;
memcpy ( V_10 -> V_21 , F_26 () -> V_40 ,
sizeof( V_10 -> V_21 ) ) ;
while ( ! F_27 () ) {
if ( ++ V_28 > V_41 )
V_28 = 1 ;
V_10 -> V_42 = F_28 ( V_28 ) ;
V_10 -> V_20 = F_21 ( F_22 () ) ;
V_33 = V_43 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 && ( V_29 % 60 ) == 0 ) {
F_29 ( V_7 , L_4 ) ;
V_29 ++ ;
}
if ( ! ( F_14 ( V_26 -> V_44 ) &
V_45 ) ) {
F_13 ( V_7 , L_5
L_6 ) ;
F_19 ( V_7 ) -> V_46 = NULL ;
goto V_47;
}
if ( V_7 -> V_48 & V_49 ) {
F_13 ( V_7 , L_7
L_8 ) ;
F_19 ( V_7 ) -> V_46 = NULL ;
goto V_47;
}
V_34 = V_43 - V_33 ;
if ( V_34 < V_30 * V_50 )
F_30 ( V_30 *
V_50 - V_34 ) ;
V_34 = V_43 - V_33 ;
if ( V_34 > V_32 * V_50 ) {
struct V_1 * V_51 = NULL ;
struct V_9 * V_52 ;
V_35 = F_9 ( V_7 , & V_51 , V_8 ) ;
if ( V_35 ) {
F_29 ( V_7 , L_9 ,
V_35 ) ;
F_19 ( V_7 ) -> V_46 = NULL ;
goto V_47;
}
V_52 = (struct V_9 * ) ( V_51 -> V_14 ) ;
if ( V_10 -> V_42 != V_52 -> V_42 ||
memcmp ( V_10 -> V_21 , V_52 -> V_21 ,
sizeof( V_10 -> V_21 ) ) ) {
F_31 ( V_7 , V_52 ,
L_10
L_11
L_12 ) ;
F_29 ( V_7 , L_13 ) ;
goto V_47;
}
F_32 ( V_51 ) ;
}
V_32 = F_23 ( F_33 ( V_37 * V_34 / V_50 ,
V_53 ) ,
V_38 ) ;
V_10 -> V_32 = F_24 ( V_32 ) ;
}
V_10 -> V_42 = F_28 ( V_54 ) ;
V_10 -> V_20 = F_21 ( F_22 () ) ;
V_35 = F_1 ( V_2 ) ;
V_47:
F_34 ( V_23 ) ;
F_12 ( V_2 ) ;
return V_35 ;
}
static unsigned int F_35 ( void )
{
T_2 V_55 ;
do {
F_36 ( & V_55 , sizeof( T_2 ) ) ;
} while ( V_55 > V_41 );
return V_55 ;
}
int F_37 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_25 * V_26 = F_19 ( V_7 ) -> V_27 ;
struct V_1 * V_2 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_24 * V_24 ;
T_2 V_28 ;
unsigned int V_32 = F_20 ( V_26 -> V_31 ) ;
unsigned int V_56 = 0 ;
int V_35 ;
if ( V_8 < F_14 ( V_26 -> V_57 ) ||
V_8 >= F_38 ( V_26 ) ) {
F_13 ( V_7 , L_14 ) ;
goto V_47;
}
V_35 = F_9 ( V_7 , & V_2 , V_8 ) ;
if ( V_35 )
goto V_47;
V_10 = (struct V_9 * ) ( V_2 -> V_14 ) ;
if ( V_32 < V_38 )
V_32 = V_38 ;
if ( V_10 -> V_32 > V_32 )
V_32 = V_10 -> V_32 ;
V_28 = F_14 ( V_10 -> V_42 ) ;
if ( V_28 == V_54 )
goto V_58;
if ( V_28 == V_59 ) {
F_31 ( V_7 , V_10 , L_15 ) ;
goto V_47;
}
V_56 = F_33 ( V_32 * 2 + 1 ,
V_32 + 60 ) ;
if ( V_56 > V_38 * 4 )
F_13 ( V_7 , L_16
L_17 , V_56 * 2 ) ;
if ( F_30 ( V_50 * V_56 ) != 0 ) {
F_13 ( V_7 , L_18 ) ;
goto V_47;
}
V_35 = F_9 ( V_7 , & V_2 , V_8 ) ;
if ( V_35 )
goto V_47;
V_10 = (struct V_9 * ) ( V_2 -> V_14 ) ;
if ( V_28 != F_14 ( V_10 -> V_42 ) ) {
F_31 ( V_7 , V_10 ,
L_19 ) ;
goto V_47;
}
V_58:
V_10 -> V_42 = V_28 = F_28 ( F_35 () ) ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 )
goto V_47;
if ( F_30 ( V_50 * V_56 ) != 0 ) {
F_13 ( V_7 , L_18 ) ;
goto V_47;
}
V_35 = F_9 ( V_7 , & V_2 , V_8 ) ;
if ( V_35 )
goto V_47;
V_10 = (struct V_9 * ) ( V_2 -> V_14 ) ;
if ( V_28 != F_14 ( V_10 -> V_42 ) ) {
F_31 ( V_7 , V_10 ,
L_19 ) ;
goto V_47;
}
V_24 = F_39 ( sizeof( struct V_24 ) , V_60 ) ;
if ( ! V_24 ) {
F_13 ( V_7 , L_20 ) ;
goto V_47;
}
V_24 -> V_7 = V_7 ;
V_24 -> V_2 = V_2 ;
F_19 ( V_7 ) -> V_46 = F_40 ( F_18 , V_24 , L_21 ,
F_25 ( V_2 -> V_39 ,
V_10 -> V_22 ) ) ;
if ( F_41 ( F_19 ( V_7 ) -> V_46 ) ) {
F_19 ( V_7 ) -> V_46 = NULL ;
F_34 ( V_24 ) ;
F_13 ( V_7 , L_22 ,
V_7 -> V_61 ) ;
goto V_47;
}
return 0 ;
V_47:
F_12 ( V_2 ) ;
return 1 ;
}
