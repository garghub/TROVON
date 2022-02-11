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
static int F_15 ( const struct V_2 * V_38 ,
const struct V_2 * V_2 ,
T_2 * V_31 )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
int (* F_16)( struct V_40 * , const struct V_41 * , struct V_20 * );
int V_42 = - V_43 ;
F_16 = F_17 ( V_38 -> V_44 ) -> F_16 ;
if ( F_16 != NULL ) {
V_39 = F_18 ( V_45 ) ;
if ( ! V_39 ) {
V_42 = - V_46 ;
goto V_47;
}
V_21 = F_19 ( V_39 ) ;
V_42 = F_16 ( V_38 -> V_44 , & V_2 -> V_12 , V_21 ) ;
* V_31 = F_11 ( V_21 ) ;
F_20 ( V_39 ) ;
}
V_47:
return V_42 ;
}
static int F_21 ( struct V_48 * V_49 , struct V_2 * V_38 ,
struct V_2 * V_2 , struct V_50 * V_50 ,
struct V_51 * V_52 , struct V_53 * V_54 ,
T_2 * V_31 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_59 ;
V_59 = F_15 ( V_38 , V_50 -> V_2 , V_31 ) ;
if ( V_59 < 0 )
goto V_47;
V_56 = F_22 ( V_49 -> V_60 ) ;
V_58 = F_23 ( * V_31 , V_56 ) ;
if ( ! V_58 ) {
V_59 = - V_61 ;
goto V_62;
}
V_59 = V_49 -> V_63 -> V_64 -> V_65 ( V_56 , V_38 -> V_44 ,
& V_50 -> V_2 -> V_12 ,
V_52 , V_54 ) ;
V_62:
F_24 ( V_56 ) ;
V_47:
return V_59 ;
}
static inline int F_21 ( struct V_48 * V_49 ,
struct V_2 * V_38 , struct V_2 * V_2 ,
struct V_50 * V_50 , struct V_51 * V_52 ,
struct V_53 * V_54 ,
T_2 * V_31 )
{
return - V_43 ;
}
struct V_66 * F_25 ( struct V_50 * V_50 )
{
struct V_66 * V_67 ;
struct V_48 * V_49 = F_26 ( V_50 -> V_2 -> V_44 ) ;
struct V_2 * V_38 ;
struct V_51 * V_52 = NULL ;
struct V_53 * V_54 = NULL ;
int V_59 ;
T_2 V_31 = V_28 ;
F_27 ( L_1 ) ;
V_67 = F_10 ( - V_68 ) ;
if ( F_5 ( V_50 -> V_2 ) )
goto V_69;
V_67 = F_10 ( - V_46 ) ;
V_52 = F_28 () ;
V_54 = F_29 () ;
if ( V_52 == NULL || V_54 == NULL )
goto V_47;
F_27 ( L_2 , V_70 ) ;
V_38 = F_30 ( V_50 -> V_2 ) ;
V_59 = V_49 -> V_63 -> V_64 -> V_65 ( V_49 -> V_60 , V_38 -> V_44 ,
& V_50 -> V_2 -> V_12 ,
V_52 , V_54 ) ;
if ( V_59 == - V_43 && F_17 ( V_38 -> V_44 ) -> F_16 != NULL )
V_59 = F_21 ( V_49 , V_38 , V_50 -> V_2 , V_50 , V_52 , V_54 , & V_31 ) ;
F_31 ( V_38 ) ;
if ( V_59 != 0 ) {
V_67 = F_10 ( V_59 ) ;
goto V_47;
}
if ( V_54 -> V_71 & V_72 )
V_67 = F_32 ( V_50 -> V_2 ) ;
else
V_67 = F_33 ( V_50 -> V_2 , V_52 , V_54 , V_31 ) ;
if ( F_34 ( V_67 ) )
goto V_47;
F_27 ( L_3 , V_70 ) ;
F_35 ( V_67 ) ;
F_36 ( V_67 , & V_73 ) ;
F_37 ( & V_74 , V_75 ) ;
V_47:
F_38 ( V_54 ) ;
F_39 ( V_52 ) ;
V_69:
F_27 ( L_4 , V_67 ) ;
return V_67 ;
}
static void F_40 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = & V_73 ;
F_41 ( V_79 ) ;
if ( ! F_42 ( V_79 ) )
F_37 ( & V_74 , V_75 ) ;
}
void F_43 ( void )
{
if ( F_42 ( & V_73 ) )
F_44 ( & V_74 ) ;
}
static struct V_66 * F_45 ( struct V_48 * V_49 ,
const char * V_80 ,
struct V_81 * V_82 )
{
#ifdef F_46
struct V_66 * V_67 = F_10 ( - V_83 ) ;
switch ( V_49 -> V_63 -> V_64 -> V_84 ) {
case 2 :
case 3 :
V_67 = F_47 ( & V_85 , 0 , V_80 , V_82 ) ;
break;
case 4 :
V_67 = F_47 ( & V_86 , 0 , V_80 , V_82 ) ;
}
return V_67 ;
#else
return F_47 ( & V_85 , 0 , V_80 , V_82 ) ;
#endif
}
static struct V_66 * F_33 ( struct V_2 * V_2 ,
struct V_51 * V_52 ,
struct V_53 * V_54 ,
T_2 V_87 )
{
struct V_81 V_82 = {
. V_88 = V_2 -> V_89 ,
. V_2 = V_2 ,
. V_52 = V_52 ,
. V_54 = V_54 ,
. V_87 = V_87 ,
} ;
struct V_66 * V_67 = F_10 ( - V_46 ) ;
char * V_39 = ( char * ) F_48 ( V_90 ) ;
char * V_80 ;
F_27 ( L_5 ) ;
F_27 ( L_6 , V_70 ,
V_2 -> V_16 -> V_12 . V_15 ,
V_2 -> V_12 . V_15 ) ;
if ( V_39 == NULL )
goto V_47;
V_80 = F_49 ( V_2 , V_39 , V_91 ) ;
V_67 = (struct V_66 * ) V_80 ;
if ( F_34 ( V_80 ) )
goto V_92;
V_67 = F_45 ( F_50 ( V_2 -> V_89 ) , V_80 , & V_82 ) ;
V_92:
V_92 ( ( unsigned long ) V_39 ) ;
V_47:
F_27 ( L_7 , V_70 ) ;
F_27 ( L_8 , V_67 ) ;
return V_67 ;
}
