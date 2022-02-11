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
if ( F_20 ( & V_15 -> V_38 ) )
goto V_33;
V_2 -> V_39 = V_2 -> V_40 + sizeof( * V_15 ) ;
F_16 ( V_2 ) -> V_41 = F_21 ( struct V_14 , V_7 ) ;
V_16 = F_22 ( V_15 -> V_42 ) ;
if ( V_16 || V_15 -> V_7 != V_43 ) {
if ( V_16 + sizeof( struct V_14 ) > V_2 -> V_24 ) {
F_15 ( V_19 ,
V_18 , V_44 ) ;
goto V_29;
}
if ( F_23 ( V_2 , V_16 + sizeof( struct V_14 ) ) ) {
F_15 ( V_19 , V_18 , V_45 ) ;
goto V_29;
}
V_15 = F_4 ( V_2 ) ;
}
if ( V_15 -> V_7 == V_43 ) {
if ( F_24 ( V_2 ) < 0 ) {
F_15 ( V_19 , V_18 , V_45 ) ;
F_25 () ;
return V_22 ;
}
}
F_25 () ;
F_26 ( V_2 ) ;
return F_27 ( V_46 , V_47 , V_2 , V_10 , NULL ,
F_1 ) ;
V_33:
F_15 ( V_19 , V_18 , V_45 ) ;
V_29:
F_25 () ;
F_9 ( V_2 ) ;
return V_22 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_19 * V_19 = F_8 ( F_2 ( V_2 ) -> V_10 ) ;
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
unsigned int V_41 ;
int V_7 ;
bool V_48 ;
F_10 () ;
V_49:
V_18 = F_17 ( F_2 ( V_2 ) ) ;
if ( ! F_29 ( V_2 , F_30 ( V_2 ) ) )
goto V_50;
V_41 = F_16 ( V_2 ) -> V_41 ;
V_7 = F_31 ( V_2 ) [ V_41 ] ;
V_48 = F_32 ( V_2 , V_7 ) ;
if ( ( V_5 = F_3 ( V_6 [ V_7 ] ) ) != NULL ) {
int V_51 ;
if ( V_5 -> V_35 & V_52 ) {
const struct V_14 * V_15 ;
F_33 ( V_2 ) ;
F_34 ( V_2 , F_31 ( V_2 ) ,
F_35 ( V_2 ) ) ;
V_15 = F_4 ( V_2 ) ;
if ( F_20 ( & V_15 -> V_37 ) &&
! F_36 ( V_2 -> V_10 , & V_15 -> V_37 ,
& V_15 -> V_38 ) &&
! F_37 ( V_2 , V_7 ) )
goto V_50;
}
if ( ! ( V_5 -> V_35 & V_53 ) &&
! F_38 ( NULL , V_54 , V_2 ) )
goto V_50;
V_51 = V_5 -> V_55 ( V_2 ) ;
if ( V_51 > 0 )
goto V_49;
else if ( V_51 == 0 )
F_15 ( V_19 , V_18 , V_56 ) ;
} else {
if ( ! V_48 ) {
if ( F_38 ( NULL , V_54 , V_2 ) ) {
F_15 ( V_19 , V_18 ,
V_57 ) ;
F_39 ( V_2 , V_58 ,
V_59 , V_41 ) ;
}
} else
F_15 ( V_19 , V_18 , V_56 ) ;
F_9 ( V_2 ) ;
}
F_25 () ;
return 0 ;
V_50:
F_15 ( V_19 , V_18 , V_28 ) ;
F_25 () ;
F_9 ( V_2 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
return F_27 ( V_46 , V_60 , V_2 , V_2 -> V_10 , NULL ,
F_28 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
const struct V_14 * V_15 ;
bool V_61 ;
F_12 ( F_8 ( F_2 ( V_2 ) -> V_10 ) ,
F_17 ( F_2 ( V_2 ) ) , V_62 ,
V_2 -> V_24 ) ;
V_15 = F_4 ( V_2 ) ;
V_61 = F_36 ( V_2 -> V_10 , & V_15 -> V_37 , NULL ) ;
#ifdef F_42
if ( F_8 ( V_2 -> V_10 ) -> V_63 . V_64 -> V_65 &&
! ( F_43 ( & V_15 -> V_37 ) & V_66 ) &&
F_44 ( ! ( F_16 ( V_2 ) -> V_35 & V_67 ) ) ) {
struct V_1 * V_68 ;
struct V_30 * V_69 = F_16 ( V_2 ) ;
if ( F_14 ( V_69 -> V_70 ) ) {
T_2 * V_71 = F_31 ( V_2 ) + V_69 -> V_70 ;
struct V_72 * V_73 ;
T_2 V_7 = V_15 -> V_7 ;
T_3 V_74 ;
int V_75 ;
if ( ( V_71 [ 2 ] | V_71 [ 3 ] ) == 0 ) {
V_61 = false ;
if ( ! F_45 ( V_7 ) ) {
goto V_76;
}
V_75 = F_46 ( V_2 , sizeof( * V_15 ) ,
& V_7 , & V_74 ) ;
if ( V_75 < 0 )
goto V_76;
if ( V_7 != V_77 )
goto V_76;
if ( ! F_18 ( V_2 , ( F_31 ( V_2 ) +
V_75 + 1 - V_2 -> V_78 ) ) )
goto V_76;
V_73 = (struct V_72 * ) ( F_31 ( V_2 ) + V_75 ) ;
switch ( V_73 -> V_79 ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_61 = true ;
break;
}
goto V_76;
}
}
if ( V_61 )
V_68 = F_47 ( V_2 , V_25 ) ;
else {
V_68 = V_2 ;
V_2 = NULL ;
}
if ( V_68 ) {
F_48 ( V_68 ) ;
}
}
V_76:
#endif
if ( F_44 ( V_61 ) )
F_40 ( V_2 ) ;
else {
F_9 ( V_2 ) ;
}
return 0 ;
}
