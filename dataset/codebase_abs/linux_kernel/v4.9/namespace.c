char * F_1 ( char * * V_1 , struct V_2 * V_2 , char * V_3 , T_1 V_4 ,
unsigned V_5 )
{
char * V_6 ;
int V_7 ;
unsigned V_8 ;
const char * V_9 ;
V_10:
V_6 = V_3 + V_4 ;
* -- V_6 = '\0' ;
V_4 -- ;
V_8 = F_2 ( & V_11 ) ;
F_3 () ;
while ( 1 ) {
F_4 ( & V_2 -> V_12 ) ;
if ( F_5 ( V_2 ) )
break;
V_7 = V_2 -> V_13 . V_14 ;
V_4 -= V_7 + 1 ;
if ( V_4 < 0 )
goto V_15;
V_6 -= V_7 ;
memcpy ( V_6 , V_2 -> V_13 . V_16 , V_7 ) ;
* -- V_6 = '/' ;
F_6 ( & V_2 -> V_12 ) ;
V_2 = V_2 -> V_17 ;
}
if ( F_7 ( & V_11 , V_8 ) ) {
F_6 ( & V_2 -> V_12 ) ;
F_8 () ;
goto V_10;
}
if ( ( V_5 & V_18 ) && * V_6 != '/' ) {
if ( -- V_4 < 0 ) {
F_6 ( & V_2 -> V_12 ) ;
F_8 () ;
goto V_19;
}
* -- V_6 = '/' ;
}
* V_1 = V_6 ;
V_9 = V_2 -> V_20 ;
if ( ! V_9 ) {
F_6 ( & V_2 -> V_12 ) ;
F_8 () ;
F_9 ( 1 ) ;
return V_6 ;
}
V_7 = strlen ( V_9 ) ;
if ( * V_6 == '/' ) {
while ( V_7 > 0 && V_9 [ V_7 - 1 ] == '/' )
V_7 -- ;
}
V_4 -= V_7 ;
if ( V_4 < 0 ) {
F_6 ( & V_2 -> V_12 ) ;
F_8 () ;
goto V_19;
}
V_6 -= V_7 ;
memcpy ( V_6 , V_9 , V_7 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_8 () ;
return V_6 ;
V_15:
F_6 ( & V_2 -> V_12 ) ;
F_8 () ;
if ( F_7 ( & V_11 , V_8 ) )
goto V_10;
V_19:
return F_10 ( - V_21 ) ;
}
struct V_22 * F_11 ( struct V_23 * V_23 )
{
struct V_22 * V_24 ;
struct V_25 * V_26 = F_12 ( F_13 ( V_23 -> V_2 ) ) ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
F_14 ( L_1 ) ;
V_24 = F_10 ( - V_31 ) ;
if ( F_5 ( V_23 -> V_2 ) )
goto V_32;
V_24 = F_10 ( - V_33 ) ;
V_28 = F_15 () ;
V_30 = F_16 () ;
if ( V_28 == NULL || V_30 == NULL )
goto V_34;
F_14 ( L_2 , V_35 ) ;
V_24 = V_26 -> V_36 -> V_37 -> V_38 ( V_26 , V_23 -> V_2 , V_28 , V_30 ) ;
if ( F_17 ( V_24 ) )
goto V_34;
F_14 ( L_3 , V_35 ) ;
F_18 ( V_24 ) ;
F_19 ( V_24 , & V_39 ) ;
F_20 ( & V_40 , V_41 ) ;
V_34:
F_21 ( V_30 ) ;
F_22 ( V_28 ) ;
V_32:
if ( F_17 ( V_24 ) )
F_14 ( L_4 , V_35 , F_23 ( V_24 ) ) ;
else
F_14 ( L_5 , V_35 , V_24 ) ;
return V_24 ;
}
static int
F_24 ( struct V_22 * V_24 , struct V_2 * V_2 , struct V_42 * V_43 )
{
if ( F_25 ( F_13 ( V_2 ) ) -> V_44 != 0 )
return F_26 ( V_24 , V_2 , V_43 ) ;
F_27 ( F_13 ( V_2 ) , V_43 ) ;
return 0 ;
}
static int
F_28 ( struct V_2 * V_2 , struct V_45 * V_46 )
{
if ( F_25 ( F_13 ( V_2 ) ) -> V_44 != 0 )
return F_29 ( V_2 , V_46 ) ;
return - V_47 ;
}
static void F_30 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_39 ;
F_31 ( V_51 ) ;
if ( ! F_32 ( V_51 ) )
F_20 ( & V_40 , V_41 ) ;
}
void F_33 ( void )
{
if ( F_32 ( & V_39 ) )
F_34 ( & V_40 ) ;
}
static struct V_22 * F_35 ( struct V_25 * V_26 ,
const char * V_52 ,
struct V_53 * V_54 )
{
return F_36 ( & V_55 , 0 , V_52 , V_54 ) ;
}
struct V_22 * F_37 ( struct V_2 * V_2 , struct V_27 * V_28 ,
struct V_29 * V_30 , T_2 V_56 )
{
struct V_53 V_54 = {
. V_57 = V_2 -> V_58 ,
. V_2 = V_2 ,
. V_28 = V_28 ,
. V_30 = V_30 ,
. V_56 = V_56 ,
} ;
struct V_22 * V_24 = F_10 ( - V_33 ) ;
char * V_59 = ( char * ) F_38 ( V_60 ) ;
char * V_52 ;
F_14 ( L_6 ) ;
F_14 ( L_7 , V_35 ,
V_2 ) ;
if ( V_59 == NULL )
goto V_34;
V_52 = F_39 ( V_2 , V_59 , V_61 ) ;
V_24 = (struct V_22 * ) V_52 ;
if ( F_17 ( V_52 ) )
goto V_62;
V_24 = F_35 ( F_40 ( V_2 -> V_58 ) , V_52 , & V_54 ) ;
V_62:
V_62 ( ( unsigned long ) V_59 ) ;
V_34:
F_14 ( L_8 , V_35 ) ;
F_14 ( L_9 , V_24 ) ;
return V_24 ;
}
struct V_22 * F_41 ( struct V_25 * V_26 , struct V_2 * V_2 ,
struct V_27 * V_28 , struct V_29 * V_30 )
{
int V_63 ;
struct V_2 * V_64 = F_42 ( V_2 ) ;
V_63 = V_26 -> V_36 -> V_37 -> V_65 ( F_13 ( V_64 ) , & V_2 -> V_13 , V_28 , V_30 , NULL ) ;
F_43 ( V_64 ) ;
if ( V_63 != 0 )
return F_10 ( V_63 ) ;
return F_37 ( V_2 , V_28 , V_30 , V_26 -> V_66 -> V_67 -> V_68 ) ;
}
