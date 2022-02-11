static inline int
F_1 ( struct V_1 * V_2 , int type , void * V_3 , int V_4 , int V_5 )
{
if ( F_2 ( V_2 -> V_6 , type , V_4 , V_3 , V_5 ) )
goto V_7;
return 0 ;
V_7:
F_3 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
F_4 ( V_2 -> V_10 ) ;
return - 1 ;
}
int
F_5 ( struct V_11 * V_6 , int type , int V_12 ,
int V_13 , T_1 * V_10 ,
struct V_1 * V_2 , int V_5 )
__acquires( V_10 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_6 ( V_10 ) ;
V_2 -> V_10 = V_10 ;
if ( type )
V_2 -> V_14 = (struct V_15 * ) F_7 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_16 = V_12 ;
V_2 -> V_17 = V_13 ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_14 )
return F_1 ( V_2 , type , NULL , 0 , V_5 ) ;
return 0 ;
}
int
F_8 ( struct V_11 * V_6 , int type , T_1 * V_10 ,
struct V_1 * V_2 , int V_5 )
{
return F_5 ( V_6 , type , 0 , 0 , V_10 , V_2 , V_5 ) ;
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
F_14 ( struct V_18 * V_19 ,
struct V_20 T_2 * V_21 ,
struct V_18 * V_28 )
{
if ( V_21 ) {
F_9 ( V_19 , V_21 ) ;
} else {
V_19 -> V_25 = V_28 -> V_25 ;
V_19 -> V_26 = V_28 -> V_26 ;
}
}
int
F_15 ( struct V_1 * V_2 ,
struct V_20 T_2 * V_21 ,
struct V_18 * V_28 )
{
struct V_18 V_19 = { 0 } ;
F_14 ( & V_19 , V_21 , V_28 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_29 . V_25 = V_19 . V_25 ;
V_2 -> V_29 . V_26 = V_19 . V_26 ;
}
if ( V_2 -> V_14 ) {
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_25 = V_19 . V_25 ;
V_31 . V_26 = V_19 . V_26 ;
return F_1 ( V_2 , V_32 , & V_31 , sizeof( V_31 ) ,
V_33 ) ;
}
return 0 ;
}
int
F_16 ( struct V_1 * V_2 ,
const struct V_18 * V_28 ,
struct V_34 * V_35 )
{
struct V_36 V_37 ;
int V_38 ;
if ( V_28 && ! F_17 ( V_28 , V_35 ) )
return 0 ;
V_37 . V_39 = F_18 ( T_3 , V_40 , V_35 -> V_39 ) ;
V_37 . V_41 = V_35 -> V_41 ;
if ( V_2 -> V_16 ) {
V_2 -> V_29 . V_39 = V_37 . V_39 ;
V_2 -> V_29 . V_41 = V_37 . V_41 ;
}
if ( V_2 -> V_14 ) {
V_38 = F_1 ( V_2 , V_42 , & V_37 , sizeof( V_37 ) ,
V_33 ) ;
if ( V_38 < 0 || V_37 . V_39 == V_35 -> V_39 )
return V_38 ;
return F_1 ( V_2 , V_43 , V_35 , sizeof( * V_35 ) ,
V_33 ) ;
}
return 0 ;
}
static void
F_19 ( struct V_44 * V_45 ,
const struct V_44 T_2 * V_46 )
{
int V_22 ;
F_10 (i) {
const struct V_44 * V_47 = F_11 ( V_46 , V_22 ) ;
V_45 -> V_48 = 0 ;
V_45 -> V_49 += V_47 -> V_49 ;
V_45 -> V_50 += V_47 -> V_50 ;
V_45 -> V_51 += V_47 -> V_51 ;
V_45 -> V_52 += V_47 -> V_52 ;
}
}
static void F_20 ( struct V_44 * V_45 ,
const struct V_44 T_2 * V_21 ,
const struct V_44 * V_46 ,
T_5 V_48 )
{
if ( V_21 ) {
F_19 ( V_45 , V_21 ) ;
} else {
V_45 -> V_48 = V_46 -> V_48 ;
V_45 -> V_49 = V_46 -> V_49 ;
V_45 -> V_50 = V_46 -> V_50 ;
V_45 -> V_51 = V_46 -> V_51 ;
V_45 -> V_52 = V_46 -> V_52 ;
}
V_45 -> V_48 = V_48 ;
}
int
F_21 ( struct V_1 * V_2 ,
struct V_44 T_2 * V_53 ,
struct V_44 * V_46 , T_5 V_48 )
{
struct V_44 V_45 = { 0 } ;
F_20 ( & V_45 , V_53 , V_46 , V_48 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_29 . V_50 = V_45 . V_50 ;
V_2 -> V_29 . V_48 = V_45 . V_48 ;
V_2 -> V_29 . V_49 = V_45 . V_49 ;
V_2 -> V_29 . V_52 = V_45 . V_52 ;
}
if ( V_2 -> V_14 )
return F_1 ( V_2 , V_54 ,
& V_45 , sizeof( V_45 ) ,
V_33 ) ;
return 0 ;
}
int
F_22 ( struct V_1 * V_2 , void * V_55 , int V_56 )
{
if ( V_2 -> V_17 ) {
V_2 -> V_8 = F_23 ( V_55 , V_56 , V_57 ) ;
if ( ! V_2 -> V_8 )
goto V_58;
V_2 -> V_9 = V_56 ;
}
if ( V_2 -> V_14 )
return F_1 ( V_2 , V_59 , V_55 , V_56 ,
V_33 ) ;
return 0 ;
V_58:
V_2 -> V_9 = 0 ;
F_4 ( V_2 -> V_10 ) ;
return - 1 ;
}
int
F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 )
V_2 -> V_14 -> V_60 = F_7 ( V_2 -> V_6 ) - ( V_61 * ) V_2 -> V_14 ;
if ( V_2 -> V_16 )
if ( F_1 ( V_2 , V_2 -> V_16 , & V_2 -> V_29 ,
sizeof( V_2 -> V_29 ) , V_2 -> V_5 ) < 0 )
return - 1 ;
if ( V_2 -> V_17 && V_2 -> V_8 ) {
if ( F_1 ( V_2 , V_2 -> V_17 , V_2 -> V_8 ,
V_2 -> V_9 , V_2 -> V_5 ) < 0 )
return - 1 ;
}
F_3 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
F_4 ( V_2 -> V_10 ) ;
return 0 ;
}
