static int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , void * V_5 ,
T_1 V_6 , bool V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 = & V_9 -> V_13 ;
T_2 V_14 ;
F_2 ( V_15 , L_1 ) ;
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_4 = F_3 ( V_4 ) ;
V_13 -> V_6 = F_3 ( V_6 ) ;
V_14 = ( ++ V_9 -> V_16 << V_17 ) ;
if ( V_7 )
V_14 |= V_18 ;
V_14 = ( V_14 & ~ V_19 ) |
( V_3 << V_20 ) ;
V_13 -> V_14 = F_3 ( V_14 ) ;
if ( V_5 )
memcpy ( V_9 -> V_5 , V_5 , V_6 ) ;
V_6 += sizeof( * V_13 ) ;
if ( V_6 > V_21 )
V_6 = V_21 ;
return F_4 ( V_2 -> V_22 , ( unsigned char * ) & V_9 -> V_13 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_23 , T_2 V_6 )
{
int V_24 ;
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_10 -> V_11 ;
F_2 ( V_15 , L_1 ) ;
V_6 += sizeof( struct V_12 ) ;
do {
V_24 = F_6 ( V_2 -> V_22 , ( unsigned char * ) & V_9 -> V_13 ,
V_6 ) ;
if ( V_24 < 0 )
break;
} while ( F_7 ( F_8 ( V_9 -> V_13 . V_14 ) ) != V_23 );
return V_24 ;
}
static int
F_9 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
void * V_5 , T_1 V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 = & V_9 -> V_13 ;
void * V_25 ;
int V_24 = 0 , V_26 = 0 ;
T_2 V_23 , V_14 ;
F_2 ( V_15 , L_2 , V_4 , V_6 ) ;
V_24 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , false ) ;
if ( V_24 < 0 ) {
F_10 ( L_3 ,
V_24 ) ;
goto V_27;
}
V_28:
V_24 = F_5 ( V_2 , V_9 -> V_16 , V_6 ) ;
if ( V_24 < 0 )
goto V_27;
V_14 = F_8 ( V_13 -> V_14 ) ;
V_23 = ( V_14 & V_29 ) >> V_17 ;
if ( ( V_23 < V_9 -> V_16 ) && ( ++ V_26 < V_30 ) )
goto V_28;
if ( V_23 != V_9 -> V_16 ) {
F_10 ( L_4 ,
F_11 ( V_2 , V_3 ) , V_23 , V_9 -> V_16 ) ;
V_24 = - V_31 ;
goto V_27;
}
V_25 = ( void * ) & V_13 [ 1 ] ;
if ( V_5 ) {
if ( V_24 < ( int ) V_6 )
V_6 = V_24 ;
memcpy ( V_5 , V_25 , V_6 ) ;
}
if ( V_14 & V_32 )
V_24 = F_8 ( V_13 -> V_33 ) ;
V_27:
return V_24 ;
}
static int
F_12 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
void * V_5 , T_1 V_6 )
{
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_10 -> V_11 ;
struct V_12 * V_13 = & V_9 -> V_13 ;
int V_24 = 0 ;
T_2 V_14 , V_23 ;
F_2 ( V_15 , L_2 , V_4 , V_6 ) ;
V_24 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , true ) ;
if ( V_24 < 0 )
goto V_27;
V_24 = F_5 ( V_2 , V_9 -> V_16 , V_6 ) ;
if ( V_24 < 0 )
goto V_27;
V_14 = F_8 ( V_13 -> V_14 ) ;
V_23 = ( V_14 & V_29 ) >> V_17 ;
if ( V_23 != V_9 -> V_16 ) {
F_10 ( L_4 ,
F_11 ( V_2 , V_3 ) , V_23 , V_9 -> V_16 ) ;
V_24 = - V_31 ;
goto V_27;
}
if ( V_14 & V_32 )
V_24 = F_8 ( V_13 -> V_33 ) ;
V_27:
return V_24 ;
}
static void
F_13 ( struct V_1 * V_2 , int V_3 , T_3 V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 ;
F_2 ( V_15 , L_1 ) ;
F_14 ( V_36 , V_39 ) ;
V_38 = (struct V_37 * ) ( V_36 -> V_40 ) ;
V_38 -> V_14 = ( V_41 << V_42 ) ;
if ( V_36 -> V_43 == V_44 )
V_38 -> V_14 |= V_45 ;
V_38 -> V_46 = ( V_36 -> V_46 & V_47 ) ;
V_38 -> V_48 = 0 ;
V_38 -> V_49 = V_34 ;
F_15 ( V_38 , V_3 ) ;
F_16 ( V_36 -> V_40 ) ;
}
static int
F_17 ( struct V_1 * V_2 , bool V_50 , T_3 * V_3 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 ;
F_2 ( V_15 , L_1 ) ;
if ( V_36 -> V_6 <= V_39 ) {
F_2 ( V_51 , L_5 ,
V_36 -> V_6 , V_39 ) ;
return - V_52 ;
}
F_16 ( V_36 -> V_40 ) ;
V_38 = (struct V_37 * ) ( V_36 -> V_40 ) ;
* V_3 = F_18 ( V_38 ) ;
if ( * V_3 >= V_53 ) {
F_10 ( L_6 , * V_3 ) ;
return - V_52 ;
}
if ( * V_3 )
( * V_3 ) ++ ;
if ( ( ( V_38 -> V_14 & V_54 ) >> V_42 ) !=
V_41 ) {
F_10 ( L_7 ,
F_11 ( V_2 , * V_3 ) , V_38 -> V_14 ) ;
return - V_52 ;
}
if ( V_38 -> V_14 & V_55 ) {
F_2 ( V_15 , L_8 ,
F_11 ( V_2 , * V_3 ) , V_38 -> V_14 ) ;
V_36 -> V_43 = V_56 ;
}
V_36 -> V_46 = V_38 -> V_46 & V_47 ;
F_19 ( V_36 , V_39 ) ;
if ( V_50 )
F_20 ( V_2 , * V_3 , V_38 -> V_49 << 2 , V_36 ) ;
else
F_19 ( V_36 , V_38 -> V_49 << 2 ) ;
if ( V_36 -> V_6 == 0 )
return - V_57 ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , int V_3 , T_3 V_34 ,
struct V_35 * V_36 )
{
F_13 ( V_2 , V_3 , V_34 , V_36 ) ;
return F_22 ( V_2 -> V_22 , V_36 ) ;
}
static void
F_23 ( struct V_1 * V_2 , int V_3 ,
enum V_58 V_59 )
{
}
static void
F_24 ( struct V_1 * V_2 , int V_3 ,
T_3 V_60 [ V_61 ] )
{
}
static void
F_25 ( struct V_1 * V_2 , int V_3 ,
T_3 V_60 [ V_61 ] )
{
}
int F_26 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_27 ( sizeof( * V_9 ) , V_62 ) ;
if ( ! V_9 )
goto V_63;
if ( ( unsigned long ) ( & V_9 -> V_13 + 1 ) != ( unsigned long ) V_9 -> V_5 ) {
F_10 ( L_9 ) ;
goto V_63;
}
V_2 -> V_10 -> V_64 = F_17 ;
V_2 -> V_10 -> V_65 = F_9 ;
V_2 -> V_10 -> V_66 = F_12 ;
V_2 -> V_10 -> V_67 = F_21 ;
V_2 -> V_10 -> V_68 = F_23 ;
V_2 -> V_10 -> V_69 = F_24 ;
V_2 -> V_10 -> V_70 = F_25 ;
V_2 -> V_10 -> V_11 = V_9 ;
V_2 -> V_71 += V_39 + V_72 ;
V_2 -> V_22 -> V_73 = V_74 +
sizeof( struct V_12 ) ;
return 0 ;
V_63:
F_28 ( V_9 ) ;
return - V_75 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_10 -> V_11 ) ;
V_2 -> V_10 -> V_11 = NULL ;
}
