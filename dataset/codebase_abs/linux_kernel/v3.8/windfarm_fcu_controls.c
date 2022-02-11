static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
F_5 ( & V_8 -> V_10 -> V_2 , F_1 ) ;
F_3 ( V_8 ) ;
}
static int F_6 ( struct V_3 * V_4 , int V_11 ,
unsigned char * V_12 , int V_13 )
{
int V_14 , V_15 , V_16 ;
F_7 ( & V_4 -> V_17 ) ;
V_12 [ 0 ] = V_11 ;
V_14 = 0 ;
for (; ; ) {
V_16 = F_8 ( V_4 -> V_18 , V_12 , 1 ) ;
if ( V_16 > 0 || ( V_16 < 0 && V_16 != - V_19 ) || V_14 >= 100 )
break;
F_9 ( 10 ) ;
++ V_14 ;
}
if ( V_16 <= 0 ) {
F_10 ( L_1 , V_16 ) ;
V_15 = V_16 ;
goto V_20;
}
V_14 = 0 ;
for (; ; ) {
V_15 = F_11 ( V_4 -> V_18 , V_12 , V_13 ) ;
if ( V_15 > 0 || ( V_15 < 0 && V_15 != - V_21 ) || V_14 >= 100 )
break;
F_9 ( 10 ) ;
++ V_14 ;
}
if ( V_15 <= 0 )
F_10 ( L_2 , V_16 ) ;
V_20:
F_12 ( & V_4 -> V_17 ) ;
return V_15 ;
}
static int F_13 ( struct V_3 * V_4 , int V_11 ,
const unsigned char * V_22 , int V_13 )
{
int V_14 , V_16 ;
unsigned char V_12 [ 16 ] ;
V_12 [ 0 ] = V_11 ;
memcpy ( V_12 + 1 , V_22 , V_13 ) ;
++ V_13 ;
V_14 = 0 ;
for (; ; ) {
V_16 = F_8 ( V_4 -> V_18 , V_12 , V_13 ) ;
if ( V_16 > 0 || ( V_16 < 0 && V_16 != - V_19 ) || V_14 >= 100 )
break;
F_9 ( 10 ) ;
++ V_14 ;
}
if ( V_16 < 0 )
F_10 ( L_3 , V_16 ) ;
return V_16 ;
}
static int F_14 ( struct V_5 * V_6 , T_1 V_23 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_3 * V_4 = V_8 -> V_10 ;
int V_24 , V_25 = V_4 -> V_26 ;
unsigned char V_12 [ 2 ] ;
if ( V_23 < V_8 -> V_27 )
V_23 = V_8 -> V_27 ;
if ( V_23 > V_8 -> V_28 )
V_23 = V_8 -> V_28 ;
V_8 -> V_29 = V_23 ;
V_12 [ 0 ] = V_23 >> ( 8 - V_25 ) ;
V_12 [ 1 ] = V_23 << V_25 ;
V_24 = F_13 ( V_4 , 0x10 + ( V_8 -> V_30 * 2 ) , V_12 , 2 ) ;
if ( V_24 < 0 )
return - V_19 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 , T_1 * V_23 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_3 * V_4 = V_8 -> V_10 ;
int V_24 , V_31 , V_25 = V_4 -> V_26 ;
unsigned char V_32 ;
unsigned char V_33 ;
unsigned char V_12 [ 2 ] ;
V_24 = F_6 ( V_4 , 0xb , & V_32 , 1 ) ;
if ( V_24 != 1 )
return - V_19 ;
if ( ( V_32 & ( 1 << V_8 -> V_30 ) ) != 0 )
return - V_34 ;
V_24 = F_6 ( V_4 , 0xd , & V_33 , 1 ) ;
if ( V_24 != 1 )
return - V_19 ;
if ( ( V_33 & ( 1 << V_8 -> V_30 ) ) == 0 )
return - V_35 ;
#if V_36
V_31 = 0x11 ;
#else
V_31 = 0x10 ;
#endif
V_24 = F_6 ( V_4 , V_31 + ( V_8 -> V_30 * 2 ) , V_12 , 2 ) ;
if ( V_24 != 2 )
return - V_19 ;
* V_23 = ( V_12 [ 0 ] << ( 8 - V_25 ) ) | V_12 [ 1 ] >> V_25 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 , T_1 V_23 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_3 * V_4 = V_8 -> V_10 ;
unsigned char V_12 [ 2 ] ;
int V_24 ;
if ( V_23 < V_8 -> V_27 )
V_23 = V_8 -> V_27 ;
if ( V_23 > V_8 -> V_28 )
V_23 = V_8 -> V_28 ;
V_8 -> V_29 = V_23 ;
V_23 = ( V_23 * 2559 ) / 1000 ;
V_12 [ 0 ] = V_23 ;
V_24 = F_13 ( V_4 , 0x30 + ( V_8 -> V_30 * 2 ) , V_12 , 1 ) ;
if ( V_24 < 0 )
return - V_19 ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 , T_1 * V_23 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_3 * V_4 = V_8 -> V_10 ;
unsigned char V_32 ;
unsigned char V_33 ;
unsigned char V_12 [ 2 ] ;
int V_24 ;
V_24 = F_6 ( V_4 , 0x2b , & V_32 , 1 ) ;
if ( V_24 != 1 )
return - V_19 ;
if ( ( V_32 & ( 1 << V_8 -> V_30 ) ) != 0 )
return - V_34 ;
V_24 = F_6 ( V_4 , 0x2d , & V_33 , 1 ) ;
if ( V_24 != 1 )
return - V_19 ;
if ( ( V_33 & ( 1 << V_8 -> V_30 ) ) == 0 )
return - V_35 ;
V_24 = F_6 ( V_4 , 0x30 + ( V_8 -> V_30 * 2 ) , V_12 , 1 ) ;
if ( V_24 != 1 )
return - V_19 ;
* V_23 = ( ( ( T_1 ) V_12 [ 0 ] ) * 1000 ) / 2559 ;
return 0 ;
}
static T_1 F_18 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
return V_8 -> V_27 ;
}
static T_1 F_19 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
return V_8 -> V_28 ;
}
static void F_20 ( struct V_7 * V_8 )
{
const struct V_37 * V_38 = F_21 ( 0 ) ;
T_2 V_39 = 0 , V_40 = 0xffff ;
T_2 V_41 [ 4 ] ;
if ( V_38 ) {
memcpy ( & V_41 , V_38 -> V_42 , 8 ) ;
if ( V_41 [ 0 ] != 0xffff && V_41 [ 1 ] != 0xffff ) {
V_39 = V_28 ( V_39 , V_41 [ 0 ] ) ;
V_40 = V_27 ( V_40 , V_41 [ 1 ] ) ;
}
if ( V_41 [ 2 ] != 0xffff && V_41 [ 3 ] != 0xffff ) {
V_39 = V_28 ( V_39 , V_41 [ 2 ] ) ;
V_40 = V_27 ( V_40 , V_41 [ 3 ] ) ;
}
}
if ( V_39 == V_40 || V_39 == 0 || V_40 == 0xffff ) {
V_39 = V_43 ;
V_40 = V_44 ;
}
V_8 -> V_27 = V_39 ;
V_8 -> V_28 = V_40 ;
F_22 ( L_4 ,
V_8 -> V_45 . V_46 , V_39 , V_40 ) ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_10 ;
const struct V_37 * V_47 = F_21 ( 0 ) ;
const struct V_37 * V_48 = F_21 ( 1 ) ;
V_8 -> V_27 = 2400 >> V_4 -> V_26 ;
V_8 -> V_28 = 56000 >> V_4 -> V_26 ;
if ( V_47 && ! strcmp ( V_8 -> V_45 . V_46 , L_5 ) ) {
V_8 -> V_27 = V_28 ( V_8 -> V_27 , ( T_1 ) V_47 -> V_49 ) ;
V_8 -> V_28 = V_27 ( V_8 -> V_28 , ( T_1 ) V_47 -> V_50 ) ;
goto V_20;
}
if ( V_48 && ! strcmp ( V_8 -> V_45 . V_46 , L_6 ) ) {
V_8 -> V_27 = V_28 ( V_8 -> V_27 , ( T_1 ) V_48 -> V_49 ) ;
V_8 -> V_28 = V_27 ( V_8 -> V_28 , ( T_1 ) V_48 -> V_50 ) ;
goto V_20;
}
if ( V_47 && ! strcmp ( V_8 -> V_45 . V_46 , L_7 ) ) {
V_8 -> V_27 = V_28 ( V_8 -> V_27 , ( T_1 ) V_47 -> V_51 ) ;
V_8 -> V_28 = V_27 ( V_8 -> V_28 , ( T_1 ) V_47 -> V_52 ) ;
goto V_20;
}
if ( V_48 && ! strcmp ( V_8 -> V_45 . V_46 , L_8 ) ) {
V_8 -> V_27 = V_28 ( V_8 -> V_27 , ( T_1 ) V_48 -> V_51 ) ;
V_8 -> V_28 = V_27 ( V_8 -> V_28 , ( T_1 ) V_48 -> V_52 ) ;
goto V_20;
}
if ( ! strncmp ( V_8 -> V_45 . V_46 , L_9 , 7 ) ) {
V_8 -> V_27 = V_28 ( V_8 -> V_27 , ( T_1 ) V_47 -> V_49 ) ;
V_8 -> V_28 = V_27 ( V_8 -> V_28 , ( T_1 ) V_47 -> V_50 ) ;
goto V_20;
}
V_20:
F_22 ( L_10 ,
V_8 -> V_45 . V_46 , V_8 -> V_27 , V_8 -> V_28 ) ;
}
static void F_24 ( struct V_3 * V_4 , const char * V_46 ,
int type , int V_30 )
{
struct V_7 * V_8 ;
V_8 = F_25 ( sizeof( * V_8 ) , V_53 ) ;
if ( ! V_8 )
return;
V_8 -> V_10 = V_4 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_45 . V_46 = V_46 ;
V_8 -> V_45 . V_9 = V_8 ;
if ( type == V_54 ) {
if ( ! strncmp ( V_46 , L_11 , strlen ( L_11 ) ) )
F_20 ( V_8 ) ;
else
F_23 ( V_8 ) ;
V_8 -> V_45 . type = V_55 ;
V_8 -> V_45 . V_56 = & V_57 ;
} else {
V_8 -> V_27 = 10 ;
V_8 -> V_28 = 100 ;
V_8 -> V_45 . type = V_58 ;
V_8 -> V_45 . V_56 = & V_59 ;
}
if ( F_26 ( & V_8 -> V_45 ) ) {
F_10 ( L_12 , V_46 ) ;
F_3 ( V_8 ) ;
return;
}
F_27 ( & V_8 -> V_60 , & V_4 -> V_61 ) ;
F_28 ( & V_4 -> V_2 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
static const struct {
const char * V_62 ;
const char * V_63 ;
} V_64 [] = {
{ L_13 , L_14 , } ,
{ L_15 , L_14 , } ,
{ L_16 , L_17 , } ,
{ L_18 , L_19 , } ,
{ L_20 , L_19 , } ,
{ L_21 , L_5 , } ,
{ L_22 , L_7 , } ,
{ L_23 , L_6 , } ,
{ L_24 , L_8 , } ,
{ L_25 , L_26 , } ,
{ L_27 , L_28 , } ,
{ L_29 , L_30 , } ,
{ L_31 , L_32 , } ,
{ L_33 , L_34 , } ,
{ L_35 , L_36 , } ,
{ L_37 , L_38 , } ,
{ L_39 , L_40 , } ,
} ;
struct V_65 * V_66 = NULL , * V_67 = V_4 -> V_18 -> V_68 . V_69 ;
int V_70 ;
F_22 ( L_41 ) ;
while ( ( V_66 = F_30 ( V_67 , V_66 ) ) != NULL ) {
int V_30 , type = - 1 ;
const char * V_71 ;
const char * V_46 ;
const T_3 * V_11 ;
F_22 ( L_42 , V_66 -> V_46 , V_66 -> type ) ;
if ( ! strcmp ( V_66 -> type , L_43 ) ||
! strcmp ( V_66 -> type , L_44 ) )
type = V_54 ;
if ( ! strcmp ( V_66 -> type , L_45 ) ||
! strcmp ( V_66 -> type , L_46 ) )
type = V_72 ;
if ( type == - 1 )
continue;
V_71 = F_31 ( V_66 , L_47 , NULL ) ;
V_11 = F_31 ( V_66 , L_48 , NULL ) ;
if ( V_71 == NULL || V_11 == NULL )
continue;
F_22 ( L_49 , V_71 , * V_11 ) ;
for ( V_70 = 0 ; V_70 < F_32 ( V_64 ) ; V_70 ++ ) {
if ( strncmp ( V_71 , V_64 [ V_70 ] . V_62 ,
strlen ( V_64 [ V_70 ] . V_62 ) ) )
continue;
V_46 = V_64 [ V_70 ] . V_63 ;
F_22 ( L_50 , V_46 ) ;
if ( type == V_54 )
V_30 = ( ( * V_11 ) - 0x10 ) / 2 ;
else
V_30 = ( ( * V_11 ) - 0x30 ) / 2 ;
if ( V_30 > 7 ) {
F_33 ( L_51
L_52 ,
V_66 -> V_73 ) ;
break;
}
F_24 ( V_4 , V_46 , type , V_30 ) ;
break;
}
}
}
static void F_34 ( struct V_3 * V_4 )
{
if ( ! F_35 ( L_53 ) )
return;
F_24 ( V_4 , L_14 , V_72 , 1 ) ;
F_24 ( V_4 , L_17 , V_54 , 2 ) ;
F_24 ( V_4 , L_19 , V_72 , 2 ) ;
F_24 ( V_4 , L_5 , V_54 , 3 ) ;
F_24 ( V_4 , L_7 , V_54 , 4 ) ;
F_24 ( V_4 , L_6 , V_54 , 5 ) ;
F_24 ( V_4 , L_8 , V_54 , 6 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
unsigned char V_12 = 0xff ;
int V_24 ;
V_24 = F_13 ( V_4 , 0xe , & V_12 , 1 ) ;
if ( V_24 < 0 )
return - V_19 ;
V_24 = F_13 ( V_4 , 0x2e , & V_12 , 1 ) ;
if ( V_24 < 0 )
return - V_19 ;
V_24 = F_6 ( V_4 , 0 , & V_12 , 1 ) ;
if ( V_24 < 0 )
return - V_19 ;
V_4 -> V_26 = ( V_12 == 1 ) ? 2 : 3 ;
F_37 ( L_54 ,
V_4 -> V_26 ) ;
return 0 ;
}
static int F_38 ( struct V_74 * V_75 ,
const struct V_76 * V_30 )
{
struct V_3 * V_4 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_77 ;
F_39 ( & V_4 -> V_2 ) ;
F_40 ( & V_4 -> V_17 ) ;
F_41 ( & V_4 -> V_61 ) ;
V_4 -> V_18 = V_75 ;
if ( F_36 ( V_4 ) ) {
F_10 ( L_55 ) ;
F_3 ( V_4 ) ;
return - V_35 ;
}
F_29 ( V_4 ) ;
if ( F_42 ( & V_4 -> V_61 ) )
F_34 ( V_4 ) ;
if ( F_42 ( & V_4 -> V_61 ) ) {
F_10 ( L_56 ) ;
F_3 ( V_4 ) ;
return - V_21 ;
}
F_43 ( & V_75 -> V_68 , V_4 ) ;
return 0 ;
}
static int F_44 ( struct V_74 * V_75 )
{
struct V_3 * V_4 = F_45 ( & V_75 -> V_68 ) ;
struct V_7 * V_8 ;
while ( ! F_42 ( & V_4 -> V_61 ) ) {
V_8 = F_46 ( & V_4 -> V_61 , struct V_7 , V_60 ) ;
F_47 ( & V_8 -> V_60 ) ;
F_48 ( & V_8 -> V_45 ) ;
}
F_5 ( & V_4 -> V_2 , F_1 ) ;
return 0 ;
}
