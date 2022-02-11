int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( F_2 ( V_4 -> V_6 , 0x1a8 ) == 1 )
return F_3 ( V_4 , 0x20400 ) ;
else
return - V_7 ;
}
void
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( F_2 ( V_4 -> V_6 , 0x1a8 ) == 1 ) {
F_5 ( V_4 , 0x20008 , 0x80008000 , 0x80000000 ) ;
F_5 ( V_4 , 0x2000c , 0x80000003 , 0x00000000 ) ;
F_6 ( 20 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 ;
struct V_11 * V_5 = & V_2 -> V_5 ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_12 ;
F_8 ( & V_2 -> V_9 . V_13 , V_12 ) ;
F_9 ( V_4 , 0x20000 , 0x000003ff ) ;
F_9 ( V_4 , 0x20484 , V_9 -> V_14 . V_15 ) ;
F_9 ( V_4 , 0x20480 , V_9 -> V_14 . V_16 ) ;
F_9 ( V_4 , 0x204c4 , V_9 -> V_17 . V_16 ) ;
F_9 ( V_4 , 0x204c0 , V_9 -> V_18 . V_16 ) ;
F_9 ( V_4 , 0x20414 , V_9 -> V_19 . V_16 ) ;
F_10 ( & V_2 -> V_9 . V_13 , V_12 ) ;
F_11 ( V_5 ,
L_1 ,
V_9 -> V_17 . V_16 ,
V_9 -> V_17 . V_15 ,
V_9 -> V_19 . V_16 ,
V_9 -> V_19 . V_15 ,
V_9 -> V_18 . V_16 ,
V_9 -> V_18 . V_15 ,
V_9 -> V_14 . V_16 ,
V_9 -> V_14 . V_15 ) ;
}
static void
F_12 ( struct V_1 * V_2 ,
T_1 V_20 , T_2 V_21 ,
const struct V_22 * V_23 ,
enum V_24 V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
enum V_26 V_27 ;
enum V_28 V_29 , V_30 ;
int V_16 , V_31 ;
V_29 = F_13 ( V_2 , V_25 ) ;
V_16 = F_3 ( V_4 , V_20 ) ;
if ( V_16 == V_23 -> V_16 ) {
F_9 ( V_4 , V_20 , V_23 -> V_16 - V_23 -> V_15 ) ;
V_30 = V_32 ;
} else {
F_9 ( V_4 , V_20 , V_23 -> V_16 ) ;
V_30 = V_33 ;
}
V_31 = V_2 -> V_34 -> V_35 ( V_2 ) ;
if ( V_30 == V_33 && V_31 > V_23 -> V_16 )
V_30 = V_32 ;
else if ( V_30 == V_32 &&
V_31 < V_23 -> V_16 - V_23 -> V_15 )
V_30 = V_33 ;
F_14 ( V_2 , V_25 , V_30 ) ;
if ( V_29 < V_30 )
V_27 = V_36 ;
else if ( V_29 > V_30 )
V_27 = V_37 ;
else
return;
F_15 ( V_2 , V_25 , V_27 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
struct V_11 * V_5 = & V_2 -> V_5 ;
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
unsigned long V_12 ;
T_1 V_38 ;
F_8 ( & V_2 -> V_9 . V_13 , V_12 ) ;
V_38 = F_3 ( V_4 , 0x20100 ) & 0x3ff ;
if ( V_38 & 0x002 ) {
F_12 ( V_2 , 0x20414 , 24 ,
& V_9 -> V_19 ,
V_39 ) ;
V_38 &= ~ 0x002 ;
}
if ( V_38 & 0x004 ) {
F_12 ( V_2 , 0x20480 , 20 ,
& V_9 -> V_14 ,
V_40 ) ;
V_38 &= ~ 0x004 ;
}
if ( V_38 & 0x008 ) {
F_12 ( V_2 , 0x204c4 , 21 ,
& V_9 -> V_17 ,
V_41 ) ;
V_38 &= ~ 0x008 ;
}
if ( V_38 & 0x010 ) {
F_12 ( V_2 , 0x204c0 , 22 ,
& V_9 -> V_18 ,
V_42 ) ;
V_38 &= ~ 0x010 ;
}
if ( V_38 )
F_17 ( V_5 , L_2 , V_38 ) ;
F_9 ( V_4 , 0x20100 , 0xffffffff ) ;
F_9 ( V_4 , 0x1100 , 0x10000 ) ;
F_10 ( & V_2 -> V_9 . V_13 , V_12 ) ;
}
void
F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
F_9 ( V_4 , 0x20000 , 0x00000000 ) ;
F_9 ( V_4 , 0x20100 , 0xffffffff ) ;
F_9 ( V_4 , 0x1100 , 0x10000 ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
int
F_20 ( struct V_3 * V_4 , int V_43 , struct V_1 * * V_44 )
{
struct V_1 * V_2 ;
int V_45 ;
V_45 = F_21 ( & V_46 , V_4 , V_43 , & V_2 ) ;
* V_44 = V_2 ;
if ( V_45 )
return V_45 ;
F_14 ( V_2 , V_40 ,
V_33 ) ;
F_14 ( V_2 , V_41 ,
V_33 ) ;
F_14 ( V_2 , V_42 ,
V_33 ) ;
F_14 ( V_2 , V_39 ,
V_33 ) ;
return 0 ;
}
