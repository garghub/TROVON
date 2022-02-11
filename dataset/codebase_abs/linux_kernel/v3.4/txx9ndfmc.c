static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
return V_8 -> V_9 ;
}
static void T_1 * F_2 ( struct V_1 * V_9 , unsigned int V_10 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
return V_12 -> V_16 + ( V_10 << V_14 -> V_17 ) ;
}
static T_2 F_4 ( struct V_1 * V_9 , unsigned int V_10 )
{
return F_5 ( F_2 ( V_9 , V_10 ) ) ;
}
static void F_6 ( struct V_1 * V_9 ,
T_2 V_18 , unsigned int V_10 )
{
F_7 ( V_18 , F_2 ( V_9 , V_10 ) ) ;
}
static T_3 F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_4 ( V_9 , V_19 ) ;
}
static void F_9 ( struct V_2 * V_3 , const T_3 * V_20 ,
int V_21 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
void T_1 * V_22 = F_2 ( V_9 , V_19 ) ;
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
F_6 ( V_9 , V_23 | V_25 , V_24 ) ;
while ( V_21 -- )
F_7 ( * V_20 ++ , V_22 ) ;
F_6 ( V_9 , V_23 , V_24 ) ;
}
static void F_10 ( struct V_2 * V_3 , T_3 * V_20 , int V_21 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
void T_1 * V_22 = F_2 ( V_9 , V_19 ) ;
while ( V_21 -- )
* V_20 ++ = F_5 ( V_22 ) ;
}
static int F_11 ( struct V_2 * V_3 , const T_3 * V_20 ,
int V_21 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
void T_1 * V_22 = F_2 ( V_9 , V_19 ) ;
while ( V_21 -- )
if ( * V_20 ++ != ( T_3 ) F_5 ( V_22 ) )
return - V_26 ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , int V_27 ,
unsigned int V_28 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
struct V_1 * V_9 = V_8 -> V_9 ;
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
if ( V_28 & V_29 ) {
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
V_23 &= ~ ( V_30 | V_31 | V_32 ) ;
V_23 |= V_28 & V_33 ? V_30 : 0 ;
V_23 |= V_28 & V_34 ? V_31 : 0 ;
V_23 |= V_28 & V_35 ? V_32 : 0 ;
if ( V_8 -> V_36 >= 0 && ( V_28 & V_35 ) ) {
V_23 &= ~ V_37 ;
V_23 |= F_13 ( V_8 -> V_36 ) ;
}
F_6 ( V_9 , V_23 , V_24 ) ;
}
if ( V_27 != V_38 )
F_6 ( V_9 , V_27 & 0xff , V_19 ) ;
if ( V_14 -> V_39 & V_40 ) {
if ( ( V_28 & V_29 ) && V_27 == V_38 )
F_6 ( V_9 , 0 , V_19 ) ;
}
F_14 () ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return ! ( F_4 ( V_9 , V_41 ) & V_42 ) ;
}
static int F_16 ( struct V_2 * V_3 , const T_3 * V_43 ,
T_3 * V_44 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_45 ;
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
V_23 &= ~ V_46 ;
F_6 ( V_9 , V_23 | V_47 , V_24 ) ;
F_6 ( V_9 , V_23 | V_48 , V_24 ) ;
for ( V_45 = V_5 -> V_49 . V_50 ; V_45 > 0 ; V_45 -= 3 ) {
V_44 [ 1 ] = F_4 ( V_9 , V_19 ) ;
V_44 [ 0 ] = F_4 ( V_9 , V_19 ) ;
V_44 [ 2 ] = F_4 ( V_9 , V_19 ) ;
V_44 += 3 ;
}
F_6 ( V_9 , V_23 | V_47 , V_24 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , unsigned char * V_20 ,
unsigned char * V_51 , unsigned char * V_52 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_53 ;
int V_54 = 0 ;
int V_55 ;
for ( V_53 = V_5 -> V_49 . V_56 ; V_53 > 0 ; V_53 -= 256 ) {
V_55 = F_18 ( V_20 , V_51 , V_52 , 256 ) ;
if ( V_55 < 0 )
return V_55 ;
V_54 += V_55 ;
V_20 += 256 ;
V_51 += 3 ;
V_52 += 3 ;
}
return V_54 ;
}
static void F_19 ( struct V_2 * V_3 , int V_57 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
V_23 &= ~ V_46 ;
F_6 ( V_9 , V_23 | V_58 , V_24 ) ;
F_6 ( V_9 , V_23 | V_47 , V_24 ) ;
F_6 ( V_9 , V_23 | V_59 , V_24 ) ;
}
static void F_20 ( struct V_1 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_60 = 100 ;
if ( V_14 -> V_39 & V_61 )
;
else {
F_6 ( V_9 ,
F_4 ( V_9 , V_62 ) |
V_63 ,
V_62 ) ;
while ( F_4 ( V_9 , V_62 ) & V_63 ) {
if ( -- V_60 == 0 ) {
F_21 ( & V_9 -> V_9 , L_1 ) ;
break;
}
F_22 ( 1 ) ;
}
}
F_6 ( V_9 , ( V_12 -> V_64 << 4 ) | V_12 -> V_65 , V_66 ) ;
F_6 ( V_9 ,
( V_14 -> V_39 & V_67 ) ?
V_68 : 0 , V_24 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_69 ;
V_69 = F_24 ( V_3 , 1 , NULL ) ;
if ( ! V_69 ) {
if ( V_3 -> V_70 >= 512 ) {
V_5 -> V_49 . V_56 = 512 ;
V_5 -> V_49 . V_50 = 6 ;
}
V_69 = F_25 ( V_3 ) ;
}
return V_69 ;
}
static int T_4 F_26 ( struct V_1 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
int V_64 , V_65 ;
int V_71 ;
struct V_11 * V_12 ;
unsigned long V_72 = V_14 -> V_73 ;
struct V_74 * V_75 ;
V_75 = F_27 ( V_9 , V_76 , 0 ) ;
if ( ! V_75 )
return - V_77 ;
V_12 = F_28 ( & V_9 -> V_9 , sizeof( * V_12 ) , V_78 ) ;
if ( ! V_12 )
return - V_79 ;
V_12 -> V_16 = F_29 ( & V_9 -> V_9 , V_75 ) ;
if ( ! V_12 -> V_16 )
return - V_80 ;
V_64 = V_14 -> V_64 ? : 20 ;
V_65 = V_14 -> V_65 ? : 90 ;
V_64 = F_30 ( V_72 , V_64 ) ;
V_65 = F_30 ( V_72 , V_65 ) ;
if ( V_14 -> V_39 & V_81 )
V_64 -= 2 ;
V_65 -= 1 ;
V_64 = F_31 ( V_64 , 1 , 15 ) ;
V_12 -> V_64 = V_64 ;
V_65 = F_31 ( V_65 , 1 , 15 ) ;
V_12 -> V_65 = V_65 ;
F_32 ( & V_9 -> V_9 , L_2 ,
( V_72 + 500000 ) / 1000000 , V_64 , V_65 ) ;
F_33 ( & V_12 -> V_82 . V_83 ) ;
F_34 ( & V_12 -> V_82 . V_84 ) ;
F_35 ( V_9 , V_12 ) ;
F_20 ( V_9 ) ;
for ( V_71 = 0 ; V_71 < V_85 ; V_71 ++ ) {
struct V_7 * V_8 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
if ( ! ( V_14 -> V_86 & ( 1 << V_71 ) ) )
continue;
V_8 = F_36 ( sizeof( struct V_7 ) ,
V_78 ) ;
if ( ! V_8 ) {
F_21 ( & V_9 -> V_9 , L_3
L_4 ) ;
continue;
}
V_5 = & V_8 -> V_5 ;
V_3 = & V_8 -> V_3 ;
V_3 -> V_87 = V_88 ;
V_3 -> V_6 = V_5 ;
V_5 -> V_89 = F_8 ;
V_5 -> V_90 = F_10 ;
V_5 -> V_91 = F_9 ;
V_5 -> V_92 = F_11 ;
V_5 -> V_93 = F_12 ;
V_5 -> V_94 = F_15 ;
V_5 -> V_49 . V_95 = F_16 ;
V_5 -> V_49 . V_96 = F_17 ;
V_5 -> V_49 . V_97 = F_19 ;
V_5 -> V_49 . V_57 = V_98 ;
V_5 -> V_49 . V_56 = 256 ;
V_5 -> V_49 . V_50 = 3 ;
V_5 -> V_49 . V_99 = 1 ;
V_5 -> V_100 = 100 ;
V_5 -> V_101 = & V_12 -> V_82 ;
V_5 -> V_6 = V_8 ;
V_8 -> V_9 = V_9 ;
if ( V_14 -> V_86 != 1 ) {
V_8 -> V_36 = V_71 ;
V_8 -> V_102 = F_37 ( V_78 , L_5 ,
F_38 ( & V_9 -> V_9 ) , V_71 ) ;
} else {
V_8 -> V_36 = - 1 ;
V_8 -> V_102 = F_39 ( F_38 ( & V_9 -> V_9 ) ,
V_78 ) ;
}
if ( ! V_8 -> V_102 ) {
F_40 ( V_8 ) ;
F_21 ( & V_9 -> V_9 , L_6 ) ;
continue;
}
if ( V_14 -> V_103 & ( 1 << V_71 ) )
V_5 -> V_104 |= V_105 ;
if ( F_23 ( V_3 ) ) {
F_40 ( V_8 -> V_102 ) ;
F_40 ( V_8 ) ;
continue;
}
V_3 -> V_106 = V_8 -> V_102 ;
F_41 ( V_3 , NULL , NULL , NULL , 0 ) ;
V_12 -> V_107 [ V_71 ] = V_3 ;
}
return 0 ;
}
static int T_5 F_42 ( struct V_1 * V_9 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_71 ;
F_35 ( V_9 , NULL ) ;
if ( ! V_12 )
return 0 ;
for ( V_71 = 0 ; V_71 < V_85 ; V_71 ++ ) {
struct V_2 * V_3 = V_12 -> V_107 [ V_71 ] ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
if ( ! V_3 )
continue;
V_5 = V_3 -> V_6 ;
V_8 = V_5 -> V_6 ;
F_43 ( V_3 ) ;
F_40 ( V_8 -> V_102 ) ;
F_40 ( V_8 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_9 )
{
if ( F_3 ( V_9 ) )
F_20 ( V_9 ) ;
return 0 ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_108 , F_26 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_108 ) ;
}
