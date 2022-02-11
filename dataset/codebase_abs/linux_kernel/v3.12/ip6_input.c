int F_1 ( struct V_1 * V_2 )
{
if ( V_3 && ! F_2 ( V_2 ) ) {
const struct V_4 * V_5 ;
V_5 = F_3 ( V_6 [ F_4 ( V_2 ) -> V_7 ] ) ;
if ( V_5 && V_5 -> V_8 )
V_5 -> V_8 ( V_2 ) ;
}
if ( ! F_2 ( V_2 ) )
F_5 ( V_2 ) ;
return F_6 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 , struct V_9 * V_10 , struct V_11 * V_12 , struct V_9 * V_13 )
{
const struct V_14 * V_15 ;
T_1 V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_19 = F_8 ( V_2 -> V_10 ) ;
if ( V_2 -> V_20 == V_21 ) {
F_9 ( V_2 ) ;
return V_22 ;
}
F_10 () ;
V_18 = F_11 ( V_2 -> V_10 ) ;
F_12 ( V_19 , V_18 , V_23 , V_2 -> V_24 ) ;
if ( ( V_2 = F_13 ( V_2 , V_25 ) ) == NULL ||
! V_18 || F_14 ( V_18 -> V_26 . V_27 ) ) {
F_15 ( V_19 , V_18 , V_28 ) ;
goto V_29;
}
memset ( F_16 ( V_2 ) , 0 , sizeof( struct V_30 ) ) ;
F_16 ( V_2 ) -> V_31 = F_2 ( V_2 ) ? F_17 ( F_2 ( V_2 ) ) -> V_10 -> V_32 : V_10 -> V_32 ;
if ( F_14 ( ! F_18 ( V_2 , sizeof( * V_15 ) ) ) )
goto V_33;
V_15 = F_4 ( V_2 ) ;
if ( V_15 -> V_34 != 6 )
goto V_33;
F_19 ( F_8 ( V_10 ) , V_18 ,
V_35 +
( F_20 ( V_15 ) & V_36 ) ,
F_21 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ! ( V_10 -> V_37 & V_38 ) &&
F_22 ( & V_15 -> V_39 ) )
goto V_33;
if ( ! ( V_2 -> V_20 == V_40 ||
V_10 -> V_37 & V_38 ) &&
F_23 ( & V_15 -> V_39 ) &&
F_24 ( & V_15 -> V_39 ) == 1 )
goto V_33;
if ( F_23 ( & V_15 -> V_39 ) &&
F_24 ( & V_15 -> V_39 ) == 0 )
goto V_33;
if ( F_23 ( & V_15 -> V_41 ) )
goto V_33;
V_2 -> V_42 = V_2 -> V_43 + sizeof( * V_15 ) ;
F_16 ( V_2 ) -> V_44 = F_25 ( struct V_14 , V_7 ) ;
V_16 = F_26 ( V_15 -> V_45 ) ;
if ( V_16 || V_15 -> V_7 != V_46 ) {
if ( V_16 + sizeof( struct V_14 ) > V_2 -> V_24 ) {
F_15 ( V_19 ,
V_18 , V_47 ) ;
goto V_29;
}
if ( F_27 ( V_2 , V_16 + sizeof( struct V_14 ) ) ) {
F_15 ( V_19 , V_18 , V_48 ) ;
goto V_29;
}
V_15 = F_4 ( V_2 ) ;
}
if ( V_15 -> V_7 == V_46 ) {
if ( F_28 ( V_2 ) < 0 ) {
F_15 ( V_19 , V_18 , V_48 ) ;
F_29 () ;
return V_22 ;
}
}
F_29 () ;
F_30 ( V_2 ) ;
return F_31 ( V_49 , V_50 , V_2 , V_10 , NULL ,
F_1 ) ;
V_33:
F_15 ( V_19 , V_18 , V_48 ) ;
V_29:
F_29 () ;
F_9 ( V_2 ) ;
return V_22 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_19 * V_19 = F_8 ( F_2 ( V_2 ) -> V_10 ) ;
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
unsigned int V_44 ;
int V_7 ;
bool V_51 ;
F_10 () ;
V_52:
V_18 = F_17 ( F_2 ( V_2 ) ) ;
if ( ! F_33 ( V_2 , F_34 ( V_2 ) ) )
goto V_53;
V_44 = F_16 ( V_2 ) -> V_44 ;
V_7 = F_35 ( V_2 ) [ V_44 ] ;
V_51 = F_36 ( V_2 , V_7 ) ;
if ( ( V_5 = F_3 ( V_6 [ V_7 ] ) ) != NULL ) {
int V_54 ;
if ( V_5 -> V_37 & V_55 ) {
const struct V_14 * V_15 ;
F_37 ( V_2 ) ;
F_38 ( V_2 , F_35 ( V_2 ) ,
F_39 ( V_2 ) ) ;
V_15 = F_4 ( V_2 ) ;
if ( F_23 ( & V_15 -> V_39 ) &&
! F_40 ( V_2 -> V_10 , & V_15 -> V_39 ,
& V_15 -> V_41 ) &&
! F_41 ( V_2 , V_7 , F_39 ( V_2 ) ) )
goto V_53;
}
if ( ! ( V_5 -> V_37 & V_56 ) &&
! F_42 ( NULL , V_57 , V_2 ) )
goto V_53;
V_54 = V_5 -> V_58 ( V_2 ) ;
if ( V_54 > 0 )
goto V_52;
else if ( V_54 == 0 )
F_15 ( V_19 , V_18 , V_59 ) ;
} else {
if ( ! V_51 ) {
if ( F_42 ( NULL , V_57 , V_2 ) ) {
F_15 ( V_19 , V_18 ,
V_60 ) ;
F_43 ( V_2 , V_61 ,
V_62 , V_44 ) ;
}
F_9 ( V_2 ) ;
} else {
F_15 ( V_19 , V_18 , V_59 ) ;
F_44 ( V_2 ) ;
}
}
F_29 () ;
return 0 ;
V_53:
F_15 ( V_19 , V_18 , V_28 ) ;
F_29 () ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_31 ( V_49 , V_63 , V_2 , V_2 -> V_10 , NULL ,
F_32 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 ;
bool V_64 ;
F_12 ( F_8 ( F_2 ( V_2 ) -> V_10 ) ,
F_17 ( F_2 ( V_2 ) ) , V_65 ,
V_2 -> V_24 ) ;
V_15 = F_4 ( V_2 ) ;
V_64 = F_40 ( V_2 -> V_10 , & V_15 -> V_39 , NULL ) ;
#ifdef F_47
if ( F_8 ( V_2 -> V_10 ) -> V_66 . V_67 -> V_68 &&
! ( F_48 ( & V_15 -> V_39 ) &
( V_69 | V_70 ) ) &&
F_49 ( ! ( F_16 ( V_2 ) -> V_37 & V_71 ) ) ) {
struct V_1 * V_72 ;
struct V_30 * V_73 = F_16 ( V_2 ) ;
if ( F_14 ( V_73 -> V_37 & V_74 ) ) {
T_2 V_7 = V_15 -> V_7 ;
T_3 V_75 ;
int V_76 ;
if ( V_73 -> V_77 == F_50 ( V_78 ) ) {
V_64 = false ;
if ( ! F_51 ( V_7 ) ) {
goto V_79;
}
V_76 = F_52 ( V_2 , sizeof( * V_15 ) ,
& V_7 , & V_75 ) ;
if ( V_76 < 0 )
goto V_79;
if ( ! F_41 ( V_2 , V_7 , V_76 ) )
goto V_79;
V_64 = true ;
}
}
if ( V_64 )
V_72 = F_53 ( V_2 , V_25 ) ;
else {
V_72 = V_2 ;
V_2 = NULL ;
}
if ( V_72 ) {
F_54 ( V_72 ) ;
}
}
V_79:
#endif
if ( F_49 ( V_64 ) )
F_45 ( V_2 ) ;
else {
F_9 ( V_2 ) ;
}
return 0 ;
}
