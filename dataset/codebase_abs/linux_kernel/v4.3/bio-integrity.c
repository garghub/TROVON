struct V_1 * F_1 ( struct V_2 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_10 ;
unsigned V_11 ;
if ( ! V_7 || ! V_7 -> V_12 ) {
V_5 = F_2 ( sizeof( struct V_1 ) +
sizeof( struct V_13 ) * V_4 , V_3 ) ;
V_11 = V_4 ;
} else {
V_5 = F_3 ( V_7 -> V_12 , V_3 ) ;
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
V_2 -> V_23 |= V_24 ;
return V_5 ;
V_17:
F_7 ( V_5 , V_7 -> V_12 ) ;
return NULL ;
}
void F_8 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_9 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_5 -> V_25 & V_26 )
F_10 ( F_11 ( V_5 -> V_15 -> V_27 ) +
V_5 -> V_15 -> V_28 ) ;
if ( V_7 && V_7 -> V_12 ) {
if ( V_5 -> V_20 != V_10 )
F_12 ( V_7 -> V_16 , V_5 -> V_15 ,
V_5 -> V_20 ) ;
F_7 ( V_5 , V_7 -> V_12 ) ;
} else {
F_10 ( V_5 ) ;
}
V_2 -> V_22 = NULL ;
}
int F_13 ( struct V_2 * V_2 , struct V_29 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_1 * V_5 = F_9 ( V_2 ) ;
struct V_13 * V_32 ;
if ( V_5 -> V_33 >= V_5 -> V_18 ) {
F_14 ( V_34 L_1 , V_35 ) ;
return 0 ;
}
V_32 = V_5 -> V_15 + V_5 -> V_33 ;
if ( V_5 -> V_33 &&
F_15 ( F_16 ( V_2 -> V_36 ) ,
& V_5 -> V_15 [ V_5 -> V_33 - 1 ] , V_31 ) )
return 0 ;
V_32 -> V_27 = V_29 ;
V_32 -> V_37 = V_30 ;
V_32 -> V_28 = V_31 ;
V_5 -> V_33 ++ ;
return V_30 ;
}
bool F_17 ( struct V_2 * V_2 )
{
struct V_38 * V_39 = F_18 ( V_2 -> V_36 ) ;
if ( ! F_19 ( V_2 ) )
return false ;
if ( F_9 ( V_2 ) )
return false ;
if ( V_39 == NULL )
return false ;
if ( F_20 ( V_2 ) == V_40 && V_39 -> V_41 != NULL &&
( V_39 -> V_42 & V_43 ) )
return true ;
if ( F_20 ( V_2 ) == V_44 && V_39 -> V_45 != NULL &&
( V_39 -> V_42 & V_46 ) )
return true ;
return false ;
}
static inline unsigned int F_21 ( struct V_38 * V_39 ,
unsigned int V_47 )
{
return V_47 >> ( F_22 ( V_39 -> V_48 ) - 9 ) ;
}
static inline unsigned int F_23 ( struct V_38 * V_39 ,
unsigned int V_47 )
{
return F_21 ( V_39 , V_47 ) * V_39 -> V_49 ;
}
static int F_24 ( struct V_2 * V_2 ,
T_2 * V_50 )
{
struct V_38 * V_39 = F_18 ( V_2 -> V_36 ) ;
struct V_51 V_52 ;
struct V_53 V_54 ;
struct V_13 V_55 ;
struct V_1 * V_5 = F_9 ( V_2 ) ;
unsigned int V_56 = 0 ;
void * V_57 = F_11 ( V_5 -> V_15 -> V_27 ) +
V_5 -> V_15 -> V_28 ;
V_52 . V_58 = V_2 -> V_36 -> V_59 -> V_58 ;
V_52 . V_48 = V_39 -> V_48 ;
V_52 . V_60 = F_25 ( V_5 ) ;
V_52 . V_57 = V_57 ;
F_26 (bv, bio, bviter) {
void * V_61 = F_27 ( V_55 . V_27 ) ;
V_52 . V_62 = V_61 + V_55 . V_28 ;
V_52 . V_63 = V_55 . V_37 ;
V_56 = V_50 ( & V_52 ) ;
if ( V_56 ) {
F_28 ( V_61 ) ;
return V_56 ;
}
F_28 ( V_61 ) ;
}
return V_56 ;
}
int F_29 ( struct V_2 * V_2 )
{
struct V_1 * V_5 ;
struct V_38 * V_39 ;
struct V_64 * V_65 ;
void * V_66 ;
unsigned long V_67 , V_68 ;
unsigned int V_30 , V_69 ;
unsigned int V_70 , V_31 , V_71 ;
unsigned int V_72 ;
V_39 = F_18 ( V_2 -> V_36 ) ;
V_65 = F_16 ( V_2 -> V_36 ) ;
F_30 ( V_39 == NULL ) ;
F_30 ( F_9 ( V_2 ) ) ;
V_72 = F_21 ( V_39 , F_31 ( V_2 ) ) ;
V_30 = V_72 * V_39 -> V_49 ;
V_66 = F_2 ( V_30 , V_73 | V_65 -> V_74 ) ;
if ( F_4 ( V_66 == NULL ) ) {
F_14 ( V_34 L_2 ) ;
return - V_75 ;
}
V_68 = ( ( ( unsigned long ) V_66 ) + V_30 + V_76 - 1 ) >> V_77 ;
V_67 = ( ( unsigned long ) V_66 ) >> V_77 ;
V_69 = V_68 - V_67 ;
V_5 = F_1 ( V_2 , V_73 , V_69 ) ;
if ( F_4 ( V_5 == NULL ) ) {
F_14 ( V_34 L_3 ) ;
F_10 ( V_66 ) ;
return - V_78 ;
}
V_5 -> V_25 |= V_26 ;
V_5 -> V_79 . V_80 = V_30 ;
F_32 ( V_5 , V_2 -> V_81 . V_82 ) ;
if ( V_39 -> V_42 & V_83 )
V_5 -> V_25 |= V_84 ;
V_31 = F_33 ( V_66 ) ;
for ( V_71 = 0 ; V_71 < V_69 ; V_71 ++ ) {
int V_56 ;
V_70 = V_76 - V_31 ;
if ( V_30 <= 0 )
break;
if ( V_70 > V_30 )
V_70 = V_30 ;
V_56 = F_13 ( V_2 , F_34 ( V_66 ) ,
V_70 , V_31 ) ;
if ( V_56 == 0 )
return 0 ;
if ( V_56 < V_70 )
break;
V_66 += V_70 ;
V_30 -= V_70 ;
V_31 = 0 ;
}
if ( F_20 ( V_2 ) == V_40 ) {
V_5 -> V_85 = V_2 -> V_86 ;
V_2 -> V_86 = V_87 ;
}
if ( F_20 ( V_2 ) == V_44 )
F_24 ( V_2 , V_39 -> V_45 ) ;
return 0 ;
}
static void F_35 ( struct V_88 * V_89 )
{
struct V_1 * V_5 =
F_36 ( V_89 , struct V_1 , V_90 ) ;
struct V_2 * V_2 = V_5 -> V_21 ;
struct V_38 * V_39 = F_18 ( V_2 -> V_36 ) ;
V_2 -> V_91 = F_24 ( V_2 , V_39 -> V_41 ) ;
V_2 -> V_86 = V_5 -> V_85 ;
F_37 ( V_2 ) ;
}
void V_87 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_9 ( V_2 ) ;
F_30 ( V_5 -> V_21 != V_2 ) ;
if ( V_2 -> V_91 ) {
V_2 -> V_86 = V_5 -> V_85 ;
F_37 ( V_2 ) ;
return;
}
F_38 ( & V_5 -> V_90 , F_35 ) ;
F_39 ( V_92 , & V_5 -> V_90 ) ;
}
void F_40 ( struct V_2 * V_2 , unsigned int V_93 )
{
struct V_1 * V_5 = F_9 ( V_2 ) ;
struct V_38 * V_39 = F_18 ( V_2 -> V_36 ) ;
unsigned V_70 = F_23 ( V_39 , V_93 >> 9 ) ;
F_41 ( V_5 -> V_15 , & V_5 -> V_79 , V_70 ) ;
}
void F_42 ( struct V_2 * V_2 , unsigned int V_31 ,
unsigned int V_47 )
{
struct V_1 * V_5 = F_9 ( V_2 ) ;
struct V_38 * V_39 = F_18 ( V_2 -> V_36 ) ;
F_40 ( V_2 , V_31 << 9 ) ;
V_5 -> V_79 . V_80 = F_23 ( V_39 , V_47 ) ;
}
int F_43 ( struct V_2 * V_2 , struct V_2 * V_94 ,
T_1 V_3 )
{
struct V_1 * V_95 = F_9 ( V_94 ) ;
struct V_1 * V_5 ;
F_30 ( V_95 == NULL ) ;
V_5 = F_1 ( V_2 , V_3 , V_95 -> V_33 ) ;
if ( V_5 == NULL )
return - V_78 ;
memcpy ( V_5 -> V_15 , V_95 -> V_15 ,
V_95 -> V_33 * sizeof( struct V_13 ) ) ;
V_5 -> V_33 = V_95 -> V_33 ;
V_5 -> V_79 = V_95 -> V_79 ;
return 0 ;
}
int F_44 ( struct V_6 * V_7 , int V_96 )
{
if ( V_7 -> V_12 )
return 0 ;
V_7 -> V_12 = F_45 ( V_96 , V_20 ) ;
if ( ! V_7 -> V_12 )
return - 1 ;
V_7 -> V_16 = F_46 ( V_96 ) ;
if ( ! V_7 -> V_16 ) {
F_47 ( V_7 -> V_12 ) ;
return - 1 ;
}
return 0 ;
}
void F_48 ( struct V_6 * V_7 )
{
if ( V_7 -> V_12 )
F_47 ( V_7 -> V_12 ) ;
if ( V_7 -> V_16 )
F_47 ( V_7 -> V_16 ) ;
}
void T_3 F_49 ( void )
{
V_92 = F_50 ( L_4 , V_97 |
V_98 | V_99 , 1 ) ;
if ( ! V_92 )
F_51 ( L_5 ) ;
V_20 = F_52 ( L_6 ,
sizeof( struct V_1 ) +
sizeof( struct V_13 ) * V_14 ,
0 , V_100 | V_101 , NULL ) ;
}
