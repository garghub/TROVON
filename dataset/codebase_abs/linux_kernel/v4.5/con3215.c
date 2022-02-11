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
V_9 -> V_3 &= ~ V_41 ;
if ( ! ( V_9 -> V_42 . V_3 & V_43 ) ) {
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
if ( ( V_9 -> V_12 || V_9 -> V_25 ) &&
! ( V_9 -> V_3 & V_36 ) &&
! ( V_9 -> V_3 & V_41 ) ) {
V_9 -> V_44 . V_45 = V_46 + V_47 ;
F_12 ( & V_9 -> V_44 ) ;
V_9 -> V_3 |= V_41 ;
}
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static inline void F_13 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_42 . V_3 & V_48 ) ||
( V_9 -> V_42 . V_3 & V_43 ) )
return;
if ( V_9 -> V_12 != NULL )
F_8 ( V_9 ) ;
else if ( V_9 -> V_25 != NULL ) {
if ( ( V_9 -> V_25 -> V_33 == 0 ) ||
( V_9 -> V_3 & V_49 ) ) {
F_8 ( V_9 ) ;
}
}
if ( ( V_9 -> V_12 || V_9 -> V_25 ) &&
! ( V_9 -> V_3 & V_36 ) &&
! ( V_9 -> V_3 & V_41 ) ) {
V_9 -> V_44 . V_45 = V_46 + V_47 ;
F_12 ( & V_9 -> V_44 ) ;
V_9 -> V_3 |= V_41 ;
}
}
static void F_14 ( unsigned long V_50 )
{
struct V_8 * V_9 = (struct V_8 * ) V_50 ;
struct V_51 * V_52 ;
V_52 = F_15 ( & V_9 -> V_42 ) ;
if ( V_52 ) {
F_16 ( V_52 ) ;
F_17 ( V_52 ) ;
}
}
static void F_18 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
if ( V_52 && V_29 - V_9 -> V_17 >= V_53 )
F_19 ( & V_9 -> V_54 ) ;
}
static void F_20 ( struct V_55 * V_38 , unsigned long V_56 ,
struct V_57 * V_57 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_58 , V_59 ;
int V_17 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
V_2 = (struct V_1 * ) V_56 ;
V_52 = F_15 ( & V_9 -> V_42 ) ;
V_58 = V_57 -> V_61 . V_62 . V_58 ;
V_59 = V_57 -> V_61 . V_62 . V_59 ;
if ( V_58 != 0 )
F_18 ( V_9 , V_52 ) ;
if ( V_59 & 0x01 ) {
V_59 &= ~ 0x01 ;
}
switch ( V_59 ) {
case 0x80 :
if ( V_58 != 0 )
break;
F_5 ( V_9 ) ;
F_18 ( V_9 , V_52 ) ;
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
F_22 ( V_9 -> V_20 , V_17 ) ;
V_65 = F_23 ( V_9 -> V_20 , V_17 , V_52 ) ;
switch ( V_65 & V_66 ) {
case V_67 :
break;
case V_68 :
F_24 ( & V_9 -> V_42 , V_65 ,
V_69 ) ;
F_25 ( & V_9 -> V_42 ) ;
break;
case V_70 :
if ( V_17 < 2 ||
( strncmp ( V_9 -> V_20 + V_17 - 2 , L_1 , 2 ) &&
strncmp ( V_9 -> V_20 + V_17 - 2 , L_2 , 2 ) ) ) {
V_9 -> V_20 [ V_17 ] = '\n' ;
V_17 ++ ;
} else
V_17 -= 2 ;
F_26 ( & V_9 -> V_42 , V_9 -> V_20 ,
V_17 ) ;
F_25 ( & V_9 -> V_42 ) ;
break;
}
} else if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
if ( F_27 ( & V_9 -> V_71 ) &&
V_9 -> V_25 == NULL &&
V_9 -> V_12 == NULL ) {
F_28 ( & V_9 -> V_71 ) ;
}
F_18 ( V_9 , V_52 ) ;
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
F_18 ( V_9 , V_52 ) ;
}
V_63:
F_17 ( V_52 ) ;
}
static void F_29 ( struct V_8 * V_9 )
{
int V_22 ;
char V_72 ;
F_30 ( V_9 -> V_24 != 0 ) ;
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
static void F_31 ( struct V_8 * V_9 , unsigned int V_73 )
{
while ( V_29 - V_9 -> V_17 < V_73 ) {
if ( V_9 -> V_42 . V_3 & V_43 ) {
F_29 ( V_9 ) ;
continue;
}
V_9 -> V_3 |= V_49 ;
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_49 ;
#ifdef F_32
F_33 ( V_9 -> V_38 ) ;
#endif
if ( V_29 - V_9 -> V_17 >= V_73 )
break;
F_34 ( F_11 ( V_9 -> V_38 ) ) ;
F_35 ( 100 ) ;
F_36 ( F_11 ( V_9 -> V_38 ) ) ;
}
}
static void F_37 ( struct V_8 * V_9 , const char * V_74 ,
unsigned int V_73 )
{
unsigned long V_3 ;
int V_75 , V_17 ;
while ( V_73 > 0 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_17 = ( V_73 > V_29 ) ?
V_29 : V_73 ;
V_73 -= V_17 ;
F_31 ( V_9 , V_17 ) ;
while ( 1 ) {
V_75 = F_38 ( int , V_17 ,
F_39 ( V_29 - V_9 -> V_17 ,
V_29 - V_9 -> V_28 ) ) ;
if ( V_75 <= 0 )
break;
memcpy ( V_9 -> V_31 + V_9 -> V_28 , V_74 , V_75 ) ;
F_40 ( V_9 -> V_31 + V_9 -> V_28 , V_75 ) ;
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
static void F_41 ( struct V_8 * V_9 , unsigned char V_72 )
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
F_31 ( V_9 , V_73 ) ;
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
static void F_42 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_17 > 0 ) {
V_9 -> V_3 |= V_49 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_49 ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_43 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
if ( V_9 -> V_42 . V_3 & V_48 )
return 0 ;
V_9 -> V_76 = 0 ;
V_9 -> V_42 . V_3 |= V_48 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_44 ( struct V_8 * V_9 )
{
F_45 ( V_80 , V_81 ) ;
unsigned long V_3 ;
if ( ! ( V_9 -> V_42 . V_3 & V_48 ) ||
( V_9 -> V_3 & V_82 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( ( V_9 -> V_3 & V_36 ) ||
V_9 -> V_25 != NULL ||
V_9 -> V_12 != NULL ) {
V_9 -> V_42 . V_3 |= V_83 ;
F_46 ( & V_9 -> V_71 , & V_80 ) ;
F_47 ( V_84 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_48 () ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_49 ( & V_9 -> V_71 , & V_80 ) ;
F_47 ( V_85 ) ;
V_9 -> V_42 . V_3 &= ~ ( V_48 | V_83 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static struct V_8 * F_50 ( void )
{
struct V_8 * V_14 ;
V_14 = F_51 ( sizeof( struct V_8 ) , V_86 | V_87 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_31 = F_51 ( V_29 , V_86 | V_87 ) ;
V_14 -> V_20 = F_51 ( V_88 , V_86 | V_87 ) ;
if ( ! V_14 -> V_31 || ! V_14 -> V_20 ) {
F_52 ( V_14 -> V_20 ) ;
F_52 ( V_14 -> V_31 ) ;
F_52 ( V_14 ) ;
return NULL ;
}
F_53 ( & V_14 -> V_44 , F_10 , ( unsigned long ) V_14 ) ;
F_54 ( & V_14 -> V_71 ) ;
F_55 ( & V_14 -> V_54 , F_14 , ( unsigned long ) V_14 ) ;
F_56 ( & V_14 -> V_42 ) ;
return V_14 ;
}
static void F_57 ( struct V_8 * V_9 )
{
F_52 ( V_9 -> V_20 ) ;
F_52 ( V_9 -> V_31 ) ;
F_58 ( & V_9 -> V_42 ) ;
F_52 ( V_9 ) ;
}
static int F_59 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
int line ;
if ( V_89 [ 0 ] && ( V_89 [ 0 ] == F_21 ( & V_38 -> V_60 ) ) )
return 0 ;
V_9 = F_50 () ;
if ( V_9 == NULL )
return - V_90 ;
V_9 -> V_38 = V_38 ;
F_60 ( & V_38 -> V_60 , V_9 ) ;
V_38 -> V_91 = F_20 ;
F_36 ( & V_92 ) ;
for ( line = 0 ; line < V_93 ; line ++ ) {
if ( ! V_89 [ line ] ) {
V_89 [ line ] = V_9 ;
break;
}
}
F_34 ( & V_92 ) ;
if ( line == V_93 ) {
F_57 ( V_9 ) ;
return - V_94 ;
}
return 0 ;
}
static void F_61 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
unsigned int line ;
F_62 ( V_38 ) ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
if ( V_9 ) {
F_36 ( & V_92 ) ;
for ( line = 0 ; line < V_93 ; line ++ )
if ( V_89 [ line ] == V_9 )
break;
V_89 [ line ] = NULL ;
F_34 ( & V_92 ) ;
F_60 ( & V_38 -> V_60 , NULL ) ;
F_57 ( V_9 ) ;
}
}
static int F_63 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
if ( ! V_9 )
return - V_94 ;
return F_43 ( V_9 ) ;
}
static int F_64 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
if ( ! V_9 )
return - V_94 ;
F_44 ( V_9 ) ;
return 0 ;
}
static int F_65 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_31 ( V_9 , V_29 ) ;
V_9 -> V_42 . V_3 |= V_43 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static int F_66 ( struct V_55 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_21 ( & V_38 -> V_60 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_42 . V_3 &= ~ V_43 ;
V_9 -> V_3 |= V_49 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_49 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_67 ( struct V_95 * V_96 , const char * V_74 ,
unsigned int V_17 )
{
struct V_8 * V_9 ;
int V_77 ;
if ( V_17 <= 0 )
return;
V_9 = V_89 [ 0 ] ;
while ( V_17 > 0 ) {
for ( V_77 = 0 ; V_77 < V_17 ; V_77 ++ )
if ( V_74 [ V_77 ] == '\t' || V_74 [ V_77 ] == '\n' )
break;
F_37 ( V_9 , V_74 , V_77 ) ;
V_17 -= V_77 ;
V_74 += V_77 ;
if ( V_17 > 0 ) {
F_41 ( V_9 , * V_74 ) ;
V_17 -- ;
V_74 ++ ;
}
}
}
static struct V_97 * F_68 ( struct V_95 * V_75 , int * V_98 )
{
* V_98 = V_75 -> V_98 ;
return V_99 ;
}
static void F_69 ( void )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = V_89 [ 0 ] ;
if ( V_9 -> V_42 . V_3 & V_43 )
if ( F_70 ( V_9 -> V_38 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_31 ( V_9 , V_29 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_71 ( struct V_100 * V_101 ,
unsigned long V_102 , void * V_50 )
{
F_69 () ;
return V_103 ;
}
static int T_1 F_72 ( void )
{
struct V_55 * V_38 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_77 ;
if ( ! V_104 )
return - V_94 ;
if ( V_105 ) {
F_73 ( L_3 , NULL , 0 , NULL ) ;
F_73 ( L_4 , NULL , 0 , NULL ) ;
}
V_5 = NULL ;
F_74 ( & V_4 ) ;
for ( V_77 = 0 ; V_77 < V_106 ; V_77 ++ ) {
V_2 = F_51 ( sizeof( struct V_1 ) , V_86 | V_87 ) ;
if ( ! V_2 )
return - V_90 ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
V_38 = F_75 ( & V_107 ) ;
if ( F_76 ( V_38 ) )
return - V_94 ;
V_89 [ 0 ] = V_9 = F_50 () ;
V_9 -> V_38 = V_38 ;
F_60 ( & V_38 -> V_60 , V_9 ) ;
V_38 -> V_91 = F_20 ;
V_9 -> V_3 |= V_82 ;
if ( F_77 ( V_38 ) ) {
F_78 ( V_38 ) ;
F_57 ( V_9 ) ;
V_89 [ 0 ] = NULL ;
return - V_94 ;
}
if ( F_43 ( V_9 ) != 0 ) {
F_57 ( V_9 ) ;
V_89 [ 0 ] = NULL ;
return - V_94 ;
}
F_79 ( & V_108 , & V_109 ) ;
F_80 ( & V_110 ) ;
F_81 ( & V_111 ) ;
return 0 ;
}
static int F_82 ( struct V_97 * V_112 , struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = V_89 [ V_52 -> V_98 ] ;
if ( V_9 == NULL )
return - V_94 ;
V_52 -> V_113 = V_9 ;
return F_83 ( & V_9 -> V_42 , V_112 , V_52 ) ;
}
static int F_84 ( struct V_51 * V_52 , struct V_114 * V_115 )
{
struct V_8 * V_9 = V_52 -> V_113 ;
int V_116 ;
F_85 ( & V_9 -> V_42 , V_52 ) ;
V_9 -> V_42 . V_117 = 0 ;
V_116 = F_43 ( V_9 ) ;
if ( V_116 )
return V_116 ;
return 0 ;
}
static void F_86 ( struct V_51 * V_52 , struct V_114 * V_115 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
if ( V_9 == NULL || V_52 -> V_17 > 1 )
return;
V_52 -> V_118 = 1 ;
F_44 ( V_9 ) ;
F_87 ( & V_9 -> V_54 ) ;
V_52 -> V_118 = 0 ;
F_85 ( & V_9 -> V_42 , NULL ) ;
}
static int F_88 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
if ( ( V_29 - V_9 -> V_17 - V_78 ) >= 0 )
return V_29 - V_9 -> V_17 - V_78 ;
else
return 0 ;
}
static int F_89 ( struct V_51 * V_52 ,
const unsigned char * V_119 , int V_17 )
{
struct V_8 * V_9 ;
int V_77 , V_24 ;
if ( ! V_52 )
return 0 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
V_24 = V_17 ;
while ( V_17 > 0 ) {
for ( V_77 = 0 ; V_77 < V_17 ; V_77 ++ )
if ( V_119 [ V_77 ] == '\t' || V_119 [ V_77 ] == '\n' )
break;
F_37 ( V_9 , V_119 , V_77 ) ;
V_17 -= V_77 ;
V_119 += V_77 ;
if ( V_17 > 0 ) {
F_41 ( V_9 , * V_119 ) ;
V_17 -- ;
V_119 ++ ;
}
}
return V_24 ;
}
static int F_90 ( struct V_51 * V_52 , unsigned char V_72 )
{
struct V_8 * V_9 ;
if ( ! V_52 )
return 0 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
F_41 ( V_9 , V_72 ) ;
return 1 ;
}
static void F_91 ( struct V_51 * V_52 )
{
}
static int F_92 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
return V_9 -> V_17 ;
}
static void F_93 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
F_42 ( V_9 ) ;
F_16 ( V_52 ) ;
}
static void F_94 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
V_9 -> V_3 |= V_37 ;
}
static void F_95 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
if ( V_9 -> V_3 & V_37 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_37 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_96 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
V_9 -> V_3 |= V_39 ;
}
static void F_97 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_52 -> V_113 ;
if ( V_9 -> V_3 & V_39 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_39 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static int T_1 F_98 ( void )
{
struct V_97 * V_112 ;
int V_120 ;
if ( ! V_104 )
return 0 ;
V_112 = F_99 ( V_93 ) ;
if ( ! V_112 )
return - V_90 ;
V_120 = F_100 ( & V_107 ) ;
if ( V_120 ) {
F_101 ( V_112 ) ;
return V_120 ;
}
V_112 -> V_121 = L_5 ;
V_112 -> V_122 = L_6 ;
V_112 -> V_123 = V_124 ;
V_112 -> V_125 = 64 ;
V_112 -> type = V_126 ;
V_112 -> V_127 = V_128 ;
V_112 -> V_129 = V_130 ;
V_112 -> V_129 . V_131 = V_132 | V_133 ;
V_112 -> V_129 . V_134 = V_135 ;
V_112 -> V_129 . V_136 = V_137 ;
V_112 -> V_3 = V_138 ;
F_102 ( V_112 , & V_139 ) ;
V_120 = F_103 ( V_112 ) ;
if ( V_120 ) {
F_101 ( V_112 ) ;
return V_120 ;
}
V_99 = V_112 ;
return 0 ;
}
static void T_2 F_104 ( void )
{
F_105 ( V_99 ) ;
F_101 ( V_99 ) ;
F_106 ( & V_107 ) ;
}
