static inline int
F_1 ( struct V_1 * V_2 , int type , void * V_3 , int V_4 )
{
if ( F_2 ( V_2 -> V_5 , type , V_4 , V_3 ) )
goto V_6;
return 0 ;
V_6:
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
F_4 ( V_2 -> V_9 ) ;
return - 1 ;
}
int
F_5 ( struct V_10 * V_5 , int type , int V_11 ,
int V_12 , T_1 * V_9 , struct V_1 * V_2 )
__acquires( V_9 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_6 ( V_9 ) ;
V_2 -> V_9 = V_9 ;
if ( type )
V_2 -> V_13 = (struct V_14 * ) F_7 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_16 = V_12 ;
if ( V_2 -> V_13 )
return F_1 ( V_2 , type , NULL , 0 ) ;
return 0 ;
}
int
F_8 ( struct V_10 * V_5 , int type , T_1 * V_9 ,
struct V_1 * V_2 )
{
return F_5 ( V_5 , type , 0 , 0 , V_9 , V_2 ) ;
}
static void
F_9 ( struct V_17 * V_18 ,
struct V_19 T_2 * V_20 )
{
int V_21 ;
F_10 (i) {
struct V_19 * V_22 = F_11 ( V_20 , V_21 ) ;
unsigned int V_23 ;
T_3 V_24 ;
T_4 V_25 ;
do {
V_23 = F_12 ( & V_22 -> V_26 ) ;
V_24 = V_22 -> V_18 . V_24 ;
V_25 = V_22 -> V_18 . V_25 ;
} while ( F_13 ( & V_22 -> V_26 , V_23 ) );
V_18 -> V_24 += V_24 ;
V_18 -> V_25 += V_25 ;
}
}
void
F_14 ( struct V_17 * V_18 ,
struct V_19 T_2 * V_20 ,
struct V_17 * V_27 )
{
if ( V_20 ) {
F_9 ( V_18 , V_20 ) ;
} else {
V_18 -> V_24 = V_27 -> V_24 ;
V_18 -> V_25 = V_27 -> V_25 ;
}
}
int
F_15 ( struct V_1 * V_2 ,
struct V_19 T_2 * V_20 ,
struct V_17 * V_27 )
{
struct V_17 V_18 = { 0 } ;
F_14 ( & V_18 , V_20 , V_27 ) ;
if ( V_2 -> V_15 ) {
V_2 -> V_28 . V_24 = V_18 . V_24 ;
V_2 -> V_28 . V_25 = V_18 . V_25 ;
}
if ( V_2 -> V_13 ) {
struct V_29 V_30 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_24 = V_18 . V_24 ;
V_30 . V_25 = V_18 . V_25 ;
return F_1 ( V_2 , V_31 , & V_30 , sizeof( V_30 ) ) ;
}
return 0 ;
}
int
F_16 ( struct V_1 * V_2 ,
const struct V_17 * V_27 ,
struct V_32 * V_33 )
{
struct V_34 V_35 ;
int V_36 ;
if ( V_27 && ! F_17 ( V_27 , V_33 ) )
return 0 ;
V_35 . V_37 = F_18 ( T_3 , V_38 , V_33 -> V_37 ) ;
V_35 . V_39 = V_33 -> V_39 ;
if ( V_2 -> V_15 ) {
V_2 -> V_28 . V_37 = V_35 . V_37 ;
V_2 -> V_28 . V_39 = V_35 . V_39 ;
}
if ( V_2 -> V_13 ) {
V_36 = F_1 ( V_2 , V_40 , & V_35 , sizeof( V_35 ) ) ;
if ( V_36 < 0 || V_35 . V_37 == V_33 -> V_37 )
return V_36 ;
return F_1 ( V_2 , V_41 , V_33 , sizeof( * V_33 ) ) ;
}
return 0 ;
}
static void
F_19 ( struct V_42 * V_43 ,
const struct V_42 T_2 * V_44 )
{
int V_21 ;
F_10 (i) {
const struct V_42 * V_45 = F_11 ( V_44 , V_21 ) ;
V_43 -> V_46 = 0 ;
V_43 -> V_47 += V_45 -> V_47 ;
V_43 -> V_48 += V_45 -> V_48 ;
V_43 -> V_49 += V_45 -> V_49 ;
V_43 -> V_50 += V_45 -> V_50 ;
}
}
static void F_20 ( struct V_42 * V_43 ,
const struct V_42 T_2 * V_20 ,
const struct V_42 * V_44 ,
T_5 V_46 )
{
if ( V_20 ) {
F_19 ( V_43 , V_20 ) ;
} else {
V_43 -> V_46 = V_44 -> V_46 ;
V_43 -> V_47 = V_44 -> V_47 ;
V_43 -> V_48 = V_44 -> V_48 ;
V_43 -> V_49 = V_44 -> V_49 ;
V_43 -> V_50 = V_44 -> V_50 ;
}
V_43 -> V_46 = V_46 ;
}
int
F_21 ( struct V_1 * V_2 ,
struct V_42 T_2 * V_51 ,
struct V_42 * V_44 , T_5 V_46 )
{
struct V_42 V_43 = { 0 } ;
F_20 ( & V_43 , V_51 , V_44 , V_46 ) ;
if ( V_2 -> V_15 ) {
V_2 -> V_28 . V_48 = V_43 . V_48 ;
V_2 -> V_28 . V_46 = V_43 . V_46 ;
V_2 -> V_28 . V_47 = V_43 . V_47 ;
V_2 -> V_28 . V_50 = V_43 . V_50 ;
}
if ( V_2 -> V_13 )
return F_1 ( V_2 , V_52 ,
& V_43 , sizeof( V_43 ) ) ;
return 0 ;
}
int
F_22 ( struct V_1 * V_2 , void * V_53 , int V_54 )
{
if ( V_2 -> V_16 ) {
V_2 -> V_7 = F_23 ( V_53 , V_54 , V_55 ) ;
if ( ! V_2 -> V_7 )
goto V_56;
V_2 -> V_8 = V_54 ;
}
if ( V_2 -> V_13 )
return F_1 ( V_2 , V_57 , V_53 , V_54 ) ;
return 0 ;
V_56:
V_2 -> V_8 = 0 ;
F_4 ( V_2 -> V_9 ) ;
return - 1 ;
}
int
F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 )
V_2 -> V_13 -> V_58 = F_7 ( V_2 -> V_5 ) - ( V_59 * ) V_2 -> V_13 ;
if ( V_2 -> V_15 )
if ( F_1 ( V_2 , V_2 -> V_15 , & V_2 -> V_28 ,
sizeof( V_2 -> V_28 ) ) < 0 )
return - 1 ;
if ( V_2 -> V_16 && V_2 -> V_7 ) {
if ( F_1 ( V_2 , V_2 -> V_16 , V_2 -> V_7 ,
V_2 -> V_8 ) < 0 )
return - 1 ;
}
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
F_4 ( V_2 -> V_9 ) ;
return 0 ;
}
