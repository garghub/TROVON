static inline bool F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 == V_3 ) || ( V_1 == V_2 ) ;
}
const struct V_4 * V_4 ( struct V_5 V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_8 ) ; V_7 ++ ) {
const struct V_4 * V_9 = & V_8 [ V_7 ] ;
if ( F_1 ( V_9 -> V_6 . V_10 , V_6 . V_10 ) &&
F_1 ( V_9 -> V_6 . V_11 , V_6 . V_11 ) &&
F_1 ( V_9 -> V_6 . V_12 , V_6 . V_12 ) &&
F_1 ( V_9 -> V_6 . V_13 , V_6 . V_13 ) )
return V_9 ;
}
return NULL ;
}
struct V_14 * F_3 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_23 * V_24 ;
struct V_5 V_6 ;
const struct V_4 * V_9 ;
struct V_14 * V_25 = NULL ;
if ( ! V_21 ) {
F_4 ( V_16 -> V_16 , L_1 ) ;
return NULL ;
}
V_24 = V_21 -> V_16 . V_26 ;
V_6 = V_24 -> V_6 ;
V_9 = V_4 ( V_24 -> V_6 ) ;
if ( ! V_9 ) {
F_5 ( V_16 -> V_16 , L_2 ,
V_6 . V_10 , V_6 . V_11 , V_6 . V_12 , V_6 . V_13 ) ;
return NULL ;
}
F_6 ( L_3 , V_6 . V_10 , V_6 . V_11 ,
V_6 . V_12 , V_6 . V_13 ) ;
V_25 = V_9 -> V_27 ( V_16 ) ;
if ( F_7 ( V_25 ) ) {
F_5 ( V_16 -> V_16 , L_4 ) ;
V_25 = NULL ;
}
if ( V_25 ) {
int V_28 ;
F_8 ( & V_16 -> V_29 ) ;
V_25 -> V_30 -> V_31 ( V_25 ) ;
F_9 ( & V_16 -> V_29 ) ;
F_10 ( V_25 -> V_32 ) ;
V_28 = V_25 -> V_30 -> V_33 ( V_25 ) ;
if ( V_28 ) {
F_4 ( V_16 -> V_16 , L_5 , V_28 ) ;
V_25 -> V_30 -> V_34 ( V_25 ) ;
V_25 = NULL ;
} else {
F_11 ( V_25 -> V_32 ) ;
F_12 ( V_25 ) ;
}
}
return V_25 ;
}
static void F_13 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
V_18 -> V_22 = V_21 ;
}
static int F_14 ( struct V_35 * V_16 , struct V_35 * V_36 , void * V_37 )
{
static struct V_23 V_24 = {} ;
struct V_38 * V_39 , * V_40 = V_16 -> V_41 ;
T_2 V_42 ;
int V_28 , V_7 ;
V_28 = F_15 ( V_40 , L_6 , & V_42 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_7 , V_28 ) ;
return V_28 ;
}
V_24 . V_6 = F_16 ( ( V_42 >> 24 ) & 0xff ,
( V_42 >> 16 ) & 0xff , ( V_42 >> 8 ) & 0xff , V_42 & 0xff ) ;
V_24 . V_43 = 0 ;
V_24 . V_44 = ~ 0 ;
F_17 (node, child) {
if ( F_18 ( V_39 , L_8 ) ) {
struct V_38 * V_45 ;
F_17 (child, pwrlvl) {
V_28 = F_15 ( V_45 , L_9 , & V_42 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_10 , V_28 ) ;
return V_28 ;
}
V_24 . V_43 = F_19 ( V_24 . V_43 , V_42 ) ;
V_24 . V_44 = F_20 ( V_24 . V_44 , V_42 ) ;
}
}
}
if ( ! V_24 . V_43 ) {
F_4 ( V_16 , L_11 ) ;
return - V_46 ;
}
for ( V_7 = 0 ; V_7 < F_2 ( V_47 ) ; V_7 ++ )
if ( F_21 ( V_40 , V_47 [ V_7 ] . V_48 ) )
V_24 . V_47 |= V_47 [ V_7 ] . V_49 ;
V_16 -> V_26 = & V_24 ;
F_13 ( F_22 ( V_36 ) , F_23 ( V_16 ) ) ;
return 0 ;
}
static void F_24 ( struct V_35 * V_16 , struct V_35 * V_36 ,
void * V_37 )
{
F_13 ( F_22 ( V_36 ) , NULL ) ;
}
static int F_25 ( struct V_20 * V_21 )
{
return F_26 ( & V_21 -> V_16 , & V_50 ) ;
}
static int F_27 ( struct V_20 * V_21 )
{
F_28 ( & V_21 -> V_16 , & V_50 ) ;
return 0 ;
}
void T_3 F_29 ( void )
{
F_30 ( & V_51 ) ;
}
void T_4 F_31 ( void )
{
F_32 ( & V_51 ) ;
}
