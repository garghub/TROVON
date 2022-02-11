static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static struct V_5 * F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
F_8 ( & V_8 -> V_9 ) ;
if ( F_9 ( V_10 , V_8 -> V_11 + V_12 ) || ! V_8 -> V_13 ) {
int V_14 , V_15 ;
F_10 ( & V_2 -> V_7 , L_1 ) ;
V_14 = ( V_8 -> V_16 & V_17 ) ? 1 : 0 ;
V_15 = ( V_8 -> V_16 & V_17 ) ? 5 : 6 ;
for (; V_14 < V_15 ; V_14 ++ ) {
V_8 -> V_18 [ V_14 ] = F_1 ( V_2 ,
F_11 ( V_14 ) ) ;
V_8 -> V_19 [ V_14 ] = F_1 ( V_2 ,
F_12 ( V_14 ) ) ;
V_8 -> V_20 [ V_14 ] = F_1 ( V_2 ,
F_13 ( V_14 ) ) ;
}
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
if ( V_8 -> V_16 & F_14 ( V_14 ) ) {
V_8 -> V_18 [ 6 + V_14 ] = F_1 ( V_2 ,
F_15 ( V_14 ) ) ;
V_8 -> V_20 [ 6 + V_14 ] = F_1 ( V_2 ,
F_16 ( V_14 ) ) ;
V_8 -> V_19 [ 6 + V_14 ] = F_1 ( V_2 ,
F_17 ( V_14 ) ) ;
} else {
V_8 -> V_21 [ V_14 ] = F_1 ( V_2 ,
F_18 ( V_14 ) ) ;
V_8 -> V_22 [ V_14 ] = F_1 ( V_2 ,
F_19 ( V_14 ) ) ;
}
}
V_15 = ( V_8 -> V_16 & V_17 ) ? 3 : 2 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_8 -> V_23 [ V_14 ] = F_1 ( V_2 ,
V_24 [ V_14 ] ) ;
V_8 -> V_25 [ V_14 ] = F_1 ( V_2 ,
V_26 [ V_14 ] ) ;
V_8 -> V_27 [ V_14 ] = F_1 ( V_2 ,
V_28 [ V_14 ] ) ;
}
V_14 = F_1 ( V_2 , V_29 ) ;
V_15 = F_1 ( V_2 , V_30 ) ;
V_8 -> V_31 = F_20 ( V_14 , V_15 ) ;
V_14 = F_1 ( V_2 , V_32 ) ;
V_15 = F_1 ( V_2 , V_33 ) ;
V_8 -> V_34 = F_20 ( V_14 , V_15 ) ;
V_14 = F_1 ( V_2 , V_35 ) ;
V_8 -> V_36 [ 0 ] = ( V_14 >> 4 ) & 0x03 ;
V_8 -> V_36 [ 1 ] = ( V_14 >> 6 ) & 0x03 ;
V_8 -> V_37 = ( V_14 & 0x0F )
| ( F_1 ( V_2 , V_38 ) & 0x01 )
<< 4 ;
V_8 -> V_39 = F_1 ( V_2 , V_40 )
| ( F_1 ( V_2 , V_41 )
<< 8 ) ;
V_8 -> V_42 = F_1 ( V_2 , V_43 ) ;
V_8 -> V_11 = V_10 ;
V_8 -> V_13 = 1 ;
}
F_21 ( & V_8 -> V_9 ) ;
return V_8 ;
}
static T_2 F_22 ( struct V_6 * V_7 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_2 , F_24 ( V_8 -> V_18 [ V_47 ] ,
V_8 -> V_49 [ V_47 ] ) ) ;
}
static T_2 F_25 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_2 , F_24 ( V_8 -> V_19 [ V_47 ] ,
V_8 -> V_49 [ V_47 ] ) ) ;
}
static T_2 F_26 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_2 , F_24 ( V_8 -> V_20 [ V_47 ] ,
V_8 -> V_49 [ V_47 ] ) ) ;
}
static T_2 F_27 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
long V_51 ;
int V_52 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
V_8 -> V_19 [ V_47 ] = F_29 ( V_51 , V_8 -> V_49 [ V_47 ] ) ;
F_3 ( V_2 , V_47 < 6 ? F_12 ( V_47 ) :
F_17 ( V_47 - 6 ) , V_8 -> V_19 [ V_47 ] ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_30 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
long V_51 ;
int V_52 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
V_8 -> V_20 [ V_47 ] = F_29 ( V_51 , V_8 -> V_49 [ V_47 ] ) ;
F_3 ( V_2 , V_47 < 6 ? F_13 ( V_47 ) :
F_16 ( V_47 - 6 ) , V_8 -> V_20 [ V_47 ] ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_31 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_3 , F_32 ( V_8 -> V_23 [ V_47 ] ) ) ;
}
static T_2 F_33 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_3 ,
F_32 ( V_8 -> V_27 [ V_47 ] ) ) ;
}
static T_2 F_34 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_3 ,
F_32 ( V_8 -> V_25 [ V_47 ] ) ) ;
}
static T_2 F_35 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
long V_51 ;
int V_52 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
V_8 -> V_27 [ V_47 ] = F_36 ( V_51 ) ;
F_3 ( V_2 , V_28 [ V_47 ] , V_8 -> V_27 [ V_47 ] ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_37 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
long V_51 ;
int V_52 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
V_8 -> V_25 [ V_47 ] = F_36 ( V_51 ) ;
F_3 ( V_2 , V_26 [ V_47 ] , V_8 -> V_25 [ V_47 ] ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_38 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_46 , L_3 , F_32 ( V_8 -> V_31 ) ) ;
}
static T_2 F_39 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_46 , L_3 , F_32 ( V_8 -> V_34 ) ) ;
}
static T_2 F_40 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_3 , F_41 ( V_8 -> V_21 [ V_47 ] ,
F_42 ( V_8 -> V_36 [ V_47 ] ) ) ) ;
}
static T_2 F_43 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_3 , F_41 ( V_8 -> V_22 [ V_47 ] ,
F_42 ( V_8 -> V_36 [ V_47 ] ) ) ) ;
}
static T_2 F_44 ( struct V_6 * V_7 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_3 ,
F_42 ( V_8 -> V_36 [ V_47 ] ) ) ;
}
static T_2 F_45 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
long V_51 ;
int V_52 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
V_8 -> V_22 [ V_47 ] = F_46 ( V_51 ,
F_42 ( V_8 -> V_36 [ V_47 ] ) ) ;
F_3 ( V_2 , F_19 ( V_47 ) , V_8 -> V_22 [ V_47 ] ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_47 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
int V_47 = F_23 ( V_45 ) -> V_48 ;
long V_51 ;
int V_52 ;
unsigned long F_20 ;
T_1 V_3 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
F_20 = F_41 ( V_8 -> V_22 [ V_47 ] ,
F_42 ( V_8 -> V_36 [ V_47 ] ) ) ;
switch ( V_51 ) {
case 1 :
V_8 -> V_36 [ V_47 ] = 0 ;
break;
case 2 :
V_8 -> V_36 [ V_47 ] = 1 ;
break;
case 4 :
V_8 -> V_36 [ V_47 ] = 2 ;
break;
case 8 :
V_8 -> V_36 [ V_47 ] = 3 ;
break;
default:
F_21 ( & V_8 -> V_9 ) ;
return - V_53 ;
}
V_3 = F_1 ( V_2 , V_35 ) ;
switch ( V_47 ) {
case 0 :
V_3 = ( V_3 & 0xCF ) | ( V_8 -> V_36 [ 0 ] << 4 ) ;
break;
case 1 :
V_3 = ( V_3 & 0x3F ) | ( V_8 -> V_36 [ 1 ] << 6 ) ;
break;
}
F_3 ( V_2 , V_35 , V_3 ) ;
V_8 -> V_22 [ V_47 ] = F_46 ( F_20 , V_51 ) ;
F_3 ( V_2 , F_19 ( V_47 ) ,
V_8 -> V_22 [ V_47 ] ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_48 ( struct V_6 * V_7 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_46 , L_3 , V_8 -> V_39 ) ;
}
static T_2 F_49 ( struct V_6 * V_7 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_46 , L_3 , F_50 ( V_8 -> V_37 , V_8 -> V_54 ) ) ;
}
static T_2 F_51 ( struct V_6 * V_7 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_5 * V_8 = F_52 ( V_7 ) ;
return sprintf ( V_46 , L_3 , V_8 -> V_54 ) ;
}
static T_2 F_53 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_5 * V_8 = F_52 ( V_7 ) ;
unsigned long V_51 ;
int V_52 ;
V_52 = F_54 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_51 > 255 )
return - V_53 ;
V_8 -> V_54 = V_51 ;
return V_50 ;
}
static T_2 F_55 ( struct V_6 * V_7 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_46 , L_3 , F_56 ( V_8 -> V_42 ) ) ;
}
static T_2 F_57 ( struct V_6 * V_7 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_50 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
struct V_5 * V_8 = F_7 ( V_2 ) ;
long V_51 ;
int V_52 ;
V_52 = F_28 ( V_46 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
F_8 ( & V_8 -> V_9 ) ;
V_8 -> V_42 = F_58 ( V_51 ) ;
F_3 ( V_2 , V_43 , V_8 -> V_42 ) ;
F_21 ( & V_8 -> V_9 ) ;
return V_50 ;
}
static T_2 F_59 ( struct V_6 * V_7 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_55 = F_23 ( V_45 ) -> V_48 ;
return sprintf ( V_46 , L_2 , ( V_8 -> V_39 >> V_55 ) & 1 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_58 * V_59 = V_2 -> V_59 ;
const char * V_60 ;
T_1 V_61 , V_62 ;
if ( ! F_61 ( V_59 , V_63 ) )
return - V_64 ;
if ( F_1 ( V_2 , V_65 ) & 0x80 )
return - V_64 ;
V_61 = F_1 ( V_2 , V_66 ) ;
V_62 = F_1 ( V_2 , V_67 ) ;
if ( V_61 == 0x02
&& ( V_62 >= 0x01 && V_62 <= 0x08 ) )
V_60 = L_4 ;
else if ( V_61 == 0x41
&& ( V_62 & 0xf0 ) == 0x10 )
V_60 = L_5 ;
else {
F_10 ( & V_59 -> V_7 , L_6 ,
V_2 -> V_68 ) ;
return - V_64 ;
}
F_62 ( V_57 -> type , V_60 , V_69 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
F_64 ( & V_7 -> V_70 , & V_71 ) ;
F_64 ( & V_7 -> V_70 , & V_72 ) ;
F_64 ( & V_7 -> V_70 , & V_73 ) ;
F_64 ( & V_7 -> V_70 , & V_74 ) ;
F_64 ( & V_7 -> V_70 , & V_75 ) ;
F_64 ( & V_7 -> V_70 , & V_76 ) ;
F_64 ( & V_7 -> V_70 , & V_77 ) ;
F_64 ( & V_7 -> V_70 , & V_78 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_8 = F_7 ( V_2 ) ;
if ( F_66 ( & V_2 -> V_7 ) ) {
V_8 -> V_16 = * ( T_1 * ) F_66 ( & V_2 -> V_7 ) ;
F_3 ( V_2 ,
V_79 , V_8 -> V_16 ) ;
} else {
V_8 -> V_16 = F_1 ( V_2 , V_79 ) ;
}
V_8 -> V_80 = F_1 ( V_2 , V_65 ) & 0x6F ;
if ( ! ( V_8 -> V_80 & 0x01 ) ) {
int V_14 ;
for ( V_14 = 1 ; V_14 < 6 ; V_14 ++ ) {
F_3 ( V_2 , F_12 ( V_14 ) , 0x00 ) ;
F_3 ( V_2 , F_13 ( V_14 ) , 0xFF ) ;
}
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
F_3 ( V_2 , V_26 [ V_14 ] , 0x7F ) ;
F_3 ( V_2 , V_28 [ V_14 ] , 0x00 ) ;
F_3 ( V_2 , F_17 ( V_14 ) , 0x00 ) ;
F_3 ( V_2 , F_16 ( V_14 ) , 0xFF ) ;
}
if ( V_8 -> V_16 & V_17 ) {
F_3 ( V_2 , V_26 [ 2 ] , 0x7F ) ;
F_3 ( V_2 , V_28 [ 2 ] , 0x00 ) ;
} else {
F_3 ( V_2 , F_12 ( 0 ) , 0x00 ) ;
F_3 ( V_2 , F_13 ( 0 ) , 0xFF ) ;
}
}
if ( ( V_8 -> V_80 & 0x09 ) != 0x01 )
F_3 ( V_2 , V_65 ,
( V_8 -> V_80 & 0x77 ) | 0x01 ) ;
}
static int F_67 ( struct V_1 * V_2 , const struct V_81 * V_82 )
{
struct V_5 * V_8 ;
int V_52 ;
V_8 = F_68 ( & V_2 -> V_7 , sizeof( struct V_5 ) , V_83 ) ;
if ( ! V_8 )
return - V_84 ;
F_69 ( V_2 , V_8 ) ;
F_70 ( & V_8 -> V_9 ) ;
F_65 ( V_2 ) ;
V_8 -> V_49 [ 0 ] = 2500 ;
V_8 -> V_49 [ 1 ] = 2700 ;
V_8 -> V_49 [ 2 ] = ( V_8 -> V_16 & V_85 ) ? 5000 : 3300 ;
V_8 -> V_49 [ 3 ] = 5000 ;
V_8 -> V_49 [ 4 ] = 12000 ;
V_8 -> V_49 [ 5 ] = 2700 ;
V_8 -> V_49 [ 6 ] = 1875 ;
V_8 -> V_49 [ 7 ] = 1875 ;
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_71 ) ;
if ( V_52 )
goto V_86;
if ( V_8 -> V_16 & F_14 ( 0 ) ) {
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_72 ) ;
if ( V_52 )
goto V_87;
} else {
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_73 ) ;
if ( V_52 )
goto V_87;
}
if ( V_8 -> V_16 & F_14 ( 1 ) ) {
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_74 ) ;
if ( V_52 )
goto V_87;
} else {
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_75 ) ;
if ( V_52 )
goto V_87;
}
if ( V_8 -> V_16 & V_17 ) {
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_76 ) ;
if ( V_52 )
goto V_87;
} else {
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_77 ) ;
if ( V_52 )
goto V_87;
}
if ( ! ( V_8 -> V_16 & V_88 ) ) {
V_8 -> V_54 = F_72 () ;
V_52 = F_71 ( & V_2 -> V_7 . V_70 , & V_78 ) ;
if ( V_52 )
goto V_87;
}
V_8 -> V_89 = F_73 ( & V_2 -> V_7 ) ;
if ( F_74 ( V_8 -> V_89 ) ) {
V_52 = F_75 ( V_8 -> V_89 ) ;
goto V_87;
}
return 0 ;
V_87:
F_63 ( V_2 ) ;
V_86:
F_3 ( V_2 , V_65 , V_8 -> V_80 ) ;
return V_52 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_8 = F_7 ( V_2 ) ;
F_77 ( V_8 -> V_89 ) ;
F_63 ( V_2 ) ;
F_3 ( V_2 , V_65 , V_8 -> V_80 ) ;
return 0 ;
}
