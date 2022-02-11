static char * F_1 ( unsigned char V_1 )
{
switch ( V_1 ) {
case V_2 : return ( L_1 ) ;
case V_3 : return ( L_2 ) ;
case V_4 : return ( L_3 ) ;
case V_5 : return ( L_4 ) ;
case V_6 : return ( L_5 ) ;
case V_7 : return ( L_6 ) ;
case V_8 : return ( L_7 ) ;
case V_9 : return ( L_8 ) ;
case V_10 : return ( L_9 ) ;
case V_11 : return ( L_10 ) ;
case V_12 : return ( L_11 ) ;
case V_13 : return ( L_12 ) ;
case V_14 : return ( L_13 ) ;
case V_15 : return ( L_14 ) ;
}
return ( L_15 ) ;
}
static char * F_2 ( unsigned char V_16 )
{
static char V_17 [ 40 ] ;
strcpy ( V_17 , L_16 ) ;
if ( V_16 & V_18 )
strcat ( V_17 , L_17 ) ;
if ( V_16 & V_19 )
strcat ( V_17 , L_18 ) ;
if ( V_16 & V_20 )
strcat ( V_17 , L_19 ) ;
if ( V_16 & V_21 )
strcat ( V_17 , L_20 ) ;
if ( V_16 & V_22 )
strcat ( V_17 , L_21 ) ;
if ( V_16 & V_23 )
strcat ( V_17 , L_22 ) ;
strcat ( V_17 , L_23 ) ;
return V_17 ;
}
static unsigned int F_3 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
if ( V_25 -> V_27 != V_27 ) {
V_25 -> V_27 = V_27 ;
V_25 -> V_28 = 0 ;
}
V_25 -> V_1 = V_2 ;
V_25 -> V_29 = V_2 ;
V_25 -> V_30 = V_31 * 1000000 ;
V_25 -> V_32 = V_33 ;
return 3 ;
}
static void F_4 ( struct V_24 * V_25 , unsigned char V_34 )
{
V_25 -> V_35 [ 0 ] = 4 ;
V_25 -> V_35 [ 1 ] = V_25 -> V_36 [ 1 ] | 4 ;
V_25 -> V_35 [ 2 ] = V_25 -> V_36 [ 2 ] ;
V_25 -> V_35 [ 3 ] = V_25 -> V_36 [ 3 ] ;
V_25 -> V_35 [ 4 ] = V_34 ;
V_25 -> V_37 = 5 ;
}
static int F_5 ( struct V_24 * V_25 ,
unsigned char * V_38 ,
unsigned int V_39 )
{
unsigned int V_40 ;
if ( V_39 < 2 )
return V_41 ;
if ( V_39 > V_42 )
return V_43 ;
if ( V_25 -> V_1 == V_13 )
return V_44 ;
if ( V_25 -> V_1 != V_2 )
return V_45 ;
if ( V_46 & V_47 ) {
F_6 ( V_48 L_24 ) ;
F_6 ( V_48 L_25 , V_39 - 2 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_6 ( L_26 , V_38 [ V_40 ] ) ;
F_6 ( L_27 ) ;
}
V_25 -> V_36 [ 0 ] = V_39 + 1 ;
V_25 -> V_36 [ 1 ] = * V_38 ;
V_25 -> V_36 [ 2 ] = V_25 -> V_28 ++ ;
memcpy ( V_25 -> V_36 + 3 , V_38 + 1 , V_39 - 1 ) ;
V_25 -> V_49 = V_39 + 2 ;
V_25 -> V_50 = 0 ;
V_25 -> V_51 = 0 ;
V_25 -> V_52 = 0 ;
V_25 -> V_1 = V_3 ;
V_25 -> V_53 = V_25 -> V_30 ;
F_4 ( V_25 , V_54 ) ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 ,
unsigned char * V_38 ,
unsigned int V_55 )
{
int V_40 , V_56 ;
V_56 = V_25 -> V_37 - 2 ;
if ( V_56 < 3 || V_56 > V_42 ) {
F_4 ( V_25 , V_54 ) ;
V_56 = 3 ;
}
V_38 [ 0 ] = V_25 -> V_35 [ 1 ] ;
V_38 [ 1 ] = V_25 -> V_35 [ 3 ] ;
if ( V_55 < V_56 || V_25 -> V_52 ) {
V_38 [ 2 ] = V_57 ;
V_56 = 3 ;
} else
memcpy ( V_38 + 2 , V_25 -> V_35 + 4 , V_56 - 2 ) ;
if ( V_46 & V_47 ) {
F_6 ( V_48 L_28 , V_56 ) ;
for ( V_40 = 0 ; V_40 < V_56 ; V_40 ++ )
F_6 ( L_26 , V_38 [ V_40 ] ) ;
F_6 ( L_27 ) ;
}
return V_56 ;
}
static void F_8 ( struct V_24 * V_25 )
{
if ( V_46 )
F_6 ( V_48 L_29 ,
F_2 ( V_58 ) ) ;
if ( V_58 & V_19 )
F_9 ( V_19 ) ;
F_9 ( V_59 ) ;
F_9 ( V_21 ) ;
F_10 ( V_60 ) ;
}
static void F_11 ( struct V_24 * V_25 )
{
int V_40 , V_39 ;
if ( ! ( V_58 & V_22 ) )
return;
F_9 ( V_19 ) ;
F_9 ( V_22 ) ;
V_58 ;
F_9 ( V_22 ) ;
F_9 ( V_61 ) ;
if ( V_46 )
F_6 ( V_48 L_30 ,
F_2 ( V_58 ) ) ;
V_39 = V_62 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
V_62 ;
F_9 ( V_19 ) ;
if ( V_46 )
F_6 ( L_31 , V_39 + 1 ) ;
}
static inline void F_12 ( struct V_24 * V_25 )
{
int V_40 ;
if ( V_46 & V_47 ) {
F_6 ( V_48 L_32 ,
V_25 -> V_49 , V_25 -> V_28 ) ;
for ( V_40 = 0 ; V_40 < V_25 -> V_49 ; V_40 ++ )
F_6 ( L_26 , V_25 -> V_36 [ V_40 ] ) ;
F_6 ( L_27 ) ;
}
for ( V_40 = 0 ; V_40 < V_25 -> V_49 ; V_40 ++ )
F_13 ( V_25 -> V_36 [ V_40 ] ) ;
}
static inline int F_14 ( struct V_24 * V_25 )
{
unsigned char V_40 ;
V_25 -> V_35 [ 0 ] = V_62 ;
V_25 -> V_37 = V_25 -> V_35 [ 0 ] ;
if ( V_25 -> V_37 < 4 || V_25 -> V_37 >= V_42 ) {
if ( V_46 & V_47 )
F_6 ( V_48 L_33 ,
V_25 -> V_37 ) ;
V_25 -> V_52 = 1 ;
return 1 ;
}
for ( V_40 = 1 ; V_40 <= V_25 -> V_37 ; V_40 ++ )
V_25 -> V_35 [ V_40 ] = V_62 ;
V_25 -> V_37 ++ ;
if ( V_46 & V_47 ) {
int V_63 = V_25 -> V_37 ;
F_6 ( V_48 L_34 ,
V_63 , V_25 -> V_35 [ 2 ] ) ;
if ( V_63 > 16 )
V_63 = 16 ;
for ( V_40 = 0 ; V_40 < V_63 ; V_40 ++ )
F_6 ( V_64 L_26 , V_25 -> V_35 [ V_40 ] ) ;
F_6 ( V_64 L_35 , V_25 -> V_37 == V_63 ? L_36 : L_37 ) ;
}
if ( ( V_25 -> V_35 [ 3 ] == V_25 -> V_36 [ 3 ] ) &&
( V_25 -> V_35 [ 2 ] == V_25 -> V_36 [ 2 ] ) &&
( ( V_25 -> V_35 [ 1 ] & 0xF8 ) == ( V_25 -> V_36 [ 1 ] & 0xF8 ) ) )
return 1 ;
if ( V_46 & V_47 )
F_6 ( V_48 L_38
L_39 ,
V_25 -> V_36 [ 1 ] | 0x04 , V_25 -> V_36 [ 2 ] , V_25 -> V_36 [ 3 ] ,
V_25 -> V_35 [ 1 ] , V_25 -> V_35 [ 2 ] , V_25 -> V_35 [ 3 ] ) ;
return 0 ;
}
static enum V_65 F_15 ( struct V_24 * V_25 ,
unsigned char V_16 ,
unsigned char V_66 )
{
char * V_67 ;
V_25 -> V_53 = V_25 -> V_30 ;
switch ( V_66 ) {
case V_68 :
V_67 = L_40 ;
break;
default:
V_67 = L_41 ;
break;
}
F_6 ( V_48 L_42 ,
V_67 , V_69 , V_70 ) ;
( V_25 -> V_50 ) ++ ;
if ( V_25 -> V_50 < V_25 -> V_32 ) {
F_6 ( L_43 ,
V_25 -> V_32 - V_25 -> V_50 ) ;
V_25 -> V_1 = V_12 ;
return V_71 ;
}
F_6 ( V_48 L_44 ,
V_25 -> V_32 ) ;
if ( ! V_25 -> V_51 )
F_6 ( V_72 L_45 ) ;
else if ( V_25 -> V_28 <= ( unsigned char ) ( V_25 -> V_32 & 0xFF ) ) {
F_6 ( V_48 L_46 ) ;
V_25 -> V_1 = V_9 ;
return V_71 ;
}
V_25 -> V_1 = V_2 ;
switch ( V_66 ) {
case V_68 :
if ( V_16 & V_18 ) {
V_66 = V_44 ;
V_25 -> V_1 = V_13 ;
}
break;
default:
break;
}
F_4 ( V_25 , V_66 ) ;
return V_73 ;
}
static enum V_65 F_16 ( struct V_24 * V_25 , long time )
{
unsigned char V_16 , V_74 [ 8 ] ;
static enum V_75 V_76 = V_77 ;
int V_40 ;
V_16 = V_58 ;
V_25 -> V_51 |= V_16 ;
if ( ( V_46 & V_78 ) && ( V_25 -> V_1 != V_76 ) ) {
F_6 ( V_48 L_47 ,
V_69 ,
V_70 ,
V_25 -> V_53 ,
time ) ;
V_76 = V_25 -> V_1 ;
}
if ( ( V_25 -> V_1 < V_4 ) && ( V_16 & V_22 ) ) {
F_11 ( V_25 ) ;
F_17 ( V_79 ) ;
}
if ( ( V_25 -> V_1 != V_2 ) &&
( V_25 -> V_1 < V_77 ) ) {
V_25 -> V_53 -= time ;
if ( ( V_25 -> V_53 < 0 ) && ( V_25 -> V_1 < V_9 ) )
return F_15 ( V_25 ,
V_16 ,
V_68 ) ;
}
switch ( V_25 -> V_1 ) {
case V_2 :
if ( V_16 & V_21 ) {
F_9 ( V_21 ) ;
return V_80 ;
}
if ( V_16 & V_19 )
F_9 ( V_19 ) ;
if ( ! V_25 -> V_81 )
F_18 ( V_14 ,
V_71 ) ;
V_25 -> V_53 = V_25 -> V_30 ;
F_17 ( V_82 ) ;
case V_3 :
if ( V_16 & ( V_18 | V_23 ) )
F_17 ( V_79 ) ;
if ( V_58 & V_19 )
F_9 ( V_19 ) ;
F_18 ( V_4 ,
V_71 ) ;
case V_4 :
if ( V_16 & V_19 )
F_9 ( V_19 ) ;
F_9 ( V_59 ) ;
F_12 ( V_25 ) ;
F_9 ( V_23 ) ;
F_18 ( V_5 ,
V_71 ) ;
case V_5 :
if ( V_16 & ( V_18 | V_23 ) )
F_17 ( V_79 ) ;
F_18 ( V_6 ,
V_71 ) ;
case V_6 :
if ( ! ( V_16 & V_22 ) )
F_17 ( V_79 ) ;
F_9 ( V_19 ) ;
F_9 ( V_22 ) ;
F_18 ( V_7 ,
V_71 ) ;
case V_7 :
if ( V_16 & V_22 ) {
F_9 ( V_22 ) ;
F_17 ( V_79 ) ;
}
F_18 ( V_8 ,
V_71 ) ;
case V_8 :
if ( ! ( V_16 & V_19 ) )
F_9 ( V_19 ) ;
F_9 ( V_61 ) ;
V_40 = F_14 ( V_25 ) ;
F_9 ( V_19 ) ;
if ( ! V_40 )
F_18 ( V_6 ,
V_71 ) ;
V_25 -> V_1 = V_25 -> V_29 ;
return V_25 -> V_1 == V_2 ?
V_73 :
V_71 ;
case V_13 :
if ( ! ( V_16 & V_18 ) ) {
F_8 ( V_25 ) ;
F_3 ( V_25 , V_25 -> V_27 ) ;
}
return V_79 ;
case V_9 :
F_8 ( V_25 ) ;
F_11 ( V_25 ) ;
F_18 ( V_10 ,
V_79 ) ;
case V_10 :
F_9 ( V_59 ) ;
F_13 ( 3 ) ;
F_13 ( 0x18 ) ;
F_13 ( 42 ) ;
F_13 ( 3 ) ;
F_9 ( V_23 ) ;
V_25 -> V_53 = V_83 * 1000000 ;
F_18 ( V_11 ,
V_79 ) ;
case V_11 :
if ( V_25 -> V_53 > 0 )
return V_79 ;
F_11 ( V_25 ) ;
F_18 ( V_12 ,
V_79 ) ;
case V_12 :
V_25 -> V_37 = 0 ;
V_25 -> V_51 = 0 ;
V_25 -> V_53 = V_25 -> V_30 ;
F_18 ( V_3 ,
V_79 ) ;
case V_14 :
V_25 -> V_81 = 1 ;
{
unsigned char V_84 [] = { 0x18 , 0x36 } ;
V_25 -> V_1 = V_2 ;
F_5 ( V_25 , V_84 , sizeof( V_84 ) ) ;
}
V_25 -> V_29 = V_15 ;
F_18 ( V_3 ,
V_79 ) ;
case V_15 :
V_40 = F_7 ( V_25 , V_74 , sizeof( V_74 ) ) ;
F_3 ( V_25 , V_25 -> V_27 ) ;
if ( ( V_40 == 8 ) && ! V_74 [ 2 ] ) {
V_25 -> V_81 = V_74 [ 3 ] ;
V_25 -> V_30 = V_74 [ 6 ] * 1000000 ;
V_25 -> V_32 = V_74 [ 7 ] ;
} else
F_6 ( V_48 L_48 ) ;
if ( ! V_25 -> V_81 )
V_25 -> V_81 = 1 ;
F_6 ( V_48 L_49 ,
V_25 -> V_30 / 1000000L , V_25 -> V_32 ) ;
V_25 -> V_53 = V_25 -> V_30 ;
return V_71 ;
default:
return F_15 ( V_25 ,
V_16 ,
V_54 ) ;
}
return V_79 ;
}
static int F_19 ( struct V_24 * V_25 )
{
if ( ( V_58 == 0xFF ) && ( V_85 == 0xFF ) )
return 1 ;
F_8 ( V_25 ) ;
return 0 ;
}
static void F_20 ( struct V_24 * V_25 )
{
}
static int F_21 ( void )
{
return sizeof( struct V_24 ) ;
}
