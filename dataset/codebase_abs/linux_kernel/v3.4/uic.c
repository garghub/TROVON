static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = F_3 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 , V_7 ;
V_7 = 1 << ( 31 - V_4 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
if ( F_5 ( V_2 ) )
F_6 ( V_3 -> V_9 + V_10 , V_7 ) ;
V_6 = F_7 ( V_3 -> V_9 + V_11 ) ;
V_6 |= V_7 ;
F_6 ( V_3 -> V_9 + V_11 , V_6 ) ;
F_8 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = F_3 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_6 = F_7 ( V_3 -> V_9 + V_11 ) ;
V_6 &= ~ ( 1 << ( 31 - V_4 ) ) ;
F_6 ( V_3 -> V_9 + V_11 , V_6 ) ;
F_8 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = F_3 ( V_2 ) ;
unsigned long V_5 ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_6 ( V_3 -> V_9 + V_10 , 1 << ( 31 - V_4 ) ) ;
F_8 ( & V_3 -> V_8 , V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = F_3 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_6 , V_7 ;
V_7 = 1 << ( 31 - V_4 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_6 = F_7 ( V_3 -> V_9 + V_11 ) ;
V_6 &= ~ V_7 ;
F_6 ( V_3 -> V_9 + V_11 , V_6 ) ;
if ( ! F_5 ( V_2 ) )
F_6 ( V_3 -> V_9 + V_10 , V_7 ) ;
F_8 ( & V_3 -> V_8 , V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_4 = F_3 ( V_2 ) ;
unsigned long V_5 ;
int V_13 , V_14 ;
T_1 V_15 , V_16 , V_17 ;
switch ( V_12 & V_18 ) {
case V_19 :
F_9 ( V_2 ) ;
return 0 ;
case V_20 :
V_13 = 1 ; V_14 = 1 ;
break;
case V_21 :
V_13 = 1 ; V_14 = 0 ;
break;
case V_22 :
V_13 = 0 ; V_14 = 1 ;
break;
case V_23 :
V_13 = 0 ; V_14 = 0 ;
break;
default:
return - V_24 ;
}
V_17 = ~ ( 1 << ( 31 - V_4 ) ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
V_15 = F_7 ( V_3 -> V_9 + V_25 ) ;
V_16 = F_7 ( V_3 -> V_9 + V_26 ) ;
V_15 = ( V_15 & V_17 ) | ( V_13 << ( 31 - V_4 ) ) ;
V_16 = ( V_16 & V_17 ) | ( V_14 << ( 31 - V_4 ) ) ;
F_6 ( V_3 -> V_9 + V_26 , V_16 ) ;
F_6 ( V_3 -> V_9 + V_25 , V_15 ) ;
F_8 ( & V_3 -> V_8 , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_27 * V_28 , unsigned int V_29 ,
T_2 V_30 )
{
struct V_3 * V_3 = V_28 -> V_31 ;
F_14 ( V_29 , V_3 ) ;
F_15 ( V_29 , & V_32 , V_33 ) ;
F_16 ( V_29 , V_19 ) ;
return 0 ;
}
void F_17 ( unsigned int V_29 , struct V_34 * V_35 )
{
struct V_36 * V_37 = F_18 ( V_35 ) ;
struct V_1 * V_38 = F_19 ( V_35 ) ;
struct V_3 * V_3 = F_20 ( V_29 ) ;
T_1 V_39 ;
int V_4 ;
int V_40 ;
F_21 ( & V_35 -> V_8 ) ;
if ( F_5 ( V_38 ) )
V_37 -> V_41 ( V_38 ) ;
else
V_37 -> V_42 ( V_38 ) ;
F_22 ( & V_35 -> V_8 ) ;
V_39 = F_7 ( V_3 -> V_9 + V_43 ) ;
if ( ! V_39 )
goto V_44;
V_4 = 32 - F_23 ( V_39 ) ;
V_40 = F_24 ( V_3 -> V_45 , V_4 ) ;
F_25 ( V_40 ) ;
V_44:
F_21 ( & V_35 -> V_8 ) ;
if ( F_5 ( V_38 ) )
V_37 -> V_46 ( V_38 ) ;
if ( ! F_26 ( V_38 ) && V_37 -> V_47 )
V_37 -> V_47 ( V_38 ) ;
F_22 ( & V_35 -> V_8 ) ;
}
static struct V_3 * T_3 F_27 ( struct V_48 * V_49 )
{
struct V_3 * V_3 ;
const T_1 * V_50 , * V_51 ;
int V_52 ;
F_28 ( ! F_29 ( V_49 , L_1 ) ) ;
V_3 = F_30 ( sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return NULL ;
F_31 ( & V_3 -> V_8 ) ;
V_50 = F_32 ( V_49 , L_2 , & V_52 ) ;
if ( ! V_50 || ( V_52 != sizeof( T_1 ) ) ) {
F_33 ( V_54 L_3
L_4 , V_49 -> V_55 ) ;
return NULL ;
}
V_3 -> V_56 = * V_50 ;
V_51 = F_32 ( V_49 , L_5 , & V_52 ) ;
if ( ! V_51 || ( V_52 != 2 * sizeof( T_1 ) ) ) {
F_33 ( V_54 L_3
L_6 , V_49 -> V_55 ) ;
return NULL ;
}
V_3 -> V_9 = * V_51 ;
V_3 -> V_45 = F_34 ( V_49 , V_57 , & V_58 ,
V_3 ) ;
if ( ! V_3 -> V_45 )
return NULL ;
F_6 ( V_3 -> V_9 + V_11 , 0 ) ;
F_6 ( V_3 -> V_9 + V_59 , 0 ) ;
F_6 ( V_3 -> V_9 + V_25 , 0 ) ;
F_6 ( V_3 -> V_9 + V_10 , 0xffffffff ) ;
F_33 ( L_7 , V_3 -> V_56 ,
V_57 , V_3 -> V_9 ) ;
return V_3 ;
}
void T_3 F_35 ( void )
{
struct V_48 * V_60 ;
struct V_3 * V_3 ;
const T_1 * V_61 ;
F_36 (np, NULL, L_1 ) {
V_61 = F_32 ( V_60 , L_8 , NULL ) ;
if ( ! V_61 )
break;
}
F_28 ( ! V_60 ) ;
V_62 = F_27 ( V_60 ) ;
if ( ! V_62 )
F_37 ( L_9 , V_60 -> V_55 ) ;
F_38 ( V_62 -> V_45 ) ;
F_39 ( V_60 ) ;
F_36 (np, NULL, L_1 ) {
V_61 = F_32 ( V_60 , L_8 , NULL ) ;
if ( V_61 ) {
int V_63 ;
V_3 = F_27 ( V_60 ) ;
if ( ! V_3 )
F_37 ( L_10 ,
V_60 -> V_55 ) ;
V_63 = F_40 ( V_60 , 0 ) ;
F_41 ( V_63 , V_3 ) ;
F_42 ( V_63 , F_17 ) ;
}
}
}
unsigned int F_43 ( void )
{
T_1 V_39 ;
int V_4 ;
F_28 ( ! V_62 ) ;
V_39 = F_7 ( V_62 -> V_9 + V_43 ) ;
V_4 = 32 - F_23 ( V_39 ) ;
return F_24 ( V_62 -> V_45 , V_4 ) ;
}
