static inline void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_2 & V_3 , V_1 + V_4 ) ;
}
static inline void F_3 ( void T_1 * V_1 , T_2 V_5 )
{
F_2 ( V_5 & V_6 , V_1 + V_7 ) ;
}
static inline void F_4 ( void T_1 * V_1 )
{
F_2 ( 1 << V_8 , V_1 + V_9 ) ;
}
static inline void F_5 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_9 ) ;
}
static inline void F_6 ( void T_1 * V_1 , T_2 V_10 )
{
F_2 ( V_10 , V_1 + V_11 ) ;
}
static int F_7 ( void T_1 * V_1 , T_2 V_10 )
{
T_2 V_12 ;
T_2 V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_12 = F_8 ( V_1 + V_15 ) ;
if ( V_12 & V_10 )
break;
F_9 ( 1 ) ;
}
if ( V_13 == V_14 )
return - V_16 ;
return 0 ;
}
static int F_10 ( void T_1 * V_1 )
{
static const T_2 V_17 [] = V_18 ;
int V_19 ;
int V_20 ;
F_1 ( V_1 , V_21 ) ;
for ( V_19 = 0 ; V_19 < F_11 ( V_17 ) ; V_19 ++ ) {
F_6 ( V_1 , V_17 [ V_19 ] ) ;
F_4 ( V_1 ) ;
V_20 = F_7 ( V_1 , V_22 ) ;
F_5 ( V_1 ) ;
if ( V_20 )
return V_20 ;
}
return F_7 ( V_1 , V_23 ) ;
}
static int F_12 ( void T_1 * V_1 )
{
int V_20 ;
F_1 ( V_1 , V_24 ) ;
F_4 ( V_1 ) ;
V_20 = F_7 ( V_1 , V_23 ) ;
F_5 ( V_1 ) ;
return V_20 ;
}
static int F_13 ( void * V_25 , unsigned int V_26 , void * V_27 ,
T_3 V_28 )
{
struct V_29 * V_30 = V_25 ;
T_2 * V_31 = V_27 ;
T_2 V_32 ;
T_2 V_33 = V_26 / V_30 -> V_34 -> V_35 ;
int V_19 , V_20 ;
for ( V_32 = 0 ; V_32 < V_28 ; ) {
F_1 ( V_30 -> V_1 , V_36 ) ;
F_3 ( V_30 -> V_1 , V_33 ++ ) ;
F_4 ( V_30 -> V_1 ) ;
V_20 = F_7 ( V_30 -> V_1 , V_22 ) ;
if ( V_20 ) {
F_14 ( V_30 -> V_37 , L_1 , V_20 ) ;
return - V_38 ;
}
for ( V_19 = 0 ; V_19 < V_30 -> V_39 -> V_40 ; V_19 ++ ) {
* V_31 ++ = F_8 ( V_30 -> V_1 +
V_30 -> V_39 -> V_41 [ V_19 ] ) ;
V_32 += sizeof( * V_31 ) ;
}
F_5 ( V_30 -> V_1 ) ;
}
return 0 ;
}
static int F_15 ( void * V_25 , unsigned int V_26 , void * V_27 ,
T_3 V_28 )
{
struct V_29 * V_30 = V_25 ;
T_2 * V_31 = V_27 ;
T_2 V_42 ;
T_2 V_33 = V_26 / V_30 -> V_34 -> V_35 ;
int V_19 , V_20 ;
if ( V_26 % V_30 -> V_34 -> V_35 )
return - V_43 ;
V_20 = F_10 ( V_30 -> V_1 ) ;
if ( V_20 )
return - V_38 ;
for ( V_42 = 0 ; V_42 < V_28 ; ) {
F_1 ( V_30 -> V_1 , V_44 ) ;
F_3 ( V_30 -> V_1 , V_33 ++ ) ;
for ( V_19 = 0 ; V_19 < V_30 -> V_39 -> V_40 ; V_19 ++ ) {
F_2 ( * V_31 , V_30 -> V_1 + V_30 -> V_39 -> V_45 [ V_19 ] ) ;
V_31 ++ ;
V_42 += sizeof( * V_31 ) ;
}
F_4 ( V_30 -> V_1 ) ;
V_20 = F_7 ( V_30 -> V_1 , V_22 ) ;
F_5 ( V_30 -> V_1 ) ;
if ( V_20 ) {
F_14 ( V_30 -> V_37 , L_2 , V_20 ) ;
return - V_38 ;
}
}
F_12 ( V_30 -> V_1 ) ;
return 0 ;
}
static int F_16 ( struct V_46 * V_47 )
{
struct V_48 * V_37 = & V_47 -> V_37 ;
struct V_49 * V_50 = V_37 -> V_51 ;
struct V_52 * V_53 ;
struct V_29 * V_30 ;
struct V_54 * V_55 ;
int V_56 ;
T_2 V_57 ;
V_30 = F_17 ( V_37 , sizeof( * V_30 ) , V_58 ) ;
if ( ! V_30 )
return - V_59 ;
if ( F_18 ( V_37 -> V_51 , L_3 ) )
V_30 -> V_39 = & V_60 ;
else if ( F_18 ( V_37 -> V_51 , L_4 ) )
V_30 -> V_39 = & V_61 ;
else {
F_14 ( & V_47 -> V_37 ,
L_5 , V_62 ) ;
return - V_43 ;
}
V_53 = F_19 ( V_47 , V_63 , 0 ) ;
V_30 -> V_1 = F_20 ( V_37 , V_53 ) ;
if ( F_21 ( V_30 -> V_1 ) ) {
F_14 ( V_37 , L_6 ) ;
return F_22 ( V_30 -> V_1 ) ;
}
F_2 ( F_8 ( V_30 -> V_1 + V_64 ) |
F_23 ( V_65 ) ,
V_30 -> V_1 + V_64 ) ;
F_5 ( V_30 -> V_1 ) ;
V_56 = F_24 ( V_50 , L_7 , & V_57 ) ;
if ( V_56 ) {
F_14 ( V_37 , L_8 ) ;
return - V_43 ;
} else if ( V_57 == 0 ) {
F_14 ( V_37 , L_9 ) ;
return - V_43 ;
}
V_66 . V_67 = 4 * V_57 ;
V_66 . V_37 = V_37 ;
V_66 . V_30 = V_30 ;
if ( F_18 ( V_37 -> V_51 , L_4 ) ) {
V_66 . V_35 = 8 ;
V_66 . V_68 = 8 ;
}
V_30 -> V_34 = & V_66 ;
V_55 = F_25 ( & V_66 ) ;
if ( F_21 ( V_55 ) ) {
F_14 ( V_37 , L_10 ) ;
return F_22 ( V_55 ) ;
}
F_26 ( V_47 , V_55 ) ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 )
{
struct V_54 * V_55 = F_28 ( V_47 ) ;
return F_29 ( V_55 ) ;
}
