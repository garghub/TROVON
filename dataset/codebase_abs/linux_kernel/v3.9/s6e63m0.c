static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
T_1 V_5 [ 1 ] ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 2 ,
. V_11 = V_5 ,
} ;
V_5 [ 0 ] = ( V_3 << 8 ) | V_4 ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
return F_4 ( V_2 -> V_12 , & V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char V_13 ,
unsigned char V_14 )
{
int V_15 = 0 ;
if ( V_13 != V_16 )
V_15 = F_1 ( V_2 , 0x0 , V_13 ) ;
if ( V_14 != V_17 )
V_15 = F_1 ( V_2 , 0x1 , V_14 ) ;
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
const unsigned short * V_18 )
{
int V_15 = 0 , V_19 = 0 ;
while ( ( V_18 [ V_19 ] & V_20 ) != V_21 ) {
if ( ( V_18 [ V_19 ] & V_20 ) != V_22 ) {
V_15 = F_5 ( V_2 , V_18 [ V_19 ] , V_18 [ V_19 + 1 ] ) ;
if ( V_15 )
break;
} else {
F_7 ( V_18 [ V_19 + 1 ] ) ;
}
V_19 += 2 ;
}
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 , const unsigned int * gamma )
{
unsigned int V_19 = 0 ;
int V_15 = 0 ;
V_15 = F_5 ( V_2 , 0xfa , 0x00 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_1 ) ;
goto V_24;
}
for ( V_19 = 0 ; V_19 < V_25 ; V_19 ++ ) {
V_15 = F_5 ( V_2 , V_16 , gamma [ V_19 ] ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_2 ) ;
goto V_24;
}
}
V_15 = F_5 ( V_2 , 0xfa , 0x01 ) ;
if ( V_15 )
F_9 ( V_2 -> V_23 , L_3 ) ;
V_24:
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 , int gamma )
{
int V_15 = 0 ;
V_15 = F_8 ( V_2 , V_26 . V_27 [ gamma ] ) ;
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_15 , V_19 ;
const unsigned short * V_28 [] = {
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ,
V_34 ,
} ;
for ( V_19 = 0 ; V_19 < F_12 ( V_28 ) ; V_19 ++ ) {
V_15 = F_6 ( V_2 , V_28 [ V_19 ] ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_15 = 0 , V_19 ;
const unsigned short * V_35 [] = {
V_36 ,
V_37 ,
} ;
for ( V_19 = 0 ; V_19 < F_12 ( V_35 ) ; V_19 ++ ) {
V_15 = F_6 ( V_2 , V_35 [ V_19 ] ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_6 ( V_2 , V_38 ) ;
return V_15 ;
}
static int F_15 ( int V_39 )
{
return V_39 <= V_40 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_42 = V_2 -> V_45 ;
V_44 = V_2 -> V_44 ;
if ( ! V_42 -> V_46 ) {
F_9 ( V_2 -> V_23 , L_4 ) ;
return - V_47 ;
} else {
V_42 -> V_46 ( V_2 -> V_48 , 1 ) ;
F_7 ( V_42 -> V_49 ) ;
}
if ( ! V_42 -> V_50 ) {
F_9 ( V_2 -> V_23 , L_5 ) ;
return - V_47 ;
} else {
V_42 -> V_50 ( V_2 -> V_48 ) ;
F_7 ( V_42 -> V_51 ) ;
}
V_15 = F_11 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_6 ) ;
return V_15 ;
}
V_15 = F_13 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_7 ) ;
return V_15 ;
}
V_15 = F_10 ( V_2 , V_44 -> V_52 . V_53 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_8 ) ;
return V_15 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 ;
struct V_41 * V_42 ;
V_42 = V_2 -> V_45 ;
V_15 = F_14 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_9 ) ;
return - V_54 ;
}
F_7 ( V_42 -> V_55 ) ;
V_42 -> V_46 ( V_2 -> V_48 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_39 )
{
int V_15 = 0 ;
if ( F_15 ( V_39 ) && ! F_15 ( V_2 -> V_39 ) )
V_15 = F_16 ( V_2 ) ;
else if ( ! F_15 ( V_39 ) && F_15 ( V_2 -> V_39 ) )
V_15 = F_17 ( V_2 ) ;
if ( ! V_15 )
V_2 -> V_39 = V_39 ;
return V_15 ;
}
static int F_19 ( struct V_56 * V_48 , int V_39 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
if ( V_39 != V_57 && V_39 != V_58 &&
V_39 != V_40 ) {
F_9 ( V_2 -> V_23 , L_10 ) ;
return - V_47 ;
}
return F_18 ( V_2 , V_39 ) ;
}
static int F_21 ( struct V_56 * V_48 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
return V_2 -> V_39 ;
}
static int F_22 ( struct V_43 * V_44 )
{
return V_44 -> V_52 . V_53 ;
}
static int F_23 ( struct V_43 * V_44 )
{
int V_15 = 0 , V_53 = V_44 -> V_52 . V_53 ;
struct V_1 * V_2 = F_24 ( V_44 ) ;
if ( V_53 < V_59 ||
V_53 > V_44 -> V_52 . V_60 ) {
F_9 ( & V_44 -> V_23 , L_11 ,
V_59 , V_61 ) ;
return - V_47 ;
}
V_15 = F_10 ( V_2 , V_44 -> V_52 . V_53 ) ;
if ( V_15 ) {
F_9 ( & V_44 -> V_23 , L_12 ) ;
return - V_54 ;
}
return V_15 ;
}
static T_2 F_25 ( struct V_62 * V_23 ,
struct V_63 * V_64 , char * V_5 )
{
struct V_1 * V_2 = F_26 ( V_23 ) ;
char V_65 [ 10 ] ;
switch ( V_2 -> V_66 ) {
case 0 :
sprintf ( V_65 , L_13 ) ;
strcat ( V_5 , V_65 ) ;
break;
case 1 :
sprintf ( V_65 , L_14 ) ;
strcat ( V_5 , V_65 ) ;
break;
case 2 :
sprintf ( V_65 , L_15 ) ;
strcat ( V_5 , V_65 ) ;
break;
default:
F_27 ( V_23 , L_16 ) ;
break;
}
return strlen ( V_5 ) ;
}
static T_2 F_28 ( struct V_62 * V_23 ,
struct V_63 * V_64 ,
const char * V_5 , T_3 V_10 )
{
struct V_1 * V_2 = F_26 ( V_23 ) ;
struct V_43 * V_44 = NULL ;
int V_53 , V_67 ;
V_67 = F_29 ( V_5 , 0 , & V_2 -> V_66 ) ;
if ( V_67 < 0 )
return V_67 ;
V_44 = V_2 -> V_44 ;
V_53 = V_44 -> V_52 . V_53 ;
switch ( V_2 -> V_66 ) {
case 0 :
F_8 ( V_2 , V_26 . V_27 [ V_53 ] ) ;
break;
case 1 :
F_8 ( V_2 , V_26 . V_68 [ V_53 ] ) ;
break;
case 2 :
F_8 ( V_2 , V_26 . V_69 [ V_53 ] ) ;
break;
default:
F_27 ( V_23 , L_17 ) ;
F_8 ( V_2 , V_26 . V_27 [ V_53 ] ) ;
break;
}
return V_10 ;
}
static T_2 F_30 ( struct V_62 * V_23 ,
struct V_63 * V_64 , char * V_5 )
{
struct V_1 * V_2 = F_26 ( V_23 ) ;
char V_65 [ 3 ] ;
sprintf ( V_65 , L_18 , V_2 -> V_70 ) ;
strcpy ( V_5 , V_65 ) ;
return strlen ( V_5 ) ;
}
static int F_31 ( struct V_71 * V_12 )
{
int V_15 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_56 * V_48 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_72 V_52 ;
V_2 = F_32 ( & V_12 -> V_23 , sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_12 -> V_75 = 9 ;
V_15 = F_33 ( V_12 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_12 -> V_23 , L_19 ) ;
return V_15 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = & V_12 -> V_23 ;
V_2 -> V_45 = V_12 -> V_23 . V_76 ;
if ( ! V_2 -> V_45 ) {
F_9 ( & V_12 -> V_23 , L_20 ) ;
return - V_47 ;
}
V_48 = F_34 ( L_21 , & V_12 -> V_23 , V_2 , & V_77 ) ;
if ( F_35 ( V_48 ) )
return F_36 ( V_48 ) ;
V_2 -> V_48 = V_48 ;
memset ( & V_52 , 0 , sizeof( struct V_72 ) ) ;
V_52 . type = V_78 ;
V_52 . V_60 = V_61 ;
V_44 = F_37 ( L_22 , & V_12 -> V_23 , V_2 ,
& V_79 , & V_52 ) ;
if ( F_35 ( V_44 ) ) {
V_15 = F_36 ( V_44 ) ;
goto V_80;
}
V_44 -> V_52 . V_53 = V_61 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_70 =
sizeof( V_26 ) / ( V_81 * sizeof( int * ) ) ;
V_15 = F_38 ( & ( V_12 -> V_23 ) , & V_82 ) ;
if ( V_15 < 0 )
F_9 ( & ( V_12 -> V_23 ) , L_23 ) ;
V_15 = F_38 ( & ( V_12 -> V_23 ) , & V_83 ) ;
if ( V_15 < 0 )
F_9 ( & ( V_12 -> V_23 ) , L_23 ) ;
if ( ! V_2 -> V_45 -> V_84 ) {
V_2 -> V_39 = V_58 ;
F_18 ( V_2 , V_57 ) ;
} else {
V_2 -> V_39 = V_57 ;
}
F_39 ( V_12 , V_2 ) ;
F_27 ( & V_12 -> V_23 , L_24 ) ;
return 0 ;
V_80:
F_40 ( V_48 ) ;
return V_15 ;
}
static int F_41 ( struct V_71 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
F_18 ( V_2 , V_58 ) ;
F_43 ( & V_12 -> V_23 , & V_83 ) ;
F_43 ( & V_12 -> V_23 , & V_82 ) ;
F_44 ( V_2 -> V_44 ) ;
F_40 ( V_2 -> V_48 ) ;
return 0 ;
}
static int F_45 ( struct V_71 * V_12 , T_4 V_85 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
F_46 ( & V_12 -> V_23 , L_25 , V_2 -> V_39 ) ;
return F_18 ( V_2 , V_58 ) ;
}
static int F_47 ( struct V_71 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
V_2 -> V_39 = V_58 ;
return F_18 ( V_2 , V_57 ) ;
}
static void F_48 ( struct V_71 * V_12 )
{
struct V_1 * V_2 = F_42 ( V_12 ) ;
F_18 ( V_2 , V_58 ) ;
}
