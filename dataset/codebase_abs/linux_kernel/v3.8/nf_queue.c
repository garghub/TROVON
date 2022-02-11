void F_1 ( const struct V_1 * V_2 )
{
F_2 ( F_3 ( V_3 ) ) ;
F_4 ( V_3 , V_2 ) ;
}
void F_5 ( void )
{
F_6 ( V_3 , NULL ) ;
F_7 () ;
}
static void F_8 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 )
F_9 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_9 ( V_5 -> V_7 ) ;
#ifdef F_10
if ( V_5 -> V_8 -> V_9 ) {
struct V_10 * V_9 = V_5 -> V_8 -> V_9 ;
if ( V_9 -> V_11 )
F_9 ( V_9 -> V_11 ) ;
if ( V_9 -> V_12 )
F_9 ( V_9 -> V_12 ) ;
}
#endif
F_11 ( V_5 -> V_13 -> V_14 ) ;
}
static int F_12 ( struct V_15 * V_8 ,
struct V_16 * V_13 ,
T_1 V_17 , unsigned int V_18 ,
struct V_19 * V_6 ,
struct V_19 * V_7 ,
int (* F_13)( struct V_15 * ) ,
unsigned int V_20 )
{
int V_21 = - V_22 ;
struct V_4 * V_5 = NULL ;
#ifdef F_10
struct V_19 * V_11 ;
struct V_19 * V_12 ;
#endif
const struct V_23 * V_24 ;
const struct V_1 * V_2 ;
F_14 () ;
V_2 = F_15 ( V_3 ) ;
if ( ! V_2 ) {
V_21 = - V_25 ;
goto V_26;
}
V_24 = F_16 ( V_17 ) ;
if ( ! V_24 )
goto V_26;
V_5 = F_17 ( sizeof( * V_5 ) + V_24 -> V_27 , V_28 ) ;
if ( ! V_5 ) {
V_21 = - V_29 ;
goto V_26;
}
* V_5 = (struct V_4 ) {
. V_8 = V_8 ,
. V_13 = V_13 ,
. V_17 = V_17 ,
. V_18 = V_18 ,
. V_6 = V_6 ,
. V_7 = V_7 ,
. F_13 = F_13 ,
} ;
if ( ! F_18 ( V_5 -> V_13 -> V_14 ) ) {
V_21 = - V_30 ;
goto V_26;
}
if ( V_6 )
F_19 ( V_6 ) ;
if ( V_7 )
F_19 ( V_7 ) ;
#ifdef F_10
if ( V_8 -> V_9 ) {
V_11 = V_8 -> V_9 -> V_11 ;
if ( V_11 )
F_19 ( V_11 ) ;
V_12 = V_8 -> V_9 -> V_12 ;
if ( V_12 )
F_19 ( V_12 ) ;
}
#endif
F_20 ( V_8 ) ;
V_24 -> V_31 ( V_8 , V_5 ) ;
V_21 = V_2 -> V_32 ( V_5 , V_20 ) ;
F_21 () ;
if ( V_21 < 0 ) {
F_8 ( V_5 ) ;
goto V_33;
}
return 0 ;
V_26:
F_21 () ;
V_33:
F_22 ( V_5 ) ;
return V_21 ;
}
static void F_23 ( struct V_15 * V_8 )
{
if ( V_8 -> V_9 )
F_24 ( V_8 , V_8 -> V_34 - V_8 -> V_35 ) ;
}
static void F_25 ( struct V_15 * V_8 )
{
if ( V_8 -> V_9 )
F_26 ( V_8 , V_8 -> V_34 - V_8 -> V_35 ) ;
}
int F_27 ( struct V_15 * V_8 ,
struct V_16 * V_13 ,
T_1 V_17 , unsigned int V_18 ,
struct V_19 * V_6 ,
struct V_19 * V_7 ,
int (* F_13)( struct V_15 * ) ,
unsigned int V_20 )
{
struct V_15 * V_36 ;
int V_33 = - V_37 ;
unsigned int V_38 ;
if ( ! F_28 ( V_8 ) )
return F_12 ( V_8 , V_13 , V_17 , V_18 , V_6 , V_7 , F_13 ,
V_20 ) ;
switch ( V_17 ) {
case V_39 :
V_8 -> V_40 = F_29 ( V_41 ) ;
break;
case V_42 :
V_8 -> V_40 = F_29 ( V_43 ) ;
break;
}
F_23 ( V_8 ) ;
V_36 = F_30 ( V_8 , 0 ) ;
if ( F_31 ( V_36 ) )
goto V_44;
V_38 = 0 ;
V_33 = 0 ;
do {
struct V_15 * V_45 = V_36 -> V_46 ;
V_36 -> V_46 = NULL ;
if ( V_33 == 0 ) {
F_25 ( V_36 ) ;
V_33 = F_12 ( V_36 , V_13 , V_17 , V_18 , V_6 ,
V_7 , F_13 , V_20 ) ;
}
if ( V_33 == 0 )
V_38 ++ ;
else
F_32 ( V_36 ) ;
V_36 = V_45 ;
} while ( V_36 );
if ( V_38 ) {
F_32 ( V_8 ) ;
return 0 ;
}
V_44:
F_25 ( V_8 ) ;
return V_33 ;
}
void F_33 ( struct V_4 * V_5 , unsigned int V_47 )
{
struct V_15 * V_8 = V_5 -> V_8 ;
struct V_16 * V_13 = V_5 -> V_13 ;
const struct V_23 * V_24 ;
int V_33 ;
F_14 () ;
F_8 ( V_5 ) ;
if ( V_47 == V_48 ) {
V_13 = F_34 ( V_13 -> V_49 . V_50 , struct V_16 , V_49 ) ;
V_47 = V_51 ;
}
if ( V_47 == V_51 ) {
V_24 = F_16 ( V_5 -> V_17 ) ;
if ( ! V_24 || V_24 -> V_52 ( V_8 , V_5 ) < 0 )
V_47 = V_53 ;
}
if ( V_47 == V_51 ) {
V_54:
V_47 = F_35 ( & V_55 [ V_5 -> V_17 ] [ V_5 -> V_18 ] ,
V_8 , V_5 -> V_18 ,
V_5 -> V_6 , V_5 -> V_7 , & V_13 ,
V_5 -> F_13 , V_56 ) ;
}
switch ( V_47 & V_57 ) {
case V_51 :
case V_58 :
F_36 () ;
V_5 -> F_13 ( V_8 ) ;
F_37 () ;
break;
case V_59 :
V_33 = F_12 ( V_8 , V_13 , V_5 -> V_17 , V_5 -> V_18 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> F_13 ,
V_47 >> V_60 ) ;
if ( V_33 < 0 ) {
if ( V_33 == - V_30 )
goto V_54;
if ( V_33 == - V_25 &&
( V_47 & V_61 ) )
goto V_54;
F_32 ( V_8 ) ;
}
break;
case V_62 :
break;
default:
F_32 ( V_8 ) ;
}
F_21 () ;
F_22 ( V_5 ) ;
}
