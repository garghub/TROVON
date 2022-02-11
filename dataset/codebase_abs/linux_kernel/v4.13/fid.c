static inline void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_4 , (struct V_5 * ) & V_1 -> V_6 ) ;
}
void F_3 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_4 ( & V_1 -> V_7 ) ;
F_1 ( V_1 , V_3 ) ;
F_5 ( & V_1 -> V_7 ) ;
}
static struct V_2 * F_6 ( struct V_1 * V_1 , T_1 V_8 , int V_9 )
{
struct V_2 * V_3 , * V_10 ;
F_7 ( V_11 , L_1 ,
V_1 , V_1 , F_8 ( & V_12 , V_8 ) ,
V_9 ) ;
V_10 = NULL ;
if ( V_1 -> V_6 ) {
struct V_5 * V_13 = (struct V_5 * ) & V_1 -> V_6 ;
F_4 ( & V_1 -> V_7 ) ;
F_9 (fid, h, dlist) {
if ( V_9 || F_10 ( V_3 -> V_8 , V_8 ) ) {
V_10 = V_3 ;
break;
}
}
F_5 ( & V_1 -> V_7 ) ;
}
return V_10 ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_1 * V_1 , const unsigned char * * * V_16 )
{
int V_17 = 0 , V_18 ;
const unsigned char * * V_19 ;
struct V_1 * V_20 ;
for ( V_20 = V_1 ; ! F_12 ( V_20 ) ; V_20 = V_20 -> V_21 )
V_17 ++ ;
V_19 = F_13 ( sizeof( char * ) * V_17 , V_22 ) ;
if ( ! V_19 )
goto V_23;
for ( V_20 = V_1 , V_18 = ( V_17 - 1 ) ; V_18 >= 0 ; V_18 -- , V_20 = V_20 -> V_21 )
V_19 [ V_18 ] = V_20 -> V_24 . V_25 ;
* V_16 = V_19 ;
return V_17 ;
V_23:
return - V_26 ;
}
static struct V_2 * F_14 ( struct V_1 * V_1 ,
T_1 V_8 , int V_9 )
{
struct V_1 * V_20 ;
const unsigned char * * V_19 , * V_27 ;
int V_18 , V_17 , V_28 , V_29 , V_30 ;
struct V_14 * V_15 ;
struct V_2 * V_3 , * V_31 = NULL ;
V_15 = F_15 ( V_1 ) ;
V_30 = V_15 -> V_32 & V_33 ;
V_3 = F_6 ( V_1 , V_8 , V_9 ) ;
if ( V_3 )
return V_3 ;
F_16 ( & V_15 -> V_34 ) ;
V_20 = V_1 -> V_21 ;
V_3 = F_6 ( V_20 , V_8 , V_9 ) ;
if ( V_3 ) {
V_3 = F_17 ( V_3 , 1 , & V_1 -> V_24 . V_25 , 1 ) ;
goto V_35;
}
F_18 ( & V_15 -> V_34 ) ;
V_3 = F_6 ( V_1 -> V_36 -> V_37 , V_8 , V_9 ) ;
if ( ! V_3 ) {
if ( V_30 == V_38 )
return F_19 ( - V_39 ) ;
if ( F_20 ( V_15 ) || F_21 ( V_15 ) )
V_27 = NULL ;
else
V_27 = V_15 -> V_27 ;
V_3 = F_22 ( V_15 -> V_40 , NULL , V_27 , V_8 ,
V_15 -> V_41 ) ;
if ( F_23 ( V_3 ) )
return V_3 ;
F_3 ( V_1 -> V_36 -> V_37 , V_3 ) ;
}
if ( V_1 -> V_36 -> V_37 == V_1 )
return V_3 ;
F_16 ( & V_15 -> V_34 ) ;
V_17 = F_11 ( V_15 , V_1 , & V_19 ) ;
if ( V_17 < 0 ) {
V_3 = F_19 ( V_17 ) ;
goto V_23;
}
V_29 = 1 ;
V_18 = 0 ;
while ( V_18 < V_17 ) {
V_28 = F_24 ( V_17 - V_18 , V_42 ) ;
V_3 = F_17 ( V_3 , V_28 , & V_19 [ V_18 ] , V_29 ) ;
if ( F_23 ( V_3 ) ) {
if ( V_31 ) {
F_25 ( V_31 ) ;
}
F_26 ( V_19 ) ;
goto V_23;
}
V_31 = V_3 ;
V_18 += V_28 ;
V_29 = 0 ;
}
F_26 ( V_19 ) ;
V_35:
if ( ! F_23 ( V_3 ) ) {
F_4 ( & V_1 -> V_7 ) ;
if ( F_27 ( V_1 ) ) {
F_5 ( & V_1 -> V_7 ) ;
F_25 ( V_3 ) ;
V_3 = F_19 ( - V_43 ) ;
} else {
F_1 ( V_1 , V_3 ) ;
F_5 ( & V_1 -> V_7 ) ;
}
}
V_23:
F_18 ( & V_15 -> V_34 ) ;
return V_3 ;
}
struct V_2 * F_28 ( struct V_1 * V_1 )
{
T_1 V_8 ;
int V_9 , V_30 ;
struct V_14 * V_15 ;
V_15 = F_15 ( V_1 ) ;
V_30 = V_15 -> V_32 & V_33 ;
switch ( V_30 ) {
case V_38 :
case V_44 :
case V_45 :
V_8 = F_29 () ;
V_9 = 0 ;
break;
case V_46 :
V_8 = V_15 -> V_8 ;
V_9 = 1 ;
break;
default:
V_8 = V_47 ;
V_9 = 0 ;
break;
}
return F_14 ( V_1 , V_8 , V_9 ) ;
}
struct V_2 * F_30 ( struct V_1 * V_1 )
{
int V_48 ;
struct V_2 * V_3 ;
V_3 = F_31 ( F_14 ( V_1 , V_49 , 0 ) ) ;
if ( F_23 ( V_3 ) )
goto V_50;
V_48 = F_32 ( V_3 , V_51 ) ;
if ( V_48 < 0 ) {
F_25 ( V_3 ) ;
V_3 = F_19 ( V_48 ) ;
goto V_50;
}
V_50:
return V_3 ;
}
