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
static unsigned int F_24 ( struct V_1 * V_7 )
{
unsigned int V_43 ;
V_7 -> V_8 = 0 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_5 ; V_43 ++ ) {
struct V_11 * V_50 = & V_7 -> V_20 [ V_43 ] ;
struct V_51 * V_52 ;
V_15 V_53 ;
V_50 -> V_54 . V_29 = F_25 ( V_50 -> V_54 . V_29 ) ;
if ( ! V_50 -> V_54 . V_29 )
goto V_55;
V_53 = F_26 ( V_50 -> V_54 . V_29 , & V_52 ) ;
if ( ! V_53 )
goto V_55;
V_7 -> V_24 [ V_7 -> V_8 ] = V_53 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_50 -> V_54 . V_29 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_52 = V_52 ;
V_7 -> V_8 ++ ;
}
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
struct V_51 * V_52 ;
V_15 V_53 ;
V_56 -> V_29 = F_25 ( V_56 -> V_29 ) ;
if ( ! V_56 -> V_29 )
goto V_55;
V_53 = F_26 ( V_56 -> V_29 , & V_52 ) ;
if ( ! V_53 )
goto V_55;
V_7 -> V_24 [ V_7 -> V_8 ] = V_53 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_56 -> V_29 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_52 = V_52 ;
V_7 -> V_8 ++ ;
}
return V_7 -> V_8 ;
V_55:
F_27 ( V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_7 , struct V_28 * V_57 )
{
int V_43 = 0 ;
T_1 V_58 = ~ 0 ;
void * V_59 = NULL ;
for ( V_43 = 0 ; V_43 < V_7 -> V_5 ; V_43 ++ ) {
struct V_11 * V_50 = & V_7 -> V_20 [ V_43 ] ;
T_1 V_60 = ( V_7 -> V_25 [ V_43 ] +
V_50 -> V_54 . V_31 ) >> V_50 -> V_61 ;
T_1 * V_54 ;
if ( V_57 != V_50 -> V_57 . V_29 )
continue;
if ( V_58 != V_50 -> V_57 . V_31 >> V_38 ) {
if ( V_59 )
F_15 ( V_57 , V_58 ,
V_59 ) ;
V_59 = F_13 ( V_57 ,
V_50 -> V_57 . V_31 >> V_38 ) ;
V_58 = V_50 -> V_57 . V_31 >> V_38 ;
if ( F_29 ( ! V_59 ) ) {
F_16 ( L_3 ) ;
return - V_62 ;
}
}
V_54 = V_59 + ( V_50 -> V_57 . V_31 & ~ V_39 ) ;
* V_54 = V_60 ;
}
if ( V_59 )
F_15 ( V_57 , V_58 , V_59 ) ;
return 0 ;
}
static bool F_30 ( struct V_11 * V_50 , struct V_28 * V_57 ,
unsigned int V_31 )
{
V_31 *= sizeof( T_1 ) ;
if ( V_50 -> V_57 . V_29 != V_57 || V_50 -> V_57 . V_31 != V_31 )
return false ;
return true ;
}
static int F_31 ( struct V_63 * V_64 , unsigned long V_31 )
{
if ( V_64 -> V_7 -> V_65 ( V_64 -> V_48 , V_64 -> V_66 , V_31 ) ) {
if ( ! V_64 -> V_5 )
return - V_67 ;
if ( ! F_30 ( V_64 -> V_50 , V_64 -> V_57 , V_64 -> V_31 ) )
return - V_67 ;
V_64 -> V_5 -- ;
V_64 -> V_50 ++ ;
}
return 0 ;
}
static int F_32 ( struct V_63 * V_64 )
{
T_1 V_68 = V_64 -> V_68 ;
T_1 V_69 = V_64 -> V_69 ;
int V_70 ;
while ( V_68 ) {
if ( V_64 -> V_30 == 0 )
return - V_67 ;
if ( V_68 & 1 ) {
V_70 = F_31 ( V_64 , V_69 ) ;
if ( V_70 < 0 )
return V_70 ;
V_64 -> V_30 -- ;
V_64 -> V_31 ++ ;
}
V_68 >>= 1 ;
V_69 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_63 * V_64 )
{
T_1 V_71 = V_64 -> V_71 ;
T_1 V_69 = V_64 -> V_69 ;
int V_70 ;
while ( V_71 ) {
if ( V_64 -> V_30 == 0 )
return - V_67 ;
V_70 = F_31 ( V_64 , V_69 ) ;
if ( V_70 < 0 )
return V_70 ;
V_69 ++ ;
V_64 -> V_30 -- ;
V_64 -> V_31 ++ ;
V_71 -- ;
}
return 0 ;
}
static int F_34 ( struct V_63 * V_64 )
{
T_1 V_71 = V_64 -> V_71 ;
int V_70 ;
while ( V_71 ) {
if ( V_64 -> V_30 == 0 )
return - V_67 ;
V_70 = F_31 ( V_64 , V_64 -> V_69 ) ;
if ( V_70 < 0 )
return V_70 ;
V_64 -> V_30 -- ;
V_64 -> V_31 ++ ;
V_71 -- ;
}
return 0 ;
}
static int F_35 ( struct V_63 * V_64 , struct V_14 * V_56 )
{
T_1 * V_72 = ( T_1 * ) V_64 -> V_7 -> V_73 +
( V_56 -> V_31 / sizeof( T_1 ) ) ;
int V_74 = 0 ;
if ( ! V_64 -> V_7 -> V_65 )
return 0 ;
V_64 -> V_30 = V_56 -> V_30 ;
V_64 -> V_57 = V_56 -> V_29 ;
V_64 -> V_31 = 0 ;
while ( V_64 -> V_30 && ! V_74 ) {
T_1 V_75 = V_72 [ V_64 -> V_31 ] ;
T_1 V_76 = ( V_75 & 0xf0000000 ) >> 28 ;
V_64 -> V_68 = 0 ;
V_64 -> V_69 = 0 ;
V_64 -> V_71 = 0 ;
V_64 -> V_30 -- ;
V_64 -> V_31 ++ ;
switch ( V_76 ) {
case 0 :
V_64 -> V_66 = V_75 >> 6 & 0x3ff ;
V_64 -> V_68 = V_75 & 0x3f ;
V_64 -> V_69 = V_75 >> 16 & 0xfff ;
V_74 = F_32 ( V_64 ) ;
if ( V_74 )
goto V_77;
break;
case 1 :
V_64 -> V_69 = V_75 >> 16 & 0xfff ;
V_64 -> V_71 = V_75 & 0xffff ;
V_74 = F_33 ( V_64 ) ;
if ( V_74 )
goto V_77;
break;
case 2 :
V_64 -> V_69 = V_75 >> 16 & 0xfff ;
V_64 -> V_71 = V_75 & 0xffff ;
V_74 = F_34 ( V_64 ) ;
if ( V_74 )
goto V_77;
break;
case 3 :
V_64 -> V_68 = V_75 & 0xffff ;
V_64 -> V_69 = V_75 >> 16 & 0xfff ;
V_74 = F_32 ( V_64 ) ;
if ( V_74 )
goto V_77;
break;
case 4 :
case 5 :
case 14 :
break;
default:
V_74 = - V_67 ;
break;
}
}
V_77:
return V_74 ;
}
static inline int F_36 ( struct V_1 * V_7 , struct V_78 * V_48 )
{
struct V_63 V_64 ;
T_3 V_79 = 0 ;
T_3 V_31 = 0 ;
int V_43 ;
V_64 . V_7 = V_7 ;
V_64 . V_48 = V_48 ;
V_64 . V_50 = V_7 -> V_20 ;
V_64 . V_5 = V_7 -> V_5 ;
V_64 . V_66 = 0 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
V_79 += V_56 -> V_30 * sizeof( T_1 ) ;
}
V_7 -> V_73 = F_37 ( V_48 , V_79 , & V_7 -> V_80 ,
V_17 ) ;
if ( ! V_7 -> V_73 ) {
V_7 -> V_73 = NULL ;
return - V_62 ;
}
V_7 -> V_81 = V_79 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
void * V_82 ;
V_82 = F_38 ( V_56 -> V_29 ) ;
memcpy ( V_7 -> V_73 + V_31 , V_82 + V_56 -> V_31 ,
V_56 -> V_30 * sizeof( T_1 ) ) ;
F_39 ( V_56 -> V_29 , V_82 ) ;
V_56 -> V_83 = V_7 -> V_80 ;
V_56 -> V_31 = V_31 ;
if ( F_35 ( & V_64 , V_56 ) )
return - V_67 ;
V_31 += V_56 -> V_30 * sizeof( T_1 ) ;
}
if ( V_64 . V_5 )
return - V_67 ;
return 0 ;
}
int F_40 ( struct V_1 * V_7 , struct V_78 * V_48 )
{
int V_74 ;
unsigned int V_43 , V_84 ;
struct V_40 * V_41 = F_41 ( V_48 -> V_85 ) ;
F_42 ( V_86 , F_19 ( V_41 ) ) ;
F_43 ( V_86 , F_19 ( V_41 ) ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_44 ; V_43 ++ ) {
T_1 V_46 = V_7 -> V_22 [ V_43 ] . V_46 ;
if ( V_46 < F_19 ( V_41 ) )
F_44 ( V_46 , V_86 ) ;
}
F_45 (i, waitchk_mask, host1x_syncpt_nb_pts(host))
F_46 ( V_41 -> V_87 + V_43 ) ;
V_74 = F_24 ( V_7 ) ;
if ( ! V_74 )
goto V_77;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
if ( V_56 -> V_88 )
continue;
V_56 -> V_83 = V_7 -> V_26 [ V_43 ] ;
for ( V_84 = V_43 + 1 ; V_84 < V_7 -> V_33 ; V_84 ++ )
if ( V_7 -> V_23 [ V_84 ] . V_29 == V_56 -> V_29 )
V_7 -> V_23 [ V_84 ] . V_88 = true ;
V_74 = F_28 ( V_7 , V_56 -> V_29 ) ;
if ( V_74 )
break;
V_74 = F_17 ( V_7 , V_41 , V_56 -> V_29 ) ;
if ( V_74 )
break;
}
if ( F_47 ( V_89 ) && ! V_74 ) {
V_74 = F_36 ( V_7 , V_48 ) ;
if ( V_74 ) {
F_27 ( V_7 ) ;
return V_74 ;
}
}
V_77:
F_48 () ;
return V_74 ;
}
void F_27 ( struct V_1 * V_7 )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_8 ; V_43 ++ ) {
struct V_12 * V_55 = & V_7 -> V_21 [ V_43 ] ;
F_49 ( V_55 -> V_29 , V_55 -> V_52 ) ;
F_50 ( V_55 -> V_29 ) ;
}
V_7 -> V_8 = 0 ;
if ( V_7 -> V_81 )
F_51 ( V_7 -> V_19 -> V_48 , V_7 -> V_81 ,
V_7 -> V_73 , V_7 -> V_80 ) ;
}
void F_52 ( struct V_78 * V_48 , struct V_1 * V_7 )
{
F_23 ( V_48 , L_4 , V_7 -> V_46 ) ;
F_23 ( V_48 , L_5 , V_7 -> V_90 ) ;
F_23 ( V_48 , L_6 , V_7 -> V_91 ) ;
F_23 ( V_48 , L_7 , V_7 -> V_92 ) ;
F_23 ( V_48 , L_8 , V_7 -> V_93 ) ;
F_23 ( V_48 , L_9 , V_7 -> V_8 ) ;
}
