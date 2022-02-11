struct V_1 * F_1 ( const char * V_2 ,
int V_3 , int V_4 )
{
struct V_1 * V_5 ;
V_6 ;
F_2 ( V_2 != NULL ) ;
F_2 ( V_4 < V_3 ) ;
F_3 ( V_5 ) ;
if ( V_5 == NULL )
RETURN ( F_4 ( - V_7 ) ) ;
F_5 ( & V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = 0 ;
F_6 ( & V_5 -> V_11 ) ;
F_7 ( V_5 -> V_12 , V_2 ,
sizeof( V_5 -> V_12 ) ) ;
V_5 -> V_13 = V_3 ;
V_5 -> V_14 = V_4 ;
memset ( & V_5 -> V_15 , 0 , sizeof( V_5 -> V_15 ) ) ;
F_8 ( V_16 , L_1 ,
V_5 -> V_12 , V_3 , V_4 ) ;
RETURN ( V_5 ) ;
}
void F_9 ( struct V_1 * V_5 )
{
T_1 V_17 ;
V_6 ;
F_2 ( V_5 != NULL ) ;
F_10 ( V_5 ) ;
if ( V_5 -> V_15 . V_18 > 0 ) {
V_17 = V_5 -> V_15 . V_19 * 100 ;
F_11 ( V_17 , V_5 -> V_15 . V_18 ) ;
} else {
V_17 = 0 ;
}
F_8 ( V_16 , L_2 , V_5 -> V_12 ) ;
F_8 ( V_16 , L_3 V_20 L_4 , V_5 -> V_15 . V_18 ) ;
F_8 ( V_16 , L_5 V_20 L_4 , V_5 -> V_15 . V_19 ) ;
F_8 ( V_16 , L_6 V_20 L_7 , V_17 ) ;
F_12 ( V_5 ) ;
EXIT ;
}
void F_13 ( struct V_1 * V_5 ,
struct V_21 * V_22 )
{
F_14 ( & V_22 -> V_23 ) ;
F_14 ( & V_22 -> V_24 ) ;
V_5 -> V_10 -- ;
F_12 ( V_22 ) ;
}
static void F_15 ( struct V_1 * V_5 )
{
struct V_21 * V_25 ;
struct V_21 * V_26 ;
struct V_27 * V_28 ;
struct V_27 * V_29 ;
struct V_30 * V_31 = & V_5 -> V_8 ;
V_6 ;
V_32:
F_16 (f_curr, f_next, head, fce_list) {
V_28 = & V_25 -> V_33 ;
V_29 = & V_26 -> V_33 ;
F_2 ( F_17 ( V_28 ) ) ;
if ( & V_26 -> V_23 == V_31 )
break;
if ( V_28 -> V_34 != V_29 -> V_34 )
continue;
F_18 ( V_28 -> V_35 <= V_29 -> V_35 ,
L_8 V_36 L_9 V_36 L_4 ,
F_19 ( V_28 ) , F_19 ( V_29 ) ) ;
if ( V_28 -> V_37 == V_29 -> V_35 ) {
if ( V_28 -> V_38 != V_29 -> V_38 )
continue;
V_29 -> V_35 = V_28 -> V_35 ;
F_13 ( V_5 , V_25 ) ;
continue;
}
if ( V_29 -> V_35 < V_28 -> V_37 ) {
if ( V_28 -> V_38 == V_29 -> V_38 ) {
V_29 -> V_35 = V_28 -> V_35 ;
V_29 -> V_37 = F_20 ( V_28 -> V_37 ,
V_29 -> V_37 ) ;
F_13 ( V_5 , V_25 ) ;
} else {
if ( V_29 -> V_37 <= V_28 -> V_37 ) {
* V_29 = * V_28 ;
F_13 ( V_5 , V_25 ) ;
} else
V_29 -> V_35 = V_28 -> V_37 ;
}
goto V_32;
}
if ( V_28 -> V_35 == V_29 -> V_35 &&
V_28 -> V_37 == V_29 -> V_37 )
F_13 ( V_5 , V_25 ) ;
}
EXIT ;
}
static inline void F_21 ( struct V_1 * V_5 ,
struct V_21 * V_39 ,
struct V_30 * V_40 )
{
F_22 ( & V_39 -> V_23 , V_40 ) ;
F_22 ( & V_39 -> V_24 , & V_5 -> V_9 ) ;
V_5 -> V_10 ++ ;
F_15 ( V_5 ) ;
}
static int F_23 ( struct V_1 * V_5 )
{
struct V_21 * V_41 ;
struct V_30 * V_42 ;
int V_43 = 0 ;
V_6 ;
F_2 ( V_5 != NULL ) ;
if ( V_5 -> V_10 < V_5 -> V_13 )
RETURN ( 0 ) ;
V_42 = V_5 -> V_9 . V_44 ;
while ( V_5 -> V_10 + V_5 -> V_14 >
V_5 -> V_13 && V_42 != & V_5 -> V_9 ) {
V_41 = F_24 ( V_42 , struct V_21 , V_24 ) ;
V_42 = V_42 -> V_44 ;
F_13 ( V_5 , V_41 ) ;
V_43 ++ ;
}
F_8 ( V_16 , L_10
L_11 , V_5 -> V_12 , V_43 ) ;
RETURN ( 0 ) ;
}
void F_10 ( struct V_1 * V_5 )
{
V_6 ;
F_25 ( & V_5 -> V_11 ) ;
V_5 -> V_13 = 0 ;
F_23 ( V_5 ) ;
F_26 ( & V_5 -> V_11 ) ;
EXIT ;
}
void F_27 ( struct V_1 * V_5 ,
struct V_21 * V_25 ,
struct V_21 * V_39 )
{
const struct V_27 * V_45 = & V_39 -> V_33 ;
const T_2 V_46 = V_45 -> V_35 ;
const T_2 V_47 = V_45 -> V_37 ;
struct V_21 * V_48 ;
V_6 ;
F_28 ( V_48 , sizeof *V_48 , V_49 ) ;
if ( ! V_48 ) {
F_12 ( V_39 ) ;
EXIT ;
return;
}
V_48 -> V_33 . V_35 = V_47 ;
V_48 -> V_33 . V_37 = V_25 -> V_33 . V_37 ;
V_48 -> V_33 . V_38 = V_25 -> V_33 . V_38 ;
V_25 -> V_33 . V_37 = V_46 ;
F_21 ( V_5 , V_39 , & V_25 -> V_23 ) ;
F_21 ( V_5 , V_48 , & V_39 -> V_23 ) ;
EXIT ;
}
static void F_29 ( struct V_1 * V_5 ,
struct V_21 * V_25 ,
struct V_21 * V_39 )
{
const struct V_27 * V_45 = & V_39 -> V_33 ;
const T_2 V_46 = V_45 -> V_35 ;
const T_2 V_47 = V_45 -> V_37 ;
const T_3 V_50 = V_45 -> V_38 ;
if ( V_25 -> V_33 . V_38 == V_50 ) {
V_25 -> V_33 . V_35 = F_30 ( V_25 -> V_33 . V_35 ,
V_46 ) ;
V_25 -> V_33 . V_37 = F_20 ( V_25 -> V_33 . V_37 ,
V_47 ) ;
F_12 ( V_39 ) ;
F_15 ( V_5 ) ;
} else if ( V_46 <= V_25 -> V_33 . V_35 &&
V_25 -> V_33 . V_37 <= V_47 ) {
V_25 -> V_33 = * V_45 ;
F_12 ( V_39 ) ;
F_15 ( V_5 ) ;
} else if ( V_25 -> V_33 . V_35 < V_46 &&
V_47 < V_25 -> V_33 . V_37 ) {
F_27 ( V_5 , V_25 , V_39 ) ;
} else if ( V_47 <= V_25 -> V_33 . V_37 ) {
F_2 ( V_46 <= V_25 -> V_33 . V_35 ) ;
V_25 -> V_33 . V_35 = V_47 ;
F_21 ( V_5 , V_39 , V_25 -> V_23 . V_44 ) ;
} else if ( V_25 -> V_33 . V_35 <= V_46 ) {
F_2 ( V_25 -> V_33 . V_37 <= V_47 ) ;
V_25 -> V_33 . V_37 = V_46 ;
F_21 ( V_5 , V_39 , & V_25 -> V_23 ) ;
} else
F_31 ( L_12 V_36 L_13 V_36 L_4 ,
F_19 ( V_45 ) , F_19 ( & V_25 -> V_33 ) ) ;
}
struct V_21
* F_32 ( const struct V_27 * V_45 )
{
struct V_21 * V_39 ;
F_2 ( F_17 ( V_45 ) ) ;
F_3 ( V_39 ) ;
if ( ! V_39 )
RETURN ( F_4 ( - V_7 ) ) ;
V_39 -> V_33 = * V_45 ;
RETURN ( V_39 ) ;
}
int F_33 ( struct V_1 * V_5 ,
struct V_21 * V_39 )
{
struct V_21 * V_25 ;
struct V_21 * V_51 ;
struct V_30 * V_31 ;
struct V_30 * V_44 = NULL ;
const T_2 V_46 = V_39 -> V_33 . V_35 ;
const T_2 V_47 = V_39 -> V_33 . V_37 ;
T_4 V_52 = V_39 -> V_33 . V_34 ;
V_6 ;
if ( ! V_5 -> V_53 )
F_23 ( V_5 ) ;
V_31 = & V_5 -> V_8 ;
F_16 (f_curr, n, head, fce_list) {
if ( V_47 < V_25 -> V_33 . V_35 ||
( V_47 == V_25 -> V_33 . V_35 &&
V_52 != V_25 -> V_33 . V_34 ) )
break;
V_44 = & V_25 -> V_23 ;
if ( V_46 < V_25 -> V_33 . V_37 &&
V_52 == V_25 -> V_33 . V_34 ) {
F_29 ( V_5 , V_25 , V_39 ) ;
goto V_54;
}
}
if ( V_44 == NULL )
V_44 = V_31 ;
F_8 ( V_16 , L_14 V_36 L_4 , F_19 ( & V_39 -> V_33 ) ) ;
F_21 ( V_5 , V_39 , V_44 ) ;
V_54:
RETURN ( 0 ) ;
}
int F_34 ( struct V_1 * V_5 ,
const struct V_27 * V_45 )
{
struct V_21 * V_41 ;
int V_55 ;
V_41 = F_32 ( V_45 ) ;
if ( F_35 ( V_41 ) )
RETURN ( F_36 ( V_41 ) ) ;
F_25 ( & V_5 -> V_11 ) ;
V_55 = F_33 ( V_5 , V_41 ) ;
F_26 ( & V_5 -> V_11 ) ;
if ( V_55 )
F_12 ( V_41 ) ;
RETURN ( V_55 ) ;
}
void F_37 ( struct V_1 * V_5 ,
const struct V_27 * V_45 )
{
struct V_21 * V_41 ;
struct V_21 * V_56 ;
struct V_30 * V_31 ;
V_31 = & V_5 -> V_8 ;
F_16 (flde, tmp, head, fce_list) {
if ( V_45 -> V_35 == V_41 -> V_33 . V_35 ||
( V_45 -> V_37 == V_41 -> V_33 . V_37 &&
V_45 -> V_34 == V_41 -> V_33 . V_34 ) ) {
F_13 ( V_5 , V_41 ) ;
break;
}
}
}
void F_38 ( struct V_1 * V_5 ,
const struct V_27 * V_45 )
{
F_25 ( & V_5 -> V_11 ) ;
F_37 ( V_5 , V_45 ) ;
F_26 ( & V_5 -> V_11 ) ;
}
struct V_21
* F_39 ( struct V_1 * V_5 ,
struct V_27 * V_45 )
{
struct V_21 * V_41 ;
struct V_21 * V_57 = NULL ;
struct V_30 * V_31 ;
V_31 = & V_5 -> V_8 ;
F_40 (flde, head, fce_list) {
if ( V_45 -> V_35 == V_41 -> V_33 . V_35 ||
( V_45 -> V_37 == V_41 -> V_33 . V_37 &&
V_45 -> V_34 == V_41 -> V_33 . V_34 ) ) {
V_57 = V_41 ;
break;
}
}
RETURN ( V_57 ) ;
}
struct V_21
* F_41 ( struct V_1 * V_5 , struct V_27 * V_45 )
{
struct V_21 * V_57 = NULL ;
V_6 ;
F_42 ( & V_5 -> V_11 ) ;
V_57 = F_39 ( V_5 , V_45 ) ;
F_43 ( & V_5 -> V_11 ) ;
RETURN ( V_57 ) ;
}
int F_44 ( struct V_1 * V_5 ,
const T_2 V_58 , struct V_27 * V_45 )
{
struct V_21 * V_41 ;
struct V_21 * V_44 = NULL ;
struct V_30 * V_31 ;
V_6 ;
F_42 ( & V_5 -> V_11 ) ;
V_31 = & V_5 -> V_8 ;
V_5 -> V_15 . V_18 ++ ;
F_40 (flde, head, fce_list) {
if ( V_41 -> V_33 . V_35 > V_58 ) {
if ( V_44 != NULL )
* V_45 = V_44 -> V_33 ;
break;
}
V_44 = V_41 ;
if ( F_45 ( & V_41 -> V_33 , V_58 ) ) {
* V_45 = V_41 -> V_33 ;
V_5 -> V_15 . V_19 ++ ;
F_43 ( & V_5 -> V_11 ) ;
RETURN ( 0 ) ;
}
}
F_43 ( & V_5 -> V_11 ) ;
RETURN ( - V_59 ) ;
}
