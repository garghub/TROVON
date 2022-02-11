static T_1 F_1 ( void )
{
static unsigned V_1 = 1 ;
V_1 = V_1 << 1 ;
V_1 |= ( 0 != ( V_1 & 0x100 ) ) ^ ( 0 != ( V_1 & 0x10 ) )
^ ( 0 != ( V_1 & 0x80 ) ) ^ ( 0 != ( V_1 & 0x40 ) ) ;
V_1 &= 0xff ;
return V_1 ;
}
int F_2 ( struct V_2 * V_3 , T_2 V_4 , T_3 V_5 )
{
switch ( V_3 -> type ) {
case V_6 :
return 0 ;
case V_7 :
case V_8 :
return ( ( V_4 < V_3 -> V_4 ) ||
( ( V_4 + V_5 ) > ( V_3 -> V_4 + V_3 -> V_5 ) ) ) ?
- V_9 : 0 ;
default:
return - V_9 ;
}
}
static void F_3 ( int V_10 , struct V_2 * V_3 )
{
T_4 V_11 = V_3 -> V_12 . V_13 << 8 | F_1 () ;
T_4 V_14 = ( V_10 & V_15 ) ? V_11 : 0 ;
if ( V_3 -> V_12 . V_16 -> type == V_17 ) {
V_3 -> V_18 . V_11 = V_11 ;
V_3 -> V_18 . V_14 = V_14 ;
}
V_3 -> V_11 = V_11 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_19 = V_20 ;
V_3 -> type = V_21 ;
V_3 -> V_22 = F_4 ( V_23 ) ;
}
void F_5 ( void * V_24 )
{
struct V_2 * V_3 = V_24 ;
int V_25 ;
if ( V_3 -> V_26 )
F_6 ( V_3 -> V_26 ) ;
if ( V_3 -> V_27 ) {
for ( V_25 = 0 ; V_25 < V_3 -> V_28 ; V_25 ++ )
F_7 ( V_3 -> V_27 [ V_25 ] ) ;
F_7 ( V_3 -> V_27 ) ;
}
}
static int F_8 ( struct V_29 * V_30 , struct V_2 * V_3 , int V_31 )
{
int V_25 ;
int V_28 ;
struct V_32 * * V_27 = V_3 -> V_27 ;
V_28 = ( V_31 + V_23 - 1 ) / V_23 ;
V_3 -> V_27 = F_9 ( V_28 , sizeof( * V_27 ) , V_33 ) ;
if ( ! V_3 -> V_27 )
goto V_34;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ ) {
V_3 -> V_27 [ V_25 ] = F_10 ( sizeof( * * V_27 ) , V_33 ) ;
if ( ! V_3 -> V_27 [ V_25 ] )
goto V_35;
}
F_11 ( ! F_12 ( V_23 ) ) ;
V_3 -> V_22 = F_4 ( V_23 ) ;
V_3 -> V_36 = V_23 - 1 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_28 = V_28 ;
V_3 -> V_37 = V_28 * V_23 ;
return 0 ;
V_35:
for ( V_25 -- ; V_25 >= 0 ; V_25 -- )
F_7 ( V_3 -> V_27 [ V_25 ] ) ;
F_7 ( V_3 -> V_27 ) ;
V_34:
return - V_38 ;
}
int F_13 ( struct V_29 * V_30 , struct V_39 * V_40 ,
int V_10 , struct V_2 * V_3 )
{
F_3 ( V_10 , V_3 ) ;
V_3 -> V_40 = V_40 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_19 = V_41 ;
V_3 -> type = V_6 ;
return 0 ;
}
int F_14 ( struct V_29 * V_30 , struct V_39 * V_40 , T_2 V_42 ,
T_2 V_5 , T_2 V_4 , int V_10 , struct V_43 * V_44 ,
struct V_2 * V_3 )
{
int V_45 ;
struct V_32 * * V_27 ;
struct V_46 * V_47 = NULL ;
struct V_48 * V_26 ;
struct V_49 * V_50 ;
int V_31 ;
void * V_51 ;
int V_52 ;
V_26 = F_15 ( V_40 -> V_53 . V_54 -> V_55 , V_42 , V_5 , V_10 , 0 ) ;
if ( F_16 ( V_26 ) ) {
F_17 ( L_1 ,
( int ) F_18 ( V_26 ) ) ;
V_52 = - V_56 ;
goto V_34;
}
V_3 -> V_26 = V_26 ;
V_31 = V_26 -> V_57 ;
F_3 ( V_10 , V_3 ) ;
V_52 = F_8 ( V_30 , V_3 , V_31 ) ;
if ( V_52 ) {
F_17 ( L_2 , V_52 ) ;
F_6 ( V_26 ) ;
goto V_34;
}
F_11 ( ! F_12 ( V_26 -> V_58 ) ) ;
V_3 -> V_59 = F_4 ( V_26 -> V_58 ) ;
V_3 -> V_60 = V_26 -> V_58 - 1 ;
V_31 = 0 ;
V_27 = V_3 -> V_27 ;
if ( V_5 > 0 ) {
V_47 = V_27 [ 0 ] -> V_47 ;
F_19 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_51 = F_20 ( F_21 ( V_50 ) ) ;
if ( ! V_51 ) {
F_17 ( L_3 ) ;
V_52 = - V_38 ;
goto V_34;
}
V_47 -> V_61 = ( V_62 ) V_51 ;
V_47 -> V_63 = V_26 -> V_58 ;
V_31 ++ ;
V_47 ++ ;
if ( V_31 >= V_23 ) {
V_27 ++ ;
V_47 = V_27 [ 0 ] -> V_47 ;
V_31 = 0 ;
}
}
}
V_3 -> V_40 = V_40 ;
V_3 -> V_26 = V_26 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_64 = V_42 ;
V_3 -> V_65 = F_22 ( V_26 ) ;
V_3 -> V_19 = V_41 ;
V_3 -> type = V_7 ;
return 0 ;
V_34:
return V_52 ;
}
int F_23 ( struct V_29 * V_30 , struct V_39 * V_40 ,
int V_66 , struct V_2 * V_3 )
{
int V_52 ;
F_3 ( 0 , V_3 ) ;
V_3 -> V_18 . V_14 = V_3 -> V_18 . V_11 ;
V_52 = F_8 ( V_30 , V_3 , V_66 ) ;
if ( V_52 )
goto V_34;
V_3 -> V_40 = V_40 ;
V_3 -> V_37 = V_66 ;
V_3 -> V_19 = V_67 ;
V_3 -> type = V_7 ;
return 0 ;
V_34:
return V_52 ;
}
static void F_24 (
struct V_2 * V_3 ,
T_2 V_4 ,
int * V_68 ,
int * V_69 ,
T_3 * V_70 )
{
T_3 V_65 = V_4 - V_3 -> V_4 + V_3 -> V_65 ;
int V_71 ;
int V_72 ;
T_2 V_5 ;
if ( F_25 ( V_3 -> V_59 ) ) {
* V_70 = V_65 & V_3 -> V_60 ;
V_65 >>= V_3 -> V_59 ;
* V_69 = V_65 & V_3 -> V_36 ;
* V_68 = V_65 >> V_3 -> V_22 ;
} else {
V_71 = 0 ;
V_72 = 0 ;
V_5 = V_3 -> V_27 [ V_71 ] -> V_47 [ V_72 ] . V_63 ;
while ( V_65 >= V_5 ) {
V_65 -= V_5 ;
V_72 ++ ;
if ( V_72 == V_23 ) {
V_71 ++ ;
V_72 = 0 ;
}
V_5 = V_3 -> V_27 [ V_71 ] -> V_47 [ V_72 ] . V_63 ;
}
* V_68 = V_71 ;
* V_69 = V_72 ;
* V_70 = V_65 ;
}
}
void * F_26 ( struct V_2 * V_3 , T_2 V_4 , int V_5 )
{
T_3 V_65 ;
int V_73 , V_74 ;
void * V_61 ;
if ( V_3 -> V_19 != V_41 ) {
F_17 ( L_4 ) ;
V_61 = NULL ;
goto V_75;
}
if ( ! V_3 -> V_27 ) {
V_61 = ( void * ) ( V_62 ) V_4 ;
goto V_75;
}
if ( F_2 ( V_3 , V_4 , V_5 ) ) {
F_17 ( L_5 ) ;
V_61 = NULL ;
goto V_75;
}
F_24 ( V_3 , V_4 , & V_73 , & V_74 , & V_65 ) ;
if ( V_65 + V_5 > V_3 -> V_27 [ V_73 ] -> V_47 [ V_74 ] . V_63 ) {
F_17 ( L_6 ) ;
V_61 = NULL ;
goto V_75;
}
V_61 = ( void * ) ( V_62 ) V_3 -> V_27 [ V_73 ] -> V_47 [ V_74 ] . V_61 + V_65 ;
V_75:
return V_61 ;
}
int F_27 ( struct V_2 * V_3 , T_2 V_4 , void * V_61 , int V_5 ,
enum V_76 V_77 , T_4 * V_78 )
{
int V_52 ;
int V_79 ;
T_1 * V_64 ;
struct V_32 * * V_27 ;
struct V_46 * V_47 ;
int V_73 ;
int V_25 ;
T_3 V_65 ;
T_4 V_80 = V_78 ? ( * V_78 ) : 0 ;
if ( V_3 -> type == V_6 ) {
T_1 * V_81 , * V_82 ;
V_81 = ( V_77 == V_83 ) ?
V_61 : ( ( void * ) ( V_62 ) V_4 ) ;
V_82 = ( V_77 == V_83 ) ?
( ( void * ) ( V_62 ) V_4 ) : V_61 ;
if ( V_78 )
* V_78 = F_28 ( * V_78 , V_81 , V_5 ) ;
memcpy ( V_82 , V_81 , V_5 ) ;
return 0 ;
}
F_11 ( ! V_3 -> V_27 ) ;
V_52 = F_2 ( V_3 , V_4 , V_5 ) ;
if ( V_52 ) {
V_52 = - V_9 ;
goto V_34;
}
F_24 ( V_3 , V_4 , & V_73 , & V_25 , & V_65 ) ;
V_27 = V_3 -> V_27 + V_73 ;
V_47 = V_27 [ 0 ] -> V_47 + V_25 ;
while ( V_5 > 0 ) {
T_1 * V_81 , * V_82 ;
V_64 = ( T_1 * ) ( V_62 ) V_47 -> V_61 + V_65 ;
V_81 = ( V_77 == V_83 ) ? V_61 : V_64 ;
V_82 = ( V_77 == V_83 ) ? V_64 : V_61 ;
V_79 = V_47 -> V_63 - V_65 ;
if ( V_79 > V_5 )
V_79 = V_5 ;
if ( V_78 )
V_80 = F_28 ( V_80 , V_81 , V_79 ) ;
memcpy ( V_82 , V_81 , V_79 ) ;
V_5 -= V_79 ;
V_61 += V_79 ;
V_65 = 0 ;
V_47 ++ ;
V_25 ++ ;
if ( V_25 == V_23 ) {
V_25 = 0 ;
V_27 ++ ;
V_47 = V_27 [ 0 ] -> V_47 ;
}
}
if ( V_78 )
* V_78 = V_80 ;
return 0 ;
V_34:
return V_52 ;
}
int F_29 (
struct V_29 * V_30 ,
struct V_39 * V_40 ,
int V_10 ,
struct V_84 * V_85 ,
void * V_61 ,
int V_5 ,
enum V_76 V_77 ,
T_4 * V_78 )
{
int V_79 ;
struct V_86 * V_87 = & V_85 -> V_87 [ V_85 -> V_88 ] ;
int V_65 = V_85 -> V_89 ;
int V_90 = V_85 -> V_90 ;
struct V_2 * V_3 = NULL ;
T_2 V_4 ;
int V_52 ;
if ( V_5 == 0 )
return 0 ;
if ( V_5 > V_90 ) {
V_52 = - V_56 ;
goto V_35;
}
if ( V_87 -> V_5 && ( V_65 < V_87 -> V_5 ) ) {
V_3 = F_30 ( V_40 , V_10 , V_87 -> V_11 , V_91 ) ;
if ( ! V_3 ) {
V_52 = - V_56 ;
goto V_34;
}
}
while ( V_5 > 0 ) {
V_79 = V_5 ;
if ( V_65 >= V_87 -> V_5 ) {
if ( V_3 ) {
F_31 ( V_3 ) ;
V_3 = NULL ;
}
V_87 ++ ;
V_85 -> V_88 ++ ;
V_65 = 0 ;
if ( V_85 -> V_88 >= V_85 -> V_92 ) {
V_52 = - V_93 ;
goto V_35;
}
if ( V_87 -> V_5 ) {
V_3 = F_30 ( V_40 , V_10 , V_87 -> V_11 ,
V_91 ) ;
if ( ! V_3 ) {
V_52 = - V_56 ;
goto V_34;
}
} else {
continue;
}
}
if ( V_79 > V_87 -> V_5 - V_65 )
V_79 = V_87 -> V_5 - V_65 ;
if ( V_79 > 0 ) {
V_4 = V_87 -> V_61 + V_65 ;
V_52 = F_27 ( V_3 , V_4 , V_61 , V_79 , V_77 , V_78 ) ;
if ( V_52 )
goto V_35;
V_65 += V_79 ;
V_90 -= V_79 ;
V_5 -= V_79 ;
V_61 += V_79 ;
}
}
V_85 -> V_89 = V_65 ;
V_85 -> V_90 = V_90 ;
if ( V_3 )
F_31 ( V_3 ) ;
return 0 ;
V_35:
if ( V_3 )
F_31 ( V_3 ) ;
V_34:
return V_52 ;
}
int F_32 ( struct V_84 * V_85 , unsigned int V_5 )
{
struct V_86 * V_87 = & V_85 -> V_87 [ V_85 -> V_88 ] ;
int V_65 = V_85 -> V_89 ;
int V_90 = V_85 -> V_90 ;
while ( V_5 ) {
unsigned int V_79 ;
if ( V_65 >= V_87 -> V_5 ) {
V_87 ++ ;
V_85 -> V_88 ++ ;
V_65 = 0 ;
if ( V_85 -> V_88 >= V_85 -> V_92 )
return - V_93 ;
}
V_79 = V_5 ;
if ( V_79 > V_87 -> V_5 - V_65 )
V_79 = V_87 -> V_5 - V_65 ;
V_65 += V_79 ;
V_90 -= V_79 ;
V_5 -= V_79 ;
}
V_85 -> V_89 = V_65 ;
V_85 -> V_90 = V_90 ;
return 0 ;
}
struct V_2 * F_30 ( struct V_39 * V_40 , int V_10 , T_4 V_1 ,
enum V_94 type )
{
struct V_2 * V_3 ;
struct V_29 * V_30 = F_33 ( V_40 -> V_53 . V_95 ) ;
int V_13 = V_1 >> 8 ;
if ( V_13 >= V_96 && V_13 <= V_97 ) {
V_3 = F_34 ( & V_30 -> V_98 , V_13 ) ;
if ( ! V_3 )
goto V_34;
} else {
goto V_34;
}
if ( ( type == V_91 && V_3 -> V_11 != V_1 ) ||
( type == V_99 && V_3 -> V_14 != V_1 ) )
goto V_35;
if ( V_3 -> V_40 != V_40 )
goto V_35;
if ( V_10 && ! ( V_10 & V_3 -> V_10 ) )
goto V_35;
if ( V_3 -> V_19 != V_41 )
goto V_35;
return V_3 ;
V_35:
F_31 ( V_3 ) ;
V_34:
return NULL ;
}
int F_35 ( struct V_29 * V_30 , struct V_2 * V_3 ,
T_2 * V_100 , int V_101 , T_2 V_4 )
{
int V_25 ;
int V_31 ;
int V_52 ;
struct V_32 * * V_27 ;
struct V_46 * V_47 ;
int V_58 ;
if ( V_101 > V_3 -> V_37 ) {
V_52 = - V_56 ;
goto V_34;
}
V_31 = 0 ;
V_58 = 1 << V_3 -> V_59 ;
V_27 = V_3 -> V_27 ;
V_47 = V_27 [ 0 ] -> V_47 ;
for ( V_25 = 0 ; V_25 < V_101 ; V_25 ++ ) {
V_47 -> V_61 = * V_100 ++ ;
V_47 -> V_63 = V_58 ;
V_47 ++ ;
V_31 ++ ;
if ( V_31 == V_23 ) {
V_27 ++ ;
V_47 = V_27 [ 0 ] -> V_47 ;
V_31 = 0 ;
}
}
V_3 -> V_4 = V_4 ;
V_3 -> V_64 = V_4 ;
V_3 -> V_5 = V_101 << V_3 -> V_59 ;
V_3 -> V_19 = V_41 ;
return 0 ;
V_34:
return V_52 ;
}
