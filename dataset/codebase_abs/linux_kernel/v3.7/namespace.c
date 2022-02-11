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
static void F_23 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_40 ;
F_24 ( V_46 ) ;
if ( ! F_25 ( V_46 ) )
F_19 ( & V_41 , V_42 ) ;
}
void F_26 ( void )
{
if ( F_25 ( & V_40 ) )
F_27 ( & V_41 ) ;
}
static struct V_22 * F_28 ( struct V_25 * V_26 ,
const char * V_47 ,
struct V_48 * V_49 )
{
return F_29 ( & V_50 , 0 , V_47 , V_49 ) ;
}
struct V_22 * F_30 ( struct V_2 * V_2 , struct V_28 * V_29 ,
struct V_30 * V_31 , T_2 V_51 )
{
struct V_48 V_49 = {
. V_52 = V_2 -> V_53 ,
. V_2 = V_2 ,
. V_29 = V_29 ,
. V_31 = V_31 ,
. V_51 = V_51 ,
} ;
struct V_22 * V_24 = F_10 ( - V_34 ) ;
char * V_54 = ( char * ) F_31 ( V_55 ) ;
char * V_47 ;
F_13 ( L_6 ) ;
F_13 ( L_7 , V_36 ,
V_2 -> V_17 -> V_13 . V_16 ,
V_2 -> V_13 . V_16 ) ;
if ( V_54 == NULL )
goto V_35;
V_47 = F_32 ( V_2 , V_54 , V_56 ) ;
V_24 = (struct V_22 * ) V_47 ;
if ( F_16 ( V_47 ) )
goto V_57;
V_24 = F_28 ( F_33 ( V_2 -> V_53 ) , V_47 , & V_49 ) ;
V_57:
V_57 ( ( unsigned long ) V_54 ) ;
V_35:
F_13 ( L_8 , V_36 ) ;
F_13 ( L_9 , V_24 ) ;
return V_24 ;
}
struct V_22 * F_34 ( struct V_25 * V_26 , struct V_2 * V_2 ,
struct V_28 * V_29 , struct V_30 * V_31 )
{
int V_58 ;
struct V_2 * V_59 = F_35 ( V_2 ) ;
V_58 = V_26 -> V_37 -> V_38 -> V_60 ( V_59 -> V_27 , & V_2 -> V_13 , V_29 , V_31 ) ;
F_36 ( V_59 ) ;
if ( V_58 != 0 )
return F_10 ( V_58 ) ;
return F_30 ( V_2 , V_29 , V_31 , V_26 -> V_61 -> V_62 -> V_63 ) ;
}
