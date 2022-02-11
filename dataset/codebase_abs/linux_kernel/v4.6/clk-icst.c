static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_2 -> V_8 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_9 = V_5 & 0x1ff ;
V_4 -> V_10 = ( V_5 >> 9 ) & 0x7f ;
V_4 -> V_11 = ( V_5 >> 16 ) & 03 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_2 -> V_8 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_5 &= ~ 0x7ffff ;
V_5 |= V_4 . V_9 | ( V_4 . V_10 << 9 ) | ( V_4 . V_11 << 16 ) ;
V_6 = F_4 ( V_2 -> V_7 , V_2 -> V_12 , V_13 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_4 ( V_2 -> V_7 , V_2 -> V_8 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_4 ( V_2 -> V_7 , V_2 -> V_12 , 0 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static unsigned long F_5 ( struct V_14 * V_15 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_3 V_4 ;
int V_6 ;
if ( V_16 )
V_2 -> V_17 -> V_18 = V_16 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 ) {
F_7 ( L_1 ) ;
return 0 ;
}
V_2 -> V_19 = F_8 ( V_2 -> V_17 , V_4 ) ;
return V_2 -> V_19 ;
}
static long F_9 ( struct V_14 * V_15 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_3 V_4 ;
V_4 = F_10 ( V_2 -> V_17 , V_19 ) ;
return F_8 ( V_2 -> V_17 , V_4 ) ;
}
static int F_11 ( struct V_14 * V_15 , unsigned long V_19 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
struct V_3 V_4 ;
if ( V_16 )
V_2 -> V_17 -> V_18 = V_16 ;
V_4 = F_10 ( V_2 -> V_17 , V_19 ) ;
V_2 -> V_19 = F_8 ( V_2 -> V_17 , V_4 ) ;
return F_3 ( V_2 , V_4 ) ;
}
static struct V_21 * F_12 ( struct V_22 * V_23 ,
const struct V_24 * V_25 ,
const char * V_26 ,
const char * V_27 ,
struct V_28 * V_7 )
{
struct V_21 * V_21 ;
struct V_1 * V_2 ;
struct V_29 V_30 ;
struct V_31 * V_32 ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_2 ) {
F_7 ( L_2 ) ;
return F_14 ( - V_34 ) ;
}
V_32 = F_15 ( V_25 -> V_17 , sizeof( * V_32 ) , V_33 ) ;
if ( ! V_32 ) {
F_16 ( V_2 ) ;
F_7 ( L_3 ) ;
return F_14 ( - V_34 ) ;
}
V_30 . V_26 = V_26 ;
V_30 . V_35 = & V_36 ;
V_30 . V_37 = 0 ;
V_30 . V_38 = ( V_27 ? & V_27 : NULL ) ;
V_30 . V_39 = ( V_27 ? 1 : 0 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_15 . V_30 = & V_30 ;
V_2 -> V_17 = V_32 ;
V_2 -> V_8 = V_25 -> V_40 ;
V_2 -> V_12 = V_25 -> V_41 ;
V_21 = F_17 ( V_23 , & V_2 -> V_15 ) ;
if ( F_18 ( V_21 ) ) {
F_16 ( V_32 ) ;
F_16 ( V_2 ) ;
}
return V_21 ;
}
struct V_21 * F_19 ( struct V_22 * V_23 ,
const struct V_24 * V_25 ,
const char * V_26 ,
const char * V_27 ,
void T_2 * V_42 )
{
struct V_43 V_44 = {
. V_45 = 32 ,
. V_46 = 32 ,
. V_47 = 4 ,
} ;
struct V_28 * V_7 ;
V_7 = F_20 ( V_23 , V_42 , & V_44 ) ;
if ( F_18 ( V_7 ) ) {
F_7 ( L_4 ) ;
return F_21 ( V_7 ) ;
}
return F_12 ( V_23 , V_25 , V_26 , V_27 , V_7 ) ;
}
static void T_3 F_22 ( struct V_48 * V_49 )
{
struct V_48 * V_50 ;
struct V_28 * V_7 ;
struct V_24 V_51 ;
const char * V_26 = V_49 -> V_26 ;
const char * V_27 ;
struct V_21 * V_52 ;
V_50 = F_23 ( V_49 ) ;
if ( ! V_50 ) {
F_7 ( L_5 ) ;
return;
}
V_7 = F_24 ( V_50 ) ;
if ( F_18 ( V_7 ) ) {
F_7 ( L_6 ) ;
return;
}
if ( F_25 ( V_49 , L_7 , & V_51 . V_40 ) ) {
F_7 ( L_8 ) ;
return;
}
if ( F_25 ( V_49 , L_9 , & V_51 . V_41 ) ) {
F_7 ( L_10 ) ;
return;
}
if ( F_26 ( V_49 , L_11 ) )
V_51 . V_17 = & V_53 ;
else if ( F_26 ( V_49 , L_12 ) )
V_51 . V_17 = & V_54 ;
else {
F_7 ( L_13 , V_26 ) ;
return;
}
V_27 = F_27 ( V_49 , 0 ) ;
V_52 = F_12 ( NULL , & V_51 , V_26 , V_27 , V_7 ) ;
if ( F_18 ( V_52 ) ) {
F_7 ( L_14 , V_26 ) ;
return;
}
F_28 ( V_49 , V_55 , V_52 ) ;
F_29 ( L_15 , V_26 ) ;
}
