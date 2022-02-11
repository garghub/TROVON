static struct V_1 * F_1 ( void )
{
int V_2 ;
struct V_1 * V_3 ;
if ( V_4 == NULL ) {
F_2 ( & V_5 ) ;
if ( V_4 )
goto V_6;
V_4 = F_3 ( V_7 , 0 , V_8 ) ;
if ( F_4 ( V_4 ) ) {
F_5 ( L_1 ,
V_7 , F_6 ( V_4 ) ) ;
V_2 = F_6 ( V_4 ) ;
V_4 = NULL ;
F_7 ( & V_5 ) ;
return F_8 ( V_2 ) ;
}
V_2 = F_9 ( V_4 , V_9 , V_10 ) ;
if ( V_2 ) {
F_10 ( V_4 ) ;
V_4 = NULL ;
F_7 ( & V_5 ) ;
return F_8 ( V_2 ) ;
}
V_6:
F_7 ( & V_5 ) ;
}
V_3 = F_11 ( sizeof( * V_3 ) + F_12 ( V_4 ) ,
V_11 ) ;
if ( ! V_3 )
return F_8 ( - V_12 ) ;
V_3 -> V_13 = V_4 ;
V_3 -> V_14 = V_15 ;
V_2 = F_13 ( V_3 ) ;
if ( V_2 ) {
F_14 ( V_3 ) ;
return F_8 ( V_2 ) ;
}
return V_3 ;
}
static void F_15 ( struct V_1 * V_3 , struct V_16 * V_16 ,
char * V_17 )
{
struct V_18 {
unsigned long V_19 ;
T_1 V_20 ;
T_2 V_21 ;
T_3 V_22 ;
T_4 V_23 ;
} V_24 ;
memset ( & V_24 , 0 , sizeof V_24 ) ;
V_24 . V_19 = V_16 -> V_25 ;
V_24 . V_20 = V_16 -> V_26 ;
V_24 . V_21 = V_16 -> V_27 ;
V_24 . V_22 = V_16 -> V_28 ;
V_24 . V_23 = V_16 -> V_29 ;
F_16 ( V_3 , ( const V_30 * ) & V_24 , sizeof V_24 ) ;
F_17 ( V_3 , V_17 ) ;
}
int F_18 ( struct V_31 * V_31 , const char * V_32 ,
const char * V_33 , T_5 V_34 ,
char * V_17 )
{
struct V_16 * V_16 = V_31 -> V_35 ;
struct V_1 * V_3 ;
char * * V_36 ;
T_5 V_37 = 0 ;
char * V_38 = NULL ;
int error ;
int V_39 ;
if ( ! V_16 -> V_40 || ! V_16 -> V_40 -> V_41 )
return - V_42 ;
V_3 = F_1 () ;
if ( F_4 ( V_3 ) )
return F_6 ( V_3 ) ;
error = - V_43 ;
for ( V_36 = V_44 ; * V_36 != NULL ; V_36 ++ ) {
if ( ( V_32 && V_33 )
&& ! strcmp ( * V_36 , V_32 ) ) {
error = 0 ;
F_16 ( V_3 , ( const V_30 * ) V_33 ,
V_34 ) ;
continue;
}
V_39 = F_19 ( V_31 , * V_36 ,
& V_38 , V_37 , V_45 ) ;
if ( V_39 == - V_12 ) {
error = - V_12 ;
goto V_6;
}
if ( V_39 < 0 )
continue;
error = 0 ;
V_37 = V_39 ;
F_16 ( V_3 , ( const V_30 * ) V_38 , V_37 ) ;
}
F_15 ( V_3 , V_16 , V_17 ) ;
V_6:
F_14 ( V_38 ) ;
F_14 ( V_3 ) ;
return error ;
}
int F_20 ( struct V_31 * V_31 , const char * V_46 ,
const char * V_38 , T_5 V_47 )
{
struct V_16 * V_16 = V_31 -> V_35 ;
struct V_48 V_49 ;
int V_2 = 0 ;
V_2 = F_18 ( V_31 , V_46 , V_38 ,
V_47 , V_49 . V_17 ) ;
if ( V_2 == 0 ) {
V_49 . type = V_50 ;
V_2 = F_21 ( V_31 , V_51 ,
& V_49 ,
sizeof( V_49 ) , 0 ) ;
}
else if ( V_2 == - V_43 )
V_2 = V_16 -> V_40 -> V_52 ( V_31 , V_51 ) ;
return V_2 ;
}
int F_22 ( struct V_16 * V_16 , const struct V_53 * V_54 ,
char * V_55 )
{
struct V_1 * V_3 ;
V_3 = F_1 () ;
if ( F_4 ( V_3 ) ) {
F_23 ( V_56 L_2 ) ;
return F_6 ( V_3 ) ;
}
F_16 ( V_3 , V_54 -> V_57 , V_54 -> V_58 ) ;
F_15 ( V_3 , V_16 , V_55 ) ;
F_14 ( V_3 ) ;
return 0 ;
}
int F_24 ( void )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
int V_2 = 0 ;
V_60 = F_25 ( & V_63 , V_64 , NULL ) ;
if ( F_4 ( V_60 ) )
return - V_65 ;
F_26 ( & V_60 -> V_66 ) ;
V_62 = V_60 -> V_67 . V_68 ;
if ( V_62 -> V_69 > V_70 ) {
V_2 = - V_71 ;
goto V_6;
}
memcpy ( V_9 , V_62 -> V_72 , V_62 -> V_69 ) ;
V_6:
memset ( V_62 -> V_72 , 0 , V_62 -> V_69 ) ;
F_27 ( & V_60 -> V_66 ) ;
F_28 ( V_60 ) ;
return V_2 ;
}
