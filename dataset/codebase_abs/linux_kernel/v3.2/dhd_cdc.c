static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 ( V_4 -> V_6 . V_5 ) +
sizeof( struct V_7 ) ;
F_3 ( V_8 , L_1 ) ;
if ( V_5 > V_9 )
V_5 = V_9 ;
return F_4 ( V_2 -> V_10 , ( unsigned char * ) & V_4 -> V_6 ,
V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_5 )
{
int V_12 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_8 , L_1 ) ;
do {
V_12 = F_6 ( V_2 -> V_10 ,
( unsigned char * ) & V_4 -> V_6 ,
V_5 + sizeof( struct V_7 ) ) ;
if ( V_12 < 0 )
break;
} while ( F_7 ( F_2 ( V_4 -> V_6 . V_13 ) ) != V_11 );
return V_12 ;
}
int
F_8 ( struct V_1 * V_2 , int V_14 , T_2 V_15 ,
void * V_16 , T_2 V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_7 * V_6 = & V_4 -> V_6 ;
void * V_17 ;
int V_12 = 0 , V_18 = 0 ;
T_1 V_11 , V_13 ;
F_3 ( V_8 , L_1 ) ;
F_3 ( V_19 , L_2 , V_15 , V_5 ) ;
if ( V_15 == V_20 && V_16 ) {
if ( ! strcmp ( ( char * ) V_16 , L_3 ) ) {
strncpy ( ( char * ) V_16 , L_4 ,
V_21 ) ;
goto V_22;
} else if ( ! strcmp ( ( char * ) V_16 , L_5 ) ) {
* ( int * ) V_16 = V_2 -> V_23 ;
goto V_22;
}
}
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_15 = F_9 ( V_15 ) ;
V_6 -> V_5 = F_9 ( V_5 ) ;
V_13 = ( ++ V_4 -> V_24 << V_25 ) ;
V_13 = ( V_13 & ~ V_26 ) |
( V_14 << V_27 ) ;
V_6 -> V_13 = F_9 ( V_13 ) ;
if ( V_16 )
memcpy ( V_4 -> V_16 , V_16 , V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 ) {
F_3 ( ERROR , L_6 ,
V_12 ) ;
goto V_22;
}
V_28:
V_12 = F_5 ( V_2 , V_4 -> V_24 , V_5 ) ;
if ( V_12 < 0 )
goto V_22;
V_13 = F_2 ( V_6 -> V_13 ) ;
V_11 = ( V_13 & V_29 ) >> V_25 ;
if ( ( V_11 < V_4 -> V_24 ) && ( ++ V_18 < V_30 ) )
goto V_28;
if ( V_11 != V_4 -> V_24 ) {
F_3 ( ERROR , L_7 ,
F_10 ( V_2 , V_14 ) , V_11 , V_4 -> V_24 ) ;
V_12 = - V_31 ;
goto V_22;
}
V_17 = ( void * ) & V_6 [ 1 ] ;
if ( V_16 ) {
if ( V_12 < ( int ) V_5 )
V_5 = V_12 ;
memcpy ( V_16 , V_17 , V_5 ) ;
}
if ( V_13 & V_32 ) {
V_12 = F_2 ( V_6 -> V_33 ) ;
V_2 -> V_23 = V_12 ;
}
V_22:
return V_12 ;
}
int F_11 ( struct V_1 * V_2 , int V_14 , T_2 V_15 ,
void * V_16 , T_2 V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_7 * V_6 = & V_4 -> V_6 ;
int V_12 = 0 ;
T_1 V_13 , V_11 ;
F_3 ( V_8 , L_1 ) ;
F_3 ( V_19 , L_2 , V_15 , V_5 ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_15 = F_9 ( V_15 ) ;
V_6 -> V_5 = F_9 ( V_5 ) ;
V_13 = ( ++ V_4 -> V_24 << V_25 ) | V_34 ;
V_13 = ( V_13 & ~ V_26 ) |
( V_14 << V_27 ) ;
V_6 -> V_13 = F_9 ( V_13 ) ;
if ( V_16 )
memcpy ( V_4 -> V_16 , V_16 , V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
goto V_22;
V_12 = F_5 ( V_2 , V_4 -> V_24 , V_5 ) ;
if ( V_12 < 0 )
goto V_22;
V_13 = F_2 ( V_6 -> V_13 ) ;
V_11 = ( V_13 & V_29 ) >> V_25 ;
if ( V_11 != V_4 -> V_24 ) {
F_3 ( ERROR , L_7 ,
F_10 ( V_2 , V_14 ) , V_11 , V_4 -> V_24 ) ;
V_12 = - V_31 ;
goto V_22;
}
if ( V_13 & V_32 ) {
V_12 = F_2 ( V_6 -> V_33 ) ;
V_2 -> V_23 = V_12 ;
}
V_22:
return V_12 ;
}
int
F_12 ( struct V_1 * V_2 , int V_14 , struct V_35 * V_36 ,
int V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_12 = - 1 ;
if ( V_2 -> V_37 == V_38 ) {
F_3 ( ERROR , L_8 ) ;
return V_12 ;
}
F_13 ( V_2 ) ;
F_3 ( V_8 , L_1 ) ;
if ( V_5 > V_39 )
goto V_22;
if ( V_4 -> V_40 == true ) {
F_3 ( V_8 , L_9 ,
V_36 -> V_15 , ( unsigned long ) V_36 -> V_15 , V_4 -> V_41 ,
( unsigned long ) V_4 -> V_41 ) ;
if ( V_36 -> V_15 == V_42 ||
V_36 -> V_15 == V_20 )
F_3 ( V_8 , L_10 , ( char * ) V_36 -> V_16 ) ;
goto V_22;
}
V_4 -> V_40 = true ;
V_4 -> V_41 = V_36 -> V_15 ;
if ( V_36 -> V_43 )
V_12 = F_11 ( V_2 , V_14 , V_36 -> V_15 ,
V_36 -> V_16 , V_5 ) ;
else {
V_12 = F_8 ( V_2 , V_14 , V_36 -> V_15 ,
V_36 -> V_16 , V_5 ) ;
if ( V_12 > 0 )
V_36 -> V_44 = V_12 -
sizeof( struct V_7 ) ;
}
if ( V_12 >= 0 )
V_12 = 0 ;
else {
struct V_7 * V_6 = & V_4 -> V_6 ;
V_36 -> V_45 = F_2 ( V_6 -> V_5 ) ;
}
if ( ! V_12 && V_36 -> V_15 == V_42 &&
! strcmp ( V_36 -> V_16 , L_11 ) ) {
int V_46 ;
T_3 V_47 = 0 ;
V_46 = strlen ( L_11 ) + 1 ;
if ( V_5 >= ( int ) ( V_46 + sizeof( int ) ) )
memcpy ( & V_47 , ( char * ) V_36 -> V_16 + V_46 , sizeof( int ) ) ;
V_2 -> V_48 = ( V_49 ) F_2 ( V_47 ) ;
}
V_4 -> V_40 = false ;
V_22:
F_14 ( V_2 ) ;
return V_12 ;
}
static bool F_15 ( struct V_50 * V_51 )
{
return V_51 -> V_52 == V_53 ;
}
static void F_16 ( struct V_50 * V_51 , bool V_54 )
{
V_51 -> V_52 = ( V_54 ? V_55 : V_56 ) ;
}
void F_17 ( struct V_1 * V_2 , int V_14 ,
struct V_50 * V_57 )
{
struct V_58 * V_59 ;
F_3 ( V_8 , L_1 ) ;
F_18 ( V_57 , V_60 ) ;
V_59 = (struct V_58 * ) ( V_57 -> V_61 ) ;
V_59 -> V_13 = ( V_62 << V_63 ) ;
if ( F_15 ( V_57 ) )
V_59 -> V_13 |= V_64 ;
V_59 -> V_65 = ( V_57 -> V_65 & V_66 ) ;
V_59 -> V_67 = 0 ;
V_59 -> V_68 = 0 ;
F_19 ( V_59 , V_14 ) ;
}
int F_20 ( struct V_1 * V_2 , int * V_14 ,
struct V_50 * V_57 )
{
struct V_58 * V_59 ;
F_3 ( V_8 , L_1 ) ;
if ( V_57 -> V_5 < V_60 ) {
F_3 ( ERROR , L_12 ,
V_57 -> V_5 , V_60 ) ;
return - V_69 ;
}
V_59 = (struct V_58 * ) ( V_57 -> V_61 ) ;
* V_14 = F_21 ( V_59 ) ;
if ( * V_14 >= V_70 ) {
F_3 ( ERROR , L_13 , * V_14 ) ;
return - V_69 ;
}
if ( ( ( V_59 -> V_13 & V_71 ) >> V_63 ) !=
V_62 ) {
F_3 ( ERROR , L_14 ,
F_10 ( V_2 , * V_14 ) , V_59 -> V_13 ) ;
return - V_69 ;
}
if ( V_59 -> V_13 & V_72 ) {
F_3 ( V_73 , L_15 ,
F_10 ( V_2 , * V_14 ) , V_59 -> V_13 ) ;
F_16 ( V_57 , true ) ;
}
V_57 -> V_65 = V_59 -> V_65 & V_66 ;
F_22 ( V_57 , V_60 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_74 ;
V_74 = F_24 ( sizeof( struct V_3 ) , V_75 ) ;
if ( ! V_74 )
goto V_76;
if ( ( unsigned long ) ( & V_74 -> V_6 + 1 ) != ( unsigned long ) V_74 -> V_16 ) {
F_3 ( ERROR , L_16 ) ;
goto V_76;
}
V_2 -> V_4 = V_74 ;
V_2 -> V_77 += V_60 ;
V_2 -> V_78 = V_39 +
sizeof( struct V_7 ) + V_79 ;
return 0 ;
V_76:
F_25 ( V_74 ) ;
return - V_80 ;
}
void F_26 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_81 . V_82 = V_2 -> V_82 ;
V_2 -> V_81 . V_83 = V_2 -> V_83 ;
V_2 -> V_81 . V_84 = V_2 -> V_84 ;
V_2 -> V_81 . V_85 = V_2 -> V_85 ;
V_2 -> V_81 . V_86 = V_2 -> V_86 ;
V_2 -> V_81 . V_87 = V_2 -> V_88 ;
return;
}
int F_28 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
char V_16 [ 128 ] ;
F_3 ( V_8 , L_1 ) ;
F_13 ( V_2 ) ;
strcpy ( V_16 , L_17 ) ;
V_12 = F_8 ( V_2 , 0 , V_20 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_12 < 0 ) {
F_14 ( V_2 ) ;
return V_12 ;
}
memcpy ( V_2 -> V_89 , V_16 , V_90 ) ;
F_14 ( V_2 ) ;
V_12 = F_29 ( V_2 ) ;
V_2 -> V_91 = true ;
return V_12 ;
}
void F_30 ( struct V_1 * V_2 )
{
}
