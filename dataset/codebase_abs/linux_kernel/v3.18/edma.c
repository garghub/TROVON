static inline unsigned int F_1 ( unsigned V_1 , int V_2 )
{
return ( unsigned int ) F_2 ( V_3 [ V_1 ] + V_2 ) ;
}
static inline void F_3 ( unsigned V_1 , int V_2 , int V_4 )
{
F_4 ( V_4 , V_3 [ V_1 ] + V_2 ) ;
}
static inline void F_5 ( unsigned V_1 , int V_2 , unsigned V_5 ,
unsigned V_6 )
{
unsigned V_4 = F_1 ( V_1 , V_2 ) ;
V_4 &= V_5 ;
V_4 |= V_6 ;
F_3 ( V_1 , V_2 , V_4 ) ;
}
static inline void F_6 ( unsigned V_1 , int V_2 , unsigned V_5 )
{
unsigned V_4 = F_1 ( V_1 , V_2 ) ;
V_4 &= V_5 ;
F_3 ( V_1 , V_2 , V_4 ) ;
}
static inline void F_7 ( unsigned V_1 , int V_2 , unsigned V_6 )
{
unsigned V_4 = F_1 ( V_1 , V_2 ) ;
V_4 |= V_6 ;
F_3 ( V_1 , V_2 , V_4 ) ;
}
static inline unsigned int F_8 ( unsigned V_1 , int V_2 , int V_7 )
{
return F_1 ( V_1 , V_2 + ( V_7 << 2 ) ) ;
}
static inline void F_9 ( unsigned V_1 , int V_2 , int V_7 ,
unsigned V_4 )
{
F_3 ( V_1 , V_2 + ( V_7 << 2 ) , V_4 ) ;
}
static inline void F_10 ( unsigned V_1 , int V_2 , int V_7 ,
unsigned V_5 , unsigned V_6 )
{
F_5 ( V_1 , V_2 + ( V_7 << 2 ) , V_5 , V_6 ) ;
}
static inline void F_11 ( unsigned V_1 , int V_2 , int V_7 , unsigned V_6 )
{
F_7 ( V_1 , V_2 + ( V_7 << 2 ) , V_6 ) ;
}
static inline void F_12 ( unsigned V_1 , int V_2 , int V_7 , int V_8 ,
unsigned V_6 )
{
F_7 ( V_1 , V_2 + ( ( V_7 * 2 + V_8 ) << 2 ) , V_6 ) ;
}
static inline void F_13 ( unsigned V_1 , int V_2 , int V_7 , int V_8 ,
unsigned V_4 )
{
F_3 ( V_1 , V_2 + ( ( V_7 * 2 + V_8 ) << 2 ) , V_4 ) ;
}
static inline unsigned int F_14 ( unsigned V_1 , int V_2 )
{
return F_1 ( V_1 , V_9 + V_2 ) ;
}
static inline unsigned int F_15 ( unsigned V_1 , int V_2 ,
int V_7 )
{
return F_1 ( V_1 , V_9 + V_2 + ( V_7 << 2 ) ) ;
}
static inline void F_16 ( unsigned V_1 , int V_2 , unsigned V_4 )
{
F_3 ( V_1 , V_9 + V_2 , V_4 ) ;
}
static inline void F_17 ( unsigned V_1 , int V_2 , int V_7 ,
unsigned V_4 )
{
F_3 ( V_1 , V_9 + V_2 + ( V_7 << 2 ) , V_4 ) ;
}
static inline unsigned int F_18 ( unsigned V_1 , int V_2 ,
int V_10 )
{
return F_1 ( V_1 , V_11 + V_2 + ( V_10 << 5 ) ) ;
}
static inline void F_19 ( unsigned V_1 , int V_2 , int V_10 ,
unsigned V_4 )
{
F_3 ( V_1 , V_11 + V_2 + ( V_10 << 5 ) , V_4 ) ;
}
static inline void F_20 ( unsigned V_1 , int V_2 , int V_10 ,
unsigned V_5 , unsigned V_6 )
{
F_5 ( V_1 , V_11 + V_2 + ( V_10 << 5 ) , V_5 , V_6 ) ;
}
static inline void F_21 ( unsigned V_1 , int V_2 , int V_10 ,
unsigned V_5 )
{
F_6 ( V_1 , V_11 + V_2 + ( V_10 << 5 ) , V_5 ) ;
}
static inline void F_22 ( unsigned V_1 , int V_2 , int V_10 ,
unsigned V_6 )
{
F_7 ( V_1 , V_11 + V_2 + ( V_10 << 5 ) , V_6 ) ;
}
static inline void F_23 ( int V_2 , int V_12 , unsigned long * V_13 )
{
for (; V_12 > 0 ; V_12 -- )
F_24 ( V_2 + ( V_12 - 1 ) , V_13 ) ;
}
static inline void F_25 ( int V_2 , int V_12 , unsigned long * V_13 )
{
for (; V_12 > 0 ; V_12 -- )
F_26 ( V_2 + ( V_12 - 1 ) , V_13 ) ;
}
static void F_27 ( unsigned V_1 , unsigned V_14 ,
enum V_15 V_16 )
{
int V_17 = ( V_14 & 0x7 ) * 4 ;
if ( V_16 == V_18 )
V_16 = V_19 [ V_1 ] -> V_20 ;
V_16 &= 7 ;
F_10 ( V_1 , V_21 , ( V_14 >> 3 ) ,
~ ( 0x7 << V_17 ) , V_16 << V_17 ) ;
}
static void T_1 F_28 ( unsigned V_1 , int V_16 ,
int V_22 )
{
int V_17 = V_16 * 4 ;
F_5 ( V_1 , V_23 , ~ ( 0x7 << V_17 ) ,
( ( V_22 & 0x7 ) << V_17 ) ) ;
}
static void T_1 F_29 ( unsigned V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_24 ; V_7 ++ )
F_9 ( V_1 , V_25 , V_7 , ( V_7 << 5 ) ) ;
}
static inline void
F_30 ( unsigned V_26 ,
void (* F_31)( unsigned V_27 , T_2 V_28 , void * V_29 ) ,
void * V_29 )
{
unsigned V_1 ;
V_1 = F_32 ( V_26 ) ;
V_26 = F_33 ( V_26 ) ;
if ( ! F_31 )
F_17 ( V_1 , V_30 , V_26 >> 5 ,
F_34 ( V_26 & 0x1f ) ) ;
V_19 [ V_1 ] -> V_31 [ V_26 ] . F_31 = F_31 ;
V_19 [ V_1 ] -> V_31 [ V_26 ] . V_29 = V_29 ;
if ( F_31 ) {
F_17 ( V_1 , V_32 , V_26 >> 5 ,
F_34 ( V_26 & 0x1f ) ) ;
F_17 ( V_1 , V_33 , V_26 >> 5 ,
F_34 ( V_26 & 0x1f ) ) ;
}
}
static int F_35 ( int V_34 )
{
if ( V_34 >= V_19 [ 0 ] -> V_35 && V_34 <= V_19 [ 0 ] -> V_36 )
return 0 ;
else if ( V_34 >= V_19 [ 1 ] -> V_35 &&
V_34 <= V_19 [ 1 ] -> V_36 )
return 1 ;
return - 1 ;
}
static T_3 F_36 ( int V_34 , void * V_29 )
{
int V_1 ;
T_4 V_37 ;
T_4 V_38 ;
T_4 V_39 ;
V_1 = F_35 ( V_34 ) ;
if ( V_1 < 0 )
return V_40 ;
F_37 ( V_29 , L_1 ) ;
V_38 = F_15 ( V_1 , V_41 , 0 ) ;
if ( ! V_38 ) {
V_38 = F_15 ( V_1 , V_41 , 1 ) ;
if ( ! V_38 )
return V_40 ;
V_37 = F_15 ( V_1 , V_42 , 1 ) ;
V_39 = 1 ;
} else {
V_37 = F_15 ( V_1 , V_42 , 0 ) ;
V_39 = 0 ;
}
do {
T_4 V_43 ;
T_4 V_27 ;
F_37 ( V_29 , L_2 , V_39 , V_38 ) ;
V_43 = F_38 ( V_38 ) ;
V_38 &= ~ ( F_34 ( V_43 ) ) ;
if ( V_37 & F_34 ( V_43 ) ) {
V_27 = ( V_39 << 5 ) | V_43 ;
F_17 ( V_1 , V_32 , V_39 ,
F_34 ( V_43 ) ) ;
if ( V_19 [ V_1 ] -> V_31 [ V_27 ] . F_31 )
V_19 [ V_1 ] -> V_31 [ V_27 ] . F_31 (
V_27 , V_44 ,
V_19 [ V_1 ] -> V_31 [ V_27 ] . V_29 ) ;
}
} while ( V_38 );
F_16 ( V_1 , V_45 , 1 ) ;
return V_46 ;
}
static T_3 F_39 ( int V_34 , void * V_29 )
{
int V_7 ;
int V_1 ;
unsigned int V_47 = 0 ;
V_1 = F_35 ( V_34 ) ;
if ( V_1 < 0 )
return V_40 ;
F_37 ( V_29 , L_3 ) ;
if ( ( F_8 ( V_1 , V_48 , 0 ) == 0 ) &&
( F_8 ( V_1 , V_48 , 1 ) == 0 ) &&
( F_1 ( V_1 , V_49 ) == 0 ) &&
( F_1 ( V_1 , V_50 ) == 0 ) )
return V_40 ;
while ( 1 ) {
int V_8 = - 1 ;
if ( F_8 ( V_1 , V_48 , 0 ) )
V_8 = 0 ;
else if ( F_8 ( V_1 , V_48 , 1 ) )
V_8 = 1 ;
if ( V_8 >= 0 ) {
F_37 ( V_29 , L_4 , V_8 ,
F_8 ( V_1 , V_48 , V_8 ) ) ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ ) {
int V_51 = ( V_8 << 5 ) + V_7 ;
if ( F_8 ( V_1 , V_48 , V_8 ) &
F_34 ( V_7 ) ) {
F_9 ( V_1 , V_52 , V_8 ,
F_34 ( V_7 ) ) ;
F_17 ( V_1 , V_53 ,
V_8 , F_34 ( V_7 ) ) ;
if ( V_19 [ V_1 ] -> V_31 [ V_51 ] .
F_31 ) {
V_19 [ V_1 ] -> V_31 [ V_51 ] .
F_31 ( V_51 ,
V_54 ,
V_19 [ V_1 ] -> V_31
[ V_51 ] . V_29 ) ;
}
}
}
} else if ( F_1 ( V_1 , V_49 ) ) {
F_37 ( V_29 , L_5 ,
F_1 ( V_1 , V_49 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
if ( F_1 ( V_1 , V_49 ) & F_34 ( V_7 ) ) {
F_3 ( V_1 , V_55 , F_34 ( V_7 ) ) ;
F_16 ( V_1 , V_56 ,
F_34 ( V_7 ) ) ;
}
}
} else if ( F_1 ( V_1 , V_50 ) ) {
F_37 ( V_29 , L_6 ,
F_1 ( V_1 , V_50 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
if ( F_1 ( V_1 , V_50 ) & F_34 ( V_7 ) ) {
F_3 ( V_1 , V_57 , F_34 ( V_7 ) ) ;
}
}
}
if ( ( F_8 ( V_1 , V_48 , 0 ) == 0 ) &&
( F_8 ( V_1 , V_48 , 1 ) == 0 ) &&
( F_1 ( V_1 , V_49 ) == 0 ) &&
( F_1 ( V_1 , V_50 ) == 0 ) )
break;
V_47 ++ ;
if ( V_47 > 10 )
break;
}
F_3 ( V_1 , V_58 , 1 ) ;
return V_46 ;
}
static int F_40 ( int V_1 , unsigned int V_59 ,
unsigned int V_60 ,
unsigned int V_61 )
{
int V_7 , V_8 ;
unsigned int V_62 = V_60 ;
int V_63 = V_61 ;
F_41 ( V_64 , V_65 ) ;
for ( V_7 = V_61 ; V_7 < V_19 [ V_1 ] -> V_60 ; ++ V_7 ) {
V_8 = F_33 ( V_7 ) ;
if ( ! F_42 ( V_8 , V_19 [ V_1 ] -> V_66 ) ) {
if ( V_62 == V_60 )
V_63 = V_7 ;
V_62 -- ;
F_24 ( V_8 , V_64 ) ;
if ( V_62 == 0 )
break;
} else {
F_26 ( V_8 , V_64 ) ;
if ( V_59 == V_67 ) {
V_63 = V_7 ;
break;
} else {
V_62 = V_60 ;
}
}
}
if ( V_7 == V_19 [ V_1 ] -> V_60 )
V_63 = V_7 ;
V_8 = V_61 ;
F_43 (j, tmp_inuse, stop_slot)
F_26 ( V_8 , V_19 [ V_1 ] -> V_66 ) ;
if ( V_62 )
return - V_68 ;
for ( V_8 = V_7 - V_60 + 1 ; V_8 <= V_7 ; ++ V_8 )
F_44 ( V_3 [ V_1 ] + F_45 ( V_8 ) ,
& V_69 , V_70 ) ;
return F_46 ( V_1 , V_7 - V_60 + 1 ) ;
}
static int F_47 ( struct V_71 * V_72 , void * V_29 )
{
struct V_73 * V_74 = F_48 ( V_72 ) ;
int V_7 , V_62 , V_1 ;
struct V_75 V_76 ;
if ( V_72 -> V_77 ) {
V_62 = F_49 ( V_72 -> V_77 , L_7 ) ;
if ( V_62 < 0 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_62 ; V_7 ++ ) {
if ( F_50 ( V_72 -> V_77 , L_8 ,
L_9 , V_7 ,
& V_76 ) )
continue;
if ( ! F_51 ( V_78 , V_76 . V_79 ) ) {
F_52 ( V_76 . V_79 ) ;
continue;
}
F_26 ( F_33 ( V_76 . args [ 0 ] ) ,
V_19 [ 0 ] -> V_80 ) ;
F_52 ( V_76 . V_79 ) ;
}
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_74 -> V_81 ; V_7 ++ ) {
if ( ( V_74 -> V_82 [ V_7 ] . V_83 & V_84 ) &&
( int ) V_74 -> V_82 [ V_7 ] . V_85 >= 0 ) {
V_1 = F_32 ( V_74 -> V_82 [ V_7 ] . V_85 ) ;
F_26 ( F_33 ( V_74 -> V_82 [ V_7 ] . V_85 ) ,
V_19 [ V_1 ] -> V_80 ) ;
}
}
return 0 ;
}
int F_53 ( int V_27 ,
void (* F_31)( unsigned V_27 , T_2 V_28 , void * V_29 ) ,
void * V_29 ,
enum V_15 V_86 )
{
unsigned V_7 , V_87 = 0 , V_1 = 0 ;
int V_88 = 0 ;
if ( ! V_89 ) {
V_88 = F_54 ( & V_90 , NULL , NULL ,
F_47 ) ;
if ( V_88 < 0 )
return V_88 ;
V_89 = true ;
}
if ( V_27 >= 0 ) {
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
}
if ( V_27 < 0 ) {
for ( V_7 = 0 ; V_7 < V_91 ; V_7 ++ ) {
V_27 = 0 ;
for (; ; ) {
V_27 = F_55 ( V_19 [ V_7 ] -> V_80 ,
V_19 [ V_7 ] -> V_92 ,
V_27 ) ;
if ( V_27 == V_19 [ V_7 ] -> V_92 )
break;
if ( ! F_42 ( V_27 ,
V_19 [ V_7 ] -> V_66 ) ) {
V_87 = 1 ;
V_1 = V_7 ;
break;
}
V_27 ++ ;
}
if ( V_87 )
break;
}
if ( ! V_87 )
return - V_93 ;
} else if ( V_27 >= V_19 [ V_1 ] -> V_92 ) {
return - V_94 ;
} else if ( F_42 ( V_27 , V_19 [ V_1 ] -> V_66 ) ) {
return - V_68 ;
}
F_12 ( V_1 , V_95 , 0 , V_27 >> 5 , F_34 ( V_27 & 0x1f ) ) ;
F_56 ( F_46 ( V_1 , V_27 ) ) ;
F_44 ( V_3 [ V_1 ] + F_45 ( V_27 ) ,
& V_69 , V_70 ) ;
if ( F_31 )
F_30 ( F_46 ( V_1 , V_27 ) ,
F_31 , V_29 ) ;
F_27 ( V_1 , V_27 , V_86 ) ;
return F_46 ( V_1 , V_27 ) ;
}
void F_57 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 >= V_19 [ V_1 ] -> V_92 )
return;
F_30 ( V_27 , NULL , NULL ) ;
F_44 ( V_3 [ V_1 ] + F_45 ( V_27 ) ,
& V_69 , V_70 ) ;
F_26 ( V_27 , V_19 [ V_1 ] -> V_66 ) ;
}
int F_58 ( unsigned V_1 , int V_43 )
{
if ( ! V_19 [ V_1 ] )
return - V_94 ;
if ( V_43 >= 0 )
V_43 = F_33 ( V_43 ) ;
if ( V_43 < 0 ) {
V_43 = V_19 [ V_1 ] -> V_92 ;
for (; ; ) {
V_43 = F_59 ( V_19 [ V_1 ] -> V_66 ,
V_19 [ V_1 ] -> V_60 , V_43 ) ;
if ( V_43 == V_19 [ V_1 ] -> V_60 )
return - V_93 ;
if ( ! F_42 ( V_43 , V_19 [ V_1 ] -> V_66 ) )
break;
}
} else if ( V_43 < V_19 [ V_1 ] -> V_92 ||
V_43 >= V_19 [ V_1 ] -> V_60 ) {
return - V_94 ;
} else if ( F_42 ( V_43 , V_19 [ V_1 ] -> V_66 ) ) {
return - V_68 ;
}
F_44 ( V_3 [ V_1 ] + F_45 ( V_43 ) ,
& V_69 , V_70 ) ;
return F_46 ( V_1 , V_43 ) ;
}
void F_60 ( unsigned V_43 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_92 ||
V_43 >= V_19 [ V_1 ] -> V_60 )
return;
F_44 ( V_3 [ V_1 ] + F_45 ( V_43 ) ,
& V_69 , V_70 ) ;
F_26 ( V_43 , V_19 [ V_1 ] -> V_66 ) ;
}
int F_61 ( unsigned V_1 , unsigned int V_59 , int V_43 , int V_62 )
{
if ( ( V_59 != V_96 ) &&
( V_43 < V_19 [ V_1 ] -> V_92 ||
V_43 >= V_19 [ V_1 ] -> V_60 ) )
return - V_94 ;
if ( V_62 < 1 || V_62 >
( V_19 [ V_1 ] -> V_60 - V_19 [ V_1 ] -> V_92 ) )
return - V_94 ;
switch ( V_59 ) {
case V_96 :
return F_40 ( V_1 , V_59 , V_62 ,
V_19 [ V_1 ] -> V_92 ) ;
case V_67 :
case V_97 :
return F_40 ( V_1 , V_59 , V_62 , V_43 ) ;
default:
return - V_94 ;
}
}
int F_62 ( unsigned V_43 , int V_62 )
{
unsigned V_1 , V_98 ;
int V_7 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_92 ||
V_43 >= V_19 [ V_1 ] -> V_60 ||
V_62 < 1 )
return - V_94 ;
for ( V_7 = V_43 ; V_7 < V_43 + V_62 ; ++ V_7 ) {
V_1 = F_32 ( V_7 ) ;
V_98 = F_33 ( V_7 ) ;
F_44 ( V_3 [ V_1 ] + F_45 ( V_98 ) ,
& V_69 , V_70 ) ;
F_26 ( V_98 , V_19 [ V_1 ] -> V_66 ) ;
}
return 0 ;
}
void F_63 ( unsigned V_43 , T_5 V_99 ,
enum V_100 V_101 , enum V_102 V_103 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_60 ) {
unsigned int V_7 = F_18 ( V_1 , V_104 , V_43 ) ;
if ( V_101 ) {
V_7 = ( V_7 & ~ ( V_105 ) ) | ( V_106 | ( ( V_103 & 0x7 ) << 8 ) ) ;
} else {
V_7 &= ~ V_106 ;
}
F_19 ( V_1 , V_104 , V_43 , V_7 ) ;
F_19 ( V_1 , V_107 , V_43 , V_99 ) ;
}
}
void F_64 ( unsigned V_43 , T_5 V_108 ,
enum V_100 V_101 , enum V_102 V_103 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_60 ) {
unsigned int V_7 = F_18 ( V_1 , V_104 , V_43 ) ;
if ( V_101 ) {
V_7 = ( V_7 & ~ ( V_105 ) ) | ( V_109 | ( ( V_103 & 0x7 ) << 8 ) ) ;
} else {
V_7 &= ~ V_109 ;
}
F_19 ( V_1 , V_104 , V_43 , V_7 ) ;
F_19 ( V_1 , V_110 , V_43 , V_108 ) ;
}
}
T_5 F_65 ( unsigned V_43 , bool V_111 )
{
T_4 V_112 , V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
V_112 = F_45 ( V_43 ) ;
V_112 += V_111 ? V_110 : V_107 ;
return F_1 ( V_1 , V_112 ) ;
}
void F_66 ( unsigned V_43 , T_6 V_113 , T_6 V_114 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_60 ) {
F_20 ( V_1 , V_115 , V_43 ,
0xffff0000 , V_113 ) ;
F_20 ( V_1 , V_116 , V_43 ,
0xffff0000 , V_114 ) ;
}
}
void F_67 ( unsigned V_43 , T_6 V_117 , T_6 V_118 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_60 ) {
F_20 ( V_1 , V_115 , V_43 ,
0x0000ffff , V_117 << 16 ) ;
F_20 ( V_1 , V_116 , V_43 ,
0x0000ffff , V_118 << 16 ) ;
}
}
void F_68 ( unsigned V_43 ,
T_2 V_119 , T_2 V_120 , T_2 V_121 ,
T_2 V_122 , enum V_123 V_124 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 < V_19 [ V_1 ] -> V_60 ) {
F_20 ( V_1 , V_125 , V_43 ,
0x0000ffff , V_122 << 16 ) ;
if ( V_124 == V_126 )
F_21 ( V_1 , V_104 , V_43 , ~ V_127 ) ;
else
F_22 ( V_1 , V_104 , V_43 , V_127 ) ;
F_19 ( V_1 , V_128 , V_43 , ( V_120 << 16 ) | V_119 ) ;
F_19 ( V_1 , V_129 , V_43 , V_121 ) ;
}
}
void F_69 ( unsigned V_130 , unsigned V_131 )
{
unsigned V_132 , V_133 ;
V_132 = F_32 ( V_130 ) ;
V_130 = F_33 ( V_130 ) ;
V_133 = F_32 ( V_131 ) ;
V_131 = F_33 ( V_131 ) ;
if ( V_130 >= V_19 [ V_132 ] -> V_60 )
return;
if ( V_131 >= V_19 [ V_133 ] -> V_60 )
return;
F_20 ( V_132 , V_125 , V_130 , 0xffff0000 ,
F_45 ( V_131 ) ) ;
}
void F_70 ( unsigned V_130 )
{
unsigned V_1 ;
V_1 = F_32 ( V_130 ) ;
V_130 = F_33 ( V_130 ) ;
if ( V_130 >= V_19 [ V_1 ] -> V_60 )
return;
F_22 ( V_1 , V_125 , V_130 , 0xffff ) ;
}
void F_71 ( unsigned V_43 , const struct V_134 * V_135 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 >= V_19 [ V_1 ] -> V_60 )
return;
F_44 ( V_3 [ V_1 ] + F_45 ( V_43 ) , V_135 ,
V_70 ) ;
}
void F_72 ( unsigned V_43 , struct V_134 * V_135 )
{
unsigned V_1 ;
V_1 = F_32 ( V_43 ) ;
V_43 = F_33 ( V_43 ) ;
if ( V_43 >= V_19 [ V_1 ] -> V_60 )
return;
F_73 ( V_135 , V_3 [ V_1 ] + F_45 ( V_43 ) ,
V_70 ) ;
}
void F_74 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 < V_19 [ V_1 ] -> V_92 ) {
unsigned int V_136 = F_34 ( V_27 & 0x1f ) ;
F_17 ( V_1 , V_137 , V_27 >> 5 , V_136 ) ;
}
}
void F_75 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 < V_19 [ V_1 ] -> V_92 ) {
unsigned int V_136 = F_34 ( V_27 & 0x1f ) ;
F_17 ( V_1 , V_138 , V_27 >> 5 , V_136 ) ;
}
}
int F_76 ( unsigned V_27 )
{
unsigned V_1 ;
unsigned int V_136 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
V_136 = F_34 ( V_27 & 0x1f ) ;
F_17 ( V_1 , V_139 , ( V_27 >> 5 ) , V_136 ) ;
F_77 ( L_10 , ( V_27 >> 5 ) ,
F_15 ( V_1 , V_139 , ( V_27 >> 5 ) ) ) ;
return 0 ;
}
int F_78 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 < V_19 [ V_1 ] -> V_92 ) {
int V_8 = V_27 >> 5 ;
unsigned int V_136 = F_34 ( V_27 & 0x1f ) ;
if ( F_79 ( V_27 , V_19 [ V_1 ] -> V_80 ) ) {
F_77 ( L_10 , V_8 ,
F_15 ( V_1 , V_139 , V_8 ) ) ;
F_17 ( V_1 , V_139 , V_8 , V_136 ) ;
return 0 ;
}
F_77 ( L_11 , V_8 ,
F_15 ( V_1 , V_140 , V_8 ) ) ;
F_9 ( V_1 , V_141 , V_8 , V_136 ) ;
F_9 ( V_1 , V_52 , V_8 , V_136 ) ;
F_17 ( V_1 , V_53 , V_8 , V_136 ) ;
F_17 ( V_1 , V_138 , V_8 , V_136 ) ;
F_77 ( L_12 , V_8 ,
F_15 ( V_1 , V_142 , V_8 ) ) ;
return 0 ;
}
return - V_94 ;
}
void F_56 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 < V_19 [ V_1 ] -> V_92 ) {
int V_8 = V_27 >> 5 ;
unsigned int V_136 = F_34 ( V_27 & 0x1f ) ;
F_17 ( V_1 , V_137 , V_8 , V_136 ) ;
F_17 ( V_1 , V_143 , V_8 , V_136 ) ;
F_17 ( V_1 , V_53 , V_8 , V_136 ) ;
F_9 ( V_1 , V_52 , V_8 , V_136 ) ;
F_77 ( L_12 , V_8 ,
F_15 ( V_1 , V_142 , V_8 ) ) ;
}
}
void F_80 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 < V_19 [ V_1 ] -> V_92 ) {
int V_8 = ( V_27 >> 5 ) ;
unsigned int V_136 = F_34 ( V_27 & 0x1f ) ;
F_77 ( L_13 , V_8 ,
F_8 ( V_1 , V_48 , V_8 ) ) ;
F_17 ( V_1 , V_143 , V_8 , V_136 ) ;
F_9 ( V_1 , V_52 , V_8 , V_136 ) ;
F_17 ( V_1 , V_53 , V_8 , V_136 ) ;
F_3 ( V_1 , V_57 , F_34 ( 16 ) | F_34 ( 1 ) | F_34 ( 0 ) ) ;
}
}
void F_81 ( unsigned V_27 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 >= V_19 [ V_1 ] -> V_92 )
return;
if ( V_27 < 32 )
F_3 ( V_1 , V_141 , F_34 ( V_27 ) ) ;
else
F_3 ( V_1 , V_144 , F_34 ( V_27 - 32 ) ) ;
}
void F_82 ( unsigned V_27 , enum V_15 V_86 )
{
unsigned V_1 ;
V_1 = F_32 ( V_27 ) ;
V_27 = F_33 ( V_27 ) ;
if ( V_27 >= V_19 [ V_1 ] -> V_92 )
return;
if ( V_86 == V_18 )
V_86 = V_19 [ V_1 ] -> V_20 ;
if ( V_86 >= V_19 [ V_1 ] -> V_145 )
return;
F_27 ( V_1 , V_27 , V_86 ) ;
}
static int F_83 ( struct V_71 * V_72 , struct V_146 * V_147 ,
struct V_148 * V_19 , int V_149 )
{
int V_7 ;
T_4 V_150 , V_151 ;
F_84 ( * V_152 ) [ 2 ] ;
V_151 = F_1 ( V_149 , V_153 ) ;
V_150 = F_85 ( V_151 ) ;
V_19 -> V_154 = F_34 ( V_150 ) ;
V_150 = F_86 ( V_151 ) ;
V_19 -> V_92 = F_34 ( V_150 + 1 ) ;
V_150 = F_87 ( V_151 ) ;
V_19 -> V_60 = F_34 ( V_150 + 4 ) ;
V_150 = F_88 ( V_151 ) ;
V_19 -> V_145 = V_150 + 1 ;
F_37 ( V_72 , L_14 , V_149 ,
V_151 ) ;
F_37 ( V_72 , L_15 , V_19 -> V_154 ) ;
F_37 ( V_72 , L_16 , V_19 -> V_92 ) ;
F_37 ( V_72 , L_17 , V_19 -> V_60 ) ;
F_37 ( V_72 , L_18 , V_19 -> V_145 ) ;
if ( V_147 -> V_155 )
return 0 ;
V_152 = F_89 ( V_72 ,
( V_19 -> V_145 + 1 ) * sizeof( F_84 ) ,
V_156 ) ;
if ( ! V_152 )
return - V_93 ;
for ( V_7 = 0 ; V_7 < V_19 -> V_145 ; V_7 ++ ) {
V_152 [ V_7 ] [ 0 ] = V_7 ;
V_152 [ V_7 ] [ 1 ] = V_7 ;
}
V_152 [ V_7 ] [ 0 ] = - 1 ;
V_152 [ V_7 ] [ 1 ] = - 1 ;
V_147 -> V_155 = V_152 ;
V_147 -> V_20 = V_7 - 1 ;
return 0 ;
}
static int F_90 ( struct V_71 * V_72 , struct V_157 * V_158 ,
struct V_146 * V_147 , T_7 V_159 )
{
const char V_160 [] = L_19 ;
struct V_82 V_161 ;
void T_8 * V_162 ;
T_6 ( * V_163 ) [ 2 ] ;
T_7 V_164 = V_159 / sizeof( T_6 ) ;
T_4 V_165 , V_2 , V_166 ;
int V_88 , V_7 ;
V_163 = F_89 ( V_72 , ( V_164 + 2 ) * sizeof( T_6 ) , V_156 ) ;
if ( ! V_163 )
return - V_93 ;
V_88 = F_91 ( V_158 , 1 , & V_161 ) ;
if ( V_88 )
return - V_93 ;
V_162 = F_92 ( V_72 , V_161 . V_85 , F_93 ( & V_161 ) ) ;
if ( ! V_162 )
return - V_93 ;
V_88 = F_94 ( V_158 , V_160 , ( T_2 * ) V_163 , V_164 ) ;
if ( V_88 )
return - V_167 ;
V_164 >>= 1 ;
V_163 [ V_164 ] [ 0 ] = V_163 [ V_164 ] [ 1 ] = - 1 ;
for ( V_7 = 0 ; V_7 < V_164 ; V_7 ++ ) {
V_165 = ( V_163 [ V_7 ] [ 1 ] & 0x03 ) << 3 ;
V_2 = V_163 [ V_7 ] [ 1 ] & 0xfffffffc ;
V_166 = F_95 ( V_162 + V_2 ) ;
V_166 &= ~ ( 0xff << V_165 ) ;
V_166 |= V_163 [ V_7 ] [ 0 ] << V_165 ;
F_96 ( V_166 , ( V_162 + V_2 ) ) ;
}
V_147 -> V_163 = ( const T_6 ( * ) [ 2 ] ) V_163 ;
return 0 ;
}
static int F_97 ( struct V_71 * V_72 ,
struct V_157 * V_158 ,
struct V_146 * V_147 )
{
int V_88 = 0 ;
struct V_168 * V_169 ;
T_7 V_159 ;
struct V_170 * V_171 ;
V_171 = F_89 ( V_72 , sizeof( struct V_170 ) , V_156 ) ;
if ( ! V_171 )
return - V_93 ;
V_147 -> V_172 = V_171 ;
V_169 = F_98 ( V_158 , L_19 , & V_159 ) ;
if ( V_169 )
V_88 = F_90 ( V_72 , V_158 , V_147 , V_159 ) ;
return V_88 ;
}
static struct V_146 * F_99 ( struct V_71 * V_72 ,
struct V_157 * V_158 )
{
struct V_146 * V_173 ;
int V_88 ;
V_173 = F_89 ( V_72 , sizeof( struct V_146 ) , V_156 ) ;
if ( ! V_173 )
return F_100 ( - V_93 ) ;
V_88 = F_97 ( V_72 , V_158 , V_173 ) ;
if ( V_88 )
return F_100 ( V_88 ) ;
F_101 ( V_174 , V_175 . V_176 ) ;
F_101 ( V_177 , V_175 . V_176 ) ;
F_102 ( V_72 -> V_77 , V_178 ,
& V_175 ) ;
return V_173 ;
}
static struct V_146 * F_99 ( struct V_71 * V_72 ,
struct V_157 * V_158 )
{
return F_100 ( - V_179 ) ;
}
static int F_103 ( struct V_73 * V_74 )
{
struct V_146 * * V_173 = V_74 -> V_72 . V_180 ;
struct V_146 * V_181 [ V_182 ] = { NULL } ;
F_84 ( * V_155 ) [ 2 ] ;
int V_7 , V_8 , V_183 , V_184 , V_185 = 0 ;
int V_186 = - 1 ;
const T_6 ( * V_187 ) [ 2 ] ;
const T_6 ( * V_188 ) [ 2 ] ;
const T_6 ( * V_163 ) [ 2 ] ;
int V_34 [ V_182 ] = { 0 , 0 } ;
int V_189 [ V_182 ] = { 0 , 0 } ;
struct V_82 * V_190 [ V_182 ] = { NULL } ;
struct V_82 V_161 [ V_182 ] ;
char V_191 [ 10 ] ;
struct V_157 * V_158 = V_74 -> V_72 . V_77 ;
struct V_71 * V_72 = & V_74 -> V_72 ;
int V_88 ;
struct V_192 V_193 = {
. V_194 = L_20 ,
. V_195 = F_104 ( 32 ) ,
. V_196 = & V_74 -> V_72 ,
} ;
if ( V_158 ) {
if ( V_91 ) {
F_105 ( V_72 , L_21 ) ;
return - V_197 ;
}
V_181 [ 0 ] = F_99 ( V_72 , V_158 ) ;
if ( F_106 ( V_181 [ 0 ] ) ) {
F_105 ( V_72 , L_22 ) ;
return F_107 ( V_181 [ 0 ] ) ;
}
V_173 = V_181 ;
}
if ( ! V_173 )
return - V_197 ;
F_108 ( V_72 ) ;
V_88 = F_109 ( V_72 ) ;
if ( V_88 < 0 ) {
F_105 ( V_72 , L_23 ) ;
return V_88 ;
}
for ( V_8 = 0 ; V_8 < V_182 ; V_8 ++ ) {
if ( ! V_173 [ V_8 ] ) {
if ( ! V_185 )
return - V_197 ;
break;
}
if ( V_158 ) {
V_88 = F_91 ( V_158 , V_8 , & V_161 [ V_8 ] ) ;
if ( ! V_88 )
V_190 [ V_8 ] = & V_161 [ V_8 ] ;
} else {
sprintf ( V_191 , L_24 , V_8 ) ;
V_190 [ V_8 ] = F_110 ( V_74 ,
V_198 ,
V_191 ) ;
}
if ( ! V_190 [ V_8 ] ) {
if ( V_185 )
break;
else
return - V_197 ;
} else {
V_185 = 1 ;
}
V_3 [ V_8 ] = F_111 ( & V_74 -> V_72 , V_190 [ V_8 ] ) ;
if ( F_106 ( V_3 [ V_8 ] ) )
return F_107 ( V_3 [ V_8 ] ) ;
V_19 [ V_8 ] = F_89 ( & V_74 -> V_72 , sizeof( struct V_148 ) ,
V_156 ) ;
if ( ! V_19 [ V_8 ] )
return - V_93 ;
V_88 = F_83 ( V_72 , V_173 [ V_8 ] , V_19 [ V_8 ] , V_8 ) ;
if ( V_88 )
return V_88 ;
V_19 [ V_8 ] -> V_20 = V_173 [ V_8 ] -> V_20 ;
F_37 ( & V_74 -> V_72 , L_25 ,
V_3 [ V_8 ] ) ;
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_60 ; V_7 ++ )
F_44 ( V_3 [ V_8 ] + F_45 ( V_7 ) ,
& V_69 , V_70 ) ;
memset ( V_19 [ V_8 ] -> V_80 , 0xff ,
sizeof( V_19 [ V_8 ] -> V_80 ) ) ;
if ( V_173 [ V_8 ] -> V_172 ) {
V_187 = V_173 [ V_8 ] -> V_172 -> V_187 ;
if ( V_187 ) {
for ( V_7 = 0 ; V_187 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_183 = V_187 [ V_7 ] [ 0 ] ;
V_184 = V_187 [ V_7 ] [ 1 ] ;
F_25 ( V_183 , V_184 ,
V_19 [ V_8 ] -> V_80 ) ;
}
}
V_188 = V_173 [ V_8 ] -> V_172 -> V_188 ;
if ( V_188 ) {
for ( V_7 = 0 ; V_188 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_183 = V_188 [ V_7 ] [ 0 ] ;
V_184 = V_188 [ V_7 ] [ 1 ] ;
F_23 ( V_183 , V_184 ,
V_19 [ V_8 ] -> V_66 ) ;
}
}
}
V_163 = V_173 [ V_8 ] -> V_163 ;
if ( V_163 ) {
for ( V_7 = 0 ; V_163 [ V_7 ] [ 1 ] != - 1 ; V_7 ++ ) {
V_183 = V_163 [ V_7 ] [ 1 ] ;
F_25 ( V_183 , 1 ,
V_19 [ V_8 ] -> V_80 ) ;
}
}
if ( V_158 ) {
V_34 [ V_8 ] = F_112 ( V_158 , 0 ) ;
V_189 [ V_8 ] = F_112 ( V_158 , 2 ) ;
} else {
char V_199 [ 10 ] ;
sprintf ( V_199 , L_26 , V_8 ) ;
V_34 [ V_8 ] = F_113 ( V_74 , V_199 ) ;
sprintf ( V_199 , L_27 , V_8 ) ;
V_189 [ V_8 ] = F_113 ( V_74 , V_199 ) ;
}
V_19 [ V_8 ] -> V_35 = V_34 [ V_8 ] ;
V_19 [ V_8 ] -> V_36 = V_189 [ V_8 ] ;
V_186 = F_114 ( V_72 , V_34 [ V_8 ] , F_36 , 0 ,
L_28 , V_72 ) ;
if ( V_186 < 0 ) {
F_37 ( & V_74 -> V_72 ,
L_29 ,
V_34 [ V_8 ] , V_186 ) ;
return V_186 ;
}
V_186 = F_114 ( V_72 , V_189 [ V_8 ] , F_39 , 0 ,
L_30 , V_72 ) ;
if ( V_186 < 0 ) {
F_37 ( & V_74 -> V_72 ,
L_29 ,
V_189 [ V_8 ] , V_186 ) ;
return V_186 ;
}
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_92 ; V_7 ++ )
F_27 ( V_8 , V_7 , V_173 [ V_8 ] -> V_20 ) ;
V_155 = V_173 [ V_8 ] -> V_155 ;
for ( V_7 = 0 ; V_155 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ )
F_28 ( V_8 ,
V_155 [ V_7 ] [ 0 ] ,
V_155 [ V_7 ] [ 1 ] ) ;
if ( F_1 ( V_8 , V_153 ) & V_200 )
F_29 ( V_8 ) ;
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_154 ; V_7 ++ ) {
F_13 ( V_8 , V_95 , V_7 , 0 , 0x0 ) ;
F_13 ( V_8 , V_95 , V_7 , 1 , 0x0 ) ;
F_9 ( V_8 , V_201 , V_7 , 0x0 ) ;
}
V_91 ++ ;
V_193 . V_59 = V_8 ;
F_115 ( & V_193 ) ;
}
return 0 ;
}
static int T_1 F_116 ( void )
{
return F_117 ( & V_202 , F_103 ) ;
}
