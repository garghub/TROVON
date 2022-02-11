static void * F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
const struct V_5 * V_6 = F_3 ( V_4 ) -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
void * error = F_4 ( - V_11 ) ;
V_8 = F_5 ( V_4 ) ;
if ( ! V_8 )
return error ;
if ( F_6 ( V_8 , V_12 ) ) {
error = F_7 ( & V_10 , V_8 , V_6 ) ;
if ( ! error )
F_8 ( V_3 , & V_10 ) ;
}
F_9 ( V_8 ) ;
return error ;
}
static int F_10 ( struct V_1 * V_1 , char T_1 * V_13 , int V_14 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
const struct V_5 * V_6 = F_3 ( V_4 ) -> V_6 ;
struct V_7 * V_8 ;
char V_15 [ 50 ] ;
int V_16 = - V_11 ;
V_8 = F_5 ( V_4 ) ;
if ( ! V_8 )
return V_16 ;
if ( F_6 ( V_8 , V_12 ) ) {
V_16 = F_11 ( V_15 , sizeof( V_15 ) , V_8 , V_6 ) ;
if ( V_16 >= 0 )
V_16 = F_12 ( V_13 , V_14 , V_15 ) ;
}
F_9 ( V_8 ) ;
return V_16 ;
}
static int F_13 ( struct V_4 * V_17 ,
struct V_1 * V_1 , struct V_7 * V_8 , const void * V_18 )
{
const struct V_5 * V_6 = V_18 ;
struct V_4 * V_4 ;
struct V_19 * V_20 ;
V_4 = F_14 ( V_17 -> V_21 , V_8 ) ;
if ( ! V_4 )
goto V_22;
V_20 = F_3 ( V_4 ) ;
V_4 -> V_23 = V_24 | V_25 ;
V_4 -> V_26 = & V_27 ;
V_20 -> V_6 = V_6 ;
F_15 ( V_1 , & V_28 ) ;
F_16 ( V_1 , V_4 ) ;
if ( F_17 ( V_1 , 0 ) )
return 0 ;
V_22:
return - V_29 ;
}
static int F_18 ( struct V_30 * V_30 , struct V_31 * V_32 )
{
struct V_7 * V_8 = F_5 ( F_19 ( V_30 ) ) ;
const struct V_5 * * V_33 , * * V_34 ;
if ( ! V_8 )
return - V_29 ;
if ( ! F_20 ( V_30 , V_32 ) )
goto V_22;
if ( V_32 -> V_35 >= 2 + F_21 ( V_36 ) )
goto V_22;
V_33 = V_36 + ( V_32 -> V_35 - 2 ) ;
V_34 = & V_36 [ F_21 ( V_36 ) - 1 ] ;
while ( V_33 <= V_34 ) {
const struct V_5 * V_37 = * V_33 ;
if ( ! F_22 ( V_30 , V_32 , V_37 -> V_15 , strlen ( V_37 -> V_15 ) ,
F_13 , V_8 , V_37 ) )
break;
V_32 -> V_35 ++ ;
V_33 ++ ;
}
V_22:
F_9 ( V_8 ) ;
return 0 ;
}
static struct V_1 * F_23 ( struct V_4 * V_17 ,
struct V_1 * V_1 , unsigned int V_38 )
{
int error ;
struct V_7 * V_8 = F_5 ( V_17 ) ;
const struct V_5 * * V_33 , * * V_34 ;
unsigned int V_39 = V_1 -> V_40 . V_39 ;
error = - V_29 ;
if ( ! V_8 )
goto V_41;
V_34 = & V_36 [ F_21 ( V_36 ) ] ;
for ( V_33 = V_36 ; V_33 < V_34 ; V_33 ++ ) {
if ( strlen ( ( * V_33 ) -> V_15 ) != V_39 )
continue;
if ( ! memcmp ( V_1 -> V_40 . V_15 , ( * V_33 ) -> V_15 , V_39 ) )
break;
}
if ( V_33 == V_34 )
goto V_22;
error = F_13 ( V_17 , V_1 , V_8 , * V_33 ) ;
V_22:
F_9 ( V_8 ) ;
V_41:
return F_4 ( error ) ;
}
