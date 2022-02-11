int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( F_2 ( V_4 , 0x1a8 ) == 1 )
return F_3 ( V_2 , 0x20400 ) ;
else
return - V_5 ;
}
void
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( F_2 ( V_4 , 0x1a8 ) == 1 ) {
F_5 ( V_2 , 0x20008 , 0x80008000 , 0x80000000 ) ;
F_5 ( V_2 , 0x2000c , 0x80000003 , 0x00000000 ) ;
F_6 ( 20 ) ;
}
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_8 * V_9 = & V_7 -> V_10 ;
unsigned long V_11 ;
F_8 ( & V_7 -> V_9 . V_12 , V_11 ) ;
F_9 ( V_2 , 0x20000 , 0x000003ff ) ;
F_9 ( V_2 , 0x20484 , V_9 -> V_13 . V_14 ) ;
F_9 ( V_2 , 0x20480 , V_9 -> V_13 . V_15 ) ;
F_9 ( V_2 , 0x204c4 , V_9 -> V_16 . V_15 ) ;
F_9 ( V_2 , 0x204c0 , V_9 -> V_17 . V_15 ) ;
F_9 ( V_2 , 0x20414 , V_9 -> V_18 . V_15 ) ;
F_10 ( & V_7 -> V_9 . V_12 , V_11 ) ;
F_11 ( V_2 ,
L_1 ,
V_9 -> V_16 . V_15 , V_9 -> V_16 . V_14 ,
V_9 -> V_18 . V_15 ,
V_9 -> V_18 . V_14 ,
V_9 -> V_17 . V_15 , V_9 -> V_17 . V_14 ,
V_9 -> V_13 . V_15 , V_9 -> V_13 . V_14 ) ;
}
static void
F_12 ( struct V_1 * V_2 ,
T_1 V_19 , T_2 V_20 ,
const struct V_21 * V_22 ,
enum V_23 V_24 )
{
enum V_25 V_26 ;
enum V_27 V_28 , V_29 ;
int V_15 , V_30 ;
V_28 = F_13 ( V_2 , V_24 ) ;
V_15 = F_3 ( V_2 , V_19 ) ;
if ( V_15 == V_22 -> V_15 ) {
F_9 ( V_2 , V_19 , V_22 -> V_15 - V_22 -> V_14 ) ;
V_29 = V_31 ;
} else {
F_9 ( V_2 , V_19 , V_22 -> V_15 ) ;
V_29 = V_32 ;
}
V_30 = V_2 -> V_33 ( V_2 ) ;
if ( V_29 == V_32 && V_30 > V_22 -> V_15 )
V_29 = V_31 ;
else if ( V_29 == V_31 &&
V_30 < V_22 -> V_15 - V_22 -> V_14 )
V_29 = V_32 ;
F_14 ( V_2 , V_24 , V_29 ) ;
if ( V_28 < V_29 )
V_26 = V_34 ;
else if ( V_28 > V_29 )
V_26 = V_35 ;
else
return;
F_15 ( V_2 , V_24 , V_26 ) ;
}
static void
F_16 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_1 ( V_37 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_8 * V_9 = & V_7 -> V_10 ;
unsigned long V_11 ;
T_1 V_38 ;
F_8 ( & V_7 -> V_9 . V_12 , V_11 ) ;
V_38 = F_3 ( V_2 , 0x20100 ) & 0x3ff ;
if ( V_38 & 0x002 ) {
F_12 ( V_2 , 0x20414 , 24 ,
& V_9 -> V_18 ,
V_39 ) ;
V_38 &= ~ 0x002 ;
}
if ( V_38 & 0x004 ) {
F_12 ( V_2 , 0x20480 , 20 ,
& V_9 -> V_13 ,
V_40 ) ;
V_38 &= ~ 0x004 ;
}
if ( V_38 & 0x008 ) {
F_12 ( V_2 , 0x204c4 , 21 ,
& V_9 -> V_16 ,
V_41 ) ;
V_38 &= ~ 0x008 ;
}
if ( V_38 & 0x010 ) {
F_12 ( V_2 , 0x204c0 , 22 ,
& V_9 -> V_17 ,
V_42 ) ;
V_38 &= ~ 0x010 ;
}
if ( V_38 )
F_17 ( V_2 , L_2 , V_38 ) ;
F_9 ( V_2 , 0x20100 , 0xffffffff ) ;
F_9 ( V_2 , 0x1100 , 0x10000 ) ;
F_10 ( & V_7 -> V_9 . V_12 , V_11 ) ;
}
static int
F_18 ( struct V_43 * V_44 )
{
struct V_45 * V_7 = ( void * ) V_44 ;
int V_46 ;
V_46 = F_19 ( & V_7 -> V_47 . V_47 ) ;
if ( V_46 )
return V_46 ;
F_4 ( & V_7 -> V_47 . V_47 ) ;
return 0 ;
}
static int
F_20 ( struct V_43 * V_48 ,
struct V_43 * V_49 ,
struct V_50 * V_51 , void * V_52 , T_3 V_53 ,
struct V_43 * * V_54 )
{
struct V_45 * V_7 ;
int V_46 ;
V_46 = F_21 ( V_48 , V_49 , V_51 , & V_7 ) ;
* V_54 = F_22 ( V_7 ) ;
if ( V_46 )
return V_46 ;
V_7 -> V_47 . V_47 . V_55 = V_56 ;
V_7 -> V_47 . V_47 . V_57 = V_58 ;
V_7 -> V_47 . V_47 . V_59 = V_60 ;
V_7 -> V_47 . V_47 . V_61 = V_62 ;
V_7 -> V_47 . V_47 . V_33 = F_1 ;
V_7 -> V_47 . V_9 . V_63 = F_7 ;
F_23 ( V_7 ) -> V_38 = F_16 ;
F_14 ( & V_7 -> V_47 . V_47 ,
V_40 ,
V_32 ) ;
F_14 ( & V_7 -> V_47 . V_47 ,
V_41 ,
V_32 ) ;
F_14 ( & V_7 -> V_47 . V_47 ,
V_42 ,
V_32 ) ;
F_14 ( & V_7 -> V_47 . V_47 ,
V_39 ,
V_32 ) ;
return F_24 ( & V_7 -> V_47 . V_47 ) ;
}
int
F_25 ( struct V_43 * V_44 , bool V_64 )
{
F_9 ( V_44 , 0x20000 , 0x00000000 ) ;
F_9 ( V_44 , 0x20100 , 0xffffffff ) ;
F_9 ( V_44 , 0x1100 , 0x10000 ) ;
return F_26 ( V_44 , V_64 ) ;
}
