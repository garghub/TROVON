int F_1 ( T_1 V_1 , const struct V_2 * V_3 )
{
int V_4 ;
const struct V_2 * V_5 ;
if ( V_1 >= F_2 ( V_6 ) )
return - V_7 ;
F_3 ( & V_8 ) ;
V_5 = F_4 ( V_6 [ V_1 ] ,
F_5 ( & V_8 ) ) ;
if ( V_5 == V_3 )
V_4 = - V_9 ;
else if ( V_5 )
V_4 = - V_10 ;
else {
F_6 ( V_6 [ V_1 ] , V_3 ) ;
V_4 = 0 ;
}
F_7 ( & V_8 ) ;
return V_4 ;
}
int F_8 ( T_1 V_1 , const struct V_2 * V_3 )
{
const struct V_2 * V_5 ;
if ( V_1 >= F_2 ( V_6 ) )
return - V_7 ;
F_3 ( & V_8 ) ;
V_5 = F_4 ( V_6 [ V_1 ] ,
F_5 ( & V_8 ) ) ;
if ( V_5 && V_5 != V_3 ) {
F_7 ( & V_8 ) ;
return - V_7 ;
}
F_9 ( V_6 [ V_1 ] , NULL ) ;
F_7 ( & V_8 ) ;
F_10 () ;
return 0 ;
}
void F_11 ( const struct V_2 * V_3 )
{
T_1 V_1 ;
F_3 ( & V_8 ) ;
for ( V_1 = 0 ; V_1 < F_2 ( V_6 ) ; V_1 ++ ) {
if ( F_4 (
V_6 [ V_1 ] ,
F_5 ( & V_8 )
) == V_3 )
F_9 ( V_6 [ V_1 ] , NULL ) ;
}
F_7 ( & V_8 ) ;
F_10 () ;
}
static void F_12 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 )
F_13 ( V_12 -> V_13 ) ;
if ( V_12 -> V_14 )
F_13 ( V_12 -> V_14 ) ;
#ifdef F_14
if ( V_12 -> V_15 -> V_16 ) {
struct V_17 * V_16 = V_12 -> V_15 -> V_16 ;
if ( V_16 -> V_18 )
F_13 ( V_16 -> V_18 ) ;
if ( V_16 -> V_19 )
F_13 ( V_16 -> V_19 ) ;
}
#endif
F_15 ( V_12 -> V_20 -> V_21 ) ;
}
static int F_16 ( struct V_22 * V_15 ,
struct V_23 * V_20 ,
T_1 V_1 , unsigned int V_24 ,
struct V_25 * V_13 ,
struct V_25 * V_14 ,
int (* F_17)( struct V_22 * ) ,
unsigned int V_26 )
{
int V_27 = - V_28 ;
struct V_11 * V_12 = NULL ;
#ifdef F_14
struct V_25 * V_18 ;
struct V_25 * V_19 ;
#endif
const struct V_29 * V_30 ;
const struct V_2 * V_3 ;
F_18 () ;
V_3 = F_19 ( V_6 [ V_1 ] ) ;
if ( ! V_3 ) {
V_27 = - V_31 ;
goto V_32;
}
V_30 = F_20 ( V_1 ) ;
if ( ! V_30 )
goto V_32;
V_12 = F_21 ( sizeof( * V_12 ) + V_30 -> V_33 , V_34 ) ;
if ( ! V_12 ) {
V_27 = - V_35 ;
goto V_32;
}
* V_12 = (struct V_11 ) {
. V_15 = V_15 ,
. V_20 = F_22 ( V_20 , struct V_36 , V_37 ) ,
. V_1 = V_1 ,
. V_24 = V_24 ,
. V_13 = V_13 ,
. V_14 = V_14 ,
. F_17 = F_17 ,
} ;
if ( ! F_23 ( V_12 -> V_20 -> V_21 ) ) {
V_27 = - V_38 ;
goto V_32;
}
if ( V_13 )
F_24 ( V_13 ) ;
if ( V_14 )
F_24 ( V_14 ) ;
#ifdef F_14
if ( V_15 -> V_16 ) {
V_18 = V_15 -> V_16 -> V_18 ;
if ( V_18 )
F_24 ( V_18 ) ;
V_19 = V_15 -> V_16 -> V_19 ;
if ( V_19 )
F_24 ( V_19 ) ;
}
#endif
F_25 ( V_15 ) ;
V_30 -> V_39 ( V_15 , V_12 ) ;
V_27 = V_3 -> V_40 ( V_12 , V_26 ) ;
F_26 () ;
if ( V_27 < 0 ) {
F_12 ( V_12 ) ;
goto V_41;
}
return 0 ;
V_32:
F_26 () ;
V_41:
F_27 ( V_12 ) ;
return V_27 ;
}
static void F_28 ( struct V_22 * V_15 )
{
if ( V_15 -> V_16 )
F_29 ( V_15 , V_15 -> V_42 - V_15 -> V_43 ) ;
}
static void F_30 ( struct V_22 * V_15 )
{
if ( V_15 -> V_16 )
F_31 ( V_15 , V_15 -> V_42 - V_15 -> V_43 ) ;
}
int F_32 ( struct V_22 * V_15 ,
struct V_23 * V_20 ,
T_1 V_1 , unsigned int V_24 ,
struct V_25 * V_13 ,
struct V_25 * V_14 ,
int (* F_17)( struct V_22 * ) ,
unsigned int V_26 )
{
struct V_22 * V_44 ;
int V_41 = - V_7 ;
unsigned int V_45 ;
if ( ! F_33 ( V_15 ) )
return F_16 ( V_15 , V_20 , V_1 , V_24 , V_13 , V_14 , F_17 ,
V_26 ) ;
switch ( V_1 ) {
case V_46 :
V_15 -> V_47 = F_34 ( V_48 ) ;
break;
case V_49 :
V_15 -> V_47 = F_34 ( V_50 ) ;
break;
}
F_28 ( V_15 ) ;
V_44 = F_35 ( V_15 , 0 ) ;
if ( F_36 ( V_44 ) )
goto V_51;
V_45 = 0 ;
V_41 = 0 ;
do {
struct V_22 * V_52 = V_44 -> V_53 ;
V_44 -> V_53 = NULL ;
if ( V_41 == 0 ) {
F_30 ( V_44 ) ;
V_41 = F_16 ( V_44 , V_20 , V_1 , V_24 , V_13 ,
V_14 , F_17 , V_26 ) ;
}
if ( V_41 == 0 )
V_45 ++ ;
else
F_37 ( V_44 ) ;
V_44 = V_52 ;
} while ( V_44 );
if ( V_45 ) {
F_37 ( V_15 ) ;
return 0 ;
}
V_51:
F_30 ( V_15 ) ;
return V_41 ;
}
void F_38 ( struct V_11 * V_12 , unsigned int V_54 )
{
struct V_22 * V_15 = V_12 -> V_15 ;
struct V_23 * V_20 = & V_12 -> V_20 -> V_37 ;
const struct V_29 * V_30 ;
int V_41 ;
F_18 () ;
F_12 ( V_12 ) ;
if ( V_54 == V_55 ) {
V_20 = V_20 -> V_56 ;
V_54 = V_57 ;
}
if ( V_54 == V_57 ) {
V_30 = F_20 ( V_12 -> V_1 ) ;
if ( ! V_30 || V_30 -> V_58 ( V_15 , V_12 ) < 0 )
V_54 = V_59 ;
}
if ( V_54 == V_57 ) {
V_60:
V_54 = F_39 ( & V_61 [ V_12 -> V_1 ] [ V_12 -> V_24 ] ,
V_15 , V_12 -> V_24 ,
V_12 -> V_13 , V_12 -> V_14 , & V_20 ,
V_12 -> F_17 , V_62 ) ;
}
switch ( V_54 & V_63 ) {
case V_57 :
case V_64 :
F_40 () ;
V_12 -> F_17 ( V_15 ) ;
F_41 () ;
break;
case V_65 :
V_41 = F_16 ( V_15 , V_20 , V_12 -> V_1 , V_12 -> V_24 ,
V_12 -> V_13 , V_12 -> V_14 , V_12 -> F_17 ,
V_54 >> V_66 ) ;
if ( V_41 < 0 ) {
if ( V_41 == - V_38 )
goto V_60;
if ( V_41 == - V_31 &&
( V_54 & V_67 ) )
goto V_60;
F_37 ( V_15 ) ;
}
break;
case V_68 :
break;
default:
F_37 ( V_15 ) ;
}
F_26 () ;
F_27 ( V_12 ) ;
}
static void * F_42 ( struct V_69 * V_70 , T_2 * V_71 )
{
if ( * V_71 >= F_2 ( V_6 ) )
return NULL ;
return V_71 ;
}
static void * F_43 ( struct V_69 * V_72 , void * V_73 , T_2 * V_71 )
{
( * V_71 ) ++ ;
if ( * V_71 >= F_2 ( V_6 ) )
return NULL ;
return V_71 ;
}
static void F_44 ( struct V_69 * V_72 , void * V_73 )
{
}
static int F_45 ( struct V_69 * V_72 , void * V_73 )
{
int V_4 ;
T_2 * V_71 = V_73 ;
const struct V_2 * V_3 ;
F_18 () ;
V_3 = F_19 ( V_6 [ * V_71 ] ) ;
if ( ! V_3 )
V_4 = F_46 ( V_72 , L_1 , * V_71 ) ;
else
V_4 = F_46 ( V_72 , L_2 , * V_71 , V_3 -> V_74 ) ;
F_26 () ;
return V_4 ;
}
static int F_47 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
return F_48 ( V_76 , & V_77 ) ;
}
int T_3 F_49 ( void )
{
#ifdef F_50
if ( ! F_51 ( L_3 , V_78 ,
V_79 , & V_80 ) )
return - 1 ;
#endif
return 0 ;
}
