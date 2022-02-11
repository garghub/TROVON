static void * F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
const struct V_6 * V_7 = F_2 ( V_4 ) -> V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 ;
void * error = F_3 ( - V_12 ) ;
V_9 = F_4 ( V_4 ) ;
if ( ! V_9 )
return error ;
if ( F_5 ( V_9 , V_13 ) ) {
error = F_6 ( & V_11 , V_9 , V_7 ) ;
if ( ! error )
F_7 ( V_3 , & V_11 ) ;
}
F_8 ( V_9 ) ;
return error ;
}
static int F_9 ( struct V_1 * V_1 , char T_1 * V_14 , int V_15 )
{
struct V_4 * V_4 = V_1 -> V_5 ;
const struct V_6 * V_7 = F_2 ( V_4 ) -> V_7 ;
struct V_8 * V_9 ;
char V_16 [ 50 ] ;
int V_17 = - V_12 ;
V_9 = F_4 ( V_4 ) ;
if ( ! V_9 )
return V_17 ;
if ( F_5 ( V_9 , V_13 ) ) {
V_17 = F_10 ( V_16 , sizeof( V_16 ) , V_9 , V_7 ) ;
if ( V_17 >= 0 )
V_17 = F_11 ( V_14 , V_15 , V_16 ) ;
}
F_8 ( V_9 ) ;
return V_17 ;
}
static int F_12 ( struct V_4 * V_18 ,
struct V_1 * V_1 , struct V_8 * V_9 , const void * V_19 )
{
const struct V_6 * V_7 = V_19 ;
struct V_4 * V_4 ;
struct V_20 * V_21 ;
V_4 = F_13 ( V_18 -> V_22 , V_9 ) ;
if ( ! V_4 )
goto V_23;
V_21 = F_2 ( V_4 ) ;
V_4 -> V_24 = V_25 | V_26 ;
V_4 -> V_27 = & V_28 ;
V_21 -> V_7 = V_7 ;
F_14 ( V_1 , & V_29 ) ;
F_15 ( V_1 , V_4 ) ;
if ( F_16 ( V_1 , 0 ) )
return 0 ;
V_23:
return - V_30 ;
}
static int F_17 ( struct V_31 * V_31 , struct V_32 * V_33 )
{
struct V_8 * V_9 = F_4 ( F_18 ( V_31 ) ) ;
const struct V_6 * * V_34 , * * V_35 ;
if ( ! V_9 )
return - V_30 ;
if ( ! F_19 ( V_31 , V_33 ) )
goto V_23;
if ( V_33 -> V_36 >= 2 + F_20 ( V_37 ) )
goto V_23;
V_34 = V_37 + ( V_33 -> V_36 - 2 ) ;
V_35 = & V_37 [ F_20 ( V_37 ) - 1 ] ;
while ( V_34 <= V_35 ) {
const struct V_6 * V_38 = * V_34 ;
if ( ! F_21 ( V_31 , V_33 , V_38 -> V_16 , strlen ( V_38 -> V_16 ) ,
F_12 , V_9 , V_38 ) )
break;
V_33 -> V_36 ++ ;
V_34 ++ ;
}
V_23:
F_8 ( V_9 ) ;
return 0 ;
}
static struct V_1 * F_22 ( struct V_4 * V_18 ,
struct V_1 * V_1 , unsigned int V_39 )
{
int error ;
struct V_8 * V_9 = F_4 ( V_18 ) ;
const struct V_6 * * V_34 , * * V_35 ;
unsigned int V_40 = V_1 -> V_41 . V_40 ;
error = - V_30 ;
if ( ! V_9 )
goto V_42;
V_35 = & V_37 [ F_20 ( V_37 ) ] ;
for ( V_34 = V_37 ; V_34 < V_35 ; V_34 ++ ) {
if ( strlen ( ( * V_34 ) -> V_16 ) != V_40 )
continue;
if ( ! memcmp ( V_1 -> V_41 . V_16 , ( * V_34 ) -> V_16 , V_40 ) )
break;
}
if ( V_34 == V_35 )
goto V_23;
error = F_12 ( V_18 , V_1 , V_9 , * V_34 ) ;
V_23:
F_8 ( V_9 ) ;
V_42:
return F_3 ( error ) ;
}
