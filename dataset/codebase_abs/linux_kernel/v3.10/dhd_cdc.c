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
F_3 ( V_8 , L_2 , V_15 , V_5 ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_15 = F_9 ( V_15 ) ;
V_6 -> V_5 = F_9 ( V_5 ) ;
V_13 = ( ++ V_4 -> V_19 << V_20 ) ;
V_13 = ( V_13 & ~ V_21 ) |
( V_14 << V_22 ) ;
V_6 -> V_13 = F_9 ( V_13 ) ;
if ( V_16 )
memcpy ( V_4 -> V_16 , V_16 , V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 ) {
F_10 ( L_3 ,
V_12 ) ;
goto V_23;
}
V_24:
V_12 = F_5 ( V_2 , V_4 -> V_19 , V_5 ) ;
if ( V_12 < 0 )
goto V_23;
V_13 = F_2 ( V_6 -> V_13 ) ;
V_11 = ( V_13 & V_25 ) >> V_20 ;
if ( ( V_11 < V_4 -> V_19 ) && ( ++ V_18 < V_26 ) )
goto V_24;
if ( V_11 != V_4 -> V_19 ) {
F_10 ( L_4 ,
F_11 ( V_2 , V_14 ) , V_11 , V_4 -> V_19 ) ;
V_12 = - V_27 ;
goto V_23;
}
V_17 = ( void * ) & V_6 [ 1 ] ;
if ( V_16 ) {
if ( V_12 < ( int ) V_5 )
V_5 = V_12 ;
memcpy ( V_16 , V_17 , V_5 ) ;
}
if ( V_13 & V_28 )
V_12 = F_2 ( V_6 -> V_29 ) ;
V_23:
return V_12 ;
}
int F_12 ( struct V_1 * V_2 , int V_14 , T_2 V_15 ,
void * V_16 , T_2 V_5 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_7 * V_6 = & V_4 -> V_6 ;
int V_12 = 0 ;
T_1 V_13 , V_11 ;
F_3 ( V_8 , L_2 , V_15 , V_5 ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
V_6 -> V_15 = F_9 ( V_15 ) ;
V_6 -> V_5 = F_9 ( V_5 ) ;
V_13 = ( ++ V_4 -> V_19 << V_20 ) | V_30 ;
V_13 = ( V_13 & ~ V_21 ) |
( V_14 << V_22 ) ;
V_6 -> V_13 = F_9 ( V_13 ) ;
if ( V_16 )
memcpy ( V_4 -> V_16 , V_16 , V_5 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
goto V_23;
V_12 = F_5 ( V_2 , V_4 -> V_19 , V_5 ) ;
if ( V_12 < 0 )
goto V_23;
V_13 = F_2 ( V_6 -> V_13 ) ;
V_11 = ( V_13 & V_25 ) >> V_20 ;
if ( V_11 != V_4 -> V_19 ) {
F_10 ( L_4 ,
F_11 ( V_2 , V_14 ) , V_11 , V_4 -> V_19 ) ;
V_12 = - V_27 ;
goto V_23;
}
if ( V_13 & V_28 )
V_12 = F_2 ( V_6 -> V_29 ) ;
V_23:
return V_12 ;
}
static bool F_13 ( struct V_31 * V_32 )
{
return V_32 -> V_33 == V_34 ;
}
static void F_14 ( struct V_31 * V_32 , bool V_35 )
{
V_32 -> V_33 = ( V_35 ? V_36 : V_37 ) ;
}
void F_15 ( struct V_1 * V_2 , int V_14 , T_3 V_38 ,
struct V_31 * V_39 )
{
struct V_40 * V_41 ;
F_3 ( V_8 , L_1 ) ;
F_16 ( V_39 , V_42 ) ;
V_41 = (struct V_40 * ) ( V_39 -> V_43 ) ;
V_41 -> V_13 = ( V_44 << V_45 ) ;
if ( F_13 ( V_39 ) )
V_41 -> V_13 |= V_46 ;
V_41 -> V_47 = ( V_39 -> V_47 & V_48 ) ;
V_41 -> V_49 = 0 ;
V_41 -> V_50 = V_38 ;
F_17 ( V_41 , V_14 ) ;
}
int F_18 ( struct V_1 * V_2 , bool V_51 , T_3 * V_14 ,
struct V_31 * V_39 )
{
struct V_40 * V_41 ;
F_3 ( V_8 , L_1 ) ;
if ( V_39 -> V_5 <= V_42 ) {
F_3 ( V_52 , L_5 ,
V_39 -> V_5 , V_42 ) ;
return - V_53 ;
}
V_41 = (struct V_40 * ) ( V_39 -> V_43 ) ;
* V_14 = F_19 ( V_41 ) ;
if ( * V_14 >= V_54 ) {
F_10 ( L_6 , * V_14 ) ;
return - V_53 ;
}
if ( * V_14 )
( * V_14 ) ++ ;
if ( ( ( V_41 -> V_13 & V_55 ) >> V_45 ) !=
V_44 ) {
F_10 ( L_7 ,
F_11 ( V_2 , * V_14 ) , V_41 -> V_13 ) ;
return - V_53 ;
}
if ( V_41 -> V_13 & V_56 ) {
F_3 ( V_8 , L_8 ,
F_11 ( V_2 , * V_14 ) , V_41 -> V_13 ) ;
F_14 ( V_39 , true ) ;
}
V_39 -> V_47 = V_41 -> V_47 & V_48 ;
F_20 ( V_39 , V_42 ) ;
if ( V_51 )
F_21 ( V_2 , * V_14 , V_41 -> V_50 << 2 , V_39 ) ;
else
F_20 ( V_39 , V_41 -> V_50 << 2 ) ;
if ( V_39 -> V_5 == 0 )
return - V_57 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_58 ;
V_58 = F_23 ( sizeof( struct V_3 ) , V_59 ) ;
if ( ! V_58 )
goto V_60;
if ( ( unsigned long ) ( & V_58 -> V_6 + 1 ) != ( unsigned long ) V_58 -> V_16 ) {
F_10 ( L_9 ) ;
goto V_60;
}
V_2 -> V_4 = V_58 ;
V_2 -> V_61 += V_42 + V_62 ;
V_2 -> V_10 -> V_63 = V_64 +
sizeof( struct V_7 ) + V_65 ;
return 0 ;
V_60:
F_24 ( V_58 ) ;
return - V_66 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_26 ( struct V_1 * V_2 )
{
}
