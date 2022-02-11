static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
unsigned long V_6 = V_7 + F_2 ( V_8 ) ;
int V_9 ;
T_1 V_10 [ 6 ] ;
if ( V_5 < 1 || V_5 > 4 )
return - V_11 ;
F_3 ( V_5 < 1 || V_5 > 4 ) ;
V_10 [ 5 ] = 0x80 + V_5 - 1 ;
V_10 [ 4 ] = V_3 ;
V_10 [ 3 ] = V_4 [ 0 ] ;
if ( V_5 > 1 )
V_10 [ 2 ] = V_4 [ 1 ] ;
if ( V_5 > 2 )
V_10 [ 1 ] = V_4 [ 2 ] ;
if ( V_5 > 3 )
V_10 [ 0 ] = V_4 [ 3 ] ;
V_9 = V_2 -> V_12 ( V_2 , 4 - V_5 , & V_10 [ 4 - V_5 ] , 2 + V_5 ) ;
if ( V_9 != 2 + V_5 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_1 ,
V_3 , V_9 ) ;
return ( V_9 < 0 ) ? V_9 : - V_14 ;
}
while ( F_5 ( V_6 ) ) {
V_9 = V_2 -> V_15 ( V_2 , 0x05 ) ;
if ( V_9 == 0x80 + V_5 - 1 )
return V_5 ;
if ( V_9 == 0x94 + V_5 - 1 ) {
F_6 ( 1 , L_2 , V_9 ) ;
return - V_16 ;
}
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_3 ,
V_9 ) ;
return V_9 ;
}
F_7 ( 5 ) ;
}
F_6 ( 0 , L_4 , V_3 ) ;
return - V_17 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
unsigned long V_6 = V_7 + F_2 ( V_8 ) ;
T_1 V_18 [ 4 ] ;
int V_9 ;
int V_19 ;
if ( V_5 < 1 || V_5 > 4 )
return - V_11 ;
V_18 [ 1 ] = 0x84 + V_5 - 1 ;
V_18 [ 0 ] = V_3 ;
V_9 = V_2 -> V_12 ( V_2 , 0x04 , V_18 , 2 ) ;
if ( V_9 != 2 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_5 ,
V_3 , V_9 ) ;
return ( V_9 < 0 ) ? V_9 : - V_14 ;
}
while ( F_5 ( V_6 ) ) {
V_9 = V_2 -> V_15 ( V_2 , 0x05 ) ;
if ( V_9 == 0x84 + V_5 - 1 )
break;
if ( V_9 == 0x94 + V_5 - 1 ) {
F_6 ( 1 , L_2 ,
V_9 ) ;
return - V_16 ;
}
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_3 ,
V_9 ) ;
return V_9 ;
}
F_7 ( 5 ) ;
}
if ( V_9 != 0x84 + V_5 - 1 ) {
F_6 ( 0 , L_6 , V_3 ) ;
}
V_9 = V_2 -> V_20 ( V_2 , 0x00 , 4 - V_5 , V_18 , V_5 ) ;
if ( V_9 != V_5 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_7 ,
V_3 , V_9 ) ;
return ( V_9 < 0 ) ? V_9 : - V_14 ;
}
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_4 [ V_19 ] = V_18 [ V_5 - 1 - V_19 ] ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_9 ;
V_9 = F_8 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_9 == 1 )
return 0 ;
return ( V_9 < 0 ) ? V_9 : - V_14 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 , int V_21 )
{
unsigned long V_6 = V_7 + F_2 ( V_8 ) ;
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_22 ( V_2 , V_21 ? 2 : 3 , V_3 , V_4 , V_5 ) ;
if ( V_9 != V_5 ) {
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_8 ,
V_3 , V_9 ) ;
return V_9 ;
} else {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_9 ,
V_5 , V_3 , V_9 ) ;
return - V_14 ;
}
}
while ( F_5 ( V_6 ) ) {
V_9 = V_2 -> V_15 ( V_2 , 0x05 ) ;
if ( V_9 == 0 )
return V_5 ;
if ( V_9 == 0x10 ) {
F_6 ( 1 , L_10 ,
V_3 ) ;
return - V_16 ;
}
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_3 ,
V_9 ) ;
return V_9 ;
}
F_7 ( 5 ) ;
}
if ( V_9 == 0x02 || V_9 == 0x04 ) {
F_6 ( 0 ,
L_11 ,
V_3 , V_9 ) ;
return - V_17 ;
}
F_4 ( & V_2 -> V_13 -> V_2 ,
L_12 ,
V_3 , V_9 ) ;
return - V_14 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_2 V_5 )
{
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_20 ( V_2 , 2 , V_3 , V_4 , V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_13 ,
V_3 , V_9 ) ;
return V_9 ;
}
V_9 = V_2 -> V_15 ( V_2 , 0x05 ) ;
if ( V_9 == 0 )
return V_5 ;
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_3 ,
V_9 ) ;
return V_9 ;
}
if ( V_9 == 0x10 ) {
F_6 ( 1 , L_10 ,
V_3 ) ;
return - V_16 ;
}
if ( V_9 == 0x02 || V_9 == 0x04 ) {
F_6 ( 0 ,
L_11 ,
V_3 , V_9 ) ;
return - V_17 ;
}
F_4 ( & V_2 -> V_13 -> V_2 ,
L_12 ,
V_3 , V_9 ) ;
return - V_14 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_9 ;
T_1 V_4 ;
V_9 = F_11 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_9 == 1 )
return 0 ;
return ( V_9 < 0 ) ? V_9 : - V_14 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 )
{
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_22 ( V_2 , 0x06 , V_3 , V_4 , V_5 ) ;
if ( V_9 != V_5 ) {
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_8 ,
V_3 , V_9 ) ;
return V_9 ;
} else {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_9 ,
V_5 , V_3 , V_9 ) ;
return - V_14 ;
}
}
V_9 = V_2 -> V_23 ( V_2 , 0x08 , 0x0000 ) ;
if ( ! V_9 )
return V_5 ;
else if ( V_9 > 0 ) {
F_6 ( 1 , L_14 , V_9 ) ;
return - V_16 ;
}
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 )
{
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_20 ( V_2 , 0x06 , V_3 , V_4 , V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_13 -> V_2 ,
L_13 ,
V_3 , V_9 ) ;
return V_9 ;
}
V_9 = V_2 -> V_23 ( V_2 , 0x08 , 0x0000 ) ;
if ( ! V_9 )
return V_5 ;
else if ( V_9 > 0 ) {
F_6 ( 1 , L_14 , V_9 ) ;
return - V_16 ;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
int V_9 ;
V_9 = F_14 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static inline int F_16 ( struct V_24 * V_25 , T_2 V_3 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_26 = - V_11 ;
if ( V_25 -> V_27 == V_28 )
V_26 = F_12 ( V_2 , V_3 ) ;
else if ( V_25 -> V_27 == V_29 )
V_26 = F_9 ( V_2 , V_3 ) ;
else if ( V_25 -> V_27 == V_30 )
V_26 = F_15 ( V_2 , V_3 ) ;
return V_26 ;
}
static inline int F_17 ( struct V_24 * V_25 ,
struct V_31 V_32 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_3 = V_32 . V_3 << 1 ;
int V_26 = - V_11 ;
if ( V_25 -> V_27 == V_28 )
V_26 = F_11 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
else if ( V_25 -> V_27 == V_29 )
V_26 = F_8 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
else if ( V_25 -> V_27 == V_30 )
V_26 = F_14 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
return V_26 ;
}
static inline int F_18 ( struct V_24 * V_25 ,
struct V_31 V_32 , int V_21 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_3 = V_32 . V_3 << 1 ;
int V_26 = - V_11 ;
if ( V_25 -> V_27 == V_28 )
V_26 = F_10 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 , V_21 ) ;
else if ( V_25 -> V_27 == V_29 )
V_26 = F_1 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
else if ( V_25 -> V_27 == V_30 )
V_26 = F_13 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
return V_26 ;
}
static int F_19 ( struct V_33 * V_34 ,
struct V_31 V_35 [] , int V_36 )
{
struct V_24 * V_25 = V_34 -> V_37 ;
struct V_1 * V_2 = V_25 -> V_2 ;
unsigned V_38 = V_25 -> V_38 ;
int V_3 , V_26 , V_19 ;
T_1 V_39 ;
if ( V_2 -> V_40 )
return - V_41 ;
if ( ! F_20 ( & V_2 -> V_42 ) )
return - V_43 ;
if ( V_38 != V_2 -> V_44 &&
V_25 -> V_27 == V_28 ) {
if ( V_38 == 1 )
V_39 = V_45 ;
else
V_39 = 0 ;
F_21 ( V_2 , V_46 , V_39 ,
V_45 ) ;
V_2 -> V_44 = V_38 ;
}
if ( V_36 <= 0 ) {
F_22 ( & V_2 -> V_42 ) ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_36 ; V_19 ++ ) {
V_3 = V_35 [ V_19 ] . V_3 << 1 ;
if ( ! V_35 [ V_19 ] . V_5 ) {
V_26 = F_16 ( V_25 , V_3 ) ;
if ( V_26 == - V_16 )
V_26 = - V_41 ;
} else if ( V_35 [ V_19 ] . V_47 & V_48 ) {
V_26 = F_17 ( V_25 , V_35 [ V_19 ] ) ;
} else {
V_26 = F_18 ( V_25 , V_35 [ V_19 ] , V_19 == V_36 - 1 ) ;
}
if ( V_26 < 0 )
goto error;
F_6 ( 2 , L_15 ,
( V_35 [ V_19 ] . V_47 & V_48 ) ? L_16 : L_17 ,
V_19 == V_36 - 1 ? L_18 : L_19 ,
V_3 , V_35 [ V_19 ] . V_5 ,
V_35 [ V_19 ] . V_5 , V_35 [ V_19 ] . V_4 ) ;
}
F_22 ( & V_2 -> V_42 ) ;
return V_36 ;
error:
F_6 ( 2 , L_20 ,
( V_35 [ V_19 ] . V_47 & V_48 ) ? L_16 : L_17 ,
V_19 == V_36 - 1 ? L_18 : L_19 ,
V_3 , V_35 [ V_19 ] . V_5 ,
( V_26 == - V_41 ) ? L_21 : L_22 ,
V_26 ) ;
F_22 ( & V_2 -> V_42 ) ;
return V_26 ;
}
static inline unsigned long F_23 ( char * V_4 , int V_49 , int V_50 )
{
unsigned long V_51 = 0 ;
unsigned long V_52 = 0 ;
int V_5 = 0 ;
unsigned char V_53 ;
do {
if ( V_5 == V_49 ) {
V_53 = ( char ) V_5 ;
V_5 = - 1 ;
} else
V_53 = * V_4 ++ ;
V_52 = ( V_52 << 8 ) | V_53 ;
V_5 ++ ;
if ( ( V_5 & ( 32 / 8 - 1 ) ) == 0 )
V_51 = ( ( V_51 ^ V_52 ) * 0x9e370001UL ) ;
} while ( V_5 );
return ( V_51 >> ( 32 - V_50 ) ) & 0xffffffffUL ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_38 , T_2 V_3 ,
bool V_54 , T_2 V_5 , T_1 * V_55 )
{
int V_56 = V_5 , V_57 , V_58 , V_9 ;
T_1 V_4 [ 2 ] ;
if ( V_3 + V_56 > ( V_54 * 0xff00 + 0xff + 1 ) )
return - V_59 ;
V_4 [ 0 ] = V_3 >> 8 ;
V_4 [ 1 ] = V_3 & 0xff ;
V_9 = F_25 ( & V_2 -> V_60 [ V_38 ] , V_4 + ! V_54 , 1 + V_54 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_2 -> V_61 . V_62 )
V_58 = 4 ;
else
V_58 = 64 ;
while ( V_56 > 0 ) {
if ( V_56 > V_58 )
V_57 = V_58 ;
else
V_57 = V_56 ;
V_9 = F_26 ( & V_2 -> V_60 [ V_38 ] , V_55 , V_57 ) ;
if ( V_9 < 0 )
return V_9 ;
V_56 -= V_57 ;
V_55 += V_57 ;
}
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned V_38 ,
T_1 * * V_63 , T_2 * V_64 )
{
const T_2 V_5 = 256 ;
int V_65 ;
struct V_66 * V_67 ;
T_1 V_4 , * V_55 ;
* V_63 = NULL ;
* V_64 = 0 ;
V_2 -> V_60 [ V_38 ] . V_3 = 0xa0 >> 1 ;
V_65 = F_26 ( & V_2 -> V_60 [ V_38 ] , & V_4 , 0 ) ;
if ( V_65 < 0 ) {
F_28 ( & V_2 -> V_13 -> V_2 , L_23 ) ;
return - V_41 ;
}
V_55 = F_29 ( V_5 , V_68 ) ;
if ( V_55 == NULL )
return - V_69 ;
V_65 = F_24 ( V_2 , V_38 , 0x0000 ,
V_2 -> V_70 ,
V_5 , V_55 ) ;
if ( V_65 != V_5 ) {
F_30 ( & V_2 -> V_13 -> V_2 ,
L_24 , V_65 ) ;
goto error;
}
if ( V_71 ) {
F_31 ( V_72 , L_25 , V_73 ,
16 , 1 , V_55 , V_5 , true ) ;
if ( V_2 -> V_70 )
F_28 ( & V_2 -> V_13 -> V_2 ,
L_26 , 256 ) ;
}
if ( V_2 -> V_70 &&
V_55 [ 0 ] == 0x26 && V_55 [ 3 ] == 0x00 ) {
T_2 V_74 ;
T_2 V_75 ;
V_2 -> V_51 = F_23 ( V_55 , V_5 , 32 ) ;
V_74 = ( V_55 [ 1 ] << 8 ) + 4 ;
F_28 ( & V_2 -> V_13 -> V_2 ,
L_27 ,
V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] , V_55 [ 3 ] , V_2 -> V_51 ) ;
F_28 ( & V_2 -> V_13 -> V_2 ,
L_28 ) ;
F_28 ( & V_2 -> V_13 -> V_2 ,
L_29 ,
V_74 , V_55 [ 2 ] ) ;
V_65 = F_24 ( V_2 , V_38 , V_74 + 46 , 1 , 2 ,
V_55 ) ;
if ( V_65 != 2 ) {
F_30 ( & V_2 -> V_13 -> V_2 ,
L_30 ,
V_65 ) ;
goto error;
}
V_75 = V_74 + V_55 [ 0 ] + ( V_55 [ 1 ] << 8 ) ;
V_65 = F_24 ( V_2 , V_38 , V_75 , 1 , V_5 ,
V_55 ) ;
if ( V_65 != V_5 ) {
F_30 ( & V_2 -> V_13 -> V_2 ,
L_30 ,
V_65 ) ;
goto error;
}
if ( V_55 [ 0 ] != 0x1a || V_55 [ 1 ] != 0xeb ||
V_55 [ 2 ] != 0x67 || V_55 [ 3 ] != 0x95 ) {
F_28 ( & V_2 -> V_13 -> V_2 ,
L_31 ) ;
F_32 ( V_55 ) ;
return 0 ;
}
} else if ( ! V_2 -> V_70 &&
V_55 [ 0 ] == 0x1a && V_55 [ 1 ] == 0xeb &&
V_55 [ 2 ] == 0x67 && V_55 [ 3 ] == 0x95 ) {
V_2 -> V_51 = F_23 ( V_55 , V_5 , 32 ) ;
F_28 ( & V_2 -> V_13 -> V_2 ,
L_27 ,
V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] , V_55 [ 3 ] , V_2 -> V_51 ) ;
F_28 ( & V_2 -> V_13 -> V_2 ,
L_28 ) ;
} else {
F_28 ( & V_2 -> V_13 -> V_2 ,
L_32 ) ;
V_65 = - V_41 ;
goto error;
}
* V_63 = V_55 ;
* V_64 = V_5 ;
V_67 = ( void * ) * V_63 ;
switch ( F_33 ( V_67 -> V_76 ) >> 4 & 0x3 ) {
case 0 :
F_28 ( & V_2 -> V_13 -> V_2 , L_33 ) ;
break;
case 1 :
F_28 ( & V_2 -> V_13 -> V_2 , L_34 ) ;
break;
case 2 :
if ( V_2 -> V_77 < V_78 )
F_28 ( & V_2 -> V_13 -> V_2 ,
L_35 ) ;
else
F_28 ( & V_2 -> V_13 -> V_2 ,
L_36 ) ;
break;
case 3 :
if ( V_2 -> V_77 < V_78 )
F_28 ( & V_2 -> V_13 -> V_2 ,
L_36 ) ;
else
F_28 ( & V_2 -> V_13 -> V_2 ,
L_37 ) ;
break;
}
if ( F_33 ( V_67 -> V_76 ) & 1 << 3 )
F_28 ( & V_2 -> V_13 -> V_2 , L_38 ) ;
if ( F_33 ( V_67 -> V_76 ) & 1 << 2 )
F_28 ( & V_2 -> V_13 -> V_2 , L_39 ) ;
switch ( F_33 ( V_67 -> V_76 ) & 0x3 ) {
case 0 :
F_28 ( & V_2 -> V_13 -> V_2 , L_40 ) ;
break;
case 1 :
F_28 ( & V_2 -> V_13 -> V_2 , L_41 ) ;
break;
case 2 :
F_28 ( & V_2 -> V_13 -> V_2 , L_42 ) ;
break;
case 3 :
F_28 ( & V_2 -> V_13 -> V_2 , L_43 ) ;
break;
}
F_28 ( & V_2 -> V_13 -> V_2 ,
L_44 ,
V_67 -> V_79 ,
F_33 ( V_67 -> V_80 ) ,
F_33 ( V_67 -> V_81 ) ,
F_33 ( V_67 -> V_82 ) ) ;
return 0 ;
error:
F_32 ( V_55 ) ;
return V_65 ;
}
static T_3 F_34 ( struct V_33 * V_34 )
{
struct V_24 * V_25 = V_34 -> V_37 ;
if ( ( V_25 -> V_27 == V_28 ) ||
( V_25 -> V_27 == V_30 ) ) {
return V_83 | V_84 ;
} else if ( V_25 -> V_27 == V_29 ) {
return ( V_83 | V_84 ) &
~ V_85 ;
}
F_35 ( 1 , L_45 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , unsigned V_38 )
{
T_1 V_86 [ 128 ] ;
unsigned char V_4 ;
int V_19 , V_26 ;
memset ( V_86 , 0 , F_37 ( V_86 ) ) ;
for ( V_19 = 0 ; V_19 < F_37 ( V_87 ) ; V_19 ++ ) {
V_2 -> V_60 [ V_38 ] . V_3 = V_19 ;
V_26 = F_26 ( & V_2 -> V_60 [ V_38 ] , & V_4 , 0 ) ;
if ( V_26 < 0 )
continue;
V_86 [ V_19 ] = V_19 ;
F_28 ( & V_2 -> V_13 -> V_2 ,
L_46 ,
V_19 << 1 , V_38 , V_87 [ V_19 ] ? V_87 [ V_19 ] : L_47 ) ;
}
if ( V_38 == V_2 -> V_88 )
V_2 -> V_89 = F_23 ( V_86 ,
F_37 ( V_86 ) , 32 ) ;
}
int F_38 ( struct V_1 * V_2 , unsigned V_38 ,
enum V_90 V_27 )
{
int V_91 ;
F_3 ( ! V_2 -> V_12 || ! V_2 -> V_15 ) ;
F_3 ( ! V_2 -> V_22 || ! V_2 -> V_23 ) ;
if ( V_38 >= V_92 )
return - V_41 ;
V_2 -> V_34 [ V_38 ] = V_93 ;
V_2 -> V_34 [ V_38 ] . V_2 . V_94 = & V_2 -> V_13 -> V_2 ;
strcpy ( V_2 -> V_34 [ V_38 ] . V_95 , F_39 ( & V_2 -> V_13 -> V_2 ) ) ;
V_2 -> V_25 [ V_38 ] . V_38 = V_38 ;
V_2 -> V_25 [ V_38 ] . V_27 = V_27 ;
V_2 -> V_25 [ V_38 ] . V_2 = V_2 ;
V_2 -> V_34 [ V_38 ] . V_37 = & V_2 -> V_25 [ V_38 ] ;
V_91 = F_40 ( & V_2 -> V_34 [ V_38 ] ) ;
if ( V_91 < 0 ) {
F_30 ( & V_2 -> V_13 -> V_2 ,
L_48 ,
V_96 , V_91 ) ;
return V_91 ;
}
V_2 -> V_60 [ V_38 ] = V_97 ;
V_2 -> V_60 [ V_38 ] . V_98 = & V_2 -> V_34 [ V_38 ] ;
if ( ! V_38 ) {
V_91 = F_27 ( V_2 , V_38 , & V_2 -> V_63 , & V_2 -> V_64 ) ;
if ( ( V_91 < 0 ) && ( V_91 != - V_41 ) ) {
F_30 ( & V_2 -> V_13 -> V_2 ,
L_49 ,
V_96 , V_91 ) ;
return V_91 ;
}
}
if ( V_99 )
F_36 ( V_2 , V_38 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , unsigned V_38 )
{
if ( V_38 >= V_92 )
return - V_41 ;
F_42 ( & V_2 -> V_34 [ V_38 ] ) ;
return 0 ;
}
