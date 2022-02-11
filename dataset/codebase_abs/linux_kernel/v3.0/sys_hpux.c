unsigned long F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 + V_2 ) ;
}
int F_3 ( void )
{
return - V_3 ;
}
int F_4 ( int V_4 )
{
return - V_3 ;
}
int F_5 ( void )
{
return - V_3 ;
}
int F_6 ( int T_1 * V_5 )
{
return F_7 ( - 1 , V_5 , 0 ) ;
}
int F_8 ( void )
{
return F_9 ( 0 , 0 ) ;
}
int F_10 ( void )
{
return F_8 () ;
}
int F_11 ( int V_6 )
{
switch ( V_6 ) {
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
default:
return - V_11 ;
}
}
static int F_12 ( T_2 V_12 , struct F_12 T_1 * V_13 )
{
struct V_14 * V_15 ;
struct F_12 V_16 ;
struct V_17 V_18 ;
int V_19 = - V_11 ;
V_15 = F_13 ( V_12 ) ;
if ( V_15 == NULL )
goto V_20;
V_19 = F_14 ( V_15 -> V_21 , & V_18 ) ;
F_15 ( V_15 ) ;
if ( V_19 )
goto V_20;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_22 = ( V_23 ) V_18 . V_24 ;
V_16 . V_25 = ( V_26 ) V_18 . V_27 ;
V_16 . V_28 = ( V_26 ) V_18 . V_29 ;
V_19 = F_16 ( V_13 , & V_16 , sizeof( V_16 ) ) ? - V_30 : 0 ;
V_20:
return V_19 ;
}
static int F_17 ( struct V_17 * V_31 , struct V_32 T_1 * V_33 )
{
struct V_32 V_34 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_35 = V_31 -> V_35 ;
V_34 . V_29 = V_31 -> V_29 ;
V_34 . V_36 = V_31 -> V_36 ;
V_34 . V_24 = V_31 -> V_24 ;
V_34 . V_37 = V_31 -> V_37 ;
V_34 . V_38 = V_31 -> V_38 ;
V_34 . V_27 = V_31 -> V_27 ;
V_34 . V_39 [ 0 ] = V_31 -> V_39 . V_40 [ 0 ] ;
V_34 . V_39 [ 1 ] = V_31 -> V_39 . V_40 [ 1 ] ;
if ( F_16 ( V_33 , & V_34 , sizeof( V_34 ) ) )
return - V_30 ;
return 0 ;
}
T_3 long V_32 ( const char T_1 * V_41 ,
struct V_32 T_1 * V_34 )
{
struct V_17 V_31 ;
int error = F_18 ( V_41 , & V_31 ) ;
if ( ! error )
error = F_17 ( & V_31 , V_34 ) ;
return error ;
}
T_3 long F_19 ( unsigned int V_42 , struct V_32 T_1 * V_34 )
{
struct V_17 V_31 ;
int error = F_20 ( V_42 , & V_31 ) ;
if ( ! error )
error = F_17 ( & V_31 , V_34 ) ;
return error ;
}
static int F_21 ( struct V_43 T_1 * V_44 )
{
int error ;
if ( ! V_44 )
return - V_30 ;
if ( ! F_22 ( V_45 , V_44 , sizeof( struct V_43 ) ) )
return - V_30 ;
F_23 ( & V_46 ) ;
error = F_24 ( & V_44 -> V_47 , & F_25 () -> V_47 ,
V_48 - 1 ) ;
error |= F_26 ( 0 , V_44 -> V_47 + V_48 - 1 ) ;
error |= F_24 ( & V_44 -> V_49 , & F_25 () -> V_49 ,
V_48 - 1 ) ;
error |= F_26 ( 0 , V_44 -> V_49 + V_48 - 1 ) ;
error |= F_24 ( & V_44 -> V_50 , & F_25 () -> V_50 ,
V_48 - 1 ) ;
error |= F_26 ( 0 , V_44 -> V_50 + V_48 - 1 ) ;
error |= F_24 ( & V_44 -> V_51 , & F_25 () -> V_51 ,
V_48 - 1 ) ;
error |= F_26 ( 0 , V_44 -> V_51 + V_48 - 1 ) ;
error |= F_24 ( & V_44 -> V_52 , & F_25 () -> V_52 ,
V_48 - 1 ) ;
error |= F_26 ( 0 , V_44 -> V_52 + V_48 - 1 ) ;
F_27 ( & V_46 ) ;
#if 0
error |= __put_user(0,name->idnumber);
error |= __put_user(0,name->idnumber+HPUX_SNLEN-1);
#endif
error = error ? - V_30 : 0 ;
return error ;
}
int F_28 ( char T_1 * V_13 , int V_53 , int type )
{
int V_54 ;
int error ;
switch( type ) {
case 0 :
return F_21 ( (struct V_43 T_1 * ) V_13 ) ;
break ;
case 1 :
return - V_30 ;
break ;
case 2 :
return F_12 ( F_29 ( V_53 ) ,
(struct F_12 T_1 * ) V_13 ) ;
break;
case 3 :
if ( ! F_30 ( V_55 ) )
return - V_56 ;
if ( V_53 <= 0 )
return - V_11 ;
V_54 = ( V_53 <= V_57 ) ? V_53 : V_57 ;
return F_31 ( V_13 , V_54 ) ;
break ;
case 4 :
if ( ! F_30 ( V_55 ) )
return - V_56 ;
if ( V_53 <= 0 )
return - V_11 ;
V_54 = ( V_53 <= V_57 ) ? V_53 : V_57 ;
return F_31 ( V_13 , V_54 ) ;
break ;
case 5 :
if ( V_53 <= 0 )
return - V_11 ;
return F_32 ( V_13 , V_53 ) ;
break ;
case 6 :
if ( ! F_30 ( V_55 ) )
return - V_56 ;
if ( V_53 <= 0 )
return - V_11 ;
V_54 = ( V_53 <= V_57 ) ? V_53 : V_57 ;
F_33 ( & V_46 ) ;
error = - V_30 ;
if ( ! F_34 ( F_25 () -> V_47 , V_13 , V_54 ) ) {
F_25 () -> V_47 [ V_54 ] = 0 ;
error = 0 ;
}
F_35 ( & V_46 ) ;
return error ;
break ;
case 7 :
if ( ! F_30 ( V_55 ) )
return - V_56 ;
if ( V_53 <= 0 )
return - V_11 ;
V_54 = ( V_53 <= V_57 ) ? V_53 : V_57 ;
F_33 ( & V_46 ) ;
error = - V_30 ;
if ( ! F_34 ( F_25 () -> V_50 , V_13 , V_54 ) ) {
F_25 () -> V_50 [ V_54 ] = 0 ;
error = 0 ;
}
F_35 ( & V_46 ) ;
return error ;
break ;
default:
return - V_30 ;
}
}
int F_36 ( char T_1 * V_44 , int V_54 )
{
int V_58 ;
int V_19 = - V_30 ;
F_23 ( & V_46 ) ;
V_58 = strlen ( F_25 () -> V_59 ) + 1 ;
if ( V_58 < V_54 )
V_54 = V_58 ;
if( V_54 > V_57 )
goto V_60;
if( F_16 ( V_44 , F_25 () -> V_59 , V_54 ) )
goto V_60;
V_19 = 0 ;
V_60:
F_27 ( & V_46 ) ;
return V_19 ;
}
int F_37 ( int * V_61 )
{
return F_38 ( V_61 , 0 ) ;
}
int F_39 ( int V_62 , int V_63 , T_4 V_64 )
{
return 0 ;
}
int F_40 ( int V_65 , unsigned long V_66 , unsigned long V_67 )
{
char * V_68 = NULL ;
int V_54 = 0 ;
int V_69 ;
F_41 ( V_70 L_1 ) ;
F_41 ( V_70 L_2 , V_65 ) ;
F_41 ( V_70 L_3 , V_66 ) ;
if ( V_65 == 1 ) {
char T_1 * V_71 = ( char T_1 * ) V_66 ;
V_54 = F_42 ( V_71 ) ;
F_41 ( V_70 L_4 , V_54 ) ;
if ( V_54 == 0 )
return 0 ;
V_68 = F_43 ( V_54 , V_72 ) ;
if ( ! V_68 ) {
F_41 ( V_70 L_5 ) ;
return 0 ;
}
if ( F_34 ( V_68 , V_71 , V_54 ) ) {
F_41 ( V_70 L_6 ) ;
F_44 ( V_68 ) ;
return 0 ;
}
V_68 [ V_54 ] = '\0' ;
F_41 ( V_70 L_7 , V_68 ) ;
if ( ! strcmp ( V_68 , L_8 ) ) {
V_69 = 0 ;
} else {
V_69 = 0 ;
}
F_44 ( V_68 ) ;
F_41 ( V_70 L_9 , V_69 ) ;
return V_69 ;
}
return 0 ;
}
int
F_45 ( unsigned long V_66 , unsigned long V_67 , unsigned long V_73 ,
unsigned long V_74 , unsigned long V_75 , unsigned long V_76 ,
unsigned long V_77 , unsigned long V_78 )
{
const char * V_44 = NULL ;
if ( V_78 <= V_79 && V_78 >= 0 ) {
V_44 = V_80 [ V_78 ] ;
}
if ( V_44 ) {
F_41 ( V_70 L_10 ,
V_78 , V_44 ) ;
} else {
F_41 ( V_70 L_11 ,
V_78 ) ;
}
F_41 ( V_70 L_12 ,
V_66 , V_67 , V_73 , V_74 , V_75 , V_76 , V_77 ) ;
return - V_3 ;
}
