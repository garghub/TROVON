static void F_1 ( struct V_1 * V_1 , unsigned char * V_2 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
memcpy ( V_1 -> V_5 , V_2 , 2 ) ;
V_3 = F_2 ( V_1 -> V_6 ,
F_3 ( V_1 -> V_6 , 3 ) ,
V_1 -> V_5 , 2 , NULL , 500 ) ;
if ( V_3 < 0 ) {
F_4 ( L_1 ,
V_1 -> V_5 [ 0 ] , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static void F_5 ( struct V_1 * V_1 , unsigned char V_7 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
V_3 = F_2 ( V_1 -> V_6 ,
F_6 ( V_1 -> V_6 , 0x84 ) ,
V_1 -> V_5 , 1 , NULL , 500 ) ;
V_7 = V_1 -> V_5 [ 0 ] ;
if ( V_3 < 0 ) {
F_4 ( L_2 ,
V_1 -> V_5 [ 0 ] , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
T_1 V_9 [] [ 2 ] = {
{ 0x71 , 0x80 } ,
{ 0x70 , 0x07 }
} ;
V_9 [ 0 ] [ 1 ] |= ( V_8 -> V_10 [ V_11 ] . V_12 >> 1 ) ;
F_1 ( V_1 , V_9 [ 0 ] ) ;
F_1 ( V_1 , V_9 [ 1 ] ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
T_1 V_13 [] [ 2 ] = {
{ 0x71 , 0x1E } ,
{ 0x70 , 0x06 }
} ;
T_1 V_14 ;
V_14 = ( ( V_15 - V_8 -> V_16 ) * V_17 )
/ ( V_15 - V_18 ) ;
V_13 [ 0 ] [ 1 ] += V_14 ;
F_1 ( V_1 , V_13 [ 0 ] ) ;
F_1 ( V_1 , V_13 [ 1 ] ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
T_1 V_19 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xcf , 0x00 }
} ;
V_19 [ 1 ] [ 1 ] = ( V_8 -> V_10 [ V_20 ] . V_12 << 4 ) ;
F_1 ( V_1 , V_19 [ 0 ] ) ;
F_1 ( V_1 , V_19 [ 1 ] ) ;
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
T_1 V_21 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xe6 , 0x00 }
} ;
V_21 [ 1 ] [ 1 ] = V_8 -> V_10 [ V_22 ] . V_12 ;
F_1 ( V_1 , V_21 [ 0 ] ) ;
F_1 ( V_1 , V_21 [ 1 ] ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
T_1 V_23 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xe7 , 0x00 }
} ;
V_23 [ 1 ] [ 1 ] = V_8 -> V_10 [ V_24 ] . V_12 ;
F_1 ( V_1 , V_23 [ 0 ] ) ;
F_1 ( V_1 , V_23 [ 1 ] ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
T_1 V_25 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xe9 , 0x00 }
} ;
V_25 [ 1 ] [ 1 ] = V_8 -> V_10 [ V_26 ] . V_12 ;
F_1 ( V_1 , V_25 [ 0 ] ) ;
F_1 ( V_1 , V_25 [ 1 ] ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
int V_27 ;
int V_28 ;
T_1 V_7 = 0xff ;
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
struct V_29 V_30 [] = {
{ { 0x71 , 0x81 } , 0 , 0 } ,
{ { 0x70 , 0x05 } , 0 , V_31 } ,
{ { 0x95 , 0x70 } , 1 , 0 } ,
{ { 0x71 , 0x81 - V_1 -> V_32 } , 0 , 0 } ,
{ { 0x70 , 0x04 } , 0 , V_31 } ,
{ { 0x95 , 0x70 } , 1 , 0 } ,
{ { 0x71 , 0x00 } , 0 , 0 } ,
{ { 0x70 , 0x08 } , 0 , V_31 } ,
{ { 0x95 , 0x70 } , 1 , 0 } ,
#define F_14 9
{ { 0x94 , 0x02 } , 0 , 0 } ,
{ { 0xde , 0x24 } , 0 , 0 } ,
{ { 0x94 , 0x02 } , 0 , 0 } ,
{ { 0xdd , 0xf0 } , 0 , 0 } ,
{ { 0x94 , 0x02 } , 0 , 0 } ,
{ { 0xe3 , 0x2c } , 0 , 0 } ,
{ { 0x94 , 0x02 } , 0 , 0 } ,
{ { 0xe4 , 0x00 } , 0 , 0 } ,
{ { 0x94 , 0x02 } , 0 , 0 } ,
{ { 0xe5 , 0x00 } , 0 , 0 } ,
{ { 0x94 , 0x02 } , 0 , 0 } ,
{ { 0xe6 , 0x2c } , 0 , 0 } ,
{ { 0x94 , 0x03 } , 0 , 0 } ,
{ { 0xaa , 0x00 } , 0 , 0 }
} ;
V_8 -> V_33 = 0 ;
if ( V_8 -> type == V_34 )
V_28 = F_14 ;
else
V_28 = F_15 ( V_30 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_1 ( V_1 , V_30 [ V_27 ] . V_35 ) ;
if ( V_30 [ V_27 ] . V_36 )
F_16 ( V_30 [ V_27 ] . V_36 ) ;
if ( V_30 [ V_27 ] . V_37 )
F_5 ( V_1 , V_7 ) ;
}
F_8 ( V_1 ) ;
F_16 ( 2 ) ;
F_7 ( V_1 ) ;
if ( V_1 -> V_4 < 0 )
F_17 ( V_38 , L_3 ) ;
return V_1 -> V_4 ;
}
static void F_18 ( struct V_1 * V_1 ,
T_1 * V_39 , int V_40 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
int V_41 ;
T_2 V_42 ;
F_17 ( V_43 , L_4 ,
V_40 , V_44 ) ;
if ( V_40 != V_44 ) {
F_17 ( V_45 , L_5 ) ;
goto V_46;
}
V_42 = ( ( T_2 * ) V_39 ) [ 0 ] ;
if ( V_42 == V_47 ) {
V_8 -> V_33 = V_39 [ 0x0a ] - 1 ;
F_17 ( V_43 , L_6 , V_8 -> V_33 ) ;
F_19 ( V_1 , V_48 ,
V_8 -> V_49 , V_50 ) ;
F_19 ( V_1 , V_51 ,
V_39 + V_52 ,
V_44 - V_52 ) ;
} else if ( V_8 -> V_33 > 0 ) {
F_17 ( V_43 , L_7 ,
V_8 -> V_33 ) ;
V_8 -> V_33 -= 1 ;
if ( V_8 -> V_33 == 0 )
V_41 = V_53 ;
else
V_41 = V_51 ;
F_19 ( V_1 , V_41 ,
V_39 , V_44 ) ;
} else
goto V_46;
return;
V_46:
V_1 -> V_54 = V_55 ;
}
static int F_20 ( struct V_1 * V_1 ,
const struct V_56 * V_57 )
{
struct V_58 * V_58 = & V_1 -> V_58 ;
struct V_8 * V_6 = (struct V_8 * ) V_1 ;
V_6 -> type = V_57 -> V_59 ;
V_1 -> V_58 . V_10 = V_6 -> V_10 ;
V_6 -> V_16 = V_60 ;
V_58 -> V_61 = V_62 ;
V_58 -> V_63 = F_15 ( V_62 ) ;
V_58 -> V_64 = 1 ;
V_58 -> V_65 = 1 ;
V_58 -> V_66 = V_44 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
int V_27 ;
T_1 * V_67 ;
static T_1 V_68 [] [ 2 ] = {
{ 0x71 , 0x00 } ,
{ 0x70 , 0x09 } ,
{ 0x71 , 0x80 } ,
{ 0x70 , 0x05 }
} ;
for (; ; ) {
F_2 ( V_1 -> V_6 ,
V_1 -> V_69 [ 0 ] -> V_70 ,
V_1 -> V_69 [ 0 ] -> V_71 ,
V_44 , NULL ,
V_72 ) ;
V_27 = 0 ;
V_67 = V_1 -> V_69 [ 0 ] -> V_71 ;
while ( ( V_27 < ( V_44 - 1 ) ) &&
( ( V_67 [ V_27 ] != 0xff ) || ( V_67 [ V_27 + 1 ] != 0xd9 ) ) )
V_27 ++ ;
if ( V_27 != ( V_44 - 1 ) )
break;
}
for ( V_27 = 0 ; V_27 < F_15 ( V_68 ) ; V_27 ++ )
F_1 ( V_1 , V_68 [ V_27 ] ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
return V_1 -> V_4 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_8 * V_6 = (struct V_8 * ) V_1 ;
F_24 ( V_6 -> V_49 , V_1 -> V_73 , V_1 -> V_74 ,
0x21 ) ;
F_25 ( V_6 -> V_49 , V_6 -> V_16 ) ;
F_17 ( V_43 , L_8 ,
V_1 -> V_73 , V_1 -> V_74 ) ;
F_13 ( V_1 ) ;
return V_1 -> V_4 ;
}
static int F_26 ( struct V_1 * V_1 ,
struct V_75 * V_76 )
{
switch ( V_76 -> V_57 ) {
case V_77 :
switch ( V_76 -> V_78 ) {
case 0 :
strcpy ( ( char * ) V_76 -> V_79 , L_9 ) ;
return 0 ;
case 1 :
strcpy ( ( char * ) V_76 -> V_79 , L_10 ) ;
return 0 ;
case 2 :
strcpy ( ( char * ) V_76 -> V_79 , L_11 ) ;
return 0 ;
}
break;
}
return - V_80 ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_81 * V_82 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
if ( V_82 -> V_16 < V_18 )
V_8 -> V_16 = V_18 ;
else if ( V_82 -> V_16 > V_15 )
V_8 -> V_16 = V_15 ;
else
V_8 -> V_16 = V_82 -> V_16 ;
if ( V_1 -> V_83 ) {
F_25 ( V_8 -> V_49 , V_8 -> V_16 ) ;
F_8 ( V_1 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 ,
struct V_81 * V_82 )
{
struct V_8 * V_8 = (struct V_8 * ) V_1 ;
memset ( V_82 , 0 , sizeof *V_82 ) ;
V_82 -> V_16 = V_8 -> V_16 ;
V_82 -> V_84 = V_85
| V_86 ;
return 0 ;
}
static int F_29 ( struct V_87 * V_88 ,
const struct V_56 * V_57 )
{
return F_30 ( V_88 , V_57 ,
V_89 [ V_57 -> V_59 ] ,
sizeof( struct V_8 ) ,
V_90 ) ;
}
