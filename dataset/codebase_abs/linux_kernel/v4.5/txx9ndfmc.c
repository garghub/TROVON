static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
return V_7 -> V_8 ;
}
static void T_1 * F_4 ( struct V_1 * V_8 , unsigned int V_9 )
{
struct V_10 * V_11 = F_5 ( V_8 ) ;
struct V_12 * V_13 = F_6 ( & V_8 -> V_8 ) ;
return V_11 -> V_14 + ( V_9 << V_13 -> V_15 ) ;
}
static T_2 F_7 ( struct V_1 * V_8 , unsigned int V_9 )
{
return F_8 ( F_4 ( V_8 , V_9 ) ) ;
}
static void F_9 ( struct V_1 * V_8 ,
T_2 V_16 , unsigned int V_9 )
{
F_10 ( V_16 , F_4 ( V_8 , V_9 ) ) ;
}
static T_3 F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_7 ( V_8 , V_17 ) ;
}
static void F_12 ( struct V_2 * V_3 , const T_3 * V_18 ,
int V_19 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
void T_1 * V_20 = F_4 ( V_8 , V_17 ) ;
T_2 V_21 = F_7 ( V_8 , V_22 ) ;
F_9 ( V_8 , V_21 | V_23 , V_22 ) ;
while ( V_19 -- )
F_10 ( * V_18 ++ , V_20 ) ;
F_9 ( V_8 , V_21 , V_22 ) ;
}
static void F_13 ( struct V_2 * V_3 , T_3 * V_18 , int V_19 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
void T_1 * V_20 = F_4 ( V_8 , V_17 ) ;
while ( V_19 -- )
* V_18 ++ = F_8 ( V_20 ) ;
}
static void F_14 ( struct V_2 * V_3 , int V_24 ,
unsigned int V_25 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_1 * V_8 = V_7 -> V_8 ;
struct V_12 * V_13 = F_6 ( & V_8 -> V_8 ) ;
if ( V_25 & V_26 ) {
T_2 V_21 = F_7 ( V_8 , V_22 ) ;
V_21 &= ~ ( V_27 | V_28 | V_29 ) ;
V_21 |= V_25 & V_30 ? V_27 : 0 ;
V_21 |= V_25 & V_31 ? V_28 : 0 ;
V_21 |= V_25 & V_32 ? V_29 : 0 ;
if ( V_7 -> V_33 >= 0 && ( V_25 & V_32 ) ) {
V_21 &= ~ V_34 ;
V_21 |= F_15 ( V_7 -> V_33 ) ;
}
F_9 ( V_8 , V_21 , V_22 ) ;
}
if ( V_24 != V_35 )
F_9 ( V_8 , V_24 & 0xff , V_17 ) ;
if ( V_13 -> V_36 & V_37 ) {
if ( ( V_25 & V_26 ) && V_24 == V_35 )
F_9 ( V_8 , 0 , V_17 ) ;
}
F_16 () ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return ! ( F_7 ( V_8 , V_38 ) & V_39 ) ;
}
static int F_18 ( struct V_2 * V_3 , const T_3 * V_40 ,
T_3 * V_41 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_42 ;
T_2 V_21 = F_7 ( V_8 , V_22 ) ;
V_21 &= ~ V_43 ;
F_9 ( V_8 , V_21 | V_44 , V_22 ) ;
F_9 ( V_8 , V_21 | V_45 , V_22 ) ;
for ( V_42 = V_5 -> V_46 . V_47 ; V_42 > 0 ; V_42 -= 3 ) {
V_41 [ 1 ] = F_7 ( V_8 , V_17 ) ;
V_41 [ 0 ] = F_7 ( V_8 , V_17 ) ;
V_41 [ 2 ] = F_7 ( V_8 , V_17 ) ;
V_41 += 3 ;
}
F_9 ( V_8 , V_21 | V_44 , V_22 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , unsigned char * V_18 ,
unsigned char * V_48 , unsigned char * V_49 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_50 ;
int V_51 = 0 ;
int V_52 ;
for ( V_50 = V_5 -> V_46 . V_53 ; V_50 > 0 ; V_50 -= 256 ) {
V_52 = F_20 ( V_18 , V_48 , V_49 , 256 ) ;
if ( V_52 < 0 )
return V_52 ;
V_51 += V_52 ;
V_18 += 256 ;
V_48 += 3 ;
V_49 += 3 ;
}
return V_51 ;
}
static void F_21 ( struct V_2 * V_3 , int V_54 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_2 V_21 = F_7 ( V_8 , V_22 ) ;
V_21 &= ~ V_43 ;
F_9 ( V_8 , V_21 | V_55 , V_22 ) ;
F_9 ( V_8 , V_21 | V_44 , V_22 ) ;
F_9 ( V_8 , V_21 | V_56 , V_22 ) ;
}
static void F_22 ( struct V_1 * V_8 )
{
struct V_12 * V_13 = F_6 ( & V_8 -> V_8 ) ;
struct V_10 * V_11 = F_5 ( V_8 ) ;
int V_57 = 100 ;
if ( V_13 -> V_36 & V_58 )
;
else {
F_9 ( V_8 ,
F_7 ( V_8 , V_59 ) |
V_60 ,
V_59 ) ;
while ( F_7 ( V_8 , V_59 ) & V_60 ) {
if ( -- V_57 == 0 ) {
F_23 ( & V_8 -> V_8 , L_1 ) ;
break;
}
F_24 ( 1 ) ;
}
}
F_9 ( V_8 , ( V_11 -> V_61 << 4 ) | V_11 -> V_62 , V_63 ) ;
F_9 ( V_8 ,
( V_13 -> V_36 & V_64 ) ?
V_65 : 0 , V_22 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_66 ;
V_66 = F_26 ( V_3 , 1 , NULL ) ;
if ( ! V_66 ) {
if ( V_3 -> V_67 >= 512 ) {
V_5 -> V_46 . V_53 = 512 ;
V_5 -> V_46 . V_47 = 6 ;
}
V_66 = F_27 ( V_3 ) ;
}
return V_66 ;
}
static int T_4 F_28 ( struct V_1 * V_8 )
{
struct V_12 * V_13 = F_6 ( & V_8 -> V_8 ) ;
int V_61 , V_62 ;
int V_68 ;
struct V_10 * V_11 ;
unsigned long V_69 = V_13 -> V_70 ;
struct V_71 * V_72 ;
V_11 = F_29 ( & V_8 -> V_8 , sizeof( * V_11 ) , V_73 ) ;
if ( ! V_11 )
return - V_74 ;
V_72 = F_30 ( V_8 , V_75 , 0 ) ;
V_11 -> V_14 = F_31 ( & V_8 -> V_8 , V_72 ) ;
if ( F_32 ( V_11 -> V_14 ) )
return F_33 ( V_11 -> V_14 ) ;
V_61 = V_13 -> V_61 ? : 20 ;
V_62 = V_13 -> V_62 ? : 90 ;
V_61 = F_34 ( V_69 , V_61 ) ;
V_62 = F_34 ( V_69 , V_62 ) ;
if ( V_13 -> V_36 & V_76 )
V_61 -= 2 ;
V_62 -= 1 ;
V_61 = F_35 ( V_61 , 1 , 15 ) ;
V_11 -> V_61 = V_61 ;
V_62 = F_35 ( V_62 , 1 , 15 ) ;
V_11 -> V_62 = V_62 ;
F_36 ( & V_8 -> V_8 , L_2 ,
( V_69 + 500000 ) / 1000000 , V_61 , V_62 ) ;
F_37 ( & V_11 -> V_77 . V_78 ) ;
F_38 ( & V_11 -> V_77 . V_79 ) ;
F_39 ( V_8 , V_11 ) ;
F_22 ( V_8 ) ;
for ( V_68 = 0 ; V_68 < V_80 ; V_68 ++ ) {
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
if ( ! ( V_13 -> V_81 & ( 1 << V_68 ) ) )
continue;
V_7 = F_40 ( sizeof( struct V_6 ) ,
V_73 ) ;
if ( ! V_7 )
continue;
V_5 = & V_7 -> V_5 ;
V_3 = F_41 ( V_5 ) ;
V_3 -> V_8 . V_82 = & V_8 -> V_8 ;
V_5 -> V_83 = F_11 ;
V_5 -> V_84 = F_13 ;
V_5 -> V_85 = F_12 ;
V_5 -> V_86 = F_14 ;
V_5 -> V_87 = F_17 ;
V_5 -> V_46 . V_88 = F_18 ;
V_5 -> V_46 . V_89 = F_19 ;
V_5 -> V_46 . V_90 = F_21 ;
V_5 -> V_46 . V_54 = V_91 ;
V_5 -> V_46 . V_53 = 256 ;
V_5 -> V_46 . V_47 = 3 ;
V_5 -> V_46 . V_92 = 1 ;
V_5 -> V_93 = 100 ;
V_5 -> V_94 = & V_11 -> V_77 ;
F_42 ( V_5 , V_7 ) ;
V_7 -> V_8 = V_8 ;
if ( V_13 -> V_81 != 1 ) {
V_7 -> V_33 = V_68 ;
V_7 -> V_95 = F_43 ( V_73 , L_3 ,
F_44 ( & V_8 -> V_8 ) , V_68 ) ;
} else {
V_7 -> V_33 = - 1 ;
V_7 -> V_95 = F_45 ( F_44 ( & V_8 -> V_8 ) ,
V_73 ) ;
}
if ( ! V_7 -> V_95 ) {
F_46 ( V_7 ) ;
F_23 ( & V_8 -> V_8 , L_4 ) ;
continue;
}
if ( V_13 -> V_96 & ( 1 << V_68 ) )
V_5 -> V_97 |= V_98 ;
if ( F_25 ( V_3 ) ) {
F_46 ( V_7 -> V_95 ) ;
F_46 ( V_7 ) ;
continue;
}
V_3 -> V_99 = V_7 -> V_95 ;
F_47 ( V_3 , NULL , NULL , NULL , 0 ) ;
V_11 -> V_100 [ V_68 ] = V_3 ;
}
return 0 ;
}
static int T_5 F_48 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = F_5 ( V_8 ) ;
int V_68 ;
if ( ! V_11 )
return 0 ;
for ( V_68 = 0 ; V_68 < V_80 ; V_68 ++ ) {
struct V_2 * V_3 = V_11 -> V_100 [ V_68 ] ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( ! V_3 )
continue;
V_5 = F_2 ( V_3 ) ;
V_7 = F_3 ( V_5 ) ;
F_49 ( V_3 ) ;
F_46 ( V_7 -> V_95 ) ;
F_46 ( V_7 ) ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_8 )
{
if ( F_5 ( V_8 ) )
F_22 ( V_8 ) ;
return 0 ;
}
