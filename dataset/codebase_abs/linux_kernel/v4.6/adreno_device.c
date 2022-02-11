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
V_28 = V_25 -> V_30 -> V_32 ( V_25 ) ;
if ( V_28 ) {
F_4 ( V_16 -> V_16 , L_5 , V_28 ) ;
V_25 -> V_30 -> V_33 ( V_25 ) ;
V_25 = NULL ;
} else {
F_10 ( V_25 ) ;
}
}
return V_25 ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_20 * V_21 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
V_18 -> V_22 = V_21 ;
}
static int F_12 ( struct V_34 * V_16 , struct V_34 * V_35 , void * V_36 )
{
static struct V_23 V_24 = {} ;
struct V_37 * V_38 , * V_39 = V_16 -> V_40 ;
T_2 V_41 ;
int V_28 ;
V_28 = F_13 ( V_39 , L_6 , & V_41 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_7 , V_28 ) ;
return V_28 ;
}
V_24 . V_6 = F_14 ( ( V_41 >> 24 ) & 0xff ,
( V_41 >> 16 ) & 0xff , ( V_41 >> 8 ) & 0xff , V_41 & 0xff ) ;
V_24 . V_42 = 0 ;
V_24 . V_43 = ~ 0 ;
F_15 (node, child) {
if ( F_16 ( V_38 , L_8 ) ) {
struct V_37 * V_44 ;
F_15 (child, pwrlvl) {
V_28 = F_13 ( V_44 , L_9 , & V_41 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_10 , V_28 ) ;
return V_28 ;
}
V_24 . V_42 = F_17 ( V_24 . V_42 , V_41 ) ;
V_24 . V_43 = F_18 ( V_24 . V_43 , V_41 ) ;
}
}
}
if ( ! V_24 . V_42 ) {
F_4 ( V_16 , L_11 ) ;
return - V_45 ;
}
V_16 -> V_26 = & V_24 ;
F_11 ( F_19 ( V_35 ) , F_20 ( V_16 ) ) ;
return 0 ;
}
static void F_21 ( struct V_34 * V_16 , struct V_34 * V_35 ,
void * V_36 )
{
F_11 ( F_19 ( V_35 ) , NULL ) ;
}
static int F_22 ( struct V_20 * V_21 )
{
return F_23 ( & V_21 -> V_16 , & V_46 ) ;
}
static int F_24 ( struct V_20 * V_21 )
{
F_25 ( & V_21 -> V_16 , & V_46 ) ;
return 0 ;
}
void T_3 F_26 ( void )
{
F_27 ( & V_47 ) ;
}
void T_4 F_28 ( void )
{
F_29 ( & V_47 ) ;
}
