static inline T_1 F_1 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 )
{
register T_1 V_4 ;
F_2 ( V_1 , V_3 ) ;
V_4 = F_3 ( V_2 ) ;
return V_4 ;
}
static inline void F_4 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 ,
T_1 * V_5 , int V_6 )
{
F_2 ( V_1 , V_3 ) ;
F_5 ( V_2 , V_5 , V_6 ) ;
}
static inline void F_6 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_5 ) ;
}
static inline void F_7 ( unsigned int V_1 , unsigned int V_2 , T_1 V_3 ,
T_1 * V_5 , int V_6 )
{
F_2 ( V_1 , V_3 ) ;
F_8 ( V_2 , V_5 , V_6 ) ;
}
static T_1 F_9 ( struct V_7 * V_8 , T_1 V_9 )
{
return F_1 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_9 ) ;
}
static void F_10 ( struct V_7 * V_8 , T_1 V_9 , T_1 V_14 )
{
F_6 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_9 , V_14 ) ;
}
static void F_11 ( struct V_7 * V_8 , T_1 * V_5 , int V_6 )
{
F_4 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , 0 , V_5 , V_6 ) ;
}
static void F_12 ( struct V_7 * V_8 , T_1 * V_5 , int V_6 )
{
F_7 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , 0 , V_5 , V_6 ) ;
}
static T_1 F_13 ( struct V_7 * V_8 , int V_15 , T_1 V_9 )
{
return F_1 ( V_8 -> V_10 . V_11 . V_16 ,
V_8 -> V_10 . V_11 . V_15 , V_9 + ( V_15 ? 0x40 : 0 ) ) ;
}
static void F_14 ( struct V_7 * V_8 , int V_15 , T_1 V_9 ,
T_1 V_14 )
{
F_6 ( V_8 -> V_10 . V_11 . V_16 ,
V_8 -> V_10 . V_11 . V_15 , V_9 + ( V_15 ? 0x40 : 0 ) , V_14 ) ;
}
static T_2 F_15 ( int V_17 , void * V_18 )
{
struct V_7 * V_8 = V_18 ;
T_1 V_19 ;
T_3 V_20 ;
F_16 ( & V_8 -> V_21 , V_20 ) ;
if ( V_8 -> V_22 == V_23 ) {
int V_24 ;
V_24 = F_17 ( V_8 -> V_10 . V_11 . V_25 + V_26 ) ;
if ( ! ( V_24 & V_27 ) ) {
F_18 ( & V_8 -> V_21 , V_20 ) ;
return V_28 ;
}
F_19 ( V_24 , V_8 -> V_10 . V_11 . V_25 + V_26 ) ;
}
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 ,
V_29 + 0x40 ) ;
V_30:
if ( V_19 )
F_20 ( V_8 , V_19 ) ;
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_31 ) ;
V_32:
if ( V_19 )
F_21 ( V_8 , V_19 ) ;
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 ,
V_29 + 0x40 ) ;
if ( V_19 ) {
if ( V_8 -> V_33 & V_34 )
F_22 ( V_8 , L_1 ) ;
goto V_30;
}
V_19 = F_1 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_31 ) ;
if ( V_19 ) {
if ( V_8 -> V_33 & V_35 )
F_22 ( V_8 , L_2 ) ;
goto V_32;
}
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_36 , 0xFF ) ;
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_36 + 0x40 ,
0xFF ) ;
F_6 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_37 , 0xFF ) ;
F_6 ( V_8 -> V_10 . V_11 . V_12 , V_8 -> V_10 . V_11 . V_13 , V_37 , 0 ) ;
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_36 , 0 ) ;
F_6 ( V_8 -> V_10 . V_11 . V_16 , V_8 -> V_10 . V_11 . V_15 , V_36 + 0x40 , 0 ) ;
F_18 ( & V_8 -> V_21 , V_20 ) ;
return V_38 ;
}
static void F_23 ( struct V_7 * V_8 )
{
if ( V_8 -> V_22 == V_23 ) {
int V_19 ;
V_19 = F_17 ( V_8 -> V_10 . V_11 . V_25 + V_26 ) ;
V_19 &= V_39 ;
F_19 ( V_19 , V_8 -> V_10 . V_11 . V_25 + V_26 ) ;
F_24 ( V_8 -> V_10 . V_11 . V_25 , 0x40 ) ;
F_24 ( V_8 -> V_10 . V_11 . V_13 , 4 ) ;
} else {
F_24 ( V_8 -> V_10 . V_11 . V_13 , 2 ) ;
F_24 ( V_8 -> V_10 . V_11 . V_12 , 2 ) ;
}
}
static void F_25 ( struct V_7 * V_8 )
{
if ( V_8 -> V_22 == V_23 ) {
int V_19 ;
V_19 = F_17 ( V_8 -> V_10 . V_11 . V_25 + V_26 ) ;
V_19 |= V_40 ;
F_19 ( V_19 , V_8 -> V_10 . V_11 . V_25 + V_26 ) ;
}
F_26 ( V_8 , 3 ) ;
}
static int F_27 ( struct V_7 * V_8 , int V_41 , void * V_42 )
{
T_3 V_20 ;
switch ( V_41 ) {
case V_43 :
F_16 ( & V_8 -> V_21 , V_20 ) ;
F_25 ( V_8 ) ;
F_18 ( & V_8 -> V_21 , V_20 ) ;
return 0 ;
case V_44 :
F_23 ( V_8 ) ;
return 0 ;
case V_45 :
F_16 ( & V_8 -> V_21 , V_20 ) ;
F_25 ( V_8 ) ;
F_18 ( & V_8 -> V_21 , V_20 ) ;
return 0 ;
case V_46 :
return 0 ;
}
return 0 ;
}
int F_28 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
char V_49 [ 64 ] ;
strcpy ( V_49 , V_50 ) ;
F_29 ( V_51 L_3 , F_30 ( V_49 ) ) ;
if ( V_8 -> V_52 != V_53 )
return 0 ;
#ifdef F_31
if ( ! V_48 -> V_54 [ 1 ] && F_32 () ) {
struct V_55 * V_56 = NULL ;
int V_57 ;
V_58 = F_33 ( F_34 ( 'S' , 'D' , 'A' ) ,
F_35 ( 0x0150 ) , V_58 ) ;
if ( V_58 ) {
V_56 = F_36 ( V_58 ,
F_34 ( 'S' , 'D' , 'A' ) ,
F_35 ( 0x0150 ) , V_56 ) ;
if ( ! V_56 ) {
F_29 ( V_59 L_4
L_5 ) ;
return 0 ;
}
F_37 ( V_56 ) ;
V_57 = F_38 ( V_56 ) ;
if ( V_57 < 0 ) {
F_29 ( V_60 L_6
L_7 , V_61 , V_57 ) ;
return 0 ;
}
V_48 -> V_54 [ 1 ] = F_39 ( V_56 , 0 ) ;
V_48 -> V_54 [ 2 ] = F_39 ( V_56 , 1 ) ;
V_48 -> V_54 [ 0 ] = F_40 ( V_56 , 0 ) ;
if ( ! V_48 -> V_54 [ 0 ] || ! V_48 -> V_54 [ 1 ] ||
! V_48 -> V_54 [ 2 ] ) {
F_29 ( V_59 L_8
L_9 ,
V_48 -> V_54 [ 0 ] , V_48 -> V_54 [ 1 ] ,
V_48 -> V_54 [ 2 ] ) ;
F_37 ( V_56 ) ;
return 0 ;
}
} else
F_29 ( V_51 L_10 ) ;
}
#endif
if ( V_48 -> V_54 [ 1 ] ) {
V_8 -> V_10 . V_11 . V_13 = V_48 -> V_54 [ 1 ] + V_62 ;
V_8 -> V_10 . V_11 . V_15 = V_48 -> V_54 [ 1 ] + V_63 ;
V_8 -> V_10 . V_11 . V_12 = V_48 -> V_54 [ 2 ] + V_62 ;
V_8 -> V_10 . V_11 . V_16 = V_48 -> V_54 [ 2 ] + V_63 ;
V_8 -> V_10 . V_11 . V_25 = 0 ;
V_8 -> V_22 = V_64 ;
V_8 -> V_65 = V_48 -> V_54 [ 0 ] ;
if ( ! F_41 ( V_8 -> V_10 . V_11 . V_13 , 2 , L_11 ) ) {
F_29 ( V_60 L_12
L_13 ,
V_8 -> V_10 . V_11 . V_13 , V_8 -> V_10 . V_11 . V_13 + 1 ) ;
return 0 ;
}
if ( ! F_41 ( V_8 -> V_10 . V_11 . V_12 , 2 , L_14 ) ) {
F_29 ( V_60 L_15
L_13 ,
V_8 -> V_10 . V_11 . V_12 ,
V_8 -> V_10 . V_11 . V_12 + 1 ) ;
F_24 ( V_8 -> V_10 . V_11 . V_13 , 2 ) ;
return 0 ;
}
} else {
#ifdef F_42
static struct V_66 * V_67 ;
T_4 V_68 ;
V_8 -> V_22 = 0 ;
if ( ( V_67 = F_43 ( V_69 ,
V_70 ,
V_67 ) ) ) {
if ( F_44 ( V_67 ) )
return 0 ;
if ( ! V_67 -> V_65 ) {
F_29 ( V_60
L_16 ) ;
return 0 ;
}
V_8 -> V_65 = V_67 -> V_65 ;
V_8 -> V_10 . V_11 . V_25 = F_45 ( V_67 , 0 ) ;
if ( ! V_8 -> V_10 . V_11 . V_25 ) {
F_29 ( V_60
L_17 ) ;
return 0 ;
}
V_68 = F_45 ( V_67 , 1 ) ;
if ( ! V_68 ) {
F_29 ( V_60
L_18 ) ;
return 0 ;
}
V_8 -> V_22 = V_23 ;
} else {
F_29 ( V_60 L_19 ) ;
return 0 ;
}
V_8 -> V_71 |= V_72 ;
V_8 -> V_10 . V_11 . V_13 = V_68 + V_73 ;
V_8 -> V_10 . V_11 . V_12 = V_68 + V_74 ;
V_8 -> V_10 . V_11 . V_15 = V_68 + V_75 ;
V_8 -> V_10 . V_11 . V_16 = V_68 + V_76 ;
if ( ! F_41 ( V_8 -> V_10 . V_11 . V_13 , 4 , L_20 ) ) {
F_29 ( V_60
L_21 ,
V_8 -> V_10 . V_11 . V_13 , V_8 -> V_10 . V_11 . V_13 + 4 ) ;
return 0 ;
}
if ( ! F_41 ( V_8 -> V_10 . V_11 . V_25 , 0x40 , L_22 ) ) {
F_29 ( V_60
L_23 ,
V_8 -> V_10 . V_11 . V_25 ,
V_8 -> V_10 . V_11 . V_25 + 0x40 ) ;
F_24 ( V_8 -> V_10 . V_11 . V_13 , 4 ) ;
return 0 ;
}
#else
F_29 ( V_60 L_24 ) ;
F_29 ( V_60 L_25 ) ;
return 0 ;
#endif
}
F_29 ( V_51 L_26 ,
( V_8 -> V_22 == 1 ) ? L_27 : L_28 ,
V_8 -> V_65 , V_8 -> V_10 . V_11 . V_13 , V_8 -> V_10 . V_11 . V_12 ) ;
F_46 ( V_8 ) ;
V_8 -> V_77 = & F_9 ;
V_8 -> V_78 = & F_10 ;
V_8 -> V_79 = & F_11 ;
V_8 -> V_80 = & F_12 ;
V_8 -> V_81 = & F_13 ;
V_8 -> V_82 = & F_14 ;
V_8 -> V_83 = & V_84 ;
V_8 -> V_85 = & F_27 ;
V_8 -> V_86 = & F_15 ;
F_47 ( V_8 , L_29 ) ;
if ( F_48 ( V_8 , L_29 ) ) {
F_29 ( V_60 L_30
L_31 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
return 1 ;
}
