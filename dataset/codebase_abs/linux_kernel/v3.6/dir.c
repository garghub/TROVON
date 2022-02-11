static int
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 . V_7 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_10 ) -> V_14 ;
struct V_15 V_16 ;
struct V_17 V_18 ;
int V_19 = 0 ;
if ( V_2 -> V_20 >> 32 )
goto V_21;
V_19 = V_13 -> V_22 ( V_10 , V_5 -> V_23 , V_5 -> V_24 , & V_18 ) ;
if ( V_19 )
goto V_21;
switch ( ( unsigned long ) V_2 -> V_20 ) {
case 0 :
if ( V_4 ( V_3 , L_1 , 1 , 0 , V_5 -> V_23 , V_25 ) < 0 )
goto V_26;
V_2 -> V_20 += 1 ;
case 1 :
if ( V_4 ( V_3 , L_2 , 2 , 1 , V_18 . V_27 , V_25 ) < 0 )
goto V_26;
V_2 -> V_20 += 1 ;
default:
break;
}
F_3 ( & V_28 ) ;
V_19 = V_13 -> V_29 ( & V_18 , V_2 -> V_20 - 2 ) ;
if ( V_19 )
goto V_30;
while ( V_13 -> V_31 ( & V_18 , & V_16 ) == 0 ) {
if ( V_4 ( V_3 , V_16 . V_32 , V_16 . V_33 ,
V_2 -> V_20 , V_16 . V_34 , V_35 ) < 0 )
goto V_30;
V_2 -> V_20 += 1 ;
}
V_30:
F_4 ( & V_28 ) ;
V_26:
V_13 -> free ( & V_18 ) ;
V_21:
return V_19 ;
}
int
F_5 ( struct V_9 * V_10 , struct V_15 * V_16 , int V_36 )
{
int V_19 = - V_37 ;
#ifdef F_6
struct V_12 * V_13 = F_2 ( V_10 ) -> V_14 ;
struct V_17 V_18 ;
F_7 ( V_38 L_3 ,
V_16 -> V_34 , V_16 -> V_27 ) ;
if ( ! V_13 -> V_39 ) {
V_19 = - V_37 ;
goto V_21;
}
V_19 = V_13 -> V_22 ( V_10 , V_16 -> V_27 , 0 , & V_18 ) ;
if ( V_19 )
goto V_21;
F_8 ( & V_28 ) ;
V_19 = V_13 -> V_39 ( & V_18 , V_16 ) ;
F_9 ( & V_28 ) ;
if ( V_36 ) {
int V_40 = V_13 -> V_41 ( & V_18 ) ;
if ( ! V_19 )
V_19 = V_40 ;
}
V_13 -> free ( & V_18 ) ;
V_21:
#endif
return V_19 ;
}
static int
F_10 ( struct V_42 * V_32 , struct V_15 * V_16 )
{
int V_43 ;
if ( V_32 -> V_44 != V_16 -> V_33 )
return 0 ;
for ( V_43 = 0 ; V_43 < V_32 -> V_44 ; V_43 ++ ) {
char V_45 , V_46 ;
V_45 = V_32 -> V_32 [ V_43 ] ;
V_46 = V_16 -> V_32 [ V_43 ] ;
if ( V_45 >= 'A' && V_45 <= 'Z' )
V_45 += 'a' - 'A' ;
if ( V_46 >= 'A' && V_46 <= 'Z' )
V_46 += 'a' - 'A' ;
if ( V_45 != V_46 )
return 0 ;
}
return 1 ;
}
static int
F_11 ( struct V_5 * V_5 , struct V_42 * V_32 , struct V_15 * V_16 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_10 ) -> V_14 ;
struct V_17 V_18 ;
int V_19 ;
V_19 = V_13 -> V_22 ( V_10 , V_5 -> V_23 , V_5 -> V_24 , & V_18 ) ;
if ( V_19 )
goto V_21;
if ( F_12 ( V_5 ) -> V_27 != V_18 . V_27 ) {
F_13 ( V_10 , L_4 ,
F_12 ( V_5 ) -> V_27 , V_18 . V_27 ) ;
V_19 = - V_47 ;
goto V_26;
}
V_16 -> V_27 = V_5 -> V_23 ;
if ( V_32 -> V_44 == 2 && V_32 -> V_32 [ 0 ] == '.' && V_32 -> V_32 [ 1 ] == '.' ) {
V_16 -> V_33 = 0 ;
V_16 -> V_34 = V_16 -> V_27 ;
goto V_26;
}
F_3 ( & V_28 ) ;
V_19 = V_13 -> V_29 ( & V_18 , 0 ) ;
if ( V_19 )
goto V_30;
V_19 = - V_48 ;
while ( V_13 -> V_31 ( & V_18 , V_16 ) == 0 ) {
if ( F_10 ( V_32 , V_16 ) ) {
V_19 = 0 ;
break;
}
}
V_30:
F_4 ( & V_28 ) ;
V_26:
V_13 -> free ( & V_18 ) ;
V_21:
return V_19 ;
}
static int
F_14 ( const struct V_7 * V_49 , const struct V_5 * V_5 ,
struct V_42 * V_42 )
{
const unsigned int V_33 = F_2 ( V_49 -> V_50 ) -> V_51 ;
const unsigned char * V_32 ;
unsigned long V_52 ;
int V_43 ;
if ( V_42 -> V_44 < V_33 )
return 0 ;
V_42 -> V_44 = V_43 = V_33 ;
V_32 = V_42 -> V_32 ;
V_52 = F_15 () ;
while ( V_43 -- ) {
char V_53 ;
V_53 = * V_32 ++ ;
if ( V_53 >= 'A' && V_53 <= 'Z' )
V_53 += 'a' - 'A' ;
V_52 = F_16 ( V_53 , V_52 ) ;
}
V_42 -> V_52 = F_17 ( V_52 ) ;
return 0 ;
}
static int
F_18 ( const struct V_7 * V_49 , const struct V_5 * V_54 ,
const struct V_7 * V_7 , const struct V_5 * V_5 ,
unsigned int V_44 , const char * V_55 , const struct V_42 * V_32 )
{
int V_43 ;
if ( V_44 != V_32 -> V_44 )
return 1 ;
for ( V_43 = 0 ; V_43 < V_32 -> V_44 ; V_43 ++ ) {
char V_56 , V_57 ;
V_56 = V_55 [ V_43 ] ;
V_57 = V_32 -> V_32 [ V_43 ] ;
if ( V_56 >= 'A' && V_56 <= 'Z' )
V_56 += 'a' - 'A' ;
if ( V_57 >= 'A' && V_57 <= 'Z' )
V_57 += 'a' - 'A' ;
if ( V_56 != V_57 )
return 1 ;
}
return 0 ;
}
static struct V_7 *
F_19 ( struct V_5 * V_18 , struct V_7 * V_7 , unsigned int V_58 )
{
struct V_5 * V_5 = NULL ;
struct V_15 V_16 ;
int error ;
error = F_11 ( V_18 , & V_7 -> V_59 , & V_16 ) ;
if ( error == 0 ) {
error = - V_60 ;
V_5 = F_20 ( V_18 -> V_11 , & V_16 ) ;
if ( V_5 )
error = 0 ;
}
F_21 ( V_7 , V_5 ) ;
return F_22 ( error ) ;
}
