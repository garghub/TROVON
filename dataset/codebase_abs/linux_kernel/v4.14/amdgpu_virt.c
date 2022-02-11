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
int F_3 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_13 * * V_14 )
{
struct V_15 V_16 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
int V_3 ;
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
* V_14 = F_9 ( V_2 , V_12 , V_2 -> V_8 . V_9 ) ;
if ( ! * V_14 ) {
F_10 ( & V_16 , & V_18 ) ;
F_8 ( L_2 ) ;
return - V_27 ;
}
V_3 = F_11 ( V_2 , ( * V_14 ) -> V_28 . V_12 , V_29 ,
V_5 ) ;
if ( V_3 ) {
F_8 ( L_3 , V_3 ) ;
F_12 ( V_2 , * V_14 ) ;
F_10 ( & V_16 , & V_18 ) ;
return V_3 ;
}
V_3 = F_13 ( V_2 , * V_14 , V_29 , 0 , V_5 ,
V_30 | V_31 |
V_32 ) ;
if ( V_3 ) {
F_8 ( L_4 , V_3 ) ;
F_12 ( V_2 , * V_14 ) ;
F_10 ( & V_16 , & V_18 ) ;
return V_3 ;
}
F_10 ( & V_16 , & V_18 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_33 . V_34 = 1 ;
V_2 -> V_35 = true ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
F_15 ( & V_2 -> V_8 . V_38 ) ;
}
T_1 F_16 ( struct V_1 * V_2 , T_1 V_39 )
{
signed long V_3 ;
T_1 V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 = & V_2 -> V_45 . V_44 ;
struct V_46 * V_47 = & V_44 -> V_47 ;
F_17 ( ! V_47 -> V_48 -> V_49 ) ;
F_18 ( & V_44 -> V_50 ) ;
F_19 ( V_47 , 32 ) ;
F_20 ( V_47 , V_39 ) ;
F_21 ( V_47 , & V_42 ) ;
F_22 ( V_47 ) ;
F_23 ( & V_44 -> V_50 ) ;
V_3 = F_24 ( V_42 , false , F_25 ( V_51 ) ) ;
F_26 ( V_42 ) ;
if ( V_3 < 1 ) {
F_8 ( L_5 , V_3 ) ;
return ~ 0 ;
}
V_40 = V_2 -> V_52 . V_52 [ V_2 -> V_8 . V_53 ] ;
return V_40 ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_54 )
{
signed long V_3 ;
struct V_41 * V_42 ;
struct V_43 * V_44 = & V_2 -> V_45 . V_44 ;
struct V_46 * V_47 = & V_44 -> V_47 ;
F_17 ( ! V_47 -> V_48 -> V_55 ) ;
F_18 ( & V_44 -> V_50 ) ;
F_19 ( V_47 , 32 ) ;
F_28 ( V_47 , V_39 , V_54 ) ;
F_21 ( V_47 , & V_42 ) ;
F_22 ( V_47 ) ;
F_23 ( & V_44 -> V_50 ) ;
V_3 = F_24 ( V_42 , false , F_25 ( V_51 ) ) ;
if ( V_3 < 1 )
F_8 ( L_5 , V_3 ) ;
F_26 ( V_42 ) ;
}
int F_29 ( struct V_1 * V_2 , bool V_56 )
{
struct V_57 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_58 && V_8 -> V_58 -> V_59 ) {
V_3 = V_8 -> V_58 -> V_59 ( V_2 , V_56 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_60 &= ~ V_61 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 , bool V_56 )
{
struct V_57 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_58 && V_8 -> V_58 -> V_62 ) {
V_3 = V_8 -> V_58 -> V_62 ( V_2 , V_56 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_60 |= V_61 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_57 * V_8 = & V_2 -> V_8 ;
int V_3 ;
if ( V_8 -> V_58 && V_8 -> V_58 -> V_63 ) {
V_3 = V_8 -> V_58 -> V_63 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_8 . V_60 &= ~ V_61 ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! F_33 ( V_2 ) || V_2 -> V_8 . V_64 . V_65 )
return 0 ;
V_3 = F_2 ( V_2 , V_6 , V_6 ,
V_7 ,
& V_2 -> V_8 . V_64 . V_24 ,
& V_2 -> V_8 . V_64 . V_65 ,
( void * ) & V_2 -> V_8 . V_64 . V_66 ) ;
if ( V_3 ) {
F_8 ( L_6 , V_3 ) ;
return V_3 ;
}
memset ( ( void * ) V_2 -> V_8 . V_64 . V_66 , 0 , V_6 ) ;
F_34 ( L_7 ,
V_2 -> V_8 . V_64 . V_65 ,
V_2 -> V_8 . V_64 . V_66 ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( ! F_33 ( V_2 ) || ! V_2 -> V_8 . V_64 . V_65 )
return;
F_36 ( & V_2 -> V_8 . V_64 . V_24 ,
& V_2 -> V_8 . V_64 . V_65 ,
( void * ) & V_2 -> V_8 . V_64 . V_66 ) ;
V_2 -> V_8 . V_64 . V_65 = 0 ;
}
