static inline void F_1 ( void )
{
unsigned int V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 | V_3 , V_2 ) ;
}
static void F_4 ( unsigned long V_4 )
{
if ( F_5 ( V_5 , V_6 ) ||
( ! F_6 ( & V_7 ) ) ) {
F_1 () ;
F_7 ( & V_8 , V_5 + V_9 ) ;
} else
F_8 ( L_1 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
V_6 = V_5 + V_11 -> V_12 * V_13 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 )
{
unsigned int V_1 = F_2 ( V_2 ) ;
F_3 ( V_11 -> V_12 , V_2 + V_14 ) ;
F_3 ( V_1 | V_15 | V_3 , V_2 ) ;
F_9 ( V_11 ) ;
F_7 ( & V_8 , V_5 + V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 )
{
unsigned int V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 & ~ V_15 , V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
unsigned int V_16 )
{
F_3 ( V_16 , V_2 + V_14 ) ;
V_11 -> V_12 = V_16 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
unsigned char V_21 ;
int V_22 = - V_23 ;
if ( F_14 ( V_18 ) ) {
F_15 ( & V_18 -> V_24 , L_2 ) ;
return - V_23 ;
}
if ( F_16 ( & V_25 , & V_26 , V_27 ,
0xf0000000 , 0xffffff00 , 0xff , NULL , NULL ) ) {
F_15 ( & V_18 -> V_24 , L_3 ) ;
goto V_28;
}
F_17 ( V_18 , V_29 , V_26 . V_30 ) ;
F_18 ( V_18 , V_31 , & V_21 ) ;
V_21 |= V_32 | V_33 ;
F_19 ( V_18 , V_31 , V_21 ) ;
F_20 ( V_18 , V_29 , & V_34 ) ;
if ( V_34 ) {
F_21 ( & V_18 -> V_24 , L_4 , V_34 ) ;
} else {
F_15 ( & V_18 -> V_24 , L_5 ) ;
goto V_35;
}
if ( ! F_22 ( V_34 , V_27 , L_6 ) ) {
F_15 ( & V_18 -> V_24 , L_7 ) ;
goto V_35;
}
V_2 = F_23 ( V_34 , V_27 ) ;
if ( V_2 == NULL ) {
F_15 ( & V_18 -> V_24 , L_8 ) ;
goto V_36;
}
if ( V_12 < 1 || V_12 > V_37 )
V_12 = V_38 ;
V_7 . V_12 = V_12 ;
V_7 . V_39 = & V_18 -> V_24 ;
F_24 ( & V_7 , V_40 ) ;
if ( F_2 ( V_2 ) & V_41 )
V_7 . V_42 |= V_43 ;
V_22 = F_25 ( & V_7 ) ;
if ( V_22 )
goto V_44;
F_7 ( & V_8 , V_5 + V_9 ) ;
return 0 ;
V_44:
F_26 ( V_2 ) ;
V_36:
F_27 ( V_34 , V_27 ) ;
V_35:
F_28 ( & V_26 ) ;
V_28:
F_29 ( V_18 ) ;
return V_22 ;
}
static void F_30 ( struct V_17 * V_18 )
{
F_31 ( & V_7 ) ;
F_32 ( & V_8 ) ;
F_26 ( V_2 ) ;
F_27 ( V_34 , V_27 ) ;
F_28 ( & V_26 ) ;
F_29 ( V_18 ) ;
}
