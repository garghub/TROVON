T_1
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return V_5 -> V_7 [ V_3 ] . V_8 ;
}
static int
F_2 ( struct V_9 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = ( void * ) V_2 -> V_13 ;
T_1 V_14 = V_5 -> V_15 . V_8 + V_12 -> V_16 * 16 ;
int V_17 ;
V_17 = F_3 ( V_2 , 5 ) ;
if ( V_17 == 0 ) {
F_4 ( V_2 , 0 , V_18 , 4 ) ;
F_5 ( V_2 , F_6 ( V_14 ) ) ;
F_5 ( V_2 , F_7 ( V_14 ) ) ;
F_5 ( V_2 , V_6 -> V_19 ) ;
F_5 ( V_2 , V_20 ) ;
F_8 ( V_2 ) ;
}
return V_17 ;
}
static int
F_9 ( struct V_9 * V_6 ,
struct V_1 * V_21 , struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = ( void * ) V_21 -> V_13 ;
T_1 V_14 = V_5 -> V_15 . V_8 + V_12 -> V_16 * 16 ;
int V_17 ;
V_17 = F_3 ( V_2 , 5 ) ;
if ( V_17 == 0 ) {
F_4 ( V_2 , 0 , V_18 , 4 ) ;
F_5 ( V_2 , F_6 ( V_14 ) ) ;
F_5 ( V_2 , F_7 ( V_14 ) ) ;
F_5 ( V_2 , V_6 -> V_19 ) ;
F_5 ( V_2 , V_22 |
V_23 ) ;
F_8 ( V_2 ) ;
}
return V_17 ;
}
static T_2
F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = ( void * ) V_2 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_26 -> V_6 ;
return F_11 ( V_25 -> V_27 , V_12 -> V_16 * 16 / 4 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_26 -> V_29 ;
struct V_24 * V_25 = V_2 -> V_26 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_29 -> V_31 . V_32 ; V_30 ++ ) {
struct V_33 * V_27 = F_13 ( V_29 , V_30 ) ;
F_14 ( V_27 , & V_5 -> V_7 [ V_30 ] ) ;
}
F_14 ( V_25 -> V_27 , & V_5 -> V_15 ) ;
F_15 ( & V_5 -> V_34 ) ;
V_2 -> V_6 = NULL ;
F_16 ( V_5 ) ;
}
static int
F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = ( void * ) V_2 -> V_13 ;
struct V_35 * V_36 = V_35 ( V_12 ) ;
struct V_24 * V_25 = V_2 -> V_26 -> V_6 ;
struct V_4 * V_5 ;
int V_17 , V_30 ;
V_5 = V_2 -> V_6 = F_18 ( sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_38 ;
F_19 ( & V_5 -> V_34 ) ;
V_17 = F_20 ( V_25 -> V_27 , V_36 -> V_39 , & V_5 -> V_15 ) ;
if ( V_17 )
F_12 ( V_2 ) ;
for ( V_30 = 0 ; ! V_17 && V_30 < V_2 -> V_26 -> V_29 -> V_31 . V_32 ; V_30 ++ ) {
struct V_33 * V_27 = F_13 ( V_2 -> V_26 -> V_29 , V_30 ) ;
V_17 = F_20 ( V_27 , V_36 -> V_39 , & V_5 -> V_7 [ V_30 ] ) ;
}
F_21 ( V_25 -> V_27 , V_12 -> V_16 * 16 / 4 , 0x00000000 ) ;
return V_17 ;
}
static bool
F_22 ( struct V_40 * V_26 )
{
struct V_41 * V_42 = V_41 ( V_26 -> V_43 ) ;
struct V_24 * V_25 = V_26 -> V_6 ;
int V_30 ;
V_25 -> V_44 = F_23 ( ( V_42 -> V_45 + 1 ) * sizeof( T_2 ) ) ;
if ( V_25 -> V_44 ) {
for ( V_30 = 0 ; V_30 <= V_42 -> V_45 ; V_30 ++ )
V_25 -> V_44 [ V_30 ] = F_11 ( V_25 -> V_27 , V_30 ) ;
}
return V_25 -> V_44 != NULL ;
}
static void
F_24 ( struct V_40 * V_26 )
{
struct V_41 * V_42 = V_41 ( V_26 -> V_43 ) ;
struct V_24 * V_25 = V_26 -> V_6 ;
int V_30 ;
if ( V_25 -> V_44 ) {
for ( V_30 = 0 ; V_30 <= V_42 -> V_45 ; V_30 ++ )
F_21 ( V_25 -> V_27 , V_30 , V_25 -> V_44 [ V_30 ] ) ;
F_25 ( V_25 -> V_44 ) ;
V_25 -> V_44 = NULL ;
}
}
static void
F_26 ( struct V_40 * V_26 )
{
struct V_24 * V_25 = V_26 -> V_6 ;
F_27 ( V_25 -> V_27 ) ;
if ( V_25 -> V_27 )
F_28 ( V_25 -> V_27 ) ;
F_29 ( NULL , & V_25 -> V_27 ) ;
V_26 -> V_6 = NULL ;
F_16 ( V_25 ) ;
}
int
F_30 ( struct V_40 * V_26 )
{
struct V_41 * V_42 = V_41 ( V_26 -> V_43 ) ;
struct V_24 * V_25 ;
int V_17 ;
V_25 = V_26 -> V_6 = F_18 ( sizeof( * V_25 ) , V_37 ) ;
if ( ! V_25 )
return - V_38 ;
V_25 -> V_34 . V_46 = F_26 ;
V_25 -> V_34 . V_44 = F_22 ;
V_25 -> V_34 . V_47 = F_24 ;
V_25 -> V_34 . V_48 = F_17 ;
V_25 -> V_34 . V_49 = F_12 ;
V_25 -> V_34 . V_50 = F_2 ;
V_25 -> V_34 . V_51 = F_9 ;
V_25 -> V_34 . V_52 = F_10 ;
V_17 = F_31 ( V_26 -> V_29 , 16 * ( V_42 -> V_45 + 1 ) , 0 ,
V_53 , 0 , 0 , NULL , & V_25 -> V_27 ) ;
if ( V_17 == 0 ) {
V_17 = F_32 ( V_25 -> V_27 , V_53 ) ;
if ( V_17 == 0 ) {
V_17 = F_33 ( V_25 -> V_27 ) ;
if ( V_17 )
F_28 ( V_25 -> V_27 ) ;
}
if ( V_17 )
F_29 ( NULL , & V_25 -> V_27 ) ;
}
if ( V_17 )
F_26 ( V_26 ) ;
return V_17 ;
}
