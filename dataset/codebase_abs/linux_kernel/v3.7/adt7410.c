static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_4 = F_2 ( V_2 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ! ( V_4 & V_6 ) )
return 0 ;
F_3 ( 60 ) ;
}
return - V_7 ;
}
static struct V_8 * F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_8 * V_11 = F_6 ( V_2 ) ;
struct V_8 * V_12 = V_11 ;
F_7 ( & V_11 -> V_13 ) ;
if ( F_8 ( V_14 , V_11 -> V_15 + V_16 + V_16 / 2 )
|| ! V_11 -> V_17 ) {
int V_3 , V_4 ;
F_9 ( & V_2 -> V_10 , L_1 ) ;
V_4 = F_1 ( V_2 ) ;
if ( F_10 ( V_4 ) ) {
V_12 = F_11 ( V_4 ) ;
goto abort;
}
for ( V_3 = 0 ; V_3 < F_12 ( V_11 -> V_18 ) ; V_3 ++ ) {
V_4 = F_13 ( V_2 ,
V_19 [ V_3 ] ) ;
if ( F_10 ( V_4 < 0 ) ) {
F_9 ( V_10 ,
L_2 ,
V_19 [ V_3 ] , V_4 ) ;
V_12 = F_11 ( V_4 ) ;
goto abort;
}
V_11 -> V_18 [ V_3 ] = V_4 ;
}
V_4 = F_2 ( V_2 , V_20 ) ;
if ( F_10 ( V_4 < 0 ) ) {
F_9 ( V_10 ,
L_2 ,
V_20 , V_4 ) ;
V_12 = F_11 ( V_4 ) ;
goto abort;
}
V_11 -> V_21 = V_4 ;
V_11 -> V_15 = V_14 ;
V_11 -> V_17 = true ;
}
abort:
F_14 ( & V_11 -> V_13 ) ;
return V_12 ;
}
static T_1 F_15 ( long V_18 )
{
return F_16 ( F_17 ( V_18 , V_22 ,
V_23 ) * 128 , 1000 ) ;
}
static int F_18 ( struct V_8 * V_11 , T_1 V_24 )
{
if ( ! ( V_11 -> V_25 & V_26 ) )
V_24 &= V_27 ;
return F_16 ( V_24 * 1000 , 128 ) ;
}
static T_2 F_19 ( struct V_9 * V_10 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_31 * V_32 = F_20 ( V_29 ) ;
struct V_8 * V_11 = F_4 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
return sprintf ( V_30 , L_3 , F_18 ( V_11 ,
V_11 -> V_18 [ V_32 -> V_33 ] ) ) ;
}
static T_2 F_23 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
const char * V_30 , T_3 V_34 )
{
struct V_31 * V_32 = F_20 ( V_29 ) ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_8 * V_11 = F_6 ( V_2 ) ;
int V_35 = V_32 -> V_33 ;
long V_18 ;
int V_12 ;
V_12 = F_24 ( V_30 , 10 , & V_18 ) ;
if ( V_12 )
return V_12 ;
F_7 ( & V_11 -> V_13 ) ;
V_11 -> V_18 [ V_35 ] = F_15 ( V_18 ) ;
V_12 = F_25 ( V_2 , V_19 [ V_35 ] ,
V_11 -> V_18 [ V_35 ] ) ;
if ( V_12 )
V_34 = V_12 ;
F_14 ( & V_11 -> V_13 ) ;
return V_34 ;
}
static T_2 F_26 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_20 ( V_29 ) ;
struct V_8 * V_11 ;
int V_35 = V_32 -> V_33 ;
int V_21 ;
V_11 = F_4 ( V_10 ) ;
if ( F_21 ( V_11 ) )
return F_22 ( V_11 ) ;
V_21 = ( V_11 -> V_21 & V_36 ) * 1000 ;
if ( V_35 == 2 )
V_21 = - V_21 ;
return sprintf ( V_30 , L_3 ,
F_18 ( V_11 , V_11 -> V_18 [ V_35 ] ) - V_21 ) ;
}
static T_2 F_27 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
const char * V_30 , T_3 V_34 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_8 * V_11 = F_6 ( V_2 ) ;
int V_37 , V_12 ;
long V_21 ;
V_12 = F_24 ( V_30 , 10 , & V_21 ) ;
if ( V_12 )
return V_12 ;
V_37 = F_18 ( V_11 , V_11 -> V_18 [ 1 ] ) ;
V_21 = F_17 ( V_21 , V_22 , V_23 ) ;
V_11 -> V_21 = F_17 ( F_16 ( V_37 - V_21 , 1000 ) ,
0 , V_36 ) ;
V_12 = F_28 ( V_2 , V_20 , V_11 -> V_21 ) ;
if ( V_12 )
return V_12 ;
return V_34 ;
}
static T_2 F_29 ( struct V_9 * V_10 ,
struct V_28 * V_29 ,
char * V_30 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_31 * V_32 = F_20 ( V_29 ) ;
int V_12 ;
V_12 = F_2 ( V_2 , V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
return sprintf ( V_30 , L_3 , ! ! ( V_12 & V_32 -> V_33 ) ) ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
struct V_8 * V_11 ;
int V_12 ;
if ( ! F_31 ( V_2 -> V_40 ,
V_41 | V_42 ) )
return - V_43 ;
V_11 = F_32 ( & V_2 -> V_10 , sizeof( struct V_8 ) ,
V_44 ) ;
if ( ! V_11 )
return - V_45 ;
F_33 ( V_2 , V_11 ) ;
F_34 ( & V_11 -> V_13 ) ;
V_12 = F_2 ( V_2 , V_46 ) ;
if ( V_12 < 0 ) {
F_9 ( & V_2 -> V_10 , L_4 , V_12 ) ;
return V_12 ;
}
V_11 -> V_47 = V_12 ;
V_11 -> V_25 = V_12 | V_48 | V_26 |
V_49 ;
if ( V_11 -> V_25 != V_11 -> V_47 ) {
V_12 = F_28 ( V_2 , V_46 ,
V_11 -> V_25 ) ;
if ( V_12 )
return V_12 ;
}
F_9 ( & V_2 -> V_10 , L_5 , V_11 -> V_25 ) ;
V_12 = F_35 ( & V_2 -> V_10 . V_50 , & V_51 ) ;
if ( V_12 )
goto V_52;
V_11 -> V_53 = F_36 ( & V_2 -> V_10 ) ;
if ( F_21 ( V_11 -> V_53 ) ) {
V_12 = F_22 ( V_11 -> V_53 ) ;
goto V_54;
}
F_37 ( & V_2 -> V_10 , L_6 , V_2 -> V_55 ) ;
return 0 ;
V_54:
F_38 ( & V_2 -> V_10 . V_50 , & V_51 ) ;
V_52:
F_28 ( V_2 , V_46 , V_11 -> V_47 ) ;
return V_12 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_11 = F_6 ( V_2 ) ;
F_40 ( V_11 -> V_53 ) ;
F_38 ( & V_2 -> V_10 . V_50 , & V_51 ) ;
if ( V_11 -> V_47 != V_11 -> V_25 )
F_28 ( V_2 , V_46 ,
V_11 -> V_47 ) ;
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
int V_12 ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_8 * V_11 = F_6 ( V_2 ) ;
V_12 = F_28 ( V_2 , V_46 ,
V_11 -> V_25 | V_56 ) ;
return V_12 ;
}
static int F_42 ( struct V_9 * V_10 )
{
int V_12 ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_8 * V_11 = F_6 ( V_2 ) ;
V_12 = F_28 ( V_2 , V_46 , V_11 -> V_25 ) ;
return V_12 ;
}
