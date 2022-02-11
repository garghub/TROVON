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
F_4 ( V_2 , V_3 * V_16 / 255 ) ;
}
V_8 -> V_19 = ( V_3 * 0x64 ) / 0xff | V_20 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
T_1 V_21 = 0 ;
T_1 V_22 ;
if ( ! V_8 )
return;
V_22 = V_8 -> V_23 & V_24 ;
if ( ! V_22 ) {
F_2 ( L_2 ) ;
return;
}
if ( V_22 & V_25 )
V_21 |= F_1 ( V_2 , V_8 -> V_3 ) ;
V_8 -> V_23 = V_21 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
if ( V_8 && V_26 ) {
F_7 ( V_5 , 0 , V_27 ) ;
F_7 ( V_5 , 1 , V_27 ) ;
V_8 -> V_28 = V_29 | V_30 | V_31
| V_32 ;
V_8 -> V_33 = 1 ;
}
}
static int F_8 ( struct V_34 * V_35 ,
unsigned long V_36 , void * V_37 )
{
struct V_38 * V_39 ;
if ( ! V_26 )
return V_40 ;
V_39 = V_26 -> V_39 ;
V_39 -> V_41 = 0 ;
return V_42 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_43 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_44 )
return;
if ( V_9 -> V_39 ) {
V_9 -> V_39 -> V_41 = 0 ;
V_9 -> V_39 -> V_45 = 1 ;
V_26 = V_9 ;
F_10 ( & V_46 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_43 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_44 )
return;
if ( V_9 -> V_39 ) {
V_9 -> V_39 -> V_45 = 0 ;
V_26 = NULL ;
F_12 ( & V_46 ) ;
}
F_13 ( V_9 -> V_44 ) ;
V_9 -> V_44 = NULL ;
V_9 -> V_39 = NULL ;
V_9 -> V_47 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_48 = NULL ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_43 * V_9 = & V_5 -> V_9 ;
T_1 V_49 , V_50 ;
void T_2 * V_51 ;
int V_52 = 0 ;
F_15 ( V_2 -> V_53 , V_54 , & V_49 ) ;
if ( V_49 == 0 ) {
F_2 ( L_3 ) ;
return - V_55 ;
}
F_16 ( L_4 , V_49 ) ;
V_51 = F_17 ( V_49 , 8 * 1024 ) ;
if ( ! V_51 )
return - V_56 ;
if ( memcmp ( V_51 , V_57 , 16 ) ) {
F_2 ( L_5 ) ;
V_52 = - V_58 ;
goto V_59;
}
V_9 -> V_44 = V_51 ;
V_9 -> V_48 = V_51 + V_60 ;
V_9 -> V_61 = V_51 + V_62 ;
V_50 = V_9 -> V_44 -> V_50 ;
if ( V_50 & V_63 ) {
F_2 ( L_6 ) ;
V_9 -> V_39 = V_51 + V_64 ;
}
if ( V_50 & V_65 ) {
F_2 ( L_7 ) ;
V_9 -> V_8 = V_51 + V_66 ;
}
return 0 ;
V_59:
F_13 ( V_51 ) ;
return V_52 ;
}
