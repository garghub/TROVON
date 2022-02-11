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
F_7 ( V_14 ) ;
F_1 ( V_2 , V_18 ) ;
F_7 ( V_14 << 1 ) ;
}
}
static int F_8 ( struct V_1 * V_2 , unsigned V_19 , int V_20 )
{
unsigned long V_21 = V_22 ;
T_1 V_3 ;
int V_23 = 0 ;
if ( ! V_2 -> V_6 ) {
while ( ! ( F_4 ( V_2 -> V_4 + V_8 ) & V_9 ) ) {
F_9 () ;
if ( F_10 ( V_22 , V_21 + V_19 ) ) {
F_11 ( V_2 -> V_24 , L_1 ) ;
F_1 ( V_2 , 0 ) ;
V_23 = - V_25 ;
break;
}
}
V_3 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_2 ( 0 , V_2 -> V_4 + V_8 ) ;
} else {
V_23 = F_12 ( V_2 -> V_11 ,
( V_2 -> V_10 & V_9 ) , V_19 ) ;
if ( F_13 ( ! ( V_2 -> V_10 & V_9 ) ) ) {
F_11 ( V_2 -> V_24 , L_2 ) ;
F_1 ( V_2 , 0 ) ;
V_23 = - V_26 ;
}
V_3 = V_2 -> V_10 ;
V_2 -> V_10 = 0 ;
}
if ( V_23 < 0 )
return V_23 ;
if ( ! ( V_3 & V_27 ) ) {
F_11 ( V_2 -> V_24 , L_3 ) ;
return - V_25 ;
}
if ( V_3 & V_28 ) {
F_11 ( V_2 -> V_24 , L_4 ) ;
return - V_25 ;
}
if ( V_20 && ( V_3 & V_29 ) ) {
F_11 ( V_2 -> V_24 , L_5 ) ;
F_1 ( V_2 , V_18 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , T_1 clock ,
int V_32 , T_1 * V_15 )
{
const struct V_33 * div = NULL ;
unsigned int V_34 = F_15 ( V_35 ) ;
T_1 V_36 ;
int V_37 ;
if ( clock == V_38 ) {
* V_15 = F_16 ( V_31 ) / 2048 ;
return - V_39 ;
}
V_36 = F_16 ( V_31 ) / clock ;
for ( V_37 = 0 ; V_37 < F_17 ( V_40 ) ; V_37 ++ ) {
div = & V_40 [ V_37 ] ;
if ( div -> V_41 & 0xc0 && V_34 == 0x80822011 )
continue;
if ( div -> V_36 >= V_36 )
break;
}
* V_15 = F_16 ( V_31 ) / div -> V_36 ;
return ( int ) div -> V_41 ;
}
static void F_18 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_32 )
{
int V_42 , V_41 ;
if ( clock == V_43 ) {
F_11 ( V_2 -> V_24 , L_6 ,
F_4 ( V_2 -> V_4 + V_44 ) ) ;
return;
}
V_42 = F_14 ( V_31 , clock , V_32 , & V_2 -> V_15 ) ;
V_41 = ( V_42 >= 0 ) ? V_42 : 0x3f ;
F_2 ( V_41 & 0xff , V_2 -> V_4 + V_44 ) ;
if ( V_42 >= 0 )
F_19 ( V_2 -> V_24 , L_7 , V_2 -> V_15 ,
V_41 ) ;
}
static void F_18 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_32 )
{
}
static void F_20 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_32 )
{
struct V_30 * V_45 ;
void T_3 * V_46 ;
const T_1 * V_47 ;
T_1 V_48 ;
V_45 = F_21 ( NULL , NULL ,
L_8 ) ;
if ( V_45 ) {
V_46 = F_22 ( V_45 , 0 ) ;
if ( V_46 ) {
V_47 = F_23 ( V_31 , L_9 , NULL ) ;
V_48 = ( * V_47 & 0xff ) / 0x20 ;
F_24 ( V_46 , 1 << ( 24 + V_48 * 2 ) ) ;
F_25 ( V_46 ) ;
}
F_26 ( V_45 ) ;
}
F_18 ( V_31 , V_2 , clock , V_32 ) ;
}
static void F_20 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_32 )
{
}
static T_1 F_27 ( void )
{
struct V_30 * V_31 = NULL ;
T_1 T_3 * V_49 ;
T_1 V_50 = 0 ;
V_31 = F_28 ( NULL , L_10 ) ;
if ( V_31 ) {
const T_1 * V_51 = F_23 ( V_31 , L_9 , NULL ) ;
if ( V_51 ) {
V_49 = F_29 ( F_30 () + * V_51 + 0x14 , 0x4 ) ;
if ( ! V_49 )
F_31 ( V_52
L_11 ) ;
else
V_50 = F_32 ( V_49 ) & 0x00000080 ;
F_25 ( V_49 ) ;
}
}
if ( V_31 )
F_26 ( V_31 ) ;
return V_50 ;
}
static int F_33 ( struct V_30 * V_31 , T_1 clock ,
T_1 V_32 , T_1 * V_15 )
{
const struct V_33 * div = NULL ;
T_1 V_36 ;
int V_37 ;
if ( clock == V_38 ) {
* V_15 = F_34 () / V_32 / ( 16 * 3072 ) ;
return - V_39 ;
}
if ( F_35 ( V_31 , L_12 ) )
V_32 = F_27 () ? 3 : 2 ;
if ( ! V_32 )
V_32 = 1 ;
V_36 = F_34 () / clock / V_32 ;
F_36 ( L_13 ,
F_34 () , clock , V_36 ) ;
for ( V_37 = 0 ; V_37 < F_17 ( V_53 ) ; V_37 ++ ) {
div = & V_53 [ V_37 ] ;
if ( div -> V_36 >= V_36 )
break;
}
* V_15 = F_34 () / V_32 / div -> V_36 ;
return div ? ( int ) div -> V_41 : - V_39 ;
}
static void F_37 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_32 )
{
int V_42 , V_41 ;
if ( clock == V_43 ) {
F_11 ( V_2 -> V_24 , L_14 ,
F_4 ( V_2 -> V_4 + V_54 ) ,
F_4 ( V_2 -> V_4 + V_44 ) ) ;
return;
}
V_42 = F_33 ( V_31 , clock , V_32 , & V_2 -> V_15 ) ;
V_41 = ( V_42 >= 0 ) ? V_42 : 0x1031 ;
F_2 ( V_41 & 0xff , V_2 -> V_4 + V_44 ) ;
F_2 ( ( V_41 >> 8 ) & 0xff , V_2 -> V_4 + V_54 ) ;
if ( V_42 >= 0 )
F_19 ( V_2 -> V_24 , L_15 ,
V_2 -> V_15 , V_41 >> 8 , V_41 & 0xff ) ;
}
static void F_37 ( struct V_30 * V_31 ,
struct V_1 * V_2 ,
T_1 clock , T_1 V_32 )
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
static int F_40 ( struct V_1 * V_2 , int V_55 ,
const T_4 * V_56 , int V_57 , int V_58 )
{
int V_37 , V_23 ;
unsigned V_19 = V_2 -> V_59 . V_19 ;
T_1 V_60 = V_58 ? V_61 : 0 ;
F_1 ( V_2 , V_62 | V_18 | V_16 | V_17 | V_60 ) ;
F_2 ( ( V_55 << 1 ) , V_2 -> V_4 + V_63 ) ;
V_23 = F_8 ( V_2 , V_19 , 1 ) ;
if ( V_23 < 0 )
return V_23 ;
for ( V_37 = 0 ; V_37 < V_57 ; V_37 ++ ) {
F_2 ( V_56 [ V_37 ] , V_2 -> V_4 + V_63 ) ;
V_23 = F_8 ( V_2 , V_19 , 1 ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_55 ,
T_4 * V_56 , int V_57 , int V_58 , bool V_64 )
{
unsigned V_19 = V_2 -> V_59 . V_19 ;
int V_37 , V_23 ;
T_1 V_60 = V_58 ? V_61 : 0 ;
F_1 ( V_2 , V_62 | V_18 | V_16 | V_17 | V_60 ) ;
F_2 ( ( V_55 << 1 ) | 1 , V_2 -> V_4 + V_63 ) ;
V_23 = F_8 ( V_2 , V_19 , 1 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_57 ) {
if ( V_57 == 1 && ! V_64 )
F_1 ( V_2 , V_62 | V_18 | V_16 | V_65 ) ;
else
F_1 ( V_2 , V_62 | V_18 | V_16 ) ;
F_4 ( V_2 -> V_4 + V_63 ) ;
}
for ( V_37 = 0 ; V_37 < V_57 ; V_37 ++ ) {
T_4 V_66 ;
V_23 = F_8 ( V_2 , V_19 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_37 || ! V_64 ) {
if ( V_37 == V_57 - 2 )
F_1 ( V_2 , V_62 | V_18 | V_16
| V_65 ) ;
if ( V_37 == V_57 - 1 )
F_1 ( V_2 , V_62 | V_18 | V_16
| V_17 ) ;
}
V_66 = F_4 ( V_2 -> V_4 + V_63 ) ;
if ( V_37 == 0 && V_64 ) {
if ( V_66 == 0 || V_66 > V_67 )
return - V_68 ;
V_57 += V_66 ;
if ( V_57 == 2 )
F_1 ( V_2 , V_62 | V_18 | V_16
| V_65 ) ;
}
V_56 [ V_37 ] = V_66 ;
}
return V_57 ;
}
static int F_42 ( struct V_69 * V_59 , struct V_70 * V_71 , int V_72 )
{
struct V_70 * V_73 ;
int V_37 ;
int V_42 = 0 ;
unsigned long V_21 = V_22 ;
struct V_1 * V_2 = F_43 ( V_59 ) ;
F_38 ( V_2 ) ;
while ( F_4 ( V_2 -> V_4 + V_8 ) & V_74 ) {
if ( F_44 ( V_75 ) ) {
F_11 ( V_2 -> V_24 , L_16 ) ;
F_1 ( V_2 , 0 ) ;
return - V_76 ;
}
if ( F_10 ( V_22 , V_21 + V_77 ) ) {
T_4 V_78 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_11 ( V_2 -> V_24 , L_1 ) ;
if ( ( V_78 & ( V_27 | V_74 | V_29 ) ) != 0 ) {
F_2 ( V_78 & ~ V_28 ,
V_2 -> V_4 + V_8 ) ;
F_6 ( V_2 ) ;
}
return - V_25 ;
}
F_9 () ;
}
for ( V_37 = 0 ; V_42 >= 0 && V_37 < V_72 ; V_37 ++ ) {
V_73 = & V_71 [ V_37 ] ;
F_11 ( V_2 -> V_24 ,
L_17 ,
V_73 -> V_60 & V_79 ? L_18 : L_19 ,
V_73 -> V_80 , V_73 -> V_81 , V_37 + 1 , V_72 ) ;
if ( V_73 -> V_60 & V_79 ) {
bool V_64 = V_73 -> V_60 & V_82 ;
V_42 = F_41 ( V_2 , V_73 -> V_81 , V_73 -> V_83 , V_73 -> V_80 , V_37 ,
V_64 ) ;
if ( V_64 && V_42 > 0 )
V_73 -> V_80 = V_42 ;
} else {
V_42 =
F_40 ( V_2 , V_73 -> V_81 , V_73 -> V_83 , V_73 -> V_80 , V_37 ) ;
}
}
F_39 ( V_2 ) ;
V_21 = V_22 ;
while ( F_4 ( V_2 -> V_4 + V_8 ) & V_74 ) {
if ( F_10 ( V_22 , V_21 + V_77 ) ) {
T_4 V_78 = F_4 ( V_2 -> V_4 + V_8 ) ;
F_11 ( V_2 -> V_24 , L_1 ) ;
if ( ( V_78 & ( V_27 | V_74 | V_29 ) ) != 0 ) {
F_2 ( V_78 & ~ V_28 ,
V_2 -> V_4 + V_8 ) ;
F_6 ( V_2 ) ;
}
return - V_25 ;
}
F_45 () ;
}
return ( V_42 < 0 ) ? V_42 : V_72 ;
}
static T_1 F_46 ( struct V_69 * V_59 )
{
return V_84 | V_85
| V_86 | V_87 ;
}
static int F_47 ( struct V_88 * V_89 )
{
const struct V_90 * V_91 ;
struct V_1 * V_2 ;
const T_1 * V_51 ;
T_1 clock = V_38 ;
int V_23 = 0 ;
int V_92 ;
struct V_93 V_94 ;
struct V_95 * V_95 ;
int V_96 ;
V_91 = F_48 ( V_97 , & V_89 -> V_24 ) ;
if ( ! V_91 )
return - V_39 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_24 = & V_89 -> V_24 ;
F_50 ( & V_2 -> V_11 ) ;
V_2 -> V_4 = F_22 ( V_89 -> V_24 . V_100 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_51 ( V_2 -> V_24 , L_20 ) ;
V_23 = - V_99 ;
goto V_101;
}
V_2 -> V_6 = F_52 ( V_89 -> V_24 . V_100 , 0 ) ;
if ( V_2 -> V_6 ) {
V_23 = F_53 ( V_2 -> V_6 , F_3 ,
V_102 , L_21 , V_2 ) ;
if ( V_23 < 0 ) {
F_51 ( V_2 -> V_24 , L_22 ) ;
goto V_103;
}
}
V_95 = F_54 ( & V_89 -> V_24 , NULL ) ;
if ( ! F_55 ( V_95 ) ) {
V_96 = F_56 ( V_95 ) ;
if ( V_96 ) {
F_51 ( & V_89 -> V_24 , L_23 ) ;
goto V_103;
} else {
V_2 -> V_104 = V_95 ;
}
}
if ( F_23 ( V_89 -> V_24 . V_100 , L_24 , NULL ) ) {
clock = V_43 ;
} else {
V_51 = F_23 ( V_89 -> V_24 . V_100 , L_25 ,
& V_92 ) ;
if ( V_51 && V_92 == sizeof( T_1 ) )
clock = * V_51 ;
}
if ( V_91 -> V_56 ) {
const struct V_105 * V_56 = V_91 -> V_56 ;
V_56 -> V_106 ( V_89 -> V_24 . V_100 , V_2 , clock , V_56 -> V_32 ) ;
} else {
if ( F_23 ( V_89 -> V_24 . V_100 , L_26 , NULL ) )
F_37 ( V_89 -> V_24 . V_100 , V_2 , clock , 0 ) ;
}
V_51 = F_23 ( V_89 -> V_24 . V_100 , L_27 , & V_92 ) ;
if ( V_51 && V_92 == sizeof( T_1 ) ) {
V_107 . V_19 = * V_51 * V_77 / 1000000 ;
if ( V_107 . V_19 < 5 )
V_107 . V_19 = 5 ;
}
F_19 ( V_2 -> V_24 , L_28 , V_107 . V_19 * 1000000 / V_77 ) ;
F_57 ( V_89 , V_2 ) ;
V_2 -> V_59 = V_107 ;
F_58 ( V_89 -> V_24 . V_100 , 0 , & V_94 ) ;
F_59 ( V_2 -> V_59 . V_108 , sizeof( V_2 -> V_59 . V_108 ) ,
L_29 , ( unsigned long long ) V_94 . V_109 ) ;
F_60 ( & V_2 -> V_59 , V_2 ) ;
V_2 -> V_59 . V_24 . V_110 = & V_89 -> V_24 ;
V_2 -> V_59 . V_24 . V_100 = F_61 ( V_89 -> V_24 . V_100 ) ;
V_23 = F_62 ( & V_2 -> V_59 ) ;
if ( V_23 < 0 ) {
F_51 ( V_2 -> V_24 , L_30 ) ;
goto V_111;
}
return V_23 ;
V_111:
if ( V_2 -> V_104 )
F_63 ( V_2 -> V_104 ) ;
F_64 ( V_2 -> V_6 , V_2 ) ;
V_103:
F_65 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_4 ) ;
V_101:
F_66 ( V_2 ) ;
return V_23 ;
}
static int F_67 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_68 ( V_89 ) ;
F_69 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_104 )
F_63 ( V_2 -> V_104 ) ;
if ( V_2 -> V_6 )
F_64 ( V_2 -> V_6 , V_2 ) ;
F_65 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_4 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_112 * V_24 )
{
struct V_1 * V_2 = F_71 ( V_24 ) ;
V_2 -> V_41 = F_4 ( V_2 -> V_4 + V_44 ) ;
V_2 -> V_113 = F_4 ( V_2 -> V_4 + V_54 ) ;
return 0 ;
}
static int F_72 ( struct V_112 * V_24 )
{
struct V_1 * V_2 = F_71 ( V_24 ) ;
F_2 ( V_2 -> V_41 , V_2 -> V_4 + V_44 ) ;
F_2 ( V_2 -> V_113 , V_2 -> V_4 + V_54 ) ;
return 0 ;
}
