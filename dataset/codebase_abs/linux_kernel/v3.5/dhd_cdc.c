static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 ( V_4 -> V_6 . V_5 ) +
sizeof( struct V_7 ) ;
F_3 ( V_8 , L_1 ) ;
if ( V_5 > V_9 )
V_5 = V_9 ;
return V_2 -> V_10 -> V_11 ( V_2 -> V_12 ,
( unsigned char * ) & V_4 -> V_6 ,
V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_5 )
{
int V_14 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_8 , L_1 ) ;
do {
V_14 = V_2 -> V_10 -> V_15 ( V_2 -> V_12 ,
( unsigned char * ) & V_4 -> V_6 ,
V_5 + sizeof( struct V_7 ) ) ;
if ( V_14 < 0 )
break;
} while ( F_5 ( F_2 ( V_4 -> V_6 . V_16 ) ) != V_13 );
return V_14 ;
}
int
F_6 ( struct V_1 * V_2 , int V_17 , T_2 V_18 ,
void * V_19 , T_2 V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_7 * V_6 = & V_4 -> V_6 ;
void * V_20 ;
int V_14 = 0 , V_21 = 0 ;
T_1 V_13 , V_16 ;
F_3 ( V_8 , L_1 ) ;
F_3 ( V_22 , L_2 , V_18 , V_5 ) ;
if ( V_18 == V_23 && V_19 ) {
if ( ! strcmp ( ( char * ) V_19 , L_3 ) ) {
strncpy ( ( char * ) V_19 , L_4 ,
V_24 ) ;
goto V_25;
} else if ( ! strcmp ( ( char * ) V_19 , L_5 ) ) {
* ( int * ) V_19 = V_2 -> V_26 ;
goto V_25;
}
}
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_18 = F_7 ( V_18 ) ;
V_6 -> V_5 = F_7 ( V_5 ) ;
V_16 = ( ++ V_4 -> V_27 << V_28 ) ;
V_16 = ( V_16 & ~ V_29 ) |
( V_17 << V_30 ) ;
V_6 -> V_16 = F_7 ( V_16 ) ;
if ( V_19 )
memcpy ( V_4 -> V_19 , V_19 , V_5 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 ) {
F_3 ( ERROR , L_6 ,
V_14 ) ;
goto V_25;
}
V_31:
V_14 = F_4 ( V_2 , V_4 -> V_27 , V_5 ) ;
if ( V_14 < 0 )
goto V_25;
V_16 = F_2 ( V_6 -> V_16 ) ;
V_13 = ( V_16 & V_32 ) >> V_28 ;
if ( ( V_13 < V_4 -> V_27 ) && ( ++ V_21 < V_33 ) )
goto V_31;
if ( V_13 != V_4 -> V_27 ) {
F_3 ( ERROR , L_7 ,
F_8 ( V_2 , V_17 ) , V_13 , V_4 -> V_27 ) ;
V_14 = - V_34 ;
goto V_25;
}
V_20 = ( void * ) & V_6 [ 1 ] ;
if ( V_19 ) {
if ( V_14 < ( int ) V_5 )
V_5 = V_14 ;
memcpy ( V_19 , V_20 , V_5 ) ;
}
if ( V_16 & V_35 ) {
V_14 = F_2 ( V_6 -> V_36 ) ;
V_2 -> V_26 = V_14 ;
}
V_25:
return V_14 ;
}
int F_9 ( struct V_1 * V_2 , int V_17 , T_2 V_18 ,
void * V_19 , T_2 V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_7 * V_6 = & V_4 -> V_6 ;
int V_14 = 0 ;
T_1 V_16 , V_13 ;
F_3 ( V_8 , L_1 ) ;
F_3 ( V_22 , L_2 , V_18 , V_5 ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_18 = F_7 ( V_18 ) ;
V_6 -> V_5 = F_7 ( V_5 ) ;
V_16 = ( ++ V_4 -> V_27 << V_28 ) | V_37 ;
V_16 = ( V_16 & ~ V_29 ) |
( V_17 << V_30 ) ;
V_6 -> V_16 = F_7 ( V_16 ) ;
if ( V_19 )
memcpy ( V_4 -> V_19 , V_19 , V_5 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 < 0 )
goto V_25;
V_14 = F_4 ( V_2 , V_4 -> V_27 , V_5 ) ;
if ( V_14 < 0 )
goto V_25;
V_16 = F_2 ( V_6 -> V_16 ) ;
V_13 = ( V_16 & V_32 ) >> V_28 ;
if ( V_13 != V_4 -> V_27 ) {
F_3 ( ERROR , L_7 ,
F_8 ( V_2 , V_17 ) , V_13 , V_4 -> V_27 ) ;
V_14 = - V_34 ;
goto V_25;
}
if ( V_16 & V_35 ) {
V_14 = F_2 ( V_6 -> V_36 ) ;
V_2 -> V_26 = V_14 ;
}
V_25:
return V_14 ;
}
int
F_10 ( struct V_1 * V_2 , int V_17 , struct V_38 * V_39 ,
int V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 = - 1 ;
if ( V_2 -> V_10 -> V_40 == V_41 ) {
F_3 ( ERROR , L_8 ) ;
return V_14 ;
}
F_11 ( & V_2 -> V_42 ) ;
F_3 ( V_8 , L_1 ) ;
if ( V_5 > V_43 )
goto V_25;
if ( V_4 -> V_44 == true ) {
F_3 ( V_8 , L_9 ,
V_39 -> V_18 , ( unsigned long ) V_39 -> V_18 , V_4 -> V_45 ,
( unsigned long ) V_4 -> V_45 ) ;
if ( V_39 -> V_18 == V_46 ||
V_39 -> V_18 == V_23 )
F_3 ( V_8 , L_10 , ( char * ) V_39 -> V_19 ) ;
goto V_25;
}
V_4 -> V_44 = true ;
V_4 -> V_45 = V_39 -> V_18 ;
if ( V_39 -> V_47 )
V_14 = F_9 ( V_2 , V_17 , V_39 -> V_18 ,
V_39 -> V_19 , V_5 ) ;
else {
V_14 = F_6 ( V_2 , V_17 , V_39 -> V_18 ,
V_39 -> V_19 , V_5 ) ;
if ( V_14 > 0 )
V_39 -> V_48 = V_14 -
sizeof( struct V_7 ) ;
}
if ( V_14 >= 0 )
V_14 = 0 ;
else {
struct V_7 * V_6 = & V_4 -> V_6 ;
V_39 -> V_49 = F_2 ( V_6 -> V_5 ) ;
}
if ( ! V_14 && V_39 -> V_18 == V_46 &&
! strcmp ( V_39 -> V_19 , L_11 ) ) {
int V_50 ;
T_3 V_51 = 0 ;
V_50 = strlen ( L_11 ) + 1 ;
if ( V_5 >= ( int ) ( V_50 + sizeof( int ) ) )
memcpy ( & V_51 , ( char * ) V_39 -> V_19 + V_50 , sizeof( int ) ) ;
V_2 -> V_52 = ( V_53 ) F_2 ( V_51 ) ;
}
V_4 -> V_44 = false ;
V_25:
F_12 ( & V_2 -> V_42 ) ;
return V_14 ;
}
static bool F_13 ( struct V_54 * V_55 )
{
return V_55 -> V_56 == V_57 ;
}
static void F_14 ( struct V_54 * V_55 , bool V_58 )
{
V_55 -> V_56 = ( V_58 ? V_59 : V_60 ) ;
}
void F_15 ( struct V_1 * V_2 , int V_17 ,
struct V_54 * V_61 )
{
struct V_62 * V_63 ;
F_3 ( V_8 , L_1 ) ;
F_16 ( V_61 , V_64 ) ;
V_63 = (struct V_62 * ) ( V_61 -> V_65 ) ;
V_63 -> V_16 = ( V_66 << V_67 ) ;
if ( F_13 ( V_61 ) )
V_63 -> V_16 |= V_68 ;
V_63 -> V_69 = ( V_61 -> V_69 & V_70 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_72 = 0 ;
F_17 ( V_63 , V_17 ) ;
}
int F_18 ( struct V_73 * V_12 , int * V_17 ,
struct V_54 * V_61 )
{
struct V_62 * V_63 ;
struct V_74 * V_10 = F_19 ( V_12 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_3 ( V_8 , L_1 ) ;
if ( V_61 -> V_5 < V_64 ) {
F_3 ( ERROR , L_12 ,
V_61 -> V_5 , V_64 ) ;
return - V_75 ;
}
V_63 = (struct V_62 * ) ( V_61 -> V_65 ) ;
* V_17 = F_20 ( V_63 ) ;
if ( * V_17 >= V_76 ) {
F_3 ( ERROR , L_13 , * V_17 ) ;
return - V_75 ;
}
if ( ( ( V_63 -> V_16 & V_77 ) >> V_67 ) !=
V_66 ) {
F_3 ( ERROR , L_14 ,
F_8 ( V_2 , * V_17 ) , V_63 -> V_16 ) ;
return - V_75 ;
}
if ( V_63 -> V_16 & V_78 ) {
F_3 ( V_79 , L_15 ,
F_8 ( V_2 , * V_17 ) , V_63 -> V_16 ) ;
F_14 ( V_61 , true ) ;
}
V_61 -> V_69 = V_63 -> V_69 & V_70 ;
F_21 ( V_61 , V_64 ) ;
F_21 ( V_61 , V_63 -> V_72 << 2 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_80 ;
V_80 = F_23 ( sizeof( struct V_3 ) , V_81 ) ;
if ( ! V_80 )
goto V_82;
if ( ( unsigned long ) ( & V_80 -> V_6 + 1 ) != ( unsigned long ) V_80 -> V_19 ) {
F_3 ( ERROR , L_16 ) ;
goto V_82;
}
V_2 -> V_4 = V_80 ;
V_2 -> V_83 += V_64 ;
V_2 -> V_10 -> V_84 = V_43 +
sizeof( struct V_7 ) + V_85 ;
return 0 ;
V_82:
F_24 ( V_80 ) ;
return - V_86 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
char V_19 [ 128 ] ;
F_3 ( V_8 , L_1 ) ;
F_11 ( & V_2 -> V_42 ) ;
strcpy ( V_19 , L_17 ) ;
V_14 = F_6 ( V_2 , 0 , V_23 ,
V_19 , sizeof( V_19 ) ) ;
if ( V_14 < 0 ) {
F_12 ( & V_2 -> V_42 ) ;
return V_14 ;
}
memcpy ( V_2 -> V_87 , V_19 , V_88 ) ;
F_12 ( & V_2 -> V_42 ) ;
V_14 = F_27 ( V_2 ) ;
V_2 -> V_89 = true ;
return V_14 ;
}
void F_28 ( struct V_1 * V_2 )
{
}
