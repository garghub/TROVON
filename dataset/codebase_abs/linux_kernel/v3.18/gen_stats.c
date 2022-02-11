static inline int
F_1 ( struct V_1 * V_2 , int type , void * V_3 , int V_4 )
{
if ( F_2 ( V_2 -> V_5 , type , V_4 , V_3 ) )
goto V_6;
return 0 ;
V_6:
F_3 ( V_2 -> V_7 ) ;
return - 1 ;
}
int
F_4 ( struct V_8 * V_5 , int type , int V_9 ,
int V_10 , T_1 * V_7 , struct V_1 * V_2 )
__acquires( V_7 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_5 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
if ( type )
V_2 -> V_11 = (struct V_12 * ) F_6 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = V_9 ;
V_2 -> V_14 = V_10 ;
if ( V_2 -> V_11 )
return F_1 ( V_2 , type , NULL , 0 ) ;
return 0 ;
}
int
F_7 ( struct V_8 * V_5 , int type , T_1 * V_7 ,
struct V_1 * V_2 )
{
return F_4 ( V_5 , type , 0 , 0 , V_7 , V_2 ) ;
}
static void
F_8 ( struct V_15 * V_16 ,
struct V_17 T_2 * V_18 )
{
int V_19 ;
F_9 (i) {
struct V_17 * V_20 = F_10 ( V_18 , V_19 ) ;
unsigned int V_21 ;
T_3 V_22 ;
T_4 V_23 ;
do {
V_21 = F_11 ( & V_20 -> V_24 ) ;
V_22 = V_20 -> V_16 . V_22 ;
V_23 = V_20 -> V_16 . V_23 ;
} while ( F_12 ( & V_20 -> V_24 , V_21 ) );
V_16 -> V_22 += V_22 ;
V_16 -> V_23 += V_23 ;
}
}
void
F_13 ( struct V_15 * V_16 ,
struct V_17 T_2 * V_18 ,
struct V_15 * V_25 )
{
if ( V_18 ) {
F_8 ( V_16 , V_18 ) ;
} else {
V_16 -> V_22 = V_25 -> V_22 ;
V_16 -> V_23 = V_25 -> V_23 ;
}
}
int
F_14 ( struct V_1 * V_2 ,
struct V_17 T_2 * V_18 ,
struct V_15 * V_25 )
{
struct V_15 V_16 = { 0 } ;
F_13 ( & V_16 , V_18 , V_25 ) ;
if ( V_2 -> V_13 ) {
V_2 -> V_26 . V_22 = V_16 . V_22 ;
V_2 -> V_26 . V_23 = V_16 . V_23 ;
}
if ( V_2 -> V_11 ) {
struct V_27 V_28 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_22 = V_16 . V_22 ;
V_28 . V_23 = V_16 . V_23 ;
return F_1 ( V_2 , V_29 , & V_28 , sizeof( V_28 ) ) ;
}
return 0 ;
}
int
F_15 ( struct V_1 * V_2 ,
const struct V_15 * V_25 ,
struct V_30 * V_31 )
{
struct V_32 V_33 ;
int V_34 ;
if ( V_25 && ! F_16 ( V_25 , V_31 ) )
return 0 ;
V_33 . V_35 = F_17 ( T_3 , V_36 , V_31 -> V_35 ) ;
V_33 . V_37 = V_31 -> V_37 ;
if ( V_2 -> V_13 ) {
V_2 -> V_26 . V_35 = V_33 . V_35 ;
V_2 -> V_26 . V_37 = V_33 . V_37 ;
}
if ( V_2 -> V_11 ) {
V_34 = F_1 ( V_2 , V_38 , & V_33 , sizeof( V_33 ) ) ;
if ( V_34 < 0 || V_33 . V_35 == V_31 -> V_35 )
return V_34 ;
return F_1 ( V_2 , V_39 , V_31 , sizeof( * V_31 ) ) ;
}
return 0 ;
}
static void
F_18 ( struct V_40 * V_41 ,
const struct V_40 T_2 * V_42 )
{
int V_19 ;
F_9 (i) {
const struct V_40 * V_43 = F_10 ( V_42 , V_19 ) ;
V_41 -> V_44 = 0 ;
V_41 -> V_45 += V_43 -> V_45 ;
V_41 -> V_46 += V_43 -> V_46 ;
V_41 -> V_47 += V_43 -> V_47 ;
V_41 -> V_48 += V_43 -> V_48 ;
}
}
static void F_19 ( struct V_40 * V_41 ,
const struct V_40 T_2 * V_18 ,
const struct V_40 * V_42 ,
T_5 V_44 )
{
if ( V_18 ) {
F_18 ( V_41 , V_18 ) ;
} else {
V_41 -> V_44 = V_42 -> V_44 ;
V_41 -> V_45 = V_42 -> V_45 ;
V_41 -> V_46 = V_42 -> V_46 ;
V_41 -> V_47 = V_42 -> V_47 ;
V_41 -> V_48 = V_42 -> V_48 ;
}
V_41 -> V_44 = V_44 ;
}
int
F_20 ( struct V_1 * V_2 ,
struct V_40 T_2 * V_49 ,
struct V_40 * V_42 , T_5 V_44 )
{
struct V_40 V_41 = { 0 } ;
F_19 ( & V_41 , V_49 , V_42 , V_44 ) ;
if ( V_2 -> V_13 ) {
V_2 -> V_26 . V_46 = V_41 . V_46 ;
V_2 -> V_26 . V_44 = V_41 . V_44 ;
V_2 -> V_26 . V_45 = V_41 . V_45 ;
V_2 -> V_26 . V_48 = V_41 . V_48 ;
}
if ( V_2 -> V_11 )
return F_1 ( V_2 , V_50 ,
& V_41 , sizeof( V_41 ) ) ;
return 0 ;
}
int
F_21 ( struct V_1 * V_2 , void * V_51 , int V_52 )
{
if ( V_2 -> V_14 ) {
V_2 -> V_53 = V_51 ;
V_2 -> V_54 = V_52 ;
}
if ( V_2 -> V_11 )
return F_1 ( V_2 , V_55 , V_51 , V_52 ) ;
return 0 ;
}
int
F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_56 = F_6 ( V_2 -> V_5 ) - ( V_57 * ) V_2 -> V_11 ;
if ( V_2 -> V_13 )
if ( F_1 ( V_2 , V_2 -> V_13 , & V_2 -> V_26 ,
sizeof( V_2 -> V_26 ) ) < 0 )
return - 1 ;
if ( V_2 -> V_14 && V_2 -> V_53 ) {
if ( F_1 ( V_2 , V_2 -> V_14 , V_2 -> V_53 ,
V_2 -> V_54 ) < 0 )
return - 1 ;
}
F_3 ( V_2 -> V_7 ) ;
return 0 ;
}
