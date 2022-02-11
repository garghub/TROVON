static void F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 -> V_4 + V_2 * 4 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , int V_2 )
{
return F_4 ( V_1 -> V_4 + V_2 * 4 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 , 0x00000020 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 , 0x00000010 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_5 )
{
F_1 ( V_1 , 5 , V_5 ) ;
F_1 ( V_1 , 0 , 0x0c000040 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 , 0x08080000 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 57 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x20000000 )
return 0 ;
F_1 ( V_1 , 0 , 0x00000008 ) ;
}
F_10 ( & V_1 -> V_7 -> V_8 , L_1 ) ;
return - V_9 ;
}
static T_2 F_11 ( struct V_1 * V_1 )
{
int V_6 ;
T_2 V_10 ;
V_10 = 0 ;
for ( V_6 = 0 ; V_6 < 57 ; V_6 ++ ) {
V_10 |= ( T_2 ) ( F_3 ( V_1 , 0 ) >> 30 & 1 ) << V_6 ;
F_1 ( V_1 , 0 , 0x00000008 ) ;
}
return V_10 ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , 0 , 0x00000008 ) ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x80000000 )
return 0 ;
F_13 ( ( V_11 + 999 ) / 1000 ) ;
}
F_10 ( & V_1 -> V_7 -> V_8 , L_2 ) ;
return - V_9 ;
}
static int F_14 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , 0 , 0x01010000 ) ;
F_1 ( V_1 , 0 , 0x01000000 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x00000001 )
return 0 ;
F_13 ( ( V_11 + 999 ) / 1000 ) ;
}
F_10 ( & V_1 -> V_7 -> V_8 , L_3 ) ;
return - V_9 ;
}
static int F_15 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , 0 , 0x02020000 ) ;
F_1 ( V_1 , 0 , 0x02000000 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x00000002 )
return 0 ;
F_13 ( ( V_11 + 999 ) / 1000 ) ;
}
F_10 ( & V_1 -> V_7 -> V_8 , L_4 ) ;
return - V_9 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_6 , V_12 ;
T_1 V_13 ;
V_13 = F_3 ( V_1 , 0 ) & 0x00000004 ;
F_1 ( V_1 , 0 , 0x00000002 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
for ( V_12 = 0 ; V_12 < 1024 ; V_12 ++ ) {
if ( ( F_3 ( V_1 , 0 ) & 0x00000004 ) != V_13 )
return 0 ;
}
F_13 ( ( V_11 + 999 ) / 1000 ) ;
}
F_10 ( & V_1 -> V_7 -> V_8 , L_5 ) ;
return - V_9 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_6 , V_14 ;
int V_15 ;
F_13 ( ( V_11 + 999 ) / 1000 ) ;
V_15 = V_1 -> V_7 -> V_16 == 0x211a ? 128 : 166 ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
V_14 = F_16 ( V_1 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 , 0x0b0b0000 ) ;
}
static void F_19 ( struct V_1 * V_1 , int V_17 , int V_18 )
{
F_1 ( V_1 , 2 , 1 << ( V_17 + 8 ) | V_18 << V_17 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_19 ( V_1 , V_6 , 0 ) ;
}
static int F_21 ( struct V_1 * V_1 , struct V_20 * V_21 )
{
T_1 V_22 ;
int V_6 ;
int V_17 ;
struct V_23 * V_24 ;
int V_25 ;
T_3 * V_26 ;
int V_27 ;
if ( ! V_21 -> V_28 [ V_29 - 1 ] )
return 0 ;
for ( V_6 = 0 ; V_6 < V_29 ; V_6 ++ ) {
V_22 = F_22 ( V_21 -> V_28 [ V_6 ] ) ;
V_17 = ( V_22 >> 29 ) - 1 ;
if ( V_17 < 0 || V_17 >= V_19 )
continue;
V_24 = V_1 -> V_30 [ V_17 ] ;
if ( V_22 >> 25 & 1 )
V_24 -> V_31 = 0 ;
else if ( ! V_24 -> V_31 )
continue;
if ( V_22 >> 24 & 1 )
F_23 ( V_32 L_6 ,
V_1 -> V_33 , V_1 -> V_34 ) ;
V_27 = V_22 >> 26 & 0x7 ;
if ( V_24 -> V_35 != - 1 && V_27 != ( ( V_24 -> V_35 + 1 ) & 0x7 ) )
F_23 ( V_32 L_7 ,
V_17 ) ;
V_24 -> V_35 = V_27 ;
V_26 = V_24 -> V_26 ;
V_25 = V_24 -> V_36 * 188 + V_24 -> V_31 * 3 ;
V_26 [ V_25 ] = V_22 >> 16 ;
V_26 [ V_25 + 1 ] = V_22 >> 8 ;
if ( V_24 -> V_31 != 62 )
V_26 [ V_25 + 2 ] = V_22 ;
if ( ++ V_24 -> V_31 >= 63 ) {
V_24 -> V_31 = 0 ;
if ( ++ V_24 -> V_36 >= 21 ) {
F_24 ( & V_24 -> V_37 , V_26 , 21 ) ;
V_24 -> V_36 = 0 ;
}
}
}
V_21 -> V_28 [ V_29 - 1 ] = 0 ;
return 1 ;
}
static int F_25 ( void * V_3 )
{
struct V_1 * V_1 ;
struct V_20 * V_21 ;
V_1 = V_3 ;
F_26 () ;
while ( ! F_27 () ) {
F_28 () ;
V_21 = V_1 -> V_38 [ V_1 -> V_33 ] . V_39 [ V_1 -> V_34 ] . V_21 ;
if ( ! F_21 ( V_1 , V_21 ) ) {
F_29 ( ( V_11 + 999 ) / 1000 ) ;
continue;
}
if ( ++ V_1 -> V_34 >= V_40 ) {
F_5 ( V_1 ) ;
V_1 -> V_34 = 0 ;
if ( ++ V_1 -> V_33 >= V_41 )
V_1 -> V_33 = 0 ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_1 , void * V_21 , T_4 V_42 )
{
F_31 ( & V_1 -> V_7 -> V_8 , V_43 , V_21 , V_42 ) ;
}
static void * F_32 ( struct V_1 * V_1 , T_4 * V_44 , T_1 * V_45 )
{
void * V_21 ;
T_4 V_42 ;
V_21 = F_33 ( & V_1 -> V_7 -> V_8 , V_43 , & V_42 ,
V_46 ) ;
if ( V_21 == NULL )
return NULL ;
F_34 ( V_42 & ( V_43 - 1 ) ) ;
F_34 ( V_42 >> V_47 >> 31 >> 1 ) ;
* V_44 = V_42 ;
* V_45 = V_42 >> V_47 ;
return V_21 ;
}
static void F_35 ( struct V_1 * V_1 , struct V_48 * V_26 )
{
F_30 ( V_1 , V_26 -> V_21 , V_26 -> V_42 ) ;
}
static int
F_36 ( struct V_1 * V_1 , struct V_48 * V_26 , T_1 * V_45 )
{
struct V_20 * V_21 ;
T_4 V_42 ;
V_21 = F_32 ( V_1 , & V_42 , V_45 ) ;
if ( V_21 == NULL )
return - V_49 ;
V_21 -> V_28 [ V_29 - 1 ] = 0 ;
V_26 -> V_21 = V_21 ;
V_26 -> V_42 = V_42 ;
return 0 ;
}
static void F_37 ( struct V_1 * V_1 , struct V_50 * V_51 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_40 ; V_6 ++ )
F_35 ( V_1 , & V_51 -> V_39 [ V_6 ] ) ;
F_30 ( V_1 , V_51 -> V_21 , V_51 -> V_42 ) ;
}
static int
F_38 ( struct V_1 * V_1 , struct V_50 * V_51 , T_1 * V_45 )
{
struct V_52 * V_21 ;
T_4 V_42 ;
int V_6 , V_14 ;
T_1 V_53 ;
V_21 = F_32 ( V_1 , & V_42 , V_45 ) ;
if ( V_21 == NULL )
return - V_49 ;
for ( V_6 = 0 ; V_6 < V_40 ; V_6 ++ ) {
V_14 = F_36 ( V_1 , & V_51 -> V_39 [ V_6 ] , & V_53 ) ;
if ( V_14 < 0 )
goto V_54;
V_21 -> V_55 [ V_6 ] = F_39 ( V_53 ) ;
}
F_5 ( V_1 ) ;
V_51 -> V_21 = V_21 ;
V_51 -> V_42 = V_42 ;
return 0 ;
V_54:
while ( V_6 -- )
F_35 ( V_1 , & V_51 -> V_39 [ V_6 ] ) ;
F_30 ( V_1 , V_21 , V_42 ) ;
return V_14 ;
}
static void F_40 ( struct V_1 * V_1 )
{
struct V_50 * V_38 ;
int V_6 ;
V_38 = V_1 -> V_38 ;
F_8 ( V_1 ) ;
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ )
F_37 ( V_1 , & V_38 [ V_6 ] ) ;
F_41 ( V_38 ) ;
}
static int F_42 ( struct V_1 * V_1 )
{
struct V_50 * V_38 ;
int V_6 , V_14 ;
T_1 V_5 , V_56 ;
V_38 = F_43 ( sizeof( struct V_50 ) * V_41 ) ;
if ( V_38 == NULL )
return - V_49 ;
F_6 ( V_1 ) ;
V_6 = 0 ;
if ( V_41 ) {
V_14 = F_38 ( V_1 , & V_38 [ 0 ] , & V_5 ) ;
if ( V_14 )
goto V_54;
V_6 ++ ;
}
while ( V_6 < V_41 ) {
V_14 = F_38 ( V_1 , & V_38 [ V_6 ] , & V_56 ) ;
if ( V_14 )
goto V_54;
V_38 [ V_6 - 1 ] . V_21 -> V_57 = F_39 ( V_56 ) ;
V_6 ++ ;
}
V_38 [ V_41 - 1 ] . V_21 -> V_57 = F_39 ( V_5 ) ;
F_7 ( V_1 , V_5 ) ;
V_1 -> V_38 = V_38 ;
return 0 ;
V_54:
while ( V_6 -- )
F_37 ( V_1 , & V_38 [ V_6 ] ) ;
F_41 ( V_38 ) ;
return V_14 ;
}
static int F_44 ( struct V_1 * V_1 )
{
int V_14 = 0 ;
F_45 ( & V_1 -> V_58 ) ;
if ( ! V_1 -> V_59 ) {
V_1 -> V_59 = F_46 ( F_25 , V_1 , L_8 ) ;
if ( F_47 ( V_1 -> V_59 ) ) {
V_14 = F_48 ( V_1 -> V_59 ) ;
V_1 -> V_59 = NULL ;
}
}
F_49 ( & V_1 -> V_58 ) ;
return V_14 ;
}
static int F_50 ( struct V_60 * V_61 )
{
struct V_23 * V_24 ;
V_24 = F_51 ( V_61 -> V_37 , struct V_23 , V_37 ) ;
if ( ! V_24 -> V_62 ++ ) {
int V_14 ;
V_14 = F_44 ( V_24 -> V_1 ) ;
if ( V_14 )
return V_14 ;
F_19 ( V_24 -> V_1 , V_24 -> V_17 , 1 ) ;
}
return 0 ;
}
static void F_52 ( struct V_1 * V_1 )
{
int V_6 , V_63 ;
F_45 ( & V_1 -> V_58 ) ;
for ( V_6 = 0 , V_63 = 0 ; V_6 < V_19 ; V_6 ++ )
V_63 += V_1 -> V_30 [ V_6 ] -> V_62 ;
if ( V_63 == 0 && V_1 -> V_59 ) {
F_53 ( V_1 -> V_59 ) ;
V_1 -> V_59 = NULL ;
}
F_49 ( & V_1 -> V_58 ) ;
}
static int F_54 ( struct V_60 * V_61 )
{
struct V_23 * V_24 ;
V_24 = F_51 ( V_61 -> V_37 , struct V_23 , V_37 ) ;
if ( ! -- V_24 -> V_62 ) {
F_19 ( V_24 -> V_1 , V_24 -> V_17 , 0 ) ;
F_52 ( V_24 -> V_1 ) ;
}
return 0 ;
}
static void
F_55 ( struct V_1 * V_1 )
{
int V_64 ;
int V_6 ;
struct V_23 * V_24 ;
static const int V_65 [] = {
1 << 4 ,
1 << 6 | 1 << 7 ,
1 << 5 ,
1 << 6 | 1 << 8 ,
} ;
V_64 = V_1 -> V_66 | ! V_1 -> V_67 << 3 ;
F_45 ( & V_1 -> V_58 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
V_24 = V_1 -> V_30 [ V_6 ] ;
switch ( V_24 -> V_68 ) {
case V_69 :
V_64 |= 1 << 1 ;
break;
case V_70 :
V_64 |= 1 << 1 | 1 << 2 ;
break;
default:
break;
}
V_64 |= V_65 [ V_6 ] ;
}
F_1 ( V_1 , 1 , V_64 ) ;
F_49 ( & V_1 -> V_58 ) ;
}
static int F_56 ( struct V_71 * V_72 , enum V_73 V_68 )
{
struct V_23 * V_24 ;
V_24 = F_51 ( V_72 -> V_74 , struct V_23 , V_24 ) ;
V_24 -> V_68 = V_68 ;
F_55 ( V_24 -> V_1 ) ;
if ( V_24 -> V_75 )
return V_24 -> V_75 ( V_72 , V_68 ) ;
else
return 0 ;
}
static int F_57 ( struct V_71 * V_72 )
{
struct V_23 * V_24 ;
V_24 = F_51 ( V_72 -> V_74 , struct V_23 , V_24 ) ;
V_24 -> V_76 = 1 ;
F_55 ( V_24 -> V_1 ) ;
if ( V_24 -> V_77 )
return V_24 -> V_77 ( V_72 ) ;
else
return 0 ;
}
static int F_58 ( struct V_71 * V_72 )
{
struct V_23 * V_24 ;
V_24 = F_51 ( V_72 -> V_74 , struct V_23 , V_24 ) ;
V_24 -> V_76 = 0 ;
F_55 ( V_24 -> V_1 ) ;
F_13 ( ( V_11 + 999 ) / 1000 ) ;
if ( V_24 -> V_78 )
return V_24 -> V_78 ( V_72 ) ;
else
return 0 ;
}
static void F_59 ( struct V_23 * V_24 )
{
V_24 -> V_37 . V_79 . V_80 ( & V_24 -> V_37 . V_79 ) ;
F_60 ( & V_24 -> V_81 ) ;
F_61 ( & V_24 -> V_37 ) ;
F_62 ( & V_24 -> V_24 ) ;
F_63 ( ( unsigned long ) V_24 -> V_26 ) ;
F_64 ( V_24 ) ;
}
static struct V_23 *
F_65 ( struct V_1 * V_1 )
{
struct V_23 * V_24 ;
void * V_26 ;
struct V_82 * V_83 ;
struct V_84 * V_37 ;
struct V_81 * V_81 ;
int V_14 ;
V_24 = F_66 ( sizeof( struct V_23 ) , V_46 ) ;
if ( ! V_24 ) {
V_14 = - V_49 ;
goto V_54;
}
V_24 -> V_1 = V_1 ;
V_24 -> V_68 = V_85 ;
V_24 -> V_76 = 1 ;
V_26 = ( T_3 * ) F_67 ( V_46 ) ;
if ( ! V_26 ) {
V_14 = - V_49 ;
goto V_86;
}
V_24 -> V_26 = V_26 ;
V_24 -> V_31 = 0 ;
V_24 -> V_36 = 0 ;
V_24 -> V_35 = - 1 ;
V_83 = & V_24 -> V_24 ;
V_83 -> V_87 = V_24 ;
V_14 = F_68 ( V_83 , V_88 , V_89 ,
& V_1 -> V_7 -> V_8 , V_90 ) ;
if ( V_14 < 0 )
goto V_91;
V_37 = & V_24 -> V_37 ;
V_37 -> V_79 . V_92 = V_93 | V_94 ;
V_37 -> V_87 = V_24 ;
V_37 -> V_95 = 256 ;
V_37 -> V_96 = 256 ;
V_37 -> V_97 = F_50 ;
V_37 -> V_98 = F_54 ;
V_37 -> V_99 = NULL ;
V_14 = F_69 ( V_37 ) ;
if ( V_14 < 0 )
goto V_100;
V_81 = & V_24 -> V_81 ;
V_81 -> V_96 = 256 ;
V_81 -> V_37 = & V_37 -> V_79 ;
V_81 -> V_92 = 0 ;
V_14 = F_70 ( V_81 , V_83 ) ;
if ( V_14 < 0 )
goto V_101;
return V_24 ;
V_101:
F_61 ( V_37 ) ;
V_100:
F_62 ( V_83 ) ;
V_91:
F_63 ( ( unsigned long ) V_26 ) ;
V_86:
F_64 ( V_24 ) ;
V_54:
return F_71 ( V_14 ) ;
}
static void F_72 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_59 ( V_1 -> V_30 [ V_6 ] ) ;
}
static int F_73 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_23 * V_24 ;
int V_14 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
V_24 = F_65 ( V_1 ) ;
if ( F_47 ( V_24 ) ) {
V_14 = F_48 ( V_24 ) ;
goto V_54;
}
V_24 -> V_17 = V_6 ;
V_1 -> V_30 [ V_6 ] = V_24 ;
}
return 0 ;
V_54:
while ( V_6 -- )
F_59 ( V_1 -> V_30 [ V_6 ] ) ;
return V_14 ;
}
static void F_74 ( struct V_23 * V_24 )
{
F_75 ( V_24 -> V_72 ) ;
}
static int F_76 ( struct V_23 * V_24 , struct V_71 * V_72 )
{
int V_14 ;
V_24 -> V_75 = V_72 -> V_102 . V_103 ;
V_24 -> V_77 = V_72 -> V_102 . V_76 ;
V_24 -> V_78 = V_72 -> V_102 . V_104 ;
V_72 -> V_102 . V_103 = F_56 ;
V_72 -> V_102 . V_76 = F_57 ;
V_72 -> V_102 . V_104 = F_58 ;
V_14 = F_77 ( & V_24 -> V_24 , V_72 ) ;
if ( V_14 < 0 )
return V_14 ;
V_24 -> V_72 = V_72 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_74 ( V_1 -> V_30 [ V_6 ] ) ;
}
static int F_79 ( struct V_1 * V_1 )
{
int V_6 , V_12 ;
struct V_105 * V_106 ;
const struct V_107 * V_108 , * V_109 ;
struct V_71 * V_72 [ 4 ] ;
int V_14 ;
V_6 = 0 ;
V_12 = 0 ;
V_106 = & V_1 -> V_106 ;
V_108 = V_1 -> V_7 -> V_16 == 0x211a ? V_110 : V_111 ;
do {
V_109 = & V_108 [ V_6 / 2 ] ;
V_72 [ V_6 ] = F_80 ( & V_109 -> V_112 ,
V_106 ) ;
if ( ! V_72 [ V_6 ] ) {
V_14 = - V_113 ;
goto V_54;
}
V_6 ++ ;
V_72 [ V_6 ] = F_81 ( & V_109 -> V_114 ,
V_106 ) ;
if ( ! V_72 [ V_6 ] ) {
V_14 = - V_113 ;
goto V_54;
}
V_6 ++ ;
V_14 = F_82 ( V_72 [ V_6 - 2 ] ) ;
if ( V_14 < 0 )
goto V_54;
V_14 = F_83 ( V_72 [ V_6 - 1 ] ) ;
if ( V_14 < 0 )
goto V_54;
} while ( V_6 < 4 );
do {
V_14 = F_76 ( V_1 -> V_30 [ V_12 ] , V_72 [ V_12 ] ) ;
if ( V_14 < 0 )
goto V_54;
} while ( ++ V_12 < 4 );
return 0 ;
V_54:
while ( V_6 -- > V_12 )
V_72 [ V_6 ] -> V_102 . V_115 ( V_72 [ V_6 ] ) ;
while ( V_12 -- )
F_75 ( V_72 [ V_12 ] ) ;
return V_14 ;
}
static void F_84 ( struct V_1 * V_1 , int V_42 , int V_116 , int V_117 ,
int clock , int V_3 , int V_118 )
{
F_1 ( V_1 , 4 , V_42 << 18 | V_116 << 13 | V_117 << 12 |
! clock << 11 | ! V_3 << 10 | V_118 ) ;
}
static void F_85 ( struct V_1 * V_1 , int V_42 , int * V_44 , int V_3 )
{
F_84 ( V_1 , V_42 , 1 , 0 , 0 , V_3 , V_42 + 1 ) ;
F_84 ( V_1 , V_42 + 1 , 1 , 0 , 1 , V_3 , V_42 + 2 ) ;
F_84 ( V_1 , V_42 + 2 , 1 , 0 , 0 , V_3 , V_42 + 3 ) ;
* V_44 = V_42 + 3 ;
}
static void F_86 ( struct V_1 * V_1 , int V_42 , int * V_44 )
{
F_84 ( V_1 , V_42 , 1 , 0 , 0 , 1 , V_42 + 1 ) ;
F_84 ( V_1 , V_42 + 1 , 1 , 0 , 1 , 1 , V_42 + 2 ) ;
F_84 ( V_1 , V_42 + 2 , 1 , 1 , 1 , 1 , V_42 + 3 ) ;
F_84 ( V_1 , V_42 + 3 , 1 , 0 , 0 , 1 , V_42 + 4 ) ;
* V_44 = V_42 + 4 ;
}
static void F_87 ( struct V_1 * V_1 , int V_42 , int * V_44 , int V_3 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
F_85 ( V_1 , V_42 , & V_42 , V_3 >> ( 7 - V_6 ) & 1 ) ;
F_85 ( V_1 , V_42 , & V_42 , 1 ) ;
* V_44 = V_42 ;
}
static void F_88 ( struct V_1 * V_1 , int V_42 , int * V_44 , int V_119 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
F_86 ( V_1 , V_42 , & V_42 ) ;
F_85 ( V_1 , V_42 , & V_42 , V_119 ) ;
* V_44 = V_42 ;
}
static void F_89 ( struct V_1 * V_1 , int V_42 , int * V_44 )
{
F_84 ( V_1 , V_42 , 1 , 0 , 1 , 1 , V_42 + 1 ) ;
F_84 ( V_1 , V_42 + 1 , 1 , 0 , 1 , 0 , V_42 + 2 ) ;
F_84 ( V_1 , V_42 + 2 , 1 , 0 , 0 , 0 , V_42 + 3 ) ;
* V_44 = V_42 + 3 ;
}
static void
F_90 ( struct V_1 * V_1 , int V_42 , int * V_44 , struct V_120 * V_121 )
{
int V_6 ;
F_89 ( V_1 , V_42 , & V_42 ) ;
F_87 ( V_1 , V_42 , & V_42 , V_121 -> V_42 << 1 ) ;
for ( V_6 = 0 ; V_6 < V_121 -> V_122 ; V_6 ++ )
F_87 ( V_1 , V_42 , & V_42 , V_121 -> V_26 [ V_6 ] ) ;
* V_44 = V_42 ;
}
static void
F_91 ( struct V_1 * V_1 , int V_42 , int * V_44 , struct V_120 * V_121 )
{
int V_6 ;
F_89 ( V_1 , V_42 , & V_42 ) ;
F_87 ( V_1 , V_42 , & V_42 , V_121 -> V_42 << 1 | 1 ) ;
for ( V_6 = 0 ; V_6 < V_121 -> V_122 ; V_6 ++ )
F_88 ( V_1 , V_42 , & V_42 , V_6 == V_121 -> V_122 - 1 ) ;
* V_44 = V_42 ;
}
static int F_92 ( struct V_1 * V_1 , int V_42 )
{
F_84 ( V_1 , V_42 , 1 , 0 , 0 , 0 , V_42 + 1 ) ;
F_84 ( V_1 , V_42 + 1 , 1 , 0 , 1 , 0 , V_42 + 2 ) ;
F_84 ( V_1 , V_42 + 2 , 1 , 0 , 1 , 1 , 0 ) ;
F_1 ( V_1 , 0 , 0x00000004 ) ;
do {
if ( F_93 ( V_123 ) )
return - V_124 ;
F_29 ( ( V_11 + 999 ) / 1000 ) ;
} while ( F_3 ( V_1 , 0 ) & 0x00000080 );
return 0 ;
}
static void F_94 ( struct V_1 * V_1 , int * V_44 )
{
int V_42 ;
V_42 = 0 ;
F_84 ( V_1 , V_42 , 0 , 0 , 1 , 1 , V_42 ) ;
V_42 = V_42 + 1 ;
if ( ! V_1 -> V_125 ) {
F_84 ( V_1 , V_42 , 1 , 0 , 1 , 1 , V_42 + 1 ) ;
F_84 ( V_1 , V_42 + 1 , 1 , 0 , 1 , 0 , V_42 + 2 ) ;
V_42 = V_42 + 2 ;
V_1 -> V_125 = 1 ;
}
* V_44 = V_42 ;
}
static int F_95 ( struct V_105 * V_24 , struct V_120 * V_126 , int V_127 )
{
struct V_1 * V_1 ;
int V_6 ;
struct V_120 * V_121 , * V_128 ;
int V_42 , V_14 ;
T_5 V_122 ;
T_1 V_129 ;
V_1 = F_96 ( V_24 ) ;
for ( V_6 = 0 ; V_6 < V_127 ; V_6 ++ ) {
V_121 = & V_126 [ V_6 ] ;
if ( V_121 -> V_130 & V_131 )
return - V_132 ;
if ( V_6 + 1 < V_127 )
V_128 = & V_126 [ V_6 + 1 ] ;
else
V_128 = NULL ;
if ( V_128 && V_128 -> V_130 & V_131 ) {
V_6 ++ ;
V_122 = V_128 -> V_122 ;
if ( V_122 > 4 )
return - V_132 ;
F_94 ( V_1 , & V_42 ) ;
F_90 ( V_1 , V_42 , & V_42 , V_121 ) ;
F_91 ( V_1 , V_42 , & V_42 , V_128 ) ;
V_14 = F_92 ( V_1 , V_42 ) ;
if ( V_14 < 0 )
return V_14 ;
V_129 = F_3 ( V_1 , 2 ) ;
while ( V_122 -- ) {
V_128 -> V_26 [ V_122 ] = V_129 ;
V_129 >>= 8 ;
}
} else {
F_94 ( V_1 , & V_42 ) ;
F_90 ( V_1 , V_42 , & V_42 , V_121 ) ;
V_14 = F_92 ( V_1 , V_42 ) ;
if ( V_14 < 0 )
return V_14 ;
}
}
return V_127 ;
}
static T_1 F_97 ( struct V_105 * V_24 )
{
return V_133 ;
}
static void F_98 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 128 ; V_6 ++ )
F_84 ( V_1 , 0 , 0 , 0 , 1 , 1 , 0 ) ;
}
static void F_99 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 1024 ; V_6 ++ )
F_84 ( V_1 , V_6 , 0 , 0 , 1 , 1 , 0 ) ;
}
static void F_100 ( struct V_134 * V_7 )
{
struct V_1 * V_1 ;
void T_6 * V_4 ;
V_1 = F_101 ( V_7 ) ;
V_4 = V_1 -> V_4 ;
if ( V_1 -> V_59 )
F_53 ( V_1 -> V_59 ) ;
F_40 ( V_1 ) ;
F_78 ( V_1 ) ;
F_18 ( V_1 ) ;
V_1 -> V_66 = 0 ;
V_1 -> V_67 = 1 ;
F_55 ( V_1 ) ;
F_72 ( V_1 ) ;
F_102 ( & V_1 -> V_106 ) ;
F_64 ( V_1 ) ;
F_103 ( V_7 , V_4 ) ;
F_104 ( V_7 ) ;
F_105 ( V_7 ) ;
}
static int F_106 ( struct V_134 * V_7 , const struct V_135 * V_136 )
{
int V_14 ;
void T_6 * V_4 ;
struct V_1 * V_1 ;
struct V_105 * V_106 ;
V_14 = F_107 ( V_7 ) ;
if ( V_14 < 0 )
goto V_54;
V_14 = F_108 ( V_7 , F_109 ( 32 ) ) ;
if ( V_14 < 0 )
goto V_137;
F_110 ( V_7 ) ;
V_14 = F_111 ( V_7 , V_88 ) ;
if ( V_14 < 0 )
goto V_137;
V_4 = F_112 ( V_7 , 0 , 0 ) ;
if ( ! V_4 ) {
V_14 = - V_9 ;
goto V_138;
}
V_1 = F_66 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_1 ) {
V_14 = - V_49 ;
goto V_139;
}
F_113 ( & V_1 -> V_58 ) ;
V_1 -> V_7 = V_7 ;
V_1 -> V_4 = V_4 ;
F_114 ( V_7 , V_1 ) ;
V_14 = F_73 ( V_1 ) ;
if ( V_14 < 0 )
goto V_86;
F_113 ( & V_1 -> V_58 ) ;
V_1 -> V_66 = 0 ;
V_1 -> V_67 = 1 ;
F_55 ( V_1 ) ;
V_106 = & V_1 -> V_106 ;
V_106 -> V_140 = & V_141 ;
V_106 -> V_142 = NULL ;
V_106 -> V_8 . V_143 = & V_7 -> V_8 ;
strcpy ( V_106 -> V_144 , V_88 ) ;
F_115 ( V_106 , V_1 ) ;
V_14 = F_116 ( V_106 ) ;
if ( V_14 < 0 )
goto V_145;
F_99 ( V_1 ) ;
F_98 ( V_1 ) ;
V_14 = F_9 ( V_1 ) ;
if ( V_14 < 0 )
goto V_146;
F_11 ( V_1 ) ;
V_14 = F_12 ( V_1 ) ;
if ( V_14 < 0 )
goto V_146;
V_14 = F_14 ( V_1 ) ;
if ( V_14 < 0 )
goto V_146;
V_14 = F_15 ( V_1 ) ;
if ( V_14 < 0 )
goto V_146;
V_14 = F_17 ( V_1 ) ;
if ( V_14 < 0 )
goto V_146;
F_20 ( V_1 ) ;
V_1 -> V_66 = 1 ;
F_55 ( V_1 ) ;
F_13 ( ( V_11 + 49 ) / 50 ) ;
V_1 -> V_67 = 0 ;
F_55 ( V_1 ) ;
F_13 ( ( V_11 + 999 ) / 1000 ) ;
V_14 = F_79 ( V_1 ) ;
if ( V_14 < 0 )
goto V_147;
V_14 = F_42 ( V_1 ) ;
if ( V_14 < 0 )
goto V_148;
return 0 ;
V_148:
F_78 ( V_1 ) ;
V_147:
F_18 ( V_1 ) ;
V_1 -> V_66 = 0 ;
V_1 -> V_67 = 1 ;
F_55 ( V_1 ) ;
V_146:
F_102 ( V_106 ) ;
V_145:
F_72 ( V_1 ) ;
V_86:
F_64 ( V_1 ) ;
V_139:
F_103 ( V_7 , V_4 ) ;
V_138:
F_104 ( V_7 ) ;
V_137:
F_105 ( V_7 ) ;
V_54:
return V_14 ;
}
