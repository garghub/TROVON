int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( V_6 , L_1 ,
V_3 -> V_3 , V_1 -> V_7 . V_8 ) ;
V_5 = V_1 -> V_9 ;
if ( ! V_5 ) {
V_5 = F_3 ( sizeof( struct V_4 ) , V_10 ) ;
if ( ! V_5 )
return - V_11 ;
F_4 ( & V_5 -> V_12 ) ;
F_5 ( & V_5 -> V_13 ) ;
V_1 -> V_9 = V_5 ;
}
F_6 ( & V_5 -> V_12 ) ;
F_7 ( & V_3 -> V_14 , & V_5 -> V_13 ) ;
F_8 ( & V_5 -> V_12 ) ;
return 0 ;
}
static struct V_2 * F_9 ( struct V_1 * V_1 , T_1 V_15 , int V_16 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 , * V_17 ;
F_2 ( V_6 , L_2 ,
V_1 -> V_7 . V_8 , V_1 , V_15 , V_16 ) ;
V_5 = (struct V_4 * ) V_1 -> V_9 ;
V_17 = NULL ;
if ( V_5 ) {
F_6 ( & V_5 -> V_12 ) ;
F_10 (fid, &dent->fidlist, dlist) {
if ( V_16 || V_3 -> V_15 == V_15 ) {
V_17 = V_3 ;
break;
}
}
F_8 ( & V_5 -> V_12 ) ;
}
return V_17 ;
}
static int F_11 ( struct V_18 * V_19 ,
struct V_1 * V_1 , char * * * V_20 )
{
int V_21 = 0 , V_22 ;
char * * V_23 ;
struct V_1 * V_24 ;
for ( V_24 = V_1 ; ! F_12 ( V_24 ) ; V_24 = V_24 -> V_25 )
V_21 ++ ;
V_23 = F_3 ( sizeof( char * ) * V_21 , V_10 ) ;
if ( ! V_23 )
goto V_26;
for ( V_24 = V_1 , V_22 = ( V_21 - 1 ) ; V_22 >= 0 ; V_22 -- , V_24 = V_24 -> V_25 )
V_23 [ V_22 ] = ( char * ) V_24 -> V_7 . V_8 ;
* V_20 = V_23 ;
return V_21 ;
V_26:
return - V_11 ;
}
static struct V_2 * F_13 ( struct V_1 * V_1 ,
T_2 V_15 , int V_16 )
{
struct V_1 * V_24 ;
char * * V_23 , * V_27 ;
int V_22 , V_21 , V_28 , V_29 , V_30 ;
struct V_18 * V_19 ;
struct V_2 * V_3 , * V_31 = NULL ;
V_19 = F_14 ( V_1 ) ;
V_30 = V_19 -> V_32 & V_33 ;
V_3 = F_9 ( V_1 , V_15 , V_16 ) ;
if ( V_3 )
return V_3 ;
F_15 ( & V_19 -> V_34 ) ;
V_24 = V_1 -> V_25 ;
V_3 = F_9 ( V_24 , V_15 , V_16 ) ;
if ( V_3 ) {
V_3 = F_16 ( V_3 , 1 , ( char * * ) & V_1 -> V_7 . V_8 , 1 ) ;
goto V_35;
}
F_17 ( & V_19 -> V_34 ) ;
V_3 = F_9 ( V_1 -> V_36 -> V_37 , V_15 , V_16 ) ;
if ( ! V_3 ) {
if ( V_30 == V_38 )
return F_18 ( - V_39 ) ;
if ( F_19 ( V_19 ) || F_20 ( V_19 ) )
V_27 = NULL ;
else
V_27 = V_19 -> V_27 ;
V_3 = F_21 ( V_19 -> V_40 , NULL , V_27 , V_15 ,
V_19 -> V_41 ) ;
if ( F_22 ( V_3 ) )
return V_3 ;
F_1 ( V_1 -> V_36 -> V_37 , V_3 ) ;
}
if ( V_1 -> V_36 -> V_37 == V_1 )
return V_3 ;
F_15 ( & V_19 -> V_34 ) ;
V_21 = F_11 ( V_19 , V_1 , & V_23 ) ;
if ( V_21 < 0 ) {
V_3 = F_18 ( V_21 ) ;
goto V_26;
}
V_29 = 1 ;
V_22 = 0 ;
while ( V_22 < V_21 ) {
V_28 = F_23 ( V_21 - V_22 , V_42 ) ;
V_3 = F_16 ( V_3 , V_28 , & V_23 [ V_22 ] , V_29 ) ;
if ( F_22 ( V_3 ) ) {
if ( V_31 ) {
F_24 ( V_31 ) ;
}
F_25 ( V_23 ) ;
goto V_26;
}
V_31 = V_3 ;
V_22 += V_28 ;
V_29 = 0 ;
}
F_25 ( V_23 ) ;
V_35:
if ( ! F_22 ( V_3 ) )
F_1 ( V_1 , V_3 ) ;
V_26:
F_17 ( & V_19 -> V_34 ) ;
return V_3 ;
}
struct V_2 * F_26 ( struct V_1 * V_1 )
{
T_2 V_15 ;
int V_16 , V_30 ;
struct V_18 * V_19 ;
V_19 = F_14 ( V_1 ) ;
V_30 = V_19 -> V_32 & V_33 ;
switch ( V_30 ) {
case V_38 :
case V_43 :
case V_44 :
V_15 = F_27 () ;
V_16 = 0 ;
break;
case V_45 :
V_15 = V_19 -> V_15 ;
V_16 = 1 ;
break;
default:
V_15 = ~ 0 ;
V_16 = 0 ;
break;
}
return F_13 ( V_1 , V_15 , V_16 ) ;
}
struct V_2 * F_28 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_17 ;
V_3 = F_26 ( V_1 ) ;
if ( F_22 ( V_3 ) )
return V_3 ;
V_17 = F_16 ( V_3 , 0 , NULL , 1 ) ;
return V_17 ;
}
static struct V_2 * F_29 ( struct V_1 * V_1 , T_2 V_15 )
{
struct V_2 * V_3 , * V_17 ;
V_3 = F_13 ( V_1 , V_15 , 0 ) ;
if ( F_22 ( V_3 ) )
return V_3 ;
V_17 = F_16 ( V_3 , 0 , NULL , 1 ) ;
return V_17 ;
}
struct V_2 * F_30 ( struct V_1 * V_1 )
{
int V_46 ;
struct V_2 * V_3 ;
V_3 = F_29 ( V_1 , 0 ) ;
if ( F_22 ( V_3 ) )
goto V_47;
V_46 = F_31 ( V_3 , V_48 ) ;
if ( V_46 < 0 ) {
F_24 ( V_3 ) ;
V_3 = F_18 ( V_46 ) ;
goto V_47;
}
V_47:
return V_3 ;
}
