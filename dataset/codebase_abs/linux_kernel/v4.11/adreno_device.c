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
static int F_14 ( struct V_35 * V_16 , T_2 * V_36 )
{
struct V_37 * V_38 = V_16 -> V_39 ;
const char * V_40 ;
int V_28 ;
V_28 = F_15 ( V_38 , L_6 , 0 , & V_40 ) ;
if ( V_28 == 0 ) {
unsigned V_6 , V_41 ;
if ( sscanf ( V_40 , L_7 , & V_6 , & V_41 ) == 2 ) {
* V_36 = 0 ;
* V_36 |= ( V_6 / 100 ) << 24 ;
V_6 %= 100 ;
* V_36 |= ( V_6 / 10 ) << 16 ;
V_6 %= 10 ;
* V_36 |= V_6 << 8 ;
* V_36 |= V_41 ;
return 0 ;
}
}
V_28 = F_16 ( V_38 , L_8 , V_36 ) ;
if ( V_28 )
return V_28 ;
F_5 ( V_16 , L_9 ) ;
F_5 ( V_16 , L_10 ,
( * V_36 >> 24 ) & 0xff , ( * V_36 >> 16 ) & 0xff ,
( * V_36 >> 8 ) & 0xff , * V_36 & 0xff ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_16 , struct V_35 * V_42 , void * V_43 )
{
static struct V_23 V_24 = {} ;
struct V_37 * V_44 , * V_38 = V_16 -> V_39 ;
T_2 V_45 ;
int V_28 ;
V_28 = F_14 ( V_16 , & V_45 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_11 , V_28 ) ;
return V_28 ;
}
V_24 . V_6 = F_18 ( ( V_45 >> 24 ) & 0xff ,
( V_45 >> 16 ) & 0xff , ( V_45 >> 8 ) & 0xff , V_45 & 0xff ) ;
V_24 . V_46 = 0 ;
V_24 . V_47 = ~ 0 ;
F_19 (node, child) {
if ( F_20 ( V_44 , L_12 ) ) {
struct V_37 * V_48 ;
F_19 (child, pwrlvl) {
V_28 = F_16 ( V_48 , L_13 , & V_45 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_14 , V_28 ) ;
return V_28 ;
}
V_24 . V_46 = F_21 ( V_24 . V_46 , V_45 ) ;
V_24 . V_47 = F_22 ( V_24 . V_47 , V_45 ) ;
}
}
}
if ( ! V_24 . V_46 ) {
F_5 ( V_16 , L_15 ) ;
V_24 . V_46 = 200000000 ;
V_24 . V_47 = 27000000 ;
}
V_16 -> V_26 = & V_24 ;
F_13 ( F_23 ( V_42 ) , F_24 ( V_16 ) ) ;
return 0 ;
}
static void F_25 ( struct V_35 * V_16 , struct V_35 * V_42 ,
void * V_43 )
{
F_13 ( F_23 ( V_42 ) , NULL ) ;
}
static int F_26 ( struct V_20 * V_21 )
{
return F_27 ( & V_21 -> V_16 , & V_49 ) ;
}
static int F_28 ( struct V_20 * V_21 )
{
F_29 ( & V_21 -> V_16 , & V_49 ) ;
return 0 ;
}
void T_3 F_30 ( void )
{
F_31 ( & V_50 ) ;
}
void T_4 F_32 ( void )
{
F_33 ( & V_50 ) ;
}
