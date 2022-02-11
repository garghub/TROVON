int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , T_1 * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_3 , V_5 , V_4 ) ;
if ( V_6 != 0 )
return V_6 ;
return V_4 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , T_1 * V_5 )
{
return F_4 ( V_2 -> V_7 , V_3 , V_5 , V_4 ) ;
}
T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_8 ;
int V_6 ;
V_6 = F_6 ( V_2 -> V_7 , V_3 , & V_8 ) ;
if ( V_6 < 0 )
return - 1 ;
return V_8 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
return F_8 ( V_2 -> V_7 , V_3 , V_8 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 , T_1 V_8 )
{
return F_10 ( V_2 -> V_7 , V_3 , V_9 , V_8 ) ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
return F_10 ( V_2 -> V_7 , V_3 , V_8 , 0 ) ;
}
static T_2 F_12 ( struct V_10 * V_11 , struct V_12 * V_13 ,
char * V_14 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
T_1 V_15 [ 16 ] ;
int V_16 , V_17 , V_18 = 0 ;
char * V_19 = V_14 ;
static T_1 V_20 [] = {
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
0
} ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += sizeof( V_15 ) ) {
for ( V_17 = 0 ; V_17 < sizeof( V_15 ) ; V_17 ++ )
if ( V_16 == V_20 [ V_18 ] ) {
V_18 ++ ;
V_15 [ V_17 ] = 0x00 ;
} else
V_15 [ V_17 ] = F_5 ( V_2 , V_16 + V_17 ) ;
F_14 ( V_15 , sizeof( V_15 ) , 16 , 1 , V_19 , 128 , 0 ) ;
V_19 += strlen ( V_19 ) ;
* V_19 ++ = '\n' ;
* V_19 = '\0' ;
}
return V_19 - V_14 ;
}
static T_2 F_15 ( struct V_10 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_16 ;
V_16 = sprintf ( V_14 , L_1 ,
V_2 -> V_26 [ 0 ] ,
V_2 -> V_26 [ 1 ] ,
V_2 -> V_26 [ 2 ] ,
V_2 -> V_26 [ 3 ] ,
V_2 -> V_26 [ 4 ] ) ;
return V_16 ;
}
static void
F_16 ( struct V_1 * V_2 , const char * V_27 ,
struct V_28 * * V_29 )
{
int V_6 ;
* V_29 = F_17 ( V_27 , - 1 ) ;
if ( ! * V_29 ) {
F_18 ( V_2 -> V_11 , L_2 , V_27 ) ;
return;
}
( * V_29 ) -> V_11 . V_30 = V_2 -> V_11 ;
V_6 = F_19 ( * V_29 ) ;
if ( V_6 ) {
F_18 ( V_2 -> V_11 , L_3 , V_27 , V_6 ) ;
F_20 ( * V_29 ) ;
* V_29 = NULL ;
}
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_31 * V_32 = F_22 ( V_11 ) ;
struct V_1 * V_2 = F_23 ( V_32 ) ;
return F_24 ( V_2 ) ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_31 * V_32 = F_22 ( V_11 ) ;
struct V_1 * V_2 = F_23 ( V_32 ) ;
return F_26 ( V_2 ) ;
}
static int F_27 ( struct V_31 * V_32 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 = F_28 ( & V_32 -> V_11 ) ;
int V_37 , V_6 ;
int V_38 , V_39 ;
if ( ! V_32 -> V_40 ) {
F_18 ( & V_32 -> V_11 , L_4 ) ;
return - V_41 ;
}
V_2 = F_29 ( & V_32 -> V_11 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
F_30 ( V_32 , V_2 ) ;
V_2 -> V_11 = & V_32 -> V_11 ;
V_2 -> V_36 = V_36 ;
F_31 ( & V_2 -> V_44 ) ;
V_2 -> V_7 = F_32 ( V_32 , & V_45 ) ;
if ( F_33 ( V_2 -> V_7 ) ) {
V_6 = F_34 ( V_2 -> V_7 ) ;
F_18 ( V_2 -> V_11 , L_5 , V_6 ) ;
return V_6 ;
}
V_38 = F_5 ( V_2 , 0 ) ;
V_39 = F_5 ( V_2 , 1 ) ;
if ( V_38 < 0 || V_39 < 0 ) {
F_18 ( V_2 -> V_11 , L_6 ) ;
V_6 = - V_46 ;
return V_6 ;
}
F_35 ( V_2 -> V_11 , L_7 ,
V_38 , V_39 ) ;
F_36 ( V_2 , V_32 -> V_40 ) ;
F_16 ( V_2 , L_8 , & V_2 -> V_47 ) ;
F_16 ( V_2 , L_9 , & V_2 -> V_48 ) ;
F_16 ( V_2 , L_10 , & V_2 -> V_49 ) ;
F_16 ( V_2 , L_11 , & V_2 -> V_50 ) ;
F_16 ( V_2 , L_12 , & V_2 -> V_51 ) ;
for ( V_37 = 0 ; V_37 < V_52 ; V_37 ++ ) {
struct V_28 * V_29 ;
int V_53 ;
V_29 = F_17 ( L_13 , V_37 ) ;
if ( ! V_29 )
return - V_43 ;
V_29 -> V_11 . V_30 = V_2 -> V_11 ;
V_6 = F_37 ( V_29 , & V_36 -> V_54 [ V_37 ] ,
sizeof( V_36 -> V_54 [ V_37 ] ) ) ;
if ( V_6 ) {
F_20 ( V_29 ) ;
for ( V_53 = 0 ; V_53 < V_37 ; V_53 ++ )
F_20 ( V_2 -> V_55 [ V_53 ] ) ;
return V_6 ;
}
V_2 -> V_55 [ V_37 ] = V_29 ;
F_19 ( V_29 ) ;
}
V_6 = F_38 ( & V_32 -> V_11 . V_56 , & V_57 ) ;
if ( V_6 )
F_18 ( V_2 -> V_11 , L_14 ) ;
if ( V_36 -> V_58 )
V_36 -> V_58 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_23 ( V_32 ) ;
int V_37 ;
F_40 ( & V_32 -> V_11 . V_56 , & V_57 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 -> V_47 ) ;
F_42 ( V_2 -> V_48 ) ;
F_42 ( V_2 -> V_49 ) ;
F_42 ( V_2 -> V_50 ) ;
F_42 ( V_2 -> V_51 ) ;
for ( V_37 = 0 ; V_37 < V_52 ; V_37 ++ )
F_42 ( V_2 -> V_55 [ V_37 ] ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_59 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_59 ) ;
}
