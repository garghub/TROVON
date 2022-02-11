static void F_1 ( unsigned int V_1 )
{
int V_2 , V_3 ;
char V_4 [ 64 ] ;
memset ( V_4 , 0 , 64 ) ;
V_3 = 0 ;
for ( V_2 = 31 ; V_2 >= 0 ; V_2 -- ) {
if ( V_1 & ( 1 << V_2 ) )
V_4 [ V_3 ++ ] = '1' ;
else
V_4 [ V_3 ++ ] = '0' ;
if ( ( V_2 & 3 ) == 0 )
V_4 [ V_3 ++ ] = ' ' ;
}
F_2 ( L_1 , V_4 ) ;
}
static int T_1 F_3 ( struct V_5 * V_6 , const struct V_7 * V_8 )
{
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 ;
unsigned long V_13 ;
unsigned short V_14 ;
if ( F_4 ( V_6 ) )
return - V_15 ;
F_5 ( V_6 , V_16 , 0x0000 ) ;
F_6 ( V_6 ) ;
F_7 ( V_6 , V_17 , & V_14 ) ;
F_8 ( V_6 , V_17 , V_14 ) ;
if ( ! F_9 ( F_10 ( V_6 , 0 ) , 128 , L_2 ) ) {
F_11 ( L_3 , V_18 ) ;
return - V_15 ;
}
V_10 = F_12 ( sizeof( struct V_11 ) ) ;
if ( ! V_10 )
goto V_19;
V_12 = F_13 ( V_10 ) ;
V_12 -> V_20 = F_14 ( V_6 , 8192 , & V_12 -> V_21 ) ;
if ( V_12 -> V_20 == NULL ) {
F_11 ( L_4 , V_18 ) ;
goto V_22;
}
V_12 -> V_23 = F_14 ( V_6 , 8192 , & V_12 -> V_24 ) ;
if ( V_12 -> V_23 == NULL ) {
F_11 ( L_5 , V_18 ) ;
goto V_25;
}
F_15 ( V_10 , & V_6 -> V_10 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_26 = F_10 ( V_6 , 0 ) ;
F_16 ( & V_12 -> V_27 ) ;
V_10 -> V_28 = V_6 -> V_28 ;
V_10 -> V_29 = V_12 -> V_26 ;
F_17 ( V_12 ) ;
F_18 ( V_12 ) ;
F_19 ( V_12 ) ;
V_10 -> V_30 = & V_30 ;
F_20 ( V_6 , V_10 ) ;
if ( F_21 ( V_10 ) ) {
F_11 ( L_6 , V_18 ) ;
goto V_31;
}
F_22 ( V_10 , L_7 ,
V_6 -> V_32 , V_6 -> V_28 ) ;
F_23 ( V_12 ) ;
F_24 ( & V_12 -> V_27 , V_13 ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 ) ;
F_27 ( & V_12 -> V_27 , V_13 ) ;
F_28 ( V_12 ) ;
return 0 ;
V_31:
F_29 ( V_12 -> V_23 ) ;
V_25:
F_29 ( V_12 -> V_20 ) ;
V_22:
F_30 ( V_10 ) ;
V_19:
return - V_15 ;
}
static void T_2 F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_32 ( V_6 ) ;
struct V_11 * V_33 = F_13 ( V_10 ) ;
F_33 ( V_6 , 8192 , V_33 -> V_20 , V_33 -> V_21 ) ;
F_33 ( V_6 , 8192 , V_33 -> V_23 , V_33 -> V_24 ) ;
F_34 ( V_10 -> V_29 , 128 ) ;
F_35 ( V_10 ) ;
F_30 ( V_10 ) ;
F_20 ( V_6 , NULL ) ;
}
static T_3 F_36 ( int V_28 , void * V_34 )
{
struct V_9 * V_10 = (struct V_9 * ) V_34 ;
struct V_11 * V_33 = F_13 ( V_10 ) ;
unsigned int V_35 ;
int V_2 ;
F_37 ( & V_33 -> V_27 ) ;
V_35 = F_38 ( V_33 -> V_26 + V_36 ) ;
#if V_37 V_38 && V_38 > 1
F_1 ( V_35 ) ;
F_2 ( L_8 ,
V_33 -> V_23 [ 0 ] , V_33 -> V_23 [ 4 ] ) ;
F_2 ( L_9 ,
V_33 -> V_20 [ 0 ] , V_33 -> V_20 [ 4 ] ) ;
#endif
if ( V_35 == 0 || V_35 == 0xffffffff ) {
F_39 ( & V_33 -> V_27 ) ;
return V_39 ;
}
if ( F_40 ( V_33 ) ) {
int V_40 ;
F_41 ( V_10 , L_10 ) ;
V_40 = F_42 ( V_33 ) ;
F_22 ( V_10 , L_11 , V_40 ) ;
if ( V_40 )
F_43 ( V_10 ) ;
else
F_44 ( V_10 ) ;
}
V_35 |= 0xffffffff ;
F_45 ( V_35 , V_33 -> V_26 + V_36 ) ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ )
F_46 ( V_10 , V_33 , V_2 , V_42 [ V_2 ] ) ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ )
F_47 ( V_10 , V_33 , V_2 , V_42 [ V_2 ] ) ;
F_39 ( & V_33 -> V_27 ) ;
return V_43 ;
}
static T_4 F_48 ( struct V_44 * V_45 ,
struct V_9 * V_10 )
{
struct V_11 * V_33 ;
unsigned long V_13 ;
int V_46 ;
int V_47 ;
V_33 = F_13 ( V_10 ) ;
F_24 ( & V_33 -> V_27 , V_13 ) ;
for ( V_47 = 0 ; V_47 < V_41 ; V_47 ++ )
F_46 ( V_10 , V_33 , V_47 , V_42 [ V_47 ] ) ;
V_46 = ( V_33 -> V_48 + 1 ) % ( V_41 ) ;
V_47 = V_33 -> V_48 ;
if ( V_33 -> V_23 [ 4 * V_47 ] == 0 ) {
memset ( & V_33 -> V_23 [ V_42 [ V_47 ] / 4 ] , 0 , 1536 ) ;
F_49 ( V_45 ,
& ( V_33 -> V_23 [ V_42 [ V_47 ] / 4 ] ) ,
V_45 -> V_49 ) ;
V_33 -> V_23 [ 4 * V_47 + 1 ] = F_50 ( V_45 -> V_49 ) ;
if ( V_47 == V_41 - 1 )
V_33 -> V_23 [ 4 * V_47 + 1 ] |= F_50 ( 1 << 25 ) ;
V_33 -> V_23 [ 4 * V_47 + 1 ] |= F_50 ( 0xF0000000 ) ;
V_33 -> V_50 [ V_47 ] = V_45 ;
F_51 () ;
V_33 -> V_23 [ 4 * V_47 ] = F_50 ( 0x80000000 ) ;
F_52 ( V_33 ) ;
if ( V_33 -> V_23 [ V_46 * 4 ] & F_50 ( 0x8000000 ) ) {
F_53 ( V_10 ) ;
}
V_33 -> V_48 = V_46 ;
F_27 ( & V_33 -> V_27 , V_13 ) ;
return V_51 ;
}
F_53 ( V_10 ) ;
F_27 ( & V_33 -> V_27 , V_13 ) ;
F_52 ( V_33 ) ;
return V_52 ;
}
static int F_54 ( struct V_9 * V_10 )
{
struct V_11 * V_53 = F_13 ( V_10 ) ;
int V_54 ;
F_22 ( V_10 , L_12 ,
V_10 -> V_28 ) ;
V_54 = F_55 ( V_10 -> V_28 , F_36 , V_55 , V_10 -> V_56 , V_10 ) ;
if ( V_54 )
return V_54 ;
F_56 ( V_53 ) ;
V_53 -> V_57 = 1 ;
return 0 ;
}
static int F_57 ( struct V_9 * V_10 )
{
struct V_11 * V_33 ;
unsigned long V_13 ;
V_33 = F_13 ( V_10 ) ;
F_53 ( V_10 ) ;
F_24 ( & V_33 -> V_27 , V_13 ) ;
F_58 ( V_33 ) ;
#if 0
deactivate_receiver(card);
deactivate_transmitter(card);
#endif
F_59 ( V_33 ) ;
F_27 ( & V_33 -> V_27 , V_13 ) ;
V_33 -> V_57 = 0 ;
F_60 ( V_10 -> V_28 , V_10 ) ;
return 0 ;
}
static void F_61 ( struct V_9 * V_10 )
{
F_62 ( V_10 -> V_28 ) ;
F_36 ( V_10 -> V_28 , V_10 ) ;
F_63 ( V_10 -> V_28 ) ;
}
static void F_17 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
unsigned long V_13 ;
F_24 ( & V_33 -> V_27 , V_13 ) ;
V_58 = F_38 ( V_33 -> V_26 + V_59 ) ;
V_58 |= 0x01 ;
F_45 ( V_58 , V_33 -> V_26 + V_59 ) ;
F_64 ( 100 ) ;
V_58 = F_38 ( V_33 -> V_26 + V_59 ) ;
V_58 &= ~ 0x01 ;
F_45 ( V_58 , V_33 -> V_26 + V_59 ) ;
V_58 = 0 ;
F_45 ( V_58 , V_33 -> V_26 + V_59 ) ;
F_58 ( V_33 ) ;
F_65 ( V_33 ) ;
F_66 ( V_33 ) ;
F_27 ( & V_33 -> V_27 , V_13 ) ;
}
static void F_52 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = 0 ;
F_45 ( V_58 , V_33 -> V_26 + V_60 ) ;
}
static void F_28 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = 0 ;
F_45 ( V_58 , V_33 -> V_26 + V_61 ) ;
}
static void F_19 ( struct V_11 * V_33 )
{
T_5 V_62 ;
int V_2 ;
F_67 ( V_33 -> V_20 == NULL ) ;
F_67 ( V_33 -> V_23 == NULL ) ;
memset ( V_33 -> V_20 , 0 , 128 ) ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ ) {
V_33 -> V_20 [ V_2 * 4 + 0 ] = F_50 ( 0x80000000 ) ;
V_33 -> V_20 [ V_2 * 4 + 1 ] = F_50 ( 1536 ) ;
if ( V_2 == V_41 - 1 )
V_33 -> V_20 [ V_2 * 4 + 1 ] |= F_50 ( 1 << 25 ) ;
V_62 = V_33 -> V_21 ;
V_33 -> V_20 [ V_2 * 4 + 2 ] = F_50 ( V_62 + V_42 [ V_2 ] ) ;
V_33 -> V_20 [ V_2 * 4 + 3 ] = 0 ;
}
F_51 () ;
V_62 = V_33 -> V_21 ;
F_45 ( V_62 , V_33 -> V_26 + V_63 ) ;
memset ( V_33 -> V_23 , 0 , 128 ) ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ ) {
V_33 -> V_23 [ V_2 * 4 + 0 ] = 0x00000000 ;
V_33 -> V_23 [ V_2 * 4 + 1 ] = F_50 ( 1536 ) ;
if ( V_2 == V_41 - 1 )
V_33 -> V_23 [ V_2 * 4 + 1 ] |= F_50 ( 1 << 25 ) ;
V_62 = V_33 -> V_24 ;
V_33 -> V_23 [ V_2 * 4 + 2 ] = F_50 ( V_62 + V_42 [ V_2 ] ) ;
V_33 -> V_23 [ V_2 * 4 + 3 ] = 0 ;
}
F_51 () ;
V_62 = V_33 -> V_24 ;
F_45 ( V_62 , V_33 -> V_26 + V_64 ) ;
}
static void F_59 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = 0 ;
F_45 ( V_58 , V_33 -> V_26 + V_63 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_64 ) ;
}
static int F_40 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_36 ) ;
if ( ( V_58 & ( 1 << 27 ) ) == 0 )
return 0 ;
V_58 = ( 1 << 27 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_36 ) ;
return 1 ;
}
static int F_68 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_36 ) ;
if ( ( V_58 & ( 7 << 20 ) ) == 0 )
return 0 ;
return 1 ;
}
static int F_69 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_36 ) ;
if ( ( V_58 & ( 7 << 17 ) ) == 0 )
return 0 ;
return 1 ;
}
static void F_26 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
int V_65 ;
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
if ( ( V_58 & 2 ) && ( F_69 ( V_33 ) ) )
return;
V_58 = V_58 & ~ 2 ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
V_65 = 10 ;
while ( V_65 > 0 ) {
if ( ! F_69 ( V_33 ) )
break;
F_64 ( 50 ) ;
V_65 -- ;
if ( V_65 <= 0 )
F_70 ( V_33 -> V_10 , L_13 ) ;
}
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
V_58 = V_58 | 2 ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
V_65 = 10 ;
while ( V_65 > 0 ) {
if ( F_69 ( V_33 ) )
break;
F_64 ( 50 ) ;
V_65 -- ;
if ( V_65 <= 0 )
F_70 ( V_33 -> V_10 ,
L_14 ) ;
}
}
static void F_65 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
int V_65 ;
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
V_58 = V_58 & ~ 2 ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
V_65 = 10 ;
while ( V_65 > 0 ) {
if ( ! F_69 ( V_33 ) )
break;
F_64 ( 50 ) ;
V_65 -- ;
if ( V_65 <= 0 )
F_70 ( V_33 -> V_10 , L_13 ) ;
}
}
static void F_25 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
int V_65 ;
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
if ( ( V_58 & ( 1 << 13 ) ) && ( F_68 ( V_33 ) ) )
return;
V_58 = V_58 & ~ ( 1 << 13 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
V_65 = 10 ;
while ( V_65 > 0 ) {
if ( ! F_68 ( V_33 ) )
break;
F_64 ( 50 ) ;
V_65 -- ;
if ( V_65 <= 0 )
F_70 ( V_33 -> V_10 ,
L_15 ) ;
}
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
V_58 = V_58 | ( 1 << 13 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
V_65 = 10 ;
while ( V_65 > 0 ) {
if ( F_68 ( V_33 ) )
break;
F_64 ( 50 ) ;
V_65 -- ;
if ( V_65 <= 0 )
F_70 ( V_33 -> V_10 ,
L_16 ) ;
}
}
static void F_66 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
int V_65 ;
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
V_58 = V_58 & ~ 2 ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
V_65 = 20 ;
while ( V_65 > 0 ) {
if ( ! F_68 ( V_33 ) )
break;
F_64 ( 50 ) ;
V_65 -- ;
if ( V_65 <= 0 )
F_70 ( V_33 -> V_10 ,
L_15 ) ;
}
}
static void F_71 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_67 ) ;
V_58 |= 1 ;
F_45 ( V_58 , V_33 -> V_26 + V_67 ) ;
}
static void F_72 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_67 ) ;
V_58 = V_58 | ( 1 << 6 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_67 ) ;
}
static void F_73 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_67 ) ;
V_58 = V_58 | ( 1 << 27 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_67 ) ;
}
static void F_58 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = 0 ;
F_45 ( V_58 , V_33 -> V_26 + V_67 ) ;
}
static void F_74 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_67 ) ;
V_58 |= ( 1 << 16 ) ;
V_58 |= ( 1 << 15 ) ;
V_58 |= ( 1 << 13 ) ;
V_58 |= ( 1 << 8 ) ;
V_58 |= ( 1 << 7 ) ;
V_58 |= ( 1 << 5 ) ;
V_58 |= ( 1 << 2 ) ;
V_58 |= ( 1 << 1 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_67 ) ;
}
static int F_75 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_38 ( V_33 -> V_26 + V_66 ) ;
V_58 = V_58 | ( 1 << 6 ) ;
F_45 ( V_58 , V_33 -> V_26 + V_66 ) ;
return 1 ;
}
static int F_42 ( struct V_11 * V_33 )
{
unsigned int V_58 ;
V_58 = F_76 ( V_33 -> V_26 + V_68 ) ;
if ( ! ( V_58 & ( 1 << 2 ) ) )
return 10 ;
if ( ! ( V_58 & ( 1 << 1 ) ) )
return 100 ;
return 0 ;
}
static void F_18 ( struct V_11 * V_33 )
{
unsigned char V_69 , V_70 , V_71 , V_72 , V_73 ;
unsigned long V_13 ;
int V_2 ;
F_24 ( & V_33 -> V_27 , V_13 ) ;
F_45 ( 1 << 12 , V_33 -> V_26 + V_74 ) ;
for ( V_2 = 0x100 ; V_2 < 0x1f7 ; V_2 += V_71 + 2 ) {
F_45 ( V_2 , V_33 -> V_26 + V_75 ) ;
V_70 = F_38 ( V_33 -> V_26 + V_74 ) & 0xff ;
F_45 ( V_2 + 1 , V_33 -> V_26 + V_75 ) ;
V_71 = F_38 ( V_33 -> V_26 + V_74 ) & 0xff ;
F_45 ( V_2 + 2 , V_33 -> V_26 + V_75 ) ;
V_72 = F_38 ( V_33 -> V_26 + V_74 ) & 0xff ;
F_45 ( V_2 + 3 , V_33 -> V_26 + V_75 ) ;
V_73 = F_38 ( V_33 -> V_26 + V_74 ) & 0xff ;
if ( ( V_70 == 0x22 ) && ( V_72 == 0x04 ) && ( V_73 == 0x06 ) ) {
for ( V_69 = 0 ; V_69 < 6 ; V_69 ++ ) {
F_45 ( V_2 + V_69 + 4 , V_33 -> V_26 + V_75 ) ;
V_33 -> V_10 -> V_76 [ V_69 ] = F_38 ( V_33 -> V_26 + V_74 ) & 0xff ;
}
break;
} else if ( V_71 == 0 ) {
break;
}
}
F_27 ( & V_33 -> V_27 , V_13 ) ;
F_2 ( L_17 , V_33 -> V_10 -> V_76 ) ;
}
static void F_23 ( struct V_11 * V_33 )
{
unsigned long V_13 ;
F_5 ( V_33 -> V_6 , V_16 , 0x0000 ) ;
F_19 ( V_33 ) ;
F_24 ( & V_33 -> V_27 , V_13 ) ;
F_45 ( 0x0008 , V_33 -> V_26 + V_77 ) ;
F_64 ( 25 ) ;
F_45 ( 0xa8050000 , V_33 -> V_26 + V_77 ) ;
F_64 ( 25 ) ;
F_45 ( 0xa00f0000 , V_33 -> V_26 + V_77 ) ;
F_64 ( 25 ) ;
F_27 ( & V_33 -> V_27 , V_13 ) ;
F_77 ( V_33 -> V_10 ) ;
}
static void F_56 ( struct V_11 * V_33 )
{
unsigned long V_13 ;
int V_2 ;
F_5 ( V_33 -> V_6 , V_16 , 0x0000 ) ;
F_19 ( V_33 ) ;
F_24 ( & V_33 -> V_27 , V_13 ) ;
F_73 ( V_33 ) ;
F_71 ( V_33 ) ;
F_72 ( V_33 ) ;
F_74 ( V_33 ) ;
F_75 ( V_33 ) ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ )
F_47 ( V_33 -> V_10 , V_33 , V_2 , V_42 [ V_2 ] ) ;
F_27 ( & V_33 -> V_27 , V_13 ) ;
F_28 ( V_33 ) ;
F_52 ( V_33 ) ;
F_77 ( V_33 -> V_10 ) ;
}
static void
F_47 ( struct V_9 * V_10 , struct V_11 * V_33 ,
int V_78 , unsigned int V_79 )
{
int V_35 ;
V_35 = F_78 ( V_33 -> V_20 [ 4 * V_78 ] ) ;
if ( V_35 > 0 ) {
short V_80 = ( ( V_35 >> 16 ) & 0x7ff ) - 4 ;
struct V_44 * V_45 ;
if ( V_80 > 1518 ) {
F_70 ( V_10 , L_18 , V_80 ) ;
V_80 = 1518 ;
}
V_45 = F_79 ( V_10 , V_80 + 2 ) ;
if ( V_45 == NULL ) {
V_10 -> V_81 . V_82 ++ ;
goto V_83;
}
F_80 ( V_45 , 2 ) ;
F_81 ( V_45 ,
& V_33 -> V_20 [ V_79 / 4 ] ,
V_80 ) ;
F_82 ( V_45 , V_80 ) ;
V_45 -> V_84 = F_83 ( V_45 , V_10 ) ;
F_84 ( V_45 ) ;
V_10 -> V_81 . V_85 ++ ;
V_10 -> V_81 . V_86 += V_80 ;
V_83:
V_33 -> V_20 [ 4 * V_78 ] = F_50 ( 0x80000000 ) ;
F_28 ( V_33 ) ;
}
}
static void
F_46 ( struct V_9 * V_10 ,
struct V_11 * V_33 ,
int V_78 , unsigned int V_79 )
{
int V_35 ;
V_35 = F_78 ( V_33 -> V_23 [ 4 * V_78 ] ) ;
#if 0
if (status & 0x8000) {
pr_err("Major transmit error status %x\n", status);
card->tx_buffer[4*descnr] = 0;
netif_wake_queue (dev);
}
#endif
if ( V_35 > 0 ) {
if ( V_33 -> V_50 [ V_78 ] != NULL ) {
V_10 -> V_81 . V_87 += V_33 -> V_50 [ V_78 ] -> V_49 ;
F_85 ( V_33 -> V_50 [ V_78 ] ) ;
}
V_33 -> V_50 [ V_78 ] = NULL ;
if ( V_35 & ( 1 << 8 ) )
V_10 -> V_81 . V_88 ++ ;
V_33 -> V_23 [ 4 * V_78 ] = 0 ;
F_86 ( V_10 ) ;
V_10 -> V_81 . V_89 ++ ;
}
}
static int T_6 F_87 ( void )
{
return F_88 ( & V_90 ) ;
}
static void T_7 F_89 ( void )
{
F_90 ( & V_90 ) ;
}
