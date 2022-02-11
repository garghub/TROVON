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
static int F_18 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_32 ;
V_32 = F_1 ( V_2 , V_33 ) ;
V_32 &= ~ ( V_34 | V_35 | V_36 ) ;
switch ( V_31 & V_37 ) {
case V_38 :
V_32 |= V_39 | V_40 ;
break;
case V_41 :
V_32 |= V_42 | V_43 ;
break;
case V_44 :
V_32 |= V_45 | V_46 ;
}
if ( ( V_31 & V_47 ) != V_48 )
return - V_49 ;
F_4 ( V_2 , V_33 , V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_32 ;
V_32 = F_1 ( V_2 , V_33 ) ;
V_32 &= ~ V_34 ;
switch ( V_31 & V_37 ) {
case V_38 :
V_32 |= V_39 ;
break;
case V_41 :
V_32 |= V_42 ;
break;
case V_44 :
V_32 |= V_45 ;
}
if ( ( V_31 & V_47 ) != V_48 )
return - V_49 ;
F_4 ( V_2 , V_33 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_32 ;
V_32 = F_1 ( V_2 , V_33 ) ;
V_32 &= ~ ( V_35 | V_36 ) ;
switch ( V_31 & V_37 ) {
case V_38 :
V_32 |= V_40 ;
break;
case V_41 :
V_32 |= V_43 ;
break;
case V_44 :
V_32 |= V_46 ;
}
if ( ( V_31 & V_47 ) == V_50 )
V_32 |= V_35 ;
F_4 ( V_2 , V_33 , V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_51 * V_52 , int V_53 ,
struct V_29 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_25 * V_26 = F_22 ( V_2 ) ;
int V_55 = F_1 ( V_2 , V_56 ) ;
switch ( V_53 ) {
case V_57 :
case V_58 :
F_2 ( V_2 , V_56 ,
V_55 & ~ V_59 ) ;
F_23 ( & V_26 -> V_24 ) ;
break;
case V_60 :
case V_61 :
F_2 ( V_2 , V_56 ,
V_55 | V_59 ) ;
F_23 ( & V_26 -> V_24 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_51 * V_52 ,
struct V_62 * V_63 ,
struct V_29 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
T_1 V_64 = F_1 ( V_2 , V_65 ) ;
if ( V_64 & V_66 ) {
int V_67 = F_25 ( V_63 ) ;
T_1 V_68 = F_1 ( V_2 , V_69 ) ;
V_64 &= ~ 0x3 ;
switch ( V_67 ) {
case 6250 ... 12500 :
V_64 |= 0x0 ;
break;
case 12501 ... 25000 :
V_64 |= 0x1 ;
break;
case 25001 ... 50000 :
V_64 |= 0x2 ;
break;
case 50001 ... 100000 :
V_64 |= 0x3 ;
break;
}
F_4 ( V_2 , V_69 , V_70 | V_68 ) ;
}
if ( V_52 -> V_71 == V_72 )
V_64 |= V_73 | V_74 ;
else
V_64 |= V_75 | V_76 ;
F_4 ( V_2 , V_65 , V_64 ) ;
return 0 ;
}
static void F_26 ( struct V_51 * V_52 ,
struct V_29 * V_54 )
{
struct V_77 * V_78 = V_52 -> V_79 ;
struct V_1 * V_2 = V_78 -> V_2 ;
T_1 V_64 = F_1 ( V_2 , V_65 ) ;
if ( V_64 & V_66 ) {
T_1 V_68 = F_1 ( V_2 , V_69 ) ;
F_4 ( V_2 , V_69 , ~ V_70 & V_68 ) ;
}
if ( V_52 -> V_71 == V_72 )
V_64 &= ~ ( V_73 | V_74 ) ;
else
V_64 &= ~ ( V_75 | V_76 ) ;
F_4 ( V_2 , V_65 , V_64 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_80 V_81 )
{
int V_68 = F_1 ( V_2 , V_69 ) ;
int V_3 ;
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
if ( V_2 -> V_82 . V_83 == V_81 )
return 0 ;
switch ( V_81 ) {
case V_84 :
case V_85 :
F_4 ( V_2 , V_69 , V_86 | V_68 ) ;
break;
case V_87 :
if ( V_2 -> V_82 . V_83 == V_88 ) {
if ( F_12 ( V_20 -> V_89 ) ) {
F_13 ( V_20 -> V_89 , 1 ) ;
F_14 ( 1 ) ;
F_11 ( V_2 ) ;
}
F_9 ( V_2 ) ;
}
F_4 ( V_2 , V_69 , 0x0 ) ;
break;
case V_88 :
if ( ! F_12 ( V_20 -> V_89 ) )
break;
F_13 ( V_20 -> V_89 , 0 ) ;
for ( V_3 = V_12 ; V_3 < V_7 ; V_3 ++ )
F_3 ( V_3 - 0x10 , & V_9 ) ;
}
V_2 -> V_82 . V_83 = V_81 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_87 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
struct V_25 * V_26 = F_22 ( V_2 ) ;
int V_90 ;
V_26 -> V_2 = V_2 ;
V_2 -> V_13 = ( V_91 ) F_6 ;
V_2 -> V_14 = V_26 -> V_14 ;
if ( ! V_20 )
return - V_49 ;
if ( F_12 ( V_20 -> V_22 ) ) {
V_90 = F_31 ( V_20 -> V_22 , V_92 ,
L_6 ) ;
if ( V_90 )
goto V_93;
}
if ( F_12 ( V_20 -> V_89 ) ) {
V_90 = F_31 ( V_20 -> V_89 , V_92 ,
L_7 ) ;
if ( V_90 )
goto V_94;
} else {
V_90 = F_11 ( V_2 ) ;
if ( V_90 )
goto V_94;
}
F_32 ( & V_26 -> V_24 , F_15 ) ;
F_27 ( V_2 , V_87 ) ;
switch ( V_20 -> V_95 ) {
case V_96 :
F_2 ( V_2 , V_65 , 0 ) ;
break;
case V_97 :
F_2 ( V_2 , V_65 ,
V_66 ) ;
break;
}
return 0 ;
V_94:
if ( F_12 ( V_20 -> V_22 ) )
F_33 ( V_20 -> V_22 ) ;
V_93:
return V_90 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_17 -> V_21 ;
F_27 ( V_2 , V_88 ) ;
F_33 ( V_20 -> V_22 ) ;
F_33 ( V_20 -> V_89 ) ;
return 0 ;
}
static T_3 int F_35 ( struct V_98 * V_99 ,
const struct V_100 * V_101 )
{
struct V_25 * V_26 ;
int V_90 ;
V_26 = F_36 ( & V_99 -> V_17 , sizeof( struct V_25 ) ,
V_102 ) ;
if ( V_26 == NULL )
return - V_103 ;
F_37 ( V_99 , V_26 ) ;
V_26 -> V_14 = V_99 ;
V_90 = F_38 ( & V_99 -> V_17 ,
& V_104 , V_105 , F_39 ( V_105 ) ) ;
return V_90 ;
}
static int T_4 F_40 ( struct V_98 * V_99 )
{
F_41 ( & V_99 -> V_17 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
int V_90 = 0 ;
#if F_43 ( V_106 ) || F_43 ( V_107 )
V_90 = F_44 ( & V_108 ) ;
if ( V_90 != 0 )
F_45 ( L_8 , V_90 ) ;
#endif
return V_90 ;
}
static void T_6 F_46 ( void )
{
#if F_43 ( V_106 ) || F_43 ( V_107 )
F_47 ( & V_108 ) ;
#endif
}
