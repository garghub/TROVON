int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
struct V_4 * V_7 = NULL ;
struct V_8 V_9 ;
V_6 = F_2 ( V_1 , V_10 , V_11 , 0 , & V_7 ) ;
if ( V_6 < 0 )
goto error;
V_9 . V_12 = V_10 ;
V_9 . V_13 = V_3 -> V_14 ;
V_9 . V_15 = V_3 -> V_16 ;
V_6 = F_3 ( V_7 , (struct V_17 * ) & V_9 ,
sizeof( V_9 ) ) ;
if ( V_6 < 0 )
goto error;
if ( V_3 -> V_18 ) {
V_9 . V_12 = V_10 ;
V_9 . V_13 = V_3 -> V_19 ;
V_9 . V_15 = V_3 -> V_18 ;
V_6 = F_4 ( V_7 , (struct V_17 * ) & V_9 ,
sizeof( V_9 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
}
V_7 -> V_20 -> V_21 = ! V_3 -> V_22 ;
* V_5 = V_7 ;
return 0 ;
error:
if ( V_7 ) {
F_5 ( V_7 , V_23 ) ;
F_6 ( V_7 ) ;
}
* V_5 = NULL ;
return V_6 ;
}
void F_7 ( struct V_1 * V_1 , struct V_4 * V_7 ,
struct V_24 * V_3 )
{
struct V_7 * V_20 = V_7 -> V_20 ;
F_8 ( V_20 ) -> V_25 = 0 ;
F_9 ( V_20 ) ;
F_10 ( V_20 , V_3 -> V_26 ) ;
F_11 ( V_20 ) -> V_27 = V_3 -> V_27 ;
F_11 ( V_20 ) -> V_28 = V_3 -> V_28 ;
F_11 ( V_20 ) -> V_29 = V_3 -> V_29 ;
F_11 ( V_20 ) -> V_30 = V_3 -> V_30 ;
F_11 ( V_20 ) -> V_31 = V_3 -> V_31 ;
F_12 ( V_7 ) ;
}
void F_13 ( struct V_32 * V_33 , struct V_4 * V_7 ,
unsigned short type )
{
struct V_7 * V_20 = V_7 -> V_20 ;
struct V_34 V_35 ;
if ( ! V_33 -> V_36 -> V_37 ||
! ( V_33 -> V_38 & V_39 ) )
return;
V_35 . type = type ;
V_35 . V_40 = V_20 -> V_41 ;
V_35 . V_42 = F_8 ( V_20 ) -> V_43 ;
V_33 -> V_36 -> V_37 ( V_33 , & V_35 ) ;
}
void F_14 ( struct V_32 * V_33 , struct V_4 * V_7 ,
unsigned short type )
{
struct V_7 * V_20 = V_7 -> V_20 ;
struct V_34 V_35 ;
if ( ! V_33 -> V_36 -> V_44 ||
! ( V_33 -> V_38 & V_39 ) )
return;
V_35 . type = type ;
V_35 . V_40 = V_20 -> V_41 ;
V_35 . V_42 = F_8 ( V_20 ) -> V_43 ;
V_33 -> V_36 -> V_44 ( V_33 , & V_35 ) ;
}
void F_15 ( struct V_4 * V_7 , unsigned short type )
{
struct V_7 * V_20 = V_7 -> V_20 ;
struct V_1 * V_1 = F_16 ( V_20 ) ;
struct V_34 V_35 ;
struct V_32 * V_33 ;
V_35 . type = type ;
V_35 . V_40 = V_20 -> V_41 ;
V_35 . V_42 = F_8 ( V_20 ) -> V_43 ;
F_17 () ;
F_18 (net, dev) {
if ( ! V_33 -> V_36 -> V_37 )
continue;
if ( ! ( V_33 -> V_38 & V_39 ) )
continue;
V_33 -> V_36 -> V_37 ( V_33 , & V_35 ) ;
}
F_19 () ;
}
void F_20 ( struct V_4 * V_7 , unsigned short type )
{
struct V_7 * V_20 = V_7 -> V_20 ;
struct V_1 * V_1 = F_16 ( V_20 ) ;
struct V_34 V_35 ;
struct V_32 * V_33 ;
V_35 . type = type ;
V_35 . V_40 = V_20 -> V_41 ;
V_35 . V_42 = F_8 ( V_20 ) -> V_43 ;
F_17 () ;
F_18 (net, dev) {
if ( ! V_33 -> V_36 -> V_44 )
continue;
if ( ! ( V_33 -> V_38 & V_39 ) )
continue;
V_33 -> V_36 -> V_44 ( V_33 , & V_35 ) ;
}
F_19 () ;
}
void F_21 ( struct V_45 * V_46 , struct V_7 * V_20 , struct V_47 * V_48 ,
T_1 V_49 , T_1 V_50 , T_2 V_51 , T_2 V_52 ,
T_3 V_53 , T_3 V_54 , T_3 V_55 ,
bool V_56 , bool V_57 )
{
struct V_58 * V_59 ;
F_22 ( V_48 , sizeof( * V_59 ) ) ;
F_23 ( V_48 ) ;
V_59 = F_24 ( V_48 ) ;
V_59 -> V_60 = V_55 ;
V_59 -> V_61 = V_54 ;
V_59 -> V_62 = F_25 ( V_48 -> V_62 ) ;
memset ( & ( F_26 ( V_48 ) -> V_63 ) , 0 , sizeof( F_26 ( V_48 ) -> V_63 ) ) ;
F_27 ( V_57 , V_48 , V_49 , V_50 , V_48 -> V_62 ) ;
F_28 ( V_20 , V_46 , V_48 , V_49 , V_50 , V_64 , V_51 , V_52 , V_53 , V_56 ) ;
}
void F_29 ( struct V_4 * V_7 )
{
F_10 ( V_7 -> V_20 , NULL ) ;
F_5 ( V_7 , V_23 ) ;
F_6 ( V_7 ) ;
}
struct V_65 * F_30 ( struct V_47 * V_48 , unsigned short V_66 ,
T_3 V_67 , T_4 V_68 , int V_69 )
{
struct V_65 * V_70 ;
struct V_71 * V_72 ;
if ( V_66 == V_10 )
V_70 = F_31 ( V_48 , V_67 , V_68 , V_69 ) ;
else
V_70 = F_32 ( V_48 , V_67 , V_68 , V_69 ) ;
if ( ! V_70 )
return NULL ;
V_72 = & V_70 -> V_73 . V_74 ;
V_72 -> V_75 . V_76 = F_24 ( V_48 ) -> V_61 ;
V_72 -> V_75 . V_77 = F_24 ( V_48 ) -> V_60 ;
if ( F_24 ( V_48 ) -> V_78 )
V_72 -> V_75 . V_79 |= V_80 ;
return V_70 ;
}
