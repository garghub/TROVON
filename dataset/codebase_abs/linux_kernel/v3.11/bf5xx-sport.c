int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_1 V_5 , int V_6 )
{
F_2 ( L_1 ,
V_7 , V_3 , V_4 , V_5 , V_6 ) ;
if ( ( V_2 -> V_8 -> V_9 & V_10 ) || ( V_2 -> V_8 -> V_11 & V_12 ) )
return - V_13 ;
if ( V_3 & 0x7 )
return - V_14 ;
if ( V_3 > 32 )
return - V_14 ;
if ( V_3 ) {
V_2 -> V_8 -> V_15 = ( ( V_3 >> 3 ) - 1 ) << 12 ;
V_2 -> V_8 -> V_16 = V_17 | V_18 | \
( V_6 ? ( V_19 | V_20 ) : 0 ) ;
V_2 -> V_8 -> V_21 = V_4 ;
V_2 -> V_8 -> V_22 = V_5 ;
V_2 -> V_8 -> V_23 = 0 ;
V_2 -> V_8 -> V_24 = 0 ;
V_2 -> V_8 -> V_25 = 0 ;
V_2 -> V_8 -> V_26 = 0 ;
V_2 -> V_8 -> V_27 = 0 ;
V_2 -> V_8 -> V_28 = 0 ;
} else {
V_2 -> V_8 -> V_15 = 0 ;
V_2 -> V_8 -> V_16 = 0 ;
V_2 -> V_8 -> V_21 = 0 ;
V_2 -> V_8 -> V_22 = 0 ;
}
V_2 -> V_8 -> V_23 = 0 ; V_2 -> V_8 -> V_25 = 0 ; V_2 -> V_8 -> V_27 = 0 ;
V_2 -> V_8 -> V_24 = 0 ; V_2 -> V_8 -> V_26 = 0 ; V_2 -> V_8 -> V_28 = 0 ;
F_3 () ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int V_29 , unsigned int V_30 , unsigned int V_31 )
{
if ( ( V_2 -> V_8 -> V_9 & V_10 ) || ( V_2 -> V_8 -> V_11 & V_12 ) )
return - V_13 ;
V_2 -> V_8 -> V_11 = V_11 ;
V_2 -> V_8 -> V_29 = V_29 ;
V_2 -> V_8 -> V_32 = V_30 ;
V_2 -> V_8 -> V_33 = V_31 ;
F_3 () ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned int V_34 , unsigned int V_30 , unsigned int V_31 )
{
if ( ( V_2 -> V_8 -> V_9 & V_10 ) || ( V_2 -> V_8 -> V_11 & V_12 ) )
return - V_13 ;
V_2 -> V_8 -> V_9 = V_9 ;
V_2 -> V_8 -> V_34 = V_34 ;
V_2 -> V_8 -> V_35 = V_30 ;
V_2 -> V_8 -> V_36 = V_31 ;
F_3 () ;
return 0 ;
}
static void F_6 ( struct V_37 * V_38 , void * V_39 , int V_40 ,
T_2 V_41 , unsigned int V_42 ,
unsigned int V_43 , unsigned int V_44 , T_2 V_45 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_40 ; ++ V_46 ) {
V_38 [ V_46 ] . V_47 = & ( V_38 [ V_46 + 1 ] ) ;
V_38 [ V_46 ] . V_48 = ( unsigned long ) V_39 + V_46 * V_41 ;
V_38 [ V_46 ] . V_42 = V_42 ;
V_38 [ V_46 ] . V_43 = V_43 ;
V_38 [ V_46 ] . V_49 = V_45 ;
V_38 [ V_46 ] . V_50 = V_44 ;
V_38 [ V_46 ] . V_51 = V_45 ;
}
V_38 [ V_40 - 1 ] . V_47 = V_38 ;
F_2 ( L_2
L_3 ,
V_38 , V_38 [ 0 ] . V_47 ,
V_38 + 1 , V_38 [ 1 ] . V_47 ,
V_38 [ 0 ] . V_43 , V_38 [ 0 ] . V_50 ,
V_38 [ 0 ] . V_48 , V_38 [ 0 ] . V_42 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_52 ) ;
F_8 ( V_2 -> V_53 ) ;
V_2 -> V_8 -> V_11 |= V_12 ;
V_2 -> V_8 -> V_9 |= V_10 ;
F_3 () ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
V_2 -> V_8 -> V_9 &= ~ V_10 ;
V_2 -> V_8 -> V_11 &= ~ V_12 ;
F_3 () ;
F_10 ( V_2 -> V_52 ) ;
F_10 ( V_2 -> V_53 ) ;
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
struct V_37 * V_38 , V_54 ;
unsigned long V_55 ;
F_12 ( V_2 -> V_56 == NULL ) ;
F_12 ( V_2 -> V_57 == V_2 -> V_56 ) ;
V_2 -> V_56 -> V_47 = V_2 -> V_56 + 1 ;
F_13 ( V_55 ) ;
V_38 = F_14 ( V_2 -> V_52 ) ;
V_54 = * V_38 ;
V_38 -> V_43 = V_2 -> V_58 / 2 ;
V_38 -> V_50 = 0 ;
V_38 -> V_47 = V_2 -> V_56 ;
F_15 ( V_55 ) ;
while ( ( F_16 ( V_2 -> V_52 ) -
sizeof( struct V_37 ) ) != V_2 -> V_56 )
continue;
V_2 -> V_57 = V_2 -> V_56 ;
* V_38 = V_54 ;
return 0 ;
}
static inline int F_17 ( struct V_1 * V_2 , int V_59 )
{
if ( V_59 ) {
V_2 -> V_56 -> V_47 = V_2 -> V_56 ;
V_2 -> V_57 = V_2 -> V_56 ;
} else
V_2 -> V_57 = V_2 -> V_60 ;
F_18 ( V_2 -> V_52 , V_2 -> V_57 ) ;
F_19 ( V_2 -> V_52 , 0 ) ;
F_20 ( V_2 -> V_52 , 0 ) ;
F_21 ( V_2 -> V_52 , ( V_61 | V_62 | \
V_63 | V_64 ) ) ;
F_22 ( V_2 -> V_52 , V_2 -> V_57 -> V_48 ) ;
F_3 () ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , int V_59 )
{
if ( V_59 ) {
V_2 -> V_65 -> V_47 = V_2 -> V_65 ;
V_2 -> V_66 = V_2 -> V_65 ;
} else
V_2 -> V_66 = V_2 -> V_67 ;
F_18 ( V_2 -> V_53 , V_2 -> V_66 ) ;
F_19 ( V_2 -> V_53 , 0 ) ;
F_20 ( V_2 -> V_53 , 0 ) ;
F_21 ( V_2 -> V_53 ,
( V_61 | V_62 | V_63 ) ) ;
F_22 ( V_2 -> V_53 , V_2 -> V_66 -> V_48 ) ;
F_3 () ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
unsigned long V_55 ;
F_2 ( L_4 , V_7 ) ;
if ( V_2 -> V_68 )
return - V_13 ;
if ( V_2 -> V_69 ) {
F_12 ( V_2 -> V_60 == NULL ) ;
F_12 ( V_2 -> V_57 != V_2 -> V_56 ) ;
F_13 ( V_55 ) ;
while ( ( F_16 ( V_2 -> V_52 ) -
sizeof( struct V_37 ) ) != V_2 -> V_56 )
continue;
V_2 -> V_56 -> V_47 = V_2 -> V_60 ;
F_15 ( V_55 ) ;
V_2 -> V_57 = V_2 -> V_60 ;
} else {
F_23 ( V_2 , 1 ) ;
F_17 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
}
V_2 -> V_68 = 1 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
F_2 ( L_4 , V_7 ) ;
if ( ! V_2 -> V_68 )
return 0 ;
if ( V_2 -> V_69 ) {
F_11 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_66 = NULL ;
}
V_2 -> V_68 = 0 ;
return 0 ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
struct V_37 * V_38 , V_54 ;
unsigned long V_55 ;
F_12 ( V_2 -> V_65 == NULL ) ;
F_12 ( V_2 -> V_66 == V_2 -> V_65 ) ;
V_2 -> V_65 -> V_47 = V_2 -> V_65 + 1 ;
F_13 ( V_55 ) ;
V_38 = F_14 ( V_2 -> V_53 ) ;
V_54 = * V_38 ;
V_38 -> V_43 = V_2 -> V_58 / 2 ;
V_38 -> V_50 = 0 ;
V_38 -> V_47 = V_2 -> V_65 ;
F_15 ( V_55 ) ;
while ( ( F_16 ( V_2 -> V_53 ) - \
sizeof( struct V_37 ) ) != V_2 -> V_65 )
continue;
V_2 -> V_66 = V_2 -> V_65 ;
* V_38 = V_54 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned long V_55 ;
F_2 ( L_5 , V_7 ,
V_2 -> V_69 , V_2 -> V_68 ) ;
if ( V_2 -> V_69 )
return - V_13 ;
if ( V_2 -> V_68 ) {
F_12 ( V_2 -> V_67 == NULL ) ;
F_12 ( V_2 -> V_66 != V_2 -> V_65 ) ;
F_13 ( V_55 ) ;
while ( ( F_16 ( V_2 -> V_53 ) -
sizeof( struct V_37 ) ) != V_2 -> V_65 )
continue;
V_2 -> V_65 -> V_47 = V_2 -> V_67 ;
F_15 ( V_55 ) ;
V_2 -> V_66 = V_2 -> V_67 ;
} else {
F_23 ( V_2 , 0 ) ;
F_17 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
}
V_2 -> V_69 = 1 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_69 )
return 0 ;
if ( V_2 -> V_68 ) {
F_26 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
V_2 -> V_57 = NULL ;
V_2 -> V_66 = NULL ;
}
V_2 -> V_69 = 0 ;
return 0 ;
}
static inline int F_29 ( T_2 V_45 )
{
switch ( V_45 ) {
case 1 :
return V_70 ;
case 2 :
return V_71 ;
case 4 :
default:
return V_63 ;
}
}
int F_30 ( struct V_1 * V_2 , void * V_39 ,
int V_40 , T_2 V_41 )
{
unsigned int V_43 ;
unsigned int V_50 ;
unsigned int V_42 ;
T_3 V_72 ;
F_2 ( L_6 , V_7 , \
V_39 , V_40 , V_41 ) ;
V_43 = V_41 / V_2 -> V_45 ;
V_50 = 0 ;
if ( V_43 >= 0x10000 ) {
int V_46 , V_73 = V_43 ;
for ( V_46 = 16 ; V_46 > 0 ; V_46 -- ) {
V_43 = 1 << V_46 ;
if ( ( V_73 & ( V_43 - 1 ) ) == 0 ) {
V_50 = V_73 >> V_46 ;
if ( V_50 < 0x10000 )
break;
}
}
if ( V_46 == 0 )
return - V_14 ;
}
F_2 ( L_7 , V_7 ,
V_43 , V_50 ) ;
if ( V_2 -> V_60 )
F_31 ( NULL , V_2 -> V_74 ,
V_2 -> V_60 , 0 ) ;
V_2 -> V_60 = F_32 ( NULL , \
V_40 * sizeof( struct V_37 ) , & V_72 , 0 ) ;
V_2 -> V_74 = V_40 * sizeof( struct V_37 ) ;
if ( ! V_2 -> V_60 ) {
F_33 ( L_8 ) ;
return - V_75 ;
}
V_2 -> V_76 = V_39 ;
V_2 -> V_77 = V_41 ;
V_2 -> V_78 = V_40 ;
V_42 = 0x7000 | V_79 | F_29 ( V_2 -> V_45 ) | V_64 | \
( V_80 << 8 ) ;
if ( V_50 != 0 )
V_42 |= V_81 ;
F_6 ( V_2 -> V_60 , V_39 , V_40 , V_41 ,
V_42 | V_82 , V_43 , V_50 , V_2 -> V_45 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , void * V_39 , \
int V_40 , T_2 V_41 )
{
unsigned int V_43 ;
unsigned int V_50 ;
unsigned int V_42 ;
T_3 V_72 ;
F_2 ( L_9 ,
V_7 , V_39 , V_40 , V_41 ) ;
V_43 = V_41 / V_2 -> V_45 ;
V_50 = 0 ;
if ( V_43 >= 0x10000 ) {
int V_46 , V_73 = V_43 ;
for ( V_46 = 16 ; V_46 > 0 ; V_46 -- ) {
V_43 = 1 << V_46 ;
if ( ( V_73 & ( V_43 - 1 ) ) == 0 ) {
V_50 = V_73 >> V_46 ;
if ( V_50 < 0x10000 )
break;
}
}
if ( V_46 == 0 )
return - V_14 ;
}
F_2 ( L_10 , V_7 ,
V_43 , V_50 ) ;
if ( V_2 -> V_67 ) {
F_31 ( NULL , V_2 -> V_83 , \
V_2 -> V_67 , 0 ) ;
}
V_2 -> V_67 = F_32 ( NULL , \
V_40 * sizeof( struct V_37 ) , & V_72 , 0 ) ;
V_2 -> V_83 = V_40 * sizeof( struct V_37 ) ;
if ( ! V_2 -> V_67 ) {
F_33 ( L_11 ) ;
return - V_75 ;
}
V_2 -> V_84 = V_39 ;
V_2 -> V_85 = V_41 ;
V_2 -> V_86 = V_40 ;
V_42 = 0x7000 | V_79 | F_29 ( V_2 -> V_45 ) | \
( V_80 << 8 ) ;
if ( V_50 != 0 )
V_42 |= V_81 ;
F_6 ( V_2 -> V_67 , V_39 , V_40 , V_41 ,
V_42 | V_82 , V_43 , V_50 , V_2 -> V_45 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
unsigned V_87 ;
F_2 ( L_12 , V_7 ) ;
if ( V_88 )
V_38 = F_36 ( 2 * sizeof( * V_38 ) ) ;
else {
T_3 V_72 ;
V_38 = F_32 ( NULL , 2 * sizeof( * V_38 ) , & V_72 , 0 ) ;
memset ( V_38 , 0 , 2 * sizeof( * V_38 ) ) ;
}
if ( V_38 == NULL ) {
F_33 ( L_13 ) ;
return - V_75 ;
}
V_2 -> V_56 = V_38 ;
V_38 -> V_48 = ( unsigned long ) V_2 -> V_89 ;
V_87 = V_61 | V_62 | F_29 ( V_2 -> V_45 )
| V_64 | V_82 ;
V_38 -> V_42 = V_87 ;
V_38 -> V_43 = V_2 -> V_58 / V_2 -> V_45 ;
V_38 -> V_49 = V_2 -> V_45 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
memcpy ( V_38 + 1 , V_38 , sizeof( * V_38 ) ) ;
V_38 -> V_47 = V_38 + 1 ;
V_38 [ 1 ] . V_47 = V_38 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
unsigned int V_87 ;
F_2 ( L_12 , V_7 ) ;
if ( V_88 )
V_38 = F_36 ( 2 * sizeof( * V_38 ) ) ;
else {
T_3 V_72 ;
V_38 = F_32 ( NULL , 2 * sizeof( * V_38 ) , & V_72 , 0 ) ;
memset ( V_38 , 0 , 2 * sizeof( * V_38 ) ) ;
}
if ( ! V_38 ) {
F_33 ( L_14 ) ;
return - V_75 ;
}
V_2 -> V_65 = V_38 ;
V_38 -> V_48 = ( unsigned long ) V_2 -> V_89 + \
V_2 -> V_58 ;
V_87 = V_61 | V_62 |
F_29 ( V_2 -> V_45 ) | V_82 ;
V_38 -> V_42 = V_87 ;
V_38 -> V_43 = V_2 -> V_58 / V_2 -> V_45 ;
V_38 -> V_49 = V_2 -> V_45 ;
V_38 -> V_50 = 0 ;
V_38 -> V_51 = 0 ;
memcpy ( V_38 + 1 , V_38 , sizeof( * V_38 ) ) ;
V_38 -> V_47 = V_38 + 1 ;
V_38 [ 1 ] . V_47 = V_38 ;
return 0 ;
}
unsigned long F_38 ( struct V_1 * V_2 )
{
unsigned long V_90 = F_39 ( V_2 -> V_52 ) ;
return ( unsigned char * ) V_90 - V_2 -> V_76 ;
}
unsigned long F_40 ( struct V_1 * V_2 )
{
unsigned long V_90 = F_39 ( V_2 -> V_53 ) ;
return ( unsigned char * ) V_90 - V_2 -> V_84 ;
}
void F_41 ( struct V_1 * V_2 , int * V_91 , int V_92 )
{
++ ( * V_91 ) ;
if ( V_92 == 1 && * V_91 == V_2 -> V_86 )
* V_91 = 0 ;
if ( V_92 == 0 && * V_91 == V_2 -> V_78 )
* V_91 = 0 ;
}
void F_42 ( struct V_1 * V_2 , int * V_91 , int V_92 )
{
-- ( * V_91 ) ;
if ( V_92 == 1 && * V_91 == 0 )
* V_91 = V_2 -> V_86 ;
if ( V_92 == 0 && * V_91 == 0 )
* V_91 = V_2 -> V_78 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned int * V_93 ,
unsigned int * V_94 ,
unsigned int * V_95 )
{
int V_96 = 0 ;
if ( V_93 ) {
F_3 () ;
V_96 = V_2 -> V_8 -> V_97 ;
if ( V_96 & ( V_98 | V_99 | V_100 | V_101 ) )
V_2 -> V_8 -> V_97 = ( V_96 & ( V_98 | V_99 | V_100 | V_101 ) ) ;
F_3 () ;
* V_93 = V_96 ;
}
if ( V_94 ) {
F_3 () ;
V_96 = F_44 ( V_2 -> V_52 ) ;
if ( V_96 & ( V_102 | V_103 ) )
F_45 ( V_2 -> V_52 ) ;
F_3 () ;
* V_94 = V_96 ;
}
if ( V_95 ) {
F_3 () ;
V_96 = F_44 ( V_2 -> V_53 ) ;
if ( V_96 & ( V_102 | V_103 ) )
F_45 ( V_2 -> V_53 ) ;
F_3 () ;
* V_95 = V_96 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , char * V_39 , T_2 V_104 )
{
int V_105 ;
V_105 = snprintf ( V_39 , V_104 ,
L_15
L_16 ,
V_2 -> V_8 -> V_97 ,
V_2 -> V_52 ,
F_44 ( V_2 -> V_52 ) ,
V_2 -> V_53 ,
F_44 ( V_2 -> V_53 ) ) ;
V_39 += V_105 ;
V_104 -= V_105 ;
V_105 += snprintf ( V_39 , V_104 ,
L_17
L_18
L_19 ,
V_2 -> V_57 , V_2 -> V_66 ,
V_2 -> V_60 , V_2 -> V_67 ,
V_2 -> V_56 , V_2 -> V_65 ) ;
return V_105 ;
}
static T_4 F_47 ( int V_106 , void * V_107 )
{
unsigned int V_94 ;
struct V_1 * V_2 = V_107 ;
F_2 ( L_4 , V_7 ) ;
F_43 ( V_2 , NULL , & V_94 , NULL ) ;
if ( ! ( V_94 & V_102 ) )
F_33 ( L_20 ) ;
if ( V_2 -> V_108 ) {
V_2 -> V_108 ( V_2 -> V_109 ) ;
return V_110 ;
}
return V_111 ;
}
static T_4 F_48 ( int V_106 , void * V_107 )
{
unsigned int V_95 ;
struct V_1 * V_2 = V_107 ;
F_2 ( L_4 , V_7 ) ;
F_43 ( V_2 , NULL , NULL , & V_95 ) ;
if ( ! ( V_95 & V_102 ) ) {
F_33 ( L_21 ) ;
return V_110 ;
}
if ( V_2 -> V_112 ) {
V_2 -> V_112 ( V_2 -> V_113 ) ;
return V_110 ;
}
return V_111 ;
}
static T_4 F_49 ( int V_106 , void * V_107 )
{
unsigned int V_96 = 0 ;
struct V_1 * V_2 = V_107 ;
F_2 ( L_22 , V_7 ) ;
if ( F_43 ( V_2 , & V_96 , NULL , NULL ) ) {
F_33 ( L_23 ) ;
return V_111 ;
}
if ( V_96 & ( V_98 | V_99 | V_100 | V_101 ) ) {
F_50 ( L_24 ,
V_96 & V_98 ? L_25 : L_26 ,
V_96 & V_99 ? L_27 : L_26 ,
V_96 & V_100 ? L_28 : L_26 ,
V_96 & V_101 ? L_29 : L_26 ) ;
if ( V_96 & V_98 || V_96 & V_99 ) {
F_10 ( V_2 -> V_53 ) ;
if ( V_2 -> V_69 )
F_23 ( V_2 , 0 ) ;
else
F_23 ( V_2 , 1 ) ;
F_8 ( V_2 -> V_53 ) ;
} else {
F_10 ( V_2 -> V_52 ) ;
if ( V_2 -> V_68 )
F_17 ( V_2 , 0 ) ;
else
F_17 ( V_2 , 1 ) ;
F_8 ( V_2 -> V_52 ) ;
}
}
V_96 = V_2 -> V_8 -> V_97 ;
if ( V_96 & ( V_98 | V_99 | V_100 | V_101 ) )
V_2 -> V_8 -> V_97 = ( V_96 & ( V_98 | V_99 | V_100 | V_101 ) ) ;
F_3 () ;
if ( V_2 -> V_114 )
V_2 -> V_114 ( V_2 -> V_115 ) ;
return V_110 ;
}
int F_51 ( struct V_1 * V_2 ,
void (* V_108)( void * ) , void * V_109 )
{
F_12 ( V_108 == NULL ) ;
V_2 -> V_108 = V_108 ;
V_2 -> V_109 = V_109 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 ,
void (* V_112)( void * ) , void * V_113 )
{
F_12 ( V_112 == NULL ) ;
V_2 -> V_112 = V_112 ;
V_2 -> V_113 = V_113 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 ,
void (* V_114)( void * ) , void * V_115 )
{
F_12 ( V_114 == NULL ) ;
V_2 -> V_114 = V_114 ;
V_2 -> V_115 = V_115 ;
return 0 ;
}
static int F_54 ( struct V_116 * V_117 , struct V_118 * V_119 )
{
struct V_120 * V_121 = & V_117 -> V_121 ;
struct V_122 * V_123 = V_121 -> V_124 ;
struct V_125 * V_126 ;
V_119 -> V_127 = V_117 -> V_128 ;
if ( ! V_123 ) {
F_55 ( V_121 , L_30 ) ;
return - V_129 ;
}
V_119 -> V_130 = V_123 -> V_130 ;
V_126 = F_56 ( V_117 , V_131 , 0 ) ;
if ( ! V_126 ) {
F_55 ( V_121 , L_31 ) ;
return - V_129 ;
}
V_119 -> V_8 = (struct V_132 * ) V_126 -> V_133 ;
V_126 = F_56 ( V_117 , V_134 , 0 ) ;
if ( ! V_126 ) {
F_55 ( V_121 , L_32 ) ;
return - V_129 ;
}
V_119 -> V_52 = V_126 -> V_133 ;
V_126 = F_56 ( V_117 , V_134 , 1 ) ;
if ( ! V_126 ) {
F_55 ( V_121 , L_33 ) ;
return - V_129 ;
}
V_119 -> V_53 = V_126 -> V_133 ;
V_126 = F_56 ( V_117 , V_135 , 0 ) ;
if ( ! V_126 ) {
F_55 ( V_121 , L_34 ) ;
return - V_129 ;
}
V_119 -> V_136 = V_126 -> V_133 ;
return 0 ;
}
struct V_1 * F_57 ( struct V_116 * V_117 ,
unsigned int V_45 , unsigned int V_58 , T_2 V_137 )
{
struct V_120 * V_121 = & V_117 -> V_121 ;
struct V_118 V_119 ;
struct V_1 * V_2 ;
int V_105 ;
F_58 ( V_121 , L_4 , V_7 ) ;
V_119 . V_45 = V_45 ;
V_119 . V_58 = V_58 ;
F_12 ( V_119 . V_45 == 0 || V_119 . V_58 == 0 ) ;
V_105 = F_54 ( V_117 , & V_119 ) ;
if ( V_105 )
return NULL ;
if ( F_59 ( V_119 . V_130 , L_35 ) ) {
F_55 ( V_121 , L_36 ) ;
return NULL ;
}
V_2 = F_60 ( sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 ) {
F_55 ( V_121 , L_37 ) ;
goto V_139;
}
V_2 -> V_127 = V_119 . V_127 ;
V_2 -> V_52 = V_119 . V_52 ;
V_2 -> V_53 = V_119 . V_53 ;
V_2 -> V_136 = V_119 . V_136 ;
V_2 -> V_8 = V_119 . V_8 ;
V_2 -> V_130 = V_119 . V_130 ;
if ( F_61 ( V_2 -> V_52 , L_38 ) == - V_13 ) {
F_55 ( V_121 , L_39 , V_2 -> V_52 ) ;
goto V_140;
}
if ( F_62 ( V_2 -> V_52 , F_47 , V_2 ) != 0 ) {
F_55 ( V_121 , L_40 , V_2 -> V_52 ) ;
goto V_141;
}
if ( F_61 ( V_2 -> V_53 , L_41 ) == - V_13 ) {
F_55 ( V_121 , L_42 , V_2 -> V_53 ) ;
goto V_141;
}
if ( F_62 ( V_2 -> V_53 , F_48 , V_2 ) != 0 ) {
F_55 ( V_121 , L_43 , V_2 -> V_53 ) ;
goto V_142;
}
if ( F_63 ( V_2 -> V_136 , F_49 , V_143 , L_44 ,
V_2 ) < 0 ) {
F_55 ( V_121 , L_45 , V_2 -> V_136 ) ;
goto V_142;
}
F_64 ( V_121 , L_46 ,
V_2 -> V_52 , V_2 -> V_53 ,
V_2 -> V_136 , V_2 -> V_8 ) ;
V_2 -> V_45 = V_119 . V_45 ;
V_2 -> V_58 = V_119 . V_58 ;
V_2 -> V_144 = F_60 ( V_137 , V_138 ) ;
if ( ! V_2 -> V_144 ) {
F_55 ( V_121 , L_47 , V_137 ) ;
goto V_145;
}
if ( V_88 )
V_2 -> V_89 = F_36 ( V_119 . V_58 * 2 ) ;
else
V_2 -> V_89 = F_60 ( V_119 . V_58 * 2 , V_138 ) ;
if ( V_2 -> V_89 == NULL ) {
F_55 ( V_121 , L_48 ) ;
goto V_146;
}
V_105 = F_35 ( V_2 ) ;
if ( V_105 ) {
F_55 ( V_121 , L_49 ) ;
goto V_147;
}
V_105 = F_37 ( V_2 ) ;
if ( V_105 ) {
F_55 ( V_121 , L_50 ) ;
goto V_148;
}
F_65 ( V_117 , V_2 ) ;
return V_2 ;
V_148:
if ( V_88 )
F_66 ( V_2 -> V_56 ) ;
else
F_31 ( NULL , 2 * sizeof( struct V_37 ) ,
V_2 -> V_56 , 0 ) ;
V_147:
if ( V_88 )
F_66 ( V_2 -> V_89 ) ;
else
F_67 ( V_2 -> V_89 ) ;
V_146:
F_67 ( V_2 -> V_144 ) ;
V_145:
F_68 ( V_2 -> V_136 , V_2 ) ;
V_142:
F_69 ( V_2 -> V_53 ) ;
V_141:
F_69 ( V_2 -> V_52 ) ;
V_140:
F_67 ( V_2 ) ;
V_139:
F_70 ( V_119 . V_130 ) ;
return NULL ;
}
void F_71 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_9 ( V_2 ) ;
if ( V_2 -> V_60 )
F_31 ( NULL , V_2 -> V_74 ,
V_2 -> V_60 , 0 ) ;
if ( V_2 -> V_67 )
F_31 ( NULL , V_2 -> V_83 ,
V_2 -> V_67 , 0 ) ;
#if V_88 != 0
F_66 ( V_2 -> V_56 ) ;
F_66 ( V_2 -> V_65 ) ;
F_66 ( V_2 -> V_89 ) ;
#else
F_31 ( NULL , 2 * sizeof( struct V_37 ) ,
V_2 -> V_56 , 0 ) ;
F_31 ( NULL , 2 * sizeof( struct V_37 ) ,
V_2 -> V_65 , 0 ) ;
F_67 ( V_2 -> V_89 ) ;
#endif
F_69 ( V_2 -> V_52 ) ;
F_69 ( V_2 -> V_53 ) ;
F_68 ( V_2 -> V_136 , V_2 ) ;
F_67 ( V_2 -> V_144 ) ;
F_70 ( V_2 -> V_130 ) ;
F_67 ( V_2 ) ;
}
int F_72 ( struct V_1 * V_2 , T_5 * V_149 , \
T_5 * V_150 , int V_104 )
{
unsigned short V_151 ;
unsigned short V_96 ;
unsigned long V_55 ;
unsigned long V_152 = 0 ;
F_2 ( L_51 , \
V_7 , V_149 , V_150 , V_104 ) ;
F_2 ( L_52
L_53 ,
V_2 -> V_8 -> V_9 , V_2 -> V_8 -> V_34 ,
V_2 -> V_8 -> V_35 , V_2 -> V_8 -> V_36 ,
V_2 -> V_8 -> V_15 , V_2 -> V_8 -> V_16 ) ;
F_73 ( ( unsigned ) V_149 , ( unsigned ) ( V_149 + V_104 ) ) ;
V_151 = ( V_153 | V_71 | V_79 ) ;
F_74 ( V_2 -> V_53 , ( unsigned long ) V_149 ) ;
F_19 ( V_2 -> V_53 , V_104 / 2 ) ;
F_20 ( V_2 -> V_53 , 2 ) ;
F_21 ( V_2 -> V_53 , V_151 ) ;
F_8 ( V_2 -> V_53 ) ;
if ( V_150 != NULL ) {
F_75 ( ( unsigned ) V_150 , \
( unsigned ) ( V_150 + V_104 ) ) ;
V_151 = ( V_153 | V_71 | V_64 | V_79 ) ;
F_74 ( V_2 -> V_52 , ( unsigned long ) V_150 ) ;
F_19 ( V_2 -> V_52 , V_104 / 2 ) ;
F_20 ( V_2 -> V_52 , 2 ) ;
F_21 ( V_2 -> V_52 , V_151 ) ;
F_8 ( V_2 -> V_52 ) ;
}
F_13 ( V_55 ) ;
V_2 -> V_8 -> V_9 |= V_10 ;
V_2 -> V_8 -> V_11 |= V_12 ;
F_3 () ;
V_96 = F_44 ( V_2 -> V_53 ) ;
while ( V_96 & V_154 ) {
F_76 ( 1 ) ;
V_96 = F_44 ( V_2 -> V_53 ) ;
F_2 ( L_54 , V_96 ) ;
if ( V_152 ++ > 100 )
goto V_155;
}
V_96 = V_2 -> V_8 -> V_97 ;
V_152 = 0 ;
while ( ! ( V_96 & V_156 ) ) {
F_2 ( L_55 , V_96 ) ;
F_76 ( 1 ) ;
V_96 = * ( unsigned short * ) & V_2 -> V_8 -> V_97 ;
if ( V_152 ++ > 1000 )
goto V_155;
}
F_76 ( 20 ) ;
F_2 ( L_55 , V_96 ) ;
V_155:
V_2 -> V_8 -> V_9 &= ~ V_10 ;
V_2 -> V_8 -> V_11 &= ~ V_12 ;
F_3 () ;
F_10 ( V_2 -> V_53 ) ;
F_45 ( V_2 -> V_53 ) ;
if ( V_150 != NULL ) {
F_10 ( V_2 -> V_52 ) ;
F_45 ( V_2 -> V_52 ) ;
}
F_3 () ;
F_15 ( V_55 ) ;
return 0 ;
}
