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
F_8 ( & V_21 -> V_16 ) ;
F_9 ( & V_16 -> V_29 ) ;
V_28 = F_10 ( V_25 ) ;
F_11 ( & V_16 -> V_29 ) ;
F_12 ( & V_21 -> V_16 ) ;
if ( V_28 ) {
F_4 ( V_16 -> V_16 , L_5 , V_28 ) ;
V_25 -> V_30 -> V_31 ( V_25 ) ;
V_25 = NULL ;
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
static int F_14 ( struct V_32 * V_16 , T_2 * V_33 )
{
struct V_34 * V_35 = V_16 -> V_36 ;
const char * V_37 ;
int V_28 ;
V_28 = F_15 ( V_35 , L_6 , 0 , & V_37 ) ;
if ( V_28 == 0 ) {
unsigned V_6 , V_38 ;
if ( sscanf ( V_37 , L_7 , & V_6 , & V_38 ) == 2 ) {
* V_33 = 0 ;
* V_33 |= ( V_6 / 100 ) << 24 ;
V_6 %= 100 ;
* V_33 |= ( V_6 / 10 ) << 16 ;
V_6 %= 10 ;
* V_33 |= V_6 << 8 ;
* V_33 |= V_38 ;
return 0 ;
}
}
V_28 = F_16 ( V_35 , L_8 , V_33 ) ;
if ( V_28 )
return V_28 ;
F_5 ( V_16 , L_9 ) ;
F_5 ( V_16 , L_10 ,
( * V_33 >> 24 ) & 0xff , ( * V_33 >> 16 ) & 0xff ,
( * V_33 >> 8 ) & 0xff , * V_33 & 0xff ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_16 )
{
struct V_34 * V_39 , * V_35 ;
int V_28 ;
V_35 = F_18 ( V_16 -> V_36 , NULL ,
L_11 ) ;
if ( ! V_35 ) {
F_4 ( V_16 , L_12 ) ;
return - V_40 ;
}
F_19 (node, child) {
unsigned int V_41 ;
V_28 = F_16 ( V_39 , L_13 , & V_41 ) ;
if ( V_28 )
continue;
if ( V_41 != 27000000 )
F_20 ( V_16 , V_41 , 0 ) ;
}
return 0 ;
}
static int F_21 ( struct V_32 * V_16 ,
struct V_23 * V_24 )
{
unsigned long V_42 = V_43 ;
struct V_44 * V_45 ;
int V_28 ;
if ( ! F_22 ( V_16 -> V_36 , L_14 , NULL ) )
V_28 = F_17 ( V_16 ) ;
else
V_28 = F_23 ( V_16 ) ;
if ( V_28 )
return V_28 ;
V_45 = F_24 ( V_16 , & V_42 ) ;
if ( ! F_7 ( V_45 ) )
V_24 -> V_46 = F_25 ( V_45 ) ;
if ( ! V_24 -> V_46 ) {
F_26 ( V_16 ,
L_15 ) ;
V_24 -> V_46 = 200000000 ;
}
return 0 ;
}
static int F_27 ( struct V_32 * V_16 , struct V_32 * V_47 , void * V_48 )
{
static struct V_23 V_24 = {} ;
T_2 V_41 ;
int V_28 ;
V_28 = F_14 ( V_16 , & V_41 ) ;
if ( V_28 ) {
F_4 ( V_16 , L_16 , V_28 ) ;
return V_28 ;
}
V_24 . V_6 = F_28 ( ( V_41 >> 24 ) & 0xff ,
( V_41 >> 16 ) & 0xff , ( V_41 >> 8 ) & 0xff , V_41 & 0xff ) ;
V_24 . V_46 = 0 ;
V_28 = F_21 ( V_16 , & V_24 ) ;
if ( V_28 )
return V_28 ;
V_16 -> V_26 = & V_24 ;
F_13 ( F_29 ( V_47 ) , F_30 ( V_16 ) ) ;
return 0 ;
}
static void F_31 ( struct V_32 * V_16 , struct V_32 * V_47 ,
void * V_48 )
{
F_13 ( F_29 ( V_47 ) , NULL ) ;
}
static int F_32 ( struct V_20 * V_21 )
{
return F_33 ( & V_21 -> V_16 , & V_49 ) ;
}
static int F_34 ( struct V_20 * V_21 )
{
F_35 ( & V_21 -> V_16 , & V_49 ) ;
return 0 ;
}
static int F_36 ( struct V_32 * V_16 )
{
struct V_20 * V_21 = F_30 ( V_16 ) ;
struct V_14 * V_25 = F_37 ( V_21 ) ;
return V_25 -> V_30 -> V_50 ( V_25 ) ;
}
static int F_38 ( struct V_32 * V_16 )
{
struct V_20 * V_21 = F_30 ( V_16 ) ;
struct V_14 * V_25 = F_37 ( V_21 ) ;
return V_25 -> V_30 -> V_51 ( V_25 ) ;
}
void T_3 F_39 ( void )
{
F_40 ( & V_52 ) ;
}
void T_4 F_41 ( void )
{
F_42 ( & V_52 ) ;
}
