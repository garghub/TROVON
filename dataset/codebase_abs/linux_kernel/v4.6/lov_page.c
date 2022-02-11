static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_3 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 ,
V_4 -> V_7 == V_6 &&
V_6 -> V_8 == V_4 &&
V_4 -> V_9 == V_6 -> V_9 ) ;
}
static void F_4 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_3 * V_6 = F_2 ( V_2 ) ;
F_5 ( F_1 ( V_2 ) ) ;
if ( V_6 ) {
F_6 ( V_6 -> V_9 == V_12 ) ;
F_7 ( & V_6 -> V_13 , L_1 , V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
V_2 -> V_5 -> V_7 = NULL ;
F_8 ( V_11 , V_6 ) ;
}
}
static int F_9 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 )
{
struct V_17 * V_18 = F_10 ( V_11 ) ;
struct V_19 * V_6 ;
F_5 ( F_1 ( V_2 ) ) ;
F_5 ( ! F_11 ( V_2 ) -> V_20 ) ;
V_6 = F_12 ( V_11 , V_18 , V_2 ) ;
if ( ! F_13 ( V_6 ) ) {
F_2 ( V_2 ) -> V_21 = V_6 -> V_22 ;
F_14 ( V_6 ) ;
} else
F_15 () ;
return 0 ;
}
static void F_16 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 , struct V_14 * V_15 )
{
F_9 ( V_11 , V_2 , V_15 , 0 ) ;
}
static int F_17 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_17 * V_18 = F_10 ( V_11 ) ;
struct V_19 * V_6 ;
int V_23 = 0 ;
F_5 ( F_1 ( V_2 ) ) ;
F_5 ( ! F_11 ( V_2 ) -> V_20 ) ;
V_6 = F_12 ( V_11 , V_18 , V_2 ) ;
if ( ! F_13 ( V_6 ) ) {
V_23 = F_18 ( V_6 -> V_24 , V_6 -> V_22 ,
V_2 -> V_5 -> V_7 , V_25 ) ;
F_14 ( V_6 ) ;
} else {
V_23 = F_19 ( V_6 ) ;
F_20 ( V_26 , V_11 , V_2 -> V_5 , L_2 , V_23 ) ;
}
return V_23 ;
}
static int F_21 ( const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
void * V_27 , T_1 V_28 )
{
struct V_29 * V_30 = F_11 ( V_2 ) ;
return (* V_28)( V_11 , V_27 , V_31 L_3 , V_30 ) ;
}
static void F_22 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
F_6 ( ! V_2 -> V_5 -> V_7 ) ;
}
int F_23 ( const struct V_10 * V_11 , struct V_32 * V_33 ,
struct V_3 * V_4 , struct V_4 * V_34 )
{
struct V_35 * V_36 = F_24 ( V_33 ) ;
struct V_37 * V_38 = F_25 ( V_36 ) ;
struct V_17 * V_18 = F_10 ( V_11 ) ;
struct V_3 * V_39 ;
struct V_32 * V_40 ;
struct V_19 * V_6 ;
struct V_29 * V_41 = F_26 ( V_33 , V_4 ) ;
T_2 V_42 ;
T_3 V_43 ;
int V_44 ;
int V_23 ;
V_42 = F_27 ( V_33 , V_4 -> V_45 ) ;
V_44 = F_28 ( V_36 -> V_46 , V_42 ) ;
F_6 ( V_44 < V_38 -> V_47 ) ;
V_23 = F_29 ( V_36 -> V_46 , V_42 , V_44 , & V_43 ) ;
F_6 ( V_23 == 0 ) ;
V_41 -> V_20 = 1 ;
F_30 ( V_4 , & V_41 -> V_48 , V_33 , & V_49 ) ;
V_6 = F_31 ( V_11 , V_18 , V_44 ) ;
if ( F_13 ( V_6 ) ) {
V_23 = F_19 ( V_6 ) ;
goto V_50;
}
V_40 = F_32 ( V_38 -> V_51 [ V_44 ] ) ;
V_39 = F_33 ( V_6 -> V_24 , V_40 ,
F_34 ( V_40 , V_43 ) , V_34 , V_4 ) ;
F_14 ( V_6 ) ;
if ( F_13 ( V_39 ) ) {
V_23 = F_19 ( V_39 ) ;
goto V_50;
}
if ( F_35 ( V_39 -> V_8 == V_4 ) ) {
F_36 ( & V_39 -> V_13 , L_1 , V_4 ) ;
V_41 -> V_20 = 0 ;
V_23 = 0 ;
} else {
F_20 ( V_26 , V_11 , V_4 , L_4 ) ;
F_20 ( V_26 , V_11 , V_39 , L_5 ) ;
F_6 ( 0 ) ;
}
V_50:
return V_23 ;
}
int F_37 ( const struct V_10 * V_11 , struct V_32 * V_33 ,
struct V_3 * V_4 , struct V_4 * V_34 )
{
struct V_29 * V_41 = F_26 ( V_33 , V_4 ) ;
void * V_52 ;
F_30 ( V_4 , & V_41 -> V_48 , V_33 , & V_53 ) ;
V_52 = F_38 ( V_34 ) ;
memset ( V_52 , 0 , F_39 ( V_33 ) ) ;
F_40 ( V_34 ) ;
F_41 ( V_11 , V_4 , 1 ) ;
return 0 ;
}
