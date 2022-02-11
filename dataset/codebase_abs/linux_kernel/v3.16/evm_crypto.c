static struct V_1 * F_1 ( char type )
{
long V_2 ;
char * V_3 ;
struct V_4 * * V_5 ;
struct V_1 * V_6 ;
if ( type == V_7 ) {
V_5 = & V_8 ;
V_3 = V_9 ;
} else {
V_5 = & V_10 ;
V_3 = V_11 ;
}
if ( * V_5 == NULL ) {
F_2 ( & V_12 ) ;
if ( * V_5 )
goto V_13;
* V_5 = F_3 ( V_3 , 0 , V_14 ) ;
if ( F_4 ( * V_5 ) ) {
V_2 = F_5 ( * V_5 ) ;
F_6 ( L_1 , V_3 , V_2 ) ;
* V_5 = NULL ;
F_7 ( & V_12 ) ;
return F_8 ( V_2 ) ;
}
if ( type == V_7 ) {
V_2 = F_9 ( * V_5 , V_15 , V_16 ) ;
if ( V_2 ) {
F_10 ( * V_5 ) ;
* V_5 = NULL ;
F_7 ( & V_12 ) ;
return F_8 ( V_2 ) ;
}
}
V_13:
F_7 ( & V_12 ) ;
}
V_6 = F_11 ( sizeof( * V_6 ) + F_12 ( * V_5 ) ,
V_17 ) ;
if ( ! V_6 )
return F_8 ( - V_18 ) ;
V_6 -> V_5 = * V_5 ;
V_6 -> V_19 = V_20 ;
V_2 = F_13 ( V_6 ) ;
if ( V_2 ) {
F_14 ( V_6 ) ;
return F_8 ( V_2 ) ;
}
return V_6 ;
}
static void F_15 ( struct V_1 * V_6 , struct V_21 * V_21 ,
char * V_22 )
{
struct V_23 {
unsigned long V_24 ;
T_1 V_25 ;
T_2 V_26 ;
T_3 V_27 ;
T_4 V_28 ;
} V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_24 = V_21 -> V_30 ;
V_29 . V_25 = V_21 -> V_31 ;
V_29 . V_26 = F_16 ( & V_32 , V_21 -> V_33 ) ;
V_29 . V_27 = F_17 ( & V_32 , V_21 -> V_34 ) ;
V_29 . V_28 = V_21 -> V_35 ;
F_18 ( V_6 , ( const V_36 * ) & V_29 , sizeof( V_29 ) ) ;
if ( V_37 & V_38 )
F_18 ( V_6 , V_21 -> V_39 -> V_40 ,
sizeof( V_21 -> V_39 -> V_40 ) ) ;
F_19 ( V_6 , V_22 ) ;
}
static int F_20 ( struct V_41 * V_41 ,
const char * V_42 ,
const char * V_43 ,
T_5 V_44 ,
char type , char * V_22 )
{
struct V_21 * V_21 = V_41 -> V_45 ;
struct V_1 * V_6 ;
char * * V_46 ;
T_5 V_47 = 0 ;
char * V_48 = NULL ;
int error ;
int V_49 ;
if ( ! V_21 -> V_50 -> V_51 )
return - V_52 ;
V_6 = F_1 ( type ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
error = - V_53 ;
for ( V_46 = V_54 ; * V_46 != NULL ; V_46 ++ ) {
if ( ( V_42 && V_43 )
&& ! strcmp ( * V_46 , V_42 ) ) {
error = 0 ;
F_18 ( V_6 , ( const V_36 * ) V_43 ,
V_44 ) ;
continue;
}
V_49 = F_21 ( V_41 , * V_46 ,
& V_48 , V_47 , V_55 ) ;
if ( V_49 == - V_18 ) {
error = - V_18 ;
goto V_13;
}
if ( V_49 < 0 )
continue;
error = 0 ;
V_47 = V_49 ;
F_18 ( V_6 , ( const V_36 * ) V_48 , V_47 ) ;
}
F_15 ( V_6 , V_21 , V_22 ) ;
V_13:
F_14 ( V_48 ) ;
F_14 ( V_6 ) ;
return error ;
}
int F_22 ( struct V_41 * V_41 , const char * V_42 ,
const char * V_43 , T_5 V_44 ,
char * V_22 )
{
return F_20 ( V_41 , V_42 , V_43 ,
V_44 , V_7 , V_22 ) ;
}
int F_23 ( struct V_41 * V_41 , const char * V_42 ,
const char * V_43 , T_5 V_44 ,
char * V_22 )
{
return F_20 ( V_41 , V_42 , V_43 ,
V_44 , V_56 , V_22 ) ;
}
int F_24 ( struct V_41 * V_41 , const char * V_57 ,
const char * V_48 , T_5 V_58 )
{
struct V_21 * V_21 = V_41 -> V_45 ;
struct V_59 V_60 ;
int V_2 = 0 ;
V_2 = F_22 ( V_41 , V_57 , V_48 ,
V_58 , V_60 . V_22 ) ;
if ( V_2 == 0 ) {
V_60 . type = V_7 ;
V_2 = F_25 ( V_41 , V_61 ,
& V_60 ,
sizeof( V_60 ) , 0 ) ;
} else if ( V_2 == - V_53 && V_21 -> V_50 -> V_62 ) {
V_2 = V_21 -> V_50 -> V_62 ( V_41 , V_61 ) ;
}
return V_2 ;
}
int F_26 ( struct V_21 * V_21 , const struct V_63 * V_64 ,
char * V_65 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_7 ) ;
if ( F_4 ( V_6 ) ) {
F_27 ( L_2 ) ;
return F_5 ( V_6 ) ;
}
F_18 ( V_6 , V_64 -> V_66 , V_64 -> V_67 ) ;
F_15 ( V_6 , V_21 , V_65 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
int F_28 ( void )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_2 = 0 ;
V_69 = F_29 ( & V_72 , V_73 , NULL ) ;
if ( F_4 ( V_69 ) )
return - V_74 ;
F_30 ( & V_69 -> V_75 ) ;
V_71 = V_69 -> V_76 . V_77 ;
if ( V_71 -> V_78 > V_79 ) {
V_2 = - V_80 ;
goto V_13;
}
memcpy ( V_15 , V_71 -> V_81 , V_71 -> V_78 ) ;
V_13:
memset ( V_71 -> V_81 , 0 , V_71 -> V_78 ) ;
F_31 ( & V_69 -> V_75 ) ;
F_32 ( V_69 ) ;
return V_2 ;
}
