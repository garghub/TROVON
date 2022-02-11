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
int V_69 = V_70 ;
F_23 ( & V_71 ) ;
V_67 = F_6 ( V_7 ) & F_7 () ;
if ( V_67 ) {
if ( V_67 & V_52 )
V_68 |= ( V_72 | V_73 ) ;
if ( V_67 & V_45 ) {
F_24 ( & V_38 ) ;
F_5 ( V_45 ) ;
}
if ( V_67 & V_42 )
F_24 ( & V_43 ) ;
F_3 ( V_44 , V_67 ) ;
if ( ! V_74 ) {
F_25 ( V_66 , 1 , V_68 ) ;
F_12 ( & V_64 -> V_32 , L_7 ,
V_36 , V_68 >> 8 , V_68 & 0x000000FF ) ;
} else {
V_75 |= V_68 ;
F_5 ( V_76 ) ;
F_26 () ;
}
V_69 = V_77 ;
}
F_27 ( & V_71 ) ;
return V_69 ;
}
static const struct V_8 *
F_28 ( struct V_63 * V_64 )
{
const struct V_78 * V_79 ;
if ( V_64 -> V_32 . V_80 ) {
V_79 = F_29 ( V_81 , V_64 -> V_32 . V_80 ) ;
if ( ! V_79 )
return NULL ;
return ( const struct V_8 * ) V_79 -> V_82 ;
}
return & V_83 ;
}
static int T_3 F_30 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_84 * V_85 ;
int V_69 = 0 ;
V_8 = F_28 ( V_64 ) ;
if ( ! V_8 )
return - V_86 ;
V_85 = F_31 ( V_64 , V_87 , 0 ) ;
if ( ! V_85 ) {
F_32 ( & V_64 -> V_32 , L_8 ) ;
return - V_88 ;
}
V_61 = F_33 ( V_64 , 0 ) ;
if ( V_61 < 0 ) {
F_32 ( & V_64 -> V_32 , L_9 ) ;
return - V_88 ;
}
V_89 = F_34 ( & V_64 -> V_32 , V_85 -> V_90 ,
F_35 ( V_85 ) ) ;
if ( ! V_89 ) {
F_32 ( & V_64 -> V_32 , L_10 ) ;
return - V_91 ;
}
V_92 = F_36 ( & V_64 -> V_32 , NULL ) ;
if ( F_37 ( V_92 ) )
return F_38 ( V_92 ) ;
V_69 = F_39 ( V_92 ) ;
if ( V_69 ) {
F_32 ( & V_64 -> V_32 , L_11 ) ;
return V_69 ;
}
F_3 ( V_39 , 0 ) ;
F_3 ( V_93 , 0 ) ;
F_5 ( V_42 | V_52 |
V_45 | V_94 |
V_95 ) ;
V_69 = F_40 ( & V_64 -> V_32 , V_61 , F_21 ,
V_96 | V_97 ,
L_12 , V_64 ) ;
if ( V_69 ) {
F_32 ( & V_64 -> V_32 , L_13 , V_61 ) ;
goto V_98;
}
if ( ! F_41 ( & V_64 -> V_32 ) )
F_42 ( & V_64 -> V_32 , 1 ) ;
V_66 = F_43 ( & V_64 -> V_32 , V_64 -> V_99 ,
& V_100 , V_101 ) ;
if ( F_37 ( V_66 ) ) {
V_69 = F_38 ( V_66 ) ;
goto V_98;
}
F_44 ( V_64 , V_66 ) ;
F_1 ( V_45 ) ;
F_45 ( & V_64 -> V_32 , L_14 ) ;
return 0 ;
V_98:
F_46 ( V_92 ) ;
return V_69 ;
}
static int T_4 F_47 ( struct V_63 * V_64 )
{
F_5 ( V_42 | V_52 |
V_45 | V_94 |
V_95 ) ;
F_46 ( V_92 ) ;
return 0 ;
}
static void F_48 ( struct V_63 * V_64 )
{
F_3 ( V_6 , V_42 | V_52 |
V_45 | V_94 |
V_95 ) ;
}
static int F_49 ( struct V_31 * V_32 )
{
V_76 = F_7 ()
& ( V_52 | V_45 ) ;
if ( V_76 ) {
if ( F_50 ( V_32 ) ) {
unsigned long V_2 ;
F_51 ( V_61 ) ;
F_2 ( & V_71 , V_2 ) ;
V_74 = true ;
F_4 ( & V_71 , V_2 ) ;
} else {
F_5 ( V_76 ) ;
}
}
return 0 ;
}
static int F_52 ( struct V_31 * V_32 )
{
struct V_65 * V_66 = F_53 ( V_32 ) ;
if ( V_76 ) {
if ( F_50 ( V_32 ) ) {
unsigned long V_2 ;
F_2 ( & V_71 , V_2 ) ;
if ( V_75 ) {
F_25 ( V_66 , 1 , V_75 ) ;
V_75 = 0 ;
}
V_74 = false ;
F_4 ( & V_71 , V_2 ) ;
F_54 ( V_61 ) ;
}
F_1 ( V_76 ) ;
}
return 0 ;
}
