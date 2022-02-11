int F_1 ( struct V_1 * V_2 )
{
if ( V_3 && ! F_2 ( V_2 ) && V_2 -> V_4 == NULL ) {
const struct V_5 * V_6 ;
V_6 = F_3 ( V_7 [ F_4 ( V_2 ) -> V_8 ] ) ;
if ( V_6 && V_6 -> V_9 )
V_6 -> V_9 ( V_2 ) ;
}
if ( ! F_2 ( V_2 ) )
F_5 ( V_2 ) ;
return F_6 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 , struct V_10 * V_11 , struct V_12 * V_13 , struct V_10 * V_14 )
{
const struct V_15 * V_16 ;
T_1 V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_20 = F_8 ( V_2 -> V_11 ) ;
if ( V_2 -> V_21 == V_22 ) {
F_9 ( V_2 ) ;
return V_23 ;
}
F_10 () ;
V_19 = F_11 ( V_2 -> V_11 ) ;
F_12 ( V_20 , V_19 , V_24 , V_2 -> V_25 ) ;
if ( ( V_2 = F_13 ( V_2 , V_26 ) ) == NULL ||
! V_19 || F_14 ( V_19 -> V_27 . V_28 ) ) {
F_15 ( V_20 , V_19 , V_29 ) ;
goto V_30;
}
memset ( F_16 ( V_2 ) , 0 , sizeof( struct V_31 ) ) ;
F_16 ( V_2 ) -> V_32 = F_2 ( V_2 ) ? F_17 ( F_2 ( V_2 ) ) -> V_11 -> V_33 : V_11 -> V_33 ;
if ( F_14 ( ! F_18 ( V_2 , sizeof( * V_16 ) ) ) )
goto V_34;
V_16 = F_4 ( V_2 ) ;
if ( V_16 -> V_35 != 6 )
goto V_34;
F_19 ( F_8 ( V_11 ) , V_19 ,
V_36 +
( F_20 ( V_16 ) & V_37 ) ,
F_21 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ! ( V_11 -> V_38 & V_39 ) &&
F_22 ( & V_16 -> V_40 ) )
goto V_34;
if ( ! ( V_2 -> V_21 == V_41 ||
V_11 -> V_38 & V_39 ) &&
F_23 ( & V_16 -> V_40 ) &&
F_24 ( & V_16 -> V_40 ) == 1 )
goto V_34;
if ( F_23 ( & V_16 -> V_40 ) &&
F_24 ( & V_16 -> V_40 ) == 0 )
goto V_34;
if ( F_23 ( & V_16 -> V_42 ) )
goto V_34;
V_2 -> V_43 = V_2 -> V_44 + sizeof( * V_16 ) ;
F_16 ( V_2 ) -> V_45 = F_25 ( struct V_15 , V_8 ) ;
V_17 = F_26 ( V_16 -> V_46 ) ;
if ( V_17 || V_16 -> V_8 != V_47 ) {
if ( V_17 + sizeof( struct V_15 ) > V_2 -> V_25 ) {
F_15 ( V_20 ,
V_19 , V_48 ) ;
goto V_30;
}
if ( F_27 ( V_2 , V_17 + sizeof( struct V_15 ) ) ) {
F_15 ( V_20 , V_19 , V_49 ) ;
goto V_30;
}
V_16 = F_4 ( V_2 ) ;
}
if ( V_16 -> V_8 == V_47 ) {
if ( F_28 ( V_2 ) < 0 ) {
F_15 ( V_20 , V_19 , V_49 ) ;
F_29 () ;
return V_23 ;
}
}
F_29 () ;
F_30 ( V_2 ) ;
return F_31 ( V_50 , V_51 , V_2 , V_11 , NULL ,
F_1 ) ;
V_34:
F_15 ( V_20 , V_19 , V_49 ) ;
V_30:
F_29 () ;
F_9 ( V_2 ) ;
return V_23 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_8 ( F_2 ( V_2 ) -> V_11 ) ;
const struct V_5 * V_6 ;
struct V_18 * V_19 ;
unsigned int V_45 ;
int V_8 ;
bool V_52 ;
F_10 () ;
V_53:
V_19 = F_17 ( F_2 ( V_2 ) ) ;
if ( ! F_33 ( V_2 , F_34 ( V_2 ) ) )
goto V_54;
V_45 = F_16 ( V_2 ) -> V_45 ;
V_8 = F_35 ( V_2 ) [ V_45 ] ;
V_52 = F_36 ( V_2 , V_8 ) ;
if ( ( V_6 = F_3 ( V_7 [ V_8 ] ) ) != NULL ) {
int V_55 ;
if ( V_6 -> V_38 & V_56 ) {
const struct V_15 * V_16 ;
F_37 ( V_2 ) ;
F_38 ( V_2 , F_35 ( V_2 ) ,
F_39 ( V_2 ) ) ;
V_16 = F_4 ( V_2 ) ;
if ( F_23 ( & V_16 -> V_40 ) &&
! F_40 ( V_2 -> V_11 , & V_16 -> V_40 ,
& V_16 -> V_42 ) &&
! F_41 ( V_2 , V_8 , F_39 ( V_2 ) ) )
goto V_54;
}
if ( ! ( V_6 -> V_38 & V_57 ) &&
! F_42 ( NULL , V_58 , V_2 ) )
goto V_54;
V_55 = V_6 -> V_59 ( V_2 ) ;
if ( V_55 > 0 )
goto V_53;
else if ( V_55 == 0 )
F_15 ( V_20 , V_19 , V_60 ) ;
} else {
if ( ! V_52 ) {
if ( F_42 ( NULL , V_58 , V_2 ) ) {
F_15 ( V_20 , V_19 ,
V_61 ) ;
F_43 ( V_2 , V_62 ,
V_63 , V_45 ) ;
}
F_9 ( V_2 ) ;
} else {
F_15 ( V_20 , V_19 , V_60 ) ;
F_44 ( V_2 ) ;
}
}
F_29 () ;
return 0 ;
V_54:
F_15 ( V_20 , V_19 , V_29 ) ;
F_29 () ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_31 ( V_50 , V_64 , V_2 , V_2 -> V_11 , NULL ,
F_32 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 ;
bool V_65 ;
F_12 ( F_8 ( F_2 ( V_2 ) -> V_11 ) ,
F_17 ( F_2 ( V_2 ) ) , V_66 ,
V_2 -> V_25 ) ;
V_16 = F_4 ( V_2 ) ;
V_65 = F_40 ( V_2 -> V_11 , & V_16 -> V_40 , NULL ) ;
#ifdef F_47
if ( F_8 ( V_2 -> V_11 ) -> V_67 . V_68 -> V_69 &&
! ( F_48 ( & V_16 -> V_40 ) &
( V_70 | V_71 ) ) &&
F_49 ( ! ( F_16 ( V_2 ) -> V_38 & V_72 ) ) ) {
struct V_1 * V_73 ;
struct V_31 * V_74 = F_16 ( V_2 ) ;
if ( F_14 ( V_74 -> V_38 & V_75 ) ) {
T_2 V_8 = V_16 -> V_8 ;
T_3 V_76 ;
int V_77 ;
if ( V_74 -> V_78 == F_50 ( V_79 ) ) {
V_65 = false ;
if ( ! F_51 ( V_8 ) ) {
goto V_80;
}
V_77 = F_52 ( V_2 , sizeof( * V_16 ) ,
& V_8 , & V_76 ) ;
if ( V_77 < 0 )
goto V_80;
if ( ! F_41 ( V_2 , V_8 , V_77 ) )
goto V_80;
V_65 = true ;
}
}
if ( V_65 )
V_73 = F_53 ( V_2 , V_26 ) ;
else {
V_73 = V_2 ;
V_2 = NULL ;
}
if ( V_73 ) {
F_54 ( V_73 ) ;
}
}
V_80:
#endif
if ( F_49 ( V_65 ) )
F_45 ( V_2 ) ;
else {
F_9 ( V_2 ) ;
}
return 0 ;
}
