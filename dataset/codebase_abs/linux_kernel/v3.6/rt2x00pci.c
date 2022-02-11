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
F_11 ( V_16 , V_31 ) ;
}
return ! V_21 ;
}
void F_12 ( struct V_12 * V_13 , bool V_32 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; ! F_13 ( V_13 ) && V_7 < 10 ; V_7 ++ )
F_14 ( 10 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_17 * V_18 ;
void * V_33 ;
T_2 V_34 ;
unsigned int V_7 ;
V_33 = F_16 ( V_2 -> V_35 ,
V_13 -> V_36 * V_13 -> V_30 ,
& V_34 , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
memset ( V_33 , 0 , V_13 -> V_36 * V_13 -> V_30 ) ;
for ( V_7 = 0 ; V_7 < V_13 -> V_36 ; V_7 ++ ) {
V_18 = V_13 -> V_39 [ V_7 ] . V_23 ;
V_18 -> V_28 = V_33 + V_7 * V_13 -> V_30 ;
V_18 -> V_40 = V_34 + V_7 * V_13 -> V_30 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_17 * V_18 =
V_13 -> V_39 [ 0 ] . V_23 ;
if ( V_18 -> V_28 )
F_18 ( V_2 -> V_35 ,
V_13 -> V_36 * V_13 -> V_30 ,
V_18 -> V_28 , V_18 -> V_40 ) ;
V_18 -> V_28 = NULL ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_41 ;
F_20 (rt2x00dev, queue) {
V_41 = F_15 ( V_2 , V_13 ) ;
if ( V_41 )
goto exit;
}
V_41 = F_21 ( V_2 -> V_42 ,
V_2 -> V_24 -> V_25 -> V_43 ,
V_44 , V_2 -> V_45 , V_2 ) ;
if ( V_41 ) {
ERROR ( V_2 , L_3 ,
V_2 -> V_42 , V_41 ) ;
goto exit;
}
return 0 ;
exit:
F_20 (rt2x00dev, queue)
F_17 ( V_2 , V_13 ) ;
return V_41 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
F_23 ( V_2 -> V_42 , V_2 ) ;
F_20 (rt2x00dev, queue)
F_17 ( V_2 , V_13 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
F_25 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
if ( V_2 -> V_48 . V_49 ) {
F_26 ( V_2 -> V_48 . V_49 ) ;
V_2 -> V_48 . V_49 = NULL ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_50 * V_50 = F_28 ( V_2 -> V_35 ) ;
V_2 -> V_48 . V_49 = F_29 ( V_50 , 0 ) ;
if ( ! V_2 -> V_48 . V_49 )
goto exit;
V_2 -> V_47 = F_30 ( V_2 -> V_24 -> V_51 , V_37 ) ;
if ( ! V_2 -> V_47 )
goto exit;
V_2 -> V_46 = F_30 ( V_2 -> V_24 -> V_52 , V_37 ) ;
if ( ! V_2 -> V_46 )
goto exit;
return 0 ;
exit:
F_31 ( L_4 ) ;
F_24 ( V_2 ) ;
return - V_38 ;
}
int F_32 ( struct V_50 * V_50 , const struct V_53 * V_24 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 ;
int V_56 ;
T_3 V_57 ;
V_56 = F_33 ( V_50 ) ;
if ( V_56 ) {
F_31 ( L_5 ) ;
return V_56 ;
}
V_56 = F_34 ( V_50 , F_35 ( V_50 ) ) ;
if ( V_56 ) {
F_31 ( L_6 ) ;
goto V_58;
}
F_36 ( V_50 ) ;
if ( F_37 ( V_50 ) )
F_31 ( L_7 ) ;
if ( F_38 ( & V_50 -> V_35 , F_39 ( 32 ) ) ) {
F_31 ( L_8 ) ;
V_56 = - V_59 ;
goto V_60;
}
V_55 = F_40 ( sizeof( struct V_1 ) , V_24 -> V_55 ) ;
if ( ! V_55 ) {
F_31 ( L_9 ) ;
V_56 = - V_38 ;
goto V_60;
}
F_41 ( V_50 , V_55 ) ;
V_2 = V_55 -> V_61 ;
V_2 -> V_35 = & V_50 -> V_35 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_42 = V_50 -> V_42 ;
V_2 -> V_45 = F_35 ( V_50 ) ;
if ( F_42 ( V_50 ) )
F_43 ( V_2 , V_62 ) ;
else
F_43 ( V_2 , V_63 ) ;
V_56 = F_27 ( V_2 ) ;
if ( V_56 )
goto V_64;
F_44 ( V_50 , V_65 , & V_57 ) ;
V_2 -> V_57 . V_66 = V_57 ;
V_56 = F_45 ( V_2 ) ;
if ( V_56 )
goto V_67;
return 0 ;
V_67:
F_24 ( V_2 ) ;
V_64:
F_46 ( V_55 ) ;
V_60:
F_47 ( V_50 ) ;
V_58:
F_48 ( V_50 ) ;
F_41 ( V_50 , NULL ) ;
return V_56 ;
}
void F_49 ( struct V_50 * V_50 )
{
struct V_54 * V_55 = F_50 ( V_50 ) ;
struct V_1 * V_2 = V_55 -> V_61 ;
F_51 ( V_2 ) ;
F_24 ( V_2 ) ;
F_46 ( V_55 ) ;
F_41 ( V_50 , NULL ) ;
F_48 ( V_50 ) ;
F_47 ( V_50 ) ;
}
int F_52 ( struct V_50 * V_50 , T_4 V_68 )
{
struct V_54 * V_55 = F_50 ( V_50 ) ;
struct V_1 * V_2 = V_55 -> V_61 ;
int V_56 ;
V_56 = F_53 ( V_2 , V_68 ) ;
if ( V_56 )
return V_56 ;
F_54 ( V_50 ) ;
F_48 ( V_50 ) ;
return F_55 ( V_50 , F_56 ( V_50 , V_68 ) ) ;
}
int F_57 ( struct V_50 * V_50 )
{
struct V_54 * V_55 = F_50 ( V_50 ) ;
struct V_1 * V_2 = V_55 -> V_61 ;
if ( F_55 ( V_50 , V_69 ) ||
F_33 ( V_50 ) ) {
ERROR ( V_2 , L_10 ) ;
return - V_59 ;
}
F_58 ( V_50 ) ;
return F_59 ( V_2 ) ;
}
