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
if ( ! V_5 -> V_4 )
return;
if ( V_21 & V_25 )
V_18 = V_26 ;
else if ( V_21 & V_27 )
V_18 = V_28 ;
else if ( V_21 & V_29 )
V_18 = V_30 ;
F_3 ( & V_2 -> V_13 , L_4 , V_14 , V_18 ) ;
if ( V_21 & V_31 )
F_11 ( & V_2 -> V_2 , 0 , V_32 ) ;
if ( V_2 -> V_2 . V_33 && V_2 -> V_34 ) {
for ( V_22 = 0 ; V_22 < V_5 -> V_4 ; ++ V_22 )
if ( ! F_12 ( V_2 , V_3 [ V_22 ] ) )
F_11 ( & V_2 -> V_2 , V_3 [ V_22 ] ,
V_18 ) ;
} else {
F_13 ( & V_2 -> V_2 , V_3 , V_18 ,
V_5 -> V_4 ) ;
}
F_14 ( & V_2 -> V_2 ) ;
}
static int F_15 ( struct V_35 * V_13 , T_1 V_36 )
{
return 0 ;
}
static void F_16 ( struct V_37 * V_38 , int V_39 )
{
}
static void F_17 ( struct V_37 * V_38 ,
struct V_1 * V_2 , struct V_40 * V_41 )
{
if ( V_41 && ! F_18 ( & V_38 -> V_42 , V_41 ) )
return;
if ( V_41 )
F_19 ( & V_38 -> V_42 , V_41 ) ;
}
static int F_20 ( struct V_37 * V_38 )
{
return 0 ;
}
static int F_21 ( struct V_37 * V_38 ,
unsigned int V_43 , unsigned int V_44 )
{
return 0 ;
}
static int F_22 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
int V_45 ;
if ( V_38 )
F_17 ( V_38 , V_2 , NULL ) ;
V_45 = F_5 ( V_2 -> V_46 , V_47 ) ;
if ( V_45 ) {
F_6 ( & V_2 -> V_13 , L_5
L_6 , V_14 , V_45 ) ;
return V_45 ;
}
V_45 = F_23 ( V_38 , V_2 ) ;
if ( V_45 ) {
F_24 ( V_2 -> V_46 ) ;
return V_45 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_24 ( V_2 -> V_46 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_48 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
unsigned long V_20 ;
T_1 V_49 ;
F_9 ( & V_17 -> V_23 , V_20 ) ;
if ( V_48 )
V_17 -> V_50 |= ( V_51 | V_52 ) ;
else
V_17 -> V_50 &= ~ ( V_51 | V_52 ) ;
V_49 = V_17 -> V_50 ;
F_10 ( & V_17 -> V_23 , V_20 ) ;
F_15 ( V_2 -> V_53 -> V_13 , V_49 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
if ( V_17 -> V_21 & V_54 )
return 1 ;
return 0 ;
}
static int F_29 ( struct V_37 * V_38 ,
unsigned int V_55 , unsigned long V_56 )
{
struct V_57 V_58 ;
struct V_1 * V_2 = V_38 -> V_59 ;
switch ( V_55 ) {
case V_60 :
memset ( & V_58 , 0 , sizeof V_58 ) ;
V_58 . type = V_61 ;
V_58 . line = V_2 -> V_62 ;
V_58 . V_2 = V_2 -> V_63 ;
V_58 . V_64 = 460800 ;
if ( F_30 ( ( void V_65 * ) V_56 , & V_58 , sizeof V_58 ) )
return - V_66 ;
return 0 ;
default:
break;
}
return - V_67 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_32 ( sizeof( * V_17 ) , V_47 ) ;
if ( ! V_17 )
return - V_68 ;
F_33 ( & V_17 -> V_23 ) ;
F_34 ( V_2 , V_17 ) ;
V_2 -> V_2 . V_69 = 256 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = F_8 ( V_2 ) ;
F_36 ( V_17 ) ;
return 0 ;
}
