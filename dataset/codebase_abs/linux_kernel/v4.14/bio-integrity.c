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
static void F_11 ( struct V_3 * V_3 )
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
V_3 -> V_24 &= ~ V_25 ;
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
F_18 ( V_3 -> V_37 -> V_38 ,
& V_6 -> V_16 [ V_6 -> V_34 - 1 ] , V_32 ) )
return 0 ;
V_33 -> V_28 = V_30 ;
V_33 -> V_39 = V_31 ;
V_33 -> V_29 = V_32 ;
V_6 -> V_34 ++ ;
return V_31 ;
}
static inline unsigned int F_19 ( struct V_40 * V_41 ,
unsigned int V_42 )
{
return V_42 >> ( V_41 -> V_43 - 9 ) ;
}
static inline unsigned int F_20 ( struct V_40 * V_41 ,
unsigned int V_42 )
{
return F_19 ( V_41 , V_42 ) * V_41 -> V_44 ;
}
static T_2 F_21 ( struct V_3 * V_3 ,
struct V_45 * V_46 , T_3 * V_47 )
{
struct V_40 * V_41 = F_22 ( V_3 -> V_37 ) ;
struct V_48 V_49 ;
struct V_45 V_50 ;
struct V_12 V_51 ;
struct V_2 * V_6 = F_12 ( V_3 ) ;
T_2 V_52 = V_53 ;
void * V_54 = F_14 ( V_6 -> V_16 -> V_28 ) +
V_6 -> V_16 -> V_29 ;
V_49 . V_55 = V_3 -> V_37 -> V_55 ;
V_49 . V_56 = 1 << V_41 -> V_43 ;
V_49 . V_57 = V_46 -> V_58 ;
V_49 . V_54 = V_54 ;
F_23 (bv, bio, bviter, *proc_iter) {
void * V_59 = F_24 ( V_51 . V_28 ) ;
V_49 . V_60 = V_59 + V_51 . V_29 ;
V_49 . V_61 = V_51 . V_39 ;
V_52 = V_47 ( & V_49 ) ;
if ( V_52 ) {
F_25 ( V_59 ) ;
return V_52 ;
}
F_25 ( V_59 ) ;
}
return V_52 ;
}
bool F_26 ( struct V_3 * V_3 )
{
struct V_2 * V_6 ;
struct V_40 * V_41 = F_22 ( V_3 -> V_37 ) ;
struct V_62 * V_63 = V_3 -> V_37 -> V_38 ;
void * V_64 ;
unsigned long V_65 , V_66 ;
unsigned int V_31 , V_67 ;
unsigned int V_68 , V_32 , V_69 ;
unsigned int V_70 ;
T_2 V_71 ;
if ( ! V_41 )
return true ;
if ( F_27 ( V_3 ) != V_72 && F_27 ( V_3 ) != V_73 )
return true ;
if ( ! F_28 ( V_3 ) )
return true ;
if ( F_12 ( V_3 ) )
return true ;
if ( F_29 ( V_3 ) == V_74 ) {
if ( ! V_41 -> V_75 -> V_76 ||
! ( V_41 -> V_77 & V_78 ) )
return true ;
} else {
if ( ! V_41 -> V_75 -> V_79 ||
! ( V_41 -> V_77 & V_80 ) )
return true ;
}
V_70 = F_19 ( V_41 , F_28 ( V_3 ) ) ;
V_31 = V_70 * V_41 -> V_44 ;
V_64 = F_4 ( V_31 , V_81 | V_63 -> V_82 ) ;
V_71 = V_83 ;
if ( F_6 ( V_64 == NULL ) ) {
F_17 ( V_35 L_2 ) ;
goto V_84;
}
V_66 = ( ( ( unsigned long ) V_64 ) + V_31 + V_85 - 1 ) >> V_86 ;
V_65 = ( ( unsigned long ) V_64 ) >> V_86 ;
V_67 = V_66 - V_65 ;
V_6 = F_3 ( V_3 , V_81 , V_67 ) ;
if ( F_30 ( V_6 ) ) {
F_17 ( V_35 L_3 ) ;
F_13 ( V_64 ) ;
V_71 = V_83 ;
goto V_84;
}
V_6 -> V_26 |= V_27 ;
V_6 -> V_87 . V_88 = V_31 ;
F_31 ( V_6 , V_3 -> V_89 . V_58 ) ;
if ( V_41 -> V_77 & V_90 )
V_6 -> V_26 |= V_91 ;
V_32 = F_32 ( V_64 ) ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ ) {
int V_52 ;
V_68 = V_85 - V_32 ;
if ( V_31 <= 0 )
break;
if ( V_68 > V_31 )
V_68 = V_31 ;
V_52 = F_16 ( V_3 , F_33 ( V_64 ) ,
V_68 , V_32 ) ;
if ( V_52 == 0 )
return false ;
if ( V_52 < V_68 )
break;
V_64 += V_68 ;
V_31 -= V_68 ;
V_32 = 0 ;
}
if ( F_29 ( V_3 ) == V_92 ) {
F_21 ( V_3 , & V_3 -> V_89 ,
V_41 -> V_75 -> V_79 ) ;
}
return true ;
V_84:
V_3 -> V_93 = V_71 ;
F_34 ( V_3 ) ;
return false ;
}
static void F_35 ( struct V_94 * V_95 )
{
struct V_2 * V_6 =
F_36 ( V_95 , struct V_2 , V_96 ) ;
struct V_3 * V_3 = V_6 -> V_22 ;
struct V_40 * V_41 = F_22 ( V_3 -> V_37 ) ;
struct V_45 V_49 = V_3 -> V_89 ;
if ( F_37 ( V_3 , & V_49 , V_49 . V_97 ) ) {
V_3 -> V_93 = F_21 ( V_3 , & V_49 ,
V_41 -> V_75 -> V_76 ) ;
} else {
V_3 -> V_93 = V_98 ;
}
F_11 ( V_3 ) ;
F_34 ( V_3 ) ;
}
bool F_38 ( struct V_3 * V_3 )
{
struct V_40 * V_41 = F_22 ( V_3 -> V_37 ) ;
struct V_2 * V_6 = F_12 ( V_3 ) ;
if ( F_27 ( V_3 ) == V_72 && ! V_3 -> V_93 &&
( V_6 -> V_26 & V_27 ) && V_41 -> V_75 -> V_76 ) {
F_39 ( & V_6 -> V_96 , F_35 ) ;
F_40 ( V_1 , & V_6 -> V_96 ) ;
return false ;
}
F_11 ( V_3 ) ;
return true ;
}
void F_41 ( struct V_3 * V_3 , unsigned int V_99 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_40 * V_41 = F_22 ( V_3 -> V_37 ) ;
unsigned V_68 = F_20 ( V_41 , V_99 >> 9 ) ;
V_6 -> V_87 . V_58 += V_99 >> 9 ;
F_42 ( V_6 -> V_16 , & V_6 -> V_87 , V_68 ) ;
}
void F_43 ( struct V_3 * V_3 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_40 * V_41 = F_22 ( V_3 -> V_37 ) ;
V_6 -> V_87 . V_88 = F_20 ( V_41 , F_28 ( V_3 ) ) ;
}
int F_44 ( struct V_3 * V_3 , struct V_3 * V_100 ,
T_1 V_4 )
{
struct V_2 * V_101 = F_12 ( V_100 ) ;
struct V_2 * V_6 ;
F_45 ( V_101 == NULL ) ;
V_6 = F_3 ( V_3 , V_4 , V_101 -> V_34 ) ;
if ( F_30 ( V_6 ) )
return F_46 ( V_6 ) ;
memcpy ( V_6 -> V_16 , V_101 -> V_16 ,
V_101 -> V_34 * sizeof( struct V_12 ) ) ;
V_6 -> V_34 = V_101 -> V_34 ;
V_6 -> V_87 = V_101 -> V_87 ;
return 0 ;
}
int F_47 ( struct V_7 * V_8 , int V_102 )
{
if ( V_8 -> V_11 )
return 0 ;
V_8 -> V_11 = F_48 ( V_102 , V_20 ) ;
if ( ! V_8 -> V_11 )
return - 1 ;
V_8 -> V_17 = F_49 ( V_102 ) ;
if ( ! V_8 -> V_17 ) {
F_50 ( V_8 -> V_11 ) ;
return - 1 ;
}
return 0 ;
}
void F_51 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 )
F_50 ( V_8 -> V_11 ) ;
if ( V_8 -> V_17 )
F_50 ( V_8 -> V_17 ) ;
}
void T_4 F_52 ( void )
{
V_1 = F_53 ( L_4 , V_103 |
V_104 | V_105 , 1 ) ;
if ( ! V_1 )
F_54 ( L_5 ) ;
V_20 = F_55 ( L_6 ,
sizeof( struct V_2 ) +
sizeof( struct V_12 ) * V_13 ,
0 , V_106 | V_107 , NULL ) ;
}
