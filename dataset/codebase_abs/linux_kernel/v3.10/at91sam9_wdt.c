static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 | V_3 ) ;
}
static void F_3 ( unsigned long V_4 )
{
if ( F_4 ( V_5 , V_6 . V_7 ) ||
( ! F_5 ( & V_8 ) ) ) {
F_1 () ;
F_6 ( & V_6 . V_9 , V_5 + V_10 ) ;
} else
F_7 ( L_1 ) ;
}
static int F_8 ( struct V_11 * V_12 )
{
V_6 . V_7 = V_5 + V_12 -> V_13 * V_14 ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 )
{
F_8 ( V_12 ) ;
F_6 ( & V_6 . V_9 , V_5 + V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , unsigned int V_15 )
{
V_12 -> V_13 = V_15 ;
return 0 ;
}
static int F_12 ( unsigned int V_13 )
{
unsigned int V_16 ;
unsigned int V_17 ;
V_17 = F_13 ( V_18 ) ;
if ( V_17 & V_19 ) {
F_14 ( L_2 ) ;
return - V_20 ;
}
V_16 = V_21
| V_22
| V_23
| ( V_13 & V_24 ) ;
F_2 ( V_18 , V_16 ) ;
return 0 ;
}
static int T_1 F_15 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
int V_29 ;
V_28 = F_16 ( V_26 , V_30 , 0 ) ;
if ( ! V_28 )
return - V_31 ;
V_6 . V_32 = F_17 ( V_28 -> V_33 , F_18 ( V_28 ) ) ;
if ( ! V_6 . V_32 ) {
F_19 ( & V_26 -> V_34 , L_3 ) ;
return - V_35 ;
}
V_8 . V_36 = & V_26 -> V_34 ;
F_20 ( & V_8 , V_37 , & V_26 -> V_34 ) ;
F_21 ( & V_8 , V_38 ) ;
V_29 = F_12 ( F_22 ( V_39 * 1000 ) ) ;
if ( V_29 )
return V_29 ;
V_29 = F_23 ( & V_8 ) ;
if ( V_29 )
return V_29 ;
V_6 . V_7 = V_5 + V_8 . V_13 * V_14 ;
F_24 ( & V_6 . V_9 , F_3 , 0 ) ;
F_6 ( & V_6 . V_9 , V_5 + V_10 ) ;
F_25 ( L_4 ,
V_8 . V_13 , V_38 ) ;
return 0 ;
}
static int T_2 F_26 ( struct V_25 * V_26 )
{
F_27 ( & V_8 ) ;
F_28 ( L_5 ) ;
F_29 ( & V_6 . V_9 ) ;
return 0 ;
}
