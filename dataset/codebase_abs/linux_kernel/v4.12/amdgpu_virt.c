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
V_3 = F_11 ( V_2 , V_14 -> V_12 , V_28 ,
V_5 ) ;
if ( V_3 ) {
F_8 ( L_3 , V_3 ) ;
F_12 ( V_2 , V_14 ) ;
F_10 ( & V_16 , & V_18 ) ;
return V_3 ;
}
V_3 = F_13 ( V_2 , V_14 , V_28 , 0 , V_5 ,
V_29 | V_30 |
V_31 ) ;
if ( V_3 ) {
F_8 ( L_4 , V_3 ) ;
F_12 ( V_2 , V_14 ) ;
F_10 ( & V_16 , & V_18 ) ;
return V_3 ;
}
V_12 -> V_32 = V_14 ;
F_10 ( & V_16 , & V_18 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_33 . V_34 = 1 ;
V_2 -> V_35 = true ;
F_15 ( & V_2 -> V_8 . V_36 ) ;
F_15 ( & V_2 -> V_8 . V_37 ) ;
}
T_1 F_16 ( struct V_1 * V_2 , T_1 V_38 )
{
signed long V_3 ;
T_1 V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 = & V_2 -> V_44 . V_43 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
F_17 ( ! V_46 -> V_47 -> V_48 ) ;
F_18 ( & V_2 -> V_8 . V_36 ) ;
F_19 ( V_46 , 32 ) ;
F_20 ( V_46 , V_38 ) ;
F_21 ( V_46 , & V_41 ) ;
F_22 ( V_46 ) ;
F_23 ( & V_2 -> V_8 . V_36 ) ;
V_3 = F_24 ( V_41 , false ) ;
if ( V_3 )
F_8 ( L_5 , V_3 ) ;
F_25 ( V_41 ) ;
V_39 = V_2 -> V_49 . V_49 [ V_2 -> V_8 . V_50 ] ;
return V_39 ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_38 , T_1 V_51 )
{
signed long V_3 ;
struct V_40 * V_41 ;
struct V_42 * V_43 = & V_2 -> V_44 . V_43 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
F_17 ( ! V_46 -> V_47 -> V_52 ) ;
F_18 ( & V_2 -> V_8 . V_36 ) ;
F_19 ( V_46 , 32 ) ;
F_27 ( V_46 , V_38 , V_51 ) ;
F_21 ( V_46 , & V_41 ) ;
F_22 ( V_46 ) ;
F_23 ( & V_2 -> V_8 . V_36 ) ;
V_3 = F_24 ( V_41 , false ) ;
if ( V_3 )
F_8 ( L_5 , V_3 ) ;
F_25 ( V_41 ) ;
}
int F_28 ( struct V_1 * V_2 , bool V_53 )
{
struct V_54 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_55 && V_8 -> V_55 -> V_56 ) {
V_3 = V_8 -> V_55 -> V_56 ( V_2 , V_53 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_57 &= ~ V_58 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 , bool V_53 )
{
struct V_54 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_55 && V_8 -> V_55 -> V_59 ) {
V_3 = V_8 -> V_55 -> V_59 ( V_2 , V_53 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_57 |= V_58 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_54 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_55 && V_8 -> V_55 -> V_60 ) {
V_3 = V_8 -> V_55 -> V_60 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_57 &= ~ V_58 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! F_32 ( V_2 ) || V_2 -> V_8 . V_61 . V_62 )
return 0 ;
V_3 = F_2 ( V_2 , V_6 , V_6 ,
V_7 ,
& V_2 -> V_8 . V_61 . V_24 ,
& V_2 -> V_8 . V_61 . V_62 ,
( void * ) & V_2 -> V_8 . V_61 . V_63 ) ;
if ( V_3 ) {
F_8 ( L_6 , V_3 ) ;
return V_3 ;
}
memset ( ( void * ) V_2 -> V_8 . V_61 . V_63 , 0 , V_6 ) ;
F_33 ( L_7 ,
V_2 -> V_8 . V_61 . V_62 ,
V_2 -> V_8 . V_61 . V_63 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( ! F_32 ( V_2 ) || ! V_2 -> V_8 . V_61 . V_62 )
return;
F_35 ( & V_2 -> V_8 . V_61 . V_24 ,
& V_2 -> V_8 . V_61 . V_62 ,
( void * ) & V_2 -> V_8 . V_61 . V_63 ) ;
V_2 -> V_8 . V_61 . V_62 = 0 ;
}
