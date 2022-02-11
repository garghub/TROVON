static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_5 ) ;
if ( V_3 == - 1 )
V_8 -> V_9 = 1 ;
else
V_8 -> V_9 = 0 ;
F_3 ( V_5 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_4 * V_5 , struct V_10 * V_11 )
{
int V_12 , V_13 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
unsigned int V_16 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
V_16 = V_2 -> V_18 . V_19 ;
V_13 = V_5 -> V_20 ;
V_12 = F_5 ( V_2 ) ;
if ( V_15 -> V_21 ( V_5 , V_12 , V_15 -> V_22 ,
NULL , NULL , NULL , V_13 ) == V_23 ) {
V_8 -> V_24 = V_12 ;
} else
V_12 = F_6 ( V_11 ) ;
F_7 ( V_2 , V_12 , V_12 ) ;
V_8 -> V_16 = V_16 ;
V_8 -> V_25 = ( V_16 & V_26 ) ? V_27 : V_28 ;
V_2 -> V_18 . V_19 &= ~ V_29 ;
F_3 ( V_5 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned int V_30 ;
V_30 = ( ( V_8 -> V_31 ) ? V_32 : 0 ) |
( ( V_8 -> V_33 ) ? V_34 : 0 ) |
( ( V_8 -> V_35 ) ? V_36 : 0 ) |
( ( V_8 -> V_37 ) ? V_38 : 0 ) |
( ( V_8 -> V_39 ) ? V_40 : 0 ) |
( ( V_8 -> V_41 ) ? V_42 : 0 ) ;
return V_30 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_43 , unsigned int V_44 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
if ( V_43 & V_32 )
V_8 -> V_31 = 1 ;
if ( V_43 & V_34 )
V_8 -> V_33 = 1 ;
if ( V_44 & V_32 )
V_8 -> V_31 = 0 ;
if ( V_44 & V_34 )
V_8 -> V_33 = 0 ;
F_3 ( V_5 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_4 * V_5 , const unsigned char * V_45 , int V_46 )
{
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_47 ;
int V_48 , V_49 ;
struct V_50 * V_51 ;
int V_52 , V_53 , V_54 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
if ( V_15 -> V_55 == V_56 ) {
V_53 = 64 ;
V_54 = 0 ;
} else {
V_53 = 63 ;
V_54 = 1 ;
}
F_11 ( & V_5 -> V_57 , L_1 , V_58 , V_46 ,
V_8 -> V_59 ) ;
for ( V_48 = V_46 ; V_48 > 0 ; V_48 -= V_49 ) {
V_49 = V_48 ;
if ( V_49 > V_53 )
V_49 = V_53 ;
V_47 = V_8 -> V_59 ;
V_51 = V_8 -> V_60 [ V_47 ] ;
if ( V_51 == NULL ) {
F_11 ( & V_5 -> V_57 , L_2 , V_58 ) ;
return V_46 ;
}
F_11 ( & V_5 -> V_57 , L_3 ,
V_58 , F_12 ( V_51 -> V_61 ) , V_47 ) ;
if ( V_51 -> V_62 == - V_63 ) {
if ( F_13 ( V_64 ,
V_8 -> V_65 [ V_47 ] + 10 * V_66 ) )
break;
F_14 ( V_51 ) ;
break;
}
( ( char * ) V_51 -> V_67 ) [ 0 ] = 0 ;
memcpy ( V_51 -> V_67 + V_54 , V_45 , V_49 ) ;
V_45 += V_49 ;
V_51 -> V_68 = V_49 + V_54 ;
V_52 = F_15 ( V_51 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_4 , V_52 ) ;
V_8 -> V_65 [ V_47 ] = V_64 ;
V_8 -> V_59 = ( V_47 + 1 ) & V_15 -> V_70 ;
}
return V_46 - V_48 ;
}
static void F_16 ( struct V_50 * V_50 )
{
int V_71 , V_52 ;
int V_72 ;
struct V_4 * V_5 ;
unsigned char * V_73 = V_50 -> V_67 ;
int V_62 = V_50 -> V_62 ;
V_72 = F_12 ( V_50 -> V_61 ) ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_5 ,
V_58 , V_62 , V_72 ) ;
return;
}
V_5 = V_50 -> V_74 ;
if ( V_50 -> V_75 ) {
if ( ( V_73 [ 0 ] & 0x80 ) == 0 ) {
if ( V_73 [ 0 ] & V_76 )
V_52 = V_77 ;
else
V_52 = 0 ;
for ( V_71 = 1 ; V_71 < V_50 -> V_75 ; ++ V_71 )
F_17 ( & V_5 -> V_5 , V_73 [ V_71 ] , V_52 ) ;
} else {
F_11 ( & V_5 -> V_57 , L_6 , V_58 ) ;
for ( V_71 = 0 ; V_71 + 1 < V_50 -> V_75 ; V_71 += 2 ) {
int V_78 = V_73 [ V_71 ] , V_79 = 0 ;
if ( V_78 & V_76 )
V_79 |= V_77 ;
if ( V_78 & V_80 )
V_79 |= V_81 ;
if ( V_78 & V_82 )
V_79 |= V_83 ;
F_17 ( & V_5 -> V_5 , V_73 [ V_71 + 1 ] ,
V_79 ) ;
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
}
static void F_19 ( struct V_50 * V_50 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
F_11 ( & V_5 -> V_57 , L_8 , V_58 , V_50 == V_8 -> V_60 [ 1 ] ) ;
F_20 ( V_5 ) ;
}
static void F_21 ( struct V_50 * V_50 )
{
}
static void F_22 ( struct V_50 * V_50 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_84 ) {
F_11 ( & V_5 -> V_57 , L_9 , V_58 ) ;
F_23 ( V_5 -> V_85 , V_5 ,
V_8 -> V_84 - 1 ) ;
}
}
static void F_24 ( struct V_50 * V_50 )
{
unsigned char * V_73 = V_50 -> V_67 ;
struct V_86 * V_87 ;
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 , V_52 ;
int V_62 = V_50 -> V_62 ;
V_85 = V_50 -> V_74 ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_10 , V_58 , V_62 ) ;
return;
}
if ( V_50 -> V_75 != 9 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_11 , V_58 , V_50 -> V_75 ) ;
goto exit;
}
V_87 = (struct V_86 * ) V_73 ;
#if 0
dev_dbg(&urb->dev->dev,
"%s - port status: port %d cts %d dcd %d dsr %d ri %d toff %d txoff %d rxen %d cr %d",
__func__, msg->port, msg->hskia_cts, msg->gpia_dcd, msg->dsr,
msg->ri, msg->_txOff, msg->_txXoff, msg->rxEnabled,
msg->controlResponse);
#endif
if ( V_87 -> V_5 >= V_85 -> V_90 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_12 , V_58 , V_87 -> V_5 ) ;
goto exit;
}
V_5 = V_85 -> V_5 [ V_87 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_39 ;
V_8 -> V_35 = ( ( V_87 -> V_91 ) ? 1 : 0 ) ;
V_8 -> V_37 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_93 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_39 )
F_25 ( & V_5 -> V_5 , true ) ;
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
exit: ;
}
static void F_26 ( struct V_50 * V_50 )
{
}
static void F_27 ( struct V_50 * V_50 )
{
int V_52 ;
struct V_4 * V_5 ;
unsigned char * V_73 ;
struct V_7 * V_8 ;
int V_62 = V_50 -> V_62 ;
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
V_73 = V_50 -> V_67 ;
if ( V_50 != V_8 -> V_95 [ V_8 -> V_96 ] )
return;
do {
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_5 ,
V_58 , V_62 , F_12 ( V_50 -> V_61 ) ) ;
return;
}
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
V_73 = V_50 -> V_67 ;
if ( V_50 -> V_75 ) {
F_28 ( & V_5 -> V_5 , V_73 ,
V_50 -> V_75 ) ;
F_18 ( & V_5 -> V_5 ) ;
}
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 ,
V_58 , V_52 ) ;
V_8 -> V_96 ^= 1 ;
V_50 = V_8 -> V_95 [ V_8 -> V_96 ] ;
} while ( V_50 -> V_62 != - V_63 );
}
static void F_29 ( struct V_50 * V_50 )
{
}
static void F_30 ( struct V_50 * V_50 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_84 ) {
F_11 ( & V_5 -> V_57 , L_9 , V_58 ) ;
F_31 ( V_5 -> V_85 , V_5 ,
V_8 -> V_84 - 1 ) ;
}
}
static void F_32 ( struct V_50 * V_50 )
{
int V_52 ;
unsigned char * V_73 = V_50 -> V_67 ;
struct V_97 * V_87 ;
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 ;
int V_62 = V_50 -> V_62 ;
V_85 = V_50 -> V_74 ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_10 , V_58 , V_62 ) ;
return;
}
if ( V_50 -> V_75 != sizeof( struct V_97 ) ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_13 , V_58 , V_50 -> V_75 ) ;
goto exit;
}
V_87 = (struct V_97 * ) V_73 ;
if ( V_87 -> V_5 >= V_85 -> V_90 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_12 , V_58 , V_87 -> V_5 ) ;
goto exit;
}
V_5 = V_85 -> V_5 [ V_87 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_39 ;
V_8 -> V_35 = ( ( V_87 -> V_98 ) ? 1 : 0 ) ;
V_8 -> V_37 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_39 && V_89 )
F_25 ( & V_5 -> V_5 , true ) ;
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
exit: ;
}
static void F_33 ( struct V_50 * V_50 )
{
}
static void F_34 ( struct V_50 * V_50 )
{
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_71 ;
V_85 = V_50 -> V_74 ;
for ( V_71 = 0 ; V_71 < V_85 -> V_90 ; ++ V_71 ) {
V_5 = V_85 -> V_5 [ V_71 ] ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_84 ) {
F_11 ( & V_5 -> V_57 , L_9 , V_58 ) ;
F_35 ( V_85 , V_5 ,
V_8 -> V_84 - 1 ) ;
break;
}
}
}
static void F_36 ( struct V_50 * V_50 )
{
int V_52 ;
unsigned char * V_73 = V_50 -> V_67 ;
struct V_100 * V_87 ;
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 ;
int V_62 = V_50 -> V_62 ;
V_85 = V_50 -> V_74 ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_10 , V_58 , V_62 ) ;
return;
}
if ( V_50 -> V_75 !=
sizeof( struct V_100 ) ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_13 , V_58 , V_50 -> V_75 ) ;
goto exit;
}
V_87 = (struct V_100 * ) V_73 ;
if ( V_87 -> V_101 >= V_85 -> V_90 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_12 ,
V_58 , V_87 -> V_101 ) ;
goto exit;
}
V_5 = V_85 -> V_5 [ V_87 -> V_101 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_39 ;
V_8 -> V_35 = ( ( V_87 -> V_98 ) ? 1 : 0 ) ;
V_8 -> V_37 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_39 && V_89 )
F_25 ( & V_5 -> V_5 , true ) ;
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
exit: ;
}
static void F_37 ( struct V_50 * V_50 )
{
}
static void F_38 ( struct V_50 * V_50 )
{
int V_71 , V_52 ;
int V_72 ;
struct V_4 * V_5 ;
unsigned char * V_73 = V_50 -> V_67 ;
int V_62 = V_50 -> V_62 ;
V_72 = F_12 ( V_50 -> V_61 ) ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_5 ,
V_58 , V_62 , V_72 ) ;
return;
}
V_5 = V_50 -> V_74 ;
if ( V_50 -> V_75 ) {
if ( ( V_73 [ 0 ] & 0x80 ) == 0 ) {
F_28 ( & V_5 -> V_5 , V_73 + 1 ,
V_50 -> V_75 - 1 ) ;
} else {
for ( V_71 = 0 ; V_71 + 1 < V_50 -> V_75 ; V_71 += 2 ) {
int V_78 = V_73 [ V_71 ] , V_79 = 0 ;
if ( V_78 & V_76 )
V_79 |= V_77 ;
if ( V_78 & V_80 )
V_79 |= V_81 ;
if ( V_78 & V_82 )
V_79 |= V_83 ;
F_17 ( & V_5 -> V_5 , V_73 [ V_71 + 1 ] ,
V_79 ) ;
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
}
static void F_39 ( struct V_50 * V_50 )
{
int V_71 , V_102 , V_103 , V_52 ;
struct V_88 * V_85 ;
struct V_4 * V_5 ;
unsigned char * V_73 = V_50 -> V_67 ;
int V_62 = V_50 -> V_62 ;
V_85 = V_50 -> V_74 ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_10 , V_58 , V_62 ) ;
return;
}
V_71 = 0 ;
V_102 = 0 ;
while ( V_71 < V_50 -> V_75 ) {
if ( V_73 [ V_71 ] >= V_85 -> V_90 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_12 ,
V_58 , V_73 [ V_71 ] ) ;
return;
}
V_5 = V_85 -> V_5 [ V_73 [ V_71 ++ ] ] ;
V_102 = V_73 [ V_71 ++ ] ;
if ( ( V_73 [ V_71 ] & 0x80 ) == 0 ) {
V_71 ++ ;
for ( V_103 = 1 ; V_103 < V_102 && V_71 < V_50 -> V_75 ; ++ V_103 )
F_17 ( & V_5 -> V_5 ,
V_73 [ V_71 ++ ] , 0 ) ;
} else {
for ( V_103 = 0 ; V_103 + 1 < V_102 &&
V_71 + 1 < V_50 -> V_75 ; V_103 += 2 ) {
int V_78 = V_73 [ V_71 ] , V_79 = 0 ;
if ( V_78 & V_76 )
V_79 |= V_77 ;
if ( V_78 & V_80 )
V_79 |= V_81 ;
if ( V_78 & V_82 )
V_79 |= V_83 ;
F_17 ( & V_5 -> V_5 , V_73 [ V_71 + 1 ] ,
V_79 ) ;
V_71 += 2 ;
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_50 -> V_57 -> V_57 , L_7 , V_58 , V_52 ) ;
}
static void F_40 ( struct V_50 * V_50 )
{
}
static void F_41 ( struct V_50 * V_50 )
{
int V_71 , V_52 ;
int V_72 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
unsigned char * V_73 = V_50 -> V_67 ;
int V_62 = V_50 -> V_62 ;
V_72 = F_12 ( V_50 -> V_61 ) ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_5 ,
V_58 , V_62 , V_72 ) ;
return;
}
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
if ( V_50 -> V_75 ) {
if ( V_8 -> V_24 > 57600 )
F_28 ( & V_5 -> V_5 , V_73 ,
V_50 -> V_75 ) ;
else {
if ( ( V_73 [ 0 ] & 0x80 ) == 0 ) {
if ( V_73 [ 0 ] & V_76 )
V_52 = V_77 ;
else
V_52 = 0 ;
for ( V_71 = 1 ; V_71 < V_50 -> V_75 ; ++ V_71 )
F_17 ( & V_5 -> V_5 ,
V_73 [ V_71 ] , V_52 ) ;
} else {
F_11 ( & V_5 -> V_57 , L_6 , V_58 ) ;
for ( V_71 = 0 ; V_71 + 1 < V_50 -> V_75 ; V_71 += 2 ) {
int V_78 = V_73 [ V_71 ] , V_79 = 0 ;
if ( V_78 & V_76 )
V_79 |= V_77 ;
if ( V_78 & V_80 )
V_79 |= V_81 ;
if ( V_78 & V_82 )
V_79 |= V_83 ;
F_17 ( & V_5 -> V_5 ,
V_73 [ V_71 + 1 ] , V_79 ) ;
}
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
}
static void F_42 ( struct V_50 * V_50 )
{
unsigned char * V_73 = V_50 -> V_67 ;
struct V_104 * V_87 ;
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 , V_52 ;
int V_62 = V_50 -> V_62 ;
V_85 = V_50 -> V_74 ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_10 , V_58 , V_62 ) ;
return;
}
if ( V_50 -> V_75 < 14 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_11 , V_58 , V_50 -> V_75 ) ;
goto exit;
}
V_87 = (struct V_104 * ) V_73 ;
V_5 = V_85 -> V_5 [ 0 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_39 ;
V_8 -> V_35 = ( ( V_87 -> V_98 ) ? 1 : 0 ) ;
V_8 -> V_37 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_39 && V_89 )
F_25 ( & V_5 -> V_5 , true ) ;
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
exit:
;
}
static void F_43 ( struct V_50 * V_50 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_50 -> V_74 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_84 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_9 , V_58 ) ;
F_44 ( V_5 -> V_85 , V_5 ,
V_8 -> V_84 - 1 ) ;
}
}
static void F_45 ( struct V_50 * V_50 )
{
int V_52 ;
unsigned char * V_73 = V_50 -> V_67 ;
struct V_105 * V_87 ;
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 ;
int V_62 = V_50 -> V_62 ;
V_85 = V_50 -> V_74 ;
if ( V_62 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_10 , V_58 , V_62 ) ;
return;
}
if ( V_50 -> V_75 !=
sizeof( struct V_105 ) ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_13 , V_58 , V_50 -> V_75 ) ;
return;
}
V_87 = (struct V_105 * ) V_73 ;
if ( V_87 -> V_5 >= V_85 -> V_90 ) {
F_11 ( & V_50 -> V_57 -> V_57 , L_12 , V_58 , V_87 -> V_5 ) ;
return;
}
V_5 = V_85 -> V_5 [ V_87 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_39 ;
V_8 -> V_35 = ( ( V_87 -> V_91 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_93 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_39 && V_89 )
F_25 ( & V_5 -> V_5 , true ) ;
V_52 = F_15 ( V_50 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_7 , V_58 , V_52 ) ;
}
static void F_46 ( struct V_50 * V_50 )
{
struct V_88 * V_85 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_71 ;
V_85 = V_50 -> V_74 ;
for ( V_71 = 0 ; V_71 < V_85 -> V_90 ; ++ V_71 ) {
V_5 = V_85 -> V_5 [ V_71 ] ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_84 ) {
F_11 ( & V_5 -> V_57 , L_9 , V_58 ) ;
F_47 ( V_85 , V_5 ,
V_8 -> V_84 - 1 ) ;
break;
}
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_47 ;
int V_106 ;
struct V_50 * V_51 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
if ( V_15 -> V_55 == V_56 )
V_106 = 64 ;
else
V_106 = 63 ;
V_47 = V_8 -> V_59 ;
V_51 = V_8 -> V_60 [ V_47 ] ;
if ( V_51 != NULL ) {
if ( V_51 -> V_62 != - V_63 )
return V_106 ;
V_47 = ( V_47 + 1 ) & V_15 -> V_70 ;
V_51 = V_8 -> V_60 [ V_47 ] ;
if ( V_51 != NULL ) {
if ( V_51 -> V_62 != - V_63 )
return V_106 ;
}
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_71 , V_52 ;
int V_12 , V_13 ;
struct V_50 * V_50 ;
unsigned int V_16 = 0 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
V_8 -> V_31 = 1 ;
V_8 -> V_33 = 1 ;
V_8 -> V_24 = 9600 ;
V_8 -> V_107 = 0 ;
V_8 -> V_108 = 0 ;
V_8 -> V_59 = 0 ;
V_8 -> V_96 = 0 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_50 = V_8 -> V_95 [ V_71 ] ;
if ( V_50 == NULL )
continue;
F_50 ( V_50 -> V_57 , V_50 -> V_61 ) ;
V_52 = F_15 ( V_50 , V_109 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_14 , V_58 , V_71 , V_52 ) ;
}
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_50 = V_8 -> V_60 [ V_71 ] ;
if ( V_50 == NULL )
continue;
}
V_13 = V_5 -> V_20 ;
if ( V_2 ) {
V_16 = V_2 -> V_18 . V_19 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 >= 0
&& V_15 -> V_21 ( V_5 , V_12 , V_15 -> V_22 ,
NULL , NULL , NULL , V_13 ) == V_23 ) {
V_8 -> V_24 = V_12 ;
}
}
V_8 -> V_16 = V_16 ;
V_8 -> V_25 = ( V_16 & V_26 ) ? V_27 : V_28 ;
F_3 ( V_5 , 1 ) ;
return 0 ;
}
static inline void F_51 ( struct V_50 * V_50 )
{
if ( V_50 && V_50 -> V_62 == - V_63 )
F_52 ( V_50 ) ;
}
static void F_53 ( struct V_4 * V_5 , int V_110 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
V_8 -> V_31 = V_110 ;
V_8 -> V_33 = V_110 ;
F_3 ( V_5 , 0 ) ;
}
static void F_54 ( struct V_4 * V_5 )
{
int V_71 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_5 ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_33 = 0 ;
F_3 ( V_5 , 2 ) ;
F_55 ( 100 ) ;
V_8 -> V_59 = 0 ;
V_8 -> V_96 = 0 ;
F_51 ( V_8 -> V_111 ) ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
F_51 ( V_8 -> V_95 [ V_71 ] ) ;
F_51 ( V_8 -> V_60 [ V_71 ] ) ;
}
}
static int F_56 ( struct V_88 * V_85 )
{
char * V_112 ;
F_11 ( & V_85 -> V_57 -> V_57 , L_15 ,
F_57 ( V_85 -> V_57 -> V_113 . V_114 ) ,
F_57 ( V_85 -> V_57 -> V_113 . V_115 ) ) ;
if ( ( F_57 ( V_85 -> V_57 -> V_113 . V_114 ) & 0x8000 )
!= 0x8000 ) {
F_11 ( & V_85 -> V_57 -> V_57 , L_16 ) ;
return 1 ;
}
switch ( F_57 ( V_85 -> V_57 -> V_113 . V_115 ) ) {
case V_116 :
V_112 = L_17 ;
break;
case V_117 :
V_112 = L_18 ;
break;
case V_118 :
V_112 = L_19 ;
break;
case V_119 :
V_112 = L_20 ;
break;
case V_120 :
V_112 = L_21 ;
break;
case V_121 :
V_112 = L_22 ;
break;
case V_122 :
V_112 = L_23 ;
break;
case V_123 :
V_112 = L_24 ;
break;
case V_124 :
V_112 = L_25 ;
break;
case V_125 :
V_112 = L_26 ;
break;
case V_126 :
V_112 = L_27 ;
break;
case V_127 :
V_112 = L_28 ;
break;
default:
F_58 ( & V_85 -> V_57 -> V_57 , L_29 ,
F_57 ( V_85 -> V_57 -> V_113 . V_115 ) ) ;
return 1 ;
}
F_11 ( & V_85 -> V_57 -> V_57 , L_30 , V_112 ) ;
if ( F_59 ( V_85 -> V_57 , V_112 ) < 0 ) {
F_58 ( & V_85 -> V_57 -> V_57 , L_31 ,
V_112 ) ;
return - V_128 ;
}
return 1 ;
}
static struct V_129 const * F_60 ( struct V_88 const * V_85 ,
int V_72 )
{
struct V_130 * V_131 ;
struct V_129 * V_132 ;
int V_71 ;
V_131 = V_85 -> V_133 -> V_134 ;
for ( V_71 = 0 ; V_71 < V_131 -> V_135 . V_136 ; ++ V_71 ) {
V_132 = & V_131 -> V_72 [ V_71 ] . V_135 ;
if ( V_132 -> V_137 == V_72 )
return V_132 ;
}
F_61 ( & V_85 -> V_133 -> V_57 , L_32
L_33 , V_72 ) ;
return NULL ;
}
static struct V_50 * F_62 ( struct V_88 * V_85 , int V_72 ,
int V_138 , void * V_139 , char * V_45 , int V_102 ,
void (* F_63)( struct V_50 * ) )
{
struct V_50 * V_50 ;
struct V_129 const * V_140 ;
char const * V_141 ;
if ( V_72 == - 1 )
return NULL ;
F_11 ( & V_85 -> V_133 -> V_57 , L_34 , V_58 , V_72 ) ;
V_50 = F_64 ( 0 , V_109 ) ;
if ( ! V_50 )
return NULL ;
if ( V_72 == 0 ) {
return V_50 ;
}
V_140 = F_60 ( V_85 , V_72 ) ;
if ( ! V_140 ) {
return V_50 ;
}
if ( F_65 ( V_140 ) ) {
V_141 = L_35 ;
F_66 ( V_50 , V_85 -> V_57 ,
F_67 ( V_85 -> V_57 , V_72 ) | V_138 ,
V_45 , V_102 , F_63 , V_139 ,
V_140 -> V_142 ) ;
} else if ( F_68 ( V_140 ) ) {
V_141 = L_36 ;
F_69 ( V_50 , V_85 -> V_57 ,
F_70 ( V_85 -> V_57 , V_72 ) | V_138 ,
V_45 , V_102 , F_63 , V_139 ) ;
} else {
F_61 ( & V_85 -> V_133 -> V_57 ,
L_37 ,
F_71 ( V_140 ) ) ;
F_72 ( V_50 ) ;
return NULL ;
}
F_11 ( & V_85 -> V_133 -> V_57 , L_38 ,
V_58 , V_50 , V_141 , V_72 ) ;
return V_50 ;
}
static void F_73 ( struct V_88 * V_85 )
{
struct V_143 * V_144 ;
const struct V_14 * V_15 ;
struct V_145 * V_146 ;
V_144 = F_74 ( V_85 ) ;
V_15 = V_144 -> V_17 ;
V_146 = & V_147 [ V_15 -> V_55 ] ;
V_144 -> V_148 = F_62
( V_85 , V_15 -> V_149 , V_150 ,
V_85 , V_144 -> V_151 , V_152 ,
V_146 -> V_153 ) ;
V_144 -> V_154 = F_62
( V_85 , V_15 -> V_155 , V_150 ,
V_85 , V_144 -> V_156 , V_157 ,
F_39 ) ;
V_144 -> V_158 = F_62
( V_85 , V_15 -> V_159 , V_160 ,
V_85 , V_144 -> V_161 , V_162 ,
V_146 -> V_163 ) ;
}
static int F_75 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_22 , T_2 * V_164 ,
T_2 * V_165 , T_2 * V_166 , int V_167 )
{
T_1 V_168 ,
div ,
V_169 ;
F_11 ( & V_5 -> V_57 , L_39 , V_58 , V_12 ) ;
V_168 = V_12 * 16L ;
if ( V_168 == 0 )
return V_170 ;
if ( V_12 > 57600 )
return V_170 ;
div = V_22 / V_168 ;
if ( div == 0 )
return V_170 ;
else
V_169 = 0 - div ;
if ( div > 0xffff )
return V_170 ;
if ( V_165 )
* V_165 = ( T_2 ) ( V_169 & 0xff ) ;
if ( V_164 )
* V_164 = ( T_2 ) ( ( V_169 >> 8 ) & 0xff ) ;
if ( V_165 && V_164 )
F_11 ( & V_5 -> V_57 , L_40 ,
V_58 , V_12 , * V_164 , * V_165 ) ;
return V_23 ;
}
static int F_76 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_22 , T_2 * V_164 ,
T_2 * V_165 , T_2 * V_166 , int V_167 )
{
T_1 V_168 ,
div ;
F_11 ( & V_5 -> V_57 , L_39 , V_58 , V_12 ) ;
V_168 = V_12 * 16L ;
if ( V_168 == 0 )
return V_170 ;
div = V_22 / V_168 ;
if ( div == 0 )
return V_170 ;
if ( div > 0xffff )
return V_170 ;
if ( V_165 )
* V_165 = ( T_2 ) ( div & 0xff ) ;
if ( V_164 )
* V_164 = ( T_2 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_165 && V_164 )
F_11 ( & V_5 -> V_57 , L_40 ,
V_58 , V_12 , * V_164 , * V_165 ) ;
return V_23 ;
}
static int F_77 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_22 , T_2 * V_164 ,
T_2 * V_165 , T_2 * V_166 , int V_167 )
{
T_1 V_168 ,
V_171 ,
div ,
V_172 ,
V_173 ,
V_174 ;
T_2 V_175 ;
int V_71 ;
F_11 ( & V_5 -> V_57 , L_39 , V_58 , V_12 ) ;
V_168 = V_12 * 16L ;
if ( V_168 == 0 )
return V_170 ;
V_174 = 0xffffffff ;
V_175 = 0 ;
for ( V_71 = 8 ; V_71 <= 0xff ; ++ V_71 ) {
V_171 = ( V_22 * 8 ) / ( T_1 ) V_71 ;
div = V_171 / V_168 ;
if ( div == 0 )
continue;
V_172 = V_171 / div ;
V_173 = ( V_172 > V_168 ) ? ( V_172 - V_168 ) : ( V_168 - V_172 ) ;
if ( V_173 < V_174 ) {
V_175 = V_71 ;
V_174 = V_173 ;
}
}
if ( V_175 == 0 )
return V_170 ;
V_171 = ( V_22 * 8 ) / ( T_1 ) V_175 ;
div = V_171 / V_168 ;
if ( V_165 )
* V_165 = ( T_2 ) ( div & 0xff ) ;
if ( V_164 )
* V_164 = ( T_2 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_166 ) {
* V_166 = V_175 ;
}
return V_23 ;
}
static int F_78 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_22 , T_2 * V_164 ,
T_2 * V_165 , T_2 * V_166 , int V_167 )
{
T_1 V_168 ,
div ,
V_169 ;
F_11 ( & V_5 -> V_57 , L_39 , V_58 , V_12 ) ;
V_168 = V_12 * 16L ;
if ( V_168 == 0 )
return V_170 ;
div = V_176 / V_168 ;
if ( div == 0 )
return V_170 ;
else
V_169 = 0 - div ;
if ( V_167 == 0 ) {
if ( div > 0xffff )
return V_170 ;
} else {
if ( V_167 == 1 ) {
if ( div > 0xff )
return V_170 ;
} else
return V_170 ;
}
if ( V_165 )
* V_165 = ( T_2 ) ( V_169 & 0xff ) ;
if ( V_164 )
* V_164 = ( T_2 ) ( ( V_169 >> 8 ) & 0xff ) ;
F_11 ( & V_5 -> V_57 , L_41 , V_58 , V_12 ) ;
return V_23 ;
}
static int F_23 ( struct V_88 * V_85 ,
struct V_4 * V_5 ,
int V_177 )
{
struct V_178 V_87 ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_50 * V_51 ;
int V_13 , V_52 ;
F_11 ( & V_5 -> V_57 , L_42 , V_58 , V_177 ) ;
V_144 = F_74 ( V_85 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_144 -> V_17 ;
V_13 = V_5 -> V_20 ;
V_51 = V_8 -> V_179 ;
F_11 ( & V_5 -> V_57 , L_43 , V_58 , F_12 ( V_51 -> V_61 ) ) ;
if ( V_51 == NULL ) {
F_11 ( & V_5 -> V_57 , L_44 , V_58 ) ;
return - 1 ;
}
if ( ( V_177 + 1 ) > V_8 -> V_84 )
V_8 -> V_84 = V_177 + 1 ;
if ( V_51 -> V_62 == - V_63 ) {
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_178 ) ) ;
if ( V_8 -> V_107 != V_8 -> V_24 ) {
V_8 -> V_107 = V_8 -> V_24 ;
V_87 . V_180 = 0xff ;
if ( V_15 -> V_21 ( V_5 , V_8 -> V_24 , V_15 -> V_22 ,
& V_87 . V_181 , & V_87 . V_182 , & V_87 . V_166 ,
V_13 ) == V_170 ) {
F_11 ( & V_5 -> V_57 , L_45 ,
V_58 , V_8 -> V_24 ) ;
V_87 . V_182 = 0 ;
V_87 . V_181 = 125 ;
V_87 . V_166 = 10 ;
}
V_87 . V_183 = 0xff ;
}
V_87 . V_184 = ( V_8 -> V_16 & V_185 ) ? V_186 : V_187 ;
switch ( V_8 -> V_16 & V_188 ) {
case V_189 :
V_87 . V_184 |= V_190 ;
break;
case V_191 :
V_87 . V_184 |= V_192 ;
break;
case V_193 :
V_87 . V_184 |= V_194 ;
break;
case V_195 :
V_87 . V_184 |= V_196 ;
break;
}
if ( V_8 -> V_16 & V_197 ) {
V_87 . V_184 |= ( V_8 -> V_16 & V_198 ) ?
V_199 : V_200 ;
}
V_87 . V_201 = 0xff ;
V_87 . V_202 = ( V_8 -> V_25 == V_27 ) ;
V_87 . V_203 = 0 ;
V_87 . V_204 = 0xff ;
V_87 . V_205 = 16 ;
V_87 . V_206 = 17 ;
V_87 . V_207 = 19 ;
if ( V_177 == 1 ) {
V_87 . V_208 = 1 ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 1 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0xff ;
}
else if ( V_177 == 2 ) {
V_87 . V_208 = 0 ;
V_87 . V_209 = 1 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 1 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0 ;
}
else {
V_87 . V_208 = ( ! V_8 -> V_9 ) ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = ( V_8 -> V_9 ) ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 0 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0x0 ;
}
V_87 . V_218 = 0xff ;
V_87 . V_219 = V_8 -> V_31 ;
V_87 . V_220 = 0xff ;
V_87 . V_221 = V_8 -> V_33 ;
V_8 -> V_84 = 0 ;
memcpy ( V_51 -> V_67 , & V_87 , sizeof( V_87 ) ) ;
V_51 -> V_68 = sizeof( V_87 ) ;
V_52 = F_15 ( V_51 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_46 , V_58 , V_52 ) ;
return 0 ;
}
static int F_31 ( struct V_88 * V_85 ,
struct V_4 * V_5 ,
int V_177 )
{
struct V_222 V_87 ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_50 * V_51 ;
int V_13 , V_52 ;
V_144 = F_74 ( V_85 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_144 -> V_17 ;
V_13 = V_5 -> V_20 ;
V_51 = V_8 -> V_179 ;
if ( V_51 == NULL ) {
F_11 ( & V_5 -> V_57 , L_44 , V_58 ) ;
return - 1 ;
}
if ( ( V_177 + 1 ) > V_8 -> V_84 )
V_8 -> V_84 = V_177 + 1 ;
if ( V_51 -> V_62 == - V_63 ) {
F_11 ( & V_5 -> V_57 , L_47 , V_58 ) ;
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_222 ) ) ;
V_87 . V_223 = 1 ;
if ( V_15 -> V_21 ( V_5 , V_8 -> V_24 , V_15 -> V_22 ,
& V_87 . V_181 , & V_87 . V_182 , NULL ,
V_13 ) == V_170 ) {
F_11 ( & V_5 -> V_57 , L_48 ,
V_58 , V_8 -> V_24 ) ;
V_87 . V_182 = 0xff ;
V_87 . V_181 = 0xb2 ;
}
V_87 . V_224 = 0 ;
V_87 . V_202 = ( V_8 -> V_25 == V_27 ) ;
V_87 . V_203 = 0 ;
V_87 . V_225 = V_8 -> V_31 ;
V_87 . V_226 = V_8 -> V_33 ;
V_87 . V_205 = 16 ;
V_87 . V_227 = 10 ;
V_87 . V_228 = 45 ;
V_87 . V_206 = 17 ;
V_87 . V_207 = 19 ;
if ( V_177 == 1 ) {
V_87 . V_208 = 1 ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_229 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 1 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0xff ;
}
else if ( V_177 == 2 ) {
V_87 . V_208 = 0 ;
V_87 . V_209 = 1 ;
V_87 . V_210 = 0 ;
V_87 . V_229 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 1 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0 ;
}
else {
V_87 . V_208 = ( ! V_8 -> V_9 ) ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_229 = 0 ;
V_87 . V_211 = ( V_8 -> V_9 ) ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 0 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0x0 ;
}
V_8 -> V_84 = 0 ;
memcpy ( V_51 -> V_67 , & V_87 , sizeof( V_87 ) ) ;
V_51 -> V_68 = sizeof( V_87 ) ;
V_52 = F_15 ( V_51 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_49 , V_58 ) ;
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) OK %d bytes\n", __func__,
this_urb->transfer_buffer_length);
}
#endif
return 0 ;
}
static int F_35 ( struct V_88 * V_85 ,
struct V_4 * V_5 ,
int V_177 )
{
struct V_230 V_87 ;
struct V_231 * V_232 = NULL ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_50 * V_51 ;
int V_52 , V_13 ;
V_144 = F_74 ( V_85 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_144 -> V_17 ;
V_51 = V_144 -> V_158 ;
V_13 = V_5 -> V_20 ;
if ( V_51 == NULL ) {
F_11 ( & V_5 -> V_57 , L_50 , V_58 ) ;
return - 1 ;
}
F_11 ( & V_5 -> V_57 , L_51 ,
V_58 , F_12 ( V_51 -> V_61 ) , V_13 ) ;
if ( ( V_177 + 1 ) > V_8 -> V_84 )
V_8 -> V_84 = V_177 + 1 ;
if ( V_51 -> V_62 == - V_63 ) {
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_230 ) ) ;
V_87 . V_101 = V_13 ;
if ( V_8 -> V_107 != V_8 -> V_24 ) {
V_8 -> V_107 = V_8 -> V_24 ;
V_87 . V_180 = 0xff ;
if ( V_15 -> V_21 ( V_5 , V_8 -> V_24 , V_15 -> V_22 ,
& V_87 . V_181 , & V_87 . V_182 , & V_87 . V_166 ,
V_13 ) == V_170 ) {
F_11 ( & V_5 -> V_57 , L_45 ,
V_58 , V_8 -> V_24 ) ;
V_87 . V_182 = 0 ;
V_87 . V_181 = 125 ;
V_87 . V_166 = 10 ;
}
}
V_87 . V_184 = ( V_8 -> V_16 & V_185 ) ? V_186 : V_187 ;
switch ( V_8 -> V_16 & V_188 ) {
case V_189 :
V_87 . V_184 |= V_190 ;
break;
case V_191 :
V_87 . V_184 |= V_192 ;
break;
case V_193 :
V_87 . V_184 |= V_194 ;
break;
case V_195 :
V_87 . V_184 |= V_196 ;
break;
}
if ( V_8 -> V_16 & V_197 ) {
V_87 . V_184 |= ( V_8 -> V_16 & V_198 ) ?
V_199 : V_200 ;
}
V_87 . V_201 = 0xff ;
V_87 . V_202 = ( V_8 -> V_25 == V_27 ) ;
V_87 . V_203 = 0 ;
V_87 . V_204 = 0xff ;
V_87 . V_205 = 16 ;
V_87 . V_206 = 17 ;
V_87 . V_207 = 19 ;
if ( V_177 == 1 ) {
V_87 . V_208 = 1 ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 1 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0xff ;
V_87 . V_233 = 1 ;
V_87 . V_234 = 0 ;
}
else if ( V_177 == 2 ) {
V_87 . V_208 = 0 ;
V_87 . V_209 = 1 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 1 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0 ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 1 ;
}
else {
V_87 . V_208 = ( ! V_8 -> V_9 ) ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = ( V_8 -> V_9 ) ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 0 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0x0 ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 0 ;
}
V_87 . V_235 = 0xff ;
V_87 . V_225 = V_8 -> V_31 ;
V_87 . V_236 = 0xff ;
V_87 . V_226 = V_8 -> V_33 ;
V_8 -> V_84 = 0 ;
if ( V_15 -> V_237 == V_238 ) {
V_232 = ( void * ) ( V_144 -> V_239 ) ;
V_232 -> V_240 = V_241 | V_160 ;
V_232 -> V_242 = 0xB0 ; ;
V_232 -> V_243 = 0 ;
V_232 -> V_244 = 0 ;
V_232 -> V_245 = F_79 ( sizeof( V_87 ) ) ;
memcpy ( V_144 -> V_161 , & V_87 , sizeof( V_87 ) ) ;
F_80 ( V_51 , V_85 -> V_57 ,
F_81 ( V_85 -> V_57 , 0 ) ,
( unsigned char * ) V_232 , V_144 -> V_161 ,
sizeof( V_87 ) , F_34 , V_85 ) ;
} else {
memcpy ( V_51 -> V_67 , & V_87 , sizeof( V_87 ) ) ;
V_51 -> V_68 = sizeof( V_87 ) ;
}
V_52 = F_15 ( V_51 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_46 , V_58 , V_52 ) ;
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(%d) OK %d bytes (end %d)\n", __func__,
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0 ;
}
static int F_44 ( struct V_88 * V_85 ,
struct V_4 * V_5 ,
int V_177 )
{
struct V_246 V_87 ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_50 * V_51 ;
int V_52 ;
T_2 V_166 ;
V_144 = F_74 ( V_85 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_144 -> V_17 ;
V_51 = V_8 -> V_179 ;
if ( V_51 == NULL ) {
F_11 ( & V_5 -> V_57 , L_44 , V_58 ) ;
return - 1 ;
}
if ( ( V_177 + 1 ) > V_8 -> V_84 )
V_8 -> V_84 = V_177 + 1 ;
if ( V_51 -> V_62 == - V_63 ) {
F_11 ( & V_5 -> V_57 , L_47 , V_58 ) ;
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_246 ) ) ;
if ( V_8 -> V_107 != V_8 -> V_24 ) {
V_8 -> V_107 = V_8 -> V_24 ;
V_87 . V_180 = 0x01 ;
if ( V_15 -> V_21 ( V_5 , V_8 -> V_24 , V_15 -> V_22 ,
& V_87 . V_181 , & V_87 . V_182 , & V_166 , 0 ) == V_170 ) {
F_11 ( & V_5 -> V_57 , L_45 ,
V_58 , V_8 -> V_24 ) ;
V_8 -> V_24 = 9600 ;
V_15 -> V_21 ( V_5 , V_8 -> V_24 , V_15 -> V_22 ,
& V_87 . V_181 , & V_87 . V_182 , & V_166 , 0 ) ;
}
V_87 . V_247 = 1 ;
V_87 . V_248 = 1 ;
}
if ( V_8 -> V_24 > 57600 ) {
V_87 . V_249 = V_250 ;
V_87 . V_251 = V_252 ;
} else {
V_87 . V_249 = V_253 ;
V_87 . V_251 = V_254 ;
}
V_87 . V_184 = ( V_8 -> V_16 & V_185 ) ? V_186 : V_187 ;
switch ( V_8 -> V_16 & V_188 ) {
case V_189 :
V_87 . V_184 |= V_190 ;
break;
case V_191 :
V_87 . V_184 |= V_192 ;
break;
case V_193 :
V_87 . V_184 |= V_194 ;
break;
case V_195 :
V_87 . V_184 |= V_196 ;
break;
}
if ( V_8 -> V_16 & V_197 ) {
V_87 . V_184 |= ( V_8 -> V_16 & V_198 ) ?
V_199 : V_200 ;
}
if ( V_8 -> V_108 != V_8 -> V_16 ) {
V_8 -> V_108 = V_8 -> V_16 ;
V_87 . V_201 = 0x01 ;
}
if ( V_8 -> V_25 == V_27 )
V_87 . V_255 = V_256 ;
V_87 . V_257 = 0x01 ;
V_87 . V_258 = 0x01 ;
V_87 . V_259 = 16 ;
V_87 . V_260 = 16 ;
V_87 . V_261 = 0 ;
V_87 . V_206 = 17 ;
V_87 . V_207 = 19 ;
if ( V_177 == 1 ) {
V_87 . V_262 = 1 ;
V_87 . V_214 = 1 ;
V_87 . V_211 = ( V_8 -> V_9 ) ;
}
else if ( V_177 == 2 )
V_87 . V_262 = 0 ;
else {
V_87 . V_262 = 1 ;
V_87 . V_211 = ( V_8 -> V_9 ) ;
}
V_87 . V_235 = 0x01 ;
V_87 . V_225 = V_8 -> V_31 ;
V_87 . V_236 = 0x01 ;
V_87 . V_226 = V_8 -> V_33 ;
V_8 -> V_84 = 0 ;
memcpy ( V_51 -> V_67 , & V_87 , sizeof( V_87 ) ) ;
V_51 -> V_68 = sizeof( V_87 ) ;
V_52 = F_15 ( V_51 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_46 , V_58 , V_52 ) ;
return 0 ;
}
static int F_47 ( struct V_88 * V_85 ,
struct V_4 * V_5 ,
int V_177 )
{
struct V_263 V_87 ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_50 * V_51 ;
int V_52 , V_13 ;
V_144 = F_74 ( V_85 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_144 -> V_17 ;
V_51 = V_144 -> V_158 ;
V_13 = V_5 -> V_20 ;
if ( V_51 == NULL ) {
F_11 ( & V_5 -> V_57 , L_50 , V_58 ) ;
return - 1 ;
}
if ( ( V_177 + 1 ) > V_8 -> V_84 )
V_8 -> V_84 = V_177 + 1 ;
if ( V_51 -> V_62 == - V_63 ) {
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_263 ) ) ;
V_87 . V_5 = V_13 ;
if ( V_8 -> V_107 != V_8 -> V_24 ) {
V_8 -> V_107 = V_8 -> V_24 ;
V_87 . V_180 = 0xff ;
if ( V_15 -> V_21 ( V_5 , V_8 -> V_24 , V_15 -> V_22 ,
& V_87 . V_181 , & V_87 . V_182 , & V_87 . V_166 ,
V_13 ) == V_170 ) {
F_11 ( & V_5 -> V_57 , L_45 ,
V_58 , V_8 -> V_24 ) ;
V_87 . V_182 = 0 ;
V_87 . V_181 = 125 ;
V_87 . V_166 = 10 ;
}
V_87 . V_183 = 0xff ;
}
V_87 . V_184 = ( V_8 -> V_16 & V_185 ) ? V_186 : V_187 ;
switch ( V_8 -> V_16 & V_188 ) {
case V_189 :
V_87 . V_184 |= V_190 ;
break;
case V_191 :
V_87 . V_184 |= V_192 ;
break;
case V_193 :
V_87 . V_184 |= V_194 ;
break;
case V_195 :
V_87 . V_184 |= V_196 ;
break;
}
if ( V_8 -> V_16 & V_197 ) {
V_87 . V_184 |= ( V_8 -> V_16 & V_198 ) ?
V_199 : V_200 ;
}
V_87 . V_201 = 0xff ;
V_87 . V_202 = ( V_8 -> V_25 == V_27 ) ;
V_87 . V_203 = 0 ;
V_87 . V_204 = 0xff ;
V_87 . V_205 = 16 ;
V_87 . V_206 = 17 ;
V_87 . V_207 = 19 ;
if ( V_177 == 1 ) {
V_87 . V_208 = 1 ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 1 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0xff ;
} else if ( V_177 == 2 ) {
V_87 . V_208 = 0 ;
V_87 . V_209 = 1 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = 0 ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 1 ;
V_87 . V_214 = 1 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0 ;
} else {
V_87 . V_208 = ( ! V_8 -> V_9 ) ;
V_87 . V_209 = 0 ;
V_87 . V_210 = 0 ;
V_87 . V_211 = ( V_8 -> V_9 ) ;
V_87 . V_212 = 0 ;
V_87 . V_213 = 0 ;
V_87 . V_214 = 0 ;
V_87 . V_215 = 0 ;
V_87 . V_216 = 0 ;
V_87 . V_217 = 0x0 ;
}
V_87 . V_218 = 0xff ;
V_87 . V_219 = V_8 -> V_31 ;
V_87 . V_220 = 0xff ;
V_87 . V_221 = V_8 -> V_33 ;
V_8 -> V_84 = 0 ;
memcpy ( V_51 -> V_67 , & V_87 , sizeof( V_87 ) ) ;
V_51 -> V_68 = sizeof( V_87 ) ;
V_52 = F_15 ( V_51 , V_69 ) ;
if ( V_52 != 0 )
F_11 ( & V_5 -> V_57 , L_46 , V_58 , V_52 ) ;
return 0 ;
}
static void F_3 ( struct V_4 * V_5 , int V_177 )
{
struct V_88 * V_85 = V_5 -> V_85 ;
struct V_143 * V_144 ;
const struct V_14 * V_15 ;
V_144 = F_74 ( V_85 ) ;
V_15 = V_144 -> V_17 ;
switch ( V_15 -> V_55 ) {
case V_264 :
F_23 ( V_85 , V_5 , V_177 ) ;
break;
case V_265 :
F_31 ( V_85 , V_5 , V_177 ) ;
break;
case V_266 :
F_35 ( V_85 , V_5 , V_177 ) ;
break;
case V_56 :
F_44 ( V_85 , V_5 , V_177 ) ;
break;
case V_267 :
F_47 ( V_85 , V_5 , V_177 ) ;
break;
}
}
static int F_82 ( struct V_88 * V_85 )
{
int V_71 , V_52 ;
struct V_143 * V_144 ;
const struct V_14 * V_15 ;
for ( V_71 = 0 ; ( V_15 = V_268 [ V_71 ] ) != NULL ; ++ V_71 )
if ( V_15 -> V_237 ==
F_57 ( V_85 -> V_57 -> V_113 . V_115 ) )
break;
if ( V_15 == NULL ) {
F_58 ( & V_85 -> V_57 -> V_57 , L_52 ,
V_58 , F_57 ( V_85 -> V_57 -> V_113 . V_115 ) ) ;
return - V_269 ;
}
V_144 = F_83 ( sizeof( struct V_143 ) , V_109 ) ;
if ( ! V_144 )
return - V_270 ;
V_144 -> V_151 = F_83 ( V_152 , V_109 ) ;
if ( ! V_144 -> V_151 )
goto V_271;
V_144 -> V_156 = F_83 ( V_157 , V_109 ) ;
if ( ! V_144 -> V_156 )
goto V_272;
V_144 -> V_161 = F_83 ( V_162 , V_109 ) ;
if ( ! V_144 -> V_161 )
goto V_273;
V_144 -> V_239 = F_83 ( sizeof( struct V_231 ) , V_109 ) ;
if ( ! V_144 -> V_239 )
goto V_274;
V_144 -> V_17 = V_15 ;
F_84 ( V_85 , V_144 ) ;
F_73 ( V_85 ) ;
if ( V_144 -> V_148 != NULL ) {
V_52 = F_15 ( V_144 -> V_148 , V_109 ) ;
if ( V_52 != 0 )
F_11 ( & V_85 -> V_57 -> V_57 , L_53 , V_58 , V_52 ) ;
}
if ( V_144 -> V_154 != NULL ) {
V_52 = F_15 ( V_144 -> V_154 , V_109 ) ;
if ( V_52 != 0 )
F_11 ( & V_85 -> V_57 -> V_57 , L_54 , V_58 , V_52 ) ;
}
return 0 ;
V_274:
F_85 ( V_144 -> V_161 ) ;
V_273:
F_85 ( V_144 -> V_156 ) ;
V_272:
F_85 ( V_144 -> V_151 ) ;
V_271:
F_85 ( V_144 ) ;
return - V_270 ;
}
static void F_86 ( struct V_88 * V_85 )
{
struct V_143 * V_144 ;
V_144 = F_74 ( V_85 ) ;
F_51 ( V_144 -> V_148 ) ;
F_51 ( V_144 -> V_158 ) ;
F_51 ( V_144 -> V_154 ) ;
}
static void F_87 ( struct V_88 * V_85 )
{
struct V_143 * V_144 ;
V_144 = F_74 ( V_85 ) ;
F_72 ( V_144 -> V_148 ) ;
F_72 ( V_144 -> V_154 ) ;
F_72 ( V_144 -> V_158 ) ;
F_85 ( V_144 -> V_239 ) ;
F_85 ( V_144 -> V_161 ) ;
F_85 ( V_144 -> V_156 ) ;
F_85 ( V_144 -> V_151 ) ;
F_85 ( V_144 ) ;
}
static int F_88 ( struct V_4 * V_5 )
{
struct V_88 * V_85 = V_5 -> V_85 ;
struct V_143 * V_144 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_145 * V_146 ;
int V_275 ;
int V_276 ;
int V_71 ;
V_144 = F_74 ( V_85 ) ;
V_15 = V_144 -> V_17 ;
V_8 = F_83 ( sizeof( * V_8 ) , V_109 ) ;
if ( ! V_8 )
return - V_270 ;
for ( V_71 = 0 ; V_71 < F_89 ( V_8 -> V_277 ) ; ++ V_71 ) {
V_8 -> V_277 [ V_71 ] = F_83 ( V_278 , V_109 ) ;
if ( ! V_8 -> V_277 [ V_71 ] )
goto V_279;
}
for ( V_71 = 0 ; V_71 < F_89 ( V_8 -> V_280 ) ; ++ V_71 ) {
V_8 -> V_280 [ V_71 ] = F_83 ( V_281 , V_109 ) ;
if ( ! V_8 -> V_280 [ V_71 ] )
goto V_282;
}
V_8 -> V_283 = F_83 ( V_284 , V_109 ) ;
if ( ! V_8 -> V_283 )
goto V_285;
V_8 -> V_286 = F_83 ( V_287 , V_109 ) ;
if ( ! V_8 -> V_286 )
goto V_288;
V_8 -> V_17 = V_15 ;
V_146 = & V_147 [ V_15 -> V_55 ] ;
V_276 = V_5 -> V_20 ;
V_275 = V_15 -> V_289 [ V_276 ] ;
for ( V_71 = 0 ; V_71 <= V_15 -> V_290 ; ++ V_71 , ++ V_275 ) {
V_8 -> V_95 [ V_71 ] = F_62 ( V_85 , V_275 ,
V_150 , V_5 ,
V_8 -> V_277 [ V_71 ] ,
V_278 ,
V_146 -> V_291 ) ;
}
V_275 = V_15 -> V_292 [ V_276 ] ;
for ( V_71 = 0 ; V_71 <= V_15 -> V_70 ; ++ V_71 , ++ V_275 ) {
V_8 -> V_60 [ V_71 ] = F_62 ( V_85 , V_275 ,
V_160 , V_5 ,
V_8 -> V_280 [ V_71 ] ,
V_281 ,
V_146 -> V_293 ) ;
}
V_8 -> V_111 = F_62 ( V_85 ,
V_15 -> V_294 [ V_276 ] ,
V_150 , V_5 ,
V_8 -> V_283 ,
V_284 ,
V_146 -> V_295 ) ;
V_8 -> V_179 = F_62 ( V_85 ,
V_15 -> V_296 [ V_276 ] ,
V_160 , V_5 ,
V_8 -> V_286 ,
V_287 ,
V_146 -> V_297 ) ;
F_90 ( V_5 , V_8 ) ;
return 0 ;
V_288:
F_85 ( V_8 -> V_283 ) ;
V_285:
for ( V_71 = 0 ; V_71 < F_89 ( V_8 -> V_280 ) ; ++ V_71 )
F_85 ( V_8 -> V_280 [ V_71 ] ) ;
V_282:
for ( V_71 = 0 ; V_71 < F_89 ( V_8 -> V_277 ) ; ++ V_71 )
F_85 ( V_8 -> V_277 [ V_71 ] ) ;
V_279:
F_85 ( V_8 ) ;
return - V_270 ;
}
static int F_91 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
int V_71 ;
V_8 = F_2 ( V_5 ) ;
F_51 ( V_8 -> V_111 ) ;
F_51 ( V_8 -> V_179 ) ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
F_51 ( V_8 -> V_95 [ V_71 ] ) ;
F_51 ( V_8 -> V_60 [ V_71 ] ) ;
}
F_72 ( V_8 -> V_111 ) ;
F_72 ( V_8 -> V_179 ) ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
F_72 ( V_8 -> V_95 [ V_71 ] ) ;
F_72 ( V_8 -> V_60 [ V_71 ] ) ;
}
F_85 ( V_8 -> V_286 ) ;
F_85 ( V_8 -> V_283 ) ;
for ( V_71 = 0 ; V_71 < F_89 ( V_8 -> V_280 ) ; ++ V_71 )
F_85 ( V_8 -> V_280 [ V_71 ] ) ;
for ( V_71 = 0 ; V_71 < F_89 ( V_8 -> V_277 ) ; ++ V_71 )
F_85 ( V_8 -> V_277 [ V_71 ] ) ;
F_85 ( V_8 ) ;
return 0 ;
}
