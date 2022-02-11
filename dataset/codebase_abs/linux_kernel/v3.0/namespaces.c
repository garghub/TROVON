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
V_1 -> V_22 = & V_23 ;
F_5 ( V_1 , V_2 ) ;
if ( F_6 ( V_1 , NULL ) )
error = NULL ;
V_14:
return error ;
V_16:
F_7 ( V_2 ) ;
goto V_14;
}
static int F_8 ( struct V_24 * V_25 , void * V_26 ,
T_1 V_27 , struct V_4 * V_5 ,
const struct V_7 * V_28 )
{
return F_9 ( V_25 , V_26 , V_27 ,
V_28 -> V_29 , strlen ( V_28 -> V_29 ) ,
F_1 , V_5 , V_28 ) ;
}
static int F_10 ( struct V_24 * V_25 , void * V_26 ,
T_1 V_27 )
{
int V_30 ;
struct V_1 * V_1 = V_25 -> V_31 . V_1 ;
struct V_2 * V_2 = V_1 -> V_32 ;
struct V_4 * V_5 = F_11 ( V_2 ) ;
const struct V_7 * * V_33 , * * V_34 ;
T_2 V_35 ;
int V_36 ;
V_36 = - V_11 ;
if ( ! V_5 )
goto V_37;
V_36 = - V_38 ;
if ( ! F_12 ( V_5 , V_39 ) )
goto V_14;
V_36 = 0 ;
V_30 = V_25 -> V_40 ;
switch ( V_30 ) {
case 0 :
V_35 = V_2 -> V_41 ;
if ( V_27 ( V_26 , L_1 , 1 , V_30 , V_35 , V_42 ) < 0 )
goto V_14;
V_30 ++ ;
V_25 -> V_40 ++ ;
case 1 :
V_35 = F_13 ( V_1 ) ;
if ( V_27 ( V_26 , L_2 , 2 , V_30 , V_35 , V_42 ) < 0 )
goto V_14;
V_30 ++ ;
V_25 -> V_40 ++ ;
default:
V_30 -= 2 ;
if ( V_30 >= F_14 ( V_43 ) ) {
V_36 = 1 ;
goto V_14;
}
V_33 = V_43 + V_30 ;
V_34 = & V_43 [ F_14 ( V_43 ) - 1 ] ;
while ( V_33 <= V_34 ) {
if ( F_8 ( V_25 , V_26 , V_27 ,
V_5 , * V_33 ) < 0 )
goto V_14;
V_25 -> V_40 ++ ;
V_33 ++ ;
}
}
V_36 = 1 ;
V_14:
F_15 ( V_5 ) ;
V_37:
return V_36 ;
}
static struct V_1 * F_16 ( struct V_2 * V_3 ,
struct V_1 * V_1 , struct V_44 * V_45 )
{
struct V_1 * error ;
struct V_4 * V_5 = F_11 ( V_3 ) ;
const struct V_7 * * V_33 , * * V_34 ;
unsigned int V_46 = V_1 -> V_47 . V_46 ;
error = F_2 ( - V_11 ) ;
if ( ! V_5 )
goto V_37;
error = F_2 ( - V_38 ) ;
if ( ! F_12 ( V_5 , V_39 ) )
goto V_14;
V_34 = & V_43 [ F_14 ( V_43 ) - 1 ] ;
for ( V_33 = V_43 ; V_33 <= V_34 ; V_33 ++ ) {
if ( strlen ( ( * V_33 ) -> V_29 ) != V_46 )
continue;
if ( ! memcmp ( V_1 -> V_47 . V_29 , ( * V_33 ) -> V_29 , V_46 ) )
break;
}
error = F_2 ( - V_11 ) ;
if ( V_33 > V_34 )
goto V_14;
error = F_1 ( V_3 , V_1 , V_5 , * V_33 ) ;
V_14:
F_15 ( V_5 ) ;
V_37:
return error ;
}
struct V_24 * F_17 ( int V_48 )
{
struct V_24 * V_24 ;
V_24 = F_18 ( V_48 ) ;
if ( ! V_24 )
return F_2 ( - V_49 ) ;
if ( V_24 -> V_50 != & V_21 )
goto V_51;
return V_24 ;
V_51:
F_19 ( V_24 ) ;
return F_2 ( - V_52 ) ;
}
