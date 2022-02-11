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
const int V_19 , const int V_20 )
{
struct V_12 * V_21 ;
const struct V_22 * V_23 ;
const T_6 V_24 = F_7 ( V_16 , V_18 ) ;
unsigned int V_25 = F_1 ( V_1 , V_17 , V_18 , V_15 , V_16 ) ;
unsigned int V_26 = V_25 & V_14 -> V_27 ;
struct V_28 * V_29 = & V_14 -> V_30 [ V_26 ] ;
V_31:
F_8 (sk, node, &head->chain) {
if ( V_21 -> V_32 != V_25 )
continue;
if ( ! F_9 ( V_21 , V_1 , V_15 , V_17 , V_24 , V_19 , V_20 ) )
continue;
if ( F_10 ( ! F_11 ( & V_21 -> V_33 ) ) )
goto V_34;
if ( F_10 ( ! F_9 ( V_21 , V_1 , V_15 , V_17 , V_24 , V_19 , V_20 ) ) ) {
F_12 ( V_21 ) ;
goto V_31;
}
goto V_35;
}
if ( F_13 ( V_23 ) != V_26 )
goto V_31;
V_34:
V_21 = NULL ;
V_35:
return V_21 ;
}
static inline int F_14 ( struct V_12 * V_21 , struct V_1 * V_1 ,
const unsigned short V_18 ,
const struct V_2 * V_17 ,
const int V_19 , const int V_20 , bool V_36 )
{
int V_37 = - 1 ;
if ( F_15 ( F_16 ( V_21 ) , V_1 ) && F_17 ( V_21 ) -> V_38 == V_18 &&
V_21 -> V_39 == V_40 ) {
V_37 = 1 ;
if ( ! F_18 ( & V_21 -> V_41 ) ) {
if ( ! F_19 ( & V_21 -> V_41 , V_17 ) )
return - 1 ;
V_37 ++ ;
}
if ( V_21 -> V_42 || V_36 ) {
bool V_43 = ( V_21 -> V_42 == V_19 ||
V_21 -> V_42 == V_20 ) ;
if ( V_36 && ! V_43 )
return - 1 ;
if ( V_21 -> V_42 && V_43 )
V_37 ++ ;
}
if ( V_21 -> V_44 == F_20 () )
V_37 ++ ;
}
return V_37 ;
}
struct V_12 * F_21 ( struct V_1 * V_1 ,
struct V_13 * V_14 ,
struct V_45 * V_46 , int V_47 ,
const struct V_2 * V_15 ,
const T_3 V_16 , const struct V_2 * V_17 ,
const unsigned short V_18 , const int V_19 , const int V_20 )
{
unsigned int V_25 = F_22 ( V_1 , V_18 ) ;
struct V_48 * V_49 = & V_14 -> V_50 [ V_25 ] ;
int V_37 , V_51 = 0 , V_52 = 0 , V_53 = 0 ;
bool V_36 = F_23 ( V_1 , V_46 ) ;
struct V_12 * V_21 , * V_54 = NULL ;
T_1 V_55 = 0 ;
F_24 (sk, &ilb->head) {
V_37 = F_14 ( V_21 , V_1 , V_18 , V_17 , V_19 , V_20 , V_36 ) ;
if ( V_37 > V_51 ) {
V_53 = V_21 -> V_56 ;
if ( V_53 ) {
V_55 = F_1 ( V_1 , V_17 , V_18 ,
V_15 , V_16 ) ;
V_54 = F_25 ( V_21 , V_55 ,
V_46 , V_47 ) ;
if ( V_54 )
return V_54 ;
V_52 = 1 ;
}
V_54 = V_21 ;
V_51 = V_37 ;
} else if ( V_37 == V_51 && V_53 ) {
V_52 ++ ;
if ( F_26 ( V_55 , V_52 ) == 0 )
V_54 = V_21 ;
V_55 = F_27 ( V_55 ) ;
}
}
return V_54 ;
}
struct V_12 * F_28 ( struct V_1 * V_1 , struct V_13 * V_14 ,
struct V_45 * V_46 , int V_47 ,
const struct V_2 * V_15 , const T_3 V_16 ,
const struct V_2 * V_17 , const T_3 V_57 ,
const int V_19 )
{
struct V_12 * V_21 ;
bool V_58 ;
V_21 = F_29 ( V_1 , V_14 , V_46 , V_47 , V_15 , V_16 , V_17 ,
F_30 ( V_57 ) , V_19 , 0 , & V_58 ) ;
if ( V_21 && ! V_58 && ! F_11 ( & V_21 -> V_33 ) )
V_21 = NULL ;
return V_21 ;
}
static int F_31 ( struct V_59 * V_60 ,
struct V_12 * V_21 , const T_7 V_4 ,
struct V_61 * * V_62 )
{
struct V_13 * V_63 = V_60 -> V_14 ;
struct V_64 * V_65 = F_17 ( V_21 ) ;
const struct V_2 * V_17 = & V_21 -> V_41 ;
const struct V_2 * V_15 = & V_21 -> V_66 ;
const int V_19 = V_21 -> V_42 ;
struct V_1 * V_1 = F_16 ( V_21 ) ;
const int V_20 = F_32 ( V_1 , V_19 ) ;
const T_6 V_24 = F_7 ( V_65 -> V_67 , V_4 ) ;
const unsigned int V_25 = F_1 ( V_1 , V_17 , V_4 , V_15 ,
V_65 -> V_67 ) ;
struct V_28 * V_29 = V_28 ( V_63 , V_25 ) ;
T_8 * V_68 = F_33 ( V_63 , V_25 ) ;
struct V_12 * V_69 ;
const struct V_22 * V_23 ;
struct V_61 * V_70 = NULL ;
F_34 ( V_68 ) ;
F_35 (sk2, node, &head->chain) {
if ( V_69 -> V_32 != V_25 )
continue;
if ( F_36 ( F_9 ( V_69 , V_1 , V_15 , V_17 , V_24 ,
V_19 , V_20 ) ) ) {
if ( V_69 -> V_71 == V_72 ) {
V_70 = F_37 ( V_69 ) ;
if ( F_38 ( V_21 , V_69 , V_62 ) )
break;
}
goto V_73;
}
}
V_65 -> V_38 = V_4 ;
V_65 -> V_74 = F_39 ( V_4 ) ;
V_21 -> V_32 = V_25 ;
F_40 ( ! F_41 ( V_21 ) ) ;
F_42 ( V_21 , & V_29 -> V_75 ) ;
if ( V_70 ) {
F_43 ( (struct V_12 * ) V_70 ) ;
F_44 ( V_1 , V_76 ) ;
}
F_45 ( V_68 ) ;
F_46 ( F_16 ( V_21 ) , V_21 -> V_77 , 1 ) ;
if ( V_62 ) {
* V_62 = V_70 ;
} else if ( V_70 ) {
F_47 ( V_70 ) ;
}
return 0 ;
V_73:
F_45 ( V_68 ) ;
return - V_78 ;
}
static T_1 F_48 ( const struct V_12 * V_21 )
{
const struct V_64 * V_65 = F_17 ( V_21 ) ;
return F_49 ( V_21 -> V_41 . V_11 ,
V_21 -> V_66 . V_11 ,
V_65 -> V_67 ) ;
}
int F_50 ( struct V_59 * V_60 ,
struct V_12 * V_21 )
{
T_1 V_79 = 0 ;
if ( ! F_17 ( V_21 ) -> V_38 )
V_79 = F_48 ( V_21 ) ;
return F_51 ( V_60 , V_21 , V_79 ,
F_31 ) ;
}
int F_52 ( struct V_12 * V_21 )
{
int V_80 = 0 ;
if ( V_21 -> V_71 != V_81 ) {
F_53 () ;
V_80 = F_54 ( V_21 , NULL ) ;
F_55 () ;
}
return V_80 ;
}
