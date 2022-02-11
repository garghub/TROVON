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
int V_7 , V_1 ;
for ( V_7 = 0 ; V_7 < V_76 -> V_77 ; V_7 ++ ) {
if ( ( V_76 -> V_78 [ V_7 ] . V_79 & V_80 ) &&
( int ) V_76 -> V_78 [ V_7 ] . V_81 >= 0 ) {
V_1 = F_33 ( V_76 -> V_78 [ V_7 ] . V_81 ) ;
F_26 ( F_34 ( V_76 -> V_78 [ V_7 ] . V_81 ) ,
V_19 [ V_1 ] -> V_82 ) ;
}
}
return 0 ;
}
int F_50 ( int V_29 ,
void (* F_32)( unsigned V_29 , T_2 V_30 , void * V_31 ) ,
void * V_31 ,
enum V_15 V_83 )
{
unsigned V_7 , V_84 = 0 , V_1 = 0 ;
int V_85 = 0 ;
if ( ! V_86 ) {
V_85 = F_51 ( & V_87 , NULL , NULL ,
F_48 ) ;
if ( V_85 < 0 )
return V_85 ;
V_86 = true ;
}
if ( V_29 >= 0 ) {
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
}
if ( V_29 < 0 ) {
for ( V_7 = 0 ; V_7 < V_88 ; V_7 ++ ) {
V_29 = 0 ;
for (; ; ) {
V_29 = F_52 ( V_19 [ V_7 ] -> V_82 ,
V_19 [ V_7 ] -> V_89 ,
V_29 ) ;
if ( V_29 == V_19 [ V_7 ] -> V_89 )
break;
if ( ! F_43 ( V_29 ,
V_19 [ V_7 ] -> V_68 ) ) {
V_84 = 1 ;
V_1 = V_7 ;
break;
}
V_29 ++ ;
}
if ( V_84 )
break;
}
if ( ! V_84 )
return - V_90 ;
} else if ( V_29 >= V_19 [ V_1 ] -> V_89 ) {
return - V_91 ;
} else if ( F_43 ( V_29 , V_19 [ V_1 ] -> V_68 ) ) {
return - V_70 ;
}
F_12 ( V_1 , V_92 , 0 , V_29 >> 5 , F_35 ( V_29 & 0x1f ) ) ;
F_53 ( F_47 ( V_1 , V_29 ) ) ;
F_45 ( V_3 [ V_1 ] + F_46 ( V_29 ) ,
& V_71 , V_72 ) ;
if ( F_32 )
F_31 ( F_47 ( V_1 , V_29 ) ,
F_32 , V_31 ) ;
F_27 ( V_1 , V_29 , V_83 ) ;
return F_47 ( V_1 , V_29 ) ;
}
void F_54 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 >= V_19 [ V_1 ] -> V_89 )
return;
F_31 ( V_29 , NULL , NULL ) ;
F_45 ( V_3 [ V_1 ] + F_46 ( V_29 ) ,
& V_71 , V_72 ) ;
F_26 ( V_29 , V_19 [ V_1 ] -> V_68 ) ;
}
int F_55 ( unsigned V_1 , int V_45 )
{
if ( ! V_19 [ V_1 ] )
return - V_91 ;
if ( V_45 >= 0 )
V_45 = F_34 ( V_45 ) ;
if ( V_45 < 0 ) {
V_45 = V_19 [ V_1 ] -> V_89 ;
for (; ; ) {
V_45 = F_56 ( V_19 [ V_1 ] -> V_68 ,
V_19 [ V_1 ] -> V_62 , V_45 ) ;
if ( V_45 == V_19 [ V_1 ] -> V_62 )
return - V_90 ;
if ( ! F_43 ( V_45 , V_19 [ V_1 ] -> V_68 ) )
break;
}
} else if ( V_45 < V_19 [ V_1 ] -> V_89 ||
V_45 >= V_19 [ V_1 ] -> V_62 ) {
return - V_91 ;
} else if ( F_43 ( V_45 , V_19 [ V_1 ] -> V_68 ) ) {
return - V_70 ;
}
F_45 ( V_3 [ V_1 ] + F_46 ( V_45 ) ,
& V_71 , V_72 ) ;
return F_47 ( V_1 , V_45 ) ;
}
void F_57 ( unsigned V_45 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_89 ||
V_45 >= V_19 [ V_1 ] -> V_62 )
return;
F_45 ( V_3 [ V_1 ] + F_46 ( V_45 ) ,
& V_71 , V_72 ) ;
F_26 ( V_45 , V_19 [ V_1 ] -> V_68 ) ;
}
int F_58 ( unsigned V_1 , unsigned int V_61 , int V_45 , int V_64 )
{
if ( ( V_61 != V_93 ) &&
( V_45 < V_19 [ V_1 ] -> V_89 ||
V_45 >= V_19 [ V_1 ] -> V_62 ) )
return - V_91 ;
if ( V_64 < 1 || V_64 >
( V_19 [ V_1 ] -> V_62 - V_19 [ V_1 ] -> V_89 ) )
return - V_91 ;
switch ( V_61 ) {
case V_93 :
return F_41 ( V_1 , V_61 , V_64 ,
V_19 [ V_1 ] -> V_89 ) ;
case V_69 :
case V_94 :
return F_41 ( V_1 , V_61 , V_64 , V_45 ) ;
default:
return - V_91 ;
}
}
int F_59 ( unsigned V_45 , int V_64 )
{
unsigned V_1 , V_95 ;
int V_7 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_89 ||
V_45 >= V_19 [ V_1 ] -> V_62 ||
V_64 < 1 )
return - V_91 ;
for ( V_7 = V_45 ; V_7 < V_45 + V_64 ; ++ V_7 ) {
V_1 = F_33 ( V_7 ) ;
V_95 = F_34 ( V_7 ) ;
F_45 ( V_3 [ V_1 ] + F_46 ( V_95 ) ,
& V_71 , V_72 ) ;
F_26 ( V_95 , V_19 [ V_1 ] -> V_68 ) ;
}
return 0 ;
}
void F_60 ( unsigned V_45 , T_5 V_96 ,
enum V_97 V_98 , enum V_99 V_100 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
unsigned int V_7 = F_18 ( V_1 , V_101 , V_45 ) ;
if ( V_98 ) {
V_7 = ( V_7 & ~ ( V_102 ) ) | ( V_103 | ( ( V_100 & 0x7 ) << 8 ) ) ;
} else {
V_7 &= ~ V_103 ;
}
F_19 ( V_1 , V_101 , V_45 , V_7 ) ;
F_19 ( V_1 , V_104 , V_45 , V_96 ) ;
}
}
void F_61 ( unsigned V_45 , T_5 V_105 ,
enum V_97 V_98 , enum V_99 V_100 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
unsigned int V_7 = F_18 ( V_1 , V_101 , V_45 ) ;
if ( V_98 ) {
V_7 = ( V_7 & ~ ( V_102 ) ) | ( V_106 | ( ( V_100 & 0x7 ) << 8 ) ) ;
} else {
V_7 &= ~ V_106 ;
}
F_19 ( V_1 , V_101 , V_45 , V_7 ) ;
F_19 ( V_1 , V_107 , V_45 , V_105 ) ;
}
}
void F_62 ( unsigned V_45 , T_5 * V_108 , T_5 * V_109 )
{
struct V_110 V_111 ;
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
F_63 ( F_47 ( V_1 , V_45 ) , & V_111 ) ;
if ( V_108 != NULL )
* V_108 = V_111 . V_108 ;
if ( V_109 != NULL )
* V_109 = V_111 . V_109 ;
}
void F_64 ( unsigned V_45 , T_6 V_112 , T_6 V_113 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
F_20 ( V_1 , V_114 , V_45 ,
0xffff0000 , V_112 ) ;
F_20 ( V_1 , V_115 , V_45 ,
0xffff0000 , V_113 ) ;
}
}
void F_65 ( unsigned V_45 , T_6 V_116 , T_6 V_117 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
F_20 ( V_1 , V_114 , V_45 ,
0x0000ffff , V_116 << 16 ) ;
F_20 ( V_1 , V_115 , V_45 ,
0x0000ffff , V_117 << 16 ) ;
}
}
void F_66 ( unsigned V_45 ,
T_2 V_118 , T_2 V_119 , T_2 V_120 ,
T_2 V_121 , enum V_122 V_123 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 < V_19 [ V_1 ] -> V_62 ) {
F_20 ( V_1 , V_124 , V_45 ,
0x0000ffff , V_121 << 16 ) ;
if ( V_123 == V_125 )
F_21 ( V_1 , V_101 , V_45 , ~ V_126 ) ;
else
F_22 ( V_1 , V_101 , V_45 , V_126 ) ;
F_19 ( V_1 , V_127 , V_45 , ( V_119 << 16 ) | V_118 ) ;
F_19 ( V_1 , V_128 , V_45 , V_120 ) ;
}
}
void F_67 ( unsigned V_129 , unsigned V_130 )
{
unsigned V_131 , V_132 ;
V_131 = F_33 ( V_129 ) ;
V_129 = F_34 ( V_129 ) ;
V_132 = F_33 ( V_130 ) ;
V_130 = F_34 ( V_130 ) ;
if ( V_129 >= V_19 [ V_131 ] -> V_62 )
return;
if ( V_130 >= V_19 [ V_132 ] -> V_62 )
return;
F_20 ( V_131 , V_124 , V_129 , 0xffff0000 ,
F_46 ( V_130 ) ) ;
}
void F_68 ( unsigned V_129 )
{
unsigned V_1 ;
V_1 = F_33 ( V_129 ) ;
V_129 = F_34 ( V_129 ) ;
if ( V_129 >= V_19 [ V_1 ] -> V_62 )
return;
F_22 ( V_1 , V_124 , V_129 , 0xffff ) ;
}
void F_69 ( unsigned V_45 , const struct V_110 * V_133 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 >= V_19 [ V_1 ] -> V_62 )
return;
F_45 ( V_3 [ V_1 ] + F_46 ( V_45 ) , V_133 ,
V_72 ) ;
}
void F_63 ( unsigned V_45 , struct V_110 * V_133 )
{
unsigned V_1 ;
V_1 = F_33 ( V_45 ) ;
V_45 = F_34 ( V_45 ) ;
if ( V_45 >= V_19 [ V_1 ] -> V_62 )
return;
F_70 ( V_133 , V_3 [ V_1 ] + F_46 ( V_45 ) ,
V_72 ) ;
}
void F_71 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_89 ) {
unsigned int V_134 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_135 , V_29 >> 5 , V_134 ) ;
}
}
void F_72 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_89 ) {
unsigned int V_134 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_136 , V_29 >> 5 , V_134 ) ;
}
}
int F_73 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_89 ) {
int V_8 = V_29 >> 5 ;
unsigned int V_134 = F_35 ( V_29 & 0x1f ) ;
if ( F_74 ( V_29 , V_19 [ V_1 ] -> V_82 ) ) {
F_75 ( L_7 , V_8 ,
F_15 ( V_1 , V_137 , V_8 ) ) ;
F_17 ( V_1 , V_137 , V_8 , V_134 ) ;
return 0 ;
}
F_75 ( L_8 , V_8 ,
F_15 ( V_1 , V_138 , V_8 ) ) ;
F_9 ( V_1 , V_139 , V_8 , V_134 ) ;
F_9 ( V_1 , V_54 , V_8 , V_134 ) ;
F_17 ( V_1 , V_55 , V_8 , V_134 ) ;
F_17 ( V_1 , V_136 , V_8 , V_134 ) ;
F_75 ( L_9 , V_8 ,
F_15 ( V_1 , V_140 , V_8 ) ) ;
return 0 ;
}
return - V_91 ;
}
void F_53 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_89 ) {
int V_8 = V_29 >> 5 ;
unsigned int V_134 = F_35 ( V_29 & 0x1f ) ;
F_17 ( V_1 , V_135 , V_8 , V_134 ) ;
F_17 ( V_1 , V_141 , V_8 , V_134 ) ;
F_17 ( V_1 , V_55 , V_8 , V_134 ) ;
F_9 ( V_1 , V_54 , V_8 , V_134 ) ;
F_75 ( L_9 , V_8 ,
F_15 ( V_1 , V_140 , V_8 ) ) ;
}
}
void F_76 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 < V_19 [ V_1 ] -> V_89 ) {
int V_8 = ( V_29 >> 5 ) ;
unsigned int V_134 = F_35 ( V_29 & 0x1f ) ;
F_75 ( L_10 , V_8 ,
F_8 ( V_1 , V_50 , V_8 ) ) ;
F_17 ( V_1 , V_141 , V_8 , V_134 ) ;
F_9 ( V_1 , V_54 , V_8 , V_134 ) ;
F_17 ( V_1 , V_55 , V_8 , V_134 ) ;
F_3 ( V_1 , V_59 , F_35 ( 16 ) | F_35 ( 1 ) | F_35 ( 0 ) ) ;
}
}
void F_77 ( unsigned V_29 )
{
unsigned V_1 ;
V_1 = F_33 ( V_29 ) ;
V_29 = F_34 ( V_29 ) ;
if ( V_29 >= V_19 [ V_1 ] -> V_89 )
return;
if ( V_29 < 32 )
F_3 ( V_1 , V_139 , F_35 ( V_29 ) ) ;
else
F_3 ( V_1 , V_142 , F_35 ( V_29 - 32 ) ) ;
}
static int F_78 ( const struct V_143 * V_144 ,
const char * V_145 , T_6 * V_146 ,
T_7 V_147 )
{
int V_85 ;
V_85 = F_79 ( V_144 , V_145 , V_146 , V_147 ) ;
if ( V_85 )
return V_85 ;
* V_146 ++ = - 1 ;
* V_146 ++ = - 1 ;
return 0 ;
}
static int F_80 ( struct V_73 * V_74 ,
struct V_143 * V_148 ,
struct V_149 * V_150 , int V_12 )
{
int V_85 , V_7 ;
struct V_78 V_151 ;
void T_8 * V_152 ;
const T_6 ( * V_153 ) [ 2 ] ;
T_4 V_154 , V_2 , V_155 ;
V_153 = F_81 ( V_74 ,
V_12 / sizeof( T_6 ) + 2 * sizeof( T_6 ) ,
V_156 ) ;
if ( ! V_153 )
return - V_90 ;
V_85 = F_82 ( V_148 , 1 , & V_151 ) ;
if ( V_85 )
return - V_157 ;
V_152 = F_83 ( V_74 , V_151 . V_81 , F_84 ( & V_151 ) ) ;
if ( ! V_152 )
return - V_90 ;
V_85 = F_78 ( V_148 ,
L_11 ,
( T_6 * ) V_153 ,
V_12 / sizeof( T_4 ) ) ;
if ( V_85 )
return - V_157 ;
for ( V_7 = 0 ; V_153 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_154 = ( V_153 [ V_7 ] [ 1 ] & 0x03 ) << 3 ;
V_2 = V_153 [ V_7 ] [ 1 ] & 0xfffffffc ;
V_155 = F_85 ( V_152 + V_2 ) ;
V_155 &= ~ ( 0xff << V_154 ) ;
V_155 |= V_153 [ V_7 ] [ 0 ] << V_154 ;
F_86 ( V_155 , ( V_152 + V_2 ) ) ;
}
V_150 -> V_153 = V_153 ;
return 0 ;
}
static int F_87 ( struct V_73 * V_74 ,
struct V_143 * V_148 ,
struct V_149 * V_150 )
{
int V_85 = 0 , V_7 ;
T_4 V_158 ;
struct V_159 * V_160 ;
T_7 V_147 ;
struct V_161 * V_162 ;
F_88 ( * V_163 ) [ 2 ] , ( * V_164 ) [ 2 ] ;
memset ( V_150 , 0 , sizeof( struct V_149 ) ) ;
V_85 = F_89 ( V_148 , L_12 , & V_158 ) ;
if ( V_85 < 0 )
return V_85 ;
V_150 -> V_165 = V_158 ;
V_85 = F_89 ( V_148 , L_13 , & V_158 ) ;
if ( V_85 < 0 )
return V_85 ;
V_150 -> V_166 = V_158 ;
V_85 = F_89 ( V_148 , L_14 , & V_158 ) ;
if ( V_85 < 0 )
return V_85 ;
V_150 -> V_167 = V_158 ;
V_150 -> V_168 = 1 ;
V_162 = F_81 ( V_74 , sizeof( struct V_161 ) , V_156 ) ;
if ( ! V_162 )
return - V_90 ;
V_150 -> V_169 = V_162 ;
V_163 = F_81 ( V_74 , 8 * sizeof( F_88 ) , V_156 ) ;
if ( ! V_163 )
return - V_90 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_163 [ V_7 ] [ 0 ] = V_7 ;
V_163 [ V_7 ] [ 1 ] = V_7 ;
}
V_163 [ V_7 ] [ 0 ] = - 1 ;
V_163 [ V_7 ] [ 1 ] = - 1 ;
V_150 -> V_170 = V_163 ;
V_164 = F_81 ( V_74 , 8 * sizeof( F_88 ) , V_156 ) ;
if ( ! V_164 )
return - V_90 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_164 [ V_7 ] [ 0 ] = V_7 ;
V_164 [ V_7 ] [ 1 ] = V_7 ;
}
V_164 [ V_7 ] [ 0 ] = - 1 ;
V_164 [ V_7 ] [ 1 ] = - 1 ;
V_150 -> V_171 = V_164 ;
V_150 -> V_20 = 0 ;
V_160 = F_90 ( V_148 , L_11 , & V_147 ) ;
if ( V_160 )
V_85 = F_80 ( V_74 , V_148 , V_150 , V_147 ) ;
return V_85 ;
}
static struct V_149 * F_91 ( struct V_73 * V_74 ,
struct V_143 * V_148 )
{
struct V_149 * V_172 ;
int V_85 ;
V_172 = F_81 ( V_74 , sizeof( struct V_149 ) , V_156 ) ;
if ( ! V_172 )
return F_92 ( - V_90 ) ;
V_85 = F_87 ( V_74 , V_148 , V_172 ) ;
if ( V_85 )
return F_92 ( V_85 ) ;
F_93 ( V_173 , V_174 . V_175 ) ;
F_94 ( V_74 -> V_176 , V_177 ,
& V_174 ) ;
return V_172 ;
}
static struct V_149 * F_91 ( struct V_73 * V_74 ,
struct V_143 * V_148 )
{
return F_92 ( - V_178 ) ;
}
static int F_95 ( struct V_75 * V_76 )
{
struct V_149 * * V_172 = V_76 -> V_74 . V_179 ;
struct V_149 * V_180 [ V_181 ] = { NULL } ;
F_88 ( * V_171 ) [ 2 ] ;
F_88 ( * V_170 ) [ 2 ] ;
int V_7 , V_8 , V_182 , V_183 , V_184 = 0 ;
int V_185 = - 1 ;
const T_6 ( * V_186 ) [ 2 ] ;
const T_6 ( * V_187 ) [ 2 ] ;
const T_6 ( * V_153 ) [ 2 ] ;
int V_36 [ V_181 ] = { 0 , 0 } ;
int V_188 [ V_181 ] = { 0 , 0 } ;
struct V_78 * V_189 [ V_181 ] = { NULL } ;
struct V_78 V_151 [ V_181 ] ;
char V_190 [ 10 ] ;
char V_191 [ 10 ] ;
struct V_143 * V_148 = V_76 -> V_74 . V_176 ;
struct V_73 * V_74 = & V_76 -> V_74 ;
int V_85 ;
if ( V_148 ) {
if ( V_88 ) {
F_96 ( V_74 , L_15 ) ;
return - V_192 ;
}
V_180 [ 0 ] = F_91 ( V_74 , V_148 ) ;
if ( F_97 ( V_180 [ 0 ] ) ) {
F_96 ( V_74 , L_16 ) ;
return F_98 ( V_180 [ 0 ] ) ;
}
V_172 = V_180 ;
}
if ( ! V_172 )
return - V_192 ;
F_99 ( V_74 ) ;
V_85 = F_100 ( V_74 ) ;
if ( V_85 < 0 ) {
F_96 ( V_74 , L_17 ) ;
return V_85 ;
}
for ( V_8 = 0 ; V_8 < V_181 ; V_8 ++ ) {
if ( ! V_172 [ V_8 ] ) {
if ( ! V_184 )
return - V_192 ;
break;
}
if ( V_148 ) {
V_85 = F_82 ( V_148 , V_8 , & V_151 [ V_8 ] ) ;
if ( ! V_85 )
V_189 [ V_8 ] = & V_151 [ V_8 ] ;
} else {
sprintf ( V_190 , L_18 , V_8 ) ;
V_189 [ V_8 ] = F_101 ( V_76 ,
V_193 ,
V_190 ) ;
}
if ( ! V_189 [ V_8 ] ) {
if ( V_184 )
break;
else
return - V_192 ;
} else {
V_184 = 1 ;
}
V_3 [ V_8 ] = F_102 ( & V_76 -> V_74 , V_189 [ V_8 ] ) ;
if ( F_97 ( V_3 [ V_8 ] ) )
return F_98 ( V_3 [ V_8 ] ) ;
V_19 [ V_8 ] = F_81 ( & V_76 -> V_74 , sizeof( struct V_194 ) ,
V_156 ) ;
if ( ! V_19 [ V_8 ] )
return - V_90 ;
V_19 [ V_8 ] -> V_89 = F_103 ( unsigned , V_172 [ V_8 ] -> V_165 ,
V_26 ) ;
V_19 [ V_8 ] -> V_62 = F_103 ( unsigned , V_172 [ V_8 ] -> V_167 ,
V_67 ) ;
V_19 [ V_8 ] -> V_195 = F_103 ( unsigned , V_172 [ V_8 ] -> V_168 ,
V_181 ) ;
V_19 [ V_8 ] -> V_20 = V_172 [ V_8 ] -> V_20 ;
F_38 ( & V_76 -> V_74 , L_19 ,
V_3 [ V_8 ] ) ;
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_62 ; V_7 ++ )
F_45 ( V_3 [ V_8 ] + F_46 ( V_7 ) ,
& V_71 , V_72 ) ;
memset ( V_19 [ V_8 ] -> V_82 , 0xff ,
sizeof( V_19 [ V_8 ] -> V_82 ) ) ;
if ( V_172 [ V_8 ] -> V_169 ) {
V_186 = V_172 [ V_8 ] -> V_169 -> V_186 ;
if ( V_186 ) {
for ( V_7 = 0 ; V_186 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_182 = V_186 [ V_7 ] [ 0 ] ;
V_183 = V_186 [ V_7 ] [ 1 ] ;
F_25 ( V_182 , V_183 ,
V_19 [ V_8 ] -> V_82 ) ;
}
}
V_187 = V_172 [ V_8 ] -> V_169 -> V_187 ;
if ( V_187 ) {
for ( V_7 = 0 ; V_187 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ ) {
V_182 = V_187 [ V_7 ] [ 0 ] ;
V_183 = V_187 [ V_7 ] [ 1 ] ;
F_23 ( V_182 , V_183 ,
V_19 [ V_8 ] -> V_68 ) ;
}
}
}
V_153 = V_172 [ V_8 ] -> V_153 ;
if ( V_153 ) {
for ( V_7 = 0 ; V_153 [ V_7 ] [ 1 ] != - 1 ; V_7 ++ ) {
V_182 = V_153 [ V_7 ] [ 1 ] ;
F_25 ( V_182 , 1 ,
V_19 [ V_8 ] -> V_82 ) ;
}
}
if ( V_148 ) {
V_36 [ V_8 ] = F_104 ( V_148 , 0 ) ;
} else {
sprintf ( V_191 , L_20 , V_8 ) ;
V_36 [ V_8 ] = F_105 ( V_76 , V_191 ) ;
}
V_19 [ V_8 ] -> V_37 = V_36 [ V_8 ] ;
V_185 = F_106 ( & V_76 -> V_74 , V_36 [ V_8 ] ,
F_37 , 0 , L_21 ,
& V_76 -> V_74 ) ;
if ( V_185 < 0 ) {
F_38 ( & V_76 -> V_74 ,
L_22 ,
V_36 [ V_8 ] , V_185 ) ;
return V_185 ;
}
if ( V_148 ) {
V_188 [ V_8 ] = F_104 ( V_148 , 2 ) ;
} else {
sprintf ( V_191 , L_23 , V_8 ) ;
V_188 [ V_8 ] = F_105 ( V_76 , V_191 ) ;
}
V_19 [ V_8 ] -> V_38 = V_188 [ V_8 ] ;
V_185 = F_106 ( & V_76 -> V_74 , V_188 [ V_8 ] ,
F_40 , 0 ,
L_24 , & V_76 -> V_74 ) ;
if ( V_185 < 0 ) {
F_38 ( & V_76 -> V_74 ,
L_22 ,
V_188 [ V_8 ] , V_185 ) ;
return V_185 ;
}
for ( V_7 = 0 ; V_7 < V_19 [ V_8 ] -> V_89 ; V_7 ++ )
F_27 ( V_8 , V_7 , V_172 [ V_8 ] -> V_20 ) ;
V_170 = V_172 [ V_8 ] -> V_170 ;
V_171 = V_172 [ V_8 ] -> V_171 ;
for ( V_7 = 0 ; V_170 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ )
F_28 ( V_8 , V_170 [ V_7 ] [ 0 ] ,
V_170 [ V_7 ] [ 1 ] ) ;
for ( V_7 = 0 ; V_171 [ V_7 ] [ 0 ] != - 1 ; V_7 ++ )
F_29 ( V_8 ,
V_171 [ V_7 ] [ 0 ] ,
V_171 [ V_7 ] [ 1 ] ) ;
if ( F_1 ( V_8 , V_196 ) & V_197 )
F_30 ( V_8 ) ;
for ( V_7 = 0 ; V_7 < V_172 [ V_8 ] -> V_166 ; V_7 ++ ) {
F_13 ( V_8 , V_92 , V_7 , 0 , 0x0 ) ;
F_13 ( V_8 , V_92 , V_7 , 1 , 0x0 ) ;
F_9 ( V_8 , V_198 , V_7 , 0x0 ) ;
}
V_88 ++ ;
}
return 0 ;
}
static int T_1 F_107 ( void )
{
return F_108 ( & V_199 , F_95 ) ;
}
