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
unsigned V_10 ;
if ( ! V_8 || ! V_8 -> V_11 ) {
V_6 = F_4 ( sizeof( struct V_2 ) +
sizeof( struct V_12 ) * V_5 , V_4 ) ;
V_10 = V_5 ;
} else {
V_6 = F_5 ( V_8 -> V_11 , V_4 ) ;
V_10 = V_13 ;
}
if ( F_6 ( ! V_6 ) )
return F_7 ( - V_14 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
if ( V_5 > V_10 ) {
unsigned long V_15 = 0 ;
V_6 -> V_16 = F_8 ( V_4 , V_5 , & V_15 ,
V_8 -> V_17 ) ;
if ( ! V_6 -> V_16 )
goto V_18;
V_6 -> V_19 = F_9 ( V_15 ) ;
V_6 -> V_20 = V_15 ;
} else {
V_6 -> V_16 = V_6 -> V_21 ;
V_6 -> V_19 = V_10 ;
}
V_6 -> V_22 = V_3 ;
V_3 -> V_23 = V_6 ;
V_3 -> V_24 |= V_25 ;
return V_6 ;
V_18:
F_10 ( V_6 , V_8 -> V_11 ) ;
return F_7 ( - V_14 ) ;
}
void F_11 ( struct V_3 * V_3 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_9 ;
if ( V_6 -> V_26 & V_27 )
F_13 ( F_14 ( V_6 -> V_16 -> V_28 ) +
V_6 -> V_16 -> V_29 ) ;
if ( V_8 && V_8 -> V_11 ) {
F_15 ( V_8 -> V_17 , V_6 -> V_16 , V_6 -> V_20 ) ;
F_10 ( V_6 , V_8 -> V_11 ) ;
} else {
F_13 ( V_6 ) ;
}
V_3 -> V_23 = NULL ;
}
int F_16 ( struct V_3 * V_3 , struct V_30 * V_30 ,
unsigned int V_31 , unsigned int V_32 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_12 * V_33 ;
if ( V_6 -> V_34 >= V_6 -> V_19 ) {
F_17 ( V_35 L_1 , V_36 ) ;
return 0 ;
}
V_33 = V_6 -> V_16 + V_6 -> V_34 ;
if ( V_6 -> V_34 &&
F_18 ( F_19 ( V_3 -> V_37 ) ,
& V_6 -> V_16 [ V_6 -> V_34 - 1 ] , V_32 ) )
return 0 ;
V_33 -> V_28 = V_30 ;
V_33 -> V_38 = V_31 ;
V_33 -> V_29 = V_32 ;
V_6 -> V_34 ++ ;
return V_31 ;
}
bool F_20 ( struct V_3 * V_3 )
{
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
if ( F_22 ( V_3 ) != V_41 && F_22 ( V_3 ) != V_42 )
return false ;
if ( F_12 ( V_3 ) )
return false ;
if ( V_40 == NULL )
return false ;
if ( F_23 ( V_3 ) == V_43 && V_40 -> V_44 -> V_45 != NULL &&
( V_40 -> V_46 & V_47 ) )
return true ;
if ( F_23 ( V_3 ) == V_48 && V_40 -> V_44 -> V_49 != NULL &&
( V_40 -> V_46 & V_50 ) )
return true ;
return false ;
}
static inline unsigned int F_24 ( struct V_39 * V_40 ,
unsigned int V_51 )
{
return V_51 >> ( V_40 -> V_52 - 9 ) ;
}
static inline unsigned int F_25 ( struct V_39 * V_40 ,
unsigned int V_51 )
{
return F_24 ( V_40 , V_51 ) * V_40 -> V_53 ;
}
static int F_26 ( struct V_3 * V_3 ,
T_2 * V_54 )
{
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
struct V_55 V_56 ;
struct V_57 V_58 ;
struct V_12 V_59 ;
struct V_2 * V_6 = F_12 ( V_3 ) ;
unsigned int V_60 = 0 ;
void * V_61 = F_14 ( V_6 -> V_16 -> V_28 ) +
V_6 -> V_16 -> V_29 ;
V_56 . V_62 = V_3 -> V_37 -> V_63 -> V_62 ;
V_56 . V_64 = 1 << V_40 -> V_52 ;
V_56 . V_65 = F_27 ( V_6 ) ;
V_56 . V_61 = V_61 ;
F_28 (bv, bio, bviter) {
void * V_66 = F_29 ( V_59 . V_28 ) ;
V_56 . V_67 = V_66 + V_59 . V_29 ;
V_56 . V_68 = V_59 . V_38 ;
V_60 = V_54 ( & V_56 ) ;
if ( V_60 ) {
F_30 ( V_66 ) ;
return V_60 ;
}
F_30 ( V_66 ) ;
}
return V_60 ;
}
int F_31 ( struct V_3 * V_3 )
{
struct V_2 * V_6 ;
struct V_39 * V_40 ;
struct V_69 * V_70 ;
void * V_71 ;
unsigned long V_72 , V_73 ;
unsigned int V_31 , V_74 ;
unsigned int V_75 , V_32 , V_76 ;
unsigned int V_77 ;
V_40 = F_21 ( V_3 -> V_37 ) ;
V_70 = F_19 ( V_3 -> V_37 ) ;
F_32 ( V_40 == NULL ) ;
F_32 ( F_12 ( V_3 ) ) ;
V_77 = F_24 ( V_40 , F_33 ( V_3 ) ) ;
V_31 = V_77 * V_40 -> V_53 ;
V_71 = F_4 ( V_31 , V_78 | V_70 -> V_79 ) ;
if ( F_6 ( V_71 == NULL ) ) {
F_17 ( V_35 L_2 ) ;
return - V_14 ;
}
V_73 = ( ( ( unsigned long ) V_71 ) + V_31 + V_80 - 1 ) >> V_81 ;
V_72 = ( ( unsigned long ) V_71 ) >> V_81 ;
V_74 = V_73 - V_72 ;
V_6 = F_3 ( V_3 , V_78 , V_74 ) ;
if ( F_34 ( V_6 ) ) {
F_17 ( V_35 L_3 ) ;
F_13 ( V_71 ) ;
return F_35 ( V_6 ) ;
}
V_6 -> V_26 |= V_27 ;
V_6 -> V_82 . V_83 = V_31 ;
F_36 ( V_6 , V_3 -> V_84 . V_85 ) ;
if ( V_40 -> V_46 & V_86 )
V_6 -> V_26 |= V_87 ;
V_32 = F_37 ( V_71 ) ;
for ( V_76 = 0 ; V_76 < V_74 ; V_76 ++ ) {
int V_60 ;
V_75 = V_80 - V_32 ;
if ( V_31 <= 0 )
break;
if ( V_75 > V_31 )
V_75 = V_31 ;
V_60 = F_16 ( V_3 , F_38 ( V_71 ) ,
V_75 , V_32 ) ;
if ( V_60 == 0 )
return 0 ;
if ( V_60 < V_75 )
break;
V_71 += V_75 ;
V_31 -= V_75 ;
V_32 = 0 ;
}
if ( F_23 ( V_3 ) == V_43 ) {
V_6 -> V_88 = V_3 -> V_89 ;
V_3 -> V_89 = V_90 ;
}
if ( F_23 ( V_3 ) == V_48 )
F_26 ( V_3 , V_40 -> V_44 -> V_49 ) ;
return 0 ;
}
static void F_39 ( struct V_91 * V_92 )
{
struct V_2 * V_6 =
F_40 ( V_92 , struct V_2 , V_93 ) ;
struct V_3 * V_3 = V_6 -> V_22 ;
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
V_3 -> V_94 = F_26 ( V_3 , V_40 -> V_44 -> V_45 ) ;
V_3 -> V_89 = V_6 -> V_88 ;
F_41 ( V_3 ) ;
}
void V_90 ( struct V_3 * V_3 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
F_32 ( V_6 -> V_22 != V_3 ) ;
if ( V_3 -> V_94 ) {
V_3 -> V_89 = V_6 -> V_88 ;
F_41 ( V_3 ) ;
return;
}
F_42 ( & V_6 -> V_93 , F_39 ) ;
F_43 ( V_1 , & V_6 -> V_93 ) ;
}
void F_44 ( struct V_3 * V_3 , unsigned int V_95 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
unsigned V_75 = F_25 ( V_40 , V_95 >> 9 ) ;
F_45 ( V_6 -> V_16 , & V_6 -> V_82 , V_75 ) ;
}
void F_46 ( struct V_3 * V_3 , unsigned int V_32 ,
unsigned int V_51 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
F_44 ( V_3 , V_32 << 9 ) ;
V_6 -> V_82 . V_83 = F_25 ( V_40 , V_51 ) ;
}
int F_47 ( struct V_3 * V_3 , struct V_3 * V_96 ,
T_1 V_4 )
{
struct V_2 * V_97 = F_12 ( V_96 ) ;
struct V_2 * V_6 ;
F_32 ( V_97 == NULL ) ;
V_6 = F_3 ( V_3 , V_4 , V_97 -> V_34 ) ;
if ( F_34 ( V_6 ) )
return F_35 ( V_6 ) ;
memcpy ( V_6 -> V_16 , V_97 -> V_16 ,
V_97 -> V_34 * sizeof( struct V_12 ) ) ;
V_6 -> V_34 = V_97 -> V_34 ;
V_6 -> V_82 = V_97 -> V_82 ;
return 0 ;
}
int F_48 ( struct V_7 * V_8 , int V_98 )
{
if ( V_8 -> V_11 )
return 0 ;
V_8 -> V_11 = F_49 ( V_98 , V_20 ) ;
if ( ! V_8 -> V_11 )
return - 1 ;
V_8 -> V_17 = F_50 ( V_98 ) ;
if ( ! V_8 -> V_17 ) {
F_51 ( V_8 -> V_11 ) ;
return - 1 ;
}
return 0 ;
}
void F_52 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 )
F_51 ( V_8 -> V_11 ) ;
if ( V_8 -> V_17 )
F_51 ( V_8 -> V_17 ) ;
}
void T_3 F_53 ( void )
{
V_1 = F_54 ( L_4 , V_99 |
V_100 | V_101 , 1 ) ;
if ( ! V_1 )
F_55 ( L_5 ) ;
V_20 = F_56 ( L_6 ,
sizeof( struct V_2 ) +
sizeof( struct V_12 ) * V_13 ,
0 , V_102 | V_103 , NULL ) ;
}
