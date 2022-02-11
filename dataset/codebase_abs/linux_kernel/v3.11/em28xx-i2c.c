static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
int V_6 ;
int V_7 ;
T_1 V_8 [ 6 ] ;
if ( V_5 < 1 || V_5 > 4 )
return - V_9 ;
F_2 ( V_5 < 1 || V_5 > 4 ) ;
V_8 [ 5 ] = 0x80 + V_5 - 1 ;
V_8 [ 4 ] = V_3 ;
V_8 [ 3 ] = V_4 [ 0 ] ;
if ( V_5 > 1 )
V_8 [ 2 ] = V_4 [ 1 ] ;
if ( V_5 > 2 )
V_8 [ 1 ] = V_4 [ 2 ] ;
if ( V_5 > 3 )
V_8 [ 0 ] = V_4 [ 3 ] ;
V_6 = V_2 -> V_10 ( V_2 , 4 - V_5 , & V_8 [ 4 - V_5 ] , 2 + V_5 ) ;
if ( V_6 != 2 + V_5 ) {
F_3 ( L_1 ,
V_3 , V_6 ) ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
for ( V_7 = V_12 ; V_7 > 0 ;
V_7 -= 5 ) {
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 == 0x80 + V_5 - 1 ) {
return V_5 ;
} else if ( V_6 == 0x94 + V_5 - 1 ) {
return - V_14 ;
} else if ( V_6 < 0 ) {
F_3 ( L_2 ,
V_6 ) ;
return V_6 ;
}
F_4 ( 5 ) ;
}
F_3 ( L_3 , V_3 ) ;
return - V_11 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
{
T_1 V_15 [ 4 ] ;
int V_6 ;
int V_16 ;
int V_17 ;
if ( V_5 < 1 || V_5 > 4 )
return - V_9 ;
V_15 [ 1 ] = 0x84 + V_5 - 1 ;
V_15 [ 0 ] = V_3 ;
V_6 = V_2 -> V_10 ( V_2 , 0x04 , V_15 , 2 ) ;
if ( V_6 != 2 ) {
F_3 ( L_4 ,
V_3 , V_6 ) ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
for ( V_16 = V_12 ; V_16 > 0 ;
V_16 -= 5 ) {
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 == 0x84 + V_5 - 1 ) {
break;
} else if ( V_6 == 0x94 + V_5 - 1 ) {
return - V_14 ;
} else if ( V_6 < 0 ) {
F_3 ( L_2 ,
V_6 ) ;
return V_6 ;
}
F_4 ( 5 ) ;
}
if ( V_6 != 0x84 + V_5 - 1 )
F_3 ( L_5 , V_3 ) ;
V_6 = V_2 -> V_18 ( V_2 , 0x00 , 4 - V_5 , V_15 , V_5 ) ;
if ( V_6 != V_5 ) {
F_3 ( L_6 ,
V_3 , V_6 ) ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ )
V_4 [ V_17 ] = V_15 [ V_5 - 1 - V_17 ] ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 == 1 )
return 0 ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 , int V_19 )
{
int V_7 , V_6 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_9 ;
V_6 = V_2 -> V_20 ( V_2 , V_19 ? 2 : 3 , V_3 , V_4 , V_5 ) ;
if ( V_6 != V_5 ) {
if ( V_6 < 0 ) {
F_3 ( L_7 ,
V_3 , V_6 ) ;
return V_6 ;
} else {
F_3 ( L_8 ,
V_5 , V_3 , V_6 ) ;
return - V_11 ;
}
}
for ( V_7 = V_12 ; V_7 > 0 ;
V_7 -= 5 ) {
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 == 0 ) {
return V_5 ;
} else if ( V_6 == 0x10 ) {
return - V_14 ;
} else if ( V_6 < 0 ) {
F_3 ( L_9 ,
V_6 ) ;
return V_6 ;
}
F_4 ( 5 ) ;
}
F_3 ( L_3 , V_3 ) ;
return - V_11 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_2 V_5 )
{
int V_6 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_9 ;
V_6 = V_2 -> V_18 ( V_2 , 2 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_10 ,
V_3 , V_6 ) ;
return V_6 ;
}
V_6 = V_2 -> V_13 ( V_2 , 0x05 ) ;
if ( V_6 < 0 ) {
F_3 ( L_9 ,
V_6 ) ;
return V_6 ;
}
if ( V_6 > 0 ) {
if ( V_6 == 0x10 ) {
return - V_14 ;
} else {
F_3 ( L_11 , V_6 ) ;
return - V_11 ;
}
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_6 ;
T_1 V_4 ;
V_6 = F_8 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 == 1 )
return 0 ;
return ( V_6 < 0 ) ? V_6 : - V_11 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 )
{
int V_6 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_9 ;
V_6 = V_2 -> V_20 ( V_2 , 0x06 , V_3 , V_4 , V_5 ) ;
if ( V_6 != V_5 ) {
if ( V_6 < 0 ) {
F_3 ( L_7 ,
V_3 , V_6 ) ;
return V_6 ;
} else {
F_3 ( L_8 ,
V_5 , V_3 , V_6 ) ;
return - V_11 ;
}
}
V_6 = V_2 -> V_21 ( V_2 , 0x08 , 0x0000 ) ;
if ( ! V_6 )
return V_5 ;
else if ( V_6 > 0 )
return - V_14 ;
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 )
{
int V_6 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_9 ;
V_6 = V_2 -> V_18 ( V_2 , 0x06 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_10 ,
V_3 , V_6 ) ;
return V_6 ;
}
V_6 = V_2 -> V_21 ( V_2 , 0x08 , 0x0000 ) ;
if ( ! V_6 )
return V_5 ;
else if ( V_6 > 0 )
return - V_14 ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_11 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static inline int F_13 ( struct V_22 * V_23 , T_2 V_3 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
int V_24 = - V_9 ;
if ( V_23 -> V_25 == V_26 )
V_24 = F_9 ( V_2 , V_3 ) ;
else if ( V_23 -> V_25 == V_27 )
V_24 = F_6 ( V_2 , V_3 ) ;
else if ( V_23 -> V_25 == V_28 )
V_24 = F_12 ( V_2 , V_3 ) ;
if ( V_24 == - V_14 ) {
if ( V_29 )
F_14 ( L_12 ) ;
}
return V_24 ;
}
static inline int F_15 ( struct V_22 * V_23 ,
struct V_30 V_31 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
T_2 V_3 = V_31 . V_3 << 1 ;
int V_32 , V_24 = - V_9 ;
if ( V_23 -> V_25 == V_26 )
V_24 = F_8 ( V_2 , V_3 , V_31 . V_4 , V_31 . V_5 ) ;
else if ( V_23 -> V_25 == V_27 )
V_24 = F_5 ( V_2 , V_3 , V_31 . V_4 , V_31 . V_5 ) ;
else if ( V_23 -> V_25 == V_28 )
V_24 = F_11 ( V_2 , V_3 , V_31 . V_4 , V_31 . V_5 ) ;
if ( V_29 ) {
for ( V_32 = 0 ; V_32 < V_31 . V_5 ; V_32 ++ )
F_14 ( L_13 , V_31 . V_4 [ V_32 ] ) ;
}
return V_24 ;
}
static inline int F_16 ( struct V_22 * V_23 ,
struct V_30 V_31 , int V_19 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
T_2 V_3 = V_31 . V_3 << 1 ;
int V_32 , V_24 = - V_9 ;
if ( V_29 ) {
for ( V_32 = 0 ; V_32 < V_31 . V_5 ; V_32 ++ )
F_14 ( L_13 , V_31 . V_4 [ V_32 ] ) ;
}
if ( V_23 -> V_25 == V_26 )
V_24 = F_7 ( V_2 , V_3 , V_31 . V_4 , V_31 . V_5 , V_19 ) ;
else if ( V_23 -> V_25 == V_27 )
V_24 = F_1 ( V_2 , V_3 , V_31 . V_4 , V_31 . V_5 ) ;
else if ( V_23 -> V_25 == V_28 )
V_24 = F_10 ( V_2 , V_3 , V_31 . V_4 , V_31 . V_5 ) ;
return V_24 ;
}
static int F_17 ( struct V_33 * V_34 ,
struct V_30 V_35 [] , int V_36 )
{
struct V_22 * V_23 = V_34 -> V_37 ;
struct V_1 * V_2 = V_23 -> V_2 ;
unsigned V_38 = V_23 -> V_38 ;
int V_3 , V_24 , V_17 ;
T_1 V_39 ;
V_24 = F_18 ( & V_2 -> V_40 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_38 != V_2 -> V_41 &&
V_23 -> V_25 == V_26 ) {
if ( V_38 == 1 )
V_39 = V_42 ;
else
V_39 = 0 ;
F_19 ( V_2 , V_43 , V_39 ,
V_42 ) ;
V_2 -> V_41 = V_38 ;
}
if ( V_36 <= 0 ) {
F_20 ( & V_2 -> V_40 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < V_36 ; V_17 ++ ) {
V_3 = V_35 [ V_17 ] . V_3 << 1 ;
if ( V_29 )
F_14 ( V_44 L_14 ,
V_2 -> V_45 , V_46 ,
( V_35 [ V_17 ] . V_47 & V_48 ) ? L_15 : L_16 ,
V_17 == V_36 - 1 ? L_17 : L_18 ,
V_3 , V_35 [ V_17 ] . V_5 ) ;
if ( ! V_35 [ V_17 ] . V_5 ) {
V_24 = F_13 ( V_23 , V_3 ) ;
if ( V_24 == - V_14 ) {
F_20 ( & V_2 -> V_40 ) ;
return V_24 ;
}
} else if ( V_35 [ V_17 ] . V_47 & V_48 ) {
V_24 = F_15 ( V_23 , V_35 [ V_17 ] ) ;
} else {
V_24 = F_16 ( V_23 , V_35 [ V_17 ] , V_17 == V_36 - 1 ) ;
}
if ( V_24 < 0 ) {
if ( V_29 )
F_14 ( L_19 , V_24 ) ;
F_20 ( & V_2 -> V_40 ) ;
return V_24 ;
}
if ( V_29 )
F_14 ( L_20 ) ;
}
F_20 ( & V_2 -> V_40 ) ;
return V_36 ;
}
static inline unsigned long F_21 ( char * V_4 , int V_49 , int V_50 )
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
static int F_22 ( struct V_1 * V_2 , unsigned V_38 , T_2 V_3 ,
bool V_54 , T_2 V_5 , T_1 * V_55 )
{
int V_56 = V_5 , V_57 , V_58 , V_6 ;
T_1 V_4 [ 2 ] ;
if ( V_3 + V_56 > ( V_54 * 0xff00 + 0xff + 1 ) )
return - V_59 ;
V_4 [ 0 ] = V_3 >> 8 ;
V_4 [ 1 ] = V_3 & 0xff ;
V_6 = F_23 ( & V_2 -> V_60 [ V_38 ] , V_4 + ! V_54 , 1 + V_54 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_61 . V_62 )
V_58 = 4 ;
else
V_58 = 64 ;
while ( V_56 > 0 ) {
if ( V_56 > V_58 )
V_57 = V_58 ;
else
V_57 = V_56 ;
V_6 = F_24 ( & V_2 -> V_60 [ V_38 ] , V_55 , V_57 ) ;
if ( V_6 < 0 )
return V_6 ;
V_56 -= V_57 ;
V_55 += V_57 ;
}
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_38 ,
T_1 * * V_63 , T_2 * V_64 )
{
const T_2 V_5 = 256 ;
int V_17 , V_65 ;
struct V_66 * V_67 ;
T_1 V_4 , * V_55 ;
* V_63 = NULL ;
* V_64 = 0 ;
V_2 -> V_60 [ V_38 ] . V_3 = 0xa0 >> 1 ;
V_65 = F_24 ( & V_2 -> V_60 [ V_38 ] , & V_4 , 0 ) ;
if ( V_65 < 0 ) {
F_26 ( L_21 ) ;
return - V_14 ;
}
V_55 = F_27 ( V_5 , V_68 ) ;
if ( V_55 == NULL )
return - V_69 ;
V_65 = F_22 ( V_2 , V_38 , 0x0000 ,
V_2 -> V_70 ,
V_5 , V_55 ) ;
if ( V_65 != V_5 ) {
F_28 ( L_22 , V_65 ) ;
goto error;
}
for ( V_17 = 0 ; V_17 < V_5 ; V_17 ++ ) {
if ( 0 == ( V_17 % 16 ) ) {
if ( V_2 -> V_70 )
F_26 ( L_23 , V_17 ) ;
else
F_26 ( L_24 , V_17 ) ;
}
F_14 ( L_13 , V_55 [ V_17 ] ) ;
if ( 15 == ( V_17 % 16 ) )
F_14 ( L_20 ) ;
}
if ( V_2 -> V_70 )
F_26 ( L_25 , V_17 ) ;
if ( V_2 -> V_70 &&
V_55 [ 0 ] == 0x26 && V_55 [ 3 ] == 0x00 ) {
T_2 V_71 ;
T_2 V_72 ;
V_2 -> V_51 = F_21 ( V_55 , V_5 , 32 ) ;
V_71 = ( V_55 [ 1 ] << 8 ) + 4 ;
F_26 ( L_26 ,
V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] , V_55 [ 3 ] , V_2 -> V_51 ) ;
F_26 ( L_27 ) ;
F_26 ( L_28 ,
V_71 , V_55 [ 2 ] ) ;
V_65 = F_22 ( V_2 , V_38 , V_71 + 46 , 1 , 2 ,
V_55 ) ;
if ( V_65 != 2 ) {
F_28 ( L_29 ,
V_65 ) ;
goto error;
}
V_72 = V_71 + V_55 [ 0 ] + ( V_55 [ 1 ] << 8 ) ;
V_65 = F_22 ( V_2 , V_38 , V_72 , 1 , V_5 ,
V_55 ) ;
if ( V_65 != V_5 ) {
F_28 ( L_29 ,
V_65 ) ;
goto error;
}
if ( V_55 [ 0 ] != 0x1a || V_55 [ 1 ] != 0xeb ||
V_55 [ 2 ] != 0x67 || V_55 [ 3 ] != 0x95 ) {
F_26 ( L_30 ) ;
F_29 ( V_55 ) ;
return 0 ;
}
} else if ( ! V_2 -> V_70 &&
V_55 [ 0 ] == 0x1a && V_55 [ 1 ] == 0xeb &&
V_55 [ 2 ] == 0x67 && V_55 [ 3 ] == 0x95 ) {
V_2 -> V_51 = F_21 ( V_55 , V_5 , 32 ) ;
F_26 ( L_26 ,
V_55 [ 0 ] , V_55 [ 1 ] , V_55 [ 2 ] , V_55 [ 3 ] , V_2 -> V_51 ) ;
F_26 ( L_27 ) ;
} else {
F_26 ( L_31 ) ;
V_65 = - V_14 ;
goto error;
}
* V_63 = V_55 ;
* V_64 = V_5 ;
V_67 = ( void * ) * V_63 ;
switch ( F_30 ( V_67 -> V_73 ) >> 4 & 0x3 ) {
case 0 :
F_26 ( L_32 ) ;
break;
case 1 :
F_26 ( L_33 ) ;
break;
case 2 :
F_26 ( L_34 ) ;
break;
case 3 :
F_26 ( L_35 ) ;
break;
}
if ( F_30 ( V_67 -> V_73 ) & 1 << 3 )
F_26 ( L_36 ) ;
if ( F_30 ( V_67 -> V_73 ) & 1 << 2 )
F_26 ( L_37 ) ;
switch ( F_30 ( V_67 -> V_73 ) & 0x3 ) {
case 0 :
F_26 ( L_38 ) ;
break;
case 1 :
F_26 ( L_39 ) ;
break;
case 2 :
F_26 ( L_40 ) ;
break;
case 3 :
F_26 ( L_41 ) ;
break;
}
F_26 ( L_42 ,
V_67 -> V_74 ,
F_30 ( V_67 -> V_75 ) ,
F_30 ( V_67 -> V_76 ) ,
F_30 ( V_67 -> V_77 ) ) ;
return 0 ;
error:
F_29 ( V_55 ) ;
return V_65 ;
}
static T_3 F_31 ( struct V_33 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_37 ;
if ( ( V_23 -> V_25 == V_26 ) ||
( V_23 -> V_25 == V_28 ) ) {
return V_78 | V_79 ;
} else if ( V_23 -> V_25 == V_27 ) {
return ( V_78 | V_79 ) &
~ V_80 ;
}
F_32 ( 1 , L_43 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 , unsigned V_38 )
{
T_1 V_81 [ 128 ] ;
unsigned char V_4 ;
int V_17 , V_24 ;
memset ( V_81 , 0 , F_34 ( V_81 ) ) ;
for ( V_17 = 0 ; V_17 < F_34 ( V_82 ) ; V_17 ++ ) {
V_2 -> V_60 [ V_38 ] . V_3 = V_17 ;
V_24 = F_24 ( & V_2 -> V_60 [ V_38 ] , & V_4 , 0 ) ;
if ( V_24 < 0 )
continue;
V_81 [ V_17 ] = V_17 ;
F_26 ( L_44 ,
V_17 << 1 , V_38 , V_82 [ V_17 ] ? V_82 [ V_17 ] : L_45 ) ;
}
if ( V_38 == V_2 -> V_83 )
V_2 -> V_84 = F_21 ( V_81 ,
F_34 ( V_81 ) , 32 ) ;
}
int F_35 ( struct V_1 * V_2 , unsigned V_38 ,
enum V_85 V_25 )
{
int V_86 ;
F_2 ( ! V_2 -> V_10 || ! V_2 -> V_13 ) ;
F_2 ( ! V_2 -> V_20 || ! V_2 -> V_21 ) ;
if ( V_38 >= V_87 )
return - V_14 ;
V_2 -> V_34 [ V_38 ] = V_88 ;
V_2 -> V_34 [ V_38 ] . V_2 . V_89 = & V_2 -> V_90 -> V_2 ;
strcpy ( V_2 -> V_34 [ V_38 ] . V_45 , V_2 -> V_45 ) ;
V_2 -> V_23 [ V_38 ] . V_38 = V_38 ;
V_2 -> V_23 [ V_38 ] . V_25 = V_25 ;
V_2 -> V_23 [ V_38 ] . V_2 = V_2 ;
V_2 -> V_34 [ V_38 ] . V_37 = & V_2 -> V_23 [ V_38 ] ;
F_36 ( & V_2 -> V_34 [ V_38 ] , & V_2 -> V_91 ) ;
V_86 = F_37 ( & V_2 -> V_34 [ V_38 ] ) ;
if ( V_86 < 0 ) {
F_28 ( L_46 ,
V_46 , V_86 ) ;
return V_86 ;
}
V_2 -> V_60 [ V_38 ] = V_92 ;
V_2 -> V_60 [ V_38 ] . V_93 = & V_2 -> V_34 [ V_38 ] ;
if ( ! V_38 ) {
V_86 = F_25 ( V_2 , V_38 , & V_2 -> V_63 , & V_2 -> V_64 ) ;
if ( ( V_86 < 0 ) && ( V_86 != - V_14 ) ) {
F_28 ( L_47 ,
V_46 , V_86 ) ;
return V_86 ;
}
}
if ( V_94 )
F_33 ( V_2 , V_38 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , unsigned V_38 )
{
if ( V_38 >= V_87 )
return - V_14 ;
F_39 ( & V_2 -> V_34 [ V_38 ] ) ;
return 0 ;
}
