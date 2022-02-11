char * F_1 ( char * * V_1 , struct V_2 * V_2 , char * V_3 , T_1 V_4 )
{
char * V_5 ;
int V_6 ;
unsigned V_7 ;
const char * V_8 ;
V_9:
V_5 = V_3 + V_4 ;
* -- V_5 = '\0' ;
V_4 -- ;
V_7 = F_2 ( & V_10 ) ;
F_3 () ;
while ( 1 ) {
F_4 ( & V_2 -> V_11 ) ;
if ( F_5 ( V_2 ) )
break;
V_6 = V_2 -> V_12 . V_13 ;
V_4 -= V_6 + 1 ;
if ( V_4 < 0 )
goto V_14;
V_5 -= V_6 ;
memcpy ( V_5 , V_2 -> V_12 . V_15 , V_6 ) ;
* -- V_5 = '/' ;
F_6 ( & V_2 -> V_11 ) ;
V_2 = V_2 -> V_16 ;
}
if ( F_7 ( & V_10 , V_7 ) ) {
F_6 ( & V_2 -> V_11 ) ;
F_8 () ;
goto V_9;
}
if ( * V_5 != '/' ) {
if ( -- V_4 < 0 ) {
F_6 ( & V_2 -> V_11 ) ;
F_8 () ;
goto V_17;
}
* -- V_5 = '/' ;
}
* V_1 = V_5 ;
V_8 = V_2 -> V_18 ;
if ( ! V_8 ) {
F_6 ( & V_2 -> V_11 ) ;
F_8 () ;
F_9 ( 1 ) ;
return V_5 ;
}
V_6 = strlen ( V_8 ) ;
while ( V_6 > 0 && V_8 [ V_6 - 1 ] == '/' )
V_6 -- ;
V_4 -= V_6 ;
if ( V_4 < 0 ) {
F_6 ( & V_2 -> V_11 ) ;
F_8 () ;
goto V_17;
}
V_5 -= V_6 ;
memcpy ( V_5 , V_8 , V_6 ) ;
F_6 ( & V_2 -> V_11 ) ;
F_8 () ;
return V_5 ;
V_14:
F_6 ( & V_2 -> V_11 ) ;
F_8 () ;
if ( F_7 ( & V_10 , V_7 ) )
goto V_9;
V_17:
return F_10 ( - V_19 ) ;
}
struct V_20 * F_11 ( struct V_21 * V_21 )
{
struct V_20 * V_22 ;
struct V_23 * V_24 = F_12 ( V_21 -> V_2 -> V_25 ) ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_29 = NULL ;
F_13 ( L_1 ) ;
V_22 = F_10 ( - V_30 ) ;
if ( F_5 ( V_21 -> V_2 ) )
goto V_31;
V_22 = F_10 ( - V_32 ) ;
V_27 = F_14 () ;
V_29 = F_15 () ;
if ( V_27 == NULL || V_29 == NULL )
goto V_33;
F_13 ( L_2 , V_34 ) ;
V_22 = V_24 -> V_35 -> V_36 -> V_37 ( V_24 , V_21 -> V_2 , V_27 , V_29 ) ;
if ( F_16 ( V_22 ) )
goto V_33;
F_13 ( L_3 , V_34 ) ;
F_17 ( V_22 ) ;
F_18 ( V_22 , & V_38 ) ;
F_19 ( & V_39 , V_40 ) ;
V_33:
F_20 ( V_29 ) ;
F_21 ( V_27 ) ;
V_31:
if ( F_16 ( V_22 ) )
F_13 ( L_4 , V_34 , F_22 ( V_22 ) ) ;
else
F_13 ( L_5 , V_34 , V_22 ) ;
return V_22 ;
}
static void F_23 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_38 ;
F_24 ( V_44 ) ;
if ( ! F_25 ( V_44 ) )
F_19 ( & V_39 , V_40 ) ;
}
void F_26 ( void )
{
if ( F_25 ( & V_38 ) )
F_27 ( & V_39 ) ;
}
static struct V_20 * F_28 ( struct V_23 * V_24 ,
const char * V_45 ,
struct V_46 * V_47 )
{
#ifdef F_29
struct V_20 * V_22 = F_10 ( - V_48 ) ;
switch ( V_24 -> V_35 -> V_36 -> V_49 ) {
case 2 :
case 3 :
V_22 = F_30 ( & V_50 , 0 , V_45 , V_47 ) ;
break;
case 4 :
V_22 = F_30 ( & V_51 , 0 , V_45 , V_47 ) ;
}
return V_22 ;
#else
return F_30 ( & V_50 , 0 , V_45 , V_47 ) ;
#endif
}
struct V_20 * F_31 ( struct V_2 * V_2 , struct V_26 * V_27 ,
struct V_28 * V_29 , T_2 V_52 )
{
struct V_46 V_47 = {
. V_53 = V_2 -> V_54 ,
. V_2 = V_2 ,
. V_27 = V_27 ,
. V_29 = V_29 ,
. V_52 = V_52 ,
} ;
struct V_20 * V_22 = F_10 ( - V_32 ) ;
char * V_55 = ( char * ) F_32 ( V_56 ) ;
char * V_45 ;
F_13 ( L_6 ) ;
F_13 ( L_7 , V_34 ,
V_2 -> V_16 -> V_12 . V_15 ,
V_2 -> V_12 . V_15 ) ;
if ( V_55 == NULL )
goto V_33;
V_45 = F_33 ( V_2 , V_55 , V_57 ) ;
V_22 = (struct V_20 * ) V_45 ;
if ( F_16 ( V_45 ) )
goto V_58;
V_22 = F_28 ( F_34 ( V_2 -> V_54 ) , V_45 , & V_47 ) ;
V_58:
V_58 ( ( unsigned long ) V_55 ) ;
V_33:
F_13 ( L_8 , V_34 ) ;
F_13 ( L_9 , V_22 ) ;
return V_22 ;
}
struct V_20 * F_35 ( struct V_23 * V_24 , struct V_2 * V_2 ,
struct V_26 * V_27 , struct V_28 * V_29 )
{
int V_59 ;
struct V_2 * V_60 = F_36 ( V_2 ) ;
V_59 = V_24 -> V_35 -> V_36 -> V_61 ( V_60 -> V_25 , & V_2 -> V_12 , V_27 , V_29 ) ;
F_37 ( V_60 ) ;
if ( V_59 != 0 )
return F_10 ( V_59 ) ;
return F_31 ( V_2 , V_27 , V_29 , V_24 -> V_62 -> V_63 -> V_64 ) ;
}
