int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
void * V_4 ;
V_3 = F_2 ( V_2 , V_5 , V_6 ,
V_7 , & V_2 -> V_8 . V_9 ,
& V_2 -> V_8 . V_10 , & V_4 ) ;
if ( V_3 )
return V_3 ;
memset ( V_4 , 0 , V_5 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
int V_3 ;
struct V_13 * V_14 ;
struct V_15 V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
F_4 ( & V_18 ) ;
F_4 ( & V_22 . V_23 ) ;
V_22 . V_24 = & V_2 -> V_8 . V_9 -> V_25 ;
V_22 . V_26 = true ;
F_5 ( & V_22 . V_23 , & V_18 ) ;
F_6 ( V_12 , & V_18 , & V_20 ) ;
V_3 = F_7 ( & V_16 , & V_18 , true , NULL ) ;
if ( V_3 ) {
F_8 ( L_1 , V_3 ) ;
return V_3 ;
}
V_14 = F_9 ( V_2 , V_12 , V_2 -> V_8 . V_9 ) ;
if ( ! V_14 ) {
F_10 ( & V_16 , & V_18 ) ;
F_8 ( L_2 ) ;
return - V_27 ;
}
V_3 = F_11 ( V_2 , V_14 , V_28 , 0 , V_5 ,
V_29 | V_30 |
V_31 ) ;
if ( V_3 ) {
F_8 ( L_3 , V_3 ) ;
F_12 ( V_2 , V_14 ) ;
F_10 ( & V_16 , & V_18 ) ;
return V_3 ;
}
V_12 -> V_32 = V_14 ;
F_10 ( & V_16 , & V_18 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_33 . V_34 = 1 ;
V_2 -> V_35 = true ;
F_14 ( & V_2 -> V_8 . V_36 ) ;
}
T_1 F_15 ( struct V_1 * V_2 , T_1 V_37 )
{
signed long V_3 ;
T_1 V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = & V_2 -> V_43 . V_42 ;
struct V_44 * V_45 = & V_42 -> V_45 ;
F_16 ( ! V_45 -> V_46 -> V_47 ) ;
F_17 ( & V_2 -> V_8 . V_36 ) ;
F_18 ( V_45 , 32 ) ;
F_19 ( V_45 ) ;
F_20 ( V_45 , V_37 ) ;
F_21 ( V_45 ) ;
F_22 ( V_45 , & V_40 ) ;
F_23 ( V_45 ) ;
F_24 ( & V_2 -> V_8 . V_36 ) ;
V_3 = F_25 ( V_40 , false ) ;
if ( V_3 )
F_8 ( L_4 , V_3 ) ;
F_26 ( V_40 ) ;
V_38 = V_2 -> V_48 . V_48 [ V_2 -> V_8 . V_49 ] ;
return V_38 ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_37 , T_1 V_50 )
{
signed long V_3 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = & V_2 -> V_43 . V_42 ;
struct V_44 * V_45 = & V_42 -> V_45 ;
F_16 ( ! V_45 -> V_46 -> V_51 ) ;
F_17 ( & V_2 -> V_8 . V_36 ) ;
F_18 ( V_45 , 32 ) ;
F_19 ( V_45 ) ;
F_28 ( V_45 , V_37 , V_50 ) ;
F_21 ( V_45 ) ;
F_22 ( V_45 , & V_40 ) ;
F_23 ( V_45 ) ;
F_24 ( & V_2 -> V_8 . V_36 ) ;
V_3 = F_25 ( V_40 , false ) ;
if ( V_3 )
F_8 ( L_4 , V_3 ) ;
F_26 ( V_40 ) ;
}
int F_29 ( struct V_1 * V_2 , bool V_52 )
{
struct V_53 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_54 && V_8 -> V_54 -> V_55 ) {
V_3 = V_8 -> V_54 -> V_55 ( V_2 , V_52 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_56 &= ~ V_57 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 , bool V_52 )
{
struct V_53 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_54 && V_8 -> V_54 -> V_58 ) {
V_3 = V_8 -> V_54 -> V_58 ( V_2 , V_52 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_56 |= V_57 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_53 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_54 && V_8 -> V_54 -> V_59 ) {
V_3 = V_8 -> V_54 -> V_59 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_56 &= ~ V_57 ;
}
return 0 ;
}
