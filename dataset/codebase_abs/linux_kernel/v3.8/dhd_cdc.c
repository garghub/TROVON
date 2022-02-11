static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 ( V_4 -> V_6 . V_5 ) +
sizeof( struct V_7 ) ;
F_3 ( V_8 , L_1 ) ;
if ( V_5 > V_9 )
V_5 = V_9 ;
return F_4 ( V_2 -> V_10 , ( unsigned char * ) & V_4 -> V_6 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_5 )
{
int V_12 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_8 , L_1 ) ;
V_5 += sizeof( struct V_7 ) ;
do {
V_12 = F_6 ( V_2 -> V_10 , ( unsigned char * ) & V_4 -> V_6 ,
V_5 ) ;
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
F_10 ( L_6 ,
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
F_10 ( L_7 ,
F_11 ( V_2 , V_14 ) , V_11 , V_4 -> V_24 ) ;
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
int F_12 ( struct V_1 * V_2 , int V_14 , T_2 V_15 ,
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
F_10 ( L_7 ,
F_11 ( V_2 , V_14 ) , V_11 , V_4 -> V_24 ) ;
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
static bool F_13 ( struct V_35 * V_36 )
{
return V_36 -> V_37 == V_38 ;
}
static void F_14 ( struct V_35 * V_36 , bool V_39 )
{
V_36 -> V_37 = ( V_39 ? V_40 : V_41 ) ;
}
void F_15 ( struct V_1 * V_2 , int V_14 ,
struct V_35 * V_42 )
{
struct V_43 * V_44 ;
F_3 ( V_8 , L_1 ) ;
F_16 ( V_42 , V_45 ) ;
V_44 = (struct V_43 * ) ( V_42 -> V_46 ) ;
V_44 -> V_13 = ( V_47 << V_48 ) ;
if ( F_13 ( V_42 ) )
V_44 -> V_13 |= V_49 ;
V_44 -> V_50 = ( V_42 -> V_50 & V_51 ) ;
V_44 -> V_52 = 0 ;
V_44 -> V_53 = 0 ;
F_17 ( V_44 , V_14 ) ;
}
int F_18 ( struct V_54 * V_55 , int * V_14 ,
struct V_35 * V_42 )
{
struct V_43 * V_44 ;
struct V_56 * V_10 = F_19 ( V_55 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_3 ( V_8 , L_1 ) ;
if ( V_42 -> V_5 < V_45 ) {
F_10 ( L_8 ,
V_42 -> V_5 , V_45 ) ;
return - V_57 ;
}
V_44 = (struct V_43 * ) ( V_42 -> V_46 ) ;
* V_14 = F_20 ( V_44 ) ;
if ( * V_14 >= V_58 ) {
F_10 ( L_9 , * V_14 ) ;
return - V_57 ;
}
if ( ( ( V_44 -> V_13 & V_59 ) >> V_48 ) !=
V_47 ) {
F_10 ( L_10 ,
F_11 ( V_2 , * V_14 ) , V_44 -> V_13 ) ;
return - V_57 ;
}
if ( V_44 -> V_13 & V_60 ) {
F_3 ( V_61 , L_11 ,
F_11 ( V_2 , * V_14 ) , V_44 -> V_13 ) ;
F_14 ( V_42 , true ) ;
}
V_42 -> V_50 = V_44 -> V_50 & V_51 ;
F_21 ( V_42 , V_45 ) ;
F_21 ( V_42 , V_44 -> V_53 << 2 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_62 ;
V_62 = F_23 ( sizeof( struct V_3 ) , V_63 ) ;
if ( ! V_62 )
goto V_64;
if ( ( unsigned long ) ( & V_62 -> V_6 + 1 ) != ( unsigned long ) V_62 -> V_16 ) {
F_10 ( L_12 ) ;
goto V_64;
}
V_2 -> V_4 = V_62 ;
V_2 -> V_65 += V_45 ;
V_2 -> V_10 -> V_66 = V_67 +
sizeof( struct V_7 ) + V_68 ;
return 0 ;
V_64:
F_24 ( V_62 ) ;
return - V_69 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_26 ( struct V_1 * V_2 )
{
}
