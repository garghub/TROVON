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
if ( F_13 ( V_2 -> V_26 -> V_31 ) -> V_32 >= V_33 ) {
for ( V_30 = 0 ; V_30 < V_29 -> V_34 . V_35 ; V_30 ++ ) {
struct V_36 * V_27 = F_14 ( V_29 , V_30 ) ;
F_15 ( V_27 , & V_5 -> V_7 [ V_30 ] ) ;
}
} else
if ( F_13 ( V_2 -> V_26 -> V_31 ) -> V_32 >= V_37 ) {
for ( V_30 = 0 ; V_30 < V_29 -> V_34 . V_35 ; V_30 ++ ) {
struct V_36 * V_27 = F_16 ( V_29 , V_30 ) ;
F_15 ( V_27 , & V_5 -> V_7 [ V_30 ] ) ;
}
}
F_15 ( V_25 -> V_27 , & V_5 -> V_15 ) ;
F_17 ( & V_5 -> V_38 ) ;
V_2 -> V_6 = NULL ;
F_18 ( V_5 ) ;
}
static int
F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = ( void * ) V_2 -> V_13 ;
struct V_39 * V_40 = V_39 ( V_12 ) ;
struct V_24 * V_25 = V_2 -> V_26 -> V_6 ;
struct V_4 * V_5 ;
int V_17 , V_30 ;
V_5 = V_2 -> V_6 = F_20 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
F_21 ( & V_5 -> V_38 ) ;
V_17 = F_22 ( V_25 -> V_27 , V_40 -> V_43 , & V_5 -> V_15 ) ;
if ( V_17 )
F_12 ( V_2 ) ;
for ( V_30 = 0 ; ! V_17 && V_30 < V_2 -> V_26 -> V_29 -> V_34 . V_35 ; V_30 ++ ) {
struct V_36 * V_27 ;
if ( F_13 ( V_2 -> V_26 -> V_31 ) -> V_32 >= V_33 )
V_27 = F_14 ( V_2 -> V_26 -> V_29 , V_30 ) ;
else
V_27 = F_16 ( V_2 -> V_26 -> V_29 , V_30 ) ;
V_17 = F_22 ( V_27 , V_40 -> V_43 , & V_5 -> V_7 [ V_30 ] ) ;
}
F_23 ( V_25 -> V_27 , V_12 -> V_16 * 16 / 4 , 0x00000000 ) ;
return V_17 ;
}
static bool
F_24 ( struct V_44 * V_26 )
{
struct V_45 * V_46 = V_45 ( V_26 -> V_31 ) ;
struct V_24 * V_25 = V_26 -> V_6 ;
int V_30 ;
V_25 -> V_47 = F_25 ( ( V_46 -> V_48 + 1 ) * sizeof( T_2 ) ) ;
if ( V_25 -> V_47 ) {
for ( V_30 = 0 ; V_30 <= V_46 -> V_48 ; V_30 ++ )
V_25 -> V_47 [ V_30 ] = F_11 ( V_25 -> V_27 , V_30 ) ;
}
return V_25 -> V_47 != NULL ;
}
static void
F_26 ( struct V_44 * V_26 )
{
struct V_45 * V_46 = V_45 ( V_26 -> V_31 ) ;
struct V_24 * V_25 = V_26 -> V_6 ;
int V_30 ;
if ( V_25 -> V_47 ) {
for ( V_30 = 0 ; V_30 <= V_46 -> V_48 ; V_30 ++ )
F_23 ( V_25 -> V_27 , V_30 , V_25 -> V_47 [ V_30 ] ) ;
F_27 ( V_25 -> V_47 ) ;
V_25 -> V_47 = NULL ;
}
}
static void
F_28 ( struct V_44 * V_26 )
{
struct V_24 * V_25 = V_26 -> V_6 ;
F_29 ( V_25 -> V_27 ) ;
F_30 ( NULL , & V_25 -> V_27 ) ;
V_26 -> V_6 = NULL ;
F_18 ( V_25 ) ;
}
int
F_31 ( struct V_44 * V_26 )
{
struct V_45 * V_46 = V_45 ( V_26 -> V_31 ) ;
struct V_24 * V_25 ;
int V_17 ;
V_25 = V_26 -> V_6 = F_20 ( sizeof( * V_25 ) , V_41 ) ;
if ( ! V_25 )
return - V_42 ;
V_25 -> V_38 . V_49 = F_28 ;
V_25 -> V_38 . V_47 = F_24 ;
V_25 -> V_38 . V_50 = F_26 ;
V_25 -> V_38 . V_51 = F_19 ;
V_25 -> V_38 . V_52 = F_12 ;
V_25 -> V_38 . V_53 = F_2 ;
V_25 -> V_38 . V_54 = F_9 ;
V_25 -> V_38 . V_55 = F_10 ;
V_17 = F_32 ( V_26 -> V_29 , 16 * ( V_46 -> V_48 + 1 ) , 0 ,
V_56 , 0 , 0 , NULL , & V_25 -> V_27 ) ;
if ( V_17 == 0 ) {
V_17 = F_33 ( V_25 -> V_27 , V_56 ) ;
if ( V_17 == 0 )
V_17 = F_34 ( V_25 -> V_27 ) ;
if ( V_17 )
F_30 ( NULL , & V_25 -> V_27 ) ;
}
if ( V_17 )
F_28 ( V_26 ) ;
return V_17 ;
}
