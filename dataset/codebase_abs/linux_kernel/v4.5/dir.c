static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = F_3 ( V_6 ) -> V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_15 = 0 ;
if ( V_3 -> V_16 >> 32 )
return 0 ;
V_15 = V_9 -> V_17 ( V_6 , V_4 -> V_18 , V_4 -> V_19 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( V_3 -> V_16 == 0 ) {
if ( ! F_4 ( V_1 , V_3 ) )
goto V_20;
V_3 -> V_16 = 1 ;
}
if ( V_3 -> V_16 == 1 ) {
if ( ! F_5 ( V_3 , L_1 , 2 , V_14 . V_21 , V_22 ) )
goto V_20;
V_3 -> V_16 = 2 ;
}
F_6 ( & V_23 ) ;
V_15 = V_9 -> V_24 ( & V_14 , V_3 -> V_16 - 2 ) ;
if ( V_15 )
goto V_25;
while ( V_9 -> V_26 ( & V_14 , & V_12 ) == 0 ) {
if ( ! F_5 ( V_3 , V_12 . V_27 , V_12 . V_28 ,
V_12 . V_29 , V_30 ) )
break;
V_3 -> V_16 ++ ;
}
V_25:
F_7 ( & V_23 ) ;
V_20:
V_9 -> free ( & V_14 ) ;
return V_15 ;
}
int
F_8 ( struct V_5 * V_6 , struct V_11 * V_12 , int V_31 )
{
int V_15 = - V_32 ;
#ifdef F_9
const struct V_8 * V_9 = F_3 ( V_6 ) -> V_10 ;
struct V_13 V_14 ;
F_10 ( V_33 L_2 ,
V_12 -> V_29 , V_12 -> V_21 ) ;
if ( ! V_9 -> V_34 ) {
V_15 = - V_32 ;
goto V_35;
}
V_15 = V_9 -> V_17 ( V_6 , V_12 -> V_21 , 0 , & V_14 ) ;
if ( V_15 )
goto V_35;
F_11 ( & V_23 ) ;
V_15 = V_9 -> V_34 ( & V_14 , V_12 ) ;
F_12 ( & V_23 ) ;
if ( V_31 ) {
int V_36 = V_9 -> V_37 ( & V_14 ) ;
if ( ! V_15 )
V_15 = V_36 ;
}
V_9 -> free ( & V_14 ) ;
V_35:
#endif
return V_15 ;
}
static int
F_13 ( struct V_38 * V_27 , struct V_11 * V_12 )
{
int V_39 ;
if ( V_27 -> V_40 != V_12 -> V_28 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_27 -> V_40 ; V_39 ++ ) {
char V_41 , V_42 ;
V_41 = V_27 -> V_27 [ V_39 ] ;
V_42 = V_12 -> V_27 [ V_39 ] ;
if ( V_41 >= 'A' && V_41 <= 'Z' )
V_41 += 'a' - 'A' ;
if ( V_42 >= 'A' && V_42 <= 'Z' )
V_42 += 'a' - 'A' ;
if ( V_41 != V_42 )
return 0 ;
}
return 1 ;
}
static int
F_14 ( struct V_4 * V_4 , struct V_38 * V_27 , struct V_11 * V_12 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = F_3 ( V_6 ) -> V_10 ;
struct V_13 V_14 ;
int V_15 ;
V_15 = V_9 -> V_17 ( V_6 , V_4 -> V_18 , V_4 -> V_19 , & V_14 ) ;
if ( V_15 )
goto V_35;
if ( F_15 ( V_4 ) -> V_21 != V_14 . V_21 ) {
F_16 ( V_6 , L_3 ,
F_15 ( V_4 ) -> V_21 , V_14 . V_21 ) ;
V_15 = - V_43 ;
goto V_20;
}
V_12 -> V_21 = V_4 -> V_18 ;
if ( V_27 -> V_40 == 2 && V_27 -> V_27 [ 0 ] == '.' && V_27 -> V_27 [ 1 ] == '.' ) {
V_12 -> V_28 = 0 ;
V_12 -> V_29 = V_12 -> V_21 ;
goto V_20;
}
F_6 ( & V_23 ) ;
V_15 = V_9 -> V_24 ( & V_14 , 0 ) ;
if ( V_15 )
goto V_25;
V_15 = - V_44 ;
while ( V_9 -> V_26 ( & V_14 , V_12 ) == 0 ) {
if ( F_13 ( V_27 , V_12 ) ) {
V_15 = 0 ;
break;
}
}
V_25:
F_7 ( & V_23 ) ;
V_20:
V_9 -> free ( & V_14 ) ;
V_35:
return V_15 ;
}
static int
F_17 ( const struct V_45 * V_46 , struct V_38 * V_38 )
{
const unsigned int V_28 = F_3 ( V_46 -> V_47 ) -> V_48 ;
const unsigned char * V_27 ;
unsigned long V_49 ;
int V_39 ;
if ( V_38 -> V_40 < V_28 )
return 0 ;
V_38 -> V_40 = V_39 = V_28 ;
V_27 = V_38 -> V_27 ;
V_49 = F_18 () ;
while ( V_39 -- ) {
char V_50 ;
V_50 = * V_27 ++ ;
if ( V_50 >= 'A' && V_50 <= 'Z' )
V_50 += 'a' - 'A' ;
V_49 = F_19 ( V_50 , V_49 ) ;
}
V_38 -> V_49 = F_20 ( V_49 ) ;
return 0 ;
}
static int
F_21 ( const struct V_45 * V_46 , const struct V_45 * V_45 ,
unsigned int V_40 , const char * V_51 , const struct V_38 * V_27 )
{
int V_39 ;
if ( V_40 != V_27 -> V_40 )
return 1 ;
for ( V_39 = 0 ; V_39 < V_27 -> V_40 ; V_39 ++ ) {
char V_52 , V_53 ;
V_52 = V_51 [ V_39 ] ;
V_53 = V_27 -> V_27 [ V_39 ] ;
if ( V_52 >= 'A' && V_52 <= 'Z' )
V_52 += 'a' - 'A' ;
if ( V_53 >= 'A' && V_53 <= 'Z' )
V_53 += 'a' - 'A' ;
if ( V_52 != V_53 )
return 1 ;
}
return 0 ;
}
static struct V_45 *
F_22 ( struct V_4 * V_14 , struct V_45 * V_45 , unsigned int V_54 )
{
struct V_4 * V_4 = NULL ;
struct V_11 V_12 ;
int error ;
error = F_14 ( V_14 , & V_45 -> V_55 , & V_12 ) ;
if ( error == 0 ) {
error = - V_56 ;
V_4 = F_23 ( V_14 -> V_7 , & V_12 ) ;
if ( V_4 )
error = 0 ;
}
F_24 ( V_45 , V_4 ) ;
return F_25 ( error ) ;
}
