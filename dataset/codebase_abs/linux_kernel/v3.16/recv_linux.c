void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
enum V_4 V_5 = 0 ;
union V_6 V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 = & V_2 -> V_12 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned long V_16 ;
if ( V_14 -> V_17 == 0 ) {
V_14 -> V_17 = V_18 ;
} else {
V_16 = V_18 ;
if ( V_16 - V_14 -> V_17 < 60 * V_19 ) {
V_14 -> V_20 = true ;
V_14 -> V_17 = 0 ;
V_14 -> V_21 = V_16 ;
} else {
V_14 -> V_17 = V_18 ;
}
}
if ( V_3 )
V_5 |= V_22 ;
else
V_5 |= V_23 ;
F_2 ( V_2 -> V_24 ,
( T_1 * ) & V_11 -> V_25 [ 0 ] ,
V_5 , - 1 , NULL , V_26 ) ;
memset ( & V_9 , 0x00 , sizeof( V_9 ) ) ;
if ( V_3 )
V_9 . V_27 |= V_28 ;
else
V_9 . V_27 |= V_29 ;
V_9 . V_30 . V_31 = V_32 ;
F_3 ( V_9 . V_30 . V_33 , & V_11 -> V_25 [ 0 ] ) ;
memset ( & V_7 , 0x00 , sizeof( V_7 ) ) ;
V_7 . V_34 . V_35 = sizeof( V_9 ) ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_10 * V_11 = & V_2 -> V_12 ;
V_39 = & V_2 -> V_42 ;
V_41 = V_37 -> V_43 ;
if ( ! V_41 ) {
F_5 ( V_44 , V_45 ,
( L_1 ) ) ;
goto V_46;
}
F_5 ( V_44 , V_47 ,
( L_2 ) ) ;
F_5 ( V_44 , V_47 ,
( L_3 ,
V_37 -> V_43 -> V_34 ) ) ;
F_5 ( V_44 , V_47 ,
( L_4 ,
V_41 -> V_48 , V_41 -> V_34 ,
F_6 ( V_41 ) , F_7 ( V_41 ) , V_41 -> V_49 ) ) ;
if ( F_8 ( V_11 , V_50 ) == true ) {
struct V_40 * V_51 = NULL ;
struct V_52 * V_53 = NULL ;
struct V_54 * V_55 = & V_2 -> V_56 ;
struct V_57 * V_58 = & V_37 -> V_59 ;
int V_60 = F_9 ( V_58 -> V_61 ) ;
if ( ! F_10 ( V_58 -> V_61 ,
F_11 ( & V_2 -> V_62 ) ) ) {
if ( V_60 ) {
V_53 = F_12 ( V_2 ) ;
V_51 = F_13 ( V_41 , V_26 ) ;
} else {
V_53 = F_14 ( V_55 , V_58 -> V_61 ) ;
}
if ( V_53 ) {
struct V_63 * V_24 = V_2 -> V_24 ;
V_41 -> V_64 = V_24 ;
F_15 ( V_41 , F_16 ( V_41 ) ) ;
F_17 ( V_41 , V_24 ) ;
if ( V_60 )
V_41 = V_51 ;
else
goto V_65;
}
} else {
}
}
V_41 -> V_66 = V_67 ;
V_41 -> V_64 = V_2 -> V_24 ;
V_41 -> V_68 = F_18 ( V_41 , V_2 -> V_24 ) ;
F_19 ( V_41 ) ;
V_65:
V_37 -> V_43 = NULL ;
F_20 ( V_37 ) ;
F_5 ( V_44 , V_47 ,
( L_5 ) ) ;
return V_69 ;
V_46:
F_20 ( V_37 ) ;
return V_70 ;
}
void F_21 ( struct V_71 * V_72 )
{
F_22 ( & V_72 -> V_73 ,
V_74 ,
( unsigned long ) V_72 ) ;
}
