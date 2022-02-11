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
if ( ! F_5 ( V_2 ) && ( V_3 >= V_11 ) )
return 0 ;
F_6 ( L_1 , V_3 , V_8 ) ;
if ( V_2 -> V_12 ( V_2 -> V_13 , V_10 , 3 ) == 3 ) {
unsigned int V_14 ;
F_7 ( V_2 -> V_13 , V_10 , 1 ) ;
F_8 ( V_2 -> V_13 , V_10 , 2 ) ;
V_14 = ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
if ( V_14 != V_8 ) {
F_6 ( L_2 ,
( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ) ;
return - V_15 ;
}
if ( V_3 >= 0x10 )
F_9 ( V_3 - 0x10 , & V_9 ) ;
return 0 ;
} else
return - V_15 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_10 [ 3 ] ;
T_1 * V_4 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_11 ; V_3 ++ ) {
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = ( V_4 [ V_3 ] & 0xff00 ) >> 8 ;
V_10 [ 2 ] = V_4 [ V_3 ] & 0x00ff ;
if ( V_2 -> V_12 ( V_2 -> V_13 , V_10 , 3 ) != 3 )
F_11 ( V_2 -> V_16 , L_3 ,
V_17 , V_3 ) ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_16 -> V_20 ;
if ( F_13 ( V_19 -> V_21 ) ) {
F_14 ( V_19 -> V_21 , 1 ) ;
F_15 ( 1 ) ;
F_14 ( V_19 -> V_21 , 0 ) ;
} else {
T_2 V_10 [ 3 ] ;
V_10 [ 0 ] = V_6 ;
V_10 [ 1 ] = 0 ;
V_10 [ 2 ] = 0 ;
if ( V_2 -> V_12 ( V_2 -> V_13 , V_10 , 3 ) != 3 ) {
F_11 ( V_2 -> V_16 , L_4 , V_17 ) ;
return - V_15 ;
}
}
return 0 ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_17 ( V_23 , struct V_24 , V_23 ) ;
struct V_1 * V_26 = V_25 -> V_2 ;
int V_27 , V_3 ;
F_18 (bit, &uda1380_cache_dirty, UDA1380_CACHEREGNUM - 0x10 ) {
V_3 = 0x10 + V_27 ;
F_6 ( L_5 , V_3 ,
F_1 ( V_26 , V_3 ) ) ;
F_4 ( V_26 , V_3 ,
F_1 ( V_26 , V_3 ) ) ;
F_9 ( V_27 , & V_9 ) ;
}
}
static int F_19 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
int V_31 ;
V_31 = F_1 ( V_2 , V_32 ) ;
V_31 &= ~ ( V_33 | V_34 | V_35 ) ;
switch ( V_30 & V_36 ) {
case V_37 :
V_31 |= V_38 | V_39 ;
break;
case V_40 :
V_31 |= V_41 | V_42 ;
break;
case V_43 :
V_31 |= V_44 | V_45 ;
}
if ( ( V_30 & V_46 ) != V_47 )
return - V_48 ;
F_2 ( V_2 , V_32 , V_31 ) ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
int V_31 ;
V_31 = F_1 ( V_2 , V_32 ) ;
V_31 &= ~ V_33 ;
switch ( V_30 & V_36 ) {
case V_37 :
V_31 |= V_38 ;
break;
case V_40 :
V_31 |= V_41 ;
break;
case V_43 :
V_31 |= V_44 ;
}
if ( ( V_30 & V_46 ) != V_47 )
return - V_48 ;
F_4 ( V_2 , V_32 , V_31 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
int V_31 ;
V_31 = F_1 ( V_2 , V_32 ) ;
V_31 &= ~ ( V_34 | V_35 ) ;
switch ( V_30 & V_36 ) {
case V_37 :
V_31 |= V_39 ;
break;
case V_40 :
V_31 |= V_42 ;
break;
case V_43 :
V_31 |= V_45 ;
}
if ( ( V_30 & V_46 ) == V_49 )
V_31 |= V_34 ;
F_4 ( V_2 , V_32 , V_31 ) ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 , int V_52 ,
struct V_28 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_24 * V_25 = F_23 ( V_2 ) ;
int V_54 = F_1 ( V_2 , V_55 ) ;
switch ( V_52 ) {
case V_56 :
case V_57 :
F_2 ( V_2 , V_55 ,
V_54 & ~ V_58 ) ;
F_24 ( & V_25 -> V_23 ) ;
break;
case V_59 :
case V_60 :
F_2 ( V_2 , V_55 ,
V_54 | V_58 ) ;
F_24 ( & V_25 -> V_23 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_50 * V_51 ,
struct V_61 * V_62 ,
struct V_28 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_1 V_63 = F_1 ( V_2 , V_64 ) ;
if ( V_63 & V_65 ) {
int V_66 = F_26 ( V_62 ) ;
T_1 V_67 = F_1 ( V_2 , V_68 ) ;
V_63 &= ~ 0x3 ;
switch ( V_66 ) {
case 6250 ... 12500 :
V_63 |= 0x0 ;
break;
case 12501 ... 25000 :
V_63 |= 0x1 ;
break;
case 25001 ... 50000 :
V_63 |= 0x2 ;
break;
case 50001 ... 100000 :
V_63 |= 0x3 ;
break;
}
F_4 ( V_2 , V_68 , V_69 | V_67 ) ;
}
if ( V_51 -> V_70 == V_71 )
V_63 |= V_72 | V_73 ;
else
V_63 |= V_74 | V_75 ;
F_4 ( V_2 , V_64 , V_63 ) ;
return 0 ;
}
static void F_27 ( struct V_50 * V_51 ,
struct V_28 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
T_1 V_63 = F_1 ( V_2 , V_64 ) ;
if ( V_63 & V_65 ) {
T_1 V_67 = F_1 ( V_2 , V_68 ) ;
F_4 ( V_2 , V_68 , ~ V_69 & V_67 ) ;
}
if ( V_51 -> V_70 == V_71 )
V_63 &= ~ ( V_72 | V_73 ) ;
else
V_63 &= ~ ( V_74 | V_75 ) ;
F_4 ( V_2 , V_64 , V_63 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
int V_67 = F_1 ( V_2 , V_68 ) ;
int V_3 ;
struct V_18 * V_19 = V_2 -> V_16 -> V_20 ;
switch ( V_77 ) {
case V_78 :
case V_79 :
F_4 ( V_2 , V_68 , V_80 | V_67 ) ;
break;
case V_81 :
if ( F_29 ( V_2 ) == V_82 ) {
if ( F_13 ( V_19 -> V_83 ) ) {
F_14 ( V_19 -> V_83 , 1 ) ;
F_15 ( 1 ) ;
F_12 ( V_2 ) ;
}
F_10 ( V_2 ) ;
}
F_4 ( V_2 , V_68 , 0x0 ) ;
break;
case V_82 :
if ( ! F_13 ( V_19 -> V_83 ) )
break;
F_14 ( V_19 -> V_83 , 0 ) ;
for ( V_3 = V_11 ; V_3 < V_7 ; V_3 ++ )
F_3 ( V_3 - 0x10 , & V_9 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_16 -> V_20 ;
struct V_24 * V_25 = F_23 ( V_2 ) ;
int V_84 ;
V_25 -> V_2 = V_2 ;
V_2 -> V_12 = ( V_85 ) F_7 ;
V_2 -> V_13 = V_25 -> V_13 ;
if ( ! F_13 ( V_19 -> V_83 ) ) {
V_84 = F_12 ( V_2 ) ;
if ( V_84 )
return V_84 ;
}
F_31 ( & V_25 -> V_23 , F_16 ) ;
switch ( V_19 -> V_86 ) {
case V_87 :
F_2 ( V_2 , V_64 , 0 ) ;
break;
case V_88 :
F_2 ( V_2 , V_64 ,
V_65 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_89 * V_90 ,
const struct V_91 * V_92 )
{
struct V_18 * V_19 = V_90 -> V_16 . V_20 ;
struct V_24 * V_25 ;
int V_84 ;
if ( ! V_19 )
return - V_48 ;
V_25 = F_33 ( & V_90 -> V_16 , sizeof( struct V_24 ) ,
V_93 ) ;
if ( V_25 == NULL )
return - V_94 ;
if ( F_13 ( V_19 -> V_21 ) ) {
V_84 = F_34 ( & V_90 -> V_16 , V_19 -> V_21 ,
V_95 , L_6 ) ;
if ( V_84 )
return V_84 ;
}
if ( F_13 ( V_19 -> V_83 ) ) {
V_84 = F_34 ( & V_90 -> V_16 , V_19 -> V_83 ,
V_95 , L_7 ) ;
if ( V_84 )
return V_84 ;
}
F_35 ( V_90 , V_25 ) ;
V_25 -> V_13 = V_90 ;
V_84 = F_36 ( & V_90 -> V_16 ,
& V_96 , V_97 , F_37 ( V_97 ) ) ;
return V_84 ;
}
static int F_38 ( struct V_89 * V_90 )
{
F_39 ( & V_90 -> V_16 ) ;
return 0 ;
}
