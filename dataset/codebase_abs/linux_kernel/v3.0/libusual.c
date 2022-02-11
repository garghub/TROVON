void F_1 ( int type )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
if ( type <= 0 || type >= 3 )
return;
V_2 = & V_4 [ type ] ;
F_2 ( & V_5 , V_3 ) ;
V_2 -> V_6 |= V_7 ;
F_3 ( & V_5 , V_3 ) ;
}
void F_4 ( int type )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
if ( type <= 0 || type >= 3 )
return;
V_2 = & V_4 [ type ] ;
F_2 ( & V_5 , V_3 ) ;
V_2 -> V_6 &= ~ V_7 ;
F_3 ( & V_5 , V_3 ) ;
}
int F_5 ( const struct V_8 * V_9 , int V_10 )
{
int V_11 = F_6 ( V_9 -> V_12 ) ;
if ( V_10 <= 0 || V_10 >= 3 )
return - V_13 ;
if ( V_11 == V_10 )
return 0 ;
if ( V_11 == V_14 && V_10 == F_7 ( & V_15 ) )
return 0 ;
return - V_16 ;
}
static int F_8 ( struct V_17 * V_18 ,
const struct V_8 * V_9 )
{
int V_19 ;
unsigned long type ;
struct V_20 * V_21 ;
unsigned long V_3 ;
type = F_6 ( V_9 -> V_12 ) ;
if ( type == 0 )
type = F_7 ( & V_15 ) ;
F_2 ( & V_5 , V_3 ) ;
if ( ( V_4 [ type ] . V_6 & ( V_22 | V_7 ) ) != 0 ) {
F_3 ( & V_5 , V_3 ) ;
return - V_23 ;
}
V_4 [ type ] . V_6 |= V_22 ;
F_3 ( & V_5 , V_3 ) ;
V_21 = F_9 ( V_24 , ( void * ) type , L_1 , type ) ;
if ( F_10 ( V_21 ) ) {
V_19 = F_11 ( V_21 ) ;
F_12 ( V_25 L_2
L_3 ,
V_26 [ type ] , V_19 ) ;
F_2 ( & V_5 , V_3 ) ;
V_4 [ type ] . V_6 &= ~ V_22 ;
F_3 ( & V_5 , V_3 ) ;
return V_19 ;
}
F_13 ( & V_27 ) ;
return - V_23 ;
}
static void F_14 ( struct V_17 * V_18 )
{
;
}
static int V_24 ( void * V_28 )
{
int type = ( unsigned long ) V_28 ;
struct V_1 * V_2 = & V_4 [ type ] ;
int V_19 ;
unsigned long V_3 ;
F_15 ( & V_29 ) ;
V_19 = F_16 ( V_26 [ type ] ) ;
F_2 ( & V_5 , V_3 ) ;
if ( V_19 == 0 && ( V_2 -> V_6 & V_7 ) == 0 ) {
F_12 ( V_30 L_2
L_4 ,
V_26 [ type ] ) ;
}
V_2 -> V_6 &= ~ V_22 ;
F_3 ( & V_5 , V_3 ) ;
F_17 ( & V_29 ) ;
F_18 ( & V_31 , 0 ) ;
}
static int T_1 F_19 ( void )
{
int V_19 ;
F_15 ( & V_29 ) ;
V_19 = F_20 ( & V_32 ) ;
F_17 ( & V_29 ) ;
return V_19 ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_32 ) ;
while ( F_7 ( & V_27 ) > 0 ) {
F_23 ( & V_31 ) ;
F_24 ( & V_27 ) ;
}
}
static int F_25 ( const char * V_33 , struct V_34 * V_35 )
{
int V_36 ;
int V_37 ;
int V_38 = 0 ;
V_37 = strlen ( V_33 ) ;
if ( V_37 == 0 )
return - V_39 ;
if ( V_33 [ V_37 - 1 ] == '\n' )
-- V_37 ;
for ( V_36 = 1 ; V_36 < 3 ; V_36 ++ ) {
if ( strncmp ( V_33 , V_26 [ V_36 ] , V_37 ) == 0 ) {
V_38 = V_36 ;
break;
}
}
if ( V_38 == 0 )
return - V_13 ;
F_26 ( & V_15 , V_38 ) ;
return 0 ;
}
static int F_27 ( char * V_40 , struct V_34 * V_35 )
{
return strlen ( strcpy ( V_40 , V_26 [ F_7 ( & V_15 ) ] ) ) ;
}
