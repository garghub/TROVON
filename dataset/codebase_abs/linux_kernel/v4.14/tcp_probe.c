static inline int F_1 ( void )
{
return ( V_1 . V_2 - V_1 . V_3 ) & ( V_4 - 1 ) ;
}
static inline int F_2 ( void )
{
return V_4 - F_1 () - 1 ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
unsigned int V_11 = V_8 -> V_11 ;
const struct V_12 * V_13 = F_4 ( V_6 ) ;
const struct V_14 * V_15 = F_5 ( V_6 ) ;
if ( ( ( V_16 == 0 && V_17 == 0 ) ||
F_6 ( V_15 -> V_18 ) == V_16 ||
F_6 ( V_15 -> V_19 ) == V_16 ||
( V_17 > 0 && V_8 -> V_20 == V_17 ) ) &&
( V_21 || V_13 -> V_22 != V_1 . V_23 ) ) {
F_7 ( & V_1 . V_24 ) ;
if ( F_2 () > 1 ) {
struct V_25 * V_26 = V_1 . log + V_1 . V_2 ;
V_26 -> V_27 = F_8 () ;
switch ( V_6 -> V_28 ) {
case V_29 :
F_9 ( V_15 , V_26 -> V_30 . V_31 , V_32 ) ;
F_9 ( V_15 , V_26 -> V_33 . V_31 , V_34 ) ;
break;
case V_35 :
memset ( & V_26 -> V_30 . V_36 , 0 , sizeof( V_26 -> V_30 . V_36 ) ) ;
memset ( & V_26 -> V_33 . V_36 , 0 , sizeof( V_26 -> V_33 . V_36 ) ) ;
#if F_10 ( V_37 )
V_26 -> V_30 . V_36 . V_38 = V_35 ;
V_26 -> V_30 . V_36 . V_39 = V_15 -> V_19 ;
V_26 -> V_30 . V_36 . V_40 = F_11 ( V_6 ) -> V_41 ;
V_26 -> V_33 . V_36 . V_38 = V_35 ;
V_26 -> V_33 . V_36 . V_39 = V_15 -> V_18 ;
V_26 -> V_33 . V_36 . V_40 = V_6 -> V_42 ;
#endif
break;
default:
F_12 () ;
}
V_26 -> V_43 = V_11 ;
V_26 -> V_44 = V_13 -> V_44 ;
V_26 -> V_45 = V_13 -> V_45 ;
V_26 -> V_22 = V_13 -> V_22 ;
V_26 -> V_46 = V_13 -> V_46 ;
V_26 -> V_47 = V_13 -> V_47 ;
V_26 -> V_48 = F_13 ( V_6 ) ;
V_26 -> V_49 = V_13 -> V_50 >> 3 ;
V_1 . V_2 = ( V_1 . V_2 + 1 ) & ( V_4 - 1 ) ;
}
V_1 . V_23 = V_13 -> V_22 ;
F_14 ( & V_1 . V_24 ) ;
F_15 ( & V_1 . V_51 ) ;
}
F_16 () ;
}
static int F_17 ( struct V_52 * V_52 , struct V_53 * V_53 )
{
F_18 ( & V_1 . V_24 ) ;
V_1 . V_2 = V_1 . V_3 = 0 ;
V_1 . V_54 = F_8 () ;
F_19 ( & V_1 . V_24 ) ;
return 0 ;
}
static int F_20 ( char * V_55 , int V_56 )
{
const struct V_25 * V_26
= V_1 . log + V_1 . V_3 ;
struct V_57 V_58
= F_21 ( F_22 ( V_26 -> V_27 , V_1 . V_54 ) ) ;
return F_23 ( V_55 , V_56 ,
L_1 ,
( unsigned long ) V_58 . V_59 ,
( unsigned long ) V_58 . V_60 ,
& V_26 -> V_30 , & V_26 -> V_33 , V_26 -> V_43 , V_26 -> V_44 , V_26 -> V_45 ,
V_26 -> V_22 , V_26 -> V_48 , V_26 -> V_46 , V_26 -> V_49 , V_26 -> V_47 ) ;
}
static T_1 F_24 ( struct V_53 * V_53 , char T_2 * V_61 ,
T_3 V_11 , T_4 * V_62 )
{
int error = 0 ;
T_3 V_63 = 0 ;
if ( ! V_61 )
return - V_64 ;
while ( V_63 < V_11 ) {
char V_55 [ 256 ] ;
int V_65 ;
error = F_25 ( V_1 . V_51 ,
F_1 () > 0 ) ;
if ( error )
break;
F_18 ( & V_1 . V_24 ) ;
if ( V_1 . V_2 == V_1 . V_3 ) {
F_19 ( & V_1 . V_24 ) ;
continue;
}
V_65 = F_20 ( V_55 , sizeof( V_55 ) ) ;
if ( V_63 + V_65 < V_11 )
V_1 . V_3 = ( V_1 . V_3 + 1 ) & ( V_4 - 1 ) ;
F_19 ( & V_1 . V_24 ) ;
if ( V_63 + V_65 >= V_11 )
break;
if ( F_26 ( V_61 + V_63 , V_55 , V_65 ) )
return - V_66 ;
V_63 += V_65 ;
}
return V_63 == 0 ? error : V_63 ;
}
static T_5 int F_27 ( void )
{
int V_67 = - V_68 ;
F_28 ( F_29 ( V_69 ,
F_3 ) == 0 ) ;
F_30 ( & V_1 . V_51 ) ;
F_31 ( & V_1 . V_24 ) ;
if ( V_4 == 0 )
return - V_64 ;
V_4 = F_32 ( V_4 ) ;
V_1 . log = F_33 ( V_4 , sizeof( struct V_25 ) , V_70 ) ;
if ( ! V_1 . log )
goto V_71;
if ( ! F_34 ( V_72 , V_73 , V_74 . V_75 , & V_76 ) )
goto V_71;
V_67 = F_35 ( & V_77 ) ;
if ( V_67 )
goto V_78;
F_36 ( L_2 ,
V_16 , V_17 , V_4 ) ;
return 0 ;
V_78:
F_37 ( V_72 , V_74 . V_75 ) ;
V_71:
F_38 ( V_1 . log ) ;
return V_67 ;
}
static T_6 void F_39 ( void )
{
F_37 ( V_72 , V_74 . V_75 ) ;
F_40 ( & V_77 ) ;
F_38 ( V_1 . log ) ;
}
