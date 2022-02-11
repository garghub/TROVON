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
V_5 -> V_18 = F_6 ( V_9 ) ;
} else {
V_5 -> V_15 = V_5 -> V_19 ;
V_5 -> V_18 = V_11 ;
}
V_5 -> V_20 = V_9 ;
V_5 -> V_21 = V_2 ;
V_2 -> V_22 = V_5 ;
return V_5 ;
V_17:
F_7 ( V_5 , V_7 -> V_13 ) ;
return NULL ;
}
void F_8 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = V_2 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_5 -> V_23 )
F_9 ( V_5 -> V_24 ) ;
if ( V_7 ) {
if ( V_5 -> V_20 != V_10 )
F_10 ( V_7 -> V_16 , V_5 -> V_15 ,
V_5 -> V_20 ) ;
F_7 ( V_5 , V_7 -> V_13 ) ;
} else {
F_9 ( V_5 ) ;
}
V_2 -> V_22 = NULL ;
}
int F_11 ( struct V_2 * V_2 , struct V_25 * V_25 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_1 * V_5 = V_2 -> V_22 ;
struct V_12 * V_28 ;
if ( V_5 -> V_29 >= V_5 -> V_18 ) {
F_12 ( V_30 L_1 , V_31 ) ;
return 0 ;
}
V_28 = V_5 -> V_15 + V_5 -> V_29 ;
V_28 -> V_32 = V_25 ;
V_28 -> V_33 = V_26 ;
V_28 -> V_34 = V_27 ;
V_5 -> V_29 ++ ;
return V_26 ;
}
static int F_13 ( struct V_35 * V_36 , int V_37 )
{
struct V_38 * V_39 = F_14 ( V_36 ) ;
if ( V_39 == NULL )
return 0 ;
if ( V_37 == V_40 && V_39 -> V_41 != NULL &&
( V_39 -> V_42 & V_43 ) )
return 1 ;
if ( V_37 == V_44 && V_39 -> V_45 != NULL &&
( V_39 -> V_42 & V_46 ) )
return 1 ;
return 0 ;
}
int F_15 ( struct V_2 * V_2 )
{
if ( ! F_16 ( V_2 ) )
return 0 ;
if ( F_17 ( V_2 ) )
return 0 ;
return F_13 ( V_2 -> V_47 , F_18 ( V_2 ) ) ;
}
static inline unsigned int F_19 ( struct V_38 * V_39 ,
unsigned int V_48 )
{
if ( V_39 -> V_49 == 4096 )
return V_48 >>= 3 ;
return V_48 ;
}
static inline unsigned int F_20 ( struct V_38 * V_39 ,
unsigned int V_48 )
{
return F_19 ( V_39 , V_48 ) * V_39 -> V_50 ;
}
unsigned int F_21 ( struct V_2 * V_2 )
{
struct V_38 * V_39 = F_14 ( V_2 -> V_47 ) ;
F_22 ( V_2 -> V_51 . V_52 == 0 ) ;
return V_39 -> V_53 * ( V_2 -> V_51 . V_52 / V_39 -> V_49 ) ;
}
static int F_23 ( struct V_2 * V_2 , void * V_54 , unsigned int V_26 ,
int V_55 )
{
struct V_1 * V_5 = V_2 -> V_22 ;
struct V_38 * V_39 = F_14 ( V_2 -> V_47 ) ;
unsigned int V_56 ;
F_22 ( V_5 -> V_24 == NULL ) ;
if ( V_39 -> V_53 == 0 )
return - 1 ;
V_56 = F_19 ( V_39 ,
F_24 ( V_26 , V_39 -> V_53 ) ) ;
if ( V_56 * V_39 -> V_50 > V_5 -> V_57 . V_52 ) {
F_12 ( V_30 L_2 , V_31 ,
V_56 * V_39 -> V_50 , V_5 -> V_57 . V_52 ) ;
return - 1 ;
}
if ( V_55 )
V_39 -> V_58 ( V_5 -> V_24 , V_54 , V_56 ) ;
else
V_39 -> V_59 ( V_5 -> V_24 , V_54 , V_56 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_2 , void * V_54 , unsigned int V_26 )
{
F_22 ( F_18 ( V_2 ) != V_44 ) ;
return F_23 ( V_2 , V_54 , V_26 , 1 ) ;
}
int F_26 ( struct V_2 * V_2 , void * V_54 , unsigned int V_26 )
{
F_22 ( F_18 ( V_2 ) != V_40 ) ;
return F_23 ( V_2 , V_54 , V_26 , 0 ) ;
}
static int F_27 ( struct V_2 * V_2 , int V_60 )
{
struct V_38 * V_39 = F_14 ( V_2 -> V_47 ) ;
struct V_61 V_62 ;
struct V_12 * V_63 ;
T_2 V_64 ;
unsigned int V_48 , V_65 = 0 , V_66 ;
void * V_67 = V_2 -> V_22 -> V_24 ;
if ( V_60 )
V_64 = V_2 -> V_51 . V_68 ;
else
V_64 = V_2 -> V_22 -> V_57 . V_68 ;
V_62 . V_69 = V_2 -> V_47 -> V_70 -> V_69 ;
V_62 . V_49 = V_39 -> V_49 ;
F_28 (bv, bio, i) {
void * V_71 = F_29 ( V_63 -> V_32 ) ;
V_62 . V_72 = V_71 + V_63 -> V_34 ;
V_62 . V_73 = V_63 -> V_33 ;
V_62 . V_67 = V_67 ;
V_62 . V_64 = V_64 ;
if ( V_60 )
V_39 -> V_45 ( & V_62 ) ;
else {
V_65 = V_39 -> V_41 ( & V_62 ) ;
if ( V_65 ) {
F_30 ( V_71 ) ;
return V_65 ;
}
}
V_48 = V_63 -> V_33 / V_39 -> V_49 ;
V_64 += V_48 ;
V_67 += V_48 * V_39 -> V_50 ;
F_30 ( V_71 ) ;
}
return V_65 ;
}
static void F_31 ( struct V_2 * V_2 )
{
F_27 ( V_2 , 1 ) ;
}
static inline unsigned short F_32 ( struct V_38 * V_39 )
{
if ( V_39 )
return V_39 -> V_50 ;
return 0 ;
}
int F_33 ( struct V_2 * V_2 )
{
struct V_1 * V_5 ;
struct V_38 * V_39 ;
struct V_74 * V_75 ;
void * V_76 ;
unsigned long V_77 , V_78 ;
unsigned int V_26 , V_79 ;
unsigned int V_80 , V_27 , V_66 ;
unsigned int V_48 ;
V_39 = F_14 ( V_2 -> V_47 ) ;
V_75 = F_34 ( V_2 -> V_47 ) ;
F_22 ( V_39 == NULL ) ;
F_22 ( F_17 ( V_2 ) ) ;
V_48 = F_19 ( V_39 , F_35 ( V_2 ) ) ;
V_26 = V_48 * F_32 ( V_39 ) ;
V_76 = F_2 ( V_26 , V_81 | V_75 -> V_82 ) ;
if ( F_4 ( V_76 == NULL ) ) {
F_12 ( V_30 L_3 ) ;
return - V_83 ;
}
V_78 = ( ( ( unsigned long ) V_76 ) + V_26 + V_84 - 1 ) >> V_85 ;
V_77 = ( ( unsigned long ) V_76 ) >> V_85 ;
V_79 = V_78 - V_77 ;
V_5 = F_1 ( V_2 , V_81 , V_79 ) ;
if ( F_4 ( V_5 == NULL ) ) {
F_12 ( V_30 L_4 ) ;
F_9 ( V_76 ) ;
return - V_86 ;
}
V_5 -> V_23 = 1 ;
V_5 -> V_24 = V_76 ;
V_5 -> V_57 . V_52 = V_26 ;
V_5 -> V_57 . V_68 = V_2 -> V_51 . V_68 ;
V_27 = F_36 ( V_76 ) ;
for ( V_66 = 0 ; V_66 < V_79 ; V_66 ++ ) {
int V_65 ;
V_80 = V_84 - V_27 ;
if ( V_26 <= 0 )
break;
if ( V_80 > V_26 )
V_80 = V_26 ;
V_65 = F_11 ( V_2 , F_37 ( V_76 ) ,
V_80 , V_27 ) ;
if ( V_65 == 0 )
return 0 ;
if ( V_65 < V_80 )
break;
V_76 += V_80 ;
V_26 -= V_80 ;
V_27 = 0 ;
}
if ( F_18 ( V_2 ) == V_40 ) {
V_5 -> V_87 = V_2 -> V_88 ;
V_2 -> V_88 = V_89 ;
}
if ( F_18 ( V_2 ) == V_44 )
F_31 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_2 )
{
return F_27 ( V_2 , 0 ) ;
}
static void F_39 ( struct V_90 * V_91 )
{
struct V_1 * V_5 =
F_40 ( V_91 , struct V_1 , V_92 ) ;
struct V_2 * V_2 = V_5 -> V_21 ;
int error ;
error = F_38 ( V_2 ) ;
V_2 -> V_88 = V_5 -> V_87 ;
F_41 ( V_2 , error ) ;
}
void V_89 ( struct V_2 * V_2 , int error )
{
struct V_1 * V_5 = V_2 -> V_22 ;
F_22 ( V_5 -> V_21 != V_2 ) ;
if ( error ) {
V_2 -> V_88 = V_5 -> V_87 ;
F_41 ( V_2 , error ) ;
return;
}
F_42 ( & V_5 -> V_92 , F_39 ) ;
F_43 ( V_93 , & V_5 -> V_92 ) ;
}
void F_44 ( struct V_2 * V_2 , unsigned int V_94 )
{
struct V_1 * V_5 = V_2 -> V_22 ;
struct V_38 * V_39 = F_14 ( V_2 -> V_47 ) ;
unsigned V_80 = F_20 ( V_39 , V_94 >> 9 ) ;
F_45 ( V_5 -> V_15 , & V_5 -> V_57 , V_80 ) ;
}
void F_46 ( struct V_2 * V_2 , unsigned int V_27 ,
unsigned int V_48 )
{
struct V_1 * V_5 = V_2 -> V_22 ;
struct V_38 * V_39 = F_14 ( V_2 -> V_47 ) ;
F_44 ( V_2 , V_27 << 9 ) ;
V_5 -> V_57 . V_52 = F_20 ( V_39 , V_48 ) ;
}
int F_47 ( struct V_2 * V_2 , struct V_2 * V_95 ,
T_1 V_3 )
{
struct V_1 * V_96 = V_95 -> V_22 ;
struct V_1 * V_5 ;
F_22 ( V_96 == NULL ) ;
V_5 = F_1 ( V_2 , V_3 , V_96 -> V_29 ) ;
if ( V_5 == NULL )
return - V_86 ;
memcpy ( V_5 -> V_15 , V_96 -> V_15 ,
V_96 -> V_29 * sizeof( struct V_12 ) ) ;
V_5 -> V_29 = V_96 -> V_29 ;
V_5 -> V_57 = V_96 -> V_57 ;
return 0 ;
}
int F_48 ( struct V_6 * V_7 , int V_97 )
{
if ( V_7 -> V_13 )
return 0 ;
V_7 -> V_13 = F_49 ( V_97 , V_20 ) ;
if ( ! V_7 -> V_13 )
return - 1 ;
V_7 -> V_16 = F_50 ( V_97 ) ;
if ( ! V_7 -> V_16 ) {
F_51 ( V_7 -> V_13 ) ;
return - 1 ;
}
return 0 ;
}
void F_52 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 )
F_51 ( V_7 -> V_13 ) ;
if ( V_7 -> V_16 )
F_51 ( V_7 -> V_16 ) ;
}
void T_3 F_53 ( void )
{
V_93 = F_54 ( L_5 , V_98 |
V_99 | V_100 , 1 ) ;
if ( ! V_93 )
F_55 ( L_6 ) ;
V_20 = F_56 ( L_7 ,
sizeof( struct V_1 ) +
sizeof( struct V_12 ) * V_14 ,
0 , V_101 | V_102 , NULL ) ;
if ( ! V_20 )
F_55 ( L_8 ) ;
}
