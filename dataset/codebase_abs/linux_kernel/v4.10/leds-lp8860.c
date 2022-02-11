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
static int F_8 ( struct V_21 * V_22 ,
enum V_23 V_24 )
{
struct V_1 * V_2 =
F_9 ( V_22 , struct V_1 , V_25 ) ;
int V_26 = V_24 * 255 ;
int V_4 ;
F_2 ( & V_2 -> V_3 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_2 ) ;
goto V_11;
}
V_4 = F_3 ( V_2 -> V_6 , V_27 ,
( V_26 & 0xff00 ) >> 8 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_3 ) ;
goto V_11;
}
V_4 = F_3 ( V_2 -> V_6 , V_28 ,
V_26 & 0xff ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_4 ) ;
goto V_11;
}
V_11:
F_5 ( & V_2 -> V_3 ) ;
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
int V_4 , V_29 , V_30 ;
if ( V_2 -> V_31 )
F_11 ( V_2 -> V_31 , 1 ) ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
goto V_11;
V_4 = F_7 ( V_2 -> V_6 , V_32 , & V_16 ) ;
if ( V_4 )
goto V_11;
V_4 = F_1 ( V_2 , V_5 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_5 ) ;
goto V_11;
}
V_30 = F_12 ( V_33 ) / sizeof( V_33 [ 0 ] ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_4 = F_3 ( V_2 -> V_34 ,
V_33 [ V_29 ] . V_35 ,
V_33 [ V_29 ] . V_36 ) ;
if ( V_4 ) {
F_4 ( & V_2 -> V_9 -> V_10 , L_6 ) ;
goto V_11;
}
}
V_4 = F_1 ( V_2 , V_14 ) ;
if ( V_4 )
goto V_11;
V_4 = F_3 ( V_2 -> V_6 ,
V_37 ,
V_38 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_9 -> V_10 , L_7 ) ;
V_11:
if ( V_4 )
if ( V_2 -> V_31 )
F_11 ( V_2 -> V_31 , 0 ) ;
return V_4 ;
}
static int F_13 ( struct V_39 * V_9 ,
const struct V_40 * V_41 )
{
int V_4 ;
struct V_1 * V_2 ;
struct V_42 * V_43 = V_9 -> V_10 . V_44 ;
V_2 = F_14 ( & V_9 -> V_10 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_47 = V_48 ;
if ( V_9 -> V_10 . V_44 ) {
V_4 = F_15 ( V_43 , L_8 , & V_2 -> V_47 ) ;
if ( V_4 ) {
F_4 ( & V_9 -> V_10 , L_9 ) ;
return - V_49 ;
}
}
V_2 -> V_31 = F_16 ( & V_9 -> V_10 ,
L_10 , V_50 ) ;
if ( F_17 ( V_2 -> V_31 ) ) {
V_4 = F_18 ( V_2 -> V_31 ) ;
F_4 ( & V_9 -> V_10 , L_11 , V_4 ) ;
return V_4 ;
}
V_2 -> V_51 = F_19 ( & V_9 -> V_10 , L_12 ) ;
if ( F_17 ( V_2 -> V_51 ) )
V_2 -> V_51 = NULL ;
V_2 -> V_9 = V_9 ;
V_2 -> V_25 . V_52 = V_2 -> V_47 ;
V_2 -> V_25 . V_53 = V_54 ;
V_2 -> V_25 . V_55 = F_8 ;
F_20 ( & V_2 -> V_3 ) ;
F_21 ( V_9 , V_2 ) ;
V_2 -> V_6 = F_22 ( V_9 , & V_56 ) ;
if ( F_17 ( V_2 -> V_6 ) ) {
V_4 = F_18 ( V_2 -> V_6 ) ;
F_4 ( & V_9 -> V_10 , L_13 ,
V_4 ) ;
return V_4 ;
}
V_2 -> V_34 = F_22 ( V_9 , & V_57 ) ;
if ( F_17 ( V_2 -> V_34 ) ) {
V_4 = F_18 ( V_2 -> V_34 ) ;
F_4 ( & V_9 -> V_10 , L_13 ,
V_4 ) ;
return V_4 ;
}
V_4 = F_10 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_23 ( & V_9 -> V_10 , & V_2 -> V_25 ) ;
if ( V_4 ) {
F_4 ( & V_9 -> V_10 , L_14 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static int F_24 ( struct V_39 * V_9 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
int V_4 ;
F_26 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_31 )
F_11 ( V_2 -> V_31 , 0 ) ;
if ( V_2 -> V_51 ) {
V_4 = F_27 ( V_2 -> V_51 ) ;
if ( V_4 )
F_4 ( & V_2 -> V_9 -> V_10 ,
L_15 ) ;
}
return 0 ;
}
