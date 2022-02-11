static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
struct V_10 * V_11 = V_5 -> V_10 ;
F_2 ( L_1 , V_3 ) ;
if ( ! ( V_3 & V_12 ) )
return V_13 ;
if ( V_11 == NULL )
return V_13 ;
V_3 &= V_14 ;
if ( V_3 > 255 )
return V_13 ;
F_3 ( V_2 , V_3 * V_11 -> V_15 . V_16 / 255 ) ;
V_8 -> V_17 = ( V_3 * 0x64 ) / 0xff | V_18 ;
return 0 ;
}
static void F_4 ( struct V_19 * V_20 )
{
struct V_21 * V_9 =
F_5 ( V_20 , struct V_21 , V_22 ) ;
struct V_4 * V_5 =
F_5 ( V_9 , struct V_4 , V_9 ) ;
struct V_7 * V_8 = V_9 -> V_8 ;
T_1 V_23 = 0 ;
T_1 V_24 ;
if ( ! V_8 )
return;
V_24 = V_8 -> V_25 & V_26 ;
if ( ! V_24 ) {
F_2 ( L_2 ) ;
return;
}
if ( V_24 & V_27 )
V_23 |= F_1 ( V_5 -> V_2 , V_8 -> V_3 ) ;
V_8 -> V_25 = V_23 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_9 . V_8 )
F_7 ( & V_5 -> V_9 . V_22 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
if ( V_8 && V_28 ) {
F_9 ( V_5 , 0 , V_29 ) ;
F_9 ( V_5 , 1 , V_29 ) ;
V_8 -> V_30 = V_31 | V_32 | V_33
| V_34 ;
V_8 -> V_35 = 1 ;
}
}
static int F_10 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
struct V_40 * V_41 ;
if ( ! V_28 )
return V_42 ;
V_41 = V_28 -> V_41 ;
V_41 -> V_43 = 0 ;
return V_44 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_45 )
return;
if ( V_9 -> V_41 ) {
V_9 -> V_41 -> V_43 = 0 ;
V_9 -> V_41 -> V_46 = 1 ;
V_28 = V_9 ;
F_12 ( & V_47 ) ;
}
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_45 )
return;
if ( V_9 -> V_41 ) {
V_9 -> V_41 -> V_46 = 0 ;
V_28 = NULL ;
F_14 ( & V_47 ) ;
}
F_15 ( & V_9 -> V_22 ) ;
F_16 ( V_9 -> V_45 ) ;
V_9 -> V_45 = NULL ;
V_9 -> V_41 = NULL ;
V_9 -> V_48 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_49 = NULL ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 * V_9 = & V_5 -> V_9 ;
T_1 V_50 , V_51 ;
void T_2 * V_52 ;
int V_53 = 0 ;
F_18 ( V_2 -> V_54 , V_55 , & V_50 ) ;
if ( V_50 == 0 ) {
F_2 ( L_3 ) ;
return - V_56 ;
}
F_19 ( & V_9 -> V_22 , F_4 ) ;
F_20 ( L_4 , V_50 ) ;
V_52 = F_21 ( V_50 , 8 * 1024 ) ;
if ( ! V_52 )
return - V_57 ;
if ( memcmp ( V_52 , V_58 , 16 ) ) {
F_2 ( L_5 ) ;
V_53 = - V_59 ;
goto V_60;
}
V_9 -> V_45 = V_52 ;
V_9 -> V_49 = V_52 + V_61 ;
V_9 -> V_62 = V_52 + V_63 ;
V_51 = V_9 -> V_45 -> V_51 ;
if ( V_51 & V_64 ) {
F_2 ( L_6 ) ;
V_9 -> V_41 = V_52 + V_65 ;
}
if ( V_51 & V_66 ) {
F_2 ( L_7 ) ;
V_9 -> V_8 = V_52 + V_67 ;
}
return 0 ;
V_60:
F_16 ( V_52 ) ;
return V_53 ;
}
