static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 * V_2 -> V_6 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 * V_2 -> V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 = F_3 ( V_2 , V_10 ) ;
if ( ( V_2 -> V_11 == V_12 ) || ( V_2 -> V_11 == V_13 ) ) {
F_1 ( V_2 , V_14 , V_15 ) ;
F_6 ( & V_2 -> V_16 ) ;
return;
}
if ( V_9 & V_17 ) {
V_2 -> V_11 = V_13 ;
F_1 ( V_2 , V_14 , V_18 ) ;
return;
}
if ( ( V_2 -> V_11 == V_19 ) || ( V_2 -> V_11 == V_20 ) ) {
V_2 -> V_11 =
( V_8 -> V_21 & V_22 ) ? V_23 : V_20 ;
if ( V_9 & V_24 ) {
V_2 -> V_11 = V_13 ;
F_1 ( V_2 , V_14 , V_18 ) ;
return;
}
} else
V_8 -> V_25 [ V_2 -> V_26 ++ ] = F_3 ( V_2 , V_27 ) ;
if ( V_2 -> V_26 == V_8 -> V_28 ) {
V_2 -> V_29 -- ;
V_2 -> V_8 ++ ;
V_2 -> V_26 = 0 ;
V_8 = V_2 -> V_8 ;
if ( V_2 -> V_29 ) {
if ( ! ( V_8 -> V_21 & V_30 ) ) {
T_1 V_31 = ( V_8 -> V_31 << 1 ) ;
if ( V_8 -> V_21 & V_22 )
V_31 |= 1 ;
V_2 -> V_11 = V_19 ;
F_1 ( V_2 , V_27 , V_31 ) ;
F_1 ( V_2 , V_14 , V_32 ) ;
return;
} else
V_2 -> V_11 = ( V_8 -> V_21 & V_22 )
? V_23 : V_20 ;
} else {
V_2 -> V_11 = V_12 ;
F_1 ( V_2 , V_14 , V_18 ) ;
return;
}
}
if ( V_2 -> V_11 == V_23 ) {
F_1 ( V_2 , V_14 , V_2 -> V_26 == ( V_8 -> V_28 - 1 ) ?
V_33 : V_34 ) ;
} else {
F_1 ( V_2 , V_27 , V_8 -> V_25 [ V_2 -> V_26 ++ ] ) ;
F_1 ( V_2 , V_14 , V_35 ) ;
}
}
static T_2 F_7 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
F_5 ( V_2 ) ;
return V_38 ;
}
static int F_8 ( struct V_39 * V_40 , struct V_7 * V_41 , int V_42 )
{
struct V_1 * V_2 = F_9 ( V_40 ) ;
V_2 -> V_8 = V_41 ;
V_2 -> V_26 = 0 ;
V_2 -> V_29 = V_42 ;
V_2 -> V_11 = V_19 ;
F_1 ( V_2 , V_27 ,
( V_2 -> V_8 -> V_31 << 1 ) |
( ( V_2 -> V_8 -> V_21 & V_22 ) ? 1 : 0 ) ) ;
F_1 ( V_2 , V_14 , V_32 ) ;
if ( F_10 ( V_2 -> V_16 , ( V_2 -> V_11 == V_13 ) ||
( V_2 -> V_11 == V_12 ) , V_43 ) )
return ( V_2 -> V_11 == V_12 ) ? V_42 : - V_44 ;
else
return - V_45 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_46 ;
T_1 V_47 = F_3 ( V_2 , V_48 ) ;
F_1 ( V_2 , V_48 , V_47 & ~ ( V_49 | V_50 ) ) ;
V_46 = ( V_2 -> V_51 / ( 5 * 100 ) ) - 1 ;
F_1 ( V_2 , V_52 , V_46 & 0xff ) ;
F_1 ( V_2 , V_53 , V_46 >> 8 ) ;
F_1 ( V_2 , V_14 , V_15 ) ;
F_1 ( V_2 , V_48 , V_47 | V_50 | V_49 ) ;
}
static T_3 F_12 ( struct V_39 * V_40 )
{
return V_54 | V_55 ;
}
static int F_13 ( struct V_56 * V_57 ,
struct V_1 * V_2 )
{
const T_4 * V_58 ;
V_58 = F_14 ( V_57 -> V_59 . V_60 , L_1 , NULL ) ;
if ( ! V_58 ) {
F_15 ( & V_57 -> V_59 , L_2 ) ;
return - V_61 ;
}
V_2 -> V_6 = F_16 ( V_58 ) ;
V_58 = F_14 ( V_57 -> V_59 . V_60 , L_3 , NULL ) ;
if ( ! V_58 ) {
F_15 ( & V_57 -> V_59 ,
L_4 ) ;
return - V_61 ;
}
V_2 -> V_51 = F_16 ( V_58 ) / 1000 ;
return 0 ;
}
static int T_5 F_17 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_62 * V_63 ;
struct V_64 * V_65 , * V_66 ;
int V_67 ;
int V_68 ;
V_65 = F_18 ( V_57 , V_69 , 0 ) ;
if ( ! V_65 )
return - V_61 ;
V_66 = F_18 ( V_57 , V_70 , 0 ) ;
if ( ! V_66 )
return - V_61 ;
V_2 = F_19 ( & V_57 -> V_59 , sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
return - V_72 ;
if ( ! F_20 ( & V_57 -> V_59 , V_65 -> V_73 ,
F_21 ( V_65 ) , V_57 -> V_74 ) ) {
F_15 ( & V_57 -> V_59 , L_5 ) ;
return - V_75 ;
}
V_2 -> V_5 = F_22 ( & V_57 -> V_59 , V_65 -> V_73 ,
F_21 ( V_65 ) ) ;
if ( ! V_2 -> V_5 ) {
F_15 ( & V_57 -> V_59 , L_6 ) ;
return - V_44 ;
}
V_63 = V_57 -> V_59 . V_76 ;
if ( V_63 ) {
V_2 -> V_6 = V_63 -> V_6 ;
V_2 -> V_51 = V_63 -> V_51 ;
} else {
V_67 = F_13 ( V_57 , V_2 ) ;
if ( V_67 )
return V_67 ;
}
F_11 ( V_2 ) ;
F_23 ( & V_2 -> V_16 ) ;
V_67 = F_24 ( & V_57 -> V_59 , V_66 -> V_73 , F_7 , 0 ,
V_57 -> V_74 , V_2 ) ;
if ( V_67 ) {
F_15 ( & V_57 -> V_59 , L_7 ) ;
return V_67 ;
}
F_25 ( V_57 , V_2 ) ;
V_2 -> V_40 = V_77 ;
F_26 ( & V_2 -> V_40 , V_2 ) ;
V_2 -> V_40 . V_59 . V_78 = & V_57 -> V_59 ;
V_2 -> V_40 . V_59 . V_60 = V_57 -> V_59 . V_60 ;
V_67 = F_27 ( & V_2 -> V_40 ) ;
if ( V_67 ) {
F_15 ( & V_57 -> V_59 , L_8 ) ;
return V_67 ;
}
if ( V_63 ) {
for ( V_68 = 0 ; V_68 < V_63 -> V_79 ; V_68 ++ )
F_28 ( & V_2 -> V_40 , V_63 -> V_80 + V_68 ) ;
} else {
F_29 ( & V_2 -> V_40 ) ;
}
return 0 ;
}
static int T_6 F_30 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_31 ( V_57 ) ;
F_1 ( V_2 , V_48 , F_3 ( V_2 , V_48 )
& ~ ( V_49 | V_50 ) ) ;
F_32 ( & V_2 -> V_40 ) ;
F_25 ( V_57 , NULL ) ;
return 0 ;
}
static int F_33 ( struct V_56 * V_57 , T_7 V_11 )
{
struct V_1 * V_2 = F_31 ( V_57 ) ;
T_1 V_47 = F_3 ( V_2 , V_48 ) ;
F_1 ( V_2 , V_48 , V_47 & ~ ( V_49 | V_50 ) ) ;
return 0 ;
}
static int F_34 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_31 ( V_57 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
