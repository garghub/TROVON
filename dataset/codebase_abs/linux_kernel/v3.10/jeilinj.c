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
static void F_5 ( struct V_1 * V_1 , unsigned char * V_7 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
V_3 = F_2 ( V_1 -> V_6 ,
F_6 ( V_1 -> V_6 , 0x84 ) ,
V_1 -> V_5 , 1 , NULL , 500 ) ;
* V_7 = V_1 -> V_5 [ 0 ] ;
if ( V_3 < 0 ) {
F_4 ( L_2 ,
V_1 -> V_5 [ 0 ] , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static void F_7 ( struct V_1 * V_1 , T_1 V_8 )
{
T_2 V_9 [] [ 2 ] = {
{ 0x71 , 0x80 } ,
{ 0x70 , 0x07 }
} ;
V_9 [ 0 ] [ 1 ] |= V_8 >> 1 ;
F_1 ( V_1 , V_9 [ 0 ] ) ;
F_1 ( V_1 , V_9 [ 1 ] ) ;
}
static void F_8 ( struct V_1 * V_1 , T_1 V_8 )
{
T_2 V_10 [] [ 2 ] = {
{ 0x71 , 0x1E } ,
{ 0x70 , 0x06 }
} ;
T_2 V_11 ;
V_11 = ( ( V_12 - V_8 ) * V_13 )
/ ( V_12 - V_14 ) ;
V_10 [ 0 ] [ 1 ] += V_11 ;
F_1 ( V_1 , V_10 [ 0 ] ) ;
F_1 ( V_1 , V_10 [ 1 ] ) ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_8 )
{
T_2 V_15 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xcf , 0x00 }
} ;
V_15 [ 1 ] [ 1 ] = V_8 << 4 ;
F_1 ( V_1 , V_15 [ 0 ] ) ;
F_1 ( V_1 , V_15 [ 1 ] ) ;
}
static void F_10 ( struct V_1 * V_1 , T_1 V_8 )
{
T_2 V_16 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xe6 , 0x00 }
} ;
V_16 [ 1 ] [ 1 ] = V_8 ;
F_1 ( V_1 , V_16 [ 0 ] ) ;
F_1 ( V_1 , V_16 [ 1 ] ) ;
}
static void F_11 ( struct V_1 * V_1 , T_1 V_8 )
{
T_2 V_17 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xe7 , 0x00 }
} ;
V_17 [ 1 ] [ 1 ] = V_8 ;
F_1 ( V_1 , V_17 [ 0 ] ) ;
F_1 ( V_1 , V_17 [ 1 ] ) ;
}
static void F_12 ( struct V_1 * V_1 , T_1 V_8 )
{
T_2 V_18 [] [ 2 ] = {
{ 0x94 , 0x02 } ,
{ 0xe9 , 0x00 }
} ;
V_18 [ 1 ] [ 1 ] = V_8 ;
F_1 ( V_1 , V_18 [ 0 ] ) ;
F_1 ( V_1 , V_18 [ 1 ] ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
int V_19 ;
int V_20 ;
T_2 V_7 = 0xff ;
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
struct V_22 V_23 [] = {
{ { 0x71 , 0x81 } , 0 , 0 } ,
{ { 0x70 , 0x05 } , 0 , V_24 } ,
{ { 0x95 , 0x70 } , 1 , 0 } ,
{ { 0x71 , 0x81 - V_1 -> V_25 } , 0 , 0 } ,
{ { 0x70 , 0x04 } , 0 , V_24 } ,
{ { 0x95 , 0x70 } , 1 , 0 } ,
{ { 0x71 , 0x00 } , 0 , 0 } ,
{ { 0x70 , 0x08 } , 0 , V_24 } ,
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
V_21 -> V_26 = 0 ;
if ( V_21 -> type == V_27 )
V_20 = F_14 ;
else
V_20 = F_15 ( V_23 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
F_1 ( V_1 , V_23 [ V_19 ] . V_28 ) ;
if ( V_23 [ V_19 ] . V_29 )
F_16 ( V_23 [ V_19 ] . V_29 ) ;
if ( V_23 [ V_19 ] . V_30 )
F_5 ( V_1 , & V_7 ) ;
}
F_8 ( V_1 , F_17 ( V_21 -> V_31 ) ) ;
F_16 ( 2 ) ;
F_7 ( V_1 , F_17 ( V_21 -> V_32 ) ) ;
if ( V_1 -> V_4 < 0 )
F_18 ( L_3 ) ;
return V_1 -> V_4 ;
}
static void F_19 ( struct V_1 * V_1 ,
T_2 * V_33 , int V_34 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
int V_35 ;
T_3 V_36 ;
F_20 ( V_37 , L_4 ,
V_34 , V_38 ) ;
if ( V_34 != V_38 ) {
F_20 ( V_39 , L_5 ) ;
goto V_40;
}
V_36 = ( ( T_3 * ) V_33 ) [ 0 ] ;
if ( V_36 == V_41 ) {
V_21 -> V_26 = V_33 [ 0x0a ] - 1 ;
F_20 ( V_37 , L_6 , V_21 -> V_26 ) ;
F_21 ( V_1 , V_42 ,
V_21 -> V_43 , V_44 ) ;
F_21 ( V_1 , V_45 ,
V_33 + V_46 ,
V_38 - V_46 ) ;
} else if ( V_21 -> V_26 > 0 ) {
F_20 ( V_37 , L_7 ,
V_21 -> V_26 ) ;
V_21 -> V_26 -= 1 ;
if ( V_21 -> V_26 == 0 )
V_35 = V_47 ;
else
V_35 = V_45 ;
F_21 ( V_1 , V_35 ,
V_33 , V_38 ) ;
} else
goto V_40;
return;
V_40:
V_1 -> V_48 = V_49 ;
}
static int F_22 ( struct V_1 * V_1 ,
const struct V_50 * V_51 )
{
struct V_52 * V_52 = & V_1 -> V_52 ;
struct V_21 * V_6 = (struct V_21 * ) V_1 ;
V_6 -> type = V_51 -> V_53 ;
V_6 -> V_54 = V_55 ;
V_52 -> V_56 = V_57 ;
V_52 -> V_58 = F_15 ( V_57 ) ;
V_52 -> V_59 = 1 ;
V_52 -> V_60 = 1 ;
V_52 -> V_61 = V_38 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_1 )
{
int V_19 ;
T_2 * V_62 ;
static T_2 V_63 [] [ 2 ] = {
{ 0x71 , 0x00 } ,
{ 0x70 , 0x09 } ,
{ 0x71 , 0x80 } ,
{ 0x70 , 0x05 }
} ;
for (; ; ) {
F_2 ( V_1 -> V_6 ,
V_1 -> V_64 [ 0 ] -> V_65 ,
V_1 -> V_64 [ 0 ] -> V_66 ,
V_38 , NULL ,
V_67 ) ;
V_19 = 0 ;
V_62 = V_1 -> V_64 [ 0 ] -> V_66 ;
while ( ( V_19 < ( V_38 - 1 ) ) &&
( ( V_62 [ V_19 ] != 0xff ) || ( V_62 [ V_19 + 1 ] != 0xd9 ) ) )
V_19 ++ ;
if ( V_19 != ( V_38 - 1 ) )
break;
}
for ( V_19 = 0 ; V_19 < F_15 ( V_63 ) ; V_19 ++ )
F_1 ( V_1 , V_63 [ V_19 ] ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
return V_1 -> V_4 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_21 * V_6 = (struct V_21 * ) V_1 ;
F_26 ( V_6 -> V_43 , V_1 -> V_68 , V_1 -> V_69 ,
0x21 ) ;
F_27 ( V_6 -> V_43 , V_6 -> V_54 ) ;
F_20 ( V_37 , L_8 ,
V_1 -> V_68 , V_1 -> V_69 ) ;
F_13 ( V_1 ) ;
return V_1 -> V_4 ;
}
static int F_28 ( struct V_70 * V_71 )
{
struct V_1 * V_1 =
F_29 ( V_71 -> V_72 , struct V_1 , V_73 ) ;
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
V_1 -> V_4 = 0 ;
if ( ! V_1 -> V_74 )
return 0 ;
switch ( V_71 -> V_51 ) {
case V_75 :
F_7 ( V_1 , V_71 -> V_8 ) ;
break;
case V_76 :
F_10 ( V_1 , V_71 -> V_8 ) ;
break;
case V_77 :
F_11 ( V_1 , V_71 -> V_8 ) ;
break;
case V_78 :
F_12 ( V_1 , V_71 -> V_8 ) ;
break;
case V_79 :
F_9 ( V_1 , V_71 -> V_8 ) ;
break;
case V_80 :
F_27 ( V_21 -> V_43 , V_71 -> V_8 ) ;
F_8 ( V_1 , V_71 -> V_8 ) ;
break;
}
return V_1 -> V_4 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
struct V_81 * V_82 = & V_1 -> V_73 ;
static const struct V_83 V_84 = {
. V_85 = & V_86 ,
. V_51 = V_79 ,
. type = V_87 ,
. V_88 = L_9 ,
. V_89 = 3 ,
. V_90 = 1 ,
. V_91 = 0 ,
} ;
V_1 -> V_92 . V_73 = V_82 ;
F_31 ( V_82 , 6 ) ;
V_21 -> V_32 = F_32 ( V_82 , & V_86 ,
V_75 ,
V_93 , 1 ,
V_93 ) ;
F_33 ( V_82 , & V_84 , NULL ) ;
F_34 ( V_82 , & V_86 ,
V_76 , 0 , 3 , 1 , 2 ) ;
F_34 ( V_82 , & V_86 ,
V_77 , 0 , 3 , 1 , 2 ) ;
F_34 ( V_82 , & V_86 ,
V_78 , 0 , 3 , 1 , 2 ) ;
V_21 -> V_31 = F_34 ( V_82 , & V_86 ,
V_80 ,
V_14 , V_12 , 1 , V_55 ) ;
if ( V_82 -> error ) {
F_4 ( L_10 ) ;
return V_82 -> error ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 ,
const struct V_94 * V_95 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
F_36 ( V_21 -> V_31 , V_95 -> V_54 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 ,
struct V_94 * V_95 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
memset ( V_95 , 0 , sizeof *V_95 ) ;
V_95 -> V_54 = F_17 ( V_21 -> V_31 ) ;
V_95 -> V_96 = V_97
| V_98 ;
return 0 ;
}
static int F_38 ( struct V_99 * V_100 ,
const struct V_50 * V_51 )
{
return F_39 ( V_100 , V_51 ,
V_101 [ V_51 -> V_53 ] ,
sizeof( struct V_21 ) ,
V_102 ) ;
}
