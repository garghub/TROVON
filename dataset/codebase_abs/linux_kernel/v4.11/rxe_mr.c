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
F_21 ( ! F_14 ( V_27 -> V_59 ) ) ;
V_3 -> V_60 = F_4 ( V_27 -> V_59 ) ;
V_3 -> V_61 = V_27 -> V_59 - 1 ;
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
V_48 -> V_62 = ( V_63 ) V_52 ;
V_48 -> V_64 = V_27 -> V_59 ;
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
V_3 -> V_65 = V_43 ;
V_3 -> V_66 = F_25 ( V_27 ) ;
V_3 -> V_19 = V_42 ;
V_3 -> type = V_7 ;
return 0 ;
V_35:
return V_53 ;
}
int F_26 ( struct V_30 * V_31 , struct V_40 * V_41 ,
int V_67 , struct V_2 * V_3 )
{
int V_53 ;
F_3 ( 0 , V_3 ) ;
V_3 -> V_18 . V_14 = V_3 -> V_18 . V_11 ;
V_53 = F_10 ( V_31 , V_3 , V_67 ) ;
if ( V_53 )
goto V_35;
V_3 -> V_41 = V_41 ;
V_3 -> V_38 = V_67 ;
V_3 -> V_19 = V_68 ;
V_3 -> type = V_7 ;
return 0 ;
V_35:
return V_53 ;
}
static void F_27 (
struct V_2 * V_3 ,
T_3 V_4 ,
int * V_69 ,
int * V_70 ,
T_4 * V_71 )
{
T_4 V_66 = V_4 - V_3 -> V_4 + V_3 -> V_66 ;
int V_72 ;
int V_73 ;
T_3 V_5 ;
if ( F_28 ( V_3 -> V_60 ) ) {
* V_71 = V_66 & V_3 -> V_61 ;
V_66 >>= V_3 -> V_60 ;
* V_70 = V_66 & V_3 -> V_37 ;
* V_69 = V_66 >> V_3 -> V_22 ;
} else {
V_72 = 0 ;
V_73 = 0 ;
V_5 = V_3 -> V_28 [ V_72 ] -> V_48 [ V_73 ] . V_64 ;
while ( V_66 >= V_5 ) {
V_66 -= V_5 ;
V_73 ++ ;
if ( V_73 == V_23 ) {
V_72 ++ ;
V_73 = 0 ;
}
V_5 = V_3 -> V_28 [ V_72 ] -> V_48 [ V_73 ] . V_64 ;
}
* V_69 = V_72 ;
* V_70 = V_73 ;
* V_71 = V_66 ;
}
}
void * F_29 ( struct V_2 * V_3 , T_3 V_4 , int V_5 )
{
T_4 V_66 ;
int V_74 , V_75 ;
void * V_62 ;
if ( V_3 -> V_19 != V_42 ) {
F_19 ( L_4 ) ;
V_62 = NULL ;
goto V_76;
}
if ( ! V_3 -> V_28 ) {
V_62 = ( void * ) ( V_63 ) V_4 ;
goto V_76;
}
if ( F_2 ( V_3 , V_4 , V_5 ) ) {
F_19 ( L_5 ) ;
V_62 = NULL ;
goto V_76;
}
F_27 ( V_3 , V_4 , & V_74 , & V_75 , & V_66 ) ;
if ( V_66 + V_5 > V_3 -> V_28 [ V_74 ] -> V_48 [ V_75 ] . V_64 ) {
F_19 ( L_6 ) ;
V_62 = NULL ;
goto V_76;
}
V_62 = ( void * ) ( V_63 ) V_3 -> V_28 [ V_74 ] -> V_48 [ V_75 ] . V_62 + V_66 ;
V_76:
return V_62 ;
}
int F_30 ( struct V_2 * V_3 , T_3 V_4 , void * V_62 , int V_5 ,
enum V_77 V_78 , T_2 * V_79 )
{
int V_53 ;
int V_80 ;
T_1 * V_65 ;
struct V_33 * * V_28 ;
struct V_47 * V_48 ;
int V_74 ;
int V_26 ;
T_4 V_66 ;
T_2 V_81 = V_79 ? ( * V_79 ) : 0 ;
if ( V_5 == 0 )
return 0 ;
if ( V_3 -> type == V_6 ) {
T_1 * V_82 , * V_83 ;
V_82 = ( V_78 == V_84 ) ?
V_62 : ( ( void * ) ( V_63 ) V_4 ) ;
V_83 = ( V_78 == V_84 ) ?
( ( void * ) ( V_63 ) V_4 ) : V_62 ;
if ( V_79 )
* V_79 = F_31 ( * V_79 , V_82 , V_5 ) ;
memcpy ( V_83 , V_82 , V_5 ) ;
return 0 ;
}
F_21 ( ! V_3 -> V_28 ) ;
V_53 = F_2 ( V_3 , V_4 , V_5 ) ;
if ( V_53 ) {
V_53 = - V_9 ;
goto V_35;
}
F_27 ( V_3 , V_4 , & V_74 , & V_26 , & V_66 ) ;
V_28 = V_3 -> V_28 + V_74 ;
V_48 = V_28 [ 0 ] -> V_48 + V_26 ;
while ( V_5 > 0 ) {
T_1 * V_82 , * V_83 ;
V_65 = ( T_1 * ) ( V_63 ) V_48 -> V_62 + V_66 ;
V_82 = ( V_78 == V_84 ) ? V_62 : V_65 ;
V_83 = ( V_78 == V_84 ) ? V_65 : V_62 ;
V_80 = V_48 -> V_64 - V_66 ;
if ( V_80 > V_5 )
V_80 = V_5 ;
if ( V_79 )
V_81 = F_31 ( V_81 , V_82 , V_80 ) ;
memcpy ( V_83 , V_82 , V_80 ) ;
V_5 -= V_80 ;
V_62 += V_80 ;
V_66 = 0 ;
V_48 ++ ;
V_26 ++ ;
if ( V_26 == V_23 ) {
V_26 = 0 ;
V_28 ++ ;
V_48 = V_28 [ 0 ] -> V_48 ;
}
}
if ( V_79 )
* V_79 = V_81 ;
return 0 ;
V_35:
return V_53 ;
}
int F_32 (
struct V_30 * V_31 ,
struct V_40 * V_41 ,
int V_10 ,
struct V_85 * V_86 ,
void * V_62 ,
int V_5 ,
enum V_77 V_78 ,
T_2 * V_79 )
{
int V_80 ;
struct V_87 * V_88 = & V_86 -> V_88 [ V_86 -> V_89 ] ;
int V_66 = V_86 -> V_90 ;
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
if ( V_88 -> V_5 && ( V_66 < V_88 -> V_5 ) ) {
V_3 = F_33 ( V_41 , V_10 , V_88 -> V_11 , V_92 ) ;
if ( ! V_3 ) {
V_53 = - V_57 ;
goto V_35;
}
}
while ( V_5 > 0 ) {
V_80 = V_5 ;
if ( V_66 >= V_88 -> V_5 ) {
if ( V_3 ) {
F_34 ( V_3 ) ;
V_3 = NULL ;
}
V_88 ++ ;
V_86 -> V_89 ++ ;
V_66 = 0 ;
if ( V_86 -> V_89 >= V_86 -> V_93 ) {
V_53 = - V_94 ;
goto V_36;
}
if ( V_88 -> V_5 ) {
V_3 = F_33 ( V_41 , V_10 , V_88 -> V_11 ,
V_92 ) ;
if ( ! V_3 ) {
V_53 = - V_57 ;
goto V_35;
}
} else {
continue;
}
}
if ( V_80 > V_88 -> V_5 - V_66 )
V_80 = V_88 -> V_5 - V_66 ;
if ( V_80 > 0 ) {
V_4 = V_88 -> V_62 + V_66 ;
V_53 = F_30 ( V_3 , V_4 , V_62 , V_80 , V_78 , V_79 ) ;
if ( V_53 )
goto V_36;
V_66 += V_80 ;
V_91 -= V_80 ;
V_5 -= V_80 ;
V_62 += V_80 ;
}
}
V_86 -> V_90 = V_66 ;
V_86 -> V_91 = V_91 ;
if ( V_3 )
F_34 ( V_3 ) ;
return 0 ;
V_36:
if ( V_3 )
F_34 ( V_3 ) ;
V_35:
return V_53 ;
}
int F_35 ( struct V_85 * V_86 , unsigned int V_5 )
{
struct V_87 * V_88 = & V_86 -> V_88 [ V_86 -> V_89 ] ;
int V_66 = V_86 -> V_90 ;
int V_91 = V_86 -> V_91 ;
while ( V_5 ) {
unsigned int V_80 ;
if ( V_66 >= V_88 -> V_5 ) {
V_88 ++ ;
V_86 -> V_89 ++ ;
V_66 = 0 ;
if ( V_86 -> V_89 >= V_86 -> V_93 )
return - V_94 ;
}
V_80 = V_5 ;
if ( V_80 > V_88 -> V_5 - V_66 )
V_80 = V_88 -> V_5 - V_66 ;
V_66 += V_80 ;
V_91 -= V_80 ;
V_5 -= V_80 ;
}
V_86 -> V_90 = V_66 ;
V_86 -> V_91 = V_91 ;
return 0 ;
}
struct V_2 * F_33 ( struct V_40 * V_41 , int V_10 , T_2 V_1 ,
enum V_95 type )
{
struct V_2 * V_3 ;
struct V_30 * V_31 = F_36 ( V_41 -> V_54 . V_96 ) ;
int V_13 = V_1 >> 8 ;
if ( V_13 >= V_97 && V_13 <= V_98 ) {
V_3 = F_37 ( & V_31 -> V_99 , V_13 ) ;
if ( ! V_3 )
goto V_35;
} else {
goto V_35;
}
if ( ( type == V_92 && V_3 -> V_11 != V_1 ) ||
( type == V_100 && V_3 -> V_14 != V_1 ) )
goto V_36;
if ( V_3 -> V_41 != V_41 )
goto V_36;
if ( V_10 && ! ( V_10 & V_3 -> V_10 ) )
goto V_36;
if ( V_3 -> V_19 != V_42 )
goto V_36;
return V_3 ;
V_36:
F_34 ( V_3 ) ;
V_35:
return NULL ;
}
int F_38 ( struct V_30 * V_31 , struct V_2 * V_3 ,
T_3 * V_101 , int V_102 , T_3 V_4 )
{
int V_26 ;
int V_32 ;
int V_53 ;
struct V_33 * * V_28 ;
struct V_47 * V_48 ;
int V_59 ;
if ( V_102 > V_3 -> V_38 ) {
V_53 = - V_57 ;
goto V_35;
}
V_32 = 0 ;
V_59 = 1 << V_3 -> V_60 ;
V_28 = V_3 -> V_28 ;
V_48 = V_28 [ 0 ] -> V_48 ;
for ( V_26 = 0 ; V_26 < V_102 ; V_26 ++ ) {
V_48 -> V_62 = * V_101 ++ ;
V_48 -> V_64 = V_59 ;
V_48 ++ ;
V_32 ++ ;
if ( V_32 == V_23 ) {
V_28 ++ ;
V_48 = V_28 [ 0 ] -> V_48 ;
V_32 = 0 ;
}
}
V_3 -> V_4 = V_4 ;
V_3 -> V_65 = V_4 ;
V_3 -> V_5 = V_102 << V_3 -> V_60 ;
V_3 -> V_19 = V_42 ;
return 0 ;
V_35:
return V_53 ;
}
