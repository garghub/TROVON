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
V_25 -> V_30 = V_31 * V_32 ;
V_25 -> V_33 = V_34 ;
return 3 ;
}
static void F_4 ( struct V_24 * V_25 , unsigned char V_35 )
{
V_25 -> V_36 [ 0 ] = 4 ;
V_25 -> V_36 [ 1 ] = V_25 -> V_37 [ 1 ] | 4 ;
V_25 -> V_36 [ 2 ] = V_25 -> V_37 [ 2 ] ;
V_25 -> V_36 [ 3 ] = V_25 -> V_37 [ 3 ] ;
V_25 -> V_36 [ 4 ] = V_35 ;
V_25 -> V_38 = 5 ;
}
static int F_5 ( struct V_24 * V_25 ,
unsigned char * V_39 ,
unsigned int V_40 )
{
unsigned int V_41 ;
if ( V_40 < 2 )
return V_42 ;
if ( V_40 > V_43 )
return V_44 ;
if ( V_25 -> V_1 == V_13 )
return V_45 ;
if ( V_25 -> V_1 != V_2 )
return V_46 ;
if ( V_47 & V_48 ) {
F_6 ( V_49 L_24 ) ;
F_6 ( V_49 L_25 , V_40 - 2 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
F_6 ( L_26 , V_39 [ V_41 ] ) ;
F_6 ( L_27 ) ;
}
V_25 -> V_37 [ 0 ] = V_40 + 1 ;
V_25 -> V_37 [ 1 ] = * V_39 ;
V_25 -> V_37 [ 2 ] = V_25 -> V_28 ++ ;
memcpy ( V_25 -> V_37 + 3 , V_39 + 1 , V_40 - 1 ) ;
V_25 -> V_50 = V_40 + 2 ;
V_25 -> V_51 = 0 ;
V_25 -> V_52 = 0 ;
V_25 -> V_53 = 0 ;
V_25 -> V_1 = V_3 ;
V_25 -> V_54 = V_25 -> V_30 ;
F_4 ( V_25 , V_55 ) ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 ,
unsigned char * V_39 ,
unsigned int V_56 )
{
int V_41 , V_57 ;
V_57 = V_25 -> V_38 - 2 ;
if ( V_57 < 3 || V_57 > V_43 ) {
F_4 ( V_25 , V_55 ) ;
V_57 = 3 ;
}
V_39 [ 0 ] = V_25 -> V_36 [ 1 ] ;
V_39 [ 1 ] = V_25 -> V_36 [ 3 ] ;
if ( V_56 < V_57 || V_25 -> V_53 ) {
V_39 [ 2 ] = V_58 ;
V_57 = 3 ;
} else
memcpy ( V_39 + 2 , V_25 -> V_36 + 4 , V_57 - 2 ) ;
if ( V_47 & V_48 ) {
F_6 ( V_49 L_28 , V_57 ) ;
for ( V_41 = 0 ; V_41 < V_57 ; V_41 ++ )
F_6 ( L_26 , V_39 [ V_41 ] ) ;
F_6 ( L_27 ) ;
}
return V_57 ;
}
static void F_8 ( struct V_24 * V_25 )
{
if ( V_47 )
F_6 ( V_49 L_29 ,
F_2 ( V_59 ) ) ;
if ( V_59 & V_19 )
F_9 ( V_19 ) ;
F_9 ( V_60 ) ;
F_9 ( V_21 ) ;
F_10 ( V_61 ) ;
}
static void F_11 ( struct V_24 * V_25 )
{
int V_41 , V_40 ;
if ( ! ( V_59 & V_22 ) )
return;
F_9 ( V_19 ) ;
F_9 ( V_22 ) ;
V_59 ;
F_9 ( V_22 ) ;
F_9 ( V_62 ) ;
if ( V_47 )
F_6 ( V_49 L_30 ,
F_2 ( V_59 ) ) ;
V_40 = V_63 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
V_63 ;
F_9 ( V_19 ) ;
if ( V_47 )
F_6 ( L_31 , V_40 + 1 ) ;
}
static inline void F_12 ( struct V_24 * V_25 )
{
int V_41 ;
if ( V_47 & V_48 ) {
F_6 ( V_49 L_32 ,
V_25 -> V_50 , V_25 -> V_28 ) ;
for ( V_41 = 0 ; V_41 < V_25 -> V_50 ; V_41 ++ )
F_6 ( L_26 , V_25 -> V_37 [ V_41 ] ) ;
F_6 ( L_27 ) ;
}
for ( V_41 = 0 ; V_41 < V_25 -> V_50 ; V_41 ++ )
F_13 ( V_25 -> V_37 [ V_41 ] ) ;
}
static inline int F_14 ( struct V_24 * V_25 )
{
unsigned int V_41 ;
V_25 -> V_36 [ 0 ] = V_63 ;
V_25 -> V_38 = V_25 -> V_36 [ 0 ] ;
if ( V_25 -> V_38 < 4 || V_25 -> V_38 >= V_43 ) {
if ( V_47 & V_48 )
F_6 ( V_49 L_33 ,
V_25 -> V_38 ) ;
V_25 -> V_53 = 1 ;
return 1 ;
}
for ( V_41 = 1 ; V_41 <= V_25 -> V_38 ; V_41 ++ )
V_25 -> V_36 [ V_41 ] = V_63 ;
V_25 -> V_38 ++ ;
if ( V_47 & V_48 ) {
int V_64 = V_25 -> V_38 ;
F_6 ( V_49 L_34 ,
V_64 , V_25 -> V_36 [ 2 ] ) ;
if ( V_64 > 16 )
V_64 = 16 ;
for ( V_41 = 0 ; V_41 < V_64 ; V_41 ++ )
F_6 ( V_65 L_26 , V_25 -> V_36 [ V_41 ] ) ;
F_6 ( V_65 L_35 , V_25 -> V_38 == V_64 ? L_36 : L_37 ) ;
}
if ( ( V_25 -> V_36 [ 3 ] == V_25 -> V_37 [ 3 ] ) &&
( V_25 -> V_36 [ 2 ] == V_25 -> V_37 [ 2 ] ) &&
( ( V_25 -> V_36 [ 1 ] & 0xF8 ) == ( V_25 -> V_37 [ 1 ] & 0xF8 ) ) )
return 1 ;
if ( V_47 & V_48 )
F_6 ( V_49 L_38
L_39 ,
V_25 -> V_37 [ 1 ] | 0x04 , V_25 -> V_37 [ 2 ] , V_25 -> V_37 [ 3 ] ,
V_25 -> V_36 [ 1 ] , V_25 -> V_36 [ 2 ] , V_25 -> V_36 [ 3 ] ) ;
return 0 ;
}
static enum V_66 F_15 ( struct V_24 * V_25 ,
unsigned char V_16 ,
unsigned char V_67 )
{
char * V_68 ;
V_25 -> V_54 = V_25 -> V_30 ;
switch ( V_67 ) {
case V_69 :
V_68 = L_40 ;
break;
default:
V_68 = L_41 ;
break;
}
F_6 ( V_49 L_42 ,
V_68 , V_70 , V_71 ) ;
( V_25 -> V_51 ) ++ ;
if ( V_25 -> V_51 < V_25 -> V_33 ) {
F_6 ( L_43 ,
V_25 -> V_33 - V_25 -> V_51 ) ;
V_25 -> V_1 = V_12 ;
return V_72 ;
}
F_6 ( V_49 L_44 ,
V_25 -> V_33 ) ;
if ( ! V_25 -> V_52 )
F_6 ( V_73 L_45 ) ;
else if ( V_25 -> V_28 <= ( unsigned char ) ( V_25 -> V_33 & 0xFF ) ) {
F_6 ( V_49 L_46 ) ;
V_25 -> V_1 = V_9 ;
return V_72 ;
}
V_25 -> V_1 = V_2 ;
switch ( V_67 ) {
case V_69 :
if ( V_16 & V_18 ) {
V_67 = V_45 ;
V_25 -> V_1 = V_13 ;
}
break;
default:
break;
}
F_4 ( V_25 , V_67 ) ;
return V_74 ;
}
static enum V_66 F_16 ( struct V_24 * V_25 , long time )
{
unsigned char V_16 , V_75 [ 8 ] ;
static enum V_76 V_77 = V_78 ;
int V_41 ;
V_16 = V_59 ;
V_25 -> V_52 |= V_16 ;
if ( ( V_47 & V_79 ) && ( V_25 -> V_1 != V_77 ) ) {
F_6 ( V_49 L_47 ,
V_70 ,
V_71 ,
V_25 -> V_54 ,
time ) ;
V_77 = V_25 -> V_1 ;
}
if ( ( V_25 -> V_1 < V_4 ) && ( V_16 & V_22 ) ) {
F_11 ( V_25 ) ;
F_17 ( V_80 ) ;
}
if ( ( V_25 -> V_1 != V_2 ) &&
( V_25 -> V_1 < V_78 ) ) {
V_25 -> V_54 -= time ;
if ( ( V_25 -> V_54 < 0 ) && ( V_25 -> V_1 < V_9 ) )
return F_15 ( V_25 ,
V_16 ,
V_69 ) ;
}
switch ( V_25 -> V_1 ) {
case V_2 :
if ( V_16 & V_21 ) {
F_9 ( V_21 ) ;
return V_81 ;
}
if ( V_16 & V_19 )
F_9 ( V_19 ) ;
if ( ! V_25 -> V_82 )
F_18 ( V_14 ,
V_72 ) ;
V_25 -> V_54 = V_25 -> V_30 ;
F_17 ( V_83 ) ;
case V_3 :
if ( V_16 & ( V_18 | V_23 ) )
F_17 ( V_80 ) ;
if ( V_59 & V_19 )
F_9 ( V_19 ) ;
F_18 ( V_4 ,
V_72 ) ;
case V_4 :
if ( V_16 & V_19 )
F_9 ( V_19 ) ;
F_9 ( V_60 ) ;
F_12 ( V_25 ) ;
F_9 ( V_23 ) ;
F_18 ( V_5 ,
V_72 ) ;
case V_5 :
if ( V_16 & ( V_18 | V_23 ) )
F_17 ( V_80 ) ;
F_18 ( V_6 ,
V_72 ) ;
case V_6 :
if ( ! ( V_16 & V_22 ) )
F_17 ( V_80 ) ;
F_9 ( V_19 ) ;
F_9 ( V_22 ) ;
F_18 ( V_7 ,
V_72 ) ;
case V_7 :
if ( V_16 & V_22 ) {
F_9 ( V_22 ) ;
F_17 ( V_80 ) ;
}
F_18 ( V_8 ,
V_72 ) ;
case V_8 :
if ( ! ( V_16 & V_19 ) )
F_9 ( V_19 ) ;
F_9 ( V_62 ) ;
V_41 = F_14 ( V_25 ) ;
F_9 ( V_19 ) ;
if ( ! V_41 )
F_18 ( V_6 ,
V_72 ) ;
V_25 -> V_1 = V_25 -> V_29 ;
return V_25 -> V_1 == V_2 ?
V_74 :
V_72 ;
case V_13 :
if ( ! ( V_16 & V_18 ) ) {
F_8 ( V_25 ) ;
F_3 ( V_25 , V_25 -> V_27 ) ;
}
return V_80 ;
case V_9 :
F_8 ( V_25 ) ;
F_11 ( V_25 ) ;
F_18 ( V_10 ,
V_80 ) ;
case V_10 :
F_9 ( V_60 ) ;
F_13 ( 3 ) ;
F_13 ( 0x18 ) ;
F_13 ( 42 ) ;
F_13 ( 3 ) ;
F_9 ( V_23 ) ;
V_25 -> V_54 = V_84 * V_32 ;
F_18 ( V_11 ,
V_80 ) ;
case V_11 :
if ( V_25 -> V_54 > 0 )
return V_80 ;
F_11 ( V_25 ) ;
F_18 ( V_12 ,
V_80 ) ;
case V_12 :
V_25 -> V_38 = 0 ;
V_25 -> V_52 = 0 ;
V_25 -> V_54 = V_25 -> V_30 ;
F_18 ( V_3 ,
V_80 ) ;
case V_14 :
V_25 -> V_82 = 1 ;
{
unsigned char V_85 [] = { 0x18 , 0x36 } ;
V_25 -> V_1 = V_2 ;
F_5 ( V_25 , V_85 , sizeof( V_85 ) ) ;
}
V_25 -> V_29 = V_15 ;
F_18 ( V_3 ,
V_80 ) ;
case V_15 :
V_41 = F_7 ( V_25 , V_75 , sizeof( V_75 ) ) ;
F_3 ( V_25 , V_25 -> V_27 ) ;
if ( ( V_41 == 8 ) && ! V_75 [ 2 ] ) {
V_25 -> V_82 = V_75 [ 3 ] ;
V_25 -> V_30 = V_75 [ 6 ] * V_32 ;
V_25 -> V_33 = V_75 [ 7 ] ;
} else
F_6 ( V_49 L_48 ) ;
if ( ! V_25 -> V_82 )
V_25 -> V_82 = 1 ;
F_6 ( V_49 L_49 ,
V_25 -> V_30 / V_32 , V_25 -> V_33 ) ;
V_25 -> V_54 = V_25 -> V_30 ;
return V_72 ;
default:
return F_15 ( V_25 ,
V_16 ,
V_55 ) ;
}
return V_80 ;
}
static int F_19 ( struct V_24 * V_25 )
{
if ( ( V_59 == 0xFF ) && ( V_86 == 0xFF ) )
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
