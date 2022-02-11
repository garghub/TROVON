int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , int V_5 )
{
F_2 ( L_1 , V_6 ,
V_3 , V_4 , V_5 ) ;
if ( ( V_2 -> V_7 -> V_8 & V_9 ) || ( V_2 -> V_7 -> V_10 & V_11 ) )
return - V_12 ;
if ( V_3 & 0x7 )
return - V_13 ;
if ( V_3 > 32 )
return - V_13 ;
if ( V_3 ) {
V_2 -> V_7 -> V_14 = ( ( V_3 >> 3 ) - 1 ) << 12 ;
V_2 -> V_7 -> V_15 = V_16 | V_17 | \
( V_5 ? ( V_18 | V_19 ) : 0 ) ;
V_2 -> V_7 -> V_20 = V_4 ;
V_2 -> V_7 -> V_21 = V_4 ;
V_2 -> V_7 -> V_22 = 0 ;
V_2 -> V_7 -> V_23 = 0 ;
V_2 -> V_7 -> V_24 = 0 ;
V_2 -> V_7 -> V_25 = 0 ;
V_2 -> V_7 -> V_26 = 0 ;
V_2 -> V_7 -> V_27 = 0 ;
} else {
V_2 -> V_7 -> V_14 = 0 ;
V_2 -> V_7 -> V_15 = 0 ;
V_2 -> V_7 -> V_20 = 0 ;
V_2 -> V_7 -> V_21 = 0 ;
}
V_2 -> V_7 -> V_22 = 0 ; V_2 -> V_7 -> V_24 = 0 ; V_2 -> V_7 -> V_26 = 0 ;
V_2 -> V_7 -> V_23 = 0 ; V_2 -> V_7 -> V_25 = 0 ; V_2 -> V_7 -> V_27 = 0 ;
F_3 () ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned int V_28 , unsigned int V_29 , unsigned int V_30 )
{
if ( ( V_2 -> V_7 -> V_8 & V_9 ) || ( V_2 -> V_7 -> V_10 & V_11 ) )
return - V_12 ;
V_2 -> V_7 -> V_10 = V_10 ;
V_2 -> V_7 -> V_28 = V_28 ;
V_2 -> V_7 -> V_31 = V_29 ;
V_2 -> V_7 -> V_32 = V_30 ;
F_3 () ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_33 , unsigned int V_29 , unsigned int V_30 )
{
if ( ( V_2 -> V_7 -> V_8 & V_9 ) || ( V_2 -> V_7 -> V_10 & V_11 ) )
return - V_12 ;
V_2 -> V_7 -> V_8 = V_8 ;
V_2 -> V_7 -> V_33 = V_33 ;
V_2 -> V_7 -> V_34 = V_29 ;
V_2 -> V_7 -> V_35 = V_30 ;
F_3 () ;
return 0 ;
}
static void F_6 ( struct V_36 * V_37 , void * V_38 , int V_39 ,
T_2 V_40 , unsigned int V_41 ,
unsigned int V_42 , unsigned int V_43 , T_2 V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_39 ; ++ V_45 ) {
V_37 [ V_45 ] . V_46 = & ( V_37 [ V_45 + 1 ] ) ;
V_37 [ V_45 ] . V_47 = ( unsigned long ) V_38 + V_45 * V_40 ;
V_37 [ V_45 ] . V_41 = V_41 ;
V_37 [ V_45 ] . V_42 = V_42 ;
V_37 [ V_45 ] . V_48 = V_44 ;
V_37 [ V_45 ] . V_49 = V_43 ;
V_37 [ V_45 ] . V_50 = V_44 ;
}
V_37 [ V_39 - 1 ] . V_46 = V_37 ;
F_2 ( L_2
L_3 ,
V_37 , V_37 [ 0 ] . V_46 ,
V_37 + 1 , V_37 [ 1 ] . V_46 ,
V_37 [ 0 ] . V_42 , V_37 [ 0 ] . V_49 ,
V_37 [ 0 ] . V_47 , V_37 [ 0 ] . V_41 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_51 ) ;
F_8 ( V_2 -> V_52 ) ;
V_2 -> V_7 -> V_10 |= V_11 ;
V_2 -> V_7 -> V_8 |= V_9 ;
F_3 () ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
V_2 -> V_7 -> V_8 &= ~ V_9 ;
V_2 -> V_7 -> V_10 &= ~ V_11 ;
F_3 () ;
F_10 ( V_2 -> V_51 ) ;
F_10 ( V_2 -> V_52 ) ;
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
struct V_36 * V_37 , V_53 ;
unsigned long V_54 ;
F_12 ( V_2 -> V_55 == NULL ) ;
F_12 ( V_2 -> V_56 == V_2 -> V_55 ) ;
V_2 -> V_55 -> V_46 = V_2 -> V_55 + 1 ;
F_13 ( V_54 ) ;
V_37 = F_14 ( V_2 -> V_51 ) ;
V_53 = * V_37 ;
V_37 -> V_42 = V_2 -> V_57 / 2 ;
V_37 -> V_49 = 0 ;
V_37 -> V_46 = V_2 -> V_55 ;
F_15 ( V_54 ) ;
while ( ( F_16 ( V_2 -> V_51 ) -
sizeof( struct V_36 ) ) != V_2 -> V_55 )
continue;
V_2 -> V_56 = V_2 -> V_55 ;
* V_37 = V_53 ;
return 0 ;
}
static inline int F_17 ( struct V_1 * V_2 , int V_58 )
{
if ( V_58 ) {
V_2 -> V_55 -> V_46 = V_2 -> V_55 ;
V_2 -> V_56 = V_2 -> V_55 ;
} else
V_2 -> V_56 = V_2 -> V_59 ;
F_18 ( V_2 -> V_51 , V_2 -> V_56 ) ;
F_19 ( V_2 -> V_51 , 0 ) ;
F_20 ( V_2 -> V_51 , 0 ) ;
F_21 ( V_2 -> V_51 , ( V_60 | V_61 | \
V_62 | V_63 ) ) ;
F_22 ( V_2 -> V_51 , V_2 -> V_56 -> V_47 ) ;
F_3 () ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , int V_58 )
{
if ( V_58 ) {
V_2 -> V_64 -> V_46 = V_2 -> V_64 ;
V_2 -> V_65 = V_2 -> V_64 ;
} else
V_2 -> V_65 = V_2 -> V_66 ;
F_18 ( V_2 -> V_52 , V_2 -> V_65 ) ;
F_19 ( V_2 -> V_52 , 0 ) ;
F_20 ( V_2 -> V_52 , 0 ) ;
F_21 ( V_2 -> V_52 ,
( V_60 | V_61 | V_62 ) ) ;
F_22 ( V_2 -> V_52 , V_2 -> V_65 -> V_47 ) ;
F_3 () ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_2 ( L_4 , V_6 ) ;
if ( V_2 -> V_67 )
return - V_12 ;
if ( V_2 -> V_68 ) {
F_12 ( V_2 -> V_59 == NULL ) ;
F_12 ( V_2 -> V_56 != V_2 -> V_55 ) ;
F_13 ( V_54 ) ;
while ( ( F_16 ( V_2 -> V_51 ) -
sizeof( struct V_36 ) ) != V_2 -> V_55 )
continue;
V_2 -> V_55 -> V_46 = V_2 -> V_59 ;
F_15 ( V_54 ) ;
V_2 -> V_56 = V_2 -> V_59 ;
} else {
F_23 ( V_2 , 1 ) ;
F_17 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
}
V_2 -> V_67 = 1 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
F_2 ( L_4 , V_6 ) ;
if ( ! V_2 -> V_67 )
return 0 ;
if ( V_2 -> V_68 ) {
F_11 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_65 = NULL ;
}
V_2 -> V_67 = 0 ;
return 0 ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
struct V_36 * V_37 , V_53 ;
unsigned long V_54 ;
F_12 ( V_2 -> V_64 == NULL ) ;
F_12 ( V_2 -> V_65 == V_2 -> V_64 ) ;
V_2 -> V_64 -> V_46 = V_2 -> V_64 + 1 ;
F_13 ( V_54 ) ;
V_37 = F_14 ( V_2 -> V_52 ) ;
V_53 = * V_37 ;
V_37 -> V_42 = V_2 -> V_57 / 2 ;
V_37 -> V_49 = 0 ;
V_37 -> V_46 = V_2 -> V_64 ;
F_15 ( V_54 ) ;
while ( ( F_16 ( V_2 -> V_52 ) - \
sizeof( struct V_36 ) ) != V_2 -> V_64 )
continue;
V_2 -> V_65 = V_2 -> V_64 ;
* V_37 = V_53 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
F_2 ( L_5 , V_6 ,
V_2 -> V_68 , V_2 -> V_67 ) ;
if ( V_2 -> V_68 )
return - V_12 ;
if ( V_2 -> V_67 ) {
F_12 ( V_2 -> V_66 == NULL ) ;
F_12 ( V_2 -> V_65 != V_2 -> V_64 ) ;
F_13 ( V_54 ) ;
while ( ( F_16 ( V_2 -> V_52 ) -
sizeof( struct V_36 ) ) != V_2 -> V_64 )
continue;
V_2 -> V_64 -> V_46 = V_2 -> V_66 ;
F_15 ( V_54 ) ;
V_2 -> V_65 = V_2 -> V_66 ;
} else {
F_23 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
}
V_2 -> V_68 = 1 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_68 )
return 0 ;
if ( V_2 -> V_67 ) {
F_26 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
V_2 -> V_56 = NULL ;
V_2 -> V_65 = NULL ;
}
V_2 -> V_68 = 0 ;
return 0 ;
}
static inline int F_29 ( T_2 V_44 )
{
switch ( V_44 ) {
case 1 :
return V_69 ;
case 2 :
return V_70 ;
case 4 :
default:
return V_62 ;
}
}
int F_30 ( struct V_1 * V_2 , void * V_38 ,
int V_39 , T_2 V_40 )
{
unsigned int V_42 ;
unsigned int V_49 ;
unsigned int V_41 ;
T_3 V_71 ;
F_2 ( L_6 , V_6 , \
V_38 , V_39 , V_40 ) ;
V_42 = V_40 / V_2 -> V_44 ;
V_49 = 0 ;
if ( V_42 >= 0x10000 ) {
int V_45 , V_72 = V_42 ;
for ( V_45 = 16 ; V_45 > 0 ; V_45 -- ) {
V_42 = 1 << V_45 ;
if ( ( V_72 & ( V_42 - 1 ) ) == 0 ) {
V_49 = V_72 >> V_45 ;
if ( V_49 < 0x10000 )
break;
}
}
if ( V_45 == 0 )
return - V_13 ;
}
F_2 ( L_7 , V_6 ,
V_42 , V_49 ) ;
if ( V_2 -> V_59 )
F_31 ( NULL , V_2 -> V_73 ,
V_2 -> V_59 , 0 ) ;
V_2 -> V_59 = F_32 ( NULL , \
V_39 * sizeof( struct V_36 ) , & V_71 , 0 ) ;
V_2 -> V_73 = V_39 * sizeof( struct V_36 ) ;
if ( ! V_2 -> V_59 ) {
F_33 ( L_8 ) ;
return - V_74 ;
}
V_2 -> V_75 = V_38 ;
V_2 -> V_76 = V_40 ;
V_2 -> V_77 = V_39 ;
V_41 = 0x7000 | V_78 | F_29 ( V_2 -> V_44 ) | V_63 | \
( V_79 << 8 ) ;
if ( V_49 != 0 )
V_41 |= V_80 ;
F_6 ( V_2 -> V_59 , V_38 , V_39 , V_40 ,
V_41 | V_81 , V_42 , V_49 , V_2 -> V_44 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , void * V_38 , \
int V_39 , T_2 V_40 )
{
unsigned int V_42 ;
unsigned int V_49 ;
unsigned int V_41 ;
T_3 V_71 ;
F_2 ( L_9 ,
V_6 , V_38 , V_39 , V_40 ) ;
V_42 = V_40 / V_2 -> V_44 ;
V_49 = 0 ;
if ( V_42 >= 0x10000 ) {
int V_45 , V_72 = V_42 ;
for ( V_45 = 16 ; V_45 > 0 ; V_45 -- ) {
V_42 = 1 << V_45 ;
if ( ( V_72 & ( V_42 - 1 ) ) == 0 ) {
V_49 = V_72 >> V_45 ;
if ( V_49 < 0x10000 )
break;
}
}
if ( V_45 == 0 )
return - V_13 ;
}
F_2 ( L_10 , V_6 ,
V_42 , V_49 ) ;
if ( V_2 -> V_66 ) {
F_31 ( NULL , V_2 -> V_82 , \
V_2 -> V_66 , 0 ) ;
}
V_2 -> V_66 = F_32 ( NULL , \
V_39 * sizeof( struct V_36 ) , & V_71 , 0 ) ;
V_2 -> V_82 = V_39 * sizeof( struct V_36 ) ;
if ( ! V_2 -> V_66 ) {
F_33 ( L_11 ) ;
return - V_74 ;
}
V_2 -> V_83 = V_38 ;
V_2 -> V_84 = V_40 ;
V_2 -> V_85 = V_39 ;
V_41 = 0x7000 | V_78 | F_29 ( V_2 -> V_44 ) | \
( V_79 << 8 ) ;
if ( V_49 != 0 )
V_41 |= V_80 ;
F_6 ( V_2 -> V_66 , V_38 , V_39 , V_40 ,
V_41 | V_81 , V_42 , V_49 , V_2 -> V_44 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
unsigned V_86 ;
F_2 ( L_12 , V_6 ) ;
if ( V_87 )
V_37 = F_36 ( 2 * sizeof( * V_37 ) ) ;
else {
T_3 V_71 ;
V_37 = F_32 ( NULL , 2 * sizeof( * V_37 ) , & V_71 , 0 ) ;
memset ( V_37 , 0 , 2 * sizeof( * V_37 ) ) ;
}
if ( V_37 == NULL ) {
F_33 ( L_13 ) ;
return - V_74 ;
}
V_2 -> V_55 = V_37 ;
V_37 -> V_47 = ( unsigned long ) V_2 -> V_88 ;
V_86 = V_60 | V_61 | F_29 ( V_2 -> V_44 )
| V_63 | V_81 ;
V_37 -> V_41 = V_86 ;
V_37 -> V_42 = V_2 -> V_57 / V_2 -> V_44 ;
V_37 -> V_48 = V_2 -> V_44 ;
V_37 -> V_49 = 0 ;
V_37 -> V_50 = 0 ;
memcpy ( V_37 + 1 , V_37 , sizeof( * V_37 ) ) ;
V_37 -> V_46 = V_37 + 1 ;
V_37 [ 1 ] . V_46 = V_37 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
unsigned int V_86 ;
F_2 ( L_12 , V_6 ) ;
if ( V_87 )
V_37 = F_36 ( 2 * sizeof( * V_37 ) ) ;
else {
T_3 V_71 ;
V_37 = F_32 ( NULL , 2 * sizeof( * V_37 ) , & V_71 , 0 ) ;
memset ( V_37 , 0 , 2 * sizeof( * V_37 ) ) ;
}
if ( ! V_37 ) {
F_33 ( L_14 ) ;
return - V_74 ;
}
V_2 -> V_64 = V_37 ;
V_37 -> V_47 = ( unsigned long ) V_2 -> V_88 + \
V_2 -> V_57 ;
V_86 = V_60 | V_61 |
F_29 ( V_2 -> V_44 ) | V_81 ;
V_37 -> V_41 = V_86 ;
V_37 -> V_42 = V_2 -> V_57 / V_2 -> V_44 ;
V_37 -> V_48 = V_2 -> V_44 ;
V_37 -> V_49 = 0 ;
V_37 -> V_50 = 0 ;
memcpy ( V_37 + 1 , V_37 , sizeof( * V_37 ) ) ;
V_37 -> V_46 = V_37 + 1 ;
V_37 [ 1 ] . V_46 = V_37 ;
return 0 ;
}
unsigned long F_38 ( struct V_1 * V_2 )
{
unsigned long V_89 = F_39 ( V_2 -> V_51 ) ;
return ( unsigned char * ) V_89 - V_2 -> V_75 ;
}
unsigned long F_40 ( struct V_1 * V_2 )
{
unsigned long V_89 = F_39 ( V_2 -> V_52 ) ;
return ( unsigned char * ) V_89 - V_2 -> V_83 ;
}
void F_41 ( struct V_1 * V_2 , int * V_90 , int V_91 )
{
++ ( * V_90 ) ;
if ( V_91 == 1 && * V_90 == V_2 -> V_85 )
* V_90 = 0 ;
if ( V_91 == 0 && * V_90 == V_2 -> V_77 )
* V_90 = 0 ;
}
void F_42 ( struct V_1 * V_2 , int * V_90 , int V_91 )
{
-- ( * V_90 ) ;
if ( V_91 == 1 && * V_90 == 0 )
* V_90 = V_2 -> V_85 ;
if ( V_91 == 0 && * V_90 == 0 )
* V_90 = V_2 -> V_77 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned int * V_92 ,
unsigned int * V_93 ,
unsigned int * V_94 )
{
int V_95 = 0 ;
if ( V_92 ) {
F_3 () ;
V_95 = V_2 -> V_7 -> V_96 ;
if ( V_95 & ( V_97 | V_98 | V_99 | V_100 ) )
V_2 -> V_7 -> V_96 = ( V_95 & ( V_97 | V_98 | V_99 | V_100 ) ) ;
F_3 () ;
* V_92 = V_95 ;
}
if ( V_93 ) {
F_3 () ;
V_95 = F_44 ( V_2 -> V_51 ) ;
if ( V_95 & ( V_101 | V_102 ) )
F_45 ( V_2 -> V_51 ) ;
F_3 () ;
* V_93 = V_95 ;
}
if ( V_94 ) {
F_3 () ;
V_95 = F_44 ( V_2 -> V_52 ) ;
if ( V_95 & ( V_101 | V_102 ) )
F_45 ( V_2 -> V_52 ) ;
F_3 () ;
* V_94 = V_95 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , char * V_38 , T_2 V_103 )
{
int V_104 ;
V_104 = snprintf ( V_38 , V_103 ,
L_15
L_16 ,
V_2 -> V_7 -> V_96 ,
V_2 -> V_51 ,
F_44 ( V_2 -> V_51 ) ,
V_2 -> V_52 ,
F_44 ( V_2 -> V_52 ) ) ;
V_38 += V_104 ;
V_103 -= V_104 ;
V_104 += snprintf ( V_38 , V_103 ,
L_17
L_18
L_19 ,
V_2 -> V_56 , V_2 -> V_65 ,
V_2 -> V_59 , V_2 -> V_66 ,
V_2 -> V_55 , V_2 -> V_64 ) ;
return V_104 ;
}
static T_4 F_47 ( int V_105 , void * V_106 )
{
unsigned int V_93 ;
struct V_1 * V_2 = V_106 ;
F_2 ( L_4 , V_6 ) ;
F_43 ( V_2 , NULL , & V_93 , NULL ) ;
if ( ! ( V_93 & V_101 ) )
F_33 ( L_20 ) ;
if ( V_2 -> V_107 ) {
V_2 -> V_107 ( V_2 -> V_108 ) ;
return V_109 ;
}
return V_110 ;
}
static T_4 F_48 ( int V_105 , void * V_106 )
{
unsigned int V_94 ;
struct V_1 * V_2 = V_106 ;
F_2 ( L_4 , V_6 ) ;
F_43 ( V_2 , NULL , NULL , & V_94 ) ;
if ( ! ( V_94 & V_101 ) ) {
F_33 ( L_21 ) ;
return V_109 ;
}
if ( V_2 -> V_111 ) {
V_2 -> V_111 ( V_2 -> V_112 ) ;
return V_109 ;
}
return V_110 ;
}
static T_4 F_49 ( int V_105 , void * V_106 )
{
unsigned int V_95 = 0 ;
struct V_1 * V_2 = V_106 ;
F_2 ( L_22 , V_6 ) ;
if ( F_43 ( V_2 , & V_95 , NULL , NULL ) ) {
F_33 ( L_23 ) ;
return V_110 ;
}
if ( V_95 & ( V_97 | V_98 | V_99 | V_100 ) ) {
F_50 ( L_24 ,
V_95 & V_97 ? L_25 : L_26 ,
V_95 & V_98 ? L_27 : L_26 ,
V_95 & V_99 ? L_28 : L_26 ,
V_95 & V_100 ? L_29 : L_26 ) ;
if ( V_95 & V_97 || V_95 & V_98 ) {
F_10 ( V_2 -> V_52 ) ;
if ( V_2 -> V_68 )
F_23 ( V_2 , 0 ) ;
else
F_23 ( V_2 , 1 ) ;
F_8 ( V_2 -> V_52 ) ;
} else {
F_10 ( V_2 -> V_51 ) ;
if ( V_2 -> V_67 )
F_17 ( V_2 , 0 ) ;
else
F_17 ( V_2 , 1 ) ;
F_8 ( V_2 -> V_51 ) ;
}
}
V_95 = V_2 -> V_7 -> V_96 ;
if ( V_95 & ( V_97 | V_98 | V_99 | V_100 ) )
V_2 -> V_7 -> V_96 = ( V_95 & ( V_97 | V_98 | V_99 | V_100 ) ) ;
F_3 () ;
if ( V_2 -> V_113 )
V_2 -> V_113 ( V_2 -> V_114 ) ;
return V_109 ;
}
int F_51 ( struct V_1 * V_2 ,
void (* V_107)( void * ) , void * V_108 )
{
F_12 ( V_107 == NULL ) ;
V_2 -> V_107 = V_107 ;
V_2 -> V_108 = V_108 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 ,
void (* V_111)( void * ) , void * V_112 )
{
F_12 ( V_111 == NULL ) ;
V_2 -> V_111 = V_111 ;
V_2 -> V_112 = V_112 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
void (* V_113)( void * ) , void * V_114 )
{
F_12 ( V_113 == NULL ) ;
V_2 -> V_113 = V_113 ;
V_2 -> V_114 = V_114 ;
return 0 ;
}
static int F_54 ( struct V_115 * V_116 , struct V_117 * V_118 )
{
struct V_119 * V_120 = & V_116 -> V_120 ;
struct V_121 * V_122 = V_120 -> V_123 ;
struct V_124 * V_125 ;
V_118 -> V_126 = V_116 -> V_127 ;
if ( ! V_122 ) {
F_55 ( V_120 , L_30 ) ;
return - V_128 ;
}
V_118 -> V_129 = V_122 -> V_129 ;
V_125 = F_56 ( V_116 , V_130 , 0 ) ;
if ( ! V_125 ) {
F_55 ( V_120 , L_31 ) ;
return - V_128 ;
}
V_118 -> V_7 = (struct V_131 * ) V_125 -> V_132 ;
V_125 = F_56 ( V_116 , V_133 , 0 ) ;
if ( ! V_125 ) {
F_55 ( V_120 , L_32 ) ;
return - V_128 ;
}
V_118 -> V_51 = V_125 -> V_132 ;
V_125 = F_56 ( V_116 , V_133 , 1 ) ;
if ( ! V_125 ) {
F_55 ( V_120 , L_33 ) ;
return - V_128 ;
}
V_118 -> V_52 = V_125 -> V_132 ;
V_125 = F_56 ( V_116 , V_134 , 0 ) ;
if ( ! V_125 ) {
F_55 ( V_120 , L_34 ) ;
return - V_128 ;
}
V_118 -> V_135 = V_125 -> V_132 ;
return 0 ;
}
struct V_1 * F_57 ( struct V_115 * V_116 ,
unsigned int V_44 , unsigned int V_57 , T_2 V_136 )
{
struct V_119 * V_120 = & V_116 -> V_120 ;
struct V_117 V_118 ;
struct V_1 * V_2 ;
int V_104 ;
F_58 ( V_120 , L_4 , V_6 ) ;
V_118 . V_44 = V_44 ;
V_118 . V_57 = V_57 ;
F_12 ( V_118 . V_44 == 0 || V_118 . V_57 == 0 ) ;
V_104 = F_54 ( V_116 , & V_118 ) ;
if ( V_104 )
return NULL ;
if ( F_59 ( V_118 . V_129 , L_35 ) ) {
F_55 ( V_120 , L_36 ) ;
return NULL ;
}
V_2 = F_60 ( sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 ) {
F_55 ( V_120 , L_37 ) ;
goto V_138;
}
V_2 -> V_126 = V_118 . V_126 ;
V_2 -> V_51 = V_118 . V_51 ;
V_2 -> V_52 = V_118 . V_52 ;
V_2 -> V_135 = V_118 . V_135 ;
V_2 -> V_7 = V_118 . V_7 ;
V_2 -> V_129 = V_118 . V_129 ;
if ( F_61 ( V_2 -> V_51 , L_38 ) == - V_12 ) {
F_55 ( V_120 , L_39 , V_2 -> V_51 ) ;
goto V_139;
}
if ( F_62 ( V_2 -> V_51 , F_47 , V_2 ) != 0 ) {
F_55 ( V_120 , L_40 , V_2 -> V_51 ) ;
goto V_140;
}
if ( F_61 ( V_2 -> V_52 , L_41 ) == - V_12 ) {
F_55 ( V_120 , L_42 , V_2 -> V_52 ) ;
goto V_140;
}
if ( F_62 ( V_2 -> V_52 , F_48 , V_2 ) != 0 ) {
F_55 ( V_120 , L_43 , V_2 -> V_52 ) ;
goto V_141;
}
if ( F_63 ( V_2 -> V_135 , F_49 , V_142 , L_44 ,
V_2 ) < 0 ) {
F_55 ( V_120 , L_45 , V_2 -> V_135 ) ;
goto V_141;
}
F_64 ( V_120 , L_46 ,
V_2 -> V_51 , V_2 -> V_52 ,
V_2 -> V_135 , V_2 -> V_7 ) ;
V_2 -> V_44 = V_118 . V_44 ;
V_2 -> V_57 = V_118 . V_57 ;
V_2 -> V_143 = F_60 ( V_136 , V_137 ) ;
if ( ! V_2 -> V_143 ) {
F_55 ( V_120 , L_47 , V_136 ) ;
goto V_144;
}
if ( V_87 )
V_2 -> V_88 = F_36 ( V_118 . V_57 * 2 ) ;
else
V_2 -> V_88 = F_60 ( V_118 . V_57 * 2 , V_137 ) ;
if ( V_2 -> V_88 == NULL ) {
F_55 ( V_120 , L_48 ) ;
goto V_145;
}
V_104 = F_35 ( V_2 ) ;
if ( V_104 ) {
F_55 ( V_120 , L_49 ) ;
goto V_146;
}
V_104 = F_37 ( V_2 ) ;
if ( V_104 ) {
F_55 ( V_120 , L_50 ) ;
goto V_147;
}
F_65 ( V_116 , V_2 ) ;
return V_2 ;
V_147:
if ( V_87 )
F_66 ( V_2 -> V_55 ) ;
else
F_31 ( NULL , 2 * sizeof( struct V_36 ) ,
V_2 -> V_55 , 0 ) ;
V_146:
if ( V_87 )
F_66 ( V_2 -> V_88 ) ;
else
F_67 ( V_2 -> V_88 ) ;
V_145:
F_67 ( V_2 -> V_143 ) ;
V_144:
F_68 ( V_2 -> V_135 , V_2 ) ;
V_141:
F_69 ( V_2 -> V_52 ) ;
V_140:
F_69 ( V_2 -> V_51 ) ;
V_139:
F_67 ( V_2 ) ;
V_138:
F_70 ( V_118 . V_129 ) ;
return NULL ;
}
void F_71 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_9 ( V_2 ) ;
if ( V_2 -> V_59 )
F_31 ( NULL , V_2 -> V_73 ,
V_2 -> V_59 , 0 ) ;
if ( V_2 -> V_66 )
F_31 ( NULL , V_2 -> V_82 ,
V_2 -> V_66 , 0 ) ;
#if V_87 != 0
F_66 ( V_2 -> V_55 ) ;
F_66 ( V_2 -> V_64 ) ;
F_66 ( V_2 -> V_88 ) ;
#else
F_31 ( NULL , 2 * sizeof( struct V_36 ) ,
V_2 -> V_55 , 0 ) ;
F_31 ( NULL , 2 * sizeof( struct V_36 ) ,
V_2 -> V_64 , 0 ) ;
F_67 ( V_2 -> V_88 ) ;
#endif
F_69 ( V_2 -> V_51 ) ;
F_69 ( V_2 -> V_52 ) ;
F_68 ( V_2 -> V_135 , V_2 ) ;
F_67 ( V_2 -> V_143 ) ;
F_70 ( V_2 -> V_129 ) ;
F_67 ( V_2 ) ;
}
int F_72 ( struct V_1 * V_2 , T_5 * V_148 , \
T_5 * V_149 , int V_103 )
{
unsigned short V_150 ;
unsigned short V_95 ;
unsigned long V_54 ;
unsigned long V_151 = 0 ;
F_2 ( L_51 , \
V_6 , V_148 , V_149 , V_103 ) ;
F_2 ( L_52
L_53 ,
V_2 -> V_7 -> V_8 , V_2 -> V_7 -> V_33 ,
V_2 -> V_7 -> V_34 , V_2 -> V_7 -> V_35 ,
V_2 -> V_7 -> V_14 , V_2 -> V_7 -> V_15 ) ;
F_73 ( ( unsigned ) V_148 , ( unsigned ) ( V_148 + V_103 ) ) ;
V_150 = ( V_152 | V_70 | V_78 ) ;
F_74 ( V_2 -> V_52 , ( unsigned long ) V_148 ) ;
F_19 ( V_2 -> V_52 , V_103 / 2 ) ;
F_20 ( V_2 -> V_52 , 2 ) ;
F_21 ( V_2 -> V_52 , V_150 ) ;
F_8 ( V_2 -> V_52 ) ;
if ( V_149 != NULL ) {
F_75 ( ( unsigned ) V_149 , \
( unsigned ) ( V_149 + V_103 ) ) ;
V_150 = ( V_152 | V_70 | V_63 | V_78 ) ;
F_74 ( V_2 -> V_51 , ( unsigned long ) V_149 ) ;
F_19 ( V_2 -> V_51 , V_103 / 2 ) ;
F_20 ( V_2 -> V_51 , 2 ) ;
F_21 ( V_2 -> V_51 , V_150 ) ;
F_8 ( V_2 -> V_51 ) ;
}
F_13 ( V_54 ) ;
V_2 -> V_7 -> V_8 |= V_9 ;
V_2 -> V_7 -> V_10 |= V_11 ;
F_3 () ;
V_95 = F_44 ( V_2 -> V_52 ) ;
while ( V_95 & V_153 ) {
F_76 ( 1 ) ;
V_95 = F_44 ( V_2 -> V_52 ) ;
F_2 ( L_54 , V_95 ) ;
if ( V_151 ++ > 100 )
goto V_154;
}
V_95 = V_2 -> V_7 -> V_96 ;
V_151 = 0 ;
while ( ! ( V_95 & V_155 ) ) {
F_2 ( L_55 , V_95 ) ;
F_76 ( 1 ) ;
V_95 = * ( unsigned short * ) & V_2 -> V_7 -> V_96 ;
if ( V_151 ++ > 1000 )
goto V_154;
}
F_76 ( 20 ) ;
F_2 ( L_55 , V_95 ) ;
V_154:
V_2 -> V_7 -> V_8 &= ~ V_9 ;
V_2 -> V_7 -> V_10 &= ~ V_11 ;
F_3 () ;
F_10 ( V_2 -> V_52 ) ;
F_45 ( V_2 -> V_52 ) ;
if ( V_149 != NULL ) {
F_10 ( V_2 -> V_51 ) ;
F_45 ( V_2 -> V_51 ) ;
}
F_3 () ;
F_15 ( V_54 ) ;
return 0 ;
}
