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
F_19 ( L_1 , V_29 ) ;
}
static void T_2 * T_6 F_20 ( struct V_28 * V_29 )
{
void T_2 * V_32 ;
V_32 = F_21 ( V_29 , 0 , V_29 -> V_33 ) ;
if ( F_22 ( V_32 ) )
F_19 ( L_2 , V_29 ) ;
return V_32 ;
}
static int T_6 F_23 ( struct V_28 * V_29 ,
struct V_28 * V_34 )
{
void T_2 * V_32 ;
V_5 . type = V_24 ;
V_32 = F_20 ( V_29 ) ;
V_5 . V_17 = V_32 + V_35 ;
V_5 . V_8 = V_32 + V_36 ;
V_5 . V_37 = V_32 + V_38 ;
V_5 . V_16 = V_32 + V_39 ;
V_5 . V_6 = V_32 + V_40 ;
V_5 . V_12 = NULL ;
F_24 ( V_5 . V_37 ) ;
F_17 ( V_29 , V_41 ) ;
return 0 ;
}
static int T_6 F_25 ( struct V_28 * V_29 ,
struct V_28 * V_34 )
{
void T_2 * V_32 ;
int V_42 ;
V_5 . type = V_43 ;
V_32 = F_20 ( V_29 ) ;
V_5 . V_17 = V_32 + V_44 ;
V_5 . V_8 = V_32 + V_45 ;
V_5 . V_37 = V_32 + V_46 ;
V_5 . V_16 = V_32 + V_47 ;
V_5 . V_6 = V_32 + V_48 ;
V_5 . V_12 = V_32 + V_49 ;
F_26 ( V_50 ,
V_5 . V_37 ) ;
for ( V_42 = 0 ; V_42 < 16 * 0x10 ; V_42 += 0x10 )
F_27 ( 0 , V_5 . V_6 + V_42 ) ;
F_17 ( V_29 , V_51 ) ;
F_28 ( F_12 ) ;
return 0 ;
}
