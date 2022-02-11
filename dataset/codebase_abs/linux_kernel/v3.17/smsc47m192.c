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
return F_1 ( F_4 ( V_1 , - 128000 , 127000 ) , 1 , 1000 ) ;
}
static inline int F_6 ( T_2 V_1 )
{
return V_1 * 1000 ;
}
static struct V_6 * F_7 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
int V_12 , V_13 ;
F_9 ( & V_9 -> V_14 ) ;
if ( F_10 ( V_15 , V_9 -> V_16 + V_17 + V_17 / 2 )
|| ! V_9 -> V_18 ) {
T_1 V_19 = F_11 ( V_11 , V_20 ) ;
F_12 ( & V_11 -> V_8 , L_1 ) ;
for ( V_12 = 0 ; V_12 <= 7 ; V_12 ++ ) {
V_9 -> V_21 [ V_12 ] = F_11 ( V_11 ,
F_13 ( V_12 ) ) ;
V_9 -> V_22 [ V_12 ] = F_11 ( V_11 ,
F_14 ( V_12 ) ) ;
V_9 -> V_23 [ V_12 ] = F_11 ( V_11 ,
F_15 ( V_12 ) ) ;
}
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_9 -> V_24 [ V_12 ] = F_11 ( V_11 ,
V_25 [ V_12 ] ) ;
V_9 -> V_26 [ V_12 ] = F_11 ( V_11 ,
V_27 [ V_12 ] ) ;
V_9 -> V_28 [ V_12 ] = F_11 ( V_11 ,
V_29 [ V_12 ] ) ;
}
for ( V_12 = 1 ; V_12 < 3 ; V_12 ++ )
V_9 -> V_30 [ V_12 ] = F_11 ( V_11 ,
F_16 ( V_12 ) ) ;
if ( V_19 & 0x10 ) {
V_9 -> V_30 [ 0 ] = V_9 -> V_30 [ 1 ] ;
V_9 -> V_30 [ 1 ] = 0 ;
} else
V_9 -> V_30 [ 0 ] = 0 ;
V_9 -> V_31 = F_11 ( V_11 , V_32 )
& 0x0f ;
V_13 = F_11 ( V_11 ,
V_33 ) ;
if ( V_13 & 0x20 )
V_9 -> V_31 |= ( F_11 ( V_11 ,
V_34 ) & 0x01 ) << 4 ;
V_9 -> V_35 = F_11 ( V_11 ,
V_36 ) |
( F_11 ( V_11 ,
V_37 ) << 8 ) ;
V_9 -> V_16 = V_15 ;
V_9 -> V_18 = 1 ;
}
F_17 ( & V_9 -> V_14 ) ;
return V_9 ;
}
static T_3 F_18 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_2 ( V_9 -> V_21 [ V_43 ] , V_43 ) ) ;
}
static T_3 F_20 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_2 ( V_9 -> V_22 [ V_43 ] , V_43 ) ) ;
}
static T_3 F_21 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_2 ( V_9 -> V_23 [ V_43 ] , V_43 ) ) ;
}
static T_3 F_22 ( struct V_7 * V_8 , struct V_38 * V_39 ,
const char * V_40 , T_4 V_45 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_1 ;
int V_46 ;
V_46 = F_23 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_9 ( & V_9 -> V_14 ) ;
V_9 -> V_22 [ V_43 ] = F_3 ( V_1 , V_43 ) ;
F_24 ( V_11 , F_14 ( V_43 ) ,
V_9 -> V_22 [ V_43 ] ) ;
F_17 ( & V_9 -> V_14 ) ;
return V_45 ;
}
static T_3 F_25 ( struct V_7 * V_8 , struct V_38 * V_39 ,
const char * V_40 , T_4 V_45 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_1 ;
int V_46 ;
V_46 = F_23 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_9 ( & V_9 -> V_14 ) ;
V_9 -> V_23 [ V_43 ] = F_3 ( V_1 , V_43 ) ;
F_24 ( V_11 , F_15 ( V_43 ) ,
V_9 -> V_23 [ V_43 ] ) ;
F_17 ( & V_9 -> V_14 ) ;
return V_45 ;
}
static T_3 F_26 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_6 ( V_9 -> V_24 [ V_43 ] ) ) ;
}
static T_3 F_27 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_6 ( V_9 -> V_28 [ V_43 ] ) ) ;
}
static T_3 F_28 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_6 ( V_9 -> V_26 [ V_43 ] ) ) ;
}
static T_3 F_29 ( struct V_7 * V_8 , struct V_38 * V_39 ,
const char * V_40 , T_4 V_45 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
long V_1 ;
int V_46 ;
V_46 = F_30 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_9 ( & V_9 -> V_14 ) ;
V_9 -> V_28 [ V_43 ] = F_5 ( V_1 ) ;
F_24 ( V_11 , V_29 [ V_43 ] ,
V_9 -> V_28 [ V_43 ] ) ;
F_17 ( & V_9 -> V_14 ) ;
return V_45 ;
}
static T_3 F_31 ( struct V_7 * V_8 , struct V_38 * V_39 ,
const char * V_40 , T_4 V_45 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
long V_1 ;
int V_46 ;
V_46 = F_30 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_9 ( & V_9 -> V_14 ) ;
V_9 -> V_26 [ V_43 ] = F_5 ( V_1 ) ;
F_24 ( V_11 , V_27 [ V_43 ] ,
V_9 -> V_26 [ V_43 ] ) ;
F_17 ( & V_9 -> V_14 ) ;
return V_45 ;
}
static T_3 F_32 ( struct V_7 * V_8 , struct V_38
* V_39 , char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_6 ( V_9 -> V_30 [ V_43 ] ) ) ;
}
static T_3 F_33 ( struct V_7 * V_8 , struct V_38
* V_39 , const char * V_40 , T_4 V_45 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_8 ( V_8 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
T_1 V_19 = F_11 ( V_11 , V_20 ) ;
long V_1 ;
int V_46 ;
V_46 = F_30 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
F_9 ( & V_9 -> V_14 ) ;
V_9 -> V_30 [ V_43 ] = F_5 ( V_1 ) ;
if ( V_43 > 1 )
F_24 ( V_11 ,
F_16 ( V_43 ) , V_9 -> V_30 [ V_43 ] ) ;
else if ( V_9 -> V_30 [ V_43 ] != 0 ) {
F_24 ( V_11 , V_20 ,
( V_19 & 0xef ) | ( V_43 == 0 ? 0x10 : 0 ) ) ;
V_9 -> V_30 [ 1 - V_43 ] = 0 ;
F_24 ( V_11 ,
F_16 ( V_43 ) , V_9 -> V_30 [ V_43 ] ) ;
} else if ( ( V_19 & 0x10 ) == ( V_43 == 0 ? 0x10 : 0 ) )
F_24 ( V_11 ,
F_16 ( V_43 ) , 0 ) ;
F_17 ( & V_9 -> V_14 ) ;
return V_45 ;
}
static T_3 F_34 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_2 , F_35 ( V_9 -> V_31 , V_9 -> V_47 ) ) ;
}
static T_3 F_36 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_6 * V_9 = F_8 ( V_8 ) ;
return sprintf ( V_40 , L_2 , V_9 -> V_47 ) ;
}
static T_3 F_37 ( struct V_7 * V_8 , struct V_38 * V_39 ,
const char * V_40 , T_4 V_45 )
{
struct V_6 * V_9 = F_8 ( V_8 ) ;
unsigned long V_1 ;
int V_46 ;
V_46 = F_23 ( V_40 , 10 , & V_1 ) ;
if ( V_46 )
return V_46 ;
if ( V_1 > 255 )
return - V_48 ;
V_9 -> V_47 = V_1 ;
return V_45 ;
}
static T_3 F_38 ( struct V_7 * V_8 , struct V_38 * V_39 ,
char * V_40 )
{
struct V_41 * V_42 = F_19 ( V_39 ) ;
int V_43 = V_42 -> V_44 ;
struct V_6 * V_9 = F_7 ( V_8 ) ;
return sprintf ( V_40 , L_3 , ( V_9 -> V_35 & V_43 ) ? 1 : 0 ) ;
}
static void F_39 ( struct V_10 * V_11 )
{
int V_12 ;
T_1 V_13 = F_11 ( V_11 , V_33 ) ;
T_1 V_19 = F_11 ( V_11 , V_20 ) ;
F_24 ( V_11 , V_20 ,
( V_19 & 0xfd ) | 0x02 ) ;
if ( ! ( V_13 & 0x01 ) ) {
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
F_24 ( V_11 ,
F_14 ( V_12 ) , 0 ) ;
F_24 ( V_11 ,
F_15 ( V_12 ) , 0xff ) ;
}
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
F_24 ( V_11 ,
V_29 [ V_12 ] , 0x80 ) ;
F_24 ( V_11 ,
V_27 [ V_12 ] , 0x7f ) ;
}
F_24 ( V_11 , V_33 ,
( V_13 & 0xf7 ) | 0x01 ) ;
}
}
static int F_40 ( struct V_10 * V_11 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_11 -> V_52 ;
int V_53 ;
if ( ! F_41 ( V_52 , V_54 ) )
return - V_55 ;
V_53 = F_11 ( V_11 , V_56 ) ;
if ( F_11 ( V_11 ,
V_57 ) == 0x55
&& ( V_53 & 0xf0 ) == 0x20
&& ( F_11 ( V_11 ,
V_32 ) & 0x70 ) == 0x00
&& ( F_11 ( V_11 ,
V_34 ) & 0xfe ) == 0x80 ) {
F_42 ( & V_52 -> V_8 ,
L_4
L_5 , V_53 & 0x0f ) ;
} else {
F_12 ( & V_52 -> V_8 ,
L_6 ,
V_11 -> V_58 ) ;
return - V_55 ;
}
F_43 ( V_50 -> type , L_7 , V_59 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 ,
const struct V_60 * V_61 )
{
struct V_7 * V_8 = & V_11 -> V_8 ;
struct V_7 * V_62 ;
struct V_6 * V_9 ;
int V_13 ;
V_9 = F_45 ( V_8 , sizeof( struct V_6 ) , V_63 ) ;
if ( ! V_9 )
return - V_64 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_47 = F_46 () ;
F_47 ( & V_9 -> V_14 ) ;
F_39 ( V_11 ) ;
V_9 -> V_65 [ 0 ] = & V_66 ;
V_13 = F_11 ( V_11 , V_33 ) ;
if ( ! ( V_13 & 0x20 ) )
V_9 -> V_65 [ 1 ] = & V_67 ;
V_62 = F_48 ( V_8 , V_11 -> V_68 ,
V_9 , V_9 -> V_65 ) ;
return F_49 ( V_62 ) ;
}
