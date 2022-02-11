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
V_37 = F_6 ( V_38 ) ;
F_3 ( V_38 , V_37 | V_39 | V_40 ) ;
F_1 ( V_41 ) ;
F_14 ( & V_42 ) ;
F_5 ( V_41 ) ;
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
V_37 = F_6 ( V_38 ) ;
F_3 ( V_38 , V_37 & ~ ( V_39 | V_40 ) ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 , struct V_43 * V_44 )
{
struct V_13 * V_14 = & V_44 -> time ;
F_8 ( V_45 , V_46 , V_14 ) ;
V_14 -> V_35 = F_11 ( V_14 -> V_29 , V_14 -> V_27 , V_14 -> V_22 ) ;
V_14 -> V_22 = V_47 - 1900 ;
V_44 -> V_48 = ( F_7 () & V_49 )
? 1 : 0 ;
F_12 ( V_32 , L_1 , V_36 ,
1900 + V_14 -> V_22 , V_14 -> V_27 , V_14 -> V_29 ,
V_14 -> V_20 , V_14 -> V_18 , V_14 -> V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 , struct V_43 * V_44 )
{
struct V_13 V_14 ;
F_8 ( V_33 , V_34 , & V_14 ) ;
V_47 = V_14 . V_22 ;
V_14 . V_20 = V_44 -> time . V_20 ;
V_14 . V_18 = V_44 -> time . V_18 ;
V_14 . V_16 = V_44 -> time . V_16 ;
F_5 ( V_49 ) ;
F_3 ( V_45 ,
F_15 ( V_14 . V_16 ) << 0
| F_15 ( V_14 . V_18 ) << 8
| F_15 ( V_14 . V_20 ) << 16
| V_50 | V_51 | V_52 ) ;
F_3 ( V_46 ,
F_15 ( V_14 . V_27 + 1 ) << 16
| F_15 ( V_14 . V_29 ) << 24
| V_53 | V_54 ) ;
if ( V_44 -> V_48 ) {
F_3 ( V_55 , V_49 ) ;
F_1 ( V_49 ) ;
}
F_12 ( V_32 , L_1 , V_36 ,
V_47 , V_14 . V_27 , V_14 . V_29 , V_14 . V_20 ,
V_14 . V_18 , V_14 . V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_31 * V_32 , unsigned int V_48 )
{
F_12 ( V_32 , L_2 , V_36 , V_48 ) ;
if ( V_48 ) {
F_3 ( V_55 , V_49 ) ;
F_1 ( V_49 ) ;
} else
F_5 ( V_49 ) ;
return 0 ;
}
static int F_19 ( struct V_31 * V_32 , struct V_56 * V_57 )
{
unsigned long V_58 = F_7 () ;
F_20 ( V_57 , L_3 ,
( V_58 & V_41 ) ? L_4 : L_5 ) ;
F_20 ( V_57 , L_6 ,
( V_58 & V_59 ) ? L_4 : L_5 ) ;
return 0 ;
}
static T_2 F_21 ( int V_60 , void * V_61 )
{
struct V_62 * V_63 = V_61 ;
struct V_64 * V_65 = F_22 ( V_63 ) ;
unsigned int V_66 ;
unsigned long V_67 = 0 ;
V_66 = F_6 ( V_7 ) & F_7 () ;
if ( V_66 ) {
if ( V_66 & V_49 )
V_67 |= ( V_68 | V_69 ) ;
if ( V_66 & V_59 )
V_67 |= ( V_70 | V_69 ) ;
if ( V_66 & V_41 )
F_23 ( & V_42 ) ;
F_3 ( V_55 , V_66 ) ;
F_24 ( V_65 , 1 , V_67 ) ;
F_12 ( & V_63 -> V_32 , L_7 , V_36 ,
V_67 >> 8 , V_67 & 0x000000FF ) ;
return V_71 ;
}
return V_72 ;
}
static const struct V_8 *
F_25 ( struct V_62 * V_63 )
{
const struct V_73 * V_74 ;
if ( V_63 -> V_32 . V_75 ) {
V_74 = F_26 ( V_76 , V_63 -> V_32 . V_75 ) ;
if ( ! V_74 )
return NULL ;
return ( const struct V_8 * ) V_74 -> V_77 ;
}
return & V_78 ;
}
static int T_3 F_27 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
struct V_79 * V_80 ;
int V_81 = 0 ;
V_8 = F_25 ( V_63 ) ;
if ( ! V_8 )
return - V_82 ;
V_80 = F_28 ( V_63 , V_83 , 0 ) ;
if ( ! V_80 ) {
F_29 ( & V_63 -> V_32 , L_8 ) ;
return - V_84 ;
}
V_60 = F_30 ( V_63 , 0 ) ;
if ( V_60 < 0 ) {
F_29 ( & V_63 -> V_32 , L_9 ) ;
return - V_84 ;
}
V_85 = F_31 ( V_80 -> V_86 , F_32 ( V_80 ) ) ;
if ( ! V_85 ) {
F_29 ( & V_63 -> V_32 , L_10 ) ;
return - V_87 ;
}
F_3 ( V_38 , 0 ) ;
F_3 ( V_88 , 0 ) ;
F_5 ( V_41 | V_49 |
V_59 | V_89 |
V_90 ) ;
V_81 = F_33 ( V_60 , F_21 ,
V_91 ,
L_11 , V_63 ) ;
if ( V_81 ) {
F_29 ( & V_63 -> V_32 , L_12 , V_60 ) ;
goto V_92;
}
if ( ! F_34 ( & V_63 -> V_32 ) )
F_35 ( & V_63 -> V_32 , 1 ) ;
V_65 = F_36 ( V_63 -> V_93 , & V_63 -> V_32 ,
& V_94 , V_95 ) ;
if ( F_37 ( V_65 ) ) {
V_81 = F_38 ( V_65 ) ;
goto V_96;
}
F_39 ( V_63 , V_65 ) ;
F_40 ( & V_63 -> V_32 , L_13 ) ;
return 0 ;
V_96:
F_41 ( V_60 , V_63 ) ;
V_92:
F_42 ( V_85 ) ;
return V_81 ;
}
static int T_4 F_43 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_22 ( V_63 ) ;
F_5 ( V_41 | V_49 |
V_59 | V_89 |
V_90 ) ;
F_41 ( V_60 , V_63 ) ;
F_44 ( V_65 ) ;
F_42 ( V_85 ) ;
F_39 ( V_63 , NULL ) ;
return 0 ;
}
static int F_45 ( struct V_31 * V_32 )
{
V_97 = F_7 ()
& ( V_49 | V_59 ) ;
if ( V_97 ) {
if ( F_46 ( V_32 ) )
F_47 ( V_60 ) ;
else
F_5 ( V_97 ) ;
}
return 0 ;
}
static int F_48 ( struct V_31 * V_32 )
{
if ( V_97 ) {
if ( F_46 ( V_32 ) )
F_49 ( V_60 ) ;
else
F_1 ( V_97 ) ;
}
return 0 ;
}
