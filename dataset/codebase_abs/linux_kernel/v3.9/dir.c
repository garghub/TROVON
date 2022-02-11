static int
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) -> V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
int V_16 = 0 ;
if ( V_2 -> V_17 >> 32 )
goto V_18;
V_16 = V_10 -> V_19 ( V_7 , V_5 -> V_20 , V_5 -> V_21 , & V_15 ) ;
if ( V_16 )
goto V_18;
switch ( ( unsigned long ) V_2 -> V_17 ) {
case 0 :
if ( V_4 ( V_3 , L_1 , 1 , 0 , V_5 -> V_20 , V_22 ) < 0 )
goto V_23;
V_2 -> V_17 += 1 ;
case 1 :
if ( V_4 ( V_3 , L_2 , 2 , 1 , V_15 . V_24 , V_22 ) < 0 )
goto V_23;
V_2 -> V_17 += 1 ;
default:
break;
}
F_4 ( & V_25 ) ;
V_16 = V_10 -> V_26 ( & V_15 , V_2 -> V_17 - 2 ) ;
if ( V_16 )
goto V_27;
while ( V_10 -> V_28 ( & V_15 , & V_13 ) == 0 ) {
if ( V_4 ( V_3 , V_13 . V_29 , V_13 . V_30 ,
V_2 -> V_17 , V_13 . V_31 , V_32 ) < 0 )
goto V_27;
V_2 -> V_17 += 1 ;
}
V_27:
F_5 ( & V_25 ) ;
V_23:
V_10 -> free ( & V_15 ) ;
V_18:
return V_16 ;
}
int
F_6 ( struct V_6 * V_7 , struct V_12 * V_13 , int V_33 )
{
int V_16 = - V_34 ;
#ifdef F_7
struct V_9 * V_10 = F_3 ( V_7 ) -> V_11 ;
struct V_14 V_15 ;
F_8 ( V_35 L_3 ,
V_13 -> V_31 , V_13 -> V_24 ) ;
if ( ! V_10 -> V_36 ) {
V_16 = - V_34 ;
goto V_18;
}
V_16 = V_10 -> V_19 ( V_7 , V_13 -> V_24 , 0 , & V_15 ) ;
if ( V_16 )
goto V_18;
F_9 ( & V_25 ) ;
V_16 = V_10 -> V_36 ( & V_15 , V_13 ) ;
F_10 ( & V_25 ) ;
if ( V_33 ) {
int V_37 = V_10 -> V_38 ( & V_15 ) ;
if ( ! V_16 )
V_16 = V_37 ;
}
V_10 -> free ( & V_15 ) ;
V_18:
#endif
return V_16 ;
}
static int
F_11 ( struct V_39 * V_29 , struct V_12 * V_13 )
{
int V_40 ;
if ( V_29 -> V_41 != V_13 -> V_30 )
return 0 ;
for ( V_40 = 0 ; V_40 < V_29 -> V_41 ; V_40 ++ ) {
char V_42 , V_43 ;
V_42 = V_29 -> V_29 [ V_40 ] ;
V_43 = V_13 -> V_29 [ V_40 ] ;
if ( V_42 >= 'A' && V_42 <= 'Z' )
V_42 += 'a' - 'A' ;
if ( V_43 >= 'A' && V_43 <= 'Z' )
V_43 += 'a' - 'A' ;
if ( V_42 != V_43 )
return 0 ;
}
return 1 ;
}
static int
F_12 ( struct V_5 * V_5 , struct V_39 * V_29 , struct V_12 * V_13 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) -> V_11 ;
struct V_14 V_15 ;
int V_16 ;
V_16 = V_10 -> V_19 ( V_7 , V_5 -> V_20 , V_5 -> V_21 , & V_15 ) ;
if ( V_16 )
goto V_18;
if ( F_13 ( V_5 ) -> V_24 != V_15 . V_24 ) {
F_14 ( V_7 , L_4 ,
F_13 ( V_5 ) -> V_24 , V_15 . V_24 ) ;
V_16 = - V_44 ;
goto V_23;
}
V_13 -> V_24 = V_5 -> V_20 ;
if ( V_29 -> V_41 == 2 && V_29 -> V_29 [ 0 ] == '.' && V_29 -> V_29 [ 1 ] == '.' ) {
V_13 -> V_30 = 0 ;
V_13 -> V_31 = V_13 -> V_24 ;
goto V_23;
}
F_4 ( & V_25 ) ;
V_16 = V_10 -> V_26 ( & V_15 , 0 ) ;
if ( V_16 )
goto V_27;
V_16 = - V_45 ;
while ( V_10 -> V_28 ( & V_15 , V_13 ) == 0 ) {
if ( F_11 ( V_29 , V_13 ) ) {
V_16 = 0 ;
break;
}
}
V_27:
F_5 ( & V_25 ) ;
V_23:
V_10 -> free ( & V_15 ) ;
V_18:
return V_16 ;
}
static int
F_15 ( const struct V_46 * V_47 , const struct V_5 * V_5 ,
struct V_39 * V_39 )
{
const unsigned int V_30 = F_3 ( V_47 -> V_48 ) -> V_49 ;
const unsigned char * V_29 ;
unsigned long V_50 ;
int V_40 ;
if ( V_39 -> V_41 < V_30 )
return 0 ;
V_39 -> V_41 = V_40 = V_30 ;
V_29 = V_39 -> V_29 ;
V_50 = F_16 () ;
while ( V_40 -- ) {
char V_51 ;
V_51 = * V_29 ++ ;
if ( V_51 >= 'A' && V_51 <= 'Z' )
V_51 += 'a' - 'A' ;
V_50 = F_17 ( V_51 , V_50 ) ;
}
V_39 -> V_50 = F_18 ( V_50 ) ;
return 0 ;
}
static int
F_19 ( const struct V_46 * V_47 , const struct V_5 * V_52 ,
const struct V_46 * V_46 , const struct V_5 * V_5 ,
unsigned int V_41 , const char * V_53 , const struct V_39 * V_29 )
{
int V_40 ;
if ( V_41 != V_29 -> V_41 )
return 1 ;
for ( V_40 = 0 ; V_40 < V_29 -> V_41 ; V_40 ++ ) {
char V_54 , V_55 ;
V_54 = V_53 [ V_40 ] ;
V_55 = V_29 -> V_29 [ V_40 ] ;
if ( V_54 >= 'A' && V_54 <= 'Z' )
V_54 += 'a' - 'A' ;
if ( V_55 >= 'A' && V_55 <= 'Z' )
V_55 += 'a' - 'A' ;
if ( V_54 != V_55 )
return 1 ;
}
return 0 ;
}
static struct V_46 *
F_20 ( struct V_5 * V_15 , struct V_46 * V_46 , unsigned int V_56 )
{
struct V_5 * V_5 = NULL ;
struct V_12 V_13 ;
int error ;
error = F_12 ( V_15 , & V_46 -> V_57 , & V_13 ) ;
if ( error == 0 ) {
error = - V_58 ;
V_5 = F_21 ( V_15 -> V_8 , & V_13 ) ;
if ( V_5 )
error = 0 ;
}
F_22 ( V_46 , V_5 ) ;
return F_23 ( error ) ;
}
