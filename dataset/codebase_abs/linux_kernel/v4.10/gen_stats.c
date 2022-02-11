static inline int
F_1 ( struct V_1 * V_2 , int type , void * V_3 , int V_4 , int V_5 )
{
if ( F_2 ( V_2 -> V_6 , type , V_4 , V_3 , V_5 ) )
goto V_7;
return 0 ;
V_7:
if ( V_2 -> V_8 )
F_3 ( V_2 -> V_8 ) ;
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = 0 ;
return - 1 ;
}
int
F_5 ( struct V_11 * V_6 , int type , int V_12 ,
int V_13 , T_1 * V_8 ,
struct V_1 * V_2 , int V_5 )
__acquires( V_8 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( type )
V_2 -> V_14 = (struct V_15 * ) F_6 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_16 = V_12 ;
V_2 -> V_17 = V_13 ;
V_2 -> V_5 = V_5 ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
F_7 ( V_8 ) ;
}
if ( V_2 -> V_14 )
return F_1 ( V_2 , type , NULL , 0 , V_5 ) ;
return 0 ;
}
int
F_8 ( struct V_11 * V_6 , int type , T_1 * V_8 ,
struct V_1 * V_2 , int V_5 )
{
return F_5 ( V_6 , type , 0 , 0 , V_8 , V_2 , V_5 ) ;
}
static void
F_9 ( struct V_18 * V_19 ,
struct V_20 T_2 * V_21 )
{
int V_22 ;
F_10 (i) {
struct V_20 * V_23 = F_11 ( V_21 , V_22 ) ;
unsigned int V_24 ;
T_3 V_25 ;
T_4 V_26 ;
do {
V_24 = F_12 ( & V_23 -> V_27 ) ;
V_25 = V_23 -> V_19 . V_25 ;
V_26 = V_23 -> V_19 . V_26 ;
} while ( F_13 ( & V_23 -> V_27 , V_24 ) );
V_19 -> V_25 += V_25 ;
V_19 -> V_26 += V_26 ;
}
}
void
F_14 ( const T_5 * V_28 ,
struct V_18 * V_19 ,
struct V_20 T_2 * V_21 ,
struct V_18 * V_29 )
{
unsigned int V_30 ;
if ( V_21 ) {
F_9 ( V_19 , V_21 ) ;
return;
}
do {
if ( V_28 )
V_30 = F_15 ( V_28 ) ;
V_19 -> V_25 = V_29 -> V_25 ;
V_19 -> V_26 = V_29 -> V_26 ;
} while ( V_28 && F_16 ( V_28 , V_30 ) );
}
int
F_17 ( const T_5 * V_28 ,
struct V_1 * V_2 ,
struct V_20 T_2 * V_21 ,
struct V_18 * V_29 )
{
struct V_18 V_19 = { 0 } ;
F_14 ( V_28 , & V_19 , V_21 , V_29 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_31 . V_25 = V_19 . V_25 ;
V_2 -> V_31 . V_26 = V_19 . V_26 ;
}
if ( V_2 -> V_14 ) {
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_25 = V_19 . V_25 ;
V_33 . V_26 = V_19 . V_26 ;
return F_1 ( V_2 , V_34 , & V_33 , sizeof( V_33 ) ,
V_35 ) ;
}
return 0 ;
}
int
F_18 ( struct V_1 * V_2 ,
struct V_36 T_6 * * V_37 )
{
struct V_38 V_39 ;
struct V_40 V_41 ;
int V_42 ;
if ( ! F_19 ( V_37 , & V_39 ) )
return 0 ;
V_41 . V_43 = F_20 ( T_3 , V_44 , V_39 . V_43 ) ;
V_41 . V_45 = V_39 . V_45 ;
if ( V_2 -> V_16 ) {
V_2 -> V_31 . V_43 = V_41 . V_43 ;
V_2 -> V_31 . V_45 = V_41 . V_45 ;
}
if ( V_2 -> V_14 ) {
V_42 = F_1 ( V_2 , V_46 , & V_41 , sizeof( V_41 ) ,
V_35 ) ;
if ( V_42 < 0 || V_41 . V_43 == V_39 . V_43 )
return V_42 ;
return F_1 ( V_2 , V_47 , & V_39 ,
sizeof( V_39 ) , V_35 ) ;
}
return 0 ;
}
static void
F_21 ( struct V_48 * V_49 ,
const struct V_48 T_2 * V_50 )
{
int V_22 ;
F_10 (i) {
const struct V_48 * V_51 = F_11 ( V_50 , V_22 ) ;
V_49 -> V_52 = 0 ;
V_49 -> V_53 += V_51 -> V_53 ;
V_49 -> V_54 += V_51 -> V_54 ;
V_49 -> V_55 += V_51 -> V_55 ;
V_49 -> V_56 += V_51 -> V_56 ;
}
}
static void F_22 ( struct V_48 * V_49 ,
const struct V_48 T_2 * V_21 ,
const struct V_48 * V_50 ,
T_7 V_52 )
{
if ( V_21 ) {
F_21 ( V_49 , V_21 ) ;
} else {
V_49 -> V_52 = V_50 -> V_52 ;
V_49 -> V_53 = V_50 -> V_53 ;
V_49 -> V_54 = V_50 -> V_54 ;
V_49 -> V_55 = V_50 -> V_55 ;
V_49 -> V_56 = V_50 -> V_56 ;
}
V_49 -> V_52 = V_52 ;
}
int
F_23 ( struct V_1 * V_2 ,
struct V_48 T_2 * V_57 ,
struct V_48 * V_50 , T_7 V_52 )
{
struct V_48 V_49 = { 0 } ;
F_22 ( & V_49 , V_57 , V_50 , V_52 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_31 . V_54 = V_49 . V_54 ;
V_2 -> V_31 . V_52 = V_49 . V_52 ;
V_2 -> V_31 . V_53 = V_49 . V_53 ;
V_2 -> V_31 . V_56 = V_49 . V_56 ;
}
if ( V_2 -> V_14 )
return F_1 ( V_2 , V_58 ,
& V_49 , sizeof( V_49 ) ,
V_35 ) ;
return 0 ;
}
int
F_24 ( struct V_1 * V_2 , void * V_59 , int V_60 )
{
if ( V_2 -> V_17 ) {
V_2 -> V_9 = F_25 ( V_59 , V_60 , V_61 ) ;
if ( ! V_2 -> V_9 )
goto V_62;
V_2 -> V_10 = V_60 ;
}
if ( V_2 -> V_14 )
return F_1 ( V_2 , V_63 , V_59 , V_60 ,
V_35 ) ;
return 0 ;
V_62:
if ( V_2 -> V_8 )
F_3 ( V_2 -> V_8 ) ;
V_2 -> V_10 = 0 ;
return - 1 ;
}
int
F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 )
V_2 -> V_14 -> V_64 = F_6 ( V_2 -> V_6 ) - ( V_65 * ) V_2 -> V_14 ;
if ( V_2 -> V_16 )
if ( F_1 ( V_2 , V_2 -> V_16 , & V_2 -> V_31 ,
sizeof( V_2 -> V_31 ) , V_2 -> V_5 ) < 0 )
return - 1 ;
if ( V_2 -> V_17 && V_2 -> V_9 ) {
if ( F_1 ( V_2 , V_2 -> V_17 , V_2 -> V_9 ,
V_2 -> V_10 , V_2 -> V_5 ) < 0 )
return - 1 ;
}
if ( V_2 -> V_8 )
F_3 ( V_2 -> V_8 ) ;
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = 0 ;
return 0 ;
}
