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
static inline unsigned int F_10 ( struct V_1 * V_5 )
{
if ( V_5 -> V_19 == V_10 )
return V_14 ;
return F_11 ( V_5 -> V_19 ) ;
}
int F_12 ( struct V_2 * V_2 , struct V_24 * V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_12 * V_27 ;
if ( V_5 -> V_28 >= F_10 ( V_5 ) ) {
F_13 ( V_29 L_1 , V_30 ) ;
return 0 ;
}
V_27 = V_5 -> V_15 + V_5 -> V_28 ;
V_27 -> V_31 = V_24 ;
V_27 -> V_32 = V_25 ;
V_27 -> V_33 = V_26 ;
V_5 -> V_28 ++ ;
return V_25 ;
}
static int F_14 ( struct V_34 * V_35 , int V_36 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
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
int F_16 ( struct V_2 * V_2 )
{
if ( F_17 ( V_2 ) )
return 0 ;
return F_14 ( V_2 -> V_46 , F_18 ( V_2 ) ) ;
}
static inline unsigned int F_19 ( struct V_37 * V_38 ,
unsigned int V_47 )
{
if ( V_38 -> V_48 == 4096 )
return V_47 >>= 3 ;
return V_47 ;
}
static inline unsigned int F_20 ( struct V_37 * V_38 ,
unsigned int V_47 )
{
return F_19 ( V_38 , V_47 ) * V_38 -> V_49 ;
}
unsigned int F_21 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 -> V_46 ) ;
F_22 ( V_2 -> V_50 . V_51 == 0 ) ;
return V_38 -> V_52 * ( V_2 -> V_50 . V_51 / V_38 -> V_48 ) ;
}
static int F_23 ( struct V_2 * V_2 , void * V_53 , unsigned int V_25 ,
int V_54 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_37 * V_38 = F_15 ( V_2 -> V_46 ) ;
unsigned int V_55 ;
F_22 ( V_5 -> V_23 == NULL ) ;
if ( V_38 -> V_52 == 0 )
return - 1 ;
V_55 = F_19 ( V_38 ,
F_24 ( V_25 , V_38 -> V_52 ) ) ;
if ( V_55 * V_38 -> V_49 > V_5 -> V_56 . V_51 ) {
F_13 ( V_29 L_2 , V_30 ,
V_55 * V_38 -> V_49 , V_5 -> V_56 . V_51 ) ;
return - 1 ;
}
if ( V_54 )
V_38 -> V_57 ( V_5 -> V_23 , V_53 , V_55 ) ;
else
V_38 -> V_58 ( V_5 -> V_23 , V_53 , V_55 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_2 , void * V_53 , unsigned int V_25 )
{
F_22 ( F_18 ( V_2 ) != V_43 ) ;
return F_23 ( V_2 , V_53 , V_25 , 1 ) ;
}
int F_26 ( struct V_2 * V_2 , void * V_53 , unsigned int V_25 )
{
F_22 ( F_18 ( V_2 ) != V_39 ) ;
return F_23 ( V_2 , V_53 , V_25 , 0 ) ;
}
static void F_27 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 -> V_46 ) ;
struct V_59 V_60 ;
struct V_12 V_61 ;
struct V_62 V_63 ;
T_2 V_64 = V_2 -> V_50 . V_65 ;
unsigned int V_47 , V_66 ;
void * V_67 = V_2 -> V_21 -> V_23 ;
V_66 = 0 ;
V_60 . V_68 = V_2 -> V_46 -> V_69 -> V_68 ;
V_60 . V_48 = V_38 -> V_48 ;
F_28 (bv, bio, iter) {
void * V_70 = F_29 ( V_61 . V_31 ) ;
V_60 . V_71 = V_70 + V_61 . V_33 ;
V_60 . V_72 = V_61 . V_32 ;
V_60 . V_67 = V_67 ;
V_60 . V_64 = V_64 ;
V_38 -> V_44 ( & V_60 ) ;
V_47 = V_61 . V_32 / V_38 -> V_48 ;
V_64 += V_47 ;
V_67 += V_47 * V_38 -> V_49 ;
V_66 += V_47 * V_38 -> V_49 ;
F_22 ( V_66 > V_2 -> V_21 -> V_56 . V_51 ) ;
F_30 ( V_70 ) ;
}
}
static inline unsigned short F_31 ( struct V_37 * V_38 )
{
if ( V_38 )
return V_38 -> V_49 ;
return 0 ;
}
int F_32 ( struct V_2 * V_2 )
{
struct V_1 * V_5 ;
struct V_37 * V_38 ;
struct V_73 * V_74 ;
void * V_75 ;
unsigned long V_76 , V_77 ;
unsigned int V_25 , V_78 ;
unsigned int V_79 , V_26 , V_80 ;
unsigned int V_47 ;
V_38 = F_15 ( V_2 -> V_46 ) ;
V_74 = F_33 ( V_2 -> V_46 ) ;
F_22 ( V_38 == NULL ) ;
F_22 ( F_17 ( V_2 ) ) ;
V_47 = F_19 ( V_38 , F_34 ( V_2 ) ) ;
V_25 = V_47 * F_31 ( V_38 ) ;
V_75 = F_2 ( V_25 , V_81 | V_74 -> V_82 ) ;
if ( F_4 ( V_75 == NULL ) ) {
F_13 ( V_29 L_3 ) ;
return - V_83 ;
}
V_77 = ( ( ( unsigned long ) V_75 ) + V_25 + V_84 - 1 ) >> V_85 ;
V_76 = ( ( unsigned long ) V_75 ) >> V_85 ;
V_78 = V_77 - V_76 ;
V_5 = F_1 ( V_2 , V_81 , V_78 ) ;
if ( F_4 ( V_5 == NULL ) ) {
F_13 ( V_29 L_4 ) ;
F_8 ( V_75 ) ;
return - V_86 ;
}
V_5 -> V_22 = 1 ;
V_5 -> V_23 = V_75 ;
V_5 -> V_56 . V_51 = V_25 ;
V_5 -> V_56 . V_65 = V_2 -> V_50 . V_65 ;
V_26 = F_35 ( V_75 ) ;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ ) {
int V_87 ;
V_79 = V_84 - V_26 ;
if ( V_25 <= 0 )
break;
if ( V_79 > V_25 )
V_79 = V_25 ;
V_87 = F_12 ( V_2 , F_36 ( V_75 ) ,
V_79 , V_26 ) ;
if ( V_87 == 0 )
return 0 ;
if ( V_87 < V_79 )
break;
V_75 += V_79 ;
V_25 -= V_79 ;
V_26 = 0 ;
}
if ( F_18 ( V_2 ) == V_39 ) {
V_5 -> V_88 = V_2 -> V_89 ;
V_2 -> V_89 = V_90 ;
}
if ( F_18 ( V_2 ) == V_43 )
F_27 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_15 ( V_2 -> V_46 ) ;
struct V_59 V_60 ;
struct V_12 * V_61 ;
T_2 V_64 = V_2 -> V_21 -> V_56 . V_65 ;
unsigned int V_47 , V_87 = 0 ;
void * V_67 = V_2 -> V_21 -> V_23 ;
int V_80 ;
V_60 . V_68 = V_2 -> V_46 -> V_69 -> V_68 ;
V_60 . V_48 = V_38 -> V_48 ;
F_38 (bv, bio, i) {
void * V_70 = F_29 ( V_61 -> V_31 ) ;
V_60 . V_71 = V_70 + V_61 -> V_33 ;
V_60 . V_72 = V_61 -> V_32 ;
V_60 . V_67 = V_67 ;
V_60 . V_64 = V_64 ;
V_87 = V_38 -> V_40 ( & V_60 ) ;
if ( V_87 ) {
F_30 ( V_70 ) ;
return V_87 ;
}
V_47 = V_61 -> V_32 / V_38 -> V_48 ;
V_64 += V_47 ;
V_67 += V_47 * V_38 -> V_49 ;
F_30 ( V_70 ) ;
}
return V_87 ;
}
static void F_39 ( struct V_91 * V_92 )
{
struct V_1 * V_5 =
F_40 ( V_92 , struct V_1 , V_93 ) ;
struct V_2 * V_2 = V_5 -> V_20 ;
int error ;
error = F_37 ( V_2 ) ;
V_2 -> V_89 = V_5 -> V_88 ;
F_41 ( V_2 , error ) ;
}
void V_90 ( struct V_2 * V_2 , int error )
{
struct V_1 * V_5 = V_2 -> V_21 ;
F_22 ( V_5 -> V_20 != V_2 ) ;
if ( error ) {
V_2 -> V_89 = V_5 -> V_88 ;
F_42 ( V_2 , error ) ;
return;
}
F_43 ( & V_5 -> V_93 , F_39 ) ;
F_44 ( V_94 , & V_5 -> V_93 ) ;
}
void F_45 ( struct V_2 * V_2 , unsigned int V_95 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_37 * V_38 = F_15 ( V_2 -> V_46 ) ;
unsigned V_79 = F_20 ( V_38 , V_95 >> 9 ) ;
F_46 ( V_5 -> V_15 , & V_5 -> V_56 , V_79 ) ;
}
void F_47 ( struct V_2 * V_2 , unsigned int V_26 ,
unsigned int V_47 )
{
struct V_1 * V_5 = V_2 -> V_21 ;
struct V_37 * V_38 = F_15 ( V_2 -> V_46 ) ;
F_45 ( V_2 , V_26 << 9 ) ;
V_5 -> V_56 . V_51 = F_20 ( V_38 , V_47 ) ;
}
int F_48 ( struct V_2 * V_2 , struct V_2 * V_96 ,
T_1 V_3 )
{
struct V_1 * V_97 = V_96 -> V_21 ;
struct V_1 * V_5 ;
F_22 ( V_97 == NULL ) ;
V_5 = F_1 ( V_2 , V_3 , V_97 -> V_28 ) ;
if ( V_5 == NULL )
return - V_86 ;
memcpy ( V_5 -> V_15 , V_97 -> V_15 ,
V_97 -> V_28 * sizeof( struct V_12 ) ) ;
V_5 -> V_28 = V_97 -> V_28 ;
V_5 -> V_56 = V_97 -> V_56 ;
return 0 ;
}
int F_49 ( struct V_6 * V_7 , int V_98 )
{
if ( V_7 -> V_13 )
return 0 ;
V_7 -> V_13 = F_50 ( V_98 , V_19 ) ;
if ( ! V_7 -> V_13 )
return - 1 ;
V_7 -> V_16 = F_51 ( V_7 , V_98 ) ;
if ( ! V_7 -> V_16 ) {
F_52 ( V_7 -> V_13 ) ;
return - 1 ;
}
return 0 ;
}
void F_53 ( struct V_6 * V_7 )
{
if ( V_7 -> V_13 )
F_52 ( V_7 -> V_13 ) ;
if ( V_7 -> V_16 )
F_52 ( V_7 -> V_16 ) ;
}
void T_3 F_54 ( void )
{
V_94 = F_55 ( L_5 , V_99 |
V_100 | V_101 , 1 ) ;
if ( ! V_94 )
F_56 ( L_6 ) ;
V_19 = F_57 ( L_7 ,
sizeof( struct V_1 ) +
sizeof( struct V_12 ) * V_14 ,
0 , V_102 | V_103 , NULL ) ;
if ( ! V_19 )
F_56 ( L_8 ) ;
}
