struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 = NULL ;
unsigned int V_8 = V_4 + V_5 ;
T_2 V_9 ;
void * V_10 ;
V_9 = sizeof( struct V_1 ) +
V_5 * sizeof( struct V_11 ) +
V_8 * sizeof( struct V_12 ) +
V_6 * sizeof( struct V_13 ) +
V_4 * sizeof( struct V_14 ) +
V_8 * sizeof( V_15 ) +
V_8 * sizeof( T_1 * ) ;
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
V_50 -> V_54 = F_25 ( V_50 -> V_54 ) ;
if ( ! V_50 -> V_54 )
goto V_55;
V_53 = F_26 ( V_50 -> V_54 , & V_52 ) ;
if ( ! V_53 )
goto V_55;
V_7 -> V_24 [ V_7 -> V_8 ] = V_53 ;
V_7 -> V_21 [ V_7 -> V_8 ] . V_29 = V_50 -> V_54 ;
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
static unsigned int F_28 ( struct V_1 * V_7 , struct V_28 * V_57 )
{
int V_43 = 0 ;
T_1 V_58 = ~ 0 ;
void * V_59 = NULL ;
while ( V_43 < V_7 -> V_5 ) {
struct V_11 * V_50 = & V_7 -> V_20 [ V_43 ] ;
T_1 V_60 = ( V_7 -> V_25 [ V_43 ] +
V_50 -> V_61 ) >> V_50 -> V_62 ;
T_1 * V_54 ;
if ( ! ( V_50 -> V_57 && V_57 == V_50 -> V_57 ) ) {
V_43 ++ ;
continue;
}
if ( V_58 != V_50 -> V_63 >> V_38 ) {
if ( V_59 )
F_15 ( V_57 , V_58 ,
V_59 ) ;
V_59 = F_13 ( V_57 ,
V_50 -> V_63 >> V_38 ) ;
V_58 = V_50 -> V_63 >> V_38 ;
if ( F_29 ( ! V_59 ) ) {
F_16 ( L_3 ) ;
return - V_64 ;
}
}
V_54 = V_59 + ( V_50 -> V_63 & ~ V_39 ) ;
* V_54 = V_60 ;
V_50 -> V_57 = 0 ;
}
if ( V_59 )
F_15 ( V_57 , V_58 , V_59 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_50 , struct V_28 * V_57 ,
unsigned int V_31 )
{
V_31 *= sizeof( T_1 ) ;
if ( V_50 -> V_57 != V_57 || V_50 -> V_63 != V_31 )
return - V_65 ;
return 0 ;
}
static int F_31 ( struct V_66 * V_67 )
{
T_1 V_68 = V_67 -> V_68 ;
T_1 V_69 = V_67 -> V_69 ;
while ( V_68 ) {
if ( V_67 -> V_30 == 0 )
return - V_65 ;
if ( V_68 & 1 ) {
if ( V_67 -> V_7 -> V_70 ( V_67 -> V_48 , V_67 -> V_71 , V_69 ) ) {
bool V_72 = F_30 ( V_67 -> V_50 ,
V_67 -> V_73 ,
V_67 -> V_31 ) ;
if ( ! V_67 -> V_5 || V_72 )
return - V_65 ;
V_67 -> V_50 ++ ;
V_67 -> V_5 -- ;
}
V_67 -> V_30 -- ;
V_67 -> V_31 ++ ;
}
V_68 >>= 1 ;
V_69 ++ ;
}
return 0 ;
}
static int F_32 ( struct V_66 * V_67 )
{
T_1 V_74 = V_67 -> V_74 ;
T_1 V_69 = V_67 -> V_69 ;
while ( V_67 ) {
if ( V_67 -> V_30 == 0 )
return - V_65 ;
if ( V_67 -> V_7 -> V_70 ( V_67 -> V_48 , V_67 -> V_71 , V_69 ) ) {
bool V_72 = F_30 ( V_67 -> V_50 , V_67 -> V_73 ,
V_67 -> V_31 ) ;
if ( ! V_67 -> V_5 || V_72 )
return - V_65 ;
V_67 -> V_50 ++ ;
V_67 -> V_5 -- ;
}
V_69 ++ ;
V_67 -> V_30 -- ;
V_67 -> V_31 ++ ;
V_74 -- ;
}
return 0 ;
}
static int F_33 ( struct V_66 * V_67 )
{
int V_70 = V_67 -> V_7 -> V_70 ( V_67 -> V_48 , V_67 -> V_71 , V_67 -> V_69 ) ;
T_1 V_74 = V_67 -> V_74 ;
while ( V_74 ) {
if ( V_67 -> V_30 == 0 )
return - V_65 ;
if ( V_70 ) {
bool V_72 = F_30 ( V_67 -> V_50 , V_67 -> V_73 ,
V_67 -> V_31 ) ;
if ( ! V_67 -> V_5 || V_72 )
return - V_65 ;
V_67 -> V_50 ++ ;
V_67 -> V_5 -- ;
}
V_67 -> V_30 -- ;
V_67 -> V_31 ++ ;
V_74 -- ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_7 , struct V_75 * V_48 ,
struct V_14 * V_56 )
{
T_1 * V_76 ;
int V_77 = 0 ;
struct V_66 V_67 ;
V_67 . V_7 = V_7 ;
V_67 . V_48 = V_48 ;
V_67 . V_50 = V_7 -> V_20 ;
V_67 . V_5 = V_7 -> V_5 ;
V_67 . V_73 = V_56 -> V_29 ;
V_67 . V_31 = 0 ;
V_67 . V_71 = 0 ;
if ( ! V_7 -> V_70 )
return 0 ;
V_76 = F_35 ( V_56 -> V_29 ) ;
if ( ! V_76 )
return - V_64 ;
V_67 . V_30 = V_56 -> V_30 ;
while ( V_67 . V_30 && ! V_77 ) {
T_1 V_78 = V_76 [ V_67 . V_31 ] ;
T_1 V_79 = ( V_78 & 0xf0000000 ) >> 28 ;
V_67 . V_68 = 0 ;
V_67 . V_69 = 0 ;
V_67 . V_74 = 0 ;
V_67 . V_30 -- ;
V_67 . V_31 ++ ;
switch ( V_79 ) {
case 0 :
V_67 . V_71 = V_78 >> 6 & 0x3ff ;
V_67 . V_68 = V_78 & 0x3f ;
V_67 . V_69 = V_78 >> 16 & 0xfff ;
V_77 = F_31 ( & V_67 ) ;
if ( V_77 )
goto V_80;
break;
case 1 :
V_67 . V_69 = V_78 >> 16 & 0xfff ;
V_67 . V_74 = V_78 & 0xffff ;
V_77 = F_32 ( & V_67 ) ;
if ( V_77 )
goto V_80;
break;
case 2 :
V_67 . V_69 = V_78 >> 16 & 0xfff ;
V_67 . V_74 = V_78 & 0xffff ;
V_77 = F_33 ( & V_67 ) ;
if ( V_77 )
goto V_80;
break;
case 3 :
V_67 . V_68 = V_78 & 0xffff ;
V_67 . V_69 = V_78 >> 16 & 0xfff ;
V_77 = F_31 ( & V_67 ) ;
if ( V_77 )
goto V_80;
break;
case 4 :
case 5 :
case 14 :
break;
default:
V_77 = - V_65 ;
break;
}
}
if ( V_67 . V_5 )
V_77 = - V_65 ;
V_80:
F_36 ( V_56 -> V_29 , V_76 ) ;
return V_77 ;
}
static inline int F_37 ( struct V_1 * V_7 , struct V_75 * V_48 )
{
T_3 V_81 = 0 ;
T_3 V_31 = 0 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
V_81 += V_56 -> V_30 * sizeof( T_1 ) ;
}
V_7 -> V_82 = F_38 ( V_48 , V_81 ,
& V_7 -> V_83 ,
V_17 ) ;
if ( ! V_7 -> V_82 ) {
int V_77 = F_39 ( V_7 -> V_82 ) ;
V_7 -> V_82 = NULL ;
return V_77 ;
}
V_7 -> V_84 = V_81 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
void * V_85 ;
V_85 = F_35 ( V_56 -> V_29 ) ;
memcpy ( V_7 -> V_82 + V_31 , V_85 + V_56 -> V_31 ,
V_56 -> V_30 * sizeof( T_1 ) ) ;
F_36 ( V_56 -> V_29 , V_85 ) ;
V_56 -> V_86 = V_7 -> V_83 ;
V_56 -> V_31 = V_31 ;
V_56 -> V_29 = NULL ;
V_31 += V_56 -> V_30 * sizeof( T_1 ) ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_7 , struct V_75 * V_48 )
{
int V_77 ;
unsigned int V_43 , V_87 ;
struct V_40 * V_41 = F_41 ( V_48 -> V_88 ) ;
F_42 ( V_89 , F_19 ( V_41 ) ) ;
F_43 ( V_89 , F_19 ( V_41 ) ) ;
for ( V_43 = 0 ; V_43 < V_7 -> V_44 ; V_43 ++ ) {
T_1 V_46 = V_7 -> V_22 [ V_43 ] . V_46 ;
if ( V_46 < F_19 ( V_41 ) )
F_44 ( V_46 , V_89 ) ;
}
F_45 (i, waitchk_mask, host1x_syncpt_nb_pts(host))
F_46 ( V_41 -> V_90 + V_43 ) ;
V_77 = F_24 ( V_7 ) ;
if ( ! V_77 )
goto V_80;
for ( V_43 = 0 ; V_43 < V_7 -> V_33 ; V_43 ++ ) {
struct V_14 * V_56 = & V_7 -> V_23 [ V_43 ] ;
if ( V_56 -> V_91 )
continue;
V_56 -> V_86 = V_7 -> V_26 [ V_43 ] ;
for ( V_87 = 0 ; V_87 < V_7 -> V_33 ; V_87 ++ )
if ( V_7 -> V_23 [ V_87 ] . V_29 == V_56 -> V_29 )
V_7 -> V_23 [ V_87 ] . V_91 = true ;
V_77 = 0 ;
if ( F_47 ( V_92 ) )
V_77 = F_34 ( V_7 , V_48 , V_56 ) ;
if ( V_77 )
F_48 ( V_48 , L_4 , V_77 ) ;
if ( ! V_77 )
V_77 = F_28 ( V_7 , V_56 -> V_29 ) ;
if ( ! V_77 )
V_77 = F_17 ( V_7 , V_41 , V_56 -> V_29 ) ;
if ( V_77 )
break;
}
if ( F_47 ( V_92 ) && ! V_77 ) {
V_77 = F_37 ( V_7 , V_48 ) ;
if ( V_77 ) {
F_27 ( V_7 ) ;
return V_77 ;
}
}
V_80:
F_49 () ;
return V_77 ;
}
void F_27 ( struct V_1 * V_7 )
{
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < V_7 -> V_8 ; V_43 ++ ) {
struct V_12 * V_55 = & V_7 -> V_21 [ V_43 ] ;
F_50 ( V_55 -> V_29 , V_55 -> V_52 ) ;
F_51 ( V_55 -> V_29 ) ;
}
V_7 -> V_8 = 0 ;
if ( V_7 -> V_84 )
F_52 ( V_7 -> V_19 -> V_48 , V_7 -> V_84 ,
V_7 -> V_82 ,
V_7 -> V_83 ) ;
}
void F_53 ( struct V_75 * V_48 , struct V_1 * V_7 )
{
F_23 ( V_48 , L_5 , V_7 -> V_46 ) ;
F_23 ( V_48 , L_6 , V_7 -> V_93 ) ;
F_23 ( V_48 , L_7 , V_7 -> V_94 ) ;
F_23 ( V_48 , L_8 , V_7 -> V_95 ) ;
F_23 ( V_48 , L_9 , V_7 -> V_96 ) ;
F_23 ( V_48 , L_10 , V_7 -> V_8 ) ;
}
