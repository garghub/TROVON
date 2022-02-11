int F_1 ( struct V_1 * V_2 ,
const unsigned int V_3 ,
const struct V_4 V_5 ,
T_1 * V_6 )
{
unsigned int V_7 ;
if ( ! F_2 ( V_8 , & V_2 -> V_9 ) )
return 0 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
F_3 ( V_2 , V_3 , V_6 ) ;
if ( ! F_4 ( * V_6 , V_5 ) )
return 1 ;
F_5 ( V_11 ) ;
}
F_6 ( V_12 L_1
L_2 , V_13 , V_3 , * V_6 ) ;
* V_6 = ~ 0 ;
return 0 ;
}
bool F_7 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 = 16 ;
while ( -- V_23 ) {
V_18 = F_8 ( V_15 , V_24 ) ;
V_20 = V_18 -> V_25 ;
if ( V_2 -> V_26 -> V_27 -> V_28 ( V_18 ) )
break;
V_22 = F_9 ( V_18 -> V_29 ) ;
V_22 -> V_30 = V_20 -> V_30 ;
V_22 -> V_31 = V_18 -> V_15 -> V_32 ;
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
F_12 ( V_18 , V_33 ) ;
}
return ! V_23 ;
}
void F_13 ( struct V_14 * V_15 , bool V_34 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; ! F_14 ( V_15 ) && V_7 < 10 ; V_7 ++ )
F_15 ( 10 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_19 * V_20 ;
void * V_35 ;
T_2 V_36 ;
unsigned int V_7 ;
V_35 = F_17 ( V_2 -> V_37 ,
V_15 -> V_38 * V_15 -> V_32 ,
& V_36 , V_39 ) ;
if ( ! V_35 )
return - V_40 ;
memset ( V_35 , 0 , V_15 -> V_38 * V_15 -> V_32 ) ;
for ( V_7 = 0 ; V_7 < V_15 -> V_38 ; V_7 ++ ) {
V_20 = V_15 -> V_41 [ V_7 ] . V_25 ;
V_20 -> V_30 = V_35 + V_7 * V_15 -> V_32 ;
V_20 -> V_42 = V_36 + V_7 * V_15 -> V_32 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_19 * V_20 =
V_15 -> V_41 [ 0 ] . V_25 ;
if ( V_20 -> V_30 )
F_19 ( V_2 -> V_37 ,
V_15 -> V_38 * V_15 -> V_32 ,
V_20 -> V_30 , V_20 -> V_42 ) ;
V_20 -> V_30 = NULL ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_43 ;
F_21 (rt2x00dev, queue) {
V_43 = F_16 ( V_2 , V_15 ) ;
if ( V_43 )
goto exit;
}
V_43 = F_22 ( V_2 -> V_44 ,
V_2 -> V_26 -> V_27 -> V_45 ,
V_46 , V_2 -> V_47 , V_2 ) ;
if ( V_43 ) {
F_23 ( V_2 , L_3 ,
V_2 -> V_44 , V_43 ) ;
goto exit;
}
return 0 ;
exit:
F_21 (rt2x00dev, queue)
F_18 ( V_2 , V_15 ) ;
return V_43 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
F_25 ( V_2 -> V_44 , V_2 ) ;
F_21 (rt2x00dev, queue)
F_18 ( V_2 , V_15 ) ;
}
