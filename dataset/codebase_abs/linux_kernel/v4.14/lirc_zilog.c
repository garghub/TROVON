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
if ( V_2 -> V_7 . V_8 >= 0 ) {
F_7 ( V_2 -> V_7 . V_8 ) ;
V_2 -> V_7 . V_8 = - 1 ;
}
if ( F_8 ( & V_2 -> V_9 . V_10 ) )
F_9 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_11 ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , bool V_3 )
{
int V_12 ;
if ( V_3 )
return F_13 ( & V_2 -> V_4 , F_5 ) ;
F_3 ( & V_5 ) ;
V_12 = F_13 ( & V_2 -> V_4 , F_5 ) ;
F_4 ( & V_5 ) ;
return V_12 ;
}
static struct V_13 * F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
F_15 ( & V_2 -> V_15 ) ;
V_14 = V_2 -> V_14 ;
if ( V_14 )
F_2 ( & V_14 -> V_4 ) ;
F_16 ( & V_2 -> V_15 ) ;
return V_14 ;
}
static void F_17 ( struct V_13 * V_14 , bool V_3 )
{
if ( ! F_18 ( V_14 -> V_16 ) ) {
F_19 ( V_14 -> V_16 ) ;
V_14 -> V_16 = NULL ;
F_12 ( V_14 -> V_2 , V_3 ) ;
}
}
static void F_20 ( struct V_6 * V_4 )
{
struct V_13 * V_14 = F_6 ( V_4 , struct V_13 , V_4 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
V_2 -> V_7 . V_17 &= ~ V_18 ;
V_2 -> V_14 = NULL ;
}
static int F_21 ( struct V_13 * V_14 , bool V_3 )
{
int V_12 ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_15 ( & V_2 -> V_15 ) ;
V_12 = F_13 ( & V_14 -> V_4 , F_20 ) ;
F_16 ( & V_2 -> V_15 ) ;
if ( V_12 ) {
F_17 ( V_14 , V_3 ) ;
F_11 ( V_14 ) ;
F_22 ( & V_2 -> V_9 . V_19 ) ;
}
if ( V_12 )
F_12 ( V_2 , V_3 ) ;
return V_12 ;
}
static struct V_20 * F_23 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
F_15 ( & V_2 -> V_22 ) ;
V_21 = V_2 -> V_21 ;
if ( V_21 )
F_2 ( & V_21 -> V_4 ) ;
F_16 ( & V_2 -> V_22 ) ;
return V_21 ;
}
static void F_24 ( struct V_6 * V_4 )
{
struct V_20 * V_21 = F_6 ( V_4 , struct V_20 , V_4 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
V_2 -> V_7 . V_17 &= ~ V_23 ;
V_2 -> V_21 = NULL ;
F_11 ( V_21 ) ;
}
static int F_25 ( struct V_20 * V_21 , bool V_3 )
{
int V_12 ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_15 ( & V_2 -> V_22 ) ;
V_12 = F_13 ( & V_21 -> V_4 , F_24 ) ;
F_16 ( & V_2 -> V_22 ) ;
if ( V_12 )
F_12 ( V_2 , V_3 ) ;
return V_12 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_24 ;
unsigned char V_25 [ 2 ] ;
unsigned char V_26 [ 6 ] ;
int V_27 = 0 ;
int V_28 ;
int V_29 = 0 ;
unsigned char V_30 [ 1 ] = { 0 } ;
struct V_31 * V_9 = V_2 -> V_7 . V_9 ;
struct V_13 * V_14 ;
struct V_20 * V_21 ;
if ( F_27 ( V_9 ) ) {
F_28 ( V_2 -> V_7 . V_32 , L_1 ) ;
return - V_33 ;
}
V_14 = F_14 ( V_2 ) ;
if ( ! V_14 )
return - V_34 ;
F_3 ( & V_14 -> V_35 ) ;
if ( ! V_14 -> V_36 ) {
F_4 ( & V_14 -> V_35 ) ;
F_21 ( V_14 , false ) ;
return - V_34 ;
}
V_21 = F_23 ( V_2 ) ;
do {
if ( F_29 () ) {
V_28 = - V_37 ;
break;
}
F_3 ( & V_2 -> V_38 ) ;
if ( F_29 () ) {
F_4 ( & V_2 -> V_38 ) ;
V_28 = - V_37 ;
break;
}
V_28 = F_30 ( V_14 -> V_36 , V_30 , 1 ) ;
if ( V_28 != 1 ) {
F_31 ( V_2 -> V_7 . V_32 , L_2 ,
V_28 ) ;
if ( V_29 >= 3 ) {
F_4 ( & V_2 -> V_38 ) ;
F_31 ( V_2 -> V_7 . V_32 ,
L_3 ) ;
break;
}
F_31 ( V_2 -> V_7 . V_32 ,
L_4 ) ;
F_32 ( V_39 ) ;
if ( F_29 () ) {
F_4 ( & V_2 -> V_38 ) ;
V_28 = - V_37 ;
break;
}
F_33 ( ( 100 * V_40 + 999 ) / 1000 ) ;
if ( V_21 )
V_21 -> V_41 = 1 ;
++ V_29 ;
F_4 ( & V_2 -> V_38 ) ;
V_28 = 0 ;
continue;
}
if ( F_29 () ) {
F_4 ( & V_2 -> V_38 ) ;
V_28 = - V_37 ;
break;
}
V_28 = F_34 ( V_14 -> V_36 , V_26 , sizeof( V_26 ) ) ;
F_4 ( & V_2 -> V_38 ) ;
if ( V_28 != sizeof( V_26 ) ) {
F_31 ( V_2 -> V_7 . V_32 ,
L_5 ,
V_28 ) ;
} else {
V_14 -> V_42 [ 0 ] = V_26 [ 3 ] ;
V_14 -> V_42 [ 1 ] = V_26 [ 4 ] ;
V_14 -> V_42 [ 2 ] = V_26 [ 5 ] ;
F_28 ( V_2 -> V_7 . V_32 ,
L_6 ,
V_14 -> V_42 [ 0 ] , V_14 -> V_42 [ 1 ] ) ;
}
if ( V_14 -> V_43 ) {
if ( V_27 && ( V_26 [ 0 ] == 0x80 ) ) {
V_28 = 0 ;
break;
} else if ( V_27 && ( V_26 [ 0 ] == 0x00 ) ) {
V_28 = - V_37 ;
break;
}
} else if ( ( V_14 -> V_42 [ 0 ] & 0x80 ) == 0 ) {
V_28 = V_27 ? 0 : - V_37 ;
break;
}
V_24 = ( ( ( T_1 ) V_14 -> V_42 [ 0 ] & 0x7f ) << 6 ) | ( V_14 -> V_42 [ 1 ] >> 2 ) ;
V_25 [ 0 ] = ( V_24 >> 8 ) & 0xff ;
V_25 [ 1 ] = V_24 & 0xff ;
F_35 ( V_9 , V_25 ) ;
++ V_27 ;
V_28 = 0 ;
} while ( ! F_27 ( V_9 ) );
F_4 ( & V_14 -> V_35 ) ;
if ( V_21 )
F_25 ( V_21 , false ) ;
F_21 ( V_14 , false ) ;
return V_28 ;
}
static int F_36 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_31 * V_9 = V_2 -> V_7 . V_9 ;
F_28 ( V_2 -> V_7 . V_32 , L_7 ) ;
while ( ! F_29 () ) {
F_32 ( V_45 ) ;
if ( F_37 ( & V_2 -> V_46 ) == 0 ) {
F_33 ( V_40 / 2 ) ;
continue;
}
F_33 ( ( 260 * V_40 ) / 1000 ) ;
if ( F_29 () )
break;
if ( ! F_26 ( V_2 ) )
F_22 ( & V_9 -> V_19 ) ;
}
F_28 ( V_2 -> V_7 . V_32 , L_8 ) ;
return 0 ;
}
static int F_38 ( unsigned char * * V_47 ,
unsigned char * V_48 , unsigned int * V_49 )
{
if ( * V_47 + 4 > V_48 )
return 0 ;
* V_49 = ( ( * V_47 ) [ 0 ] << 24 ) | ( ( * V_47 ) [ 1 ] << 16 ) |
( ( * V_47 ) [ 2 ] << 8 ) | ( * V_47 ) [ 3 ] ;
* V_47 += 4 ;
return 1 ;
}
static int F_39 ( unsigned char * * V_47 ,
unsigned char * V_48 , unsigned char * V_49 )
{
if ( * V_47 + 1 > V_48 )
return 0 ;
* V_49 = * ( ( * V_47 ) ++ ) ;
return 1 ;
}
static int F_40 ( unsigned char * * V_47 ,
unsigned char * V_48 , unsigned int V_50 )
{
if ( * V_47 + V_50 > V_48 )
return 0 ;
* V_47 += V_50 ;
return 1 ;
}
static int F_41 ( unsigned char * V_51 ,
unsigned int V_52 , unsigned int V_53 )
{
unsigned char * V_47 , * V_48 , * V_54 , * V_55 ;
unsigned char V_56 , V_57 , V_58 ;
unsigned int V_59 , V_60 , V_61 , V_62 ;
for ( V_59 = 0 , V_60 = V_63 -> V_64 ; V_60 ; V_60 >>= 1 ) {
V_61 = V_59 + ( V_60 >> 1 ) ;
V_47 = V_63 -> V_65 [ V_61 ] ;
if ( ! F_38 ( & V_47 , V_63 -> V_48 , & V_62 ) )
goto V_66;
if ( V_62 == V_52 ) {
break;
} else if ( V_52 > V_62 ) {
V_59 = V_61 + 1 ;
-- V_60 ;
}
}
if ( ! V_60 )
return - V_67 ;
V_48 = V_61 < V_63 -> V_64 - 1 ?
V_63 -> V_65 [ V_61 + 1 ] : V_63 -> V_48 ;
if ( ! F_39 ( & V_47 , V_48 , & V_56 ) ||
! F_39 ( & V_47 , V_48 , & V_57 ) ||
V_57 > V_68 || V_56 == 0 )
goto V_66;
V_54 = V_47 ;
if ( ! F_40 ( & V_47 , V_48 , V_57 ) )
goto V_66;
if ( ! F_39 ( & V_47 , V_48 , & V_58 ) )
goto V_66;
for ( V_62 = 0 ; V_62 < V_68 ; ++ V_62 ) {
if ( V_63 -> V_69 [ V_62 ] == - 1 ) {
if ( ! F_39 ( & V_47 , V_48 , & V_51 [ V_62 ] ) )
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
if ( ! F_40 ( & V_47 , V_48 , ( V_56 - 1 ) * ( V_57 + 1 ) ) )
goto V_66;
for ( V_59 = 0 , V_60 = V_56 - 1 ; V_60 ; V_60 >>= 1 ) {
unsigned char * V_70 ;
V_61 = V_59 + ( V_60 >> 1 ) ;
V_70 = V_55 + ( V_57 + 1 ) * V_61 ;
if ( * V_70 == V_53 ) {
++ V_70 ;
for ( V_62 = 0 ; V_62 < V_57 ; ++ V_62 ) {
unsigned char V_49 ;
if ( ! F_39 ( & V_70 , V_48 , & V_49 ) ||
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
F_42 ( L_9 ) ;
return - V_71 ;
}
static int F_43 ( struct V_20 * V_21 , unsigned char * V_72 )
{
int V_62 , V_73 , V_28 ;
unsigned char V_51 [ 5 ] ;
for ( V_62 = 0 ; V_62 < V_68 ; ) {
int V_74 = V_68 - V_62 ;
if ( V_74 > 4 )
V_74 = 4 ;
V_51 [ 0 ] = ( unsigned char ) ( V_62 + 1 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; ++ V_73 )
V_51 [ 1 + V_73 ] = V_72 [ V_62 + V_73 ] ;
F_28 ( V_21 -> V_2 -> V_7 . V_32 , L_10 , 5 , V_51 ) ;
V_28 = F_30 ( V_21 -> V_36 , V_51 , V_74 + 1 ) ;
if ( V_28 != V_74 + 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_2 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
V_62 += V_74 ;
}
return 0 ;
}
static int F_44 ( struct V_20 * V_21 )
{
int V_28 , V_62 ;
unsigned char V_51 [ 4 ] ;
V_28 = F_43 ( V_21 , V_63 -> V_75 ) ;
if ( V_28 != 0 )
return V_28 ;
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x20 ;
V_28 = F_30 ( V_21 -> V_36 , V_51 , 2 ) ;
if ( V_28 != 2 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_2 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
for ( V_62 = 0 ; V_62 < 10 ; V_62 ++ ) {
V_28 = F_30 ( V_21 -> V_36 , V_51 , 1 ) ;
if ( V_28 == 1 )
break;
F_45 ( 100 ) ;
}
if ( V_28 != 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_2 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
V_28 = F_34 ( V_21 -> V_36 , V_51 , 4 ) ;
if ( V_28 != 4 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_11 , V_28 ) ;
return 0 ;
}
if ( ( V_51 [ 0 ] != 0x80 ) && ( V_51 [ 0 ] != 0xa0 ) ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_12 ,
V_51 [ 0 ] ) ;
return 0 ;
}
F_46 ( V_21 -> V_2 -> V_7 . V_32 ,
L_13 ,
V_51 [ 1 ] , V_51 [ 2 ] , V_51 [ 3 ] ) ;
return 0 ;
}
static void F_47 ( void )
{
if ( V_63 ) {
F_48 ( V_63 -> V_65 ) ;
F_48 ( V_63 -> V_76 ) ;
F_48 ( V_63 ) ;
V_63 = NULL ;
F_49 ( L_14 ) ;
}
}
static void F_50 ( void )
{
F_3 ( & V_77 ) ;
F_47 () ;
F_4 ( & V_77 ) ;
}
static int F_51 ( struct V_20 * V_21 )
{
int V_28 ;
unsigned int V_62 ;
unsigned char * V_47 , V_78 , V_79 ;
const struct V_80 * V_81 ;
F_3 ( & V_77 ) ;
if ( V_63 ) {
V_28 = 0 ;
goto V_82;
}
V_28 = F_52 ( & V_81 , L_15 , V_21 -> V_2 -> V_7 . V_32 ) ;
if ( V_28 != 0 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_16 ,
V_28 ) ;
V_28 = V_28 < 0 ? V_28 : - V_71 ;
goto V_82;
}
F_28 ( V_21 -> V_2 -> V_7 . V_32 , L_17 , V_81 -> V_83 ) ;
V_63 = F_53 ( sizeof( * V_63 ) ) ;
if ( ! V_63 ) {
F_54 ( V_81 ) ;
V_28 = - V_84 ;
goto V_82;
}
V_63 -> V_65 = NULL ;
V_63 -> V_76 = F_53 ( V_81 -> V_83 ) ;
if ( ! V_63 -> V_76 ) {
F_54 ( V_81 ) ;
F_48 ( V_63 ) ;
V_28 = - V_84 ;
goto V_82;
}
memcpy ( V_63 -> V_76 , V_81 -> V_47 , V_81 -> V_83 ) ;
V_63 -> V_48 = V_63 -> V_76 + V_81 -> V_83 ;
F_54 ( V_81 ) ; V_81 = NULL ;
V_47 = V_63 -> V_76 ;
if ( ! F_39 ( & V_47 , V_63 -> V_48 , & V_78 ) )
goto V_66;
if ( V_78 != 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_18 ,
V_78 ) ;
F_47 () ;
V_28 = - V_71 ;
goto V_82;
}
V_63 -> V_75 = V_47 ;
if ( ! F_40 ( & V_47 , V_63 -> V_48 , V_68 ) )
goto V_66;
if ( ! F_38 ( & V_47 , V_63 -> V_48 ,
& V_63 -> V_64 ) )
goto V_66;
F_28 ( V_21 -> V_2 -> V_7 . V_32 , L_19 ,
V_63 -> V_64 ) ;
V_63 -> V_65 = F_53 (
V_63 -> V_64 * sizeof( char * ) ) ;
if ( ! V_63 -> V_65 ) {
F_47 () ;
V_28 = - V_84 ;
goto V_82;
}
for ( V_62 = 0 ; V_62 < V_68 ; ++ V_62 )
V_63 -> V_69 [ V_62 ] = - 1 ;
if ( ! F_39 ( & V_47 , V_63 -> V_48 , & V_79 ) ||
V_79 > V_68 )
goto V_66;
for ( V_62 = 0 ; V_62 < V_79 ; ++ V_62 ) {
unsigned char V_61 , V_49 ;
if ( ! F_39 ( & V_47 , V_63 -> V_48 , & V_61 ) ||
! F_39 ( & V_47 , V_63 -> V_48 , & V_49 ) ||
V_61 >= V_68 )
goto V_66;
V_63 -> V_69 [ V_61 ] = ( int ) V_49 ;
}
for ( V_62 = 0 ; V_62 < V_63 -> V_64 ; ++ V_62 ) {
unsigned int V_58 ;
unsigned char V_56 ;
unsigned char V_57 ;
V_63 -> V_65 [ V_62 ] = V_47 ;
if ( ! F_38 ( & V_47 , V_63 -> V_48 , & V_58 ) ||
! F_39 ( & V_47 , V_63 -> V_48 , & V_56 ) ||
! F_39 ( & V_47 , V_63 -> V_48 , & V_57 ) ||
V_57 > V_68 || V_56 == 0 )
goto V_66;
if ( ! F_40 ( & V_47 , V_63 -> V_48 , V_57 ) )
goto V_66;
if ( ! F_40 ( & V_47 , V_63 -> V_48 ,
1 + V_68 - V_79 ) )
goto V_66;
if ( ! F_40 ( & V_47 , V_63 -> V_48 ,
( V_57 + 1 ) * ( V_56 - 1 ) ) )
goto V_66;
}
V_28 = 0 ;
goto V_82;
V_66:
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_9 ) ;
F_47 () ;
V_28 = - V_71 ;
V_82:
F_4 ( & V_77 ) ;
return V_28 ;
}
static T_2 F_55 ( struct V_85 * V_86 , char T_3 * V_87 , T_4 V_88 ,
T_5 * V_89 )
{
struct V_1 * V_2 = V_86 -> V_90 ;
struct V_13 * V_14 ;
struct V_31 * V_9 = V_2 -> V_7 . V_9 ;
int V_28 = 0 , V_91 = 0 , V_92 = 0 ;
unsigned int V_93 ;
F_56 ( V_94 , V_95 ) ;
F_28 ( V_2 -> V_7 . V_32 , L_20 ) ;
if ( V_88 % V_9 -> V_96 ) {
F_28 ( V_2 -> V_7 . V_32 , L_21 ) ;
return - V_97 ;
}
V_14 = F_14 ( V_2 ) ;
if ( ! V_14 )
return - V_34 ;
F_57 ( & V_9 -> V_19 , & V_94 ) ;
F_32 ( V_45 ) ;
while ( V_91 < V_88 && V_28 == 0 ) {
if ( F_58 ( V_9 ) ) {
if ( V_91 )
break;
if ( V_86 -> V_98 & V_99 ) {
V_28 = - V_100 ;
break;
}
if ( F_59 ( V_95 ) ) {
V_28 = - V_101 ;
break;
}
F_60 () ;
F_32 ( V_45 ) ;
} else {
unsigned char V_51 [ V_102 ] ;
if ( V_9 -> V_96 > sizeof( V_51 ) ) {
F_31 ( V_2 -> V_7 . V_32 ,
L_22 ,
V_9 -> V_96 ) ;
V_28 = - V_97 ;
break;
}
V_93 = F_61 ( V_9 , V_51 ) ;
if ( V_93 == V_9 -> V_96 ) {
V_28 = F_62 ( V_87 + V_91 , V_51 ,
V_9 -> V_96 ) ;
V_91 += V_9 -> V_96 ;
} else {
V_92 ++ ;
}
if ( V_92 >= 5 ) {
F_31 ( V_2 -> V_7 . V_32 , L_23 ) ;
V_28 = - V_103 ;
}
}
}
F_63 ( & V_9 -> V_19 , & V_94 ) ;
F_21 ( V_14 , false ) ;
F_32 ( V_104 ) ;
F_28 ( V_2 -> V_7 . V_32 , L_24 , V_28 ,
V_28 ? L_25 : L_26 ) ;
return V_28 ? V_28 : V_91 ;
}
static int F_64 ( struct V_20 * V_21 , unsigned int V_24 , unsigned int V_53 )
{
unsigned char V_72 [ V_68 ] ;
unsigned char V_51 [ 2 ] ;
int V_62 , V_28 ;
V_28 = F_41 ( V_72 , V_24 , V_53 ) ;
if ( V_28 == - V_67 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_27 ,
V_24 , V_53 ) ;
return V_28 ;
} else if ( V_28 != 0 ) {
return V_28 ;
}
V_28 = F_43 ( V_21 , V_72 ) ;
if ( V_28 != 0 )
return V_28 ;
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x40 ;
V_28 = F_30 ( V_21 -> V_36 , V_51 , 2 ) ;
if ( V_28 != 2 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_2 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
for ( V_62 = 0 ; V_62 < 10 ; V_62 ++ ) {
V_28 = F_30 ( V_21 -> V_36 , V_51 , 1 ) ;
if ( V_28 == 1 )
break;
F_45 ( 100 ) ;
}
if ( V_28 != 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_2 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
V_28 = F_34 ( V_21 -> V_36 , V_51 , 1 ) ;
if ( V_28 != 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_11 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
if ( V_51 [ 0 ] != 0xA0 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_28 ,
V_51 [ 0 ] ) ;
return - V_71 ;
}
V_51 [ 0 ] = 0x00 ;
V_51 [ 1 ] = 0x80 ;
V_28 = F_30 ( V_21 -> V_36 , V_51 , 2 ) ;
if ( V_28 != 2 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_2 , V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
if ( ! V_21 -> V_105 ) {
F_28 ( V_21 -> V_2 -> V_7 . V_32 , L_29 , V_24 , V_53 ) ;
return 0 ;
}
for ( V_62 = 0 ; V_62 < 20 ; ++ V_62 ) {
F_32 ( V_39 ) ;
F_33 ( ( 50 * V_40 + 999 ) / 1000 ) ;
V_28 = F_30 ( V_21 -> V_36 , V_51 , 1 ) ;
if ( V_28 == 1 )
break;
F_28 ( V_21 -> V_2 -> V_7 . V_32 ,
L_30 ,
V_28 , V_62 + 1 ) ;
}
if ( V_28 != 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_31 ,
V_28 ) ;
return V_28 < 0 ? V_28 : - V_71 ;
}
V_62 = F_34 ( V_21 -> V_36 , V_51 , 1 ) ;
if ( V_62 != 1 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_11 , V_28 ) ;
return - V_71 ;
}
if ( V_51 [ 0 ] != 0x80 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 , L_32 ,
V_51 [ 0 ] ) ;
return - V_71 ;
}
F_28 ( V_21 -> V_2 -> V_7 . V_32 , L_29 , V_24 , V_53 ) ;
return 0 ;
}
static T_2 F_65 ( struct V_85 * V_86 , const char T_3 * V_51 , T_4 V_88 ,
T_5 * V_89 )
{
struct V_1 * V_2 = V_86 -> V_90 ;
struct V_20 * V_21 ;
T_4 V_62 ;
int V_29 = 0 ;
if ( V_88 % sizeof( int ) )
return - V_97 ;
V_21 = F_23 ( V_2 ) ;
if ( ! V_21 )
return - V_34 ;
F_3 ( & V_21 -> V_35 ) ;
if ( ! V_21 -> V_36 ) {
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
return - V_34 ;
}
F_3 ( & V_2 -> V_38 ) ;
for ( V_62 = 0 ; V_62 < V_88 ; ) {
int V_28 = 0 ;
int V_106 ;
if ( F_66 ( & V_106 , V_51 + V_62 , sizeof( V_106 ) ) ) {
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
return - V_71 ;
}
if ( V_21 -> V_41 == 1 ) {
V_28 = F_51 ( V_21 ) ;
if ( V_28 != 0 ) {
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
if ( V_28 != - V_84 )
V_28 = - V_103 ;
return V_28 ;
}
V_28 = F_44 ( V_21 ) ;
if ( V_28 == 0 )
V_21 -> V_41 = 0 ;
}
if ( V_28 == 0 ) {
V_28 = F_64 ( V_21 , ( unsigned int ) V_106 >> 16 ,
( unsigned int ) V_106 & 0xFFFF ) ;
if ( V_28 == - V_67 ) {
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
return V_28 ;
}
}
if ( V_28 != 0 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_33 ) ;
if ( V_29 >= 3 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_34 ) ;
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
return V_28 ;
}
F_32 ( V_39 ) ;
F_33 ( ( 100 * V_40 + 999 ) / 1000 ) ;
V_21 -> V_41 = 1 ;
++ V_29 ;
} else {
V_62 += sizeof( int ) ;
}
}
F_4 ( & V_2 -> V_38 ) ;
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
return V_88 ;
}
static unsigned int F_67 ( struct V_85 * V_86 , T_6 * V_94 )
{
struct V_1 * V_2 = V_86 -> V_90 ;
struct V_13 * V_14 ;
struct V_31 * V_9 = V_2 -> V_7 . V_9 ;
unsigned int V_28 ;
F_28 ( V_2 -> V_7 . V_32 , L_35 , V_107 ) ;
V_14 = F_14 ( V_2 ) ;
if ( ! V_14 ) {
F_28 ( V_2 -> V_7 . V_32 , L_36 , V_107 ) ;
return V_108 ;
}
F_68 ( V_86 , & V_9 -> V_19 , V_94 ) ;
V_28 = F_58 ( V_9 ) ? 0 : ( V_109 | V_110 ) ;
F_28 ( V_2 -> V_7 . V_32 , L_37 , V_107 ,
V_28 ? L_38 : L_39 ) ;
return V_28 ;
}
static long F_69 ( struct V_85 * V_86 , unsigned int V_111 , unsigned long V_44 )
{
struct V_1 * V_2 = V_86 -> V_90 ;
unsigned long T_3 * V_112 = ( unsigned long T_3 * ) V_44 ;
int V_113 ;
unsigned long V_114 , V_17 ;
V_17 = V_2 -> V_7 . V_17 ;
switch ( V_111 ) {
case V_115 :
V_113 = F_70 ( 13UL , V_112 ) ;
break;
case V_116 :
V_113 = F_70 ( V_17 , V_112 ) ;
break;
case V_117 :
if ( ! ( V_17 & V_118 ) )
return - V_119 ;
V_113 = F_70 ( F_71
( V_17 & V_118 ) ,
V_112 ) ;
break;
case V_120 :
if ( ! ( V_17 & V_118 ) )
return - V_119 ;
V_113 = F_72 ( V_114 , V_112 ) ;
if ( ! V_113 && ! ( F_73 ( V_114 ) & V_17 ) )
V_113 = - V_119 ;
break;
case V_121 :
if ( ! ( V_17 & V_122 ) )
return - V_119 ;
V_113 = F_70 ( V_123 , V_112 ) ;
break;
case V_124 :
if ( ! ( V_17 & V_122 ) )
return - V_119 ;
V_113 = F_72 ( V_114 , V_112 ) ;
if ( ! V_113 && V_114 != V_123 )
return - V_97 ;
break;
default:
return - V_97 ;
}
return V_113 ;
}
static struct V_1 * F_74 ( unsigned int V_8 )
{
struct V_1 * V_2 ;
struct V_1 * V_28 = NULL ;
F_3 ( & V_5 ) ;
if ( ! F_75 ( & V_125 ) ) {
F_76 (ir, &ir_devices_list, list) {
if ( V_2 -> V_7 . V_8 == V_8 ) {
V_28 = F_1 ( V_2 , true ) ;
break;
}
}
}
F_4 ( & V_5 ) ;
return V_28 ;
}
static int F_77 ( struct V_126 * V_127 , struct V_85 * V_86 )
{
struct V_1 * V_2 ;
unsigned int V_8 = F_78 ( V_127 -> V_128 ) ;
V_2 = F_74 ( V_8 ) ;
if ( ! V_2 )
return - V_129 ;
F_79 ( & V_2 -> V_46 ) ;
V_86 -> V_90 = V_2 ;
F_80 ( V_127 , V_86 ) ;
return 0 ;
}
static int F_81 ( struct V_126 * V_127 , struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_90 ;
if ( ! V_2 ) {
F_42 ( L_40 ,
V_107 ) ;
return - V_129 ;
}
F_82 ( & V_2 -> V_46 ) ;
F_12 ( V_2 , false ) ;
return 0 ;
}
static int F_83 ( struct V_130 * V_131 )
{
if ( strncmp ( L_41 , V_131 -> V_132 , 8 ) == 0 ) {
struct V_20 * V_21 = F_84 ( V_131 ) ;
if ( V_21 ) {
F_3 ( & V_21 -> V_35 ) ;
V_21 -> V_36 = NULL ;
F_4 ( & V_21 -> V_35 ) ;
F_25 ( V_21 , false ) ;
}
} else if ( strncmp ( L_42 , V_131 -> V_132 , 8 ) == 0 ) {
struct V_13 * V_14 = F_84 ( V_131 ) ;
if ( V_14 ) {
F_3 ( & V_14 -> V_35 ) ;
V_14 -> V_36 = NULL ;
F_4 ( & V_14 -> V_35 ) ;
F_21 ( V_14 , false ) ;
}
}
return 0 ;
}
static struct V_1 * F_85 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
if ( F_75 ( & V_125 ) )
return NULL ;
F_76 (ir, &ir_devices_list, list)
if ( V_2 -> V_134 == V_134 ) {
F_1 ( V_2 , true ) ;
return V_2 ;
}
return NULL ;
}
static int F_86 ( struct V_130 * V_131 , const struct V_135 * V_58 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_13 * V_14 ;
struct V_133 * V_136 = V_131 -> V_134 ;
int V_28 ;
bool V_137 = false ;
F_28 ( & V_131 -> V_32 , L_43 ,
V_107 , V_58 -> V_132 , V_136 -> V_138 , V_136 -> V_132 , V_131 -> V_139 ) ;
if ( V_58 -> V_140 & V_141 )
V_137 = true ;
else if ( V_142 )
return - V_34 ;
F_87 ( L_44 ,
V_137 ? L_45 : L_46 , V_136 -> V_132 , V_136 -> V_138 ) ;
F_3 ( & V_5 ) ;
V_2 = F_85 ( V_136 ) ;
if ( ! V_2 ) {
V_2 = F_88 ( sizeof( * V_2 ) , V_143 ) ;
if ( ! V_2 ) {
V_28 = - V_84 ;
goto V_144;
}
F_89 ( & V_2 -> V_4 ) ;
F_90 ( & V_2 -> V_11 ) ;
F_91 ( & V_2 -> V_11 , & V_125 ) ;
V_2 -> V_134 = V_136 ;
F_92 ( & V_2 -> V_38 ) ;
F_93 ( & V_2 -> V_46 , 0 ) ;
F_94 ( & V_2 -> V_22 ) ;
F_94 ( & V_2 -> V_15 ) ;
memcpy ( & V_2 -> V_7 , & V_145 , sizeof( struct V_146 ) ) ;
V_2 -> V_7 . V_9 = & V_2 -> V_9 ;
V_2 -> V_7 . V_32 = & V_136 -> V_32 ;
V_28 = F_95 ( V_2 -> V_7 . V_9 ,
V_2 -> V_7 . V_96 , V_2 -> V_7 . V_147 ) ;
if ( V_28 )
goto V_148;
}
if ( V_137 ) {
V_14 = F_14 ( V_2 ) ;
V_21 = F_88 ( sizeof( * V_21 ) , V_143 ) ;
if ( ! V_21 ) {
V_28 = - V_84 ;
goto V_149;
}
F_89 ( & V_21 -> V_4 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_7 . V_17 |= V_23 ;
F_92 ( & V_21 -> V_35 ) ;
V_21 -> V_36 = V_131 ;
V_21 -> V_41 = 1 ;
V_21 -> V_105 =
( V_58 -> V_140 & V_150 ) ? false : true ;
V_21 -> V_2 = F_1 ( V_2 , true ) ;
F_96 ( V_131 , F_23 ( V_2 ) ) ;
F_51 ( V_21 ) ;
if ( ! V_14 && ! V_142 ) {
F_97 ( V_21 -> V_2 -> V_7 . V_32 ,
L_47 ,
V_136 -> V_132 , V_136 -> V_138 ) ;
goto V_151;
}
} else {
V_21 = F_23 ( V_2 ) ;
V_14 = F_88 ( sizeof( * V_14 ) , V_143 ) ;
if ( ! V_14 ) {
V_28 = - V_84 ;
goto V_149;
}
F_89 ( & V_14 -> V_4 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_7 . V_17 |= V_18 ;
F_92 ( & V_14 -> V_35 ) ;
V_14 -> V_36 = V_131 ;
V_14 -> V_43 =
( V_58 -> V_140 & V_150 ) ? true : false ;
V_14 -> V_2 = F_1 ( V_2 , true ) ;
F_96 ( V_131 , F_14 ( V_2 ) ) ;
V_14 -> V_16 = F_98 ( F_36 , F_1 ( V_2 , true ) ,
L_48 , V_136 -> V_138 ) ;
if ( F_99 ( V_14 -> V_16 ) ) {
V_28 = F_100 ( V_14 -> V_16 ) ;
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_49 ,
V_107 ) ;
F_12 ( V_2 , true ) ;
F_96 ( V_131 , NULL ) ;
F_21 ( V_14 , true ) ;
V_2 -> V_7 . V_17 &= ~ V_18 ;
goto V_152;
}
if ( ! V_21 ) {
F_87 ( L_50 ,
V_136 -> V_132 , V_136 -> V_138 ) ;
goto V_151;
}
}
V_2 -> V_7 . V_8 = F_101 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_7 . V_8 < 0 ) {
F_31 ( V_21 -> V_2 -> V_7 . V_32 ,
L_51 ,
V_107 , V_2 -> V_7 . V_8 ) ;
V_28 = - V_153 ;
goto V_149;
}
F_97 ( V_2 -> V_7 . V_32 ,
L_52 ,
V_136 -> V_132 , V_136 -> V_138 , V_2 -> V_7 . V_8 ) ;
V_151:
if ( V_14 )
F_21 ( V_14 , true ) ;
if ( V_21 )
F_25 ( V_21 , true ) ;
F_12 ( V_2 , true ) ;
F_97 ( V_2 -> V_7 . V_32 ,
L_53 ,
V_137 ? L_45 : L_46 , V_136 -> V_132 , V_136 -> V_138 ) ;
F_4 ( & V_5 ) ;
return 0 ;
V_149:
if ( V_14 )
F_21 ( V_14 , true ) ;
V_152:
if ( V_21 )
F_25 ( V_21 , true ) ;
V_148:
F_12 ( V_2 , true ) ;
V_144:
F_31 ( & V_131 -> V_32 ,
L_54 ,
V_107 , V_137 ? L_45 : L_46 , V_136 -> V_132 , V_136 -> V_138 , V_28 ) ;
F_4 ( & V_5 ) ;
return V_28 ;
}
static int T_7 F_102 ( void )
{
int V_28 ;
F_103 ( L_55 ) ;
F_92 ( & V_77 ) ;
F_104 ( L_56 ) ;
V_28 = F_105 ( & V_154 ) ;
if ( V_28 )
F_42 ( L_57 ) ;
else
F_103 ( L_58 ) ;
return V_28 ;
}
static void T_8 F_106 ( void )
{
F_107 ( & V_154 ) ;
F_50 () ;
F_103 ( L_59 ) ;
}
