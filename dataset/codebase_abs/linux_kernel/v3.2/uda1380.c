static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 == V_6 )
return 0 ;
if ( V_3 >= V_7 )
return - 1 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_8 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_7 )
return;
if ( ( V_3 >= 0x10 ) && ( V_4 [ V_3 ] != V_8 ) )
F_3 ( V_3 - 0x10 , & V_9 ) ;
V_4 [ V_3 ] = V_8 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_8 )
{
T_2 V_10 [ 3 ] ;
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = ( V_8 & 0xff00 ) >> 8 ;
V_10 [ 2 ] = V_8 & 0x00ff ;
F_2 ( V_2 , V_3 , V_8 ) ;
if ( ! V_2 -> V_11 && ( V_3 >= V_12 ) )
return 0 ;
F_5 ( L_1 , V_3 , V_8 ) ;
if ( V_2 -> V_13 ( V_2 -> V_14 , V_10 , 3 ) == 3 ) {
unsigned int V_15 ;
F_6 ( V_2 -> V_14 , V_10 , 1 ) ;
F_7 ( V_2 -> V_14 , V_10 , 2 ) ;
V_15 = ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
if ( V_15 != V_8 ) {
F_5 ( L_2 ,
( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ) ;
return - V_16 ;
}
if ( V_3 >= 0x10 )
F_8 ( V_3 - 0x10 , & V_9 ) ;
return 0 ;
} else
return - V_16 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_10 [ 3 ] ;
T_1 * V_4 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = ( V_4 [ V_3 ] & 0xff00 ) >> 8 ;
V_10 [ 2 ] = V_4 [ V_3 ] & 0x00ff ;
if ( V_2 -> V_13 ( V_2 -> V_14 , V_10 , 3 ) != 3 )
F_10 ( V_2 -> V_17 , L_3 ,
V_18 , V_3 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
if ( F_12 ( V_20 -> V_22 ) ) {
F_13 ( V_20 -> V_22 , 1 ) ;
F_14 ( 1 ) ;
F_13 ( V_20 -> V_22 , 0 ) ;
} else {
T_2 V_10 [ 3 ] ;
V_10 [ 0 ] = V_6 ;
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] = 0 ;
if ( V_2 -> V_13 ( V_2 -> V_14 , V_10 , 3 ) != 3 ) {
F_10 ( V_2 -> V_17 , L_4 , V_18 ) ;
return - V_16 ;
}
}
return 0 ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_24 , struct V_25 , V_24 ) ;
struct V_1 * V_27 = V_26 -> V_2 ;
int V_28 , V_3 ;
F_17 (bit, &uda1380_cache_dirty, UDA1380_CACHEREGNUM - 0x10 ) {
V_3 = 0x10 + V_28 ;
F_5 ( L_5 , V_3 ,
F_1 ( V_27 , V_3 ) ) ;
F_4 ( V_27 , V_3 ,
F_1 ( V_27 , V_3 ) ) ;
F_8 ( V_28 , & V_9 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
F_19 ( V_30 , V_31 ,
F_20 ( V_31 ) ) ;
F_21 ( V_30 , V_32 , F_20 ( V_32 ) ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
int V_36 ;
V_36 = F_1 ( V_2 , V_37 ) ;
V_36 &= ~ ( V_38 | V_39 | V_40 ) ;
switch ( V_35 & V_41 ) {
case V_42 :
V_36 |= V_43 | V_44 ;
break;
case V_45 :
V_36 |= V_46 | V_47 ;
break;
case V_48 :
V_36 |= V_49 | V_50 ;
}
if ( ( V_35 & V_51 ) != V_52 )
return - V_53 ;
F_4 ( V_2 , V_37 , V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
int V_36 ;
V_36 = F_1 ( V_2 , V_37 ) ;
V_36 &= ~ V_38 ;
switch ( V_35 & V_41 ) {
case V_42 :
V_36 |= V_43 ;
break;
case V_45 :
V_36 |= V_46 ;
break;
case V_48 :
V_36 |= V_49 ;
}
if ( ( V_35 & V_51 ) != V_52 )
return - V_53 ;
F_4 ( V_2 , V_37 , V_36 ) ;
return 0 ;
}
static int F_24 ( struct V_33 * V_34 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_34 -> V_2 ;
int V_36 ;
V_36 = F_1 ( V_2 , V_37 ) ;
V_36 &= ~ ( V_39 | V_40 ) ;
switch ( V_35 & V_41 ) {
case V_42 :
V_36 |= V_44 ;
break;
case V_45 :
V_36 |= V_47 ;
break;
case V_48 :
V_36 |= V_50 ;
}
if ( ( V_35 & V_51 ) == V_54 )
V_36 |= V_39 ;
F_4 ( V_2 , V_37 , V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_55 * V_56 , int V_57 ,
struct V_33 * V_58 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_25 * V_26 = F_26 ( V_2 ) ;
int V_62 = F_1 ( V_2 , V_63 ) ;
switch ( V_57 ) {
case V_64 :
case V_65 :
F_2 ( V_2 , V_63 ,
V_62 & ~ V_66 ) ;
F_27 ( & V_26 -> V_24 ) ;
break;
case V_67 :
case V_68 :
F_2 ( V_2 , V_63 ,
V_62 | V_66 ) ;
F_27 ( & V_26 -> V_24 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_55 * V_56 ,
struct V_69 * V_70 ,
struct V_33 * V_58 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
struct V_1 * V_2 = V_60 -> V_2 ;
T_1 V_71 = F_1 ( V_2 , V_72 ) ;
if ( V_71 & V_73 ) {
int V_74 = F_29 ( V_70 ) ;
T_1 V_75 = F_1 ( V_2 , V_76 ) ;
V_71 &= ~ 0x3 ;
switch ( V_74 ) {
case 6250 ... 12500 :
V_71 |= 0x0 ;
break;
case 12501 ... 25000 :
V_71 |= 0x1 ;
break;
case 25001 ... 50000 :
V_71 |= 0x2 ;
break;
case 50001 ... 100000 :
V_71 |= 0x3 ;
break;
}
F_4 ( V_2 , V_76 , V_77 | V_75 ) ;
}
if ( V_56 -> V_78 == V_79 )
V_71 |= V_80 | V_81 ;
else
V_71 |= V_82 | V_83 ;
F_4 ( V_2 , V_72 , V_71 ) ;
return 0 ;
}
static void F_30 ( struct V_55 * V_56 ,
struct V_33 * V_58 )
{
struct V_59 * V_60 = V_56 -> V_61 ;
struct V_1 * V_2 = V_60 -> V_2 ;
T_1 V_71 = F_1 ( V_2 , V_72 ) ;
if ( V_71 & V_73 ) {
T_1 V_75 = F_1 ( V_2 , V_76 ) ;
F_4 ( V_2 , V_76 , ~ V_77 & V_75 ) ;
}
if ( V_56 -> V_78 == V_79 )
V_71 &= ~ ( V_80 | V_81 ) ;
else
V_71 &= ~ ( V_82 | V_83 ) ;
F_4 ( V_2 , V_72 , V_71 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_84 V_85 )
{
int V_75 = F_1 ( V_2 , V_76 ) ;
int V_3 ;
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
if ( V_2 -> V_30 . V_86 == V_85 )
return 0 ;
switch ( V_85 ) {
case V_87 :
case V_88 :
F_4 ( V_2 , V_76 , V_89 | V_75 ) ;
break;
case V_90 :
if ( V_2 -> V_30 . V_86 == V_91 ) {
if ( F_12 ( V_20 -> V_92 ) ) {
F_13 ( V_20 -> V_92 , 1 ) ;
F_14 ( 1 ) ;
F_11 ( V_2 ) ;
}
F_9 ( V_2 ) ;
}
F_4 ( V_2 , V_76 , 0x0 ) ;
break;
case V_91 :
if ( ! F_12 ( V_20 -> V_92 ) )
break;
F_13 ( V_20 -> V_92 , 0 ) ;
for ( V_3 = V_12 ; V_3 < V_7 ; V_3 ++ )
F_3 ( V_3 - 0x10 , & V_9 ) ;
}
V_2 -> V_30 . V_86 = V_85 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , T_3 V_93 )
{
F_31 ( V_2 , V_91 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_90 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
struct V_25 * V_26 = F_26 ( V_2 ) ;
int V_94 ;
V_26 -> V_2 = V_2 ;
V_2 -> V_13 = ( V_95 ) F_6 ;
V_2 -> V_14 = V_26 -> V_14 ;
if ( ! V_20 )
return - V_53 ;
if ( F_12 ( V_20 -> V_22 ) ) {
V_94 = F_35 ( V_20 -> V_22 , L_6 ) ;
if ( V_94 )
goto V_96;
V_94 = F_36 ( V_20 -> V_22 , 0 ) ;
if ( V_94 )
goto V_97;
}
if ( F_12 ( V_20 -> V_92 ) ) {
V_94 = F_35 ( V_20 -> V_92 , L_7 ) ;
if ( V_94 )
goto V_98;
V_94 = F_36 ( V_20 -> V_92 , 0 ) ;
if ( V_94 )
goto V_99;
} else {
V_94 = F_11 ( V_2 ) ;
if ( V_94 ) {
F_10 ( V_2 -> V_17 , L_8 ) ;
goto V_100;
}
}
F_37 ( & V_26 -> V_24 , F_15 ) ;
F_31 ( V_2 , V_90 ) ;
switch ( V_20 -> V_101 ) {
case V_102 :
F_2 ( V_2 , V_72 , 0 ) ;
break;
case V_103 :
F_2 ( V_2 , V_72 ,
V_73 ) ;
break;
}
F_38 ( V_2 , V_104 ,
F_20 ( V_104 ) ) ;
F_18 ( V_2 ) ;
return 0 ;
V_100:
V_99:
if ( F_12 ( V_20 -> V_92 ) )
F_39 ( V_20 -> V_92 ) ;
V_97:
V_98:
if ( F_12 ( V_20 -> V_22 ) )
F_39 ( V_20 -> V_22 ) ;
V_96:
return V_94 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
F_31 ( V_2 , V_91 ) ;
F_39 ( V_20 -> V_22 ) ;
F_39 ( V_20 -> V_92 ) ;
return 0 ;
}
static T_4 int F_41 ( struct V_105 * V_106 ,
const struct V_107 * V_108 )
{
struct V_25 * V_26 ;
int V_94 ;
V_26 = F_42 ( sizeof( struct V_25 ) , V_109 ) ;
if ( V_26 == NULL )
return - V_110 ;
F_43 ( V_106 , V_26 ) ;
V_26 -> V_14 = V_106 ;
V_94 = F_44 ( & V_106 -> V_17 ,
& V_111 , V_112 , F_20 ( V_112 ) ) ;
if ( V_94 < 0 )
F_45 ( V_26 ) ;
return V_94 ;
}
static int T_5 F_46 ( struct V_105 * V_106 )
{
F_47 ( & V_106 -> V_17 ) ;
F_45 ( F_48 ( V_106 ) ) ;
return 0 ;
}
static int T_6 F_49 ( void )
{
int V_94 = 0 ;
#if F_50 ( V_113 ) || F_50 ( V_114 )
V_94 = F_51 ( & V_115 ) ;
if ( V_94 != 0 )
F_52 ( L_9 , V_94 ) ;
#endif
return V_94 ;
}
static void T_7 F_53 ( void )
{
#if F_50 ( V_113 ) || F_50 ( V_114 )
F_54 ( & V_115 ) ;
#endif
}
