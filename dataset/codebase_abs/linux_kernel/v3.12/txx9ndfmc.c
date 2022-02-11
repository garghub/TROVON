static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
return V_8 -> V_9 ;
}
static void T_1 * F_2 ( struct V_1 * V_9 , unsigned int V_10 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_13 * V_14 = F_4 ( & V_9 -> V_9 ) ;
return V_12 -> V_15 + ( V_10 << V_14 -> V_16 ) ;
}
static T_2 F_5 ( struct V_1 * V_9 , unsigned int V_10 )
{
return F_6 ( F_2 ( V_9 , V_10 ) ) ;
}
static void F_7 ( struct V_1 * V_9 ,
T_2 V_17 , unsigned int V_10 )
{
F_8 ( V_17 , F_2 ( V_9 , V_10 ) ) ;
}
static T_3 F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_5 ( V_9 , V_18 ) ;
}
static void F_10 ( struct V_2 * V_3 , const T_3 * V_19 ,
int V_20 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
void T_1 * V_21 = F_2 ( V_9 , V_18 ) ;
T_2 V_22 = F_5 ( V_9 , V_23 ) ;
F_7 ( V_9 , V_22 | V_24 , V_23 ) ;
while ( V_20 -- )
F_8 ( * V_19 ++ , V_21 ) ;
F_7 ( V_9 , V_22 , V_23 ) ;
}
static void F_11 ( struct V_2 * V_3 , T_3 * V_19 , int V_20 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
void T_1 * V_21 = F_2 ( V_9 , V_18 ) ;
while ( V_20 -- )
* V_19 ++ = F_6 ( V_21 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_25 ,
unsigned int V_26 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
struct V_1 * V_9 = V_8 -> V_9 ;
struct V_13 * V_14 = F_4 ( & V_9 -> V_9 ) ;
if ( V_26 & V_27 ) {
T_2 V_22 = F_5 ( V_9 , V_23 ) ;
V_22 &= ~ ( V_28 | V_29 | V_30 ) ;
V_22 |= V_26 & V_31 ? V_28 : 0 ;
V_22 |= V_26 & V_32 ? V_29 : 0 ;
V_22 |= V_26 & V_33 ? V_30 : 0 ;
if ( V_8 -> V_34 >= 0 && ( V_26 & V_33 ) ) {
V_22 &= ~ V_35 ;
V_22 |= F_13 ( V_8 -> V_34 ) ;
}
F_7 ( V_9 , V_22 , V_23 ) ;
}
if ( V_25 != V_36 )
F_7 ( V_9 , V_25 & 0xff , V_18 ) ;
if ( V_14 -> V_37 & V_38 ) {
if ( ( V_26 & V_27 ) && V_25 == V_36 )
F_7 ( V_9 , 0 , V_18 ) ;
}
F_14 () ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return ! ( F_5 ( V_9 , V_39 ) & V_40 ) ;
}
static int F_16 ( struct V_2 * V_3 , const T_3 * V_41 ,
T_3 * V_42 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_43 ;
T_2 V_22 = F_5 ( V_9 , V_23 ) ;
V_22 &= ~ V_44 ;
F_7 ( V_9 , V_22 | V_45 , V_23 ) ;
F_7 ( V_9 , V_22 | V_46 , V_23 ) ;
for ( V_43 = V_5 -> V_47 . V_48 ; V_43 > 0 ; V_43 -= 3 ) {
V_42 [ 1 ] = F_5 ( V_9 , V_18 ) ;
V_42 [ 0 ] = F_5 ( V_9 , V_18 ) ;
V_42 [ 2 ] = F_5 ( V_9 , V_18 ) ;
V_42 += 3 ;
}
F_7 ( V_9 , V_22 | V_45 , V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , unsigned char * V_19 ,
unsigned char * V_49 , unsigned char * V_50 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_51 ;
int V_52 = 0 ;
int V_53 ;
for ( V_51 = V_5 -> V_47 . V_54 ; V_51 > 0 ; V_51 -= 256 ) {
V_53 = F_18 ( V_19 , V_49 , V_50 , 256 ) ;
if ( V_53 < 0 )
return V_53 ;
V_52 += V_53 ;
V_19 += 256 ;
V_49 += 3 ;
V_50 += 3 ;
}
return V_52 ;
}
static void F_19 ( struct V_2 * V_3 , int V_55 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_2 V_22 = F_5 ( V_9 , V_23 ) ;
V_22 &= ~ V_44 ;
F_7 ( V_9 , V_22 | V_56 , V_23 ) ;
F_7 ( V_9 , V_22 | V_45 , V_23 ) ;
F_7 ( V_9 , V_22 | V_57 , V_23 ) ;
}
static void F_20 ( struct V_1 * V_9 )
{
struct V_13 * V_14 = F_4 ( & V_9 -> V_9 ) ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_58 = 100 ;
if ( V_14 -> V_37 & V_59 )
;
else {
F_7 ( V_9 ,
F_5 ( V_9 , V_60 ) |
V_61 ,
V_60 ) ;
while ( F_5 ( V_9 , V_60 ) & V_61 ) {
if ( -- V_58 == 0 ) {
F_21 ( & V_9 -> V_9 , L_1 ) ;
break;
}
F_22 ( 1 ) ;
}
}
F_7 ( V_9 , ( V_12 -> V_62 << 4 ) | V_12 -> V_63 , V_64 ) ;
F_7 ( V_9 ,
( V_14 -> V_37 & V_65 ) ?
V_66 : 0 , V_23 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_67 ;
V_67 = F_24 ( V_3 , 1 , NULL ) ;
if ( ! V_67 ) {
if ( V_3 -> V_68 >= 512 ) {
V_5 -> V_47 . V_54 = 512 ;
V_5 -> V_47 . V_48 = 6 ;
}
V_67 = F_25 ( V_3 ) ;
}
return V_67 ;
}
static int T_4 F_26 ( struct V_1 * V_9 )
{
struct V_13 * V_14 = F_4 ( & V_9 -> V_9 ) ;
int V_62 , V_63 ;
int V_69 ;
struct V_11 * V_12 ;
unsigned long V_70 = V_14 -> V_71 ;
struct V_72 * V_73 ;
V_12 = F_27 ( & V_9 -> V_9 , sizeof( * V_12 ) , V_74 ) ;
if ( ! V_12 )
return - V_75 ;
V_73 = F_28 ( V_9 , V_76 , 0 ) ;
V_12 -> V_15 = F_29 ( & V_9 -> V_9 , V_73 ) ;
if ( F_30 ( V_12 -> V_15 ) )
return F_31 ( V_12 -> V_15 ) ;
V_62 = V_14 -> V_62 ? : 20 ;
V_63 = V_14 -> V_63 ? : 90 ;
V_62 = F_32 ( V_70 , V_62 ) ;
V_63 = F_32 ( V_70 , V_63 ) ;
if ( V_14 -> V_37 & V_77 )
V_62 -= 2 ;
V_63 -= 1 ;
V_62 = F_33 ( V_62 , 1 , 15 ) ;
V_12 -> V_62 = V_62 ;
V_63 = F_33 ( V_63 , 1 , 15 ) ;
V_12 -> V_63 = V_63 ;
F_34 ( & V_9 -> V_9 , L_2 ,
( V_70 + 500000 ) / 1000000 , V_62 , V_63 ) ;
F_35 ( & V_12 -> V_78 . V_79 ) ;
F_36 ( & V_12 -> V_78 . V_80 ) ;
F_37 ( V_9 , V_12 ) ;
F_20 ( V_9 ) ;
for ( V_69 = 0 ; V_69 < V_81 ; V_69 ++ ) {
struct V_7 * V_8 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
if ( ! ( V_14 -> V_82 & ( 1 << V_69 ) ) )
continue;
V_8 = F_38 ( sizeof( struct V_7 ) ,
V_74 ) ;
if ( ! V_8 ) {
F_21 ( & V_9 -> V_9 , L_3
L_4 ) ;
continue;
}
V_5 = & V_8 -> V_5 ;
V_3 = & V_8 -> V_3 ;
V_3 -> V_83 = V_84 ;
V_3 -> V_6 = V_5 ;
V_5 -> V_85 = F_9 ;
V_5 -> V_86 = F_11 ;
V_5 -> V_87 = F_10 ;
V_5 -> V_88 = F_12 ;
V_5 -> V_89 = F_15 ;
V_5 -> V_47 . V_90 = F_16 ;
V_5 -> V_47 . V_91 = F_17 ;
V_5 -> V_47 . V_92 = F_19 ;
V_5 -> V_47 . V_55 = V_93 ;
V_5 -> V_47 . V_54 = 256 ;
V_5 -> V_47 . V_48 = 3 ;
V_5 -> V_47 . V_94 = 1 ;
V_5 -> V_95 = 100 ;
V_5 -> V_96 = & V_12 -> V_78 ;
V_5 -> V_6 = V_8 ;
V_8 -> V_9 = V_9 ;
if ( V_14 -> V_82 != 1 ) {
V_8 -> V_34 = V_69 ;
V_8 -> V_97 = F_39 ( V_74 , L_5 ,
F_40 ( & V_9 -> V_9 ) , V_69 ) ;
} else {
V_8 -> V_34 = - 1 ;
V_8 -> V_97 = F_41 ( F_40 ( & V_9 -> V_9 ) ,
V_74 ) ;
}
if ( ! V_8 -> V_97 ) {
F_42 ( V_8 ) ;
F_21 ( & V_9 -> V_9 , L_6 ) ;
continue;
}
if ( V_14 -> V_98 & ( 1 << V_69 ) )
V_5 -> V_99 |= V_100 ;
if ( F_23 ( V_3 ) ) {
F_42 ( V_8 -> V_97 ) ;
F_42 ( V_8 ) ;
continue;
}
V_3 -> V_101 = V_8 -> V_97 ;
F_43 ( V_3 , NULL , NULL , NULL , 0 ) ;
V_12 -> V_102 [ V_69 ] = V_3 ;
}
return 0 ;
}
static int T_5 F_44 ( struct V_1 * V_9 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_69 ;
if ( ! V_12 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_81 ; V_69 ++ ) {
struct V_2 * V_3 = V_12 -> V_102 [ V_69 ] ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
if ( ! V_3 )
continue;
V_5 = V_3 -> V_6 ;
V_8 = V_5 -> V_6 ;
F_45 ( V_3 ) ;
F_42 ( V_8 -> V_97 ) ;
F_42 ( V_8 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_9 )
{
if ( F_3 ( V_9 ) )
F_20 ( V_9 ) ;
return 0 ;
}
