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
F_5 ( V_11 , V_10 -> V_12 ) ;
struct V_1 V_2 [ 4 ] ;
unsigned int V_13 ;
F_6 ( V_2 , 4 ) ;
V_13 = F_1 ( & V_2 [ 0 ] , V_10 -> V_14 , V_10 -> V_15 ) ;
V_13 += F_1 ( & V_2 [ 1 ] , V_5 -> V_7 ,
sizeof( V_5 -> V_7 ) ) ;
V_13 += F_1 ( & V_2 [ 2 ] , V_10 -> V_16 , V_10 -> V_15 ) ;
V_13 += F_1 ( & V_2 [ 3 ] , V_5 -> V_8 ,
sizeof( V_5 -> V_8 ) ) ;
F_7 ( V_11 , V_10 -> V_12 ) ;
F_8 ( V_11 , 0 , NULL , NULL ) ;
F_9 ( V_11 , V_2 , V_10 -> V_17 , V_13 ) ;
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
}
static void F_12 ( struct V_9 * V_10 , int V_18 )
{
struct V_1 V_19 [ 1 ] , V_20 [ 1 ] ;
F_13 ( V_11 , V_10 -> V_21 ) ;
F_14 ( V_11 , V_10 -> V_21 ) ;
F_15 ( V_11 , 0 , NULL , NULL ) ;
F_4 ( V_10 ) ;
if ( ! V_18 ) {
F_16 ( V_10 -> V_21 , V_10 -> V_17 ,
V_10 -> V_15 ) ;
F_6 ( V_19 , 1 ) ;
F_6 ( V_20 , 1 ) ;
F_1 ( V_19 , V_10 -> V_17 , V_10 -> V_15 ) ;
F_1 ( V_20 , V_10 -> V_16 , V_10 -> V_15 ) ;
F_17 ( V_11 , V_19 , V_20 , V_10 -> V_15 ,
NULL ) ;
if ( F_18 ( V_11 ) )
F_19 ( V_22 L_1 ) ;
} else {
memcpy ( V_10 -> V_16 , V_10 -> V_17 , V_10 -> V_15 ) ;
}
if ( V_10 -> V_15 == 8 ) {
V_10 -> V_16 [ 0 ] = 0xd1 ;
V_10 -> V_16 [ 1 ] = 0x26 ;
V_10 -> V_16 [ 2 ] = 0x9e ;
}
F_16 ( V_10 -> V_21 , V_10 -> V_16 , V_10 -> V_15 ) ;
F_20 ( V_11 ) ;
}
static void * F_21 ( unsigned char * V_23 , int V_24 )
{
struct V_9 * V_10 ;
unsigned int V_25 ;
if ( V_24 != V_26 + sizeof( V_10 -> V_14 ) ||
V_23 [ 0 ] != V_27 || V_23 [ 1 ] != V_26 )
goto V_28;
V_10 = F_22 ( sizeof( * V_10 ) , V_29 ) ;
if ( V_10 == NULL )
goto V_28;
V_10 -> V_21 = F_23 ( L_2 , 0 , V_30 ) ;
if ( F_24 ( V_10 -> V_21 ) ) {
V_10 -> V_21 = NULL ;
goto V_31;
}
V_10 -> V_12 = F_25 ( L_3 , 0 , V_30 ) ;
if ( F_24 ( V_10 -> V_12 ) ) {
V_10 -> V_12 = NULL ;
goto V_31;
}
V_25 = F_26 ( V_10 -> V_12 ) ;
if ( V_25 < V_32 )
goto V_31;
V_10 -> V_17 = F_27 ( V_25 , V_29 ) ;
if ( ! V_10 -> V_17 )
goto V_31;
memcpy ( V_10 -> V_14 , & V_23 [ V_26 ] ,
sizeof( V_10 -> V_14 ) ) ;
memcpy ( V_10 -> V_16 , V_10 -> V_14 ,
sizeof( V_10 -> V_14 ) ) ;
return ( void * ) V_10 ;
V_31:
F_28 ( V_10 -> V_17 ) ;
F_29 ( V_10 -> V_12 ) ;
F_30 ( V_10 -> V_21 ) ;
F_28 ( V_10 ) ;
V_28:
return NULL ;
}
static void F_31 ( void * V_33 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
if ( V_10 ) {
F_28 ( V_10 -> V_17 ) ;
F_29 ( V_10 -> V_12 ) ;
F_30 ( V_10 -> V_21 ) ;
F_28 ( V_10 ) ;
}
}
static int
F_32 ( void * V_33 , unsigned char * V_23 , int V_24 , int V_34 , int V_35 ,
const char * V_36 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
unsigned char V_37 ;
if ( V_24 != V_26 ||
V_23 [ 0 ] != V_27 || V_23 [ 1 ] != V_26 )
return 0 ;
F_33 ( & V_23 [ 2 ] , V_37 ) ;
if ( V_37 & V_38 )
V_10 -> V_15 = 16 ;
else if ( V_37 & V_39 )
V_10 -> V_15 = 8 ;
else {
F_19 ( V_22 L_4 , V_36 ,
V_34 ) ;
return 0 ;
}
if ( V_37 & V_40 )
V_10 -> V_41 = 1 ;
F_12 ( V_10 , 1 ) ;
if ( V_35 ) {
int V_42 ;
char V_43 [ sizeof( V_10 -> V_14 ) * 2 + 1 ] ;
char V_44 [ sizeof( V_10 -> V_16 ) * 2 + 1 ] ;
F_19 ( V_45 L_5 ,
V_36 , V_34 , ( V_10 -> V_15 == 16 ) ? 128 : 40 ,
( V_10 -> V_41 ) ? L_6 : L_7 ) ;
for ( V_42 = 0 ; V_42 < sizeof( V_10 -> V_14 ) ; V_42 ++ )
sprintf ( V_43 + V_42 * 2 , L_8 , V_10 -> V_14 [ V_42 ] ) ;
for ( V_42 = 0 ; V_42 < sizeof( V_10 -> V_16 ) ; V_42 ++ )
sprintf ( V_44 + V_42 * 2 , L_8 , V_10 -> V_16 [ V_42 ] ) ;
F_19 ( V_45
L_9 ,
V_36 , V_34 , V_43 , V_44 ) ;
}
V_10 -> V_46 = V_47 - 1 ;
V_10 -> V_48 = V_49 ;
V_10 -> V_34 = V_34 ;
V_10 -> V_35 = V_35 ;
return 1 ;
}
static int
F_34 ( void * V_33 , unsigned char * V_23 , int V_24 , int V_34 ,
int V_50 , int V_35 )
{
return F_32 ( V_33 , V_23 , V_24 , V_34 , V_35 , L_10 ) ;
}
static void F_35 ( void * V_33 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
V_10 -> V_48 |= V_51 ;
}
static int
F_36 ( void * V_33 , unsigned char * V_52 , unsigned char * V_53 ,
int V_54 , int V_55 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
F_13 ( V_11 , V_10 -> V_21 ) ;
int V_56 ;
int V_57 ;
struct V_1 V_19 [ 1 ] , V_20 [ 1 ] ;
V_56 = F_37 ( V_52 ) ;
if ( V_56 < 0x0021 || V_56 > 0x00fa )
return 0 ;
if ( V_55 < V_54 + V_58 + 2 ) {
F_19 ( V_45 L_11
L_12 , V_10 -> V_34 ,
V_55 , V_55 + V_58 + 2 ) ;
return - 1 ;
}
V_55 = V_54 + V_58 + 2 ;
V_53 [ 0 ] = F_38 ( V_52 ) ;
V_53 [ 1 ] = F_39 ( V_52 ) ;
F_40 ( V_59 , V_53 + 2 ) ;
V_53 += V_60 ;
V_10 -> V_46 = ( V_10 -> V_46 + 1 ) % V_47 ;
if ( V_10 -> V_35 >= 7 )
F_19 ( V_45 L_13 , V_10 -> V_34 ,
V_10 -> V_46 ) ;
F_40 ( V_10 -> V_46 , V_53 ) ;
if ( ! V_10 -> V_41 ||
( ( V_10 -> V_46 & 0xff ) == 0xff ) ||
( V_10 -> V_48 & V_51 ) ) {
if ( V_10 -> V_35 && V_10 -> V_41 )
F_19 ( V_45 L_14 ,
V_10 -> V_34 ) ;
F_12 ( V_10 , 0 ) ;
V_10 -> V_48 |= V_51 ;
}
V_53 [ 0 ] |= V_10 -> V_48 ;
V_10 -> V_48 &= ~ V_51 ;
V_53 += V_58 ;
V_52 += 2 ;
V_54 -= 2 ;
F_6 ( V_19 , 1 ) ;
F_6 ( V_20 , 1 ) ;
F_1 ( V_19 , V_52 , V_54 ) ;
F_1 ( V_20 , V_53 , V_55 ) ;
F_14 ( V_11 , V_10 -> V_21 ) ;
F_15 ( V_11 , 0 , NULL , NULL ) ;
F_17 ( V_11 , V_19 , V_20 , V_54 , NULL ) ;
V_57 = F_18 ( V_11 ) ;
F_20 ( V_11 ) ;
if ( V_57 ) {
F_19 ( V_45 L_15 ) ;
return - 1 ;
}
V_10 -> V_61 . V_62 += V_54 ;
V_10 -> V_61 . V_63 ++ ;
V_10 -> V_61 . V_64 += V_55 ;
V_10 -> V_61 . V_65 ++ ;
return V_55 ;
}
static void F_41 ( void * V_33 , struct V_66 * V_61 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
* V_61 = V_10 -> V_61 ;
}
static int
F_42 ( void * V_33 , unsigned char * V_23 , int V_24 , int V_34 ,
int V_50 , int V_67 , int V_35 )
{
return F_32 ( V_33 , V_23 , V_24 , V_34 , V_35 , L_16 ) ;
}
static void F_43 ( void * V_33 )
{
return;
}
static int
F_44 ( void * V_33 , unsigned char * V_52 , int V_54 , unsigned char * V_53 ,
int V_55 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
F_13 ( V_11 , V_10 -> V_21 ) ;
unsigned V_46 ;
int V_68 = F_45 ( V_52 ) & V_51 ;
struct V_1 V_19 [ 1 ] , V_20 [ 1 ] ;
if ( V_54 <= V_60 + V_58 ) {
if ( V_10 -> V_35 )
F_19 ( V_45
L_17 ,
V_10 -> V_34 , V_54 ) ;
return V_69 ;
}
if ( V_55 < V_54 - V_58 - 1 ) {
F_19 ( V_45 L_18
L_12 , V_10 -> V_34 ,
V_55 , V_54 - V_58 - 1 ) ;
return V_69 ;
}
V_55 = V_54 - V_58 - 2 ;
V_46 = F_46 ( V_52 ) ;
if ( V_10 -> V_35 >= 7 )
F_19 ( V_45 L_19 ,
V_10 -> V_34 , V_46 ) ;
if ( ! ( F_45 ( V_52 ) & V_49 ) ) {
F_19 ( V_45
L_20 ,
V_10 -> V_34 ) ;
V_10 -> V_70 += 100 ;
goto V_71;
}
if ( ! V_10 -> V_41 && ! V_68 ) {
F_19 ( V_45 L_21
L_22 , V_10 -> V_34 ) ;
V_10 -> V_70 += 100 ;
goto V_71;
}
if ( V_10 -> V_41 && ( ( V_46 & 0xff ) == 0xff ) && ! V_68 ) {
F_19 ( V_45 L_23
L_24 , V_10 -> V_34 ) ;
V_10 -> V_70 += 100 ;
goto V_71;
}
if ( ! V_10 -> V_41 ) {
if ( ( V_46 - V_10 -> V_46 ) % V_47
> V_47 / 2 ) {
V_10 -> V_70 ++ ;
goto V_71;
}
while ( V_10 -> V_46 != V_46 ) {
F_12 ( V_10 , 0 ) ;
V_10 -> V_46 = ( V_10 -> V_46 + 1 ) % V_47 ;
}
} else {
if ( ! V_10 -> V_72 ) {
V_10 -> V_46 = ( V_10 -> V_46 + 1 ) % V_47 ;
if ( V_46 != V_10 -> V_46 ) {
V_10 -> V_72 = 1 ;
return V_69 ;
}
} else {
if ( ! V_68 ) {
return V_69 ;
} else {
while ( ( V_46 & ~ 0xff ) !=
( V_10 -> V_46 & ~ 0xff ) ) {
F_12 ( V_10 , 0 ) ;
V_10 -> V_46 =
( V_10 -> V_46 +
256 ) % V_47 ;
}
V_10 -> V_72 = 0 ;
V_10 -> V_46 = V_46 ;
}
}
if ( V_68 )
F_12 ( V_10 , 0 ) ;
}
V_53 [ 0 ] = F_38 ( V_52 ) ;
V_53 [ 1 ] = F_39 ( V_52 ) ;
V_53 += 2 ;
V_52 += V_60 + V_58 ;
V_54 -= V_60 + V_58 ;
F_6 ( V_19 , 1 ) ;
F_6 ( V_20 , 1 ) ;
F_1 ( V_19 , V_52 , 1 ) ;
F_1 ( V_20 , V_53 , 1 ) ;
F_14 ( V_11 , V_10 -> V_21 ) ;
F_15 ( V_11 , 0 , NULL , NULL ) ;
F_17 ( V_11 , V_19 , V_20 , 1 , NULL ) ;
if ( F_47 ( V_11 ) ) {
F_19 ( V_45 L_25 ) ;
V_55 = V_69 ;
goto V_73;
}
if ( ( V_53 [ 0 ] & 0x01 ) != 0 ) {
V_53 [ 1 ] = V_53 [ 0 ] ;
V_53 [ 0 ] = 0 ;
V_53 ++ ;
V_55 ++ ;
}
F_1 ( V_19 , V_52 + 1 , V_54 - 1 ) ;
F_1 ( V_20 , V_53 + 1 , V_55 - 1 ) ;
F_17 ( V_11 , V_19 , V_20 , V_54 - 1 , NULL ) ;
if ( F_47 ( V_11 ) ) {
F_19 ( V_45 L_25 ) ;
V_55 = V_69 ;
goto V_73;
}
V_10 -> V_61 . V_62 += V_55 ;
V_10 -> V_61 . V_63 ++ ;
V_10 -> V_61 . V_64 += V_54 ;
V_10 -> V_61 . V_65 ++ ;
V_10 -> V_70 >>= 1 ;
V_73:
F_20 ( V_11 ) ;
return V_55 ;
V_71:
if ( V_10 -> V_70 < V_74 )
return V_69 ;
else
return V_75 ;
}
static void F_48 ( void * V_33 , unsigned char * V_52 , int V_76 )
{
struct V_9 * V_10 = (struct V_9 * ) V_33 ;
if ( V_10 -> V_35 &&
( F_37 ( V_52 ) >= 0x0021 && F_37 ( V_52 ) <= 0x00fa ) )
F_19 ( V_45
L_26
L_27 , V_10 -> V_34 , F_37 ( V_52 ) ) ;
V_10 -> V_61 . V_77 += V_76 ;
V_10 -> V_61 . V_78 ++ ;
V_10 -> V_61 . V_62 += V_76 ;
V_10 -> V_61 . V_63 ++ ;
}
static int T_1 F_49 ( void )
{
int V_79 ;
if ( ! ( F_50 ( L_2 , 0 , V_30 ) &&
F_51 ( L_3 , 0 , V_30 ) ) )
return - V_80 ;
V_5 = F_27 ( sizeof( struct V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_81 ;
F_3 ( V_5 ) ;
V_79 = F_52 ( & V_82 ) ;
if ( V_79 == 0 )
F_19 ( V_83 L_28 ) ;
else
F_28 ( V_5 ) ;
return V_79 ;
}
static void T_2 F_53 ( void )
{
F_54 ( & V_82 ) ;
F_28 ( V_5 ) ;
}
