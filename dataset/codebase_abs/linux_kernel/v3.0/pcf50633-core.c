static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_3 ,
V_4 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_8 , L_1 , V_4 , V_3 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , int V_4 , T_1 * V_5 )
{
int V_6 ;
V_6 = F_5 ( V_2 -> V_7 , V_3 ,
V_4 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_8 , L_2 , V_4 , V_3 ) ;
return V_6 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
int V_9 , T_1 * V_5 )
{
int V_6 ;
F_7 ( & V_2 -> V_10 ) ;
V_6 = F_1 ( V_2 , V_3 , V_9 , V_5 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
int V_9 , T_1 * V_5 )
{
int V_6 ;
F_7 ( & V_2 -> V_10 ) ;
V_6 = F_4 ( V_2 , V_3 , V_9 , V_5 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_6 ;
}
T_1 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_11 ;
F_7 ( & V_2 -> V_10 ) ;
F_1 ( V_2 , V_3 , 1 , & V_11 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_11 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
int V_6 ;
F_7 ( & V_2 -> V_10 ) ;
V_6 = F_4 ( V_2 , V_3 , 1 , & V_11 ) ;
F_8 ( & V_2 -> V_10 ) ;
return V_6 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 , T_1 V_11 )
{
int V_6 ;
T_1 V_13 ;
V_11 &= V_12 ;
F_7 ( & V_2 -> V_10 ) ;
V_6 = F_1 ( V_2 , V_3 , 1 , & V_13 ) ;
if ( V_6 < 0 )
goto V_14;
V_13 &= ~ V_12 ;
V_13 |= V_11 ;
V_6 = F_4 ( V_2 , V_3 , 1 , & V_13 ) ;
V_14:
F_8 ( & V_2 -> V_10 ) ;
return V_6 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
int V_6 ;
T_1 V_13 ;
F_7 ( & V_2 -> V_10 ) ;
V_6 = F_1 ( V_2 , V_3 , 1 , & V_13 ) ;
if ( V_6 < 0 )
goto V_14;
V_13 &= ~ V_11 ;
V_6 = F_4 ( V_2 , V_3 , 1 , & V_13 ) ;
V_14:
F_8 ( & V_2 -> V_10 ) ;
return V_6 ;
}
static T_2 F_14 ( struct V_15 * V_8 , struct V_16 * V_17 ,
char * V_18 )
{
struct V_1 * V_2 = F_15 ( V_8 ) ;
T_1 V_19 [ 16 ] ;
int V_20 , V_21 , V_22 = 0 ;
char * V_23 = V_18 ;
static T_1 V_24 [] = {
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
0
} ;
for ( V_20 = 0 ; V_20 < 256 ; V_20 += sizeof( V_19 ) ) {
for ( V_21 = 0 ; V_21 < sizeof( V_19 ) ; V_21 ++ )
if ( V_20 == V_24 [ V_22 ] ) {
V_22 ++ ;
V_19 [ V_21 ] = 0x00 ;
} else
V_19 [ V_21 ] = F_10 ( V_2 , V_20 + V_21 ) ;
F_16 ( V_19 , sizeof( V_19 ) , 16 , 1 , V_23 , 128 , 0 ) ;
V_23 += strlen ( V_23 ) ;
* V_23 ++ = '\n' ;
* V_23 = '\0' ;
}
return V_23 - V_18 ;
}
static T_2 F_17 ( struct V_15 * V_8 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_15 ( V_8 ) ;
int V_20 ;
V_20 = sprintf ( V_18 , L_3 ,
V_2 -> V_30 [ 0 ] ,
V_2 -> V_30 [ 1 ] ,
V_2 -> V_30 [ 2 ] ,
V_2 -> V_30 [ 3 ] ,
V_2 -> V_30 [ 4 ] ) ;
return V_20 ;
}
static void
F_18 ( struct V_1 * V_2 , const char * V_31 ,
struct V_32 * * V_33 )
{
int V_6 ;
* V_33 = F_19 ( V_31 , - 1 ) ;
if ( ! * V_33 ) {
F_3 ( V_2 -> V_8 , L_4 , V_31 ) ;
return;
}
( * V_33 ) -> V_8 . V_34 = V_2 -> V_8 ;
V_6 = F_20 ( * V_33 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_5 , V_31 , V_6 ) ;
F_21 ( * V_33 ) ;
* V_33 = NULL ;
}
}
static int F_22 ( struct V_15 * V_8 )
{
struct V_7 * V_35 = F_23 ( V_8 ) ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
return F_25 ( V_2 ) ;
}
static int F_26 ( struct V_15 * V_8 )
{
struct V_7 * V_35 = F_23 ( V_8 ) ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
return F_27 ( V_2 ) ;
}
static int T_3 F_28 ( struct V_7 * V_35 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 = V_35 -> V_8 . V_40 ;
int V_41 , V_6 ;
int V_42 , V_43 ;
if ( ! V_35 -> V_44 ) {
F_3 ( & V_35 -> V_8 , L_6 ) ;
return - V_45 ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_39 = V_39 ;
F_30 ( & V_2 -> V_10 ) ;
F_31 ( V_35 , V_2 ) ;
V_2 -> V_8 = & V_35 -> V_8 ;
V_2 -> V_7 = V_35 ;
V_42 = F_10 ( V_2 , 0 ) ;
V_43 = F_10 ( V_2 , 1 ) ;
if ( V_42 < 0 || V_43 < 0 ) {
F_3 ( V_2 -> V_8 , L_7 ) ;
V_6 = - V_48 ;
goto V_49;
}
F_32 ( V_2 -> V_8 , L_8 ,
V_42 , V_43 ) ;
F_33 ( V_2 , V_35 -> V_44 ) ;
F_18 ( V_2 , L_9 ,
& V_2 -> V_50 ) ;
F_18 ( V_2 , L_10 ,
& V_2 -> V_51 ) ;
F_18 ( V_2 , L_11 ,
& V_2 -> V_52 ) ;
F_18 ( V_2 , L_12 ,
& V_2 -> V_53 ) ;
F_18 ( V_2 , L_13 ,
& V_2 -> V_54 ) ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ ) {
struct V_32 * V_33 ;
V_33 = F_19 ( L_14 , V_41 ) ;
if ( ! V_33 ) {
F_3 ( V_2 -> V_8 , L_15 , V_41 ) ;
continue;
}
V_33 -> V_8 . V_34 = V_2 -> V_8 ;
F_34 ( V_33 , & V_39 -> V_56 [ V_41 ] ,
sizeof( V_39 -> V_56 [ V_41 ] ) ) ;
V_2 -> V_57 [ V_41 ] = V_33 ;
F_20 ( V_33 ) ;
}
V_6 = F_35 ( & V_35 -> V_8 . V_58 , & V_59 ) ;
if ( V_6 )
F_3 ( V_2 -> V_8 , L_16 ) ;
if ( V_39 -> V_60 )
V_39 -> V_60 ( V_2 ) ;
return 0 ;
V_49:
F_36 ( V_2 ) ;
return V_6 ;
}
static int T_4 F_37 ( struct V_7 * V_35 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
int V_41 ;
F_38 ( & V_35 -> V_8 . V_58 , & V_59 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 -> V_50 ) ;
F_40 ( V_2 -> V_51 ) ;
F_40 ( V_2 -> V_52 ) ;
F_40 ( V_2 -> V_53 ) ;
F_40 ( V_2 -> V_54 ) ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ )
F_40 ( V_2 -> V_57 [ V_41 ] ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
return F_42 ( & V_61 ) ;
}
static void T_6 F_43 ( void )
{
F_44 ( & V_61 ) ;
}
