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
} else
F_7 ( V_18 [ V_19 + 1 ] * 1000 ) ;
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
static int F_15 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 = NULL ;
V_40 = V_2 -> V_43 ;
if ( ! V_40 ) {
F_9 ( V_2 -> V_23 , L_4 ) ;
return - V_44 ;
}
V_42 = V_2 -> V_42 ;
if ( ! V_42 ) {
F_9 ( V_2 -> V_23 , L_5 ) ;
return - V_44 ;
}
if ( ! V_40 -> V_45 ) {
F_9 ( V_2 -> V_23 , L_6 ) ;
return - V_44 ;
} else {
V_40 -> V_45 ( V_2 -> V_46 , 1 ) ;
F_16 ( V_40 -> V_47 ) ;
}
if ( ! V_40 -> V_48 ) {
F_9 ( V_2 -> V_23 , L_7 ) ;
return - V_44 ;
} else {
V_40 -> V_48 ( V_2 -> V_46 ) ;
F_16 ( V_40 -> V_49 ) ;
}
V_15 = F_11 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_8 ) ;
return V_15 ;
}
V_15 = F_13 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_9 ) ;
return V_15 ;
}
V_15 = F_10 ( V_2 , V_42 -> V_50 . V_51 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_10 ) ;
return V_15 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_39 * V_40 = NULL ;
V_40 = V_2 -> V_43 ;
if ( ! V_40 ) {
F_9 ( V_2 -> V_23 , L_4 ) ;
return - V_44 ;
}
V_15 = F_14 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_23 , L_11 ) ;
return - V_52 ;
}
F_16 ( V_40 -> V_53 ) ;
if ( ! V_40 -> V_45 ) {
F_9 ( V_2 -> V_23 , L_6 ) ;
return - V_44 ;
} else
V_40 -> V_45 ( V_2 -> V_46 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_54 )
{
int V_15 = 0 ;
if ( F_19 ( V_54 ) && ! F_19 ( V_2 -> V_54 ) )
V_15 = F_15 ( V_2 ) ;
else if ( ! F_19 ( V_54 ) && F_19 ( V_2 -> V_54 ) )
V_15 = F_17 ( V_2 ) ;
if ( ! V_15 )
V_2 -> V_54 = V_54 ;
return V_15 ;
}
static int F_20 ( struct V_55 * V_46 , int V_54 )
{
struct V_1 * V_2 = F_21 ( V_46 ) ;
if ( V_54 != V_56 && V_54 != V_57 &&
V_54 != V_58 ) {
F_9 ( V_2 -> V_23 , L_12 ) ;
return - V_59 ;
}
return F_18 ( V_2 , V_54 ) ;
}
static int F_22 ( struct V_55 * V_46 )
{
struct V_1 * V_2 = F_21 ( V_46 ) ;
return V_2 -> V_54 ;
}
static int F_23 ( struct V_41 * V_42 )
{
return V_42 -> V_50 . V_51 ;
}
static int F_24 ( struct V_41 * V_42 )
{
int V_15 = 0 , V_51 = V_42 -> V_50 . V_51 ;
struct V_1 * V_2 = F_25 ( V_42 ) ;
if ( V_51 < V_60 ||
V_51 > V_42 -> V_50 . V_61 ) {
F_9 ( & V_42 -> V_23 , L_13 ,
V_60 , V_62 ) ;
return - V_59 ;
}
V_15 = F_10 ( V_2 , V_42 -> V_50 . V_51 ) ;
if ( V_15 ) {
F_9 ( & V_42 -> V_23 , L_14 ) ;
return - V_52 ;
}
return V_15 ;
}
static T_2 F_26 ( struct V_63 * V_23 ,
struct V_64 * V_65 , char * V_5 )
{
struct V_1 * V_2 = F_27 ( V_23 ) ;
char V_66 [ 10 ] ;
switch ( V_2 -> V_67 ) {
case 0 :
sprintf ( V_66 , L_15 ) ;
strcat ( V_5 , V_66 ) ;
break;
case 1 :
sprintf ( V_66 , L_16 ) ;
strcat ( V_5 , V_66 ) ;
break;
case 2 :
sprintf ( V_66 , L_17 ) ;
strcat ( V_5 , V_66 ) ;
break;
default:
F_28 ( V_23 , L_18 ) ;
break;
}
return strlen ( V_5 ) ;
}
static T_2 F_29 ( struct V_63 * V_23 ,
struct V_64 * V_65 ,
const char * V_5 , T_3 V_10 )
{
struct V_1 * V_2 = F_27 ( V_23 ) ;
struct V_41 * V_42 = NULL ;
int V_51 , V_68 ;
V_68 = F_30 ( V_5 , 0 , & V_2 -> V_67 ) ;
if ( V_68 < 0 )
return V_68 ;
V_42 = V_2 -> V_42 ;
V_51 = V_42 -> V_50 . V_51 ;
switch ( V_2 -> V_67 ) {
case 0 :
F_8 ( V_2 , V_26 . V_27 [ V_51 ] ) ;
break;
case 1 :
F_8 ( V_2 , V_26 . V_69 [ V_51 ] ) ;
break;
case 2 :
F_8 ( V_2 , V_26 . V_70 [ V_51 ] ) ;
break;
default:
F_28 ( V_23 , L_19 ) ;
F_8 ( V_2 , V_26 . V_27 [ V_51 ] ) ;
break;
}
return V_10 ;
}
static T_2 F_31 ( struct V_63 * V_23 ,
struct V_64 * V_65 , char * V_5 )
{
struct V_1 * V_2 = F_27 ( V_23 ) ;
char V_66 [ 3 ] ;
sprintf ( V_66 , L_20 , V_2 -> V_71 ) ;
strcpy ( V_5 , V_66 ) ;
return strlen ( V_5 ) ;
}
static int F_32 ( struct V_72 * V_12 )
{
int V_15 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_55 * V_46 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_73 V_50 ;
V_2 = F_33 ( & V_12 -> V_23 , sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_12 -> V_76 = 9 ;
V_15 = F_34 ( V_12 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_12 -> V_23 , L_21 ) ;
return V_15 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = & V_12 -> V_23 ;
V_2 -> V_43 = V_12 -> V_23 . V_77 ;
if ( ! V_2 -> V_43 ) {
F_9 ( & V_12 -> V_23 , L_4 ) ;
return - V_44 ;
}
V_46 = F_35 ( L_22 , & V_12 -> V_23 , V_2 , & V_78 ) ;
if ( F_36 ( V_46 ) )
return F_37 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
memset ( & V_50 , 0 , sizeof( struct V_73 ) ) ;
V_50 . type = V_79 ;
V_50 . V_61 = V_62 ;
V_42 = F_38 ( L_23 , & V_12 -> V_23 , V_2 ,
& V_80 , & V_50 ) ;
if ( F_36 ( V_42 ) ) {
V_15 = F_37 ( V_42 ) ;
goto V_81;
}
V_42 -> V_50 . V_51 = V_62 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_71 =
sizeof( V_26 ) / ( V_82 * sizeof( int ) ) ;
V_15 = F_39 ( & ( V_12 -> V_23 ) , & V_83 ) ;
if ( V_15 < 0 )
F_9 ( & ( V_12 -> V_23 ) , L_24 ) ;
V_15 = F_39 ( & ( V_12 -> V_23 ) , & V_84 ) ;
if ( V_15 < 0 )
F_9 ( & ( V_12 -> V_23 ) , L_24 ) ;
if ( ! V_2 -> V_43 -> V_85 ) {
V_2 -> V_54 = V_57 ;
F_18 ( V_2 , V_56 ) ;
} else
V_2 -> V_54 = V_56 ;
F_40 ( & V_12 -> V_23 , V_2 ) ;
F_28 ( & V_12 -> V_23 , L_25 ) ;
return 0 ;
V_81:
F_41 ( V_46 ) ;
return V_15 ;
}
static int F_42 ( struct V_72 * V_12 )
{
struct V_1 * V_2 = F_27 ( & V_12 -> V_23 ) ;
F_18 ( V_2 , V_57 ) ;
F_43 ( & V_12 -> V_23 , & V_84 ) ;
F_43 ( & V_12 -> V_23 , & V_83 ) ;
F_44 ( V_2 -> V_42 ) ;
F_41 ( V_2 -> V_46 ) ;
return 0 ;
}
static int F_45 ( struct V_72 * V_12 , T_4 V_86 )
{
int V_15 = 0 ;
struct V_1 * V_2 = F_27 ( & V_12 -> V_23 ) ;
F_46 ( & V_12 -> V_23 , L_26 , V_2 -> V_54 ) ;
V_87 = V_2 -> V_54 ;
V_15 = F_18 ( V_2 , V_57 ) ;
return V_15 ;
}
static int F_47 ( struct V_72 * V_12 )
{
int V_15 = 0 ;
struct V_1 * V_2 = F_27 ( & V_12 -> V_23 ) ;
if ( V_87 == V_56 )
V_2 -> V_54 = V_57 ;
F_46 ( & V_12 -> V_23 , L_27 , V_87 ) ;
V_15 = F_18 ( V_2 , V_87 ) ;
return V_15 ;
}
static void F_48 ( struct V_72 * V_12 )
{
struct V_1 * V_2 = F_27 ( & V_12 -> V_23 ) ;
F_18 ( V_2 , V_57 ) ;
}
