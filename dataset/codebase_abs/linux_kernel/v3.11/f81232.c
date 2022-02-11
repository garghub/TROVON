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
unsigned char * V_3 = V_5 -> V_7 ;
char V_18 = V_19 ;
unsigned long V_20 ;
T_1 V_21 ;
int V_22 ;
F_9 ( & V_17 -> V_23 , V_20 ) ;
V_21 = V_17 -> V_21 ;
V_17 -> V_21 &= ~ V_24 ;
F_10 ( & V_17 -> V_23 , V_20 ) ;
F_11 ( & V_2 -> V_2 . V_25 ) ;
if ( ! V_5 -> V_4 )
return;
if ( V_21 & V_26 )
V_18 = V_27 ;
else if ( V_21 & V_28 )
V_18 = V_29 ;
else if ( V_21 & V_30 )
V_18 = V_31 ;
F_3 ( & V_2 -> V_13 , L_4 , V_14 , V_18 ) ;
if ( V_21 & V_32 )
F_12 ( & V_2 -> V_2 , 0 , V_33 ) ;
if ( V_2 -> V_2 . V_34 && V_2 -> V_35 ) {
for ( V_22 = 0 ; V_22 < V_5 -> V_4 ; ++ V_22 )
if ( ! F_13 ( V_2 , V_3 [ V_22 ] ) )
F_12 ( & V_2 -> V_2 , V_3 [ V_22 ] ,
V_18 ) ;
} else {
F_14 ( & V_2 -> V_2 , V_3 , V_18 ,
V_5 -> V_4 ) ;
}
F_15 ( & V_2 -> V_2 ) ;
}
static int F_16 ( struct V_36 * V_13 , T_1 V_37 )
{
return 0 ;
}
static void F_17 ( struct V_38 * V_39 , int V_40 )
{
}
static void F_18 ( struct V_38 * V_39 ,
struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( V_42 && ! F_19 ( & V_39 -> V_43 , V_42 ) )
return;
if ( V_42 )
F_20 ( & V_39 -> V_43 , V_42 ) ;
}
static int F_21 ( struct V_38 * V_39 )
{
return 0 ;
}
static int F_22 ( struct V_38 * V_39 ,
unsigned int V_44 , unsigned int V_45 )
{
return 0 ;
}
static int F_23 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
int V_46 ;
if ( V_39 )
F_18 ( V_39 , V_2 , NULL ) ;
V_46 = F_5 ( V_2 -> V_47 , V_48 ) ;
if ( V_46 ) {
F_6 ( & V_2 -> V_13 , L_5
L_6 , V_14 , V_46 ) ;
return V_46 ;
}
V_46 = F_24 ( V_39 , V_2 ) ;
if ( V_46 ) {
F_25 ( V_2 -> V_47 ) ;
return V_46 ;
}
V_2 -> V_2 . V_49 = 256 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_25 ( V_2 -> V_47 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_50 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
unsigned long V_20 ;
T_1 V_51 ;
F_9 ( & V_17 -> V_23 , V_20 ) ;
if ( V_50 )
V_17 -> V_52 |= ( V_53 | V_54 ) ;
else
V_17 -> V_52 &= ~ ( V_53 | V_54 ) ;
V_51 = V_17 -> V_52 ;
F_10 ( & V_17 -> V_23 , V_20 ) ;
F_16 ( V_2 -> V_55 -> V_13 , V_51 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
if ( V_17 -> V_21 & V_56 )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_38 * V_39 , unsigned long V_57 )
{
struct V_1 * V_2 = V_39 -> V_58 ;
struct V_16 * V_17 = F_8 ( V_2 ) ;
unsigned long V_20 ;
unsigned int V_59 ;
unsigned int V_8 ;
unsigned int V_60 ;
F_9 ( & V_17 -> V_23 , V_20 ) ;
V_59 = V_17 -> V_21 ;
F_10 ( & V_17 -> V_23 , V_20 ) ;
while ( 1 ) {
F_31 ( & V_2 -> V_2 . V_25 ) ;
if ( F_32 ( V_61 ) )
return - V_62 ;
if ( V_2 -> V_55 -> V_63 )
return - V_64 ;
F_9 ( & V_17 -> V_23 , V_20 ) ;
V_8 = V_17 -> V_21 ;
F_10 ( & V_17 -> V_23 , V_20 ) ;
V_60 = V_59 ^ V_8 ;
if ( ( ( V_57 & V_65 ) && ( V_60 & V_66 ) ) ||
( ( V_57 & V_67 ) && ( V_60 & V_68 ) ) ||
( ( V_57 & V_69 ) && ( V_60 & V_56 ) ) ||
( ( V_57 & V_70 ) && ( V_60 & V_71 ) ) ) {
return 0 ;
}
V_59 = V_8 ;
}
return 0 ;
}
static int F_33 ( struct V_38 * V_39 ,
unsigned int V_72 , unsigned long V_57 )
{
struct V_73 V_74 ;
struct V_1 * V_2 = V_39 -> V_58 ;
F_3 ( & V_2 -> V_13 , L_7 , V_14 , V_72 ) ;
switch ( V_72 ) {
case V_75 :
memset ( & V_74 , 0 , sizeof V_74 ) ;
V_74 . type = V_76 ;
V_74 . line = V_2 -> V_77 ;
V_74 . V_2 = V_2 -> V_78 ;
V_74 . V_79 = 460800 ;
if ( F_34 ( ( void V_80 * ) V_57 , & V_74 , sizeof V_74 ) )
return - V_81 ;
return 0 ;
default:
F_3 ( & V_2 -> V_13 , L_8 ,
V_14 , V_72 ) ;
break;
}
return - V_82 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_36 ( sizeof( * V_17 ) , V_48 ) ;
if ( ! V_17 )
return - V_83 ;
F_37 ( & V_17 -> V_23 ) ;
F_38 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_8 ( V_2 ) ;
F_40 ( V_17 ) ;
return 0 ;
}
