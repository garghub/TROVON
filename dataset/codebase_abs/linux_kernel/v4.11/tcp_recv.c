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
struct V_38 * V_39 = V_36 -> V_40 ;
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_3 * V_4 = V_42 -> V_44 ;
struct V_10 * V_45 ;
T_2 V_46 = V_16 , V_14 ;
F_3 ( L_3 , V_42 , V_11 , V_34 ,
V_16 ) ;
while ( V_46 ) {
if ( ! V_4 ) {
V_4 = F_20 ( V_7 ,
V_36 -> V_47 ) ;
if ( ! V_4 ) {
V_33 -> error = - V_48 ;
goto V_13;
}
V_42 -> V_44 = V_4 ;
F_3 ( L_4 , V_4 ) ;
F_21 ( & V_4 -> V_5 , V_39 ,
V_39 -> V_49 -> V_50 ) ;
V_4 -> V_5 . V_51 [ V_52 ] =
F_22 () ;
F_23 ( & V_4 -> V_6 ) ;
}
if ( V_46 && V_42 -> V_53 ) {
V_14 = F_10 ( V_42 -> V_53 , V_46 ) ;
F_3 ( L_5 , V_14 ,
V_11 ) ;
F_17 ( V_11 , V_34 ,
( char * ) & V_4 -> V_5 . V_25 +
sizeof( struct V_54 ) -
V_42 -> V_53 ,
V_14 ) ;
V_42 -> V_53 -= V_14 ;
V_46 -= V_14 ;
V_34 += V_14 ;
if ( V_42 -> V_53 == 0 ) {
V_42 -> V_55 =
F_14 ( V_4 -> V_5 . V_25 . V_26 ) ;
V_4 -> V_5 . V_51 [ V_56 ] =
F_22 () ;
}
}
if ( V_46 && V_42 -> V_55 ) {
V_14 = F_10 ( V_42 -> V_55 , V_46 ) ;
V_45 = F_24 ( V_11 , V_34 , V_14 , V_36 -> V_47 ) ;
if ( ! V_45 ) {
V_33 -> error = - V_48 ;
goto V_13;
}
F_25 ( & V_4 -> V_6 , V_45 ) ;
F_3 ( L_6
L_7 ,
V_11 , V_11 -> V_37 , V_11 -> V_16 , V_34 , V_14 ,
V_45 , V_45 -> V_37 , V_45 -> V_16 ) ;
V_42 -> V_55 -= V_14 ;
V_46 -= V_14 ;
V_34 += V_14 ;
}
if ( V_42 -> V_53 == 0 && V_42 -> V_55 == 0 ) {
struct V_19 * V_20 = V_39 -> V_49 ;
if ( V_4 -> V_5 . V_25 . V_57 == V_58 )
F_13 ( V_20 , V_4 ) ;
else
F_26 ( V_20 , V_20 -> V_50 ,
V_20 -> V_59 , & V_4 -> V_5 ,
V_36 -> V_47 ) ;
V_42 -> V_53 = sizeof( struct V_54 ) ;
V_42 -> V_55 = 0 ;
V_42 -> V_44 = NULL ;
F_27 ( & V_4 -> V_5 ) ;
V_4 = NULL ;
}
}
V_13:
F_3 ( L_8 ,
V_16 , V_46 , V_11 -> V_16 ,
F_28 ( & V_42 -> V_60 -> V_61 -> V_62 ) ) ;
return V_16 - V_46 ;
}
static int F_29 ( struct V_38 * V_39 , T_3 V_47 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_63 * V_64 = V_42 -> V_60 ;
T_1 V_33 ;
struct V_35 V_36 ;
V_36 . V_40 = V_39 ;
V_36 . V_47 = V_47 ;
V_33 . V_36 . V_37 = & V_36 ;
V_33 . error = 0 ;
V_33 . V_65 = 1 ;
F_30 ( V_64 -> V_61 , & V_33 , F_19 ) ;
F_3 ( L_9 , V_42 , V_47 ,
V_33 . error ) ;
return V_33 . error ;
}
int F_31 ( struct V_38 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_63 * V_64 = V_42 -> V_60 ;
int V_12 = 0 ;
F_3 ( L_10 ,
V_39 -> V_66 , V_42 , V_64 ) ;
F_32 ( V_64 -> V_61 ) ;
V_12 = F_29 ( V_39 , V_67 ) ;
F_33 ( V_64 -> V_61 ) ;
return V_12 ;
}
void F_34 ( struct V_64 * V_61 )
{
void (* F_35)( struct V_64 * V_61 );
struct V_38 * V_39 ;
struct V_41 * V_42 ;
F_3 ( L_11 , V_61 ) ;
F_36 ( & V_61 -> V_68 ) ;
V_39 = V_61 -> V_69 ;
if ( ! V_39 ) {
F_35 = V_61 -> V_70 ;
goto V_13;
}
V_42 = V_39 -> V_43 ;
F_35 = V_42 -> V_71 ;
F_37 ( V_72 ) ;
if ( F_29 ( V_39 , V_73 ) == - V_48 )
F_38 ( V_74 , & V_39 -> V_75 , 0 ) ;
V_13:
F_39 ( & V_61 -> V_68 ) ;
F_35 ( V_61 ) ;
}
int F_40 ( void )
{
V_7 = F_41 ( L_12 ,
sizeof( struct V_3 ) ,
0 , 0 , NULL ) ;
if ( ! V_7 )
return - V_48 ;
return 0 ;
}
void F_42 ( void )
{
F_43 ( V_7 ) ;
}
