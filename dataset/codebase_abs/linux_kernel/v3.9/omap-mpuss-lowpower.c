static inline void F_1 ( unsigned int V_1 , T_1 V_2 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_3 ( V_2 , V_4 -> V_6 ) ;
}
static void F_4 ( unsigned int V_1 , unsigned int V_7 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
T_1 V_8 ;
switch ( V_7 ) {
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
F_3 ( V_8 , V_4 -> V_16 ) ;
}
static inline void F_5 ( void )
{
T_1 V_17 ;
V_17 = F_6 ( V_18 ,
V_19 , V_20 ) ;
F_7 ( V_17 , V_18 ,
V_19 , V_20 ) ;
}
static inline void F_8 ( unsigned int V_1 )
{
T_1 V_17 ;
if ( V_1 ) {
V_17 = F_9 ( V_21 ,
V_22 ) ;
F_10 ( V_17 , V_21 ,
V_22 ) ;
} else {
V_17 = F_9 ( V_23 ,
V_24 ) ;
F_10 ( V_17 , V_23 ,
V_24 ) ;
}
}
T_1 F_11 ( void )
{
T_1 V_17 ;
V_17 = F_6 ( V_18 ,
V_19 , V_20 ) ;
V_17 &= V_25 ;
return V_17 ;
}
static void F_12 ( unsigned int V_1 , unsigned int V_26 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_3 ( V_26 , V_4 -> V_27 ) ;
}
static void F_13 ( void )
{
T_1 V_28 ;
void T_2 * V_29 = F_14 () ;
V_28 = F_15 ( V_29 + V_30 ) ;
F_3 ( V_28 , V_31 + V_32 ) ;
V_28 = F_15 ( V_29 + V_33 ) ;
F_3 ( V_28 , V_31 + V_34 ) ;
}
static void F_13 ( void )
{}
int F_16 ( unsigned int V_35 , unsigned int V_36 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_35 ) ;
unsigned int V_26 = 0 ;
unsigned int V_37 ;
if ( F_17 () == V_38 )
return - V_39 ;
switch ( V_36 ) {
case V_13 :
case V_14 :
V_26 = 0 ;
break;
case V_11 :
V_26 = 1 ;
break;
case V_9 :
default:
F_18 ( 1 ) ;
return - V_39 ;
}
F_19 ( NULL ) ;
F_5 () ;
if ( ( F_20 ( V_40 ) == V_9 ) &&
( F_21 ( V_40 ) == V_11 ) )
V_26 = 2 ;
F_8 ( V_35 ) ;
F_22 ( V_4 -> V_41 , V_36 ) ;
F_1 ( V_35 , F_23 ( V_42 ) ) ;
F_4 ( V_35 , V_36 ) ;
F_12 ( V_35 , V_26 ) ;
F_24 ( V_26 , V_43 ) ;
V_37 = F_25 () ;
F_22 ( V_4 -> V_41 , V_13 ) ;
F_26 ( NULL ) ;
return 0 ;
}
int T_3 F_27 ( unsigned int V_35 , unsigned int V_36 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_35 ) ;
unsigned int V_7 = 0 ;
if ( F_17 () == V_38 )
return - V_39 ;
if ( V_36 == V_11 )
V_7 = 1 ;
F_28 ( V_4 -> V_41 ) ;
F_22 ( V_4 -> V_41 , V_36 ) ;
F_1 ( V_35 , F_23 ( V_4 -> V_44 ) ) ;
F_4 ( V_35 , V_36 ) ;
V_43 ( V_7 ) ;
F_22 ( V_4 -> V_41 , V_13 ) ;
return 0 ;
}
int T_4 F_29 ( void )
{
struct V_3 * V_4 ;
if ( F_17 () == V_38 ) {
F_30 ( 1 , L_1 ) ;
return - V_45 ;
}
V_31 = F_31 () ;
V_4 = & F_2 ( V_5 , 0x0 ) ;
V_4 -> V_16 = V_31 + V_46 ;
V_4 -> V_6 = V_31 + V_47 ;
V_4 -> V_27 = V_31 + V_48 ;
V_4 -> V_41 = F_32 ( L_2 ) ;
if ( ! V_4 -> V_41 ) {
F_33 ( L_3 ) ;
return - V_45 ;
}
F_28 ( V_4 -> V_41 ) ;
F_8 ( 0 ) ;
F_22 ( V_4 -> V_41 , V_13 ) ;
V_4 = & F_2 ( V_5 , 0x1 ) ;
V_4 -> V_16 = V_31 + V_49 ;
V_4 -> V_6 = V_31 + V_50 ;
V_4 -> V_27 = V_31 + V_51 ;
if ( F_34 () )
V_4 -> V_44 = V_52 ;
else
V_4 -> V_44 = V_53 ;
V_4 -> V_41 = F_32 ( L_4 ) ;
if ( ! V_4 -> V_41 ) {
F_33 ( L_5 ) ;
return - V_45 ;
}
F_28 ( V_4 -> V_41 ) ;
F_8 ( 1 ) ;
F_22 ( V_4 -> V_41 , V_13 ) ;
V_40 = F_32 ( L_6 ) ;
if ( ! V_40 ) {
F_33 ( L_7 ) ;
return - V_45 ;
}
F_28 ( V_40 ) ;
F_5 () ;
if ( F_35 () != V_54 )
F_3 ( 1 , V_31 + V_55 ) ;
else
F_3 ( 0 , V_31 + V_55 ) ;
F_13 () ;
return 0 ;
}
