T_1
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return V_5 -> V_7 [ V_3 ] . V_8 ;
}
static int
F_2 ( struct V_1 * V_2 , T_1 V_9 , T_2 V_10 )
{
int V_11 = F_3 ( V_2 , 8 ) ;
if ( V_11 == 0 ) {
F_4 ( V_2 , 0 , V_12 , 1 ) ;
F_5 ( V_2 , V_2 -> V_13 . V_14 ) ;
F_4 ( V_2 , 0 , V_15 , 5 ) ;
F_5 ( V_2 , F_6 ( V_9 ) ) ;
F_5 ( V_2 , F_7 ( V_9 ) ) ;
F_5 ( V_2 , V_10 ) ;
F_5 ( V_2 , V_16 ) ;
F_5 ( V_2 , 0x00000000 ) ;
F_8 ( V_2 ) ;
}
return V_11 ;
}
static int
F_9 ( struct V_1 * V_2 , T_1 V_9 , T_2 V_10 )
{
int V_11 = F_3 ( V_2 , 7 ) ;
if ( V_11 == 0 ) {
F_4 ( V_2 , 0 , V_12 , 1 ) ;
F_5 ( V_2 , V_2 -> V_13 . V_14 ) ;
F_4 ( V_2 , 0 , V_15 , 4 ) ;
F_5 ( V_2 , F_6 ( V_9 ) ) ;
F_5 ( V_2 , F_7 ( V_9 ) ) ;
F_5 ( V_2 , V_10 ) ;
F_5 ( V_2 , V_17 ) ;
F_8 ( V_2 ) ;
}
return V_11 ;
}
static int
F_10 ( struct V_18 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_19 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_20 = V_2 -> V_21 * 16 ;
if ( V_6 -> V_22 )
V_20 += V_5 -> V_23 . V_8 ;
else
V_20 += V_5 -> V_24 . V_8 ;
return V_5 -> V_25 . V_26 ( V_2 , V_20 , V_6 -> V_25 . V_27 ) ;
}
static int
F_11 ( struct V_18 * V_6 ,
struct V_1 * V_28 , struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_20 = V_28 -> V_21 * 16 ;
if ( V_6 -> V_22 )
V_20 += V_5 -> V_23 . V_8 ;
else
V_20 += V_5 -> V_24 . V_8 ;
return V_5 -> V_25 . V_29 ( V_2 , V_20 , V_6 -> V_25 . V_27 ) ;
}
static T_2
F_12 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 -> V_6 ;
return F_13 ( V_31 -> V_33 , V_2 -> V_21 * 16 / 4 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_32 -> V_35 ;
struct V_30 * V_31 = V_2 -> V_32 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 -> V_37 . V_38 ; V_36 ++ ) {
struct V_39 * V_33 = F_15 ( V_35 , V_36 ) ;
F_16 ( V_33 , & V_5 -> V_7 [ V_36 ] ) ;
}
F_17 ( V_31 -> V_33 , V_2 -> V_21 * 16 / 4 , V_5 -> V_25 . V_10 ) ;
F_16 ( V_31 -> V_33 , & V_5 -> V_23 ) ;
F_16 ( V_31 -> V_33 , & V_5 -> V_24 ) ;
F_18 ( & V_5 -> V_25 ) ;
V_2 -> V_6 = NULL ;
F_19 ( & V_5 -> V_25 ) ;
}
int
F_20 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = ( void * ) F_21 ( & V_2 -> V_42 -> V_25 ) ;
struct V_30 * V_31 = V_2 -> V_32 -> V_6 ;
struct V_4 * V_5 ;
int V_11 , V_36 ;
V_5 = V_2 -> V_6 = F_22 ( sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 )
return - V_44 ;
F_23 ( V_2 , & V_5 -> V_25 ) ;
V_5 -> V_25 . V_45 = F_10 ;
V_5 -> V_25 . V_46 = F_11 ;
V_5 -> V_25 . V_47 = F_12 ;
V_5 -> V_25 . V_26 = F_2 ;
V_5 -> V_25 . V_29 = F_9 ;
V_5 -> V_25 . V_10 = F_12 ( V_2 ) ;
V_11 = F_24 ( V_31 -> V_33 , V_41 -> V_48 , & V_5 -> V_24 ) ;
if ( V_11 == 0 ) {
V_11 = F_24 ( V_31 -> V_49 , V_41 -> V_48 ,
& V_5 -> V_23 ) ;
}
for ( V_36 = 0 ; ! V_11 && V_36 < V_2 -> V_32 -> V_35 -> V_37 . V_38 ; V_36 ++ ) {
struct V_39 * V_33 = F_15 ( V_2 -> V_32 -> V_35 , V_36 ) ;
V_11 = F_24 ( V_33 , V_41 -> V_48 , & V_5 -> V_7 [ V_36 ] ) ;
}
if ( V_11 )
F_14 ( V_2 ) ;
return V_11 ;
}
static bool
F_25 ( struct V_50 * V_32 )
{
struct V_30 * V_31 = V_32 -> V_6 ;
int V_36 ;
V_31 -> V_51 = F_26 ( V_31 -> V_25 . V_52 * sizeof( T_2 ) ) ;
if ( V_31 -> V_51 ) {
for ( V_36 = 0 ; V_36 < V_31 -> V_25 . V_52 ; V_36 ++ )
V_31 -> V_51 [ V_36 ] = F_13 ( V_31 -> V_33 , V_36 * 4 ) ;
}
return V_31 -> V_51 != NULL ;
}
static void
F_27 ( struct V_50 * V_32 )
{
struct V_30 * V_31 = V_32 -> V_6 ;
int V_36 ;
if ( V_31 -> V_51 ) {
for ( V_36 = 0 ; V_36 < V_31 -> V_25 . V_52 ; V_36 ++ )
F_17 ( V_31 -> V_33 , V_36 * 4 , V_31 -> V_51 [ V_36 ] ) ;
F_28 ( V_31 -> V_51 ) ;
V_31 -> V_51 = NULL ;
}
}
static void
F_29 ( struct V_50 * V_32 )
{
struct V_30 * V_31 = V_32 -> V_6 ;
F_30 ( V_31 -> V_49 ) ;
if ( V_31 -> V_49 )
F_31 ( V_31 -> V_49 ) ;
F_32 ( NULL , & V_31 -> V_49 ) ;
F_30 ( V_31 -> V_33 ) ;
if ( V_31 -> V_33 )
F_31 ( V_31 -> V_33 ) ;
F_32 ( NULL , & V_31 -> V_33 ) ;
V_32 -> V_6 = NULL ;
F_33 ( V_31 ) ;
}
int
F_34 ( struct V_50 * V_32 )
{
struct V_53 * V_54 = F_35 ( & V_32 -> V_42 ) ;
struct V_30 * V_31 ;
T_2 V_55 ;
int V_11 ;
V_31 = V_32 -> V_6 = F_22 ( sizeof( * V_31 ) , V_43 ) ;
if ( ! V_31 )
return - V_44 ;
V_31 -> V_25 . V_56 = F_29 ;
V_31 -> V_25 . V_51 = F_25 ;
V_31 -> V_25 . V_57 = F_27 ;
V_31 -> V_25 . V_58 = F_20 ;
V_31 -> V_25 . V_59 = F_14 ;
V_31 -> V_25 . V_52 = V_54 -> V_60 + 1 ;
V_31 -> V_25 . V_61 = F_36 ( V_31 -> V_25 . V_52 ) ;
V_31 -> V_25 . V_62 = true ;
V_55 = V_32 -> V_42 . V_63 . V_64 != 0 ? V_65 :
V_66 | V_67 ;
V_11 = F_37 ( V_32 -> V_35 , 16 * V_31 -> V_25 . V_52 , 0 , V_55 , 0 ,
0 , NULL , NULL , & V_31 -> V_33 ) ;
if ( V_11 == 0 ) {
V_11 = F_38 ( V_31 -> V_33 , V_55 , false ) ;
if ( V_11 == 0 ) {
V_11 = F_39 ( V_31 -> V_33 ) ;
if ( V_11 )
F_31 ( V_31 -> V_33 ) ;
}
if ( V_11 )
F_32 ( NULL , & V_31 -> V_33 ) ;
}
if ( V_11 == 0 )
V_11 = F_37 ( V_32 -> V_35 , 16 * V_31 -> V_25 . V_52 , 0 ,
V_66 | V_67 , 0 ,
0 , NULL , NULL , & V_31 -> V_49 ) ;
if ( V_11 == 0 ) {
V_11 = F_38 ( V_31 -> V_49 , V_66 , false ) ;
if ( V_11 == 0 ) {
V_11 = F_39 ( V_31 -> V_49 ) ;
if ( V_11 )
F_31 ( V_31 -> V_49 ) ;
}
if ( V_11 )
F_32 ( NULL , & V_31 -> V_49 ) ;
}
if ( V_11 )
F_29 ( V_32 ) ;
return V_11 ;
}
