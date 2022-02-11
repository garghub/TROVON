T_1 F_1 ( const struct V_1 * V_1 ,
const struct V_2 * V_3 , const T_2 V_4 ,
const struct V_2 * V_5 , const T_3 V_6 )
{
static T_1 T_4 V_7 ;
static T_1 T_5 V_7 ;
T_1 V_8 , V_9 ;
F_2 ( & T_4 , sizeof( T_4 ) ) ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
V_8 = ( V_10 T_1 ) V_3 -> V_11 [ 3 ] ;
V_9 = F_3 ( V_5 , T_5 ) ;
return F_4 ( V_8 , V_4 , V_9 , V_6 ,
T_4 + F_5 ( V_1 ) ) ;
}
struct V_12 * F_6 ( struct V_1 * V_1 ,
struct V_13 * V_14 ,
const struct V_2 * V_15 ,
const T_3 V_16 ,
const struct V_2 * V_17 ,
const T_2 V_18 ,
const int V_19 )
{
struct V_12 * V_20 ;
const struct V_21 * V_22 ;
const T_6 V_23 = F_7 ( V_16 , V_18 ) ;
unsigned int V_24 = F_1 ( V_1 , V_17 , V_18 , V_15 , V_16 ) ;
unsigned int V_25 = V_24 & V_14 -> V_26 ;
struct V_27 * V_28 = & V_14 -> V_29 [ V_25 ] ;
F_8 () ;
V_30:
F_9 (sk, node, &head->chain) {
if ( V_20 -> V_31 != V_24 )
continue;
if ( ! F_10 ( V_20 , V_1 , V_15 , V_17 , V_23 , V_19 ) )
continue;
if ( F_11 ( ! F_12 ( & V_20 -> V_32 ) ) )
goto V_33;
if ( F_11 ( ! F_10 ( V_20 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
F_13 ( V_20 ) ;
goto V_30;
}
goto V_34;
}
if ( F_14 ( V_22 ) != V_25 )
goto V_30;
V_33:
V_20 = NULL ;
V_34:
F_15 () ;
return V_20 ;
}
static inline int F_16 ( struct V_12 * V_20 , struct V_1 * V_1 ,
const unsigned short V_18 ,
const struct V_2 * V_17 ,
const int V_19 )
{
int V_35 = - 1 ;
if ( F_17 ( F_18 ( V_20 ) , V_1 ) && F_19 ( V_20 ) -> V_36 == V_18 &&
V_20 -> V_37 == V_38 ) {
V_35 = 1 ;
if ( ! F_20 ( & V_20 -> V_39 ) ) {
if ( ! F_21 ( & V_20 -> V_39 , V_17 ) )
return - 1 ;
V_35 ++ ;
}
if ( V_20 -> V_40 ) {
if ( V_20 -> V_40 != V_19 )
return - 1 ;
V_35 ++ ;
}
if ( V_20 -> V_41 == F_22 () )
V_35 ++ ;
}
return V_35 ;
}
struct V_12 * F_23 ( struct V_1 * V_1 ,
struct V_13 * V_14 , const struct V_2 * V_15 ,
const T_3 V_16 , const struct V_2 * V_17 ,
const unsigned short V_18 , const int V_19 )
{
struct V_12 * V_20 ;
const struct V_21 * V_22 ;
struct V_12 * V_42 ;
int V_35 , V_43 , V_44 = 0 , V_45 = 0 ;
T_1 V_46 = 0 ;
unsigned int V_24 = F_24 ( V_1 , V_18 ) ;
struct V_47 * V_48 = & V_14 -> V_49 [ V_24 ] ;
F_8 () ;
V_30:
V_42 = NULL ;
V_43 = 0 ;
F_25 (sk, node, &ilb->head) {
V_35 = F_16 ( V_20 , V_1 , V_18 , V_17 , V_19 ) ;
if ( V_35 > V_43 ) {
V_43 = V_35 ;
V_42 = V_20 ;
V_45 = V_20 -> V_50 ;
if ( V_45 ) {
V_46 = F_1 ( V_1 , V_17 , V_18 ,
V_15 , V_16 ) ;
V_44 = 1 ;
}
} else if ( V_35 == V_43 && V_45 ) {
V_44 ++ ;
if ( F_26 ( V_46 , V_44 ) == 0 )
V_42 = V_20 ;
V_46 = F_27 ( V_46 ) ;
}
}
if ( F_14 ( V_22 ) != V_24 + V_51 )
goto V_30;
if ( V_42 ) {
if ( F_11 ( ! F_12 ( & V_42 -> V_32 ) ) )
V_42 = NULL ;
else if ( F_11 ( F_16 ( V_42 , V_1 , V_18 , V_17 ,
V_19 ) < V_43 ) ) {
F_28 ( V_42 ) ;
goto V_30;
}
}
F_15 () ;
return V_42 ;
}
struct V_12 * F_29 ( struct V_1 * V_1 , struct V_13 * V_14 ,
const struct V_2 * V_15 , const T_3 V_16 ,
const struct V_2 * V_17 , const T_3 V_52 ,
const int V_19 )
{
struct V_12 * V_20 ;
F_30 () ;
V_20 = F_31 ( V_1 , V_14 , V_15 , V_16 , V_17 , F_32 ( V_52 ) , V_19 ) ;
F_33 () ;
return V_20 ;
}
static int F_34 ( struct V_53 * V_54 ,
struct V_12 * V_20 , const T_7 V_4 ,
struct V_55 * * V_56 )
{
struct V_13 * V_57 = V_54 -> V_14 ;
struct V_58 * V_59 = F_19 ( V_20 ) ;
const struct V_2 * V_17 = & V_20 -> V_39 ;
const struct V_2 * V_15 = & V_20 -> V_60 ;
const int V_19 = V_20 -> V_40 ;
const T_6 V_23 = F_7 ( V_59 -> V_61 , V_4 ) ;
struct V_1 * V_1 = F_18 ( V_20 ) ;
const unsigned int V_24 = F_1 ( V_1 , V_17 , V_4 , V_15 ,
V_59 -> V_61 ) ;
struct V_27 * V_28 = V_27 ( V_57 , V_24 ) ;
T_8 * V_62 = F_35 ( V_57 , V_24 ) ;
struct V_12 * V_63 ;
const struct V_21 * V_22 ;
struct V_55 * V_64 = NULL ;
F_36 ( V_62 ) ;
F_25 (sk2, node, &head->chain) {
if ( V_63 -> V_31 != V_24 )
continue;
if ( F_37 ( F_10 ( V_63 , V_1 , V_15 , V_17 , V_23 , V_19 ) ) ) {
if ( V_63 -> V_65 == V_66 ) {
V_64 = F_38 ( V_63 ) ;
if ( F_39 ( V_20 , V_63 , V_56 ) )
break;
}
goto V_67;
}
}
V_59 -> V_36 = V_4 ;
V_59 -> V_68 = F_40 ( V_4 ) ;
V_20 -> V_31 = V_24 ;
F_41 ( ! F_42 ( V_20 ) ) ;
F_43 ( V_20 , & V_28 -> V_69 ) ;
if ( V_64 ) {
F_44 ( (struct V_12 * ) V_64 ) ;
F_45 ( V_1 , V_70 ) ;
}
F_46 ( V_62 ) ;
F_47 ( F_18 ( V_20 ) , V_20 -> V_71 , 1 ) ;
if ( V_56 ) {
* V_56 = V_64 ;
} else if ( V_64 ) {
F_48 ( V_64 ) ;
}
return 0 ;
V_67:
F_46 ( V_62 ) ;
return - V_72 ;
}
static T_1 F_49 ( const struct V_12 * V_20 )
{
const struct V_58 * V_59 = F_19 ( V_20 ) ;
return F_50 ( V_20 -> V_39 . V_11 ,
V_20 -> V_60 . V_11 ,
V_59 -> V_61 ) ;
}
int F_51 ( struct V_53 * V_54 ,
struct V_12 * V_20 )
{
T_1 V_73 = 0 ;
if ( ! F_19 ( V_20 ) -> V_36 )
V_73 = F_49 ( V_20 ) ;
return F_52 ( V_54 , V_20 , V_73 ,
F_34 ) ;
}
