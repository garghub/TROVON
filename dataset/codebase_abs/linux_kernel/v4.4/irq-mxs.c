static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_3 << ( ( V_2 -> V_4 & 3 ) << 3 ) ;
}
static void T_2 * F_2 ( struct V_1 * V_2 )
{
return V_5 . V_6 + ( ( V_2 -> V_4 >> 2 ) * 0x10 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_7 ,
V_5 . V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_9 ,
V_5 . V_6 + V_10 + F_6 ( V_2 -> V_4 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_4 ( V_9 ,
V_5 . V_6 + V_11 + F_6 ( V_2 -> V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_4 ( F_1 ( V_2 , V_9 ) ,
F_2 ( V_2 ) + V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( F_10 ( V_2 -> V_4 ) ,
V_5 . V_12 +
F_11 ( V_2 -> V_4 ) ) ;
F_4 ( F_1 ( V_2 , V_9 ) ,
F_2 ( V_2 ) + V_11 ) ;
}
T_3 void T_4 F_12 ( struct V_13 * V_14 )
{
T_1 V_15 ;
V_15 = F_13 ( V_5 . V_16 ) ;
F_4 ( V_15 , V_5 . V_17 ) ;
F_14 ( V_18 , V_15 , V_14 ) ;
}
static int F_15 ( struct V_19 * V_2 , unsigned int V_20 ,
T_5 V_21 )
{
struct V_22 * V_23 ;
if ( V_5 . type == V_24 )
V_23 = & V_25 ;
else
V_23 = & V_26 ;
F_16 ( V_20 , V_23 , V_27 ) ;
return 0 ;
}
static void T_6 F_17 ( struct V_28 * V_29 ,
int V_30 )
{
V_18 = F_18 ( V_29 , V_30 ,
& V_31 , NULL ) ;
if ( ! V_18 )
F_19 ( L_1 , V_29 -> V_32 ) ;
}
static void T_2 * T_6 F_20 ( struct V_28 * V_29 )
{
void T_2 * V_33 ;
V_33 = F_21 ( V_29 , 0 , V_29 -> V_34 ) ;
if ( ! V_33 )
F_19 ( L_2 , V_29 -> V_32 ) ;
return V_33 ;
}
static int T_6 F_22 ( struct V_28 * V_29 ,
struct V_28 * V_35 )
{
void T_2 * V_33 ;
V_5 . type = V_24 ;
V_33 = F_20 ( V_29 ) ;
V_5 . V_17 = V_33 + V_36 ;
V_5 . V_8 = V_33 + V_37 ;
V_5 . V_38 = V_33 + V_39 ;
V_5 . V_16 = V_33 + V_40 ;
V_5 . V_6 = V_33 + V_41 ;
V_5 . V_12 = NULL ;
F_23 ( V_5 . V_38 ) ;
F_17 ( V_29 , V_42 ) ;
return 0 ;
}
static int T_6 F_24 ( struct V_28 * V_29 ,
struct V_28 * V_35 )
{
void T_2 * V_33 ;
int V_43 ;
V_5 . type = V_44 ;
V_33 = F_20 ( V_29 ) ;
V_5 . V_17 = V_33 + V_45 ;
V_5 . V_8 = V_33 + V_46 ;
V_5 . V_38 = V_33 + V_47 ;
V_5 . V_16 = V_33 + V_48 ;
V_5 . V_6 = V_33 + V_49 ;
V_5 . V_12 = V_33 + V_50 ;
F_25 ( V_51 ,
V_5 . V_38 ) ;
for ( V_43 = 0 ; V_43 < 16 * 0x10 ; V_43 += 0x10 )
F_26 ( 0 , V_5 . V_6 + V_43 ) ;
F_17 ( V_29 , V_52 ) ;
return 0 ;
}
