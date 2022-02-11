static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
char * V_4 , int V_5 )
{
int V_6 ;
int V_7 ;
unsigned char V_8 [ 6 ] ;
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
V_6 = V_2 -> V_9 ( V_2 , 4 - V_5 , & V_8 [ 4 - V_5 ] , 2 + V_5 ) ;
if ( V_6 != 2 + V_5 ) {
F_3 ( L_1 , V_6 ) ;
return - V_10 ;
}
for ( V_7 = V_11 ; V_7 > 0 ;
V_7 -= 5 ) {
V_6 = V_2 -> V_12 ( V_2 , 0x05 ) ;
if ( V_6 == 0x80 + V_5 - 1 )
return V_5 ;
F_4 ( 5 ) ;
}
F_3 ( L_2 ) ;
return - V_10 ;
}
static int F_5 ( void * V_13 , unsigned char V_3 , char * V_4 ,
short V_5 )
{
char * V_14 = V_4 ;
int V_6 ;
int V_15 = 0 ;
int V_16 ;
int V_17 = 4 ;
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
while ( V_5 > 0 ) {
V_16 = ( V_5 > V_17 ) ? V_17 : V_5 ;
V_6 = F_1 ( V_2 , V_3 , V_14 , V_16 ) ;
if ( V_6 > 0 ) {
V_5 -= V_16 ;
V_14 += V_16 ;
V_15 += V_16 ;
} else
return ( V_6 < 0 ) ? V_6 : - V_18 ;
}
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char V_3 )
{
char V_19 ;
int V_6 ;
int V_7 ;
V_19 = V_3 ;
V_6 = V_2 -> V_9 ( V_2 , 0x04 , & V_19 , 1 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 ,
V_6 ) ;
return V_6 ;
}
V_19 = 0x84 ;
V_6 = V_2 -> V_9 ( V_2 , 0x05 , & V_19 , 1 ) ;
if ( V_6 < 0 ) {
F_3 ( L_4 , V_6 ) ;
return V_6 ;
}
for ( V_7 = V_11 ; V_7 > 0 ;
V_7 -= 5 ) {
unsigned V_20 = V_2 -> V_12 ( V_2 , 0x5 ) ;
if ( V_20 == 0x94 )
return - V_21 ;
else if ( V_20 == 0x84 )
return 0 ;
F_4 ( 5 ) ;
}
return - V_21 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char V_3 ,
char * V_4 , int V_5 )
{
int V_6 ;
V_6 = F_6 ( V_2 , V_3 ) ;
if ( V_6 ) {
F_3
( L_5 ,
V_3 , V_6 ) ;
return V_6 ;
}
V_6 = V_2 -> V_22 ( V_2 , 0x0 , 0x3 , V_4 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_6 ,
V_3 , V_6 ) ;
return V_6 ;
}
return V_6 ;
}
static int F_8 ( void * V_13 , unsigned char V_3 , char * V_4 ,
short V_5 , int V_23 )
{
int V_15 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
int V_7 , V_6 ;
V_15 = V_2 -> V_24 ( V_2 , V_23 ? 2 : 3 , V_3 , V_4 , V_5 ) ;
for ( V_7 = V_11 ; V_7 > 0 ;
V_7 -= 5 ) {
V_6 = V_2 -> V_12 ( V_2 , 0x05 ) ;
if ( ! V_6 )
break;
F_4 ( 5 ) ;
}
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned char V_3 ,
char * V_4 , int V_5 )
{
int V_6 ;
V_6 = V_2 -> V_22 ( V_2 , 2 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( L_7 , V_6 ) ;
return V_6 ;
}
if ( V_2 -> V_12 ( V_2 , 0x5 ) != 0 )
return - V_21 ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned char V_3 )
{
int V_6 ;
V_6 = V_2 -> V_25 ( V_2 , 2 , V_3 ) ;
if ( V_6 < 0 ) {
F_3 ( L_8 , V_6 ) ;
return V_6 ;
}
if ( V_2 -> V_12 ( V_2 , 0x5 ) != 0 )
return - V_21 ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_28 V_29 [] , int V_30 )
{
struct V_1 * V_2 = V_27 -> V_31 ;
int V_3 , V_32 , V_33 , V_34 ;
if ( V_30 <= 0 )
return 0 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
V_3 = V_29 [ V_33 ] . V_3 << 1 ;
F_12 ( 2 , L_9 ,
( V_29 [ V_33 ] . V_35 & V_36 ) ? L_10 : L_11 ,
V_33 == V_30 - 1 ? L_12 : L_13 , V_3 , V_29 [ V_33 ] . V_5 ) ;
if ( ! V_29 [ V_33 ] . V_5 ) {
if ( V_2 -> V_37 . V_38 )
V_32 = F_6 ( V_2 , V_3 ) ;
else
V_32 = F_10 ( V_2 , V_3 ) ;
if ( V_32 < 0 ) {
F_12 ( 2 , L_14 ) ;
return V_32 ;
}
} else if ( V_29 [ V_33 ] . V_35 & V_36 ) {
if ( V_2 -> V_37 . V_38 )
V_32 = F_7 ( V_2 , V_3 ,
V_29 [ V_33 ] . V_4 ,
V_29 [ V_33 ] . V_5 ) ;
else
V_32 = F_9 ( V_2 , V_3 ,
V_29 [ V_33 ] . V_4 ,
V_29 [ V_33 ] . V_5 ) ;
if ( V_39 >= 2 ) {
for ( V_34 = 0 ; V_34 < V_29 [ V_33 ] . V_5 ; V_34 ++ )
F_13 ( L_15 , V_29 [ V_33 ] . V_4 [ V_34 ] ) ;
}
} else {
if ( V_39 >= 2 ) {
for ( V_34 = 0 ; V_34 < V_29 [ V_33 ] . V_5 ; V_34 ++ )
F_13 ( L_15 , V_29 [ V_33 ] . V_4 [ V_34 ] ) ;
}
if ( V_2 -> V_37 . V_38 )
V_32 = F_5 ( V_2 , V_3 ,
V_29 [ V_33 ] . V_4 ,
V_29 [ V_33 ] . V_5 ) ;
else
V_32 = F_8 ( V_2 , V_3 ,
V_29 [ V_33 ] . V_4 ,
V_29 [ V_33 ] . V_5 ,
V_33 == V_30 - 1 ) ;
}
if ( V_32 < 0 )
goto V_40;
if ( V_39 >= 2 )
F_13 ( L_16 ) ;
}
return V_30 ;
V_40:
F_12 ( 2 , L_17 , V_32 ) ;
return V_32 ;
}
static inline unsigned long F_14 ( char * V_4 , int V_41 , int V_42 )
{
unsigned long V_43 = 0 ;
unsigned long V_44 = 0 ;
int V_5 = 0 ;
unsigned char V_45 ;
do {
if ( V_5 == V_41 ) {
V_45 = ( char ) V_5 ;
V_5 = - 1 ;
} else
V_45 = * V_4 ++ ;
V_44 = ( V_44 << 8 ) | V_45 ;
V_5 ++ ;
if ( ( V_5 & ( 32 / 8 - 1 ) ) == 0 )
V_43 = ( ( V_43 ^ V_44 ) * 0x9e370001UL ) ;
} while ( V_5 );
return ( V_43 >> ( 32 - V_42 ) ) & 0xffffffffUL ;
}
static int F_15 ( struct V_1 * V_2 , unsigned char * V_46 , int V_5 )
{
unsigned char V_4 , * V_47 = V_46 ;
struct V_48 * V_49 = ( void * ) V_46 ;
int V_33 , V_40 , V_50 = V_5 , V_51 ;
if ( V_2 -> V_52 == V_53 ||
V_2 -> V_52 == V_54 ||
V_2 -> V_52 == V_55 ) {
return 0 ;
}
V_2 -> V_56 . V_3 = 0xa0 >> 1 ;
V_40 = F_16 ( & V_2 -> V_56 , & V_4 , 0 ) ;
if ( V_40 < 0 ) {
F_17 ( L_18 ) ;
memset ( V_46 , 0 , V_5 ) ;
return - V_21 ;
}
V_4 = 0 ;
V_40 = F_18 ( & V_2 -> V_56 , & V_4 , 1 ) ;
if ( V_40 != 1 ) {
F_13 ( V_57 L_19 ,
V_2 -> V_58 , V_40 ) ;
return V_40 ;
}
while ( V_50 > 0 ) {
if ( V_50 > 16 )
V_51 = 16 ;
else
V_51 = V_50 ;
if ( V_51 !=
( V_40 = F_16 ( & V_2 -> V_56 , V_47 , V_51 ) ) ) {
F_13 ( V_59
L_20 ,
V_2 -> V_58 , V_40 ) ;
return V_40 ;
}
V_50 -= V_51 ;
V_47 += V_51 ;
}
for ( V_33 = 0 ; V_33 < V_5 ; V_33 ++ ) {
if ( 0 == ( V_33 % 16 ) )
F_13 ( V_57 L_21 , V_2 -> V_58 , V_33 ) ;
F_13 ( L_15 , V_46 [ V_33 ] ) ;
if ( 15 == ( V_33 % 16 ) )
F_13 ( L_16 ) ;
}
if ( V_49 -> V_60 == 0x9567eb1a )
V_2 -> V_43 = F_14 ( V_46 , V_5 , 32 ) ;
F_13 ( V_57 L_22 ,
V_2 -> V_58 , V_49 -> V_60 , V_2 -> V_43 ) ;
F_13 ( V_57 L_23 , V_2 -> V_58 ) ;
switch ( V_49 -> V_61 >> 4 & 0x3 ) {
case 0 :
F_13 ( V_57 L_24 , V_2 -> V_58 ) ;
break;
case 1 :
F_13 ( V_57 L_25 ,
V_2 -> V_58 ) ;
break;
case 2 :
F_13 ( V_57 L_26 ,
V_2 -> V_58 ) ;
break;
case 3 :
F_13 ( V_57 L_27 ,
V_2 -> V_58 ) ;
break;
}
if ( V_49 -> V_61 & 1 << 3 )
F_13 ( V_57 L_28 , V_2 -> V_58 ) ;
if ( V_49 -> V_61 & 1 << 2 )
F_13 ( V_57 L_29 , V_2 -> V_58 ) ;
switch ( V_49 -> V_61 & 0x3 ) {
case 0 :
F_13 ( V_57 L_30 , V_2 -> V_58 ) ;
break;
case 1 :
F_13 ( V_57 L_31 , V_2 -> V_58 ) ;
break;
case 2 :
F_13 ( V_57 L_32 , V_2 -> V_58 ) ;
break;
case 3 :
F_13 ( V_57 L_33 , V_2 -> V_58 ) ;
break;
}
F_13 ( V_57 L_34 ,
V_2 -> V_58 ,
V_49 -> V_62 ,
V_49 -> V_63 ,
V_49 -> V_64 ,
V_49 -> V_65 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_26 * V_66 )
{
return V_67 ;
}
void F_20 ( struct V_1 * V_2 )
{
T_2 V_68 [ 128 ] ;
unsigned char V_4 ;
int V_33 , V_32 ;
memset ( V_68 , 0 , F_21 ( V_68 ) ) ;
for ( V_33 = 0 ; V_33 < F_21 ( V_69 ) ; V_33 ++ ) {
V_2 -> V_56 . V_3 = V_33 ;
V_32 = F_16 ( & V_2 -> V_56 , & V_4 , 0 ) ;
if ( V_32 < 0 )
continue;
V_68 [ V_33 ] = V_33 ;
F_13 ( V_57 L_35 ,
V_2 -> V_58 , V_33 << 1 , V_69 [ V_33 ] ? V_69 [ V_33 ] : L_36 ) ;
}
V_2 -> V_70 = F_14 ( V_68 ,
F_21 ( V_68 ) , 32 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_71 ;
F_2 ( ! V_2 -> V_9 || ! V_2 -> V_12 ) ;
F_2 ( ! V_2 -> V_24 || ! V_2 -> V_25 ) ;
V_2 -> V_27 = V_72 ;
V_2 -> V_27 . V_2 . V_73 = & V_2 -> V_74 -> V_2 ;
strcpy ( V_2 -> V_27 . V_58 , V_2 -> V_58 ) ;
V_2 -> V_27 . V_31 = V_2 ;
F_23 ( & V_2 -> V_27 , & V_2 -> V_75 ) ;
V_71 = F_24 ( & V_2 -> V_27 ) ;
if ( V_71 < 0 ) {
F_17 ( L_37 ,
V_76 , V_71 ) ;
return V_71 ;
}
V_2 -> V_56 = V_77 ;
V_2 -> V_56 . V_78 = & V_2 -> V_27 ;
V_71 = F_15 ( V_2 , V_2 -> V_46 , sizeof( V_2 -> V_46 ) ) ;
if ( ( V_71 < 0 ) && ( V_71 != - V_21 ) ) {
F_17 ( L_38 ,
V_76 , V_71 ) ;
return V_71 ;
}
if ( V_79 )
F_20 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_27 ) ;
return 0 ;
}
