int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
V_5 = F_2 ( V_5 ) ;
if ( ! V_5 )
return V_6 ;
if ( V_1 -> V_7 . V_8 && ! F_3 ( V_5 ) && V_5 -> V_3 == NULL ) {
const struct V_9 * V_10 ;
V_10 = F_4 ( V_11 [ F_5 ( V_5 ) -> V_12 ] ) ;
if ( V_10 && V_10 -> V_13 )
V_10 -> V_13 ( V_5 ) ;
}
if ( ! F_6 ( V_5 ) )
F_7 ( V_5 ) ;
return F_8 ( V_5 ) ;
}
int F_9 ( struct V_4 * V_5 , struct V_14 * V_15 , struct V_16 * V_17 , struct V_14 * V_18 )
{
const struct V_19 * V_20 ;
T_1 V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_1 = F_10 ( V_5 -> V_15 ) ;
if ( V_5 -> V_24 == V_25 ) {
F_11 ( V_5 ) ;
return V_26 ;
}
F_12 () ;
V_23 = F_13 ( V_5 -> V_15 ) ;
F_14 ( V_1 , V_23 , V_27 , V_5 -> V_28 ) ;
if ( ( V_5 = F_15 ( V_5 , V_29 ) ) == NULL ||
! V_23 || F_16 ( V_23 -> V_30 . V_31 ) ) {
F_17 ( V_1 , V_23 , V_32 ) ;
goto V_33;
}
memset ( F_18 ( V_5 ) , 0 , sizeof( struct V_34 ) ) ;
F_18 ( V_5 ) -> V_35 = F_6 ( V_5 ) ? F_19 ( F_3 ( V_5 ) ) -> V_15 -> V_36 : V_15 -> V_36 ;
if ( F_16 ( ! F_20 ( V_5 , sizeof( * V_20 ) ) ) )
goto V_37;
V_20 = F_5 ( V_5 ) ;
if ( V_20 -> V_38 != 6 )
goto V_37;
F_21 ( V_1 , V_23 ,
V_39 +
( F_22 ( V_20 ) & V_40 ) ,
F_23 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ( F_24 ( & V_20 -> V_41 ) ||
F_24 ( & V_20 -> V_42 ) ) &&
! ( V_15 -> V_43 & V_44 ) )
goto V_37;
if ( ! ( V_5 -> V_24 == V_45 ||
V_15 -> V_43 & V_44 ) &&
F_25 ( & V_20 -> V_42 ) &&
F_26 ( & V_20 -> V_42 ) == 1 )
goto V_37;
if ( ! F_25 ( & V_20 -> V_42 ) &&
( V_5 -> V_24 == V_46 ||
V_5 -> V_24 == V_47 ) &&
V_23 -> V_30 . V_48 )
goto V_37;
if ( F_25 ( & V_20 -> V_42 ) &&
F_26 ( & V_20 -> V_42 ) == 0 )
goto V_37;
if ( F_25 ( & V_20 -> V_41 ) )
goto V_37;
V_5 -> V_49 = V_5 -> V_50 + sizeof( * V_20 ) ;
F_18 ( V_5 ) -> V_51 = F_27 ( struct V_19 , V_12 ) ;
V_21 = F_28 ( V_20 -> V_52 ) ;
if ( V_21 || V_20 -> V_12 != V_53 ) {
if ( V_21 + sizeof( struct V_19 ) > V_5 -> V_28 ) {
F_17 ( V_1 ,
V_23 , V_54 ) ;
goto V_33;
}
if ( F_29 ( V_5 , V_21 + sizeof( struct V_19 ) ) ) {
F_17 ( V_1 , V_23 , V_55 ) ;
goto V_33;
}
V_20 = F_5 ( V_5 ) ;
}
if ( V_20 -> V_12 == V_53 ) {
if ( F_30 ( V_5 ) < 0 ) {
F_17 ( V_1 , V_23 , V_55 ) ;
F_31 () ;
return V_26 ;
}
}
F_31 () ;
F_32 ( V_5 ) ;
return F_33 ( V_56 , V_57 ,
V_1 , NULL , V_5 , V_15 , NULL ,
F_1 ) ;
V_37:
F_17 ( V_1 , V_23 , V_55 ) ;
V_33:
F_31 () ;
F_11 ( V_5 ) ;
return V_26 ;
}
static int F_34 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_9 * V_10 ;
struct V_22 * V_23 ;
unsigned int V_51 ;
int V_12 ;
bool V_58 ;
bool V_59 = false ;
F_12 () ;
V_60:
V_23 = F_19 ( F_3 ( V_5 ) ) ;
if ( ! F_35 ( V_5 , F_36 ( V_5 ) ) )
goto V_61;
V_51 = F_18 ( V_5 ) -> V_51 ;
V_12 = F_37 ( V_5 ) [ V_51 ] ;
V_62:
V_58 = F_38 ( V_5 , V_12 ) ;
V_10 = F_4 ( V_11 [ V_12 ] ) ;
if ( V_10 ) {
int V_63 ;
if ( V_59 ) {
if ( ! ( V_10 -> V_43 & V_64 ) ) {
goto V_61;
}
} else if ( V_10 -> V_43 & V_64 ) {
const struct V_19 * V_20 ;
V_59 = true ;
F_39 ( V_5 ) ;
F_40 ( V_5 , F_37 ( V_5 ) ,
F_41 ( V_5 ) ) ;
V_20 = F_5 ( V_5 ) ;
if ( F_25 ( & V_20 -> V_42 ) &&
! F_42 ( V_5 -> V_15 , & V_20 -> V_42 ,
& V_20 -> V_41 ) &&
! F_43 ( V_5 , V_12 , F_41 ( V_5 ) ) )
goto V_61;
}
if ( ! ( V_10 -> V_43 & V_65 ) &&
! F_44 ( NULL , V_66 , V_5 ) )
goto V_61;
V_63 = V_10 -> V_67 ( V_5 ) ;
if ( V_63 > 0 ) {
if ( V_10 -> V_43 & V_64 ) {
V_12 = V_63 ;
goto V_62;
} else {
goto V_60;
}
} else if ( V_63 == 0 ) {
F_17 ( V_1 , V_23 , V_68 ) ;
}
} else {
if ( ! V_58 ) {
if ( F_44 ( NULL , V_66 , V_5 ) ) {
F_17 ( V_1 , V_23 ,
V_69 ) ;
F_45 ( V_5 , V_70 ,
V_71 , V_51 ) ;
}
F_11 ( V_5 ) ;
} else {
F_17 ( V_1 , V_23 , V_68 ) ;
F_46 ( V_5 ) ;
}
}
F_31 () ;
return 0 ;
V_61:
F_17 ( V_1 , V_23 , V_32 ) ;
F_31 () ;
F_11 ( V_5 ) ;
return 0 ;
}
int F_47 ( struct V_4 * V_5 )
{
return F_33 ( V_56 , V_72 ,
F_10 ( V_5 -> V_15 ) , NULL , V_5 , V_5 -> V_15 , NULL ,
F_34 ) ;
}
int F_48 ( struct V_4 * V_5 )
{
const struct V_19 * V_20 ;
bool V_73 ;
F_14 ( F_10 ( F_3 ( V_5 ) -> V_15 ) ,
F_19 ( F_3 ( V_5 ) ) , V_74 ,
V_5 -> V_28 ) ;
V_20 = F_5 ( V_5 ) ;
V_73 = F_42 ( V_5 -> V_15 , & V_20 -> V_42 , NULL ) ;
#ifdef F_49
if ( F_10 ( V_5 -> V_15 ) -> V_75 . V_76 -> V_77 &&
! ( F_50 ( & V_20 -> V_42 ) &
( V_78 | V_79 ) ) &&
F_51 ( ! ( F_18 ( V_5 ) -> V_43 & V_80 ) ) ) {
struct V_4 * V_81 ;
struct V_34 * V_82 = F_18 ( V_5 ) ;
if ( F_16 ( V_82 -> V_43 & V_83 ) ) {
T_2 V_12 = V_20 -> V_12 ;
T_3 V_84 ;
int V_85 ;
if ( V_82 -> V_86 == F_52 ( V_87 ) ) {
V_73 = false ;
if ( ! F_53 ( V_12 ) ) {
goto V_88;
}
V_85 = F_54 ( V_5 , sizeof( * V_20 ) ,
& V_12 , & V_84 ) ;
if ( V_85 < 0 )
goto V_88;
if ( F_43 ( V_5 , V_12 , V_85 ) )
V_73 = true ;
goto V_88;
}
}
if ( V_73 )
V_81 = F_55 ( V_5 , V_29 ) ;
else {
V_81 = V_5 ;
V_5 = NULL ;
}
if ( V_81 ) {
F_56 ( V_81 ) ;
}
}
V_88:
#endif
if ( F_51 ( V_73 ) )
F_47 ( V_5 ) ;
else {
F_11 ( V_5 ) ;
}
return 0 ;
}
