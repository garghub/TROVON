static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
int V_3 = F_2 ( V_2 -> V_4 . V_3 ) + sizeof( V_5 ) ;
F_3 ( ( L_1 , V_6 ) ) ;
if ( V_3 > V_7 )
V_3 = V_7 ;
return F_4 ( V_1 -> V_8 , ( unsigned char * ) & V_2 -> V_4 , V_3 ) ;
}
static int F_5 ( T_1 * V_1 , T_3 V_9 , T_3 V_3 )
{
int V_10 ;
T_2 * V_2 = V_1 -> V_2 ;
F_3 ( ( L_1 , V_6 ) ) ;
do {
V_10 =
F_6 ( V_1 -> V_8 , ( unsigned char * ) & V_2 -> V_4 ,
V_3 + sizeof( V_5 ) ) ;
if ( V_10 < 0 )
break;
} while ( F_7 ( F_2 ( V_2 -> V_4 . V_11 ) ) != V_9 );
return V_10 ;
}
int
F_8 ( T_1 * V_1 , int V_12 , T_4 V_13 , void * V_14 , T_4 V_3 )
{
T_2 * V_2 = V_1 -> V_2 ;
V_5 * V_4 = & V_2 -> V_4 ;
void * V_15 ;
int V_10 = 0 , V_16 = 0 ;
T_3 V_9 , V_11 = 0 ;
F_3 ( ( L_1 , V_6 ) ) ;
F_9 ( ( L_2 , V_6 , V_13 , V_3 ) ) ;
if ( V_13 == V_17 && V_14 ) {
if ( ! strcmp ( ( char * ) V_14 , L_3 ) ) {
strncpy ( ( char * ) V_14 , L_4 ,
V_18 ) ;
goto V_19;
} else if ( ! strcmp ( ( char * ) V_14 , L_5 ) ) {
* ( int * ) V_14 = V_1 -> V_20 ;
goto V_19;
}
}
memset ( V_4 , 0 , sizeof( V_5 ) ) ;
V_4 -> V_13 = F_10 ( V_13 ) ;
V_4 -> V_3 = F_10 ( V_3 ) ;
V_4 -> V_11 = ( ++ V_2 -> V_21 << V_22 ) ;
F_11 ( V_4 , V_12 ) ;
V_4 -> V_11 = F_10 ( V_4 -> V_11 ) ;
if ( V_14 )
memcpy ( V_2 -> V_14 , V_14 , V_3 ) ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 ) {
F_12 ( ( L_6
L_7 , V_10 ) ) ;
goto V_19;
}
V_23:
V_10 = F_5 ( V_1 , V_2 -> V_21 , V_3 ) ;
if ( V_10 < 0 )
goto V_19;
V_11 = F_2 ( V_4 -> V_11 ) ;
V_9 = ( V_11 & V_24 ) >> V_22 ;
if ( ( V_9 < V_2 -> V_21 ) && ( ++ V_16 < V_25 ) )
goto V_23;
if ( V_9 != V_2 -> V_21 ) {
F_12 ( ( L_8 ,
F_13 ( V_1 , V_12 ) , V_6 , V_9 , V_2 -> V_21 ) ) ;
V_10 = - V_26 ;
goto V_19;
}
V_15 = ( void * ) & V_4 [ 1 ] ;
if ( V_14 ) {
if ( V_10 < ( int ) V_3 )
V_3 = V_10 ;
memcpy ( V_14 , V_15 , V_3 ) ;
}
if ( V_11 & V_27 ) {
V_10 = F_2 ( V_4 -> V_28 ) ;
V_1 -> V_20 = V_10 ;
}
V_19:
return V_10 ;
}
int F_14 ( T_1 * V_1 , int V_12 , T_4 V_13 , void * V_14 , T_4 V_3 )
{
T_2 * V_2 = V_1 -> V_2 ;
V_5 * V_4 = & V_2 -> V_4 ;
int V_10 = 0 ;
T_3 V_11 , V_9 ;
F_3 ( ( L_1 , V_6 ) ) ;
F_9 ( ( L_2 , V_6 , V_13 , V_3 ) ) ;
memset ( V_4 , 0 , sizeof( V_5 ) ) ;
V_4 -> V_13 = F_10 ( V_13 ) ;
V_4 -> V_3 = F_10 ( V_3 ) ;
V_4 -> V_11 = ( ++ V_2 -> V_21 << V_22 ) | V_29 ;
F_11 ( V_4 , V_12 ) ;
V_4 -> V_11 = F_10 ( V_4 -> V_11 ) ;
if ( V_14 )
memcpy ( V_2 -> V_14 , V_14 , V_3 ) ;
V_10 = F_1 ( V_1 ) ;
if ( V_10 < 0 )
goto V_19;
V_10 = F_5 ( V_1 , V_2 -> V_21 , V_3 ) ;
if ( V_10 < 0 )
goto V_19;
V_11 = F_2 ( V_4 -> V_11 ) ;
V_9 = ( V_11 & V_24 ) >> V_22 ;
if ( V_9 != V_2 -> V_21 ) {
F_12 ( ( L_8 ,
F_13 ( V_1 , V_12 ) , V_6 , V_9 , V_2 -> V_21 ) ) ;
V_10 = - V_26 ;
goto V_19;
}
if ( V_11 & V_27 ) {
V_10 = F_2 ( V_4 -> V_28 ) ;
V_1 -> V_20 = V_10 ;
}
V_19:
return V_10 ;
}
int
F_15 ( T_1 * V_1 , int V_12 , T_5 * V_30 , void * V_14 , int V_3 )
{
T_2 * V_2 = V_1 -> V_2 ;
int V_10 = - 1 ;
if ( V_1 -> V_31 == V_32 ) {
F_12 ( ( L_9 ,
V_6 ) ) ;
return V_10 ;
}
F_16 ( V_1 ) ;
F_3 ( ( L_1 , V_6 ) ) ;
ASSERT ( V_3 <= V_33 ) ;
if ( V_3 > V_33 )
goto V_19;
if ( V_2 -> V_34 == true ) {
F_3 ( ( L_10
L_11 ,
V_30 -> V_13 , ( unsigned long ) V_30 -> V_13 , V_2 -> V_35 ,
( unsigned long ) V_2 -> V_35 ) ) ;
if ( ( V_30 -> V_13 == V_36 ) || ( V_30 -> V_13 == V_17 ) )
F_3 ( ( L_12 , ( char * ) V_14 ) ) ;
goto V_19;
}
V_2 -> V_34 = true ;
V_2 -> V_35 = V_30 -> V_13 ;
if ( V_30 -> V_37 )
V_10 = F_14 ( V_1 , V_12 , V_30 -> V_13 , V_14 , V_3 ) ;
else {
V_10 = F_8 ( V_1 , V_12 , V_30 -> V_13 , V_14 , V_3 ) ;
if ( V_10 > 0 )
V_30 -> V_38 = V_10 - sizeof( V_5 ) ;
}
if ( V_10 >= 0 )
V_10 = 0 ;
else {
V_5 * V_4 = & V_2 -> V_4 ;
V_30 -> V_39 = F_2 ( V_4 -> V_3 ) ;
}
if ( ( ! V_10 ) && ( V_30 -> V_13 == V_36 ) && ( ! strcmp ( V_14 , L_13 ) ) ) {
int V_40 , V_41 = 0 ;
V_40 = strlen ( L_13 ) + 1 ;
if ( V_3 >= ( int ) ( V_40 + sizeof( int ) ) )
memcpy ( & V_41 , ( char * ) V_14 + V_40 , sizeof( int ) ) ;
V_1 -> V_42 = ( V_43 ) F_2 ( V_41 ) ;
}
V_2 -> V_34 = false ;
V_19:
F_17 ( V_1 ) ;
return V_10 ;
}
int
F_18 ( T_1 * V_44 , const char * V_45 ,
void * V_46 , int V_47 , void * V_48 , int V_3 , bool V_37 )
{
return - V_49 ;
}
void F_19 ( T_1 * V_44 , struct V_50 * V_51 )
{
F_20 ( V_51 , L_14 , V_44 -> V_2 -> V_21 ) ;
}
void F_21 ( T_1 * V_1 , int V_12 , struct V_52 * V_53 )
{
#ifdef F_22
struct V_54 * V_55 ;
#endif
F_3 ( ( L_1 , V_6 ) ) ;
#ifdef F_22
F_23 ( V_53 , V_56 ) ;
V_55 = (struct V_54 * ) ( V_53 -> V_57 ) ;
V_55 -> V_11 = ( V_58 << V_59 ) ;
if ( F_24 ( V_53 ) )
V_55 -> V_11 |= V_60 ;
V_55 -> V_61 = ( V_53 -> V_61 & V_62 ) ;
V_55 -> V_63 = 0 ;
V_55 -> V_64 = 0 ;
#endif
F_25 ( V_55 , V_12 ) ;
}
int F_26 ( T_1 * V_1 , int * V_12 , struct V_52 * V_53 )
{
#ifdef F_22
struct V_54 * V_55 ;
#endif
F_3 ( ( L_1 , V_6 ) ) ;
#ifdef F_22
if ( V_53 -> V_3 < V_56 ) {
F_12 ( ( L_15 , V_6 ,
V_53 -> V_3 , V_56 ) ) ;
return - V_65 ;
}
V_55 = (struct V_54 * ) ( V_53 -> V_57 ) ;
* V_12 = F_27 ( V_55 ) ;
if ( * V_12 >= V_66 ) {
F_12 ( ( L_16 ,
V_6 , * V_12 ) ) ;
return - V_65 ;
}
if ( ( ( V_55 -> V_11 & V_67 ) >> V_59 ) !=
V_58 ) {
F_12 ( ( L_17 ,
F_13 ( V_1 , * V_12 ) , V_55 -> V_11 ) ) ;
return - V_65 ;
}
if ( V_55 -> V_11 & V_68 ) {
F_28 ( ( L_18
L_19 ,
F_13 ( V_1 , * V_12 ) , V_55 -> V_11 ) ) ;
F_29 ( V_53 , true ) ;
}
V_53 -> V_61 = V_55 -> V_61 & V_62 ;
F_30 ( V_53 , V_56 ) ;
#endif
return 0 ;
}
int F_31 ( T_1 * V_1 )
{
T_2 * V_69 ;
V_69 = F_32 ( sizeof( T_2 ) , V_70 ) ;
if ( ! V_69 ) {
F_12 ( ( L_20 , V_6 ) ) ;
goto V_71;
}
if ( ( unsigned long ) ( & V_69 -> V_4 + 1 ) != ( unsigned long ) V_69 -> V_14 ) {
F_12 ( ( L_21 ) ) ;
goto V_71;
}
V_1 -> V_2 = V_69 ;
#ifdef F_22
V_1 -> V_72 += V_56 ;
#endif
V_1 -> V_73 = V_33 + sizeof( V_5 ) + V_74 ;
return 0 ;
V_71:
F_33 ( V_69 ) ;
return - V_75 ;
}
void F_34 ( T_1 * V_1 )
{
F_33 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_35 ( T_1 * V_1 )
{
V_1 -> V_76 . V_77 = V_1 -> V_77 ;
V_1 -> V_76 . V_78 = V_1 -> V_78 ;
V_1 -> V_76 . V_79 = V_1 -> V_79 ;
V_1 -> V_76 . V_80 = V_1 -> V_80 ;
V_1 -> V_76 . V_81 = V_1 -> V_81 ;
V_1 -> V_76 . V_82 = V_1 -> V_83 ;
return;
}
int F_36 ( T_1 * V_1 )
{
int V_10 = 0 ;
char V_14 [ 128 ] ;
F_3 ( ( L_1 , V_6 ) ) ;
F_16 ( V_1 ) ;
strcpy ( V_14 , L_22 ) ;
V_10 = F_8 ( V_1 , 0 , V_17 , V_14 , sizeof( V_14 ) ) ;
if ( V_10 < 0 ) {
F_17 ( V_1 ) ;
return V_10 ;
}
memcpy ( V_1 -> V_84 , V_14 , V_85 ) ;
F_17 ( V_1 ) ;
#ifdef F_37
V_10 = F_38 ( V_1 ) ;
#endif
V_1 -> V_86 = true ;
return V_10 ;
}
void F_39 ( T_1 * V_1 )
{
}
