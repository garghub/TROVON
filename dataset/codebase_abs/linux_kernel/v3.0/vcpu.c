void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
}
void F_2 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
V_6 = F_3 () ;
F_4 ( V_7 << V_8 , V_2 -> V_3 . V_9 ) ;
F_5 () ;
F_4 ( V_10 << V_8 , V_2 -> V_3 . V_11 ) ;
F_5 () ;
F_6 ( V_6 ) ;
return;
}
void F_7 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
V_6 = F_3 () ;
F_4 ( V_7 << V_8 , V_2 -> V_3 . V_12 ) ;
F_5 () ;
F_4 ( V_10 << V_8 , V_2 -> V_3 . V_13 ) ;
F_5 () ;
F_6 ( V_6 ) ;
return;
}
static int F_8 ( struct V_14 V_15 , struct V_14 V_16 )
{
return V_17 [ F_9 ( V_15 ) ] [ F_9 ( V_16 ) ] ;
}
void F_10 ( struct V_1 * V_2 , struct V_14 V_18 ,
struct V_14 V_19 )
{
int V_20 ;
V_20 = F_8 ( V_18 , V_19 ) ;
switch ( V_20 ) {
case V_21 :
F_2 ( V_2 ) ;
V_2 -> V_3 . V_4 |= V_5 ;
break;
case V_22 :
F_7 ( V_2 ) ;
V_2 -> V_3 . V_4 &= ~ V_5 ;
break;
case V_23 :
break;
case V_24 :
break;
default:
break;
}
return;
}
void F_11 ( struct V_1 * V_2 , struct V_14 V_18 ,
struct V_14 V_19 )
{
if ( ( V_18 . V_25 != V_19 . V_25 )
|| ( V_18 . V_26 != V_19 . V_26 )
|| ( V_18 . V_27 != V_19 . V_27 ) )
F_10 ( V_2 , V_18 , V_19 ) ;
return;
}
void F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) ) {
V_2 -> V_3 . V_4 |= V_28 ;
F_7 ( V_2 ) ;
}
return;
}
void F_14 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
F_2 ( V_2 ) ;
V_2 -> V_3 . V_4 &= ~ V_28 ;
return;
}
static inline unsigned long
F_15 ( unsigned long V_29 , unsigned long V_30 , unsigned long V_31 )
{
V_31 += V_30 ;
if ( V_31 >= V_29 )
V_31 -= V_29 ;
return V_31 ;
}
static inline unsigned long F_16 ( struct V_32 * V_33 ,
long V_34 )
{
unsigned long V_35 = ( V_33 -> V_36 >> 25 ) & 0x7f ;
return F_15 ( 96 , V_35 , ( V_34 - V_37 ) ) ;
}
static inline unsigned long * F_17 ( unsigned long * V_38 ,
long V_39 )
{
long V_40 = F_18 ( V_38 ) + V_39 ;
int V_41 = 0 ;
if ( V_39 < 0 )
V_40 -= 0x3e ;
if ( V_40 < 0 ) {
while ( V_40 <= - 0x3f ) {
V_41 -- ;
V_40 += 0x3f ;
}
} else {
while ( V_40 >= 0x3f ) {
V_41 ++ ;
V_40 -= 0x3f ;
}
}
return V_38 + V_39 + V_41 ;
}
static void F_19 ( struct V_32 * V_33 , unsigned long V_42 ,
unsigned long * V_43 , int * V_44 )
{
unsigned long * V_45 , * V_38 , * V_46 , * V_47 ;
unsigned long * V_48 = ( void * ) V_49 + V_50 ;
unsigned long V_51 ;
unsigned long V_52 , V_53 ;
long V_54 = ( V_33 -> V_36 ) & 0x7f ;
long V_29 = ( ( ( V_33 -> V_36 >> 14 ) & 0xf ) << 3 ) ;
long V_55 = ( V_33 -> V_36 >> 18 ) & 0x7f ;
long V_56 = V_42 - 32 ;
if ( V_56 < V_29 )
V_56 = F_15 ( V_29 , V_55 , V_56 ) ;
V_52 = F_20 ( V_57 ) ;
V_53 = V_52 & ( ~ ( 0x3 ) ) ;
F_21 ( V_57 , V_53 ) ;
V_47 = ( unsigned long * ) F_20 ( V_58 ) ;
V_45 = V_48 + ( V_33 -> V_59 >> 19 ) ;
V_38 = F_17 ( V_45 , - V_54 + V_56 ) ;
V_51 = 1UL << F_18 ( V_38 ) ;
V_46 = F_22 ( V_38 ) ;
if ( V_38 >= V_47 ) {
F_23 () ;
F_24 () ;
V_47 = ( unsigned long * ) F_20 ( V_58 ) ;
}
* V_43 = * V_38 ;
if ( V_44 ) {
if ( V_47 < V_46 )
* V_44 = ( int ) ! ! ( F_20 ( V_60 )
& V_51 ) ;
else
* V_44 = ( int ) ! ! ( ( * V_46 ) & V_51 ) ;
F_21 ( V_57 , V_52 ) ;
}
}
void F_25 ( struct V_32 * V_33 , unsigned long V_42 ,
unsigned long V_43 , unsigned long V_44 )
{
unsigned long * V_45 , * V_47 , * V_38 , * V_46 ;
unsigned long * V_48 = ( void * ) V_49 + V_50 ;
unsigned long V_51 ;
unsigned long V_52 , V_53 , V_6 ;
unsigned long V_61 ;
long V_54 = ( V_33 -> V_36 ) & 0x7f ;
long V_29 = ( ( ( V_33 -> V_36 >> 14 ) & 0xf ) << 3 ) ;
long V_55 = ( V_33 -> V_36 >> 18 ) & 0x7f ;
long V_56 = V_42 - 32 ;
if ( V_56 < V_29 )
V_56 = F_15 ( V_29 , V_55 , V_56 ) ;
V_52 = F_20 ( V_57 ) ;
V_53 = V_52 & ( ~ 0x3fff0003 ) ;
F_21 ( V_57 , V_53 ) ;
V_45 = V_48 + ( V_33 -> V_59 >> 19 ) ;
V_38 = F_17 ( V_45 , - V_54 + V_56 ) ;
V_51 = 1UL << F_18 ( V_38 ) ;
V_46 = F_22 ( V_38 ) ;
F_26 ( V_6 ) ;
V_47 = ( unsigned long * ) F_20 ( V_58 ) ;
if ( V_38 >= V_47 ) {
F_23 () ;
F_24 () ;
* V_38 = V_43 ;
V_47 = ( unsigned long * ) F_20 ( V_58 ) ;
V_61 = F_20 ( V_60 ) ;
if ( V_47 < V_46 )
V_61 = V_61 & ( ~ V_51 ) ;
else
* V_46 = ( * V_46 ) & ( ~ V_51 ) ;
F_24 () ;
F_27 () ;
F_21 ( V_60 , V_61 ) ;
} else {
V_61 = F_20 ( V_60 ) ;
* V_38 = V_43 ;
if ( V_47 < V_46 )
V_61 = V_61 & ( ~ V_51 ) ;
else
* V_46 = ( * V_46 ) & ( ~ V_51 ) ;
F_21 ( V_58 , ( unsigned long ) V_47 ) ;
F_21 ( V_60 , V_61 ) ;
}
F_28 ( V_6 ) ;
F_21 ( V_57 , V_52 ) ;
}
void F_29 ( unsigned long V_34 , unsigned long * V_43 ,
int * V_44 , struct V_32 * V_33 )
{
unsigned long V_38 , * V_62 ;
if ( V_34 >= V_63 ) {
F_19 ( V_33 , V_34 , V_43 , V_44 ) ;
return;
}
V_38 = ( unsigned long ) V_33 ;
V_62 = & V_33 -> V_64 ;
V_38 += V_65 [ V_34 ] ;
* V_43 = * ( unsigned long * ) V_38 ;
if ( V_44 )
* V_44 = ( * V_62 >> ( ( V_38 >> 3 ) & 0x3f ) ) & 0x1UL ;
}
void F_30 ( unsigned long V_34 , unsigned long V_43 ,
int V_44 , struct V_32 * V_33 )
{
unsigned long V_38 ;
unsigned long V_66 ;
unsigned long * V_62 ;
if ( V_34 >= V_63 ) {
F_25 ( V_33 , V_34 , V_43 , V_44 ) ;
return;
}
V_38 = ( unsigned long ) V_33 ;
V_62 = & V_33 -> V_64 ;
V_38 += V_65 [ V_34 ] ;
* ( unsigned long * ) V_38 = V_43 ;
V_66 = 1UL << ( ( V_38 >> 3 ) & 0x3f ) ;
if ( V_44 )
* V_62 |= V_66 ;
else
* V_62 &= ~ V_66 ;
}
T_1 F_31 ( struct V_1 * V_2 , unsigned long V_31 )
{
struct V_32 * V_33 = F_32 ( V_2 ) ;
unsigned long V_43 ;
if ( ! V_31 )
return 0 ;
F_29 ( V_31 , & V_43 , 0 , V_33 ) ;
return V_43 ;
}
void F_33 ( struct V_1 * V_2 , unsigned long V_31 , T_1 V_67 , int V_44 )
{
struct V_32 * V_33 = F_32 ( V_2 ) ;
long V_54 = ( V_33 -> V_36 ) & 0x7f ;
if ( ! V_31 )
return;
if ( V_31 >= V_54 + 32 )
return;
F_30 ( V_31 , V_67 , V_44 , V_33 ) ;
}
void F_34 ( unsigned long V_34 , struct V_68 * V_69 ,
struct V_32 * V_33 )
{
if ( V_34 >= V_37 )
V_34 = V_37 + F_16 ( V_33 , V_34 ) ;
#define F_35 ( V_31 ) \
case (reg) : \
ia64_stf_spill(fpval, reg); \
break
switch ( V_34 ) {
F_35 ( 0 ) ;
F_35 ( 1 ) ;
F_35 ( 2 ) ;
F_35 ( 3 ) ;
F_35 ( 4 ) ;
F_35 ( 5 ) ;
F_35 ( 6 ) ;
F_35 ( 7 ) ;
F_35 ( 8 ) ;
F_35 ( 9 ) ;
F_35 ( 10 ) ;
F_35 ( 11 ) ;
F_35 ( 12 ) ;
F_35 ( 13 ) ;
F_35 ( 14 ) ;
F_35 ( 15 ) ;
F_35 ( 16 ) ;
F_35 ( 17 ) ;
F_35 ( 18 ) ;
F_35 ( 19 ) ;
F_35 ( 20 ) ;
F_35 ( 21 ) ;
F_35 ( 22 ) ;
F_35 ( 23 ) ;
F_35 ( 24 ) ;
F_35 ( 25 ) ;
F_35 ( 26 ) ;
F_35 ( 27 ) ;
F_35 ( 28 ) ;
F_35 ( 29 ) ;
F_35 ( 30 ) ;
F_35 ( 31 ) ;
F_35 ( 32 ) ;
F_35 ( 33 ) ;
F_35 ( 34 ) ;
F_35 ( 35 ) ;
F_35 ( 36 ) ;
F_35 ( 37 ) ;
F_35 ( 38 ) ;
F_35 ( 39 ) ;
F_35 ( 40 ) ;
F_35 ( 41 ) ;
F_35 ( 42 ) ;
F_35 ( 43 ) ;
F_35 ( 44 ) ;
F_35 ( 45 ) ;
F_35 ( 46 ) ;
F_35 ( 47 ) ;
F_35 ( 48 ) ;
F_35 ( 49 ) ;
F_35 ( 50 ) ;
F_35 ( 51 ) ;
F_35 ( 52 ) ;
F_35 ( 53 ) ;
F_35 ( 54 ) ;
F_35 ( 55 ) ;
F_35 ( 56 ) ;
F_35 ( 57 ) ;
F_35 ( 58 ) ;
F_35 ( 59 ) ;
F_35 ( 60 ) ;
F_35 ( 61 ) ;
F_35 ( 62 ) ;
F_35 ( 63 ) ;
F_35 ( 64 ) ;
F_35 ( 65 ) ;
F_35 ( 66 ) ;
F_35 ( 67 ) ;
F_35 ( 68 ) ;
F_35 ( 69 ) ;
F_35 ( 70 ) ;
F_35 ( 71 ) ;
F_35 ( 72 ) ;
F_35 ( 73 ) ;
F_35 ( 74 ) ;
F_35 ( 75 ) ;
F_35 ( 76 ) ;
F_35 ( 77 ) ;
F_35 ( 78 ) ;
F_35 ( 79 ) ;
F_35 ( 80 ) ;
F_35 ( 81 ) ;
F_35 ( 82 ) ;
F_35 ( 83 ) ;
F_35 ( 84 ) ;
F_35 ( 85 ) ;
F_35 ( 86 ) ;
F_35 ( 87 ) ;
F_35 ( 88 ) ;
F_35 ( 89 ) ;
F_35 ( 90 ) ;
F_35 ( 91 ) ;
F_35 ( 92 ) ;
F_35 ( 93 ) ;
F_35 ( 94 ) ;
F_35 ( 95 ) ;
F_35 ( 96 ) ;
F_35 ( 97 ) ;
F_35 ( 98 ) ;
F_35 ( 99 ) ;
F_35 ( 100 ) ;
F_35 ( 101 ) ;
F_35 ( 102 ) ;
F_35 ( 103 ) ;
F_35 ( 104 ) ;
F_35 ( 105 ) ;
F_35 ( 106 ) ;
F_35 ( 107 ) ;
F_35 ( 108 ) ;
F_35 ( 109 ) ;
F_35 ( 110 ) ;
F_35 ( 111 ) ;
F_35 ( 112 ) ;
F_35 ( 113 ) ;
F_35 ( 114 ) ;
F_35 ( 115 ) ;
F_35 ( 116 ) ;
F_35 ( 117 ) ;
F_35 ( 118 ) ;
F_35 ( 119 ) ;
F_35 ( 120 ) ;
F_35 ( 121 ) ;
F_35 ( 122 ) ;
F_35 ( 123 ) ;
F_35 ( 124 ) ;
F_35 ( 125 ) ;
F_35 ( 126 ) ;
F_35 ( 127 ) ;
}
#undef F_35
}
void F_36 ( unsigned long V_34 , struct V_68 * V_69 ,
struct V_32 * V_33 )
{
if ( V_34 >= V_37 )
V_34 = V_37 + F_16 ( V_33 , V_34 ) ;
#define F_35 ( V_31 ) \
case (reg) : \
ia64_ldf_fill(reg, fpval); \
break
switch ( V_34 ) {
F_35 ( 2 ) ;
F_35 ( 3 ) ;
F_35 ( 4 ) ;
F_35 ( 5 ) ;
F_35 ( 6 ) ;
F_35 ( 7 ) ;
F_35 ( 8 ) ;
F_35 ( 9 ) ;
F_35 ( 10 ) ;
F_35 ( 11 ) ;
F_35 ( 12 ) ;
F_35 ( 13 ) ;
F_35 ( 14 ) ;
F_35 ( 15 ) ;
F_35 ( 16 ) ;
F_35 ( 17 ) ;
F_35 ( 18 ) ;
F_35 ( 19 ) ;
F_35 ( 20 ) ;
F_35 ( 21 ) ;
F_35 ( 22 ) ;
F_35 ( 23 ) ;
F_35 ( 24 ) ;
F_35 ( 25 ) ;
F_35 ( 26 ) ;
F_35 ( 27 ) ;
F_35 ( 28 ) ;
F_35 ( 29 ) ;
F_35 ( 30 ) ;
F_35 ( 31 ) ;
F_35 ( 32 ) ;
F_35 ( 33 ) ;
F_35 ( 34 ) ;
F_35 ( 35 ) ;
F_35 ( 36 ) ;
F_35 ( 37 ) ;
F_35 ( 38 ) ;
F_35 ( 39 ) ;
F_35 ( 40 ) ;
F_35 ( 41 ) ;
F_35 ( 42 ) ;
F_35 ( 43 ) ;
F_35 ( 44 ) ;
F_35 ( 45 ) ;
F_35 ( 46 ) ;
F_35 ( 47 ) ;
F_35 ( 48 ) ;
F_35 ( 49 ) ;
F_35 ( 50 ) ;
F_35 ( 51 ) ;
F_35 ( 52 ) ;
F_35 ( 53 ) ;
F_35 ( 54 ) ;
F_35 ( 55 ) ;
F_35 ( 56 ) ;
F_35 ( 57 ) ;
F_35 ( 58 ) ;
F_35 ( 59 ) ;
F_35 ( 60 ) ;
F_35 ( 61 ) ;
F_35 ( 62 ) ;
F_35 ( 63 ) ;
F_35 ( 64 ) ;
F_35 ( 65 ) ;
F_35 ( 66 ) ;
F_35 ( 67 ) ;
F_35 ( 68 ) ;
F_35 ( 69 ) ;
F_35 ( 70 ) ;
F_35 ( 71 ) ;
F_35 ( 72 ) ;
F_35 ( 73 ) ;
F_35 ( 74 ) ;
F_35 ( 75 ) ;
F_35 ( 76 ) ;
F_35 ( 77 ) ;
F_35 ( 78 ) ;
F_35 ( 79 ) ;
F_35 ( 80 ) ;
F_35 ( 81 ) ;
F_35 ( 82 ) ;
F_35 ( 83 ) ;
F_35 ( 84 ) ;
F_35 ( 85 ) ;
F_35 ( 86 ) ;
F_35 ( 87 ) ;
F_35 ( 88 ) ;
F_35 ( 89 ) ;
F_35 ( 90 ) ;
F_35 ( 91 ) ;
F_35 ( 92 ) ;
F_35 ( 93 ) ;
F_35 ( 94 ) ;
F_35 ( 95 ) ;
F_35 ( 96 ) ;
F_35 ( 97 ) ;
F_35 ( 98 ) ;
F_35 ( 99 ) ;
F_35 ( 100 ) ;
F_35 ( 101 ) ;
F_35 ( 102 ) ;
F_35 ( 103 ) ;
F_35 ( 104 ) ;
F_35 ( 105 ) ;
F_35 ( 106 ) ;
F_35 ( 107 ) ;
F_35 ( 108 ) ;
F_35 ( 109 ) ;
F_35 ( 110 ) ;
F_35 ( 111 ) ;
F_35 ( 112 ) ;
F_35 ( 113 ) ;
F_35 ( 114 ) ;
F_35 ( 115 ) ;
F_35 ( 116 ) ;
F_35 ( 117 ) ;
F_35 ( 118 ) ;
F_35 ( 119 ) ;
F_35 ( 120 ) ;
F_35 ( 121 ) ;
F_35 ( 122 ) ;
F_35 ( 123 ) ;
F_35 ( 124 ) ;
F_35 ( 125 ) ;
F_35 ( 126 ) ;
F_35 ( 127 ) ;
}
}
void F_37 ( struct V_1 * V_2 , unsigned long V_31 ,
struct V_68 * V_43 )
{
struct V_32 * V_33 = F_32 ( V_2 ) ;
F_34 ( V_31 , V_43 , V_33 ) ;
}
void F_38 ( struct V_1 * V_2 , unsigned long V_31 ,
struct V_68 * V_43 )
{
struct V_32 * V_33 = F_32 ( V_2 ) ;
if ( V_31 > 1 )
F_36 ( V_31 , V_43 , V_33 ) ;
}
static long F_39 ( struct V_1 * V_2 )
{
#if F_40 ( V_70 ) || F_40 ( V_71 )
struct V_72 * V_72 = (struct V_72 * ) V_73 ;
if ( V_72 -> V_3 . V_74 )
return ( * V_75 ) ;
else
#endif
return F_20 ( V_76 ) ;
}
T_1 F_41 ( struct V_1 * V_2 )
{
unsigned long V_77 ;
V_77 = F_42 ( V_2 , V_78 ) + F_39 ( V_2 ) ;
if ( V_77 >= F_42 ( V_2 , V_79 ) ) {
F_42 ( V_2 , V_79 ) = V_77 ;
return V_77 ;
} else
return F_42 ( V_2 , V_79 ) ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_43 )
{
struct V_1 * V_80 ;
struct V_72 * V_72 ;
int V_41 ;
long V_78 = V_43 - F_39 ( V_2 ) ;
unsigned long V_81 = F_44 ( V_2 , V_82 ) ;
V_72 = (struct V_72 * ) V_73 ;
if ( F_45 ( V_2 ) ) {
for ( V_41 = 0 ; V_41 < F_46 ( & V_72 -> V_83 ) ; V_41 ++ ) {
V_80 = (struct V_1 * ) ( ( char * ) V_2 +
sizeof( struct V_84 ) * V_41 ) ;
F_42 ( V_80 , V_78 ) = V_78 ;
F_42 ( V_80 , V_79 ) = 0 ;
}
}
F_42 ( V_2 , V_79 ) = 0 ;
if ( F_44 ( V_2 , V_85 ) <= V_43 ) {
F_42 ( V_2 , V_86 ) = 0 ;
F_47 ( V_2 , V_81 ) ;
} else {
F_42 ( V_2 , V_86 ) = 1 ;
F_48 ( V_2 , F_44 ( V_2 , V_85 ) ) ;
}
}
static inline T_1 F_49 ( struct V_1 * V_2 )
{
return ( ( T_1 ) F_44 ( V_2 , V_85 ) ) ;
}
static inline void F_48 ( struct V_1 * V_2 , T_1 V_43 )
{
unsigned long V_81 = F_44 ( V_2 , V_82 ) ;
F_44 ( V_2 , V_85 ) = V_43 ;
if ( V_43 > F_41 ( V_2 ) ) {
F_42 ( V_2 , V_86 ) = 1 ;
F_47 ( V_2 , V_81 ) ;
F_42 ( V_2 , V_87 ) = 0 ;
} else
F_42 ( V_2 , V_86 ) = 0 ;
}
static inline void F_50 ( struct V_1 * V_2 , T_1 V_43 )
{
F_44 ( V_2 , V_82 ) = V_43 ;
if ( ! F_51 ( V_43 ) && V_2 -> V_3 . V_87 ) {
F_52 ( V_2 , F_53 ( V_43 ) ) ;
V_2 -> V_3 . V_87 = 0 ;
}
}
static inline void F_54 ( struct V_1 * V_2 , T_1 V_43 )
{
int V_88 ;
V_88 = F_55 ( V_2 ) ;
if ( V_88 == V_89 )
return;
F_42 ( V_2 , V_90 [ V_88 >> 6 ] ) &= ~ ( 1UL << ( V_88 & 63 ) ) ;
F_44 ( V_2 , V_91 ) = 0 ;
V_2 -> V_3 . V_92 = 1 ;
}
int F_56 ( struct V_1 * V_2 , int V_93 , int V_94 )
{
union V_95 V_96 ;
V_96 . V_43 = F_44 ( V_2 , V_97 ) ;
if ( V_94 == V_98 )
return V_99 ;
if ( V_93 == V_98 ) {
return V_100 ;
}
if ( V_94 == V_101 )
return V_99 ;
if ( V_93 == V_101 ) {
if ( V_96 . V_102 ) {
return V_103 ;
} else
return V_100 ;
}
if ( F_57 ( V_93 , V_94 ) ) {
if ( F_58 ( V_93 , V_96 . V_104 + ( V_96 . V_102 << 4 ) ) )
return V_100 ;
else
return V_103 ;
} else {
return V_99 ;
}
}
void F_52 ( struct V_1 * V_2 , T_2 V_88 )
{
long V_105 ;
int V_106 ;
F_26 ( V_105 ) ;
V_106 = F_59 ( V_88 , & F_44 ( V_2 , V_107 [ 0 ] ) ) ;
F_28 ( V_105 ) ;
V_2 -> V_3 . V_92 = 1 ;
}
void F_47 ( struct V_1 * V_2 , T_2 V_88 )
{
long V_105 ;
int V_106 ;
F_26 ( V_105 ) ;
V_106 = F_60 ( V_88 , & F_44 ( V_2 , V_107 [ 0 ] ) ) ;
F_28 ( V_105 ) ;
if ( V_106 ) {
V_2 -> V_3 . V_92 = 1 ;
F_61 () ;
}
}
void F_62 ( struct V_1 * V_2 , int V_88 )
{
T_1 V_108 ;
if ( V_88 == V_89 )
V_108 = 0 ;
else if ( V_88 == V_98 )
V_108 = 32 ;
else if ( V_88 == V_101 )
V_108 = 16 ;
else
V_108 = V_88 >> 4 ;
F_44 ( V_2 , V_108 ) = V_108 ;
if ( F_44 ( V_2 , V_109 ) . V_110 )
F_63 ( V_111 ,
( T_1 ) V_2 -> V_3 . V_112 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
}
T_1 F_64 ( struct V_1 * V_2 )
{
int V_88 , V_94 , V_113 ;
V_88 = F_65 ( V_2 ) ;
V_94 = F_55 ( V_2 ) ;
V_113 = F_56 ( V_2 , V_88 , V_94 ) ;
if ( V_88 == V_89 || V_113 == V_99 ) {
if ( F_44 ( V_2 , V_108 ) )
F_62 ( V_2 , V_89 ) ;
return V_114 ;
}
if ( V_113 == V_103 ) {
F_62 ( V_2 , V_88 ) ;
return V_114 ;
}
F_42 ( V_2 , V_90 [ V_88 >> 6 ] ) |= ( 1UL << ( V_88 & 63 ) ) ;
F_47 ( V_2 , V_88 ) ;
return ( T_1 ) V_88 ;
}
T_1 F_66 ( struct V_1 * V_2 , T_1 V_115 )
{
union V_116 V_117 ;
union V_118 V_119 ;
T_1 V_120 ;
T_1 V_121 ;
V_117 . V_43 = F_67 ( V_2 ) ;
V_119 . V_43 = F_68 ( V_2 , V_115 ) ;
V_121 = ( ( V_115 >> V_119 . V_122 ) << 3 ) & ( ( 1UL << ( V_117 . V_123 ) ) - 1 ) ;
if ( V_117 . V_124 ) {
V_120 = F_63 ( V_125 , V_115 , V_119 . V_43 ,
V_117 . V_43 , 0 , 0 , 0 , 0 ) ;
} else {
V_120 = ( V_115 & V_126 ) | V_121 |
( V_117 . V_43 << 3 >> ( V_117 . V_123 + 3 ) << ( V_117 . V_123 ) ) ;
}
return V_120 ;
}
T_1 F_69 ( struct V_1 * V_2 , T_1 V_115 )
{
union V_118 V_119 ;
union V_116 V_117 ;
T_1 V_120 ;
V_117 . V_43 = F_67 ( V_2 ) ;
V_119 . V_43 = F_68 ( V_2 , V_115 ) ;
if ( V_117 . V_124 ) {
V_120 = F_63 ( V_127 , V_115 , V_119 . V_43 ,
0 , 0 , 0 , 0 , 0 ) ;
} else
V_120 = 1 ;
return V_120 ;
}
T_1 F_70 ( struct V_1 * V_2 , T_1 V_115 )
{
struct V_128 * V_129 ;
union V_116 V_117 ;
T_1 V_130 ;
V_117 . V_43 = F_67 ( V_2 ) ;
if ( V_117 . V_124 == 0 ) {
V_130 = 1 ;
return V_130 ;
}
V_129 = F_71 ( V_2 , V_115 , V_131 ) ;
if ( ! V_129 || ! V_129 -> V_132 )
V_130 = 1 ;
else
V_130 = V_129 -> V_130 ;
return V_130 ;
}
void F_72 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_134 , V_115 ;
V_115 = F_31 ( V_2 , V_133 . V_135 . V_136 ) ;
V_134 = F_66 ( V_2 , V_115 ) ;
F_33 ( V_2 , V_133 . V_135 . V_42 , V_134 , 0 ) ;
}
void F_73 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_137 , V_115 ;
V_115 = F_31 ( V_2 , V_133 . V_135 . V_136 ) ;
V_137 = F_69 ( V_2 , V_115 ) ;
F_33 ( V_2 , V_133 . V_135 . V_42 , V_137 , 0 ) ;
}
int F_74 ( struct V_1 * V_2 , T_1 V_115 , unsigned long * V_138 )
{
struct V_128 * V_129 ;
union V_139 V_140 , V_141 ;
struct V_32 * V_33 ;
struct V_14 V_142 ;
V_33 = F_32 ( V_2 ) ;
V_141 . V_43 = F_42 ( V_2 , V_143 ) ;
V_140 . V_43 = 0 ;
V_140 . V_144 = V_141 . V_144 ;
V_140 . V_145 = V_141 . V_145 ;
V_142 = * (struct V_14 * ) & F_44 ( V_2 , V_142 ) ;
V_140 . V_146 = 1 ;
V_129 = F_75 ( V_115 ) ;
if ( V_129 ) {
if ( V_129 -> V_132 == 0 ) {
F_76 ( V_2 , V_140 . V_43 ) ;
F_77 ( V_2 , V_115 ) ;
return V_147 ;
} else if ( V_129 -> V_148 == V_149 ) {
F_76 ( V_2 , V_140 . V_43 ) ;
F_78 ( V_2 , V_115 ) ;
return V_147 ;
} else {
* V_138 = ( V_129 -> V_150 >> V_129 -> V_122 << V_129 -> V_122 ) |
( V_115 & ( F_79 ( V_129 -> V_122 ) - 1 ) ) ;
return V_151 ;
}
}
V_129 = F_71 ( V_2 , V_115 , V_131 ) ;
if ( V_129 ) {
if ( V_129 -> V_132 == 0 ) {
F_76 ( V_2 , V_140 . V_43 ) ;
F_77 ( V_2 , V_115 ) ;
return V_147 ;
} else if ( V_129 -> V_148 == V_149 ) {
F_76 ( V_2 , V_140 . V_43 ) ;
F_78 ( V_2 , V_115 ) ;
return V_147 ;
} else{
* V_138 = ( ( V_129 -> V_152 >> ( V_129 -> V_122 - 12 ) ) << V_129 -> V_122 )
| ( V_115 & ( F_79 ( V_129 -> V_122 ) - 1 ) ) ;
return V_151 ;
}
}
if ( ! F_80 ( V_2 , V_115 , V_153 ) ) {
if ( V_142 . V_154 ) {
F_76 ( V_2 , V_140 . V_43 ) ;
F_81 ( V_2 , V_115 ) ;
return V_147 ;
} else {
F_82 ( V_2 ) ;
return V_147 ;
}
} else {
if ( V_142 . V_154 ) {
F_76 ( V_2 , V_140 . V_43 ) ;
F_83 ( V_2 , V_115 ) ;
return V_147 ;
} else{
F_82 ( V_2 ) ;
return V_147 ;
}
}
return V_151 ;
}
int F_84 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_42 , V_136 ;
V_136 = F_31 ( V_2 , V_133 . V_135 . V_136 ) ;
if ( F_74 ( V_2 , V_136 , & V_42 ) )
return V_147 ;
F_33 ( V_2 , V_133 . V_135 . V_42 , V_42 , 0 ) ;
return ( V_151 ) ;
}
void F_85 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_42 , V_136 ;
V_136 = F_31 ( V_2 , V_133 . V_135 . V_136 ) ;
V_42 = F_70 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_135 . V_42 , V_42 , 0 ) ;
}
void F_86 ( struct V_1 * V_2 , T_1 V_155 , T_1 V_156 , T_1 V_157 )
{
F_87 ( V_2 , V_155 , V_156 , V_157 , V_158 ) ;
}
void F_88 ( struct V_1 * V_2 , T_1 V_155 , T_1 V_156 , T_1 V_157 )
{
F_87 ( V_2 , V_155 , V_156 , V_157 , V_131 ) ;
}
void F_89 ( struct V_1 * V_2 , T_1 V_159 , T_1 V_155 , T_1 V_156 , T_1 V_157 )
{
T_1 V_122 , V_160 , V_161 ;
struct V_128 * V_162 ;
V_122 = F_90 ( V_156 ) ;
V_160 = F_91 ( V_157 , V_122 ) ;
V_155 &= ~ V_163 ;
V_161 = F_68 ( V_2 , V_157 ) ;
V_161 = V_161 & V_164 ;
V_162 = (struct V_128 * ) & V_2 -> V_3 . V_165 [ V_159 ] ;
F_92 ( V_162 , V_155 , V_156 , V_160 , V_161 ) ;
F_93 ( F_42 ( V_2 , V_166 ) , V_160 ) ;
}
void F_94 ( struct V_1 * V_2 , T_1 V_159 , T_1 V_155 , T_1 V_156 , T_1 V_157 )
{
T_1 V_167 ;
T_1 V_122 , V_160 , V_161 ;
struct V_128 * V_168 ;
V_122 = F_90 ( V_156 ) ;
V_160 = F_91 ( V_157 , V_122 ) ;
V_155 &= ~ V_163 ;
if ( V_122 != V_169 )
F_95 ( V_2 , V_160 , V_122 ) ;
V_167 = ( V_155 & V_170 ) >> V_171 ;
if ( F_96 ( V_167 ) )
V_155 |= V_172 ;
V_161 = F_68 ( V_2 , V_160 ) ;
V_161 = V_161 & V_164 ;
V_168 = (struct V_128 * ) & V_2 -> V_3 . V_173 [ V_159 ] ;
F_92 ( (struct V_128 * ) & V_2 -> V_3 . V_173 [ V_159 ] ,
V_155 , V_156 , V_160 , V_161 ) ;
F_93 ( F_42 ( V_2 , V_174 ) , V_160 ) ;
}
void F_97 ( struct V_1 * V_2 , T_1 V_157 , T_1 V_122 )
{
int V_175 ;
T_1 V_160 ;
V_160 = F_91 ( V_157 , V_122 ) ;
while ( ( V_175 = F_98 ( V_2 , V_160 , V_122 , V_131 ) ) >= 0 )
V_2 -> V_3 . V_173 [ V_175 ] . V_176 = 0 ;
F_95 ( V_2 , V_160 , V_122 ) ;
}
void F_99 ( struct V_1 * V_2 , T_1 V_157 , T_1 V_122 )
{
int V_175 ;
T_1 V_160 ;
V_160 = F_91 ( V_157 , V_122 ) ;
while ( ( V_175 = F_98 ( V_2 , V_160 , V_122 , V_158 ) ) >= 0 )
V_2 -> V_3 . V_165 [ V_175 ] . V_176 = 0 ;
F_95 ( V_2 , V_160 , V_122 ) ;
}
void F_100 ( struct V_1 * V_2 , T_1 V_160 , T_1 V_122 )
{
V_160 = F_91 ( V_160 , V_122 ) ;
F_95 ( V_2 , V_160 , V_122 ) ;
}
void F_101 ( struct V_1 * V_2 , T_1 V_160 )
{
F_102 ( V_2 ) ;
}
void F_103 ( struct V_1 * V_2 , T_1 V_160 , T_1 V_122 )
{
struct V_177 * V_132 = & V_2 -> V_3 . V_178 ;
long V_6 ;
F_26 ( V_6 ) ;
V_132 -> V_179 = V_180 ;
V_132 -> V_181 . V_182 . V_183 = F_68 ( V_2 , V_160 ) ;
V_132 -> V_181 . V_182 . V_184 = V_160 ;
V_132 -> V_181 . V_182 . V_122 = V_122 ;
F_104 ( V_2 ) ;
F_100 ( V_2 , V_160 , V_122 ) ;
F_28 ( V_6 ) ;
}
void F_105 ( struct V_1 * V_2 , T_1 V_160 , T_1 V_122 )
{
F_103 ( V_2 , V_160 , V_122 ) ;
}
void F_106 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_157 ;
V_157 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
F_101 ( V_2 , V_157 ) ;
}
void F_107 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_157 , V_156 ;
V_157 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_156 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_105 ( V_2 , V_157 , F_90 ( V_156 ) ) ;
}
void F_108 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_157 , V_156 ;
V_157 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_156 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_103 ( V_2 , V_157 , F_90 ( V_156 ) ) ;
}
void F_109 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_157 , V_156 ;
V_157 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_156 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_100 ( V_2 , V_157 , F_90 ( V_156 ) ) ;
}
void F_110 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_157 , V_156 ;
V_157 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_156 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_97 ( V_2 , V_157 , F_90 ( V_156 ) ) ;
}
void F_111 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_157 , V_156 ;
V_157 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_156 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_99 ( V_2 , V_157 , F_90 ( V_156 ) ) ;
}
void F_112 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_156 , V_157 , V_155 , V_159 ;
V_159 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_155 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
V_156 = F_113 ( V_2 ) ;
V_157 = F_114 ( V_2 ) ;
F_94 ( V_2 , V_159 , V_155 , V_156 , V_157 ) ;
}
void F_115 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_156 , V_157 , V_155 , V_159 ;
V_159 = F_31 ( V_2 , V_133 . V_185 . V_136 ) ;
V_155 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
V_156 = F_113 ( V_2 ) ;
V_157 = F_114 ( V_2 ) ;
F_89 ( V_2 , V_159 , V_155 , V_156 , V_157 ) ;
}
void F_116 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_156 , V_157 , V_155 ;
V_156 = F_113 ( V_2 ) ;
V_157 = F_114 ( V_2 ) ;
V_155 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_88 ( V_2 , V_155 , V_156 , V_157 ) ;
}
void F_117 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_156 , V_157 , V_155 ;
V_156 = F_113 ( V_2 ) ;
V_157 = F_114 ( V_2 ) ;
V_155 = F_31 ( V_2 , V_133 . V_185 . V_186 ) ;
F_86 ( V_2 , V_155 , V_156 , V_157 ) ;
}
void F_118 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_187 ;
if ( V_133 . V_188 . V_189 )
V_187 = - V_133 . V_188 . V_187 ;
else
V_187 = V_133 . V_188 . V_187 ;
F_43 ( V_2 , V_187 ) ;
}
void F_119 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_186 ;
V_186 = F_31 ( V_2 , V_133 . V_190 . V_186 ) ;
F_43 ( V_2 , V_186 ) ;
}
void F_120 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_42 ;
V_42 = F_41 ( V_2 ) ;
F_33 ( V_2 , V_133 . V_191 . V_42 , V_42 , 0 ) ;
}
unsigned long F_121 ( struct V_1 * V_2 , unsigned long V_31 )
{
return ( ( unsigned long ) F_122 ( V_31 ) ) ;
}
void F_123 ( struct V_1 * V_2 , unsigned long V_31 , unsigned long V_43 )
{
F_124 ( V_31 , V_43 ) ;
}
unsigned long F_125 ( struct V_1 * V_2 , unsigned long V_31 ,
unsigned long V_43 )
{
union V_118 V_192 , V_193 ;
unsigned long V_194 ;
struct V_177 * V_132 = & V_2 -> V_3 . V_178 ;
unsigned long V_6 ;
V_192 . V_43 = F_68 ( V_2 , V_31 ) ;
V_193 . V_43 = V_43 ;
V_2 -> V_3 . V_119 [ V_31 >> V_8 ] = V_43 ;
switch ( ( unsigned long ) ( V_31 >> V_8 ) ) {
case V_195 :
V_2 -> V_3 . V_196 = F_126 ( V_43 ) ;
F_26 ( V_6 ) ;
V_132 -> V_179 = V_197 ;
F_104 ( V_2 ) ;
F_28 ( V_6 ) ;
break;
case V_10 :
V_194 = F_126 ( V_43 ) ;
V_2 -> V_3 . V_13 = V_194 ;
if ( ! F_13 ( V_2 ) )
F_4 ( V_31 , V_194 ) ;
break;
case V_7 :
V_194 = F_126 ( V_43 ) ;
V_2 -> V_3 . V_12 = V_194 ;
if ( ! F_13 ( V_2 ) )
F_4 ( V_31 , V_194 ) ;
break;
default:
F_4 ( V_31 , F_126 ( V_43 ) ) ;
break;
}
return ( V_151 ) ;
}
void F_127 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_186 ;
V_136 = F_31 ( V_2 , V_133 . V_198 . V_136 ) ;
V_186 = F_31 ( V_2 , V_133 . V_198 . V_186 ) ;
F_125 ( V_2 , V_136 , V_186 ) ;
}
void F_128 ( struct V_1 * V_2 , T_3 V_133 )
{
}
void F_129 ( struct V_1 * V_2 , T_3 V_133 )
{
}
void F_130 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_186 ;
V_136 = F_31 ( V_2 , V_133 . V_198 . V_136 ) ;
V_186 = F_31 ( V_2 , V_133 . V_198 . V_186 ) ;
F_131 ( V_2 , V_136 , V_186 ) ;
}
void F_132 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_186 ;
V_136 = F_31 ( V_2 , V_133 . V_198 . V_136 ) ;
V_186 = F_31 ( V_2 , V_133 . V_198 . V_186 ) ;
F_133 ( V_2 , V_136 , V_186 ) ;
}
void F_134 ( struct V_1 * V_2 , T_3 V_133 )
{
T_1 V_136 , V_186 ;
V_136 = F_31 ( V_2 , V_133 . V_198 . V_136 ) ;
V_186 = F_31 ( V_2 , V_133 . V_198 . V_186 ) ;
F_123 ( V_2 , V_136 , V_186 ) ;
}
void F_135 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_42 ;
V_136 = F_31 ( V_2 , V_133 . V_199 . V_136 ) ;
V_42 = F_68 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_199 . V_42 , V_42 , 0 ) ;
}
void F_136 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_42 ;
V_136 = F_31 ( V_2 , V_133 . V_199 . V_136 ) ;
V_42 = F_121 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_199 . V_42 , V_42 , 0 ) ;
}
void F_137 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_42 ;
V_136 = F_31 ( V_2 , V_133 . V_199 . V_136 ) ;
V_42 = F_138 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_199 . V_42 , V_42 , 0 ) ;
}
void F_139 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_42 ;
V_136 = F_31 ( V_2 , V_133 . V_199 . V_136 ) ;
V_42 = F_140 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_199 . V_42 , V_42 , 0 ) ;
}
void F_141 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_42 ;
V_136 = F_31 ( V_2 , V_133 . V_199 . V_136 ) ;
V_42 = F_142 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_199 . V_42 , V_42 , 0 ) ;
}
unsigned long F_143 ( struct V_1 * V_2 , unsigned long V_31 )
{
if ( V_31 > ( F_144 ( 3 ) & 0xff ) )
return 0 ;
else
return F_144 ( V_31 ) ;
}
void F_145 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_136 , V_42 ;
V_136 = F_31 ( V_2 , V_133 . V_199 . V_136 ) ;
V_42 = F_143 ( V_2 , V_136 ) ;
F_33 ( V_2 , V_133 . V_199 . V_42 , V_42 , 0 ) ;
}
void F_146 ( struct V_1 * V_2 , unsigned long V_43 )
{
F_44 ( V_2 , V_97 ) = V_43 ;
V_2 -> V_3 . V_200 = 1 ;
}
unsigned long F_147 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_186 ;
V_186 = F_31 ( V_2 , V_133 . V_201 . V_186 ) ;
F_44 ( V_2 , V_202 [ V_133 . V_201 . V_203 ] ) = V_186 ;
switch ( V_133 . V_201 . V_203 ) {
case 0 :
F_148 ( V_2 , V_186 ) ;
break;
case 1 :
F_48 ( V_2 , V_186 ) ;
break;
case 66 :
F_146 ( V_2 , V_186 ) ;
break;
case 67 :
F_54 ( V_2 , V_186 ) ;
break;
default:
break;
}
return 0 ;
}
unsigned long F_149 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_204 = V_133 . V_205 . V_42 ;
unsigned long V_43 ;
switch ( V_133 . V_205 . V_203 ) {
case 65 :
V_43 = F_64 ( V_2 ) ;
F_33 ( V_2 , V_204 , V_43 , 0 ) ;
break;
case 67 :
F_33 ( V_2 , V_204 , 0L , 0 ) ;
break;
default:
V_43 = F_44 ( V_2 , V_202 [ V_133 . V_205 . V_203 ] ) ;
F_33 ( V_2 , V_204 , V_43 , 0 ) ;
break;
}
return 0 ;
}
void F_150 ( struct V_1 * V_2 , unsigned long V_43 )
{
unsigned long V_113 ;
struct V_32 * V_33 ;
struct V_14 V_18 , V_19 ;
V_18 = * (struct V_14 * ) & F_44 ( V_2 , V_142 ) ;
V_33 = F_32 ( V_2 ) ;
if ( V_43 & ( V_206 | V_207 | V_208 ) )
F_151 ( V_2 , L_1
L_2 ) ;
F_44 ( V_2 , V_142 ) = V_43
& ( ~ ( V_209 | V_210 | V_211 |
V_212 | V_213 | V_214 ) ) ;
if ( ! V_18 . V_41 && ( V_43 & V_215 ) ) {
V_2 -> V_3 . V_200 = 1 ;
}
V_19 = * (struct V_14 * ) & F_44 ( V_2 , V_142 ) ;
V_113 = V_216 + V_215 + V_217 + V_218 +
V_219 + V_220 + V_221 + V_222 +
V_208 ;
V_33 -> V_223 = ( V_33 -> V_223 & V_113 ) | ( V_43 & ( ~ V_113 ) ) ;
F_11 ( V_2 , V_18 , V_19 ) ;
return ;
}
unsigned long F_152 ( struct V_1 * V_2 )
{
struct V_14 V_142 ;
struct V_32 * V_33 = F_32 ( V_2 ) ;
V_142 = * (struct V_14 * ) & F_44 ( V_2 , V_142 ) ;
if ( ! V_142 . V_154 )
F_44 ( V_2 , V_224 ) = V_33 -> V_36 ;
V_33 -> V_36 = V_225 ;
return ( V_151 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
unsigned long V_41 ;
struct V_32 * V_33 = F_32 ( V_2 ) ;
unsigned long * V_226 = & V_33 -> V_227 ;
unsigned long * V_228 = & F_44 ( V_2 , V_229 [ 0 ] ) ;
unsigned long * V_230 = & F_44 ( V_2 , V_231 [ 0 ] ) ;
unsigned long * V_232 = & V_33 -> V_64 ;
unsigned long * V_233 = & F_44 ( V_2 , V_234 ) ;
unsigned long * V_235 = & F_44 ( V_2 , V_236 ) ;
if ( F_44 ( V_2 , V_142 ) & V_222 ) {
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ ) {
* V_230 ++ = * V_226 ;
* V_226 ++ = * V_228 ++ ;
}
F_154 ( V_41 , V_233 , V_235 , V_232 ,
V_237 ) ;
F_44 ( V_2 , V_142 ) &= ~ V_222 ;
}
}
void F_155 ( struct V_1 * V_2 )
{
unsigned long V_41 ;
struct V_32 * V_33 = F_32 ( V_2 ) ;
unsigned long * V_226 = & V_33 -> V_227 ;
unsigned long * V_228 = & F_44 ( V_2 , V_229 [ 0 ] ) ;
unsigned long * V_230 = & F_44 ( V_2 , V_231 [ 0 ] ) ;
unsigned long * V_232 = & V_33 -> V_64 ;
unsigned long * V_233 = & F_44 ( V_2 , V_234 ) ;
unsigned long * V_235 = & F_44 ( V_2 , V_236 ) ;
if ( ! ( F_44 ( V_2 , V_142 ) & V_222 ) ) {
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ ) {
* V_228 ++ = * V_226 ;
* V_226 ++ = * V_230 ++ ;
}
F_156 ( V_41 , V_233 , V_235 , V_232 ,
V_237 ) ;
F_44 ( V_2 , V_142 ) |= V_222 ;
}
}
void F_157 ( struct V_1 * V_2 )
{
unsigned long V_224 , V_6 ;
struct V_32 * V_33 = F_32 ( V_2 ) ;
V_6 = F_44 ( V_2 , V_238 ) ;
if ( V_6 & V_222 )
F_155 ( V_2 ) ;
else
F_153 ( V_2 ) ;
F_150 ( V_2 , V_6 ) ;
V_224 = F_44 ( V_2 , V_224 ) ;
if ( V_224 >> 63 )
V_33 -> V_36 = V_224 ;
V_33 -> V_239 = F_44 ( V_2 , V_240 ) ;
}
unsigned long F_158 ( struct V_1 * V_2 )
{
unsigned long V_113 ;
struct V_32 * V_33 = F_32 ( V_2 ) ;
V_113 = V_241 | V_242 | V_243 | V_244 |
V_245 | V_246 | V_247 ;
return ( F_44 ( V_2 , V_142 ) & ~ V_113 ) | ( V_33 -> V_223 & V_113 ) ;
}
void F_159 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_142 ;
unsigned long V_248 = ( V_133 . V_249 . V_41 << 23 ) | ( V_133 . V_249 . V_250 << 21 )
| V_133 . V_249 . V_187 ;
V_142 = F_158 ( V_2 ) ;
V_142 &= ( ~ V_248 ) ;
F_150 ( V_2 , V_142 ) ;
}
void F_160 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_142 ;
unsigned long V_248 = ( V_133 . V_249 . V_41 << 23 ) | ( V_133 . V_249 . V_250 << 21 )
| V_133 . V_249 . V_187 ;
V_142 = F_158 ( V_2 ) ;
V_142 |= V_248 ;
F_150 ( V_2 , V_142 ) ;
}
void F_161 ( struct V_1 * V_2 , unsigned long V_43 )
{
V_43 = ( V_43 & F_162 ( 0 , 32 ) ) | ( F_158 ( V_2 ) & F_162 ( 32 , 32 ) ) ;
F_150 ( V_2 , V_43 ) ;
}
void F_163 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_43 ;
V_43 = F_31 ( V_2 , V_133 . V_251 . V_186 ) ;
F_161 ( V_2 , V_43 ) ;
}
void F_164 ( struct V_1 * V_2 , T_3 V_133 )
{
unsigned long V_43 ;
V_43 = F_158 ( V_2 ) ;
V_43 = ( V_43 & F_162 ( 0 , 32 ) ) | ( V_43 & F_162 ( 35 , 2 ) ) ;
F_33 ( V_2 , V_133 . V_205 . V_42 , V_43 , 0 ) ;
}
void F_165 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_32 ( V_2 ) ;
struct V_14 * V_238 = (struct V_14 * ) & V_33 -> V_223 ;
if ( V_238 -> V_252 == 2 ) {
V_238 -> V_252 = 0 ;
V_33 -> V_239 += 16 ;
} else
V_238 -> V_252 ++ ;
}
void F_166 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_32 ( V_2 ) ;
struct V_14 * V_238 = (struct V_14 * ) & V_33 -> V_223 ;
if ( V_238 -> V_252 == 0 ) {
V_238 -> V_252 = 2 ;
V_33 -> V_239 -= 16 ;
} else
V_238 -> V_252 -- ;
}
void F_167 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
unsigned long V_253 , V_254 , V_255 ;
T_3 V_133 ;
V_253 = V_151 ;
V_254 = F_42 ( V_2 , V_254 ) ;
V_255 = F_42 ( V_2 , V_255 ) ;
V_133 . V_133 = V_255 ;
F_12 ( V_2 ) ;
switch ( V_254 ) {
case V_256 :
F_159 ( V_2 , V_133 ) ;
break;
case V_257 :
F_160 ( V_2 , V_133 ) ;
break;
case V_258 :
F_163 ( V_2 , V_133 ) ;
break;
case V_259 :
F_164 ( V_2 , V_133 ) ;
break;
case V_260 :
F_149 ( V_2 , V_133 ) ;
break;
case V_261 :
F_147 ( V_2 , V_133 ) ;
break;
case V_262 :
F_153 ( V_2 ) ;
break;
case V_263 :
F_155 ( V_2 ) ;
break;
case V_264 :
F_152 ( V_2 ) ;
break;
case V_265 :
F_157 ( V_2 ) ;
break;
case V_266 :
F_112 ( V_2 , V_133 ) ;
break;
case V_267 :
F_115 ( V_2 , V_133 ) ;
break;
case V_268 :
F_110 ( V_2 , V_133 ) ;
break;
case V_269 :
F_111 ( V_2 , V_133 ) ;
break;
case V_270 :
F_116 ( V_2 , V_133 ) ;
break;
case V_271 :
F_117 ( V_2 , V_133 ) ;
break;
case V_272 :
F_109 ( V_2 , V_133 ) ;
break;
case V_273 :
F_107 ( V_2 , V_133 ) ;
break;
case V_274 :
F_108 ( V_2 , V_133 ) ;
break;
case V_275 :
F_106 ( V_2 , V_133 ) ;
break;
case V_276 :
F_127 ( V_2 , V_133 ) ;
break;
case V_277 :
F_135 ( V_2 , V_133 ) ;
break;
case V_278 :
F_72 ( V_2 , V_133 ) ;
break;
case V_279 :
F_73 ( V_2 , V_133 ) ;
break;
case V_280 :
V_253 = F_84 ( V_2 , V_133 ) ;
break;
case V_281 :
F_85 ( V_2 , V_133 ) ;
break;
case V_282 :
F_118 ( V_2 , V_133 ) ;
break;
case V_283 :
F_119 ( V_2 , V_133 ) ;
break;
case V_284 :
F_120 ( V_2 , V_133 ) ;
break;
case V_285 :
F_128 ( V_2 , V_133 ) ;
break;
case V_286 :
F_129 ( V_2 , V_133 ) ;
break;
case V_287 :
F_130 ( V_2 , V_133 ) ;
break;
case V_288 :
F_132 ( V_2 , V_133 ) ;
break;
case V_289 :
F_134 ( V_2 , V_133 ) ;
break;
case V_290 :
F_137 ( V_2 , V_133 ) ;
break;
case V_291 :
F_139 ( V_2 , V_133 ) ;
break;
case V_292 :
F_141 ( V_2 , V_133 ) ;
break;
case V_293 :
F_136 ( V_2 , V_133 ) ;
break;
case V_294 :
F_145 ( V_2 , V_133 ) ;
break;
case V_295 :
V_253 = V_147 ;
break;
default:
break;
} ;
if ( V_253 == V_151 && V_254 != V_265 )
F_165 ( V_2 ) ;
F_14 ( V_2 ) ;
}
void F_168 ( struct V_1 * V_2 )
{
int V_41 ;
V_2 -> V_3 . V_4 = V_5 ;
F_42 ( V_2 , V_119 [ 0 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 1 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 2 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 3 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 4 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 5 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 6 ] ) = 0x38 ;
F_42 ( V_2 , V_119 [ 7 ] ) = 0x38 ;
F_44 ( V_2 , V_142 ) = V_222 ;
F_44 ( V_2 , V_296 ) = 0 ;
F_44 ( V_2 , V_297 ) = 15 << 2 ;
F_44 ( V_2 , V_82 ) = 0x10000 ;
F_44 ( V_2 , V_85 ) = 0 ;
F_42 ( V_2 , V_79 ) = 0 ;
F_44 ( V_2 , V_298 ) = F_169 ( V_2 ) ;
F_44 ( V_2 , V_299 ) = 0 ;
F_44 ( V_2 , V_97 ) = 0x10000 ;
F_44 ( V_2 , V_91 ) = 0 ;
F_44 ( V_2 , V_107 [ 0 ] ) = 0 ;
F_44 ( V_2 , V_107 [ 1 ] ) = 0 ;
F_44 ( V_2 , V_107 [ 2 ] ) = 0 ;
F_44 ( V_2 , V_107 [ 3 ] ) = 0 ;
F_44 ( V_2 , V_300 ) = 0x10000 ;
F_44 ( V_2 , V_301 ) = 0x10000 ;
F_44 ( V_2 , V_302 ) = 0x10000 ;
F_44 ( V_2 , V_303 ) = 0x10000 ;
F_62 ( V_2 , V_89 ) ;
F_170 ( V_2 ) = 0x80 ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ )
F_171 ( V_2 , V_41 ) = 0 ;
}
void F_172 ( struct V_1 * V_2 )
{
unsigned long V_6 ;
F_26 ( V_6 ) ;
V_2 -> V_3 . V_12 = F_126 ( F_42 ( V_2 , V_119 [ V_7 ] ) ) ;
V_2 -> V_3 . V_13 = F_126 ( F_42 ( V_2 , V_119 [ V_10 ] ) ) ;
if ( F_13 ( V_2 ) ) {
if ( V_2 -> V_3 . V_4 & V_28 )
F_151 ( V_2 , L_3 ) ;
F_4 ( ( V_7 << V_8 ) , V_2 -> V_3 . V_9 ) ;
F_173 () ;
F_4 ( ( V_10 << V_8 ) , V_2 -> V_3 . V_11 ) ;
F_173 () ;
} else {
F_4 ( ( V_7 << V_8 ) ,
V_2 -> V_3 . V_12 ) ;
F_173 () ;
F_4 ( ( V_10 << V_8 ) ,
V_2 -> V_3 . V_13 ) ;
F_173 () ;
}
F_4 ( ( V_304 << V_8 ) ,
F_126 ( F_42 ( V_2 , V_119 [ V_304 ] ) ) ) ;
F_173 () ;
F_4 ( ( V_305 << V_8 ) ,
F_126 ( F_42 ( V_2 , V_119 [ V_305 ] ) ) ) ;
F_173 () ;
F_4 ( ( V_306 << V_8 ) ,
F_126 ( F_42 ( V_2 , V_119 [ V_306 ] ) ) ) ;
F_173 () ;
F_4 ( ( V_307 << V_8 ) ,
F_126 ( F_42 ( V_2 , V_119 [ V_307 ] ) ) ) ;
F_173 () ;
F_4 ( ( V_308 << V_8 ) ,
F_126 ( F_42 ( V_2 , V_119 [ V_308 ] ) ) ) ;
F_173 () ;
F_5 () ;
F_6 ( V_6 ) ;
}
int F_174 ( void )
{
struct V_1 * V_80 ;
V_80 = V_49 ;
F_63 ( V_309 , ( unsigned long ) V_80 -> V_3 . V_112 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
F_175 ( V_80 ) ;
F_176 ( V_80 ) ;
F_168 ( V_80 ) ;
F_172 ( V_80 ) ;
F_177 () ;
return 0 ;
}
static void F_178 ( struct V_32 * V_33 )
{
unsigned long V_310 = V_33 -> V_239 + V_14 ( V_33 ) -> V_252 ;
struct V_1 * V_2 = V_49 ;
if ( V_2 != NULL )
F_179 ( L_4 ,
V_2 , V_2 -> V_311 ) ;
F_179 ( L_5 ,
V_33 -> V_223 , V_33 -> V_36 , V_310 ) ;
F_179 ( L_6 ,
V_33 -> V_312 , V_33 -> V_313 , V_33 -> V_314 ) ;
F_179 ( L_7 ,
V_33 -> V_315 , V_33 -> V_316 , V_33 -> V_317 ) ;
F_179 ( L_8 ,
V_33 -> V_59 , V_33 -> V_318 , V_33 -> V_319 ) ;
F_179 ( L_9 , V_33 -> V_320 , V_33 -> V_321 ) ;
F_179 ( L_10 , V_33 -> V_228 ,
V_33 -> V_322 , V_33 -> V_323 ) ;
F_179 ( L_11 ,
V_33 -> V_324 . V_181 . V_325 [ 1 ] , V_33 -> V_324 . V_181 . V_325 [ 0 ] ,
V_33 -> V_326 . V_181 . V_325 [ 1 ] , V_33 -> V_326 . V_181 . V_325 [ 0 ] ) ;
F_179 ( L_12 ,
V_33 -> V_327 . V_181 . V_325 [ 1 ] , V_33 -> V_327 . V_181 . V_325 [ 0 ] ,
V_33 -> V_328 . V_181 . V_325 [ 1 ] , V_33 -> V_328 . V_181 . V_325 [ 0 ] ) ;
F_179 ( L_13 ,
V_33 -> V_329 . V_181 . V_325 [ 1 ] , V_33 -> V_329 . V_181 . V_325 [ 0 ] ,
V_33 -> V_330 . V_181 . V_325 [ 1 ] , V_33 -> V_330 . V_181 . V_325 [ 0 ] ) ;
F_179 ( L_14 , V_33 -> V_42 ,
V_33 -> V_186 , V_33 -> V_136 ) ;
F_179 ( L_15 , V_33 -> V_331 ,
V_33 -> V_332 , V_33 -> V_333 ) ;
F_179 ( L_16 , V_33 -> V_334 ,
V_33 -> V_335 , V_33 -> V_336 ) ;
F_179 ( L_17 , V_33 -> V_337 ,
V_33 -> V_338 , V_33 -> V_227 ) ;
F_179 ( L_18 , V_33 -> V_339 ,
V_33 -> V_340 , V_33 -> V_341 ) ;
F_179 ( L_19 , V_33 -> V_342 ,
V_33 -> V_343 , V_33 -> V_344 ) ;
F_179 ( L_20 , V_33 -> V_345 ,
V_33 -> V_346 , V_33 -> V_347 ) ;
F_179 ( L_21 , V_33 -> V_348 ,
V_33 -> V_349 , V_33 -> V_350 ) ;
F_179 ( L_22 , V_33 -> V_351 ,
V_33 -> V_352 , V_33 -> V_353 ) ;
}
void F_151 ( struct V_1 * V_80 , const char * V_354 , ... )
{
T_4 args ;
char V_355 [ 256 ] ;
struct V_32 * V_33 = F_32 ( V_80 ) ;
struct V_177 * V_132 = & V_80 -> V_3 . V_178 ;
va_start ( args , V_354 ) ;
vsnprintf ( V_355 , sizeof( V_355 ) , V_354 , args ) ;
va_end ( args ) ;
F_179 ( V_355 ) ;
F_178 ( V_33 ) ;
V_132 -> V_179 = V_356 ;
F_104 ( V_80 ) ;
while ( 1 ) ;
}
