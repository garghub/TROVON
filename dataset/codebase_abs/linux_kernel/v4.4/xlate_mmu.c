static void F_1 ( struct V_1 * * V_2 , unsigned V_3 ,
T_1 V_4 , void * V_5 )
{
unsigned long V_6 = 0 ;
struct V_1 * V_1 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
if ( ( V_7 % V_8 ) == 0 ) {
V_1 = V_2 [ V_7 / V_8 ] ;
V_6 = F_2 ( V_1 ) ;
}
V_4 ( F_3 ( V_6 ++ ) , V_5 ) ;
}
}
static void F_4 ( unsigned long V_9 , void * V_5 )
{
struct V_10 * V_11 = V_5 ;
V_11 -> V_12 [ V_11 -> V_13 ] = * V_11 -> V_14 ;
V_11 -> V_15 [ V_11 -> V_13 ] = V_9 ;
V_11 -> V_16 [ V_11 -> V_13 ] = 0 ;
V_11 -> V_13 ++ ;
V_11 -> V_14 ++ ;
}
static int F_5 ( T_2 * V_17 , T_3 V_18 , unsigned long V_19 ,
void * V_5 )
{
struct V_10 * V_11 = V_5 ;
struct V_1 * V_1 = V_11 -> V_2 [ V_11 -> V_20 ++ ] ;
T_2 V_21 = F_6 ( F_7 ( F_8 ( V_1 ) , V_11 -> V_22 ) ) ;
int V_23 , V_3 ;
T_4 V_7 ;
struct V_24 V_25 = {
. V_26 = V_27 ,
. V_28 = V_11 -> V_26 ,
. V_29 = V_30 ,
} ;
V_3 = F_9 ( F_10 ( V_11 -> V_31 ) , V_8 , V_11 -> V_31 ) ;
V_11 -> V_31 -= V_3 ;
V_11 -> V_13 = 0 ;
F_1 ( & V_1 , V_3 , F_4 , V_11 ) ;
F_11 ( V_11 -> V_13 != V_3 ) ;
F_12 ( V_25 . V_32 , V_11 -> V_12 ) ;
F_12 ( V_25 . V_33 , V_11 -> V_15 ) ;
F_12 ( V_25 . V_34 , V_11 -> V_16 ) ;
V_25 . V_35 = V_3 ;
V_23 = F_13 ( V_36 , & V_25 ) ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
int V_37 = ( V_23 < 0 ) ? V_23 : V_11 -> V_16 [ V_7 ] ;
* ( V_11 -> V_38 ++ ) = V_37 ;
if ( ! V_37 )
V_11 -> V_39 ++ ;
}
if ( ! V_23 )
F_14 ( V_11 -> V_40 -> V_41 , V_19 , V_17 , V_21 ) ;
return 0 ;
}
int F_15 ( struct V_42 * V_40 ,
unsigned long V_19 ,
T_5 * V_9 , int V_43 ,
int * V_38 , T_6 V_22 ,
unsigned V_26 ,
struct V_1 * * V_2 )
{
int V_37 ;
struct V_10 V_5 ;
unsigned long V_44 = F_16 ( V_43 , V_8 ) << V_45 ;
F_11 ( ! ( ( V_40 -> V_46 & ( V_47 | V_48 ) ) == ( V_47 | V_48 ) ) ) ;
V_5 . V_14 = V_9 ;
V_5 . V_31 = V_43 ;
V_5 . V_22 = V_22 ;
V_5 . V_26 = V_26 ;
V_5 . V_40 = V_40 ;
V_5 . V_2 = V_2 ;
V_5 . V_20 = 0 ;
V_5 . V_38 = V_38 ;
V_5 . V_39 = 0 ;
V_37 = F_17 ( V_40 -> V_41 , V_19 , V_44 ,
F_5 , & V_5 ) ;
return V_37 < 0 ? V_37 : V_5 . V_39 ;
}
static void F_18 ( unsigned long V_9 , void * V_5 )
{
struct V_49 V_50 ;
V_50 . V_26 = V_27 ;
V_50 . V_51 = V_9 ;
( void ) F_13 ( V_52 , & V_50 ) ;
}
int F_19 ( struct V_42 * V_40 ,
int V_43 , struct V_1 * * V_2 )
{
F_1 ( V_2 , V_43 , F_18 , NULL ) ;
return 0 ;
}
