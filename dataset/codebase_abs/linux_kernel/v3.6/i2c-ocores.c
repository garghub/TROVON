static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 == 4 )
F_2 ( V_4 , V_2 -> V_6 + ( V_3 << V_2 -> V_7 ) ) ;
else if ( V_2 -> V_5 == 2 )
F_3 ( V_4 , V_2 -> V_6 + ( V_3 << V_2 -> V_7 ) ) ;
else
F_4 ( V_4 , V_2 -> V_6 + ( V_3 << V_2 -> V_7 ) ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_5 == 4 )
return F_6 ( V_2 -> V_6 + ( V_3 << V_2 -> V_7 ) ) ;
else if ( V_2 -> V_5 == 2 )
return F_7 ( V_2 -> V_6 + ( V_3 << V_2 -> V_7 ) ) ;
else
return F_8 ( V_2 -> V_6 + ( V_3 << V_2 -> V_7 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_10 = F_5 ( V_2 , V_11 ) ;
if ( ( V_2 -> V_12 == V_13 ) || ( V_2 -> V_12 == V_14 ) ) {
F_1 ( V_2 , V_15 , V_16 ) ;
F_10 ( & V_2 -> V_17 ) ;
return;
}
if ( V_10 & V_18 ) {
V_2 -> V_12 = V_14 ;
F_1 ( V_2 , V_15 , V_19 ) ;
return;
}
if ( ( V_2 -> V_12 == V_20 ) || ( V_2 -> V_12 == V_21 ) ) {
V_2 -> V_12 =
( V_9 -> V_22 & V_23 ) ? V_24 : V_21 ;
if ( V_10 & V_25 ) {
V_2 -> V_12 = V_14 ;
F_1 ( V_2 , V_15 , V_19 ) ;
return;
}
} else
V_9 -> V_26 [ V_2 -> V_27 ++ ] = F_5 ( V_2 , V_28 ) ;
if ( V_2 -> V_27 == V_9 -> V_29 ) {
V_2 -> V_30 -- ;
V_2 -> V_9 ++ ;
V_2 -> V_27 = 0 ;
V_9 = V_2 -> V_9 ;
if ( V_2 -> V_30 ) {
if ( ! ( V_9 -> V_22 & V_31 ) ) {
T_1 V_32 = ( V_9 -> V_32 << 1 ) ;
if ( V_9 -> V_22 & V_23 )
V_32 |= 1 ;
V_2 -> V_12 = V_20 ;
F_1 ( V_2 , V_28 , V_32 ) ;
F_1 ( V_2 , V_15 , V_33 ) ;
return;
} else
V_2 -> V_12 = ( V_9 -> V_22 & V_23 )
? V_24 : V_21 ;
} else {
V_2 -> V_12 = V_13 ;
F_1 ( V_2 , V_15 , V_19 ) ;
return;
}
}
if ( V_2 -> V_12 == V_24 ) {
F_1 ( V_2 , V_15 , V_2 -> V_27 == ( V_9 -> V_29 - 1 ) ?
V_34 : V_35 ) ;
} else {
F_1 ( V_2 , V_28 , V_9 -> V_26 [ V_2 -> V_27 ++ ] ) ;
F_1 ( V_2 , V_15 , V_36 ) ;
}
}
static T_2 F_11 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
F_9 ( V_2 ) ;
return V_39 ;
}
static int F_12 ( struct V_40 * V_41 , struct V_8 * V_42 , int V_43 )
{
struct V_1 * V_2 = F_13 ( V_41 ) ;
V_2 -> V_9 = V_42 ;
V_2 -> V_27 = 0 ;
V_2 -> V_30 = V_43 ;
V_2 -> V_12 = V_20 ;
F_1 ( V_2 , V_28 ,
( V_2 -> V_9 -> V_32 << 1 ) |
( ( V_2 -> V_9 -> V_22 & V_23 ) ? 1 : 0 ) ) ;
F_1 ( V_2 , V_15 , V_33 ) ;
if ( F_14 ( V_2 -> V_17 , ( V_2 -> V_12 == V_14 ) ||
( V_2 -> V_12 == V_13 ) , V_44 ) )
return ( V_2 -> V_12 == V_13 ) ? V_43 : - V_45 ;
else
return - V_46 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_47 ;
T_1 V_48 = F_5 ( V_2 , V_49 ) ;
F_1 ( V_2 , V_49 , V_48 & ~ ( V_50 | V_51 ) ) ;
V_47 = ( V_2 -> V_52 / ( 5 * 100 ) ) - 1 ;
F_1 ( V_2 , V_53 , V_47 & 0xff ) ;
F_1 ( V_2 , V_54 , V_47 >> 8 ) ;
F_1 ( V_2 , V_15 , V_16 ) ;
F_1 ( V_2 , V_49 , V_48 | V_51 | V_50 ) ;
}
static T_3 F_16 ( struct V_40 * V_41 )
{
return V_55 | V_56 ;
}
static int F_17 ( struct V_57 * V_58 ,
struct V_1 * V_2 )
{
struct V_59 * V_60 = V_58 -> V_61 . V_62 ;
T_3 V_63 ;
if ( F_18 ( V_60 , L_1 , & V_2 -> V_7 ) ) {
if ( ! F_18 ( V_60 , L_2 , & V_63 ) ) {
if ( ! F_19 ( V_63 ) ) {
F_20 ( & V_58 -> V_61 , L_3 ,
V_63 ) ;
return - V_64 ;
}
V_2 -> V_7 = F_21 ( V_63 ) ;
F_22 ( & V_58 -> V_61 ,
L_4 ) ;
}
}
if ( F_18 ( V_60 , L_5 , & V_63 ) ) {
F_20 ( & V_58 -> V_61 ,
L_6 ) ;
return - V_65 ;
}
V_2 -> V_52 = V_63 / 1000 ;
F_18 ( V_58 -> V_61 . V_62 , L_7 ,
& V_2 -> V_5 ) ;
return 0 ;
}
static int T_4 F_23 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
struct V_68 * V_69 , * V_70 ;
int V_71 ;
int V_72 ;
V_69 = F_24 ( V_58 , V_73 , 0 ) ;
if ( ! V_69 )
return - V_65 ;
V_70 = F_24 ( V_58 , V_74 , 0 ) ;
if ( ! V_70 )
return - V_65 ;
V_2 = F_25 ( & V_58 -> V_61 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
if ( ! F_26 ( & V_58 -> V_61 , V_69 -> V_77 ,
F_27 ( V_69 ) , V_58 -> V_78 ) ) {
F_20 ( & V_58 -> V_61 , L_8 ) ;
return - V_79 ;
}
V_2 -> V_6 = F_28 ( & V_58 -> V_61 , V_69 -> V_77 ,
F_27 ( V_69 ) ) ;
if ( ! V_2 -> V_6 ) {
F_20 ( & V_58 -> V_61 , L_9 ) ;
return - V_45 ;
}
V_67 = V_58 -> V_61 . V_80 ;
if ( V_67 ) {
V_2 -> V_7 = V_67 -> V_7 ;
V_2 -> V_5 = V_67 -> V_5 ;
V_2 -> V_52 = V_67 -> V_52 ;
} else {
V_71 = F_17 ( V_58 , V_2 ) ;
if ( V_71 )
return V_71 ;
}
if ( V_2 -> V_5 == 0 )
V_2 -> V_5 = 1 ;
F_15 ( V_2 ) ;
F_29 ( & V_2 -> V_17 ) ;
V_71 = F_30 ( & V_58 -> V_61 , V_70 -> V_77 , F_11 , 0 ,
V_58 -> V_78 , V_2 ) ;
if ( V_71 ) {
F_20 ( & V_58 -> V_61 , L_10 ) ;
return V_71 ;
}
F_31 ( V_58 , V_2 ) ;
V_2 -> V_41 = V_81 ;
F_32 ( & V_2 -> V_41 , V_2 ) ;
V_2 -> V_41 . V_61 . V_82 = & V_58 -> V_61 ;
V_2 -> V_41 . V_61 . V_62 = V_58 -> V_61 . V_62 ;
V_71 = F_33 ( & V_2 -> V_41 ) ;
if ( V_71 ) {
F_20 ( & V_58 -> V_61 , L_11 ) ;
return V_71 ;
}
if ( V_67 ) {
for ( V_72 = 0 ; V_72 < V_67 -> V_83 ; V_72 ++ )
F_34 ( & V_2 -> V_41 , V_67 -> V_84 + V_72 ) ;
} else {
F_35 ( & V_2 -> V_41 ) ;
}
return 0 ;
}
static int T_5 F_36 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_37 ( V_58 ) ;
F_1 ( V_2 , V_49 , F_5 ( V_2 , V_49 )
& ~ ( V_50 | V_51 ) ) ;
F_38 ( & V_2 -> V_41 ) ;
F_31 ( V_58 , NULL ) ;
return 0 ;
}
static int F_39 ( struct V_85 * V_61 )
{
struct V_1 * V_2 = F_40 ( V_61 ) ;
T_1 V_48 = F_5 ( V_2 , V_49 ) ;
F_1 ( V_2 , V_49 , V_48 & ~ ( V_50 | V_51 ) ) ;
return 0 ;
}
static int F_41 ( struct V_85 * V_61 )
{
struct V_1 * V_2 = F_40 ( V_61 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
