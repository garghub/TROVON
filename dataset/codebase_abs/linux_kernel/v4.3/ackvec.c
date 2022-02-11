struct V_1 * F_1 ( const T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( V_4 , V_2 ) ;
if ( V_3 != NULL ) {
V_3 -> V_5 = V_3 -> V_6 = V_7 - 1 ;
F_3 ( & V_3 -> V_8 ) ;
}
return V_3 ;
}
static void F_4 ( struct V_1 * V_3 )
{
struct V_9 * V_10 , * V_11 ;
F_5 (cur, next, &av->av_records, avr_node)
F_6 ( V_12 , V_10 ) ;
F_3 ( & V_3 -> V_8 ) ;
}
void F_7 ( struct V_1 * V_3 )
{
if ( F_8 ( V_3 != NULL ) ) {
F_4 ( V_3 ) ;
F_6 ( V_4 , V_3 ) ;
}
}
int F_9 ( struct V_1 * V_3 , T_2 V_13 , T_3 V_14 )
{
struct V_9 * V_15 ;
V_15 = F_10 ( V_12 , V_16 ) ;
if ( V_15 == NULL )
return - V_17 ;
V_15 -> V_18 = V_13 ;
V_15 -> V_19 = V_3 -> V_5 ;
V_15 -> V_20 = V_3 -> V_21 ;
V_15 -> V_22 = V_14 ;
V_15 -> V_23 = F_11 ( V_3 -> V_24 + V_3 -> V_5 ) ;
if ( V_3 -> V_25 )
F_4 ( V_3 ) ;
F_12 ( & V_15 -> V_26 , & V_3 -> V_8 ) ;
F_13 ( L_1 ,
( unsigned long long ) V_15 -> V_18 ,
( unsigned long long ) V_15 -> V_20 ,
V_15 -> V_23 ) ;
return 0 ;
}
static struct V_9 * F_14 ( struct V_27 * V_28 ,
const T_2 V_29 )
{
struct V_9 * V_15 ;
F_15 (avr, av_list, avr_node) {
if ( V_15 -> V_18 == V_29 )
return V_15 ;
if ( F_16 ( V_29 , V_15 -> V_18 ) )
break;
}
return NULL ;
}
static inline T_4 F_17 ( const T_4 V_30 , const T_4 V_31 )
{
return ( V_30 + V_31 ) % V_7 ;
}
static inline T_4 F_18 ( const T_4 V_30 , const T_4 V_31 )
{
return F_17 ( V_30 , V_7 - V_31 ) ;
}
T_4 F_19 ( const struct V_1 * V_3 )
{
if ( F_20 ( V_3 -> V_25 ) )
return V_7 ;
return F_18 ( V_3 -> V_6 , V_3 -> V_5 ) ;
}
static void F_21 ( struct V_1 * V_3 , T_5 V_32 ,
T_2 V_13 , enum V_33 V_34 )
{
T_4 V_35 = V_3 -> V_5 ;
F_22 ( V_32 > 0 ) ;
if ( F_20 ( F_23 ( V_3 ) ) )
return;
do {
T_3 V_36 = F_11 ( V_3 -> V_24 + V_35 ) ;
if ( V_32 + V_36 >= 0 ) {
if ( V_3 -> V_24 [ V_35 ] == V_37 )
V_3 -> V_24 [ V_35 ] = V_34 ;
else
F_13 ( L_2 ,
( unsigned long long ) V_13 , V_34 ) ;
break;
}
V_32 += V_36 + 1 ;
V_35 = F_17 ( V_35 , 1 ) ;
} while ( V_35 != V_3 -> V_6 );
}
static void F_24 ( struct V_1 * V_3 , T_4 V_38 )
{
T_4 V_39 = F_17 ( V_3 -> V_5 , 1 ) ,
V_40 = V_7 - V_39 ;
if ( V_38 > V_40 ) {
memset ( V_3 -> V_24 + V_39 , V_37 , V_40 ) ;
V_39 = 0 ;
V_38 -= V_40 ;
}
if ( V_38 )
memset ( V_3 -> V_24 + V_39 , V_37 , V_38 ) ;
}
static void F_25 ( struct V_1 * V_3 , T_6 V_41 ,
T_2 V_13 , enum V_33 V_34 )
{
T_6 V_42 = V_41 ;
if ( V_41 > V_43 ) {
T_6 V_44 = V_41 - 1 ;
F_26 ( L_3 , V_44 ) ;
for ( V_41 = V_42 = 1 ; V_44 ; ++ V_42 ) {
T_3 V_40 = F_27 ( T_6 , V_44 , V_45 ) ;
V_3 -> V_5 = F_18 ( V_3 -> V_5 , 1 ) ;
V_3 -> V_24 [ V_3 -> V_5 ] = V_37 | V_40 ;
V_44 -= V_40 ;
}
}
if ( V_42 + F_19 ( V_3 ) >= V_7 ) {
F_28 ( L_4 ) ;
V_3 -> V_25 = true ;
}
V_3 -> V_5 = F_18 ( V_3 -> V_5 , V_41 ) ;
if ( V_3 -> V_25 )
V_3 -> V_6 = V_3 -> V_5 ;
V_3 -> V_24 [ V_3 -> V_5 ] = V_34 ;
V_3 -> V_21 = V_13 ;
if ( V_41 > 1 )
F_24 ( V_3 , V_41 - 1 ) ;
}
void F_29 ( struct V_1 * V_3 , struct V_46 * V_47 )
{
T_2 V_13 = F_30 ( V_47 ) -> V_48 ;
enum V_33 V_34 = V_49 ;
if ( F_23 ( V_3 ) ) {
F_25 ( V_3 , 1 , V_13 , V_34 ) ;
V_3 -> V_50 = V_13 ;
} else {
T_5 V_41 = F_31 ( V_3 -> V_21 , V_13 ) ;
T_3 * V_51 = V_3 -> V_24 + V_3 -> V_5 ;
if ( V_41 == 1 &&
F_32 ( V_51 ) == V_34 &&
F_11 ( V_51 ) < V_45 ) {
* V_51 += 1 ;
V_3 -> V_21 = V_13 ;
} else if ( V_41 > 0 ) {
F_25 ( V_3 , V_41 , V_13 , V_34 ) ;
} else {
F_21 ( V_3 , V_41 , V_13 , V_34 ) ;
}
}
}
void F_33 ( struct V_1 * V_3 , const T_2 V_29 )
{
struct V_9 * V_15 , * V_11 ;
T_3 V_52 , V_53 ;
T_5 V_54 ;
V_15 = F_14 ( & V_3 -> V_8 , V_29 ) ;
if ( V_15 == NULL )
return;
V_54 = F_31 ( V_3 -> V_50 , V_15 -> V_20 ) ;
if ( V_54 < 0 )
goto V_55;
V_53 = V_54 < V_15 -> V_23 ? V_54 : V_15 -> V_23 ;
V_52 = F_11 ( V_3 -> V_24 + V_15 -> V_19 ) ;
if ( V_52 > V_53 ) {
V_3 -> V_24 [ V_15 -> V_19 ] -= V_53 + 1 ;
V_3 -> V_6 = F_17 ( V_15 -> V_19 , 1 ) ;
if ( V_3 -> V_25 )
V_3 -> V_25 = ( V_3 -> V_5 == V_3 -> V_6 ) ;
} else {
V_3 -> V_6 = V_15 -> V_19 ;
V_3 -> V_25 = 0 ;
}
V_3 -> V_50 = F_34 ( V_15 -> V_20 , 1 ) ;
V_55:
F_35 (avr, next, &av->av_records, avr_node) {
F_36 ( & V_15 -> V_26 ) ;
F_6 ( V_12 , V_15 ) ;
}
}
int F_37 ( struct V_27 * V_56 , T_3 * V_57 , T_3 V_40 , T_3 V_58 )
{
struct V_59 * V_60 = F_38 ( sizeof( * V_60 ) , V_16 ) ;
if ( V_60 == NULL )
return - V_17 ;
V_60 -> V_57 = V_57 ;
V_60 -> V_40 = V_40 ;
V_60 -> V_58 = V_58 ;
F_39 ( & V_60 -> V_61 , V_56 ) ;
return 0 ;
}
void F_40 ( struct V_27 * V_62 )
{
struct V_59 * V_10 , * V_11 ;
F_5 (cur, next, parsed_chunks, node)
F_41 ( V_10 ) ;
F_3 ( V_62 ) ;
}
int T_7 F_42 ( void )
{
V_4 = F_43 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_63 , NULL ) ;
if ( V_4 == NULL )
goto V_64;
V_12 = F_43 ( L_6 ,
sizeof( struct V_9 ) ,
0 , V_63 , NULL ) ;
if ( V_12 == NULL )
goto V_65;
return 0 ;
V_65:
F_44 ( V_4 ) ;
V_4 = NULL ;
V_64:
F_28 ( L_7 ) ;
return - V_17 ;
}
void F_45 ( void )
{
F_44 ( V_4 ) ;
V_4 = NULL ;
F_44 ( V_12 ) ;
V_12 = NULL ;
}
