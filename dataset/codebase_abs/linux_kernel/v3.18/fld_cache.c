struct V_1 * F_1 ( const char * V_2 ,
int V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 ( V_2 != NULL ) ;
F_2 ( V_4 < V_3 ) ;
F_3 ( V_5 ) ;
if ( V_5 == NULL )
return F_4 ( - V_6 ) ;
F_5 ( & V_5 -> V_7 ) ;
F_5 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = 0 ;
F_6 ( & V_5 -> V_10 ) ;
F_7 ( V_5 -> V_11 , V_2 ,
sizeof( V_5 -> V_11 ) ) ;
V_5 -> V_12 = V_3 ;
V_5 -> V_13 = V_4 ;
memset ( & V_5 -> V_14 , 0 , sizeof( V_5 -> V_14 ) ) ;
F_8 ( V_15 , L_1 ,
V_5 -> V_11 , V_3 , V_4 ) ;
return V_5 ;
}
void F_9 ( struct V_1 * V_5 )
{
T_1 V_16 ;
F_2 ( V_5 != NULL ) ;
F_10 ( V_5 ) ;
if ( V_5 -> V_14 . V_17 > 0 ) {
V_16 = V_5 -> V_14 . V_18 * 100 ;
F_11 ( V_16 , V_5 -> V_14 . V_17 ) ;
} else {
V_16 = 0 ;
}
F_8 ( V_15 , L_2 , V_5 -> V_11 ) ;
F_8 ( V_15 , L_3 , V_5 -> V_14 . V_17 ) ;
F_8 ( V_15 , L_4 , V_5 -> V_14 . V_18 ) ;
F_8 ( V_15 , L_5 , V_16 ) ;
F_12 ( V_5 ) ;
}
void F_13 ( struct V_1 * V_5 ,
struct V_19 * V_20 )
{
F_14 ( & V_20 -> V_21 ) ;
F_14 ( & V_20 -> V_22 ) ;
V_5 -> V_9 -- ;
F_12 ( V_20 ) ;
}
static void F_15 ( struct V_1 * V_5 )
{
struct V_19 * V_23 ;
struct V_19 * V_24 ;
struct V_25 * V_26 ;
struct V_25 * V_27 ;
struct V_28 * V_29 = & V_5 -> V_7 ;
V_30:
F_16 (f_curr, f_next, head, fce_list) {
V_26 = & V_23 -> V_31 ;
V_27 = & V_24 -> V_31 ;
F_2 ( F_17 ( V_26 ) ) ;
if ( & V_24 -> V_21 == V_29 )
break;
if ( V_26 -> V_32 != V_27 -> V_32 )
continue;
F_18 ( V_26 -> V_33 <= V_27 -> V_33 ,
L_6 V_34 L_7 V_34 L_8 ,
F_19 ( V_26 ) , F_19 ( V_27 ) ) ;
if ( V_26 -> V_35 == V_27 -> V_33 ) {
if ( V_26 -> V_36 != V_27 -> V_36 )
continue;
V_27 -> V_33 = V_26 -> V_33 ;
F_13 ( V_5 , V_23 ) ;
continue;
}
if ( V_27 -> V_33 < V_26 -> V_35 ) {
if ( V_26 -> V_36 == V_27 -> V_36 ) {
V_27 -> V_33 = V_26 -> V_33 ;
V_27 -> V_35 = F_20 ( V_26 -> V_35 ,
V_27 -> V_35 ) ;
F_13 ( V_5 , V_23 ) ;
} else {
if ( V_27 -> V_35 <= V_26 -> V_35 ) {
* V_27 = * V_26 ;
F_13 ( V_5 , V_23 ) ;
} else
V_27 -> V_33 = V_26 -> V_35 ;
}
goto V_30;
}
if ( V_26 -> V_33 == V_27 -> V_33 &&
V_26 -> V_35 == V_27 -> V_35 )
F_13 ( V_5 , V_23 ) ;
}
}
static inline void F_21 ( struct V_1 * V_5 ,
struct V_19 * V_37 ,
struct V_28 * V_38 )
{
F_22 ( & V_37 -> V_21 , V_38 ) ;
F_22 ( & V_37 -> V_22 , & V_5 -> V_8 ) ;
V_5 -> V_9 ++ ;
F_15 ( V_5 ) ;
}
static int F_23 ( struct V_1 * V_5 )
{
struct V_19 * V_39 ;
struct V_28 * V_40 ;
int V_41 = 0 ;
F_2 ( V_5 != NULL ) ;
if ( V_5 -> V_9 < V_5 -> V_12 )
return 0 ;
V_40 = V_5 -> V_8 . V_42 ;
while ( V_5 -> V_9 + V_5 -> V_13 >
V_5 -> V_12 && V_40 != & V_5 -> V_8 ) {
V_39 = F_24 ( V_40 , struct V_19 , V_22 ) ;
V_40 = V_40 -> V_42 ;
F_13 ( V_5 , V_39 ) ;
V_41 ++ ;
}
F_8 ( V_15 , L_9 ,
V_5 -> V_11 , V_41 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_5 )
{
F_25 ( & V_5 -> V_10 ) ;
V_5 -> V_12 = 0 ;
F_23 ( V_5 ) ;
F_26 ( & V_5 -> V_10 ) ;
}
void F_27 ( struct V_1 * V_5 ,
struct V_19 * V_23 ,
struct V_19 * V_37 )
{
const struct V_25 * V_43 = & V_37 -> V_31 ;
const T_2 V_44 = V_43 -> V_33 ;
const T_2 V_45 = V_43 -> V_35 ;
struct V_19 * V_46 ;
F_28 ( V_46 , sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 ) {
F_12 ( V_37 ) ;
return;
}
V_46 -> V_31 . V_33 = V_45 ;
V_46 -> V_31 . V_35 = V_23 -> V_31 . V_35 ;
V_46 -> V_31 . V_36 = V_23 -> V_31 . V_36 ;
V_23 -> V_31 . V_35 = V_44 ;
F_21 ( V_5 , V_37 , & V_23 -> V_21 ) ;
F_21 ( V_5 , V_46 , & V_37 -> V_21 ) ;
}
static void F_29 ( struct V_1 * V_5 ,
struct V_19 * V_23 ,
struct V_19 * V_37 )
{
const struct V_25 * V_43 = & V_37 -> V_31 ;
const T_2 V_44 = V_43 -> V_33 ;
const T_2 V_45 = V_43 -> V_35 ;
const T_3 V_48 = V_43 -> V_36 ;
if ( V_23 -> V_31 . V_36 == V_48 ) {
V_23 -> V_31 . V_33 = F_30 ( V_23 -> V_31 . V_33 ,
V_44 ) ;
V_23 -> V_31 . V_35 = F_20 ( V_23 -> V_31 . V_35 ,
V_45 ) ;
F_12 ( V_37 ) ;
F_15 ( V_5 ) ;
} else if ( V_44 <= V_23 -> V_31 . V_33 &&
V_23 -> V_31 . V_35 <= V_45 ) {
V_23 -> V_31 = * V_43 ;
F_12 ( V_37 ) ;
F_15 ( V_5 ) ;
} else if ( V_23 -> V_31 . V_33 < V_44 &&
V_45 < V_23 -> V_31 . V_35 ) {
F_27 ( V_5 , V_23 , V_37 ) ;
} else if ( V_45 <= V_23 -> V_31 . V_35 ) {
F_2 ( V_44 <= V_23 -> V_31 . V_33 ) ;
V_23 -> V_31 . V_33 = V_45 ;
F_21 ( V_5 , V_37 , V_23 -> V_21 . V_42 ) ;
} else if ( V_23 -> V_31 . V_33 <= V_44 ) {
F_2 ( V_23 -> V_31 . V_35 <= V_45 ) ;
V_23 -> V_31 . V_35 = V_44 ;
F_21 ( V_5 , V_37 , & V_23 -> V_21 ) ;
} else
F_31 ( L_10 V_34 L_11 V_34 L_8 ,
F_19 ( V_43 ) , F_19 ( & V_23 -> V_31 ) ) ;
}
struct V_19
* F_32 ( const struct V_25 * V_43 )
{
struct V_19 * V_37 ;
F_2 ( F_17 ( V_43 ) ) ;
F_3 ( V_37 ) ;
if ( ! V_37 )
return F_4 ( - V_6 ) ;
V_37 -> V_31 = * V_43 ;
return V_37 ;
}
int F_33 ( struct V_1 * V_5 ,
struct V_19 * V_37 )
{
struct V_19 * V_23 ;
struct V_19 * V_49 ;
struct V_28 * V_29 ;
struct V_28 * V_42 = NULL ;
const T_2 V_44 = V_37 -> V_31 . V_33 ;
const T_2 V_45 = V_37 -> V_31 . V_35 ;
T_4 V_50 = V_37 -> V_31 . V_32 ;
if ( ! V_5 -> V_51 )
F_23 ( V_5 ) ;
V_29 = & V_5 -> V_7 ;
F_16 (f_curr, n, head, fce_list) {
if ( V_45 < V_23 -> V_31 . V_33 ||
( V_45 == V_23 -> V_31 . V_33 &&
V_50 != V_23 -> V_31 . V_32 ) )
break;
V_42 = & V_23 -> V_21 ;
if ( V_44 < V_23 -> V_31 . V_35 &&
V_50 == V_23 -> V_31 . V_32 ) {
F_29 ( V_5 , V_23 , V_37 ) ;
goto V_52;
}
}
if ( V_42 == NULL )
V_42 = V_29 ;
F_8 ( V_15 , L_12 V_34 L_8 , F_19 ( & V_37 -> V_31 ) ) ;
F_21 ( V_5 , V_37 , V_42 ) ;
V_52:
return 0 ;
}
int F_34 ( struct V_1 * V_5 ,
const struct V_25 * V_43 )
{
struct V_19 * V_39 ;
int V_53 ;
V_39 = F_32 ( V_43 ) ;
if ( F_35 ( V_39 ) )
return F_36 ( V_39 ) ;
F_25 ( & V_5 -> V_10 ) ;
V_53 = F_33 ( V_5 , V_39 ) ;
F_26 ( & V_5 -> V_10 ) ;
if ( V_53 )
F_12 ( V_39 ) ;
return V_53 ;
}
void F_37 ( struct V_1 * V_5 ,
const struct V_25 * V_43 )
{
struct V_19 * V_39 ;
struct V_19 * V_54 ;
struct V_28 * V_29 ;
V_29 = & V_5 -> V_7 ;
F_16 (flde, tmp, head, fce_list) {
if ( V_43 -> V_33 == V_39 -> V_31 . V_33 ||
( V_43 -> V_35 == V_39 -> V_31 . V_35 &&
V_43 -> V_32 == V_39 -> V_31 . V_32 ) ) {
F_13 ( V_5 , V_39 ) ;
break;
}
}
}
void F_38 ( struct V_1 * V_5 ,
const struct V_25 * V_43 )
{
F_25 ( & V_5 -> V_10 ) ;
F_37 ( V_5 , V_43 ) ;
F_26 ( & V_5 -> V_10 ) ;
}
struct V_19
* F_39 ( struct V_1 * V_5 ,
struct V_25 * V_43 )
{
struct V_19 * V_39 ;
struct V_19 * V_55 = NULL ;
struct V_28 * V_29 ;
V_29 = & V_5 -> V_7 ;
F_40 (flde, head, fce_list) {
if ( V_43 -> V_33 == V_39 -> V_31 . V_33 ||
( V_43 -> V_35 == V_39 -> V_31 . V_35 &&
V_43 -> V_32 == V_39 -> V_31 . V_32 ) ) {
V_55 = V_39 ;
break;
}
}
return V_55 ;
}
struct V_19
* F_41 ( struct V_1 * V_5 , struct V_25 * V_43 )
{
struct V_19 * V_55 = NULL ;
F_42 ( & V_5 -> V_10 ) ;
V_55 = F_39 ( V_5 , V_43 ) ;
F_43 ( & V_5 -> V_10 ) ;
return V_55 ;
}
int F_44 ( struct V_1 * V_5 ,
const T_2 V_56 , struct V_25 * V_43 )
{
struct V_19 * V_39 ;
struct V_19 * V_42 = NULL ;
struct V_28 * V_29 ;
F_42 ( & V_5 -> V_10 ) ;
V_29 = & V_5 -> V_7 ;
V_5 -> V_14 . V_17 ++ ;
F_40 (flde, head, fce_list) {
if ( V_39 -> V_31 . V_33 > V_56 ) {
if ( V_42 != NULL )
* V_43 = V_42 -> V_31 ;
break;
}
V_42 = V_39 ;
if ( F_45 ( & V_39 -> V_31 , V_56 ) ) {
* V_43 = V_39 -> V_31 ;
V_5 -> V_14 . V_18 ++ ;
F_43 ( & V_5 -> V_10 ) ;
return 0 ;
}
}
F_43 ( & V_5 -> V_10 ) ;
return - V_57 ;
}
