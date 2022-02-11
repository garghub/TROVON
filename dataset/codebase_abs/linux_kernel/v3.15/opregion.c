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
static void F_5 ( struct V_21 * V_22 )
{
struct V_23 * V_9 =
F_6 ( V_22 , struct V_23 , V_24 ) ;
struct V_4 * V_5 =
F_6 ( V_9 , struct V_4 , V_9 ) ;
struct V_7 * V_8 = V_9 -> V_8 ;
T_1 V_25 = 0 ;
T_1 V_26 ;
if ( ! V_8 )
return;
V_26 = V_8 -> V_27 & V_28 ;
if ( ! V_26 ) {
F_2 ( L_2 ) ;
return;
}
if ( V_26 & V_29 )
V_25 |= F_1 ( V_5 -> V_2 , V_8 -> V_3 ) ;
V_8 -> V_27 = V_25 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_9 . V_8 )
F_8 ( & V_5 -> V_9 . V_24 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 . V_8 ;
if ( V_8 && V_30 ) {
F_10 ( V_5 , 0 , V_31 ) ;
F_10 ( V_5 , 1 , V_31 ) ;
V_8 -> V_32 = V_33 | V_34 | V_35
| V_36 ;
V_8 -> V_37 = 1 ;
}
}
static int F_11 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
struct V_42 * V_43 ;
if ( ! V_30 )
return V_44 ;
V_43 = V_30 -> V_43 ;
V_43 -> V_45 = 0 ;
return V_46 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_23 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_47 )
return;
if ( V_9 -> V_43 ) {
V_9 -> V_43 -> V_45 = 0 ;
V_9 -> V_43 -> V_48 = 1 ;
V_30 = V_9 ;
F_13 ( & V_49 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_23 * V_9 = & V_5 -> V_9 ;
if ( ! V_9 -> V_47 )
return;
if ( V_9 -> V_43 ) {
V_9 -> V_43 -> V_48 = 0 ;
V_30 = NULL ;
F_15 ( & V_49 ) ;
}
F_16 ( & V_9 -> V_24 ) ;
F_17 ( V_9 -> V_47 ) ;
V_9 -> V_47 = NULL ;
V_9 -> V_43 = NULL ;
V_9 -> V_50 = NULL ;
V_9 -> V_8 = NULL ;
V_9 -> V_51 = NULL ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_23 * V_9 = & V_5 -> V_9 ;
T_1 V_52 , V_53 ;
void T_2 * V_54 ;
int V_55 = 0 ;
F_19 ( V_2 -> V_56 , V_57 , & V_52 ) ;
if ( V_52 == 0 ) {
F_2 ( L_3 ) ;
return - V_58 ;
}
F_20 ( & V_9 -> V_24 , F_5 ) ;
F_21 ( L_4 , V_52 ) ;
V_54 = F_22 ( V_52 , 8 * 1024 ) ;
if ( ! V_54 )
return - V_59 ;
if ( memcmp ( V_54 , V_60 , 16 ) ) {
F_2 ( L_5 ) ;
V_55 = - V_61 ;
goto V_62;
}
V_9 -> V_47 = V_54 ;
V_9 -> V_51 = V_54 + V_63 ;
V_9 -> V_64 = V_54 + V_65 ;
V_53 = V_9 -> V_47 -> V_53 ;
if ( V_53 & V_66 ) {
F_2 ( L_6 ) ;
V_9 -> V_43 = V_54 + V_67 ;
}
if ( V_53 & V_68 ) {
F_2 ( L_7 ) ;
V_9 -> V_8 = V_54 + V_69 ;
}
return 0 ;
V_62:
F_17 ( V_54 ) ;
return V_55 ;
}
