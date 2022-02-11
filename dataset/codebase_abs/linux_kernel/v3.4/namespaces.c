static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_1 , struct V_4 * V_5 , const void * V_6 )
{
const struct V_7 * V_8 = V_6 ;
struct V_2 * V_2 ;
struct V_9 * V_10 ;
struct V_1 * error = F_2 ( - V_11 ) ;
void * V_12 ;
V_2 = F_3 ( V_3 -> V_13 , V_5 ) ;
if ( ! V_2 )
goto V_14;
V_12 = V_8 -> V_15 ( V_5 ) ;
if ( ! V_12 )
goto V_16;
V_10 = F_4 ( V_2 ) ;
V_2 -> V_17 = V_18 | V_19 ;
V_2 -> V_20 = & V_21 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_12 = V_12 ;
F_5 ( V_1 , & V_22 ) ;
F_6 ( V_1 , V_2 ) ;
if ( F_7 ( V_1 , NULL ) )
error = NULL ;
V_14:
return error ;
V_16:
F_8 ( V_2 ) ;
goto V_14;
}
static int F_9 ( struct V_23 * V_24 , void * V_25 ,
T_1 V_26 , struct V_4 * V_5 ,
const struct V_7 * V_27 )
{
return F_10 ( V_24 , V_25 , V_26 ,
V_27 -> V_28 , strlen ( V_27 -> V_28 ) ,
F_1 , V_5 , V_27 ) ;
}
static int F_11 ( struct V_23 * V_24 , void * V_25 ,
T_1 V_26 )
{
int V_29 ;
struct V_1 * V_1 = V_24 -> V_30 . V_1 ;
struct V_2 * V_2 = V_1 -> V_31 ;
struct V_4 * V_5 = F_12 ( V_2 ) ;
const struct V_7 * * V_32 , * * V_33 ;
T_2 V_34 ;
int V_35 ;
V_35 = - V_11 ;
if ( ! V_5 )
goto V_36;
V_35 = - V_37 ;
if ( ! F_13 ( V_5 , V_38 ) )
goto V_14;
V_35 = 0 ;
V_29 = V_24 -> V_39 ;
switch ( V_29 ) {
case 0 :
V_34 = V_2 -> V_40 ;
if ( V_26 ( V_25 , L_1 , 1 , V_29 , V_34 , V_41 ) < 0 )
goto V_14;
V_29 ++ ;
V_24 -> V_39 ++ ;
case 1 :
V_34 = F_14 ( V_1 ) ;
if ( V_26 ( V_25 , L_2 , 2 , V_29 , V_34 , V_41 ) < 0 )
goto V_14;
V_29 ++ ;
V_24 -> V_39 ++ ;
default:
V_29 -= 2 ;
if ( V_29 >= F_15 ( V_42 ) ) {
V_35 = 1 ;
goto V_14;
}
V_32 = V_42 + V_29 ;
V_33 = & V_42 [ F_15 ( V_42 ) - 1 ] ;
while ( V_32 <= V_33 ) {
if ( F_9 ( V_24 , V_25 , V_26 ,
V_5 , * V_32 ) < 0 )
goto V_14;
V_24 -> V_39 ++ ;
V_32 ++ ;
}
}
V_35 = 1 ;
V_14:
F_16 ( V_5 ) ;
V_36:
return V_35 ;
}
static struct V_1 * F_17 ( struct V_2 * V_3 ,
struct V_1 * V_1 , struct V_43 * V_44 )
{
struct V_1 * error ;
struct V_4 * V_5 = F_12 ( V_3 ) ;
const struct V_7 * * V_32 , * * V_33 ;
unsigned int V_45 = V_1 -> V_46 . V_45 ;
error = F_2 ( - V_11 ) ;
if ( ! V_5 )
goto V_36;
error = F_2 ( - V_37 ) ;
if ( ! F_13 ( V_5 , V_38 ) )
goto V_14;
V_33 = & V_42 [ F_15 ( V_42 ) ] ;
for ( V_32 = V_42 ; V_32 < V_33 ; V_32 ++ ) {
if ( strlen ( ( * V_32 ) -> V_28 ) != V_45 )
continue;
if ( ! memcmp ( V_1 -> V_46 . V_28 , ( * V_32 ) -> V_28 , V_45 ) )
break;
}
error = F_2 ( - V_11 ) ;
if ( V_32 == V_33 )
goto V_14;
error = F_1 ( V_3 , V_1 , V_5 , * V_32 ) ;
V_14:
F_16 ( V_5 ) ;
V_36:
return error ;
}
struct V_23 * F_18 ( int V_47 )
{
struct V_23 * V_23 ;
V_23 = F_19 ( V_47 ) ;
if ( ! V_23 )
return F_2 ( - V_48 ) ;
if ( V_23 -> V_49 != & V_21 )
goto V_50;
return V_23 ;
V_50:
F_20 ( V_23 ) ;
return F_2 ( - V_51 ) ;
}
