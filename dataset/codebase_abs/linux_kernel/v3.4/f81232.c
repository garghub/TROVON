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
F_3 ( L_1 , V_10 , V_2 -> V_11 ) ;
switch ( V_8 ) {
case 0 :
break;
case - V_12 :
case - V_13 :
case - V_14 :
F_3 ( L_2 , V_10 ,
V_8 ) ;
return;
default:
F_3 ( L_3 , V_10 ,
V_8 ) ;
goto exit;
}
F_4 ( V_15 , & V_2 -> V_16 , V_10 ,
V_5 -> V_4 , V_5 -> V_7 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
exit:
V_9 = F_5 ( V_5 , V_17 ) ;
if ( V_9 )
F_6 ( & V_5 -> V_16 -> V_16 ,
L_4 ,
V_10 , V_9 ) ;
}
static void F_7 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
struct V_18 * V_19 = F_8 ( V_2 ) ;
struct V_20 * V_21 ;
unsigned char * V_3 = V_5 -> V_7 ;
char V_22 = V_23 ;
unsigned long V_24 ;
T_1 V_25 ;
int V_26 ;
F_9 ( & V_19 -> V_27 , V_24 ) ;
V_25 = V_19 -> V_25 ;
V_19 -> V_25 &= ~ V_28 ;
F_10 ( & V_19 -> V_27 , V_24 ) ;
F_11 ( & V_19 -> V_29 ) ;
if ( ! V_5 -> V_4 )
return;
V_21 = F_12 ( & V_2 -> V_2 ) ;
if ( ! V_21 )
return;
if ( V_25 & V_30 )
V_22 = V_31 ;
else if ( V_25 & V_32 )
V_22 = V_33 ;
else if ( V_25 & V_34 )
V_22 = V_35 ;
F_3 ( L_5 , V_10 , V_22 ) ;
if ( V_25 & V_36 )
F_13 ( V_21 , 0 , V_37 ) ;
if ( V_2 -> V_2 . V_38 && V_2 -> V_39 ) {
for ( V_26 = 0 ; V_26 < V_5 -> V_4 ; ++ V_26 )
if ( ! F_14 ( V_2 , V_3 [ V_26 ] ) )
F_13 ( V_21 , V_3 [ V_26 ] , V_22 ) ;
} else {
F_15 ( V_21 , V_3 , V_22 ,
V_5 -> V_4 ) ;
}
F_16 ( V_21 ) ;
F_17 ( V_21 ) ;
}
static int F_18 ( struct V_40 * V_16 , T_1 V_41 )
{
return 0 ;
}
static void F_19 ( struct V_20 * V_21 , int V_42 )
{
}
static void F_20 ( struct V_20 * V_21 ,
struct V_1 * V_2 , struct V_43 * V_44 )
{
if ( ! F_21 ( V_21 -> V_45 , V_44 ) )
return;
}
static int F_22 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_23 ( struct V_20 * V_21 ,
unsigned int V_46 , unsigned int V_47 )
{
return 0 ;
}
static int F_24 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_43 V_48 ;
int V_49 ;
if ( V_21 )
F_20 ( V_21 , V_2 , & V_48 ) ;
F_3 ( L_6 , V_10 ) ;
V_49 = F_5 ( V_2 -> V_50 , V_51 ) ;
if ( V_49 ) {
F_6 ( & V_2 -> V_16 , L_7
L_8 , V_10 , V_49 ) ;
return V_49 ;
}
V_49 = F_25 ( V_21 , V_2 ) ;
if ( V_49 ) {
F_26 ( V_2 -> V_50 ) ;
return V_49 ;
}
V_2 -> V_2 . V_52 = 256 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_26 ( V_2 -> V_50 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_53 )
{
struct V_18 * V_19 = F_8 ( V_2 ) ;
unsigned long V_24 ;
T_1 V_54 ;
F_9 ( & V_19 -> V_27 , V_24 ) ;
if ( V_53 )
V_19 -> V_55 |= ( V_56 | V_57 ) ;
else
V_19 -> V_55 &= ~ ( V_56 | V_57 ) ;
V_54 = V_19 -> V_55 ;
F_10 ( & V_19 -> V_27 , V_24 ) ;
F_18 ( V_2 -> V_58 -> V_16 , V_54 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_8 ( V_2 ) ;
if ( V_19 -> V_25 & V_59 )
return 1 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned int V_60 )
{
struct V_18 * V_19 = F_8 ( V_2 ) ;
unsigned long V_24 ;
unsigned int V_61 ;
unsigned int V_8 ;
unsigned int V_62 ;
F_9 ( & V_19 -> V_27 , V_24 ) ;
V_61 = V_19 -> V_25 ;
F_10 ( & V_19 -> V_27 , V_24 ) ;
while ( 1 ) {
F_32 ( & V_19 -> V_29 ) ;
if ( F_33 ( V_63 ) )
return - V_64 ;
F_9 ( & V_19 -> V_27 , V_24 ) ;
V_8 = V_19 -> V_25 ;
F_10 ( & V_19 -> V_27 , V_24 ) ;
V_62 = V_61 ^ V_8 ;
if ( ( ( V_60 & V_65 ) && ( V_62 & V_66 ) ) ||
( ( V_60 & V_67 ) && ( V_62 & V_68 ) ) ||
( ( V_60 & V_69 ) && ( V_62 & V_59 ) ) ||
( ( V_60 & V_70 ) && ( V_62 & V_71 ) ) ) {
return 0 ;
}
V_61 = V_8 ;
}
return 0 ;
}
static int F_34 ( struct V_20 * V_21 ,
unsigned int V_72 , unsigned long V_60 )
{
struct V_73 V_74 ;
struct V_1 * V_2 = V_21 -> V_75 ;
F_3 ( L_9 , V_10 , V_2 -> V_11 , V_72 ) ;
switch ( V_72 ) {
case V_76 :
memset ( & V_74 , 0 , sizeof V_74 ) ;
V_74 . type = V_77 ;
V_74 . line = V_2 -> V_58 -> V_78 ;
V_74 . V_2 = V_2 -> V_11 ;
V_74 . V_79 = 460800 ;
if ( F_35 ( ( void V_80 * ) V_60 , & V_74 , sizeof V_74 ) )
return - V_81 ;
return 0 ;
case V_82 :
F_3 ( L_10 , V_10 , V_2 -> V_11 ) ;
return F_31 ( V_2 , V_60 ) ;
default:
F_3 ( L_11 , V_10 , V_72 ) ;
break;
}
return - V_83 ;
}
static int F_36 ( struct V_84 * V_58 )
{
struct V_18 * V_19 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_58 -> V_85 ; ++ V_26 ) {
V_19 = F_37 ( sizeof( struct V_18 ) , V_51 ) ;
if ( ! V_19 )
goto V_86;
F_38 ( & V_19 -> V_27 ) ;
F_39 ( & V_19 -> V_29 ) ;
F_40 ( V_58 -> V_2 [ V_26 ] , V_19 ) ;
}
return 0 ;
V_86:
for ( -- V_26 ; V_26 >= 0 ; -- V_26 ) {
V_19 = F_8 ( V_58 -> V_2 [ V_26 ] ) ;
F_41 ( V_19 ) ;
F_40 ( V_58 -> V_2 [ V_26 ] , NULL ) ;
}
return - V_87 ;
}
static void F_42 ( struct V_84 * V_58 )
{
int V_26 ;
struct V_18 * V_19 ;
for ( V_26 = 0 ; V_26 < V_58 -> V_85 ; ++ V_26 ) {
V_19 = F_8 ( V_58 -> V_2 [ V_26 ] ) ;
F_41 ( V_19 ) ;
}
}
