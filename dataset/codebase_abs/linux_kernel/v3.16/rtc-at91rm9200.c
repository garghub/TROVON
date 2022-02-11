static void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_4 |= V_1 ;
F_3 ( V_5 , V_1 ) ;
F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( T_1 V_1 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_3 ( V_6 , V_1 ) ;
F_6 ( V_7 ) ;
V_4 &= ~ V_1 ;
F_4 ( & V_3 , V_2 ) ;
}
static T_1 F_7 ( void )
{
unsigned long V_2 ;
T_1 V_1 ;
if ( V_8 -> V_9 ) {
F_2 ( & V_3 , V_2 ) ;
V_1 = V_4 ;
F_4 ( & V_3 , V_2 ) ;
} else {
V_1 = F_6 ( V_10 ) ;
}
return V_1 ;
}
static void F_8 ( unsigned int V_11 , unsigned int V_12 ,
struct V_13 * V_14 )
{
unsigned int time , V_15 ;
do {
time = F_6 ( V_11 ) ;
V_15 = F_6 ( V_12 ) ;
} while ( ( time != F_6 ( V_11 ) ) ||
( V_15 != F_6 ( V_12 ) ) );
V_14 -> V_16 = F_9 ( ( time & V_17 ) >> 0 ) ;
V_14 -> V_18 = F_9 ( ( time & V_19 ) >> 8 ) ;
V_14 -> V_20 = F_9 ( ( time & V_21 ) >> 16 ) ;
V_14 -> V_22 = F_9 ( V_15 & V_23 ) * 100 ;
V_14 -> V_22 += F_9 ( ( V_15 & V_24 ) >> 8 ) ;
V_14 -> V_25 = F_9 ( ( V_15 & V_26 ) >> 21 ) - 1 ;
V_14 -> V_27 = F_9 ( ( V_15 & V_28 ) >> 16 ) - 1 ;
V_14 -> V_29 = F_9 ( ( V_15 & V_30 ) >> 24 ) ;
}
static int F_10 ( struct V_31 * V_32 , struct V_13 * V_14 )
{
F_8 ( V_33 , V_34 , V_14 ) ;
V_14 -> V_35 = F_11 ( V_14 -> V_29 , V_14 -> V_27 , V_14 -> V_22 ) ;
V_14 -> V_22 = V_14 -> V_22 - 1900 ;
F_12 ( V_32 , L_1 , V_36 ,
1900 + V_14 -> V_22 , V_14 -> V_27 , V_14 -> V_29 ,
V_14 -> V_20 , V_14 -> V_18 , V_14 -> V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_31 * V_32 , struct V_13 * V_14 )
{
unsigned long V_37 ;
F_12 ( V_32 , L_1 , V_36 ,
1900 + V_14 -> V_22 , V_14 -> V_27 , V_14 -> V_29 ,
V_14 -> V_20 , V_14 -> V_18 , V_14 -> V_16 ) ;
F_14 ( & V_38 ) ;
V_37 = F_6 ( V_39 ) ;
F_3 ( V_39 , V_37 | V_40 | V_41 ) ;
F_1 ( V_42 ) ;
F_14 ( & V_43 ) ;
F_5 ( V_42 ) ;
F_3 ( V_33 ,
F_15 ( V_14 -> V_16 ) << 0
| F_15 ( V_14 -> V_18 ) << 8
| F_15 ( V_14 -> V_20 ) << 16 ) ;
F_3 ( V_34 ,
F_15 ( ( V_14 -> V_22 + 1900 ) / 100 )
| F_15 ( V_14 -> V_22 % 100 ) << 8
| F_15 ( V_14 -> V_27 + 1 ) << 16
| F_15 ( V_14 -> V_25 + 1 ) << 21
| F_15 ( V_14 -> V_29 ) << 24 ) ;
V_37 = F_6 ( V_39 ) ;
F_3 ( V_44 , V_45 ) ;
F_3 ( V_39 , V_37 & ~ ( V_40 | V_41 ) ) ;
F_1 ( V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 , struct V_46 * V_47 )
{
struct V_13 * V_14 = & V_47 -> time ;
F_8 ( V_48 , V_49 , V_14 ) ;
V_14 -> V_35 = F_11 ( V_14 -> V_29 , V_14 -> V_27 , V_14 -> V_22 ) ;
V_14 -> V_22 = V_50 - 1900 ;
V_47 -> V_51 = ( F_7 () & V_52 )
? 1 : 0 ;
F_12 ( V_32 , L_1 , V_36 ,
1900 + V_14 -> V_22 , V_14 -> V_27 , V_14 -> V_29 ,
V_14 -> V_20 , V_14 -> V_18 , V_14 -> V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 , struct V_46 * V_47 )
{
struct V_13 V_14 ;
F_8 ( V_33 , V_34 , & V_14 ) ;
V_50 = V_14 . V_22 ;
V_14 . V_27 = V_47 -> time . V_27 ;
V_14 . V_29 = V_47 -> time . V_29 ;
V_14 . V_20 = V_47 -> time . V_20 ;
V_14 . V_18 = V_47 -> time . V_18 ;
V_14 . V_16 = V_47 -> time . V_16 ;
F_5 ( V_52 ) ;
F_3 ( V_48 ,
F_15 ( V_14 . V_16 ) << 0
| F_15 ( V_14 . V_18 ) << 8
| F_15 ( V_14 . V_20 ) << 16
| V_53 | V_54 | V_55 ) ;
F_3 ( V_49 ,
F_15 ( V_14 . V_27 + 1 ) << 16
| F_15 ( V_14 . V_29 ) << 24
| V_56 | V_57 ) ;
if ( V_47 -> V_51 ) {
F_3 ( V_44 , V_52 ) ;
F_1 ( V_52 ) ;
}
F_12 ( V_32 , L_1 , V_36 ,
V_50 , V_14 . V_27 , V_14 . V_29 , V_14 . V_20 ,
V_14 . V_18 , V_14 . V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_31 * V_32 , unsigned int V_51 )
{
F_12 ( V_32 , L_2 , V_36 , V_51 ) ;
if ( V_51 ) {
F_3 ( V_44 , V_52 ) ;
F_1 ( V_52 ) ;
} else
F_5 ( V_52 ) ;
return 0 ;
}
static int F_19 ( struct V_31 * V_32 , struct V_58 * V_59 )
{
unsigned long V_60 = F_7 () ;
F_20 ( V_59 , L_3 ,
( V_60 & V_42 ) ? L_4 : L_5 ) ;
F_20 ( V_59 , L_6 ,
( V_60 & V_45 ) ? L_4 : L_5 ) ;
return 0 ;
}
static T_2 F_21 ( int V_61 , void * V_62 )
{
struct V_63 * V_64 = V_62 ;
struct V_65 * V_66 = F_22 ( V_64 ) ;
unsigned int V_67 ;
unsigned long V_68 = 0 ;
V_67 = F_6 ( V_7 ) & F_7 () ;
if ( V_67 ) {
if ( V_67 & V_52 )
V_68 |= ( V_69 | V_70 ) ;
if ( V_67 & V_45 ) {
F_23 ( & V_38 ) ;
F_5 ( V_45 ) ;
}
if ( V_67 & V_42 )
F_23 ( & V_43 ) ;
F_3 ( V_44 , V_67 ) ;
F_24 ( V_66 , 1 , V_68 ) ;
F_12 ( & V_64 -> V_32 , L_7 , V_36 ,
V_68 >> 8 , V_68 & 0x000000FF ) ;
return V_71 ;
}
return V_72 ;
}
static const struct V_8 *
F_25 ( struct V_63 * V_64 )
{
const struct V_73 * V_74 ;
if ( V_64 -> V_32 . V_75 ) {
V_74 = F_26 ( V_76 , V_64 -> V_32 . V_75 ) ;
if ( ! V_74 )
return NULL ;
return ( const struct V_8 * ) V_74 -> V_77 ;
}
return & V_78 ;
}
static int T_3 F_27 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_79 * V_80 ;
int V_81 = 0 ;
V_8 = F_25 ( V_64 ) ;
if ( ! V_8 )
return - V_82 ;
V_80 = F_28 ( V_64 , V_83 , 0 ) ;
if ( ! V_80 ) {
F_29 ( & V_64 -> V_32 , L_8 ) ;
return - V_84 ;
}
V_61 = F_30 ( V_64 , 0 ) ;
if ( V_61 < 0 ) {
F_29 ( & V_64 -> V_32 , L_9 ) ;
return - V_84 ;
}
V_85 = F_31 ( & V_64 -> V_32 , V_80 -> V_86 ,
F_32 ( V_80 ) ) ;
if ( ! V_85 ) {
F_29 ( & V_64 -> V_32 , L_10 ) ;
return - V_87 ;
}
F_3 ( V_39 , 0 ) ;
F_3 ( V_88 , 0 ) ;
F_5 ( V_42 | V_52 |
V_45 | V_89 |
V_90 ) ;
V_81 = F_33 ( & V_64 -> V_32 , V_61 , F_21 ,
V_91 ,
L_11 , V_64 ) ;
if ( V_81 ) {
F_29 ( & V_64 -> V_32 , L_12 , V_61 ) ;
return V_81 ;
}
if ( ! F_34 ( & V_64 -> V_32 ) )
F_35 ( & V_64 -> V_32 , 1 ) ;
V_66 = F_36 ( & V_64 -> V_32 , V_64 -> V_92 ,
& V_93 , V_94 ) ;
if ( F_37 ( V_66 ) )
return F_38 ( V_66 ) ;
F_39 ( V_64 , V_66 ) ;
F_1 ( V_45 ) ;
F_40 ( & V_64 -> V_32 , L_13 ) ;
return 0 ;
}
static int T_4 F_41 ( struct V_63 * V_64 )
{
F_5 ( V_42 | V_52 |
V_45 | V_89 |
V_90 ) ;
return 0 ;
}
static void F_42 ( struct V_63 * V_64 )
{
F_3 ( V_6 , V_42 | V_52 |
V_45 | V_89 |
V_90 ) ;
}
static int F_43 ( struct V_31 * V_32 )
{
V_95 = F_7 ()
& ( V_52 | V_45 ) ;
if ( V_95 ) {
if ( F_44 ( V_32 ) )
F_45 ( V_61 ) ;
else
F_5 ( V_95 ) ;
}
return 0 ;
}
static int F_46 ( struct V_31 * V_32 )
{
if ( V_95 ) {
if ( F_44 ( V_32 ) )
F_47 ( V_61 ) ;
else
F_1 ( V_95 ) ;
}
return 0 ;
}
