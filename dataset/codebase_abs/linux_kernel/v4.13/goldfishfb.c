static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 = V_2 ;
T_2 V_6 ;
F_2 ( & V_5 -> V_7 , V_3 ) ;
V_6 = F_3 ( V_5 -> V_8 + V_9 ) ;
if ( V_6 & V_10 ) {
V_5 -> V_11 ++ ;
F_4 ( & V_5 -> V_12 ) ;
}
F_5 ( & V_5 -> V_7 , V_3 ) ;
return V_6 ? V_13 : V_14 ;
}
static inline T_2 F_6 ( int V_15 , struct V_16 * V_17 )
{
unsigned int V_18 = ( 1 << V_17 -> V_19 ) - 1 ;
return ( V_15 >> ( 16 - V_17 -> V_19 ) & V_18 ) << V_17 -> V_20 ;
}
static int
F_7 ( unsigned int V_21 , unsigned int V_22 , unsigned int V_23 ,
unsigned int V_24 , unsigned int V_25 , struct V_26 * V_27 )
{
struct V_4 * V_5 = F_8 ( V_27 , struct V_4 , V_5 ) ;
if ( V_21 < 16 ) {
V_5 -> V_28 [ V_21 ] = F_6 ( V_25 , & V_5 -> V_5 . V_29 . V_25 ) |
F_6 ( V_24 , & V_5 -> V_5 . V_29 . V_24 ) |
F_6 ( V_23 , & V_5 -> V_5 . V_29 . V_23 ) |
F_6 ( V_22 , & V_5 -> V_5 . V_29 . V_22 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_9 ( struct V_30 * V_29 ,
struct V_26 * V_27 )
{
if ( ( V_29 -> V_31 & 1 ) != ( V_27 -> V_29 . V_31 & 1 ) ) {
if ( ( V_29 -> V_32 != V_27 -> V_29 . V_33 ) ||
( V_29 -> V_33 != V_27 -> V_29 . V_32 ) ||
( V_29 -> V_34 != V_27 -> V_29 . V_33 ) ||
( V_29 -> V_35 > V_27 -> V_29 . V_32 * 2 ) ||
( V_29 -> V_35 < V_27 -> V_29 . V_32 ) ) {
return - V_36 ;
}
} else {
if ( ( V_29 -> V_32 != V_27 -> V_29 . V_32 ) ||
( V_29 -> V_33 != V_27 -> V_29 . V_33 ) ||
( V_29 -> V_34 != V_27 -> V_29 . V_32 ) ||
( V_29 -> V_35 > V_27 -> V_29 . V_33 * 2 ) ||
( V_29 -> V_35 < V_27 -> V_29 . V_33 ) ) {
return - V_36 ;
}
}
if ( ( V_29 -> V_37 != V_27 -> V_29 . V_37 ) ||
( V_29 -> V_38 != V_27 -> V_29 . V_38 ) ||
( V_29 -> V_39 != V_27 -> V_29 . V_39 ) ) {
return - V_36 ;
}
return 0 ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = F_8 ( V_27 , struct V_4 , V_5 ) ;
if ( V_5 -> V_40 != V_5 -> V_5 . V_29 . V_31 ) {
V_27 -> V_41 . V_42 = V_27 -> V_29 . V_32 * 2 ;
V_5 -> V_40 = V_5 -> V_5 . V_29 . V_31 ;
F_11 ( V_5 -> V_40 , V_5 -> V_8 + V_43 ) ;
}
return 0 ;
}
static int F_12 ( struct V_30 * V_29 ,
struct V_26 * V_27 )
{
unsigned long V_3 ;
int V_11 ;
struct V_4 * V_5 = F_8 ( V_27 , struct V_4 , V_5 ) ;
F_2 ( & V_5 -> V_7 , V_3 ) ;
V_11 = V_5 -> V_11 ;
F_11 ( V_5 -> V_5 . V_41 . V_44 + V_5 -> V_5 . V_29 . V_32 * 2 * V_29 -> V_45 ,
V_5 -> V_8 + V_46 ) ;
F_5 ( & V_5 -> V_7 , V_3 ) ;
F_13 ( V_5 -> V_12 ,
V_5 -> V_11 != V_11 , V_47 / 15 ) ;
if ( V_5 -> V_11 == V_11 )
F_14 ( L_1 ) ;
return 0 ;
}
static int F_15 ( int V_48 , struct V_26 * V_27 )
{
struct V_4 * V_5 = F_8 ( V_27 , struct V_4 , V_5 ) ;
switch ( V_48 ) {
case V_49 :
F_11 ( 1 , V_5 -> V_8 + V_50 ) ;
break;
case V_51 :
F_11 ( 0 , V_5 -> V_8 + V_50 ) ;
break;
}
return 0 ;
}
static int F_16 ( struct V_52 * V_53 )
{
int V_54 ;
struct V_55 * V_56 ;
struct V_4 * V_5 ;
T_3 V_57 ;
T_2 V_58 , V_59 ;
T_4 V_60 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_61 ) ;
if ( V_5 == NULL ) {
V_54 = - V_62 ;
goto V_63;
}
F_18 ( & V_5 -> V_7 ) ;
F_19 ( & V_5 -> V_12 ) ;
F_20 ( V_53 , V_5 ) ;
V_56 = F_21 ( V_53 , V_64 , 0 ) ;
if ( V_56 == NULL ) {
V_54 = - V_65 ;
goto V_66;
}
V_5 -> V_8 = F_22 ( V_56 -> V_67 , V_68 ) ;
if ( V_5 -> V_8 == NULL ) {
V_54 = - V_62 ;
goto V_66;
}
V_5 -> V_1 = F_23 ( V_53 , 0 ) ;
if ( V_5 -> V_1 <= 0 ) {
V_54 = - V_65 ;
goto V_69;
}
V_58 = F_3 ( V_5 -> V_8 + V_70 ) ;
V_59 = F_3 ( V_5 -> V_8 + V_71 ) ;
V_5 -> V_5 . V_72 = & V_73 ;
V_5 -> V_5 . V_74 = V_75 ;
V_5 -> V_5 . V_76 = V_5 -> V_28 ;
V_5 -> V_5 . V_41 . type = V_77 ;
V_5 -> V_5 . V_41 . V_78 = V_79 ;
V_5 -> V_5 . V_41 . V_42 = V_58 * 2 ;
V_5 -> V_5 . V_41 . V_80 = V_81 ;
V_5 -> V_5 . V_41 . V_82 = 1 ;
V_5 -> V_5 . V_29 . V_32 = V_58 ;
V_5 -> V_5 . V_29 . V_33 = V_59 ;
V_5 -> V_5 . V_29 . V_34 = V_58 ;
V_5 -> V_5 . V_29 . V_35 = V_59 * 2 ;
V_5 -> V_5 . V_29 . V_38 = 16 ;
V_5 -> V_5 . V_29 . V_83 = V_84 ;
V_5 -> V_5 . V_29 . V_59 = F_3 ( V_5 -> V_8 + V_85 ) ;
V_5 -> V_5 . V_29 . V_58 = F_3 ( V_5 -> V_8 + V_86 ) ;
V_5 -> V_5 . V_29 . V_87 = 10000 ;
V_5 -> V_5 . V_29 . V_22 . V_20 = 11 ;
V_5 -> V_5 . V_29 . V_22 . V_19 = 5 ;
V_5 -> V_5 . V_29 . V_23 . V_20 = 5 ;
V_5 -> V_5 . V_29 . V_23 . V_19 = 6 ;
V_5 -> V_5 . V_29 . V_24 . V_20 = 0 ;
V_5 -> V_5 . V_29 . V_24 . V_19 = 5 ;
V_57 = V_58 * V_59 * 2 * 2 ;
V_5 -> V_5 . V_88 = ( char V_89 V_90 * ) F_24 (
& V_53 -> V_91 , V_57 ,
& V_60 , V_61 ) ;
F_25 ( L_2 ,
V_58 , V_59 , V_5 -> V_5 . V_88 ) ;
if ( V_5 -> V_5 . V_88 == NULL ) {
V_54 = - V_62 ;
goto V_92;
}
V_5 -> V_5 . V_41 . V_44 = V_60 ;
V_5 -> V_5 . V_41 . V_93 = V_57 ;
V_54 = F_26 ( & V_5 -> V_5 , & V_5 -> V_5 . V_29 ) ;
if ( V_54 )
goto V_94;
V_54 = F_27 ( V_5 -> V_1 , F_1 , V_95 ,
V_53 -> V_96 , V_5 ) ;
if ( V_54 )
goto V_97;
F_11 ( V_10 , V_5 -> V_8 + V_98 ) ;
F_12 ( & V_5 -> V_5 . V_29 , & V_5 -> V_5 ) ;
V_54 = F_28 ( & V_5 -> V_5 ) ;
if ( V_54 )
goto V_99;
return 0 ;
V_99:
F_29 ( V_5 -> V_1 , V_5 ) ;
V_97:
V_94:
F_30 ( & V_53 -> V_91 , V_57 ,
( void * ) V_5 -> V_5 . V_88 ,
V_5 -> V_5 . V_41 . V_44 ) ;
V_92:
V_69:
F_31 ( V_5 -> V_8 ) ;
V_66:
F_32 ( V_5 ) ;
V_63:
return V_54 ;
}
static int F_33 ( struct V_52 * V_53 )
{
T_3 V_57 ;
struct V_4 * V_5 = F_34 ( V_53 ) ;
V_57 = V_5 -> V_5 . V_29 . V_34 * V_5 -> V_5 . V_29 . V_35 * 2 ;
F_35 ( & V_5 -> V_5 ) ;
F_29 ( V_5 -> V_1 , V_5 ) ;
F_30 ( & V_53 -> V_91 , V_57 , ( void * ) V_5 -> V_5 . V_88 ,
V_5 -> V_5 . V_41 . V_44 ) ;
F_31 ( V_5 -> V_8 ) ;
return 0 ;
}
