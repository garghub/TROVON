static unsigned int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
const T_1 V_4 ,
const struct V_2 * V_5 ,
const T_2 V_6 )
{
static T_3 T_4 V_7 ;
static T_3 T_5 V_7 ;
T_3 V_8 , V_9 ;
F_2 ( & T_4 , sizeof( T_4 ) ) ;
F_2 ( & T_5 , sizeof( T_5 ) ) ;
V_8 = ( V_10 T_3 ) V_3 -> V_11 [ 3 ] ;
V_9 = F_3 ( V_5 , T_5 ) ;
return F_4 ( V_8 , V_4 , V_9 , V_6 ,
T_4 + F_5 ( V_1 ) ) ;
}
static int F_6 ( const struct V_12 * V_13 )
{
const struct V_14 * V_15 = F_7 ( V_13 ) ;
const struct V_2 * V_3 = & V_13 -> V_16 ;
const struct V_2 * V_5 = & V_13 -> V_17 ;
const T_6 V_4 = V_15 -> V_18 ;
const T_2 V_6 = V_15 -> V_19 ;
struct V_1 * V_1 = F_8 ( V_13 ) ;
return F_1 ( V_1 , V_3 , V_4 , V_5 , V_6 ) ;
}
int F_9 ( struct V_12 * V_13 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_13 -> V_24 -> V_25 . V_23 ;
int V_26 = 0 ;
F_10 ( ! F_11 ( V_13 ) ) ;
if ( V_13 -> V_27 == V_28 ) {
struct V_29 * V_30 ;
V_30 = & V_23 -> V_31 [ F_12 ( V_13 ) ] ;
F_13 ( & V_30 -> V_32 ) ;
F_14 ( V_13 , & V_30 -> V_33 ) ;
F_15 ( & V_30 -> V_32 ) ;
} else {
unsigned int V_34 ;
struct V_35 * V_36 ;
T_7 * V_32 ;
V_13 -> V_37 = V_34 = F_6 ( V_13 ) ;
V_36 = & F_16 ( V_23 , V_34 ) -> V_38 ;
V_32 = F_17 ( V_23 , V_34 ) ;
F_13 ( V_32 ) ;
F_14 ( V_13 , V_36 ) ;
if ( V_21 ) {
F_10 ( V_13 -> V_37 != V_21 -> V_39 ) ;
V_26 = F_18 ( V_21 ) ;
}
F_15 ( V_32 ) ;
}
F_19 ( F_8 ( V_13 ) , V_13 -> V_24 , 1 ) ;
return V_26 ;
}
struct V_12 * F_20 ( struct V_1 * V_1 ,
struct V_22 * V_23 ,
const struct V_2 * V_40 ,
const T_2 V_41 ,
const struct V_2 * V_42 ,
const T_1 V_43 ,
const int V_44 )
{
struct V_12 * V_13 ;
const struct V_45 * V_46 ;
const T_8 V_47 = F_21 ( V_41 , V_43 ) ;
unsigned int V_34 = F_1 ( V_1 , V_42 , V_43 , V_40 , V_41 ) ;
unsigned int V_48 = V_34 & V_23 -> V_49 ;
struct F_16 * V_33 = & V_23 -> V_50 [ V_48 ] ;
F_22 () ;
V_51:
F_23 (sk, node, &head->chain) {
if ( V_13 -> V_37 != V_34 )
continue;
if ( ! F_24 ( V_13 , V_1 , V_40 , V_42 , V_47 , V_44 ) )
continue;
if ( F_25 ( ! F_26 ( & V_13 -> V_52 ) ) )
goto V_53;
if ( F_25 ( ! F_24 ( V_13 , V_1 , V_40 , V_42 , V_47 , V_44 ) ) ) {
F_27 ( V_13 ) ;
goto V_51;
}
goto V_54;
}
if ( F_28 ( V_46 ) != V_48 )
goto V_51;
V_53:
V_13 = NULL ;
V_54:
F_29 () ;
return V_13 ;
}
static inline int F_30 ( struct V_12 * V_13 , struct V_1 * V_1 ,
const unsigned short V_43 ,
const struct V_2 * V_42 ,
const int V_44 )
{
int V_55 = - 1 ;
if ( F_31 ( F_8 ( V_13 ) , V_1 ) && F_7 ( V_13 ) -> V_18 == V_43 &&
V_13 -> V_56 == V_57 ) {
V_55 = 1 ;
if ( ! F_32 ( & V_13 -> V_16 ) ) {
if ( ! F_33 ( & V_13 -> V_16 , V_42 ) )
return - 1 ;
V_55 ++ ;
}
if ( V_13 -> V_58 ) {
if ( V_13 -> V_58 != V_44 )
return - 1 ;
V_55 ++ ;
}
}
return V_55 ;
}
struct V_12 * F_34 ( struct V_1 * V_1 ,
struct V_22 * V_23 , const struct V_2 * V_40 ,
const T_2 V_41 , const struct V_2 * V_42 ,
const unsigned short V_43 , const int V_44 )
{
struct V_12 * V_13 ;
const struct V_45 * V_46 ;
struct V_12 * V_59 ;
int V_55 , V_60 , V_61 = 0 , V_62 = 0 ;
T_3 V_63 = 0 ;
unsigned int V_34 = F_35 ( V_1 , V_43 ) ;
struct V_29 * V_30 = & V_23 -> V_31 [ V_34 ] ;
F_22 () ;
V_51:
V_59 = NULL ;
V_60 = 0 ;
F_36 (sk, node, &ilb->head) {
V_55 = F_30 ( V_13 , V_1 , V_43 , V_42 , V_44 ) ;
if ( V_55 > V_60 ) {
V_60 = V_55 ;
V_59 = V_13 ;
V_62 = V_13 -> V_64 ;
if ( V_62 ) {
V_63 = F_1 ( V_1 , V_42 , V_43 ,
V_40 , V_41 ) ;
V_61 = 1 ;
}
} else if ( V_55 == V_60 && V_62 ) {
V_61 ++ ;
if ( ( ( V_65 ) V_63 * V_61 ) >> 32 == 0 )
V_59 = V_13 ;
V_63 = F_37 ( V_63 ) ;
}
}
if ( F_28 ( V_46 ) != V_34 + V_66 )
goto V_51;
if ( V_59 ) {
if ( F_25 ( ! F_26 ( & V_59 -> V_52 ) ) )
V_59 = NULL ;
else if ( F_25 ( F_30 ( V_59 , V_1 , V_43 , V_42 ,
V_44 ) < V_60 ) ) {
F_38 ( V_59 ) ;
goto V_51;
}
}
F_29 () ;
return V_59 ;
}
struct V_12 * F_39 ( struct V_1 * V_1 , struct V_22 * V_23 ,
const struct V_2 * V_40 , const T_2 V_41 ,
const struct V_2 * V_42 , const T_2 V_67 ,
const int V_44 )
{
struct V_12 * V_13 ;
F_40 () ;
V_13 = F_41 ( V_1 , V_23 , V_40 , V_41 , V_42 , F_42 ( V_67 ) , V_44 ) ;
F_43 () ;
return V_13 ;
}
static int F_44 ( struct V_68 * V_69 ,
struct V_12 * V_13 , const T_6 V_4 ,
struct V_20 * * V_70 )
{
struct V_22 * V_71 = V_69 -> V_23 ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
const struct V_2 * V_42 = & V_13 -> V_16 ;
const struct V_2 * V_40 = & V_13 -> V_17 ;
const int V_44 = V_13 -> V_58 ;
const T_8 V_47 = F_21 ( V_15 -> V_19 , V_4 ) ;
struct V_1 * V_1 = F_8 ( V_13 ) ;
const unsigned int V_34 = F_1 ( V_1 , V_42 , V_4 , V_40 ,
V_15 -> V_19 ) ;
struct F_16 * V_33 = F_16 ( V_71 , V_34 ) ;
T_7 * V_32 = F_17 ( V_71 , V_34 ) ;
struct V_12 * V_72 ;
const struct V_45 * V_46 ;
struct V_20 * V_21 = NULL ;
int V_26 = 0 ;
F_13 ( V_32 ) ;
F_36 (sk2, node, &head->chain) {
if ( V_72 -> V_37 != V_34 )
continue;
if ( F_45 ( F_24 ( V_72 , V_1 , V_40 , V_42 , V_47 , V_44 ) ) ) {
if ( V_72 -> V_27 == V_73 ) {
V_21 = F_46 ( V_72 ) ;
if ( F_47 ( V_13 , V_72 , V_70 ) )
break;
}
goto V_74;
}
}
V_15 -> V_18 = V_4 ;
V_15 -> V_75 = F_48 ( V_4 ) ;
V_13 -> V_37 = V_34 ;
F_10 ( ! F_11 ( V_13 ) ) ;
F_14 ( V_13 , & V_33 -> V_38 ) ;
if ( V_21 ) {
V_26 = F_18 ( V_21 ) ;
F_49 ( V_1 , V_76 ) ;
}
F_15 ( V_32 ) ;
if ( V_26 )
F_50 ( V_21 ) ;
F_19 ( F_8 ( V_13 ) , V_13 -> V_24 , 1 ) ;
if ( V_70 ) {
* V_70 = V_21 ;
} else if ( V_21 ) {
F_51 ( V_21 , V_69 ) ;
F_50 ( V_21 ) ;
}
return 0 ;
V_74:
F_15 ( V_32 ) ;
return - V_77 ;
}
static inline T_3 F_52 ( const struct V_12 * V_13 )
{
const struct V_14 * V_15 = F_7 ( V_13 ) ;
return F_53 ( V_13 -> V_16 . V_11 ,
V_13 -> V_17 . V_11 ,
V_15 -> V_19 ) ;
}
int F_54 ( struct V_68 * V_69 ,
struct V_12 * V_13 )
{
return F_55 ( V_69 , V_13 , F_52 ( V_13 ) ,
F_44 , F_9 ) ;
}
