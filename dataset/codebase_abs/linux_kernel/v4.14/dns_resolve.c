T_1 F_1 ( struct V_1 * V_1 , char * V_2 , T_2 V_3 ,
struct V_4 * V_5 , T_2 V_6 )
{
T_1 V_7 ;
char * V_8 = NULL ;
int V_9 ;
V_9 = F_2 ( NULL , V_2 , V_3 , NULL , & V_8 , NULL ) ;
if ( V_9 > 0 )
V_7 = F_3 ( V_1 , V_8 , V_9 , V_5 , V_6 ) ;
else
V_7 = - V_10 ;
F_4 ( V_8 ) ;
return V_7 ;
}
static void F_5 ( struct V_11 * V_12 ,
struct V_11 * V_13 )
{
struct V_14 * V_15 ;
struct V_14 * V_16 ;
V_15 = F_6 ( V_12 , struct V_14 , V_17 ) ;
V_16 = F_6 ( V_13 , struct V_14 , V_17 ) ;
memcpy ( & V_15 -> V_18 , & V_16 -> V_18 , V_16 -> V_19 ) ;
V_15 -> V_19 = V_16 -> V_19 ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_11 * V_13 )
{
struct V_14 * V_15 ;
struct V_14 * V_16 ;
V_15 = F_6 ( V_12 , struct V_14 , V_17 ) ;
V_16 = F_6 ( V_13 , struct V_14 , V_17 ) ;
F_4 ( V_15 -> V_20 ) ;
V_15 -> V_20 = F_8 ( V_16 -> V_20 , V_16 -> V_3 , V_21 ) ;
if ( V_15 -> V_20 ) {
V_15 -> V_3 = V_16 -> V_3 ;
F_5 ( V_12 , V_13 ) ;
} else {
V_15 -> V_3 = 0 ;
V_15 -> V_19 = 0 ;
}
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_14 * V_24 ;
V_24 = F_6 ( V_23 , struct V_14 , V_17 . V_23 ) ;
F_4 ( V_24 -> V_20 ) ;
F_4 ( V_24 ) ;
}
static struct V_11 * F_10 ( void )
{
struct V_14 * V_24 = F_11 ( sizeof( * V_24 ) , V_21 ) ;
if ( V_24 != NULL ) {
V_24 -> V_20 = NULL ;
V_24 -> V_3 = 0 ;
V_24 -> V_19 = 0 ;
return & V_24 -> V_17 ;
}
return NULL ;
}
static unsigned int F_12 ( const struct V_14 * V_16 )
{
return F_13 ( V_16 -> V_20 , V_25 ) ;
}
static void F_14 ( struct V_26 * V_27 ,
struct V_11 * V_28 ,
char * * V_29 , int * V_30 )
{
struct V_14 * V_16 = F_6 ( V_28 , struct V_14 , V_17 ) ;
F_15 ( V_29 , V_30 , V_16 -> V_20 ) ;
( * V_29 ) [ - 1 ] = '\n' ;
}
static int F_16 ( struct V_26 * V_27 ,
struct V_11 * V_28 )
{
struct V_14 * V_16 = F_6 ( V_28 , struct V_14 , V_17 ) ;
int V_7 ;
V_7 = F_17 ( V_27 , V_16 -> V_20 ) ;
if ( V_7 )
V_7 = F_18 ( V_27 , V_28 ) ;
return V_7 ;
}
static int F_19 ( struct V_11 * V_31 ,
struct V_11 * V_32 )
{
struct V_14 * V_33 ;
struct V_14 * V_34 ;
V_33 = F_6 ( V_31 , struct V_14 , V_17 ) ;
V_34 = F_6 ( V_32 , struct V_14 , V_17 ) ;
if ( V_33 -> V_3 == 0 || V_33 -> V_3 != V_34 -> V_3 )
return 0 ;
return memcmp ( V_33 -> V_20 , V_34 -> V_20 , V_33 -> V_3 ) == 0 ;
}
static int F_20 ( struct V_35 * V_36 , struct V_26 * V_27 ,
struct V_11 * V_17 )
{
struct V_14 * V_24 ;
long V_37 ;
if ( V_17 == NULL ) {
F_21 ( V_36 , L_1 ) ;
return 0 ;
}
V_24 = F_6 ( V_17 , struct V_14 , V_17 ) ;
V_37 = V_24 -> V_17 . V_38 - F_22 () ;
if ( V_37 < 0 )
V_37 = 0 ;
if ( ! F_23 ( V_39 , & V_17 -> V_40 ) ) {
char V_41 [ V_42 + V_43 + 1 ] ;
F_24 ( (struct V_4 * ) & V_24 -> V_18 , V_41 , sizeof( V_41 ) ) ;
F_25 ( V_36 , L_2 , V_41 ) ;
} else
F_21 ( V_36 , L_3 ) ;
F_25 ( V_36 , L_4 , V_24 -> V_20 , V_37 ) ;
return 0 ;
}
static struct V_14 * F_26 ( struct V_26 * V_27 ,
struct V_14 * V_16 )
{
struct V_11 * V_28 ;
V_28 = F_27 ( V_27 ,
& V_16 -> V_17 ,
F_12 ( V_16 ) ) ;
if ( ! V_28 )
return NULL ;
return F_6 ( V_28 , struct V_14 , V_17 ) ;
}
static struct V_14 * F_28 ( struct V_26 * V_27 ,
struct V_14 * V_15 ,
struct V_14 * V_16 )
{
struct V_11 * V_28 ;
V_28 = F_29 ( V_27 ,
& V_15 -> V_17 , & V_16 -> V_17 ,
F_12 ( V_16 ) ) ;
if ( ! V_28 )
return NULL ;
return F_6 ( V_28 , struct V_14 , V_17 ) ;
}
static int F_30 ( struct V_26 * V_27 , char * V_41 , int V_44 )
{
char V_45 [ V_46 + 1 ] ;
struct V_14 V_16 , * V_24 ;
unsigned int V_37 ;
T_1 V_47 ;
int V_7 = - V_48 ;
if ( V_41 [ V_44 - 1 ] != '\n' )
goto V_49;
V_41 [ V_44 - 1 ] = '\0' ;
V_47 = F_31 ( & V_41 , V_45 , sizeof( V_45 ) ) ;
if ( V_47 <= 0 )
goto V_49;
V_16 . V_19 = F_3 ( V_27 -> V_1 , V_45 , V_47 ,
(struct V_4 * ) & V_16 . V_18 ,
sizeof( V_16 . V_18 ) ) ;
V_47 = F_31 ( & V_41 , V_45 , sizeof( V_45 ) ) ;
if ( V_47 <= 0 )
goto V_49;
V_16 . V_20 = V_45 ;
V_16 . V_3 = V_47 ;
memset ( & V_16 . V_17 , 0 , sizeof( V_16 . V_17 ) ) ;
if ( F_32 ( & V_41 , & V_37 ) < 0 )
goto V_49;
if ( V_37 == 0 )
goto V_49;
V_16 . V_17 . V_38 = V_37 + F_22 () ;
V_7 = - V_50 ;
V_24 = F_26 ( V_27 , & V_16 ) ;
if ( V_24 == NULL )
goto V_49;
if ( V_16 . V_19 == 0 )
F_33 ( V_39 , & V_16 . V_17 . V_40 ) ;
V_24 = F_28 ( V_27 , & V_16 , V_24 ) ;
if ( V_24 == NULL )
goto V_49;
V_7 = 0 ;
F_34 ( & V_24 -> V_17 , V_27 ) ;
V_49:
return V_7 ;
}
static int F_35 ( struct V_26 * V_27 ,
struct V_14 * V_16 ,
struct V_14 * * V_24 ,
struct V_51 * V_52 )
{
int V_7 = - V_50 ;
* V_24 = F_26 ( V_27 , V_16 ) ;
if ( * V_24 ) {
V_7 = F_36 ( V_27 , & ( * V_24 ) -> V_17 , & V_52 -> V_53 ) ;
if ( V_7 )
* V_24 = NULL ;
}
return V_7 ;
}
static int F_37 ( struct V_26 * V_27 ,
struct V_14 * V_16 ,
struct V_14 * * V_24 )
{
int V_7 = - V_50 ;
* V_24 = F_26 ( V_27 , V_16 ) ;
if ( ! * V_24 )
goto V_54;
V_7 = - V_55 ;
if ( ! F_23 ( V_56 , & ( * V_24 ) -> V_17 . V_40 )
|| ( * V_24 ) -> V_17 . V_38 < F_22 ()
|| V_27 -> V_57 > ( * V_24 ) -> V_17 . V_58 )
goto V_59;
V_7 = - V_60 ;
if ( F_23 ( V_39 , & ( * V_24 ) -> V_17 . V_40 ) )
goto V_59;
return 0 ;
V_59:
F_34 ( & ( * V_24 ) -> V_17 , V_27 ) ;
V_54:
* V_24 = NULL ;
return V_7 ;
}
static int F_38 ( struct V_26 * V_27 ,
struct V_14 * V_16 ,
struct V_14 * * V_24 )
{
struct V_51 * V_52 ;
int V_7 = - V_50 ;
V_52 = F_39 () ;
if ( ! V_52 )
goto V_49;
V_7 = F_35 ( V_27 , V_16 , V_24 , V_52 ) ;
if ( V_7 == - V_61 ) {
V_7 = F_40 ( V_52 ) ;
if ( ! V_7 )
V_7 = F_37 ( V_27 , V_16 , V_24 ) ;
}
F_41 ( V_52 ) ;
V_49:
return V_7 ;
}
T_1 F_1 ( struct V_1 * V_1 , char * V_2 ,
T_2 V_3 , struct V_4 * V_5 , T_2 V_6 )
{
struct V_14 V_16 = {
. V_20 = V_2 ,
. V_3 = V_3 ,
} ;
struct V_14 * V_24 = NULL ;
T_1 V_7 ;
struct V_62 * V_63 = F_42 ( V_1 , V_64 ) ;
V_7 = F_38 ( V_63 -> V_65 , & V_16 , & V_24 ) ;
if ( V_7 == 0 ) {
if ( V_6 >= V_24 -> V_19 ) {
memcpy ( V_5 , & V_24 -> V_18 , V_24 -> V_19 ) ;
V_7 = V_24 -> V_19 ;
} else
V_7 = - V_66 ;
F_34 ( & V_24 -> V_17 , V_63 -> V_65 ) ;
} else if ( V_7 == - V_60 )
V_7 = - V_10 ;
return V_7 ;
}
int F_43 ( struct V_1 * V_1 )
{
int V_67 ;
struct V_62 * V_63 = F_42 ( V_1 , V_64 ) ;
V_63 -> V_65 = F_44 ( & V_68 , V_1 ) ;
if ( F_45 ( V_63 -> V_65 ) )
return F_46 ( V_63 -> V_65 ) ;
V_67 = F_47 ( V_1 , V_63 -> V_65 ) ;
if ( V_67 )
goto V_69;
return 0 ;
V_69:
F_48 ( V_63 -> V_65 , V_1 ) ;
return V_67 ;
}
void F_49 ( struct V_1 * V_1 )
{
struct V_62 * V_63 = F_42 ( V_1 , V_64 ) ;
F_50 ( V_1 , V_63 -> V_65 ) ;
F_48 ( V_63 -> V_65 , V_1 ) ;
}
static int F_51 ( struct V_1 * V_1 )
{
return F_43 ( V_1 ) ;
}
static void F_52 ( struct V_1 * V_1 )
{
F_49 ( V_1 ) ;
}
static int F_53 ( struct V_70 * V_71 , unsigned long V_72 ,
void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_1 * V_1 = V_75 -> V_76 ;
struct V_62 * V_63 = F_42 ( V_1 , V_64 ) ;
struct V_26 * V_27 = V_63 -> V_65 ;
int V_7 = 0 ;
if ( V_27 == NULL )
return 0 ;
if ( ! F_54 ( V_77 ) )
return 0 ;
switch ( V_72 ) {
case V_78 :
V_7 = F_55 ( V_75 , V_27 ) ;
break;
case V_79 :
F_56 ( V_75 , V_27 ) ;
break;
default:
V_7 = - V_80 ;
break;
}
F_57 ( V_77 ) ;
return V_7 ;
}
int F_58 ( void )
{
int V_67 ;
V_67 = F_59 ( & V_81 ) ;
if ( V_67 < 0 )
goto V_49;
V_67 = F_60 ( & V_82 ) ;
if ( V_67 < 0 )
goto V_83;
return 0 ;
V_83:
F_61 ( & V_81 ) ;
V_49:
return V_67 ;
}
void F_62 ( void )
{
F_63 ( & V_82 ) ;
F_61 ( & V_81 ) ;
}
