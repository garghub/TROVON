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
F_10 ( V_7 , V_1 , L_1 ) ;
return - V_8 ;
}
static T_2 F_11 ( struct V_1 * V_1 )
{
int V_6 ;
T_2 V_9 ;
V_9 = 0 ;
for ( V_6 = 0 ; V_6 < 57 ; V_6 ++ ) {
V_9 |= ( T_2 ) ( F_3 ( V_1 , 0 ) >> 30 & 1 ) << V_6 ;
F_1 ( V_1 , 0 , 0x00000008 ) ;
}
return V_9 ;
}
static int F_12 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , 0 , 0x00000008 ) ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x80000000 )
return 0 ;
F_13 ( ( V_10 + 999 ) / 1000 ) ;
}
F_10 ( V_7 , V_1 , L_2 ) ;
return - V_8 ;
}
static int F_14 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , 0 , 0x01010000 ) ;
F_1 ( V_1 , 0 , 0x01000000 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x00000001 )
return 0 ;
F_13 ( ( V_10 + 999 ) / 1000 ) ;
}
F_10 ( V_7 , V_1 , L_3 ) ;
return - V_8 ;
}
static int F_15 ( struct V_1 * V_1 )
{
int V_6 ;
F_1 ( V_1 , 0 , 0x02020000 ) ;
F_1 ( V_1 , 0 , 0x02000000 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
if ( F_3 ( V_1 , 0 ) & 0x00000002 )
return 0 ;
F_13 ( ( V_10 + 999 ) / 1000 ) ;
}
F_10 ( V_7 , V_1 , L_4 ) ;
return - V_8 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_6 , V_11 ;
T_1 V_12 ;
V_12 = F_3 ( V_1 , 0 ) & 0x00000004 ;
F_1 ( V_1 , 0 , 0x00000002 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
for ( V_11 = 0 ; V_11 < 1024 ; V_11 ++ ) {
if ( ( F_3 ( V_1 , 0 ) & 0x00000004 ) != V_12 )
return 0 ;
}
F_13 ( ( V_10 + 999 ) / 1000 ) ;
}
F_10 ( V_7 , V_1 , L_5 ) ;
return - V_8 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_6 , V_13 ;
int V_14 ;
F_13 ( ( V_10 + 999 ) / 1000 ) ;
V_14 = V_1 -> V_15 -> V_16 == 0x211a ? 128 : 166 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
V_13 = F_16 ( V_1 ) ;
if ( V_13 < 0 )
return V_13 ;
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
if ( ! V_21 -> V_27 [ V_28 - 1 ] )
return 0 ;
for ( V_6 = 0 ; V_6 < V_28 ; V_6 ++ ) {
V_22 = F_22 ( V_21 -> V_27 [ V_6 ] ) ;
V_17 = ( V_22 >> 29 ) - 1 ;
if ( V_17 < 0 || V_17 >= V_19 )
continue;
V_24 = V_1 -> V_29 [ V_17 ] ;
if ( V_22 >> 25 & 1 )
V_24 -> V_30 = 0 ;
else if ( ! V_24 -> V_30 )
continue;
V_26 = V_24 -> V_26 ;
V_25 = V_24 -> V_31 * 188 + V_24 -> V_30 * 3 ;
V_26 [ V_25 ] = V_22 >> 16 ;
V_26 [ V_25 + 1 ] = V_22 >> 8 ;
if ( V_24 -> V_30 != 62 )
V_26 [ V_25 + 2 ] = V_22 ;
if ( ++ V_24 -> V_30 >= 63 ) {
V_24 -> V_30 = 0 ;
if ( ++ V_24 -> V_31 >= 21 ) {
F_23 ( & V_24 -> V_32 , V_26 , 21 ) ;
V_24 -> V_31 = 0 ;
}
}
}
V_21 -> V_27 [ V_28 - 1 ] = 0 ;
return 1 ;
}
static int F_24 ( void * V_3 )
{
struct V_1 * V_1 ;
int V_33 ;
int V_34 ;
struct V_20 * V_21 ;
V_1 = V_3 ;
F_25 () ;
V_33 = 0 ;
V_34 = 0 ;
while ( ! F_26 () ) {
F_27 () ;
V_21 = V_1 -> V_35 [ V_33 ] . V_36 [ V_34 ] . V_21 ;
if ( ! F_21 ( V_1 , V_21 ) ) {
F_28 ( ( V_10 + 999 ) / 1000 ) ;
continue;
}
if ( ++ V_34 >= V_37 ) {
F_5 ( V_1 ) ;
V_34 = 0 ;
if ( ++ V_33 >= V_38 )
V_33 = 0 ;
}
}
return 0 ;
}
static void F_29 ( struct V_1 * V_1 , void * V_21 , T_4 V_39 )
{
F_30 ( & V_1 -> V_15 -> V_40 , V_41 , V_21 , V_39 ) ;
}
static void * F_31 ( struct V_1 * V_1 , T_4 * V_42 , T_1 * V_43 )
{
void * V_21 ;
T_4 V_39 ;
V_21 = F_32 ( & V_1 -> V_15 -> V_40 , V_41 , & V_39 ,
V_44 ) ;
if ( V_21 == NULL )
return NULL ;
F_33 ( V_39 & ( V_41 - 1 ) ) ;
F_33 ( V_39 >> V_45 >> 31 >> 1 ) ;
* V_42 = V_39 ;
* V_43 = V_39 >> V_45 ;
return V_21 ;
}
static void F_34 ( struct V_1 * V_1 , struct V_46 * V_26 )
{
F_29 ( V_1 , V_26 -> V_21 , V_26 -> V_39 ) ;
}
static int
F_35 ( struct V_1 * V_1 , struct V_46 * V_26 , T_1 * V_43 )
{
struct V_20 * V_21 ;
T_4 V_39 ;
V_21 = F_31 ( V_1 , & V_39 , V_43 ) ;
if ( V_21 == NULL )
return - V_47 ;
V_21 -> V_27 [ V_28 - 1 ] = 0 ;
V_26 -> V_21 = V_21 ;
V_26 -> V_39 = V_39 ;
return 0 ;
}
static void F_36 ( struct V_1 * V_1 , struct V_48 * V_49 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ )
F_34 ( V_1 , & V_49 -> V_36 [ V_6 ] ) ;
F_29 ( V_1 , V_49 -> V_21 , V_49 -> V_39 ) ;
}
static int
F_37 ( struct V_1 * V_1 , struct V_48 * V_49 , T_1 * V_43 )
{
struct V_50 * V_21 ;
T_4 V_39 ;
int V_6 , V_13 ;
T_1 V_51 ;
V_21 = F_31 ( V_1 , & V_39 , V_43 ) ;
if ( V_21 == NULL )
return - V_47 ;
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ ) {
V_13 = F_35 ( V_1 , & V_49 -> V_36 [ V_6 ] , & V_51 ) ;
if ( V_13 < 0 )
goto V_52;
V_21 -> V_53 [ V_6 ] = F_38 ( V_51 ) ;
}
F_5 ( V_1 ) ;
V_49 -> V_21 = V_21 ;
V_49 -> V_39 = V_39 ;
return 0 ;
V_52:
while ( V_6 -- )
F_34 ( V_1 , & V_49 -> V_36 [ V_6 ] ) ;
F_29 ( V_1 , V_21 , V_39 ) ;
return V_13 ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_48 * V_35 ;
int V_6 ;
V_35 = V_1 -> V_35 ;
F_8 ( V_1 ) ;
for ( V_6 = 0 ; V_6 < V_38 ; V_6 ++ )
F_36 ( V_1 , & V_35 [ V_6 ] ) ;
F_40 ( V_35 ) ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_48 * V_35 ;
int V_6 , V_13 ;
T_1 V_5 , V_54 ;
V_35 = F_42 ( sizeof( struct V_48 ) * V_38 ) ;
if ( V_35 == NULL )
return - V_47 ;
F_6 ( V_1 ) ;
V_6 = 0 ;
if ( V_38 ) {
V_13 = F_37 ( V_1 , & V_35 [ 0 ] , & V_5 ) ;
if ( V_13 )
goto V_52;
V_6 ++ ;
}
while ( V_6 < V_38 ) {
V_13 = F_37 ( V_1 , & V_35 [ V_6 ] , & V_54 ) ;
if ( V_13 )
goto V_52;
V_35 [ V_6 - 1 ] . V_21 -> V_55 = F_38 ( V_54 ) ;
V_6 ++ ;
}
V_35 [ V_38 - 1 ] . V_21 -> V_55 = F_38 ( V_5 ) ;
F_7 ( V_1 , V_5 ) ;
V_1 -> V_35 = V_35 ;
return 0 ;
V_52:
while ( V_6 -- )
F_36 ( V_1 , & V_35 [ V_6 ] ) ;
F_40 ( V_35 ) ;
return V_13 ;
}
static int F_43 ( struct V_56 * V_57 )
{
struct V_23 * V_24 ;
V_24 = F_44 ( V_57 -> V_32 , struct V_23 , V_32 ) ;
if ( ! V_24 -> V_58 ++ )
F_19 ( V_24 -> V_1 , V_24 -> V_17 , 1 ) ;
return 0 ;
}
static int F_45 ( struct V_56 * V_57 )
{
struct V_23 * V_24 ;
V_24 = F_44 ( V_57 -> V_32 , struct V_23 , V_32 ) ;
if ( ! -- V_24 -> V_58 )
F_19 ( V_24 -> V_1 , V_24 -> V_17 , 0 ) ;
return 0 ;
}
static void
F_46 ( struct V_1 * V_1 )
{
int V_59 ;
int V_6 ;
struct V_23 * V_24 ;
static const int V_60 [] = {
1 << 4 ,
1 << 6 | 1 << 7 ,
1 << 5 ,
1 << 6 | 1 << 8 ,
} ;
V_59 = V_1 -> V_61 | ! V_1 -> V_62 << 3 ;
F_47 ( & V_1 -> V_63 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
V_24 = V_1 -> V_29 [ V_6 ] ;
switch ( V_24 -> V_64 ) {
case V_65 :
V_59 |= 1 << 1 ;
break;
case V_66 :
V_59 |= 1 << 1 | 1 << 2 ;
break;
default:
break;
}
V_59 |= V_60 [ V_6 ] ;
}
F_1 ( V_1 , 1 , V_59 ) ;
F_48 ( & V_1 -> V_63 ) ;
}
static int F_49 ( struct V_67 * V_68 , T_5 V_64 )
{
struct V_23 * V_24 ;
V_24 = F_44 ( V_68 -> V_69 , struct V_23 , V_24 ) ;
V_24 -> V_64 = V_64 ;
F_46 ( V_24 -> V_1 ) ;
if ( V_24 -> V_70 )
return V_24 -> V_70 ( V_68 , V_64 ) ;
else
return 0 ;
}
static int F_50 ( struct V_67 * V_68 )
{
struct V_23 * V_24 ;
V_24 = F_44 ( V_68 -> V_69 , struct V_23 , V_24 ) ;
V_24 -> V_71 = 1 ;
F_46 ( V_24 -> V_1 ) ;
if ( V_24 -> V_72 )
return V_24 -> V_72 ( V_68 ) ;
else
return 0 ;
}
static int F_51 ( struct V_67 * V_68 )
{
struct V_23 * V_24 ;
V_24 = F_44 ( V_68 -> V_69 , struct V_23 , V_24 ) ;
V_24 -> V_71 = 0 ;
F_46 ( V_24 -> V_1 ) ;
F_13 ( ( V_10 + 999 ) / 1000 ) ;
if ( V_24 -> V_73 )
return V_24 -> V_73 ( V_68 ) ;
else
return 0 ;
}
static void F_52 ( struct V_23 * V_24 )
{
F_53 ( & V_24 -> V_74 ) ;
V_24 -> V_32 . V_75 . V_76 ( & V_24 -> V_32 . V_75 ) ;
F_54 ( & V_24 -> V_77 ) ;
F_55 ( & V_24 -> V_32 ) ;
F_56 ( & V_24 -> V_24 ) ;
F_57 ( ( unsigned long ) V_24 -> V_26 ) ;
F_58 ( V_24 ) ;
}
static struct V_23 *
F_59 ( struct V_1 * V_1 )
{
struct V_23 * V_24 ;
void * V_26 ;
struct V_78 * V_79 ;
struct V_80 * V_32 ;
struct V_77 * V_77 ;
int V_13 ;
V_24 = F_60 ( sizeof( struct V_23 ) , V_44 ) ;
if ( ! V_24 ) {
V_13 = - V_47 ;
goto V_52;
}
V_24 -> V_1 = V_1 ;
V_24 -> V_64 = V_81 ;
V_24 -> V_71 = 1 ;
V_26 = ( T_3 * ) F_61 ( V_44 ) ;
if ( ! V_26 ) {
V_13 = - V_47 ;
goto V_82;
}
V_24 -> V_26 = V_26 ;
V_24 -> V_30 = 0 ;
V_24 -> V_31 = 0 ;
V_79 = & V_24 -> V_24 ;
V_79 -> V_83 = V_24 ;
V_13 = F_62 ( V_79 , V_84 , V_85 ,
& V_1 -> V_15 -> V_40 , V_86 ) ;
if ( V_13 < 0 )
goto V_87;
V_32 = & V_24 -> V_32 ;
V_32 -> V_75 . V_88 = V_89 | V_90 ;
V_32 -> V_83 = V_24 ;
V_32 -> V_91 = 256 ;
V_32 -> V_92 = 256 ;
V_32 -> V_93 = F_43 ;
V_32 -> V_94 = F_45 ;
V_32 -> V_95 = NULL ;
V_13 = F_63 ( V_32 ) ;
if ( V_13 < 0 )
goto V_96;
V_77 = & V_24 -> V_77 ;
V_77 -> V_92 = 256 ;
V_77 -> V_32 = & V_32 -> V_75 ;
V_77 -> V_88 = 0 ;
V_13 = F_64 ( V_77 , V_79 ) ;
if ( V_13 < 0 )
goto V_97;
F_65 ( V_79 , & V_24 -> V_74 , & V_32 -> V_75 ) ;
return V_24 ;
V_97:
F_55 ( V_32 ) ;
V_96:
F_56 ( V_79 ) ;
V_87:
F_57 ( ( unsigned long ) V_26 ) ;
V_82:
F_58 ( V_24 ) ;
V_52:
return F_66 ( V_13 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_52 ( V_1 -> V_29 [ V_6 ] ) ;
}
static int F_68 ( struct V_1 * V_1 )
{
int V_6 ;
struct V_23 * V_24 ;
int V_13 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
V_24 = F_59 ( V_1 ) ;
if ( F_69 ( V_24 ) ) {
V_13 = F_70 ( V_24 ) ;
goto V_52;
}
V_24 -> V_17 = V_6 ;
V_1 -> V_29 [ V_6 ] = V_24 ;
}
return 0 ;
V_52:
while ( V_6 -- )
F_52 ( V_1 -> V_29 [ V_6 ] ) ;
return V_13 ;
}
static void F_71 ( struct V_23 * V_24 )
{
F_72 ( V_24 -> V_68 ) ;
}
static int F_73 ( struct V_23 * V_24 , struct V_67 * V_68 )
{
int V_13 ;
V_24 -> V_70 = V_68 -> V_98 . V_99 ;
V_24 -> V_72 = V_68 -> V_98 . V_71 ;
V_24 -> V_73 = V_68 -> V_98 . V_100 ;
V_68 -> V_98 . V_99 = F_49 ;
V_68 -> V_98 . V_71 = F_50 ;
V_68 -> V_98 . V_100 = F_51 ;
V_13 = F_74 ( & V_24 -> V_24 , V_68 ) ;
if ( V_13 < 0 )
return V_13 ;
V_24 -> V_68 = V_68 ;
return 0 ;
}
static void F_75 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_71 ( V_1 -> V_29 [ V_6 ] ) ;
}
static int F_76 ( struct V_1 * V_1 )
{
int V_6 , V_11 ;
struct V_101 * V_102 ;
const struct V_103 * V_104 , * V_105 ;
struct V_67 * V_68 [ 4 ] ;
int V_13 ;
V_6 = 0 ;
V_11 = 0 ;
V_102 = & V_1 -> V_102 ;
V_104 = V_1 -> V_15 -> V_16 == 0x211a ? V_106 : V_107 ;
do {
V_105 = & V_104 [ V_6 / 2 ] ;
V_68 [ V_6 ] = F_77 ( & V_105 -> V_108 ,
V_102 ) ;
if ( ! V_68 [ V_6 ] ) {
V_13 = - V_109 ;
goto V_52;
}
V_6 ++ ;
V_68 [ V_6 ] = F_78 ( & V_105 -> V_110 ,
V_102 ) ;
if ( ! V_68 [ V_6 ] ) {
V_13 = - V_109 ;
goto V_52;
}
V_6 ++ ;
V_13 = F_79 ( V_68 [ V_6 - 2 ] ) ;
if ( V_13 < 0 )
goto V_52;
V_13 = F_80 ( V_68 [ V_6 - 1 ] ) ;
if ( V_13 < 0 )
goto V_52;
} while ( V_6 < 4 );
do {
V_13 = F_73 ( V_1 -> V_29 [ V_11 ] , V_68 [ V_11 ] ) ;
if ( V_13 < 0 )
goto V_52;
} while ( ++ V_11 < 4 );
return 0 ;
V_52:
while ( V_6 -- > V_11 )
V_68 [ V_6 ] -> V_98 . V_111 ( V_68 [ V_6 ] ) ;
while ( V_11 -- )
F_72 ( V_68 [ V_11 ] ) ;
return V_13 ;
}
static void F_81 ( struct V_1 * V_1 , int V_39 , int V_112 , int V_113 ,
int clock , int V_3 , int V_114 )
{
F_1 ( V_1 , 4 , V_39 << 18 | V_112 << 13 | V_113 << 12 |
! clock << 11 | ! V_3 << 10 | V_114 ) ;
}
static void F_82 ( struct V_1 * V_1 , int V_39 , int * V_42 , int V_3 )
{
F_81 ( V_1 , V_39 , 1 , 0 , 0 , V_3 , V_39 + 1 ) ;
F_81 ( V_1 , V_39 + 1 , 1 , 0 , 1 , V_3 , V_39 + 2 ) ;
F_81 ( V_1 , V_39 + 2 , 1 , 0 , 0 , V_3 , V_39 + 3 ) ;
* V_42 = V_39 + 3 ;
}
static void F_83 ( struct V_1 * V_1 , int V_39 , int * V_42 )
{
F_81 ( V_1 , V_39 , 1 , 0 , 0 , 1 , V_39 + 1 ) ;
F_81 ( V_1 , V_39 + 1 , 1 , 0 , 1 , 1 , V_39 + 2 ) ;
F_81 ( V_1 , V_39 + 2 , 1 , 1 , 1 , 1 , V_39 + 3 ) ;
F_81 ( V_1 , V_39 + 3 , 1 , 0 , 0 , 1 , V_39 + 4 ) ;
* V_42 = V_39 + 4 ;
}
static void F_84 ( struct V_1 * V_1 , int V_39 , int * V_42 , int V_3 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
F_82 ( V_1 , V_39 , & V_39 , V_3 >> ( 7 - V_6 ) & 1 ) ;
F_82 ( V_1 , V_39 , & V_39 , 1 ) ;
* V_42 = V_39 ;
}
static void F_85 ( struct V_1 * V_1 , int V_39 , int * V_42 , int V_115 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ )
F_83 ( V_1 , V_39 , & V_39 ) ;
F_82 ( V_1 , V_39 , & V_39 , V_115 ) ;
* V_42 = V_39 ;
}
static void F_86 ( struct V_1 * V_1 , int V_39 , int * V_42 )
{
F_81 ( V_1 , V_39 , 1 , 0 , 1 , 1 , V_39 + 1 ) ;
F_81 ( V_1 , V_39 + 1 , 1 , 0 , 1 , 0 , V_39 + 2 ) ;
F_81 ( V_1 , V_39 + 2 , 1 , 0 , 0 , 0 , V_39 + 3 ) ;
* V_42 = V_39 + 3 ;
}
static void
F_87 ( struct V_1 * V_1 , int V_39 , int * V_42 , struct V_116 * V_117 )
{
int V_6 ;
F_86 ( V_1 , V_39 , & V_39 ) ;
F_84 ( V_1 , V_39 , & V_39 , V_117 -> V_39 << 1 ) ;
for ( V_6 = 0 ; V_6 < V_117 -> V_118 ; V_6 ++ )
F_84 ( V_1 , V_39 , & V_39 , V_117 -> V_26 [ V_6 ] ) ;
* V_42 = V_39 ;
}
static void
F_88 ( struct V_1 * V_1 , int V_39 , int * V_42 , struct V_116 * V_117 )
{
int V_6 ;
F_86 ( V_1 , V_39 , & V_39 ) ;
F_84 ( V_1 , V_39 , & V_39 , V_117 -> V_39 << 1 | 1 ) ;
for ( V_6 = 0 ; V_6 < V_117 -> V_118 ; V_6 ++ )
F_85 ( V_1 , V_39 , & V_39 , V_6 == V_117 -> V_118 - 1 ) ;
* V_42 = V_39 ;
}
static int F_89 ( struct V_1 * V_1 , int V_39 )
{
F_81 ( V_1 , V_39 , 1 , 0 , 0 , 0 , V_39 + 1 ) ;
F_81 ( V_1 , V_39 + 1 , 1 , 0 , 1 , 0 , V_39 + 2 ) ;
F_81 ( V_1 , V_39 + 2 , 1 , 0 , 1 , 1 , 0 ) ;
F_1 ( V_1 , 0 , 0x00000004 ) ;
do {
if ( F_90 ( V_119 ) )
return - V_120 ;
F_28 ( ( V_10 + 999 ) / 1000 ) ;
} while ( F_3 ( V_1 , 0 ) & 0x00000080 );
return 0 ;
}
static void F_91 ( struct V_1 * V_1 , int * V_42 )
{
int V_39 ;
V_39 = 0 ;
F_81 ( V_1 , V_39 , 0 , 0 , 1 , 1 , V_39 ) ;
V_39 = V_39 + 1 ;
if ( ! V_1 -> V_121 ) {
F_81 ( V_1 , V_39 , 1 , 0 , 1 , 1 , V_39 + 1 ) ;
F_81 ( V_1 , V_39 + 1 , 1 , 0 , 1 , 0 , V_39 + 2 ) ;
V_39 = V_39 + 2 ;
V_1 -> V_121 = 1 ;
}
* V_42 = V_39 ;
}
static int F_92 ( struct V_101 * V_24 , struct V_116 * V_122 , int V_123 )
{
struct V_1 * V_1 ;
int V_6 ;
struct V_116 * V_117 , * V_124 ;
int V_39 , V_13 ;
T_6 V_118 ;
T_1 V_125 ;
V_1 = F_93 ( V_24 ) ;
for ( V_6 = 0 ; V_6 < V_123 ; V_6 ++ ) {
V_117 = & V_122 [ V_6 ] ;
if ( V_117 -> V_126 & V_127 )
return - V_128 ;
if ( V_6 + 1 < V_123 )
V_124 = & V_122 [ V_6 + 1 ] ;
else
V_124 = NULL ;
if ( V_124 && V_124 -> V_126 & V_127 ) {
V_6 ++ ;
V_118 = V_124 -> V_118 ;
if ( V_118 > 4 )
return - V_128 ;
F_91 ( V_1 , & V_39 ) ;
F_87 ( V_1 , V_39 , & V_39 , V_117 ) ;
F_88 ( V_1 , V_39 , & V_39 , V_124 ) ;
V_13 = F_89 ( V_1 , V_39 ) ;
if ( V_13 < 0 )
return V_13 ;
V_125 = F_3 ( V_1 , 2 ) ;
while ( V_118 -- ) {
V_124 -> V_26 [ V_118 ] = V_125 ;
V_125 >>= 8 ;
}
} else {
F_91 ( V_1 , & V_39 ) ;
F_87 ( V_1 , V_39 , & V_39 , V_117 ) ;
V_13 = F_89 ( V_1 , V_39 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
return V_123 ;
}
static T_1 F_94 ( struct V_101 * V_24 )
{
return V_129 ;
}
static void F_95 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 128 ; V_6 ++ )
F_81 ( V_1 , 0 , 0 , 0 , 1 , 1 , 0 ) ;
}
static void F_96 ( struct V_1 * V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 1024 ; V_6 ++ )
F_81 ( V_1 , V_6 , 0 , 0 , 1 , 1 , 0 ) ;
}
static void T_7 F_97 ( struct V_130 * V_15 )
{
struct V_1 * V_1 ;
void T_8 * V_4 ;
V_1 = F_98 ( V_15 ) ;
V_4 = V_1 -> V_4 ;
F_99 ( V_1 -> V_131 ) ;
F_39 ( V_1 ) ;
F_75 ( V_1 ) ;
F_18 ( V_1 ) ;
V_1 -> V_61 = 0 ;
V_1 -> V_62 = 1 ;
F_46 ( V_1 ) ;
F_67 ( V_1 ) ;
F_100 ( & V_1 -> V_102 ) ;
F_101 ( V_15 , NULL ) ;
F_58 ( V_1 ) ;
F_102 ( V_15 , V_4 ) ;
F_103 ( V_15 ) ;
F_104 ( V_15 ) ;
}
static int T_9
F_105 ( struct V_130 * V_15 , const struct V_132 * V_133 )
{
int V_13 ;
void T_8 * V_4 ;
struct V_1 * V_1 ;
struct V_101 * V_102 ;
struct V_134 * V_131 ;
V_13 = F_106 ( V_15 ) ;
if ( V_13 < 0 )
goto V_52;
V_13 = F_107 ( V_15 , F_108 ( 32 ) ) ;
if ( V_13 < 0 )
goto V_135;
F_109 ( V_15 ) ;
V_13 = F_110 ( V_15 , V_84 ) ;
if ( V_13 < 0 )
goto V_135;
V_4 = F_111 ( V_15 , 0 , 0 ) ;
if ( ! V_4 ) {
V_13 = - V_8 ;
goto V_136;
}
V_1 = F_60 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_1 ) {
V_13 = - V_47 ;
goto V_137;
}
F_112 ( & V_1 -> V_63 ) ;
V_1 -> V_15 = V_15 ;
V_1 -> V_4 = V_4 ;
F_101 ( V_15 , V_1 ) ;
V_13 = F_68 ( V_1 ) ;
if ( V_13 < 0 )
goto V_82;
F_112 ( & V_1 -> V_63 ) ;
V_1 -> V_61 = 0 ;
V_1 -> V_62 = 1 ;
F_46 ( V_1 ) ;
V_102 = & V_1 -> V_102 ;
V_102 -> V_138 = & V_139 ;
V_102 -> V_140 = NULL ;
V_102 -> V_40 . V_141 = & V_15 -> V_40 ;
strcpy ( V_102 -> V_142 , V_84 ) ;
F_113 ( V_102 , V_1 ) ;
V_13 = F_114 ( V_102 ) ;
if ( V_13 < 0 )
goto V_143;
F_96 ( V_1 ) ;
F_95 ( V_1 ) ;
V_13 = F_9 ( V_1 ) ;
if ( V_13 < 0 )
goto V_144;
F_11 ( V_1 ) ;
V_13 = F_12 ( V_1 ) ;
if ( V_13 < 0 )
goto V_144;
V_13 = F_14 ( V_1 ) ;
if ( V_13 < 0 )
goto V_144;
V_13 = F_15 ( V_1 ) ;
if ( V_13 < 0 )
goto V_144;
V_13 = F_17 ( V_1 ) ;
if ( V_13 < 0 )
goto V_144;
F_20 ( V_1 ) ;
V_1 -> V_61 = 1 ;
F_46 ( V_1 ) ;
F_13 ( ( V_10 + 49 ) / 50 ) ;
V_1 -> V_62 = 0 ;
F_46 ( V_1 ) ;
F_13 ( ( V_10 + 999 ) / 1000 ) ;
V_13 = F_76 ( V_1 ) ;
if ( V_13 < 0 )
goto V_145;
V_13 = F_41 ( V_1 ) ;
if ( V_13 < 0 )
goto V_146;
V_131 = F_115 ( F_24 , V_1 , L_6 ) ;
if ( F_69 ( V_131 ) ) {
V_13 = F_70 ( V_131 ) ;
goto V_147;
}
V_1 -> V_131 = V_131 ;
return 0 ;
V_147:
F_39 ( V_1 ) ;
V_146:
F_75 ( V_1 ) ;
V_145:
F_18 ( V_1 ) ;
V_1 -> V_61 = 0 ;
V_1 -> V_62 = 1 ;
F_46 ( V_1 ) ;
V_144:
F_100 ( V_102 ) ;
V_143:
F_67 ( V_1 ) ;
V_82:
F_101 ( V_15 , NULL ) ;
F_58 ( V_1 ) ;
V_137:
F_102 ( V_15 , V_4 ) ;
V_136:
F_103 ( V_15 ) ;
V_135:
F_104 ( V_15 ) ;
V_52:
return V_13 ;
}
static int T_10 F_116 ( void )
{
return F_117 ( & V_148 ) ;
}
static void T_11 F_118 ( void )
{
F_119 ( & V_148 ) ;
}
