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
unsigned int V_8 ,
struct V_9 * V_10 )
{
struct V_5 * V_11 ;
unsigned int V_3 = F_1 ( V_8 ) ;
F_5 ( V_6 == NULL ) ;
V_11 = NULL ;
if ( ! F_3 ( V_3 ) )
V_11 = F_6 ( V_12 [ V_3 ] . V_13 , V_7 ) ;
if ( V_11 == NULL ) {
V_3 = V_4 ;
V_11 = F_7 ( V_10 -> V_14 , V_7 ) ;
if ( F_8 ( V_11 == NULL ) ) {
F_9 ( V_15 L_1 , V_16 ) ;
return NULL ;
}
}
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_12 = V_3 ;
V_11 -> V_17 = V_6 ;
V_6 -> V_18 = V_11 ;
return V_11 ;
}
struct V_5 * F_10 ( struct V_6 * V_6 ,
T_1 V_7 ,
unsigned int V_8 )
{
return F_4 ( V_6 , V_7 , V_8 , V_19 ) ;
}
void F_11 ( struct V_6 * V_6 , struct V_9 * V_10 )
{
struct V_5 * V_11 = V_6 -> V_18 ;
F_5 ( V_11 == NULL ) ;
if ( ! F_12 ( V_6 , V_20 ) && ! F_12 ( V_6 , V_21 )
&& V_11 -> V_22 != NULL )
F_13 ( V_11 -> V_22 ) ;
if ( F_3 ( V_11 -> V_12 ) )
F_14 ( V_11 , V_10 -> V_14 ) ;
else
F_15 ( V_12 [ V_11 -> V_12 ] . V_13 , V_11 ) ;
V_6 -> V_18 = NULL ;
}
int F_16 ( struct V_6 * V_6 , struct V_23 * V_23 ,
unsigned int V_24 , unsigned int V_25 )
{
struct V_5 * V_11 = V_6 -> V_18 ;
struct V_26 * V_27 ;
if ( V_11 -> V_28 >= F_17 ( V_11 -> V_12 ) ) {
F_9 ( V_15 L_2 , V_16 ) ;
return 0 ;
}
V_27 = F_18 ( V_11 , V_11 -> V_28 ) ;
F_5 ( V_27 == NULL ) ;
V_27 -> V_29 = V_23 ;
V_27 -> V_30 = V_24 ;
V_27 -> V_31 = V_25 ;
V_11 -> V_28 ++ ;
return V_24 ;
}
static int F_19 ( struct V_32 * V_33 , int V_34 )
{
struct V_35 * V_36 = F_20 ( V_33 ) ;
if ( V_36 == NULL )
return 0 ;
if ( V_34 == V_37 && V_36 -> V_38 != NULL &&
( V_36 -> V_39 & V_40 ) )
return 1 ;
if ( V_34 == V_41 && V_36 -> V_42 != NULL &&
( V_36 -> V_39 & V_43 ) )
return 1 ;
return 0 ;
}
int F_21 ( struct V_6 * V_6 )
{
if ( F_22 ( V_6 ) )
return 0 ;
return F_19 ( V_6 -> V_44 , F_23 ( V_6 ) ) ;
}
static inline unsigned int F_24 ( struct V_35 * V_36 ,
unsigned int V_45 )
{
if ( V_36 -> V_46 == 4096 )
return V_45 >>= 3 ;
return V_45 ;
}
unsigned int F_25 ( struct V_6 * V_6 )
{
struct V_35 * V_36 = F_20 ( V_6 -> V_44 ) ;
F_5 ( V_6 -> V_47 == 0 ) ;
return V_36 -> V_48 * ( V_6 -> V_47 / V_36 -> V_46 ) ;
}
int F_26 ( struct V_6 * V_6 , void * V_49 , unsigned int V_24 , int V_50 )
{
struct V_5 * V_11 = V_6 -> V_18 ;
struct V_35 * V_36 = F_20 ( V_6 -> V_44 ) ;
unsigned int V_51 ;
F_5 ( V_11 -> V_22 == NULL ) ;
if ( V_36 -> V_48 == 0 )
return - 1 ;
V_51 = F_24 ( V_36 ,
F_27 ( V_24 , V_36 -> V_48 ) ) ;
if ( V_51 * V_36 -> V_52 > V_11 -> V_53 ) {
F_9 ( V_15 L_3 ,
V_16 , V_51 * V_36 -> V_52 , V_11 -> V_53 ) ;
return - 1 ;
}
if ( V_50 )
V_36 -> V_54 ( V_11 -> V_22 , V_49 , V_51 ) ;
else
V_36 -> V_55 ( V_11 -> V_22 , V_49 , V_51 ) ;
return 0 ;
}
int F_28 ( struct V_6 * V_6 , void * V_49 , unsigned int V_24 )
{
F_5 ( F_23 ( V_6 ) != V_41 ) ;
return F_26 ( V_6 , V_49 , V_24 , 1 ) ;
}
int F_29 ( struct V_6 * V_6 , void * V_49 , unsigned int V_24 )
{
F_5 ( F_23 ( V_6 ) != V_37 ) ;
return F_26 ( V_6 , V_49 , V_24 , 0 ) ;
}
static void F_30 ( struct V_6 * V_6 )
{
struct V_35 * V_36 = F_20 ( V_6 -> V_44 ) ;
struct V_56 V_57 ;
struct V_26 * V_58 ;
T_2 V_59 = V_6 -> V_60 ;
unsigned int V_61 , V_45 , V_62 ;
void * V_63 = V_6 -> V_18 -> V_22 ;
V_62 = 0 ;
V_57 . V_64 = V_6 -> V_44 -> V_65 -> V_64 ;
V_57 . V_46 = V_36 -> V_46 ;
F_31 (bv, bio, i) {
void * V_66 = F_32 ( V_58 -> V_29 ) ;
V_57 . V_67 = V_66 + V_58 -> V_31 ;
V_57 . V_68 = V_58 -> V_30 ;
V_57 . V_63 = V_63 ;
V_57 . V_59 = V_59 ;
V_36 -> V_42 ( & V_57 ) ;
V_45 = V_58 -> V_30 / V_36 -> V_46 ;
V_59 += V_45 ;
V_63 += V_45 * V_36 -> V_52 ;
V_62 += V_45 * V_36 -> V_52 ;
F_5 ( V_62 > V_6 -> V_18 -> V_53 ) ;
F_33 ( V_66 ) ;
}
}
static inline unsigned short F_34 ( struct V_35 * V_36 )
{
if ( V_36 )
return V_36 -> V_52 ;
return 0 ;
}
int F_35 ( struct V_6 * V_6 )
{
struct V_5 * V_11 ;
struct V_35 * V_36 ;
struct V_69 * V_70 ;
void * V_71 ;
unsigned long V_72 , V_73 ;
unsigned int V_24 , V_74 ;
unsigned int V_75 , V_25 , V_61 ;
unsigned int V_45 ;
V_36 = F_20 ( V_6 -> V_44 ) ;
V_70 = F_36 ( V_6 -> V_44 ) ;
F_5 ( V_36 == NULL ) ;
F_5 ( F_22 ( V_6 ) ) ;
V_45 = F_24 ( V_36 , F_37 ( V_6 ) ) ;
V_24 = V_45 * F_34 ( V_36 ) ;
V_71 = F_38 ( V_24 , V_76 | V_70 -> V_77 ) ;
if ( F_8 ( V_71 == NULL ) ) {
F_9 ( V_15 L_4 ) ;
return - V_78 ;
}
V_73 = ( ( ( unsigned long ) V_71 ) + V_24 + V_79 - 1 ) >> V_80 ;
V_72 = ( ( unsigned long ) V_71 ) >> V_80 ;
V_74 = V_73 - V_72 ;
V_11 = F_10 ( V_6 , V_76 , V_74 ) ;
if ( F_8 ( V_11 == NULL ) ) {
F_9 ( V_15 L_5 ) ;
F_13 ( V_71 ) ;
return - V_81 ;
}
V_11 -> V_22 = V_71 ;
V_11 -> V_53 = V_24 ;
V_11 -> V_82 = V_6 -> V_60 ;
V_25 = F_39 ( V_71 ) ;
for ( V_61 = 0 ; V_61 < V_74 ; V_61 ++ ) {
int V_83 ;
V_75 = V_79 - V_25 ;
if ( V_24 <= 0 )
break;
if ( V_75 > V_24 )
V_75 = V_24 ;
V_83 = F_16 ( V_6 , F_40 ( V_71 ) ,
V_75 , V_25 ) ;
if ( V_83 == 0 )
return 0 ;
if ( V_83 < V_75 )
break;
V_71 += V_75 ;
V_24 -= V_75 ;
V_25 = 0 ;
}
if ( F_23 ( V_6 ) == V_37 ) {
V_11 -> V_84 = V_6 -> V_85 ;
V_6 -> V_85 = V_86 ;
}
if ( F_23 ( V_6 ) == V_41 )
F_30 ( V_6 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_6 )
{
struct V_35 * V_36 = F_20 ( V_6 -> V_44 ) ;
struct V_56 V_57 ;
struct V_26 * V_58 ;
T_2 V_59 = V_6 -> V_18 -> V_82 ;
unsigned int V_61 , V_45 , V_62 , V_83 ;
void * V_63 = V_6 -> V_18 -> V_22 ;
V_83 = V_62 = 0 ;
V_57 . V_64 = V_6 -> V_44 -> V_65 -> V_64 ;
V_57 . V_46 = V_36 -> V_46 ;
F_31 (bv, bio, i) {
void * V_66 = F_32 ( V_58 -> V_29 ) ;
V_57 . V_67 = V_66 + V_58 -> V_31 ;
V_57 . V_68 = V_58 -> V_30 ;
V_57 . V_63 = V_63 ;
V_57 . V_59 = V_59 ;
V_83 = V_36 -> V_38 ( & V_57 ) ;
if ( V_83 ) {
F_33 ( V_66 ) ;
return V_83 ;
}
V_45 = V_58 -> V_30 / V_36 -> V_46 ;
V_59 += V_45 ;
V_63 += V_45 * V_36 -> V_52 ;
V_62 += V_45 * V_36 -> V_52 ;
F_5 ( V_62 > V_6 -> V_18 -> V_53 ) ;
F_33 ( V_66 ) ;
}
return V_83 ;
}
static void F_42 ( struct V_87 * V_88 )
{
struct V_5 * V_11 =
F_43 ( V_88 , struct V_5 , V_89 ) ;
struct V_6 * V_6 = V_11 -> V_17 ;
int error ;
error = F_41 ( V_6 ) ;
V_6 -> V_85 = V_11 -> V_84 ;
F_44 ( V_6 , error ) ;
}
void V_86 ( struct V_6 * V_6 , int error )
{
struct V_5 * V_11 = V_6 -> V_18 ;
F_5 ( V_11 -> V_17 != V_6 ) ;
if ( error ) {
V_6 -> V_85 = V_11 -> V_84 ;
F_44 ( V_6 , error ) ;
return;
}
F_45 ( & V_11 -> V_89 , F_42 ) ;
F_46 ( V_90 , & V_11 -> V_89 ) ;
}
void F_47 ( struct V_5 * V_11 ,
unsigned int V_91 )
{
struct V_26 * V_27 ;
unsigned int V_61 ;
F_48 (iv, bip, i) {
if ( V_91 == 0 ) {
V_11 -> V_92 = V_61 ;
return;
} else if ( V_91 >= V_27 -> V_30 ) {
V_91 -= V_27 -> V_30 ;
} else {
V_27 -> V_31 += V_91 ;
V_27 -> V_30 -= V_91 ;
V_11 -> V_92 = V_61 ;
return;
}
}
}
void F_49 ( struct V_5 * V_11 ,
unsigned int V_24 )
{
struct V_26 * V_27 ;
unsigned int V_61 ;
F_48 (iv, bip, i) {
if ( V_24 == 0 ) {
V_11 -> V_28 = V_61 ;
return;
} else if ( V_24 >= V_27 -> V_30 ) {
V_24 -= V_27 -> V_30 ;
} else {
V_27 -> V_30 = V_24 ;
V_24 = 0 ;
}
}
}
void F_50 ( struct V_6 * V_6 , unsigned int V_93 )
{
struct V_5 * V_11 = V_6 -> V_18 ;
struct V_35 * V_36 = F_20 ( V_6 -> V_44 ) ;
unsigned int V_51 ;
F_5 ( V_11 == NULL ) ;
F_5 ( V_36 == NULL ) ;
V_51 = F_24 ( V_36 , V_93 >> 9 ) ;
F_47 ( V_11 , V_51 * V_36 -> V_52 ) ;
}
void F_51 ( struct V_6 * V_6 , unsigned int V_25 ,
unsigned int V_45 )
{
struct V_5 * V_11 = V_6 -> V_18 ;
struct V_35 * V_36 = F_20 ( V_6 -> V_44 ) ;
unsigned int V_51 ;
F_5 ( V_11 == NULL ) ;
F_5 ( V_36 == NULL ) ;
F_5 ( ! F_12 ( V_6 , V_20 ) ) ;
V_51 = F_24 ( V_36 , V_45 ) ;
V_11 -> V_82 = V_11 -> V_82 + V_25 ;
F_47 ( V_11 , V_25 * V_36 -> V_52 ) ;
F_49 ( V_11 , V_45 * V_36 -> V_52 ) ;
}
void F_52 ( struct V_6 * V_6 , struct V_94 * V_95 , int V_45 )
{
struct V_35 * V_36 ;
struct V_5 * V_11 = V_6 -> V_18 ;
unsigned int V_51 ;
if ( F_22 ( V_6 ) == 0 )
return;
V_36 = F_20 ( V_6 -> V_44 ) ;
F_5 ( V_36 == NULL ) ;
F_5 ( V_11 -> V_28 != 1 ) ;
V_51 = F_24 ( V_36 , V_45 ) ;
V_95 -> V_96 . V_18 = & V_95 -> V_97 ;
V_95 -> V_98 . V_18 = & V_95 -> V_99 ;
V_95 -> V_100 = V_11 -> V_101 [ 0 ] ;
V_95 -> V_102 = V_11 -> V_101 [ 0 ] ;
V_95 -> V_97 . V_101 [ 0 ] = V_95 -> V_100 ;
V_95 -> V_99 . V_101 [ 0 ] = V_95 -> V_102 ;
V_95 -> V_100 . V_30 = V_45 * V_36 -> V_52 ;
V_95 -> V_102 . V_31 += V_45 * V_36 -> V_52 ;
V_95 -> V_102 . V_30 -= V_45 * V_36 -> V_52 ;
V_95 -> V_97 . V_82 = V_6 -> V_18 -> V_82 ;
V_95 -> V_99 . V_82 = V_6 -> V_18 -> V_82 + V_51 ;
V_95 -> V_97 . V_28 = V_95 -> V_99 . V_28 = 1 ;
V_95 -> V_97 . V_92 = V_95 -> V_99 . V_92 = 0 ;
}
int F_53 ( struct V_6 * V_6 , struct V_6 * V_103 ,
T_1 V_7 , struct V_9 * V_10 )
{
struct V_5 * V_104 = V_103 -> V_18 ;
struct V_5 * V_11 ;
F_5 ( V_104 == NULL ) ;
V_11 = F_4 ( V_6 , V_7 , V_104 -> V_28 , V_10 ) ;
if ( V_11 == NULL )
return - V_81 ;
memcpy ( V_11 -> V_101 , V_104 -> V_101 ,
V_104 -> V_28 * sizeof( struct V_26 ) ) ;
V_11 -> V_82 = V_104 -> V_82 ;
V_11 -> V_28 = V_104 -> V_28 ;
V_11 -> V_92 = V_104 -> V_92 ;
return 0 ;
}
int F_54 ( struct V_9 * V_10 , int V_105 )
{
unsigned int V_106 = F_1 ( V_2 ) ;
if ( V_10 -> V_14 )
return 0 ;
V_10 -> V_14 =
F_55 ( V_105 , V_12 [ V_106 ] . V_13 ) ;
if ( ! V_10 -> V_14 )
return - 1 ;
return 0 ;
}
void F_56 ( struct V_9 * V_10 )
{
if ( V_10 -> V_14 )
F_57 ( V_10 -> V_14 ) ;
}
void T_3 F_58 ( void )
{
unsigned int V_61 ;
V_90 = F_59 ( L_6 , V_107 |
V_108 | V_109 , 1 ) ;
if ( ! V_90 )
F_60 ( L_7 ) ;
for ( V_61 = 0 ; V_61 < V_110 ; V_61 ++ ) {
unsigned int V_111 ;
V_111 = sizeof( struct V_5 )
+ V_12 [ V_61 ] . V_8 * sizeof( struct V_26 ) ;
V_12 [ V_61 ] . V_13 =
F_61 ( V_12 [ V_61 ] . V_112 , V_111 , 0 ,
V_113 | V_114 , NULL ) ;
}
}
