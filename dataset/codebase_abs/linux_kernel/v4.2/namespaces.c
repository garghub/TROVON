static const char * F_1 ( struct V_1 * V_1 , void * * V_2 )
{
struct V_3 * V_3 = F_2 ( V_1 ) ;
const struct V_4 * V_5 = F_3 ( V_3 ) -> V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
void * error = F_4 ( - V_10 ) ;
V_7 = F_5 ( V_3 ) ;
if ( ! V_7 )
return error ;
if ( F_6 ( V_7 , V_11 ) ) {
error = F_7 ( & V_9 , V_7 , V_5 ) ;
if ( ! error )
F_8 ( & V_9 ) ;
}
F_9 ( V_7 ) ;
return error ;
}
static int F_10 ( struct V_1 * V_1 , char T_1 * V_12 , int V_13 )
{
struct V_3 * V_3 = F_2 ( V_1 ) ;
const struct V_4 * V_5 = F_3 ( V_3 ) -> V_5 ;
struct V_6 * V_7 ;
char V_14 [ 50 ] ;
int V_15 = - V_10 ;
V_7 = F_5 ( V_3 ) ;
if ( ! V_7 )
return V_15 ;
if ( F_6 ( V_7 , V_11 ) ) {
V_15 = F_11 ( V_14 , sizeof( V_14 ) , V_7 , V_5 ) ;
if ( V_15 >= 0 )
V_15 = F_12 ( V_12 , V_13 , V_14 ) ;
}
F_9 ( V_7 ) ;
return V_15 ;
}
static int F_13 ( struct V_3 * V_16 ,
struct V_1 * V_1 , struct V_6 * V_7 , const void * V_17 )
{
const struct V_4 * V_5 = V_17 ;
struct V_3 * V_3 ;
struct V_18 * V_19 ;
V_3 = F_14 ( V_16 -> V_20 , V_7 ) ;
if ( ! V_3 )
goto V_21;
V_19 = F_3 ( V_3 ) ;
V_3 -> V_22 = V_23 | V_24 ;
V_3 -> V_25 = & V_26 ;
V_19 -> V_5 = V_5 ;
F_15 ( V_1 , & V_27 ) ;
F_16 ( V_1 , V_3 ) ;
if ( F_17 ( V_1 , 0 ) )
return 0 ;
V_21:
return - V_28 ;
}
static int F_18 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
struct V_6 * V_7 = F_5 ( F_19 ( V_29 ) ) ;
const struct V_4 * * V_32 , * * V_33 ;
if ( ! V_7 )
return - V_28 ;
if ( ! F_20 ( V_29 , V_31 ) )
goto V_21;
if ( V_31 -> V_34 >= 2 + F_21 ( V_35 ) )
goto V_21;
V_32 = V_35 + ( V_31 -> V_34 - 2 ) ;
V_33 = & V_35 [ F_21 ( V_35 ) - 1 ] ;
while ( V_32 <= V_33 ) {
const struct V_4 * V_36 = * V_32 ;
if ( ! F_22 ( V_29 , V_31 , V_36 -> V_14 , strlen ( V_36 -> V_14 ) ,
F_13 , V_7 , V_36 ) )
break;
V_31 -> V_34 ++ ;
V_32 ++ ;
}
V_21:
F_9 ( V_7 ) ;
return 0 ;
}
static struct V_1 * F_23 ( struct V_3 * V_16 ,
struct V_1 * V_1 , unsigned int V_37 )
{
int error ;
struct V_6 * V_7 = F_5 ( V_16 ) ;
const struct V_4 * * V_32 , * * V_33 ;
unsigned int V_38 = V_1 -> V_39 . V_38 ;
error = - V_28 ;
if ( ! V_7 )
goto V_40;
V_33 = & V_35 [ F_21 ( V_35 ) ] ;
for ( V_32 = V_35 ; V_32 < V_33 ; V_32 ++ ) {
if ( strlen ( ( * V_32 ) -> V_14 ) != V_38 )
continue;
if ( ! memcmp ( V_1 -> V_39 . V_14 , ( * V_32 ) -> V_14 , V_38 ) )
break;
}
if ( V_32 == V_33 )
goto V_21;
error = F_13 ( V_16 , V_1 , V_7 , * V_32 ) ;
V_21:
F_9 ( V_7 ) ;
V_40:
return F_4 ( error ) ;
}
