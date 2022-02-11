int F_1 ( void * V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = - V_4 ;
if ( F_2 ( V_5 , & V_6 ) )
goto V_7;
V_3 = - V_8 ;
if ( V_2 > V_9 )
goto V_10;
memcpy ( V_11 , V_1 , V_2 ) ;
V_12 |= V_13 ;
F_3 ( L_1 ) ;
return 0 ;
V_10:
F_4 ( V_5 , & V_6 ) ;
V_7:
F_5 ( L_2 ) ;
return V_3 ;
}
static struct V_14 * F_6 ( char type )
{
long V_3 ;
char * V_15 ;
struct V_16 * * V_17 ;
struct V_14 * V_18 ;
if ( type == V_19 ) {
if ( ! ( V_12 & V_13 ) ) {
F_5 ( L_3 ) ;
return F_7 ( - V_20 ) ;
}
V_17 = & V_21 ;
V_15 = V_22 ;
} else {
V_17 = & V_23 ;
V_15 = V_24 ;
}
if ( * V_17 == NULL ) {
F_8 ( & V_25 ) ;
if ( * V_17 )
goto V_26;
* V_17 = F_9 ( V_15 , 0 , V_27 ) ;
if ( F_10 ( * V_17 ) ) {
V_3 = F_11 ( * V_17 ) ;
F_5 ( L_4 , V_15 , V_3 ) ;
* V_17 = NULL ;
F_12 ( & V_25 ) ;
return F_7 ( V_3 ) ;
}
if ( type == V_19 ) {
V_3 = F_13 ( * V_17 , V_11 , V_28 ) ;
if ( V_3 ) {
F_14 ( * V_17 ) ;
* V_17 = NULL ;
F_12 ( & V_25 ) ;
return F_7 ( V_3 ) ;
}
}
V_26:
F_12 ( & V_25 ) ;
}
V_18 = F_15 ( sizeof( * V_18 ) + F_16 ( * V_17 ) ,
V_29 ) ;
if ( ! V_18 )
return F_7 ( - V_30 ) ;
V_18 -> V_17 = * V_17 ;
V_18 -> V_31 = V_32 ;
V_3 = F_17 ( V_18 ) ;
if ( V_3 ) {
F_18 ( V_18 ) ;
return F_7 ( V_3 ) ;
}
return V_18 ;
}
static void F_19 ( struct V_14 * V_18 , struct V_33 * V_33 ,
char * V_34 )
{
struct V_35 {
unsigned long V_36 ;
T_2 V_37 ;
T_3 V_38 ;
T_4 V_39 ;
T_5 V_40 ;
} V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_36 = V_33 -> V_42 ;
V_41 . V_37 = V_33 -> V_43 ;
V_41 . V_38 = F_20 ( & V_44 , V_33 -> V_45 ) ;
V_41 . V_39 = F_21 ( & V_44 , V_33 -> V_46 ) ;
V_41 . V_40 = V_33 -> V_47 ;
F_22 ( V_18 , ( const V_48 * ) & V_41 , sizeof( V_41 ) ) ;
if ( V_49 & V_50 )
F_22 ( V_18 , V_33 -> V_51 -> V_52 ,
sizeof( V_33 -> V_51 -> V_52 ) ) ;
F_23 ( V_18 , V_34 ) ;
}
static int F_24 ( struct V_53 * V_53 ,
const char * V_54 ,
const char * V_55 ,
T_1 V_56 ,
char type , char * V_34 )
{
struct V_33 * V_33 = F_25 ( V_53 ) ;
struct V_14 * V_18 ;
char * * V_57 ;
T_1 V_58 = 0 ;
char * V_59 = NULL ;
int error ;
int V_60 ;
if ( ! V_33 -> V_61 -> V_62 )
return - V_63 ;
V_18 = F_6 ( type ) ;
if ( F_10 ( V_18 ) )
return F_11 ( V_18 ) ;
error = - V_64 ;
for ( V_57 = V_65 ; * V_57 != NULL ; V_57 ++ ) {
if ( ( V_54 && V_55 )
&& ! strcmp ( * V_57 , V_54 ) ) {
error = 0 ;
F_22 ( V_18 , ( const V_48 * ) V_55 ,
V_56 ) ;
continue;
}
V_60 = F_26 ( V_53 , * V_57 ,
& V_59 , V_58 , V_66 ) ;
if ( V_60 == - V_30 ) {
error = - V_30 ;
goto V_26;
}
if ( V_60 < 0 )
continue;
error = 0 ;
V_58 = V_60 ;
F_22 ( V_18 , ( const V_48 * ) V_59 , V_58 ) ;
}
F_19 ( V_18 , V_33 , V_34 ) ;
V_26:
F_18 ( V_59 ) ;
F_18 ( V_18 ) ;
return error ;
}
int F_27 ( struct V_53 * V_53 , const char * V_54 ,
const char * V_55 , T_1 V_56 ,
char * V_34 )
{
return F_24 ( V_53 , V_54 , V_55 ,
V_56 , V_19 , V_34 ) ;
}
int F_28 ( struct V_53 * V_53 , const char * V_54 ,
const char * V_55 , T_1 V_56 ,
char * V_34 )
{
return F_24 ( V_53 , V_54 , V_55 ,
V_56 , V_67 , V_34 ) ;
}
int F_29 ( struct V_53 * V_53 , const char * V_68 ,
const char * V_59 , T_1 V_69 )
{
struct V_33 * V_33 = F_25 ( V_53 ) ;
struct V_70 V_71 ;
int V_3 = 0 ;
V_3 = F_27 ( V_53 , V_68 , V_59 ,
V_69 , V_71 . V_34 ) ;
if ( V_3 == 0 ) {
V_71 . type = V_19 ;
V_3 = F_30 ( V_53 , V_72 ,
& V_71 ,
sizeof( V_71 ) , 0 ) ;
} else if ( V_3 == - V_64 && V_33 -> V_61 -> V_73 ) {
V_3 = V_33 -> V_61 -> V_73 ( V_53 , V_72 ) ;
}
return V_3 ;
}
int F_31 ( struct V_33 * V_33 , const struct V_74 * V_75 ,
char * V_76 )
{
struct V_14 * V_18 ;
V_18 = F_6 ( V_19 ) ;
if ( F_10 ( V_18 ) ) {
F_3 ( L_5 ) ;
return F_11 ( V_18 ) ;
}
F_22 ( V_18 , V_75 -> V_77 , V_75 -> V_78 ) ;
F_19 ( V_18 , V_33 , V_76 ) ;
F_18 ( V_18 ) ;
return 0 ;
}
int F_32 ( void )
{
struct V_1 * V_79 ;
struct V_80 * V_81 ;
int V_3 ;
V_79 = F_33 ( & V_82 , V_83 , NULL ) ;
if ( F_10 ( V_79 ) )
return - V_84 ;
F_34 ( & V_79 -> V_85 ) ;
V_81 = V_79 -> V_86 . V_87 [ 0 ] ;
V_3 = F_1 ( V_81 -> V_88 , V_81 -> V_89 ) ;
memset ( V_81 -> V_88 , 0 , V_81 -> V_89 ) ;
F_35 ( & V_79 -> V_85 ) ;
F_36 ( V_79 ) ;
return V_3 ;
}
