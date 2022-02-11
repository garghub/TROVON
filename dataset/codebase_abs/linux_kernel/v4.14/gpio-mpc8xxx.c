static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
V_7 = V_2 -> V_9 ( V_6 -> V_10 + V_11 ) ;
V_4 = V_2 -> V_9 ( V_6 -> V_10 + V_12 ) & ~ V_7 ;
V_8 = V_2 -> V_13 & V_7 ;
return ! ! ( ( V_4 | V_8 ) & V_2 -> V_14 ( V_2 , V_3 ) ) ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_3 >= 28 )
return - V_15 ;
return V_6 -> V_16 ( V_2 , V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_3 <= 3 )
return - V_15 ;
return V_6 -> V_16 ( V_2 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_18 && V_17 < V_19 )
return F_6 ( V_6 -> V_18 , V_17 ) ;
else
return - V_20 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_22 ) ;
struct V_23 * V_24 = F_9 ( V_22 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_25 ;
V_25 = V_2 -> V_9 ( V_6 -> V_10 + V_26 )
& V_2 -> V_9 ( V_6 -> V_10 + V_27 ) ;
if ( V_25 )
F_10 ( F_11 ( V_6 -> V_18 ,
32 - F_12 ( V_25 ) ) ) ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( & V_22 -> V_29 ) ;
}
static void F_13 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_31 ;
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_6 -> V_10 + V_27 ,
V_2 -> V_9 ( V_6 -> V_10 + V_27 )
| V_2 -> V_14 ( V_2 , F_16 ( V_30 ) ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_31 ;
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_6 -> V_10 + V_27 ,
V_2 -> V_9 ( V_6 -> V_10 + V_27 )
& ~ ( V_2 -> V_14 ( V_2 , F_16 ( V_30 ) ) ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
}
static void F_19 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_33 ( V_6 -> V_10 + V_26 ,
V_2 -> V_14 ( V_2 , F_16 ( V_30 ) ) ) ;
}
static int F_20 ( struct V_29 * V_30 , unsigned int V_34 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_31 ;
switch ( V_34 ) {
case V_35 :
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_6 -> V_10 + V_36 ,
V_2 -> V_9 ( V_6 -> V_10 + V_36 )
| V_2 -> V_14 ( V_2 , F_16 ( V_30 ) ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
break;
case V_37 :
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_6 -> V_10 + V_36 ,
V_2 -> V_9 ( V_6 -> V_10 + V_36 )
& ~ ( V_2 -> V_14 ( V_2 , F_16 ( V_30 ) ) ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_21 ( struct V_29 * V_30 , unsigned int V_34 )
{
struct V_5 * V_6 = F_14 ( V_30 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_3 = F_16 ( V_30 ) ;
void T_2 * V_38 ;
unsigned int V_39 ;
unsigned long V_31 ;
if ( V_3 < 16 ) {
V_38 = V_6 -> V_10 + V_36 ;
V_39 = ( 15 - V_3 ) * 2 ;
} else {
V_38 = V_6 -> V_10 + V_40 ;
V_39 = ( 15 - ( V_3 % 16 ) ) * 2 ;
}
switch ( V_34 ) {
case V_35 :
case V_41 :
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_38 , ( V_2 -> V_9 ( V_38 ) & ~ ( 3 << V_39 ) )
| ( 2 << V_39 ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
break;
case V_42 :
case V_43 :
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_38 , ( V_2 -> V_9 ( V_38 ) & ~ ( 3 << V_39 ) )
| ( 1 << V_39 ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
break;
case V_37 :
F_15 ( & V_6 -> V_32 , V_31 ) ;
V_2 -> V_33 ( V_38 , ( V_2 -> V_9 ( V_38 ) & ~ ( 3 << V_39 ) ) ) ;
F_17 ( & V_6 -> V_32 , V_31 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_22 ( struct V_44 * V_45 , unsigned int V_18 ,
T_3 V_46 )
{
F_23 ( V_18 , V_45 -> V_47 ) ;
F_24 ( V_18 , & V_48 , V_49 ) ;
return 0 ;
}
static int F_25 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
const struct V_56 * V_57 =
F_26 ( & V_51 -> V_54 ) ;
int V_58 ;
V_6 = F_27 ( & V_51 -> V_54 , sizeof( * V_6 ) , V_59 ) ;
if ( ! V_6 )
return - V_60 ;
F_28 ( V_51 , V_6 ) ;
F_29 ( & V_6 -> V_32 ) ;
V_6 -> V_10 = F_30 ( V_53 , 0 ) ;
if ( ! V_6 -> V_10 )
return - V_60 ;
V_2 = & V_6 -> V_2 ;
if ( F_31 ( V_53 , L_1 ) ) {
V_58 = F_32 ( V_2 , & V_51 -> V_54 , 4 ,
V_6 -> V_10 + V_12 ,
NULL , NULL ,
V_6 -> V_10 + V_11 , NULL ,
V_61 ) ;
if ( V_58 )
goto V_62;
F_33 ( & V_51 -> V_54 , L_2 ) ;
} else {
V_58 = F_32 ( V_2 , & V_51 -> V_54 , 4 ,
V_6 -> V_10 + V_12 ,
NULL , NULL ,
V_6 -> V_10 + V_11 , NULL ,
V_61
| V_63 ) ;
if ( V_58 )
goto V_62;
F_33 ( & V_51 -> V_54 , L_3 ) ;
}
V_6 -> V_16 = V_2 -> V_16 ;
if ( ! V_57 )
V_57 = & V_64 ;
V_48 . V_65 = V_57 -> V_65 ;
if ( V_57 -> V_66 )
V_2 -> V_16 = V_57 -> V_66 ;
if ( V_57 -> V_67 )
V_2 -> V_68 = V_57 -> V_67 ;
V_2 -> V_69 = F_5 ;
V_58 = F_34 ( V_2 , V_6 ) ;
if ( V_58 ) {
F_35 ( L_4 ,
V_53 , V_58 ) ;
goto V_62;
}
V_6 -> V_70 = F_36 ( V_53 , 0 ) ;
if ( ! V_6 -> V_70 )
return 0 ;
V_6 -> V_18 = F_37 ( V_53 , V_19 ,
& V_71 , V_6 ) ;
if ( ! V_6 -> V_18 )
return 0 ;
V_2 -> V_33 ( V_6 -> V_10 + V_26 , 0xffffffff ) ;
V_2 -> V_33 ( V_6 -> V_10 + V_27 , 0 ) ;
F_38 ( V_6 -> V_70 ,
F_7 , V_6 ) ;
return 0 ;
V_62:
F_39 ( V_6 -> V_10 ) ;
return V_58 ;
}
static int F_40 ( struct V_50 * V_51 )
{
struct V_5 * V_6 = F_41 ( V_51 ) ;
if ( V_6 -> V_18 ) {
F_38 ( V_6 -> V_70 , NULL , NULL ) ;
F_42 ( V_6 -> V_18 ) ;
}
F_43 ( & V_6 -> V_2 ) ;
F_39 ( V_6 -> V_10 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_72 ) ;
}
