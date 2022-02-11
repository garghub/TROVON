static inline T_1 F_1 ( void * V_1 )
{
T_1 * V_2 = V_1 ;
return * V_2 ;
}
static inline T_2 F_2 ( void * V_1 )
{
T_3 * V_2 = V_1 ;
return F_3 ( * V_2 ) ;
}
static inline T_4 F_4 ( void * V_1 )
{
T_5 * V_2 = V_1 ;
return F_5 ( * V_2 ) ;
}
static inline void F_6 ( T_4 V_3 , void * V_1 )
{
T_1 * V_2 = V_1 ;
* V_2 = V_3 ;
}
static inline void F_7 ( T_4 V_3 , void * V_1 )
{
T_3 V_4 ;
T_3 * V_2 = V_1 ;
V_4 = F_8 ( V_3 ) ;
* V_2 = V_4 ;
}
static inline void F_9 ( T_4 V_3 , void * V_1 )
{
T_5 V_5 ;
T_5 * V_2 = V_1 ;
V_5 = F_10 ( V_3 ) ;
* V_2 = V_5 ;
}
static unsigned char * F_11 ( struct V_6 * V_7 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 == NULL )
return NULL ;
return V_11 -> V_13 [ V_8 ] [ V_9 ] ;
}
static struct V_14 * F_12 (
struct V_6 * V_7 ,
int V_8 , int V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
if ( V_11 == NULL )
return NULL ;
return V_11 -> V_15 [ V_8 ] [ V_9 ] ;
}
static void F_13 ( unsigned char * V_16 , int V_17 ,
int V_18 , T_4 * V_3 )
{
char * V_2 = V_16 + V_17 ;
switch ( V_18 ) {
case 1 :
* V_3 = F_1 ( V_2 ) ;
break;
case 2 :
* V_3 = F_2 ( V_2 ) ;
break;
case 4 :
* V_3 = F_4 ( V_2 ) ;
break;
}
}
static void F_14 ( unsigned char * V_16 , int V_17 ,
int V_18 , T_4 V_3 )
{
char * V_2 = V_16 + V_17 ;
switch ( V_18 ) {
case 1 :
F_6 ( V_3 , V_2 ) ;
break;
case 2 :
F_7 ( V_3 , V_2 ) ;
break;
case 4 :
F_9 ( V_3 , V_2 ) ;
break;
}
}
static int F_15 ( struct V_19 * V_20 ,
unsigned int V_21 , int V_17 , int V_18 , T_4 * V_3 )
{
char * V_16 ;
struct V_6 * V_7 = F_16 ( V_20 ) ;
unsigned int V_8 = V_21 >> 3 ;
unsigned int V_9 = V_21 & 0x7 ;
F_17 ( V_17 % V_18 ) ;
F_18 ( L_1 , V_20 -> V_22 ) ;
V_16 = F_11 ( V_7 , V_8 , V_9 ) ;
F_18 ( L_2 , V_8 , V_17 , V_18 ) ;
if ( ! V_16 ) {
F_18 ( L_3 ) ;
return V_23 ;
}
F_13 ( V_16 , V_17 , V_18 , V_3 ) ;
F_18 ( L_4 , * V_3 ) ;
return V_24 ;
}
static int F_19 ( struct V_19 * V_20 ,
unsigned int V_21 , int V_17 , int V_18 , T_4 V_3 )
{
char * V_16 ;
struct V_6 * V_7 = F_16 ( V_20 ) ;
struct V_14 * V_15 ;
unsigned int V_8 = V_21 >> 3 ;
unsigned int V_9 = V_21 & 0x7 ;
F_17 ( V_17 % V_18 ) ;
V_16 = F_11 ( V_7 , V_8 , V_9 ) ;
if ( ! V_16 )
return V_23 ;
if ( V_3 == ~ 0 ) {
int V_25 = ( V_17 - V_26 ) >> 3 ;
switch ( V_17 ) {
case V_26 :
case V_27 :
if ( V_18 != 4 )
return V_23 ;
V_15 = F_12 ( V_7 , V_8 , V_9 ) ;
if ( ! V_15 )
return V_23 ;
F_14 ( V_16 , V_17 , V_18 ,
( V_15 -> V_28 [ V_25 ] . V_29 - V_15 -> V_28 [ V_25 ] . V_30 ) ) ;
return V_24 ;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
break;
default:
break;
}
}
F_14 ( V_16 , V_17 , V_18 , V_3 ) ;
F_18 ( L_5 ,
V_17 , V_18 , V_3 ) ;
return V_24 ;
}
static inline void F_20 ( struct V_6 * V_7 ,
unsigned int V_8 , unsigned int V_9 ,
unsigned int V_35 )
{
T_4 V_3 ;
unsigned char * V_16 ;
struct V_14 * V_15 ;
V_16 = F_11 ( V_7 , V_8 , V_9 ) ;
V_15 = F_12 ( V_7 , V_8 , V_9 ) ;
if ( ! V_16 || ! V_15 )
return;
switch ( V_35 ) {
case 3 :
V_3 = ( V_15 -> V_28 [ 2 ] . V_30 & 0xfffffff0 )
| V_36 ;
F_14 ( V_16 , V_33 , 4 , V_3 ) ;
V_3 = V_15 -> V_28 [ 2 ] . V_30 >> 32 ;
F_14 ( V_16 , V_34 , 4 , V_3 ) ;
case 2 :
V_3 = ( V_15 -> V_28 [ 1 ] . V_30 & 0xfffffff0 )
| V_36 ;
F_14 ( V_16 , V_27 , 4 , V_3 ) ;
V_3 = V_15 -> V_28 [ 1 ] . V_30 >> 32 ;
F_14 ( V_16 , V_32 , 4 , V_3 ) ;
case 1 :
V_3 = ( V_15 -> V_28 [ 0 ] . V_30 & 0xfffffff0 )
| V_36 ;
F_14 ( V_16 , V_26 , 4 , V_3 ) ;
V_3 = V_15 -> V_28 [ 0 ] . V_30 >> 32 ;
F_14 ( V_16 , V_31 , 4 , V_3 ) ;
break;
}
V_3 = V_37 | V_38 | V_39 ;
F_14 ( V_16 , V_40 , 2 , V_3 ) ;
}
static int T_6 F_21 ( struct V_41 * V_42 ,
struct V_6 * V_7 )
{
unsigned int V_43 ;
int V_35 = 0 ;
T_4 V_3 ;
const T_4 * V_44 , * V_45 , * V_46 , * V_47 , * V_48 ;
unsigned int V_8 , V_9 ;
struct V_10 * V_11 = V_7 -> V_12 ;
unsigned char * * V_16 = NULL ;
struct V_14 * * V_15 = NULL ;
const char * V_49 ;
const unsigned long * V_50 ;
int V_18 , V_51 ;
if ( V_11 == NULL ) {
F_22 ( V_52 L_6
L_7 ) ;
goto error;
}
V_49 = F_23 ( V_42 , L_8 , & V_43 ) ;
if ( ! V_49 ) {
F_22 ( V_52 L_9 ) ;
goto error;
}
V_48 = F_23 ( V_42 , L_10 , & V_43 ) ;
if ( V_48 == NULL )
goto error;
V_8 = ( ( V_48 [ 0 ] >> 8 ) & 0xff ) >> 3 ;
V_9 = ( V_48 [ 0 ] >> 8 ) & 0x7 ;
F_18 ( L_11 , V_49 ,
V_8 , V_9 ) ;
V_18 = 256 ;
V_16 = & V_11 -> V_13 [ V_8 ] [ V_9 ] ;
* V_16 = F_24 ( V_18 , V_53 ) ;
if ( * V_16 == NULL ) {
F_22 ( V_52 L_6
L_12 ) ;
goto error;
}
F_18 ( L_13 ,
( unsigned long ) * V_16 ) ;
V_18 = sizeof( struct V_14 ) ;
V_15 = & V_11 -> V_15 [ V_8 ] [ V_9 ] ;
* V_15 = F_24 ( V_18 , V_53 ) ;
if ( * V_15 == NULL ) {
F_22 ( V_52
L_14 ) ;
goto error;
}
F_18 ( L_15 , ( unsigned long ) * V_15 ) ;
V_44 = F_23 ( V_42 , L_16 , NULL ) ;
V_45 = F_23 ( V_42 , L_17 , NULL ) ;
V_46 = F_23 ( V_42 , L_18 , NULL ) ;
V_47 = F_23 ( V_42 , L_19 , NULL ) ;
if ( ! V_44 || ! V_45 || ! V_46 || ! V_47 ) {
F_22 ( V_52 L_20 ) ;
goto error;
}
F_14 ( * V_16 , V_54 , 2 , V_44 [ 0 ] & 0xffff ) ;
F_14 ( * V_16 , V_55 , 2 , V_45 [ 0 ] & 0xffff ) ;
F_18 ( L_21 , V_46 [ 0 ] ) ;
F_14 ( * V_16 , V_56 , 1 , V_46 [ 0 ] & 0xff ) ;
F_14 ( * V_16 , V_57 , 2 ,
( V_46 [ 0 ] >> 8 ) & 0xffff ) ;
F_14 ( * V_16 , V_58 , 1 , V_47 [ 0 ] ) ;
while ( V_35 < V_59 ) {
V_51 = F_25 ( V_42 ,
V_35 , & ( * V_15 ) -> V_28 [ V_35 ] ) ;
if ( V_51 )
break;
V_35 ++ ;
}
F_20 ( V_7 , V_8 , V_9 , V_35 ) ;
V_50 = F_23 ( V_42 , L_22 , & V_43 ) ;
if ( ! V_50 ) {
F_22 ( V_52 L_23 ) ;
goto error;
}
V_3 = V_50 [ 0 ] ;
F_14 ( * V_16 , V_60 , 1 , 1 ) ;
F_14 ( * V_16 , V_61 , 1 , V_3 ) ;
#ifdef F_26
F_18 ( L_24 , V_49 , V_50 [ 0 ] ) ;
for ( V_25 = 0 ; V_25 < 6 ; V_25 ++ ) {
F_13 ( * V_16 ,
V_26 + 0x4 * V_25 , 4 ,
& V_3 ) ;
F_18 ( L_25 ,
V_49 , V_9 , V_25 , V_3 ) ;
}
#endif
F_14 ( * V_16 , V_62 , 1 ,
V_63 ) ;
return 0 ;
error:
if ( V_64 ) {
if ( V_16 && * V_16 )
F_27 ( * V_16 ) ;
if ( V_15 && * V_15 )
F_27 ( * V_15 ) ;
} else {
if ( V_16 && * V_16 ) {
V_18 = 256 ;
F_28 ( ( unsigned long ) ( * V_16 ) , V_18 ) ;
}
if ( V_15 && * V_15 ) {
V_18 = sizeof( struct V_14 ) ;
F_28 ( ( unsigned long ) ( * V_15 ) , V_18 ) ;
}
}
return 1 ;
}
static int T_6 F_29 ( struct V_41 * V_65 ,
struct V_6 * V_66 )
{
const int * V_67 ;
unsigned int V_68 ;
V_67 = F_23 ( V_65 , L_26 , & V_68 ) ;
if ( V_67 == NULL || V_68 < 2 * sizeof( int ) )
return 1 ;
V_66 -> V_69 = V_67 [ 0 ] ;
V_66 -> V_70 = V_67 [ 1 ] ;
return 0 ;
}
static void T_6 F_30 ( struct V_6 * V_7 )
{
V_7 -> V_12 =
F_24 ( sizeof( struct V_10 ) ,
V_53 ) ;
}
static int T_6 F_31 ( struct V_41 * V_65 ,
struct V_6 * V_66 )
{
struct V_41 * V_42 ;
V_66 -> V_71 = & V_72 ;
F_30 ( V_66 ) ;
for ( V_42 = F_32 ( V_65 , NULL ) ;
V_42 != NULL ; V_42 = F_32 ( V_65 , V_42 ) )
F_21 ( V_42 , V_66 ) ;
return 0 ;
}
int T_6 F_33 ( struct V_6 * V_66 )
{
struct V_41 * V_65 = V_66 -> V_73 ;
const struct V_74 * V_75 ;
struct V_76 * V_77 ;
int V_78 ;
V_75 = F_34 ( V_79 , V_65 ) ;
if ( ! V_75 )
return 1 ;
F_29 ( V_65 , V_66 ) ;
V_66 -> V_80 = 1 ;
V_77 = V_75 -> V_81 ;
V_78 = (* V_77 -> V_82 )( V_65 , V_66 ) ;
if ( V_78 )
return 1 ;
if ( V_77 -> V_71 )
F_35 ( V_66 , V_77 -> V_71 ,
V_77 -> V_83 ,
V_77 -> V_84 ) ;
return 0 ;
}
int F_36 ( struct V_19 * V_20 )
{
return V_85 ;
}
