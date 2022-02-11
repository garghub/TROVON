static inline int F_1 ( void )
{
return ( V_1 . V_2 - V_1 . V_3 ) & ( V_4 - 1 ) ;
}
static inline int F_2 ( void )
{
return V_4 - F_1 () - 1 ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 , unsigned int V_11 )
{
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
F_10 ( V_15 , V_26 -> V_30 . V_36 , V_32 ) ;
F_10 ( V_15 , V_26 -> V_33 . V_36 , V_34 ) ;
break;
default:
F_11 () ;
}
V_26 -> V_37 = V_8 -> V_11 ;
V_26 -> V_38 = V_13 -> V_38 ;
V_26 -> V_39 = V_13 -> V_39 ;
V_26 -> V_22 = V_13 -> V_22 ;
V_26 -> V_40 = V_13 -> V_40 ;
V_26 -> V_41 = V_13 -> V_41 ;
V_26 -> V_42 = F_12 ( V_6 ) ;
V_26 -> V_43 = V_13 -> V_43 >> 3 ;
V_1 . V_2 = ( V_1 . V_2 + 1 ) & ( V_4 - 1 ) ;
}
V_1 . V_23 = V_13 -> V_22 ;
F_13 ( & V_1 . V_24 ) ;
F_14 ( & V_1 . V_44 ) ;
}
F_15 () ;
}
static int F_16 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
F_17 ( & V_1 . V_24 ) ;
V_1 . V_2 = V_1 . V_3 = 0 ;
V_1 . V_47 = F_8 () ;
F_18 ( & V_1 . V_24 ) ;
return 0 ;
}
static int F_19 ( char * V_48 , int V_49 )
{
const struct V_25 * V_26
= V_1 . log + V_1 . V_3 ;
struct V_50 V_51
= F_20 ( F_21 ( V_26 -> V_27 , V_1 . V_47 ) ) ;
return F_22 ( V_48 , V_49 ,
L_1 ,
( unsigned long ) V_51 . V_52 ,
( unsigned long ) V_51 . V_53 ,
& V_26 -> V_30 , & V_26 -> V_33 , V_26 -> V_37 , V_26 -> V_38 , V_26 -> V_39 ,
V_26 -> V_22 , V_26 -> V_42 , V_26 -> V_40 , V_26 -> V_43 , V_26 -> V_41 ) ;
}
static T_1 F_23 ( struct V_46 * V_46 , char T_2 * V_54 ,
T_3 V_11 , T_4 * V_55 )
{
int error = 0 ;
T_3 V_56 = 0 ;
if ( ! V_54 )
return - V_57 ;
while ( V_56 < V_11 ) {
char V_48 [ 256 ] ;
int V_58 ;
error = F_24 ( V_1 . V_44 ,
F_1 () > 0 ) ;
if ( error )
break;
F_17 ( & V_1 . V_24 ) ;
if ( V_1 . V_2 == V_1 . V_3 ) {
F_18 ( & V_1 . V_24 ) ;
continue;
}
V_58 = F_19 ( V_48 , sizeof( V_48 ) ) ;
if ( V_56 + V_58 < V_11 )
V_1 . V_3 = ( V_1 . V_3 + 1 ) & ( V_4 - 1 ) ;
F_18 ( & V_1 . V_24 ) ;
if ( V_56 + V_58 >= V_11 )
break;
if ( F_25 ( V_54 + V_56 , V_48 , V_58 ) )
return - V_59 ;
V_56 += V_58 ;
}
return V_56 == 0 ? error : V_56 ;
}
static T_5 int F_26 ( void )
{
int V_60 = - V_61 ;
F_27 ( F_28 ( V_62 ,
F_3 ) == 0 ) ;
F_29 ( & V_1 . V_44 ) ;
F_30 ( & V_1 . V_24 ) ;
if ( V_4 == 0 )
return - V_57 ;
V_4 = F_31 ( V_4 ) ;
V_1 . log = F_32 ( V_4 , sizeof( struct V_25 ) , V_63 ) ;
if ( ! V_1 . log )
goto V_64;
if ( ! F_33 ( V_65 , V_66 , V_67 . V_68 , & V_69 ) )
goto V_64;
V_60 = F_34 ( & V_70 ) ;
if ( V_60 )
goto V_71;
F_35 ( L_2 ,
V_16 , V_17 , V_4 ) ;
return 0 ;
V_71:
F_36 ( V_65 , V_67 . V_68 ) ;
V_64:
F_37 ( V_1 . log ) ;
return V_60 ;
}
static T_6 void F_38 ( void )
{
F_36 ( V_65 , V_67 . V_68 ) ;
F_39 ( & V_70 ) ;
F_37 ( V_1 . log ) ;
}
