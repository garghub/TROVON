static const char * F_1 ( struct V_1 * V_1 ,
struct V_2 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
void * error = F_3 ( - V_11 ) ;
if ( ! V_1 )
return F_3 ( - V_12 ) ;
V_8 = F_4 ( V_2 ) ;
if ( ! V_8 )
return error ;
if ( F_5 ( V_8 , V_13 ) ) {
error = F_6 ( & V_10 , V_8 , V_6 ) ;
if ( ! error )
F_7 ( & V_10 ) ;
}
F_8 ( V_8 ) ;
return error ;
}
static int F_9 ( struct V_1 * V_1 , char T_1 * V_14 , int V_15 )
{
struct V_2 * V_2 = F_10 ( V_1 ) ;
const struct V_5 * V_6 = F_2 ( V_2 ) -> V_6 ;
struct V_7 * V_8 ;
char V_16 [ 50 ] ;
int V_17 = - V_11 ;
V_8 = F_4 ( V_2 ) ;
if ( ! V_8 )
return V_17 ;
if ( F_5 ( V_8 , V_13 ) ) {
V_17 = F_11 ( V_16 , sizeof( V_16 ) , V_8 , V_6 ) ;
if ( V_17 >= 0 )
V_17 = F_12 ( V_14 , V_15 , V_16 ) ;
}
F_8 ( V_8 ) ;
return V_17 ;
}
static int F_13 ( struct V_2 * V_18 ,
struct V_1 * V_1 , struct V_7 * V_8 , const void * V_19 )
{
const struct V_5 * V_6 = V_19 ;
struct V_2 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_14 ( V_18 -> V_22 , V_8 , V_23 | V_24 ) ;
if ( ! V_2 )
goto V_25;
V_21 = F_2 ( V_2 ) ;
V_2 -> V_26 = & V_27 ;
V_21 -> V_6 = V_6 ;
F_15 ( V_1 , & V_28 ) ;
F_16 ( V_1 , V_2 ) ;
if ( F_17 ( V_1 , 0 ) )
return 0 ;
V_25:
return - V_29 ;
}
static int F_18 ( struct V_30 * V_30 , struct V_31 * V_32 )
{
struct V_7 * V_8 = F_4 ( F_19 ( V_30 ) ) ;
const struct V_5 * * V_33 , * * V_34 ;
if ( ! V_8 )
return - V_29 ;
if ( ! F_20 ( V_30 , V_32 ) )
goto V_25;
if ( V_32 -> V_35 >= 2 + F_21 ( V_36 ) )
goto V_25;
V_33 = V_36 + ( V_32 -> V_35 - 2 ) ;
V_34 = & V_36 [ F_21 ( V_36 ) - 1 ] ;
while ( V_33 <= V_34 ) {
const struct V_5 * V_37 = * V_33 ;
if ( ! F_22 ( V_30 , V_32 , V_37 -> V_16 , strlen ( V_37 -> V_16 ) ,
F_13 , V_8 , V_37 ) )
break;
V_32 -> V_35 ++ ;
V_33 ++ ;
}
V_25:
F_8 ( V_8 ) ;
return 0 ;
}
static struct V_1 * F_23 ( struct V_2 * V_18 ,
struct V_1 * V_1 , unsigned int V_38 )
{
int error ;
struct V_7 * V_8 = F_4 ( V_18 ) ;
const struct V_5 * * V_33 , * * V_34 ;
unsigned int V_39 = V_1 -> V_40 . V_39 ;
error = - V_29 ;
if ( ! V_8 )
goto V_41;
V_34 = & V_36 [ F_21 ( V_36 ) ] ;
for ( V_33 = V_36 ; V_33 < V_34 ; V_33 ++ ) {
if ( strlen ( ( * V_33 ) -> V_16 ) != V_39 )
continue;
if ( ! memcmp ( V_1 -> V_40 . V_16 , ( * V_33 ) -> V_16 , V_39 ) )
break;
}
if ( V_33 == V_34 )
goto V_25;
error = F_13 ( V_18 , V_1 , V_8 , * V_33 ) ;
V_25:
F_8 ( V_8 ) ;
V_41:
return F_3 ( error ) ;
}
