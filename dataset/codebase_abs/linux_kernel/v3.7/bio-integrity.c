static inline unsigned int F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case 1 :
return 0 ;
case 2 ... 4 :
return 1 ;
case 5 ... 16 :
return 2 ;
case 17 ... 64 :
return 3 ;
case 65 ... 128 :
return 4 ;
case 129 ... V_2 :
return 5 ;
default:
F_2 () ;
}
}
static inline int F_3 ( unsigned int V_3 )
{
if ( V_3 == V_4 )
return 1 ;
return 0 ;
}
struct V_5 * F_4 ( struct V_6 * V_6 ,
T_1 V_7 ,
unsigned int V_8 )
{
struct V_5 * V_9 ;
unsigned int V_3 = F_1 ( V_8 ) ;
struct V_10 * V_11 = V_6 -> V_12 ;
if ( ! V_11 )
V_11 = V_13 ;
F_5 ( V_6 == NULL ) ;
V_9 = NULL ;
if ( ! F_3 ( V_3 ) )
V_9 = F_6 ( V_14 [ V_3 ] . V_15 , V_7 ) ;
if ( V_9 == NULL ) {
V_3 = V_4 ;
V_9 = F_7 ( V_11 -> V_16 , V_7 ) ;
if ( F_8 ( V_9 == NULL ) ) {
F_9 ( V_17 L_1 , V_18 ) ;
return NULL ;
}
}
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_14 = V_3 ;
V_9 -> V_19 = V_6 ;
V_6 -> V_20 = V_9 ;
return V_9 ;
}
void F_10 ( struct V_6 * V_6 )
{
struct V_5 * V_9 = V_6 -> V_20 ;
struct V_10 * V_11 = V_6 -> V_12 ;
if ( ! V_11 )
V_11 = V_13 ;
F_5 ( V_9 == NULL ) ;
if ( ! F_11 ( V_6 , V_21 ) && ! F_11 ( V_6 , V_22 )
&& V_9 -> V_23 != NULL )
F_12 ( V_9 -> V_23 ) ;
if ( F_3 ( V_9 -> V_14 ) )
F_13 ( V_9 , V_11 -> V_16 ) ;
else
F_14 ( V_14 [ V_9 -> V_14 ] . V_15 , V_9 ) ;
V_6 -> V_20 = NULL ;
}
int F_15 ( struct V_6 * V_6 , struct V_24 * V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_5 * V_9 = V_6 -> V_20 ;
struct V_27 * V_28 ;
if ( V_9 -> V_29 >= F_16 ( V_9 -> V_14 ) ) {
F_9 ( V_17 L_2 , V_18 ) ;
return 0 ;
}
V_28 = F_17 ( V_9 , V_9 -> V_29 ) ;
F_5 ( V_28 == NULL ) ;
V_28 -> V_30 = V_24 ;
V_28 -> V_31 = V_25 ;
V_28 -> V_32 = V_26 ;
V_9 -> V_29 ++ ;
return V_25 ;
}
static int F_18 ( struct V_33 * V_34 , int V_35 )
{
struct V_36 * V_37 = F_19 ( V_34 ) ;
if ( V_37 == NULL )
return 0 ;
if ( V_35 == V_38 && V_37 -> V_39 != NULL &&
( V_37 -> V_40 & V_41 ) )
return 1 ;
if ( V_35 == V_42 && V_37 -> V_43 != NULL &&
( V_37 -> V_40 & V_44 ) )
return 1 ;
return 0 ;
}
int F_20 ( struct V_6 * V_6 )
{
if ( F_21 ( V_6 ) )
return 0 ;
return F_18 ( V_6 -> V_45 , F_22 ( V_6 ) ) ;
}
static inline unsigned int F_23 ( struct V_36 * V_37 ,
unsigned int V_46 )
{
if ( V_37 -> V_47 == 4096 )
return V_46 >>= 3 ;
return V_46 ;
}
unsigned int F_24 ( struct V_6 * V_6 )
{
struct V_36 * V_37 = F_19 ( V_6 -> V_45 ) ;
F_5 ( V_6 -> V_48 == 0 ) ;
return V_37 -> V_49 * ( V_6 -> V_48 / V_37 -> V_47 ) ;
}
int F_25 ( struct V_6 * V_6 , void * V_50 , unsigned int V_25 , int V_51 )
{
struct V_5 * V_9 = V_6 -> V_20 ;
struct V_36 * V_37 = F_19 ( V_6 -> V_45 ) ;
unsigned int V_52 ;
F_5 ( V_9 -> V_23 == NULL ) ;
if ( V_37 -> V_49 == 0 )
return - 1 ;
V_52 = F_23 ( V_37 ,
F_26 ( V_25 , V_37 -> V_49 ) ) ;
if ( V_52 * V_37 -> V_53 > V_9 -> V_54 ) {
F_9 ( V_17 L_3 ,
V_18 , V_52 * V_37 -> V_53 , V_9 -> V_54 ) ;
return - 1 ;
}
if ( V_51 )
V_37 -> V_55 ( V_9 -> V_23 , V_50 , V_52 ) ;
else
V_37 -> V_56 ( V_9 -> V_23 , V_50 , V_52 ) ;
return 0 ;
}
int F_27 ( struct V_6 * V_6 , void * V_50 , unsigned int V_25 )
{
F_5 ( F_22 ( V_6 ) != V_42 ) ;
return F_25 ( V_6 , V_50 , V_25 , 1 ) ;
}
int F_28 ( struct V_6 * V_6 , void * V_50 , unsigned int V_25 )
{
F_5 ( F_22 ( V_6 ) != V_38 ) ;
return F_25 ( V_6 , V_50 , V_25 , 0 ) ;
}
static void F_29 ( struct V_6 * V_6 )
{
struct V_36 * V_37 = F_19 ( V_6 -> V_45 ) ;
struct V_57 V_58 ;
struct V_27 * V_59 ;
T_2 V_60 = V_6 -> V_61 ;
unsigned int V_62 , V_46 , V_63 ;
void * V_64 = V_6 -> V_20 -> V_23 ;
V_63 = 0 ;
V_58 . V_65 = V_6 -> V_45 -> V_66 -> V_65 ;
V_58 . V_47 = V_37 -> V_47 ;
F_30 (bv, bio, i) {
void * V_67 = F_31 ( V_59 -> V_30 ) ;
V_58 . V_68 = V_67 + V_59 -> V_32 ;
V_58 . V_69 = V_59 -> V_31 ;
V_58 . V_64 = V_64 ;
V_58 . V_60 = V_60 ;
V_37 -> V_43 ( & V_58 ) ;
V_46 = V_59 -> V_31 / V_37 -> V_47 ;
V_60 += V_46 ;
V_64 += V_46 * V_37 -> V_53 ;
V_63 += V_46 * V_37 -> V_53 ;
F_5 ( V_63 > V_6 -> V_20 -> V_54 ) ;
F_32 ( V_67 ) ;
}
}
static inline unsigned short F_33 ( struct V_36 * V_37 )
{
if ( V_37 )
return V_37 -> V_53 ;
return 0 ;
}
int F_34 ( struct V_6 * V_6 )
{
struct V_5 * V_9 ;
struct V_36 * V_37 ;
struct V_70 * V_71 ;
void * V_72 ;
unsigned long V_73 , V_74 ;
unsigned int V_25 , V_75 ;
unsigned int V_76 , V_26 , V_62 ;
unsigned int V_46 ;
V_37 = F_19 ( V_6 -> V_45 ) ;
V_71 = F_35 ( V_6 -> V_45 ) ;
F_5 ( V_37 == NULL ) ;
F_5 ( F_21 ( V_6 ) ) ;
V_46 = F_23 ( V_37 , F_36 ( V_6 ) ) ;
V_25 = V_46 * F_33 ( V_37 ) ;
V_72 = F_37 ( V_25 , V_77 | V_71 -> V_78 ) ;
if ( F_8 ( V_72 == NULL ) ) {
F_9 ( V_17 L_4 ) ;
return - V_79 ;
}
V_74 = ( ( ( unsigned long ) V_72 ) + V_25 + V_80 - 1 ) >> V_81 ;
V_73 = ( ( unsigned long ) V_72 ) >> V_81 ;
V_75 = V_74 - V_73 ;
V_9 = F_4 ( V_6 , V_77 , V_75 ) ;
if ( F_8 ( V_9 == NULL ) ) {
F_9 ( V_17 L_5 ) ;
F_12 ( V_72 ) ;
return - V_82 ;
}
V_9 -> V_23 = V_72 ;
V_9 -> V_54 = V_25 ;
V_9 -> V_83 = V_6 -> V_61 ;
V_26 = F_38 ( V_72 ) ;
for ( V_62 = 0 ; V_62 < V_75 ; V_62 ++ ) {
int V_84 ;
V_76 = V_80 - V_26 ;
if ( V_25 <= 0 )
break;
if ( V_76 > V_25 )
V_76 = V_25 ;
V_84 = F_15 ( V_6 , F_39 ( V_72 ) ,
V_76 , V_26 ) ;
if ( V_84 == 0 )
return 0 ;
if ( V_84 < V_76 )
break;
V_72 += V_76 ;
V_25 -= V_76 ;
V_26 = 0 ;
}
if ( F_22 ( V_6 ) == V_38 ) {
V_9 -> V_85 = V_6 -> V_86 ;
V_6 -> V_86 = V_87 ;
}
if ( F_22 ( V_6 ) == V_42 )
F_29 ( V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_6 )
{
struct V_36 * V_37 = F_19 ( V_6 -> V_45 ) ;
struct V_57 V_58 ;
struct V_27 * V_59 ;
T_2 V_60 = V_6 -> V_20 -> V_83 ;
unsigned int V_62 , V_46 , V_63 , V_84 ;
void * V_64 = V_6 -> V_20 -> V_23 ;
V_84 = V_63 = 0 ;
V_58 . V_65 = V_6 -> V_45 -> V_66 -> V_65 ;
V_58 . V_47 = V_37 -> V_47 ;
F_30 (bv, bio, i) {
void * V_67 = F_31 ( V_59 -> V_30 ) ;
V_58 . V_68 = V_67 + V_59 -> V_32 ;
V_58 . V_69 = V_59 -> V_31 ;
V_58 . V_64 = V_64 ;
V_58 . V_60 = V_60 ;
V_84 = V_37 -> V_39 ( & V_58 ) ;
if ( V_84 ) {
F_32 ( V_67 ) ;
return V_84 ;
}
V_46 = V_59 -> V_31 / V_37 -> V_47 ;
V_60 += V_46 ;
V_64 += V_46 * V_37 -> V_53 ;
V_63 += V_46 * V_37 -> V_53 ;
F_5 ( V_63 > V_6 -> V_20 -> V_54 ) ;
F_32 ( V_67 ) ;
}
return V_84 ;
}
static void F_41 ( struct V_88 * V_89 )
{
struct V_5 * V_9 =
F_42 ( V_89 , struct V_5 , V_90 ) ;
struct V_6 * V_6 = V_9 -> V_19 ;
int error ;
error = F_40 ( V_6 ) ;
V_6 -> V_86 = V_9 -> V_85 ;
F_43 ( V_6 , error ) ;
}
void V_87 ( struct V_6 * V_6 , int error )
{
struct V_5 * V_9 = V_6 -> V_20 ;
F_5 ( V_9 -> V_19 != V_6 ) ;
if ( error ) {
V_6 -> V_86 = V_9 -> V_85 ;
F_43 ( V_6 , error ) ;
return;
}
F_44 ( & V_9 -> V_90 , F_41 ) ;
F_45 ( V_91 , & V_9 -> V_90 ) ;
}
void F_46 ( struct V_5 * V_9 ,
unsigned int V_92 )
{
struct V_27 * V_28 ;
unsigned int V_62 ;
F_47 (iv, bip, i) {
if ( V_92 == 0 ) {
V_9 -> V_93 = V_62 ;
return;
} else if ( V_92 >= V_28 -> V_31 ) {
V_92 -= V_28 -> V_31 ;
} else {
V_28 -> V_32 += V_92 ;
V_28 -> V_31 -= V_92 ;
V_9 -> V_93 = V_62 ;
return;
}
}
}
void F_48 ( struct V_5 * V_9 ,
unsigned int V_25 )
{
struct V_27 * V_28 ;
unsigned int V_62 ;
F_47 (iv, bip, i) {
if ( V_25 == 0 ) {
V_9 -> V_29 = V_62 ;
return;
} else if ( V_25 >= V_28 -> V_31 ) {
V_25 -= V_28 -> V_31 ;
} else {
V_28 -> V_31 = V_25 ;
V_25 = 0 ;
}
}
}
void F_49 ( struct V_6 * V_6 , unsigned int V_94 )
{
struct V_5 * V_9 = V_6 -> V_20 ;
struct V_36 * V_37 = F_19 ( V_6 -> V_45 ) ;
unsigned int V_52 ;
F_5 ( V_9 == NULL ) ;
F_5 ( V_37 == NULL ) ;
V_52 = F_23 ( V_37 , V_94 >> 9 ) ;
F_46 ( V_9 , V_52 * V_37 -> V_53 ) ;
}
void F_50 ( struct V_6 * V_6 , unsigned int V_26 ,
unsigned int V_46 )
{
struct V_5 * V_9 = V_6 -> V_20 ;
struct V_36 * V_37 = F_19 ( V_6 -> V_45 ) ;
unsigned int V_52 ;
F_5 ( V_9 == NULL ) ;
F_5 ( V_37 == NULL ) ;
F_5 ( ! F_11 ( V_6 , V_21 ) ) ;
V_52 = F_23 ( V_37 , V_46 ) ;
V_9 -> V_83 = V_9 -> V_83 + V_26 ;
F_46 ( V_9 , V_26 * V_37 -> V_53 ) ;
F_48 ( V_9 , V_46 * V_37 -> V_53 ) ;
}
void F_51 ( struct V_6 * V_6 , struct V_95 * V_96 , int V_46 )
{
struct V_36 * V_37 ;
struct V_5 * V_9 = V_6 -> V_20 ;
unsigned int V_52 ;
if ( F_21 ( V_6 ) == 0 )
return;
V_37 = F_19 ( V_6 -> V_45 ) ;
F_5 ( V_37 == NULL ) ;
F_5 ( V_9 -> V_29 != 1 ) ;
V_52 = F_23 ( V_37 , V_46 ) ;
V_96 -> V_97 . V_20 = & V_96 -> V_98 ;
V_96 -> V_99 . V_20 = & V_96 -> V_100 ;
V_96 -> V_101 = V_9 -> V_102 [ 0 ] ;
V_96 -> V_103 = V_9 -> V_102 [ 0 ] ;
V_96 -> V_98 . V_102 [ 0 ] = V_96 -> V_101 ;
V_96 -> V_100 . V_102 [ 0 ] = V_96 -> V_103 ;
V_96 -> V_101 . V_31 = V_46 * V_37 -> V_53 ;
V_96 -> V_103 . V_32 += V_46 * V_37 -> V_53 ;
V_96 -> V_103 . V_31 -= V_46 * V_37 -> V_53 ;
V_96 -> V_98 . V_83 = V_6 -> V_20 -> V_83 ;
V_96 -> V_100 . V_83 = V_6 -> V_20 -> V_83 + V_52 ;
V_96 -> V_98 . V_29 = V_96 -> V_100 . V_29 = 1 ;
V_96 -> V_98 . V_93 = V_96 -> V_100 . V_93 = 0 ;
}
int F_52 ( struct V_6 * V_6 , struct V_6 * V_104 ,
T_1 V_7 )
{
struct V_5 * V_105 = V_104 -> V_20 ;
struct V_5 * V_9 ;
F_5 ( V_105 == NULL ) ;
V_9 = F_4 ( V_6 , V_7 , V_105 -> V_29 ) ;
if ( V_9 == NULL )
return - V_82 ;
memcpy ( V_9 -> V_102 , V_105 -> V_102 ,
V_105 -> V_29 * sizeof( struct V_27 ) ) ;
V_9 -> V_83 = V_105 -> V_83 ;
V_9 -> V_29 = V_105 -> V_29 ;
V_9 -> V_93 = V_105 -> V_93 ;
return 0 ;
}
int F_53 ( struct V_10 * V_11 , int V_106 )
{
unsigned int V_107 = F_1 ( V_2 ) ;
if ( V_11 -> V_16 )
return 0 ;
V_11 -> V_16 =
F_54 ( V_106 , V_14 [ V_107 ] . V_15 ) ;
if ( ! V_11 -> V_16 )
return - 1 ;
return 0 ;
}
void F_55 ( struct V_10 * V_11 )
{
if ( V_11 -> V_16 )
F_56 ( V_11 -> V_16 ) ;
}
void T_3 F_57 ( void )
{
unsigned int V_62 ;
V_91 = F_58 ( L_6 , V_108 |
V_109 | V_110 , 1 ) ;
if ( ! V_91 )
F_59 ( L_7 ) ;
for ( V_62 = 0 ; V_62 < V_111 ; V_62 ++ ) {
unsigned int V_112 ;
V_112 = sizeof( struct V_5 )
+ V_14 [ V_62 ] . V_8 * sizeof( struct V_27 ) ;
V_14 [ V_62 ] . V_15 =
F_60 ( V_14 [ V_62 ] . V_113 , V_112 , 0 ,
V_114 | V_115 , NULL ) ;
}
}
