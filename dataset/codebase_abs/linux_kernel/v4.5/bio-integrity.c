void F_1 ( void )
{
F_2 ( V_1 ) ;
}
struct V_2 * F_3 ( struct V_3 * V_3 ,
T_1 V_4 ,
unsigned int V_5 )
{
struct V_2 * V_6 ;
struct V_7 * V_8 = V_3 -> V_9 ;
unsigned long V_10 = V_11 ;
unsigned V_12 ;
if ( ! V_8 || ! V_8 -> V_13 ) {
V_6 = F_4 ( sizeof( struct V_2 ) +
sizeof( struct V_14 ) * V_5 , V_4 ) ;
V_12 = V_5 ;
} else {
V_6 = F_5 ( V_8 -> V_13 , V_4 ) ;
V_12 = V_15 ;
}
if ( F_6 ( ! V_6 ) )
return F_7 ( - V_16 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
if ( V_5 > V_12 ) {
V_6 -> V_17 = F_8 ( V_4 , V_5 , & V_10 ,
V_8 -> V_18 ) ;
if ( ! V_6 -> V_17 )
goto V_19;
V_6 -> V_20 = F_9 ( V_10 ) ;
} else {
V_6 -> V_17 = V_6 -> V_21 ;
V_6 -> V_20 = V_12 ;
}
V_6 -> V_22 = V_10 ;
V_6 -> V_23 = V_3 ;
V_3 -> V_24 = V_6 ;
V_3 -> V_25 |= V_26 ;
return V_6 ;
V_19:
F_10 ( V_6 , V_8 -> V_13 ) ;
return F_7 ( - V_16 ) ;
}
void F_11 ( struct V_3 * V_3 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_9 ;
if ( V_6 -> V_27 & V_28 )
F_13 ( F_14 ( V_6 -> V_17 -> V_29 ) +
V_6 -> V_17 -> V_30 ) ;
if ( V_8 && V_8 -> V_13 ) {
if ( V_6 -> V_22 != V_11 )
F_15 ( V_8 -> V_18 , V_6 -> V_17 ,
V_6 -> V_22 ) ;
F_10 ( V_6 , V_8 -> V_13 ) ;
} else {
F_13 ( V_6 ) ;
}
V_3 -> V_24 = NULL ;
}
int F_16 ( struct V_3 * V_3 , struct V_31 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_14 * V_34 ;
if ( V_6 -> V_35 >= V_6 -> V_20 ) {
F_17 ( V_36 L_1 , V_37 ) ;
return 0 ;
}
V_34 = V_6 -> V_17 + V_6 -> V_35 ;
if ( V_6 -> V_35 &&
F_18 ( F_19 ( V_3 -> V_38 ) ,
& V_6 -> V_17 [ V_6 -> V_35 - 1 ] , V_33 ) )
return 0 ;
V_34 -> V_29 = V_31 ;
V_34 -> V_39 = V_32 ;
V_34 -> V_30 = V_33 ;
V_6 -> V_35 ++ ;
return V_32 ;
}
bool F_20 ( struct V_3 * V_3 )
{
struct V_40 * V_41 = F_21 ( V_3 -> V_38 ) ;
if ( ! F_22 ( V_3 ) )
return false ;
if ( F_12 ( V_3 ) )
return false ;
if ( V_41 == NULL )
return false ;
if ( F_23 ( V_3 ) == V_42 && V_41 -> V_43 -> V_44 != NULL &&
( V_41 -> V_45 & V_46 ) )
return true ;
if ( F_23 ( V_3 ) == V_47 && V_41 -> V_43 -> V_48 != NULL &&
( V_41 -> V_45 & V_49 ) )
return true ;
return false ;
}
static inline unsigned int F_24 ( struct V_40 * V_41 ,
unsigned int V_50 )
{
return V_50 >> ( V_41 -> V_51 - 9 ) ;
}
static inline unsigned int F_25 ( struct V_40 * V_41 ,
unsigned int V_50 )
{
return F_24 ( V_41 , V_50 ) * V_41 -> V_52 ;
}
static int F_26 ( struct V_3 * V_3 ,
T_2 * V_53 )
{
struct V_40 * V_41 = F_21 ( V_3 -> V_38 ) ;
struct V_54 V_55 ;
struct V_56 V_57 ;
struct V_14 V_58 ;
struct V_2 * V_6 = F_12 ( V_3 ) ;
unsigned int V_59 = 0 ;
void * V_60 = F_14 ( V_6 -> V_17 -> V_29 ) +
V_6 -> V_17 -> V_30 ;
V_55 . V_61 = V_3 -> V_38 -> V_62 -> V_61 ;
V_55 . V_63 = 1 << V_41 -> V_51 ;
V_55 . V_64 = F_27 ( V_6 ) ;
V_55 . V_60 = V_60 ;
F_28 (bv, bio, bviter) {
void * V_65 = F_29 ( V_58 . V_29 ) ;
V_55 . V_66 = V_65 + V_58 . V_30 ;
V_55 . V_67 = V_58 . V_39 ;
V_59 = V_53 ( & V_55 ) ;
if ( V_59 ) {
F_30 ( V_65 ) ;
return V_59 ;
}
F_30 ( V_65 ) ;
}
return V_59 ;
}
int F_31 ( struct V_3 * V_3 )
{
struct V_2 * V_6 ;
struct V_40 * V_41 ;
struct V_68 * V_69 ;
void * V_70 ;
unsigned long V_71 , V_72 ;
unsigned int V_32 , V_73 ;
unsigned int V_74 , V_33 , V_75 ;
unsigned int V_76 ;
V_41 = F_21 ( V_3 -> V_38 ) ;
V_69 = F_19 ( V_3 -> V_38 ) ;
F_32 ( V_41 == NULL ) ;
F_32 ( F_12 ( V_3 ) ) ;
V_76 = F_24 ( V_41 , F_33 ( V_3 ) ) ;
V_32 = V_76 * V_41 -> V_52 ;
V_70 = F_4 ( V_32 , V_77 | V_69 -> V_78 ) ;
if ( F_6 ( V_70 == NULL ) ) {
F_17 ( V_36 L_2 ) ;
return - V_16 ;
}
V_72 = ( ( ( unsigned long ) V_70 ) + V_32 + V_79 - 1 ) >> V_80 ;
V_71 = ( ( unsigned long ) V_70 ) >> V_80 ;
V_73 = V_72 - V_71 ;
V_6 = F_3 ( V_3 , V_77 , V_73 ) ;
if ( F_34 ( V_6 ) ) {
F_17 ( V_36 L_3 ) ;
F_13 ( V_70 ) ;
return F_35 ( V_6 ) ;
}
V_6 -> V_27 |= V_28 ;
V_6 -> V_81 . V_82 = V_32 ;
F_36 ( V_6 , V_3 -> V_83 . V_84 ) ;
if ( V_41 -> V_45 & V_85 )
V_6 -> V_27 |= V_86 ;
V_33 = F_37 ( V_70 ) ;
for ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ ) {
int V_59 ;
V_74 = V_79 - V_33 ;
if ( V_32 <= 0 )
break;
if ( V_74 > V_32 )
V_74 = V_32 ;
V_59 = F_16 ( V_3 , F_38 ( V_70 ) ,
V_74 , V_33 ) ;
if ( V_59 == 0 )
return 0 ;
if ( V_59 < V_74 )
break;
V_70 += V_74 ;
V_32 -= V_74 ;
V_33 = 0 ;
}
if ( F_23 ( V_3 ) == V_42 ) {
V_6 -> V_87 = V_3 -> V_88 ;
V_3 -> V_88 = V_89 ;
}
if ( F_23 ( V_3 ) == V_47 )
F_26 ( V_3 , V_41 -> V_43 -> V_48 ) ;
return 0 ;
}
static void F_39 ( struct V_90 * V_91 )
{
struct V_2 * V_6 =
F_40 ( V_91 , struct V_2 , V_92 ) ;
struct V_3 * V_3 = V_6 -> V_23 ;
struct V_40 * V_41 = F_21 ( V_3 -> V_38 ) ;
V_3 -> V_93 = F_26 ( V_3 , V_41 -> V_43 -> V_44 ) ;
V_3 -> V_88 = V_6 -> V_87 ;
F_41 ( V_3 ) ;
}
void V_89 ( struct V_3 * V_3 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
F_32 ( V_6 -> V_23 != V_3 ) ;
if ( V_3 -> V_93 ) {
V_3 -> V_88 = V_6 -> V_87 ;
F_41 ( V_3 ) ;
return;
}
F_42 ( & V_6 -> V_92 , F_39 ) ;
F_43 ( V_1 , & V_6 -> V_92 ) ;
}
void F_44 ( struct V_3 * V_3 , unsigned int V_94 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_40 * V_41 = F_21 ( V_3 -> V_38 ) ;
unsigned V_74 = F_25 ( V_41 , V_94 >> 9 ) ;
F_45 ( V_6 -> V_17 , & V_6 -> V_81 , V_74 ) ;
}
void F_46 ( struct V_3 * V_3 , unsigned int V_33 ,
unsigned int V_50 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_40 * V_41 = F_21 ( V_3 -> V_38 ) ;
F_44 ( V_3 , V_33 << 9 ) ;
V_6 -> V_81 . V_82 = F_25 ( V_41 , V_50 ) ;
}
int F_47 ( struct V_3 * V_3 , struct V_3 * V_95 ,
T_1 V_4 )
{
struct V_2 * V_96 = F_12 ( V_95 ) ;
struct V_2 * V_6 ;
F_32 ( V_96 == NULL ) ;
V_6 = F_3 ( V_3 , V_4 , V_96 -> V_35 ) ;
if ( F_34 ( V_6 ) )
return F_35 ( V_6 ) ;
memcpy ( V_6 -> V_17 , V_96 -> V_17 ,
V_96 -> V_35 * sizeof( struct V_14 ) ) ;
V_6 -> V_35 = V_96 -> V_35 ;
V_6 -> V_81 = V_96 -> V_81 ;
return 0 ;
}
int F_48 ( struct V_7 * V_8 , int V_97 )
{
if ( V_8 -> V_13 )
return 0 ;
V_8 -> V_13 = F_49 ( V_97 , V_22 ) ;
if ( ! V_8 -> V_13 )
return - 1 ;
V_8 -> V_18 = F_50 ( V_97 ) ;
if ( ! V_8 -> V_18 ) {
F_51 ( V_8 -> V_13 ) ;
return - 1 ;
}
return 0 ;
}
void F_52 ( struct V_7 * V_8 )
{
if ( V_8 -> V_13 )
F_51 ( V_8 -> V_13 ) ;
if ( V_8 -> V_18 )
F_51 ( V_8 -> V_18 ) ;
}
void T_3 F_53 ( void )
{
V_1 = F_54 ( L_4 , V_98 |
V_99 | V_100 , 1 ) ;
if ( ! V_1 )
F_55 ( L_5 ) ;
V_22 = F_56 ( L_6 ,
sizeof( struct V_2 ) +
sizeof( struct V_14 ) * V_15 ,
0 , V_101 | V_102 , NULL ) ;
}
