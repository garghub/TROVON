static int F_1 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( F_3 ( V_2 ) ) ;
V_7 = F_4 ( V_5 ) ;
if ( F_5 ( V_7 ) ) {
F_6 ( V_5 ) ;
return F_7 ( V_7 ) ;
}
V_8 = F_8 ( V_1 , V_5 , V_7 , V_3 ) ;
F_9 ( V_7 ) ;
F_6 ( V_5 ) ;
return V_8 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_2 * V_11 ,
T_3 V_12 , T_3 V_13 )
{
struct V_14 * V_14 = F_11 ( V_11 ) ;
struct V_15 * V_16 = F_12 ( V_14 ) ;
struct V_17 args = {
. V_18 = F_13 ( V_14 ) ,
. V_19 = V_12 ,
. V_20 = V_13 ,
. V_21 = V_16 -> V_22 ,
} ;
struct V_23 V_24 = {
. V_25 = V_16 ,
} ;
int V_26 ;
V_10 -> V_27 = & args ;
V_10 -> V_28 = & V_24 ;
V_26 = F_1 ( & args . V_29 , V_11 , V_30 ) ;
if ( V_26 )
return V_26 ;
V_24 . V_31 = F_14 () ;
if ( ! V_24 . V_31 )
return - V_32 ;
V_26 = F_15 ( V_16 -> V_33 , V_16 , V_10 ,
& args . V_34 , & V_24 . V_35 , 0 ) ;
if ( V_26 == 0 )
V_26 = F_16 ( V_14 , V_24 . V_31 ) ;
F_17 ( V_24 . V_31 ) ;
return V_26 ;
}
static int F_18 ( struct V_9 * V_10 , struct V_2 * V_11 ,
T_3 V_12 , T_3 V_13 )
{
struct V_15 * V_16 = F_12 ( F_11 ( V_11 ) ) ;
struct V_36 V_37 = { } ;
int V_38 ;
do {
V_38 = F_10 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( V_38 == - V_39 )
return - V_40 ;
V_38 = F_19 ( V_16 , V_38 , & V_37 ) ;
} while ( V_37 . V_41 );
return V_38 ;
}
int F_20 ( struct V_2 * V_11 , T_3 V_12 , T_3 V_13 )
{
struct V_9 V_10 = {
. V_42 = & V_43 [ V_44 ] ,
} ;
struct V_14 * V_14 = F_11 ( V_11 ) ;
int V_38 ;
if ( ! F_21 ( V_14 , V_45 ) )
return - V_40 ;
F_22 ( & V_14 -> V_46 ) ;
V_38 = F_18 ( & V_10 , V_11 , V_12 , V_13 ) ;
if ( V_38 == - V_40 )
F_12 ( V_14 ) -> V_47 &= ~ V_45 ;
F_23 ( & V_14 -> V_46 ) ;
return V_38 ;
}
int F_24 ( struct V_2 * V_11 , T_3 V_12 , T_3 V_13 )
{
struct V_9 V_10 = {
. V_42 = & V_43 [ V_48 ] ,
} ;
struct V_14 * V_14 = F_11 ( V_11 ) ;
int V_38 ;
if ( ! F_21 ( V_14 , V_49 ) )
return - V_40 ;
F_25 ( V_14 ) ;
F_22 ( & V_14 -> V_46 ) ;
V_38 = F_18 ( & V_10 , V_11 , V_12 , V_13 ) ;
if ( V_38 == 0 )
F_26 ( V_14 , V_12 , ( V_12 + V_13 ) - 1 ) ;
if ( V_38 == - V_40 )
F_12 ( V_14 ) -> V_47 &= ~ V_49 ;
F_23 ( & V_14 -> V_46 ) ;
return V_38 ;
}
static T_3 F_27 ( struct V_2 * V_11 , T_3 V_12 , int V_50 )
{
struct V_14 * V_14 = F_11 ( V_11 ) ;
struct V_51 args = {
. V_52 = F_13 ( V_14 ) ,
. V_53 = V_12 ,
. V_54 = ( V_50 == V_55 ) ?
V_56 : V_57 ,
} ;
struct V_58 V_24 ;
struct V_9 V_10 = {
. V_42 = & V_43 [ V_59 ] ,
. V_27 = & args ,
. V_28 = & V_24 ,
} ;
struct V_15 * V_16 = F_12 ( V_14 ) ;
int V_26 ;
if ( ! F_21 ( V_14 , V_60 ) )
return - V_39 ;
V_26 = F_1 ( & args . V_61 , V_11 , V_62 ) ;
if ( V_26 )
return V_26 ;
F_25 ( V_14 ) ;
V_26 = F_15 ( V_16 -> V_33 , V_16 , & V_10 ,
& args . V_34 , & V_24 . V_35 , 0 ) ;
if ( V_26 == - V_39 )
V_16 -> V_47 &= ~ V_60 ;
if ( V_26 )
return V_26 ;
return F_28 ( V_11 , V_24 . V_63 , V_14 -> V_64 -> V_65 ) ;
}
T_3 F_29 ( struct V_2 * V_11 , T_3 V_12 , int V_50 )
{
struct V_15 * V_16 = F_12 ( F_11 ( V_11 ) ) ;
struct V_36 V_37 = { } ;
int V_38 ;
do {
V_38 = F_27 ( V_11 , V_12 , V_50 ) ;
if ( V_38 == - V_39 )
return - V_40 ;
V_38 = F_19 ( V_16 , V_38 , & V_37 ) ;
} while ( V_37 . V_41 );
return V_38 ;
}
static void
F_30 ( struct V_66 * V_67 , void * V_68 )
{
struct V_69 * V_70 = V_68 ;
struct V_15 * V_16 = F_12 ( V_70 -> args . V_14 ) ;
F_31 ( F_32 ( V_16 ) , & V_70 -> args . V_34 ,
& V_70 -> V_24 . V_35 , V_67 ) ;
}
static void
F_33 ( struct V_66 * V_67 , void * V_68 )
{
struct V_69 * V_70 = V_68 ;
if ( ! F_34 ( V_67 , & V_70 -> V_24 . V_35 ) )
return;
switch ( V_67 -> V_71 ) {
case 0 :
break;
case - V_39 :
case - V_40 :
F_12 ( V_70 -> V_14 ) -> V_47 &= ~ V_72 ;
default:
F_35 ( L_1 , V_73 , V_67 -> V_71 ) ;
}
}
static void
F_36 ( void * V_68 )
{
struct V_69 * V_70 = V_68 ;
struct V_15 * V_74 = F_12 ( V_70 -> args . V_14 ) ;
if ( V_74 -> V_75 -> V_76 )
V_74 -> V_75 -> V_76 ( V_70 ) ;
F_37 ( F_38 ( V_70 -> args . V_14 ) -> V_77 ) ;
F_39 () ;
F_40 ( V_78 , & F_38 ( V_70 -> args . V_14 ) -> V_79 ) ;
F_41 () ;
F_42 ( V_70 -> V_14 ) ;
F_17 ( V_70 -> args . V_80 ) ;
F_17 ( V_70 ) ;
}
int F_43 ( struct V_15 * V_16 ,
struct V_69 * V_70 )
{
struct V_9 V_10 = {
. V_42 = & V_43 [ V_81 ] ,
. V_27 = & V_70 -> args ,
. V_28 = & V_70 -> V_24 ,
} ;
struct V_82 V_83 = {
. V_84 = V_16 -> V_33 ,
. V_9 = & V_10 ,
. V_85 = & V_86 ,
. V_87 = V_70 ,
. V_79 = V_88 ,
} ;
struct V_66 * V_67 ;
V_70 -> V_14 = F_44 ( V_70 -> args . V_14 ) ;
if ( ! V_70 -> V_14 ) {
F_36 ( V_70 ) ;
return - V_89 ;
}
F_45 ( & V_70 -> args . V_34 , & V_70 -> V_24 . V_35 , 0 ) ;
V_67 = F_46 ( & V_83 ) ;
if ( F_5 ( V_67 ) )
return F_7 ( V_67 ) ;
return 0 ;
}
