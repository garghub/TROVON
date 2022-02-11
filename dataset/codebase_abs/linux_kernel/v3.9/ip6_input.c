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
if ( ! ( V_10 -> V_35 & V_36 ) &&
F_19 ( & V_15 -> V_37 ) )
goto V_33;
if ( ! ( V_2 -> V_20 == V_38 ||
V_10 -> V_35 & V_36 ) &&
F_20 ( & V_15 -> V_37 ) &&
F_21 ( & V_15 -> V_37 ) == 1 )
goto V_33;
if ( F_20 ( & V_15 -> V_37 ) &&
F_21 ( & V_15 -> V_37 ) == 0 )
goto V_33;
if ( F_20 ( & V_15 -> V_39 ) )
goto V_33;
V_2 -> V_40 = V_2 -> V_41 + sizeof( * V_15 ) ;
F_16 ( V_2 ) -> V_42 = F_22 ( struct V_14 , V_7 ) ;
V_16 = F_23 ( V_15 -> V_43 ) ;
if ( V_16 || V_15 -> V_7 != V_44 ) {
if ( V_16 + sizeof( struct V_14 ) > V_2 -> V_24 ) {
F_15 ( V_19 ,
V_18 , V_45 ) ;
goto V_29;
}
if ( F_24 ( V_2 , V_16 + sizeof( struct V_14 ) ) ) {
F_15 ( V_19 , V_18 , V_46 ) ;
goto V_29;
}
V_15 = F_4 ( V_2 ) ;
}
if ( V_15 -> V_7 == V_44 ) {
if ( F_25 ( V_2 ) < 0 ) {
F_15 ( V_19 , V_18 , V_46 ) ;
F_26 () ;
return V_22 ;
}
}
F_26 () ;
F_27 ( V_2 ) ;
return F_28 ( V_47 , V_48 , V_2 , V_10 , NULL ,
F_1 ) ;
V_33:
F_15 ( V_19 , V_18 , V_46 ) ;
V_29:
F_26 () ;
F_9 ( V_2 ) ;
return V_22 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_19 * V_19 = F_8 ( F_2 ( V_2 ) -> V_10 ) ;
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
unsigned int V_42 ;
int V_7 ;
bool V_49 ;
F_10 () ;
V_50:
V_18 = F_17 ( F_2 ( V_2 ) ) ;
if ( ! F_30 ( V_2 , F_31 ( V_2 ) ) )
goto V_51;
V_42 = F_16 ( V_2 ) -> V_42 ;
V_7 = F_32 ( V_2 ) [ V_42 ] ;
V_49 = F_33 ( V_2 , V_7 ) ;
if ( ( V_5 = F_3 ( V_6 [ V_7 ] ) ) != NULL ) {
int V_52 ;
if ( V_5 -> V_35 & V_53 ) {
const struct V_14 * V_15 ;
F_34 ( V_2 ) ;
F_35 ( V_2 , F_32 ( V_2 ) ,
F_36 ( V_2 ) ) ;
V_15 = F_4 ( V_2 ) ;
if ( F_20 ( & V_15 -> V_37 ) &&
! F_37 ( V_2 -> V_10 , & V_15 -> V_37 ,
& V_15 -> V_39 ) &&
! F_38 ( V_2 , V_7 , F_36 ( V_2 ) ) )
goto V_51;
}
if ( ! ( V_5 -> V_35 & V_54 ) &&
! F_39 ( NULL , V_55 , V_2 ) )
goto V_51;
V_52 = V_5 -> V_56 ( V_2 ) ;
if ( V_52 > 0 )
goto V_50;
else if ( V_52 == 0 )
F_15 ( V_19 , V_18 , V_57 ) ;
} else {
if ( ! V_49 ) {
if ( F_39 ( NULL , V_55 , V_2 ) ) {
F_15 ( V_19 , V_18 ,
V_58 ) ;
F_40 ( V_2 , V_59 ,
V_60 , V_42 ) ;
}
F_9 ( V_2 ) ;
} else {
F_15 ( V_19 , V_18 , V_57 ) ;
F_41 ( V_2 ) ;
}
}
F_26 () ;
return 0 ;
V_51:
F_15 ( V_19 , V_18 , V_28 ) ;
F_26 () ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
return F_28 ( V_47 , V_61 , V_2 , V_2 -> V_10 , NULL ,
F_29 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 ;
bool V_62 ;
F_12 ( F_8 ( F_2 ( V_2 ) -> V_10 ) ,
F_17 ( F_2 ( V_2 ) ) , V_63 ,
V_2 -> V_24 ) ;
V_15 = F_4 ( V_2 ) ;
V_62 = F_37 ( V_2 -> V_10 , & V_15 -> V_37 , NULL ) ;
#ifdef F_44
if ( F_8 ( V_2 -> V_10 ) -> V_64 . V_65 -> V_66 &&
! ( F_45 ( & V_15 -> V_37 ) &
( V_67 | V_68 ) ) &&
F_46 ( ! ( F_16 ( V_2 ) -> V_35 & V_69 ) ) ) {
struct V_1 * V_70 ;
struct V_30 * V_71 = F_16 ( V_2 ) ;
if ( F_14 ( V_71 -> V_35 & V_72 ) ) {
T_2 V_7 = V_15 -> V_7 ;
T_3 V_73 ;
int V_74 ;
if ( V_71 -> V_75 == F_47 ( V_76 ) ) {
V_62 = false ;
if ( ! F_48 ( V_7 ) ) {
goto V_77;
}
V_74 = F_49 ( V_2 , sizeof( * V_15 ) ,
& V_7 , & V_73 ) ;
if ( V_74 < 0 )
goto V_77;
if ( ! F_38 ( V_2 , V_7 , V_74 ) )
goto V_77;
V_62 = true ;
}
}
if ( V_62 )
V_70 = F_50 ( V_2 , V_25 ) ;
else {
V_70 = V_2 ;
V_2 = NULL ;
}
if ( V_70 ) {
F_51 ( V_70 ) ;
}
}
V_77:
#endif
if ( F_46 ( V_62 ) )
F_42 ( V_2 ) ;
else {
F_9 ( V_2 ) ;
}
return 0 ;
}
