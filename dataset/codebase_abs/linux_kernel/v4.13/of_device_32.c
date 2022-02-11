static int F_1 ( struct V_1 * V_2 )
{
if ( ! strcmp ( V_2 -> type , L_1 ) || ! strcmp ( V_2 -> type , L_2 ) ) {
if ( ! F_2 ( V_2 , L_3 , NULL ) )
return 0 ;
return 1 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
int * V_3 , int * V_4 )
{
if ( V_3 )
* V_3 = 3 ;
if ( V_4 )
* V_4 = 2 ;
}
static int F_4 ( T_1 * V_5 , const T_1 * V_6 ,
int V_7 , int V_8 , int V_9 )
{
T_1 V_10 [ V_11 ] ;
int V_12 ;
if ( ( V_5 [ 0 ] ^ V_6 [ 0 ] ) & 0x03000000 )
return - V_13 ;
if ( F_5 ( V_5 + 1 , V_6 + 1 , V_6 + V_7 + V_9 ,
V_7 - 1 , V_8 ) )
return - V_13 ;
memcpy ( V_10 , V_6 + V_7 , V_9 * 4 ) ;
for ( V_12 = 0 ; V_12 < V_7 - 1 ; V_12 ++ )
V_10 [ V_9 - 1 - V_12 ] +=
( V_5 [ V_7 - 1 - V_12 ] -
V_6 [ V_7 - 1 - V_12 ] ) ;
memcpy ( V_5 , V_10 , V_9 * 4 ) ;
return 0 ;
}
static unsigned long F_6 ( const T_1 * V_5 , unsigned long V_14 )
{
T_1 V_15 = V_5 [ 0 ] ;
V_14 = 0 ;
switch( ( V_15 >> 24 ) & 0x03 ) {
case 0x01 :
V_14 |= V_16 ;
break;
case 0x02 :
case 0x03 :
V_14 |= V_17 ;
break;
}
if ( V_15 & 0x40000000 )
V_14 |= V_18 ;
return V_14 ;
}
static unsigned long F_7 ( const T_1 * V_5 , unsigned long V_14 )
{
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return ! strcmp ( V_2 -> type , L_4 ) ;
}
static void F_9 ( struct V_1 * V_19 ,
int * V_3 , int * V_4 )
{
if ( V_3 )
* V_3 = 1 ;
if ( V_4 )
* V_4 = 1 ;
}
static int F_10 ( T_1 * V_5 , const T_1 * V_6 ,
int V_7 , int V_8 , int V_9 )
{
return F_11 ( V_5 , V_6 , V_7 , V_8 , V_9 ) ;
}
static unsigned long F_12 ( const T_1 * V_5 ,
unsigned long V_14 )
{
return V_17 ;
}
static struct V_20 * F_13 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_14 ( V_21 ) ; V_12 ++ )
if ( ! V_21 [ V_12 ] . V_22 || V_21 [ V_12 ] . V_22 ( V_2 ) )
return & V_21 [ V_12 ] ;
F_15 () ;
return NULL ;
}
static int T_2 F_16 ( struct V_1 * V_23 ,
struct V_20 * V_24 ,
struct V_20 * V_25 ,
T_1 * V_5 ,
int V_7 , int V_8 , int V_9 )
{
const T_1 * V_26 ;
unsigned int V_27 ;
int V_28 ;
V_26 = F_17 ( V_23 , L_3 , & V_27 ) ;
if ( V_26 == NULL || V_27 == 0 ) {
T_1 V_10 [ V_11 ] ;
int V_12 ;
memset ( V_10 , 0 , V_9 * 4 ) ;
for ( V_12 = 0 ; V_12 < V_7 ; V_12 ++ )
V_10 [ V_9 - 1 - V_12 ] =
V_5 [ V_7 - 1 - V_12 ] ;
memcpy ( V_5 , V_10 , V_9 * 4 ) ;
return 0 ;
}
V_27 /= 4 ;
V_28 = V_7 + V_9 + V_8 ;
for (; V_27 >= V_28 ; V_27 -= V_28 , V_26 += V_28 ) {
if ( ! V_24 -> V_29 ( V_5 , V_26 , V_7 , V_8 , V_9 ) )
return 0 ;
}
return 1 ;
}
static int T_2 F_18 ( struct V_1 * V_30 )
{
if ( F_2 ( V_30 , L_3 , NULL ) != NULL )
return 0 ;
if ( ! strcmp ( V_30 -> V_31 , L_5 ) ||
! strcmp ( V_30 -> V_31 , L_6 ) ||
! strcmp ( V_30 -> V_31 , L_7 ) ||
! strcmp ( V_30 -> V_31 , L_8 ) )
return 0 ;
return 1 ;
}
static void T_2 F_19 ( struct V_32 * V_33 ,
struct V_34 * V_23 )
{
struct V_32 * V_35 ;
struct V_20 * V_24 ;
int V_7 , V_8 ;
int V_36 , V_37 ;
const void * V_38 ;
if ( ! V_23 )
return;
V_35 = F_20 ( V_23 ) ;
V_24 = F_13 ( V_35 -> V_39 . V_40 ) ;
V_24 -> V_41 ( V_33 -> V_39 . V_40 , & V_7 , & V_8 ) ;
V_38 = F_17 ( V_33 -> V_39 . V_40 , V_24 -> V_42 , & V_37 ) ;
if ( ! V_38 || V_37 == 0 )
return;
V_37 /= 4 ;
V_37 /= V_7 + V_8 ;
V_33 -> V_43 = V_33 -> V_44 . V_43 ;
V_33 -> V_45 = V_37 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
struct V_43 * V_46 = & V_33 -> V_43 [ V_36 ] ;
T_1 V_5 [ V_11 ] ;
const T_1 * V_47 = ( V_38 + ( V_36 * ( ( V_7 + V_8 ) * 4 ) ) ) ;
struct V_1 * V_48 = V_33 -> V_39 . V_40 ;
struct V_1 * V_30 = V_35 -> V_39 . V_40 ;
struct V_20 * V_25 , * V_49 ;
T_3 V_50 , V_10 = V_51 ;
unsigned long V_14 ;
int V_52 , V_53 ;
int V_9 , V_54 ;
V_50 = F_21 ( V_47 + V_7 , V_8 ) ;
memcpy ( V_5 , V_47 , V_7 * 4 ) ;
V_14 = V_24 -> V_55 ( V_47 , 0 ) ;
if ( F_18 ( V_30 ) ) {
V_10 = F_21 ( V_5 , V_7 ) ;
goto V_56;
}
V_52 = V_7 ;
V_53 = V_8 ;
V_49 = V_24 ;
while ( 1 ) {
V_48 = V_30 ;
V_30 = V_48 -> V_23 ;
if ( ! V_30 ) {
V_10 = F_21 ( V_5 , V_52 ) ;
break;
}
V_25 = F_13 ( V_30 ) ;
V_25 -> V_41 ( V_48 , & V_9 , & V_54 ) ;
if ( F_16 ( V_48 , V_49 , V_25 , V_5 ,
V_52 , V_53 , V_9 ) )
break;
V_14 = V_25 -> V_55 ( V_5 , V_14 ) ;
V_52 = V_9 ;
V_53 = V_54 ;
V_49 = V_25 ;
}
V_56:
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
if ( V_57 )
F_22 ( L_9 ,
V_33 -> V_39 . V_40 -> V_58 , V_36 ,
V_10 ) ;
if ( V_10 != V_51 ) {
V_46 -> V_59 = V_10 & 0xffffffff ;
V_46 -> V_60 = V_10 + V_50 - 1 ;
V_46 -> V_14 = V_14 | ( ( V_10 >> 32ULL ) & 0xffUL ) ;
}
V_46 -> V_31 = V_33 -> V_39 . V_40 -> V_31 ;
}
}
static struct V_32 * T_2 F_23 ( struct V_1 * V_48 ,
struct V_34 * V_23 )
{
struct V_32 * V_33 = F_24 ( sizeof( * V_33 ) , V_61 ) ;
const struct V_62 * V_63 ;
struct V_64 * V_65 ;
int V_66 , V_12 ;
if ( ! V_33 )
return NULL ;
V_65 = & V_33 -> V_39 . V_44 ;
V_65 -> V_33 = V_33 ;
V_33 -> V_39 . V_40 = V_48 ;
V_63 = F_17 ( V_48 , L_10 , & V_66 ) ;
if ( V_63 ) {
V_33 -> V_44 . V_67 = V_66 / sizeof( struct V_62 ) ;
for ( V_12 = 0 ; V_12 < V_33 -> V_44 . V_67 ; V_12 ++ )
V_33 -> V_44 . V_68 [ V_12 ] =
V_69 . V_70 ( V_33 , V_63 [ V_12 ] . V_71 ) ;
} else {
const unsigned int * V_72 =
F_17 ( V_48 , L_11 , & V_66 ) ;
if ( V_72 ) {
V_33 -> V_44 . V_67 = V_66 / sizeof( unsigned int ) ;
for ( V_12 = 0 ; V_12 < V_33 -> V_44 . V_67 ; V_12 ++ )
V_33 -> V_44 . V_68 [ V_12 ] =
V_69 . V_70 ( V_33 , V_72 [ V_12 ] ) ;
} else {
V_33 -> V_44 . V_67 = 0 ;
}
}
F_19 ( V_33 , V_23 ) ;
V_33 -> V_39 . V_23 = V_23 ;
V_33 -> V_39 . V_24 = & V_73 ;
if ( ! V_23 )
F_25 ( & V_33 -> V_39 , L_12 ) ;
else
F_25 ( & V_33 -> V_39 , L_13 , V_48 -> V_74 ) ;
if ( F_26 ( V_33 ) ) {
F_22 ( L_14 ,
V_48 -> V_58 ) ;
F_27 ( V_33 ) ;
V_33 = NULL ;
}
return V_33 ;
}
static void T_2 F_28 ( struct V_1 * V_48 , struct V_34 * V_23 )
{
while ( V_48 ) {
struct V_32 * V_33 = F_23 ( V_48 , V_23 ) ;
if ( V_33 )
F_28 ( V_48 -> V_19 , & V_33 -> V_39 ) ;
V_48 = V_48 -> V_75 ;
}
}
static int T_2 F_29 ( void )
{
struct V_1 * V_76 = F_30 ( L_15 ) ;
struct V_32 * V_23 ;
V_23 = F_23 ( V_76 , NULL ) ;
if ( ! V_23 )
return 0 ;
F_28 ( V_76 -> V_19 , & V_23 -> V_39 ) ;
return 0 ;
}
static int T_2 F_31 ( char * V_77 )
{
int V_78 = 0 ;
F_32 ( & V_77 , & V_78 ) ;
if ( V_78 & 1 )
V_57 = 1 ;
return 1 ;
}
