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
F_12 ( V_2 ) ;
V_7 -> V_55 = F_14 ( V_2 ) ;
return true ;
}
static bool F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_4 ) {
F_15 ( V_2 , L_8 ) ;
return false ;
}
V_11 = F_7 ( & V_2 -> V_15 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_4 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_56 ) ;
} else {
F_15 ( V_2 , L_9 ) ;
return false ;
}
return true ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_57 * V_58 ;
int V_59 = 0 , V_60 ;
for ( V_60 = V_7 -> V_61 ; V_60 ; V_60 >>= 1 ) {
if ( V_60 & 1 )
F_11 ( V_2 , & V_7 -> V_62 [ V_59 ] ,
V_7 -> V_63 ) ;
++ V_59 ;
}
V_58 = & V_7 -> V_22 [ V_7 -> V_63 ] . V_24 ;
V_7 -> V_22 [ V_7 -> V_63 ] . V_23 -- ;
if ( V_58 -> V_4 != V_2 -> V_64 ) {
if ( ( V_58 -> V_4 != NULL ) &&
( V_2 -> V_64 -> V_12 . V_30 >=
V_58 -> V_4 -> V_12 . V_30 ) ) {
memcpy ( ( void * ) V_2 -> V_64 -> V_12 . V_13 ,
( void * ) V_58 -> V_4 -> V_12 . V_13 ,
V_7 -> V_49 *
V_7 -> V_50 ) ;
memcpy ( ( void * ) V_2 -> V_64 -> V_26 . V_13 ,
( void * ) V_58 -> V_4 -> V_26 . V_13 ,
V_7 -> V_49 *
V_7 -> V_50 / 2 ) ;
} else {
if ( V_58 -> V_4 != NULL )
F_15 ( V_2 ,
L_10 ,
V_2 -> V_64 -> V_12 . V_30 ,
V_58 -> V_4 -> V_12 . V_30 ) ;
}
if ( ! F_1 ( V_2 , V_2 -> V_64 ) ) {
if ( V_7 -> V_65 )
F_18 ( V_2 , V_2 -> V_64 ) ;
}
} else {
if ( ! F_1 ( V_2 , V_2 -> V_64 ) ) {
if ( V_7 -> V_65 )
F_18 ( V_2 , V_58 -> V_4 ) ;
}
}
if ( V_7 -> V_22 [ V_7 -> V_63 ] . V_23 == 0 ) {
if ( ! F_1 (
V_2 , V_7 -> V_22 [ V_7 -> V_63 ] . V_24 . V_4 ) ) {
struct V_3 * V_4 ;
V_4 = F_3 ( V_2 ,
V_7 -> V_22 [ V_7 -> V_63 ] . V_24 . V_4 -> V_12 . V_13 ) ;
F_6 ( V_2 , V_4 ) ;
} else {
F_9 (
V_7 -> V_22 [ V_7 -> V_63 ] . V_24 . V_4 ) ;
}
}
if ( V_7 -> V_66 > 0 && V_7 -> V_67 != V_7 -> V_66 - 1 )
V_7 -> V_55 = F_14 ( V_2 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
struct V_68 * V_25 = V_2 -> V_25 ;
F_21 ( V_2 -> V_25 ,
V_69 ,
V_70 ) ;
if ( V_25 -> V_71 & V_72 )
return true ;
else
return false ;
}
static struct V_1 * F_22 ( struct V_68 * V_25 )
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
bool V_73 = false ;
if ( ! V_7 -> V_74 ) {
V_73 = F_20 ( V_2 ) ;
if ( ! V_73 ) {
F_15 ( V_2 , L_11 ,
V_7 -> V_75 ) ;
return false ;
}
if ( F_25 ( & V_2 -> V_76 ) ) {
F_15 ( V_2 , L_12 ) ;
return false ;
}
F_8 ( V_2 , L_13 , V_7 -> V_75 ,
V_7 -> V_46 , V_7 -> V_47 ) ;
} else {
F_8 ( V_2 , L_14 ,
V_7 -> V_75 ) ;
}
F_19 ( V_2 ) ;
V_7 -> V_75 ++ ;
return true ;
}
static bool F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_7 -> V_66 <= 0 || V_7 -> V_67 == V_7 -> V_66 )
return true ;
return false ;
}
static struct V_3 * F_27 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 = NULL ;
V_11 = F_7 ( & V_2 -> V_56 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_4 = (struct V_3 * ) V_11 -> V_4 ;
V_4 -> V_77 |= V_78 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_15 ) ;
F_8 ( V_2 , L_15 ,
V_11 -> V_4 , V_4 -> V_77 ) ;
} else
F_8 ( V_2 , L_16 ) ;
return V_4 ;
}
static bool F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 ;
if ( ! V_4 ) {
F_8 ( V_2 , L_8 ) ;
return false ;
}
V_11 = F_7 ( & V_2 -> V_15 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
V_11 -> V_4 = V_4 ;
F_5 ( & V_11 -> V_14 , & V_2 -> V_79 ) ;
} else {
F_15 ( V_2 , L_1 ) ;
return false ;
}
return true ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_80 ;
F_30 (node, tmp, &inst->fb_use_list, list)
F_5 ( & V_11 -> V_14 , & V_2 -> V_16 ) ;
F_12 ( V_2 ) ;
V_2 -> V_7 -> V_55 = F_14 ( V_2 ) ;
if ( F_31 ( & V_2 -> V_76 ) )
F_15 ( V_2 , L_17 ) ;
V_2 -> V_7 -> V_51 . V_13 = ( unsigned long ) V_2 -> V_51 . V_13 ;
V_2 -> V_7 -> V_51 . V_52 = ( unsigned long ) V_2 -> V_51 . V_53 ;
V_2 -> V_7 -> V_51 . V_54 = ( unsigned long ) V_2 -> V_51 . V_30 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_5 ;
F_33 ( & V_2 -> V_15 ) ;
F_33 ( & V_2 -> V_79 ) ;
F_33 ( & V_2 -> V_16 ) ;
F_33 ( & V_2 -> V_56 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_2 -> V_81 ) ; V_5 ++ ) {
F_33 ( & V_2 -> V_81 [ V_5 ] . V_14 ) ;
V_2 -> V_81 [ V_5 ] . V_4 = NULL ;
F_34 ( & V_2 -> V_81 [ V_5 ] . V_14 ,
& V_2 -> V_15 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
V_83 -> V_84 = V_2 -> V_7 -> V_31 ;
V_83 -> V_85 = V_2 -> V_7 -> V_33 ;
V_83 -> V_86 = V_2 -> V_7 -> V_32 ;
V_83 -> V_87 = V_2 -> V_7 -> V_34 ;
V_83 -> V_46 = V_2 -> V_7 -> V_46 ;
V_83 -> V_47 = V_2 -> V_7 -> V_47 ;
V_83 -> V_49 = V_2 -> V_7 -> V_49 ;
V_83 -> V_50 = V_2 -> V_7 -> V_50 ;
F_8 ( V_2 , L_18 ,
V_83 -> V_46 , V_83 -> V_47 , V_83 -> V_49 , V_83 -> V_50 ) ;
F_8 ( V_2 , L_19 , V_83 -> V_84 ,
V_83 -> V_86 , V_83 -> V_85 , V_83 -> V_87 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * * V_88 )
{
* V_88 = F_27 ( V_2 ) ;
if ( * V_88 )
( * V_88 ) -> V_77 |= V_78 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_3 * * V_88 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 = NULL ;
V_11 = F_7 ( & V_2 -> V_16 ,
struct V_10 , V_14 ) ;
if ( V_11 ) {
F_5 ( & V_11 -> V_14 , & V_2 -> V_15 ) ;
V_4 = (struct V_3 * ) V_11 -> V_4 ;
V_4 -> V_77 |= V_89 ;
F_8 ( V_2 , L_20 ,
V_11 -> V_4 , V_4 -> V_77 ) ;
} else {
F_8 ( V_2 , L_21 ) ;
}
* V_88 = V_4 ;
}
static void F_38 ( unsigned long V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
struct V_27 * V_36 ;
int V_73 = 0 ;
V_73 = F_39 ( & V_2 -> V_76 ) ;
if ( V_73 )
F_15 ( V_2 , L_22 ) ;
V_36 = & V_2 -> V_51 ;
if ( V_36 -> V_13 )
F_13 ( V_2 -> V_25 , V_36 ) ;
F_12 ( V_2 ) ;
F_23 ( V_2 ) ;
}
static int F_40 ( struct V_68 * V_25 , unsigned long * V_90 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_25 ) ;
if ( ! V_2 )
return - V_91 ;
V_2 -> V_92 = 0 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_76 . V_93 = V_94 ;
V_2 -> V_76 . V_39 = V_25 -> V_39 -> V_95 ;
V_2 -> V_76 . V_25 = V_25 ;
V_2 -> V_76 . V_96 = V_97 ;
if ( F_41 ( & V_2 -> V_76 ) ) {
F_15 ( V_2 , L_23 ) ;
goto V_98;
}
V_2 -> V_7 = (struct V_6 * ) V_2 -> V_76 . V_7 ;
F_32 ( V_2 ) ;
( * V_90 ) = ( unsigned long ) V_2 ;
return 0 ;
V_98:
F_23 ( V_2 ) ;
return - V_99 ;
}
static int F_42 ( unsigned long V_90 , struct V_27 * V_100 ,
struct V_3 * V_4 , bool * V_101 )
{
int V_73 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_102 [ 3 ] ;
int V_5 ;
* V_101 = false ;
if ( ( V_100 == NULL ) && ( V_4 == NULL ) ) {
F_8 ( V_2 , L_24 ) ;
F_29 ( V_2 ) ;
return V_73 ;
}
if ( V_100 == NULL ) {
F_15 ( V_2 , L_25 ) ;
return - V_99 ;
}
F_8 ( V_2 , L_26 , V_100 -> V_30 ) ;
while ( 1 ) {
struct V_3 * V_64 = NULL ;
V_102 [ 0 ] = * ( ( unsigned int * ) V_100 -> V_13 ) ;
V_102 [ 1 ] = * ( ( unsigned int * ) ( V_100 -> V_13 + 4 ) ) ;
V_102 [ 2 ] = * ( ( unsigned int * ) ( V_100 -> V_13 + 8 ) ) ;
V_7 -> V_100 = * V_100 ;
if ( V_4 )
V_7 -> V_4 = * V_4 ;
if ( ! V_7 -> V_103 ) {
unsigned int V_104 ;
unsigned int V_105 ;
unsigned char * V_106 ;
unsigned char * V_107 ;
V_104 = V_100 -> V_30 > V_108 ?
V_108 : V_100 -> V_30 ;
V_105 = V_108 - V_104 ;
V_106 = V_100 -> V_13 + V_100 -> V_30 - V_104 ;
V_107 = V_7 -> V_109 + V_105 ;
memcpy ( V_107 , V_106 , V_104 ) ;
} else {
if ( ( V_7 -> V_66 > 0 ) &&
( V_7 -> V_67 < V_7 -> V_66 ) ) {
unsigned int V_19 = V_7 -> V_67 ;
memcpy ( ( void * ) V_100 -> V_13 ,
( void * ) ( V_100 -> V_13 +
V_7 -> V_110 [ V_19 ] ) ,
V_7 -> V_111 [ V_19 ] ) ;
}
}
V_73 = F_43 ( & V_2 -> V_76 , V_102 , 3 ) ;
if ( V_73 ) {
F_15 ( V_2 , L_27 ) ;
goto V_112;
}
if ( V_7 -> V_48 ) {
if ( ! F_17 ( V_2 ) ) {
V_73 = - V_99 ;
goto V_112;
}
}
if ( V_7 -> V_66 > 0 ) {
V_64 = & V_7 -> V_8 [ V_7 -> V_55 ] . V_4 ;
if ( V_7 -> V_67 < V_7 -> V_66 )
V_2 -> V_64 = V_64 ;
else
V_2 -> V_64 = V_4 ;
} else {
V_2 -> V_64 = V_4 ;
}
V_7 -> V_22 [ V_7 -> V_63 ] . V_24 . V_4 = V_2 -> V_64 ;
if ( ! F_1 ( V_2 , V_2 -> V_64 ) )
F_28 ( V_2 , V_2 -> V_64 ) ;
F_8 ( V_2 , L_28 , V_7 -> V_75 ) ;
if ( V_7 -> V_74 )
F_8 ( V_2 ,
L_29 ,
V_7 -> V_63 , V_7 -> V_113 ) ;
if ( V_7 -> V_74 && ( V_7 -> V_113 <
V_114 ) ) {
F_15 ( V_2 ,
L_30 ,
V_7 -> V_63 , V_7 -> V_113 ) ;
F_11 ( V_2 , & V_7 -> V_63 ,
V_7 -> V_113 ) ;
V_73 = - V_99 ;
goto V_112;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_7 -> V_115 ) ; V_5 ++ ) {
unsigned int V_19 = V_7 -> V_115 [ V_5 ] . V_19 ;
V_7 -> V_115 [ V_5 ] . V_24 = & V_7 -> V_22 [ V_19 ] . V_24 ;
}
if ( V_7 -> V_48 ) {
* V_101 = true ;
F_8 ( V_2 , L_31 ) ;
V_73 = 0 ;
goto V_112;
}
if ( F_24 ( V_2 ) != true ) {
F_15 ( V_2 , L_32 ) ;
V_73 = - V_99 ;
goto V_112;
}
if ( F_26 ( V_2 ) )
break;
}
V_2 -> V_92 ++ ;
V_112:
if ( V_73 < 0 )
F_6 ( V_2 , V_4 ) ;
return V_73 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
V_117 -> V_118 = 0 ;
V_117 -> V_119 = 0 ;
V_117 -> V_120 = V_2 -> V_7 -> V_46 ;
V_117 -> V_121 = V_2 -> V_7 -> V_47 ;
F_8 ( V_2 , L_33 ,
V_117 -> V_118 , V_117 -> V_119 , V_117 -> V_120 , V_117 -> V_121 ) ;
}
static int F_45 ( unsigned long V_90 ,
enum V_122 type , void * V_123 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
int V_73 = 0 ;
switch ( type ) {
case V_124 :
F_36 ( V_2 , V_123 ) ;
break;
case V_125 :
F_37 ( V_2 , V_123 ) ;
break;
case V_126 :
F_35 ( V_2 , V_123 ) ;
break;
case V_127 :
* ( ( unsigned int * ) V_123 ) = V_128 ;
break;
case V_129 :
F_44 ( V_2 , V_123 ) ;
break;
default:
F_15 ( V_2 , L_34 , type ) ;
V_73 = - V_99 ;
break;
}
return V_73 ;
}
struct V_130 * F_46 ( void )
{
return & V_131 ;
}
