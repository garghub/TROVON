static void F_1 ( struct V_1 * V_2 ,
const T_1 V_3 [ 16 ] , T_1 V_4 [ 16 ] )
{
F_2 ( ( void * ) V_2 , V_4 , V_3 ) ;
}
static void * F_3 ( int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL )
goto V_9;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = ( void * ) F_5 ( L_1 , 0 , V_10 ) ;
if ( F_6 ( V_7 -> V_2 ) ) {
F_7 ( L_2 ) ;
V_7 -> V_2 = NULL ;
goto V_9;
}
return V_7 ;
V_9:
if ( V_7 ) {
if ( V_7 -> V_2 )
F_8 ( ( void * ) V_7 -> V_2 ) ;
F_9 ( V_7 ) ;
}
return NULL ;
}
static void F_10 ( void * V_7 )
{
struct V_6 * V_11 = V_7 ;
if ( V_11 && V_11 -> V_2 )
F_8 ( ( void * ) V_11 -> V_2 ) ;
F_9 ( V_7 ) ;
}
static inline void F_11 ( T_1 * V_12 , T_1 * V_13 , T_2 V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
V_12 [ V_15 ] ^= V_13 [ V_15 ] ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
T_1 * V_18 , T_2 V_19 , T_1 * V_20 , T_1 * V_21 ,
T_1 * V_22 )
{
T_1 * V_23 , V_24 = 0 ;
T_2 V_25 ;
T_3 V_26 ;
int V_27 , V_28 ;
T_1 V_29 [ 2 * V_30 ] ;
V_26 = F_13 ( V_17 -> V_31 ) ;
V_27 = ( ( V_26 & ( V_32 | V_33 ) ) ==
( V_32 | V_33 ) ) ;
V_28 = ( ( F_14 ( V_26 ) == V_34 ) &&
( F_15 ( V_26 ) & 0x80 ) ) ;
V_25 = 22 ;
if ( V_27 )
V_25 += 6 ;
if ( V_28 ) {
V_23 = ( T_1 * ) & V_17 -> V_35 ;
if ( V_27 )
V_23 += 6 ;
V_24 = * V_23 & 0x0f ;
V_25 += 2 ;
}
V_20 [ 0 ] = 0x59 ;
V_20 [ 1 ] = V_24 ;
memcpy ( V_20 + 2 , V_17 -> V_36 , V_37 ) ;
memcpy ( V_20 + 8 , V_18 , V_38 ) ;
V_20 [ 14 ] = ( V_19 >> 8 ) & 0xff ;
V_20 [ 15 ] = V_19 & 0xff ;
V_23 = ( T_1 * ) V_17 ;
V_29 [ 0 ] = 0 ;
V_29 [ 1 ] = V_25 & 0xff ;
V_29 [ 2 ] = V_23 [ 0 ] & 0x8f ;
V_29 [ 3 ] = V_23 [ 1 ] & 0xc7 ;
memcpy ( V_29 + 4 , V_17 -> V_39 , 3 * V_37 ) ;
V_23 = ( T_1 * ) & V_17 -> V_40 ;
V_29 [ 22 ] = V_23 [ 0 ] & 0x0f ;
V_29 [ 23 ] = 0 ;
memset ( V_29 + 24 , 0 , 8 ) ;
if ( V_27 )
memcpy ( V_29 + 24 , V_17 -> V_35 , V_37 ) ;
if ( V_28 ) {
V_29 [ V_27 ? 30 : 24 ] = V_24 ;
}
F_1 ( V_2 , V_20 , V_21 ) ;
F_11 ( V_21 , V_29 , V_30 ) ;
F_1 ( V_2 , V_21 , V_21 ) ;
F_11 ( V_21 , & V_29 [ V_30 ] , V_30 ) ;
F_1 ( V_2 , V_21 , V_21 ) ;
V_20 [ 0 ] &= 0x07 ;
V_20 [ 14 ] = V_20 [ 15 ] = 0 ;
F_1 ( V_2 , V_20 , V_22 ) ;
}
static int F_16 ( struct V_41 * V_42 , int V_43 , void * V_7 )
{
struct V_6 * V_44 = V_7 ;
int V_45 , V_15 ;
T_1 * V_23 ;
struct V_16 * V_17 ;
struct V_46 * V_47 = (struct V_46 * ) ( V_42 -> V_48 +
V_49 ) ;
if ( F_17 ( V_42 ) < V_50 ||
F_18 ( V_42 ) < V_51 ||
V_42 -> V_14 < V_43 )
return - 1 ;
V_45 = V_42 -> V_14 - V_43 ;
V_23 = F_19 ( V_42 , V_50 ) ;
memmove ( V_23 , V_23 + V_50 , V_43 ) ;
V_23 += V_43 ;
V_15 = V_38 - 1 ;
while ( V_15 >= 0 ) {
V_44 -> V_52 [ V_15 ] ++ ;
if ( V_44 -> V_52 [ V_15 ] != 0 )
break;
V_15 -- ;
}
* V_23 ++ = V_44 -> V_52 [ 5 ] ;
* V_23 ++ = V_44 -> V_52 [ 4 ] ;
* V_23 ++ = 0 ;
* V_23 ++ = ( V_44 -> V_5 << 6 ) | ( 1 << 5 ) ;
* V_23 ++ = V_44 -> V_52 [ 3 ] ;
* V_23 ++ = V_44 -> V_52 [ 2 ] ;
* V_23 ++ = V_44 -> V_52 [ 1 ] ;
* V_23 ++ = V_44 -> V_52 [ 0 ] ;
V_17 = (struct V_16 * ) V_42 -> V_53 ;
if ( ! V_47 -> V_54 ) {
int V_55 , V_56 , V_14 ;
T_1 * V_57 ;
T_1 * V_20 = V_44 -> V_58 ;
T_1 * V_12 = V_44 -> V_59 ;
T_1 * V_60 = V_44 -> V_61 ;
T_1 * V_22 = V_44 -> V_62 ;
V_57 = F_20 ( V_42 , V_51 ) ;
F_12 ( V_44 -> V_2 , V_17 , V_44 -> V_52 , V_45 ,
V_20 , V_12 , V_22 ) ;
V_55 = F_21 ( V_45 , V_30 ) ;
V_56 = V_45 % V_30 ;
for ( V_15 = 1 ; V_15 <= V_55 ; V_15 ++ ) {
V_14 = ( V_15 == V_55 && V_56 ) ? V_56 : V_30 ;
F_11 ( V_12 , V_23 , V_14 ) ;
F_1 ( V_44 -> V_2 , V_12 , V_12 ) ;
V_20 [ 14 ] = ( V_15 >> 8 ) & 0xff ;
V_20 [ 15 ] = V_15 & 0xff ;
F_1 ( V_44 -> V_2 , V_20 , V_60 ) ;
F_11 ( V_23 , V_60 , V_14 ) ;
V_23 += V_14 ;
}
for ( V_15 = 0 ; V_15 < V_51 ; V_15 ++ )
V_57 [ V_15 ] = V_12 [ V_15 ] ^ V_22 [ V_15 ] ;
}
return 0 ;
}
static int F_22 ( struct V_41 * V_42 , int V_43 , void * V_7 )
{
struct V_6 * V_44 = V_7 ;
T_1 V_63 , * V_23 ;
struct V_16 * V_17 ;
struct V_46 * V_47 = (struct V_46 * ) ( V_42 -> V_48 +
V_49 ) ;
T_1 V_18 [ 6 ] ;
if ( V_42 -> V_14 < V_43 + V_50 + V_51 ) {
V_44 -> V_64 ++ ;
return - 1 ;
}
V_17 = (struct V_16 * ) V_42 -> V_53 ;
V_23 = V_42 -> V_53 + V_43 ;
V_63 = V_23 [ 3 ] ;
if ( ! ( V_63 & ( 1 << 5 ) ) ) {
if ( F_23 () ) {
F_7 ( L_3 ,
V_17 -> V_36 ) ;
}
V_44 -> V_64 ++ ;
return - 2 ;
}
V_63 >>= 6 ;
if ( V_44 -> V_5 != V_63 ) {
F_7 ( L_4 ,
V_44 -> V_5 , V_63 , V_7 ) ;
return - 6 ;
}
if ( ! V_44 -> V_65 ) {
if ( F_23 () ) {
F_7 ( L_5 ,
V_17 -> V_36 , V_63 ) ;
}
return - 3 ;
}
V_18 [ 0 ] = V_23 [ 7 ] ;
V_18 [ 1 ] = V_23 [ 6 ] ;
V_18 [ 2 ] = V_23 [ 5 ] ;
V_18 [ 3 ] = V_23 [ 4 ] ;
V_18 [ 4 ] = V_23 [ 1 ] ;
V_18 [ 5 ] = V_23 [ 0 ] ;
V_23 += 8 ;
if ( memcmp ( V_18 , V_44 -> V_66 , V_38 ) <= 0 ) {
V_44 -> V_67 ++ ;
return - 4 ;
}
if ( ! V_47 -> V_54 ) {
T_2 V_45 = V_42 -> V_14 - V_43 - V_50 -
V_51 ;
T_1 * V_57 = V_42 -> V_53 + V_42 -> V_14 - V_51 ;
T_1 * V_20 = V_44 -> V_68 ;
T_1 * V_12 = V_44 -> V_69 ;
T_1 * V_13 = V_44 -> V_70 ;
int V_15 , V_55 , V_56 , V_14 ;
F_12 ( V_44 -> V_2 , V_17 , V_18 , V_45 , V_20 , V_13 , V_12 ) ;
F_11 ( V_57 , V_12 , V_51 ) ;
V_55 = F_21 ( V_45 , V_30 ) ;
V_56 = V_45 % V_30 ;
for ( V_15 = 1 ; V_15 <= V_55 ; V_15 ++ ) {
V_14 = ( V_15 == V_55 && V_56 ) ? V_56 : V_30 ;
V_20 [ 14 ] = ( V_15 >> 8 ) & 0xff ;
V_20 [ 15 ] = V_15 & 0xff ;
F_1 ( V_44 -> V_2 , V_20 , V_12 ) ;
F_11 ( V_23 , V_12 , V_14 ) ;
F_11 ( V_13 , V_23 , V_14 ) ;
F_1 ( V_44 -> V_2 , V_13 , V_13 ) ;
V_23 += V_14 ;
}
if ( memcmp ( V_57 , V_13 , V_51 ) != 0 ) {
if ( F_23 () ) {
F_7 ( L_6 ,
V_17 -> V_36 ) ;
}
V_44 -> V_71 ++ ;
return - 5 ;
}
memcpy ( V_44 -> V_66 , V_18 , V_38 ) ;
}
memmove ( V_42 -> V_53 + V_50 , V_42 -> V_53 , V_43 ) ;
F_24 ( V_42 , V_50 ) ;
F_25 ( V_42 , V_42 -> V_14 - V_51 ) ;
return V_63 ;
}
static int F_26 ( void * V_44 , int V_14 , T_1 * V_72 , void * V_7 )
{
struct V_6 * V_53 = V_7 ;
int V_63 ;
struct V_1 * V_2 = V_53 -> V_2 ;
V_63 = V_53 -> V_5 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_5 = V_63 ;
V_53 -> V_2 = V_2 ;
if ( V_14 == V_73 ) {
memcpy ( V_53 -> V_44 , V_44 , V_73 ) ;
V_53 -> V_65 = 1 ;
if ( V_72 ) {
V_53 -> V_66 [ 0 ] = V_72 [ 5 ] ;
V_53 -> V_66 [ 1 ] = V_72 [ 4 ] ;
V_53 -> V_66 [ 2 ] = V_72 [ 3 ] ;
V_53 -> V_66 [ 3 ] = V_72 [ 2 ] ;
V_53 -> V_66 [ 4 ] = V_72 [ 1 ] ;
V_53 -> V_66 [ 5 ] = V_72 [ 0 ] ;
}
F_27 ( ( void * ) V_53 -> V_2 , V_53 -> V_44 , V_73 ) ;
} else if ( V_14 == 0 )
V_53 -> V_65 = 0 ;
else
return - 1 ;
return 0 ;
}
static int F_28 ( void * V_44 , int V_14 , T_1 * V_72 , void * V_7 )
{
struct V_6 * V_53 = V_7 ;
if ( V_14 < V_73 )
return - 1 ;
if ( ! V_53 -> V_65 )
return 0 ;
memcpy ( V_44 , V_53 -> V_44 , V_73 ) ;
if ( V_72 ) {
V_72 [ 0 ] = V_53 -> V_52 [ 5 ] ;
V_72 [ 1 ] = V_53 -> V_52 [ 4 ] ;
V_72 [ 2 ] = V_53 -> V_52 [ 3 ] ;
V_72 [ 3 ] = V_53 -> V_52 [ 2 ] ;
V_72 [ 4 ] = V_53 -> V_52 [ 1 ] ;
V_72 [ 5 ] = V_53 -> V_52 [ 0 ] ;
}
return V_73 ;
}
static void F_29 ( struct V_74 * V_75 , void * V_7 )
{
struct V_6 * V_76 = V_7 ;
F_30 ( V_75 ,
L_7 ,
V_76 -> V_5 , V_76 -> V_65 ,
V_76 -> V_52 , V_76 -> V_66 ,
V_76 -> V_64 ,
V_76 -> V_67 ,
V_76 -> V_71 ) ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_77 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_77 ) ;
}
