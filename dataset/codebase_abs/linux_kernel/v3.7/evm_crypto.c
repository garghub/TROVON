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
V_29 . V_26 = F_16 ( & V_32 , V_21 -> V_33 ) ;
V_29 . V_27 = F_17 ( & V_32 , V_21 -> V_34 ) ;
V_29 . V_28 = V_21 -> V_35 ;
F_18 ( V_6 , ( const V_36 * ) & V_29 , sizeof V_29 ) ;
F_19 ( V_6 , V_22 ) ;
}
static int F_20 ( struct V_37 * V_37 ,
const char * V_38 ,
const char * V_39 ,
T_5 V_40 ,
char type , char * V_22 )
{
struct V_21 * V_21 = V_37 -> V_41 ;
struct V_1 * V_6 ;
char * * V_42 ;
T_5 V_43 = 0 ;
char * V_44 = NULL ;
int error ;
int V_45 ;
if ( ! V_21 -> V_46 || ! V_21 -> V_46 -> V_47 )
return - V_48 ;
V_6 = F_1 ( type ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
error = - V_49 ;
for ( V_42 = V_50 ; * V_42 != NULL ; V_42 ++ ) {
if ( ( V_38 && V_39 )
&& ! strcmp ( * V_42 , V_38 ) ) {
error = 0 ;
F_18 ( V_6 , ( const V_36 * ) V_39 ,
V_40 ) ;
continue;
}
V_45 = F_21 ( V_37 , * V_42 ,
& V_44 , V_43 , V_51 ) ;
if ( V_45 == - V_18 ) {
error = - V_18 ;
goto V_13;
}
if ( V_45 < 0 )
continue;
error = 0 ;
V_43 = V_45 ;
F_18 ( V_6 , ( const V_36 * ) V_44 , V_43 ) ;
}
F_15 ( V_6 , V_21 , V_22 ) ;
V_13:
F_14 ( V_44 ) ;
F_14 ( V_6 ) ;
return error ;
}
int F_22 ( struct V_37 * V_37 , const char * V_38 ,
const char * V_39 , T_5 V_40 ,
char * V_22 )
{
return F_20 ( V_37 , V_38 , V_39 ,
V_40 , V_7 , V_22 ) ;
}
int F_23 ( struct V_37 * V_37 , const char * V_38 ,
const char * V_39 , T_5 V_40 ,
char * V_22 )
{
return F_20 ( V_37 , V_38 , V_39 ,
V_40 , V_52 , V_22 ) ;
}
int F_24 ( struct V_37 * V_37 , const char * V_53 ,
const char * V_44 , T_5 V_54 )
{
struct V_21 * V_21 = V_37 -> V_41 ;
struct V_55 V_56 ;
int V_2 = 0 ;
V_2 = F_22 ( V_37 , V_53 , V_44 ,
V_54 , V_56 . V_22 ) ;
if ( V_2 == 0 ) {
V_56 . type = V_7 ;
V_2 = F_25 ( V_37 , V_57 ,
& V_56 ,
sizeof( V_56 ) , 0 ) ;
}
else if ( V_2 == - V_49 )
V_2 = V_21 -> V_46 -> V_58 ( V_37 , V_57 ) ;
return V_2 ;
}
int F_26 ( struct V_21 * V_21 , const struct V_59 * V_60 ,
char * V_61 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_7 ) ;
if ( F_4 ( V_6 ) ) {
F_27 ( V_62 L_2 ) ;
return F_5 ( V_6 ) ;
}
F_18 ( V_6 , V_60 -> V_63 , V_60 -> V_64 ) ;
F_15 ( V_6 , V_21 , V_61 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
int F_28 ( void )
{
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int V_2 = 0 ;
V_66 = F_29 ( & V_69 , V_70 , NULL ) ;
if ( F_4 ( V_66 ) )
return - V_71 ;
F_30 ( & V_66 -> V_72 ) ;
V_68 = V_66 -> V_73 . V_74 ;
if ( V_68 -> V_75 > V_76 ) {
V_2 = - V_77 ;
goto V_13;
}
memcpy ( V_15 , V_68 -> V_78 , V_68 -> V_75 ) ;
V_13:
memset ( V_68 -> V_78 , 0 , V_68 -> V_75 ) ;
F_31 ( & V_66 -> V_72 ) ;
F_32 ( V_66 ) ;
return V_2 ;
}
