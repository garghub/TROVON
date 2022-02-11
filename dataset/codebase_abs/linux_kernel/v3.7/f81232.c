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
F_4 ( & V_2 -> V_13 , V_14 ,
V_5 -> V_4 , V_5 -> V_7 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
exit:
V_9 = F_5 ( V_5 , V_15 ) ;
if ( V_9 )
F_6 ( & V_5 -> V_13 -> V_13 ,
L_3 ,
V_14 , V_9 ) ;
}
static void F_7 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_6 ;
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_18 * V_19 ;
unsigned char * V_3 = V_5 -> V_7 ;
char V_20 = V_21 ;
unsigned long V_22 ;
T_1 V_23 ;
int V_24 ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
V_23 = V_17 -> V_23 ;
V_17 -> V_23 &= ~ V_26 ;
F_10 ( & V_17 -> V_25 , V_22 ) ;
F_11 ( & V_17 -> V_27 ) ;
if ( ! V_5 -> V_4 )
return;
V_19 = F_12 ( & V_2 -> V_2 ) ;
if ( ! V_19 )
return;
if ( V_23 & V_28 )
V_20 = V_29 ;
else if ( V_23 & V_30 )
V_20 = V_31 ;
else if ( V_23 & V_32 )
V_20 = V_33 ;
F_3 ( & V_2 -> V_13 , L_4 , V_14 , V_20 ) ;
if ( V_23 & V_34 )
F_13 ( V_19 , 0 , V_35 ) ;
if ( V_2 -> V_2 . V_36 && V_2 -> V_37 ) {
for ( V_24 = 0 ; V_24 < V_5 -> V_4 ; ++ V_24 )
if ( ! F_14 ( V_2 , V_3 [ V_24 ] ) )
F_13 ( V_19 , V_3 [ V_24 ] , V_20 ) ;
} else {
F_15 ( V_19 , V_3 , V_20 ,
V_5 -> V_4 ) ;
}
F_16 ( V_19 ) ;
F_17 ( V_19 ) ;
}
static int F_18 ( struct V_38 * V_13 , T_1 V_39 )
{
return 0 ;
}
static void F_19 ( struct V_18 * V_19 , int V_40 )
{
}
static void F_20 ( struct V_18 * V_19 ,
struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( ! F_21 ( & V_19 -> V_43 , V_42 ) )
return;
F_22 ( & V_19 -> V_43 , V_42 ) ;
}
static int F_23 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_24 ( struct V_18 * V_19 ,
unsigned int V_44 , unsigned int V_45 )
{
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
struct V_41 V_46 ;
int V_47 ;
if ( V_19 )
F_20 ( V_19 , V_2 , & V_46 ) ;
V_47 = F_5 ( V_2 -> V_48 , V_49 ) ;
if ( V_47 ) {
F_6 ( & V_2 -> V_13 , L_5
L_6 , V_14 , V_47 ) ;
return V_47 ;
}
V_47 = F_26 ( V_19 , V_2 ) ;
if ( V_47 ) {
F_27 ( V_2 -> V_48 ) ;
return V_47 ;
}
V_2 -> V_2 . V_50 = 256 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_27 ( V_2 -> V_48 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_51 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
unsigned long V_22 ;
T_1 V_52 ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
if ( V_51 )
V_17 -> V_53 |= ( V_54 | V_55 ) ;
else
V_17 -> V_53 &= ~ ( V_54 | V_55 ) ;
V_52 = V_17 -> V_53 ;
F_10 ( & V_17 -> V_25 , V_22 ) ;
F_18 ( V_2 -> V_56 -> V_13 , V_52 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
if ( V_17 -> V_23 & V_57 )
return 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_58 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
unsigned long V_22 ;
unsigned int V_59 ;
unsigned int V_8 ;
unsigned int V_60 ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
V_59 = V_17 -> V_23 ;
F_10 ( & V_17 -> V_25 , V_22 ) ;
while ( 1 ) {
F_33 ( & V_17 -> V_27 ) ;
if ( F_34 ( V_61 ) )
return - V_62 ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
V_8 = V_17 -> V_23 ;
F_10 ( & V_17 -> V_25 , V_22 ) ;
V_60 = V_59 ^ V_8 ;
if ( ( ( V_58 & V_63 ) && ( V_60 & V_64 ) ) ||
( ( V_58 & V_65 ) && ( V_60 & V_66 ) ) ||
( ( V_58 & V_67 ) && ( V_60 & V_57 ) ) ||
( ( V_58 & V_68 ) && ( V_60 & V_69 ) ) ) {
return 0 ;
}
V_59 = V_8 ;
}
return 0 ;
}
static int F_35 ( struct V_18 * V_19 ,
unsigned int V_70 , unsigned long V_58 )
{
struct V_71 V_72 ;
struct V_1 * V_2 = V_19 -> V_73 ;
F_3 ( & V_2 -> V_13 , L_7 , V_14 ,
V_2 -> V_74 , V_70 ) ;
switch ( V_70 ) {
case V_75 :
memset ( & V_72 , 0 , sizeof V_72 ) ;
V_72 . type = V_76 ;
V_72 . line = V_2 -> V_56 -> V_77 ;
V_72 . V_2 = V_2 -> V_74 ;
V_72 . V_78 = 460800 ;
if ( F_36 ( ( void V_79 * ) V_58 , & V_72 , sizeof V_72 ) )
return - V_80 ;
return 0 ;
case V_81 :
F_3 ( & V_2 -> V_13 , L_8 , V_14 ,
V_2 -> V_74 ) ;
return F_32 ( V_2 , V_58 ) ;
default:
F_3 ( & V_2 -> V_13 , L_9 ,
V_14 , V_70 ) ;
break;
}
return - V_82 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_38 ( sizeof( * V_17 ) , V_49 ) ;
if ( ! V_17 )
return - V_83 ;
F_39 ( & V_17 -> V_25 ) ;
F_40 ( & V_17 -> V_27 ) ;
F_41 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_8 ( V_2 ) ;
F_43 ( V_17 ) ;
return 0 ;
}
