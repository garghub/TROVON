T_1 unsigned long F_1 ( void )
{
return V_1 ;
}
unsigned long F_2 ( struct V_2 * V_3 , unsigned long V_4 , unsigned long V_5 , unsigned long V_6 , unsigned long V_7 )
{
struct V_8 V_9 ;
if ( V_7 & V_10 ) {
if ( ( V_7 & V_11 ) &&
( ( V_4 - ( V_6 << V_12 ) ) & ( V_13 - 1 ) ) )
return - V_14 ;
return V_4 ;
}
if ( V_5 > V_15 - V_1 )
return - V_16 ;
if ( ! V_4 )
V_4 = V_17 ;
V_9 . V_7 = 0 ;
V_9 . V_18 = V_5 ;
V_9 . V_19 = V_4 ;
V_9 . V_20 = V_15 ;
V_9 . V_21 = ( V_7 & V_11 ) ?
( V_22 & ( V_13 - 1 ) ) : 0 ;
V_9 . V_23 = V_6 << V_12 ;
return F_3 ( & V_9 ) ;
}
T_1 int F_4 ( struct V_24 * V_25 )
{
int V_26 [ 2 ] ;
int error ;
error = F_5 ( V_26 , 0 ) ;
if ( error )
goto V_27;
V_25 -> V_28 [ V_29 ] = V_26 [ 1 ] ;
error = V_26 [ 0 ] ;
V_27:
return error ;
}
int F_6 ( unsigned long V_4 , unsigned long V_5 )
{
if ( V_5 > V_15 - V_1 || V_4 + V_5 > V_15 - V_1 )
return - V_14 ;
return 0 ;
}
T_1 unsigned long F_7 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_30 , unsigned long V_7 , unsigned long V_26 ,
unsigned long V_6 )
{
return F_8 ( V_4 , V_5 , V_30 , V_7 , V_26 ,
V_6 >> ( V_12 - 12 ) ) ;
}
T_1 unsigned long F_9 ( unsigned long V_4 , unsigned long V_5 ,
unsigned long V_30 , unsigned long V_7 , unsigned long V_26 ,
unsigned long V_31 )
{
return F_8 ( V_4 , V_5 , V_30 , V_7 , V_26 , V_31 >> V_12 ) ;
}
long F_10 ( unsigned long V_32 , unsigned long V_33 ,
unsigned long V_30 , unsigned long V_6 ,
unsigned long V_7 )
{
return F_11 ( V_32 , V_33 , V_30 ,
( V_6 >> ( V_12 - 12 ) ) , V_7 ) ;
}
T_1 unsigned long
F_12 ( struct V_24 * V_25 )
{
static int V_34 = 0 ;
if ( V_34 ++ > 5 )
return - V_35 ;
F_13 ( L_1 ,
V_36 -> V_37 , F_14 ( V_36 ) , ( int ) V_25 -> V_28 [ 1 ] ) ;
#ifdef F_15
F_16 ( V_25 ) ;
#endif
return - V_35 ;
}
T_1 void
F_17 ( struct V_24 * V_25 )
{
T_2 V_9 ;
#ifdef F_18
F_13 ( L_2 , V_25 -> V_38 , V_25 -> V_39 ) ;
#endif
V_9 . V_40 = V_41 ;
V_9 . V_42 = 0 ;
V_9 . V_43 = V_44 ;
V_9 . V_45 = ( void V_46 * ) V_25 -> V_38 ;
V_9 . V_47 = 0 ;
F_19 ( V_41 , & V_9 , V_36 ) ;
#ifdef F_18
F_13 ( L_3 , V_25 -> V_38 , V_25 -> V_39 ) ;
#endif
}
T_1 int
F_20 ( int V_48 , const struct V_49 V_46 * V_50 ,
struct V_49 V_46 * V_51 )
{
struct V_52 V_53 , V_54 ;
int V_55 ;
F_21 ( V_48 >= 0 ) ;
V_48 = - V_48 ;
if ( V_50 ) {
unsigned long V_56 ;
if ( ! F_22 ( V_57 , V_50 , sizeof( * V_50 ) ) ||
F_23 ( V_53 . V_58 . V_59 , & V_50 -> V_59 ) ||
F_23 ( V_53 . V_58 . V_60 , & V_50 -> V_60 ) ||
F_23 ( V_53 . V_58 . V_61 , & V_50 -> V_61 ) ||
F_23 ( V_56 , & V_50 -> V_62 ) )
return - V_63 ;
F_24 ( & V_53 . V_58 . V_62 , V_56 ) ;
V_53 . V_64 = NULL ;
}
V_55 = F_25 ( V_48 , V_50 ? & V_53 : NULL , V_51 ? & V_54 : NULL ) ;
if ( ! V_55 && V_51 ) {
if ( ! F_22 ( V_65 , V_51 , sizeof( * V_51 ) ) ||
F_26 ( V_54 . V_58 . V_59 , & V_51 -> V_59 ) ||
F_26 ( V_54 . V_58 . V_60 , & V_51 -> V_60 ) ||
F_26 ( V_54 . V_58 . V_61 , & V_51 -> V_61 ) ||
F_26 ( V_54 . V_58 . V_62 . V_48 [ 0 ] , & V_51 -> V_62 ) )
return - V_63 ;
}
return V_55 ;
}
T_1 long
F_27 ( int V_48 ,
const struct V_66 V_46 * V_50 ,
struct V_66 V_46 * V_51 ,
void V_46 * V_67 ,
T_3 V_68 )
{
struct V_52 V_53 , V_54 ;
int V_55 ;
if ( V_68 != sizeof( V_69 ) )
return - V_14 ;
if ( V_50 ) {
V_53 . V_64 = V_67 ;
if ( F_28 ( & V_53 . V_58 , V_50 , sizeof( * V_50 ) ) )
return - V_63 ;
}
V_55 = F_25 ( V_48 , V_50 ? & V_53 : NULL , V_51 ? & V_54 : NULL ) ;
if ( ! V_55 && V_51 ) {
if ( F_29 ( V_51 , & V_54 . V_58 , sizeof( * V_51 ) ) )
return - V_63 ;
}
return V_55 ;
}
T_1 int F_30 ( char V_46 * V_70 , int V_5 )
{
int V_71 , V_72 ;
if ( V_5 < 0 )
return - V_14 ;
F_31 ( & V_73 ) ;
V_71 = strlen ( F_32 () -> V_74 ) + 1 ;
V_72 = - V_14 ;
if ( V_71 > V_5 )
goto V_27;
V_72 = - V_63 ;
if ( ! F_29 ( V_70 , F_32 () -> V_74 , V_71 ) )
V_72 = 0 ;
V_27:
F_33 ( & V_73 ) ;
return V_72 ;
}
