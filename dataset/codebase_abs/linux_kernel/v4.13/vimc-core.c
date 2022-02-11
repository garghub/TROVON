static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; V_3 ++ ) {
const struct V_7 * V_8 = & V_2 -> V_5 -> V_9 [ V_3 ] ;
struct V_10 * V_11 =
F_2 ( V_2 -> V_12 [ V_8 -> V_13 ] ) ;
struct V_10 * V_14 =
F_2 ( V_2 -> V_12 [ V_8 -> V_15 ] ) ;
V_4 = F_3 ( V_11 -> V_16 , V_8 -> V_17 ,
V_14 -> V_16 , V_8 -> V_18 ,
V_8 -> V_19 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static int F_4 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( F_6 ( V_21 ) ,
struct V_1 , V_22 ) ;
int V_4 ;
F_7 ( V_21 , L_1 ) ;
V_4 = F_8 ( V_2 -> V_23 . V_24 , & V_2 -> V_25 ) ;
if ( V_4 ) {
F_9 ( V_2 -> V_23 . V_24 ,
L_2 , V_4 ) ;
return V_4 ;
}
V_4 = F_10 ( V_21 , & V_2 -> V_25 ) ;
if ( V_4 )
goto V_26;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
goto V_27;
V_4 = F_11 ( & V_2 -> V_23 ) ;
if ( V_4 ) {
F_9 ( V_2 -> V_23 . V_24 ,
L_3 , V_4 ) ;
goto V_27;
}
V_4 = F_12 ( & V_2 -> V_25 ) ;
if ( V_4 ) {
F_9 ( V_2 -> V_23 . V_24 ,
L_4 ,
V_4 ) ;
goto V_28;
}
return 0 ;
V_28:
F_13 ( & V_2 -> V_23 ) ;
V_27:
F_14 ( V_21 , NULL ) ;
V_26:
F_15 ( & V_2 -> V_25 ) ;
return V_4 ;
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_5 ( F_6 ( V_21 ) ,
struct V_1 , V_22 ) ;
F_7 ( V_21 , L_5 ) ;
F_13 ( & V_2 -> V_23 ) ;
F_14 ( V_21 , NULL ) ;
F_15 ( & V_2 -> V_25 ) ;
}
static int F_17 ( struct V_20 * V_29 , void * V_30 )
{
const struct V_31 * V_22 = F_6 ( V_29 ) ;
const char * V_32 = V_30 ;
return ! strcmp ( V_22 -> V_24 . V_33 , V_32 ) ;
}
static struct V_34 * F_18 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = NULL ;
struct V_36 V_37 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_38 ; V_3 ++ ) {
F_7 ( & V_2 -> V_22 . V_24 , L_6 ,
V_2 -> V_5 -> V_39 [ V_3 ] . V_40 ) ;
F_19 ( V_37 . V_41 , V_2 -> V_5 -> V_39 [ V_3 ] . V_32 ,
sizeof( V_37 . V_41 ) ) ;
V_2 -> V_12 [ V_3 ] = F_20 ( & V_2 -> V_22 . V_24 ,
V_2 -> V_5 -> V_39 [ V_3 ] . V_40 ,
V_42 ,
& V_37 ,
sizeof( V_37 ) ) ;
if ( ! V_2 -> V_12 [ V_3 ] ) {
while ( -- V_3 >= 0 )
F_21 ( V_2 -> V_12 [ V_3 ] ) ;
return F_22 ( - V_43 ) ;
}
F_23 ( & V_2 -> V_22 . V_24 , & V_35 , F_17 ,
( void * ) V_2 -> V_5 -> V_39 [ V_3 ] . V_32 ) ;
}
return V_35 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_38 ; V_3 ++ )
F_21 ( V_2 -> V_12 [ V_3 ] ) ;
}
static int F_25 ( struct V_31 * V_22 )
{
struct V_1 * V_2 = F_5 ( V_22 , struct V_1 , V_22 ) ;
struct V_34 * V_35 = NULL ;
int V_4 ;
F_7 ( & V_22 -> V_24 , L_7 ) ;
V_2 -> V_12 = F_26 ( & V_2 -> V_22 . V_24 , V_2 -> V_5 -> V_38 ,
sizeof( * V_2 -> V_12 ) , V_44 ) ;
if ( ! V_2 -> V_12 )
return - V_43 ;
V_35 = F_18 ( V_2 ) ;
if ( F_27 ( V_35 ) )
return F_28 ( V_35 ) ;
V_2 -> V_25 . V_23 = & V_2 -> V_23 ;
F_19 ( V_2 -> V_23 . V_45 , V_46 ,
sizeof( V_2 -> V_23 . V_45 ) ) ;
V_2 -> V_23 . V_24 = & V_22 -> V_24 ;
F_29 ( & V_2 -> V_23 ) ;
V_4 = F_30 ( & V_22 -> V_24 , & V_47 ,
V_35 ) ;
if ( V_4 ) {
F_31 ( & V_2 -> V_23 ) ;
F_24 ( V_2 ) ;
F_32 ( V_2 ) ;
return V_4 ;
}
return 0 ;
}
static int F_33 ( struct V_31 * V_22 )
{
struct V_1 * V_2 = F_5 ( V_22 , struct V_1 , V_22 ) ;
F_7 ( & V_22 -> V_24 , L_8 ) ;
F_34 ( & V_22 -> V_24 , & V_47 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static void F_35 ( struct V_20 * V_24 )
{
}
static int T_1 F_36 ( void )
{
int V_4 ;
V_4 = F_37 ( & V_48 . V_22 ) ;
if ( V_4 ) {
F_9 ( & V_48 . V_22 . V_24 ,
L_9 , V_4 ) ;
return V_4 ;
}
V_4 = F_38 ( & V_49 ) ;
if ( V_4 ) {
F_9 ( & V_48 . V_22 . V_24 ,
L_10 , V_4 ) ;
F_39 ( & V_49 ) ;
return V_4 ;
}
return 0 ;
}
static void T_2 F_40 ( void )
{
F_39 ( & V_49 ) ;
F_21 ( & V_48 . V_22 ) ;
}
