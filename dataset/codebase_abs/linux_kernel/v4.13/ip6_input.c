int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
void (* F_2)( struct V_4 * V_5 );
V_5 = F_3 ( V_5 ) ;
if ( ! V_5 )
return V_6 ;
if ( V_1 -> V_7 . V_8 && ! F_4 ( V_5 ) && V_5 -> V_3 == NULL ) {
const struct V_9 * V_10 ;
V_10 = F_5 ( V_11 [ F_6 ( V_5 ) -> V_12 ] ) ;
if ( V_10 && ( F_2 = F_7 ( V_10 -> V_13 ) ) )
F_2 ( V_5 ) ;
}
if ( ! F_8 ( V_5 ) )
F_9 ( V_5 ) ;
return F_10 ( V_5 ) ;
}
int F_11 ( struct V_4 * V_5 , struct V_14 * V_15 , struct V_16 * V_17 , struct V_14 * V_18 )
{
const struct V_19 * V_20 ;
T_1 V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_1 = F_12 ( V_5 -> V_15 ) ;
if ( V_5 -> V_24 == V_25 ) {
F_13 ( V_5 ) ;
return V_26 ;
}
F_14 () ;
V_23 = F_15 ( V_5 -> V_15 ) ;
F_16 ( V_1 , V_23 , V_27 , V_5 -> V_28 ) ;
if ( ( V_5 = F_17 ( V_5 , V_29 ) ) == NULL ||
! V_23 || F_18 ( V_23 -> V_30 . V_31 ) ) {
F_19 ( V_1 , V_23 , V_32 ) ;
goto V_33;
}
memset ( F_20 ( V_5 ) , 0 , sizeof( struct V_34 ) ) ;
F_20 ( V_5 ) -> V_35 = F_8 ( V_5 ) ? F_21 ( F_4 ( V_5 ) ) -> V_15 -> V_36 : V_15 -> V_36 ;
if ( F_18 ( ! F_22 ( V_5 , sizeof( * V_20 ) ) ) )
goto V_37;
V_20 = F_6 ( V_5 ) ;
if ( V_20 -> V_38 != 6 )
goto V_37;
F_23 ( V_1 , V_23 ,
V_39 +
( F_24 ( V_20 ) & V_40 ) ,
F_25 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ( F_26 ( & V_20 -> V_41 ) ||
F_26 ( & V_20 -> V_42 ) ) &&
! ( V_15 -> V_43 & V_44 ) )
goto V_37;
if ( ! ( V_5 -> V_24 == V_45 ||
V_15 -> V_43 & V_44 ) &&
F_27 ( & V_20 -> V_42 ) &&
F_28 ( & V_20 -> V_42 ) == 1 )
goto V_37;
if ( ! F_27 ( & V_20 -> V_42 ) &&
( V_5 -> V_24 == V_46 ||
V_5 -> V_24 == V_47 ) &&
V_23 -> V_30 . V_48 )
goto V_37;
if ( F_27 ( & V_20 -> V_42 ) &&
F_28 ( & V_20 -> V_42 ) == 0 )
goto V_37;
if ( F_27 ( & V_20 -> V_41 ) )
goto V_37;
V_5 -> V_49 = V_5 -> V_50 + sizeof( * V_20 ) ;
F_20 ( V_5 ) -> V_51 = F_29 ( struct V_19 , V_12 ) ;
V_21 = F_30 ( V_20 -> V_52 ) ;
if ( V_21 || V_20 -> V_12 != V_53 ) {
if ( V_21 + sizeof( struct V_19 ) > V_5 -> V_28 ) {
F_19 ( V_1 ,
V_23 , V_54 ) ;
goto V_33;
}
if ( F_31 ( V_5 , V_21 + sizeof( struct V_19 ) ) ) {
F_19 ( V_1 , V_23 , V_55 ) ;
goto V_33;
}
V_20 = F_6 ( V_5 ) ;
}
if ( V_20 -> V_12 == V_53 ) {
if ( F_32 ( V_5 ) < 0 ) {
F_19 ( V_1 , V_23 , V_55 ) ;
F_33 () ;
return V_26 ;
}
}
F_33 () ;
F_34 ( V_5 ) ;
return F_35 ( V_56 , V_57 ,
V_1 , NULL , V_5 , V_15 , NULL ,
F_1 ) ;
V_37:
F_19 ( V_1 , V_23 , V_55 ) ;
V_33:
F_33 () ;
F_13 ( V_5 ) ;
return V_26 ;
}
static int F_36 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_9 * V_10 ;
struct V_22 * V_23 ;
unsigned int V_51 ;
int V_12 ;
bool V_58 ;
bool V_59 = false ;
F_14 () ;
V_60:
V_23 = F_21 ( F_4 ( V_5 ) ) ;
if ( ! F_37 ( V_5 , F_38 ( V_5 ) ) )
goto V_61;
V_51 = F_20 ( V_5 ) -> V_51 ;
V_12 = F_39 ( V_5 ) [ V_51 ] ;
V_62:
V_58 = F_40 ( V_5 , V_12 ) ;
V_10 = F_5 ( V_11 [ V_12 ] ) ;
if ( V_10 ) {
int V_63 ;
if ( V_59 ) {
if ( ! ( V_10 -> V_43 & V_64 ) ) {
goto V_61;
}
} else if ( V_10 -> V_43 & V_64 ) {
const struct V_19 * V_20 ;
V_59 = true ;
F_41 ( V_5 ) ;
F_42 ( V_5 , F_39 ( V_5 ) ,
F_43 ( V_5 ) ) ;
V_20 = F_6 ( V_5 ) ;
if ( F_27 ( & V_20 -> V_42 ) &&
! F_44 ( V_5 -> V_15 , & V_20 -> V_42 ,
& V_20 -> V_41 ) &&
! F_45 ( V_5 , V_12 , F_43 ( V_5 ) ) )
goto V_61;
}
if ( ! ( V_10 -> V_43 & V_65 ) &&
! F_46 ( NULL , V_66 , V_5 ) )
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
F_19 ( V_1 , V_23 , V_68 ) ;
}
} else {
if ( ! V_58 ) {
if ( F_46 ( NULL , V_66 , V_5 ) ) {
F_19 ( V_1 , V_23 ,
V_69 ) ;
F_47 ( V_5 , V_70 ,
V_71 , V_51 ) ;
}
F_13 ( V_5 ) ;
} else {
F_19 ( V_1 , V_23 , V_68 ) ;
F_48 ( V_5 ) ;
}
}
F_33 () ;
return 0 ;
V_61:
F_19 ( V_1 , V_23 , V_32 ) ;
F_33 () ;
F_13 ( V_5 ) ;
return 0 ;
}
int F_49 ( struct V_4 * V_5 )
{
return F_35 ( V_56 , V_72 ,
F_12 ( V_5 -> V_15 ) , NULL , V_5 , V_5 -> V_15 , NULL ,
F_36 ) ;
}
int F_50 ( struct V_4 * V_5 )
{
const struct V_19 * V_20 ;
bool V_73 ;
F_16 ( F_12 ( F_4 ( V_5 ) -> V_15 ) ,
F_21 ( F_4 ( V_5 ) ) , V_74 ,
V_5 -> V_28 ) ;
V_20 = F_6 ( V_5 ) ;
V_73 = F_44 ( V_5 -> V_15 , & V_20 -> V_42 , NULL ) ;
#ifdef F_51
if ( F_12 ( V_5 -> V_15 ) -> V_75 . V_76 -> V_77 &&
! ( F_52 ( & V_20 -> V_42 ) &
( V_78 | V_79 ) ) &&
F_53 ( ! ( F_20 ( V_5 ) -> V_43 & V_80 ) ) ) {
struct V_4 * V_81 ;
struct V_34 * V_82 = F_20 ( V_5 ) ;
if ( F_18 ( V_82 -> V_43 & V_83 ) ) {
T_2 V_12 = V_20 -> V_12 ;
T_3 V_84 ;
int V_85 ;
if ( V_82 -> V_86 == F_54 ( V_87 ) ) {
V_73 = false ;
if ( ! F_55 ( V_12 ) ) {
goto V_88;
}
V_85 = F_56 ( V_5 , sizeof( * V_20 ) ,
& V_12 , & V_84 ) ;
if ( V_85 < 0 )
goto V_88;
if ( F_45 ( V_5 , V_12 , V_85 ) )
V_73 = true ;
goto V_88;
}
}
if ( V_73 )
V_81 = F_57 ( V_5 , V_29 ) ;
else {
V_81 = V_5 ;
V_5 = NULL ;
}
if ( V_81 ) {
F_58 ( V_81 ) ;
}
}
V_88:
#endif
if ( F_53 ( V_73 ) )
F_49 ( V_5 ) ;
else {
F_13 ( V_5 ) ;
}
return 0 ;
}
