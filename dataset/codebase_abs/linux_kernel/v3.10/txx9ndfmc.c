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
static void F_11 ( struct V_2 * V_3 , int V_26 ,
unsigned int V_27 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_6 ;
struct V_1 * V_9 = V_8 -> V_9 ;
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
if ( V_27 & V_28 ) {
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
V_23 &= ~ ( V_29 | V_30 | V_31 ) ;
V_23 |= V_27 & V_32 ? V_29 : 0 ;
V_23 |= V_27 & V_33 ? V_30 : 0 ;
V_23 |= V_27 & V_34 ? V_31 : 0 ;
if ( V_8 -> V_35 >= 0 && ( V_27 & V_34 ) ) {
V_23 &= ~ V_36 ;
V_23 |= F_12 ( V_8 -> V_35 ) ;
}
F_6 ( V_9 , V_23 , V_24 ) ;
}
if ( V_26 != V_37 )
F_6 ( V_9 , V_26 & 0xff , V_19 ) ;
if ( V_14 -> V_38 & V_39 ) {
if ( ( V_27 & V_28 ) && V_26 == V_37 )
F_6 ( V_9 , 0 , V_19 ) ;
}
F_13 () ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return ! ( F_4 ( V_9 , V_40 ) & V_41 ) ;
}
static int F_15 ( struct V_2 * V_3 , const T_3 * V_42 ,
T_3 * V_43 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_44 ;
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
V_23 &= ~ V_45 ;
F_6 ( V_9 , V_23 | V_46 , V_24 ) ;
F_6 ( V_9 , V_23 | V_47 , V_24 ) ;
for ( V_44 = V_5 -> V_48 . V_49 ; V_44 > 0 ; V_44 -= 3 ) {
V_43 [ 1 ] = F_4 ( V_9 , V_19 ) ;
V_43 [ 0 ] = F_4 ( V_9 , V_19 ) ;
V_43 [ 2 ] = F_4 ( V_9 , V_19 ) ;
V_43 += 3 ;
}
F_6 ( V_9 , V_23 | V_46 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned char * V_20 ,
unsigned char * V_50 , unsigned char * V_51 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_52 ;
int V_53 = 0 ;
int V_54 ;
for ( V_52 = V_5 -> V_48 . V_55 ; V_52 > 0 ; V_52 -= 256 ) {
V_54 = F_17 ( V_20 , V_50 , V_51 , 256 ) ;
if ( V_54 < 0 )
return V_54 ;
V_53 += V_54 ;
V_20 += 256 ;
V_50 += 3 ;
V_51 += 3 ;
}
return V_53 ;
}
static void F_18 ( struct V_2 * V_3 , int V_56 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_2 V_23 = F_4 ( V_9 , V_24 ) ;
V_23 &= ~ V_45 ;
F_6 ( V_9 , V_23 | V_57 , V_24 ) ;
F_6 ( V_9 , V_23 | V_46 , V_24 ) ;
F_6 ( V_9 , V_23 | V_58 , V_24 ) ;
}
static void F_19 ( struct V_1 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_59 = 100 ;
if ( V_14 -> V_38 & V_60 )
;
else {
F_6 ( V_9 ,
F_4 ( V_9 , V_61 ) |
V_62 ,
V_61 ) ;
while ( F_4 ( V_9 , V_61 ) & V_62 ) {
if ( -- V_59 == 0 ) {
F_20 ( & V_9 -> V_9 , L_1 ) ;
break;
}
F_21 ( 1 ) ;
}
}
F_6 ( V_9 , ( V_12 -> V_63 << 4 ) | V_12 -> V_64 , V_65 ) ;
F_6 ( V_9 ,
( V_14 -> V_38 & V_66 ) ?
V_67 : 0 , V_24 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
int V_68 ;
V_68 = F_23 ( V_3 , 1 , NULL ) ;
if ( ! V_68 ) {
if ( V_3 -> V_69 >= 512 ) {
V_5 -> V_48 . V_55 = 512 ;
V_5 -> V_48 . V_49 = 6 ;
}
V_68 = F_24 ( V_3 ) ;
}
return V_68 ;
}
static int T_4 F_25 ( struct V_1 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_9 . V_15 ;
int V_63 , V_64 ;
int V_70 ;
struct V_11 * V_12 ;
unsigned long V_71 = V_14 -> V_72 ;
struct V_73 * V_74 ;
V_74 = F_26 ( V_9 , V_75 , 0 ) ;
if ( ! V_74 )
return - V_76 ;
V_12 = F_27 ( & V_9 -> V_9 , sizeof( * V_12 ) , V_77 ) ;
if ( ! V_12 )
return - V_78 ;
V_12 -> V_16 = F_28 ( & V_9 -> V_9 , V_74 ) ;
if ( F_29 ( V_12 -> V_16 ) )
return F_30 ( V_12 -> V_16 ) ;
V_63 = V_14 -> V_63 ? : 20 ;
V_64 = V_14 -> V_64 ? : 90 ;
V_63 = F_31 ( V_71 , V_63 ) ;
V_64 = F_31 ( V_71 , V_64 ) ;
if ( V_14 -> V_38 & V_79 )
V_63 -= 2 ;
V_64 -= 1 ;
V_63 = F_32 ( V_63 , 1 , 15 ) ;
V_12 -> V_63 = V_63 ;
V_64 = F_32 ( V_64 , 1 , 15 ) ;
V_12 -> V_64 = V_64 ;
F_33 ( & V_9 -> V_9 , L_2 ,
( V_71 + 500000 ) / 1000000 , V_63 , V_64 ) ;
F_34 ( & V_12 -> V_80 . V_81 ) ;
F_35 ( & V_12 -> V_80 . V_82 ) ;
F_36 ( V_9 , V_12 ) ;
F_19 ( V_9 ) ;
for ( V_70 = 0 ; V_70 < V_83 ; V_70 ++ ) {
struct V_7 * V_8 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
if ( ! ( V_14 -> V_84 & ( 1 << V_70 ) ) )
continue;
V_8 = F_37 ( sizeof( struct V_7 ) ,
V_77 ) ;
if ( ! V_8 ) {
F_20 ( & V_9 -> V_9 , L_3
L_4 ) ;
continue;
}
V_5 = & V_8 -> V_5 ;
V_3 = & V_8 -> V_3 ;
V_3 -> V_85 = V_86 ;
V_3 -> V_6 = V_5 ;
V_5 -> V_87 = F_8 ;
V_5 -> V_88 = F_10 ;
V_5 -> V_89 = F_9 ;
V_5 -> V_90 = F_11 ;
V_5 -> V_91 = F_14 ;
V_5 -> V_48 . V_92 = F_15 ;
V_5 -> V_48 . V_93 = F_16 ;
V_5 -> V_48 . V_94 = F_18 ;
V_5 -> V_48 . V_56 = V_95 ;
V_5 -> V_48 . V_55 = 256 ;
V_5 -> V_48 . V_49 = 3 ;
V_5 -> V_48 . V_96 = 1 ;
V_5 -> V_97 = 100 ;
V_5 -> V_98 = & V_12 -> V_80 ;
V_5 -> V_6 = V_8 ;
V_8 -> V_9 = V_9 ;
if ( V_14 -> V_84 != 1 ) {
V_8 -> V_35 = V_70 ;
V_8 -> V_99 = F_38 ( V_77 , L_5 ,
F_39 ( & V_9 -> V_9 ) , V_70 ) ;
} else {
V_8 -> V_35 = - 1 ;
V_8 -> V_99 = F_40 ( F_39 ( & V_9 -> V_9 ) ,
V_77 ) ;
}
if ( ! V_8 -> V_99 ) {
F_41 ( V_8 ) ;
F_20 ( & V_9 -> V_9 , L_6 ) ;
continue;
}
if ( V_14 -> V_100 & ( 1 << V_70 ) )
V_5 -> V_101 |= V_102 ;
if ( F_22 ( V_3 ) ) {
F_41 ( V_8 -> V_99 ) ;
F_41 ( V_8 ) ;
continue;
}
V_3 -> V_103 = V_8 -> V_99 ;
F_42 ( V_3 , NULL , NULL , NULL , 0 ) ;
V_12 -> V_104 [ V_70 ] = V_3 ;
}
return 0 ;
}
static int T_5 F_43 ( struct V_1 * V_9 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_70 ;
F_36 ( V_9 , NULL ) ;
if ( ! V_12 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_83 ; V_70 ++ ) {
struct V_2 * V_3 = V_12 -> V_104 [ V_70 ] ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
if ( ! V_3 )
continue;
V_5 = V_3 -> V_6 ;
V_8 = V_5 -> V_6 ;
F_44 ( V_3 ) ;
F_41 ( V_8 -> V_99 ) ;
F_41 ( V_8 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_9 )
{
if ( F_3 ( V_9 ) )
F_19 ( V_9 ) ;
return 0 ;
}
