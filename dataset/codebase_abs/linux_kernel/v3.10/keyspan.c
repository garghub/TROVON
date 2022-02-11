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
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_12 = F_5 ( V_2 ) ;
if ( V_15 -> V_23 ( V_5 , V_12 , V_15 -> V_24 ,
NULL , NULL , NULL , V_13 ) == V_25 ) {
V_8 -> V_26 = V_12 ;
} else
V_12 = F_6 ( V_11 ) ;
F_7 ( V_2 , V_12 , V_12 ) ;
V_8 -> V_16 = V_16 ;
V_8 -> V_27 = ( V_16 & V_28 ) ? V_29 : V_30 ;
V_2 -> V_18 . V_19 &= ~ V_31 ;
F_3 ( V_5 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
unsigned int V_32 ;
V_32 = ( ( V_8 -> V_33 ) ? V_34 : 0 ) |
( ( V_8 -> V_35 ) ? V_36 : 0 ) |
( ( V_8 -> V_37 ) ? V_38 : 0 ) |
( ( V_8 -> V_39 ) ? V_40 : 0 ) |
( ( V_8 -> V_41 ) ? V_42 : 0 ) |
( ( V_8 -> V_43 ) ? V_44 : 0 ) ;
return V_32 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_45 , unsigned int V_46 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ) ;
if ( V_45 & V_34 )
V_8 -> V_33 = 1 ;
if ( V_45 & V_36 )
V_8 -> V_35 = 1 ;
if ( V_46 & V_34 )
V_8 -> V_33 = 0 ;
if ( V_46 & V_36 )
V_8 -> V_35 = 0 ;
F_3 ( V_5 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_4 * V_5 , const unsigned char * V_47 , int V_48 )
{
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_49 ;
int V_50 , V_51 ;
struct V_52 * V_53 ;
int V_54 , V_55 , V_56 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
if ( V_15 -> V_57 == V_58 ) {
V_55 = 64 ;
V_56 = 0 ;
} else {
V_55 = 63 ;
V_56 = 1 ;
}
F_11 ( & V_5 -> V_59 , L_1 ,
V_60 , V_5 -> V_20 , V_48 , V_8 -> V_61 ) ;
for ( V_50 = V_48 ; V_50 > 0 ; V_50 -= V_51 ) {
V_51 = V_50 ;
if ( V_51 > V_55 )
V_51 = V_55 ;
V_49 = V_8 -> V_61 ;
V_53 = V_8 -> V_62 [ V_49 ] ;
if ( V_53 == NULL ) {
F_11 ( & V_5 -> V_59 , L_2 , V_60 ) ;
return V_48 ;
}
F_11 ( & V_5 -> V_59 , L_3 ,
V_60 , F_12 ( V_53 -> V_63 ) , V_49 ) ;
if ( V_53 -> V_64 == - V_65 ) {
if ( F_13 ( V_66 ,
V_8 -> V_67 [ V_49 ] + 10 * V_68 ) )
break;
F_14 ( V_53 ) ;
break;
}
( ( char * ) V_53 -> V_69 ) [ 0 ] = 0 ;
memcpy ( V_53 -> V_69 + V_56 , V_47 , V_51 ) ;
V_47 += V_51 ;
V_53 -> V_70 = V_51 + V_56 ;
V_54 = F_15 ( V_53 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_4 , V_54 ) ;
V_8 -> V_67 [ V_49 ] = V_66 ;
V_8 -> V_61 = ( V_49 + 1 ) & V_15 -> V_72 ;
}
return V_48 - V_50 ;
}
static void F_16 ( struct V_52 * V_52 )
{
int V_73 , V_54 ;
int V_74 ;
struct V_4 * V_5 ;
unsigned char * V_75 = V_52 -> V_69 ;
int V_64 = V_52 -> V_64 ;
V_74 = F_12 ( V_52 -> V_63 ) ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_5 ,
V_60 , V_64 , V_74 ) ;
return;
}
V_5 = V_52 -> V_76 ;
if ( V_52 -> V_77 ) {
if ( ( V_75 [ 0 ] & 0x80 ) == 0 ) {
if ( V_75 [ 0 ] & V_78 )
V_54 = V_79 ;
else
V_54 = 0 ;
for ( V_73 = 1 ; V_73 < V_52 -> V_77 ; ++ V_73 )
F_17 ( & V_5 -> V_5 , V_75 [ V_73 ] , V_54 ) ;
} else {
F_11 ( & V_5 -> V_59 , L_6 , V_60 ) ;
for ( V_73 = 0 ; V_73 + 1 < V_52 -> V_77 ; V_73 += 2 ) {
int V_80 = V_75 [ V_73 ] , V_81 = 0 ;
if ( V_80 & V_78 )
V_81 |= V_79 ;
if ( V_80 & V_82 )
V_81 |= V_83 ;
if ( V_80 & V_84 )
V_81 |= V_85 ;
F_17 ( & V_5 -> V_5 , V_75 [ V_73 + 1 ] ,
V_81 ) ;
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
}
static void F_19 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
F_11 ( & V_5 -> V_59 , L_8 , V_60 , V_52 == V_8 -> V_62 [ 1 ] ) ;
F_20 ( V_5 ) ;
}
static void F_21 ( struct V_52 * V_52 )
{
}
static void F_22 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_86 ) {
F_11 ( & V_5 -> V_59 , L_9 , V_60 ) ;
F_23 ( V_5 -> V_21 , V_5 ,
V_8 -> V_86 - 1 ) ;
}
}
static void F_24 ( struct V_52 * V_52 )
{
unsigned char * V_75 = V_52 -> V_69 ;
struct V_87 * V_88 ;
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_90 , V_54 ;
int V_64 = V_52 -> V_64 ;
V_21 = V_52 -> V_76 ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_10 , V_60 , V_64 ) ;
return;
}
if ( V_52 -> V_77 != 9 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_11 , V_60 , V_52 -> V_77 ) ;
goto exit;
}
V_88 = (struct V_87 * ) V_75 ;
#if 0
dev_dbg(&urb->dev->dev,
"%s - port status: port %d cts %d dcd %d dsr %d ri %d toff %d txoff %d rxen %d cr %d",
__func__, msg->port, msg->hskia_cts, msg->gpia_dcd, msg->dsr,
msg->ri, msg->_txOff, msg->_txXoff, msg->rxEnabled,
msg->controlResponse);
#endif
if ( V_88 -> V_5 >= V_21 -> V_91 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_12 , V_60 , V_88 -> V_5 ) ;
goto exit;
}
V_5 = V_21 -> V_5 [ V_88 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_90 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_88 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_88 -> V_93 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_88 -> V_94 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_88 -> V_95 ) ? 1 : 0 ) ;
if ( V_90 != V_8 -> V_41 )
F_25 ( & V_5 -> V_5 , true ) ;
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
exit: ;
}
static void F_26 ( struct V_52 * V_52 )
{
}
static void F_27 ( struct V_52 * V_52 )
{
int V_54 ;
struct V_4 * V_5 ;
unsigned char * V_75 ;
struct V_7 * V_8 ;
int V_64 = V_52 -> V_64 ;
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
V_75 = V_52 -> V_69 ;
if ( V_52 != V_8 -> V_96 [ V_8 -> V_97 ] )
return;
do {
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_5 ,
V_60 , V_64 , F_12 ( V_52 -> V_63 ) ) ;
return;
}
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
V_75 = V_52 -> V_69 ;
if ( V_52 -> V_77 ) {
F_28 ( & V_5 -> V_5 , V_75 ,
V_52 -> V_77 ) ;
F_18 ( & V_5 -> V_5 ) ;
}
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 ,
V_60 , V_54 ) ;
V_8 -> V_97 ^= 1 ;
V_52 = V_8 -> V_96 [ V_8 -> V_97 ] ;
} while ( V_52 -> V_64 != - V_65 );
}
static void F_29 ( struct V_52 * V_52 )
{
}
static void F_30 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_86 ) {
F_11 ( & V_5 -> V_59 , L_9 , V_60 ) ;
F_31 ( V_5 -> V_21 , V_5 ,
V_8 -> V_86 - 1 ) ;
}
}
static void F_32 ( struct V_52 * V_52 )
{
int V_54 ;
unsigned char * V_75 = V_52 -> V_69 ;
struct V_98 * V_88 ;
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_90 ;
int V_64 = V_52 -> V_64 ;
V_21 = V_52 -> V_76 ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_10 , V_60 , V_64 ) ;
return;
}
if ( V_52 -> V_77 != sizeof( struct V_98 ) ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_13 , V_60 , V_52 -> V_77 ) ;
goto exit;
}
V_88 = (struct V_98 * ) V_75 ;
if ( V_88 -> V_5 >= V_21 -> V_91 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_12 , V_60 , V_88 -> V_5 ) ;
goto exit;
}
V_5 = V_21 -> V_5 [ V_88 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_90 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_88 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_88 -> V_93 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_88 -> V_100 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_88 -> V_95 ) ? 1 : 0 ) ;
if ( V_90 != V_8 -> V_41 && V_90 )
F_25 ( & V_5 -> V_5 , true ) ;
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
exit: ;
}
static void F_33 ( struct V_52 * V_52 )
{
}
static void F_34 ( struct V_52 * V_52 )
{
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_73 ;
V_21 = V_52 -> V_76 ;
for ( V_73 = 0 ; V_73 < V_21 -> V_91 ; ++ V_73 ) {
V_5 = V_21 -> V_5 [ V_73 ] ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_86 ) {
F_11 ( & V_5 -> V_59 , L_9 , V_60 ) ;
F_35 ( V_21 , V_5 ,
V_8 -> V_86 - 1 ) ;
break;
}
}
}
static void F_36 ( struct V_52 * V_52 )
{
int V_54 ;
unsigned char * V_75 = V_52 -> V_69 ;
struct V_101 * V_88 ;
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_90 ;
int V_64 = V_52 -> V_64 ;
V_21 = V_52 -> V_76 ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_10 , V_60 , V_64 ) ;
return;
}
if ( V_52 -> V_77 !=
sizeof( struct V_101 ) ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_13 , V_60 , V_52 -> V_77 ) ;
goto exit;
}
V_88 = (struct V_101 * ) V_75 ;
if ( V_88 -> V_102 >= V_21 -> V_91 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_12 ,
V_60 , V_88 -> V_102 ) ;
goto exit;
}
V_5 = V_21 -> V_5 [ V_88 -> V_102 ] ;
V_8 = F_2 ( V_5 ) ;
V_90 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_88 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_88 -> V_93 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_88 -> V_100 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_88 -> V_95 ) ? 1 : 0 ) ;
if ( V_90 != V_8 -> V_41 && V_90 )
F_25 ( & V_5 -> V_5 , true ) ;
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
exit: ;
}
static void F_37 ( struct V_52 * V_52 )
{
}
static void F_38 ( struct V_52 * V_52 )
{
int V_73 , V_54 ;
int V_74 ;
struct V_4 * V_5 ;
unsigned char * V_75 = V_52 -> V_69 ;
int V_64 = V_52 -> V_64 ;
V_74 = F_12 ( V_52 -> V_63 ) ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_5 ,
V_60 , V_64 , V_74 ) ;
return;
}
V_5 = V_52 -> V_76 ;
if ( V_52 -> V_77 ) {
if ( ( V_75 [ 0 ] & 0x80 ) == 0 ) {
F_28 ( & V_5 -> V_5 , V_75 + 1 ,
V_52 -> V_77 - 1 ) ;
} else {
for ( V_73 = 0 ; V_73 + 1 < V_52 -> V_77 ; V_73 += 2 ) {
int V_80 = V_75 [ V_73 ] , V_81 = 0 ;
if ( V_80 & V_78 )
V_81 |= V_79 ;
if ( V_80 & V_82 )
V_81 |= V_83 ;
if ( V_80 & V_84 )
V_81 |= V_85 ;
F_17 ( & V_5 -> V_5 , V_75 [ V_73 + 1 ] ,
V_81 ) ;
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
}
static void F_39 ( struct V_52 * V_52 )
{
int V_73 , V_103 , V_104 , V_54 ;
struct V_89 * V_21 ;
struct V_4 * V_5 ;
unsigned char * V_75 = V_52 -> V_69 ;
int V_64 = V_52 -> V_64 ;
V_21 = V_52 -> V_76 ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_10 , V_60 , V_64 ) ;
return;
}
V_73 = 0 ;
V_103 = 0 ;
while ( V_73 < V_52 -> V_77 ) {
if ( V_75 [ V_73 ] >= V_21 -> V_91 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_12 ,
V_60 , V_75 [ V_73 ] ) ;
return;
}
V_5 = V_21 -> V_5 [ V_75 [ V_73 ++ ] ] ;
V_103 = V_75 [ V_73 ++ ] ;
if ( ( V_75 [ V_73 ] & 0x80 ) == 0 ) {
V_73 ++ ;
for ( V_104 = 1 ; V_104 < V_103 && V_73 < V_52 -> V_77 ; ++ V_104 )
F_17 ( & V_5 -> V_5 ,
V_75 [ V_73 ++ ] , 0 ) ;
} else {
for ( V_104 = 0 ; V_104 + 1 < V_103 &&
V_73 + 1 < V_52 -> V_77 ; V_104 += 2 ) {
int V_80 = V_75 [ V_73 ] , V_81 = 0 ;
if ( V_80 & V_78 )
V_81 |= V_79 ;
if ( V_80 & V_82 )
V_81 |= V_83 ;
if ( V_80 & V_84 )
V_81 |= V_85 ;
F_17 ( & V_5 -> V_5 , V_75 [ V_73 + 1 ] ,
V_81 ) ;
V_73 += 2 ;
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_52 -> V_59 -> V_59 , L_7 , V_60 , V_54 ) ;
}
static void F_40 ( struct V_52 * V_52 )
{
}
static void F_41 ( struct V_52 * V_52 )
{
int V_73 , V_54 ;
int V_74 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
unsigned char * V_75 = V_52 -> V_69 ;
int V_64 = V_52 -> V_64 ;
V_74 = F_12 ( V_52 -> V_63 ) ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_5 ,
V_60 , V_64 , V_74 ) ;
return;
}
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
if ( V_52 -> V_77 ) {
if ( V_8 -> V_26 > 57600 )
F_28 ( & V_5 -> V_5 , V_75 ,
V_52 -> V_77 ) ;
else {
if ( ( V_75 [ 0 ] & 0x80 ) == 0 ) {
if ( V_75 [ 0 ] & V_78 )
V_54 = V_79 ;
else
V_54 = 0 ;
for ( V_73 = 1 ; V_73 < V_52 -> V_77 ; ++ V_73 )
F_17 ( & V_5 -> V_5 ,
V_75 [ V_73 ] , V_54 ) ;
} else {
F_11 ( & V_5 -> V_59 , L_6 , V_60 ) ;
for ( V_73 = 0 ; V_73 + 1 < V_52 -> V_77 ; V_73 += 2 ) {
int V_80 = V_75 [ V_73 ] , V_81 = 0 ;
if ( V_80 & V_78 )
V_81 |= V_79 ;
if ( V_80 & V_82 )
V_81 |= V_83 ;
if ( V_80 & V_84 )
V_81 |= V_85 ;
F_17 ( & V_5 -> V_5 ,
V_75 [ V_73 + 1 ] , V_81 ) ;
}
}
}
F_18 ( & V_5 -> V_5 ) ;
}
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
}
static void F_42 ( struct V_52 * V_52 )
{
unsigned char * V_75 = V_52 -> V_69 ;
struct V_105 * V_88 ;
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_90 , V_54 ;
int V_64 = V_52 -> V_64 ;
V_21 = V_52 -> V_76 ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_10 , V_60 , V_64 ) ;
return;
}
if ( V_52 -> V_77 < 14 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_11 , V_60 , V_52 -> V_77 ) ;
goto exit;
}
V_88 = (struct V_105 * ) V_75 ;
V_5 = V_21 -> V_5 [ 0 ] ;
V_8 = F_2 ( V_5 ) ;
V_90 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_88 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_88 -> V_93 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_88 -> V_100 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_88 -> V_95 ) ? 1 : 0 ) ;
if ( V_90 != V_8 -> V_41 && V_90 )
F_25 ( & V_5 -> V_5 , true ) ;
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
exit:
;
}
static void F_43 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_76 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_86 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_9 , V_60 ) ;
F_44 ( V_5 -> V_21 , V_5 ,
V_8 -> V_86 - 1 ) ;
}
}
static void F_45 ( struct V_52 * V_52 )
{
int V_54 ;
unsigned char * V_75 = V_52 -> V_69 ;
struct V_106 * V_88 ;
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_90 ;
int V_64 = V_52 -> V_64 ;
V_21 = V_52 -> V_76 ;
if ( V_64 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_10 , V_60 , V_64 ) ;
return;
}
if ( V_52 -> V_77 !=
sizeof( struct V_106 ) ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_13 , V_60 , V_52 -> V_77 ) ;
return;
}
V_88 = (struct V_106 * ) V_75 ;
if ( V_88 -> V_5 >= V_21 -> V_91 ) {
F_11 ( & V_52 -> V_59 -> V_59 , L_12 , V_60 , V_88 -> V_5 ) ;
return;
}
V_5 = V_21 -> V_5 [ V_88 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_90 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_88 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_88 -> V_94 ) ? 1 : 0 ) ;
if ( V_90 != V_8 -> V_41 && V_90 )
F_25 ( & V_5 -> V_5 , true ) ;
V_54 = F_15 ( V_52 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_7 , V_60 , V_54 ) ;
}
static void F_46 ( struct V_52 * V_52 )
{
struct V_89 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_73 ;
V_21 = V_52 -> V_76 ;
for ( V_73 = 0 ; V_73 < V_21 -> V_91 ; ++ V_73 ) {
V_5 = V_21 -> V_5 [ V_73 ] ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_86 ) {
F_11 ( & V_5 -> V_59 , L_9 , V_60 ) ;
F_47 ( V_21 , V_5 ,
V_8 -> V_86 - 1 ) ;
break;
}
}
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_49 ;
int V_107 ;
struct V_52 * V_53 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
if ( V_15 -> V_57 == V_58 )
V_107 = 64 ;
else
V_107 = 63 ;
V_49 = V_8 -> V_61 ;
V_53 = V_8 -> V_62 [ V_49 ] ;
if ( V_53 != NULL ) {
if ( V_53 -> V_64 != - V_65 )
return V_107 ;
V_49 = ( V_49 + 1 ) & V_15 -> V_72 ;
V_53 = V_8 -> V_62 [ V_49 ] ;
if ( V_53 != NULL ) {
if ( V_53 -> V_64 != - V_65 )
return V_107 ;
}
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_73 , V_54 ;
int V_12 , V_13 ;
struct V_52 * V_52 ;
unsigned int V_16 = 0 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
V_8 -> V_33 = 1 ;
V_8 -> V_35 = 1 ;
V_8 -> V_26 = 9600 ;
V_8 -> V_108 = 0 ;
V_8 -> V_109 = 0 ;
V_8 -> V_61 = 0 ;
V_8 -> V_97 = 0 ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
V_52 = V_8 -> V_96 [ V_73 ] ;
if ( V_52 == NULL )
continue;
F_50 ( V_52 -> V_59 , V_52 -> V_63 ) ;
V_54 = F_15 ( V_52 , V_110 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_14 , V_60 , V_73 , V_54 ) ;
}
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
V_52 = V_8 -> V_62 [ V_73 ] ;
if ( V_52 == NULL )
continue;
}
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
if ( V_2 ) {
V_16 = V_2 -> V_18 . V_19 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 >= 0
&& V_15 -> V_23 ( V_5 , V_12 , V_15 -> V_24 ,
NULL , NULL , NULL , V_13 ) == V_25 ) {
V_8 -> V_26 = V_12 ;
}
}
V_8 -> V_16 = V_16 ;
V_8 -> V_27 = ( V_16 & V_28 ) ? V_29 : V_30 ;
F_3 ( V_5 , 1 ) ;
return 0 ;
}
static inline void F_51 ( struct V_52 * V_52 )
{
if ( V_52 && V_52 -> V_64 == - V_65 )
F_52 ( V_52 ) ;
}
static void F_53 ( struct V_4 * V_5 , int V_111 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
V_8 -> V_33 = V_111 ;
V_8 -> V_35 = V_111 ;
F_3 ( V_5 , 0 ) ;
}
static void F_54 ( struct V_4 * V_5 )
{
int V_73 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_5 ) ;
V_8 -> V_33 = 0 ;
V_8 -> V_35 = 0 ;
F_3 ( V_5 , 2 ) ;
F_55 ( 100 ) ;
V_8 -> V_61 = 0 ;
V_8 -> V_97 = 0 ;
F_51 ( V_8 -> V_112 ) ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
F_51 ( V_8 -> V_96 [ V_73 ] ) ;
F_51 ( V_8 -> V_62 [ V_73 ] ) ;
}
}
static int F_56 ( struct V_89 * V_21 )
{
char * V_113 ;
F_11 ( & V_21 -> V_59 -> V_59 , L_15 ,
F_57 ( V_21 -> V_59 -> V_114 . V_115 ) ,
F_57 ( V_21 -> V_59 -> V_114 . V_116 ) ) ;
if ( ( F_57 ( V_21 -> V_59 -> V_114 . V_115 ) & 0x8000 )
!= 0x8000 ) {
F_11 ( & V_21 -> V_59 -> V_59 , L_16 ) ;
return 1 ;
}
switch ( F_57 ( V_21 -> V_59 -> V_114 . V_116 ) ) {
case V_117 :
V_113 = L_17 ;
break;
case V_118 :
V_113 = L_18 ;
break;
case V_119 :
V_113 = L_19 ;
break;
case V_120 :
V_113 = L_20 ;
break;
case V_121 :
V_113 = L_21 ;
break;
case V_122 :
V_113 = L_22 ;
break;
case V_123 :
V_113 = L_23 ;
break;
case V_124 :
V_113 = L_24 ;
break;
case V_125 :
V_113 = L_25 ;
break;
case V_126 :
V_113 = L_26 ;
break;
case V_127 :
V_113 = L_27 ;
break;
case V_128 :
V_113 = L_28 ;
break;
default:
F_58 ( & V_21 -> V_59 -> V_59 , L_29 ,
F_57 ( V_21 -> V_59 -> V_114 . V_116 ) ) ;
return 1 ;
}
F_11 ( & V_21 -> V_59 -> V_59 , L_30 , V_113 ) ;
if ( F_59 ( V_21 -> V_59 , V_113 ) < 0 ) {
F_58 ( & V_21 -> V_59 -> V_59 , L_31 ,
V_113 ) ;
return - V_129 ;
}
return 1 ;
}
static struct V_130 const * F_60 ( struct V_89 const * V_21 ,
int V_74 )
{
struct V_131 * V_132 ;
struct V_130 * V_133 ;
int V_73 ;
V_132 = V_21 -> V_134 -> V_135 ;
for ( V_73 = 0 ; V_73 < V_132 -> V_136 . V_137 ; ++ V_73 ) {
V_133 = & V_132 -> V_74 [ V_73 ] . V_136 ;
if ( V_133 -> V_138 == V_74 )
return V_133 ;
}
F_61 ( & V_21 -> V_134 -> V_59 , L_32
L_33 , V_74 ) ;
return NULL ;
}
static struct V_52 * F_62 ( struct V_89 * V_21 , int V_74 ,
int V_139 , void * V_140 , char * V_47 , int V_103 ,
void (* F_63)( struct V_52 * ) )
{
struct V_52 * V_52 ;
struct V_130 const * V_141 ;
char const * V_142 ;
if ( V_74 == - 1 )
return NULL ;
F_11 ( & V_21 -> V_134 -> V_59 , L_34 , V_60 , V_74 ) ;
V_52 = F_64 ( 0 , V_110 ) ;
if ( V_52 == NULL ) {
F_11 ( & V_21 -> V_134 -> V_59 , L_35 , V_60 , V_74 ) ;
return NULL ;
}
if ( V_74 == 0 ) {
return V_52 ;
}
V_141 = F_60 ( V_21 , V_74 ) ;
if ( ! V_141 ) {
return V_52 ;
}
if ( F_65 ( V_141 ) ) {
V_142 = L_36 ;
F_66 ( V_52 , V_21 -> V_59 ,
F_67 ( V_21 -> V_59 , V_74 ) | V_139 ,
V_47 , V_103 , F_63 , V_140 ,
V_141 -> V_143 ) ;
} else if ( F_68 ( V_141 ) ) {
V_142 = L_37 ;
F_69 ( V_52 , V_21 -> V_59 ,
F_70 ( V_21 -> V_59 , V_74 ) | V_139 ,
V_47 , V_103 , F_63 , V_140 ) ;
} else {
F_61 ( & V_21 -> V_134 -> V_59 ,
L_38 ,
F_71 ( V_141 ) ) ;
F_72 ( V_52 ) ;
return NULL ;
}
F_11 ( & V_21 -> V_134 -> V_59 , L_39 ,
V_60 , V_52 , V_142 , V_74 ) ;
return V_52 ;
}
static void F_73 ( struct V_89 * V_21 )
{
struct V_144 * V_145 ;
const struct V_14 * V_15 ;
struct V_146 * V_147 ;
V_145 = F_74 ( V_21 ) ;
V_15 = V_145 -> V_17 ;
V_147 = & V_148 [ V_15 -> V_57 ] ;
V_145 -> V_149 = F_62
( V_21 , V_15 -> V_150 , V_151 ,
V_21 , V_145 -> V_152 , V_153 ,
V_147 -> V_154 ) ;
V_145 -> V_155 = F_62
( V_21 , V_15 -> V_156 , V_151 ,
V_21 , V_145 -> V_157 , V_158 ,
F_39 ) ;
V_145 -> V_159 = F_62
( V_21 , V_15 -> V_160 , V_161 ,
V_21 , V_145 -> V_162 , V_163 ,
V_147 -> V_164 ) ;
}
static int F_75 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_24 , T_2 * V_165 ,
T_2 * V_166 , T_2 * V_167 , int V_168 )
{
T_1 V_169 ,
div ,
V_170 ;
F_11 ( & V_5 -> V_59 , L_40 , V_60 , V_12 ) ;
V_169 = V_12 * 16L ;
if ( V_169 == 0 )
return V_171 ;
if ( V_12 > 57600 )
return V_171 ;
div = V_24 / V_169 ;
if ( div == 0 )
return V_171 ;
else
V_170 = 0 - div ;
if ( div > 0xffff )
return V_171 ;
if ( V_166 )
* V_166 = ( T_2 ) ( V_170 & 0xff ) ;
if ( V_165 )
* V_165 = ( T_2 ) ( ( V_170 >> 8 ) & 0xff ) ;
if ( V_166 && V_165 )
F_11 ( & V_5 -> V_59 , L_41 ,
V_60 , V_12 , * V_165 , * V_166 ) ;
return V_25 ;
}
static int F_76 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_24 , T_2 * V_165 ,
T_2 * V_166 , T_2 * V_167 , int V_168 )
{
T_1 V_169 ,
div ;
F_11 ( & V_5 -> V_59 , L_40 , V_60 , V_12 ) ;
V_169 = V_12 * 16L ;
if ( V_169 == 0 )
return V_171 ;
div = V_24 / V_169 ;
if ( div == 0 )
return V_171 ;
if ( div > 0xffff )
return V_171 ;
if ( V_166 )
* V_166 = ( T_2 ) ( div & 0xff ) ;
if ( V_165 )
* V_165 = ( T_2 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_166 && V_165 )
F_11 ( & V_5 -> V_59 , L_41 ,
V_60 , V_12 , * V_165 , * V_166 ) ;
return V_25 ;
}
static int F_77 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_24 , T_2 * V_165 ,
T_2 * V_166 , T_2 * V_167 , int V_168 )
{
T_1 V_169 ,
V_172 ,
div ,
V_173 ,
V_174 ,
V_175 ;
T_2 V_176 ;
int V_73 ;
F_11 ( & V_5 -> V_59 , L_40 , V_60 , V_12 ) ;
V_169 = V_12 * 16L ;
if ( V_169 == 0 )
return V_171 ;
V_175 = 0xffffffff ;
V_176 = 0 ;
for ( V_73 = 8 ; V_73 <= 0xff ; ++ V_73 ) {
V_172 = ( V_24 * 8 ) / ( T_1 ) V_73 ;
div = V_172 / V_169 ;
if ( div == 0 )
continue;
V_173 = V_172 / div ;
V_174 = ( V_173 > V_169 ) ? ( V_173 - V_169 ) : ( V_169 - V_173 ) ;
if ( V_174 < V_175 ) {
V_176 = V_73 ;
V_175 = V_174 ;
}
}
if ( V_176 == 0 )
return V_171 ;
V_172 = ( V_24 * 8 ) / ( T_1 ) V_176 ;
div = V_172 / V_169 ;
if ( V_166 )
* V_166 = ( T_2 ) ( div & 0xff ) ;
if ( V_165 )
* V_165 = ( T_2 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_167 ) {
* V_167 = V_176 ;
}
return V_25 ;
}
static int F_78 ( struct V_4 * V_5 ,
T_1 V_12 , T_1 V_24 , T_2 * V_165 ,
T_2 * V_166 , T_2 * V_167 , int V_168 )
{
T_1 V_169 ,
div ,
V_170 ;
F_11 ( & V_5 -> V_59 , L_40 , V_60 , V_12 ) ;
V_169 = V_12 * 16L ;
if ( V_169 == 0 )
return V_171 ;
div = V_177 / V_169 ;
if ( div == 0 )
return V_171 ;
else
V_170 = 0 - div ;
if ( V_168 == 0 ) {
if ( div > 0xffff )
return V_171 ;
} else {
if ( V_168 == 1 ) {
if ( div > 0xff )
return V_171 ;
} else
return V_171 ;
}
if ( V_166 )
* V_166 = ( T_2 ) ( V_170 & 0xff ) ;
if ( V_165 )
* V_165 = ( T_2 ) ( ( V_170 >> 8 ) & 0xff ) ;
F_11 ( & V_5 -> V_59 , L_42 , V_60 , V_12 ) ;
return V_25 ;
}
static int F_23 ( struct V_89 * V_21 ,
struct V_4 * V_5 ,
int V_178 )
{
struct V_179 V_88 ;
struct V_144 * V_145 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_13 , V_54 ;
F_11 ( & V_5 -> V_59 , L_43 , V_60 , V_178 ) ;
V_145 = F_74 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_145 -> V_17 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_53 = V_8 -> V_180 ;
F_11 ( & V_5 -> V_59 , L_44 , V_60 , F_12 ( V_53 -> V_63 ) ) ;
if ( V_53 == NULL ) {
F_11 ( & V_5 -> V_59 , L_45 , V_60 ) ;
return - 1 ;
}
if ( ( V_178 + 1 ) > V_8 -> V_86 )
V_8 -> V_86 = V_178 + 1 ;
if ( V_53 -> V_64 == - V_65 ) {
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_88 , 0 , sizeof( struct V_179 ) ) ;
if ( V_8 -> V_108 != V_8 -> V_26 ) {
V_8 -> V_108 = V_8 -> V_26 ;
V_88 . V_181 = 0xff ;
if ( V_15 -> V_23 ( V_5 , V_8 -> V_26 , V_15 -> V_24 ,
& V_88 . V_182 , & V_88 . V_183 , & V_88 . V_167 ,
V_13 ) == V_171 ) {
F_11 ( & V_5 -> V_59 , L_46 ,
V_60 , V_8 -> V_26 ) ;
V_88 . V_183 = 0 ;
V_88 . V_182 = 125 ;
V_88 . V_167 = 10 ;
}
V_88 . V_184 = 0xff ;
}
V_88 . V_185 = ( V_8 -> V_16 & V_186 ) ? V_187 : V_188 ;
switch ( V_8 -> V_16 & V_189 ) {
case V_190 :
V_88 . V_185 |= V_191 ;
break;
case V_192 :
V_88 . V_185 |= V_193 ;
break;
case V_194 :
V_88 . V_185 |= V_195 ;
break;
case V_196 :
V_88 . V_185 |= V_197 ;
break;
}
if ( V_8 -> V_16 & V_198 ) {
V_88 . V_185 |= ( V_8 -> V_16 & V_199 ) ?
V_200 : V_201 ;
}
V_88 . V_202 = 0xff ;
V_88 . V_203 = ( V_8 -> V_27 == V_29 ) ;
V_88 . V_204 = 0 ;
V_88 . V_205 = 0xff ;
V_88 . V_206 = 16 ;
V_88 . V_207 = 17 ;
V_88 . V_208 = 19 ;
if ( V_178 == 1 ) {
V_88 . V_209 = 1 ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 1 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0xff ;
}
else if ( V_178 == 2 ) {
V_88 . V_209 = 0 ;
V_88 . V_210 = 1 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 1 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0 ;
}
else {
V_88 . V_209 = ( ! V_8 -> V_9 ) ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = ( V_8 -> V_9 ) ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 0 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0x0 ;
}
V_88 . V_219 = 0xff ;
V_88 . V_220 = V_8 -> V_33 ;
V_88 . V_221 = 0xff ;
V_88 . V_222 = V_8 -> V_35 ;
V_8 -> V_86 = 0 ;
memcpy ( V_53 -> V_69 , & V_88 , sizeof( V_88 ) ) ;
V_53 -> V_70 = sizeof( V_88 ) ;
V_54 = F_15 ( V_53 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_47 , V_60 , V_54 ) ;
return 0 ;
}
static int F_31 ( struct V_89 * V_21 ,
struct V_4 * V_5 ,
int V_178 )
{
struct V_223 V_88 ;
struct V_144 * V_145 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_13 , V_54 ;
V_145 = F_74 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_145 -> V_17 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_53 = V_8 -> V_180 ;
if ( V_53 == NULL ) {
F_11 ( & V_5 -> V_59 , L_45 , V_60 ) ;
return - 1 ;
}
if ( ( V_178 + 1 ) > V_8 -> V_86 )
V_8 -> V_86 = V_178 + 1 ;
if ( V_53 -> V_64 == - V_65 ) {
F_11 ( & V_5 -> V_59 , L_48 , V_60 ) ;
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_88 , 0 , sizeof( struct V_223 ) ) ;
V_88 . V_224 = 1 ;
if ( V_15 -> V_23 ( V_5 , V_8 -> V_26 , V_15 -> V_24 ,
& V_88 . V_182 , & V_88 . V_183 , NULL ,
V_13 ) == V_171 ) {
F_11 ( & V_5 -> V_59 , L_49 ,
V_60 , V_8 -> V_26 ) ;
V_88 . V_183 = 0xff ;
V_88 . V_182 = 0xb2 ;
}
V_88 . V_225 = 0 ;
V_88 . V_203 = ( V_8 -> V_27 == V_29 ) ;
V_88 . V_204 = 0 ;
V_88 . V_226 = V_8 -> V_33 ;
V_88 . V_227 = V_8 -> V_35 ;
V_88 . V_206 = 16 ;
V_88 . V_228 = 10 ;
V_88 . V_229 = 45 ;
V_88 . V_207 = 17 ;
V_88 . V_208 = 19 ;
if ( V_178 == 1 ) {
V_88 . V_209 = 1 ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_230 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 1 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0xff ;
}
else if ( V_178 == 2 ) {
V_88 . V_209 = 0 ;
V_88 . V_210 = 1 ;
V_88 . V_211 = 0 ;
V_88 . V_230 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 1 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0 ;
}
else {
V_88 . V_209 = ( ! V_8 -> V_9 ) ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_230 = 0 ;
V_88 . V_212 = ( V_8 -> V_9 ) ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 0 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0x0 ;
}
V_8 -> V_86 = 0 ;
memcpy ( V_53 -> V_69 , & V_88 , sizeof( V_88 ) ) ;
V_53 -> V_70 = sizeof( V_88 ) ;
V_54 = F_15 ( V_53 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_50 , V_60 ) ;
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) OK %d bytes\n", __func__,
this_urb->transfer_buffer_length);
}
#endif
return 0 ;
}
static int F_35 ( struct V_89 * V_21 ,
struct V_4 * V_5 ,
int V_178 )
{
struct V_231 V_88 ;
struct V_232 * V_233 = NULL ;
struct V_144 * V_145 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_54 , V_13 ;
V_145 = F_74 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_145 -> V_17 ;
V_53 = V_145 -> V_159 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
if ( V_53 == NULL ) {
F_11 ( & V_5 -> V_59 , L_51 , V_60 , V_5 -> V_20 ) ;
return - 1 ;
}
F_11 ( & V_5 -> V_59 , L_52 ,
V_60 , F_12 ( V_53 -> V_63 ) ,
V_5 -> V_20 , V_13 ) ;
if ( ( V_178 + 1 ) > V_8 -> V_86 )
V_8 -> V_86 = V_178 + 1 ;
if ( V_53 -> V_64 == - V_65 ) {
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_88 , 0 , sizeof( struct V_231 ) ) ;
V_88 . V_102 = V_13 ;
if ( V_8 -> V_108 != V_8 -> V_26 ) {
V_8 -> V_108 = V_8 -> V_26 ;
V_88 . V_181 = 0xff ;
if ( V_15 -> V_23 ( V_5 , V_8 -> V_26 , V_15 -> V_24 ,
& V_88 . V_182 , & V_88 . V_183 , & V_88 . V_167 ,
V_13 ) == V_171 ) {
F_11 ( & V_5 -> V_59 , L_46 ,
V_60 , V_8 -> V_26 ) ;
V_88 . V_183 = 0 ;
V_88 . V_182 = 125 ;
V_88 . V_167 = 10 ;
}
}
V_88 . V_185 = ( V_8 -> V_16 & V_186 ) ? V_187 : V_188 ;
switch ( V_8 -> V_16 & V_189 ) {
case V_190 :
V_88 . V_185 |= V_191 ;
break;
case V_192 :
V_88 . V_185 |= V_193 ;
break;
case V_194 :
V_88 . V_185 |= V_195 ;
break;
case V_196 :
V_88 . V_185 |= V_197 ;
break;
}
if ( V_8 -> V_16 & V_198 ) {
V_88 . V_185 |= ( V_8 -> V_16 & V_199 ) ?
V_200 : V_201 ;
}
V_88 . V_202 = 0xff ;
V_88 . V_203 = ( V_8 -> V_27 == V_29 ) ;
V_88 . V_204 = 0 ;
V_88 . V_205 = 0xff ;
V_88 . V_206 = 16 ;
V_88 . V_207 = 17 ;
V_88 . V_208 = 19 ;
if ( V_178 == 1 ) {
V_88 . V_209 = 1 ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 1 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0xff ;
V_88 . V_234 = 1 ;
V_88 . V_235 = 0 ;
}
else if ( V_178 == 2 ) {
V_88 . V_209 = 0 ;
V_88 . V_210 = 1 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 1 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0 ;
V_88 . V_234 = 0 ;
V_88 . V_235 = 1 ;
}
else {
V_88 . V_209 = ( ! V_8 -> V_9 ) ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = ( V_8 -> V_9 ) ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 0 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0x0 ;
V_88 . V_234 = 0 ;
V_88 . V_235 = 0 ;
}
V_88 . V_236 = 0xff ;
V_88 . V_226 = V_8 -> V_33 ;
V_88 . V_237 = 0xff ;
V_88 . V_227 = V_8 -> V_35 ;
V_8 -> V_86 = 0 ;
if ( V_15 -> V_238 == V_239 ) {
V_233 = ( void * ) ( V_145 -> V_240 ) ;
V_233 -> V_241 = V_242 | V_161 ;
V_233 -> V_243 = 0xB0 ; ;
V_233 -> V_244 = 0 ;
V_233 -> V_245 = 0 ;
V_233 -> V_246 = F_79 ( sizeof( V_88 ) ) ;
memcpy ( V_145 -> V_162 , & V_88 , sizeof( V_88 ) ) ;
F_80 ( V_53 , V_21 -> V_59 ,
F_81 ( V_21 -> V_59 , 0 ) ,
( unsigned char * ) V_233 , V_145 -> V_162 ,
sizeof( V_88 ) , F_34 , V_21 ) ;
} else {
memcpy ( V_53 -> V_69 , & V_88 , sizeof( V_88 ) ) ;
V_53 -> V_70 = sizeof( V_88 ) ;
}
V_54 = F_15 ( V_53 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_47 , V_60 , V_54 ) ;
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(%d) OK %d bytes (end %d)\n", __func__,
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0 ;
}
static int F_44 ( struct V_89 * V_21 ,
struct V_4 * V_5 ,
int V_178 )
{
struct V_247 V_88 ;
struct V_144 * V_145 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_54 ;
T_2 V_167 ;
V_145 = F_74 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_145 -> V_17 ;
V_53 = V_8 -> V_180 ;
if ( V_53 == NULL ) {
F_11 ( & V_5 -> V_59 , L_45 , V_60 ) ;
return - 1 ;
}
if ( ( V_178 + 1 ) > V_8 -> V_86 )
V_8 -> V_86 = V_178 + 1 ;
if ( V_53 -> V_64 == - V_65 ) {
F_11 ( & V_5 -> V_59 , L_48 , V_60 ) ;
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_88 , 0 , sizeof( struct V_247 ) ) ;
if ( V_8 -> V_108 != V_8 -> V_26 ) {
V_8 -> V_108 = V_8 -> V_26 ;
V_88 . V_181 = 0x01 ;
if ( V_15 -> V_23 ( V_5 , V_8 -> V_26 , V_15 -> V_24 ,
& V_88 . V_182 , & V_88 . V_183 , & V_167 , 0 ) == V_171 ) {
F_11 ( & V_5 -> V_59 , L_46 ,
V_60 , V_8 -> V_26 ) ;
V_8 -> V_26 = 9600 ;
V_15 -> V_23 ( V_5 , V_8 -> V_26 , V_15 -> V_24 ,
& V_88 . V_182 , & V_88 . V_183 , & V_167 , 0 ) ;
}
V_88 . V_248 = 1 ;
V_88 . V_249 = 1 ;
}
if ( V_8 -> V_26 > 57600 ) {
V_88 . V_250 = V_251 ;
V_88 . V_252 = V_253 ;
} else {
V_88 . V_250 = V_254 ;
V_88 . V_252 = V_255 ;
}
V_88 . V_185 = ( V_8 -> V_16 & V_186 ) ? V_187 : V_188 ;
switch ( V_8 -> V_16 & V_189 ) {
case V_190 :
V_88 . V_185 |= V_191 ;
break;
case V_192 :
V_88 . V_185 |= V_193 ;
break;
case V_194 :
V_88 . V_185 |= V_195 ;
break;
case V_196 :
V_88 . V_185 |= V_197 ;
break;
}
if ( V_8 -> V_16 & V_198 ) {
V_88 . V_185 |= ( V_8 -> V_16 & V_199 ) ?
V_200 : V_201 ;
}
if ( V_8 -> V_109 != V_8 -> V_16 ) {
V_8 -> V_109 = V_8 -> V_16 ;
V_88 . V_202 = 0x01 ;
}
if ( V_8 -> V_27 == V_29 )
V_88 . V_256 = V_257 ;
V_88 . V_258 = 0x01 ;
V_88 . V_259 = 0x01 ;
V_88 . V_260 = 16 ;
V_88 . V_261 = 16 ;
V_88 . V_262 = 0 ;
V_88 . V_207 = 17 ;
V_88 . V_208 = 19 ;
if ( V_178 == 1 ) {
V_88 . V_263 = 1 ;
V_88 . V_215 = 1 ;
V_88 . V_212 = ( V_8 -> V_9 ) ;
}
else if ( V_178 == 2 )
V_88 . V_263 = 0 ;
else {
V_88 . V_263 = 1 ;
V_88 . V_212 = ( V_8 -> V_9 ) ;
}
V_88 . V_236 = 0x01 ;
V_88 . V_226 = V_8 -> V_33 ;
V_88 . V_237 = 0x01 ;
V_88 . V_227 = V_8 -> V_35 ;
V_8 -> V_86 = 0 ;
memcpy ( V_53 -> V_69 , & V_88 , sizeof( V_88 ) ) ;
V_53 -> V_70 = sizeof( V_88 ) ;
V_54 = F_15 ( V_53 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_47 , V_60 , V_54 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_21 ,
struct V_4 * V_5 ,
int V_178 )
{
struct V_264 V_88 ;
struct V_144 * V_145 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_54 , V_13 ;
V_145 = F_74 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_145 -> V_17 ;
V_53 = V_145 -> V_159 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
if ( V_53 == NULL ) {
F_11 ( & V_5 -> V_59 , L_51 , V_60 ,
V_5 -> V_20 ) ;
return - 1 ;
}
if ( ( V_178 + 1 ) > V_8 -> V_86 )
V_8 -> V_86 = V_178 + 1 ;
if ( V_53 -> V_64 == - V_65 ) {
F_55 ( 5 ) ;
return - 1 ;
}
memset ( & V_88 , 0 , sizeof( struct V_264 ) ) ;
V_88 . V_5 = V_13 ;
if ( V_8 -> V_108 != V_8 -> V_26 ) {
V_8 -> V_108 = V_8 -> V_26 ;
V_88 . V_181 = 0xff ;
if ( V_15 -> V_23 ( V_5 , V_8 -> V_26 , V_15 -> V_24 ,
& V_88 . V_182 , & V_88 . V_183 , & V_88 . V_167 ,
V_13 ) == V_171 ) {
F_11 ( & V_5 -> V_59 , L_46 ,
V_60 , V_8 -> V_26 ) ;
V_88 . V_183 = 0 ;
V_88 . V_182 = 125 ;
V_88 . V_167 = 10 ;
}
V_88 . V_184 = 0xff ;
}
V_88 . V_185 = ( V_8 -> V_16 & V_186 ) ? V_187 : V_188 ;
switch ( V_8 -> V_16 & V_189 ) {
case V_190 :
V_88 . V_185 |= V_191 ;
break;
case V_192 :
V_88 . V_185 |= V_193 ;
break;
case V_194 :
V_88 . V_185 |= V_195 ;
break;
case V_196 :
V_88 . V_185 |= V_197 ;
break;
}
if ( V_8 -> V_16 & V_198 ) {
V_88 . V_185 |= ( V_8 -> V_16 & V_199 ) ?
V_200 : V_201 ;
}
V_88 . V_202 = 0xff ;
V_88 . V_203 = ( V_8 -> V_27 == V_29 ) ;
V_88 . V_204 = 0 ;
V_88 . V_205 = 0xff ;
V_88 . V_206 = 16 ;
V_88 . V_207 = 17 ;
V_88 . V_208 = 19 ;
if ( V_178 == 1 ) {
V_88 . V_209 = 1 ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 1 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0xff ;
} else if ( V_178 == 2 ) {
V_88 . V_209 = 0 ;
V_88 . V_210 = 1 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = 0 ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 1 ;
V_88 . V_215 = 1 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0 ;
} else {
V_88 . V_209 = ( ! V_8 -> V_9 ) ;
V_88 . V_210 = 0 ;
V_88 . V_211 = 0 ;
V_88 . V_212 = ( V_8 -> V_9 ) ;
V_88 . V_213 = 0 ;
V_88 . V_214 = 0 ;
V_88 . V_215 = 0 ;
V_88 . V_216 = 0 ;
V_88 . V_217 = 0 ;
V_88 . V_218 = 0x0 ;
}
V_88 . V_219 = 0xff ;
V_88 . V_220 = V_8 -> V_33 ;
V_88 . V_221 = 0xff ;
V_88 . V_222 = V_8 -> V_35 ;
V_8 -> V_86 = 0 ;
memcpy ( V_53 -> V_69 , & V_88 , sizeof( V_88 ) ) ;
V_53 -> V_70 = sizeof( V_88 ) ;
V_54 = F_15 ( V_53 , V_71 ) ;
if ( V_54 != 0 )
F_11 ( & V_5 -> V_59 , L_47 , V_60 , V_54 ) ;
return 0 ;
}
static void F_3 ( struct V_4 * V_5 , int V_178 )
{
struct V_89 * V_21 = V_5 -> V_21 ;
struct V_144 * V_145 ;
const struct V_14 * V_15 ;
V_145 = F_74 ( V_21 ) ;
V_15 = V_145 -> V_17 ;
switch ( V_15 -> V_57 ) {
case V_265 :
F_23 ( V_21 , V_5 , V_178 ) ;
break;
case V_266 :
F_31 ( V_21 , V_5 , V_178 ) ;
break;
case V_267 :
F_35 ( V_21 , V_5 , V_178 ) ;
break;
case V_58 :
F_44 ( V_21 , V_5 , V_178 ) ;
break;
case V_268 :
F_47 ( V_21 , V_5 , V_178 ) ;
break;
}
}
static int F_82 ( struct V_89 * V_21 )
{
int V_73 , V_54 ;
struct V_144 * V_145 ;
const struct V_14 * V_15 ;
for ( V_73 = 0 ; ( V_15 = V_269 [ V_73 ] ) != NULL ; ++ V_73 )
if ( V_15 -> V_238 ==
F_57 ( V_21 -> V_59 -> V_114 . V_116 ) )
break;
if ( V_15 == NULL ) {
F_58 ( & V_21 -> V_59 -> V_59 , L_53 ,
V_60 , F_57 ( V_21 -> V_59 -> V_114 . V_116 ) ) ;
return 1 ;
}
V_145 = F_83 ( sizeof( struct V_144 ) , V_110 ) ;
if ( ! V_145 ) {
F_11 ( & V_21 -> V_59 -> V_59 , L_54 , V_60 ) ;
return - V_270 ;
}
V_145 -> V_17 = V_15 ;
F_84 ( V_21 , V_145 ) ;
F_73 ( V_21 ) ;
if ( V_145 -> V_149 != NULL ) {
V_54 = F_15 ( V_145 -> V_149 , V_110 ) ;
if ( V_54 != 0 )
F_11 ( & V_21 -> V_59 -> V_59 , L_55 , V_60 , V_54 ) ;
}
if ( V_145 -> V_155 != NULL ) {
V_54 = F_15 ( V_145 -> V_155 , V_110 ) ;
if ( V_54 != 0 )
F_11 ( & V_21 -> V_59 -> V_59 , L_56 , V_60 , V_54 ) ;
}
return 0 ;
}
static void F_85 ( struct V_89 * V_21 )
{
struct V_144 * V_145 ;
V_145 = F_74 ( V_21 ) ;
F_51 ( V_145 -> V_149 ) ;
F_51 ( V_145 -> V_159 ) ;
F_51 ( V_145 -> V_155 ) ;
}
static void F_86 ( struct V_89 * V_21 )
{
struct V_144 * V_145 ;
V_145 = F_74 ( V_21 ) ;
F_72 ( V_145 -> V_149 ) ;
F_72 ( V_145 -> V_155 ) ;
F_72 ( V_145 -> V_159 ) ;
F_87 ( V_145 ) ;
}
static int F_88 ( struct V_4 * V_5 )
{
struct V_89 * V_21 = V_5 -> V_21 ;
struct V_144 * V_145 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_146 * V_147 ;
int V_271 ;
int V_272 ;
int V_73 ;
V_145 = F_74 ( V_21 ) ;
V_15 = V_145 -> V_17 ;
V_8 = F_83 ( sizeof( * V_8 ) , V_110 ) ;
if ( ! V_8 )
return - V_270 ;
V_8 -> V_17 = V_15 ;
V_147 = & V_148 [ V_15 -> V_57 ] ;
V_272 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_271 = V_15 -> V_273 [ V_272 ] ;
for ( V_73 = 0 ; V_73 <= V_15 -> V_274 ; ++ V_73 , ++ V_271 ) {
V_8 -> V_96 [ V_73 ] = F_62 ( V_21 , V_271 ,
V_151 , V_5 ,
V_8 -> V_275 [ V_73 ] , 64 ,
V_147 -> V_276 ) ;
}
V_271 = V_15 -> V_277 [ V_272 ] ;
for ( V_73 = 0 ; V_73 <= V_15 -> V_72 ; ++ V_73 , ++ V_271 ) {
V_8 -> V_62 [ V_73 ] = F_62 ( V_21 , V_271 ,
V_161 , V_5 ,
V_8 -> V_278 [ V_73 ] , 64 ,
V_147 -> V_279 ) ;
}
V_8 -> V_112 = F_62 ( V_21 ,
V_15 -> V_280 [ V_272 ] ,
V_151 , V_5 ,
V_8 -> V_281 , 1 ,
V_147 -> V_282 ) ;
V_8 -> V_180 = F_62 ( V_21 ,
V_15 -> V_283 [ V_272 ] ,
V_161 , V_5 ,
V_8 -> V_284 , 64 ,
V_147 -> V_285 ) ;
F_89 ( V_5 , V_8 ) ;
return 0 ;
}
static int F_90 ( struct V_4 * V_5 )
{
struct V_7 * V_8 ;
int V_73 ;
V_8 = F_2 ( V_5 ) ;
F_51 ( V_8 -> V_112 ) ;
F_51 ( V_8 -> V_180 ) ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
F_51 ( V_8 -> V_96 [ V_73 ] ) ;
F_51 ( V_8 -> V_62 [ V_73 ] ) ;
}
F_72 ( V_8 -> V_112 ) ;
F_72 ( V_8 -> V_180 ) ;
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
F_72 ( V_8 -> V_96 [ V_73 ] ) ;
F_72 ( V_8 -> V_62 [ V_73 ] ) ;
}
F_87 ( V_8 ) ;
return 0 ;
}
