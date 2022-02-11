int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_6 ;
int V_9 = 0 ;
F_2 ( ! F_3 ( V_2 ) ) ;
if ( V_2 -> V_10 == V_11 ) {
struct V_12 * V_13 ;
V_13 = & V_6 -> V_14 [ F_4 ( V_2 ) ] ;
F_5 ( & V_13 -> V_15 ) ;
F_6 ( V_2 , & V_13 -> V_16 ) ;
F_7 ( & V_13 -> V_15 ) ;
} else {
unsigned int V_17 ;
struct V_18 * V_19 ;
T_1 * V_15 ;
V_2 -> V_20 = V_17 = F_8 ( V_2 ) ;
V_19 = & F_9 ( V_6 , V_17 ) -> V_21 ;
V_15 = F_10 ( V_6 , V_17 ) ;
F_5 ( V_15 ) ;
F_6 ( V_2 , V_19 ) ;
if ( V_4 ) {
F_2 ( V_2 -> V_20 != V_4 -> V_22 ) ;
V_9 = F_11 ( V_4 ) ;
}
F_7 ( V_15 ) ;
}
F_12 ( F_13 ( V_2 ) , V_2 -> V_7 , 1 ) ;
return V_9 ;
}
struct V_1 * F_14 ( struct V_23 * V_23 ,
struct V_5 * V_6 ,
const struct V_24 * V_25 ,
const T_2 V_26 ,
const struct V_24 * V_27 ,
const T_3 V_28 ,
const int V_29 )
{
struct V_1 * V_2 ;
const struct V_30 * V_31 ;
const T_4 V_32 = F_15 ( V_26 , V_28 ) ;
unsigned int V_17 = F_16 ( V_23 , V_27 , V_28 , V_25 , V_26 ) ;
unsigned int V_33 = V_17 & V_6 -> V_34 ;
struct F_9 * V_16 = & V_6 -> V_35 [ V_33 ] ;
F_17 () ;
V_36:
F_18 (sk, node, &head->chain) {
if ( V_2 -> V_20 != V_17 )
continue;
if ( F_19 ( F_20 ( V_2 , V_23 , V_25 , V_27 , V_32 , V_29 ) ) ) {
if ( F_21 ( ! F_22 ( & V_2 -> V_37 ) ) )
goto V_38;
if ( F_21 ( ! F_20 ( V_2 , V_23 , V_25 , V_27 ,
V_32 , V_29 ) ) ) {
F_23 ( V_2 ) ;
goto V_36;
}
goto V_39;
}
}
if ( F_24 ( V_31 ) != V_33 )
goto V_36;
V_38:
F_18 (sk, node, &head->twchain) {
if ( V_2 -> V_20 != V_17 )
continue;
if ( F_19 ( F_25 ( V_2 , V_23 , V_25 , V_27 ,
V_32 , V_29 ) ) ) {
if ( F_21 ( ! F_22 ( & V_2 -> V_37 ) ) ) {
V_2 = NULL ;
goto V_39;
}
if ( F_21 ( ! F_25 ( V_2 , V_23 , V_25 , V_27 ,
V_32 , V_29 ) ) ) {
F_23 ( V_2 ) ;
goto V_38;
}
goto V_39;
}
}
if ( F_24 ( V_31 ) != V_33 )
goto V_38;
V_2 = NULL ;
V_39:
F_26 () ;
return V_2 ;
}
static inline int F_27 ( struct V_1 * V_2 , struct V_23 * V_23 ,
const unsigned short V_28 ,
const struct V_24 * V_27 ,
const int V_29 )
{
int V_40 = - 1 ;
if ( F_28 ( F_13 ( V_2 ) , V_23 ) && F_29 ( V_2 ) -> V_41 == V_28 &&
V_2 -> V_42 == V_43 ) {
const struct V_44 * V_45 = F_30 ( V_2 ) ;
V_40 = 1 ;
if ( ! F_31 ( & V_45 -> V_46 ) ) {
if ( ! F_32 ( & V_45 -> V_46 , V_27 ) )
return - 1 ;
V_40 ++ ;
}
if ( V_2 -> V_47 ) {
if ( V_2 -> V_47 != V_29 )
return - 1 ;
V_40 ++ ;
}
}
return V_40 ;
}
struct V_1 * F_33 ( struct V_23 * V_23 ,
struct V_5 * V_6 , const struct V_24 * V_27 ,
const unsigned short V_28 , const int V_29 )
{
struct V_1 * V_2 ;
const struct V_30 * V_31 ;
struct V_1 * V_48 ;
int V_40 , V_49 ;
unsigned int V_17 = F_34 ( V_23 , V_28 ) ;
struct V_12 * V_13 = & V_6 -> V_14 [ V_17 ] ;
F_17 () ;
V_36:
V_48 = NULL ;
V_49 = - 1 ;
F_35 (sk, node, &ilb->head) {
V_40 = F_27 ( V_2 , V_23 , V_28 , V_27 , V_29 ) ;
if ( V_40 > V_49 ) {
V_49 = V_40 ;
V_48 = V_2 ;
}
}
if ( F_24 ( V_31 ) != V_17 + V_50 )
goto V_36;
if ( V_48 ) {
if ( F_21 ( ! F_22 ( & V_48 -> V_37 ) ) )
V_48 = NULL ;
else if ( F_21 ( F_27 ( V_48 , V_23 , V_28 , V_27 ,
V_29 ) < V_49 ) ) {
F_23 ( V_48 ) ;
goto V_36;
}
}
F_26 () ;
return V_48 ;
}
struct V_1 * F_36 ( struct V_23 * V_23 , struct V_5 * V_6 ,
const struct V_24 * V_25 , const T_2 V_26 ,
const struct V_24 * V_27 , const T_2 V_51 ,
const int V_29 )
{
struct V_1 * V_2 ;
F_37 () ;
V_2 = F_38 ( V_23 , V_6 , V_25 , V_26 , V_27 , F_39 ( V_51 ) , V_29 ) ;
F_40 () ;
return V_2 ;
}
static int F_41 ( struct V_52 * V_53 ,
struct V_1 * V_2 , const T_5 V_54 ,
struct V_3 * * V_55 )
{
struct V_5 * V_56 = V_53 -> V_6 ;
struct V_57 * V_58 = F_29 ( V_2 ) ;
const struct V_44 * V_45 = F_30 ( V_2 ) ;
const struct V_24 * V_27 = & V_45 -> V_46 ;
const struct V_24 * V_25 = & V_45 -> V_27 ;
const int V_29 = V_2 -> V_47 ;
const T_4 V_32 = F_15 ( V_58 -> V_59 , V_54 ) ;
struct V_23 * V_23 = F_13 ( V_2 ) ;
const unsigned int V_17 = F_16 ( V_23 , V_27 , V_54 , V_25 ,
V_58 -> V_59 ) ;
struct F_9 * V_16 = F_9 ( V_56 , V_17 ) ;
T_1 * V_15 = F_10 ( V_56 , V_17 ) ;
struct V_1 * V_60 ;
const struct V_30 * V_31 ;
struct V_3 * V_4 ;
int V_9 = 0 ;
F_5 ( V_15 ) ;
F_35 (sk2, node, &head->twchain) {
if ( V_60 -> V_20 != V_17 )
continue;
if ( F_19 ( F_25 ( V_60 , V_23 , V_25 , V_27 ,
V_32 , V_29 ) ) ) {
V_4 = F_42 ( V_60 ) ;
if ( F_43 ( V_2 , V_60 , V_55 ) )
goto V_61;
else
goto V_62;
}
}
V_4 = NULL ;
F_35 (sk2, node, &head->chain) {
if ( V_60 -> V_20 != V_17 )
continue;
if ( F_19 ( F_20 ( V_60 , V_23 , V_25 , V_27 , V_32 , V_29 ) ) )
goto V_62;
}
V_61:
V_58 -> V_41 = V_54 ;
V_58 -> V_63 = F_44 ( V_54 ) ;
V_2 -> V_20 = V_17 ;
F_2 ( ! F_3 ( V_2 ) ) ;
F_6 ( V_2 , & V_16 -> V_21 ) ;
if ( V_4 ) {
V_9 = F_11 ( V_4 ) ;
F_45 ( V_23 , V_64 ) ;
}
F_7 ( V_15 ) ;
if ( V_9 )
F_46 ( V_4 ) ;
F_12 ( F_13 ( V_2 ) , V_2 -> V_7 , 1 ) ;
if ( V_55 ) {
* V_55 = V_4 ;
} else if ( V_4 ) {
F_47 ( V_4 , V_53 ) ;
F_46 ( V_4 ) ;
}
return 0 ;
V_62:
F_7 ( V_15 ) ;
return - V_65 ;
}
static inline T_6 F_48 ( const struct V_1 * V_2 )
{
const struct V_57 * V_58 = F_29 ( V_2 ) ;
const struct V_44 * V_45 = F_30 ( V_2 ) ;
return F_49 ( V_45 -> V_46 . V_66 ,
V_45 -> V_27 . V_66 ,
V_58 -> V_59 ) ;
}
int F_50 ( struct V_52 * V_53 ,
struct V_1 * V_2 )
{
return F_51 ( V_53 , V_2 , F_48 ( V_2 ) ,
F_41 , F_1 ) ;
}
