static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_2 , V_6 ) ;
V_5 &= ~ V_7 ;
if ( strcmp ( V_4 -> V_8 , L_1 ) == 0 )
V_5 |= V_9 ;
else if ( strcmp ( V_4 -> V_8 , L_2 ) == 0 )
V_5 |= V_10 ;
else if ( strcmp ( V_4 -> V_8 , L_3 ) == 0 )
V_5 |= V_11 ;
else {
F_3 ( V_12 L_4 , V_4 -> V_8 ) ;
return - V_13 ;
}
F_4 ( V_2 , V_6 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_2 , V_6 ) ;
switch ( V_5 & V_7 ) {
case V_14 :
V_4 -> V_15 = 1 ;
V_4 -> V_8 = L_1 ;
break;
case V_16 :
case V_17 :
V_4 -> V_15 = 1 ;
V_4 -> V_8 = L_2 ;
break;
case V_11 :
V_4 -> V_15 = 1 ;
V_4 -> V_8 = L_3 ;
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
unsigned long V_5 = F_2 ( V_2 , V_6 ) ;
F_7 ( L_5 ,
V_20 , V_2 , V_2 -> V_21 , V_19 ) ;
V_5 &= V_7 ;
F_4 ( V_2 , V_6 , V_5 | V_19 -> V_5 ) ;
F_4 ( V_2 , V_22 , V_19 -> V_23 ) ;
F_4 ( V_2 , V_24 , V_19 -> V_25 | V_26 ) ;
F_4 ( V_2 , V_24 , V_19 -> V_25 ) ;
return 0 ;
}
static int F_8 ( struct V_27 * V_28 )
{
F_7 ( L_6 , V_28 ) ;
return F_9 ( V_28 , & V_29 ) ;
}
static inline int F_10 ( void )
{
return F_11 ( & V_30 , & V_29 ) ;
}
static inline void F_12 ( void )
{
F_13 ( & V_30 ) ;
}
