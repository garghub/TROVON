static void F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
}
static void F_2 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
unsigned char * V_3 = V_5 -> V_7 ;
unsigned int V_4 = V_5 -> V_4 ;
int V_8 = V_5 -> V_8 ;
int V_9 ;
switch ( V_8 ) {
case 0 :
break;
case - V_10 :
case - V_11 :
case - V_12 :
F_3 ( & V_2 -> V_13 , L_1 ,
V_14 , V_8 ) ;
return;
default:
F_3 ( & V_2 -> V_13 , L_2 ,
V_14 , V_8 ) ;
goto exit;
}
F_4 ( V_15 , & V_2 -> V_13 , V_14 ,
V_5 -> V_4 , V_5 -> V_7 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
exit:
V_9 = F_5 ( V_5 , V_16 ) ;
if ( V_9 )
F_6 ( & V_5 -> V_13 -> V_13 ,
L_3 ,
V_14 , V_9 ) ;
}
static void F_7 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_19 * V_20 ;
unsigned char * V_3 = V_5 -> V_7 ;
char V_21 = V_22 ;
unsigned long V_23 ;
T_1 V_24 ;
int V_25 ;
F_9 ( & V_18 -> V_26 , V_23 ) ;
V_24 = V_18 -> V_24 ;
V_18 -> V_24 &= ~ V_27 ;
F_10 ( & V_18 -> V_26 , V_23 ) ;
F_11 ( & V_18 -> V_28 ) ;
if ( ! V_5 -> V_4 )
return;
V_20 = F_12 ( & V_2 -> V_2 ) ;
if ( ! V_20 )
return;
if ( V_24 & V_29 )
V_21 = V_30 ;
else if ( V_24 & V_31 )
V_21 = V_32 ;
else if ( V_24 & V_33 )
V_21 = V_34 ;
F_3 ( & V_2 -> V_13 , L_4 , V_14 , V_21 ) ;
if ( V_24 & V_35 )
F_13 ( V_20 , 0 , V_36 ) ;
if ( V_2 -> V_2 . V_37 && V_2 -> V_38 ) {
for ( V_25 = 0 ; V_25 < V_5 -> V_4 ; ++ V_25 )
if ( ! F_14 ( V_2 , V_3 [ V_25 ] ) )
F_13 ( V_20 , V_3 [ V_25 ] , V_21 ) ;
} else {
F_15 ( V_20 , V_3 , V_21 ,
V_5 -> V_4 ) ;
}
F_16 ( V_20 ) ;
F_17 ( V_20 ) ;
}
static int F_18 ( struct V_39 * V_13 , T_1 V_40 )
{
return 0 ;
}
static void F_19 ( struct V_19 * V_20 , int V_41 )
{
}
static void F_20 ( struct V_19 * V_20 ,
struct V_1 * V_2 , struct V_42 * V_43 )
{
if ( ! F_21 ( V_20 -> V_44 , V_43 ) )
return;
}
static int F_22 ( struct V_19 * V_20 )
{
return 0 ;
}
static int F_23 ( struct V_19 * V_20 ,
unsigned int V_45 , unsigned int V_46 )
{
return 0 ;
}
static int F_24 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_42 V_47 ;
int V_48 ;
if ( V_20 )
F_20 ( V_20 , V_2 , & V_47 ) ;
V_48 = F_5 ( V_2 -> V_49 , V_50 ) ;
if ( V_48 ) {
F_6 ( & V_2 -> V_13 , L_5
L_6 , V_14 , V_48 ) ;
return V_48 ;
}
V_48 = F_25 ( V_20 , V_2 ) ;
if ( V_48 ) {
F_26 ( V_2 -> V_49 ) ;
return V_48 ;
}
V_2 -> V_2 . V_51 = 256 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_26 ( V_2 -> V_49 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_52 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
unsigned long V_23 ;
T_1 V_53 ;
F_9 ( & V_18 -> V_26 , V_23 ) ;
if ( V_52 )
V_18 -> V_54 |= ( V_55 | V_56 ) ;
else
V_18 -> V_54 &= ~ ( V_55 | V_56 ) ;
V_53 = V_18 -> V_54 ;
F_10 ( & V_18 -> V_26 , V_23 ) ;
F_18 ( V_2 -> V_57 -> V_13 , V_53 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
if ( V_18 -> V_24 & V_58 )
return 1 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned int V_59 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
unsigned long V_23 ;
unsigned int V_60 ;
unsigned int V_8 ;
unsigned int V_61 ;
F_9 ( & V_18 -> V_26 , V_23 ) ;
V_60 = V_18 -> V_24 ;
F_10 ( & V_18 -> V_26 , V_23 ) ;
while ( 1 ) {
F_32 ( & V_18 -> V_28 ) ;
if ( F_33 ( V_62 ) )
return - V_63 ;
F_9 ( & V_18 -> V_26 , V_23 ) ;
V_8 = V_18 -> V_24 ;
F_10 ( & V_18 -> V_26 , V_23 ) ;
V_61 = V_60 ^ V_8 ;
if ( ( ( V_59 & V_64 ) && ( V_61 & V_65 ) ) ||
( ( V_59 & V_66 ) && ( V_61 & V_67 ) ) ||
( ( V_59 & V_68 ) && ( V_61 & V_58 ) ) ||
( ( V_59 & V_69 ) && ( V_61 & V_70 ) ) ) {
return 0 ;
}
V_60 = V_8 ;
}
return 0 ;
}
static int F_34 ( struct V_19 * V_20 ,
unsigned int V_71 , unsigned long V_59 )
{
struct V_72 V_73 ;
struct V_1 * V_2 = V_20 -> V_74 ;
F_3 ( & V_2 -> V_13 , L_7 , V_14 ,
V_2 -> V_75 , V_71 ) ;
switch ( V_71 ) {
case V_76 :
memset ( & V_73 , 0 , sizeof V_73 ) ;
V_73 . type = V_77 ;
V_73 . line = V_2 -> V_57 -> V_78 ;
V_73 . V_2 = V_2 -> V_75 ;
V_73 . V_79 = 460800 ;
if ( F_35 ( ( void V_80 * ) V_59 , & V_73 , sizeof V_73 ) )
return - V_81 ;
return 0 ;
case V_82 :
F_3 ( & V_2 -> V_13 , L_8 , V_14 ,
V_2 -> V_75 ) ;
return F_31 ( V_2 , V_59 ) ;
default:
F_3 ( & V_2 -> V_13 , L_9 ,
V_14 , V_71 ) ;
break;
}
return - V_83 ;
}
static int F_36 ( struct V_84 * V_57 )
{
struct V_17 * V_18 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_57 -> V_85 ; ++ V_25 ) {
V_18 = F_37 ( sizeof( struct V_17 ) , V_50 ) ;
if ( ! V_18 )
goto V_86;
F_38 ( & V_18 -> V_26 ) ;
F_39 ( & V_18 -> V_28 ) ;
F_40 ( V_57 -> V_2 [ V_25 ] , V_18 ) ;
}
return 0 ;
V_86:
for ( -- V_25 ; V_25 >= 0 ; -- V_25 ) {
V_18 = F_8 ( V_57 -> V_2 [ V_25 ] ) ;
F_41 ( V_18 ) ;
F_40 ( V_57 -> V_2 [ V_25 ] , NULL ) ;
}
return - V_87 ;
}
static void F_42 ( struct V_84 * V_57 )
{
int V_25 ;
struct V_17 * V_18 ;
for ( V_25 = 0 ; V_25 < V_57 -> V_85 ; ++ V_25 ) {
V_18 = F_8 ( V_57 -> V_2 [ V_25 ] ) ;
F_41 ( V_18 ) ;
}
}
