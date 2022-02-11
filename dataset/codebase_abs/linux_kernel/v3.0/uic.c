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
static int F_17 ( struct V_27 * V_28 , struct V_34 * V_35 ,
const T_1 * V_36 , unsigned int V_37 ,
T_2 * V_38 , unsigned int * V_39 )
{
F_18 ( V_37 != 2 ) ;
* V_38 = V_36 [ 0 ] ;
* V_39 = V_36 [ 1 ] ;
return 0 ;
}
void F_19 ( unsigned int V_29 , struct V_40 * V_41 )
{
struct V_42 * V_43 = F_20 ( V_41 ) ;
struct V_1 * V_44 = F_21 ( V_41 ) ;
struct V_3 * V_3 = F_22 ( V_29 ) ;
T_1 V_45 ;
int V_4 ;
int V_46 ;
F_23 ( & V_41 -> V_8 ) ;
if ( F_5 ( V_44 ) )
V_43 -> V_47 ( V_44 ) ;
else
V_43 -> V_48 ( V_44 ) ;
F_24 ( & V_41 -> V_8 ) ;
V_45 = F_7 ( V_3 -> V_9 + V_49 ) ;
if ( ! V_45 )
goto V_50;
V_4 = 32 - F_25 ( V_45 ) ;
V_46 = F_26 ( V_3 -> V_51 , V_4 ) ;
F_27 ( V_46 ) ;
V_50:
F_23 ( & V_41 -> V_8 ) ;
if ( F_5 ( V_44 ) )
V_43 -> V_52 ( V_44 ) ;
if ( ! F_28 ( V_44 ) && V_43 -> V_53 )
V_43 -> V_53 ( V_44 ) ;
F_24 ( & V_41 -> V_8 ) ;
}
static struct V_3 * T_3 F_29 ( struct V_34 * V_54 )
{
struct V_3 * V_3 ;
const T_1 * V_55 , * V_56 ;
int V_57 ;
F_18 ( ! F_30 ( V_54 , L_1 ) ) ;
V_3 = F_31 ( sizeof( * V_3 ) , V_58 ) ;
if ( ! V_3 )
return NULL ;
F_32 ( & V_3 -> V_8 ) ;
V_55 = F_33 ( V_54 , L_2 , & V_57 ) ;
if ( ! V_55 || ( V_57 != sizeof( T_1 ) ) ) {
F_34 ( V_59 L_3
L_4 , V_54 -> V_60 ) ;
return NULL ;
}
V_3 -> V_61 = * V_55 ;
V_56 = F_33 ( V_54 , L_5 , & V_57 ) ;
if ( ! V_56 || ( V_57 != 2 * sizeof( T_1 ) ) ) {
F_34 ( V_59 L_3
L_6 , V_54 -> V_60 ) ;
return NULL ;
}
V_3 -> V_9 = * V_56 ;
V_3 -> V_51 = F_35 ( V_54 , V_62 ,
V_63 , & V_64 , - 1 ) ;
if ( ! V_3 -> V_51 )
return NULL ;
V_3 -> V_51 -> V_31 = V_3 ;
F_6 ( V_3 -> V_9 + V_11 , 0 ) ;
F_6 ( V_3 -> V_9 + V_65 , 0 ) ;
F_6 ( V_3 -> V_9 + V_25 , 0 ) ;
F_6 ( V_3 -> V_9 + V_10 , 0xffffffff ) ;
F_34 ( L_7 , V_3 -> V_61 ,
V_63 , V_3 -> V_9 ) ;
return V_3 ;
}
void T_3 F_36 ( void )
{
struct V_34 * V_66 ;
struct V_3 * V_3 ;
const T_1 * V_67 ;
F_37 (np, NULL, L_1 ) {
V_67 = F_33 ( V_66 , L_8 , NULL ) ;
if ( ! V_67 )
break;
}
F_18 ( ! V_66 ) ;
V_68 = F_29 ( V_66 ) ;
if ( ! V_68 )
F_38 ( L_9 , V_66 -> V_60 ) ;
F_39 ( V_68 -> V_51 ) ;
F_40 ( V_66 ) ;
F_37 (np, NULL, L_1 ) {
V_67 = F_33 ( V_66 , L_8 , NULL ) ;
if ( V_67 ) {
int V_69 ;
V_3 = F_29 ( V_66 ) ;
if ( ! V_3 )
F_38 ( L_10 ,
V_66 -> V_60 ) ;
V_69 = F_41 ( V_66 , 0 ) ;
F_42 ( V_69 , V_3 ) ;
F_43 ( V_69 , F_19 ) ;
}
}
}
unsigned int F_44 ( void )
{
T_1 V_45 ;
int V_4 ;
F_18 ( ! V_68 ) ;
V_45 = F_7 ( V_68 -> V_9 + V_49 ) ;
V_4 = 32 - F_25 ( V_45 ) ;
return F_26 ( V_68 -> V_51 , V_4 ) ;
}
