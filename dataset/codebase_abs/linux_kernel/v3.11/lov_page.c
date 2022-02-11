static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_3 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 != NULL ,
V_4 -> V_7 == V_6 &&
V_6 -> V_8 == V_4 &&
V_4 -> V_9 == V_6 -> V_9 ) ;
}
static void F_4 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_3 * V_6 = F_2 ( V_2 ) ;
F_5 ( F_1 ( V_2 ) ) ;
V_12 ;
if ( V_6 != NULL ) {
F_6 ( V_6 -> V_9 == V_13 ) ;
F_7 ( & V_6 -> V_14 , L_1 , V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
V_2 -> V_5 -> V_7 = NULL ;
F_8 ( V_11 , V_6 ) ;
}
EXIT ;
}
static int F_9 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 )
{
struct V_18 * V_19 = F_10 ( V_11 ) ;
struct V_20 * V_6 ;
F_5 ( F_1 ( V_2 ) ) ;
F_5 ( ! F_11 ( V_2 ) -> V_21 ) ;
V_12 ;
V_6 = F_12 ( V_11 , V_19 , V_2 ) ;
if ( ! F_13 ( V_6 ) ) {
F_2 ( V_2 ) -> V_22 = V_6 -> V_23 ;
F_14 ( V_6 ) ;
} else
F_15 () ;
RETURN ( 0 ) ;
}
static void F_16 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 , struct V_15 * V_16 )
{
F_9 ( V_11 , V_2 , V_16 , 0 ) ;
}
static int F_17 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_18 * V_19 = F_10 ( V_11 ) ;
struct V_20 * V_6 ;
int V_24 = 0 ;
F_5 ( F_1 ( V_2 ) ) ;
F_5 ( ! F_11 ( V_2 ) -> V_21 ) ;
V_12 ;
V_6 = F_12 ( V_11 , V_19 , V_2 ) ;
if ( ! F_13 ( V_6 ) ) {
V_24 = F_18 ( V_6 -> V_25 , V_6 -> V_23 ,
V_2 -> V_5 -> V_7 , V_26 ) ;
F_14 ( V_6 ) ;
} else {
V_24 = F_19 ( V_6 ) ;
F_20 ( V_27 , V_11 , V_2 -> V_5 , L_2 , V_24 ) ;
}
RETURN ( V_24 ) ;
}
static int F_21 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
void * V_28 , T_1 V_29 )
{
struct V_30 * V_31 = F_11 ( V_2 ) ;
return (* V_29)( V_11 , V_28 , V_32 L_3 , V_31 ) ;
}
static void F_22 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_6 ( V_2 -> V_5 -> V_7 == NULL ) ;
}
int F_23 ( const struct V_10 * V_11 , struct V_33 * V_34 ,
struct V_3 * V_4 , struct V_4 * V_35 )
{
struct V_36 * V_37 = F_24 ( V_34 ) ;
struct V_38 * V_39 = F_25 ( V_37 ) ;
struct V_18 * V_19 = F_10 ( V_11 ) ;
struct V_3 * V_40 ;
struct V_33 * V_41 ;
struct V_20 * V_6 ;
struct V_30 * V_42 = F_26 ( V_34 , V_4 ) ;
T_2 V_43 ;
T_3 V_44 ;
int V_45 ;
int V_24 ;
V_12 ;
V_43 = F_27 ( V_34 , V_4 -> V_46 ) ;
V_45 = F_28 ( V_37 -> V_47 , V_43 ) ;
F_6 ( V_45 < V_39 -> V_48 ) ;
V_24 = F_29 ( V_37 -> V_47 , V_43 , V_45 ,
& V_44 ) ;
F_6 ( V_24 == 0 ) ;
V_42 -> V_21 = 1 ;
F_30 ( V_4 , & V_42 -> V_49 , V_34 , & V_50 ) ;
V_6 = F_31 ( V_11 , V_19 , V_45 ) ;
if ( F_13 ( V_6 ) )
GOTO ( V_51 , V_24 = F_19 ( V_6 ) ) ;
V_41 = F_32 ( V_39 -> V_52 [ V_45 ] ) ;
V_40 = F_33 ( V_6 -> V_25 , V_41 ,
F_34 ( V_41 , V_44 ) , V_35 , V_4 ) ;
F_14 ( V_6 ) ;
if ( F_13 ( V_40 ) )
GOTO ( V_51 , V_24 = F_19 ( V_40 ) ) ;
if ( F_35 ( V_40 -> V_8 == V_4 ) ) {
F_36 ( & V_40 -> V_14 , L_1 , V_4 ) ;
V_42 -> V_21 = 0 ;
V_24 = 0 ;
} else {
F_20 ( V_27 , V_11 , V_4 , L_4 ) ;
F_20 ( V_27 , V_11 , V_40 , L_5 ) ;
F_6 ( 0 ) ;
}
EXIT ;
V_51:
return V_24 ;
}
int F_37 ( const struct V_10 * V_11 , struct V_33 * V_34 ,
struct V_3 * V_4 , struct V_4 * V_35 )
{
struct V_30 * V_42 = F_26 ( V_34 , V_4 ) ;
void * V_53 ;
V_12 ;
F_30 ( V_4 , & V_42 -> V_49 , V_34 , & V_54 ) ;
V_53 = F_38 ( V_35 ) ;
memset ( V_53 , 0 , F_39 ( V_34 ) ) ;
F_40 ( V_35 ) ;
F_41 ( V_11 , V_4 , 1 ) ;
RETURN ( 0 ) ;
}
