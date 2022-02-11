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
F_6 ( V_6 [ V_1 ] , NULL ) ;
F_7 ( & V_8 ) ;
F_9 () ;
return 0 ;
}
void F_10 ( const struct V_2 * V_3 )
{
T_1 V_1 ;
F_3 ( & V_8 ) ;
for ( V_1 = 0 ; V_1 < F_2 ( V_6 ) ; V_1 ++ ) {
if ( F_4 (
V_6 [ V_1 ] ,
F_5 ( & V_8 )
) == V_3 )
F_6 ( V_6 [ V_1 ] , NULL ) ;
}
F_7 ( & V_8 ) ;
F_9 () ;
}
static void F_11 ( struct V_11 * V_12 )
{
if ( V_12 -> V_13 )
F_12 ( V_12 -> V_13 ) ;
if ( V_12 -> V_14 )
F_12 ( V_12 -> V_14 ) ;
#ifdef F_13
if ( V_12 -> V_15 -> V_16 ) {
struct V_17 * V_16 = V_12 -> V_15 -> V_16 ;
if ( V_16 -> V_18 )
F_12 ( V_16 -> V_18 ) ;
if ( V_16 -> V_19 )
F_12 ( V_16 -> V_19 ) ;
}
#endif
F_14 ( V_12 -> V_20 -> V_21 ) ;
}
static int F_15 ( struct V_22 * V_15 ,
struct V_23 * V_20 ,
T_1 V_1 , unsigned int V_24 ,
struct V_25 * V_13 ,
struct V_25 * V_14 ,
int (* F_16)( struct V_22 * ) ,
unsigned int V_26 )
{
int V_27 = - V_28 ;
struct V_11 * V_12 = NULL ;
#ifdef F_13
struct V_25 * V_18 ;
struct V_25 * V_19 ;
#endif
const struct V_29 * V_30 ;
const struct V_2 * V_3 ;
F_17 () ;
V_3 = F_18 ( V_6 [ V_1 ] ) ;
if ( ! V_3 ) {
V_27 = - V_31 ;
goto V_32;
}
V_30 = F_19 ( V_1 ) ;
if ( ! V_30 )
goto V_32;
V_12 = F_20 ( sizeof( * V_12 ) + V_30 -> V_33 , V_34 ) ;
if ( ! V_12 ) {
V_27 = - V_35 ;
goto V_32;
}
* V_12 = (struct V_11 ) {
. V_15 = V_15 ,
. V_20 = F_21 ( V_20 , struct V_36 , V_37 ) ,
. V_1 = V_1 ,
. V_24 = V_24 ,
. V_13 = V_13 ,
. V_14 = V_14 ,
. F_16 = F_16 ,
} ;
if ( ! F_22 ( V_12 -> V_20 -> V_21 ) ) {
V_27 = - V_38 ;
goto V_32;
}
if ( V_13 )
F_23 ( V_13 ) ;
if ( V_14 )
F_23 ( V_14 ) ;
#ifdef F_13
if ( V_15 -> V_16 ) {
V_18 = V_15 -> V_16 -> V_18 ;
if ( V_18 )
F_23 ( V_18 ) ;
V_19 = V_15 -> V_16 -> V_19 ;
if ( V_19 )
F_23 ( V_19 ) ;
}
#endif
F_24 ( V_15 ) ;
V_30 -> V_39 ( V_15 , V_12 ) ;
V_27 = V_3 -> V_40 ( V_12 , V_26 ) ;
F_25 () ;
if ( V_27 < 0 ) {
F_11 ( V_12 ) ;
goto V_41;
}
return 0 ;
V_32:
F_25 () ;
V_41:
F_26 ( V_12 ) ;
return V_27 ;
}
int F_27 ( struct V_22 * V_15 ,
struct V_23 * V_20 ,
T_1 V_1 , unsigned int V_24 ,
struct V_25 * V_13 ,
struct V_25 * V_14 ,
int (* F_16)( struct V_22 * ) ,
unsigned int V_26 )
{
struct V_22 * V_42 ;
int V_41 ;
unsigned int V_43 ;
if ( ! F_28 ( V_15 ) )
return F_15 ( V_15 , V_20 , V_1 , V_24 , V_13 , V_14 , F_16 ,
V_26 ) ;
switch ( V_1 ) {
case V_44 :
V_15 -> V_45 = F_29 ( V_46 ) ;
break;
case V_47 :
V_15 -> V_45 = F_29 ( V_48 ) ;
break;
}
V_42 = F_30 ( V_15 , 0 ) ;
if ( F_31 ( V_42 ) )
return - V_7 ;
V_43 = 0 ;
V_41 = 0 ;
do {
struct V_22 * V_49 = V_42 -> V_50 ;
V_42 -> V_50 = NULL ;
if ( V_41 == 0 )
V_41 = F_15 ( V_42 , V_20 , V_1 , V_24 , V_13 ,
V_14 , F_16 , V_26 ) ;
if ( V_41 == 0 )
V_43 ++ ;
else
F_32 ( V_42 ) ;
V_42 = V_49 ;
} while ( V_42 );
if ( F_33 ( V_41 && V_43 ) )
V_41 = 0 ;
if ( V_41 == 0 )
F_32 ( V_15 ) ;
return V_41 ;
}
void F_34 ( struct V_11 * V_12 , unsigned int V_51 )
{
struct V_22 * V_15 = V_12 -> V_15 ;
struct V_23 * V_20 = & V_12 -> V_20 -> V_37 ;
const struct V_29 * V_30 ;
int V_41 ;
F_17 () ;
F_11 ( V_12 ) ;
if ( V_51 == V_52 ) {
V_20 = V_20 -> V_53 ;
V_51 = V_54 ;
}
if ( V_51 == V_54 ) {
V_30 = F_19 ( V_12 -> V_1 ) ;
if ( ! V_30 || V_30 -> V_55 ( V_15 , V_12 ) < 0 )
V_51 = V_56 ;
}
if ( V_51 == V_54 ) {
V_57:
V_51 = F_35 ( & V_58 [ V_12 -> V_1 ] [ V_12 -> V_24 ] ,
V_15 , V_12 -> V_24 ,
V_12 -> V_13 , V_12 -> V_14 , & V_20 ,
V_12 -> F_16 , V_59 ) ;
}
switch ( V_51 & V_60 ) {
case V_54 :
case V_61 :
F_36 () ;
V_12 -> F_16 ( V_15 ) ;
F_37 () ;
break;
case V_62 :
V_41 = F_15 ( V_15 , V_20 , V_12 -> V_1 , V_12 -> V_24 ,
V_12 -> V_13 , V_12 -> V_14 , V_12 -> F_16 ,
V_51 >> V_63 ) ;
if ( V_41 < 0 ) {
if ( V_41 == - V_38 )
goto V_57;
if ( V_41 == - V_31 &&
( V_51 & V_64 ) )
goto V_57;
F_32 ( V_15 ) ;
}
break;
case V_65 :
default:
F_32 ( V_15 ) ;
}
F_25 () ;
F_26 ( V_12 ) ;
}
static void * F_38 ( struct V_66 * V_67 , T_2 * V_68 )
{
if ( * V_68 >= F_2 ( V_6 ) )
return NULL ;
return V_68 ;
}
static void * F_39 ( struct V_66 * V_69 , void * V_70 , T_2 * V_68 )
{
( * V_68 ) ++ ;
if ( * V_68 >= F_2 ( V_6 ) )
return NULL ;
return V_68 ;
}
static void F_40 ( struct V_66 * V_69 , void * V_70 )
{
}
static int F_41 ( struct V_66 * V_69 , void * V_70 )
{
int V_4 ;
T_2 * V_68 = V_70 ;
const struct V_2 * V_3 ;
F_17 () ;
V_3 = F_18 ( V_6 [ * V_68 ] ) ;
if ( ! V_3 )
V_4 = F_42 ( V_69 , L_1 , * V_68 ) ;
else
V_4 = F_42 ( V_69 , L_2 , * V_68 , V_3 -> V_71 ) ;
F_25 () ;
return V_4 ;
}
static int F_43 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_44 ( V_73 , & V_74 ) ;
}
int T_3 F_45 ( void )
{
#ifdef F_46
if ( ! F_47 ( L_3 , V_75 ,
V_76 , & V_77 ) )
return - 1 ;
#endif
return 0 ;
}
