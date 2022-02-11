static inline void F_1 ( unsigned int V_1 , T_1 V_2 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_3 ( V_2 , V_4 -> V_6 ) ;
}
static inline void F_4 ( unsigned int V_1 ,
unsigned int V_7 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_5 ( V_4 -> V_8 , V_7 ) ;
}
static inline unsigned int F_6 ( unsigned int V_1 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
return F_7 ( V_4 -> V_8 ) ;
}
static inline void F_8 ( unsigned int V_1 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_9 ( V_4 -> V_8 ) ;
}
static void F_10 ( unsigned int V_1 , unsigned int V_9 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
T_1 V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = V_12 ;
break;
case V_13 :
V_10 = V_14 ;
break;
case V_15 :
case V_16 :
default:
V_10 = V_17 ;
break;
}
F_3 ( V_10 , V_4 -> V_18 ) ;
}
static inline void F_11 ( void )
{
T_1 V_19 ;
V_19 = F_12 ( V_20 ,
V_21 , V_22 ) ;
F_13 ( V_19 , V_20 ,
V_21 , V_22 ) ;
}
static inline void F_14 ( unsigned int V_1 )
{
T_1 V_19 ;
if ( V_1 ) {
V_19 = F_15 ( V_23 ,
V_24 ) ;
F_16 ( V_19 , V_23 ,
V_24 ) ;
} else {
V_19 = F_15 ( V_25 ,
V_26 ) ;
F_16 ( V_19 , V_25 ,
V_26 ) ;
}
}
T_1 F_17 ( void )
{
T_1 V_19 ;
V_19 = F_12 ( V_20 ,
V_21 , V_22 ) ;
V_19 &= V_27 ;
return V_19 ;
}
static void F_18 ( unsigned int V_1 , unsigned int V_28 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_3 ( V_28 , V_4 -> V_29 ) ;
}
static void F_19 ( void )
{
T_1 V_30 ;
void T_2 * V_31 = F_20 () ;
V_30 = F_21 ( V_31 + V_32 ) ;
F_3 ( V_30 , V_33 + V_34 ) ;
V_30 = F_21 ( V_31 + V_35 ) ;
F_3 ( V_30 , V_33 + V_36 ) ;
}
static void F_19 ( void )
{}
int F_22 ( unsigned int V_37 , unsigned int V_7 )
{
unsigned int V_28 = 0 ;
unsigned int V_38 ;
if ( F_23 () == V_39 )
return - V_40 ;
switch ( V_7 ) {
case V_15 :
case V_16 :
V_28 = 0 ;
break;
case V_13 :
V_28 = 1 ;
break;
case V_11 :
default:
F_24 ( 1 ) ;
return - V_40 ;
}
F_25 () ;
F_11 () ;
if ( ( F_26 ( V_41 ) == V_11 ) &&
( F_27 ( V_41 ) == V_13 ) )
V_28 = 2 ;
F_14 ( V_37 ) ;
F_4 ( V_37 , V_7 ) ;
F_1 ( V_37 , F_28 ( V_42 ) ) ;
F_10 ( V_37 , V_7 ) ;
F_18 ( V_37 , V_28 ) ;
F_29 ( V_28 , V_43 ) ;
V_38 = F_30 () ;
F_4 ( V_38 , V_15 ) ;
F_31 () ;
return 0 ;
}
int T_3 F_32 ( unsigned int V_37 , unsigned int V_7 )
{
unsigned int V_9 = 0 ;
if ( F_23 () == V_39 )
return - V_40 ;
if ( V_7 == V_13 )
V_9 = 1 ;
F_8 ( V_37 ) ;
F_4 ( V_37 , V_7 ) ;
F_1 ( V_37 , F_28 ( V_44 ) ) ;
F_10 ( V_37 , V_7 ) ;
V_43 ( V_9 ) ;
F_4 ( V_37 , V_15 ) ;
return 0 ;
}
int T_4 F_33 ( void )
{
struct V_3 * V_4 ;
if ( F_23 () == V_39 ) {
F_34 ( 1 , L_1 ) ;
return - V_45 ;
}
V_33 = F_35 () ;
V_4 = & F_2 ( V_5 , 0x0 ) ;
V_4 -> V_18 = V_33 + V_46 ;
V_4 -> V_6 = V_33 + V_47 ;
V_4 -> V_29 = V_33 + V_48 ;
V_4 -> V_8 = F_36 ( L_2 ) ;
if ( ! V_4 -> V_8 ) {
F_37 ( L_3 ) ;
return - V_45 ;
}
F_9 ( V_4 -> V_8 ) ;
F_14 ( 0 ) ;
F_5 ( V_4 -> V_8 , V_15 ) ;
V_4 = & F_2 ( V_5 , 0x1 ) ;
V_4 -> V_18 = V_33 + V_49 ;
V_4 -> V_6 = V_33 + V_50 ;
V_4 -> V_29 = V_33 + V_51 ;
V_4 -> V_8 = F_36 ( L_4 ) ;
if ( ! V_4 -> V_8 ) {
F_37 ( L_5 ) ;
return - V_45 ;
}
F_9 ( V_4 -> V_8 ) ;
F_14 ( 1 ) ;
F_5 ( V_4 -> V_8 , V_15 ) ;
V_41 = F_36 ( L_6 ) ;
if ( ! V_41 ) {
F_37 ( L_7 ) ;
return - V_45 ;
}
F_9 ( V_41 ) ;
F_11 () ;
if ( F_38 () != V_52 )
F_3 ( 1 , V_33 + V_53 ) ;
else
F_3 ( 0 , V_33 + V_53 ) ;
F_19 () ;
return 0 ;
}
