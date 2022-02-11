static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
V_2 = V_5 ;
V_5 = V_2 -> V_6 ;
F_3 ( & V_4 , V_3 ) ;
return V_2 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( V_2 -> type == V_7 )
return;
V_2 -> type = V_7 ;
F_2 ( & V_4 , V_3 ) ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
F_3 ( & V_4 , V_3 ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
V_2 = V_9 -> V_12 ;
if ( V_2 == NULL ) {
V_2 = F_1 () ;
V_2 -> type = V_13 ;
V_2 -> V_14 = V_9 ;
V_9 -> V_12 = V_2 ;
}
V_11 = V_2 -> V_15 ;
V_11 -> V_16 = 0x0A ;
V_11 -> V_3 = 0x20 ;
V_11 -> V_17 = 160 ;
V_11 -> V_18 = ( V_19 ) F_6 ( V_9 -> V_20 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_21 , V_17 , V_22 , V_23 ;
if ( V_9 -> V_17 <= V_9 -> V_24 )
return;
V_2 = V_9 -> V_25 ;
if ( V_2 == NULL ) {
V_2 = F_1 () ;
V_2 -> type = V_26 ;
V_2 -> V_14 = V_9 ;
V_9 -> V_25 = V_2 ;
} else {
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_11 = V_2 -> V_15 ;
V_2 -> V_27 = ( V_9 -> V_28 - V_9 -> V_17 + V_9 -> V_24 ) &
( V_29 - 1 ) ;
V_23 = 0 ;
V_22 = V_2 -> V_27 ;
while ( V_23 < V_30 && V_22 != V_9 -> V_28 ) {
if ( V_9 -> V_31 [ V_22 ] == 0x15 )
V_23 ++ ;
V_22 = ( V_22 + 1 ) & ( V_29 - 1 ) ;
}
V_21 = ( ( V_22 - 1 - V_2 -> V_27 ) & ( V_29 - 1 ) ) + 1 ;
if ( V_21 > V_32 )
V_21 = V_32 ;
V_2 -> V_21 = V_21 ;
V_9 -> V_24 += V_21 ;
V_2 -> V_33 = ( V_22 == V_9 -> V_28 ) && ( V_21 < V_34 ) ;
V_22 = V_2 -> V_27 ;
while ( V_21 > 0 ) {
if ( V_11 > V_2 -> V_15 )
V_11 [ - 1 ] . V_3 |= 0x40 ;
V_11 -> V_16 = 0x01 ;
V_11 -> V_3 = 0x20 ;
V_11 -> V_18 =
( V_19 ) F_6 ( V_9 -> V_31 + V_22 ) ;
V_17 = V_21 ;
if ( V_22 + V_17 > V_29 )
V_17 = V_29 - V_22 ;
V_11 -> V_17 = V_17 ;
V_21 -= V_17 ;
V_22 = ( V_22 + V_17 ) & ( V_29 - 1 ) ;
V_11 ++ ;
}
if ( V_11 > V_2 -> V_15 )
V_11 [ - 1 ] . V_3 |= 0x40 ;
V_11 -> V_16 = 0x03 ;
V_11 -> V_3 = 0 ;
V_11 -> V_18 = 0 ;
V_11 -> V_17 = 1 ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_35 ;
V_2 = V_9 -> V_12 ;
if ( V_2 != NULL &&
! ( V_9 -> V_3 & ( V_36 | V_37 ) ) ) {
V_9 -> V_12 = NULL ;
V_35 = F_9 ( V_9 -> V_38 , V_2 -> V_15 ,
( unsigned long ) V_2 , 0 , 0 ) ;
if ( V_35 != 0 ) {
V_9 -> V_12 = V_2 ;
} else {
V_9 -> V_3 |= V_36 ;
}
}
V_2 = V_9 -> V_25 ;
if ( V_2 != NULL &&
! ( V_9 -> V_3 & ( V_36 | V_39 ) ) ) {
V_9 -> V_25 = NULL ;
V_35 = F_9 ( V_9 -> V_38 , V_2 -> V_15 ,
( unsigned long ) V_2 , 0 , 0 ) ;
if ( V_35 != 0 ) {
V_9 -> V_25 = V_2 ;
} else {
V_9 -> V_3 |= V_36 ;
}
}
}
static void F_10 ( unsigned long V_40 )
{
struct V_8 * V_9 = (struct V_8 * ) V_40 ;
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_3 & V_41 ) {
F_12 ( & V_9 -> V_42 ) ;
V_9 -> V_3 &= ~ V_41 ;
if ( ! ( V_9 -> V_3 & V_43 ) ) {
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
}
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static inline void F_13 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_3 & V_44 ) || ( V_9 -> V_3 & V_43 ) )
return;
if ( V_9 -> V_12 != NULL )
F_8 ( V_9 ) ;
else if ( V_9 -> V_25 != NULL ) {
if ( ( V_9 -> V_25 -> V_33 == 0 ) ||
( V_9 -> V_3 & V_45 ) ) {
F_8 ( V_9 ) ;
if ( V_9 -> V_3 & V_41 ) {
F_12 ( & V_9 -> V_42 ) ;
V_9 -> V_3 &= ~ V_41 ;
}
} else if ( ! ( V_9 -> V_3 & V_41 ) ) {
F_14 ( & V_9 -> V_42 ) ;
V_9 -> V_42 . V_46 = V_47 + V_48 ;
V_9 -> V_42 . V_49 = ( unsigned long ) V_9 ;
V_9 -> V_42 . V_50 = F_10 ;
F_15 ( & V_9 -> V_42 ) ;
V_9 -> V_3 |= V_41 ;
}
}
}
static void F_16 ( unsigned long V_49 )
{
struct V_8 * V_9 = (struct V_8 * ) V_49 ;
F_17 ( V_9 -> V_51 ) ;
}
static void F_18 ( struct V_8 * V_9 )
{
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
if ( V_9 -> V_51 && V_29 - V_9 -> V_17 >= V_52 )
F_19 ( & V_9 -> V_53 ) ;
}
static void F_20 ( struct V_54 * V_38 , unsigned long V_55 ,
struct V_56 * V_56 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_57 * V_51 ;
int V_58 , V_59 ;
int V_17 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
V_2 = (struct V_1 * ) V_55 ;
V_58 = V_56 -> V_61 . V_62 . V_58 ;
V_59 = V_56 -> V_61 . V_62 . V_59 ;
if ( V_58 != 0 )
F_18 ( V_9 ) ;
if ( V_59 & 0x01 ) {
V_59 &= ~ 0x01 ;
}
switch ( V_59 ) {
case 0x80 :
if ( V_58 != 0 )
break;
F_5 ( V_9 ) ;
F_18 ( V_9 ) ;
break;
case 0x08 :
case 0x0C :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
return;
if ( V_2 -> type == V_13 ) {
V_2 -> V_63 = V_56 -> V_61 . V_62 . V_17 ;
}
if ( V_59 == 0x08 )
break;
case 0x04 :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
return;
if ( V_2 -> type == V_13 && V_9 -> V_51 != NULL ) {
unsigned int V_64 ;
V_51 = V_9 -> V_51 ;
V_17 = 160 - V_2 -> V_63 ;
F_22 ( V_9 -> V_20 , V_17 ) ;
V_64 = F_23 ( V_9 -> V_20 , V_17 , V_51 ) ;
switch ( V_64 & V_65 ) {
case V_66 :
break;
case V_67 :
F_24 ( V_51 , V_64 , V_68 ) ;
F_25 ( V_9 -> V_51 ) ;
break;
case V_69 :
if ( V_17 < 2 ||
( strncmp ( V_9 -> V_20 + V_17 - 2 , L_1 , 2 ) &&
strncmp ( V_9 -> V_20 + V_17 - 2 , L_2 , 2 ) ) ) {
V_9 -> V_20 [ V_17 ] = '\n' ;
V_17 ++ ;
} else
V_17 -= 2 ;
F_26 ( V_51 , V_9 -> V_20 , V_17 ) ;
F_25 ( V_9 -> V_51 ) ;
break;
}
} else if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
if ( F_27 ( & V_9 -> V_70 ) &&
V_9 -> V_25 == NULL &&
V_9 -> V_12 == NULL ) {
F_28 ( & V_9 -> V_70 ) ;
}
F_18 ( V_9 ) ;
break;
default:
if ( V_2 != NULL && V_2 -> type != V_7 ) {
if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
}
F_18 ( V_9 ) ;
}
return;
}
static void F_29 ( struct V_8 * V_9 )
{
int V_22 ;
char V_71 ;
F_30 ( V_9 -> V_24 != 0 ) ;
V_22 = ( V_9 -> V_28 - V_9 -> V_17 ) & ( V_29 - 1 ) ;
while ( V_9 -> V_17 > 0 ) {
V_71 = V_9 -> V_31 [ V_22 ] ;
V_22 = ( V_22 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 -- ;
if ( V_71 == 0x15 )
break;
}
V_9 -> V_28 = V_22 ;
}
static void F_31 ( struct V_8 * V_9 , unsigned int V_72 )
{
while ( V_29 - V_9 -> V_17 < V_72 ) {
if ( V_9 -> V_3 & V_43 ) {
F_29 ( V_9 ) ;
continue;
}
V_9 -> V_3 |= V_45 ;
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_45 ;
#ifdef F_32
F_33 () ;
#endif
if ( V_29 - V_9 -> V_17 >= V_72 )
break;
F_34 ( F_11 ( V_9 -> V_38 ) ) ;
F_35 ( 100 ) ;
F_36 ( F_11 ( V_9 -> V_38 ) ) ;
}
}
static void F_37 ( struct V_8 * V_9 , const char * V_73 ,
unsigned int V_72 )
{
unsigned long V_3 ;
int V_74 , V_17 ;
while ( V_72 > 0 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_17 = ( V_72 > V_29 ) ?
V_29 : V_72 ;
V_72 -= V_17 ;
F_31 ( V_9 , V_17 ) ;
while ( 1 ) {
V_74 = F_38 ( int , V_17 ,
F_39 ( V_29 - V_9 -> V_17 ,
V_29 - V_9 -> V_28 ) ) ;
if ( V_74 <= 0 )
break;
memcpy ( V_9 -> V_31 + V_9 -> V_28 , V_73 , V_74 ) ;
F_40 ( V_9 -> V_31 + V_9 -> V_28 , V_74 ) ;
V_9 -> V_28 = ( V_9 -> V_28 + V_74 ) & ( V_29 - 1 ) ;
V_9 -> V_17 += V_74 ;
V_9 -> V_75 += V_74 ;
V_73 += V_74 ;
V_17 -= V_74 ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_41 ( struct V_8 * V_9 , unsigned char V_71 )
{
unsigned long V_3 ;
unsigned int V_72 , V_76 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_71 == '\t' ) {
V_72 = V_77 - ( V_9 -> V_75 % V_77 ) ;
V_9 -> V_75 += V_72 ;
V_71 = ' ' ;
} else if ( V_71 == '\n' ) {
V_72 = 1 ;
V_9 -> V_75 = 0 ;
} else {
V_72 = 1 ;
V_9 -> V_75 ++ ;
}
F_31 ( V_9 , V_72 ) ;
for ( V_76 = 0 ; V_76 < V_72 ; V_76 ++ ) {
V_9 -> V_31 [ V_9 -> V_28 ] = ( char ) V_78 [ ( int ) V_71 ] ;
V_9 -> V_28 = ( V_9 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 ++ ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static void F_42 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_17 > 0 ) {
V_9 -> V_3 |= V_45 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_45 ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_43 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
if ( V_9 -> V_3 & V_44 )
return 0 ;
V_9 -> V_75 = 0 ;
V_9 -> V_3 |= V_44 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_44 ( struct V_8 * V_9 )
{
F_45 ( V_79 , V_80 ) ;
unsigned long V_3 ;
if ( ! ( V_9 -> V_3 & V_44 ) || ( V_9 -> V_3 & V_81 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( ( V_9 -> V_3 & V_36 ) ||
V_9 -> V_25 != NULL ||
V_9 -> V_12 != NULL ) {
V_9 -> V_3 |= V_82 ;
F_46 ( & V_9 -> V_70 , & V_79 ) ;
F_47 ( V_83 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_48 () ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_49 ( & V_9 -> V_70 , & V_79 ) ;
F_47 ( V_84 ) ;
V_9 -> V_3 &= ~ ( V_44 | V_82 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_50 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
int line ;
if ( V_85 [ 0 ] && ( V_85 [ 0 ] == F_21 ( & V_38 -> V_60 ) ) )
return 0 ;
V_9 = F_51 ( sizeof( struct V_8 ) +
V_86 , V_87 | V_88 ) ;
if ( V_9 == NULL )
return - V_89 ;
F_36 ( & V_90 ) ;
for ( line = 0 ; line < V_91 ; line ++ ) {
if ( ! V_85 [ line ] ) {
V_85 [ line ] = V_9 ;
break;
}
}
F_34 ( & V_90 ) ;
if ( line == V_91 ) {
F_52 ( V_9 ) ;
return - V_92 ;
}
V_9 -> V_38 = V_38 ;
V_9 -> V_20 = ( char * ) V_9 + sizeof( struct V_8 ) ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 -> V_31 = F_51 ( V_29 ,
V_87 | V_88 ) ;
if ( V_9 -> V_31 == NULL ) {
F_36 ( & V_90 ) ;
V_85 [ line ] = NULL ;
F_34 ( & V_90 ) ;
F_52 ( V_9 ) ;
return - V_89 ;
}
F_53 ( & V_9 -> V_70 ) ;
F_54 ( & V_9 -> V_53 , F_16 , ( unsigned long ) V_9 ) ;
F_55 ( & V_38 -> V_60 , V_9 ) ;
V_38 -> V_93 = F_20 ;
return 0 ;
}
static void F_56 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
F_57 ( V_38 ) ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
if ( V_9 ) {
F_55 ( & V_38 -> V_60 , NULL ) ;
F_52 ( V_9 -> V_31 ) ;
F_52 ( V_9 ) ;
}
}
static int F_58 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
if ( ! V_9 )
return - V_92 ;
return F_43 ( V_9 ) ;
}
static int F_59 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
if ( ! V_9 )
return - V_92 ;
F_44 ( V_9 ) ;
return 0 ;
}
static int F_60 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_31 ( V_9 , V_29 ) ;
V_9 -> V_3 |= V_43 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static int F_61 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_43 ;
V_9 -> V_3 |= V_45 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_45 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_62 ( struct V_94 * V_95 , const char * V_73 ,
unsigned int V_17 )
{
struct V_8 * V_9 ;
int V_76 ;
if ( V_17 <= 0 )
return;
V_9 = V_85 [ 0 ] ;
while ( V_17 > 0 ) {
for ( V_76 = 0 ; V_76 < V_17 ; V_76 ++ )
if ( V_73 [ V_76 ] == '\t' || V_73 [ V_76 ] == '\n' )
break;
F_37 ( V_9 , V_73 , V_76 ) ;
V_17 -= V_76 ;
V_73 += V_76 ;
if ( V_17 > 0 ) {
F_41 ( V_9 , * V_73 ) ;
V_17 -- ;
V_73 ++ ;
}
}
}
static struct V_96 * F_63 ( struct V_94 * V_74 , int * V_97 )
{
* V_97 = V_74 -> V_97 ;
return V_98 ;
}
static void F_64 ( void )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = V_85 [ 0 ] ;
if ( V_9 -> V_3 & V_43 )
if ( F_65 () )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_31 ( V_9 , V_29 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_66 ( struct V_99 * V_100 ,
unsigned long V_101 , void * V_49 )
{
F_64 () ;
return V_102 ;
}
static int T_1 F_67 ( void )
{
struct V_54 * V_38 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_76 ;
if ( ! V_103 )
return - V_92 ;
if ( V_104 ) {
F_68 ( L_3 , NULL , 0 , NULL ) ;
F_68 ( L_4 , NULL , 0 , NULL ) ;
}
V_5 = NULL ;
F_69 ( & V_4 ) ;
for ( V_76 = 0 ; V_76 < V_105 ; V_76 ++ ) {
V_2 = F_70 ( sizeof( struct V_1 ) , V_87 | V_88 ) ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
V_38 = F_71 () ;
if ( F_72 ( V_38 ) )
return - V_92 ;
V_85 [ 0 ] = V_9 = (struct V_8 * )
F_70 ( sizeof( struct V_8 ) , V_87 | V_88 ) ;
V_9 -> V_31 = F_70 ( V_29 , V_87 | V_88 ) ;
V_9 -> V_20 = F_70 ( V_86 , V_87 | V_88 ) ;
V_9 -> V_38 = V_38 ;
F_55 ( & V_38 -> V_60 , V_9 ) ;
V_38 -> V_93 = F_20 ;
V_9 -> V_3 |= V_81 ;
F_53 ( & V_9 -> V_70 ) ;
F_54 ( & V_9 -> V_53 , F_16 , ( unsigned long ) V_9 ) ;
if ( F_43 ( V_9 ) != 0 ) {
F_52 ( V_9 -> V_20 ) ;
F_52 ( V_9 -> V_31 ) ;
F_52 ( V_9 ) ;
V_85 [ 0 ] = NULL ;
return - V_92 ;
}
F_73 ( & V_106 , & V_107 ) ;
F_74 ( & V_108 ) ;
F_75 ( & V_109 ) ;
return 0 ;
}
static int F_76 ( struct V_57 * V_51 , struct V_110 * V_111 )
{
struct V_8 * V_9 ;
int V_112 ;
V_9 = V_85 [ V_51 -> V_97 ] ;
if ( V_9 == NULL )
return - V_92 ;
V_51 -> V_113 = V_9 ;
V_9 -> V_51 = V_51 ;
V_51 -> V_114 = 0 ;
V_112 = F_43 ( V_9 ) ;
if ( V_112 )
return V_112 ;
return 0 ;
}
static void F_77 ( struct V_57 * V_51 , struct V_110 * V_111 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
if ( V_9 == NULL || V_51 -> V_17 > 1 )
return;
V_51 -> V_115 = 1 ;
F_44 ( V_9 ) ;
F_78 ( & V_9 -> V_53 ) ;
V_51 -> V_115 = 0 ;
V_9 -> V_51 = NULL ;
}
static int F_79 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
if ( ( V_29 - V_9 -> V_17 - V_77 ) >= 0 )
return V_29 - V_9 -> V_17 - V_77 ;
else
return 0 ;
}
static int F_80 ( struct V_57 * V_51 ,
const unsigned char * V_116 , int V_17 )
{
struct V_8 * V_9 ;
if ( ! V_51 )
return 0 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
F_37 ( V_9 , V_116 , V_17 ) ;
return V_17 ;
}
static int F_81 ( struct V_57 * V_51 , unsigned char V_71 )
{
struct V_8 * V_9 ;
if ( ! V_51 )
return 0 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
F_41 ( V_9 , V_71 ) ;
return 1 ;
}
static void F_82 ( struct V_57 * V_51 )
{
}
static int F_83 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
return V_9 -> V_17 ;
}
static void F_84 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
F_42 ( V_9 ) ;
F_17 ( V_51 ) ;
}
static void F_85 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
V_9 -> V_3 |= V_37 ;
}
static void F_86 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
if ( V_9 -> V_3 & V_37 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_37 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_87 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
V_9 -> V_3 |= V_39 ;
}
static void F_88 ( struct V_57 * V_51 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_51 -> V_113 ;
if ( V_9 -> V_3 & V_39 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_39 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static int T_1 F_89 ( void )
{
struct V_96 * V_117 ;
int V_118 ;
if ( ! V_103 )
return 0 ;
V_117 = F_90 ( V_91 ) ;
if ( ! V_117 )
return - V_89 ;
V_118 = F_91 ( & V_119 ) ;
if ( V_118 ) {
F_92 ( V_117 ) ;
return V_118 ;
}
V_117 -> V_120 = L_5 ;
V_117 -> V_121 = L_6 ;
V_117 -> V_122 = V_123 ;
V_117 -> V_124 = 64 ;
V_117 -> type = V_125 ;
V_117 -> V_126 = V_127 ;
V_117 -> V_128 = V_129 ;
V_117 -> V_128 . V_130 = V_131 | V_132 ;
V_117 -> V_128 . V_133 = V_134 | V_135 ;
V_117 -> V_128 . V_136 = V_137 ;
V_117 -> V_3 = V_138 ;
F_93 ( V_117 , & V_139 ) ;
V_118 = F_94 ( V_117 ) ;
if ( V_118 ) {
F_92 ( V_117 ) ;
return V_118 ;
}
V_98 = V_117 ;
return 0 ;
}
static void T_2 F_95 ( void )
{
F_96 ( V_98 ) ;
F_92 ( V_98 ) ;
F_97 ( & V_119 ) ;
}
