bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( F_3 ( V_4 ) ) ;
struct V_6 * V_7 = & V_2 -> V_8 [ V_5 ] ;
F_4 ( & V_7 -> V_9 ) ;
F_5 ( V_7 -> V_10 < 0 ) ;
if ( F_6 ( V_4 ) ) {
F_7 ( V_4 , & V_7 -> V_11 ) ;
if ( V_7 -> V_10 ++ == 0 )
F_8 ( V_5 , V_2 -> V_12 ) ;
F_9 ( & V_7 -> V_9 ) ;
return true ;
}
F_9 ( & V_7 -> V_9 ) ;
return false ;
}
bool F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = F_2 ( F_3 ( V_4 ) ) ;
struct V_6 * V_7 = & V_2 -> V_8 [ V_5 ] ;
F_4 ( & V_7 -> V_9 ) ;
if ( ! F_6 ( V_4 ) ) {
F_11 ( V_4 ) ;
if ( -- V_7 -> V_10 == 0 )
F_12 ( V_5 , V_2 -> V_12 ) ;
F_5 ( V_7 -> V_10 < 0 ) ;
F_9 ( & V_7 -> V_9 ) ;
return true ;
}
F_9 ( & V_7 -> V_9 ) ;
return false ;
}
unsigned long
F_13 ( struct V_1 * V_2 , int V_5 )
{
unsigned long V_13 = 0 ;
struct V_6 * V_7 = & V_2 -> V_8 [ V_5 ] ;
F_4 ( & V_7 -> V_9 ) ;
F_5 ( V_7 -> V_10 < 0 ) ;
V_13 += V_7 -> V_10 ;
F_9 ( & V_7 -> V_9 ) ;
return V_13 ;
}
unsigned long
F_14 ( struct V_1 * V_2 , int V_5 , T_1 V_14 ,
void * V_15 , unsigned long * V_16 )
{
struct V_6 * V_7 = & V_2 -> V_8 [ V_5 ] ;
struct V_3 * V_4 , * V_17 ;
unsigned long V_18 = 0 ;
F_4 ( & V_7 -> V_9 ) ;
V_19:
F_15 (item, n, &nlru->list) {
enum V_20 V_21 ;
if ( ! * V_16 )
break;
-- * V_16 ;
V_21 = V_14 ( V_4 , & V_7 -> V_9 , V_15 ) ;
switch ( V_21 ) {
case V_22 :
if ( -- V_7 -> V_10 == 0 )
F_12 ( V_5 , V_2 -> V_12 ) ;
F_5 ( V_7 -> V_10 < 0 ) ;
V_18 ++ ;
break;
case V_23 :
F_16 ( V_4 , & V_7 -> V_11 ) ;
break;
case V_24 :
break;
case V_25 :
goto V_19;
default:
F_17 () ;
}
}
F_9 ( & V_7 -> V_9 ) ;
return V_18 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_26 ;
T_2 V_27 = sizeof( * V_2 -> V_8 ) * V_28 ;
V_2 -> V_8 = F_19 ( V_27 , V_29 ) ;
if ( ! V_2 -> V_8 )
return - V_30 ;
F_20 ( V_2 -> V_12 ) ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ ) {
F_21 ( & V_2 -> V_8 [ V_26 ] . V_9 ) ;
F_22 ( & V_2 -> V_8 [ V_26 ] . V_11 ) ;
V_2 -> V_8 [ V_26 ] . V_10 = 0 ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_8 ) ;
}
