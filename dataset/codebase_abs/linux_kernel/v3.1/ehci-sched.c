static union V_1 *
F_1 ( struct V_2 * V_3 , union V_1 * V_4 ,
T_1 V_5 )
{
switch ( F_2 ( V_3 , V_5 ) ) {
case V_6 :
return & V_4 -> V_7 -> V_8 ;
case V_9 :
return & V_4 -> V_10 -> V_11 ;
case V_12 :
return & V_4 -> V_13 -> V_14 ;
default:
return & V_4 -> V_15 -> V_16 ;
}
}
static T_1 *
F_3 ( struct V_2 * V_3 , union V_1 * V_4 ,
T_1 V_5 )
{
switch ( F_2 ( V_3 , V_5 ) ) {
case V_6 :
return & V_4 -> V_7 -> V_17 -> V_18 ;
default:
return V_4 -> V_18 ;
}
}
static void F_4 ( struct V_2 * V_3 , unsigned V_19 , void * V_20 )
{
union V_1 * V_21 = & V_3 -> V_22 [ V_19 ] ;
T_1 * V_23 = & V_3 -> V_4 [ V_19 ] ;
union V_1 V_24 = * V_21 ;
while ( V_24 . V_20 && V_24 . V_20 != V_20 ) {
V_21 = F_1 ( V_3 , V_21 ,
F_5 ( V_3 , * V_23 ) ) ;
V_23 = F_3 ( V_3 , & V_24 ,
F_5 ( V_3 , * V_23 ) ) ;
V_24 = * V_21 ;
}
if ( ! V_24 . V_20 )
return;
* V_21 = * F_1 ( V_3 , & V_24 ,
F_5 ( V_3 , * V_23 ) ) ;
if ( ! V_3 -> V_25 ||
* F_3 ( V_3 , & V_24 , F_5 ( V_3 , * V_23 ) )
!= F_6 ( V_3 ) )
* V_23 = * F_3 ( V_3 , & V_24 ,
F_5 ( V_3 , * V_23 ) ) ;
else
* V_23 = V_3 -> V_26 -> V_27 ;
}
static unsigned short
F_7 ( struct V_2 * V_3 , unsigned V_19 , unsigned V_28 )
{
T_1 * V_23 = & V_3 -> V_4 [ V_19 ] ;
union V_1 * V_29 = & V_3 -> V_22 [ V_19 ] ;
unsigned V_30 = 0 ;
struct V_31 * V_17 ;
while ( V_29 -> V_20 ) {
switch ( F_2 ( V_3 , F_5 ( V_3 , * V_23 ) ) ) {
case V_6 :
V_17 = V_29 -> V_7 -> V_17 ;
if ( V_17 -> V_32 & F_8 ( V_3 , 1 << V_28 ) )
V_30 += V_29 -> V_7 -> V_30 ;
if ( V_17 -> V_32 & F_8 ( V_3 ,
1 << ( 8 + V_28 ) ) )
V_30 += V_29 -> V_7 -> V_33 ;
V_23 = & V_17 -> V_18 ;
V_29 = & V_29 -> V_7 -> V_8 ;
break;
default:
if ( V_29 -> V_10 -> V_34 != F_6 ( V_3 ) ) {
F_9 ( V_3 , L_1 ) ;
}
V_23 = & V_29 -> V_10 -> V_18 ;
V_29 = & V_29 -> V_10 -> V_11 ;
break;
case V_12 :
if ( V_29 -> V_13 -> V_35 [ V_28 ] )
V_30 += V_29 -> V_13 -> V_36 -> V_30 ;
V_23 = & V_29 -> V_13 -> V_18 ;
V_29 = & V_29 -> V_13 -> V_14 ;
break;
case V_37 :
if ( V_29 -> V_15 -> V_38 & F_8 ( V_3 ,
1 << V_28 ) ) {
if ( V_29 -> V_15 -> V_39 &
F_8 ( V_3 , 1 << 31 ) )
V_30 += V_29 -> V_15 -> V_36 -> V_30 ;
else
V_30 += F_10 ( 188 ) ;
}
if ( V_29 -> V_15 -> V_38 &
F_8 ( V_3 , 1 << ( 8 + V_28 ) ) ) {
V_30 += V_29 -> V_15 -> V_36 -> V_33 ;
}
V_23 = & V_29 -> V_15 -> V_18 ;
V_29 = & V_29 -> V_15 -> V_16 ;
break;
}
}
#ifdef F_11
if ( V_30 > V_3 -> V_40 )
F_12 ( V_3 , L_2 ,
V_19 * 8 + V_28 , V_30 ) ;
#endif
return V_30 ;
}
static int F_13 ( struct V_41 * V_42 , struct V_41 * V_43 )
{
if ( ! V_42 -> V_44 || ! V_43 -> V_44 )
return 0 ;
if ( V_42 -> V_44 != V_43 -> V_44 )
return 0 ;
if ( V_42 -> V_44 -> V_45 )
return V_42 -> V_46 == V_43 -> V_46 ;
else
return 1 ;
}
static inline unsigned char F_14 ( struct V_2 * V_3 , T_1 V_47 )
{
unsigned char V_48 = V_49 & F_2 ( V_3 , V_47 ) ;
if ( ! V_48 ) {
F_12 ( V_3 , L_3 ) ;
return 7 ;
}
return F_15 ( V_48 ) - 1 ;
}
static inline void F_16 ( unsigned short V_50 [ 8 ] )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < 7 ; V_51 ++ ) {
if ( V_52 [ V_51 ] < V_50 [ V_51 ] ) {
V_50 [ V_51 + 1 ] += V_50 [ V_51 ] - V_52 [ V_51 ] ;
V_50 [ V_51 ] = V_52 [ V_51 ] ;
}
}
}
static void
F_17 (
struct V_2 * V_3 ,
struct V_41 * V_53 ,
unsigned V_19 ,
unsigned short V_50 [ 8 ]
)
{
T_1 * V_23 = & V_3 -> V_4 [ V_19 ] ;
union V_1 * V_29 = & V_3 -> V_22 [ V_19 ] ;
unsigned char V_54 ;
memset ( V_50 , 0 , 16 ) ;
while ( V_29 -> V_20 ) {
switch ( F_2 ( V_3 , F_5 ( V_3 , * V_23 ) ) ) {
case V_12 :
V_23 = & V_29 -> V_13 -> V_18 ;
V_29 = & V_29 -> V_13 -> V_14 ;
continue;
case V_6 :
if ( F_13 ( V_53 , V_29 -> V_7 -> V_53 ) ) {
V_54 = F_14 ( V_3 , V_29 -> V_7 -> V_17 -> V_32 ) ;
V_50 [ V_54 ] += V_29 -> V_7 -> V_50 ;
}
V_23 = & V_29 -> V_7 -> V_17 -> V_18 ;
V_29 = & V_29 -> V_7 -> V_8 ;
continue;
case V_37 :
if ( F_13 ( V_53 , V_29 -> V_15 -> V_55 -> V_53 ) ) {
V_54 = F_14 ( V_3 , V_29 -> V_15 -> V_38 ) ;
V_50 [ V_54 ] += V_29 -> V_15 -> V_36 -> V_50 ;
}
V_23 = & V_29 -> V_15 -> V_18 ;
V_29 = & V_29 -> V_15 -> V_16 ;
continue;
default:
F_9 ( V_3 , L_4 ,
V_19 ) ;
V_23 = & V_29 -> V_10 -> V_18 ;
V_29 = & V_29 -> V_10 -> V_11 ;
}
}
F_16 ( V_50 ) ;
if ( V_52 [ 7 ] < V_50 [ 7 ] )
F_12 ( V_3 , L_5 ,
V_19 , V_50 [ 7 ] - V_52 [ 7 ] ) ;
}
static int F_18 (
struct V_2 * V_3 ,
unsigned V_56 ,
struct V_41 * V_53 ,
unsigned V_19 ,
unsigned V_28 ,
T_2 V_30
)
{
if ( ( V_56 == 0 ) || ( V_28 >= 7 ) )
return 0 ;
for (; V_19 < V_3 -> V_57 ; V_19 += V_56 ) {
unsigned short V_50 [ 8 ] ;
F_17 ( V_3 , V_53 , V_19 , V_50 ) ;
F_19 ( V_3 , L_6
L_7 ,
V_19 , V_30 , V_28 ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] ,
V_50 [ 4 ] , V_50 [ 5 ] , V_50 [ 6 ] , V_50 [ 7 ] ) ;
if ( V_52 [ V_28 ] <= V_50 [ V_28 ] ) {
F_19 ( V_3 , L_8 ,
V_19 , V_28 ) ;
return 0 ;
}
if ( 125 < V_30 ) {
int V_58 = ( V_30 / 125 ) ;
int V_51 ;
for ( V_51 = V_28 ; V_51 < ( V_28 + V_58 ) && V_51 < 8 ; V_51 ++ )
if ( 0 < V_50 [ V_51 ] ) {
F_19 ( V_3 ,
L_9
L_10 ,
V_19 , V_51 ) ;
return 0 ;
}
}
V_50 [ V_28 ] += V_30 ;
F_16 ( V_50 ) ;
if ( V_52 [ 7 ] < V_50 [ 7 ] ) {
F_19 ( V_3 ,
L_11 ,
V_30 , V_19 , V_28 ) ;
return 0 ;
}
}
return 1 ;
}
static int F_20 (
struct V_2 * V_3 ,
unsigned V_56 ,
struct V_41 * V_53 ,
unsigned V_19 ,
T_3 V_59
)
{
if ( V_56 == 0 )
return 0 ;
for (; V_19 < V_3 -> V_57 ; V_19 += V_56 ) {
union V_1 V_24 ;
T_1 type ;
struct V_31 * V_17 ;
V_24 = V_3 -> V_22 [ V_19 ] ;
type = F_5 ( V_3 , V_3 -> V_4 [ V_19 ] ) ;
while ( V_24 . V_20 ) {
switch ( F_2 ( V_3 , type ) ) {
case V_12 :
type = F_5 ( V_3 , V_24 . V_13 -> V_18 ) ;
V_24 = V_24 . V_13 -> V_14 ;
continue;
case V_6 :
V_17 = V_24 . V_7 -> V_17 ;
if ( F_13 ( V_53 , V_24 . V_7 -> V_53 ) ) {
T_3 V_47 ;
V_47 = F_2 ( V_3 ,
V_17 -> V_32 ) ;
V_47 |= V_47 >> 8 ;
if ( V_47 & V_59 )
break;
}
type = F_5 ( V_3 , V_17 -> V_18 ) ;
V_24 = V_24 . V_7 -> V_8 ;
continue;
case V_37 :
if ( F_13 ( V_53 , V_24 . V_15 -> V_55 -> V_53 ) ) {
T_2 V_47 ;
V_47 = F_2 ( V_3 , V_24 . V_15
-> V_38 ) ;
V_47 |= V_47 >> 8 ;
if ( V_47 & V_59 )
break;
}
type = F_5 ( V_3 , V_24 . V_15 -> V_18 ) ;
V_24 = V_24 . V_15 -> V_16 ;
continue;
default:
F_9 ( V_3 ,
L_12 ,
V_19 , type ) ;
}
return 0 ;
}
}
return 1 ;
}
static int F_21 ( struct V_2 * V_3 )
{
T_3 V_60 ;
int V_61 ;
if ( V_3 -> V_62 ++ )
return 0 ;
V_61 = F_22 ( V_3 , & V_3 -> V_63 -> V_61 ,
V_64 , 0 , 9 * 125 ) ;
if ( V_61 ) {
F_23 ( F_24 ( V_3 ) ) ;
return V_61 ;
}
V_60 = F_25 ( V_3 , & V_3 -> V_63 -> V_65 ) | V_66 ;
F_26 ( V_3 , V_60 , & V_3 -> V_63 -> V_65 ) ;
F_24 ( V_3 ) -> V_67 = V_68 ;
V_3 -> V_69 = F_25 ( V_3 , & V_3 -> V_63 -> V_70 )
% ( V_3 -> V_57 << 3 ) ;
if ( F_27 ( V_3 -> V_71 ) )
V_3 -> V_72 = F_28 () ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
T_3 V_60 ;
int V_61 ;
if ( -- V_3 -> V_62 )
return 0 ;
if ( F_27 ( V_3 -> V_71 ) ) {
T_4 V_73 = F_30 ( V_3 -> V_72 , 1000 ) ;
T_4 V_74 = F_28 () ;
T_5 V_75 = F_31 ( V_73 , V_74 ) ;
if ( F_27 ( V_75 > 0 ) )
F_32 ( V_75 ) ;
}
V_61 = F_22 ( V_3 , & V_3 -> V_63 -> V_61 ,
V_64 , V_64 , 9 * 125 ) ;
if ( V_61 ) {
F_23 ( F_24 ( V_3 ) ) ;
return V_61 ;
}
V_60 = F_25 ( V_3 , & V_3 -> V_63 -> V_65 ) & ~ V_66 ;
F_26 ( V_3 , V_60 , & V_3 -> V_63 -> V_65 ) ;
F_33 ( V_3 ) ;
V_3 -> V_69 = - 1 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_76 * V_7 )
{
unsigned V_51 ;
unsigned V_56 = V_7 -> V_56 ;
F_35 ( & V_7 -> V_53 -> V_53 ,
L_13 ,
V_56 , F_36 ( V_3 , & V_7 -> V_17 -> V_32 )
& ( V_77 | V_49 ) ,
V_7 , V_7 -> V_78 , V_7 -> V_30 , V_7 -> V_33 ) ;
if ( V_56 == 0 )
V_56 = 1 ;
for ( V_51 = V_7 -> V_78 ; V_51 < V_3 -> V_57 ; V_51 += V_56 ) {
union V_1 * V_79 = & V_3 -> V_22 [ V_51 ] ;
T_1 * V_23 = & V_3 -> V_4 [ V_51 ] ;
union V_1 V_24 = * V_79 ;
T_1 type = 0 ;
while ( V_24 . V_20 ) {
type = F_5 ( V_3 , * V_23 ) ;
if ( type == F_8 ( V_3 , V_6 ) )
break;
V_79 = F_1 ( V_3 , V_79 , type ) ;
V_23 = F_3 ( V_3 , & V_24 , type ) ;
V_24 = * V_79 ;
}
while ( V_24 . V_20 && V_7 != V_24 . V_7 ) {
if ( V_7 -> V_56 > V_24 . V_7 -> V_56 )
break;
V_79 = & V_24 . V_7 -> V_8 ;
V_23 = & V_24 . V_7 -> V_17 -> V_18 ;
V_24 = * V_79 ;
}
if ( V_7 != V_24 . V_7 ) {
V_7 -> V_8 = V_24 ;
if ( V_24 . V_7 )
V_7 -> V_17 -> V_18 = * V_23 ;
F_37 () ;
V_79 -> V_7 = V_7 ;
* V_23 = F_38 ( V_3 , V_7 -> V_27 ) ;
}
}
V_7 -> V_80 = V_81 ;
V_7 -> V_82 = 0 ;
F_39 ( V_7 ) ;
F_24 ( V_3 ) -> V_83 . V_84 += V_7 -> V_56
? ( ( V_7 -> V_30 + V_7 -> V_33 ) / V_7 -> V_56 )
: ( V_7 -> V_30 * 8 ) ;
return F_21 ( V_3 ) ;
}
static int F_40 ( struct V_2 * V_3 , struct V_76 * V_7 )
{
unsigned V_51 ;
unsigned V_56 ;
if ( ( V_56 = V_7 -> V_56 ) == 0 )
V_56 = 1 ;
for ( V_51 = V_7 -> V_78 ; V_51 < V_3 -> V_57 ; V_51 += V_56 )
F_4 ( V_3 , V_51 , V_7 ) ;
F_24 ( V_3 ) -> V_83 . V_84 -= V_7 -> V_56
? ( ( V_7 -> V_30 + V_7 -> V_33 ) / V_7 -> V_56 )
: ( V_7 -> V_30 * 8 ) ;
F_35 ( & V_7 -> V_53 -> V_53 ,
L_14 ,
V_7 -> V_56 ,
F_36 ( V_3 , & V_7 -> V_17 -> V_32 ) & ( V_77 | V_49 ) ,
V_7 , V_7 -> V_78 , V_7 -> V_30 , V_7 -> V_33 ) ;
V_7 -> V_80 = V_85 ;
V_7 -> V_8 . V_20 = NULL ;
F_41 ( V_7 ) ;
return F_29 ( V_3 ) ;
}
static void F_42 ( struct V_2 * V_3 , struct V_76 * V_7 )
{
unsigned V_86 ;
struct V_31 * V_17 = V_7 -> V_17 ;
int V_87 ;
if ( V_7 -> V_80 != V_81 ) {
if ( V_7 -> V_80 == V_88 )
V_7 -> V_89 = 1 ;
return;
}
F_40 ( V_3 , V_7 ) ;
if ( F_43 ( & V_7 -> V_90 )
|| ( F_8 ( V_3 , V_77 )
& V_17 -> V_32 ) != 0 )
V_86 = 2 ;
else
V_86 = 55 ;
F_32 ( V_86 ) ;
V_7 -> V_80 = V_91 ;
V_17 -> V_18 = F_6 ( V_3 ) ;
F_37 () ;
F_44 ( V_3 , V_7 ) ;
if ( ! F_43 ( & V_7 -> V_90 ) &&
F_45 ( F_24 ( V_3 ) -> V_67 ) ) {
V_87 = F_46 ( V_3 , V_7 ) ;
if ( V_87 != 0 )
F_12 ( V_3 , L_15 ,
V_7 , V_87 ) ;
}
}
static int F_47 (
struct V_2 * V_3 ,
unsigned V_19 ,
unsigned V_28 ,
unsigned V_56 ,
unsigned V_30
) {
int V_92 ;
if ( V_28 >= 8 )
return 0 ;
V_30 = V_3 -> V_40 - V_30 ;
if ( F_27 ( V_56 == 0 ) ) {
do {
for ( V_28 = 0 ; V_28 < 7 ; V_28 ++ ) {
V_92 = F_7 ( V_3 , V_19 , V_28 ) ;
if ( V_92 > V_30 )
return 0 ;
}
} while ( ( V_19 += 1 ) < V_3 -> V_57 );
} else {
do {
V_92 = F_7 ( V_3 , V_19 , V_28 ) ;
if ( V_92 > V_30 )
return 0 ;
} while ( ( V_19 += V_56 ) < V_3 -> V_57 );
}
return 1 ;
}
static int F_48 (
struct V_2 * V_3 ,
unsigned V_19 ,
unsigned V_28 ,
const struct V_76 * V_7 ,
T_1 * V_93
)
{
int V_94 = - V_95 ;
T_6 V_47 = 0 ;
if ( V_7 -> V_33 && V_28 >= 6 )
goto V_96;
if ( ! F_47 ( V_3 , V_19 , V_28 , V_7 -> V_56 , V_7 -> V_30 ) )
goto V_96;
if ( ! V_7 -> V_33 ) {
V_94 = 0 ;
* V_93 = 0 ;
goto V_96;
}
#ifdef F_49
if ( F_18 ( V_3 , V_7 -> V_56 , V_7 -> V_53 , V_19 , V_28 ,
V_7 -> V_50 ) ) {
unsigned V_51 ;
for ( V_51 = V_28 + 1 ; V_51 < 8 && V_51 < V_28 + 4 ; V_51 ++ )
if ( ! F_47 ( V_3 , V_19 , V_51 ,
V_7 -> V_56 , V_7 -> V_33 ) )
goto V_96;
else
V_47 |= 1 << V_51 ;
V_94 = 0 ;
* V_93 = F_8 ( V_3 , V_47 << 8 ) ;
}
#else
V_47 = 0x03 << ( V_28 + V_7 -> V_97 ) ;
* V_93 = F_8 ( V_3 , V_47 << 8 ) ;
V_47 |= 1 << V_28 ;
if ( F_20 ( V_3 , V_7 -> V_56 , V_7 -> V_53 , V_19 , V_47 ) ) {
if ( ! F_47 ( V_3 , V_19 , V_28 + V_7 -> V_97 + 1 ,
V_7 -> V_56 , V_7 -> V_33 ) )
goto V_96;
if ( ! F_47 ( V_3 , V_19 , V_28 + V_7 -> V_97 ,
V_7 -> V_56 , V_7 -> V_33 ) )
goto V_96;
V_94 = 0 ;
}
#endif
V_96:
return V_94 ;
}
static int F_46 ( struct V_2 * V_3 , struct V_76 * V_7 )
{
int V_61 ;
unsigned V_28 ;
T_1 V_98 ;
unsigned V_19 ;
struct V_31 * V_17 = V_7 -> V_17 ;
F_50 ( V_3 , V_7 ) ;
V_17 -> V_18 = F_6 ( V_3 ) ;
V_19 = V_7 -> V_78 ;
if ( V_19 < V_7 -> V_56 ) {
V_28 = F_15 ( F_36 ( V_3 , & V_17 -> V_32 ) & V_49 ) ;
V_61 = F_48 ( V_3 , V_19 , -- V_28 ,
V_7 , & V_98 ) ;
} else {
V_28 = 0 ;
V_98 = 0 ;
V_61 = - V_95 ;
}
if ( V_61 ) {
if ( V_7 -> V_56 ) {
int V_51 ;
for ( V_51 = V_7 -> V_56 ; V_61 && V_51 > 0 ; -- V_51 ) {
V_19 = ++ V_3 -> V_99 % V_7 -> V_56 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_61 = F_48 ( V_3 ,
V_19 , V_28 , V_7 ,
& V_98 ) ;
if ( V_61 == 0 )
break;
}
}
} else {
V_19 = 0 ;
V_61 = F_48 ( V_3 , 0 , 0 , V_7 , & V_98 ) ;
}
if ( V_61 )
goto V_96;
V_7 -> V_78 = V_19 ;
V_17 -> V_32 &= F_8 ( V_3 , ~ ( V_77 | V_49 ) ) ;
V_17 -> V_32 |= V_7 -> V_56
? F_8 ( V_3 , 1 << V_28 )
: F_8 ( V_3 , V_49 ) ;
V_17 -> V_32 |= V_98 ;
} else
F_9 ( V_3 , L_16 , V_7 ) ;
V_61 = F_34 ( V_3 , V_7 ) ;
V_96:
return V_61 ;
}
static int F_51 (
struct V_2 * V_3 ,
struct V_55 * V_55 ,
struct V_100 * V_90 ,
T_7 V_101
) {
unsigned V_102 ;
unsigned long V_103 ;
struct V_76 * V_7 ;
int V_61 ;
struct V_100 V_104 ;
V_102 = V_55 -> V_105 -> V_106 . V_107 ;
F_52 ( & V_3 -> V_108 , V_103 ) ;
if ( F_27 ( ! F_53 ( F_24 ( V_3 ) ) ) ) {
V_61 = - V_109 ;
goto V_110;
}
V_61 = F_54 ( F_24 ( V_3 ) , V_55 ) ;
if ( F_27 ( V_61 ) )
goto V_110;
F_55 ( & V_104 ) ;
V_7 = F_56 ( V_3 , V_55 , & V_104 , V_102 , & V_55 -> V_105 -> V_111 ) ;
if ( V_7 == NULL ) {
V_61 = - V_112 ;
goto V_96;
}
if ( V_7 -> V_80 == V_91 ) {
if ( ( V_61 = F_46 ( V_3 , V_7 ) ) != 0 )
goto V_96;
}
V_7 = F_56 ( V_3 , V_55 , V_90 , V_102 , & V_55 -> V_105 -> V_111 ) ;
F_57 ( V_7 == NULL ) ;
F_24 ( V_3 ) -> V_83 . V_113 ++ ;
V_96:
if ( F_27 ( V_61 ) )
F_58 ( F_24 ( V_3 ) , V_55 ) ;
V_110:
F_59 ( & V_3 -> V_108 , V_103 ) ;
if ( V_61 )
F_60 ( V_3 , V_55 , V_90 ) ;
return V_61 ;
}
static struct V_114 *
F_61 ( T_7 V_101 )
{
struct V_114 * V_36 ;
V_36 = F_62 ( sizeof *V_36 , V_101 ) ;
if ( F_63 ( V_36 != NULL ) ) {
F_55 ( & V_36 -> V_115 ) ;
F_55 ( & V_36 -> V_116 ) ;
V_36 -> V_69 = - 1 ;
V_36 -> V_117 = 1 ;
}
return V_36 ;
}
static void
F_64 (
struct V_2 * V_3 ,
struct V_114 * V_36 ,
struct V_41 * V_53 ,
int V_118 ,
unsigned V_119
)
{
static const T_6 V_120 [] = { 0x01 , 0x03 , 0x07 , 0x0f , 0x1f , 0x3f } ;
T_3 V_121 ;
unsigned V_102 , V_122 ;
int V_123 ;
long V_124 ;
V_102 = F_65 ( V_118 ) ;
V_123 = F_66 ( V_118 ) ? V_125 : 0 ;
V_122 = F_67 ( V_53 , V_118 , ! V_123 ) ;
if ( V_123 ) {
V_121 = ( 1 << 11 ) ;
} else {
V_121 = 0 ;
}
if ( V_53 -> V_126 == V_127 ) {
unsigned V_45 = F_68 ( V_122 ) ;
V_36 -> V_128 = 1 ;
V_122 = F_69 ( V_122 ) ;
V_121 |= V_122 ;
V_122 *= V_45 ;
V_36 -> V_129 = F_8 ( V_3 , ( V_102 << 8 ) | V_53 -> V_130 ) ;
V_36 -> V_121 = F_8 ( V_3 , V_121 ) ;
V_36 -> V_131 = F_8 ( V_3 , V_45 ) ;
V_36 -> V_30 = F_10 ( V_122 ) ;
V_124 = V_36 -> V_30 * 8 ;
V_124 /= V_119 ;
} else {
T_3 V_132 ;
int V_133 ;
int V_134 ;
V_132 = V_53 -> V_46 << 24 ;
if ( ! F_70 ( V_3 )
|| ( V_53 -> V_44 -> V_135 !=
F_24 ( V_3 ) -> V_83 . V_136 ) )
V_132 |= V_53 -> V_44 -> V_135 -> V_130 << 16 ;
V_132 |= V_102 << 8 ;
V_132 |= V_53 -> V_130 ;
V_36 -> V_30 = F_10 ( V_122 ) ;
V_133 = V_53 -> V_44 ? V_53 -> V_44 -> V_133 : 0 ;
V_36 -> V_50 = F_71 ( V_133 + F_72 (
V_53 -> V_126 , V_123 , 1 , V_122 ) ) ;
V_134 = F_73 ( 1u , ( V_122 + 187 ) / 188 ) ;
if ( V_123 ) {
T_3 V_137 ;
V_132 |= 1 << 31 ;
V_36 -> V_33 = V_36 -> V_30 ;
V_36 -> V_30 = F_10 ( 1 ) ;
V_36 -> V_138 = 1 ;
V_137 = ( 1 << ( V_134 + 2 ) ) - 1 ;
V_36 -> V_138 |= V_137 << ( 8 + 2 ) ;
} else
V_36 -> V_138 = V_120 [ V_134 - 1 ] ;
V_124 = V_36 -> V_30 + V_36 -> V_33 ;
V_124 /= V_119 << 3 ;
V_36 -> V_139 = F_8 ( V_3 , V_132 ) ;
}
V_36 -> V_124 = V_124 ;
V_36 -> V_140 = V_53 ;
V_36 -> V_107 = V_123 | V_102 ;
V_36 -> V_119 = V_119 ;
V_36 -> V_122 = V_122 ;
}
static void
F_74 ( struct V_2 * V_3 , struct V_114 * V_36 )
{
V_36 -> V_117 -- ;
if ( V_36 -> V_117 == 1 ) {
while ( ! F_43 ( & V_36 -> V_116 ) ) {
struct V_100 * V_141 ;
V_141 = V_36 -> V_116 . V_142 ;
F_75 ( V_141 ) ;
if ( V_36 -> V_128 ) {
struct V_143 * V_13 ;
V_13 = F_76 ( V_141 , struct V_143 ,
V_144 ) ;
F_77 ( V_3 -> V_145 , V_13 ,
V_13 -> V_146 ) ;
} else {
struct V_147 * V_15 ;
V_15 = F_76 ( V_141 , struct V_147 ,
V_148 ) ;
F_77 ( V_3 -> V_149 , V_15 ,
V_15 -> V_150 ) ;
}
}
V_36 -> V_107 &= 0x0f ;
if ( V_36 -> V_105 )
V_36 -> V_105 -> V_111 = NULL ;
F_78 ( V_36 ) ;
}
}
static inline struct V_114 *
F_79 ( struct V_114 * V_36 )
{
if ( F_63 ( V_36 != NULL ) )
V_36 -> V_117 ++ ;
return V_36 ;
}
static struct V_114 *
F_80 ( struct V_2 * V_3 , struct V_55 * V_55 )
{
unsigned V_102 ;
struct V_114 * V_36 ;
struct V_151 * V_105 ;
unsigned long V_103 ;
V_102 = F_65 ( V_55 -> V_118 ) ;
if ( F_66 ( V_55 -> V_118 ) )
V_105 = V_55 -> V_53 -> V_152 [ V_102 ] ;
else
V_105 = V_55 -> V_53 -> V_153 [ V_102 ] ;
F_52 ( & V_3 -> V_108 , V_103 ) ;
V_36 = V_105 -> V_111 ;
if ( F_27 ( V_36 == NULL ) ) {
V_36 = F_61 ( V_154 ) ;
if ( F_63 ( V_36 != NULL ) ) {
V_105 -> V_111 = V_36 ;
V_36 -> V_105 = V_105 ;
F_64 ( V_3 , V_36 , V_55 -> V_53 , V_55 -> V_118 ,
V_55 -> V_119 ) ;
}
} else if ( F_27 ( V_36 -> V_17 != NULL ) ) {
F_9 ( V_3 , L_17 ,
V_55 -> V_53 -> V_155 , V_102 ,
F_66 ( V_55 -> V_118 ) ? L_18 : L_19 ) ;
V_36 = NULL ;
}
V_36 = F_79 ( V_36 ) ;
F_59 ( & V_3 -> V_108 , V_103 ) ;
return V_36 ;
}
static struct V_156 *
F_81 ( unsigned V_157 , T_7 V_101 )
{
struct V_156 * V_158 ;
int V_159 = sizeof *V_158 ;
V_159 += V_157 * sizeof ( struct V_160 ) ;
V_158 = F_62 ( V_159 , V_101 ) ;
if ( F_63 ( V_158 != NULL ) ) {
F_55 ( & V_158 -> V_115 ) ;
}
return V_158 ;
}
static inline void
F_82 (
struct V_2 * V_3 ,
struct V_156 * V_158 ,
struct V_114 * V_36 ,
struct V_55 * V_55
)
{
unsigned V_51 ;
T_8 V_161 = V_55 -> V_162 ;
V_158 -> V_163 = V_55 -> V_164 * V_36 -> V_119 ;
for ( V_51 = 0 ; V_51 < V_55 -> V_164 ; V_51 ++ ) {
struct V_160 * V_28 = & V_158 -> V_165 [ V_51 ] ;
unsigned V_166 ;
T_8 V_167 ;
T_3 V_168 ;
V_166 = V_55 -> V_169 [ V_51 ] . V_166 ;
V_167 = V_161 + V_55 -> V_169 [ V_51 ] . V_170 ;
V_168 = V_171 ;
V_168 |= V_167 & 0x0fff ;
if ( F_27 ( ( ( V_51 + 1 ) == V_55 -> V_164 ) )
&& ! ( V_55 -> V_172 & V_173 ) )
V_168 |= V_174 ;
V_168 |= V_166 << 16 ;
V_28 -> V_175 = F_8 ( V_3 , V_168 ) ;
V_28 -> V_176 = ( V_167 & ~ ( V_177 ) 0x0fff ) ;
V_167 += V_166 ;
if ( F_27 ( ( V_28 -> V_176 != ( V_167 & ~ ( V_177 ) 0x0fff ) ) ) )
V_28 -> V_178 = 1 ;
}
}
static void
F_83 (
struct V_114 * V_36 ,
struct V_156 * V_158
)
{
if ( ! V_158 )
return;
F_84 ( & V_158 -> V_115 , & V_36 -> V_116 ) ;
F_78 ( V_158 ) ;
}
static int
F_85 (
struct V_114 * V_36 ,
struct V_2 * V_3 ,
struct V_55 * V_55 ,
T_7 V_101
)
{
struct V_143 * V_13 ;
T_8 V_146 ;
int V_51 ;
unsigned V_179 ;
struct V_156 * V_180 ;
unsigned long V_103 ;
V_180 = F_81 ( V_55 -> V_164 , V_101 ) ;
if ( F_27 ( V_180 == NULL ) )
return - V_112 ;
F_82 ( V_3 , V_180 , V_36 , V_55 ) ;
if ( V_55 -> V_119 < 8 )
V_179 = 1 + ( V_180 -> V_163 + 7 ) / 8 ;
else
V_179 = V_55 -> V_164 ;
F_52 ( & V_3 -> V_108 , V_103 ) ;
for ( V_51 = 0 ; V_51 < V_179 ; V_51 ++ ) {
if ( F_63 ( ! F_43 ( & V_36 -> V_116 ) ) ) {
V_13 = F_76 ( V_36 -> V_116 . V_79 ,
struct V_143 , V_144 ) ;
F_75 ( & V_13 -> V_144 ) ;
V_146 = V_13 -> V_146 ;
} else {
F_59 ( & V_3 -> V_108 , V_103 ) ;
V_13 = F_86 ( V_3 -> V_145 , V_101 ,
& V_146 ) ;
F_52 ( & V_3 -> V_108 , V_103 ) ;
if ( ! V_13 ) {
F_83 ( V_36 , V_180 ) ;
F_59 ( & V_3 -> V_108 , V_103 ) ;
return - V_112 ;
}
}
memset ( V_13 , 0 , sizeof *V_13 ) ;
V_13 -> V_146 = V_146 ;
F_87 ( & V_13 -> V_144 , & V_180 -> V_115 ) ;
}
F_59 ( & V_3 -> V_108 , V_103 ) ;
V_55 -> V_111 = V_180 ;
V_55 -> V_181 = 0 ;
return 0 ;
}
static inline int
F_88 (
struct V_2 * V_3 ,
T_3 V_182 ,
T_3 V_28 ,
T_6 V_30 ,
T_3 V_56
)
{
V_28 %= V_56 ;
do {
if ( F_7 ( V_3 , V_28 >> 3 , V_28 & 0x7 )
> ( V_3 -> V_40 - V_30 ) )
return 0 ;
V_28 += V_56 ;
} while ( V_28 < V_182 );
return 1 ;
}
static inline int
F_89 (
struct V_2 * V_3 ,
T_3 V_182 ,
struct V_114 * V_36 ,
T_3 V_28 ,
struct V_156 * V_180 ,
T_3 V_183
)
{
T_3 V_47 , V_137 ;
T_3 V_19 , V_54 ;
V_47 = V_36 -> V_138 << ( V_28 & 7 ) ;
if ( V_47 & ~ 0xffff )
return 0 ;
V_28 %= V_183 ;
do {
T_3 V_184 ;
V_19 = V_28 >> 3 ;
V_54 = V_28 & 7 ;
#ifdef F_49
if ( ! F_18 ( V_3 , V_183 << 3 ,
V_36 -> V_140 , V_19 , V_54 , V_36 -> V_50 ) )
return 0 ;
#else
if ( ! F_20 ( V_3 , V_183 << 3 ,
V_36 -> V_140 , V_19 , V_47 ) )
return 0 ;
#endif
V_184 = V_3 -> V_40 - V_36 -> V_30 ;
for ( V_137 = V_36 -> V_138 & 0xff ; V_137 ; V_137 >>= 1 , V_54 ++ ) {
if ( F_7 ( V_3 , V_19 , V_54 ) > V_184 )
return 0 ;
}
if ( V_36 -> V_33 ) {
V_54 = V_28 & 7 ;
V_184 = V_3 -> V_40 - V_36 -> V_33 ;
do {
V_137 = 1 << V_54 ;
V_137 <<= 8 ;
if ( ( V_36 -> V_138 & V_137 ) == 0 )
continue;
if ( F_7 ( V_3 , V_19 , V_54 )
> V_184 )
return 0 ;
} while ( ++ V_54 < 8 );
}
V_28 += V_183 ;
} while ( V_28 < V_182 );
V_36 -> V_185 = F_8 ( V_3 , V_36 -> V_138 << ( V_28 & 7 ) ) ;
return 1 ;
}
static int
F_90 (
struct V_2 * V_3 ,
struct V_55 * V_55 ,
struct V_114 * V_36
)
{
T_3 V_74 , V_142 , V_78 , V_56 , V_163 ;
int V_61 ;
unsigned V_182 = V_3 -> V_57 << 3 ;
struct V_156 * V_180 = V_55 -> V_111 ;
V_56 = V_55 -> V_119 ;
V_163 = V_180 -> V_163 ;
if ( ! V_36 -> V_128 ) {
V_56 <<= 3 ;
V_163 <<= 3 ;
}
if ( V_163 > V_182 - V_186 ) {
F_9 ( V_3 , L_20 , V_55 ) ;
V_61 = - V_187 ;
goto V_188;
}
V_74 = F_25 ( V_3 , & V_3 -> V_63 -> V_70 ) & ( V_182 - 1 ) ;
if ( F_63 ( ! F_43 ( & V_36 -> V_115 ) ) ) {
T_3 V_189 ;
if ( ! V_36 -> V_128 && V_3 -> V_190 )
V_142 = V_74 + V_3 -> V_191 ;
else
V_142 = V_74 ;
V_189 = ( V_36 -> V_69 - V_56 - V_142 ) & ( V_182 - 1 ) ;
if ( V_189 >= V_182 - 2 * V_186 )
V_78 = V_142 + V_189 - V_182 + V_56 *
F_91 ( V_182 - V_189 , V_56 ) ;
else
V_78 = V_142 + V_189 + V_56 ;
if ( V_78 - V_74 >= V_182 ) {
F_9 ( V_3 , L_21 ,
V_55 , V_78 - V_74 - V_56 , V_56 ,
V_182 ) ;
V_61 = - V_187 ;
goto V_188;
}
}
else {
V_78 = V_186 + ( V_74 & ~ 0x07 ) ;
V_142 = V_78 + V_56 ;
for (; V_78 < V_142 ; V_78 ++ ) {
if ( V_36 -> V_128 ) {
if ( F_88 ( V_3 , V_182 , V_78 ,
V_36 -> V_30 , V_56 ) )
break;
} else {
if ( ( V_78 % 8 ) >= 6 )
continue;
if ( F_89 ( V_3 , V_182 , V_36 ,
V_78 , V_180 , V_56 ) )
break;
}
}
if ( V_78 == V_142 ) {
F_9 ( V_3 , L_22 ,
V_55 , V_74 , V_74 + V_182 ) ;
V_61 = - V_95 ;
goto V_188;
}
}
if ( F_27 ( V_78 - V_74 + V_163 - V_56
>= V_182 - 2 * V_186 ) ) {
F_9 ( V_3 , L_21 ,
V_55 , V_78 - V_74 , V_163 - V_56 ,
V_182 - 2 * V_186 ) ;
V_61 = - V_187 ;
goto V_188;
}
V_36 -> V_69 = V_78 & ( V_182 - 1 ) ;
V_55 -> V_192 = V_36 -> V_69 ;
if ( ! V_36 -> V_128 )
V_55 -> V_192 >>= 3 ;
return 0 ;
V_188:
F_83 ( V_36 , V_180 ) ;
V_55 -> V_111 = NULL ;
return V_61 ;
}
static inline void
F_92 ( struct V_2 * V_3 , struct V_114 * V_36 ,
struct V_143 * V_13 )
{
int V_51 ;
V_13 -> V_18 = F_6 ( V_3 ) ;
V_13 -> V_193 [ 0 ] = V_36 -> V_129 ;
V_13 -> V_193 [ 1 ] = V_36 -> V_121 ;
V_13 -> V_193 [ 2 ] = V_36 -> V_131 ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ )
V_13 -> V_194 [ V_51 ] = - 1 ;
}
static inline void
F_93 (
struct V_2 * V_3 ,
struct V_143 * V_13 ,
struct V_156 * V_158 ,
unsigned V_194 ,
T_2 V_28
)
{
struct V_160 * V_54 = & V_158 -> V_165 [ V_194 ] ;
unsigned V_195 = V_13 -> V_195 ;
V_28 &= 0x07 ;
V_13 -> V_194 [ V_28 ] = V_194 ;
V_13 -> V_35 [ V_28 ] = V_54 -> V_175 ;
V_13 -> V_35 [ V_28 ] |= F_8 ( V_3 , V_195 << 12 ) ;
V_13 -> V_193 [ V_195 ] |= F_8 ( V_3 , V_54 -> V_176 & ~ ( T_3 ) 0 ) ;
V_13 -> V_196 [ V_195 ] |= F_8 ( V_3 , ( T_3 ) ( V_54 -> V_176 >> 32 ) ) ;
if ( F_27 ( V_54 -> V_178 ) ) {
V_177 V_176 = V_54 -> V_176 + 4096 ;
V_13 -> V_195 = ++ V_195 ;
V_13 -> V_193 [ V_195 ] |= F_8 ( V_3 , V_176 & ~ ( T_3 ) 0 ) ;
V_13 -> V_196 [ V_195 ] |= F_8 ( V_3 , ( T_3 ) ( V_176 >> 32 ) ) ;
}
}
static inline void
F_94 ( struct V_2 * V_3 , unsigned V_19 , struct V_143 * V_13 )
{
union V_1 * V_79 = & V_3 -> V_22 [ V_19 ] ;
T_1 * V_23 = & V_3 -> V_4 [ V_19 ] ;
union V_1 V_24 = * V_79 ;
T_1 type = 0 ;
while ( V_24 . V_20 ) {
type = F_5 ( V_3 , * V_23 ) ;
if ( type == F_8 ( V_3 , V_6 ) )
break;
V_79 = F_1 ( V_3 , V_79 , type ) ;
V_23 = F_3 ( V_3 , & V_24 , type ) ;
V_24 = * V_79 ;
}
V_13 -> V_14 = V_24 ;
V_13 -> V_18 = * V_23 ;
V_79 -> V_13 = V_13 ;
V_13 -> V_19 = V_19 ;
F_37 () ;
* V_23 = F_8 ( V_3 , V_13 -> V_146 | V_12 ) ;
}
static int
F_95 (
struct V_2 * V_3 ,
struct V_55 * V_55 ,
unsigned V_182 ,
struct V_114 * V_36
)
{
int V_165 ;
unsigned V_69 , V_28 , V_19 ;
struct V_156 * V_158 = V_55 -> V_111 ;
struct V_143 * V_13 ;
V_69 = V_36 -> V_69 & ( V_182 - 1 ) ;
if ( F_27 ( F_43 ( & V_36 -> V_115 ) ) ) {
F_24 ( V_3 ) -> V_83 . V_84
+= V_36 -> V_124 ;
F_19 ( V_3 ,
L_23 ,
V_55 -> V_53 -> V_155 , V_36 -> V_107 & 0x0f ,
( V_36 -> V_107 & V_125 ) ? L_18 : L_19 ,
V_55 -> V_119 ,
V_69 >> 3 , V_69 & 0x7 ) ;
}
if ( F_24 ( V_3 ) -> V_83 . V_197 == 0 ) {
if ( V_3 -> V_198 == 1 )
F_96 () ;
}
F_24 ( V_3 ) -> V_83 . V_197 ++ ;
for ( V_165 = 0 , V_13 = NULL ; V_165 < V_55 -> V_164 ; ) {
if ( V_13 == NULL ) {
V_13 = F_76 ( V_158 -> V_115 . V_142 ,
struct V_143 , V_144 ) ;
F_97 ( & V_13 -> V_144 , & V_36 -> V_115 ) ;
V_13 -> V_36 = F_79 ( V_36 ) ;
V_13 -> V_55 = V_55 ;
F_92 ( V_3 , V_36 , V_13 ) ;
}
V_28 = V_69 & 0x07 ;
V_19 = V_69 >> 3 ;
F_93 ( V_3 , V_13 , V_158 , V_165 , V_28 ) ;
V_69 += V_36 -> V_119 ;
V_69 &= V_182 - 1 ;
V_165 ++ ;
if ( ( ( V_69 >> 3 ) != V_19 )
|| V_165 == V_55 -> V_164 ) {
F_94 ( V_3 , V_19 & ( V_3 -> V_57 - 1 ) , V_13 ) ;
V_13 = NULL ;
}
}
V_36 -> V_69 = V_69 ;
F_83 ( V_36 , V_158 ) ;
V_55 -> V_111 = NULL ;
F_98 ( V_3 , V_199 ) ;
return F_21 ( V_3 ) ;
}
static unsigned
F_99 (
struct V_2 * V_3 ,
struct V_143 * V_13
) {
struct V_55 * V_55 = V_13 -> V_55 ;
struct V_200 * V_106 ;
T_3 V_201 ;
unsigned V_28 ;
int V_202 = - 1 ;
struct V_114 * V_36 = V_13 -> V_36 ;
struct V_41 * V_53 ;
unsigned V_94 = false ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
if ( F_63 ( V_13 -> V_194 [ V_28 ] == - 1 ) )
continue;
V_202 = V_13 -> V_194 [ V_28 ] ;
V_106 = & V_55 -> V_169 [ V_202 ] ;
V_201 = F_36 ( V_3 , & V_13 -> V_35 [ V_28 ] ) ;
V_13 -> V_35 [ V_28 ] = 0 ;
if ( F_27 ( V_201 & V_203 ) ) {
V_55 -> V_181 ++ ;
if ( V_201 & V_204 )
V_106 -> V_61 = F_66 ( V_55 -> V_118 )
? - V_205
: - V_206 ;
else if ( V_201 & V_207 )
V_106 -> V_61 = - V_208 ;
else
V_106 -> V_61 = - V_209 ;
if ( ! ( V_201 & V_207 ) ) {
V_106 -> V_210 = F_100 ( V_201 ) ;
V_55 -> V_210 += V_106 -> V_210 ;
}
} else if ( F_63 ( ( V_201 & V_171 ) == 0 ) ) {
V_106 -> V_61 = 0 ;
V_106 -> V_210 = F_100 ( V_201 ) ;
V_55 -> V_210 += V_106 -> V_210 ;
} else {
V_106 -> V_61 = - V_211 ;
}
}
if ( F_63 ( ( V_202 + 1 ) != V_55 -> V_164 ) )
goto V_96;
V_53 = V_55 -> V_53 ;
F_101 ( V_3 , V_55 , 0 ) ;
V_94 = true ;
V_55 = NULL ;
( void ) F_29 ( V_3 ) ;
F_24 ( V_3 ) -> V_83 . V_197 -- ;
if ( F_24 ( V_3 ) -> V_83 . V_197 == 0 ) {
if ( V_3 -> V_198 == 1 )
F_102 () ;
}
if ( F_27 ( F_103 ( & V_36 -> V_115 ) ) ) {
F_24 ( V_3 ) -> V_83 . V_84
-= V_36 -> V_124 ;
F_19 ( V_3 ,
L_24 ,
V_53 -> V_155 , V_36 -> V_107 & 0x0f ,
( V_36 -> V_107 & V_125 ) ? L_18 : L_19 ) ;
}
F_74 ( V_3 , V_36 ) ;
V_96:
V_13 -> V_55 = NULL ;
if ( V_3 -> V_212 != V_13 -> V_19 || V_13 -> V_194 [ 7 ] != - 1 ) {
V_13 -> V_36 = NULL ;
F_104 ( & V_13 -> V_144 , & V_36 -> V_116 ) ;
F_74 ( V_3 , V_36 ) ;
} else {
F_104 ( & V_13 -> V_144 , & V_3 -> V_213 ) ;
if ( V_36 -> V_117 == 2 ) {
V_36 -> V_105 -> V_111 = NULL ;
V_36 -> V_105 = NULL ;
}
}
return V_94 ;
}
static int F_105 ( struct V_2 * V_3 , struct V_55 * V_55 ,
T_7 V_101 )
{
int V_61 = - V_214 ;
unsigned long V_103 ;
struct V_114 * V_36 ;
V_36 = F_80 ( V_3 , V_55 ) ;
if ( F_27 ( V_36 == NULL ) ) {
F_9 ( V_3 , L_25 ) ;
return - V_112 ;
}
if ( F_27 ( V_55 -> V_119 != V_36 -> V_119 ) ) {
F_9 ( V_3 , L_26 ,
V_36 -> V_119 , V_55 -> V_119 ) ;
goto V_96;
}
#ifdef F_106
F_9 ( V_3 ,
L_27 ,
V_215 , V_55 -> V_53 -> V_155 , V_55 ,
F_65 ( V_55 -> V_118 ) ,
F_66 ( V_55 -> V_118 ) ? L_18 : L_19 ,
V_55 -> V_216 ,
V_55 -> V_164 , V_55 -> V_119 ,
V_36 ) ;
#endif
V_61 = F_85 ( V_36 , V_3 , V_55 , V_101 ) ;
if ( F_27 ( V_61 < 0 ) ) {
F_9 ( V_3 , L_28 ) ;
goto V_96;
}
F_52 ( & V_3 -> V_108 , V_103 ) ;
if ( F_27 ( ! F_53 ( F_24 ( V_3 ) ) ) ) {
V_61 = - V_109 ;
goto V_110;
}
V_61 = F_54 ( F_24 ( V_3 ) , V_55 ) ;
if ( F_27 ( V_61 ) )
goto V_110;
V_61 = F_90 ( V_3 , V_55 , V_36 ) ;
if ( F_63 ( V_61 == 0 ) )
F_95 ( V_3 , V_55 , V_3 -> V_57 << 3 , V_36 ) ;
else
F_58 ( F_24 ( V_3 ) , V_55 ) ;
V_110:
F_59 ( & V_3 -> V_108 , V_103 ) ;
V_96:
if ( F_27 ( V_61 < 0 ) )
F_74 ( V_3 , V_36 ) ;
return V_61 ;
}
static inline void
F_107 (
struct V_2 * V_3 ,
struct V_156 * V_158 ,
struct V_114 * V_36 ,
struct V_55 * V_55
)
{
unsigned V_51 ;
T_8 V_161 = V_55 -> V_162 ;
V_158 -> V_163 = V_55 -> V_164 * V_36 -> V_119 ;
for ( V_51 = 0 ; V_51 < V_55 -> V_164 ; V_51 ++ ) {
struct V_160 * V_165 = & V_158 -> V_165 [ V_51 ] ;
unsigned V_166 ;
T_8 V_167 ;
T_3 V_168 ;
V_166 = V_55 -> V_169 [ V_51 ] . V_166 & 0x03ff ;
V_167 = V_161 + V_55 -> V_169 [ V_51 ] . V_170 ;
V_168 = V_217 ;
if ( ( ( V_51 + 1 ) == V_55 -> V_164 )
&& ! ( V_55 -> V_172 & V_173 ) )
V_168 |= V_218 ;
V_168 |= V_166 << 16 ;
V_165 -> V_175 = F_8 ( V_3 , V_168 ) ;
V_165 -> V_176 = V_167 ;
V_165 -> V_121 = ( V_167 + V_166 ) & ~ 0x0fff ;
if ( V_165 -> V_121 != ( V_167 & ~ ( V_177 ) 0x0fff ) )
V_165 -> V_178 = 1 ;
if ( V_36 -> V_107 & V_125 )
continue;
V_166 = ( V_166 + 187 ) / 188 ;
if ( V_166 > 1 )
V_166 |= 1 << 3 ;
V_165 -> V_121 |= V_166 ;
}
}
static int
F_108 (
struct V_114 * V_36 ,
struct V_2 * V_3 ,
struct V_55 * V_55 ,
T_7 V_101
)
{
struct V_147 * V_15 ;
T_8 V_150 ;
int V_51 ;
struct V_156 * V_158 ;
unsigned long V_103 ;
V_158 = F_81 ( V_55 -> V_164 , V_101 ) ;
if ( V_158 == NULL )
return - V_112 ;
F_107 ( V_3 , V_158 , V_36 , V_55 ) ;
F_52 ( & V_3 -> V_108 , V_103 ) ;
for ( V_51 = 0 ; V_51 < V_55 -> V_164 ; V_51 ++ ) {
if ( ! F_43 ( & V_36 -> V_116 ) ) {
V_15 = F_76 ( V_36 -> V_116 . V_79 ,
struct V_147 , V_148 ) ;
F_75 ( & V_15 -> V_148 ) ;
V_150 = V_15 -> V_150 ;
} else {
F_59 ( & V_3 -> V_108 , V_103 ) ;
V_15 = F_86 ( V_3 -> V_149 , V_101 ,
& V_150 ) ;
F_52 ( & V_3 -> V_108 , V_103 ) ;
if ( ! V_15 ) {
F_83 ( V_36 , V_158 ) ;
F_59 ( & V_3 -> V_108 , V_103 ) ;
return - V_112 ;
}
}
memset ( V_15 , 0 , sizeof *V_15 ) ;
V_15 -> V_150 = V_150 ;
F_87 ( & V_15 -> V_148 , & V_158 -> V_115 ) ;
}
V_55 -> V_111 = V_158 ;
V_55 -> V_181 = 0 ;
F_59 ( & V_3 -> V_108 , V_103 ) ;
return 0 ;
}
static inline void
F_109 (
struct V_2 * V_3 ,
struct V_114 * V_36 ,
struct V_147 * V_15 ,
struct V_156 * V_158 ,
unsigned V_194
)
{
struct V_160 * V_54 = & V_158 -> V_165 [ V_194 ] ;
V_177 V_176 = V_54 -> V_176 ;
V_15 -> V_18 = F_6 ( V_3 ) ;
V_15 -> V_39 = V_36 -> V_139 ;
V_15 -> V_38 = V_36 -> V_185 ;
V_15 -> V_219 = V_54 -> V_175 ;
V_15 -> V_220 = F_6 ( V_3 ) ;
V_176 = V_54 -> V_176 ;
V_15 -> V_221 [ 0 ] = F_8 ( V_3 , V_176 ) ;
V_15 -> V_222 [ 0 ] = F_8 ( V_3 , V_176 >> 32 ) ;
V_15 -> V_221 [ 1 ] = F_8 ( V_3 , V_54 -> V_121 ) ;
if ( V_54 -> V_178 )
V_176 += 4096 ;
V_15 -> V_222 [ 1 ] = F_8 ( V_3 , V_176 >> 32 ) ;
V_15 -> V_194 = V_194 ;
}
static inline void
F_110 ( struct V_2 * V_3 , unsigned V_19 , struct V_147 * V_15 )
{
V_15 -> V_16 = V_3 -> V_22 [ V_19 ] ;
V_15 -> V_18 = V_3 -> V_4 [ V_19 ] ;
V_3 -> V_22 [ V_19 ] . V_15 = V_15 ;
V_15 -> V_19 = V_19 ;
F_37 () ;
V_3 -> V_4 [ V_19 ] = F_8 ( V_3 , V_15 -> V_150 | V_37 ) ;
}
static int
F_111 (
struct V_2 * V_3 ,
struct V_55 * V_55 ,
unsigned V_182 ,
struct V_114 * V_36
)
{
int V_165 ;
unsigned V_69 ;
struct V_156 * V_180 = V_55 -> V_111 ;
struct V_147 * V_15 ;
V_69 = V_36 -> V_69 ;
if ( F_43 ( & V_36 -> V_115 ) ) {
F_24 ( V_3 ) -> V_83 . V_84
+= V_36 -> V_124 ;
F_19 ( V_3 ,
L_29 ,
V_55 -> V_53 -> V_155 , V_36 -> V_107 & 0x0f ,
( V_36 -> V_107 & V_125 ) ? L_18 : L_19 ,
( V_69 >> 3 ) & ( V_3 -> V_57 - 1 ) ,
V_36 -> V_119 , F_2 ( V_3 , V_36 -> V_185 ) ) ;
}
if ( F_24 ( V_3 ) -> V_83 . V_197 == 0 ) {
if ( V_3 -> V_198 == 1 )
F_96 () ;
}
F_24 ( V_3 ) -> V_83 . V_197 ++ ;
for ( V_165 = 0 , V_15 = NULL ;
V_165 < V_55 -> V_164 ;
V_165 ++ ) {
F_57 ( F_43 ( & V_180 -> V_115 ) ) ;
V_15 = F_76 ( V_180 -> V_115 . V_142 ,
struct V_147 , V_148 ) ;
F_97 ( & V_15 -> V_148 , & V_36 -> V_115 ) ;
V_15 -> V_36 = F_79 ( V_36 ) ;
V_15 -> V_55 = V_55 ;
F_109 ( V_3 , V_36 , V_15 , V_180 , V_165 ) ;
F_110 ( V_3 , ( V_69 >> 3 ) & ( V_3 -> V_57 - 1 ) ,
V_15 ) ;
V_69 += V_36 -> V_119 << 3 ;
}
V_36 -> V_69 = V_69 & ( V_182 - 1 ) ;
F_83 ( V_36 , V_180 ) ;
V_55 -> V_111 = NULL ;
F_98 ( V_3 , V_199 ) ;
return F_21 ( V_3 ) ;
}
static unsigned
F_112 (
struct V_2 * V_3 ,
struct V_147 * V_15
) {
struct V_55 * V_55 = V_15 -> V_55 ;
struct V_200 * V_106 ;
T_3 V_201 ;
int V_202 = - 1 ;
struct V_114 * V_36 = V_15 -> V_36 ;
struct V_41 * V_53 ;
unsigned V_94 = false ;
V_202 = V_15 -> V_194 ;
V_106 = & V_55 -> V_169 [ V_202 ] ;
V_201 = F_36 ( V_3 , & V_15 -> V_219 ) ;
if ( V_201 & V_223 ) {
V_55 -> V_181 ++ ;
if ( V_201 & V_224 )
V_106 -> V_61 = F_66 ( V_55 -> V_118 )
? - V_205
: - V_206 ;
else if ( V_201 & V_225 )
V_106 -> V_61 = - V_208 ;
else
V_106 -> V_61 = - V_209 ;
} else {
V_106 -> V_61 = 0 ;
V_106 -> V_210 = V_106 -> V_166 - F_113 ( V_201 ) ;
V_55 -> V_210 += V_106 -> V_210 ;
}
if ( ( V_202 + 1 ) != V_55 -> V_164 )
goto V_96;
V_53 = V_55 -> V_53 ;
F_101 ( V_3 , V_55 , 0 ) ;
V_94 = true ;
V_55 = NULL ;
( void ) F_29 ( V_3 ) ;
F_24 ( V_3 ) -> V_83 . V_197 -- ;
if ( F_24 ( V_3 ) -> V_83 . V_197 == 0 ) {
if ( V_3 -> V_198 == 1 )
F_102 () ;
}
if ( F_103 ( & V_36 -> V_115 ) ) {
F_24 ( V_3 ) -> V_83 . V_84
-= V_36 -> V_124 ;
F_19 ( V_3 ,
L_24 ,
V_53 -> V_155 , V_36 -> V_107 & 0x0f ,
( V_36 -> V_107 & V_125 ) ? L_18 : L_19 ) ;
}
F_74 ( V_3 , V_36 ) ;
V_96:
V_15 -> V_55 = NULL ;
if ( V_3 -> V_212 != V_15 -> V_19 ) {
V_15 -> V_36 = NULL ;
F_104 ( & V_15 -> V_148 , & V_36 -> V_116 ) ;
F_74 ( V_3 , V_36 ) ;
} else {
F_104 ( & V_15 -> V_148 , & V_3 -> V_226 ) ;
if ( V_36 -> V_117 == 2 ) {
V_36 -> V_105 -> V_111 = NULL ;
V_36 -> V_105 = NULL ;
}
}
return V_94 ;
}
static int F_114 ( struct V_2 * V_3 , struct V_55 * V_55 ,
T_7 V_101 )
{
int V_61 = - V_214 ;
unsigned long V_103 ;
struct V_114 * V_36 ;
V_36 = F_80 ( V_3 , V_55 ) ;
if ( V_36 == NULL ) {
F_9 ( V_3 , L_25 ) ;
return - V_112 ;
}
if ( V_55 -> V_119 != V_36 -> V_119 ) {
F_9 ( V_3 , L_26 ,
V_36 -> V_119 , V_55 -> V_119 ) ;
goto V_96;
}
#ifdef F_106
F_9 ( V_3 ,
L_30 ,
V_55 , V_55 -> V_53 -> V_155 ,
F_65 ( V_55 -> V_118 ) ,
F_66 ( V_55 -> V_118 ) ? L_18 : L_19 ,
V_55 -> V_216 ) ;
#endif
V_61 = F_108 ( V_36 , V_3 , V_55 , V_101 ) ;
if ( V_61 < 0 ) {
F_9 ( V_3 , L_31 ) ;
goto V_96;
}
F_52 ( & V_3 -> V_108 , V_103 ) ;
if ( F_27 ( ! F_53 ( F_24 ( V_3 ) ) ) ) {
V_61 = - V_109 ;
goto V_110;
}
V_61 = F_54 ( F_24 ( V_3 ) , V_55 ) ;
if ( F_27 ( V_61 ) )
goto V_110;
V_61 = F_90 ( V_3 , V_55 , V_36 ) ;
if ( V_61 == 0 )
F_111 ( V_3 , V_55 , V_3 -> V_57 << 3 , V_36 ) ;
else
F_58 ( F_24 ( V_3 ) , V_55 ) ;
V_110:
F_59 ( & V_3 -> V_108 , V_103 ) ;
V_96:
if ( V_61 < 0 )
F_74 ( V_3 , V_36 ) ;
return V_61 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_143 * V_13 , * V_227 ;
struct V_147 * V_15 , * V_228 ;
F_115 (itd, n, &ehci->cached_itd_list, itd_list) {
struct V_114 * V_36 = V_13 -> V_36 ;
V_13 -> V_36 = NULL ;
F_104 ( & V_13 -> V_144 , & V_36 -> V_116 ) ;
F_74 ( V_3 , V_36 ) ;
}
F_115 (sitd, sn, &ehci->cached_sitd_list, sitd_list) {
struct V_114 * V_36 = V_15 -> V_36 ;
V_15 -> V_36 = NULL ;
F_104 ( & V_15 -> V_148 , & V_36 -> V_116 ) ;
F_74 ( V_3 , V_36 ) ;
}
}
static void
F_116 ( struct V_2 * V_3 )
{
unsigned V_229 , V_19 , clock , V_212 , V_182 ;
unsigned V_230 ;
V_182 = V_3 -> V_57 << 3 ;
V_229 = V_3 -> V_69 ;
if ( F_45 ( F_24 ( V_3 ) -> V_67 ) ) {
clock = F_25 ( V_3 , & V_3 -> V_63 -> V_70 ) ;
V_212 = ( clock >> 3 ) & ( V_3 -> V_57 - 1 ) ;
} else {
clock = V_229 + V_182 - 1 ;
V_212 = - 1 ;
}
if ( V_3 -> V_212 != V_212 ) {
F_33 ( V_3 ) ;
V_3 -> V_212 = V_212 ;
}
clock &= V_182 - 1 ;
V_212 = clock >> 3 ;
++ V_3 -> V_231 ;
for (; ; ) {
union V_1 V_29 , * V_232 ;
T_1 type , * V_23 ;
unsigned V_233 = false ;
V_19 = V_229 >> 3 ;
V_234:
V_232 = & V_3 -> V_22 [ V_19 ] ;
V_23 = & V_3 -> V_4 [ V_19 ] ;
V_29 . V_20 = V_232 -> V_20 ;
type = F_5 ( V_3 , * V_23 ) ;
V_230 = 0 ;
while ( V_29 . V_20 != NULL ) {
unsigned V_54 ;
union V_1 V_235 ;
int V_236 ;
V_236 = F_45 ( F_24 ( V_3 ) -> V_67 ) ;
switch ( F_2 ( V_3 , type ) ) {
case V_6 :
V_235 . V_7 = F_39 ( V_29 . V_7 ) ;
type = F_5 ( V_3 , V_29 . V_7 -> V_17 -> V_18 ) ;
V_29 = V_29 . V_7 -> V_8 ;
if ( V_235 . V_7 -> V_237 != V_3 -> V_231 ) {
V_230 = F_44 ( V_3 , V_235 . V_7 ) ;
if ( ! V_230 )
V_235 . V_7 -> V_237 = V_3 -> V_231 ;
if ( F_27 ( F_43 ( & V_235 . V_7 -> V_90 ) ||
V_235 . V_7 -> V_89 ) )
F_42 ( V_3 , V_235 . V_7 ) ;
}
F_41 ( V_235 . V_7 ) ;
break;
case V_9 :
if ( V_29 . V_10 -> V_34 != F_6 ( V_3 ) ) {
F_117 ( L_32 ) ;
}
type = F_5 ( V_3 , V_29 . V_10 -> V_18 ) ;
V_29 = V_29 . V_10 -> V_11 ;
break;
case V_12 :
if ( V_19 == V_212 && V_236 ) {
F_118 () ;
for ( V_54 = 0 ; V_54 < 8 ; V_54 ++ ) {
if ( V_29 . V_13 -> V_35 [ V_54 ] &
F_119 ( V_3 ) )
break;
}
if ( V_54 < 8 ) {
V_233 = true ;
V_232 = & V_29 . V_13 -> V_14 ;
V_23 = & V_29 . V_13 -> V_18 ;
type = F_5 ( V_3 ,
V_29 . V_13 -> V_18 ) ;
V_29 = * V_232 ;
break;
}
}
* V_232 = V_29 . V_13 -> V_14 ;
if ( ! V_3 -> V_25 ||
V_29 . V_13 -> V_18 != F_6 ( V_3 ) )
* V_23 = V_29 . V_13 -> V_18 ;
else
* V_23 = V_3 -> V_26 -> V_27 ;
type = F_5 ( V_3 , V_29 . V_13 -> V_18 ) ;
F_37 () ;
V_230 = F_99 ( V_3 , V_29 . V_13 ) ;
V_29 = * V_232 ;
break;
case V_37 :
if ( ( ( V_19 == V_212 ) ||
( ( ( V_19 + 1 ) & ( V_3 -> V_57 - 1 ) )
== V_212 ) )
&& V_236
&& ( V_29 . V_15 -> V_219 &
F_120 ( V_3 ) ) ) {
V_233 = true ;
V_232 = & V_29 . V_15 -> V_16 ;
V_23 = & V_29 . V_15 -> V_18 ;
type = F_5 ( V_3 ,
V_29 . V_15 -> V_18 ) ;
V_29 = * V_232 ;
break;
}
* V_232 = V_29 . V_15 -> V_16 ;
if ( ! V_3 -> V_25 ||
V_29 . V_15 -> V_18 != F_6 ( V_3 ) )
* V_23 = V_29 . V_15 -> V_18 ;
else
* V_23 = V_3 -> V_26 -> V_27 ;
type = F_5 ( V_3 , V_29 . V_15 -> V_18 ) ;
F_37 () ;
V_230 = F_112 ( V_3 , V_29 . V_15 ) ;
V_29 = * V_232 ;
break;
default:
F_117 ( L_33 ,
type , V_19 , V_29 . V_20 ) ;
V_29 . V_20 = NULL ;
}
if ( F_27 ( V_230 ) ) {
if ( F_63 ( V_3 -> V_62 > 0 ) )
goto V_234;
V_229 = clock ;
break;
}
}
if ( V_233 && F_45 ( F_24 ( V_3 ) -> V_67 ) ) {
V_3 -> V_69 = V_229 ;
break;
}
if ( V_229 == clock ) {
unsigned V_74 ;
if ( ! F_45 ( F_24 ( V_3 ) -> V_67 )
|| V_3 -> V_62 == 0 )
break;
V_3 -> V_69 = V_229 ;
V_74 = F_25 ( V_3 , & V_3 -> V_63 -> V_70 ) &
( V_182 - 1 ) ;
if ( V_229 == V_74 )
break;
clock = V_74 ;
V_212 = clock >> 3 ;
if ( V_3 -> V_212 != V_212 ) {
F_33 ( V_3 ) ;
V_3 -> V_212 = V_212 ;
++ V_3 -> V_231 ;
}
} else {
V_229 ++ ;
V_229 &= V_182 - 1 ;
}
}
}
