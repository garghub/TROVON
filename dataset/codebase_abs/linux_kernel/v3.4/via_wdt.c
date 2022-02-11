static inline void F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 | V_3 , V_2 ) ;
}
static void F_4 ( unsigned long V_4 )
{
if ( F_5 ( V_5 , V_6 ) ||
( ! F_6 ( V_7 , & V_8 . V_9 ) ) ) {
F_1 () ;
F_7 ( & V_10 , V_5 + V_11 ) ;
} else
F_8 ( L_1 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
V_6 = V_5 + V_13 -> V_14 * V_15 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
unsigned int V_1 = F_2 ( V_2 ) ;
F_3 ( V_13 -> V_14 , V_2 + V_16 ) ;
F_3 ( V_1 | V_17 | V_3 , V_2 ) ;
F_9 ( V_13 ) ;
F_7 ( & V_10 , V_5 + V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
unsigned int V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 & ~ V_17 , V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned int V_18 )
{
F_3 ( V_18 , V_2 + V_16 ) ;
V_13 -> V_14 = V_18 ;
return 0 ;
}
static int T_1 F_13 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
unsigned char V_23 ;
int V_24 = - V_25 ;
if ( F_14 ( V_20 ) ) {
F_15 ( & V_20 -> V_26 , L_2 ) ;
return - V_25 ;
}
if ( F_16 ( & V_27 , & V_28 , V_29 ,
0xf0000000 , 0xffffff00 , 0xff , NULL , NULL ) ) {
F_15 ( & V_20 -> V_26 , L_3 ) ;
goto V_30;
}
F_17 ( V_20 , V_31 , V_28 . V_32 ) ;
F_18 ( V_20 , V_33 , & V_23 ) ;
V_23 |= V_34 | V_35 ;
F_19 ( V_20 , V_33 , V_23 ) ;
F_20 ( V_20 , V_31 , & V_36 ) ;
if ( V_36 ) {
F_21 ( & V_20 -> V_26 , L_4 , V_36 ) ;
} else {
F_15 ( & V_20 -> V_26 , L_5 ) ;
goto V_37;
}
if ( ! F_22 ( V_36 , V_29 , L_6 ) ) {
F_15 ( & V_20 -> V_26 , L_7 ) ;
goto V_37;
}
V_2 = F_23 ( V_36 , V_29 ) ;
if ( V_2 == NULL ) {
F_15 ( & V_20 -> V_26 , L_8 ) ;
goto V_38;
}
V_8 . V_14 = V_14 ;
F_24 ( & V_8 , V_39 ) ;
if ( F_2 ( V_2 ) & V_40 )
V_8 . V_41 |= V_42 ;
V_24 = F_25 ( & V_8 ) ;
if ( V_24 )
goto V_43;
F_7 ( & V_10 , V_5 + V_11 ) ;
return 0 ;
V_43:
F_26 ( V_2 ) ;
V_38:
F_27 ( V_36 , V_29 ) ;
V_37:
F_28 ( & V_28 ) ;
V_30:
F_29 ( V_20 ) ;
return V_24 ;
}
static void T_2 F_30 ( struct V_19 * V_20 )
{
F_31 ( & V_8 ) ;
F_32 ( & V_10 ) ;
F_26 ( V_2 ) ;
F_27 ( V_36 , V_29 ) ;
F_28 ( & V_28 ) ;
F_29 ( V_20 ) ;
}
static int T_3 F_33 ( void )
{
if ( V_14 < 1 || V_14 > V_44 )
V_14 = V_45 ;
return F_34 ( & V_46 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_46 ) ;
}
