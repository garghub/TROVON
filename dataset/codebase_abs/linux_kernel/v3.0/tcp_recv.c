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
int F_7 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_1 V_10 )
{
struct V_3 * V_4 ;
struct V_8 * V_11 , V_12 ;
struct V_13 * V_14 ;
unsigned long V_15 , V_16 ;
int V_17 = 0 ;
if ( V_10 == 0 )
goto V_18;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
V_11 = V_9 ;
V_12 = * V_11 ;
F_8 (&tinc->ti_skb_list, skb) {
V_16 = 0 ;
while ( V_16 < V_14 -> V_19 ) {
while ( V_12 . V_20 == 0 ) {
V_11 ++ ;
V_12 = * V_11 ;
}
V_15 = F_9 ( V_12 . V_20 , V_10 ) ;
V_15 = F_9 ( V_15 , V_14 -> V_19 - V_16 ) ;
F_3 ( L_3
L_4 ,
V_17 , V_10 , V_14 , V_16 , V_14 -> V_19 ,
V_12 . V_21 , V_12 . V_20 , V_15 ) ;
if ( F_10 ( V_14 , V_16 , & V_12 ,
V_15 ) ) {
V_17 = - V_22 ;
goto V_18;
}
F_11 ( V_23 , V_15 ) ;
V_10 -= V_15 ;
V_17 += V_15 ;
V_16 += V_15 ;
if ( V_10 == 0 )
goto V_18;
}
}
V_18:
return V_17 ;
}
static void F_12 ( struct V_24 * V_25 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 ;
unsigned int V_15 , V_16 ;
unsigned int V_26 ;
unsigned int V_27 ;
struct V_28 * V_29 ;
int V_17 ;
if ( F_13 ( V_4 -> V_5 . V_30 . V_31 ) != V_32 )
return;
V_27 = 0 ;
V_26 = 0 ;
V_29 = V_25 -> V_33 ;
F_8 (&tinc->ti_skb_list, skb) {
V_16 = 0 ;
while ( V_16 < V_14 -> V_19 ) {
V_15 = F_14 (unsigned int, PAGE_SIZE - map_off,
skb->len - skb_off) ;
F_15 ( V_27 >= V_34 ) ;
V_17 = F_16 ( V_14 , V_16 ,
( void * ) V_29 -> V_35 [ V_27 ] + V_26 ,
V_15 ) ;
F_15 ( V_17 != 0 ) ;
V_16 += V_15 ;
V_26 += V_15 ;
if ( V_26 == V_36 ) {
V_26 = 0 ;
V_27 ++ ;
}
}
}
F_17 ( V_29 , ~ ( V_37 ) 0 ) ;
}
static int F_18 ( T_2 * V_38 , struct V_13 * V_14 ,
unsigned int V_39 , T_1 V_19 )
{
struct V_40 * V_41 = V_38 -> V_41 . V_42 ;
struct V_24 * V_25 = V_41 -> V_25 ;
struct V_43 * V_44 = V_25 -> V_45 ;
struct V_3 * V_4 = V_44 -> V_46 ;
struct V_13 * V_47 ;
T_1 V_48 = V_19 , V_15 ;
F_3 ( L_5 , V_44 , V_14 , V_39 ,
V_19 ) ;
while ( V_48 ) {
if ( ! V_4 ) {
V_4 = F_19 ( V_7 ,
V_41 -> V_49 ) ;
if ( ! V_4 ) {
V_38 -> error = - V_50 ;
goto V_18;
}
V_44 -> V_46 = V_4 ;
F_3 ( L_6 , V_4 ) ;
F_20 ( & V_4 -> V_5 , V_25 , V_25 -> V_51 ) ;
F_21 ( & V_4 -> V_6 ) ;
}
if ( V_48 && V_44 -> V_52 ) {
V_15 = F_9 ( V_44 -> V_52 , V_48 ) ;
F_3 ( L_7 , V_15 ,
V_14 ) ;
F_16 ( V_14 , V_39 ,
( char * ) & V_4 -> V_5 . V_30 +
sizeof( struct V_53 ) -
V_44 -> V_52 ,
V_15 ) ;
V_44 -> V_52 -= V_15 ;
V_48 -= V_15 ;
V_39 += V_15 ;
if ( V_44 -> V_52 == 0 ) {
V_44 -> V_54 =
F_13 ( V_4 -> V_5 . V_30 . V_31 ) ;
}
}
if ( V_48 && V_44 -> V_54 ) {
V_47 = F_22 ( V_14 , V_41 -> V_49 ) ;
if ( ! V_47 ) {
V_38 -> error = - V_50 ;
goto V_18;
}
V_15 = F_9 ( V_44 -> V_54 , V_48 ) ;
F_23 ( V_47 , V_39 ) ;
F_24 ( V_47 , V_15 ) ;
F_25 ( & V_4 -> V_6 , V_47 ) ;
F_3 ( L_8
L_9 ,
V_14 , V_14 -> V_42 , V_14 -> V_19 , V_39 , V_15 ,
V_47 , V_47 -> V_42 , V_47 -> V_19 ) ;
V_44 -> V_54 -= V_15 ;
V_48 -= V_15 ;
V_39 += V_15 ;
}
if ( V_44 -> V_52 == 0 && V_44 -> V_54 == 0 ) {
if ( V_4 -> V_5 . V_30 . V_55 == V_56 )
F_12 ( V_25 , V_4 ) ;
else
F_26 ( V_25 , V_25 -> V_51 ,
V_25 -> V_57 , & V_4 -> V_5 ,
V_41 -> V_49 , V_41 -> V_58 ) ;
V_44 -> V_52 = sizeof( struct V_53 ) ;
V_44 -> V_54 = 0 ;
V_44 -> V_46 = NULL ;
F_27 ( & V_4 -> V_5 ) ;
V_4 = NULL ;
}
}
V_18:
F_3 ( L_10 ,
V_19 , V_48 , V_14 -> V_19 ,
F_28 ( & V_44 -> V_59 -> V_60 -> V_61 ) ) ;
return V_19 - V_48 ;
}
static int F_29 ( struct V_24 * V_25 , T_3 V_49 ,
enum V_62 V_58 )
{
struct V_43 * V_44 = V_25 -> V_45 ;
struct V_63 * V_64 = V_44 -> V_59 ;
T_2 V_38 ;
struct V_40 V_41 ;
V_41 . V_25 = V_25 ;
V_41 . V_49 = V_49 ;
V_41 . V_58 = V_58 ;
V_38 . V_41 . V_42 = & V_41 ;
V_38 . error = 0 ;
V_38 . V_65 = 1 ;
F_30 ( V_64 -> V_60 , & V_38 , F_18 ) ;
F_3 ( L_11 , V_44 , V_49 ,
V_38 . error ) ;
return V_38 . error ;
}
int F_31 ( struct V_24 * V_25 )
{
struct V_43 * V_44 = V_25 -> V_45 ;
struct V_63 * V_64 = V_44 -> V_59 ;
int V_17 = 0 ;
F_3 ( L_12 , V_25 , V_44 , V_64 ) ;
F_32 ( V_64 -> V_60 ) ;
V_17 = F_29 ( V_25 , V_66 , V_67 ) ;
F_33 ( V_64 -> V_60 ) ;
return V_17 ;
}
void F_34 ( struct V_64 * V_60 , int V_68 )
{
void (* F_35)( struct V_64 * V_60 , int V_68 );
struct V_24 * V_25 ;
struct V_43 * V_44 ;
F_3 ( L_13 , V_60 , V_68 ) ;
F_36 ( & V_60 -> V_69 ) ;
V_25 = V_60 -> V_70 ;
if ( ! V_25 ) {
F_35 = V_60 -> V_71 ;
goto V_18;
}
V_44 = V_25 -> V_45 ;
F_35 = V_44 -> V_72 ;
F_37 ( V_73 ) ;
if ( F_29 ( V_25 , V_74 , V_75 ) == - V_50 )
F_38 ( V_76 , & V_25 -> V_77 , 0 ) ;
V_18:
F_39 ( & V_60 -> V_69 ) ;
F_35 ( V_60 , V_68 ) ;
}
int F_40 ( void )
{
V_7 = F_41 ( L_14 ,
sizeof( struct V_3 ) ,
0 , 0 , NULL ) ;
if ( ! V_7 )
return - V_50 ;
return 0 ;
}
void F_42 ( void )
{
F_43 ( V_7 ) ;
}
