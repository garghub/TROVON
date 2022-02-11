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
V_15 = F_6 ( V_2 , V_23 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_1 ) ;
goto V_25;
}
for ( V_19 = 0 ; V_19 < V_26 ; V_19 ++ ) {
V_15 = F_5 ( V_2 , V_16 , gamma [ V_19 ] ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_2 ) ;
goto V_25;
}
}
V_15 = F_6 ( V_2 , V_27 ) ;
if ( V_15 )
F_9 ( V_2 -> V_24 , L_3 ) ;
V_25:
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 , int gamma )
{
int V_15 = 0 ;
V_15 = F_8 ( V_2 , V_28 . V_29 [ gamma ] ) ;
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_15 , V_19 ;
static const unsigned short * V_30 [] = {
V_31 ,
V_32 ,
V_33 ,
V_34 ,
V_35 ,
V_36 ,
V_37 ,
V_27 ,
V_38 ,
} ;
for ( V_19 = 0 ; V_19 < F_12 ( V_30 ) ; V_19 ++ ) {
V_15 = F_6 ( V_2 , V_30 [ V_19 ] ) ;
F_7 ( 300 ) ;
if ( V_15 )
break;
}
return V_15 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
V_15 = F_6 ( V_2 , V_39 ) ;
return V_15 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_6 ( V_2 , V_40 ) ;
V_15 = F_6 ( V_2 , V_41 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_42 * V_43 = NULL ;
V_43 = V_2 -> V_44 ;
if ( ! V_43 ) {
F_9 ( V_2 -> V_24 , L_4 ) ;
return - V_45 ;
}
if ( ! V_43 -> V_46 ) {
F_9 ( V_2 -> V_24 , L_5 ) ;
return - V_45 ;
} else {
V_43 -> V_46 ( V_2 -> V_47 , 1 ) ;
F_16 ( V_43 -> V_48 ) ;
}
if ( ! V_43 -> V_49 ) {
F_9 ( V_2 -> V_24 , L_6 ) ;
return - V_45 ;
} else {
V_43 -> V_49 ( V_2 -> V_47 ) ;
F_16 ( V_43 -> V_50 ) ;
}
V_15 = F_11 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_7 ) ;
return V_15 ;
}
V_15 = F_13 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_8 ) ;
return V_15 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
struct V_42 * V_43 = NULL ;
V_43 = V_2 -> V_44 ;
if ( ! V_43 ) {
F_9 ( V_2 -> V_24 , L_4 ) ;
return - V_45 ;
}
V_15 = F_14 ( V_2 ) ;
if ( V_15 ) {
F_9 ( V_2 -> V_24 , L_9 ) ;
return - V_51 ;
}
F_16 ( V_43 -> V_52 ) ;
if ( ! V_43 -> V_46 ) {
F_9 ( V_2 -> V_24 , L_5 ) ;
return - V_45 ;
} else
V_43 -> V_46 ( V_2 -> V_47 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_53 )
{
int V_15 = 0 ;
if ( F_19 ( V_53 ) && ! F_19 ( V_2 -> V_53 ) )
V_15 = F_15 ( V_2 ) ;
else if ( ! F_19 ( V_53 ) && F_19 ( V_2 -> V_53 ) )
V_15 = F_17 ( V_2 ) ;
if ( ! V_15 )
V_2 -> V_53 = V_53 ;
return V_15 ;
}
static int F_20 ( struct V_54 * V_47 , int V_53 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
if ( V_53 != V_55 && V_53 != V_56 &&
V_53 != V_57 ) {
F_9 ( V_2 -> V_24 , L_10 ) ;
return - V_58 ;
}
return F_18 ( V_2 , V_53 ) ;
}
static int F_22 ( struct V_54 * V_47 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
return V_2 -> V_53 ;
}
static int F_23 ( struct V_59 * V_60 )
{
return V_60 -> V_61 . V_62 ;
}
static int F_24 ( struct V_59 * V_60 )
{
int V_15 = 0 , V_62 = V_60 -> V_61 . V_62 ;
struct V_1 * V_2 = F_25 ( V_60 ) ;
if ( V_62 < V_63 ||
V_62 > V_60 -> V_61 . V_64 ) {
F_9 ( & V_60 -> V_24 , L_11 ,
V_63 , V_65 ) ;
return - V_58 ;
}
V_15 = F_10 ( V_2 , V_60 -> V_61 . V_62 ) ;
if ( V_15 ) {
F_9 ( & V_60 -> V_24 , L_12 ) ;
return - V_51 ;
}
return V_15 ;
}
static int F_26 ( struct V_66 * V_12 )
{
int V_15 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_54 * V_47 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_67 V_61 ;
V_2 = F_27 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_12 -> V_70 = 9 ;
V_15 = F_28 ( V_12 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_12 -> V_24 , L_13 ) ;
goto V_71;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_24 = & V_12 -> V_24 ;
V_2 -> V_44 = V_12 -> V_24 . V_72 ;
if ( ! V_2 -> V_44 ) {
F_9 ( & V_12 -> V_24 , L_4 ) ;
goto V_71;
}
V_47 = F_29 ( L_14 , & V_12 -> V_24 , V_2 , & V_73 ) ;
if ( F_30 ( V_47 ) ) {
V_15 = F_31 ( V_47 ) ;
goto V_71;
}
V_2 -> V_47 = V_47 ;
memset ( & V_61 , 0 , sizeof( struct V_67 ) ) ;
V_61 . type = V_74 ;
V_61 . V_64 = V_65 ;
V_60 = F_32 ( L_15 , & V_12 -> V_24 ,
V_2 , & V_75 , & V_61 ) ;
if ( F_30 ( V_60 ) ) {
V_15 = F_31 ( V_60 ) ;
goto V_76;
}
V_60 -> V_61 . V_62 = V_65 ;
V_2 -> V_60 = V_60 ;
if ( ! V_2 -> V_44 -> V_77 ) {
V_2 -> V_53 = V_56 ;
F_18 ( V_2 , V_55 ) ;
} else
V_2 -> V_53 = V_55 ;
F_33 ( & V_12 -> V_24 , V_2 ) ;
F_34 ( & V_12 -> V_24 , L_16 ) ;
return 0 ;
V_76:
F_35 ( V_2 -> V_47 ) ;
V_71:
F_36 ( V_2 ) ;
return V_15 ;
}
static int T_2 F_37 ( struct V_66 * V_12 )
{
struct V_1 * V_2 = F_38 ( & V_12 -> V_24 ) ;
F_18 ( V_2 , V_56 ) ;
F_39 ( V_2 -> V_60 ) ;
F_35 ( V_2 -> V_47 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_66 * V_12 , T_3 V_78 )
{
int V_15 = 0 ;
struct V_1 * V_2 = F_38 ( & V_12 -> V_24 ) ;
F_41 ( & V_12 -> V_24 , L_17 , V_2 -> V_53 ) ;
V_15 = F_18 ( V_2 , V_56 ) ;
return V_15 ;
}
static int F_42 ( struct V_66 * V_12 )
{
int V_15 = 0 ;
struct V_1 * V_2 = F_38 ( & V_12 -> V_24 ) ;
V_2 -> V_53 = V_56 ;
V_15 = F_18 ( V_2 , V_55 ) ;
return V_15 ;
}
static void F_43 ( struct V_66 * V_12 )
{
struct V_1 * V_2 = F_38 ( & V_12 -> V_24 ) ;
F_18 ( V_2 , V_56 ) ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_79 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_79 ) ;
}
