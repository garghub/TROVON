static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static T_2 F_3 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
if ( F_4 ( V_2 -> V_4 + V_8 ) & V_9 ) {
V_2 -> V_10 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
F_5 ( & V_2 -> V_11 ) ;
}
return V_12 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_14 = 1000000 / V_2 -> V_15 + 1 ;
if ( V_14 < 2 )
V_14 = 2 ;
for ( V_13 = 9 ; V_13 ; V_13 -- ) {
F_1 ( V_2 , 0 ) ;
F_1 ( V_2 , V_16 | V_17 | V_18 ) ;
F_4 ( V_2 -> V_4 + V_19 ) ;
F_1 ( V_2 , V_18 ) ;
F_7 ( V_14 << 1 ) ;
}
}
static int F_8 ( struct V_1 * V_2 , unsigned V_20 , int V_21 )
{
unsigned long V_22 = V_23 ;
T_1 V_24 ;
int V_25 = 0 ;
if ( ! V_2 -> V_6 ) {
while ( ! ( F_4 ( V_2 -> V_4 + V_8 ) & V_9 ) ) {
F_9 () ;
if ( F_10 ( V_23 , V_22 + V_20 ) ) {
F_11 ( V_2 -> V_26 , L_1 ) ;
F_1 ( V_2 , 0 ) ;
V_25 = - V_27 ;
break;
}
}
V_24 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
} else {
V_25 = F_12 ( V_2 -> V_11 ,
( V_2 -> V_10 & V_9 ) , V_20 ) ;
if ( F_13 ( ! ( V_2 -> V_10 & V_9 ) ) ) {
F_11 ( V_2 -> V_26 , L_2 ) ;
F_1 ( V_2 , 0 ) ;
V_25 = - V_27 ;
}
V_24 = V_2 -> V_10 ;
V_2 -> V_10 = 0 ;
}
if ( V_25 < 0 )
return V_25 ;
if ( ! ( V_24 & V_28 ) ) {
F_11 ( V_2 -> V_26 , L_3 ) ;
return - V_29 ;
}
if ( V_24 & V_30 ) {
F_11 ( V_2 -> V_26 , L_4 ) ;
return - V_31 ;
}
if ( V_21 && ( V_24 & V_32 ) ) {
F_11 ( V_2 -> V_26 , L_5 ) ;
F_1 ( V_2 , V_18 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_14 ( struct V_34 * V_35 , T_1 clock ,
int V_36 , T_1 * V_15 )
{
const struct V_37 * div = NULL ;
unsigned int V_38 = F_15 ( V_39 ) ;
T_1 V_40 ;
int V_41 ;
if ( clock == V_42 ) {
* V_15 = F_16 ( V_35 ) / 2048 ;
return - V_43 ;
}
V_40 = F_16 ( V_35 ) / clock ;
for ( V_41 = 0 ; V_41 < F_17 ( V_44 ) ; V_41 ++ ) {
div = & V_44 [ V_41 ] ;
if ( div -> V_45 & 0xc0 && V_38 == 0x80822011 )
continue;
if ( div -> V_40 >= V_40 )
break;
}
* V_15 = F_16 ( V_35 ) / div -> V_40 ;
return ( int ) div -> V_45 ;
}
static void F_18 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_36 )
{
int V_46 , V_45 ;
if ( clock == V_47 ) {
F_11 ( V_2 -> V_26 , L_6 ,
F_4 ( V_2 -> V_4 + V_48 ) ) ;
return;
}
V_46 = F_14 ( V_35 , clock , V_36 , & V_2 -> V_15 ) ;
V_45 = ( V_46 >= 0 ) ? V_46 : 0x3f ;
F_2 ( V_45 & 0xff , V_2 -> V_4 + V_48 ) ;
if ( V_46 >= 0 )
F_19 ( V_2 -> V_26 , L_7 , V_2 -> V_15 ,
V_45 ) ;
}
static void F_18 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_36 )
{
}
static void F_20 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_36 )
{
struct V_34 * V_49 ;
void T_3 * V_50 ;
const T_1 * V_51 ;
T_1 V_52 ;
V_49 = F_21 ( NULL , NULL ,
L_8 ) ;
if ( V_49 ) {
V_50 = F_22 ( V_49 , 0 ) ;
if ( V_50 ) {
V_51 = F_23 ( V_35 , L_9 , NULL ) ;
V_52 = ( * V_51 & 0xff ) / 0x20 ;
F_24 ( V_50 , 1 << ( 24 + V_52 * 2 ) ) ;
F_25 ( V_50 ) ;
}
F_26 ( V_49 ) ;
}
F_18 ( V_35 , V_2 , clock , V_36 ) ;
}
static void F_20 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_36 )
{
}
static T_1 F_27 ( void )
{
struct V_34 * V_35 = NULL ;
T_1 T_3 * V_53 ;
T_1 V_54 = 0 ;
V_35 = F_28 ( NULL , L_10 ) ;
if ( V_35 ) {
const T_1 * V_55 = F_23 ( V_35 , L_9 , NULL ) ;
if ( V_55 ) {
V_53 = F_29 ( F_30 () + * V_55 + 0x14 , 0x4 ) ;
if ( ! V_53 )
F_31 ( V_56
L_11 ) ;
else
V_54 = F_32 ( V_53 ) & 0x00000080 ;
F_25 ( V_53 ) ;
}
}
F_26 ( V_35 ) ;
return V_54 ;
}
static int F_33 ( struct V_34 * V_35 , T_1 clock ,
T_1 V_36 , T_1 * V_15 )
{
const struct V_37 * div = NULL ;
T_1 V_40 ;
int V_41 ;
if ( clock == V_42 ) {
* V_15 = F_34 () / V_36 / ( 16 * 3072 ) ;
return - V_43 ;
}
if ( F_35 ( V_35 , L_12 ) )
V_36 = F_27 () ? 3 : 2 ;
if ( ! V_36 )
V_36 = 1 ;
V_40 = F_34 () / clock / V_36 ;
F_36 ( L_13 ,
F_34 () , clock , V_40 ) ;
for ( V_41 = 0 ; V_41 < F_17 ( V_57 ) ; V_41 ++ ) {
div = & V_57 [ V_41 ] ;
if ( div -> V_40 >= V_40 )
break;
}
* V_15 = F_34 () / V_36 / div -> V_40 ;
return div ? ( int ) div -> V_45 : - V_43 ;
}
static void F_37 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_36 )
{
int V_46 , V_45 ;
if ( clock == V_47 ) {
F_11 ( V_2 -> V_26 , L_14 ,
F_4 ( V_2 -> V_4 + V_58 ) ,
F_4 ( V_2 -> V_4 + V_48 ) ) ;
return;
}
V_46 = F_33 ( V_35 , clock , V_36 , & V_2 -> V_15 ) ;
V_45 = ( V_46 >= 0 ) ? V_46 : 0x1031 ;
F_2 ( V_45 & 0xff , V_2 -> V_4 + V_48 ) ;
F_2 ( ( V_45 >> 8 ) & 0xff , V_2 -> V_4 + V_58 ) ;
if ( V_46 >= 0 )
F_19 ( V_2 -> V_26 , L_15 ,
V_2 -> V_15 , V_45 >> 8 , V_45 & 0xff ) ;
}
static void F_37 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_36 )
{
}
static void F_38 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
F_1 ( V_2 , V_18 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_18 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_59 ,
const T_4 * V_60 , int V_61 , int V_62 )
{
int V_41 , V_25 ;
unsigned V_20 = V_2 -> V_63 . V_20 ;
T_1 V_64 = V_62 ? V_65 : 0 ;
F_1 ( V_2 , V_66 | V_18 | V_16 | V_17 | V_64 ) ;
F_2 ( ( V_59 << 1 ) , V_2 -> V_4 + V_19 ) ;
V_25 = F_8 ( V_2 , V_20 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
for ( V_41 = 0 ; V_41 < V_61 ; V_41 ++ ) {
F_2 ( V_60 [ V_41 ] , V_2 -> V_4 + V_19 ) ;
V_25 = F_8 ( V_2 , V_20 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_59 ,
T_4 * V_60 , int V_61 , int V_62 , bool V_67 )
{
unsigned V_20 = V_2 -> V_63 . V_20 ;
int V_41 , V_25 ;
T_1 V_64 = V_62 ? V_65 : 0 ;
F_1 ( V_2 , V_66 | V_18 | V_16 | V_17 | V_64 ) ;
F_2 ( ( V_59 << 1 ) | 1 , V_2 -> V_4 + V_19 ) ;
V_25 = F_8 ( V_2 , V_20 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_61 ) {
if ( V_61 == 1 && ! V_67 )
F_1 ( V_2 , V_66 | V_18 | V_16 | V_68 ) ;
else
F_1 ( V_2 , V_66 | V_18 | V_16 ) ;
F_4 ( V_2 -> V_4 + V_19 ) ;
}
for ( V_41 = 0 ; V_41 < V_61 ; V_41 ++ ) {
T_4 V_69 ;
V_25 = F_8 ( V_2 , V_20 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_41 || ! V_67 ) {
if ( V_41 == V_61 - 2 )
F_1 ( V_2 , V_66 | V_18 | V_16
| V_68 ) ;
if ( V_41 == V_61 - 1 )
F_1 ( V_2 , V_66 | V_18 | V_16
| V_17 ) ;
}
V_69 = F_4 ( V_2 -> V_4 + V_19 ) ;
if ( V_41 == 0 && V_67 ) {
if ( V_69 == 0 || V_69 > V_70 )
return - V_71 ;
V_61 += V_69 ;
if ( V_61 == 2 )
F_1 ( V_2 , V_66 | V_18 | V_16
| V_68 ) ;
}
V_60 [ V_41 ] = V_69 ;
}
return V_61 ;
}
static int F_42 ( struct V_72 * V_63 , struct V_73 * V_74 , int V_75 )
{
struct V_73 * V_76 ;
int V_41 ;
int V_46 = 0 ;
unsigned long V_22 = V_23 ;
struct V_1 * V_2 = F_43 ( V_63 ) ;
F_38 ( V_2 ) ;
while ( F_4 ( V_2 -> V_4 + V_8 ) & V_77 ) {
if ( F_44 ( V_78 ) ) {
F_11 ( V_2 -> V_26 , L_16 ) ;
F_1 ( V_2 , 0 ) ;
return - V_79 ;
}
if ( F_10 ( V_23 , V_22 + V_80 ) ) {
T_4 V_81 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_11 ( V_2 -> V_26 , L_1 ) ;
if ( ( V_81 & ( V_28 | V_77 | V_32 ) ) != 0 ) {
F_2 ( V_81 & ~ V_30 ,
V_2 -> V_4 + V_8 ) ;
F_6 ( V_2 ) ;
}
return - V_29 ;
}
F_9 () ;
}
for ( V_41 = 0 ; V_46 >= 0 && V_41 < V_75 ; V_41 ++ ) {
V_76 = & V_74 [ V_41 ] ;
F_11 ( V_2 -> V_26 ,
L_17 ,
V_76 -> V_64 & V_82 ? L_18 : L_19 ,
V_76 -> V_83 , V_76 -> V_84 , V_41 + 1 , V_75 ) ;
if ( V_76 -> V_64 & V_82 ) {
bool V_67 = V_76 -> V_64 & V_85 ;
V_46 = F_41 ( V_2 , V_76 -> V_84 , V_76 -> V_86 , V_76 -> V_83 , V_41 ,
V_67 ) ;
if ( V_67 && V_46 > 0 )
V_76 -> V_83 = V_46 ;
} else {
V_46 =
F_40 ( V_2 , V_76 -> V_84 , V_76 -> V_86 , V_76 -> V_83 , V_41 ) ;
}
}
F_39 ( V_2 ) ;
V_22 = V_23 ;
while ( F_4 ( V_2 -> V_4 + V_8 ) & V_77 ) {
if ( F_10 ( V_23 , V_22 + V_80 ) ) {
T_4 V_81 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_11 ( V_2 -> V_26 , L_1 ) ;
if ( ( V_81 & ( V_28 | V_77 | V_32 ) ) != 0 ) {
F_2 ( V_81 & ~ V_30 ,
V_2 -> V_4 + V_8 ) ;
F_6 ( V_2 ) ;
}
return - V_29 ;
}
F_45 () ;
}
return ( V_46 < 0 ) ? V_46 : V_75 ;
}
static T_1 F_46 ( struct V_72 * V_63 )
{
return V_87 | V_88
| V_89 | V_90 ;
}
static int F_47 ( struct V_91 * V_92 )
{
const struct V_93 * V_94 ;
struct V_1 * V_2 ;
const T_1 * V_55 ;
T_1 clock = V_42 ;
int V_25 = 0 ;
int V_95 ;
struct V_96 V_97 ;
struct V_98 * V_98 ;
int V_99 ;
V_94 = F_48 ( V_100 , & V_92 -> V_26 ) ;
if ( ! V_94 )
return - V_43 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_101 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_26 = & V_92 -> V_26 ;
F_50 ( & V_2 -> V_11 ) ;
V_2 -> V_4 = F_22 ( V_92 -> V_26 . V_103 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_51 ( V_2 -> V_26 , L_20 ) ;
V_25 = - V_102 ;
goto V_104;
}
V_2 -> V_6 = F_52 ( V_92 -> V_26 . V_103 , 0 ) ;
if ( V_2 -> V_6 ) {
V_25 = F_53 ( V_2 -> V_6 , F_3 ,
V_105 , L_21 , V_2 ) ;
if ( V_25 < 0 ) {
F_51 ( V_2 -> V_26 , L_22 ) ;
goto V_106;
}
}
V_98 = F_54 ( & V_92 -> V_26 , NULL ) ;
if ( ! F_55 ( V_98 ) ) {
V_99 = F_56 ( V_98 ) ;
if ( V_99 ) {
F_51 ( & V_92 -> V_26 , L_23 ) ;
goto V_106;
} else {
V_2 -> V_107 = V_98 ;
}
}
if ( F_23 ( V_92 -> V_26 . V_103 , L_24 , NULL ) ) {
clock = V_47 ;
} else {
V_55 = F_23 ( V_92 -> V_26 . V_103 , L_25 ,
& V_95 ) ;
if ( V_55 && V_95 == sizeof( T_1 ) )
clock = * V_55 ;
}
if ( V_94 -> V_60 ) {
const struct V_108 * V_60 = V_94 -> V_60 ;
V_60 -> V_109 ( V_92 -> V_26 . V_103 , V_2 , clock , V_60 -> V_36 ) ;
} else {
if ( F_23 ( V_92 -> V_26 . V_103 , L_26 , NULL ) )
F_37 ( V_92 -> V_26 . V_103 , V_2 , clock , 0 ) ;
}
V_55 = F_23 ( V_92 -> V_26 . V_103 , L_27 , & V_95 ) ;
if ( V_55 && V_95 == sizeof( T_1 ) ) {
V_110 . V_20 = * V_55 * V_80 / 1000000 ;
if ( V_110 . V_20 < 5 )
V_110 . V_20 = 5 ;
}
F_19 ( V_2 -> V_26 , L_28 , V_110 . V_20 * 1000000 / V_80 ) ;
F_57 ( V_92 , V_2 ) ;
V_2 -> V_63 = V_110 ;
F_58 ( V_92 -> V_26 . V_103 , 0 , & V_97 ) ;
F_59 ( V_2 -> V_63 . V_111 , sizeof( V_2 -> V_63 . V_111 ) ,
L_29 , ( unsigned long long ) V_97 . V_112 ) ;
F_60 ( & V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 . V_26 . V_113 = & V_92 -> V_26 ;
V_2 -> V_63 . V_26 . V_103 = F_61 ( V_92 -> V_26 . V_103 ) ;
V_25 = F_62 ( & V_2 -> V_63 ) ;
if ( V_25 < 0 ) {
F_51 ( V_2 -> V_26 , L_30 ) ;
goto V_114;
}
return V_25 ;
V_114:
if ( V_2 -> V_107 )
F_63 ( V_2 -> V_107 ) ;
F_64 ( V_2 -> V_6 , V_2 ) ;
V_106:
F_65 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_4 ) ;
V_104:
F_66 ( V_2 ) ;
return V_25 ;
}
static int F_67 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_68 ( V_92 ) ;
F_69 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_107 )
F_63 ( V_2 -> V_107 ) ;
if ( V_2 -> V_6 )
F_64 ( V_2 -> V_6 , V_2 ) ;
F_65 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_4 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_115 * V_26 )
{
struct V_1 * V_2 = F_71 ( V_26 ) ;
V_2 -> V_45 = F_4 ( V_2 -> V_4 + V_48 ) ;
V_2 -> V_116 = F_4 ( V_2 -> V_4 + V_58 ) ;
return 0 ;
}
static int F_72 ( struct V_115 * V_26 )
{
struct V_1 * V_2 = F_71 ( V_26 ) ;
F_2 ( V_2 -> V_45 , V_2 -> V_4 + V_48 ) ;
F_2 ( V_2 -> V_116 , V_2 -> V_4 + V_58 ) ;
return 0 ;
}
