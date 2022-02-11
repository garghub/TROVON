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
F_18 ( V_33 , L_3 ) ;
return V_1 -> V_4 ;
}
static void F_19 ( struct V_1 * V_1 ,
T_2 * V_34 , int V_35 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
int V_36 ;
T_3 V_37 ;
F_18 ( V_38 , L_4 ,
V_35 , V_39 ) ;
if ( V_35 != V_39 ) {
F_18 ( V_40 , L_5 ) ;
goto V_41;
}
V_37 = ( ( T_3 * ) V_34 ) [ 0 ] ;
if ( V_37 == V_42 ) {
V_21 -> V_26 = V_34 [ 0x0a ] - 1 ;
F_18 ( V_38 , L_6 , V_21 -> V_26 ) ;
F_20 ( V_1 , V_43 ,
V_21 -> V_44 , V_45 ) ;
F_20 ( V_1 , V_46 ,
V_34 + V_47 ,
V_39 - V_47 ) ;
} else if ( V_21 -> V_26 > 0 ) {
F_18 ( V_38 , L_7 ,
V_21 -> V_26 ) ;
V_21 -> V_26 -= 1 ;
if ( V_21 -> V_26 == 0 )
V_36 = V_48 ;
else
V_36 = V_46 ;
F_20 ( V_1 , V_36 ,
V_34 , V_39 ) ;
} else
goto V_41;
return;
V_41:
V_1 -> V_49 = V_50 ;
}
static int F_21 ( struct V_1 * V_1 ,
const struct V_51 * V_52 )
{
struct V_53 * V_53 = & V_1 -> V_53 ;
struct V_21 * V_6 = (struct V_21 * ) V_1 ;
V_6 -> type = V_52 -> V_54 ;
V_6 -> V_55 = V_56 ;
V_53 -> V_57 = V_58 ;
V_53 -> V_59 = F_15 ( V_58 ) ;
V_53 -> V_60 = 1 ;
V_53 -> V_61 = 1 ;
V_53 -> V_62 = V_39 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_1 )
{
int V_19 ;
T_2 * V_63 ;
static T_2 V_64 [] [ 2 ] = {
{ 0x71 , 0x00 } ,
{ 0x70 , 0x09 } ,
{ 0x71 , 0x80 } ,
{ 0x70 , 0x05 }
} ;
for (; ; ) {
F_2 ( V_1 -> V_6 ,
V_1 -> V_65 [ 0 ] -> V_66 ,
V_1 -> V_65 [ 0 ] -> V_67 ,
V_39 , NULL ,
V_68 ) ;
V_19 = 0 ;
V_63 = V_1 -> V_65 [ 0 ] -> V_67 ;
while ( ( V_19 < ( V_39 - 1 ) ) &&
( ( V_63 [ V_19 ] != 0xff ) || ( V_63 [ V_19 + 1 ] != 0xd9 ) ) )
V_19 ++ ;
if ( V_19 != ( V_39 - 1 ) )
break;
}
for ( V_19 = 0 ; V_19 < F_15 ( V_64 ) ; V_19 ++ )
F_1 ( V_1 , V_64 [ V_19 ] ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
return V_1 -> V_4 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_21 * V_6 = (struct V_21 * ) V_1 ;
F_25 ( V_6 -> V_44 , V_1 -> V_69 , V_1 -> V_70 ,
0x21 ) ;
F_26 ( V_6 -> V_44 , V_6 -> V_55 ) ;
F_18 ( V_38 , L_8 ,
V_1 -> V_69 , V_1 -> V_70 ) ;
F_13 ( V_1 ) ;
return V_1 -> V_4 ;
}
static int F_27 ( struct V_71 * V_72 )
{
struct V_1 * V_1 =
F_28 ( V_72 -> V_73 , struct V_1 , V_74 ) ;
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
V_1 -> V_4 = 0 ;
if ( ! V_1 -> V_75 )
return 0 ;
switch ( V_72 -> V_52 ) {
case V_76 :
F_7 ( V_1 , V_72 -> V_8 ) ;
break;
case V_77 :
F_10 ( V_1 , V_72 -> V_8 ) ;
break;
case V_78 :
F_11 ( V_1 , V_72 -> V_8 ) ;
break;
case V_79 :
F_12 ( V_1 , V_72 -> V_8 ) ;
break;
case V_80 :
F_9 ( V_1 , V_72 -> V_8 ) ;
break;
case V_81 :
F_26 ( V_21 -> V_44 , V_72 -> V_8 ) ;
F_8 ( V_1 , V_72 -> V_8 ) ;
break;
}
return V_1 -> V_4 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
struct V_82 * V_83 = & V_1 -> V_74 ;
static const struct V_84 V_85 = {
. V_86 = & V_87 ,
. V_52 = V_80 ,
. type = V_88 ,
. V_89 = L_9 ,
. V_90 = 3 ,
. V_91 = 1 ,
. V_92 = 0 ,
} ;
V_1 -> V_93 . V_74 = V_83 ;
F_30 ( V_83 , 6 ) ;
V_21 -> V_32 = F_31 ( V_83 , & V_87 ,
V_76 ,
V_94 , 1 ,
V_94 ) ;
F_32 ( V_83 , & V_85 , NULL ) ;
F_33 ( V_83 , & V_87 ,
V_77 , 0 , 3 , 1 , 2 ) ;
F_33 ( V_83 , & V_87 ,
V_78 , 0 , 3 , 1 , 2 ) ;
F_33 ( V_83 , & V_87 ,
V_79 , 0 , 3 , 1 , 2 ) ;
V_21 -> V_31 = F_33 ( V_83 , & V_87 ,
V_81 ,
V_14 , V_12 , 1 , V_56 ) ;
if ( V_83 -> error ) {
F_4 ( L_10 ) ;
return V_83 -> error ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 ,
const struct V_95 * V_96 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
F_35 ( V_21 -> V_31 , V_96 -> V_55 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 ,
struct V_95 * V_96 )
{
struct V_21 * V_21 = (struct V_21 * ) V_1 ;
memset ( V_96 , 0 , sizeof *V_96 ) ;
V_96 -> V_55 = F_17 ( V_21 -> V_31 ) ;
V_96 -> V_97 = V_98
| V_99 ;
return 0 ;
}
static int F_37 ( struct V_100 * V_101 ,
const struct V_51 * V_52 )
{
return F_38 ( V_101 , V_52 ,
V_102 [ V_52 -> V_54 ] ,
sizeof( struct V_21 ) ,
V_103 ) ;
}
