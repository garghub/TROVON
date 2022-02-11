struct V_1 * F_1 ( const char * V_2 ,
int V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 ( V_2 != NULL ) ;
F_2 ( V_4 < V_3 ) ;
V_5 = F_3 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return F_4 ( - V_7 ) ;
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
return V_5 ;
}
void F_9 ( struct V_1 * V_5 )
{
T_1 V_17 ;
F_2 ( V_5 != NULL ) ;
F_10 ( V_5 ) ;
if ( V_5 -> V_15 . V_18 > 0 ) {
V_17 = V_5 -> V_15 . V_19 * 100 ;
F_11 ( V_17 , V_5 -> V_15 . V_18 ) ;
} else {
V_17 = 0 ;
}
F_8 ( V_16 , L_2 , V_5 -> V_12 ) ;
F_8 ( V_16 , L_3 , V_5 -> V_15 . V_18 ) ;
F_8 ( V_16 , L_4 , V_5 -> V_15 . V_19 ) ;
F_8 ( V_16 , L_5 , V_17 ) ;
F_12 ( V_5 ) ;
}
void F_13 ( struct V_1 * V_5 ,
struct V_20 * V_21 )
{
F_14 ( & V_21 -> V_22 ) ;
F_14 ( & V_21 -> V_23 ) ;
V_5 -> V_10 -- ;
F_12 ( V_21 ) ;
}
static void F_15 ( struct V_1 * V_5 )
{
struct V_20 * V_24 ;
struct V_20 * V_25 ;
struct V_26 * V_27 ;
struct V_26 * V_28 ;
struct V_29 * V_30 = & V_5 -> V_8 ;
V_31:
F_16 (f_curr, f_next, head, fce_list) {
V_27 = & V_24 -> V_32 ;
V_28 = & V_25 -> V_32 ;
F_2 ( F_17 ( V_27 ) ) ;
if ( & V_25 -> V_22 == V_30 )
break;
if ( V_27 -> V_33 != V_28 -> V_33 )
continue;
F_18 ( V_27 -> V_34 <= V_28 -> V_34 ,
L_6 V_35 L_7 V_35 L_8 ,
F_19 ( V_27 ) , F_19 ( V_28 ) ) ;
if ( V_27 -> V_36 == V_28 -> V_34 ) {
if ( V_27 -> V_37 != V_28 -> V_37 )
continue;
V_28 -> V_34 = V_27 -> V_34 ;
F_13 ( V_5 , V_24 ) ;
continue;
}
if ( V_28 -> V_34 < V_27 -> V_36 ) {
if ( V_27 -> V_37 == V_28 -> V_37 ) {
V_28 -> V_34 = V_27 -> V_34 ;
V_28 -> V_36 = F_20 ( V_27 -> V_36 ,
V_28 -> V_36 ) ;
F_13 ( V_5 , V_24 ) ;
} else {
if ( V_28 -> V_36 <= V_27 -> V_36 ) {
* V_28 = * V_27 ;
F_13 ( V_5 , V_24 ) ;
} else
V_28 -> V_34 = V_27 -> V_36 ;
}
goto V_31;
}
if ( V_27 -> V_34 == V_28 -> V_34 &&
V_27 -> V_36 == V_28 -> V_36 )
F_13 ( V_5 , V_24 ) ;
}
}
static inline void F_21 ( struct V_1 * V_5 ,
struct V_20 * V_38 ,
struct V_29 * V_39 )
{
F_22 ( & V_38 -> V_22 , V_39 ) ;
F_22 ( & V_38 -> V_23 , & V_5 -> V_9 ) ;
V_5 -> V_10 ++ ;
F_15 ( V_5 ) ;
}
static int F_23 ( struct V_1 * V_5 )
{
struct V_20 * V_40 ;
struct V_29 * V_41 ;
int V_42 = 0 ;
F_2 ( V_5 != NULL ) ;
if ( V_5 -> V_10 < V_5 -> V_13 )
return 0 ;
V_41 = V_5 -> V_9 . V_43 ;
while ( V_5 -> V_10 + V_5 -> V_14 >
V_5 -> V_13 && V_41 != & V_5 -> V_9 ) {
V_40 = F_24 ( V_41 , struct V_20 , V_23 ) ;
V_41 = V_41 -> V_43 ;
F_13 ( V_5 , V_40 ) ;
V_42 ++ ;
}
F_8 ( V_16 , L_9 ,
V_5 -> V_12 , V_42 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_5 )
{
F_25 ( & V_5 -> V_11 ) ;
V_5 -> V_13 = 0 ;
F_23 ( V_5 ) ;
F_26 ( & V_5 -> V_11 ) ;
}
static void F_27 ( struct V_1 * V_5 ,
struct V_20 * V_24 ,
struct V_20 * V_38 )
{
const struct V_26 * V_44 = & V_38 -> V_32 ;
const T_2 V_45 = V_44 -> V_34 ;
const T_2 V_46 = V_44 -> V_36 ;
struct V_20 * V_47 ;
V_47 = F_3 ( sizeof( * V_47 ) , V_48 ) ;
if ( ! V_47 ) {
F_12 ( V_38 ) ;
return;
}
V_47 -> V_32 . V_34 = V_46 ;
V_47 -> V_32 . V_36 = V_24 -> V_32 . V_36 ;
V_47 -> V_32 . V_37 = V_24 -> V_32 . V_37 ;
V_24 -> V_32 . V_36 = V_45 ;
F_21 ( V_5 , V_38 , & V_24 -> V_22 ) ;
F_21 ( V_5 , V_47 , & V_38 -> V_22 ) ;
}
static void F_28 ( struct V_1 * V_5 ,
struct V_20 * V_24 ,
struct V_20 * V_38 )
{
const struct V_26 * V_44 = & V_38 -> V_32 ;
const T_2 V_45 = V_44 -> V_34 ;
const T_2 V_46 = V_44 -> V_36 ;
const T_3 V_49 = V_44 -> V_37 ;
if ( V_24 -> V_32 . V_37 == V_49 ) {
V_24 -> V_32 . V_34 = F_29 ( V_24 -> V_32 . V_34 ,
V_45 ) ;
V_24 -> V_32 . V_36 = F_20 ( V_24 -> V_32 . V_36 ,
V_46 ) ;
F_12 ( V_38 ) ;
F_15 ( V_5 ) ;
} else if ( V_45 <= V_24 -> V_32 . V_34 &&
V_24 -> V_32 . V_36 <= V_46 ) {
V_24 -> V_32 = * V_44 ;
F_12 ( V_38 ) ;
F_15 ( V_5 ) ;
} else if ( V_24 -> V_32 . V_34 < V_45 &&
V_46 < V_24 -> V_32 . V_36 ) {
F_27 ( V_5 , V_24 , V_38 ) ;
} else if ( V_46 <= V_24 -> V_32 . V_36 ) {
F_2 ( V_45 <= V_24 -> V_32 . V_34 ) ;
V_24 -> V_32 . V_34 = V_46 ;
F_21 ( V_5 , V_38 , V_24 -> V_22 . V_43 ) ;
} else if ( V_24 -> V_32 . V_34 <= V_45 ) {
F_2 ( V_24 -> V_32 . V_36 <= V_46 ) ;
V_24 -> V_32 . V_36 = V_45 ;
F_21 ( V_5 , V_38 , & V_24 -> V_22 ) ;
} else
F_30 ( L_10 V_35 L_11 V_35 L_8 ,
F_19 ( V_44 ) , F_19 ( & V_24 -> V_32 ) ) ;
}
struct V_20
* F_31 ( const struct V_26 * V_44 )
{
struct V_20 * V_38 ;
F_2 ( F_17 ( V_44 ) ) ;
V_38 = F_3 ( sizeof( * V_38 ) , V_6 ) ;
if ( ! V_38 )
return F_4 ( - V_7 ) ;
V_38 -> V_32 = * V_44 ;
return V_38 ;
}
int F_32 ( struct V_1 * V_5 ,
struct V_20 * V_38 )
{
struct V_20 * V_24 ;
struct V_20 * V_50 ;
struct V_29 * V_30 ;
struct V_29 * V_43 = NULL ;
const T_2 V_45 = V_38 -> V_32 . V_34 ;
const T_2 V_46 = V_38 -> V_32 . V_36 ;
T_4 V_51 = V_38 -> V_32 . V_33 ;
if ( ! V_5 -> V_52 )
F_23 ( V_5 ) ;
V_30 = & V_5 -> V_8 ;
F_16 (f_curr, n, head, fce_list) {
if ( V_46 < V_24 -> V_32 . V_34 ||
( V_46 == V_24 -> V_32 . V_34 &&
V_51 != V_24 -> V_32 . V_33 ) )
break;
V_43 = & V_24 -> V_22 ;
if ( V_45 < V_24 -> V_32 . V_36 &&
V_51 == V_24 -> V_32 . V_33 ) {
F_28 ( V_5 , V_24 , V_38 ) ;
goto V_53;
}
}
if ( V_43 == NULL )
V_43 = V_30 ;
F_8 ( V_16 , L_12 V_35 L_8 , F_19 ( & V_38 -> V_32 ) ) ;
F_21 ( V_5 , V_38 , V_43 ) ;
V_53:
return 0 ;
}
int F_33 ( struct V_1 * V_5 ,
const struct V_26 * V_44 )
{
struct V_20 * V_40 ;
int V_54 ;
V_40 = F_31 ( V_44 ) ;
if ( F_34 ( V_40 ) )
return F_35 ( V_40 ) ;
F_25 ( & V_5 -> V_11 ) ;
V_54 = F_32 ( V_5 , V_40 ) ;
F_26 ( & V_5 -> V_11 ) ;
if ( V_54 )
F_12 ( V_40 ) ;
return V_54 ;
}
void F_36 ( struct V_1 * V_5 ,
const struct V_26 * V_44 )
{
struct V_20 * V_40 ;
struct V_20 * V_55 ;
struct V_29 * V_30 ;
V_30 = & V_5 -> V_8 ;
F_16 (flde, tmp, head, fce_list) {
if ( V_44 -> V_34 == V_40 -> V_32 . V_34 ||
( V_44 -> V_36 == V_40 -> V_32 . V_36 &&
V_44 -> V_33 == V_40 -> V_32 . V_33 ) ) {
F_13 ( V_5 , V_40 ) ;
break;
}
}
}
void F_37 ( struct V_1 * V_5 ,
const struct V_26 * V_44 )
{
F_25 ( & V_5 -> V_11 ) ;
F_36 ( V_5 , V_44 ) ;
F_26 ( & V_5 -> V_11 ) ;
}
struct V_20
* F_38 ( struct V_1 * V_5 ,
struct V_26 * V_44 )
{
struct V_20 * V_40 ;
struct V_20 * V_56 = NULL ;
struct V_29 * V_30 ;
V_30 = & V_5 -> V_8 ;
F_39 (flde, head, fce_list) {
if ( V_44 -> V_34 == V_40 -> V_32 . V_34 ||
( V_44 -> V_36 == V_40 -> V_32 . V_36 &&
V_44 -> V_33 == V_40 -> V_32 . V_33 ) ) {
V_56 = V_40 ;
break;
}
}
return V_56 ;
}
struct V_20
* F_40 ( struct V_1 * V_5 , struct V_26 * V_44 )
{
struct V_20 * V_56 = NULL ;
F_41 ( & V_5 -> V_11 ) ;
V_56 = F_38 ( V_5 , V_44 ) ;
F_42 ( & V_5 -> V_11 ) ;
return V_56 ;
}
int F_43 ( struct V_1 * V_5 ,
const T_2 V_57 , struct V_26 * V_44 )
{
struct V_20 * V_40 ;
struct V_20 * V_43 = NULL ;
struct V_29 * V_30 ;
F_41 ( & V_5 -> V_11 ) ;
V_30 = & V_5 -> V_8 ;
V_5 -> V_15 . V_18 ++ ;
F_39 (flde, head, fce_list) {
if ( V_40 -> V_32 . V_34 > V_57 ) {
if ( V_43 != NULL )
* V_44 = V_43 -> V_32 ;
break;
}
V_43 = V_40 ;
if ( F_44 ( & V_40 -> V_32 , V_57 ) ) {
* V_44 = V_40 -> V_32 ;
V_5 -> V_15 . V_19 ++ ;
F_42 ( & V_5 -> V_11 ) ;
return 0 ;
}
}
F_42 ( & V_5 -> V_11 ) ;
return - V_58 ;
}
