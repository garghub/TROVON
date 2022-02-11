static inline int F_1 ( void )
{
return ( V_1 . V_2 - V_1 . V_3 ) & ( V_4 - 1 ) ;
}
static inline int F_2 ( void )
{
return V_4 - F_1 () - 1 ;
}
static int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , unsigned int V_11 )
{
const struct V_12 * V_13 = F_4 ( V_6 ) ;
const struct V_14 * V_15 = F_5 ( V_6 ) ;
if ( ( V_16 == 0 || F_6 ( V_15 -> V_17 ) == V_16 ||
F_6 ( V_15 -> V_18 ) == V_16 ) &&
( V_19 || V_13 -> V_20 != V_1 . V_21 ) ) {
F_7 ( & V_1 . V_22 ) ;
if ( F_2 () > 1 ) {
struct V_23 * V_24 = V_1 . log + V_1 . V_2 ;
V_24 -> V_25 = F_8 () ;
V_24 -> V_26 = V_15 -> V_27 ;
V_24 -> V_28 = V_15 -> V_18 ;
V_24 -> V_29 = V_15 -> V_30 ;
V_24 -> V_31 = V_15 -> V_17 ;
V_24 -> V_32 = V_8 -> V_11 ;
V_24 -> V_33 = V_13 -> V_33 ;
V_24 -> V_34 = V_13 -> V_34 ;
V_24 -> V_20 = V_13 -> V_20 ;
V_24 -> V_35 = V_13 -> V_35 ;
V_24 -> V_36 = F_9 ( V_6 ) ;
V_24 -> V_37 = V_13 -> V_37 >> 3 ;
V_1 . V_2 = ( V_1 . V_2 + 1 ) & ( V_4 - 1 ) ;
}
V_1 . V_21 = V_13 -> V_20 ;
F_10 ( & V_1 . V_22 ) ;
F_11 ( & V_1 . V_38 ) ;
}
F_12 () ;
return 0 ;
}
static int F_13 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
F_14 ( & V_1 . V_22 ) ;
V_1 . V_2 = V_1 . V_3 = 0 ;
V_1 . V_41 = F_8 () ;
F_15 ( & V_1 . V_22 ) ;
return 0 ;
}
static int F_16 ( char * V_42 , int V_43 )
{
const struct V_23 * V_24
= V_1 . log + V_1 . V_3 ;
struct V_44 V_45
= F_17 ( F_18 ( V_24 -> V_25 , V_1 . V_41 ) ) ;
return F_19 ( V_42 , V_43 ,
L_1 ,
( unsigned long ) V_45 . V_46 ,
( unsigned long ) V_45 . V_47 ,
& V_24 -> V_26 , F_6 ( V_24 -> V_28 ) ,
& V_24 -> V_29 , F_6 ( V_24 -> V_31 ) ,
V_24 -> V_32 , V_24 -> V_33 , V_24 -> V_34 ,
V_24 -> V_20 , V_24 -> V_36 , V_24 -> V_35 , V_24 -> V_37 ) ;
}
static T_1 F_20 ( struct V_40 * V_40 , char T_2 * V_48 ,
T_3 V_11 , T_4 * V_49 )
{
int error = 0 ;
T_3 V_50 = 0 ;
if ( ! V_48 )
return - V_51 ;
while ( V_50 < V_11 ) {
char V_42 [ 164 ] ;
int V_52 ;
error = F_21 ( V_1 . V_38 ,
F_1 () > 0 ) ;
if ( error )
break;
F_14 ( & V_1 . V_22 ) ;
if ( V_1 . V_2 == V_1 . V_3 ) {
F_15 ( & V_1 . V_22 ) ;
continue;
}
V_52 = F_16 ( V_42 , sizeof( V_42 ) ) ;
if ( V_50 + V_52 < V_11 )
V_1 . V_3 = ( V_1 . V_3 + 1 ) & ( V_4 - 1 ) ;
F_15 ( & V_1 . V_22 ) ;
if ( V_50 + V_52 >= V_11 )
break;
if ( F_22 ( V_48 + V_50 , V_42 , V_52 ) )
return - V_53 ;
V_50 += V_52 ;
}
return V_50 == 0 ? error : V_50 ;
}
static T_5 int F_23 ( void )
{
int V_54 = - V_55 ;
F_24 ( & V_1 . V_38 ) ;
F_25 ( & V_1 . V_22 ) ;
if ( V_4 == 0 )
return - V_51 ;
V_4 = F_26 ( V_4 ) ;
V_1 . log = F_27 ( V_4 , sizeof( struct V_23 ) , V_56 ) ;
if ( ! V_1 . log )
goto V_57;
if ( ! F_28 ( & V_58 , V_59 , V_60 , & V_61 ) )
goto V_57;
V_54 = F_29 ( & V_62 ) ;
if ( V_54 )
goto V_63;
F_30 ( L_2 , V_16 , V_4 ) ;
return 0 ;
V_63:
F_31 ( & V_58 , V_59 ) ;
V_57:
F_32 ( V_1 . log ) ;
return V_54 ;
}
static T_6 void F_33 ( void )
{
F_31 ( & V_58 , V_59 ) ;
F_34 ( & V_62 ) ;
F_32 ( V_1 . log ) ;
}
