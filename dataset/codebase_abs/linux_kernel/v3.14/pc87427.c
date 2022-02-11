static inline void F_1 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline int F_3 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_4 ( V_1 + 1 ) ;
}
static inline void F_5 ( int V_1 )
{
F_2 ( 0x02 , V_1 ) ;
F_2 ( 0x02 , V_1 + 1 ) ;
}
static inline int F_6 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_2 )
{
return F_4 ( V_5 -> V_7 [ V_6 ] + V_2 ) ;
}
static inline int F_7 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 V_8 , T_1 V_2 )
{
F_2 ( V_8 , V_5 -> V_7 [ V_6 ] + V_9 ) ;
return F_4 ( V_5 -> V_7 [ V_6 ] + V_2 ) ;
}
static inline void F_8 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 V_8 , T_1 V_2 , T_1 V_10 )
{
F_2 ( V_8 , V_5 -> V_7 [ V_6 ] + V_9 ) ;
F_2 ( V_10 , V_5 -> V_7 [ V_6 ] + V_2 ) ;
}
static void F_9 ( struct V_4 * V_5 , T_1 V_11 )
{
int V_12 = V_5 -> V_7 [ V_13 ] ;
F_2 ( F_10 ( V_11 ) , V_12 + V_9 ) ;
V_5 -> V_14 [ V_11 ] = F_11 ( V_12 + V_15 ) ;
V_5 -> V_16 [ V_11 ] = F_11 ( V_12 + V_17 ) ;
V_5 -> V_18 [ V_11 ] = F_4 ( V_12 + V_19 ) ;
F_2 ( V_5 -> V_18 [ V_11 ] , V_12 + V_19 ) ;
}
static inline unsigned long F_12 ( T_2 V_2 )
{
V_2 &= 0xfffc ;
if ( V_2 == 0x0000 || V_2 == 0xfffc )
return 0 ;
return 5400000UL / V_2 ;
}
static inline T_2 F_13 ( unsigned long V_3 )
{
if ( V_3 < 83UL )
return 0xffff ;
if ( V_3 >= 1350000UL )
return 0x0004 ;
return ( ( 1350000UL + V_3 / 2 ) / V_3 ) << 2 ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_11 )
{
int V_12 = V_5 -> V_7 [ V_13 ] ;
F_2 ( F_15 ( V_11 ) , V_12 + V_9 ) ;
V_5 -> V_20 [ V_11 ] = F_4 ( V_12 + V_21 ) ;
V_5 -> V_22 [ V_11 ] = F_4 ( V_12 + V_23 ) ;
}
static inline int F_16 ( T_1 V_2 )
{
switch ( V_2 & V_24 ) {
case V_25 :
return 0 ;
case V_26 :
case V_27 :
return 1 ;
case V_28 :
return 2 ;
default:
return - V_29 ;
}
}
static inline T_1 F_17 ( unsigned long V_3 , T_1 V_30 )
{
switch ( V_3 ) {
default:
return V_25 ;
case 1 :
return V_30 ? V_26 : V_27 ;
case 2 :
return V_28 ;
}
}
static void F_18 ( struct V_4 * V_5 , T_1 V_11 )
{
int V_12 = V_5 -> V_7 [ V_31 ] ;
F_2 ( F_19 ( V_11 ) , V_12 + V_9 ) ;
V_5 -> V_32 [ V_11 ] = F_20 ( F_11 ( V_12 + V_33 ) ) ;
V_5 -> V_34 [ V_11 ] = F_4 ( V_12 + V_35 ) ;
V_5 -> V_36 [ V_11 ] = F_4 ( V_12 + V_37 ) ;
V_5 -> V_38 [ V_11 ] = F_4 ( V_12 + V_39 ) ;
V_5 -> V_40 [ V_11 ] = F_4 ( V_12 + V_41 ) ;
V_5 -> V_42 [ V_11 ] = F_4 ( V_12 + V_43 ) ;
F_2 ( V_5 -> V_42 [ V_11 ] , V_12 + V_43 ) ;
}
static inline unsigned int F_21 ( T_1 V_2 )
{
switch ( V_2 & V_44 ) {
case V_45 :
return 4 ;
case V_46 :
case V_47 :
return 3 ;
default:
return 0 ;
}
}
static inline long F_22 ( T_3 V_2 )
{
return V_2 * 1000 / 256 ;
}
static inline long F_23 ( T_4 V_2 )
{
return V_2 * 1000 ;
}
static struct V_4 * F_24 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_25 ( V_49 ) ;
int V_50 ;
F_26 ( & V_5 -> V_51 ) ;
if ( ! F_27 ( V_52 , V_5 -> V_53 + V_54 )
&& V_5 -> V_53 )
goto V_55;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
if ( ! ( V_5 -> V_56 & ( 1 << V_50 ) ) )
continue;
F_9 ( V_5 , V_50 ) ;
}
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( ! ( V_5 -> V_57 & ( 1 << V_50 ) ) )
continue;
F_14 ( V_5 , V_50 ) ;
}
for ( V_50 = 0 ; V_50 < 6 ; V_50 ++ ) {
if ( ! ( V_5 -> V_58 & ( 1 << V_50 ) ) )
continue;
F_18 ( V_5 , V_50 ) ;
}
V_5 -> V_53 = V_52 ;
V_55:
F_28 ( & V_5 -> V_51 ) ;
return V_5 ;
}
static T_5 F_29 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_1 , F_12 ( V_5 -> V_14 [ V_11 ] ) ) ;
}
static T_5 F_31 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_1 , F_12 ( V_5 -> V_16 [ V_11 ] ) ) ;
}
static T_5 F_32 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ! ! ( V_5 -> V_18 [ V_11 ]
& V_63 ) ) ;
}
static T_5 F_33 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ! ! ( V_5 -> V_18 [ V_11 ]
& V_64 ) ) ;
}
static T_5 F_34 ( struct V_48 * V_49 , struct V_59
* V_60 , const char * V_61 , T_6 V_65 )
{
struct V_4 * V_5 = F_25 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
unsigned long V_3 ;
int V_12 = V_5 -> V_7 [ V_13 ] ;
if ( F_35 ( V_61 , 10 , & V_3 ) < 0 )
return - V_66 ;
F_26 ( & V_5 -> V_51 ) ;
F_2 ( F_10 ( V_11 ) , V_12 + V_9 ) ;
F_2 ( 0 , V_12 + V_19 ) ;
V_5 -> V_16 [ V_11 ] = F_13 ( V_3 ) ;
F_36 ( V_5 -> V_16 [ V_11 ] , V_12 + V_17 ) ;
F_2 ( V_67 , V_12 + V_19 ) ;
F_28 ( & V_5 -> V_51 ) ;
return V_65 ;
}
static void F_37 ( struct V_4 * V_5 , int V_11 , T_1 V_68 )
{
int V_12 = V_5 -> V_7 [ V_13 ] ;
V_5 -> V_20 [ V_11 ] &= ~ V_24 ;
V_5 -> V_20 [ V_11 ] |= V_68 ;
F_2 ( V_5 -> V_20 [ V_11 ] , V_12 + V_21 ) ;
}
static T_5 F_38 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
int V_20 ;
V_20 = F_16 ( V_5 -> V_20 [ V_11 ] ) ;
if ( V_20 < 0 )
return V_20 ;
return sprintf ( V_61 , L_2 , V_20 ) ;
}
static T_5 F_39 ( struct V_48 * V_49 , struct V_59
* V_60 , const char * V_61 , T_6 V_65 )
{
struct V_4 * V_5 = F_25 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
unsigned long V_3 ;
if ( F_35 ( V_61 , 10 , & V_3 ) < 0 || V_3 > 2 )
return - V_66 ;
if ( V_3 == 2 && ! ( V_5 -> V_69 & ( 1 << V_11 ) ) )
return - V_66 ;
F_26 ( & V_5 -> V_51 ) ;
F_14 ( V_5 , V_11 ) ;
F_37 ( V_5 , V_11 , F_17 ( V_3 , V_5 -> V_22 [ V_11 ] ) ) ;
F_28 ( & V_5 -> V_51 ) ;
return V_65 ;
}
static T_5 F_40 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ( int ) V_5 -> V_22 [ V_11 ] ) ;
}
static T_5 F_41 ( struct V_48 * V_49 , struct V_59
* V_60 , const char * V_61 , T_6 V_65 )
{
struct V_4 * V_5 = F_25 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
unsigned long V_3 ;
int V_12 = V_5 -> V_7 [ V_13 ] ;
T_1 V_68 ;
if ( F_35 ( V_61 , 10 , & V_3 ) < 0 || V_3 > 0xff )
return - V_66 ;
F_26 ( & V_5 -> V_51 ) ;
F_14 ( V_5 , V_11 ) ;
V_68 = V_5 -> V_20 [ V_11 ] & V_24 ;
if ( V_68 != V_26 && V_68 != V_27 ) {
F_42 ( V_49 ,
L_3 ,
V_11 + 1 ) ;
F_28 ( & V_5 -> V_51 ) ;
return - V_70 ;
}
if ( V_68 == V_26 && V_3 == 0 ) {
F_37 ( V_5 , V_11 , V_27 ) ;
V_68 = V_27 ;
F_43 ( V_49 , L_4 , V_11 + 1 ,
L_5 , L_6 ) ;
} else if ( V_68 == V_27 && V_3 != 0 ) {
F_37 ( V_5 , V_11 , V_26 ) ;
V_68 = V_26 ;
F_43 ( V_49 , L_4 , V_11 + 1 ,
L_6 , L_5 ) ;
}
V_5 -> V_22 [ V_11 ] = V_3 ;
if ( V_68 == V_26 )
F_2 ( V_3 , V_12 + V_23 ) ;
F_28 ( & V_5 -> V_51 ) ;
return V_65 ;
}
static T_5 F_44 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_7 , F_22 ( V_5 -> V_32 [ V_11 ] ) ) ;
}
static T_5 F_45 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_7 , F_23 ( V_5 -> V_36 [ V_11 ] ) ) ;
}
static T_5 F_46 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_7 , F_23 ( V_5 -> V_34 [ V_11 ] ) ) ;
}
static T_5 F_47 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_7 , F_23 ( V_5 -> V_38 [ V_11 ] ) ) ;
}
static T_5 F_48 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_8 , F_21 ( V_5 -> V_40 [ V_11 ] ) ) ;
}
static T_5 F_49 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ! ! ( V_5 -> V_42 [ V_11 ]
& V_71 ) ) ;
}
static T_5 F_50 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ! ! ( V_5 -> V_42 [ V_11 ]
& V_72 ) ) ;
}
static T_5 F_51 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ! ! ( V_5 -> V_42 [ V_11 ]
& V_73 ) ) ;
}
static T_5 F_52 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_24 ( V_49 ) ;
int V_11 = F_30 ( V_60 ) -> V_62 ;
return sprintf ( V_61 , L_2 , ! ! ( V_5 -> V_42 [ V_11 ]
& V_74 ) ) ;
}
static T_5 F_53 ( struct V_48 * V_49 , struct V_59
* V_60 , char * V_61 )
{
struct V_4 * V_5 = F_25 ( V_49 ) ;
return sprintf ( V_61 , L_9 , V_5 -> V_75 ) ;
}
static int F_54 ( struct V_76 * V_77 ,
int V_65 )
{
struct V_78 * V_79 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_65 ; V_50 ++ ) {
V_79 = F_55 ( V_77 , V_80 , V_50 ) ;
if ( ! V_79 ) {
F_56 ( & V_77 -> V_49 , L_10 , V_50 ) ;
return - V_81 ;
}
if ( ! F_57 ( & V_77 -> V_49 , V_79 -> V_82 ,
F_58 ( V_79 ) , V_83 ) ) {
F_56 ( & V_77 -> V_49 ,
L_11 ,
( unsigned long ) V_79 -> V_82 ,
( unsigned long ) V_79 -> V_84 ) ;
return - V_85 ;
}
}
return 0 ;
}
static void F_59 ( struct V_48 * V_49 )
{
struct V_86 * V_87 = F_60 ( V_49 ) ;
struct V_4 * V_5 = F_25 ( V_49 ) ;
int V_50 ;
T_1 V_2 ;
V_2 = F_6 ( V_5 , V_13 , V_9 ) ;
if ( ! ( V_2 & 0x80 ) )
F_61 ( V_49 , L_12 , L_13 ) ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
if ( ! ( V_87 -> V_88 & ( 1 << V_50 ) ) )
continue;
V_2 = F_7 ( V_5 , V_13 , F_10 ( V_50 ) ,
V_19 ) ;
if ( V_2 & V_67 )
V_5 -> V_56 |= ( 1 << V_50 ) ;
}
if ( ! V_5 -> V_56 ) {
F_43 ( V_49 , L_14 ) ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
if ( ! ( V_87 -> V_88 & ( 1 << V_50 ) ) )
continue;
F_8 ( V_5 , V_13 , F_10 ( V_50 ) ,
V_19 ,
V_67 ) ;
}
V_5 -> V_56 = V_87 -> V_88 ;
}
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( ! ( V_87 -> V_89 & ( 1 << V_50 ) ) )
continue;
V_2 = F_7 ( V_5 , V_13 , F_15 ( V_50 ) ,
V_21 ) ;
if ( V_2 & V_90 )
V_5 -> V_57 |= ( 1 << V_50 ) ;
if ( ( V_2 & V_24 ) == V_28 ) {
F_43 ( V_49 , L_15 ,
V_50 + 1 ) ;
V_5 -> V_69 |= ( 1 << V_50 ) ;
}
}
V_2 = F_6 ( V_5 , V_31 , V_9 ) ;
if ( ! ( V_2 & 0x80 ) )
F_61 ( V_49 , L_12 , L_16 ) ;
for ( V_50 = 0 ; V_50 < 6 ; V_50 ++ ) {
V_2 = F_7 ( V_5 , V_31 , F_19 ( V_50 ) ,
V_43 ) ;
if ( V_2 & V_91 )
V_5 -> V_58 |= ( 1 << V_50 ) ;
}
}
static void F_62 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_25 ( V_49 ) ;
int V_50 ;
F_63 ( V_49 , & V_92 ) ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
if ( ! ( V_5 -> V_56 & ( 1 << V_50 ) ) )
continue;
F_64 ( & V_49 -> V_93 , & V_94 [ V_50 ] ) ;
}
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( ! ( V_5 -> V_57 & ( 1 << V_50 ) ) )
continue;
F_64 ( & V_49 -> V_93 , & V_95 [ V_50 ] ) ;
}
for ( V_50 = 0 ; V_50 < 6 ; V_50 ++ ) {
if ( ! ( V_5 -> V_58 & ( 1 << V_50 ) ) )
continue;
F_64 ( & V_49 -> V_93 , & V_96 [ V_50 ] ) ;
}
}
static int F_65 ( struct V_76 * V_77 )
{
struct V_86 * V_87 = F_60 ( & V_77 -> V_49 ) ;
struct V_4 * V_5 ;
int V_50 , V_97 , V_98 ;
V_5 = F_66 ( & V_77 -> V_49 , sizeof( struct V_4 ) ,
V_99 ) ;
if ( ! V_5 ) {
F_67 ( L_17 ) ;
return - V_100 ;
}
V_5 -> V_7 [ 0 ] = V_87 -> V_7 [ 0 ] ;
V_5 -> V_7 [ 1 ] = V_87 -> V_7 [ 1 ] ;
V_98 = ( V_5 -> V_7 [ 0 ] != 0 ) + ( V_5 -> V_7 [ 1 ] != 0 ) ;
V_97 = F_54 ( V_77 , V_98 ) ;
if ( V_97 )
return V_97 ;
F_68 ( & V_5 -> V_51 ) ;
V_5 -> V_75 = L_18 ;
F_69 ( V_77 , V_5 ) ;
F_59 ( & V_77 -> V_49 ) ;
V_97 = F_70 ( & V_77 -> V_49 , & V_92 ) ;
if ( V_97 )
return V_97 ;
for ( V_50 = 0 ; V_50 < 8 ; V_50 ++ ) {
if ( ! ( V_5 -> V_56 & ( 1 << V_50 ) ) )
continue;
V_97 = F_71 ( & V_77 -> V_49 . V_93 ,
& V_94 [ V_50 ] ) ;
if ( V_97 )
goto V_101;
}
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( ! ( V_5 -> V_57 & ( 1 << V_50 ) ) )
continue;
V_97 = F_71 ( & V_77 -> V_49 . V_93 ,
& V_95 [ V_50 ] ) ;
if ( V_97 )
goto V_101;
}
for ( V_50 = 0 ; V_50 < 6 ; V_50 ++ ) {
if ( ! ( V_5 -> V_58 & ( 1 << V_50 ) ) )
continue;
V_97 = F_71 ( & V_77 -> V_49 . V_93 ,
& V_96 [ V_50 ] ) ;
if ( V_97 )
goto V_101;
}
V_5 -> V_102 = F_72 ( & V_77 -> V_49 ) ;
if ( F_73 ( V_5 -> V_102 ) ) {
V_97 = F_74 ( V_5 -> V_102 ) ;
F_56 ( & V_77 -> V_49 , L_19 , V_97 ) ;
goto V_101;
}
return 0 ;
V_101:
F_62 ( & V_77 -> V_49 ) ;
return V_97 ;
}
static int F_75 ( struct V_76 * V_77 )
{
struct V_4 * V_5 = F_76 ( V_77 ) ;
F_77 ( V_5 -> V_102 ) ;
F_62 ( & V_77 -> V_49 ) ;
return 0 ;
}
static int T_7 F_78 ( const struct V_86 * V_87 )
{
struct V_78 V_79 [ 2 ] = {
{ . V_103 = V_80 } ,
{ . V_103 = V_80 } ,
} ;
int V_97 , V_50 , V_98 ;
V_98 = 0 ;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
if ( ! V_87 -> V_7 [ V_50 ] )
continue;
V_79 [ V_98 ] . V_82 = V_87 -> V_7 [ V_50 ] ;
V_79 [ V_98 ] . V_84 = V_87 -> V_7 [ V_50 ] + V_104 - 1 ;
V_79 [ V_98 ] . V_75 = V_105 [ V_50 ] ;
V_97 = F_79 ( & V_79 [ V_98 ] ) ;
if ( V_97 )
goto exit;
V_98 ++ ;
}
V_77 = F_80 ( V_83 , V_79 [ 0 ] . V_82 ) ;
if ( ! V_77 ) {
V_97 = - V_100 ;
F_67 ( L_20 ) ;
goto exit;
}
V_97 = F_81 ( V_77 , V_79 , V_98 ) ;
if ( V_97 ) {
F_67 ( L_21 , V_97 ) ;
goto V_106;
}
V_97 = F_82 ( V_77 , V_87 ,
sizeof( struct V_86 ) ) ;
if ( V_97 ) {
F_67 ( L_22 ) ;
goto V_106;
}
V_97 = F_83 ( V_77 ) ;
if ( V_97 ) {
F_67 ( L_23 , V_97 ) ;
goto V_106;
}
return 0 ;
V_106:
F_84 ( V_77 ) ;
exit:
return V_97 ;
}
static int T_7 F_85 ( int V_1 , struct V_86 * V_87 )
{
T_2 V_3 ;
T_1 V_107 , V_108 ;
int V_50 , V_97 = 0 ;
V_3 = V_109 ? V_109 : F_3 ( V_1 , V_110 ) ;
if ( V_3 != 0xf2 ) {
V_97 = - V_111 ;
goto exit;
}
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
V_87 -> V_7 [ V_50 ] = 0 ;
F_1 ( V_1 , V_112 , V_113 [ V_50 ] ) ;
V_3 = F_3 ( V_1 , V_114 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_86 ( L_24 ,
V_113 [ V_50 ] ) ;
continue;
}
V_3 = F_3 ( V_1 , V_115 ) ;
if ( V_3 & 0x01 ) {
F_87 ( L_25 ,
V_113 [ V_50 ] ) ;
continue;
}
V_3 = ( F_3 ( V_1 , V_116 ) << 8 )
| F_3 ( V_1 , V_116 + 1 ) ;
if ( ! V_3 ) {
F_86 ( L_26 ,
V_113 [ V_50 ] ) ;
continue;
}
V_87 -> V_7 [ V_50 ] = V_3 ;
}
if ( ! V_87 -> V_7 [ 0 ] && ! V_87 -> V_7 [ 1 ] ) {
V_97 = - V_111 ;
goto exit;
}
V_87 -> V_88 = ( 1 << 2 ) | ( 1 << 3 ) ;
V_107 = F_3 ( V_1 , V_117 ) ;
if ( ! ( V_107 & ( 1 << 3 ) ) )
V_87 -> V_88 |= ( 1 << 0 ) ;
if ( ! ( V_107 & ( 1 << 2 ) ) )
V_87 -> V_88 |= ( 1 << 4 ) ;
V_107 = F_3 ( V_1 , V_118 ) ;
if ( ! ( V_107 & ( 1 << 0 ) ) )
V_87 -> V_88 |= ( 1 << 1 ) ;
V_107 = F_3 ( V_1 , V_119 ) ;
if ( ! ( V_107 & ( 1 << 0 ) ) )
V_87 -> V_88 |= ( 1 << 7 ) ;
V_108 = F_3 ( V_1 , V_120 ) ;
if ( ! ( V_107 & ( 1 << 1 ) ) && ( V_108 & ( 1 << 3 ) ) )
V_87 -> V_88 |= ( 1 << 5 ) ;
V_107 = F_3 ( V_1 , V_121 ) ;
if ( ( V_107 & ( 1 << 3 ) ) && ! ( V_108 & ( 1 << 5 ) ) )
V_87 -> V_88 |= ( 1 << 6 ) ;
V_87 -> V_89 = ( 1 << 0 ) ;
if ( V_108 & ( 1 << 0 ) )
V_87 -> V_89 |= ( 1 << 3 ) ;
V_107 = F_3 ( V_1 , V_122 ) ;
if ( ! ( V_107 & ( 1 << 4 ) ) ) {
if ( V_108 & ( 1 << 1 ) )
V_87 -> V_89 |= ( 1 << 1 ) ;
if ( V_108 & ( 1 << 2 ) )
V_87 -> V_89 |= ( 1 << 2 ) ;
}
V_107 = F_3 ( V_1 , V_123 ) ;
if ( V_107 & ( 1 << 6 ) )
V_87 -> V_89 |= ( 1 << 1 ) ;
if ( V_107 & ( 1 << 5 ) )
V_87 -> V_89 |= ( 1 << 2 ) ;
exit:
F_5 ( V_1 ) ;
return V_97 ;
}
static int T_7 F_88 ( void )
{
int V_97 ;
struct V_86 V_87 ;
if ( F_85 ( 0x2e , & V_87 )
&& F_85 ( 0x4e , & V_87 ) )
return - V_111 ;
V_97 = F_89 ( & V_124 ) ;
if ( V_97 )
goto exit;
V_97 = F_78 ( & V_87 ) ;
if ( V_97 )
goto V_125;
return 0 ;
V_125:
F_90 ( & V_124 ) ;
exit:
return V_97 ;
}
static void T_8 F_91 ( void )
{
F_92 ( V_77 ) ;
F_90 ( & V_124 ) ;
}
