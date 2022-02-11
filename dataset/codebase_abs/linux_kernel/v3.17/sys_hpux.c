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
struct F_12 V_14 ;
struct V_15 V_16 ;
int V_17 = F_13 ( V_12 , & V_16 ) ;
if ( V_17 )
goto V_18;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_19 = ( V_20 ) V_16 . V_21 ;
V_14 . V_22 = ( V_23 ) V_16 . V_24 ;
V_14 . V_25 = ( V_23 ) V_16 . V_26 ;
V_17 = F_14 ( V_13 , & V_14 , sizeof( V_14 ) ) ? - V_27 : 0 ;
V_18:
return V_17 ;
}
static int F_15 ( struct V_15 * V_28 , struct V_29 T_1 * V_30 )
{
struct V_29 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = V_28 -> V_32 ;
V_31 . V_26 = V_28 -> V_26 ;
V_31 . V_33 = V_28 -> V_33 ;
V_31 . V_21 = V_28 -> V_21 ;
V_31 . V_34 = V_28 -> V_34 ;
V_31 . V_35 = V_28 -> V_35 ;
V_31 . V_24 = V_28 -> V_24 ;
V_31 . V_36 [ 0 ] = V_28 -> V_36 . V_37 [ 0 ] ;
V_31 . V_36 [ 1 ] = V_28 -> V_36 . V_37 [ 1 ] ;
if ( F_14 ( V_30 , & V_31 , sizeof( V_31 ) ) )
return - V_27 ;
return 0 ;
}
T_3 long V_29 ( const char T_1 * V_38 ,
struct V_29 T_1 * V_31 )
{
struct V_15 V_28 ;
int error = F_16 ( V_38 , & V_28 ) ;
if ( ! error )
error = F_15 ( & V_28 , V_31 ) ;
return error ;
}
T_3 long F_17 ( unsigned int V_39 , struct V_29 T_1 * V_31 )
{
struct V_15 V_28 ;
int error = F_18 ( V_39 , & V_28 ) ;
if ( ! error )
error = F_15 ( & V_28 , V_31 ) ;
return error ;
}
static int F_19 ( struct V_40 T_1 * V_41 )
{
int error ;
if ( ! V_41 )
return - V_27 ;
if ( ! F_20 ( V_42 , V_41 , sizeof( struct V_40 ) ) )
return - V_27 ;
F_21 ( & V_43 ) ;
error = F_22 ( & V_41 -> V_44 , & F_23 () -> V_44 ,
V_45 - 1 ) ;
error |= F_24 ( 0 , V_41 -> V_44 + V_45 - 1 ) ;
error |= F_22 ( & V_41 -> V_46 , & F_23 () -> V_46 ,
V_45 - 1 ) ;
error |= F_24 ( 0 , V_41 -> V_46 + V_45 - 1 ) ;
error |= F_22 ( & V_41 -> V_47 , & F_23 () -> V_47 ,
V_45 - 1 ) ;
error |= F_24 ( 0 , V_41 -> V_47 + V_45 - 1 ) ;
error |= F_22 ( & V_41 -> V_48 , & F_23 () -> V_48 ,
V_45 - 1 ) ;
error |= F_24 ( 0 , V_41 -> V_48 + V_45 - 1 ) ;
error |= F_22 ( & V_41 -> V_49 , & F_23 () -> V_49 ,
V_45 - 1 ) ;
error |= F_24 ( 0 , V_41 -> V_49 + V_45 - 1 ) ;
F_25 ( & V_43 ) ;
#if 0
error |= __put_user(0,name->idnumber);
error |= __put_user(0,name->idnumber+HPUX_SNLEN-1);
#endif
error = error ? - V_27 : 0 ;
return error ;
}
int F_26 ( char T_1 * V_13 , int V_50 , int type )
{
int V_51 ;
int error ;
switch( type ) {
case 0 :
return F_19 ( (struct V_40 T_1 * ) V_13 ) ;
break ;
case 1 :
return - V_27 ;
break ;
case 2 :
return F_12 ( F_27 ( V_50 ) ,
(struct F_12 T_1 * ) V_13 ) ;
break;
case 3 :
if ( ! F_28 ( V_52 ) )
return - V_53 ;
if ( V_50 <= 0 )
return - V_11 ;
V_51 = ( V_50 <= V_54 ) ? V_50 : V_54 ;
return F_29 ( V_13 , V_51 ) ;
break ;
case 4 :
if ( ! F_28 ( V_52 ) )
return - V_53 ;
if ( V_50 <= 0 )
return - V_11 ;
V_51 = ( V_50 <= V_54 ) ? V_50 : V_54 ;
return F_29 ( V_13 , V_51 ) ;
break ;
case 5 :
if ( V_50 <= 0 )
return - V_11 ;
return F_30 ( V_13 , V_50 ) ;
break ;
case 6 :
if ( ! F_28 ( V_52 ) )
return - V_53 ;
if ( V_50 <= 0 )
return - V_11 ;
V_51 = ( V_50 <= V_54 ) ? V_50 : V_54 ;
F_31 ( & V_43 ) ;
error = - V_27 ;
if ( ! F_32 ( F_23 () -> V_44 , V_13 , V_51 ) ) {
F_23 () -> V_44 [ V_51 ] = 0 ;
error = 0 ;
}
F_33 ( & V_43 ) ;
return error ;
break ;
case 7 :
if ( ! F_28 ( V_52 ) )
return - V_53 ;
if ( V_50 <= 0 )
return - V_11 ;
V_51 = ( V_50 <= V_54 ) ? V_50 : V_54 ;
F_31 ( & V_43 ) ;
error = - V_27 ;
if ( ! F_32 ( F_23 () -> V_47 , V_13 , V_51 ) ) {
F_23 () -> V_47 [ V_51 ] = 0 ;
error = 0 ;
}
F_33 ( & V_43 ) ;
return error ;
break ;
default:
return - V_27 ;
}
}
int F_34 ( char T_1 * V_41 , int V_51 )
{
int V_55 ;
int V_17 = - V_27 ;
F_21 ( & V_43 ) ;
V_55 = strlen ( F_23 () -> V_56 ) + 1 ;
if ( V_55 < V_51 )
V_51 = V_55 ;
if( V_51 > V_54 )
goto V_57;
if( F_14 ( V_41 , F_23 () -> V_56 , V_51 ) )
goto V_57;
V_17 = 0 ;
V_57:
F_25 ( & V_43 ) ;
return V_17 ;
}
int F_35 ( int * V_58 )
{
return F_36 ( V_58 , 0 ) ;
}
int F_37 ( int V_59 , int V_60 , T_4 V_61 )
{
return 0 ;
}
int F_38 ( int V_62 , unsigned long V_63 , unsigned long V_64 )
{
char * V_65 = NULL ;
int V_51 = 0 ;
int V_66 ;
F_39 ( V_67 L_1 ) ;
F_39 ( V_67 L_2 , V_62 ) ;
F_39 ( V_67 L_3 , V_63 ) ;
if ( V_62 == 1 ) {
char T_1 * V_68 = ( char T_1 * ) V_63 ;
V_51 = F_40 ( V_68 ) ;
F_39 ( V_67 L_4 , V_51 ) ;
if ( V_51 == 0 )
return 0 ;
V_65 = F_41 ( V_51 , V_69 ) ;
if ( ! V_65 ) {
F_39 ( V_67 L_5 ) ;
return 0 ;
}
if ( F_32 ( V_65 , V_68 , V_51 ) ) {
F_39 ( V_67 L_6 ) ;
F_42 ( V_65 ) ;
return 0 ;
}
V_65 [ V_51 - 1 ] = '\0' ;
F_39 ( V_67 L_7 , V_65 ) ;
if ( ! strcmp ( V_65 , L_8 ) ) {
V_66 = 0 ;
} else {
V_66 = 0 ;
}
F_42 ( V_65 ) ;
F_39 ( V_67 L_9 , V_66 ) ;
return V_66 ;
}
return 0 ;
}
int
F_43 ( unsigned long V_63 , unsigned long V_64 , unsigned long V_70 ,
unsigned long V_71 , unsigned long V_72 , unsigned long V_73 ,
unsigned long V_74 , unsigned long V_75 )
{
const char * V_41 = NULL ;
if ( V_75 <= V_76 && V_75 >= 0 ) {
V_41 = V_77 [ V_75 ] ;
}
if ( V_41 ) {
F_39 ( V_67 L_10 ,
V_75 , V_41 ) ;
} else {
F_39 ( V_67 L_11 ,
V_75 ) ;
}
F_39 ( V_67 L_12 ,
V_63 , V_64 , V_70 , V_71 , V_72 , V_73 , V_74 ) ;
return - V_3 ;
}
