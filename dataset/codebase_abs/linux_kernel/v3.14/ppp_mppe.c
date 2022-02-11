static unsigned int
F_1 ( struct V_1 * V_2 , const void * V_3 , unsigned int V_4 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_3 ( struct V_5 * V_6 )
{
memset ( V_6 -> V_7 , 0x00 , sizeof( V_6 -> V_7 ) ) ;
memset ( V_6 -> V_8 , 0xF2 , sizeof( V_6 -> V_8 ) ) ;
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
struct V_1 V_2 [ 4 ] ;
unsigned int V_13 ;
F_5 ( V_2 , 4 ) ;
V_13 = F_1 ( & V_2 [ 0 ] , V_10 -> V_14 , V_10 -> V_15 ) ;
V_13 += F_1 ( & V_2 [ 1 ] , V_5 -> V_7 ,
sizeof( V_5 -> V_7 ) ) ;
V_13 += F_1 ( & V_2 [ 2 ] , V_10 -> V_16 , V_10 -> V_15 ) ;
V_13 += F_1 ( & V_2 [ 3 ] , V_5 -> V_8 ,
sizeof( V_5 -> V_8 ) ) ;
V_12 . V_17 = V_10 -> V_18 ;
V_12 . V_19 = 0 ;
F_6 ( & V_12 , V_2 , V_13 , V_10 -> V_20 ) ;
}
static void F_7 ( struct V_9 * V_10 , int V_21 )
{
struct V_1 V_22 [ 1 ] , V_23 [ 1 ] ;
struct V_24 V_12 = { . V_17 = V_10 -> V_25 } ;
F_4 ( V_10 ) ;
if ( ! V_21 ) {
F_8 ( V_10 -> V_25 , V_10 -> V_20 ,
V_10 -> V_15 ) ;
F_5 ( V_22 , 1 ) ;
F_5 ( V_23 , 1 ) ;
F_1 ( V_22 , V_10 -> V_20 , V_10 -> V_15 ) ;
F_1 ( V_23 , V_10 -> V_16 , V_10 -> V_15 ) ;
if ( F_9 ( & V_12 , V_23 , V_22 ,
V_10 -> V_15 ) != 0 ) {
F_10 ( V_26 L_1 ) ;
}
} else {
memcpy ( V_10 -> V_16 , V_10 -> V_20 , V_10 -> V_15 ) ;
}
if ( V_10 -> V_15 == 8 ) {
V_10 -> V_16 [ 0 ] = 0xd1 ;
V_10 -> V_16 [ 1 ] = 0x26 ;
V_10 -> V_16 [ 2 ] = 0x9e ;
}
F_8 ( V_10 -> V_25 , V_10 -> V_16 , V_10 -> V_15 ) ;
}
static void * F_11 ( unsigned char * V_27 , int V_28 )
{
struct V_9 * V_10 ;
unsigned int V_29 ;
if ( V_28 != V_30 + sizeof( V_10 -> V_14 ) ||
V_27 [ 0 ] != V_31 || V_27 [ 1 ] != V_30 )
goto V_32;
V_10 = F_12 ( sizeof( * V_10 ) , V_33 ) ;
if ( V_10 == NULL )
goto V_32;
V_10 -> V_25 = F_13 ( L_2 , 0 , V_34 ) ;
if ( F_14 ( V_10 -> V_25 ) ) {
V_10 -> V_25 = NULL ;
goto V_35;
}
V_10 -> V_18 = F_15 ( L_3 , 0 , V_34 ) ;
if ( F_14 ( V_10 -> V_18 ) ) {
V_10 -> V_18 = NULL ;
goto V_35;
}
V_29 = F_16 ( V_10 -> V_18 ) ;
if ( V_29 < V_36 )
goto V_35;
V_10 -> V_20 = F_17 ( V_29 , V_33 ) ;
if ( ! V_10 -> V_20 )
goto V_35;
memcpy ( V_10 -> V_14 , & V_27 [ V_30 ] ,
sizeof( V_10 -> V_14 ) ) ;
memcpy ( V_10 -> V_16 , V_10 -> V_14 ,
sizeof( V_10 -> V_14 ) ) ;
return ( void * ) V_10 ;
V_35:
if ( V_10 -> V_20 )
F_18 ( V_10 -> V_20 ) ;
if ( V_10 -> V_18 )
F_19 ( V_10 -> V_18 ) ;
if ( V_10 -> V_25 )
F_20 ( V_10 -> V_25 ) ;
F_18 ( V_10 ) ;
V_32:
return NULL ;
}
static void F_21 ( void * V_37 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
if ( V_10 ) {
if ( V_10 -> V_20 )
F_18 ( V_10 -> V_20 ) ;
if ( V_10 -> V_18 )
F_19 ( V_10 -> V_18 ) ;
if ( V_10 -> V_25 )
F_20 ( V_10 -> V_25 ) ;
F_18 ( V_10 ) ;
}
}
static int
F_22 ( void * V_37 , unsigned char * V_27 , int V_28 , int V_38 , int V_39 ,
const char * V_40 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
unsigned char V_41 ;
if ( V_28 != V_30 ||
V_27 [ 0 ] != V_31 || V_27 [ 1 ] != V_30 )
return 0 ;
F_23 ( & V_27 [ 2 ] , V_41 ) ;
if ( V_41 & V_42 )
V_10 -> V_15 = 16 ;
else if ( V_41 & V_43 )
V_10 -> V_15 = 8 ;
else {
F_10 ( V_26 L_4 , V_40 ,
V_38 ) ;
return 0 ;
}
if ( V_41 & V_44 )
V_10 -> V_45 = 1 ;
F_7 ( V_10 , 1 ) ;
if ( V_39 ) {
int V_46 ;
char V_47 [ sizeof( V_10 -> V_14 ) * 2 + 1 ] ;
char V_48 [ sizeof( V_10 -> V_16 ) * 2 + 1 ] ;
F_10 ( V_49 L_5 ,
V_40 , V_38 , ( V_10 -> V_15 == 16 ) ? 128 : 40 ,
( V_10 -> V_45 ) ? L_6 : L_7 ) ;
for ( V_46 = 0 ; V_46 < sizeof( V_10 -> V_14 ) ; V_46 ++ )
sprintf ( V_47 + V_46 * 2 , L_8 , V_10 -> V_14 [ V_46 ] ) ;
for ( V_46 = 0 ; V_46 < sizeof( V_10 -> V_16 ) ; V_46 ++ )
sprintf ( V_48 + V_46 * 2 , L_8 , V_10 -> V_16 [ V_46 ] ) ;
F_10 ( V_49
L_9 ,
V_40 , V_38 , V_47 , V_48 ) ;
}
V_10 -> V_50 = V_51 - 1 ;
V_10 -> V_52 = V_53 ;
V_10 -> V_38 = V_38 ;
V_10 -> V_39 = V_39 ;
return 1 ;
}
static int
F_24 ( void * V_37 , unsigned char * V_27 , int V_28 , int V_38 ,
int V_54 , int V_39 )
{
return F_22 ( V_37 , V_27 , V_28 , V_38 , V_39 , L_10 ) ;
}
static void F_25 ( void * V_37 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
V_10 -> V_52 |= V_55 ;
}
static int
F_26 ( void * V_37 , unsigned char * V_56 , unsigned char * V_57 ,
int V_58 , int V_59 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
struct V_24 V_12 = { . V_17 = V_10 -> V_25 } ;
int V_60 ;
struct V_1 V_22 [ 1 ] , V_23 [ 1 ] ;
V_60 = F_27 ( V_56 ) ;
if ( V_60 < 0x0021 || V_60 > 0x00fa )
return 0 ;
if ( V_59 < V_58 + V_61 + 2 ) {
F_10 ( V_49 L_11
L_12 , V_10 -> V_38 ,
V_59 , V_59 + V_61 + 2 ) ;
return - 1 ;
}
V_59 = V_58 + V_61 + 2 ;
V_57 [ 0 ] = F_28 ( V_56 ) ;
V_57 [ 1 ] = F_29 ( V_56 ) ;
F_30 ( V_62 , V_57 + 2 ) ;
V_57 += V_63 ;
V_10 -> V_50 = ( V_10 -> V_50 + 1 ) % V_51 ;
if ( V_10 -> V_39 >= 7 )
F_10 ( V_49 L_13 , V_10 -> V_38 ,
V_10 -> V_50 ) ;
F_30 ( V_10 -> V_50 , V_57 ) ;
if ( ! V_10 -> V_45 ||
( ( V_10 -> V_50 & 0xff ) == 0xff ) ||
( V_10 -> V_52 & V_55 ) ) {
if ( V_10 -> V_39 && V_10 -> V_45 )
F_10 ( V_49 L_14 ,
V_10 -> V_38 ) ;
F_7 ( V_10 , 0 ) ;
V_10 -> V_52 |= V_55 ;
}
V_57 [ 0 ] |= V_10 -> V_52 ;
V_10 -> V_52 &= ~ V_55 ;
V_57 += V_61 ;
V_56 += 2 ;
V_58 -= 2 ;
F_5 ( V_22 , 1 ) ;
F_5 ( V_23 , 1 ) ;
F_1 ( V_22 , V_56 , V_58 ) ;
F_1 ( V_23 , V_57 , V_59 ) ;
if ( F_9 ( & V_12 , V_23 , V_22 , V_58 ) != 0 ) {
F_10 ( V_49 L_15 ) ;
return - 1 ;
}
V_10 -> V_64 . V_65 += V_58 ;
V_10 -> V_64 . V_66 ++ ;
V_10 -> V_64 . V_67 += V_59 ;
V_10 -> V_64 . V_68 ++ ;
return V_59 ;
}
static void F_31 ( void * V_37 , struct V_69 * V_64 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
* V_64 = V_10 -> V_64 ;
}
static int
F_32 ( void * V_37 , unsigned char * V_27 , int V_28 , int V_38 ,
int V_54 , int V_70 , int V_39 )
{
return F_22 ( V_37 , V_27 , V_28 , V_38 , V_39 , L_16 ) ;
}
static void F_33 ( void * V_37 )
{
return;
}
static int
F_34 ( void * V_37 , unsigned char * V_56 , int V_58 , unsigned char * V_57 ,
int V_59 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
struct V_24 V_12 = { . V_17 = V_10 -> V_25 } ;
unsigned V_50 ;
int V_71 = F_35 ( V_56 ) & V_55 ;
int V_72 = 0 ;
struct V_1 V_22 [ 1 ] , V_23 [ 1 ] ;
if ( V_58 <= V_63 + V_61 ) {
if ( V_10 -> V_39 )
F_10 ( V_49
L_17 ,
V_10 -> V_38 , V_58 ) ;
return V_73 ;
}
if ( V_59 < V_58 - V_61 - 1 ) {
F_10 ( V_49 L_18
L_12 , V_10 -> V_38 ,
V_59 , V_58 - V_61 - 1 ) ;
return V_73 ;
}
V_59 = V_58 - V_61 - 2 ;
V_50 = F_36 ( V_56 ) ;
if ( V_10 -> V_39 >= 7 )
F_10 ( V_49 L_19 ,
V_10 -> V_38 , V_50 ) ;
if ( ! ( F_35 ( V_56 ) & V_53 ) ) {
F_10 ( V_49
L_20 ,
V_10 -> V_38 ) ;
V_10 -> V_74 += 100 ;
V_72 = 1 ;
}
if ( ! V_10 -> V_45 && ! V_71 ) {
F_10 ( V_49 L_21
L_22 , V_10 -> V_38 ) ;
V_10 -> V_74 += 100 ;
V_72 = 1 ;
}
if ( V_10 -> V_45 && ( ( V_50 & 0xff ) == 0xff ) && ! V_71 ) {
F_10 ( V_49 L_23
L_24 , V_10 -> V_38 ) ;
V_10 -> V_74 += 100 ;
V_72 = 1 ;
}
if ( V_72 ) {
if ( V_10 -> V_74 < V_75 )
return V_73 ;
else
return V_76 ;
}
if ( ! V_10 -> V_45 ) {
while ( V_10 -> V_50 != V_50 ) {
F_7 ( V_10 , 0 ) ;
V_10 -> V_50 = ( V_10 -> V_50 + 1 ) % V_51 ;
}
} else {
if ( ! V_10 -> V_77 ) {
V_10 -> V_50 = ( V_10 -> V_50 + 1 ) % V_51 ;
if ( V_50 != V_10 -> V_50 ) {
V_10 -> V_77 = 1 ;
return V_73 ;
}
} else {
if ( ! V_71 ) {
return V_73 ;
} else {
while ( ( V_50 & ~ 0xff ) !=
( V_10 -> V_50 & ~ 0xff ) ) {
F_7 ( V_10 , 0 ) ;
V_10 -> V_50 =
( V_10 -> V_50 +
256 ) % V_51 ;
}
V_10 -> V_77 = 0 ;
V_10 -> V_50 = V_50 ;
}
}
if ( V_71 )
F_7 ( V_10 , 0 ) ;
}
V_57 [ 0 ] = F_28 ( V_56 ) ;
V_57 [ 1 ] = F_29 ( V_56 ) ;
V_57 += 2 ;
V_56 += V_63 + V_61 ;
V_58 -= V_63 + V_61 ;
F_5 ( V_22 , 1 ) ;
F_5 ( V_23 , 1 ) ;
F_1 ( V_22 , V_56 , 1 ) ;
F_1 ( V_23 , V_57 , 1 ) ;
if ( F_37 ( & V_12 , V_23 , V_22 , 1 ) != 0 ) {
F_10 ( V_49 L_25 ) ;
return V_73 ;
}
if ( ( V_57 [ 0 ] & 0x01 ) != 0 ) {
V_57 [ 1 ] = V_57 [ 0 ] ;
V_57 [ 0 ] = 0 ;
V_57 ++ ;
V_59 ++ ;
}
F_1 ( V_22 , V_56 + 1 , V_58 - 1 ) ;
F_1 ( V_23 , V_57 + 1 , V_59 - 1 ) ;
if ( F_37 ( & V_12 , V_23 , V_22 , V_58 - 1 ) ) {
F_10 ( V_49 L_25 ) ;
return V_73 ;
}
V_10 -> V_64 . V_65 += V_59 ;
V_10 -> V_64 . V_66 ++ ;
V_10 -> V_64 . V_67 += V_58 ;
V_10 -> V_64 . V_68 ++ ;
V_10 -> V_74 >>= 1 ;
return V_59 ;
}
static void F_38 ( void * V_37 , unsigned char * V_56 , int V_78 )
{
struct V_9 * V_10 = (struct V_9 * ) V_37 ;
if ( V_10 -> V_39 &&
( F_27 ( V_56 ) >= 0x0021 && F_27 ( V_56 ) <= 0x00fa ) )
F_10 ( V_49
L_26
L_27 , V_10 -> V_38 , F_27 ( V_56 ) ) ;
V_10 -> V_64 . V_79 += V_78 ;
V_10 -> V_64 . V_80 ++ ;
V_10 -> V_64 . V_65 += V_78 ;
V_10 -> V_64 . V_66 ++ ;
}
static int T_1 F_39 ( void )
{
int V_81 ;
if ( ! ( F_40 ( L_2 , 0 , V_34 ) &&
F_41 ( L_3 , 0 , V_34 ) ) )
return - V_82 ;
V_5 = F_17 ( sizeof( struct V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_83 ;
F_3 ( V_5 ) ;
V_81 = F_42 ( & V_84 ) ;
if ( V_81 == 0 )
F_10 ( V_85 L_28 ) ;
else
F_18 ( V_5 ) ;
return V_81 ;
}
static void T_2 F_43 ( void )
{
F_44 ( & V_84 ) ;
F_18 ( V_5 ) ;
}
