static int F_1 ( unsigned long V_1 )
{
F_2 () ;
return 0 ;
}
static void F_3 ( void )
{}
static void F_4 ( unsigned int V_2 , unsigned int V_1 )
{}
static inline void F_5 ( unsigned int V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
if ( V_5 -> V_7 )
F_7 ( V_3 , V_5 -> V_7 ) ;
}
static void F_8 ( unsigned int V_2 , unsigned int V_1 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
T_1 V_8 ;
switch ( V_1 ) {
case V_9 :
V_8 = V_10 ;
break;
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
case V_14 :
default:
V_8 = V_15 ;
break;
}
if ( V_5 -> V_16 )
F_7 ( V_8 , V_5 -> V_16 ) ;
}
static inline void F_9 ( void )
{
T_1 V_17 ;
V_17 = F_10 ( V_18 ,
V_19 , V_20 ) ;
F_11 ( V_17 , V_18 ,
V_19 , V_20 ) ;
}
static inline void F_12 ( unsigned int V_2 )
{
T_1 V_17 ;
if ( V_2 ) {
V_17 = F_13 ( V_21 ,
V_22 ) ;
F_14 ( V_17 , V_21 ,
V_22 ) ;
} else {
V_17 = F_13 ( V_23 ,
V_22 ) ;
F_14 ( V_17 , V_23 ,
V_22 ) ;
}
}
static void F_15 ( unsigned int V_2 , unsigned int V_24 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
if ( V_5 -> V_25 )
F_7 ( V_24 , V_5 -> V_25 ) ;
}
static void T_2 F_16 ( void )
{
void T_3 * V_26 = F_17 () ;
if ( V_26 && V_27 ) {
F_7 ( V_28 . V_29 ,
V_27 + V_30 ) ;
F_7 ( V_28 . V_31 ,
V_27 + V_32 ) ;
}
}
static void T_2 F_16 ( void )
{}
int F_18 ( unsigned int V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_33 ) ;
unsigned int V_24 = 0 ;
unsigned int V_35 ;
if ( F_19 () == V_36 )
return - V_37 ;
switch ( V_34 ) {
case V_13 :
case V_14 :
V_24 = 0 ;
break;
case V_11 :
V_24 = 1 ;
break;
case V_9 :
if ( F_20 ( V_38 ) ) {
V_24 = 0 ;
break;
}
default:
F_21 ( 1 ) ;
return - V_37 ;
}
F_22 ( NULL ) ;
F_9 () ;
if ( ( F_23 ( V_39 ) == V_9 ) &&
( F_24 ( V_39 ) == V_11 ) )
V_24 = 2 ;
F_12 ( V_33 ) ;
F_25 ( V_5 -> V_40 , V_34 ) ;
F_5 ( V_33 , F_26 ( V_41 . V_42 ) ) ;
V_41 . V_43 ( V_33 , V_34 ) ;
F_15 ( V_33 , V_24 ) ;
if ( V_24 )
F_27 ( V_24 , V_41 . V_44 ) ;
else
V_41 . V_44 ( V_24 ) ;
if ( F_20 ( V_45 ) && V_33 )
F_28 () ;
V_35 = F_29 () ;
F_25 ( V_5 -> V_40 , V_13 ) ;
F_30 ( NULL ) ;
return 0 ;
}
int F_31 ( unsigned int V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_33 ) ;
unsigned int V_1 = 0 ;
if ( F_19 () == V_36 )
return - V_37 ;
V_34 = F_32 ( V_5 -> V_40 ,
false , V_34 ) ;
if ( V_34 == V_11 )
V_1 = 1 ;
F_33 ( V_5 -> V_40 ) ;
F_25 ( V_5 -> V_40 , V_34 ) ;
F_5 ( V_33 , F_26 ( V_41 . V_46 ) ) ;
V_41 . V_43 ( V_33 , V_34 ) ;
V_41 . V_44 ( V_1 ) ;
F_25 ( V_5 -> V_40 , V_13 ) ;
return 0 ;
}
static void F_34 ( void )
{
T_1 V_17 ;
V_17 = F_13 ( V_47 ,
V_48 ) ;
V_17 |= F_35 ( 24 ) | F_35 ( 25 ) ;
F_14 ( V_17 , V_47 ,
V_48 ) ;
}
int T_2 F_36 ( void )
{
struct V_4 * V_5 ;
if ( F_19 () == V_36 ) {
F_37 ( 1 , L_1 ) ;
return - V_49 ;
}
if ( F_38 () )
V_27 = F_39 () ;
V_5 = & F_6 ( V_6 , 0x0 ) ;
if ( V_27 ) {
V_5 -> V_16 = V_27 + V_50 ;
V_5 -> V_7 = V_27 +
V_51 ;
V_5 -> V_25 = V_27 + V_52 ;
}
V_5 -> V_40 = F_40 ( L_2 ) ;
if ( ! V_5 -> V_40 ) {
F_41 ( L_3 ) ;
return - V_49 ;
}
F_33 ( V_5 -> V_40 ) ;
F_12 ( 0 ) ;
F_25 ( V_5 -> V_40 , V_13 ) ;
V_5 = & F_6 ( V_6 , 0x1 ) ;
if ( V_27 ) {
V_5 -> V_16 = V_27 + V_53 ;
V_5 -> V_7 = V_27 +
V_54 ;
V_5 -> V_25 = V_27 + V_55 ;
}
V_5 -> V_40 = F_40 ( L_4 ) ;
if ( ! V_5 -> V_40 ) {
F_41 ( L_5 ) ;
return - V_49 ;
}
F_33 ( V_5 -> V_40 ) ;
F_12 ( 1 ) ;
F_25 ( V_5 -> V_40 , V_13 ) ;
V_39 = F_40 ( L_6 ) ;
if ( ! V_39 ) {
F_41 ( L_7 ) ;
return - V_49 ;
}
F_33 ( V_39 ) ;
F_9 () ;
if ( V_27 ) {
F_7 ( ( F_42 () != V_56 ) ? 1 : 0 ,
V_27 + V_57 ) ;
F_16 () ;
}
if ( F_38 () ) {
V_41 . V_44 = V_58 ;
V_41 . V_42 = V_59 ;
V_41 . V_43 = F_8 ;
V_41 . V_46 = V_60 ;
V_22 = V_61 ;
} else if ( F_43 () || F_44 () ) {
V_22 = V_62 ;
F_34 () ;
}
if ( F_45 () )
V_41 . V_46 = V_63 ;
return 0 ;
}
