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
ERROR ( V_2 , L_1
L_2 , V_3 , * V_6 ) ;
* V_6 = ~ 0 ;
return 0 ;
}
bool F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 = 16 ;
while ( -- V_21 ) {
V_16 = F_7 ( V_13 , V_22 ) ;
V_18 = V_16 -> V_23 ;
if ( V_2 -> V_24 -> V_25 -> V_26 ( V_16 ) )
break;
V_20 = F_8 ( V_16 -> V_27 ) ;
V_20 -> V_28 = V_18 -> V_28 ;
V_20 -> V_29 = V_16 -> V_13 -> V_30 ;
F_9 ( V_16 ) ;
F_10 ( V_16 ) ;
F_11 ( V_16 ) ;
}
return ! V_21 ;
}
void F_12 ( struct V_12 * V_13 , bool V_31 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; ! F_13 ( V_13 ) && V_7 < 10 ; V_7 ++ )
F_14 ( 10 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_17 * V_18 ;
void * V_32 ;
T_2 V_33 ;
unsigned int V_7 ;
V_32 = F_16 ( V_2 -> V_34 ,
V_13 -> V_35 * V_13 -> V_30 ,
& V_33 , V_36 ) ;
if ( ! V_32 )
return - V_37 ;
memset ( V_32 , 0 , V_13 -> V_35 * V_13 -> V_30 ) ;
for ( V_7 = 0 ; V_7 < V_13 -> V_35 ; V_7 ++ ) {
V_18 = V_13 -> V_38 [ V_7 ] . V_23 ;
V_18 -> V_28 = V_32 + V_7 * V_13 -> V_30 ;
V_18 -> V_39 = V_33 + V_7 * V_13 -> V_30 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_17 * V_18 =
V_13 -> V_38 [ 0 ] . V_23 ;
if ( V_18 -> V_28 )
F_18 ( V_2 -> V_34 ,
V_13 -> V_35 * V_13 -> V_30 ,
V_18 -> V_28 , V_18 -> V_39 ) ;
V_18 -> V_28 = NULL ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_40 ;
F_20 (rt2x00dev, queue) {
V_40 = F_15 ( V_2 , V_13 ) ;
if ( V_40 )
goto exit;
}
V_40 = F_21 ( V_2 -> V_41 ,
V_2 -> V_24 -> V_25 -> V_42 ,
V_43 , V_2 -> V_44 , V_2 ) ;
if ( V_40 ) {
ERROR ( V_2 , L_3 ,
V_2 -> V_41 , V_40 ) ;
goto exit;
}
return 0 ;
exit:
F_20 (rt2x00dev, queue)
F_17 ( V_2 , V_13 ) ;
return V_40 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
F_23 ( V_2 -> V_41 , V_2 ) ;
F_20 (rt2x00dev, queue)
F_17 ( V_2 , V_13 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
F_25 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
if ( V_2 -> V_47 . V_48 ) {
F_26 ( V_2 -> V_47 . V_48 ) ;
V_2 -> V_47 . V_48 = NULL ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_49 * V_49 = F_28 ( V_2 -> V_34 ) ;
V_2 -> V_47 . V_48 = F_29 ( V_49 , 0 ) ;
if ( ! V_2 -> V_47 . V_48 )
goto exit;
V_2 -> V_46 = F_30 ( V_2 -> V_24 -> V_50 , V_36 ) ;
if ( ! V_2 -> V_46 )
goto exit;
V_2 -> V_45 = F_30 ( V_2 -> V_24 -> V_51 , V_36 ) ;
if ( ! V_2 -> V_45 )
goto exit;
return 0 ;
exit:
F_31 ( L_4 ) ;
F_24 ( V_2 ) ;
return - V_37 ;
}
int F_32 ( struct V_49 * V_49 , const struct V_52 * V_24 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 ;
int V_55 ;
V_55 = F_33 ( V_49 ) ;
if ( V_55 ) {
F_31 ( L_5 ) ;
return V_55 ;
}
V_55 = F_34 ( V_49 , F_35 ( V_49 ) ) ;
if ( V_55 ) {
F_31 ( L_6 ) ;
goto V_56;
}
F_36 ( V_49 ) ;
if ( F_37 ( V_49 ) )
F_31 ( L_7 ) ;
if ( F_38 ( & V_49 -> V_34 , F_39 ( 32 ) ) ) {
F_31 ( L_8 ) ;
V_55 = - V_57 ;
goto V_58;
}
V_54 = F_40 ( sizeof( struct V_1 ) , V_24 -> V_54 ) ;
if ( ! V_54 ) {
F_31 ( L_9 ) ;
V_55 = - V_37 ;
goto V_58;
}
F_41 ( V_49 , V_54 ) ;
V_2 = V_54 -> V_59 ;
V_2 -> V_34 = & V_49 -> V_34 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_41 = V_49 -> V_41 ;
V_2 -> V_44 = F_35 ( V_49 ) ;
if ( F_42 ( V_49 ) )
F_43 ( V_2 , V_60 ) ;
else
F_43 ( V_2 , V_61 ) ;
V_55 = F_27 ( V_2 ) ;
if ( V_55 )
goto V_62;
V_55 = F_44 ( V_2 ) ;
if ( V_55 )
goto V_63;
return 0 ;
V_63:
F_24 ( V_2 ) ;
V_62:
F_45 ( V_54 ) ;
V_58:
F_46 ( V_49 ) ;
V_56:
F_47 ( V_49 ) ;
F_41 ( V_49 , NULL ) ;
return V_55 ;
}
void F_48 ( struct V_49 * V_49 )
{
struct V_53 * V_54 = F_49 ( V_49 ) ;
struct V_1 * V_2 = V_54 -> V_59 ;
F_50 ( V_2 ) ;
F_24 ( V_2 ) ;
F_45 ( V_54 ) ;
F_41 ( V_49 , NULL ) ;
F_47 ( V_49 ) ;
F_46 ( V_49 ) ;
}
int F_51 ( struct V_49 * V_49 , T_3 V_64 )
{
struct V_53 * V_54 = F_49 ( V_49 ) ;
struct V_1 * V_2 = V_54 -> V_59 ;
int V_55 ;
V_55 = F_52 ( V_2 , V_64 ) ;
if ( V_55 )
return V_55 ;
F_53 ( V_49 ) ;
F_47 ( V_49 ) ;
return F_54 ( V_49 , F_55 ( V_49 , V_64 ) ) ;
}
int F_56 ( struct V_49 * V_49 )
{
struct V_53 * V_54 = F_49 ( V_49 ) ;
struct V_1 * V_2 = V_54 -> V_59 ;
if ( F_54 ( V_49 , V_65 ) ||
F_33 ( V_49 ) ) {
ERROR ( V_2 , L_10 ) ;
return - V_57 ;
}
F_57 ( V_49 ) ;
return F_58 ( V_2 ) ;
}
