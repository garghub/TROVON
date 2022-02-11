int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( V_1 -> V_6 . V_7 && ! F_2 ( V_5 ) && V_5 -> V_3 == NULL ) {
const struct V_8 * V_9 ;
V_9 = F_3 ( V_10 [ F_4 ( V_5 ) -> V_11 ] ) ;
if ( V_9 && V_9 -> V_12 )
V_9 -> V_12 ( V_5 ) ;
}
if ( ! F_5 ( V_5 ) )
F_6 ( V_5 ) ;
return F_7 ( V_5 ) ;
}
int F_8 ( struct V_4 * V_5 , struct V_13 * V_14 , struct V_15 * V_16 , struct V_13 * V_17 )
{
const struct V_18 * V_19 ;
T_1 V_20 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_9 ( V_5 -> V_14 ) ;
if ( V_5 -> V_23 == V_24 ) {
F_10 ( V_5 ) ;
return V_25 ;
}
F_11 () ;
V_22 = F_12 ( V_5 -> V_14 ) ;
F_13 ( V_1 , V_22 , V_26 , V_5 -> V_27 ) ;
if ( ( V_5 = F_14 ( V_5 , V_28 ) ) == NULL ||
! V_22 || F_15 ( V_22 -> V_29 . V_30 ) ) {
F_16 ( V_1 , V_22 , V_31 ) ;
goto V_32;
}
memset ( F_17 ( V_5 ) , 0 , sizeof( struct V_33 ) ) ;
F_17 ( V_5 ) -> V_34 = F_5 ( V_5 ) ? F_18 ( F_2 ( V_5 ) ) -> V_14 -> V_35 : V_14 -> V_35 ;
if ( F_15 ( ! F_19 ( V_5 , sizeof( * V_19 ) ) ) )
goto V_36;
V_19 = F_4 ( V_5 ) ;
if ( V_19 -> V_37 != 6 )
goto V_36;
F_20 ( V_1 , V_22 ,
V_38 +
( F_21 ( V_19 ) & V_39 ) ,
F_22 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ! ( V_14 -> V_40 & V_41 ) &&
F_23 ( & V_19 -> V_42 ) )
goto V_36;
if ( ! ( V_5 -> V_23 == V_43 ||
V_14 -> V_40 & V_41 ) &&
F_24 ( & V_19 -> V_42 ) &&
F_25 ( & V_19 -> V_42 ) == 1 )
goto V_36;
if ( ! F_24 ( & V_19 -> V_42 ) &&
( V_5 -> V_23 == V_44 ||
V_5 -> V_23 == V_45 ) &&
V_22 -> V_29 . V_46 )
goto V_36;
if ( F_24 ( & V_19 -> V_42 ) &&
F_25 ( & V_19 -> V_42 ) == 0 )
goto V_36;
if ( F_24 ( & V_19 -> V_47 ) )
goto V_36;
V_5 -> V_48 = V_5 -> V_49 + sizeof( * V_19 ) ;
F_17 ( V_5 ) -> V_50 = F_26 ( struct V_18 , V_11 ) ;
V_20 = F_27 ( V_19 -> V_51 ) ;
if ( V_20 || V_19 -> V_11 != V_52 ) {
if ( V_20 + sizeof( struct V_18 ) > V_5 -> V_27 ) {
F_16 ( V_1 ,
V_22 , V_53 ) ;
goto V_32;
}
if ( F_28 ( V_5 , V_20 + sizeof( struct V_18 ) ) ) {
F_16 ( V_1 , V_22 , V_54 ) ;
goto V_32;
}
V_19 = F_4 ( V_5 ) ;
}
if ( V_19 -> V_11 == V_52 ) {
if ( F_29 ( V_5 ) < 0 ) {
F_16 ( V_1 , V_22 , V_54 ) ;
F_30 () ;
return V_25 ;
}
}
F_30 () ;
F_31 ( V_5 ) ;
return F_32 ( V_55 , V_56 ,
V_1 , NULL , V_5 , V_14 , NULL ,
F_1 ) ;
V_36:
F_16 ( V_1 , V_22 , V_54 ) ;
V_32:
F_30 () ;
F_10 ( V_5 ) ;
return V_25 ;
}
static int F_33 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
const struct V_8 * V_9 ;
struct V_21 * V_22 ;
unsigned int V_50 ;
int V_11 ;
bool V_57 ;
F_11 () ;
V_58:
V_22 = F_18 ( F_2 ( V_5 ) ) ;
if ( ! F_34 ( V_5 , F_35 ( V_5 ) ) )
goto V_59;
V_50 = F_17 ( V_5 ) -> V_50 ;
V_11 = F_36 ( V_5 ) [ V_50 ] ;
V_57 = F_37 ( V_5 , V_11 ) ;
V_9 = F_3 ( V_10 [ V_11 ] ) ;
if ( V_9 ) {
int V_60 ;
if ( V_9 -> V_40 & V_61 ) {
const struct V_18 * V_19 ;
F_38 ( V_5 ) ;
F_39 ( V_5 , F_36 ( V_5 ) ,
F_40 ( V_5 ) ) ;
V_19 = F_4 ( V_5 ) ;
if ( F_24 ( & V_19 -> V_42 ) &&
! F_41 ( V_5 -> V_14 , & V_19 -> V_42 ,
& V_19 -> V_47 ) &&
! F_42 ( V_5 , V_11 , F_40 ( V_5 ) ) )
goto V_59;
}
if ( ! ( V_9 -> V_40 & V_62 ) &&
! F_43 ( NULL , V_63 , V_5 ) )
goto V_59;
V_60 = V_9 -> V_64 ( V_5 ) ;
if ( V_60 > 0 )
goto V_58;
else if ( V_60 == 0 )
F_16 ( V_1 , V_22 , V_65 ) ;
} else {
if ( ! V_57 ) {
if ( F_43 ( NULL , V_63 , V_5 ) ) {
F_16 ( V_1 , V_22 ,
V_66 ) ;
F_44 ( V_5 , V_67 ,
V_68 , V_50 ) ;
}
F_10 ( V_5 ) ;
} else {
F_16 ( V_1 , V_22 , V_65 ) ;
F_45 ( V_5 ) ;
}
}
F_30 () ;
return 0 ;
V_59:
F_16 ( V_1 , V_22 , V_31 ) ;
F_30 () ;
F_10 ( V_5 ) ;
return 0 ;
}
int F_46 ( struct V_4 * V_5 )
{
return F_32 ( V_55 , V_69 ,
F_9 ( V_5 -> V_14 ) , NULL , V_5 , V_5 -> V_14 , NULL ,
F_33 ) ;
}
int F_47 ( struct V_4 * V_5 )
{
const struct V_18 * V_19 ;
bool V_70 ;
F_13 ( F_9 ( F_2 ( V_5 ) -> V_14 ) ,
F_18 ( F_2 ( V_5 ) ) , V_71 ,
V_5 -> V_27 ) ;
V_19 = F_4 ( V_5 ) ;
V_70 = F_41 ( V_5 -> V_14 , & V_19 -> V_42 , NULL ) ;
#ifdef F_48
if ( F_9 ( V_5 -> V_14 ) -> V_72 . V_73 -> V_74 &&
! ( F_49 ( & V_19 -> V_42 ) &
( V_75 | V_76 ) ) &&
F_50 ( ! ( F_17 ( V_5 ) -> V_40 & V_77 ) ) ) {
struct V_4 * V_78 ;
struct V_33 * V_79 = F_17 ( V_5 ) ;
if ( F_15 ( V_79 -> V_40 & V_80 ) ) {
T_2 V_11 = V_19 -> V_11 ;
T_3 V_81 ;
int V_82 ;
if ( V_79 -> V_83 == F_51 ( V_84 ) ) {
V_70 = false ;
if ( ! F_52 ( V_11 ) ) {
goto V_85;
}
V_82 = F_53 ( V_5 , sizeof( * V_19 ) ,
& V_11 , & V_81 ) ;
if ( V_82 < 0 )
goto V_85;
if ( F_42 ( V_5 , V_11 , V_82 ) )
V_70 = true ;
goto V_85;
}
}
if ( V_70 )
V_78 = F_54 ( V_5 , V_28 ) ;
else {
V_78 = V_5 ;
V_5 = NULL ;
}
if ( V_78 ) {
F_55 ( V_78 ) ;
}
}
V_85:
#endif
if ( F_50 ( V_70 ) )
F_46 ( V_5 ) ;
else {
F_10 ( V_5 ) ;
}
return 0 ;
}
