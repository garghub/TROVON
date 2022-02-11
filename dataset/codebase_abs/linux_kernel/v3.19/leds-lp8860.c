static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_3 ) ;
if ( V_3 == V_5 ) {
V_4 = F_3 ( V_2 -> V_6 ,
V_7 ,
V_8 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
goto V_11;
}
V_4 = F_3 ( V_2 -> V_6 ,
V_7 ,
V_12 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
goto V_11;
}
V_4 = F_3 ( V_2 -> V_6 ,
V_7 ,
V_13 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
goto V_11;
}
} else {
V_4 = F_3 ( V_2 -> V_6 ,
V_7 ,
V_14 ) ;
}
V_11:
F_5 ( & V_2 -> V_3 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_4 , V_15 ;
unsigned int V_16 ;
V_4 = F_7 ( V_2 -> V_6 , V_17 , & V_16 ) ;
if ( V_4 )
goto V_11;
V_15 = V_16 ;
V_4 = F_7 ( V_2 -> V_6 , V_18 , & V_16 ) ;
if ( V_4 )
goto V_11;
V_15 |= V_16 ;
if ( V_15 )
V_4 = F_3 ( V_2 -> V_6 , V_19 ,
V_20 ) ;
V_11:
return V_4 ;
}
static void F_8 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_22 , struct V_1 , V_22 ) ;
int V_4 ;
int V_23 = V_2 -> V_24 * 255 ;
F_2 ( & V_2 -> V_3 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_2 ) ;
goto V_11;
}
V_4 = F_3 ( V_2 -> V_6 , V_25 ,
( V_23 & 0xff00 ) >> 8 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_3 ) ;
goto V_11;
}
V_4 = F_3 ( V_2 -> V_6 , V_26 ,
V_23 & 0xff ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_4 ) ;
goto V_11;
}
V_11:
F_5 ( & V_2 -> V_3 ) ;
}
static void F_10 ( struct V_27 * V_28 ,
enum V_29 V_30 )
{
struct V_1 * V_2 =
F_9 ( V_28 , struct V_1 , V_31 ) ;
V_2 -> V_24 = V_30 ;
F_11 ( & V_2 -> V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
int V_4 , V_32 , V_33 ;
if ( V_2 -> V_34 )
F_13 ( V_2 -> V_34 , 1 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
goto V_11;
V_4 = F_7 ( V_2 -> V_6 , V_35 , & V_16 ) ;
if ( V_4 )
goto V_11;
V_4 = F_1 ( V_2 , V_5 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_5 ) ;
goto V_11;
}
V_33 = F_14 ( V_36 ) / sizeof( V_36 [ 0 ] ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_4 = F_3 ( V_2 -> V_37 ,
V_36 [ V_32 ] . V_38 ,
V_36 [ V_32 ] . V_39 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_6 ) ;
goto V_11;
}
}
V_4 = F_1 ( V_2 , V_14 ) ;
if ( V_4 )
goto V_11;
V_4 = F_3 ( V_2 -> V_6 ,
V_40 ,
V_41 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_9 -> V_10 , L_7 ) ;
V_11:
if ( V_4 )
if ( V_2 -> V_34 )
F_13 ( V_2 -> V_34 , 0 ) ;
return V_4 ;
}
static int F_15 ( struct V_42 * V_9 ,
const struct V_43 * V_44 )
{
int V_4 ;
struct V_1 * V_2 ;
struct V_45 * V_46 = V_9 -> V_10 . V_47 ;
V_2 = F_16 ( & V_9 -> V_10 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_50 = V_51 ;
if ( V_9 -> V_10 . V_47 ) {
V_4 = F_17 ( V_46 , L_8 , & V_2 -> V_50 ) ;
if ( V_4 ) {
F_4 ( & V_9 -> V_10 , L_9 ) ;
return - V_52 ;
}
}
V_2 -> V_34 = F_18 ( & V_9 -> V_10 , L_10 ) ;
if ( F_19 ( V_2 -> V_34 ) )
V_2 -> V_34 = NULL ;
else
F_13 ( V_2 -> V_34 , 0 ) ;
V_2 -> V_53 = F_20 ( & V_9 -> V_10 , L_11 ) ;
if ( F_19 ( V_2 -> V_53 ) )
V_2 -> V_53 = NULL ;
V_2 -> V_9 = V_9 ;
V_2 -> V_31 . V_54 = V_2 -> V_50 ;
V_2 -> V_31 . V_55 = V_56 ;
V_2 -> V_31 . V_57 = F_10 ;
F_21 ( & V_2 -> V_3 ) ;
F_22 ( & V_2 -> V_22 , F_8 ) ;
F_23 ( V_9 , V_2 ) ;
V_2 -> V_6 = F_24 ( V_9 , & V_58 ) ;
if ( F_19 ( V_2 -> V_6 ) ) {
V_4 = F_25 ( V_2 -> V_6 ) ;
F_4 ( & V_9 -> V_10 , L_12 ,
V_4 ) ;
return V_4 ;
}
V_2 -> V_37 = F_24 ( V_9 , & V_59 ) ;
if ( F_19 ( V_2 -> V_37 ) ) {
V_4 = F_25 ( V_2 -> V_37 ) ;
F_4 ( & V_9 -> V_10 , L_12 ,
V_4 ) ;
return V_4 ;
}
V_4 = F_12 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_26 ( & V_9 -> V_10 , & V_2 -> V_31 ) ;
if ( V_4 ) {
F_4 ( & V_9 -> V_10 , L_13 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_27 ( struct V_42 * V_9 )
{
struct V_1 * V_2 = F_28 ( V_9 ) ;
int V_4 ;
F_29 ( & V_2 -> V_31 ) ;
F_30 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_34 )
F_13 ( V_2 -> V_34 , 0 ) ;
if ( V_2 -> V_53 ) {
V_4 = F_31 ( V_2 -> V_53 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_9 -> V_10 ,
L_14 ) ;
}
return 0 ;
}
