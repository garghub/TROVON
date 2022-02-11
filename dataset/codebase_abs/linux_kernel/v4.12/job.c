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
struct V_28 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_44 ; V_43 ++ ) {
struct V_13 * V_45 = & V_7 -> V_22 [ V_43 ] ;
struct V_34 * V_35 =
F_18 ( V_41 , V_45 -> V_46 ) ;
if ( V_45 -> V_46 > F_19 ( V_41 ) )
continue;
if ( V_42 != V_45 -> V_29 )
continue;
F_20 ( V_45 -> V_29 , V_45 -> V_31 ,
V_45 -> V_46 , V_45 -> V_47 ,
F_21 ( V_35 ) ) ;
if ( F_22 ( V_35 , V_45 -> V_47 ) ) {
F_23 ( V_41 -> V_48 ,
L_2 ,
V_45 -> V_46 , V_35 -> V_49 , V_45 -> V_47 ,
F_21 ( V_35 ) ) ;
F_12 ( V_35 , V_42 , V_45 -> V_31 ) ;
}
V_45 -> V_29 = NULL ;
}
return 0 ;
}
static unsigned int F_24 ( struct V_40 * V_41 , struct V_1 * V_7 )
{
unsigned int V_43 ;
int V_50 ;
V_7 -> V_8 = 0 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_5 ; V_43 ++ ) {
struct V_11 * V_51 = & V_7 -> V_20 [ V_43 ] ;
struct V_52 * V_53 ;
V_15 V_54 ;
V_51 -> V_55 . V_29 = F_25 ( V_51 -> V_55 . V_29 ) ;
if ( ! V_51 -> V_55 . V_29 ) {
V_50 = - V_56 ;
goto V_57;
}
V_54 = F_26 ( V_51 -> V_55 . V_29 , & V_53 ) ;
if ( ! V_54 ) {
V_50 = - V_56 ;
goto V_57;
}
V_7 -> V_24 [ V_7 -> V_8 ] = V_54 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_51 -> V_55 . V_29 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_53 = V_53 ;
V_7 -> V_8 ++ ;
}
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_58 = & V_7 -> V_23 [ V_43 ] ;
T_3 V_59 = 0 ;
struct V_60 * V_61 ;
struct V_52 * V_53 ;
V_15 V_54 ;
unsigned long V_62 ;
struct V_63 * V_64 ;
unsigned int V_65 ;
V_58 -> V_29 = F_25 ( V_58 -> V_29 ) ;
if ( ! V_58 -> V_29 ) {
V_50 = - V_56 ;
goto V_57;
}
V_54 = F_26 ( V_58 -> V_29 , & V_53 ) ;
if ( ! V_54 ) {
V_50 = - V_56 ;
goto V_57;
}
if ( ! F_27 ( V_66 ) && V_41 -> V_67 ) {
F_28 (sgt->sgl, sg, sgt->nents, j)
V_59 += V_61 -> V_68 ;
V_59 = F_29 ( & V_41 -> V_63 , V_59 ) ;
V_62 = F_30 ( & V_41 -> V_63 ) ;
V_64 = F_31 ( & V_41 -> V_63 , V_59 >> V_62 ,
V_41 -> V_69 >> V_62 , true ) ;
if ( ! V_64 ) {
V_50 = - V_70 ;
goto V_57;
}
V_50 = F_32 ( V_41 -> V_67 ,
F_33 ( & V_41 -> V_63 , V_64 ) ,
V_53 -> V_71 , V_53 -> V_72 , V_73 ) ;
if ( V_50 == 0 ) {
F_34 ( & V_41 -> V_63 , V_64 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_7 -> V_24 [ V_7 -> V_8 ] =
F_33 ( & V_41 -> V_63 , V_64 ) ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_74 = V_59 ;
} else {
V_7 -> V_24 [ V_7 -> V_8 ] = V_54 ;
}
V_7 -> V_26 [ V_43 ] = V_7 -> V_24 [ V_7 -> V_8 ] ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_58 -> V_29 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_53 = V_53 ;
V_7 -> V_8 ++ ;
}
return 0 ;
V_57:
F_35 ( V_7 ) ;
return V_50 ;
}
static int F_36 ( struct V_1 * V_7 , struct V_28 * V_75 )
{
int V_43 = 0 ;
T_1 V_76 = ~ 0 ;
void * V_77 = NULL ;
for ( V_43 = 0 ; V_43 < V_7 -> V_5 ; V_43 ++ ) {
struct V_11 * V_51 = & V_7 -> V_20 [ V_43 ] ;
T_1 V_78 = ( V_7 -> V_25 [ V_43 ] +
V_51 -> V_55 . V_31 ) >> V_51 -> V_62 ;
T_1 * V_55 ;
if ( V_75 != V_51 -> V_75 . V_29 )
continue;
if ( V_76 != V_51 -> V_75 . V_31 >> V_38 ) {
if ( V_77 )
F_15 ( V_75 , V_76 ,
V_77 ) ;
V_77 = F_13 ( V_75 ,
V_51 -> V_75 . V_31 >> V_38 ) ;
V_76 = V_51 -> V_75 . V_31 >> V_38 ;
if ( F_37 ( ! V_77 ) ) {
F_16 ( L_3 ) ;
return - V_70 ;
}
}
V_55 = V_77 + ( V_51 -> V_75 . V_31 & ~ V_39 ) ;
* V_55 = V_78 ;
}
if ( V_77 )
F_15 ( V_75 , V_76 , V_77 ) ;
return 0 ;
}
static bool F_38 ( struct V_11 * V_51 , struct V_28 * V_75 ,
unsigned int V_31 )
{
V_31 *= sizeof( T_1 ) ;
if ( V_51 -> V_75 . V_29 != V_75 || V_51 -> V_75 . V_31 != V_31 )
return false ;
return true ;
}
static int F_39 ( struct V_79 * V_80 , unsigned long V_31 )
{
if ( V_80 -> V_7 -> V_81 ( V_80 -> V_48 , V_80 -> V_82 , V_31 ) ) {
if ( ! V_80 -> V_5 )
return - V_56 ;
if ( ! F_38 ( V_80 -> V_51 , V_80 -> V_75 , V_80 -> V_31 ) )
return - V_56 ;
V_80 -> V_5 -- ;
V_80 -> V_51 ++ ;
}
return 0 ;
}
static int F_40 ( struct V_79 * V_80 )
{
T_1 V_83 = V_80 -> V_83 ;
T_1 V_84 = V_80 -> V_84 ;
int V_85 ;
while ( V_83 ) {
if ( V_80 -> V_30 == 0 )
return - V_56 ;
if ( V_83 & 1 ) {
V_85 = F_39 ( V_80 , V_84 ) ;
if ( V_85 < 0 )
return V_85 ;
V_80 -> V_30 -- ;
V_80 -> V_31 ++ ;
}
V_83 >>= 1 ;
V_84 ++ ;
}
return 0 ;
}
static int F_41 ( struct V_79 * V_80 )
{
T_1 V_86 = V_80 -> V_86 ;
T_1 V_84 = V_80 -> V_84 ;
int V_85 ;
while ( V_86 ) {
if ( V_80 -> V_30 == 0 )
return - V_56 ;
V_85 = F_39 ( V_80 , V_84 ) ;
if ( V_85 < 0 )
return V_85 ;
V_84 ++ ;
V_80 -> V_30 -- ;
V_80 -> V_31 ++ ;
V_86 -- ;
}
return 0 ;
}
static int F_42 ( struct V_79 * V_80 )
{
T_1 V_86 = V_80 -> V_86 ;
int V_85 ;
while ( V_86 ) {
if ( V_80 -> V_30 == 0 )
return - V_56 ;
V_85 = F_39 ( V_80 , V_80 -> V_84 ) ;
if ( V_85 < 0 )
return V_85 ;
V_80 -> V_30 -- ;
V_80 -> V_31 ++ ;
V_86 -- ;
}
return 0 ;
}
static int F_43 ( struct V_79 * V_80 , struct V_14 * V_58 )
{
T_1 * V_87 = ( T_1 * ) V_80 -> V_7 -> V_88 +
( V_58 -> V_31 / sizeof( T_1 ) ) ;
int V_50 = 0 ;
if ( ! V_80 -> V_7 -> V_81 )
return 0 ;
V_80 -> V_30 = V_58 -> V_30 ;
V_80 -> V_75 = V_58 -> V_29 ;
V_80 -> V_31 = 0 ;
while ( V_80 -> V_30 && ! V_50 ) {
T_1 V_89 = V_87 [ V_80 -> V_31 ] ;
T_1 V_90 = ( V_89 & 0xf0000000 ) >> 28 ;
V_80 -> V_83 = 0 ;
V_80 -> V_84 = 0 ;
V_80 -> V_86 = 0 ;
V_80 -> V_30 -- ;
V_80 -> V_31 ++ ;
switch ( V_90 ) {
case 0 :
V_80 -> V_82 = V_89 >> 6 & 0x3ff ;
V_80 -> V_83 = V_89 & 0x3f ;
V_80 -> V_84 = V_89 >> 16 & 0xfff ;
V_50 = F_40 ( V_80 ) ;
if ( V_50 )
goto V_91;
break;
case 1 :
V_80 -> V_84 = V_89 >> 16 & 0xfff ;
V_80 -> V_86 = V_89 & 0xffff ;
V_50 = F_41 ( V_80 ) ;
if ( V_50 )
goto V_91;
break;
case 2 :
V_80 -> V_84 = V_89 >> 16 & 0xfff ;
V_80 -> V_86 = V_89 & 0xffff ;
V_50 = F_42 ( V_80 ) ;
if ( V_50 )
goto V_91;
break;
case 3 :
V_80 -> V_83 = V_89 & 0xffff ;
V_80 -> V_84 = V_89 >> 16 & 0xfff ;
V_50 = F_40 ( V_80 ) ;
if ( V_50 )
goto V_91;
break;
case 4 :
case 5 :
case 14 :
break;
default:
V_50 = - V_56 ;
break;
}
}
V_91:
return V_50 ;
}
static inline int F_44 ( struct V_1 * V_7 , struct V_92 * V_48 )
{
struct V_79 V_80 ;
T_3 V_74 = 0 ;
T_3 V_31 = 0 ;
int V_43 ;
V_80 . V_7 = V_7 ;
V_80 . V_48 = V_48 ;
V_80 . V_51 = V_7 -> V_20 ;
V_80 . V_5 = V_7 -> V_5 ;
V_80 . V_82 = 0 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_58 = & V_7 -> V_23 [ V_43 ] ;
V_74 += V_58 -> V_30 * sizeof( T_1 ) ;
}
V_7 -> V_88 = F_45 ( V_48 , V_74 , & V_7 -> V_93 ,
V_17 ) ;
if ( ! V_7 -> V_88 ) {
V_7 -> V_88 = NULL ;
return - V_70 ;
}
V_7 -> V_94 = V_74 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_58 = & V_7 -> V_23 [ V_43 ] ;
void * V_95 ;
V_95 = F_46 ( V_58 -> V_29 ) ;
memcpy ( V_7 -> V_88 + V_31 , V_95 + V_58 -> V_31 ,
V_58 -> V_30 * sizeof( T_1 ) ) ;
F_47 ( V_58 -> V_29 , V_95 ) ;
V_58 -> V_96 = V_7 -> V_93 ;
V_58 -> V_31 = V_31 ;
if ( F_43 ( & V_80 , V_58 ) )
return - V_56 ;
V_31 += V_58 -> V_30 * sizeof( T_1 ) ;
}
if ( V_80 . V_5 )
return - V_56 ;
return 0 ;
}
int F_48 ( struct V_1 * V_7 , struct V_92 * V_48 )
{
int V_50 ;
unsigned int V_43 , V_65 ;
struct V_40 * V_41 = F_49 ( V_48 -> V_97 ) ;
F_50 ( V_98 , F_19 ( V_41 ) ) ;
F_51 ( V_98 , F_19 ( V_41 ) ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_44 ; V_43 ++ ) {
T_1 V_46 = V_7 -> V_22 [ V_43 ] . V_46 ;
if ( V_46 < F_19 ( V_41 ) )
F_52 ( V_46 , V_98 ) ;
}
F_53 (i, waitchk_mask, host1x_syncpt_nb_pts(host))
F_54 ( V_41 -> V_99 + V_43 ) ;
V_50 = F_24 ( V_41 , V_7 ) ;
if ( V_50 )
goto V_91;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_58 = & V_7 -> V_23 [ V_43 ] ;
if ( V_58 -> V_100 )
continue;
V_58 -> V_96 = V_7 -> V_26 [ V_43 ] ;
for ( V_65 = V_43 + 1 ; V_65 < V_7 -> V_33 ; V_65 ++ ) {
if ( V_7 -> V_23 [ V_65 ] . V_29 == V_58 -> V_29 ) {
V_7 -> V_23 [ V_65 ] . V_100 = true ;
V_7 -> V_23 [ V_65 ] . V_96 = V_58 -> V_96 ;
}
}
V_50 = F_36 ( V_7 , V_58 -> V_29 ) ;
if ( V_50 )
break;
V_50 = F_17 ( V_7 , V_41 , V_58 -> V_29 ) ;
if ( V_50 )
break;
}
if ( F_27 ( V_66 ) && ! V_50 ) {
V_50 = F_44 ( V_7 , V_48 ) ;
if ( V_50 ) {
F_35 ( V_7 ) ;
return V_50 ;
}
}
V_91:
F_55 () ;
return V_50 ;
}
void F_35 ( struct V_1 * V_7 )
{
struct V_40 * V_41 = F_49 ( V_7 -> V_19 -> V_48 -> V_97 ) ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_8 ; V_43 ++ ) {
struct V_12 * V_57 = & V_7 -> V_21 [ V_43 ] ;
if ( ! F_27 ( V_66 ) && V_41 -> V_67 ) {
F_56 ( V_41 -> V_67 , V_7 -> V_24 [ V_43 ] ,
V_57 -> V_74 ) ;
F_57 ( & V_41 -> V_63 ,
F_58 ( & V_41 -> V_63 , V_7 -> V_24 [ V_43 ] ) ) ;
}
F_59 ( V_57 -> V_29 , V_57 -> V_53 ) ;
F_60 ( V_57 -> V_29 ) ;
}
V_7 -> V_8 = 0 ;
if ( V_7 -> V_94 )
F_61 ( V_7 -> V_19 -> V_48 , V_7 -> V_94 ,
V_7 -> V_88 , V_7 -> V_93 ) ;
}
void F_62 ( struct V_92 * V_48 , struct V_1 * V_7 )
{
F_23 ( V_48 , L_4 , V_7 -> V_46 ) ;
F_23 ( V_48 , L_5 , V_7 -> V_101 ) ;
F_23 ( V_48 , L_6 , V_7 -> V_102 ) ;
F_23 ( V_48 , L_7 , V_7 -> V_103 ) ;
F_23 ( V_48 , L_8 , V_7 -> V_104 ) ;
F_23 ( V_48 , L_9 , V_7 -> V_8 ) ;
}
