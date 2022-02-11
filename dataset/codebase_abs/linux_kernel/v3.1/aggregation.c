static bool F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_3 ,
int V_4 ,
unsigned long V_5 ,
bool V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_9 )
{
struct V_1 * V_1 =
(struct V_1 * ) V_9 -> V_10 -> V_11 ;
int V_12 = V_9 -> V_4 + V_4 ;
struct V_7 * V_13 = NULL ;
bool V_14 = false ;
if ( F_2 ( V_5 , V_9 -> V_5 ) &&
F_3 ( V_5 + F_4 ( V_15 ) ,
V_9 -> V_5 ) &&
( V_12 <= V_16 ) ) {
V_13 = F_5 ( V_3 ) ;
if ( ! V_13 )
goto V_17;
if ( ( ! V_6 ) &&
( ! ( V_1 -> V_18 & V_19 ) ) &&
( V_1 -> V_20 != 1 ) &&
( ( ! V_9 -> V_21 ) ||
( V_9 -> V_8 == V_13 ) ) ) {
V_14 = true ;
goto V_17;
}
if ( ( V_6 ) &&
( V_2 -> V_20 == 1 ) &&
( V_9 -> V_8 == V_8 ) &&
( V_1 -> V_18 & V_19 ||
( V_9 -> V_21 &&
V_9 -> V_8 != V_13 ) ) ) {
V_14 = true ;
goto V_17;
}
}
V_17:
if ( V_13 )
F_6 ( V_13 ) ;
return V_14 ;
}
static void F_7 ( const unsigned char * V_22 ,
int V_4 , unsigned long V_5 ,
bool V_23 ,
struct V_7 * V_8 ,
int V_24 )
{
struct V_3 * V_3 = F_8 ( V_8 -> V_25 ) ;
struct V_9 * V_26 ;
unsigned char * V_27 ;
if ( ! F_9 ( & V_8 -> V_28 ) )
return;
if ( ! V_24 ) {
if ( ! F_10 ( & V_3 -> V_29 ) ) {
F_11 ( V_30 , V_3 ,
L_1 ) ;
goto V_17;
}
}
V_26 = F_12 ( sizeof( * V_26 ) , V_31 ) ;
if ( ! V_26 ) {
if ( ! V_24 )
F_13 ( & V_3 -> V_29 ) ;
goto V_17;
}
if ( ( F_14 ( & V_3 -> V_32 ) ) &&
( V_4 < V_16 ) )
V_26 -> V_10 = F_15 ( V_16 +
sizeof( struct V_33 ) ) ;
else
V_26 -> V_10 = F_15 ( V_4 +
sizeof( struct V_33 ) ) ;
if ( ! V_26 -> V_10 ) {
if ( ! V_24 )
F_13 ( & V_3 -> V_29 ) ;
F_16 ( V_26 ) ;
goto V_17;
}
F_17 ( V_26 -> V_10 , sizeof( struct V_33 ) ) ;
F_18 ( & V_26 -> V_34 ) ;
V_27 = F_19 ( V_26 -> V_10 , V_4 ) ;
V_26 -> V_4 = V_4 ;
memcpy ( V_27 , V_22 , V_4 ) ;
V_26 -> V_21 = V_24 ;
V_26 -> V_8 = V_8 ;
V_26 -> V_35 = 0 ;
V_26 -> V_36 = V_37 ;
V_26 -> V_5 = V_5 ;
if ( V_23 )
V_26 -> V_36 |= 1 ;
F_20 ( & V_3 -> V_38 ) ;
F_21 ( & V_26 -> V_34 , & V_3 -> V_39 ) ;
F_22 ( & V_3 -> V_38 ) ;
F_23 ( & V_26 -> V_40 ,
V_41 ) ;
F_24 ( V_42 ,
& V_26 -> V_40 ,
V_5 - V_43 ) ;
return;
V_17:
F_6 ( V_8 ) ;
}
static void F_25 ( struct V_9 * V_26 ,
const unsigned char * V_22 , int V_4 ,
bool V_23 )
{
unsigned char * V_27 ;
V_27 = F_19 ( V_26 -> V_10 , V_4 ) ;
memcpy ( V_27 , V_22 , V_4 ) ;
V_26 -> V_4 += V_4 ;
V_26 -> V_35 ++ ;
if ( V_23 )
V_26 -> V_36 |=
( 1 << V_26 -> V_35 ) ;
}
void F_26 ( struct V_3 * V_3 ,
unsigned char * V_22 , int V_4 ,
struct V_7 * V_8 , int V_24 ,
unsigned long V_5 )
{
struct V_9 * V_26 = NULL , * V_44 = NULL ;
struct V_45 * V_46 ;
struct V_1 * V_1 =
(struct V_1 * ) V_22 ;
bool V_23 = V_1 -> V_18 & V_19 ? 1 : 0 ;
F_20 ( & V_3 -> V_38 ) ;
if ( ( F_14 ( & V_3 -> V_32 ) ) && ( ! V_24 ) ) {
F_27 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_1 ( V_1 ,
V_3 ,
V_4 ,
V_5 ,
V_23 ,
V_8 ,
V_44 ) ) {
V_26 = V_44 ;
break;
}
}
}
if ( ! V_26 ) {
F_22 ( & V_3 -> V_38 ) ;
if ( ( ! V_24 ) &&
( F_14 ( & V_3 -> V_32 ) ) )
V_5 += F_4 ( V_15 ) ;
F_7 ( V_22 , V_4 ,
V_5 , V_23 ,
V_8 , V_24 ) ;
} else {
F_25 ( V_26 ,
V_22 , V_4 ,
V_23 ) ;
F_22 ( & V_3 -> V_38 ) ;
}
}
void F_28 ( const struct V_33 * V_33 ,
unsigned char * V_22 , int V_4 ,
struct V_7 * V_8 )
{
struct V_1 * V_1 ;
int V_47 = 0 ;
unsigned char * V_48 ;
V_1 = (struct V_1 * ) V_22 ;
do {
V_1 -> V_49 = F_29 ( V_1 -> V_49 ) ;
V_1 -> V_50 = F_30 ( V_1 -> V_50 ) ;
V_48 = V_22 + V_47 + V_51 ;
F_31 ( V_33 , V_1 , V_48 , V_8 ) ;
V_47 += V_51 +
F_32 ( V_1 -> V_52 ) ;
V_1 = (struct V_1 * )
( V_22 + V_47 ) ;
} while ( F_33 ( V_47 , V_4 ,
V_1 -> V_52 ) );
}
