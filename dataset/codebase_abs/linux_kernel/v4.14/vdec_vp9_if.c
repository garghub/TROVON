static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_7 -> V_8 ) ; V_5 ++ ) {
if ( V_4 == & V_7 -> V_8 [ V_5 ] . V_4 )
return true ;
}
return false ;
}
static struct V_3 * F_3 ( struct V_1
* V_2 , void * V_9 )
{
struct V_3 * V_4 = NULL ;
struct V_10 * V_11 ;
F_4 (node, &inst->fb_use_list, list) {
V_4 = (struct V_3 * ) V_11 -> V_4 ;
if ( V_4 -> V_12 . V_13 == V_9 ) {
F_5 ( & V_11 -> V_14 ,
& V_2 -> V_15 ) ;
break;
}
}
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 ;
if ( V_4 ) {
V_11 = F_7 ( & V_2 -> V_15 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_4 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_16 ) ;
}
} else {
F_8 ( V_2 , L_1 ) ;
}
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_17 * V_8 =
F_10 ( V_4 , struct V_17 , V_4 ) ;
V_8 -> V_18 = 0 ;
}
static void F_11 ( struct V_1 * V_2 , int * V_19 ,
int V_20 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_21 = * V_19 ;
if ( V_21 >= 0 && V_7 -> V_22 [ V_21 ] . V_23 > 0 ) {
V_7 -> V_22 [ V_21 ] . V_23 -- ;
if ( V_7 -> V_22 [ V_21 ] . V_23 == 0 ) {
if ( ! F_1 ( V_2 ,
V_7 -> V_22 [ V_21 ] . V_24 . V_4 ) ) {
struct V_3 * V_4 ;
V_4 = F_3 ( V_2 ,
V_7 -> V_22 [ V_21 ] . V_24 . V_4 -> V_12 . V_13 ) ;
F_6 ( V_2 , V_4 ) ;
} else
F_9 (
V_7 -> V_22 [ V_21 ] . V_24 . V_4 ) ;
}
}
* V_19 = V_20 ;
V_7 -> V_22 [ V_20 ] . V_23 ++ ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_7 -> V_8 ) ; V_5 ++ ) {
if ( V_7 -> V_8 [ V_5 ] . V_4 . V_12 . V_13 ) {
F_13 ( V_2 -> V_25 ,
& V_7 -> V_8 [ V_5 ] . V_4 . V_12 ) ;
F_13 ( V_2 -> V_25 ,
& V_7 -> V_8 [ V_5 ] . V_4 . V_26 ) ;
V_7 -> V_8 [ V_5 ] . V_18 = 0 ;
}
}
}
static int F_14 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_27 * V_28 ;
struct V_27 * V_29 ;
struct V_6 * V_7 = V_2 -> V_7 ;
for ( V_19 = 0 ;
V_19 < F_2 ( V_7 -> V_8 ) ;
V_19 ++ ) {
if ( V_7 -> V_8 [ V_19 ] . V_4 . V_12 . V_13 &&
V_7 -> V_8 [ V_19 ] . V_18 == 0 ) {
return V_19 ;
}
}
for ( V_19 = 0 ;
V_19 < F_2 ( V_7 -> V_8 ) ;
V_19 ++ ) {
if ( V_7 -> V_8 [ V_19 ] . V_4 . V_12 . V_13 == NULL )
break;
}
if ( V_19 == F_2 ( V_7 -> V_8 ) ) {
F_15 ( V_2 , L_2 ) ;
return - 1 ;
}
V_28 = & V_7 -> V_8 [ V_19 ] . V_4 . V_12 ;
V_28 -> V_30 = V_7 -> V_31 +
V_7 -> V_32 ;
if ( F_16 ( V_2 -> V_25 , V_28 ) ) {
F_15 ( V_2 , L_3 ) ;
return - 1 ;
}
V_29 = & V_7 -> V_8 [ V_19 ] . V_4 . V_26 ;
V_29 -> V_30 = V_7 -> V_33 +
V_7 -> V_34 ;
if ( F_16 ( V_2 -> V_25 , V_29 ) ) {
F_15 ( V_2 , L_4 ) ;
return - 1 ;
}
V_7 -> V_8 [ V_19 ] . V_18 = 0 ;
return V_19 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_35 ;
struct V_27 * V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
if ( ! ( V_2 -> V_25 -> V_39 -> V_40 &
V_41 ) ) {
V_37 = V_42 ;
V_38 = V_43 ;
} else {
V_37 = V_44 ;
V_38 = V_45 ;
}
if ( ( V_7 -> V_46 > V_37 ) ||
( V_7 -> V_47 > V_38 ) ) {
F_15 ( V_2 , L_5 ,
V_7 -> V_46 , V_7 -> V_47 ) ;
return false ;
}
F_8 ( V_2 , L_6 ,
V_7 -> V_48 ,
V_7 -> V_46 ,
V_7 -> V_47 ,
V_7 -> V_49 ,
V_7 -> V_50 ) ;
V_36 = & V_2 -> V_51 ;
if ( V_36 -> V_13 )
F_13 ( V_2 -> V_25 , V_36 ) ;
V_36 -> V_30 = ( ( V_7 -> V_49 / 64 ) *
( V_7 -> V_50 / 64 ) + 2 ) * 36 * 16 ;
V_35 = F_16 ( V_2 -> V_25 , V_36 ) ;
if ( V_35 ) {
V_36 -> V_30 = 0 ;
F_15 ( V_2 , L_7 ) ;
return false ;
}
V_7 -> V_51 . V_13 = ( unsigned long ) V_36 -> V_13 ;
V_7 -> V_51 . V_52 = ( unsigned long ) V_36 -> V_53 ;
V_7 -> V_51 . V_54 = ( unsigned int ) V_36 -> V_30 ;
V_36 = & V_2 -> V_55 ;
if ( V_36 -> V_13 )
F_13 ( V_2 -> V_25 , V_36 ) ;
V_36 -> V_30 = V_56 ;
V_35 = F_16 ( V_2 -> V_25 , V_36 ) ;
if ( V_35 ) {
V_36 -> V_30 = 0 ;
F_15 ( V_2 , L_8 ) ;
return false ;
}
V_7 -> V_55 . V_13 = ( unsigned long ) V_36 -> V_13 ;
V_7 -> V_55 . V_52 = ( unsigned long ) V_36 -> V_53 ;
V_7 -> V_55 . V_54 = ( unsigned int ) V_36 -> V_30 ;
F_12 ( V_2 ) ;
V_7 -> V_57 = F_14 ( V_2 ) ;
return true ;
}
static bool F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_4 ) {
F_15 ( V_2 , L_9 ) ;
return false ;
}
V_11 = F_7 ( & V_2 -> V_15 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_4 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_58 ) ;
} else {
F_15 ( V_2 , L_10 ) ;
return false ;
}
return true ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_59 * V_60 ;
int V_61 = 0 , V_62 ;
for ( V_62 = V_7 -> V_63 ; V_62 ; V_62 >>= 1 ) {
if ( V_62 & 1 )
F_11 ( V_2 , & V_7 -> V_64 [ V_61 ] ,
V_7 -> V_65 ) ;
++ V_61 ;
}
V_60 = & V_7 -> V_22 [ V_7 -> V_65 ] . V_24 ;
V_7 -> V_22 [ V_7 -> V_65 ] . V_23 -- ;
if ( V_60 -> V_4 != V_2 -> V_66 ) {
if ( ( V_60 -> V_4 != NULL ) &&
( V_2 -> V_66 -> V_12 . V_30 >=
V_60 -> V_4 -> V_12 . V_30 ) ) {
memcpy ( ( void * ) V_2 -> V_66 -> V_12 . V_13 ,
( void * ) V_60 -> V_4 -> V_12 . V_13 ,
V_7 -> V_49 *
V_7 -> V_50 ) ;
memcpy ( ( void * ) V_2 -> V_66 -> V_26 . V_13 ,
( void * ) V_60 -> V_4 -> V_26 . V_13 ,
V_7 -> V_49 *
V_7 -> V_50 / 2 ) ;
} else {
if ( V_60 -> V_4 != NULL )
F_15 ( V_2 ,
L_11 ,
V_2 -> V_66 -> V_12 . V_30 ,
V_60 -> V_4 -> V_12 . V_30 ) ;
}
if ( ! F_1 ( V_2 , V_2 -> V_66 ) ) {
if ( V_7 -> V_67 )
F_18 ( V_2 , V_2 -> V_66 ) ;
}
} else {
if ( ! F_1 ( V_2 , V_2 -> V_66 ) ) {
if ( V_7 -> V_67 )
F_18 ( V_2 , V_60 -> V_4 ) ;
}
}
if ( V_7 -> V_22 [ V_7 -> V_65 ] . V_23 == 0 ) {
if ( ! F_1 (
V_2 , V_7 -> V_22 [ V_7 -> V_65 ] . V_24 . V_4 ) ) {
struct V_3 * V_4 ;
V_4 = F_3 ( V_2 ,
V_7 -> V_22 [ V_7 -> V_65 ] . V_24 . V_4 -> V_12 . V_13 ) ;
F_6 ( V_2 , V_4 ) ;
} else {
F_9 (
V_7 -> V_22 [ V_7 -> V_65 ] . V_24 . V_4 ) ;
}
}
if ( V_7 -> V_68 > 0 && V_7 -> V_69 != V_7 -> V_68 - 1 )
V_7 -> V_57 = F_14 ( V_2 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
struct V_70 * V_25 = V_2 -> V_25 ;
F_21 ( V_2 -> V_25 ,
V_71 ,
V_72 ) ;
if ( V_25 -> V_73 & V_74 )
return true ;
else
return false ;
}
static struct V_1 * F_22 ( struct V_70 * V_25 )
{
int V_35 ;
struct V_27 V_36 ;
struct V_1 * V_2 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_30 = sizeof( struct V_1 ) ;
V_35 = F_16 ( V_25 , & V_36 ) ;
if ( V_35 )
return NULL ;
V_2 = V_36 . V_13 ;
V_2 -> V_36 = V_36 ;
return V_2 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_27 V_36 ;
V_36 = V_2 -> V_36 ;
if ( V_36 . V_13 )
F_13 ( V_2 -> V_25 , & V_36 ) ;
}
static bool F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
bool V_75 = false ;
if ( ! V_7 -> V_76 ) {
V_75 = F_20 ( V_2 ) ;
if ( ! V_75 ) {
F_15 ( V_2 , L_12 ,
V_7 -> V_77 ) ;
return false ;
}
if ( F_25 ( & V_2 -> V_78 ) ) {
F_15 ( V_2 , L_13 ) ;
return false ;
}
F_8 ( V_2 , L_14 , V_7 -> V_77 ,
V_7 -> V_46 , V_7 -> V_47 ) ;
} else {
F_8 ( V_2 , L_15 ,
V_7 -> V_77 ) ;
}
F_19 ( V_2 ) ;
V_7 -> V_77 ++ ;
return true ;
}
static bool F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_7 -> V_68 <= 0 || V_7 -> V_69 == V_7 -> V_68 )
return true ;
return false ;
}
static struct V_3 * F_27 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 = NULL ;
V_11 = F_7 ( & V_2 -> V_58 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_4 = (struct V_3 * ) V_11 -> V_4 ;
V_4 -> V_79 |= V_80 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_15 ) ;
F_8 ( V_2 , L_16 ,
V_11 -> V_4 , V_4 -> V_79 ) ;
} else
F_8 ( V_2 , L_17 ) ;
return V_4 ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_4 ) {
F_8 ( V_2 , L_9 ) ;
return false ;
}
V_11 = F_7 ( & V_2 -> V_15 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_4 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_81 ) ;
} else {
F_15 ( V_2 , L_1 ) ;
return false ;
}
return true ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_82 ;
F_30 (node, tmp, &inst->fb_use_list, list)
F_5 ( & V_11 -> V_14 , & V_2 -> V_16 ) ;
F_12 ( V_2 ) ;
V_2 -> V_7 -> V_57 = F_14 ( V_2 ) ;
if ( F_31 ( & V_2 -> V_78 ) )
F_15 ( V_2 , L_18 ) ;
V_2 -> V_7 -> V_51 . V_13 = ( unsigned long ) V_2 -> V_51 . V_13 ;
V_2 -> V_7 -> V_51 . V_52 = ( unsigned long ) V_2 -> V_51 . V_53 ;
V_2 -> V_7 -> V_51 . V_54 = ( unsigned long ) V_2 -> V_51 . V_30 ;
V_2 -> V_7 -> V_55 . V_13 = ( unsigned long ) V_2 -> V_55 . V_13 ;
V_2 -> V_7 -> V_55 . V_52 = ( unsigned long ) V_2 -> V_55 . V_53 ;
V_2 -> V_7 -> V_55 . V_54 = ( unsigned long ) V_2 -> V_55 . V_30 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_5 ;
F_33 ( & V_2 -> V_15 ) ;
F_33 ( & V_2 -> V_81 ) ;
F_33 ( & V_2 -> V_16 ) ;
F_33 ( & V_2 -> V_58 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_2 -> V_83 ) ; V_5 ++ ) {
F_33 ( & V_2 -> V_83 [ V_5 ] . V_14 ) ;
V_2 -> V_83 [ V_5 ] . V_4 = NULL ;
F_34 ( & V_2 -> V_83 [ V_5 ] . V_14 ,
& V_2 -> V_15 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
V_85 -> V_86 = V_2 -> V_7 -> V_31 ;
V_85 -> V_87 = V_2 -> V_7 -> V_33 ;
V_85 -> V_88 = V_2 -> V_7 -> V_32 ;
V_85 -> V_89 = V_2 -> V_7 -> V_34 ;
V_85 -> V_46 = V_2 -> V_7 -> V_46 ;
V_85 -> V_47 = V_2 -> V_7 -> V_47 ;
V_85 -> V_49 = V_2 -> V_7 -> V_49 ;
V_85 -> V_50 = V_2 -> V_7 -> V_50 ;
F_8 ( V_2 , L_19 ,
V_85 -> V_46 , V_85 -> V_47 , V_85 -> V_49 , V_85 -> V_50 ) ;
F_8 ( V_2 , L_20 , V_85 -> V_86 ,
V_85 -> V_88 , V_85 -> V_87 , V_85 -> V_89 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * * V_90 )
{
* V_90 = F_27 ( V_2 ) ;
if ( * V_90 )
( * V_90 ) -> V_79 |= V_80 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_3 * * V_90 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 = NULL ;
V_11 = F_7 ( & V_2 -> V_16 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
F_5 ( & V_11 -> V_14 , & V_2 -> V_15 ) ;
V_4 = (struct V_3 * ) V_11 -> V_4 ;
V_4 -> V_79 |= V_91 ;
F_8 ( V_2 , L_21 ,
V_11 -> V_4 , V_4 -> V_79 ) ;
} else {
F_8 ( V_2 , L_22 ) ;
}
* V_90 = V_4 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_6 * V_7 ) {
if ( V_7 -> V_69 >= V_92 - 1 ) {
F_15 ( V_2 , L_23 ,
V_7 -> V_69 ) ;
return - V_93 ;
}
if ( V_7 -> V_94 >= V_92 ) {
F_15 ( V_2 , L_24 ,
V_7 -> V_94 ) ;
return - V_93 ;
}
if ( V_7 -> V_65 >= V_92 ) {
F_15 ( V_2 , L_25 ,
V_7 -> V_65 ) ;
return - V_93 ;
}
return 0 ;
}
static void F_39 ( unsigned long V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
struct V_27 * V_36 ;
int V_75 = 0 ;
V_75 = F_40 ( & V_2 -> V_78 ) ;
if ( V_75 )
F_15 ( V_2 , L_26 ) ;
V_36 = & V_2 -> V_51 ;
if ( V_36 -> V_13 )
F_13 ( V_2 -> V_25 , V_36 ) ;
V_36 = & V_2 -> V_55 ;
if ( V_36 -> V_13 )
F_13 ( V_2 -> V_25 , V_36 ) ;
F_12 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static int F_41 ( struct V_70 * V_25 , unsigned long * V_95 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_25 ) ;
if ( ! V_2 )
return - V_96 ;
V_2 -> V_97 = 0 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_78 . V_98 = V_99 ;
V_2 -> V_78 . V_39 = V_25 -> V_39 -> V_100 ;
V_2 -> V_78 . V_25 = V_25 ;
V_2 -> V_78 . V_101 = V_102 ;
if ( F_42 ( & V_2 -> V_78 ) ) {
F_15 ( V_2 , L_27 ) ;
goto V_103;
}
V_2 -> V_7 = (struct V_6 * ) V_2 -> V_78 . V_7 ;
F_32 ( V_2 ) ;
( * V_95 ) = ( unsigned long ) V_2 ;
return 0 ;
V_103:
F_23 ( V_2 ) ;
return - V_104 ;
}
static int F_43 ( unsigned long V_95 , struct V_27 * V_105 ,
struct V_3 * V_4 , bool * V_106 )
{
int V_75 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_107 [ 3 ] ;
int V_5 ;
* V_106 = false ;
if ( ( V_105 == NULL ) && ( V_4 == NULL ) ) {
F_8 ( V_2 , L_28 ) ;
F_29 ( V_2 ) ;
return V_75 ;
}
if ( V_105 == NULL ) {
F_15 ( V_2 , L_29 ) ;
return - V_104 ;
}
F_8 ( V_2 , L_30 , V_105 -> V_30 ) ;
while ( 1 ) {
struct V_3 * V_66 = NULL ;
V_107 [ 0 ] = * ( ( unsigned int * ) V_105 -> V_13 ) ;
V_107 [ 1 ] = * ( ( unsigned int * ) ( V_105 -> V_13 + 4 ) ) ;
V_107 [ 2 ] = * ( ( unsigned int * ) ( V_105 -> V_13 + 8 ) ) ;
V_7 -> V_105 = * V_105 ;
if ( V_4 )
V_7 -> V_4 = * V_4 ;
if ( ! V_7 -> V_108 ) {
unsigned int V_109 ;
unsigned int V_110 ;
unsigned char * V_111 ;
unsigned char * V_112 ;
V_109 = V_105 -> V_30 > V_113 ?
V_113 : V_105 -> V_30 ;
V_110 = V_113 - V_109 ;
V_111 = V_105 -> V_13 + V_105 -> V_30 - V_109 ;
V_112 = V_7 -> V_114 + V_110 ;
memcpy ( V_112 , V_111 , V_109 ) ;
} else {
if ( ( V_7 -> V_68 > 0 ) &&
( V_7 -> V_69 < V_7 -> V_68 ) ) {
unsigned int V_19 = V_7 -> V_69 ;
memcpy ( ( void * ) V_105 -> V_13 ,
( void * ) ( V_105 -> V_13 +
V_7 -> V_115 [ V_19 ] ) ,
V_7 -> V_116 [ V_19 ] ) ;
}
}
memset ( V_2 -> V_55 . V_13 , 0 , V_2 -> V_55 . V_30 ) ;
V_75 = F_44 ( & V_2 -> V_78 , V_107 , 3 ) ;
if ( V_75 ) {
F_15 ( V_2 , L_31 ) ;
goto V_117;
}
V_75 = F_38 ( V_2 , V_7 ) ;
if ( V_75 ) {
F_15 ( V_2 , L_32 ) ;
goto V_117;
}
if ( V_7 -> V_48 ) {
if ( ! F_17 ( V_2 ) ) {
V_75 = - V_104 ;
goto V_117;
}
}
if ( V_7 -> V_68 > 0 ) {
V_66 = & V_7 -> V_8 [ V_7 -> V_57 ] . V_4 ;
if ( V_7 -> V_69 < V_7 -> V_68 )
V_2 -> V_66 = V_66 ;
else
V_2 -> V_66 = V_4 ;
} else {
V_2 -> V_66 = V_4 ;
}
V_7 -> V_22 [ V_7 -> V_65 ] . V_24 . V_4 = V_2 -> V_66 ;
if ( ! F_1 ( V_2 , V_2 -> V_66 ) )
F_28 ( V_2 , V_2 -> V_66 ) ;
F_8 ( V_2 , L_33 , V_7 -> V_77 ) ;
if ( V_7 -> V_76 )
F_8 ( V_2 ,
L_34 ,
V_7 -> V_65 , V_7 -> V_94 ) ;
if ( V_7 -> V_76 && ( V_7 -> V_94 <
V_92 ) ) {
F_15 ( V_2 ,
L_35 ,
V_7 -> V_65 , V_7 -> V_94 ) ;
F_11 ( V_2 , & V_7 -> V_65 ,
V_7 -> V_94 ) ;
V_75 = - V_104 ;
goto V_117;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_7 -> V_118 ) ; V_5 ++ ) {
unsigned int V_19 = V_7 -> V_118 [ V_5 ] . V_19 ;
V_7 -> V_118 [ V_5 ] . V_24 = & V_7 -> V_22 [ V_19 ] . V_24 ;
}
if ( V_7 -> V_48 ) {
* V_106 = true ;
F_8 ( V_2 , L_36 ) ;
V_75 = 0 ;
goto V_117;
}
if ( F_24 ( V_2 ) != true ) {
F_15 ( V_2 , L_37 ) ;
V_75 = - V_104 ;
goto V_117;
}
if ( F_26 ( V_2 ) )
break;
}
V_2 -> V_97 ++ ;
V_117:
if ( V_75 < 0 )
F_6 ( V_2 , V_4 ) ;
return V_75 ;
}
static void F_45 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
V_120 -> V_121 = 0 ;
V_120 -> V_122 = 0 ;
V_120 -> V_123 = V_2 -> V_7 -> V_46 ;
V_120 -> V_124 = V_2 -> V_7 -> V_47 ;
F_8 ( V_2 , L_38 ,
V_120 -> V_121 , V_120 -> V_122 , V_120 -> V_123 , V_120 -> V_124 ) ;
}
static int F_46 ( unsigned long V_95 ,
enum V_125 type , void * V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
int V_75 = 0 ;
switch ( type ) {
case V_127 :
F_36 ( V_2 , V_126 ) ;
break;
case V_128 :
F_37 ( V_2 , V_126 ) ;
break;
case V_129 :
F_35 ( V_2 , V_126 ) ;
break;
case V_130 :
* ( ( unsigned int * ) V_126 ) = V_131 ;
break;
case V_132 :
F_45 ( V_2 , V_126 ) ;
break;
default:
F_15 ( V_2 , L_39 , type ) ;
V_75 = - V_104 ;
break;
}
return V_75 ;
}
struct V_133 * F_47 ( void )
{
return & V_134 ;
}
