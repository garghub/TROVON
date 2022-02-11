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
F_18 ( V_12 -> V_28 ) -> V_34 = F_6 ( V_1 + V_6 ) ;
F_6 ( V_1 + V_7 ) ;
switch ( F_18 ( V_12 -> V_28 ) -> V_34 ) {
case V_35 :
V_12 -> V_29 = V_36 ;
V_12 -> V_31 = V_37 ;
break;
case V_38 :
V_12 -> V_29 = V_39 ;
V_12 -> V_31 = V_40 ;
break;
case V_41 :
V_12 -> V_29 = V_42 ;
V_12 -> V_31 = V_43 ;
break;
default:
F_10 ( L_4 , F_18 ( V_12 -> V_28 ) -> V_34 ) ;
V_12 -> V_22 -> V_23 . V_44 ++ ;
F_14 ( V_45 , & ( V_12 -> V_22 -> V_46 ) ) ;
F_15 ( V_12 -> V_28 ) ;
V_12 -> V_28 = NULL ;
break;
}
} else {
T_1 V_47 = F_6 ( V_1 + V_6 ) ;
* F_19 ( V_12 -> V_28 , 1 ) = V_47 ;
F_6 ( V_1 + V_7 ) ;
V_12 -> V_31 -- ;
if ( V_12 -> V_31 == 0 ) {
int V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
switch ( V_12 -> V_29 ) {
case V_36 :
V_50 = V_49 ( V_12 -> V_28 ) ;
V_12 -> V_29 = V_55 ;
V_12 -> V_31 = V_50 -> V_56 ;
break;
case V_39 :
V_52 = V_51 ( V_12 -> V_28 ) ;
V_48 = F_20 ( V_52 -> V_48 ) ;
V_12 -> V_29 = V_55 ;
V_12 -> V_31 = V_48 ;
break;
case V_42 :
V_54 = V_53 ( V_12 -> V_28 ) ;
V_12 -> V_29 = V_55 ;
V_12 -> V_31 = V_54 -> V_48 ;
break;
case V_55 :
F_21 ( V_12 -> V_22 , V_12 -> V_28 ) ;
V_12 -> V_28 = NULL ;
break;
}
}
}
}
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
}
static T_3 F_22 ( int V_57 , void * V_58 )
{
T_2 * V_12 = V_58 ;
unsigned int V_1 ;
int V_59 ;
T_3 V_60 = V_61 ;
if ( ! V_12 || ! V_12 -> V_22 )
return V_61 ;
V_1 = V_12 -> V_15 -> V_16 [ 0 ] -> V_17 ;
F_23 ( & ( V_12 -> V_62 ) ) ;
V_59 = F_6 ( V_1 + V_63 ) ;
if ( V_59 & 0x80 ) {
int V_23 = F_7 ( V_1 , 0x7001 ) ;
if ( ( V_23 & 0xff ) == 0x7f ) {
F_10 ( L_5 , V_23 ) ;
} else if ( ( V_23 & 0xff ) != 0xff ) {
if ( V_23 & 0x0020 ) {
int V_64 = F_7 ( V_1 , 0x7002 ) & 0x10 ;
F_24 ( L_6 , V_12 -> V_22 -> V_65 ,
V_64 ? L_7 : L_8 ) ;
}
if ( V_23 & 0x0001 )
F_16 ( V_12 ) ;
if ( V_23 & 0x0002 ) {
F_14 ( V_13 , & ( V_12 -> V_14 ) ) ;
F_9 ( V_12 ) ;
}
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
F_2 ( V_59 , V_1 + V_63 ) ;
}
V_60 = V_66 ;
}
F_25 ( & ( V_12 -> V_62 ) ) ;
return V_60 ;
}
static int F_26 ( struct V_67 * V_22 )
{
T_2 * V_12 = F_27 ( V_22 ) ;
F_28 ( & ( V_12 -> V_20 ) ) ;
return 0 ;
}
static int F_29 ( struct V_67 * V_22 )
{
F_30 ( V_45 , & ( V_22 -> V_46 ) ) ;
return 0 ;
}
static int F_31 ( struct V_67 * V_22 )
{
if ( ! F_32 ( V_45 , & ( V_22 -> V_46 ) ) )
return 0 ;
F_26 ( V_22 ) ;
return 0 ;
}
static int F_33 ( struct V_67 * V_22 , struct V_18 * V_19 )
{
T_2 * V_12 = F_27 ( V_22 ) ;
unsigned long V_46 ;
switch ( F_18 ( V_19 ) -> V_34 ) {
case V_68 :
V_22 -> V_23 . V_69 ++ ;
break;
case V_38 :
V_22 -> V_23 . V_70 ++ ;
break;
case V_41 :
V_22 -> V_23 . V_71 ++ ;
break;
} ;
memcpy ( F_34 ( V_19 , 1 ) , & F_18 ( V_19 ) -> V_34 , 1 ) ;
F_35 ( & ( V_12 -> V_20 ) , V_19 ) ;
F_36 ( & ( V_12 -> V_62 ) , V_46 ) ;
F_9 ( V_12 ) ;
F_37 ( & ( V_12 -> V_62 ) , V_46 ) ;
return 0 ;
}
static int F_38 ( T_2 * V_12 , const unsigned char * V_72 ,
int V_73 )
{
char * V_74 = ( char * ) V_72 ;
char V_75 [ 9 ] ;
unsigned int V_1 , V_25 , V_2 , V_76 , V_77 ;
int V_78 , V_79 = 0 ;
V_1 = V_12 -> V_15 -> V_16 [ 0 ] -> V_17 ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_4 ( V_1 , 0x8040 , 0x0400 ) ;
F_39 ( 1 ) ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_39 ( 17 ) ;
while ( V_73 ) {
if ( V_74 [ 0 ] != 'S' ) {
F_10 ( L_9 ) ;
V_79 = - V_80 ;
goto error;
}
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
memcpy ( V_75 , V_74 + 2 , 2 ) ;
V_25 = F_40 ( V_75 , NULL , 16 ) ;
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
memcpy ( V_75 , V_74 + 4 , 8 ) ;
V_2 = F_40 ( V_75 , NULL , 16 ) ;
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
memcpy ( V_75 , V_74 + ( V_25 * 2 ) + 2 , 2 ) ;
V_76 = F_40 ( V_75 , NULL , 16 ) ;
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
for ( V_77 = 0 , V_78 = 0 ; V_78 < V_25 ; V_78 ++ ) {
memcpy ( V_75 , V_74 + ( V_78 * 2 ) + 2 , 2 ) ;
V_77 += F_41 ( V_75 , NULL , 16 ) ;
}
if ( ( ( V_77 + V_76 ) & 0xff ) != 0xff ) {
F_10 ( L_10 ) ;
V_79 = - V_81 ;
goto error;
}
if ( V_74 [ 1 ] == '3' ) {
F_1 ( V_1 , V_2 ) ;
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
for ( V_78 = 0 ; V_78 < ( V_25 - 4 ) / 2 ; V_78 ++ ) {
memcpy ( V_75 , V_74 + ( V_78 * 4 ) + 12 , 4 ) ;
V_77 = F_40 ( V_75 , NULL , 16 ) ;
F_3 ( V_1 , V_77 ) ;
}
}
V_74 += ( V_25 * 2 ) + 6 ;
V_73 -= ( V_25 * 2 ) + 6 ;
}
F_39 ( 17 ) ;
F_1 ( V_1 , 0x3000 ) ;
F_2 ( F_6 ( V_1 + V_63 ) | 0x40 , V_1 + V_63 ) ;
error:
F_39 ( 17 ) ;
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
F_4 ( V_1 , 0x7005 , 0x0000 ) ;
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
return V_79 ;
}
static int F_42 ( T_2 * V_12 )
{
const struct V_72 * V_72 ;
struct V_67 * V_22 ;
int V_79 ;
F_43 ( & ( V_12 -> V_62 ) ) ;
F_44 ( & ( V_12 -> V_20 ) ) ;
V_12 -> V_29 = V_30 ;
V_12 -> V_31 = 0 ;
V_12 -> V_28 = NULL ;
V_22 = F_45 () ;
if ( ! V_22 ) {
F_10 ( L_11 ) ;
return - V_82 ;
}
V_12 -> V_22 = V_22 ;
V_22 -> V_83 = V_84 ;
F_46 ( V_22 , V_12 ) ;
F_47 ( V_22 , & V_12 -> V_15 -> V_85 ) ;
V_22 -> V_86 = F_29 ;
V_22 -> V_87 = F_31 ;
V_22 -> V_88 = F_26 ;
V_22 -> V_89 = F_33 ;
V_79 = F_48 ( & V_72 , L_12 , & V_12 -> V_15 -> V_85 ) ;
if ( V_79 < 0 ) {
F_10 ( L_13 ) ;
goto error;
}
V_79 = F_38 ( V_12 , V_72 -> V_21 , V_72 -> V_25 ) ;
F_49 ( V_72 ) ;
if ( V_79 < 0 ) {
F_10 ( L_14 ) ;
goto error;
}
F_50 ( 1000 ) ;
V_79 = F_51 ( V_22 ) ;
if ( V_79 < 0 ) {
F_10 ( L_15 ) ;
goto error;
}
return 0 ;
error:
V_12 -> V_22 = NULL ;
F_52 ( V_22 ) ;
return V_79 ;
}
static int F_53 ( T_2 * V_12 )
{
struct V_67 * V_22 = V_12 -> V_22 ;
if ( ! V_22 )
return - V_90 ;
F_31 ( V_22 ) ;
F_54 ( V_22 ) ;
F_52 ( V_22 ) ;
return 0 ;
}
static int F_55 ( struct V_91 * V_92 )
{
T_2 * V_12 ;
V_12 = F_56 ( & V_92 -> V_85 , sizeof( * V_12 ) , V_93 ) ;
if ( ! V_12 )
return - V_82 ;
V_12 -> V_15 = V_92 ;
V_92 -> V_94 = V_12 ;
V_92 -> V_95 |= V_96 | V_97 |
V_98 ;
return F_57 ( V_92 ) ;
}
static void F_58 ( struct V_91 * V_92 )
{
F_59 ( V_92 ) ;
}
static int F_60 ( struct V_91 * V_15 , void * V_99 )
{
int * V_100 = V_99 ;
if ( ! V_100 )
V_15 -> V_101 = 16 ;
if ( ( V_15 -> V_16 [ 0 ] -> V_102 != 8 ) || ( V_15 -> V_16 [ 0 ] -> V_17 == 0 ) )
return - V_103 ;
V_15 -> V_16 [ 0 ] -> V_102 = 8 ;
V_15 -> V_16 [ 0 ] -> V_46 &= ~ V_104 ;
V_15 -> V_16 [ 0 ] -> V_46 |= V_105 ;
return F_61 ( V_15 ) ;
}
static int F_62 ( struct V_91 * V_15 ,
void * V_99 )
{
static unsigned int V_106 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_107 ;
if ( V_15 -> V_101 > 3 )
return - V_90 ;
V_15 -> V_16 [ 0 ] -> V_46 &= ~ V_104 ;
V_15 -> V_16 [ 0 ] -> V_46 |= V_105 ;
V_15 -> V_16 [ 0 ] -> V_102 = 8 ;
for ( V_107 = 0 ; V_107 < 5 ; V_107 ++ ) {
V_15 -> V_16 [ 0 ] -> V_17 = V_106 [ V_107 ] ;
V_15 -> V_101 = V_106 [ V_107 ] ? 16 : 3 ;
if ( ! F_61 ( V_15 ) )
return 0 ;
}
return - V_90 ;
}
static int F_57 ( struct V_91 * V_92 )
{
T_2 * V_12 = V_92 -> V_94 ;
int V_78 ;
unsigned long V_100 ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ )
if ( ! F_63 ( V_92 , F_60 , ( void * ) V_100 ) )
goto V_108;
if ( ! F_63 ( V_92 , F_62 , NULL ) )
goto V_108;
F_10 ( L_16 ) ;
goto V_109;
V_108:
V_78 = F_64 ( V_92 , & F_22 ) ;
if ( V_78 != 0 )
goto V_109;
V_78 = F_65 ( V_92 ) ;
if ( V_78 != 0 )
goto V_109;
if ( F_42 ( V_12 ) != 0 )
goto V_109;
return 0 ;
V_109:
F_59 ( V_92 ) ;
return - V_90 ;
}
static void F_59 ( struct V_91 * V_92 )
{
T_2 * V_12 = V_92 -> V_94 ;
F_53 ( V_12 ) ;
F_66 ( V_92 ) ;
}
