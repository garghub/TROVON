static int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 * V_3 ;
}
static bool F_2 ( struct V_1 * V_4 ,
int V_5 ,
unsigned long V_6 ,
bool V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_10 )
{
struct V_1 * V_1 =
(struct V_1 * ) V_10 -> V_11 -> V_12 ;
int V_13 = V_10 -> V_5 + V_5 ;
if ( F_3 ( V_6 , V_10 -> V_6 ) &&
F_4 ( V_6 + F_5 ( V_14 ) ,
V_10 -> V_6 ) &&
( V_13 <= V_15 ) ) {
if ( ( ! V_7 ) &&
( ! ( V_1 -> V_16 & V_17 ) ) &&
( V_1 -> V_18 != 1 ) &&
( ( ! V_10 -> V_19 ) ||
( V_10 -> V_9 -> V_20 == 0 ) ) )
return true ;
if ( ( V_7 ) &&
( V_4 -> V_18 == 1 ) &&
( V_10 -> V_9 == V_9 ) &&
( V_1 -> V_16 & V_17 ||
( V_10 -> V_19 &&
V_10 -> V_9 -> V_20 != 0 ) ) )
return true ;
}
return false ;
}
static void F_6 ( unsigned char * V_21 , int V_5 ,
unsigned long V_6 , bool V_22 ,
struct V_8 * V_9 ,
int V_23 )
{
struct V_24 * V_24 = F_7 ( V_9 -> V_25 ) ;
struct V_10 * V_26 ;
unsigned char * V_27 ;
if ( ! F_8 ( & V_9 -> V_28 ) )
return;
if ( ! V_23 ) {
if ( ! F_9 ( & V_24 -> V_29 ) ) {
F_10 ( V_30 , V_24 ,
L_1 ) ;
goto V_31;
}
}
V_26 = F_11 ( sizeof( struct V_10 ) , V_32 ) ;
if ( ! V_26 ) {
if ( ! V_23 )
F_12 ( & V_24 -> V_29 ) ;
goto V_31;
}
if ( ( F_13 ( & V_24 -> V_33 ) ) &&
( V_5 < V_15 ) )
V_26 -> V_11 = F_14 ( V_15 +
sizeof( struct V_34 ) ) ;
else
V_26 -> V_11 = F_14 ( V_5 +
sizeof( struct V_34 ) ) ;
if ( ! V_26 -> V_11 ) {
if ( ! V_23 )
F_12 ( & V_24 -> V_29 ) ;
F_15 ( V_26 ) ;
goto V_31;
}
F_16 ( V_26 -> V_11 , sizeof( struct V_34 ) ) ;
F_17 ( & V_26 -> V_35 ) ;
V_27 = F_18 ( V_26 -> V_11 , V_5 ) ;
V_26 -> V_5 = V_5 ;
memcpy ( V_27 , V_21 , V_5 ) ;
V_26 -> V_19 = V_23 ;
V_26 -> V_9 = V_9 ;
V_26 -> V_36 = 0 ;
V_26 -> V_37 = 0 ;
V_26 -> V_6 = V_6 ;
if ( V_22 )
V_26 -> V_37 |= 1 ;
F_19 ( & V_24 -> V_38 ) ;
F_20 ( & V_26 -> V_35 , & V_24 -> V_39 ) ;
F_21 ( & V_24 -> V_38 ) ;
F_22 ( & V_26 -> V_40 ,
V_41 ) ;
F_23 ( V_42 ,
& V_26 -> V_40 ,
V_6 - V_43 ) ;
return;
V_31:
F_24 ( V_9 ) ;
}
static void F_25 ( struct V_10 * V_26 ,
unsigned char * V_21 ,
int V_5 ,
bool V_22 )
{
unsigned char * V_27 ;
V_27 = F_18 ( V_26 -> V_11 , V_5 ) ;
memcpy ( V_27 , V_21 , V_5 ) ;
V_26 -> V_5 += V_5 ;
V_26 -> V_36 ++ ;
if ( V_22 )
V_26 -> V_37 |=
( 1 << V_26 -> V_36 ) ;
}
void F_26 ( struct V_24 * V_24 ,
unsigned char * V_21 , int V_5 ,
struct V_8 * V_9 , char V_23 ,
unsigned long V_6 )
{
struct V_10 * V_26 = NULL , * V_44 = NULL ;
struct V_45 * V_46 ;
struct V_1 * V_1 =
(struct V_1 * ) V_21 ;
bool V_22 = V_1 -> V_16 & V_17 ? 1 : 0 ;
F_19 ( & V_24 -> V_38 ) ;
if ( ( F_13 ( & V_24 -> V_33 ) ) && ( ! V_23 ) ) {
F_27 (forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if ( F_2 ( V_1 ,
V_5 ,
V_6 ,
V_22 ,
V_9 ,
V_44 ) ) {
V_26 = V_44 ;
break;
}
}
}
if ( ! V_26 ) {
F_21 ( & V_24 -> V_38 ) ;
if ( ( ! V_23 ) &&
( F_13 ( & V_24 -> V_33 ) ) )
V_6 += F_5 ( V_14 ) ;
F_6 ( V_21 , V_5 ,
V_6 , V_22 ,
V_9 , V_23 ) ;
} else {
F_25 ( V_26 ,
V_21 , V_5 ,
V_22 ) ;
F_21 ( & V_24 -> V_38 ) ;
}
}
void F_28 ( struct V_34 * V_34 , unsigned char * V_21 ,
int V_5 , struct V_8 * V_9 )
{
struct V_1 * V_1 ;
int V_47 = 0 ;
unsigned char * V_48 ;
V_1 = (struct V_1 * ) V_21 ;
do {
V_1 -> V_49 = F_29 ( V_1 -> V_49 ) ;
V_48 = V_21 + V_47 + V_50 ;
F_30 ( V_34 , V_1 ,
V_48 , F_1 ( V_1 ) ,
V_9 ) ;
V_47 += V_50 + F_1 ( V_1 ) ;
V_1 = (struct V_1 * )
( V_21 + V_47 ) ;
} while ( F_31 ( V_47 , V_5 ,
V_1 -> V_2 ) );
}
