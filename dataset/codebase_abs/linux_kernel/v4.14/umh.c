static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
(* V_2 -> V_3 )( V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
struct V_5 * V_6 = F_4 ( & V_4 -> V_7 , NULL ) ;
if ( V_6 )
V_7 ( V_6 ) ;
else
F_1 ( V_4 ) ;
}
static int F_5 ( void * V_8 )
{
struct V_1 * V_4 = V_8 ;
struct V_9 * V_10 ;
int V_11 ;
F_6 ( & V_12 -> V_13 -> V_14 ) ;
F_7 ( V_12 , 1 ) ;
F_8 ( & V_12 -> V_13 -> V_14 ) ;
F_9 ( V_12 , 0 ) ;
V_11 = - V_15 ;
V_10 = F_10 ( V_12 ) ;
if ( ! V_10 )
goto V_16;
F_11 ( & V_17 ) ;
V_10 -> V_18 = F_12 ( V_19 , V_10 -> V_18 ) ;
V_10 -> V_20 = F_12 ( V_21 ,
V_10 -> V_20 ) ;
F_13 ( & V_17 ) ;
if ( V_4 -> V_22 ) {
V_11 = V_4 -> V_22 ( V_4 , V_10 ) ;
if ( V_11 ) {
F_14 ( V_10 ) ;
goto V_16;
}
}
F_15 ( V_10 ) ;
V_11 = F_16 ( F_17 ( V_4 -> V_23 ) ,
( const char V_24 * const V_24 * ) V_4 -> V_25 ,
( const char V_24 * const V_24 * ) V_4 -> V_26 ) ;
V_16:
V_4 -> V_11 = V_11 ;
if ( ! ( V_4 -> V_27 & V_28 ) )
F_3 ( V_4 ) ;
if ( ! V_11 )
return 0 ;
F_18 ( 0 ) ;
}
static void F_19 ( struct V_1 * V_4 )
{
T_1 V_29 ;
F_20 ( V_30 , V_31 ) ;
V_29 = F_21 ( F_5 , V_4 , V_30 ) ;
if ( V_29 < 0 ) {
V_4 -> V_11 = V_29 ;
} else {
int V_32 = - V_33 ;
F_22 ( V_29 , ( int V_24 * ) & V_32 , 0 , NULL ) ;
if ( V_32 )
V_4 -> V_11 = V_32 ;
}
F_20 ( V_30 , V_34 ) ;
F_3 ( V_4 ) ;
}
static void F_23 ( struct V_35 * V_36 )
{
struct V_1 * V_4 =
F_24 ( V_36 , struct V_1 , V_36 ) ;
if ( V_4 -> V_27 & V_28 ) {
F_19 ( V_4 ) ;
} else {
T_1 V_29 ;
V_29 = F_21 ( F_5 , V_4 ,
V_37 | V_30 ) ;
if ( V_29 < 0 ) {
V_4 -> V_11 = V_29 ;
F_3 ( V_4 ) ;
}
}
}
int F_25 ( void )
{
F_26 ( V_27 ) ;
int V_32 = 0 ;
F_27 ( & V_38 ) ;
for (; ; ) {
F_28 ( & V_39 , & V_27 ,
V_40 ) ;
if ( ! V_41 )
break;
if ( V_41 == V_42 )
V_32 = - V_43 ;
F_29 ( & V_38 ) ;
if ( V_32 )
break;
F_30 () ;
F_31 () ;
F_27 ( & V_38 ) ;
}
F_32 ( & V_39 , & V_27 ) ;
return V_32 ;
}
long F_33 ( long V_44 )
{
F_26 ( V_27 ) ;
if ( V_44 < 0 )
return - V_45 ;
F_27 ( & V_38 ) ;
for (; ; ) {
F_28 ( & V_39 , & V_27 ,
V_46 ) ;
if ( ! V_41 )
break;
F_29 ( & V_38 ) ;
V_44 = F_34 ( V_44 ) ;
if ( ! V_44 )
break;
F_27 ( & V_38 ) ;
}
F_32 ( & V_39 , & V_27 ) ;
return V_44 ;
}
void F_35 ( void )
{
F_29 ( & V_38 ) ;
}
void F_36 ( enum V_47 V_48 )
{
F_37 ( & V_38 ) ;
V_41 = V_48 ;
F_38 ( & V_39 ) ;
F_39 ( & V_38 ) ;
}
int F_40 ( enum V_47 V_48 )
{
long V_11 ;
if ( ! V_48 )
return - V_45 ;
F_37 ( & V_38 ) ;
V_41 = V_48 ;
F_39 ( & V_38 ) ;
V_11 = F_41 ( V_49 ,
F_42 ( & V_50 ) == 0 ,
V_51 ) ;
if ( V_11 )
return 0 ;
F_36 ( V_52 ) ;
return - V_43 ;
}
static void F_43 ( void )
{
F_44 ( & V_50 ) ;
F_45 () ;
}
static void F_46 ( void )
{
if ( F_47 ( & V_50 ) )
F_38 ( & V_49 ) ;
}
struct V_1 * F_48 ( const char * V_23 , char * * V_25 ,
char * * V_26 , T_2 V_53 ,
int (* V_22)( struct V_1 * V_2 , struct V_9 * V_10 ) ,
void (* V_3)( struct V_1 * V_2 ) ,
void * V_8 )
{
struct V_1 * V_4 ;
V_4 = F_49 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_4 )
goto V_16;
F_50 ( & V_4 -> V_36 , F_23 ) ;
#ifdef F_51
V_4 -> V_23 = V_54 ;
#else
V_4 -> V_23 = V_23 ;
#endif
V_4 -> V_25 = V_25 ;
V_4 -> V_26 = V_26 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_8 = V_8 ;
V_16:
return V_4 ;
}
int F_52 ( struct V_1 * V_4 , int V_27 )
{
F_53 ( V_55 ) ;
int V_11 = 0 ;
if ( ! V_4 -> V_23 ) {
F_1 ( V_4 ) ;
return - V_45 ;
}
F_43 () ;
if ( V_41 ) {
V_11 = - V_56 ;
goto V_16;
}
if ( strlen ( V_4 -> V_23 ) == 0 )
goto V_16;
V_4 -> V_7 = ( V_27 == V_57 ) ? NULL : & V_55 ;
V_4 -> V_27 = V_27 ;
F_54 ( V_58 , & V_4 -> V_36 ) ;
if ( V_27 == V_57 )
goto V_59;
if ( V_27 & V_60 ) {
V_11 = F_55 ( & V_55 ) ;
if ( ! V_11 )
goto V_61;
if ( F_4 ( & V_4 -> V_7 , NULL ) )
goto V_59;
}
F_56 ( & V_55 ) ;
V_61:
V_11 = V_4 -> V_11 ;
V_16:
F_1 ( V_4 ) ;
V_59:
F_46 () ;
return V_11 ;
}
int F_57 ( const char * V_23 , char * * V_25 , char * * V_26 , int V_27 )
{
struct V_1 * V_2 ;
T_2 V_53 = ( V_27 == V_57 ) ? V_62 : V_63 ;
V_2 = F_48 ( V_23 , V_25 , V_26 , V_53 ,
NULL , NULL , NULL ) ;
if ( V_2 == NULL )
return - V_15 ;
return F_52 ( V_2 , V_27 ) ;
}
static int F_58 ( struct V_64 * V_65 , int V_66 ,
void V_24 * V_67 , T_3 * V_68 , T_4 * V_69 )
{
struct V_64 V_70 ;
unsigned long V_71 [ V_72 ] ;
T_5 V_73 ;
int V_74 , V_75 ;
if ( V_66 && ( ! F_59 ( V_76 ) ||
! F_59 ( V_77 ) ) )
return - V_78 ;
F_11 ( & V_17 ) ;
for ( V_75 = 0 ; V_75 < V_72 ; V_75 ++ ) {
if ( V_65 -> V_8 == V_79 )
V_71 [ V_75 ] = V_19 . V_80 [ V_75 ] ;
else if ( V_65 -> V_8 == V_81 )
V_71 [ V_75 ] = V_21 . V_80 [ V_75 ] ;
else
F_60 () ;
}
F_13 ( & V_17 ) ;
V_70 = * V_65 ;
V_70 . V_8 = & V_71 ;
V_74 = F_61 ( & V_70 , V_66 , V_67 , V_68 , V_69 ) ;
if ( V_74 < 0 )
return V_74 ;
for ( V_75 = 0 ; V_75 < V_72 ; V_75 ++ )
V_73 . V_80 [ V_75 ] = V_71 [ V_75 ] ;
F_11 ( & V_17 ) ;
if ( V_66 ) {
if ( V_65 -> V_8 == V_79 )
V_19 = F_12 ( V_19 , V_73 ) ;
if ( V_65 -> V_8 == V_81 )
V_21 = F_12 ( V_21 , V_73 ) ;
}
F_13 ( & V_17 ) ;
return 0 ;
}
