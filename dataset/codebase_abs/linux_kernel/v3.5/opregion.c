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
if ( F_3 ( V_15 ) ) {
int V_16 = V_11 -> V_17 . V_18 ;
V_11 -> V_17 . V_19 = V_3 * V_16 / 255 ;
F_4 ( V_11 ) ;
}
V_8 -> V_20 = ( V_3 * 0x64 ) / 0xff | V_21 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_22 = 0 ;
T_1 V_23 ;
if ( ! V_8 )
return;
V_23 = V_8 -> V_24 & V_25 ;
if ( ! V_23 ) {
F_2 ( L_2 ) ;
return;
}
if ( V_23 & V_26 )
V_22 |= F_1 ( V_2 , V_8 -> V_3 ) ;
V_8 -> V_24 = V_22 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
if ( V_8 && V_27 ) {
F_7 ( V_5 , 0 , V_28 ) ;
F_7 ( V_5 , 1 , V_28 ) ;
V_8 -> V_29 = V_30 | V_31 | V_32
| V_33 ;
V_8 -> V_34 = 1 ;
}
}
static int F_8 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
struct V_39 * V_40 ;
if ( ! V_27 )
return V_41 ;
V_40 = V_27 -> V_40 ;
V_40 -> V_42 = 0 ;
return V_43 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_44 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_45 )
return;
if ( V_9 -> V_40 ) {
V_9 -> V_40 -> V_42 = 0 ;
V_9 -> V_40 -> V_46 = 1 ;
V_27 = V_9 ;
F_10 ( & V_47 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_44 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_45 )
return;
if ( V_9 -> V_40 ) {
V_9 -> V_40 -> V_46 = 0 ;
V_27 = NULL ;
F_12 ( & V_47 ) ;
}
F_13 ( V_9 -> V_45 ) ;
V_9 -> V_45 = NULL ;
V_9 -> V_40 = NULL ;
V_9 -> V_48 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_49 = NULL ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_44 * V_9 = & V_5 -> V_9 ;
T_1 V_50 , V_51 ;
void T_2 * V_52 ;
int V_53 = 0 ;
F_15 ( V_2 -> V_54 , V_55 , & V_50 ) ;
if ( V_50 == 0 ) {
F_2 ( L_3 ) ;
return - V_56 ;
}
F_16 ( L_4 , V_50 ) ;
V_52 = F_17 ( V_50 , 8 * 1024 ) ;
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
V_9 -> V_40 = V_52 + V_65 ;
}
if ( V_51 & V_66 ) {
F_2 ( L_7 ) ;
V_9 -> V_8 = V_52 + V_67 ;
}
return 0 ;
V_60:
F_13 ( V_52 ) ;
return V_53 ;
}
