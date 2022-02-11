static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 ;
int V_8 ;
if ( F_3 ( V_9 , & V_4 -> V_10 ) ) {
while ( ( V_7 = F_4 ( & V_4 -> V_11 ) ) ) {
if ( F_5 ( V_4 -> V_12 . V_13 . V_14 ) ) {
V_8 = V_4 -> V_12 . V_13 . V_15 ( V_4 -> V_12 . V_13 . V_14 , V_7 ) ;
if ( V_8 )
F_6 ( V_7 ) ;
} else
F_6 ( V_7 ) ;
}
}
if ( F_3 ( V_16 , & V_4 -> V_10 ) ) {
if ( V_4 -> V_17 )
V_4 -> V_17 ( V_4 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_2 ( V_2 , struct V_18 , V_5 ) ;
struct V_6 * V_7 ;
int V_8 ;
if ( F_3 ( V_9 , & V_19 -> V_10 ) ) {
while ( ( V_7 = F_4 ( & V_19 -> V_11 ) ) ) {
V_19 -> V_20 -- ;
if ( F_5 ( V_19 -> V_21 . V_14 ) ) {
V_8 = V_19 -> V_21 . V_15 ( V_19 -> V_21 . V_14 , V_7 ) ;
if ( V_8 )
F_6 ( V_7 ) ;
} else
F_6 ( V_7 ) ;
}
}
}
int
F_8 ( struct V_3 * V_21 , int V_22 , void * V_23 )
{
F_9 ( V_24 , & V_21 -> V_10 ) ;
V_21 -> V_22 = V_22 ;
V_21 -> V_25 = NULL ;
V_21 -> V_26 = NULL ;
V_21 -> V_27 = NULL ;
V_21 -> V_28 = 0 ;
V_21 -> V_17 = V_23 ;
F_10 ( & V_21 -> V_29 ) ;
F_10 ( & V_21 -> V_11 ) ;
F_11 ( & V_21 -> V_12 . V_30 ) ;
F_12 ( & V_21 -> V_5 , F_1 ) ;
return 0 ;
}
int
F_13 ( struct V_18 * V_21 , int V_22 )
{
V_21 -> V_10 = 0 ;
V_21 -> V_22 = V_22 ;
V_21 -> V_25 = NULL ;
V_21 -> V_26 = NULL ;
V_21 -> V_27 = NULL ;
V_21 -> V_28 = 0 ;
F_10 ( & V_21 -> V_11 ) ;
V_21 -> V_20 = 0 ;
V_21 -> V_31 = NULL ;
F_12 ( & V_21 -> V_5 , F_7 ) ;
return 0 ;
}
int
F_14 ( struct V_3 * V_21 )
{
if ( V_21 -> V_27 ) {
F_6 ( V_21 -> V_27 ) ;
V_21 -> V_27 = NULL ;
}
if ( V_21 -> V_26 ) {
F_6 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
}
F_15 ( & V_21 -> V_29 ) ;
F_15 ( & V_21 -> V_11 ) ;
F_16 ( & V_21 -> V_5 ) ;
return 0 ;
}
void
F_17 ( struct V_18 * V_21 )
{
if ( V_21 -> V_27 ) {
F_6 ( V_21 -> V_27 ) ;
V_21 -> V_27 = NULL ;
}
V_21 -> V_28 = 0 ;
if ( V_21 -> V_26 ) {
F_6 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
}
if ( V_21 -> V_31 ) {
F_6 ( V_21 -> V_31 ) ;
V_21 -> V_31 = NULL ;
}
F_3 ( V_32 , & V_21 -> V_10 ) ;
F_3 ( V_33 , & V_21 -> V_10 ) ;
F_3 ( V_34 , & V_21 -> V_10 ) ;
}
int
F_18 ( struct V_18 * V_21 )
{
F_17 ( V_21 ) ;
F_15 ( & V_21 -> V_11 ) ;
V_21 -> V_20 = 0 ;
F_16 ( & V_21 -> V_5 ) ;
return 0 ;
}
static inline T_1
F_19 ( T_2 * V_35 )
{
T_1 V_36 , V_37 ;
V_36 = * V_35 >> 2 ;
V_37 = V_35 [ 1 ] >> 1 ;
return V_36 | ( V_37 << 8 ) ;
}
void
F_20 ( struct V_3 * V_4 )
{
struct V_38 * V_39 ;
if ( V_4 -> V_26 -> V_40 < 2 ) {
F_6 ( V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
return;
}
V_39 = F_21 ( V_4 -> V_26 ) ;
V_39 -> V_41 = V_42 ;
V_39 -> V_43 = F_19 ( V_4 -> V_26 -> V_44 ) ;
F_22 ( & V_4 -> V_11 , V_4 -> V_26 ) ;
V_4 -> V_26 = NULL ;
F_23 ( V_4 , V_9 ) ;
}
void
F_24 ( struct V_3 * V_45 , struct V_3 * V_4 )
{
struct V_38 * V_39 ;
if ( V_45 -> V_26 -> V_40 < 2 ) {
F_6 ( V_45 -> V_26 ) ;
V_45 -> V_26 = NULL ;
return;
}
V_39 = F_21 ( V_45 -> V_26 ) ;
V_39 -> V_41 = V_46 ;
V_39 -> V_43 = F_19 ( V_45 -> V_26 -> V_44 ) ;
F_22 ( & V_4 -> V_11 , V_45 -> V_26 ) ;
V_45 -> V_26 = NULL ;
F_23 ( V_4 , V_9 ) ;
}
void
F_25 ( struct V_18 * V_19 , unsigned int V_43 )
{
struct V_38 * V_39 ;
V_39 = F_21 ( V_19 -> V_26 ) ;
V_39 -> V_41 = V_42 ;
V_39 -> V_43 = V_43 ;
if ( V_19 -> V_20 >= 64 ) {
F_26 ( V_47 L_1
L_2 , V_19 ) ;
F_15 ( & V_19 -> V_11 ) ;
V_19 -> V_20 = 0 ;
return;
}
V_19 -> V_20 ++ ;
F_22 ( & V_19 -> V_11 , V_19 -> V_26 ) ;
V_19 -> V_26 = NULL ;
F_23 ( V_19 , V_9 ) ;
}
void
F_27 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_22 ( & V_4 -> V_11 , V_7 ) ;
F_23 ( V_4 , V_9 ) ;
}
void
F_28 ( struct V_18 * V_19 , struct V_6 * V_7 )
{
if ( V_19 -> V_20 >= 64 ) {
F_26 ( V_47 L_1
L_2 , V_19 ) ;
F_15 ( & V_19 -> V_11 ) ;
V_19 -> V_20 = 0 ;
}
V_19 -> V_20 ++ ;
F_22 ( & V_19 -> V_11 , V_7 ) ;
F_23 ( V_19 , V_9 ) ;
}
static void
F_29 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
V_7 = F_30 ( V_48 , F_31 ( V_4 -> V_27 ) ,
0 , NULL , V_49 ) ;
if ( ! V_7 ) {
F_26 ( V_50 L_3 , V_51 ,
F_31 ( V_4 -> V_27 ) ) ;
return;
}
F_22 ( & V_4 -> V_11 , V_7 ) ;
F_23 ( V_4 , V_9 ) ;
}
int
F_32 ( struct V_3 * V_4 )
{
V_4 -> V_28 = 0 ;
V_4 -> V_27 = F_4 ( & V_4 -> V_29 ) ;
if ( V_4 -> V_27 ) {
F_29 ( V_4 ) ;
return 1 ;
}
V_4 -> V_27 = NULL ;
F_3 ( V_32 , & V_4 -> V_10 ) ;
return 0 ;
}
void
F_33 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
if ( V_19 -> V_20 >= 64 ) {
F_26 ( V_47 L_1
L_2 , V_19 ) ;
F_15 ( & V_19 -> V_11 ) ;
V_19 -> V_20 = 0 ;
}
V_7 = F_30 ( V_48 , F_31 ( V_19 -> V_27 ) ,
0 , NULL , V_49 ) ;
if ( ! V_7 ) {
F_26 ( V_50 L_3 , V_51 ,
F_31 ( V_19 -> V_27 ) ) ;
return;
}
V_19 -> V_20 ++ ;
F_22 ( & V_19 -> V_11 , V_7 ) ;
F_23 ( V_19 , V_9 ) ;
}
int
F_34 ( struct V_18 * V_19 )
{
V_19 -> V_28 = 0 ;
if ( F_35 ( V_33 , & V_19 -> V_10 ) ) {
V_19 -> V_27 = V_19 -> V_31 ;
if ( V_19 -> V_27 ) {
V_19 -> V_31 = NULL ;
F_3 ( V_33 , & V_19 -> V_10 ) ;
if ( ! F_35 ( V_52 , & V_19 -> V_10 ) )
F_33 ( V_19 ) ;
return 1 ;
} else {
F_3 ( V_33 , & V_19 -> V_10 ) ;
F_26 ( V_47 L_4 ) ;
}
}
V_19 -> V_27 = NULL ;
F_3 ( V_32 , & V_19 -> V_10 ) ;
return 0 ;
}
void
F_36 ( struct V_53 * V_21 , T_1 V_54 , int V_43 , struct V_6 * V_7 )
{
struct V_38 * V_39 ;
if ( ! V_7 ) {
F_37 ( V_21 , V_54 , V_43 , 0 , NULL , V_49 ) ;
} else {
if ( V_21 -> V_14 ) {
V_39 = F_21 ( V_7 ) ;
V_39 -> V_41 = V_54 ;
V_39 -> V_43 = V_43 ;
if ( ! V_21 -> V_15 ( V_21 -> V_14 , V_7 ) )
return;
}
F_6 ( V_7 ) ;
}
}
int
F_38 ( struct V_3 * V_21 , struct V_6 * V_7 )
{
if ( V_7 -> V_40 <= 0 ) {
F_26 ( V_47 L_5 , V_51 ) ;
return - V_55 ;
}
if ( V_7 -> V_40 > V_21 -> V_22 ) {
F_26 ( V_47 L_6 ,
V_51 , V_7 -> V_40 , V_21 -> V_22 ) ;
return - V_55 ;
}
if ( F_9 ( V_32 , & V_21 -> V_10 ) ) {
F_22 ( & V_21 -> V_29 , V_7 ) ;
return 0 ;
} else {
V_21 -> V_27 = V_7 ;
V_21 -> V_28 = 0 ;
return 1 ;
}
}
int
F_39 ( struct V_18 * V_21 , struct V_6 * V_7 )
{
if ( V_7 -> V_40 <= 0 ) {
F_26 ( V_47 L_5 , V_51 ) ;
return - V_55 ;
}
if ( V_7 -> V_40 > V_21 -> V_22 ) {
F_26 ( V_47 L_6 ,
V_51 , V_7 -> V_40 , V_21 -> V_22 ) ;
return - V_55 ;
}
if ( V_21 -> V_31 ) {
F_26 ( V_47
L_7 ,
V_51 , V_7 -> V_40 , V_21 -> V_31 -> V_40 ) ;
return - V_56 ;
}
if ( F_9 ( V_32 , & V_21 -> V_10 ) ) {
F_9 ( V_33 , & V_21 -> V_10 ) ;
V_21 -> V_31 = V_7 ;
return 0 ;
} else {
V_21 -> V_27 = V_7 ;
V_21 -> V_28 = 0 ;
return 1 ;
}
}
