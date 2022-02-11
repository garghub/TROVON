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
memset ( & V_29 , 0 , sizeof V_29 ) ;
V_29 . V_24 = V_21 -> V_30 ;
V_29 . V_25 = V_21 -> V_31 ;
V_29 . V_26 = V_21 -> V_32 ;
V_29 . V_27 = V_21 -> V_33 ;
V_29 . V_28 = V_21 -> V_34 ;
F_16 ( V_6 , ( const V_35 * ) & V_29 , sizeof V_29 ) ;
F_17 ( V_6 , V_22 ) ;
}
static int F_18 ( struct V_36 * V_36 ,
const char * V_37 ,
const char * V_38 ,
T_5 V_39 ,
char type , char * V_22 )
{
struct V_21 * V_21 = V_36 -> V_40 ;
struct V_1 * V_6 ;
char * * V_41 ;
T_5 V_42 = 0 ;
char * V_43 = NULL ;
int error ;
int V_44 ;
if ( ! V_21 -> V_45 || ! V_21 -> V_45 -> V_46 )
return - V_47 ;
V_6 = F_1 ( type ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
error = - V_48 ;
for ( V_41 = V_49 ; * V_41 != NULL ; V_41 ++ ) {
if ( ( V_37 && V_38 )
&& ! strcmp ( * V_41 , V_37 ) ) {
error = 0 ;
F_16 ( V_6 , ( const V_35 * ) V_38 ,
V_39 ) ;
continue;
}
V_44 = F_19 ( V_36 , * V_41 ,
& V_43 , V_42 , V_50 ) ;
if ( V_44 == - V_18 ) {
error = - V_18 ;
goto V_13;
}
if ( V_44 < 0 )
continue;
error = 0 ;
V_42 = V_44 ;
F_16 ( V_6 , ( const V_35 * ) V_43 , V_42 ) ;
}
F_15 ( V_6 , V_21 , V_22 ) ;
V_13:
F_14 ( V_43 ) ;
F_14 ( V_6 ) ;
return error ;
}
int F_20 ( struct V_36 * V_36 , const char * V_37 ,
const char * V_38 , T_5 V_39 ,
char * V_22 )
{
return F_18 ( V_36 , V_37 , V_38 ,
V_39 , V_7 , V_22 ) ;
}
int F_21 ( struct V_36 * V_36 , const char * V_37 ,
const char * V_38 , T_5 V_39 ,
char * V_22 )
{
return F_18 ( V_36 , V_37 , V_38 ,
V_39 , V_51 , V_22 ) ;
}
int F_22 ( struct V_36 * V_36 , const char * V_52 ,
const char * V_43 , T_5 V_53 )
{
struct V_21 * V_21 = V_36 -> V_40 ;
struct V_54 V_55 ;
int V_2 = 0 ;
V_2 = F_20 ( V_36 , V_52 , V_43 ,
V_53 , V_55 . V_22 ) ;
if ( V_2 == 0 ) {
V_55 . type = V_7 ;
V_2 = F_23 ( V_36 , V_56 ,
& V_55 ,
sizeof( V_55 ) , 0 ) ;
}
else if ( V_2 == - V_48 )
V_2 = V_21 -> V_45 -> V_57 ( V_36 , V_56 ) ;
return V_2 ;
}
int F_24 ( struct V_21 * V_21 , const struct V_58 * V_59 ,
char * V_60 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_7 ) ;
if ( F_4 ( V_6 ) ) {
F_25 ( V_61 L_2 ) ;
return F_5 ( V_6 ) ;
}
F_16 ( V_6 , V_59 -> V_62 , V_59 -> V_63 ) ;
F_15 ( V_6 , V_21 , V_60 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
int F_26 ( void )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
int V_2 = 0 ;
V_65 = F_27 ( & V_68 , V_69 , NULL ) ;
if ( F_4 ( V_65 ) )
return - V_70 ;
F_28 ( & V_65 -> V_71 ) ;
V_67 = V_65 -> V_72 . V_73 ;
if ( V_67 -> V_74 > V_75 ) {
V_2 = - V_76 ;
goto V_13;
}
memcpy ( V_15 , V_67 -> V_77 , V_67 -> V_74 ) ;
V_13:
memset ( V_67 -> V_77 , 0 , V_67 -> V_74 ) ;
F_29 ( & V_65 -> V_71 ) ;
F_30 ( V_65 ) ;
return V_2 ;
}
