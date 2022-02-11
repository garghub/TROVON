static int F_1 ( const char * V_1 , const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
char V_6 [ 32 ] ;
if ( V_3 -> V_7 )
F_2 ( V_6 , F_3 ( & V_3 -> V_7 -> V_8 ) , sizeof( V_6 ) ) ;
else
sprintf ( V_6 , L_1 ,
F_4 ( V_3 -> V_9 ) , V_3 -> V_9 -> V_10 ) ;
return F_5 ( L_2 , V_1 , V_6 , V_3 -> V_11 , V_5 ) ;
}
static void T_1 F_6 ( struct V_12 * V_8 , unsigned int V_13 ,
T_2 * V_14 ,
T_2 * V_15 )
{
T_2 V_16 ;
struct V_17 * V_18 ;
int V_19 ;
F_7 ( L_3 , F_8 ( V_8 ) ) ;
* V_14 = * V_15 = 0 ;
for ( V_19 = 0 ; V_19 <= V_20 ; V_19 ++ ) {
V_18 = & V_8 -> V_17 [ V_19 ] ;
if ( ! ( V_18 -> V_13 & V_13 ) )
continue;
if ( V_18 -> V_16 ) {
V_18 -> V_21 -= V_18 -> V_16 ;
V_18 -> V_16 = 0 ;
}
V_18 -> V_13 |= V_22 ;
}
V_16 = 0 ;
for (; ; ) {
T_2 V_23 = 0 ;
int V_24 = - 1 ;
for ( V_19 = 0 ; V_19 <= V_20 ; V_19 ++ ) {
V_18 = & V_8 -> V_17 [ V_19 ] ;
if ( ! ( V_18 -> V_13 & V_22 ) ||
! ( V_18 -> V_13 & V_13 ) )
continue;
if ( F_9 ( V_18 ) > V_23 ) {
V_23 = F_9 ( V_18 ) ;
V_24 = V_19 ;
}
}
if ( V_24 < 0 )
break;
V_18 = & V_8 -> V_17 [ V_24 ] ;
if ( V_23 > * V_15 )
* V_15 = V_23 ;
* V_14 += V_23 ;
V_18 -> V_16 = V_16 ;
V_16 += V_23 ;
V_18 -> V_21 = V_18 -> V_16 + V_23 - 1 ;
V_18 -> V_13 &= ~ V_22 ;
F_7 ( L_4 ,
V_24 , V_18 -> V_16 , V_18 -> V_21 ) ;
}
F_7 ( L_5 ,
F_8 ( V_8 ) , * V_14 , * V_15 ) ;
}
static void T_1 F_10 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_12 * V_8 ,
T_2 V_14 ,
T_2 V_15 )
{
struct V_29 * V_30 , * V_31 = F_11 ( sizeof( * V_31 ) , V_32 ) ;
V_31 -> V_14 = V_14 ;
V_31 -> V_15 = V_15 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_28 = V_28 ;
F_12 (w1, list, link) {
if ( V_30 -> V_15 < V_15 ) {
F_13 ( & V_31 -> V_33 , & V_30 -> V_33 ) ;
return;
}
}
F_13 ( & V_31 -> V_33 , V_26 ) ;
}
static void T_1 F_14 ( struct V_12 * V_8 ,
unsigned int V_13 ,
T_2 V_34 )
{
struct V_17 * V_18 ;
int V_19 ;
F_7 ( L_6 , F_8 ( V_8 ) , V_13 , V_34 ) ;
for ( V_19 = 0 ; V_19 <= V_20 ; V_19 ++ ) {
V_18 = & V_8 -> V_17 [ V_19 ] ;
if ( V_18 -> V_13 & V_13 ) {
V_8 -> V_17 [ V_19 ] . V_16 += V_34 ;
V_8 -> V_17 [ V_19 ] . V_21 += V_34 ;
}
}
F_7 ( L_7 , F_8 ( V_8 ) , V_13 , V_34 ) ;
}
static void T_1 F_15 ( struct V_27 * V_28 ,
unsigned int V_13 ,
T_2 V_34 )
{
struct V_17 * V_18 ;
struct V_12 * V_8 ;
struct V_27 * V_35 ;
int V_19 ;
F_7 ( L_8 ,
V_28 -> V_36 ? F_8 ( V_28 -> V_36 ) : L_9 , V_13 , V_34 ) ;
F_16 (bus, r, i) {
if ( V_18 && ( V_18 -> V_13 & V_13 ) ) {
V_18 -> V_16 += V_34 ;
V_18 -> V_21 += V_34 ;
}
}
F_12 (dev, &bus->devices, bus_list)
F_14 ( V_8 , V_13 , V_34 ) ;
F_12 (cbus, &bus->children, node)
F_15 ( V_35 , V_13 , V_34 ) ;
F_7 ( L_10 ,
V_28 -> V_36 ? F_8 ( V_28 -> V_36 ) : L_9 , V_13 ) ;
}
static void T_1 F_17 ( struct V_27 * V_28 , unsigned int V_13 ,
T_2 * V_14 ,
T_2 * V_15 )
{
struct V_37 * V_38 = F_18 ( V_28 ) ;
struct V_39 * V_40 = V_38 -> V_41 ;
T_2 V_42 , V_43 , V_16 ;
T_2 V_44 , V_45 ;
struct V_12 * V_46 ;
struct V_27 * V_35 ;
struct V_25 V_47 ;
struct V_29 * V_31 ;
unsigned int V_48 ;
* V_14 = * V_15 = 0 ;
F_7 ( L_11 ,
V_28 -> V_36 ? F_8 ( V_28 -> V_36 ) : L_9 , V_13 ) ;
if ( V_13 & V_49 ) {
V_48 = 0 ;
V_44 = V_40 -> V_50 . V_51 ;
V_45 = 0x1000 ;
} else {
V_48 = 1 ;
V_44 = V_40 -> V_50 . V_52 ;
V_45 = 0x100000 ;
}
F_19 ( & V_47 ) ;
F_12 (cbus, &bus->children, node) {
F_17 ( V_35 , V_13 , & V_42 , & V_43 ) ;
F_10 ( & V_47 , V_35 , NULL , V_42 , V_43 ) ;
}
F_12 (cdev, &bus->devices, bus_list) {
F_6 ( V_46 , V_13 , & V_42 , & V_43 ) ;
if ( V_43 < V_44 )
V_43 = V_44 ;
F_10 ( & V_47 , NULL , V_46 , V_42 , V_43 ) ;
}
if ( F_20 ( & V_47 ) )
goto V_53;
if ( V_28 -> V_36 ) {
V_16 = 0 ;
} else {
if ( V_13 & V_49 )
V_16 = V_38 -> V_54 . V_16 + 0x1000 ;
else
V_16 = V_38 -> V_55 [ 0 ] . V_16 ;
}
while( ! F_20 ( & V_47 ) ) {
V_31 = F_21 ( & V_47 , struct V_29 , V_33 ) ;
F_22 ( & V_31 -> V_33 ) ;
if ( V_31 -> V_14 ) {
if ( V_16 ) {
V_16 = F_23 ( V_16 , V_31 -> V_15 ) ;
if ( V_31 -> V_8 )
F_14 ( V_31 -> V_8 , V_13 , V_16 ) ;
else if ( V_31 -> V_28 )
F_15 ( V_31 -> V_28 , V_13 , V_16 ) ;
}
if ( V_31 -> V_15 > * V_15 )
* V_15 = V_31 -> V_15 ;
}
V_16 += V_31 -> V_14 ;
F_24 ( V_31 ) ;
}
* V_14 = V_16 ;
* V_15 = F_25 ( T_2 , * V_15 ,
F_25 ( T_2 , V_44 , V_45 ) ) ;
* V_14 = F_23 ( * V_14 ,
F_25 ( T_2 , V_44 , V_45 ) ) ;
V_53:
if ( V_28 -> V_36 ) {
struct V_17 * V_56 = V_28 -> V_17 [ V_48 ] ;
if ( F_26 ( V_56 == NULL ) )
return;
V_56 -> V_16 = 0 ;
V_56 -> V_13 = ( * V_14 ) ? V_13 : 0 ;
V_56 -> V_21 = ( * V_14 ) ? ( * V_14 - 1 ) : 0 ;
}
F_7 ( L_12 ,
V_28 -> V_36 ? F_8 ( V_28 -> V_36 ) : L_9 , V_13 , * V_14 , * V_15 ) ;
}
static struct V_57 * F_27 ( struct V_12 * V_8 )
{
struct V_58 * V_59 ;
V_59 = F_28 ( V_8 ) ;
if ( ! V_59 )
return NULL ;
return F_29 ( V_59 ) ;
}
static void T_1 F_30 ( struct V_12 * V_8 )
{
struct V_37 * V_38 = F_18 ( V_8 -> V_28 ) ;
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_57 * V_60 = F_27 ( V_8 ) ;
unsigned int V_3 , V_19 ;
T_2 V_61 ;
struct V_17 V_62 ;
struct V_17 V_63 ;
struct V_64 V_65 ;
int V_66 ;
V_3 = V_60 ? V_60 -> V_11 : 0 ;
V_62 . V_16 = V_63 . V_16 = ( T_2 ) - 1 ;
V_62 . V_21 = V_63 . V_21 = 0 ;
V_62 . V_13 = V_49 ;
V_63 . V_13 = V_67 ;
for ( V_19 = 0 ; V_19 <= V_20 ; V_19 ++ ) {
struct V_17 * V_18 = NULL ;
if ( V_8 -> V_17 [ V_19 ] . V_13 & V_49 )
V_18 = & V_62 ;
if ( V_8 -> V_17 [ V_19 ] . V_13 & V_67 )
V_18 = & V_63 ;
if ( ! V_18 )
continue;
if ( V_8 -> V_17 [ V_19 ] . V_16 < V_18 -> V_16 )
V_18 -> V_16 = V_8 -> V_17 [ V_19 ] . V_16 ;
if ( V_8 -> V_17 [ V_19 ] . V_21 > V_18 -> V_21 )
V_18 -> V_21 = V_8 -> V_17 [ V_19 ] . V_21 ;
}
if ( V_62 . V_16 < V_62 . V_21 ) {
F_31 ( V_8 , & V_65 , & V_62 ) ;
V_61 = V_65 . V_16 ;
V_19 = V_61 / V_40 -> V_50 . V_51 ;
while( V_19 < V_40 -> V_50 . V_68 && V_61 <= V_65 . V_21 ) {
if ( V_40 -> V_50 . V_69 [ V_19 ] ) {
F_32 ( L_13
L_14 ,
F_8 ( V_8 ) , V_19 ,
V_40 -> V_50 . V_69 [ V_19 ] ) ;
break;
}
V_40 -> V_50 . V_69 [ V_19 ] = V_3 ;
V_66 = F_33 ( V_40 -> V_70 , V_3 ,
V_71 ,
0 , V_19 ) ;
if ( V_66 != V_72 ) {
F_32 ( L_15
L_16 ,
F_8 ( V_8 ) , V_66 , V_19 ) ;
break;
}
V_61 += V_40 -> V_50 . V_51 ;
V_19 ++ ;
} ;
}
if ( V_63 . V_16 < V_63 . V_21 ) {
F_31 ( V_8 , & V_65 , & V_63 ) ;
V_61 = V_65 . V_16 ;
V_19 = V_61 / V_40 -> V_50 . V_52 ;
while( V_19 < V_40 -> V_50 . V_68 && V_61 <= V_65 . V_21 ) {
if ( V_40 -> V_50 . V_73 [ V_19 ] ) {
F_32 ( L_17
L_14 ,
F_8 ( V_8 ) , V_19 ,
V_40 -> V_50 . V_73 [ V_19 ] ) ;
break;
}
V_40 -> V_50 . V_73 [ V_19 ] = V_3 ;
V_66 = F_33 ( V_40 -> V_70 , V_3 ,
V_74 ,
0 , V_19 ) ;
if ( V_66 != V_72 ) {
F_32 ( L_15
L_18 ,
F_8 ( V_8 ) , V_66 , V_19 ) ;
break;
}
V_61 += V_40 -> V_50 . V_52 ;
V_19 ++ ;
}
}
}
static int T_1 F_34 ( struct V_37 * V_38 ,
struct V_17 * V_18 )
{
struct V_17 * V_75 ;
if ( V_18 -> V_13 & V_49 )
V_75 = & V_38 -> V_54 ;
else if ( V_18 -> V_13 & V_67 )
V_75 = & V_38 -> V_55 [ 0 ] ;
else
return 1 ;
if ( V_18 -> V_16 >= V_75 -> V_16 && V_18 -> V_21 <= V_75 -> V_21 )
return 1 ;
V_18 -> V_13 = 0 ;
return 0 ;
}
static void T_1 F_35 ( struct V_27 * V_28 )
{
struct V_37 * V_38 = F_18 ( V_28 ) ;
struct V_27 * V_35 ;
struct V_12 * V_46 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_28 -> V_36 && ( V_19 < 2 ) ; V_19 ++ ) {
struct V_17 * V_18 = V_28 -> V_17 [ V_19 ] ;
if ( V_18 && ! F_34 ( V_38 , V_18 ) )
F_32 ( L_19 ,
F_8 ( V_28 -> V_36 ) , V_28 -> V_10 , V_19 ) ;
}
if ( V_28 -> V_36 )
F_36 ( V_28 ) ;
F_12 (cdev, &bus->devices, bus_list) {
for ( V_19 = 0 ; V_19 <= V_20 ; V_19 ++ ) {
struct V_17 * V_18 = & V_46 -> V_17 [ V_19 ] ;
if ( ! F_34 ( V_38 , V_18 ) )
F_32 ( L_20 ,
F_8 ( V_46 ) , V_19 ) ;
}
F_30 ( V_46 ) ;
for ( V_19 = 0 ; V_19 <= V_20 ; V_19 ++ )
F_37 ( V_46 , V_19 ) ;
}
F_12 (cbus, &bus->children, node)
F_35 ( V_35 ) ;
}
static int T_1 F_38 ( struct V_39 * V_40 )
{
unsigned long V_3 ;
do {
V_3 = F_39 ( V_40 -> V_50 . V_76 ,
V_40 -> V_50 . V_68 , 0 ) ;
if ( V_3 >= V_40 -> V_50 . V_68 )
return V_77 ;
} while( F_40 ( V_3 , V_40 -> V_50 . V_76 ) );
V_40 -> V_50 . V_78 [ V_3 ] . V_11 = V_3 ;
return V_3 ;
}
static void T_1 F_41 ( struct V_39 * V_40 , int V_3 )
{
F_26 ( V_40 -> V_50 . V_78 [ V_3 ] . V_7 ) ;
memset ( & V_40 -> V_50 . V_78 [ V_3 ] , 0 , sizeof( struct V_2 ) ) ;
F_42 ( V_3 , V_40 -> V_50 . V_76 ) ;
}
static struct V_2 * T_1 F_43 ( struct V_12 * V_8 )
{
struct V_37 * V_38 = F_18 ( V_8 -> V_28 ) ;
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_57 * V_60 = F_27 ( V_8 ) ;
if ( ! V_60 )
return NULL ;
if ( V_60 -> V_11 == V_77 )
return NULL ;
return & V_40 -> V_50 . V_78 [ V_60 -> V_11 ] ;
}
static struct V_2 * T_1 F_44 ( struct V_12 * V_8 )
{
struct V_2 * V_3 = F_43 ( V_8 ) ;
while ( ! V_3 && V_8 -> V_28 -> V_36 ) {
V_8 = V_8 -> V_28 -> V_36 ;
V_3 = F_43 ( V_8 ) ;
if ( V_3 )
V_3 = V_3 -> V_79 ;
}
return V_3 ;
}
static int T_1 F_45 ( struct V_39 * V_40 ,
struct V_2 * V_3 )
{
struct V_12 * V_80 ;
T_3 V_81 , V_82 , V_83 ;
long V_66 , V_84 , V_85 ;
if ( V_3 -> V_9 ) {
int V_86 ;
V_82 = V_87 ;
V_83 = V_88 ;
V_80 = V_3 -> V_9 -> V_36 ;
V_86 = V_3 -> V_9 -> V_89 - V_3 -> V_9 -> V_90 + 1 ;
switch( V_86 ) {
case 1 : V_81 = V_91 ; break;
case 2 : V_81 = V_92 ; break;
case 4 : V_81 = V_93 ; break;
case 8 : V_81 = V_94 ; break;
case 16 : V_81 = V_95 ; break;
case 32 : V_81 = V_96 ; break;
default:
F_32 ( L_21
L_22 ,
F_8 ( V_3 -> V_9 -> V_36 ) , V_86 ) ;
V_81 = V_91 ;
}
V_84 = V_3 -> V_85 + ( V_86 << 8 ) ;
} else {
V_80 = V_3 -> V_7 -> V_28 -> V_36 ;
V_81 = V_91 ;
V_82 = V_97 ;
V_83 = V_98 ;
V_84 = V_3 -> V_85 + 1 ;
}
V_66 = F_46 ( V_40 -> V_70 , V_3 -> V_11 , V_3 -> V_85 ,
V_81 , V_82 , V_83 , V_99 ) ;
if ( V_66 ) {
F_47 ( V_3 , L_23 , V_66 ) ;
return - V_100 ;
}
F_48 ( V_40 -> V_70 , V_3 -> V_11 ,
V_101 ) ;
while ( V_80 ) {
struct V_57 * V_60 = F_27 ( V_80 ) ;
if ( V_60 && V_60 -> V_11 != V_77 ) {
V_66 = F_49 ( V_40 -> V_70 , V_60 -> V_11 ,
V_3 -> V_11 , V_102 ) ;
}
V_80 = V_80 -> V_28 -> V_36 ;
}
for ( V_85 = V_3 -> V_85 ; V_85 < V_84 ; V_85 ++ )
V_40 -> V_50 . V_103 [ V_85 ] = V_3 -> V_11 ;
if ( V_40 -> type == V_104 ) {
V_3 -> V_105 = V_3 -> V_11 ;
V_66 = F_50 ( V_40 -> V_70 , V_3 -> V_105 ,
V_3 -> V_11 ) ;
if ( V_66 ) {
F_47 ( V_3 , L_24 ,
V_66 , V_3 -> V_105 ) ;
V_3 -> V_105 = - 1 ;
} else {
V_66 = F_51 ( V_40 -> V_70 ,
V_3 -> V_105 , V_106 ) ;
if ( V_66 ) {
F_47 ( V_3 , L_25 ,
V_66 , V_3 -> V_105 ) ;
V_3 -> V_105 = - 1 ;
}
}
} else if ( V_40 -> type == V_107 )
V_3 -> V_105 = 0 ;
return 0 ;
}
static void T_1 F_52 ( struct V_39 * V_40 ,
struct V_2 * V_3 )
{
struct V_2 * V_108 ;
F_12 (lpe, &phb->ioda.pe_list, link) {
if ( V_108 -> V_109 < V_3 -> V_109 ) {
F_13 ( & V_3 -> V_33 , & V_108 -> V_33 ) ;
return;
}
}
F_13 ( & V_3 -> V_33 , & V_40 -> V_50 . V_110 ) ;
}
static unsigned int F_53 ( struct V_12 * V_8 )
{
if ( V_8 -> V_111 != V_112 )
return 0 ;
if ( V_8 -> V_113 == V_114 ||
V_8 -> V_113 == V_115 ||
V_8 -> V_113 == V_116 )
return 3 ;
if ( ( V_8 -> V_113 >> 8 ) == V_117 )
return 15 ;
return 10 ;
}
static struct V_2 * T_1 F_54 ( struct V_12 * V_8 )
{
struct V_37 * V_38 = F_18 ( V_8 -> V_28 ) ;
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_57 * V_60 = F_27 ( V_8 ) ;
struct V_2 * V_3 ;
int V_118 ;
if ( ! V_60 ) {
F_32 ( L_26 ,
F_8 ( V_8 ) ) ;
return NULL ;
}
if ( V_60 -> V_11 != V_77 )
return NULL ;
if ( V_8 -> V_28 -> V_10 == 0 )
V_118 = 0 ;
else
V_118 = F_38 ( V_40 ) ;
if ( V_118 == V_77 ) {
F_55 ( L_27 ,
F_8 ( V_8 ) ) ;
return NULL ;
}
V_3 = & V_40 -> V_50 . V_78 [ V_118 ] ;
F_56 ( V_8 ) ;
V_60 -> V_119 = V_8 ;
V_60 -> V_11 = V_118 ;
V_3 -> V_7 = V_8 ;
V_3 -> V_9 = NULL ;
V_3 -> V_120 = - 1 ;
V_3 -> V_105 = - 1 ;
V_3 -> V_85 = V_8 -> V_28 -> V_10 << 8 | V_60 -> V_121 ;
F_57 ( V_3 , L_28 ) ;
if ( F_45 ( V_40 , V_3 ) ) {
if ( V_118 )
F_41 ( V_40 , V_118 ) ;
V_60 -> V_11 = V_77 ;
V_3 -> V_7 = NULL ;
F_58 ( V_8 ) ;
return NULL ;
}
V_3 -> V_109 = F_53 ( V_8 ) ;
if ( V_3 -> V_109 != 0 ) {
V_40 -> V_50 . V_109 += V_3 -> V_109 ;
V_40 -> V_50 . V_122 ++ ;
}
F_52 ( V_40 , V_3 ) ;
return V_3 ;
}
static void F_59 ( struct V_27 * V_28 , struct V_2 * V_3 )
{
struct V_12 * V_8 ;
F_12 (dev, &bus->devices, bus_list) {
struct V_57 * V_60 = F_27 ( V_8 ) ;
if ( V_60 == NULL ) {
F_60 ( L_29 ,
F_8 ( V_8 ) ) ;
continue;
}
F_56 ( V_8 ) ;
V_60 -> V_119 = V_8 ;
V_60 -> V_11 = V_3 -> V_11 ;
V_3 -> V_109 += F_53 ( V_8 ) ;
if ( V_8 -> V_89 )
F_59 ( V_8 -> V_89 , V_3 ) ;
}
}
static void T_1 F_61 ( struct V_12 * V_8 ,
struct V_2 * V_123 )
{
struct V_37 * V_38 = F_18 ( V_8 -> V_28 ) ;
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_27 * V_28 = V_8 -> V_89 ;
struct V_2 * V_3 ;
int V_118 ;
if ( ! V_28 ) {
F_55 ( L_30 ,
F_8 ( V_8 ) ) ;
return;
}
V_118 = F_38 ( V_40 ) ;
if ( V_118 == V_77 ) {
F_55 ( L_31 ,
F_8 ( V_8 ) ) ;
return;
}
V_3 = & V_40 -> V_50 . V_78 [ V_118 ] ;
V_123 -> V_79 = V_3 ;
V_3 -> V_9 = V_28 ;
V_3 -> V_7 = NULL ;
V_3 -> V_120 = - 1 ;
V_3 -> V_105 = - 1 ;
V_3 -> V_85 = V_28 -> V_90 << 8 ;
V_3 -> V_109 = 0 ;
F_57 ( V_3 , L_32 ,
V_28 -> V_90 , V_28 -> V_89 ) ;
if ( F_45 ( V_40 , V_3 ) ) {
if ( V_118 )
F_41 ( V_40 , V_118 ) ;
V_3 -> V_9 = NULL ;
return;
}
F_59 ( V_28 , V_3 ) ;
if ( V_3 -> V_109 != 0 ) {
V_40 -> V_50 . V_109 += V_3 -> V_109 ;
V_40 -> V_50 . V_122 ++ ;
}
F_52 ( V_40 , V_3 ) ;
}
static void T_1 F_62 ( struct V_27 * V_28 )
{
struct V_12 * V_8 ;
struct V_2 * V_3 ;
F_12 (dev, &bus->devices, bus_list) {
V_3 = F_54 ( V_8 ) ;
if ( V_3 == NULL )
continue;
if ( V_8 -> V_124 == V_125 )
F_61 ( V_8 , V_3 ) ;
else if ( V_8 -> V_89 )
F_62 ( V_8 -> V_89 ) ;
}
}
static void T_1 F_63 ( struct V_39 * V_40 ,
struct V_12 * V_8 )
{
}
static void T_1 F_64 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_12 * V_8 ;
F_12 (dev, &bus->devices, bus_list) {
F_65 ( & V_8 -> V_8 , & V_3 -> V_126 ) ;
if ( V_8 -> V_89 )
F_64 ( V_3 , V_8 -> V_89 ) ;
}
}
static void T_1 F_66 ( struct V_39 * V_40 ,
struct V_2 * V_3 ,
unsigned int V_127 ,
unsigned int V_128 )
{
struct V_129 * V_130 = NULL ;
const T_4 * V_131 ;
struct V_132 * V_133 ;
unsigned int V_19 ;
T_5 V_66 ;
void * V_134 ;
#define F_67 ((0x10000000 / 0x1000) * 8)
if ( F_26 ( V_3 -> V_120 >= 0 ) )
return;
V_3 -> V_120 = V_127 ;
F_57 ( V_3 , L_33 ,
( V_127 << 28 ) , ( ( V_127 + V_128 ) << 28 ) - 1 ) ;
V_130 = F_68 ( V_40 -> V_38 -> V_135 , V_32 ,
F_69 ( F_67 * V_128 ) ) ;
if ( ! V_130 ) {
F_47 ( V_3 , L_34 ) ;
goto V_136;
}
V_134 = F_70 ( V_130 ) ;
memset ( V_134 , 0 , F_67 * V_128 ) ;
for ( V_19 = 0 ; V_19 < V_128 ; V_19 ++ ) {
V_66 = F_71 ( V_40 -> V_70 ,
V_3 -> V_11 ,
V_127 + V_19 , 1 ,
F_72 ( V_134 ) + F_67 * V_19 ,
F_67 , 0x1000 ) ;
if ( V_66 ) {
F_47 ( V_3 , L_35
L_36 , V_66 ) ;
goto V_136;
}
}
V_133 = & V_3 -> V_126 ;
F_73 ( V_133 , V_134 , F_67 * V_128 ,
V_127 << 28 ) ;
V_131 = F_74 ( V_40 -> V_38 -> V_137 , L_37 , NULL ) ;
if ( V_131 ) {
V_133 -> V_138 = 0 ;
V_133 -> V_139 = ( unsigned long ) F_75 ( F_76 ( V_131 ) , 8 ) ;
V_133 -> V_140 = V_141 | V_142
| V_143 ;
}
F_77 ( V_133 , V_40 -> V_38 -> V_135 ) ;
if ( V_3 -> V_7 )
F_65 ( & V_3 -> V_7 -> V_8 , V_133 ) ;
else
F_64 ( V_3 , V_3 -> V_9 ) ;
return;
V_136:
if ( V_3 -> V_120 >= 0 )
V_3 -> V_120 = - 1 ;
if ( V_130 )
F_78 ( V_130 , F_69 ( F_67 * V_128 ) ) ;
}
static void T_1 F_79 ( struct V_39 * V_40 )
{
struct V_37 * V_38 = V_40 -> V_38 ;
unsigned int V_144 , V_145 , V_128 , V_146 , V_127 ;
struct V_2 * V_3 ;
if ( V_40 -> V_50 . V_122 > V_40 -> V_50 . V_147 )
V_144 = 0 ;
else
V_144 = V_40 -> V_50 . V_147 -
V_40 -> V_50 . V_122 ;
F_80 ( L_38 ,
V_38 -> V_148 , V_40 -> V_50 . V_147 ) ;
F_80 ( L_39 ,
V_40 -> V_50 . V_122 , V_40 -> V_50 . V_109 ) ;
V_145 = V_40 -> V_50 . V_147 ;
V_146 = V_40 -> V_50 . V_109 ;
V_127 = 0 ;
F_12 (pe, &phb->ioda.pe_list, link) {
if ( ! V_3 -> V_109 )
continue;
if ( ! V_145 ) {
F_81 ( V_3 , L_40 ) ;
continue;
}
V_128 = 1 ;
if ( V_144 ) {
V_128 += ( ( V_3 -> V_109 * V_144 ) + ( V_146 / 2 ) ) / V_146 ;
if ( V_128 > V_145 )
V_128 = V_145 ;
}
F_57 ( V_3 , L_41 ,
V_3 -> V_109 , V_128 ) ;
F_66 ( V_40 , V_3 , V_127 , V_128 ) ;
V_145 -= V_128 ;
V_127 += V_128 ;
}
}
static int F_82 ( struct V_39 * V_40 , struct V_12 * V_8 ,
unsigned int V_149 , unsigned int V_150 ,
struct V_151 * V_152 )
{
struct V_2 * V_3 = F_44 ( V_8 ) ;
unsigned int V_153 = V_149 - V_40 -> V_154 ;
T_6 V_155 ;
T_7 V_156 , V_157 ;
int V_66 ;
if ( V_3 == NULL )
return - V_100 ;
if ( V_3 -> V_105 < 0 )
return - V_100 ;
V_66 = F_83 ( V_40 -> V_70 , V_3 -> V_11 , V_153 ) ;
if ( V_66 ) {
F_60 ( L_42 ,
F_8 ( V_8 ) , V_66 , V_153 ) ;
return - V_158 ;
}
if ( V_150 ) {
V_66 = F_84 ( V_40 -> V_70 , V_3 -> V_105 , V_153 , 1 ,
& V_155 , & V_157 ) ;
if ( V_66 ) {
F_60 ( L_43 ,
F_8 ( V_8 ) , V_66 ) ;
return - V_158 ;
}
V_152 -> V_159 = V_155 >> 32 ;
V_152 -> V_160 = V_155 & 0xfffffffful ;
} else {
V_66 = F_85 ( V_40 -> V_70 , V_3 -> V_105 , V_153 , 1 ,
& V_156 , & V_157 ) ;
if ( V_66 ) {
F_60 ( L_44 ,
F_8 ( V_8 ) , V_66 ) ;
return - V_158 ;
}
V_152 -> V_159 = 0 ;
V_152 -> V_160 = V_156 ;
}
V_152 -> V_157 = V_157 ;
F_7 ( L_45
L_46 ,
F_8 ( V_8 ) , V_150 ? L_47 : L_48 , V_149 , V_153 ,
V_152 -> V_159 , V_152 -> V_160 , V_157 , V_3 -> V_11 ) ;
return 0 ;
}
static void F_86 ( struct V_39 * V_40 )
{
unsigned int V_161 ;
const T_8 * V_162 = F_74 ( V_40 -> V_38 -> V_137 ,
L_49 , NULL ) ;
if ( ! V_162 ) {
V_162 = F_74 ( V_40 -> V_38 -> V_137 , L_50 , NULL ) ;
}
if ( ! V_162 )
return;
V_40 -> V_154 = F_87 ( V_162 ) ;
V_40 -> V_163 = F_87 ( V_162 + 1 ) ;
V_161 = F_88 ( V_40 -> V_163 ) * sizeof( unsigned long ) ;
V_40 -> V_164 = F_89 ( V_161 , V_32 ) ;
if ( ! V_40 -> V_164 ) {
F_32 ( L_51 ,
V_40 -> V_38 -> V_148 ) ;
return;
}
V_40 -> V_165 = F_82 ;
V_40 -> V_166 = 1 ;
F_80 ( L_52 ,
V_40 -> V_163 , V_40 -> V_154 ) ;
}
static void F_86 ( struct V_39 * V_40 ) { }
static void T_1 F_90 ( struct V_37 * V_38 )
{
T_2 V_14 , V_15 ;
struct V_27 * V_167 ;
F_62 ( V_38 -> V_28 ) ;
F_17 ( V_38 -> V_28 , V_49 , & V_14 , & V_15 ) ;
F_17 ( V_38 -> V_28 , V_67 , & V_14 , & V_15 ) ;
F_35 ( V_38 -> V_28 ) ;
F_79 ( V_38 -> V_41 ) ;
F_12 (child, &hose->bus->children, node) {
struct V_12 * V_36 = V_167 -> V_36 ;
if ( ! V_36 )
continue;
F_91 ( V_167 , V_36 -> V_168 ) ;
}
}
static int T_1 F_92 ( struct V_12 * V_8 )
{
struct V_57 * V_60 = F_27 ( V_8 ) ;
if ( ! V_60 || V_60 -> V_11 == V_77 )
return - V_169 ;
return 0 ;
}
static T_9 F_93 ( struct V_39 * V_40 , struct V_27 * V_28 ,
T_9 V_121 )
{
return V_40 -> V_50 . V_103 [ ( V_28 -> V_10 << 8 ) | V_121 ] ;
}
void T_10 F_94 ( struct V_58 * V_59 )
{
struct V_37 * V_38 ;
static int V_170 = 1 ;
struct V_39 * V_40 ;
unsigned long V_14 , V_171 , V_172 , V_173 ;
const T_11 * V_174 ;
T_11 V_175 ;
void * V_176 ;
long V_66 ;
F_80 ( L_53 , V_59 -> V_177 ) ;
V_174 = F_74 ( V_59 , L_54 , NULL ) ;
if ( ! V_174 ) {
F_32 ( L_55 ) ;
return;
}
V_175 = F_76 ( V_174 ) ;
F_95 ( L_56 , V_175 ) ;
V_40 = F_96 ( sizeof( struct V_39 ) ) ;
if ( V_40 ) {
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 -> V_38 = V_38 = F_97 ( V_59 ) ;
}
if ( ! V_40 || ! V_40 -> V_38 ) {
F_32 ( L_57 ,
V_59 -> V_177 ) ;
return;
}
F_98 ( & V_40 -> V_178 ) ;
V_38 -> V_179 = 0 ;
V_38 -> V_180 = 0xff ;
V_38 -> V_41 = V_40 ;
V_40 -> V_70 = V_175 ;
V_40 -> type = V_104 ;
if ( F_99 ( V_59 , L_58 ) )
V_40 -> V_181 = V_182 ;
else
V_40 -> V_181 = V_183 ;
F_100 ( V_40 -> V_38 , V_59 , V_170 ) ;
V_170 = 0 ;
V_40 -> V_184 = F_101 ( V_59 , 0 ) ;
if ( V_40 -> V_184 == NULL )
F_32 ( L_59 ) ;
V_40 -> V_50 . V_68 = 128 ;
V_40 -> V_50 . V_185 = F_9 ( & V_38 -> V_55 [ 0 ] ) ;
V_40 -> V_50 . V_185 += 0x10000 ;
V_40 -> V_50 . V_52 = V_40 -> V_50 . V_185 / V_40 -> V_50 . V_68 ;
V_40 -> V_50 . V_186 = V_38 -> V_55 [ 0 ] . V_16 -
V_38 -> V_187 ;
V_40 -> V_50 . V_188 = V_38 -> V_189 ;
V_40 -> V_50 . V_51 = V_40 -> V_50 . V_188 / V_40 -> V_50 . V_68 ;
V_40 -> V_50 . V_190 = 0 ;
V_14 = F_102 ( V_40 -> V_50 . V_68 / 8 , sizeof( unsigned long ) ) ;
V_171 = V_14 ;
V_14 += V_40 -> V_50 . V_68 ;
V_172 = V_14 ;
V_14 += V_40 -> V_50 . V_68 ;
V_173 = V_14 ;
V_14 += V_40 -> V_50 . V_68 * sizeof( struct V_2 ) ;
V_176 = F_96 ( V_14 ) ;
memset ( V_176 , 0 , V_14 ) ;
V_40 -> V_50 . V_76 = V_176 ;
V_40 -> V_50 . V_73 = V_176 + V_171 ;
V_40 -> V_50 . V_69 = V_176 + V_172 ;
V_40 -> V_50 . V_78 = V_176 + V_173 ;
F_103 ( 0 , V_40 -> V_50 . V_76 ) ;
F_19 ( & V_40 -> V_50 . V_110 ) ;
V_40 -> V_50 . V_147 = V_40 -> V_50 . V_186 >> 28 ;
V_38 -> V_55 [ 1 ] . V_13 = 0 ;
V_38 -> V_55 [ 1 ] . V_16 = 0 ;
V_38 -> V_55 [ 1 ] . V_21 = 0 ;
V_38 -> V_55 [ 2 ] . V_13 = 0 ;
V_38 -> V_55 [ 2 ] . V_16 = 0 ;
V_38 -> V_55 [ 2 ] . V_21 = 0 ;
#if 0
rc = opal_pci_set_phb_mem_window(opal->phb_id,
window_type,
window_num,
starting_real_address,
starting_pci_address,
segment_size);
#endif
F_80 ( L_60 ,
V_40 -> V_50 . V_68 ,
V_40 -> V_50 . V_185 , V_40 -> V_50 . V_52 ,
V_40 -> V_50 . V_188 , V_40 -> V_50 . V_51 ) ;
if ( V_40 -> V_184 ) {
F_7 ( L_61 , F_104 ( V_40 -> V_184 + 0x100 ) ) ;
F_7 ( L_62 , F_104 ( V_40 -> V_184 + 0x160 ) ) ;
F_7 ( L_63 , F_104 ( V_40 -> V_184 + 0x170 ) ) ;
F_7 ( L_64 , F_104 ( V_40 -> V_184 + 0x178 ) ) ;
F_7 ( L_65 , F_104 ( V_40 -> V_184 + 0x180 ) ) ;
F_7 ( L_66 , F_104 ( V_40 -> V_184 + 0x190 ) ) ;
F_7 ( L_67 , F_104 ( V_40 -> V_184 + 0x198 ) ) ;
F_7 ( L_68 , F_104 ( V_40 -> V_184 + 0x1a0 ) ) ;
}
V_40 -> V_38 -> V_191 = & V_192 ;
V_40 -> V_193 = F_93 ;
V_40 -> V_194 = F_63 ;
F_86 ( V_40 ) ;
V_195 = 1 ;
V_196 . V_197 = F_90 ;
V_196 . V_198 = F_92 ;
F_105 ( V_199 ) ;
V_66 = F_106 ( V_175 , V_200 , V_201 ) ;
if ( V_66 )
F_55 ( L_69 , V_66 ) ;
F_46 ( V_175 , 0 , 0 , 7 , 1 , 1 , V_99 ) ;
}
void T_10 F_107 ( struct V_58 * V_59 )
{
struct V_58 * V_202 ;
const T_11 * V_174 ;
T_11 V_203 ;
F_80 ( L_70 , V_59 -> V_177 ) ;
V_174 = F_74 ( V_59 , L_71 , NULL ) ;
if ( ! V_174 ) {
F_32 ( L_72 ) ;
return;
}
V_203 = F_76 ( V_174 ) ;
F_7 ( L_73 , V_203 ) ;
F_108 (np, phbn) {
if ( F_99 ( V_202 , L_74 ) )
F_94 ( V_202 ) ;
}
}
