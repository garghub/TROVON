static inline void F_1 ( void )
{
while ( F_2 ( V_1 ) & V_2 ) ;
}
static inline void F_3 ( int V_3 )
{
if ( V_3 ) {
F_4 ( 6 , V_1 ) ;
} else {
F_4 ( 7 , V_1 ) ;
}
}
static inline void F_5 ( int V_3 , T_1 V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
T_2 V_8 = V_9 * V_5 + V_4 ;
if ( V_3 )
V_8 <<= 1 ;
F_4 ( V_6 - 1 , V_10 ) ;
F_4 ( V_7 - 1 , V_11 ) ;
F_4 ( V_8 & 0xffff , V_12 ) ;
F_4 ( V_8 >> 16 , V_13 ) ;
}
static inline void F_6 ( int V_3 , T_1 V_14 , T_1 V_15 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_16 ,
T_2 V_17 )
{
T_2 V_8 , V_18 ;
T_2 V_19 = 0 ;
V_7 -- ;
V_6 -- ;
F_4 ( V_16 , V_20 ) ;
if ( ( V_15 < V_5 ) || ( ( V_15 == V_5 ) && ( V_14 <= V_4 ) ) ) {
V_8 = V_9 * ( V_15 + V_7 ) + V_14 + V_6 ;
V_18 = V_9 * ( V_5 + V_7 ) + V_4 + V_6 ;
if ( V_17 ) {
if ( V_3 )
V_19 = ( ( V_6 >> 3 ) + 1 ) * ( V_7 + 1 ) - 1 ;
else
V_19 =
( ( ( V_6 >> 4 ) + 1 ) * ( V_7 + 1 ) - 1 ) * 2 ;
F_4 ( ( 1 << 5 ) | 1 , V_21 ) ;
} else
F_4 ( 1 , V_21 ) ;
} else {
V_8 = V_9 * V_15 + V_14 ;
V_18 = V_9 * V_5 + V_4 ;
if ( V_17 ) {
F_4 ( ( 1 << 5 ) , V_21 ) ;
} else {
F_4 ( 0 , V_21 ) ;
}
}
if ( V_3 ) {
V_8 <<= 1 ;
V_18 <<= 1 ;
}
F_4 ( V_6 , V_10 ) ;
F_4 ( V_7 , V_11 ) ;
F_4 ( V_8 & 0xffff , V_22 ) ;
F_4 ( V_8 >> 16 , V_23 ) ;
F_4 ( V_18 & 0xffff , V_12 ) ;
F_4 ( V_18 >> 16 , V_13 ) ;
if ( V_17 ) {
V_19 += V_17 ;
F_4 ( V_19 & 0xffff , V_24 ) ;
F_4 ( V_19 >> 16 , V_25 ) ;
}
F_3 ( V_3 ) ;
}
static void F_7 ( struct V_26 * V_27 , const struct V_28 * V_29 )
{
if ( V_29 -> V_16 != V_30 )
F_8 ( V_27 , V_29 ) ;
else {
F_1 () ;
F_4 ( 0x00f0 , V_20 ) ;
F_4 ( 16 , V_21 ) ;
if ( V_27 -> V_31 . V_32 == 16 ) {
F_4 ( ( ( T_2 * ) ( V_27 -> V_33 ) ) [ V_29 -> V_34 ] ,
V_35 ) ;
F_5 ( 1 , V_29 -> V_4 , V_29 -> V_5 , V_29 -> V_6 ,
V_29 -> V_7 ) ;
F_3 ( 1 ) ;
} else {
F_4 ( V_29 -> V_34 , V_35 ) ;
F_5 ( 0 , V_29 -> V_4 , V_29 -> V_5 , V_29 -> V_6 ,
V_29 -> V_7 ) ;
F_3 ( 0 ) ;
}
}
}
static void F_9 ( struct V_26 * V_27 , const struct V_36 * V_37 )
{
F_1 () ;
F_6 ( V_27 -> V_31 . V_32 == 16 , V_37 -> V_14 , V_37 -> V_15 ,
V_37 -> V_4 , V_37 -> V_5 , V_37 -> V_6 , V_37 -> V_7 ,
0x00cc , 0 ) ;
}
static int F_10 ( struct V_38 * V_31 ,
struct V_26 * V_39 )
{
int V_40 = V_31 -> V_40 ;
int V_41 = V_31 -> V_41 ;
if ( V_40 != 0 )
return - V_42 ;
F_4 ( ( V_41 * V_39 -> V_43 . V_44 ) >> 10 , V_45 ) ;
return 0 ;
}
int F_11 ( int V_46 , struct V_26 * V_39 )
{
unsigned short V_47 ;
if ( V_46 ) {
V_47 = F_2 ( V_48 ) ;
V_47 &= ~ V_49 ;
F_4 ( V_47 , V_48 ) ;
V_47 = F_2 ( V_50 ) ;
V_47 |= V_51 ;
F_4 ( V_47 , V_50 ) ;
V_47 = F_2 ( V_52 ) ;
V_47 |= V_53 ;
F_4 ( V_47 , V_52 ) ;
} else {
V_47 = F_2 ( V_52 ) ;
V_47 &= ~ V_53 ;
F_4 ( V_47 , V_52 ) ;
V_47 = F_2 ( V_50 ) ;
V_47 &= ~ ( V_51 | V_54 ) ;
F_4 ( V_47 , V_50 ) ;
do {
V_47 = F_2 ( V_50 ) ;
} while( V_47 & V_55 );
V_47 = F_2 ( V_48 ) ;
V_47 |= V_49 ;
F_4 ( V_47 , V_48 ) ;
}
return 0 ;
}
static int F_12 ( unsigned V_56 , unsigned V_57 , unsigned V_58 ,
unsigned V_59 , unsigned V_60 , struct V_26 * V_39 )
{
if ( V_56 >= 256 )
return 1 ;
switch ( V_39 -> V_31 . V_32 ) {
case 8 :
F_4 ( V_56 << 8 , V_61 ) ;
F_4 ( V_57 >> 10 , V_62 ) ;
F_4 ( V_58 >> 10 , V_62 ) ;
F_4 ( V_59 >> 10 , V_62 ) ;
break;
case 16 :
if ( V_56 >= 16 )
return 1 ;
( ( T_2 * ) ( V_39 -> V_33 ) ) [ V_56 ] =
( ( V_57 & 0xf800 ) ) |
( ( V_58 & 0xfc00 ) >> 5 ) | ( ( V_59 & 0xf800 ) >> 11 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_26 * V_39 )
{
F_1 () ;
return 0 ;
}
static int F_14 ( struct V_38 * V_31 , struct V_26 * V_39 )
{
int V_63 ;
V_31 -> V_64 = V_39 -> V_31 . V_64 ;
V_31 -> V_65 = V_39 -> V_31 . V_64 ;
V_31 -> V_66 = V_39 -> V_31 . V_66 ;
if ( ( V_31 -> V_32 != 8 ) && ( V_31 -> V_32 != 16 ) )
V_31 -> V_32 = V_39 -> V_31 . V_32 ;
if ( V_31 -> V_67 < V_31 -> V_66 )
V_31 -> V_67 = V_31 -> V_66 ;
V_63 = V_39 -> V_43 . V_68 / V_31 -> V_64 ;
if ( V_31 -> V_32 == 16 )
V_63 /= 2 ;
if ( V_31 -> V_67 > V_63 )
V_31 -> V_67 = V_63 ;
V_31 -> V_40 = 0 ;
V_31 -> V_41 = 0 ;
switch ( V_31 -> V_32 ) {
case 8 :
V_31 -> V_57 . V_69 = 0 ;
V_31 -> V_57 . V_70 = 8 ;
V_31 -> V_58 . V_69 = 0 ;
V_31 -> V_58 . V_70 = 8 ;
V_31 -> V_59 . V_69 = 0 ;
V_31 -> V_59 . V_70 = 8 ;
V_31 -> V_60 . V_69 = 0 ;
V_31 -> V_60 . V_70 = 0 ;
break;
case 16 :
V_31 -> V_57 . V_69 = 11 ;
V_31 -> V_57 . V_70 = 5 ;
V_31 -> V_58 . V_69 = 5 ;
V_31 -> V_58 . V_70 = 6 ;
V_31 -> V_59 . V_69 = 0 ;
V_31 -> V_59 . V_70 = 5 ;
V_31 -> V_60 . V_69 = 0 ;
V_31 -> V_60 . V_70 = 0 ;
break;
}
return 0 ;
}
static int F_15 ( struct V_26 * V_39 )
{
unsigned short V_71 ;
switch ( V_39 -> V_31 . V_32 ) {
case 8 :
V_39 -> V_43 . V_44 = V_39 -> V_31 . V_64 ;
V_39 -> V_43 . V_72 = V_73 ;
V_39 -> V_43 . V_74 = 16 ;
break;
case 16 :
V_39 -> V_43 . V_44 = V_39 -> V_31 . V_64 * 2 ;
V_39 -> V_43 . V_72 = V_75 ;
V_39 -> V_43 . V_74 = 8 ;
break;
}
F_4 ( V_39 -> V_43 . V_44 , V_76 ) ;
V_71 = F_2 ( V_77 ) ;
V_71 &= ~ 15 ;
V_71 |= ( V_39 -> V_31 . V_32 == 8 ) ? 4 : 8 ;
F_4 ( V_71 , V_77 ) ;
return 0 ;
}
static int F_16 ( struct V_78 * V_79 )
{
unsigned short V_80 , V_71 , V_81 ;
struct V_26 * V_39 ;
int V_82 ;
if ( F_17 ( L_1 , NULL ) )
return - V_83 ;
V_84 . V_85 = F_18 ( 0x1000 ) ;
V_84 . V_86 = 0x1000 ;
V_84 . V_87 = F_18 ( 0x02000000 ) ;
V_84 . V_68 = 512 * 1024 ;
V_80 = F_2 ( V_76 ) ;
V_81 = F_2 ( V_88 ) ;
V_71 = F_2 ( V_77 ) ;
switch ( V_71 & 15 ) {
default:
case 4 :
V_89 . V_32 = 8 ;
V_89 . V_64 = V_80 ;
break;
case 8 :
V_89 . V_32 = 16 ;
V_89 . V_64 = V_80 / 2 ;
break;
}
V_84 . V_44 = V_80 ;
V_84 . V_72 = ( V_89 . V_32 == 8 ) ?
V_73 : V_75 ;
V_89 . V_66 = V_81 + 1 ;
V_89 . V_65 = V_89 . V_64 ;
V_89 . V_67 = V_84 . V_68 / V_80 ;
switch ( V_89 . V_32 ) {
case 8 :
V_89 . V_57 . V_69 = 0 ;
V_89 . V_57 . V_70 = 8 ;
V_89 . V_58 . V_69 = 0 ;
V_89 . V_58 . V_70 = 8 ;
V_89 . V_59 . V_69 = 0 ;
V_89 . V_59 . V_70 = 8 ;
V_89 . V_60 . V_69 = 0 ;
V_89 . V_60 . V_70 = 0 ;
break;
case 16 :
V_89 . V_57 . V_69 = 11 ;
V_89 . V_57 . V_70 = 5 ;
V_89 . V_58 . V_69 = 5 ;
V_89 . V_58 . V_70 = 6 ;
V_89 . V_59 . V_69 = 0 ;
V_89 . V_59 . V_70 = 5 ;
V_89 . V_60 . V_69 = 0 ;
V_89 . V_60 . V_70 = 0 ;
break;
}
V_39 = F_19 ( sizeof( T_2 ) * 16 , & V_79 -> V_79 ) ;
if ( F_20 ( ! V_39 ) )
return - V_90 ;
V_39 -> V_91 = & V_92 ;
V_39 -> V_31 = V_89 ;
V_39 -> V_43 = V_84 ;
V_39 -> V_33 = V_39 -> V_93 ;
V_39 -> V_94 = V_95 | V_96 |
V_97 | V_98 ;
V_39 -> V_99 = ( void * ) V_84 . V_87 ;
V_82 = F_21 ( & V_39 -> V_100 , 256 , 0 ) ;
if ( F_20 ( V_82 < 0 ) )
goto V_101;
V_82 = F_22 ( V_39 ) ;
if ( F_20 ( V_82 < 0 ) )
goto V_102;
F_23 ( V_79 , V_39 ) ;
V_26 ( V_39 , L_2 , V_39 -> V_43 . V_103 ) ;
return 0 ;
V_102:
F_24 ( & V_39 -> V_100 ) ;
V_101:
F_25 ( V_39 ) ;
return V_82 ;
}
static int F_26 ( struct V_78 * V_79 )
{
struct V_26 * V_39 = F_27 ( V_79 ) ;
F_28 ( V_39 ) ;
F_24 ( & V_39 -> V_100 ) ;
F_25 ( V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_104 * V_79 )
{
T_1 V_47 ;
F_11 ( 1 , 0 ) ;
V_47 = F_2 ( V_52 ) ;
V_47 |= V_105 ;
F_4 ( V_47 , V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_104 * V_79 )
{
T_1 V_47 ;
V_47 = F_2 ( V_52 ) ;
V_47 &= ~ V_106 ;
F_31 ( 100 ) ;
V_47 = F_2 ( V_52 ) ;
V_47 &= ~ V_105 ;
F_4 ( V_47 , V_52 ) ;
F_11 ( 0 , 0 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
int V_82 ;
V_82 = F_33 ( & V_107 ) ;
if ( ! V_82 ) {
V_82 = F_34 ( & V_108 ) ;
if ( V_82 )
F_35 ( & V_107 ) ;
}
return V_82 ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_108 ) ;
F_35 ( & V_107 ) ;
}
