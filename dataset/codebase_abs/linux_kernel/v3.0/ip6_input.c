inline int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) == NULL )
F_3 ( V_2 ) ;
return F_4 ( V_2 ) ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 , struct V_3 * V_7 )
{
const struct V_8 * V_9 ;
T_1 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_13 = F_6 ( V_2 -> V_4 ) ;
if ( V_2 -> V_14 == V_15 ) {
F_7 ( V_2 ) ;
return V_16 ;
}
F_8 () ;
V_12 = F_9 ( V_2 -> V_4 ) ;
F_10 ( V_13 , V_12 , V_17 , V_2 -> V_18 ) ;
if ( ( V_2 = F_11 ( V_2 , V_19 ) ) == NULL ||
! V_12 || F_12 ( V_12 -> V_20 . V_21 ) ) {
F_13 ( V_13 , V_12 , V_22 ) ;
goto V_23;
}
memset ( F_14 ( V_2 ) , 0 , sizeof( struct V_24 ) ) ;
F_14 ( V_2 ) -> V_25 = F_2 ( V_2 ) ? F_15 ( F_2 ( V_2 ) ) -> V_4 -> V_26 : V_4 -> V_26 ;
if ( F_12 ( ! F_16 ( V_2 , sizeof( * V_9 ) ) ) )
goto V_27;
V_9 = F_17 ( V_2 ) ;
if ( V_9 -> V_28 != 6 )
goto V_27;
if ( ! ( V_4 -> V_29 & V_30 ) &&
F_18 ( & V_9 -> V_31 ) )
goto V_27;
V_2 -> V_32 = V_2 -> V_33 + sizeof( * V_9 ) ;
F_14 ( V_2 ) -> V_34 = F_19 ( struct V_8 , V_35 ) ;
V_10 = F_20 ( V_9 -> V_36 ) ;
if ( V_10 || V_9 -> V_35 != V_37 ) {
if ( V_10 + sizeof( struct V_8 ) > V_2 -> V_18 ) {
F_13 ( V_13 ,
V_12 , V_38 ) ;
goto V_23;
}
if ( F_21 ( V_2 , V_10 + sizeof( struct V_8 ) ) ) {
F_13 ( V_13 , V_12 , V_39 ) ;
goto V_23;
}
V_9 = F_17 ( V_2 ) ;
}
if ( V_9 -> V_35 == V_37 ) {
if ( F_22 ( V_2 ) < 0 ) {
F_13 ( V_13 , V_12 , V_39 ) ;
F_23 () ;
return V_16 ;
}
}
F_23 () ;
F_24 ( V_2 ) ;
return F_25 ( V_40 , V_41 , V_2 , V_4 , NULL ,
F_1 ) ;
V_27:
F_13 ( V_13 , V_12 , V_39 ) ;
V_23:
F_23 () ;
F_7 ( V_2 ) ;
return V_16 ;
}
static int F_26 ( struct V_1 * V_2 )
{
const struct V_42 * V_43 ;
unsigned int V_34 ;
int V_35 , V_44 ;
T_2 V_45 ;
struct V_11 * V_12 ;
struct V_13 * V_13 = F_6 ( F_2 ( V_2 ) -> V_4 ) ;
F_8 () ;
V_46:
V_12 = F_15 ( F_2 ( V_2 ) ) ;
if ( ! F_27 ( V_2 , F_28 ( V_2 ) ) )
goto V_47;
V_34 = F_14 ( V_2 ) -> V_34 ;
V_35 = F_29 ( V_2 ) [ V_34 ] ;
V_44 = F_30 ( V_2 , V_35 ) ;
V_45 = V_35 & ( V_48 - 1 ) ;
if ( ( V_43 = F_31 ( V_49 [ V_45 ] ) ) != NULL ) {
int V_50 ;
if ( V_43 -> V_29 & V_51 ) {
const struct V_8 * V_9 ;
F_32 ( V_2 ) ;
F_33 ( V_2 , F_29 ( V_2 ) ,
F_34 ( V_2 ) ) ;
V_9 = F_17 ( V_2 ) ;
if ( F_35 ( & V_9 -> V_31 ) &&
! F_36 ( V_2 -> V_4 , & V_9 -> V_31 ,
& V_9 -> V_52 ) &&
! F_37 ( V_2 , V_35 ) )
goto V_47;
}
if ( ! ( V_43 -> V_29 & V_53 ) &&
! F_38 ( NULL , V_54 , V_2 ) )
goto V_47;
V_50 = V_43 -> V_55 ( V_2 ) ;
if ( V_50 > 0 )
goto V_46;
else if ( V_50 == 0 )
F_13 ( V_13 , V_12 , V_56 ) ;
} else {
if ( ! V_44 ) {
if ( F_38 ( NULL , V_54 , V_2 ) ) {
F_13 ( V_13 , V_12 ,
V_57 ) ;
F_39 ( V_2 , V_58 ,
V_59 , V_34 ) ;
}
} else
F_13 ( V_13 , V_12 , V_56 ) ;
F_7 ( V_2 ) ;
}
F_23 () ;
return 0 ;
V_47:
F_13 ( V_13 , V_12 , V_22 ) ;
F_23 () ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
return F_25 ( V_40 , V_60 , V_2 , V_2 -> V_4 , NULL ,
F_26 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
const struct V_8 * V_9 ;
int V_61 ;
F_10 ( F_6 ( F_2 ( V_2 ) -> V_4 ) ,
F_15 ( F_2 ( V_2 ) ) , V_62 ,
V_2 -> V_18 ) ;
V_9 = F_17 ( V_2 ) ;
V_61 = F_36 ( V_2 -> V_4 , & V_9 -> V_31 , NULL ) ;
#ifdef F_42
if ( F_6 ( V_2 -> V_4 ) -> V_63 . V_64 -> V_65 &&
! ( F_43 ( & V_9 -> V_31 ) & V_66 ) &&
F_44 ( ! ( F_14 ( V_2 ) -> V_29 & V_67 ) ) ) {
struct V_1 * V_68 ;
struct V_24 * V_69 = F_14 ( V_2 ) ;
if ( F_12 ( V_69 -> V_70 ) ) {
T_2 * V_71 = F_29 ( V_2 ) + V_69 -> V_70 ;
struct V_72 * V_73 ;
T_2 V_35 = V_9 -> V_35 ;
int V_74 ;
if ( ( V_71 [ 2 ] | V_71 [ 3 ] ) == 0 ) {
V_61 = 0 ;
if ( ! F_45 ( V_35 ) ) {
goto V_75;
}
V_74 = F_46 ( V_2 , sizeof( * V_9 ) ,
& V_35 ) ;
if ( V_74 < 0 )
goto V_75;
if ( V_35 != V_76 )
goto V_75;
if ( ! F_16 ( V_2 , ( F_29 ( V_2 ) +
V_74 + 1 - V_2 -> V_77 ) ) )
goto V_75;
V_73 = (struct V_72 * ) ( F_29 ( V_2 ) + V_74 ) ;
switch ( V_73 -> V_78 ) {
case V_79 :
case V_80 :
case V_81 :
case V_82 :
V_61 = 1 ;
break;
}
goto V_75;
}
}
if ( V_61 )
V_68 = F_47 ( V_2 , V_19 ) ;
else {
V_68 = V_2 ;
V_2 = NULL ;
}
if ( V_68 ) {
F_48 ( V_68 ) ;
}
}
V_75:
#endif
if ( F_44 ( V_61 ) )
F_40 ( V_2 ) ;
else {
F_7 ( V_2 ) ;
}
return 0 ;
}
