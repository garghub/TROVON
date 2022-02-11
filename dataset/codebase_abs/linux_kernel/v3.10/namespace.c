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
if ( V_5 & V_18 ) {
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
struct V_25 * V_26 = F_12 ( V_23 -> V_2 -> V_27 ) ;
struct V_28 * V_29 = NULL ;
struct V_30 * V_31 = NULL ;
F_13 ( L_1 ) ;
V_24 = F_10 ( - V_32 ) ;
if ( F_5 ( V_23 -> V_2 ) )
goto V_33;
V_24 = F_10 ( - V_34 ) ;
V_29 = F_14 () ;
V_31 = F_15 () ;
if ( V_29 == NULL || V_31 == NULL )
goto V_35;
F_13 ( L_2 , V_36 ) ;
V_24 = V_26 -> V_37 -> V_38 -> V_39 ( V_26 , V_23 -> V_2 , V_29 , V_31 ) ;
if ( F_16 ( V_24 ) )
goto V_35;
F_13 ( L_3 , V_36 ) ;
F_17 ( V_24 ) ;
F_18 ( V_24 , & V_40 ) ;
F_19 ( & V_41 , V_42 ) ;
V_35:
F_20 ( V_31 ) ;
F_21 ( V_29 ) ;
V_33:
if ( F_16 ( V_24 ) )
F_13 ( L_4 , V_36 , F_22 ( V_24 ) ) ;
else
F_13 ( L_5 , V_36 , V_24 ) ;
return V_24 ;
}
static int
F_23 ( struct V_22 * V_24 , struct V_2 * V_2 , struct V_43 * V_44 )
{
if ( F_24 ( V_2 -> V_27 ) -> V_45 != 0 )
return F_25 ( V_24 , V_2 , V_44 ) ;
F_26 ( V_2 -> V_27 , V_44 ) ;
return 0 ;
}
static int
F_27 ( struct V_2 * V_2 , struct V_46 * V_47 )
{
if ( F_24 ( V_2 -> V_27 ) -> V_45 != 0 )
return F_28 ( V_2 , V_47 ) ;
return - V_48 ;
}
static void F_29 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_40 ;
F_30 ( V_52 ) ;
if ( ! F_31 ( V_52 ) )
F_19 ( & V_41 , V_42 ) ;
}
void F_32 ( void )
{
if ( F_31 ( & V_40 ) )
F_33 ( & V_41 ) ;
}
static struct V_22 * F_34 ( struct V_25 * V_26 ,
const char * V_53 ,
struct V_54 * V_55 )
{
return F_35 ( & V_56 , 0 , V_53 , V_55 ) ;
}
struct V_22 * F_36 ( struct V_2 * V_2 , struct V_28 * V_29 ,
struct V_30 * V_31 , T_2 V_57 )
{
struct V_54 V_55 = {
. V_58 = V_2 -> V_59 ,
. V_2 = V_2 ,
. V_29 = V_29 ,
. V_31 = V_31 ,
. V_57 = V_57 ,
} ;
struct V_22 * V_24 = F_10 ( - V_34 ) ;
char * V_60 = ( char * ) F_37 ( V_61 ) ;
char * V_53 ;
F_13 ( L_6 ) ;
F_13 ( L_7 , V_36 ,
V_2 -> V_17 -> V_13 . V_16 ,
V_2 -> V_13 . V_16 ) ;
if ( V_60 == NULL )
goto V_35;
V_53 = F_38 ( V_2 , V_60 , V_62 ) ;
V_24 = (struct V_22 * ) V_53 ;
if ( F_16 ( V_53 ) )
goto V_63;
V_24 = F_34 ( F_39 ( V_2 -> V_59 ) , V_53 , & V_55 ) ;
V_63:
V_63 ( ( unsigned long ) V_60 ) ;
V_35:
F_13 ( L_8 , V_36 ) ;
F_13 ( L_9 , V_24 ) ;
return V_24 ;
}
struct V_22 * F_40 ( struct V_25 * V_26 , struct V_2 * V_2 ,
struct V_28 * V_29 , struct V_30 * V_31 )
{
int V_64 ;
struct V_2 * V_65 = F_41 ( V_2 ) ;
V_64 = V_26 -> V_37 -> V_38 -> V_66 ( V_65 -> V_27 , & V_2 -> V_13 , V_29 , V_31 ) ;
F_42 ( V_65 ) ;
if ( V_64 != 0 )
return F_10 ( V_64 ) ;
return F_36 ( V_2 , V_29 , V_31 , V_26 -> V_67 -> V_68 -> V_69 ) ;
}
