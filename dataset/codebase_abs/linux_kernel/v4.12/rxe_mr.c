static T_1 F_1 ( void )
{
static T_2 V_1 = 1 ;
V_1 = V_1 << 1 ;
V_1 |= ( 0 != ( V_1 & 0x100 ) ) ^ ( 0 != ( V_1 & 0x10 ) )
^ ( 0 != ( V_1 & 0x80 ) ) ^ ( 0 != ( V_1 & 0x40 ) ) ;
V_1 &= 0xff ;
return V_1 ;
}
int F_2 ( struct V_2 * V_3 , T_3 V_4 , T_4 V_5 )
{
switch ( V_3 -> type ) {
case V_6 :
return 0 ;
case V_7 :
case V_8 :
if ( V_4 < V_3 -> V_4 ||
V_5 > V_3 -> V_5 ||
V_4 > V_3 -> V_4 + V_3 -> V_5 - V_5 )
return - V_9 ;
return 0 ;
default:
return - V_9 ;
}
}
static void F_3 ( int V_10 , struct V_2 * V_3 )
{
T_2 V_11 = V_3 -> V_12 . V_13 << 8 | F_1 () ;
T_2 V_14 = ( V_10 & V_15 ) ? V_11 : 0 ;
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
void F_5 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_6 ( V_25 , F_7 ( * V_3 ) , V_12 ) ;
int V_26 ;
if ( V_3 -> V_27 )
F_8 ( V_3 -> V_27 ) ;
if ( V_3 -> V_28 ) {
for ( V_26 = 0 ; V_26 < V_3 -> V_29 ; V_26 ++ )
F_9 ( V_3 -> V_28 [ V_26 ] ) ;
F_9 ( V_3 -> V_28 ) ;
}
}
static int F_10 ( struct V_30 * V_31 , struct V_2 * V_3 , int V_32 )
{
int V_26 ;
int V_29 ;
struct V_33 * * V_28 = V_3 -> V_28 ;
V_29 = ( V_32 + V_23 - 1 ) / V_23 ;
V_3 -> V_28 = F_11 ( V_29 , sizeof( * V_28 ) , V_34 ) ;
if ( ! V_3 -> V_28 )
goto V_35;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
V_3 -> V_28 [ V_26 ] = F_12 ( sizeof( * * V_28 ) , V_34 ) ;
if ( ! V_3 -> V_28 [ V_26 ] )
goto V_36;
}
F_13 ( ! F_14 ( V_23 ) ) ;
V_3 -> V_22 = F_4 ( V_23 ) ;
V_3 -> V_37 = V_23 - 1 ;
V_3 -> V_32 = V_32 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_38 = V_29 * V_23 ;
return 0 ;
V_36:
for ( V_26 -- ; V_26 >= 0 ; V_26 -- )
F_9 ( V_3 -> V_28 [ V_26 ] ) ;
F_9 ( V_3 -> V_28 ) ;
V_35:
return - V_39 ;
}
int F_15 ( struct V_30 * V_31 , struct V_40 * V_41 ,
int V_10 , struct V_2 * V_3 )
{
F_3 ( V_10 , V_3 ) ;
V_3 -> V_41 = V_41 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_19 = V_42 ;
V_3 -> type = V_6 ;
return 0 ;
}
int F_16 ( struct V_30 * V_31 , struct V_40 * V_41 , T_3 V_43 ,
T_3 V_5 , T_3 V_4 , int V_10 , struct V_44 * V_45 ,
struct V_2 * V_3 )
{
int V_46 ;
struct V_33 * * V_28 ;
struct V_47 * V_48 = NULL ;
struct V_49 * V_27 ;
struct V_50 * V_51 ;
int V_32 ;
void * V_52 ;
int V_53 ;
V_27 = F_17 ( V_41 -> V_54 . V_55 -> V_56 , V_43 , V_5 , V_10 , 0 ) ;
if ( F_18 ( V_27 ) ) {
F_19 ( L_1 ,
( int ) F_20 ( V_27 ) ) ;
V_53 = - V_57 ;
goto V_35;
}
V_3 -> V_27 = V_27 ;
V_32 = V_27 -> V_58 ;
F_3 ( V_10 , V_3 ) ;
V_53 = F_10 ( V_31 , V_3 , V_32 ) ;
if ( V_53 ) {
F_19 ( L_2 , V_53 ) ;
F_8 ( V_27 ) ;
goto V_35;
}
V_3 -> V_59 = V_27 -> V_59 ;
V_3 -> V_60 = F_21 ( V_27 -> V_59 ) - 1 ;
V_32 = 0 ;
V_28 = V_3 -> V_28 ;
if ( V_5 > 0 ) {
V_48 = V_28 [ 0 ] -> V_48 ;
F_22 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_52 = F_23 ( F_24 ( V_51 ) ) ;
if ( ! V_52 ) {
F_19 ( L_3 ) ;
V_53 = - V_39 ;
goto V_35;
}
V_48 -> V_61 = ( V_62 ) V_52 ;
V_48 -> V_63 = F_21 ( V_27 -> V_59 ) ;
V_32 ++ ;
V_48 ++ ;
if ( V_32 >= V_23 ) {
V_28 ++ ;
V_48 = V_28 [ 0 ] -> V_48 ;
V_32 = 0 ;
}
}
}
V_3 -> V_41 = V_41 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_64 = V_43 ;
V_3 -> V_65 = F_25 ( V_27 ) ;
V_3 -> V_19 = V_42 ;
V_3 -> type = V_7 ;
return 0 ;
V_35:
return V_53 ;
}
int F_26 ( struct V_30 * V_31 , struct V_40 * V_41 ,
int V_66 , struct V_2 * V_3 )
{
int V_53 ;
F_3 ( 0 , V_3 ) ;
V_3 -> V_18 . V_14 = V_3 -> V_18 . V_11 ;
V_53 = F_10 ( V_31 , V_3 , V_66 ) ;
if ( V_53 )
goto V_35;
V_3 -> V_41 = V_41 ;
V_3 -> V_38 = V_66 ;
V_3 -> V_19 = V_67 ;
V_3 -> type = V_7 ;
return 0 ;
V_35:
return V_53 ;
}
static void F_27 (
struct V_2 * V_3 ,
T_3 V_4 ,
int * V_68 ,
int * V_69 ,
T_4 * V_70 )
{
T_4 V_65 = V_4 - V_3 -> V_4 + V_3 -> V_65 ;
int V_71 ;
int V_72 ;
T_3 V_5 ;
if ( F_28 ( V_3 -> V_59 ) ) {
* V_70 = V_65 & V_3 -> V_60 ;
V_65 >>= V_3 -> V_59 ;
* V_69 = V_65 & V_3 -> V_37 ;
* V_68 = V_65 >> V_3 -> V_22 ;
} else {
V_71 = 0 ;
V_72 = 0 ;
V_5 = V_3 -> V_28 [ V_71 ] -> V_48 [ V_72 ] . V_63 ;
while ( V_65 >= V_5 ) {
V_65 -= V_5 ;
V_72 ++ ;
if ( V_72 == V_23 ) {
V_71 ++ ;
V_72 = 0 ;
}
V_5 = V_3 -> V_28 [ V_71 ] -> V_48 [ V_72 ] . V_63 ;
}
* V_68 = V_71 ;
* V_69 = V_72 ;
* V_70 = V_65 ;
}
}
void * F_29 ( struct V_2 * V_3 , T_3 V_4 , int V_5 )
{
T_4 V_65 ;
int V_73 , V_74 ;
void * V_61 ;
if ( V_3 -> V_19 != V_42 ) {
F_19 ( L_4 ) ;
V_61 = NULL ;
goto V_75;
}
if ( ! V_3 -> V_28 ) {
V_61 = ( void * ) ( V_62 ) V_4 ;
goto V_75;
}
if ( F_2 ( V_3 , V_4 , V_5 ) ) {
F_19 ( L_5 ) ;
V_61 = NULL ;
goto V_75;
}
F_27 ( V_3 , V_4 , & V_73 , & V_74 , & V_65 ) ;
if ( V_65 + V_5 > V_3 -> V_28 [ V_73 ] -> V_48 [ V_74 ] . V_63 ) {
F_19 ( L_6 ) ;
V_61 = NULL ;
goto V_75;
}
V_61 = ( void * ) ( V_62 ) V_3 -> V_28 [ V_73 ] -> V_48 [ V_74 ] . V_61 + V_65 ;
V_75:
return V_61 ;
}
int F_30 ( struct V_2 * V_3 , T_3 V_4 , void * V_61 , int V_5 ,
enum V_76 V_77 , T_2 * V_78 )
{
int V_53 ;
int V_79 ;
T_1 * V_64 ;
struct V_33 * * V_28 ;
struct V_47 * V_48 ;
int V_73 ;
int V_26 ;
T_4 V_65 ;
T_2 V_80 = V_78 ? ( * V_78 ) : 0 ;
if ( V_5 == 0 )
return 0 ;
if ( V_3 -> type == V_6 ) {
T_1 * V_81 , * V_82 ;
V_81 = ( V_77 == V_83 ) ?
V_61 : ( ( void * ) ( V_62 ) V_4 ) ;
V_82 = ( V_77 == V_83 ) ?
( ( void * ) ( V_62 ) V_4 ) : V_61 ;
if ( V_78 )
* V_78 = F_31 ( F_32 ( V_3 -> V_41 -> V_54 . V_84 ) ,
* V_78 , V_81 , V_5 ) ;
memcpy ( V_82 , V_81 , V_5 ) ;
return 0 ;
}
F_33 ( ! V_3 -> V_28 ) ;
V_53 = F_2 ( V_3 , V_4 , V_5 ) ;
if ( V_53 ) {
V_53 = - V_9 ;
goto V_35;
}
F_27 ( V_3 , V_4 , & V_73 , & V_26 , & V_65 ) ;
V_28 = V_3 -> V_28 + V_73 ;
V_48 = V_28 [ 0 ] -> V_48 + V_26 ;
while ( V_5 > 0 ) {
T_1 * V_81 , * V_82 ;
V_64 = ( T_1 * ) ( V_62 ) V_48 -> V_61 + V_65 ;
V_81 = ( V_77 == V_83 ) ? V_61 : V_64 ;
V_82 = ( V_77 == V_83 ) ? V_64 : V_61 ;
V_79 = V_48 -> V_63 - V_65 ;
if ( V_79 > V_5 )
V_79 = V_5 ;
if ( V_78 )
V_80 = F_31 ( F_32 ( V_3 -> V_41 -> V_54 . V_84 ) ,
V_80 , V_81 , V_79 ) ;
memcpy ( V_82 , V_81 , V_79 ) ;
V_5 -= V_79 ;
V_61 += V_79 ;
V_65 = 0 ;
V_48 ++ ;
V_26 ++ ;
if ( V_26 == V_23 ) {
V_26 = 0 ;
V_28 ++ ;
V_48 = V_28 [ 0 ] -> V_48 ;
}
}
if ( V_78 )
* V_78 = V_80 ;
return 0 ;
V_35:
return V_53 ;
}
int F_34 (
struct V_30 * V_31 ,
struct V_40 * V_41 ,
int V_10 ,
struct V_85 * V_86 ,
void * V_61 ,
int V_5 ,
enum V_76 V_77 ,
T_2 * V_78 )
{
int V_79 ;
struct V_87 * V_88 = & V_86 -> V_88 [ V_86 -> V_89 ] ;
int V_65 = V_86 -> V_90 ;
int V_91 = V_86 -> V_91 ;
struct V_2 * V_3 = NULL ;
T_3 V_4 ;
int V_53 ;
if ( V_5 == 0 )
return 0 ;
if ( V_5 > V_91 ) {
V_53 = - V_57 ;
goto V_36;
}
if ( V_88 -> V_5 && ( V_65 < V_88 -> V_5 ) ) {
V_3 = F_35 ( V_41 , V_10 , V_88 -> V_11 , V_92 ) ;
if ( ! V_3 ) {
V_53 = - V_57 ;
goto V_35;
}
}
while ( V_5 > 0 ) {
V_79 = V_5 ;
if ( V_65 >= V_88 -> V_5 ) {
if ( V_3 ) {
F_36 ( V_3 ) ;
V_3 = NULL ;
}
V_88 ++ ;
V_86 -> V_89 ++ ;
V_65 = 0 ;
if ( V_86 -> V_89 >= V_86 -> V_93 ) {
V_53 = - V_94 ;
goto V_36;
}
if ( V_88 -> V_5 ) {
V_3 = F_35 ( V_41 , V_10 , V_88 -> V_11 ,
V_92 ) ;
if ( ! V_3 ) {
V_53 = - V_57 ;
goto V_35;
}
} else {
continue;
}
}
if ( V_79 > V_88 -> V_5 - V_65 )
V_79 = V_88 -> V_5 - V_65 ;
if ( V_79 > 0 ) {
V_4 = V_88 -> V_61 + V_65 ;
V_53 = F_30 ( V_3 , V_4 , V_61 , V_79 , V_77 , V_78 ) ;
if ( V_53 )
goto V_36;
V_65 += V_79 ;
V_91 -= V_79 ;
V_5 -= V_79 ;
V_61 += V_79 ;
}
}
V_86 -> V_90 = V_65 ;
V_86 -> V_91 = V_91 ;
if ( V_3 )
F_36 ( V_3 ) ;
return 0 ;
V_36:
if ( V_3 )
F_36 ( V_3 ) ;
V_35:
return V_53 ;
}
int F_37 ( struct V_85 * V_86 , unsigned int V_5 )
{
struct V_87 * V_88 = & V_86 -> V_88 [ V_86 -> V_89 ] ;
int V_65 = V_86 -> V_90 ;
int V_91 = V_86 -> V_91 ;
while ( V_5 ) {
unsigned int V_79 ;
if ( V_65 >= V_88 -> V_5 ) {
V_88 ++ ;
V_86 -> V_89 ++ ;
V_65 = 0 ;
if ( V_86 -> V_89 >= V_86 -> V_93 )
return - V_94 ;
}
V_79 = V_5 ;
if ( V_79 > V_88 -> V_5 - V_65 )
V_79 = V_88 -> V_5 - V_65 ;
V_65 += V_79 ;
V_91 -= V_79 ;
V_5 -= V_79 ;
}
V_86 -> V_90 = V_65 ;
V_86 -> V_91 = V_91 ;
return 0 ;
}
struct V_2 * F_35 ( struct V_40 * V_41 , int V_10 , T_2 V_1 ,
enum V_95 type )
{
struct V_2 * V_3 ;
struct V_30 * V_31 = F_32 ( V_41 -> V_54 . V_84 ) ;
int V_13 = V_1 >> 8 ;
if ( V_13 >= V_96 && V_13 <= V_97 ) {
V_3 = F_38 ( & V_31 -> V_98 , V_13 ) ;
if ( ! V_3 )
goto V_35;
} else {
goto V_35;
}
if ( ( type == V_92 && V_3 -> V_11 != V_1 ) ||
( type == V_99 && V_3 -> V_14 != V_1 ) )
goto V_36;
if ( V_3 -> V_41 != V_41 )
goto V_36;
if ( V_10 && ! ( V_10 & V_3 -> V_10 ) )
goto V_36;
if ( V_3 -> V_19 != V_42 )
goto V_36;
return V_3 ;
V_36:
F_36 ( V_3 ) ;
V_35:
return NULL ;
}
int F_39 ( struct V_30 * V_31 , struct V_2 * V_3 ,
T_3 * V_100 , int V_101 , T_3 V_4 )
{
int V_26 ;
int V_32 ;
int V_53 ;
struct V_33 * * V_28 ;
struct V_47 * V_48 ;
int V_102 ;
if ( V_101 > V_3 -> V_38 ) {
V_53 = - V_57 ;
goto V_35;
}
V_32 = 0 ;
V_102 = 1 << V_3 -> V_59 ;
V_28 = V_3 -> V_28 ;
V_48 = V_28 [ 0 ] -> V_48 ;
for ( V_26 = 0 ; V_26 < V_101 ; V_26 ++ ) {
V_48 -> V_61 = * V_100 ++ ;
V_48 -> V_63 = V_102 ;
V_48 ++ ;
V_32 ++ ;
if ( V_32 == V_23 ) {
V_28 ++ ;
V_48 = V_28 [ 0 ] -> V_48 ;
V_32 = 0 ;
}
}
V_3 -> V_4 = V_4 ;
V_3 -> V_64 = V_4 ;
V_3 -> V_5 = V_101 << V_3 -> V_59 ;
V_3 -> V_19 = V_42 ;
return 0 ;
V_35:
return V_53 ;
}
