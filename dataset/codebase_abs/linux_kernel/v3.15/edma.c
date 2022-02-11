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
static void T_1 F_28 ( unsigned V_1 , int V_16 , int V_22 )
{
int V_17 = V_16 * 4 ;
F_5 ( V_1 , V_23 , ~ ( 0x7 << V_17 ) , ( ( V_22 & 0x7 ) << V_17 ) ) ;
}
static void T_1 F_29 ( unsigned V_1 , int V_16 ,
int V_24 )
{
int V_17 = V_16 * 4 ;
F_5 ( V_1 , V_25 , ~ ( 0x7 << V_17 ) ,
( ( V_24 & 0x7 ) << V_17 ) ) ;
}
static void T_1 F_30 ( unsigned V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ )
F_9 ( V_1 , V_27 , V_7 , ( V_7 << 5 ) ) ;
}
static inline void
F_31 ( unsigned V_28 ,
void (* F_32)( unsigned V_29 , T_2 V_30 , void * V_31 ) ,
void * V_31 )
{
unsigned V_1 ;
V_1 = F_33 ( V_28 ) ;
V_28 = F_34 ( V_28 ) ;
if ( ! F_32 )
F_17 ( V_1 , V_32 , V_28 >> 5 ,
F_35 ( V_28 & 0x1f ) ) ;
V_19 [ V_1 ] -> V_33 [ V_28 ] . F_32 = F_32 ;
V_19 [ V_1 ] -> V_33 [ V_28 ] . V_31 = V_31 ;
if ( F_32 ) {
F_17 ( V_1 , V_34 , V_28 >> 5 ,
F_35 ( V_28 & 0x1f ) ) ;
F_17 ( V_1 , V_35 , V_28 >> 5 ,
F_35 ( V_28 & 0x1f ) ) ;
}
}
static int F_36 ( int V_36 )
{
if ( V_36 >= V_19 [ 0 ] -> V_37 && V_36 <= V_19 [ 0 ] -> V_38 )
return 0 ;
else if ( V_36 >= V_19 [ 1 ] -> V_37 &&
V_36 <= V_19 [ 1 ] -> V_38 )
return 1 ;
return - 1 ;
}
static T_3 F_37 ( int V_36 , void * V_31 )
{
int V_1 ;
T_4 V_39 ;
T_4 V_40 ;
T_4 V_41 ;
V_1 = F_36 ( V_36 ) ;
if ( V_1 < 0 )
return V_42 ;
F_38 ( V_31 , L_1 ) ;
V_40 = F_15 ( V_1 , V_43 , 0 ) ;
if ( ! V_40 ) {
V_40 = F_15 ( V_1 , V_43 , 1 ) ;
if ( ! V_40 )
return V_42 ;
V_39 = F_15 ( V_1 , V_44 , 1 ) ;
V_41 = 1 ;
} else {
V_39 = F_15 ( V_1 , V_44 , 0 ) ;
V_41 = 0 ;
}
do {
T_4 V_45 ;
T_4 V_29 ;
F_38 ( V_31 , L_2 , V_41 , V_40 ) ;
V_45 = F_39 ( V_40 ) ;
V_40 &= ~ ( F_35 ( V_45 ) ) ;
if ( V_39 & F_35 ( V_45 ) ) {
V_29 = ( V_41 << 5 ) | V_45 ;
F_17 ( V_1 , V_34 , V_41 ,
F_35 ( V_45 ) ) ;
if ( V_19 [ V_1 ] -> V_33 [ V_29 ] . F_32 )
V_19 [ V_1 ] -> V_33 [ V_29 ] . F_32 (
V_29 , V_46 ,
V_19 [ V_1 ] -> V_33 [ V_29 ] . V_31 ) ;
}
} while ( V_40 );
F_16 ( V_1 , V_47 , 1 ) ;
return V_48 ;
}
static T_3 F_40 ( int V_36 , void * V_31 )
{
int V_7 ;
int V_1 ;
unsigned int V_49 = 0 ;
V_1 = F_36 ( V_36 ) ;
if ( V_1 < 0 )
return V_42 ;
F_38 ( V_31 , L_3 ) ;
if ( ( F_8 ( V_1 , V_50 , 0 ) == 0 ) &&
( F_8 ( V_1 , V_50 , 1 ) == 0 ) &&
( F_1 ( V_1 , V_51 ) == 0 ) &&
( F_1 ( V_1 , V_52 ) == 0 ) )
return V_42 ;
while ( 1 ) {
int V_8 = - 1 ;
if ( F_8 ( V_1 , V_50 , 0 ) )
V_8 = 0 ;
else if ( F_8 ( V_1 , V_50 , 1 ) )
V_8 = 1 ;
if ( V_8 >= 0 ) {
F_38 ( V_31 , L_4 , V_8 ,
F_8 ( V_1 , V_50 , V_8 ) ) ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ ) {
int V_53 = ( V_8 << 5 ) + V_7 ;
if ( F_8 ( V_1 , V_50 , V_8 ) &
F_35 ( V_7 ) ) {
F_9 ( V_1 , V_54 , V_8 ,
F_35 ( V_7 ) ) ;
F_17 ( V_1 , V_55 ,
V_8 , F_35 ( V_7 ) ) ;
if ( V_19 [ V_1 ] -> V_33 [ V_53 ] .
F_32 ) {
V_19 [ V_1 ] -> V_33 [ V_53 ] .
F_32 ( V_53 ,
V_56 ,
V_19 [ V_1 ] -> V_33
[ V_53 ] . V_31 ) ;
}
}
}
} else if ( F_1 ( V_1 , V_51 ) ) {
F_38 ( V_31 , L_5 ,
F_1 ( V_1 , V_51 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
if ( F_1 ( V_1 , V_51 ) & F_35 ( V_7 ) ) {
F_3 ( V_1 , V_57 , F_35 ( V_7 ) ) ;
F_16 ( V_1 , V_58 ,
F_35 ( V_7 ) ) ;
}
}
} else if ( F_1 ( V_1 , V_52 ) ) {
F_38 ( V_31 , L_6 ,
F_1 ( V_1 , V_52 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
if ( F_1 ( V_1 , V_52 ) & F_35 ( V_7 ) ) {
F_3 ( V_1 , V_59 , F_35 ( V_7 ) ) ;
}
}
}
if ( ( F_8 ( V_1 , V_50 , 0 ) == 0 ) &&
( F_8 ( V_1 , V_50 , 1 ) == 0 ) &&
( F_1 ( V_1 , V_51 ) == 0 ) &&
( F_1 ( V_1 , V_52 ) == 0 ) )
break;
V_49 ++ ;
if ( V_49 > 10 )
break;
}
F_3 ( V_1 , V_60 , 1 ) ;
return V_48 ;
}
static int F_41 ( int V_1 , unsigned int V_61 ,
unsigned int V_62 ,
unsigned int V_63 )
{
int V_7 , V_8 ;
unsigned int V_64 = V_62 ;
int V_65 = V_63 ;
F_42 ( V_66 , V_67 ) ;
for ( V_7 = V_63 ; V_7 < V_19 [ V_1 ] -> V_62 ; ++ V_7 ) {
V_8 = F_34 ( V_7 ) ;
if ( ! F_43 ( V_8 , V_19 [ V_1 ] -> V_68 ) ) {
if ( V_64 == V_62 )
V_65 = V_7 ;
V_64 -- ;
F_24 ( V_8 , V_66 ) ;
if ( V_64 == 0 )
break;
} else {
F_26 ( V_8 , V_66 ) ;
if ( V_61 == V_69 ) {
V_65 = V_7 ;
break;
} else {
V_64 = V_62 ;
}
}
}
if ( V_7 == V_19 [ V_1 ] -> V_62 )
V_65 = V_7 ;
V_8 = V_63 ;
F_44 (j, tmp_inuse, stop_slot)
F_26 ( V_8 , V_19 [ V_1 ] -> V_68 ) ;
if ( V_64 )
return - V_70 ;
for ( V_8 = V_7 - V_62 + 1 ; V_8 <= V_7 ; ++ V_8 )
F_45 ( V_3 [ V_1 ] + F_46 ( V_8 ) ,
& V_71 , V_72 ) ;
return F_47 ( V_1 , V_7 - V_62 + 1 ) ;
}
static int F_48 ( struct V_73 * V_74 , void * V_31 )
{
struct V_75 * V_76 = F_49 ( V_74 ) ;
int V_7 , V_64 , V_1 ;
struct V_77 V_78 ;
if ( V_74 -> V_79 ) {
V_64 = F_50 ( V_74 -> V_79 , L_7 ) ;
if ( V_64 < 0 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_64 ; V_7 ++ ) {
if ( F_51 ( V_74 -> V_79 , L_8 ,
L_9 , V_7 ,
& V_78 ) )
continue;
if ( ! F_52 ( V_80 , V_78 . V_81 ) ) {
F_53 ( V_78 . V_81 ) ;
continue;
}
F_26 ( F_34 ( V_78 . args [ 0 ] ) ,
V_19 [ 0 ] -> V_82 ) ;
F_53 ( V_78 . V_81 ) ;
}
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_76 -> V_83 ; V_7 ++ ) {
if ( ( V_76 -> V_84 [ V_7 ] . V_85 & V_86 ) &&
( int ) V_76 -> V_84 [ V_7 ] . V_87 >= 0 ) {
V_1 = F_33 ( V_76 -> V_84 [ V_7 ] . V_87 ) ;
F_26 ( F_34 ( V_76 -> V_84 [ V_7 ] . V_87 ) ,
V_19 [ V_1 ] -> V_82 ) ;
}
}
return 0 ;
}
int F_54 ( int V_29 ,
void (* F_32)( unsigned V_29 , T_2 V_30 , void * V_31 ) ,
void * V_31 ,
enum V_15 V_88 )
{
unsigned V_7 , V_89 = 0 , V_1 = 0 ;
int V_90 = 0 ;
if ( ! V_91 ) {
V_90 = F_55 ( & V_92 , NULL , NULL ,
F_48 ) ;
if ( V_90 < 0 )
return V_90 ;
V_91 = true ;
}
if ( V_29 >= 0 ) {
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
}
if ( V_29 < 0 ) {
for ( V_7 = 0 ; V_7 < V_93 ; V_7 ++ ) {
V_29 = 0 ;
for (; ; ) {
V_29 = F_56 ( V_19 [ V_7 ] -> V_82 ,
V_19 [ V_7 ] -> V_94 ,
V_29 ) ;
if ( V_29 == V_19 [ V_7 ] -> V_94 )
break;
if ( ! F_43 ( V_29 ,
V_19 [ V_7 ] -> V_68 ) ) {
V_89 = 1 ;
V_1 = V_7 ;
break;
}
V_29 ++ ;
}
if ( V_89 )
break;
}
if ( ! V_89 )
return - V_95 ;
} else if ( V_29 >= V_19 [ V_1 ] -> V_94 ) {
return - V_96 ;
} else if ( F_43 ( V_29 , V_19 [ V_1 ] -> V_68 ) ) {
return - V_70 ;
}
F_12 ( V_1 , V_97 , 0 , V_29 >> 5 , F_35 ( V_29 & 0x1f ) ) ;
F_57 ( F_47 ( V_1 , V_29 ) ) ;
F_45 ( V_3 [ V_1 ] + F_46 ( V_29 ) ,
& V_71 , V_72 ) ;
if ( F_32 )
F_31 ( F_47 ( V_1 , V_29 ) ,
F_32 , V_31 ) ;
F_27 ( V_1 , V_29 , V_88 ) ;
return F_47 ( V_1 , V_29 ) ;
}
void F_58 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 >= V_19 [ V_1 ] -> V_94 )
return;
F_31 ( V_29 , NULL , NULL ) ;
F_45 ( V_3 [ V_1 ] + F_46 ( V_29 ) ,
& V_71 , V_72 ) ;
F_26 ( V_29 , V_19 [ V_1 ] -> V_68 ) ;
}
int F_59 ( unsigned V_1 , int V_45 )
{
if ( ! V_19 [ V_1 ] )
return - V_96 ;
if ( V_45 >= 0 )
V_45 = F_34 ( V_45 ) ;
if ( V_45 < 0 ) {
V_45 = V_19 [ V_1 ] -> V_94 ;
for (; ; ) {
V_45 = F_60 ( V_19 [ V_1 ] -> V_68 ,
V_19 [ V_1 ] -> V_62 , V_45 ) ;
if ( V_45 == V_19 [ V_1 ] -> V_62 )
return - V_95 ;
if ( ! F_43 ( V_45 , V_19 [ V_1 ] -> V_68 ) )
break;
}
} else if ( V_45 < V_19 [ V_1 ] -> V_94 ||
V_45 >= V_19 [ V_1 ] -> V_62 ) {
return - V_96 ;
} else if ( F_43 ( V_45 , V_19 [ V_1 ] -> V_68 ) ) {
return - V_70 ;
}
F_45 ( V_3 [ V_1 ] + F_46 ( V_45 ) ,
& V_71 , V_72 ) ;
return F_47 ( V_1 , V_45 ) ;
}
void F_61 ( unsigned V_45 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_94 ||
V_45 >= V_19 [ V_1 ] -> V_62 )
return;
F_45 ( V_3 [ V_1 ] + F_46 ( V_45 ) ,
& V_71 , V_72 ) ;
F_26 ( V_45 , V_19 [ V_1 ] -> V_68 ) ;
}
int F_62 ( unsigned V_1 , unsigned int V_61 , int V_45 , int V_64 )
{
if ( ( V_61 != V_98 ) &&
( V_45 < V_19 [ V_1 ] -> V_94 ||
V_45 >= V_19 [ V_1 ] -> V_62 ) )
return - V_96 ;
if ( V_64 < 1 || V_64 >
( V_19 [ V_1 ] -> V_62 - V_19 [ V_1 ] -> V_94 ) )
return - V_96 ;
switch ( V_61 ) {
case V_98 :
return F_41 ( V_1 , V_61 , V_64 ,
V_19 [ V_1 ] -> V_94 ) ;
case V_69 :
case V_99 :
return F_41 ( V_1 , V_61 , V_64 , V_45 ) ;
default:
return - V_96 ;
}
}
int F_63 ( unsigned V_45 , int V_64 )
{
unsigned V_1 , V_100 ;
int V_7 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_94 ||
V_45 >= V_19 [ V_1 ] -> V_62 ||
V_64 < 1 )
return - V_96 ;
for ( V_7 = V_45 ; V_7 < V_45 + V_64 ; ++ V_7 ) {
V_1 = F_33 ( V_7 ) ;
V_100 = F_34 ( V_7 ) ;
F_45 ( V_3 [ V_1 ] + F_46 ( V_100 ) ,
& V_71 , V_72 ) ;
F_26 ( V_100 , V_19 [ V_1 ] -> V_68 ) ;
}
return 0 ;
}
void F_64 ( unsigned V_45 , T_5 V_101 ,
enum V_102 V_103 , enum V_104 V_105 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
unsigned int V_7 = F_18 ( V_1 , V_106 , V_45 ) ;
if ( V_103 ) {
V_7 = ( V_7 & ~ ( V_107 ) ) | ( V_108 | ( ( V_105 & 0x7 ) << 8 ) ) ;
} else {
V_7 &= ~ V_108 ;
}
F_19 ( V_1 , V_106 , V_45 , V_7 ) ;
F_19 ( V_1 , V_109 , V_45 , V_101 ) ;
}
}
void F_65 ( unsigned V_45 , T_5 V_110 ,
enum V_102 V_103 , enum V_104 V_105 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
unsigned int V_7 = F_18 ( V_1 , V_106 , V_45 ) ;
if ( V_103 ) {
V_7 = ( V_7 & ~ ( V_107 ) ) | ( V_111 | ( ( V_105 & 0x7 ) << 8 ) ) ;
} else {
V_7 &= ~ V_111 ;
}
F_19 ( V_1 , V_106 , V_45 , V_7 ) ;
F_19 ( V_1 , V_112 , V_45 , V_110 ) ;
}
}
void F_66 ( unsigned V_45 , T_5 * V_113 , T_5 * V_114 )
{
struct V_115 V_116 ;
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
F_67 ( F_47 ( V_1 , V_45 ) , & V_116 ) ;
if ( V_113 != NULL )
* V_113 = V_116 . V_113 ;
if ( V_114 != NULL )
* V_114 = V_116 . V_114 ;
}
void F_68 ( unsigned V_45 , T_6 V_117 , T_6 V_118 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
F_20 ( V_1 , V_119 , V_45 ,
0xffff0000 , V_117 ) ;
F_20 ( V_1 , V_120 , V_45 ,
0xffff0000 , V_118 ) ;
}
}
void F_69 ( unsigned V_45 , T_6 V_121 , T_6 V_122 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
F_20 ( V_1 , V_119 , V_45 ,
0x0000ffff , V_121 << 16 ) ;
F_20 ( V_1 , V_120 , V_45 ,
0x0000ffff , V_122 << 16 ) ;
}
}
void F_70 ( unsigned V_45 ,
T_2 V_123 , T_2 V_124 , T_2 V_125 ,
T_2 V_126 , enum V_127 V_128 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
F_20 ( V_1 , V_129 , V_45 ,
0x0000ffff , V_126 << 16 ) ;
if ( V_128 == V_130 )
F_21 ( V_1 , V_106 , V_45 , ~ V_131 ) ;
else
F_22 ( V_1 , V_106 , V_45 , V_131 ) ;
F_19 ( V_1 , V_132 , V_45 , ( V_124 << 16 ) | V_123 ) ;
F_19 ( V_1 , V_133 , V_45 , V_125 ) ;
}
}
void F_71 ( unsigned V_134 , unsigned V_135 )
{
unsigned V_136 , V_137 ;
V_136 = F_33 ( V_134 ) ;
V_134 = F_34 ( V_134 ) ;
V_137 = F_33 ( V_135 ) ;
V_135 = F_34 ( V_135 ) ;
if ( V_134 >= V_19 [ V_136 ] -> V_62 )
return;
if ( V_135 >= V_19 [ V_137 ] -> V_62 )
return;
F_20 ( V_136 , V_129 , V_134 , 0xffff0000 ,
F_46 ( V_135 ) ) ;
}
void F_72 ( unsigned V_134 )
{
unsigned V_1 ;
V_1 = F_33 ( V_134 ) ;
V_134 = F_34 ( V_134 ) ;
if ( V_134 >= V_19 [ V_1 ] -> V_62 )
return;
F_22 ( V_1 , V_129 , V_134 , 0xffff ) ;
}
void F_73 ( unsigned V_45 , const struct V_115 * V_138 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 >= V_19 [ V_1 ] -> V_62 )
return;
F_45 ( V_3 [ V_1 ] + F_46 ( V_45 ) , V_138 ,
V_72 ) ;
}
void F_67 ( unsigned V_45 , struct V_115 * V_138 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 >= V_19 [ V_1 ] -> V_62 )
return;
F_74 ( V_138 , V_3 [ V_1 ] + F_46 ( V_45 ) ,
V_72 ) ;
}
void F_75 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_94 ) {
unsigned int V_139 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_140 , V_29 >> 5 , V_139 ) ;
}
}
void F_76 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_94 ) {
unsigned int V_139 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_141 , V_29 >> 5 , V_139 ) ;
}
}
int F_77 ( unsigned V_29 )
{
unsigned V_1 ;
unsigned int V_139 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
V_139 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_142 , ( V_29 >> 5 ) , V_139 ) ;
F_78 ( L_10 , ( V_29 >> 5 ) ,
F_15 ( V_1 , V_142 , ( V_29 >> 5 ) ) ) ;
return 0 ;
}
int F_79 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_94 ) {
int V_8 = V_29 >> 5 ;
unsigned int V_139 = F_35 ( V_29 & 0x1f ) ;
if ( F_80 ( V_29 , V_19 [ V_1 ] -> V_82 ) ) {
F_78 ( L_10 , V_8 ,
F_15 ( V_1 , V_142 , V_8 ) ) ;
F_17 ( V_1 , V_142 , V_8 , V_139 ) ;
return 0 ;
}
F_78 ( L_11 , V_8 ,
F_15 ( V_1 , V_143 , V_8 ) ) ;
F_9 ( V_1 , V_144 , V_8 , V_139 ) ;
F_9 ( V_1 , V_54 , V_8 , V_139 ) ;
F_17 ( V_1 , V_55 , V_8 , V_139 ) ;
F_17 ( V_1 , V_141 , V_8 , V_139 ) ;
F_78 ( L_12 , V_8 ,
F_15 ( V_1 , V_145 , V_8 ) ) ;
return 0 ;
}
return - V_96 ;
}
void F_57 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_94 ) {
int V_8 = V_29 >> 5 ;
unsigned int V_139 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_140 , V_8 , V_139 ) ;
F_17 ( V_1 , V_146 , V_8 , V_139 ) ;
F_17 ( V_1 , V_55 , V_8 , V_139 ) ;
F_9 ( V_1 , V_54 , V_8 , V_139 ) ;
F_78 ( L_12 , V_8 ,
F_15 ( V_1 , V_145 , V_8 ) ) ;
}
}
void F_81 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_94 ) {
int V_8 = ( V_29 >> 5 ) ;
unsigned int V_139 = F_35 ( V_29 & 0x1f ) ;
F_78 ( L_13 , V_8 ,
F_8 ( V_1 , V_50 , V_8 ) ) ;
F_17 ( V_1 , V_146 , V_8 , V_139 ) ;
F_9 ( V_1 , V_54 , V_8 , V_139 ) ;
F_17 ( V_1 , V_55 , V_8 , V_139 ) ;
F_3 ( V_1 , V_59 , F_35 ( 16 ) | F_35 ( 1 ) | F_35 ( 0 ) ) ;
}
}
void F_82 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 >= V_19 [ V_1 ] -> V_94 )
return;
if ( V_29 < 32 )
F_3 ( V_1 , V_144 , F_35 ( V_29 ) ) ;
else
F_3 ( V_1 , V_147 , F_35 ( V_29 - 32 ) ) ;
}
static int F_83 ( struct V_73 * V_74 , struct V_148 * V_149 ,
struct V_150 * V_151 , T_7 V_152 )
{
const char V_153 [] = L_14 ;
struct V_84 V_154 ;
void T_8 * V_155 ;
T_6 ( * V_156 ) [ 2 ] ;
T_7 V_157 = V_152 / sizeof( T_6 ) ;
T_4 V_158 , V_2 , V_159 ;
int V_90 , V_7 ;
V_156 = F_84 ( V_74 , ( V_157 + 2 ) * sizeof( T_6 ) , V_160 ) ;
if ( ! V_156 )
return - V_95 ;
V_90 = F_85 ( V_149 , 1 , & V_154 ) ;
if ( V_90 )
return - V_95 ;
V_155 = F_86 ( V_74 , V_154 . V_87 , F_87 ( & V_154 ) ) ;
if ( ! V_155 )
return - V_95 ;
V_90 = F_88 ( V_149 , V_153 , ( T_2 * ) V_156 , V_157 ) ;
if ( V_90 )
return - V_161 ;
V_157 >>= 1 ;
V_156 [ V_157 ] [ 0 ] = V_156 [ V_157 ] [ 1 ] = - 1 ;
for ( V_7 = 0 ; V_7 < V_157 ; V_7 ++ ) {
V_158 = ( V_156 [ V_7 ] [ 1 ] & 0x03 ) << 3 ;
V_2 = V_156 [ V_7 ] [ 1 ] & 0xfffffffc ;
V_159 = F_89 ( V_155 + V_2 ) ;
V_159 &= ~ ( 0xff << V_158 ) ;
V_159 |= V_156 [ V_7 ] [ 0 ] << V_158 ;
F_90 ( V_159 , ( V_155 + V_2 ) ) ;
}
V_151 -> V_156 = ( const T_6 ( * ) [ 2 ] ) V_156 ;
return 0 ;
}
static int F_91 ( struct V_73 * V_74 ,
struct V_148 * V_149 ,
struct V_150 * V_151 )
{
int V_90 = 0 , V_7 ;
T_4 V_162 ;
struct V_163 * V_164 ;
T_7 V_152 ;
struct V_165 * V_166 ;
F_92 ( * V_167 ) [ 2 ] , ( * V_168 ) [ 2 ] ;
memset ( V_151 , 0 , sizeof( struct V_150 ) ) ;
V_90 = F_93 ( V_149 , L_15 , & V_162 ) ;
if ( V_90 < 0 )
return V_90 ;
V_151 -> V_169 = V_162 ;
V_90 = F_93 ( V_149 , L_16 , & V_162 ) ;
if ( V_90 < 0 )
return V_90 ;
V_151 -> V_170 = V_162 ;
V_90 = F_93 ( V_149 , L_17 , & V_162 ) ;
if ( V_90 < 0 )
return V_90 ;
V_151 -> V_171 = V_162 ;
V_151 -> V_172 = 1 ;
V_166 = F_84 ( V_74 , sizeof( struct V_165 ) , V_160 ) ;
if ( ! V_166 )
return - V_95 ;
V_151 -> V_173 = V_166 ;
V_167 = F_84 ( V_74 , 8 * sizeof( F_92 ) , V_160 ) ;
if ( ! V_167 )
return - V_95 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_167 [ V_7 ] [ 0 ] = V_7 ;
V_167 [ V_7 ] [ 1 ] = V_7 ;
}
V_167 [ V_7 ] [ 0 ] = - 1 ;
V_167 [ V_7 ] [ 1 ] = - 1 ;
V_151 -> V_174 = V_167 ;
V_168 = F_84 ( V_74 , 8 * sizeof( F_92 ) , V_160 ) ;
if ( ! V_168 )
return - V_95 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_168 [ V_7 ] [ 0 ] = V_7 ;
V_168 [ V_7 ] [ 1 ] = V_7 ;
}
V_168 [ V_7 ] [ 0 ] = - 1 ;
V_168 [ V_7 ] [ 1 ] = - 1 ;
V_151 -> V_175 = V_168 ;
V_151 -> V_20 = 0 ;
V_164 = F_94 ( V_149 , L_14 , & V_152 ) ;
if ( V_164 )
V_90 = F_83 ( V_74 , V_149 , V_151 , V_152 ) ;
return V_90 ;
}
static struct V_150 * F_95 ( struct V_73 * V_74 ,
struct V_148 * V_149 )
{
struct V_150 * V_176 ;
int V_90 ;
V_176 = F_84 ( V_74 , sizeof( struct V_150 ) , V_160 ) ;
if ( ! V_176 )
return F_96 ( - V_95 ) ;
V_90 = F_91 ( V_74 , V_149 , V_176 ) ;
if ( V_90 )
return F_96 ( V_90 ) ;
F_97 ( V_177 , V_178 . V_179 ) ;
F_98 ( V_74 -> V_79 , V_180 ,
& V_178 ) ;
return V_176 ;
}
static struct V_150 * F_95 ( struct V_73 * V_74 ,
struct V_148 * V_149 )
{
return F_96 ( - V_181 ) ;
}
static int F_99 ( struct V_75 * V_76 )
{
struct V_150 * * V_176 = V_76 -> V_74 . V_182 ;
struct V_150 * V_183 [ V_184 ] = { NULL } ;
F_92 ( * V_175 ) [ 2 ] ;
F_92 ( * V_174 ) [ 2 ] ;
int V_7 , V_8 , V_185 , V_186 , V_187 = 0 ;
int V_188 = - 1 ;
const T_6 ( * V_189 ) [ 2 ] ;
const T_6 ( * V_190 ) [ 2 ] ;
const T_6 ( * V_156 ) [ 2 ] ;
int V_36 [ V_184 ] = { 0 , 0 } ;
int V_191 [ V_184 ] = { 0 , 0 } ;
struct V_84 * V_192 [ V_184 ] = { NULL } ;
struct V_84 V_154 [ V_184 ] ;
char V_193 [ 10 ] ;
char V_194 [ 10 ] ;
struct V_148 * V_149 = V_76 -> V_74 . V_79 ;
struct V_73 * V_74 = & V_76 -> V_74 ;
int V_90 ;
if ( V_149 ) {
if ( V_93 ) {
F_100 ( V_74 , L_18 ) ;
return - V_195 ;
}
V_183 [ 0 ] = F_95 ( V_74 , V_149 ) ;
if ( F_101 ( V_183 [ 0 ] ) ) {
F_100 ( V_74 , L_19 ) ;
return F_102 ( V_183 [ 0 ] ) ;
}
V_176 = V_183 ;
}
if ( ! V_176 )
return - V_195 ;
F_103 ( V_74 ) ;
V_90 = F_104 ( V_74 ) ;
if ( V_90 < 0 ) {
F_100 ( V_74 , L_20 ) ;
return V_90 ;
}
for ( V_8 = 0 ; V_8 < V_184 ; V_8 ++ ) {
if ( ! V_176 [ V_8 ] ) {
if ( ! V_187 )
return - V_195 ;
break;
}
if ( V_149 ) {
V_90 = F_85 ( V_149 , V_8 , & V_154 [ V_8 ] ) ;
if ( ! V_90 )
V_192 [ V_8 ] = & V_154 [ V_8 ] ;
} else {
sprintf ( V_193 , L_21 , V_8 ) ;
V_192 [ V_8 ] = F_105 ( V_76 ,
V_196 ,
V_193 ) ;
}
if ( ! V_192 [ V_8 ] ) {
if ( V_187 )
break;
else
return - V_195 ;
} else {
V_187 = 1 ;
}
V_3 [ V_8 ] = F_106 ( & V_76 -> V_74 , V_192 [ V_8 ] ) ;
if ( F_101 ( V_3 [ V_8 ] ) )
return F_102 ( V_3 [ V_8 ] ) ;
V_19 [ V_8 ] = F_84 ( & V_76 -> V_74 , sizeof( struct V_197 ) ,
V_160 ) ;
if ( ! V_19 [ V_8 ] )
return - V_95 ;
V_19 [ V_8 ] -> V_94 = F_107 ( unsigned , V_176 [ V_8 ] -> V_169 ,
V_26 ) ;
V_19 [ V_8 ] -> V_62 = F_107 ( unsigned , V_176 [ V_8 ] -> V_171 ,
V_67 ) ;
V_19 [ V_8 ] -> V_198 = F_107 ( unsigned , V_176 [ V_8 ] -> V_172 ,
V_184 ) ;
V_19 [ V_8 ] -> V_20 = V_176 [ V_8 ] -> V_20 ;
F_38 ( & V_76 -> V_74 , L_22 ,
V_3 [ V_8 ] ) ;
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_62 ; V_7 ++ )
F_45 ( V_3 [ V_8 ] + F_46 ( V_7 ) ,
& V_71 , V_72 ) ;
memset ( V_19 [ V_8 ] -> V_82 , 0xff ,
sizeof( V_19 [ V_8 ] -> V_82 ) ) ;
if ( V_176 [ V_8 ] -> V_173 ) {
V_189 = V_176 [ V_8 ] -> V_173 -> V_189 ;
if ( V_189 ) {
for ( V_7 = 0 ; V_189 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_185 = V_189 [ V_7 ] [ 0 ] ;
V_186 = V_189 [ V_7 ] [ 1 ] ;
F_25 ( V_185 , V_186 ,
V_19 [ V_8 ] -> V_82 ) ;
}
}
V_190 = V_176 [ V_8 ] -> V_173 -> V_190 ;
if ( V_190 ) {
for ( V_7 = 0 ; V_190 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_185 = V_190 [ V_7 ] [ 0 ] ;
V_186 = V_190 [ V_7 ] [ 1 ] ;
F_23 ( V_185 , V_186 ,
V_19 [ V_8 ] -> V_68 ) ;
}
}
}
V_156 = V_176 [ V_8 ] -> V_156 ;
if ( V_156 ) {
for ( V_7 = 0 ; V_156 [ V_7 ] [ 1 ] != - 1 ; V_7 ++ ) {
V_185 = V_156 [ V_7 ] [ 1 ] ;
F_25 ( V_185 , 1 ,
V_19 [ V_8 ] -> V_82 ) ;
}
}
if ( V_149 ) {
V_36 [ V_8 ] = F_108 ( V_149 , 0 ) ;
} else {
sprintf ( V_194 , L_23 , V_8 ) ;
V_36 [ V_8 ] = F_109 ( V_76 , V_194 ) ;
}
V_19 [ V_8 ] -> V_37 = V_36 [ V_8 ] ;
V_188 = F_110 ( & V_76 -> V_74 , V_36 [ V_8 ] ,
F_37 , 0 , L_24 ,
& V_76 -> V_74 ) ;
if ( V_188 < 0 ) {
F_38 ( & V_76 -> V_74 ,
L_25 ,
V_36 [ V_8 ] , V_188 ) ;
return V_188 ;
}
if ( V_149 ) {
V_191 [ V_8 ] = F_108 ( V_149 , 2 ) ;
} else {
sprintf ( V_194 , L_26 , V_8 ) ;
V_191 [ V_8 ] = F_109 ( V_76 , V_194 ) ;
}
V_19 [ V_8 ] -> V_38 = V_191 [ V_8 ] ;
V_188 = F_110 ( & V_76 -> V_74 , V_191 [ V_8 ] ,
F_40 , 0 ,
L_27 , & V_76 -> V_74 ) ;
if ( V_188 < 0 ) {
F_38 ( & V_76 -> V_74 ,
L_25 ,
V_191 [ V_8 ] , V_188 ) ;
return V_188 ;
}
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_94 ; V_7 ++ )
F_27 ( V_8 , V_7 , V_176 [ V_8 ] -> V_20 ) ;
V_174 = V_176 [ V_8 ] -> V_174 ;
V_175 = V_176 [ V_8 ] -> V_175 ;
for ( V_7 = 0 ; V_174 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ )
F_28 ( V_8 , V_174 [ V_7 ] [ 0 ] ,
V_174 [ V_7 ] [ 1 ] ) ;
for ( V_7 = 0 ; V_175 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ )
F_29 ( V_8 ,
V_175 [ V_7 ] [ 0 ] ,
V_175 [ V_7 ] [ 1 ] ) ;
if ( F_1 ( V_8 , V_199 ) & V_200 )
F_30 ( V_8 ) ;
for ( V_7 = 0 ; V_7 < V_176 [ V_8 ] -> V_170 ; V_7 ++ ) {
F_13 ( V_8 , V_97 , V_7 , 0 , 0x0 ) ;
F_13 ( V_8 , V_97 , V_7 , 1 , 0x0 ) ;
F_9 ( V_8 , V_201 , V_7 , 0x0 ) ;
}
V_93 ++ ;
}
return 0 ;
}
static int T_1 F_111 ( void )
{
return F_112 ( & V_202 , F_99 ) ;
}
