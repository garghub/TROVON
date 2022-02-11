int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( V_6 && ! F_2 ( V_5 ) && V_5 -> V_3 == NULL ) {
const struct V_7 * V_8 ;
V_8 = F_3 ( V_9 [ F_4 ( V_5 ) -> V_10 ] ) ;
if ( V_8 && V_8 -> V_11 )
V_8 -> V_11 ( V_5 ) ;
}
if ( ! F_5 ( V_5 ) )
F_6 ( V_5 ) ;
return F_7 ( V_5 ) ;
}
int F_8 ( struct V_4 * V_5 , struct V_12 * V_13 , struct V_14 * V_15 , struct V_12 * V_16 )
{
const struct V_17 * V_18 ;
T_1 V_19 ;
struct V_20 * V_21 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_13 ) ;
if ( V_5 -> V_22 == V_23 ) {
F_10 ( V_5 ) ;
return V_24 ;
}
F_11 () ;
V_21 = F_12 ( V_5 -> V_13 ) ;
F_13 ( V_1 , V_21 , V_25 , V_5 -> V_26 ) ;
if ( ( V_5 = F_14 ( V_5 , V_27 ) ) == NULL ||
! V_21 || F_15 ( V_21 -> V_28 . V_29 ) ) {
F_16 ( V_1 , V_21 , V_30 ) ;
goto V_31;
}
memset ( F_17 ( V_5 ) , 0 , sizeof( struct V_32 ) ) ;
F_17 ( V_5 ) -> V_33 = F_5 ( V_5 ) ? F_18 ( F_2 ( V_5 ) ) -> V_13 -> V_34 : V_13 -> V_34 ;
if ( F_15 ( ! F_19 ( V_5 , sizeof( * V_18 ) ) ) )
goto V_35;
V_18 = F_4 ( V_5 ) ;
if ( V_18 -> V_36 != 6 )
goto V_35;
F_20 ( V_1 , V_21 ,
V_37 +
( F_21 ( V_18 ) & V_38 ) ,
F_22 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ! ( V_13 -> V_39 & V_40 ) &&
F_23 ( & V_18 -> V_41 ) )
goto V_35;
if ( ! ( V_5 -> V_22 == V_42 ||
V_13 -> V_39 & V_40 ) &&
F_24 ( & V_18 -> V_41 ) &&
F_25 ( & V_18 -> V_41 ) == 1 )
goto V_35;
if ( F_24 ( & V_18 -> V_41 ) &&
F_25 ( & V_18 -> V_41 ) == 0 )
goto V_35;
if ( F_24 ( & V_18 -> V_43 ) )
goto V_35;
V_5 -> V_44 = V_5 -> V_45 + sizeof( * V_18 ) ;
F_17 ( V_5 ) -> V_46 = F_26 ( struct V_17 , V_10 ) ;
V_19 = F_27 ( V_18 -> V_47 ) ;
if ( V_19 || V_18 -> V_10 != V_48 ) {
if ( V_19 + sizeof( struct V_17 ) > V_5 -> V_26 ) {
F_16 ( V_1 ,
V_21 , V_49 ) ;
goto V_31;
}
if ( F_28 ( V_5 , V_19 + sizeof( struct V_17 ) ) ) {
F_16 ( V_1 , V_21 , V_50 ) ;
goto V_31;
}
V_18 = F_4 ( V_5 ) ;
}
if ( V_18 -> V_10 == V_48 ) {
if ( F_29 ( V_5 ) < 0 ) {
F_16 ( V_1 , V_21 , V_50 ) ;
F_30 () ;
return V_24 ;
}
}
F_30 () ;
F_31 ( V_5 ) ;
return F_32 ( V_51 , V_52 ,
V_1 , NULL , V_5 , V_13 , NULL ,
F_1 ) ;
V_35:
F_16 ( V_1 , V_21 , V_50 ) ;
V_31:
F_30 () ;
F_10 ( V_5 ) ;
return V_24 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_7 * V_8 ;
struct V_20 * V_21 ;
unsigned int V_46 ;
int V_10 ;
bool V_53 ;
F_11 () ;
V_54:
V_21 = F_18 ( F_2 ( V_5 ) ) ;
if ( ! F_34 ( V_5 , F_35 ( V_5 ) ) )
goto V_55;
V_46 = F_17 ( V_5 ) -> V_46 ;
V_10 = F_36 ( V_5 ) [ V_46 ] ;
V_53 = F_37 ( V_5 , V_10 ) ;
V_8 = F_3 ( V_9 [ V_10 ] ) ;
if ( V_8 ) {
int V_56 ;
if ( V_8 -> V_39 & V_57 ) {
const struct V_17 * V_18 ;
F_38 ( V_5 ) ;
F_39 ( V_5 , F_36 ( V_5 ) ,
F_40 ( V_5 ) ) ;
V_18 = F_4 ( V_5 ) ;
if ( F_24 ( & V_18 -> V_41 ) &&
! F_41 ( V_5 -> V_13 , & V_18 -> V_41 ,
& V_18 -> V_43 ) &&
! F_42 ( V_5 , V_10 , F_40 ( V_5 ) ) )
goto V_55;
}
if ( ! ( V_8 -> V_39 & V_58 ) &&
! F_43 ( NULL , V_59 , V_5 ) )
goto V_55;
V_56 = V_8 -> V_60 ( V_5 ) ;
if ( V_56 > 0 )
goto V_54;
else if ( V_56 == 0 )
F_16 ( V_1 , V_21 , V_61 ) ;
} else {
if ( ! V_53 ) {
if ( F_43 ( NULL , V_59 , V_5 ) ) {
F_16 ( V_1 , V_21 ,
V_62 ) ;
F_44 ( V_5 , V_63 ,
V_64 , V_46 ) ;
}
F_10 ( V_5 ) ;
} else {
F_16 ( V_1 , V_21 , V_61 ) ;
F_45 ( V_5 ) ;
}
}
F_30 () ;
return 0 ;
V_55:
F_16 ( V_1 , V_21 , V_30 ) ;
F_30 () ;
F_10 ( V_5 ) ;
return 0 ;
}
int F_46 ( struct V_4 * V_5 )
{
return F_32 ( V_51 , V_65 ,
F_9 ( V_5 -> V_13 ) , NULL , V_5 , V_5 -> V_13 , NULL ,
F_33 ) ;
}
int F_47 ( struct V_4 * V_5 )
{
const struct V_17 * V_18 ;
bool V_66 ;
F_13 ( F_9 ( F_2 ( V_5 ) -> V_13 ) ,
F_18 ( F_2 ( V_5 ) ) , V_67 ,
V_5 -> V_26 ) ;
V_18 = F_4 ( V_5 ) ;
V_66 = F_41 ( V_5 -> V_13 , & V_18 -> V_41 , NULL ) ;
#ifdef F_48
if ( F_9 ( V_5 -> V_13 ) -> V_68 . V_69 -> V_70 &&
! ( F_49 ( & V_18 -> V_41 ) &
( V_71 | V_72 ) ) &&
F_50 ( ! ( F_17 ( V_5 ) -> V_39 & V_73 ) ) ) {
struct V_4 * V_74 ;
struct V_32 * V_75 = F_17 ( V_5 ) ;
if ( F_15 ( V_75 -> V_39 & V_76 ) ) {
T_2 V_10 = V_18 -> V_10 ;
T_3 V_77 ;
int V_78 ;
if ( V_75 -> V_79 == F_51 ( V_80 ) ) {
V_66 = false ;
if ( ! F_52 ( V_10 ) ) {
goto V_81;
}
V_78 = F_53 ( V_5 , sizeof( * V_18 ) ,
& V_10 , & V_77 ) ;
if ( V_78 < 0 )
goto V_81;
if ( F_42 ( V_5 , V_10 , V_78 ) )
V_66 = true ;
goto V_81;
}
}
if ( V_66 )
V_74 = F_54 ( V_5 , V_27 ) ;
else {
V_74 = V_5 ;
V_5 = NULL ;
}
if ( V_74 ) {
F_55 ( V_74 ) ;
}
}
V_81:
#endif
if ( F_50 ( V_66 ) )
F_46 ( V_5 ) ;
else {
F_10 ( V_5 ) ;
}
return 0 ;
}
