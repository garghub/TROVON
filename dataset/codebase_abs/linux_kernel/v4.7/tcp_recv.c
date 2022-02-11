static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 , V_4 , V_2 ) ;
F_4 ( & V_4 -> V_6 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_1 ( V_2 ) ;
F_3 ( L_2 , V_4 , V_2 ) ;
F_6 ( V_7 , V_4 ) ;
}
int F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 ;
int V_12 = 0 ;
if ( ! F_8 ( V_9 ) )
goto V_13;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_9 (&tinc->ti_skb_list, skb) {
unsigned long V_14 , V_15 ;
for ( V_15 = 0 ; V_15 < V_11 -> V_16 ; V_15 += V_14 ) {
V_14 = F_8 ( V_9 ) ;
V_14 = F_10 ( V_14 , V_11 -> V_16 - V_15 ) ;
if ( F_11 ( V_11 , V_15 , V_9 , V_14 ) )
return - V_17 ;
F_12 ( V_18 , V_14 ) ;
V_12 += V_14 ;
if ( ! F_8 ( V_9 ) )
goto V_13;
}
}
V_13:
return V_12 ;
}
static void F_13 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 ;
unsigned int V_14 , V_15 ;
unsigned int V_21 ;
unsigned int V_22 ;
struct V_23 * V_24 ;
int V_12 ;
if ( F_14 ( V_4 -> V_5 . V_25 . V_26 ) != V_27 )
return;
V_22 = 0 ;
V_21 = 0 ;
V_24 = V_20 -> V_28 ;
F_9 (&tinc->ti_skb_list, skb) {
V_15 = 0 ;
while ( V_15 < V_11 -> V_16 ) {
V_14 = F_15 (unsigned int, PAGE_SIZE - map_off,
skb->len - skb_off) ;
F_16 ( V_22 >= V_29 ) ;
V_12 = F_17 ( V_11 , V_15 ,
( void * ) V_24 -> V_30 [ V_22 ] + V_21 ,
V_14 ) ;
F_16 ( V_12 != 0 ) ;
V_15 += V_14 ;
V_21 += V_14 ;
if ( V_21 == V_31 ) {
V_21 = 0 ;
V_22 ++ ;
}
}
}
F_18 ( V_24 , ~ ( V_32 ) 0 ) ;
}
static int F_19 ( T_1 * V_33 , struct V_10 * V_11 ,
unsigned int V_34 , T_2 V_16 )
{
struct V_35 * V_36 = V_33 -> V_36 . V_37 ;
struct V_19 * V_20 = V_36 -> V_20 ;
struct V_38 * V_39 = V_20 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_41 ;
struct V_10 * V_42 ;
T_2 V_43 = V_16 , V_14 ;
F_3 ( L_3 , V_39 , V_11 , V_34 ,
V_16 ) ;
while ( V_43 ) {
if ( ! V_4 ) {
V_4 = F_20 ( V_7 ,
V_36 -> V_44 ) ;
if ( ! V_4 ) {
V_33 -> error = - V_45 ;
goto V_13;
}
V_39 -> V_41 = V_4 ;
F_3 ( L_4 , V_4 ) ;
F_21 ( & V_4 -> V_5 , V_20 , V_20 -> V_46 ) ;
F_22 ( & V_4 -> V_6 ) ;
}
if ( V_43 && V_39 -> V_47 ) {
V_14 = F_10 ( V_39 -> V_47 , V_43 ) ;
F_3 ( L_5 , V_14 ,
V_11 ) ;
F_17 ( V_11 , V_34 ,
( char * ) & V_4 -> V_5 . V_25 +
sizeof( struct V_48 ) -
V_39 -> V_47 ,
V_14 ) ;
V_39 -> V_47 -= V_14 ;
V_43 -= V_14 ;
V_34 += V_14 ;
if ( V_39 -> V_47 == 0 ) {
V_39 -> V_49 =
F_14 ( V_4 -> V_5 . V_25 . V_26 ) ;
}
}
if ( V_43 && V_39 -> V_49 ) {
V_14 = F_10 ( V_39 -> V_49 , V_43 ) ;
V_42 = F_23 ( V_11 , V_34 , V_14 , V_36 -> V_44 ) ;
if ( ! V_42 ) {
V_33 -> error = - V_45 ;
goto V_13;
}
F_24 ( & V_4 -> V_6 , V_42 ) ;
F_3 ( L_6
L_7 ,
V_11 , V_11 -> V_37 , V_11 -> V_16 , V_34 , V_14 ,
V_42 , V_42 -> V_37 , V_42 -> V_16 ) ;
V_39 -> V_49 -= V_14 ;
V_43 -= V_14 ;
V_34 += V_14 ;
}
if ( V_39 -> V_47 == 0 && V_39 -> V_49 == 0 ) {
if ( V_4 -> V_5 . V_25 . V_50 == V_51 )
F_13 ( V_20 , V_4 ) ;
else
F_25 ( V_20 , V_20 -> V_46 ,
V_20 -> V_52 , & V_4 -> V_5 ,
V_36 -> V_44 ) ;
V_39 -> V_47 = sizeof( struct V_48 ) ;
V_39 -> V_49 = 0 ;
V_39 -> V_41 = NULL ;
F_26 ( & V_4 -> V_5 ) ;
V_4 = NULL ;
}
}
V_13:
F_3 ( L_8 ,
V_16 , V_43 , V_11 -> V_16 ,
F_27 ( & V_39 -> V_53 -> V_54 -> V_55 ) ) ;
return V_16 - V_43 ;
}
static int F_28 ( struct V_19 * V_20 , T_3 V_44 )
{
struct V_38 * V_39 = V_20 -> V_40 ;
struct V_56 * V_57 = V_39 -> V_53 ;
T_1 V_33 ;
struct V_35 V_36 ;
V_36 . V_20 = V_20 ;
V_36 . V_44 = V_44 ;
V_33 . V_36 . V_37 = & V_36 ;
V_33 . error = 0 ;
V_33 . V_58 = 1 ;
F_29 ( V_57 -> V_54 , & V_33 , F_19 ) ;
F_3 ( L_9 , V_39 , V_44 ,
V_33 . error ) ;
return V_33 . error ;
}
int F_30 ( struct V_19 * V_20 )
{
struct V_38 * V_39 = V_20 -> V_40 ;
struct V_56 * V_57 = V_39 -> V_53 ;
int V_12 = 0 ;
F_3 ( L_10 , V_20 , V_39 , V_57 ) ;
F_31 ( V_57 -> V_54 ) ;
V_12 = F_28 ( V_20 , V_59 ) ;
F_32 ( V_57 -> V_54 ) ;
return V_12 ;
}
void F_33 ( struct V_57 * V_54 )
{
void (* F_34)( struct V_57 * V_54 );
struct V_19 * V_20 ;
struct V_38 * V_39 ;
F_3 ( L_11 , V_54 ) ;
F_35 ( & V_54 -> V_60 ) ;
V_20 = V_54 -> V_61 ;
if ( ! V_20 ) {
F_34 = V_54 -> V_62 ;
goto V_13;
}
V_39 = V_20 -> V_40 ;
F_34 = V_39 -> V_63 ;
F_36 ( V_64 ) ;
if ( F_28 ( V_20 , V_65 ) == - V_45 )
F_37 ( V_66 , & V_20 -> V_67 , 0 ) ;
V_13:
F_38 ( & V_54 -> V_60 ) ;
F_34 ( V_54 ) ;
}
int F_39 ( void )
{
V_7 = F_40 ( L_12 ,
sizeof( struct V_3 ) ,
0 , 0 , NULL ) ;
if ( ! V_7 )
return - V_45 ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( V_7 ) ;
}
