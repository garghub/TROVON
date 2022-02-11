static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_7 )
return;
F_5 ( V_1 -> V_7 , 1 ) ;
F_6 ( 150 , 200 ) ;
F_5 ( V_1 -> V_7 , 0 ) ;
}
static enum V_8
F_7 ( struct V_4 * V_6 , bool V_9 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
unsigned int V_10 ;
F_8 ( V_1 -> V_11 , V_12 , & V_10 ) ;
return ( V_10 & V_13 ) ?
V_14 : V_15 ;
}
static int F_9 ( struct V_4 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_11 = V_1 -> V_11 ;
T_1 V_16 = V_17 ;
unsigned long V_18 ;
unsigned int V_10 ;
struct V_19 * V_19 ;
int V_20 = 0 ;
int V_21 ;
V_21 = F_10 ( V_11 , V_22 ,
V_23 ,
V_23 ) ;
if ( V_21 )
return V_21 ;
V_18 = V_24 +
F_11 ( V_25 ) ;
do {
V_21 = F_8 ( V_11 , V_22 , & V_10 ) ;
if ( V_21 )
return V_21 ;
} while ( ! ( V_10 & V_26 ) &&
F_12 ( V_24 , V_18 ) );
if ( ! ( V_10 & V_26 ) ) {
F_13 ( & V_1 -> V_27 -> V_28 , L_1 ) ;
return - V_29 ;
}
V_21 = F_14 ( V_11 , V_22 , V_10 ) ;
if ( V_21 )
return V_21 ;
V_19 = F_15 ( V_6 , V_1 -> V_27 -> V_30 ) ;
F_16 ( V_6 , V_19 ) ;
if ( V_19 ) {
V_20 = F_17 ( V_6 , V_19 ) ;
F_18 ( V_19 ) ;
}
V_21 = F_19 ( & V_6 -> V_31 ,
& V_16 , 1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_8 ( V_11 , V_22 , & V_10 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_11 , V_22 ,
V_23 |
V_26 , 0 ) ;
if ( V_21 )
return V_21 ;
V_18 = V_24 +
F_11 ( V_25 ) ;
do {
V_21 = F_8 ( V_11 , V_22 , & V_10 ) ;
if ( V_21 )
return V_21 ;
} while ( V_10 & ( V_23 |
V_26 ) &&
F_12 ( V_24 , V_18 ) );
if ( V_10 & ( V_23 |
V_26 ) ) {
F_13 ( & V_1 -> V_27 -> V_28 , L_2 ) ;
return - V_29 ;
}
return V_20 ;
}
static enum V_32 F_20 ( struct V_4 * V_6 ,
struct V_33 * V_34 )
{
return V_35 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_10 ( V_1 -> V_11 , V_22 ,
V_36 ,
V_36 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_10 ( V_1 -> V_11 , V_37 ,
V_38 ,
F_23 ( 0 ) ) ;
F_10 ( V_1 -> V_11 , V_22 ,
V_36 , 0 ) ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_33 * V_39 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_11 = V_1 -> V_11 ;
T_2 V_40 [ F_25 ( V_41 ) ] ;
struct V_42 V_43 ;
int V_21 ;
V_40 [ 0 ] = V_39 -> clock ;
V_40 [ 1 ] = V_39 -> clock >> 8 ;
V_40 [ 2 ] = V_39 -> V_44 ;
V_40 [ 3 ] = 0x00 ;
V_40 [ 4 ] = V_39 -> V_45 ;
V_40 [ 5 ] = V_39 -> V_45 >> 8 ;
V_40 [ 6 ] = V_39 -> V_46 ;
V_40 [ 7 ] = V_39 -> V_46 >> 8 ;
V_40 [ 8 ] = V_47 | V_48 |
V_49 ;
V_40 [ 9 ] = V_50 |
V_51 ;
V_21 = F_26 ( V_11 , V_52 , V_40 , 10 ) ;
if ( V_21 )
return;
V_21 = F_27 ( & V_43 , V_39 , false ) ;
if ( V_21 < 0 ) {
F_28 ( L_3 ) ;
return;
}
V_21 = F_29 ( & V_43 , V_40 , sizeof( V_40 ) ) ;
if ( V_21 < 0 ) {
F_28 ( L_4 , V_21 ) ;
return;
}
F_26 ( V_11 , V_53 ,
V_40 + V_54 - 1 ,
V_55 + 1 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_56 * V_57 = V_3 -> V_28 ;
int V_21 ;
F_31 ( & V_1 -> V_6 ,
& V_58 ) ;
if ( ! F_32 ( V_57 , V_59 ) ) {
F_13 ( & V_1 -> V_27 -> V_28 ,
L_5 ) ;
return - V_60 ;
}
V_21 = F_33 ( V_57 , & V_1 -> V_6 ,
& V_61 ,
V_62 ) ;
if ( V_21 )
return V_21 ;
if ( V_1 -> V_27 -> V_63 > 0 )
V_1 -> V_6 . V_64 = V_65 ;
else
V_1 -> V_6 . V_64 = V_66 ;
F_34 ( & V_1 -> V_6 , V_3 -> V_67 ) ;
return 0 ;
}
static T_3 F_35 ( int V_63 , void * V_68 )
{
struct V_1 * V_1 = V_68 ;
unsigned int V_10 = 0 ;
F_8 ( V_1 -> V_11 , V_12 , & V_10 ) ;
F_14 ( V_1 -> V_11 , V_12 , V_10 ) ;
if ( ( V_10 & V_69 ) && V_1 -> V_3 . V_28 )
F_36 ( V_1 -> V_3 . V_28 ) ;
return V_70 ;
}
static int F_37 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_75 * V_28 = & V_72 -> V_28 ;
unsigned int V_10 = 0 ;
struct V_1 * V_1 ;
T_2 V_76 [ 4 ] ;
int V_21 ;
V_1 = F_38 ( V_28 , sizeof( * V_1 ) , V_77 ) ;
if ( ! V_1 )
return - V_78 ;
V_1 -> V_27 = V_72 ;
V_1 -> V_11 = F_39 ( V_72 , & V_79 ) ;
if ( F_40 ( V_1 -> V_11 ) )
return F_41 ( V_1 -> V_11 ) ;
V_1 -> V_7 = F_42 ( V_28 , L_6 ,
V_80 ) ;
if ( F_40 ( V_1 -> V_7 ) ) {
F_13 ( V_28 , L_7 ,
F_41 ( V_1 -> V_7 ) ) ;
return F_41 ( V_1 -> V_7 ) ;
}
F_4 ( V_1 ) ;
V_21 = F_14 ( V_1 -> V_11 , V_81 , 0x0 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_43 ( V_1 -> V_11 , F_44 ( 0 ) ,
& V_76 , 4 ) ;
if ( V_21 ) {
F_13 ( V_28 , L_8 , V_21 ) ;
return V_21 ;
}
if ( V_76 [ 0 ] != 0xb0 ) {
F_13 ( V_28 , L_9 ,
V_76 [ 0 ] ) ;
return - V_82 ;
}
F_8 ( V_1 -> V_11 , V_12 , & V_10 ) ;
F_14 ( V_1 -> V_11 , V_12 , V_10 ) ;
if ( V_72 -> V_63 > 0 ) {
F_14 ( V_1 -> V_11 , V_83 ,
V_69 ) ;
V_21 = F_45 ( V_28 , V_72 -> V_63 , NULL ,
F_35 ,
V_84 , F_46 ( V_28 ) ,
V_1 ) ;
if ( V_21 )
return V_21 ;
}
V_1 -> V_3 . V_85 = & V_86 ;
V_1 -> V_3 . V_87 = V_28 -> V_87 ;
F_47 ( & V_1 -> V_3 ) ;
F_48 ( V_72 , V_1 ) ;
return 0 ;
}
static int F_49 ( struct V_71 * V_72 )
{
struct V_1 * V_1 = F_50 ( V_72 ) ;
F_51 ( & V_1 -> V_3 ) ;
return 0 ;
}
