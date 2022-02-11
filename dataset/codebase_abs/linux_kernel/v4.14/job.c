struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 = NULL ;
unsigned int V_8 = V_4 + V_5 ;
T_2 V_9 ;
void * V_10 ;
V_9 = sizeof( struct V_1 ) +
( T_2 ) V_5 * sizeof( struct V_11 ) +
( T_2 ) V_8 * sizeof( struct V_12 ) +
( T_2 ) V_6 * sizeof( struct V_13 ) +
( T_2 ) V_4 * sizeof( struct V_14 ) +
( T_2 ) V_8 * sizeof( V_15 ) +
( T_2 ) V_8 * sizeof( T_1 * ) ;
if ( V_9 > V_16 )
return NULL ;
V_10 = V_7 = F_2 ( V_9 , V_17 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( & V_7 -> V_18 ) ;
V_7 -> V_19 = V_3 ;
V_10 += sizeof( struct V_1 ) ;
V_7 -> V_20 = V_5 ? V_10 : NULL ;
V_10 += V_5 * sizeof( struct V_11 ) ;
V_7 -> V_21 = V_8 ? V_10 : NULL ;
V_10 += V_8 * sizeof( struct V_12 ) ;
V_7 -> V_22 = V_6 ? V_10 : NULL ;
V_10 += V_6 * sizeof( struct V_13 ) ;
V_7 -> V_23 = V_4 ? V_10 : NULL ;
V_10 += V_4 * sizeof( struct V_14 ) ;
V_7 -> V_24 = V_8 ? V_10 : NULL ;
V_7 -> V_25 = V_7 -> V_24 ;
V_7 -> V_26 = & V_7 -> V_24 [ V_5 ] ;
return V_7 ;
}
struct V_1 * F_4 ( struct V_1 * V_7 )
{
F_5 ( & V_7 -> V_18 ) ;
return V_7 ;
}
static void F_6 ( struct V_27 * V_18 )
{
struct V_1 * V_7 = F_7 ( V_18 , struct V_1 , V_18 ) ;
F_8 ( V_7 ) ;
}
void F_9 ( struct V_1 * V_7 )
{
F_10 ( & V_7 -> V_18 , F_6 ) ;
}
void F_11 ( struct V_1 * V_7 , struct V_28 * V_29 ,
T_1 V_30 , T_1 V_31 )
{
struct V_14 * V_32 = & V_7 -> V_23 [ V_7 -> V_33 ] ;
V_32 -> V_30 = V_30 ;
V_32 -> V_29 = V_29 ;
V_32 -> V_31 = V_31 ;
V_7 -> V_33 ++ ;
}
static void F_12 ( struct V_34 * V_35 ,
struct V_28 * V_36 , T_1 V_31 )
{
void * V_37 = NULL ;
V_37 = F_13 ( V_36 , V_31 >> V_38 ) ;
if ( V_37 ) {
F_14 ( V_35 ,
V_37 + ( V_31 & ~ V_39 ) ) ;
F_15 ( V_36 , V_31 >> V_38 , V_37 ) ;
} else
F_16 ( L_1 ) ;
}
static int F_17 ( struct V_1 * V_7 , struct V_40 * V_41 ,
struct V_14 * V_42 )
{
struct V_28 * V_43 = V_42 -> V_29 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
struct V_13 * V_46 = & V_7 -> V_22 [ V_44 ] ;
struct V_34 * V_35 =
F_18 ( V_41 , V_46 -> V_47 ) ;
if ( V_46 -> V_47 > F_19 ( V_41 ) )
continue;
if ( V_43 != V_46 -> V_29 )
continue;
F_20 ( V_46 -> V_29 , V_46 -> V_31 ,
V_46 -> V_47 , V_46 -> V_48 ,
F_21 ( V_35 ) ) ;
if ( F_22 ( V_35 , V_46 -> V_48 ) ) {
F_23 ( V_41 -> V_49 ,
L_2 ,
V_46 -> V_47 , V_35 -> V_50 , V_46 -> V_48 ,
F_21 ( V_35 ) ) ;
F_12 ( V_35 , V_43 ,
V_42 -> V_31 + V_46 -> V_31 ) ;
}
V_46 -> V_29 = NULL ;
}
return 0 ;
}
static unsigned int F_24 ( struct V_40 * V_41 , struct V_1 * V_7 )
{
unsigned int V_44 ;
int V_51 ;
V_7 -> V_8 = 0 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_5 ; V_44 ++ ) {
struct V_11 * V_52 = & V_7 -> V_20 [ V_44 ] ;
struct V_53 * V_54 ;
V_15 V_55 ;
V_52 -> V_56 . V_29 = F_25 ( V_52 -> V_56 . V_29 ) ;
if ( ! V_52 -> V_56 . V_29 ) {
V_51 = - V_57 ;
goto V_58;
}
V_55 = F_26 ( V_52 -> V_56 . V_29 , & V_54 ) ;
V_7 -> V_24 [ V_7 -> V_8 ] = V_55 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_52 -> V_56 . V_29 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_54 = V_54 ;
V_7 -> V_8 ++ ;
}
for ( V_44 = 0 ; V_44 < V_7 -> V_33 ; V_44 ++ ) {
struct V_14 * V_42 = & V_7 -> V_23 [ V_44 ] ;
T_3 V_59 = 0 ;
struct V_60 * V_61 ;
struct V_53 * V_54 ;
V_15 V_55 ;
unsigned long V_62 ;
struct V_63 * V_64 ;
unsigned int V_65 ;
V_42 -> V_29 = F_25 ( V_42 -> V_29 ) ;
if ( ! V_42 -> V_29 ) {
V_51 = - V_57 ;
goto V_58;
}
V_55 = F_26 ( V_42 -> V_29 , & V_54 ) ;
if ( ! F_27 ( V_66 ) && V_41 -> V_67 ) {
F_28 (sgt->sgl, sg, sgt->nents, j)
V_59 += V_61 -> V_68 ;
V_59 = F_29 ( & V_41 -> V_63 , V_59 ) ;
V_62 = F_30 ( & V_41 -> V_63 ) ;
V_64 = F_31 ( & V_41 -> V_63 , V_59 >> V_62 ,
V_41 -> V_69 >> V_62 , true ) ;
if ( ! V_64 ) {
V_51 = - V_70 ;
goto V_58;
}
V_51 = F_32 ( V_41 -> V_67 ,
F_33 ( & V_41 -> V_63 , V_64 ) ,
V_54 -> V_71 , V_54 -> V_72 , V_73 ) ;
if ( V_51 == 0 ) {
F_34 ( & V_41 -> V_63 , V_64 ) ;
V_51 = - V_57 ;
goto V_58;
}
V_7 -> V_24 [ V_7 -> V_8 ] =
F_33 ( & V_41 -> V_63 , V_64 ) ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_74 = V_59 ;
} else {
V_7 -> V_24 [ V_7 -> V_8 ] = V_55 ;
}
V_7 -> V_26 [ V_44 ] = V_7 -> V_24 [ V_7 -> V_8 ] ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_42 -> V_29 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_54 = V_54 ;
V_7 -> V_8 ++ ;
}
return 0 ;
V_58:
F_35 ( V_7 ) ;
return V_51 ;
}
static int F_36 ( struct V_1 * V_7 , struct V_14 * V_42 )
{
int V_44 = 0 ;
T_1 V_75 = ~ 0 ;
void * V_76 = NULL ;
struct V_28 * V_77 = V_42 -> V_29 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_5 ; V_44 ++ ) {
struct V_11 * V_52 = & V_7 -> V_20 [ V_44 ] ;
T_1 V_78 = ( V_7 -> V_25 [ V_44 ] +
V_52 -> V_56 . V_31 ) >> V_52 -> V_62 ;
T_1 * V_56 ;
if ( V_77 != V_52 -> V_77 . V_29 )
continue;
if ( F_27 ( V_66 ) ) {
V_56 = ( T_1 * ) V_7 -> V_79 +
V_52 -> V_77 . V_31 / sizeof( T_1 ) +
V_42 -> V_31 / sizeof( T_1 ) ;
goto V_80;
}
if ( V_75 != V_52 -> V_77 . V_31 >> V_38 ) {
if ( V_76 )
F_15 ( V_77 , V_75 ,
V_76 ) ;
V_76 = F_13 ( V_77 ,
V_52 -> V_77 . V_31 >> V_38 ) ;
V_75 = V_52 -> V_77 . V_31 >> V_38 ;
if ( F_37 ( ! V_76 ) ) {
F_16 ( L_3 ) ;
return - V_70 ;
}
}
V_56 = V_76 + ( V_52 -> V_77 . V_31 & ~ V_39 ) ;
V_80:
* V_56 = V_78 ;
}
if ( V_76 )
F_15 ( V_77 , V_75 , V_76 ) ;
return 0 ;
}
static bool F_38 ( struct V_11 * V_52 , struct V_28 * V_77 ,
unsigned int V_31 )
{
V_31 *= sizeof( T_1 ) ;
if ( V_52 -> V_77 . V_29 != V_77 || V_52 -> V_77 . V_31 != V_31 )
return false ;
if ( V_52 -> V_62 )
return false ;
return true ;
}
static bool F_39 ( struct V_13 * V_46 , struct V_28 * V_77 ,
unsigned int V_31 )
{
V_31 *= sizeof( T_1 ) ;
if ( V_46 -> V_29 != V_77 || V_46 -> V_31 != V_31 )
return false ;
return true ;
}
static int F_40 ( struct V_81 * V_82 , unsigned long V_31 )
{
if ( ! V_82 -> V_7 -> V_83 )
return 0 ;
if ( V_82 -> V_7 -> V_83 ( V_82 -> V_49 , V_82 -> V_84 , V_31 ) ) {
if ( ! V_82 -> V_5 )
return - V_57 ;
if ( ! F_38 ( V_82 -> V_52 , V_82 -> V_77 , V_82 -> V_31 ) )
return - V_57 ;
V_82 -> V_5 -- ;
V_82 -> V_52 ++ ;
}
if ( V_31 == V_85 ) {
if ( V_82 -> V_84 != V_86 )
return - V_57 ;
if ( ! V_82 -> V_6 )
return - V_57 ;
if ( ! F_39 ( V_82 -> V_22 , V_82 -> V_77 , V_82 -> V_31 ) )
return - V_57 ;
V_82 -> V_6 -- ;
V_82 -> V_22 ++ ;
}
return 0 ;
}
static int F_41 ( struct V_81 * V_82 , T_1 V_84 )
{
if ( ! V_82 -> V_7 -> V_87 ) {
if ( V_82 -> V_84 != V_84 )
return - V_57 ;
} else {
if ( ! V_82 -> V_7 -> V_87 ( V_82 -> V_84 ) )
return - V_57 ;
}
return 0 ;
}
static int F_42 ( struct V_81 * V_82 )
{
T_1 V_88 = V_82 -> V_88 ;
T_1 V_89 = V_82 -> V_89 ;
int V_90 ;
while ( V_88 ) {
if ( V_82 -> V_30 == 0 )
return - V_57 ;
if ( V_88 & 1 ) {
V_90 = F_40 ( V_82 , V_89 ) ;
if ( V_90 < 0 )
return V_90 ;
V_82 -> V_30 -- ;
V_82 -> V_31 ++ ;
}
V_88 >>= 1 ;
V_89 ++ ;
}
return 0 ;
}
static int F_43 ( struct V_81 * V_82 )
{
T_1 V_91 = V_82 -> V_91 ;
T_1 V_89 = V_82 -> V_89 ;
int V_90 ;
while ( V_91 ) {
if ( V_82 -> V_30 == 0 )
return - V_57 ;
V_90 = F_40 ( V_82 , V_89 ) ;
if ( V_90 < 0 )
return V_90 ;
V_89 ++ ;
V_82 -> V_30 -- ;
V_82 -> V_31 ++ ;
V_91 -- ;
}
return 0 ;
}
static int F_44 ( struct V_81 * V_82 )
{
T_1 V_91 = V_82 -> V_91 ;
int V_90 ;
while ( V_91 ) {
if ( V_82 -> V_30 == 0 )
return - V_57 ;
V_90 = F_40 ( V_82 , V_82 -> V_89 ) ;
if ( V_90 < 0 )
return V_90 ;
V_82 -> V_30 -- ;
V_82 -> V_31 ++ ;
V_91 -- ;
}
return 0 ;
}
static int F_45 ( struct V_81 * V_82 , struct V_14 * V_42 )
{
T_1 * V_92 = ( T_1 * ) V_82 -> V_7 -> V_79 +
( V_42 -> V_31 / sizeof( T_1 ) ) ;
T_1 V_93 = V_82 -> V_84 ;
int V_51 = 0 ;
V_82 -> V_30 = V_42 -> V_30 ;
V_82 -> V_77 = V_42 -> V_29 ;
V_82 -> V_31 = 0 ;
while ( V_82 -> V_30 && ! V_51 ) {
T_1 V_94 = V_92 [ V_82 -> V_31 ] ;
T_1 V_95 = ( V_94 & 0xf0000000 ) >> 28 ;
V_82 -> V_88 = 0 ;
V_82 -> V_89 = 0 ;
V_82 -> V_91 = 0 ;
V_82 -> V_30 -- ;
V_82 -> V_31 ++ ;
switch ( V_95 ) {
case 0 :
V_82 -> V_84 = V_94 >> 6 & 0x3ff ;
V_82 -> V_88 = V_94 & 0x3f ;
V_82 -> V_89 = V_94 >> 16 & 0xfff ;
V_51 = F_41 ( V_82 , V_93 ) ;
if ( ! V_51 )
V_51 = F_42 ( V_82 ) ;
if ( V_51 )
goto V_96;
break;
case 1 :
V_82 -> V_89 = V_94 >> 16 & 0xfff ;
V_82 -> V_91 = V_94 & 0xffff ;
V_51 = F_43 ( V_82 ) ;
if ( V_51 )
goto V_96;
break;
case 2 :
V_82 -> V_89 = V_94 >> 16 & 0xfff ;
V_82 -> V_91 = V_94 & 0xffff ;
V_51 = F_44 ( V_82 ) ;
if ( V_51 )
goto V_96;
break;
case 3 :
V_82 -> V_88 = V_94 & 0xffff ;
V_82 -> V_89 = V_94 >> 16 & 0xfff ;
V_51 = F_42 ( V_82 ) ;
if ( V_51 )
goto V_96;
break;
case 4 :
case 14 :
break;
default:
V_51 = - V_57 ;
break;
}
}
V_96:
return V_51 ;
}
static inline int F_46 ( struct V_1 * V_7 , struct V_97 * V_49 )
{
struct V_81 V_82 ;
T_3 V_74 = 0 ;
T_3 V_31 = 0 ;
int V_44 ;
V_82 . V_7 = V_7 ;
V_82 . V_49 = V_49 ;
V_82 . V_52 = V_7 -> V_20 ;
V_82 . V_5 = V_7 -> V_5 ;
V_82 . V_22 = V_7 -> V_22 ;
V_82 . V_6 = V_7 -> V_45 ;
V_82 . V_84 = V_7 -> V_84 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_33 ; V_44 ++ ) {
struct V_14 * V_42 = & V_7 -> V_23 [ V_44 ] ;
V_74 += V_42 -> V_30 * sizeof( T_1 ) ;
}
V_7 -> V_79 = F_47 ( V_49 , V_74 , & V_7 -> V_98 ,
V_99 ) ;
if ( ! V_7 -> V_79 )
V_7 -> V_79 = F_47 ( V_49 , V_74 ,
& V_7 -> V_98 ,
V_17 ) ;
if ( ! V_7 -> V_79 )
return - V_70 ;
V_7 -> V_100 = V_74 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_33 ; V_44 ++ ) {
struct V_14 * V_42 = & V_7 -> V_23 [ V_44 ] ;
void * V_101 ;
V_101 = F_48 ( V_42 -> V_29 ) ;
memcpy ( V_7 -> V_79 + V_31 , V_101 + V_42 -> V_31 ,
V_42 -> V_30 * sizeof( T_1 ) ) ;
F_49 ( V_42 -> V_29 , V_101 ) ;
V_42 -> V_102 = V_7 -> V_98 ;
V_42 -> V_31 = V_31 ;
if ( F_45 ( & V_82 , V_42 ) )
return - V_57 ;
V_31 += V_42 -> V_30 * sizeof( T_1 ) ;
}
if ( V_82 . V_5 || V_82 . V_6 )
return - V_57 ;
return 0 ;
}
int F_50 ( struct V_1 * V_7 , struct V_97 * V_49 )
{
int V_51 ;
unsigned int V_44 , V_65 ;
struct V_40 * V_41 = F_51 ( V_49 -> V_103 ) ;
F_52 ( V_104 , F_19 ( V_41 ) ) ;
F_53 ( V_104 , F_19 ( V_41 ) ) ;
for ( V_44 = 0 ; V_44 < V_7 -> V_45 ; V_44 ++ ) {
T_1 V_47 = V_7 -> V_22 [ V_44 ] . V_47 ;
if ( V_47 < F_19 ( V_41 ) )
F_54 ( V_47 , V_104 ) ;
}
F_55 (i, waitchk_mask, host1x_syncpt_nb_pts(host))
F_56 ( V_41 -> V_105 + V_44 ) ;
V_51 = F_24 ( V_41 , V_7 ) ;
if ( V_51 )
goto V_96;
if ( F_27 ( V_66 ) ) {
V_51 = F_46 ( V_7 , V_49 ) ;
if ( V_51 )
goto V_96;
}
for ( V_44 = 0 ; V_44 < V_7 -> V_33 ; V_44 ++ ) {
struct V_14 * V_42 = & V_7 -> V_23 [ V_44 ] ;
if ( V_42 -> V_106 )
continue;
if ( ! F_27 ( V_66 ) )
V_42 -> V_102 = V_7 -> V_26 [ V_44 ] ;
for ( V_65 = V_44 + 1 ; V_65 < V_7 -> V_33 ; V_65 ++ ) {
if ( V_7 -> V_23 [ V_65 ] . V_29 == V_42 -> V_29 ) {
V_7 -> V_23 [ V_65 ] . V_106 = true ;
V_7 -> V_23 [ V_65 ] . V_102 = V_42 -> V_102 ;
}
}
V_51 = F_36 ( V_7 , V_42 ) ;
if ( V_51 )
break;
V_51 = F_17 ( V_7 , V_41 , V_42 ) ;
if ( V_51 )
break;
}
V_96:
if ( V_51 )
F_35 ( V_7 ) ;
F_57 () ;
return V_51 ;
}
void F_35 ( struct V_1 * V_7 )
{
struct V_40 * V_41 = F_51 ( V_7 -> V_19 -> V_49 -> V_103 ) ;
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < V_7 -> V_8 ; V_44 ++ ) {
struct V_12 * V_58 = & V_7 -> V_21 [ V_44 ] ;
if ( ! F_27 ( V_66 ) && V_41 -> V_67 ) {
F_58 ( V_41 -> V_67 , V_7 -> V_24 [ V_44 ] ,
V_58 -> V_74 ) ;
F_59 ( & V_41 -> V_63 ,
F_60 ( & V_41 -> V_63 , V_7 -> V_24 [ V_44 ] ) ) ;
}
F_61 ( V_58 -> V_29 , V_58 -> V_54 ) ;
F_62 ( V_58 -> V_29 ) ;
}
V_7 -> V_8 = 0 ;
if ( V_7 -> V_100 )
F_63 ( V_7 -> V_19 -> V_49 , V_7 -> V_100 ,
V_7 -> V_79 , V_7 -> V_98 ) ;
}
void F_64 ( struct V_97 * V_49 , struct V_1 * V_7 )
{
F_23 ( V_49 , L_4 , V_7 -> V_47 ) ;
F_23 ( V_49 , L_5 , V_7 -> V_107 ) ;
F_23 ( V_49 , L_6 , V_7 -> V_108 ) ;
F_23 ( V_49 , L_7 , V_7 -> V_109 ) ;
F_23 ( V_49 , L_8 , V_7 -> V_110 ) ;
F_23 ( V_49 , L_9 , V_7 -> V_8 ) ;
}
