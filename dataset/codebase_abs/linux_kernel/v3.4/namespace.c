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
T_2 F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_24 V_25 ;
int V_26 ;
T_2 V_27 = V_28 ;
for ( V_26 = 0 ; V_26 < V_21 -> V_29 ; V_26 ++ ) {
struct V_30 * V_31 ;
V_31 = & V_21 -> V_21 [ V_26 ] ;
if ( V_31 -> V_31 == V_32 || V_31 -> V_31 == V_28 ) {
V_27 = V_31 -> V_31 ;
break;
} else if ( V_31 -> V_31 == V_33 ) {
V_25 . V_13 = V_31 -> V_34 . V_35 . V_13 ;
V_25 . V_36 = V_31 -> V_34 . V_35 . V_36 ;
V_23 = F_12 ( & V_25 ) ;
if ( ! V_23 )
continue;
V_27 = F_13 ( V_23 , V_31 -> V_34 . V_37 ) ;
F_14 ( V_23 ) ;
break;
}
}
return V_27 ;
}
static struct V_38 * F_15 ( struct V_39 * V_40 ,
struct V_41 * V_15 ,
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_46 ;
if ( F_16 ( V_40 ) -> V_47 == 4 )
return F_17 ( V_40 , V_15 , V_43 , V_45 ) ;
V_46 = F_16 ( V_40 ) -> F_18 ( F_19 ( V_40 ) -> V_48 , V_40 , V_15 , V_43 , V_45 ) ;
if ( V_46 )
return F_10 ( V_46 ) ;
return F_20 ( F_19 ( V_40 ) -> V_48 ) ;
}
static inline struct V_38 * F_15 ( struct V_39 * V_40 ,
struct V_41 * V_15 ,
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
int V_46 = F_16 ( V_40 ) -> F_18 ( F_19 ( V_40 ) -> V_48 , V_40 , V_15 , V_43 , V_45 ) ;
if ( V_46 )
return F_10 ( V_46 ) ;
return F_20 ( F_19 ( V_40 ) -> V_48 ) ;
}
struct V_49 * F_21 ( struct V_50 * V_50 )
{
struct V_49 * V_51 ;
struct V_2 * V_52 ;
struct V_42 * V_43 = NULL ;
struct V_44 * V_45 = NULL ;
struct V_38 * V_48 ;
F_22 ( L_1 ) ;
V_51 = F_10 ( - V_53 ) ;
if ( F_5 ( V_50 -> V_2 ) )
goto V_54;
V_51 = F_10 ( - V_55 ) ;
V_43 = F_23 () ;
V_45 = F_24 () ;
if ( V_43 == NULL || V_45 == NULL )
goto V_56;
F_22 ( L_2 , V_57 ) ;
V_52 = F_25 ( V_50 -> V_2 ) ;
V_48 = F_15 ( V_52 -> V_58 , & V_50 -> V_2 -> V_12 , V_43 , V_45 ) ;
F_26 ( V_52 ) ;
if ( F_27 ( V_48 ) ) {
V_51 = F_28 ( V_48 ) ;
goto V_56;
}
if ( V_45 -> V_59 & V_60 )
V_51 = F_29 ( V_48 , V_50 -> V_2 ) ;
else
V_51 = F_30 ( V_50 -> V_2 , V_43 , V_45 , V_48 -> V_61 -> V_62 ) ;
F_31 ( V_48 ) ;
if ( F_27 ( V_51 ) )
goto V_56;
F_22 ( L_3 , V_57 ) ;
F_32 ( V_51 ) ;
F_33 ( V_51 , & V_63 ) ;
F_34 ( & V_64 , V_65 ) ;
V_56:
F_35 ( V_45 ) ;
F_36 ( V_43 ) ;
V_54:
if ( F_27 ( V_51 ) )
F_22 ( L_4 , V_57 , F_37 ( V_51 ) ) ;
else
F_22 ( L_5 , V_57 , V_51 ) ;
return V_51 ;
}
static void F_38 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = & V_63 ;
F_39 ( V_69 ) ;
if ( ! F_40 ( V_69 ) )
F_34 ( & V_64 , V_65 ) ;
}
void F_41 ( void )
{
if ( F_40 ( & V_63 ) )
F_42 ( & V_64 ) ;
}
static struct V_49 * F_43 ( struct V_70 * V_71 ,
const char * V_72 ,
struct V_73 * V_74 )
{
#ifdef F_44
struct V_49 * V_51 = F_10 ( - V_75 ) ;
switch ( V_71 -> V_76 -> V_77 -> V_47 ) {
case 2 :
case 3 :
V_51 = F_45 ( & V_78 , 0 , V_72 , V_74 ) ;
break;
case 4 :
V_51 = F_45 ( & V_79 , 0 , V_72 , V_74 ) ;
}
return V_51 ;
#else
return F_45 ( & V_78 , 0 , V_72 , V_74 ) ;
#endif
}
static struct V_49 * F_30 ( struct V_2 * V_2 ,
struct V_42 * V_43 ,
struct V_44 * V_45 ,
T_2 V_80 )
{
struct V_73 V_74 = {
. V_81 = V_2 -> V_82 ,
. V_2 = V_2 ,
. V_43 = V_43 ,
. V_45 = V_45 ,
. V_80 = V_80 ,
} ;
struct V_49 * V_51 = F_10 ( - V_55 ) ;
char * V_83 = ( char * ) F_46 ( V_84 ) ;
char * V_72 ;
F_22 ( L_6 ) ;
F_22 ( L_7 , V_57 ,
V_2 -> V_16 -> V_12 . V_15 ,
V_2 -> V_12 . V_15 ) ;
if ( V_83 == NULL )
goto V_56;
V_72 = F_47 ( V_2 , V_83 , V_85 ) ;
V_51 = (struct V_49 * ) V_72 ;
if ( F_27 ( V_72 ) )
goto V_86;
V_51 = F_43 ( F_48 ( V_2 -> V_82 ) , V_72 , & V_74 ) ;
V_86:
V_86 ( ( unsigned long ) V_83 ) ;
V_56:
F_22 ( L_8 , V_57 ) ;
F_22 ( L_9 , V_51 ) ;
return V_51 ;
}
