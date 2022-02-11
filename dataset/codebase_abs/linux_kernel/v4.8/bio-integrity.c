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
if ( ! F_22 ( V_3 ) )
return false ;
if ( F_12 ( V_3 ) )
return false ;
if ( V_40 == NULL )
return false ;
if ( F_23 ( V_3 ) == V_41 && V_40 -> V_42 -> V_43 != NULL &&
( V_40 -> V_44 & V_45 ) )
return true ;
if ( F_23 ( V_3 ) == V_46 && V_40 -> V_42 -> V_47 != NULL &&
( V_40 -> V_44 & V_48 ) )
return true ;
return false ;
}
static inline unsigned int F_24 ( struct V_39 * V_40 ,
unsigned int V_49 )
{
return V_49 >> ( V_40 -> V_50 - 9 ) ;
}
static inline unsigned int F_25 ( struct V_39 * V_40 ,
unsigned int V_49 )
{
return F_24 ( V_40 , V_49 ) * V_40 -> V_51 ;
}
static int F_26 ( struct V_3 * V_3 ,
T_2 * V_52 )
{
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
struct V_53 V_54 ;
struct V_55 V_56 ;
struct V_12 V_57 ;
struct V_2 * V_6 = F_12 ( V_3 ) ;
unsigned int V_58 = 0 ;
void * V_59 = F_14 ( V_6 -> V_16 -> V_28 ) +
V_6 -> V_16 -> V_29 ;
V_54 . V_60 = V_3 -> V_37 -> V_61 -> V_60 ;
V_54 . V_62 = 1 << V_40 -> V_50 ;
V_54 . V_63 = F_27 ( V_6 ) ;
V_54 . V_59 = V_59 ;
F_28 (bv, bio, bviter) {
void * V_64 = F_29 ( V_57 . V_28 ) ;
V_54 . V_65 = V_64 + V_57 . V_29 ;
V_54 . V_66 = V_57 . V_38 ;
V_58 = V_52 ( & V_54 ) ;
if ( V_58 ) {
F_30 ( V_64 ) ;
return V_58 ;
}
F_30 ( V_64 ) ;
}
return V_58 ;
}
int F_31 ( struct V_3 * V_3 )
{
struct V_2 * V_6 ;
struct V_39 * V_40 ;
struct V_67 * V_68 ;
void * V_69 ;
unsigned long V_70 , V_71 ;
unsigned int V_31 , V_72 ;
unsigned int V_73 , V_32 , V_74 ;
unsigned int V_75 ;
V_40 = F_21 ( V_3 -> V_37 ) ;
V_68 = F_19 ( V_3 -> V_37 ) ;
F_32 ( V_40 == NULL ) ;
F_32 ( F_12 ( V_3 ) ) ;
V_75 = F_24 ( V_40 , F_33 ( V_3 ) ) ;
V_31 = V_75 * V_40 -> V_51 ;
V_69 = F_4 ( V_31 , V_76 | V_68 -> V_77 ) ;
if ( F_6 ( V_69 == NULL ) ) {
F_17 ( V_35 L_2 ) ;
return - V_14 ;
}
V_71 = ( ( ( unsigned long ) V_69 ) + V_31 + V_78 - 1 ) >> V_79 ;
V_70 = ( ( unsigned long ) V_69 ) >> V_79 ;
V_72 = V_71 - V_70 ;
V_6 = F_3 ( V_3 , V_76 , V_72 ) ;
if ( F_34 ( V_6 ) ) {
F_17 ( V_35 L_3 ) ;
F_13 ( V_69 ) ;
return F_35 ( V_6 ) ;
}
V_6 -> V_26 |= V_27 ;
V_6 -> V_80 . V_81 = V_31 ;
F_36 ( V_6 , V_3 -> V_82 . V_83 ) ;
if ( V_40 -> V_44 & V_84 )
V_6 -> V_26 |= V_85 ;
V_32 = F_37 ( V_69 ) ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
int V_58 ;
V_73 = V_78 - V_32 ;
if ( V_31 <= 0 )
break;
if ( V_73 > V_31 )
V_73 = V_31 ;
V_58 = F_16 ( V_3 , F_38 ( V_69 ) ,
V_73 , V_32 ) ;
if ( V_58 == 0 )
return 0 ;
if ( V_58 < V_73 )
break;
V_69 += V_73 ;
V_31 -= V_73 ;
V_32 = 0 ;
}
if ( F_23 ( V_3 ) == V_41 ) {
V_6 -> V_86 = V_3 -> V_87 ;
V_3 -> V_87 = V_88 ;
}
if ( F_23 ( V_3 ) == V_46 )
F_26 ( V_3 , V_40 -> V_42 -> V_47 ) ;
return 0 ;
}
static void F_39 ( struct V_89 * V_90 )
{
struct V_2 * V_6 =
F_40 ( V_90 , struct V_2 , V_91 ) ;
struct V_3 * V_3 = V_6 -> V_22 ;
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
V_3 -> V_92 = F_26 ( V_3 , V_40 -> V_42 -> V_43 ) ;
V_3 -> V_87 = V_6 -> V_86 ;
F_41 ( V_3 ) ;
}
void V_88 ( struct V_3 * V_3 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
F_32 ( V_6 -> V_22 != V_3 ) ;
if ( V_3 -> V_92 ) {
V_3 -> V_87 = V_6 -> V_86 ;
F_41 ( V_3 ) ;
return;
}
F_42 ( & V_6 -> V_91 , F_39 ) ;
F_43 ( V_1 , & V_6 -> V_91 ) ;
}
void F_44 ( struct V_3 * V_3 , unsigned int V_93 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
unsigned V_73 = F_25 ( V_40 , V_93 >> 9 ) ;
F_45 ( V_6 -> V_16 , & V_6 -> V_80 , V_73 ) ;
}
void F_46 ( struct V_3 * V_3 , unsigned int V_32 ,
unsigned int V_49 )
{
struct V_2 * V_6 = F_12 ( V_3 ) ;
struct V_39 * V_40 = F_21 ( V_3 -> V_37 ) ;
F_44 ( V_3 , V_32 << 9 ) ;
V_6 -> V_80 . V_81 = F_25 ( V_40 , V_49 ) ;
}
int F_47 ( struct V_3 * V_3 , struct V_3 * V_94 ,
T_1 V_4 )
{
struct V_2 * V_95 = F_12 ( V_94 ) ;
struct V_2 * V_6 ;
F_32 ( V_95 == NULL ) ;
V_6 = F_3 ( V_3 , V_4 , V_95 -> V_34 ) ;
if ( F_34 ( V_6 ) )
return F_35 ( V_6 ) ;
memcpy ( V_6 -> V_16 , V_95 -> V_16 ,
V_95 -> V_34 * sizeof( struct V_12 ) ) ;
V_6 -> V_34 = V_95 -> V_34 ;
V_6 -> V_80 = V_95 -> V_80 ;
return 0 ;
}
int F_48 ( struct V_7 * V_8 , int V_96 )
{
if ( V_8 -> V_11 )
return 0 ;
V_8 -> V_11 = F_49 ( V_96 , V_20 ) ;
if ( ! V_8 -> V_11 )
return - 1 ;
V_8 -> V_17 = F_50 ( V_96 ) ;
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
V_1 = F_54 ( L_4 , V_97 |
V_98 | V_99 , 1 ) ;
if ( ! V_1 )
F_55 ( L_5 ) ;
V_20 = F_56 ( L_6 ,
sizeof( struct V_2 ) +
sizeof( struct V_12 ) * V_13 ,
0 , V_100 | V_101 , NULL ) ;
}
