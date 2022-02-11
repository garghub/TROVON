static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline void F_2 ( struct V_1 * V_5 )
{
T_1 V_6 = F_3 ( V_5 -> V_7 ) ;
V_6 &= ~ 0x80 ;
F_4 ( V_5 -> V_7 , V_6 | V_8 ) ;
}
static inline void F_5 ( struct V_1 * V_5 )
{
T_1 V_6 = F_3 ( V_5 -> V_7 ) ;
V_6 |= 0x80 ;
F_4 ( V_5 -> V_7 , V_6 & ~ V_8 ) ;
}
static inline void F_6 ( struct V_1 * V_5 )
{
T_1 V_6 = F_3 ( V_5 -> V_7 ) ;
F_4 ( V_5 -> V_7 , V_6 | V_9 ) ;
}
static inline void F_7 ( struct V_1 * V_5 )
{
T_1 V_6 = F_3 ( V_5 -> V_7 ) ;
F_4 ( V_5 -> V_7 , V_6 & ~ V_9 ) ;
}
static inline void F_8 ( unsigned V_10 )
{
F_9 ( V_10 ) ;
}
static inline void F_10 ( struct V_2 * V_11 , int V_12 )
{
struct V_1 * V_5 = F_1 ( V_11 ) ;
if ( V_12 )
F_6 ( V_5 ) ;
else
F_7 ( V_5 ) ;
}
static inline void F_11 ( struct V_2 * V_11 , int V_12 )
{
}
static inline int F_12 ( struct V_2 * V_11 )
{
struct V_1 * V_5 = F_1 ( V_11 ) ;
return ( ( V_13 == ( F_13 ( V_5 -> V_7 ) & V_13 ) ) ? 0 : 1 ) ;
}
static void F_14 ( struct V_2 * V_3 , int V_14 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_14 )
F_5 ( V_5 ) ;
else
F_2 ( V_5 ) ;
}
static T_2 F_15 ( struct V_2 * V_3 , unsigned V_15 , T_2 V_16 , T_1 V_17 )
{
return F_16 ( V_3 , V_15 , 0 , 0 , V_16 , V_17 ) ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_5 ;
struct V_22 * V_23 ;
int V_24 ;
if ( V_25 ) {
F_18 ( V_26
L_1 ,
V_27 ) ;
return;
}
V_23 = F_19 ( V_19 -> V_28 -> V_29 , sizeof *V_5 ) ;
if ( ! V_23 ) {
V_24 = - V_30 ;
goto V_31;
}
V_5 = F_20 ( V_23 ) ;
V_5 -> V_32 . V_23 = F_21 ( V_23 ) ;
V_5 -> V_32 . V_33 = F_14 ;
V_5 -> V_32 . V_34 [ V_35 ] = F_15 ;
V_5 -> V_32 . V_36 = V_37 ;
V_5 -> V_7 = V_19 ;
V_21 = F_22 ( V_19 , V_27 ,
NULL , NULL , NULL ,
V_38 , V_5 ) ;
if ( ! V_21 ) {
V_24 = - V_30 ;
goto V_39;
}
V_5 -> V_21 = V_21 ;
V_24 = F_23 ( V_21 ) ;
if ( V_24 < 0 )
goto V_40;
V_24 = F_24 ( & V_5 -> V_32 ) ;
if ( V_24 < 0 ) {
F_18 ( V_26
L_2 ,
V_27 , V_24 ) ;
goto V_41;
}
strcpy ( V_5 -> V_42 . V_43 , L_3 ) ;
V_5 -> V_42 . V_44 = 6 * 1000 * 1000 ;
V_5 -> V_42 . V_45 = 0 ;
V_5 -> V_42 . V_46 = V_37 | V_35 ;
F_4 ( V_5 -> V_7 , V_47 ) ;
V_5 -> V_42 . V_4 = V_5 ;
V_5 -> V_48 = F_25 ( V_5 -> V_32 . V_23 , & V_5 -> V_42 ) ;
if ( V_5 -> V_48 )
F_26 ( & V_5 -> V_48 -> V_29 , L_4 ,
F_27 ( & V_5 -> V_48 -> V_29 ) ) ;
else {
F_18 ( V_26 L_5 , V_27 ) ;
V_24 = - V_49 ;
goto V_50;
}
V_5 -> V_48 -> V_51 = 8 ;
V_25 = V_5 ;
return;
V_50:
F_28 ( & V_5 -> V_32 ) ;
V_41:
F_4 ( V_5 -> V_7 , 0 ) ;
F_29 ( 10 ) ;
F_30 ( V_5 -> V_21 ) ;
V_40:
F_31 ( V_21 ) ;
V_39:
( void ) F_32 ( V_23 ) ;
V_31:
F_33 ( L_6 , V_27 , V_24 ) ;
}
static void F_34 ( struct V_18 * V_19 )
{
struct V_1 * V_5 ;
if ( ! V_25 || V_25 -> V_7 != V_19 )
return;
V_5 = V_25 ;
F_28 ( & V_5 -> V_32 ) ;
F_4 ( V_5 -> V_7 , 0 ) ;
F_30 ( V_5 -> V_21 ) ;
F_31 ( V_5 -> V_21 ) ;
( void ) F_32 ( V_5 -> V_32 . V_23 ) ;
V_25 = NULL ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_52 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_52 ) ;
}
