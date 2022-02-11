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
F_4 ( L_1 ,
V_3 , V_9 ) ;
return ( V_9 < 0 ) ? V_9 : - V_13 ;
}
while ( F_5 ( V_6 ) ) {
V_9 = V_2 -> V_14 ( V_2 , 0x05 ) ;
if ( V_9 == 0x80 + V_5 - 1 )
return V_5 ;
if ( V_9 == 0x94 + V_5 - 1 ) {
if ( V_15 == 1 )
F_4 ( L_2 ,
V_9 ) ;
return - V_16 ;
}
if ( V_9 < 0 ) {
F_4 ( L_3 ,
V_9 ) ;
return V_9 ;
}
F_6 ( 5 ) ;
}
if ( V_15 )
F_4 ( L_4 , V_3 ) ;
return - V_17 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_2 V_5 )
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
F_4 ( L_5 ,
V_3 , V_9 ) ;
return ( V_9 < 0 ) ? V_9 : - V_13 ;
}
while ( F_5 ( V_6 ) ) {
V_9 = V_2 -> V_14 ( V_2 , 0x05 ) ;
if ( V_9 == 0x84 + V_5 - 1 )
break;
if ( V_9 == 0x94 + V_5 - 1 ) {
if ( V_15 == 1 )
F_4 ( L_2 ,
V_9 ) ;
return - V_16 ;
}
if ( V_9 < 0 ) {
F_4 ( L_3 ,
V_9 ) ;
return V_9 ;
}
F_6 ( 5 ) ;
}
if ( V_9 != 0x84 + V_5 - 1 ) {
if ( V_15 )
F_4 ( L_6 ,
V_3 ) ;
}
V_9 = V_2 -> V_20 ( V_2 , 0x00 , 4 - V_5 , V_18 , V_5 ) ;
if ( V_9 != V_5 ) {
F_4 ( L_7 ,
V_3 , V_9 ) ;
return ( V_9 < 0 ) ? V_9 : - V_13 ;
}
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_4 [ V_19 ] = V_18 [ V_5 - 1 - V_19 ] ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_9 ;
V_9 = F_7 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_9 == 1 )
return 0 ;
return ( V_9 < 0 ) ? V_9 : - V_13 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 , int V_21 )
{
unsigned long V_6 = V_7 + F_2 ( V_8 ) ;
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_22 ( V_2 , V_21 ? 2 : 3 , V_3 , V_4 , V_5 ) ;
if ( V_9 != V_5 ) {
if ( V_9 < 0 ) {
F_4 ( L_8 ,
V_3 , V_9 ) ;
return V_9 ;
} else {
F_4 ( L_9 ,
V_5 , V_3 , V_9 ) ;
return - V_13 ;
}
}
while ( F_5 ( V_6 ) ) {
V_9 = V_2 -> V_14 ( V_2 , 0x05 ) ;
if ( V_9 == 0 )
return V_5 ;
if ( V_9 == 0x10 ) {
if ( V_15 == 1 )
F_4 ( L_10 ,
V_3 ) ;
return - V_16 ;
}
if ( V_9 < 0 ) {
F_4 ( L_3 ,
V_9 ) ;
return V_9 ;
}
F_6 ( 5 ) ;
}
if ( V_9 == 0x02 || V_9 == 0x04 ) {
if ( V_15 )
F_4 ( L_11 ,
V_3 , V_9 ) ;
return - V_17 ;
}
F_4 ( L_12 ,
V_3 , V_9 ) ;
return - V_13 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 , T_2 V_5 )
{
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_20 ( V_2 , 2 , V_3 , V_4 , V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( L_13 ,
V_3 , V_9 ) ;
return V_9 ;
}
V_9 = V_2 -> V_14 ( V_2 , 0x05 ) ;
if ( V_9 == 0 )
return V_5 ;
if ( V_9 < 0 ) {
F_4 ( L_3 ,
V_9 ) ;
return V_9 ;
}
if ( V_9 == 0x10 ) {
if ( V_15 == 1 )
F_4 ( L_10 ,
V_3 ) ;
return - V_16 ;
}
if ( V_9 == 0x02 || V_9 == 0x04 ) {
if ( V_15 )
F_4 ( L_11 ,
V_3 , V_9 ) ;
return - V_17 ;
}
F_4 ( L_12 ,
V_3 , V_9 ) ;
return - V_13 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_9 ;
T_1 V_4 ;
V_9 = F_10 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_9 == 1 )
return 0 ;
return ( V_9 < 0 ) ? V_9 : - V_13 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 )
{
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_22 ( V_2 , 0x06 , V_3 , V_4 , V_5 ) ;
if ( V_9 != V_5 ) {
if ( V_9 < 0 ) {
F_4 ( L_8 ,
V_3 , V_9 ) ;
return V_9 ;
} else {
F_4 ( L_9 ,
V_5 , V_3 , V_9 ) ;
return - V_13 ;
}
}
V_9 = V_2 -> V_23 ( V_2 , 0x08 , 0x0000 ) ;
if ( ! V_9 )
return V_5 ;
else if ( V_9 > 0 ) {
if ( V_15 == 1 )
F_4 ( L_14 ,
V_9 ) ;
return - V_16 ;
}
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 ,
T_2 V_5 )
{
int V_9 ;
if ( V_5 < 1 || V_5 > 64 )
return - V_11 ;
V_9 = V_2 -> V_20 ( V_2 , 0x06 , V_3 , V_4 , V_5 ) ;
if ( V_9 < 0 ) {
F_4 ( L_13 ,
V_3 , V_9 ) ;
return V_9 ;
}
V_9 = V_2 -> V_23 ( V_2 , 0x08 , 0x0000 ) ;
if ( ! V_9 )
return V_5 ;
else if ( V_9 > 0 ) {
if ( V_15 == 1 )
F_4 ( L_14 ,
V_9 ) ;
return - V_16 ;
}
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
int V_9 ;
V_9 = F_13 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static inline int F_15 ( struct V_24 * V_25 , T_2 V_3 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_26 = - V_11 ;
if ( V_25 -> V_27 == V_28 )
V_26 = F_11 ( V_2 , V_3 ) ;
else if ( V_25 -> V_27 == V_29 )
V_26 = F_8 ( V_2 , V_3 ) ;
else if ( V_25 -> V_27 == V_30 )
V_26 = F_14 ( V_2 , V_3 ) ;
return V_26 ;
}
static inline int F_16 ( struct V_24 * V_25 ,
struct V_31 V_32 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_3 = V_32 . V_3 << 1 ;
int V_26 = - V_11 ;
if ( V_25 -> V_27 == V_28 )
V_26 = F_10 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
else if ( V_25 -> V_27 == V_29 )
V_26 = F_7 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
else if ( V_25 -> V_27 == V_30 )
V_26 = F_13 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
return V_26 ;
}
static inline int F_17 ( struct V_24 * V_25 ,
struct V_31 V_32 , int V_21 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_3 = V_32 . V_3 << 1 ;
int V_26 = - V_11 ;
if ( V_25 -> V_27 == V_28 )
V_26 = F_9 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 , V_21 ) ;
else if ( V_25 -> V_27 == V_29 )
V_26 = F_1 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
else if ( V_25 -> V_27 == V_30 )
V_26 = F_12 ( V_2 , V_3 , V_32 . V_4 , V_32 . V_5 ) ;
return V_26 ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_31 V_35 [] , int V_36 )
{
struct V_24 * V_25 = V_34 -> V_37 ;
struct V_1 * V_2 = V_25 -> V_2 ;
unsigned V_38 = V_25 -> V_38 ;
int V_3 , V_26 , V_19 ;
T_1 V_39 ;
if ( V_2 -> V_40 )
return - V_41 ;
V_26 = F_19 ( & V_2 -> V_42 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_38 != V_2 -> V_43 &&
V_25 -> V_27 == V_28 ) {
if ( V_38 == 1 )
V_39 = V_44 ;
else
V_39 = 0 ;
F_20 ( V_2 , V_45 , V_39 ,
V_44 ) ;
V_2 -> V_43 = V_38 ;
}
if ( V_36 <= 0 ) {
F_21 ( & V_2 -> V_42 ) ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_36 ; V_19 ++ ) {
V_3 = V_35 [ V_19 ] . V_3 << 1 ;
if ( V_15 > 1 )
F_22 ( V_46 L_15 ,
V_2 -> V_47 , V_48 ,
( V_35 [ V_19 ] . V_49 & V_50 ) ? L_16 : L_17 ,
V_19 == V_36 - 1 ? L_18 : L_19 ,
V_3 , V_35 [ V_19 ] . V_5 ) ;
if ( ! V_35 [ V_19 ] . V_5 ) {
V_26 = F_15 ( V_25 , V_3 ) ;
if ( V_26 < 0 ) {
if ( V_26 == - V_16 ) {
if ( V_15 > 1 )
F_22 ( V_51 L_20 ) ;
V_26 = - V_41 ;
} else {
if ( V_15 > 1 )
F_22 ( V_51 L_21 , V_26 ) ;
}
F_21 ( & V_2 -> V_42 ) ;
return V_26 ;
}
} else if ( V_35 [ V_19 ] . V_49 & V_50 ) {
V_26 = F_16 ( V_25 , V_35 [ V_19 ] ) ;
if ( V_15 > 1 && V_26 >= 0 )
F_22 ( V_51 L_22 ,
V_35 [ V_19 ] . V_5 , V_35 [ V_19 ] . V_4 ) ;
} else {
if ( V_15 > 1 )
F_22 ( V_51 L_22 ,
V_35 [ V_19 ] . V_5 , V_35 [ V_19 ] . V_4 ) ;
V_26 = F_17 ( V_25 , V_35 [ V_19 ] , V_19 == V_36 - 1 ) ;
}
if ( V_26 < 0 ) {
if ( V_15 > 1 )
F_22 ( V_51 L_21 , V_26 ) ;
F_21 ( & V_2 -> V_42 ) ;
return V_26 ;
}
if ( V_15 > 1 )
F_22 ( V_51 L_23 ) ;
}
F_21 ( & V_2 -> V_42 ) ;
return V_36 ;
}
static inline unsigned long F_23 ( char * V_4 , int V_52 , int V_53 )
{
unsigned long V_54 = 0 ;
unsigned long V_55 = 0 ;
int V_5 = 0 ;
unsigned char V_56 ;
do {
if ( V_5 == V_52 ) {
V_56 = ( char ) V_5 ;
V_5 = - 1 ;
} else
V_56 = * V_4 ++ ;
V_55 = ( V_55 << 8 ) | V_56 ;
V_5 ++ ;
if ( ( V_5 & ( 32 / 8 - 1 ) ) == 0 )
V_54 = ( ( V_54 ^ V_55 ) * 0x9e370001UL ) ;
} while ( V_5 );
return ( V_54 >> ( 32 - V_53 ) ) & 0xffffffffUL ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_38 , T_2 V_3 ,
bool V_57 , T_2 V_5 , T_1 * V_58 )
{
int V_59 = V_5 , V_60 , V_61 , V_9 ;
T_1 V_4 [ 2 ] ;
if ( V_3 + V_59 > ( V_57 * 0xff00 + 0xff + 1 ) )
return - V_62 ;
V_4 [ 0 ] = V_3 >> 8 ;
V_4 [ 1 ] = V_3 & 0xff ;
V_9 = F_25 ( & V_2 -> V_63 [ V_38 ] , V_4 + ! V_57 , 1 + V_57 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_2 -> V_64 . V_65 )
V_61 = 4 ;
else
V_61 = 64 ;
while ( V_59 > 0 ) {
if ( V_59 > V_61 )
V_60 = V_61 ;
else
V_60 = V_59 ;
V_9 = F_26 ( & V_2 -> V_63 [ V_38 ] , V_58 , V_60 ) ;
if ( V_9 < 0 )
return V_9 ;
V_59 -= V_60 ;
V_58 += V_60 ;
}
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned V_38 ,
T_1 * * V_66 , T_2 * V_67 )
{
const T_2 V_5 = 256 ;
int V_68 ;
struct V_69 * V_70 ;
T_1 V_4 , * V_58 ;
* V_66 = NULL ;
* V_67 = 0 ;
V_2 -> V_63 [ V_38 ] . V_3 = 0xa0 >> 1 ;
V_68 = F_26 ( & V_2 -> V_63 [ V_38 ] , & V_4 , 0 ) ;
if ( V_68 < 0 ) {
F_28 ( L_24 ) ;
return - V_41 ;
}
V_58 = F_29 ( V_5 , V_71 ) ;
if ( V_58 == NULL )
return - V_72 ;
V_68 = F_24 ( V_2 , V_38 , 0x0000 ,
V_2 -> V_73 ,
V_5 , V_58 ) ;
if ( V_68 != V_5 ) {
F_30 ( L_25 , V_68 ) ;
goto error;
}
if ( V_15 ) {
F_31 ( V_74 , L_26 , V_75 ,
16 , 1 , V_58 , V_5 , true ) ;
if ( V_2 -> V_73 )
F_28 ( L_27 , 256 ) ;
}
if ( V_2 -> V_73 &&
V_58 [ 0 ] == 0x26 && V_58 [ 3 ] == 0x00 ) {
T_2 V_76 ;
T_2 V_77 ;
V_2 -> V_54 = F_23 ( V_58 , V_5 , 32 ) ;
V_76 = ( V_58 [ 1 ] << 8 ) + 4 ;
F_28 ( L_28 ,
V_58 [ 0 ] , V_58 [ 1 ] , V_58 [ 2 ] , V_58 [ 3 ] , V_2 -> V_54 ) ;
F_28 ( L_29 ) ;
F_28 ( L_30 ,
V_76 , V_58 [ 2 ] ) ;
V_68 = F_24 ( V_2 , V_38 , V_76 + 46 , 1 , 2 ,
V_58 ) ;
if ( V_68 != 2 ) {
F_30 ( L_31 ,
V_68 ) ;
goto error;
}
V_77 = V_76 + V_58 [ 0 ] + ( V_58 [ 1 ] << 8 ) ;
V_68 = F_24 ( V_2 , V_38 , V_77 , 1 , V_5 ,
V_58 ) ;
if ( V_68 != V_5 ) {
F_30 ( L_31 ,
V_68 ) ;
goto error;
}
if ( V_58 [ 0 ] != 0x1a || V_58 [ 1 ] != 0xeb ||
V_58 [ 2 ] != 0x67 || V_58 [ 3 ] != 0x95 ) {
F_28 ( L_32 ) ;
F_32 ( V_58 ) ;
return 0 ;
}
} else if ( ! V_2 -> V_73 &&
V_58 [ 0 ] == 0x1a && V_58 [ 1 ] == 0xeb &&
V_58 [ 2 ] == 0x67 && V_58 [ 3 ] == 0x95 ) {
V_2 -> V_54 = F_23 ( V_58 , V_5 , 32 ) ;
F_28 ( L_28 ,
V_58 [ 0 ] , V_58 [ 1 ] , V_58 [ 2 ] , V_58 [ 3 ] , V_2 -> V_54 ) ;
F_28 ( L_29 ) ;
} else {
F_28 ( L_33 ) ;
V_68 = - V_41 ;
goto error;
}
* V_66 = V_58 ;
* V_67 = V_5 ;
V_70 = ( void * ) * V_66 ;
switch ( F_33 ( V_70 -> V_78 ) >> 4 & 0x3 ) {
case 0 :
F_28 ( L_34 ) ;
break;
case 1 :
F_28 ( L_35 ) ;
break;
case 2 :
if ( V_2 -> V_79 < V_80 )
F_28 ( L_36 ) ;
else
F_28 ( L_37 ) ;
break;
case 3 :
if ( V_2 -> V_79 < V_80 )
F_28 ( L_37 ) ;
else
F_28 ( L_38 ) ;
break;
}
if ( F_33 ( V_70 -> V_78 ) & 1 << 3 )
F_28 ( L_39 ) ;
if ( F_33 ( V_70 -> V_78 ) & 1 << 2 )
F_28 ( L_40 ) ;
switch ( F_33 ( V_70 -> V_78 ) & 0x3 ) {
case 0 :
F_28 ( L_41 ) ;
break;
case 1 :
F_28 ( L_42 ) ;
break;
case 2 :
F_28 ( L_43 ) ;
break;
case 3 :
F_28 ( L_44 ) ;
break;
}
F_28 ( L_45 ,
V_70 -> V_81 ,
F_33 ( V_70 -> V_82 ) ,
F_33 ( V_70 -> V_83 ) ,
F_33 ( V_70 -> V_84 ) ) ;
return 0 ;
error:
F_32 ( V_58 ) ;
return V_68 ;
}
static T_3 F_34 ( struct V_33 * V_34 )
{
struct V_24 * V_25 = V_34 -> V_37 ;
if ( ( V_25 -> V_27 == V_28 ) ||
( V_25 -> V_27 == V_30 ) ) {
return V_85 | V_86 ;
} else if ( V_25 -> V_27 == V_29 ) {
return ( V_85 | V_86 ) &
~ V_87 ;
}
F_35 ( 1 , L_46 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 , unsigned V_38 )
{
T_1 V_88 [ 128 ] ;
unsigned char V_4 ;
int V_19 , V_26 ;
memset ( V_88 , 0 , F_37 ( V_88 ) ) ;
for ( V_19 = 0 ; V_19 < F_37 ( V_89 ) ; V_19 ++ ) {
V_2 -> V_63 [ V_38 ] . V_3 = V_19 ;
V_26 = F_26 ( & V_2 -> V_63 [ V_38 ] , & V_4 , 0 ) ;
if ( V_26 < 0 )
continue;
V_88 [ V_19 ] = V_19 ;
F_28 ( L_47 ,
V_19 << 1 , V_38 , V_89 [ V_19 ] ? V_89 [ V_19 ] : L_48 ) ;
}
if ( V_38 == V_2 -> V_90 )
V_2 -> V_91 = F_23 ( V_88 ,
F_37 ( V_88 ) , 32 ) ;
}
int F_38 ( struct V_1 * V_2 , unsigned V_38 ,
enum V_92 V_27 )
{
int V_93 ;
F_3 ( ! V_2 -> V_12 || ! V_2 -> V_14 ) ;
F_3 ( ! V_2 -> V_22 || ! V_2 -> V_23 ) ;
if ( V_38 >= V_94 )
return - V_41 ;
V_2 -> V_34 [ V_38 ] = V_95 ;
V_2 -> V_34 [ V_38 ] . V_2 . V_96 = & V_2 -> V_97 -> V_2 ;
strcpy ( V_2 -> V_34 [ V_38 ] . V_47 , V_2 -> V_47 ) ;
V_2 -> V_25 [ V_38 ] . V_38 = V_38 ;
V_2 -> V_25 [ V_38 ] . V_27 = V_27 ;
V_2 -> V_25 [ V_38 ] . V_2 = V_2 ;
V_2 -> V_34 [ V_38 ] . V_37 = & V_2 -> V_25 [ V_38 ] ;
V_93 = F_39 ( & V_2 -> V_34 [ V_38 ] ) ;
if ( V_93 < 0 ) {
F_30 ( L_49 ,
V_48 , V_93 ) ;
return V_93 ;
}
V_2 -> V_63 [ V_38 ] = V_98 ;
V_2 -> V_63 [ V_38 ] . V_99 = & V_2 -> V_34 [ V_38 ] ;
if ( ! V_38 ) {
V_93 = F_27 ( V_2 , V_38 , & V_2 -> V_66 , & V_2 -> V_67 ) ;
if ( ( V_93 < 0 ) && ( V_93 != - V_41 ) ) {
F_30 ( L_50 ,
V_48 , V_93 ) ;
return V_93 ;
}
}
if ( V_100 )
F_36 ( V_2 , V_38 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , unsigned V_38 )
{
if ( V_38 >= V_94 )
return - V_41 ;
F_41 ( & V_2 -> V_34 [ V_38 ] ) ;
return 0 ;
}
