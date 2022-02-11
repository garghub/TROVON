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
if ( V_2 -> V_10 . V_11 )
F_8 ( & V_2 -> V_10 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 , bool V_3 )
{
int V_13 ;
if ( V_3 )
return F_12 ( & V_2 -> V_4 , F_5 ) ;
F_3 ( & V_5 ) ;
V_13 = F_12 ( & V_2 -> V_4 , F_5 ) ;
F_4 ( & V_5 ) ;
return V_13 ;
}
static struct V_14 * F_13 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
F_14 ( & V_2 -> V_16 ) ;
V_15 = V_2 -> V_15 ;
if ( V_15 != NULL )
F_2 ( & V_15 -> V_4 ) ;
F_15 ( & V_2 -> V_16 ) ;
return V_15 ;
}
static void F_16 ( struct V_14 * V_15 , bool V_3 )
{
if ( ! F_17 ( V_15 -> V_17 ) ) {
F_18 ( V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
F_11 ( V_15 -> V_2 , V_3 ) ;
}
}
static void F_19 ( struct V_6 * V_4 )
{
struct V_14 * V_15 = F_6 ( V_4 , struct V_14 , V_4 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
V_2 -> V_7 . V_18 &= ~ V_19 ;
V_2 -> V_15 = NULL ;
return;
}
static int F_20 ( struct V_14 * V_15 , bool V_3 )
{
int V_13 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_14 ( & V_2 -> V_16 ) ;
V_13 = F_12 ( & V_15 -> V_4 , F_19 ) ;
F_15 ( & V_2 -> V_16 ) ;
if ( V_13 ) {
F_16 ( V_15 , V_3 ) ;
F_10 ( V_15 ) ;
F_21 ( & V_2 -> V_10 . V_20 ) ;
}
if ( V_13 )
F_11 ( V_2 , V_3 ) ;
return V_13 ;
}
static struct V_21 * F_22 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
F_14 ( & V_2 -> V_23 ) ;
V_22 = V_2 -> V_22 ;
if ( V_22 != NULL )
F_2 ( & V_22 -> V_4 ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_22 ;
}
static void F_23 ( struct V_6 * V_4 )
{
struct V_21 * V_22 = F_6 ( V_4 , struct V_21 , V_4 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
V_2 -> V_7 . V_18 &= ~ V_24 ;
V_2 -> V_22 = NULL ;
F_10 ( V_22 ) ;
}
static int F_24 ( struct V_21 * V_22 , bool V_3 )
{
int V_13 ;
struct V_1 * V_2 = V_22 -> V_2 ;
F_14 ( & V_2 -> V_23 ) ;
V_13 = F_12 ( & V_22 -> V_4 , F_23 ) ;
F_15 ( & V_2 -> V_23 ) ;
if ( V_13 )
F_11 ( V_2 , V_3 ) ;
return V_13 ;
}
static int F_25 ( struct V_1 * V_2 )
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
if ( F_26 ( V_10 ) ) {
F_27 ( L_1 ) ;
return - V_33 ;
}
V_15 = F_13 ( V_2 ) ;
if ( V_15 == NULL )
return - V_34 ;
F_3 ( & V_15 -> V_35 ) ;
if ( V_15 -> V_36 == NULL ) {
F_4 ( & V_15 -> V_35 ) ;
F_20 ( V_15 , false ) ;
return - V_34 ;
}
V_22 = F_22 ( V_2 ) ;
do {
if ( F_28 () ) {
V_29 = - V_37 ;
break;
}
F_3 ( & V_2 -> V_38 ) ;
if ( F_28 () ) {
F_4 ( & V_2 -> V_38 ) ;
V_29 = - V_37 ;
break;
}
V_29 = F_29 ( V_15 -> V_36 , V_31 , 1 ) ;
if ( V_29 != 1 ) {
F_30 ( L_2 , V_29 ) ;
if ( V_30 >= 3 ) {
F_4 ( & V_2 -> V_38 ) ;
F_30 ( L_3
L_4 ) ;
break;
}
F_30 ( L_5
L_6 ) ;
F_31 ( V_39 ) ;
if ( F_28 () ) {
F_4 ( & V_2 -> V_38 ) ;
V_29 = - V_37 ;
break;
}
F_32 ( ( 100 * V_40 + 999 ) / 1000 ) ;
if ( V_22 != NULL )
V_22 -> V_41 = 1 ;
++ V_30 ;
F_4 ( & V_2 -> V_38 ) ;
V_29 = 0 ;
continue;
}
if ( F_28 () ) {
F_4 ( & V_2 -> V_38 ) ;
V_29 = - V_37 ;
break;
}
V_29 = F_33 ( V_15 -> V_36 , V_27 , sizeof( V_27 ) ) ;
F_4 ( & V_2 -> V_38 ) ;
if ( V_29 != sizeof( V_27 ) ) {
F_30 ( L_7
L_8 , V_29 ) ;
} else {
V_15 -> V_42 [ 0 ] = V_27 [ 3 ] ;
V_15 -> V_42 [ 1 ] = V_27 [ 4 ] ;
V_15 -> V_42 [ 2 ] = V_27 [ 5 ] ;
F_27 ( L_9 , V_15 -> V_42 [ 0 ] , V_15 -> V_42 [ 1 ] ) ;
}
if ( V_15 -> V_43 ) {
if ( V_28 && ( V_27 [ 0 ] == 0x80 ) ) {
V_29 = 0 ;
break;
} else if ( V_28 && ( V_27 [ 0 ] == 0x00 ) ) {
V_29 = - V_37 ;
break;
}
} else if ( ( V_15 -> V_42 [ 0 ] & 0x80 ) == 0 ) {
V_29 = V_28 ? 0 : - V_37 ;
break;
}
V_25 = ( ( ( T_1 ) V_15 -> V_42 [ 0 ] & 0x7f ) << 6 ) | ( V_15 -> V_42 [ 1 ] >> 2 ) ;
V_26 [ 0 ] = ( V_25 >> 8 ) & 0xff ;
V_26 [ 1 ] = V_25 & 0xff ;
F_34 ( V_10 , V_26 ) ;
++ V_28 ;
V_29 = 0 ;
} while ( ! F_26 ( V_10 ) );
F_4 ( & V_15 -> V_35 ) ;
if ( V_22 != NULL )
F_24 ( V_22 , false ) ;
F_20 ( V_15 , false ) ;
return V_29 ;
}
static int F_35 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
F_27 ( L_10 ) ;
while ( ! F_28 () ) {
F_31 ( V_45 ) ;
if ( F_36 ( & V_2 -> V_46 ) == 0 ) {
F_32 ( V_40 / 2 ) ;
continue;
}
F_32 ( ( 260 * V_40 ) / 1000 ) ;
if ( F_28 () )
break;
if ( ! F_25 ( V_2 ) )
F_21 ( & V_10 -> V_20 ) ;
}
F_27 ( L_11 ) ;
return 0 ;
}
static int F_37 ( void * V_47 )
{
return 0 ;
}
static void F_38 ( void * V_47 )
{
return;
}
static int F_39 ( unsigned char * * V_47 ,
unsigned char * V_48 , unsigned int * V_49 )
{
if ( * V_47 + 4 > V_48 )
return 0 ;
* V_49 = ( ( * V_47 ) [ 0 ] << 24 ) | ( ( * V_47 ) [ 1 ] << 16 ) |
( ( * V_47 ) [ 2 ] << 8 ) | ( * V_47 ) [ 3 ] ;
* V_47 += 4 ;
return 1 ;
}
static int F_40 ( unsigned char * * V_47 ,
unsigned char * V_48 , unsigned char * V_49 )
{
if ( * V_47 + 1 > V_48 )
return 0 ;
* V_49 = * ( ( * V_47 ) ++ ) ;
return 1 ;
}
static int F_41 ( unsigned char * * V_47 ,
unsigned char * V_48 , unsigned int V_50 )
{
if ( * V_47 + V_50 > V_48 )
return 0 ;
* V_47 += V_50 ;
return 1 ;
}
static int F_42 ( unsigned char * V_51 ,
unsigned int V_52 , unsigned int V_53 )
{
unsigned char * V_47 , * V_48 , * V_54 , * V_55 ;
unsigned char V_56 , V_57 , V_58 ;
unsigned int V_59 , V_60 , V_61 , V_62 ;
for ( V_59 = 0 , V_60 = V_63 -> V_64 ; V_60 ; V_60 >>= 1 ) {
V_61 = V_59 + ( V_60 >> 1 ) ;
V_47 = V_63 -> V_65 [ V_61 ] ;
if ( ! F_39 ( & V_47 , V_63 -> V_48 , & V_62 ) )
goto V_66;
if ( V_62 == V_52 )
break;
else if ( V_52 > V_62 ) {
V_59 = V_61 + 1 ;
-- V_60 ;
}
}
if ( ! V_60 )
return - V_67 ;
V_48 = V_61 < V_63 -> V_64 - 1 ?
V_63 -> V_65 [ V_61 + 1 ] : V_63 -> V_48 ;
if ( ! F_40 ( & V_47 , V_48 , & V_56 ) ||
! F_40 ( & V_47 , V_48 , & V_57 ) ||
V_57 > V_68 || V_56 == 0 )
goto V_66;
V_54 = V_47 ;
if ( ! F_41 ( & V_47 , V_48 , V_57 ) )
goto V_66;
if ( ! F_40 ( & V_47 , V_48 , & V_58 ) )
goto V_66;
for ( V_62 = 0 ; V_62 < V_68 ; ++ V_62 ) {
if ( V_63 -> V_69 [ V_62 ] == - 1 ) {
if ( ! F_40 ( & V_47 , V_48 , & V_51 [ V_62 ] ) )
goto V_66;
} else {
V_51 [ V_62 ] = ( unsigned char ) V_63 -> V_69 [ V_62 ] ;
}
}
if ( V_53 == V_58 )
return 0 ;
if ( V_56 == 1 )
return - V_67 ;
V_55 = V_47 ;
if ( ! F_41 ( & V_47 , V_48 , ( V_56 - 1 ) * ( V_57 + 1 ) ) )
goto V_66;
for ( V_59 = 0 , V_60 = V_56 - 1 ; V_60 ; V_60 >>= 1 ) {
unsigned char * V_70 ;
V_61 = V_59 + ( V_60 >> 1 ) ;
V_70 = V_55 + ( V_57 + 1 ) * V_61 ;
if ( * V_70 == V_53 ) {
++ V_70 ;
for ( V_62 = 0 ; V_62 < V_57 ; ++ V_62 ) {
unsigned char V_49 ;
if ( ! F_40 ( & V_70 , V_48 , & V_49 ) ||
V_54 [ V_62 ] >= V_68 )
goto V_66;
V_51 [ V_54 [ V_62 ] ] = V_49 ;
}
return 0 ;
} else if ( V_53 > * V_70 ) {
V_59 = V_61 + 1 ;
-- V_60 ;
}
}
return - V_67 ;
V_66:
F_30 ( L_12 ) ;
return - V_71 ;
}
static int F_43 ( struct V_21 * V_22 , unsigned char * V_72 )
{
int V_62 , V_73 , V_29 ;
unsigned char V_51 [ 5 ] ;
for ( V_62 = 0 ; V_62 < V_68 ; ) {
int V_74 = V_68 - V_62 ;
if ( V_74 > 4 )
V_74 = 4 ;
V_51 [ 0 ] = ( unsigned char ) ( V_62 + 1 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; ++ V_73 )
V_51 [ 1 + V_73 ] = V_72 [ V_62 + V_73 ] ;
F_27 ( L_13 , 5 , V_51 ) ;
V_29 = F_29 ( V_22 -> V_36 , V_51 , V_74 + 1 ) ;
if ( V_29 != V_74 + 1 ) {
F_30 ( L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
V_62 += V_74 ;
}
return 0 ;
}
static int F_44 ( struct V_21 * V_22 )
{
int V_29 , V_62 ;
unsigned char V_51 [ 4 ] ;
V_29 = F_43 ( V_22 , V_63 -> V_75 ) ;
if ( V_29 != 0 )
return V_29 ;
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x20 ;
V_29 = F_29 ( V_22 -> V_36 , V_51 , 2 ) ;
if ( V_29 != 2 ) {
F_30 ( L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
for ( V_62 = 0 ; V_62 < 10 ; V_62 ++ ) {
V_29 = F_29 ( V_22 -> V_36 , V_51 , 1 ) ;
if ( V_29 == 1 )
break;
F_45 ( 100 ) ;
}
if ( V_29 != 1 ) {
F_30 ( L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
V_29 = F_33 ( V_22 -> V_36 , V_51 , 4 ) ;
if ( V_29 != 4 ) {
F_30 ( L_14 , V_29 ) ;
return 0 ;
}
if ( ( V_51 [ 0 ] != 0x80 ) && ( V_51 [ 0 ] != 0xa0 ) ) {
F_30 ( L_15 , V_51 [ 0 ] ) ;
return 0 ;
}
F_46 ( L_16
L_17 , V_51 [ 1 ] , V_51 [ 2 ] , V_51 [ 3 ] ) ;
return 0 ;
}
static void F_47 ( void )
{
if ( V_63 ) {
if ( V_63 -> V_65 )
F_48 ( V_63 -> V_65 ) ;
if ( V_63 -> V_76 )
F_48 ( V_63 -> V_76 ) ;
F_48 ( V_63 ) ;
V_63 = NULL ;
F_27 ( L_18 ) ;
}
}
static void F_49 ( void )
{
F_3 ( & V_77 ) ;
F_47 () ;
F_4 ( & V_77 ) ;
}
static int F_50 ( struct V_21 * V_22 )
{
int V_29 ;
unsigned int V_62 ;
unsigned char * V_47 , V_78 , V_79 ;
const struct V_80 * V_81 ;
F_3 ( & V_77 ) ;
if ( V_63 ) {
V_29 = 0 ;
goto V_82;
}
V_29 = F_51 ( & V_81 , L_19 , V_22 -> V_2 -> V_7 . V_83 ) ;
if ( V_29 != 0 ) {
F_30 ( L_20
L_21 , V_29 ) ;
V_29 = V_29 < 0 ? V_29 : - V_71 ;
goto V_82;
}
F_27 ( L_22 , V_81 -> V_84 ) ;
V_63 = F_52 ( sizeof( * V_63 ) ) ;
if ( V_63 == NULL ) {
F_30 ( L_23 ) ;
F_53 ( V_81 ) ;
V_29 = - V_85 ;
goto V_82;
}
V_63 -> V_65 = NULL ;
V_63 -> V_76 = F_52 ( V_81 -> V_84 ) ;
if ( V_63 -> V_76 == NULL ) {
F_30 ( L_23 ) ;
F_53 ( V_81 ) ;
F_48 ( V_63 ) ;
V_29 = - V_85 ;
goto V_82;
}
memcpy ( V_63 -> V_76 , V_81 -> V_47 , V_81 -> V_84 ) ;
V_63 -> V_48 = V_63 -> V_76 + V_81 -> V_84 ;
F_53 ( V_81 ) ; V_81 = NULL ;
V_47 = V_63 -> V_76 ;
if ( ! F_40 ( & V_47 , V_63 -> V_48 , & V_78 ) )
goto V_66;
if ( V_78 != 1 ) {
F_30 ( L_24
L_25 ,
V_78 ) ;
F_47 () ;
V_29 = - V_71 ;
goto V_82;
}
V_63 -> V_75 = V_47 ;
if ( ! F_41 ( & V_47 , V_63 -> V_48 , V_68 ) )
goto V_66;
if ( ! F_39 ( & V_47 , V_63 -> V_48 ,
& V_63 -> V_64 ) )
goto V_66;
F_27 ( L_26 , V_63 -> V_64 ) ;
V_63 -> V_65 = F_52 (
V_63 -> V_64 * sizeof( char * ) ) ;
if ( V_63 -> V_65 == NULL ) {
F_47 () ;
V_29 = - V_85 ;
goto V_82;
}
for ( V_62 = 0 ; V_62 < V_68 ; ++ V_62 )
V_63 -> V_69 [ V_62 ] = - 1 ;
if ( ! F_40 ( & V_47 , V_63 -> V_48 , & V_79 ) ||
V_79 > V_68 )
goto V_66;
for ( V_62 = 0 ; V_62 < V_79 ; ++ V_62 ) {
unsigned char V_61 , V_49 ;
if ( ! F_40 ( & V_47 , V_63 -> V_48 , & V_61 ) ||
! F_40 ( & V_47 , V_63 -> V_48 , & V_49 ) ||
V_61 >= V_68 )
goto V_66;
V_63 -> V_69 [ V_61 ] = ( int ) V_49 ;
}
for ( V_62 = 0 ; V_62 < V_63 -> V_64 ; ++ V_62 ) {
unsigned int V_58 ;
unsigned char V_56 ;
unsigned char V_57 ;
V_63 -> V_65 [ V_62 ] = V_47 ;
if ( ! F_39 ( & V_47 , V_63 -> V_48 , & V_58 ) ||
! F_40 ( & V_47 , V_63 -> V_48 , & V_56 ) ||
! F_40 ( & V_47 , V_63 -> V_48 , & V_57 ) ||
V_57 > V_68 || V_56 == 0 )
goto V_66;
if ( ! F_41 ( & V_47 , V_63 -> V_48 , V_57 ) )
goto V_66;
if ( ! F_41 ( & V_47 , V_63 -> V_48 ,
1 + V_68 - V_79 ) )
goto V_66;
if ( ! F_41 ( & V_47 , V_63 -> V_48 ,
( V_57 + 1 ) * ( V_56 - 1 ) ) )
goto V_66;
}
V_29 = 0 ;
goto V_82;
V_66:
F_30 ( L_12 ) ;
F_47 () ;
V_29 = - V_71 ;
V_82:
F_4 ( & V_77 ) ;
return V_29 ;
}
static T_2 F_54 ( struct V_86 * V_87 , char * V_88 , T_3 V_89 , T_4 * V_90 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
struct V_14 * V_15 ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
int V_29 = 0 , V_92 = 0 , V_93 = 0 ;
unsigned int V_94 ;
F_55 ( V_95 , V_96 ) ;
F_27 ( L_27 ) ;
if ( V_89 % V_10 -> V_97 ) {
F_27 ( L_28 ) ;
return - V_98 ;
}
V_15 = F_13 ( V_2 ) ;
if ( V_15 == NULL )
return - V_34 ;
F_56 ( & V_10 -> V_20 , & V_95 ) ;
F_31 ( V_45 ) ;
while ( V_92 < V_89 && V_29 == 0 ) {
if ( F_57 ( V_10 ) ) {
if ( V_92 )
break;
if ( V_87 -> V_99 & V_100 ) {
V_29 = - V_101 ;
break;
}
if ( F_58 ( V_96 ) ) {
V_29 = - V_102 ;
break;
}
F_59 () ;
F_31 ( V_45 ) ;
} else {
unsigned char V_51 [ V_103 ] ;
if ( V_10 -> V_97 > sizeof( V_51 ) ) {
F_30 ( L_29 ,
V_10 -> V_97 ) ;
V_29 = - V_98 ;
break;
}
V_94 = F_60 ( V_10 , V_51 ) ;
if ( V_94 == V_10 -> V_97 ) {
V_29 = F_61 ( ( void * ) V_88 + V_92 , V_51 ,
V_10 -> V_97 ) ;
V_92 += V_10 -> V_97 ;
} else {
V_93 ++ ;
}
if ( V_93 >= 5 ) {
F_30 ( L_30 ) ;
V_29 = - V_104 ;
}
}
}
F_62 ( & V_10 -> V_20 , & V_95 ) ;
F_20 ( V_15 , false ) ;
F_31 ( V_105 ) ;
F_27 ( L_31 , V_29 , V_29 ? L_32 : L_33 ) ;
return V_29 ? V_29 : V_92 ;
}
static int F_63 ( struct V_21 * V_22 , unsigned int V_25 , unsigned int V_53 )
{
unsigned char V_72 [ V_68 ] ;
unsigned char V_51 [ 2 ] ;
int V_62 , V_29 ;
V_29 = F_42 ( V_72 , V_25 , V_53 ) ;
if ( V_29 == - V_67 ) {
F_30 ( L_34
L_35 , V_25 , V_53 ) ;
return V_29 ;
} else if ( V_29 != 0 )
return V_29 ;
V_29 = F_43 ( V_22 , V_72 ) ;
if ( V_29 != 0 )
return V_29 ;
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x40 ;
V_29 = F_29 ( V_22 -> V_36 , V_51 , 2 ) ;
if ( V_29 != 2 ) {
F_30 ( L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
for ( V_62 = 0 ; V_62 < 10 ; V_62 ++ ) {
V_29 = F_29 ( V_22 -> V_36 , V_51 , 1 ) ;
if ( V_29 == 1 )
break;
F_45 ( 100 ) ;
}
if ( V_29 != 1 ) {
F_30 ( L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
V_29 = F_33 ( V_22 -> V_36 , V_51 , 1 ) ;
if ( V_29 != 1 ) {
F_30 ( L_14 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
if ( V_51 [ 0 ] != 0xA0 ) {
F_30 ( L_36 ,
V_51 [ 0 ] ) ;
return - V_71 ;
}
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x80 ;
V_29 = F_29 ( V_22 -> V_36 , V_51 , 2 ) ;
if ( V_29 != 2 ) {
F_30 ( L_2 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
if ( ! V_22 -> V_106 ) {
F_27 ( L_37 , V_25 , V_53 ) ;
return 0 ;
}
for ( V_62 = 0 ; V_62 < 20 ; ++ V_62 ) {
F_31 ( V_39 ) ;
F_32 ( ( 50 * V_40 + 999 ) / 1000 ) ;
V_29 = F_29 ( V_22 -> V_36 , V_51 , 1 ) ;
if ( V_29 == 1 )
break;
F_27 ( L_38
L_39 , V_29 , V_62 + 1 ) ;
}
if ( V_29 != 1 ) {
F_30 ( L_40
L_41 , V_29 ) ;
return V_29 < 0 ? V_29 : - V_71 ;
}
V_62 = F_33 ( V_22 -> V_36 , V_51 , 1 ) ;
if ( V_62 != 1 ) {
F_30 ( L_14 , V_29 ) ;
return - V_71 ;
}
if ( V_51 [ 0 ] != 0x80 ) {
F_30 ( L_42 , V_51 [ 0 ] ) ;
return - V_71 ;
}
F_27 ( L_37 , V_25 , V_53 ) ;
return 0 ;
}
static T_2 F_64 ( struct V_86 * V_87 , const char * V_51 , T_3 V_89 ,
T_4 * V_90 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
struct V_21 * V_22 ;
T_3 V_62 ;
int V_30 = 0 ;
if ( V_89 % sizeof( int ) )
return - V_98 ;
V_22 = F_22 ( V_2 ) ;
if ( V_22 == NULL )
return - V_34 ;
F_3 ( & V_22 -> V_35 ) ;
if ( V_22 -> V_36 == NULL ) {
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
return - V_34 ;
}
F_3 ( & V_2 -> V_38 ) ;
for ( V_62 = 0 ; V_62 < V_89 ; ) {
int V_29 = 0 ;
int V_107 ;
if ( F_65 ( & V_107 , V_51 + V_62 , sizeof( V_107 ) ) ) {
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
return - V_71 ;
}
if ( V_22 -> V_41 == 1 ) {
V_29 = F_50 ( V_22 ) ;
if ( V_29 != 0 ) {
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
if ( V_29 != - V_85 )
V_29 = - V_104 ;
return V_29 ;
}
V_29 = F_44 ( V_22 ) ;
if ( V_29 == 0 )
V_22 -> V_41 = 0 ;
}
if ( V_29 == 0 ) {
V_29 = F_63 ( V_22 , ( unsigned ) V_107 >> 16 ,
( unsigned ) V_107 & 0xFFFF ) ;
if ( V_29 == - V_67 ) {
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
return V_29 ;
}
}
if ( V_29 != 0 ) {
F_30 ( L_43
L_44 ) ;
if ( V_30 >= 3 ) {
F_30 ( L_45
L_4 ) ;
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
return V_29 ;
}
F_31 ( V_39 ) ;
F_32 ( ( 100 * V_40 + 999 ) / 1000 ) ;
V_22 -> V_41 = 1 ;
++ V_30 ;
} else
V_62 += sizeof( int ) ;
}
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
return V_89 ;
}
static unsigned int F_66 ( struct V_86 * V_87 , T_5 * V_95 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
struct V_14 * V_15 ;
struct V_32 * V_10 = V_2 -> V_7 . V_10 ;
unsigned int V_29 ;
F_27 ( L_46 ) ;
V_15 = F_13 ( V_2 ) ;
if ( V_15 == NULL ) {
F_27 ( L_47 ) ;
return V_108 ;
}
F_67 ( V_87 , & V_10 -> V_20 , V_95 ) ;
V_29 = F_57 ( V_10 ) ? 0 : ( V_109 | V_110 ) ;
F_27 ( L_48 , V_29 ? L_49 : L_50 ) ;
return V_29 ;
}
static long F_68 ( struct V_86 * V_87 , unsigned int V_111 , unsigned long V_44 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
int V_112 ;
unsigned long V_113 , V_18 ;
V_18 = V_2 -> V_7 . V_18 ;
switch ( V_111 ) {
case V_114 :
V_112 = F_69 ( ( unsigned long ) 13 ,
( unsigned long * ) V_44 ) ;
break;
case V_115 :
V_112 = F_69 ( V_18 , ( unsigned long * ) V_44 ) ;
break;
case V_116 :
if ( ! ( V_18 & V_117 ) )
return - V_118 ;
V_112 = F_69 ( F_70
( V_18 & V_117 ) ,
( unsigned long * ) V_44 ) ;
break;
case V_119 :
if ( ! ( V_18 & V_117 ) )
return - V_118 ;
V_112 = F_71 ( V_113 , ( unsigned long * ) V_44 ) ;
if ( ! V_112 && ! ( F_72 ( V_113 ) & V_18 ) )
V_112 = - V_98 ;
break;
case V_120 :
if ( ! ( V_18 & V_121 ) )
return - V_118 ;
V_112 = F_69 ( V_122 , ( unsigned long * ) V_44 ) ;
break;
case V_123 :
if ( ! ( V_18 & V_121 ) )
return - V_118 ;
V_112 = F_71 ( V_113 , ( unsigned long * ) V_44 ) ;
if ( ! V_112 && V_113 != V_122 )
return - V_98 ;
break;
default:
return - V_98 ;
}
return V_112 ;
}
static struct V_1 * F_73 ( unsigned int V_8 )
{
struct V_1 * V_2 ;
struct V_1 * V_29 = NULL ;
F_3 ( & V_5 ) ;
if ( ! F_74 ( & V_124 ) ) {
F_75 (ir, &ir_devices_list, list) {
if ( V_2 -> V_7 . V_8 == V_8 ) {
V_29 = F_1 ( V_2 , true ) ;
break;
}
}
}
F_4 ( & V_5 ) ;
return V_29 ;
}
static int F_76 ( struct V_125 * V_126 , struct V_86 * V_87 )
{
struct V_1 * V_2 ;
unsigned int V_8 = F_77 ( V_126 -> V_127 ) ;
V_2 = F_73 ( V_8 ) ;
if ( V_2 == NULL )
return - V_128 ;
F_78 ( & V_2 -> V_46 ) ;
V_87 -> V_91 = V_2 ;
F_79 ( V_126 , V_87 ) ;
return 0 ;
}
static int F_80 ( struct V_125 * V_126 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_91 ;
if ( V_2 == NULL ) {
F_30 ( L_51 ) ;
return - V_128 ;
}
F_81 ( & V_2 -> V_46 ) ;
F_11 ( V_2 , false ) ;
return 0 ;
}
static int F_82 ( struct V_129 * V_130 )
{
if ( strncmp ( L_52 , V_130 -> V_131 , 8 ) == 0 ) {
struct V_21 * V_22 = F_83 ( V_130 ) ;
if ( V_22 != NULL ) {
F_3 ( & V_22 -> V_35 ) ;
V_22 -> V_36 = NULL ;
F_4 ( & V_22 -> V_35 ) ;
F_24 ( V_22 , false ) ;
}
} else if ( strncmp ( L_53 , V_130 -> V_131 , 8 ) == 0 ) {
struct V_14 * V_15 = F_83 ( V_130 ) ;
if ( V_15 != NULL ) {
F_3 ( & V_15 -> V_35 ) ;
V_15 -> V_36 = NULL ;
F_4 ( & V_15 -> V_35 ) ;
F_20 ( V_15 , false ) ;
}
}
return 0 ;
}
static struct V_1 * F_84 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
if ( F_74 ( & V_124 ) )
return NULL ;
F_75 (ir, &ir_devices_list, list)
if ( V_2 -> V_133 == V_133 ) {
F_1 ( V_2 , true ) ;
return V_2 ;
}
return NULL ;
}
static int F_85 ( struct V_129 * V_130 , const struct V_134 * V_58 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_14 * V_15 ;
struct V_132 * V_135 = V_130 -> V_133 ;
int V_29 ;
bool V_136 = false ;
F_27 ( L_54 ,
V_137 , V_58 -> V_131 , V_135 -> V_138 , V_135 -> V_131 , V_130 -> V_139 ) ;
if ( V_58 -> V_140 & V_141 )
V_136 = true ;
else if ( V_142 )
return - V_34 ;
F_86 ( L_55 ,
V_136 ? L_56 : L_57 , V_135 -> V_131 , V_135 -> V_138 ) ;
F_3 ( & V_5 ) ;
V_2 = F_84 ( V_135 ) ;
if ( V_2 == NULL ) {
V_2 = F_87 ( sizeof( struct V_1 ) , V_143 ) ;
if ( V_2 == NULL ) {
V_29 = - V_85 ;
goto V_144;
}
F_88 ( & V_2 -> V_4 ) ;
F_89 ( & V_2 -> V_12 ) ;
F_90 ( & V_2 -> V_12 , & V_124 ) ;
V_2 -> V_133 = V_135 ;
F_91 ( & V_2 -> V_38 ) ;
F_92 ( & V_2 -> V_46 , 0 ) ;
F_93 ( & V_2 -> V_23 ) ;
F_93 ( & V_2 -> V_16 ) ;
memcpy ( & V_2 -> V_7 , & V_145 , sizeof( struct V_146 ) ) ;
V_2 -> V_7 . V_10 = & V_2 -> V_10 ;
V_2 -> V_7 . V_83 = & V_135 -> V_83 ;
V_29 = F_94 ( V_2 -> V_7 . V_10 ,
V_2 -> V_7 . V_97 , V_2 -> V_7 . V_147 ) ;
if ( V_29 )
goto V_148;
}
if ( V_136 ) {
V_15 = F_13 ( V_2 ) ;
V_22 = F_87 ( sizeof( struct V_21 ) , V_143 ) ;
if ( V_22 == NULL ) {
V_29 = - V_85 ;
goto V_149;
}
F_88 ( & V_22 -> V_4 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_7 . V_18 |= V_24 ;
F_91 ( & V_22 -> V_35 ) ;
V_22 -> V_36 = V_130 ;
V_22 -> V_41 = 1 ;
V_22 -> V_106 =
( V_58 -> V_140 & V_150 ) ? false : true ;
V_22 -> V_2 = F_1 ( V_2 , true ) ;
F_95 ( V_130 , F_22 ( V_2 ) ) ;
F_50 ( V_22 ) ;
if ( V_15 == NULL && ! V_142 ) {
F_86 ( L_58
L_59 , V_135 -> V_131 , V_135 -> V_138 ) ;
goto V_151;
}
} else {
V_22 = F_22 ( V_2 ) ;
V_15 = F_87 ( sizeof( struct V_14 ) , V_143 ) ;
if ( V_15 == NULL ) {
V_29 = - V_85 ;
goto V_149;
}
F_88 ( & V_15 -> V_4 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_7 . V_18 |= V_19 ;
F_91 ( & V_15 -> V_35 ) ;
V_15 -> V_36 = V_130 ;
V_15 -> V_43 =
( V_58 -> V_140 & V_150 ) ? true : false ;
V_15 -> V_2 = F_1 ( V_2 , true ) ;
F_95 ( V_130 , F_13 ( V_2 ) ) ;
V_15 -> V_17 = F_96 ( F_35 , F_1 ( V_2 , true ) ,
L_60 , V_135 -> V_138 ) ;
if ( F_97 ( V_15 -> V_17 ) ) {
V_29 = F_98 ( V_15 -> V_17 ) ;
F_30 ( L_61
L_62 , V_137 ) ;
F_11 ( V_2 , true ) ;
F_95 ( V_130 , NULL ) ;
F_20 ( V_15 , true ) ;
V_2 -> V_7 . V_18 &= ~ V_19 ;
goto V_149;
}
if ( V_22 == NULL ) {
F_86 ( L_63
L_64 , V_135 -> V_131 , V_135 -> V_138 ) ;
goto V_151;
}
}
V_2 -> V_7 . V_8 = V_8 ;
V_2 -> V_7 . V_8 = F_99 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_7 . V_8 < 0 || V_2 -> V_7 . V_8 >= V_9 ) {
F_30 ( L_65 ,
V_137 , V_9 - 1 , V_2 -> V_7 . V_8 ) ;
V_29 = - V_152 ;
goto V_149;
}
F_86 ( L_66 ,
V_135 -> V_131 , V_135 -> V_138 , V_2 -> V_7 . V_8 ) ;
V_151:
if ( V_15 != NULL )
F_20 ( V_15 , true ) ;
if ( V_22 != NULL )
F_24 ( V_22 , true ) ;
F_11 ( V_2 , true ) ;
F_86 ( L_67 ,
V_136 ? L_56 : L_57 , V_135 -> V_131 , V_135 -> V_138 ) ;
F_4 ( & V_5 ) ;
return 0 ;
V_149:
if ( V_15 != NULL )
F_20 ( V_15 , true ) ;
if ( V_22 != NULL )
F_24 ( V_22 , true ) ;
V_148:
F_11 ( V_2 , true ) ;
V_144:
F_30 ( L_68 ,
V_137 , V_136 ? L_56 : L_57 , V_135 -> V_131 , V_135 -> V_138 ,
V_29 ) ;
F_4 ( & V_5 ) ;
return V_29 ;
}
static int T_6 F_100 ( void )
{
int V_29 ;
F_46 ( L_69 ) ;
F_91 ( & V_77 ) ;
F_101 ( L_70 ) ;
V_29 = F_102 ( & V_153 ) ;
if ( V_29 )
F_30 ( L_71 ) ;
else
F_46 ( L_72 ) ;
return V_29 ;
}
static void T_7 F_103 ( void )
{
F_104 ( & V_153 ) ;
F_49 () ;
F_46 ( L_73 ) ;
}
