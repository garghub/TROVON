static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 ( V_4 -> V_6 . V_5 ) +
sizeof( struct V_7 ) ;
F_3 ( ( L_1 , V_8 ) ) ;
if ( V_5 > V_9 )
V_5 = V_9 ;
return F_4 ( V_2 -> V_10 , ( unsigned char * ) & V_4 -> V_6 ,
V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_5 )
{
int V_12 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( ( L_1 , V_8 ) ) ;
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
T_1 V_11 , V_13 = 0 ;
F_3 ( ( L_1 , V_8 ) ) ;
F_9 ( ( L_2 , V_8 , V_15 , V_5 ) ) ;
if ( V_15 == V_19 && V_16 ) {
if ( ! strcmp ( ( char * ) V_16 , L_3 ) ) {
strncpy ( ( char * ) V_16 , L_4 ,
V_20 ) ;
goto V_21;
} else if ( ! strcmp ( ( char * ) V_16 , L_5 ) ) {
* ( int * ) V_16 = V_2 -> V_22 ;
goto V_21;
}
}
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_15 = F_10 ( V_15 ) ;
V_6 -> V_5 = F_10 ( V_5 ) ;
V_6 -> V_13 = ( ++ V_4 -> V_23 << V_24 ) ;
F_11 ( V_6 , V_14 ) ;
V_6 -> V_13 = F_10 ( V_6 -> V_13 ) ;
if ( V_16 )
memcpy ( V_4 -> V_16 , V_16 , V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 ) {
F_12 ( ( L_6
L_7 , V_12 ) ) ;
goto V_21;
}
V_25:
V_12 = F_5 ( V_2 , V_4 -> V_23 , V_5 ) ;
if ( V_12 < 0 )
goto V_21;
V_13 = F_2 ( V_6 -> V_13 ) ;
V_11 = ( V_13 & V_26 ) >> V_24 ;
if ( ( V_11 < V_4 -> V_23 ) && ( ++ V_18 < V_27 ) )
goto V_25;
if ( V_11 != V_4 -> V_23 ) {
F_12 ( ( L_8 ,
F_13 ( V_2 , V_14 ) , V_8 , V_11 ,
V_4 -> V_23 ) ) ;
V_12 = - V_28 ;
goto V_21;
}
V_17 = ( void * ) & V_6 [ 1 ] ;
if ( V_16 ) {
if ( V_12 < ( int ) V_5 )
V_5 = V_12 ;
memcpy ( V_16 , V_17 , V_5 ) ;
}
if ( V_13 & V_29 ) {
V_12 = F_2 ( V_6 -> V_30 ) ;
V_2 -> V_22 = V_12 ;
}
V_21:
return V_12 ;
}
int F_14 ( struct V_1 * V_2 , int V_14 , T_2 V_15 ,
void * V_16 , T_2 V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_7 * V_6 = & V_4 -> V_6 ;
int V_12 = 0 ;
T_1 V_13 , V_11 ;
F_3 ( ( L_1 , V_8 ) ) ;
F_9 ( ( L_2 , V_8 , V_15 , V_5 ) ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_15 = F_10 ( V_15 ) ;
V_6 -> V_5 = F_10 ( V_5 ) ;
V_6 -> V_13 = ( ++ V_4 -> V_23 << V_24 ) | V_31 ;
F_11 ( V_6 , V_14 ) ;
V_6 -> V_13 = F_10 ( V_6 -> V_13 ) ;
if ( V_16 )
memcpy ( V_4 -> V_16 , V_16 , V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
goto V_21;
V_12 = F_5 ( V_2 , V_4 -> V_23 , V_5 ) ;
if ( V_12 < 0 )
goto V_21;
V_13 = F_2 ( V_6 -> V_13 ) ;
V_11 = ( V_13 & V_26 ) >> V_24 ;
if ( V_11 != V_4 -> V_23 ) {
F_12 ( ( L_8 ,
F_13 ( V_2 , V_14 ) , V_8 , V_11 ,
V_4 -> V_23 ) ) ;
V_12 = - V_28 ;
goto V_21;
}
if ( V_13 & V_29 ) {
V_12 = F_2 ( V_6 -> V_30 ) ;
V_2 -> V_22 = V_12 ;
}
V_21:
return V_12 ;
}
int
F_15 ( struct V_1 * V_2 , int V_14 , struct V_32 * V_33 ,
void * V_16 , int V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_12 = - 1 ;
if ( V_2 -> V_34 == V_35 ) {
F_12 ( ( L_9 ,
V_8 ) ) ;
return V_12 ;
}
F_16 ( V_2 ) ;
F_3 ( ( L_1 , V_8 ) ) ;
if ( V_5 > V_36 )
goto V_21;
if ( V_4 -> V_37 == true ) {
F_3 ( ( L_10
L_11 ,
V_33 -> V_15 , ( unsigned long ) V_33 -> V_15 , V_4 -> V_38 ,
( unsigned long ) V_4 -> V_38 ) ) ;
if ( ( V_33 -> V_15 == V_39 ) ||
( V_33 -> V_15 == V_19 ) )
F_3 ( ( L_12 , ( char * ) V_16 ) ) ;
goto V_21;
}
V_4 -> V_37 = true ;
V_4 -> V_38 = V_33 -> V_15 ;
if ( V_33 -> V_40 )
V_12 = F_14 ( V_2 , V_14 , V_33 -> V_15 ,
V_16 , V_5 ) ;
else {
V_12 = F_8 ( V_2 , V_14 , V_33 -> V_15 ,
V_16 , V_5 ) ;
if ( V_12 > 0 )
V_33 -> V_41 = V_12 - sizeof( struct V_7 ) ;
}
if ( V_12 >= 0 )
V_12 = 0 ;
else {
struct V_7 * V_6 = & V_4 -> V_6 ;
V_33 -> V_42 = F_2 ( V_6 -> V_5 ) ;
}
if ( ! V_12 && V_33 -> V_15 == V_39 &&
! strcmp ( V_16 , L_13 ) ) {
int V_43 , V_44 = 0 ;
V_43 = strlen ( L_13 ) + 1 ;
if ( V_5 >= ( int ) ( V_43 + sizeof( int ) ) )
memcpy ( & V_44 , ( char * ) V_16 + V_43 , sizeof( int ) ) ;
V_2 -> V_45 = ( V_46 ) F_2 ( V_44 ) ;
}
V_4 -> V_37 = false ;
V_21:
F_17 ( V_2 ) ;
return V_12 ;
}
void F_18 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
F_19 ( V_48 , L_14 , V_2 -> V_4 -> V_23 ) ;
}
void F_20 ( struct V_1 * V_2 , int V_14 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 ;
F_3 ( ( L_1 , V_8 ) ) ;
F_21 ( V_50 , V_53 ) ;
V_52 = (struct V_51 * ) ( V_50 -> V_54 ) ;
V_52 -> V_13 = ( V_55 << V_56 ) ;
if ( F_22 ( V_50 ) )
V_52 -> V_13 |= V_57 ;
V_52 -> V_58 = ( V_50 -> V_58 & V_59 ) ;
V_52 -> V_60 = 0 ;
V_52 -> V_61 = 0 ;
F_23 ( V_52 , V_14 ) ;
}
int F_24 ( struct V_1 * V_2 , int * V_14 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 ;
F_3 ( ( L_1 , V_8 ) ) ;
if ( V_50 -> V_5 < V_53 ) {
F_12 ( ( L_15 , V_8 ,
V_50 -> V_5 , V_53 ) ) ;
return - V_62 ;
}
V_52 = (struct V_51 * ) ( V_50 -> V_54 ) ;
* V_14 = F_25 ( V_52 ) ;
if ( * V_14 >= V_63 ) {
F_12 ( ( L_16 ,
V_8 , * V_14 ) ) ;
return - V_62 ;
}
if ( ( ( V_52 -> V_13 & V_64 ) >> V_56 ) !=
V_55 ) {
F_12 ( ( L_17 ,
F_13 ( V_2 , * V_14 ) , V_52 -> V_13 ) ) ;
return - V_62 ;
}
if ( V_52 -> V_13 & V_65 ) {
F_26 ( ( L_18
L_19 ,
F_13 ( V_2 , * V_14 ) , V_52 -> V_13 ) ) ;
F_27 ( V_50 , true ) ;
}
V_50 -> V_58 = V_52 -> V_58 & V_59 ;
F_28 ( V_50 , V_53 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_66 ;
V_66 = F_30 ( sizeof( struct V_3 ) , V_67 ) ;
if ( ! V_66 ) {
F_12 ( ( L_20 , V_8 ) ) ;
goto V_68;
}
if ( ( unsigned long ) ( & V_66 -> V_6 + 1 ) != ( unsigned long ) V_66 -> V_16 ) {
F_12 ( ( L_21 ) ) ;
goto V_68;
}
V_2 -> V_4 = V_66 ;
V_2 -> V_69 += V_53 ;
V_2 -> V_70 = V_36 +
sizeof( struct V_7 ) + V_71 ;
return 0 ;
V_68:
F_31 ( V_66 ) ;
return - V_72 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_31 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_33 ( struct V_1 * V_2 )
{
V_2 -> V_73 . V_74 = V_2 -> V_74 ;
V_2 -> V_73 . V_75 = V_2 -> V_75 ;
V_2 -> V_73 . V_76 = V_2 -> V_76 ;
V_2 -> V_73 . V_77 = V_2 -> V_77 ;
V_2 -> V_73 . V_78 = V_2 -> V_78 ;
V_2 -> V_73 . V_79 = V_2 -> V_80 ;
return;
}
int F_34 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
char V_16 [ 128 ] ;
F_3 ( ( L_1 , V_8 ) ) ;
F_16 ( V_2 ) ;
strcpy ( V_16 , L_22 ) ;
V_12 = F_8 ( V_2 , 0 , V_19 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_12 < 0 ) {
F_17 ( V_2 ) ;
return V_12 ;
}
memcpy ( V_2 -> V_81 , V_16 , V_82 ) ;
F_17 ( V_2 ) ;
V_12 = F_35 ( V_2 ) ;
V_2 -> V_83 = true ;
return V_12 ;
}
void F_36 ( struct V_1 * V_2 )
{
}
