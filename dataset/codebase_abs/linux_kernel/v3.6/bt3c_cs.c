static inline void F_1 ( unsigned int V_1 , unsigned short V_2 )
{
F_2 ( V_2 & 0xff , V_1 + V_3 ) ;
F_2 ( ( V_2 >> 8 ) & 0xff , V_1 + V_4 ) ;
}
static inline void F_3 ( unsigned int V_1 , unsigned short V_5 )
{
F_2 ( V_5 & 0xff , V_1 + V_6 ) ;
F_2 ( ( V_5 >> 8 ) & 0xff , V_1 + V_7 ) ;
}
static inline void F_4 ( unsigned int V_1 , unsigned short V_2 , unsigned short V_5 )
{
F_1 ( V_1 , V_2 ) ;
F_3 ( V_1 , V_5 ) ;
}
static inline unsigned short F_5 ( unsigned int V_1 )
{
unsigned short V_5 = F_6 ( V_1 + V_6 ) ;
V_5 |= F_6 ( V_1 + V_7 ) << 8 ;
return V_5 ;
}
static inline unsigned short F_7 ( unsigned int V_1 , unsigned short V_2 )
{
F_1 ( V_1 , V_2 ) ;
return F_5 ( V_1 ) ;
}
static int F_8 ( unsigned int V_1 , int V_8 , T_1 * V_9 , int V_10 )
{
int V_11 = 0 ;
F_1 ( V_1 , 0x7080 ) ;
while ( V_11 < V_10 ) {
F_3 ( V_1 , V_9 [ V_11 ] ) ;
V_11 ++ ;
}
F_4 ( V_1 , 0x7005 , V_11 ) ;
return V_11 ;
}
static void F_9 ( T_2 * V_12 )
{
if ( ! V_12 ) {
F_10 ( L_1 ) ;
return;
}
if ( F_11 ( V_13 , & ( V_12 -> V_14 ) ) )
return;
do {
unsigned int V_1 = V_12 -> V_15 -> V_16 [ 0 ] -> V_17 ;
register struct V_18 * V_19 ;
int V_10 ;
if ( ! F_12 ( V_12 -> V_15 ) )
break;
if ( ! ( V_19 = F_13 ( & ( V_12 -> V_20 ) ) ) ) {
F_14 ( V_13 , & ( V_12 -> V_14 ) ) ;
break;
}
V_10 = F_8 ( V_1 , 256 , V_19 -> V_21 , V_19 -> V_10 ) ;
if ( V_10 != V_19 -> V_10 ) {
F_10 ( L_2 ) ;
}
F_15 ( V_19 ) ;
V_12 -> V_22 -> V_23 . V_24 += V_10 ;
} while ( 0 );
}
static void F_16 ( T_2 * V_12 )
{
unsigned int V_1 ;
int V_25 = 0 , V_26 ;
if ( ! V_12 ) {
F_10 ( L_1 ) ;
return;
}
V_1 = V_12 -> V_15 -> V_16 [ 0 ] -> V_17 ;
V_26 = F_7 ( V_1 , 0x7006 ) ;
F_1 ( V_1 , 0x7480 ) ;
while ( V_25 < V_26 ) {
V_25 ++ ;
V_12 -> V_22 -> V_23 . V_27 ++ ;
if ( V_12 -> V_28 == NULL ) {
V_12 -> V_29 = V_30 ;
V_12 -> V_31 = 0 ;
if ( ! ( V_12 -> V_28 = F_17 ( V_32 , V_33 ) ) ) {
F_10 ( L_3 ) ;
return;
}
}
if ( V_12 -> V_29 == V_30 ) {
V_12 -> V_28 -> V_34 = ( void * ) V_12 -> V_22 ;
F_18 ( V_12 -> V_28 ) -> V_35 = F_6 ( V_1 + V_6 ) ;
F_6 ( V_1 + V_7 ) ;
switch ( F_18 ( V_12 -> V_28 ) -> V_35 ) {
case V_36 :
V_12 -> V_29 = V_37 ;
V_12 -> V_31 = V_38 ;
break;
case V_39 :
V_12 -> V_29 = V_40 ;
V_12 -> V_31 = V_41 ;
break;
case V_42 :
V_12 -> V_29 = V_43 ;
V_12 -> V_31 = V_44 ;
break;
default:
F_10 ( L_4 , F_18 ( V_12 -> V_28 ) -> V_35 ) ;
V_12 -> V_22 -> V_23 . V_45 ++ ;
F_14 ( V_46 , & ( V_12 -> V_22 -> V_47 ) ) ;
F_15 ( V_12 -> V_28 ) ;
V_12 -> V_28 = NULL ;
break;
}
} else {
T_1 V_48 = F_6 ( V_1 + V_6 ) ;
* F_19 ( V_12 -> V_28 , 1 ) = V_48 ;
F_6 ( V_1 + V_7 ) ;
V_12 -> V_31 -- ;
if ( V_12 -> V_31 == 0 ) {
int V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
switch ( V_12 -> V_29 ) {
case V_37 :
V_51 = V_50 ( V_12 -> V_28 ) ;
V_12 -> V_29 = V_56 ;
V_12 -> V_31 = V_51 -> V_57 ;
break;
case V_40 :
V_53 = V_52 ( V_12 -> V_28 ) ;
V_49 = F_20 ( V_53 -> V_49 ) ;
V_12 -> V_29 = V_56 ;
V_12 -> V_31 = V_49 ;
break;
case V_43 :
V_55 = V_54 ( V_12 -> V_28 ) ;
V_12 -> V_29 = V_56 ;
V_12 -> V_31 = V_55 -> V_49 ;
break;
case V_56 :
F_21 ( V_12 -> V_28 ) ;
V_12 -> V_28 = NULL ;
break;
}
}
}
}
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
}
static T_3 F_22 ( int V_58 , void * V_59 )
{
T_2 * V_12 = V_59 ;
unsigned int V_1 ;
int V_60 ;
T_3 V_61 = V_62 ;
if ( ! V_12 || ! V_12 -> V_22 )
return V_62 ;
V_1 = V_12 -> V_15 -> V_16 [ 0 ] -> V_17 ;
F_23 ( & ( V_12 -> V_63 ) ) ;
V_60 = F_6 ( V_1 + V_64 ) ;
if ( V_60 & 0x80 ) {
int V_23 = F_7 ( V_1 , 0x7001 ) ;
if ( ( V_23 & 0xff ) == 0x7f ) {
F_10 ( L_5 , V_23 ) ;
} else if ( ( V_23 & 0xff ) != 0xff ) {
if ( V_23 & 0x0020 ) {
int V_65 = F_7 ( V_1 , 0x7002 ) & 0x10 ;
F_24 ( L_6 , V_12 -> V_22 -> V_66 ,
V_65 ? L_7 : L_8 ) ;
}
if ( V_23 & 0x0001 )
F_16 ( V_12 ) ;
if ( V_23 & 0x0002 ) {
F_14 ( V_13 , & ( V_12 -> V_14 ) ) ;
F_9 ( V_12 ) ;
}
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
F_2 ( V_60 , V_1 + V_64 ) ;
}
V_61 = V_67 ;
}
F_25 ( & ( V_12 -> V_63 ) ) ;
return V_61 ;
}
static int F_26 ( struct V_68 * V_22 )
{
T_2 * V_12 = F_27 ( V_22 ) ;
F_28 ( & ( V_12 -> V_20 ) ) ;
return 0 ;
}
static int F_29 ( struct V_68 * V_22 )
{
F_30 ( V_46 , & ( V_22 -> V_47 ) ) ;
return 0 ;
}
static int F_31 ( struct V_68 * V_22 )
{
if ( ! F_32 ( V_46 , & ( V_22 -> V_47 ) ) )
return 0 ;
F_26 ( V_22 ) ;
return 0 ;
}
static int F_33 ( struct V_18 * V_19 )
{
T_2 * V_12 ;
struct V_68 * V_22 = (struct V_68 * ) ( V_19 -> V_34 ) ;
unsigned long V_47 ;
if ( ! V_22 ) {
F_10 ( L_9 ) ;
return - V_69 ;
}
V_12 = F_27 ( V_22 ) ;
switch ( F_18 ( V_19 ) -> V_35 ) {
case V_70 :
V_22 -> V_23 . V_71 ++ ;
break;
case V_39 :
V_22 -> V_23 . V_72 ++ ;
break;
case V_42 :
V_22 -> V_23 . V_73 ++ ;
break;
} ;
memcpy ( F_34 ( V_19 , 1 ) , & F_18 ( V_19 ) -> V_35 , 1 ) ;
F_35 ( & ( V_12 -> V_20 ) , V_19 ) ;
F_36 ( & ( V_12 -> V_63 ) , V_47 ) ;
F_9 ( V_12 ) ;
F_37 ( & ( V_12 -> V_63 ) , V_47 ) ;
return 0 ;
}
static int F_38 ( struct V_68 * V_22 , unsigned int V_74 , unsigned long V_75 )
{
return - V_76 ;
}
static int F_39 ( T_2 * V_12 , const unsigned char * V_77 ,
int V_78 )
{
char * V_79 = ( char * ) V_77 ;
char V_80 [ 9 ] ;
unsigned int V_1 , V_25 , V_2 , V_81 , V_82 ;
int V_83 , V_84 = 0 ;
V_1 = V_12 -> V_15 -> V_16 [ 0 ] -> V_17 ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_4 ( V_1 , 0x8040 , 0x0400 ) ;
F_40 ( 1 ) ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_40 ( 17 ) ;
while ( V_78 ) {
if ( V_79 [ 0 ] != 'S' ) {
F_10 ( L_10 ) ;
V_84 = - V_85 ;
goto error;
}
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
memcpy ( V_80 , V_79 + 2 , 2 ) ;
V_25 = F_41 ( V_80 , NULL , 16 ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
memcpy ( V_80 , V_79 + 4 , 8 ) ;
V_2 = F_41 ( V_80 , NULL , 16 ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
memcpy ( V_80 , V_79 + ( V_25 * 2 ) + 2 , 2 ) ;
V_81 = F_41 ( V_80 , NULL , 16 ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
for ( V_82 = 0 , V_83 = 0 ; V_83 < V_25 ; V_83 ++ ) {
memcpy ( V_80 , V_79 + ( V_83 * 2 ) + 2 , 2 ) ;
V_82 += F_42 ( V_80 , NULL , 16 ) ;
}
if ( ( ( V_82 + V_81 ) & 0xff ) != 0xff ) {
F_10 ( L_11 ) ;
V_84 = - V_86 ;
goto error;
}
if ( V_79 [ 1 ] == '3' ) {
F_1 ( V_1 , V_2 ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
for ( V_83 = 0 ; V_83 < ( V_25 - 4 ) / 2 ; V_83 ++ ) {
memcpy ( V_80 , V_79 + ( V_83 * 4 ) + 12 , 4 ) ;
V_82 = F_41 ( V_80 , NULL , 16 ) ;
F_3 ( V_1 , V_82 ) ;
}
}
V_79 += ( V_25 * 2 ) + 6 ;
V_78 -= ( V_25 * 2 ) + 6 ;
}
F_40 ( 17 ) ;
F_1 ( V_1 , 0x3000 ) ;
F_2 ( F_6 ( V_1 + V_64 ) | 0x40 , V_1 + V_64 ) ;
error:
F_40 ( 17 ) ;
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
F_4 ( V_1 , 0x7005 , 0x0000 ) ;
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
return V_84 ;
}
static int F_43 ( T_2 * V_12 )
{
const struct V_77 * V_77 ;
struct V_68 * V_22 ;
int V_84 ;
F_44 ( & ( V_12 -> V_63 ) ) ;
F_45 ( & ( V_12 -> V_20 ) ) ;
V_12 -> V_29 = V_30 ;
V_12 -> V_31 = 0 ;
V_12 -> V_28 = NULL ;
V_22 = F_46 () ;
if ( ! V_22 ) {
F_10 ( L_12 ) ;
return - V_87 ;
}
V_12 -> V_22 = V_22 ;
V_22 -> V_88 = V_89 ;
F_47 ( V_22 , V_12 ) ;
F_48 ( V_22 , & V_12 -> V_15 -> V_34 ) ;
V_22 -> V_90 = F_29 ;
V_22 -> V_91 = F_31 ;
V_22 -> V_92 = F_26 ;
V_22 -> V_93 = F_33 ;
V_22 -> V_94 = F_38 ;
V_84 = F_49 ( & V_77 , L_13 , & V_12 -> V_15 -> V_34 ) ;
if ( V_84 < 0 ) {
F_10 ( L_14 ) ;
goto error;
}
V_84 = F_39 ( V_12 , V_77 -> V_21 , V_77 -> V_25 ) ;
F_50 ( V_77 ) ;
if ( V_84 < 0 ) {
F_10 ( L_15 ) ;
goto error;
}
F_51 ( 1000 ) ;
V_84 = F_52 ( V_22 ) ;
if ( V_84 < 0 ) {
F_10 ( L_16 ) ;
goto error;
}
return 0 ;
error:
V_12 -> V_22 = NULL ;
F_53 ( V_22 ) ;
return V_84 ;
}
static int F_54 ( T_2 * V_12 )
{
struct V_68 * V_22 = V_12 -> V_22 ;
if ( ! V_22 )
return - V_69 ;
F_31 ( V_22 ) ;
F_55 ( V_22 ) ;
F_53 ( V_22 ) ;
return 0 ;
}
static int F_56 ( struct V_95 * V_96 )
{
T_2 * V_12 ;
V_12 = F_57 ( sizeof( * V_12 ) , V_97 ) ;
if ( ! V_12 )
return - V_87 ;
V_12 -> V_15 = V_96 ;
V_96 -> V_98 = V_12 ;
V_96 -> V_99 |= V_100 | V_101 |
V_102 ;
return F_58 ( V_96 ) ;
}
static void F_59 ( struct V_95 * V_96 )
{
T_2 * V_12 = V_96 -> V_98 ;
F_60 ( V_96 ) ;
F_61 ( V_12 ) ;
}
static int F_62 ( struct V_95 * V_15 , void * V_103 )
{
int * V_104 = V_103 ;
if ( ! V_104 )
V_15 -> V_105 = 16 ;
if ( ( V_15 -> V_16 [ 0 ] -> V_106 != 8 ) || ( V_15 -> V_16 [ 0 ] -> V_17 == 0 ) )
return - V_107 ;
V_15 -> V_16 [ 0 ] -> V_106 = 8 ;
V_15 -> V_16 [ 0 ] -> V_47 &= ~ V_108 ;
V_15 -> V_16 [ 0 ] -> V_47 |= V_109 ;
return F_63 ( V_15 ) ;
}
static int F_64 ( struct V_95 * V_15 ,
void * V_103 )
{
static unsigned int V_110 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_111 ;
if ( V_15 -> V_105 > 3 )
return - V_69 ;
V_15 -> V_16 [ 0 ] -> V_47 &= ~ V_108 ;
V_15 -> V_16 [ 0 ] -> V_47 |= V_109 ;
V_15 -> V_16 [ 0 ] -> V_106 = 8 ;
for ( V_111 = 0 ; V_111 < 5 ; V_111 ++ ) {
V_15 -> V_16 [ 0 ] -> V_17 = V_110 [ V_111 ] ;
V_15 -> V_105 = V_110 [ V_111 ] ? 16 : 3 ;
if ( ! F_63 ( V_15 ) )
return 0 ;
}
return - V_69 ;
}
static int F_58 ( struct V_95 * V_96 )
{
T_2 * V_12 = V_96 -> V_98 ;
int V_83 ;
unsigned long V_104 ;
for ( V_104 = 0 ; V_104 < 2 ; V_104 ++ )
if ( ! F_65 ( V_96 , F_62 , ( void * ) V_104 ) )
goto V_112;
if ( ! F_65 ( V_96 , F_64 , NULL ) )
goto V_112;
F_10 ( L_17 ) ;
goto V_113;
V_112:
V_83 = F_66 ( V_96 , & F_22 ) ;
if ( V_83 != 0 )
goto V_113;
V_83 = F_67 ( V_96 ) ;
if ( V_83 != 0 )
goto V_113;
if ( F_43 ( V_12 ) != 0 )
goto V_113;
return 0 ;
V_113:
F_60 ( V_96 ) ;
return - V_69 ;
}
static void F_60 ( struct V_95 * V_96 )
{
T_2 * V_12 = V_96 -> V_98 ;
F_54 ( V_12 ) ;
F_68 ( V_96 ) ;
}
static int T_4 F_69 ( void )
{
return F_70 ( & V_114 ) ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_114 ) ;
}
