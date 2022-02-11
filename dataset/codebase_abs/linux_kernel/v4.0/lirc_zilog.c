static struct V_1 * F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( V_3 ) {
F_2 ( & V_2 -> V_4 ) ;
} else {
F_3 ( & V_5 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_4 ( & V_5 ) ;
}
return V_2 ;
}
static void F_5 ( struct V_6 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_4 , struct V_1 , V_4 ) ;
if ( V_2 -> V_7 . V_8 >= 0 && V_2 -> V_7 . V_8 < V_9 ) {
F_7 ( V_2 -> V_7 . V_8 ) ;
V_2 -> V_7 . V_8 = V_9 ;
}
if ( F_8 ( & V_2 -> V_10 . V_11 ) )
F_9 ( & V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , bool V_3 )
{
int V_13 ;
if ( V_3 )
return F_13 ( & V_2 -> V_4 , F_5 ) ;
F_3 ( & V_5 ) ;
V_13 = F_13 ( & V_2 -> V_4 , F_5 ) ;
F_4 ( & V_5 ) ;
return V_13 ;
}
static struct V_14 * F_14 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
F_15 ( & V_2 -> V_16 ) ;
V_15 = V_2 -> V_15 ;
if ( V_15 != NULL )
F_2 ( & V_15 -> V_4 ) ;
F_16 ( & V_2 -> V_16 ) ;
return V_15 ;
}
static void F_17 ( struct V_14 * V_15 , bool V_3 )
{
if ( ! F_18 ( V_15 -> V_17 ) ) {
F_19 ( V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
F_12 ( V_15 -> V_2 , V_3 ) ;
}
}
static void F_20 ( struct V_6 * V_4 )
{
struct V_14 * V_15 = F_6 ( V_4 , struct V_14 , V_4 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
V_2 -> V_7 . V_18 &= ~ V_19 ;
V_2 -> V_15 = NULL ;
}
static int F_21 ( struct V_14 * V_15 , bool V_3 )
{
int V_13 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_15 ( & V_2 -> V_16 ) ;
V_13 = F_13 ( & V_15 -> V_4 , F_20 ) ;
F_16 ( & V_2 -> V_16 ) ;
if ( V_13 ) {
F_17 ( V_15 , V_3 ) ;
F_11 ( V_15 ) ;
F_22 ( & V_2 -> V_10 . V_20 ) ;
}
if ( V_13 )
F_12 ( V_2 , V_3 ) ;
return V_13 ;
}
static struct V_21 * F_23 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
F_15 ( & V_2 -> V_23 ) ;
V_22 = V_2 -> V_22 ;
if ( V_22 != NULL )
F_2 ( & V_22 -> V_4 ) ;
F_16 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static void F_24 ( struct V_6 * V_4 )
{
struct V_21 * V_22 = F_6 ( V_4 , struct V_21 , V_4 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
V_2 -> V_7 . V_18 &= ~ V_24 ;
V_2 -> V_22 = NULL ;
F_11 ( V_22 ) ;
}
static int F_25 ( struct V_21 * V_22 , bool V_3 )
{
int V_13 ;
struct V_1 * V_2 = V_22 -> V_2 ;
F_15 ( & V_2 -> V_23 ) ;
V_13 = F_13 ( & V_22 -> V_4 , F_24 ) ;
F_16 ( & V_2 -> V_23 ) ;
if ( V_13 )
F_12 ( V_2 , V_3 ) ;
return V_13 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_25 ;
unsigned char V_26 [ 2 ] ;
unsigned char V_27 [ 6 ] ;
int V_28 = 0 ;
int V_29 ;
int V_30 = 0 ;
unsigned char V_31 [ 1 ] = { 0 } ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
struct V_14 * V_15 ;
struct V_21 * V_22 ;
if ( F_27 ( V_10 ) ) {
F_28 ( V_2 -> V_7 . V_33 , L_1 ) ;
return - V_34 ;
}
V_15 = F_14 ( V_2 ) ;
if ( V_15 == NULL )
return - V_35 ;
F_3 ( & V_15 -> V_36 ) ;
if ( V_15 -> V_37 == NULL ) {
F_4 ( & V_15 -> V_36 ) ;
F_21 ( V_15 , false ) ;
return - V_35 ;
}
V_22 = F_23 ( V_2 ) ;
do {
if ( F_29 () ) {
V_29 = - V_38 ;
break;
}
F_3 ( & V_2 -> V_39 ) ;
if ( F_29 () ) {
F_4 ( & V_2 -> V_39 ) ;
V_29 = - V_38 ;
break;
}
V_29 = F_30 ( V_15 -> V_37 , V_31 , 1 ) ;
if ( V_29 != 1 ) {
F_31 ( V_2 -> V_7 . V_33 , L_2 ,
V_29 ) ;
if ( V_30 >= 3 ) {
F_4 ( & V_2 -> V_39 ) ;
F_31 ( V_2 -> V_7 . V_33 ,
L_3 ) ;
break;
}
F_31 ( V_2 -> V_7 . V_33 ,
L_4 ) ;
F_32 ( V_40 ) ;
if ( F_29 () ) {
F_4 ( & V_2 -> V_39 ) ;
V_29 = - V_38 ;
break;
}
F_33 ( ( 100 * V_41 + 999 ) / 1000 ) ;
if ( V_22 != NULL )
V_22 -> V_42 = 1 ;
++ V_30 ;
F_4 ( & V_2 -> V_39 ) ;
V_29 = 0 ;
continue;
}
if ( F_29 () ) {
F_4 ( & V_2 -> V_39 ) ;
V_29 = - V_38 ;
break;
}
V_29 = F_34 ( V_15 -> V_37 , V_27 , sizeof( V_27 ) ) ;
F_4 ( & V_2 -> V_39 ) ;
if ( V_29 != sizeof( V_27 ) ) {
F_31 ( V_2 -> V_7 . V_33 ,
L_5 ,
V_29 ) ;
} else {
V_15 -> V_43 [ 0 ] = V_27 [ 3 ] ;
V_15 -> V_43 [ 1 ] = V_27 [ 4 ] ;
V_15 -> V_43 [ 2 ] = V_27 [ 5 ] ;
F_28 ( V_2 -> V_7 . V_33 ,
L_6 ,
V_15 -> V_43 [ 0 ] , V_15 -> V_43 [ 1 ] ) ;
}
if ( V_15 -> V_44 ) {
if ( V_28 && ( V_27 [ 0 ] == 0x80 ) ) {
V_29 = 0 ;
break;
} else if ( V_28 && ( V_27 [ 0 ] == 0x00 ) ) {
V_29 = - V_38 ;
break;
}
} else if ( ( V_15 -> V_43 [ 0 ] & 0x80 ) == 0 ) {
V_29 = V_28 ? 0 : - V_38 ;
break;
}
V_25 = ( ( ( T_1 ) V_15 -> V_43 [ 0 ] & 0x7f ) << 6 ) | ( V_15 -> V_43 [ 1 ] >> 2 ) ;
V_26 [ 0 ] = ( V_25 >> 8 ) & 0xff ;
V_26 [ 1 ] = V_25 & 0xff ;
F_35 ( V_10 , V_26 ) ;
++ V_28 ;
V_29 = 0 ;
} while ( ! F_27 ( V_10 ) );
F_4 ( & V_15 -> V_36 ) ;
if ( V_22 != NULL )
F_25 ( V_22 , false ) ;
F_21 ( V_15 , false ) ;
return V_29 ;
}
static int F_36 ( void * V_45 )
{
struct V_1 * V_2 = V_45 ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
F_28 ( V_2 -> V_7 . V_33 , L_7 ) ;
while ( ! F_29 () ) {
F_32 ( V_46 ) ;
if ( F_37 ( & V_2 -> V_47 ) == 0 ) {
F_33 ( V_41 / 2 ) ;
continue;
}
F_33 ( ( 260 * V_41 ) / 1000 ) ;
if ( F_29 () )
break;
if ( ! F_26 ( V_2 ) )
F_22 ( & V_10 -> V_20 ) ;
}
F_28 ( V_2 -> V_7 . V_33 , L_8 ) ;
return 0 ;
}
static int F_38 ( void * V_48 )
{
return 0 ;
}
static void F_39 ( void * V_48 )
{
}
static int F_40 ( unsigned char * * V_48 ,
unsigned char * V_49 , unsigned int * V_50 )
{
if ( * V_48 + 4 > V_49 )
return 0 ;
* V_50 = ( ( * V_48 ) [ 0 ] << 24 ) | ( ( * V_48 ) [ 1 ] << 16 ) |
( ( * V_48 ) [ 2 ] << 8 ) | ( * V_48 ) [ 3 ] ;
* V_48 += 4 ;
return 1 ;
}
static int F_41 ( unsigned char * * V_48 ,
unsigned char * V_49 , unsigned char * V_50 )
{
if ( * V_48 + 1 > V_49 )
return 0 ;
* V_50 = * ( ( * V_48 ) ++ ) ;
return 1 ;
}
static int F_42 ( unsigned char * * V_48 ,
unsigned char * V_49 , unsigned int V_51 )
{
if ( * V_48 + V_51 > V_49 )
return 0 ;
* V_48 += V_51 ;
return 1 ;
}
static int F_43 ( unsigned char * V_52 ,
unsigned int V_53 , unsigned int V_54 )
{
unsigned char * V_48 , * V_49 , * V_55 , * V_56 ;
unsigned char V_57 , V_58 , V_59 ;
unsigned int V_60 , V_61 , V_62 , V_63 ;
for ( V_60 = 0 , V_61 = V_64 -> V_65 ; V_61 ; V_61 >>= 1 ) {
V_62 = V_60 + ( V_61 >> 1 ) ;
V_48 = V_64 -> V_66 [ V_62 ] ;
if ( ! F_40 ( & V_48 , V_64 -> V_49 , & V_63 ) )
goto V_67;
if ( V_63 == V_53 )
break;
else if ( V_53 > V_63 ) {
V_60 = V_62 + 1 ;
-- V_61 ;
}
}
if ( ! V_61 )
return - V_68 ;
V_49 = V_62 < V_64 -> V_65 - 1 ?
V_64 -> V_66 [ V_62 + 1 ] : V_64 -> V_49 ;
if ( ! F_41 ( & V_48 , V_49 , & V_57 ) ||
! F_41 ( & V_48 , V_49 , & V_58 ) ||
V_58 > V_69 || V_57 == 0 )
goto V_67;
V_55 = V_48 ;
if ( ! F_42 ( & V_48 , V_49 , V_58 ) )
goto V_67;
if ( ! F_41 ( & V_48 , V_49 , & V_59 ) )
goto V_67;
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 ) {
if ( V_64 -> V_70 [ V_63 ] == - 1 ) {
if ( ! F_41 ( & V_48 , V_49 , & V_52 [ V_63 ] ) )
goto V_67;
} else {
V_52 [ V_63 ] = ( unsigned char ) V_64 -> V_70 [ V_63 ] ;
}
}
if ( V_54 == V_59 )
return 0 ;
if ( V_57 == 1 )
return - V_68 ;
V_56 = V_48 ;
if ( ! F_42 ( & V_48 , V_49 , ( V_57 - 1 ) * ( V_58 + 1 ) ) )
goto V_67;
for ( V_60 = 0 , V_61 = V_57 - 1 ; V_61 ; V_61 >>= 1 ) {
unsigned char * V_71 ;
V_62 = V_60 + ( V_61 >> 1 ) ;
V_71 = V_56 + ( V_58 + 1 ) * V_62 ;
if ( * V_71 == V_54 ) {
++ V_71 ;
for ( V_63 = 0 ; V_63 < V_58 ; ++ V_63 ) {
unsigned char V_50 ;
if ( ! F_41 ( & V_71 , V_49 , & V_50 ) ||
V_55 [ V_63 ] >= V_69 )
goto V_67;
V_52 [ V_55 [ V_63 ] ] = V_50 ;
}
return 0 ;
} else if ( V_54 > * V_71 ) {
V_60 = V_62 + 1 ;
-- V_61 ;
}
}
return - V_68 ;
V_67:
F_44 ( L_9 ) ;
return - V_72 ;
}
static int F_45 ( struct V_21 * V_22 , unsigned char * V_73 )
{
int V_63 , V_74 , V_29 ;
unsigned char V_52 [ 5 ] ;
for ( V_63 = 0 ; V_63 < V_69 ; ) {
int V_75 = V_69 - V_63 ;
if ( V_75 > 4 )
V_75 = 4 ;
V_52 [ 0 ] = ( unsigned char ) ( V_63 + 1 ) ;
for ( V_74 = 0 ; V_74 < V_75 ; ++ V_74 )
V_52 [ 1 + V_74 ] = V_73 [ V_63 + V_74 ] ;
F_28 ( V_22 -> V_2 -> V_7 . V_33 , L_10 , 5 , V_52 ) ;
V_29 = F_30 ( V_22 -> V_37 , V_52 , V_75 + 1 ) ;
if ( V_29 != V_75 + 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
V_63 += V_75 ;
}
return 0 ;
}
static int F_46 ( struct V_21 * V_22 )
{
int V_29 , V_63 ;
unsigned char V_52 [ 4 ] ;
V_29 = F_45 ( V_22 , V_64 -> V_76 ) ;
if ( V_29 != 0 )
return V_29 ;
V_52 [ 0 ] = 0x00 ;
V_52 [ 1 ] = 0x20 ;
V_29 = F_30 ( V_22 -> V_37 , V_52 , 2 ) ;
if ( V_29 != 2 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
for ( V_63 = 0 ; V_63 < 10 ; V_63 ++ ) {
V_29 = F_30 ( V_22 -> V_37 , V_52 , 1 ) ;
if ( V_29 == 1 )
break;
F_47 ( 100 ) ;
}
if ( V_29 != 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
V_29 = F_34 ( V_22 -> V_37 , V_52 , 4 ) ;
if ( V_29 != 4 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_11 , V_29 ) ;
return 0 ;
}
if ( ( V_52 [ 0 ] != 0x80 ) && ( V_52 [ 0 ] != 0xa0 ) ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_12 ,
V_52 [ 0 ] ) ;
return 0 ;
}
F_48 ( V_22 -> V_2 -> V_7 . V_33 ,
L_13 ,
V_52 [ 1 ] , V_52 [ 2 ] , V_52 [ 3 ] ) ;
return 0 ;
}
static void F_49 ( void )
{
if ( V_64 ) {
F_50 ( V_64 -> V_66 ) ;
F_50 ( V_64 -> V_77 ) ;
F_50 ( V_64 ) ;
V_64 = NULL ;
F_51 ( L_14 ) ;
}
}
static void F_52 ( void )
{
F_3 ( & V_78 ) ;
F_49 () ;
F_4 ( & V_78 ) ;
}
static int F_53 ( struct V_21 * V_22 )
{
int V_29 ;
unsigned int V_63 ;
unsigned char * V_48 , V_79 , V_80 ;
const struct V_81 * V_82 ;
F_3 ( & V_78 ) ;
if ( V_64 ) {
V_29 = 0 ;
goto V_83;
}
V_29 = F_54 ( & V_82 , L_15 , V_22 -> V_2 -> V_7 . V_33 ) ;
if ( V_29 != 0 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_16 ,
V_29 ) ;
V_29 = V_29 < 0 ? V_29 : - V_72 ;
goto V_83;
}
F_28 ( V_22 -> V_2 -> V_7 . V_33 , L_17 , V_82 -> V_84 ) ;
V_64 = F_55 ( sizeof( * V_64 ) ) ;
if ( V_64 == NULL ) {
F_56 ( V_82 ) ;
V_29 = - V_85 ;
goto V_83;
}
V_64 -> V_66 = NULL ;
V_64 -> V_77 = F_55 ( V_82 -> V_84 ) ;
if ( V_64 -> V_77 == NULL ) {
F_56 ( V_82 ) ;
F_50 ( V_64 ) ;
V_29 = - V_85 ;
goto V_83;
}
memcpy ( V_64 -> V_77 , V_82 -> V_48 , V_82 -> V_84 ) ;
V_64 -> V_49 = V_64 -> V_77 + V_82 -> V_84 ;
F_56 ( V_82 ) ; V_82 = NULL ;
V_48 = V_64 -> V_77 ;
if ( ! F_41 ( & V_48 , V_64 -> V_49 , & V_79 ) )
goto V_67;
if ( V_79 != 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_18 ,
V_79 ) ;
F_49 () ;
V_29 = - V_72 ;
goto V_83;
}
V_64 -> V_76 = V_48 ;
if ( ! F_42 ( & V_48 , V_64 -> V_49 , V_69 ) )
goto V_67;
if ( ! F_40 ( & V_48 , V_64 -> V_49 ,
& V_64 -> V_65 ) )
goto V_67;
F_28 ( V_22 -> V_2 -> V_7 . V_33 , L_19 ,
V_64 -> V_65 ) ;
V_64 -> V_66 = F_55 (
V_64 -> V_65 * sizeof( char * ) ) ;
if ( V_64 -> V_66 == NULL ) {
F_49 () ;
V_29 = - V_85 ;
goto V_83;
}
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 )
V_64 -> V_70 [ V_63 ] = - 1 ;
if ( ! F_41 ( & V_48 , V_64 -> V_49 , & V_80 ) ||
V_80 > V_69 )
goto V_67;
for ( V_63 = 0 ; V_63 < V_80 ; ++ V_63 ) {
unsigned char V_62 , V_50 ;
if ( ! F_41 ( & V_48 , V_64 -> V_49 , & V_62 ) ||
! F_41 ( & V_48 , V_64 -> V_49 , & V_50 ) ||
V_62 >= V_69 )
goto V_67;
V_64 -> V_70 [ V_62 ] = ( int ) V_50 ;
}
for ( V_63 = 0 ; V_63 < V_64 -> V_65 ; ++ V_63 ) {
unsigned int V_59 ;
unsigned char V_57 ;
unsigned char V_58 ;
V_64 -> V_66 [ V_63 ] = V_48 ;
if ( ! F_40 ( & V_48 , V_64 -> V_49 , & V_59 ) ||
! F_41 ( & V_48 , V_64 -> V_49 , & V_57 ) ||
! F_41 ( & V_48 , V_64 -> V_49 , & V_58 ) ||
V_58 > V_69 || V_57 == 0 )
goto V_67;
if ( ! F_42 ( & V_48 , V_64 -> V_49 , V_58 ) )
goto V_67;
if ( ! F_42 ( & V_48 , V_64 -> V_49 ,
1 + V_69 - V_80 ) )
goto V_67;
if ( ! F_42 ( & V_48 , V_64 -> V_49 ,
( V_58 + 1 ) * ( V_57 - 1 ) ) )
goto V_67;
}
V_29 = 0 ;
goto V_83;
V_67:
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_9 ) ;
F_49 () ;
V_29 = - V_72 ;
V_83:
F_4 ( & V_78 ) ;
return V_29 ;
}
static T_2 F_57 ( struct V_86 * V_87 , char T_3 * V_88 , T_4 V_89 ,
T_5 * V_90 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
struct V_14 * V_15 ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
int V_29 = 0 , V_92 = 0 , V_93 = 0 ;
unsigned int V_94 ;
F_58 ( V_95 , V_96 ) ;
F_28 ( V_2 -> V_7 . V_33 , L_20 ) ;
if ( V_89 % V_10 -> V_97 ) {
F_28 ( V_2 -> V_7 . V_33 , L_21 ) ;
return - V_98 ;
}
V_15 = F_14 ( V_2 ) ;
if ( V_15 == NULL )
return - V_35 ;
F_59 ( & V_10 -> V_20 , & V_95 ) ;
F_32 ( V_46 ) ;
while ( V_92 < V_89 && V_29 == 0 ) {
if ( F_60 ( V_10 ) ) {
if ( V_92 )
break;
if ( V_87 -> V_99 & V_100 ) {
V_29 = - V_101 ;
break;
}
if ( F_61 ( V_96 ) ) {
V_29 = - V_102 ;
break;
}
F_62 () ;
F_32 ( V_46 ) ;
} else {
unsigned char V_52 [ V_103 ] ;
if ( V_10 -> V_97 > sizeof( V_52 ) ) {
F_31 ( V_2 -> V_7 . V_33 ,
L_22 ,
V_10 -> V_97 ) ;
V_29 = - V_98 ;
break;
}
V_94 = F_63 ( V_10 , V_52 ) ;
if ( V_94 == V_10 -> V_97 ) {
V_29 = F_64 ( V_88 + V_92 , V_52 ,
V_10 -> V_97 ) ;
V_92 += V_10 -> V_97 ;
} else {
V_93 ++ ;
}
if ( V_93 >= 5 ) {
F_31 ( V_2 -> V_7 . V_33 , L_23 ) ;
V_29 = - V_104 ;
}
}
}
F_65 ( & V_10 -> V_20 , & V_95 ) ;
F_21 ( V_15 , false ) ;
F_32 ( V_105 ) ;
F_28 ( V_2 -> V_7 . V_33 , L_24 , V_29 ,
V_29 ? L_25 : L_26 ) ;
return V_29 ? V_29 : V_92 ;
}
static int F_66 ( struct V_21 * V_22 , unsigned int V_25 , unsigned int V_54 )
{
unsigned char V_73 [ V_69 ] ;
unsigned char V_52 [ 2 ] ;
int V_63 , V_29 ;
V_29 = F_43 ( V_73 , V_25 , V_54 ) ;
if ( V_29 == - V_68 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_27 ,
V_25 , V_54 ) ;
return V_29 ;
} else if ( V_29 != 0 )
return V_29 ;
V_29 = F_45 ( V_22 , V_73 ) ;
if ( V_29 != 0 )
return V_29 ;
V_52 [ 0 ] = 0x00 ;
V_52 [ 1 ] = 0x40 ;
V_29 = F_30 ( V_22 -> V_37 , V_52 , 2 ) ;
if ( V_29 != 2 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
for ( V_63 = 0 ; V_63 < 10 ; V_63 ++ ) {
V_29 = F_30 ( V_22 -> V_37 , V_52 , 1 ) ;
if ( V_29 == 1 )
break;
F_47 ( 100 ) ;
}
if ( V_29 != 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
V_29 = F_34 ( V_22 -> V_37 , V_52 , 1 ) ;
if ( V_29 != 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_11 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
if ( V_52 [ 0 ] != 0xA0 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_28 ,
V_52 [ 0 ] ) ;
return - V_72 ;
}
V_52 [ 0 ] = 0x00 ;
V_52 [ 1 ] = 0x80 ;
V_29 = F_30 ( V_22 -> V_37 , V_52 , 2 ) ;
if ( V_29 != 2 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
if ( ! V_22 -> V_106 ) {
F_28 ( V_22 -> V_2 -> V_7 . V_33 , L_29 , V_25 , V_54 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < 20 ; ++ V_63 ) {
F_32 ( V_40 ) ;
F_33 ( ( 50 * V_41 + 999 ) / 1000 ) ;
V_29 = F_30 ( V_22 -> V_37 , V_52 , 1 ) ;
if ( V_29 == 1 )
break;
F_28 ( V_22 -> V_2 -> V_7 . V_33 ,
L_30 ,
V_29 , V_63 + 1 ) ;
}
if ( V_29 != 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_31 ,
V_29 ) ;
return V_29 < 0 ? V_29 : - V_72 ;
}
V_63 = F_34 ( V_22 -> V_37 , V_52 , 1 ) ;
if ( V_63 != 1 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_11 , V_29 ) ;
return - V_72 ;
}
if ( V_52 [ 0 ] != 0x80 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 , L_32 ,
V_52 [ 0 ] ) ;
return - V_72 ;
}
F_28 ( V_22 -> V_2 -> V_7 . V_33 , L_29 , V_25 , V_54 ) ;
return 0 ;
}
static T_2 F_67 ( struct V_86 * V_87 , const char T_3 * V_52 , T_4 V_89 ,
T_5 * V_90 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
struct V_21 * V_22 ;
T_4 V_63 ;
int V_30 = 0 ;
if ( V_89 % sizeof( int ) )
return - V_98 ;
V_22 = F_23 ( V_2 ) ;
if ( V_22 == NULL )
return - V_35 ;
F_3 ( & V_22 -> V_36 ) ;
if ( V_22 -> V_37 == NULL ) {
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
return - V_35 ;
}
F_3 ( & V_2 -> V_39 ) ;
for ( V_63 = 0 ; V_63 < V_89 ; ) {
int V_29 = 0 ;
int V_107 ;
if ( F_68 ( & V_107 , V_52 + V_63 , sizeof( V_107 ) ) ) {
F_4 ( & V_2 -> V_39 ) ;
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
return - V_72 ;
}
if ( V_22 -> V_42 == 1 ) {
V_29 = F_53 ( V_22 ) ;
if ( V_29 != 0 ) {
F_4 ( & V_2 -> V_39 ) ;
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
if ( V_29 != - V_85 )
V_29 = - V_104 ;
return V_29 ;
}
V_29 = F_46 ( V_22 ) ;
if ( V_29 == 0 )
V_22 -> V_42 = 0 ;
}
if ( V_29 == 0 ) {
V_29 = F_66 ( V_22 , ( unsigned ) V_107 >> 16 ,
( unsigned ) V_107 & 0xFFFF ) ;
if ( V_29 == - V_68 ) {
F_4 ( & V_2 -> V_39 ) ;
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
return V_29 ;
}
}
if ( V_29 != 0 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_33 ) ;
if ( V_30 >= 3 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_34 ) ;
F_4 ( & V_2 -> V_39 ) ;
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
return V_29 ;
}
F_32 ( V_40 ) ;
F_33 ( ( 100 * V_41 + 999 ) / 1000 ) ;
V_22 -> V_42 = 1 ;
++ V_30 ;
} else
V_63 += sizeof( int ) ;
}
F_4 ( & V_2 -> V_39 ) ;
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
return V_89 ;
}
static unsigned int F_69 ( struct V_86 * V_87 , T_6 * V_95 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
struct V_14 * V_15 ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
unsigned int V_29 ;
F_28 ( V_2 -> V_7 . V_33 , L_35 ) ;
V_15 = F_14 ( V_2 ) ;
if ( V_15 == NULL ) {
F_28 ( V_2 -> V_7 . V_33 , L_36 ) ;
return V_108 ;
}
F_70 ( V_87 , & V_10 -> V_20 , V_95 ) ;
V_29 = F_60 ( V_10 ) ? 0 : ( V_109 | V_110 ) ;
F_28 ( V_2 -> V_7 . V_33 , L_37 ,
V_29 ? L_38 : L_39 ) ;
return V_29 ;
}
static long F_71 ( struct V_86 * V_87 , unsigned int V_111 , unsigned long V_45 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
unsigned long T_3 * V_112 = ( unsigned long T_3 * ) V_45 ;
int V_113 ;
unsigned long V_114 , V_18 ;
V_18 = V_2 -> V_7 . V_18 ;
switch ( V_111 ) {
case V_115 :
V_113 = F_72 ( 13UL , V_112 ) ;
break;
case V_116 :
V_113 = F_72 ( V_18 , V_112 ) ;
break;
case V_117 :
if ( ! ( V_18 & V_118 ) )
return - V_119 ;
V_113 = F_72 ( F_73
( V_18 & V_118 ) ,
V_112 ) ;
break;
case V_120 :
if ( ! ( V_18 & V_118 ) )
return - V_119 ;
V_113 = F_74 ( V_114 , V_112 ) ;
if ( ! V_113 && ! ( F_75 ( V_114 ) & V_18 ) )
V_113 = - V_98 ;
break;
case V_121 :
if ( ! ( V_18 & V_122 ) )
return - V_119 ;
V_113 = F_72 ( V_123 , V_112 ) ;
break;
case V_124 :
if ( ! ( V_18 & V_122 ) )
return - V_119 ;
V_113 = F_74 ( V_114 , V_112 ) ;
if ( ! V_113 && V_114 != V_123 )
return - V_98 ;
break;
default:
return - V_98 ;
}
return V_113 ;
}
static struct V_1 * F_76 ( unsigned int V_8 )
{
struct V_1 * V_2 ;
struct V_1 * V_29 = NULL ;
F_3 ( & V_5 ) ;
if ( ! F_77 ( & V_125 ) ) {
F_78 (ir, &ir_devices_list, list) {
if ( V_2 -> V_7 . V_8 == V_8 ) {
V_29 = F_1 ( V_2 , true ) ;
break;
}
}
}
F_4 ( & V_5 ) ;
return V_29 ;
}
static int F_79 ( struct V_126 * V_127 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned int V_8 = F_80 ( V_127 -> V_128 ) ;
V_2 = F_76 ( V_8 ) ;
if ( V_2 == NULL )
return - V_129 ;
F_81 ( & V_2 -> V_47 ) ;
V_87 -> V_91 = V_2 ;
F_82 ( V_127 , V_87 ) ;
return 0 ;
}
static int F_83 ( struct V_126 * V_127 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
if ( V_2 == NULL ) {
F_31 ( V_2 -> V_7 . V_33 ,
L_40 ) ;
return - V_129 ;
}
F_84 ( & V_2 -> V_47 ) ;
F_12 ( V_2 , false ) ;
return 0 ;
}
static int F_85 ( struct V_130 * V_131 )
{
if ( strncmp ( L_41 , V_131 -> V_132 , 8 ) == 0 ) {
struct V_21 * V_22 = F_86 ( V_131 ) ;
if ( V_22 != NULL ) {
F_3 ( & V_22 -> V_36 ) ;
V_22 -> V_37 = NULL ;
F_4 ( & V_22 -> V_36 ) ;
F_25 ( V_22 , false ) ;
}
} else if ( strncmp ( L_42 , V_131 -> V_132 , 8 ) == 0 ) {
struct V_14 * V_15 = F_86 ( V_131 ) ;
if ( V_15 != NULL ) {
F_3 ( & V_15 -> V_36 ) ;
V_15 -> V_37 = NULL ;
F_4 ( & V_15 -> V_36 ) ;
F_21 ( V_15 , false ) ;
}
}
return 0 ;
}
static struct V_1 * F_87 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
if ( F_77 ( & V_125 ) )
return NULL ;
F_78 (ir, &ir_devices_list, list)
if ( V_2 -> V_134 == V_134 ) {
F_1 ( V_2 , true ) ;
return V_2 ;
}
return NULL ;
}
static int F_88 ( struct V_130 * V_131 , const struct V_135 * V_59 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_14 * V_15 ;
struct V_133 * V_136 = V_131 -> V_134 ;
int V_29 ;
bool V_137 = false ;
F_28 ( & V_131 -> V_33 , L_43 ,
V_138 , V_59 -> V_132 , V_136 -> V_139 , V_136 -> V_132 , V_131 -> V_140 ) ;
if ( V_59 -> V_141 & V_142 )
V_137 = true ;
else if ( V_143 )
return - V_35 ;
F_89 ( L_44 ,
V_137 ? L_45 : L_46 , V_136 -> V_132 , V_136 -> V_139 ) ;
F_3 ( & V_5 ) ;
V_2 = F_87 ( V_136 ) ;
if ( V_2 == NULL ) {
V_2 = F_90 ( sizeof( struct V_1 ) , V_144 ) ;
if ( V_2 == NULL ) {
V_29 = - V_85 ;
goto V_145;
}
F_91 ( & V_2 -> V_4 ) ;
F_92 ( & V_2 -> V_12 ) ;
F_93 ( & V_2 -> V_12 , & V_125 ) ;
V_2 -> V_134 = V_136 ;
F_94 ( & V_2 -> V_39 ) ;
F_95 ( & V_2 -> V_47 , 0 ) ;
F_96 ( & V_2 -> V_23 ) ;
F_96 ( & V_2 -> V_16 ) ;
memcpy ( & V_2 -> V_7 , & V_146 , sizeof( struct V_147 ) ) ;
V_2 -> V_7 . V_10 = & V_2 -> V_10 ;
V_2 -> V_7 . V_33 = & V_136 -> V_33 ;
V_29 = F_97 ( V_2 -> V_7 . V_10 ,
V_2 -> V_7 . V_97 , V_2 -> V_7 . V_148 ) ;
if ( V_29 )
goto V_149;
}
if ( V_137 ) {
V_15 = F_14 ( V_2 ) ;
V_22 = F_90 ( sizeof( struct V_21 ) , V_144 ) ;
if ( V_22 == NULL ) {
V_29 = - V_85 ;
goto V_150;
}
F_91 ( & V_22 -> V_4 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_7 . V_18 |= V_24 ;
F_94 ( & V_22 -> V_36 ) ;
V_22 -> V_37 = V_131 ;
V_22 -> V_42 = 1 ;
V_22 -> V_106 =
( V_59 -> V_141 & V_151 ) ? false : true ;
V_22 -> V_2 = F_1 ( V_2 , true ) ;
F_98 ( V_131 , F_23 ( V_2 ) ) ;
F_53 ( V_22 ) ;
if ( V_15 == NULL && ! V_143 ) {
F_99 ( V_22 -> V_2 -> V_7 . V_33 ,
L_47 ,
V_136 -> V_132 , V_136 -> V_139 ) ;
goto V_152;
}
} else {
V_22 = F_23 ( V_2 ) ;
V_15 = F_90 ( sizeof( struct V_14 ) , V_144 ) ;
if ( V_15 == NULL ) {
V_29 = - V_85 ;
goto V_150;
}
F_91 ( & V_15 -> V_4 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_7 . V_18 |= V_19 ;
F_94 ( & V_15 -> V_36 ) ;
V_15 -> V_37 = V_131 ;
V_15 -> V_44 =
( V_59 -> V_141 & V_151 ) ? true : false ;
V_15 -> V_2 = F_1 ( V_2 , true ) ;
F_98 ( V_131 , F_14 ( V_2 ) ) ;
V_15 -> V_17 = F_100 ( F_36 , F_1 ( V_2 , true ) ,
L_48 , V_136 -> V_139 ) ;
if ( F_101 ( V_15 -> V_17 ) ) {
V_29 = F_102 ( V_15 -> V_17 ) ;
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_49 ,
V_138 ) ;
F_12 ( V_2 , true ) ;
F_98 ( V_131 , NULL ) ;
F_21 ( V_15 , true ) ;
V_2 -> V_7 . V_18 &= ~ V_19 ;
goto V_150;
}
if ( V_22 == NULL ) {
F_89 ( L_50 ,
V_136 -> V_132 , V_136 -> V_139 ) ;
goto V_152;
}
}
V_2 -> V_7 . V_8 = V_8 ;
V_2 -> V_7 . V_8 = F_103 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_7 . V_8 < 0 || V_2 -> V_7 . V_8 >= V_9 ) {
F_31 ( V_22 -> V_2 -> V_7 . V_33 ,
L_51 ,
V_138 , V_9 - 1 , V_2 -> V_7 . V_8 ) ;
V_29 = - V_153 ;
goto V_150;
}
F_99 ( V_2 -> V_7 . V_33 ,
L_52 ,
V_136 -> V_132 , V_136 -> V_139 , V_2 -> V_7 . V_8 ) ;
V_152:
if ( V_15 != NULL )
F_21 ( V_15 , true ) ;
if ( V_22 != NULL )
F_25 ( V_22 , true ) ;
F_12 ( V_2 , true ) ;
F_99 ( V_2 -> V_7 . V_33 ,
L_53 ,
V_137 ? L_45 : L_46 , V_136 -> V_132 , V_136 -> V_139 ) ;
F_4 ( & V_5 ) ;
return 0 ;
V_150:
if ( V_15 != NULL )
F_21 ( V_15 , true ) ;
if ( V_22 != NULL )
F_25 ( V_22 , true ) ;
V_149:
F_12 ( V_2 , true ) ;
V_145:
F_31 ( & V_131 -> V_33 ,
L_54 ,
V_138 , V_137 ? L_45 : L_46 , V_136 -> V_132 , V_136 -> V_139 , V_29 ) ;
F_4 ( & V_5 ) ;
return V_29 ;
}
static int T_7 F_104 ( void )
{
int V_29 ;
F_105 ( L_55 ) ;
F_94 ( & V_78 ) ;
F_106 ( L_56 ) ;
V_29 = F_107 ( & V_154 ) ;
if ( V_29 )
F_44 ( L_57 ) ;
else
F_105 ( L_58 ) ;
return V_29 ;
}
static void T_8 F_108 ( void )
{
F_109 ( & V_154 ) ;
F_52 () ;
F_105 ( L_59 ) ;
}
