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
V_16 = V_2 -> V_18 -> V_19 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_12 = F_5 ( V_2 ) ;
if ( V_15 -> V_23 ( V_12 , V_15 -> V_24 ,
NULL , NULL , NULL , V_13 ) == V_25 ) {
V_8 -> V_26 = V_12 ;
} else
V_12 = F_6 ( V_11 ) ;
F_7 ( V_2 , V_12 , V_12 ) ;
V_8 -> V_16 = V_16 ;
V_8 -> V_27 = ( V_16 & V_28 ) ? V_29 : V_30 ;
V_2 -> V_18 -> V_19 &= ~ V_31 ;
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
F_11 ( L_1 ,
V_59 , V_5 -> V_20 , V_48 , V_8 -> V_60 ) ;
for ( V_50 = V_48 ; V_50 > 0 ; V_50 -= V_51 ) {
V_51 = V_50 ;
if ( V_51 > V_55 )
V_51 = V_55 ;
V_49 = V_8 -> V_60 ;
V_53 = V_8 -> V_61 [ V_49 ] ;
if ( V_53 == NULL ) {
F_11 ( L_2 , V_59 ) ;
return V_48 ;
}
F_11 ( L_3 ,
V_59 , F_12 ( V_53 -> V_62 ) , V_49 ) ;
if ( V_53 -> V_63 == - V_64 ) {
if ( F_13 ( V_65 ,
V_8 -> V_66 [ V_49 ] + 10 * V_67 ) )
break;
F_14 ( V_53 ) ;
break;
}
( ( char * ) V_53 -> V_68 ) [ 0 ] = 0 ;
memcpy ( V_53 -> V_68 + V_56 , V_47 , V_51 ) ;
V_47 += V_51 ;
V_53 -> V_69 = V_51 + V_56 ;
V_54 = F_15 ( V_53 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_4 , V_54 ) ;
V_8 -> V_66 [ V_49 ] = V_65 ;
V_8 -> V_60 = ( V_49 + 1 ) & V_15 -> V_71 ;
}
return V_48 - V_50 ;
}
static void F_16 ( struct V_52 * V_52 )
{
int V_72 , V_54 ;
int V_73 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
unsigned char * V_74 = V_52 -> V_68 ;
int V_63 = V_52 -> V_63 ;
V_73 = F_12 ( V_52 -> V_62 ) ;
if ( V_63 ) {
F_11 ( L_5 ,
V_59 , V_63 , V_73 ) ;
return;
}
V_5 = V_52 -> V_75 ;
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && V_52 -> V_76 ) {
if ( ( V_74 [ 0 ] & 0x80 ) == 0 ) {
if ( V_74 [ 0 ] & V_77 )
V_54 = V_78 ;
else
V_54 = 0 ;
for ( V_72 = 1 ; V_72 < V_52 -> V_76 ; ++ V_72 )
F_18 ( V_2 , V_74 [ V_72 ] , V_54 ) ;
} else {
F_11 ( L_6 , V_59 ) ;
for ( V_72 = 0 ; V_72 + 1 < V_52 -> V_76 ; V_72 += 2 ) {
int V_79 = V_74 [ V_72 ] , V_80 = 0 ;
if ( V_79 & V_77 )
V_80 |= V_78 ;
if ( V_79 & V_81 )
V_80 |= V_82 ;
if ( V_79 & V_83 )
V_80 |= V_84 ;
F_18 ( V_2 , V_74 [ V_72 + 1 ] , V_80 ) ;
}
}
F_19 ( V_2 ) ;
}
F_20 ( V_2 ) ;
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
}
static void F_21 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
F_11 ( L_8 , V_59 , V_52 == V_8 -> V_61 [ 1 ] ) ;
F_22 ( V_5 ) ;
}
static void F_23 ( struct V_52 * V_52 )
{
}
static void F_24 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_85 ) {
F_11 ( L_9 , V_59 ) ;
F_25 ( V_5 -> V_21 , V_5 ,
V_8 -> V_85 - 1 ) ;
}
}
static void F_26 ( struct V_52 * V_52 )
{
unsigned char * V_74 = V_52 -> V_68 ;
struct V_86 * V_87 ;
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_89 , V_54 ;
int V_63 = V_52 -> V_63 ;
V_21 = V_52 -> V_75 ;
if ( V_63 ) {
F_11 ( L_10 , V_59 , V_63 ) ;
return;
}
if ( V_52 -> V_76 != 9 ) {
F_11 ( L_11 , V_59 , V_52 -> V_76 ) ;
goto exit;
}
V_87 = (struct V_86 * ) V_74 ;
#if 0
dbg("%s - port status: port %d cts %d dcd %d dsr %d ri %d toff %d txoff %d rxen %d cr %d",
__func__, msg->port, msg->hskia_cts, msg->gpia_dcd, msg->dsr, msg->ri, msg->_txOff,
msg->_txXoff, msg->rxEnabled, msg->controlResponse);
#endif
if ( V_87 -> V_5 >= V_21 -> V_90 ) {
F_11 ( L_12 , V_59 , V_87 -> V_5 ) ;
goto exit;
}
V_5 = V_21 -> V_5 [ V_87 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_87 -> V_91 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_93 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_41 ) {
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && ! F_27 ( V_2 ) )
F_28 ( V_2 ) ;
F_20 ( V_2 ) ;
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
exit: ;
}
static void F_29 ( struct V_52 * V_52 )
{
}
static void F_30 ( struct V_52 * V_52 )
{
int V_54 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
unsigned char * V_74 ;
struct V_7 * V_8 ;
int V_63 = V_52 -> V_63 ;
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
V_74 = V_52 -> V_68 ;
if ( V_52 != V_8 -> V_95 [ V_8 -> V_96 ] )
return;
do {
if ( V_63 ) {
F_11 ( L_5 ,
V_59 , V_63 , F_12 ( V_52 -> V_62 ) ) ;
return;
}
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
V_74 = V_52 -> V_68 ;
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && V_52 -> V_76 ) {
F_31 ( V_2 , V_74 , V_52 -> V_76 ) ;
F_19 ( V_2 ) ;
}
F_20 ( V_2 ) ;
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 ,
V_59 , V_54 ) ;
V_8 -> V_96 ^= 1 ;
V_52 = V_8 -> V_95 [ V_8 -> V_96 ] ;
} while ( V_52 -> V_63 != - V_64 );
}
static void F_32 ( struct V_52 * V_52 )
{
}
static void F_33 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_85 ) {
F_11 ( L_9 , V_59 ) ;
F_34 ( V_5 -> V_21 , V_5 ,
V_8 -> V_85 - 1 ) ;
}
}
static void F_35 ( struct V_52 * V_52 )
{
int V_54 ;
unsigned char * V_74 = V_52 -> V_68 ;
struct V_97 * V_87 ;
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_89 ;
int V_63 = V_52 -> V_63 ;
V_21 = V_52 -> V_75 ;
if ( V_63 ) {
F_11 ( L_10 , V_59 , V_63 ) ;
return;
}
if ( V_52 -> V_76 != sizeof( struct V_97 ) ) {
F_11 ( L_13 , V_59 , V_52 -> V_76 ) ;
goto exit;
}
V_87 = (struct V_97 * ) V_74 ;
if ( V_87 -> V_5 >= V_21 -> V_90 ) {
F_11 ( L_12 , V_59 , V_87 -> V_5 ) ;
goto exit;
}
V_5 = V_21 -> V_5 [ V_87 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_87 -> V_98 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if( V_89 != V_8 -> V_41 && V_89 ) {
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && ! F_27 ( V_2 ) )
F_28 ( V_2 ) ;
F_20 ( V_2 ) ;
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
exit: ;
}
static void F_36 ( struct V_52 * V_52 )
{
}
static void F_37 ( struct V_52 * V_52 )
{
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_72 ;
V_21 = V_52 -> V_75 ;
for ( V_72 = 0 ; V_72 < V_21 -> V_90 ; ++ V_72 ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_85 ) {
F_11 ( L_9 , V_59 ) ;
F_38 ( V_21 , V_5 ,
V_8 -> V_85 - 1 ) ;
break;
}
}
}
static void F_39 ( struct V_52 * V_52 )
{
int V_54 ;
unsigned char * V_74 = V_52 -> V_68 ;
struct V_100 * V_87 ;
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 ;
int V_63 = V_52 -> V_63 ;
V_21 = V_52 -> V_75 ;
if ( V_63 ) {
F_11 ( L_10 , V_59 , V_63 ) ;
return;
}
if ( V_52 -> V_76 !=
sizeof( struct V_100 ) ) {
F_11 ( L_13 , V_59 , V_52 -> V_76 ) ;
goto exit;
}
V_87 = (struct V_100 * ) V_74 ;
if ( V_87 -> V_101 >= V_21 -> V_90 ) {
F_11 ( L_12 ,
V_59 , V_87 -> V_101 ) ;
goto exit;
}
V_5 = V_21 -> V_5 [ V_87 -> V_101 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_87 -> V_98 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_41 && V_89 ) {
struct V_1 * V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && ! F_27 ( V_2 ) )
F_28 ( V_2 ) ;
F_20 ( V_2 ) ;
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
exit: ;
}
static void F_40 ( struct V_52 * V_52 )
{
}
static void F_41 ( struct V_52 * V_52 )
{
int V_72 , V_54 ;
int V_73 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
unsigned char * V_74 = V_52 -> V_68 ;
int V_63 = V_52 -> V_63 ;
V_73 = F_12 ( V_52 -> V_62 ) ;
if ( V_63 ) {
F_11 ( L_5 , V_59 ,
V_63 , V_73 ) ;
return;
}
V_5 = V_52 -> V_75 ;
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && V_52 -> V_76 ) {
if ( ( V_74 [ 0 ] & 0x80 ) == 0 ) {
F_31 ( V_2 , V_74 + 1 ,
V_52 -> V_76 - 1 ) ;
} else {
for ( V_72 = 0 ; V_72 + 1 < V_52 -> V_76 ; V_72 += 2 ) {
int V_79 = V_74 [ V_72 ] , V_80 = 0 ;
if ( V_79 & V_77 )
V_80 |= V_78 ;
if ( V_79 & V_81 )
V_80 |= V_82 ;
if ( V_79 & V_83 )
V_80 |= V_84 ;
F_18 ( V_2 , V_74 [ V_72 + 1 ] , V_80 ) ;
}
}
F_19 ( V_2 ) ;
}
F_20 ( V_2 ) ;
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
}
static void F_42 ( struct V_52 * V_52 )
{
int V_72 , V_102 , V_103 , V_54 ;
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
unsigned char * V_74 = V_52 -> V_68 ;
int V_63 = V_52 -> V_63 ;
V_21 = V_52 -> V_75 ;
if ( V_63 ) {
F_11 ( L_10 , V_59 , V_63 ) ;
return;
}
V_72 = 0 ;
V_102 = 0 ;
if ( V_52 -> V_76 ) {
while ( V_72 < V_52 -> V_76 ) {
if ( V_74 [ V_72 ] >= V_21 -> V_90 ) {
F_11 ( L_12 ,
V_59 , V_74 [ V_72 ] ) ;
return;
}
V_5 = V_21 -> V_5 [ V_74 [ V_72 ++ ] ] ;
V_2 = F_17 ( & V_5 -> V_5 ) ;
V_102 = V_74 [ V_72 ++ ] ;
if ( ( V_74 [ V_72 ] & 0x80 ) == 0 ) {
V_72 ++ ;
for ( V_103 = 1 ; V_103 < V_102 ; ++ V_103 )
F_18 ( V_2 , V_74 [ V_72 ++ ] , 0 ) ;
} else {
for ( V_103 = 0 ; V_103 + 1 < V_102 ; V_103 += 2 ) {
int V_79 = V_74 [ V_72 ] , V_80 = 0 ;
if ( V_79 & V_77 )
V_80 |= V_78 ;
if ( V_79 & V_81 )
V_80 |= V_82 ;
if ( V_79 & V_83 )
V_80 |= V_84 ;
F_18 ( V_2 ,
V_74 [ V_72 + 1 ] , V_80 ) ;
V_72 += 2 ;
}
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
}
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
}
static void F_43 ( struct V_52 * V_52 )
{
}
static void F_44 ( struct V_52 * V_52 )
{
int V_72 , V_54 ;
int V_73 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
unsigned char * V_74 = V_52 -> V_68 ;
int V_63 = V_52 -> V_63 ;
V_73 = F_12 ( V_52 -> V_62 ) ;
if ( V_63 ) {
F_11 ( L_5 ,
V_59 , V_63 , V_73 ) ;
return;
}
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
if ( V_52 -> V_76 ) {
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_8 -> V_26 > 57600 )
F_31 ( V_2 , V_74 , V_52 -> V_76 ) ;
else {
if ( ( V_74 [ 0 ] & 0x80 ) == 0 ) {
if ( V_74 [ 0 ] & V_77 )
V_54 = V_78 ;
else
V_54 = 0 ;
for ( V_72 = 1 ; V_72 < V_52 -> V_76 ; ++ V_72 )
F_18 ( V_2 , V_74 [ V_72 ] ,
V_54 ) ;
} else {
F_11 ( L_6 , V_59 ) ;
for ( V_72 = 0 ; V_72 + 1 < V_52 -> V_76 ; V_72 += 2 ) {
int V_79 = V_74 [ V_72 ] , V_80 = 0 ;
if ( V_79 & V_77 )
V_80 |= V_78 ;
if ( V_79 & V_81 )
V_80 |= V_82 ;
if ( V_79 & V_83 )
V_80 |= V_84 ;
F_18 ( V_2 , V_74 [ V_72 + 1 ] ,
V_80 ) ;
}
}
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
}
static void F_45 ( struct V_52 * V_52 )
{
unsigned char * V_74 = V_52 -> V_68 ;
struct V_104 * V_87 ;
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_89 , V_54 ;
int V_63 = V_52 -> V_63 ;
V_21 = V_52 -> V_75 ;
if ( V_63 ) {
F_11 ( L_10 , V_59 , V_63 ) ;
return;
}
if ( V_52 -> V_76 < 14 ) {
F_11 ( L_11 , V_59 , V_52 -> V_76 ) ;
goto exit;
}
V_87 = (struct V_104 * ) V_74 ;
V_5 = V_21 -> V_5 [ 0 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_87 -> V_98 ) ? 1 : 0 ) ;
V_8 -> V_39 = ( ( V_87 -> V_92 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_99 ) ? 1 : 0 ) ;
V_8 -> V_43 = ( ( V_87 -> V_94 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_41 && V_89 ) {
V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && ! F_27 ( V_2 ) )
F_28 ( V_2 ) ;
F_20 ( V_2 ) ;
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
exit:
;
}
static void F_46 ( struct V_52 * V_52 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_5 = V_52 -> V_75 ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_85 ) {
F_11 ( L_9 , V_59 ) ;
F_47 ( V_5 -> V_21 , V_5 ,
V_8 -> V_85 - 1 ) ;
}
}
static void F_48 ( struct V_52 * V_52 )
{
int V_54 ;
unsigned char * V_74 = V_52 -> V_68 ;
struct V_105 * V_87 ;
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_89 ;
int V_63 = V_52 -> V_63 ;
V_21 = V_52 -> V_75 ;
if ( V_63 ) {
F_11 ( L_10 , V_59 , V_63 ) ;
return;
}
if ( V_52 -> V_76 !=
sizeof( struct V_105 ) ) {
F_11 ( L_13 , V_59 , V_52 -> V_76 ) ;
return;
}
V_87 = (struct V_105 * ) V_74 ;
if ( V_87 -> V_5 >= V_21 -> V_90 ) {
F_11 ( L_12 , V_59 , V_87 -> V_5 ) ;
return;
}
V_5 = V_21 -> V_5 [ V_87 -> V_5 ] ;
V_8 = F_2 ( V_5 ) ;
V_89 = V_8 -> V_41 ;
V_8 -> V_37 = ( ( V_87 -> V_91 ) ? 1 : 0 ) ;
V_8 -> V_41 = ( ( V_87 -> V_93 ) ? 1 : 0 ) ;
if ( V_89 != V_8 -> V_41 && V_89 ) {
struct V_1 * V_2 = F_17 ( & V_5 -> V_5 ) ;
if ( V_2 && ! F_27 ( V_2 ) )
F_28 ( V_2 ) ;
F_20 ( V_2 ) ;
}
V_54 = F_15 ( V_52 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_7 , V_59 , V_54 ) ;
}
static void F_49 ( struct V_52 * V_52 )
{
struct V_88 * V_21 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_72 ;
V_21 = V_52 -> V_75 ;
for ( V_72 = 0 ; V_72 < V_21 -> V_90 ; ++ V_72 ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
V_8 = F_2 ( V_5 ) ;
if ( V_8 -> V_85 ) {
F_11 ( L_9 , V_59 ) ;
F_50 ( V_21 , V_5 ,
V_8 -> V_85 - 1 ) ;
break;
}
}
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_49 ;
int V_106 ;
struct V_52 * V_53 ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
if ( V_15 -> V_57 == V_58 )
V_106 = 64 ;
else
V_106 = 63 ;
V_49 = V_8 -> V_60 ;
V_53 = V_8 -> V_61 [ V_49 ] ;
if ( V_53 != NULL ) {
if ( V_53 -> V_63 != - V_64 )
return V_106 ;
V_49 = ( V_49 + 1 ) & V_15 -> V_71 ;
V_53 = V_8 -> V_61 [ V_49 ] ;
if ( V_53 != NULL ) {
if ( V_53 -> V_63 != - V_64 )
return V_106 ;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_7 * V_8 ;
struct V_107 * V_108 ;
struct V_88 * V_21 = V_5 -> V_21 ;
const struct V_14 * V_15 ;
int V_72 , V_54 ;
int V_12 , V_13 ;
struct V_52 * V_52 ;
unsigned int V_16 = 0 ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_8 -> V_17 ;
V_8 -> V_33 = 1 ;
V_8 -> V_35 = 1 ;
V_8 -> V_26 = 9600 ;
V_8 -> V_109 = 0 ;
V_8 -> V_110 = 0 ;
V_8 -> V_60 = 0 ;
V_8 -> V_96 = 0 ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_52 = V_8 -> V_95 [ V_72 ] ;
if ( V_52 == NULL )
continue;
F_54 ( V_52 -> V_111 , V_52 -> V_62 ) ;
V_54 = F_15 ( V_52 , V_112 ) ;
if ( V_54 != 0 )
F_11 ( L_14 ,
V_59 , V_72 , V_54 ) ;
}
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
V_52 = V_8 -> V_61 [ V_72 ] ;
if ( V_52 == NULL )
continue;
}
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
if ( V_2 ) {
V_16 = V_2 -> V_18 -> V_19 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 >= 0
&& V_15 -> V_23 ( V_12 , V_15 -> V_24 ,
NULL , NULL , NULL , V_13 ) == V_25 ) {
V_8 -> V_26 = V_12 ;
}
}
V_8 -> V_16 = V_16 ;
V_8 -> V_27 = ( V_16 & V_28 ) ? V_29 : V_30 ;
F_3 ( V_5 , 1 ) ;
return 0 ;
}
static inline void F_55 ( struct V_52 * V_52 )
{
if ( V_52 && V_52 -> V_63 == - V_64 )
F_56 ( V_52 ) ;
}
static void F_57 ( struct V_4 * V_5 , int V_113 )
{
struct V_7 * V_8 = F_2 ( V_5 ) ;
V_8 -> V_33 = V_113 ;
V_8 -> V_35 = V_113 ;
F_3 ( V_5 , 0 ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
int V_72 ;
struct V_88 * V_21 = V_5 -> V_21 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_8 -> V_33 = 0 ;
V_8 -> V_35 = 0 ;
if ( V_21 -> V_111 ) {
F_3 ( V_5 , 2 ) ;
F_59 ( 100 ) ;
}
V_8 -> V_60 = 0 ;
V_8 -> V_96 = 0 ;
if ( V_21 -> V_111 ) {
F_55 ( V_8 -> V_114 ) ;
for ( V_72 = 0 ; V_72 < 2 ; V_72 ++ ) {
F_55 ( V_8 -> V_95 [ V_72 ] ) ;
F_55 ( V_8 -> V_61 [ V_72 ] ) ;
}
}
}
static int F_60 ( struct V_88 * V_21 )
{
int V_115 ;
const struct V_116 * V_117 ;
char * V_118 ;
const struct V_119 * V_120 ;
F_11 ( L_15 ,
F_61 ( V_21 -> V_111 -> V_121 . V_122 ) ,
F_61 ( V_21 -> V_111 -> V_121 . V_123 ) ) ;
if ( ( F_61 ( V_21 -> V_111 -> V_121 . V_122 ) & 0x8000 )
!= 0x8000 ) {
F_11 ( L_16 ) ;
return 1 ;
}
switch ( F_61 ( V_21 -> V_111 -> V_121 . V_123 ) ) {
case V_124 :
V_118 = L_17 ;
break;
case V_125 :
V_118 = L_18 ;
break;
case V_126 :
V_118 = L_19 ;
break;
case V_127 :
V_118 = L_20 ;
break;
case V_128 :
V_118 = L_21 ;
break;
case V_129 :
V_118 = L_22 ;
break;
case V_130 :
V_118 = L_23 ;
break;
case V_131 :
V_118 = L_24 ;
break;
case V_132 :
V_118 = L_25 ;
break;
case V_133 :
V_118 = L_26 ;
break;
case V_134 :
V_118 = L_27 ;
break;
case V_135 :
V_118 = L_28 ;
break;
default:
F_62 ( & V_21 -> V_111 -> V_111 , L_29 ,
F_61 ( V_21 -> V_111 -> V_121 . V_123 ) ) ;
return 1 ;
}
if ( F_63 ( & V_120 , V_118 , & V_21 -> V_111 -> V_111 ) ) {
F_62 ( & V_21 -> V_111 -> V_111 , L_30 , V_118 ) ;
return ( 1 ) ;
}
F_11 ( L_31 , V_118 ) ;
V_115 = F_64 ( V_21 , 1 ) ;
V_117 = ( const struct V_116 * ) V_120 -> V_74 ;
while ( V_117 ) {
V_115 = F_65 ( V_21 , F_66 ( V_117 -> V_136 ) ,
( unsigned char * ) V_117 -> V_74 ,
F_67 ( V_117 -> V_102 ) , 0xa0 ) ;
if ( V_115 < 0 ) {
F_62 ( & V_21 -> V_111 -> V_111 , L_32 ,
V_115 , F_66 ( V_117 -> V_136 ) ,
V_117 -> V_74 , F_67 ( V_117 -> V_102 ) ) ;
break;
}
V_117 = F_68 ( V_117 ) ;
}
F_69 ( V_120 ) ;
V_115 = F_64 ( V_21 , 0 ) ;
return 1 ;
}
static struct V_137 const * F_70 ( struct V_88 const * V_21 ,
int V_73 )
{
struct V_138 * V_139 ;
struct V_137 * V_140 ;
int V_72 ;
V_139 = V_21 -> V_141 -> V_142 ;
for ( V_72 = 0 ; V_72 < V_139 -> V_143 . V_144 ; ++ V_72 ) {
V_140 = & V_139 -> V_73 [ V_72 ] . V_143 ;
if ( V_140 -> V_145 == V_73 )
return V_140 ;
}
F_71 ( & V_21 -> V_141 -> V_111 , L_33
L_34 , V_73 ) ;
return NULL ;
}
static struct V_52 * F_72 ( struct V_88 * V_21 , int V_73 ,
int V_146 , void * V_147 , char * V_47 , int V_102 ,
void (* F_73)( struct V_52 * ) )
{
struct V_52 * V_52 ;
struct V_137 const * V_148 ;
char const * V_149 ;
if ( V_73 == - 1 )
return NULL ;
F_11 ( L_35 , V_59 , V_73 ) ;
V_52 = F_74 ( 0 , V_112 ) ;
if ( V_52 == NULL ) {
F_11 ( L_36 , V_59 , V_73 ) ;
return NULL ;
}
if ( V_73 == 0 ) {
return V_52 ;
}
V_148 = F_70 ( V_21 , V_73 ) ;
if ( ! V_148 ) {
return V_52 ;
}
if ( F_75 ( V_148 ) ) {
V_149 = L_37 ;
F_76 ( V_52 , V_21 -> V_111 ,
F_77 ( V_21 -> V_111 , V_73 ) | V_146 ,
V_47 , V_102 , F_73 , V_147 ,
V_148 -> V_150 ) ;
} else if ( F_78 ( V_148 ) ) {
V_149 = L_38 ;
F_79 ( V_52 , V_21 -> V_111 ,
F_80 ( V_21 -> V_111 , V_73 ) | V_146 ,
V_47 , V_102 , F_73 , V_147 ) ;
} else {
F_71 ( & V_21 -> V_141 -> V_111 ,
L_39 ,
F_81 ( V_148 ) ) ;
F_82 ( V_52 ) ;
return NULL ;
}
F_11 ( L_40 ,
V_59 , V_52 , V_149 , V_73 ) ;
return V_52 ;
}
static void F_83 ( struct V_88 * V_21 )
{
int V_72 , V_151 ;
struct V_107 * V_108 ;
const struct V_14 * V_15 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_152 * V_153 ;
int V_154 ;
V_108 = F_53 ( V_21 ) ;
V_15 = V_108 -> V_17 ;
V_153 = & V_155 [ V_15 -> V_57 ] ;
V_108 -> V_156 = F_72
( V_21 , V_15 -> V_157 , V_158 ,
V_21 , V_108 -> V_159 , V_160 ,
V_153 -> V_161 ) ;
V_108 -> V_162 = F_72
( V_21 , V_15 -> V_163 , V_158 ,
V_21 , V_108 -> V_164 , V_165 ,
F_42 ) ;
V_108 -> V_166 = F_72
( V_21 , V_15 -> V_167 , V_168 ,
V_21 , V_108 -> V_169 , V_170 ,
V_153 -> V_171 ) ;
for ( V_72 = 0 ; V_72 < V_15 -> V_90 ; V_72 ++ ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
V_8 = F_2 ( V_5 ) ;
V_154 = V_15 -> V_172 [ V_72 ] ;
for ( V_151 = 0 ; V_151 <= V_15 -> V_173 ; ++ V_151 , ++ V_154 ) {
V_8 -> V_95 [ V_151 ] = F_72
( V_21 , V_154 , V_158 , V_5 ,
V_8 -> V_174 [ V_151 ] , 64 ,
V_153 -> V_175 ) ;
}
for (; V_151 < 2 ; ++ V_151 )
V_8 -> V_95 [ V_151 ] = NULL ;
V_154 = V_15 -> V_176 [ V_72 ] ;
for ( V_151 = 0 ; V_151 <= V_15 -> V_71 ; ++ V_151 , ++ V_154 ) {
V_8 -> V_61 [ V_151 ] = F_72
( V_21 , V_154 , V_168 , V_5 ,
V_8 -> V_177 [ V_151 ] , 64 ,
V_153 -> V_178 ) ;
}
for (; V_151 < 2 ; ++ V_151 )
V_8 -> V_61 [ V_151 ] = NULL ;
V_8 -> V_114 = F_72
( V_21 , V_15 -> V_179 [ V_72 ] , V_158 ,
V_5 , V_8 -> V_180 , 1 , V_153 -> V_181 ) ;
V_8 -> V_182 = F_72
( V_21 , V_15 -> V_183 [ V_72 ] , V_168 ,
V_5 , V_8 -> V_184 , 64 ,
V_153 -> V_185 ) ;
}
}
static int F_84 ( T_1 V_12 , T_1 V_24 , T_2 * V_186 ,
T_2 * V_187 , T_2 * V_188 , int V_189 )
{
T_1 V_190 ,
div ,
V_191 ;
F_11 ( L_41 , V_59 , V_12 ) ;
V_190 = V_12 * 16L ;
if ( V_190 == 0 )
return V_192 ;
if ( V_12 > 57600 )
return V_192 ;
div = V_24 / V_190 ;
if ( div == 0 )
return V_192 ;
else
V_191 = 0 - div ;
if ( div > 0xffff )
return V_192 ;
if ( V_187 )
* V_187 = ( T_2 ) ( V_191 & 0xff ) ;
if ( V_186 )
* V_186 = ( T_2 ) ( ( V_191 >> 8 ) & 0xff ) ;
if ( V_187 && V_186 )
F_11 ( L_42 ,
V_59 , V_12 , * V_186 , * V_187 ) ;
return V_25 ;
}
static int F_85 ( T_1 V_12 , T_1 V_24 , T_2 * V_186 ,
T_2 * V_187 , T_2 * V_188 , int V_189 )
{
T_1 V_190 ,
div ;
F_11 ( L_41 , V_59 , V_12 ) ;
V_190 = V_12 * 16L ;
if ( V_190 == 0 )
return V_192 ;
div = V_24 / V_190 ;
if ( div == 0 )
return V_192 ;
if ( div > 0xffff )
return V_192 ;
if ( V_187 )
* V_187 = ( T_2 ) ( div & 0xff ) ;
if ( V_186 )
* V_186 = ( T_2 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_187 && V_186 )
F_11 ( L_42 ,
V_59 , V_12 , * V_186 , * V_187 ) ;
return V_25 ;
}
static int F_86 ( T_1 V_12 , T_1 V_24 , T_2 * V_186 ,
T_2 * V_187 , T_2 * V_188 , int V_189 )
{
T_1 V_190 ,
V_193 ,
div ,
V_194 ,
V_195 ,
V_196 ;
T_2 V_197 ;
int V_72 ;
F_11 ( L_41 , V_59 , V_12 ) ;
V_190 = V_12 * 16L ;
if ( V_190 == 0 )
return V_192 ;
V_196 = 0xffffffff ;
V_197 = 0 ;
for ( V_72 = 8 ; V_72 <= 0xff ; ++ V_72 ) {
V_193 = ( V_24 * 8 ) / ( T_1 ) V_72 ;
div = V_193 / V_190 ;
if ( div == 0 )
continue;
V_194 = V_193 / div ;
V_195 = ( V_194 > V_190 ) ? ( V_194 - V_190 ) : ( V_190 - V_194 ) ;
if ( V_195 < V_196 ) {
V_197 = V_72 ;
V_196 = V_195 ;
}
}
if ( V_197 == 0 )
return V_192 ;
V_193 = ( V_24 * 8 ) / ( T_1 ) V_197 ;
div = V_193 / V_190 ;
if ( V_187 )
* V_187 = ( T_2 ) ( div & 0xff ) ;
if ( V_186 )
* V_186 = ( T_2 ) ( ( div >> 8 ) & 0xff ) ;
if ( V_188 ) {
* V_188 = V_197 ;
}
return V_25 ;
}
static int F_87 ( T_1 V_12 , T_1 V_24 , T_2 * V_186 ,
T_2 * V_187 , T_2 * V_188 , int V_189 )
{
T_1 V_190 ,
div ,
V_191 ;
F_11 ( L_41 , V_59 , V_12 ) ;
V_190 = V_12 * 16L ;
if ( V_190 == 0 )
return V_192 ;
div = V_198 / V_190 ;
if ( div == 0 )
return V_192 ;
else
V_191 = 0 - div ;
if ( V_189 == 0 ) {
if ( div > 0xffff )
return V_192 ;
} else {
if ( V_189 == 1 ) {
if ( div > 0xff )
return V_192 ;
} else
return V_192 ;
}
if ( V_187 )
* V_187 = ( T_2 ) ( V_191 & 0xff ) ;
if ( V_186 )
* V_186 = ( T_2 ) ( ( V_191 >> 8 ) & 0xff ) ;
F_11 ( L_43 , V_59 , V_12 ) ;
return V_25 ;
}
static int F_25 ( struct V_88 * V_21 ,
struct V_4 * V_5 ,
int V_199 )
{
struct V_200 V_87 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
int V_182 ;
struct V_52 * V_53 ;
int V_13 , V_54 ;
F_11 ( L_44 , V_59 , V_199 ) ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_108 -> V_17 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_182 = V_15 -> V_183 [ V_5 -> V_20 ] ;
V_53 = V_8 -> V_182 ;
F_11 ( L_45 , V_59 , F_12 ( V_53 -> V_62 ) ) ;
if ( V_53 == NULL ) {
F_11 ( L_46 , V_59 ) ;
return - 1 ;
}
if ( ( V_199 + 1 ) > V_8 -> V_85 )
V_8 -> V_85 = V_199 + 1 ;
if ( V_53 -> V_63 == - V_64 ) {
F_59 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_200 ) ) ;
if ( V_8 -> V_109 != V_8 -> V_26 ) {
V_8 -> V_109 = V_8 -> V_26 ;
V_87 . V_201 = 0xff ;
if ( V_15 -> V_23
( V_8 -> V_26 , V_15 -> V_24 , & V_87 . V_202 ,
& V_87 . V_203 , & V_87 . V_188 , V_13 ) == V_192 ) {
F_11 ( L_47 ,
V_59 , V_8 -> V_26 ) ;
V_87 . V_203 = 0 ;
V_87 . V_202 = 125 ;
V_87 . V_188 = 10 ;
}
V_87 . V_204 = 0xff ;
}
V_87 . V_205 = ( V_8 -> V_16 & V_206 ) ? V_207 : V_208 ;
switch ( V_8 -> V_16 & V_209 ) {
case V_210 :
V_87 . V_205 |= V_211 ;
break;
case V_212 :
V_87 . V_205 |= V_213 ;
break;
case V_214 :
V_87 . V_205 |= V_215 ;
break;
case V_216 :
V_87 . V_205 |= V_217 ;
break;
}
if ( V_8 -> V_16 & V_218 ) {
V_87 . V_205 |= ( V_8 -> V_16 & V_219 ) ?
V_220 : V_221 ;
}
V_87 . V_222 = 0xff ;
V_87 . V_223 = ( V_8 -> V_27 == V_29 ) ;
V_87 . V_224 = 0 ;
V_87 . V_225 = 0xff ;
V_87 . V_226 = 16 ;
V_87 . V_227 = 17 ;
V_87 . V_228 = 19 ;
if ( V_199 == 1 ) {
V_87 . V_229 = 1 ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 1 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0xff ;
}
else if ( V_199 == 2 ) {
V_87 . V_229 = 0 ;
V_87 . V_230 = 1 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 1 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0 ;
}
else {
V_87 . V_229 = ( ! V_8 -> V_9 ) ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = ( V_8 -> V_9 ) ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 0 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0x0 ;
}
V_87 . V_239 = 0xff ;
V_87 . V_240 = V_8 -> V_33 ;
V_87 . V_241 = 0xff ;
V_87 . V_242 = V_8 -> V_35 ;
V_8 -> V_85 = 0 ;
memcpy ( V_53 -> V_68 , & V_87 , sizeof( V_87 ) ) ;
V_53 -> V_69 = sizeof( V_87 ) ;
V_54 = F_15 ( V_53 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_48 , V_59 , V_54 ) ;
#if 0
else {
dbg("%s - usb_submit_urb(%d) OK %d bytes (end %d)", __func__
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0 ;
}
static int F_34 ( struct V_88 * V_21 ,
struct V_4 * V_5 ,
int V_199 )
{
struct V_243 V_87 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_13 , V_54 ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_108 -> V_17 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
V_53 = V_8 -> V_182 ;
if ( V_53 == NULL ) {
F_11 ( L_46 , V_59 ) ;
return - 1 ;
}
if ( ( V_199 + 1 ) > V_8 -> V_85 )
V_8 -> V_85 = V_199 + 1 ;
if ( V_53 -> V_63 == - V_64 ) {
F_11 ( L_49 , V_59 ) ;
F_59 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_243 ) ) ;
V_87 . V_244 = 1 ;
if ( V_15 -> V_23 ( V_8 -> V_26 , V_15 -> V_24 ,
& V_87 . V_202 , & V_87 . V_203 , NULL , V_13 ) == V_192 ) {
F_11 ( L_50 ,
V_59 , V_8 -> V_26 ) ;
V_87 . V_203 = 0xff ;
V_87 . V_202 = 0xb2 ;
}
V_87 . V_245 = 0 ;
V_87 . V_223 = ( V_8 -> V_27 == V_29 ) ;
V_87 . V_224 = 0 ;
V_87 . V_246 = V_8 -> V_33 ;
V_87 . V_247 = V_8 -> V_35 ;
V_87 . V_226 = 16 ;
V_87 . V_248 = 10 ;
V_87 . V_249 = 45 ;
V_87 . V_227 = 17 ;
V_87 . V_228 = 19 ;
if ( V_199 == 1 ) {
V_87 . V_229 = 1 ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_250 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 1 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0xff ;
}
else if ( V_199 == 2 ) {
V_87 . V_229 = 0 ;
V_87 . V_230 = 1 ;
V_87 . V_231 = 0 ;
V_87 . V_250 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 1 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0 ;
}
else {
V_87 . V_229 = ( ! V_8 -> V_9 ) ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_250 = 0 ;
V_87 . V_232 = ( V_8 -> V_9 ) ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 0 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0x0 ;
}
V_8 -> V_85 = 0 ;
memcpy ( V_53 -> V_68 , & V_87 , sizeof( V_87 ) ) ;
V_53 -> V_69 = sizeof( V_87 ) ;
V_54 = F_15 ( V_53 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_51 , V_59 ) ;
#if 0
else {
dbg("%s - usb_submit_urb(setup) OK %d bytes", __func__,
this_urb->transfer_buffer_length);
}
#endif
return 0 ;
}
static int F_38 ( struct V_88 * V_21 ,
struct V_4 * V_5 ,
int V_199 )
{
struct V_251 V_87 ;
struct V_252 * V_253 = NULL ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_54 , V_13 ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_108 -> V_17 ;
V_53 = V_108 -> V_166 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
if ( V_53 == NULL ) {
F_11 ( L_52 , V_59 , V_5 -> V_20 ) ;
return - 1 ;
}
F_11 ( L_53 ,
V_59 , F_12 ( V_53 -> V_62 ) ,
V_5 -> V_20 , V_13 ) ;
if ( ( V_199 + 1 ) > V_8 -> V_85 )
V_8 -> V_85 = V_199 + 1 ;
if ( V_53 -> V_63 == - V_64 ) {
F_59 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_251 ) ) ;
V_87 . V_101 = V_13 ;
if ( V_8 -> V_109 != V_8 -> V_26 ) {
V_8 -> V_109 = V_8 -> V_26 ;
V_87 . V_201 = 0xff ;
if ( V_15 -> V_23
( V_8 -> V_26 , V_15 -> V_24 , & V_87 . V_202 ,
& V_87 . V_203 , & V_87 . V_188 , V_13 ) == V_192 ) {
F_11 ( L_47 ,
V_59 , V_8 -> V_26 ) ;
V_87 . V_203 = 0 ;
V_87 . V_202 = 125 ;
V_87 . V_188 = 10 ;
}
}
V_87 . V_205 = ( V_8 -> V_16 & V_206 ) ? V_207 : V_208 ;
switch ( V_8 -> V_16 & V_209 ) {
case V_210 :
V_87 . V_205 |= V_211 ;
break;
case V_212 :
V_87 . V_205 |= V_213 ;
break;
case V_214 :
V_87 . V_205 |= V_215 ;
break;
case V_216 :
V_87 . V_205 |= V_217 ;
break;
}
if ( V_8 -> V_16 & V_218 ) {
V_87 . V_205 |= ( V_8 -> V_16 & V_219 ) ?
V_220 : V_221 ;
}
V_87 . V_222 = 0xff ;
V_87 . V_223 = ( V_8 -> V_27 == V_29 ) ;
V_87 . V_224 = 0 ;
V_87 . V_225 = 0xff ;
V_87 . V_226 = 16 ;
V_87 . V_227 = 17 ;
V_87 . V_228 = 19 ;
if ( V_199 == 1 ) {
V_87 . V_229 = 1 ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 1 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0xff ;
V_87 . V_254 = 1 ;
V_87 . V_255 = 0 ;
}
else if ( V_199 == 2 ) {
V_87 . V_229 = 0 ;
V_87 . V_230 = 1 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 1 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0 ;
V_87 . V_254 = 0 ;
V_87 . V_255 = 1 ;
}
else {
V_87 . V_229 = ( ! V_8 -> V_9 ) ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = ( V_8 -> V_9 ) ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 0 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0x0 ;
V_87 . V_254 = 0 ;
V_87 . V_255 = 0 ;
}
V_87 . V_256 = 0xff ;
V_87 . V_246 = V_8 -> V_33 ;
V_87 . V_257 = 0xff ;
V_87 . V_247 = V_8 -> V_35 ;
V_8 -> V_85 = 0 ;
if ( V_15 -> V_258 == V_259 ) {
V_253 = ( void * ) ( V_108 -> V_260 ) ;
V_253 -> V_261 = V_262 | V_168 ;
V_253 -> V_263 = 0xB0 ; ;
V_253 -> V_264 = 0 ;
V_253 -> V_265 = 0 ;
V_253 -> V_266 = F_88 ( sizeof( V_87 ) ) ;
memcpy ( V_108 -> V_169 , & V_87 , sizeof( V_87 ) ) ;
F_89 ( V_53 , V_21 -> V_111 ,
F_90 ( V_21 -> V_111 , 0 ) ,
( unsigned char * ) V_253 , V_108 -> V_169 ,
sizeof( V_87 ) , F_37 , V_21 ) ;
} else {
memcpy ( V_53 -> V_68 , & V_87 , sizeof( V_87 ) ) ;
V_53 -> V_69 = sizeof( V_87 ) ;
}
V_54 = F_15 ( V_53 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_48 , V_59 , V_54 ) ;
#if 0
else {
dbg("%s - usb_submit_urb(%d) OK %d bytes (end %d)", __func__,
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0 ;
}
static int F_47 ( struct V_88 * V_21 ,
struct V_4 * V_5 ,
int V_199 )
{
struct V_267 V_87 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_54 ;
T_2 V_188 ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_108 -> V_17 ;
V_53 = V_8 -> V_182 ;
if ( V_53 == NULL ) {
F_11 ( L_46 , V_59 ) ;
return - 1 ;
}
if ( ( V_199 + 1 ) > V_8 -> V_85 )
V_8 -> V_85 = V_199 + 1 ;
if ( V_53 -> V_63 == - V_64 ) {
F_11 ( L_49 , V_59 ) ;
F_59 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_267 ) ) ;
if ( V_8 -> V_109 != V_8 -> V_26 ) {
V_8 -> V_109 = V_8 -> V_26 ;
V_87 . V_201 = 0x01 ;
if ( V_15 -> V_23
( V_8 -> V_26 , V_15 -> V_24 , & V_87 . V_202 ,
& V_87 . V_203 , & V_188 , 0 ) == V_192 ) {
F_11 ( L_47 ,
V_59 , V_8 -> V_26 ) ;
V_8 -> V_26 = 9600 ;
V_15 -> V_23 ( V_8 -> V_26 , V_15 -> V_24 ,
& V_87 . V_202 , & V_87 . V_203 , & V_188 , 0 ) ;
}
V_87 . V_268 = 1 ;
V_87 . V_269 = 1 ;
}
if ( V_8 -> V_26 > 57600 ) {
V_87 . V_270 = V_271 ;
V_87 . V_272 = V_273 ;
} else {
V_87 . V_270 = V_274 ;
V_87 . V_272 = V_275 ;
}
V_87 . V_205 = ( V_8 -> V_16 & V_206 ) ? V_207 : V_208 ;
switch ( V_8 -> V_16 & V_209 ) {
case V_210 :
V_87 . V_205 |= V_211 ;
break;
case V_212 :
V_87 . V_205 |= V_213 ;
break;
case V_214 :
V_87 . V_205 |= V_215 ;
break;
case V_216 :
V_87 . V_205 |= V_217 ;
break;
}
if ( V_8 -> V_16 & V_218 ) {
V_87 . V_205 |= ( V_8 -> V_16 & V_219 ) ?
V_220 : V_221 ;
}
if ( V_8 -> V_110 != V_8 -> V_16 ) {
V_8 -> V_110 = V_8 -> V_16 ;
V_87 . V_222 = 0x01 ;
}
if ( V_8 -> V_27 == V_29 )
V_87 . V_276 = V_277 ;
V_87 . V_278 = 0x01 ;
V_87 . V_279 = 0x01 ;
V_87 . V_280 = 16 ;
V_87 . V_281 = 16 ;
V_87 . V_282 = 0 ;
V_87 . V_227 = 17 ;
V_87 . V_228 = 19 ;
if ( V_199 == 1 ) {
V_87 . V_283 = 1 ;
V_87 . V_235 = 1 ;
V_87 . V_232 = ( V_8 -> V_9 ) ;
}
else if ( V_199 == 2 )
V_87 . V_283 = 0 ;
else {
V_87 . V_283 = 1 ;
V_87 . V_232 = ( V_8 -> V_9 ) ;
}
V_87 . V_256 = 0x01 ;
V_87 . V_246 = V_8 -> V_33 ;
V_87 . V_257 = 0x01 ;
V_87 . V_247 = V_8 -> V_35 ;
V_8 -> V_85 = 0 ;
memcpy ( V_53 -> V_68 , & V_87 , sizeof( V_87 ) ) ;
V_53 -> V_69 = sizeof( V_87 ) ;
V_54 = F_15 ( V_53 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_48 , V_59 , V_54 ) ;
return 0 ;
}
static int F_50 ( struct V_88 * V_21 ,
struct V_4 * V_5 ,
int V_199 )
{
struct V_284 V_87 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
struct V_52 * V_53 ;
int V_54 , V_13 ;
V_108 = F_53 ( V_21 ) ;
V_8 = F_2 ( V_5 ) ;
V_15 = V_108 -> V_17 ;
V_53 = V_108 -> V_166 ;
V_13 = V_5 -> V_20 - V_5 -> V_21 -> V_22 ;
if ( V_53 == NULL ) {
F_11 ( L_52 , V_59 ,
V_5 -> V_20 ) ;
return - 1 ;
}
if ( ( V_199 + 1 ) > V_8 -> V_85 )
V_8 -> V_85 = V_199 + 1 ;
if ( V_53 -> V_63 == - V_64 ) {
F_59 ( 5 ) ;
return - 1 ;
}
memset ( & V_87 , 0 , sizeof( struct V_284 ) ) ;
V_87 . V_5 = V_13 ;
if ( V_8 -> V_109 != V_8 -> V_26 ) {
V_8 -> V_109 = V_8 -> V_26 ;
V_87 . V_201 = 0xff ;
if ( V_15 -> V_23
( V_8 -> V_26 , V_15 -> V_24 , & V_87 . V_202 ,
& V_87 . V_203 , & V_87 . V_188 , V_13 ) == V_192 ) {
F_11 ( L_47 ,
V_59 , V_8 -> V_26 ) ;
V_87 . V_203 = 0 ;
V_87 . V_202 = 125 ;
V_87 . V_188 = 10 ;
}
V_87 . V_204 = 0xff ;
}
V_87 . V_205 = ( V_8 -> V_16 & V_206 ) ? V_207 : V_208 ;
switch ( V_8 -> V_16 & V_209 ) {
case V_210 :
V_87 . V_205 |= V_211 ;
break;
case V_212 :
V_87 . V_205 |= V_213 ;
break;
case V_214 :
V_87 . V_205 |= V_215 ;
break;
case V_216 :
V_87 . V_205 |= V_217 ;
break;
}
if ( V_8 -> V_16 & V_218 ) {
V_87 . V_205 |= ( V_8 -> V_16 & V_219 ) ?
V_220 : V_221 ;
}
V_87 . V_222 = 0xff ;
V_87 . V_223 = ( V_8 -> V_27 == V_29 ) ;
V_87 . V_224 = 0 ;
V_87 . V_225 = 0xff ;
V_87 . V_226 = 16 ;
V_87 . V_227 = 17 ;
V_87 . V_228 = 19 ;
if ( V_199 == 1 ) {
V_87 . V_229 = 1 ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 1 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0xff ;
} else if ( V_199 == 2 ) {
V_87 . V_229 = 0 ;
V_87 . V_230 = 1 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = 0 ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 1 ;
V_87 . V_235 = 1 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0 ;
} else {
V_87 . V_229 = ( ! V_8 -> V_9 ) ;
V_87 . V_230 = 0 ;
V_87 . V_231 = 0 ;
V_87 . V_232 = ( V_8 -> V_9 ) ;
V_87 . V_233 = 0 ;
V_87 . V_234 = 0 ;
V_87 . V_235 = 0 ;
V_87 . V_236 = 0 ;
V_87 . V_237 = 0 ;
V_87 . V_238 = 0x0 ;
}
V_87 . V_239 = 0xff ;
V_87 . V_240 = V_8 -> V_33 ;
V_87 . V_241 = 0xff ;
V_87 . V_242 = V_8 -> V_35 ;
V_8 -> V_85 = 0 ;
memcpy ( V_53 -> V_68 , & V_87 , sizeof( V_87 ) ) ;
V_53 -> V_69 = sizeof( V_87 ) ;
V_54 = F_15 ( V_53 , V_70 ) ;
if ( V_54 != 0 )
F_11 ( L_48 , V_59 ,
V_54 ) ;
return 0 ;
}
static void F_3 ( struct V_4 * V_5 , int V_199 )
{
struct V_88 * V_21 = V_5 -> V_21 ;
struct V_107 * V_108 ;
const struct V_14 * V_15 ;
V_108 = F_53 ( V_21 ) ;
V_15 = V_108 -> V_17 ;
switch ( V_15 -> V_57 ) {
case V_285 :
F_25 ( V_21 , V_5 , V_199 ) ;
break;
case V_286 :
F_34 ( V_21 , V_5 , V_199 ) ;
break;
case V_287 :
F_38 ( V_21 , V_5 , V_199 ) ;
break;
case V_58 :
F_47 ( V_21 , V_5 , V_199 ) ;
break;
case V_288 :
F_50 ( V_21 , V_5 , V_199 ) ;
break;
}
}
static int F_91 ( struct V_88 * V_21 )
{
int V_72 , V_54 ;
struct V_4 * V_5 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
const struct V_14 * V_15 ;
for ( V_72 = 0 ; ( V_15 = V_289 [ V_72 ] ) != NULL ; ++ V_72 )
if ( V_15 -> V_258 ==
F_61 ( V_21 -> V_111 -> V_121 . V_123 ) )
break;
if ( V_15 == NULL ) {
F_62 ( & V_21 -> V_111 -> V_111 , L_54 ,
V_59 , F_61 ( V_21 -> V_111 -> V_121 . V_123 ) ) ;
return 1 ;
}
V_108 = F_92 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_108 ) {
F_11 ( L_55 ,
V_59 ) ;
return - V_290 ;
}
V_108 -> V_17 = V_15 ;
F_93 ( V_21 , V_108 ) ;
for ( V_72 = 0 ; V_72 < V_21 -> V_90 ; V_72 ++ ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
V_8 = F_92 ( sizeof( struct V_7 ) ,
V_112 ) ;
if ( ! V_8 ) {
F_11 ( L_56 , V_59 , V_72 ) ;
return 1 ;
}
V_8 -> V_17 = V_15 ;
F_94 ( V_5 , V_8 ) ;
}
F_83 ( V_21 ) ;
if ( V_108 -> V_156 != NULL ) {
V_54 = F_15 ( V_108 -> V_156 , V_112 ) ;
if ( V_54 != 0 )
F_11 ( L_57 , V_59 ,
V_54 ) ;
}
if ( V_108 -> V_162 != NULL ) {
V_54 = F_15 ( V_108 -> V_162 , V_112 ) ;
if ( V_54 != 0 )
F_11 ( L_58 , V_59 ,
V_54 ) ;
}
return 0 ;
}
static void F_95 ( struct V_88 * V_21 )
{
int V_72 , V_151 ;
struct V_4 * V_5 ;
struct V_107 * V_108 ;
struct V_7 * V_8 ;
V_108 = F_53 ( V_21 ) ;
F_55 ( V_108 -> V_156 ) ;
F_55 ( V_108 -> V_166 ) ;
F_55 ( V_108 -> V_162 ) ;
for ( V_72 = 0 ; V_72 < V_21 -> V_90 ; ++ V_72 ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
V_8 = F_2 ( V_5 ) ;
F_55 ( V_8 -> V_114 ) ;
F_55 ( V_8 -> V_182 ) ;
for ( V_151 = 0 ; V_151 < 2 ; V_151 ++ ) {
F_55 ( V_8 -> V_95 [ V_151 ] ) ;
F_55 ( V_8 -> V_61 [ V_151 ] ) ;
}
}
F_82 ( V_108 -> V_156 ) ;
F_82 ( V_108 -> V_162 ) ;
F_82 ( V_108 -> V_166 ) ;
for ( V_72 = 0 ; V_72 < V_21 -> V_90 ; ++ V_72 ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
V_8 = F_2 ( V_5 ) ;
F_82 ( V_8 -> V_114 ) ;
F_82 ( V_8 -> V_182 ) ;
for ( V_151 = 0 ; V_151 < 2 ; V_151 ++ ) {
F_82 ( V_8 -> V_95 [ V_151 ] ) ;
F_82 ( V_8 -> V_61 [ V_151 ] ) ;
}
}
}
static void F_96 ( struct V_88 * V_21 )
{
int V_72 ;
struct V_4 * V_5 ;
struct V_107 * V_108 ;
V_108 = F_53 ( V_21 ) ;
F_97 ( V_108 ) ;
for ( V_72 = 0 ; V_72 < V_21 -> V_90 ; V_72 ++ ) {
V_5 = V_21 -> V_5 [ V_72 ] ;
F_97 ( F_2 ( V_5 ) ) ;
}
}
