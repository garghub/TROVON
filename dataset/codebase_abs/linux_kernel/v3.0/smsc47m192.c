static inline int F_1 ( long V_1 , int V_2 , int div )
{
if ( V_1 < 0 )
return ( V_1 * V_2 - div / 2 ) / div ;
else
return ( V_1 * V_2 + div / 2 ) / div ;
}
static inline unsigned int F_2 ( T_1 V_3 , int V_4 )
{
return F_1 ( V_3 , V_5 [ V_4 ] , 192 ) ;
}
static inline T_1 F_3 ( unsigned long V_1 , int V_4 )
{
return F_4 ( F_1 ( V_1 , 192 , V_5 [ V_4 ] ) , 0 , 255 ) ;
}
static inline T_2 F_5 ( int V_1 )
{
return F_4 ( F_1 ( V_1 , 1 , 1000 ) , - 128000 , 127000 ) ;
}
static inline int F_6 ( T_2 V_1 )
{
return V_1 * 1000 ;
}
static T_3 F_7 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_16 -> V_17 [ V_13 ] , V_13 ) ) ;
}
static T_3 F_10 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_16 -> V_18 [ V_13 ] , V_13 ) ) ;
}
static T_3 F_11 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_16 -> V_19 [ V_13 ] , V_13 ) ) ;
}
static T_3 F_12 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_4 V_20 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_21 * V_22 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_14 ( V_22 ) ;
unsigned long V_1 = F_15 ( V_10 , NULL , 10 ) ;
F_16 ( & V_16 -> V_23 ) ;
V_16 -> V_18 [ V_13 ] = F_3 ( V_1 , V_13 ) ;
F_17 ( V_22 , F_18 ( V_13 ) ,
V_16 -> V_18 [ V_13 ] ) ;
F_19 ( & V_16 -> V_23 ) ;
return V_20 ;
}
static T_3 F_20 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_4 V_20 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_21 * V_22 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_14 ( V_22 ) ;
unsigned long V_1 = F_15 ( V_10 , NULL , 10 ) ;
F_16 ( & V_16 -> V_23 ) ;
V_16 -> V_19 [ V_13 ] = F_3 ( V_1 , V_13 ) ;
F_17 ( V_22 , F_21 ( V_13 ) ,
V_16 -> V_19 [ V_13 ] ) ;
F_19 ( & V_16 -> V_23 ) ;
return V_20 ;
}
static T_3 F_22 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_16 -> V_24 [ V_13 ] ) ) ;
}
static T_3 F_23 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_16 -> V_25 [ V_13 ] ) ) ;
}
static T_3 F_24 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_16 -> V_26 [ V_13 ] ) ) ;
}
static T_3 F_25 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_4 V_20 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_21 * V_22 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_14 ( V_22 ) ;
long V_1 = F_26 ( V_10 , NULL , 10 ) ;
F_16 ( & V_16 -> V_23 ) ;
V_16 -> V_25 [ V_13 ] = F_5 ( V_1 ) ;
F_17 ( V_22 , V_27 [ V_13 ] ,
V_16 -> V_25 [ V_13 ] ) ;
F_19 ( & V_16 -> V_23 ) ;
return V_20 ;
}
static T_3 F_27 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_4 V_20 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_21 * V_22 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_14 ( V_22 ) ;
long V_1 = F_26 ( V_10 , NULL , 10 ) ;
F_16 ( & V_16 -> V_23 ) ;
V_16 -> V_26 [ V_13 ] = F_5 ( V_1 ) ;
F_17 ( V_22 , V_28 [ V_13 ] ,
V_16 -> V_26 [ V_13 ] ) ;
F_19 ( & V_16 -> V_23 ) ;
return V_20 ;
}
static T_3 F_28 ( struct V_6 * V_7 , struct V_8
* V_9 , char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_6 ( V_16 -> V_29 [ V_13 ] ) ) ;
}
static T_3 F_29 ( struct V_6 * V_7 , struct V_8
* V_9 , const char * V_10 , T_4 V_20 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_21 * V_22 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_14 ( V_22 ) ;
T_1 V_30 = F_30 ( V_22 , V_31 ) ;
long V_1 = F_26 ( V_10 , NULL , 10 ) ;
F_16 ( & V_16 -> V_23 ) ;
V_16 -> V_29 [ V_13 ] = F_5 ( V_1 ) ;
if ( V_13 > 1 )
F_17 ( V_22 ,
F_31 ( V_13 ) , V_16 -> V_29 [ V_13 ] ) ;
else if ( V_16 -> V_29 [ V_13 ] != 0 ) {
F_17 ( V_22 , V_31 ,
( V_30 & 0xef ) | ( V_13 == 0 ? 0x10 : 0 ) ) ;
V_16 -> V_29 [ 1 - V_13 ] = 0 ;
F_17 ( V_22 ,
F_31 ( V_13 ) , V_16 -> V_29 [ V_13 ] ) ;
} else if ( ( V_30 & 0x10 ) == ( V_13 == 0 ? 0x10 : 0 ) )
F_17 ( V_22 ,
F_31 ( V_13 ) , 0 ) ;
F_19 ( & V_16 -> V_23 ) ;
return V_20 ;
}
static T_3 F_32 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_1 , F_33 ( V_16 -> V_32 , V_16 -> V_33 ) ) ;
}
static T_3 F_34 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_15 * V_16 = F_35 ( V_7 ) ;
return sprintf ( V_10 , L_1 , V_16 -> V_33 ) ;
}
static T_3 F_36 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_4 V_20 )
{
struct V_15 * V_16 = F_35 ( V_7 ) ;
V_16 -> V_33 = F_15 ( V_10 , NULL , 10 ) ;
return V_20 ;
}
static T_3 F_37 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_8 ( V_9 ) ;
int V_13 = V_12 -> V_14 ;
struct V_15 * V_16 = F_9 ( V_7 ) ;
return sprintf ( V_10 , L_2 , ( V_16 -> V_34 & V_13 ) ? 1 : 0 ) ;
}
static void F_38 ( struct V_21 * V_22 )
{
int V_35 ;
T_1 V_36 = F_30 ( V_22 , V_37 ) ;
T_1 V_30 = F_30 ( V_22 , V_31 ) ;
F_17 ( V_22 , V_31 ,
( V_30 & 0xfd ) | 0x02 ) ;
if ( ! ( V_36 & 0x01 ) ) {
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
F_17 ( V_22 ,
F_18 ( V_35 ) , 0 ) ;
F_17 ( V_22 ,
F_21 ( V_35 ) , 0xff ) ;
}
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ ) {
F_17 ( V_22 ,
V_27 [ V_35 ] , 0x80 ) ;
F_17 ( V_22 ,
V_28 [ V_35 ] , 0x7f ) ;
}
F_17 ( V_22 , V_37 ,
( V_36 & 0xf7 ) | 0x01 ) ;
}
}
static int F_39 ( struct V_21 * V_22 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_22 -> V_41 ;
int V_42 ;
if ( ! F_40 ( V_41 , V_43 ) )
return - V_44 ;
V_42 = F_30 ( V_22 , V_45 ) ;
if ( F_30 ( V_22 ,
V_46 ) == 0x55
&& ( V_42 & 0xf0 ) == 0x20
&& ( F_30 ( V_22 ,
V_47 ) & 0x70 ) == 0x00
&& ( F_30 ( V_22 ,
V_48 ) & 0xfe ) == 0x80 ) {
F_41 ( & V_41 -> V_7 ,
L_3
L_4 , V_42 & 0x0f ) ;
} else {
F_42 ( & V_41 -> V_7 ,
L_5 ,
V_22 -> V_49 ) ;
return - V_44 ;
}
F_43 ( V_39 -> type , L_6 , V_50 ) ;
return 0 ;
}
static int F_44 ( struct V_21 * V_22 ,
const struct V_51 * V_52 )
{
struct V_15 * V_16 ;
int V_36 ;
int V_53 ;
V_16 = F_45 ( sizeof( struct V_15 ) , V_54 ) ;
if ( ! V_16 ) {
V_53 = - V_55 ;
goto exit;
}
F_46 ( V_22 , V_16 ) ;
V_16 -> V_33 = F_47 () ;
F_48 ( & V_16 -> V_23 ) ;
F_38 ( V_22 ) ;
if ( ( V_53 = F_49 ( & V_22 -> V_7 . V_56 , & V_57 ) ) )
goto V_58;
V_36 = F_30 ( V_22 , V_37 ) ;
if ( ! ( V_36 & 0x20 ) ) {
if ( ( V_53 = F_49 ( & V_22 -> V_7 . V_56 ,
& V_59 ) ) )
goto V_60;
}
V_16 -> V_61 = F_50 ( & V_22 -> V_7 ) ;
if ( F_51 ( V_16 -> V_61 ) ) {
V_53 = F_52 ( V_16 -> V_61 ) ;
goto V_60;
}
return 0 ;
V_60:
F_53 ( & V_22 -> V_7 . V_56 , & V_57 ) ;
F_53 ( & V_22 -> V_7 . V_56 , & V_59 ) ;
V_58:
F_54 ( V_16 ) ;
exit:
return V_53 ;
}
static int F_55 ( struct V_21 * V_22 )
{
struct V_15 * V_16 = F_14 ( V_22 ) ;
F_56 ( V_16 -> V_61 ) ;
F_53 ( & V_22 -> V_7 . V_56 , & V_57 ) ;
F_53 ( & V_22 -> V_7 . V_56 , & V_59 ) ;
F_54 ( V_16 ) ;
return 0 ;
}
static struct V_15 * F_9 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = F_13 ( V_7 ) ;
struct V_15 * V_16 = F_14 ( V_22 ) ;
int V_35 , V_36 ;
F_16 ( & V_16 -> V_23 ) ;
if ( F_57 ( V_62 , V_16 -> V_63 + V_64 + V_64 / 2 )
|| ! V_16 -> V_65 ) {
T_1 V_30 = F_30 ( V_22 , V_31 ) ;
F_42 ( & V_22 -> V_7 , L_7 ) ;
for ( V_35 = 0 ; V_35 <= 7 ; V_35 ++ ) {
V_16 -> V_17 [ V_35 ] = F_30 ( V_22 ,
F_58 ( V_35 ) ) ;
V_16 -> V_18 [ V_35 ] = F_30 ( V_22 ,
F_18 ( V_35 ) ) ;
V_16 -> V_19 [ V_35 ] = F_30 ( V_22 ,
F_21 ( V_35 ) ) ;
}
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ ) {
V_16 -> V_24 [ V_35 ] = F_30 ( V_22 ,
V_66 [ V_35 ] ) ;
V_16 -> V_26 [ V_35 ] = F_30 ( V_22 ,
V_28 [ V_35 ] ) ;
V_16 -> V_25 [ V_35 ] = F_30 ( V_22 ,
V_27 [ V_35 ] ) ;
}
for ( V_35 = 1 ; V_35 < 3 ; V_35 ++ )
V_16 -> V_29 [ V_35 ] = F_30 ( V_22 ,
F_31 ( V_35 ) ) ;
if ( V_30 & 0x10 ) {
V_16 -> V_29 [ 0 ] = V_16 -> V_29 [ 1 ] ;
V_16 -> V_29 [ 1 ] = 0 ;
} else
V_16 -> V_29 [ 0 ] = 0 ;
V_16 -> V_32 = F_30 ( V_22 , V_47 )
& 0x0f ;
V_36 = F_30 ( V_22 ,
V_37 ) ;
if ( V_36 & 0x20 )
V_16 -> V_32 |= ( F_30 ( V_22 ,
V_48 ) & 0x01 ) << 4 ;
V_16 -> V_34 = F_30 ( V_22 ,
V_67 ) |
( F_30 ( V_22 ,
V_68 ) << 8 ) ;
V_16 -> V_63 = V_62 ;
V_16 -> V_65 = 1 ;
}
F_19 ( & V_16 -> V_23 ) ;
return V_16 ;
}
static int T_5 F_59 ( void )
{
return F_60 ( & V_69 ) ;
}
static void T_6 F_61 ( void )
{
F_62 ( & V_69 ) ;
}
