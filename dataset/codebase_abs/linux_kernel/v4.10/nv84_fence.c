static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , 8 ) ;
if ( V_5 == 0 ) {
F_3 ( V_2 , 0 , V_6 , 1 ) ;
F_4 ( V_2 , V_2 -> V_7 . V_8 ) ;
F_3 ( V_2 , 0 , V_9 , 5 ) ;
F_4 ( V_2 , F_5 ( V_3 ) ) ;
F_4 ( V_2 , F_6 ( V_3 ) ) ;
F_4 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , 0x00000000 ) ;
F_7 ( V_2 ) ;
}
return V_5 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , 7 ) ;
if ( V_5 == 0 ) {
F_3 ( V_2 , 0 , V_6 , 1 ) ;
F_4 ( V_2 , V_2 -> V_7 . V_8 ) ;
F_3 ( V_2 , 0 , V_9 , 4 ) ;
F_4 ( V_2 , F_5 ( V_3 ) ) ;
F_4 ( V_2 , F_6 ( V_3 ) ) ;
F_4 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_11 ) ;
F_7 ( V_2 ) ;
}
return V_5 ;
}
static int
F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
struct V_15 * V_16 = V_2 -> V_13 ;
T_1 V_17 = V_2 -> V_18 * 16 ;
if ( V_13 -> V_19 )
V_17 += V_16 -> V_20 . V_21 ;
else
V_17 += V_16 -> V_22 . V_21 ;
return V_16 -> V_23 . V_24 ( V_2 , V_17 , V_13 -> V_23 . V_25 ) ;
}
static int
F_10 ( struct V_12 * V_13 ,
struct V_1 * V_26 , struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_13 ;
T_1 V_17 = V_26 -> V_18 * 16 ;
if ( V_13 -> V_19 )
V_17 += V_16 -> V_20 . V_21 ;
else
V_17 += V_16 -> V_22 . V_21 ;
return V_16 -> V_23 . V_27 ( V_2 , V_17 , V_13 -> V_23 . V_25 ) ;
}
static T_2
F_11 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 -> V_13 ;
return F_12 ( V_29 -> V_31 , V_2 -> V_18 * 16 / 4 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_30 -> V_13 ;
struct V_15 * V_16 = V_2 -> V_13 ;
F_14 ( V_29 -> V_31 , V_2 -> V_18 * 16 / 4 , V_16 -> V_23 . V_4 ) ;
F_15 ( & V_29 -> V_32 ) ;
F_16 ( V_29 -> V_31 , & V_16 -> V_20 ) ;
F_16 ( V_29 -> V_31 , & V_16 -> V_22 ) ;
F_17 ( & V_29 -> V_32 ) ;
F_18 ( & V_16 -> V_23 ) ;
V_2 -> V_13 = NULL ;
F_19 ( & V_16 -> V_23 ) ;
}
int
F_20 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = ( void * ) V_2 -> V_35 . V_36 ;
struct V_28 * V_29 = V_2 -> V_30 -> V_13 ;
struct V_15 * V_16 ;
int V_5 ;
V_16 = V_2 -> V_13 = F_21 ( sizeof( * V_16 ) , V_37 ) ;
if ( ! V_16 )
return - V_38 ;
F_22 ( V_2 , & V_16 -> V_23 ) ;
V_16 -> V_23 . V_39 = F_9 ;
V_16 -> V_23 . V_40 = F_10 ;
V_16 -> V_23 . V_41 = F_11 ;
V_16 -> V_23 . V_24 = F_1 ;
V_16 -> V_23 . V_27 = F_8 ;
V_16 -> V_23 . V_4 = F_11 ( V_2 ) ;
F_15 ( & V_29 -> V_32 ) ;
V_5 = F_23 ( V_29 -> V_31 , V_34 -> V_42 , & V_16 -> V_22 ) ;
if ( V_5 == 0 ) {
V_5 = F_23 ( V_29 -> V_43 , V_34 -> V_42 ,
& V_16 -> V_20 ) ;
}
F_17 ( & V_29 -> V_32 ) ;
if ( V_5 )
F_13 ( V_2 ) ;
return V_5 ;
}
static bool
F_24 ( struct V_44 * V_30 )
{
struct V_28 * V_29 = V_30 -> V_13 ;
int V_45 ;
V_29 -> V_46 = F_25 ( V_29 -> V_23 . V_47 * sizeof( T_2 ) ) ;
if ( V_29 -> V_46 ) {
for ( V_45 = 0 ; V_45 < V_29 -> V_23 . V_47 ; V_45 ++ )
V_29 -> V_46 [ V_45 ] = F_12 ( V_29 -> V_31 , V_45 * 4 ) ;
}
return V_29 -> V_46 != NULL ;
}
static void
F_26 ( struct V_44 * V_30 )
{
struct V_28 * V_29 = V_30 -> V_13 ;
int V_45 ;
if ( V_29 -> V_46 ) {
for ( V_45 = 0 ; V_45 < V_29 -> V_23 . V_47 ; V_45 ++ )
F_14 ( V_29 -> V_31 , V_45 * 4 , V_29 -> V_46 [ V_45 ] ) ;
F_27 ( V_29 -> V_46 ) ;
V_29 -> V_46 = NULL ;
}
}
static void
F_28 ( struct V_44 * V_30 )
{
struct V_28 * V_29 = V_30 -> V_13 ;
F_29 ( V_29 -> V_43 ) ;
if ( V_29 -> V_43 )
F_30 ( V_29 -> V_43 ) ;
F_31 ( NULL , & V_29 -> V_43 ) ;
F_29 ( V_29 -> V_31 ) ;
if ( V_29 -> V_31 )
F_30 ( V_29 -> V_31 ) ;
F_31 ( NULL , & V_29 -> V_31 ) ;
V_30 -> V_13 = NULL ;
F_32 ( V_29 ) ;
}
int
F_33 ( struct V_44 * V_30 )
{
struct V_48 * V_49 = F_34 ( & V_30 -> V_50 ) ;
struct V_28 * V_29 ;
T_2 V_51 ;
int V_5 ;
V_29 = V_30 -> V_13 = F_21 ( sizeof( * V_29 ) , V_37 ) ;
if ( ! V_29 )
return - V_38 ;
V_29 -> V_23 . V_52 = F_28 ;
V_29 -> V_23 . V_46 = F_24 ;
V_29 -> V_23 . V_53 = F_26 ;
V_29 -> V_23 . V_54 = F_20 ;
V_29 -> V_23 . V_55 = F_13 ;
V_29 -> V_23 . V_47 = V_49 -> V_56 ;
V_29 -> V_23 . V_57 = F_35 ( V_29 -> V_23 . V_47 ) ;
V_29 -> V_23 . V_58 = true ;
F_36 ( & V_29 -> V_32 ) ;
V_51 = V_30 -> V_50 . V_59 . V_60 != 0 ? V_61 :
V_62 | V_63 ;
V_5 = F_37 ( V_30 -> V_64 , 16 * V_29 -> V_23 . V_47 , 0 , V_51 , 0 ,
0 , NULL , NULL , & V_29 -> V_31 ) ;
if ( V_5 == 0 ) {
V_5 = F_38 ( V_29 -> V_31 , V_51 , false ) ;
if ( V_5 == 0 ) {
V_5 = F_39 ( V_29 -> V_31 ) ;
if ( V_5 )
F_30 ( V_29 -> V_31 ) ;
}
if ( V_5 )
F_31 ( NULL , & V_29 -> V_31 ) ;
}
if ( V_5 == 0 )
V_5 = F_37 ( V_30 -> V_64 , 16 * V_29 -> V_23 . V_47 , 0 ,
V_62 | V_63 , 0 ,
0 , NULL , NULL , & V_29 -> V_43 ) ;
if ( V_5 == 0 ) {
V_5 = F_38 ( V_29 -> V_43 , V_62 , false ) ;
if ( V_5 == 0 ) {
V_5 = F_39 ( V_29 -> V_43 ) ;
if ( V_5 )
F_30 ( V_29 -> V_43 ) ;
}
if ( V_5 )
F_31 ( NULL , & V_29 -> V_43 ) ;
}
if ( V_5 )
F_28 ( V_30 ) ;
return V_5 ;
}
