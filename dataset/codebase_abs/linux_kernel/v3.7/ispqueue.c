static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return;
if ( V_2 -> V_4 . V_5 . V_6 == 0 || V_2 -> V_7 == 0 ||
V_2 -> V_7 > V_8 )
F_2 () ;
else {
F_3 ( ( void * ) V_2 -> V_4 . V_5 . V_6 , V_2 -> V_4 . V_9 ,
V_10 ) ;
F_4 ( V_2 -> V_4 . V_5 . V_6 ,
V_2 -> V_4 . V_5 . V_6 + V_2 -> V_4 . V_9 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
int V_16 = 0 ;
if ( V_2 -> V_4 . V_17 == V_18 )
return 0 ;
if ( ! V_19 || ! V_19 -> V_20 )
return V_11 ? - V_21 : 0 ;
V_14 = V_2 -> V_4 . V_5 . V_6 ;
V_15 = V_2 -> V_4 . V_5 . V_6 + V_2 -> V_4 . V_9 - 1 ;
F_6 ( & V_19 -> V_20 -> V_22 ) ;
F_7 ( & V_19 -> V_20 -> V_23 ) ;
do {
V_13 = F_8 ( V_19 -> V_20 , V_14 ) ;
if ( V_13 == NULL ) {
V_16 = - V_24 ;
goto V_25;
}
if ( V_11 )
V_13 -> V_26 |= V_27 ;
else
V_13 -> V_26 &= ~ V_27 ;
V_14 = V_13 -> V_28 + 1 ;
} while ( V_13 -> V_28 < V_15 );
if ( V_11 )
V_2 -> V_26 |= V_27 ;
else
V_2 -> V_26 &= ~ V_27 ;
V_25:
F_9 ( & V_19 -> V_20 -> V_23 ) ;
F_10 ( & V_19 -> V_20 -> V_22 ) ;
return V_16 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
unsigned int V_7 ;
unsigned int V_31 ;
void * V_32 ;
V_32 = V_2 -> V_33 ;
V_7 = F_12 ( V_2 -> V_4 . V_9 ) >> V_34 ;
V_30 = F_13 ( V_7 * sizeof( * V_30 ) ) ;
if ( V_30 == NULL )
return - V_35 ;
F_14 ( V_30 , V_7 ) ;
for ( V_31 = 0 ; V_31 < V_7 ; ++ V_31 , V_32 += V_36 ) {
struct V_37 * V_37 = F_15 ( V_32 ) ;
if ( V_37 == NULL || F_16 ( V_37 ) ) {
F_17 ( V_30 ) ;
return - V_21 ;
}
F_18 ( & V_30 [ V_31 ] , V_37 , V_36 , 0 ) ;
}
V_2 -> V_38 = V_7 ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
unsigned int V_39 = V_2 -> V_39 ;
unsigned int V_31 ;
V_30 = F_13 ( V_2 -> V_7 * sizeof( * V_30 ) ) ;
if ( V_30 == NULL )
return - V_35 ;
F_14 ( V_30 , V_2 -> V_7 ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; ++ V_31 ) {
if ( F_16 ( V_2 -> V_40 [ V_31 ] ) ) {
F_17 ( V_30 ) ;
return - V_21 ;
}
F_18 ( & V_30 [ V_31 ] , V_2 -> V_40 [ V_31 ] , V_36 - V_39 ,
V_39 ) ;
V_39 = 0 ;
}
V_2 -> V_38 = V_2 -> V_7 ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
unsigned int V_39 = V_2 -> V_39 ;
unsigned long V_41 = V_2 -> V_42 >> V_34 ;
unsigned int V_31 ;
V_30 = F_13 ( V_2 -> V_7 * sizeof( * V_30 ) ) ;
if ( V_30 == NULL )
return - V_35 ;
F_14 ( V_30 , V_2 -> V_7 ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; ++ V_31 , ++ V_41 ) {
F_18 ( & V_30 [ V_31 ] , F_21 ( V_41 ) , V_36 - V_39 ,
V_39 ) ;
F_22 ( & V_30 [ V_31 ] ) = ( V_41 << V_34 ) + V_39 ;
V_39 = 0 ;
}
V_2 -> V_38 = V_2 -> V_7 ;
V_2 -> V_30 = V_30 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
enum V_43 V_44 ;
unsigned int V_31 ;
if ( V_2 -> V_45 -> V_46 -> V_47 )
V_2 -> V_45 -> V_46 -> V_47 ( V_2 ) ;
if ( ! ( V_2 -> V_26 & V_48 ) ) {
V_44 = V_2 -> V_4 . type == V_49
? V_10 : V_50 ;
F_24 ( V_2 -> V_45 -> V_51 , V_2 -> V_30 , V_2 -> V_38 ,
V_44 ) ;
}
F_17 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_38 = 0 ;
if ( V_2 -> V_40 != NULL ) {
F_5 ( V_2 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_7 ; ++ V_31 )
F_25 ( V_2 -> V_40 [ V_31 ] ) ;
F_17 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
}
V_2 -> V_7 = 0 ;
V_2 -> V_3 = false ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_52 ;
unsigned int V_53 ;
unsigned int V_54 ;
int V_16 ;
V_52 = V_2 -> V_4 . V_5 . V_6 ;
V_53 = ( V_52 & V_55 ) >> V_34 ;
V_54 = ( ( V_52 + V_2 -> V_4 . V_9 - 1 ) & V_55 ) >> V_34 ;
V_2 -> V_39 = V_52 & ~ V_55 ;
V_2 -> V_7 = V_54 - V_53 + 1 ;
V_2 -> V_40 = F_13 ( V_2 -> V_7 * sizeof( V_2 -> V_40 [ 0 ] ) ) ;
if ( V_2 -> V_40 == NULL )
return - V_35 ;
F_27 ( & V_19 -> V_20 -> V_22 ) ;
V_16 = F_28 ( V_19 , V_19 -> V_20 , V_52 & V_55 ,
V_2 -> V_7 ,
V_2 -> V_4 . type == V_49 , 0 ,
V_2 -> V_40 , NULL ) ;
F_29 ( & V_19 -> V_20 -> V_22 ) ;
if ( V_16 != V_2 -> V_7 ) {
V_2 -> V_7 = V_16 < 0 ? 0 : V_16 ;
F_23 ( V_2 ) ;
return - V_24 ;
}
V_16 = F_5 ( V_2 , 1 ) ;
if ( V_16 < 0 )
F_23 ( V_2 ) ;
return V_16 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
unsigned long V_56 ;
unsigned long V_57 ;
unsigned long V_14 ;
unsigned long V_15 ;
T_1 V_58 ;
int V_16 = - V_24 ;
V_14 = V_2 -> V_4 . V_5 . V_6 ;
V_15 = V_2 -> V_4 . V_5 . V_6 + V_2 -> V_4 . V_9 - 1 ;
V_2 -> V_39 = V_14 & ~ V_55 ;
V_2 -> V_7 = ( V_15 >> V_34 ) - ( V_14 >> V_34 ) + 1 ;
V_2 -> V_40 = NULL ;
F_27 ( & V_19 -> V_20 -> V_22 ) ;
V_13 = F_8 ( V_19 -> V_20 , V_14 ) ;
if ( V_13 == NULL || V_13 -> V_28 < V_15 )
goto V_59;
for ( V_56 = 0 ; V_14 <= V_15 ; V_14 += V_36 ) {
V_16 = F_31 ( V_13 , V_14 , & V_57 ) ;
if ( V_16 )
goto V_59;
if ( V_56 == 0 )
V_58 = V_57 << V_34 ;
else if ( V_57 != V_56 + 1 ) {
V_16 = - V_24 ;
goto V_59;
}
V_56 = V_57 ;
}
V_2 -> V_42 = V_58 + V_2 -> V_39 ;
V_16 = 0 ;
V_59:
F_29 ( & V_19 -> V_20 -> V_22 ) ;
return V_16 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
T_2 V_60 ;
unsigned long V_14 ;
unsigned long V_15 ;
int V_16 = - V_24 ;
V_14 = V_2 -> V_4 . V_5 . V_6 ;
V_15 = V_2 -> V_4 . V_5 . V_6 + V_2 -> V_4 . V_9 - 1 ;
F_27 ( & V_19 -> V_20 -> V_22 ) ;
do {
V_13 = F_8 ( V_19 -> V_20 , V_14 ) ;
if ( V_13 == NULL )
goto V_59;
if ( V_14 == V_2 -> V_4 . V_5 . V_6 ) {
V_2 -> V_26 = V_13 -> V_26 ;
V_60 = V_13 -> V_60 ;
}
if ( ( V_2 -> V_26 ^ V_13 -> V_26 ) & V_48 )
goto V_59;
if ( V_60 != V_13 -> V_60 )
goto V_59;
V_14 = V_13 -> V_28 + 1 ;
} while ( V_13 -> V_28 < V_15 );
if ( V_60 == F_33 ( V_60 ) ||
V_60 == F_34 ( V_60 ) )
V_2 -> V_3 = true ;
V_16 = 0 ;
V_59:
F_29 ( & V_19 -> V_20 -> V_22 ) ;
return V_16 ;
}
static int F_35 ( struct V_1 * V_2 )
{
enum V_43 V_44 ;
int V_16 ;
switch ( V_2 -> V_4 . V_17 ) {
case V_18 :
V_16 = F_11 ( V_2 ) ;
break;
case V_61 :
V_16 = F_32 ( V_2 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_2 -> V_26 & V_48 ) {
V_16 = F_30 ( V_2 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_20 ( V_2 ) ;
} else {
V_16 = F_26 ( V_2 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_19 ( V_2 ) ;
}
break;
default:
return - V_21 ;
}
if ( V_16 < 0 )
goto V_59;
if ( ! ( V_2 -> V_26 & V_48 ) ) {
V_44 = V_2 -> V_4 . type == V_49
? V_10 : V_50 ;
V_16 = F_36 ( V_2 -> V_45 -> V_51 , V_2 -> V_30 , V_2 -> V_38 ,
V_44 ) ;
if ( V_16 != V_2 -> V_38 ) {
V_16 = - V_24 ;
goto V_59;
}
}
if ( V_2 -> V_45 -> V_46 -> V_62 )
V_16 = V_2 -> V_45 -> V_46 -> V_62 ( V_2 ) ;
V_59:
if ( V_16 < 0 ) {
F_23 ( V_2 ) ;
return V_16 ;
}
return V_16 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_63 * V_4 )
{
memcpy ( V_4 , & V_2 -> V_4 , sizeof( * V_4 ) ) ;
if ( V_2 -> V_64 )
V_4 -> V_65 |= V_66 ;
switch ( V_2 -> V_67 ) {
case V_68 :
V_4 -> V_65 |= V_69 ;
case V_70 :
V_4 -> V_65 |= V_71 ;
case V_72 :
case V_73 :
V_4 -> V_65 |= V_74 ;
break;
case V_75 :
default:
break;
}
}
static int F_38 ( struct V_1 * V_2 , int V_76 )
{
if ( V_76 ) {
return ( V_2 -> V_67 != V_72 &&
V_2 -> V_67 != V_73 )
? 0 : - V_77 ;
}
return F_39 ( V_2 -> V_78 ,
V_2 -> V_67 != V_72 &&
V_2 -> V_67 != V_73 ) ;
}
static int F_40 ( struct V_79 * V_45 )
{
unsigned int V_31 ;
if ( V_45 -> V_80 )
return - V_81 ;
for ( V_31 = 0 ; V_31 < V_45 -> V_82 ; ++ V_31 ) {
if ( V_45 -> V_83 [ V_31 ] -> V_64 != 0 )
return - V_81 ;
}
for ( V_31 = 0 ; V_31 < V_45 -> V_82 ; ++ V_31 ) {
struct V_1 * V_2 = V_45 -> V_83 [ V_31 ] ;
F_23 ( V_2 ) ;
F_17 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
F_41 ( V_2 ) ;
V_45 -> V_83 [ V_31 ] = NULL ;
}
F_42 ( & V_45 -> V_45 ) ;
V_45 -> V_82 = 0 ;
return 0 ;
}
static int F_43 ( struct V_79 * V_45 ,
unsigned int V_84 ,
unsigned int V_85 , enum V_86 V_17 )
{
struct V_1 * V_2 ;
unsigned int V_31 ;
void * V_87 ;
int V_16 ;
V_16 = F_40 ( V_45 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_84 == 0 )
return 0 ;
for ( V_31 = 0 ; V_31 < V_84 ; ++ V_31 ) {
V_2 = F_44 ( V_45 -> V_88 , V_89 ) ;
if ( V_2 == NULL )
break;
if ( V_17 == V_18 ) {
V_87 = F_45 ( F_12 ( V_85 ) ) ;
if ( V_87 == NULL ) {
F_41 ( V_2 ) ;
break;
}
V_2 -> V_4 . V_5 . V_39 = V_31 * F_12 ( V_85 ) ;
V_2 -> V_33 = V_87 ;
}
V_2 -> V_4 . V_90 = V_31 ;
V_2 -> V_4 . V_9 = V_85 ;
V_2 -> V_4 . type = V_45 -> type ;
V_2 -> V_4 . V_91 = V_92 ;
V_2 -> V_4 . V_17 = V_17 ;
V_2 -> V_45 = V_45 ;
F_46 ( & V_2 -> V_78 ) ;
V_45 -> V_83 [ V_31 ] = V_2 ;
}
if ( V_31 == 0 )
return - V_35 ;
V_45 -> V_82 = V_31 ;
return V_84 ;
}
int F_47 ( struct V_79 * V_45 )
{
return F_40 ( V_45 ) ;
}
int F_48 ( struct V_79 * V_45 ,
enum V_93 type ,
const struct V_94 * V_46 ,
struct V_95 * V_51 , unsigned int V_88 )
{
F_42 ( & V_45 -> V_45 ) ;
F_49 ( & V_45 -> V_11 ) ;
F_50 ( & V_45 -> V_96 ) ;
V_45 -> type = type ;
V_45 -> V_46 = V_46 ;
V_45 -> V_51 = V_51 ;
V_45 -> V_88 = V_88 ;
return 0 ;
}
int F_51 ( struct V_79 * V_45 ,
struct V_97 * V_98 )
{
unsigned int V_84 = V_98 -> V_82 ;
unsigned int V_85 ;
int V_16 ;
if ( V_98 -> type != V_45 -> type )
return - V_21 ;
V_45 -> V_46 -> V_99 ( V_45 , & V_84 , & V_85 ) ;
if ( V_85 == 0 )
return - V_21 ;
V_84 = F_52 (unsigned int, nbuffers, ISP_VIDEO_MAX_BUFFERS) ;
F_53 ( & V_45 -> V_11 ) ;
V_16 = F_43 ( V_45 , V_84 , V_85 , V_98 -> V_17 ) ;
if ( V_16 < 0 )
goto V_59;
V_98 -> V_82 = V_16 ;
V_16 = 0 ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
return V_16 ;
}
int F_55 ( struct V_79 * V_45 ,
struct V_63 * V_4 )
{
struct V_1 * V_2 ;
int V_16 = 0 ;
if ( V_4 -> type != V_45 -> type )
return - V_21 ;
F_53 ( & V_45 -> V_11 ) ;
if ( V_4 -> V_90 >= V_45 -> V_82 ) {
V_16 = - V_21 ;
goto V_59;
}
V_2 = V_45 -> V_83 [ V_4 -> V_90 ] ;
F_37 ( V_2 , V_4 ) ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
return V_16 ;
}
int F_56 ( struct V_79 * V_45 ,
struct V_63 * V_4 )
{
struct V_1 * V_2 ;
unsigned long V_65 ;
int V_16 = - V_21 ;
if ( V_4 -> type != V_45 -> type )
goto V_59;
F_53 ( & V_45 -> V_11 ) ;
if ( V_4 -> V_90 >= V_45 -> V_82 )
goto V_59;
V_2 = V_45 -> V_83 [ V_4 -> V_90 ] ;
if ( V_4 -> V_17 != V_2 -> V_4 . V_17 )
goto V_59;
if ( V_2 -> V_67 != V_75 )
goto V_59;
if ( V_4 -> V_17 == V_61 &&
V_4 -> V_9 < V_2 -> V_4 . V_9 )
goto V_59;
if ( V_4 -> V_17 == V_61 &&
V_4 -> V_5 . V_6 != V_2 -> V_4 . V_5 . V_6 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_5 . V_6 = V_4 -> V_5 . V_6 ;
V_2 -> V_100 = 0 ;
}
if ( ! V_2 -> V_100 ) {
V_16 = F_35 ( V_2 ) ;
if ( V_16 < 0 )
goto V_59;
V_2 -> V_100 = 1 ;
}
F_1 ( V_2 ) ;
V_2 -> V_67 = V_72 ;
F_57 ( & V_2 -> V_101 , & V_45 -> V_45 ) ;
if ( V_45 -> V_80 ) {
F_58 ( & V_45 -> V_96 , V_65 ) ;
V_45 -> V_46 -> V_102 ( V_2 ) ;
F_59 ( & V_45 -> V_96 , V_65 ) ;
}
V_16 = 0 ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
return V_16 ;
}
int F_60 ( struct V_79 * V_45 ,
struct V_63 * V_4 , int V_76 )
{
struct V_1 * V_2 ;
int V_16 ;
if ( V_4 -> type != V_45 -> type )
return - V_21 ;
F_53 ( & V_45 -> V_11 ) ;
if ( F_61 ( & V_45 -> V_45 ) ) {
V_16 = - V_21 ;
goto V_59;
}
V_2 = F_62 ( & V_45 -> V_45 , struct V_1 , V_101 ) ;
V_16 = F_38 ( V_2 , V_76 ) ;
if ( V_16 < 0 )
goto V_59;
F_63 ( & V_2 -> V_101 ) ;
F_37 ( V_2 , V_4 ) ;
V_2 -> V_67 = V_75 ;
V_4 -> V_65 &= ~ V_74 ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
return V_16 ;
}
int F_64 ( struct V_79 * V_45 )
{
struct V_1 * V_2 ;
unsigned long V_65 ;
F_53 ( & V_45 -> V_11 ) ;
if ( V_45 -> V_80 )
goto V_59;
V_45 -> V_80 = 1 ;
F_58 ( & V_45 -> V_96 , V_65 ) ;
F_65 (buf, &queue->queue, stream)
V_45 -> V_46 -> V_102 ( V_2 ) ;
F_59 ( & V_45 -> V_96 , V_65 ) ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
return 0 ;
}
void F_66 ( struct V_79 * V_45 )
{
struct V_1 * V_2 ;
unsigned long V_65 ;
unsigned int V_31 ;
F_53 ( & V_45 -> V_11 ) ;
if ( ! V_45 -> V_80 )
goto V_59;
V_45 -> V_80 = 0 ;
F_58 ( & V_45 -> V_96 , V_65 ) ;
for ( V_31 = 0 ; V_31 < V_45 -> V_82 ; ++ V_31 ) {
V_2 = V_45 -> V_83 [ V_31 ] ;
if ( V_2 -> V_67 == V_73 )
F_67 ( & V_2 -> V_78 ) ;
V_2 -> V_67 = V_75 ;
}
F_59 ( & V_45 -> V_96 , V_65 ) ;
F_42 ( & V_45 -> V_45 ) ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
}
void F_68 ( struct V_79 * V_45 )
{
struct V_1 * V_2 ;
unsigned int V_31 ;
F_53 ( & V_45 -> V_11 ) ;
if ( ! V_45 -> V_80 )
goto V_59;
for ( V_31 = 0 ; V_31 < V_45 -> V_82 ; ++ V_31 ) {
V_2 = V_45 -> V_83 [ V_31 ] ;
if ( V_2 -> V_67 == V_70 )
V_2 -> V_67 = V_68 ;
}
V_59:
F_54 ( & V_45 -> V_11 ) ;
}
static void F_69 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_103 ;
V_2 -> V_64 ++ ;
}
static void F_70 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_103 ;
V_2 -> V_64 -- ;
}
int F_71 ( struct V_79 * V_45 ,
struct V_12 * V_13 )
{
struct V_1 * V_104 ( V_2 ) ;
unsigned long V_85 ;
unsigned int V_31 ;
int V_16 = 0 ;
F_53 ( & V_45 -> V_11 ) ;
for ( V_31 = 0 ; V_31 < V_45 -> V_82 ; ++ V_31 ) {
V_2 = V_45 -> V_83 [ V_31 ] ;
if ( ( V_2 -> V_4 . V_5 . V_39 >> V_34 ) == V_13 -> V_105 )
break;
}
if ( V_31 == V_45 -> V_82 ) {
V_16 = - V_21 ;
goto V_59;
}
V_85 = V_13 -> V_28 - V_13 -> V_106 ;
if ( V_2 -> V_4 . V_17 != V_18 ||
V_85 != F_12 ( V_2 -> V_4 . V_9 ) ) {
V_16 = - V_21 ;
goto V_59;
}
V_16 = F_72 ( V_13 , V_2 -> V_33 , 0 ) ;
if ( V_16 < 0 )
goto V_59;
V_13 -> V_107 = & V_108 ;
V_13 -> V_103 = V_2 ;
F_69 ( V_13 ) ;
V_59:
F_54 ( & V_45 -> V_11 ) ;
return V_16 ;
}
unsigned int F_73 ( struct V_79 * V_45 ,
struct V_109 * V_109 , T_3 * V_78 )
{
struct V_1 * V_2 ;
unsigned int V_110 = 0 ;
F_53 ( & V_45 -> V_11 ) ;
if ( F_61 ( & V_45 -> V_45 ) ) {
V_110 |= V_111 ;
goto V_59;
}
V_2 = F_62 ( & V_45 -> V_45 , struct V_1 , V_101 ) ;
F_74 ( V_109 , & V_2 -> V_78 , V_78 ) ;
if ( V_2 -> V_67 == V_70 ||
V_2 -> V_67 == V_68 ) {
if ( V_45 -> type == V_49 )
V_110 |= V_112 | V_113 ;
else
V_110 |= V_114 | V_115 ;
}
V_59:
F_54 ( & V_45 -> V_11 ) ;
return V_110 ;
}
