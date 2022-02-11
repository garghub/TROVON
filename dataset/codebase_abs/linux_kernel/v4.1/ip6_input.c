int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_5 && ! F_2 ( V_4 ) && V_4 -> V_2 == NULL ) {
const struct V_6 * V_7 ;
V_7 = F_3 ( V_8 [ F_4 ( V_4 ) -> V_9 ] ) ;
if ( V_7 && V_7 -> V_10 )
V_7 -> V_10 ( V_4 ) ;
}
if ( ! F_2 ( V_4 ) )
F_5 ( V_4 ) ;
return F_6 ( V_4 ) ;
}
int F_7 ( struct V_3 * V_4 , struct V_11 * V_12 , struct V_13 * V_14 , struct V_11 * V_15 )
{
const struct V_16 * V_17 ;
T_1 V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_21 = F_8 ( V_4 -> V_12 ) ;
if ( V_4 -> V_22 == V_23 ) {
F_9 ( V_4 ) ;
return V_24 ;
}
F_10 () ;
V_20 = F_11 ( V_4 -> V_12 ) ;
F_12 ( V_21 , V_20 , V_25 , V_4 -> V_26 ) ;
if ( ( V_4 = F_13 ( V_4 , V_27 ) ) == NULL ||
! V_20 || F_14 ( V_20 -> V_28 . V_29 ) ) {
F_15 ( V_21 , V_20 , V_30 ) ;
goto V_31;
}
memset ( F_16 ( V_4 ) , 0 , sizeof( struct V_32 ) ) ;
F_16 ( V_4 ) -> V_33 = F_2 ( V_4 ) ? F_17 ( F_2 ( V_4 ) ) -> V_12 -> V_34 : V_12 -> V_34 ;
if ( F_14 ( ! F_18 ( V_4 , sizeof( * V_17 ) ) ) )
goto V_35;
V_17 = F_4 ( V_4 ) ;
if ( V_17 -> V_36 != 6 )
goto V_35;
F_19 ( F_8 ( V_12 ) , V_20 ,
V_37 +
( F_20 ( V_17 ) & V_38 ) ,
F_21 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ! ( V_12 -> V_39 & V_40 ) &&
F_22 ( & V_17 -> V_41 ) )
goto V_35;
if ( ! ( V_4 -> V_22 == V_42 ||
V_12 -> V_39 & V_40 ) &&
F_23 ( & V_17 -> V_41 ) &&
F_24 ( & V_17 -> V_41 ) == 1 )
goto V_35;
if ( F_23 ( & V_17 -> V_41 ) &&
F_24 ( & V_17 -> V_41 ) == 0 )
goto V_35;
if ( F_23 ( & V_17 -> V_43 ) )
goto V_35;
V_4 -> V_44 = V_4 -> V_45 + sizeof( * V_17 ) ;
F_16 ( V_4 ) -> V_46 = F_25 ( struct V_16 , V_9 ) ;
V_18 = F_26 ( V_17 -> V_47 ) ;
if ( V_18 || V_17 -> V_9 != V_48 ) {
if ( V_18 + sizeof( struct V_16 ) > V_4 -> V_26 ) {
F_15 ( V_21 ,
V_20 , V_49 ) ;
goto V_31;
}
if ( F_27 ( V_4 , V_18 + sizeof( struct V_16 ) ) ) {
F_15 ( V_21 , V_20 , V_50 ) ;
goto V_31;
}
V_17 = F_4 ( V_4 ) ;
}
if ( V_17 -> V_9 == V_48 ) {
if ( F_28 ( V_4 ) < 0 ) {
F_15 ( V_21 , V_20 , V_50 ) ;
F_29 () ;
return V_24 ;
}
}
F_29 () ;
F_30 ( V_4 ) ;
return F_31 ( V_51 , V_52 , NULL , V_4 ,
V_12 , NULL ,
F_1 ) ;
V_35:
F_15 ( V_21 , V_20 , V_50 ) ;
V_31:
F_29 () ;
F_9 ( V_4 ) ;
return V_24 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_21 * V_21 = F_8 ( F_2 ( V_4 ) -> V_12 ) ;
const struct V_6 * V_7 ;
struct V_19 * V_20 ;
unsigned int V_46 ;
int V_9 ;
bool V_53 ;
F_10 () ;
V_54:
V_20 = F_17 ( F_2 ( V_4 ) ) ;
if ( ! F_33 ( V_4 , F_34 ( V_4 ) ) )
goto V_55;
V_46 = F_16 ( V_4 ) -> V_46 ;
V_9 = F_35 ( V_4 ) [ V_46 ] ;
V_53 = F_36 ( V_4 , V_9 ) ;
V_7 = F_3 ( V_8 [ V_9 ] ) ;
if ( V_7 ) {
int V_56 ;
if ( V_7 -> V_39 & V_57 ) {
const struct V_16 * V_17 ;
F_37 ( V_4 ) ;
F_38 ( V_4 , F_35 ( V_4 ) ,
F_39 ( V_4 ) ) ;
V_17 = F_4 ( V_4 ) ;
if ( F_23 ( & V_17 -> V_41 ) &&
! F_40 ( V_4 -> V_12 , & V_17 -> V_41 ,
& V_17 -> V_43 ) &&
! F_41 ( V_4 , V_9 , F_39 ( V_4 ) ) )
goto V_55;
}
if ( ! ( V_7 -> V_39 & V_58 ) &&
! F_42 ( NULL , V_59 , V_4 ) )
goto V_55;
V_56 = V_7 -> V_60 ( V_4 ) ;
if ( V_56 > 0 )
goto V_54;
else if ( V_56 == 0 )
F_15 ( V_21 , V_20 , V_61 ) ;
} else {
if ( ! V_53 ) {
if ( F_42 ( NULL , V_59 , V_4 ) ) {
F_15 ( V_21 , V_20 ,
V_62 ) ;
F_43 ( V_4 , V_63 ,
V_64 , V_46 ) ;
}
F_9 ( V_4 ) ;
} else {
F_15 ( V_21 , V_20 , V_61 ) ;
F_44 ( V_4 ) ;
}
}
F_29 () ;
return 0 ;
V_55:
F_15 ( V_21 , V_20 , V_30 ) ;
F_29 () ;
F_9 ( V_4 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_4 )
{
return F_31 ( V_51 , V_65 , NULL , V_4 ,
V_4 -> V_12 , NULL ,
F_32 ) ;
}
int F_46 ( struct V_3 * V_4 )
{
const struct V_16 * V_17 ;
bool V_66 ;
F_12 ( F_8 ( F_2 ( V_4 ) -> V_12 ) ,
F_17 ( F_2 ( V_4 ) ) , V_67 ,
V_4 -> V_26 ) ;
V_17 = F_4 ( V_4 ) ;
V_66 = F_40 ( V_4 -> V_12 , & V_17 -> V_41 , NULL ) ;
#ifdef F_47
if ( F_8 ( V_4 -> V_12 ) -> V_68 . V_69 -> V_70 &&
! ( F_48 ( & V_17 -> V_41 ) &
( V_71 | V_72 ) ) &&
F_49 ( ! ( F_16 ( V_4 ) -> V_39 & V_73 ) ) ) {
struct V_3 * V_74 ;
struct V_32 * V_75 = F_16 ( V_4 ) ;
if ( F_14 ( V_75 -> V_39 & V_76 ) ) {
T_2 V_9 = V_17 -> V_9 ;
T_3 V_77 ;
int V_78 ;
if ( V_75 -> V_79 == F_50 ( V_80 ) ) {
V_66 = false ;
if ( ! F_51 ( V_9 ) ) {
goto V_81;
}
V_78 = F_52 ( V_4 , sizeof( * V_17 ) ,
& V_9 , & V_77 ) ;
if ( V_78 < 0 )
goto V_81;
if ( ! F_41 ( V_4 , V_9 , V_78 ) )
goto V_81;
V_66 = true ;
}
}
if ( V_66 )
V_74 = F_53 ( V_4 , V_27 ) ;
else {
V_74 = V_4 ;
V_4 = NULL ;
}
if ( V_74 ) {
F_54 ( V_74 ) ;
}
}
V_81:
#endif
if ( F_49 ( V_66 ) )
F_45 ( V_4 ) ;
else {
F_9 ( V_4 ) ;
}
return 0 ;
}
