struct V_1 * F_1 ( struct V_2 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_10 ;
unsigned V_11 ;
if ( ! V_7 ) {
V_5 = F_2 ( sizeof( struct V_1 ) +
sizeof( struct V_12 ) * V_4 , V_3 ) ;
V_11 = V_4 ;
} else {
V_5 = F_3 ( V_7 -> V_13 , V_3 ) ;
V_11 = V_14 ;
}
if ( F_4 ( ! V_5 ) )
return NULL ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
if ( V_4 > V_11 ) {
V_5 -> V_15 = F_5 ( V_3 , V_4 , & V_9 ,
V_7 -> V_16 ) ;
if ( ! V_5 -> V_15 )
goto V_17;
} else {
V_5 -> V_15 = V_5 -> V_18 ;
}
V_5 -> V_19 = V_9 ;
V_5 -> V_20 = V_2 ;
V_2 -> V_21 = V_5 ;
return V_5 ;
V_17:
F_6 ( V_5 , V_7 -> V_13 ) ;
return NULL ;
}
void F_7 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_5 -> V_22 )
F_8 ( V_5 -> V_23 ) ;
if ( V_7 ) {
if ( V_5 -> V_19 != V_10 )
F_9 ( V_7 -> V_16 , V_5 -> V_15 ,
V_5 -> V_19 ) ;
F_6 ( V_5 , V_7 -> V_13 ) ;
} else {
F_8 ( V_5 ) ;
}
V_2 -> V_21 = NULL ;
}
int F_10 ( struct V_2 * V_2 , struct V_24 * V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_12 * V_27 ;
if ( V_5 -> V_28 >= F_11 ( V_5 -> V_19 ) ) {
F_12 ( V_29 L_1 , V_30 ) ;
return 0 ;
}
V_27 = F_13 ( V_5 , V_5 -> V_28 ) ;
F_14 ( V_27 == NULL ) ;
V_27 -> V_31 = V_24 ;
V_27 -> V_32 = V_25 ;
V_27 -> V_33 = V_26 ;
V_5 -> V_28 ++ ;
return V_25 ;
}
static int F_15 ( struct V_34 * V_35 , int V_36 )
{
struct V_37 * V_38 = F_16 ( V_35 ) ;
if ( V_38 == NULL )
return 0 ;
if ( V_36 == V_39 && V_38 -> V_40 != NULL &&
( V_38 -> V_41 & V_42 ) )
return 1 ;
if ( V_36 == V_43 && V_38 -> V_44 != NULL &&
( V_38 -> V_41 & V_45 ) )
return 1 ;
return 0 ;
}
int F_17 ( struct V_2 * V_2 )
{
if ( F_18 ( V_2 ) )
return 0 ;
return F_15 ( V_2 -> V_46 , F_19 ( V_2 ) ) ;
}
static inline unsigned int F_20 ( struct V_37 * V_38 ,
unsigned int V_47 )
{
if ( V_38 -> V_48 == 4096 )
return V_47 >>= 3 ;
return V_47 ;
}
unsigned int F_21 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_16 ( V_2 -> V_46 ) ;
F_14 ( V_2 -> V_49 == 0 ) ;
return V_38 -> V_50 * ( V_2 -> V_49 / V_38 -> V_48 ) ;
}
int F_22 ( struct V_2 * V_2 , void * V_51 , unsigned int V_25 , int V_52 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_37 * V_38 = F_16 ( V_2 -> V_46 ) ;
unsigned int V_53 ;
F_14 ( V_5 -> V_23 == NULL ) ;
if ( V_38 -> V_50 == 0 )
return - 1 ;
V_53 = F_20 ( V_38 ,
F_23 ( V_25 , V_38 -> V_50 ) ) ;
if ( V_53 * V_38 -> V_54 > V_5 -> V_55 ) {
F_12 ( V_29 L_2 ,
V_30 , V_53 * V_38 -> V_54 , V_5 -> V_55 ) ;
return - 1 ;
}
if ( V_52 )
V_38 -> V_56 ( V_5 -> V_23 , V_51 , V_53 ) ;
else
V_38 -> V_57 ( V_5 -> V_23 , V_51 , V_53 ) ;
return 0 ;
}
int F_24 ( struct V_2 * V_2 , void * V_51 , unsigned int V_25 )
{
F_14 ( F_19 ( V_2 ) != V_43 ) ;
return F_22 ( V_2 , V_51 , V_25 , 1 ) ;
}
int F_25 ( struct V_2 * V_2 , void * V_51 , unsigned int V_25 )
{
F_14 ( F_19 ( V_2 ) != V_39 ) ;
return F_22 ( V_2 , V_51 , V_25 , 0 ) ;
}
static void F_26 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_16 ( V_2 -> V_46 ) ;
struct V_58 V_59 ;
struct V_12 * V_60 ;
T_2 V_61 = V_2 -> V_62 ;
unsigned int V_63 , V_47 , V_64 ;
void * V_65 = V_2 -> V_21 -> V_23 ;
V_64 = 0 ;
V_59 . V_66 = V_2 -> V_46 -> V_67 -> V_66 ;
V_59 . V_48 = V_38 -> V_48 ;
F_27 (bv, bio, i) {
void * V_68 = F_28 ( V_60 -> V_31 ) ;
V_59 . V_69 = V_68 + V_60 -> V_33 ;
V_59 . V_70 = V_60 -> V_32 ;
V_59 . V_65 = V_65 ;
V_59 . V_61 = V_61 ;
V_38 -> V_44 ( & V_59 ) ;
V_47 = V_60 -> V_32 / V_38 -> V_48 ;
V_61 += V_47 ;
V_65 += V_47 * V_38 -> V_54 ;
V_64 += V_47 * V_38 -> V_54 ;
F_14 ( V_64 > V_2 -> V_21 -> V_55 ) ;
F_29 ( V_68 ) ;
}
}
static inline unsigned short F_30 ( struct V_37 * V_38 )
{
if ( V_38 )
return V_38 -> V_54 ;
return 0 ;
}
int F_31 ( struct V_2 * V_2 )
{
struct V_1 * V_5 ;
struct V_37 * V_38 ;
struct V_71 * V_72 ;
void * V_73 ;
unsigned long V_74 , V_75 ;
unsigned int V_25 , V_76 ;
unsigned int V_77 , V_26 , V_63 ;
unsigned int V_47 ;
V_38 = F_16 ( V_2 -> V_46 ) ;
V_72 = F_32 ( V_2 -> V_46 ) ;
F_14 ( V_38 == NULL ) ;
F_14 ( F_18 ( V_2 ) ) ;
V_47 = F_20 ( V_38 , F_33 ( V_2 ) ) ;
V_25 = V_47 * F_30 ( V_38 ) ;
V_73 = F_2 ( V_25 , V_78 | V_72 -> V_79 ) ;
if ( F_4 ( V_73 == NULL ) ) {
F_12 ( V_29 L_3 ) ;
return - V_80 ;
}
V_75 = ( ( ( unsigned long ) V_73 ) + V_25 + V_81 - 1 ) >> V_82 ;
V_74 = ( ( unsigned long ) V_73 ) >> V_82 ;
V_76 = V_75 - V_74 ;
V_5 = F_1 ( V_2 , V_78 , V_76 ) ;
if ( F_4 ( V_5 == NULL ) ) {
F_12 ( V_29 L_4 ) ;
F_8 ( V_73 ) ;
return - V_83 ;
}
V_5 -> V_22 = 1 ;
V_5 -> V_23 = V_73 ;
V_5 -> V_55 = V_25 ;
V_5 -> V_84 = V_2 -> V_62 ;
V_26 = F_34 ( V_73 ) ;
for ( V_63 = 0 ; V_63 < V_76 ; V_63 ++ ) {
int V_85 ;
V_77 = V_81 - V_26 ;
if ( V_25 <= 0 )
break;
if ( V_77 > V_25 )
V_77 = V_25 ;
V_85 = F_10 ( V_2 , F_35 ( V_73 ) ,
V_77 , V_26 ) ;
if ( V_85 == 0 )
return 0 ;
if ( V_85 < V_77 )
break;
V_73 += V_77 ;
V_25 -= V_77 ;
V_26 = 0 ;
}
if ( F_19 ( V_2 ) == V_39 ) {
V_5 -> V_86 = V_2 -> V_87 ;
V_2 -> V_87 = V_88 ;
}
if ( F_19 ( V_2 ) == V_43 )
F_26 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_16 ( V_2 -> V_46 ) ;
struct V_58 V_59 ;
struct V_12 * V_60 ;
T_2 V_61 = V_2 -> V_21 -> V_84 ;
unsigned int V_63 , V_47 , V_64 , V_85 ;
void * V_65 = V_2 -> V_21 -> V_23 ;
V_85 = V_64 = 0 ;
V_59 . V_66 = V_2 -> V_46 -> V_67 -> V_66 ;
V_59 . V_48 = V_38 -> V_48 ;
F_27 (bv, bio, i) {
void * V_68 = F_28 ( V_60 -> V_31 ) ;
V_59 . V_69 = V_68 + V_60 -> V_33 ;
V_59 . V_70 = V_60 -> V_32 ;
V_59 . V_65 = V_65 ;
V_59 . V_61 = V_61 ;
V_85 = V_38 -> V_40 ( & V_59 ) ;
if ( V_85 ) {
F_29 ( V_68 ) ;
return V_85 ;
}
V_47 = V_60 -> V_32 / V_38 -> V_48 ;
V_61 += V_47 ;
V_65 += V_47 * V_38 -> V_54 ;
V_64 += V_47 * V_38 -> V_54 ;
F_14 ( V_64 > V_2 -> V_21 -> V_55 ) ;
F_29 ( V_68 ) ;
}
return V_85 ;
}
static void F_37 ( struct V_89 * V_90 )
{
struct V_1 * V_5 =
F_38 ( V_90 , struct V_1 , V_91 ) ;
struct V_2 * V_2 = V_5 -> V_20 ;
int error ;
error = F_36 ( V_2 ) ;
V_2 -> V_87 = V_5 -> V_86 ;
F_39 ( V_2 , error ) ;
}
void V_88 ( struct V_2 * V_2 , int error )
{
struct V_1 * V_5 = V_2 -> V_21 ;
F_14 ( V_5 -> V_20 != V_2 ) ;
if ( error ) {
V_2 -> V_87 = V_5 -> V_86 ;
F_39 ( V_2 , error ) ;
return;
}
F_40 ( & V_5 -> V_91 , F_37 ) ;
F_41 ( V_92 , & V_5 -> V_91 ) ;
}
void F_42 ( struct V_1 * V_5 ,
unsigned int V_93 )
{
struct V_12 * V_27 ;
unsigned int V_63 ;
F_43 (iv, bip, i) {
if ( V_93 == 0 ) {
V_5 -> V_94 = V_63 ;
return;
} else if ( V_93 >= V_27 -> V_32 ) {
V_93 -= V_27 -> V_32 ;
} else {
V_27 -> V_33 += V_93 ;
V_27 -> V_32 -= V_93 ;
V_5 -> V_94 = V_63 ;
return;
}
}
}
void F_44 ( struct V_1 * V_5 ,
unsigned int V_25 )
{
struct V_12 * V_27 ;
unsigned int V_63 ;
F_43 (iv, bip, i) {
if ( V_25 == 0 ) {
V_5 -> V_28 = V_63 ;
return;
} else if ( V_25 >= V_27 -> V_32 ) {
V_25 -= V_27 -> V_32 ;
} else {
V_27 -> V_32 = V_25 ;
V_25 = 0 ;
}
}
}
void F_45 ( struct V_2 * V_2 , unsigned int V_95 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_37 * V_38 = F_16 ( V_2 -> V_46 ) ;
unsigned int V_53 ;
F_14 ( V_5 == NULL ) ;
F_14 ( V_38 == NULL ) ;
V_53 = F_20 ( V_38 , V_95 >> 9 ) ;
F_42 ( V_5 , V_53 * V_38 -> V_54 ) ;
}
void F_46 ( struct V_2 * V_2 , unsigned int V_26 ,
unsigned int V_47 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_37 * V_38 = F_16 ( V_2 -> V_46 ) ;
unsigned int V_53 ;
F_14 ( V_5 == NULL ) ;
F_14 ( V_38 == NULL ) ;
F_14 ( ! F_47 ( V_2 , V_96 ) ) ;
V_53 = F_20 ( V_38 , V_47 ) ;
V_5 -> V_84 = V_5 -> V_84 + V_26 ;
F_42 ( V_5 , V_26 * V_38 -> V_54 ) ;
F_44 ( V_5 , V_47 * V_38 -> V_54 ) ;
}
void F_48 ( struct V_2 * V_2 , struct V_97 * V_98 , int V_47 )
{
struct V_37 * V_38 ;
struct V_1 * V_5 = V_2 -> V_21 ;
unsigned int V_53 ;
if ( F_18 ( V_2 ) == 0 )
return;
V_38 = F_16 ( V_2 -> V_46 ) ;
F_14 ( V_38 == NULL ) ;
F_14 ( V_5 -> V_28 != 1 ) ;
V_53 = F_20 ( V_38 , V_47 ) ;
V_98 -> V_99 . V_21 = & V_98 -> V_100 ;
V_98 -> V_101 . V_21 = & V_98 -> V_102 ;
V_98 -> V_103 = V_5 -> V_15 [ V_5 -> V_94 ] ;
V_98 -> V_104 = V_5 -> V_15 [ V_5 -> V_94 ] ;
V_98 -> V_100 . V_15 = & V_98 -> V_103 ;
V_98 -> V_102 . V_15 = & V_98 -> V_104 ;
V_98 -> V_103 . V_32 = V_47 * V_38 -> V_54 ;
V_98 -> V_104 . V_33 += V_47 * V_38 -> V_54 ;
V_98 -> V_104 . V_32 -= V_47 * V_38 -> V_54 ;
V_98 -> V_100 . V_84 = V_2 -> V_21 -> V_84 ;
V_98 -> V_102 . V_84 = V_2 -> V_21 -> V_84 + V_53 ;
V_98 -> V_100 . V_28 = V_98 -> V_102 . V_28 = 1 ;
V_98 -> V_100 . V_94 = V_98 -> V_102 . V_94 = 0 ;
}
int F_49 ( struct V_2 * V_2 , struct V_2 * V_105 ,
T_1 V_3 )
{
struct V_1 * V_106 = V_105 -> V_21 ;
struct V_1 * V_5 ;
F_14 ( V_106 == NULL ) ;
V_5 = F_1 ( V_2 , V_3 , V_106 -> V_28 ) ;
if ( V_5 == NULL )
return - V_83 ;
memcpy ( V_5 -> V_15 , V_106 -> V_15 ,
V_106 -> V_28 * sizeof( struct V_12 ) ) ;
V_5 -> V_84 = V_106 -> V_84 ;
V_5 -> V_28 = V_106 -> V_28 ;
V_5 -> V_94 = V_106 -> V_94 ;
return 0 ;
}
int F_50 ( struct V_6 * V_7 , int V_107 )
{
if ( V_7 -> V_13 )
return 0 ;
V_7 -> V_13 = F_51 ( V_107 , V_19 ) ;
V_7 -> V_16 = F_52 ( V_7 , V_107 ) ;
if ( ! V_7 -> V_16 )
return - 1 ;
if ( ! V_7 -> V_13 )
return - 1 ;
return 0 ;
}
void F_53 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 )
F_54 ( V_7 -> V_13 ) ;
if ( V_7 -> V_16 )
F_54 ( V_7 -> V_13 ) ;
}
void T_3 F_55 ( void )
{
V_92 = F_56 ( L_5 , V_108 |
V_109 | V_110 , 1 ) ;
if ( ! V_92 )
F_57 ( L_6 ) ;
V_19 = F_58 ( L_7 ,
sizeof( struct V_1 ) +
sizeof( struct V_12 ) * V_14 ,
0 , V_111 | V_112 , NULL ) ;
if ( ! V_19 )
F_57 ( L_8 ) ;
}
