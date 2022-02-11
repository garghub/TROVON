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
if ( ! ( V_9 -> V_43 . V_3 & V_44 ) ) {
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
}
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static inline void F_13 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_43 . V_3 & V_45 ) ||
( V_9 -> V_43 . V_3 & V_44 ) )
return;
if ( V_9 -> V_12 != NULL )
F_8 ( V_9 ) ;
else if ( V_9 -> V_25 != NULL ) {
if ( ( V_9 -> V_25 -> V_33 == 0 ) ||
( V_9 -> V_3 & V_46 ) ) {
F_8 ( V_9 ) ;
if ( V_9 -> V_3 & V_41 ) {
F_12 ( & V_9 -> V_42 ) ;
V_9 -> V_3 &= ~ V_41 ;
}
} else if ( ! ( V_9 -> V_3 & V_41 ) ) {
V_9 -> V_42 . V_47 = V_48 + V_49 ;
F_14 ( & V_9 -> V_42 ) ;
V_9 -> V_3 |= V_41 ;
}
}
}
static void F_15 ( unsigned long V_50 )
{
struct V_8 * V_9 = (struct V_8 * ) V_50 ;
struct V_51 * V_52 ;
V_52 = F_16 ( & V_9 -> V_43 ) ;
if ( V_52 ) {
F_17 ( V_52 ) ;
F_18 ( V_52 ) ;
}
}
static void F_19 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
if ( V_52 && V_29 - V_9 -> V_17 >= V_53 )
F_20 ( & V_9 -> V_54 ) ;
}
static void F_21 ( struct V_55 * V_38 , unsigned long V_56 ,
struct V_57 * V_57 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_58 , V_59 ;
int V_17 ;
V_9 = F_22 ( & V_38 -> V_60 ) ;
V_2 = (struct V_1 * ) V_56 ;
V_52 = F_16 ( & V_9 -> V_43 ) ;
V_58 = V_57 -> V_61 . V_62 . V_58 ;
V_59 = V_57 -> V_61 . V_62 . V_59 ;
if ( V_58 != 0 )
F_19 ( V_9 , V_52 ) ;
if ( V_59 & 0x01 ) {
V_59 &= ~ 0x01 ;
}
switch ( V_59 ) {
case 0x80 :
if ( V_58 != 0 )
break;
F_5 ( V_9 ) ;
F_19 ( V_9 , V_52 ) ;
break;
case 0x08 :
case 0x0C :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
goto V_63;
if ( V_2 -> type == V_13 ) {
V_2 -> V_64 = V_57 -> V_61 . V_62 . V_17 ;
}
if ( V_59 == 0x08 )
break;
case 0x04 :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
goto V_63;
if ( V_2 -> type == V_13 && V_52 != NULL ) {
unsigned int V_65 ;
V_17 = 160 - V_2 -> V_64 ;
F_23 ( V_9 -> V_20 , V_17 ) ;
V_65 = F_24 ( V_9 -> V_20 , V_17 , V_52 ) ;
switch ( V_65 & V_66 ) {
case V_67 :
break;
case V_68 :
F_25 ( V_52 , V_65 , V_69 ) ;
F_26 ( V_52 ) ;
break;
case V_70 :
if ( V_17 < 2 ||
( strncmp ( V_9 -> V_20 + V_17 - 2 , L_1 , 2 ) &&
strncmp ( V_9 -> V_20 + V_17 - 2 , L_2 , 2 ) ) ) {
V_9 -> V_20 [ V_17 ] = '\n' ;
V_17 ++ ;
} else
V_17 -= 2 ;
F_27 ( V_52 , V_9 -> V_20 , V_17 ) ;
F_26 ( V_52 ) ;
break;
}
} else if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
if ( F_28 ( & V_9 -> V_71 ) &&
V_9 -> V_25 == NULL &&
V_9 -> V_12 == NULL ) {
F_29 ( & V_9 -> V_71 ) ;
}
F_19 ( V_9 , V_52 ) ;
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
F_19 ( V_9 , V_52 ) ;
}
V_63:
F_18 ( V_52 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
int V_22 ;
char V_72 ;
F_31 ( V_9 -> V_24 != 0 ) ;
V_22 = ( V_9 -> V_28 - V_9 -> V_17 ) & ( V_29 - 1 ) ;
while ( V_9 -> V_17 > 0 ) {
V_72 = V_9 -> V_31 [ V_22 ] ;
V_22 = ( V_22 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 -- ;
if ( V_72 == 0x15 )
break;
}
V_9 -> V_28 = V_22 ;
}
static void F_32 ( struct V_8 * V_9 , unsigned int V_73 )
{
while ( V_29 - V_9 -> V_17 < V_73 ) {
if ( V_9 -> V_43 . V_3 & V_44 ) {
F_30 ( V_9 ) ;
continue;
}
V_9 -> V_3 |= V_46 ;
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_46 ;
#ifdef F_33
F_34 () ;
#endif
if ( V_29 - V_9 -> V_17 >= V_73 )
break;
F_35 ( F_11 ( V_9 -> V_38 ) ) ;
F_36 ( 100 ) ;
F_37 ( F_11 ( V_9 -> V_38 ) ) ;
}
}
static void F_38 ( struct V_8 * V_9 , const char * V_74 ,
unsigned int V_73 )
{
unsigned long V_3 ;
int V_75 , V_17 ;
while ( V_73 > 0 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_17 = ( V_73 > V_29 ) ?
V_29 : V_73 ;
V_73 -= V_17 ;
F_32 ( V_9 , V_17 ) ;
while ( 1 ) {
V_75 = F_39 ( int , V_17 ,
F_40 ( V_29 - V_9 -> V_17 ,
V_29 - V_9 -> V_28 ) ) ;
if ( V_75 <= 0 )
break;
memcpy ( V_9 -> V_31 + V_9 -> V_28 , V_74 , V_75 ) ;
F_41 ( V_9 -> V_31 + V_9 -> V_28 , V_75 ) ;
V_9 -> V_28 = ( V_9 -> V_28 + V_75 ) & ( V_29 - 1 ) ;
V_9 -> V_17 += V_75 ;
V_9 -> V_76 += V_75 ;
V_74 += V_75 ;
V_17 -= V_75 ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_42 ( struct V_8 * V_9 , unsigned char V_72 )
{
unsigned long V_3 ;
unsigned int V_73 , V_77 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_72 == '\t' ) {
V_73 = V_78 - ( V_9 -> V_76 % V_78 ) ;
V_9 -> V_76 += V_73 ;
V_72 = ' ' ;
} else if ( V_72 == '\n' ) {
V_73 = 1 ;
V_9 -> V_76 = 0 ;
} else {
V_73 = 1 ;
V_9 -> V_76 ++ ;
}
F_32 ( V_9 , V_73 ) ;
for ( V_77 = 0 ; V_77 < V_73 ; V_77 ++ ) {
V_9 -> V_31 [ V_9 -> V_28 ] = ( char ) V_79 [ ( int ) V_72 ] ;
V_9 -> V_28 = ( V_9 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 ++ ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static void F_43 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_17 > 0 ) {
V_9 -> V_3 |= V_46 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_46 ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_44 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
if ( V_9 -> V_43 . V_3 & V_45 )
return 0 ;
V_9 -> V_76 = 0 ;
V_9 -> V_43 . V_3 |= V_45 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_45 ( struct V_8 * V_9 )
{
F_46 ( V_80 , V_81 ) ;
unsigned long V_3 ;
if ( ! ( V_9 -> V_43 . V_3 & V_45 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( ( V_9 -> V_3 & V_36 ) ||
V_9 -> V_25 != NULL ||
V_9 -> V_12 != NULL ) {
V_9 -> V_43 . V_3 |= V_82 ;
F_47 ( & V_9 -> V_71 , & V_80 ) ;
F_48 ( V_83 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_49 () ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_50 ( & V_9 -> V_71 , & V_80 ) ;
F_48 ( V_84 ) ;
V_9 -> V_43 . V_3 &= ~ ( V_45 | V_82 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static struct V_8 * F_51 ( void )
{
struct V_8 * V_14 ;
V_14 = F_52 ( sizeof( struct V_8 ) , V_85 | V_86 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_31 = F_52 ( V_29 , V_85 | V_86 ) ;
V_14 -> V_20 = F_52 ( V_87 , V_85 | V_86 ) ;
if ( ! V_14 -> V_31 || ! V_14 -> V_20 ) {
F_53 ( V_14 ) ;
return NULL ;
}
F_54 ( & V_14 -> V_42 , F_10 , ( unsigned long ) V_14 ) ;
F_55 ( & V_14 -> V_71 ) ;
F_56 ( & V_14 -> V_54 , F_15 , ( unsigned long ) V_14 ) ;
F_57 ( & V_14 -> V_43 ) ;
return V_14 ;
}
static void F_58 ( struct V_8 * V_9 )
{
F_53 ( V_9 -> V_20 ) ;
F_53 ( V_9 -> V_31 ) ;
F_53 ( V_9 ) ;
}
static int F_59 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
int line ;
if ( V_88 [ 0 ] && ( V_88 [ 0 ] == F_22 ( & V_38 -> V_60 ) ) )
return 0 ;
V_9 = F_51 () ;
if ( V_9 == NULL )
return - V_89 ;
V_9 -> V_38 = V_38 ;
F_60 ( & V_38 -> V_60 , V_9 ) ;
V_38 -> V_90 = F_21 ;
F_37 ( & V_91 ) ;
for ( line = 0 ; line < V_92 ; line ++ ) {
if ( ! V_88 [ line ] ) {
V_88 [ line ] = V_9 ;
break;
}
}
F_35 ( & V_91 ) ;
if ( line == V_92 ) {
F_58 ( V_9 ) ;
return - V_93 ;
}
return 0 ;
}
static void F_61 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
unsigned int line ;
F_62 ( V_38 ) ;
V_9 = F_22 ( & V_38 -> V_60 ) ;
if ( V_9 ) {
F_37 ( & V_91 ) ;
for ( line = 0 ; line < V_92 ; line ++ )
if ( V_88 [ line ] == V_9 )
break;
V_88 [ line ] = NULL ;
F_35 ( & V_91 ) ;
F_60 ( & V_38 -> V_60 , NULL ) ;
F_58 ( V_9 ) ;
}
}
static int F_63 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_22 ( & V_38 -> V_60 ) ;
if ( ! V_9 )
return - V_93 ;
return F_44 ( V_9 ) ;
}
static int F_64 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_22 ( & V_38 -> V_60 ) ;
if ( ! V_9 )
return - V_93 ;
F_45 ( V_9 ) ;
return 0 ;
}
static int F_65 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_22 ( & V_38 -> V_60 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_32 ( V_9 , V_29 ) ;
V_9 -> V_43 . V_3 |= V_44 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static int F_66 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_22 ( & V_38 -> V_60 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_43 . V_3 &= ~ V_44 ;
V_9 -> V_3 |= V_46 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_46 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_67 ( struct V_94 * V_95 , const char * V_74 ,
unsigned int V_17 )
{
struct V_8 * V_9 ;
int V_77 ;
if ( V_17 <= 0 )
return;
V_9 = V_88 [ 0 ] ;
while ( V_17 > 0 ) {
for ( V_77 = 0 ; V_77 < V_17 ; V_77 ++ )
if ( V_74 [ V_77 ] == '\t' || V_74 [ V_77 ] == '\n' )
break;
F_38 ( V_9 , V_74 , V_77 ) ;
V_17 -= V_77 ;
V_74 += V_77 ;
if ( V_17 > 0 ) {
F_42 ( V_9 , * V_74 ) ;
V_17 -- ;
V_74 ++ ;
}
}
}
static struct V_96 * F_68 ( struct V_94 * V_75 , int * V_97 )
{
* V_97 = V_75 -> V_97 ;
return V_98 ;
}
static void F_69 ( void )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = V_88 [ 0 ] ;
if ( V_9 -> V_43 . V_3 & V_44 )
if ( F_70 () )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_32 ( V_9 , V_29 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_71 ( struct V_99 * V_100 ,
unsigned long V_101 , void * V_50 )
{
F_69 () ;
return V_102 ;
}
static int T_1 F_72 ( void )
{
struct V_55 * V_38 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_77 ;
if ( ! V_103 )
return - V_93 ;
if ( V_104 ) {
F_73 ( L_3 , NULL , 0 , NULL ) ;
F_73 ( L_4 , NULL , 0 , NULL ) ;
}
V_5 = NULL ;
F_74 ( & V_4 ) ;
for ( V_77 = 0 ; V_77 < V_105 ; V_77 ++ ) {
V_2 = F_52 ( sizeof( struct V_1 ) , V_85 | V_86 ) ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
V_38 = F_75 () ;
if ( F_76 ( V_38 ) )
return - V_93 ;
V_88 [ 0 ] = V_9 = F_51 () ;
V_9 -> V_38 = V_38 ;
F_60 ( & V_38 -> V_60 , V_9 ) ;
V_38 -> V_90 = F_21 ;
if ( F_44 ( V_9 ) != 0 ) {
F_58 ( V_9 ) ;
V_88 [ 0 ] = NULL ;
return - V_93 ;
}
F_77 ( & V_106 , & V_107 ) ;
F_78 ( & V_108 ) ;
F_79 ( & V_109 ) ;
return 0 ;
}
static int F_80 ( struct V_96 * V_110 , struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = V_88 [ V_52 -> V_97 ] ;
if ( V_9 == NULL )
return - V_93 ;
V_52 -> V_111 = V_9 ;
return F_81 ( & V_9 -> V_43 , V_110 , V_52 ) ;
}
static int F_82 ( struct V_51 * V_52 , struct V_112 * V_113 )
{
struct V_8 * V_9 = V_52 -> V_111 ;
int V_114 ;
F_83 ( & V_9 -> V_43 , V_52 ) ;
V_52 -> V_115 = 0 ;
V_114 = F_44 ( V_9 ) ;
if ( V_114 )
return V_114 ;
return 0 ;
}
static void F_84 ( struct V_51 * V_52 , struct V_112 * V_113 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
if ( V_9 == NULL || V_52 -> V_17 > 1 )
return;
V_52 -> V_116 = 1 ;
F_45 ( V_9 ) ;
F_85 ( & V_9 -> V_54 ) ;
V_52 -> V_116 = 0 ;
F_83 ( & V_9 -> V_43 , NULL ) ;
}
static int F_86 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
if ( ( V_29 - V_9 -> V_17 - V_78 ) >= 0 )
return V_29 - V_9 -> V_17 - V_78 ;
else
return 0 ;
}
static int F_87 ( struct V_51 * V_52 ,
const unsigned char * V_117 , int V_17 )
{
struct V_8 * V_9 ;
if ( ! V_52 )
return 0 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
F_38 ( V_9 , V_117 , V_17 ) ;
return V_17 ;
}
static int F_88 ( struct V_51 * V_52 , unsigned char V_72 )
{
struct V_8 * V_9 ;
if ( ! V_52 )
return 0 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
F_42 ( V_9 , V_72 ) ;
return 1 ;
}
static void F_89 ( struct V_51 * V_52 )
{
}
static int F_90 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
return V_9 -> V_17 ;
}
static void F_91 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
F_43 ( V_9 ) ;
F_17 ( V_52 ) ;
}
static void F_92 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
V_9 -> V_3 |= V_37 ;
}
static void F_93 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
if ( V_9 -> V_3 & V_37 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_37 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_94 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
V_9 -> V_3 |= V_39 ;
}
static void F_95 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_52 -> V_111 ;
if ( V_9 -> V_3 & V_39 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_39 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static int T_1 F_96 ( void )
{
struct V_96 * V_110 ;
int V_118 ;
if ( ! V_103 )
return 0 ;
V_110 = F_97 ( V_92 ) ;
if ( ! V_110 )
return - V_89 ;
V_118 = F_98 ( & V_119 ) ;
if ( V_118 ) {
F_99 ( V_110 ) ;
return V_118 ;
}
V_110 -> V_120 = L_5 ;
V_110 -> V_121 = L_6 ;
V_110 -> V_122 = V_123 ;
V_110 -> V_124 = 64 ;
V_110 -> type = V_125 ;
V_110 -> V_126 = V_127 ;
V_110 -> V_128 = V_129 ;
V_110 -> V_128 . V_130 = V_131 | V_132 ;
V_110 -> V_128 . V_133 = V_134 | V_135 ;
V_110 -> V_128 . V_136 = V_137 ;
V_110 -> V_3 = V_138 ;
F_100 ( V_110 , & V_139 ) ;
V_118 = F_101 ( V_110 ) ;
if ( V_118 ) {
F_99 ( V_110 ) ;
return V_118 ;
}
V_98 = V_110 ;
return 0 ;
}
static void T_2 F_102 ( void )
{
F_103 ( V_98 ) ;
F_99 ( V_98 ) ;
F_104 ( & V_119 ) ;
}
